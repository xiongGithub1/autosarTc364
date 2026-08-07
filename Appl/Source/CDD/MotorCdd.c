/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  MotorCdd.c
 *           Config:  last364.dpa
 *        SW-C Type:  MotorCdd
 *
 *        Generator:  MICROSAR RTE Generator Version 4.29.0
 *                    RTE Core Version 1.29.0
 *          License:  CBD2200508
 *
 *      Description:  C-Code implementation template for SW-C <MotorCdd>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */
/* PRQA S 0857 EOF */ /* MD_MSR_Dir1.1 */
/* PRQA S 0614 EOF */ /* MD_Rte_TestCode */

/* PRQA S 3109 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3112 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2982 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2983 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2880 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3203 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3205 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3206 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3218 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3229 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2002 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3334 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3417 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3426 EOF */ /* MD_Rte_TestCode */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_MotorCdd.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Tle9180_Driver.h"
#include "MotorCdd_Adc.h"
#include "Tle5012bd_Driver.h"
#include "MotorCdd_Foc.h"
#include "IfxGtm_reg.h"
#include "MotorZeroCal.h"

#define MOTORCDD_DTM_CDTM_INDEX             (0U)
#define MOTORCDD_DTM_INDEX                  (4U)
#define MOTORCDD_DTM_CH_U                   (1U)
#define MOTORCDD_DTM_CH_V                   (2U)
#define MOTORCDD_DTM_CH_W                   (3U)
#define MOTORCDD_DTM_CLK_SEL_CMU_CLK1       (1U)
#define MOTORCDD_DTM_PATH_ENABLE            (1U)
#define MOTORCDD_DTM_DEADTIME_TICKS         (200U)
#define MOTORCDD_DTM_TOUTSEL0_VALUE         (0x28882222UL)

volatile uint8 MotorCdd_PwmComplementaryInitDone = 0U;
uint32 MotorCdd_Os1msCounter = 0U;
static volatile uint8 MotorCdd_InitComplete = 0U;

static void MotorCdd_PwmComplementaryInit(void);
static void MotorCdd_PublishFeedback(void);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 *********************************************************************************************************************/


#define MotorCdd_START_SEC_CODE
#include "MotorCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MotorCdd_CODE) AdcSampleReady(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: AdcSampleReady
 *********************************************************************************************************************/

	/* 10 kHz: sample and FOC run in the same Cat2 ISR. */
//	MotorCdd_AdcRunFastLoop();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotorCDDMainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 1ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotorCDDMainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MotorCdd_CODE) MotorCdd_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotorCDDMainFunction
 *********************************************************************************************************************/
  MotorCdd_Os1msCounter++;
  if (MotorCdd_InitComplete == 0U)
  {
    return;
  }

  Tle9180_Driver_MainFunction();
  MotorZeroCal_MainFunction();
  MotorCdd_PublishFeedback();
  MotorCdd_FocUpdateCmdMirror();
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Pp_MotorCdd_EnableInverter_EnableInverter
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <EnableInverter> of PortPrototype <Pp_MotorCdd_EnableInverter>
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Pp_MotorCdd_EnableInverter_EnableInverter_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MotorCdd_CODE) Pp_MotorCdd_EnableInverter_EnableInverter(boolean arg) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Pp_MotorCdd_EnableInverter_EnableInverter
 *********************************************************************************************************************/
  if (arg != FALSE)
  {
    if (MotorCdd_AdcIsCurrentOffsetReady() != 0U)
    {
      MotorCdd_FocPrepareOutputEnable();
      Tle9180_Driver_EnableOutput(TRUE);
    }
  }
  else
  {
    MotorCdd_FocStopOutput();
    Tle9180_Driver_EnableOutput(FALSE);
  }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MotorCdd_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MotorCdd_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, MotorCdd_CODE) MotorCdd_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotorCdd_Init
 *********************************************************************************************************************/
  MotorCdd_AdcInit();
  /* 9180 first (QSPI3 Sync Init steps continue in MotorCDDMainFunction). */
  Tle9180_Driver_Init();
  Tle5012bd_Driver_Init();
  MotorCdd_PwmComplementaryInit();
  MotorCdd_AdcHwTriggerInit();
  MotorCdd_FocInit();
  MotorCdd_InitComplete = 1U;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define MotorCdd_STOP_SEC_CODE
#include "MotorCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#define MotorCdd_START_SEC_CODE
#include "MotorCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

static void MotorCdd_PublishFeedback(void)
{
  const MotorCdd_AdcPhysicalType* adcPhysical;
  float32 angleRad;

  adcPhysical = MotorCdd_GetAdcPhysical();
  if (adcPhysical != NULL_PTR)
  {
    (void)Rte_Write_Pp_MotorDcBusVoltage_Vbus(adcPhysical->vinv_V);
  }

  angleRad = Tle5012bd_Driver_GetElectricalAngleRad();
  (void)Rte_Write_Pp_MotorElectricalAngle_ElectricAngle(angleRad);

  /* OV latch from 9180 status can be wired here when register read is available. */
  (void)Rte_Write_Pp_MotorFaultStatus_tle9180_Ov_Fault(FALSE);
}

/* ===========================================================================
 * 互补 PWM 死区初始化（GTM CDTM[0].DTM[4]，位定义见 IfxGtm_regdef.h）
 * 输入：ATOM0 CH1/2/3 的 6 路 PWM（高/低边各 3 路），经 DTM 插入死区后输出。
 * ---------------------------------------------------------------------------
 * DTM_CTRL：
 *   CLK_SEL [1:0] = 1 ：选择 CMU_CLK1 作为死区计数时钟
 *   DTM_SEL [3:2] / UPD_MODE [6:4] / SR_UPD_EN [8] / SHUT_OFF_RST [16]
 *                      保持复位默认（本工程由 PWM MCAL 初始化）。
 * CH_CTRL2（每通道 8 位，共 4 通道 × 输出0/1；这里只用通道1/2/3 即 U/V/W）：
 *   POLx_y [0/4/8/...] ：输出 y 极性（1=反相）
 *   OCx_y  [1/5/...]   ：输出 y 控制方式（0=受死区模块控制）
 *   SLx_y  [2/6/...]   ：输出 y 强制电平（0=跟随输入）
 *   DTx_y  [3/7/...]   ：输出 y 死区路径使能（1=开启，本函数置 1）
 *   即：DT0_1/DT1_1/DT0_2/DT1_2/DT0_3/DT1_3 = 1 → U/V/W 高、低边均插入死区。
 * CH_DTV（每通道 10 位）：
 *   RELRISE [9:0]  ：上升沿死区重载值（tick）
 *   RELFALL [25:16]：下降沿死区重载值（tick）
 *   本工程 = MOTORCDD_DTM_DEADTIME_TICKS(200) @ CMU_CLK1(100MHz) ≈ 2 µs
 * TOUTSEL[0]：选择 GTM 输出到芯片引脚（TOUT 映射），
 *   0x28882222 把 6 路互补 PWM 分配到 TLE9180 对应栅极输入引脚。
 * =========================================================================== */
static void MotorCdd_PwmComplementaryInit(void)
{
  /* DTM_CTRL.CLK_SEL = CMU_CLK1：死区计数器时钟源。 */
  MODULE_GTM.CDTM[MOTORCDD_DTM_CDTM_INDEX].DTM[MOTORCDD_DTM_INDEX].CTRL.B.CLK_SEL =
      MOTORCDD_DTM_CLK_SEL_CMU_CLK1;

  /* CH_CTRL2.DT0_x / DT1_x = 1：开启 U/V/W 高低边死区路径。 */
  MODULE_GTM.CDTM[MOTORCDD_DTM_CDTM_INDEX].DTM[MOTORCDD_DTM_INDEX].CH_CTRL2.B.DT0_1 =
      MOTORCDD_DTM_PATH_ENABLE;
  MODULE_GTM.CDTM[MOTORCDD_DTM_CDTM_INDEX].DTM[MOTORCDD_DTM_INDEX].CH_CTRL2.B.DT1_1 =
      MOTORCDD_DTM_PATH_ENABLE;
  MODULE_GTM.CDTM[MOTORCDD_DTM_CDTM_INDEX].DTM[MOTORCDD_DTM_INDEX].CH_CTRL2.B.DT0_2 =
      MOTORCDD_DTM_PATH_ENABLE;
  MODULE_GTM.CDTM[MOTORCDD_DTM_CDTM_INDEX].DTM[MOTORCDD_DTM_INDEX].CH_CTRL2.B.DT1_2 =
      MOTORCDD_DTM_PATH_ENABLE;
  MODULE_GTM.CDTM[MOTORCDD_DTM_CDTM_INDEX].DTM[MOTORCDD_DTM_INDEX].CH_CTRL2.B.DT0_3 =
      MOTORCDD_DTM_PATH_ENABLE;
  MODULE_GTM.CDTM[MOTORCDD_DTM_CDTM_INDEX].DTM[MOTORCDD_DTM_INDEX].CH_CTRL2.B.DT1_3 =
      MOTORCDD_DTM_PATH_ENABLE;

  /* CH_DTV.RELRISE / RELFALL = 200：U/V/W 三相上升/下降沿死区各 2 µs。 */
  MODULE_GTM.CDTM[MOTORCDD_DTM_CDTM_INDEX].DTM[MOTORCDD_DTM_INDEX].CH[MOTORCDD_DTM_CH_U].DTV.B.RELFALL =
      MOTORCDD_DTM_DEADTIME_TICKS;
  MODULE_GTM.CDTM[MOTORCDD_DTM_CDTM_INDEX].DTM[MOTORCDD_DTM_INDEX].CH[MOTORCDD_DTM_CH_U].DTV.B.RELRISE =
      MOTORCDD_DTM_DEADTIME_TICKS;
  MODULE_GTM.CDTM[MOTORCDD_DTM_CDTM_INDEX].DTM[MOTORCDD_DTM_INDEX].CH[MOTORCDD_DTM_CH_V].DTV.B.RELFALL =
      MOTORCDD_DTM_DEADTIME_TICKS;
  MODULE_GTM.CDTM[MOTORCDD_DTM_CDTM_INDEX].DTM[MOTORCDD_DTM_INDEX].CH[MOTORCDD_DTM_CH_V].DTV.B.RELRISE =
      MOTORCDD_DTM_DEADTIME_TICKS;
  MODULE_GTM.CDTM[MOTORCDD_DTM_CDTM_INDEX].DTM[MOTORCDD_DTM_INDEX].CH[MOTORCDD_DTM_CH_W].DTV.B.RELFALL =
      MOTORCDD_DTM_DEADTIME_TICKS;
  MODULE_GTM.CDTM[MOTORCDD_DTM_CDTM_INDEX].DTM[MOTORCDD_DTM_INDEX].CH[MOTORCDD_DTM_CH_W].DTV.B.RELRISE =
      MOTORCDD_DTM_DEADTIME_TICKS;

  /* CH_CTRL2.POL0_1/2/3 = 1：U/V/W 低边输出极性反相（与高边互补电平匹配）。 */
  MODULE_GTM.CDTM[MOTORCDD_DTM_CDTM_INDEX].DTM[MOTORCDD_DTM_INDEX].CH_CTRL2.B.POL0_1 = 1U;
  MODULE_GTM.CDTM[MOTORCDD_DTM_CDTM_INDEX].DTM[MOTORCDD_DTM_INDEX].CH_CTRL2.B.POL0_2 = 1U;
  MODULE_GTM.CDTM[MOTORCDD_DTM_CDTM_INDEX].DTM[MOTORCDD_DTM_INDEX].CH_CTRL2.B.POL0_3 = 1U;

  /* TOUTSEL[0]：把 6 路互补 PWM 映射到 TLE9180 栅极驱动输入引脚。 */
  MODULE_GTM.TOUTSEL[0].U = MOTORCDD_DTM_TOUTSEL0_VALUE;
  MotorCdd_PwmComplementaryInitDone = 1U;
}

#define MotorCdd_STOP_SEC_CODE
#include "MotorCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_TestCode:
     Reason:     This justification is used as summary justification for all deviations caused by wrong analysis tool results.
                 The used analysis tool QAC 9.0 sometimes creates wrong messages. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/

