/*
 * tle5012_a.h
 *
 *  Created on: 2020Äê6ÔÂ15ÈÕ
 *      Author: Administrator
 */

#ifndef _TLE5012_A_H_
#define _TLE5012_A_H_

#include "tle5012_a_regdef.h"

typedef struct TLE5012_SFR
{
		STAT_TYPE			STAT_Type;
		ACSTAT_TYPE			ACSTAT_Type;
		AVAL_TYPE			AVAL_Type;
		ASPD_TYPE			ASPD_Type;
		AREV_TYPE			AREV_Type;
		FSYNC_TYPE			FSYNC_Type;
		MOD_1_TYPE			MOD_1_Type;
		SIL_TYPE			SIL_Type;
		MOD_2_TYPE			MOD_2_Type;
		MOD_3_TYPE			MOD_3_Type;
		OFFX_TYPE			OFFX_Type;
		OFFY_TYPE			OFFY_Type;
		SYNCH_TYPE			SYNCH_Type;
		IFAB_TYPE			IFAB_Type;
		MOD_4_TYPE			MOD_4_Type;
		TCO_Y_TYPE			TCO_Y_Type;
		ADC_X_TYPE			ADC_X_Type;
		ADC_Y_TYPE			ADC_Y_Type;
		D_MAG_TYPE			D_MAG_Type;
		T_RAW_TYPE			T_RAW_Type;
		IIF_CNT_TYPE		IIF_CNT_Type;
		T25O_TYPE			T25O_Type;

}TLE5012_SFR;
extern TLE5012_SFR tle5012_sfr;

#endif /* _TLE5012_A_H_ */
