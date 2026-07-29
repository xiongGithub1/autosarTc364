/**********************************************************************************************************************
 *  Tle5012bd_Spi.h - TLE5012BD on QSPI2: direct SFR exchange (no MCAL SyncTransmit)
 **********************************************************************************************************************/
#ifndef TLE5012BD_SPI_H
#define TLE5012BD_SPI_H

#include "Std_Types.h"

extern uint32 Tle5012bd_SpiLastTxWord;
extern uint32 Tle5012bd_SpiLastRxWord;
extern Std_ReturnType Tle5012bd_SpiLastResult;

/* Call once after Spi_Init() so ECON/SLSO match SpiJob_5012BD. */
void Tle5012bd_SpiHwInit(void);

/* Blocking 32-bit frame via QSPI2 DATAENTRY/RXEXIT (~bit-time + short poll). */
Std_ReturnType Tle5012bd_SpiExchangeU32(uint32 txWord, uint32 *rxWord);

#endif /* TLE5012BD_SPI_H */
