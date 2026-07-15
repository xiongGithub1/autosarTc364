#include "Spi_test.h"

#include "Dio.h"
#include "Dio_Cfg.h"
#include "IfxPort_reg.h"
#include "IfxQspi_bf.h"
#include "IfxQspi_reg.h"
#include "Spi_Cfg.h"
#include "Spi_PBcfg.h"

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

uint32 SpiTest_TxWord = 0u;
uint32 SpiTest_RxWord = 0u;
uint32 SpiTest_PrevRxWord = 0u;
Std_ReturnType SpiTest_SetupResult = E_NOT_OK;
Std_ReturnType SpiTest_TransmitResult = E_NOT_OK;
Spi_StatusType SpiTest_StatusBefore = SPI_UNINIT;
Spi_StatusType SpiTest_StatusAfter = SPI_UNINIT;
Spi_JobResultType SpiTest_JobResultBefore = SPI_JOB_FAILED;
Spi_JobResultType SpiTest_JobResultAfter = SPI_JOB_FAILED;
Spi_SeqResultType SpiTest_SeqResult = SPI_SEQ_FAILED;
Spi_SeqResultType SpiTest_SeqResultBefore = SPI_SEQ_FAILED;
uint32 SpiTest_TestCounter = 0u;
uint32 SpiTest_OkCounter = 0u;
uint32 SpiTest_FailCounter = 0u;
boolean SpiTest_RxChanged = FALSE;
boolean SpiTest_Enabled = TRUE;
boolean SpiTest_LoopbackMatch = FALSE;
boolean SpiTest_LoopbackInternal = FALSE;
boolean SpiTest_MrstPinLevel = FALSE;
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

static void SpiTest_Qspi3LoopbackTest(void);
static void SpiTest_SampleQspi3Regs(void);

void SpiTest_Init(void)
{
  SpiTest_StatusBefore = Spi_GetStatus();
}

void SpiTest_RunOnce(void)
{
  if (SpiTest_Enabled == TRUE)
  {
    SpiTest_Qspi3LoopbackTest();
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
  SpiTest_StatusBefore = Spi_GetStatus();
  SpiTest_JobResultBefore =
      Spi_GetJobResult(SpiConf_SpiJob_SpiJob_9183);
  SpiTest_SeqResultBefore =
      Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_9183);

  if (Spi_GetStatus() != SPI_IDLE)
  {
    return;
  }

#if (SPITEST_QSPI3_LOOPBACK_USE_INTERNAL == 1U)
  SpiTest_LoopbackInternal = TRUE;
  SpiTest_Qspi3LoopbackCtrlResult =
      Spi_ControlLoopBack(SPI_QSPI3_INDEX, SPI_LOOPBACK_ENABLE);
#else
  SpiTest_LoopbackInternal = FALSE;
  SpiTest_Qspi3LoopbackCtrlResult =
      Spi_ControlLoopBack(SPI_QSPI3_INDEX, SPI_LOOPBACK_DISABLE);
#endif

  SpiTest_Qspi3GlobalconLbBeforeTx = (uint32)QSPI3_GLOBALCON.B.LB;

  SpiTest_SetupResult = Spi_SetupEB(
      SpiConf_SpiChannel_SpiChannel_9183,
      (const Spi_DataBufferType *)&txWord,
      (Spi_DataBufferType *)&rxWord,
      1U);

  if (SpiTest_SetupResult == E_OK)
  {
    SpiTest_TransmitResult =
        Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_9183);
    SpiTest_SeqResult =
        Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_9183);
  }
  else
  {
    SpiTest_TransmitResult = E_NOT_OK;
    SpiTest_SeqResult = SPI_SEQ_FAILED;
  }

  (void)Spi_ControlLoopBack(SPI_QSPI3_INDEX, SPI_LOOPBACK_DISABLE);

  SpiTest_TxWord = txWord & SPITEST_QSPI3_SPI_FRAME_MASK;
  SpiTest_RxWord = rxWord & SPITEST_QSPI3_SPI_FRAME_MASK;
  SpiTest_MrstPinLevel = (boolean)((P22_IN.U & 0x00000002U) != 0U);
  SpiTest_LoopbackMatch =
      (boolean)((SpiTest_SetupResult == E_OK) &&
                (SpiTest_TransmitResult == E_OK) &&
                (SpiTest_SeqResult == SPI_SEQ_OK) &&
                (SpiTest_Qspi3LoopbackCtrlResult == E_OK) &&
                (SpiTest_TxWord == SpiTest_RxWord));

  SpiTest_StatusAfter = Spi_GetStatus();
  SpiTest_JobResultAfter =
      Spi_GetJobResult(SpiConf_SpiJob_SpiJob_9183);
  SpiTest_SampleQspi3Regs();
  SpiTest_Qspi3BitCount = (uint8)(SpiTest_Qspi3Status1 & 0x000000FFU);
  SpiTest_Qspi3GlobalconLb = (uint32)QSPI3_GLOBALCON.B.LB;

  SpiTest_RxChanged = (boolean)(SpiTest_PrevRxWord != SpiTest_RxWord);
  SpiTest_PrevRxWord = SpiTest_RxWord;

  SpiTest_TestCounter++;
  if (SpiTest_LoopbackMatch == TRUE)
  {
    SpiTest_OkCounter++;
  }
  else
  {
    SpiTest_FailCounter++;
  }
}
