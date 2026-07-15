/**********************************************************************************************************************
 * tle9180_test.c - TLE9180 SPI bring-up (StartApp)
 **********************************************************************************************************************/
#include "tle9180_test.h"

#include "Spi_Cfg.h"

boolean Tle9180Test_Enabled = TRUE;
boolean Tle9180Test_HwInited = FALSE;
Tle9180_DriverStateType Tle9180Test_State = TLE9180_DRV_STATE_UNINIT;
uint8 Tle9180Test_LastInitError = 0U;
uint8 Tle9180Test_OperationModeRaw = 0U;
Tle9180_OperationModeType Tle9180Test_OperationMode = TLE9180_OP_MODE_UNKNOWN;
boolean Tle9180Test_IsSleepMode = FALSE;
boolean Tle9180Test_IsIdleMode = FALSE;
boolean Tle9180Test_IsConfigMode = FALSE;
boolean Tle9180Test_IsConfigLockMode = FALSE;
boolean Tle9180Test_IsNormalMode = FALSE;
uint32 Tle9180Test_MainCounter = 0U;
uint32 Tle9180Test_InitStepCounter = 0U;
Std_ReturnType Tle9180Test_LastSpiExchangeResult = E_NOT_OK;
uint32 Tle9180Test_LastTxFrame = 0U;
uint32 Tle9180Test_LastRxFrame = 0U;
uint8 Tle9180Test_LastRxAddress = 0U;
uint8 Tle9180Test_LastRxData = 0U;
Spi_StatusType Tle9180Test_SpiStatusBefore = SPI_UNINIT;
Spi_StatusType Tle9180Test_SpiStatusAfter = SPI_UNINIT;
Spi_JobResultType Tle9180Test_SpiJobResultBefore = SPI_JOB_FAILED;
Spi_JobResultType Tle9180Test_SpiJobResultAfter = SPI_JOB_FAILED;
Spi_SeqResultType Tle9180Test_SpiSeqResultBefore = SPI_SEQ_FAILED;
Spi_SeqResultType Tle9180Test_SpiSeqResultAfter = SPI_SEQ_FAILED;
uint32 Tle9180Test_TestCounter = 0U;
uint32 Tle9180Test_OkCounter = 0U;
uint32 Tle9180Test_FailCounter = 0U;

static void Tle9180Test_UpdateSnapshot(void)
{
  Tle9180Test_State = Tle9180_Driver_GetState();
  Tle9180Test_LastInitError = Tle9180_Driver_GetLastInitError();
  Tle9180Test_OperationModeRaw = Tle9180_Driver_GetOperationModeRaw();
  Tle9180Test_OperationMode = Tle9180_Driver_GetOperationMode();
  Tle9180Test_IsSleepMode = (boolean)(Tle9180Test_OperationMode == TLE9180_OP_MODE_SLEEP);
  Tle9180Test_IsIdleMode = (boolean)(Tle9180Test_OperationMode == TLE9180_OP_MODE_IDLE);
  Tle9180Test_IsConfigMode = (boolean)(Tle9180Test_OperationMode == TLE9180_OP_MODE_CONFIG);
  Tle9180Test_IsConfigLockMode = (boolean)(Tle9180Test_OperationMode == TLE9180_OP_MODE_CONFIG_LOCK);
  Tle9180Test_IsNormalMode = (boolean)(Tle9180Test_OperationMode == TLE9180_OP_MODE_NORMAL);
  Tle9180Test_MainCounter = Tle9180_Driver_MainCounter;
  Tle9180Test_InitStepCounter = Tle9180_Driver_InitStepCounter;
  Tle9180Test_LastSpiExchangeResult = Tle9180_Driver_LastSpiExchangeResult;
  Tle9180Test_LastTxFrame = Tle9180_Driver_LastTxFrame;
  Tle9180Test_LastRxFrame = Tle9180_Driver_LastRxFrame;
  Tle9180Test_LastRxAddress = Tle9180_Driver_LastRxAddress;
  Tle9180Test_LastRxData = Tle9180_Driver_LastRxData;
  Tle9180Test_HwInited = (boolean)(Tle9180Test_State == TLE9180_DRV_STATE_READY);
}

void Tle9180Test_Init(void)
{
  Tle9180Test_SpiStatusBefore = Spi_GetStatus();
  Tle9180Test_SpiJobResultBefore = Spi_GetJobResult(SpiConf_SpiJob_SpiJob_9183);
  Tle9180Test_SpiSeqResultBefore = Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_9183);

  /* Blocking bring-up: Port + SPI config sequence. */
  Tle9180_Driver_Init();
  Tle9180Test_UpdateSnapshot();

  Tle9180Test_SpiStatusAfter = Spi_GetStatus();
  Tle9180Test_SpiJobResultAfter = Spi_GetJobResult(SpiConf_SpiJob_SpiJob_9183);
  Tle9180Test_SpiSeqResultAfter = Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_9183);
}

void Tle9180Test_RunOnce(void)
{
  if (Tle9180Test_Enabled != TRUE)
  {
    return;
  }

  Tle9180Test_SpiStatusBefore = Spi_GetStatus();
  Tle9180Test_SpiJobResultBefore = Spi_GetJobResult(SpiConf_SpiJob_SpiJob_9183);
  Tle9180Test_SpiSeqResultBefore = Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_9183);

  /* Stepwise init path if Init() left UNINIT; no-op when READY/FAULT. */
  Tle9180_Driver_MainFunction();

  if (Tle9180_Driver_GetState() == TLE9180_DRV_STATE_READY)
  {
    (void)Tle9180_Driver_ReadOperationMode();
  }

  Tle9180Test_UpdateSnapshot();

  Tle9180Test_SpiStatusAfter = Spi_GetStatus();
  Tle9180Test_SpiJobResultAfter = Spi_GetJobResult(SpiConf_SpiJob_SpiJob_9183);
  Tle9180Test_SpiSeqResultAfter = Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence_9183);

  Tle9180Test_TestCounter++;
  if ((Tle9180Test_State == TLE9180_DRV_STATE_READY) &&
      (Tle9180Test_LastSpiExchangeResult == E_OK))
  {
    Tle9180Test_OkCounter++;
  }
  else if (Tle9180Test_State == TLE9180_DRV_STATE_FAULT)
  {
    Tle9180Test_FailCounter++;
  }
}
