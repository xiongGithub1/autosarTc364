/**********************************************************************************************************************
 *  Tle5012bd_Spi.h - TLE5012BD SPI transport via AUTOSAR MCAL Sync (QSPI2)
 **********************************************************************************************************************/
#ifndef TLE5012BD_SPI_H
#define TLE5012BD_SPI_H

#include "Spi.h"
#include "Std_Types.h"

extern uint32 Tle5012bd_SpiLastTxWord;
extern uint32 Tle5012bd_SpiLastRxWord;
extern Std_ReturnType Tle5012bd_SpiLastResult;
extern Std_ReturnType Tle5012bd_SpiLastSetupResult;
extern Std_ReturnType Tle5012bd_SpiLastTransmitResult;

Std_ReturnType Tle5012bd_SpiExchangeU32(uint32 txWord, uint32 *rxWord);

#endif /* TLE5012BD_SPI_H */
