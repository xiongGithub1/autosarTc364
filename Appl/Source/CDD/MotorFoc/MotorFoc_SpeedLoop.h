#ifndef MOTORFOC_SPEEDLOOP_H
#define MOTORFOC_SPEEDLOOP_H

#include "MotorFoc_Types.h"

void MotorFoc_SpeedLoopInit(MotorFoc_ContextType* ctx);
void MotorFoc_RunSpeedLoop(MotorFoc_ContextType* ctx, float32 measSpeedRpm);

#endif /* MOTORFOC_SPEEDLOOP_H */
