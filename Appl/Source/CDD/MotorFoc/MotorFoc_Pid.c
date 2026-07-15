/*
 * @Author: qinXiong
 * @Date: 2026-07-11 09:00:42
 * @LastEditors: Qxiong&&2307975018@qq.com
 * @LastEditTime: 2026-07-11 11:38:37
 * @Description: 
 */
#include "MotorFoc_Pid.h"

void MotorFoc_CurrentPidInit(MotorFoc_CurrentPidType* pi,
                             float32 w,
                             float32 rs,
                             float32 lm)
{
  pi->DisTimer = 0.0001F;
  pi->P_Gain = w * lm;
  pi->I_Gain = w * rs;
  pi->D_Gain = 0.0F;
  pi->B_Gain = 0.015F;
  pi->I_Sum = 0.0F;
  pi->Error = 0.0F;
  pi->Out = 0.0F;
  pi->v1 = 0.0F;
  pi->ui = 0.0F;
  pi->i1 = 0.0F;
  pi->w1 = 0.0F;
  pi->Min_output = -6.92F * 0.8F;
  pi->Max_output = 6.92F * 0.8F;
}

void MotorFoc_SpeedPidInit(MotorFoc_SpeedPidType* pi)
{
  pi->DisTimer = 0.001F;
  pi->P_Gain = 0.02F;
  pi->I_Gain = 85.0F;
  pi->D_Gain = 0.0F;
  pi->B_Gain = 0.015F;
  pi->I_Sum = 0.0F;
  pi->Error = 0.0F;
  pi->Out = 0.0F;
  pi->v1 = 0.0F;
  pi->ui = 0.0F;
  pi->i1 = 0.0F;
  pi->w1 = 0.0F;
  pi->Min_output = -65.0F;
  pi->Max_output = 65.0F;
}

void MotorFoc_CurrentPidIdealCalc(float32 ref, float32 fdb, float32* out, MotorFoc_CurrentPidType* pi)
{
  pi->Error = ref - fdb;
  pi->ui = (pi->Out == pi->v1) ? ((pi->I_Gain * pi->DisTimer * pi->Error) + pi->i1) : pi->i1;
  pi->i1 = pi->ui;
  pi->v1 = pi->P_Gain * (pi->Error + pi->ui);

  if (pi->v1 >= pi->Max_output)
  {
    pi->Out = pi->Max_output;
  }
  else if (pi->v1 <= pi->Min_output)
  {
    pi->Out = pi->Min_output;
  }
  else
  {
    pi->Out = pi->v1;
  }

  pi->w1 = (pi->Out == pi->v1) ? 1.0F : 0.0F;
  *out = pi->Out;
}

void MotorFoc_SpeedPidIdealCalc(float32 ref, float32 fdb, float32* out, MotorFoc_SpeedPidType* pi)
{
  pi->Error = ref - fdb;
  pi->ui = (pi->Out == pi->v1) ? ((pi->I_Gain * pi->DisTimer * pi->Error) + pi->i1) : pi->i1;
  pi->i1 = pi->ui;
  pi->v1 = pi->P_Gain * (pi->Error + pi->ui);

  if (pi->v1 >= pi->Max_output)
  {
    pi->Out = pi->Max_output;
  }
  else if (pi->v1 <= pi->Min_output)
  {
    pi->Out = pi->Min_output;
  }
  else
  {
    pi->Out = pi->v1;
  }

  pi->w1 = (pi->Out == pi->v1) ? 1.0F : 0.0F;
  *out = pi->Out;
}
