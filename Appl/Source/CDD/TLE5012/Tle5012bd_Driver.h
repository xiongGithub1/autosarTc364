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
  TLE5012BD_STATE_WAIT_SSC = 1U,
  TLE5012BD_STATE_READY = 2U
} Tle5012bd_StateType;

void Tle5012bd_Driver_Init(void);
/* Call once from StartApp after Spi_Init + settle — restores SSC like cable replug. */
Std_ReturnType Tle5012bd_Driver_SscActivate(void);
Tle5012bd_StateType Tle5012bd_Driver_GetState(void);
void Tle5012bd_Driver_ReadAngle(Tle5012 *sensor);
void Tle5012bd_Driver_ReadAngleSpeed(Tle5012 *sensor);
/* FOC non-blocking: kick AVAL read; try consume completed frame into sensor. */
Std_ReturnType Tle5012bd_Driver_AngleAsyncKick(void);
uint8 Tle5012bd_Driver_AngleAsyncTryConsume(Tle5012 *sensor);
void Tle5012bd_Driver_DiscardCompletedSpi(void);
float32 Tle5012bd_Driver_GetElectricalAngleRad(void);
float32 Tle5012bd_Driver_GetMechanicalRpm(void);

extern Tle5012 Tle5012bd_Sensor;
extern volatile uint8 Tle5012bd_SscActivateDone;
extern volatile uint8 Tle5012bd_SscActivateResult;
extern volatile uint16 Tle5012bd_SscLastStat;
extern volatile uint16 Tle5012bd_SscLastAval;

#endif /* TLE5012BD_DRIVER_H */
