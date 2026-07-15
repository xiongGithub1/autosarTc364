#ifndef MOTORFOC_PID_H
#define MOTORFOC_PID_H

#include "Std_Types.h"

typedef struct
{
  float32 P_Gain;
  float32 I_Gain;
  float32 D_Gain;
  float32 B_Gain;
  float32 Error;
  float32 Max_output;
  float32 Min_output;
  float32 Out;
  float32 v1;
  float32 ui;
  float32 i1;
  float32 w1;
  float32 I_Sum;
  float32 DisTimer;
} MotorFoc_CurrentPidType;

typedef struct
{
  float32 P_Gain;
  float32 I_Gain;
  float32 D_Gain;
  float32 B_Gain;
  float32 Error;
  float32 Max_output;
  float32 Min_output;
  float32 Out;
  float32 v1;
  float32 ui;
  float32 i1;
  float32 w1;
  float32 I_Sum;
  float32 DisTimer;
} MotorFoc_SpeedPidType;

void MotorFoc_CurrentPidInit(MotorFoc_CurrentPidType* pi,
                             float32 w,
                             float32 rs,
                             float32 lm);
void MotorFoc_SpeedPidInit(MotorFoc_SpeedPidType* pi);
void MotorFoc_CurrentPidIdealCalc(float32 ref,
                                  float32 fdb,
                                  float32* out,
                                  MotorFoc_CurrentPidType* pi);
void MotorFoc_SpeedPidIdealCalc(float32 ref,
                                float32 fdb,
                                float32* out,
                                MotorFoc_SpeedPidType* pi);

#endif /* MOTORFOC_PID_H */
