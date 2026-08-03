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
 *              File: E2EXf_MemMap.h
 *   Generation Time: 2024-08-03 19:52:21
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

#if defined E2EXF_START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_CODE_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_CODE_OPEN
#  error Using E2EXF_STOP_SEC_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_CONST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_CONST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_CONST_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section farrom "MSR_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef E2EXF_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_CONST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_CONST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_CONST_UNSPECIFIED_OPEN
#  error Using E2EXF_STOP_SEC_CONST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma section farrom restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef E2EXF_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_VAR_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_VAR_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_VAR_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef E2EXF_START_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_VAR_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_VAR_INIT_UNSPECIFIED_OPEN
#  error Using E2EXF_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_VAR_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef E2EXF_STOP_SEC_VAR_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_VAR_NOINIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_NOINIT/OS_SystemApplication_OsCore0_VAR_NOINIT */
# pragma section farnoclear "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_VAR_NOINIT_UNSPECIFIED_OPEN
#  error Using E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_VAR_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_NOINIT/OS_SystemApplication_OsCore0_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_VAR_ZERO_INIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_VAR_ZERO_INIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_VAR_ZERO_INIT_8BIT_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef E2EXF_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_VAR_ZERO_INIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_VAR_ZERO_INIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_VAR_ZERO_INIT_8BIT_OPEN
#  error Using E2EXF_STOP_SEC_VAR_ZERO_INIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef E2EXF_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef E2EXF_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN
#  error Using E2EXF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_VAR_NOCACHE_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef E2EXF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_VAR_ZERO_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef E2EXF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_VAR_ZERO_INIT_UNSPECIFIED_OPEN
#  error Using E2EXF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_VAR_ZERO_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef E2EXF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_CODE_OsApplication_OsCore1
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_CODE_OsApplication_OsCore1 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_CODE_OsApplication_OsCore1_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_START_SEC_CODE_OsApplication_OsCore1 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_CODE_OsApplication_OsCore1
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_CODE_OsApplication_OsCore1 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_CODE_OsApplication_OsCore1_OPEN
#  error Using E2EXF_STOP_SEC_CODE_OsApplication_OsCore1 is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_CODE_OsApplication_OsCore1_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_STOP_SEC_CODE_OsApplication_OsCore1 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_CODE_SystemApplication_OsCore0
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_CODE_SystemApplication_OsCore0 is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_CODE_SystemApplication_OsCore0_OPEN

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_START_SEC_CODE_SystemApplication_OsCore0 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_CODE_SystemApplication_OsCore0
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_CODE_SystemApplication_OsCore0 is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_CODE_SystemApplication_OsCore0_OPEN
#  error Using E2EXF_STOP_SEC_CODE_SystemApplication_OsCore0 is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_CODE_SystemApplication_OsCore0_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Generation of pragmas is not possible as neither a start/stop pragma nor a valid vLinkGen logical group reference is given. */

# undef E2EXF_STOP_SEC_CODE_SystemApplication_OsCore0 /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_OsCore1_VAR_INIT/OS_OsApplication_OsCore1_VAR_INIT */
# pragma section farnoclear "OS_CORE1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef E2EXF_START_SEC_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED_OPEN
#  error Using E2EXF_STOP_SEC_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_OsCore1_VAR_INIT/OS_OsApplication_OsCore1_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef E2EXF_STOP_SEC_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_OsCore1_VAR_NOINIT/OS_OsApplication_OsCore1_VAR_NOINIT */
# pragma section farnoclear "OS_CORE1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE1_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE1_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef E2EXF_START_SEC_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED_OPEN
#  error Using E2EXF_STOP_SEC_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_OsApplication_OsCore1_VAR_NOINIT/OS_OsApplication_OsCore1_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef E2EXF_STOP_SEC_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef E2EXF_START_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED_OPEN
#  error Using E2EXF_STOP_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_INIT/OS_SystemApplication_OsCore0_VAR_INIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef E2EXF_STOP_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined E2EXF_START_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using E2EXF_START_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define E2EXF_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_NOINIT/OS_SystemApplication_OsCore0_VAR_NOINIT */
# pragma section farnoclear "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss "OS_CORE0_VAR_NOINIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata "OS_CORE0_VAR" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef E2EXF_START_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined E2EXF_STOP_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using E2EXF_STOP_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef E2EXF_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED_OPEN
#  error Using E2EXF_STOP_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef E2EXF_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/OS_SystemApplication_OsCore0_VAR_NOINIT/OS_SystemApplication_OsCore0_VAR_NOINIT */
# pragma section farnoclear restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section farbss restore /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma section fardata restore /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef E2EXF_STOP_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

/* -------------------------------------------------------------------------------- */


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/

#ifdef E2EXF_START_SEC_CODE
# error Using E2EXF_START_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_CODE
# error Using E2EXF_STOP_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_CONST_UNSPECIFIED
# error Using E2EXF_START_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_CONST_UNSPECIFIED
# error Using E2EXF_STOP_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_VAR_INIT_UNSPECIFIED
# error Using E2EXF_START_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_VAR_INIT_UNSPECIFIED
# error Using E2EXF_STOP_SEC_VAR_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED
# error Using E2EXF_START_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# error Using E2EXF_STOP_SEC_VAR_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_VAR_ZERO_INIT_8BIT
# error Using E2EXF_START_SEC_VAR_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_VAR_ZERO_INIT_8BIT
# error Using E2EXF_STOP_SEC_VAR_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# error Using E2EXF_START_SEC_VAR_NOCACHE_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT
# error Using E2EXF_STOP_SEC_VAR_NOCACHE_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# error Using E2EXF_START_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# error Using E2EXF_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_CODE_OsApplication_OsCore1
# error Using E2EXF_START_SEC_CODE_OsApplication_OsCore1 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_CODE_OsApplication_OsCore1
# error Using E2EXF_STOP_SEC_CODE_OsApplication_OsCore1 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_CODE_SystemApplication_OsCore0
# error Using E2EXF_START_SEC_CODE_SystemApplication_OsCore0 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_CODE_SystemApplication_OsCore0
# error Using E2EXF_STOP_SEC_CODE_SystemApplication_OsCore0 is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED
# error Using E2EXF_START_SEC_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED
# error Using E2EXF_STOP_SEC_VAR_OsApplication_OsCore1_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED
# error Using E2EXF_START_SEC_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED
# error Using E2EXF_STOP_SEC_VAR_OsApplication_OsCore1_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED
# error Using E2EXF_START_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED
# error Using E2EXF_STOP_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_START_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED
# error Using E2EXF_START_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef E2EXF_STOP_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED
# error Using E2EXF_STOP_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif

#ifdef MEMMAP_ERROR
# error No MemMap section found in E2EXf_MemMap.h. Check your section define for validity.
#endif


/**********************************************************************************************************************
 *  POST USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

#endif
/**********************************************************************************************************************
 *  END OF FILE: E2EXf_MemMap.h
 *********************************************************************************************************************/

