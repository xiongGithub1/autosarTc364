/**********************************************************************************************************************
 *  Tle9180_AutosarPort.h - Dio/Spi/Mcal delay for TLE9180 gate driver (AUTOSAR MCAL)
 **********************************************************************************************************************/
#ifndef TLE9180_AUTOSARPORT_H
#define TLE9180_AUTOSARPORT_H

#include "Std_Types.h"
#include "TLE9180_Types.h"

void Tle9180_Port_DelayUs(uint32 delayUs);
void Tle9180_Port_DelayMs(uint32 delayMs);

void Tle9180_Port_ActivateInhibit(void);
void Tle9180_Port_DeactivateInhibit(void);
void Tle9180_Port_ActivateEnable(void);
void Tle9180_Port_DeactivateEnable(void);
void Tle9180_Port_ActivateSafeOff(void);
void Tle9180_Port_DeactivateSafeOff(void);
boolean Tle9180_Port_GetErrorState(void);

Std_ReturnType Tle9180_Port_SpiExchange(IfxTLE9180 *handle, uint32 txFrame);

#endif /* TLE9180_AUTOSARPORT_H */
