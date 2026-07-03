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
 *             File:  Rte_Hook.h
 *           Config:  last364.dpa
 *      ECU-Project:  last364
 *
 *        Generator:  MICROSAR RTE Generator Version 4.29.0
 *                    RTE Core Version 1.29.0
 *          License:  CBD2200508
 *
 *      Description:  Header file containing definitions for VFB tracing
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Names of available VFB-Trace-Hooks
 **********************************************************************************************************************
 *
 * Not configured:
 *
 *  Rte_Runnable_BswM_BswM_MainFunction_Return
 *  Rte_Runnable_BswM_BswM_MainFunction_Start
 *  Rte_Runnable_ComM_ComM_MainFunction_0_Return
 *  Rte_Runnable_ComM_ComM_MainFunction_0_Start
 *  Rte_Runnable_ComM_GetCurrentComMode_Return
 *  Rte_Runnable_ComM_GetCurrentComMode_Start
 *  Rte_Runnable_ComM_GetInhibitionStatus_Return
 *  Rte_Runnable_ComM_GetInhibitionStatus_Start
 *  Rte_Runnable_ComM_GetMaxComMode_Return
 *  Rte_Runnable_ComM_GetMaxComMode_Start
 *  Rte_Runnable_ComM_GetRequestedComMode_Return
 *  Rte_Runnable_ComM_GetRequestedComMode_Start
 *  Rte_Runnable_ComM_LimitChannelToNoComMode_Return
 *  Rte_Runnable_ComM_LimitChannelToNoComMode_Start
 *  Rte_Runnable_ComM_LimitECUToNoComMode_Return
 *  Rte_Runnable_ComM_LimitECUToNoComMode_Start
 *  Rte_Runnable_ComM_PreventWakeUp_Return
 *  Rte_Runnable_ComM_PreventWakeUp_Start
 *  Rte_Runnable_ComM_ReadInhibitCounter_Return
 *  Rte_Runnable_ComM_ReadInhibitCounter_Start
 *  Rte_Runnable_ComM_RequestComMode_Return
 *  Rte_Runnable_ComM_RequestComMode_Start
 *  Rte_Runnable_ComM_ResetInhibitCounter_Return
 *  Rte_Runnable_ComM_ResetInhibitCounter_Start
 *  Rte_Runnable_ComM_SetECUGroupClassification_Return
 *  Rte_Runnable_ComM_SetECUGroupClassification_Start
 *  Rte_Runnable_EcuM_EcuM_MainFunction_Return
 *  Rte_Runnable_EcuM_EcuM_MainFunction_Start
 *  Rte_Runnable_EcuM_GetBootTarget_Return
 *  Rte_Runnable_EcuM_GetBootTarget_Start
 *  Rte_Runnable_EcuM_GetLastShutdownTarget_Return
 *  Rte_Runnable_EcuM_GetLastShutdownTarget_Start
 *  Rte_Runnable_EcuM_GetShutdownCause_Return
 *  Rte_Runnable_EcuM_GetShutdownCause_Start
 *  Rte_Runnable_EcuM_GetShutdownTarget_Return
 *  Rte_Runnable_EcuM_GetShutdownTarget_Start
 *  Rte_Runnable_EcuM_GetStateWrapper_Return
 *  Rte_Runnable_EcuM_GetStateWrapper_Start
 *  Rte_Runnable_EcuM_ReleasePOSTRUN_Return
 *  Rte_Runnable_EcuM_ReleasePOSTRUN_Start
 *  Rte_Runnable_EcuM_ReleaseRUN_Return
 *  Rte_Runnable_EcuM_ReleaseRUN_Start
 *  Rte_Runnable_EcuM_RequestPOSTRUN_Return
 *  Rte_Runnable_EcuM_RequestPOSTRUN_Start
 *  Rte_Runnable_EcuM_RequestRUN_Return
 *  Rte_Runnable_EcuM_RequestRUN_Start
 *  Rte_Runnable_EcuM_SelectBootTarget_Return
 *  Rte_Runnable_EcuM_SelectBootTarget_Start
 *  Rte_Runnable_EcuM_SelectShutdownCause_Return
 *  Rte_Runnable_EcuM_SelectShutdownCause_Start
 *  Rte_Runnable_EcuM_SelectShutdownTarget_Return
 *  Rte_Runnable_EcuM_SelectShutdownTarget_Start
 *  Rte_Runnable_Os_OsCore0_swc_GetCounterValue_Return
 *  Rte_Runnable_Os_OsCore0_swc_GetCounterValue_Start
 *  Rte_Runnable_Os_OsCore0_swc_GetElapsedValue_Return
 *  Rte_Runnable_Os_OsCore0_swc_GetElapsedValue_Start
 *  Rte_Runnable_StartApp_StartApp_Cyclic1000ms_Return
 *  Rte_Runnable_StartApp_StartApp_Cyclic1000ms_Start
 *  Rte_Runnable_StartApp_StartApp_Cyclic10ms_Return
 *  Rte_Runnable_StartApp_StartApp_Cyclic10ms_Start
 *  Rte_Runnable_StartApp_StartApp_Cyclic1ms_Return
 *  Rte_Runnable_StartApp_StartApp_Cyclic1ms_Start
 *  Rte_Runnable_StartApp_StartApp_Cyclic250ms_Return
 *  Rte_Runnable_StartApp_StartApp_Cyclic250ms_Start
 *  Rte_Runnable_StartApp_StartApp_Init_Return
 *  Rte_Runnable_StartApp_StartApp_Init_Start
 *  Rte_SwitchAckHook_EcuM_currentMode_currentMode_Return
 *  Rte_SwitchAckHook_EcuM_currentMode_currentMode_Start
 *  Rte_SwitchHook_EcuM_currentMode_currentMode_Return
 *  Rte_SwitchHook_EcuM_currentMode_currentMode_Start
 *  Rte_Task_Activate
 *  Rte_Task_Dispatch
 *  Rte_Task_Terminate
 *  Rte_Task_WaitEvent
 *  Rte_Task_WaitEventRet
 *  SchM_EnterHook_Adc_KernelData_Return
 *  SchM_EnterHook_Adc_KernelData_Start
 *  SchM_EnterHook_Adc_SrcRegAccess_Return
 *  SchM_EnterHook_Adc_SrcRegAccess_Start
 *  SchM_EnterHook_BswM_BSWM_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_BswM_BSWM_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_1_Return
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_1_Start
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_2_Return
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_2_Start
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_3_Return
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_3_Start
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_4_Return
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_4_Start
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_5_Return
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_5_Start
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_6_Return
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_6_Start
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_7_Return
 *  SchM_EnterHook_CanIf_CANIF_EXCLUSIVE_AREA_7_Start
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_1_Return
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_1_Start
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_2_Return
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_2_Start
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_3_Return
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_3_Start
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_4_Return
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_4_Start
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_5_Return
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_5_Start
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_6_Return
 *  SchM_EnterHook_CanSM_CANSM_EXCLUSIVE_AREA_6_Start
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_1_Return
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_1_Start
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_2_Return
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_2_Start
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_3_Return
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_3_Start
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_4_Return
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_4_Start
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_5_Return
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_5_Start
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_6_Return
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_6_Start
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_7_Return
 *  SchM_EnterHook_Can_CAN_EXCLUSIVE_AREA_7_Start
 *  SchM_EnterHook_ComM_COMM_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_ComM_COMM_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_ComM_COMM_EXCLUSIVE_AREA_1_Return
 *  SchM_EnterHook_ComM_COMM_EXCLUSIVE_AREA_1_Start
 *  SchM_EnterHook_ComM_COMM_EXCLUSIVE_AREA_2_Return
 *  SchM_EnterHook_ComM_COMM_EXCLUSIVE_AREA_2_Start
 *  SchM_EnterHook_ComM_COMM_EXCLUSIVE_AREA_3_Return
 *  SchM_EnterHook_ComM_COMM_EXCLUSIVE_AREA_3_Start
 *  SchM_EnterHook_ComM_COMM_EXCLUSIVE_AREA_4_Return
 *  SchM_EnterHook_ComM_COMM_EXCLUSIVE_AREA_4_Start
 *  SchM_EnterHook_ComM_COMM_EXCLUSIVE_AREA_5_Return
 *  SchM_EnterHook_ComM_COMM_EXCLUSIVE_AREA_5_Start
 *  SchM_EnterHook_ComM_COMM_EXCLUSIVE_AREA_6_Return
 *  SchM_EnterHook_ComM_COMM_EXCLUSIVE_AREA_6_Start
 *  SchM_EnterHook_ComM_COMM_EXCLUSIVE_AREA_7_Return
 *  SchM_EnterHook_ComM_COMM_EXCLUSIVE_AREA_7_Start
 *  SchM_EnterHook_Com_COM_EXCLUSIVE_AREA_BOTH_Return
 *  SchM_EnterHook_Com_COM_EXCLUSIVE_AREA_BOTH_Start
 *  SchM_EnterHook_Com_COM_EXCLUSIVE_AREA_RX_Return
 *  SchM_EnterHook_Com_COM_EXCLUSIVE_AREA_RX_Start
 *  SchM_EnterHook_Com_COM_EXCLUSIVE_AREA_TX_Return
 *  SchM_EnterHook_Com_COM_EXCLUSIVE_AREA_TX_Start
 *  SchM_EnterHook_Det_DET_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_Det_DET_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_Dma_ChEventStatus_Return
 *  SchM_EnterHook_Dma_ChEventStatus_Start
 *  SchM_EnterHook_Dma_ChannelConfigUpdate_Return
 *  SchM_EnterHook_Dma_ChannelConfigUpdate_Start
 *  SchM_EnterHook_Dma_ChannelFreezeResume_Return
 *  SchM_EnterHook_Dma_ChannelFreezeResume_Start
 *  SchM_EnterHook_Dma_ChannelHWTrigger_Return
 *  SchM_EnterHook_Dma_ChannelHWTrigger_Start
 *  SchM_EnterHook_Dma_ChannelInitDeinit_Return
 *  SchM_EnterHook_Dma_ChannelInitDeinit_Start
 *  SchM_EnterHook_Dma_ChannelStartStop_Return
 *  SchM_EnterHook_Dma_ChannelStartStop_Start
 *  SchM_EnterHook_Dma_ChannelSwitchBuffer_Return
 *  SchM_EnterHook_Dma_ChannelSwitchBuffer_Start
 *  SchM_EnterHook_Dma_InterruptStatus_Return
 *  SchM_EnterHook_Dma_InterruptStatus_Start
 *  SchM_EnterHook_Dma_MEErrorStatus_Return
 *  SchM_EnterHook_Dma_MEErrorStatus_Start
 *  SchM_EnterHook_EcuM_ECUM_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_EcuM_ECUM_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_EcuM_ECUM_EXCLUSIVE_AREA_1_Return
 *  SchM_EnterHook_EcuM_ECUM_EXCLUSIVE_AREA_1_Start
 *  SchM_EnterHook_EcuM_ECUM_EXCLUSIVE_AREA_2_Return
 *  SchM_EnterHook_EcuM_ECUM_EXCLUSIVE_AREA_2_Start
 *  SchM_EnterHook_EcuM_ECUM_EXCLUSIVE_AREA_3_Return
 *  SchM_EnterHook_EcuM_ECUM_EXCLUSIVE_AREA_3_Start
 *  SchM_EnterHook_McalLib_CpuEndInit_Return
 *  SchM_EnterHook_McalLib_CpuEndInit_Start
 *  SchM_EnterHook_McalLib_PeripheralEndInit_Return
 *  SchM_EnterHook_McalLib_PeripheralEndInit_Start
 *  SchM_EnterHook_McalLib_SafetyEndInit_Return
 *  SchM_EnterHook_McalLib_SafetyEndInit_Start
 *  SchM_EnterHook_McalLib_StmTimerResolution_Return
 *  SchM_EnterHook_McalLib_StmTimerResolution_Start
 *  SchM_EnterHook_Mcu_AtomAgcReg_Return
 *  SchM_EnterHook_Mcu_AtomAgcReg_Start
 *  SchM_EnterHook_Mcu_TomTgcReg_Return
 *  SchM_EnterHook_Mcu_TomTgcReg_Start
 *  SchM_EnterHook_PduR_PDUR_EXCLUSIVE_AREA_0_Return
 *  SchM_EnterHook_PduR_PDUR_EXCLUSIVE_AREA_0_Start
 *  SchM_EnterHook_Spi_Buffer_Update_Return
 *  SchM_EnterHook_Spi_Buffer_Update_Start
 *  SchM_EnterHook_Spi_Cancel_Seq_Return
 *  SchM_EnterHook_Spi_Cancel_Seq_Start
 *  SchM_EnterHook_Spi_ChannelLock_Return
 *  SchM_EnterHook_Spi_ChannelLock_Start
 *  SchM_EnterHook_Spi_Queue_Update_QSPI0_Return
 *  SchM_EnterHook_Spi_Queue_Update_QSPI0_Start
 *  SchM_EnterHook_Spi_Queue_Update_QSPI1_Return
 *  SchM_EnterHook_Spi_Queue_Update_QSPI1_Start
 *  SchM_EnterHook_Spi_Queue_Update_QSPI2_Return
 *  SchM_EnterHook_Spi_Queue_Update_QSPI2_Start
 *  SchM_EnterHook_Spi_Queue_Update_QSPI3_Return
 *  SchM_EnterHook_Spi_Queue_Update_QSPI3_Start
 *  SchM_EnterHook_Spi_Queue_Update_QSPI4_Return
 *  SchM_EnterHook_Spi_Queue_Update_QSPI4_Start
 *  SchM_EnterHook_Spi_Queue_Update_QSPI5_Return
 *  SchM_EnterHook_Spi_Queue_Update_QSPI5_Start
 *  SchM_EnterHook_Spi_Queue_Update_Return
 *  SchM_EnterHook_Spi_Queue_Update_Start
 *  SchM_EnterHook_Spi_SyncLock_Return
 *  SchM_EnterHook_Spi_SyncLock_Start
 *  SchM_ExitHook_Adc_KernelData_Return
 *  SchM_ExitHook_Adc_KernelData_Start
 *  SchM_ExitHook_Adc_SrcRegAccess_Return
 *  SchM_ExitHook_Adc_SrcRegAccess_Start
 *  SchM_ExitHook_BswM_BSWM_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_BswM_BSWM_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_1_Return
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_1_Start
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_2_Return
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_2_Start
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_3_Return
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_3_Start
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_4_Return
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_4_Start
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_5_Return
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_5_Start
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_6_Return
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_6_Start
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_7_Return
 *  SchM_ExitHook_CanIf_CANIF_EXCLUSIVE_AREA_7_Start
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_1_Return
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_1_Start
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_2_Return
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_2_Start
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_3_Return
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_3_Start
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_4_Return
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_4_Start
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_5_Return
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_5_Start
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_6_Return
 *  SchM_ExitHook_CanSM_CANSM_EXCLUSIVE_AREA_6_Start
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_1_Return
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_1_Start
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_2_Return
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_2_Start
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_3_Return
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_3_Start
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_4_Return
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_4_Start
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_5_Return
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_5_Start
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_6_Return
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_6_Start
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_7_Return
 *  SchM_ExitHook_Can_CAN_EXCLUSIVE_AREA_7_Start
 *  SchM_ExitHook_ComM_COMM_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_ComM_COMM_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_ComM_COMM_EXCLUSIVE_AREA_1_Return
 *  SchM_ExitHook_ComM_COMM_EXCLUSIVE_AREA_1_Start
 *  SchM_ExitHook_ComM_COMM_EXCLUSIVE_AREA_2_Return
 *  SchM_ExitHook_ComM_COMM_EXCLUSIVE_AREA_2_Start
 *  SchM_ExitHook_ComM_COMM_EXCLUSIVE_AREA_3_Return
 *  SchM_ExitHook_ComM_COMM_EXCLUSIVE_AREA_3_Start
 *  SchM_ExitHook_ComM_COMM_EXCLUSIVE_AREA_4_Return
 *  SchM_ExitHook_ComM_COMM_EXCLUSIVE_AREA_4_Start
 *  SchM_ExitHook_ComM_COMM_EXCLUSIVE_AREA_5_Return
 *  SchM_ExitHook_ComM_COMM_EXCLUSIVE_AREA_5_Start
 *  SchM_ExitHook_ComM_COMM_EXCLUSIVE_AREA_6_Return
 *  SchM_ExitHook_ComM_COMM_EXCLUSIVE_AREA_6_Start
 *  SchM_ExitHook_ComM_COMM_EXCLUSIVE_AREA_7_Return
 *  SchM_ExitHook_ComM_COMM_EXCLUSIVE_AREA_7_Start
 *  SchM_ExitHook_Com_COM_EXCLUSIVE_AREA_BOTH_Return
 *  SchM_ExitHook_Com_COM_EXCLUSIVE_AREA_BOTH_Start
 *  SchM_ExitHook_Com_COM_EXCLUSIVE_AREA_RX_Return
 *  SchM_ExitHook_Com_COM_EXCLUSIVE_AREA_RX_Start
 *  SchM_ExitHook_Com_COM_EXCLUSIVE_AREA_TX_Return
 *  SchM_ExitHook_Com_COM_EXCLUSIVE_AREA_TX_Start
 *  SchM_ExitHook_Det_DET_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_Det_DET_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_Dma_ChEventStatus_Return
 *  SchM_ExitHook_Dma_ChEventStatus_Start
 *  SchM_ExitHook_Dma_ChannelConfigUpdate_Return
 *  SchM_ExitHook_Dma_ChannelConfigUpdate_Start
 *  SchM_ExitHook_Dma_ChannelFreezeResume_Return
 *  SchM_ExitHook_Dma_ChannelFreezeResume_Start
 *  SchM_ExitHook_Dma_ChannelHWTrigger_Return
 *  SchM_ExitHook_Dma_ChannelHWTrigger_Start
 *  SchM_ExitHook_Dma_ChannelInitDeinit_Return
 *  SchM_ExitHook_Dma_ChannelInitDeinit_Start
 *  SchM_ExitHook_Dma_ChannelStartStop_Return
 *  SchM_ExitHook_Dma_ChannelStartStop_Start
 *  SchM_ExitHook_Dma_ChannelSwitchBuffer_Return
 *  SchM_ExitHook_Dma_ChannelSwitchBuffer_Start
 *  SchM_ExitHook_Dma_InterruptStatus_Return
 *  SchM_ExitHook_Dma_InterruptStatus_Start
 *  SchM_ExitHook_Dma_MEErrorStatus_Return
 *  SchM_ExitHook_Dma_MEErrorStatus_Start
 *  SchM_ExitHook_EcuM_ECUM_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_EcuM_ECUM_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_EcuM_ECUM_EXCLUSIVE_AREA_1_Return
 *  SchM_ExitHook_EcuM_ECUM_EXCLUSIVE_AREA_1_Start
 *  SchM_ExitHook_EcuM_ECUM_EXCLUSIVE_AREA_2_Return
 *  SchM_ExitHook_EcuM_ECUM_EXCLUSIVE_AREA_2_Start
 *  SchM_ExitHook_EcuM_ECUM_EXCLUSIVE_AREA_3_Return
 *  SchM_ExitHook_EcuM_ECUM_EXCLUSIVE_AREA_3_Start
 *  SchM_ExitHook_McalLib_CpuEndInit_Return
 *  SchM_ExitHook_McalLib_CpuEndInit_Start
 *  SchM_ExitHook_McalLib_PeripheralEndInit_Return
 *  SchM_ExitHook_McalLib_PeripheralEndInit_Start
 *  SchM_ExitHook_McalLib_SafetyEndInit_Return
 *  SchM_ExitHook_McalLib_SafetyEndInit_Start
 *  SchM_ExitHook_McalLib_StmTimerResolution_Return
 *  SchM_ExitHook_McalLib_StmTimerResolution_Start
 *  SchM_ExitHook_Mcu_AtomAgcReg_Return
 *  SchM_ExitHook_Mcu_AtomAgcReg_Start
 *  SchM_ExitHook_Mcu_TomTgcReg_Return
 *  SchM_ExitHook_Mcu_TomTgcReg_Start
 *  SchM_ExitHook_PduR_PDUR_EXCLUSIVE_AREA_0_Return
 *  SchM_ExitHook_PduR_PDUR_EXCLUSIVE_AREA_0_Start
 *  SchM_ExitHook_Spi_Buffer_Update_Return
 *  SchM_ExitHook_Spi_Buffer_Update_Start
 *  SchM_ExitHook_Spi_Cancel_Seq_Return
 *  SchM_ExitHook_Spi_Cancel_Seq_Start
 *  SchM_ExitHook_Spi_ChannelLock_Return
 *  SchM_ExitHook_Spi_ChannelLock_Start
 *  SchM_ExitHook_Spi_Queue_Update_QSPI0_Return
 *  SchM_ExitHook_Spi_Queue_Update_QSPI0_Start
 *  SchM_ExitHook_Spi_Queue_Update_QSPI1_Return
 *  SchM_ExitHook_Spi_Queue_Update_QSPI1_Start
 *  SchM_ExitHook_Spi_Queue_Update_QSPI2_Return
 *  SchM_ExitHook_Spi_Queue_Update_QSPI2_Start
 *  SchM_ExitHook_Spi_Queue_Update_QSPI3_Return
 *  SchM_ExitHook_Spi_Queue_Update_QSPI3_Start
 *  SchM_ExitHook_Spi_Queue_Update_QSPI4_Return
 *  SchM_ExitHook_Spi_Queue_Update_QSPI4_Start
 *  SchM_ExitHook_Spi_Queue_Update_QSPI5_Return
 *  SchM_ExitHook_Spi_Queue_Update_QSPI5_Start
 *  SchM_ExitHook_Spi_Queue_Update_Return
 *  SchM_ExitHook_Spi_Queue_Update_Start
 *  SchM_ExitHook_Spi_SyncLock_Return
 *  SchM_ExitHook_Spi_SyncLock_Start
 *  SchM_Schedulable_BswM_BswM_MainFunction_Return
 *  SchM_Schedulable_BswM_BswM_MainFunction_Start
 *  SchM_Schedulable_CanSM_CanSM_MainFunction_Return
 *  SchM_Schedulable_CanSM_CanSM_MainFunction_Start
 *  SchM_Schedulable_Can_Can_MainFunction_BusOff_Return
 *  SchM_Schedulable_Can_Can_MainFunction_BusOff_Start
 *  SchM_Schedulable_Can_Can_MainFunction_Mode_Return
 *  SchM_Schedulable_Can_Can_MainFunction_Mode_Start
 *  SchM_Schedulable_Can_Can_MainFunction_Read_Return
 *  SchM_Schedulable_Can_Can_MainFunction_Read_Start
 *  SchM_Schedulable_Can_Can_MainFunction_Wakeup_Return
 *  SchM_Schedulable_Can_Can_MainFunction_Wakeup_Start
 *  SchM_Schedulable_Can_Can_MainFunction_Write_Return
 *  SchM_Schedulable_Can_Can_MainFunction_Write_Start
 *  SchM_Schedulable_ComM_ComM_MainFunction_0_Return
 *  SchM_Schedulable_ComM_ComM_MainFunction_0_Start
 *  SchM_Schedulable_Com_Com_MainFunctionRx_ComMainFunctionRx_Return
 *  SchM_Schedulable_Com_Com_MainFunctionRx_ComMainFunctionRx_Start
 *  SchM_Schedulable_Com_Com_MainFunctionTx_ComMainFunctionTx_Return
 *  SchM_Schedulable_Com_Com_MainFunctionTx_ComMainFunctionTx_Start
 *  SchM_Schedulable_EcuM_EcuM_MainFunction_Return
 *  SchM_Schedulable_EcuM_EcuM_MainFunction_Start
 *  SchM_Schedulable_Spi_Spi_MainFunction_Handling_Return
 *  SchM_Schedulable_Spi_Spi_MainFunction_Handling_Start
 *
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_HOOK_H
# define RTE_HOOK_H

# include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_Dir1.1, MD_Rte_Os */

# include "Rte_Type.h"
# include "Rte_Cfg.h"

# ifndef RTE_VFB_TRACE
#  define RTE_VFB_TRACE (0)
# endif

#endif /* RTE_HOOK_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
