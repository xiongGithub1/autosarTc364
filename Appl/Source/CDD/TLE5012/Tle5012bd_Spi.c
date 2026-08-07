/**********************************************************************************************************************
 * TLE5012BD QSPI2 direct SFR transfer (bypasses Spi_SetupEB / Spi_SyncTransmit)
 **********************************************************************************************************************/
#include "Tle5012bd_Spi.h"
#include "IfxQspi_reg.h"
#include "IfxQspi_bf.h"
#include "IfxQspi_regdef.h"

uint32 Tle5012bd_SpiLastTxWord = 0U;
uint32 Tle5012bd_SpiLastRxWord = 0U;
Std_ReturnType Tle5012bd_SpiLastResult = E_NOT_OK;

/*
 * 与 Appl GenData SpiJob_5012BD + SpiChannel_5012BD1 对齐：
 *   QSPI2 / SLSO2(硬件片选) / 帧模式 LAST=1 / MSB 先发 / 32 位帧
 *   Idle/Lead/Trail 延时来自 Spi_IdleLeadTrailParam(1,5,1,5,1,5,*)
 * ---------------------------------------------------------------------------
 * ECON[2] = 0x00001404（位定义见 IfxQspi_regdef.h Ifx_QSPI_ECON_Bits）：
 *   Q    [5:0]  = 0x04  ：位时间基础分频（TQ=4，配合 A/B/C 得到 8 MHz 波特率）
 *   A    [7:6]  = 00    ：位段1 = 0
 *   B    [9:8]  = 00    ：位段2 = 0
 *   C    [11:10]= 01    ：位段3 = 1
 *   CPH  [12]   = 1     ：时钟相位（数据采样沿选择）
 *   CPOL [13]   = 0     ：时钟极性（空闲低）
 *   PAREN[14]   = 0     ：关闭奇偶校验
 *   BE   [31:30]= 00    ：小端，不交换字节
 * ---------------------------------------------------------------------------
 * SSOC = 0x00040000（Ifx_QSPI_SSOC_Bits）：
 *   OEN [31:16] bit18=1 ：使能 SLSO2 片选输出
 *   AOL [15:0]  = 0     ：SLSO 有效电平 = 低（片选低有效）
 * ---------------------------------------------------------------------------
 * GLOBALCON = 0x21203C00（Ifx_QSPI_GLOBALCON_Bits）：
 *   TQ   [7:0]  = 0     ：全局时间量子 = 0（由 ECON Q 决定）
 *   SI   [9]    = 0     ：状态注入关闭
 *   EXPECT[13:10]=0xF   ：期望阶段超时值 15（等待 CS 释放前的最长等待）
 *   LB   [14]   = 0     ：回环关闭
 *   DEL0 [15]   = 0     ：SLSO0 延迟模式关闭
 *   STROBE[20:16]=0     ：strobe 延迟 = 0
 *   SRF  [21]   = 1     ：接收 FIFO 满时停止传输
 *   STIP [22]   = 0     ：从机发送空闲电平 = 低
 *   EN   [24]   = 1     ：QSPI 模块使能
 *   MS   [26:25]= 00    ：主模式
 *   AREN [27]   = 0     ：自动复位关闭
 *   CLKSEL[29]  = 1     ：模块时钟源选择
 *   RESETS[31:30]=0     ：不复位子模块
 * ---------------------------------------------------------------------------
 * GLOBALCON1 = 0x17000000（Ifx_QSPI_GLOBALCON1_Bits）：
 *   TXFM [27:26]= 01    ：TXFIFO 中断模式（阈值中断）
 *   RXFM [29:28]= 01    ：RXFIFO 中断模式（阈值中断）
 *   PT2  [25:23]= 011   ：相位转换事件2（帧尾/尾延迟结束后）
 *   其余错误使能位为 0（与 MCAL SpiJob LEVEL_DELIVERED=0 配置一致）
 */
#define TLE5012BD_QSPI2_ECON_VAL              (0x00001404UL)
#define TLE5012BD_QSPI2_ECON_INDEX            (2U)
#define TLE5012BD_QSPI2_SSOC_VAL              (0x00040000UL)
/* 同 Spi_lHwSetJobConfig for SpiJob_5012BD (LEVEL_DELIVERED=0)。 */
#define TLE5012BD_QSPI2_GLOBALCON_VAL         (0x21203C00UL)
#define TLE5012BD_QSPI2_GLOBALCON1_VAL        (0x17000000UL)
/* STATUS 完成判定掩码（Ifx_QSPI_STATUS_Bits）：
   TXF[9] 发送事件标志；RXFIFOLEVEL[21:19] 接收 FIFO 深度。 */
#define TLE5012BD_SPI_TXF_RXFIFO_MASK         (0x00380200UL)
/* 完成条件：TXF=1 且 RXFIFOLEVEL==1（一帧发完且收到 1 个字）。 */
#define TLE5012BD_SPI_TXF_RXFIFO_1_SET        (0x00080200UL)
/* STATUS.ERRORFLAGS[8:0] 低 7 位：协议/帧错误标志（PCE/SPE 等）。 */
#define TLE5012BD_SPI_HW_ERROR_MASK           (0x0000007FUL)
/* FLAGSCLEAR：ERRORCLEARS[8:0]=全1 清所有错误标志；
   TXC[9]/RXC[10]/PT1C[11] 清发送/接收/PT1 事件标志。 */
#define TLE5012BD_SPI_FLAGSCLEAR_VAL          (0x00000FFFUL)
/* 轮询超时：约一帧位时间(32bit@8MHz≈4us)的余量。 */
#define TLE5012BD_SPI_POLL_TIMEOUT            (20000UL)

static uint32 Tle5012bd_SpiBaconLast = 0UL;
static uint8 Tle5012bd_SpiHwReady = 0U;

/* 构建帧控制字 BACON（Ifx_QSPI_BACON_Bits，写 BACONENTRY 送入 TXFIFO 条目）：
 *   LAST [0]    = 1   ：本字为帧最后一个字（帧结束判定）
 *   IPRE [3:1]  = 1   ：IDLE 延时预分频
 *   IDLE [6:4]  = 5   ：帧间空闲延时 5
 *   LPRE [9:7]  = 1   ：LEAD 延时预分频
 *   LEAD [12:10]= 5   ：前沿（CS 有效到时钟）延时 5
 *   TPRE [15:13]= 1   ：TRAIL 延时预分频
 *   TRAIL[18:16]= 5   ：后沿（时钟结束到 CS 释放）延时 5
 *   PARTYP[19]  = 0   ：偶校验/无校验
 *   UINT [20]   = 1   ：PT1 事件产生用户中断标志（帧完成检测）
 *   MSB  [21]   = 1   ：MSB 先发
 *   BYTE [22]   = 0   ：非字节模式（位模式）
 *   DL   [27:23]= 31  ：数据长度 32 位
 *   CS   [31:28]= 2   ：片选选择 SLSO2
 */
static uint32 Tle5012bd_SpiBuildBaconLast(void)
{
  Ifx_QSPI_BACON bacon;

  bacon.U = 0UL;
  bacon.B.LAST = 1U;
  bacon.B.IPRE = 1U;
  bacon.B.IDLE = 5U;
  bacon.B.LPRE = 1U;
  bacon.B.LEAD = 5U;
  bacon.B.TPRE = 1U;
  bacon.B.TRAIL = 5U;
  bacon.B.PARTYP = 0U;
  bacon.B.UINT = 1U;
  bacon.B.MSB = 1U;
  bacon.B.BYTE = 0U;
  bacon.B.DL = 31U; /* 32-bit frame */
  bacon.B.CS = 2U;  /* SLSO2 */
  return bacon.U;
}

void Tle5012bd_SpiHwInit(void)
{
  Tle5012bd_SpiBaconLast = Tle5012bd_SpiBuildBaconLast();

  /* 在 MCAL Spi_Init 完成 CLC/PISEL 之后，把运行期 SFR 对齐到 SpiJob_5012BD 配置：
   * GLOBALCON : 模块主配置（使能/主模式/时钟源/EXPECT 超时）
   * GLOBALCON1: FIFO 中断模式/相位转换事件
   * ECON[2]   : SLSO2 通道的位时序（Q/A/B/C、CPH/CPOL、字节序）
   * SSOC      : SLSO2 输出使能 + 有效电平
   * FLAGSCLEAR: 写 1 清除所有历史错误/事件标志，保证干净起点 */
  MODULE_QSPI2.GLOBALCON.U = TLE5012BD_QSPI2_GLOBALCON_VAL;
  MODULE_QSPI2.GLOBALCON1.U = TLE5012BD_QSPI2_GLOBALCON1_VAL;
  MODULE_QSPI2.ECON[TLE5012BD_QSPI2_ECON_INDEX].U = TLE5012BD_QSPI2_ECON_VAL;
  MODULE_QSPI2.SSOC.U = TLE5012BD_QSPI2_SSOC_VAL;
  MODULE_QSPI2.FLAGSCLEAR.U = TLE5012BD_SPI_FLAGSCLEAR_VAL;

  Tle5012bd_SpiHwReady = 1U;
}

Std_ReturnType Tle5012bd_SpiExchangeU32(uint32 txWord, uint32 *rxWord)
{
  uint32 timeout;
  uint32 status;
  Ifx_QSPI *qspi = &MODULE_QSPI2;

  Tle5012bd_SpiLastTxWord = txWord;
  Tle5012bd_SpiLastRxWord = 0U;
  Tle5012bd_SpiLastResult = E_NOT_OK;

  if ((rxWord == NULL_PTR) || (Tle5012bd_SpiHwReady == 0U))
  {
    return E_NOT_OK;
  }

  /* 丢弃 RXFIFO 里残留的旧数据：
   * STATUS.RXFIFOLEVEL[21:19] = 接收 FIFO 深度，>0 则从 RXEXIT 弹出一次。 */
  timeout = 8UL;
  while ((qspi->STATUS.B.RXFIFOLEVEL != 0U) && (timeout > 0UL))
  {
    (void)qspi->RXEXIT.U;
    timeout--;
  }

  /* 清历史错误/事件标志，避免上一帧残留影响本次判定。 */
  qspi->FLAGSCLEAR.U = TLE5012BD_SPI_FLAGSCLEAR_VAL;
  /* BACONENTRY：把帧控制字压入 TXFIFO（决定本帧时序/长度/片选）。 */
  qspi->BACONENTRY.U = Tle5012bd_SpiBaconLast;
  /* DATAENTRY[0]：把待发送的 32 位数据写入 TXFIFO，QSPI 自动启动传输。 */
  qspi->DATAENTRY[0].U = txWord;

  /* 轮询 STATUS 直到“发送事件置位 且 RXFIFO 深度=1”：
   *   STATUS.TXF[9]        发送事件标志
   *   STATUS.RXFIFOLEVEL   接收 FIFO 深度
   *   STATUS.ERRORFLAGS[8:0] 任何错误位置位 → 本次传输失败 */
  timeout = TLE5012BD_SPI_POLL_TIMEOUT;
  do
  {
    status = qspi->STATUS.U;
    if ((status & TLE5012BD_SPI_HW_ERROR_MASK) != 0UL)
    {
      qspi->FLAGSCLEAR.U = TLE5012BD_SPI_FLAGSCLEAR_VAL;
      return E_NOT_OK;
    }
    if ((status & TLE5012BD_SPI_TXF_RXFIFO_MASK) == TLE5012BD_SPI_TXF_RXFIFO_1_SET)
    {
      break;
    }
    timeout--;
  } while (timeout > 0UL);

  if (timeout == 0UL)
  {
    qspi->FLAGSCLEAR.U = TLE5012BD_SPI_FLAGSCLEAR_VAL;
    return E_NOT_OK;
  }

  /* RXEXIT：从接收 FIFO 弹出本次收到的 32 位数据。 */
  *rxWord = qspi->RXEXIT.U;
  Tle5012bd_SpiLastRxWord = *rxWord;

  /* 等待传输退出 busy 相位：STATUS.PHASE[31:28]=0 表示已回到空闲，
   * 确保 CS（SLSO2）已释放，下一帧不会和本帧粘连。 */
  timeout = TLE5012BD_SPI_POLL_TIMEOUT;
  while ((qspi->STATUS.B.PHASE != 0U) && (timeout > 0UL))
  {
    if ((qspi->STATUS.U & TLE5012BD_SPI_HW_ERROR_MASK) != 0UL)
    {
      qspi->FLAGSCLEAR.U = TLE5012BD_SPI_FLAGSCLEAR_VAL;
      return E_NOT_OK;
    }
    timeout--;
  }

  Tle5012bd_SpiLastResult = E_OK;
  return E_OK;
}
