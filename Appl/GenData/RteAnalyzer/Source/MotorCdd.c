/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  MotorCdd.c
 *           Config:  last364.dpa
 *        SW-C Type:  MotorCdd
 *
 *        Generator:  MICROSAR RTE Generator Version 4.29.0
 *                    RTE Core Version 1.29.0
 *          License:  CBD2200508
 *
 *      Description:  C-Code implementation template for SW-C <MotorCdd>
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

#include "Rte_MotorCdd.h"
#include "TSC_MotorCdd.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * boolean (MotorSw): Boolean (standard type)
 * boolean (Tle9180_ov_Fault): Boolean (standard type)
 * float32 (ElecAngle): Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * float32 (Id_act): Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * float32 (Id_ref): Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * float32 (Iq_act): Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * float32 (Iq_ref): Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * float32 (Iu_A): Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * float32 (Iv_A): Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * float32 (Iw_A): Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * float32 (MechRpm): Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * float32 (motorBusV): Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * uint16 (OriginAngle): Integer in interval [0...65535] (standard type)
 * uint8 (MotorMd): Integer in interval [0...255] (standard type)
 *
 *********************************************************************************************************************/


#define MotorCdd_START_SEC_CODE
#include "MotorCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotorCDDMainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Pp_MotorCtrlCmd_MotorMode(uint8 *data)
 *   Std_ReturnType Rte_Read_Pp_MotorCurrentRef_Id_Ref(float32 *data)
 *   Std_ReturnType Rte_Read_Pp_MotorCurrentRef_Iq_Ref(float32 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_MotorDcBusVoltage_Vbus(float32 data)
 *   Std_ReturnType Rte_Write_Pp_MotorElectricalAngle_ElectricAngle(float32 data)
 *   Std_ReturnType Rte_Write_Pp_MotorFaultStatus_tle9180_Ov_Fault(boolean data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotorCDDMainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MotorCdd_CODE) MotorCDDMainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotorCDDMainFunction
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error;

  uint8 Read_Pp_MotorCtrlCmd_MotorMode;
  float32 Read_Pp_MotorCurrentRef_Id_Ref;
  float32 Read_Pp_MotorCurrentRef_Iq_Ref;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_MotorCdd_Rte_Read_Pp_MotorCtrlCmd_MotorMode(&Read_Pp_MotorCtrlCmd_MotorMode); /* PRQA S 3226, 0315 */ /* MD_Rte_3226, MD_Rte_0315 */
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = FALSE;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = TRUE;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = TRUE;
      break;
    case RTE_E_INVALID:
      fct_error = TRUE;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = TRUE;
      break;
  }

  fct_status = TSC_MotorCdd_Rte_Read_Pp_MotorCurrentRef_Id_Ref(&Read_Pp_MotorCurrentRef_Id_Ref); /* PRQA S 3226, 0315 */ /* MD_Rte_3226, MD_Rte_0315 */
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = FALSE;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = TRUE;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = TRUE;
      break;
    case RTE_E_INVALID:
      fct_error = TRUE;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = TRUE;
      break;
  }

  fct_status = TSC_MotorCdd_Rte_Read_Pp_MotorCurrentRef_Iq_Ref(&Read_Pp_MotorCurrentRef_Iq_Ref); /* PRQA S 3226, 0315 */ /* MD_Rte_3226, MD_Rte_0315 */
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = FALSE;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = TRUE;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = TRUE;
      break;
    case RTE_E_INVALID:
      fct_error = TRUE;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = TRUE;
      break;
  }

  fct_status = TSC_MotorCdd_Rte_Write_Pp_MotorDcBusVoltage_Vbus(Rte_InitValue_Pp_MotorDcBusVoltage_Vbus); /* PRQA S 3226, 0315 */ /* MD_Rte_3226, MD_Rte_0315 */
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = FALSE;
      break;
  }

  fct_status = TSC_MotorCdd_Rte_Write_Pp_MotorElectricalAngle_ElectricAngle(Rte_InitValue_Pp_MotorElectricalAngle_ElectricAngle); /* PRQA S 3226, 0315 */ /* MD_Rte_3226, MD_Rte_0315 */
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = FALSE;
      break;
  }

  fct_status = TSC_MotorCdd_Rte_Write_Pp_MotorFaultStatus_tle9180_Ov_Fault(Rte_InitValue_Pp_MotorFaultStatus_tle9180_Ov_Fault); /* PRQA S 3226, 0315 */ /* MD_Rte_3226, MD_Rte_0315 */
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = FALSE;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotorCdd_AdcOnSampleReady
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by ExternalTriggerOccurredEvent of PortPrototype <Rp_AdcSampleReady>
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotorCdd_AdcOnSampleReady_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MotorCdd_CODE) MotorCdd_AdcOnSampleReady(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotorCdd_AdcOnSampleReady
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotorCdd_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotorCdd_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MotorCdd_CODE) MotorCdd_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotorCdd_Init
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Pp_MotorCdd_EnableInverter_EnableInverter
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <EnableInverter> of PortPrototype <Pp_MotorCdd_EnableInverter>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Pp_MotorCdd_EnableInverter_EnableInverter(boolean arg)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Pp_MotorCdd_EnableInverter_EnableInverter_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MotorCdd_CODE) Pp_MotorCdd_EnableInverter_EnableInverter(boolean arg) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Pp_MotorCdd_EnableInverter_EnableInverter
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define MotorCdd_STOP_SEC_CODE
#include "MotorCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


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
   MD_Rte_0315:  MISRA rule: Dir1.1
     Reason:     Pointer cast to void because generic access is necessary.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3226:  MISRA rule: Rule13.4
     Reason:     Needed for function like macro to do arithmetic operations in sub macros
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_TestCode:
     Reason:     This justification is used as summary justification for all deviations caused by wrong analysis tool results.
                 The used analysis tool QAC 9.0 sometimes creates wrong messages. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
