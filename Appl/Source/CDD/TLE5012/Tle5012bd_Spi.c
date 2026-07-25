/**********************************************************************************************************************
 * TLE5012BD QSPI2 asynchronous transfer service
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

static uint32 Tle5012bd_SpiTxBuf;
static uint32 Tle5012bd_SpiRxBuf;
static uint8 Tle5012bd_SpiPending = 0U;
static uint32 Tle5012bd_SpiStartTick = 0U;

#define TLE5012BD_SPI_ASYNC_TIMEOUT_US (250UL)

static uint32 Tle5012bd_SpiTimeoutTicks(void)
{
  uint32 resolution = Mcal_DelayTickResolution();
  uint32 ticks;
  if (resolution == 0U) { resolution = Mcal_DelayResetTickCalibration(); }
  if (resolution == 0U) { resolution = 10U; }
  ticks = (TLE5012BD_SPI_ASYNC_TIMEOUT_US * 1000UL) / resolution;
  return (ticks == 0U) ? 1U : ticks;
}

Std_ReturnType Tle5012bd_SpiKickU32(uint32 txWord)
{
  if (Tle5012bd_SpiPending != 0U) { return E_NOT_OK; }

  Tle5012bd_SpiLastTxWord = txWord;
  Tle5012bd_SpiLastRxWord = 0U;
  Tle5012bd_SpiLastResult = E_NOT_OK;
  Tle5012bd_SpiTxBuf = txWord;
  Tle5012bd_SpiRxBuf = 0U;
  Tle5012bd_SpiLastSetupResult = Spi_SetupEB(SpiConf_SpiChannel_SpiChannel_5012BD1,
      (const Spi_DataBufferType *)&Tle5012bd_SpiTxBuf,
      (Spi_DataBufferType *)&Tle5012bd_SpiRxBuf, 1U);
  if (Tle5012bd_SpiLastSetupResult != E_OK) { return E_NOT_OK; }

  Tle5012bd_SpiLastTransmitResult = Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_5012BD);
  if (Tle5012bd_SpiLastTransmitResult != E_OK) { return E_NOT_OK; }

  Tle5012bd_SpiStartTick = Mcal_DelayGetTick();
  Tle5012bd_SpiPending = 1U;
  return E_OK;
}

Spi_SeqResultType Tle5012bd_SpiPollU32(uint32 *rxWord)
{
  Spi_SeqResultType result;
  if ((rxWord == NULL_PTR) || (Tle5012bd_SpiPending == 0U)) { return SPI_SEQ_FAILED; }

  result = Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_5012BD);
  if (result == SPI_SEQ_PENDING)
  {
    if ((Mcal_DelayGetTick() - Tle5012bd_SpiStartTick) < Tle5012bd_SpiTimeoutTicks())
    {
      return SPI_SEQ_PENDING;
    }
    (void)Spi_Cancel(SpiConf_SpiSequence_SpiSequence_5012BD);
    Tle5012bd_SpiPending = 0U;
    Tle5012bd_SpiLastResult = E_NOT_OK;
    return SPI_SEQ_FAILED;
  }

  Tle5012bd_SpiPending = 0U;
  if (result == SPI_SEQ_OK)
  {
    *rxWord = Tle5012bd_SpiRxBuf;
    Tle5012bd_SpiLastRxWord = Tle5012bd_SpiRxBuf;
    Tle5012bd_SpiLastResult = E_OK;
  }
  else { Tle5012bd_SpiLastResult = E_NOT_OK; }
  return result;
}

/* This legacy blocking API remains for non-motor configuration accesses only. */
Std_ReturnType Tle5012bd_SpiExchangeU32(uint32 txWord, uint32 *rxWord)
{
  Spi_SeqResultType result;
  if ((rxWord == NULL_PTR) || (Tle5012bd_SpiKickU32(txWord) != E_OK)) { return E_NOT_OK; }
  do { result = Tle5012bd_SpiPollU32(rxWord); } while (result == SPI_SEQ_PENDING);
  return (result == SPI_SEQ_OK) ? E_OK : E_NOT_OK;
}
