/**********************************************************************************************************************
 *  DsadcRdc.c - TAS2143 / TLE5501 SIN/COS via MCAL Dsadc
 *
 *  Run on Core1 with FOC. BswM already called Dsadc_Init().
 *  10pp magnet -> unwrap -> motor 4pp electrical 8192.
 *  RPM: d(elec rad)/dt * 60/(2*pi) / polePairs  (same as TLE5012).
 **********************************************************************************************************************/
#include "DsadcRdc.h"
#include "Dsadc.h"
#include "MotorFoc_SinCosTable.h"
#include <math.h>

#define DSADCRDC_CH_COS              DsadcChannel_DsadcChannel_TLE5501_COSP
#define DSADCRDC_CH_SIN              DsadcChannel_DsadcChannel_TLE5501_SIN
#define DSADCRDC_HW_CH_COS           (0U)
#define DSADCRDC_HW_CH_SIN           (1U)
#define DSADCRDC_TWO_PI              (6.283185307179586F)
#define DSADCRDC_PI                  (3.141592653589793F)
#define DSADCRDC_MOTOR_POLE_PAIRS    (4U)
#define DSADCRDC_SENSOR_POLE_PAIRS   (10U)
#define DSADCRDC_TS                  (0.0001F)          /* 10 kHz FOC */
#define DSADCRDC_RAD_S_TO_RPM        (9.549296585513721F) /* 60/(2*pi) */
#define DSADCRDC_LPF_SHIFT           (4U)

volatile DsadcRdc_Type Tas2143 =
{
  1U,                              /* reversed */
  DSADCRDC_MOTOR_POLE_PAIRS,       /* polePairs */
  DSADCRDC_SENSOR_POLE_PAIRS,      /* sensorPolePairs */
  0U,                              /* offset8192 */
  0U, 0U, 0, 0.0F, 0.0F, 0.0F, 0.0F,
  0, 0, 0, 0, 0U,
  0U, 0U, 0U, 0U,
  0U, 0U,
  DSADCRDC_STATE_UNINIT
};

static sint32 DsadcRdc_CosFiltAcc = 0;
static sint32 DsadcRdc_SinFiltAcc = 0;
static uint8 DsadcRdc_FilterInit = 0U;
static uint16 DsadcRdc_PrevSensor8192 = 0U;
static uint8 DsadcRdc_UnwrapInit = 0U;
static float32 DsadcRdc_PrevElecRad = 0.0F;
static uint8 DsadcRdc_SpeedInit = 0U;

static sint32 DsadcRdc_LpfStep(const sint32 prev, const sint32 sample)
{
  return prev + ((sample - prev) >> DSADCRDC_LPF_SHIFT);
}

static uint32 DsadcRdc_CalcAmplSq(const sint32 cosV, const sint32 sinV)
{
  return (uint32)((cosV * cosV) + (sinV * sinV));
}

static void DsadcRdc_UpdateSpeed(const float32 elecRad, const uint8 motorPp)
{
  float32 err;

  if (DsadcRdc_SpeedInit == 0U)
  {
    DsadcRdc_PrevElecRad = elecRad;
    DsadcRdc_SpeedInit = 1U;
    Tas2143.angleSpeed = 0.0F;
    Tas2143.angleSpeedFilt = 0.0F;
    Tas2143.rpm = 0.0F;
    return;
  }

  err = elecRad - DsadcRdc_PrevElecRad;
  if (err > DSADCRDC_PI)
  {
    err -= DSADCRDC_TWO_PI;
  }
  else if (err < -DSADCRDC_PI)
  {
    err += DSADCRDC_TWO_PI;
  }

  Tas2143.angleSpeed = err / DSADCRDC_TS;
  Tas2143.angleSpeedFilt = (Tas2143.angleSpeedFilt * 0.9F) + (Tas2143.angleSpeed * 0.1F);
  Tas2143.rpm = Tas2143.angleSpeedFilt * DSADCRDC_RAD_S_TO_RPM / (float32)motorPp;
  DsadcRdc_PrevElecRad = elecRad;
}

static void DsadcRdc_UpdateElectricalAngle(void)
{
  float32 ang;
  uint32 sensor;
  sint32 err;
  sint32 integ;
  sint32 elec;
  sint32 span;
  uint8 motorPp;
  uint8 sensorPp;

  ang = atan2f((float32)Tas2143.sinFilt, (float32)Tas2143.cosFilt);
  if (ang < 0.0F)
  {
    ang += DSADCRDC_TWO_PI;
  }

  sensor = (uint32)(ang * MOTORFOC_SINCOS_RAD_TO_IDX);
  if (Tas2143.reversed != 0U)
  {
    sensor = (MOTORFOC_SINCOS_TABLE_SIZE - sensor) & MOTORFOC_SINCOS_IDX_MASK;
  }
  sensor &= MOTORFOC_SINCOS_IDX_MASK;
  Tas2143.sensorRaw8192 = (uint16)sensor;

  if (DsadcRdc_UnwrapInit == 0U)
  {
    DsadcRdc_PrevSensor8192 = (uint16)sensor;
    Tas2143.angleIntegral = (sint32)sensor;
    DsadcRdc_UnwrapInit = 1U;
  }
  else
  {
    err = (sint32)sensor - (sint32)DsadcRdc_PrevSensor8192;
    if (err > ((sint32)MOTORFOC_SINCOS_TABLE_SIZE / 2))
    {
      err -= (sint32)MOTORFOC_SINCOS_TABLE_SIZE;
    }
    else if (err < -((sint32)MOTORFOC_SINCOS_TABLE_SIZE / 2))
    {
      err += (sint32)MOTORFOC_SINCOS_TABLE_SIZE;
    }
    Tas2143.angleIntegral += err;
    DsadcRdc_PrevSensor8192 = (uint16)sensor;
  }

  motorPp = Tas2143.polePairs;
  sensorPp = Tas2143.sensorPolePairs;
  if (motorPp == 0U)
  {
    motorPp = 1U;
  }
  if (sensorPp == 0U)
  {
    sensorPp = 1U;
  }

  span = (sint32)MOTORFOC_SINCOS_TABLE_SIZE * (sint32)sensorPp;
  integ = Tas2143.angleIntegral;
  while (integ >= span)
  {
    integ -= span;
  }
  while (integ < 0)
  {
    integ += span;
  }
  Tas2143.angleIntegral = integ;

  elec = (integ * (sint32)motorPp) / (sint32)sensorPp;
  elec %= (sint32)MOTORFOC_SINCOS_TABLE_SIZE;
  if (elec < 0)
  {
    elec += (sint32)MOTORFOC_SINCOS_TABLE_SIZE;
  }
  elec = (elec + (sint32)Tas2143.offset8192) & (sint32)MOTORFOC_SINCOS_IDX_MASK;
  Tas2143.angleRaw8192 = (uint16)elec;
  Tas2143.angleRad = (float32)elec / MOTORFOC_SINCOS_RAD_TO_IDX;
  DsadcRdc_UpdateSpeed(Tas2143.angleRad, motorPp);
}

static Std_ReturnType DsadcRdc_ReadChannel(const Dsadc_ChannelType chId,
                                           const Dsadc_ChannelType hwChId,
                                           Dsadc_ResultType *const result)
{
  if (result == NULL_PTR)
  {
    return E_NOT_OK;
  }

  Dsadc_Isr(hwChId);

  if (Dsadc_GetStatus(chId) != DSADC_RESULT_READY)
  {
    return E_NOT_OK;
  }

  return Dsadc_ReadResult(chId, result);
}

void DsadcRdc_Init(void)
{
  const Std_ReturnType cosStart = Dsadc_StartModulation(DSADCRDC_CH_COS);
  const Std_ReturnType sinStart = Dsadc_StartModulation(DSADCRDC_CH_SIN);

  Tas2143.cosValid = 0U;
  Tas2143.sinValid = 0U;
  Tas2143.readOkCount = 0U;
  Tas2143.readFailCount = 0U;
  Tas2143.cosRaw = 0;
  Tas2143.sinRaw = 0;
  Tas2143.cosFilt = 0;
  Tas2143.sinFilt = 0;
  Tas2143.amplSq = 0U;
  Tas2143.cosStatus = 0U;
  Tas2143.sinStatus = 0U;
  Tas2143.angleRaw8192 = 0U;
  Tas2143.sensorRaw8192 = 0U;
  Tas2143.angleIntegral = 0;
  Tas2143.angleRad = 0.0F;
  Tas2143.angleSpeed = 0.0F;
  Tas2143.angleSpeedFilt = 0.0F;
  Tas2143.rpm = 0.0F;
  DsadcRdc_CosFiltAcc = 0;
  DsadcRdc_SinFiltAcc = 0;
  DsadcRdc_FilterInit = 0U;
  DsadcRdc_PrevSensor8192 = 0U;
  DsadcRdc_UnwrapInit = 0U;
  DsadcRdc_PrevElecRad = 0.0F;
  DsadcRdc_SpeedInit = 0U;

  if ((cosStart == E_OK) && (sinStart == E_OK))
  {
    Tas2143.state = DSADCRDC_STATE_RUNNING;
  }
  else
  {
    Tas2143.state = DSADCRDC_STATE_UNINIT;
  }
}

void DsadcRdc_MainFunction(void)
{
  Dsadc_ResultType cosSample = 0;
  Dsadc_ResultType sinSample = 0;
  Std_ReturnType cosRc;
  Std_ReturnType sinRc;
  sint32 cosFilt;
  sint32 sinFilt;

  if (Tas2143.state != DSADCRDC_STATE_RUNNING)
  {
    return;
  }

  cosRc = DsadcRdc_ReadChannel(DSADCRDC_CH_COS, DSADCRDC_HW_CH_COS, &cosSample);
  sinRc = DsadcRdc_ReadChannel(DSADCRDC_CH_SIN, DSADCRDC_HW_CH_SIN, &sinSample);

  Tas2143.cosStatus = (uint8)Dsadc_GetStatus(DSADCRDC_CH_COS);
  Tas2143.sinStatus = (uint8)Dsadc_GetStatus(DSADCRDC_CH_SIN);

  if ((cosRc != E_OK) || (sinRc != E_OK))
  {
    Tas2143.readFailCount++;
    return;
  }

  Tas2143.cosRaw = (sint16)cosSample;
  Tas2143.sinRaw = (sint16)sinSample;

  if (DsadcRdc_FilterInit == 0U)
  {
    DsadcRdc_CosFiltAcc = (sint32)cosSample;
    DsadcRdc_SinFiltAcc = (sint32)sinSample;
    DsadcRdc_FilterInit = 1U;
  }
  else
  {
    DsadcRdc_CosFiltAcc = DsadcRdc_LpfStep(DsadcRdc_CosFiltAcc, (sint32)cosSample);
    DsadcRdc_SinFiltAcc = DsadcRdc_LpfStep(DsadcRdc_SinFiltAcc, (sint32)sinSample);
  }

  cosFilt = DsadcRdc_CosFiltAcc;
  sinFilt = DsadcRdc_SinFiltAcc;
  Tas2143.cosFilt = (sint16)cosFilt;
  Tas2143.sinFilt = (sint16)sinFilt;
  Tas2143.amplSq = DsadcRdc_CalcAmplSq(cosFilt, sinFilt);
  DsadcRdc_UpdateElectricalAngle();

  Tas2143.cosValid = 1U;
  Tas2143.sinValid = 1U;
  Tas2143.readOkCount++;
}

DsadcRdc_StateType DsadcRdc_GetState(void)
{
  return Tas2143.state;
}

Std_ReturnType DsadcRdc_GetSinCos(sint16 *const cosOut, sint16 *const sinOut)
{
  if ((cosOut == NULL_PTR) || (sinOut == NULL_PTR))
  {
    return E_NOT_OK;
  }
  if ((Tas2143.cosValid == 0U) || (Tas2143.sinValid == 0U))
  {
    return E_NOT_OK;
  }
  *cosOut = Tas2143.cosFilt;
  *sinOut = Tas2143.sinFilt;
  return E_OK;
}

Std_ReturnType DsadcRdc_GetSinCosRaw(sint16 *const cosOut, sint16 *const sinOut)
{
  if ((cosOut == NULL_PTR) || (sinOut == NULL_PTR))
  {
    return E_NOT_OK;
  }
  if ((Tas2143.cosValid == 0U) || (Tas2143.sinValid == 0U))
  {
    return E_NOT_OK;
  }
  *cosOut = Tas2143.cosRaw;
  *sinOut = Tas2143.sinRaw;
  return E_OK;
}

Std_ReturnType DsadcRdc_GetElectricalAngle(uint16 *angleRaw8192, float32 *angleRad)
{
  if ((angleRaw8192 == NULL_PTR) || (angleRad == NULL_PTR))
  {
    return E_NOT_OK;
  }
  if ((Tas2143.cosValid == 0U) || (Tas2143.sinValid == 0U))
  {
    return E_NOT_OK;
  }

  *angleRaw8192 = Tas2143.angleRaw8192;
  *angleRad = Tas2143.angleRad;
  return E_OK;
}
