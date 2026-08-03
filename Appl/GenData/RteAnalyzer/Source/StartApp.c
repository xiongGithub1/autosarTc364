/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  StartApp.c
 *           Config:  last364.dpa
 *        SW-C Type:  StartApp
 *
 *        Generator:  MICROSAR RTE Generator Version 4.29.0
 *                    RTE Core Version 1.29.0
 *          License:  CBD2200508
 *
 *      Description:  C-Code implementation template for SW-C <StartApp>
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

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * ComM_ModeType
 *   
 *
 * ComM_UserHandleType
 *   
 *
 * EcuM_UserType
 *   
 *
 *
 * Operation Prototypes:
 * =====================
 * RequestRUN of Port Interface EcuM_StateRequest
 *   
 *
 *********************************************************************************************************************/

#include "Rte_StartApp.h"
#include "TSC_StartApp.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"

static void StartApp_TestDefines(void);


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
 * ComM_UserHandleType: Integer in interval [0...65535]
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
 * uint8: Integer in interval [0...255] (standard type)
 * uint8 (MotorMd): Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * ComM_ModeType: Enumeration of integer in interval [0...3] with enumerators
 *   COMM_NO_COMMUNICATION (0U)
 *   COMM_SILENT_COMMUNICATION (1U)
 *   COMM_FULL_COMMUNICATION (2U)
 * EcuM_UserType: Enumeration of integer in interval [0...255] with enumerators
 *
 *********************************************************************************************************************/


#define StartApp_START_SEC_CODE
#include "StartApp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StartApp_Cyclic1000ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 1s
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: StartApp_Cyclic1000ms_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, StartApp_CODE) StartApp_Cyclic1000ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StartApp_Cyclic1000ms
 *********************************************************************************************************************/

  StartApp_TestDefines(); /* PRQA S 2987 */ /* MD_Rte_2987 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StartApp_Cyclic10ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: StartApp_Cyclic10ms_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, StartApp_CODE) StartApp_Cyclic10ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StartApp_Cyclic10ms
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StartApp_Cyclic1ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 1ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: StartApp_Cyclic1ms_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, StartApp_CODE) StartApp_Cyclic1ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StartApp_Cyclic1ms
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StartApp_Cyclic250ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 250ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: StartApp_Cyclic250ms_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, StartApp_CODE) StartApp_Cyclic250ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StartApp_Cyclic250ms
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StartApp_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_ComM_UserRequest_RequestComMode(ComM_ModeType ComMode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_ComM_UserRequest_E_MODE_LIMITATION, RTE_E_ComM_UserRequest_E_NOT_OK
 *   Std_ReturnType Rte_Call_EcuM_StateRequest_RequestRUN(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_EcuM_StateRequest_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: StartApp_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, StartApp_CODE) StartApp_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StartApp_Init
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_StartApp_Rte_Call_ComM_UserRequest_RequestComMode(0U); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = FALSE;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = TRUE;
      break;
    case RTE_E_TIMEOUT:
      fct_error = TRUE;
      break;
    case RTE_E_ComM_UserRequest_E_MODE_LIMITATION:
      fct_error = TRUE;
      break;
    case RTE_E_ComM_UserRequest_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  fct_status = TSC_StartApp_Rte_Call_EcuM_StateRequest_RequestRUN(); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = FALSE;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = TRUE;
      break;
    case RTE_E_TIMEOUT:
      fct_error = TRUE;
      break;
    case RTE_E_EcuM_StateRequest_E_NOT_OK:
      fct_error = TRUE;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define StartApp_STOP_SEC_CODE
#include "StartApp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void StartApp_TestDefines(void)
{
  /* Enumeration Data Types */

  ComM_ModeType Test_ComM_ModeType_V_1 = COMM_NO_COMMUNICATION;
  ComM_ModeType Test_ComM_ModeType_V_2 = COMM_SILENT_COMMUNICATION;
  ComM_ModeType Test_ComM_ModeType_V_3 = COMM_FULL_COMMUNICATION;
}

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

   MD_Rte_2987:  MISRA rule: Rule2.2
     Reason:     Used to simplify code generation.
     Risk:       No functional risk. There is no side effect.
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
