/**********************************************************************************************************************
 *  FILE: UartTest.c
 *  DESC: VOFA+ JustFloat FOC telemetry (ASCLIN0).
 *
 *  Capture: Core1 FOC beat into a ring (unique samples).
 *  Transmit: Core0 1 ms packs up to 10 JustFloat frames into one async Uart_Write.
 *  Do not WaitIdle between frames — Default_Appl_Task is NON and shares Core0
 *  with NvM/Fee/Fls; spinning starved Fee InitGC.
 *
 *  Frame (JCom): AA 55 + 8 * float32 LE + 00 00 80 7F = 38 B.
 *
 *  Channel map (VOFA JustFloat):
 *    f0  i_motor.u          鈫� 涓夌浉鐢垫祦椤靛彧鐢� f0/f1/f2
 *    f1  i_motor.v
 *    f2  i_motor.w
 *    f3  pwm_OutU           鈫� 椹瀺娉㈤〉鍙敤 f3/f4/f5锛堜腑蹇冪害 2500锛�
 *    f4  pwm_OutV
 *    f5  pwm_OutW
 *    f6  FOC 杩愯鐢佃搴� (0..8192 璁℃暟锛屽紑鐜�=寮哄埗瑙� / 闂幆=鎺у埗鐢ㄨ)
 *    f7  TLE5012 鐪熷疄鐢佃搴� (0..8192 璁℃暟)
 *********************************************************************************************************************/
#include "UartTest.h"
#include "Uart.h"
#include "MotorCdd_Foc.h"
#include "Tle5012bd_Driver.h"

#define UARTTEST_CHANNEL                 (0U)
#define UARTTEST_CH_COUNT                (8U)
#define UARTTEST_HDR_SIZE                (0U)
#define UARTTEST_TAIL_SIZE               (4U)
#define UARTTEST_FRAME_SIZE              (UARTTEST_HDR_SIZE + (UARTTEST_CH_COUNT * 4U) + UARTTEST_TAIL_SIZE)
#define UARTTEST_RING_DEPTH              (32U)
#define UARTTEST_BURST_PER_1MS           (10U)
#define UARTTEST_TX_BUF_SIZE             (UARTTEST_FRAME_SIZE * UARTTEST_BURST_PER_1MS)

volatile uint32 UartTest_TxOkCount = 0U;
volatile uint32 UartTest_TxBusyCount = 0U;
volatile uint32 UartTest_TxFailCount = 0U;
volatile uint32 UartTest_AbortRecoverCount = 0U;
volatile uint32 UartTest_LastStatus = 0U;
volatile uint32 UartTest_CaptureCount = 0U;
volatile uint32 UartTest_DropCount = 0U;

static Uart_MemType UartTest_TxBuf[UARTTEST_TX_BUF_SIZE];
static float32 UartTest_Ring[UARTTEST_RING_DEPTH][UARTTEST_CH_COUNT];
static volatile uint8 UartTest_WrIdx = 0U;
static volatile uint8 UartTest_RdIdx = 0U;
static volatile uint8 UartTest_Count = 0U;

static void UartTest_PutFloat(uint8 *const buf, uint16 *const pos, const float32 value)
{
  const uint8 *raw = (const uint8 *)&value;
  uint16 i;
  uint16 p = *pos;

  for (i = 0U; i < 4U; i++)
  {
    buf[p + i] = raw[i];
  }
  *pos = (uint16)(p + 4U);
}

static void UartTest_FillSnap(float32 *const dst)
{
  const MotorFoc_ContextType *ctx = &MotorCdd_FocContext;

  dst[0] = ctx->i_motor.u;
  dst[1] = ctx->i_motor.v;
  dst[2] = ctx->i_motor.w;
  dst[3] = (float32)ctx->Tpwm.pwm_OutU;
  dst[4] = (float32)ctx->Tpwm.pwm_OutV;
  dst[5] = (float32)ctx->Tpwm.pwm_OutW;
  /* Same 8192-count electrical scale for overlay on VOFA. */
  dst[6] = ctx->angle.angleRaw;
  dst[7] = Tle5012bd_Sensor.Angle;
//  dst[6]=ctx->idqRef.imag;
//  dst[7]=ctx->idqMeas.imag;
}

void UartTest_Init(void)
{
  UartTest_WrIdx = 0U;
  UartTest_RdIdx = 0U;
  UartTest_Count = 0U;
}

void UartTest_CaptureFromFoc(void)
{
  uint8 wr;
  uint8 count;

  wr = UartTest_WrIdx;
  UartTest_FillSnap(&UartTest_Ring[wr][0]);
  UartTest_WrIdx = (uint8)((wr + 1U) % UARTTEST_RING_DEPTH);

  count = UartTest_Count;
  if (count < UARTTEST_RING_DEPTH)
  {
    UartTest_Count = (uint8)(count + 1U);
  }
  else
  {
    /* Overwrite oldest unread sample. */
    UartTest_RdIdx = (uint8)((UartTest_RdIdx + 1U) % UARTTEST_RING_DEPTH);
    UartTest_DropCount++;
  }
  UartTest_CaptureCount++;
}

void UartTest_MainFunction(void)
{
  Uart_ReturnType retVal;
  Uart_StatusType status;
  uint16 pos;
  uint8 rd;
  uint8 ch;
  uint8 n;
  uint8 packed;
  uint8 count;

  count = UartTest_Count;
  if (count == 0U)
  {
    return;
  }

  status = Uart_GetStatus(UARTTEST_CHANNEL);
  UartTest_LastStatus = (uint32)status;
  if (status != UART_IDLE)
  {
    UartTest_TxBusyCount++;
    return;
  }

  packed = count;
  if (packed > UARTTEST_BURST_PER_1MS)
  {
    packed = UARTTEST_BURST_PER_1MS;
  }

  pos = 0U;
  rd = UartTest_RdIdx;
  for (n = 0U; n < packed; n++)
  {
    for (ch = 0U; ch < UARTTEST_CH_COUNT; ch++)
    {
      UartTest_PutFloat(UartTest_TxBuf, &pos, UartTest_Ring[rd][ch]);
    }
    UartTest_TxBuf[pos++] = 0x00U;
    UartTest_TxBuf[pos++] = 0x00U;
    UartTest_TxBuf[pos++] = 0x80U;
    UartTest_TxBuf[pos++] = 0x7FU;
    rd = (uint8)((rd + 1U) % UARTTEST_RING_DEPTH);
  }

  retVal = Uart_Write(UARTTEST_CHANNEL, UartTest_TxBuf, (Uart_SizeType)pos);
  if (retVal == UART_E_OK)
  {
    UartTest_TxOkCount += (uint32)packed;
    UartTest_RdIdx = rd;
    UartTest_Count = (uint8)(count - packed);
  }
  else if (retVal == UART_E_BUSY)
  {
    UartTest_TxBusyCount++;
  }
  else
  {
    UartTest_TxFailCount++;
  }
}
