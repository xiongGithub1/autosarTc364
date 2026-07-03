#include "Adc.h"
#include "Os.h"
#include "IfxSrc_reg.h"

uint32 AdcTest_IsrEntryCounter = 0U;

/*
 * Os_Hal_Context_Lcfg.c maps AdcIsr_G0/G2/G3 entry to
 * Os_Isr_Adc_RS0EventInterruptHandler (same symbol for all three SRCs).
 * MCAL handler checks SEFLAG per kernel, so dispatch all used kernels here.
 *
 * Without MCD Irq.c / Irq_Init(), program SRC here to match Os ISR levels.
 */
void Adc_SrcEnableInit(void)
{
  SRC_VADC_G0_SR0.B.SRPN = 3U;
  SRC_VADC_G0_SR0.B.TOS = 0U;
  SRC_VADC_G0_SR0.B.SRE = 1U;

  SRC_VADC_G2_SR0.B.SRPN = 4U;
  SRC_VADC_G2_SR0.B.TOS = 0U;
  SRC_VADC_G2_SR0.B.SRE = 1U;

  SRC_VADC_G3_SR0.B.SRPN = 5U;
  SRC_VADC_G3_SR0.B.TOS = 0U;
  SRC_VADC_G3_SR0.B.SRE = 1U;
}

ISR(Adc_RS0EventInterruptHandler)
{
  AdcTest_IsrEntryCounter++;
  Adc_RS0EventInterruptHandler(0U);
  Adc_RS0EventInterruptHandler(2U);
  Adc_RS0EventInterruptHandler(3U);
}
