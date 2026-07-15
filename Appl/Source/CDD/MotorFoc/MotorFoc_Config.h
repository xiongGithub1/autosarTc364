#ifndef MOTORFOC_CONFIG_H
#define MOTORFOC_CONFIG_H

#include "Std_Types.h"

typedef struct
{
  uint8 polePairs;
  float32 rs;
  float32 lm;
  float32 w_i_dq;
  float32 w_speed;
} MotorFoc_MotorParamType;

typedef struct MotorFoc_ContextTag MotorFoc_ContextType;

void MotorFoc_ConfigInit(MotorFoc_MotorParamType* motor);
void MotorFoc_ConfigInitContext(MotorFoc_ContextType* ctx);

#endif /* MOTORFOC_CONFIG_H */
