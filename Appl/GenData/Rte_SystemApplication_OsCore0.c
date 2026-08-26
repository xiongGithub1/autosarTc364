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
 *             File:  Rte_SystemApplication_OsCore0.c
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
#include "Rte_Dcm.h"
#include "Rte_DemMaster_0.h"
#include "Rte_DemSatellite_0.h"
#include "Rte_Det.h"
#include "Rte_DigApp.h"
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
#include "SchM_CanNm.h"
#include "SchM_CanSM.h"
#include "SchM_CanTp.h"
#include "SchM_Com.h"
#include "SchM_ComM.h"
#include "SchM_ComXf.h"
#include "SchM_Crc.h"
#include "SchM_Dcm.h"
#include "SchM_Dem.h"
#include "SchM_Det.h"
#include "SchM_Dio.h"
#include "SchM_Dma.h"
#include "SchM_E2EXf.h"
#include "SchM_EcuM.h"
#include "SchM_Fee.h"
#include "SchM_Fls_17_Dmu.h"
#include "SchM_Irq.h"
#include "SchM_McalLib.h"
#include "SchM_Mcu.h"
#include "SchM_Nm.h"
#include "SchM_NvM.h"
#include "SchM_PduR.h"
#include "SchM_Port.h"
#include "SchM_Pwm_17_GtmCcu6.h"
#include "SchM_Sbc_30_Tlf35584.h"
#include "SchM_Spi.h"
#include "SchM_Uart.h"
#include "SchM_Xcp.h"

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
 * TxAck/ModeSwitchAck Flags
 *********************************************************************************************************************/


#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_SystemApplication_OsCore0_AckFlagsType, RTE_VAR_INIT) Rte_SystemApplication_OsCore0_AckFlags = {
  1,
};

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define Rte_SystemApplication_OsCore0_AckFlagsInit() (Rte_MemClr(&Rte_SystemApplication_OsCore0_AckFlags, sizeof(Rte_SystemApplication_OsCore0_AckFlagsType)))
/**********************************************************************************************************************
 * Defines for Rte_ComSendSignalProxy
 *********************************************************************************************************************/
#define RTE_COM_SENDSIGNALPROXY_NOCHANGE       (0U)
#define RTE_COM_SENDSIGNALPROXY_SEND           (1U)
#define RTE_COM_SENDSIGNALPROXY_INVALIDATE     (2U)



/**********************************************************************************************************************
 * RTE internal IOC replacements
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(uint8, RTE_VAR_NOINIT) Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_Queue[1]; /* PRQA S 1514 */ /* MD_Rte_1514 */

#define RTE_STOP_SEC_VAR_SystemApplication_OsCore0_NOINIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(uint8, RTE_VAR_INIT) Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_tail = 0;

#define RTE_STOP_SEC_VAR_SystemApplication_OsCore0_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define RTE_START_SEC_VAR_SystemApplication_OsCore0_ZERO_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_head = 0;

#define RTE_STOP_SEC_VAR_SystemApplication_OsCore0_ZERO_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define RTE_START_SEC_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint32_least num);
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Dcm_DcmEcuReset(Dcm_EcuResetType mode); /* PRQA S 3408 */ /* MD_Rte_3408 */

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Data structures for mode management
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
VAR(Dcm_EcuResetType, RTE_VAR_INIT) Rte_ModeMachine_Dcm_DcmEcuReset_DcmEcuReset = RTE_MODE_Dcm_DcmEcuReset_NONE; /* PRQA S 3408 */ /* MD_Rte_3408 */
#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



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

#define RTE_START_SEC_SYSTEMAPPLICATION_OSCORE0_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Rte_EventMaskType, RTE_CODE) Rte_GetModeEntryEventMask_Dcm_DcmEcuReset_DcmEcuReset(Dcm_EcuResetType mode)
{
  Rte_EventMaskType eventMask;
  switch (mode)
  {
    case 0U:
      eventMask = Rte_Ev_Run_DigApp_DcmEcuReset_ModeSwitch; /* EXECUTE */
      break;
    case 1U:
      eventMask = Rte_Ev_Run_DigApp_DcmEcuReset_ModeSwitch; /* HARD */
      break;
    case 3U:
      eventMask = Rte_Ev_Run_DigApp_DcmEcuReset_ModeSwitch; /* JUMPTOSYSSUPPLIERBOOTLOADER */
      break;
    case 4U:
      eventMask = Rte_Ev_Run_DigApp_DcmEcuReset_ModeSwitch; /* KEYONOFF */
      break;
    case 6U:
      eventMask = Rte_Ev_Run_DigApp_DcmEcuReset_ModeSwitch; /* SOFT */
      break;
    default: /* COV_RTE_MISRA */
      eventMask = (Rte_EventMaskType)0U;
      break;
  }

  return eventMask;
}


FUNC(void, RTE_CODE) Rte_InitMemory_SystemApplication_OsCore0(void)
{
  /* reset Tx Ack Flags */
  Rte_SystemApplication_OsCore0_AckFlagsInit(); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_SystemApplication_OsCore0_AckFlags.Rte_ModeSwitchAck_Dcm_DcmEcuReset_DcmEcuReset_Ack = 1U;

  /* mode management initialization part 1 */
  Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_Queue[0U] = RTE_MODE_Dcm_DcmEcuReset_NONE;

  Rte_ModeMachine_Dcm_DcmEcuReset_DcmEcuReset = RTE_MODE_Dcm_DcmEcuReset_NONE;

  Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_tail = 0;
  Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_head = 0;
}


/**********************************************************************************************************************
 * Internal C/S connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DevelopmentData_CanDriverVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  OpStatus = OpStatus; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  ErrorCode = ErrorCode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DevelopmentData_CanDriverVersion_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Data) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  OpStatus = OpStatus; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  Data = Data; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DevelopmentData_CanDriverVersion_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DCM_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Data = Data; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  OpStatus = OpStatus; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  ErrorCode = ErrorCode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DevelopmentData_DiagnosticModuleVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  OpStatus = OpStatus; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  ErrorCode = ErrorCode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DevelopmentData_DiagnosticModuleVersion_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Data) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  OpStatus = OpStatus; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  Data = Data; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DevelopmentData_DiagnosticModuleVersion_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DCM_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Data = Data; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  OpStatus = OpStatus; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  ErrorCode = ErrorCode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DevelopmentData_NmVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  OpStatus = OpStatus; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  ErrorCode = ErrorCode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DevelopmentData_NmVersion_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Data) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  OpStatus = OpStatus; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  Data = Data; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DevelopmentData_NmVersion_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DCM_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Data = Data; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  OpStatus = OpStatus; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  ErrorCode = ErrorCode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DevelopmentData_OperatingSystemVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  OpStatus = OpStatus; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  ErrorCode = ErrorCode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DevelopmentData_OperatingSystemVersion_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Data) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  OpStatus = OpStatus; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  Data = Data; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DevelopmentData_OperatingSystemVersion_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DCM_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Data = Data; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  OpStatus = OpStatus; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  ErrorCode = ErrorCode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DevelopmentData_TransportLayerVersion_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  OpStatus = OpStatus; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  ErrorCode = ErrorCode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DevelopmentData_TransportLayerVersion_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Data) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  OpStatus = OpStatus; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  Data = Data; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DevelopmentData_TransportLayerVersion_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DCM_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Data = Data; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  OpStatus = OpStatus; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  ErrorCode = ErrorCode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBInitEvt_DTC_0x000002_InitMonitorForEvent(Dem_InitMonitorReasonType InitMonitorReason) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  InitMonitorReason = InitMonitorReason; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBReadData_DID_0x1_DID_Data_GlobalTime_ReadData(P2VAR(uint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) Data) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Data = Data; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBReadData_PID_0x12_DID_Data_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) Data) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Data = Data; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBReadData_PID_0x13_DID_Data_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) Data) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Data = Data; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_DID_0x1_DID_Data_GlobalTime_ReadData(P2VAR(uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Data = Data; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_PID_0x12_DID_Data_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Data = Data; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_PID_0x13_DID_Data_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Data = Data; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
  /* call to server runnable removed as client is never triggered */

  return ret;
}


/**********************************************************************************************************************
 * RTE internal IOC replacements
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_IocSend_Rte_M_Dcm_DcmEcuReset_DcmEcuReset(CONST(uint8, RTE_CONST) data0)
{
  Std_ReturnType result = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_head != Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_tail)
  {
    result = RTE_E_LIMIT;
  }
  else
  {
    if (Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_tail == 1U)
    {
      Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_tail = 0U;
    }
    else
    {
      Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_tail = 1U;
    }

    Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_Queue[0] = data0;
  }

  return result;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_IocReceive_Rte_M_Dcm_DcmEcuReset_DcmEcuReset(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data0)
{
  Std_ReturnType result;

  if (Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_tail == Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_head)
  {
    result = RTE_E_NO_DATA;
  }
  else
  {
    if (Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_head == 1U)
    {
      Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_head = 0U;
    }
    else
    {
      Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_head = 1U;
    }
    *data0 = Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_Queue[0];
    result = RTE_E_OK;
  }
  return result;
}



/**********************************************************************************************************************
 * Transmission/Mode Switch Acknowledgement handling (Rte_Feedback/Rte_SwitchAck)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_SwitchAck_Dcm_DcmEcuReset_DcmEcuReset(void)
{
  Std_ReturnType ret = RTE_E_TRANSMIT_ACK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_SystemApplication_OsCore0_AckFlags.Rte_ModeSwitchAck_Dcm_DcmEcuReset_DcmEcuReset_Ack == 0U)
  {
    ret = RTE_E_NO_DATA;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_CN_CAN00_5e566ad9_DcmCommunicationControl_ComMConf_ComMChannel_CN_CAN00_5e566ad9(Dcm_CommunicationModeType nextMode) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  nextMode = nextMode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmControlDtcSetting_DcmControlDtcSetting(Dcm_ControlDtcSettingType nextMode) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  nextMode = nextMode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(Dcm_DiagnosticSessionControlType nextMode) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  nextMode = nextMode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmEcuReset_DcmEcuReset(Dcm_EcuResetType nextMode) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  uint8 internalIndexNextMode = Rte_GetInternalModeIndex_Dcm_DcmEcuReset(nextMode);
  uint8 internalIndexCurrentMode;
  Dcm_EcuResetType currentMode;
  SuspendOSInterrupts();
  currentMode = Rte_ModeMachine_Dcm_DcmEcuReset_DcmEcuReset;
  internalIndexCurrentMode = Rte_GetInternalModeIndex_Dcm_DcmEcuReset(currentMode);
  if (internalIndexNextMode >= 7U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else if (Rte_SystemApplication_OsCore0_AckFlags.Rte_ModeSwitchAck_Dcm_DcmEcuReset_DcmEcuReset_Ack == 0U)
  {
    ret = RTE_E_LIMIT;
    ResumeOSInterrupts();
  }
  else if (internalIndexCurrentMode >= 7U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else
  {
    Rte_EventMaskType ModeSwitchEventMask;

    ModeSwitchEventMask = Rte_GetModeEntryEventMask_Dcm_DcmEcuReset_DcmEcuReset(internalIndexNextMode); /* PRQA S 2986 */ /* MD_Rte_2986 */

    if (ModeSwitchEventMask != (Rte_EventMaskType)0)
    {
      ret = Rte_IocSend_Rte_M_Dcm_DcmEcuReset_DcmEcuReset(nextMode);

      Rte_SystemApplication_OsCore0_AckFlags.Rte_ModeSwitchAck_Dcm_DcmEcuReset_DcmEcuReset_Ack = 0U;
      ResumeOSInterrupts();

      (void)SetEvent(Default_Appl_Task, ModeSwitchEventMask); /* PRQA S 3417 */ /* MD_Rte_Os */
    }
    else
    {
      Rte_ModeMachine_Dcm_DcmEcuReset_DcmEcuReset = nextMode;
      Rte_SystemApplication_OsCore0_AckFlags.Rte_ModeSwitchAck_Dcm_DcmEcuReset_DcmEcuReset_Ack = 1U;
      ResumeOSInterrupts();
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */


/**********************************************************************************************************************
 * Transmission/Mode Switch Acknowledgement handling (Rte_Feedback/Rte_SwitchAck)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_SwitchAck_EcuM_currentMode_currentMode(void)
{

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_EcuM_currentMode_currentMode(EcuM_StateType nextMode) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  nextMode = nextMode; /* PRQA S 2983, 1338 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */

  return ret;
}

#define RTE_STOP_SEC_SYSTEMAPPLICATION_OSCORE0_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task bodies for RTE controlled tasks
 *********************************************************************************************************************/
#define RTE_START_SEC_DEFAULT_APPL_INIT_TASK_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     Default_Appl_Init_Task
 * Priority: 45
 * Schedule: NON
 *********************************************************************************************************************/
TASK(Default_Appl_Init_Task) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{

  /* call runnable */
  StartApp_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  DigInit(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_DEFAULT_APPL_INIT_TASK_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_DEFAULT_APPL_TASK_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     Default_Appl_Task
 * Priority: 5
 * Schedule: NON
 *********************************************************************************************************************/
TASK(Default_Appl_Task) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Run_DigApp_DcmEcuReset_ModeSwitch | Rte_Ev_Run_StartApp_StartApp_Cyclic1000ms | Rte_Ev_Run_StartApp_StartApp_Cyclic10ms | Rte_Ev_Run_StartApp_StartApp_Cyclic1ms | Rte_Ev_Run_StartApp_StartApp_Cyclic250ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(Default_Appl_Task, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Run_DigApp_DcmEcuReset_ModeSwitch | Rte_Ev_Run_StartApp_StartApp_Cyclic1000ms | Rte_Ev_Run_StartApp_StartApp_Cyclic10ms | Rte_Ev_Run_StartApp_StartApp_Cyclic1ms | Rte_Ev_Run_StartApp_StartApp_Cyclic250ms)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Run_StartApp_StartApp_Cyclic1ms) != (EventMaskType)0)
    {
      /* call runnable */
      StartApp_Cyclic1ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_StartApp_StartApp_Cyclic10ms) != (EventMaskType)0)
    {
      /* call runnable */
      StartApp_Cyclic10ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_StartApp_StartApp_Cyclic250ms) != (EventMaskType)0)
    {
      /* call runnable */
      StartApp_Cyclic250ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_StartApp_StartApp_Cyclic1000ms) != (EventMaskType)0)
    {
      /* call runnable */
      StartApp_Cyclic1000ms(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_DigApp_DcmEcuReset_ModeSwitch) != (EventMaskType)0)
    {
      /* call runnable */
      DcmEcuReset_ModeSwitch(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if (((ev & Rte_Ev_Run_DigApp_DcmEcuReset_ModeSwitch) != (EventMaskType)0) && (Rte_SystemApplication_OsCore0_AckFlags.Rte_ModeSwitchAck_Dcm_DcmEcuReset_DcmEcuReset_Ack == 0U))
    {
      Dcm_EcuResetType nextMode = 0U; /* PRQA S 2982 */ /* MD_Rte_2982 */

      Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
      (void)Rte_IocReceive_Rte_M_Dcm_DcmEcuReset_DcmEcuReset(&nextMode);

      Rte_ModeMachine_Dcm_DcmEcuReset_DcmEcuReset = nextMode;

      Rte_SystemApplication_OsCore0_AckFlags.Rte_ModeSwitchAck_Dcm_DcmEcuReset_DcmEcuReset_Ack = 1U;

      Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */


    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_DEFAULT_APPL_TASK_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_DEFAULT_BSW_ASYNC_TASK_10MS_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     Default_BSW_ASync_Task_10ms
 * Priority: 30
 * Schedule: NON
 *********************************************************************************************************************/
TASK(Default_BSW_ASync_Task_10ms) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Cyclic2_Default_BSW_ASync_Task_10ms_0_10ms | Rte_Ev_Cyclic2_Default_BSW_ASync_Task_10ms_0_20ms | Rte_Ev_Cyclic2_Default_BSW_ASync_Task_10ms_0_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(Default_BSW_ASync_Task_10ms, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic2_Default_BSW_ASync_Task_10ms_0_10ms | Rte_Ev_Cyclic2_Default_BSW_ASync_Task_10ms_0_20ms | Rte_Ev_Cyclic2_Default_BSW_ASync_Task_10ms_0_5ms)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic2_Default_BSW_ASync_Task_10ms_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      BswM_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      EcuM_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call schedulable entity */
      CanSM_MainFunction();

      /* call schedulable entity */
      Can_MainFunction_Mode();

      /* call schedulable entity */
      Can_MainFunction_BusOff();

      /* call schedulable entity */
      Can_MainFunction_Write();

      /* call schedulable entity */
      Can_MainFunction_Read();
    }

    if ((ev & Rte_Ev_Cyclic2_Default_BSW_ASync_Task_10ms_0_20ms) != (EventMaskType)0)
    {
      /* call runnable */
      ComM_MainFunction_0(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic2_Default_BSW_ASync_Task_10ms_0_10ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Com_MainFunctionRx_ComMainFunctionRx();
    }

    if ((ev & Rte_Ev_Cyclic2_Default_BSW_ASync_Task_10ms_0_5ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Com_MainFunctionTx_ComMainFunctionTx();
    }

    if ((ev & Rte_Ev_Cyclic2_Default_BSW_ASync_Task_10ms_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      NvM_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call schedulable entity */
      Fee_MainFunction();

      /* call schedulable entity */
      Fls_17_Dmu_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic2_Default_BSW_ASync_Task_10ms_0_5ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      CanTp_MainFunction();

      /* call schedulable entity */
      CanXcp_MainFunction();

      /* call schedulable entity */
      Xcp_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic2_Default_BSW_ASync_Task_10ms_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      Dcm_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      Dem_MasterMainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      Dem_SatelliteMainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_DEFAULT_BSW_ASYNC_TASK_10MS_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0315:  MISRA rule: Dir1.1
     Reason:     Pointer cast to void because generic access is necessary.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_1514:  MISRA rule: Rule8.9
     Reason:     Because of external definition, misra does not see the call.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_2982:  MISRA rule: Rule2.2
     Reason:     Used to simplify code generation.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_2983:  MISRA rule: Rule2.2
     Reason:     For generated code it is difficult to check the usage of each object.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_2986:  MISRA rule: Rule2.2
     Reason:     Used to simplify code generation.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_2987:  MISRA rule: Rule2.2
     Reason:     Used to simplify code generation.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
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

   MD_Rte_Qac:
     Reason:     This justification is used as summary justification for all deviations caused by wrong analysis tool results.
                 The used analysis tool QAC 9.0 sometimes creates wrong messages. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/

/**********************************************************************************************************************
 Code coverage justifications
 *********************************************************************************************************************/

/* COV_JUSTIFICATION_BEGIN
   \ID COV_RTE_MISRA
     \ACCEPT XX
     \REASON [COV_MSR_MISRA]

COV_JUSTIFICATION_END */
