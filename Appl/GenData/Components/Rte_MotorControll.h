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
 *             File:  Rte_MotorControll.h
 *           Config:  last364.dpa
 *      ECU-Project:  last364
 *
 *        Generator:  MICROSAR RTE Generator Version 4.29.0
 *                    RTE Core Version 1.29.0
 *          License:  CBD2200508
 *
 *      Description:  Application header file for SW-C <MotorControll>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_MOTORCONTROLL_H
# define RTE_MOTORCONTROLL_H

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

# include "Rte_MotorControll_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(uint8, RTE_VAR_INIT) Rte_MotorControll_Pp_MotorCtrlCmd_MotorMode;
extern VAR(float32, RTE_VAR_INIT) Rte_MotorControll_Pp_MotorCurrentRef_Id_Ref;
extern VAR(float32, RTE_VAR_INIT) Rte_MotorControll_Pp_MotorCurrentRef_Iq_Ref;
extern VAR(float32, RTE_VAR_INIT) Rte_MotorCdd_Pp_MotorDcBusVoltage_Vbus;
extern VAR(float32, RTE_VAR_INIT) Rte_MotorCdd_Pp_MotorElectricalAngle_ElectricAngle;
extern VAR(boolean, RTE_VAR_INIT) Rte_MotorCdd_Pp_MotorFaultStatus_tle9180_Ov_Fault;

#  define RTE_STOP_SEC_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_Pp_MotorCtrlCmd_MotorMode (0U)
#  define Rte_InitValue_Pp_MotorCurrentRef_Id_Ref (0.0F)
#  define Rte_InitValue_Pp_MotorCurrentRef_Iq_Ref (0.0F)
#  define Rte_InitValue_Pp_MotorDcBusVoltage_Vbus (0.0F)
#  define Rte_InitValue_Pp_MotorElectricalAngle_ElectricAngle (0.0F)
#  define Rte_InitValue_Pp_MotorFaultStatus_tle9180_Ov_Fault (FALSE)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_Pp_MotorDcBusVoltage_Vbus Rte_Read_MotorControll_Pp_MotorDcBusVoltage_Vbus
#  define Rte_Read_MotorControll_Pp_MotorDcBusVoltage_Vbus(data) (*(data) = Rte_MotorCdd_Pp_MotorDcBusVoltage_Vbus, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Pp_MotorElectricalAngle_ElectricAngle Rte_Read_MotorControll_Pp_MotorElectricalAngle_ElectricAngle
#  define Rte_Read_MotorControll_Pp_MotorElectricalAngle_ElectricAngle(data) (*(data) = Rte_MotorCdd_Pp_MotorElectricalAngle_ElectricAngle, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Pp_MotorFaultStatus_tle9180_Ov_Fault Rte_Read_MotorControll_Pp_MotorFaultStatus_tle9180_Ov_Fault
#  define Rte_Read_MotorControll_Pp_MotorFaultStatus_tle9180_Ov_Fault(data) (*(data) = Rte_MotorCdd_Pp_MotorFaultStatus_tle9180_Ov_Fault, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Pp_MotorCtrlCmd_MotorMode Rte_Write_MotorControll_Pp_MotorCtrlCmd_MotorMode
#  define Rte_Write_MotorControll_Pp_MotorCtrlCmd_MotorMode(data) (Rte_MotorControll_Pp_MotorCtrlCmd_MotorMode = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_MotorCurrentRef_Id_Ref Rte_Write_MotorControll_Pp_MotorCurrentRef_Id_Ref
#  define Rte_Write_MotorControll_Pp_MotorCurrentRef_Id_Ref(data) (Rte_MotorControll_Pp_MotorCurrentRef_Id_Ref = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_MotorCurrentRef_Iq_Ref Rte_Write_MotorControll_Pp_MotorCurrentRef_Iq_Ref
#  define Rte_Write_MotorControll_Pp_MotorCurrentRef_Iq_Ref(data) (Rte_MotorControll_Pp_MotorCurrentRef_Iq_Ref = (data), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define MotorControll_START_SEC_CODE
# include "MotorControll_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_MotorControll_Init MotorControll_Init
#  define RTE_RUNNABLE_MotorControll_MainFunction MotorControll_MainFunction
# endif

FUNC(void, MotorControll_CODE) MotorControll_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, MotorControll_CODE) MotorControll_MainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define MotorControll_STOP_SEC_CODE
# include "MotorControll_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_MOTORCONTROLL_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
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
