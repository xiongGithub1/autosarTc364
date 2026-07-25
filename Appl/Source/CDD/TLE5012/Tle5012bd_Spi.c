/**********************************************************************************************************************
 *  Tle5012bd_Spi.c - TLE5012BD: Spi Async+DMA, QSPI2 interrupt completion (no MainFunction polling)
 *
 *  EcuM sets SPI_INTERRUPT_MODE after Spi_Init. Sequence completion is driven by QSPI2/DMA ISRs.
 *  This module only checks Spi_GetSequenceResult — never calls Spi_MainFunction_Handling.
 *
 *  Task blocking:     SpiExchangeU32  (calibration / tle5012b_read_angle)
 *  Task non-blocking: StartExchange → PollExchange → TakeRxWord  (1 ms angle service)
 **********************************************************************************************************************/
#include "Tle5012bd_Spi.h"

#include "Spi.h"
#include "Spi_Cfg.h"
#include "McalLib.h"

uint32 Tle5012bd_SpiLastTxWord = 0U;
uint32 Tle5012bd_SpiLastRxWord = 0U;
Std_ReturnType Tle5012bd_SpiLastResult = E_NOT_OK;
Std_ReturnType Tle5012bd_SpiLastSetupResult = E_NOT_OK;
Std_ReturnType Tle5012bd_SpiLastTransmitResult = E_NOT_OK;
volatile Tle5012bd_SpiXferStateType Tle5012bd_SpiXferState = TLE5012BD_SPI_XFER_IDLE;

static uint32 Tle5012bd_SpiTxBuf;
static uint32 Tle5012bd_SpiRxBuf;

#define TLE5012BD_SPI_BLOCK_TIMEOUT_US   (2000UL)

static Std_ReturnType Tle5012bd_SpiTakeRxWordInternal(uint32 *rxWord);

static void Tle5012bd_SpiWaitUs(uint32 delayUs)
{
  uint32 resolution = Mcal_DelayTickResolution();
  uint32 targetTicks;
  uint32 startTick;

  if (resolution == 0U)
  {
    resolution = Mcal_DelayResetTickCalibration();
  }
  if (resolution == 0U)
  {
    volatile uint32 i;
    for (i = 0U; i < (delayUs * 200U); i++)
    {
    }
    return;
  }

  targetTicks = (delayUs * 1000UL) / resolution;
  if (targetTicks == 0U)
  {
    targetTicks = 1U;
  }
  startTick = Mcal_DelayGetTick();
  while ((Mcal_DelayGetTick() - startTick) < targetTicks)
  {
  }
}

static Std_ReturnType Tle5012bd_SpiWaitSeqDone(uint32 timeoutUs)
{
  uint32 resolution;
  uint32 targetTicks;
  uint32 startTick;
  Spi_SeqResultType seqResult;

  /* IPB-style pure spin: DMA/QSPI ISR must be able to preempt this context. */
  resolution = Mcal_DelayTickResolution();
  if (resolution == 0U)
  {
    resolution = Mcal_DelayResetTickCalibration();
  }
  if (resolution == 0U)
  {
    resolution = 10U;
  }

  targetTicks = (timeoutUs * 1000UL) / resolution;
  if (targetTicks == 0U)
  {
    targetTicks = 1U;
  }

  startTick = Mcal_DelayGetTick();
  do
  {
    seqResult = Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_5012BD);
    if (seqResult == SPI_SEQ_OK)
    {
      return E_OK;
    }
    if ((seqResult == SPI_SEQ_FAILED) || (seqResult == SPI_SEQ_CANCELED))
    {
      return E_NOT_OK;
    }
  } while ((Mcal_DelayGetTick() - startTick) < targetTicks);

  if (Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_5012BD) == SPI_SEQ_PENDING)
  {
    Spi_Cancel(SpiConf_SpiSequence_SpiSequence_5012BD);
  }
  return E_NOT_OK;
}

static Std_ReturnType Tle5012bd_SpiLaunchExchangeU32(uint32 txWord)
{
  Tle5012bd_SpiLastTxWord = txWord;
  Tle5012bd_SpiLastRxWord = 0U;
  Tle5012bd_SpiLastResult = E_NOT_OK;
  Tle5012bd_SpiLastSetupResult = E_NOT_OK;
  Tle5012bd_SpiLastTransmitResult = E_NOT_OK;

  Tle5012bd_SpiTxBuf = txWord;
  Tle5012bd_SpiRxBuf = 0U;

  Tle5012bd_SpiLastSetupResult = Spi_SetupEB(
      SpiConf_SpiChannel_SpiChannel_5012BD1,
      (const Spi_DataBufferType *)&Tle5012bd_SpiTxBuf,
      (Spi_DataBufferType *)&Tle5012bd_SpiRxBuf,
      1U);
  if (Tle5012bd_SpiLastSetupResult != E_OK)
  {
    Tle5012bd_SpiXferState = TLE5012BD_SPI_XFER_FAIL;
    return E_NOT_OK;
  }

  Tle5012bd_SpiLastTransmitResult =
      Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_5012BD);
  if (Tle5012bd_SpiLastTransmitResult != E_OK)
  {
    Tle5012bd_SpiXferState = TLE5012BD_SPI_XFER_FAIL;
    return E_NOT_OK;
  }

  Tle5012bd_SpiXferState = TLE5012BD_SPI_XFER_PENDING;
  return E_OK;
}

static Std_ReturnType Tle5012bd_SpiTakeRxWordInternal(uint32 *rxWord)
{
  Std_ReturnType result = Tle5012bd_SpiLastResult;

  if (rxWord == NULL_PTR)
  {
    return E_NOT_OK;
  }

  *rxWord = Tle5012bd_SpiLastRxWord;
  Tle5012bd_SpiXferState = TLE5012BD_SPI_XFER_IDLE;
  return result;
}

Std_ReturnType Tle5012bd_SpiExchangeU32(uint32 txWord, uint32 *rxWord)
{
  if (rxWord == NULL_PTR)
  {
    return E_NOT_OK;
  }

  if (Tle5012bd_SpiXferState == TLE5012BD_SPI_XFER_PENDING)
  {
    Spi_Cancel(SpiConf_SpiSequence_SpiSequence_5012BD);
    (void)Tle5012bd_SpiWaitSeqDone(TLE5012BD_SPI_BLOCK_TIMEOUT_US);
  }
  else if (Tle5012bd_SpiXferState != TLE5012BD_SPI_XFER_IDLE)
  {
    uint32 dropRx;

    (void)Tle5012bd_SpiTakeRxWordInternal(&dropRx);
  }

  if (Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_5012BD) == SPI_SEQ_PENDING)
  {
    Spi_Cancel(SpiConf_SpiSequence_SpiSequence_5012BD);
    (void)Tle5012bd_SpiWaitSeqDone(TLE5012BD_SPI_BLOCK_TIMEOUT_US);
  }

  if (Tle5012bd_SpiLaunchExchangeU32(txWord) != E_OK)
  {
    Spi_Cancel(SpiConf_SpiSequence_SpiSequence_5012BD);
    (void)Tle5012bd_SpiWaitSeqDone(500U);
    if (Tle5012bd_SpiLaunchExchangeU32(txWord) != E_OK)
    {
      return E_NOT_OK;
    }
  }

  if (Tle5012bd_SpiWaitSeqDone(TLE5012BD_SPI_BLOCK_TIMEOUT_US) != E_OK)
  {
    Tle5012bd_SpiXferState = TLE5012BD_SPI_XFER_FAIL;
    Tle5012bd_SpiLastResult = E_NOT_OK;
    return E_NOT_OK;
  }

  *rxWord = Tle5012bd_SpiRxBuf;
  Tle5012bd_SpiLastRxWord = Tle5012bd_SpiRxBuf;
  Tle5012bd_SpiLastResult = E_OK;
  Tle5012bd_SpiXferState = TLE5012BD_SPI_XFER_IDLE;
  return E_OK;
}

Std_ReturnType Tle5012bd_SpiStartExchangeU32(uint32 txWord)
{
  if (Tle5012bd_SpiXferState != TLE5012BD_SPI_XFER_IDLE)
  {
    return E_NOT_OK;
  }

  if (Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_5012BD) == SPI_SEQ_PENDING)
  {
    return E_NOT_OK;
  }

  return Tle5012bd_SpiLaunchExchangeU32(txWord);
}

Tle5012bd_SpiXferStateType Tle5012bd_SpiPollExchange(void)
{
  Spi_SeqResultType seqResult;

  if (Tle5012bd_SpiXferState != TLE5012BD_SPI_XFER_PENDING)
  {
    return Tle5012bd_SpiXferState;
  }

  seqResult = Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_5012BD);
  if (seqResult == SPI_SEQ_OK)
  {
    Tle5012bd_SpiLastRxWord = Tle5012bd_SpiRxBuf;
    Tle5012bd_SpiLastResult = E_OK;
    Tle5012bd_SpiXferState = TLE5012BD_SPI_XFER_OK;
  }
  else if ((seqResult == SPI_SEQ_FAILED) || (seqResult == SPI_SEQ_CANCELED))
  {
    Tle5012bd_SpiLastResult = E_NOT_OK;
    Tle5012bd_SpiXferState = TLE5012BD_SPI_XFER_FAIL;
  }
  else
  {
    /* SPI_SEQ_PENDING: hardware ISR still running. */
  }

  return Tle5012bd_SpiXferState;
}

Std_ReturnType Tle5012bd_SpiTakeRxWord(uint32 *rxWord)
{
  return Tle5012bd_SpiTakeRxWordInternal(rxWord);
}
