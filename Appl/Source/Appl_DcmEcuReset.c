/**********************************************************************************************************************
 * Appl_DcmEcuReset.c — handle DcmEcuReset mode for 10 02 JumpToBoot
 *
 * Dcm (JMP2BOOT + RST2BOOT_HIS) sequence:
 *   1) Switch(JUMPTOBOOTLOADER / JUMPTOSYSSUPPLIERBOOTLOADER)
 *   2) SwitchAck must return RTE_E_TRANSMIT_ACK (else NRC 0x22)
 *   3) Dcm_SetProgConditions()  → Appl_ArmRequestBoot()
 *   4) Switch(EXECUTE)          → soft reset; Boot sees handshake and stays
 *********************************************************************************************************************/
#include "Appl_DcmEcuReset.h"
#include "Rte.h"
#include "BrsHw.h"

Std_ReturnType Appl_DcmEcuReset_Switch(Dcm_EcuResetType nextMode)
{
  /* JUMP* modes: acknowledge only; handshake is written in Dcm_SetProgConditions. */
  if (nextMode == RTE_MODE_DcmEcuReset_EXECUTE)
  {
    BrsHwSoftwareResetECU(); /* does not return */
  }
  return RTE_E_OK;
}

Std_ReturnType Appl_DcmEcuReset_SwitchAck(void)
{
  /* No Mode Manager connected — treat every switch as immediately acknowledged.
   * Without this, Dcm WaitForResetAck maps UNCONNECTED → DCM_E_NOT_OK → NRC 0x22. */
  return RTE_E_TRANSMIT_ACK;
}
