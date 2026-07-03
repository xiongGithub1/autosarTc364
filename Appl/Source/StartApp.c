/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  StartApp.c
 *           Config:  last364.dpa
 *        SW-C Type:  StartApp
 *
 *        Generator:  MICROSAR RTE Generator Version 4.29.0
 *                    RTE Core Version 1.29.0
 *          License:  CBD2200508
 *
 *      Description:  C-Code implementation template for SW-C <StartApp>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/* PRQA S 0857 EOF */ /* MD_MSR_Dir1.1 */
/* PRQA S 0614 EOF */ /* MD_Rte_TestCode */

/* PRQA S 3109 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3112 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2982 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2983 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2880 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3203 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3205 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3206 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3218 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3229 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2002 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3334 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3417 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3426 EOF */ /* MD_Rte_TestCode */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_StartApp.h"

#include "CanIf.h"
#include "CanSM_ComM.h"
#include "Com.h"
#include "ComM.h"
#include "ComM_EcuMBswM.h"
#include "Dio.h"
#include "Dio_Cfg.h"
#include "EcuM.h"
#include "Rte_EcuM_Type.h"
#include "Spi.h"
#include "Spi_Cfg.h"
#include "Spi_PBcfg.h"
#include "IfxPort_reg.h"
#include "IfxQspi_bf.h"
#include "IfxQspi_reg.h"
#include "Tle9183.h"

/* Set to TRUE: loopback test without TLE9183. FALSE: normal 9183 register test. */
#define STARTAPP_QSPI3_LOOPBACK_TEST           (False)
/* 1 = internal loopback (QSPI GLOBALCON.LB, no wire).
 * 0 = external loopback (short P22.0 to P22.1). */
#define STARTAPP_QSPI3_LOOPBACK_USE_INTERNAL   (0U)
/* 1 = use 8-bit frame (change Spi_PBcfg DataConfig to 0x88U manually). */
#define STARTAPP_QSPI3_LOOPBACK_USE_8BIT       (0U)

#define STARTAPP_QSPI3_SPI_FRAME_MASK          (0x00FFFFFFU)
#if (STARTAPP_QSPI3_LOOPBACK_USE_8BIT == 1U)
#define STARTAPP_QSPI3_LOOPBACK_TX_PATTERN     (0x000000A5U)
#else
#define STARTAPP_QSPI3_LOOPBACK_TX_PATTERN     (0x00A5A5A5U)
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

uint8 StartApp_CanTxLampCnt;
boolean StartApp_CanTxRearInteriorLight;
uint8 StartApp_CanTxLampCntResult;
uint8 StartApp_CanTxRearInteriorLightResult;
uint32 StartApp_CanTxUpdateCounter;
uint32 StartApp_CanTxSkipCounter;
Com_StatusType StartApp_ComStatus;
EcuM_StateType StartApp_EcuMState;
Std_ReturnType StartApp_EcuMGetStateResult;
ComM_InitStatusType StartApp_ComMStatus;
Std_ReturnType StartApp_ComMGetStatusResult;
Std_ReturnType StartApp_ComMRequestResult;
boolean StartApp_ComMCommunicationAllowed;
ComM_ModeType StartApp_ComMCurrentMode;
Std_ReturnType StartApp_ComMCurrentModeResult;
ComM_ModeType StartApp_CanSMCurrentMode;
Std_ReturnType StartApp_CanSMCurrentModeResult;
CanIf_ControllerModeType StartApp_CanIfControllerMode;
Std_ReturnType StartApp_CanIfControllerModeResult;
uint8 Can1_En=0;
uint8 Can1_Nerr=0;
uint8 Can1_Nstb=0;
CanIf_PduGetModeType StartApp_CanIfPduMode;
Std_ReturnType StartApp_CanIfPduModeResult;

uint32 StartApp_9183SpiTxWord = 0u;
uint32 StartApp_9183SpiRxWord = 0u;
uint32 StartApp_9183SpiPrevRxWord = 0u;
boolean StartApp_9183HwInited = FALSE;
Std_ReturnType StartApp_9183SpiSetupResult = E_NOT_OK;
Std_ReturnType StartApp_9183SpiTransmitResult = E_NOT_OK;
Std_ReturnType StartApp_9183SpiInitCheckResult = E_NOT_OK;
Spi_StatusType StartApp_9183SpiStatusBefore = SPI_UNINIT;
Spi_StatusType StartApp_9183SpiStatusAfter = SPI_UNINIT;
Spi_JobResultType StartApp_9183SpiJobResultBefore = SPI_JOB_FAILED;
Spi_JobResultType StartApp_9183SpiJobResultAfter = SPI_JOB_FAILED;
Spi_SeqResultType StartApp_9183SpiSeqResult = SPI_SEQ_FAILED;
Spi_SeqResultType StartApp_9183SpiSeqResultBefore = SPI_SEQ_FAILED;
uint32 StartApp_9183SpiTestCounter = 0u;
uint32 StartApp_9183SpiOkCounter = 0u;
uint32 StartApp_9183SpiFailCounter = 0u;
boolean StartApp_9183SpiRxChanged = FALSE;
boolean StartApp_9183SpiTestEnabled = TRUE;
boolean StartApp_9183SpiLoopbackMatch = FALSE;
boolean StartApp_9183SpiLoopbackInternal = FALSE;
boolean StartApp_9183MrstPinLevel = FALSE;
uint8 StartApp_Qspi3BitCount = 0U;
uint32 StartApp_Qspi3GlobalconLb = 0U;
uint32 StartApp_Qspi3GlobalconLbBeforeTx = 0U;
Std_ReturnType StartApp_Qspi3LoopbackCtrlResult = E_NOT_OK;
uint32 StartApp_Qspi3Clc = 0u;
uint32 StartApp_Qspi3Pisel = 0u;
uint32 StartApp_Qspi3Globalcon = 0u;
uint32 StartApp_Qspi3Globalcon1 = 0u;
uint32 StartApp_Qspi3Bacon = 0u;
uint32 StartApp_Qspi3Status = 0u;
uint32 StartApp_Qspi3Status1 = 0u;
uint32 StartApp_Qspi3Ssoc = 0u;

static FUNC(void, StartApp_CODE) StartApp_Test9183Spi(void);
static FUNC(void, StartApp_CODE) StartApp_Qspi3LoopbackTest(void);
static FUNC(void, StartApp_CODE) StartApp_SampleQspi3Regs(void);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 *********************************************************************************************************************/


#define StartApp_START_SEC_CODE
#include "StartApp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static FUNC(void, StartApp_CODE) StartApp_SampleQspi3Regs(void)
{
  StartApp_Qspi3Clc = QSPI3_CLC.U;
  StartApp_Qspi3Pisel = QSPI3_PISEL.U;
  StartApp_Qspi3Globalcon = QSPI3_GLOBALCON.U;
  StartApp_Qspi3Globalcon1 = QSPI3_GLOBALCON1.U;
  StartApp_Qspi3Bacon = QSPI3_BACON.U;
  StartApp_Qspi3Status = QSPI3_STATUS.U;
  StartApp_Qspi3Status1 = QSPI3_STATUS1.U;
  StartApp_Qspi3Ssoc = QSPI3_SSOC.U;
}

static FUNC(void, StartApp_CODE) StartApp_Qspi3LoopbackTest(void)
{
  uint32 txWord = STARTAPP_QSPI3_LOOPBACK_TX_PATTERN;
  uint32 rxWord = 0U;

  StartApp_SampleQspi3Regs();
  StartApp_9183SpiStatusBefore = Spi_GetStatus();
  StartApp_9183SpiJobResultBefore =
      Spi_GetJobResult(SpiConf_SpiJob_SpiJob_9183);
  StartApp_9183SpiSeqResultBefore =
      Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence);

  if (Spi_GetStatus() != SPI_IDLE)
  {
    return;
  }

#if (STARTAPP_QSPI3_LOOPBACK_USE_INTERNAL == 1U)
  StartApp_9183SpiLoopbackInternal = TRUE;
  StartApp_Qspi3LoopbackCtrlResult =
      Spi_ControlLoopBack(SPI_QSPI3_INDEX, SPI_LOOPBACK_ENABLE);
#else
  StartApp_9183SpiLoopbackInternal = FALSE;
  StartApp_Qspi3LoopbackCtrlResult =
      Spi_ControlLoopBack(SPI_QSPI3_INDEX, SPI_LOOPBACK_DISABLE);
#endif

  StartApp_Qspi3GlobalconLbBeforeTx = (uint32)QSPI3_GLOBALCON.B.LB;

  StartApp_9183SpiSetupResult = Spi_SetupEB(
      SpiConf_SpiChannel_SpiChannel_9183,
      (const Spi_DataBufferType *)&txWord,
      (Spi_DataBufferType *)&rxWord,
      1U);

  if (StartApp_9183SpiSetupResult == E_OK)
  {
    StartApp_9183SpiTransmitResult =
        Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence);
    StartApp_9183SpiSeqResult =
        Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence);
  }
  else
  {
    StartApp_9183SpiTransmitResult = E_NOT_OK;
    StartApp_9183SpiSeqResult = SPI_SEQ_FAILED;
  }

  (void)Spi_ControlLoopBack(SPI_QSPI3_INDEX, SPI_LOOPBACK_DISABLE);

  StartApp_9183SpiTxWord = txWord & STARTAPP_QSPI3_SPI_FRAME_MASK;
  StartApp_9183SpiRxWord = rxWord & STARTAPP_QSPI3_SPI_FRAME_MASK;
  StartApp_9183MrstPinLevel =
      (boolean)((P22_IN.U & 0x00000002U) != 0U);
  StartApp_9183SpiLoopbackMatch =
      (boolean)((StartApp_9183SpiSetupResult == E_OK) &&
                (StartApp_9183SpiTransmitResult == E_OK) &&
                (StartApp_9183SpiSeqResult == SPI_SEQ_OK) &&
                (StartApp_Qspi3LoopbackCtrlResult == E_OK) &&
                (StartApp_Qspi3GlobalconLbBeforeTx == 1U) &&
                (StartApp_9183SpiTxWord == StartApp_9183SpiRxWord));

  StartApp_9183SpiStatusAfter = Spi_GetStatus();
  StartApp_9183SpiJobResultAfter =
      Spi_GetJobResult(SpiConf_SpiJob_SpiJob_9183);
  StartApp_SampleQspi3Regs();
  StartApp_Qspi3BitCount = (uint8)(StartApp_Qspi3Status1 & 0x000000FFU);
  StartApp_Qspi3GlobalconLb = (uint32)QSPI3_GLOBALCON.B.LB;

  StartApp_9183SpiRxChanged =
      (boolean)(StartApp_9183SpiPrevRxWord != StartApp_9183SpiRxWord);
  StartApp_9183SpiPrevRxWord = StartApp_9183SpiRxWord;

  StartApp_9183SpiTestCounter++;
  if (StartApp_9183SpiLoopbackMatch == TRUE)
  {
    StartApp_9183SpiOkCounter++;
  }
  else
  {
    StartApp_9183SpiFailCounter++;
  }
}

static FUNC(void, StartApp_CODE) StartApp_Test9183Spi(void)
{
#if (STARTAPP_QSPI3_LOOPBACK_TEST == TRUE)
  StartApp_Qspi3LoopbackTest();
#else
  uint8 nopData = 0U;

  StartApp_SampleQspi3Regs();
  StartApp_9183SpiStatusBefore = Spi_GetStatus();
  StartApp_9183SpiJobResultBefore =
      Spi_GetJobResult(SpiConf_SpiJob_SpiJob_9183);
  StartApp_9183SpiSeqResultBefore =
      Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence);

  Tle9183_MainFunction();

  if (Tle9183_Status.PowerUpDone == FALSE)
  {
    return;
  }

  StartApp_9183SpiSetupResult = Tle9183_ReadRegister(TLE9183_REG_NOP, &nopData);
  StartApp_9183SpiTxWord = Tle9183_Status.LastTxFrame;
  StartApp_9183SpiRxWord = Tle9183_Status.LastRxFrame;

  if (StartApp_9183SpiSetupResult == E_OK)
  {
    StartApp_9183SpiTransmitResult = E_OK;
    StartApp_9183SpiSeqResult = SPI_SEQ_OK;
  }
  else
  {
    StartApp_9183SpiTransmitResult = E_NOT_OK;
    StartApp_9183SpiSeqResult = SPI_SEQ_FAILED;
  }

  StartApp_9183SpiStatusAfter = Spi_GetStatus();
  StartApp_9183SpiJobResultAfter =
      Spi_GetJobResult(SpiConf_SpiJob_SpiJob_9183);
  StartApp_SampleQspi3Regs();

  StartApp_9183SpiRxChanged =
      (boolean)(StartApp_9183SpiPrevRxWord != StartApp_9183SpiRxWord);
  StartApp_9183SpiPrevRxWord = StartApp_9183SpiRxWord;

  StartApp_9183SpiTestCounter++;
  if ((StartApp_9183SpiSetupResult == E_OK) &&
      (StartApp_9183SpiTransmitResult == E_OK) &&
      (StartApp_9183SpiSeqResult == SPI_SEQ_OK) &&
      (Tle9183_Status.LastCrcOk == TRUE))
  {
    StartApp_9183SpiOkCounter++;
  }
  else
  {
    StartApp_9183SpiFailCounter++;
  }
#endif
}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, StartApp_CODE) StartApp_Cyclic1000ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StartApp_Cyclic1000ms
 *********************************************************************************************************************/

	Dio_FlipChannel(DioConf_DioChannel_DioChannel_led2);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StartApp_Cyclic10ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: StartApp_Cyclic10ms_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, StartApp_CODE) StartApp_Cyclic10ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StartApp_Cyclic10ms
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StartApp_Cyclic1ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 1ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: StartApp_Cyclic1ms_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, StartApp_CODE) StartApp_Cyclic1ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StartApp_Cyclic1ms
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StartApp_Cyclic250ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 500ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: StartApp_Cyclic500ms_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, StartApp_CODE) StartApp_Cyclic250ms(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StartApp_Cyclic500ms
 *********************************************************************************************************************/

	Dio_FlipChannel(DioConf_DioChannel_DioChannel_led1);
	Can1_En=Dio_ReadChannel(DioConf_DioChannel_DioChannel_Can1En);
	Can1_Nerr=Dio_ReadChannel(DioConf_DioChannel_DioChannel_Can1Nerr);
	Can1_Nstb=Dio_ReadChannel(DioConf_DioChannel_DioChannel_Can1Nstb);
	StartApp_CanTxLampCnt++;
	StartApp_CanTxRearInteriorLight = (StartApp_CanTxRearInteriorLight == FALSE) ? TRUE : FALSE;

	StartApp_ComStatus = Com_GetStatus();
	StartApp_EcuMGetStateResult = EcuM_GetState(&StartApp_EcuMState);
	StartApp_ComMGetStatusResult = ComM_GetStatus(&StartApp_ComMStatus);
	StartApp_ComMCurrentModeResult = ComM_GetCurrentComMode(ComMConf_ComMUser_CN_CAN00_06ecbb07, &StartApp_ComMCurrentMode);
	StartApp_CanSMCurrentModeResult = CanSM_GetCurrentComMode(ComMConf_ComMChannel_CN_CAN00_5e566ad9, &StartApp_CanSMCurrentMode);
	StartApp_CanIfControllerModeResult = CanIf_GetControllerMode(0u, &StartApp_CanIfControllerMode);
	StartApp_CanIfPduModeResult = CanIf_GetPduMode(0u, &StartApp_CanIfPduMode);

	if(StartApp_ComStatus == COM_INIT)
	{
		StartApp_CanTxLampCntResult = Com_SendSignal(ComConf_ComSignal_sig_LampCnt_omsg_MyECU_Lamp_oCAN00_f37e68ea_Tx, &StartApp_CanTxLampCnt);
		StartApp_CanTxRearInteriorLightResult = Com_SendSignal(ComConf_ComSignal_sig_RearInteriorLight_omsg_Transmit_oCAN00_49a633c1_Tx, &StartApp_CanTxRearInteriorLight);
		StartApp_CanTxUpdateCounter++;
	}
	else
	{
		StartApp_CanTxSkipCounter++;
	}

	if (StartApp_9183SpiTestEnabled == TRUE)
	{
		StartApp_Test9183Spi();
	}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: StartApp_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: StartApp_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, StartApp_CODE) StartApp_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: StartApp_Init
 *********************************************************************************************************************/
  (void)EcuM_RequestRUN(EcuMConf_EcuMFixedUserConfig_EcuMFixedUserConfig);
  ComM_CommunicationAllowed(ComMConf_ComMChannel_CN_CAN00_5e566ad9, TRUE);
  StartApp_ComMCommunicationAllowed = TRUE;
  StartApp_ComMRequestResult = ComM_RequestComMode(ComMConf_ComMUser_CN_CAN00_06ecbb07, COMM_FULL_COMMUNICATION);
  StartApp_9183SpiStatusBefore = Spi_GetStatus();
#if (STARTAPP_QSPI3_LOOPBACK_TEST != TRUE)
  Tle9183_Init();
  StartApp_9183HwInited = (boolean)(Tle9183_GetState() != TLE9183_STATE_UNINIT);
#endif
  StartApp_Test9183Spi();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define StartApp_STOP_SEC_CODE
#include "StartApp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_TestCode:
     Reason:     This justification is used as summary justification for all deviations caused by wrong analysis tool results.
                 The used analysis tool QAC 9.0 sometimes creates wrong messages. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/


