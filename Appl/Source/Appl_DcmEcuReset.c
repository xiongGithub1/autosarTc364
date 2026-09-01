/**********************************************************************************************************************
 * Appl_DcmEcuReset.c — handle DcmEcuReset mode for 10 02 JumpToBoot
 *
 * Dcm (JMP2BOOT + RST2BOOT_HIS) sequence — APP does NOT send final 50 02:
 *   1) Switch(JUMP*) — DigApp must NOT reset (prepare only)
 *   2) SwitchAck must complete (else NRC 0x22)
 *   3) Optional RCR-RP (0x78) if SendRespPendOnTransToBoot
 *   4) Dcm_SetProgConditions() → Appl_ArmRequestBoot()
 *   5) Switch(EXECUTE) immediately → soft reset (STOP_REPEATER, no APP 50 02)
 *   6) Boot stays on handshake and must send 50 02 (HIS)
 *********************************************************************************************************************/
#include "Appl_DcmEcuReset.h"
#include "Rte.h"
#include "BrsHw.h"

Std_ReturnType Appl_DcmEcuReset_Switch(Dcm_EcuResetType nextMode)
{
  /* HIS JumpToBoot (10 02):
   *   JUMP*  — prepare only (Dcm still sends 50 02 after SetProgConditions)
   *   EXECUTE — after positive response Tx confirmation → soft reset
   * SID 0x11 HARD/SOFT/KEYONOFF also reset here. */
  if ((nextMode == RTE_MODE_DcmEcuReset_EXECUTE)
      || (nextMode == RTE_MODE_DcmEcuReset_HARD)
      || (nextMode == RTE_MODE_DcmEcuReset_SOFT)
      || (nextMode == RTE_MODE_DcmEcuReset_KEYONOFF))
  {
    BrsHwSoftwareResetECU(); /* does not return */
  }
  /* JUMPTOBOOTLOADER / JUMPTOSYSSUPPLIERBOOTLOADER: no reset */
  return RTE_E_OK;
}

Std_ReturnType Appl_DcmEcuReset_SwitchAck(void)
{
  /* No Mode Manager connected — treat every switch as immediately acknowledged.
   * Without this, Dcm WaitForResetAck maps UNCONNECTED → DCM_E_NOT_OK → NRC 0x22. */
  return RTE_E_TRANSMIT_ACK;
}
