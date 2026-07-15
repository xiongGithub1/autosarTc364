#ifndef MOTORFOC_TYPES_H
#define MOTORFOC_TYPES_H

#include "Std_Types.h"
#include "MotorFoc_Config.h"
#include "MotorFoc_Pid.h"

#define MOTORFOC_PWM_PERIOD_TICKS   (10000.0F)

typedef struct
{
  float32 u;
  float32 v;
  float32 w;
  float32 vdc;
  float32 vdcMax;
} MotorFoc_CurrentType;

typedef struct
{
  float32 angleRaw;
  float32 electricalAngleRad;
  float32 cos;
  float32 sin;
} MotorFoc_AngleType;

typedef struct
{
  float32 real;
  float32 imag;
} MotorFoc_CplxType;

typedef struct
{
  float32 Tpwm;
  float32 pwmMinTimes;
  uint32 pwmMinTimesMax;
  uint32 pwmMinTimesMin;
  uint32 pwm_OutU;
  uint32 pwm_OutV;
  uint32 pwm_OutW;
} MotorFoc_PwmType;

typedef struct
{
  float32 measSpeedRPM;
  float32 refSpeedRPM;
  float32 RefIq;
} MotorFoc_SpeedCtrlType;

struct MotorFoc_ContextTag
{
  MotorFoc_CurrentType i_motor;
  MotorFoc_AngleType angle;
  MotorFoc_CplxType iab;
  MotorFoc_CplxType idqRef;
  MotorFoc_CplxType idqMeas;
  MotorFoc_CplxType vdqRef;
  MotorFoc_CplxType vabRef;
  MotorFoc_CurrentPidType piId;
  MotorFoc_CurrentPidType piIq;
  MotorFoc_SpeedPidType piSpeed;
  MotorFoc_PwmType Tpwm;
  MotorFoc_MotorParamType motor;
  MotorFoc_SpeedCtrlType speedControl;
};

#endif /* MOTORFOC_TYPES_H */
