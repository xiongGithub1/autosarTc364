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

#include "Rte_StartApp.h"

#include "CanIf.h"
#include "CanSM_ComM.h"
#include "Com.h"
#include "ComM.h"
#include "ComM_EcuMBswM.h"
#include "Dio.h"
#include "EcuM.h"
#include "Rte_EcuM_Type.h"
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

uint8 StartApp_CanTxLampCnt;
boolean StartApp_CanTxRearInteriorLight;
uint8 StartApp_CanTxLampCntResult;
uint8 StartApp_CanTxRearInteriorLightResult;
uint32 StartApp_CanTxUpdateCounter;
uint32 StartApp_CanTxSkipCounter;
Com_StatusType StartApp_ComStatus;
EcuM_StateType StartApp_EcuMState;
Std_ReturnType StartApp_EcuMGetStateResult;
ComM_InitStatusType StartApp_ComMStatus;
Std_ReturnType StartApp_ComMGetStatusResult;
Std_ReturnType StartApp_ComMRequestResult;
boolean StartApp_ComMCommunicationAllowed;
ComM_ModeType StartApp_ComMCurrentMode;
Std_ReturnType StartApp_ComMCurrentModeResult;
ComM_ModeType StartApp_CanSMCurrentMode;
Std_ReturnType StartApp_CanSMCurrentModeResult;
CanIf_ControllerModeType StartApp_CanIfControllerMode;
Std_ReturnType StartApp_CanIfControllerModeResult;
uint8 Can1_En=0;
uint8 Can1_Nerr=0;
uint8 Can1_Nstb=0;
CanIf_PduGetModeType StartApp_CanIfPduMode;
Std_ReturnType StartApp_CanIfPduModeResult;


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


#define StartApp_START_SEC_CODE
#include "StartApp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, StartApp_CODE) StartApp_Cyclic1000ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StartApp_Cyclic1000ms
 *********************************************************************************************************************/

	Dio_FlipChannel(DioConf_DioChannel_DioChannel_led2);
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
 *   - triggered on TimingEvent every 500ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: StartApp_Cyclic500ms_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, StartApp_CODE) StartApp_Cyclic250ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StartApp_Cyclic500ms
 *********************************************************************************************************************/

	Dio_FlipChannel(DioConf_DioChannel_DioChannel_led1);
	Can1_En=Dio_ReadChannel(DioConf_DioChannel_DioChannel_Can1En);
	Can1_Nerr=Dio_ReadChannel(DioConf_DioChannel_DioChannel_Can1Nerr);
	Can1_Nstb=Dio_ReadChannel(DioConf_DioChannel_DioChannel_Can1Nstb);
	StartApp_CanTxLampCnt++;
	StartApp_CanTxRearInteriorLight = (StartApp_CanTxRearInteriorLight == FALSE) ? TRUE : FALSE;

	StartApp_ComStatus = Com_GetStatus();
	StartApp_EcuMGetStateResult = EcuM_GetState(&StartApp_EcuMState);
	StartApp_ComMGetStatusResult = ComM_GetStatus(&StartApp_ComMStatus);
	StartApp_ComMCurrentModeResult = ComM_GetCurrentComMode(ComMConf_ComMUser_CN_CAN00_06ecbb07, &StartApp_ComMCurrentMode);
	StartApp_CanSMCurrentModeResult = CanSM_GetCurrentComMode(ComMConf_ComMChannel_CN_CAN00_5e566ad9, &StartApp_CanSMCurrentMode);
	StartApp_CanIfControllerModeResult = CanIf_GetControllerMode(0u, &StartApp_CanIfControllerMode);
	StartApp_CanIfPduModeResult = CanIf_GetPduMode(0u, &StartApp_CanIfPduMode);

	if(StartApp_ComStatus == COM_INIT)
	{
		StartApp_CanTxLampCntResult = Com_SendSignal(ComConf_ComSignal_sig_LampCnt_omsg_MyECU_Lamp_oCAN00_f37e68ea_Tx, &StartApp_CanTxLampCnt);
		StartApp_CanTxRearInteriorLightResult = Com_SendSignal(ComConf_ComSignal_sig_RearInteriorLight_omsg_Transmit_oCAN00_49a633c1_Tx, &StartApp_CanTxRearInteriorLight);
		StartApp_CanTxUpdateCounter++;
	}
	else
	{
		StartApp_CanTxSkipCounter++;
	}
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
  (void)EcuM_RequestRUN(EcuMConf_EcuMFixedUserConfig_EcuMFixedUserConfig);
  ComM_CommunicationAllowed(ComMConf_ComMChannel_CN_CAN00_5e566ad9, TRUE);
  StartApp_ComMCommunicationAllowed = TRUE;
  StartApp_ComMRequestResult = ComM_RequestComMode(ComMConf_ComMUser_CN_CAN00_06ecbb07, COMM_FULL_COMMUNICATION);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define StartApp_STOP_SEC_CODE
#include "StartApp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


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


