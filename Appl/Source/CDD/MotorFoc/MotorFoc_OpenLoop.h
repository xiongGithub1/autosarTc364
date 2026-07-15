#ifndef MOTORFOC_OPENLOOP_H
#define MOTORFOC_OPENLOOP_H

#include "Std_Types.h"

#define MOTORFOC_OL_ANGLE_RAW_MAX            (8191U)
#define MOTORFOC_OL_ANGLE_RAW_TO_RAD         (7.66429044544767e-4F)
#define MOTORFOC_OL_DEFAULT_ANGLE_STEP       (1U)
#define MOTORFOC_OL_DEFAULT_STEP_DIVIDER     (1U)

#define MOTORFOC_OPENLOOP_CONTROL_VOLTAGE    (0U)
#define MOTORFOC_OPENLOOP_CONTROL_CURRENT    (1U)
#define MOTORFOC_OPENLOOP_CONTROL_AUTO       (2U)

extern volatile uint8 MotorFoc_OpenLoop_RampEnable;
extern volatile uint8 MotorFoc_OpenLoop_ControlMode;
extern volatile uint8 MotorFoc_OpenLoop_ActiveControlMode;
extern volatile uint8 MotorFoc_OpenLoop_Direction;
extern volatile uint16 MotorFoc_OpenLoop_AngleStep;
extern volatile uint16 MotorFoc_OpenLoop_StepDivider;
extern volatile uint32 MotorFoc_OpenLoop_StageCounter;
extern volatile uint32 MotorFoc_OpenLoop_VoltageToCurrentTicks;
extern volatile uint16 MotorFoc_OpenLoop_AngleRaw;
extern volatile float32 MotorFoc_OpenLoop_ForcedAngleRad;
extern volatile float32 MotorFoc_OpenLoop_FixedAngleDeg;
extern volatile float32 MotorFoc_OpenLoop_VdRefCmd;
extern volatile float32 MotorFoc_OpenLoop_VqRefCmd;
extern volatile float32 MotorFoc_OpenLoop_VdRefOut;
extern volatile float32 MotorFoc_OpenLoop_VqRefOut;
extern volatile float32 MotorFoc_OpenLoop_VoltageLimitV;
extern volatile float32 MotorFoc_OpenLoop_VoltageRampV;

void MotorFoc_OpenLoop_Init(void);
void MotorFoc_OpenLoop_Reset(void);
void MotorFoc_OpenLoop_FastLoopStep(void);
void MotorFoc_OpenLoop_UpdateControlStage(void);
void MotorFoc_OpenLoop_UpdateVoltageRefs(void);
uint8 MotorFoc_OpenLoop_GetActiveControlMode(void);
float32 MotorFoc_OpenLoop_GetForcedAngleRad(void);
float32 MotorFoc_OpenLoop_GetForcedAngleDeg(void);

#endif /* MOTORFOC_OPENLOOP_H */
