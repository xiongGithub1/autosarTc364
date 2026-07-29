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
  TLE5012BD_STATE_READY = 1U
} Tle5012bd_StateType;

void Tle5012bd_Driver_Init(void);
Tle5012bd_StateType Tle5012bd_Driver_GetState(void);
Std_ReturnType Tle5012bd_Driver_ReadAngle(Tle5012 *sensor);
Std_ReturnType Tle5012bd_Driver_ReadAngleSlow(Tle5012 *sensor);
void Tle5012bd_Driver_ReadAngleSpeed(Tle5012 *sensor);
float32 Tle5012bd_Driver_GetElectricalAngleRad(void);
float32 Tle5012bd_Driver_GetMechanicalRpm(void);

extern Tle5012 Tle5012bd_Sensor;
extern volatile uint8 Tle5012bd_AngleValid;
extern volatile uint16 Tle5012bd_AngleReadOkCount;
extern volatile uint16 Tle5012bd_AngleReadFailCount;
extern volatile Std_ReturnType Tle5012bd_AngleLastResult;

#endif /* TLE5012BD_DRIVER_H */
