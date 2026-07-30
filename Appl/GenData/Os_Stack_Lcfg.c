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
 *              File: Os_Stack_Lcfg.c
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

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_STACK_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Stack_Cfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Stack.h"

/* Os kernel module dependencies */

/* Os hal dependencies */


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define OS_START_SEC_STACK_DEFAULT_APPL_TASK_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: Default_Appl_Task */
/* User: [Default_Appl_Task] */
OS_STACK_DECLARE(OsCfg_Stack_Default_Appl_Task_Dyn, OS_CFG_SIZE_DEFAULT_APPL_TASK_STACK);

#define OS_STOP_SEC_STACK_DEFAULT_APPL_TASK_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_STACK_DEFAULT_BSW_ASYNC_TASK_10MS_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: Default_BSW_ASync_Task_10ms */
/* User: [Default_BSW_ASync_Task_10ms] */
OS_STACK_DECLARE(OsCfg_Stack_Default_BSW_ASync_Task_10ms_Dyn, OS_CFG_SIZE_DEFAULT_BSW_ASYNC_TASK_10MS_STACK);

#define OS_STOP_SEC_STACK_DEFAULT_BSW_ASYNC_TASK_10MS_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_STACK_MOTORTASK_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: MotorTask */
/* User: [MotorTask] */
OS_STACK_DECLARE(OsCfg_Stack_MotorTask_Dyn, OS_CFG_SIZE_MOTORTASK_STACK);

#define OS_STOP_SEC_STACK_MOTORTASK_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_STACK_OSCORE0_ERROR_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core error stack: OsCore0_Error */
/* User: [ErrorHook_OsCore0, OsCore0] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Error_Dyn, OS_CFG_SIZE_OSCORE0_ERROR_STACK);

#define OS_STOP_SEC_STACK_OSCORE0_ERROR_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_STACK_OSCORE0_INIT_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core init stack: OsCore0_Init */
/* User: [OsCore0, Os_CoreInitHook_OsCore0] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Init_Dyn, OS_CFG_SIZE_OSCORE0_INIT_STACK);

#define OS_STOP_SEC_STACK_OSCORE0_INIT_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* ISR core global stack: OsCore0_Isr_Core */
/* User: [AdcIsr_G8, CanIsr_0, CounterIsr_SystemTimer] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Isr_Core_Dyn, OS_CFG_SIZE_OSCORE0_ISR_CORE_STACK);

#define OS_STOP_SEC_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_STACK_OSCORE0_KERNEL_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core kernel stack: OsCore0_Kernel */
/* User: [OsCore0] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Kernel_Dyn, OS_CFG_SIZE_OSCORE0_KERNEL_STACK);

#define OS_STOP_SEC_STACK_OSCORE0_KERNEL_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core shutdown stack: OsCore0_Shutdown */
/* User: [OsCore0, ShutdownHook_OsCore0] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Shutdown_Dyn, OS_CFG_SIZE_OSCORE0_SHUTDOWN_STACK);

#define OS_STOP_SEC_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_STACK_OSCORE0_STARTUP_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core startup stack: OsCore0_Startup */
/* User: [OsCore0, StartupHook_OsCore0] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Startup_Dyn, OS_CFG_SIZE_OSCORE0_STARTUP_STACK);

#define OS_STOP_SEC_STACK_OSCORE0_STARTUP_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio4294967295 */
/* User: [IdleTask_OsCore0] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO4294967295_STACK);

#define OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_STACK_OSCORE0_TASK_PRIO45_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio45 */
/* User: [Default_Appl_Init_Task] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio45_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO45_STACK);

#define OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO45_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_STACK_OSCORE0_TASK_PRIO49_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio49 */
/* User: [Default_Init_Task_Trusted] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio49_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO49_STACK);

#define OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO49_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio50 */
/* User: [Default_Init_Task] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio50_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO50_STACK);

#define OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_STACK_OSCORE1_ERROR_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core error stack: OsCore1_Error */
/* User: [ErrorHook_OsCore1, OsCore1] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore1_Error_Dyn, OS_CFG_SIZE_OSCORE1_ERROR_STACK);

#define OS_STOP_SEC_STACK_OSCORE1_ERROR_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_STACK_OSCORE1_INIT_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core init stack: OsCore1_Init */
/* User: [OsCore1, Os_CoreInitHook_OsCore1] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore1_Init_Dyn, OS_CFG_SIZE_OSCORE1_INIT_STACK);

#define OS_STOP_SEC_STACK_OSCORE1_INIT_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_STACK_OSCORE1_ISR_CORE_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* ISR core global stack: OsCore1_Isr_Core */
/* User: [CounterIsr_SystemTimer1] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore1_Isr_Core_Dyn, OS_CFG_SIZE_OSCORE1_ISR_CORE_STACK);

#define OS_STOP_SEC_STACK_OSCORE1_ISR_CORE_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_STACK_OSCORE1_KERNEL_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core kernel stack: OsCore1_Kernel */
/* User: [OsCore1] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore1_Kernel_Dyn, OS_CFG_SIZE_OSCORE1_KERNEL_STACK);

#define OS_STOP_SEC_STACK_OSCORE1_KERNEL_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_STACK_OSCORE1_SHUTDOWN_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core shutdown stack: OsCore1_Shutdown */
/* User: [OsCore1, ShutdownHook_OsCore1] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore1_Shutdown_Dyn, OS_CFG_SIZE_OSCORE1_SHUTDOWN_STACK);

#define OS_STOP_SEC_STACK_OSCORE1_SHUTDOWN_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_STACK_OSCORE1_STARTUP_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core startup stack: OsCore1_Startup */
/* User: [OsCore1, StartupHook_OsCore1] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore1_Startup_Dyn, OS_CFG_SIZE_OSCORE1_STARTUP_STACK);

#define OS_STOP_SEC_STACK_OSCORE1_STARTUP_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_STACK_OSCORE1_TASK_PRIO0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore1_Task_Prio0 */
/* User: [Default_MotorInitTask] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore1_Task_Prio0_Dyn, OS_CFG_SIZE_OSCORE1_TASK_PRIO0_STACK);

#define OS_STOP_SEC_STACK_OSCORE1_TASK_PRIO0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_STACK_OSCORE1_TASK_PRIO20_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore1_Task_Prio20 */
/* User: [BswCore1Task] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore1_Task_Prio20_Dyn, OS_CFG_SIZE_OSCORE1_TASK_PRIO20_STACK);

#define OS_STOP_SEC_STACK_OSCORE1_TASK_PRIO20_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_STACK_OSCORE1_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore1_Task_Prio4294967295 */
/* User: [IdleTask_OsCore_1] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore1_Task_Prio4294967295_Dyn, OS_CFG_SIZE_OSCORE1_TASK_PRIO4294967295_STACK);

#define OS_STOP_SEC_STACK_OSCORE1_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_STACK_OSCORE1_TASK_PRIO49_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore1_Task_Prio49 */
/* User: [Default_Init_Task_Core1_Trusted] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore1_Task_Prio49_Dyn, OS_CFG_SIZE_OSCORE1_TASK_PRIO49_STACK);

#define OS_STOP_SEC_STACK_OSCORE1_TASK_PRIO49_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_STACK_OSCORE1_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore1_Task_Prio50 */
/* User: [Default_Init_Task_Core1] */
OS_STACK_DECLARE(OsCfg_Stack_OsCore1_Task_Prio50_Dyn, OS_CFG_SIZE_OSCORE1_TASK_PRIO50_STACK);

#define OS_STOP_SEC_STACK_OSCORE1_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Stack configuration data: Default_Appl_Task */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_Default_Appl_Task =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_Default_Appl_Task_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_Default_Appl_Task_Dyn)
};

/*! Stack configuration data: Default_BSW_ASync_Task_10ms */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_Default_BSW_ASync_Task_10ms =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_Default_BSW_ASync_Task_10ms_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_Default_BSW_ASync_Task_10ms_Dyn)
};

/*! Stack configuration data: OsCore0_Error */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Error =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Error_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Error_Dyn)
};

/*! Stack configuration data: OsCore0_Init */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Init =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Init_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Init_Dyn)
};

/*! Stack configuration data: OsCore0_Isr_Core */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Isr_Core =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)
};

/*! Stack configuration data: OsCore0_Kernel */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Kernel =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Kernel_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Kernel_Dyn)
};

/*! Stack configuration data: OsCore0_Shutdown */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Shutdown =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Shutdown_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Shutdown_Dyn)
};

/*! Stack configuration data: OsCore0_Startup */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Startup =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Startup_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Startup_Dyn)
};

/*! Stack configuration data: OsCore0_Task_Prio4294967295 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio4294967295 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn)
};

/*! Stack configuration data: OsCore0_Task_Prio45 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio45 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio45_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio45_Dyn)
};

/*! Stack configuration data: OsCore0_Task_Prio49 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio49 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio49_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio49_Dyn)
};

/*! Stack configuration data: OsCore0_Task_Prio50 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio50 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio50_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio50_Dyn)
};


#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Stack configuration data: MotorTask */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_MotorTask =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_MotorTask_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_MotorTask_Dyn)
};

/*! Stack configuration data: OsCore1_Error */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore1_Error =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore1_Error_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore1_Error_Dyn)
};

/*! Stack configuration data: OsCore1_Init */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore1_Init =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore1_Init_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore1_Init_Dyn)
};

/*! Stack configuration data: OsCore1_Isr_Core */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore1_Isr_Core =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore1_Isr_Core_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore1_Isr_Core_Dyn)
};

/*! Stack configuration data: OsCore1_Kernel */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore1_Kernel =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore1_Kernel_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore1_Kernel_Dyn)
};

/*! Stack configuration data: OsCore1_Shutdown */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore1_Shutdown =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore1_Shutdown_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore1_Shutdown_Dyn)
};

/*! Stack configuration data: OsCore1_Startup */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore1_Startup =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore1_Startup_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore1_Startup_Dyn)
};

/*! Stack configuration data: OsCore1_Task_Prio0 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore1_Task_Prio0 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore1_Task_Prio0_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore1_Task_Prio0_Dyn)
};

/*! Stack configuration data: OsCore1_Task_Prio20 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore1_Task_Prio20 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore1_Task_Prio20_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore1_Task_Prio20_Dyn)
};

/*! Stack configuration data: OsCore1_Task_Prio4294967295 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore1_Task_Prio4294967295 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore1_Task_Prio4294967295_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore1_Task_Prio4294967295_Dyn)
};

/*! Stack configuration data: OsCore1_Task_Prio49 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore1_Task_Prio49 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore1_Task_Prio49_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore1_Task_Prio49_Dyn)
};

/*! Stack configuration data: OsCore1_Task_Prio50 */
CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore1_Task_Prio50 =
{
  /* .LowAddress  = */ OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore1_Task_Prio50_Dyn),
  /* .HighAddress = */ OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore1_Task_Prio50_Dyn)
};


#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Os_Stack_Lcfg.c
 *********************************************************************************************************************/
