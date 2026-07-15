#include "MotorFoc_OpenLoopCan.h"

#include "CanIf.h"
#include "CanIf_Cfg.h"
#include "MotorControll.h"
#include "MotorCdd_Foc.h"
#include "MotorCdd_Adc.h"
#include "MotorFoc_CurrentLoop.h"
#include "MotorFoc_OpenLoop.h"

#define MOTORFOC_OPENLOOPCAN_SEND_DIVIDER       (5U)
#define MOTORFOC_OPENLOOPCAN_CURRENT_SCALE      (100.0F)
#define MOTORFOC_OPENLOOPCAN_VOLTAGE_SCALE      (1000.0F)
#define MOTORFOC_OPENLOOPCAN_VDC_SCALE          (10.0F)
#define MOTORFOC_OPENLOOPCAN_ANGLE_SCALE        (1000.0F)

volatile uint8 MotorFoc_OpenLoopCan_Enable = 1U;
volatile uint8 MotorFoc_OpenLoopCan_LastTxResult = E_NOT_OK;
volatile uint32 MotorFoc_OpenLoopCan_TxCounter = 0UL;
volatile uint32 MotorFoc_OpenLoopCan_TxErrorCounter = 0UL;

static uint8 MotorFoc_OpenLoopCan_Page = MOTORFOC_OPENLOOPCAN_PAGE_CONTROL;
static uint8 MotorFoc_OpenLoopCan_Tick = 0U;
static uint16 MotorFoc_OpenLoopCan_Sequence = 0U;
static uint8 MotorFoc_OpenLoopCan_CurrentMode = (uint8)MOTOR_MODE_IDLE;
static uint8 MotorFoc_OpenLoopCan_Data[MOTORFOC_OPENLOOPCAN_PAYLOAD_LENGTH];

static sint16 MotorFoc_OpenLoopCan_PackS16(float32 value, float32 scale)
{
  float32 scaled = value * scale;
  sint32 rounded;

  if (scaled >= 32767.0F)
  {
    return (sint16)32767;
  }
  if (scaled <= -32768.0F)
  {
    return (sint16)-32768;
  }

  if (scaled >= 0.0F)
  {
    rounded = (sint32)(scaled + 0.5F);
  }
  else
  {
    rounded = (sint32)(scaled - 0.5F);
  }
  return (sint16)rounded;
}

static uint16 MotorFoc_OpenLoopCan_ClampU16(uint32 value)
{
  if (value > 65535UL)
  {
    return 65535U;
  }
  return (uint16)value;
}

static void MotorFoc_OpenLoopCan_PutU16(uint8 index, uint16 value)
{
  MotorFoc_OpenLoopCan_Data[index] = (uint8)(value & 0xFFU);
  MotorFoc_OpenLoopCan_Data[index + 1U] = (uint8)(value >> 8U);
}

static void MotorFoc_OpenLoopCan_PutS16(uint8 index,
                                        float32 value,
                                        float32 scale)
{
  MotorFoc_OpenLoopCan_PutU16(index,
                              (uint16)MotorFoc_OpenLoopCan_PackS16(value, scale));
}

static void MotorFoc_OpenLoopCan_ClearData(void)
{
  uint8 index;

  for (index = 0U; index < MOTORFOC_OPENLOOPCAN_PAYLOAD_LENGTH; index++)
  {
    MotorFoc_OpenLoopCan_Data[index] = 0U;
  }
}

static void MotorFoc_OpenLoopCan_BuildControlPage(void)
{
  const MotorFoc_ContextType* ctx = &MotorCdd_FocContext;
  const MotorCdd_AdcPhysicalType* adc = MotorCdd_GetAdcPhysical();

  MotorFoc_OpenLoopCan_ClearData();
  MotorFoc_OpenLoopCan_Data[0U] = MOTORFOC_OPENLOOPCAN_PAGE_CONTROL;
  MotorFoc_OpenLoopCan_Data[1U] = MotorFoc_OpenLoopCan_CurrentMode;
  MotorFoc_OpenLoopCan_Data[2U] = MotorFoc_CurrentLoopFault;
  MotorFoc_OpenLoopCan_Data[3U] = MotorFoc_CurrentLoopFaultReason;
  MotorFoc_OpenLoopCan_PutU16(4U, MotorFoc_OpenLoopCan_Sequence);

  MotorFoc_OpenLoopCan_PutS16(6U, MotorControll_IdRefOut,
                              MOTORFOC_OPENLOOPCAN_CURRENT_SCALE);
  MotorFoc_OpenLoopCan_PutS16(8U, MotorControll_IqRefOut,
                              MOTORFOC_OPENLOOPCAN_CURRENT_SCALE);
  MotorFoc_OpenLoopCan_PutS16(10U, ctx->idqMeas.real,
                              MOTORFOC_OPENLOOPCAN_CURRENT_SCALE);
  MotorFoc_OpenLoopCan_PutS16(12U, ctx->idqMeas.imag,
                              MOTORFOC_OPENLOOPCAN_CURRENT_SCALE);
  MotorFoc_OpenLoopCan_PutS16(14U, adc->iu_A,
                              MOTORFOC_OPENLOOPCAN_CURRENT_SCALE);
  MotorFoc_OpenLoopCan_PutS16(16U, adc->iv_A,
                              MOTORFOC_OPENLOOPCAN_CURRENT_SCALE);
  MotorFoc_OpenLoopCan_PutS16(18U, adc->iw_A,
                              MOTORFOC_OPENLOOPCAN_CURRENT_SCALE);
  MotorFoc_OpenLoopCan_PutS16(20U, ctx->i_motor.vdc,
                              MOTORFOC_OPENLOOPCAN_VDC_SCALE);
  MotorFoc_OpenLoopCan_PutU16(22U, (uint16)MotorFoc_OpenLoop_AngleRaw);
  MotorFoc_OpenLoopCan_PutS16(24U, ctx->angle.electricalAngleRad,
                              MOTORFOC_OPENLOOPCAN_ANGLE_SCALE);
  MotorFoc_OpenLoopCan_Data[26U] = MotorCdd_AdcCurrentOffsetReady;
  MotorFoc_OpenLoopCan_Data[27U] = (uint8)MotorCdd_AdcOffsetSampleCount;
  MotorFoc_OpenLoopCan_PutU16(28U,
                              (uint16)MotorCdd_GetAdcSyncCompleteCounter());
  MotorFoc_OpenLoopCan_PutU16(30U,
                              (uint16)MotorFoc_OpenLoop_StageCounter);
}

static void MotorFoc_OpenLoopCan_BuildPwmPage(void)
{
  const MotorFoc_ContextType* ctx = &MotorCdd_FocContext;

  MotorFoc_OpenLoopCan_ClearData();
  MotorFoc_OpenLoopCan_Data[0U] = MOTORFOC_OPENLOOPCAN_PAGE_PWM;
  MotorFoc_OpenLoopCan_Data[1U] = MotorFoc_OpenLoopCan_CurrentMode;
  MotorFoc_OpenLoopCan_Data[2U] = MotorFoc_CurrentLoopFault;
  MotorFoc_OpenLoopCan_Data[3U] = MotorFoc_CurrentLoopFaultReason;
  MotorFoc_OpenLoopCan_PutU16(4U, MotorFoc_OpenLoopCan_Sequence);

  MotorFoc_OpenLoopCan_PutS16(6U, ctx->vdqRef.real,
                              MOTORFOC_OPENLOOPCAN_VOLTAGE_SCALE);
  MotorFoc_OpenLoopCan_PutS16(8U, ctx->vdqRef.imag,
                              MOTORFOC_OPENLOOPCAN_VOLTAGE_SCALE);
  MotorFoc_OpenLoopCan_PutS16(10U, ctx->vabRef.real,
                              MOTORFOC_OPENLOOPCAN_VOLTAGE_SCALE);
  MotorFoc_OpenLoopCan_PutS16(12U, ctx->vabRef.imag,
                              MOTORFOC_OPENLOOPCAN_VOLTAGE_SCALE);
  MotorFoc_OpenLoopCan_PutU16(14U,
                              MotorFoc_OpenLoopCan_ClampU16(ctx->Tpwm.pwm_OutU));
  MotorFoc_OpenLoopCan_PutU16(16U,
                              MotorFoc_OpenLoopCan_ClampU16(ctx->Tpwm.pwm_OutV));
  MotorFoc_OpenLoopCan_PutU16(18U,
                              MotorFoc_OpenLoopCan_ClampU16(ctx->Tpwm.pwm_OutW));
  MotorFoc_OpenLoopCan_PutU16(20U,
                              MotorFoc_OpenLoopCan_ClampU16((uint32)ctx->Tpwm.Tpwm));
  MotorFoc_OpenLoopCan_PutS16(22U, ctx->i_motor.vdcMax,
                              MOTORFOC_OPENLOOPCAN_VDC_SCALE);
  MotorFoc_OpenLoopCan_PutS16(24U, MotorFoc_CurrentLoopFaultIuA,
                              MOTORFOC_OPENLOOPCAN_CURRENT_SCALE);
  MotorFoc_OpenLoopCan_PutS16(26U, MotorFoc_CurrentLoopFaultIvA,
                              MOTORFOC_OPENLOOPCAN_CURRENT_SCALE);
  MotorFoc_OpenLoopCan_PutS16(28U, MotorFoc_CurrentLoopFaultIwA,
                              MOTORFOC_OPENLOOPCAN_CURRENT_SCALE);
  MotorFoc_OpenLoopCan_PutS16(30U, MotorFoc_CurrentLoopFaultVdcV,
                              MOTORFOC_OPENLOOPCAN_VDC_SCALE);
}

static void MotorFoc_OpenLoopCan_BuildAdcPage(void)
{
  const MotorCdd_AdcPhysicalType* adc = MotorCdd_GetAdcPhysical();

  MotorFoc_OpenLoopCan_ClearData();
  MotorFoc_OpenLoopCan_Data[0U] = MOTORFOC_OPENLOOPCAN_PAGE_ADC;
  MotorFoc_OpenLoopCan_Data[1U] = MotorCdd_AdcCurrentFilterEnabled;
  MotorFoc_OpenLoopCan_Data[2U] = MotorCdd_AdcCurrentFilterReady;
  MotorFoc_OpenLoopCan_Data[3U] = (uint8)(MotorCdd_AdcCurrentFilterAlpha * 100.0F);
  MotorFoc_OpenLoopCan_PutU16(4U, MotorFoc_OpenLoopCan_Sequence);

  MotorFoc_OpenLoopCan_PutS16(6U, adc->iuRaw_A,
                              MOTORFOC_OPENLOOPCAN_CURRENT_SCALE);
  MotorFoc_OpenLoopCan_PutS16(8U, adc->ivRaw_A,
                              MOTORFOC_OPENLOOPCAN_CURRENT_SCALE);
  MotorFoc_OpenLoopCan_PutS16(10U, adc->iwRaw_A,
                              MOTORFOC_OPENLOOPCAN_CURRENT_SCALE);
  MotorFoc_OpenLoopCan_PutS16(12U, adc->iu_A,
                              MOTORFOC_OPENLOOPCAN_CURRENT_SCALE);
  MotorFoc_OpenLoopCan_PutS16(14U, adc->iv_A,
                              MOTORFOC_OPENLOOPCAN_CURRENT_SCALE);
  MotorFoc_OpenLoopCan_PutS16(16U, adc->iw_A,
                              MOTORFOC_OPENLOOPCAN_CURRENT_SCALE);
  MotorFoc_OpenLoopCan_PutS16(18U, (float32)MotorCdd_AdcPhaseOffsetVo1, 1.0F);
  MotorFoc_OpenLoopCan_PutS16(20U, (float32)MotorCdd_AdcPhaseOffsetVo2, 1.0F);
  MotorFoc_OpenLoopCan_PutS16(22U, (float32)MotorCdd_AdcPhaseOffsetVo3, 1.0F);
  MotorFoc_OpenLoopCan_PutS16(24U, adc->vro_V,
                              MOTORFOC_OPENLOOPCAN_VOLTAGE_SCALE);
  MotorFoc_OpenLoopCan_PutS16(26U, adc->vinv_V,
                              MOTORFOC_OPENLOOPCAN_VOLTAGE_SCALE);
  MotorFoc_OpenLoopCan_PutU16(28U,
                              (uint16)MotorCdd_GetAdcSyncCompleteCounter());
  MotorFoc_OpenLoopCan_PutU16(30U, MotorCdd_AdcOffsetSampleCount);
}

static void MotorFoc_OpenLoopCan_Transmit(void)
{
  PduInfoType pduInfo;
  Std_ReturnType result;

  pduInfo.SduDataPtr = MotorFoc_OpenLoopCan_Data;
  pduInfo.SduLength = MOTORFOC_OPENLOOPCAN_PAYLOAD_LENGTH;
  result = CanIf_Transmit(CanIfTxPduHnd_msg_MyECU_Lamp_oCAN00_41befc25_Tx,
                          &pduInfo);
  MotorFoc_OpenLoopCan_LastTxResult = result;

  if (result == E_OK)
  {
    MotorFoc_OpenLoopCan_TxCounter++;
  }
  else
  {
    MotorFoc_OpenLoopCan_TxErrorCounter++;
  }
}

void MotorFoc_OpenLoopCan_Init(void)
{
  MotorFoc_OpenLoopCan_LastTxResult = E_NOT_OK;
  MotorFoc_OpenLoopCan_TxCounter = 0UL;
  MotorFoc_OpenLoopCan_TxErrorCounter = 0UL;
  MotorFoc_OpenLoopCan_Page = MOTORFOC_OPENLOOPCAN_PAGE_CONTROL;
  MotorFoc_OpenLoopCan_Tick = 0U;
  MotorFoc_OpenLoopCan_Sequence = 0U;
  MotorFoc_OpenLoopCan_CurrentMode = (uint8)MOTOR_MODE_IDLE;
  MotorFoc_OpenLoopCan_ClearData();
}

void MotorFoc_OpenLoopCan_MainFunction(MotorMode_Type motorMode)
{
  if ((motorMode != MOTOR_MODE_OPEN_LOOP) ||
      (MotorFoc_OpenLoopCan_Enable == 0U))
  {
    MotorFoc_OpenLoopCan_Tick = 0U;
    MotorFoc_OpenLoopCan_Page = MOTORFOC_OPENLOOPCAN_PAGE_CONTROL;
    return;
  }

  MotorFoc_OpenLoopCan_CurrentMode = (uint8)motorMode;

  MotorFoc_OpenLoopCan_Tick++;
  if (MotorFoc_OpenLoopCan_Tick < MOTORFOC_OPENLOOPCAN_SEND_DIVIDER)
  {
    return;
  }
  MotorFoc_OpenLoopCan_Tick = 0U;

  if (MotorFoc_OpenLoopCan_Page == MOTORFOC_OPENLOOPCAN_PAGE_CONTROL)
  {
    MotorFoc_OpenLoopCan_BuildControlPage();
    MotorFoc_OpenLoopCan_Page = MOTORFOC_OPENLOOPCAN_PAGE_PWM;
  }
  else if (MotorFoc_OpenLoopCan_Page == MOTORFOC_OPENLOOPCAN_PAGE_PWM)
  {
    MotorFoc_OpenLoopCan_BuildPwmPage();
    MotorFoc_OpenLoopCan_Page = MOTORFOC_OPENLOOPCAN_PAGE_ADC;
  }
  else
  {
    MotorFoc_OpenLoopCan_BuildAdcPage();
    MotorFoc_OpenLoopCan_Page = MOTORFOC_OPENLOOPCAN_PAGE_CONTROL;
  }

  MotorFoc_OpenLoopCan_Sequence++;
  MotorFoc_OpenLoopCan_Transmit();
}
