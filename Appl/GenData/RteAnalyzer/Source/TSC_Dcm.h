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
 *             File:  TSC_Dcm.h
 *           Config:  last364.dpa
 *        SW-C Type:  Dcm
 *
 *        Generator:  MICROSAR RTE Generator Version 4.29.0
 *                    RTE Core Version 1.29.0
 *          License:  CBD2200508
 *
 *      Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Service interfaces */
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Boot_Software_Boot_Software_Identification_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Boot_Software_Boot_Software_Identification_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Boot_Software_Boot_Software_Identification_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Boot_Software_NumberOfModules_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Boot_Software_NumberOfModules_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Boot_Software_NumberOfModules_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_0xF410_DID_Data_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_0xF410_DID_Data_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_0xF412_DID_Data_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_0xF412_DID_Data_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_0xF413_DID_Data_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DID_0xF413_DID_Data_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DataDiagnosticIdentifier_DID_DataDiagnosticIdentifier_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_CanDriverVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_CanDriverVersion_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_CanDriverVersion_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_DiagnosticModuleVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_DiagnosticModuleVersion_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_DiagnosticModuleVersion_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_NmVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_NmVersion_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_NmVersion_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_OperatingSystemVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_OperatingSystemVersion_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_OperatingSystemVersion_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_TransportLayerVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_TransportLayerVersion_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_DevelopmentData_TransportLayerVersion_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_EcuIdentification_Part_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_EcuIdentification_Part_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_EcuIdentification_Part_Number_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Example_ReadOnlyDID_DID_Data_GlobalTime_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Example_ReadOnlyDID_DID_Data_GlobalTime_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Example_ReadWriteData_GlobalTime_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Example_ReadWriteData_GlobalTime_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Example_ReadWriteData_GlobalTime_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Example_WriteOnlyDID_DID_DataObject_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Hardware_Version_Hardware_Version_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Hardware_Version_Hardware_Version_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Hardware_Version_Hardware_Version_Number_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_SampleIoControl_DID_Data_FreezeCurrentState(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_SampleIoControl_DID_Data_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_SampleIoControl_DID_Data_ResetToDefault(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_SampleIoControl_DID_Data_ReturnControlToECU(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_SampleIoControl_DID_Data_ShortTermAdjustment(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_SerialNumber_SerialNumber_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_SerialNumber_SerialNumber_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_SerialNumber_SerialNumber_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Spare_Part_Number_Spare_Part_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Spare_Part_Number_Spare_Part_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Spare_Part_Number_Spare_Part_Number_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Vehicle_Identification_VIN_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Vehicle_Identification_VIN_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data);
Std_ReturnType TSC_Dcm_Rte_Call_DataServices_Vehicle_Identification_VIN_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_SampleRoutineControl_RequestResults(Dcm_OpStatusType OpStatus, Dcm_RequestDataOut_SampleRoutineControl_Out_ResultType *Out_Result, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_SampleRoutineControl_Start(Dcm_StartDataIn_SampleRoutineControl_In_Option0Type In_Option0, Dcm_OpStatusType OpStatus, Dcm_StartDataOut_SampleRoutineControl_Out_InitStateType *Out_InitState, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_SampleRoutineControl_Stop(Dcm_OpStatusType OpStatus, Dcm_StopDataOut_SampleRoutineControl_Out_StopStateType *Out_StopState, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_SampleRoutineControl_StartOnly_RequestResults(Dcm_OpStatusType OpStatus, Dcm_RequestDataOut_SampleRoutineControl_StartOnly_Out_ResultType *Out_Result, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_RoutineServices_SampleRoutineControl_StartOnly_Start(const Dcm_StartDataIn_SampleRoutineControl_StartOnly_In_Option1ArrayType *In_Option1, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_SecurityAccess_Level_3_CompareKey(const uint8 *Key, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_SecurityAccess_Level_3_GetSeed(Dcm_OpStatusType OpStatus, uint8 *Seed, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_SecurityAccess_UnlockedL1_CompareKey(const uint8 *Key, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode);
Std_ReturnType TSC_Dcm_Rte_Call_SecurityAccess_UnlockedL1_GetSeed(Dcm_OpStatusType OpStatus, uint8 *Seed, Dcm_NegativeResponseCodeType *ErrorCode);

/** Mode switches */
Std_ReturnType TSC_Dcm_Rte_Switch_DcmCommunicationControl_ComMConf_ComMChannel_CN_CAN00_5e566ad9_DcmCommunicationControl_ComMConf_ComMChannel_CN_CAN00_5e566ad9(Dcm_CommunicationModeType mode);
Std_ReturnType TSC_Dcm_Rte_Switch_DcmControlDtcSetting_DcmControlDtcSetting(Dcm_ControlDtcSettingType mode);
Std_ReturnType TSC_Dcm_Rte_Switch_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(Dcm_DiagnosticSessionControlType mode);
Std_ReturnType TSC_Dcm_Rte_Switch_DcmEcuReset_DcmEcuReset(Dcm_EcuResetType mode);

/** Mode switch acknowledgement */
Std_ReturnType TSC_Dcm_Rte_SwitchAck_DcmEcuReset_DcmEcuReset(void);




