/**********************************************************************************************************************
 *  DsadcRdc.h - TAS2143 / TLE5501 SIN/COS (MCAL Dsadc)
 *  UDE: add symbol Tas2143 (one struct). Set = UDE writable; Obs = watch.
 **********************************************************************************************************************/
#ifndef DSADCRDC_H
#define DSADCRDC_H

#include "Std_Types.h"

typedef enum
{
  DSADCRDC_STATE_UNINIT = 0U,
  DSADCRDC_STATE_RUNNING = 1U
} DsadcRdc_StateType;

typedef struct
{
  /* ---- Set (UDE) ---- */
  uint8 reversed;           /* 1 = invert vs open-loop */
  uint8 polePairs;          /* motor electrical, default 4 */
  uint8 sensorPolePairs;    /* magnet ring, default 10 */
  uint16 offset8192;        /* motor electrical zero, 0..8191 */

  /* ---- Obs: angle / speed ---- */
  uint16 angleRaw8192;      /* motor electrical 0..8191 (FOC) */
  uint16 sensorRaw8192;     /* 10pp magnet, one SIN/COS cycle */
  sint32 angleIntegral;     /* unwrapped 10pp counts */
  float32 angleRad;         /* motor electrical rad */
  float32 angleSpeed;       /* electrical rad/s */
  float32 angleSpeedFilt;   /* LPF electrical rad/s */
  float32 rpm;              /* mechanical RPM, same formula as TLE5012 */

  /* ---- Obs: analog ---- */
  sint16 cosRaw;
  sint16 sinRaw;
  sint16 cosFilt;
  sint16 sinFilt;
  uint32 amplSq;
  uint8 cosValid;
  uint8 sinValid;
  uint32 readOkCount;
  uint32 readFailCount;
  uint8 cosStatus;
  uint8 sinStatus;
  DsadcRdc_StateType state;
} DsadcRdc_Type;

/* UDE watch this one symbol. */
extern volatile DsadcRdc_Type Tas2143;

void DsadcRdc_Init(void);
void DsadcRdc_MainFunction(void);

DsadcRdc_StateType DsadcRdc_GetState(void);
Std_ReturnType DsadcRdc_GetSinCos(sint16 *cosOut, sint16 *sinOut);
Std_ReturnType DsadcRdc_GetSinCosRaw(sint16 *cosOut, sint16 *sinOut);
Std_ReturnType DsadcRdc_GetElectricalAngle(uint16 *angleRaw8192, float32 *angleRad);

#endif /* DSADCRDC_H */
