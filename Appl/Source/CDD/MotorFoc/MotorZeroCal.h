#ifndef MOTORZEROCAL_H
#define MOTORZEROCAL_H

#include "Std_Types.h"

#define MOTORZEROCAL_STORAGE_MAGIC      (0xA5A4U)
#define MOTORZEROCAL_ID_REF_A           (5.0F)
/* ~0.15 s to 1.5 A when ramped in PWM fast-loop. */
#define MOTORZEROCAL_ID_RAMP_STEP_A     (0.1F)
#define MOTORZEROCAL_ID_REACHED_EPS_A   (0.02F)
#define MOTORZEROCAL_ALIGN_ANGLE_DEG    (0.0F)
#define MOTORZEROCAL_ANGLE_OK_LOW       (3.0F)
#define MOTORZEROCAL_ANGLE_OK_HIGH      (8190.0F)
/* Keep Id at target for 1.5 s before reading the encoder. */
#define MOTORZEROCAL_DELAY_MS           (1500U)
/* Settle after each ANG_BASE retry. */
#define MOTORZEROCAL_RETRY_DELAY_MS     (200U)
#define MOTORZEROCAL_ANG_BASE_APPLY_DELAY_MS (500U)
#define MOTORZEROCAL_MAX_RETRY          (10U)
/* Whole align→RAM procedure must finish within this (Flash is separate). */
#define MOTORZEROCAL_TOTAL_TIMEOUT_MS   (5000U)

#define MOTORZEROCAL_START_REJECT_NONE           (0U)
#define MOTORZEROCAL_START_REJECT_VDC_LOW        (1U)
#define MOTORZEROCAL_START_REJECT_GATE_NOT_READY (2U)
#define MOTORZEROCAL_START_REJECT_ALREADY_RUNNING (3U)
#define MOTORZEROCAL_START_REJECT_VDC_STABILIZING (4U)

#define MOTORZEROCAL_FAULT_NONE     (0U)
#define MOTORZEROCAL_FAULT_CURRENT  (1U)
#define MOTORZEROCAL_FAULT_ALIGN    (2U)
#define MOTORZEROCAL_FAULT_TIMEOUT  (3U)
#define MOTORZEROCAL_FAULT_FLASH    (4U)

/* Zero calibration reads and writes TLE5012 MOD_3.ANG_BASE through SPI. */
#ifndef MOTORZEROCAL_SPI_ENABLE
#define MOTORZEROCAL_SPI_ENABLE     (1U)
#endif

typedef enum
{
  MOTORZEROCAL_STATE_IDLE = 0U,
  MOTORZEROCAL_STATE_RUNNING = 1U,
  MOTORZEROCAL_STATE_SAVING = 2U,
  MOTORZEROCAL_STATE_DONE = 3U,
  MOTORZEROCAL_STATE_FAULT = 4U
} MotorZeroCal_StateType;

extern volatile MotorZeroCal_StateType MotorZeroCal_State;
/* 1 = valid zero point in RAM for motor use. */
extern volatile uint8 MotorZeroCal_Calibrated;
/* Compatibility: same value as MotorZeroCal_Calibrated. */
extern volatile uint8 MotorZeroCal_RotorZeroInitialized;
extern volatile uint16 MotorZeroCal_AngBase;
extern volatile uint32 MotorZeroCal_TimerMs;
extern volatile uint32 MotorZeroCal_ElapsedMs;
extern volatile uint8 MotorZeroCal_RetryCount;
extern volatile float32 MotorZeroCal_IdRefA;
extern volatile float32 MotorZeroCal_IdRefTargetA;
extern volatile float32 MotorZeroCal_IdRefRampStepA;
extern volatile uint8 MotorZeroCal_StartRejectReason;
extern volatile uint8 MotorZeroCal_FaultReason;
extern volatile uint32 MotorZeroCal_AlignWaitMs;
/* 1 = RAM zero changed and not yet written to DFlash. */
extern volatile uint8 MotorZeroCal_NvDirty;
/* UDE optional: set 1 to re-queue NvM write (same as CALIBRATION_SAVE). */
extern volatile uint8 MotorZeroCal_NvSaveRequest;
/* Watch: Op 1=read 2=write; Result 0=OK 1=NOT_OK 2=PENDING. */
extern volatile uint8 MotorZeroCal_NvReadPending;
extern volatile uint8 MotorZeroCal_NvWritePending;
extern volatile uint8 MotorZeroCal_NvLastOp;
extern volatile uint8 MotorZeroCal_NvLastResult;
extern volatile uint8 MotorZeroCal_NvLastApiRet;
extern volatile uint32 MotorZeroCal_NvPendingTicks;

uint8 MotorZeroCal_CanStart(void);
void MotorZeroCal_Init(void);
void MotorZeroCal_Start(void);
void MotorZeroCal_Erase(void);
/* Write current RAM mirror to DFlash (async NvM). Optional re-save / erase persist. */
void MotorZeroCal_SaveToFlash(void);
/* Deprecated empty stub — kept for link compatibility; do not put SPI here. */
void MotorZeroCal_FastLoopStep(void);
void MotorZeroCal_RampAlignCurrentStep(void);
void MotorZeroCal_MainFunction(void);
uint8 MotorZeroCal_IsRotorZeroInitialized(void);
uint8 MotorZeroCal_UseForcedAngle(void);
float32 MotorZeroCal_GetAlignCurrentA(void);
float32 MotorZeroCal_GetForcedAngleRad(void);

#endif /* MOTORZEROCAL_H */
