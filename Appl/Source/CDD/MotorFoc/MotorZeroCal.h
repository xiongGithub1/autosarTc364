#ifndef MOTORZEROCAL_H
#define MOTORZEROCAL_H

#include "Std_Types.h"

#define MOTORZEROCAL_STORAGE_MAGIC      (0xA5A4U)
/* 0.002 A per 10 kHz fast-loop tick: 1 A is reached in about 50 ms. */
#define MOTORZEROCAL_ID_RAMP_STEP_A     (0.002F)
#define MOTORZEROCAL_ID_REACHED_EPS_A   (0.02F)
#define MOTORZEROCAL_ALIGN_ANGLE_DEG    (0.0F)
/* 判定容差（Angle 现为电角度 v%8192，8192 计数 = 360° 电角度）：
   ±1° 电角度 ≈ ±23 计数。此前沿用机械角时代的 ±3 计数（= ±0.13° 电角度），
   对齐抖动/传感器噪声很容易超过导致 FAULT_ALIGN。 */
#define MOTORZEROCAL_ANGLE_OK_LOW       (5.0F)
#define MOTORZEROCAL_ANGLE_OK_HIGH      (8186.0F)
/* Keep Id at target for 1.5 s before reading the encoder. */
#define MOTORZEROCAL_DELAY_MS           (1500U)
/* Settle after each ANG_BASE retry. */
#define MOTORZEROCAL_RETRY_DELAY_MS     (300U)
#define MOTORZEROCAL_ANG_BASE_APPLY_DELAY_MS (500U)
/* 判定容差为 ±1° 电角度，转子抖动/噪声可能让单帧读数偶尔超差，
   重试次数太少容易 FAULT_ALIGN。 */
#define MOTORZEROCAL_MAX_RETRY          (30U)
/* Whole align→RAM procedure must finish within this (Flash is separate).
   1.5 s 首次对齐 + 29 次 × 0.3 s ≈ 10.2 s，留足余量。 */
#define MOTORZEROCAL_TOTAL_TIMEOUT_MS   (20000U)

#define MOTORZEROCAL_START_REJECT_NONE           (0U)
#define MOTORZEROCAL_START_REJECT_VDC_LOW        (1U)
#define MOTORZEROCAL_START_REJECT_GATE_NOT_READY (2U)
#define MOTORZEROCAL_START_REJECT_ALREADY_RUNNING (3U)
#define MOTORZEROCAL_START_REJECT_VDC_STABILIZING (4U)
#define MOTORZEROCAL_START_REJECT_NVM_NOT_READY  (5U)

#define MOTORZEROCAL_FAULT_NONE     (0U)
#define MOTORZEROCAL_FAULT_CURRENT  (1U)
#define MOTORZEROCAL_FAULT_ALIGN    (2U)
#define MOTORZEROCAL_FAULT_TIMEOUT  (3U)
#define MOTORZEROCAL_FAULT_FLASH    (4U)

/* Zero calibration reads and writes TLE5012 MOD_3.ANG_BASE through SPI. */
#ifndef MOTORZEROCAL_SPI_ENABLE
#define MOTORZEROCAL_SPI_ENABLE     (1U)
#endif

/* 1ms 标定写 ANG_BASE 期间置 1；10 kHz 快速环检测到后跳过该拍 SPI 读取。 */
extern volatile uint8 MotorZeroCal_SpiBusy;

typedef enum
{
  MOTORZEROCAL_STATE_IDLE = 0U,
  MOTORZEROCAL_STATE_RUNNING = 1U,
  MOTORZEROCAL_STATE_SAVING = 2U,
  MOTORZEROCAL_STATE_DONE = 3U,
  MOTORZEROCAL_STATE_FAULT = 4U
} MotorZeroCal_StateType;

/* Fine-grained calibration progress. This is the primary UDE observation item. */
typedef enum
{
  MOTORZEROCAL_STAGE_IDLE = 0U,
  MOTORZEROCAL_STAGE_ALIGN_RAMP = 1U,
  MOTORZEROCAL_STAGE_ALIGN_HOLD = 2U,
  MOTORZEROCAL_STAGE_READ_ANGLE = 3U,
  MOTORZEROCAL_STAGE_APPLY_OFFSET = 4U,
  MOTORZEROCAL_STAGE_SAVE_DFLASH = 5U,
  MOTORZEROCAL_STAGE_COMPLETE = 6U,
  MOTORZEROCAL_STAGE_FAULT = 7U
} MotorZeroCal_StageType;

extern volatile MotorZeroCal_StateType MotorZeroCal_State;
extern volatile MotorZeroCal_StageType MotorZeroCal_Stage;
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
/* Valid marker read from the 4-byte NvM/Fee record. */
extern volatile uint8 MotorZeroCal_DflashValid;
/* 1 once boot NvM read is complete; safe point to decide whether to calibrate. */
extern volatile uint8 MotorZeroCal_DflashReadComplete;
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
uint8 MotorZeroCal_IsCalibrationRequired(void);
uint8 MotorZeroCal_UseForcedAngle(void);
float32 MotorZeroCal_GetAlignCurrentA(void);
float32 MotorZeroCal_GetForcedAngleRad(void);

#endif /* MOTORZEROCAL_H */
