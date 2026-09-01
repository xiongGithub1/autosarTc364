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
 *              File: WdgM_OsMemMap.h
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


/* PRQA S 0883 EOF */ /* MD_WdgM_0883 */

/********************************************************************************************************************** 
 *  Memory sections for core 0 
 *********************************************************************************************************************/ 
/* Memory section(s) for supervised entity 'WdgMSupervisedEntity' */ 
#ifdef WDGM_SE0_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
# undef WDGM_SE0_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED 
#endif /* ifdef WDGM_SE0_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE */ 
 
#ifdef WDGM_SE0_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
# undef WDGM_SE0_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED 
#endif /* ifdef WDGM_SE0_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE */ 
 
 
/********************************************************************************************************************** 
 *  Memory section(s) for core specific global data - core 0 
 *********************************************************************************************************************/ 
/* 
 * Read by all modules (tasks), written by WdgM_MainFunction() and WdgM_Init() only 
 */ 
#ifdef WDGM_GLOBAL_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
# undef WDGM_GLOBAL_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define OS_START_SEC_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED 
#endif /* ifdef WDGM_GLOBAL_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE */ 
 
#ifdef WDGM_GLOBAL_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE 
# undef WDGM_GLOBAL_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define OS_STOP_SEC_SystemApplication_OsCore0_VAR_NOINIT_UNSPECIFIED 
#endif /* ifdef WDGM_GLOBAL_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE */ 
 
 
 
/********************************************************************************************************************** 
 *  Global memory sections for single core usage 
 *********************************************************************************************************************/ 
#ifdef WDGM_GLOBAL_START_SEC_VAR_32BIT 
# undef WDGM_GLOBAL_START_SEC_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define WDGM_START_SEC_VAR_32BIT 
#endif /* ifdef WDGM_GLOBAL_START_SEC_VAR_32BIT */ 
 
#ifdef WDGM_GLOBAL_STOP_SEC_VAR_32BIT 
# undef WDGM_GLOBAL_STOP_SEC_VAR_32BIT /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define WDGM_STOP_SEC_VAR_32BIT 
#endif /* ifdef WDGM_GLOBAL_STOP_SEC_VAR_32BIT */ 
 
/********************************************************************************************************************** 
 *  Memory section for WdgM global shared data 
 *********************************************************************************************************************/ 
/* 
 * Read and write by all modules (tasks) 
 * WdgM read:  WdgM_CheckpointReached() and WdgM_MainFunction() 
 * WdgM write: WdgM_CheckpointReached() and WdgM_Init() 
 * Variables which are accessed by multiple cores must not be cached. 
 */ 
#ifdef WDGM_GLOBAL_SHARED_START_SEC_VAR_NOINIT_UNSPECIFIED 
# undef WDGM_GLOBAL_SHARED_START_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define OS_START_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED 
#endif /* ifdef WDGM_GLOBAL_SHARED_START_SEC_VAR_NOINIT_UNSPECIFIED */ 
#ifdef WDGM_GLOBAL_SHARED_STOP_SEC_VAR_NOINIT_UNSPECIFIED 
# undef WDGM_GLOBAL_SHARED_STOP_SEC_VAR_NOINIT_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */ 
# define OS_STOP_SEC_GLOBALSHARED_VAR_NOCACHE_NOINIT_UNSPECIFIED 
#endif /* ifdef WDGM_GLOBAL_SHARED_STOP_SEC_VAR_NOINIT_UNSPECIFIED */ 


/**********************************************************************************************************************
 *  END OF FILE: WdgM_OsMemMap.h
 *********************************************************************************************************************/

