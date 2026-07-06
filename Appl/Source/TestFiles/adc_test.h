#ifndef ADC_TEST_H
#define ADC_TEST_H

#include "Adc.h"
#include "Std_Types.h"



extern Std_ReturnType AdcTest_InitResult;
extern Std_ReturnType AdcTest_LastSampleResult;
extern uint32 AdcTest_SampleCounter;
extern uint32 AdcTest_SampleOkCounter;
extern uint32 AdcTest_SampleFailCounter;
extern uint32 AdcTest_BusySkipCounter;
extern uint32 AdcTest_TimeoutCounter;
extern uint32 AdcTest_HandlerPollCounter;
extern uint32 AdcTest_IsrEntryCounter;
extern uint8 AdcTest_SevFlagG0;
extern uint8 AdcTest_SevFlagG2;
extern uint8 AdcTest_SevFlagG3;

extern Adc_StatusType AdcTest_Group9183SenseStatus;
extern Adc_StatusType AdcTest_Group9183Vo2Status;
extern Adc_StatusType AdcTest_Group9183Vo3Status;

extern Adc_ValueGroupType AdcTest_Group9183SenseRaw[2];
extern Adc_ValueGroupType AdcTest_Group9183Vo2Raw[2];
extern Adc_ValueGroupType AdcTest_Group9183Vo3Raw[1];

extern Adc_ValueGroupType AdcTest_VroRaw;
extern Adc_ValueGroupType AdcTest_Vo1Raw;
extern Adc_ValueGroupType AdcTest_Vo2Raw;
extern Adc_ValueGroupType AdcTest_Vo3Raw;

extern uint32 AdcTest_EvadcClc;
extern uint32 AdcTest_EvadcG0Arbcfg;
extern uint32 AdcTest_EvadcG2Arbcfg;
extern uint32 AdcTest_EvadcG3Arbcfg;
extern uint32 AdcTest_EvadcG0Q0Qsr;
extern uint32 AdcTest_EvadcG2Q0Qsr;
extern uint32 AdcTest_EvadcG3Q0Qsr;
extern uint32 AdcTest_EvadcG0Res0;
extern uint32 AdcTest_EvadcG0Res1;
extern uint32 AdcTest_EvadcG2Res0;
extern uint32 AdcTest_EvadcG3Res0;
extern Adc_ValueGroupType AdcTest_VroResDirect;
extern Adc_ValueGroupType AdcTest_Vo1ResDirect;
extern Adc_ValueGroupType AdcTest_Vo2ResDirect;
extern Adc_ValueGroupType AdcTest_Vo3ResDirect;
extern uint8 AdcTest_VroResValid;
extern uint8 AdcTest_Vo1ResValid;
extern uint8 AdcTest_Vo2ResValid;
extern uint8 AdcTest_Vo3ResValid;

void AdcTest_Init(void);
void AdcTest_RunOnce(void);

#endif
