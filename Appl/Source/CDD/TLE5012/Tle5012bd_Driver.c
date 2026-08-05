/**********************************************************************************************************************
 *  Tle5012bd_Driver.c — TLE5012B 角度传感器驱动（QSPI2 直读，无 MCAL 开销）
 *  -------------------------------------------------------------------------------------------------------------------
 *  数据约定（与 IPB 项目一致）：
 *    - Original_Angle : 15bit 机械角原始值（0..32767，含 ANG_BASE 偏置）
 *    - Angle          : 13bit 电角度索引 = v % 8192（8192 步/电角度圈，0.044°/LSB）
 *    - anglePi        : 电角度弧度（Angle × 2π/8192）
 *    - RPM            : 机械转速 = 电角速度 × 9.5493 / 极对数（差分 + 滤波）
 *  读取策略（10 kHz 快速环内同步读）：
 *    - RD_AV=1：新角度帧，按快速环计数器差值计算真实帧间隔 dt 用于转速
 *    - RD_AV=0：无新数据（读得比传感器更新快），保持旧角度，计数 AngleNoUpdateCount
 *    - 0xFFFF / SPI 错误：真实故障，SafetyBit++，AngleReadFailCount++
 *  状态：TLE5012BD_STATE_UNINIT / READY（Init 后即 READY）。
 **********************************************************************************************************************/
#include "Tle5012bd_Driver.h"
#include "MotorCdd_Foc.h"
#include "Tle5012bd_Spi.h"

Tle5012 Tle5012bd_Sensor;

static Tle5012bd_StateType Tle5012bd_State = TLE5012BD_STATE_UNINIT;
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
  Tle5012bd_AngleValid = 0U;
  Tle5012bd_AngleReadOkCount = 0U;
  Tle5012bd_AngleReadFailCount = 0U;
  Tle5012bd_AngleLastResult = E_NOT_OK;

  /* Spi_Init must already have run (EcuM). Program QSPI2 ECON for SFR path. */
  Tle5012bd_SpiHwInit();

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
  Std_ReturnType result;
  float32 previousPeriod;

  if ((sensor == NULL_PTR) || (Tle5012bd_State != TLE5012BD_STATE_READY))
  {
    Tle5012bd_Driver_RecordResult(E_NOT_OK);
    return E_NOT_OK;
  }

  if (Tle5012bd_SpiExchangeU32(0x8020FFFFU, &rxWord) != E_OK)
  {
    Tle5012bd_Driver_RecordResult(E_NOT_OK);
    return E_NOT_OK;
  }

  previousPeriod = sensor->DisTimer;
  if (samplePeriod > 0.0F)
  {
    sensor->DisTimer = samplePeriod;
  }
  result = tle5012b_process_angle_raw(sensor, (uint16)(rxWord & 0xFFFFU));
  sensor->DisTimer = previousPeriod;
  Tle5012bd_Driver_RecordResult(result);
  return result;
}

Std_ReturnType Tle5012bd_Driver_ReadAngle(Tle5012 *sensor)
{
  return Tle5012bd_Driver_ReadAngleInternal(sensor, 0.0001F);
}


float32 Tle5012bd_Driver_GetElectricalAngleRad(void)
{
  /* anglePi is already the electrical angle in rad (v % 8192 convention). */
  float32 electricalAngle = Tle5012bd_Sensor.anglePi;

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
