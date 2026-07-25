/**********************************************************************************************************************
 * nvm_zerocal_test.c - NvM write first, then apply TLE5012 ANG_BASE on success
 *
 * AUTOSAR: NvM/Fee/Fls MainFunction MUST only run in Default_BSW_ASync_Task (Rte).
 * Do NOT call them from Appl StartApp — dual Main is non-compliant and can corrupt Fee/Fls.
 **********************************************************************************************************************/
#include "nvm_zerocal_test.h"

#include "NvM.h"
#include "NvM_Cfg.h"
#include "Fee.h"
#include "MemIf.h"
#include "Tle5012bd_Driver.h"
#include "tle5012b.h"

extern Fee_StateDataType Fee_StateVar;

static NvmZeroCalTest_StorageType NvmZeroCalTest_Storage;
static uint8 NvmZeroCalTest_WritePending = 0U;
static uint8 NvmZeroCalTest_IssueWrite = 0U;

volatile uint8 NvmZeroCalTest_Request = 0U;
volatile uint16 NvmZeroCalTest_AngBaseToWrite = 0U;
volatile uint8 NvmZeroCalTest_State = NVMZEROCALTEST_STATE_IDLE;
volatile uint8 NvmZeroCalTest_Stage = NVMZEROCALTEST_STAGE_IDLE;
volatile uint8 NvmZeroCalTest_NvLastApiRet = (uint8)E_NOT_OK;
volatile uint8 NvmZeroCalTest_NvLastResult = (uint8)NVM_REQ_NOT_OK;
volatile uint8 NvmZeroCalTest_BlockStatusBeforeWrite = (uint8)NVM_REQ_NOT_OK;
volatile uint8 NvmZeroCalTest_FeeStatus = (uint8)MEMIF_UNINIT;
volatile uint8 NvmZeroCalTest_FeeJobResult = (uint8)MEMIF_JOB_FAILED;
volatile uint8 NvmZeroCalTest_FeeMainJob = 0U;
volatile uint8 NvmZeroCalTest_FeePendReqStatus = 0U;
volatile uint8 NvmZeroCalTest_FeeInitGCState = 0U;
volatile uint8 NvmZeroCalTest_FeeCacheState = 0U;
volatile uint8 NvmZeroCalTest_FeeIntrJob = 0U;
volatile uint8 NvmZeroCalTest_FeeIntrJobStatus = 0U;
volatile uint8 NvmZeroCalTest_FeeIntrJobResult = 0U;
volatile uint8 NvmZeroCalTest_FeeRecoverRequest = 0U;
volatile uint32 NvmZeroCalTest_PendingTicks = 0UL;
volatile uint8 NvmZeroCalTest_AppliedTo5012 = 0U;
volatile uint16 NvmZeroCalTest_AppliedAngBase = 0U;
volatile uint16 NvmZeroCalTest_StorageMagic = 0U;
volatile uint16 NvmZeroCalTest_StorageAngBase = 0U;

static void NvmZeroCalTest_SyncWatchMirrors(void)
{
  NvmZeroCalTest_StorageMagic = NvmZeroCalTest_Storage.magic;
  NvmZeroCalTest_StorageAngBase = NvmZeroCalTest_Storage.angBase;
}

static void NvmZeroCalTest_SampleFee(void)
{
  NvmZeroCalTest_FeeStatus = (uint8)Fee_GetStatus();
  NvmZeroCalTest_FeeJobResult = (uint8)Fee_GetJobResult();
  NvmZeroCalTest_FeeMainJob = Fee_StateVar.FeeMainJob;
  NvmZeroCalTest_FeePendReqStatus = Fee_StateVar.FeePendReqStatus;
  NvmZeroCalTest_FeeInitGCState = Fee_StateVar.FeeInitGCState;
  NvmZeroCalTest_FeeCacheState = Fee_StateVar.FeeCacheState;
  NvmZeroCalTest_FeeIntrJob = Fee_StateVar.FeeIntrJob;
  NvmZeroCalTest_FeeIntrJobStatus = Fee_StateVar.FeeIntrJobStatus;
  NvmZeroCalTest_FeeIntrJobResult = Fee_StateVar.FeeIntrJobResult;
}

static void NvmZeroCalTest_ApplyAngBaseTo5012(uint16 angBase)
{
  NvmZeroCalTest_Stage = NVMZEROCALTEST_STAGE_BEFORE_APPLY_5012;
  Tle5012bd_Sensor.ANG_BASE = angBase;
  tle5012b_write_fast(MOD_3, angBase);
  NvmZeroCalTest_AppliedAngBase = angBase;
  NvmZeroCalTest_AppliedTo5012 = 1U;
}

static void NvmZeroCalTest_ArmWrite(void)
{
  uint16 angBase = NvmZeroCalTest_AngBaseToWrite & 0x0FFFU;

  NvmZeroCalTest_Storage.magic = NVMZEROCALTEST_STORAGE_MAGIC;
  NvmZeroCalTest_Storage.angBase = angBase;
  NvmZeroCalTest_SyncWatchMirrors();

  NvmZeroCalTest_AppliedTo5012 = 0U;
  NvmZeroCalTest_AppliedAngBase = 0U;
  NvmZeroCalTest_PendingTicks = 0UL;
  NvmZeroCalTest_WritePending = 0U;
  NvmZeroCalTest_State = NVMZEROCALTEST_STATE_WRITING;
  NvmZeroCalTest_Stage = NVMZEROCALTEST_STAGE_REQUEST_SEEN;
  NvmZeroCalTest_IssueWrite = 1U;
}

static void NvmZeroCalTest_PollWrite(void)
{
  Std_ReturnType apiRet;
  NvM_RequestResultType requestResult = NVM_REQ_PENDING;

  if (NvmZeroCalTest_WritePending == 0U)
  {
    return;
  }

  NvmZeroCalTest_Stage = NVMZEROCALTEST_STAGE_POLLING;
  NvmZeroCalTest_SampleFee();

  apiRet = NvM_GetErrorStatus(NvMConf_NvMBlockDescriptor_NvMBlock_MotorZeroCal,
                              &requestResult);
  NvmZeroCalTest_NvLastApiRet = (uint8)apiRet;

  if (apiRet != E_OK)
  {
    return;
  }

  if (requestResult == NVM_REQ_PENDING)
  {
    NvmZeroCalTest_NvLastResult = (uint8)NVM_REQ_PENDING;
    NvmZeroCalTest_PendingTicks++;
    if (NvmZeroCalTest_PendingTicks > NVMZEROCALTEST_TIMEOUT_MS)
    {
      (void)NvM_CancelJobs(NvMConf_NvMBlockDescriptor_NvMBlock_MotorZeroCal);
      NvmZeroCalTest_WritePending = 0U;
      NvmZeroCalTest_NvLastResult = (uint8)NVM_REQ_NOT_OK;
      NvmZeroCalTest_State = NVMZEROCALTEST_STATE_FAULT;
      NvmZeroCalTest_Stage = NVMZEROCALTEST_STAGE_FAULT;
    }
    return;
  }

  NvmZeroCalTest_WritePending = 0U;
  NvmZeroCalTest_NvLastResult = (uint8)requestResult;
  NvmZeroCalTest_PendingTicks = 0UL;

  if (requestResult == NVM_REQ_OK)
  {
    NvmZeroCalTest_ApplyAngBaseTo5012(NvmZeroCalTest_Storage.angBase);
    NvmZeroCalTest_State = NVMZEROCALTEST_STATE_DONE;
    NvmZeroCalTest_Stage = NVMZEROCALTEST_STAGE_DONE;
  }
  else
  {
    NvmZeroCalTest_State = NVMZEROCALTEST_STATE_FAULT;
    NvmZeroCalTest_Stage = NVMZEROCALTEST_STAGE_FAULT;
  }
}

void NvmZeroCalTest_Init(void)
{
  NvmZeroCalTest_Request = 0U;
  NvmZeroCalTest_AngBaseToWrite = 0U;
  NvmZeroCalTest_State = NVMZEROCALTEST_STATE_IDLE;
  NvmZeroCalTest_Stage = NVMZEROCALTEST_STAGE_IDLE;
  NvmZeroCalTest_NvLastApiRet = (uint8)E_NOT_OK;
  NvmZeroCalTest_NvLastResult = (uint8)NVM_REQ_NOT_OK;
  NvmZeroCalTest_BlockStatusBeforeWrite = (uint8)NVM_REQ_NOT_OK;
  NvmZeroCalTest_FeeStatus = (uint8)MEMIF_UNINIT;
  NvmZeroCalTest_FeeJobResult = (uint8)MEMIF_JOB_FAILED;
  NvmZeroCalTest_FeeMainJob = 0U;
  NvmZeroCalTest_FeePendReqStatus = 0U;
  NvmZeroCalTest_FeeInitGCState = 0U;
  NvmZeroCalTest_FeeCacheState = 0U;
  NvmZeroCalTest_FeeIntrJob = 0U;
  NvmZeroCalTest_FeeIntrJobStatus = 0U;
  NvmZeroCalTest_FeeIntrJobResult = 0U;
  NvmZeroCalTest_FeeRecoverRequest = 0U;
  NvmZeroCalTest_PendingTicks = 0UL;
  NvmZeroCalTest_AppliedTo5012 = 0U;
  NvmZeroCalTest_AppliedAngBase = 0U;
  NvmZeroCalTest_WritePending = 0U;
  NvmZeroCalTest_IssueWrite = 0U;
  NvmZeroCalTest_Storage.magic = 0U;
  NvmZeroCalTest_Storage.angBase = 0U;
  NvmZeroCalTest_SyncWatchMirrors();
}

void NvmZeroCalTest_MainFunction(void)
{
  NvmZeroCalTest_SampleFee();

  if (NvmZeroCalTest_FeeRecoverRequest != 0U)
  {
    NvmZeroCalTest_FeeRecoverRequest = 0U;
    /* Fee_Cancel cannot abort InitGC erase; only clears queued non-erase jobs. */
    Fee_Cancel();
    (void)NvM_CancelJobs(NvMConf_NvMBlockDescriptor_NvMBlock_MotorZeroCal);
  }

  if ((NvmZeroCalTest_Request != 0U) &&
      (NvmZeroCalTest_WritePending == 0U) &&
      (NvmZeroCalTest_IssueWrite == 0U) &&
      (NvmZeroCalTest_State != NVMZEROCALTEST_STATE_WRITING))
  {
    NvmZeroCalTest_Request = 0U;
    NvmZeroCalTest_ArmWrite();
  }

  NvmZeroCalTest_PollWrite();
}

void NvmZeroCalTest_MainFunction10ms(void)
{
  Std_ReturnType apiRet;
  NvM_RequestResultType blockStatus = NVM_REQ_NOT_OK;

  if (NvmZeroCalTest_IssueWrite == 0U)
  {
    return;
  }

  NvmZeroCalTest_SampleFee();

  /* InitGC FAIL still reports FeeStatus=IDLE — must not WriteBlock. */
  if (NvmZeroCalTest_FeeInitGCState == NVMZEROCALTEST_FEE_INITGC_FAIL)
  {
    NvmZeroCalTest_IssueWrite = 0U;
    NvmZeroCalTest_WritePending = 0U;
    NvmZeroCalTest_State = NVMZEROCALTEST_STATE_FAULT;
    NvmZeroCalTest_Stage = NVMZEROCALTEST_STAGE_FEE_INITGC_FAIL;
    NvmZeroCalTest_NvLastResult = (uint8)NVM_REQ_NOT_OK;
    return;
  }

  /* Gate: Fee IDLE AND InitGC COMPLETE (5). */
  if ((NvmZeroCalTest_FeeStatus != (uint8)MEMIF_IDLE) ||
      (NvmZeroCalTest_FeeInitGCState != NVMZEROCALTEST_FEE_INITGC_COMPLETE))
  {
    NvmZeroCalTest_Stage = NVMZEROCALTEST_STAGE_WAIT_FEE_IDLE;
    return;
  }

  apiRet = NvM_GetErrorStatus(NvMConf_NvMBlockDescriptor_NvMBlock_MotorZeroCal,
                              &blockStatus);
  NvmZeroCalTest_BlockStatusBeforeWrite = (uint8)blockStatus;

  if ((apiRet == E_OK) && (blockStatus == NVM_REQ_PENDING))
  {
    NvmZeroCalTest_Stage = NVMZEROCALTEST_STAGE_WAIT_NOT_PENDING;
    /* Do not CancelJobs during Fee InitGC/erase — wait for BSW Main to finish. */
    return;
  }

  NvmZeroCalTest_IssueWrite = 0U;
  NvmZeroCalTest_Stage = NVMZEROCALTEST_STAGE_BEFORE_WRITEBLOCK;

  apiRet = NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvMBlock_MotorZeroCal,
                          &NvmZeroCalTest_Storage);
  NvmZeroCalTest_NvLastApiRet = (uint8)apiRet;

  if (apiRet == E_OK)
  {
    NvmZeroCalTest_WritePending = 1U;
    NvmZeroCalTest_NvLastResult = (uint8)NVM_REQ_PENDING;
    NvmZeroCalTest_Stage = NVMZEROCALTEST_STAGE_AFTER_WRITE_OK;
  }
  else
  {
    NvmZeroCalTest_WritePending = 0U;
    NvmZeroCalTest_NvLastResult = (uint8)NVM_REQ_NOT_OK;
    NvmZeroCalTest_State = NVMZEROCALTEST_STATE_FAULT;
    NvmZeroCalTest_Stage = NVMZEROCALTEST_STAGE_AFTER_WRITE_NOK;
  }
}
