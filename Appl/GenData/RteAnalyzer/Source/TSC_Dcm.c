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
 *             File:  TSC_Dcm.c
 *           Config:  last364.dpa
 *        SW-C Type:  Dcm
 *
 *        Generator:  MICROSAR RTE Generator Version 4.29.0
 *                    RTE Core Version 1.29.0
 *          License:  CBD2200508
 *
 *      Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_Dcm.h"
#include "TSC_Dcm.h"















     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Boot_Software_Boot_Software_Identification_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_Boot_Software_Boot_Software_Identification_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Boot_Software_Boot_Software_Identification_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_Boot_Software_Boot_Software_Identification_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Boot_Software_Boot_Software_Identification_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_Boot_Software_Boot_Software_Identification_WriteData(Data, OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Boot_Software_NumberOfModules_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_Boot_Software_NumberOfModules_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Boot_Software_NumberOfModules_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_Boot_Software_NumberOfModules_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Boot_Software_NumberOfModules_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_Boot_Software_NumberOfModules_WriteData(Data, OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_WriteData(Data, OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_CanDriverVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DevelopmentData_CanDriverVersion_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_CanDriverVersion_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_DevelopmentData_CanDriverVersion_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_CanDriverVersion_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DevelopmentData_CanDriverVersion_WriteData(Data, OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_DiagnosticModuleVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DevelopmentData_DiagnosticModuleVersion_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_DiagnosticModuleVersion_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_DevelopmentData_DiagnosticModuleVersion_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_DiagnosticModuleVersion_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DevelopmentData_DiagnosticModuleVersion_WriteData(Data, OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_NmVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DevelopmentData_NmVersion_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_NmVersion_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_DevelopmentData_NmVersion_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_NmVersion_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DevelopmentData_NmVersion_WriteData(Data, OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_OperatingSystemVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DevelopmentData_OperatingSystemVersion_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_OperatingSystemVersion_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_DevelopmentData_OperatingSystemVersion_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_OperatingSystemVersion_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DevelopmentData_OperatingSystemVersion_WriteData(Data, OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_TransportLayerVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DevelopmentData_TransportLayerVersion_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_TransportLayerVersion_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_DevelopmentData_TransportLayerVersion_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_TransportLayerVersion_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_DevelopmentData_TransportLayerVersion_WriteData(Data, OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_EcuIdentification_Part_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_EcuIdentification_Part_Number_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_EcuIdentification_Part_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_EcuIdentification_Part_Number_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_EcuIdentification_Part_Number_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_EcuIdentification_Part_Number_WriteData(Data, OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Hardware_Version_Hardware_Version_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_Hardware_Version_Hardware_Version_Number_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Hardware_Version_Hardware_Version_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_Hardware_Version_Hardware_Version_Number_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Hardware_Version_Hardware_Version_Number_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_Hardware_Version_Hardware_Version_Number_WriteData(Data, OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_SampleIoControl_DID_Data_FreezeCurrentState(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_SampleIoControl_DID_Data_FreezeCurrentState(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_SampleIoControl_DID_Data_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_SampleIoControl_DID_Data_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_SampleIoControl_DID_Data_ResetToDefault(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_SampleIoControl_DID_Data_ResetToDefault(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_SampleIoControl_DID_Data_ReturnControlToECU(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_SampleIoControl_DID_Data_ReturnControlToECU(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_SampleIoControl_DID_Data_ShortTermAdjustment(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_SampleIoControl_DID_Data_ShortTermAdjustment(Data, OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_SerialNumber_SerialNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_SerialNumber_SerialNumber_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_SerialNumber_SerialNumber_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_SerialNumber_SerialNumber_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_SerialNumber_SerialNumber_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_SerialNumber_SerialNumber_WriteData(Data, OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Spare_Part_Number_Spare_Part_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_Spare_Part_Number_Spare_Part_Number_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Spare_Part_Number_Spare_Part_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_Spare_Part_Number_Spare_Part_Number_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Spare_Part_Number_Spare_Part_Number_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_Spare_Part_Number_Spare_Part_Number_WriteData(Data, OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Vehicle_Identification_VIN_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_Vehicle_Identification_VIN_ConditionCheckRead(OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Vehicle_Identification_VIN_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
{
  return Rte_Call_DataServices_Vehicle_Identification_VIN_ReadData(OpStatus, Data);
}
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Vehicle_Identification_VIN_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_DataServices_Vehicle_Identification_VIN_WriteData(Data, OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_SampleRoutineControl_RequestResults(Dcm_OpStatusType OpStatus, Dcm_RequestDataOut_SampleRoutineControl_Out_ResultType *Out_Result, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_SampleRoutineControl_RequestResults(OpStatus, Out_Result, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_SampleRoutineControl_Start(Dcm_StartDataIn_SampleRoutineControl_In_Option0Type In_Option0, Dcm_OpStatusType OpStatus, Dcm_StartDataOut_SampleRoutineControl_Out_InitStateType *Out_InitState, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_SampleRoutineControl_Start(In_Option0, OpStatus, Out_InitState, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_SampleRoutineControl_Stop(Dcm_OpStatusType OpStatus, Dcm_StopDataOut_SampleRoutineControl_Out_StopStateType *Out_StopState, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_SampleRoutineControl_Stop(OpStatus, Out_StopState, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_SampleRoutineControl_StartOnly_RequestResults(Dcm_OpStatusType OpStatus, Dcm_RequestDataOut_SampleRoutineControl_StartOnly_Out_ResultType *Out_Result, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_SampleRoutineControl_StartOnly_RequestResults(OpStatus, Out_Result, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_SampleRoutineControl_StartOnly_Start(const Dcm_StartDataIn_SampleRoutineControl_StartOnly_In_Option1ArrayType *In_Option1, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_RoutineServices_SampleRoutineControl_StartOnly_Start(In_Option1, OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_SecurityAccess_Level_3_CompareKey(const uint8 *Key, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_SecurityAccess_Level_3_CompareKey(Key, OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_SecurityAccess_Level_3_GetSeed(Dcm_OpStatusType OpStatus, uint8 *Seed, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_SecurityAccess_Level_3_GetSeed(OpStatus, Seed, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_SecurityAccess_UnlockedL1_CompareKey(const uint8 *Key, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_SecurityAccess_UnlockedL1_CompareKey(Key, OpStatus, ErrorCode);
}
Std_ReturnType TSC_Dcm_Rte_Call_SecurityAccess_UnlockedL1_GetSeed(Dcm_OpStatusType OpStatus, uint8 *Seed, Dcm_NegativeResponseCodeType *ErrorCode)
{
  return Rte_Call_SecurityAccess_UnlockedL1_GetSeed(OpStatus, Seed, ErrorCode);
}


     /* Mode Interfaces */

Std_ReturnType TSC_Dcm_Rte_Switch_DcmCommunicationControl_ComMConf_ComMChannel_CN_CAN00_5e566ad9_DcmCommunicationControl_ComMConf_ComMChannel_CN_CAN00_5e566ad9(Dcm_CommunicationModeType mode)
{
  return Rte_Switch_DcmCommunicationControl_ComMConf_ComMChannel_CN_CAN00_5e566ad9_DcmCommunicationControl_ComMConf_ComMChannel_CN_CAN00_5e566ad9( mode);
}
Std_ReturnType TSC_Dcm_Rte_Switch_DcmControlDtcSetting_DcmControlDtcSetting(Dcm_ControlDtcSettingType mode)
{
  return Rte_Switch_DcmControlDtcSetting_DcmControlDtcSetting( mode);
}
Std_ReturnType TSC_Dcm_Rte_Switch_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(Dcm_DiagnosticSessionControlType mode)
{
  return Rte_Switch_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl( mode);
}
Std_ReturnType TSC_Dcm_Rte_Switch_DcmEcuReset_DcmEcuReset(Dcm_EcuResetType mode)
{
  return Rte_Switch_DcmEcuReset_DcmEcuReset( mode);
}

Std_ReturnType TSC_Dcm_Rte_SwitchAck_DcmEcuReset_DcmEcuReset(void)
{
  return Rte_SwitchAck_DcmEcuReset_DcmEcuReset();
}


     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */







     /* Dcm */
      /* Dcm */



