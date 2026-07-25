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

# define Rte_TypeDef_ComM_InhibitionStatusType
typedef uint8 ComM_InhibitionStatusType;

# define Rte_TypeDef_ComM_UserHandleType
typedef uint16 ComM_UserHandleType;

# define Rte_TypeDef_EcuM_TimeType
typedef uint32 EcuM_TimeType;

# define Rte_TypeDef_TimeInMicrosecondsType
typedef uint32 TimeInMicrosecondsType;

# define Rte_TypeDef_ComM_ModeType
typedef uint8 ComM_ModeType;

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


# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

#  define Rte_TypeDef_dtRef_VOID
typedef void * dtRef_VOID;

#  define Rte_TypeDef_dtRef_const_VOID
typedef const void * dtRef_const_VOID;

#  define Rte_TypeDef_Dem_UdsStatusByteType
typedef uint8 Dem_UdsStatusByteType;

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

# ifdef RTE_CORE

/**********************************************************************************************************************
 * Buffers for unqueued S/R
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(float32, RTE_VAR_NOINIT) Rte_MotorCdd_Pp_MotorDcBusVoltage_Vbus; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(float32, RTE_VAR_NOINIT) Rte_MotorCdd_Pp_MotorElectricalAngle_ElectricAngle; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(boolean, RTE_VAR_NOINIT) Rte_MotorCdd_Pp_MotorFaultStatus_tle9180_Ov_Fault; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(uint8, RTE_VAR_NOINIT) Rte_MotorControll_Pp_MotorCtrlCmd_MotorMode; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(float32, RTE_VAR_NOINIT) Rte_MotorControll_Pp_MotorCurrentRef_Id_Ref; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(float32, RTE_VAR_NOINIT) Rte_MotorControll_Pp_MotorCurrentRef_Iq_Ref; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Internal C/S connections
 *********************************************************************************************************************/

/* Queue element type definitions for internal C/S connections */

typedef struct
{
  boolean arg;
} Rte_CS_ServerQueueType_MotorCdd_Pp_MotorCdd_EnableInverter_EnableInverter;

typedef struct
{
  uint8 Rte_Free;
  uint8 Rte_Active;
} Rte_CS_ServerQueueInfoType_MotorCdd_Pp_MotorCdd_EnableInverter_EnableInverter;

#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(Rte_CS_ServerQueueType_MotorCdd_Pp_MotorCdd_EnableInverter_EnableInverter, RTE_VAR_NOINIT) Rte_CS_ServerQueue_MotorCdd_Pp_MotorCdd_EnableInverter_EnableInverter;
extern VAR(Rte_CS_ServerQueueInfoType_MotorCdd_Pp_MotorCdd_EnableInverter_EnableInverter, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_MotorCdd_Pp_MotorCdd_EnableInverter_EnableInverter;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
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
