#include "MotorFoc_OpenLoop.h"

#define MOTORFOC_OL_TWO_PI                     (6.2831853071795864769F)
#define MOTORFOC_OL_DEG_TO_RAD                 (0.01745329251994329577F)
#define MOTORFOC_OL_VOLTAGE_LIMIT_V_DEFAULT    (1.0F)
#define MOTORFOC_OL_VOLTAGE_RAMP_V_DEFAULT     (0.001F)
#define MOTORFOC_OL_VOLTAGE_TO_CURRENT_TICKS_DEFAULT  (20000UL)

volatile uint8 MotorFoc_OpenLoop_RampEnable = 1U;
volatile uint8 MotorFoc_OpenLoop_ControlMode = MOTORFOC_OPENLOOP_CONTROL_CURRENT;
volatile uint8 MotorFoc_OpenLoop_ActiveControlMode = MOTORFOC_OPENLOOP_CONTROL_CURRENT;
volatile uint8 MotorFoc_OpenLoop_Direction = 0U;
volatile uint16 MotorFoc_OpenLoop_AngleStep = MOTORFOC_OL_DEFAULT_ANGLE_STEP;
volatile uint16 MotorFoc_OpenLoop_StepDivider = MOTORFOC_OL_DEFAULT_STEP_DIVIDER;
volatile uint32 MotorFoc_OpenLoop_StageCounter = 0UL;
volatile uint32 MotorFoc_OpenLoop_VoltageToCurrentTicks =
    MOTORFOC_OL_VOLTAGE_TO_CURRENT_TICKS_DEFAULT;
volatile uint16 MotorFoc_OpenLoop_AngleRaw = 0U;
volatile float32 MotorFoc_OpenLoop_ForcedAngleRad = 0.0F;
volatile float32 MotorFoc_OpenLoop_FixedAngleDeg = 0.0F;
volatile float32 MotorFoc_OpenLoop_VdRefCmd = 0.0F;
volatile float32 MotorFoc_OpenLoop_VqRefCmd = 0.0F;
volatile float32 MotorFoc_OpenLoop_VdRefOut = 0.0F;
volatile float32 MotorFoc_OpenLoop_VqRefOut = 0.0F;
volatile float32 MotorFoc_OpenLoop_VoltageLimitV = MOTORFOC_OL_VOLTAGE_LIMIT_V_DEFAULT;
volatile float32 MotorFoc_OpenLoop_VoltageRampV = MOTORFOC_OL_VOLTAGE_RAMP_V_DEFAULT;

static uint16 MotorFoc_OpenLoop_TickDivider = 0U;

static float32 MotorFoc_OpenLoop_ClampFloat(float32 value, float32 min, float32 max)
{
  if (value > max)
  {
    return max;
  }
  if (value < min)
  {
    return min;
  }
  return value;
}

static float32 MotorFoc_OpenLoop_SlewFloat(float32 current, float32 target, float32 step)
{
  if (step <= 0.0F)
  {
    return target;
  }
  if ((target - current) > step)
  {
    return current + step;
  }
  if ((current - target) > step)
  {
    return current - step;
  }
  return target;
}

static void MotorFoc_OpenLoop_UpdateForcedAngleRad(void)
{
  MotorFoc_OpenLoop_ForcedAngleRad =
      (float32)MotorFoc_OpenLoop_AngleRaw * MOTORFOC_OL_ANGLE_RAW_TO_RAD;
}

static void MotorFoc_OpenLoop_ApplyFixedAngle(void)
{
  float32 angleDeg;
  float32 angleRad;
  uint32 angleRaw;

  angleDeg = MotorFoc_OpenLoop_FixedAngleDeg;
  if (angleDeg < 0.0F)
  {
    angleDeg = 0.0F;
  }
  else if (angleDeg >= 360.0F)
  {
    angleDeg = 359.99F;
  }
  else
  {
    /* Valid fixed angle. */
  }

  angleRad = angleDeg * MOTORFOC_OL_DEG_TO_RAD;
  angleRaw = (uint32)((angleRad / MOTORFOC_OL_TWO_PI) * 8192.0F);
  if (angleRaw > MOTORFOC_OL_ANGLE_RAW_MAX)
  {
    angleRaw = MOTORFOC_OL_ANGLE_RAW_MAX;
  }

  MotorFoc_OpenLoop_AngleRaw = (uint16)angleRaw;
  MotorFoc_OpenLoop_UpdateForcedAngleRad();
}

static void MotorFoc_OpenLoop_StepAngleRaw(void)
{
  if (MotorFoc_OpenLoop_Direction == 0U)
  {
    if (MotorFoc_OpenLoop_AngleRaw >= MOTORFOC_OL_ANGLE_RAW_MAX)
    {
      MotorFoc_OpenLoop_AngleRaw = 0U;
    }
    else
    {
      MotorFoc_OpenLoop_AngleRaw =
          (uint16)(MotorFoc_OpenLoop_AngleRaw + MotorFoc_OpenLoop_AngleStep);
      if (MotorFoc_OpenLoop_AngleRaw > MOTORFOC_OL_ANGLE_RAW_MAX)
      {
        MotorFoc_OpenLoop_AngleRaw = 0U;
      }
    }
  }
  else
  {
    if (MotorFoc_OpenLoop_AngleRaw == 0U)
    {
      MotorFoc_OpenLoop_AngleRaw = MOTORFOC_OL_ANGLE_RAW_MAX;
    }
    else if (MotorFoc_OpenLoop_AngleRaw < MotorFoc_OpenLoop_AngleStep)
    {
      MotorFoc_OpenLoop_AngleRaw = MOTORFOC_OL_ANGLE_RAW_MAX;
    }
    else
    {
      MotorFoc_OpenLoop_AngleRaw =
          (uint16)(MotorFoc_OpenLoop_AngleRaw - MotorFoc_OpenLoop_AngleStep);
    }
  }
}

void MotorFoc_OpenLoop_Init(void)
{
  MotorFoc_OpenLoop_RampEnable = 1U;
  MotorFoc_OpenLoop_ControlMode = MOTORFOC_OPENLOOP_CONTROL_CURRENT;
  MotorFoc_OpenLoop_Direction = 0U;
  MotorFoc_OpenLoop_AngleStep = MOTORFOC_OL_DEFAULT_ANGLE_STEP;
  MotorFoc_OpenLoop_StepDivider = MOTORFOC_OL_DEFAULT_STEP_DIVIDER;
  MotorFoc_OpenLoop_VoltageToCurrentTicks = MOTORFOC_OL_VOLTAGE_TO_CURRENT_TICKS_DEFAULT;
  MotorFoc_OpenLoop_FixedAngleDeg = 0.0F;
  MotorFoc_OpenLoop_VdRefCmd = 0.0F;
  MotorFoc_OpenLoop_VqRefCmd = 0.0F;
  MotorFoc_OpenLoop_VoltageLimitV = MOTORFOC_OL_VOLTAGE_LIMIT_V_DEFAULT;
  MotorFoc_OpenLoop_VoltageRampV = MOTORFOC_OL_VOLTAGE_RAMP_V_DEFAULT;
  MotorFoc_OpenLoop_Reset();
}

void MotorFoc_OpenLoop_Reset(void)
{
  MotorFoc_OpenLoop_AngleRaw = 0U;
  MotorFoc_OpenLoop_TickDivider = 0U;
  MotorFoc_OpenLoop_StageCounter = 0UL;
  /* Open loop is intentionally forced-angle plus current-loop control. */
  MotorFoc_OpenLoop_ActiveControlMode = MOTORFOC_OPENLOOP_CONTROL_CURRENT;
  MotorFoc_OpenLoop_VdRefOut = 0.0F;
  MotorFoc_OpenLoop_VqRefOut = 0.0F;
  MotorFoc_OpenLoop_UpdateForcedAngleRad();
}

void MotorFoc_OpenLoop_FastLoopStep(void)
{
  if (MotorFoc_OpenLoop_RampEnable == 0U)
  {
    MotorFoc_OpenLoop_ApplyFixedAngle();
    return;
  }

  if (MotorFoc_OpenLoop_StepDivider == 0U)
  {
    MotorFoc_OpenLoop_StepDivider = 1U;
  }

  if (MotorFoc_OpenLoop_AngleStep == 0U)
  {
    MotorFoc_OpenLoop_AngleStep = 1U;
  }

  MotorFoc_OpenLoop_TickDivider++;
  if (MotorFoc_OpenLoop_TickDivider >= MotorFoc_OpenLoop_StepDivider)
  {
    MotorFoc_OpenLoop_TickDivider = 0U;
    MotorFoc_OpenLoop_StepAngleRaw();
    MotorFoc_OpenLoop_UpdateForcedAngleRad();
  }
}

void MotorFoc_OpenLoop_UpdateControlStage(void)
{
  MotorFoc_OpenLoop_ActiveControlMode = MOTORFOC_OPENLOOP_CONTROL_CURRENT;
  MotorFoc_OpenLoop_StageCounter = 0UL;
}

void MotorFoc_OpenLoop_UpdateVoltageRefs(void)
{
  float32 voltageLimit = MotorFoc_OpenLoop_VoltageLimitV;
  float32 voltageRamp = MotorFoc_OpenLoop_VoltageRampV;
  float32 vdRef;
  float32 vqRef;

  if (voltageLimit < 0.0F)
  {
    voltageLimit = -voltageLimit;
  }
  if (voltageRamp < 0.0F)
  {
    voltageRamp = -voltageRamp;
  }

  vdRef = MotorFoc_OpenLoop_ClampFloat(MotorFoc_OpenLoop_VdRefCmd,
                                       -voltageLimit,
                                       voltageLimit);
  vqRef = MotorFoc_OpenLoop_ClampFloat(MotorFoc_OpenLoop_VqRefCmd,
                                       -voltageLimit,
                                       voltageLimit);
  MotorFoc_OpenLoop_VdRefOut =
      MotorFoc_OpenLoop_SlewFloat(MotorFoc_OpenLoop_VdRefOut, vdRef, voltageRamp);
  MotorFoc_OpenLoop_VqRefOut =
      MotorFoc_OpenLoop_SlewFloat(MotorFoc_OpenLoop_VqRefOut, vqRef, voltageRamp);
}

uint8 MotorFoc_OpenLoop_GetActiveControlMode(void)
{
  return MotorFoc_OpenLoop_ActiveControlMode;
}

float32 MotorFoc_OpenLoop_GetForcedAngleRad(void)
{
  return MotorFoc_OpenLoop_ForcedAngleRad;
}

float32 MotorFoc_OpenLoop_GetForcedAngleDeg(void)
{
  return ((float32)MotorFoc_OpenLoop_AngleRaw * 360.0F) / 8192.0F;
}
