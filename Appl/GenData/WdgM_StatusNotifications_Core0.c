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
 *            Module: WdgM
 *           Program: MSR_Vector_SLP4
 *          Customer: China Lithium Battery Technology Co., Ltd.
 *       Expiry Date: 2025-08-26
 *  Ordered Derivat.: SAK-TC387QP-160F300S AE
 *    License Scope : The usage is restricted to CBD2200508_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: WdgM_StatusNotifications_Core0.c
 *   Generation Time: 2026-08-31 14:50:03
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

#define WDGM_STATUS_NOTIFICATIONS_CORE_0_C

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Rte_WdgM_SystemApplication_OsCore0.h" 

#define WDGM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  WdgM_GlobalStatusChangeNotificationCore0
 **********************************************************************************************************************/
/*! \brief      This intern notification function is called by main function of the WdgM if the global status of core 0
 *              changes.
 **********************************************************************************************************************/
FUNC(void, WDGM_CODE) WdgM_GlobalStatusChangeNotificationCore0(WdgMMode status)
{
  (void) Rte_Switch_globalmode_Core0_currentMode(status);
}

/**********************************************************************************************************************
 *  WdgM_LocalStatusChangeNotificationSE0
 **********************************************************************************************************************/
/*! \brief      This intern notification function is called by main function of the WdgM if the local status of
 *              WdgMSupervisedEntity changes.
 **********************************************************************************************************************/
FUNC(void, WDGM_CODE) WdgM_LocalStatusChangeNotificationSE0(WdgMMode status)
{
  (void) Rte_Switch_mode_WdgMSupervisedEntity_currentMode(status);
}

#define WDGM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: WdgM_StatusNotifications_Core0.h
 *********************************************************************************************************************/

