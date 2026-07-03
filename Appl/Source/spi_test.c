#include "Spi_test.h"

#include "Dio.h"
#include "Dio_Cfg.h"
#include "IfxPort_reg.h"
#include "IfxQspi_bf.h"
#include "IfxQspi_reg.h"
#include "Spi_Cfg.h"
#include "Spi_PBcfg.h"
#include "Tle9183.h"

/* Set to TRUE: loopback test without TLE9183. FALSE: normal 9183 register test. */
#define SPITEST_QSPI3_LOOPBACK_TEST           (False)
/* 1 = internal loopback (QSPI GLOBALCON.LB, no wire).
 * 0 = external loopback (short P22.0 to P22.1). */
#define SPITEST_QSPI3_LOOPBACK_USE_INTERNAL   (0U)
/* 1 = use 8-bit frame (change Spi_PBcfg DataConfig to 0x88U manually). */
#define SPITEST_QSPI3_LOOPBACK_USE_8BIT       (0U)

#define SPITEST_QSPI3_SPI_FRAME_MASK          (0x00FFFFFFU)
#if (SPITEST_QSPI3_LOOPBACK_USE_8BIT == 1U)
#define SPITEST_QSPI3_LOOPBACK_TX_PATTERN     (0x000000A5U)
#else
#define SPITEST_QSPI3_LOOPBACK_TX_PATTERN     (0x00A5A5A5U)
#endif

uint32 SpiTest_9183SpiTxWord = 0u;
uint32 SpiTest_9183SpiRxWord = 0u;
uint32 SpiTest_9183SpiPrevRxWord = 0u;
boolean SpiTest_9183HwInited = FALSE;
Std_ReturnType SpiTest_9183SpiSetupResult = E_NOT_OK;
Std_ReturnType SpiTest_9183SpiTransmitResult = E_NOT_OK;
Std_ReturnType SpiTest_9183SpiInitCheckResult = E_NOT_OK;
Spi_StatusType SpiTest_9183SpiStatusBefore = SPI_UNINIT;
Spi_StatusType SpiTest_9183SpiStatusAfter = SPI_UNINIT;
Spi_JobResultType SpiTest_9183SpiJobResultBefore = SPI_JOB_FAILED;
Spi_JobResultType SpiTest_9183SpiJobResultAfter = SPI_JOB_FAILED;
Spi_SeqResultType SpiTest_9183SpiSeqResult = SPI_SEQ_FAILED;
Spi_SeqResultType SpiTest_9183SpiSeqResultBefore = SPI_SEQ_FAILED;
uint32 SpiTest_9183SpiTestCounter = 0u;
uint32 SpiTest_9183SpiOkCounter = 0u;
uint32 SpiTest_9183SpiFailCounter = 0u;
boolean SpiTest_9183SpiRxChanged = FALSE;
boolean SpiTest_9183SpiTestEnabled = TRUE;
boolean SpiTest_9183SpiLoopbackMatch = FALSE;
boolean SpiTest_9183SpiLoopbackInternal = FALSE;
boolean SpiTest_9183MrstPinLevel = FALSE;
uint8 SpiTest_Qspi3BitCount = 0U;
uint32 SpiTest_Qspi3GlobalconLb = 0U;
uint32 SpiTest_Qspi3GlobalconLbBeforeTx = 0U;
Std_ReturnType SpiTest_Qspi3LoopbackCtrlResult = E_NOT_OK;
uint32 SpiTest_Qspi3Clc = 0u;
uint32 SpiTest_Qspi3Pisel = 0u;
uint32 SpiTest_Qspi3Globalcon = 0u;
uint32 SpiTest_Qspi3Globalcon1 = 0u;
uint32 SpiTest_Qspi3Bacon = 0u;
uint32 SpiTest_Qspi3Status = 0u;
uint32 SpiTest_Qspi3Status1 = 0u;
uint32 SpiTest_Qspi3Ssoc = 0u;

static void SpiTest_Test9183Spi(void);
static void SpiTest_Qspi3LoopbackTest(void);
static void SpiTest_SampleQspi3Regs(void);

void SpiTest_Init(void)
{
  SpiTest_9183SpiStatusBefore = Spi_GetStatus();
#if (SPITEST_QSPI3_LOOPBACK_TEST != TRUE)
  Tle9183_Init();
  SpiTest_9183HwInited = (boolean)(Tle9183_GetState() != TLE9183_STATE_UNINIT);
#endif
}

void SpiTest_RunOnce(void)
{
  if (SpiTest_9183SpiTestEnabled == TRUE)
  {
    SpiTest_Test9183Spi();
  }
}

static void SpiTest_SampleQspi3Regs(void)
{
  SpiTest_Qspi3Clc = QSPI3_CLC.U;
  SpiTest_Qspi3Pisel = QSPI3_PISEL.U;
  SpiTest_Qspi3Globalcon = QSPI3_GLOBALCON.U;
  SpiTest_Qspi3Globalcon1 = QSPI3_GLOBALCON1.U;
  SpiTest_Qspi3Bacon = QSPI3_BACON.U;
  SpiTest_Qspi3Status = QSPI3_STATUS.U;
  SpiTest_Qspi3Status1 = QSPI3_STATUS1.U;
  SpiTest_Qspi3Ssoc = QSPI3_SSOC.U;
}

static void SpiTest_Qspi3LoopbackTest(void)
{
  uint32 txWord = SPITEST_QSPI3_LOOPBACK_TX_PATTERN;
  uint32 rxWord = 0U;

  SpiTest_SampleQspi3Regs();
  SpiTest_9183SpiStatusBefore = Spi_GetStatus();
  SpiTest_9183SpiJobResultBefore =
      Spi_GetJobResult(SpiConf_SpiJob_SpiJob_9183);
  SpiTest_9183SpiSeqResultBefore =
      Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence);

  if (Spi_GetStatus() != SPI_IDLE)
  {
    return;
  }

#if (SPITEST_QSPI3_LOOPBACK_USE_INTERNAL == 1U)
  SpiTest_9183SpiLoopbackInternal = TRUE;
  SpiTest_Qspi3LoopbackCtrlResult =
      Spi_ControlLoopBack(SPI_QSPI3_INDEX, SPI_LOOPBACK_ENABLE);
#else
  SpiTest_9183SpiLoopbackInternal = FALSE;
  SpiTest_Qspi3LoopbackCtrlResult =
      Spi_ControlLoopBack(SPI_QSPI3_INDEX, SPI_LOOPBACK_DISABLE);
#endif

  SpiTest_Qspi3GlobalconLbBeforeTx = (uint32)QSPI3_GLOBALCON.B.LB;

  SpiTest_9183SpiSetupResult = Spi_SetupEB(
      SpiConf_SpiChannel_SpiChannel_9183,
      (const Spi_DataBufferType *)&txWord,
      (Spi_DataBufferType *)&rxWord,
      1U);

  if (SpiTest_9183SpiSetupResult == E_OK)
  {
    SpiTest_9183SpiTransmitResult =
        Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence);
    SpiTest_9183SpiSeqResult =
        Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence);
  }
  else
  {
    SpiTest_9183SpiTransmitResult = E_NOT_OK;
    SpiTest_9183SpiSeqResult = SPI_SEQ_FAILED;
  }

  (void)Spi_ControlLoopBack(SPI_QSPI3_INDEX, SPI_LOOPBACK_DISABLE);

  SpiTest_9183SpiTxWord = txWord & SPITEST_QSPI3_SPI_FRAME_MASK;
  SpiTest_9183SpiRxWord = rxWord & SPITEST_QSPI3_SPI_FRAME_MASK;
  SpiTest_9183MrstPinLevel =
      (boolean)((P22_IN.U & 0x00000002U) != 0U);
  SpiTest_9183SpiLoopbackMatch =
      (boolean)((SpiTest_9183SpiSetupResult == E_OK) &&
                (SpiTest_9183SpiTransmitResult == E_OK) &&
                (SpiTest_9183SpiSeqResult == SPI_SEQ_OK) &&
                (SpiTest_Qspi3LoopbackCtrlResult == E_OK) &&
                (SpiTest_Qspi3GlobalconLbBeforeTx == 1U) &&
                (SpiTest_9183SpiTxWord == SpiTest_9183SpiRxWord));

  SpiTest_9183SpiStatusAfter = Spi_GetStatus();
  SpiTest_9183SpiJobResultAfter =
      Spi_GetJobResult(SpiConf_SpiJob_SpiJob_9183);
  SpiTest_SampleQspi3Regs();
  SpiTest_Qspi3BitCount = (uint8)(SpiTest_Qspi3Status1 & 0x000000FFU);
  SpiTest_Qspi3GlobalconLb = (uint32)QSPI3_GLOBALCON.B.LB;

  SpiTest_9183SpiRxChanged =
      (boolean)(SpiTest_9183SpiPrevRxWord != SpiTest_9183SpiRxWord);
  SpiTest_9183SpiPrevRxWord = SpiTest_9183SpiRxWord;

  SpiTest_9183SpiTestCounter++;
  if (SpiTest_9183SpiLoopbackMatch == TRUE)
  {
    SpiTest_9183SpiOkCounter++;
  }
  else
  {
    SpiTest_9183SpiFailCounter++;
  }
}

static void SpiTest_Test9183Spi(void)
{
#if (SPITEST_QSPI3_LOOPBACK_TEST == TRUE)
  SpiTest_Qspi3LoopbackTest();
#else
  uint8 nopData = 0U;

  SpiTest_SampleQspi3Regs();
  SpiTest_9183SpiStatusBefore = Spi_GetStatus();
  SpiTest_9183SpiJobResultBefore =
      Spi_GetJobResult(SpiConf_SpiJob_SpiJob_9183);
  SpiTest_9183SpiSeqResultBefore =
      Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence);

  Tle9183_MainFunction();

  if (Tle9183_Status.PowerUpDone == FALSE)
  {
    return;
  }

  SpiTest_9183SpiSetupResult = Tle9183_ReadRegister(TLE9183_REG_NOP, &nopData);
  SpiTest_9183SpiTxWord = Tle9183_Status.LastTxFrame;
  SpiTest_9183SpiRxWord = Tle9183_Status.LastRxFrame;

  if (SpiTest_9183SpiSetupResult == E_OK)
  {
    SpiTest_9183SpiTransmitResult = E_OK;
    SpiTest_9183SpiSeqResult = SPI_SEQ_OK;
  }
  else
  {
    SpiTest_9183SpiTransmitResult = E_NOT_OK;
    SpiTest_9183SpiSeqResult = SPI_SEQ_FAILED;
  }

  SpiTest_9183SpiStatusAfter = Spi_GetStatus();
  SpiTest_9183SpiJobResultAfter =
      Spi_GetJobResult(SpiConf_SpiJob_SpiJob_9183);
  SpiTest_SampleQspi3Regs();

  SpiTest_9183SpiRxChanged =
      (boolean)(SpiTest_9183SpiPrevRxWord != SpiTest_9183SpiRxWord);
  SpiTest_9183SpiPrevRxWord = SpiTest_9183SpiRxWord;

  SpiTest_9183SpiTestCounter++;
  if ((SpiTest_9183SpiSetupResult == E_OK) &&
      (SpiTest_9183SpiTransmitResult == E_OK) &&
      (SpiTest_9183SpiSeqResult == SPI_SEQ_OK) &&
      (Tle9183_Status.LastCrcOk == TRUE))
  {
    SpiTest_9183SpiOkCounter++;
  }
  else
  {
    SpiTest_9183SpiFailCounter++;
  }
#endif
}
