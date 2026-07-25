/*
 * CRC.h
 *
 *  Created on: 2023Äê6ÔÂ29ÈÕ
 *      Author: zhaopinyong
 */

#ifndef CRC_H_
#define CRC_H_
#include <string.h>
#include "Platform_Types.h"

uint32 calcCRC_3(uint32 CRCinput);
uint8 calcCRC_8(uint32* CRCinput, uint8 len);

#endif /* CRC_H_ */
