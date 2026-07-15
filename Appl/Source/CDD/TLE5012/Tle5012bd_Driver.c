/**********************************************************************************************************************
 *  Tle5012bd_Driver.c
 **********************************************************************************************************************/
#include "Tle5012bd_Driver.h"

Tle5012 Tle5012bd_Sensor;

static Tle5012bd_StateType Tle5012bd_State = TLE5012BD_STATE_UNINIT;

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
  Tle5012bd_Sensor.DisTimer = 0.0001F; /* 100 us default sample period */
  Tle5012bd_Sensor.polePairs = 4U;

  /* Do not SPI here: MotorCdd_Init must bring up TLE9180 first.
   * First angle read happens in MotorControll cyclic path. */
  Tle5012bd_State = TLE5012BD_STATE_READY;
}

Tle5012bd_StateType Tle5012bd_Driver_GetState(void)
{
  return Tle5012bd_State;
}

void Tle5012bd_Driver_ReadAngle(Tle5012 *sensor)
{
  if (sensor != NULL_PTR)
  {
    tle5012b_read_angle(sensor);
  }
}

void Tle5012bd_Driver_ReadAngleSpeed(Tle5012 *sensor)
{
  if (sensor != NULL_PTR)
  {
    tle5012b_read_AngleSpeed(sensor);
  }
}

float32 Tle5012bd_Driver_GetElectricalAngleRad(void)
{
  tle5012b_read_angle(&Tle5012bd_Sensor);
  return Tle5012bd_Sensor.anglePi;
}

float32 Tle5012bd_Driver_GetMechanicalRpm(void)
{
  return Tle5012bd_Sensor.RPM;
}
