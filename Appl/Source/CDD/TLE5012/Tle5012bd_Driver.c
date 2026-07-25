/**********************************************************************************************************************
 *  Tle5012bd_Driver.c
 **********************************************************************************************************************/
#include "Tle5012bd_Driver.h"
#include "Tle5012bd_Spi.h"
#include "MotorCdd_Foc.h"
#include "Spi.h"

/* Shared SFR mirror from tle5012b.c */
extern TLE5012_SFR tle5012_sfr;

Tle5012 Tle5012bd_Sensor;

static Tle5012bd_StateType Tle5012bd_State = TLE5012BD_STATE_UNINIT;
volatile uint8 Tle5012bd_SscActivateDone = 0U;
volatile uint8 Tle5012bd_SscActivateResult = 0U;
volatile uint16 Tle5012bd_SscLastStat = 0U;
volatile uint16 Tle5012bd_SscLastAval = 0U;

/* AVAL read frame: READ | addr<<4 | 0xFFFF (see tle5012b_build_tx). */
#define TLE5012BD_AVAL_READ_TX   (0x8020FFFFUL)

static void Tle5012bd_Driver_ApplyAvalRaw(Tle5012 *tle5012, uint16 avalRaw)
{
  uint16 angle;
  uint16 prevAngle;
  uint16 delta;
  float32 angleOldPi;
  float32 error;
  static uint16 s_lastGoodAngVal = 0U;
  static uint8 s_haveLastGood = 0U;

  if (tle5012 == NULL_PTR)
  {
    return;
  }

  tle5012_sfr.AVAL_Type.U = avalRaw;

  /* SPI glitch / half-duplex contention often returns 0xFFFF → ANG_VAL=32767. */
  if (avalRaw == 0xFFFFU)
  {
    tle5012->SafetyBit++;
    return;
  }

  if (tle5012_sfr.AVAL_Type.B.RD_AV == 0U)
  {
    return;
  }

  angle = tle5012_sfr.AVAL_Type.B.ANG_VAL;

  if (s_haveLastGood != 0U)
  {
    prevAngle = s_lastGoodAngVal;
    delta = (uint16)((angle - prevAngle) & 0x7FFFU);
    if (delta > 16383U)
    {
      delta = (uint16)(32768U - (uint32)delta);
    }
    /* ~100 us sample: even 6000 rpm is only ~328 counts; 2048 ≈ 22.5° reject. */
    if (delta > 2048U)
    {
      tle5012->SafetyBit++;
      return;
    }
  }

  s_lastGoodAngVal = angle;
  s_haveLastGood = 1U;
  tle5012->Original_Angle = (float32)angle;

  /* AVAL is 15-bit mechanical; FOC table is 13-bit — scale by >>2. */
  angle = (uint16)(((uint32)angle >> 2U) & 0x1FFFU);
  tle5012->Angle = (float32)angle;

  angleOldPi = tle5012->anglePi;
  tle5012->anglePi = tle5012->Angle * 7.66429044544767e-4F;
  error = tle5012->anglePi - angleOldPi;

  if (error > M_PI)
  {
    error -= M_TWOPI;
  }
  else if (error < -M_PI)
  {
    error += M_TWOPI;
  }

  if (tle5012->DisTimer > 0.0F)
  {
    tle5012->AngleSpeed = error / tle5012->DisTimer;
    tle5012->AngleSpeedFilter =
        (tle5012->AngleSpeedFilter * 0.9F) + (tle5012->AngleSpeed * 0.1F);
    if (tle5012->polePairs > 0U)
    {
      tle5012->RPM = tle5012->AngleSpeedFilter * 9.5493F / (float32)tle5012->polePairs;
    }
  }
}

void Tle5012bd_Driver_Init(void)
{
  Tle5012bd_Sensor.Angle = 0.0F;
  Tle5012bd_Sensor.Original_Angle = 0.0F;
  Tle5012bd_Sensor.anglePi = 0.0F;
  Tle5012bd_Sensor.AngleSpeed = 0.0F;
  Tle5012bd_Sensor.AngleSpeedFilter = 0.0F;
  Tle5012bd_Sensor.RPM = 0.0F;
  Tle5012bd_Sensor.Direction = FALSE;
  Tle5012bd_Sensor.ANG_BASE = 0U;
  Tle5012bd_Sensor.Temperature = 0.0F;
#if (MOTORCDD_FOC_ANGLE_SPI_IN_FASTLOOP == 1U)
  Tle5012bd_Sensor.DisTimer = 0.0001F; /* ~100 us FocFastLoop */
#else
  Tle5012bd_Sensor.DisTimer = 0.001F; /* 1 ms StartApp */
#endif
  Tle5012bd_Sensor.polePairs = 4U;
  Tle5012bd_Sensor.SafetyBit = 0U;

  Tle5012bd_SscActivateDone = 0U;
  Tle5012bd_SscActivateResult = 0U;
  Tle5012bd_SscLastStat = 0U;
  Tle5012bd_SscLastAval = 0U;

  /* RAM only — SSC bring-up after Spi_Init + power settle (StartApp). */
  Tle5012bd_State = TLE5012BD_STATE_WAIT_SSC;
}

/*
 * Align with old IPB motorControl_RotorZeroPositionInit:
 * ChangeAngleDirection + read_all after MCU SPI is up.
 * Also clears SSC confusion left by Port/Spi pin toggling at boot
 * (same effect as unplugging/replugging the sensor cable).
 */
Std_ReturnType Tle5012bd_Driver_SscActivate(void)
{
  uint8 i;
  uint16 aval;

  if (Spi_GetStatus() != SPI_IDLE)
  {
    return E_NOT_OK;
  }

  /* Let CS stay idle after boot noise / pin mux. */
  tle5012b_delay_us(1000U);

  for (i = 0U; i < 5U; i++)
  {
    Tle5012bd_SscLastStat = tle5012b_read_fast(STAT);
    tle5012b_delay_us(100U);
  }

  for (i = 0U; i < 3U; i++)
  {
    (void)tle5012b_read_fast(AVAL);
    tle5012b_delay_us(100U);
  }

  /* Same as old IPB: force known ANG_DIR path + dummy AVAL. */
  (void)tle5012b_ChangeAngleDirection(counterclockwise);
  tle5012b_delay_us(150U);
  tle5012b_read_all();

  aval = tle5012b_read_fast(AVAL);
  Tle5012bd_SscLastAval = aval;
  Tle5012bd_Sensor.Original_Angle = (float32)(aval & 0x7FFFU);

  Tle5012bd_SscActivateDone = 1U;
  Tle5012bd_SscActivateResult = 1U;
  Tle5012bd_State = TLE5012BD_STATE_READY;
  return E_OK;
}

Tle5012bd_StateType Tle5012bd_Driver_GetState(void)
{
  return Tle5012bd_State;
}

void Tle5012bd_Driver_ReadAngle(Tle5012 *sensor)
{
  if ((sensor != NULL_PTR) && (Tle5012bd_State == TLE5012BD_STATE_READY))
  {
    tle5012b_read_angle(sensor);
  }
}

void Tle5012bd_Driver_ReadAngleSpeed(Tle5012 *sensor)
{
  if ((sensor != NULL_PTR) && (Tle5012bd_State == TLE5012BD_STATE_READY))
  {
    tle5012b_read_AngleSpeed(sensor);
  }
}

Std_ReturnType Tle5012bd_Driver_AngleAsyncKick(void)
{
  if (Tle5012bd_State != TLE5012BD_STATE_READY)
  {
    return E_NOT_OK;
  }
  return Tle5012bd_SpiStartExchangeU32(TLE5012BD_AVAL_READ_TX);
}

uint8 Tle5012bd_Driver_AngleAsyncTryConsume(Tle5012 *sensor)
{
  uint32 rxWord = 0U;
  Tle5012bd_SpiXferStateType st;

  if (sensor == NULL_PTR)
  {
    return 0U;
  }

  st = Tle5012bd_SpiPollExchange();
  if (st == TLE5012BD_SPI_XFER_PENDING)
  {
    return 0U;
  }
  if (st == TLE5012BD_SPI_XFER_FAIL)
  {
    (void)Tle5012bd_SpiTakeRxWord(&rxWord); /* clears FAIL → IDLE */
    return 0U;
  }
  if (st != TLE5012BD_SPI_XFER_OK)
  {
    return 0U;
  }

  if (Tle5012bd_SpiTakeRxWord(&rxWord) != E_OK)
  {
    return 0U;
  }

  Tle5012bd_Driver_ApplyAvalRaw(sensor, (uint16)(rxWord & 0xFFFFU));
  return 1U;
}

void Tle5012bd_Driver_DiscardCompletedSpi(void)
{
  Tle5012bd_SpiXferStateType spiSt = Tle5012bd_SpiPollExchange();

  if ((spiSt == TLE5012BD_SPI_XFER_OK) || (spiSt == TLE5012BD_SPI_XFER_FAIL))
  {
    uint32 dropRx;

    (void)Tle5012bd_SpiTakeRxWord(&dropRx);
  }
}

float32 Tle5012bd_Driver_GetElectricalAngleRad(void)
{
  float32 electricalAngle = Tle5012bd_Sensor.anglePi *
                            (float32)Tle5012bd_Sensor.polePairs;

  while (electricalAngle >= M_TWOPI)
  {
    electricalAngle -= M_TWOPI;
  }
  while (electricalAngle < 0.0F)
  {
    electricalAngle += M_TWOPI;
  }

  return electricalAngle;
}

float32 Tle5012bd_Driver_GetMechanicalRpm(void)
{
  return Tle5012bd_Sensor.RPM;
}
