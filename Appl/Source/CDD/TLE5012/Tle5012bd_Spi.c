/**********************************************************************************************************************
 *  Tle5012bd_Spi.c - TLE5012BD SPI over Spi MCAL Sync (32-bit EB frame, QSPI2)
 **********************************************************************************************************************/
#include "Tle5012bd_Spi.h"

#include "Spi.h"
#include "Spi_Cfg.h"

uint32 Tle5012bd_SpiLastTxWord = 0U;
uint32 Tle5012bd_SpiLastRxWord = 0U;
Std_ReturnType Tle5012bd_SpiLastResult = E_NOT_OK;
Std_ReturnType Tle5012bd_SpiLastSetupResult = E_NOT_OK;
Std_ReturnType Tle5012bd_SpiLastTransmitResult = E_NOT_OK;

static uint32 Tle5012bd_SpiTxBuf;
static uint32 Tle5012bd_SpiRxBuf;

Std_ReturnType Tle5012bd_SpiExchangeU32(uint32 txWord, uint32 *rxWord)
{
  Tle5012bd_SpiLastTxWord = txWord;
  Tle5012bd_SpiLastRxWord = 0U;
  Tle5012bd_SpiLastResult = E_NOT_OK;
  Tle5012bd_SpiLastSetupResult = E_NOT_OK;
  Tle5012bd_SpiLastTransmitResult = E_NOT_OK;

  if (rxWord == NULL_PTR)
  {
    return E_NOT_OK;
  }

  Tle5012bd_SpiTxBuf = txWord;
  Tle5012bd_SpiRxBuf = 0U;

  Tle5012bd_SpiLastSetupResult = Spi_SetupEB(
      SpiConf_SpiChannel_SpiChannel_5012BD1,
      (const Spi_DataBufferType *)&Tle5012bd_SpiTxBuf,
      (Spi_DataBufferType *)&Tle5012bd_SpiRxBuf,
      1U);

  if (Tle5012bd_SpiLastSetupResult != E_OK)
  {
    return E_NOT_OK;
  }

  Tle5012bd_SpiLastTransmitResult =
      Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_5012BD);
  if (Tle5012bd_SpiLastTransmitResult != E_OK)
  {
    return E_NOT_OK;
  }

  Tle5012bd_SpiLastRxWord = Tle5012bd_SpiRxBuf;
  *rxWord = Tle5012bd_SpiLastRxWord;
  Tle5012bd_SpiLastResult = E_OK;
  return E_OK;
}
