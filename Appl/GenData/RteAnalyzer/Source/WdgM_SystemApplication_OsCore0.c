/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  WdgM_SystemApplication_OsCore0.c
 *           Config:  last364.dpa
 *        SW-C Type:  WdgM_SystemApplication_OsCore0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.29.0
 *                    RTE Core Version 1.29.0
 *          License:  CBD2200508
 *
 *      Description:  C-Code implementation template for SW-C <WdgM_SystemApplication_OsCore0>
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
 * WdgMMode
 *   
 *
 * WdgM_CheckpointIdType
 *   
 *
 * WdgM_GlobalStatusType
 *   
 *
 * WdgM_LocalStatusType
 *   
 *
 * WdgM_ModeType
 *   
 *
 * WdgM_SupervisedEntityIdType
 *   
 *
 *
 * Port Prototypes:
 * ================
 * alive_WdgMSupervisedEntity
 *
 * general_Core0
 *
 * globalmode_Core0
 *
 * localStatus_WdgMSupervisedEntity
 *
 * mode_WdgMSupervisedEntity
 *
 *
 * Operation Prototypes:
 * =====================
 * CheckpointReached of Port Interface WdgM_AliveSupervision
 *   
 *
 * GetFirstExpiredSEID of Port Interface WdgM_General
 *   
 *
 * GetGlobalStatus of Port Interface WdgM_General
 *   
 *
 * GetLocalStatus of Port Interface WdgM_General
 *   
 *
 * GetMode of Port Interface WdgM_General
 *   
 *
 * PerformReset of Port Interface WdgM_General
 *   
 *
 * SetMode of Port Interface WdgM_General
 *   
 *
 * GetLocalStatus of Port Interface WdgM_LocalStatus
 *   
 *
 *
 * Mode Declaration Groups:
 * ========================
 * WdgM_Mode
 *   
 *
 *********************************************************************************************************************/

#include "Rte_WdgM_SystemApplication_OsCore0.h"
#include "TSC_WdgM_SystemApplication_OsCore0.h"
#include "SchM_WdgM.h"
#include "TSC_SchM_WdgM.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void WdgM_SystemApplication_OsCore0_TestDefines(void);

typedef P2FUNC(Std_ReturnType, RTE_CODE, FncPtrType)(void);


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
 * WdgM_CheckpointIdType: Integer in interval [0...65535]
 * WdgM_ModeType: Integer in interval [0...255]
 * WdgM_SupervisedEntityIdType: Integer in interval [0...65535]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * WdgMMode: Enumeration of integer in interval [0...255] with enumerators
 *   SUPERVISION_OK (0U)
 *   SUPERVISION_FAILED (1U)
 *   SUPERVISION_EXPIRED (2U)
 *   SUPERVISION_STOPPED (3U)
 *   SUPERVISION_DEACTIVATED (4U)
 * WdgM_GlobalStatusType: Enumeration of integer in interval [0...4] with enumerators
 *   WDGM_GLOBAL_STATUS_OK (0U)
 *   WDGM_GLOBAL_STATUS_FAILED (1U)
 *   WDGM_GLOBAL_STATUS_EXPIRED (2U)
 *   WDGM_GLOBAL_STATUS_STOPPED (3U)
 *   WDGM_GLOBAL_STATUS_DEACTIVATED (4U)
 * WdgM_LocalStatusType: Enumeration of integer in interval [0...4] with enumerators
 *   WDGM_LOCAL_STATUS_OK (0U)
 *   WDGM_LOCAL_STATUS_FAILED (1U)
 *   WDGM_LOCAL_STATUS_EXPIRED (2U)
 *   WDGM_LOCAL_STATUS_DEACTIVATED (4U)
 *
 *********************************************************************************************************************/


#define WdgM_SystemApplication_OsCore0_START_SEC_CODE
#include "WdgM_SystemApplication_OsCore0_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CheckpointReached
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CheckpointReached> of PortPrototype <alive_WdgMSupervisedEntity>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType WdgM_CheckpointReached(WdgM_CheckpointIdType CPID)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_WdgM_AliveSupervision_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CheckpointReached_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, WdgM_SystemApplication_OsCore0_CODE) WdgM_CheckpointReached(WdgM_SupervisedEntityIdType parg0, WdgM_CheckpointIdType CPID) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_CheckpointReached (returns application error)
 *********************************************************************************************************************/

  WdgM_SystemApplication_OsCore0_TestDefines(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetFirstExpiredSEID
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetFirstExpiredSEID> of PortPrototype <general_Core0>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType WdgM_GetFirstExpiredSEID(WdgM_SupervisedEntityIdType *SEID)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_WdgM_General_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetFirstExpiredSEID_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, WdgM_SystemApplication_OsCore0_CODE) WdgM_GetFirstExpiredSEID(P2VAR(WdgM_SupervisedEntityIdType, AUTOMATIC, RTE_WDGM_SYSTEMAPPLICATION_OSCORE0_APPL_VAR) SEID) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_GetFirstExpiredSEID (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetGlobalStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetGlobalStatus> of PortPrototype <general_Core0>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType WdgM_GetGlobalStatus(WdgM_GlobalStatusType *Status)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_WdgM_General_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetGlobalStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, WdgM_SystemApplication_OsCore0_CODE) WdgM_GetGlobalStatus(P2VAR(WdgM_GlobalStatusType, AUTOMATIC, RTE_WDGM_SYSTEMAPPLICATION_OSCORE0_APPL_VAR) Status) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_GetGlobalStatus (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetLocalStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetLocalStatus> of PortPrototype <general_Core0>
 *   - triggered by server invocation for OperationPrototype <GetLocalStatus> of PortPrototype <localStatus_WdgMSupervisedEntity>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType WdgM_GetLocalStatus(WdgM_SupervisedEntityIdType SEID, WdgM_LocalStatusType *Status)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_WdgM_General_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetLocalStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, WdgM_SystemApplication_OsCore0_CODE) WdgM_GetLocalStatus(WdgM_SupervisedEntityIdType SEID, P2VAR(WdgM_LocalStatusType, AUTOMATIC, RTE_WDGM_SYSTEMAPPLICATION_OSCORE0_APPL_VAR) Status) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_GetLocalStatus (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetMode
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetMode> of PortPrototype <general_Core0>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType WdgM_GetMode(WdgM_ModeType *Mode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_WdgM_General_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetMode_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, WdgM_SystemApplication_OsCore0_CODE) WdgM_GetMode(P2VAR(WdgM_ModeType, AUTOMATIC, RTE_WDGM_SYSTEMAPPLICATION_OSCORE0_APPL_VAR) Mode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_GetMode (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PerformReset
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <PerformReset> of PortPrototype <general_Core0>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType WdgM_PerformReset(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_WdgM_General_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PerformReset_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, WdgM_SystemApplication_OsCore0_CODE) WdgM_PerformReset(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_PerformReset (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SetMode
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetMode> of PortPrototype <general_Core0>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType WdgM_SetMode(WdgM_ModeType Mode, uint16 CallerID)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_WdgM_General_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SetMode_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, WdgM_SystemApplication_OsCore0_CODE) WdgM_SetMode(WdgM_ModeType Mode, uint16 CallerID) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_SetMode (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: WdgM_MainFunction
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_globalmode_Core0_currentMode(WdgMMode mode)
 *   Modes of Rte_ModeType_WdgM_Mode:
 *   - RTE_MODE_WdgM_Mode_SUPERVISION_DEACTIVATED
 *   - RTE_MODE_WdgM_Mode_SUPERVISION_EXPIRED
 *   - RTE_MODE_WdgM_Mode_SUPERVISION_FAILED
 *   - RTE_MODE_WdgM_Mode_SUPERVISION_OK
 *   - RTE_MODE_WdgM_Mode_SUPERVISION_STOPPED
 *   - RTE_TRANSITION_WdgM_Mode
 *   Std_ReturnType Rte_Switch_mode_WdgMSupervisedEntity_currentMode(WdgMMode mode)
 *   Modes of Rte_ModeType_WdgM_Mode:
 *   - RTE_MODE_WdgM_Mode_SUPERVISION_DEACTIVATED
 *   - RTE_MODE_WdgM_Mode_SUPERVISION_EXPIRED
 *   - RTE_MODE_WdgM_Mode_SUPERVISION_FAILED
 *   - RTE_MODE_WdgM_Mode_SUPERVISION_OK
 *   - RTE_MODE_WdgM_Mode_SUPERVISION_STOPPED
 *   - RTE_TRANSITION_WdgM_Mode
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, WdgM_SystemApplication_OsCore0_CODE) WdgM_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_MainFunction
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error;

  /**********************************************************
  * Direct Function Accesses and Take Addresses of Functions
  **********************************************************/

  {
    FncPtrType WdgM_SystemApplication_OsCore0_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    WdgM_SystemApplication_OsCore0_FctPtr = (FncPtrType)Rte_Switch_globalmode_Core0_currentMode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_WdgM_SystemApplication_OsCore0_Rte_Switch_globalmode_Core0_currentMode(RTE_MODE_WdgM_Mode_SUPERVISION_OK); /* PRQA S 3226, 0315 */ /* MD_Rte_3226, MD_Rte_0315 */
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = FALSE;
      break;
    case RTE_E_LIMIT:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType WdgM_SystemApplication_OsCore0_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    WdgM_SystemApplication_OsCore0_FctPtr = (FncPtrType)Rte_Switch_mode_WdgMSupervisedEntity_currentMode; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_WdgM_SystemApplication_OsCore0_Rte_Switch_mode_WdgMSupervisedEntity_currentMode(RTE_MODE_WdgM_Mode_SUPERVISION_OK); /* PRQA S 3226, 0315 */ /* MD_Rte_3226, MD_Rte_0315 */
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = FALSE;
      break;
    case RTE_E_LIMIT:
      fct_error = TRUE;
      break;
  }

 /* PRQA S 3226, 1863 L1 */ /* MD_Rte_Os, MD_Rte_Os */
  TSC_WdgM_SchM_Enter_WdgM_WDGM_EXCLUSIVE_AREA_0();
  TSC_WdgM_SchM_Exit_WdgM_WDGM_EXCLUSIVE_AREA_0();
/* PRQA L:L1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define WdgM_SystemApplication_OsCore0_STOP_SEC_CODE
#include "WdgM_SystemApplication_OsCore0_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void WdgM_SystemApplication_OsCore0_TestDefines(void)
{
  /* Enumeration Data Types */

  WdgMMode Test_WdgMMode_V_1 = SUPERVISION_OK;
  WdgMMode Test_WdgMMode_V_2 = SUPERVISION_FAILED;
  WdgMMode Test_WdgMMode_V_3 = SUPERVISION_EXPIRED;
  WdgMMode Test_WdgMMode_V_4 = SUPERVISION_STOPPED;
  WdgMMode Test_WdgMMode_V_5 = SUPERVISION_DEACTIVATED;

  WdgM_GlobalStatusType Test_WdgM_GlobalStatusType_V_1 = WDGM_GLOBAL_STATUS_OK;
  WdgM_GlobalStatusType Test_WdgM_GlobalStatusType_V_2 = WDGM_GLOBAL_STATUS_FAILED;
  WdgM_GlobalStatusType Test_WdgM_GlobalStatusType_V_3 = WDGM_GLOBAL_STATUS_EXPIRED;
  WdgM_GlobalStatusType Test_WdgM_GlobalStatusType_V_4 = WDGM_GLOBAL_STATUS_STOPPED;
  WdgM_GlobalStatusType Test_WdgM_GlobalStatusType_V_5 = WDGM_GLOBAL_STATUS_DEACTIVATED;

  WdgM_LocalStatusType Test_WdgM_LocalStatusType_V_1 = WDGM_LOCAL_STATUS_OK;
  WdgM_LocalStatusType Test_WdgM_LocalStatusType_V_2 = WDGM_LOCAL_STATUS_FAILED;
  WdgM_LocalStatusType Test_WdgM_LocalStatusType_V_3 = WDGM_LOCAL_STATUS_EXPIRED;
  WdgM_LocalStatusType Test_WdgM_LocalStatusType_V_4 = WDGM_LOCAL_STATUS_DEACTIVATED;

  /* Modes */

  WdgMMode Test_WdgM_Mode_MV_1 = RTE_MODE_WdgM_Mode_SUPERVISION_OK;
  WdgMMode Test_WdgM_Mode_MV_2 = RTE_MODE_WdgM_Mode_SUPERVISION_FAILED;
  WdgMMode Test_WdgM_Mode_MV_3 = RTE_MODE_WdgM_Mode_SUPERVISION_EXPIRED;
  WdgMMode Test_WdgM_Mode_MV_4 = RTE_MODE_WdgM_Mode_SUPERVISION_STOPPED;
  WdgMMode Test_WdgM_Mode_MV_5 = RTE_MODE_WdgM_Mode_SUPERVISION_DEACTIVATED;
  WdgMMode Test_WdgM_Mode_TV = RTE_TRANSITION_WdgM_Mode;
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

   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_TestCode:
     Reason:     This justification is used as summary justification for all deviations caused by wrong analysis tool results.
                 The used analysis tool QAC 9.0 sometimes creates wrong messages. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
