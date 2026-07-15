/**********************************************************************************************************************
 *  Tle5012bd_Driver.h - TLE5012BD angle sensor CDD driver API
 **********************************************************************************************************************/
#ifndef TLE5012BD_DRIVER_H
#define TLE5012BD_DRIVER_H

#include "Std_Types.h"
#include "tle5012b.h"


typedef enum
{
  TLE5012BD_STATE_UNINIT = 0U,
  TLE5012BD_STATE_READY
} Tle5012bd_StateType;

void Tle5012bd_Driver_Init(void);
Tle5012bd_StateType Tle5012bd_Driver_GetState(void);
void Tle5012bd_Driver_ReadAngle(Tle5012 *sensor);
void Tle5012bd_Driver_ReadAngleSpeed(Tle5012 *sensor);
float32 Tle5012bd_Driver_GetElectricalAngleRad(void);
float32 Tle5012bd_Driver_GetMechanicalRpm(void);

extern Tle5012 Tle5012bd_Sensor;

#endif /* TLE5012BD_DRIVER_H */
