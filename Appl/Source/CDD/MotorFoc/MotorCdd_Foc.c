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
  uint8 valid;
} MotorCdd_AngleCacheType;

MotorFoc_ContextType MotorCdd_FocContext;
volatile uint32 MotorCdd_FocLoopCounter = 0U;

static volatile MotorCdd_CmdMirrorType MotorCdd_CmdMirror;
static volatile MotorCdd_AngleCacheType MotorCdd_AngleCache;

void MotorCdd_FocInit(void)
{
  MotorCdd_CmdMirror.mode = (uint8)MOTOR_MODE_IDLE;
  MotorCdd_CmdMirror.idRef = 0.0F;
  MotorCdd_CmdMirror.iqRef = 0.0F;
  MotorCdd_AngleCache.angleDeg = 0.0F;
  MotorCdd_AngleCache.angleRad = 0.0F;
  MotorCdd_AngleCache.valid = 0U;

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
  Tle5012bd_Driver_ReadAngle(&Tle5012bd_Sensor);
  MotorCdd_FocPublishAngleCache(Tle5012bd_Sensor.Angle, Tle5012bd_Sensor.anglePi);
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
    /* Map forced rad → 8192-count index for sin/cos table (open-loop / zero-cal). */
    sint32 sidx = (sint32)(forcedAngleRad * MOTORFOC_SINCOS_RAD_TO_IDX);
    float32 angleRaw = (float32)((uint32)sidx & MOTORFOC_SINCOS_IDX_MASK);

    MotorFoc_SetAngleFromTle5012(&MotorCdd_FocContext, angleRaw, forcedAngleRad);
  }
  else if (MotorCdd_AngleCache.valid != 0U)
  {
    /* angleDeg field carries TLE5012 Angle counts (0..8191), not degrees. */
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
      MotorCdd_RunFocCurrentControl(MOTORZEROCAL_ID_REF_A,
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
      MotorCdd_RunFocCurrentControl(idRef, iqRef, 0U, 0.0F);
      break;

    case MOTOR_MODE_STOP:
      MotorCdd_RunFocCurrentControl(0.0F, 0.0F, 0U, 0.0F);
      break;

    case MOTOR_MODE_CALIBRATION_ERASE:
    case MOTOR_MODE_IDLE:
    default:
      break;
  }
}
