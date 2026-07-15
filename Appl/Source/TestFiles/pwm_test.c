#include "pwm_test.h"

#include "Pwm_17_GtmCcu6_Cfg.h"
#include "Pwm_17_GtmCcu6_PBcfg.h"

#define PWM_TEST_MODE_MANUAL         (0U)
#define PWM_TEST_MODE_LOW_SIDE_ONLY  (1U)
#define PWM_TEST_MODE_RAMP_ALL       (2U)
#define PWM_TEST_RAMP_STEP           (0x0200U)
#define PWM_TEST_RAMP_MAX            (PWM_TEST_DUTY_50_PERCENT)

volatile uint8 PwmTest_Enable = 0U;
volatile uint8 PwmTest_Mode = PWM_TEST_MODE_LOW_SIDE_ONLY;
volatile uint8 PwmTest_Initialized = 0U;
volatile uint8 PwmTest_UpdateRequest = 0U;
volatile uint32 PwmTest_RunCounter = 0U;
volatile uint32 PwmTest_UpdateCounter = 0U;
volatile uint32 PwmTest_DisabledCounter = 0U;
volatile Std_ReturnType PwmTest_InitCheckResult = E_NOT_OK;
volatile uint16 PwmTest_Duty[PWM_TEST_CHANNEL_COUNT] =
{
  PWM_TEST_DUTY_10_PERCENT,
  PWM_TEST_DUTY_20_PERCENT,
  PWM_TEST_DUTY_30_PERCENT,

};
volatile uint16 PwmTest_LastAppliedDuty[PWM_TEST_CHANNEL_COUNT] =
{
  0U, 0U, 0U,
};
volatile Pwm_17_GtmCcu6_OutputStateType PwmTest_OutputState[PWM_TEST_CHANNEL_COUNT] =
{
  PWM_17_GTMCCU6_LOW,
  PWM_17_GTMCCU6_LOW,
  PWM_17_GTMCCU6_LOW,

};

static const Pwm_17_GtmCcu6_ChannelType PwmTest_Channel[PWM_TEST_CHANNEL_COUNT] =
{
  Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_9180IH1,
  Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_9180IH2,
  Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_9180IH3,

};

static uint16 PwmTest_RampDuty = PWM_TEST_DUTY_0_PERCENT;
static uint8 PwmTest_RampUp = 1U;

static uint16 PwmTest_LimitDuty(uint16 duty);
static void PwmTest_UpdateOutputStates(void);
static void PwmTest_UpdatePattern(void);

void PwmTest_Init(void)
{
  
  PwmTest_InitCheckResult = Pwm_17_GtmCcu6_InitCheck(&Pwm_17_GtmCcu6_Config);

  if (PwmTest_InitCheckResult == E_OK)
  {
    PwmTest_Initialized = 1U;
    PwmTest_AllOff();
  }
  else
  {
    PwmTest_Initialized = 0U;
  }
}

void PwmTest_RunOnce(void)
{
  PwmTest_RunCounter++;

  if (PwmTest_Initialized == 0U)
  {
    PwmTest_InitCheckResult = Pwm_17_GtmCcu6_InitCheck(&Pwm_17_GtmCcu6_Config);
    if (PwmTest_InitCheckResult == E_OK)
    {
      PwmTest_Initialized = 1U;
    }
    else
    {
      return;
    }
  }

  if (PwmTest_Enable == 0U)
  {
    PwmTest_AllOff();
    PwmTest_DisabledCounter++;
    return;
  }

  PwmTest_UpdatePattern();
  PwmTest_ApplyDuty();
}

void PwmTest_ApplyDuty(void)
{
  uint8 index;

  for (index = 0U; index < PWM_TEST_CHANNEL_COUNT; index++)
  {
    PwmTest_LastAppliedDuty[index] = PwmTest_LimitDuty(PwmTest_Duty[index]);
    Pwm_17_GtmCcu6_SetDutyCycle(PwmTest_Channel[index], PwmTest_LastAppliedDuty[index]);
  }

  PwmTest_UpdateRequest = 0U;
  PwmTest_UpdateCounter++;
  PwmTest_UpdateOutputStates();
}

void PwmTest_AllOff(void)
{
  uint8 index;

  for (index = 0U; index < PWM_TEST_CHANNEL_COUNT; index++)
  {
    PwmTest_LastAppliedDuty[index] = PWM_TEST_DUTY_0_PERCENT;
    Pwm_17_GtmCcu6_SetDutyCycle(PwmTest_Channel[index], PWM_TEST_DUTY_0_PERCENT);
  }

  PwmTest_UpdateOutputStates();
}

static void PwmTest_UpdatePattern(void)
{
  uint8 index;

  if (PwmTest_UpdateRequest != 0U)
  {
    return;
  }

  if (PwmTest_Mode == PWM_TEST_MODE_LOW_SIDE_ONLY)
  {
    PwmTest_Duty[0] = PWM_TEST_DUTY_0_PERCENT;
    PwmTest_Duty[1] = PWM_TEST_DUTY_0_PERCENT;
    PwmTest_Duty[2] = PWM_TEST_DUTY_0_PERCENT;
    PwmTest_Duty[3] = PWM_TEST_DUTY_10_PERCENT;
    PwmTest_Duty[4] = PWM_TEST_DUTY_20_PERCENT;
    PwmTest_Duty[5] = PWM_TEST_DUTY_30_PERCENT;
  }
  else if (PwmTest_Mode == PWM_TEST_MODE_RAMP_ALL)
  {
    if (PwmTest_RampUp != 0U)
    {
      PwmTest_RampDuty = (uint16)(PwmTest_RampDuty + PWM_TEST_RAMP_STEP);
      if (PwmTest_RampDuty >= PWM_TEST_RAMP_MAX)
      {
        PwmTest_RampDuty = PWM_TEST_RAMP_MAX;
        PwmTest_RampUp = 0U;
      }
    }
    else
    {
      if (PwmTest_RampDuty > PWM_TEST_RAMP_STEP)
      {
        PwmTest_RampDuty = (uint16)(PwmTest_RampDuty - PWM_TEST_RAMP_STEP);
      }
      else
      {
        PwmTest_RampDuty = PWM_TEST_DUTY_0_PERCENT;
        PwmTest_RampUp = 1U;
      }
    }

    for (index = 0U; index < PWM_TEST_CHANNEL_COUNT; index++)
    {
      PwmTest_Duty[index] = PwmTest_RampDuty;
    }
  }
  else
  {
    /* Manual mode: UDE writes PwmTest_Duty[] and sets PwmTest_UpdateRequest. */
  }
}

static uint16 PwmTest_LimitDuty(uint16 duty)
{
  if (duty > PWM_TEST_DUTY_100_PERCENT)
  {
    return PWM_TEST_DUTY_100_PERCENT;
  }

  return duty;
}

static void PwmTest_UpdateOutputStates(void)
{
  uint8 index;

  for (index = 0U; index < PWM_TEST_CHANNEL_COUNT; index++)
  {
    PwmTest_OutputState[index] = Pwm_17_GtmCcu6_GetOutputState(PwmTest_Channel[index]);
  }
}
