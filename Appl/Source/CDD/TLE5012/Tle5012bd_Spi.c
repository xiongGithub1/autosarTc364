/**********************************************************************************************************************
 *  Tle5012bd_Spi.c - TLE5012BD SPI over Spi MCAL (32-bit EB frame)
 **********************************************************************************************************************/
#include "Tle5012bd_Spi.h"

#include "Appl_SpiDmaHwInit.h"
#include "McalLib.h"
#include "Spi.h"
#include "Spi_Cfg.h"

#define TLE5012BD_SPI_WAIT_TIMEOUT_US  (5000U)

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

static uint32 Tle5012bd_SpiTxBuf;
static uint32 Tle5012bd_SpiRxBuf;

/*
 * Motortask 里纯等 INTERRUPT 完成不可靠：PT 进不来 → 超时 Cancel →
 * SEQ_CANCELED + KernelStatus 仍 BUSY。
 * 正确用法：IDLE 时 SetAsyncMode(POLLING) → AsyncTransmit →
 * 循环 Spi_MainFunction_Handling() 推进状态机 → 再切回 INTERRUPT。
 */
static Std_ReturnType Tle5012bd_SpiWaitSeqDone(void)
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

    for (spin = 0U; spin < 500000UL; spin++)
    {
      Spi_MainFunction_Handling();
      seqResult = Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_5012BD);
      if (seqResult != SPI_SEQ_PENDING)
      {
        return (seqResult == SPI_SEQ_OK) ? E_OK : E_NOT_OK;
      }
    }
    Spi_Cancel(SpiConf_SpiSequence_SpiSequence_5012BD);
    Appl_SpiBusRecover();
    return E_NOT_OK;
  }

  startTick = Mcal_DelayGetTick();
  targetTicks = (TLE5012BD_SPI_WAIT_TIMEOUT_US * 1000000UL) / resolution;

  do
  {
    Spi_MainFunction_Handling();
    seqResult = Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_5012BD);
    if (seqResult != SPI_SEQ_PENDING)
    {
      return (seqResult == SPI_SEQ_OK) ? E_OK : E_NOT_OK;
    }
  } while ((Mcal_DelayGetTick() - startTick) < targetTicks);

  Spi_Cancel(SpiConf_SpiSequence_SpiSequence_5012BD);
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

  /* Must switch while IDLE; ignored if done after AsyncTransmit. */
  if (Spi_SetAsyncMode(SPI_POLLING_MODE) != E_OK)
  {
    Tle5012bd_SpiStatusAfter = Spi_GetHWUnitStatus(SPI_QSPI2_INDEX);
    return E_NOT_OK;
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
    (void)Spi_SetAsyncMode(SPI_INTERRUPT_MODE);
    Tle5012bd_SpiStatusAfter = Spi_GetHWUnitStatus(SPI_QSPI2_INDEX);
    return E_NOT_OK;
  }

  Tle5012bd_SpiLastTransmitResult =
      Spi_AsyncTransmit(SpiConf_SpiSequence_SpiSequence_5012BD);
  if (Tle5012bd_SpiLastTransmitResult != E_OK)
  {
    Tle5012bd_SpiLastSeqResult =
        Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_5012BD);
    (void)Spi_SetAsyncMode(SPI_INTERRUPT_MODE);
    Tle5012bd_SpiStatusAfter = Spi_GetHWUnitStatus(SPI_QSPI2_INDEX);
    return E_NOT_OK;
  }

  if (Tle5012bd_SpiWaitSeqDone() != E_OK)
  {
    Tle5012bd_SpiLastSeqResult =
        Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_5012BD);
    /*
     * After Cancel, Kernel may still report BUSY — SetAsyncMode(INTERRUPT)
     * will fail until soft-recovered + idle. Best-effort restore.
     */
    (void)Spi_SetAsyncMode(SPI_INTERRUPT_MODE);
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

  (void)Spi_SetAsyncMode(SPI_INTERRUPT_MODE);

  if (Tle5012bd_SpiLastSeqResult != SPI_SEQ_OK)
  {
    return E_NOT_OK;
  }

  Tle5012bd_SpiLastResult = E_OK;
  return E_OK;
}
