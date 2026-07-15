#include "MotorFoc_SpeedLoop.h"
#include "MotorFoc_Pid.h"

void MotorFoc_SpeedLoopInit(MotorFoc_ContextType* ctx)
{
  MotorFoc_SpeedPidInit(&ctx->piSpeed);
  ctx->speedControl.refSpeedRPM = 0.0F;
  ctx->speedControl.measSpeedRPM = 0.0F;
  ctx->speedControl.RefIq = 0.0F;
}

void MotorFoc_RunSpeedLoop(MotorFoc_ContextType* ctx, float32 measSpeedRpm)
{
  ctx->speedControl.measSpeedRPM = measSpeedRpm;

  if ((ctx->speedControl.measSpeedRPM > -0.5F) &&
      (ctx->speedControl.measSpeedRPM < 0.5F) &&
      (ctx->speedControl.refSpeedRPM == 0.0F))
  {
    ctx->speedControl.measSpeedRPM = 0.0F;
    ctx->piSpeed.ui = 0.0F;
    ctx->piSpeed.i1 = 0.0F;
  }

  MotorFoc_SpeedPidIdealCalc(ctx->speedControl.refSpeedRPM,
                             ctx->speedControl.measSpeedRPM,
                             &ctx->speedControl.RefIq,
                             &ctx->piSpeed);
}
