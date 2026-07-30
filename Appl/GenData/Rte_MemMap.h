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
 *            Module: MemMap
 *           Program: MSR_Vector_SLP4
 *          Customer: China Lithium Battery Technology Co., Ltd.
 *       Expiry Date: 2025-08-26
 *  Ordered Derivat.: SAK-TC387QP-160F300S AE
 *    License Scope : The usage is restricted to CBD2200508_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Rte_MemMap.h
 *   Generation Time: 2026-07-30 20:42:32
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

#ifndef MICROSAR_DISABLE_MEMMAP

/**********************************************************************************************************************
 *  PRE USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

/**********************************************************************************************************************
 *  MEMMAP SECTIONS
 *********************************************************************************************************************/

#define MEMMAP_ERROR

#if defined RTE_START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_CODE_OPEN
#  error Using RTE_STOP_SEC_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_NOINIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_NOINIT/OS_SystemApplication_OsCore0_VAR_NOINIT */
# pragma section farnoclear "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_NOINIT/OS_SystemApplication_OsCore0_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_ZERO_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_ZERO_INIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_ZERO_INIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_ZERO_INIT_8BIT_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_ZERO_INIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_ZERO_INIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_ZERO_INIT_8BIT_OPEN
#  error Using RTE_STOP_SEC_VAR_ZERO_INIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_INIT_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_CONST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_CONST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_CONST_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section farrom "MSR_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_CONST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_CONST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_CONST_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_CONST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_BSWM_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_BSWM_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_BSWM_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_BSWM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_BSWM_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_BSWM_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_BSWM_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_BSWM_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_BSWM_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_BSWM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_DET_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_DET_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_DET_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_DET_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_DET_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_DET_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_DET_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_DET_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_DET_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_DET_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_ECUM_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_ECUM_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_ECUM_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_ECUM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_ECUM_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_ECUM_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_ECUM_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_ECUM_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_ECUM_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_ECUM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_OS_OSCORE0_SWC_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_OS_OSCORE0_SWC_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_OS_OSCORE0_SWC_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_OS_OSCORE0_SWC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_OS_OSCORE0_SWC_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_OS_OSCORE0_SWC_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_OS_OSCORE0_SWC_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_OS_OSCORE0_SWC_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_OS_OSCORE0_SWC_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_OS_OSCORE0_SWC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_STARTAPP_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_STARTAPP_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_STARTAPP_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_STARTAPP_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_STARTAPP_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_STARTAPP_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_STARTAPP_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_STARTAPP_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_STARTAPP_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_STARTAPP_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_DEFAULT_APPL_INIT_TASK_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_DEFAULT_APPL_INIT_TASK_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_DEFAULT_APPL_INIT_TASK_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_DEFAULT_APPL_INIT_TASK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_DEFAULT_APPL_INIT_TASK_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_DEFAULT_APPL_INIT_TASK_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_DEFAULT_APPL_INIT_TASK_CODE_OPEN
#  error Using RTE_STOP_SEC_DEFAULT_APPL_INIT_TASK_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_DEFAULT_APPL_INIT_TASK_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_DEFAULT_APPL_INIT_TASK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_DEFAULT_APPL_TASK_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_DEFAULT_APPL_TASK_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_DEFAULT_APPL_TASK_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_DEFAULT_APPL_TASK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_DEFAULT_APPL_TASK_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_DEFAULT_APPL_TASK_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_DEFAULT_APPL_TASK_CODE_OPEN
#  error Using RTE_STOP_SEC_DEFAULT_APPL_TASK_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_DEFAULT_APPL_TASK_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_DEFAULT_APPL_TASK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_DEFAULT_INIT_TASK_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_DEFAULT_INIT_TASK_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_DEFAULT_INIT_TASK_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_DEFAULT_INIT_TASK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_DEFAULT_INIT_TASK_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_DEFAULT_INIT_TASK_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_DEFAULT_INIT_TASK_CODE_OPEN
#  error Using RTE_STOP_SEC_DEFAULT_INIT_TASK_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_DEFAULT_INIT_TASK_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_DEFAULT_INIT_TASK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_DEFAULT_INIT_TASK_TRUSTED_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_DEFAULT_INIT_TASK_TRUSTED_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_DEFAULT_INIT_TASK_TRUSTED_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_DEFAULT_INIT_TASK_TRUSTED_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_DEFAULT_INIT_TASK_TRUSTED_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_DEFAULT_INIT_TASK_TRUSTED_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_DEFAULT_INIT_TASK_TRUSTED_CODE_OPEN
#  error Using RTE_STOP_SEC_DEFAULT_INIT_TASK_TRUSTED_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_DEFAULT_INIT_TASK_TRUSTED_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_DEFAULT_INIT_TASK_TRUSTED_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_IDLETASK_OSCORE0_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_IDLETASK_OSCORE0_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_IDLETASK_OSCORE0_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_IDLETASK_OSCORE0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_IDLETASK_OSCORE0_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_IDLETASK_OSCORE0_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_IDLETASK_OSCORE0_CODE_OPEN
#  error Using RTE_STOP_SEC_IDLETASK_OSCORE0_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_IDLETASK_OSCORE0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_IDLETASK_OSCORE0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_COMM_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_COMM_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_COMM_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_COMM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_COMM_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_COMM_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_COMM_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_COMM_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_COMM_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_COMM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_MOTORCONTROLL_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_MOTORCONTROLL_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_MOTORCONTROLL_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_MOTORCONTROLL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_MOTORCONTROLL_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_MOTORCONTROLL_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_MOTORCONTROLL_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_MOTORCONTROLL_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_MOTORCONTROLL_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_MOTORCONTROLL_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_MOTORCDD_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_MOTORCDD_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_MOTORCDD_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_MOTORCDD_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_MOTORCDD_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_MOTORCDD_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_MOTORCDD_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_MOTORCDD_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_MOTORCDD_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_MOTORCDD_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_NVM_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_NVM_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_NVM_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_NVM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_NVM_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_NVM_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_NVM_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_NVM_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_NVM_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_NVM_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_DEFAULT_BSW_ASYNC_TASK_10MS_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_DEFAULT_BSW_ASYNC_TASK_10MS_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_DEFAULT_BSW_ASYNC_TASK_10MS_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_DEFAULT_BSW_ASYNC_TASK_10MS_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_DEFAULT_BSW_ASYNC_TASK_10MS_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_DEFAULT_BSW_ASYNC_TASK_10MS_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_DEFAULT_BSW_ASYNC_TASK_10MS_CODE_OPEN
#  error Using RTE_STOP_SEC_DEFAULT_BSW_ASYNC_TASK_10MS_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_DEFAULT_BSW_ASYNC_TASK_10MS_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_DEFAULT_BSW_ASYNC_TASK_10MS_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_NOINIT/OS_SystemApplication_OsCore0_VAR_NOINIT */
# pragma section farnoclear "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_NOINIT/OS_SystemApplication_OsCore0_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Using RTE_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_GLOBALSHARED_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_GLOBALSHARED_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_START_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Using RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_GLOBALSHARED_VAR_INIT/OS_GLOBALSHARED_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_NOCACHE_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_NOCACHE_INIT_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_NOCACHE_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_OS_OSCORE1_SWC_APPL_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_OS_OSCORE1_SWC_APPL_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_OS_OSCORE1_SWC_APPL_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_OS_OSCORE1_SWC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_OS_OSCORE1_SWC_APPL_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_OS_OSCORE1_SWC_APPL_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_OS_OSCORE1_SWC_APPL_CODE_OPEN
#  error Using RTE_STOP_SEC_OS_OSCORE1_SWC_APPL_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_OS_OSCORE1_SWC_APPL_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_OS_OSCORE1_SWC_APPL_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_IDLETASK_OSCORE_1_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_IDLETASK_OSCORE_1_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_IDLETASK_OSCORE_1_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_IDLETASK_OSCORE_1_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_IDLETASK_OSCORE_1_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_IDLETASK_OSCORE_1_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_IDLETASK_OSCORE_1_CODE_OPEN
#  error Using RTE_STOP_SEC_IDLETASK_OSCORE_1_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_IDLETASK_OSCORE_1_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_IDLETASK_OSCORE_1_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_OSAPPLICATION_OSCORE1_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_OSAPPLICATION_OSCORE1_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_OSAPPLICATION_OSCORE1_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_OSAPPLICATION_OSCORE1_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_OSAPPLICATION_OSCORE1_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_OSAPPLICATION_OSCORE1_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_OSAPPLICATION_OSCORE1_CODE_OPEN
#  error Using RTE_STOP_SEC_OSAPPLICATION_OSCORE1_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_OSAPPLICATION_OSCORE1_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_OSAPPLICATION_OSCORE1_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_OsCore1_VAR_NOINIT/OS_OsApplication_OsCore1_VAR_NOINIT */
# pragma section farnoclear "OS_CORE1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_START_SEC_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_OsCore1_VAR_NOINIT/OS_OsApplication_OsCore1_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_OsApplication_OsCore1_NOCACHE_NOINIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_OsApplication_OsCore1_NOCACHE_NOINIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_OsApplication_OsCore1_NOCACHE_NOINIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_OsCore1_VAR_NOINIT/OS_OsApplication_OsCore1_VAR_NOINIT */
# pragma section farnoclear "OS_CORE1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_START_SEC_VAR_OsApplication_OsCore1_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOCACHE_NOINIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOCACHE_NOINIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_OsApplication_OsCore1_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOCACHE_NOINIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_OsApplication_OsCore1_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_OsCore1_VAR_NOINIT/OS_OsApplication_OsCore1_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_OsApplication_OsCore1_ZERO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_OsApplication_OsCore1_ZERO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_OsApplication_OsCore1_ZERO_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_OsCore1_VAR_INIT/OS_OsApplication_OsCore1_VAR_INIT */
# pragma section farnoclear "OS_CORE1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_START_SEC_VAR_OsApplication_OsCore1_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_OsApplication_OsCore1_ZERO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_OsApplication_OsCore1_ZERO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_OsApplication_OsCore1_ZERO_INIT_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_VAR_OsApplication_OsCore1_ZERO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_OsApplication_OsCore1_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_OsCore1_VAR_INIT/OS_OsApplication_OsCore1_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_STOP_SEC_VAR_OsApplication_OsCore1_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_OsCore1_VAR_INIT/OS_OsApplication_OsCore1_VAR_INIT */
# pragma section farnoclear "OS_CORE1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_START_SEC_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_OsCore1_VAR_INIT/OS_OsApplication_OsCore1_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_8BIT_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_OsCore1_VAR_INIT/OS_OsApplication_OsCore1_VAR_INIT */
# pragma section farnoclear "OS_CORE1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_START_SEC_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Using RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_OsCore1_VAR_INIT/OS_OsApplication_OsCore1_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_OsCore1_VAR_INIT/OS_OsApplication_OsCore1_VAR_INIT */
# pragma section farnoclear "OS_CORE1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_START_SEC_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_OsCore1_VAR_INIT/OS_OsApplication_OsCore1_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_STOP_SEC_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_OsApplication_OsCore1_NOCACHE_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_OsApplication_OsCore1_NOCACHE_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_OsApplication_OsCore1_NOCACHE_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_OsCore1_VAR_INIT/OS_OsApplication_OsCore1_VAR_INIT */
# pragma section farnoclear "OS_CORE1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_START_SEC_VAR_OsApplication_OsCore1_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOCACHE_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOCACHE_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_OsApplication_OsCore1_NOCACHE_INIT_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOCACHE_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_OsApplication_OsCore1_NOCACHE_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_OsCore1_VAR_INIT/OS_OsApplication_OsCore1_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_SYSTEMAPPLICATION_OSCORE0_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_SYSTEMAPPLICATION_OSCORE0_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_SYSTEMAPPLICATION_OSCORE0_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_SYSTEMAPPLICATION_OSCORE0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_SYSTEMAPPLICATION_OSCORE0_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_SYSTEMAPPLICATION_OSCORE0_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_SYSTEMAPPLICATION_OSCORE0_CODE_OPEN
#  error Using RTE_STOP_SEC_SYSTEMAPPLICATION_OSCORE0_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_SYSTEMAPPLICATION_OSCORE0_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_SYSTEMAPPLICATION_OSCORE0_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_NOINIT/OS_SystemApplication_OsCore0_VAR_NOINIT */
# pragma section farnoclear "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_START_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_NOINIT/OS_SystemApplication_OsCore0_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_NOINIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_NOINIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_SystemApplication_OsCore0_NOCACHE_NOINIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_NOINIT/OS_SystemApplication_OsCore0_VAR_NOINIT */
# pragma section farnoclear "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_NOINIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_NOINIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_SystemApplication_OsCore0_NOCACHE_NOINIT_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_NOINIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_SystemApplication_OsCore0_NOCACHE_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_NOINIT/OS_SystemApplication_OsCore0_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_SystemApplication_OsCore0_ZERO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_SystemApplication_OsCore0_ZERO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_SystemApplication_OsCore0_ZERO_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_START_SEC_VAR_SystemApplication_OsCore0_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_SystemApplication_OsCore0_ZERO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_SystemApplication_OsCore0_ZERO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_SystemApplication_OsCore0_ZERO_INIT_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_VAR_SystemApplication_OsCore0_ZERO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_SystemApplication_OsCore0_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore0_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_8BIT_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Using RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_START_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_VAR_SystemApplication_OsCore0_NOCACHE_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_VAR_SystemApplication_OsCore0_NOCACHE_INIT_UNSPECIFIED_OPEN
#  error Using RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_VAR_SystemApplication_OsCore0_NOCACHE_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_DEFAULT_MOTORINITTASK_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_DEFAULT_MOTORINITTASK_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_DEFAULT_MOTORINITTASK_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_DEFAULT_MOTORINITTASK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_DEFAULT_MOTORINITTASK_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_DEFAULT_MOTORINITTASK_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_DEFAULT_MOTORINITTASK_CODE_OPEN
#  error Using RTE_STOP_SEC_DEFAULT_MOTORINITTASK_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_DEFAULT_MOTORINITTASK_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_DEFAULT_MOTORINITTASK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_MOTORTASK_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_MOTORTASK_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_MOTORTASK_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_MOTORTASK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_MOTORTASK_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_MOTORTASK_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_MOTORTASK_CODE_OPEN
#  error Using RTE_STOP_SEC_MOTORTASK_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_MOTORTASK_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_MOTORTASK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_DEFAULT_INIT_TASK_CORE1_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_DEFAULT_INIT_TASK_CORE1_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_DEFAULT_INIT_TASK_CORE1_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_DEFAULT_INIT_TASK_CORE1_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_DEFAULT_INIT_TASK_CORE1_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_DEFAULT_INIT_TASK_CORE1_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_DEFAULT_INIT_TASK_CORE1_CODE_OPEN
#  error Using RTE_STOP_SEC_DEFAULT_INIT_TASK_CORE1_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_DEFAULT_INIT_TASK_CORE1_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_DEFAULT_INIT_TASK_CORE1_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_DEFAULT_INIT_TASK_CORE1_TRUSTED_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_DEFAULT_INIT_TASK_CORE1_TRUSTED_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_DEFAULT_INIT_TASK_CORE1_TRUSTED_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_DEFAULT_INIT_TASK_CORE1_TRUSTED_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_DEFAULT_INIT_TASK_CORE1_TRUSTED_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_DEFAULT_INIT_TASK_CORE1_TRUSTED_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_DEFAULT_INIT_TASK_CORE1_TRUSTED_CODE_OPEN
#  error Using RTE_STOP_SEC_DEFAULT_INIT_TASK_CORE1_TRUSTED_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_DEFAULT_INIT_TASK_CORE1_TRUSTED_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_DEFAULT_INIT_TASK_CORE1_TRUSTED_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined RTE_START_SEC_BSWCORE1TASK_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using RTE_START_SEC_BSWCORE1TASK_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define RTE_BSWCORE1TASK_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_START_SEC_BSWCORE1TASK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined RTE_STOP_SEC_BSWCORE1TASK_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using RTE_STOP_SEC_BSWCORE1TASK_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef RTE_BSWCORE1TASK_CODE_OPEN
#  error Using RTE_STOP_SEC_BSWCORE1TASK_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef RTE_BSWCORE1TASK_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef RTE_STOP_SEC_BSWCORE1TASK_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

/* -------------------------------------------------------------------------------- */


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/

#ifdef RTE_START_SEC_CODE
# error Using RTE_START_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_CODE
# error Using RTE_STOP_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
# error Using RTE_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# error Using RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# error Using RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# error Using RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_ZERO_INIT_8BIT
# error Using RTE_START_SEC_VAR_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_ZERO_INIT_8BIT
# error Using RTE_STOP_SEC_VAR_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_INIT_UNSPECIFIED
# error Using RTE_START_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
# error Using RTE_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_CONST_UNSPECIFIED
# error Using RTE_START_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_CONST_UNSPECIFIED
# error Using RTE_STOP_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_APPL_CODE
# error Using RTE_START_SEC_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_APPL_CODE
# error Using RTE_STOP_SEC_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_BSWM_APPL_CODE
# error Using RTE_START_SEC_BSWM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_BSWM_APPL_CODE
# error Using RTE_STOP_SEC_BSWM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_DET_APPL_CODE
# error Using RTE_START_SEC_DET_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_DET_APPL_CODE
# error Using RTE_STOP_SEC_DET_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_ECUM_APPL_CODE
# error Using RTE_START_SEC_ECUM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_ECUM_APPL_CODE
# error Using RTE_STOP_SEC_ECUM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_OS_OSCORE0_SWC_APPL_CODE
# error Using RTE_START_SEC_OS_OSCORE0_SWC_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_OS_OSCORE0_SWC_APPL_CODE
# error Using RTE_STOP_SEC_OS_OSCORE0_SWC_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_STARTAPP_APPL_CODE
# error Using RTE_START_SEC_STARTAPP_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_STARTAPP_APPL_CODE
# error Using RTE_STOP_SEC_STARTAPP_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_DEFAULT_APPL_INIT_TASK_CODE
# error Using RTE_START_SEC_DEFAULT_APPL_INIT_TASK_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_DEFAULT_APPL_INIT_TASK_CODE
# error Using RTE_STOP_SEC_DEFAULT_APPL_INIT_TASK_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_DEFAULT_APPL_TASK_CODE
# error Using RTE_START_SEC_DEFAULT_APPL_TASK_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_DEFAULT_APPL_TASK_CODE
# error Using RTE_STOP_SEC_DEFAULT_APPL_TASK_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_DEFAULT_INIT_TASK_CODE
# error Using RTE_START_SEC_DEFAULT_INIT_TASK_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_DEFAULT_INIT_TASK_CODE
# error Using RTE_STOP_SEC_DEFAULT_INIT_TASK_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_DEFAULT_INIT_TASK_TRUSTED_CODE
# error Using RTE_START_SEC_DEFAULT_INIT_TASK_TRUSTED_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_DEFAULT_INIT_TASK_TRUSTED_CODE
# error Using RTE_STOP_SEC_DEFAULT_INIT_TASK_TRUSTED_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_IDLETASK_OSCORE0_CODE
# error Using RTE_START_SEC_IDLETASK_OSCORE0_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_IDLETASK_OSCORE0_CODE
# error Using RTE_STOP_SEC_IDLETASK_OSCORE0_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_COMM_APPL_CODE
# error Using RTE_START_SEC_COMM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_COMM_APPL_CODE
# error Using RTE_STOP_SEC_COMM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_MOTORCONTROLL_APPL_CODE
# error Using RTE_START_SEC_MOTORCONTROLL_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_MOTORCONTROLL_APPL_CODE
# error Using RTE_STOP_SEC_MOTORCONTROLL_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_MOTORCDD_APPL_CODE
# error Using RTE_START_SEC_MOTORCDD_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_MOTORCDD_APPL_CODE
# error Using RTE_STOP_SEC_MOTORCDD_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_NVM_APPL_CODE
# error Using RTE_START_SEC_NVM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_NVM_APPL_CODE
# error Using RTE_STOP_SEC_NVM_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_DEFAULT_BSW_ASYNC_TASK_10MS_CODE
# error Using RTE_START_SEC_DEFAULT_BSW_ASYNC_TASK_10MS_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_DEFAULT_BSW_ASYNC_TASK_10MS_CODE
# error Using RTE_STOP_SEC_DEFAULT_BSW_ASYNC_TASK_10MS_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# error Using RTE_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
# error Using RTE_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# error Using RTE_START_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED
# error Using RTE_STOP_SEC_VAR_NOCACHE_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# error Using RTE_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# error Using RTE_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# error Using RTE_START_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# error Using RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# error Using RTE_START_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED
# error Using RTE_STOP_SEC_VAR_NOCACHE_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_OS_OSCORE1_SWC_APPL_CODE
# error Using RTE_START_SEC_OS_OSCORE1_SWC_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_OS_OSCORE1_SWC_APPL_CODE
# error Using RTE_STOP_SEC_OS_OSCORE1_SWC_APPL_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_IDLETASK_OSCORE_1_CODE
# error Using RTE_START_SEC_IDLETASK_OSCORE_1_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_IDLETASK_OSCORE_1_CODE
# error Using RTE_STOP_SEC_IDLETASK_OSCORE_1_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_OSAPPLICATION_OSCORE1_CODE
# error Using RTE_START_SEC_OSAPPLICATION_OSCORE1_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_OSAPPLICATION_OSCORE1_CODE
# error Using RTE_STOP_SEC_OSAPPLICATION_OSCORE1_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED
# error Using RTE_START_SEC_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED
# error Using RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_OsApplication_OsCore1_NOCACHE_NOINIT_UNSPECIFIED
# error Using RTE_START_SEC_VAR_OsApplication_OsCore1_NOCACHE_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOCACHE_NOINIT_UNSPECIFIED
# error Using RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOCACHE_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_OsApplication_OsCore1_ZERO_INIT_UNSPECIFIED
# error Using RTE_START_SEC_VAR_OsApplication_OsCore1_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_OsApplication_OsCore1_ZERO_INIT_UNSPECIFIED
# error Using RTE_STOP_SEC_VAR_OsApplication_OsCore1_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_UNSPECIFIED
# error Using RTE_START_SEC_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_UNSPECIFIED
# error Using RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_8BIT
# error Using RTE_START_SEC_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_8BIT
# error Using RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED
# error Using RTE_START_SEC_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED
# error Using RTE_STOP_SEC_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_OsApplication_OsCore1_NOCACHE_INIT_UNSPECIFIED
# error Using RTE_START_SEC_VAR_OsApplication_OsCore1_NOCACHE_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOCACHE_INIT_UNSPECIFIED
# error Using RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOCACHE_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_SYSTEMAPPLICATION_OSCORE0_CODE
# error Using RTE_START_SEC_SYSTEMAPPLICATION_OSCORE0_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_SYSTEMAPPLICATION_OSCORE0_CODE
# error Using RTE_STOP_SEC_SYSTEMAPPLICATION_OSCORE0_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED
# error Using RTE_START_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED
# error Using RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_NOINIT_UNSPECIFIED
# error Using RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_NOINIT_UNSPECIFIED
# error Using RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore0_ZERO_INIT_UNSPECIFIED
# error Using RTE_START_SEC_VAR_SystemApplication_OsCore0_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore0_ZERO_INIT_UNSPECIFIED
# error Using RTE_STOP_SEC_VAR_SystemApplication_OsCore0_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_UNSPECIFIED
# error Using RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_UNSPECIFIED
# error Using RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_8BIT
# error Using RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_8BIT
# error Using RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED
# error Using RTE_START_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED
# error Using RTE_STOP_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_INIT_UNSPECIFIED
# error Using RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_INIT_UNSPECIFIED
# error Using RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_DEFAULT_MOTORINITTASK_CODE
# error Using RTE_START_SEC_DEFAULT_MOTORINITTASK_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_DEFAULT_MOTORINITTASK_CODE
# error Using RTE_STOP_SEC_DEFAULT_MOTORINITTASK_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_MOTORTASK_CODE
# error Using RTE_START_SEC_MOTORTASK_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_MOTORTASK_CODE
# error Using RTE_STOP_SEC_MOTORTASK_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_DEFAULT_INIT_TASK_CORE1_CODE
# error Using RTE_START_SEC_DEFAULT_INIT_TASK_CORE1_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_DEFAULT_INIT_TASK_CORE1_CODE
# error Using RTE_STOP_SEC_DEFAULT_INIT_TASK_CORE1_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_DEFAULT_INIT_TASK_CORE1_TRUSTED_CODE
# error Using RTE_START_SEC_DEFAULT_INIT_TASK_CORE1_TRUSTED_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_DEFAULT_INIT_TASK_CORE1_TRUSTED_CODE
# error Using RTE_STOP_SEC_DEFAULT_INIT_TASK_CORE1_TRUSTED_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_START_SEC_BSWCORE1TASK_CODE
# error Using RTE_START_SEC_BSWCORE1TASK_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef RTE_STOP_SEC_BSWCORE1TASK_CODE
# error Using RTE_STOP_SEC_BSWCORE1TASK_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif

#ifdef MEMMAP_ERROR
# error No MemMap section found in Rte_MemMap.h. Check your section define for validity.
#endif


/**********************************************************************************************************************
 *  POST USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

#endif
/**********************************************************************************************************************
 *  END OF FILE: Rte_MemMap.h
 *********************************************************************************************************************/

