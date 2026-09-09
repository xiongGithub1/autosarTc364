#ifndef MOTORCDD_FOC_H
#define MOTORCDD_FOC_H

#include "Std_Types.h"
#include "MotorFoc_Types.h"

typedef enum
{
  MOTORCDD_ANGLE_SRC_TLE5012 = 0U,
  MOTORCDD_ANGLE_SRC_RESOLVER = 1U
} MotorCdd_AngleSourceType;

extern MotorFoc_ContextType MotorCdd_FocContext;
extern volatile uint32 MotorCdd_FocLoopCounter;
extern volatile uint32 MotorCdd_AngleSpiFastLoopCount;
/* UDE: 0 = TLE5012, 1 = TLE5501 resolver (DSADC). Exclusive source for FOC. */
extern volatile MotorCdd_AngleSourceType MotorCdd_AngleSource;

void MotorCdd_FocInit(void);
void MotorCdd_FocFastLoop(void);
/* 1 ms ASW publishes Mode/Id/Iq; fast loop reads this mirror only. */
void MotorCdd_FocSetCmdMirror(uint8 motorMode, float32 idRef, float32 iqRef);
/* CDD main backup sync from RTE ports into the same mirror. */
void MotorCdd_FocUpdateCmdMirror(void);
/* Publish electrical angle from the latest SPI frame; fast loop uses it immediately. */
void MotorCdd_FocPublishLatestAngle(float32 electricalAngleRaw,
                                    float32 electricalAngleRad);
void MotorCdd_FocUpdateLatestAngleFromSensor(void);
void MotorCdd_FocPrepareOutputEnable(void);
void MotorCdd_FocStopOutput(void);
void MotorCdd_FocClearFault(void);
uint8 MotorCdd_FocHasFault(void);

#endif /* MOTORCDD_FOC_H */

