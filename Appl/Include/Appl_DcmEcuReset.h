/**********************************************************************************************************************
 * Appl_DcmEcuReset.h — Dcm EcuReset mode switch hooks for JumpToBoot (10 02)
 *
 * Wired from Rte_Switch / Rte_SwitchAck in Rte_SystemApplication_OsCore0.c.
 * After DaVinci RTE Generate, re-apply that wiring (or connect DcmEcuReset in Developer).
 *********************************************************************************************************************/
#ifndef APPL_DCMECURESET_H
#define APPL_DCMECURESET_H

#include "Std_Types.h"
#include "Rte_Dcm_Type.h"

Std_ReturnType Appl_DcmEcuReset_Switch(Dcm_EcuResetType nextMode);
Std_ReturnType Appl_DcmEcuReset_SwitchAck(void);

#endif /* APPL_DCMECURESET_H */
