/*
 * @Author: qinXiong
 * @Date: 2026-07-06 17:22:42
 * @LastEditors: Qxiong&&2307975018@qq.com
 * @LastEditTime: 2026-07-26 16:21:01
 * @Description: 
 */
/**********************************************************************************************************************
 * TLE5012BD QSPI2 synchronous transfer service
 **********************************************************************************************************************/
#include "Tle5012bd_Spi.h"
#include "Spi.h"
#include "Spi_Cfg.h"
#include "McalLib.h"
#include "Dio.h"
uint32 Tle5012bd_SpiLastTxWord = 0U;
uint32 Tle5012bd_SpiLastRxWord = 0U;
Std_ReturnType Tle5012bd_SpiLastResult = E_NOT_OK;
Std_ReturnType Tle5012bd_SpiLastSetupResult = E_NOT_OK;
Std_ReturnType Tle5012bd_SpiLastTransmitResult = E_NOT_OK;

static uint32 Tle5012bd_SpiTxBuf;
static uint32 Tle5012bd_SpiRxBuf;
static uint8 Tle5012bd_SpiPending = 0U;


Std_ReturnType Tle5012bd_SpiKickU32(uint32 txWord)
{
//  Dio_WriteChannel(DioConf_DioChannel_DioChannel_test2, STD_HIGH);
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
//  Dio_WriteChannel(DioConf_DioChannel_DioChannel_test2, STD_HIGH);
  Tle5012bd_SpiLastTransmitResult = Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_5012BD); //Spi_ASyncTransmit The execution took 56 microseconds.
//  Dio_WriteChannel(DioConf_DioChannel_DioChannel_test2, STD_LOW);
  if (Tle5012bd_SpiLastTransmitResult != E_OK) { return E_NOT_OK; }

  /* Sync transfer is complete; let the next driver call consume this frame. */
  Tle5012bd_SpiPending = 1U;
//  Dio_WriteChannel(DioConf_DioChannel_DioChannel_test2, STD_LOW);
  return E_OK;
}

Spi_SeqResultType Tle5012bd_SpiPollU32(uint32 *rxWord)
{
  if ((rxWord == NULL_PTR) || (Tle5012bd_SpiPending == 0U))
  {
    return SPI_SEQ_FAILED;
  }

  /* Spi_SyncTransmit completed in Kick; publish the completed frame once. */
  Tle5012bd_SpiPending = 0U;
  *rxWord = Tle5012bd_SpiRxBuf;
  Tle5012bd_SpiLastRxWord = Tle5012bd_SpiRxBuf;
  Tle5012bd_SpiLastResult = E_OK;
  return SPI_SEQ_OK;
}
/* Synchronous exchange helper for initialization and configuration accesses. */
Std_ReturnType Tle5012bd_SpiExchangeU32(uint32 txWord, uint32 *rxWord)
{
  Spi_SeqResultType result;
  if ((rxWord == NULL_PTR) || (Tle5012bd_SpiKickU32(txWord) != E_OK)) { return E_NOT_OK; }
  do { result = Tle5012bd_SpiPollU32(rxWord); } while (result == SPI_SEQ_PENDING);
  return (result == SPI_SEQ_OK) ? E_OK : E_NOT_OK;
}
