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
 *              File: Os_Link_Core1.lsl
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

/**********************************************************************************************************************
 *  CODE SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_INTVEC_CODE )
if (exists(".text.OS_INTVEC_CORE1_CODE"))
{
  group OS_INTVEC_CORE1_CODE_GROUP(align=8192)
  {
    select "[.]text.OS_INTVEC_CORE1_CODE";
  }
  "_OS_INTVEC_CORE1_CODE_START" = "_lc_gb_OS_INTVEC_CORE1_CODE_GROUP";
  "_OS_INTVEC_CORE1_CODE_END" = "_lc_ge_OS_INTVEC_CORE1_CODE_GROUP" - 1;
  "_OS_INTVEC_CORE1_CODE_LIMIT" = "_lc_ge_OS_INTVEC_CORE1_CODE_GROUP";
}
else
{
  "_OS_INTVEC_CORE1_CODE_START" = 0;
  "_OS_INTVEC_CORE1_CODE_END" = 0;
  "_OS_INTVEC_CORE1_CODE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_EXCVEC_CODE )
if (exists(".text.OS_EXCVEC_CORE1_CODE"))
{
  group OS_EXCVEC_CORE1_CODE_GROUP(align=256)
  {
    select "[.]text.OS_EXCVEC_CORE1_CODE";
  }
  "_OS_EXCVEC_CORE1_CODE_START" = "_lc_gb_OS_EXCVEC_CORE1_CODE_GROUP";
  "_OS_EXCVEC_CORE1_CODE_END" = "_lc_ge_OS_EXCVEC_CORE1_CODE_GROUP" - 1;
  "_OS_EXCVEC_CORE1_CODE_LIMIT" = "_lc_ge_OS_EXCVEC_CORE1_CODE_GROUP";
}
else
{
  "_OS_EXCVEC_CORE1_CODE_START" = 0;
  "_OS_EXCVEC_CORE1_CODE_END" = 0;
  "_OS_EXCVEC_CORE1_CODE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CALLOUT_CODE )
if (exists(".text.OS_BswCore1Task_CODE"))
{
  group OS_BswCore1Task_CODE_GROUP(align=8)
  {
    select "[.]text.OS_BswCore1Task_CODE";
  }
  "_OS_BswCore1Task_CODE_START" = "_lc_gb_OS_BswCore1Task_CODE_GROUP";
  "_OS_BswCore1Task_CODE_END" = "_lc_ge_OS_BswCore1Task_CODE_GROUP" - 1;
  "_OS_BswCore1Task_CODE_LIMIT" = "_lc_ge_OS_BswCore1Task_CODE_GROUP";
}
else
{
  "_OS_BswCore1Task_CODE_START" = 0;
  "_OS_BswCore1Task_CODE_END" = 0;
  "_OS_BswCore1Task_CODE_LIMIT" = 0;
}
if (exists(".text.OS_Default_Init_Task_Core1_CODE"))
{
  group OS_Default_Init_Task_Core1_CODE_GROUP(align=8)
  {
    select "[.]text.OS_Default_Init_Task_Core1_CODE";
  }
  "_OS_Default_Init_Task_Core1_CODE_START" = "_lc_gb_OS_Default_Init_Task_Core1_CODE_GROUP";
  "_OS_Default_Init_Task_Core1_CODE_END" = "_lc_ge_OS_Default_Init_Task_Core1_CODE_GROUP" - 1;
  "_OS_Default_Init_Task_Core1_CODE_LIMIT" = "_lc_ge_OS_Default_Init_Task_Core1_CODE_GROUP";
}
else
{
  "_OS_Default_Init_Task_Core1_CODE_START" = 0;
  "_OS_Default_Init_Task_Core1_CODE_END" = 0;
  "_OS_Default_Init_Task_Core1_CODE_LIMIT" = 0;
}
if (exists(".text.OS_Default_Init_Task_Core1_Trusted_CODE"))
{
  group OS_Default_Init_Task_Core1_Trusted_CODE_GROUP(align=8)
  {
    select "[.]text.OS_Default_Init_Task_Core1_Trusted_CODE";
  }
  "_OS_Default_Init_Task_Core1_Trusted_CODE_START" = "_lc_gb_OS_Default_Init_Task_Core1_Trusted_CODE_GROUP";
  "_OS_Default_Init_Task_Core1_Trusted_CODE_END" = "_lc_ge_OS_Default_Init_Task_Core1_Trusted_CODE_GROUP" - 1;
  "_OS_Default_Init_Task_Core1_Trusted_CODE_LIMIT" = "_lc_ge_OS_Default_Init_Task_Core1_Trusted_CODE_GROUP";
}
else
{
  "_OS_Default_Init_Task_Core1_Trusted_CODE_START" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_CODE_END" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_CODE_LIMIT" = 0;
}
if (exists(".text.OS_Default_MotorInitTask_CODE"))
{
  group OS_Default_MotorInitTask_CODE_GROUP(align=8)
  {
    select "[.]text.OS_Default_MotorInitTask_CODE";
  }
  "_OS_Default_MotorInitTask_CODE_START" = "_lc_gb_OS_Default_MotorInitTask_CODE_GROUP";
  "_OS_Default_MotorInitTask_CODE_END" = "_lc_ge_OS_Default_MotorInitTask_CODE_GROUP" - 1;
  "_OS_Default_MotorInitTask_CODE_LIMIT" = "_lc_ge_OS_Default_MotorInitTask_CODE_GROUP";
}
else
{
  "_OS_Default_MotorInitTask_CODE_START" = 0;
  "_OS_Default_MotorInitTask_CODE_END" = 0;
  "_OS_Default_MotorInitTask_CODE_LIMIT" = 0;
}
if (exists(".text.OS_MotorTask_CODE"))
{
  group OS_MotorTask_CODE_GROUP(align=8)
  {
    select "[.]text.OS_MotorTask_CODE";
  }
  "_OS_MotorTask_CODE_START" = "_lc_gb_OS_MotorTask_CODE_GROUP";
  "_OS_MotorTask_CODE_END" = "_lc_ge_OS_MotorTask_CODE_GROUP" - 1;
  "_OS_MotorTask_CODE_LIMIT" = "_lc_ge_OS_MotorTask_CODE_GROUP";
}
else
{
  "_OS_MotorTask_CODE_START" = 0;
  "_OS_MotorTask_CODE_END" = 0;
  "_OS_MotorTask_CODE_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_INTVEC_CODE
# undef OS_LINK_INTVEC_CODE
#endif

#ifdef OS_LINK_EXCVEC_CODE
# undef OS_LINK_EXCVEC_CODE
#endif

#ifdef OS_LINK_CALLOUT_CODE
# undef OS_LINK_CALLOUT_CODE
#endif


/**********************************************************************************************************************
 *  CONST SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_KERNEL ) || defined ( OS_LINK_CONST_KERNEL_FAR )
if (exists(".rodata.OS_CORE1_CONST"))
{
  group OS_CORE1_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]rodata.OS_CORE1_CONST";
  }
  "_OS_CORE1_CONST_START" = "_lc_gb_OS_CORE1_CONST_GROUP";
  "_OS_CORE1_CONST_END" = "_lc_ge_OS_CORE1_CONST_GROUP" - 1;
  "_OS_CORE1_CONST_LIMIT" = "_lc_ge_OS_CORE1_CONST_GROUP";
}
else
{
  "_OS_CORE1_CONST_START" = 0;
  "_OS_CORE1_CONST_END" = 0;
  "_OS_CORE1_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_KERNEL ) || defined ( OS_LINK_CONST_KERNEL_NEAR )
if (exists(".zrodata.OS_CORE1_CONST_FAST"))
{
  group OS_CORE1_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]zrodata.OS_CORE1_CONST_FAST";
  }
  "_OS_CORE1_CONST_FAST_START" = "_lc_gb_OS_CORE1_CONST_FAST_GROUP";
  "_OS_CORE1_CONST_FAST_END" = "_lc_ge_OS_CORE1_CONST_FAST_GROUP" - 1;
  "_OS_CORE1_CONST_FAST_LIMIT" = "_lc_ge_OS_CORE1_CONST_FAST_GROUP";
}
else
{
  "_OS_CORE1_CONST_FAST_START" = 0;
  "_OS_CORE1_CONST_FAST_END" = 0;
  "_OS_CORE1_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_INTVEC_CONST )
if (exists(".rodata.OS_INTVEC_CORE1_CONST"))
{
  group OS_INTVEC_CORE1_CONST_GROUP(align=8192)
  {
    select "[.]rodata.OS_INTVEC_CORE1_CONST";
  }
  "_OS_INTVEC_CORE1_CONST_START" = "_lc_gb_OS_INTVEC_CORE1_CONST_GROUP";
  "_OS_INTVEC_CORE1_CONST_END" = "_lc_ge_OS_INTVEC_CORE1_CONST_GROUP" - 1;
  "_OS_INTVEC_CORE1_CONST_LIMIT" = "_lc_ge_OS_INTVEC_CORE1_CONST_GROUP";
}
else
{
  "_OS_INTVEC_CORE1_CONST_START" = 0;
  "_OS_INTVEC_CORE1_CONST_END" = 0;
  "_OS_INTVEC_CORE1_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_EXCVEC_CONST )
if (exists(".rodata.OS_EXCVEC_CORE1_CONST"))
{
  group OS_EXCVEC_CORE1_CONST_GROUP(align=256)
  {
    select "[.]rodata.OS_EXCVEC_CORE1_CONST";
  }
  "_OS_EXCVEC_CORE1_CONST_START" = "_lc_gb_OS_EXCVEC_CORE1_CONST_GROUP";
  "_OS_EXCVEC_CORE1_CONST_END" = "_lc_ge_OS_EXCVEC_CORE1_CONST_GROUP" - 1;
  "_OS_EXCVEC_CORE1_CONST_LIMIT" = "_lc_ge_OS_EXCVEC_CORE1_CONST_GROUP";
}
else
{
  "_OS_EXCVEC_CORE1_CONST_START" = 0;
  "_OS_EXCVEC_CORE1_CONST_END" = 0;
  "_OS_EXCVEC_CORE1_CONST_LIMIT" = 0;
}
#endif


#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_APP ) || defined ( OS_LINK_CONST_APP_OSAPPLICATION_OSCORE1 ) || defined ( OS_LINK_CONST_APP_OSAPPLICATION_OSCORE1_FAR )
if (exists(".rodata.OS_OsApplication_OsCore1_CONST"))
{
  group OS_OsApplication_OsCore1_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]rodata.OS_OsApplication_OsCore1_CONST";
  }
  "_OS_OsApplication_OsCore1_CONST_START" = "_lc_gb_OS_OsApplication_OsCore1_CONST_GROUP";
  "_OS_OsApplication_OsCore1_CONST_END" = "_lc_ge_OS_OsApplication_OsCore1_CONST_GROUP" - 1;
  "_OS_OsApplication_OsCore1_CONST_LIMIT" = "_lc_ge_OS_OsApplication_OsCore1_CONST_GROUP";
}
else
{
  "_OS_OsApplication_OsCore1_CONST_START" = 0;
  "_OS_OsApplication_OsCore1_CONST_END" = 0;
  "_OS_OsApplication_OsCore1_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_APP ) || defined ( OS_LINK_CONST_APP_OSAPPLICATION_OSCORE1 ) || defined ( OS_LINK_CONST_APP_OSAPPLICATION_OSCORE1_NEAR )
if (exists(".zrodata.OS_OsApplication_OsCore1_CONST_FAST"))
{
  group OS_OsApplication_OsCore1_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]zrodata.OS_OsApplication_OsCore1_CONST_FAST";
  }
  "_OS_OsApplication_OsCore1_CONST_FAST_START" = "_lc_gb_OS_OsApplication_OsCore1_CONST_FAST_GROUP";
  "_OS_OsApplication_OsCore1_CONST_FAST_END" = "_lc_ge_OS_OsApplication_OsCore1_CONST_FAST_GROUP" - 1;
  "_OS_OsApplication_OsCore1_CONST_FAST_LIMIT" = "_lc_ge_OS_OsApplication_OsCore1_CONST_FAST_GROUP";
}
else
{
  "_OS_OsApplication_OsCore1_CONST_FAST_START" = 0;
  "_OS_OsApplication_OsCore1_CONST_FAST_END" = 0;
  "_OS_OsApplication_OsCore1_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_APP ) || defined ( OS_LINK_CONST_APP_OSAPPLICATION_OSCORE1 ) || defined ( OS_LINK_CONST_APP_OSAPPLICATION_OSCORE1_INIT )
















#endif

#ifdef OS_LINK_CONST_APP_OSAPPLICATION_OSCORE1
# undef OS_LINK_CONST_APP_OSAPPLICATION_OSCORE1
#endif

#ifdef OS_LINK_CONST_APP_OSAPPLICATION_OSCORE1_FAR
# undef OS_LINK_CONST_APP_OSAPPLICATION_OSCORE1_FAR
#endif

#ifdef OS_LINK_CONST_APP_OSAPPLICATION_OSCORE1_NEAR
# undef OS_LINK_CONST_APP_OSAPPLICATION_OSCORE1_NEAR
#endif

#ifdef OS_LINK_CONST_APP_OSAPPLICATION_OSCORE1_INIT
# undef OS_LINK_CONST_APP_OSAPPLICATION_OSCORE1_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_BSWCORE1TASK ) || defined ( OS_LINK_CONST_TASK_BSWCORE1TASK_FAR )
if (exists(".rodata.OS_BswCore1Task_CONST"))
{
  group OS_BswCore1Task_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]rodata.OS_BswCore1Task_CONST";
  }
  "_OS_BswCore1Task_CONST_START" = "_lc_gb_OS_BswCore1Task_CONST_GROUP";
  "_OS_BswCore1Task_CONST_END" = "_lc_ge_OS_BswCore1Task_CONST_GROUP" - 1;
  "_OS_BswCore1Task_CONST_LIMIT" = "_lc_ge_OS_BswCore1Task_CONST_GROUP";
}
else
{
  "_OS_BswCore1Task_CONST_START" = 0;
  "_OS_BswCore1Task_CONST_END" = 0;
  "_OS_BswCore1Task_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_BSWCORE1TASK ) || defined ( OS_LINK_CONST_TASK_BSWCORE1TASK_NEAR )
if (exists(".zrodata.OS_BswCore1Task_CONST_FAST"))
{
  group OS_BswCore1Task_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]zrodata.OS_BswCore1Task_CONST_FAST";
  }
  "_OS_BswCore1Task_CONST_FAST_START" = "_lc_gb_OS_BswCore1Task_CONST_FAST_GROUP";
  "_OS_BswCore1Task_CONST_FAST_END" = "_lc_ge_OS_BswCore1Task_CONST_FAST_GROUP" - 1;
  "_OS_BswCore1Task_CONST_FAST_LIMIT" = "_lc_ge_OS_BswCore1Task_CONST_FAST_GROUP";
}
else
{
  "_OS_BswCore1Task_CONST_FAST_START" = 0;
  "_OS_BswCore1Task_CONST_FAST_END" = 0;
  "_OS_BswCore1Task_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_BSWCORE1TASK ) || defined ( OS_LINK_CONST_TASK_BSWCORE1TASK_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_BSWCORE1TASK
# undef OS_LINK_CONST_TASK_BSWCORE1TASK
#endif

#ifdef OS_LINK_CONST_TASK_BSWCORE1TASK_FAR
# undef OS_LINK_CONST_TASK_BSWCORE1TASK_FAR
#endif

#ifdef OS_LINK_CONST_TASK_BSWCORE1TASK_NEAR
# undef OS_LINK_CONST_TASK_BSWCORE1TASK_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_BSWCORE1TASK_INIT
# undef OS_LINK_CONST_TASK_BSWCORE1TASK_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1 ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_FAR )
if (exists(".rodata.OS_Default_Init_Task_Core1_CONST"))
{
  group OS_Default_Init_Task_Core1_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]rodata.OS_Default_Init_Task_Core1_CONST";
  }
  "_OS_Default_Init_Task_Core1_CONST_START" = "_lc_gb_OS_Default_Init_Task_Core1_CONST_GROUP";
  "_OS_Default_Init_Task_Core1_CONST_END" = "_lc_ge_OS_Default_Init_Task_Core1_CONST_GROUP" - 1;
  "_OS_Default_Init_Task_Core1_CONST_LIMIT" = "_lc_ge_OS_Default_Init_Task_Core1_CONST_GROUP";
}
else
{
  "_OS_Default_Init_Task_Core1_CONST_START" = 0;
  "_OS_Default_Init_Task_Core1_CONST_END" = 0;
  "_OS_Default_Init_Task_Core1_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1 ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_NEAR )
if (exists(".zrodata.OS_Default_Init_Task_Core1_CONST_FAST"))
{
  group OS_Default_Init_Task_Core1_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]zrodata.OS_Default_Init_Task_Core1_CONST_FAST";
  }
  "_OS_Default_Init_Task_Core1_CONST_FAST_START" = "_lc_gb_OS_Default_Init_Task_Core1_CONST_FAST_GROUP";
  "_OS_Default_Init_Task_Core1_CONST_FAST_END" = "_lc_ge_OS_Default_Init_Task_Core1_CONST_FAST_GROUP" - 1;
  "_OS_Default_Init_Task_Core1_CONST_FAST_LIMIT" = "_lc_ge_OS_Default_Init_Task_Core1_CONST_FAST_GROUP";
}
else
{
  "_OS_Default_Init_Task_Core1_CONST_FAST_START" = 0;
  "_OS_Default_Init_Task_Core1_CONST_FAST_END" = 0;
  "_OS_Default_Init_Task_Core1_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1 ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_FAR
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_FAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_NEAR
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_INIT
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR )
if (exists(".rodata.OS_Default_Init_Task_Core1_Trusted_CONST"))
{
  group OS_Default_Init_Task_Core1_Trusted_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]rodata.OS_Default_Init_Task_Core1_Trusted_CONST";
  }
  "_OS_Default_Init_Task_Core1_Trusted_CONST_START" = "_lc_gb_OS_Default_Init_Task_Core1_Trusted_CONST_GROUP";
  "_OS_Default_Init_Task_Core1_Trusted_CONST_END" = "_lc_ge_OS_Default_Init_Task_Core1_Trusted_CONST_GROUP" - 1;
  "_OS_Default_Init_Task_Core1_Trusted_CONST_LIMIT" = "_lc_ge_OS_Default_Init_Task_Core1_Trusted_CONST_GROUP";
}
else
{
  "_OS_Default_Init_Task_Core1_Trusted_CONST_START" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_CONST_END" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR )
if (exists(".zrodata.OS_Default_Init_Task_Core1_Trusted_CONST_FAST"))
{
  group OS_Default_Init_Task_Core1_Trusted_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]zrodata.OS_Default_Init_Task_Core1_Trusted_CONST_FAST";
  }
  "_OS_Default_Init_Task_Core1_Trusted_CONST_FAST_START" = "_lc_gb_OS_Default_Init_Task_Core1_Trusted_CONST_FAST_GROUP";
  "_OS_Default_Init_Task_Core1_Trusted_CONST_FAST_END" = "_lc_ge_OS_Default_Init_Task_Core1_Trusted_CONST_FAST_GROUP" - 1;
  "_OS_Default_Init_Task_Core1_Trusted_CONST_FAST_LIMIT" = "_lc_ge_OS_Default_Init_Task_Core1_Trusted_CONST_FAST_GROUP";
}
else
{
  "_OS_Default_Init_Task_Core1_Trusted_CONST_FAST_START" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_CONST_FAST_END" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_INIT
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_MOTORINITTASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_MOTORINITTASK_FAR )
if (exists(".rodata.OS_Default_MotorInitTask_CONST"))
{
  group OS_Default_MotorInitTask_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]rodata.OS_Default_MotorInitTask_CONST";
  }
  "_OS_Default_MotorInitTask_CONST_START" = "_lc_gb_OS_Default_MotorInitTask_CONST_GROUP";
  "_OS_Default_MotorInitTask_CONST_END" = "_lc_ge_OS_Default_MotorInitTask_CONST_GROUP" - 1;
  "_OS_Default_MotorInitTask_CONST_LIMIT" = "_lc_ge_OS_Default_MotorInitTask_CONST_GROUP";
}
else
{
  "_OS_Default_MotorInitTask_CONST_START" = 0;
  "_OS_Default_MotorInitTask_CONST_END" = 0;
  "_OS_Default_MotorInitTask_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_MOTORINITTASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_MOTORINITTASK_NEAR )
if (exists(".zrodata.OS_Default_MotorInitTask_CONST_FAST"))
{
  group OS_Default_MotorInitTask_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]zrodata.OS_Default_MotorInitTask_CONST_FAST";
  }
  "_OS_Default_MotorInitTask_CONST_FAST_START" = "_lc_gb_OS_Default_MotorInitTask_CONST_FAST_GROUP";
  "_OS_Default_MotorInitTask_CONST_FAST_END" = "_lc_ge_OS_Default_MotorInitTask_CONST_FAST_GROUP" - 1;
  "_OS_Default_MotorInitTask_CONST_FAST_LIMIT" = "_lc_ge_OS_Default_MotorInitTask_CONST_FAST_GROUP";
}
else
{
  "_OS_Default_MotorInitTask_CONST_FAST_START" = 0;
  "_OS_Default_MotorInitTask_CONST_FAST_END" = 0;
  "_OS_Default_MotorInitTask_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_MOTORINITTASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_MOTORINITTASK_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_MOTORINITTASK
# undef OS_LINK_CONST_TASK_DEFAULT_MOTORINITTASK
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_MOTORINITTASK_FAR
# undef OS_LINK_CONST_TASK_DEFAULT_MOTORINITTASK_FAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_MOTORINITTASK_NEAR
# undef OS_LINK_CONST_TASK_DEFAULT_MOTORINITTASK_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_MOTORINITTASK_INIT
# undef OS_LINK_CONST_TASK_DEFAULT_MOTORINITTASK_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE_1 ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE_1_FAR )
if (exists(".rodata.OS_IdleTask_OsCore_1_CONST"))
{
  group OS_IdleTask_OsCore_1_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]rodata.OS_IdleTask_OsCore_1_CONST";
  }
  "_OS_IdleTask_OsCore_1_CONST_START" = "_lc_gb_OS_IdleTask_OsCore_1_CONST_GROUP";
  "_OS_IdleTask_OsCore_1_CONST_END" = "_lc_ge_OS_IdleTask_OsCore_1_CONST_GROUP" - 1;
  "_OS_IdleTask_OsCore_1_CONST_LIMIT" = "_lc_ge_OS_IdleTask_OsCore_1_CONST_GROUP";
}
else
{
  "_OS_IdleTask_OsCore_1_CONST_START" = 0;
  "_OS_IdleTask_OsCore_1_CONST_END" = 0;
  "_OS_IdleTask_OsCore_1_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE_1 ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE_1_NEAR )
if (exists(".zrodata.OS_IdleTask_OsCore_1_CONST_FAST"))
{
  group OS_IdleTask_OsCore_1_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]zrodata.OS_IdleTask_OsCore_1_CONST_FAST";
  }
  "_OS_IdleTask_OsCore_1_CONST_FAST_START" = "_lc_gb_OS_IdleTask_OsCore_1_CONST_FAST_GROUP";
  "_OS_IdleTask_OsCore_1_CONST_FAST_END" = "_lc_ge_OS_IdleTask_OsCore_1_CONST_FAST_GROUP" - 1;
  "_OS_IdleTask_OsCore_1_CONST_FAST_LIMIT" = "_lc_ge_OS_IdleTask_OsCore_1_CONST_FAST_GROUP";
}
else
{
  "_OS_IdleTask_OsCore_1_CONST_FAST_START" = 0;
  "_OS_IdleTask_OsCore_1_CONST_FAST_END" = 0;
  "_OS_IdleTask_OsCore_1_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE_1 ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE_1_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_IDLETASK_OSCORE_1
# undef OS_LINK_CONST_TASK_IDLETASK_OSCORE_1
#endif

#ifdef OS_LINK_CONST_TASK_IDLETASK_OSCORE_1_FAR
# undef OS_LINK_CONST_TASK_IDLETASK_OSCORE_1_FAR
#endif

#ifdef OS_LINK_CONST_TASK_IDLETASK_OSCORE_1_NEAR
# undef OS_LINK_CONST_TASK_IDLETASK_OSCORE_1_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_IDLETASK_OSCORE_1_INIT
# undef OS_LINK_CONST_TASK_IDLETASK_OSCORE_1_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_MOTORTASK ) || defined ( OS_LINK_CONST_TASK_MOTORTASK_FAR )
if (exists(".rodata.OS_MotorTask_CONST"))
{
  group OS_MotorTask_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]rodata.OS_MotorTask_CONST";
  }
  "_OS_MotorTask_CONST_START" = "_lc_gb_OS_MotorTask_CONST_GROUP";
  "_OS_MotorTask_CONST_END" = "_lc_ge_OS_MotorTask_CONST_GROUP" - 1;
  "_OS_MotorTask_CONST_LIMIT" = "_lc_ge_OS_MotorTask_CONST_GROUP";
}
else
{
  "_OS_MotorTask_CONST_START" = 0;
  "_OS_MotorTask_CONST_END" = 0;
  "_OS_MotorTask_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_MOTORTASK ) || defined ( OS_LINK_CONST_TASK_MOTORTASK_NEAR )
if (exists(".zrodata.OS_MotorTask_CONST_FAST"))
{
  group OS_MotorTask_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]zrodata.OS_MotorTask_CONST_FAST";
  }
  "_OS_MotorTask_CONST_FAST_START" = "_lc_gb_OS_MotorTask_CONST_FAST_GROUP";
  "_OS_MotorTask_CONST_FAST_END" = "_lc_ge_OS_MotorTask_CONST_FAST_GROUP" - 1;
  "_OS_MotorTask_CONST_FAST_LIMIT" = "_lc_ge_OS_MotorTask_CONST_FAST_GROUP";
}
else
{
  "_OS_MotorTask_CONST_FAST_START" = 0;
  "_OS_MotorTask_CONST_FAST_END" = 0;
  "_OS_MotorTask_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_MOTORTASK ) || defined ( OS_LINK_CONST_TASK_MOTORTASK_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_MOTORTASK
# undef OS_LINK_CONST_TASK_MOTORTASK
#endif

#ifdef OS_LINK_CONST_TASK_MOTORTASK_FAR
# undef OS_LINK_CONST_TASK_MOTORTASK_FAR
#endif

#ifdef OS_LINK_CONST_TASK_MOTORTASK_NEAR
# undef OS_LINK_CONST_TASK_MOTORTASK_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_MOTORTASK_INIT
# undef OS_LINK_CONST_TASK_MOTORTASK_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER1 ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER1_FAR )
if (exists(".rodata.OS_CounterIsr_SystemTimer1_CONST"))
{
  group OS_CounterIsr_SystemTimer1_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]rodata.OS_CounterIsr_SystemTimer1_CONST";
  }
  "_OS_CounterIsr_SystemTimer1_CONST_START" = "_lc_gb_OS_CounterIsr_SystemTimer1_CONST_GROUP";
  "_OS_CounterIsr_SystemTimer1_CONST_END" = "_lc_ge_OS_CounterIsr_SystemTimer1_CONST_GROUP" - 1;
  "_OS_CounterIsr_SystemTimer1_CONST_LIMIT" = "_lc_ge_OS_CounterIsr_SystemTimer1_CONST_GROUP";
}
else
{
  "_OS_CounterIsr_SystemTimer1_CONST_START" = 0;
  "_OS_CounterIsr_SystemTimer1_CONST_END" = 0;
  "_OS_CounterIsr_SystemTimer1_CONST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER1 ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER1_NEAR )
if (exists(".zrodata.OS_CounterIsr_SystemTimer1_CONST_FAST"))
{
  group OS_CounterIsr_SystemTimer1_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select "[.]zrodata.OS_CounterIsr_SystemTimer1_CONST_FAST";
  }
  "_OS_CounterIsr_SystemTimer1_CONST_FAST_START" = "_lc_gb_OS_CounterIsr_SystemTimer1_CONST_FAST_GROUP";
  "_OS_CounterIsr_SystemTimer1_CONST_FAST_END" = "_lc_ge_OS_CounterIsr_SystemTimer1_CONST_FAST_GROUP" - 1;
  "_OS_CounterIsr_SystemTimer1_CONST_FAST_LIMIT" = "_lc_ge_OS_CounterIsr_SystemTimer1_CONST_FAST_GROUP";
}
else
{
  "_OS_CounterIsr_SystemTimer1_CONST_FAST_START" = 0;
  "_OS_CounterIsr_SystemTimer1_CONST_FAST_END" = 0;
  "_OS_CounterIsr_SystemTimer1_CONST_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER1 ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER1_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER1
# undef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER1
#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER1_FAR
# undef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER1_FAR
#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER1_NEAR
# undef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER1_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER1_INIT
# undef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER1_INIT
#endif



#ifdef OS_LINK_CONST
# undef OS_LINK_CONST
#endif

#ifdef OS_LINK_CONST_APP
# undef OS_LINK_CONST_APP
#endif

#ifdef OS_LINK_CONST_TASK
# undef OS_LINK_CONST_TASK
#endif

#ifdef OS_LINK_CONST_ISR
# undef OS_LINK_CONST_ISR
#endif

#ifdef OS_LINK_CONST_KERNEL
# undef OS_LINK_CONST_KERNEL
#endif

#ifdef OS_LINK_CONST_KERNEL_FAR
# undef OS_LINK_CONST_KERNEL_FAR
#endif

#ifdef OS_LINK_CONST_KERNEL_NEAR
# undef OS_LINK_CONST_KERNEL_NEAR
#endif

#ifdef OS_LINK_INTVEC_CONST
# undef OS_LINK_INTVEC_CONST
#endif

#ifdef OS_LINK_EXCVEC_CONST
# undef OS_LINK_EXCVEC_CONST
#endif


/**********************************************************************************************************************
 *  VAR SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE_INIT )
if (exists(".data.OS_CORE1_VAR"))
{
  group OS_CORE1_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE1_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_CORE1_VAR";
    }
    reserved ".pad.OS_CORE1_VAR" (size=16);
  }
  "_OS_CORE1_VAR_START" = "_lc_gb_OS_CORE1_VAR_GROUP";
  "_OS_CORE1_VAR_END" = "_lc_ub__pad_OS_CORE1_VAR" - 1;
  "_OS_CORE1_VAR_LIMIT" = "_lc_ub__pad_OS_CORE1_VAR";
}
else
{
  "_OS_CORE1_VAR_START" = 0;
  "_OS_CORE1_VAR_END" = 0;
  "_OS_CORE1_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE_NOINIT )
if (exists(".bss.OS_CORE1_VAR_NOINIT"))
{
  group OS_CORE1_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE1_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CORE1_VAR_NOINIT";
    }
    reserved ".pad.OS_CORE1_VAR_NOINIT" (size=16);
  }
  "_OS_CORE1_VAR_NOINIT_START" = "_lc_gb_OS_CORE1_VAR_NOINIT_GROUP";
  "_OS_CORE1_VAR_NOINIT_END" = "_lc_ub__pad_OS_CORE1_VAR_NOINIT" - 1;
  "_OS_CORE1_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_CORE1_VAR_NOINIT";
}
else
{
  "_OS_CORE1_VAR_NOINIT_START" = 0;
  "_OS_CORE1_VAR_NOINIT_END" = 0;
  "_OS_CORE1_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT )
if (exists(".zdata.OS_CORE1_VAR_FAST"))
{
  group OS_CORE1_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE1_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_CORE1_VAR_FAST";
    }
    reserved ".pad.OS_CORE1_VAR_FAST" (size=16);
  }
  "_OS_CORE1_VAR_FAST_START" = "_lc_gb_OS_CORE1_VAR_FAST_GROUP";
  "_OS_CORE1_VAR_FAST_END" = "_lc_ub__pad_OS_CORE1_VAR_FAST" - 1;
  "_OS_CORE1_VAR_FAST_LIMIT" = "_lc_ub__pad_OS_CORE1_VAR_FAST";
}
else
{
  "_OS_CORE1_VAR_FAST_START" = 0;
  "_OS_CORE1_VAR_FAST_END" = 0;
  "_OS_CORE1_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_CORE1_VAR_FAST_NOINIT"))
{
  group OS_CORE1_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE1_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_CORE1_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_CORE1_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_CORE1_VAR_FAST_NOINIT_START" = "_lc_gb_OS_CORE1_VAR_FAST_NOINIT_GROUP";
  "_OS_CORE1_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_CORE1_VAR_FAST_NOINIT" - 1;
  "_OS_CORE1_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_CORE1_VAR_FAST_NOINIT";
}
else
{
  "_OS_CORE1_VAR_FAST_NOINIT_START" = 0;
  "_OS_CORE1_VAR_FAST_NOINIT_END" = 0;
  "_OS_CORE1_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE_INIT )
if (exists(".data.OS_CORE1_VAR_NOCACHE"))
{
  group OS_CORE1_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE1_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_CORE1_VAR_NOCACHE";
    }
    reserved ".pad.OS_CORE1_VAR_NOCACHE" (size=16);
  }
  "_OS_CORE1_VAR_NOCACHE_START" = "_lc_gb_OS_CORE1_VAR_NOCACHE_GROUP";
  "_OS_CORE1_VAR_NOCACHE_END" = "_lc_ub__pad_OS_CORE1_VAR_NOCACHE" - 1;
  "_OS_CORE1_VAR_NOCACHE_LIMIT" = "_lc_ub__pad_OS_CORE1_VAR_NOCACHE";
}
else
{
  "_OS_CORE1_VAR_NOCACHE_START" = 0;
  "_OS_CORE1_VAR_NOCACHE_END" = 0;
  "_OS_CORE1_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_CORE1_VAR_NOCACHE_NOINIT"))
{
  group OS_CORE1_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE1_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CORE1_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CORE1_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CORE1_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_CORE1_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_CORE1_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CORE1_VAR_NOCACHE_NOINIT" - 1;
  "_OS_CORE1_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_CORE1_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_CORE1_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_CORE1_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_CORE1_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_CORE1_VAR_FAST_NOCACHE"))
{
  group OS_CORE1_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE1_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_CORE1_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_CORE1_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_CORE1_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_CORE1_VAR_FAST_NOCACHE_GROUP";
  "_OS_CORE1_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_CORE1_VAR_FAST_NOCACHE" - 1;
  "_OS_CORE1_VAR_FAST_NOCACHE_LIMIT" = "_lc_ub__pad_OS_CORE1_VAR_FAST_NOCACHE";
}
else
{
  "_OS_CORE1_VAR_FAST_NOCACHE_START" = 0;
  "_OS_CORE1_VAR_FAST_NOCACHE_END" = 0;
  "_OS_CORE1_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_CORE1_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_CORE1_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE1_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_CORE1_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CORE1_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CORE1_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_CORE1_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_CORE1_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CORE1_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_CORE1_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_CORE1_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_CORE1_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_CORE1_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_CORE1_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_KERNEL_TRACE ) || defined ( OS_LINK_KERNEL_TRACE_FAR )
if (exists(".bss.OS_PUBLIC_CORE1_VAR_NOINIT"))
{
  group OS_PUBLIC_CORE1_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_PUBLIC_CORE1_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_PUBLIC_CORE1_VAR_NOINIT";
    }
    reserved ".pad.OS_PUBLIC_CORE1_VAR_NOINIT" (size=16);
  }
  "_OS_PUBLIC_CORE1_VAR_NOINIT_START" = "_lc_gb_OS_PUBLIC_CORE1_VAR_NOINIT_GROUP";
  "_OS_PUBLIC_CORE1_VAR_NOINIT_END" = "_lc_ub__pad_OS_PUBLIC_CORE1_VAR_NOINIT" - 1;
  "_OS_PUBLIC_CORE1_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_PUBLIC_CORE1_VAR_NOINIT";
}
else
{
  "_OS_PUBLIC_CORE1_VAR_NOINIT_START" = 0;
  "_OS_PUBLIC_CORE1_VAR_NOINIT_END" = 0;
  "_OS_PUBLIC_CORE1_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_KERNEL_TRACE ) || defined ( OS_LINK_KERNEL_TRACE_NEAR )
if (exists(".bss.OS_PUBLIC_CORE1_VAR_FAST_NOINIT"))
{
  group OS_PUBLIC_CORE1_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_PUBLIC_CORE1_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_PUBLIC_CORE1_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_PUBLIC_CORE1_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_PUBLIC_CORE1_VAR_FAST_NOINIT_START" = "_lc_gb_OS_PUBLIC_CORE1_VAR_FAST_NOINIT_GROUP";
  "_OS_PUBLIC_CORE1_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_PUBLIC_CORE1_VAR_FAST_NOINIT" - 1;
  "_OS_PUBLIC_CORE1_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_PUBLIC_CORE1_VAR_FAST_NOINIT";
}
else
{
  "_OS_PUBLIC_CORE1_VAR_FAST_NOINIT_START" = 0;
  "_OS_PUBLIC_CORE1_VAR_FAST_NOINIT_END" = 0;
  "_OS_PUBLIC_CORE1_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_KERNEL_BARRIERS ) || defined ( OS_LINK_KERNEL_BARRIERS_FAR )
if (exists(".bss.OS_BARRIER_CORE1_VAR_NOCACHE_NOINIT"))
{
  group OS_BARRIER_CORE1_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BARRIER_CORE1_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_BARRIER_CORE1_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_BARRIER_CORE1_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_BARRIER_CORE1_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_BARRIER_CORE1_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_BARRIER_CORE1_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_BARRIER_CORE1_VAR_NOCACHE_NOINIT" - 1;
  "_OS_BARRIER_CORE1_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_BARRIER_CORE1_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_BARRIER_CORE1_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_BARRIER_CORE1_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_BARRIER_CORE1_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_KERNEL_BARRIERS ) || defined ( OS_LINK_KERNEL_BARRIERS_NEAR )
if (exists(".bss.OS_BARRIER_CORE1_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_BARRIER_CORE1_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BARRIER_CORE1_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_BARRIER_CORE1_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_BARRIER_CORE1_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_BARRIER_CORE1_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_BARRIER_CORE1_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_BARRIER_CORE1_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_BARRIER_CORE1_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_BARRIER_CORE1_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_BARRIER_CORE1_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_BARRIER_CORE1_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_BARRIER_CORE1_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_BARRIER_CORE1_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_KERNEL_CORESTATUS ) || defined ( OS_LINK_KERNEL_CORESTATUS_FAR )
if (exists(".bss.OS_CORESTATUS_CORE1_VAR_NOCACHE_NOINIT"))
{
  group OS_CORESTATUS_CORE1_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORESTATUS_CORE1_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CORESTATUS_CORE1_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CORESTATUS_CORE1_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CORESTATUS_CORE1_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_CORESTATUS_CORE1_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_CORESTATUS_CORE1_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CORESTATUS_CORE1_VAR_NOCACHE_NOINIT" - 1;
  "_OS_CORESTATUS_CORE1_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_CORESTATUS_CORE1_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_CORESTATUS_CORE1_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_CORESTATUS_CORE1_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_CORESTATUS_CORE1_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_KERNEL_CORESTATUS ) || defined ( OS_LINK_KERNEL_CORESTATUS_NEAR )
if (exists(".bss.OS_CORESTATUS_CORE1_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_CORESTATUS_CORE1_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORESTATUS_CORE1_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CORESTATUS_CORE1_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CORESTATUS_CORE1_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CORESTATUS_CORE1_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_CORESTATUS_CORE1_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_CORESTATUS_CORE1_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CORESTATUS_CORE1_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_CORESTATUS_CORE1_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_CORESTATUS_CORE1_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_CORESTATUS_CORE1_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_CORESTATUS_CORE1_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_CORESTATUS_CORE1_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif


#ifdef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1
group OS_OsApplication_OsCore1_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1 ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_CACHE_INIT )
if (exists(".data.OS_OsApplication_OsCore1_VAR"))
{
  group OS_OsApplication_OsCore1_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsApplication_OsCore1_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_OsApplication_OsCore1_VAR";
    }
    reserved ".pad.OS_OsApplication_OsCore1_VAR" (size=16);
  }
  "_OS_OsApplication_OsCore1_VAR_START" = "_lc_gb_OS_OsApplication_OsCore1_VAR_GROUP";
  "_OS_OsApplication_OsCore1_VAR_END" = "_lc_ub__pad_OS_OsApplication_OsCore1_VAR" - 1;
  "_OS_OsApplication_OsCore1_VAR_LIMIT" = "_lc_ub__pad_OS_OsApplication_OsCore1_VAR";
}
else
{
  "_OS_OsApplication_OsCore1_VAR_START" = 0;
  "_OS_OsApplication_OsCore1_VAR_END" = 0;
  "_OS_OsApplication_OsCore1_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1 ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_CACHE_NOINIT )
if (exists(".bss.OS_OsApplication_OsCore1_VAR_NOINIT"))
{
  group OS_OsApplication_OsCore1_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsApplication_OsCore1_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_OsApplication_OsCore1_VAR_NOINIT";
    }
    reserved ".pad.OS_OsApplication_OsCore1_VAR_NOINIT" (size=16);
  }
  "_OS_OsApplication_OsCore1_VAR_NOINIT_START" = "_lc_gb_OS_OsApplication_OsCore1_VAR_NOINIT_GROUP";
  "_OS_OsApplication_OsCore1_VAR_NOINIT_END" = "_lc_ub__pad_OS_OsApplication_OsCore1_VAR_NOINIT" - 1;
  "_OS_OsApplication_OsCore1_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_OsApplication_OsCore1_VAR_NOINIT";
}
else
{
  "_OS_OsApplication_OsCore1_VAR_NOINIT_START" = 0;
  "_OS_OsApplication_OsCore1_VAR_NOINIT_END" = 0;
  "_OS_OsApplication_OsCore1_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1 ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_OsApplication_OsCore1_VAR_ZERO_INIT_bss") || exists(".data.OS_OsApplication_OsCore1_VAR_ZERO_INIT"))
{
  group OS_OsApplication_OsCore1_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsApplication_OsCore1_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_OsApplication_OsCore1_VAR_ZERO_INIT_bss";
      select "[.]data.OS_OsApplication_OsCore1_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_OsApplication_OsCore1_VAR_ZERO_INIT" (size=16);
  }
  "_OS_OsApplication_OsCore1_VAR_ZERO_INIT_START" = "_lc_gb_OS_OsApplication_OsCore1_VAR_ZERO_INIT_GROUP";
  "_OS_OsApplication_OsCore1_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_OsApplication_OsCore1_VAR_ZERO_INIT" - 1;
  "_OS_OsApplication_OsCore1_VAR_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_OsApplication_OsCore1_VAR_ZERO_INIT";
}
else
{
  "_OS_OsApplication_OsCore1_VAR_ZERO_INIT_START" = 0;
  "_OS_OsApplication_OsCore1_VAR_ZERO_INIT_END" = 0;
  "_OS_OsApplication_OsCore1_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1 ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_CACHE_INIT )
if (exists(".zdata.OS_OsApplication_OsCore1_VAR_FAST"))
{
  group OS_OsApplication_OsCore1_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsApplication_OsCore1_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_OsApplication_OsCore1_VAR_FAST";
    }
    reserved ".pad.OS_OsApplication_OsCore1_VAR_FAST" (size=16);
  }
  "_OS_OsApplication_OsCore1_VAR_FAST_START" = "_lc_gb_OS_OsApplication_OsCore1_VAR_FAST_GROUP";
  "_OS_OsApplication_OsCore1_VAR_FAST_END" = "_lc_ub__pad_OS_OsApplication_OsCore1_VAR_FAST" - 1;
  "_OS_OsApplication_OsCore1_VAR_FAST_LIMIT" = "_lc_ub__pad_OS_OsApplication_OsCore1_VAR_FAST";
}
else
{
  "_OS_OsApplication_OsCore1_VAR_FAST_START" = 0;
  "_OS_OsApplication_OsCore1_VAR_FAST_END" = 0;
  "_OS_OsApplication_OsCore1_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1 ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_OsApplication_OsCore1_VAR_FAST_NOINIT"))
{
  group OS_OsApplication_OsCore1_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsApplication_OsCore1_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_OsApplication_OsCore1_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_OsApplication_OsCore1_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_OsApplication_OsCore1_VAR_FAST_NOINIT_START" = "_lc_gb_OS_OsApplication_OsCore1_VAR_FAST_NOINIT_GROUP";
  "_OS_OsApplication_OsCore1_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_OsApplication_OsCore1_VAR_FAST_NOINIT" - 1;
  "_OS_OsApplication_OsCore1_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_OsApplication_OsCore1_VAR_FAST_NOINIT";
}
else
{
  "_OS_OsApplication_OsCore1_VAR_FAST_NOINIT_START" = 0;
  "_OS_OsApplication_OsCore1_VAR_FAST_NOINIT_END" = 0;
  "_OS_OsApplication_OsCore1_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1 ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_OsApplication_OsCore1_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_OsApplication_OsCore1_VAR_FAST_ZERO_INIT"))
{
  group OS_OsApplication_OsCore1_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsApplication_OsCore1_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_OsApplication_OsCore1_VAR_FAST_ZERO_INIT_bss";
      select "[.]zdata.OS_OsApplication_OsCore1_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_OsApplication_OsCore1_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_OsApplication_OsCore1_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_OsApplication_OsCore1_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_OsApplication_OsCore1_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_OsApplication_OsCore1_VAR_FAST_ZERO_INIT" - 1;
  "_OS_OsApplication_OsCore1_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_OsApplication_OsCore1_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_OsApplication_OsCore1_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_OsApplication_OsCore1_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_OsApplication_OsCore1_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1 ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_NOCACHE_INIT )
if (exists(".data.OS_OsApplication_OsCore1_VAR_NOCACHE"))
{
  group OS_OsApplication_OsCore1_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsApplication_OsCore1_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_OsApplication_OsCore1_VAR_NOCACHE";
    }
    reserved ".pad.OS_OsApplication_OsCore1_VAR_NOCACHE" (size=16);
  }
  "_OS_OsApplication_OsCore1_VAR_NOCACHE_START" = "_lc_gb_OS_OsApplication_OsCore1_VAR_NOCACHE_GROUP";
  "_OS_OsApplication_OsCore1_VAR_NOCACHE_END" = "_lc_ub__pad_OS_OsApplication_OsCore1_VAR_NOCACHE" - 1;
  "_OS_OsApplication_OsCore1_VAR_NOCACHE_LIMIT" = "_lc_ub__pad_OS_OsApplication_OsCore1_VAR_NOCACHE";
}
else
{
  "_OS_OsApplication_OsCore1_VAR_NOCACHE_START" = 0;
  "_OS_OsApplication_OsCore1_VAR_NOCACHE_END" = 0;
  "_OS_OsApplication_OsCore1_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1 ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_OsApplication_OsCore1_VAR_NOCACHE_NOINIT"))
{
  group OS_OsApplication_OsCore1_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsApplication_OsCore1_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_OsApplication_OsCore1_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_OsApplication_OsCore1_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_OsApplication_OsCore1_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_OsApplication_OsCore1_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_OsApplication_OsCore1_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_OsApplication_OsCore1_VAR_NOCACHE_NOINIT" - 1;
  "_OS_OsApplication_OsCore1_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_OsApplication_OsCore1_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_OsApplication_OsCore1_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_OsApplication_OsCore1_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_OsApplication_OsCore1_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1 ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_OsApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_OsApplication_OsCore1_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_OsApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_OsApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_bss";
      select "[.]data.OS_OsApplication_OsCore1_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_OsApplication_OsCore1_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_OsApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_OsApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_OsApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_OsApplication_OsCore1_VAR_NOCACHE_ZERO_INIT" - 1;
  "_OS_OsApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_OsApplication_OsCore1_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_OsApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_OsApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_OsApplication_OsCore1_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1 ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_OsApplication_OsCore1_VAR_FAST_NOCACHE"))
{
  group OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_OsApplication_OsCore1_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_OsApplication_OsCore1_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_GROUP";
  "_OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_OsApplication_OsCore1_VAR_FAST_NOCACHE" - 1;
  "_OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_LIMIT" = "_lc_ub__pad_OS_OsApplication_OsCore1_VAR_FAST_NOCACHE";
}
else
{
  "_OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_START" = 0;
  "_OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_END" = 0;
  "_OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1 ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1 ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select "[.]zdata.OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT" - 1;
  "_OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_OsApplication_OsCore1_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1
} /* OS_OsApplication_OsCore1_VAR_ALL_GROUP */
"_OS_OsApplication_OsCore1_VAR_ALL_START" = "_lc_gb_OS_OsApplication_OsCore1_VAR_ALL_GROUP";
"_OS_OsApplication_OsCore1_VAR_ALL_END" = "_lc_ge_OS_OsApplication_OsCore1_VAR_ALL_GROUP" - 1;
"_OS_OsApplication_OsCore1_VAR_ALL_LIMIT" = "_lc_ge_OS_OsApplication_OsCore1_VAR_ALL_GROUP";

# undef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR
# undef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_CACHE
# undef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_CACHE_INIT
# undef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_NOCACHE
# undef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR
# undef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_CACHE
# undef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_CACHE_INIT
# undef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_NOCACHE
# undef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_OSAPPLICATION_OSCORE1_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_BSWCORE1TASK
group OS_BswCore1Task_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_FAR ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_CACHE_INIT )
if (exists(".data.OS_BswCore1Task_VAR"))
{
  group OS_BswCore1Task_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswCore1Task_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_BswCore1Task_VAR";
    }
    reserved ".pad.OS_BswCore1Task_VAR" (size=16);
  }
  "_OS_BswCore1Task_VAR_START" = "_lc_gb_OS_BswCore1Task_VAR_GROUP";
  "_OS_BswCore1Task_VAR_END" = "_lc_ub__pad_OS_BswCore1Task_VAR" - 1;
  "_OS_BswCore1Task_VAR_LIMIT" = "_lc_ub__pad_OS_BswCore1Task_VAR";
}
else
{
  "_OS_BswCore1Task_VAR_START" = 0;
  "_OS_BswCore1Task_VAR_END" = 0;
  "_OS_BswCore1Task_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_FAR ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_CACHE_NOINIT )
if (exists(".bss.OS_BswCore1Task_VAR_NOINIT"))
{
  group OS_BswCore1Task_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswCore1Task_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_BswCore1Task_VAR_NOINIT";
    }
    reserved ".pad.OS_BswCore1Task_VAR_NOINIT" (size=16);
  }
  "_OS_BswCore1Task_VAR_NOINIT_START" = "_lc_gb_OS_BswCore1Task_VAR_NOINIT_GROUP";
  "_OS_BswCore1Task_VAR_NOINIT_END" = "_lc_ub__pad_OS_BswCore1Task_VAR_NOINIT" - 1;
  "_OS_BswCore1Task_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_BswCore1Task_VAR_NOINIT";
}
else
{
  "_OS_BswCore1Task_VAR_NOINIT_START" = 0;
  "_OS_BswCore1Task_VAR_NOINIT_END" = 0;
  "_OS_BswCore1Task_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_FAR ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_BswCore1Task_VAR_ZERO_INIT_bss") || exists(".data.OS_BswCore1Task_VAR_ZERO_INIT"))
{
  group OS_BswCore1Task_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswCore1Task_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_BswCore1Task_VAR_ZERO_INIT_bss";
      select "[.]data.OS_BswCore1Task_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_BswCore1Task_VAR_ZERO_INIT" (size=16);
  }
  "_OS_BswCore1Task_VAR_ZERO_INIT_START" = "_lc_gb_OS_BswCore1Task_VAR_ZERO_INIT_GROUP";
  "_OS_BswCore1Task_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_BswCore1Task_VAR_ZERO_INIT" - 1;
  "_OS_BswCore1Task_VAR_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_BswCore1Task_VAR_ZERO_INIT";
}
else
{
  "_OS_BswCore1Task_VAR_ZERO_INIT_START" = 0;
  "_OS_BswCore1Task_VAR_ZERO_INIT_END" = 0;
  "_OS_BswCore1Task_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_CACHE_INIT )
if (exists(".zdata.OS_BswCore1Task_VAR_FAST"))
{
  group OS_BswCore1Task_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswCore1Task_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_BswCore1Task_VAR_FAST";
    }
    reserved ".pad.OS_BswCore1Task_VAR_FAST" (size=16);
  }
  "_OS_BswCore1Task_VAR_FAST_START" = "_lc_gb_OS_BswCore1Task_VAR_FAST_GROUP";
  "_OS_BswCore1Task_VAR_FAST_END" = "_lc_ub__pad_OS_BswCore1Task_VAR_FAST" - 1;
  "_OS_BswCore1Task_VAR_FAST_LIMIT" = "_lc_ub__pad_OS_BswCore1Task_VAR_FAST";
}
else
{
  "_OS_BswCore1Task_VAR_FAST_START" = 0;
  "_OS_BswCore1Task_VAR_FAST_END" = 0;
  "_OS_BswCore1Task_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_BswCore1Task_VAR_FAST_NOINIT"))
{
  group OS_BswCore1Task_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswCore1Task_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_BswCore1Task_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_BswCore1Task_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_BswCore1Task_VAR_FAST_NOINIT_START" = "_lc_gb_OS_BswCore1Task_VAR_FAST_NOINIT_GROUP";
  "_OS_BswCore1Task_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_BswCore1Task_VAR_FAST_NOINIT" - 1;
  "_OS_BswCore1Task_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_BswCore1Task_VAR_FAST_NOINIT";
}
else
{
  "_OS_BswCore1Task_VAR_FAST_NOINIT_START" = 0;
  "_OS_BswCore1Task_VAR_FAST_NOINIT_END" = 0;
  "_OS_BswCore1Task_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_BswCore1Task_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_BswCore1Task_VAR_FAST_ZERO_INIT"))
{
  group OS_BswCore1Task_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswCore1Task_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_BswCore1Task_VAR_FAST_ZERO_INIT_bss";
      select "[.]zdata.OS_BswCore1Task_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_BswCore1Task_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_BswCore1Task_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_BswCore1Task_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_BswCore1Task_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_BswCore1Task_VAR_FAST_ZERO_INIT" - 1;
  "_OS_BswCore1Task_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_BswCore1Task_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_BswCore1Task_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_BswCore1Task_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_BswCore1Task_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_FAR ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_NOCACHE_INIT )
if (exists(".data.OS_BswCore1Task_VAR_NOCACHE"))
{
  group OS_BswCore1Task_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswCore1Task_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_BswCore1Task_VAR_NOCACHE";
    }
    reserved ".pad.OS_BswCore1Task_VAR_NOCACHE" (size=16);
  }
  "_OS_BswCore1Task_VAR_NOCACHE_START" = "_lc_gb_OS_BswCore1Task_VAR_NOCACHE_GROUP";
  "_OS_BswCore1Task_VAR_NOCACHE_END" = "_lc_ub__pad_OS_BswCore1Task_VAR_NOCACHE" - 1;
  "_OS_BswCore1Task_VAR_NOCACHE_LIMIT" = "_lc_ub__pad_OS_BswCore1Task_VAR_NOCACHE";
}
else
{
  "_OS_BswCore1Task_VAR_NOCACHE_START" = 0;
  "_OS_BswCore1Task_VAR_NOCACHE_END" = 0;
  "_OS_BswCore1Task_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_FAR ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_BswCore1Task_VAR_NOCACHE_NOINIT"))
{
  group OS_BswCore1Task_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswCore1Task_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_BswCore1Task_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_BswCore1Task_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_BswCore1Task_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_BswCore1Task_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_BswCore1Task_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_BswCore1Task_VAR_NOCACHE_NOINIT" - 1;
  "_OS_BswCore1Task_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_BswCore1Task_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_BswCore1Task_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_BswCore1Task_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_BswCore1Task_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_FAR ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_BswCore1Task_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_BswCore1Task_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_BswCore1Task_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswCore1Task_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_BswCore1Task_VAR_NOCACHE_ZERO_INIT_bss";
      select "[.]data.OS_BswCore1Task_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_BswCore1Task_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_BswCore1Task_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_BswCore1Task_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_BswCore1Task_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_BswCore1Task_VAR_NOCACHE_ZERO_INIT" - 1;
  "_OS_BswCore1Task_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_BswCore1Task_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_BswCore1Task_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_BswCore1Task_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_BswCore1Task_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_BswCore1Task_VAR_FAST_NOCACHE"))
{
  group OS_BswCore1Task_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswCore1Task_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_BswCore1Task_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_BswCore1Task_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_BswCore1Task_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_BswCore1Task_VAR_FAST_NOCACHE_GROUP";
  "_OS_BswCore1Task_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_BswCore1Task_VAR_FAST_NOCACHE" - 1;
  "_OS_BswCore1Task_VAR_FAST_NOCACHE_LIMIT" = "_lc_ub__pad_OS_BswCore1Task_VAR_FAST_NOCACHE";
}
else
{
  "_OS_BswCore1Task_VAR_FAST_NOCACHE_START" = 0;
  "_OS_BswCore1Task_VAR_FAST_NOCACHE_END" = 0;
  "_OS_BswCore1Task_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_BswCore1Task_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_BswCore1Task_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswCore1Task_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_BswCore1Task_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_BswCore1Task_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_BswCore1Task_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_BswCore1Task_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_BswCore1Task_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_BswCore1Task_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_BswCore1Task_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_BswCore1Task_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_BswCore1Task_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_BswCore1Task_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_BswCore1Task_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_BswCore1Task_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_BswCore1Task_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_BswCore1Task_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BswCore1Task_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_BswCore1Task_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select "[.]zdata.OS_BswCore1Task_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_BswCore1Task_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_BswCore1Task_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_BswCore1Task_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_BswCore1Task_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_BswCore1Task_VAR_FAST_NOCACHE_ZERO_INIT" - 1;
  "_OS_BswCore1Task_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_BswCore1Task_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_BswCore1Task_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_BswCore1Task_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_BswCore1Task_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_BSWCORE1TASK
} /* OS_BswCore1Task_VAR_ALL_GROUP */
"_OS_BswCore1Task_VAR_ALL_START" = "_lc_gb_OS_BswCore1Task_VAR_ALL_GROUP";
"_OS_BswCore1Task_VAR_ALL_END" = "_lc_ge_OS_BswCore1Task_VAR_ALL_GROUP" - 1;
"_OS_BswCore1Task_VAR_ALL_LIMIT" = "_lc_ge_OS_BswCore1Task_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_BSWCORE1TASK
#endif

#ifdef OS_LINK_VAR_TASK_BSWCORE1TASK_FAR
# undef OS_LINK_VAR_TASK_BSWCORE1TASK_FAR
#endif

#ifdef OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_CACHE
# undef OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_BSWCORE1TASK_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR
# undef OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_CACHE
# undef OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_BSWCORE1TASK_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1
group OS_Default_Init_Task_Core1_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1 ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_CACHE_INIT )
if (exists(".data.OS_Default_Init_Task_Core1_VAR"))
{
  group OS_Default_Init_Task_Core1_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Core1_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_Default_Init_Task_Core1_VAR";
    }
    reserved ".pad.OS_Default_Init_Task_Core1_VAR" (size=16);
  }
  "_OS_Default_Init_Task_Core1_VAR_START" = "_lc_gb_OS_Default_Init_Task_Core1_VAR_GROUP";
  "_OS_Default_Init_Task_Core1_VAR_END" = "_lc_ub__pad_OS_Default_Init_Task_Core1_VAR" - 1;
  "_OS_Default_Init_Task_Core1_VAR_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Core1_VAR";
}
else
{
  "_OS_Default_Init_Task_Core1_VAR_START" = 0;
  "_OS_Default_Init_Task_Core1_VAR_END" = 0;
  "_OS_Default_Init_Task_Core1_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1 ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_CACHE_NOINIT )
if (exists(".bss.OS_Default_Init_Task_Core1_VAR_NOINIT"))
{
  group OS_Default_Init_Task_Core1_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Core1_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_Init_Task_Core1_VAR_NOINIT";
    }
    reserved ".pad.OS_Default_Init_Task_Core1_VAR_NOINIT" (size=16);
  }
  "_OS_Default_Init_Task_Core1_VAR_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_Core1_VAR_NOINIT_GROUP";
  "_OS_Default_Init_Task_Core1_VAR_NOINIT_END" = "_lc_ub__pad_OS_Default_Init_Task_Core1_VAR_NOINIT" - 1;
  "_OS_Default_Init_Task_Core1_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Core1_VAR_NOINIT";
}
else
{
  "_OS_Default_Init_Task_Core1_VAR_NOINIT_START" = 0;
  "_OS_Default_Init_Task_Core1_VAR_NOINIT_END" = 0;
  "_OS_Default_Init_Task_Core1_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1 ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_Default_Init_Task_Core1_VAR_ZERO_INIT_bss") || exists(".data.OS_Default_Init_Task_Core1_VAR_ZERO_INIT"))
{
  group OS_Default_Init_Task_Core1_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Core1_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_Init_Task_Core1_VAR_ZERO_INIT_bss";
      select "[.]data.OS_Default_Init_Task_Core1_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Init_Task_Core1_VAR_ZERO_INIT" (size=16);
  }
  "_OS_Default_Init_Task_Core1_VAR_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_Core1_VAR_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_Core1_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Init_Task_Core1_VAR_ZERO_INIT" - 1;
  "_OS_Default_Init_Task_Core1_VAR_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Core1_VAR_ZERO_INIT";
}
else
{
  "_OS_Default_Init_Task_Core1_VAR_ZERO_INIT_START" = 0;
  "_OS_Default_Init_Task_Core1_VAR_ZERO_INIT_END" = 0;
  "_OS_Default_Init_Task_Core1_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1 ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_CACHE_INIT )
if (exists(".zdata.OS_Default_Init_Task_Core1_VAR_FAST"))
{
  group OS_Default_Init_Task_Core1_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Core1_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_Default_Init_Task_Core1_VAR_FAST";
    }
    reserved ".pad.OS_Default_Init_Task_Core1_VAR_FAST" (size=16);
  }
  "_OS_Default_Init_Task_Core1_VAR_FAST_START" = "_lc_gb_OS_Default_Init_Task_Core1_VAR_FAST_GROUP";
  "_OS_Default_Init_Task_Core1_VAR_FAST_END" = "_lc_ub__pad_OS_Default_Init_Task_Core1_VAR_FAST" - 1;
  "_OS_Default_Init_Task_Core1_VAR_FAST_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Core1_VAR_FAST";
}
else
{
  "_OS_Default_Init_Task_Core1_VAR_FAST_START" = 0;
  "_OS_Default_Init_Task_Core1_VAR_FAST_END" = 0;
  "_OS_Default_Init_Task_Core1_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1 ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_Default_Init_Task_Core1_VAR_FAST_NOINIT"))
{
  group OS_Default_Init_Task_Core1_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Core1_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_Init_Task_Core1_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_Default_Init_Task_Core1_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_Default_Init_Task_Core1_VAR_FAST_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_Core1_VAR_FAST_NOINIT_GROUP";
  "_OS_Default_Init_Task_Core1_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_Default_Init_Task_Core1_VAR_FAST_NOINIT" - 1;
  "_OS_Default_Init_Task_Core1_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Core1_VAR_FAST_NOINIT";
}
else
{
  "_OS_Default_Init_Task_Core1_VAR_FAST_NOINIT_START" = 0;
  "_OS_Default_Init_Task_Core1_VAR_FAST_NOINIT_END" = 0;
  "_OS_Default_Init_Task_Core1_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1 ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_Init_Task_Core1_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_Default_Init_Task_Core1_VAR_FAST_ZERO_INIT"))
{
  group OS_Default_Init_Task_Core1_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Core1_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_Init_Task_Core1_VAR_FAST_ZERO_INIT_bss";
      select "[.]zdata.OS_Default_Init_Task_Core1_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Init_Task_Core1_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_Default_Init_Task_Core1_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_Core1_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_Core1_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Init_Task_Core1_VAR_FAST_ZERO_INIT" - 1;
  "_OS_Default_Init_Task_Core1_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Core1_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_Default_Init_Task_Core1_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_Default_Init_Task_Core1_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_Default_Init_Task_Core1_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1 ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_NOCACHE_INIT )
if (exists(".data.OS_Default_Init_Task_Core1_VAR_NOCACHE"))
{
  group OS_Default_Init_Task_Core1_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Core1_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_Default_Init_Task_Core1_VAR_NOCACHE";
    }
    reserved ".pad.OS_Default_Init_Task_Core1_VAR_NOCACHE" (size=16);
  }
  "_OS_Default_Init_Task_Core1_VAR_NOCACHE_START" = "_lc_gb_OS_Default_Init_Task_Core1_VAR_NOCACHE_GROUP";
  "_OS_Default_Init_Task_Core1_VAR_NOCACHE_END" = "_lc_ub__pad_OS_Default_Init_Task_Core1_VAR_NOCACHE" - 1;
  "_OS_Default_Init_Task_Core1_VAR_NOCACHE_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Core1_VAR_NOCACHE";
}
else
{
  "_OS_Default_Init_Task_Core1_VAR_NOCACHE_START" = 0;
  "_OS_Default_Init_Task_Core1_VAR_NOCACHE_END" = 0;
  "_OS_Default_Init_Task_Core1_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1 ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_Default_Init_Task_Core1_VAR_NOCACHE_NOINIT"))
{
  group OS_Default_Init_Task_Core1_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Core1_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_Init_Task_Core1_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Default_Init_Task_Core1_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Default_Init_Task_Core1_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_Core1_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_Default_Init_Task_Core1_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Default_Init_Task_Core1_VAR_NOCACHE_NOINIT" - 1;
  "_OS_Default_Init_Task_Core1_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Core1_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_Default_Init_Task_Core1_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_Init_Task_Core1_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_Default_Init_Task_Core1_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1 ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_Default_Init_Task_Core1_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_Default_Init_Task_Core1_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_Default_Init_Task_Core1_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Core1_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_Init_Task_Core1_VAR_NOCACHE_ZERO_INIT_bss";
      select "[.]data.OS_Default_Init_Task_Core1_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Init_Task_Core1_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Default_Init_Task_Core1_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_Core1_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_Core1_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Init_Task_Core1_VAR_NOCACHE_ZERO_INIT" - 1;
  "_OS_Default_Init_Task_Core1_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Core1_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Default_Init_Task_Core1_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Default_Init_Task_Core1_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_Default_Init_Task_Core1_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1 ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE"))
{
  group OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_GROUP";
  "_OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE" - 1;
  "_OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE";
}
else
{
  "_OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_START" = 0;
  "_OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_END" = 0;
  "_OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1 ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1 ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select "[.]zdata.OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_ZERO_INIT" - 1;
  "_OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_Default_Init_Task_Core1_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1
} /* OS_Default_Init_Task_Core1_VAR_ALL_GROUP */
"_OS_Default_Init_Task_Core1_VAR_ALL_START" = "_lc_gb_OS_Default_Init_Task_Core1_VAR_ALL_GROUP";
"_OS_Default_Init_Task_Core1_VAR_ALL_END" = "_lc_ge_OS_Default_Init_Task_Core1_VAR_ALL_GROUP" - 1;
"_OS_Default_Init_Task_Core1_VAR_ALL_LIMIT" = "_lc_ge_OS_Default_Init_Task_Core1_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED
group OS_Default_Init_Task_Core1_Trusted_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_CACHE_INIT )
if (exists(".data.OS_Default_Init_Task_Core1_Trusted_VAR"))
{
  group OS_Default_Init_Task_Core1_Trusted_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Core1_Trusted_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_Default_Init_Task_Core1_Trusted_VAR";
    }
    reserved ".pad.OS_Default_Init_Task_Core1_Trusted_VAR" (size=16);
  }
  "_OS_Default_Init_Task_Core1_Trusted_VAR_START" = "_lc_gb_OS_Default_Init_Task_Core1_Trusted_VAR_GROUP";
  "_OS_Default_Init_Task_Core1_Trusted_VAR_END" = "_lc_ub__pad_OS_Default_Init_Task_Core1_Trusted_VAR" - 1;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Core1_Trusted_VAR";
}
else
{
  "_OS_Default_Init_Task_Core1_Trusted_VAR_START" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_END" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_CACHE_NOINIT )
if (exists(".bss.OS_Default_Init_Task_Core1_Trusted_VAR_NOINIT"))
{
  group OS_Default_Init_Task_Core1_Trusted_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Core1_Trusted_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_Init_Task_Core1_Trusted_VAR_NOINIT";
    }
    reserved ".pad.OS_Default_Init_Task_Core1_Trusted_VAR_NOINIT" (size=16);
  }
  "_OS_Default_Init_Task_Core1_Trusted_VAR_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_Core1_Trusted_VAR_NOINIT_GROUP";
  "_OS_Default_Init_Task_Core1_Trusted_VAR_NOINIT_END" = "_lc_ub__pad_OS_Default_Init_Task_Core1_Trusted_VAR_NOINIT" - 1;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Core1_Trusted_VAR_NOINIT";
}
else
{
  "_OS_Default_Init_Task_Core1_Trusted_VAR_NOINIT_START" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_NOINIT_END" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_Default_Init_Task_Core1_Trusted_VAR_ZERO_INIT_bss") || exists(".data.OS_Default_Init_Task_Core1_Trusted_VAR_ZERO_INIT"))
{
  group OS_Default_Init_Task_Core1_Trusted_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Core1_Trusted_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_Init_Task_Core1_Trusted_VAR_ZERO_INIT_bss";
      select "[.]data.OS_Default_Init_Task_Core1_Trusted_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Init_Task_Core1_Trusted_VAR_ZERO_INIT" (size=16);
  }
  "_OS_Default_Init_Task_Core1_Trusted_VAR_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_Core1_Trusted_VAR_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_Core1_Trusted_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Init_Task_Core1_Trusted_VAR_ZERO_INIT" - 1;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Core1_Trusted_VAR_ZERO_INIT";
}
else
{
  "_OS_Default_Init_Task_Core1_Trusted_VAR_ZERO_INIT_START" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_ZERO_INIT_END" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_CACHE_INIT )
if (exists(".zdata.OS_Default_Init_Task_Core1_Trusted_VAR_FAST"))
{
  group OS_Default_Init_Task_Core1_Trusted_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Core1_Trusted_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_Default_Init_Task_Core1_Trusted_VAR_FAST";
    }
    reserved ".pad.OS_Default_Init_Task_Core1_Trusted_VAR_FAST" (size=16);
  }
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_START" = "_lc_gb_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_GROUP";
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_END" = "_lc_ub__pad_OS_Default_Init_Task_Core1_Trusted_VAR_FAST" - 1;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Core1_Trusted_VAR_FAST";
}
else
{
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_START" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_END" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOINIT"))
{
  group OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOINIT_GROUP";
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOINIT" - 1;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOINIT";
}
else
{
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOINIT_START" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOINIT_END" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_Init_Task_Core1_Trusted_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_Default_Init_Task_Core1_Trusted_VAR_FAST_ZERO_INIT"))
{
  group OS_Default_Init_Task_Core1_Trusted_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Core1_Trusted_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_Init_Task_Core1_Trusted_VAR_FAST_ZERO_INIT_bss";
      select "[.]zdata.OS_Default_Init_Task_Core1_Trusted_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Init_Task_Core1_Trusted_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_ZERO_INIT" - 1;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_NOCACHE_INIT )
if (exists(".data.OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE"))
{
  group OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE";
    }
    reserved ".pad.OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE" (size=16);
  }
  "_OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_START" = "_lc_gb_OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_GROUP";
  "_OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_END" = "_lc_ub__pad_OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE" - 1;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE";
}
else
{
  "_OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_START" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_END" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_NOINIT"))
{
  group OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_NOINIT" - 1;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_ZERO_INIT_bss";
      select "[.]data.OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_ZERO_INIT" - 1;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE"))
{
  group OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_GROUP";
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE" - 1;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE";
}
else
{
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_START" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_END" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select "[.]zdata.OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_ZERO_INIT" - 1;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_Default_Init_Task_Core1_Trusted_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED
} /* OS_Default_Init_Task_Core1_Trusted_VAR_ALL_GROUP */
"_OS_Default_Init_Task_Core1_Trusted_VAR_ALL_START" = "_lc_gb_OS_Default_Init_Task_Core1_Trusted_VAR_ALL_GROUP";
"_OS_Default_Init_Task_Core1_Trusted_VAR_ALL_END" = "_lc_ge_OS_Default_Init_Task_Core1_Trusted_VAR_ALL_GROUP" - 1;
"_OS_Default_Init_Task_Core1_Trusted_VAR_ALL_LIMIT" = "_lc_ge_OS_Default_Init_Task_Core1_Trusted_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_CORE1_TRUSTED_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK
group OS_Default_MotorInitTask_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_CACHE_INIT )
if (exists(".data.OS_Default_MotorInitTask_VAR"))
{
  group OS_Default_MotorInitTask_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_MotorInitTask_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_Default_MotorInitTask_VAR";
    }
    reserved ".pad.OS_Default_MotorInitTask_VAR" (size=16);
  }
  "_OS_Default_MotorInitTask_VAR_START" = "_lc_gb_OS_Default_MotorInitTask_VAR_GROUP";
  "_OS_Default_MotorInitTask_VAR_END" = "_lc_ub__pad_OS_Default_MotorInitTask_VAR" - 1;
  "_OS_Default_MotorInitTask_VAR_LIMIT" = "_lc_ub__pad_OS_Default_MotorInitTask_VAR";
}
else
{
  "_OS_Default_MotorInitTask_VAR_START" = 0;
  "_OS_Default_MotorInitTask_VAR_END" = 0;
  "_OS_Default_MotorInitTask_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_CACHE_NOINIT )
if (exists(".bss.OS_Default_MotorInitTask_VAR_NOINIT"))
{
  group OS_Default_MotorInitTask_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_MotorInitTask_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_MotorInitTask_VAR_NOINIT";
    }
    reserved ".pad.OS_Default_MotorInitTask_VAR_NOINIT" (size=16);
  }
  "_OS_Default_MotorInitTask_VAR_NOINIT_START" = "_lc_gb_OS_Default_MotorInitTask_VAR_NOINIT_GROUP";
  "_OS_Default_MotorInitTask_VAR_NOINIT_END" = "_lc_ub__pad_OS_Default_MotorInitTask_VAR_NOINIT" - 1;
  "_OS_Default_MotorInitTask_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_Default_MotorInitTask_VAR_NOINIT";
}
else
{
  "_OS_Default_MotorInitTask_VAR_NOINIT_START" = 0;
  "_OS_Default_MotorInitTask_VAR_NOINIT_END" = 0;
  "_OS_Default_MotorInitTask_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_Default_MotorInitTask_VAR_ZERO_INIT_bss") || exists(".data.OS_Default_MotorInitTask_VAR_ZERO_INIT"))
{
  group OS_Default_MotorInitTask_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_MotorInitTask_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_MotorInitTask_VAR_ZERO_INIT_bss";
      select "[.]data.OS_Default_MotorInitTask_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_Default_MotorInitTask_VAR_ZERO_INIT" (size=16);
  }
  "_OS_Default_MotorInitTask_VAR_ZERO_INIT_START" = "_lc_gb_OS_Default_MotorInitTask_VAR_ZERO_INIT_GROUP";
  "_OS_Default_MotorInitTask_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_MotorInitTask_VAR_ZERO_INIT" - 1;
  "_OS_Default_MotorInitTask_VAR_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_Default_MotorInitTask_VAR_ZERO_INIT";
}
else
{
  "_OS_Default_MotorInitTask_VAR_ZERO_INIT_START" = 0;
  "_OS_Default_MotorInitTask_VAR_ZERO_INIT_END" = 0;
  "_OS_Default_MotorInitTask_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_CACHE_INIT )
if (exists(".zdata.OS_Default_MotorInitTask_VAR_FAST"))
{
  group OS_Default_MotorInitTask_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_MotorInitTask_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_Default_MotorInitTask_VAR_FAST";
    }
    reserved ".pad.OS_Default_MotorInitTask_VAR_FAST" (size=16);
  }
  "_OS_Default_MotorInitTask_VAR_FAST_START" = "_lc_gb_OS_Default_MotorInitTask_VAR_FAST_GROUP";
  "_OS_Default_MotorInitTask_VAR_FAST_END" = "_lc_ub__pad_OS_Default_MotorInitTask_VAR_FAST" - 1;
  "_OS_Default_MotorInitTask_VAR_FAST_LIMIT" = "_lc_ub__pad_OS_Default_MotorInitTask_VAR_FAST";
}
else
{
  "_OS_Default_MotorInitTask_VAR_FAST_START" = 0;
  "_OS_Default_MotorInitTask_VAR_FAST_END" = 0;
  "_OS_Default_MotorInitTask_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_Default_MotorInitTask_VAR_FAST_NOINIT"))
{
  group OS_Default_MotorInitTask_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_MotorInitTask_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_MotorInitTask_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_Default_MotorInitTask_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_Default_MotorInitTask_VAR_FAST_NOINIT_START" = "_lc_gb_OS_Default_MotorInitTask_VAR_FAST_NOINIT_GROUP";
  "_OS_Default_MotorInitTask_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_Default_MotorInitTask_VAR_FAST_NOINIT" - 1;
  "_OS_Default_MotorInitTask_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_Default_MotorInitTask_VAR_FAST_NOINIT";
}
else
{
  "_OS_Default_MotorInitTask_VAR_FAST_NOINIT_START" = 0;
  "_OS_Default_MotorInitTask_VAR_FAST_NOINIT_END" = 0;
  "_OS_Default_MotorInitTask_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_MotorInitTask_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_Default_MotorInitTask_VAR_FAST_ZERO_INIT"))
{
  group OS_Default_MotorInitTask_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_MotorInitTask_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_MotorInitTask_VAR_FAST_ZERO_INIT_bss";
      select "[.]zdata.OS_Default_MotorInitTask_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_Default_MotorInitTask_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_Default_MotorInitTask_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_Default_MotorInitTask_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_Default_MotorInitTask_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_MotorInitTask_VAR_FAST_ZERO_INIT" - 1;
  "_OS_Default_MotorInitTask_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_Default_MotorInitTask_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_Default_MotorInitTask_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_Default_MotorInitTask_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_Default_MotorInitTask_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_NOCACHE_INIT )
if (exists(".data.OS_Default_MotorInitTask_VAR_NOCACHE"))
{
  group OS_Default_MotorInitTask_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_MotorInitTask_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_Default_MotorInitTask_VAR_NOCACHE";
    }
    reserved ".pad.OS_Default_MotorInitTask_VAR_NOCACHE" (size=16);
  }
  "_OS_Default_MotorInitTask_VAR_NOCACHE_START" = "_lc_gb_OS_Default_MotorInitTask_VAR_NOCACHE_GROUP";
  "_OS_Default_MotorInitTask_VAR_NOCACHE_END" = "_lc_ub__pad_OS_Default_MotorInitTask_VAR_NOCACHE" - 1;
  "_OS_Default_MotorInitTask_VAR_NOCACHE_LIMIT" = "_lc_ub__pad_OS_Default_MotorInitTask_VAR_NOCACHE";
}
else
{
  "_OS_Default_MotorInitTask_VAR_NOCACHE_START" = 0;
  "_OS_Default_MotorInitTask_VAR_NOCACHE_END" = 0;
  "_OS_Default_MotorInitTask_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_Default_MotorInitTask_VAR_NOCACHE_NOINIT"))
{
  group OS_Default_MotorInitTask_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_MotorInitTask_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_MotorInitTask_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Default_MotorInitTask_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Default_MotorInitTask_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_MotorInitTask_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_Default_MotorInitTask_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Default_MotorInitTask_VAR_NOCACHE_NOINIT" - 1;
  "_OS_Default_MotorInitTask_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_Default_MotorInitTask_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_Default_MotorInitTask_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_MotorInitTask_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_Default_MotorInitTask_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_Default_MotorInitTask_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_Default_MotorInitTask_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_Default_MotorInitTask_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_MotorInitTask_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_Default_MotorInitTask_VAR_NOCACHE_ZERO_INIT_bss";
      select "[.]data.OS_Default_MotorInitTask_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Default_MotorInitTask_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Default_MotorInitTask_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_MotorInitTask_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_MotorInitTask_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_MotorInitTask_VAR_NOCACHE_ZERO_INIT" - 1;
  "_OS_Default_MotorInitTask_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_Default_MotorInitTask_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Default_MotorInitTask_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Default_MotorInitTask_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_Default_MotorInitTask_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_Default_MotorInitTask_VAR_FAST_NOCACHE"))
{
  group OS_Default_MotorInitTask_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_MotorInitTask_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_Default_MotorInitTask_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_Default_MotorInitTask_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_Default_MotorInitTask_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_Default_MotorInitTask_VAR_FAST_NOCACHE_GROUP";
  "_OS_Default_MotorInitTask_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_Default_MotorInitTask_VAR_FAST_NOCACHE" - 1;
  "_OS_Default_MotorInitTask_VAR_FAST_NOCACHE_LIMIT" = "_lc_ub__pad_OS_Default_MotorInitTask_VAR_FAST_NOCACHE";
}
else
{
  "_OS_Default_MotorInitTask_VAR_FAST_NOCACHE_START" = 0;
  "_OS_Default_MotorInitTask_VAR_FAST_NOCACHE_END" = 0;
  "_OS_Default_MotorInitTask_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_Default_MotorInitTask_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_Default_MotorInitTask_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_MotorInitTask_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_MotorInitTask_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Default_MotorInitTask_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Default_MotorInitTask_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_Default_MotorInitTask_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_Default_MotorInitTask_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Default_MotorInitTask_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_Default_MotorInitTask_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_Default_MotorInitTask_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_Default_MotorInitTask_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_Default_MotorInitTask_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_Default_MotorInitTask_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_Default_MotorInitTask_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_Default_MotorInitTask_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_Default_MotorInitTask_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Default_MotorInitTask_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_Default_MotorInitTask_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select "[.]zdata.OS_Default_MotorInitTask_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Default_MotorInitTask_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Default_MotorInitTask_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Default_MotorInitTask_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Default_MotorInitTask_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Default_MotorInitTask_VAR_FAST_NOCACHE_ZERO_INIT" - 1;
  "_OS_Default_MotorInitTask_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_Default_MotorInitTask_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Default_MotorInitTask_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Default_MotorInitTask_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_Default_MotorInitTask_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK
} /* OS_Default_MotorInitTask_VAR_ALL_GROUP */
"_OS_Default_MotorInitTask_VAR_ALL_START" = "_lc_gb_OS_Default_MotorInitTask_VAR_ALL_GROUP";
"_OS_Default_MotorInitTask_VAR_ALL_END" = "_lc_ge_OS_Default_MotorInitTask_VAR_ALL_GROUP" - 1;
"_OS_Default_MotorInitTask_VAR_ALL_LIMIT" = "_lc_ge_OS_Default_MotorInitTask_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR
# undef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR
# undef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_MOTORINITTASK_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1
group OS_IdleTask_OsCore_1_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_CACHE_INIT )
if (exists(".data.OS_IdleTask_OsCore_1_VAR"))
{
  group OS_IdleTask_OsCore_1_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore_1_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_IdleTask_OsCore_1_VAR";
    }
    reserved ".pad.OS_IdleTask_OsCore_1_VAR" (size=16);
  }
  "_OS_IdleTask_OsCore_1_VAR_START" = "_lc_gb_OS_IdleTask_OsCore_1_VAR_GROUP";
  "_OS_IdleTask_OsCore_1_VAR_END" = "_lc_ub__pad_OS_IdleTask_OsCore_1_VAR" - 1;
  "_OS_IdleTask_OsCore_1_VAR_LIMIT" = "_lc_ub__pad_OS_IdleTask_OsCore_1_VAR";
}
else
{
  "_OS_IdleTask_OsCore_1_VAR_START" = 0;
  "_OS_IdleTask_OsCore_1_VAR_END" = 0;
  "_OS_IdleTask_OsCore_1_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_CACHE_NOINIT )
if (exists(".bss.OS_IdleTask_OsCore_1_VAR_NOINIT"))
{
  group OS_IdleTask_OsCore_1_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore_1_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_IdleTask_OsCore_1_VAR_NOINIT";
    }
    reserved ".pad.OS_IdleTask_OsCore_1_VAR_NOINIT" (size=16);
  }
  "_OS_IdleTask_OsCore_1_VAR_NOINIT_START" = "_lc_gb_OS_IdleTask_OsCore_1_VAR_NOINIT_GROUP";
  "_OS_IdleTask_OsCore_1_VAR_NOINIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore_1_VAR_NOINIT" - 1;
  "_OS_IdleTask_OsCore_1_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_IdleTask_OsCore_1_VAR_NOINIT";
}
else
{
  "_OS_IdleTask_OsCore_1_VAR_NOINIT_START" = 0;
  "_OS_IdleTask_OsCore_1_VAR_NOINIT_END" = 0;
  "_OS_IdleTask_OsCore_1_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_IdleTask_OsCore_1_VAR_ZERO_INIT_bss") || exists(".data.OS_IdleTask_OsCore_1_VAR_ZERO_INIT"))
{
  group OS_IdleTask_OsCore_1_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore_1_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_IdleTask_OsCore_1_VAR_ZERO_INIT_bss";
      select "[.]data.OS_IdleTask_OsCore_1_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_IdleTask_OsCore_1_VAR_ZERO_INIT" (size=16);
  }
  "_OS_IdleTask_OsCore_1_VAR_ZERO_INIT_START" = "_lc_gb_OS_IdleTask_OsCore_1_VAR_ZERO_INIT_GROUP";
  "_OS_IdleTask_OsCore_1_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore_1_VAR_ZERO_INIT" - 1;
  "_OS_IdleTask_OsCore_1_VAR_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_IdleTask_OsCore_1_VAR_ZERO_INIT";
}
else
{
  "_OS_IdleTask_OsCore_1_VAR_ZERO_INIT_START" = 0;
  "_OS_IdleTask_OsCore_1_VAR_ZERO_INIT_END" = 0;
  "_OS_IdleTask_OsCore_1_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_CACHE_INIT )
if (exists(".zdata.OS_IdleTask_OsCore_1_VAR_FAST"))
{
  group OS_IdleTask_OsCore_1_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore_1_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_IdleTask_OsCore_1_VAR_FAST";
    }
    reserved ".pad.OS_IdleTask_OsCore_1_VAR_FAST" (size=16);
  }
  "_OS_IdleTask_OsCore_1_VAR_FAST_START" = "_lc_gb_OS_IdleTask_OsCore_1_VAR_FAST_GROUP";
  "_OS_IdleTask_OsCore_1_VAR_FAST_END" = "_lc_ub__pad_OS_IdleTask_OsCore_1_VAR_FAST" - 1;
  "_OS_IdleTask_OsCore_1_VAR_FAST_LIMIT" = "_lc_ub__pad_OS_IdleTask_OsCore_1_VAR_FAST";
}
else
{
  "_OS_IdleTask_OsCore_1_VAR_FAST_START" = 0;
  "_OS_IdleTask_OsCore_1_VAR_FAST_END" = 0;
  "_OS_IdleTask_OsCore_1_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_IdleTask_OsCore_1_VAR_FAST_NOINIT"))
{
  group OS_IdleTask_OsCore_1_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore_1_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_IdleTask_OsCore_1_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_IdleTask_OsCore_1_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_IdleTask_OsCore_1_VAR_FAST_NOINIT_START" = "_lc_gb_OS_IdleTask_OsCore_1_VAR_FAST_NOINIT_GROUP";
  "_OS_IdleTask_OsCore_1_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore_1_VAR_FAST_NOINIT" - 1;
  "_OS_IdleTask_OsCore_1_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_IdleTask_OsCore_1_VAR_FAST_NOINIT";
}
else
{
  "_OS_IdleTask_OsCore_1_VAR_FAST_NOINIT_START" = 0;
  "_OS_IdleTask_OsCore_1_VAR_FAST_NOINIT_END" = 0;
  "_OS_IdleTask_OsCore_1_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_IdleTask_OsCore_1_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_IdleTask_OsCore_1_VAR_FAST_ZERO_INIT"))
{
  group OS_IdleTask_OsCore_1_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore_1_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_IdleTask_OsCore_1_VAR_FAST_ZERO_INIT_bss";
      select "[.]zdata.OS_IdleTask_OsCore_1_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_IdleTask_OsCore_1_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_IdleTask_OsCore_1_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_IdleTask_OsCore_1_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_IdleTask_OsCore_1_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore_1_VAR_FAST_ZERO_INIT" - 1;
  "_OS_IdleTask_OsCore_1_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_IdleTask_OsCore_1_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_IdleTask_OsCore_1_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_IdleTask_OsCore_1_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_IdleTask_OsCore_1_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_NOCACHE_INIT )
if (exists(".data.OS_IdleTask_OsCore_1_VAR_NOCACHE"))
{
  group OS_IdleTask_OsCore_1_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore_1_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_IdleTask_OsCore_1_VAR_NOCACHE";
    }
    reserved ".pad.OS_IdleTask_OsCore_1_VAR_NOCACHE" (size=16);
  }
  "_OS_IdleTask_OsCore_1_VAR_NOCACHE_START" = "_lc_gb_OS_IdleTask_OsCore_1_VAR_NOCACHE_GROUP";
  "_OS_IdleTask_OsCore_1_VAR_NOCACHE_END" = "_lc_ub__pad_OS_IdleTask_OsCore_1_VAR_NOCACHE" - 1;
  "_OS_IdleTask_OsCore_1_VAR_NOCACHE_LIMIT" = "_lc_ub__pad_OS_IdleTask_OsCore_1_VAR_NOCACHE";
}
else
{
  "_OS_IdleTask_OsCore_1_VAR_NOCACHE_START" = 0;
  "_OS_IdleTask_OsCore_1_VAR_NOCACHE_END" = 0;
  "_OS_IdleTask_OsCore_1_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_IdleTask_OsCore_1_VAR_NOCACHE_NOINIT"))
{
  group OS_IdleTask_OsCore_1_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore_1_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_IdleTask_OsCore_1_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_IdleTask_OsCore_1_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_IdleTask_OsCore_1_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_IdleTask_OsCore_1_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_IdleTask_OsCore_1_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore_1_VAR_NOCACHE_NOINIT" - 1;
  "_OS_IdleTask_OsCore_1_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_IdleTask_OsCore_1_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_IdleTask_OsCore_1_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_IdleTask_OsCore_1_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_IdleTask_OsCore_1_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_IdleTask_OsCore_1_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_IdleTask_OsCore_1_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_IdleTask_OsCore_1_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore_1_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_IdleTask_OsCore_1_VAR_NOCACHE_ZERO_INIT_bss";
      select "[.]data.OS_IdleTask_OsCore_1_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_IdleTask_OsCore_1_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_IdleTask_OsCore_1_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_IdleTask_OsCore_1_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_IdleTask_OsCore_1_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore_1_VAR_NOCACHE_ZERO_INIT" - 1;
  "_OS_IdleTask_OsCore_1_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_IdleTask_OsCore_1_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_IdleTask_OsCore_1_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_IdleTask_OsCore_1_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_IdleTask_OsCore_1_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE"))
{
  group OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_GROUP";
  "_OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE" - 1;
  "_OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_LIMIT" = "_lc_ub__pad_OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE";
}
else
{
  "_OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_START" = 0;
  "_OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_END" = 0;
  "_OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select "[.]zdata.OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_ZERO_INIT" - 1;
  "_OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_IdleTask_OsCore_1_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1
} /* OS_IdleTask_OsCore_1_VAR_ALL_GROUP */
"_OS_IdleTask_OsCore_1_VAR_ALL_START" = "_lc_gb_OS_IdleTask_OsCore_1_VAR_ALL_GROUP";
"_OS_IdleTask_OsCore_1_VAR_ALL_END" = "_lc_ge_OS_IdleTask_OsCore_1_VAR_ALL_GROUP" - 1;
"_OS_IdleTask_OsCore_1_VAR_ALL_LIMIT" = "_lc_ge_OS_IdleTask_OsCore_1_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_CACHE
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_CACHE
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE_1_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_MOTORTASK
group OS_MotorTask_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_MOTORTASK ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_FAR ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_FAR_CACHE_INIT )
if (exists(".data.OS_MotorTask_VAR"))
{
  group OS_MotorTask_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_MotorTask_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_MotorTask_VAR";
    }
    reserved ".pad.OS_MotorTask_VAR" (size=16);
  }
  "_OS_MotorTask_VAR_START" = "_lc_gb_OS_MotorTask_VAR_GROUP";
  "_OS_MotorTask_VAR_END" = "_lc_ub__pad_OS_MotorTask_VAR" - 1;
  "_OS_MotorTask_VAR_LIMIT" = "_lc_ub__pad_OS_MotorTask_VAR";
}
else
{
  "_OS_MotorTask_VAR_START" = 0;
  "_OS_MotorTask_VAR_END" = 0;
  "_OS_MotorTask_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_MOTORTASK ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_FAR ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_FAR_CACHE_NOINIT )
if (exists(".bss.OS_MotorTask_VAR_NOINIT"))
{
  group OS_MotorTask_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_MotorTask_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_MotorTask_VAR_NOINIT";
    }
    reserved ".pad.OS_MotorTask_VAR_NOINIT" (size=16);
  }
  "_OS_MotorTask_VAR_NOINIT_START" = "_lc_gb_OS_MotorTask_VAR_NOINIT_GROUP";
  "_OS_MotorTask_VAR_NOINIT_END" = "_lc_ub__pad_OS_MotorTask_VAR_NOINIT" - 1;
  "_OS_MotorTask_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_MotorTask_VAR_NOINIT";
}
else
{
  "_OS_MotorTask_VAR_NOINIT_START" = 0;
  "_OS_MotorTask_VAR_NOINIT_END" = 0;
  "_OS_MotorTask_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_MOTORTASK ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_FAR ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_MotorTask_VAR_ZERO_INIT_bss") || exists(".data.OS_MotorTask_VAR_ZERO_INIT"))
{
  group OS_MotorTask_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_MotorTask_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_MotorTask_VAR_ZERO_INIT_bss";
      select "[.]data.OS_MotorTask_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_MotorTask_VAR_ZERO_INIT" (size=16);
  }
  "_OS_MotorTask_VAR_ZERO_INIT_START" = "_lc_gb_OS_MotorTask_VAR_ZERO_INIT_GROUP";
  "_OS_MotorTask_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_MotorTask_VAR_ZERO_INIT" - 1;
  "_OS_MotorTask_VAR_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_MotorTask_VAR_ZERO_INIT";
}
else
{
  "_OS_MotorTask_VAR_ZERO_INIT_START" = 0;
  "_OS_MotorTask_VAR_ZERO_INIT_END" = 0;
  "_OS_MotorTask_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_MOTORTASK ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_NEAR_CACHE_INIT )
if (exists(".zdata.OS_MotorTask_VAR_FAST"))
{
  group OS_MotorTask_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_MotorTask_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_MotorTask_VAR_FAST";
    }
    reserved ".pad.OS_MotorTask_VAR_FAST" (size=16);
  }
  "_OS_MotorTask_VAR_FAST_START" = "_lc_gb_OS_MotorTask_VAR_FAST_GROUP";
  "_OS_MotorTask_VAR_FAST_END" = "_lc_ub__pad_OS_MotorTask_VAR_FAST" - 1;
  "_OS_MotorTask_VAR_FAST_LIMIT" = "_lc_ub__pad_OS_MotorTask_VAR_FAST";
}
else
{
  "_OS_MotorTask_VAR_FAST_START" = 0;
  "_OS_MotorTask_VAR_FAST_END" = 0;
  "_OS_MotorTask_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_MOTORTASK ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_MotorTask_VAR_FAST_NOINIT"))
{
  group OS_MotorTask_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_MotorTask_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_MotorTask_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_MotorTask_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_MotorTask_VAR_FAST_NOINIT_START" = "_lc_gb_OS_MotorTask_VAR_FAST_NOINIT_GROUP";
  "_OS_MotorTask_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_MotorTask_VAR_FAST_NOINIT" - 1;
  "_OS_MotorTask_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_MotorTask_VAR_FAST_NOINIT";
}
else
{
  "_OS_MotorTask_VAR_FAST_NOINIT_START" = 0;
  "_OS_MotorTask_VAR_FAST_NOINIT_END" = 0;
  "_OS_MotorTask_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_MOTORTASK ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_MotorTask_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_MotorTask_VAR_FAST_ZERO_INIT"))
{
  group OS_MotorTask_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_MotorTask_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_MotorTask_VAR_FAST_ZERO_INIT_bss";
      select "[.]zdata.OS_MotorTask_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_MotorTask_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_MotorTask_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_MotorTask_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_MotorTask_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_MotorTask_VAR_FAST_ZERO_INIT" - 1;
  "_OS_MotorTask_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_MotorTask_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_MotorTask_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_MotorTask_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_MotorTask_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_MOTORTASK ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_FAR ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_FAR_NOCACHE_INIT )
if (exists(".data.OS_MotorTask_VAR_NOCACHE"))
{
  group OS_MotorTask_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_MotorTask_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_MotorTask_VAR_NOCACHE";
    }
    reserved ".pad.OS_MotorTask_VAR_NOCACHE" (size=16);
  }
  "_OS_MotorTask_VAR_NOCACHE_START" = "_lc_gb_OS_MotorTask_VAR_NOCACHE_GROUP";
  "_OS_MotorTask_VAR_NOCACHE_END" = "_lc_ub__pad_OS_MotorTask_VAR_NOCACHE" - 1;
  "_OS_MotorTask_VAR_NOCACHE_LIMIT" = "_lc_ub__pad_OS_MotorTask_VAR_NOCACHE";
}
else
{
  "_OS_MotorTask_VAR_NOCACHE_START" = 0;
  "_OS_MotorTask_VAR_NOCACHE_END" = 0;
  "_OS_MotorTask_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_MOTORTASK ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_FAR ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_MotorTask_VAR_NOCACHE_NOINIT"))
{
  group OS_MotorTask_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_MotorTask_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_MotorTask_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_MotorTask_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_MotorTask_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_MotorTask_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_MotorTask_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_MotorTask_VAR_NOCACHE_NOINIT" - 1;
  "_OS_MotorTask_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_MotorTask_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_MotorTask_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_MotorTask_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_MotorTask_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_MOTORTASK ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_FAR ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_MotorTask_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_MotorTask_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_MotorTask_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_MotorTask_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_MotorTask_VAR_NOCACHE_ZERO_INIT_bss";
      select "[.]data.OS_MotorTask_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_MotorTask_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_MotorTask_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_MotorTask_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_MotorTask_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_MotorTask_VAR_NOCACHE_ZERO_INIT" - 1;
  "_OS_MotorTask_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_MotorTask_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_MotorTask_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_MotorTask_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_MotorTask_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_MOTORTASK ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_MotorTask_VAR_FAST_NOCACHE"))
{
  group OS_MotorTask_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_MotorTask_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_MotorTask_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_MotorTask_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_MotorTask_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_MotorTask_VAR_FAST_NOCACHE_GROUP";
  "_OS_MotorTask_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_MotorTask_VAR_FAST_NOCACHE" - 1;
  "_OS_MotorTask_VAR_FAST_NOCACHE_LIMIT" = "_lc_ub__pad_OS_MotorTask_VAR_FAST_NOCACHE";
}
else
{
  "_OS_MotorTask_VAR_FAST_NOCACHE_START" = 0;
  "_OS_MotorTask_VAR_FAST_NOCACHE_END" = 0;
  "_OS_MotorTask_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_MOTORTASK ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_MotorTask_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_MotorTask_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_MotorTask_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_MotorTask_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_MotorTask_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_MotorTask_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_MotorTask_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_MotorTask_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_MotorTask_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_MotorTask_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_MotorTask_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_MotorTask_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_MotorTask_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_MotorTask_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_MOTORTASK ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_MOTORTASK_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_MotorTask_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_MotorTask_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_MotorTask_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_MotorTask_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_MotorTask_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select "[.]zdata.OS_MotorTask_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_MotorTask_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_MotorTask_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_MotorTask_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_MotorTask_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_MotorTask_VAR_FAST_NOCACHE_ZERO_INIT" - 1;
  "_OS_MotorTask_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_MotorTask_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_MotorTask_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_MotorTask_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_MotorTask_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_MOTORTASK
} /* OS_MotorTask_VAR_ALL_GROUP */
"_OS_MotorTask_VAR_ALL_START" = "_lc_gb_OS_MotorTask_VAR_ALL_GROUP";
"_OS_MotorTask_VAR_ALL_END" = "_lc_ge_OS_MotorTask_VAR_ALL_GROUP" - 1;
"_OS_MotorTask_VAR_ALL_LIMIT" = "_lc_ge_OS_MotorTask_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_MOTORTASK
#endif

#ifdef OS_LINK_VAR_TASK_MOTORTASK_FAR
# undef OS_LINK_VAR_TASK_MOTORTASK_FAR
#endif

#ifdef OS_LINK_VAR_TASK_MOTORTASK_FAR_CACHE
# undef OS_LINK_VAR_TASK_MOTORTASK_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_MOTORTASK_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_MOTORTASK_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_MOTORTASK_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_MOTORTASK_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_MOTORTASK_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_MOTORTASK_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_MOTORTASK_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_MOTORTASK_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_MOTORTASK_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_MOTORTASK_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_MOTORTASK_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_MOTORTASK_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_MOTORTASK_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_MOTORTASK_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_MOTORTASK_NEAR
# undef OS_LINK_VAR_TASK_MOTORTASK_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_MOTORTASK_NEAR_CACHE
# undef OS_LINK_VAR_TASK_MOTORTASK_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_MOTORTASK_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_MOTORTASK_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_MOTORTASK_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_MOTORTASK_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_MOTORTASK_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_MOTORTASK_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_MOTORTASK_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_MOTORTASK_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_MOTORTASK_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_MOTORTASK_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_MOTORTASK_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_MOTORTASK_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_MOTORTASK_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_MOTORTASK_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1
group OS_CounterIsr_SystemTimer1_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_CACHE_INIT )
if (exists(".data.OS_CounterIsr_SystemTimer1_VAR"))
{
  group OS_CounterIsr_SystemTimer1_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer1_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_CounterIsr_SystemTimer1_VAR";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer1_VAR" (size=16);
  }
  "_OS_CounterIsr_SystemTimer1_VAR_START" = "_lc_gb_OS_CounterIsr_SystemTimer1_VAR_GROUP";
  "_OS_CounterIsr_SystemTimer1_VAR_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer1_VAR" - 1;
  "_OS_CounterIsr_SystemTimer1_VAR_LIMIT" = "_lc_ub__pad_OS_CounterIsr_SystemTimer1_VAR";
}
else
{
  "_OS_CounterIsr_SystemTimer1_VAR_START" = 0;
  "_OS_CounterIsr_SystemTimer1_VAR_END" = 0;
  "_OS_CounterIsr_SystemTimer1_VAR_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_CACHE_NOINIT )
if (exists(".bss.OS_CounterIsr_SystemTimer1_VAR_NOINIT"))
{
  group OS_CounterIsr_SystemTimer1_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer1_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CounterIsr_SystemTimer1_VAR_NOINIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer1_VAR_NOINIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer1_VAR_NOINIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer1_VAR_NOINIT_GROUP";
  "_OS_CounterIsr_SystemTimer1_VAR_NOINIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer1_VAR_NOINIT" - 1;
  "_OS_CounterIsr_SystemTimer1_VAR_NOINIT_LIMIT" = "_lc_ub__pad_OS_CounterIsr_SystemTimer1_VAR_NOINIT";
}
else
{
  "_OS_CounterIsr_SystemTimer1_VAR_NOINIT_START" = 0;
  "_OS_CounterIsr_SystemTimer1_VAR_NOINIT_END" = 0;
  "_OS_CounterIsr_SystemTimer1_VAR_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_CounterIsr_SystemTimer1_VAR_ZERO_INIT_bss") || exists(".data.OS_CounterIsr_SystemTimer1_VAR_ZERO_INIT"))
{
  group OS_CounterIsr_SystemTimer1_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer1_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CounterIsr_SystemTimer1_VAR_ZERO_INIT_bss";
      select "[.]data.OS_CounterIsr_SystemTimer1_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer1_VAR_ZERO_INIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer1_VAR_ZERO_INIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer1_VAR_ZERO_INIT_GROUP";
  "_OS_CounterIsr_SystemTimer1_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer1_VAR_ZERO_INIT" - 1;
  "_OS_CounterIsr_SystemTimer1_VAR_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_CounterIsr_SystemTimer1_VAR_ZERO_INIT";
}
else
{
  "_OS_CounterIsr_SystemTimer1_VAR_ZERO_INIT_START" = 0;
  "_OS_CounterIsr_SystemTimer1_VAR_ZERO_INIT_END" = 0;
  "_OS_CounterIsr_SystemTimer1_VAR_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_CACHE_INIT )
if (exists(".zdata.OS_CounterIsr_SystemTimer1_VAR_FAST"))
{
  group OS_CounterIsr_SystemTimer1_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer1_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_CounterIsr_SystemTimer1_VAR_FAST";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer1_VAR_FAST" (size=16);
  }
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_START" = "_lc_gb_OS_CounterIsr_SystemTimer1_VAR_FAST_GROUP";
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer1_VAR_FAST" - 1;
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_LIMIT" = "_lc_ub__pad_OS_CounterIsr_SystemTimer1_VAR_FAST";
}
else
{
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_START" = 0;
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_END" = 0;
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_CounterIsr_SystemTimer1_VAR_FAST_NOINIT"))
{
  group OS_CounterIsr_SystemTimer1_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer1_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_CounterIsr_SystemTimer1_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer1_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_NOINIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer1_VAR_FAST_NOINIT_GROUP";
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer1_VAR_FAST_NOINIT" - 1;
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_NOINIT_LIMIT" = "_lc_ub__pad_OS_CounterIsr_SystemTimer1_VAR_FAST_NOINIT";
}
else
{
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_NOINIT_START" = 0;
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_NOINIT_END" = 0;
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_CounterIsr_SystemTimer1_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_CounterIsr_SystemTimer1_VAR_FAST_ZERO_INIT"))
{
  group OS_CounterIsr_SystemTimer1_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer1_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_CounterIsr_SystemTimer1_VAR_FAST_ZERO_INIT_bss";
      select "[.]zdata.OS_CounterIsr_SystemTimer1_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer1_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer1_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer1_VAR_FAST_ZERO_INIT" - 1;
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_CounterIsr_SystemTimer1_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_ZERO_INIT_END" = 0;
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_NOCACHE_INIT )
if (exists(".data.OS_CounterIsr_SystemTimer1_VAR_NOCACHE"))
{
  group OS_CounterIsr_SystemTimer1_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer1_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]data.OS_CounterIsr_SystemTimer1_VAR_NOCACHE";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer1_VAR_NOCACHE" (size=16);
  }
  "_OS_CounterIsr_SystemTimer1_VAR_NOCACHE_START" = "_lc_gb_OS_CounterIsr_SystemTimer1_VAR_NOCACHE_GROUP";
  "_OS_CounterIsr_SystemTimer1_VAR_NOCACHE_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer1_VAR_NOCACHE" - 1;
  "_OS_CounterIsr_SystemTimer1_VAR_NOCACHE_LIMIT" = "_lc_ub__pad_OS_CounterIsr_SystemTimer1_VAR_NOCACHE";
}
else
{
  "_OS_CounterIsr_SystemTimer1_VAR_NOCACHE_START" = 0;
  "_OS_CounterIsr_SystemTimer1_VAR_NOCACHE_END" = 0;
  "_OS_CounterIsr_SystemTimer1_VAR_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_CounterIsr_SystemTimer1_VAR_NOCACHE_NOINIT"))
{
  group OS_CounterIsr_SystemTimer1_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer1_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CounterIsr_SystemTimer1_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer1_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer1_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer1_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_CounterIsr_SystemTimer1_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer1_VAR_NOCACHE_NOINIT" - 1;
  "_OS_CounterIsr_SystemTimer1_VAR_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_CounterIsr_SystemTimer1_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_CounterIsr_SystemTimer1_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_CounterIsr_SystemTimer1_VAR_NOCACHE_NOINIT_END" = 0;
  "_OS_CounterIsr_SystemTimer1_VAR_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_CounterIsr_SystemTimer1_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_CounterIsr_SystemTimer1_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_CounterIsr_SystemTimer1_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer1_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]bss.OS_CounterIsr_SystemTimer1_VAR_NOCACHE_ZERO_INIT_bss";
      select "[.]data.OS_CounterIsr_SystemTimer1_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer1_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer1_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer1_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_CounterIsr_SystemTimer1_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer1_VAR_NOCACHE_ZERO_INIT" - 1;
  "_OS_CounterIsr_SystemTimer1_VAR_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_CounterIsr_SystemTimer1_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_CounterIsr_SystemTimer1_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_CounterIsr_SystemTimer1_VAR_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_CounterIsr_SystemTimer1_VAR_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE"))
{
  group OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zdata.OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_GROUP";
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE" - 1;
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_LIMIT" = "_lc_ub__pad_OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE";
}
else
{
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_START" = 0;
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_END" = 0;
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_NOINIT" - 1;
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_NOINIT_LIMIT" = "_lc_ub__pad_OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_NOINIT_END" = 0;
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_NOINIT_LIMIT" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select "[.]zbss.OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select "[.]zdata.OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_ZERO_INIT" - 1;
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = "_lc_ub__pad_OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
  "_OS_CounterIsr_SystemTimer1_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1
} /* OS_CounterIsr_SystemTimer1_VAR_ALL_GROUP */
"_OS_CounterIsr_SystemTimer1_VAR_ALL_START" = "_lc_gb_OS_CounterIsr_SystemTimer1_VAR_ALL_GROUP";
"_OS_CounterIsr_SystemTimer1_VAR_ALL_END" = "_lc_ge_OS_CounterIsr_SystemTimer1_VAR_ALL_GROUP" - 1;
"_OS_CounterIsr_SystemTimer1_VAR_ALL_LIMIT" = "_lc_ge_OS_CounterIsr_SystemTimer1_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_CACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_CACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER1_NEAR_NOCACHE_ZERO_INIT
#endif


#ifdef OS_LINK_VAR
# undef OS_LINK_VAR
#endif

#ifdef OS_LINK_VAR_APP
# undef OS_LINK_VAR_APP
#endif

#ifdef OS_LINK_VAR_TASK
# undef OS_LINK_VAR_TASK
#endif

#ifdef OS_LINK_VAR_ISR
# undef OS_LINK_VAR_ISR
#endif

#ifdef OS_LINK_KERNEL_TRACE
# undef OS_LINK_KERNEL_TRACE
#endif

#ifdef OS_LINK_KERNEL_TRACE_FAR
# undef OS_LINK_KERNEL_TRACE_FAR
#endif

#ifdef OS_LINK_KERNEL_TRACE_NEAR
# undef OS_LINK_KERNEL_TRACE_NEAR
#endif

#ifdef OS_LINK_KERNEL_BARRIERS
# undef OS_LINK_KERNEL_BARRIERS
#endif

#ifdef OS_LINK_KERNEL_BARRIERS_FAR
# undef OS_LINK_KERNEL_BARRIERS_FAR
#endif

#ifdef OS_LINK_KERNEL_BARRIERS_NEAR
# undef OS_LINK_KERNEL_BARRIERS_NEAR
#endif

#ifdef OS_LINK_KERNEL_CORESTATUS
# undef OS_LINK_KERNEL_CORESTATUS
#endif

#ifdef OS_LINK_KERNEL_CORESTATUS_FAR
# undef OS_LINK_KERNEL_CORESTATUS_FAR
#endif

#ifdef OS_LINK_KERNEL_CORESTATUS_NEAR
# undef OS_LINK_KERNEL_CORESTATUS_NEAR
#endif

#ifdef OS_LINK_VAR_KERNEL
# undef OS_LINK_VAR_KERNEL
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR
# undef OS_LINK_VAR_KERNEL_FAR
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_CACHE
# undef OS_LINK_VAR_KERNEL_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_NOCACHE
# undef OS_LINK_VAR_KERNEL_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_KERNEL_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR
# undef OS_LINK_VAR_KERNEL_NEAR
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_NOCACHE
# undef OS_LINK_VAR_KERNEL_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
#endif


