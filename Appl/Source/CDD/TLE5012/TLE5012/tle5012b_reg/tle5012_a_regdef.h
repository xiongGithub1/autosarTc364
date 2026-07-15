/*
 * tle5012_a_regdef.h
 *
 *  Created on: 2020Äê6ÔÂ15ÈÕ
 *      Author: Administrator
 */

#ifndef _TLE5012_A_REGDEF_H_
#define _TLE5012_A_REGDEF_H_

typedef struct STAT_TYPE_Bits			//0x0
{
	boolean	S_RST				:1;
	boolean	S_WD				:1;
	boolean	S_VR				:1;
	boolean	S_FUSE				:1;
	boolean	S_DSPU				:1;
	boolean	S_OV				:1;
	boolean	S_XYOL				:1;
	boolean	S_MAGOL				:1;
	boolean	Reserved			:1;
	boolean	S_ADCT				:1;
	boolean	S_ROM				:1;
	boolean	NO_GMR_XY			:1;
	boolean	NO_GMR_A			:1;
	uint8	S_NR				:2;
	boolean	RD_ST				:1;
} STAT_TYPE_Bits;

typedef struct ACSTAT_TYPE_Bits			//0x1
{
	boolean	AS_RST				:1;
	boolean	AS_WD				:1;
	boolean	AS_VR				:1;
	boolean	AS_FUSE				:1;
	boolean	AS_DSPU				:1;
	boolean	AS_OV				:1;
	boolean	AS_VEC_XY			:1;
	boolean	AS_VEG_MAG			:1;
	boolean	Reserved8			:1;
	boolean	AS_ADCT				:1;
	boolean	AS_FRST				:1;
	uint8	Reserved			:5;
} ACSTAT_TYPE_Bits;

typedef struct AVAL_TYPE_Bits			//0x2
{
	uint16 ANG_VAL				:15;
	boolean RD_AV				:1;
} AVAL_TYPE_Bits;

typedef struct ASPD_TYPE_Bits			//0x3
{
	uint16 ANG_SPD				:15;
	boolean RD_AS				:1;
} ASPD_TYPE_Bits;

typedef struct AREV_TYPE_Bits			//0x4
{
	uint16 REVOL				:9;
	uint16 FCNT					:6;
	boolean RD_REV				:1;
} AREV_TYPE_Bits;

typedef struct FSYNC_TYPE_Bits			//0x5
{
	uint16 TEMPER				:9;
	uint16 FSYNC				:7;
} FSYNC_TYPE_Bits;

typedef struct MOD_1_TYPE_Bits			//0x6
{
	uint8 IIF_MOD				:2;
	boolean DSPU_HOLD			:1;
	boolean Reserved3			:1;
	boolean CLK_SEL				:1;
	uint16 Reserved5			:9;
	uint8 FIR_MD				:2;
} MOD_1_TYPE_Bits;

typedef struct SIL_TYPE_Bits				//0x7
{
	uint8 ADCTV_X				:3;
	uint8 ADCTV_Y				:3;
	boolean ADCTV_EN			:1;
	uint8 reserved7				:3;
	boolean FUSE_REL			:1;
	uint8 reserved11			:3;
	boolean FILT_INV			:1;
	boolean FILT_PAR			:1;
} SIL_TYPE_Bits;

typedef struct MOD_2_TYPE_Bits				//0x8
{
	uint8 AUTOCAL				:2;
	boolean PREDICT				:1;
	boolean ANG_DIR				:1;
	uint16 ANG_RANGE			:11;
	boolean reserved15			:1;
} MOD_2_TYPE_Bits;

typedef struct MOD_3_TYPE_Bits				//0x9
{
	uint16 PAD_DRV				:2;
	boolean SSC_OD				:1;
	boolean SPIKEF				:1;
	uint16 ANG_BASE				:12;
} MOD_3_TYPE_Bits;

typedef struct OFFX_TYPE_Bits				//0xA
{
	uint8 reserved				:4;
	uint16 X_OFFSET				:12;
} OFFX_TYPE_Bits;

typedef struct OFFY_TYPE_Bits				//0xB
{
	uint8 reserved				:4;
	uint16 Y_OFFSET				:12;
} OFFY_TYPE_Bits;

typedef struct SYNCH_TYPE_Bits				//0xC
{
	uint8 reserved				:4;
	uint16 SYNCH				:12;
} SYNCH_TYPE_Bits;

typedef struct IFAB_TYPE_Bits				//0xD
{
	uint8 IFAB_HYST				:2;

	boolean IFAB_OD				:1;
	boolean FIR_UDR				:1;
	uint16 ORTHO				:12;
} IFAB_TYPE_Bits;

typedef struct MOD_4_TYPE_Bits				//0xE
{
	uint8 IF_MD					:2;
	boolean reserved			:1;
	uint8 IFAB_RES				:2;
	uint8 HSM_PLP				:4;
	uint8 TCO_X_T				:7;
} MOD_4_TYPE_Bits;

typedef struct TCO_Y_TYPE_Bits				//0xF
{
	uint8 CRC_PAR				:8;
	boolean SBIST				:1;
	uint8 TCO_Y_T				:7;
} TCO_Y_TYPE_Bits;

typedef struct ADC_X_TYPE_Bits				//0x10
{
	uint16 ADC_X				:16;
} ADC_X_TYPE_Bits;

typedef struct ADC_Y_TYPE_Bits				//0x11
{
	uint16 ADC_Y				:16;
} ADC_Y_TYPE_Bits;

typedef struct D_MAG_TYPE_Bits				//0x14
{
	uint16 MAG				:10;
	uint8 reserved			:6;
} D_MAG_TYPE_Bits;

typedef struct T_RAW_TYPE_Bits				//0x15
{
	uint16 T_RAW			:10;
	uint8 reserved			:6;
} T_RAW_TYPE_Bits;

typedef struct IIF_CNT_TYPE_Bits			//0x20
{
	uint16 IIF_CNT			:14;
	uint8 reserved			:2;
} IIF_CNT_TYPE_Bits;

typedef struct T25O_TYPE_Bits				//0x30
{
	uint16 reserved			:9;
	uint8 T25O				:7;
} T25O_TYPE_Bits;



typedef union
{
	uint16							U;
	STAT_TYPE_Bits					B;
} STAT_TYPE;

typedef union
{
	uint16							U;
	ACSTAT_TYPE_Bits				B;
} ACSTAT_TYPE;

typedef union
{
	uint16							U;
	AVAL_TYPE_Bits					B;
} AVAL_TYPE;

typedef union
{
	uint16							U;
	ASPD_TYPE_Bits					B;
} ASPD_TYPE;

typedef union
{
	uint16							U;
	FSYNC_TYPE_Bits					B;
} FSYNC_TYPE;

typedef union
{
	uint16							U;
	AREV_TYPE_Bits					B;
} AREV_TYPE;

typedef union
{
	uint16							U;
	MOD_1_TYPE_Bits					B;
} MOD_1_TYPE;

typedef union
{
	uint16							U;
	SIL_TYPE_Bits					B;
} SIL_TYPE;

typedef union
{
	uint16							U;
	MOD_2_TYPE_Bits					B;
} MOD_2_TYPE;

typedef union
{
	uint16							U;
	MOD_3_TYPE_Bits					B;
} MOD_3_TYPE;

typedef union
{
	uint16							U;
	OFFX_TYPE_Bits					B;
} OFFX_TYPE;

typedef union
{
	uint16							U;
	OFFY_TYPE_Bits					B;
} OFFY_TYPE;

typedef union
{
	uint16							U;
	SYNCH_TYPE_Bits					B;
} SYNCH_TYPE;

typedef union
{
	uint16							U;
	IFAB_TYPE_Bits					B;
} IFAB_TYPE;

typedef union
{
	uint16							U;
	MOD_4_TYPE_Bits					B;
} MOD_4_TYPE;

typedef union
{
	uint16							U;
	TCO_Y_TYPE_Bits					B;
} TCO_Y_TYPE;

typedef union
{
	uint16							U;
	ADC_X_TYPE_Bits					B;
} ADC_X_TYPE;

typedef union
{
	uint16							U;
	ADC_Y_TYPE_Bits					B;
} ADC_Y_TYPE;

typedef union
{
	uint16							U;
	D_MAG_TYPE_Bits					B;
} D_MAG_TYPE;

typedef union
{
	uint16							U;
	T_RAW_TYPE_Bits					B;
} T_RAW_TYPE;
typedef union
{
	uint16							U;
	IIF_CNT_TYPE_Bits				B;
} IIF_CNT_TYPE;

typedef union
{
	uint16							U;
	T25O_TYPE_Bits					B;
} T25O_TYPE;

#endif /* _TLE5012_A_REGDEF_H_ */
