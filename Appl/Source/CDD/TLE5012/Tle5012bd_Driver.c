/**********************************************************************************************************************
 *  Tle5012bd_Driver.c
 **********************************************************************************************************************/
#include "Tle5012bd_Driver.h"
#include "MotorCdd_Foc.h"
#include "Tle5012bd_Spi.h"

Tle5012 Tle5012bd_Sensor;

static Tle5012bd_StateType Tle5012bd_State = TLE5012BD_STATE_UNINIT;
volatile uint8 Tle5012bd_AngleReadBusy = 0U;
volatile uint8 Tle5012bd_AngleValid = 0U;
volatile uint16 Tle5012bd_AngleReadOkCount = 0U;
volatile uint16 Tle5012bd_AngleReadFailCount = 0U;
volatile Std_ReturnType Tle5012bd_AngleLastResult = E_NOT_OK;

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
  Tle5012bd_AngleReadBusy = 0U;
  Tle5012bd_AngleValid = 0U;
  Tle5012bd_AngleReadOkCount = 0U;
  Tle5012bd_AngleReadFailCount = 0U;
  Tle5012bd_AngleLastResult = E_NOT_OK;

  Tle5012bd_State = TLE5012BD_STATE_READY;
}

Tle5012bd_StateType Tle5012bd_Driver_GetState(void)
{
  return Tle5012bd_State;
}

static void Tle5012bd_Driver_RecordResult(Std_ReturnType result)
{
  Tle5012bd_AngleLastResult = result;
  if (result == E_OK)
  {
    Tle5012bd_AngleValid = 1U;
    if (Tle5012bd_AngleReadOkCount < 0xFFFFU) { Tle5012bd_AngleReadOkCount++; }
  }
  else
  {
    Tle5012bd_AngleValid = 0U;
    if (Tle5012bd_AngleReadFailCount < 0xFFFFU) { Tle5012bd_AngleReadFailCount++; }
  }
}

static Std_ReturnType Tle5012bd_Driver_ReadAngleInternal(Tle5012 *sensor,
                                                          float32 samplePeriod)
{
  uint32 rxWord = 0U;
  Spi_SeqResultType spiResult;
  Std_ReturnType result;
  float32 previousPeriod;

  if ((sensor == NULL_PTR) || (Tle5012bd_State != TLE5012BD_STATE_READY))
  {
    Tle5012bd_Driver_RecordResult(E_NOT_OK);
    return E_NOT_OK;
  }

  if (Tle5012bd_AngleReadBusy == 0U)
  {
    if (Tle5012bd_SpiKickU32(0x8020FFFFU) != E_OK)
    {
      Tle5012bd_Driver_RecordResult(E_NOT_OK);
      return E_NOT_OK;
    }
    Tle5012bd_AngleReadBusy = 1U;
    return E_NOT_OK; /* request accepted; no new angle has arrived yet */
  }

  spiResult = Tle5012bd_SpiPollU32(&rxWord);
  if (spiResult == SPI_SEQ_PENDING)
  {
    return E_NOT_OK; /* pending is not a communication failure */
  }
  Tle5012bd_AngleReadBusy = 0U;
  if (spiResult != SPI_SEQ_OK)
  {
    Tle5012bd_Driver_RecordResult(E_NOT_OK);
    return E_NOT_OK;
  }

  previousPeriod = sensor->DisTimer;
  if (samplePeriod > 0.0F) { sensor->DisTimer = samplePeriod; }
  result = tle5012b_process_angle_raw(sensor, (uint16)(rxWord & 0xFFFFU));
  sensor->DisTimer = previousPeriod;
  Tle5012bd_Driver_RecordResult(result);

  /* Keep one transfer in flight.  The result above is already published. */
  if (Tle5012bd_SpiKickU32(0x8020FFFFU) == E_OK)
  {
    Tle5012bd_AngleReadBusy = 1U;
  }
  return result;
}

Std_ReturnType Tle5012bd_Driver_ReadAngle(Tle5012 *sensor)
{
  return Tle5012bd_Driver_ReadAngleInternal(sensor, 0.0001F);
}

Std_ReturnType Tle5012bd_Driver_ReadAngleSlow(Tle5012 *sensor)
{
  return Tle5012bd_Driver_ReadAngleInternal(sensor, 0.001F);
}
void Tle5012bd_Driver_ReadAngleSpeed(Tle5012 *sensor)
{
  if ((sensor != NULL_PTR) && (Tle5012bd_State == TLE5012BD_STATE_READY))
  {
    tle5012b_read_AngleSpeed(sensor);
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


