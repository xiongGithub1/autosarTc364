#ifndef PWM_TEST_H
#define PWM_TEST_H

#include "Pwm_17_GtmCcu6.h"
#include "Std_Types.h"

#define PWM_TEST_CHANNEL_COUNT       (3U)
#define PWM_TEST_DUTY_0_PERCENT      (0x0000U)
#define PWM_TEST_DUTY_10_PERCENT     (0x0333U)
#define PWM_TEST_DUTY_20_PERCENT     (0x0666U)
#define PWM_TEST_DUTY_30_PERCENT     (0x0999U)
#define PWM_TEST_DUTY_50_PERCENT     (0x1000U)
#define PWM_TEST_DUTY_100_PERCENT    (0x2000U)

extern volatile uint8 PwmTest_Enable;
extern volatile uint8 PwmTest_Mode;
extern volatile uint8 PwmTest_Initialized;
extern volatile uint8 PwmTest_UpdateRequest;
extern volatile uint32 PwmTest_RunCounter;
extern volatile uint32 PwmTest_UpdateCounter;
extern volatile uint32 PwmTest_DisabledCounter;
extern volatile Std_ReturnType PwmTest_InitCheckResult;
extern volatile uint16 PwmTest_Duty[PWM_TEST_CHANNEL_COUNT];
extern volatile uint16 PwmTest_LastAppliedDuty[PWM_TEST_CHANNEL_COUNT];
extern volatile Pwm_17_GtmCcu6_OutputStateType PwmTest_OutputState[PWM_TEST_CHANNEL_COUNT];

void PwmTest_Init(void);
void PwmTest_RunOnce(void);
void PwmTest_ApplyDuty(void);
void PwmTest_AllOff(void);

#endif
