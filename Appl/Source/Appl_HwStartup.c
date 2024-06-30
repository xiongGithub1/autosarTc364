/**********************************************************************************************************************
 *  Appl_HwStartup.c
 *
 *  TC364 low-level startup helpers (WDT, trap/interrupt vectors, ISP).
 *  WDT unlock follows Infineon McalLib / Mcal_WdgLib sequence (LFSR password,
 *  two-step CON0 access). Simple password XOR causes WDT access trap.
 **********************************************************************************************************************/

#include "Appl_HwStartup.h"
#include "Mcal_Compiler.h"
#include "Ifx_reg.h"
#include "IfxScu_bf.h"
#include "IfxCpu_reg.h"

#if defined(_TASKING_C_TRICORE_)
extern void _lc_u_trap_tab_tc0(void);
extern void _lc_ue_istack_tc0(void);
#endif

extern uint8 _OS_INTVEC_CORE0_CODE_START[];
extern uint8 _OS_EXCVEC_CORE0_CODE_START[];

#define APPL_HWSTARTUP_WDT_SAFETY              (0U)
#define APPL_HWSTARTUP_WDT_CPU0                (1U)

#define APPL_HWSTARTUP_WDT_DISABLE_CON1        (0x00000008U) /* DR = 1 */
#define APPL_HWSTARTUP_FLASH_PWAIT_PRE_PLL     (0x00000015U)

#define APPL_HWSTARTUP_WDT_PWD_MASK            (0x0000FFFCU)
#define APPL_HWSTARTUP_WDT_PWD_INV             (0x003FU)
#define APPL_HWSTARTUP_WDT_RELOAD_MASK         (0xFFFF0000U)
#define APPL_HWSTARTUP_WDT_SR_TIMER_MASK       (0xFFFF0000U)
#define APPL_HWSTARTUP_WDT_UNLOCK              (0x00000001U)
#define APPL_HWSTARTUP_WDT_DISABLE_ENDINIT     (0x00000002U)
#define APPL_HWSTARTUP_WDT_ENABLE_ENDINIT      (0x00000003U)
#define APPL_HWSTARTUP_WDT_ENDINIT_TIMEOUT     (0x0000FFFCU)
#define APPL_HWSTARTUP_WDT_TIMER_MAX           (0xFFFFU)
#define APPL_HWSTARTUP_WDT_PASSEQ_SHIFT        (11U)
#define APPL_HWSTARTUP_WDT_PASSWORD_SHIFT      (12U)
#define APPL_HWSTARTUP_WDT_LFSR_SHIFT          (13U)

typedef struct
{
  volatile Ifx_SCU_WDTCPU_CON0 *Con0;
  volatile Ifx_SCU_WDTCPU_SR   *Sr;
  volatile Ifx_SCU_WDTCPU_CON1 *Con1;
} Appl_HwStartup_WdtAccessType;

typedef struct
{
  uint16 Password;
  uint32 TimerRelValAtReset;
} Appl_HwStartup_WdtCtxType;

static const Appl_HwStartup_WdtAccessType Appl_HwStartup_kWdtAccess[] =
{
  {
    (volatile Ifx_SCU_WDTCPU_CON0 *)&MODULE_SCU.WDTS.CON0,
    (volatile Ifx_SCU_WDTCPU_SR *)&MODULE_SCU.WDTS.SR,
    (volatile Ifx_SCU_WDTCPU_CON1 *)&MODULE_SCU.WDTS.CON1
  },
  {
    &MODULE_SCU.WDTCPU[0U].CON0,
    &MODULE_SCU.WDTCPU[0U].SR,
    &MODULE_SCU.WDTCPU[0U].CON1
  }
};

static uint16 Appl_HwStartup_lDecryptPw(uint32 con0Value)
{
  return (uint16)(((con0Value & APPL_HWSTARTUP_WDT_PWD_MASK) >>
                   IFX_SCU_WDTCPU_CON0_PW_OFF) ^ APPL_HWSTARTUP_WDT_PWD_INV);
}

static uint32 Appl_HwStartup_lCpuPwSequence(uint8 wdtSel, uint32 con0Value)
{
  uint32 password = (uint32)Appl_HwStartup_lDecryptPw(con0Value);
  const volatile Ifx_SCU_WDTCPU_SR *sr = Appl_HwStartup_kWdtAccess[wdtSel].Sr;

  if (((sr->U >> IFX_SCU_WDTCPU_SR_PAS_OFF) & IFX_SCU_WDTCPU_SR_PAS_MSK) != 0U)
  {
    const uint32 pwdBit0 = (((password >> 1U) ^ (password >> APPL_HWSTARTUP_WDT_PASSEQ_SHIFT) ^
                             (password >> APPL_HWSTARTUP_WDT_PASSWORD_SHIFT) ^
                             (password >> APPL_HWSTARTUP_WDT_LFSR_SHIFT)) & 1U);

    password = ((password << 1U) | pwdBit0) & (uint32)IFX_SCU_WDTCPU_CON0_PW_MSK;
  }

  return password;
}

static uint32 Appl_HwStartup_lCpuRelValue(uint8 wdtSel, uint32 con0Value)
{
  const volatile Ifx_SCU_WDTCPU_SR *sr = Appl_HwStartup_kWdtAccess[wdtSel].Sr;
  uint32 timerReload;

  if (((sr->U >> IFX_SCU_WDTCPU_SR_TCS_OFF) & IFX_SCU_WDTCPU_SR_TCS_MSK) != 0U)
  {
    timerReload = ((sr->U & APPL_HWSTARTUP_WDT_SR_TIMER_MASK) >> IFX_SCU_WDTCPU_SR_TIM_OFF);
    timerReload = (~timerReload) & (uint32)IFX_SCU_WDTCPU_SR_TIM_MSK;
  }
  else
  {
    timerReload = ((con0Value & APPL_HWSTARTUP_WDT_RELOAD_MASK) >> IFX_SCU_WDTCPU_CON0_REL_OFF);
  }

  return timerReload;
}

static uint32 Appl_HwStartup_lCalculateTimerReloadVal(uint8 wdtSel,
                                                      uint32 timerRelValAtReset,
                                                      boolean setEndinit)
{
  const volatile Ifx_SCU_WDTCPU_SR *sr = Appl_HwStartup_kWdtAccess[wdtSel].Sr;
  uint32 timerReload = (sr->U >> IFX_SCU_WDTCPU_SR_TIM_OFF) & (uint32)IFX_SCU_WDTCPU_SR_TIM_MSK;

  if (setEndinit != FALSE)
  {
    timerReload -= APPL_HWSTARTUP_WDT_ENDINIT_TIMEOUT;
    timerReload += timerRelValAtReset;

    if (timerReload > APPL_HWSTARTUP_WDT_TIMER_MAX)
    {
      timerReload = APPL_HWSTARTUP_WDT_TIMER_MAX;
    }
  }

  return timerReload;
}

static Appl_HwStartup_WdtCtxType Appl_HwStartup_lUpdateWdtEndinit(uint8 wdtSel,
                                                                  uint32 timerRelValAtReset,
                                                                  boolean setEndinit)
{
  Appl_HwStartup_WdtCtxType ctx;
  volatile Ifx_SCU_WDTCPU_CON0 *wdtCon0 = Appl_HwStartup_kWdtAccess[wdtSel].Con0;
  uint32 con0Value = wdtCon0->U;
  uint32 unlockPassword = Appl_HwStartup_lCpuPwSequence(wdtSel, con0Value);
  uint32 unlockTimerReload = Appl_HwStartup_lCpuRelValue(wdtSel, con0Value);
  uint32 unlockCon0Value;
  uint32 newCon0Value;
  uint32 timerReload;

  ctx.Password = Appl_HwStartup_lDecryptPw(con0Value);
  ctx.TimerRelValAtReset = 0U;

  timerReload = Appl_HwStartup_lCalculateTimerReloadVal(wdtSel, timerRelValAtReset, setEndinit);

  unlockCon0Value = (unlockTimerReload << IFX_SCU_WDTCPU_CON0_REL_OFF) |
                    (unlockPassword << IFX_SCU_WDTCPU_CON0_PW_OFF) |
                    APPL_HWSTARTUP_WDT_UNLOCK;

  if (setEndinit != FALSE)
  {
    newCon0Value = (timerReload << IFX_SCU_WDTCPU_CON0_REL_OFF) |
                   ((uint32)ctx.Password << IFX_SCU_WDTCPU_CON0_PW_OFF) |
                   APPL_HWSTARTUP_WDT_ENABLE_ENDINIT;
  }
  else
  {
    newCon0Value = (timerReload << IFX_SCU_WDTCPU_CON0_REL_OFF) |
                   ((uint32)ctx.Password << IFX_SCU_WDTCPU_CON0_PW_OFF) |
                   APPL_HWSTARTUP_WDT_DISABLE_ENDINIT;
    ctx.TimerRelValAtReset = timerReload;
  }

  wdtCon0->U = unlockCon0Value;
  (void)wdtCon0->U;

  wdtCon0->U = newCon0Value;
  (void)wdtCon0->U;

  return ctx;
}

static void Appl_HwStartup_lDisableWatchdog(uint8 wdtSel)
{
  Appl_HwStartup_WdtCtxType ctx;

  DISABLE();
  ctx = Appl_HwStartup_lUpdateWdtEndinit(wdtSel, 0U, FALSE);
  Appl_HwStartup_kWdtAccess[wdtSel].Con1->U = APPL_HWSTARTUP_WDT_DISABLE_CON1;
  (void)Appl_HwStartup_lUpdateWdtEndinit(wdtSel, ctx.TimerRelValAtReset, TRUE);
  ENABLE();
}

static void Appl_HwStartup_lInitFlashWaitStatesPrePll(void)
{
  Appl_HwStartup_WdtCtxType ctx;
  uint32 pwait;

  DISABLE();
  ctx = Appl_HwStartup_lUpdateWdtEndinit(APPL_HWSTARTUP_WDT_CPU0, 0U, FALSE);

  pwait = DMU_HF_PWAIT.U;
  pwait &= (uint32)0xFFFFFFC0U;
  pwait |= APPL_HWSTARTUP_FLASH_PWAIT_PRE_PLL;
  DMU_HF_PWAIT.U = pwait;

  (void)Appl_HwStartup_lUpdateWdtEndinit(APPL_HWSTARTUP_WDT_CPU0, ctx.TimerRelValAtReset, TRUE);
  ENABLE();
}

static void Appl_HwStartup_lInitCpuVectors(void)
{
  Appl_HwStartup_WdtCtxType ctx;
  uint32 ispAddress;
  uint32 intVecAddress;
  uint32 excVecAddress;

#if defined(_TASKING_C_TRICORE_)
  ispAddress = (uint32)&_lc_ue_istack_tc0;
#else
  ispAddress = 0U;
#endif

  intVecAddress = (uint32)&_OS_INTVEC_CORE0_CODE_START;
  excVecAddress = (uint32)&_OS_EXCVEC_CORE0_CODE_START;

  DISABLE();
  ctx = Appl_HwStartup_lUpdateWdtEndinit(APPL_HWSTARTUP_WDT_CPU0, 0U, FALSE);

  if (ispAddress != 0U)
  {
    MTCR(CPU_ISP, ispAddress);
    ISYNC();
  }

  if (excVecAddress != 0U)
  {
    MTCR(CPU_BTV, excVecAddress);
    ISYNC();
  }

  if ((intVecAddress != 0U) && ((intVecAddress & 0x00001FFFU) == 0U))
  {
    MTCR(CPU_BIV, intVecAddress);
    ISYNC();
  }

  (void)Appl_HwStartup_lUpdateWdtEndinit(APPL_HWSTARTUP_WDT_CPU0, ctx.TimerRelValAtReset, TRUE);
  ENABLE();
}

void Appl_HwStartup_Init(void)
{
  uint32 coreId;

  coreId = (uint32)MFCR(CPU_CORE_ID);
  coreId &= 0x00000007U;

  if (coreId == 0U)
  {
    Appl_HwStartup_lDisableWatchdog(APPL_HWSTARTUP_WDT_SAFETY);
    Appl_HwStartup_lInitFlashWaitStatesPrePll();
  }

  Appl_HwStartup_lDisableWatchdog((uint8)(APPL_HWSTARTUP_WDT_CPU0 + coreId));
  Appl_HwStartup_lInitCpuVectors();
}