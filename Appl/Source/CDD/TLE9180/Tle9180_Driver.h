/**********************************************************************************************************************
 *  Tle9180_Driver.h - TLE9180 gate driver CDD API (AUTOSAR)
 **********************************************************************************************************************/
#ifndef TLE9180_DRIVER_H
#define TLE9180_DRIVER_H

#include "Std_Types.h"

typedef enum
{
  TLE9180_DRV_STATE_UNINIT = 0U,
  TLE9180_DRV_STATE_READY,
  TLE9180_DRV_STATE_FAULT
} Tle9180_DriverStateType;

typedef enum
{
  TLE9180_OP_MODE_UNKNOWN = 0U,
  TLE9180_OP_MODE_SLEEP,
  TLE9180_OP_MODE_IDLE,
  TLE9180_OP_MODE_CONFIG,
  TLE9180_OP_MODE_CONFIG_LOCK,
  TLE9180_OP_MODE_SELF_TEST,
  TLE9180_OP_MODE_SAFE_OFF,
  TLE9180_OP_MODE_ERROR,
  TLE9180_OP_MODE_REDUCED,
  TLE9180_OP_MODE_NORMAL
} Tle9180_OperationModeType;
void Tle9180_Driver_Init(void);
void Tle9180_Driver_MainFunction(void);
extern uint32 Tle9180_Driver_MainCounter;
extern uint32 Tle9180_Driver_InitStepCounter;
extern Std_ReturnType Tle9180_Driver_LastSpiExchangeResult;
extern uint32 Tle9180_Driver_LastTxFrame;
extern uint32 Tle9180_Driver_LastRxFrame;
extern uint8 Tle9180_Driver_LastRxAddress;
extern uint8 Tle9180_Driver_LastRxData;
Tle9180_DriverStateType Tle9180_Driver_GetState(void);
uint8 Tle9180_Driver_GetLastInitError(void);
Std_ReturnType Tle9180_Driver_ReadOperationMode(void);
Tle9180_OperationModeType Tle9180_Driver_GetOperationMode(void);
uint8 Tle9180_Driver_GetOperationModeRaw(void);
void Tle9180_Driver_EnableOutput(boolean enable);
void Tle9180_Driver_ReadErrorStatus(void);

#endif /* TLE9180_DRIVER_H */


