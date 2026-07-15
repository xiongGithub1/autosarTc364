/**********************************************************************************************************************
 *  Tle9180_AutosarPort.c
 **********************************************************************************************************************/
#include "Tle9180_AutosarPort.h"

#include "Appl_SpiDmaHwInit.h"
#include "Dio.h"
#include "Dio_Cfg.h"
#include "McalLib.h"
#include "Spi.h"
#include "Spi_Cfg.h"

#define TLE9180_SPI_FRAME_MASK       (0x00FFFFFFU)
#define TLE9180_SPI_WAIT_TIMEOUT_US  (2000U)

static uint32 Tle9180_SpiTxBuf;
static uint32 Tle9180_SpiRxBuf;

void Tle9180_Port_DelayUs(uint32 delayUs)
{
  uint32 resolution = Mcal_DelayTickResolution();

  if (resolution == 0U)
  {
    resolution = Mcal_DelayResetTickCalibration();
  }

  if (resolution == 0U)
  {
    volatile uint32 i;

    for (i = 0U; i < (delayUs * 200U); i++)
    {
      /* fallback */
    }
  }
  else
  {
    const uint32 startTick = Mcal_DelayGetTick();
    const uint32 targetTicks = (delayUs * 1000000UL) / resolution;

    while ((Mcal_DelayGetTick() - startTick) < targetTicks)
    {
      /* wait */
    }
  }
}

void Tle9180_Port_DelayMs(uint32 delayMs)
{
  Tle9180_Port_DelayUs(delayMs * 1000U);
}

void Tle9180_Port_ActivateInhibit(void)
{
  (void)Dio_WriteChannel(DioConf_DioChannel_DioChannel_9183INH, STD_LOW);
}

void Tle9180_Port_DeactivateInhibit(void)
{
  (void)Dio_WriteChannel(DioConf_DioChannel_DioChannel_9183INH, STD_HIGH);
}

void Tle9180_Port_ActivateEnable(void)
{
  (void)Dio_WriteChannel(DioConf_DioChannel_DioChannel_9183ENA, STD_HIGH);
}

void Tle9180_Port_DeactivateEnable(void)
{
  (void)Dio_WriteChannel(DioConf_DioChannel_DioChannel_9183ENA, STD_LOW);
}

void Tle9180_Port_ActivateSafeOff(void)
{
  (void)Dio_WriteChannel(DioConf_DioChannel_DioChannel_9183SOFF, STD_LOW);
}

void Tle9180_Port_DeactivateSafeOff(void)
{
  (void)Dio_WriteChannel(DioConf_DioChannel_DioChannel_9183SOFF, STD_HIGH);
}

boolean Tle9180_Port_GetErrorState(void)
{
  return (boolean)(Dio_ReadChannel(DioConf_DioChannel_DioChannel_9183ERR) == STD_HIGH);
}

static void Tle9180_Port_StoreRx(IfxTLE9180 *handle)
{
  if (handle != NULL_PTR)
  {
    handle->transmitBuffer[handle->transmit.B.ADDRESS].U = handle->transmit.U;
    handle->receiveBuffer[handle->receive.B.ADDRESS].U = handle->receive.U;
  }
}

static Std_ReturnType Tle9180_Port_WaitSeqDone(void)
{
  uint32 resolution;
  uint32 startTick;
  uint32 targetTicks;
  Spi_SeqResultType seqResult;

  resolution = Mcal_DelayTickResolution();
  if (resolution == 0U)
  {
    resolution = Mcal_DelayResetTickCalibration();
  }

  if (resolution == 0U)
  {
    volatile uint32 spin;

    for (spin = 0U; spin < 200000UL; spin++)
    {
      seqResult = Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_9183);
      if (seqResult != SPI_SEQ_PENDING)
      {
        return (seqResult == SPI_SEQ_OK) ? E_OK : E_NOT_OK;
      }
    }
    Spi_Cancel(SpiConf_SpiSequence_SpiSequence_9183);
    Appl_SpiBusRecover();
    return E_NOT_OK;
  }

  startTick = Mcal_DelayGetTick();
  targetTicks = (TLE9180_SPI_WAIT_TIMEOUT_US * 1000000UL) / resolution;

  do
  {
    seqResult = Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_9183);
    if (seqResult != SPI_SEQ_PENDING)
    {
      return (seqResult == SPI_SEQ_OK) ? E_OK : E_NOT_OK;
    }
  } while ((Mcal_DelayGetTick() - startTick) < targetTicks);

  Spi_Cancel(SpiConf_SpiSequence_SpiSequence_9183);
  Appl_SpiBusRecover();
  return E_NOT_OK;
}

Std_ReturnType Tle9180_Port_SpiExchange(IfxTLE9180 *handle, uint32 txFrame)
{
  Std_ReturnType setupResult;
  Std_ReturnType txResult;

  if (handle == NULL_PTR)
  {
    return E_NOT_OK;
  }

  if (Spi_GetHWUnitStatus(SPI_QSPI3_INDEX) != SPI_IDLE)
  {
    Appl_SpiBusRecover();
    if (Spi_GetHWUnitStatus(SPI_QSPI3_INDEX) != SPI_IDLE)
    {
      return E_NOT_OK;
    }
  }

  handle->transmit.U = txFrame & TLE9180_SPI_FRAME_MASK;
  Tle9180_SpiTxBuf = handle->transmit.U;
  Tle9180_SpiRxBuf = 0U;

  setupResult = Spi_SetupEB(
      SpiConf_SpiChannel_SpiChannel_9183,
      (const Spi_DataBufferType *)&Tle9180_SpiTxBuf,
      (Spi_DataBufferType *)&Tle9180_SpiRxBuf,
      1U);

  if (setupResult != E_OK)
  {
    return E_NOT_OK;
  }

  txResult = Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_9183);
  if (txResult != E_OK)
  {
    return E_NOT_OK;
  }

  if (Tle9180_Port_WaitSeqDone() != E_OK)
  {
    return E_NOT_OK;
  }

  handle->receive.U = Tle9180_SpiRxBuf & TLE9180_SPI_FRAME_MASK;
  Tle9180_Port_StoreRx(handle);
  return E_OK;
}
