/**********************************************************************************************************************
 * tle9180_test.h - TLE9180 SPI bring-up helpers (called from StartApp)
 **********************************************************************************************************************/
#ifndef TLE9180_TEST_H
#define TLE9180_TEST_H

#include "Tle9180_Driver.h"
#include "Spi.h"
#include "Std_Types.h"

/* TRUE: StartApp owns 9180 init/cyclic SPI; MotorCdd skips Driver_Init. */
extern boolean Tle9180Test_Enabled;
extern boolean Tle9180Test_HwInited;
extern Tle9180_DriverStateType Tle9180Test_State;
extern uint8 Tle9180Test_LastInitError;
extern uint8 Tle9180Test_OperationModeRaw;
extern Tle9180_OperationModeType Tle9180Test_OperationMode;
extern boolean Tle9180Test_IsSleepMode;
extern boolean Tle9180Test_IsIdleMode;
extern boolean Tle9180Test_IsConfigMode;
extern boolean Tle9180Test_IsConfigLockMode;
extern boolean Tle9180Test_IsNormalMode;
extern uint32 Tle9180Test_MainCounter;
extern uint32 Tle9180Test_InitStepCounter;
extern Std_ReturnType Tle9180Test_LastSpiExchangeResult;
extern uint32 Tle9180Test_LastTxFrame;
extern uint32 Tle9180Test_LastRxFrame;
extern uint8 Tle9180Test_LastRxAddress;
extern uint8 Tle9180Test_LastRxData;
extern Spi_StatusType Tle9180Test_SpiStatusBefore;
extern Spi_StatusType Tle9180Test_SpiStatusAfter;
extern Spi_JobResultType Tle9180Test_SpiJobResultBefore;
extern Spi_JobResultType Tle9180Test_SpiJobResultAfter;
extern Spi_SeqResultType Tle9180Test_SpiSeqResultBefore;
extern Spi_SeqResultType Tle9180Test_SpiSeqResultAfter;
extern uint32 Tle9180Test_TestCounter;
extern uint32 Tle9180Test_OkCounter;
extern uint32 Tle9180Test_FailCounter;

void Tle9180Test_Init(void);
void Tle9180Test_RunOnce(void);

#endif /* TLE9180_TEST_H */
