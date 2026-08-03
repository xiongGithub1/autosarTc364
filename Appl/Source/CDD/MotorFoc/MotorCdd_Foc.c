/**********************************************************************************************************************
 *  MotorCdd_Foc.c — FOC 快速环调度（Core1，10 kHz）
 *  -------------------------------------------------------------------------------------------------------------------
 *  运行链路：
 *    EVADC 组中断通知(Adc_9183SenseVo1andVro_Notification)
 *      → MotorCdd_AdcGroup0Notification / MotorCdd_AdcRunFastLoop（采样转物理量）
 *      → 本文件 MotorCdd_FocFastLoop
 *  FocFastLoop 每拍职责：
 *    1) 读取 TLE5012 最新角度（QSPI2 直读，同步 32bit 帧）
 *    2) 转换为 13bit 电角度索引（v % 8192，0.044°/LSB，见 tle5012b.c）
 *    3) 按 MotorMode 选择角度源（开环/标定=强制角度；闭环=传感器角度）与电流参考
 *    4) 调用 MotorFoc_RunCurrentLoop（保护 → Clarke/Park/PI/SVPWM → ATOM0 CH1/2/3 占空比）
 * 关键数据：
 *    MotorCdd_CmdMirror    : 1ms 任务(MotorCdd_MainFunction)写入的 模式/Id/Iq 镜像，快速环只读
 *    MotorCdd_LatestAngle  : 最新一帧电角度（本拍读到、本拍电流环直接使用，无缓存滞后）
 *    MotorCdd_AngleFailStreak: 角度连续失败计数（≥10 拍才关输出，容忍单帧抖动）
 *    MotorCdd_FocContext   : 电流环上下文（角度/电流/dq 电压/PWM 输出）
 **********************************************************************************************************************/#include "MotorCdd_Foc.h"
#include "Rte_MotorCdd.h"
#include "MotorMode.h"
#include "MotorControll.h"
#include "MotorCdd_Adc.h"
#include "MotorZeroCal.h"
#include "MotorFoc_OpenLoop.h"
#include "TLE5012/Tle5012bd_Driver.h"
#include "TLE9180/Tle9180_Driver.h"
#include "MotorFoc_CurrentLoop.h"
#include "MotorFoc_SpeedLoop.h"
#include "MotorFoc_SinCosTable.h"
#include "Dio.h"
typedef struct
{
  uint8 mode;
  float32 idRef;
  float32 iqRef;
} MotorCdd_CmdMirrorType;

typedef struct
{
  float32 angleDeg;
  float32 angleRad;
  uint8 valid;
} MotorCdd_LatestAngleType;

MotorFoc_ContextType MotorCdd_FocContext;
volatile uint32 MotorCdd_FocLoopCounter = 0U;

static volatile MotorCdd_CmdMirrorType MotorCdd_CmdMirror;
static volatile MotorCdd_LatestAngleType MotorCdd_LatestAngle;

/* Skip SPI for first ~50 ms after FOC init (sensor SSC settle / power-up). */
#define MOTORCDD_FOC_ANGLE_SPI_BOOT_BLANK_LOOPS   (500U)
/* Stop closed-loop torque only after this many consecutive failed frames. */
#define MOTORCDD_FOC_ANGLE_FAIL_STOP_COUNT   (10U)

static uint16 MotorCdd_AngleSpiBootBlankLeft = MOTORCDD_FOC_ANGLE_SPI_BOOT_BLANK_LOOPS;
volatile uint32 MotorCdd_AngleSpiFastLoopCount = 0U;
static volatile uint16 MotorCdd_AngleFailStreak = 0U;


void MotorCdd_FocInit(void)
{
  MotorCdd_CmdMirror.mode = (uint8)MOTOR_MODE_IDLE;
  MotorCdd_CmdMirror.idRef = 0.0F;
  MotorCdd_CmdMirror.iqRef = 0.0F;
  MotorCdd_LatestAngle.angleDeg = 0.0F;
  MotorCdd_LatestAngle.angleRad = 0.0F;
  MotorCdd_LatestAngle.valid = 0U;
  MotorCdd_AngleSpiBootBlankLeft = MOTORCDD_FOC_ANGLE_SPI_BOOT_BLANK_LOOPS;
  MotorCdd_AngleSpiFastLoopCount = 0U;
  MotorCdd_AngleFailStreak = 0U;

  MotorFoc_CurrentLoopInit(&MotorCdd_FocContext);
  MotorFoc_SpeedLoopInit(&MotorCdd_FocContext);
  MotorFoc_OpenLoop_Init();
  MotorZeroCal_Init();
}

void MotorCdd_FocSetCmdMirror(uint8 motorMode, float32 idRef, float32 iqRef)
{
  MotorCdd_CmdMirror.mode = motorMode;
  MotorCdd_CmdMirror.idRef = idRef;
  MotorCdd_CmdMirror.iqRef = iqRef;
}

void MotorCdd_FocUpdateCmdMirror(void)
{
  uint8 motorMode = (uint8)MOTOR_MODE_IDLE;
  float32 idRef = 0.0F;
  float32 iqRef = 0.0F;

  (void)Rte_Read_Pp_MotorCtrlCmd_MotorMode(&motorMode);
  (void)Rte_Read_Pp_MotorCurrentRef_Id_Ref(&idRef);
  (void)Rte_Read_Pp_MotorCurrentRef_Iq_Ref(&iqRef);
  MotorCdd_FocSetCmdMirror(motorMode, idRef, iqRef);
}

void MotorCdd_FocPublishLatestAngle(float32 angleDeg, float32 angleRad)
{
  MotorCdd_LatestAngle.angleDeg = angleDeg;
  MotorCdd_LatestAngle.angleRad = angleRad;
  MotorCdd_LatestAngle.valid = 1U;
}

void MotorCdd_FocUpdateLatestAngleFromSensor(void)
{
  /* Sensor.Angle is already the electrical angle index (v % 8192, IPB
     convention): 8192 steps per electrical revolution. */
  MotorCdd_FocPublishLatestAngle(Tle5012bd_Sensor.Angle,
                                 Tle5012bd_Sensor.Angle / MOTORFOC_SINCOS_RAD_TO_IDX);
}

static uint8 MotorCdd_FocAngleSpiAllowedInFastLoop(uint8 motorMode)
{
  /* ZeroCal / open-loop use forced angle or own SPI in StartApp ??avoid QSPI2 clash. */
  if ((motorMode == (uint8)MOTOR_MODE_CALIBRATION) ||
      (motorMode == (uint8)MOTOR_MODE_CALIBRATION_ERASE) ||
      (motorMode == (uint8)MOTOR_MODE_CALIBRATION_SAVE) ||
      (motorMode == (uint8)MOTOR_MODE_OPEN_LOOP))
  {
    return 0U;
  }
  return 1U;
}

/*
 * QSPI2 SFR exchange (no MCAL SyncTransmit). Reads the latest TLE5012 frame;
 * the current loop consumes it in the same fast-loop beat.
 */
static void MotorCdd_FocServiceAngleSpi(void)
{
  if (MotorCdd_AngleSpiBootBlankLeft > 0U)
  {
    MotorCdd_AngleSpiBootBlankLeft--;
    return;
  }

  if (Tle5012bd_Driver_GetState() != TLE5012BD_STATE_READY)
  {
    return;
  }

  /* ZeroCal / open-loop use forced angle — skip 5012 SPI. */
//  if (MotorCdd_FocAngleSpiAllowedInFastLoop(motorMode) == 0U)
//  {
//    return;
//  }

//  Dio_WriteChannel(DioConf_DioChannel_DioChannel_test2, STD_HIGH);
  if (Tle5012bd_Driver_ReadAngle(&Tle5012bd_Sensor) == E_OK)
  {
    MotorCdd_AngleFailStreak = 0U;
    MotorCdd_FocUpdateLatestAngleFromSensor();
    MotorCdd_AngleSpiFastLoopCount++;
  }
  else
  {
    if (MotorCdd_AngleFailStreak < 0xFFFFU)
    {
      MotorCdd_AngleFailStreak++;
    }
  }
//  Dio_WriteChannel(DioConf_DioChannel_DioChannel_test2, STD_LOW);
}

void MotorCdd_FocPrepareOutputEnable(void)
{
  MotorFoc_CurrentLoopPreparePwmNeutral(&MotorCdd_FocContext);
  MotorCdd_AdcSynchronizePwmTriggerCounter();
  MotorFoc_CurrentLoopClearFault();
  MotorFoc_CurrentLoopArmStartupBlanking();
}

void MotorCdd_FocStopOutput(void)
{
  MotorFoc_CurrentLoopStop(&MotorCdd_FocContext);
}

void MotorCdd_FocClearFault(void)
{
  MotorFoc_CurrentLoopClearFault();
}

uint8 MotorCdd_FocHasFault(void)
{
  return MotorFoc_ProtObs.fault.active;
}

static void MotorCdd_ApplyLatestAngle(uint8 useForcedAngle, float32 forcedAngleRad)
{
  if (useForcedAngle != 0U)
  {
    /* Map forced rad ??8192-count index for sin/cos table (open-loop / zero-cal). */
    sint32 sidx = (sint32)(forcedAngleRad * MOTORFOC_SINCOS_RAD_TO_IDX);
    float32 angleRaw = (float32)((uint32)sidx & MOTORFOC_SINCOS_IDX_MASK);

    MotorFoc_SetAngleFromTle5012(&MotorCdd_FocContext, angleRaw, forcedAngleRad);
  }
  else if (MotorCdd_LatestAngle.valid != 0U)
  {
    /* Latest frame read in this fast loop: use it immediately. */
    MotorFoc_SetAngleFromTle5012(&MotorCdd_FocContext,
                                 MotorCdd_LatestAngle.angleDeg,
                                 MotorCdd_LatestAngle.angleRad);
  }
  else
  {
    /* Keep previous FOC angle until 1 ms path publishes the first sample. */
  }
}

static void MotorCdd_RunFocCurrentControl(float32 idRef,
                                          float32 iqRef,
                                          uint8 useForcedAngle,
                                          float32 forcedAngleRad)
{
  const MotorCdd_AdcPhysicalType* adcPhysical;

  if (Tle9180_Driver_GetState() != TLE9180_DRV_STATE_READY)
  {
    return;
  }

  if (MotorCdd_AdcIsCurrentOffsetReady() == 0U)
  {
    MotorCdd_AdcAccumulateCurrentOffset();
    return;
  }

  if (MotorControll_IsOutputEnabled() == 0U)
  {
    return;
  }

  /* Closed-loop torque needs a validated encoder frame. A single failed frame
     is tolerated: keep the last valid angle and keep running; stop only when
     the sensor fails for MOTORCDD_FOC_ANGLE_FAIL_STOP_COUNT beats in a row. */
  if (useForcedAngle == 0U)
  {
    if (MotorCdd_LatestAngle.valid == 0U)
    {
      /* No valid frame yet (e.g. sensor boot blanking): wait for first frame. */
      return;
    }

    if (MotorCdd_AngleFailStreak >= MOTORCDD_FOC_ANGLE_FAIL_STOP_COUNT)
    {
      MotorCdd_FocStopOutput();
      return;
    }
  }

  adcPhysical = MotorCdd_GetAdcPhysical();
  MotorFoc_SetIdRef(&MotorCdd_FocContext, idRef);
  MotorFoc_SetIqRef(&MotorCdd_FocContext, iqRef);
  MotorCdd_ApplyLatestAngle(useForcedAngle, forcedAngleRad);

  MotorFoc_UpdateCurrentFromAdc(&MotorCdd_FocContext,
                                adcPhysical->iu_A,
                                adcPhysical->iv_A,
                                adcPhysical->iw_A,
                                adcPhysical->vinv_V);
  MotorFoc_UpdateRawCurrentForProtection(adcPhysical->iuRaw_A,
                                          adcPhysical->ivRaw_A,
                                          adcPhysical->iwRaw_A);
  MotorFoc_RunCurrentLoop(&MotorCdd_FocContext);
}

void MotorCdd_FocFastLoop(void)
{
  MotorMode_Type motorMode;
  float32 idRef;
  float32 iqRef;

  MotorCdd_FocLoopCounter++;

  motorMode = (MotorMode_Type)MotorCdd_CmdMirror.mode;
  idRef = MotorCdd_CmdMirror.idRef;
  iqRef = MotorCdd_CmdMirror.iqRef;


  /* Get the latest TLE5012 frame; the current loop uses it in this beat. */
  MotorCdd_FocServiceAngleSpi();

  switch (motorMode)
  {
    case MOTOR_MODE_CALIBRATION:
      MotorZeroCal_FastLoopStep();
      if ((Tle9180_Driver_GetState() == TLE9180_DRV_STATE_READY) &&
          (MotorCdd_AdcIsCurrentOffsetReady() != 0U) &&
          (MotorControll_IsOutputEnabled() != 0U) &&
          (MotorFoc_ProtObs.fault.active == 0U))
      {
        MotorZeroCal_RampAlignCurrentStep();
      }
      MotorCdd_RunFocCurrentControl(MotorZeroCal_GetAlignCurrentA(),
                                    0.0F,
                                    1U,
                                    MotorZeroCal_GetForcedAngleRad());
      break;

    case MOTOR_MODE_OPEN_LOOP:
      /* The open-loop module owns startup sequencing and reference ramps. */
      MotorFoc_OpenLoop_FastLoopStep(idRef, iqRef);
      MotorCdd_RunFocCurrentControl(MotorFoc_OpenLoop_GetIdRefA(),
                                    MotorFoc_OpenLoop_GetIqRefA(),
                                    1U,
                                    MotorFoc_OpenLoop_GetForcedAngleRad());
      break;

    case MOTOR_MODE_FOC_SPEED:
    	break;
    case MOTOR_MODE_FOC_CURRENT:
      /* Latest TLE5012 frame read above; run the current loop on it directly. */
      MotorCdd_RunFocCurrentControl(0, iqRef, 0U, 0.0F);
      break;

    case MOTOR_MODE_STOP:
      MotorCdd_CmdMirror.idRef=0;
      MotorCdd_CmdMirror.iqRef=0;

      MotorCdd_FocStopOutput();
      break;

    case MOTOR_MODE_CALIBRATION_ERASE:
    	break;
    case MOTOR_MODE_CALIBRATION_SAVE:
    	break;
    case MOTOR_MODE_IDLE:
        MotorCdd_CmdMirror.idRef=0;
        MotorCdd_CmdMirror.iqRef=0;
        break;
    default:

      break;
  }
}

