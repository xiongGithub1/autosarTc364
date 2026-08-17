/**********************************************************************************************************************
 *  MotorCdd_Adc.c — 三相电流 / 母线电压采样与快速环入口（Core1）
 *  -------------------------------------------------------------------------------------------------------------------
 *  硬件链路：
 *    GTM ATOM0 CH7（周期 10000 ticks @100 MHz = 10 kHz）触发 EVADC 同步组
 *    G0(RES0=VO1, RES1=VRO) / G2(RES0=VO2, RES1=VINV) / G3(RES0=VO3)
 *    采样点默认 5000 ticks（周期中心，避开开关沿，采样 PWM 平均电流）
 *  中断链路：
 *    ADC 组通知(Adc_9183SenseVo1andVro_Notification)
 *      → MotorCdd_AdcGroup0Notification（直读 RES 寄存器）
 *      → MotorCdd_AdcRunFastLoop（电流换算 → 滤波 → MotorCdd_FocFastLoop）
 *  电流换算：i = (VRO - VOx - offset) × CURR_CON_FACTOR（分流电阻+增益）
 *  offset：PWM 关闭零电流状态下累计 100 拍平均值，滤除运放/ADC 零偏。
 *  滤波：一阶低通 y+=α(x-y)；默认 α=0.611（fc=fs/4=2500 Hz @10 kHz），UDE 可改。
 **********************************************************************************************************************/
#include "MotorCdd_Adc.h"
#include "MotorCdd_Foc.h"
#include "Adc_Cfg.h"
#include "Mcu_17_TimerIp.h"
#include "IfxGtm_reg.h"
#include "IfxEvadc_reg.h"
#include "IfxSrc_reg.h"
#include "string.h"
#include "Dio.h"
#include "Os.h"
/*
 * SyncChannelMask = CH1 | CH4. Fast path reads EVADC result SFRs directly
 * (no Adc_ReadGroup). Master SetupResultBuffer still needs 6 slots for MCAL ISR.
 *   G0.RES[0] VO1 (ADC0 CH4)
 *   G0.RES[1] VRO (ADC0 CH1)
 *   G2.RES[0] VO2 (ADC2 CH4, sync slave)
 *   G2.RES[1] VINV (ADC2 CH1, sync slave)
 *   G3.RES[0] VO3 (ADC3 CH4, sync slave)
 */
#define MOTORCDD_ADC_MASTER_BUF_COUNT          (6U)
#define MOTORCDD_ADC_RES_VALUE_MASK            (0x00000FFFU)

#define MOTORCDD_ADC_CURR_CON_FACTOR           (0.0310885097645123F)
#define MOTORCDD_ADC_VRO_CON_FACTOR            (0.0012210012210012F)
#define MOTORCDD_ADC_VINV_CON_FACTOR           (0.0095238095238095F)
#define MOTORCDD_ADC_OFFSET_AVG_COUNT          (100U)
/*
 * First-order LPF @ fs=10 kHz (same form as upperComputer):
 *   y += α * (x - y) ,  α = 2π·fc·Ts / (1 + 2π·fc·Ts)
 * Defaults to fc = fs/4 = 2500 Hz → α = 0.6110
 * For fc = fs/3 ≈ 3333 Hz set MotorCdd_AdcCurrentFilterAlpha = 0.6768 in UDE.
 * (Old 0.1116 was ~400 Hz — too heavy for current loop.)
 */
#define MOTORCDD_ADC_CURRENT_FILTER_ALPHA_FS_DIV4  (0.6110F) /* fc=2500 Hz */
#define MOTORCDD_ADC_CURRENT_FILTER_ALPHA_FS_DIV3  (0.6768F) /* fc≈3333 Hz */
#define MOTORCDD_ADC_CURRENT_FILTER_ALPHA_DEFAULT  \
    (MOTORCDD_ADC_CURRENT_FILTER_ALPHA_FS_DIV4)

/* ADC HW trigger is GTM ATOM0 channel 7, shared with PWM ATOM0 CH1/2/3. */
#define MOTORCDD_ADC_TRIGGER_ATOM_MODULE        (0U)
#define MOTORCDD_ADC_TRIGGER_ATOM_CHANNEL       (7U)
#define MOTORCDD_ADC_TRIGGER_PERIOD_TICKS       (10000U)
#define MOTORCDD_ADC_TRIGGER_BLANKING_TICKS     (400U)
/* Center-aligned PWM: sample near period center (peak). */
#define MOTORCDD_ADC_TRIGGER_DEFAULT_TICKS      (5000U)



static Adc_ValueGroupType MotorCdd_AdcMasterBuf[MOTORCDD_ADC_MASTER_BUF_COUNT];
static MotorCdd_AdcRawType MotorCdd_AdcRaw;
static MotorCdd_AdcPhysicalType MotorCdd_AdcPhysical;
static float32 MotorCdd_AdcCurrentFilterIuA;
static float32 MotorCdd_AdcCurrentFilterIvA;
static float32 MotorCdd_AdcCurrentFilterIwA;
volatile sint32 MotorCdd_AdcPhaseOffsetVo1;
volatile sint32 MotorCdd_AdcPhaseOffsetVo2;
volatile sint32 MotorCdd_AdcPhaseOffsetVo3;
static volatile uint32 MotorCdd_AdcSyncCompleteCounter = 0U;

volatile uint8 MotorCdd_AdcCurrentOffsetReady = 0U;
volatile uint16 MotorCdd_AdcOffsetSampleCount = 0U;
volatile uint8 MotorCdd_AdcCurrentFilterEnabled = 1U;
volatile uint8 MotorCdd_AdcCurrentFilterReady = 0U;
volatile float32 MotorCdd_AdcCurrentFilterAlpha =
    MOTORCDD_ADC_CURRENT_FILTER_ALPHA_DEFAULT;
/* 1 = reconstruct one phase by iu+iv+iw=0 (default: W from U+V). */
volatile uint8 MotorCdd_AdcReconstructEnable = 1U;
/* 0=U=-(V+W), 1=V=-(U+W), 2=W=-(U+V). Prefer 2: U/V on G0/G2 sync. */
volatile uint8 MotorCdd_AdcReconstructPhase = 2U;
volatile uint32 MotorCdd_AdcTriggerTick = MOTORCDD_ADC_TRIGGER_DEFAULT_TICKS;
volatile uint32 MotorCdd_AdcTriggerTickApplied = 0U;
volatile uint32 MotorCdd_AdcPwmCounterSyncCount = 0U;
static sint32 MotorCdd_AdcOffsetSumVo1 = 0;
static sint32 MotorCdd_AdcOffsetSumVo2 = 0;
static sint32 MotorCdd_AdcOffsetSumVo3 = 0;



void Adc_9183SenseVo1andVro_Notification(void)
{
  MotorCdd_AdcGroup0Notification();
}


static uint32 MotorCdd_AdcClampTriggerTick(uint32 triggerTick)
{
  if (triggerTick < MOTORCDD_ADC_TRIGGER_BLANKING_TICKS)
  {
    return MOTORCDD_ADC_TRIGGER_BLANKING_TICKS;
  }

  if (triggerTick > (MOTORCDD_ADC_TRIGGER_PERIOD_TICKS -
                     MOTORCDD_ADC_TRIGGER_BLANKING_TICKS))
  {
    return (MOTORCDD_ADC_TRIGGER_PERIOD_TICKS -
            MOTORCDD_ADC_TRIGGER_BLANKING_TICKS);
  }

  return triggerTick;
}

/* 设置 ADC 触发点（ATOM0 CH7，周期 10000 ticks @100MHz = 10 kHz）：
 *   GTM_ATOM0_CH7_SR1 ：影子比较值（下次更新点生效）
 *   Mcu_17_Gtm_AtomChannelShadowTransfer ：MCAL 封装的影子传输（SR1→CM1）
 *   GTM_ATOM0_CH7_CM1 ：更新后的实际比较值（回读确认）
 * 默认 5000 ticks = 周期中心，避开开关沿，采样 PWM 平均电流。 */
void MotorCdd_AdcSetTriggerTick(uint32 triggerTick)
{
  uint32 appliedTick = MotorCdd_AdcClampTriggerTick(triggerTick);

  MotorCdd_AdcTriggerTick = appliedTick;
  GTM_ATOM0_CH7_SR1.U = appliedTick;
  Mcu_17_Gtm_AtomChannelShadowTransfer(MOTORCDD_ADC_TRIGGER_ATOM_MODULE,
                                        MOTORCDD_ADC_TRIGGER_ATOM_CHANNEL);
  MotorCdd_AdcTriggerTickApplied = GTM_ATOM0_CH7_CM1.U;
}

/* 使能输出前把 PWM(CH1/2/3) 与 ADC 触发(CH7) 的计数器 CN0 全部清零，
 * 让采样点与 PWM 周期从同一相位起点开始（CN0 为通道自由运行计数器）。 */
void MotorCdd_AdcSynchronizePwmTriggerCounter(void)
{
  /* PWM CH1/2/3 与 ADC 触发 CH7 共用 ATOM0 + CMU CLK0。 */
  GTM_ATOM0_CH1_CN0.U = 0U;
  GTM_ATOM0_CH2_CN0.U = 0U;
  GTM_ATOM0_CH3_CN0.U = 0U;
  GTM_ATOM0_CH7_CN0.U = 0U;
  MotorCdd_AdcPwmCounterSyncCount++;
}

static float32 MotorCdd_AdcRawToCurrent(Adc_ValueGroupType phaseRaw,
                                        Adc_ValueGroupType vroRaw,
                                        sint32 phaseOffset)
{
  sint32 delta;

  delta = ((sint32)vroRaw - (sint32)phaseRaw) - phaseOffset;
  return ((float32)delta * MOTORCDD_ADC_CURR_CON_FACTOR);
}

static float32 MotorCdd_AdcClampFilterAlpha(float32 alpha)
{
  if (alpha < 0.0F)
  {
    return 0.0F;
  }
  if (alpha > 1.0F)
  {
    return 1.0F;
  }
  return alpha;
}

static void MotorCdd_AdcFilterPhaseCurrents(void)
{
  float32 alpha = MotorCdd_AdcClampFilterAlpha(MotorCdd_AdcCurrentFilterAlpha);

  if (MotorCdd_AdcCurrentFilterEnabled == 0U)
  {
    MotorCdd_AdcCurrentFilterIuA = MotorCdd_AdcPhysical.iuRaw_A;
    MotorCdd_AdcCurrentFilterIvA = MotorCdd_AdcPhysical.ivRaw_A;
    MotorCdd_AdcCurrentFilterIwA = MotorCdd_AdcPhysical.iwRaw_A;
  }
  else if (MotorCdd_AdcCurrentFilterReady == 0U)
  {
    /* Do not introduce a startup transient after offset calibration. */
    MotorCdd_AdcCurrentFilterIuA = MotorCdd_AdcPhysical.iuRaw_A;
    MotorCdd_AdcCurrentFilterIvA = MotorCdd_AdcPhysical.ivRaw_A;
    MotorCdd_AdcCurrentFilterIwA = MotorCdd_AdcPhysical.iwRaw_A;
  }
  else
  {
    MotorCdd_AdcCurrentFilterIuA +=
        alpha * (MotorCdd_AdcPhysical.iuRaw_A - MotorCdd_AdcCurrentFilterIuA);
    MotorCdd_AdcCurrentFilterIvA +=
        alpha * (MotorCdd_AdcPhysical.ivRaw_A - MotorCdd_AdcCurrentFilterIvA);
    MotorCdd_AdcCurrentFilterIwA +=
        alpha * (MotorCdd_AdcPhysical.iwRaw_A - MotorCdd_AdcCurrentFilterIwA);
  }

  MotorCdd_AdcCurrentFilterReady = 1U;
  MotorCdd_AdcPhysical.iu_A = MotorCdd_AdcCurrentFilterIuA;
  MotorCdd_AdcPhysical.iv_A = MotorCdd_AdcCurrentFilterIvA;
  MotorCdd_AdcPhysical.iw_A = MotorCdd_AdcCurrentFilterIwA;
}

/* Three-wire motor: iu+iv+iw must be ~0. Subtract common-mode to kill
 * sensor/ADC bias that otherwise shifts all three phases below (or above) 0.
 * Skipped when third phase is reconstructed (sum is already forced to 0). */
static void MotorCdd_AdcRemoveCommonMode(void)
{
  float32 common;

  if (MotorCdd_AdcReconstructEnable != 0U)
  {
    return;
  }

  common =
      (MotorCdd_AdcPhysical.iu_A + MotorCdd_AdcPhysical.iv_A +
       MotorCdd_AdcPhysical.iw_A) *
      (1.0F / 3.0F);

  MotorCdd_AdcPhysical.iu_A -= common;
  MotorCdd_AdcPhysical.iv_A -= common;
  MotorCdd_AdcPhysical.iw_A -= common;
}

/* Reconstruct one phase from the other two (Kirchhoff). Default: measure
 * U(VO1)+V(VO2) on G0/G2 sync group, set W = -(U+V). */
static void MotorCdd_AdcReconstructThirdPhase(void)
{
  if (MotorCdd_AdcReconstructEnable == 0U)
  {
    return;
  }

  switch (MotorCdd_AdcReconstructPhase)
  {
    case 0U:
      MotorCdd_AdcPhysical.iuRaw_A =
          -(MotorCdd_AdcPhysical.ivRaw_A + MotorCdd_AdcPhysical.iwRaw_A);
      break;
    case 1U:
      MotorCdd_AdcPhysical.ivRaw_A =
          -(MotorCdd_AdcPhysical.iuRaw_A + MotorCdd_AdcPhysical.iwRaw_A);
      break;
    case 2U:
    default:
      MotorCdd_AdcPhysical.iwRaw_A =
          -(MotorCdd_AdcPhysical.iuRaw_A + MotorCdd_AdcPhysical.ivRaw_A);
      break;
  }
}

static void MotorCdd_AdcResetOffsetAccumulator(void)
{
  MotorCdd_AdcCurrentOffsetReady = 0U;
  MotorCdd_AdcOffsetSampleCount = 0U;
  MotorCdd_AdcOffsetSumVo1 = 0;
  MotorCdd_AdcOffsetSumVo2 = 0;
  MotorCdd_AdcOffsetSumVo3 = 0;
}

void MotorCdd_AdcResetCurrentFilter(void)
{

  MotorCdd_AdcCurrentFilterIuA = 0.0F;
  MotorCdd_AdcCurrentFilterIvA = 0.0F;
  MotorCdd_AdcCurrentFilterIwA = 0.0F;
  MotorCdd_AdcCurrentFilterReady = 0U;
}

/* 直读 EVADC 结果寄存器（IfxEvadc_reg.h GxRES，位定义见 Ifx_EVADC_G_RES_Bits）：
 *   RESULT [15:0] ：最近一次转换结果（本工程 12 位有效，掩码 0x0FFF）
 *   DRC    [19:16]：数据缩减计数器（多次采样累加时用）
 *   CHNR   [24:20]：完成转换的通道号
 *   EMUX   [27:25]：外部多路选择设置
 *   CRS    [29:28]：转换请求源（硬件触发等）
 *   VF     [31]   ：有效标志（1=该结果已更新）
 * G0 为主组（同步触发），G2/G3 为同步从组，结果在 G0 中断时已全部就绪。 */
static void MotorCdd_AdcFillRawFromHwRegs(MotorCdd_AdcRawType* rawOut)
{
  /* G0.RES[0] = VO1（U 相电流分流电压） */
  rawOut->vo1 = (Adc_ValueGroupType)(MODULE_EVADC.G[0].RES[0].U &
                                     MOTORCDD_ADC_RES_VALUE_MASK);
  /* G0.RES[1] = VRO（分流参考电压） */
  rawOut->vro = (Adc_ValueGroupType)(MODULE_EVADC.G[0].RES[1].U &
                                     MOTORCDD_ADC_RES_VALUE_MASK);
  /* G2.RES[0] = VO2（V 相电流分流电压） */
  rawOut->vo2 = (Adc_ValueGroupType)(MODULE_EVADC.G[2].RES[0].U &
                                     MOTORCDD_ADC_RES_VALUE_MASK);
  /* G2.RES[1] = VINV（母线电压分压） */
  rawOut->vinv = (Adc_ValueGroupType)(MODULE_EVADC.G[2].RES[1].U &
                                      MOTORCDD_ADC_RES_VALUE_MASK);
  /* G3.RES[0] = VO3（W 相电流分流电压） */
  rawOut->vo3 = (Adc_ValueGroupType)(MODULE_EVADC.G[3].RES[0].U &
                                     MOTORCDD_ADC_RES_VALUE_MASK);
}




void MotorCdd_AdcInit(void)
{
  /* G0/G2/G3 belong to Core1 in ResourceM; Core0 EcuM only runs Adc_Init for G8.
     Without this, Adc_* from Core1 runs with ADC_UNINIT (DET off) -> no HW trigger / no ISR. */
  Adc_Init(&Adc_Config);

  (void)memset(MotorCdd_AdcMasterBuf, 0, sizeof(MotorCdd_AdcMasterBuf));
  (void)memset(&MotorCdd_AdcRaw, 0, sizeof(MotorCdd_AdcRaw));
  (void)memset(&MotorCdd_AdcPhysical, 0, sizeof(MotorCdd_AdcPhysical));
  MotorCdd_AdcPhaseOffsetVo1 = 0;
  MotorCdd_AdcPhaseOffsetVo2 = 0;
  MotorCdd_AdcPhaseOffsetVo3 = 0;
  MotorCdd_AdcSyncCompleteCounter = 0U;
  MotorCdd_AdcResetOffsetAccumulator();
  MotorCdd_AdcResetCurrentFilter();
}

void MotorCdd_AdcHwTriggerInit(void)
{
  (void)Adc_SetupResultBuffer(AdcConf_AdcGroup_AdcGroup_9183Sense,
                              MotorCdd_AdcMasterBuf);

  /* Sync master/slave: arm HW trigger and notification on the master only. */
  (void)Adc_EnableHardwareTrigger(AdcConf_AdcGroup_AdcGroup_9183Sense);

  /* Apply the common sample point only after all users of ATOM0 CH7 are set up. */
  MotorCdd_AdcSetTriggerTick(MotorCdd_AdcTriggerTick);

  Adc_EnableGroupNotification(AdcConf_AdcGroup_AdcGroup_9183Sense);

  /* SRC_VADCG0SR0（Ifx_SRC_SRCR_Bits）：
   *   SRPN [7:0]   ：服务请求优先级号（由 Irq 配置）
   *   SRE  [10]    ：服务请求使能（1=允许该中断源触发）
   *   TOS  [13:11] ：服务类型（=CPU1，ADC 中断进 Core1）
   * IrqAdc_Init 在 Core0 运行可能清掉 SRE，这里补一次使能。 */
  SRC_VADCG0SR0.B.SRE = 1U;
}

/* 快速环入口（ADC 中断上下文，10 kHz）：
   先做 ADC 原始值→物理量换算（电流/母线电压），再调用 FOC 快速环。 */void MotorCdd_AdcRunFastLoop(void)
{

  MotorCdd_AdcConvertToPhysical();
  MotorCdd_FocFastLoop();

}

/* ADC 组 G0/G2/G3 同步转换完成通知（中断上下文）：
   直读 EVADC RES 寄存器 → 更新原始值 → 立即执行快速环。
   采样与 FOC 在同一中断内完成，保证电流与 PWM 同拍。 */void MotorCdd_AdcGroup0Notification(void)
{

//  Dio_WriteChannel(DioConf_DioChannel_DioChannel_test2, STD_LOW);
//  Dio_FlipChannel(DioConf_DioChannel_DioChannel_test2);
//  Dio_WriteChannel(DioConf_DioChannel_DioChannel_test2, STD_HIGH);
  MotorCdd_AdcFillRawFromHwRegs(&MotorCdd_AdcRaw);
  MotorCdd_AdcSyncCompleteCounter++;

  MotorCdd_AdcRunFastLoop();

//  (void)SetEvent(MotorTask,
//                 Rte_Ev_Run_MotorCdd_AdcSampleReady_Rp_AdcSampleReady_AdcSampleReady);
//  Dio_WriteChannel(DioConf_DioChannel_DioChannel_test2, STD_LOW);


}



void MotorCdd_AdcConvertToPhysical(void)
{
  MotorCdd_AdcPhysical.iuRaw_A = MotorCdd_AdcRawToCurrent(MotorCdd_AdcRaw.vo1,
                                                          MotorCdd_AdcRaw.vro,
                                                          MotorCdd_AdcPhaseOffsetVo1);
  MotorCdd_AdcPhysical.ivRaw_A = MotorCdd_AdcRawToCurrent(MotorCdd_AdcRaw.vo2,
                                                          MotorCdd_AdcRaw.vro,
                                                          MotorCdd_AdcPhaseOffsetVo2);
  MotorCdd_AdcPhysical.iwRaw_A = MotorCdd_AdcRawToCurrent(MotorCdd_AdcRaw.vo3,
                                                          MotorCdd_AdcRaw.vro,
                                                          MotorCdd_AdcPhaseOffsetVo3);
  /* U/V on G0/G2 sync; default rebuild W so FOC never uses lone G3 sample. */
  MotorCdd_AdcReconstructThirdPhase();
  MotorCdd_AdcFilterPhaseCurrents();
  MotorCdd_AdcRemoveCommonMode();
  MotorCdd_AdcPhysical.vro_V = ((float32)MotorCdd_AdcRaw.vro * MOTORCDD_ADC_VRO_CON_FACTOR);
  MotorCdd_AdcPhysical.vinv_V = ((float32)MotorCdd_AdcRaw.vinv * MOTORCDD_ADC_VINV_CON_FACTOR);
}

void MotorCdd_AdcCaptureCurrentOffset(void)
{
  MotorCdd_AdcPhaseOffsetVo1 = (sint32)MotorCdd_AdcRaw.vro - (sint32)MotorCdd_AdcRaw.vo1;
  MotorCdd_AdcPhaseOffsetVo2 = (sint32)MotorCdd_AdcRaw.vro - (sint32)MotorCdd_AdcRaw.vo2;
  MotorCdd_AdcPhaseOffsetVo3 = (sint32)MotorCdd_AdcRaw.vro - (sint32)MotorCdd_AdcRaw.vo3;
  MotorCdd_AdcCurrentOffsetReady = 1U;
  MotorCdd_AdcResetCurrentFilter();
  MotorCdd_AdcConvertToPhysical();
}

void MotorCdd_AdcResetCurrentOffsetCapture(void)
{
  MotorCdd_AdcResetOffsetAccumulator();
  MotorCdd_AdcResetCurrentFilter();
}

void MotorCdd_AdcAccumulateCurrentOffset(void)
{
  if (MotorCdd_AdcCurrentOffsetReady != 0U)
  {
    return;
  }

  MotorCdd_AdcOffsetSumVo1 += ((sint32)MotorCdd_AdcRaw.vro - (sint32)MotorCdd_AdcRaw.vo1);
  MotorCdd_AdcOffsetSumVo2 += ((sint32)MotorCdd_AdcRaw.vro - (sint32)MotorCdd_AdcRaw.vo2);
  MotorCdd_AdcOffsetSumVo3 += ((sint32)MotorCdd_AdcRaw.vro - (sint32)MotorCdd_AdcRaw.vo3);
  MotorCdd_AdcOffsetSampleCount++;

  if (MotorCdd_AdcOffsetSampleCount >= MOTORCDD_ADC_OFFSET_AVG_COUNT)
  {
    MotorCdd_AdcSetCurrentOffset(
        (MotorCdd_AdcOffsetSumVo1 / (sint32)MOTORCDD_ADC_OFFSET_AVG_COUNT),
        (MotorCdd_AdcOffsetSumVo2 / (sint32)MOTORCDD_ADC_OFFSET_AVG_COUNT),
        (MotorCdd_AdcOffsetSumVo3 / (sint32)MOTORCDD_ADC_OFFSET_AVG_COUNT));
    MotorCdd_AdcCurrentOffsetReady = 1U;
    MotorCdd_AdcResetCurrentFilter();
    MotorCdd_AdcConvertToPhysical();
  }
}

uint8 MotorCdd_AdcIsCurrentOffsetReady(void)
{
  return MotorCdd_AdcCurrentOffsetReady;
}

void MotorCdd_AdcSetCurrentOffset(sint32 vo1Offset,
                                  sint32 vo2Offset,
                                  sint32 vo3Offset)
{
  MotorCdd_AdcPhaseOffsetVo1 = vo1Offset;
  MotorCdd_AdcPhaseOffsetVo2 = vo2Offset;
  MotorCdd_AdcPhaseOffsetVo3 = vo3Offset;
  MotorCdd_AdcResetCurrentFilter();
}

const MotorCdd_AdcRawType* MotorCdd_GetAdcRaw(void)
{
  return &MotorCdd_AdcRaw;
}

const MotorCdd_AdcPhysicalType* MotorCdd_GetAdcPhysical(void)
{
  return &MotorCdd_AdcPhysical;
}

uint32 MotorCdd_GetAdcSyncCompleteCounter(void)
{
  return MotorCdd_AdcSyncCompleteCounter;
}
