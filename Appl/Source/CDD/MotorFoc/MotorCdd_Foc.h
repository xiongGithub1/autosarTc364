#ifndef MOTORCDD_FOC_H
#define MOTORCDD_FOC_H

#include "Std_Types.h"
#include "MotorFoc_Types.h"

/* 0 = 5012 async Kick/Consume in StartApp 1 ms + fast-loop angle extrapolate.
 * 1 = IPB-style blocking AVAL every FocFastLoop (~100 us).
 *     Requires DMA CH4/5 (and QSPI complete path) ISR priority > AdcIsr. */
#ifndef MOTORCDD_FOC_ANGLE_SPI_IN_FASTLOOP
#define MOTORCDD_FOC_ANGLE_SPI_IN_FASTLOOP   (1U)
#endif

extern MotorFoc_ContextType MotorCdd_FocContext;
extern volatile uint32 MotorCdd_FocLoopCounter;
extern volatile uint32 MotorCdd_AngleSpiFastLoopCount;
extern volatile uint32 MotorCdd_AngleSpiSkipBusyCount;

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
/* Optional 1 ms path when MOTORCDD_FOC_ANGLE_SPI_IN_FASTLOOP==0. */
void MotorCdd_FocServiceAngleSpi1ms(void);
void MotorCdd_FocPrepareOutputEnable(void);
void MotorCdd_FocStopOutput(void);
void MotorCdd_FocClearFault(void);
uint8 MotorCdd_FocHasFault(void);

#endif /* MOTORCDD_FOC_H */
