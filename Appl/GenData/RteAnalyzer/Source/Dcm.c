/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Dcm.c
 *           Config:  last364.dpa
 *        SW-C Type:  Dcm
 *
 *        Generator:  MICROSAR RTE Generator Version 4.29.0
 *                    RTE Core Version 1.29.0
 *          License:  CBD2200508
 *
 *      Description:  C-Code implementation template for SW-C <Dcm>
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
 * Dcm_CommunicationModeType
 *   
 *
 * Dcm_ConfirmationStatusType
 *   
 *
 * Dcm_ControlDtcSettingType
 *   
 *
 * Dcm_DiagnosticSessionControlType
 *   
 *
 * Dcm_EcuResetType
 *   
 *
 * Dcm_NegativeResponseCodeType
 *   
 *
 * Dcm_OpStatusType
 *   
 *
 * Dcm_ProtocolType
 *   
 *
 * Dcm_RequestDataOut_SampleRoutineControl_Out_ResultPrimitiveType
 *   
 *
 * Dcm_RequestDataOut_SampleRoutineControl_Out_ResultType
 *   
 *
 * Dcm_RequestDataOut_SampleRoutineControl_StartOnly_Out_ResultPrimitiveType
 *   
 *
 * Dcm_RequestDataOut_SampleRoutineControl_StartOnly_Out_ResultType
 *   
 *
 * Dcm_RequestKindType
 *   
 *
 * Dcm_SecLevelType
 *   
 *
 * Dcm_SesCtrlType
 *   
 *
 * Dcm_StartDataIn_SampleRoutineControl_In_Option0PrimitiveType
 *   
 *
 * Dcm_StartDataIn_SampleRoutineControl_In_Option0Type
 *   
 *
 * Dcm_StartDataIn_SampleRoutineControl_StartOnly_In_Option1ArrayType
 *   
 *
 * Dcm_StartDataOut_SampleRoutineControl_Out_InitStatePrimitiveType
 *   
 *
 * Dcm_StartDataOut_SampleRoutineControl_Out_InitStateType
 *   
 *
 * Dcm_StopDataOut_SampleRoutineControl_Out_StopStatePrimitiveType
 *   
 *
 * Dcm_StopDataOut_SampleRoutineControl_Out_StopStateType
 *   
 *
 *********************************************************************************************************************/

#include "Rte_Dcm.h"
#include "TSC_Dcm.h"
#include "SchM_Dcm.h"
#include "TSC_SchM_Dcm.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void Dcm_TestDefines(void);

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
 * Dcm_RequestDataOut_SampleRoutineControl_Out_ResultPrimitiveType: Integer in interval [0...65535]
 * Dcm_RequestDataOut_SampleRoutineControl_Out_ResultType: Integer in interval [0...65535]
 * Dcm_RequestDataOut_SampleRoutineControl_StartOnly_Out_ResultPrimitiveType: Integer in interval [0...4294967295]
 * Dcm_RequestDataOut_SampleRoutineControl_StartOnly_Out_ResultType: Integer in interval [0...4294967295]
 * Dcm_StartDataIn_SampleRoutineControl_In_Option0PrimitiveType: Integer in interval [0...255]
 * Dcm_StartDataIn_SampleRoutineControl_In_Option0Type: Integer in interval [0...255]
 * Dcm_StartDataIn_SampleRoutineControl_StartOnly_In_Option1ArrayType: Integer in interval [0...255]
 * Dcm_StartDataOut_SampleRoutineControl_Out_InitStatePrimitiveType: Integer in interval [0...4294967295]
 * Dcm_StartDataOut_SampleRoutineControl_Out_InitStateType: Integer in interval [0...4294967295]
 * Dcm_StopDataOut_SampleRoutineControl_Out_StopStatePrimitiveType: Integer in interval [0...4294967295]
 * Dcm_StopDataOut_SampleRoutineControl_Out_StopStateType: Integer in interval [0...4294967295]
 * boolean: Boolean (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Dcm_CommunicationModeType: Enumeration of integer in interval [0...255] with enumerators
 *   DCM_ENABLE_RX_TX_NORM (0U)
 *   DCM_ENABLE_RX_DISABLE_TX_NORM (1U)
 *   DCM_DISABLE_RX_ENABLE_TX_NORM (2U)
 *   DCM_DISABLE_RX_TX_NORMAL (3U)
 *   DCM_ENABLE_RX_TX_NM (4U)
 *   DCM_ENABLE_RX_DISABLE_TX_NM (5U)
 *   DCM_DISABLE_RX_ENABLE_TX_NM (6U)
 *   DCM_DISABLE_RX_TX_NM (7U)
 *   DCM_ENABLE_RX_TX_NORM_NM (8U)
 *   DCM_ENABLE_RX_DISABLE_TX_NORM_NM (9U)
 *   DCM_DISABLE_RX_ENABLE_TX_NORM_NM (10U)
 *   DCM_DISABLE_RX_TX_NORM_NM (11U)
 * Dcm_ConfirmationStatusType: Enumeration of integer in interval [0...3] with enumerators
 *   DCM_RES_POS_OK (0U)
 *   DCM_RES_POS_NOT_OK (1U)
 *   DCM_RES_NEG_OK (2U)
 *   DCM_RES_NEG_NOT_OK (3U)
 * Dcm_ControlDtcSettingType: Enumeration of integer in interval [0...255] with enumerators
 *   DCM_ENUM_ENABLEDTCSETTING (0U)
 *   DCM_ENUM_DISABLEDTCSETTING (1U)
 * Dcm_DiagnosticSessionControlType: Enumeration of integer in interval [0...255] with enumerators
 *   DCM_ENUM_DEFAULT_SESSION (1U)
 *   DCM_ENUM_PROGRAMMING_SESSION (2U)
 *   DCM_ENUM_EXTENDED_SESSION (3U)
 * Dcm_EcuResetType: Enumeration of integer in interval [0...255] with enumerators
 *   DCM_ENUM_NONE (0U)
 *   DCM_ENUM_HARD (1U)
 *   DCM_ENUM_KEYONOFF (2U)
 *   DCM_ENUM_SOFT (3U)
 *   DCM_ENUM_JUMPTOBOOTLOADER (4U)
 *   DCM_ENUM_JUMPTOSYSSUPPLIERBOOTLOADER (5U)
 *   DCM_ENUM_EXECUTE (6U)
 * Dcm_NegativeResponseCodeType: Enumeration of integer in interval [0...255] with enumerators
 *   DCM_E_POSITIVERESPONSE (0U)
 *   DCM_E_GENERALREJECT (16U)
 *   DCM_E_SERVICENOTSUPPORTED (17U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTED (18U)
 *   DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT (19U)
 *   DCM_E_RESPONSETOOLONG (20U)
 *   DCM_E_BUSYREPEATREQUEST (33U)
 *   DCM_E_CONDITIONSNOTCORRECT (34U)
 *   DCM_E_REQUESTSEQUENCEERROR (36U)
 *   DCM_E_NORESPONSEFROMSUBNETCOMPONENT (37U)
 *   DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION (38U)
 *   DCM_E_REQUESTOUTOFRANGE (49U)
 *   DCM_E_SECURITYACCESSDENIED (51U)
 *   DCM_E_AUTHENTICATIONREQUIRED (52U)
 *   DCM_E_INVALIDKEY (53U)
 *   DCM_E_EXCEEDNUMBEROFATTEMPTS (54U)
 *   DCM_E_REQUIREDTIMEDELAYNOTEXPIRED (55U)
 *   DCM_E_CVF_INVALIDTIMEPERIOD (80U)
 *   DCM_E_CVF_INVALIDSIGNATURE (81U)
 *   DCM_E_CVF_INVALIDCHAINOFTRUST (82U)
 *   DCM_E_CVF_INVALIDTYPE (83U)
 *   DCM_E_CVF_INVALIDFORMAT (84U)
 *   DCM_E_CVF_INVALIDCONTENT (85U)
 *   DCM_E_CVF_INVALIDSCOPE (86U)
 *   DCM_E_CVF_INVALIDCERTIFICATEREVOKED (87U)
 *   DCM_E_OWNERSHIPVERIFICATIONFAILED (88U)
 *   DCM_E_CHALLENGECALCULATIONFAILED (89U)
 *   DCM_E_UPLOADDOWNLOADNOTACCEPTED (112U)
 *   DCM_E_TRANSFERDATASUSPENDED (113U)
 *   DCM_E_GENERALPROGRAMMINGFAILURE (114U)
 *   DCM_E_WRONGBLOCKSEQUENCECOUNTER (115U)
 *   DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING (120U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION (126U)
 *   DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION (127U)
 *   DCM_E_RPMTOOHIGH (129U)
 *   DCM_E_RPMTOOLOW (130U)
 *   DCM_E_ENGINEISRUNNING (131U)
 *   DCM_E_ENGINEISNOTRUNNING (132U)
 *   DCM_E_ENGINERUNTIMETOOLOW (133U)
 *   DCM_E_TEMPERATURETOOHIGH (134U)
 *   DCM_E_TEMPERATURETOOLOW (135U)
 *   DCM_E_VEHICLESPEEDTOOHIGH (136U)
 *   DCM_E_VEHICLESPEEDTOOLOW (137U)
 *   DCM_E_THROTTLE_PEDALTOOHIGH (138U)
 *   DCM_E_THROTTLE_PEDALTOOLOW (139U)
 *   DCM_E_TRANSMISSIONRANGENOTINNEUTRAL (140U)
 *   DCM_E_TRANSMISSIONRANGENOTINGEAR (141U)
 *   DCM_E_BRAKESWITCH_NOTCLOSED (143U)
 *   DCM_E_SHIFTERLEVERNOTINPARK (144U)
 *   DCM_E_TORQUECONVERTERCLUTCHLOCKED (145U)
 *   DCM_E_VOLTAGETOOHIGH (146U)
 *   DCM_E_VOLTAGETOOLOW (147U)
 *   DCM_E_VMSCNC_0 (240U)
 *   DCM_E_VMSCNC_1 (241U)
 *   DCM_E_VMSCNC_2 (242U)
 *   DCM_E_VMSCNC_3 (243U)
 *   DCM_E_VMSCNC_4 (244U)
 *   DCM_E_VMSCNC_5 (245U)
 *   DCM_E_VMSCNC_6 (246U)
 *   DCM_E_VMSCNC_7 (247U)
 *   DCM_E_VMSCNC_8 (248U)
 *   DCM_E_VMSCNC_9 (249U)
 *   DCM_E_VMSCNC_A (250U)
 *   DCM_E_VMSCNC_B (251U)
 *   DCM_E_VMSCNC_C (252U)
 *   DCM_E_VMSCNC_D (253U)
 *   DCM_E_VMSCNC_E (254U)
 * Dcm_OpStatusType: Enumeration of integer in interval [0...64] with enumerators
 *   DCM_INITIAL (0U)
 *   DCM_PENDING (1U)
 *   DCM_CANCEL (2U)
 *   DCM_FORCE_RCRRP_OK (3U)
 *   DCM_FORCE_RCRRP_NOT_OK (64U)
 * Dcm_ProtocolType: Enumeration of integer in interval [0...254] with enumerators
 *   DCM_OBD_ON_CAN (0U)
 *   DCM_OBD_ON_FLEXRAY (1U)
 *   DCM_OBD_ON_IP (2U)
 *   DCM_UDS_ON_CAN (3U)
 *   DCM_UDS_ON_FLEXRAY (4U)
 *   DCM_UDS_ON_IP (5U)
 *   DCM_NO_ACTIVE_PROTOCOL (12U)
 *   DCM_SUPPLIER_1 (240U)
 *   DCM_SUPPLIER_2 (241U)
 *   DCM_SUPPLIER_3 (242U)
 *   DCM_SUPPLIER_4 (243U)
 *   DCM_SUPPLIER_5 (244U)
 *   DCM_SUPPLIER_6 (245U)
 *   DCM_SUPPLIER_7 (246U)
 *   DCM_SUPPLIER_8 (247U)
 *   DCM_SUPPLIER_9 (248U)
 *   DCM_SUPPLIER_10 (249U)
 *   DCM_SUPPLIER_11 (250U)
 *   DCM_SUPPLIER_12 (251U)
 *   DCM_SUPPLIER_13 (252U)
 *   DCM_SUPPLIER_14 (253U)
 *   DCM_SUPPLIER_15 (254U)
 * Dcm_RequestKindType: Enumeration of integer in interval [0...2] with enumerators
 *   DCM_REQ_KIND_NONE (0U)
 *   DCM_REQ_KIND_EXTERNAL (1U)
 *   DCM_REQ_KIND_ROE (2U)
 * Dcm_SecLevelType: Enumeration of integer in interval [0...2] with enumerators
 *   DCM_SEC_LEV_LOCKED (0U)
 *   DCM_SEC_LEV_L1 (1U)
 *   DCM_SEC_LEV_L2 (2U)
 * Dcm_SesCtrlType: Enumeration of integer in interval [0...3] with enumerators
 *   DCM_DEFAULT_SESSION (1U)
 *   DCM_PROGRAMMING_SESSION (2U)
 *   DCM_EXTENDED_DIAGNOSTIC_SESSION (3U)
 *
 * Array Types:
 * ============
 * Dcm_Data13ByteType: Array with 13 element(s) of type uint8
 * Dcm_Data17ByteType: Array with 17 element(s) of type uint8
 * Dcm_Data1ByteType: Array with 1 element(s) of type uint8
 * Dcm_Data2ByteType: Array with 2 element(s) of type uint8
 * Dcm_Data4ByteType: Array with 4 element(s) of type uint8
 * Dcm_StartDataIn_SampleRoutineControl_StartOnly_In_Option1Type: Array with 3 element(s) of type Dcm_StartDataIn_SampleRoutineControl_StartOnly_In_Option1ArrayType
 *
 *********************************************************************************************************************/


#define Dcm_START_SEC_CODE
#include "Dcm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Dcm_MainFunction
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
 *   Std_ReturnType Rte_Switch_DcmCommunicationControl_ComMConf_ComMChannel_CN_CAN00_5e566ad9_DcmCommunicationControl_ComMConf_ComMChannel_CN_CAN00_5e566ad9(Dcm_CommunicationModeType mode)
 *   Modes of Rte_ModeType_DcmCommunicationControl:
 *   - RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NM
 *   - RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM
 *   - RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM_NM
 *   - RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NM
 *   - RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORMAL
 *   - RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORM_NM
 *   - RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NM
 *   - RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM
 *   - RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM_NM
 *   - RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NM
 *   - RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM
 *   - RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM_NM
 *   - RTE_TRANSITION_DcmCommunicationControl
 *   Std_ReturnType Rte_Switch_DcmControlDtcSetting_DcmControlDtcSetting(Dcm_ControlDtcSettingType mode)
 *   Modes of Rte_ModeType_DcmControlDtcSetting:
 *   - RTE_MODE_DcmControlDtcSetting_DISABLEDTCSETTING
 *   - RTE_MODE_DcmControlDtcSetting_ENABLEDTCSETTING
 *   - RTE_TRANSITION_DcmControlDtcSetting
 *   Std_ReturnType Rte_Switch_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(Dcm_DiagnosticSessionControlType mode)
 *   Modes of Rte_ModeType_DcmDiagnosticSessionControl:
 *   - RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION
 *   - RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION
 *   - RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION
 *   - RTE_TRANSITION_DcmDiagnosticSessionControl
 *   Std_ReturnType Rte_Switch_DcmEcuReset_DcmEcuReset(Dcm_EcuResetType mode)
 *   Modes of Rte_ModeType_DcmEcuReset:
 *   - RTE_MODE_DcmEcuReset_EXECUTE
 *   - RTE_MODE_DcmEcuReset_HARD
 *   - RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER
 *   - RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER
 *   - RTE_MODE_DcmEcuReset_KEYONOFF
 *   - RTE_MODE_DcmEcuReset_NONE
 *   - RTE_MODE_DcmEcuReset_SOFT
 *   - RTE_TRANSITION_DcmEcuReset
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DataServices_Boot_Software_Boot_Software_Identification_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_Boot_Software_Boot_Software_Identification_DCM_E_PENDING, RTE_E_DataServices_Boot_Software_Boot_Software_Identification_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_Boot_Software_Boot_Software_Identification_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_Boot_Software_Boot_Software_Identification_DCM_E_PENDING, RTE_E_DataServices_Boot_Software_Boot_Software_Identification_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_Boot_Software_Boot_Software_Identification_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_Boot_Software_Boot_Software_Identification_DCM_E_PENDING, RTE_E_DataServices_Boot_Software_Boot_Software_Identification_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_Boot_Software_NumberOfModules_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_Boot_Software_NumberOfModules_DCM_E_PENDING, RTE_E_DataServices_Boot_Software_NumberOfModules_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_Boot_Software_NumberOfModules_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_Boot_Software_NumberOfModules_DCM_E_PENDING, RTE_E_DataServices_Boot_Software_NumberOfModules_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_Boot_Software_NumberOfModules_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_Boot_Software_NumberOfModules_DCM_E_PENDING, RTE_E_DataServices_Boot_Software_NumberOfModules_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_DCM_E_PENDING, RTE_E_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_DCM_E_PENDING, RTE_E_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_DCM_E_PENDING, RTE_E_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_DevelopmentData_CanDriverVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DevelopmentData_CanDriverVersion_DCM_E_PENDING, RTE_E_DataServices_DevelopmentData_CanDriverVersion_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_DevelopmentData_CanDriverVersion_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DevelopmentData_CanDriverVersion_DCM_E_PENDING, RTE_E_DataServices_DevelopmentData_CanDriverVersion_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_DevelopmentData_CanDriverVersion_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DevelopmentData_CanDriverVersion_DCM_E_PENDING, RTE_E_DataServices_DevelopmentData_CanDriverVersion_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_DevelopmentData_DiagnosticModuleVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DevelopmentData_DiagnosticModuleVersion_DCM_E_PENDING, RTE_E_DataServices_DevelopmentData_DiagnosticModuleVersion_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_DevelopmentData_DiagnosticModuleVersion_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DevelopmentData_DiagnosticModuleVersion_DCM_E_PENDING, RTE_E_DataServices_DevelopmentData_DiagnosticModuleVersion_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_DevelopmentData_DiagnosticModuleVersion_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DevelopmentData_DiagnosticModuleVersion_DCM_E_PENDING, RTE_E_DataServices_DevelopmentData_DiagnosticModuleVersion_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_DevelopmentData_NmVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DevelopmentData_NmVersion_DCM_E_PENDING, RTE_E_DataServices_DevelopmentData_NmVersion_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_DevelopmentData_NmVersion_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DevelopmentData_NmVersion_DCM_E_PENDING, RTE_E_DataServices_DevelopmentData_NmVersion_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_DevelopmentData_NmVersion_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DevelopmentData_NmVersion_DCM_E_PENDING, RTE_E_DataServices_DevelopmentData_NmVersion_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_DevelopmentData_OperatingSystemVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DevelopmentData_OperatingSystemVersion_DCM_E_PENDING, RTE_E_DataServices_DevelopmentData_OperatingSystemVersion_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_DevelopmentData_OperatingSystemVersion_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DevelopmentData_OperatingSystemVersion_DCM_E_PENDING, RTE_E_DataServices_DevelopmentData_OperatingSystemVersion_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_DevelopmentData_OperatingSystemVersion_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DevelopmentData_OperatingSystemVersion_DCM_E_PENDING, RTE_E_DataServices_DevelopmentData_OperatingSystemVersion_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_DevelopmentData_TransportLayerVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DevelopmentData_TransportLayerVersion_DCM_E_PENDING, RTE_E_DataServices_DevelopmentData_TransportLayerVersion_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_DevelopmentData_TransportLayerVersion_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DevelopmentData_TransportLayerVersion_DCM_E_PENDING, RTE_E_DataServices_DevelopmentData_TransportLayerVersion_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_DevelopmentData_TransportLayerVersion_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data2ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DevelopmentData_TransportLayerVersion_DCM_E_PENDING, RTE_E_DataServices_DevelopmentData_TransportLayerVersion_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_EcuIdentification_Part_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_EcuIdentification_Part_Number_DCM_E_PENDING, RTE_E_DataServices_EcuIdentification_Part_Number_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_EcuIdentification_Part_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data13ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_EcuIdentification_Part_Number_DCM_E_PENDING, RTE_E_DataServices_EcuIdentification_Part_Number_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_EcuIdentification_Part_Number_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data13ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_EcuIdentification_Part_Number_DCM_E_PENDING, RTE_E_DataServices_EcuIdentification_Part_Number_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_Hardware_Version_Hardware_Version_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_Hardware_Version_Hardware_Version_Number_DCM_E_PENDING, RTE_E_DataServices_Hardware_Version_Hardware_Version_Number_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_Hardware_Version_Hardware_Version_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_Hardware_Version_Hardware_Version_Number_DCM_E_PENDING, RTE_E_DataServices_Hardware_Version_Hardware_Version_Number_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_Hardware_Version_Hardware_Version_Number_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_Hardware_Version_Hardware_Version_Number_DCM_E_PENDING, RTE_E_DataServices_Hardware_Version_Hardware_Version_Number_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_SampleIoControl_DID_Data_FreezeCurrentState(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_SampleIoControl_DID_Data_DCM_E_PENDING, RTE_E_DataServices_SampleIoControl_DID_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_SampleIoControl_DID_Data_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_SampleIoControl_DID_Data_DCM_E_PENDING, RTE_E_DataServices_SampleIoControl_DID_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_SampleIoControl_DID_Data_ResetToDefault(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_SampleIoControl_DID_Data_DCM_E_PENDING, RTE_E_DataServices_SampleIoControl_DID_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_SampleIoControl_DID_Data_ReturnControlToECU(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_SampleIoControl_DID_Data_DCM_E_PENDING, RTE_E_DataServices_SampleIoControl_DID_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_SampleIoControl_DID_Data_ShortTermAdjustment(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_SampleIoControl_DID_Data_DCM_E_PENDING, RTE_E_DataServices_SampleIoControl_DID_Data_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_SerialNumber_SerialNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_SerialNumber_SerialNumber_DCM_E_PENDING, RTE_E_DataServices_SerialNumber_SerialNumber_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_SerialNumber_SerialNumber_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_SerialNumber_SerialNumber_DCM_E_PENDING, RTE_E_DataServices_SerialNumber_SerialNumber_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_SerialNumber_SerialNumber_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_SerialNumber_SerialNumber_DCM_E_PENDING, RTE_E_DataServices_SerialNumber_SerialNumber_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_Spare_Part_Number_Spare_Part_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_Spare_Part_Number_Spare_Part_Number_DCM_E_PENDING, RTE_E_DataServices_Spare_Part_Number_Spare_Part_Number_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_Spare_Part_Number_Spare_Part_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_Spare_Part_Number_Spare_Part_Number_DCM_E_PENDING, RTE_E_DataServices_Spare_Part_Number_Spare_Part_Number_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_Spare_Part_Number_Spare_Part_Number_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_Spare_Part_Number_Spare_Part_Number_DCM_E_PENDING, RTE_E_DataServices_Spare_Part_Number_Spare_Part_Number_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_Vehicle_Identification_VIN_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_Vehicle_Identification_VIN_DCM_E_PENDING, RTE_E_DataServices_Vehicle_Identification_VIN_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_Vehicle_Identification_VIN_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data17ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_Vehicle_Identification_VIN_DCM_E_PENDING, RTE_E_DataServices_Vehicle_Identification_VIN_E_NOT_OK
 *   Std_ReturnType Rte_Call_DataServices_Vehicle_Identification_VIN_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data17ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_Vehicle_Identification_VIN_DCM_E_PENDING, RTE_E_DataServices_Vehicle_Identification_VIN_E_NOT_OK
 *   Std_ReturnType Rte_Call_RoutineServices_SampleRoutineControl_RequestResults(Dcm_OpStatusType OpStatus, Dcm_RequestDataOut_SampleRoutineControl_Out_ResultType *Out_Result, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoutineServices_SampleRoutineControl_DCM_E_FORCE_RCRRP, RTE_E_RoutineServices_SampleRoutineControl_DCM_E_PENDING, RTE_E_RoutineServices_SampleRoutineControl_E_NOT_OK
 *   Std_ReturnType Rte_Call_RoutineServices_SampleRoutineControl_Start(Dcm_StartDataIn_SampleRoutineControl_In_Option0Type In_Option0, Dcm_OpStatusType OpStatus, Dcm_StartDataOut_SampleRoutineControl_Out_InitStateType *Out_InitState, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoutineServices_SampleRoutineControl_DCM_E_FORCE_RCRRP, RTE_E_RoutineServices_SampleRoutineControl_DCM_E_PENDING, RTE_E_RoutineServices_SampleRoutineControl_E_NOT_OK
 *   Std_ReturnType Rte_Call_RoutineServices_SampleRoutineControl_Stop(Dcm_OpStatusType OpStatus, Dcm_StopDataOut_SampleRoutineControl_Out_StopStateType *Out_StopState, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoutineServices_SampleRoutineControl_DCM_E_FORCE_RCRRP, RTE_E_RoutineServices_SampleRoutineControl_DCM_E_PENDING, RTE_E_RoutineServices_SampleRoutineControl_E_NOT_OK
 *   Std_ReturnType Rte_Call_RoutineServices_SampleRoutineControl_StartOnly_RequestResults(Dcm_OpStatusType OpStatus, Dcm_RequestDataOut_SampleRoutineControl_StartOnly_Out_ResultType *Out_Result, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoutineServices_SampleRoutineControl_StartOnly_DCM_E_FORCE_RCRRP, RTE_E_RoutineServices_SampleRoutineControl_StartOnly_DCM_E_PENDING, RTE_E_RoutineServices_SampleRoutineControl_StartOnly_E_NOT_OK
 *   Std_ReturnType Rte_Call_RoutineServices_SampleRoutineControl_StartOnly_Start(const Dcm_StartDataIn_SampleRoutineControl_StartOnly_In_Option1ArrayType *In_Option1, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument In_Option1: Dcm_StartDataIn_SampleRoutineControl_StartOnly_In_Option1ArrayType* is of type Dcm_StartDataIn_SampleRoutineControl_StartOnly_In_Option1Type
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoutineServices_SampleRoutineControl_StartOnly_DCM_E_FORCE_RCRRP, RTE_E_RoutineServices_SampleRoutineControl_StartOnly_DCM_E_PENDING, RTE_E_RoutineServices_SampleRoutineControl_StartOnly_E_NOT_OK
 *   Std_ReturnType Rte_Call_SecurityAccess_Level_3_CompareKey(const uint8 *Key, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Key: uint8* is of type Dcm_Data2ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecurityAccess_Level_3_DCM_E_COMPARE_KEY_FAILED, RTE_E_SecurityAccess_Level_3_DCM_E_PENDING, RTE_E_SecurityAccess_Level_3_E_NOT_OK
 *   Std_ReturnType Rte_Call_SecurityAccess_Level_3_GetSeed(Dcm_OpStatusType OpStatus, uint8 *Seed, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Seed: uint8* is of type Dcm_Data2ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecurityAccess_Level_3_DCM_E_PENDING, RTE_E_SecurityAccess_Level_3_E_NOT_OK
 *   Std_ReturnType Rte_Call_SecurityAccess_UnlockedL1_CompareKey(const uint8 *Key, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Key: uint8* is of type Dcm_Data4ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecurityAccess_UnlockedL1_DCM_E_COMPARE_KEY_FAILED, RTE_E_SecurityAccess_UnlockedL1_DCM_E_PENDING, RTE_E_SecurityAccess_UnlockedL1_E_NOT_OK
 *   Std_ReturnType Rte_Call_SecurityAccess_UnlockedL1_GetSeed(Dcm_OpStatusType OpStatus, uint8 *Seed, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Seed: uint8* is of type Dcm_Data4ByteType
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecurityAccess_UnlockedL1_DCM_E_PENDING, RTE_E_SecurityAccess_UnlockedL1_E_NOT_OK
 *
 * Status Interfaces:
 * ==================
 *   Mode Switch Acknowledge:
 *   -------------------------
 *   Std_ReturnType Rte_SwitchAck_DcmEcuReset_DcmEcuReset(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Dcm_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Dcm_CODE) Dcm_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dcm_MainFunction
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error;

  Dcm_NegativeResponseCodeType Call_DataServices_Boot_Software_Boot_Software_Identification_ConditionCheckRead_ErrorCode = 0U;
  Dcm_Data4ByteType Call_DataServices_Boot_Software_Boot_Software_Identification_ReadData_Data = {
  0U, 0U, 0U, 0U
};
  Dcm_Data4ByteType Call_DataServices_Boot_Software_Boot_Software_Identification_WriteData_Data = {
  0U, 0U, 0U, 0U
};
  Dcm_NegativeResponseCodeType Call_DataServices_Boot_Software_Boot_Software_Identification_WriteData_ErrorCode = 0U;
  Dcm_NegativeResponseCodeType Call_DataServices_Boot_Software_NumberOfModules_ConditionCheckRead_ErrorCode = 0U;
  Dcm_Data1ByteType Call_DataServices_Boot_Software_NumberOfModules_ReadData_Data = {
  0U
};
  Dcm_Data1ByteType Call_DataServices_Boot_Software_NumberOfModules_WriteData_Data = {
  0U
};
  Dcm_NegativeResponseCodeType Call_DataServices_Boot_Software_NumberOfModules_WriteData_ErrorCode = 0U;
  Dcm_NegativeResponseCodeType Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_ConditionCheckRead_ErrorCode = 0U;
  Dcm_Data2ByteType Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_ReadData_Data = {
  0U, 0U
};
  Dcm_Data2ByteType Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_WriteData_Data = {
  0U, 0U
};
  Dcm_NegativeResponseCodeType Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_WriteData_ErrorCode = 0U;
  Dcm_NegativeResponseCodeType Call_DataServices_DevelopmentData_CanDriverVersion_ConditionCheckRead_ErrorCode = 0U;
  Dcm_Data2ByteType Call_DataServices_DevelopmentData_CanDriverVersion_ReadData_Data = {
  0U, 0U
};
  Dcm_Data2ByteType Call_DataServices_DevelopmentData_CanDriverVersion_WriteData_Data = {
  0U, 0U
};
  Dcm_NegativeResponseCodeType Call_DataServices_DevelopmentData_CanDriverVersion_WriteData_ErrorCode = 0U;
  Dcm_NegativeResponseCodeType Call_DataServices_DevelopmentData_DiagnosticModuleVersion_ConditionCheckRead_ErrorCode = 0U;
  Dcm_Data2ByteType Call_DataServices_DevelopmentData_DiagnosticModuleVersion_ReadData_Data = {
  0U, 0U
};
  Dcm_Data2ByteType Call_DataServices_DevelopmentData_DiagnosticModuleVersion_WriteData_Data = {
  0U, 0U
};
  Dcm_NegativeResponseCodeType Call_DataServices_DevelopmentData_DiagnosticModuleVersion_WriteData_ErrorCode = 0U;
  Dcm_NegativeResponseCodeType Call_DataServices_DevelopmentData_NmVersion_ConditionCheckRead_ErrorCode = 0U;
  Dcm_Data2ByteType Call_DataServices_DevelopmentData_NmVersion_ReadData_Data = {
  0U, 0U
};
  Dcm_Data2ByteType Call_DataServices_DevelopmentData_NmVersion_WriteData_Data = {
  0U, 0U
};
  Dcm_NegativeResponseCodeType Call_DataServices_DevelopmentData_NmVersion_WriteData_ErrorCode = 0U;
  Dcm_NegativeResponseCodeType Call_DataServices_DevelopmentData_OperatingSystemVersion_ConditionCheckRead_ErrorCode = 0U;
  Dcm_Data2ByteType Call_DataServices_DevelopmentData_OperatingSystemVersion_ReadData_Data = {
  0U, 0U
};
  Dcm_Data2ByteType Call_DataServices_DevelopmentData_OperatingSystemVersion_WriteData_Data = {
  0U, 0U
};
  Dcm_NegativeResponseCodeType Call_DataServices_DevelopmentData_OperatingSystemVersion_WriteData_ErrorCode = 0U;
  Dcm_NegativeResponseCodeType Call_DataServices_DevelopmentData_TransportLayerVersion_ConditionCheckRead_ErrorCode = 0U;
  Dcm_Data2ByteType Call_DataServices_DevelopmentData_TransportLayerVersion_ReadData_Data = {
  0U, 0U
};
  Dcm_Data2ByteType Call_DataServices_DevelopmentData_TransportLayerVersion_WriteData_Data = {
  0U, 0U
};
  Dcm_NegativeResponseCodeType Call_DataServices_DevelopmentData_TransportLayerVersion_WriteData_ErrorCode = 0U;
  Dcm_NegativeResponseCodeType Call_DataServices_EcuIdentification_Part_Number_ConditionCheckRead_ErrorCode = 0U;
  Dcm_Data13ByteType Call_DataServices_EcuIdentification_Part_Number_ReadData_Data = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Dcm_Data13ByteType Call_DataServices_EcuIdentification_Part_Number_WriteData_Data = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Dcm_NegativeResponseCodeType Call_DataServices_EcuIdentification_Part_Number_WriteData_ErrorCode = 0U;
  Dcm_NegativeResponseCodeType Call_DataServices_Hardware_Version_Hardware_Version_Number_ConditionCheckRead_ErrorCode = 0U;
  Dcm_Data4ByteType Call_DataServices_Hardware_Version_Hardware_Version_Number_ReadData_Data = {
  0U, 0U, 0U, 0U
};
  Dcm_Data4ByteType Call_DataServices_Hardware_Version_Hardware_Version_Number_WriteData_Data = {
  0U, 0U, 0U, 0U
};
  Dcm_NegativeResponseCodeType Call_DataServices_Hardware_Version_Hardware_Version_Number_WriteData_ErrorCode = 0U;
  Dcm_NegativeResponseCodeType Call_DataServices_SampleIoControl_DID_Data_FreezeCurrentState_ErrorCode = 0U;
  Dcm_Data4ByteType Call_DataServices_SampleIoControl_DID_Data_ReadData_Data = {
  0U, 0U, 0U, 0U
};
  Dcm_NegativeResponseCodeType Call_DataServices_SampleIoControl_DID_Data_ResetToDefault_ErrorCode = 0U;
  Dcm_NegativeResponseCodeType Call_DataServices_SampleIoControl_DID_Data_ReturnControlToECU_ErrorCode = 0U;
  Dcm_Data4ByteType Call_DataServices_SampleIoControl_DID_Data_ShortTermAdjustment_Data = {
  0U, 0U, 0U, 0U
};
  Dcm_NegativeResponseCodeType Call_DataServices_SampleIoControl_DID_Data_ShortTermAdjustment_ErrorCode = 0U;
  Dcm_NegativeResponseCodeType Call_DataServices_SerialNumber_SerialNumber_ConditionCheckRead_ErrorCode = 0U;
  Dcm_Data4ByteType Call_DataServices_SerialNumber_SerialNumber_ReadData_Data = {
  0U, 0U, 0U, 0U
};
  Dcm_Data4ByteType Call_DataServices_SerialNumber_SerialNumber_WriteData_Data = {
  0U, 0U, 0U, 0U
};
  Dcm_NegativeResponseCodeType Call_DataServices_SerialNumber_SerialNumber_WriteData_ErrorCode = 0U;
  Dcm_NegativeResponseCodeType Call_DataServices_Spare_Part_Number_Spare_Part_Number_ConditionCheckRead_ErrorCode = 0U;
  Dcm_Data4ByteType Call_DataServices_Spare_Part_Number_Spare_Part_Number_ReadData_Data = {
  0U, 0U, 0U, 0U
};
  Dcm_Data4ByteType Call_DataServices_Spare_Part_Number_Spare_Part_Number_WriteData_Data = {
  0U, 0U, 0U, 0U
};
  Dcm_NegativeResponseCodeType Call_DataServices_Spare_Part_Number_Spare_Part_Number_WriteData_ErrorCode = 0U;
  Dcm_NegativeResponseCodeType Call_DataServices_Vehicle_Identification_VIN_ConditionCheckRead_ErrorCode = 0U;
  Dcm_Data17ByteType Call_DataServices_Vehicle_Identification_VIN_ReadData_Data = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Dcm_Data17ByteType Call_DataServices_Vehicle_Identification_VIN_WriteData_Data = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Dcm_NegativeResponseCodeType Call_DataServices_Vehicle_Identification_VIN_WriteData_ErrorCode = 0U;
  Dcm_RequestDataOut_SampleRoutineControl_Out_ResultType Call_RoutineServices_SampleRoutineControl_RequestResults_Out_Result = 0U;
  Dcm_NegativeResponseCodeType Call_RoutineServices_SampleRoutineControl_RequestResults_ErrorCode = 0U;
  Dcm_StartDataOut_SampleRoutineControl_Out_InitStateType Call_RoutineServices_SampleRoutineControl_Start_Out_InitState = 0U;
  Dcm_NegativeResponseCodeType Call_RoutineServices_SampleRoutineControl_Start_ErrorCode = 0U;
  Dcm_StopDataOut_SampleRoutineControl_Out_StopStateType Call_RoutineServices_SampleRoutineControl_Stop_Out_StopState = 0U;
  Dcm_NegativeResponseCodeType Call_RoutineServices_SampleRoutineControl_Stop_ErrorCode = 0U;
  Dcm_RequestDataOut_SampleRoutineControl_StartOnly_Out_ResultType Call_RoutineServices_SampleRoutineControl_StartOnly_RequestResults_Out_Result = 0U;
  Dcm_NegativeResponseCodeType Call_RoutineServices_SampleRoutineControl_StartOnly_RequestResults_ErrorCode = 0U;
  Dcm_StartDataIn_SampleRoutineControl_StartOnly_In_Option1Type Call_RoutineServices_SampleRoutineControl_StartOnly_Start_In_Option1 = {
  0U, 0U, 0U
};
  Dcm_NegativeResponseCodeType Call_RoutineServices_SampleRoutineControl_StartOnly_Start_ErrorCode = 0U;
  Dcm_Data2ByteType Call_SecurityAccess_Level_3_CompareKey_Key = {
  0U, 0U
};
  Dcm_NegativeResponseCodeType Call_SecurityAccess_Level_3_CompareKey_ErrorCode = 0U;
  Dcm_Data2ByteType Call_SecurityAccess_Level_3_GetSeed_Seed = {
  0U, 0U
};
  Dcm_NegativeResponseCodeType Call_SecurityAccess_Level_3_GetSeed_ErrorCode = 0U;
  Dcm_Data4ByteType Call_SecurityAccess_UnlockedL1_CompareKey_Key = {
  0U, 0U, 0U, 0U
};
  Dcm_NegativeResponseCodeType Call_SecurityAccess_UnlockedL1_CompareKey_ErrorCode = 0U;
  Dcm_Data4ByteType Call_SecurityAccess_UnlockedL1_GetSeed_Seed = {
  0U, 0U, 0U, 0U
};
  Dcm_NegativeResponseCodeType Call_SecurityAccess_UnlockedL1_GetSeed_ErrorCode = 0U;

  /**********************************************************
  * Direct Function Accesses and Take Addresses of Functions
  **********************************************************/

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)Rte_Switch_DcmCommunicationControl_ComMConf_ComMChannel_CN_CAN00_5e566ad9_DcmCommunicationControl_ComMConf_ComMChannel_CN_CAN00_5e566ad9; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Switch_DcmCommunicationControl_ComMConf_ComMChannel_CN_CAN00_5e566ad9_DcmCommunicationControl_ComMConf_ComMChannel_CN_CAN00_5e566ad9(RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM); /* PRQA S 3226, 0315 */ /* MD_Rte_3226, MD_Rte_0315 */
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
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)Rte_Switch_DcmControlDtcSetting_DcmControlDtcSetting; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Switch_DcmControlDtcSetting_DcmControlDtcSetting(RTE_MODE_DcmControlDtcSetting_ENABLEDTCSETTING); /* PRQA S 3226, 0315 */ /* MD_Rte_3226, MD_Rte_0315 */
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
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)Rte_Switch_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Switch_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION); /* PRQA S 3226, 0315 */ /* MD_Rte_3226, MD_Rte_0315 */
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
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)Rte_Switch_DcmEcuReset_DcmEcuReset; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Switch_DcmEcuReset_DcmEcuReset(RTE_MODE_DcmEcuReset_NONE); /* PRQA S 3226, 0315 */ /* MD_Rte_3226, MD_Rte_0315 */
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
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_Boot_Software_Boot_Software_Identification_ConditionCheckRead; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_Boot_Software_Boot_Software_Identification_ConditionCheckRead(0U, &Call_DataServices_Boot_Software_Boot_Software_Identification_ConditionCheckRead_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_Boot_Software_Boot_Software_Identification_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_Boot_Software_Boot_Software_Identification_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_Boot_Software_Boot_Software_Identification_ReadData; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_Boot_Software_Boot_Software_Identification_ReadData(0U, Call_DataServices_Boot_Software_Boot_Software_Identification_ReadData_Data); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_Boot_Software_Boot_Software_Identification_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_Boot_Software_Boot_Software_Identification_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_Boot_Software_Boot_Software_Identification_WriteData; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_Boot_Software_Boot_Software_Identification_WriteData(Call_DataServices_Boot_Software_Boot_Software_Identification_WriteData_Data, 0U, &Call_DataServices_Boot_Software_Boot_Software_Identification_WriteData_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_Boot_Software_Boot_Software_Identification_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_Boot_Software_Boot_Software_Identification_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_Boot_Software_NumberOfModules_ConditionCheckRead; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_Boot_Software_NumberOfModules_ConditionCheckRead(0U, &Call_DataServices_Boot_Software_NumberOfModules_ConditionCheckRead_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_Boot_Software_NumberOfModules_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_Boot_Software_NumberOfModules_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_Boot_Software_NumberOfModules_ReadData; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_Boot_Software_NumberOfModules_ReadData(0U, Call_DataServices_Boot_Software_NumberOfModules_ReadData_Data); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_Boot_Software_NumberOfModules_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_Boot_Software_NumberOfModules_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_Boot_Software_NumberOfModules_WriteData; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_Boot_Software_NumberOfModules_WriteData(Call_DataServices_Boot_Software_NumberOfModules_WriteData_Data, 0U, &Call_DataServices_Boot_Software_NumberOfModules_WriteData_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_Boot_Software_NumberOfModules_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_Boot_Software_NumberOfModules_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_ConditionCheckRead; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_ConditionCheckRead(0U, &Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_ConditionCheckRead_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_ReadData; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_ReadData(0U, Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_ReadData_Data); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_WriteData; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_WriteData(Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_WriteData_Data, 0U, &Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_WriteData_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_DevelopmentData_CanDriverVersion_ConditionCheckRead; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_DevelopmentData_CanDriverVersion_ConditionCheckRead(0U, &Call_DataServices_DevelopmentData_CanDriverVersion_ConditionCheckRead_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_DevelopmentData_CanDriverVersion_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_DevelopmentData_CanDriverVersion_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_DevelopmentData_CanDriverVersion_ReadData; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_DevelopmentData_CanDriverVersion_ReadData(0U, Call_DataServices_DevelopmentData_CanDriverVersion_ReadData_Data); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_DevelopmentData_CanDriverVersion_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_DevelopmentData_CanDriverVersion_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_DevelopmentData_CanDriverVersion_WriteData; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_DevelopmentData_CanDriverVersion_WriteData(Call_DataServices_DevelopmentData_CanDriverVersion_WriteData_Data, 0U, &Call_DataServices_DevelopmentData_CanDriverVersion_WriteData_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_DevelopmentData_CanDriverVersion_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_DevelopmentData_CanDriverVersion_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_DevelopmentData_DiagnosticModuleVersion_ConditionCheckRead; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_DevelopmentData_DiagnosticModuleVersion_ConditionCheckRead(0U, &Call_DataServices_DevelopmentData_DiagnosticModuleVersion_ConditionCheckRead_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_DevelopmentData_DiagnosticModuleVersion_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_DevelopmentData_DiagnosticModuleVersion_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_DevelopmentData_DiagnosticModuleVersion_ReadData; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_DevelopmentData_DiagnosticModuleVersion_ReadData(0U, Call_DataServices_DevelopmentData_DiagnosticModuleVersion_ReadData_Data); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_DevelopmentData_DiagnosticModuleVersion_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_DevelopmentData_DiagnosticModuleVersion_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_DevelopmentData_DiagnosticModuleVersion_WriteData; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_DevelopmentData_DiagnosticModuleVersion_WriteData(Call_DataServices_DevelopmentData_DiagnosticModuleVersion_WriteData_Data, 0U, &Call_DataServices_DevelopmentData_DiagnosticModuleVersion_WriteData_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_DevelopmentData_DiagnosticModuleVersion_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_DevelopmentData_DiagnosticModuleVersion_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_DevelopmentData_NmVersion_ConditionCheckRead; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_DevelopmentData_NmVersion_ConditionCheckRead(0U, &Call_DataServices_DevelopmentData_NmVersion_ConditionCheckRead_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_DevelopmentData_NmVersion_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_DevelopmentData_NmVersion_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_DevelopmentData_NmVersion_ReadData; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_DevelopmentData_NmVersion_ReadData(0U, Call_DataServices_DevelopmentData_NmVersion_ReadData_Data); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_DevelopmentData_NmVersion_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_DevelopmentData_NmVersion_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_DevelopmentData_NmVersion_WriteData; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_DevelopmentData_NmVersion_WriteData(Call_DataServices_DevelopmentData_NmVersion_WriteData_Data, 0U, &Call_DataServices_DevelopmentData_NmVersion_WriteData_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_DevelopmentData_NmVersion_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_DevelopmentData_NmVersion_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_DevelopmentData_OperatingSystemVersion_ConditionCheckRead; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_DevelopmentData_OperatingSystemVersion_ConditionCheckRead(0U, &Call_DataServices_DevelopmentData_OperatingSystemVersion_ConditionCheckRead_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_DevelopmentData_OperatingSystemVersion_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_DevelopmentData_OperatingSystemVersion_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_DevelopmentData_OperatingSystemVersion_ReadData; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_DevelopmentData_OperatingSystemVersion_ReadData(0U, Call_DataServices_DevelopmentData_OperatingSystemVersion_ReadData_Data); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_DevelopmentData_OperatingSystemVersion_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_DevelopmentData_OperatingSystemVersion_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_DevelopmentData_OperatingSystemVersion_WriteData; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_DevelopmentData_OperatingSystemVersion_WriteData(Call_DataServices_DevelopmentData_OperatingSystemVersion_WriteData_Data, 0U, &Call_DataServices_DevelopmentData_OperatingSystemVersion_WriteData_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_DevelopmentData_OperatingSystemVersion_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_DevelopmentData_OperatingSystemVersion_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_DevelopmentData_TransportLayerVersion_ConditionCheckRead; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_DevelopmentData_TransportLayerVersion_ConditionCheckRead(0U, &Call_DataServices_DevelopmentData_TransportLayerVersion_ConditionCheckRead_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_DevelopmentData_TransportLayerVersion_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_DevelopmentData_TransportLayerVersion_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_DevelopmentData_TransportLayerVersion_ReadData; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_DevelopmentData_TransportLayerVersion_ReadData(0U, Call_DataServices_DevelopmentData_TransportLayerVersion_ReadData_Data); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_DevelopmentData_TransportLayerVersion_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_DevelopmentData_TransportLayerVersion_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_DevelopmentData_TransportLayerVersion_WriteData; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_DevelopmentData_TransportLayerVersion_WriteData(Call_DataServices_DevelopmentData_TransportLayerVersion_WriteData_Data, 0U, &Call_DataServices_DevelopmentData_TransportLayerVersion_WriteData_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_DevelopmentData_TransportLayerVersion_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_DevelopmentData_TransportLayerVersion_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_EcuIdentification_Part_Number_ConditionCheckRead; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_EcuIdentification_Part_Number_ConditionCheckRead(0U, &Call_DataServices_EcuIdentification_Part_Number_ConditionCheckRead_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_EcuIdentification_Part_Number_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_EcuIdentification_Part_Number_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_EcuIdentification_Part_Number_ReadData; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_EcuIdentification_Part_Number_ReadData(0U, Call_DataServices_EcuIdentification_Part_Number_ReadData_Data); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_EcuIdentification_Part_Number_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_EcuIdentification_Part_Number_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_EcuIdentification_Part_Number_WriteData; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_EcuIdentification_Part_Number_WriteData(Call_DataServices_EcuIdentification_Part_Number_WriteData_Data, 0U, &Call_DataServices_EcuIdentification_Part_Number_WriteData_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_EcuIdentification_Part_Number_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_EcuIdentification_Part_Number_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_Hardware_Version_Hardware_Version_Number_ConditionCheckRead; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_Hardware_Version_Hardware_Version_Number_ConditionCheckRead(0U, &Call_DataServices_Hardware_Version_Hardware_Version_Number_ConditionCheckRead_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_Hardware_Version_Hardware_Version_Number_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_Hardware_Version_Hardware_Version_Number_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_Hardware_Version_Hardware_Version_Number_ReadData; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_Hardware_Version_Hardware_Version_Number_ReadData(0U, Call_DataServices_Hardware_Version_Hardware_Version_Number_ReadData_Data); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_Hardware_Version_Hardware_Version_Number_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_Hardware_Version_Hardware_Version_Number_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_Hardware_Version_Hardware_Version_Number_WriteData; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_Hardware_Version_Hardware_Version_Number_WriteData(Call_DataServices_Hardware_Version_Hardware_Version_Number_WriteData_Data, 0U, &Call_DataServices_Hardware_Version_Hardware_Version_Number_WriteData_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_Hardware_Version_Hardware_Version_Number_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_Hardware_Version_Hardware_Version_Number_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_SampleIoControl_DID_Data_FreezeCurrentState; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_SampleIoControl_DID_Data_FreezeCurrentState(0U, &Call_DataServices_SampleIoControl_DID_Data_FreezeCurrentState_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_SampleIoControl_DID_Data_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_SampleIoControl_DID_Data_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_SampleIoControl_DID_Data_ReadData; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_SampleIoControl_DID_Data_ReadData(0U, Call_DataServices_SampleIoControl_DID_Data_ReadData_Data); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_SampleIoControl_DID_Data_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_SampleIoControl_DID_Data_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_SampleIoControl_DID_Data_ResetToDefault; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_SampleIoControl_DID_Data_ResetToDefault(0U, &Call_DataServices_SampleIoControl_DID_Data_ResetToDefault_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_SampleIoControl_DID_Data_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_SampleIoControl_DID_Data_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_SampleIoControl_DID_Data_ReturnControlToECU; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_SampleIoControl_DID_Data_ReturnControlToECU(0U, &Call_DataServices_SampleIoControl_DID_Data_ReturnControlToECU_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_SampleIoControl_DID_Data_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_SampleIoControl_DID_Data_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_SampleIoControl_DID_Data_ShortTermAdjustment; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_SampleIoControl_DID_Data_ShortTermAdjustment(Call_DataServices_SampleIoControl_DID_Data_ShortTermAdjustment_Data, 0U, &Call_DataServices_SampleIoControl_DID_Data_ShortTermAdjustment_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_SampleIoControl_DID_Data_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_SampleIoControl_DID_Data_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_SerialNumber_SerialNumber_ConditionCheckRead; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_SerialNumber_SerialNumber_ConditionCheckRead(0U, &Call_DataServices_SerialNumber_SerialNumber_ConditionCheckRead_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_SerialNumber_SerialNumber_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_SerialNumber_SerialNumber_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_SerialNumber_SerialNumber_ReadData; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_SerialNumber_SerialNumber_ReadData(0U, Call_DataServices_SerialNumber_SerialNumber_ReadData_Data); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_SerialNumber_SerialNumber_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_SerialNumber_SerialNumber_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_SerialNumber_SerialNumber_WriteData; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_SerialNumber_SerialNumber_WriteData(Call_DataServices_SerialNumber_SerialNumber_WriteData_Data, 0U, &Call_DataServices_SerialNumber_SerialNumber_WriteData_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_SerialNumber_SerialNumber_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_SerialNumber_SerialNumber_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_Spare_Part_Number_Spare_Part_Number_ConditionCheckRead; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_Spare_Part_Number_Spare_Part_Number_ConditionCheckRead(0U, &Call_DataServices_Spare_Part_Number_Spare_Part_Number_ConditionCheckRead_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_Spare_Part_Number_Spare_Part_Number_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_Spare_Part_Number_Spare_Part_Number_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_Spare_Part_Number_Spare_Part_Number_ReadData; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_Spare_Part_Number_Spare_Part_Number_ReadData(0U, Call_DataServices_Spare_Part_Number_Spare_Part_Number_ReadData_Data); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_Spare_Part_Number_Spare_Part_Number_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_Spare_Part_Number_Spare_Part_Number_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_Spare_Part_Number_Spare_Part_Number_WriteData; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_Spare_Part_Number_Spare_Part_Number_WriteData(Call_DataServices_Spare_Part_Number_Spare_Part_Number_WriteData_Data, 0U, &Call_DataServices_Spare_Part_Number_Spare_Part_Number_WriteData_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_Spare_Part_Number_Spare_Part_Number_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_Spare_Part_Number_Spare_Part_Number_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_Vehicle_Identification_VIN_ConditionCheckRead; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_Vehicle_Identification_VIN_ConditionCheckRead(0U, &Call_DataServices_Vehicle_Identification_VIN_ConditionCheckRead_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_Vehicle_Identification_VIN_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_Vehicle_Identification_VIN_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_Vehicle_Identification_VIN_ReadData; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_Vehicle_Identification_VIN_ReadData(0U, Call_DataServices_Vehicle_Identification_VIN_ReadData_Data); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_Vehicle_Identification_VIN_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_Vehicle_Identification_VIN_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_DataServices_Vehicle_Identification_VIN_WriteData; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_DataServices_Vehicle_Identification_VIN_WriteData(Call_DataServices_Vehicle_Identification_VIN_WriteData_Data, 0U, &Call_DataServices_Vehicle_Identification_VIN_WriteData_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_DataServices_Vehicle_Identification_VIN_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_DataServices_Vehicle_Identification_VIN_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_RoutineServices_SampleRoutineControl_RequestResults; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_RoutineServices_SampleRoutineControl_RequestResults(0U, &Call_RoutineServices_SampleRoutineControl_RequestResults_Out_Result, &Call_RoutineServices_SampleRoutineControl_RequestResults_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_RoutineServices_SampleRoutineControl_DCM_E_FORCE_RCRRP:
      fct_error = TRUE;
      break;
    case RTE_E_RoutineServices_SampleRoutineControl_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_RoutineServices_SampleRoutineControl_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_RoutineServices_SampleRoutineControl_Start; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_RoutineServices_SampleRoutineControl_Start(0U, 0U, &Call_RoutineServices_SampleRoutineControl_Start_Out_InitState, &Call_RoutineServices_SampleRoutineControl_Start_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_RoutineServices_SampleRoutineControl_DCM_E_FORCE_RCRRP:
      fct_error = TRUE;
      break;
    case RTE_E_RoutineServices_SampleRoutineControl_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_RoutineServices_SampleRoutineControl_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_RoutineServices_SampleRoutineControl_Stop; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_RoutineServices_SampleRoutineControl_Stop(0U, &Call_RoutineServices_SampleRoutineControl_Stop_Out_StopState, &Call_RoutineServices_SampleRoutineControl_Stop_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_RoutineServices_SampleRoutineControl_DCM_E_FORCE_RCRRP:
      fct_error = TRUE;
      break;
    case RTE_E_RoutineServices_SampleRoutineControl_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_RoutineServices_SampleRoutineControl_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_RoutineServices_SampleRoutineControl_StartOnly_RequestResults; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_RoutineServices_SampleRoutineControl_StartOnly_RequestResults(0U, &Call_RoutineServices_SampleRoutineControl_StartOnly_RequestResults_Out_Result, &Call_RoutineServices_SampleRoutineControl_StartOnly_RequestResults_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_RoutineServices_SampleRoutineControl_StartOnly_DCM_E_FORCE_RCRRP:
      fct_error = TRUE;
      break;
    case RTE_E_RoutineServices_SampleRoutineControl_StartOnly_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_RoutineServices_SampleRoutineControl_StartOnly_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_RoutineServices_SampleRoutineControl_StartOnly_Start; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_RoutineServices_SampleRoutineControl_StartOnly_Start(Call_RoutineServices_SampleRoutineControl_StartOnly_Start_In_Option1, 0U, &Call_RoutineServices_SampleRoutineControl_StartOnly_Start_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_RoutineServices_SampleRoutineControl_StartOnly_DCM_E_FORCE_RCRRP:
      fct_error = TRUE;
      break;
    case RTE_E_RoutineServices_SampleRoutineControl_StartOnly_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_RoutineServices_SampleRoutineControl_StartOnly_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_SecurityAccess_Level_3_CompareKey; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_SecurityAccess_Level_3_CompareKey(Call_SecurityAccess_Level_3_CompareKey_Key, 0U, &Call_SecurityAccess_Level_3_CompareKey_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_SecurityAccess_Level_3_DCM_E_COMPARE_KEY_FAILED:
      fct_error = TRUE;
      break;
    case RTE_E_SecurityAccess_Level_3_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_SecurityAccess_Level_3_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_SecurityAccess_Level_3_GetSeed; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_SecurityAccess_Level_3_GetSeed(0U, Call_SecurityAccess_Level_3_GetSeed_Seed, &Call_SecurityAccess_Level_3_GetSeed_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_SecurityAccess_Level_3_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_SecurityAccess_Level_3_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_SecurityAccess_UnlockedL1_CompareKey; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_SecurityAccess_UnlockedL1_CompareKey(Call_SecurityAccess_UnlockedL1_CompareKey_Key, 0U, &Call_SecurityAccess_UnlockedL1_CompareKey_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_SecurityAccess_UnlockedL1_DCM_E_COMPARE_KEY_FAILED:
      fct_error = TRUE;
      break;
    case RTE_E_SecurityAccess_UnlockedL1_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_SecurityAccess_UnlockedL1_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)TSC_Dcm_Rte_Call_SecurityAccess_UnlockedL1_GetSeed; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_Call_SecurityAccess_UnlockedL1_GetSeed(0U, Call_SecurityAccess_UnlockedL1_GetSeed_Seed, &Call_SecurityAccess_UnlockedL1_GetSeed_ErrorCode); /* PRQA S 0315, 3226 */ /* MD_Rte_0315, MD_Rte_3226 */
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
    case RTE_E_SecurityAccess_UnlockedL1_DCM_E_PENDING:
      fct_error = TRUE;
      break;
    case RTE_E_SecurityAccess_UnlockedL1_E_NOT_OK:
      fct_error = TRUE;
      break;
  }

  {
    FncPtrType Dcm_FctPtr; /* PRQA S 3408 */ /* MD_Rte_TestCode */
    Dcm_FctPtr = (FncPtrType)Rte_SwitchAck_DcmEcuReset_DcmEcuReset; /* PRQA S 0313 */ /* MD_Rte_TestCode */
  }
  fct_status = TSC_Dcm_Rte_SwitchAck_DcmEcuReset_DcmEcuReset(); /* PRQA S 3226, 0315 */ /* MD_Rte_3226, MD_Rte_0315 */
  switch (fct_status)
  {
    case RTE_E_NO_DATA:
      fct_error = TRUE;
      break;
    case RTE_E_TRANSMIT_ACK:
      fct_error = TRUE;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = TRUE;
      break;
  }

 /* PRQA S 3226, 1863 L1 */ /* MD_Rte_Os, MD_Rte_Os */
  TSC_Dcm_SchM_Enter_Dcm_DCM_EXCLUSIVE_AREA_0();
  TSC_Dcm_SchM_Exit_Dcm_DCM_EXCLUSIVE_AREA_0();
/* PRQA L:L1 */

  Dcm_TestDefines(); /* PRQA S 2987 */ /* MD_Rte_2987 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetActiveProtocol
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetActiveProtocol> of PortPrototype <DCMServices>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dcm_GetActiveProtocol(Dcm_ProtocolType *ActiveProtocol)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DCMServices_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetActiveProtocol_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dcm_CODE) Dcm_GetActiveProtocol(P2VAR(Dcm_ProtocolType, AUTOMATIC, RTE_DCM_APPL_VAR) ActiveProtocol) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dcm_GetActiveProtocol (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetRequestKind
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetRequestKind> of PortPrototype <DCMServices>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dcm_GetRequestKind(uint16 TesterSourceAddress, Dcm_RequestKindType *RequestKind)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DCMServices_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetRequestKind_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dcm_CODE) Dcm_GetRequestKind(uint16 TesterSourceAddress, P2VAR(Dcm_RequestKindType, AUTOMATIC, RTE_DCM_APPL_VAR) RequestKind) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dcm_GetRequestKind (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetSecurityLevel
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetSecurityLevel> of PortPrototype <DCMServices>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dcm_GetSecurityLevel(Dcm_SecLevelType *SecLevel)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DCMServices_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetSecurityLevel_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dcm_CODE) Dcm_GetSecurityLevel(P2VAR(Dcm_SecLevelType, AUTOMATIC, RTE_DCM_APPL_VAR) SecLevel) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dcm_GetSecurityLevel (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: GetSesCtrlType
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetSesCtrlType> of PortPrototype <DCMServices>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dcm_GetSesCtrlType(Dcm_SesCtrlType *SesCtrlType)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DCMServices_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: GetSesCtrlType_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dcm_CODE) Dcm_GetSesCtrlType(P2VAR(Dcm_SesCtrlType, AUTOMATIC, RTE_DCM_APPL_VAR) SesCtrlType) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dcm_GetSesCtrlType (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: ResetToDefaultSession
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ResetToDefaultSession> of PortPrototype <DCMServices>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dcm_ResetToDefaultSession(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DCMServices_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: ResetToDefaultSession_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dcm_CODE) Dcm_ResetToDefaultSession(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dcm_ResetToDefaultSession (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SetActiveDiagnostic
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetActiveDiagnostic> of PortPrototype <DCMServices>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Dcm_SetActiveDiagnostic(boolean active)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DCMServices_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: SetActiveDiagnostic_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Dcm_CODE) Dcm_SetActiveDiagnostic(boolean active) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dcm_SetActiveDiagnostic (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Dcm_STOP_SEC_CODE
#include "Dcm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void Dcm_TestDefines(void)
{
  /* Enumeration Data Types */

  Dcm_CommunicationModeType Test_Dcm_CommunicationModeType_V_1 = DCM_ENABLE_RX_TX_NORM;
  Dcm_CommunicationModeType Test_Dcm_CommunicationModeType_V_2 = DCM_ENABLE_RX_DISABLE_TX_NORM;
  Dcm_CommunicationModeType Test_Dcm_CommunicationModeType_V_3 = DCM_DISABLE_RX_ENABLE_TX_NORM;
  Dcm_CommunicationModeType Test_Dcm_CommunicationModeType_V_4 = DCM_DISABLE_RX_TX_NORMAL;
  Dcm_CommunicationModeType Test_Dcm_CommunicationModeType_V_5 = DCM_ENABLE_RX_TX_NM;
  Dcm_CommunicationModeType Test_Dcm_CommunicationModeType_V_6 = DCM_ENABLE_RX_DISABLE_TX_NM;
  Dcm_CommunicationModeType Test_Dcm_CommunicationModeType_V_7 = DCM_DISABLE_RX_ENABLE_TX_NM;
  Dcm_CommunicationModeType Test_Dcm_CommunicationModeType_V_8 = DCM_DISABLE_RX_TX_NM;
  Dcm_CommunicationModeType Test_Dcm_CommunicationModeType_V_9 = DCM_ENABLE_RX_TX_NORM_NM;
  Dcm_CommunicationModeType Test_Dcm_CommunicationModeType_V_10 = DCM_ENABLE_RX_DISABLE_TX_NORM_NM;
  Dcm_CommunicationModeType Test_Dcm_CommunicationModeType_V_11 = DCM_DISABLE_RX_ENABLE_TX_NORM_NM;
  Dcm_CommunicationModeType Test_Dcm_CommunicationModeType_V_12 = DCM_DISABLE_RX_TX_NORM_NM;

  Dcm_ConfirmationStatusType Test_Dcm_ConfirmationStatusType_V_1 = DCM_RES_POS_OK;
  Dcm_ConfirmationStatusType Test_Dcm_ConfirmationStatusType_V_2 = DCM_RES_POS_NOT_OK;
  Dcm_ConfirmationStatusType Test_Dcm_ConfirmationStatusType_V_3 = DCM_RES_NEG_OK;
  Dcm_ConfirmationStatusType Test_Dcm_ConfirmationStatusType_V_4 = DCM_RES_NEG_NOT_OK;

  Dcm_ControlDtcSettingType Test_Dcm_ControlDtcSettingType_V_1 = DCM_ENUM_ENABLEDTCSETTING;
  Dcm_ControlDtcSettingType Test_Dcm_ControlDtcSettingType_V_2 = DCM_ENUM_DISABLEDTCSETTING;

  Dcm_DiagnosticSessionControlType Test_Dcm_DiagnosticSessionControlType_V_1 = DCM_ENUM_DEFAULT_SESSION;
  Dcm_DiagnosticSessionControlType Test_Dcm_DiagnosticSessionControlType_V_2 = DCM_ENUM_PROGRAMMING_SESSION;
  Dcm_DiagnosticSessionControlType Test_Dcm_DiagnosticSessionControlType_V_3 = DCM_ENUM_EXTENDED_SESSION;

  Dcm_EcuResetType Test_Dcm_EcuResetType_V_1 = DCM_ENUM_NONE;
  Dcm_EcuResetType Test_Dcm_EcuResetType_V_2 = DCM_ENUM_HARD;
  Dcm_EcuResetType Test_Dcm_EcuResetType_V_3 = DCM_ENUM_KEYONOFF;
  Dcm_EcuResetType Test_Dcm_EcuResetType_V_4 = DCM_ENUM_SOFT;
  Dcm_EcuResetType Test_Dcm_EcuResetType_V_5 = DCM_ENUM_JUMPTOBOOTLOADER;
  Dcm_EcuResetType Test_Dcm_EcuResetType_V_6 = DCM_ENUM_JUMPTOSYSSUPPLIERBOOTLOADER;
  Dcm_EcuResetType Test_Dcm_EcuResetType_V_7 = DCM_ENUM_EXECUTE;

  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_1 = DCM_E_POSITIVERESPONSE;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_2 = DCM_E_GENERALREJECT;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_3 = DCM_E_SERVICENOTSUPPORTED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_4 = DCM_E_SUBFUNCTIONNOTSUPPORTED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_5 = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_6 = DCM_E_RESPONSETOOLONG;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_7 = DCM_E_BUSYREPEATREQUEST;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_8 = DCM_E_CONDITIONSNOTCORRECT;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_9 = DCM_E_REQUESTSEQUENCEERROR;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_10 = DCM_E_NORESPONSEFROMSUBNETCOMPONENT;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_11 = DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_12 = DCM_E_REQUESTOUTOFRANGE;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_13 = DCM_E_SECURITYACCESSDENIED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_14 = DCM_E_AUTHENTICATIONREQUIRED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_15 = DCM_E_INVALIDKEY;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_16 = DCM_E_EXCEEDNUMBEROFATTEMPTS;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_17 = DCM_E_REQUIREDTIMEDELAYNOTEXPIRED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_18 = DCM_E_CVF_INVALIDTIMEPERIOD;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_19 = DCM_E_CVF_INVALIDSIGNATURE;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_20 = DCM_E_CVF_INVALIDCHAINOFTRUST;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_21 = DCM_E_CVF_INVALIDTYPE;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_22 = DCM_E_CVF_INVALIDFORMAT;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_23 = DCM_E_CVF_INVALIDCONTENT;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_24 = DCM_E_CVF_INVALIDSCOPE;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_25 = DCM_E_CVF_INVALIDCERTIFICATEREVOKED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_26 = DCM_E_OWNERSHIPVERIFICATIONFAILED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_27 = DCM_E_CHALLENGECALCULATIONFAILED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_28 = DCM_E_UPLOADDOWNLOADNOTACCEPTED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_29 = DCM_E_TRANSFERDATASUSPENDED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_30 = DCM_E_GENERALPROGRAMMINGFAILURE;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_31 = DCM_E_WRONGBLOCKSEQUENCECOUNTER;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_32 = DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_33 = DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_34 = DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_35 = DCM_E_RPMTOOHIGH;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_36 = DCM_E_RPMTOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_37 = DCM_E_ENGINEISRUNNING;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_38 = DCM_E_ENGINEISNOTRUNNING;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_39 = DCM_E_ENGINERUNTIMETOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_40 = DCM_E_TEMPERATURETOOHIGH;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_41 = DCM_E_TEMPERATURETOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_42 = DCM_E_VEHICLESPEEDTOOHIGH;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_43 = DCM_E_VEHICLESPEEDTOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_44 = DCM_E_THROTTLE_PEDALTOOHIGH;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_45 = DCM_E_THROTTLE_PEDALTOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_46 = DCM_E_TRANSMISSIONRANGENOTINNEUTRAL;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_47 = DCM_E_TRANSMISSIONRANGENOTINGEAR;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_48 = DCM_E_BRAKESWITCH_NOTCLOSED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_49 = DCM_E_SHIFTERLEVERNOTINPARK;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_50 = DCM_E_TORQUECONVERTERCLUTCHLOCKED;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_51 = DCM_E_VOLTAGETOOHIGH;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_52 = DCM_E_VOLTAGETOOLOW;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_53 = DCM_E_VMSCNC_0;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_54 = DCM_E_VMSCNC_1;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_55 = DCM_E_VMSCNC_2;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_56 = DCM_E_VMSCNC_3;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_57 = DCM_E_VMSCNC_4;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_58 = DCM_E_VMSCNC_5;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_59 = DCM_E_VMSCNC_6;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_60 = DCM_E_VMSCNC_7;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_61 = DCM_E_VMSCNC_8;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_62 = DCM_E_VMSCNC_9;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_63 = DCM_E_VMSCNC_A;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_64 = DCM_E_VMSCNC_B;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_65 = DCM_E_VMSCNC_C;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_66 = DCM_E_VMSCNC_D;
  Dcm_NegativeResponseCodeType Test_Dcm_NegativeResponseCodeType_V_67 = DCM_E_VMSCNC_E;

  Dcm_OpStatusType Test_Dcm_OpStatusType_V_1 = DCM_INITIAL;
  Dcm_OpStatusType Test_Dcm_OpStatusType_V_2 = DCM_PENDING;
  Dcm_OpStatusType Test_Dcm_OpStatusType_V_3 = DCM_CANCEL;
  Dcm_OpStatusType Test_Dcm_OpStatusType_V_4 = DCM_FORCE_RCRRP_OK;
  Dcm_OpStatusType Test_Dcm_OpStatusType_V_5 = DCM_FORCE_RCRRP_NOT_OK;

  Dcm_ProtocolType Test_Dcm_ProtocolType_V_1 = DCM_OBD_ON_CAN;
  Dcm_ProtocolType Test_Dcm_ProtocolType_V_2 = DCM_OBD_ON_FLEXRAY;
  Dcm_ProtocolType Test_Dcm_ProtocolType_V_3 = DCM_OBD_ON_IP;
  Dcm_ProtocolType Test_Dcm_ProtocolType_V_4 = DCM_UDS_ON_CAN;
  Dcm_ProtocolType Test_Dcm_ProtocolType_V_5 = DCM_UDS_ON_FLEXRAY;
  Dcm_ProtocolType Test_Dcm_ProtocolType_V_6 = DCM_UDS_ON_IP;
  Dcm_ProtocolType Test_Dcm_ProtocolType_V_7 = DCM_NO_ACTIVE_PROTOCOL;
  Dcm_ProtocolType Test_Dcm_ProtocolType_V_8 = DCM_SUPPLIER_1;
  Dcm_ProtocolType Test_Dcm_ProtocolType_V_9 = DCM_SUPPLIER_2;
  Dcm_ProtocolType Test_Dcm_ProtocolType_V_10 = DCM_SUPPLIER_3;
  Dcm_ProtocolType Test_Dcm_ProtocolType_V_11 = DCM_SUPPLIER_4;
  Dcm_ProtocolType Test_Dcm_ProtocolType_V_12 = DCM_SUPPLIER_5;
  Dcm_ProtocolType Test_Dcm_ProtocolType_V_13 = DCM_SUPPLIER_6;
  Dcm_ProtocolType Test_Dcm_ProtocolType_V_14 = DCM_SUPPLIER_7;
  Dcm_ProtocolType Test_Dcm_ProtocolType_V_15 = DCM_SUPPLIER_8;
  Dcm_ProtocolType Test_Dcm_ProtocolType_V_16 = DCM_SUPPLIER_9;
  Dcm_ProtocolType Test_Dcm_ProtocolType_V_17 = DCM_SUPPLIER_10;
  Dcm_ProtocolType Test_Dcm_ProtocolType_V_18 = DCM_SUPPLIER_11;
  Dcm_ProtocolType Test_Dcm_ProtocolType_V_19 = DCM_SUPPLIER_12;
  Dcm_ProtocolType Test_Dcm_ProtocolType_V_20 = DCM_SUPPLIER_13;
  Dcm_ProtocolType Test_Dcm_ProtocolType_V_21 = DCM_SUPPLIER_14;
  Dcm_ProtocolType Test_Dcm_ProtocolType_V_22 = DCM_SUPPLIER_15;

  Dcm_RequestKindType Test_Dcm_RequestKindType_V_1 = DCM_REQ_KIND_NONE;
  Dcm_RequestKindType Test_Dcm_RequestKindType_V_2 = DCM_REQ_KIND_EXTERNAL;
  Dcm_RequestKindType Test_Dcm_RequestKindType_V_3 = DCM_REQ_KIND_ROE;

  Dcm_SecLevelType Test_Dcm_SecLevelType_V_1 = DCM_SEC_LEV_LOCKED;
  Dcm_SecLevelType Test_Dcm_SecLevelType_V_2 = DCM_SEC_LEV_L1;
  Dcm_SecLevelType Test_Dcm_SecLevelType_V_3 = DCM_SEC_LEV_L2;

  Dcm_SesCtrlType Test_Dcm_SesCtrlType_V_1 = DCM_DEFAULT_SESSION;
  Dcm_SesCtrlType Test_Dcm_SesCtrlType_V_2 = DCM_PROGRAMMING_SESSION;
  Dcm_SesCtrlType Test_Dcm_SesCtrlType_V_3 = DCM_EXTENDED_DIAGNOSTIC_SESSION;

  /* Modes */

  Dcm_CommunicationModeType Test_DcmCommunicationControl_MV_1 = RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM;
  Dcm_CommunicationModeType Test_DcmCommunicationControl_MV_2 = RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM;
  Dcm_CommunicationModeType Test_DcmCommunicationControl_MV_3 = RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM;
  Dcm_CommunicationModeType Test_DcmCommunicationControl_MV_4 = RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORMAL;
  Dcm_CommunicationModeType Test_DcmCommunicationControl_MV_5 = RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NM;
  Dcm_CommunicationModeType Test_DcmCommunicationControl_MV_6 = RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NM;
  Dcm_CommunicationModeType Test_DcmCommunicationControl_MV_7 = RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NM;
  Dcm_CommunicationModeType Test_DcmCommunicationControl_MV_8 = RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NM;
  Dcm_CommunicationModeType Test_DcmCommunicationControl_MV_9 = RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM_NM;
  Dcm_CommunicationModeType Test_DcmCommunicationControl_MV_10 = RTE_MODE_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM_NM;
  Dcm_CommunicationModeType Test_DcmCommunicationControl_MV_11 = RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM_NM;
  Dcm_CommunicationModeType Test_DcmCommunicationControl_MV_12 = RTE_MODE_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORM_NM;
  Dcm_CommunicationModeType Test_DcmCommunicationControl_TV = RTE_TRANSITION_DcmCommunicationControl;

  Dcm_ControlDtcSettingType Test_DcmControlDtcSetting_MV_1 = RTE_MODE_DcmControlDtcSetting_ENABLEDTCSETTING;
  Dcm_ControlDtcSettingType Test_DcmControlDtcSetting_MV_2 = RTE_MODE_DcmControlDtcSetting_DISABLEDTCSETTING;
  Dcm_ControlDtcSettingType Test_DcmControlDtcSetting_TV = RTE_TRANSITION_DcmControlDtcSetting;

  Dcm_DiagnosticSessionControlType Test_DcmDiagnosticSessionControl_MV_1 = RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION;
  Dcm_DiagnosticSessionControlType Test_DcmDiagnosticSessionControl_MV_2 = RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION;
  Dcm_DiagnosticSessionControlType Test_DcmDiagnosticSessionControl_MV_3 = RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION;
  Dcm_DiagnosticSessionControlType Test_DcmDiagnosticSessionControl_TV = RTE_TRANSITION_DcmDiagnosticSessionControl;

  Dcm_EcuResetType Test_DcmEcuReset_MV_1 = RTE_MODE_DcmEcuReset_NONE;
  Dcm_EcuResetType Test_DcmEcuReset_MV_2 = RTE_MODE_DcmEcuReset_HARD;
  Dcm_EcuResetType Test_DcmEcuReset_MV_3 = RTE_MODE_DcmEcuReset_KEYONOFF;
  Dcm_EcuResetType Test_DcmEcuReset_MV_4 = RTE_MODE_DcmEcuReset_SOFT;
  Dcm_EcuResetType Test_DcmEcuReset_MV_5 = RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER;
  Dcm_EcuResetType Test_DcmEcuReset_MV_6 = RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER;
  Dcm_EcuResetType Test_DcmEcuReset_MV_7 = RTE_MODE_DcmEcuReset_EXECUTE;
  Dcm_EcuResetType Test_DcmEcuReset_TV = RTE_TRANSITION_DcmEcuReset;
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
