#ifndef MOTORFOC_OPENLOOP_H
#define MOTORFOC_OPENLOOP_H

#include "Std_Types.h"

/* One electrical revolution is represented by 8192 sin/cos-table samples. */
#define MOTORFOC_OL_ANGLE_RAW_MAX       (8191U)
#define MOTORFOC_OL_ANGLE_RAW_TO_RAD    (7.669903939428206e-4F)

/*
 * Current-controlled open-loop startup sequence:
 * ALIGN_RAMP -> ALIGN_HOLD -> RAMP -> RUN.
 * The current PI loops remain active in every stage; only electrical angle is forced.
 */
typedef enum
{
  MOTORFOC_OPENLOOP_STAGE_ALIGN_RAMP = 0U,
  MOTORFOC_OPENLOOP_STAGE_ALIGN_HOLD = 1U,
  MOTORFOC_OPENLOOP_STAGE_RAMP       = 2U,
  MOTORFOC_OPENLOOP_STAGE_RUN        = 3U
} MotorFoc_OpenLoopStageType;

/* UDE-tunable parameters. Time values are PWM fast-loop ticks. */
extern volatile uint8 MotorFoc_OpenLoop_Direction;
extern volatile uint16 MotorFoc_OpenLoop_TargetAngleStep;
extern volatile uint16 MotorFoc_OpenLoop_StepDivider;
extern volatile uint16 MotorFoc_OpenLoop_AlignHoldTicks;
extern volatile uint16 MotorFoc_OpenLoop_AccelerationTicks;
extern volatile float32 MotorFoc_OpenLoop_AlignAngleDeg;
extern volatile float32 MotorFoc_OpenLoop_AlignCurrentA;
extern volatile float32 MotorFoc_OpenLoop_CurrentRampStepA;
/* UDE 直接写目标机械转速 (rpm)；内部换算 TargetAngleStep。 */
extern volatile float32 MotorFoc_OpenLoop_TargetRpmCmd;

/* UDE observation variables. Do not modify them while PWM is enabled. */
extern volatile MotorFoc_OpenLoopStageType MotorFoc_OpenLoop_Stage;
extern volatile uint32 MotorFoc_OpenLoop_StageCounter;
extern volatile uint16 MotorFoc_OpenLoop_AngleRaw;
extern volatile uint16 MotorFoc_OpenLoop_ActiveAngleStep;
extern volatile float32 MotorFoc_OpenLoop_ForcedAngleRad;
extern volatile float32 MotorFoc_OpenLoop_IdRefOut;
extern volatile float32 MotorFoc_OpenLoop_IqRefOut;
/* 由 ActiveAngleStep 推算的当前开环机械转速 (rpm)。 */
extern volatile float32 MotorFoc_OpenLoop_EstRpm;

void MotorFoc_OpenLoop_Init(void);
void MotorFoc_OpenLoop_Reset(void);
void MotorFoc_OpenLoop_FastLoopStep(float32 idRequestA, float32 iqRequestA);
float32 MotorFoc_OpenLoop_GetForcedAngleRad(void);
float32 MotorFoc_OpenLoop_GetForcedAngleDeg(void);
float32 MotorFoc_OpenLoop_GetIdRefA(void);
float32 MotorFoc_OpenLoop_GetIqRefA(void);

#endif /* MOTORFOC_OPENLOOP_H */
