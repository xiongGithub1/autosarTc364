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


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
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


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_MotorControll.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "MotorControll.h"
#include "MotorCdd_Foc.h"
#include "MotorFoc_SpeedLoop.h"
#include "MotorZeroCal.h"
#include "MotorFoc_OpenLoop.h"
#include "Appl_BringupCfg.h"

#include "CDD/TLE9180/Tle9180_Driver.h"
#include "CDD/MotorFoc/MotorCdd_Adc.h"
#include "CDD/TLE5012/Tle5012bd_Driver.h"

#define MOTORCONTROLL_OPENLOOP_CURRENT_LIMIT_A_DEFAULT   (20.0F)

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

static uint8 MotorControll_OutputEnabled = 0U;
static MotorMode_Type MotorControll_PrevMotorMode = MOTOR_MODE_DEFAULT;

static void MotorControll_UpdateSensorObservation(void);
static float32 MotorControll_ClampFloat(float32 value, float32 min, float32 max);
static void MotorControll_UpdateCurrentRefsViaRte(MotorMode_Type motorMode);
static void MotorControll_UpdateGateDriverObservation(void);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 *********************************************************************************************************************/


#define MotorControll_START_SEC_CODE
#include "MotorControll_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotorControll_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotorControll_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MotorControll_CODE) MotorControll_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotorControll_Init
 *********************************************************************************************************************/
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

  (void)Rte_Write_Pp_MotorCtrlCmd_MotorMode((uint8)MOTOR_MODE_DEFAULT);
  (void)Rte_Write_Pp_MotorCurrentRef_Id_Ref(0.0F);
  (void)Rte_Write_Pp_MotorCurrentRef_Iq_Ref(0.0F);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define MotorControll_STOP_SEC_CODE
#include "MotorControll_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#define MotorControll_START_SEC_CODE
#include "MotorControll_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

void MotorControll_StopPwm(void)
{
  MotorCdd_FocStopOutput();
  Tle9180_Driver_EnableOutput(FALSE);
  MotorControll_OutputEnabled = 0U;
  MotorCdd_AdcResetCurrentOffsetCapture();
}

static void MotorControll_UpdateSensorObservation(void)
{
  /* One Sync SPI only: read_angle already derives speed/RPM (no second ASPD xfer). */
  Tle5012bd_Driver_ReadAngle(&Tle5012bd_Sensor);
  MotorControll_SensorElectricalAngleRad = Tle5012bd_Sensor.anglePi;
  MotorControll_SensorMechanicalRpm = Tle5012bd_Sensor.RPM;
  /* Fast loop uses this cache only — no SPI on the ADC path. */
  MotorCdd_FocPublishAngleCache(Tle5012bd_Sensor.Angle, Tle5012bd_Sensor.anglePi);
  MotorControll_ForcedElectricalAngleDeg = MotorFoc_OpenLoop_GetForcedAngleDeg();
}

static void MotorControll_UpdateGateDriverObservation(void)
{
  /* Gate-driver SPI poll at 10 ms — not every Motortask Controll cycle. */
  if ((MotorControll_MainCounter % 10U) == 0U)
  {
    (void)Tle9180_Driver_ReadOperationMode();
  }
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

static void MotorControll_UpdateCurrentRefsViaRte(MotorMode_Type motorMode)
{
  float32 idRef = 0.0F;
  float32 iqRef = 0.0F;
  float32 currentLimit;

  switch (motorMode)
  {
    case MOTOR_MODE_CALIBRATION:
      idRef = MOTORZEROCAL_ID_REF_A;
      iqRef = 0.0F;
      break;

    case MOTOR_MODE_CALIBRATION_ERASE:
      idRef = 0.0F;
      iqRef = 0.0F;
      break;

    case MOTOR_MODE_OPEN_LOOP:
      currentLimit = MotorControll_OpenLoopCurrentLimitA;
      if (currentLimit < 0.0F)
      {
        currentLimit = -currentLimit;
      }
      idRef = MotorControll_ClampFloat(MotorControll_IdRefCmd,
                                      -currentLimit,
                                      currentLimit);
      iqRef = MotorControll_ClampFloat(MotorControll_IqRefCmd,
                                      -currentLimit,
                                      currentLimit);
      break;

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
      idRef = 0.0F;
      iqRef = 0.0F;
      break;

    case MOTOR_MODE_IDLE:
    default:
      idRef = 0.0F;
      iqRef = 0.0F;
      break;
  }

  MotorControll_IdRefOut = idRef;
  MotorControll_IqRefOut = iqRef;
  (void)Rte_Write_Pp_MotorCurrentRef_Id_Ref(idRef);
  (void)Rte_Write_Pp_MotorCurrentRef_Iq_Ref(iqRef);
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
#if (APPL_SPI9180_BRINGUP == 1)
  /* SPI9180 bring-up: do not run motor control / 5012 SPI. */
  return;
#else
  MotorMode_Type motorMode;

  MotorControll_MainCounter++;

  if (MotorControll_OpenLoopEnable != 0U)
  {
    motorMode = MOTOR_MODE_OPEN_LOOP;
  }
  else
  {
    motorMode = MotorControll_MotorModeCmd;
  }

  MotorControll_UpdateSensorObservation();
  MotorControll_UpdateGateDriverObservation();

  if (motorMode != MotorControll_PrevMotorMode)
  {
    if (motorMode == MOTOR_MODE_CALIBRATION)
    {
      MotorZeroCal_Start();
    }
    else if (motorMode == MOTOR_MODE_CALIBRATION_ERASE)
    {
      MotorZeroCal_Erase();
      MotorControll_MotorModeCmd = MOTOR_MODE_IDLE;
      motorMode = MOTOR_MODE_IDLE;
    }
    else if (motorMode == MOTOR_MODE_OPEN_LOOP)
    {
      MotorFoc_OpenLoop_Reset();
      MotorCdd_FocClearFault();
    }
    else
    {
      /* No action on other mode transitions. */
    }
  }

  MotorControll_UpdateCurrentRefsViaRte(motorMode);
  (void)Rte_Write_Pp_MotorCtrlCmd_MotorMode((uint8)motorMode);
  MotorCdd_FocSetCmdMirror((uint8)motorMode,
                           MotorControll_IdRefOut,
                           MotorControll_IqRefOut);
  MotorZeroCal_MainFunction();

  if (MotorControll_OpenLoopEnable != 0U)
  {
    motorMode = MOTOR_MODE_OPEN_LOOP;
  }
  else
  {
    motorMode = MotorControll_MotorModeCmd;
  }
  MotorControll_PrevMotorMode = motorMode;

  if (motorMode == MOTOR_MODE_IDLE)
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
#endif
}

#define MotorControll_STOP_SEC_CODE
#include "MotorControll_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_TestCode:
     Reason:     This justification is used as summary justification for all deviations caused by wrong analysis tool results.
                 The used analysis tool QAC 9.0 sometimes creates wrong messages. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
