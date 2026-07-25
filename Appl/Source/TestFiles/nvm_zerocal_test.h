/**********************************************************************************************************************
 * nvm_zerocal_test.h - Isolated NvM write test for MotorZeroCal block
 *
 * UDE sequence:
 *   1) Wait NvmZeroCalTest_FeeStatus == 1 (MEMIF_IDLE)
 *   2) NvmZeroCalTest_AngBaseToWrite = value
 *   3) NvmZeroCalTest_Request = 1
 *   4) Expect NvmZeroCalTest_Stage → 3 → 5 → 6
 *
 * If stuck at Stage 10 (FeeStatus=2) for a long time:
 *   Watch: NvmZeroCalTest_FeeMainJob, NvmZeroCalTest_FeePendReqStatus,
 *          NvmZeroCalTest_FeeInitGCState, NvmZeroCalTest_FeeIntrJobStatus
 *   Then erase DFlash sectors in UDE (see below) and power-cycle.
 *
 * Power-on OK: NvmZeroCalTest_FeeStatus==1 AND NvmZeroCalTest_FeeInitGCState==5
 * If FeeInitGCState==6 (FAIL): DFlash corrupt — erase both sectors then reset:
 *   Erase 0xAF000000 len 0x10000
 *   Erase 0xAF010000 len 0x10000
 *
 * FeeStatus: 0=UNINIT 1=IDLE 2=BUSY 3=BUSY_INTERNAL
 * FeeMainJob: 0=UNINIT 1=INITGC 2=CACHEUPDATE 3=READ 4=WRITE 5=GC ...
 * FeePendReqStatus: 1=NO_REQ 2=PEND_WRITE 3=PEND_READ 6=REQ_READ 8=NORM_WRITE ...
 **********************************************************************************************************************/
#ifndef NVM_ZEROCAL_TEST_H
#define NVM_ZEROCAL_TEST_H

#include "Std_Types.h"

#define NVMZEROCALTEST_STORAGE_MAGIC   (0xA5A4U)
#define NVMZEROCALTEST_TIMEOUT_MS      (10000U)

#define NVMZEROCALTEST_STATE_IDLE      (0U)
#define NVMZEROCALTEST_STATE_WRITING   (1U)
#define NVMZEROCALTEST_STATE_DONE      (2U)
#define NVMZEROCALTEST_STATE_FAULT     (3U)

#define NVMZEROCALTEST_STAGE_IDLE                 (0U)
#define NVMZEROCALTEST_STAGE_REQUEST_SEEN         (1U)
#define NVMZEROCALTEST_STAGE_BEFORE_WRITEBLOCK    (2U)
#define NVMZEROCALTEST_STAGE_AFTER_WRITE_OK       (3U)
#define NVMZEROCALTEST_STAGE_AFTER_WRITE_NOK      (4U)
#define NVMZEROCALTEST_STAGE_POLLING              (5U)
#define NVMZEROCALTEST_STAGE_DONE                 (6U)
#define NVMZEROCALTEST_STAGE_FAULT                (7U)
#define NVMZEROCALTEST_STAGE_BEFORE_APPLY_5012    (8U)
#define NVMZEROCALTEST_STAGE_WAIT_NOT_PENDING     (9U)
#define NVMZEROCALTEST_STAGE_WAIT_FEE_IDLE        (10U)
#define NVMZEROCALTEST_STAGE_FEE_INITGC_FAIL      (11U)

/* FeeInitGCState: 5=COMPLETE 6=FAIL — IDLE alone is NOT enough (FAIL also reports IDLE). */
#define NVMZEROCALTEST_FEE_INITGC_COMPLETE        (5U)
#define NVMZEROCALTEST_FEE_INITGC_FAIL            (6U)

typedef struct
{
  uint16 magic;
  uint16 angBase;
} NvmZeroCalTest_StorageType;

extern volatile uint8 NvmZeroCalTest_Request;
extern volatile uint16 NvmZeroCalTest_AngBaseToWrite;
extern volatile uint8 NvmZeroCalTest_State;
extern volatile uint8 NvmZeroCalTest_Stage;
extern volatile uint8 NvmZeroCalTest_NvLastApiRet;
extern volatile uint8 NvmZeroCalTest_NvLastResult;
extern volatile uint8 NvmZeroCalTest_BlockStatusBeforeWrite;
extern volatile uint8 NvmZeroCalTest_FeeStatus;
extern volatile uint8 NvmZeroCalTest_FeeJobResult;
/* Mirrors of Fee_StateVar (stuck-Fee diagnosis). */
extern volatile uint8 NvmZeroCalTest_FeeMainJob;
extern volatile uint8 NvmZeroCalTest_FeePendReqStatus;
extern volatile uint8 NvmZeroCalTest_FeeInitGCState;
extern volatile uint8 NvmZeroCalTest_FeeCacheState;
extern volatile uint8 NvmZeroCalTest_FeeIntrJob;
extern volatile uint8 NvmZeroCalTest_FeeIntrJobStatus;
extern volatile uint8 NvmZeroCalTest_FeeIntrJobResult;
/* UDE: set 1 once to call Fee_Cancel while stuck at Stage 10. */
extern volatile uint8 NvmZeroCalTest_FeeRecoverRequest;
extern volatile uint32 NvmZeroCalTest_PendingTicks;
extern volatile uint8 NvmZeroCalTest_AppliedTo5012;
extern volatile uint16 NvmZeroCalTest_AppliedAngBase;
extern volatile uint16 NvmZeroCalTest_StorageMagic;
extern volatile uint16 NvmZeroCalTest_StorageAngBase;

void NvmZeroCalTest_Init(void);
void NvmZeroCalTest_MainFunction(void);
void NvmZeroCalTest_MainFunction10ms(void);

#endif /* NVM_ZEROCAL_TEST_H */
