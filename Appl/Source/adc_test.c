#include "adc_test.h"

#include "Adc_Cfg.h"
#include "IfxEvadc_bf.h"
#include "IfxEvadc_reg.h"
#include <string.h>

#define ADC_TEST_GROUP0_CHANNEL_COUNT   (2U)
#define ADC_TEST_GROUP2_CHANNEL_COUNT   (1U)
#define ADC_TEST_GROUP3_CHANNEL_COUNT   (1U)
#define ADC_TEST_RES_VALUE_MASK         (0x00000FFFU)
#define ADC_TEST_GROUP0_VO1_BUF_IDX     (0U)
#define ADC_TEST_GROUP0_VRO_BUF_IDX     (1U)
#define ADC_TEST_PENDING_MAX_CYCLES     (4U)

Std_ReturnType AdcTest_InitResult = E_NOT_OK;
Std_ReturnType AdcTest_LastSampleResult = E_NOT_OK;
uint32 AdcTest_SampleCounter = 0U;
uint32 AdcTest_SampleOkCounter = 0U;
uint32 AdcTest_SampleFailCounter = 0U;
uint32 AdcTest_BusySkipCounter = 0U;
uint32 AdcTest_TimeoutCounter = 0U;
uint32 AdcTest_HandlerPollCounter = 0U;
uint8 AdcTest_SevFlagG0 = 0U;
uint8 AdcTest_SevFlagG2 = 0U;
uint8 AdcTest_SevFlagG3 = 0U;

Adc_StatusType AdcTest_Group9183SenseStatus = ADC_IDLE;
Adc_StatusType AdcTest_Group9183Vo2Status = ADC_IDLE;
Adc_StatusType AdcTest_Group9183Vo3Status = ADC_IDLE;

Adc_ValueGroupType AdcTest_Group9183SenseRaw[ADC_TEST_GROUP0_CHANNEL_COUNT];
Adc_ValueGroupType AdcTest_Group9183Vo2Raw[ADC_TEST_GROUP2_CHANNEL_COUNT];
Adc_ValueGroupType AdcTest_Group9183Vo3Raw[ADC_TEST_GROUP3_CHANNEL_COUNT];

Adc_ValueGroupType AdcTest_VroRaw = 0U;
Adc_ValueGroupType AdcTest_Vo1Raw = 0U;
Adc_ValueGroupType AdcTest_Vo2Raw = 0U;
Adc_ValueGroupType AdcTest_Vo3Raw = 0U;

uint32 AdcTest_EvadcClc = 0U;
uint32 AdcTest_EvadcG0Arbcfg = 0U;
uint32 AdcTest_EvadcG2Arbcfg = 0U;
uint32 AdcTest_EvadcG3Arbcfg = 0U;
uint32 AdcTest_EvadcG0Q0Qsr = 0U;
uint32 AdcTest_EvadcG2Q0Qsr = 0U;
uint32 AdcTest_EvadcG3Q0Qsr = 0U;
uint32 AdcTest_EvadcG0Res0 = 0U;
uint32 AdcTest_EvadcG0Res1 = 0U;
uint32 AdcTest_EvadcG2Res0 = 0U;
uint32 AdcTest_EvadcG3Res0 = 0U;
Adc_ValueGroupType AdcTest_VroResDirect = 0U;
Adc_ValueGroupType AdcTest_Vo1ResDirect = 0U;
Adc_ValueGroupType AdcTest_Vo2ResDirect = 0U;
Adc_ValueGroupType AdcTest_Vo3ResDirect = 0U;
uint8 AdcTest_VroResValid = 0U;
uint8 AdcTest_Vo1ResValid = 0U;
uint8 AdcTest_Vo2ResValid = 0U;
uint8 AdcTest_Vo3ResValid = 0U;

static boolean AdcTest_Group9183SensePending = FALSE;
static boolean AdcTest_Group9183Vo2Pending = FALSE;
static boolean AdcTest_Group9183Vo3Pending = FALSE;
static uint8 AdcTest_Group9183SensePendingCycles = 0U;
static uint8 AdcTest_Group9183Vo2PendingCycles = 0U;
static uint8 AdcTest_Group9183Vo3PendingCycles = 0U;

static Std_ReturnType AdcTest_StartGroup(Adc_GroupType group,
    Adc_StatusType *lastStatus, boolean *pendingFlag);
static Std_ReturnType AdcTest_ReadPendingGroup(Adc_GroupType group,
    Adc_ValueGroupType *buffer, uint8 channelCount, Adc_StatusType *lastStatus,
    boolean *pendingFlag);
static void AdcTest_UpdateNamedValues(void);
static void AdcTest_SampleHwRegs(void);
static void AdcTest_PollResultHandlers(void);
static void AdcTest_ManageStalePending(boolean *pendingFlag, uint8 *pendingCycles,
    Adc_StatusType groupStatus);

void AdcTest_Init(void)
{
  Std_ReturnType result0;
  Std_ReturnType result2;
  Std_ReturnType result3;

  Adc_SrcEnableInit();

  (void)memset(AdcTest_Group9183SenseRaw, 0, sizeof(AdcTest_Group9183SenseRaw));
  (void)memset(AdcTest_Group9183Vo2Raw, 0, sizeof(AdcTest_Group9183Vo2Raw));
  (void)memset(AdcTest_Group9183Vo3Raw, 0, sizeof(AdcTest_Group9183Vo3Raw));

  result0 = Adc_SetupResultBuffer(
      AdcConf_AdcGroup_AdcGroup_9183Sense,
      AdcTest_Group9183SenseRaw);
  result2 = Adc_SetupResultBuffer(
      AdcConf_AdcGroup_AdcGroup,
      AdcTest_Group9183Vo2Raw);
  result3 = Adc_SetupResultBuffer(
      AdcConf_AdcGroup_AdcGroup_1,
      AdcTest_Group9183Vo3Raw);

  if ((result0 == E_OK) && (result2 == E_OK) && (result3 == E_OK))
  {
    AdcTest_InitResult = E_OK;
  }
  else
  {
    AdcTest_InitResult = E_NOT_OK;
  }

  AdcTest_SampleHwRegs();
  AdcTest_UpdateNamedValues();
}

void AdcTest_RunOnce(void)
{
  Std_ReturnType result0;
  Std_ReturnType result2;
  Std_ReturnType result3;
  Std_ReturnType start0;
  Std_ReturnType start2;
  Std_ReturnType start3;

  AdcTest_SampleCounter++;

  if (AdcTest_InitResult != E_OK)
  {
    AdcTest_SampleHwRegs();
    AdcTest_LastSampleResult = E_NOT_OK;
    AdcTest_SampleFailCounter++;
    return;
  }

  AdcTest_PollResultHandlers();

  result0 = AdcTest_ReadPendingGroup(
      AdcConf_AdcGroup_AdcGroup_9183Sense,
      AdcTest_Group9183SenseRaw,
      ADC_TEST_GROUP0_CHANNEL_COUNT,
      &AdcTest_Group9183SenseStatus,
      &AdcTest_Group9183SensePending);
  result2 = AdcTest_ReadPendingGroup(
      AdcConf_AdcGroup_AdcGroup,
      AdcTest_Group9183Vo2Raw,
      ADC_TEST_GROUP2_CHANNEL_COUNT,
      &AdcTest_Group9183Vo2Status,
      &AdcTest_Group9183Vo2Pending);
  result3 = AdcTest_ReadPendingGroup(
      AdcConf_AdcGroup_AdcGroup_1,
      AdcTest_Group9183Vo3Raw,
      ADC_TEST_GROUP3_CHANNEL_COUNT,
      &AdcTest_Group9183Vo3Status,
      &AdcTest_Group9183Vo3Pending);

  AdcTest_ManageStalePending(
      &AdcTest_Group9183SensePending,
      &AdcTest_Group9183SensePendingCycles,
      AdcTest_Group9183SenseStatus);
  AdcTest_ManageStalePending(
      &AdcTest_Group9183Vo2Pending,
      &AdcTest_Group9183Vo2PendingCycles,
      AdcTest_Group9183Vo2Status);
  AdcTest_ManageStalePending(
      &AdcTest_Group9183Vo3Pending,
      &AdcTest_Group9183Vo3PendingCycles,
      AdcTest_Group9183Vo3Status);

  start0 = AdcTest_StartGroup(
      AdcConf_AdcGroup_AdcGroup_9183Sense,
      &AdcTest_Group9183SenseStatus,
      &AdcTest_Group9183SensePending);
  start2 = AdcTest_StartGroup(
      AdcConf_AdcGroup_AdcGroup,
      &AdcTest_Group9183Vo2Status,
      &AdcTest_Group9183Vo2Pending);
  start3 = AdcTest_StartGroup(
      AdcConf_AdcGroup_AdcGroup_1,
      &AdcTest_Group9183Vo3Status,
      &AdcTest_Group9183Vo3Pending);

  if (start0 == E_OK)
  {
    AdcTest_Group9183SensePendingCycles = 0U;
  }
  if (start2 == E_OK)
  {
    AdcTest_Group9183Vo2PendingCycles = 0U;
  }
  if (start3 == E_OK)
  {
    AdcTest_Group9183Vo3PendingCycles = 0U;
  }

  AdcTest_SampleHwRegs();
  AdcTest_UpdateNamedValues();

  if ((result0 == E_OK) && (result2 == E_OK) && (result3 == E_OK))
  {
    AdcTest_LastSampleResult = E_OK;
    AdcTest_SampleOkCounter++;
  }
  else if ((start0 == E_OK) && (start2 == E_OK) && (start3 == E_OK))
  {
    AdcTest_LastSampleResult = E_OK;
  }
  else
  {
    AdcTest_LastSampleResult = E_NOT_OK;
    AdcTest_SampleFailCounter++;
  }
}

static void AdcTest_PollResultHandlers(void)
{
  AdcTest_HandlerPollCounter++;
  AdcTest_SevFlagG0 = (uint8)MODULE_EVADC.G[0].SEFLAG.B.SEV0;
  AdcTest_SevFlagG2 = (uint8)MODULE_EVADC.G[2].SEFLAG.B.SEV0;
  AdcTest_SevFlagG3 = (uint8)MODULE_EVADC.G[3].SEFLAG.B.SEV0;

  Adc_RS0EventInterruptHandler(0U);
  Adc_RS0EventInterruptHandler(2U);
  Adc_RS0EventInterruptHandler(3U);
}

static void AdcTest_ManageStalePending(boolean *pendingFlag, uint8 *pendingCycles,
    Adc_StatusType groupStatus)
{
  if ((pendingFlag == NULL_PTR) || (*pendingFlag == FALSE))
  {
    if (pendingCycles != NULL_PTR)
    {
      *pendingCycles = 0U;
    }
    return;
  }

  if ((groupStatus == ADC_COMPLETED) || (groupStatus == ADC_STREAM_COMPLETED))
  {
    return;
  }

  if (groupStatus == ADC_IDLE)
  {
    *pendingFlag = FALSE;
    if (pendingCycles != NULL_PTR)
    {
      *pendingCycles = 0U;
    }
    AdcTest_TimeoutCounter++;
    return;
  }

  if (pendingCycles != NULL_PTR)
  {
    (*pendingCycles)++;
    if (*pendingCycles >= ADC_TEST_PENDING_MAX_CYCLES)
    {
      *pendingFlag = FALSE;
      *pendingCycles = 0U;
      AdcTest_TimeoutCounter++;
    }
  }
}

static Std_ReturnType AdcTest_StartGroup(Adc_GroupType group,
    Adc_StatusType *lastStatus, boolean *pendingFlag)
{
  Adc_StatusType groupStatus;

  groupStatus = Adc_GetGroupStatus(group);
  if (lastStatus != NULL_PTR)
  {
    *lastStatus = groupStatus;
  }

  if (groupStatus == ADC_BUSY)
  {
    AdcTest_BusySkipCounter++;
    return E_NOT_OK;
  }

  if ((pendingFlag != NULL_PTR) && (*pendingFlag == TRUE))
  {
    return E_NOT_OK;
  }

  Adc_StartGroupConversion(group);
  if (pendingFlag != NULL_PTR)
  {
    *pendingFlag = TRUE;
  }
  return E_OK;
}

static Std_ReturnType AdcTest_ReadPendingGroup(Adc_GroupType group,
    Adc_ValueGroupType *buffer, uint8 channelCount, Adc_StatusType *lastStatus,
    boolean *pendingFlag)
{
  Adc_StatusType groupStatus;

  if ((pendingFlag == NULL_PTR) || (*pendingFlag == FALSE))
  {
    return E_NOT_OK;
  }

  groupStatus = Adc_GetGroupStatus(group);

  if (lastStatus != NULL_PTR)
  {
    *lastStatus = groupStatus;
  }

  if (groupStatus == ADC_BUSY)
  {
    return E_NOT_OK;
  }

  if ((groupStatus != ADC_COMPLETED) && (groupStatus != ADC_STREAM_COMPLETED))
  {
    return E_NOT_OK;
  }

  if (Adc_ReadGroup(group, buffer) != E_OK)
  {
    *pendingFlag = FALSE;
    return E_NOT_OK;
  }

  if (channelCount == 0U)
  {
    *pendingFlag = FALSE;
    return E_NOT_OK;
  }

  *pendingFlag = FALSE;
  return E_OK;
}

static void AdcTest_UpdateNamedValues(void)
{
  AdcTest_Vo1Raw = AdcTest_Group9183SenseRaw[ADC_TEST_GROUP0_VO1_BUF_IDX];
  AdcTest_VroRaw = AdcTest_Group9183SenseRaw[ADC_TEST_GROUP0_VRO_BUF_IDX];
  AdcTest_Vo2Raw = AdcTest_Group9183Vo2Raw[0];
  AdcTest_Vo3Raw = AdcTest_Group9183Vo3Raw[0];
}

static void AdcTest_SampleHwRegs(void)
{
  AdcTest_EvadcClc = MODULE_EVADC.CLC.U;
  AdcTest_EvadcG0Arbcfg = MODULE_EVADC.G[0].ARBCFG.U;
  AdcTest_EvadcG2Arbcfg = MODULE_EVADC.G[2].ARBCFG.U;
  AdcTest_EvadcG3Arbcfg = MODULE_EVADC.G[3].ARBCFG.U;
  AdcTest_EvadcG0Q0Qsr = MODULE_EVADC.G[0].Q[0].QSR.U;
  AdcTest_EvadcG2Q0Qsr = MODULE_EVADC.G[2].Q[0].QSR.U;
  AdcTest_EvadcG3Q0Qsr = MODULE_EVADC.G[3].Q[0].QSR.U;
  AdcTest_EvadcG0Res0 = MODULE_EVADC.G[0].RES[0].U;
  AdcTest_EvadcG0Res1 = MODULE_EVADC.G[0].RES[1].U;
  AdcTest_EvadcG2Res0 = MODULE_EVADC.G[2].RES[0].U;
  AdcTest_EvadcG3Res0 = MODULE_EVADC.G[3].RES[0].U;

  AdcTest_Vo1ResDirect =
      (Adc_ValueGroupType)(AdcTest_EvadcG0Res0 & ADC_TEST_RES_VALUE_MASK);
  AdcTest_VroResDirect =
      (Adc_ValueGroupType)(AdcTest_EvadcG0Res1 & ADC_TEST_RES_VALUE_MASK);
  AdcTest_Vo2ResDirect =
      (Adc_ValueGroupType)(AdcTest_EvadcG2Res0 & ADC_TEST_RES_VALUE_MASK);
  AdcTest_Vo3ResDirect =
      (Adc_ValueGroupType)(AdcTest_EvadcG3Res0 & ADC_TEST_RES_VALUE_MASK);

  AdcTest_Vo1ResValid =
      (uint8)((AdcTest_EvadcG0Res0 >> IFX_EVADC_G_RES_VF_OFF) &
              IFX_EVADC_G_RES_VF_MSK);
  AdcTest_VroResValid =
      (uint8)((AdcTest_EvadcG0Res1 >> IFX_EVADC_G_RES_VF_OFF) &
              IFX_EVADC_G_RES_VF_MSK);
  AdcTest_Vo2ResValid =
      (uint8)((AdcTest_EvadcG2Res0 >> IFX_EVADC_G_RES_VF_OFF) &
              IFX_EVADC_G_RES_VF_MSK);
  AdcTest_Vo3ResValid =
      (uint8)((AdcTest_EvadcG3Res0 >> IFX_EVADC_G_RES_VF_OFF) &
              IFX_EVADC_G_RES_VF_MSK);
}
