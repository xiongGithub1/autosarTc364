/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte.c
 *           Config:  last364.dpa
 *      ECU-Project:  last364
 *
 *        Generator:  MICROSAR RTE Generator Version 4.29.0
 *                    RTE Core Version 1.29.0
 *          License:  CBD2200508
 *
 *      Description:  RTE implementation file
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0857 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define RTE_CORE
#include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_Dir1.1, MD_Rte_Os */
#include "Rte_Type.h"
#include "Rte_Main.h"

#include "Rte_BswM.h"
#include "Rte_ComM.h"
#include "Rte_Det.h"
#include "Rte_EcuM.h"
#include "Rte_MotorCdd.h"
#include "Rte_MotorControll.h"
#include "Rte_NvM.h"
#include "Rte_Os_OsCore0_swc.h"
#include "Rte_Os_OsCore1_swc.h"
#include "Rte_StartApp.h"
#include "SchM_Adc.h"
#include "SchM_BswM.h"
#include "SchM_Can.h"
#include "SchM_CanIf.h"
#include "SchM_CanSM.h"
#include "SchM_Com.h"
#include "SchM_ComM.h"
#include "SchM_ComXf.h"
#include "SchM_Crc.h"
#include "SchM_Det.h"
#include "SchM_Dio.h"
#include "SchM_Dma.h"
#include "SchM_E2EXf.h"
#include "SchM_EcuM.h"
#include "SchM_Fee.h"
#include "SchM_Fls_17_Dmu.h"
#include "SchM_IpduM.h"
#include "SchM_Irq.h"
#include "SchM_McalLib.h"
#include "SchM_Mcu.h"
#include "SchM_NvM.h"
#include "SchM_PduR.h"
#include "SchM_Port.h"
#include "SchM_Pwm_17_GtmCcu6.h"
#include "SchM_Sbc_30_Tlf35584.h"
#include "SchM_Spi.h"

#include "Rte_Hook.h"

#include "Rte_Cbk.h"

/* AUTOSAR 3.x compatibility */
#if !defined (RTE_LOCAL)
# define RTE_LOCAL static
#endif


/**********************************************************************************************************************
 * API for enable / disable interrupts global
 *********************************************************************************************************************/

#if defined(osDisableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableAllInterrupts() osDisableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_DisableAllInterrupts() DisableAllInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableAllInterrupts() osEnableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_EnableAllInterrupts() EnableAllInterrupts()   /* AUTOSAR OS */
#endif

/**********************************************************************************************************************
 * API for enable / disable interrupts up to the systemLevel
 *********************************************************************************************************************/

#if defined(osDisableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableOSInterrupts() osDisableLevelKM()   /* MICROSAR OS */
#else
# define Rte_DisableOSInterrupts() SuspendOSInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableOSInterrupts() osEnableLevelKM()   /* MICROSAR OS */
#else
# define Rte_EnableOSInterrupts() ResumeOSInterrupts()   /* AUTOSAR OS */
#endif

/**********************************************************************************************************************
 * Rte Init State Variable
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_8BIT
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

volatile VAR(uint8, RTE_VAR_ZERO_INIT_NOCACHE) Rte_InitState = RTE_STATE_UNINIT; /* PRQA S 3408 */ /* MD_Rte_3408 */
volatile VAR(uint8, RTE_VAR_ZERO_INIT_NOCACHE) Rte_StartTiming_InitState = RTE_STATE_UNINIT; /* PRQA S 0850, 3408, 1514 */ /* MD_MSR_MacroArgumentEmpty, MD_Rte_3408, MD_Rte_1514 */

#define RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOCACHE_ZERO_INIT_8BIT
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_8BIT
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

volatile VAR(uint8, RTE_VAR_ZERO_INIT_NOCACHE) Rte_InitState_1 = RTE_STATE_UNINIT; /* PRQA S 3408 */ /* MD_Rte_3408 */

#define RTE_STOP_SEC_VAR_OsApplication_OsCore1_NOCACHE_ZERO_INIT_8BIT
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 * Defines for Rte_ComSendSignalProxy
 *********************************************************************************************************************/
#define RTE_COM_SENDSIGNALPROXY_NOCHANGE       (0U)
#define RTE_COM_SENDSIGNALPROXY_SEND           (1U)
#define RTE_COM_SENDSIGNALPROXY_INVALIDATE     (2U)



/**********************************************************************************************************************
 * Timer handling
 *********************************************************************************************************************/

#if defined OS_US2TICKS_SystemTimer
# define RTE_USEC_SystemTimer OS_US2TICKS_SystemTimer
#else
# define RTE_USEC_SystemTimer(val) ((TickType)RTE_CONST_USEC_SystemTimer_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#if defined OS_MS2TICKS_SystemTimer
# define RTE_MSEC_SystemTimer OS_MS2TICKS_SystemTimer
#else
# define RTE_MSEC_SystemTimer(val) ((TickType)RTE_CONST_MSEC_SystemTimer_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#if defined OS_SEC2TICKS_SystemTimer
# define RTE_SEC_SystemTimer OS_SEC2TICKS_SystemTimer
#else
# define RTE_SEC_SystemTimer(val)  ((TickType)RTE_CONST_SEC_SystemTimer_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#if defined OS_US2TICKS_SystemTimer1
# define RTE_USEC_SystemTimer1 OS_US2TICKS_SystemTimer1
#else
# define RTE_USEC_SystemTimer1(val) ((TickType)RTE_CONST_USEC_SystemTimer1_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#if defined OS_MS2TICKS_SystemTimer1
# define RTE_MSEC_SystemTimer1 OS_MS2TICKS_SystemTimer1
#else
# define RTE_MSEC_SystemTimer1(val) ((TickType)RTE_CONST_MSEC_SystemTimer1_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#if defined OS_SEC2TICKS_SystemTimer1
# define RTE_SEC_SystemTimer1 OS_SEC2TICKS_SystemTimer1
#else
# define RTE_SEC_SystemTimer1(val)  ((TickType)RTE_CONST_SEC_SystemTimer1_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#define RTE_CONST_MSEC_SystemTimer_0U (0UL)
#define RTE_CONST_MSEC_SystemTimer1_0U (0UL)
#define RTE_CONST_MSEC_SystemTimer_1U (1UL)
#define RTE_CONST_MSEC_SystemTimer1_1U (1UL)
#define RTE_CONST_MSEC_SystemTimer_10U (10UL)
#define RTE_CONST_MSEC_SystemTimer1_10U (10UL)
#define RTE_CONST_MSEC_SystemTimer_20U (20UL)
#define RTE_CONST_MSEC_SystemTimer_250U (250UL)
#define RTE_CONST_MSEC_SystemTimer_5U (5UL)

#define RTE_CONST_SEC_SystemTimer_0U (0UL)
#define RTE_CONST_SEC_SystemTimer_1U (1000UL)


/**********************************************************************************************************************
 * Internal definitions
 *********************************************************************************************************************/

#define RTE_TASK_TIMEOUT_EVENT_MASK   ((EventMaskType)0x01)
#define RTE_TASK_WAITPOINT_EVENT_MASK ((EventMaskType)0x02)

/**********************************************************************************************************************
 * RTE life cycle API
 *********************************************************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CODE) SchM_Start(void)
{
  uint32 id = GetCoreID();
  if (id == OS_CORE_ID_0) /* PRQA S 1843 */ /* MD_Rte_Os */
  {
    Rte_InitState = RTE_STATE_SCHM_START;
  }
  if (id == OS_CORE_ID_1) /* PRQA S 1843 */ /* MD_Rte_Os */
  {
    Rte_InitState_1 = RTE_STATE_SCHM_START;
  }
}

FUNC(void, RTE_CODE) SchM_Init(void)
{
  uint32 id = GetCoreID();
  if (id == OS_CORE_ID_0) /* PRQA S 1843 */ /* MD_Rte_Os */
  {
    /* activate the tasks */
    (void)ActivateTask(Default_BSW_ASync_Task_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */

    Rte_InitState = RTE_STATE_SCHM_INIT;
  }
  if (id == OS_CORE_ID_1) /* PRQA S 1843 */ /* MD_Rte_Os */
  {
    Rte_InitState_1 = RTE_STATE_SCHM_INIT;
  }
}

FUNC(void, RTE_CODE) SchM_StartTiming(void)
{
  uint32 id = GetCoreID();
  if (id == OS_CORE_ID_0) /* PRQA S 1843 */ /* MD_Rte_Os */
  {
    SchM_StartTimingCore0(); /* PRQA S 2987 */ /* MD_Rte_2987 */
  }
  if (id == OS_CORE_ID_1) /* PRQA S 1843 */ /* MD_Rte_Os */
  {
    SchM_StartTimingCore1(); /* PRQA S 2987 */ /* MD_Rte_2987 */
  }
}

FUNC(void, RTE_CODE) SchM_StartTimingCore0(void)
{
  /* activate the alarms used for TimingEvents */
  (void)SetRelAlarm(Rte_Al_TE2_Default_BSW_ASync_Task_10ms_0_10ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(10U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_Default_BSW_ASync_Task_10ms_0_20ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(20U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Com_Com_MainFunctionTx_ComMainFunctionTx, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(5U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */

}

FUNC(void, RTE_CODE) SchM_StartTimingCore1(void)
{
  /* activate the alarms used for TimingEvents */
  (void)SetRelAlarm(Rte_Al_TE2_EcuM_EcuM_MainFunction, RTE_MSEC_SystemTimer1(0U) + (TickType)1U, RTE_MSEC_SystemTimer1(10U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */

}

FUNC(Std_ReturnType, RTE_CODE) Rte_Start(void)
{
  uint32 id = GetCoreID();
  if (id == OS_CORE_ID_0) /* PRQA S 1843 */ /* MD_Rte_Os */
  {
    /* activate the tasks */
    (void)ActivateTask(Default_Appl_Init_Task); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ActivateTask(Default_Appl_Task); /* PRQA S 3417 */ /* MD_Rte_Os */

    /* activate the alarms used for TimingEvents */
    (void)SetRelAlarm(Rte_Al_TE_StartApp_StartApp_Cyclic1000ms, RTE_SEC_SystemTimer(0U) + (TickType)1U, RTE_SEC_SystemTimer(1U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)SetRelAlarm(Rte_Al_TE_StartApp_StartApp_Cyclic10ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(10U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)SetRelAlarm(Rte_Al_TE_StartApp_StartApp_Cyclic1ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(1U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)SetRelAlarm(Rte_Al_TE_StartApp_StartApp_Cyclic250ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(250U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
    (void)SetRelAlarm(Rte_Al_TE_MotorTask_0_1ms, RTE_MSEC_SystemTimer1(0U) + (TickType)1U, RTE_MSEC_SystemTimer1(1U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */

    Rte_StartTiming_InitState = RTE_STATE_INIT;
    Rte_InitState = RTE_STATE_INIT;

  }
  if (id == OS_CORE_ID_1) /* PRQA S 1843 */ /* MD_Rte_Os */
  {
    /* activate the tasks */
    (void)ActivateTask(Default_MotorInitTask); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ActivateTask(MotorTask); /* PRQA S 3417 */ /* MD_Rte_Os */

    Rte_InitState_1 = RTE_STATE_INIT;

  }
  return RTE_E_OK;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Stop(void)
{
  uint32 id = GetCoreID();
  if (id == OS_CORE_ID_0) /* PRQA S 1843 */ /* MD_Rte_Os */
  {
    Rte_StartTiming_InitState = RTE_STATE_UNINIT;
    /* deactivate alarms */
    (void)CancelAlarm(Rte_Al_TE_StartApp_StartApp_Cyclic1000ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)CancelAlarm(Rte_Al_TE_StartApp_StartApp_Cyclic10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)CancelAlarm(Rte_Al_TE_StartApp_StartApp_Cyclic1ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)CancelAlarm(Rte_Al_TE_StartApp_StartApp_Cyclic250ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)CancelAlarm(Rte_Al_TE_MotorTask_0_1ms); /* PRQA S 3417 */ /* MD_Rte_Os */

    Rte_InitState = RTE_STATE_SCHM_INIT;

  }
  if (id == OS_CORE_ID_1) /* PRQA S 1843 */ /* MD_Rte_Os */
  {
    Rte_InitState_1 = RTE_STATE_SCHM_INIT;

  }
  return RTE_E_OK;
}

FUNC(void, RTE_CODE) SchM_Deinit(void)
{
  uint32 id = GetCoreID();
  if (id == OS_CORE_ID_0) /* PRQA S 1843 */ /* MD_Rte_Os */
  {
    /* deactivate alarms */
    (void)CancelAlarm(Rte_Al_TE2_Default_BSW_ASync_Task_10ms_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)CancelAlarm(Rte_Al_TE2_Default_BSW_ASync_Task_10ms_0_20ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)CancelAlarm(Rte_Al_TE_Com_Com_MainFunctionTx_ComMainFunctionTx); /* PRQA S 3417 */ /* MD_Rte_Os */

    Rte_InitState = RTE_STATE_UNINIT;
  }
  if (id == OS_CORE_ID_1) /* PRQA S 1843 */ /* MD_Rte_Os */
  {
    /* deactivate alarms */
    (void)CancelAlarm(Rte_Al_TE2_EcuM_EcuM_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */

    Rte_InitState_1 = RTE_STATE_UNINIT;
  }
}

FUNC(void, RTE_CODE) Rte_InitMemory(void)
{
  uint32 id;
  id = GetCoreID();
  if (id == OS_CORE_ID_0) /* PRQA S 1843 */ /* MD_Rte_Os */
  {
    Rte_InitState = RTE_STATE_UNINIT;
    Rte_StartTiming_InitState = RTE_STATE_UNINIT;
    Rte_InitMemory_SystemApplication_OsCore0();
  }
  else if (id == OS_CORE_ID_1) /* PRQA S 2004, 1843 */ /* MD_MSR_EmptyClause, MD_Rte_Os */
  {
    Rte_InitState_1 = RTE_STATE_UNINIT;
    Rte_InitMemory_OsApplication_OsCore1();
  }
}


/**********************************************************************************************************************
 * Exclusive area access
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) SchM_Enter_Adc_KernelData(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Adc_KernelData(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Adc_SrcRegAccess(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Adc_SrcRegAccess(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Dma_ChEventStatus(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Dma_ChEventStatus(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Dma_ChannelConfigUpdate(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Dma_ChannelConfigUpdate(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Dma_ChannelFreezeResume(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Dma_ChannelFreezeResume(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Dma_ChannelHWTrigger(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Dma_ChannelHWTrigger(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Dma_ChannelInitDeinit(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Dma_ChannelInitDeinit(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Dma_ChannelStartStop(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Dma_ChannelStartStop(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Dma_ChannelSwitchBuffer(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Dma_ChannelSwitchBuffer(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Dma_InterruptStatus(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Dma_InterruptStatus(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Dma_MEErrorStatus(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Dma_MEErrorStatus(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Fls_17_Dmu_Erase(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Fls_17_Dmu_Erase(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Fls_17_Dmu_Init(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Fls_17_Dmu_Init(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Fls_17_Dmu_Main(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Fls_17_Dmu_Main(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Fls_17_Dmu_ResumeErase(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Fls_17_Dmu_ResumeErase(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Fls_17_Dmu_UserContentCount(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Fls_17_Dmu_UserContentCount(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Fls_17_Dmu_Write(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Fls_17_Dmu_Write(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Mcu_AtomAgcReg(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Mcu_AtomAgcReg(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Mcu_TomTgcReg(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Mcu_TomTgcReg(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Pwm_17_GtmCcu6_HandleNotification(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Pwm_17_GtmCcu6_HandleNotification(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Pwm_17_GtmCcu6_PeriodAndDutyUpdate(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Pwm_17_GtmCcu6_PeriodAndDutyUpdate(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_Buffer_Update(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_Buffer_Update(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_Cancel_Seq(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_Cancel_Seq(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_ChannelLock(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_ChannelLock(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_Queue_Update(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_Queue_Update(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_Queue_Update_QSPI0(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_Queue_Update_QSPI0(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_Queue_Update_QSPI1(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_Queue_Update_QSPI1(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_Queue_Update_QSPI2(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_Queue_Update_QSPI2(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_Queue_Update_QSPI3(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_Queue_Update_QSPI3(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_Queue_Update_QSPI4(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_Queue_Update_QSPI4(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_Queue_Update_QSPI5(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_Queue_Update_QSPI5(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_SyncLock(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  SuspendOSInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_SyncLock(void)
{
  /* RteAnalyzer(ExclusiveArea, OS_INTERRUPT_BLOCKING) */
  ResumeOSInterrupts();
}


#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_1514:  MISRA rule: Rule8.9
     Reason:     Because of external definition, misra does not see the call.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_2987:  MISRA rule: Rule2.2
     Reason:     Used to simplify code generation.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_3408:  MISRA rule: Rule8.4
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
