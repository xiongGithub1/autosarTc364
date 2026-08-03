/**********************************************************************************************************************
 *  MotorFoc_OpenLoop.c — 开环（强制角度）启动/调速状态机
 *  -------------------------------------------------------------------------------------------------------------------
 *  适用：无位置传感器调试、台架验证、带载前整定电流环。
 *  原理：电流环始终正常工作，仅电角度由软件强制生成（不用 TLE5012），
 *        因此转子先被固定到已知电角度（ALIGN），再按受控角速度旋转。
 *  阶段：ALIGN_RAMP(Id 斜坡) → ALIGN_HOLD(保持对齐) → RAMP(角度加速+参考过渡) → RUN(匀速推进)
 *  时间单位：本文件计数均为快速环拍数（10 kHz，一拍 = 100 µs）。
 *  参数全部为 volatile，可由 UDE 在线调整（见 MotorFoc_OpenLoop.h）。
 **********************************************************************************************************************/#include "MotorFoc_OpenLoop.h"

#define MOTORFOC_OL_TWO_PI                     (6.2831853071795864769F)
#define MOTORFOC_OL_DEG_TO_RAD                 (0.01745329251994329577F)
#define MOTORFOC_OL_TARGET_ANGLE_STEP_DEFAULT  (1U)
#define MOTORFOC_OL_STEP_DIVIDER_DEFAULT        (1U)
/* 300 ms at the current 10 kHz PWM fast-loop rate. */
#define MOTORFOC_OL_ALIGN_HOLD_TICKS_DEFAULT    (3000U)
/* Add one raw-angle step every 10 ms while accelerating. */
#define MOTORFOC_OL_ACCEL_TICKS_DEFAULT         (100U)
#define MOTORFOC_OL_ALIGN_CURRENT_A_DEFAULT     (1.0F)
#define MOTORFOC_OL_CURRENT_RAMP_STEP_A_DEFAULT (0.002F)

volatile uint8 MotorFoc_OpenLoop_Direction = 0U;
volatile uint16 MotorFoc_OpenLoop_TargetAngleStep = MOTORFOC_OL_TARGET_ANGLE_STEP_DEFAULT;
volatile uint16 MotorFoc_OpenLoop_StepDivider = MOTORFOC_OL_STEP_DIVIDER_DEFAULT;
volatile uint16 MotorFoc_OpenLoop_AlignHoldTicks = MOTORFOC_OL_ALIGN_HOLD_TICKS_DEFAULT;
volatile uint16 MotorFoc_OpenLoop_AccelerationTicks = MOTORFOC_OL_ACCEL_TICKS_DEFAULT;
volatile float32 MotorFoc_OpenLoop_AlignAngleDeg = 0.0F;
volatile float32 MotorFoc_OpenLoop_AlignCurrentA = MOTORFOC_OL_ALIGN_CURRENT_A_DEFAULT;
volatile float32 MotorFoc_OpenLoop_CurrentRampStepA = MOTORFOC_OL_CURRENT_RAMP_STEP_A_DEFAULT;

volatile MotorFoc_OpenLoopStageType MotorFoc_OpenLoop_Stage = MOTORFOC_OPENLOOP_STAGE_ALIGN_RAMP;
volatile uint32 MotorFoc_OpenLoop_StageCounter = 0UL;
volatile uint16 MotorFoc_OpenLoop_AngleRaw = 0U;
volatile uint16 MotorFoc_OpenLoop_ActiveAngleStep = 0U;
volatile float32 MotorFoc_OpenLoop_ForcedAngleRad = 0.0F;
volatile float32 MotorFoc_OpenLoop_IdRefOut = 0.0F;
volatile float32 MotorFoc_OpenLoop_IqRefOut = 0.0F;

static uint16 MotorFoc_OpenLoop_StepDividerCounter = 0U;
static uint16 MotorFoc_OpenLoop_AccelerationCounter = 0U;

static float32 MotorFoc_OpenLoop_Abs(float32 value)
{
  return (value < 0.0F) ? -value : value;
}

/* Slew references in the fast loop so reference changes are deterministic. */
static float32 MotorFoc_OpenLoop_Slew(float32 current, float32 target, float32 step)
{
  step = MotorFoc_OpenLoop_Abs(step);
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

static void MotorFoc_OpenLoop_UpdateAngleRad(void)
{
  MotorFoc_OpenLoop_ForcedAngleRad =
      (float32)MotorFoc_OpenLoop_AngleRaw * MOTORFOC_OL_ANGLE_RAW_TO_RAD;
}

static void MotorFoc_OpenLoop_SetAlignAngle(void)
{
  float32 angleDeg = MotorFoc_OpenLoop_AlignAngleDeg;
  uint32 angleRaw;

  /* Normalize a UDE-entered angle before converting it to the table index. */
  while (angleDeg < 0.0F)
  {
    angleDeg += 360.0F;
  }
  while (angleDeg >= 360.0F)
  {
    angleDeg -= 360.0F;
  }

  angleRaw = (uint32)((angleDeg * MOTORFOC_OL_DEG_TO_RAD /
                       MOTORFOC_OL_TWO_PI) * 8192.0F);
  MotorFoc_OpenLoop_AngleRaw = (uint16)(angleRaw & MOTORFOC_OL_ANGLE_RAW_MAX);
  MotorFoc_OpenLoop_UpdateAngleRad();
}

static void MotorFoc_OpenLoop_AdvanceAngle(void)
{
  uint16 divider = MotorFoc_OpenLoop_StepDivider;
  uint16 step = MotorFoc_OpenLoop_ActiveAngleStep;

  if (divider == 0U)
  {
    divider = 1U;
  }
  MotorFoc_OpenLoop_StepDividerCounter++;
  if ((MotorFoc_OpenLoop_StepDividerCounter < divider) || (step == 0U))
  {
    return;
  }

  MotorFoc_OpenLoop_StepDividerCounter = 0U;
  if (MotorFoc_OpenLoop_Direction == 0U)
  {
    MotorFoc_OpenLoop_AngleRaw =
        (uint16)(((uint32)MotorFoc_OpenLoop_AngleRaw + step) & MOTORFOC_OL_ANGLE_RAW_MAX);
  }
  else
  {
    MotorFoc_OpenLoop_AngleRaw =
        (uint16)(((uint32)MotorFoc_OpenLoop_AngleRaw - step) & MOTORFOC_OL_ANGLE_RAW_MAX);
  }
  MotorFoc_OpenLoop_UpdateAngleRad();
}

static void MotorFoc_OpenLoop_Accelerate(void)
{
  uint16 target = MotorFoc_OpenLoop_TargetAngleStep;
  uint16 period = MotorFoc_OpenLoop_AccelerationTicks;

  if (target == 0U)
  {
    target = 1U;
  }
  if (period == 0U)
  {
    period = 1U;
  }

  if (MotorFoc_OpenLoop_ActiveAngleStep < target)
  {
    MotorFoc_OpenLoop_AccelerationCounter++;
    if (MotorFoc_OpenLoop_AccelerationCounter >= period)
    {
      MotorFoc_OpenLoop_AccelerationCounter = 0U;
      MotorFoc_OpenLoop_ActiveAngleStep++;
    }
  }
}

void MotorFoc_OpenLoop_Init(void)
{
  MotorFoc_OpenLoop_Direction = 0U;
  MotorFoc_OpenLoop_TargetAngleStep = MOTORFOC_OL_TARGET_ANGLE_STEP_DEFAULT;
  MotorFoc_OpenLoop_StepDivider = MOTORFOC_OL_STEP_DIVIDER_DEFAULT;
  MotorFoc_OpenLoop_AlignHoldTicks = MOTORFOC_OL_ALIGN_HOLD_TICKS_DEFAULT;
  MotorFoc_OpenLoop_AccelerationTicks = MOTORFOC_OL_ACCEL_TICKS_DEFAULT;
  MotorFoc_OpenLoop_AlignAngleDeg = 0.0F;
  MotorFoc_OpenLoop_AlignCurrentA = MOTORFOC_OL_ALIGN_CURRENT_A_DEFAULT;
  MotorFoc_OpenLoop_CurrentRampStepA = MOTORFOC_OL_CURRENT_RAMP_STEP_A_DEFAULT;
  MotorFoc_OpenLoop_Reset();
}

void MotorFoc_OpenLoop_Reset(void)
{
  MotorFoc_OpenLoop_Stage = MOTORFOC_OPENLOOP_STAGE_ALIGN_RAMP;
  MotorFoc_OpenLoop_StageCounter = 0UL;
  MotorFoc_OpenLoop_ActiveAngleStep = 0U;
  MotorFoc_OpenLoop_IdRefOut = 0.0F;
  MotorFoc_OpenLoop_IqRefOut = 0.0F;
  MotorFoc_OpenLoop_StepDividerCounter = 0U;
  MotorFoc_OpenLoop_AccelerationCounter = 0U;
  MotorFoc_OpenLoop_SetAlignAngle();
}

void MotorFoc_OpenLoop_FastLoopStep(float32 idRequestA, float32 iqRequestA)
{
  float32 alignCurrent = MotorFoc_OpenLoop_Abs(MotorFoc_OpenLoop_AlignCurrentA);

  switch (MotorFoc_OpenLoop_Stage)
  {
    case MOTORFOC_OPENLOOP_STAGE_ALIGN_RAMP:
      /* Fixed electrical angle and Id establish a known rotor position. */
      MotorFoc_OpenLoop_IdRefOut = MotorFoc_OpenLoop_Slew(
          MotorFoc_OpenLoop_IdRefOut, alignCurrent, MotorFoc_OpenLoop_CurrentRampStepA);
      MotorFoc_OpenLoop_IqRefOut = 0.0F;
      if (MotorFoc_OpenLoop_IdRefOut >= alignCurrent)
      {
        MotorFoc_OpenLoop_Stage = MOTORFOC_OPENLOOP_STAGE_ALIGN_HOLD;
        MotorFoc_OpenLoop_StageCounter = 0UL;
      }
      break;

    case MOTORFOC_OPENLOOP_STAGE_ALIGN_HOLD:
      /* Hold position: no angle advance and no q-axis torque command. */
      MotorFoc_OpenLoop_IdRefOut = alignCurrent;
      MotorFoc_OpenLoop_IqRefOut = 0.0F;
      MotorFoc_OpenLoop_StageCounter++;
      if (MotorFoc_OpenLoop_StageCounter >= (uint32)MotorFoc_OpenLoop_AlignHoldTicks)
      {
        MotorFoc_OpenLoop_Stage = MOTORFOC_OPENLOOP_STAGE_RAMP;
        MotorFoc_OpenLoop_StageCounter = 0UL;
      }
      break;

    case MOTORFOC_OPENLOOP_STAGE_RAMP:
      /* Transfer smoothly to commanded currents while accelerating forced angle. */
      MotorFoc_OpenLoop_IdRefOut = MotorFoc_OpenLoop_Slew(
          MotorFoc_OpenLoop_IdRefOut, idRequestA, MotorFoc_OpenLoop_CurrentRampStepA);
      MotorFoc_OpenLoop_IqRefOut = MotorFoc_OpenLoop_Slew(
          MotorFoc_OpenLoop_IqRefOut, iqRequestA, MotorFoc_OpenLoop_CurrentRampStepA);
      MotorFoc_OpenLoop_Accelerate();
      MotorFoc_OpenLoop_AdvanceAngle();
      if (MotorFoc_OpenLoop_ActiveAngleStep >= MotorFoc_OpenLoop_TargetAngleStep)
      {
        MotorFoc_OpenLoop_Stage = MOTORFOC_OPENLOOP_STAGE_RUN;
      }
      break;

    case MOTORFOC_OPENLOOP_STAGE_RUN:
    default:
      MotorFoc_OpenLoop_IdRefOut = MotorFoc_OpenLoop_Slew(
          MotorFoc_OpenLoop_IdRefOut, idRequestA, MotorFoc_OpenLoop_CurrentRampStepA);
      MotorFoc_OpenLoop_IqRefOut = MotorFoc_OpenLoop_Slew(
          MotorFoc_OpenLoop_IqRefOut, iqRequestA, MotorFoc_OpenLoop_CurrentRampStepA);
      MotorFoc_OpenLoop_AdvanceAngle();
      break;
  }
}

float32 MotorFoc_OpenLoop_GetForcedAngleRad(void)
{
  return MotorFoc_OpenLoop_ForcedAngleRad;
}

float32 MotorFoc_OpenLoop_GetForcedAngleDeg(void)
{
  return ((float32)MotorFoc_OpenLoop_AngleRaw * 360.0F) / 8192.0F;
}

float32 MotorFoc_OpenLoop_GetIdRefA(void)
{
  return MotorFoc_OpenLoop_IdRefOut;
}

float32 MotorFoc_OpenLoop_GetIqRefA(void)
{
  return MotorFoc_OpenLoop_IqRefOut;
}