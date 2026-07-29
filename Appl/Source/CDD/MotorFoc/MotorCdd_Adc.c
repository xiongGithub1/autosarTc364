#include "MotorCdd_Adc.h"
#include "MotorCdd_Foc.h"
#include "Adc_Cfg.h"
#include "Mcu_17_TimerIp.h"
#include "IfxGtm_reg.h"
#include "IfxEvadc_reg.h"
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
/* TC364 reference: 10 kHz sample rate, first-order LPF near 1 kHz. */
#define MOTORCDD_ADC_CURRENT_FILTER_ALPHA_DEFAULT (0.3857F)

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

static void MotorCdd_AdcFillRawFromHwRegs(MotorCdd_AdcRawType* rawOut)
{
  rawOut->vo1 = (Adc_ValueGroupType)(MODULE_EVADC.G[0].RES[0].U &
                                     MOTORCDD_ADC_RES_VALUE_MASK);
  rawOut->vro = (Adc_ValueGroupType)(MODULE_EVADC.G[0].RES[1].U &
                                     MOTORCDD_ADC_RES_VALUE_MASK);
  rawOut->vo2 = (Adc_ValueGroupType)(MODULE_EVADC.G[2].RES[0].U &
                                     MOTORCDD_ADC_RES_VALUE_MASK);
  rawOut->vinv = (Adc_ValueGroupType)(MODULE_EVADC.G[2].RES[1].U &
                                      MOTORCDD_ADC_RES_VALUE_MASK);
  rawOut->vo3 = (Adc_ValueGroupType)(MODULE_EVADC.G[3].RES[0].U &
                                     MOTORCDD_ADC_RES_VALUE_MASK);
}




void MotorCdd_AdcInit(void)
{
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
}

void MotorCdd_AdcRunFastLoop(void)
{

  MotorCdd_AdcConvertToPhysical();
  MotorCdd_FocFastLoop();

}

void MotorCdd_AdcGroup0Notification(void)
{
//  Dio_FlipChannel(DioConf_DioChannel_DioChannel_test);
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
