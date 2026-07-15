#include "tle5012_test.h"

boolean Tle5012Test_Enabled = TRUE;
boolean Tle5012Test_HwInited = FALSE;
Tle5012bd_StateType Tle5012Test_State = TLE5012BD_STATE_UNINIT;
uint32 Tle5012Test_RunEntryCounter = 0U;
uint32 Tle5012Test_StateNotReadyCounter = 0U;
uint32 Tle5012Test_TestCounter = 0U;
uint32 Tle5012Test_OkCounter = 0U;
uint32 Tle5012Test_FailCounter = 0U;
float32 Tle5012Test_Angle = 0.0F;
float32 Tle5012Test_OriginalAngle = 0.0F;
float32 Tle5012Test_ElectricalAngleRad = 0.0F;
float32 Tle5012Test_AngleSpeed = 0.0F;
float32 Tle5012Test_AngleSpeedFilter = 0.0F;
float32 Tle5012Test_MechanicalRpm = 0.0F;
boolean Tle5012Test_Direction = FALSE;
uint16 Tle5012Test_AngBase = 0U;
uint16 Tle5012Test_RawAval = 0U;
uint16 Tle5012Test_RawAspd = 0U;
uint16 Tle5012Test_RawStat = 0U;
boolean Tle5012Test_AvalValid = FALSE;
boolean Tle5012Test_AspdValid = FALSE;
uint16 Tle5012Test_AvalRawAngle = 0U;
uint16 Tle5012Test_AspdRawSpeed = 0U;
uint32 Tle5012Test_SpiLastTxWord = 0U;
uint32 Tle5012Test_SpiLastRxWord = 0U;
uint16 Tle5012Test_SpiLastTx0 = 0U;
uint16 Tle5012Test_SpiLastTx1 = 0U;
uint16 Tle5012Test_SpiLastRx0 = 0U;
uint16 Tle5012Test_SpiLastRx1 = 0U;
Std_ReturnType Tle5012Test_SpiLastResult = E_NOT_OK;
Std_ReturnType Tle5012Test_SpiLastSetupResult = E_NOT_OK;
Std_ReturnType Tle5012Test_SpiLastTransmitResult = E_NOT_OK;
Spi_SeqResultType Tle5012Test_SpiLastSeqResult = SPI_SEQ_FAILED;
Spi_StatusType Tle5012Test_SpiStatusBefore = SPI_UNINIT;
Spi_StatusType Tle5012Test_SpiStatusAfter = SPI_UNINIT;

static void Tle5012Test_SampleSensor(void);

void Tle5012Test_Init(void)
{
  Tle5012bd_Driver_Init();
  Tle5012Test_State = Tle5012bd_Driver_GetState();
  Tle5012Test_HwInited =
      (boolean)(Tle5012Test_State == TLE5012BD_STATE_READY);
  Tle5012Test_SampleSensor();
}

void Tle5012Test_RunOnce(void)
{
  Tle5012Test_RunEntryCounter++;
  if (Tle5012Test_Enabled != TRUE)
  {
    return;
  }

  Tle5012Test_State = Tle5012bd_Driver_GetState();
  if (Tle5012Test_State != TLE5012BD_STATE_READY)
  {
    Tle5012Test_StateNotReadyCounter++;
    Tle5012Test_FailCounter++;
    return;
  }

  Tle5012bd_Driver_ReadAngle(&Tle5012bd_Sensor);
  Tle5012bd_Driver_ReadAngleSpeed(&Tle5012bd_Sensor);
  Tle5012Test_SampleSensor();

  Tle5012Test_TestCounter++;
  if (Tle5012Test_AvalValid == TRUE)
  {
    Tle5012Test_OkCounter++;
  }
  else
  {
    Tle5012Test_FailCounter++;
  }
}

static void Tle5012Test_SampleSensor(void)
{
  Tle5012Test_Angle = Tle5012bd_Sensor.Angle;
  Tle5012Test_OriginalAngle = Tle5012bd_Sensor.Original_Angle;
  Tle5012Test_ElectricalAngleRad = Tle5012bd_Sensor.anglePi;
  Tle5012Test_AngleSpeed = Tle5012bd_Sensor.AngleSpeed;
  Tle5012Test_AngleSpeedFilter = Tle5012bd_Sensor.AngleSpeedFilter;
  Tle5012Test_MechanicalRpm = Tle5012bd_Sensor.RPM;
  Tle5012Test_Direction = Tle5012bd_Sensor.Direction;
  Tle5012Test_AngBase = Tle5012bd_Sensor.ANG_BASE;

  Tle5012Test_RawAval = tle5012_sfr.AVAL_Type.U;
  Tle5012Test_RawAspd = tle5012_sfr.ASPD_Type.U;
  Tle5012Test_RawStat = tle5012_sfr.STAT_Type.U;
  Tle5012Test_AvalValid = (boolean)tle5012_sfr.AVAL_Type.B.RD_AV;
  Tle5012Test_AspdValid = (boolean)tle5012_sfr.ASPD_Type.B.RD_AS;
  Tle5012Test_AvalRawAngle = tle5012_sfr.AVAL_Type.B.ANG_VAL;
  Tle5012Test_AspdRawSpeed = tle5012_sfr.ASPD_Type.B.ANG_SPD;

  Tle5012Test_SpiLastTxWord = Tle5012bd_SpiLastTxWord;
  Tle5012Test_SpiLastRxWord = Tle5012bd_SpiLastRxWord;
  Tle5012Test_SpiLastTx0 = Tle5012bd_SpiLastTxWords[0];
  Tle5012Test_SpiLastTx1 = Tle5012bd_SpiLastTxWords[1];
  Tle5012Test_SpiLastRx0 = Tle5012bd_SpiLastRxWords[0];
  Tle5012Test_SpiLastRx1 = Tle5012bd_SpiLastRxWords[1];
  Tle5012Test_SpiLastResult = Tle5012bd_SpiLastResult;
  Tle5012Test_SpiLastSetupResult = Tle5012bd_SpiLastSetupResult;
  Tle5012Test_SpiLastTransmitResult = Tle5012bd_SpiLastTransmitResult;
  Tle5012Test_SpiLastSeqResult = Tle5012bd_SpiLastSeqResult;
  Tle5012Test_SpiStatusBefore = Tle5012bd_SpiStatusBefore;
  Tle5012Test_SpiStatusAfter = Tle5012bd_SpiStatusAfter;
}

