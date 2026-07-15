/**********************************************************************************************************************
 *  Tle5012bd_Spi.h - TLE5012BD SPI transport via AUTOSAR MCAL (QSPI2)
 **********************************************************************************************************************/
#ifndef TLE5012BD_SPI_H
#define TLE5012BD_SPI_H

#include "Spi.h"
#include "Std_Types.h"

extern uint32 Tle5012bd_SpiLastTxWord;
extern uint32 Tle5012bd_SpiLastRxWord;
extern uint16 Tle5012bd_SpiLastTxWords[2];
extern uint16 Tle5012bd_SpiLastRxWords[2];
extern Std_ReturnType Tle5012bd_SpiLastResult;
extern Std_ReturnType Tle5012bd_SpiLastSetupResult;
extern Std_ReturnType Tle5012bd_SpiLastTransmitResult;
extern Spi_SeqResultType Tle5012bd_SpiLastSeqResult;
extern Spi_StatusType Tle5012bd_SpiStatusBefore;
extern Spi_StatusType Tle5012bd_SpiStatusAfter;

/* Debug: HW/DMA snapshot at Wait timeout */
extern uint32 Tle5012bd_SpiLastRxFifoLev;
extern uint32 Tle5012bd_SpiLastTxFifoLev;
extern uint32 Tle5012bd_SpiDmaRxEvents;
extern boolean Tle5012bd_SpiCpuRxDrainUsed;

Std_ReturnType Tle5012bd_SpiExchangeU32(uint32 txWord, uint32 *rxWord);

#endif /* TLE5012BD_SPI_H */
