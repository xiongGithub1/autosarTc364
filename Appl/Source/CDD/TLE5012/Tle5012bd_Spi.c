/**********************************************************************************************************************
 *  Tle5012bd_Spi.c - TLE5012BD SPI over Spi MCAL (32-bit EB frame)
 **********************************************************************************************************************/
#include "Tle5012bd_Spi.h"

#include "Appl_SpiDmaHwInit.h"
#include "Dma.h"
#include "IfxQspi_reg.h"
#include "McalLib.h"
#include "Spi.h"
#include "Spi_Cfg.h"

#define TLE5012BD_SPI_WAIT_TIMEOUT_US  (1000U)
#define TLE5012BD_DMA_RX_CH            (1U) /* must match Spi/Dma/Irq QSPI2 RX */

uint32 Tle5012bd_SpiLastTxWord = 0U;
uint32 Tle5012bd_SpiLastRxWord = 0U;
uint16 Tle5012bd_SpiLastTxWords[2] = {0U, 0U};
uint16 Tle5012bd_SpiLastRxWords[2] = {0U, 0U};
Std_ReturnType Tle5012bd_SpiLastResult = E_NOT_OK;
Std_ReturnType Tle5012bd_SpiLastSetupResult = E_NOT_OK;
Std_ReturnType Tle5012bd_SpiLastTransmitResult = E_NOT_OK;
Spi_SeqResultType Tle5012bd_SpiLastSeqResult = SPI_SEQ_FAILED;
Spi_StatusType Tle5012bd_SpiStatusBefore = SPI_UNINIT;
Spi_StatusType Tle5012bd_SpiStatusAfter = SPI_UNINIT;

uint32 Tle5012bd_SpiLastRxFifoLev = 0U;
uint32 Tle5012bd_SpiLastTxFifoLev = 0U;
uint32 Tle5012bd_SpiDmaRxEvents = 0U;
boolean Tle5012bd_SpiCpuRxDrainUsed = FALSE;

static uint32 Tle5012bd_SpiTxBuf;
static uint32 Tle5012bd_SpiRxBuf;

static void Tle5012bd_SpiCaptureHwDiag(void)
{
  Tle5012bd_SpiLastRxFifoLev = (uint32)QSPI2_STATUS.B.RXFIFOLEVEL;
  Tle5012bd_SpiLastTxFifoLev = (uint32)QSPI2_STATUS.B.TXFIFOLEVEL;
  Tle5012bd_SpiDmaRxEvents = Dma_GetEvents(TLE5012BD_DMA_RX_CH);
}

/*
 * Hardware already filled RXFIFO but RX DMA did not move it to EB →
 * MainFunction never sees DMA TC → Wait times out.
 * Drain RXEXIT by CPU so bring-up can get data and FIFO is not stuck.
 */
static Std_ReturnType Tle5012bd_SpiCpuDrainRxFifo(uint32 *lastWord)
{
  uint32 word = 0U;
  uint8 lev;
  uint8 i;

  Tle5012bd_SpiCpuRxDrainUsed = FALSE;
  lev = (uint8)QSPI2_STATUS.B.RXFIFOLEVEL;
  if (lev == 0U)
  {
    return E_NOT_OK;
  }

  for (i = 0U; i < lev; i++)
  {
    word = QSPI2_RXEXIT.U;
  }

  *lastWord = word;
  Tle5012bd_SpiCpuRxDrainUsed = TRUE;
  return E_OK;
}

static Std_ReturnType Tle5012bd_SpiWaitSeqDone(void)
{
  uint32 resolution;
  uint32 startTick;
  uint32 targetTicks;
  uint32 drainedWord;
  Spi_SeqResultType seqResult;

  resolution = Mcal_DelayTickResolution();
  if (resolution == 0U)
  {
    resolution = Mcal_DelayResetTickCalibration();
  }

  if (resolution == 0U)
  {
    volatile uint32 spin;

    for (spin = 0U; spin < 50000UL; spin++)
    {
      Spi_MainFunction_Handling();
      seqResult = Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_5012BD);
      if (seqResult != SPI_SEQ_PENDING)
      {
        return (seqResult == SPI_SEQ_OK) ? E_OK : E_NOT_OK;
      }
    }
    Tle5012bd_SpiCaptureHwDiag();
    if (Tle5012bd_SpiCpuDrainRxFifo(&drainedWord) == E_OK)
    {
      Tle5012bd_SpiRxBuf = drainedWord;
      Appl_SpiBusRecover();
      return E_OK;
    }
    Appl_SpiBusRecover();
    return E_NOT_OK;
  }

  startTick = Mcal_DelayGetTick();
  targetTicks = (TLE5012BD_SPI_WAIT_TIMEOUT_US * 1000UL) / resolution;
  if (targetTicks == 0U)
  {
    targetTicks = 1U;
  }

  do
  {
    Spi_MainFunction_Handling();
    seqResult = Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_5012BD);
    if (seqResult != SPI_SEQ_PENDING)
    {
      return (seqResult == SPI_SEQ_OK) ? E_OK : E_NOT_OK;
    }
  } while ((Mcal_DelayGetTick() - startTick) < targetTicks);

  Tle5012bd_SpiCaptureHwDiag();
  if (Tle5012bd_SpiCpuDrainRxFifo(&drainedWord) == E_OK)
  {
    Tle5012bd_SpiRxBuf = drainedWord;
    Appl_SpiBusRecover();
    return E_OK;
  }

  Appl_SpiBusRecover();
  return E_NOT_OK;
}

Std_ReturnType Tle5012bd_SpiExchangeU32(uint32 txWord, uint32 *rxWord)
{
  Tle5012bd_SpiLastTxWord = txWord;
  Tle5012bd_SpiLastRxWord = 0U;
  Tle5012bd_SpiLastTxWords[0] = 0U;
  Tle5012bd_SpiLastTxWords[1] = 0U;
  Tle5012bd_SpiLastRxWords[0] = 0U;
  Tle5012bd_SpiLastRxWords[1] = 0U;
  Tle5012bd_SpiLastResult = E_NOT_OK;
  Tle5012bd_SpiLastSetupResult = E_NOT_OK;
  Tle5012bd_SpiLastTransmitResult = E_NOT_OK;
  Tle5012bd_SpiLastSeqResult = SPI_SEQ_FAILED;
  Tle5012bd_SpiCpuRxDrainUsed = FALSE;

  if (rxWord == NULL_PTR)
  {
    return E_NOT_OK;
  }

  Tle5012bd_SpiStatusBefore = Spi_GetHWUnitStatus(SPI_QSPI2_INDEX);
  if (Tle5012bd_SpiStatusBefore != SPI_IDLE)
  {
    Appl_SpiBusRecover();
    Tle5012bd_SpiStatusBefore = Spi_GetHWUnitStatus(SPI_QSPI2_INDEX);
    if (Tle5012bd_SpiStatusBefore != SPI_IDLE)
    {
      Tle5012bd_SpiStatusAfter = Tle5012bd_SpiStatusBefore;
      return E_NOT_OK;
    }
  }

  Tle5012bd_SpiTxBuf = txWord;
  Tle5012bd_SpiRxBuf = 0U;
  Tle5012bd_SpiLastTxWords[0] = (uint16)((txWord >> 16U) & 0xFFFFU);
  Tle5012bd_SpiLastTxWords[1] = (uint16)(txWord & 0xFFFFU);

  Tle5012bd_SpiLastSetupResult = Spi_SetupEB(
      SpiConf_SpiChannel_SpiChannel_5012BD1,
      (const Spi_DataBufferType *)&Tle5012bd_SpiTxBuf,
      (Spi_DataBufferType *)&Tle5012bd_SpiRxBuf,
      1U);

  if (Tle5012bd_SpiLastSetupResult != E_OK)
  {
    Tle5012bd_SpiStatusAfter = Spi_GetHWUnitStatus(SPI_QSPI2_INDEX);
    return E_NOT_OK;
  }

  Tle5012bd_SpiLastTransmitResult =
      Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_5012BD);
  if (Tle5012bd_SpiLastTransmitResult != E_OK)
  {
    Tle5012bd_SpiLastSeqResult =
        Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_5012BD);
    Tle5012bd_SpiStatusAfter = Spi_GetHWUnitStatus(SPI_QSPI2_INDEX);
    return E_NOT_OK;
  }

  if (Tle5012bd_SpiWaitSeqDone() != E_OK)
  {
    Tle5012bd_SpiLastSeqResult =
        Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_5012BD);
    Tle5012bd_SpiStatusAfter = Spi_GetHWUnitStatus(SPI_QSPI2_INDEX);
    return E_NOT_OK;
  }

  Tle5012bd_SpiLastSeqResult =
      Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_5012BD);
  Tle5012bd_SpiLastRxWord = Tle5012bd_SpiRxBuf;
  Tle5012bd_SpiLastRxWords[0] = (uint16)((Tle5012bd_SpiRxBuf >> 16U) & 0xFFFFU);
  Tle5012bd_SpiLastRxWords[1] = (uint16)(Tle5012bd_SpiRxBuf & 0xFFFFU);
  *rxWord = Tle5012bd_SpiLastRxWord;
  Tle5012bd_SpiStatusAfter = Spi_GetHWUnitStatus(SPI_QSPI2_INDEX);

  /* CPU drain rescue: Seq may be CANCELED after recover, but RxBuf is valid. */
  if (Tle5012bd_SpiCpuRxDrainUsed == TRUE)
  {
    Tle5012bd_SpiLastResult = E_OK;
    return E_OK;
  }

  if (Tle5012bd_SpiLastSeqResult != SPI_SEQ_OK)
  {
    return E_NOT_OK;
  }

  Tle5012bd_SpiLastResult = E_OK;
  return E_OK;
}
