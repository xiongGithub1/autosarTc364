#ifndef SPI_TEST_H
#define SPI_TEST_H

#include "Spi.h"
#include "Std_Types.h"

extern uint32 SpiTest_9183SpiTxWord;
extern uint32 SpiTest_9183SpiRxWord;
extern uint32 SpiTest_9183SpiPrevRxWord;
extern boolean SpiTest_9183HwInited;
extern Std_ReturnType SpiTest_9183SpiSetupResult;
extern Std_ReturnType SpiTest_9183SpiTransmitResult;
extern Std_ReturnType SpiTest_9183SpiInitCheckResult;
extern Spi_StatusType SpiTest_9183SpiStatusBefore;
extern Spi_StatusType SpiTest_9183SpiStatusAfter;
extern Spi_JobResultType SpiTest_9183SpiJobResultBefore;
extern Spi_JobResultType SpiTest_9183SpiJobResultAfter;
extern Spi_SeqResultType SpiTest_9183SpiSeqResult;
extern Spi_SeqResultType SpiTest_9183SpiSeqResultBefore;
extern uint32 SpiTest_9183SpiTestCounter;
extern uint32 SpiTest_9183SpiOkCounter;
extern uint32 SpiTest_9183SpiFailCounter;
extern boolean SpiTest_9183SpiRxChanged;
extern boolean SpiTest_9183SpiTestEnabled;
extern boolean SpiTest_9183SpiLoopbackMatch;
extern boolean SpiTest_9183SpiLoopbackInternal;
extern boolean SpiTest_9183MrstPinLevel;
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
