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
 *              File: Os_XSignal_Cfg.h
 *   Generation Time: 2026-07-31 14:18:08
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

#ifndef OS_XSIGNAL_CFG_H
# define OS_XSIGNAL_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether the X-Signal module is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_XSIGNAL                          (STD_ON)

/*! Defines whether cross core calls shall be performed asynchronous (STD_ON) or not (STD_OFF). */
# define OS_CFG_XSIG_USEASYNC                    (STD_OFF)

/* X-Signal defines for core: OsCore0 */
# define OS_CFG_NUM_XSIG_OSCORE0_ISRS     (1u)
# define OS_CFG_SIZE_OSCORE0_SEND0_XSIGNALISR_OSCORE1_RECV0_BUFFER     (2u)
# define OS_CFG_NUM_ISR_XSIGNALISR_OSCORE0_PORTS     (1u)

/* X-Signal defines for core: OsCore1 */
# define OS_CFG_NUM_XSIG_OSCORE1_ISRS     (1u)
# define OS_CFG_SIZE_OSCORE1_SEND0_XSIGNALISR_OSCORE0_RECV0_BUFFER     (2u)
# define OS_CFG_NUM_ISR_XSIGNALISR_OSCORE1_PORTS     (1u)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_XSIGNAL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_XSignal_Cfg.h
 *********************************************************************************************************************/
