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
 *             File:  TSC_DemMaster_0.h
 *           Config:  last364.dpa
 *        SW-C Type:  DemMaster_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.29.0
 *                    RTE Core Version 1.29.0
 *          License:  CBD2200508
 *
 *      Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Service interfaces */
Std_ReturnType TSC_DemMaster_0_Rte_Call_CBInitEvt_DTC_0x000002_InitMonitorForEvent(Dem_InitMonitorReasonType InitMonitorReason);
Std_ReturnType TSC_DemMaster_0_Rte_Call_CBReadData_DID_0x1_DID_Data_GlobalTime_ReadData(uint8 *Data);
Std_ReturnType TSC_DemMaster_0_Rte_Call_CBReadData_PID_0x12_DID_Data_ReadData(DataPrimitiveType_uint16 *Data);
Std_ReturnType TSC_DemMaster_0_Rte_Call_CBReadData_PID_0x13_DID_Data_ReadData(DataPrimitiveType_uint16 *Data);




