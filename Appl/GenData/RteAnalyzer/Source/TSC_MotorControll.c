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
 *             File:  TSC_MotorControll.c
 *           Config:  last364.dpa
 *        SW-C Type:  MotorControll
 *
 *        Generator:  MICROSAR RTE Generator Version 4.29.0
 *                    RTE Core Version 1.29.0
 *          License:  CBD2200508
 *
 *      Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_MotorControll.h"
#include "TSC_MotorControll.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */






Std_ReturnType TSC_MotorControll_Rte_Read_Pp_MotorDcBusVoltage_Vbus(float32 *data)
{
  return Rte_Read_Pp_MotorDcBusVoltage_Vbus(data);
}

Std_ReturnType TSC_MotorControll_Rte_Read_Pp_MotorElectricalAngle_ElectricAngle(float32 *data)
{
  return Rte_Read_Pp_MotorElectricalAngle_ElectricAngle(data);
}

Std_ReturnType TSC_MotorControll_Rte_Read_Pp_MotorFaultStatus_tle9180_Ov_Fault(boolean *data)
{
  return Rte_Read_Pp_MotorFaultStatus_tle9180_Ov_Fault(data);
}




Std_ReturnType TSC_MotorControll_Rte_Write_Pp_MotorCtrlCmd_MotorMode(uint8 data)
{
  return Rte_Write_Pp_MotorCtrlCmd_MotorMode(data);
}

Std_ReturnType TSC_MotorControll_Rte_Write_Pp_MotorCurrentRef_Id_Ref(float32 data)
{
  return Rte_Write_Pp_MotorCurrentRef_Id_Ref(data);
}

Std_ReturnType TSC_MotorControll_Rte_Write_Pp_MotorCurrentRef_Iq_Ref(float32 data)
{
  return Rte_Write_Pp_MotorCurrentRef_Iq_Ref(data);
}





     /* Client Server Interfaces: */


     /* Service calls */
Std_ReturnType TSC_MotorControll_Rte_Call_Pp_MotorCdd_EnableInverter_EnableInverter(boolean arg)
{
  return Rte_Call_Pp_MotorCdd_EnableInverter_EnableInverter(arg);
}


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */







     /* MotorControll */
      /* MotorControll */



