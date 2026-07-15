/**********************************************************************************************************************
 * tle9180_test.c - TLE9180 SPI bring-up (TestFiles)
 **********************************************************************************************************************/
#include "tle9180_test.h"

#include "Spi_Cfg.h"

Tle9180Test_ObsType Tle9180Test_Obs =
{
  TRUE,  /* Enabled */
  FALSE, /* HwInited */
  TLE9180_DRV_STATE_UNINIT,
  0U,
  0U,
  TLE9180_OP_MODE_UNKNOWN,
  FALSE,
  FALSE,
  FALSE,
  FALSE,
  FALSE,
  0U,
  0U,
  E_NOT_OK,
  0U,
  0U,
  0U,
  0U,
  SPI_UNINIT,
  SPI_UNINIT,
  SPI_UNINIT,
  SPI_UNINIT,
  SPI_JOB_FAILED,
  SPI_JOB_FAILED,
  SPI_SEQ_FAILED,
  SPI_SEQ_FAILED,
  0U,
  0U,
  0U
};

static void Tle9180Test_UpdateDriverSnapshot(void)
{
  Tle9180Test_Obs.State = Tle9180_Driver_GetState();
  Tle9180Test_Obs.LastInitError = Tle9180_Driver_GetLastInitError();
  Tle9180Test_Obs.OpModeRaw = Tle9180_Driver_GetOperationModeRaw();
  Tle9180Test_Obs.OpMode = Tle9180_Driver_GetOperationMode();
  Tle9180Test_Obs.IsSleepMode =
      (boolean)(Tle9180Test_Obs.OpMode == TLE9180_OP_MODE_SLEEP);
  Tle9180Test_Obs.IsIdleMode =
      (boolean)(Tle9180Test_Obs.OpMode == TLE9180_OP_MODE_IDLE);
  Tle9180Test_Obs.IsConfigMode =
      (boolean)(Tle9180Test_Obs.OpMode == TLE9180_OP_MODE_CONFIG);
  Tle9180Test_Obs.IsConfigLockMode =
      (boolean)(Tle9180Test_Obs.OpMode == TLE9180_OP_MODE_CONFIG_LOCK);
  Tle9180Test_Obs.IsNormalMode =
      (boolean)(Tle9180Test_Obs.OpMode == TLE9180_OP_MODE_NORMAL);
  Tle9180Test_Obs.MainCounter = Tle9180_Driver_MainCounter;
  Tle9180Test_Obs.InitStepCounter = Tle9180_Driver_InitStepCounter;
  Tle9180Test_Obs.SpiExch = Tle9180_Driver_LastSpiExchangeResult;
  Tle9180Test_Obs.TxFrame = Tle9180_Driver_LastTxFrame;
  Tle9180Test_Obs.RxFrame = Tle9180_Driver_LastRxFrame;
  Tle9180Test_Obs.RxAddr = Tle9180_Driver_LastRxAddress;
  Tle9180Test_Obs.RxData = Tle9180_Driver_LastRxData;
  Tle9180Test_Obs.HwInited =
      (boolean)(Tle9180Test_Obs.State == TLE9180_DRV_STATE_READY);
}

static void Tle9180Test_CaptureSpiBefore(void)
{
  Tle9180Test_Obs.SpiGlobalBefore = Spi_GetStatus();
  Tle9180Test_Obs.HwUnitBefore = Spi_GetHWUnitStatus(SPI_QSPI3_INDEX);
  Tle9180Test_Obs.JobBefore = Spi_GetJobResult(SpiConf_SpiJob_SpiJob_9183);
  Tle9180Test_Obs.SeqBefore =
      Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_9183);
}

static void Tle9180Test_CaptureSpiAfter(void)
{
  Tle9180Test_Obs.SpiGlobalAfter = Spi_GetStatus();
  Tle9180Test_Obs.HwUnitAfter = Spi_GetHWUnitStatus(SPI_QSPI3_INDEX);
  Tle9180Test_Obs.JobAfter = Spi_GetJobResult(SpiConf_SpiJob_SpiJob_9183);
  Tle9180Test_Obs.SeqAfter =
      Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_9183);
}

void Tle9180Test_Init(void)
{
  Tle9180Test_CaptureSpiBefore();
  Tle9180_Driver_Init();
  Tle9180Test_UpdateDriverSnapshot();
  Tle9180Test_CaptureSpiAfter();
}

void Tle9180Test_RunOnce(void)
{
  if (Tle9180Test_Obs.Enabled != TRUE)
  {
    return;
  }

  Tle9180Test_CaptureSpiBefore();

  Tle9180_Driver_MainFunction();

  if (Tle9180_Driver_GetState() == TLE9180_DRV_STATE_READY)
  {
    (void)Tle9180_Driver_ReadOperationMode();
  }

  Tle9180Test_UpdateDriverSnapshot();
  Tle9180Test_CaptureSpiAfter();

  Tle9180Test_Obs.TestCounter++;
  if ((Tle9180Test_Obs.State == TLE9180_DRV_STATE_READY) &&
      (Tle9180Test_Obs.SpiExch == E_OK))
  {
    Tle9180Test_Obs.OkCounter++;
  }
  else
  {
    Tle9180Test_Obs.FailCounter++;
  }
}
