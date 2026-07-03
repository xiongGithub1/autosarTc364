/**********************************************************************************************************************
 *  Tle9183.h
 *
 *  TLE9183QK gate driver power-up and SPI access (datasheet Figure 21 / user manual ch.5).
 **********************************************************************************************************************/

#ifndef TLE9183_H
#define TLE9183_H

#include "Std_Types.h"

#define TLE9183_REG_CONF_SIG            (0x00U)
#define TLE9183_REG_NOP                 (0x32U)
#define TLE9183_CONF_SIG_DEFAULT        (0xBAU)

#define TLE9183_SPI_STATUS_CONFIG_VALID (0x04U)

typedef enum
{
  TLE9183_STATE_UNINIT = 0U,
  TLE9183_STATE_IDLE_READY,
  TLE9183_STATE_CONFIGURED
} Tle9183_StateType;

typedef enum
{
  TLE9183_INIT_PHASE_NONE = 0U,
  TLE9183_INIT_PHASE_POWER_DONE,
  TLE9183_INIT_PHASE_ERR_TIMEOUT,
  TLE9183_INIT_PHASE_SPI_HW_FAIL,
  TLE9183_INIT_PHASE_SPI_CRC_FAIL,
  TLE9183_INIT_PHASE_SPI_OK,
  TLE9183_INIT_PHASE_CONFIG_DONE
} Tle9183_InitPhaseType;

typedef struct
{
  Tle9183_StateType     State;
  Tle9183_InitPhaseType InitPhase;
  uint32                LastTxFrame;
  uint32                LastRxFrame;
  uint8                 LastSpiStatus;
  uint8                 LastData;
  uint8                 LastAddr;
  boolean               LastCrcOk;
  boolean               PowerUpDone;
  boolean               ErrPinLevel;
  boolean               MrstPinLevel;
  uint32                Qspi3Pisel;
  uint32                Qspi3Status;
  uint32                Qspi3ErrorFlags;
  uint32                InitAttemptCounter;
  uint32                SpiOkCounter;
  uint32                SpiFailCounter;
} Tle9183_StatusType;

extern Tle9183_StatusType Tle9183_Status;

void Tle9183_Init(void);
void Tle9183_MainFunction(void);
Std_ReturnType Tle9183_ReadRegister(uint8 regAddr, uint8 *regData);
Std_ReturnType Tle9183_WriteRegister(uint8 regAddr, uint8 regData);
Tle9183_StateType Tle9183_GetState(void);

#endif /* TLE9183_H */
