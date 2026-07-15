#include "MotorFoc_Config.h"
#include "MotorFoc_Types.h"

void MotorFoc_ConfigInit(MotorFoc_MotorParamType* motor)
{
  motor->rs = 0.0225F;
  motor->lm = 0.000038F;
  motor->polePairs = 4U;
  motor->w_i_dq = 6283.1852F;
  motor->w_speed = 628.0F;
}

void MotorFoc_ConfigInitContext(MotorFoc_ContextType* ctx)
{
  MotorFoc_ConfigInit(&ctx->motor);

  ctx->i_motor.vdcMax = 18.0F;
  ctx->i_motor.vdc = 12.0F;
  ctx->Tpwm.Tpwm = MOTORFOC_PWM_PERIOD_TICKS;
  ctx->Tpwm.pwmMinTimes = 0.99F;
  ctx->Tpwm.pwmMinTimesMax = (uint32)(ctx->Tpwm.Tpwm * 0.5F * ctx->Tpwm.pwmMinTimes);
  ctx->Tpwm.pwmMinTimesMin = (uint32)(ctx->Tpwm.Tpwm * 0.5F * (1.0F - ctx->Tpwm.pwmMinTimes));
  ctx->speedControl.measSpeedRPM = 0.0F;
  ctx->speedControl.refSpeedRPM = 0.0F;
  ctx->speedControl.RefIq = 0.0F;
  ctx->idqRef.real = 0.0F;
  ctx->idqRef.imag = 0.0F;
}
