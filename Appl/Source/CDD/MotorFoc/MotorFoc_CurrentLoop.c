#include "MotorFoc_CurrentLoop.h"
#include "MotorFoc_Pid.h"
#include "MotorFoc_SinCosTable.h"
#include "IfxGtm_reg.h"
#include <math.h> /* sqrtf for SVPWM magnitude limit */

#define MOTORFOC_SQRT3_3           (0.5773502691896257645F)
#define MOTORFOC_SQRT3             (1.73205078F)
#define MOTORFOC_VDC_MIN_RUN_DEFAULT    (6.0F)
#define MOTORFOC_CURRENT_MAX_A_DEFAULT  (20.0F)
#define MOTORFOC_CURRENT_STARTUP_BLANKING_COUNT_DEFAULT    (100U)
#define MOTORFOC_CURRENT_UNDERVOLT_CONFIRM_COUNT_DEFAULT   (20U)
#define MOTORFOC_CURRENT_OVERCURRENT_CONFIRM_COUNT_DEFAULT (10U)
#define MOTORFOC_ZERO_CURRENT_REFERENCE_A                  (0.001F)
/* ATOM0 CH1/2/3 center-aligned period (matches Pwm PBCfg 0x2710). */
#define MOTORFOC_PWM_ATOM_PERIOD           (10000U)
#define MOTORFOC_PWM_ATOM_MAX_TIMER        (0xFFFFFFU)
/* AGC GLB_CTRL UPEN_CTRL1/2/3: write 01=disable, 10=enable (no-change=00). */
#define MOTORFOC_PWM_ATOM_UPEN_DIS_CH123   (0x00140000U)
#define MOTORFOC_PWM_ATOM_UPEN_EN_CH123    (0x00280000U)

volatile float32 MotorFoc_CurrentLoopMaxCurrentA = MOTORFOC_CURRENT_MAX_A_DEFAULT;
volatile float32 MotorFoc_CurrentLoopMinVdcRunV = MOTORFOC_VDC_MIN_RUN_DEFAULT;
volatile uint16 MotorFoc_CurrentLoopStartupBlankingCount =
    MOTORFOC_CURRENT_STARTUP_BLANKING_COUNT_DEFAULT;
volatile uint16 MotorFoc_CurrentLoopStartupBlankingLeft = 0U;
volatile uint16 MotorFoc_CurrentLoopUndervoltConfirmCount =
    MOTORFOC_CURRENT_UNDERVOLT_CONFIRM_COUNT_DEFAULT;
volatile uint16 MotorFoc_CurrentLoopUndervoltCounter = 0U;
volatile uint16 MotorFoc_CurrentLoopOverCurrentConfirmCount =
    MOTORFOC_CURRENT_OVERCURRENT_CONFIRM_COUNT_DEFAULT;
volatile uint16 MotorFoc_CurrentLoopOverCurrentCounter = 0U;
volatile uint8 MotorFoc_CurrentLoopFault = 0U;
volatile uint8 MotorFoc_CurrentLoopFaultReason = MOTORFOC_CURRENT_FAULT_NONE;
volatile uint8 MotorFoc_CurrentLoopFaultClearRequest = 0U;
volatile float32 MotorFoc_CurrentLoopFaultIuA = 0.0F;
volatile float32 MotorFoc_CurrentLoopFaultIvA = 0.0F;
volatile float32 MotorFoc_CurrentLoopFaultIwA = 0.0F;
volatile float32 MotorFoc_CurrentLoopFaultVdcV = 0.0F;
static float32 MotorFoc_CurrentLoopRawIuA = 0.0F;
static float32 MotorFoc_CurrentLoopRawIvA = 0.0F;
static float32 MotorFoc_CurrentLoopRawIwA = 0.0F;

static void MotorFoc_CalcCenterAlignedSr(uint32 scaledDuty,
                                         uint32* sr0,
                                         uint32* sr1)
{
  uint32 shift;

  if (scaledDuty == 0U)
  {
    *sr0 = MOTORFOC_PWM_ATOM_MAX_TIMER;
    *sr1 = 0U;
  }
  else if (scaledDuty >= MOTORFOC_PWM_ATOM_PERIOD)
  {
    *sr0 = 0U;
    *sr1 = MOTORFOC_PWM_ATOM_MAX_TIMER;
  }
  else
  {
    shift = (MOTORFOC_PWM_ATOM_PERIOD - scaledDuty) >> 1U;
    *sr0 = shift;
    *sr1 = shift + scaledDuty;
  }
}

/* Direct ATOM0 CH1/2/3 shadow update (center-aligned, coherent). */
static void MotorFoc_ApplyAtomDuties(uint32 scaledDutyU,
                                     uint32 scaledDutyV,
                                     uint32 scaledDutyW)
{
  uint32 sr0u;
  uint32 sr1u;
  uint32 sr0v;
  uint32 sr1v;
  uint32 sr0w;
  uint32 sr1w;

  MotorFoc_CalcCenterAlignedSr(scaledDutyU, &sr0u, &sr1u);
  MotorFoc_CalcCenterAlignedSr(scaledDutyV, &sr0v, &sr1v);
  MotorFoc_CalcCenterAlignedSr(scaledDutyW, &sr0w, &sr1w);

  GTM_ATOM0_AGC_GLB_CTRL.U = MOTORFOC_PWM_ATOM_UPEN_DIS_CH123;
  GTM_ATOM0_CH1_SR0.U = sr0u;
  GTM_ATOM0_CH1_SR1.U = sr1u;
  GTM_ATOM0_CH2_SR0.U = sr0v;
  GTM_ATOM0_CH2_SR1.U = sr1v;
  GTM_ATOM0_CH3_SR0.U = sr0w;
  GTM_ATOM0_CH3_SR1.U = sr1w;
  GTM_ATOM0_AGC_GLB_CTRL.U = MOTORFOC_PWM_ATOM_UPEN_EN_CH123;
}

static void MotorFoc_UpdateSinCos(MotorFoc_ContextType* ctx)
{
  uint32 idx;

  /* Prefer discrete 8192-count angle (TLE5012 / open-loop raw); else map rad. */
  if ((ctx->angle.angleRaw >= 0.0F) &&
      (ctx->angle.angleRaw < (float32)MOTORFOC_SINCOS_TABLE_SIZE))
  {
    idx = (uint32)ctx->angle.angleRaw;
  }
  else
  {
    sint32 sidx = (sint32)(ctx->angle.electricalAngleRad * MOTORFOC_SINCOS_RAD_TO_IDX);
    idx = (uint32)sidx;
  }

  idx &= MOTORFOC_SINCOS_IDX_MASK;
  ctx->angle.sin = MotorFoc_SinCosTable[idx];
  ctx->angle.cos = MotorFoc_SinCosTable[idx + MOTORFOC_SINCOS_COS_OFFSET];
}

static void MotorFoc_DoClarke(MotorFoc_ContextType* ctx)
{
  ctx->iab.real = ctx->i_motor.u;
  ctx->iab.imag = (ctx->i_motor.v - ctx->i_motor.w) * MOTORFOC_SQRT3_3;
}

static void MotorFoc_DoPark(MotorFoc_ContextType* ctx)
{
  ctx->idqMeas.real = (ctx->iab.real * ctx->angle.cos) + (ctx->iab.imag * ctx->angle.sin);
  ctx->idqMeas.imag = (ctx->iab.imag * ctx->angle.cos) - (ctx->iab.real * ctx->angle.sin);
}

static void MotorFoc_DoInversePark(MotorFoc_ContextType* ctx)
{
  ctx->vabRef.real = (ctx->vdqRef.real * ctx->angle.cos) - (ctx->vdqRef.imag * ctx->angle.sin);
  ctx->vabRef.imag = (ctx->vdqRef.real * ctx->angle.sin) + (ctx->vdqRef.imag * ctx->angle.cos);
}

static float32 MotorFoc_GetVoltageVectorLimit(MotorFoc_ContextType* ctx)
{
  float32 vdc = ctx->i_motor.vdc;

  if (vdc < 0.0F)
  {
    vdc = 0.0F;
  }
  return MOTORFOC_SQRT3_3 * vdc * ctx->Tpwm.pwmMinTimes;
}

static void MotorFoc_UpdatePidVoltageLimit(MotorFoc_ContextType* ctx)
{
  float32 limit = MotorFoc_GetVoltageVectorLimit(ctx);

  ctx->piId.Min_output = -limit;
  ctx->piId.Max_output = limit;
  ctx->piIq.Min_output = -limit;
  ctx->piIq.Max_output = limit;
}

static void MotorFoc_LimitDqVoltageVector(MotorFoc_ContextType* ctx)
{
  float32 limit = MotorFoc_GetVoltageVectorLimit(ctx);
  float32 magnitude = sqrtf((ctx->vdqRef.real * ctx->vdqRef.real) +
                            (ctx->vdqRef.imag * ctx->vdqRef.imag));

  if ((magnitude > limit) && (magnitude > 0.0F))
  {
    float32 scale = limit / magnitude;

    ctx->vdqRef.real *= scale;
    ctx->vdqRef.imag *= scale;
  }
}

static void MotorFoc_DoCurrentPid(MotorFoc_ContextType* ctx)
{
  MotorFoc_UpdatePidVoltageLimit(ctx);
  MotorFoc_CurrentPidIdealCalc(ctx->idqRef.real,
                               ctx->idqMeas.real,
                               &ctx->vdqRef.real,
                               &ctx->piId);
  MotorFoc_CurrentPidIdealCalc(ctx->idqRef.imag,
                               ctx->idqMeas.imag,
                               &ctx->vdqRef.imag,
                               &ctx->piIq);
  MotorFoc_LimitDqVoltageVector(ctx);
}

static void MotorFoc_ResetCurrentPidState(MotorFoc_ContextType* ctx)
{
  ctx->piId.Out = 0.0F;
  ctx->piId.v1 = 0.0F;
  ctx->piId.ui = 0.0F;
  ctx->piId.i1 = 0.0F;
  ctx->piId.w1 = 0.0F;
  ctx->piIq.Out = 0.0F;
  ctx->piIq.v1 = 0.0F;
  ctx->piIq.ui = 0.0F;
  ctx->piIq.i1 = 0.0F;
  ctx->piIq.w1 = 0.0F;
}

static void MotorFoc_ApplyPwmOff(void)
{
  MotorFoc_ApplyAtomDuties(0U, 0U, 0U);
}

static float32 MotorFoc_AbsFloat(float32 value)
{
  if (value < 0.0F)
  {
    return -value;
  }
  return value;
}

static void MotorFoc_ClearCurrentLoopSignals(MotorFoc_ContextType* ctx)
{
  ctx->iab.real = 0.0F;
  ctx->iab.imag = 0.0F;
  ctx->idqRef.real = 0.0F;
  ctx->idqRef.imag = 0.0F;
  ctx->idqMeas.real = 0.0F;
  ctx->idqMeas.imag = 0.0F;
  ctx->vdqRef.real = 0.0F;
  ctx->vdqRef.imag = 0.0F;
  ctx->vabRef.real = 0.0F;
  ctx->vabRef.imag = 0.0F;
  ctx->Tpwm.pwm_OutU = 0U;
  ctx->Tpwm.pwm_OutV = 0U;
  ctx->Tpwm.pwm_OutW = 0U;
}

static uint8 MotorFoc_IsPhaseCurrentOverLimit(MotorFoc_ContextType* ctx)
{
  float32 currentLimit = MotorFoc_CurrentLoopMaxCurrentA;

  if (currentLimit < 0.0F)
  {
    currentLimit = -currentLimit;
  }
  if (currentLimit <= 0.0F)
  {
    return 0U;
  }

  if (MotorFoc_AbsFloat(MotorFoc_CurrentLoopRawIuA) > currentLimit)
  {
    return 1U;
  }
  if (MotorFoc_AbsFloat(MotorFoc_CurrentLoopRawIvA) > currentLimit)
  {
    return 1U;
  }
  if (MotorFoc_AbsFloat(MotorFoc_CurrentLoopRawIwA) > currentLimit)
  {
    return 1U;
  }

  return 0U;
}

static void MotorFoc_SetFault(MotorFoc_ContextType* ctx, uint8 faultReason)
{
  MotorFoc_CurrentLoopFault = 1U;
  MotorFoc_CurrentLoopFaultReason = faultReason;
  MotorFoc_CurrentLoopState = MOTORFOC_CURRENTLOOP_STATE_FAULT;
  MotorFoc_CurrentLoopFaultIuA = MotorFoc_CurrentLoopRawIuA;
  MotorFoc_CurrentLoopFaultIvA = MotorFoc_CurrentLoopRawIvA;
  MotorFoc_CurrentLoopFaultIwA = MotorFoc_CurrentLoopRawIwA;
  MotorFoc_CurrentLoopFaultVdcV = ctx->i_motor.vdc;
  MotorFoc_CurrentLoopFaultIdA = ctx->idqMeas.real;
  MotorFoc_CurrentLoopFaultIqA = ctx->idqMeas.imag;
  MotorFoc_CurrentLoopFaultVdV = ctx->vdqRef.real;
  MotorFoc_CurrentLoopFaultVqV = ctx->vdqRef.imag;
  MotorFoc_CurrentLoopFaultPwmU = ctx->Tpwm.pwm_OutU;
  MotorFoc_CurrentLoopFaultPwmV = ctx->Tpwm.pwm_OutV;
  MotorFoc_CurrentLoopFaultPwmW = ctx->Tpwm.pwm_OutW;
}

static uint8 MotorFoc_ConsumeStartupBlanking(void)
{
  if (MotorFoc_CurrentLoopStartupBlankingLeft > 0U)
  {
    MotorFoc_CurrentLoopStartupBlankingLeft--;
    MotorFoc_CurrentLoopUndervoltCounter = 0U;
    MotorFoc_CurrentLoopOverCurrentCounter = 0U;
    MotorFoc_CurrentLoopState = MOTORFOC_CURRENTLOOP_STATE_BLANKING;
    return 1U;
  }

  MotorFoc_CurrentLoopState = MOTORFOC_CURRENTLOOP_STATE_RUN;
  return 0U;
}

static uint8 MotorFoc_IsVdcUsable(MotorFoc_ContextType* ctx)
{
  return (ctx->i_motor.vdc > 0.1F) ? 1U : 0U;
}

static uint8 MotorFoc_CheckOverCurrentFault(MotorFoc_ContextType* ctx)
{
  uint16 confirmCount = MotorFoc_CurrentLoopOverCurrentConfirmCount;


  if (MotorFoc_IsPhaseCurrentOverLimit(ctx) == 0U)
  {
    MotorFoc_CurrentLoopOverCurrentCounter = 0U;
    return 0U;
  }

  if (confirmCount == 0U)
  {
    confirmCount = 1U;
  }

  if (MotorFoc_CurrentLoopOverCurrentCounter < confirmCount)
  {
    MotorFoc_CurrentLoopOverCurrentCounter++;
  }

  if (MotorFoc_CurrentLoopOverCurrentCounter >= confirmCount)
  {
    return 1U;
  }

  return 0U;
}

static uint8 MotorFoc_CheckUndervoltFault(MotorFoc_ContextType* ctx)
{
  uint16 confirmCount = MotorFoc_CurrentLoopUndervoltConfirmCount;
  float32 minVdc = MotorFoc_CurrentLoopMinVdcRunV;


  if (minVdc < 0.0F)
  {
    minVdc = 0.0F;
  }

  if (ctx->i_motor.vdc >= minVdc)
  {
    MotorFoc_CurrentLoopUndervoltCounter = 0U;
    return 0U;
  }

  if (confirmCount == 0U)
  {
    confirmCount = 1U;
  }

  if (MotorFoc_CurrentLoopUndervoltCounter < confirmCount)
  {
    MotorFoc_CurrentLoopUndervoltCounter++;
  }

  if (MotorFoc_CurrentLoopUndervoltCounter >= confirmCount)
  {
    return 1U;
  }

  return 0U;
}

static void MotorFoc_DoSvpwm(MotorFoc_ContextType* ctx)
{
  uint8 sectorCode = 0U;
  float32 sA;
  float32 sB;
  float32 sC;
  float32 tx;
  float32 ty;
  float32 tSum;
  float32 tA;
  float32 tB;
  float32 tC;
  float32 tCmpU;
  float32 tCmpV;
  float32 tCmpW;
  float32 voltageLimit;
  float32 voltageMagnitude;
  float32 scale;

  voltageLimit = MOTORFOC_SQRT3_3 * ctx->i_motor.vdc * ctx->Tpwm.pwmMinTimes;
  voltageMagnitude = sqrtf((ctx->vabRef.real * ctx->vabRef.real) +
                           (ctx->vabRef.imag * ctx->vabRef.imag));
  if ((voltageMagnitude > voltageLimit) && (voltageMagnitude > 0.0F))
  {
    scale = voltageLimit / voltageMagnitude;
    ctx->vabRef.real *= scale;
    ctx->vabRef.imag *= scale;
  }

  /* TC364 six-sector SVPWM. pwm_OutX remains a compare tick in [0, Tpwm / 2]. */
  sA = ctx->vabRef.imag;
  sB = (MOTORFOC_SQRT3 * ctx->vabRef.real - ctx->vabRef.imag) * 0.5F;
  sC = (-MOTORFOC_SQRT3 * ctx->vabRef.real - ctx->vabRef.imag) * 0.5F;

  if (sA > 0.0F)
  {
    sectorCode = 1U;
  }
  if (sB > 0.0F)
  {
    sectorCode += 2U;
  }
  if (sC > 0.0F)
  {
    sectorCode += 4U;
  }

  scale = MOTORFOC_SQRT3 * ctx->Tpwm.Tpwm / ctx->i_motor.vdc;
  switch (sectorCode)
  {
    case 1U:
      tx = -sB * scale;
      ty = -sC * scale;
      break;
    case 2U:
      tx = -sC * scale;
      ty = -sA * scale;
      break;
    case 3U:
      tx = sB * scale;
      ty = sA * scale;
      break;
    case 4U:
      tx = -sA * scale;
      ty = -sB * scale;
      break;
    case 5U:
      tx = sA * scale;
      ty = sC * scale;
      break;
    case 6U:
      tx = sC * scale;
      ty = sB * scale;
      break;
    default:
      tx = 0.0F;
      ty = 0.0F;
      break;
  }

  tSum = tx + ty;
  if ((tSum > ctx->Tpwm.Tpwm) && (tSum > 0.0F))
  {
    tx = tx * ctx->Tpwm.Tpwm / tSum;
    ty = ty * ctx->Tpwm.Tpwm / tSum;
  }

  tA = (ctx->Tpwm.Tpwm - tx - ty) * 0.25F;
  tB = (tx * 0.5F) + tA;
  tC = (ty * 0.5F) + tB;

  switch (sectorCode)
  {
    case 1U:
      tCmpU = tB; tCmpV = tA; tCmpW = tC;
      break;
    case 2U:
      tCmpU = tA; tCmpV = tC; tCmpW = tB;
      break;
    case 3U:
      tCmpU = tA; tCmpV = tB; tCmpW = tC;
      break;
    case 4U:
      tCmpU = tC; tCmpV = tB; tCmpW = tA;
      break;
    case 5U:
      tCmpU = tC; tCmpV = tA; tCmpW = tB;
      break;
    case 6U:
      tCmpU = tB; tCmpV = tC; tCmpW = tA;
      break;
    default:
      /* Zero vector: keep the same neutral duty used before output enable. */
      tCmpU = ctx->Tpwm.Tpwm * 0.25F;
      tCmpV = ctx->Tpwm.Tpwm * 0.25F;
      tCmpW = ctx->Tpwm.Tpwm * 0.25F;
      break;
  }

  ctx->Tpwm.pwm_OutU = (uint32)tCmpU;
  ctx->Tpwm.pwm_OutV = (uint32)tCmpV;
  ctx->Tpwm.pwm_OutW = (uint32)tCmpW;
}

static void MotorFoc_ApplyPwm(MotorFoc_ContextType* ctx)
{
  uint32 dutyMin;
  uint32 dutyMax;

  dutyMin = ctx->Tpwm.pwmMinTimesMin;
  dutyMax = ctx->Tpwm.pwmMinTimesMax;

  if (ctx->Tpwm.pwm_OutU > dutyMax)
  {
    ctx->Tpwm.pwm_OutU = dutyMax;
  }
  else if (ctx->Tpwm.pwm_OutU < dutyMin)
  {
    ctx->Tpwm.pwm_OutU = dutyMin;
  }

  if (ctx->Tpwm.pwm_OutV > dutyMax)
  {
    ctx->Tpwm.pwm_OutV = dutyMax;
  }
  else if (ctx->Tpwm.pwm_OutV < dutyMin)
  {
    ctx->Tpwm.pwm_OutV = dutyMin;
  }

  if (ctx->Tpwm.pwm_OutW > dutyMax)
  {
    ctx->Tpwm.pwm_OutW = dutyMax;
  }
  else if (ctx->Tpwm.pwm_OutW < dutyMin)
  {
    ctx->Tpwm.pwm_OutW = dutyMin;
  }

  /* pwm_Out is half-period tick; ScaledDuty = 2 * pwm_Out when Period == Tpwm. */
  MotorFoc_ApplyAtomDuties(ctx->Tpwm.pwm_OutU << 1U,
                           ctx->Tpwm.pwm_OutV << 1U,
                           ctx->Tpwm.pwm_OutW << 1U);
}

static void MotorFoc_ApplyNeutralPwm(MotorFoc_ContextType* ctx)
{
  ctx->Tpwm.pwm_OutU = (uint32)(ctx->Tpwm.Tpwm * 0.25F);
  ctx->Tpwm.pwm_OutV = (uint32)(ctx->Tpwm.Tpwm * 0.25F);
  ctx->Tpwm.pwm_OutW = (uint32)(ctx->Tpwm.Tpwm * 0.25F);
  MotorFoc_ApplyPwm(ctx);
}

void MotorFoc_CurrentLoopInit(MotorFoc_ContextType* ctx)
{
  MotorFoc_ConfigInitContext(ctx);

  MotorFoc_CurrentPidInit(&ctx->piId,
                          ctx->motor.w_i_dq,
                          ctx->motor.rs,
                          ctx->motor.lm);
  MotorFoc_CurrentPidInit(&ctx->piIq,
                          ctx->motor.w_i_dq,
                          ctx->motor.rs,
                          ctx->motor.lm);
}

void MotorFoc_SetIdRef(MotorFoc_ContextType* ctx, float32 idRef)
{
  ctx->idqRef.real = idRef;
}

void MotorFoc_SetIqRef(MotorFoc_ContextType* ctx, float32 iqRef)
{
  ctx->idqRef.imag = iqRef;
}

void MotorFoc_SetAngleFromTle5012(MotorFoc_ContextType* ctx,
                                  float32 angleRaw,
                                  float32 electricalAngleRad)
{
  ctx->angle.angleRaw = angleRaw;
  ctx->angle.electricalAngleRad = electricalAngleRad;
}

void MotorFoc_UpdateCurrentFromAdc(MotorFoc_ContextType* ctx,
                                   float32 iu,
                                   float32 iv,
                                   float32 iw,
                                   float32 vdc)
{
  ctx->i_motor.u = iu;
  ctx->i_motor.v = iv;
  ctx->i_motor.w = iw;
  ctx->i_motor.vdc = vdc;
  if (ctx->i_motor.vdc > ctx->i_motor.vdcMax)
  {
    ctx->i_motor.vdc = ctx->i_motor.vdcMax;
  }
}

void MotorFoc_UpdateRawCurrentForProtection(float32 iu,
                                             float32 iv,
                                             float32 iw)
{
  MotorFoc_CurrentLoopRawIuA = iu;
  MotorFoc_CurrentLoopRawIvA = iv;
  MotorFoc_CurrentLoopRawIwA = iw;
}

void MotorFoc_RunCurrentLoop(MotorFoc_ContextType* ctx)
{
  if (MotorFoc_CurrentLoopFaultClearRequest != 0U)
  {
    MotorFoc_CurrentLoopFaultClearRequest = 0U;
    MotorFoc_CurrentLoopClearFault();
  }

  if (MotorFoc_CurrentLoopFault != 0U)
  {
    MotorFoc_CurrentLoopStop(ctx);
    return;
  }

  if (MotorFoc_CheckUndervoltFault(ctx) != 0U)
  {
    MotorFoc_SetFault(ctx, MOTORFOC_CURRENT_FAULT_UNDERVOLT);
    MotorFoc_CurrentLoopStop(ctx);
    return;
  }

  if (MotorFoc_CheckOverCurrentFault(ctx) != 0U)
  {
    MotorFoc_SetFault(ctx, MOTORFOC_CURRENT_FAULT_OVERCURRENT);
    MotorFoc_CurrentLoopStop(ctx);
    return;
  }

  /* A zero-current open-loop test must not integrate ADC residual error. */
  if ((MotorFoc_AbsFloat(ctx->idqRef.real) < MOTORFOC_ZERO_CURRENT_REFERENCE_A) &&
      (MotorFoc_AbsFloat(ctx->idqRef.imag) < MOTORFOC_ZERO_CURRENT_REFERENCE_A))
  {
    MotorFoc_ResetCurrentPidState(ctx);
    ctx->vdqRef.real = 0.0F;
    ctx->vdqRef.imag = 0.0F;
    ctx->vabRef.real = 0.0F;
    ctx->vabRef.imag = 0.0F;
    MotorFoc_ApplyNeutralPwm(ctx);
    return;
  }

  MotorFoc_DoClarke(ctx);
  MotorFoc_UpdateSinCos(ctx);
  MotorFoc_DoPark(ctx);
  MotorFoc_DoCurrentPid(ctx);
  MotorFoc_DoInversePark(ctx);
  MotorFoc_DoSvpwm(ctx);
  MotorFoc_ApplyPwm(ctx);
}



void MotorFoc_CurrentLoopStop(MotorFoc_ContextType* ctx)
{
  MotorFoc_ResetCurrentPidState(ctx);
  MotorFoc_ClearCurrentLoopSignals(ctx);
  MotorFoc_ApplyPwmOff();
}

void MotorFoc_CurrentLoopPreparePwmNeutral(MotorFoc_ContextType* ctx)
{
  MotorFoc_ResetCurrentPidState(ctx);
  MotorFoc_ClearCurrentLoopSignals(ctx);
  MotorFoc_ApplyNeutralPwm(ctx);
}

void MotorFoc_CurrentLoopClearFault(void)
{
  MotorFoc_CurrentLoopFault = 0U;
  MotorFoc_CurrentLoopFaultReason = MOTORFOC_CURRENT_FAULT_NONE;
  MotorFoc_CurrentLoopUndervoltCounter = 0U;
  MotorFoc_CurrentLoopOverCurrentCounter = 0U;
  MotorFoc_CurrentLoopFaultIuA = 0.0F;
  MotorFoc_CurrentLoopFaultIvA = 0.0F;
  MotorFoc_CurrentLoopFaultIwA = 0.0F;
  MotorFoc_CurrentLoopFaultVdcV = 0.0F;
}

void MotorFoc_CurrentLoopArmStartupBlanking(void)
{
  MotorFoc_CurrentLoopStartupBlankingLeft = MotorFoc_CurrentLoopStartupBlankingCount;
  MotorFoc_CurrentLoopUndervoltCounter = 0U;
  MotorFoc_CurrentLoopOverCurrentCounter = 0U;
}
