/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program: MSR_Vector_SLP4
 *          Customer: China Lithium Battery Technology Co., Ltd.
 *       Expiry Date: 2025-08-26
 *  Ordered Derivat.: SAK-TC387QP-160F300S AE
 *    License Scope : The usage is restricted to CBD2200508_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Types_Lcfg.h
 *   Generation Time: 2026-07-25 11:21:06
 *           Project: last364 - Version 1.0
 *          Delivery: CBD2200508_D00
 *      Tool Version: DaVinci Configurator Classic (beta) 5.25.37 SP2
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Classic and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

#ifndef OS_TYPES_LCFG_H
# define OS_TYPES_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* OS-Application identifiers. */
#define SystemApplication_OsCore0 SystemApplication_OsCore0

/* Trusted function identifiers. */

/* Non-trusted function identifiers. */

/* Fast trusted function identifiers. */

/* Task identifiers. */
#define Default_Appl_Init_Task Default_Appl_Init_Task
#define Default_Appl_Task Default_Appl_Task
#define Default_BSW_ASync_Task Default_BSW_ASync_Task
#define Default_Init_Task Default_Init_Task
#define Default_Init_Task_Trusted Default_Init_Task_Trusted
#define IdleTask_OsCore0 IdleTask_OsCore0
#define MotorTask MotorTask

/* Category 2 ISR identifiers. */
#define AdcIsr_G0 AdcIsr_G0
#define AdcIsr_G8 AdcIsr_G8
#define CanIsr_0 CanIsr_0
#define CounterIsr_SystemTimer CounterIsr_SystemTimer
#define DMACH4SR_ISR DMACH4SR_ISR
#define DMACH5SR_ISR DMACH5SR_ISR
#define DmaErrIsr DmaErrIsr
#define Qspi2ErrIsr Qspi2ErrIsr
#define Qspi2PtIsr Qspi2PtIsr

/* Alarm identifiers. */
#define Rte_Al_TE2_Default_BSW_ASync_Task_0_10ms Rte_Al_TE2_Default_BSW_ASync_Task_0_10ms
#define Rte_Al_TE2_Default_BSW_ASync_Task_0_20ms Rte_Al_TE2_Default_BSW_ASync_Task_0_20ms
#define Rte_Al_TE_Com_Com_MainFunctionTx_ComMainFunctionTx Rte_Al_TE_Com_Com_MainFunctionTx_ComMainFunctionTx
#define Rte_Al_TE_Default_Appl_Task_0_10ms Rte_Al_TE_Default_Appl_Task_0_10ms
#define Rte_Al_TE_Default_Appl_Task_0_1ms Rte_Al_TE_Default_Appl_Task_0_1ms
#define Rte_Al_TE_StartApp_StartApp_Cyclic1000ms Rte_Al_TE_StartApp_StartApp_Cyclic1000ms
#define Rte_Al_TE_StartApp_StartApp_Cyclic250ms Rte_Al_TE_StartApp_StartApp_Cyclic250ms

/* Counter identifiers. */
#define SystemTimer SystemTimer

/* ScheduleTable identifiers. */

/* Resource identifiers. */
#define OsResource_EcuM OsResource_EcuM

/* Spinlock identifiers. */

/* Peripheral identifiers. */

/* Barrier identifiers. */

/* Trace OS-Application identifiers (All OS-Applications inclusive system objects). */

/* Trace thread identifiers (Tasks and ISRs inclusive system objects). */

/* Trace spinlock identifiers (All spinlocks inclusive system objects). */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint32  Os_AppAccessMaskType;

/*! OS-Application identifiers. */
typedef enum
{
  SystemApplication_OsCore0 = 0, /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_APPID_COUNT = 1,
  INVALID_OSAPPLICATION = OS_APPID_COUNT
} ApplicationType;

/*! Trusted function identifiers. */
typedef enum
{
  OS_TRUSTEDFUNCTIONID_COUNT = 0
} TrustedFunctionIndexType;

/*! Non-trusted function identifiers. */
typedef enum
{
  OS_NONTRUSTEDFUNCTIONID_COUNT = 0
} Os_NonTrustedFunctionIndexType;

/*! Fast trusted function identifiers. */
typedef enum
{
  OS_FASTTRUSTEDFUNCTIONID_COUNT = 0
} Os_FastTrustedFunctionIndexType;

/*! Task identifiers. */
typedef enum
{
  Default_Appl_Init_Task = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Default_Appl_Task = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Default_BSW_ASync_Task = 2,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Default_Init_Task = 3,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Default_Init_Task_Trusted = 4,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  IdleTask_OsCore0 = 5,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  MotorTask = 6,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_TASKID_COUNT = 7,
  INVALID_TASK = OS_TASKID_COUNT
} TaskType;

/*! Category 2 ISR identifiers. */
typedef enum
{
  AdcIsr_G0 = 0,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  AdcIsr_G8 = 1,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CanIsr_0 = 2,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CounterIsr_SystemTimer = 3,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  DMACH4SR_ISR = 4,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  DMACH5SR_ISR = 5,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  DmaErrIsr = 6,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Qspi2ErrIsr = 7,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Qspi2PtIsr = 8,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_ISRID_COUNT = 9,
  INVALID_ISR = OS_ISRID_COUNT
} ISRType;

/*! Alarm identifiers. */
typedef enum
{
  Rte_Al_TE2_Default_BSW_ASync_Task_0_10ms = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_Default_BSW_ASync_Task_0_20ms = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Com_Com_MainFunctionTx_ComMainFunctionTx = 2,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Default_Appl_Task_0_10ms = 3,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Default_Appl_Task_0_1ms = 4,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_StartApp_StartApp_Cyclic1000ms = 5,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_StartApp_StartApp_Cyclic250ms = 6,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_ALARMID_COUNT = 7
} AlarmType;

/*! Counter identifiers. */
typedef enum
{
  SystemTimer = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_COUNTERID_COUNT = 1
} CounterType;

/*! ScheduleTable identifiers. */
typedef enum
{
  OS_SCHTID_COUNT = 0
} ScheduleTableType;

/*! Resource identifiers. */
typedef enum
{
  OsResource_EcuM = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_RESOURCEID_COUNT = 1
} ResourceType;

/*! Spinlock identifiers. */
typedef enum
{
  OS_SPINLOCKID_COUNT = 0,
  INVALID_SPINLOCK = OS_SPINLOCKID_COUNT
} SpinlockIdType;

/*! Peripheral identifiers. */
typedef enum
{
  OS_PERIPHERALID_COUNT = 0
} Os_PeripheralIdType;

/*! Barrier identifiers. */
typedef enum
{
  OS_BARRIERID_COUNT = 0
} Os_BarrierIdType;

/*! Trace OS-Application identifiers (All OS-Applications inclusive system objects). */
typedef enum
{
  OS_TRACE_APPID_COUNT = 0,
  OS_TRACE_INVALID_APPLICATION = OS_TRACE_APPID_COUNT + 1
} Os_TraceAppIdType;

/*! Trace thread identifiers (Tasks and ISRs inclusive system objects). */
typedef enum
{
  OS_TRACE_THREADID_COUNT = 0,
  OS_TRACE_INVALID_THREAD = OS_TRACE_THREADID_COUNT + 1
} Os_TraceThreadIdType;

/*! Trace spinlock identifiers (All spinlocks inclusive system objects). */
typedef enum
{
  OS_TRACE_NUMBER_OF_CONFIGURED_SPINLOCKS = 0,
  OS_TRACE_NUMBER_OF_ALL_SPINLOCKS = 0,
  OS_TRACE_INVALID_SPINLOCK = OS_TRACE_NUMBER_OF_ALL_SPINLOCKS + 1
} Os_TraceSpinlockIdType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_TYPES_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Types_Lcfg.h
 *********************************************************************************************************************/
