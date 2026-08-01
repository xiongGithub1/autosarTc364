/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  MotorControll.c
 *           Config:  last364.dpa
 *        SW-C Type:  MotorControll
 *
 *        Generator:  MICROSAR RTE Generator Version 4.29.0
 *                    RTE Core Version 1.29.0
 *          License:  CBD2200508
 *
 *      Description:  C-Code implementation template for SW-C <MotorControll>
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/* PRQA S 0857 EOF */ /* MD_MSR_Dir1.1 */
/* PRQA S 0614 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3109 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3112 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2982 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2983 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2880 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3203 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3205 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3206 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3218 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3229 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2002 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3334 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3417 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3426 EOF */ /* MD_Rte_TestCode */

#include "Rte_MotorControll.h"

#include "MotorControll.h"
#include "MotorCdd_Foc.h"
#include "MotorFoc_SpeedLoop.h"
#include "MotorZeroCal.h"
#include "MotorFoc_OpenLoop.h"
#include "CDD/MotorFoc/MotorFoc_OpenLoopCan.h"
#include "CDD/MotorFoc/MotorFoc_CurrentLoop.h"
#include "CDD/MotorFoc/MotorCdd_Adc.h"
#include "CDD/TLE9180/Tle9180_Driver.h"
#include "CDD/TLE5012/Tle5012bd_Driver.h"

#define MOTORCONTROLL_OPENLOOP_CURRENT_LIMIT_A_DEFAULT      (20.0F)
#define MOTORCONTROLL_CAL_VDC_STABLE_MS                     (200U)

static uint16 MotorControll_CalVdcStableMs = 0U;
static uint8 MotorControll_OutputEnabled = 0U;
static MotorMode_Type MotorControll_PrevMotorMode = MOTOR_MODE_DEFAULT;

volatile uint8 MotorControll_OpenLoopEnable = 0U;
volatile uint32 MotorControll_MainCounter = 0U;
volatile uint32 MotorControll_OpenLoopBlockedCounter = 0U;
volatile float32 MotorControll_SensorElectricalAngleRad = 0.0F;
volatile float32 MotorControll_SensorMechanicalRpm = 0.0F;
volatile float32 MotorControll_ForcedElectricalAngleDeg = 0.0F;
volatile float32 MotorControll_RefSpeedRpm = 0.0F;
volatile float32 MotorControll_IdRefCmd = 0.0F;
volatile float32 MotorControll_IqRefCmd = 0.0F;
volatile float32 MotorControll_IdRefOut = 0.0F;
volatile float32 MotorControll_IqRefOut = 0.0F;
volatile float32 MotorControll_OpenLoopCurrentLimitA = MOTORCONTROLL_OPENLOOP_CURRENT_LIMIT_A_DEFAULT;
volatile MotorMode_Type MotorControll_MotorModeCmd = MOTOR_MODE_DEFAULT;
volatile uint8 MotorControll_GateDriverState = 0U;
volatile uint8 MotorControll_GateDriverLastInitError = 0U;
volatile uint8 MotorControll_GateDriverOpModeRaw = 0U;
volatile uint8 MotorControll_GateDriverOutputEnabled = 0U;

static void MotorControll_UpdateFeedbackObservation(void);
static void MotorControll_UpdateGateDriverObservation(void);
static float32 MotorControll_ClampFloat(float32 value, float32 min, float32 max);
static void MotorControll_ComputeCurrentRefs(MotorMode_Type motorMode);
static uint8 MotorControll_TryStartCalibration(void);
static void MotorControll_HandleModeTransition(MotorMode_Type motorMode,
                                               MotorMode_Type* activeMode);
static void MotorControll_ApplyOutputGating(MotorMode_Type motorMode);

#define MotorControll_START_SEC_CODE
#include "MotorControll_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, MotorControll_CODE) MotorControll_Init(void)
{
  MotorControll_OpenLoopEnable = 0U;
  MotorControll_OutputEnabled = 0U;
  MotorCdd_AdcResetCurrentOffsetCapture();
  MotorControll_SensorElectricalAngleRad = 0.0F;
  MotorControll_SensorMechanicalRpm = 0.0F;
  MotorControll_RefSpeedRpm = 0.0F;
  MotorControll_IdRefCmd = 0.0F;
  MotorControll_IqRefCmd = 0.0F;
  MotorControll_IdRefOut = 0.0F;
  MotorControll_IqRefOut = 0.0F;
  MotorControll_OpenLoopCurrentLimitA = MOTORCONTROLL_OPENLOOP_CURRENT_LIMIT_A_DEFAULT;
  MotorControll_ForcedElectricalAngleDeg = 0.0F;
  MotorControll_MotorModeCmd = MOTOR_MODE_DEFAULT;
  MotorControll_PrevMotorMode = MOTOR_MODE_DEFAULT;
  MotorControll_CalVdcStableMs = 0U;
  MotorFoc_OpenLoopCan_Init();

  (void)Rte_Write_Pp_MotorCtrlCmd_MotorMode((uint8)MOTOR_MODE_IDLE);
  (void)Rte_Write_Pp_MotorCurrentRef_Id_Ref(0.0F);
  (void)Rte_Write_Pp_MotorCurrentRef_Iq_Ref(0.0F);
}

void MotorControll_StopPwm(void)
{
  MotorCdd_FocStopOutput();
  Tle9180_Driver_EnableOutput(FALSE);
  MotorControll_OutputEnabled = 0U;
}

uint8 MotorControll_IsCurrentOffsetReady(void)
{
  return MotorCdd_AdcIsCurrentOffsetReady();
}

uint8 MotorControll_IsOutputEnabled(void)
{
  return MotorControll_OutputEnabled;
}

void MotorControll_MainFunction(void)
{
  MotorMode_Type motorMode;

  MotorControll_MainCounter++;

  motorMode = (MotorControll_OpenLoopEnable != 0U) ?
              MOTOR_MODE_OPEN_LOOP : MotorControll_MotorModeCmd;

  MotorControll_UpdateFeedbackObservation();
  MotorControll_UpdateGateDriverObservation();

  if ((motorMode == MOTOR_MODE_IDLE) &&
      (MotorFoc_CurrentLoopFault != 0U) &&
      (MotorFoc_CurrentLoopFaultReason == MOTORFOC_CURRENT_FAULT_UNDERVOLT))
  {
    const MotorCdd_AdcPhysicalType* adcPhysical = MotorCdd_GetAdcPhysical();
    float32 minVdc = MotorFoc_CurrentLoopMinVdcRunV;

    if (minVdc < 0.0F)
    {
      minVdc = 0.0F;
    }

    if (adcPhysical->vinv_V >= (minVdc + 0.5F))
    {
      MotorCdd_FocClearFault();
    }
  }

  MotorControll_HandleModeTransition(motorMode, &motorMode);
  MotorControll_ComputeCurrentRefs(motorMode);

  (void)Rte_Write_Pp_MotorCtrlCmd_MotorMode((uint8)motorMode);
  (void)Rte_Write_Pp_MotorCurrentRef_Id_Ref(MotorControll_IdRefOut);
  (void)Rte_Write_Pp_MotorCurrentRef_Iq_Ref(MotorControll_IqRefOut);

  MotorFoc_OpenLoopCan_MainFunction(motorMode);
  MotorControll_PrevMotorMode = motorMode;
  MotorControll_ApplyOutputGating(motorMode);
}

static void MotorControll_UpdateFeedbackObservation(void)
{
  float32 angleRad = 0.0F;

  (void)Rte_Read_Pp_MotorElectricalAngle_ElectricAngle(&angleRad);
  MotorControll_SensorElectricalAngleRad = angleRad;
  MotorControll_SensorMechanicalRpm = Tle5012bd_Driver_GetMechanicalRpm();
  MotorControll_ForcedElectricalAngleDeg = MotorFoc_OpenLoop_GetForcedAngleDeg();
}

static void MotorControll_UpdateGateDriverObservation(void)
{
  MotorControll_GateDriverState = (uint8)Tle9180_Driver_GetState();
  MotorControll_GateDriverLastInitError = Tle9180_Driver_GetLastInitError();
  MotorControll_GateDriverOpModeRaw = Tle9180_Driver_GetOperationModeRaw();
  MotorControll_GateDriverOutputEnabled = MotorControll_OutputEnabled;
}

static float32 MotorControll_ClampFloat(float32 value, float32 min, float32 max)
{
  if (value > max)
  {
    return max;
  }
  if (value < min)
  {
    return min;
  }
  return value;
}

static uint8 MotorControll_TryStartCalibration(void)
{
  const MotorCdd_AdcPhysicalType* adcPhysical;
  float32 minVdc;

  adcPhysical = MotorCdd_GetAdcPhysical();
  minVdc = MotorFoc_CurrentLoopMinVdcRunV;
  if (minVdc < 0.0F)
  {
    minVdc = 0.0F;
  }

  if (adcPhysical->vinv_V < (minVdc + 1.0F))
  {
    MotorControll_CalVdcStableMs = 0U;
    MotorZeroCal_StartRejectReason = MOTORZEROCAL_START_REJECT_VDC_LOW;
    return 0U;
  }

  if (MotorControll_CalVdcStableMs < MOTORCONTROLL_CAL_VDC_STABLE_MS)
  {
    MotorControll_CalVdcStableMs++;
    MotorZeroCal_StartRejectReason = MOTORZEROCAL_START_REJECT_VDC_STABILIZING;
    return 0U;
  }

  if (MotorZeroCal_CanStart() == 0U)
  {
    return 0U;
  }

  MotorCdd_FocClearFault();
  MotorZeroCal_Start();
  return 1U;
}

static void MotorControll_ComputeCurrentRefs(MotorMode_Type motorMode)
{
  float32 idRef = 0.0F;
  float32 iqRef = 0.0F;

  switch (motorMode)
  {
    case MOTOR_MODE_CALIBRATION:
      idRef = MotorZeroCal_GetAlignCurrentA();
      iqRef = 0.0F;
      break;

    case MOTOR_MODE_CALIBRATION_ERASE:
    case MOTOR_MODE_CALIBRATION_SAVE:
      idRef = 0.0F;
      iqRef = 0.0F;
      break;

    case MOTOR_MODE_OPEN_LOOP:
    {
      float32 currentLimit = MotorControll_OpenLoopCurrentLimitA;
      float32 idTarget;
      float32 iqTarget;

      if (currentLimit < 0.0F)
      {
        currentLimit = -currentLimit;
      }
      idTarget = MotorControll_ClampFloat(MotorControll_IdRefCmd,
                                          -currentLimit,
                                          currentLimit);
      iqTarget = MotorControll_ClampFloat(MotorControll_IqRefCmd,
                                          -currentLimit,
                                          currentLimit);
      /* Fast-loop open-loop state machine performs the only current reference ramp. */
      idRef = idTarget;
      iqRef = iqTarget;
      break;
    }

    case MOTOR_MODE_FOC_SPEED:
      MotorCdd_FocContext.speedControl.refSpeedRPM = MotorControll_RefSpeedRpm;
      MotorFoc_RunSpeedLoop(&MotorCdd_FocContext, MotorControll_SensorMechanicalRpm);
      idRef = 0.0F;
      iqRef = MotorCdd_FocContext.speedControl.RefIq;
      break;

    case MOTOR_MODE_FOC_CURRENT:
      idRef = MotorControll_IdRefCmd;
      iqRef = MotorControll_IqRefCmd;
      break;

    case MOTOR_MODE_STOP:
    case MOTOR_MODE_IDLE:
    default:
      idRef = 0.0F;
      iqRef = 0.0F;
      break;
  }

  MotorControll_IdRefOut = idRef;
  MotorControll_IqRefOut = iqRef;
}

static void MotorControll_HandleModeTransition(MotorMode_Type motorMode,
                                               MotorMode_Type* activeMode)
{
  if (motorMode != MotorControll_PrevMotorMode)
  {
    if (motorMode == MOTOR_MODE_CALIBRATION)
    {
      if (MotorControll_TryStartCalibration() == 0U)
      {
        if (MotorZeroCal_StartRejectReason == MOTORZEROCAL_START_REJECT_VDC_LOW)
        {
          MotorControll_MotorModeCmd = MOTOR_MODE_IDLE;
          *activeMode = MOTOR_MODE_IDLE;
        }
      }
    }
    else if (motorMode == MOTOR_MODE_CALIBRATION_ERASE)
    {
      MotorZeroCal_Erase();
      MotorControll_MotorModeCmd = MOTOR_MODE_IDLE;
      *activeMode = MOTOR_MODE_IDLE;
    }
    else if (motorMode == MOTOR_MODE_CALIBRATION_SAVE)
    {
      MotorControll_StopPwm();
      MotorZeroCal_SaveToFlash();
      MotorControll_MotorModeCmd = MOTOR_MODE_IDLE;
      *activeMode = MOTOR_MODE_IDLE;
    }
    else if (motorMode == MOTOR_MODE_OPEN_LOOP)
    {
      MotorFoc_OpenLoop_Reset();
      MotorCdd_FocClearFault();
      MotorControll_IdRefOut = 0.0F;
      MotorControll_IqRefOut = 0.0F;
    }
    else
    {
      MotorControll_CalVdcStableMs = 0U;
    }
  }
  else if (motorMode == MOTOR_MODE_CALIBRATION)
  {
    if ((MotorZeroCal_State != MOTORZEROCAL_STATE_RUNNING) &&
        (MotorZeroCal_State != MOTORZEROCAL_STATE_SAVING))
    {
      if (MotorControll_TryStartCalibration() == 0U)
      {
        if (MotorZeroCal_StartRejectReason == MOTORZEROCAL_START_REJECT_VDC_LOW)
        {
          MotorControll_MotorModeCmd = MOTOR_MODE_IDLE;
          *activeMode = MOTOR_MODE_IDLE;
        }
      }
    }
  }
  else
  {
    MotorControll_CalVdcStableMs = 0U;
  }
}

static void MotorControll_ApplyOutputGating(MotorMode_Type motorMode)
{
  if ((motorMode == MOTOR_MODE_IDLE) ||
      (motorMode == MOTOR_MODE_STOP) ||
      (motorMode == MOTOR_MODE_CALIBRATION_SAVE) ||
      (MotorZeroCal_State == MOTORZEROCAL_STATE_SAVING))
  {
    if (MotorControll_OutputEnabled != 0U)
    {
      MotorControll_StopPwm();
    }
    return;
  }

  if (Tle9180_Driver_GetState() != TLE9180_DRV_STATE_READY)
  {
    MotorControll_StopPwm();
    MotorControll_OpenLoopBlockedCounter++;
    return;
  }

  /* Do not enable the inverter if the measured DC link is below the run limit.
   * This prevents a deliberate open-loop align command from immediately latching
   * an undervoltage fault after startup blanking expires. */
  if (motorMode == MOTOR_MODE_OPEN_LOOP)
  {
    const MotorCdd_AdcPhysicalType* adcPhysical = MotorCdd_GetAdcPhysical();
    float32 minVdc = MotorFoc_CurrentLoopMinVdcRunV;

    if (minVdc < 0.0F)
    {
      minVdc = 0.0F;
    }
    if (adcPhysical->vinv_V < (minVdc + 1.0F))
    {
      MotorControll_StopPwm();
      MotorControll_OpenLoopBlockedCounter++;
      return;
    }
  }
  if (MotorCdd_FocHasFault() != 0U)
  {
    MotorControll_StopPwm();
    MotorControll_OpenLoopBlockedCounter++;
    return;
  }

  if ((MotorCdd_AdcIsCurrentOffsetReady() != 0U) &&
      (MotorControll_OutputEnabled == 0U))
  {
    MotorCdd_FocPrepareOutputEnable();
    Tle9180_Driver_EnableOutput(TRUE);
    MotorControll_OutputEnabled = 1U;
  }
}

#define MotorControll_STOP_SEC_CODE
#include "MotorControll_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
