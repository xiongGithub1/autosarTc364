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
 *             File:  Rte_MotorCdd.h
 *           Config:  last364.dpa
 *      ECU-Project:  last364
 *
 *        Generator:  MICROSAR RTE Generator Version 4.29.0
 *                    RTE Core Version 1.29.0
 *          License:  CBD2200508
 *
 *      Description:  Application header file for SW-C <MotorCdd>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_MOTORCDD_H
# define RTE_MOTORCDD_H

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

# include "Rte_MotorCdd_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(float32, RTE_VAR_NOINIT) Rte_MotorCdd_Pp_MotorDcBusVoltage_Vbus;
extern VAR(float32, RTE_VAR_NOINIT) Rte_MotorCdd_Pp_MotorElectricalAngle_ElectricAngle;
extern VAR(boolean, RTE_VAR_NOINIT) Rte_MotorCdd_Pp_MotorFaultStatus_tle9180_Ov_Fault;
extern VAR(uint8, RTE_VAR_NOINIT) Rte_MotorControll_Pp_MotorCtrlCmd_MotorMode;
extern VAR(float32, RTE_VAR_NOINIT) Rte_MotorControll_Pp_MotorCurrentRef_Id_Ref;
extern VAR(float32, RTE_VAR_NOINIT) Rte_MotorControll_Pp_MotorCurrentRef_Iq_Ref;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
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
#  define Rte_Read_Pp_MotorCtrlCmd_MotorMode Rte_Read_MotorCdd_Pp_MotorCtrlCmd_MotorMode
#  define Rte_Read_MotorCdd_Pp_MotorCtrlCmd_MotorMode(data) (*(data) = Rte_MotorControll_Pp_MotorCtrlCmd_MotorMode, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Pp_MotorCurrentRef_Id_Ref Rte_Read_MotorCdd_Pp_MotorCurrentRef_Id_Ref
#  define Rte_Read_MotorCdd_Pp_MotorCurrentRef_Id_Ref(data) (*(data) = Rte_MotorControll_Pp_MotorCurrentRef_Id_Ref, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_Pp_MotorCurrentRef_Iq_Ref Rte_Read_MotorCdd_Pp_MotorCurrentRef_Iq_Ref
#  define Rte_Read_MotorCdd_Pp_MotorCurrentRef_Iq_Ref(data) (*(data) = Rte_MotorControll_Pp_MotorCurrentRef_Iq_Ref, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_Pp_MotorDcBusVoltage_Vbus Rte_Write_MotorCdd_Pp_MotorDcBusVoltage_Vbus
#  define Rte_Write_MotorCdd_Pp_MotorDcBusVoltage_Vbus(data) (Rte_MotorCdd_Pp_MotorDcBusVoltage_Vbus = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_MotorElectricalAngle_ElectricAngle Rte_Write_MotorCdd_Pp_MotorElectricalAngle_ElectricAngle
#  define Rte_Write_MotorCdd_Pp_MotorElectricalAngle_ElectricAngle(data) (Rte_MotorCdd_Pp_MotorElectricalAngle_ElectricAngle = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_Pp_MotorFaultStatus_tle9180_Ov_Fault Rte_Write_MotorCdd_Pp_MotorFaultStatus_tle9180_Ov_Fault
#  define Rte_Write_MotorCdd_Pp_MotorFaultStatus_tle9180_Ov_Fault(data) (Rte_MotorCdd_Pp_MotorFaultStatus_tle9180_Ov_Fault = (data), ((Std_ReturnType)RTE_E_OK))


# endif /* !defined(RTE_CORE) */


# define MotorCdd_START_SEC_CODE
# include "MotorCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_MotorCDDMainFunction MotorCDDMainFunction
#  define RTE_RUNNABLE_MotorCdd_AdcOnSampleReady MotorCdd_AdcOnSampleReady
#  define RTE_RUNNABLE_MotorCdd_Init MotorCdd_Init
#  define RTE_RUNNABLE_Pp_MotorCdd_EnableInverter_EnableInverter Pp_MotorCdd_EnableInverter_EnableInverter
# endif

FUNC(void, MotorCdd_CODE) MotorCDDMainFunction(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, MotorCdd_CODE) MotorCdd_AdcOnSampleReady(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, MotorCdd_CODE) MotorCdd_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, MotorCdd_CODE) Pp_MotorCdd_EnableInverter_EnableInverter(boolean arg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define MotorCdd_STOP_SEC_CODE
# include "MotorCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_MOTORCDD_H */

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
