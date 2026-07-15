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

static void MotorCdd_PwmComplementaryInit(void);


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

FUNC(void, MotorCdd_CODE) MotorCDDMainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MotorCDDMainFunction
 *********************************************************************************************************************/
  /* Backup cmd mirror only. 9180 Sync Init/steps run in StartApp 1 ms — not MotorTask. */
  MotorCdd_FocUpdateCmdMirror();

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

static void MotorCdd_PwmComplementaryInit(void)
{
  MODULE_GTM.CDTM[MOTORCDD_DTM_CDTM_INDEX].DTM[MOTORCDD_DTM_INDEX].CTRL.B.CLK_SEL =
      MOTORCDD_DTM_CLK_SEL_CMU_CLK1;

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

  MODULE_GTM.CDTM[MOTORCDD_DTM_CDTM_INDEX].DTM[MOTORCDD_DTM_INDEX].CH_CTRL2.B.POL0_1 = 1U;
  MODULE_GTM.CDTM[MOTORCDD_DTM_CDTM_INDEX].DTM[MOTORCDD_DTM_INDEX].CH_CTRL2.B.POL0_2 = 1U;
  MODULE_GTM.CDTM[MOTORCDD_DTM_CDTM_INDEX].DTM[MOTORCDD_DTM_INDEX].CH_CTRL2.B.POL0_3 = 1U;

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

