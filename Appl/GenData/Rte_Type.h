/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_Type.h
 *           Config:  last364.dpa
 *      ECU-Project:  last364
 *
 *        Generator:  MICROSAR RTE Generator Version 4.29.0
 *                    RTE Core Version 1.29.0
 *          License:  CBD2200508
 *
 *      Description:  Header file containing user defined AUTOSAR types and RTE structures
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/* double include prevention */
#ifndef RTE_TYPE_H
# define RTE_TYPE_H

# include "Rte.h"
# ifdef RTE_CORE
/**********************************************************************************************************************
 * Type definitions for mode management
 *********************************************************************************************************************/
typedef EventMaskType Rte_EventMaskType;
# endif /* defined(RTE_CORE) */

/* PRQA S 1039 EOF */ /* MD_Rte_1039 */

/**********************************************************************************************************************
 * Data type definitions
 *********************************************************************************************************************/

# define Rte_TypeDef_DataArrayType_uint8_6
typedef uint8 DataArrayType_uint8_6[6];

# define Rte_TypeDef_Dcm_Data13ByteType
typedef uint8 Dcm_Data13ByteType[13];

# define Rte_TypeDef_Dcm_Data17ByteType
typedef uint8 Dcm_Data17ByteType[17];

# define Rte_TypeDef_Dcm_Data1ByteType
typedef uint8 Dcm_Data1ByteType[1];

# define Rte_TypeDef_Dcm_Data2ByteType
typedef uint8 Dcm_Data2ByteType[2];

# define Rte_TypeDef_Dcm_Data4ByteType
typedef uint8 Dcm_Data4ByteType[4];

# define Rte_TypeDef_Dem_MaxDataValueType
typedef uint8 Dem_MaxDataValueType[6];

# define Rte_TypeDef_ComM_InhibitionStatusType
typedef uint8 ComM_InhibitionStatusType;

# define Rte_TypeDef_ComM_UserHandleType
typedef uint16 ComM_UserHandleType;

# define Rte_TypeDef_DataPrimitiveType_uint16
typedef uint16 DataPrimitiveType_uint16;

# define Rte_TypeDef_Dcm_RequestDataOut_SampleRoutineControl_Out_ResultPrimitiveType
typedef uint16 Dcm_RequestDataOut_SampleRoutineControl_Out_ResultPrimitiveType;

# define Rte_TypeDef_Dcm_RequestDataOut_SampleRoutineControl_Out_ResultType
typedef Dcm_RequestDataOut_SampleRoutineControl_Out_ResultPrimitiveType Dcm_RequestDataOut_SampleRoutineControl_Out_ResultType;

# define Rte_TypeDef_Dcm_RequestDataOut_SampleRoutineControl_StartOnly_Out_ResultPrimitiveType
typedef uint32 Dcm_RequestDataOut_SampleRoutineControl_StartOnly_Out_ResultPrimitiveType;

# define Rte_TypeDef_Dcm_RequestDataOut_SampleRoutineControl_StartOnly_Out_ResultType
typedef Dcm_RequestDataOut_SampleRoutineControl_StartOnly_Out_ResultPrimitiveType Dcm_RequestDataOut_SampleRoutineControl_StartOnly_Out_ResultType;

# define Rte_TypeDef_Dcm_StartDataIn_SampleRoutineControl_In_Option0PrimitiveType
typedef uint8 Dcm_StartDataIn_SampleRoutineControl_In_Option0PrimitiveType;

# define Rte_TypeDef_Dcm_StartDataIn_SampleRoutineControl_In_Option0Type
typedef Dcm_StartDataIn_SampleRoutineControl_In_Option0PrimitiveType Dcm_StartDataIn_SampleRoutineControl_In_Option0Type;

# define Rte_TypeDef_Dcm_StartDataIn_SampleRoutineControl_StartOnly_In_Option1ArrayType
typedef uint8 Dcm_StartDataIn_SampleRoutineControl_StartOnly_In_Option1ArrayType;

# define Rte_TypeDef_Dcm_StartDataOut_SampleRoutineControl_Out_InitStatePrimitiveType
typedef uint32 Dcm_StartDataOut_SampleRoutineControl_Out_InitStatePrimitiveType;

# define Rte_TypeDef_Dcm_StartDataOut_SampleRoutineControl_Out_InitStateType
typedef Dcm_StartDataOut_SampleRoutineControl_Out_InitStatePrimitiveType Dcm_StartDataOut_SampleRoutineControl_Out_InitStateType;

# define Rte_TypeDef_Dcm_StopDataOut_SampleRoutineControl_Out_StopStatePrimitiveType
typedef uint32 Dcm_StopDataOut_SampleRoutineControl_Out_StopStatePrimitiveType;

# define Rte_TypeDef_Dcm_StopDataOut_SampleRoutineControl_Out_StopStateType
typedef Dcm_StopDataOut_SampleRoutineControl_Out_StopStatePrimitiveType Dcm_StopDataOut_SampleRoutineControl_Out_StopStateType;

# define Rte_TypeDef_Dem_DTCGroupType
typedef uint32 Dem_DTCGroupType;

# define Rte_TypeDef_Dem_DTCStatusMaskType
typedef uint8 Dem_DTCStatusMaskType;

# define Rte_TypeDef_Dem_EventIdType
typedef uint16 Dem_EventIdType;

# define Rte_TypeDef_Dem_RatioIdType
typedef uint16 Dem_RatioIdType;

# define Rte_TypeDef_EcuM_TimeType
typedef uint32 EcuM_TimeType;

# define Rte_TypeDef_TimeInMicrosecondsType
typedef uint32 TimeInMicrosecondsType;

# define Rte_TypeDef_WdgM_CheckpointIdType
typedef uint16 WdgM_CheckpointIdType;

# define Rte_TypeDef_WdgM_ModeType
typedef uint8 WdgM_ModeType;

# define Rte_TypeDef_WdgM_SupervisedEntityIdType
typedef uint16 WdgM_SupervisedEntityIdType;

# define Rte_TypeDef_ComM_ModeType
typedef uint8 ComM_ModeType;

# define Rte_TypeDef_Dcm_CommunicationModeType
typedef uint8 Dcm_CommunicationModeType;

# define Rte_TypeDef_Dcm_ConfirmationStatusType
typedef uint8 Dcm_ConfirmationStatusType;

# define Rte_TypeDef_Dcm_ControlDtcSettingType
typedef uint8 Dcm_ControlDtcSettingType;

# define Rte_TypeDef_Dcm_DiagnosticSessionControlType
typedef uint8 Dcm_DiagnosticSessionControlType;

# define Rte_TypeDef_Dcm_EcuResetType
typedef uint8 Dcm_EcuResetType;

# define Rte_TypeDef_Dcm_NegativeResponseCodeType
typedef uint8 Dcm_NegativeResponseCodeType;

# define Rte_TypeDef_Dcm_OpStatusType
typedef uint8 Dcm_OpStatusType;

# define Rte_TypeDef_Dcm_ProtocolType
typedef uint8 Dcm_ProtocolType;

# define Rte_TypeDef_Dcm_RequestKindType
typedef uint8 Dcm_RequestKindType;

# define Rte_TypeDef_Dcm_SecLevelType
typedef uint8 Dcm_SecLevelType;

# define Rte_TypeDef_Dcm_SesCtrlType
typedef uint8 Dcm_SesCtrlType;

# define Rte_TypeDef_Dem_DTCFormatType
typedef uint8 Dem_DTCFormatType;

# define Rte_TypeDef_Dem_DTCKindType
typedef uint8 Dem_DTCKindType;

# define Rte_TypeDef_Dem_DTCOriginType
typedef uint16 Dem_DTCOriginType;

# define Rte_TypeDef_Dem_DTCSeverityType
typedef uint8 Dem_DTCSeverityType;

# define Rte_TypeDef_Dem_DTRControlType
typedef uint8 Dem_DTRControlType;

# define Rte_TypeDef_Dem_DebounceResetStatusType
typedef uint8 Dem_DebounceResetStatusType;

# define Rte_TypeDef_Dem_DebouncingStateType
typedef uint8 Dem_DebouncingStateType;

# define Rte_TypeDef_Dem_EventStatusType
typedef uint8 Dem_EventStatusType;

# define Rte_TypeDef_Dem_IndicatorStatusType
typedef uint8 Dem_IndicatorStatusType;

# define Rte_TypeDef_Dem_InitMonitorReasonType
typedef uint8 Dem_InitMonitorReasonType;

# define Rte_TypeDef_Dem_IumprDenomCondIdType
typedef uint8 Dem_IumprDenomCondIdType;

# define Rte_TypeDef_Dem_IumprDenomCondStatusType
typedef uint8 Dem_IumprDenomCondStatusType;

# define Rte_TypeDef_Dem_IumprReadinessGroupType
typedef uint8 Dem_IumprReadinessGroupType;

# define Rte_TypeDef_Dem_MonitorStatusType
typedef uint8 Dem_MonitorStatusType;

# define Rte_TypeDef_Dem_OperationCycleStateType
typedef uint8 Dem_OperationCycleStateType;

# define Rte_TypeDef_Dem_UdsStatusByteType
typedef uint8 Dem_UdsStatusByteType;

# define Rte_TypeDef_EcuM_BootTargetType
typedef uint8 EcuM_BootTargetType;

# define Rte_TypeDef_EcuM_ModeType
typedef uint8 EcuM_ModeType;

# define Rte_TypeDef_EcuM_ShutdownCauseType
typedef uint8 EcuM_ShutdownCauseType;

# define Rte_TypeDef_EcuM_StateType
typedef uint8 EcuM_StateType;

# define Rte_TypeDef_EcuM_UserType
typedef uint8 EcuM_UserType;

# define Rte_TypeDef_WdgMMode
typedef uint8 WdgMMode;

# define Rte_TypeDef_WdgM_GlobalStatusType
typedef uint8 WdgM_GlobalStatusType;

# define Rte_TypeDef_WdgM_LocalStatusType
typedef uint8 WdgM_LocalStatusType;

# define Rte_TypeDef_Dcm_StartDataIn_SampleRoutineControl_StartOnly_In_Option1Type
typedef Dcm_StartDataIn_SampleRoutineControl_StartOnly_In_Option1ArrayType Dcm_StartDataIn_SampleRoutineControl_StartOnly_In_Option1Type[3];


# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

#  define Rte_TypeDef_dtRef_VOID
typedef void * dtRef_VOID;

#  define Rte_TypeDef_dtRef_const_VOID
typedef const void * dtRef_const_VOID;

#  define Rte_TypeDef_Dem_OperationCycleIdType
typedef uint8 Dem_OperationCycleIdType;

#  define Rte_TypeDef_NvM_BlockIdType
typedef uint16 NvM_BlockIdType;

#  define Rte_TypeDef_NvM_RequestResultType
typedef uint8 NvM_RequestResultType;

#  define Rte_TypeDef_NvM_ServiceIdType
typedef uint8 NvM_ServiceIdType;

# endif
# include "Rte_DataHandleType.h"

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef unsigned int Rte_BitType;
/**********************************************************************************************************************
 * type and extern declarations of RTE internal variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte Init State Variable
 *********************************************************************************************************************/

# define RTE_STATE_UNINIT     (0U)
# define RTE_STATE_SCHM_START (1U)
# define RTE_STATE_SCHM_INIT  (2U)
# define RTE_STATE_INIT       (3U)

# define RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_8BIT
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern volatile VAR(uint8, RTE_VAR_ZERO_INIT_NOCACHE) Rte_InitState; /* PRQA S 3408 */ /* MD_Rte_3408 */
extern volatile VAR(uint8, RTE_VAR_ZERO_INIT_NOCACHE) Rte_StartTiming_InitState; /* PRQA S 0850, 3408 */ /* MD_MSR_MacroArgumentEmpty, MD_Rte_3408 */

# define RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_8BIT
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define RTE_START_SEC_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_8BIT
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern volatile VAR(uint8, RTE_VAR_ZERO_INIT_NOCACHE) Rte_InitState_1; /* PRQA S 3408 */ /* MD_Rte_3408 */

# define RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_8BIT
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef RTE_CORE

/**********************************************************************************************************************
 * Buffers for unqueued S/R
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(float32, RTE_VAR_INIT) Rte_MotorCdd_Pp_MotorDcBusVoltage_Vbus; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotorCdd_Pp_MotorElectricalAngle_ElectricAngle; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(boolean, RTE_VAR_INIT) Rte_MotorCdd_Pp_MotorFaultStatus_tle9180_Ov_Fault; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_INIT) Rte_MotorControll_Pp_MotorCtrlCmd_MotorMode; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotorControll_Pp_MotorCurrentRef_Id_Ref; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(float32, RTE_VAR_INIT) Rte_MotorControll_Pp_MotorCurrentRef_Iq_Ref; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */

#  define RTE_STOP_SEC_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

typedef struct
{
  uint8 Rte_ModeSwitchAck_Dcm_DcmEcuReset_DcmEcuReset_Ack;
} Rte_SystemApplication_OsCore0_AckFlagsType;

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Rte_SystemApplication_OsCore0_AckFlagsType, RTE_VAR_INIT) Rte_SystemApplication_OsCore0_AckFlags;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * RTE internal IOC replacement
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_NOINIT) Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_Queue[1];

#  define RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_tail;

#  define RTE_STOP_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_VAR_SystemApplication_OsCore0_ZERO_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_head;

#  define RTE_STOP_SEC_VAR_SystemApplication_OsCore0_ZERO_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



/**********************************************************************************************************************
 * Data structures for mode management
 *********************************************************************************************************************/


#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Dcm_EcuResetType, RTE_VAR_INIT) Rte_ModeMachine_Dcm_DcmEcuReset_DcmEcuReset;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# endif /* defined(RTE_CORE) */

#endif /* RTE_TYPE_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_1039:  MISRA rule: Rule1.2
     Reason:     Same macro and function names are required to meet AUTOSAR spec.
     Risk:       No functional risk. Macro will be undefined before function definition.
     Prevention: Not required.

   MD_Rte_3408:  MISRA rule: Rule8.4
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

*/
