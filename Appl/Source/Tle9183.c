/**********************************************************************************************************************
 *  Tle9183.c
 *
 *  TLE9183QK initialization and SPI helper routines.
 **********************************************************************************************************************/

#include "Tle9183.h"

#include "Dio.h"
#include "Dio_Cfg.h"
#include "IfxPort_reg.h"
#include "IfxQspi_reg.h"
#include "McalLib.h"
#include "Spi.h"
#include "Spi_Cfg.h"

#define TLE9183_DELAY_INH_MIN_MS        (5U)
#define TLE9183_DELAY_AFTER_INH_MS       (5U)
#define TLE9183_DELAY_AFTER_ERR_US      (500U)
#define TLE9183_ERR_WAIT_TIMEOUT_MS     (20U)
#define TLE9183_SPI_PIPELINE_FLUSH_CNT  (1U)
#define TLE9183_RETRY_PERIOD_MS         (1000U)

#define TLE9183_SPI_FRAME_MASK          (0x00FFFFFFU)

Tle9183_StatusType Tle9183_Status;

static uint32 Tle9183_LastRetryMs;

static void Tle9183_DelayUs(uint32 delayUs);
static void Tle9183_DelayMs(uint32 delayMs);
static uint32 Tle9183_GetElapsedMs(uint32 startMs);
static uint32 Tle9183_GetMsTick(void);
static uint8 Tle9183_CalcCrc3(uint32 data, uint8 numBits);
static uint32 Tle9183_BuildMosiFrame(boolean isWrite, uint8 addr, uint8 data);
static boolean Tle9183_ParseMisoFrame(uint32 rxFrame, uint8 *spiStatus,
    uint8 *addr, uint8 *data, boolean *crcOk);
static Std_ReturnType Tle9183_SpiExchange(uint32 txFrame, uint32 *rxFrame);
static Std_ReturnType Tle9183_WaitErrHigh(void);
static void Tle9183_SampleQspiHw(void);
static void Tle9183_SampleMrstPin(void);
static void Tle9183_SetSleepPins(void);
static void Tle9183_SetWakePins(void);
static void Tle9183_ApplyPowerUpSequence(void);
static Std_ReturnType Tle9183_ConfigureDefault(void);

static void Tle9183_DelayUs(uint32 delayUs)
{
  uint32 resolution;
  uint32 startTick;
  uint32 targetTicks;

  resolution = Mcal_DelayTickResolution();
  if (resolution == 0U)
  {
    resolution = Mcal_DelayResetTickCalibration();
  }

  if (resolution == 0U)
  {
    volatile uint32 delayLoop;

    for (delayLoop = 0U; delayLoop < (delayUs * 200U); delayLoop++)
    {
      /* fallback busy wait */
    }
  }
  else
  {
    startTick = Mcal_DelayGetTick();
    targetTicks = (delayUs * 1000000UL) / resolution;
    while ((Mcal_DelayGetTick() - startTick) < targetTicks)
    {
      /* wait */
    }
  }
}

static void Tle9183_DelayMs(uint32 delayMs)
{
  Tle9183_DelayUs(delayMs * 1000U);
}

static uint32 Tle9183_GetMsTick(void)
{
  uint32 resolution;
  uint32 tick;

  resolution = Mcal_DelayTickResolution();
  if (resolution == 0U)
  {
    resolution = Mcal_DelayResetTickCalibration();
  }

  if (resolution == 0U)
  {
    return 0U;
  }

  tick = Mcal_DelayGetTick();
  return tick / (resolution * 1000U);
}

static uint32 Tle9183_GetElapsedMs(uint32 startMs)
{
  const uint32 nowMs = Tle9183_GetMsTick();

  if (nowMs >= startMs)
  {
    return (nowMs - startMs);
  }

  return 0U;
}

static uint8 Tle9183_CalcCrc3(uint32 data, uint8 numBits)
{
  uint8 crc = 0x4U;
  uint8 bitIndex;

  for (bitIndex = 0U; bitIndex < numBits; bitIndex++)
  {
    const uint8 dataBit = (uint8)((data >> (uint8)(numBits - 1U - bitIndex)) & 1U);
    const uint8 msb = (uint8)((crc >> 2U) & 1U);

    crc = (uint8)((crc << 1) & 7U);
    if ((msb ^ dataBit) != 0U)
    {
      crc ^= 0x3U;
    }
  }

  return crc;
}

static uint32 Tle9183_BuildMosiFrame(boolean isWrite, uint8 addr, uint8 data)
{
  const uint32 msg21 = (((uint32)(isWrite ? 1U : 0U)) << 20)
                     | (((uint32)addr & 0x7FU) << 13)
                     | (((uint32)data) << 5);
  const uint8 crc = Tle9183_CalcCrc3(msg21, 21U);

  return ((msg21 << 3) | (uint32)crc) & TLE9183_SPI_FRAME_MASK;
}

static boolean Tle9183_ParseMisoFrame(uint32 rxFrame, uint8 *spiStatus,
    uint8 *addr, uint8 *data, boolean *crcOk)
{
  const uint32 frame = rxFrame & TLE9183_SPI_FRAME_MASK;
  const uint32 msg21 = frame >> 3;
  const uint8 rxCrc = (uint8)(frame & 7U);
  const uint8 calcCrc = Tle9183_CalcCrc3(msg21, 21U);

  if (spiStatus != NULL_PTR)
  {
    *spiStatus = (uint8)((frame >> 19) & 0x1FU);
  }
  if (addr != NULL_PTR)
  {
    *addr = (uint8)((frame >> 12) & 0x7FU);
  }
  if (data != NULL_PTR)
  {
    *data = (uint8)((frame >> 4) & 0xFFU);
  }
  if (crcOk != NULL_PTR)
  {
    *crcOk = (boolean)(rxCrc == calcCrc);
  }

  return (boolean)(rxCrc == calcCrc);
}

static Std_ReturnType Tle9183_SpiExchange(uint32 txFrame, uint32 *rxFrame)
{
  uint32 rxWord = 0U;
  Std_ReturnType setupResult;
  Std_ReturnType txResult;
  Spi_SeqResultType seqResult;

  if (Spi_GetStatus() != SPI_IDLE)
  {
    return E_NOT_OK;
  }

  setupResult = Spi_SetupEB(
      SpiConf_SpiChannel_SpiChannel_9183,
      (const Spi_DataBufferType *)&txFrame,
      (Spi_DataBufferType *)&rxWord,
      1U);

  if (setupResult != E_OK)
  {
    Tle9183_Status.SpiFailCounter++;
    return E_NOT_OK;
  }

  txResult = Spi_SyncTransmit(SpiConf_SpiSequence_SpiSequence);
  seqResult = Spi_GetSequenceResult(SpiConf_SpiSequence_SpiSequence);

  Tle9183_SampleQspiHw();
  Tle9183_SampleMrstPin();
  Tle9183_Status.LastTxFrame = txFrame & TLE9183_SPI_FRAME_MASK;
  Tle9183_Status.LastRxFrame = rxWord & TLE9183_SPI_FRAME_MASK;

  if ((txResult != E_OK) || (seqResult != SPI_SEQ_OK))
  {
    Tle9183_Status.SpiFailCounter++;
    return E_NOT_OK;
  }

  if (rxFrame != NULL_PTR)
  {
    *rxFrame = rxWord & TLE9183_SPI_FRAME_MASK;
  }

  Tle9183_Status.SpiOkCounter++;
  return E_OK;
}

static void Tle9183_SampleQspiHw(void)
{
  Tle9183_Status.Qspi3Pisel = QSPI3_PISEL.U;
  Tle9183_Status.Qspi3Status = QSPI3_STATUS.U;
  Tle9183_Status.Qspi3ErrorFlags = QSPI3_STATUS.U & 0x0000FF00U;
}

static void Tle9183_SampleMrstPin(void)
{
  Tle9183_Status.MrstPinLevel =
      (boolean)((P22_IN.U & 0x00000002U) != 0U);
}

static void Tle9183_SetSleepPins(void)
{
  (void)Dio_WriteChannel(DioConf_DioChannel_DioChannel_9183INH, STD_LOW);
  (void)Dio_WriteChannel(DioConf_DioChannel_DioChannel_9183ENA, STD_LOW);
  (void)Dio_WriteChannel(DioConf_DioChannel_DioChannel_9183SOFF, STD_LOW);
}

static void Tle9183_SetWakePins(void)
{
  (void)Dio_WriteChannel(DioConf_DioChannel_DioChannel_9183SOFF, STD_HIGH);
  (void)Dio_WriteChannel(DioConf_DioChannel_DioChannel_9183ENA, STD_LOW);
  (void)Dio_WriteChannel(DioConf_DioChannel_DioChannel_9183INH, STD_HIGH);
}

static void Tle9183_ApplyPowerUpSequence(void)
{
  if (Tle9183_Status.PowerUpDone == TRUE)
  {
    return;
  }

  Tle9183_SetSleepPins();
  Tle9183_DelayMs(TLE9183_DELAY_INH_MIN_MS);
  Tle9183_SetWakePins();
  Tle9183_DelayMs(TLE9183_DELAY_AFTER_INH_MS);
  Tle9183_Status.PowerUpDone = TRUE;
  Tle9183_Status.InitPhase = TLE9183_INIT_PHASE_POWER_DONE;
}

static Std_ReturnType Tle9183_WaitErrHigh(void)
{
  uint32 startMs = Tle9183_GetMsTick();

  for (;;)
  {
    Tle9183_Status.ErrPinLevel =
        (boolean)(Dio_ReadChannel(DioConf_DioChannel_DioChannel_9183ERR) == STD_HIGH);

    if (Tle9183_Status.ErrPinLevel == TRUE)
    {
      return E_OK;
    }

    if (Tle9183_GetElapsedMs(startMs) >= TLE9183_ERR_WAIT_TIMEOUT_MS)
    {
      break;
    }
  }

  return E_NOT_OK;
}

static Std_ReturnType Tle9183_ConfigureDefault(void)
{
  uint32 rxFrame = 0U;
  uint8 flushIndex;
  uint8 nopData = 0U;

  for (flushIndex = 0U; flushIndex <= TLE9183_SPI_PIPELINE_FLUSH_CNT; flushIndex++)
  {
    if (Tle9183_SpiExchange(Tle9183_BuildMosiFrame(FALSE, TLE9183_REG_NOP, 0U), &rxFrame) != E_OK)
    {
      Tle9183_Status.InitPhase = TLE9183_INIT_PHASE_SPI_HW_FAIL;
      return E_NOT_OK;
    }

    (void)Tle9183_ParseMisoFrame(rxFrame, &Tle9183_Status.LastSpiStatus,
        &Tle9183_Status.LastAddr, &nopData, &Tle9183_Status.LastCrcOk);
    Tle9183_Status.LastData = nopData;

    if (Tle9183_Status.LastCrcOk != TRUE)
    {
      Tle9183_Status.InitPhase = TLE9183_INIT_PHASE_SPI_CRC_FAIL;
      return E_NOT_OK;
    }
  }

  Tle9183_Status.InitPhase = TLE9183_INIT_PHASE_SPI_OK;
  Tle9183_Status.State = TLE9183_STATE_IDLE_READY;

  if (Tle9183_WriteRegister(TLE9183_REG_CONF_SIG, TLE9183_CONF_SIG_DEFAULT) != E_OK)
  {
    return E_NOT_OK;
  }

  (void)Tle9183_ReadRegister(TLE9183_REG_NOP, &nopData);

  if ((Tle9183_Status.LastCrcOk == TRUE)
      && ((Tle9183_Status.LastSpiStatus & TLE9183_SPI_STATUS_CONFIG_VALID) != 0U))
  {
    Tle9183_Status.State = TLE9183_STATE_CONFIGURED;
    Tle9183_Status.InitPhase = TLE9183_INIT_PHASE_CONFIG_DONE;
  }

  return E_OK;
}

Std_ReturnType Tle9183_ReadRegister(uint8 regAddr, uint8 *regData)
{
  uint32 rxFrame = 0U;
  uint8 localData = 0U;
  const uint32 txFrame = Tle9183_BuildMosiFrame(FALSE, regAddr, 0U);

  if (Tle9183_SpiExchange(txFrame, &rxFrame) != E_OK)
  {
    return E_NOT_OK;
  }

  (void)Tle9183_ParseMisoFrame(rxFrame, &Tle9183_Status.LastSpiStatus,
      &Tle9183_Status.LastAddr, &localData, &Tle9183_Status.LastCrcOk);
  Tle9183_Status.LastData = localData;

  if (regData != NULL_PTR)
  {
    *regData = localData;
  }

  return (Tle9183_Status.LastCrcOk == TRUE) ? E_OK : E_NOT_OK;
}

Std_ReturnType Tle9183_WriteRegister(uint8 regAddr, uint8 regData)
{
  uint32 rxFrame = 0U;
  const uint32 txFrame = Tle9183_BuildMosiFrame(TRUE, regAddr, regData);

  if (Tle9183_SpiExchange(txFrame, &rxFrame) != E_OK)
  {
    return E_NOT_OK;
  }

  (void)Tle9183_ParseMisoFrame(rxFrame, &Tle9183_Status.LastSpiStatus,
      &Tle9183_Status.LastAddr, &Tle9183_Status.LastData, &Tle9183_Status.LastCrcOk);

  return (Tle9183_Status.LastCrcOk == TRUE) ? E_OK : E_NOT_OK;
}

Tle9183_StateType Tle9183_GetState(void)
{
  return Tle9183_Status.State;
}

void Tle9183_Init(void)
{
  if (Tle9183_Status.State == TLE9183_STATE_CONFIGURED)
  {
    return;
  }

  Tle9183_Status.InitAttemptCounter++;
  Tle9183_ApplyPowerUpSequence();

  if (Tle9183_WaitErrHigh() != E_OK)
  {
    Tle9183_Status.InitPhase = TLE9183_INIT_PHASE_ERR_TIMEOUT;
    return;
  }

  Tle9183_DelayUs(TLE9183_DELAY_AFTER_ERR_US);
  (void)Tle9183_ConfigureDefault();
}

void Tle9183_MainFunction(void)
{
  if (Tle9183_Status.State == TLE9183_STATE_CONFIGURED)
  {
    return;
  }

  if (Tle9183_GetElapsedMs(Tle9183_LastRetryMs) < TLE9183_RETRY_PERIOD_MS)
  {
    return;
  }

  Tle9183_LastRetryMs = Tle9183_GetMsTick();
  Tle9183_Init();
}
