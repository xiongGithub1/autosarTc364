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
 *   Generation Time: 2026-07-30 20:09:43
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
#define OsApplication_OsCore1 OsApplication_OsCore1
#define SystemApplication_OsCore0 SystemApplication_OsCore0

/* Trusted function identifiers. */

/* Non-trusted function identifiers. */

/* Fast trusted function identifiers. */

/* Task identifiers. */
#define BswCore1Task BswCore1Task
#define Default_Appl_Init_Task Default_Appl_Init_Task
#define Default_Appl_Task Default_Appl_Task
#define Default_BSW_ASync_Task_10ms Default_BSW_ASync_Task_10ms
#define Default_Init_Task Default_Init_Task
#define Default_Init_Task_Core1 Default_Init_Task_Core1
#define Default_Init_Task_Core1_Trusted Default_Init_Task_Core1_Trusted
#define Default_Init_Task_Trusted Default_Init_Task_Trusted
#define Default_MotorInitTask Default_MotorInitTask
#define IdleTask_OsCore0 IdleTask_OsCore0
#define IdleTask_OsCore_1 IdleTask_OsCore_1
#define MotorTask MotorTask

/* Category 2 ISR identifiers. */
#define AdcIsr_G8 AdcIsr_G8
#define CanIsr_0 CanIsr_0
#define CounterIsr_SystemTimer CounterIsr_SystemTimer
#define CounterIsr_SystemTimer1 CounterIsr_SystemTimer1

/* Alarm identifiers. */
#define Rte_Al_TE2_Default_BSW_ASync_Task_10ms_0_10ms Rte_Al_TE2_Default_BSW_ASync_Task_10ms_0_10ms
#define Rte_Al_TE2_Default_BSW_ASync_Task_10ms_0_20ms Rte_Al_TE2_Default_BSW_ASync_Task_10ms_0_20ms
#define Rte_Al_TE2_EcuM_EcuM_MainFunction Rte_Al_TE2_EcuM_EcuM_MainFunction
#define Rte_Al_TE_Com_Com_MainFunctionTx_ComMainFunctionTx Rte_Al_TE_Com_Com_MainFunctionTx_ComMainFunctionTx
#define Rte_Al_TE_MotorTask_0_1ms Rte_Al_TE_MotorTask_0_1ms
#define Rte_Al_TE_StartApp_StartApp_Cyclic1000ms Rte_Al_TE_StartApp_StartApp_Cyclic1000ms
#define Rte_Al_TE_StartApp_StartApp_Cyclic10ms Rte_Al_TE_StartApp_StartApp_Cyclic10ms
#define Rte_Al_TE_StartApp_StartApp_Cyclic1ms Rte_Al_TE_StartApp_StartApp_Cyclic1ms
#define Rte_Al_TE_StartApp_StartApp_Cyclic250ms Rte_Al_TE_StartApp_StartApp_Cyclic250ms

/* Counter identifiers. */
#define SystemTimer SystemTimer
#define SystemTimer1 SystemTimer1

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
  OsApplication_OsCore1 = 0, /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SystemApplication_OsCore0 = 1, /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_APPID_COUNT = 2,
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
  BswCore1Task = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Default_Appl_Init_Task = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Default_Appl_Task = 2,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Default_BSW_ASync_Task_10ms = 3,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Default_Init_Task = 4,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Default_Init_Task_Core1 = 5,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Default_Init_Task_Core1_Trusted = 6,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Default_Init_Task_Trusted = 7,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Default_MotorInitTask = 8,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  IdleTask_OsCore0 = 9,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  IdleTask_OsCore_1 = 10,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  MotorTask = 11,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_TASKID_COUNT = 12,
  INVALID_TASK = OS_TASKID_COUNT
} TaskType;

/*! Category 2 ISR identifiers. */
typedef enum
{
  AdcIsr_G8 = 0,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CanIsr_0 = 1,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CounterIsr_SystemTimer = 2,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CounterIsr_SystemTimer1 = 3,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_ISRID_COUNT = 4,
  INVALID_ISR = OS_ISRID_COUNT
} ISRType;

/*! Alarm identifiers. */
typedef enum
{
  Rte_Al_TE2_Default_BSW_ASync_Task_10ms_0_10ms = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_Default_BSW_ASync_Task_10ms_0_20ms = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_EcuM_EcuM_MainFunction = 2,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_Com_Com_MainFunctionTx_ComMainFunctionTx = 3,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_MotorTask_0_1ms = 4,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_StartApp_StartApp_Cyclic1000ms = 5,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_StartApp_StartApp_Cyclic10ms = 6,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_StartApp_StartApp_Cyclic1ms = 7,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_StartApp_StartApp_Cyclic250ms = 8,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_ALARMID_COUNT = 9
} AlarmType;

/*! Counter identifiers. */
typedef enum
{
  SystemTimer = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SystemTimer1 = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_COUNTERID_COUNT = 2
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
