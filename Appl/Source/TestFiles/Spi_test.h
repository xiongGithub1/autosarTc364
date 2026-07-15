#ifndef SPI_TEST_H
#define SPI_TEST_H

#include "Spi.h"
#include "Std_Types.h"

extern uint32 SpiTest_TxWord;
extern uint32 SpiTest_RxWord;
extern uint32 SpiTest_PrevRxWord;
extern Std_ReturnType SpiTest_SetupResult;
extern Std_ReturnType SpiTest_TransmitResult;
extern Spi_StatusType SpiTest_StatusBefore;
extern Spi_StatusType SpiTest_StatusAfter;
extern Spi_JobResultType SpiTest_JobResultBefore;
extern Spi_JobResultType SpiTest_JobResultAfter;
extern Spi_SeqResultType SpiTest_SeqResult;
extern Spi_SeqResultType SpiTest_SeqResultBefore;
extern uint32 SpiTest_TestCounter;
extern uint32 SpiTest_OkCounter;
extern uint32 SpiTest_FailCounter;
extern boolean SpiTest_RxChanged;
extern boolean SpiTest_Enabled;
extern boolean SpiTest_LoopbackMatch;
extern boolean SpiTest_LoopbackInternal;
extern boolean SpiTest_MrstPinLevel;
extern uint8 SpiTest_Qspi3BitCount;
extern uint32 SpiTest_Qspi3GlobalconLb;
extern uint32 SpiTest_Qspi3GlobalconLbBeforeTx;
extern Std_ReturnType SpiTest_Qspi3LoopbackCtrlResult;
extern uint32 SpiTest_Qspi3Clc;
extern uint32 SpiTest_Qspi3Pisel;
extern uint32 SpiTest_Qspi3Globalcon;
extern uint32 SpiTest_Qspi3Globalcon1;
extern uint32 SpiTest_Qspi3Bacon;
extern uint32 SpiTest_Qspi3Status;
extern uint32 SpiTest_Qspi3Status1;
extern uint32 SpiTest_Qspi3Ssoc;

void SpiTest_Init(void);
void SpiTest_RunOnce(void);

#endif
