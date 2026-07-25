#ifndef MOTORCDD_FOC_H
#define MOTORCDD_FOC_H

#include "Std_Types.h"
#include "MotorFoc_Types.h"

/* 0 = no angle SPI in FOC (forced-angle modes only / debug).
 * 1 = IPB-style blocking AVAL every FocFastLoop (~100 us).
 *     Requires DMA CH4/5 ISR priority > AdcIsr. */
#ifndef MOTORCDD_FOC_ANGLE_SPI_IN_FASTLOOP
#define MOTORCDD_FOC_ANGLE_SPI_IN_FASTLOOP   (1U)
#endif

extern MotorFoc_ContextType MotorCdd_FocContext;
extern volatile uint32 MotorCdd_FocLoopCounter;
extern volatile uint32 MotorCdd_AngleSpiFastLoopCount;

void MotorCdd_FocInit(void);
void MotorCdd_FocFastLoop(void);
/* 1 ms ASW publishes Mode/Id/Iq; fast loop reads this mirror only. */
void MotorCdd_FocSetCmdMirror(uint8 motorMode, float32 idRef, float32 iqRef);
/* CDD main backup sync from RTE ports into the same mirror. */
void MotorCdd_FocUpdateCmdMirror(void);
/* Publish electrical angle from slow path (after SPI); fast loop only reads cache. */
void MotorCdd_FocPublishAngleCache(float32 electricalAngleRaw,
                                   float32 electricalAngleRad);
void MotorCdd_FocUpdateAngleCacheFromSensor(void);
void MotorCdd_FocPrepareOutputEnable(void);
void MotorCdd_FocStopOutput(void);
void MotorCdd_FocClearFault(void);
uint8 MotorCdd_FocHasFault(void);

#endif /* MOTORCDD_FOC_H */

