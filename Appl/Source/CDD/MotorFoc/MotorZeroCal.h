#ifndef MOTORZEROCAL_H
#define MOTORZEROCAL_H

#include "Std_Types.h"

#define MOTORZEROCAL_STORAGE_MAGIC      (0xA5A4U)
#define MOTORZEROCAL_ID_REF_A           (8.0F)
#define MOTORZEROCAL_ANGLE_OK_LOW       (3.0F)
#define MOTORZEROCAL_ANGLE_OK_HIGH      (8190.0F)
/* Former 30000 x ~100 us fast-loop wait ≈ 3 s; now counted in 1 ms MainFunction. */
#define MOTORZEROCAL_DELAY_MS           (3000U)
#define MOTORZEROCAL_MAX_RETRY          (100U)

typedef enum
{
  MOTORZEROCAL_STATE_IDLE = 0U,
  MOTORZEROCAL_STATE_RUNNING = 1U,
  MOTORZEROCAL_STATE_DONE = 2U,
  MOTORZEROCAL_STATE_FAULT = 3U
} MotorZeroCal_StateType;

extern volatile MotorZeroCal_StateType MotorZeroCal_State;
extern volatile uint8 MotorZeroCal_RotorZeroInitialized;
extern volatile uint16 MotorZeroCal_AngBase;
extern volatile uint32 MotorZeroCal_TimerMs;
extern volatile uint8 MotorZeroCal_RetryCount;

void MotorZeroCal_Init(void);
void MotorZeroCal_Start(void);
void MotorZeroCal_Erase(void);
/* Deprecated empty stub — kept for link compatibility; do not put SPI here. */
void MotorZeroCal_FastLoopStep(void);
void MotorZeroCal_MainFunction(void);
uint8 MotorZeroCal_IsRotorZeroInitialized(void);
uint8 MotorZeroCal_UseForcedAngle(void);
float32 MotorZeroCal_GetForcedAngleRad(void);

#endif /* MOTORZEROCAL_H */
