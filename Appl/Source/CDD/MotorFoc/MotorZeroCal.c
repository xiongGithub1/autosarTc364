#include "MotorZeroCal.h"
#include "MotorMode.h"
#include "MotorControll.h"
#include "MotorFoc_OpenLoop.h"
#include "MotorFoc_CurrentLoop.h"
#include "MotorCdd_Adc.h"
#include "CDD/TLE5012/Tle5012bd_Driver.h"
#include "CDD/TLE5012/TLE5012/tle5012b.h"
#include "CDD/TLE9180/Tle9180_Driver.h"
#include "NvM.h"
#include "NvM_Cfg.h"
#include "Fee.h"
#include "MemIf.h"

/* 0 = skip power-on NvM_ReadBlock (use while debugging Fee/NvM write).
 * 1 = normal production: read DFlash after Fee IDLE. */
#ifndef MOTORZEROCAL_BOOT_NVM_READ
#define MOTORZEROCAL_BOOT_NVM_READ  (1U)
#endif

/* Fee_StateVar.FeeInitGCState: 5=COMPLETE, 6=FAIL (FAIL still reports MEMIF_IDLE). */
#define MOTORZEROCAL_FEE_INITGC_COMPLETE  (5U)
#define MOTORZEROCAL_FEE_INITGC_FAIL      (6U)

typedef struct
{
  uint16 magic;
  uint16 angBase;
} MotorZeroCal_StorageType;

static MotorZeroCal_StorageType MotorZeroCal_Storage;
volatile uint8 MotorZeroCal_NvReadPending = 0U;
volatile uint8 MotorZeroCal_NvWritePending = 0U;
volatile uint8 MotorZeroCal_NvLastOp = 0U;
volatile uint8 MotorZeroCal_NvLastResult = (uint8)NVM_REQ_NOT_OK;
volatile uint8 MotorZeroCal_NvLastApiRet = (uint8)E_NOT_OK;
volatile uint32 MotorZeroCal_NvPendingTicks = 0UL;
static uint8 MotorZeroCal_SavedOpenLoopRampEnable = 1U;
static uint8 MotorZeroCal_SavedOpenLoopControlMode = MOTORFOC_OPENLOOP_CONTROL_CURRENT;
static float32 MotorZeroCal_SavedOpenLoopFixedAngleDeg = 0.0F;
static uint8 MotorZeroCal_OpenLoopConfigSaved = 0U;
/* Timed-cal path: NvM write result drives SAVING → DONE/FAULT. */
static uint8 MotorZeroCal_TimedNvWriteActive = 0U;
/* 1 = Init wants one boot ReadBlock after Fee becomes IDLE. */
static uint8 MotorZeroCal_NvBootReadRequest = 0U;

extern volatile MotorMode_Type MotorControll_MotorModeCmd;

volatile MotorZeroCal_StateType MotorZeroCal_State = MOTORZEROCAL_STATE_IDLE;
volatile uint8 MotorZeroCal_Calibrated = 0U;
volatile uint8 MotorZeroCal_RotorZeroInitialized = 0U;
volatile uint16 MotorZeroCal_AngBase = 0U;
volatile uint32 MotorZeroCal_TimerMs = 0U;
volatile uint32 MotorZeroCal_ElapsedMs = 0UL;
volatile uint8 MotorZeroCal_RetryCount = 0U;
volatile float32 MotorZeroCal_IdRefA = 0.0F;
volatile float32 MotorZeroCal_IdRefTargetA = MOTORZEROCAL_ID_REF_A;
volatile float32 MotorZeroCal_IdRefRampStepA = MOTORZEROCAL_ID_RAMP_STEP_A;
volatile uint8 MotorZeroCal_StartRejectReason = MOTORZEROCAL_START_REJECT_NONE;
volatile uint8 MotorZeroCal_FaultReason = MOTORZEROCAL_FAULT_NONE;
volatile uint32 MotorZeroCal_AlignWaitMs = 0UL;
volatile uint8 MotorZeroCal_NvDirty = 0U;
volatile uint8 MotorZeroCal_NvSaveRequest = 0U;

static uint8 MotorZeroCal_AngBasePendingApply = 0U;
static uint16 MotorZeroCal_PendingAngBase = 0U;
static uint32 MotorZeroCal_AngBaseApplyDelayMs = 0UL;

static void MotorZeroCal_SetCalibratedFlag(uint8 value)
{
  MotorZeroCal_Calibrated = value;
  MotorZeroCal_RotorZeroInitialized = value;
}

static void MotorZeroCal_EnterFault(uint8 reason)
{
  MotorZeroCal_FaultReason = reason;
  MotorZeroCal_State = MOTORZEROCAL_STATE_FAULT;
  MotorZeroCal_TimedNvWriteActive = 0U;
}

static void MotorZeroCal_ApplyAngBase(uint16 angBase)
{
  Tle5012bd_Sensor.ANG_BASE = angBase;
#if (MOTORZEROCAL_SPI_ENABLE == 1U)
  tle5012b_write_fast(MOD_3, angBase);
  tle5012b_read_all();
#endif
}

static void MotorZeroCal_QueueAngBaseApply(uint16 angBase)
{
  MotorZeroCal_PendingAngBase = angBase;
  Tle5012bd_Sensor.ANG_BASE = angBase;
  MotorZeroCal_AngBasePendingApply = 1U;
  MotorZeroCal_AngBaseApplyDelayMs = 0UL;
}

static void MotorZeroCal_ProcessDeferredAngBase(void)
{
  if (MotorZeroCal_AngBasePendingApply == 0U)
  {
    return;
  }

  /* Do not touch sensor SPI while align / flash-hold is active. */
  if ((MotorZeroCal_State == MOTORZEROCAL_STATE_RUNNING) ||
      (MotorZeroCal_State == MOTORZEROCAL_STATE_SAVING))
  {
    return;
  }

  if (MotorZeroCal_AngBaseApplyDelayMs < MOTORZEROCAL_ANG_BASE_APPLY_DELAY_MS)
  {
    MotorZeroCal_AngBaseApplyDelayMs++;
    return;
  }

  MotorZeroCal_ApplyAngBase(MotorZeroCal_PendingAngBase);
  MotorZeroCal_AngBasePendingApply = 0U;
}

/* Boot / power-on only — called after NvM_ReadBlock completes. */
static void MotorZeroCal_LoadFromStorage(void)
{
#if (MOTORZEROCAL_SPI_ENABLE == 1U)
  (void)tle5012b_ChangeAngleDirection(counterclockwise);
#endif

  if (MotorZeroCal_Storage.magic == MOTORZEROCAL_STORAGE_MAGIC)
  {
    MotorZeroCal_SetCalibratedFlag(1U);
    MotorZeroCal_NvDirty = 0U;
    MotorZeroCal_AngBase = MotorZeroCal_Storage.angBase;
    MotorZeroCal_QueueAngBaseApply(MotorZeroCal_AngBase);
  }
  else
  {
    MotorZeroCal_SetCalibratedFlag(0U);
    MotorZeroCal_NvDirty = 0U;
    MotorZeroCal_AngBase = 0U;
    Tle5012bd_Sensor.ANG_BASE = 0U;
#if (MOTORZEROCAL_SPI_ENABLE == 1U)
    tle5012b_read_all();
#endif
  }
}

static void MotorZeroCal_SaveToStorage(void)
{
  MotorZeroCal_Storage.magic = MOTORZEROCAL_STORAGE_MAGIC;
  MotorZeroCal_Storage.angBase = MotorZeroCal_AngBase;
  MotorZeroCal_NvDirty = 1U;
}

static void MotorZeroCal_RequestNvRead(void)
{
  Std_ReturnType apiRet;

  if (MotorZeroCal_NvReadPending != 0U)
  {
    return;
  }

  apiRet = NvM_ReadBlock(NvMConf_NvMBlockDescriptor_NvMBlock_MotorZeroCal,
                         &MotorZeroCal_Storage);
  MotorZeroCal_NvLastApiRet = (uint8)apiRet;

  if (apiRet == E_OK)
  {
    MotorZeroCal_NvReadPending = 1U;
    MotorZeroCal_NvLastOp = 1U;
    MotorZeroCal_NvLastResult = (uint8)NVM_REQ_PENDING;
    MotorZeroCal_NvPendingTicks = 0UL;
  }
  else
  {
    MotorZeroCal_NvLastOp = 1U;
    MotorZeroCal_NvLastResult = (uint8)NVM_REQ_NOT_OK;
    MotorZeroCal_LoadFromStorage();
  }
}

static uint8 MotorZeroCal_RequestNvWrite(void)
{
  Std_ReturnType apiRet;

  if ((MotorZeroCal_NvWritePending != 0U) || (MotorZeroCal_NvReadPending != 0U))
  {
    return 0U;
  }

  apiRet = NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvMBlock_MotorZeroCal,
                          &MotorZeroCal_Storage);
  MotorZeroCal_NvLastApiRet = (uint8)apiRet;

  if (apiRet == E_OK)
  {
    MotorZeroCal_NvWritePending = 1U;
    MotorZeroCal_NvLastOp = 2U;
    MotorZeroCal_NvLastResult = (uint8)NVM_REQ_PENDING;
    MotorZeroCal_NvPendingTicks = 0UL;
    return 1U;
  }

  MotorZeroCal_NvLastOp = 2U;
  MotorZeroCal_NvLastResult = (uint8)NVM_REQ_NOT_OK;
  return 0U;
}

void MotorZeroCal_SaveToFlash(void)
{
  /* Motortask-safe entry: only queue. NvM_WriteBlock runs in StartApp 1 ms. */
  if (MotorControll_IsOutputEnabled() != 0U)
  {
    MotorControll_StopPwm();
  }

  /* Pack current RAM zero into mirror before queue (write uses Storage). */
  MotorZeroCal_SaveToStorage();

  MotorZeroCal_NvSaveRequest = 1U;
  MotorZeroCal_FaultReason = MOTORZEROCAL_FAULT_NONE;
  if (MotorZeroCal_State != MOTORZEROCAL_STATE_SAVING)
  {
    MotorZeroCal_State = MOTORZEROCAL_STATE_SAVING;
    MotorZeroCal_ElapsedMs = 0UL;
  }
}

/* Must run in StartApp 1 ms (not MotorTask): queues NvM_WriteBlock. */
static void MotorZeroCal_ProcessSaveRequest(void)
{
  extern Fee_StateDataType Fee_StateVar;

  if (MotorZeroCal_NvSaveRequest == 0U)
  {
    return;
  }

  if (MotorControll_IsOutputEnabled() != 0U)
  {
    MotorControll_StopPwm();
    return;
  }

  /* Fee InitGC FAIL still reports IDLE — do not WriteBlock. */
  if (Fee_StateVar.FeeInitGCState == MOTORZEROCAL_FEE_INITGC_FAIL)
  {
    MotorZeroCal_NvSaveRequest = 0U;
    MotorZeroCal_EnterFault(MOTORZEROCAL_FAULT_FLASH);
    return;
  }

  /* Wait until Fee idle and InitGC complete. */
  if ((Fee_GetStatus() != MEMIF_IDLE) ||
      (Fee_StateVar.FeeInitGCState != MOTORZEROCAL_FEE_INITGC_COMPLETE))
  {
    return;
  }

  /* Previous write still open — wait. */
  if (MotorZeroCal_NvWritePending != 0U)
  {
    return;
  }

  /* Drop stuck boot read so WriteBlock is not rejected with DET BLOCK_PENDING. */
  if (MotorZeroCal_NvReadPending != 0U)
  {
    (void)NvM_CancelJobs(NvMConf_NvMBlockDescriptor_NvMBlock_MotorZeroCal);
    MotorZeroCal_NvReadPending = 0U;
    MotorZeroCal_NvPendingTicks = 0UL;
  }

  MotorZeroCal_NvSaveRequest = 0U;
  MotorZeroCal_TimedNvWriteActive = 1U;
  MotorZeroCal_State = MOTORZEROCAL_STATE_SAVING;
  MotorZeroCal_ElapsedMs = 0UL;
  MotorZeroCal_FaultReason = MOTORZEROCAL_FAULT_NONE;

  if (MotorZeroCal_RequestNvWrite() == 0U)
  {
    MotorZeroCal_EnterFault(MOTORZEROCAL_FAULT_FLASH);
  }
}

static void MotorZeroCal_ProcessNvJobs(void)
{
  Std_ReturnType apiRet;
  NvM_RequestResultType requestResult;

  if (MotorZeroCal_NvReadPending != 0U)
  {
    apiRet = NvM_GetErrorStatus(NvMConf_NvMBlockDescriptor_NvMBlock_MotorZeroCal,
                                &requestResult);
    MotorZeroCal_NvLastApiRet = (uint8)apiRet;

    if (apiRet == E_OK)
    {
      if (requestResult == NVM_REQ_PENDING)
      {
        MotorZeroCal_NvLastResult = (uint8)requestResult;
        MotorZeroCal_NvPendingTicks++;
        if (MotorZeroCal_NvPendingTicks > 5000UL)
        {
          /* Timeout: drop app flag AND cancel NvM job, else block stays PENDING
           * and a later WriteBlock hits DET → Det_EndlessLoop (looks like CoreFreeze). */
          (void)NvM_CancelJobs(NvMConf_NvMBlockDescriptor_NvMBlock_MotorZeroCal);
          MotorZeroCal_NvReadPending = 0U;
          MotorZeroCal_NvLastResult = (uint8)NVM_REQ_NOT_OK;
          MotorZeroCal_NvPendingTicks = 0UL;
          MotorZeroCal_Storage.magic = 0U;
          MotorZeroCal_Storage.angBase = 0U;
          MotorZeroCal_LoadFromStorage();
        }
        return;
      }

      MotorZeroCal_NvReadPending = 0U;
      MotorZeroCal_NvLastResult = (uint8)requestResult;
      MotorZeroCal_NvPendingTicks = 0UL;
      if (requestResult != NVM_REQ_OK)
      {
        MotorZeroCal_Storage.magic = 0U;
        MotorZeroCal_Storage.angBase = 0U;
      }
      MotorZeroCal_LoadFromStorage();
    }
  }

  if (MotorZeroCal_NvWritePending != 0U)
  {
    apiRet = NvM_GetErrorStatus(NvMConf_NvMBlockDescriptor_NvMBlock_MotorZeroCal,
                                &requestResult);
    MotorZeroCal_NvLastApiRet = (uint8)apiRet;

    if (apiRet == E_OK)
    {
      if (requestResult != NVM_REQ_PENDING)
      {
        MotorZeroCal_NvWritePending = 0U;
        MotorZeroCal_NvPendingTicks = 0UL;
        MotorZeroCal_NvLastResult = (uint8)requestResult;

        if (MotorZeroCal_TimedNvWriteActive != 0U)
        {
          MotorZeroCal_TimedNvWriteActive = 0U;
          if (requestResult == NVM_REQ_OK)
          {
            MotorZeroCal_NvDirty = 0U;
            if (MotorZeroCal_State == MOTORZEROCAL_STATE_SAVING)
            {
              MotorZeroCal_State = MOTORZEROCAL_STATE_DONE;
            }
          }
          else
          {
            /* RAM zero remains valid this session; Flash not updated. */
            if (MotorZeroCal_State == MOTORZEROCAL_STATE_SAVING)
            {
              MotorZeroCal_EnterFault(MOTORZEROCAL_FAULT_FLASH);
            }
          }
        }
        else if (requestResult == NVM_REQ_OK)
        {
          MotorZeroCal_NvDirty = 0U;
        }
      }
      else
      {
        MotorZeroCal_NvPendingTicks++;
        MotorZeroCal_NvLastResult = (uint8)requestResult;
      }
    }
  }
}

static void MotorZeroCal_PrepareOpenLoopAlign(void)
{
  if (MotorZeroCal_OpenLoopConfigSaved == 0U)
  {
    MotorZeroCal_SavedOpenLoopRampEnable = MotorFoc_OpenLoop_RampEnable;
    MotorZeroCal_SavedOpenLoopControlMode = MotorFoc_OpenLoop_ControlMode;
    MotorZeroCal_SavedOpenLoopFixedAngleDeg = MotorFoc_OpenLoop_FixedAngleDeg;
    MotorZeroCal_OpenLoopConfigSaved = 1U;
  }

  MotorFoc_OpenLoop_Reset();
  MotorFoc_OpenLoop_RampEnable = 0U;
  MotorFoc_OpenLoop_FixedAngleDeg = MOTORZEROCAL_ALIGN_ANGLE_DEG;
  MotorFoc_OpenLoop_ControlMode = MOTORFOC_OPENLOOP_CONTROL_CURRENT;
  MotorFoc_OpenLoop_FastLoopStep();
}

static void MotorZeroCal_RestoreOpenLoopConfig(void)
{
  if (MotorZeroCal_OpenLoopConfigSaved != 0U)
  {
    MotorFoc_OpenLoop_RampEnable = MotorZeroCal_SavedOpenLoopRampEnable;
    MotorFoc_OpenLoop_ControlMode = MotorZeroCal_SavedOpenLoopControlMode;
    MotorFoc_OpenLoop_FixedAngleDeg = MotorZeroCal_SavedOpenLoopFixedAngleDeg;
    MotorZeroCal_OpenLoopConfigSaved = 0U;
  }
}

static void MotorZeroCal_RampAlignCurrent(void)
{
  float32 target = MotorZeroCal_IdRefTargetA;
  float32 step = MotorZeroCal_IdRefRampStepA;

  if (target < 0.0F)
  {
    target = 0.0F;
  }
  if (step < 0.0F)
  {
    step = -step;
  }
  if (step <= 0.0F)
  {
    step = MOTORZEROCAL_ID_RAMP_STEP_A;
  }

  if ((target - MotorZeroCal_IdRefA) > step)
  {
    MotorZeroCal_IdRefA += step;
  }
  else
  {
    MotorZeroCal_IdRefA = target;
  }
}

static uint8 MotorZeroCal_IsAlignCurrentReached(void)
{
  float32 target = MotorZeroCal_IdRefTargetA;
  float32 eps = MOTORZEROCAL_ID_REACHED_EPS_A;

  if (target < 0.0F)
  {
    target = 0.0F;
  }
  if (eps < 0.0F)
  {
    eps = -eps;
  }

  if ((target - MotorZeroCal_IdRefA) <= eps)
  {
    return 1U;
  }

  return 0U;
}

static void MotorZeroCal_ChangeAngleBasicFromAval(void)
{
#if (MOTORZEROCAL_SPI_ENABLE == 1U)
  uint16 angleBasic;

  tle5012b_read_angle(&Tle5012bd_Sensor);
  angleBasic = (uint16)Tle5012bd_Sensor.Original_Angle;
  tle5012b_ChangeAngleBasic(&Tle5012bd_Sensor, angleBasic);
#else
  /* SPI bring-up: skip sensor write path. */
#endif
}

static void MotorZeroCal_OnAlignSuccess(void)
{
  /* Align OK: RAM first, then queue DFlash write (NvM_WriteBlock in StartApp 1 ms). */
  MotorZeroCal_AngBase = Tle5012bd_Sensor.ANG_BASE;
  MotorZeroCal_SaveToStorage();
  MotorZeroCal_SetCalibratedFlag(1U);
  MotorZeroCal_TimerMs = 0U;
  MotorZeroCal_RetryCount = 0U;
  MotorZeroCal_TimedNvWriteActive = 0U;
  /* Stop PWM + queue NvM write; State becomes SAVING until NvM_REQ_OK. */
  MotorZeroCal_SaveToFlash();
}

static void MotorZeroCal_RunCalibrationStep(void)
{
  float32 angle;
  uint32 settleMs;

  if (MotorZeroCal_State != MOTORZEROCAL_STATE_RUNNING)
  {
    return;
  }

  if (MotorFoc_CurrentLoopFault != 0U)
  {
    MotorZeroCal_SetCalibratedFlag(0U);
    MotorZeroCal_EnterFault(MOTORZEROCAL_FAULT_CURRENT);
    return;
  }

  if (MotorZeroCal_IsAlignCurrentReached() == 0U)
  {
    MotorZeroCal_TimerMs = 0U;
    if (MotorControll_IsOutputEnabled() != 0U)
    {
      MotorZeroCal_AlignWaitMs++;
    }
    return;
  }

  MotorZeroCal_AlignWaitMs = 0UL;
  MotorZeroCal_TimerMs++;

  settleMs = (MotorZeroCal_RetryCount == 0U) ?
             (uint32)MOTORZEROCAL_DELAY_MS :
             (uint32)MOTORZEROCAL_RETRY_DELAY_MS;

  if (MotorZeroCal_TimerMs <= settleMs)
  {
    return;
  }

#if (MOTORZEROCAL_SPI_ENABLE == 1U)
  tle5012b_read_angle(&Tle5012bd_Sensor);
  angle = Tle5012bd_Sensor.Angle;

  if ((angle <= MOTORZEROCAL_ANGLE_OK_LOW) ||
      (angle >= MOTORZEROCAL_ANGLE_OK_HIGH))
  {
    MotorZeroCal_OnAlignSuccess();
  }
  else
  {
    MotorZeroCal_ChangeAngleBasicFromAval();
    MotorZeroCal_RetryCount++;

    if (MotorZeroCal_RetryCount >= MOTORZEROCAL_MAX_RETRY)
    {
      MotorZeroCal_RetryCount = 0U;
      MotorZeroCal_SetCalibratedFlag(0U);
      MotorZeroCal_EnterFault(MOTORZEROCAL_FAULT_ALIGN);
    }
    else
    {
      /* Let the encoder apply ANG_BASE before checking the new zero. */
      MotorZeroCal_TimerMs = 0U;
    }
  }
#else
  (void)angle;
  /* SPI bring-up: do not touch TLE5012 from ZeroCal. */
  MotorZeroCal_EnterFault(MOTORZEROCAL_FAULT_ALIGN);
#endif
}

static void MotorZeroCal_CheckTotalTimeout(void)
{
  if (MotorZeroCal_State == MOTORZEROCAL_STATE_RUNNING)
  {
    MotorZeroCal_ElapsedMs++;
    if (MotorZeroCal_ElapsedMs > MOTORZEROCAL_TOTAL_TIMEOUT_MS)
    {
      MotorZeroCal_SetCalibratedFlag(0U);
      MotorZeroCal_EnterFault(MOTORZEROCAL_FAULT_TIMEOUT);
    }
    return;
  }

  /* Flash save (PWM already off): allow longer Fee GC erase, still bound. */
  if (MotorZeroCal_State == MOTORZEROCAL_STATE_SAVING)
  {
    MotorZeroCal_ElapsedMs++;
    if (MotorZeroCal_ElapsedMs > (MOTORZEROCAL_TOTAL_TIMEOUT_MS * 4U))
    {
      MotorZeroCal_SetCalibratedFlag(1U);
      MotorZeroCal_NvDirty = 1U;
      MotorZeroCal_TimedNvWriteActive = 0U;
      MotorZeroCal_EnterFault(MOTORZEROCAL_FAULT_TIMEOUT);
    }
  }
}

void MotorZeroCal_Init(void)
{
  MotorZeroCal_State = MOTORZEROCAL_STATE_IDLE;
  MotorZeroCal_TimerMs = 0U;
  MotorZeroCal_ElapsedMs = 0UL;
  MotorZeroCal_RetryCount = 0U;
  MotorZeroCal_AlignWaitMs = 0UL;
  MotorZeroCal_StartRejectReason = MOTORZEROCAL_START_REJECT_NONE;
  MotorZeroCal_FaultReason = MOTORZEROCAL_FAULT_NONE;
  MotorZeroCal_AngBasePendingApply = 0U;
  MotorZeroCal_PendingAngBase = 0U;
  MotorZeroCal_AngBaseApplyDelayMs = 0UL;
  MotorZeroCal_Storage.magic = 0U;
  MotorZeroCal_Storage.angBase = 0U;
  MotorZeroCal_NvReadPending = 0U;
  MotorZeroCal_NvWritePending = 0U;
  MotorZeroCal_NvLastOp = 0U;
  MotorZeroCal_NvLastResult = (uint8)NVM_REQ_NOT_OK;
  MotorZeroCal_NvLastApiRet = (uint8)E_NOT_OK;
  MotorZeroCal_NvPendingTicks = 0UL;
  MotorZeroCal_NvDirty = 0U;
  MotorZeroCal_NvSaveRequest = 0U;
  MotorZeroCal_TimedNvWriteActive = 0U;
  MotorZeroCal_SetCalibratedFlag(0U);
#if (MOTORZEROCAL_BOOT_NVM_READ == 1U)
  /* Do not ReadBlock until Fee leaves INITGC/BUSY — otherwise job stays PENDING forever. */
  MotorZeroCal_NvBootReadRequest = 1U;
#else
  /* Bring-up: leave Fee alone so InitGC can finish; no boot ReadBlock. */
  MotorZeroCal_NvBootReadRequest = 0U;
#endif
}

uint8 MotorZeroCal_CanStart(void)
{
  const MotorCdd_AdcPhysicalType* adcPhysical;
  float32 minVdc;

  MotorZeroCal_StartRejectReason = MOTORZEROCAL_START_REJECT_NONE;

  if ((MotorZeroCal_State == MOTORZEROCAL_STATE_RUNNING) ||
      (MotorZeroCal_State == MOTORZEROCAL_STATE_SAVING))
  {
    MotorZeroCal_StartRejectReason = MOTORZEROCAL_START_REJECT_ALREADY_RUNNING;
    return 0U;
  }

  if (Tle9180_Driver_GetState() != TLE9180_DRV_STATE_READY)
  {
    MotorZeroCal_StartRejectReason = MOTORZEROCAL_START_REJECT_GATE_NOT_READY;
    return 0U;
  }

  adcPhysical = MotorCdd_GetAdcPhysical();
  minVdc = MotorFoc_CurrentLoopMinVdcRunV;
  if (minVdc < 0.0F)
  {
    minVdc = 0.0F;
  }

  if (adcPhysical->vinv_V < (minVdc + 1.0F))
  {
    MotorZeroCal_StartRejectReason = MOTORZEROCAL_START_REJECT_VDC_LOW;
    return 0U;
  }

  return 1U;
}

void MotorZeroCal_Start(void)
{
  MotorZeroCal_SetCalibratedFlag(0U);
  MotorZeroCal_TimerMs = 0U;
  MotorZeroCal_ElapsedMs = 0UL;
  MotorZeroCal_RetryCount = 0U;
  MotorZeroCal_AlignWaitMs = 0UL;
  MotorZeroCal_IdRefA = 0.0F;
  MotorZeroCal_StartRejectReason = MOTORZEROCAL_START_REJECT_NONE;
  MotorZeroCal_FaultReason = MOTORZEROCAL_FAULT_NONE;
  MotorZeroCal_TimedNvWriteActive = 0U;
  MotorZeroCal_PrepareOpenLoopAlign();
  MotorZeroCal_State = MOTORZEROCAL_STATE_RUNNING;
}

void MotorZeroCal_Erase(void)
{
  MotorZeroCal_RestoreOpenLoopConfig();
  MotorZeroCal_Storage.magic = 0U;
  MotorZeroCal_Storage.angBase = 0U;
  MotorZeroCal_SetCalibratedFlag(0U);
  MotorZeroCal_AngBase = 0U;
  MotorZeroCal_IdRefA = 0.0F;
  Tle5012bd_Sensor.ANG_BASE = 0U;
  MotorZeroCal_State = MOTORZEROCAL_STATE_IDLE;
  MotorZeroCal_TimerMs = 0U;
  MotorZeroCal_ElapsedMs = 0UL;
  MotorZeroCal_RetryCount = 0U;
  MotorZeroCal_FaultReason = MOTORZEROCAL_FAULT_NONE;
  MotorZeroCal_TimedNvWriteActive = 0U;
  /* RAM cleared; persist erase with MOTOR_MODE_CALIBRATION_SAVE / NvSaveRequest. */
  MotorZeroCal_NvDirty = 1U;
}

uint8 MotorZeroCal_IsRotorZeroInitialized(void)
{
  return MotorZeroCal_Calibrated;
}

uint8 MotorZeroCal_UseForcedAngle(void)
{
  if (MotorZeroCal_State == MOTORZEROCAL_STATE_RUNNING)
  {
    return 1U;
  }

  return 0U;
}

float32 MotorZeroCal_GetAlignCurrentA(void)
{
  if (MotorZeroCal_State == MOTORZEROCAL_STATE_RUNNING)
  {
    return MotorZeroCal_IdRefA;
  }

  return 0.0F;
}

float32 MotorZeroCal_GetForcedAngleRad(void)
{
  return MotorFoc_OpenLoop_GetForcedAngleRad();
}

void MotorZeroCal_FastLoopStep(void)
{
  if ((MotorZeroCal_State == MOTORZEROCAL_STATE_RUNNING) ||
      (MotorZeroCal_State == MOTORZEROCAL_STATE_SAVING))
  {
    MotorFoc_OpenLoop_FastLoopStep();
  }
}

void MotorZeroCal_RampAlignCurrentStep(void)
{
  if (MotorZeroCal_State == MOTORZEROCAL_STATE_RUNNING)
  {
    MotorZeroCal_RampAlignCurrent();
  }
}

void MotorZeroCal_MainFunction(void)
{
  extern Fee_StateDataType Fee_StateVar;

  /* Power-on read only after Fee InitGC COMPLETE (FAIL also reports IDLE). */
  if ((MotorZeroCal_NvBootReadRequest != 0U) &&
      (MotorZeroCal_NvReadPending == 0U) &&
      (MotorZeroCal_NvWritePending == 0U) &&
      (Fee_GetStatus() == MEMIF_IDLE) &&
      (Fee_StateVar.FeeInitGCState == MOTORZEROCAL_FEE_INITGC_COMPLETE))
  {
    MotorZeroCal_NvBootReadRequest = 0U;
    MotorZeroCal_RequestNvRead();
  }

  MotorZeroCal_ProcessNvJobs();
  MotorZeroCal_ProcessDeferredAngBase();

  MotorZeroCal_CheckTotalTimeout();

  if (MotorZeroCal_State == MOTORZEROCAL_STATE_RUNNING)
  {
    MotorZeroCal_RunCalibrationStep();
  }

  /* After align success SaveToFlash() — issue NvM_WriteBlock same 1 ms if PWM off. */
  MotorZeroCal_ProcessSaveRequest();

  if (MotorZeroCal_State == MOTORZEROCAL_STATE_DONE)
  {
    MotorZeroCal_RestoreOpenLoopConfig();
    /* Align+Flash done → STOP. */
    if (MotorControll_MotorModeCmd == MOTOR_MODE_CALIBRATION)
    {
      MotorControll_MotorModeCmd = MOTOR_MODE_STOP;
    }
    MotorZeroCal_State = MOTORZEROCAL_STATE_IDLE;
  }
  else if (MotorZeroCal_State == MOTORZEROCAL_STATE_FAULT)
  {
    MotorZeroCal_RestoreOpenLoopConfig();
    MotorControll_MotorModeCmd = MOTOR_MODE_IDLE;
    MotorZeroCal_State = MOTORZEROCAL_STATE_IDLE;
  }
  else
  {
    /* IDLE / RUNNING / SAVING: no exit action. */
  }
}
