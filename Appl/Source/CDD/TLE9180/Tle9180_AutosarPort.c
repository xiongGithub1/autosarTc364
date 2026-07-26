/**********************************************************************************************************************
 *  Tle9180_AutosarPort.c
 **********************************************************************************************************************/
#include "Tle9180_AutosarPort.h"

#include "Dio.h"
#include "Dio_Cfg.h"
#include "McalLib.h"
#include "Spi.h"
#include "Spi_Cfg.h"

#define TLE9180_SPI_FRAME_MASK       (0x00FFFFFFU)

static uint32 Tle9180_SpiTxBuf;
static uint32 Tle9180_SpiRxBuf;

void Tle9180_Port_DelayUs(uint32 delayUs)
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
      /* fallback */
    }
  }
  else
  {
    /* Resolution is ns/tick 鈫� ticks = (碌s * 1000) / ns */
    targetTicks = (delayUs * 1000UL) / resolution;
    if (targetTicks == 0U)
    {
      targetTicks = 1U;
    }
    startTick = Mcal_DelayGetTick();
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

Std_ReturnType Tle9180_Port_SpiExchange(IfxTLE9180 *handle, uint32 txFrame)
{
  Std_ReturnType setupResult;
  Std_ReturnType txResult;

  if (handle == NULL_PTR)
  {
    return E_NOT_OK;
  }

  handle->transmit.U = txFrame & TLE9180_SPI_FRAME_MASK;
  Tle9180_SpiTxBuf = handle->transmit.U;
  Tle9180_SpiRxBuf = 0U;
//  Dio_WriteChannel(DioConf_DioChannel_DioChannel_test2, STD_HIGH);
  setupResult = Spi_SetupEB(
      SpiConf_SpiChannel_SpiChannel_9183,
      (const Spi_DataBufferType *)&Tle9180_SpiTxBuf,
      (Spi_DataBufferType *)&Tle9180_SpiRxBuf,
      1U);

  if (setupResult != E_OK)
  {
    return E_NOT_OK;
  }

  txResult = Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence_9183);
  if (txResult != E_OK)
  {
    return E_NOT_OK;
  }

  handle->receive.U = Tle9180_SpiRxBuf & TLE9180_SPI_FRAME_MASK;
  Tle9180_Port_StoreRx(handle);
//  Dio_WriteChannel(DioConf_DioChannel_DioChannel_test2, STD_LOW);
  return E_OK;
}
