/*
 * CRC.c
 *
 *  Created on: 2023Äê6ÔÂ29ÈÕ
 *      Author: aiq
 */

#include <tle9180CRC.h>
uint32 calcCRC_3(uint32 CRCinput)
{
	uint8 i = 0,Num_Bits = 24,CRC_Bits = 3;
	uint8 xor_1 = 0, xor_2 = 0;
	uint32 crc_in = CRCinput;
	uint8 CRC[3] = {0,0,0};
	uint8 crc_out = 0;
	uint32 DataCRC=0;

	for(i=0; i<Num_Bits; i++)
	{
		xor_2 = CRC[0] ^ CRC[2];
		xor_1 = (crc_in >> (Num_Bits-1-i) & 0x1) ^ CRC[2];

		CRC[2] = CRC[1];
		CRC[1] = xor_2;
		CRC[0] = xor_1;
	}

	for(i=0; i<CRC_Bits; i++)
	{
		crc_out = crc_out ^ CRC[CRC_Bits-1-i];
		if(i < CRC_Bits - 1)
		{
			crc_out = crc_out << 1;
		}
	}
	crc_out = (crc_out + 0x4) & 0x7;	//start value 'b100'

	DataCRC = crc_out | CRCinput;
	return DataCRC;
}

uint8 calcCRC_8(uint32* CRCinput, uint8 len)
{
	uint8 i=0, j=0, Num_Bits=8, CRC_Bits=8;
	uint8 xor_1=0, xor_2=0, xor_3=0, xor_4=0;
	uint8 crc_in = 0;
	uint8 CRC[8] = {0,0,0,0,0,0,0,0};
	uint8 crc_out = 0;
	uint8 crc_in_len = 0;
	crc_in_len = len;

	for(j=0; j<=crc_in_len; j++)
	{
		if(j < crc_in_len)
		{
			crc_in = (CRCinput[j] & 0xff00)>>8;
		}
		else
		{
			crc_in = 0;		//left shift 8bit for CRC calculation
		}

		for(i=0; i<Num_Bits; i++)
		{
			xor_4 = CRC[5] ^ CRC[7];
			xor_3 = CRC[2] ^ CRC[7];
			xor_2 = CRC[1] ^ CRC[7];
			xor_1 = ((crc_in >> (Num_Bits-1-i))& 0x1) ^ CRC[7];
			CRC[7] = CRC[6];
			CRC[6] = xor_4;
			CRC[5] = CRC[4];
			CRC[4] = CRC[3];
			CRC[3] = xor_3;
			CRC[2] = xor_2;
			CRC[1] = CRC[0];
			CRC[0] = xor_1;
		}
	}

	for(i=0; i<CRC_Bits; i++)
	{
		crc_out = crc_out ^ CRC[CRC_Bits-1-i];
		if(i < CRC_Bits-1)
		{
			crc_out = crc_out<<1;
		}
	}

	return (uint8)crc_out;
}













