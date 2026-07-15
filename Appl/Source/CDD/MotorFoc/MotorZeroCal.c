#include "MotorZeroCal.h"
#include "MotorMode.h"
#include "CDD/TLE5012/Tle5012bd_Driver.h"
#include "CDD/TLE5012/TLE5012/tle5012b.h"
#include "McalLib.h"

typedef struct
{
  uint16 magic;
  uint16 angBase;
} MotorZeroCal_StorageType;

static MotorZeroCal_StorageType MotorZeroCal_Storage;

extern volatile MotorMode_Type MotorControll_MotorModeCmd;

volatile MotorZeroCal_StateType MotorZeroCal_State = MOTORZEROCAL_STATE_IDLE;
volatile uint8 MotorZeroCal_RotorZeroInitialized = 0U;
volatile uint16 MotorZeroCal_AngBase = 0U;
volatile uint32 MotorZeroCal_TimerMs = 0U;
volatile uint8 MotorZeroCal_RetryCount = 0U;

static void MotorZeroCal_DelayUs(uint32 delayUs)
{
  uint32 resolution = Mcal_DelayTickResolution();

  if (resolution == 0U)
  {
    resolution = Mcal_DelayResetTickCalibration();
  }

  if (resolution == 0U)
  {
    volatile uint32 i;

    for (i = 0U; i < (delayUs * 200U); i++)
    {
      /* fallback */
    }
  }
  else
  {
    const uint32 startTick = Mcal_DelayGetTick();
    /* Resolution is ns/tick → ticks = (µs * 1000) / ns */
    const uint32 targetTicks = (delayUs * 1000UL) / resolution;

    while ((Mcal_DelayGetTick() - startTick) < targetTicks)
    {
      /* wait */
    }
  }
}

static void MotorZeroCal_ApplyAngBase(uint16 angBase)
{
  Tle5012bd_Sensor.ANG_BASE = angBase;
  tle5012b_write_fast(MOD_3, angBase);
  MotorZeroCal_DelayUs(150U);
  tle5012b_read_all();
}

static void MotorZeroCal_LoadFromStorage(void)
{
  (void)tle5012b_ChangeAngleDirection(counterclockwise);

  if (MotorZeroCal_Storage.magic == MOTORZEROCAL_STORAGE_MAGIC)
  {
    MotorZeroCal_RotorZeroInitialized = 1U;
    MotorZeroCal_AngBase = MotorZeroCal_Storage.angBase;
    MotorZeroCal_ApplyAngBase(MotorZeroCal_AngBase);
  }
  else
  {
    MotorZeroCal_RotorZeroInitialized = 0U;
    MotorZeroCal_AngBase = 0U;
    Tle5012bd_Sensor.ANG_BASE = 0U;
    tle5012b_read_all();
  }
}

static void MotorZeroCal_SaveToStorage(void)
{
  MotorZeroCal_Storage.magic = MOTORZEROCAL_STORAGE_MAGIC;
  MotorZeroCal_Storage.angBase = MotorZeroCal_AngBase;
}

static void MotorZeroCal_ChangeAngleBasicFromAval(void)
{
  uint16 angleBasic;

  tle5012b_read_angle(&Tle5012bd_Sensor);
  angleBasic = (uint16)Tle5012bd_Sensor.Original_Angle;
  tle5012b_ChangeAngleBasic(&Tle5012bd_Sensor, angleBasic);
}

static void MotorZeroCal_RunCalibrationStep(void)
{
  float32 angle;

  if (MotorZeroCal_State != MOTORZEROCAL_STATE_RUNNING)
  {
    return;
  }

  if (MotorZeroCal_RotorZeroInitialized == 0U)
  {
    MotorZeroCal_TimerMs++;

    if (MotorZeroCal_TimerMs > MOTORZEROCAL_DELAY_MS)
    {
      tle5012b_read_angle(&Tle5012bd_Sensor);
      angle = Tle5012bd_Sensor.Angle;

      if ((angle < MOTORZEROCAL_ANGLE_OK_LOW) ||
          (angle > MOTORZEROCAL_ANGLE_OK_HIGH))
      {
        MotorZeroCal_RotorZeroInitialized = 1U;
      }
      else
      {
        MotorZeroCal_ChangeAngleBasicFromAval();
        MotorZeroCal_RetryCount++;

        if (MotorZeroCal_RetryCount > MOTORZEROCAL_MAX_RETRY)
        {
          MotorZeroCal_RetryCount = 0U;
          MotorZeroCal_State = MOTORZEROCAL_STATE_FAULT;
        }
      }
    }
  }

  if (MotorZeroCal_RotorZeroInitialized != 0U)
  {
    MotorZeroCal_AngBase = Tle5012bd_Sensor.ANG_BASE;
    MotorZeroCal_SaveToStorage();
    MotorZeroCal_State = MOTORZEROCAL_STATE_DONE;
    MotorZeroCal_TimerMs = 0U;
    MotorZeroCal_RetryCount = 0U;
  }
}

void MotorZeroCal_Init(void)
{
  MotorZeroCal_State = MOTORZEROCAL_STATE_IDLE;
  MotorZeroCal_TimerMs = 0U;
  MotorZeroCal_RetryCount = 0U;
  MotorZeroCal_LoadFromStorage();
}

void MotorZeroCal_Start(void)
{
  MotorZeroCal_RotorZeroInitialized = 0U;
  MotorZeroCal_TimerMs = 0U;
  MotorZeroCal_RetryCount = 0U;
  MotorZeroCal_State = MOTORZEROCAL_STATE_RUNNING;
}

void MotorZeroCal_Erase(void)
{
  MotorZeroCal_Storage.magic = 0U;
  MotorZeroCal_Storage.angBase = 0U;
  MotorZeroCal_RotorZeroInitialized = 0U;
  MotorZeroCal_AngBase = 0U;
  Tle5012bd_Sensor.ANG_BASE = 0U;
  MotorZeroCal_State = MOTORZEROCAL_STATE_IDLE;
  MotorZeroCal_TimerMs = 0U;
  MotorZeroCal_RetryCount = 0U;
}

uint8 MotorZeroCal_IsRotorZeroInitialized(void)
{
  return MotorZeroCal_RotorZeroInitialized;
}

uint8 MotorZeroCal_UseForcedAngle(void)
{
  if (MotorZeroCal_State == MOTORZEROCAL_STATE_RUNNING)
  {
    return 1U;
  }

  return 0U;
}

float32 MotorZeroCal_GetForcedAngleRad(void)
{
  return 0.0F;
}

void MotorZeroCal_FastLoopStep(void)
{
  /* Intentionally empty: calibration SPI/state runs in MotorZeroCal_MainFunction. */
}

void MotorZeroCal_MainFunction(void)
{
  if (MotorZeroCal_State == MOTORZEROCAL_STATE_RUNNING)
  {
    MotorZeroCal_RunCalibrationStep();
  }

  if (MotorZeroCal_State == MOTORZEROCAL_STATE_DONE)
  {
    MotorControll_MotorModeCmd = MOTOR_MODE_STOP;
    MotorZeroCal_State = MOTORZEROCAL_STATE_IDLE;
  }
  else if (MotorZeroCal_State == MOTORZEROCAL_STATE_FAULT)
  {
    MotorControll_MotorModeCmd = MOTOR_MODE_IDLE;
    MotorZeroCal_State = MOTORZEROCAL_STATE_IDLE;
  }
  else
  {
    /* No action */
  }
}
