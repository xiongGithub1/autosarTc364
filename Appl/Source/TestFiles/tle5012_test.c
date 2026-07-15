/**********************************************************************************************************************
 * tle5012_test.c - TLE5012 SPI bring-up (TestFiles)
 **********************************************************************************************************************/
#include "tle5012_test.h"

#include "Spi_Cfg.h"

Tle5012Test_ObsType Tle5012Test_Obs =
{
  TRUE,  /* Enabled */
  FALSE, /* HwInited */
  TLE5012BD_STATE_UNINIT,
  0U,
  0U,
  0U,
  0U,
  0U,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  FALSE,
  0U,
  0U,
  0U,
  0U,
  FALSE,
  FALSE,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  E_NOT_OK,
  E_NOT_OK,
  E_NOT_OK,
  SPI_SEQ_FAILED,
  SPI_UNINIT,
  SPI_UNINIT
};

static void Tle5012Test_SampleSensor(void)
{
  Tle5012Test_Obs.AngleDeg = Tle5012bd_Sensor.Angle;
  Tle5012Test_Obs.OriginalAngleDeg = Tle5012bd_Sensor.Original_Angle;
  Tle5012Test_Obs.ElectricalAngleRad = Tle5012bd_Sensor.anglePi;
  Tle5012Test_Obs.AngleSpeed = Tle5012bd_Sensor.AngleSpeed;
  Tle5012Test_Obs.AngleSpeedFilter = Tle5012bd_Sensor.AngleSpeedFilter;
  Tle5012Test_Obs.MechanicalRpm = Tle5012bd_Sensor.RPM;
  Tle5012Test_Obs.Direction = Tle5012bd_Sensor.Direction;
  Tle5012Test_Obs.AngBase = Tle5012bd_Sensor.ANG_BASE;

  Tle5012Test_Obs.RawAval = tle5012_sfr.AVAL_Type.U;
  Tle5012Test_Obs.RawAspd = tle5012_sfr.ASPD_Type.U;
  Tle5012Test_Obs.RawStat = tle5012_sfr.STAT_Type.U;
  Tle5012Test_Obs.AvalValid = (boolean)tle5012_sfr.AVAL_Type.B.RD_AV;
  Tle5012Test_Obs.AspdValid = (boolean)tle5012_sfr.ASPD_Type.B.RD_AS;
  Tle5012Test_Obs.AvalRawAngle = tle5012_sfr.AVAL_Type.B.ANG_VAL;
  Tle5012Test_Obs.AspdRawSpeed = tle5012_sfr.ASPD_Type.B.ANG_SPD;

  Tle5012Test_Obs.SpiTxWord = Tle5012bd_SpiLastTxWord;
  Tle5012Test_Obs.SpiRxWord = Tle5012bd_SpiLastRxWord;
  Tle5012Test_Obs.SpiTx0 = Tle5012bd_SpiLastTxWords[0];
  Tle5012Test_Obs.SpiTx1 = Tle5012bd_SpiLastTxWords[1];
  Tle5012Test_Obs.SpiRx0 = Tle5012bd_SpiLastRxWords[0];
  Tle5012Test_Obs.SpiRx1 = Tle5012bd_SpiLastRxWords[1];
  Tle5012Test_Obs.SpiResult = Tle5012bd_SpiLastResult;
  Tle5012Test_Obs.SpiSetupResult = Tle5012bd_SpiLastSetupResult;
  Tle5012Test_Obs.SpiTransmitResult = Tle5012bd_SpiLastTransmitResult;
  Tle5012Test_Obs.SeqResult = Tle5012bd_SpiLastSeqResult;
  Tle5012Test_Obs.HwUnitBefore = Tle5012bd_SpiStatusBefore;
  Tle5012Test_Obs.HwUnitAfter = Tle5012bd_SpiStatusAfter;
}

void Tle5012Test_Init(void)
{
  Tle5012bd_Driver_Init();
  Tle5012Test_Obs.State = Tle5012bd_Driver_GetState();
  Tle5012Test_Obs.HwInited =
      (boolean)(Tle5012Test_Obs.State == TLE5012BD_STATE_READY);
  Tle5012Test_SampleSensor();
}

void Tle5012Test_RunOnce(void)
{
  Tle5012Test_Obs.RunEntryCounter++;
  if (Tle5012Test_Obs.Enabled != TRUE)
  {
    return;
  }

  Tle5012Test_Obs.State = Tle5012bd_Driver_GetState();
  if (Tle5012Test_Obs.State != TLE5012BD_STATE_READY)
  {
    Tle5012Test_Obs.StateNotReadyCounter++;
    Tle5012Test_Obs.FailCounter++;
    Tle5012Test_Obs.HwUnitBefore = Spi_GetHWUnitStatus(SPI_QSPI2_INDEX);
    Tle5012Test_Obs.HwUnitAfter = Tle5012Test_Obs.HwUnitBefore;
    return;
  }

  Tle5012bd_Driver_ReadAngle(&Tle5012bd_Sensor);
  Tle5012bd_Driver_ReadAngleSpeed(&Tle5012bd_Sensor);
  Tle5012Test_SampleSensor();

  Tle5012Test_Obs.TestCounter++;
  if (Tle5012Test_Obs.AvalValid == TRUE)
  {
    Tle5012Test_Obs.OkCounter++;
  }
  else
  {
    Tle5012Test_Obs.FailCounter++;
  }
}
