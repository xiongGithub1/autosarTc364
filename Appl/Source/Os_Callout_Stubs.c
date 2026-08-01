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
 *              File: Os_Callout_Stubs.c
 *   Generation Time: 2026-07-31 17:05:25
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

#define OS_CALLOUT_STUBS_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Os.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_Include>
 *********************************************************************************************************************/
#include "Os_CoreInt.h"
#include "Os_Core_Lcfg.h"
#include "EcuM.h"

volatile StatusType Os_Callout_LastError = E_OK;
volatile OSServiceIdType Os_Callout_LastErrorService = OSServiceId_GetApplicationID;
volatile Os_StatusType Os_Callout_LastErrorStatus = OS_STATUS_OK;
volatile uint32 Os_Callout_LastDetailedError = 0U;
volatile Os_InterruptSourceIdType Os_Callout_UnhandledIrq = 0U;
volatile Os_ExceptionSourceIdType Os_Callout_UnhandledExc = 0U;
volatile Os_InterruptSourceIdType Os_Callout_UnhandledIrq_Core1 = 0U;
volatile Os_ExceptionSourceIdType Os_Callout_UnhandledExc_Core1 = 0U;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  StartupHook()
 *********************************************************************************************************************/
#if OS_CFG_STARTUPHOOK_SYSTEM == STD_ON
# define OS_START_SEC_STARTUPHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, OS_STARTUPHOOK_CODE) StartupHook(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_StartupHook>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_STARTUPHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* OS_CFG_STARTUPHOOK_SYSTEM */


/**********************************************************************************************************************
 *  ShutdownHook()
 *********************************************************************************************************************/
#if OS_CFG_SHUTDOWNHOOK_SYSTEM == STD_ON
# define OS_START_SEC_SHUTDOWNHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, OS_SHUTDOWNHOOK_CODE) ShutdownHook(StatusType Fatalerror)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_ShutdownHook>
 *********************************************************************************************************************/
  EcuM_Shutdown();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_SHUTDOWNHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* OS_CFG_SHUTDOWNHOOK_SYSTEM */


/**********************************************************************************************************************
 *  ErrorHook()
 *********************************************************************************************************************/
#if OS_CFG_ERRORHOOK_SYSTEM == STD_ON
# define OS_START_SEC_ERRORHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, OS_ERRORHOOK_CODE) ErrorHook(StatusType Error)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_ErrorHook>
 *********************************************************************************************************************/
  Os_ErrorInformationType CurrentError;
  volatile uint8 endless = 1u;

  Os_Callout_LastError = Error;
  if (Os_GetDetailedError(&CurrentError) == E_OK)
  {
    Os_Callout_LastErrorService = CurrentError.Service;
    Os_Callout_LastError = CurrentError.Error;
    Os_Callout_LastErrorStatus = CurrentError.DetailedError;
    Os_Callout_LastDetailedError = (uint32)CurrentError.DetailedError;
  }

  while (endless != 0u)
  {
    /* breakpoint here for OS API / status errors (NOT KernelPanic) */
  }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_ERRORHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* OS_CFG_ERRORHOOK_SYSTEM */


/**********************************************************************************************************************
 *  ProtectionHook()
 *********************************************************************************************************************/
#if OS_CFG_PROTECTIONHOOK_SYSTEM == STD_ON
# define OS_START_SEC_PROTECTIONHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(ProtectionReturnType, OS_PROTECTIONHOOK_CODE) ProtectionHook(StatusType Fatalerror)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_ProtectionHook>
 *********************************************************************************************************************/
  return PRO_SHUTDOWN;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_PROTECTIONHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* OS_CFG_PROTECTIONHOOK_SYSTEM */


/**********************************************************************************************************************
 *  PreTaskHook()
 *********************************************************************************************************************/
#if OS_CFG_PRETASKHOOK == STD_ON
# define OS_START_SEC_PRETASKHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, OS_PRETASKHOOK_CODE) PreTaskHook(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_PreTaskHook>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_PRETASKHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* OS_CFG_PRETASKHOOK */


/**********************************************************************************************************************
 *  PostTaskHook()
 *********************************************************************************************************************/
#if OS_CFG_POSTTASKHOOK == STD_ON
# define OS_START_SEC_POSTTASKHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, OS_POSTTASKHOOK_CODE) PostTaskHook(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_PostTaskHook>
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_POSTTASKHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* OS_CFG_POSTTASKHOOK */


/**********************************************************************************************************************
 *  Os_PanicHook()
 *********************************************************************************************************************/
#if OS_CFG_PANICHOOK == STD_ON
# define OS_START_SEC_PANICHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, OS_PANICHOOK_CODE) Os_PanicHook(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK OS_Callout_Stubs_PanicHook>
 *********************************************************************************************************************/
  /* Do not call Os_GetUnhandledIrq/Os_GetUnhandledExc here: OS is already inconsistent and those APIs
     may trigger a second KernelPanic via Os_ErrApplicationError. Read core-local data directly instead. */
  Os_Callout_UnhandledIrq = OsCfg_Core_OsCore0_Dyn.LastUnhandledIrq;
  Os_Callout_UnhandledExc = OsCfg_Core_OsCore0_Dyn.LastUnhandledExc;
  Os_Callout_UnhandledIrq_Core1 = OsCfg_Core_OsCore1_Dyn.LastUnhandledIrq;
  Os_Callout_UnhandledExc_Core1 = OsCfg_Core_OsCore1_Dyn.LastUnhandledExc;
  while (1U)
  {
    /* breakpoint here: inspect Os_Callout_UnhandledExc / Os_Callout_UnhandledIrq and DEAD register */
  }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>
 *********************************************************************************************************************/

}

# define OS_STOP_SEC_PANICHOOK_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* OS_CFG_PANICHOOK */



/* Unrecognized User Blocks */
#if 0
#endif


/**********************************************************************************************************************
 *  END OF FILE: Os_Callout_Stubs.c
 *********************************************************************************************************************/
