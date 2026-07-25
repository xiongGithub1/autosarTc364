#include "MotorCdd_Foc.h"
#include "Rte_MotorCdd.h"
#include "MotorMode.h"
#include "MotorControll.h"
#include "MotorCdd_Adc.h"
#include "MotorZeroCal.h"
#include "MotorFoc_OpenLoop.h"
#include "TLE5012/Tle5012bd_Driver.h"
#include "TLE9180/Tle9180_Driver.h"
#include "MotorFoc_CurrentLoop.h"
#include "MotorFoc_SpeedLoop.h"
#include "MotorFoc_SinCosTable.h"

typedef struct
{
  uint8 mode;
  float32 idRef;
  float32 iqRef;
} MotorCdd_CmdMirrorType;

typedef struct
{
  float32 angleDeg;
  float32 angleRad;
  float32 stepRawPerFastLoop;
  uint8 valid;
} MotorCdd_AngleCacheType;

MotorFoc_ContextType MotorCdd_FocContext;
volatile uint32 MotorCdd_FocLoopCounter = 0U;

static volatile MotorCdd_CmdMirrorType MotorCdd_CmdMirror;
static volatile MotorCdd_AngleCacheType MotorCdd_AngleCache;
static float32 MotorCdd_LastSensorElectricalRaw = 0.0F;
static uint8 MotorCdd_LastSensorElectricalRawValid = 0U;

/* Skip SPI for first ~50 ms after FOC init (sensor SSC settle / power-up). */
#define MOTORCDD_FOC_ANGLE_SPI_BOOT_BLANK_LOOPS   (500U)

static uint16 MotorCdd_AngleSpiBootBlankLeft = MOTORCDD_FOC_ANGLE_SPI_BOOT_BLANK_LOOPS;
volatile uint32 MotorCdd_AngleSpiFastLoopCount = 0U;

static void MotorCdd_ConvertMechanicalToElectricalAngle(float32 mechanicalRaw,
                                                         float32* electricalRaw,
                                                         float32* electricalRad)
{
  uint32 mechanicalIndex;
  uint32 polePairs = (uint32)MotorCdd_FocContext.motor.polePairs;
  uint32 electricalIndex;

  if (mechanicalRaw < 0.0F)
  {
    mechanicalIndex = 0U;
  }
  else
  {
    mechanicalIndex = (uint32)mechanicalRaw;
  }

  if (polePairs == 0U)
  {
    polePairs = 1U;
  }

  electricalIndex = (mechanicalIndex * polePairs) & MOTORFOC_SINCOS_IDX_MASK;
  *electricalRaw = (float32)electricalIndex;
  *electricalRad = ((float32)electricalIndex / MOTORFOC_SINCOS_RAD_TO_IDX);
}

void MotorCdd_FocInit(void)
{
  MotorCdd_CmdMirror.mode = (uint8)MOTOR_MODE_IDLE;
  MotorCdd_CmdMirror.idRef = 0.0F;
  MotorCdd_CmdMirror.iqRef = 0.0F;
  MotorCdd_AngleCache.angleDeg = 0.0F;
  MotorCdd_AngleCache.angleRad = 0.0F;
  MotorCdd_AngleCache.stepRawPerFastLoop = 0.0F;
  MotorCdd_AngleCache.valid = 0U;
  MotorCdd_LastSensorElectricalRaw = 0.0F;
  MotorCdd_LastSensorElectricalRawValid = 0U;
  MotorCdd_AngleSpiBootBlankLeft = MOTORCDD_FOC_ANGLE_SPI_BOOT_BLANK_LOOPS;
  MotorCdd_AngleSpiFastLoopCount = 0U;

  MotorFoc_CurrentLoopInit(&MotorCdd_FocContext);
  MotorFoc_SpeedLoopInit(&MotorCdd_FocContext);
  MotorFoc_OpenLoop_Init();
  MotorZeroCal_Init();
}

void MotorCdd_FocSetCmdMirror(uint8 motorMode, float32 idRef, float32 iqRef)
{
  MotorCdd_CmdMirror.mode = motorMode;
  MotorCdd_CmdMirror.idRef = idRef;
  MotorCdd_CmdMirror.iqRef = iqRef;
}

void MotorCdd_FocUpdateCmdMirror(void)
{
  uint8 motorMode = (uint8)MOTOR_MODE_IDLE;
  float32 idRef = 0.0F;
  float32 iqRef = 0.0F;

  (void)Rte_Read_Pp_MotorCtrlCmd_MotorMode(&motorMode);
  (void)Rte_Read_Pp_MotorCurrentRef_Id_Ref(&idRef);
  (void)Rte_Read_Pp_MotorCurrentRef_Iq_Ref(&iqRef);
  MotorCdd_FocSetCmdMirror(motorMode, idRef, iqRef);
}

void MotorCdd_FocPublishAngleCache(float32 angleDeg, float32 angleRad)
{
  MotorCdd_AngleCache.angleDeg = angleDeg;
  MotorCdd_AngleCache.angleRad = angleRad;
  MotorCdd_AngleCache.valid = 1U;
}

void MotorCdd_FocUpdateAngleCacheFromSensor(void)
{
  float32 electricalRaw;
  float32 electricalRad;
  float32 deltaRaw = 0.0F;

  /* Sensor.Angle filled by tle5012b_read_angle (blocking SPI in FocFastLoop). */
  MotorCdd_ConvertMechanicalToElectricalAngle(Tle5012bd_Sensor.Angle,
                                               &electricalRaw,
                                               &electricalRad);

  if (MotorCdd_LastSensorElectricalRawValid != 0U)
  {
    deltaRaw = electricalRaw - MotorCdd_LastSensorElectricalRaw;
    if (deltaRaw > ((float32)MOTORFOC_SINCOS_TABLE_SIZE * 0.5F))
    {
      deltaRaw -= (float32)MOTORFOC_SINCOS_TABLE_SIZE;
    }
    else if (deltaRaw < (-((float32)MOTORFOC_SINCOS_TABLE_SIZE * 0.5F)))
    {
      deltaRaw += (float32)MOTORFOC_SINCOS_TABLE_SIZE;
    }
  }

  MotorCdd_LastSensorElectricalRaw = electricalRaw;
  MotorCdd_LastSensorElectricalRawValid = 1U;
  (void)deltaRaw;
  MotorCdd_AngleCache.stepRawPerFastLoop = 0.0F;
  MotorCdd_FocPublishAngleCache(electricalRaw, electricalRad);
}

static uint8 MotorCdd_FocAngleSpiAllowedInFastLoop(uint8 motorMode)
{
  /* ZeroCal / open-loop use forced angle or own SPI in StartApp ??avoid QSPI2 clash. */
  if ((motorMode == (uint8)MOTOR_MODE_CALIBRATION) ||
      (motorMode == (uint8)MOTOR_MODE_CALIBRATION_ERASE) ||
      (motorMode == (uint8)MOTOR_MODE_CALIBRATION_SAVE) ||
      (motorMode == (uint8)MOTOR_MODE_OPEN_LOOP))
  {
    return 0U;
  }
  return 1U;
}

/*
 * IPB-style: blocking AVAL read in fast loop (SpiExchangeU32 spin-wait).
 * Requires DMA CH4/5 prio > AdcIsr.
 */
static void MotorCdd_FocServiceAngleSpi(void)
{
  uint8 motorMode = MotorCdd_CmdMirror.mode;

  if (MotorCdd_AngleSpiBootBlankLeft > 0U)
  {
    MotorCdd_AngleSpiBootBlankLeft--;
    return;
  }

  if (Tle5012bd_Driver_GetState() != TLE5012BD_STATE_READY)
  {
    return;
  }

  /* ZeroCal / open-loop use forced angle ??skip 5012 SPI. */
  if (MotorCdd_FocAngleSpiAllowedInFastLoop(motorMode) == 0U)
  {
    return;
  }

  if (Tle5012bd_Driver_ReadAngle(&Tle5012bd_Sensor) == E_OK)
  {
    MotorCdd_FocUpdateAngleCacheFromSensor();
    MotorCdd_AngleSpiFastLoopCount++;
  }
}

void MotorCdd_FocPrepareOutputEnable(void)
{
  MotorFoc_CurrentLoopPreparePwmNeutral(&MotorCdd_FocContext);
  MotorCdd_AdcSynchronizePwmTriggerCounter();
  MotorFoc_CurrentLoopClearFault();
  MotorFoc_CurrentLoopArmStartupBlanking();
}

void MotorCdd_FocStopOutput(void)
{
  MotorFoc_CurrentLoopStop(&MotorCdd_FocContext);
}

void MotorCdd_FocClearFault(void)
{
  MotorFoc_CurrentLoopClearFault();
}

uint8 MotorCdd_FocHasFault(void)
{
  return MotorFoc_CurrentLoopFault;
}

static void MotorCdd_ApplyAngleCache(uint8 useForcedAngle, float32 forcedAngleRad)
{
  if (useForcedAngle != 0U)
  {
    /* Map forced rad ??8192-count index for sin/cos table (open-loop / zero-cal). */
    sint32 sidx = (sint32)(forcedAngleRad * MOTORFOC_SINCOS_RAD_TO_IDX);
    float32 angleRaw = (float32)((uint32)sidx & MOTORFOC_SINCOS_IDX_MASK);

    MotorFoc_SetAngleFromTle5012(&MotorCdd_FocContext, angleRaw, forcedAngleRad);
  }
  else if (MotorCdd_AngleCache.valid != 0U)
  {
    /* Cache carries the electrical 8192-count angle generated from the encoder. */
    MotorFoc_SetAngleFromTle5012(&MotorCdd_FocContext,
                                 MotorCdd_AngleCache.angleDeg,
                                 MotorCdd_AngleCache.angleRad);
  }
  else
  {
    /* Keep previous FOC angle until 1 ms path publishes the first sample. */
  }
}

static void MotorCdd_RunFocCurrentControl(float32 idRef,
                                          float32 iqRef,
                                          uint8 useForcedAngle,
                                          float32 forcedAngleRad)
{
  const MotorCdd_AdcPhysicalType* adcPhysical;

  if (Tle9180_Driver_GetState() != TLE9180_DRV_STATE_READY)
  {
    return;
  }

  if (MotorCdd_AdcIsCurrentOffsetReady() == 0U)
  {
    MotorCdd_AdcAccumulateCurrentOffset();
    return;
  }

  if (MotorControll_IsOutputEnabled() == 0U)
  {
    return;
  }

  /* Closed-loop torque is forbidden without a validated encoder frame. */
  if ((useForcedAngle == 0U) && (Tle5012bd_AngleValid == 0U))
  {
    MotorCdd_FocStopOutput();
    return;
  }

  adcPhysical = MotorCdd_GetAdcPhysical();
  MotorFoc_SetIdRef(&MotorCdd_FocContext, idRef);
  MotorFoc_SetIqRef(&MotorCdd_FocContext, iqRef);
  MotorCdd_ApplyAngleCache(useForcedAngle, forcedAngleRad);

  MotorFoc_UpdateCurrentFromAdc(&MotorCdd_FocContext,
                                adcPhysical->iu_A,
                                adcPhysical->iv_A,
                                adcPhysical->iw_A,
                                adcPhysical->vinv_V);
  MotorFoc_UpdateRawCurrentForProtection(adcPhysical->iuRaw_A,
                                          adcPhysical->ivRaw_A,
                                          adcPhysical->iwRaw_A);
  MotorFoc_RunCurrentLoop(&MotorCdd_FocContext);
}

void MotorCdd_FocFastLoop(void)
{
  MotorMode_Type motorMode;
  float32 idRef;
  float32 iqRef;

  MotorCdd_FocLoopCounter++;

  motorMode = (MotorMode_Type)MotorCdd_CmdMirror.mode;
  idRef = MotorCdd_CmdMirror.idRef;
  iqRef = MotorCdd_CmdMirror.iqRef;

  switch (motorMode)
  {
    case MOTOR_MODE_CALIBRATION:
      MotorZeroCal_FastLoopStep();
      MotorFoc_OpenLoop_UpdateControlStage();
      if ((Tle9180_Driver_GetState() == TLE9180_DRV_STATE_READY) &&
          (MotorCdd_AdcIsCurrentOffsetReady() != 0U) &&
          (MotorControll_IsOutputEnabled() != 0U) &&
          (MotorFoc_CurrentLoopFault == 0U))
      {
        MotorZeroCal_RampAlignCurrentStep();
      }
      MotorCdd_RunFocCurrentControl(MotorZeroCal_GetAlignCurrentA(),
                                    0.0F,
                                    1U,
                                    MotorZeroCal_GetForcedAngleRad());
      break;

    case MOTOR_MODE_OPEN_LOOP:
      MotorFoc_OpenLoop_FastLoopStep();
      MotorFoc_OpenLoop_UpdateControlStage();
      MotorCdd_RunFocCurrentControl(idRef,
                                    iqRef,
                                    1U,
                                    MotorFoc_OpenLoop_GetForcedAngleRad());
      break;

    case MOTOR_MODE_FOC_SPEED:
    case MOTOR_MODE_FOC_CURRENT:
#if (MOTORCDD_FOC_ANGLE_SPI_IN_FASTLOOP == 1U)
      MotorCdd_FocServiceAngleSpi();
#endif
      MotorCdd_RunFocCurrentControl(idRef, iqRef, 0U, 0.0F);
      break;

    case MOTOR_MODE_STOP:
      MotorCdd_FocStopOutput();
      break;

    case MOTOR_MODE_CALIBRATION_ERASE:
    case MOTOR_MODE_CALIBRATION_SAVE:
    case MOTOR_MODE_IDLE:
    default:
      if (MotorCdd_AdcIsCurrentOffsetReady() == 0U)
      {
        /* Offset capture needs fast-loop samples but no PWM output. */
        MotorCdd_RunFocCurrentControl(0.0F, 0.0F, 0U, 0.0F);
      }
      break;
  }
}

