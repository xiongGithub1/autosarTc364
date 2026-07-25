#include "MotorCdd_Adc.h"
#include "MotorCdd_Foc.h"
#include "Adc_Cfg.h"
#include "Mcu_17_TimerIp.h"
#include "IfxGtm_reg.h"
#include "IfxEvadc_reg.h"
#include "IfxEvadc_bf.h"
#include "string.h"
#include "Dio.h"
/*
 * Master AdcGroup_9183Sense ReadGroup layout with SyncChannelMask = CH1 | CH4:
 *   [0] VO1 (ADC0 CH4)
 *   [1] VRO (ADC0 CH1)
 *   [2] VO2 (ADC2 CH4, sync slave)
 *   [3] VINV (ADC2 CH1, sync slave)
 *   [4] VO3 (ADC3 CH4, sync slave)
 *   [5] ADC3 CH1 (sync slave, unused)
 *
 * Adc_ReadGroup appends every synchronized slave result in master channel
 * order. The result buffer must therefore reserve all six values.
 */
#define MOTORCDD_ADC_MASTER_BUF_COUNT          (6U)
#define MOTORCDD_ADC_MASTER_VO1_IDX            (0U)
#define MOTORCDD_ADC_MASTER_VRO_IDX            (1U)
#define MOTORCDD_ADC_MASTER_VO2_IDX            (2U)
#define MOTORCDD_ADC_MASTER_VINV_IDX           (3U)
#define MOTORCDD_ADC_MASTER_VO3_IDX            (4U)

#define MOTORCDD_ADC_VINV_KERNEL               (2U)
#define MOTORCDD_ADC_VINV_AN_CHANNEL           (1U)
#define MOTORCDD_ADC_VINV_RESULT_REG           (1U)
#define MOTORCDD_ADC_VRO_AN_CHANNEL            (1U)

#define MOTORCDD_ADC_CURR_CON_FACTOR           (0.0310885097645123F)
#define MOTORCDD_ADC_VRO_CON_FACTOR            (0.0012210012210012F)
#define MOTORCDD_ADC_VINV_CON_FACTOR           (0.0095238095238095F)
#define MOTORCDD_ADC_OFFSET_AVG_COUNT          (100U)
/* TC364 reference: 10 kHz sample rate, first-order LPF near 1 kHz. */
#define MOTORCDD_ADC_CURRENT_FILTER_ALPHA_DEFAULT (0.3857F)

/* ADC HW trigger is GTM ATOM0 channel 7, shared with PWM ATOM0 CH1/2/3. */
#define MOTORCDD_ADC_TRIGGER_ATOM_MODULE        (0U)
#define MOTORCDD_ADC_TRIGGER_ATOM_CHANNEL       (7U)
#define MOTORCDD_ADC_TRIGGER_PERIOD_TICKS       (10000U)
#define MOTORCDD_ADC_TRIGGER_BLANKING_TICKS     (400U)
/* Center-aligned PWM: sample near period center (peak). */
#define MOTORCDD_ADC_TRIGGER_DEFAULT_TICKS      (5000U)

#define MOTORCDD_ADC_RAW_SNAP_COUNT            (2U)
/* Re-apply VINV SYNC every N ISR (oneshoot re-arm); avoid full register write at 10 kHz. */
#define MOTORCDD_ADC_VINV_SYNC_REARM_PERIOD    (8U)

/* ISR scratch / MCAL result buffer 鈥� Task must not read this directly. */
static Adc_ValueGroupType MotorCdd_AdcMasterBuf[MOTORCDD_ADC_MASTER_BUF_COUNT];

/* Ping-pong raw frames published by ISR; Task copies then converts. */
static MotorCdd_AdcRawType MotorCdd_AdcRawSnap[MOTORCDD_ADC_RAW_SNAP_COUNT];
static volatile uint8 MotorCdd_AdcRawWriteIdx = 0U;
static volatile uint8 MotorCdd_AdcRawReadyIdx = 0U;
static uint8 MotorCdd_AdcVinvSyncRearmCnt = 0U;

/* Frozen frame owned by Task after copy under interrupt lock. */
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
volatile uint32 MotorCdd_AdcTriggerTick = MOTORCDD_ADC_TRIGGER_DEFAULT_TICKS;
volatile uint32 MotorCdd_AdcTriggerTickApplied = 0U;
volatile uint32 MotorCdd_AdcPwmCounterSyncCount = 0U;
static sint32 MotorCdd_AdcOffsetSumVo1 = 0;
static sint32 MotorCdd_AdcOffsetSumVo2 = 0;
static sint32 MotorCdd_AdcOffsetSumVo3 = 0;

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

void MotorCdd_AdcSetTriggerTick(uint32 triggerTick)
{
  uint32 appliedTick = MotorCdd_AdcClampTriggerTick(triggerTick);

  MotorCdd_AdcTriggerTick = appliedTick;
  GTM_ATOM0_CH7_SR1.U = appliedTick;
  Mcu_17_Gtm_AtomChannelShadowTransfer(MOTORCDD_ADC_TRIGGER_ATOM_MODULE,
                                        MOTORCDD_ADC_TRIGGER_ATOM_CHANNEL);
  MotorCdd_AdcTriggerTickApplied = GTM_ATOM0_CH7_CM1.U;
}

void MotorCdd_AdcSynchronizePwmTriggerCounter(void)
{
  /* PWM CH1/2/3 and the ADC trigger CH7 use ATOM0 and CMU clock 0. */
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

/*
 * MCAL SyncChannelMask is CH4-only (phase currents). Enable CH1 SYNC so that
 * VINV(G2CH1) converts with VRO(G0CH1); result is read from G2.RES[1].
 */
static void MotorCdd_AdcEnableVinvSyncWithVro(void)
{
  uint32 masterVroChctr;

  masterVroChctr = MODULE_EVADC.G[0].CHCTR[MOTORCDD_ADC_VRO_AN_CHANNEL].U;
  masterVroChctr |= ((uint32)1UL << (uint32)IFX_EVADC_G_CHCTR_SYNC_OFF);
  MODULE_EVADC.G[0].CHCTR[MOTORCDD_ADC_VRO_AN_CHANNEL].U = masterVroChctr;

  MODULE_EVADC.G[MOTORCDD_ADC_VINV_KERNEL].CHCTR[MOTORCDD_ADC_VINV_AN_CHANNEL].U =
      masterVroChctr;
  MODULE_EVADC.G[MOTORCDD_ADC_VINV_KERNEL].RCR[MOTORCDD_ADC_VINV_RESULT_REG].U =
      0U;

  /* Keep ADC3 CH1 lane aligned with master CH1 SYNC (unused result). */
  MODULE_EVADC.G[3].CHCTR[MOTORCDD_ADC_VRO_AN_CHANNEL].U = masterVroChctr;
  MODULE_EVADC.G[3].RCR[MOTORCDD_ADC_VINV_RESULT_REG].U = 0U;
}

static void MotorCdd_AdcFillRawFromMasterBuffer(MotorCdd_AdcRawType* rawOut)
{
  rawOut->vo1 = MotorCdd_AdcMasterBuf[MOTORCDD_ADC_MASTER_VO1_IDX];
  rawOut->vro = MotorCdd_AdcMasterBuf[MOTORCDD_ADC_MASTER_VRO_IDX];
  rawOut->vo2 = MotorCdd_AdcMasterBuf[MOTORCDD_ADC_MASTER_VO2_IDX];
  rawOut->vinv = MotorCdd_AdcMasterBuf[MOTORCDD_ADC_MASTER_VINV_IDX];
  rawOut->vo3 = MotorCdd_AdcMasterBuf[MOTORCDD_ADC_MASTER_VO3_IDX];
}

static void MotorCdd_AdcLatchFrozenRawFromIdx(uint8 readyIdx)
{
  if (readyIdx < MOTORCDD_ADC_RAW_SNAP_COUNT)
  {
    MotorCdd_AdcRaw = MotorCdd_AdcRawSnap[readyIdx];
  }
}

static void MotorCdd_AdcLatchFrozenRaw(void)
{
  uint8 readyIdx;

  SuspendAllInterrupts();
  readyIdx = MotorCdd_AdcRawReadyIdx;
  ResumeAllInterrupts();
  MotorCdd_AdcLatchFrozenRawFromIdx(readyIdx);
}

void MotorCdd_AdcInit(void)
{
  (void)memset(MotorCdd_AdcMasterBuf, 0, sizeof(MotorCdd_AdcMasterBuf));
  (void)memset(MotorCdd_AdcRawSnap, 0, sizeof(MotorCdd_AdcRawSnap));
  (void)memset(&MotorCdd_AdcRaw, 0, sizeof(MotorCdd_AdcRaw));
  (void)memset(&MotorCdd_AdcPhysical, 0, sizeof(MotorCdd_AdcPhysical));
  MotorCdd_AdcRawWriteIdx = 0U;
  MotorCdd_AdcRawReadyIdx = 0U;
  MotorCdd_AdcVinvSyncRearmCnt = 0U;
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
  MotorCdd_AdcEnableVinvSyncWithVro();

  /* Apply the common sample point only after all users of ATOM0 CH7 are set up. */
  MotorCdd_AdcSetTriggerTick(MotorCdd_AdcTriggerTick);

  Adc_EnableGroupNotification(AdcConf_AdcGroup_AdcGroup_9183Sense);
}

void MotorCdd_AdcRunFastLoop(void)
{

  MotorCdd_AdcConvertToPhysical();
  MotorCdd_FocFastLoop();

}

void MotorCdd_AdcGroup0Notification(void)
{
  uint8 writeIdx;
  Dio_WriteChannel(DioConf_DioChannel_DioChannel_test, STD_HIGH);
  if (Adc_ReadGroup(AdcConf_AdcGroup_AdcGroup_9183Sense,
                    MotorCdd_AdcMasterBuf) != E_OK)
  {
    return;
  }

  writeIdx = MotorCdd_AdcRawWriteIdx;
  if (writeIdx >= MOTORCDD_ADC_RAW_SNAP_COUNT)
  {
    writeIdx = 0U;
  }

  MotorCdd_AdcFillRawFromMasterBuffer(&MotorCdd_AdcRawSnap[writeIdx]);
  MotorCdd_AdcRawReadyIdx = writeIdx;
  MotorCdd_AdcRawWriteIdx = (uint8)(writeIdx ^ 1U);
  MotorCdd_AdcSyncCompleteCounter++;

  MotorCdd_AdcVinvSyncRearmCnt++;
  if (MotorCdd_AdcVinvSyncRearmCnt >= MOTORCDD_ADC_VINV_SYNC_REARM_PERIOD)
  {
    MotorCdd_AdcVinvSyncRearmCnt = 0U;
    /* Oneshoot HW re-arm may rewrite CHCTR without SYNC; keep VINV with VRO. */
    MotorCdd_AdcEnableVinvSyncWithVro();
  }

#if (MOTORCDD_ADC_FASTLOOP_IN_ISR == 1U)
  /* 10 kHz: sample and FOC in the same Cat2 ISR (AdcIsr_G0 must use FPU). */
  MotorCdd_AdcLatchFrozenRawFromIdx(writeIdx);
  MotorCdd_AdcRunFastLoop();
#else
  /* Legacy Task wake path — requires Os.h / SetEvent in caller wrapper. */
#endif
  Dio_WriteChannel(DioConf_DioChannel_DioChannel_test, STD_LOW);
}

void MotorCdd_AdcOnSampleReady(void)
{
#if (MOTORCDD_ADC_FASTLOOP_IN_ISR == 0U)
  MotorCdd_AdcLatchFrozenRaw();
  MotorCdd_AdcRunFastLoop();
#else
  /* Fast loop runs in ADC ISR; RTE event is unused. */
#endif
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
  MotorCdd_AdcFilterPhaseCurrents();
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
