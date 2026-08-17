/**********************************************************************************************************************
 *  MotorFoc_CurrentLoop.c — FOC 电流环核心（10 kHz）
 *  -------------------------------------------------------------------------------------------------------------------
 *  调用链：MotorCdd_FocFastLoop → MotorFoc_RunCurrentLoop（每 100 µs 一拍）
 *  每拍流程：保护判定(OC1/OC2/欠压/启动 blanking) → Clarke → Park → dq PI → 反 Park
 *            → SVPWM → ATOM0 CH1/2/3 影子寄存器更新（中心对齐）
 *  坐标约定：
 *    - 角度：8192 计数/电角度圈（TLE5012 15bit 机械角 v%8192），0.044°/LSB
 *    - Clarke：iα = iu，iβ = (iv - iw)/√3（三相平衡）
 *    - Park：id = iα·cosθ + iβ·sinθ，iq = iβ·cosθ - iα·sinθ
 *    - 反 Park：vα = vd·cosθ - vq·sinθ，vβ = vd·sinθ + vq·cosθ
 *    - SVPWM：pwm_OutX 为半周期比较值 [0, Tpwm/2]；
 *      写入 ATOM 时 ScaledDuty = 2*pwm_Out（中心对齐，Period=10000）
 *  保护：见本文件 “OVERCURRENT / UNDERVOLTAGE PROTECTION” 段，完整流程见
 *        note/CurrentLoop_Protection.md
 **********************************************************************************************************************/#include "MotorFoc_CurrentLoop.h"
#include "MotorFoc_Pid.h"
#include "MotorFoc_SinCosTable.h"
#include "IfxGtm_reg.h"
#include <math.h> /* sqrtf for SVPWM magnitude limit */

#define MOTORFOC_SQRT3_3           (0.5773502691896257645F)
#define MOTORFOC_SQRT3             (1.73205078F)
#define MOTORFOC_VDC_MIN_RUN_DEFAULT    (6.0F)
#define MOTORFOC_VDC_SVPWM_MIN_V        (0.5F)
#define MOTORFOC_CURRENT_MAX_A_DEFAULT  (65.0F)
#define MOTORFOC_CURRENT_STARTUP_BLANKING_COUNT_DEFAULT    (100U)
#define MOTORFOC_CURRENT_UNDERVOLT_CONFIRM_COUNT_DEFAULT   (20U)
/* OC1: instantaneous hard trip = 2x rated, no debounce, always armed. */
#define MOTORFOC_CURRENT_INSTANT_TRIP_A_DEFAULT  (2.0F * MOTORFOC_CURRENT_MAX_A_DEFAULT)
/* OC2: 持续超限时间（秒）；10 kHz 一拍 = 100 µs。 */
#define MOTORFOC_CURRENT_TRIP_SEC_DEFAULT        (20.0F)
#define MOTORFOC_CURRENT_RECOVER_SEC_DEFAULT     (1.0F)
#define MOTORFOC_CURRENT_RECOVER_HYST_A_DEFAULT  (2.0F)
#define MOTORFOC_OC_AUTO_RECOVER_DEFAULT         (1U)
/* UV recovery hysteresis: recover when vdc >= MinVdcRunV + Hysteresis. */
#define MOTORFOC_VDC_HYSTERESIS_V_DEFAULT                  (1.0F)
/* UV auto-recover: vdc must stay >= recover threshold for this many loops. */
#define MOTORFOC_UNDERVOLT_RECOVER_COUNT_DEFAULT           (50U)
#define MOTORFOC_UV_AUTO_RECOVER_DEFAULT                   (1U)
#define MOTORFOC_ZERO_CURRENT_REFERENCE_A                  (0.001F)
/* ATOM0 CH1/2/3 center-aligned period (matches Pwm PBCfg 0x2710). */
#define MOTORFOC_PWM_ATOM_PERIOD           (10000U)
#define MOTORFOC_PWM_ATOM_MAX_TIMER        (0xFFFFFFU)
/* AGC GLB_CTRL UPEN_CTRLx: write 01=disable, 10=enable (00=no change).
   CH1 [19:18], CH2 [21:20], CH3 [23:22] must all be updated together. */
#define MOTORFOC_PWM_ATOM_UPEN_DIS_CH123   (0x00540000U)
#define MOTORFOC_PWM_ATOM_UPEN_EN_CH123    (0x00A80000U)
/* SVPWM sector-boundary hysteresis (volts in sA/sB/sC space).
 * Low speed: PI noise flips sector for one beat → single-sample Tcmp spike. */
#define MOTORFOC_SVPWM_SECTOR_HYST_FRAC    (0.03F)
#define MOTORFOC_SVPWM_SECTOR_HYST_MIN_V   (0.05F)

/* UDE/VOFA: last SVPWM sector code N in {1..6}, 0 = invalid/zero. */
volatile uint8 MotorFoc_SvpwmSector = 0U;
/* Last A/B/C sign bits packed as N (for hysteresis). */
static uint8 MotorFoc_SvpwmSectorBits = 3U;

/* Aggregate protection observation object (UDE: watch "MotorFoc_ProtObs"). */
volatile MotorFoc_ProtObsType MotorFoc_ProtObs =
{
  /* cfg */
  {
    MOTORFOC_CURRENT_INSTANT_TRIP_A_DEFAULT,             /* instantTripCurrentA   */
    MOTORFOC_CURRENT_MAX_A_DEFAULT,                      /* maxCurrentA           */
    MOTORFOC_CURRENT_TRIP_SEC_DEFAULT,                   /* overCurrentTripSec    */
    MOTORFOC_CURRENT_RECOVER_SEC_DEFAULT,                /* overCurrentRecoverSec */
    MOTORFOC_CURRENT_RECOVER_HYST_A_DEFAULT,             /* overCurrentRecoverHystA */
    MOTORFOC_OC_AUTO_RECOVER_DEFAULT,                    /* overCurrentAutoRecover */
    MOTORFOC_VDC_MIN_RUN_DEFAULT,                        /* minVdcRunV            */
    MOTORFOC_VDC_HYSTERESIS_V_DEFAULT,                   /* vdcHysteresisV        */
    MOTORFOC_CURRENT_UNDERVOLT_CONFIRM_COUNT_DEFAULT,    /* undervoltConfirmCount */
    MOTORFOC_UNDERVOLT_RECOVER_COUNT_DEFAULT,            /* undervoltRecoverCount */
    MOTORFOC_UV_AUTO_RECOVER_DEFAULT,                    /* uvAutoRecover         */
    MOTORFOC_CURRENT_STARTUP_BLANKING_COUNT_DEFAULT      /* startupBlankingCount  */
  },
  /* cnt */
  {
    0U,                                                   /* startupBlankingLeft   */
    0U,                                                   /* undervoltCounter      */
    0U,                                                   /* uvRecoverCounter      */
    0U,                                                   /* overCurrentCounter    */
    0U,                                                   /* overCurrentRecoverCounter */
    MOTORFOC_CURRENTLOOP_STATE_IDLE                       /* state                 */
  },
  /* fault */
  {
    0U,                                                   /* active                */
    MOTORFOC_CURRENT_FAULT_NONE,                          /* reason                */
    0U,                                                   /* clearRequest          */
    0U,                                                   /* runCount              */
    0.0F, 0.0F, 0.0F,                                     /* iuA / ivA / iwA       */
    0.0F,                                                 /* vdcV                  */
    0.0F, 0.0F,                                           /* idA / iqA             */
    0.0F, 0.0F,                                           /* vdV / vqV             */
    0U, 0U, 0U                                            /* pwmU / pwmV / pwmW    */
  },
  /* peak */
  { 0.0F, 0.0F, 0.0F },
  /* runCount */
  0U
};

static float32 MotorFoc_CurrentLoopRawIuA = 0.0F;
static float32 MotorFoc_CurrentLoopRawIvA = 0.0F;
static float32 MotorFoc_CurrentLoopRawIwA = 0.0F;

/* ===========================================================================
 * ATOM0 中心对齐 PWM 影子寄存器换算与写入
 * ---------------------------------------------------------------------------
 * ATOM CH 寄存器（IfxGtm_reg.h / IfxGtm_regdef.h）：
 *   CM0/CM1：当前比较值（硬件运行）；SR0/SR1：影子比较值（软件写）
 *   影子更新时机：在 ATOM 通道的更新点由 AGC 统一触发；
 *   ATOM0_AGC_GLB_CTRL.UPEN_CTRLx[2bit] 控制每通道是否允许影子更新：
 *     00=不改变，01=禁止更新，10=允许更新，11=保留
 *   （UPEN_CTRL0[17:16]=CH0，UPEN_CTRL1[19:18]=CH1，UPEN_CTRL2[21:20]=CH2，
 *     UPEN_CTRL3[23:22]=CH3，…）
 * ---------------------------------------------------------------------------
 * 把占空比 scaledDuty ∈ [0, Tpwm] 换算成中心对齐的 SR0/SR1：
 *   SR0=(Tpwm-duty)/2，SR1=SR0+duty → 高电平在周期中点两侧对称展开。
 *   边界：duty=0 → SR0=0xFFFFFF/SR1=0（整周期低）；
 *         duty=Tpwm → SR0=0/SR1=0xFFFFFF（整周期高）。
 * =========================================================================== */
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


/* 直接写 ATOM0 CH1/2/3 影子寄存器（中心对齐、三相一致更新）：
 *   1) AGC GLB_CTRL.UPEN_CTRL1/2/3 = 01 → 禁止 CH1/CH2/CH3 影子更新
 *   2) 写入 CH1/2/3 的 SR0/SR1 影子比较值
 *   3) AGC GLB_CTRL.UPEN_CTRL1/2/3 = 10 → 允许更新，三相同步生效 */
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

  /* UPEN_CTRL1/2/3 = 01：先禁止 CH1/CH2/CH3 更新。 */
  GTM_ATOM0_AGC_GLB_CTRL.U = MOTORFOC_PWM_ATOM_UPEN_DIS_CH123;
  /* 写影子比较值（本拍不生效，等 UPEN 使能后的更新点）。 */
  GTM_ATOM0_CH1_SR0.U = sr0u;
  GTM_ATOM0_CH1_SR1.U = sr1u;
  GTM_ATOM0_CH2_SR0.U = sr0v;
  GTM_ATOM0_CH2_SR1.U = sr1v;
  GTM_ATOM0_CH3_SR0.U = sr0w;
  GTM_ATOM0_CH3_SR1.U = sr1w;
  /* UPEN_CTRL1/2/3 = 10：允许更新，三相同步生效。 */
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

/* Clarke 变换：静止三相电流 → αβ 轴（三相平衡，iw 由 iv 参与差分）。
   iα = iu；iβ = (iv - iw) / √3 */
static void MotorFoc_DoClarke(MotorFoc_ContextType* ctx)
{
  ctx->iab.real = ctx->i_motor.u;
  ctx->iab.imag = (ctx->i_motor.v - ctx->i_motor.w) * MOTORFOC_SQRT3_3;
}

/* Park 变换：αβ → dq（旋转到电角度 θ 的同步坐标系）。
   id = iα·cosθ + iβ·sinθ；iq = iβ·cosθ - iα·sinθ */
static void MotorFoc_DoPark(MotorFoc_ContextType* ctx)
{
  ctx->idqMeas.real = (ctx->iab.real * ctx->angle.cos) + (ctx->iab.imag * ctx->angle.sin);
  ctx->idqMeas.imag = (ctx->iab.imag * ctx->angle.cos) - (ctx->iab.real * ctx->angle.sin);
}

/* 反 Park：dq 电压 → αβ（用于 SVPWM 合成）。
   vα = vd·cosθ - vq·sinθ；vβ = vd·sinθ + vq·cosθ */
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
  return MOTORFOC_SQRT3_3 * vdc * ctx->Tpwm.pwmMinTimes * 0.9F;
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

/* dq 电流 PI：先按母线电压刷新输出限幅（电压矢量限幅），再分别计算
   vd/vq，最后对 dq 电压矢量做模长限幅（六边形内切圆，避免过调制）。 */
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
  float32 currentLimit = MotorFoc_ProtObs.cfg.maxCurrentA;

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
  MotorFoc_ProtObs.fault.active = 1U;
  MotorFoc_ProtObs.fault.reason = faultReason;
  MotorFoc_ProtObs.cnt.state = MOTORFOC_CURRENTLOOP_STATE_FAULT;
  MotorFoc_ProtObs.fault.runCount = MotorFoc_ProtObs.runCount;
  MotorFoc_ProtObs.fault.iuA = MotorFoc_CurrentLoopRawIuA;
  MotorFoc_ProtObs.fault.ivA = MotorFoc_CurrentLoopRawIvA;
  MotorFoc_ProtObs.fault.iwA = MotorFoc_CurrentLoopRawIwA;
  MotorFoc_ProtObs.fault.vdcV = ctx->i_motor.vdc;
  MotorFoc_ProtObs.fault.idA = ctx->idqMeas.real;
  MotorFoc_ProtObs.fault.iqA = ctx->idqMeas.imag;
  MotorFoc_ProtObs.fault.vdV = ctx->vdqRef.real;
  MotorFoc_ProtObs.fault.vqV = ctx->vdqRef.imag;
  MotorFoc_ProtObs.fault.pwmU = ctx->Tpwm.pwm_OutU;
  MotorFoc_ProtObs.fault.pwmV = ctx->Tpwm.pwm_OutV;
  MotorFoc_ProtObs.fault.pwmW = ctx->Tpwm.pwm_OutW;
}

static uint8 MotorFoc_ConsumeStartupBlanking(void)
{
  if (MotorFoc_ProtObs.cnt.startupBlankingLeft > 0U)
  {
    MotorFoc_ProtObs.cnt.startupBlankingLeft--;
    MotorFoc_ProtObs.cnt.undervoltCounter = 0U;
    MotorFoc_ProtObs.cnt.overCurrentCounter = 0U;
    MotorFoc_ProtObs.cnt.state = MOTORFOC_CURRENTLOOP_STATE_BLANKING;
    return 1U;
  }

  MotorFoc_ProtObs.cnt.state = MOTORFOC_CURRENTLOOP_STATE_RUN;
  return 0U;
}

static uint8 MotorFoc_IsVdcUsable(MotorFoc_ContextType* ctx)
{
  return (ctx->i_motor.vdc > 0.1F) ? 1U : 0U;
}

static uint8 MotorFoc_CheckOverCurrentFault(MotorFoc_ContextType* ctx)
{
  uint32 tripBeats;
  float32 tripSec = MotorFoc_ProtObs.cfg.overCurrentTripSec;

  /* 持续超限时间(秒) → 拍数（10 kHz，一拍 = 100 µs）。
     只有电流持续超过 maxCurrentA 达到该时长才锁存过流，瞬时尖峰不触发。 */
  if (tripSec < 0.0F)
  {
    tripSec = 0.0F;
  }
  tripBeats = (uint32)(tripSec * 10000.0F);
  if (tripBeats == 0U)
  {
    tripBeats = 1U;
  }

  if (MotorFoc_IsPhaseCurrentOverLimit(ctx) == 0U)
  {
    MotorFoc_ProtObs.cnt.overCurrentCounter = 0U;
    return 0U;
  }

  if (MotorFoc_ProtObs.cnt.overCurrentCounter < 0xFFFFFFFFU)
  {
    MotorFoc_ProtObs.cnt.overCurrentCounter++;
  }

  return (MotorFoc_ProtObs.cnt.overCurrentCounter >= tripBeats) ? 1U : 0U;
}

/* OC 自动恢复判定（迟滞）：三相电流都回落到 (maxCurrentA - hyst) 以下并
   持续 overCurrentRecoverSec 才允许清除过流故障。 */
static uint8 MotorFoc_CheckOverCurrentRecovered(MotorFoc_ContextType* ctx)
{
  uint32 recoverBeats;
  float32 recoverSec = MotorFoc_ProtObs.cfg.overCurrentRecoverSec;
  float32 hysteresis = MotorFoc_ProtObs.cfg.overCurrentRecoverHystA;
  float32 limit = MotorFoc_ProtObs.cfg.maxCurrentA;
  float32 recoverLimit;

  if (limit < 0.0F)
  {
    limit = -limit;
  }
  if (hysteresis < 0.0F)
  {
    hysteresis = 0.0F;
  }
  recoverLimit = limit - hysteresis;
  if (recoverLimit < 0.0F)
  {
    recoverLimit = 0.0F;
  }

  if (recoverSec < 0.0F)
  {
    recoverSec = 0.0F;
  }
  recoverBeats = (uint32)(recoverSec * 10000.0F);
  if (recoverBeats == 0U)
  {
    recoverBeats = 1U;
  }

  if ((MotorFoc_AbsFloat(MotorFoc_CurrentLoopRawIuA) <= recoverLimit) &&
      (MotorFoc_AbsFloat(MotorFoc_CurrentLoopRawIvA) <= recoverLimit) &&
      (MotorFoc_AbsFloat(MotorFoc_CurrentLoopRawIwA) <= recoverLimit))
  {
    if (MotorFoc_ProtObs.cnt.overCurrentRecoverCounter < 0xFFFFFFFFU)
    {
      MotorFoc_ProtObs.cnt.overCurrentRecoverCounter++;
    }
  }
  else
  {
    MotorFoc_ProtObs.cnt.overCurrentRecoverCounter = 0U;
  }

  return (MotorFoc_ProtObs.cnt.overCurrentRecoverCounter >= recoverBeats) ? 1U : 0U;
}

static uint8 MotorFoc_CheckUndervoltFault(MotorFoc_ContextType* ctx)
{
  uint16 confirmCount = MotorFoc_ProtObs.cfg.undervoltConfirmCount;
  float32 minVdc = MotorFoc_ProtObs.cfg.minVdcRunV;

  if (minVdc < 0.0F)
  {
    minVdc = 0.0F;
  }

  if (ctx->i_motor.vdc >= minVdc)
  {
    MotorFoc_ProtObs.cnt.undervoltCounter = 0U;
    return 0U;
  }

  if (confirmCount == 0U)
  {
    confirmCount = 1U;
  }

  if (MotorFoc_ProtObs.cnt.undervoltCounter < confirmCount)
  {
    MotorFoc_ProtObs.cnt.undervoltCounter++;
  }

  if (MotorFoc_ProtObs.cnt.undervoltCounter >= confirmCount)
  {
    return 1U;
  }

  return 0U;
}

/**********************************************************************************************************************
 *  OVERCURRENT / UNDERVOLTAGE PROTECTION (production-style)
 *  -------------------------------------------------------------------------------------------------------------------
 *  Every 10 kHz fast-loop beat runs through this decision chain in
 *  MotorFoc_RunCurrentLoop():
 *
 *    1) explicit clear request (upper layer / user)         -> ClearFault()
 *    2) latched fault ?
 *         - undervoltage + auto-recover enabled: count stable bus
 *           samples above (trip + hysteresis); clear when reached
 *         - otherwise: output stays off (CurrentLoopStop)
 *    3) update running peak phase currents (diagnostics)
 *    4) OC1  instantaneous overcurrent (|I| > InstantTripCurrentA)
 *           -> trip immediately, NO debounce, ALWAYS armed
 *              (including startup blanking). Software fast trip;
 *              a hardware comparator / TLE9180 fault input should
 *              back this up in a production design.
 *    5) startup blanking active ? (first StartupBlankingCount loops
 *           after output enable)
 *         - yes: skip debounced OC2/UV checks, counters held at 0
 *         - no : run steps 6) and 7)
 *    6) OC2  sustained overcurrent: |I| > MaxCurrentA for
 *           overCurrentTripSec (default 20 s) continuously -> latch
 *    7) UV   undervoltage (vdc < MinVdcRunV for
 *           UndervoltConfirmCount loops, ~2 ms)            -> latch
 *
 *  Fault policy:
 *    - overcurrent (OC1/OC2): auto-clears (if overCurrentAutoRecover == 1)
 *      when all phase currents fall below (MaxCurrentA - hyst) for
 *      overCurrentRecoverSec; otherwise explicit clear required
 *    - undervoltage: auto-clears when the DC link recovers above
 *      MinVdcRunV + VdcHysteresisV for UndervoltRecoverCount loops
 *      (if UvAutoRecover == 1); the upper layer re-enables the
 *      output through PrepareOutputEnable, which re-arms blanking.
 *
 *  All thresholds / counts are volatile and UDE-tunable at runtime.
 **********************************************************************************************************************/

static void MotorFoc_UpdatePeakCurrents(void)
{
  float32 a;
  float32 b;
  float32 c;

  a = MotorFoc_AbsFloat(MotorFoc_CurrentLoopRawIuA);
  b = MotorFoc_AbsFloat(MotorFoc_CurrentLoopRawIvA);
  c = MotorFoc_AbsFloat(MotorFoc_CurrentLoopRawIwA);

  if (a > MotorFoc_ProtObs.peak.iuA) { MotorFoc_ProtObs.peak.iuA = a; }
  if (b > MotorFoc_ProtObs.peak.ivA) { MotorFoc_ProtObs.peak.ivA = b; }
  if (c > MotorFoc_ProtObs.peak.iwA) { MotorFoc_ProtObs.peak.iwA = c; }
}

/* OC1: instantaneous hard overcurrent trip (no debounce). */
static uint8 MotorFoc_CheckInstantOverCurrent(void)
{
  float32 trip = MotorFoc_ProtObs.cfg.instantTripCurrentA;

  if (trip < 0.0F)
  {
    trip = -trip;
  }
  if (trip <= 0.0F)
  {
    return 0U;
  }

  if (MotorFoc_AbsFloat(MotorFoc_CurrentLoopRawIuA) > trip) { return 1U; }
  if (MotorFoc_AbsFloat(MotorFoc_CurrentLoopRawIvA) > trip) { return 1U; }
  if (MotorFoc_AbsFloat(MotorFoc_CurrentLoopRawIwA) > trip) { return 1U; }
  return 0U;
}

/* UV recovery check with hysteresis: vdc must stay >= trip + hyst for
   UndervoltRecoverCount loops before the fault may auto-clear. */
static uint8 MotorFoc_CheckUvRecovered(MotorFoc_ContextType* ctx)
{
  uint16 recoverCount = MotorFoc_ProtObs.cfg.undervoltRecoverCount;
  float32 hysteresis = MotorFoc_ProtObs.cfg.vdcHysteresisV;
  float32 recoverV;

  if (hysteresis < 0.0F)
  {
    hysteresis = 0.0F;
  }
  recoverV = MotorFoc_ProtObs.cfg.minVdcRunV + hysteresis;
  if (recoverV < 0.0F)
  {
    recoverV = 0.0F;
  }

  if (ctx->i_motor.vdc >= recoverV)
  {
    if (MotorFoc_ProtObs.cnt.uvRecoverCounter < 0xFFFFU)
    {
      MotorFoc_ProtObs.cnt.uvRecoverCounter++;
    }
  }
  else
  {
    MotorFoc_ProtObs.cnt.uvRecoverCounter = 0U;
  }

  if (recoverCount == 0U)
  {
    recoverCount = 1U;
  }
  return (MotorFoc_ProtObs.cnt.uvRecoverCounter >= recoverCount) ? 1U : 0U;
}

static uint8 MotorFoc_SvpwmSignBitHyst(float32 value, uint8 prevBit, float32 hyst)
{
  if (value > hyst)
  {
    return 1U;
  }
  if (value < -hyst)
  {
    return 0U;
  }
  return prevBit;
}

/* 六扇区 SVPWM：αβ 电压 → 中心对齐比较值 tCmp ∈ [0, Tpwm/2]。
   - 先按母线电压限制矢量模长（√3/3 × vdc × pwmMinTimes）
   - vdc 过低(<MOTORFOC_VDC_SVPWM_MIN_V)时输出中性占空比并返回，避免除零
   - 零矢量时保持 25% 半周期（50% 占空比，零平均电压）
   - 扇区比较带滞回，抑制低速电流环噪声引起的单拍扇区翻转尖刺 */
static void MotorFoc_DoSvpwm(MotorFoc_ContextType* ctx)
{
  uint8 sectorCode = 0U;
  uint8 bitA;
  uint8 bitB;
  uint8 bitC;
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
  float32 hyst;

  voltageLimit = MOTORFOC_SQRT3_3 * ctx->i_motor.vdc * ctx->Tpwm.pwmMinTimes;
  voltageMagnitude = sqrtf((ctx->vabRef.real * ctx->vabRef.real) +
                           (ctx->vabRef.imag * ctx->vabRef.imag));
  if ((voltageMagnitude > voltageLimit) && (voltageMagnitude > 0.0F))
  {
    scale = voltageLimit / voltageMagnitude;
    ctx->vabRef.real *= scale;
    ctx->vabRef.imag *= scale;
    voltageMagnitude = voltageLimit;
  }

  if (ctx->i_motor.vdc < MOTORFOC_VDC_SVPWM_MIN_V)
  {
    /* No usable DC link: hold neutral duty and avoid divide-by-zero below. */
    ctx->Tpwm.pwm_OutU = (uint32)(ctx->Tpwm.Tpwm * 0.25F);
    ctx->Tpwm.pwm_OutV = (uint32)(ctx->Tpwm.Tpwm * 0.25F);
    ctx->Tpwm.pwm_OutW = (uint32)(ctx->Tpwm.Tpwm * 0.25F);
    MotorFoc_SvpwmSector = 0U;
    return;
  }

  /* TC364 six-sector SVPWM. pwm_OutX remains a compare tick in [0, Tpwm / 2]. */
  sA = ctx->vabRef.imag;
  sB = (MOTORFOC_SQRT3 * ctx->vabRef.real - ctx->vabRef.imag) * 0.5F;
  sC = (-MOTORFOC_SQRT3 * ctx->vabRef.real - ctx->vabRef.imag) * 0.5F;

  hyst = (MOTORFOC_SVPWM_SECTOR_HYST_FRAC * voltageMagnitude);
  if (hyst < MOTORFOC_SVPWM_SECTOR_HYST_MIN_V)
  {
    hyst = MOTORFOC_SVPWM_SECTOR_HYST_MIN_V;
  }

  bitA = MotorFoc_SvpwmSignBitHyst(sA, (uint8)(MotorFoc_SvpwmSectorBits & 0x01U), hyst);
  bitB = MotorFoc_SvpwmSignBitHyst(sB, (uint8)((MotorFoc_SvpwmSectorBits >> 1) & 0x01U), hyst);
  bitC = MotorFoc_SvpwmSignBitHyst(sC, (uint8)((MotorFoc_SvpwmSectorBits >> 2) & 0x01U), hyst);

  if (bitA != 0U)
  {
    sectorCode = 1U;
  }
  if (bitB != 0U)
  {
    sectorCode += 2U;
  }
  if (bitC != 0U)
  {
    sectorCode += 4U;
  }

  /* N==0 is invalid for a non-zero vector; keep previous valid sector. */
  if ((sectorCode == 0U) && (MotorFoc_SvpwmSectorBits >= 1U) && (MotorFoc_SvpwmSectorBits <= 6U))
  {
    sectorCode = MotorFoc_SvpwmSectorBits;
  }

  if ((sectorCode >= 1U) && (sectorCode <= 6U))
  {
    MotorFoc_SvpwmSectorBits = sectorCode;
    MotorFoc_SvpwmSector = sectorCode;
  }
  else
  {
    MotorFoc_SvpwmSector = 0U;
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

  if (tCmpU < 0.0F)
  {
    tCmpU = 0.0F;
  }
  if (tCmpV < 0.0F)
  {
    tCmpV = 0.0F;
  }
  if (tCmpW < 0.0F)
  {
    tCmpW = 0.0F;
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

  /* pwm_Out is half-period Tcmp; ScaledDuty = 2 * pwm_Out (Period == 10000).
   * last364 ATOM is center-aligned (MCAL); do NOT use upperComputer edge-aligned
   * (SR1=Tcmp, SR0=Tpwm-Tcmp) mapping — that inverts duty on this hardware. */
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
  MotorFoc_ProtObs.runCount++;

  /* 1) Explicit clear request (user / upper layer). */
  if (MotorFoc_ProtObs.fault.clearRequest != 0U)
  {
    MotorFoc_ProtObs.fault.clearRequest = 0U;
    MotorFoc_CurrentLoopClearFault();
  }

  /* 2) Latched fault:
     - overcurrent (OC1/OC2): sticky, needs explicit clear;
     - undervoltage: auto-recover (if enabled) when the DC link stays
       above (trip + hysteresis) for UndervoltRecoverCount loops. */
  if (MotorFoc_ProtObs.fault.active != 0U)
  {
    if (MotorFoc_ProtObs.fault.reason == MOTORFOC_CURRENT_FAULT_UNDERVOLT)
    {
      if ((MotorFoc_ProtObs.cfg.uvAutoRecover != 0U) &&
          (MotorFoc_CheckUvRecovered(ctx) != 0U))
      {
        MotorFoc_CurrentLoopClearFault();
      }
    }
    else if (MotorFoc_ProtObs.cfg.overCurrentAutoRecover != 0U)
    {
      /* OC1/OC2 自动恢复：三相电流回落到 (maxCurrentA - hyst) 以下并
         持续 overCurrentRecoverSec 后自动清除（迟滞防抖），由上层重新使能。 */
      if (MotorFoc_CheckOverCurrentRecovered(ctx) != 0U)
      {
        MotorFoc_CurrentLoopClearFault();
      }
    }
    MotorFoc_CurrentLoopStop(ctx);
    return;
  }

  /* 3) Running peak currents (diagnostics; reset on clear / arm). */
  MotorFoc_UpdatePeakCurrents();

  /* 4) OC1 instantaneous overcurrent: always armed, no debounce,
        even during startup blanking. */
  if (MotorFoc_CheckInstantOverCurrent() != 0U)
  {
    MotorFoc_SetFault(ctx, MOTORFOC_CURRENT_FAULT_OVERCURRENT_INST);
    MotorFoc_CurrentLoopStop(ctx);
    return;
  }

  /* 5) Startup blanking: only masks the debounced OC2/UV checks below;
        debounce counters are held at 0 during blanking. */
  if (MotorFoc_ConsumeStartupBlanking() == 0U)
  {
    /* 6) OC2 confirmed overcurrent (debounced). */
    if (MotorFoc_CheckOverCurrentFault(ctx) != 0U)
    {
      MotorFoc_SetFault(ctx, MOTORFOC_CURRENT_FAULT_OVERCURRENT);
      MotorFoc_CurrentLoopStop(ctx);
      return;
    }

    /* 7) Undervoltage (debounced). */
    if (MotorFoc_CheckUndervoltFault(ctx) != 0U)
    {
      MotorFoc_SetFault(ctx, MOTORFOC_CURRENT_FAULT_UNDERVOLT);
      MotorFoc_CurrentLoopStop(ctx);
      return;
    }
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

/* Voltage open-loop (forced angle already in ctx): no current PI.
   Used after open-loop align so SVPWM/saddle is not modulated by current noise. */
void MotorFoc_RunVoltageOpenLoop(MotorFoc_ContextType* ctx,
                                 float32 vdRef,
                                 float32 vqRef)
{
  MotorFoc_ProtObs.runCount++;

  if (MotorFoc_ProtObs.fault.clearRequest != 0U)
  {
    MotorFoc_ProtObs.fault.clearRequest = 0U;
    MotorFoc_CurrentLoopClearFault();
  }

  if (MotorFoc_ProtObs.fault.active != 0U)
  {
    if (MotorFoc_ProtObs.fault.reason == MOTORFOC_CURRENT_FAULT_UNDERVOLT)
    {
      if ((MotorFoc_ProtObs.cfg.uvAutoRecover != 0U) &&
          (MotorFoc_CheckUvRecovered(ctx) != 0U))
      {
        MotorFoc_CurrentLoopClearFault();
      }
    }
    else if (MotorFoc_ProtObs.cfg.overCurrentAutoRecover != 0U)
    {
      if (MotorFoc_CheckOverCurrentRecovered(ctx) != 0U)
      {
        MotorFoc_CurrentLoopClearFault();
      }
    }
    MotorFoc_CurrentLoopStop(ctx);
    return;
  }

  MotorFoc_UpdatePeakCurrents();

  if (MotorFoc_CheckInstantOverCurrent() != 0U)
  {
    MotorFoc_SetFault(ctx, MOTORFOC_CURRENT_FAULT_OVERCURRENT_INST);
    MotorFoc_CurrentLoopStop(ctx);
    return;
  }

  if (MotorFoc_ConsumeStartupBlanking() == 0U)
  {
    if (MotorFoc_CheckOverCurrentFault(ctx) != 0U)
    {
      MotorFoc_SetFault(ctx, MOTORFOC_CURRENT_FAULT_OVERCURRENT);
      MotorFoc_CurrentLoopStop(ctx);
      return;
    }

    if (MotorFoc_CheckUndervoltFault(ctx) != 0U)
    {
      MotorFoc_SetFault(ctx, MOTORFOC_CURRENT_FAULT_UNDERVOLT);
      MotorFoc_CurrentLoopStop(ctx);
      return;
    }
  }

  /* Keep idqMeas for UDE/VOFA; freeze current PI so it cannot fight voltage cmds. */
  MotorFoc_DoClarke(ctx);
  MotorFoc_UpdateSinCos(ctx);
  MotorFoc_DoPark(ctx);
  MotorFoc_ResetCurrentPidState(ctx);

  ctx->idqRef.real = 0.0F;
  ctx->idqRef.imag = 0.0F;
  ctx->vdqRef.real = vdRef;
  ctx->vdqRef.imag = vqRef;
  MotorFoc_LimitDqVoltageVector(ctx);
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
  MotorFoc_ProtObs.fault.active = 0U;
  MotorFoc_ProtObs.fault.reason = MOTORFOC_CURRENT_FAULT_NONE;
  MotorFoc_ProtObs.cnt.undervoltCounter = 0U;
  MotorFoc_ProtObs.cnt.uvRecoverCounter = 0U;
  MotorFoc_ProtObs.cnt.overCurrentCounter = 0U;
  MotorFoc_ProtObs.cnt.overCurrentRecoverCounter = 0U;
  MotorFoc_ProtObs.fault.runCount = 0U;
  MotorFoc_ProtObs.fault.iuA = 0.0F;
  MotorFoc_ProtObs.fault.ivA = 0.0F;
  MotorFoc_ProtObs.fault.iwA = 0.0F;
  MotorFoc_ProtObs.fault.vdcV = 0.0F;
  MotorFoc_ProtObs.peak.iuA = 0.0F;
  MotorFoc_ProtObs.peak.ivA = 0.0F;
  MotorFoc_ProtObs.peak.iwA = 0.0F;
}

void MotorFoc_CurrentLoopArmStartupBlanking(void)
{
  MotorFoc_ProtObs.cnt.startupBlankingLeft = MotorFoc_ProtObs.cfg.startupBlankingCount;
  MotorFoc_ProtObs.cnt.undervoltCounter = 0U;
  MotorFoc_ProtObs.cnt.uvRecoverCounter = 0U;
  MotorFoc_ProtObs.cnt.overCurrentCounter = 0U;
  MotorFoc_ProtObs.cnt.overCurrentRecoverCounter = 0U;
  MotorFoc_ProtObs.peak.iuA = 0.0F;
  MotorFoc_ProtObs.peak.ivA = 0.0F;
  MotorFoc_ProtObs.peak.iwA = 0.0F;
}
