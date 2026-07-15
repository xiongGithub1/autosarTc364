#ifndef MOTORCDD_ADC_H
#define MOTORCDD_ADC_H

#include "Std_Types.h"
#include "Adc.h"

typedef struct
{
  Adc_ValueGroupType vo1;
  Adc_ValueGroupType vro;
  Adc_ValueGroupType vo2;
  Adc_ValueGroupType vinv;
  Adc_ValueGroupType vo3;
} MotorCdd_AdcRawType;

typedef struct
{
  /* Unfiltered phase currents after ADC offset compensation. */
  float32 iuRaw_A;
  float32 ivRaw_A;
  float32 iwRaw_A;
  /* Filtered phase currents consumed by the FOC current loop. */
  float32 iu_A;
  float32 iv_A;
  float32 iw_A;
  float32 vro_V;
  float32 vinv_V;
} MotorCdd_AdcPhysicalType;

extern volatile sint32 MotorCdd_AdcPhaseOffsetVo1;
extern volatile sint32 MotorCdd_AdcPhaseOffsetVo2;
extern volatile sint32 MotorCdd_AdcPhaseOffsetVo3;
extern volatile uint8 MotorCdd_AdcCurrentOffsetReady;
extern volatile uint16 MotorCdd_AdcOffsetSampleCount;
extern volatile uint8 MotorCdd_AdcCurrentFilterEnabled;
extern volatile uint8 MotorCdd_AdcCurrentFilterReady;
extern volatile float32 MotorCdd_AdcCurrentFilterAlpha;
extern volatile uint32 MotorCdd_AdcTriggerTick;
extern volatile uint32 MotorCdd_AdcTriggerTickApplied;
extern volatile uint32 MotorCdd_AdcPwmCounterSyncCount;
/* ISR wanted to wake Motortask while previous AdcOnSampleReady still pending. */
extern volatile uint32 MotorCdd_AdcMissedWakeCounter;

void MotorCdd_AdcInit(void);
void MotorCdd_AdcHwTriggerInit(void);
void MotorCdd_AdcSetTriggerTick(uint32 triggerTick);
void MotorCdd_AdcSynchronizePwmTriggerCounter(void);
void MotorCdd_AdcGroup0Notification(void);
/* Called from MotorTask via RTE ExternalTrigger OsEvent (not from ADC ISR). */
void MotorCdd_AdcOnSampleReady(void);
void MotorCdd_AdcConvertToPhysical(void);
void MotorCdd_AdcCaptureCurrentOffset(void);
void MotorCdd_AdcResetCurrentOffsetCapture(void);
void MotorCdd_AdcAccumulateCurrentOffset(void);
void MotorCdd_AdcResetCurrentFilter(void);
uint8 MotorCdd_AdcIsCurrentOffsetReady(void);
void MotorCdd_AdcSetCurrentOffset(sint32 vo1Offset,
                                  sint32 vo2Offset,
                                  sint32 vo3Offset);
const MotorCdd_AdcRawType* MotorCdd_GetAdcRaw(void);
const MotorCdd_AdcPhysicalType* MotorCdd_GetAdcPhysical(void);
uint32 MotorCdd_GetAdcSyncCompleteCounter(void);

#endif /* MOTORCDD_ADC_H */
