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
 *             File:  Rte_DigApp.h
 *           Config:  last364.dpa
 *      ECU-Project:  last364
 *
 *        Generator:  MICROSAR RTE Generator Version 4.29.0
 *                    RTE Core Version 1.29.0
 *          License:  CBD2200508
 *
 *      Description:  Application header file for SW-C <DigApp>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_DIGAPP_H
# define RTE_DIGAPP_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_DigApp_Type.h"
# include "Rte_DataHandleType.h"


# define DigApp_START_SEC_CODE
# include "DigApp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CSDataServices_DID_0x1_DID_Data_GlobalTime_ReadData CSDataServices_DID_0x1_DID_Data_GlobalTime_ReadData
#  define RTE_RUNNABLE_DataServices_Boot_Software_Boot_Software_Identification_ConditionCheckRead DataServices_Boot_Software_Boot_Software_Identification_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Boot_Software_Boot_Software_Identification_ReadData DataServices_Boot_Software_Boot_Software_Identification_ReadData
#  define RTE_RUNNABLE_DataServices_Boot_Software_Boot_Software_Identification_WriteData DataServices_Boot_Software_Boot_Software_Identification_WriteData
#  define RTE_RUNNABLE_DataServices_Boot_Software_NumberOfModules_ConditionCheckRead DataServices_Boot_Software_NumberOfModules_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Boot_Software_NumberOfModules_ReadData DataServices_Boot_Software_NumberOfModules_ReadData
#  define RTE_RUNNABLE_DataServices_Boot_Software_NumberOfModules_WriteData DataServices_Boot_Software_NumberOfModules_WriteData
#  define RTE_RUNNABLE_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_ConditionCheckRead DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_ReadData DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_ReadData
#  define RTE_RUNNABLE_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_WriteData DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_WriteData
#  define RTE_RUNNABLE_DataServices_EcuIdentification_Part_Number_ConditionCheckRead DataServices_EcuIdentification_Part_Number_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_EcuIdentification_Part_Number_ReadData DataServices_EcuIdentification_Part_Number_ReadData
#  define RTE_RUNNABLE_DataServices_EcuIdentification_Part_Number_WriteData DataServices_EcuIdentification_Part_Number_WriteData
#  define RTE_RUNNABLE_DataServices_Hardware_Version_Hardware_Version_Number_ConditionCheckRead DataServices_Hardware_Version_Hardware_Version_Number_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Hardware_Version_Hardware_Version_Number_ReadData DataServices_Hardware_Version_Hardware_Version_Number_ReadData
#  define RTE_RUNNABLE_DataServices_Hardware_Version_Hardware_Version_Number_WriteData DataServices_Hardware_Version_Hardware_Version_Number_WriteData
#  define RTE_RUNNABLE_DataServices_SampleIoControl_DID_Data_FreezeCurrentState DataServices_SampleIoControl_DID_Data_FreezeCurrentState
#  define RTE_RUNNABLE_DataServices_SampleIoControl_DID_Data_ReadData DataServices_SampleIoControl_DID_Data_ReadData
#  define RTE_RUNNABLE_DataServices_SampleIoControl_DID_Data_ResetToDefault DataServices_SampleIoControl_DID_Data_ResetToDefault
#  define RTE_RUNNABLE_DataServices_SampleIoControl_DID_Data_ReturnControlToECU DataServices_SampleIoControl_DID_Data_ReturnControlToECU
#  define RTE_RUNNABLE_DataServices_SampleIoControl_DID_Data_ShortTermAdjustment DataServices_SampleIoControl_DID_Data_ShortTermAdjustment
#  define RTE_RUNNABLE_DataServices_SerialNumber_SerialNumber_ConditionCheckRead DataServices_SerialNumber_SerialNumber_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_SerialNumber_SerialNumber_ReadData DataServices_SerialNumber_SerialNumber_ReadData
#  define RTE_RUNNABLE_DataServices_SerialNumber_SerialNumber_WriteData DataServices_SerialNumber_SerialNumber_WriteData
#  define RTE_RUNNABLE_DataServices_Spare_Part_Number_Spare_Part_Number_ConditionCheckRead DataServices_Spare_Part_Number_Spare_Part_Number_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Spare_Part_Number_Spare_Part_Number_ReadData DataServices_Spare_Part_Number_Spare_Part_Number_ReadData
#  define RTE_RUNNABLE_DataServices_Spare_Part_Number_Spare_Part_Number_WriteData DataServices_Spare_Part_Number_Spare_Part_Number_WriteData
#  define RTE_RUNNABLE_DataServices_Vehicle_Identification_VIN_ConditionCheckRead DataServices_Vehicle_Identification_VIN_ConditionCheckRead
#  define RTE_RUNNABLE_DataServices_Vehicle_Identification_VIN_ReadData DataServices_Vehicle_Identification_VIN_ReadData
#  define RTE_RUNNABLE_DataServices_Vehicle_Identification_VIN_WriteData DataServices_Vehicle_Identification_VIN_WriteData
#  define RTE_RUNNABLE_DcmEcuReset_ModeSwitch DcmEcuReset_ModeSwitch
#  define RTE_RUNNABLE_DigInit DigInit
#  define RTE_RUNNABLE_RoutineServices_SampleRoutineControl_RequestResults RoutineServices_SampleRoutineControl_RequestResults
#  define RTE_RUNNABLE_RoutineServices_SampleRoutineControl_Start RoutineServices_SampleRoutineControl_Start
#  define RTE_RUNNABLE_RoutineServices_SampleRoutineControl_StartOnly_RequestResults RoutineServices_SampleRoutineControl_StartOnly_RequestResults
#  define RTE_RUNNABLE_RoutineServices_SampleRoutineControl_StartOnly_Start RoutineServices_SampleRoutineControl_StartOnly_Start
#  define RTE_RUNNABLE_RoutineServices_SampleRoutineControl_Stop RoutineServices_SampleRoutineControl_Stop
#  define RTE_RUNNABLE_SecurityAccess_Level_3_CompareKey SecurityAccess_Level_3_CompareKey
#  define RTE_RUNNABLE_SecurityAccess_Level_3_GetSeed SecurityAccess_Level_3_GetSeed
#  define RTE_RUNNABLE_SecurityAccess_UnlockedL1_CompareKey SecurityAccess_UnlockedL1_CompareKey
#  define RTE_RUNNABLE_SecurityAccess_UnlockedL1_GetSeed SecurityAccess_UnlockedL1_GetSeed
# endif

# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DigApp_CODE) CSDataServices_DID_0x1_DID_Data_GlobalTime_ReadData(P2VAR(uint8, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DigApp_CODE) CSDataServices_DID_0x1_DID_Data_GlobalTime_ReadData(P2VAR(DataArrayType_uint8_6, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DigApp_CODE) DataServices_Boot_Software_Boot_Software_Identification_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DigApp_CODE) DataServices_Boot_Software_Boot_Software_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DigApp_CODE) DataServices_Boot_Software_Boot_Software_Identification_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DigApp_CODE) DataServices_Boot_Software_Boot_Software_Identification_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIGAPP_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DigApp_CODE) DataServices_Boot_Software_Boot_Software_Identification_WriteData(P2CONST(Dcm_Data4ByteType, AUTOMATIC, RTE_DIGAPP_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DigApp_CODE) DataServices_Boot_Software_NumberOfModules_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DigApp_CODE) DataServices_Boot_Software_NumberOfModules_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DigApp_CODE) DataServices_Boot_Software_NumberOfModules_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DigApp_CODE) DataServices_Boot_Software_NumberOfModules_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIGAPP_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DigApp_CODE) DataServices_Boot_Software_NumberOfModules_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DIGAPP_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DigApp_CODE) DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DigApp_CODE) DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DigApp_CODE) DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DigApp_CODE) DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIGAPP_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DigApp_CODE) DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_WriteData(P2CONST(Dcm_Data2ByteType, AUTOMATIC, RTE_DIGAPP_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DigApp_CODE) DataServices_EcuIdentification_Part_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DigApp_CODE) DataServices_EcuIdentification_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DigApp_CODE) DataServices_EcuIdentification_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data13ByteType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DigApp_CODE) DataServices_EcuIdentification_Part_Number_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIGAPP_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DigApp_CODE) DataServices_EcuIdentification_Part_Number_WriteData(P2CONST(Dcm_Data13ByteType, AUTOMATIC, RTE_DIGAPP_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DigApp_CODE) DataServices_Hardware_Version_Hardware_Version_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DigApp_CODE) DataServices_Hardware_Version_Hardware_Version_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DigApp_CODE) DataServices_Hardware_Version_Hardware_Version_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DigApp_CODE) DataServices_Hardware_Version_Hardware_Version_Number_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIGAPP_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DigApp_CODE) DataServices_Hardware_Version_Hardware_Version_Number_WriteData(P2CONST(Dcm_Data4ByteType, AUTOMATIC, RTE_DIGAPP_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DigApp_CODE) DataServices_SampleIoControl_DID_Data_FreezeCurrentState(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DigApp_CODE) DataServices_SampleIoControl_DID_Data_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DigApp_CODE) DataServices_SampleIoControl_DID_Data_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DigApp_CODE) DataServices_SampleIoControl_DID_Data_ResetToDefault(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DigApp_CODE) DataServices_SampleIoControl_DID_Data_ReturnControlToECU(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DigApp_CODE) DataServices_SampleIoControl_DID_Data_ShortTermAdjustment(P2CONST(uint8, AUTOMATIC, RTE_DIGAPP_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DigApp_CODE) DataServices_SampleIoControl_DID_Data_ShortTermAdjustment(P2CONST(Dcm_Data4ByteType, AUTOMATIC, RTE_DIGAPP_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DigApp_CODE) DataServices_SerialNumber_SerialNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DigApp_CODE) DataServices_SerialNumber_SerialNumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DigApp_CODE) DataServices_SerialNumber_SerialNumber_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DigApp_CODE) DataServices_SerialNumber_SerialNumber_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIGAPP_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DigApp_CODE) DataServices_SerialNumber_SerialNumber_WriteData(P2CONST(Dcm_Data4ByteType, AUTOMATIC, RTE_DIGAPP_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DigApp_CODE) DataServices_Spare_Part_Number_Spare_Part_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DigApp_CODE) DataServices_Spare_Part_Number_Spare_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DigApp_CODE) DataServices_Spare_Part_Number_Spare_Part_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DigApp_CODE) DataServices_Spare_Part_Number_Spare_Part_Number_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIGAPP_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DigApp_CODE) DataServices_Spare_Part_Number_Spare_Part_Number_WriteData(P2CONST(Dcm_Data4ByteType, AUTOMATIC, RTE_DIGAPP_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DigApp_CODE) DataServices_Vehicle_Identification_VIN_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DigApp_CODE) DataServices_Vehicle_Identification_VIN_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DigApp_CODE) DataServices_Vehicle_Identification_VIN_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data17ByteType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DigApp_CODE) DataServices_Vehicle_Identification_VIN_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIGAPP_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DigApp_CODE) DataServices_Vehicle_Identification_VIN_WriteData(P2CONST(Dcm_Data17ByteType, AUTOMATIC, RTE_DIGAPP_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(void, DigApp_CODE) DcmEcuReset_ModeSwitch(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, DigApp_CODE) DigInit(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, DigApp_CODE) RoutineServices_SampleRoutineControl_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_SampleRoutineControl_Out_ResultType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Out_Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DigApp_CODE) RoutineServices_SampleRoutineControl_Start(Dcm_StartDataIn_SampleRoutineControl_In_Option0Type In_Option0, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_SampleRoutineControl_Out_InitStateType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Out_InitState, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DigApp_CODE) RoutineServices_SampleRoutineControl_StartOnly_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_SampleRoutineControl_StartOnly_Out_ResultType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Out_Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DigApp_CODE) RoutineServices_SampleRoutineControl_StartOnly_Start(P2CONST(Dcm_StartDataIn_SampleRoutineControl_StartOnly_In_Option1ArrayType, AUTOMATIC, RTE_DIGAPP_APPL_DATA) In_Option1, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DigApp_CODE) RoutineServices_SampleRoutineControl_StartOnly_Start(P2CONST(Dcm_StartDataIn_SampleRoutineControl_StartOnly_In_Option1Type, AUTOMATIC, RTE_DIGAPP_APPL_DATA) In_Option1, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DigApp_CODE) RoutineServices_SampleRoutineControl_Stop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StopDataOut_SampleRoutineControl_Out_StopStateType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Out_StopState, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DigApp_CODE) SecurityAccess_Level_3_CompareKey(P2CONST(uint8, AUTOMATIC, RTE_DIGAPP_APPL_DATA) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DigApp_CODE) SecurityAccess_Level_3_CompareKey(P2CONST(Dcm_Data2ByteType, AUTOMATIC, RTE_DIGAPP_APPL_DATA) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DigApp_CODE) SecurityAccess_Level_3_GetSeed(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DigApp_CODE) SecurityAccess_Level_3_GetSeed(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DigApp_CODE) SecurityAccess_UnlockedL1_CompareKey(P2CONST(uint8, AUTOMATIC, RTE_DIGAPP_APPL_DATA) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DigApp_CODE) SecurityAccess_UnlockedL1_CompareKey(P2CONST(Dcm_Data4ByteType, AUTOMATIC, RTE_DIGAPP_APPL_DATA) Key, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DigApp_CODE) SecurityAccess_UnlockedL1_GetSeed(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DigApp_CODE) SecurityAccess_UnlockedL1_GetSeed(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) Seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIGAPP_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif

# define DigApp_STOP_SEC_CODE
# include "DigApp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_CSDataServices_DID_0x1_DID_Data_GlobalTime_E_NOT_OK (1U)

#  define RTE_E_DataServices_Boot_Software_Boot_Software_Identification_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Boot_Software_Boot_Software_Identification_E_NOT_OK (1U)

#  define RTE_E_DataServices_Boot_Software_NumberOfModules_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Boot_Software_NumberOfModules_E_NOT_OK (1U)

#  define RTE_E_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_E_NOT_OK (1U)

#  define RTE_E_DataServices_EcuIdentification_Part_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_EcuIdentification_Part_Number_E_NOT_OK (1U)

#  define RTE_E_DataServices_Hardware_Version_Hardware_Version_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Hardware_Version_Hardware_Version_Number_E_NOT_OK (1U)

#  define RTE_E_DataServices_SampleIoControl_DID_Data_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_SampleIoControl_DID_Data_E_NOT_OK (1U)

#  define RTE_E_DataServices_SerialNumber_SerialNumber_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_SerialNumber_SerialNumber_E_NOT_OK (1U)

#  define RTE_E_DataServices_Spare_Part_Number_Spare_Part_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Spare_Part_Number_Spare_Part_Number_E_NOT_OK (1U)

#  define RTE_E_DataServices_Vehicle_Identification_VIN_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Vehicle_Identification_VIN_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_SampleRoutineControl_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_SampleRoutineControl_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_SampleRoutineControl_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_SampleRoutineControl_StartOnly_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_SampleRoutineControl_StartOnly_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_SampleRoutineControl_StartOnly_E_NOT_OK (1U)

#  define RTE_E_SecurityAccess_Level_3_DCM_E_COMPARE_KEY_FAILED (11U)

#  define RTE_E_SecurityAccess_Level_3_DCM_E_PENDING (10U)

#  define RTE_E_SecurityAccess_Level_3_E_NOT_OK (1U)

#  define RTE_E_SecurityAccess_UnlockedL1_DCM_E_COMPARE_KEY_FAILED (11U)

#  define RTE_E_SecurityAccess_UnlockedL1_DCM_E_PENDING (10U)

#  define RTE_E_SecurityAccess_UnlockedL1_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_DIGAPP_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0786:  MISRA rule: Rule5.5
     Reason:     Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
