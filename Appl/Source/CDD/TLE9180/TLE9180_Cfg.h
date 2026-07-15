/*
 * TLE9180_Cfg.h
 *
 *  Created on: 2023Äê6ÔÂ29ÈÕ
 *      Author: Administrator
 */

#ifndef TLE9180_CFG_H_
#define TLE9180_CFG_H_



typedef enum{
	Conf_Sig  			= 0x0,
	Conf_Gen_1 			= 0x010000,
	Conf_Gen_2 			= 0x020000,
	Conf_Gen_3 			= 0x030000,
	Conf_wwd 			= 0x040000,
	Tl_vs 				= 0x050000,
	Tl_vdh 				= 0x060000,
	Tl_cbvcc 			= 0x070000,
	Fm_1 				= 0x080000,
	Fm_2 				= 0x090000,
	Fm_3				= 0x0A0000,
	Fm_4 				= 0x0B0000,
	Fm_5 				= 0x0C0000,
	Dt_hs 				= 0x0D0000,
	Dt_ls 				= 0x0E0000,
	Ft_1 				= 0x0F0000,
	Ft_2	 			= 0x100000,
	Ft_3 				= 0x110000,
	Ft_4 				= 0x120000,
	Fm_6 				= 0x130000,
	Op_gain_1			= 0x200000,
	Op_gain_2 			= 0x210000,
	Op_gain_3 			= 0x220000,
	Op_0cl 				= 0x230000,
	op_con 				= 0x240000,
	Sc_ls_1 			= 0x250000,
	Sc_ls_2 			= 0x260000,
	Sc_ls_3 			= 0x270000,
	Sc_hs_1 			= 0x280000,
	Sc_hs_2 			= 0x290000,
	Sc_hs_3 			= 0x2A0000,
	Li_ctr 				= 0x2B0000,
	Misc_ctr 			= 0x2C0000,
	art_tlp 			= 0x2D0000,
	art_tla 			= 0x2E0000,
	art_fi 				= 0x2F0000,
	art_acc 			= 0x300000,
	art_entry 			= 0x310000,
	nop 				= 0x320000,
	Drev_mark 			= 0x330000,
	Ds_mark 			= 0x340000,
	Sel_st_1 			= 0x350000,
	Sel_st_2 			= 0x360000,
	En_st 				= 0x370000,
	Om_over 			= 0x400000,
	Err_over 			= 0x410000,
	Ser 				= 0x420000,
	Err_i_1				= 0x430000,
	Err_i_2 			= 0x440000,
	Err_e 				= 0x450000,
	Err_sd 				= 0x460000,
	Err_scd 			= 0x470000,
	Err_indiag 			= 0x480000,
	Err_osf 			= 0x490000,
	Err_spiconf 		= 0x4A0000,
	Err_op_12 			= 0x4B0000,
	Err_op_3 			= 0x4C0000,
	Err_outp 			= 0x4D0000,
	dsm_ls1 			= 0x4E0000,
	dsm_ls2 			= 0x4F0000,
	dsm_ls3 			= 0x500000,
	dsm_hs1 			= 0x510000,
	dsm_hs2 			= 0x520000,
	dsm_hs3 			= 0x530000,
	Rdm_ls1 			= 0x540000,
	Rdm_ls2 			= 0x550000,
	Rdm_ls3 			= 0x560000,
	Rdm_hs1 			= 0x570000,
	Rdm_hs2 			= 0x580000,
	Rdm_hs3 			= 0x590000,
	temp_ls1 			= 0x5A0000,
	temp_ls2 			= 0x5B0000,
	temp_ls3 			= 0x5C0000,
	temp_hs1 			= 0x5D0000,
	temp_hs2 			= 0x5E0000,
	temp_hs3 			= 0x5F0000,
	wwlc 				= 0x600000,
	res_cc1 			= 0x610000,
	res_cc2 			= 0x620000,
	res_cc3 			= 0x630000,
	res_vcc 			= 0x640000,
	res_cb 				= 0x650000,
	res_vs 				= 0x660000,
	res_vdh 			= 0x670000,
}tle_registers_t;
/*!
 * @brief  Op_gain_1 Register macros.		0x20
 */
typedef enum{
	op1_gain1_15_71 				= 0,
	op1_gain1_19_56					= 1<<12,
	op1_gain1_23_35					= 2<<12,
	op1_gain1_26_90					= 3<<12,
	op1_gain1_30_81					= 4<<12,
	op1_gain1_34_45					= 5<<12,
	op1_gain1_38_13					= 6<<12,
	op1_gain1_83_19					= 7<<12,
}sbc_Op1_gain_1_t;

typedef enum{
	op2_gain1_15_71 				= 0,
	op2_gain1_19_56					= 1<<8,
	op2_gain1_23_35					= 2<<8,
	op2_gain1_26_90					= 3<<8,
	op2_gain1_30_81					= 4<<8,
	op2_gain1_34_45					= 5<<8,
	op2_gain1_38_13					= 6<<8,
	op2_gain1_83_19					= 7<<8,
}sbc_Op2_gain_1_t;


/*!
 * @brief  Op_gain_2 Register macros.		0x21
 */
typedef enum{
	op1_gain2_15_71 				= 0,
	op1_gain2_19_56					= 1<<12,
	op1_gain2_23_35					= 2<<12,
	op1_gain2_26_90					= 3<<12,
	op1_gain2_30_81					= 4<<12,
	op1_gain2_34_45					= 5<<12,
	op1_gain2_38_13					= 6<<12,
	op1_gain2_83_19					= 7<<12,
}sbc_Op1_gain_2_t;

typedef enum{
	op2_gain2_15_71 				= 0,
	op2_gain2_19_56					= 1<<8,
	op2_gain2_23_35					= 2<<8,
	op2_gain2_26_90					= 3<<8,
	op2_gain2_30_81					= 4<<8,
	op2_gain2_34_45					= 5<<8,
	op2_gain2_38_13					= 6<<8,
	op2_gain2_83_19					= 7<<8,
}sbc_Op2_gain_2_t;

/*!
 * @brief  Op_gain_3 Register macros.		0x22
 */
typedef enum{
	op3_gain2_15_71 				= 0,
	op3_gain2_19_56					= 1<<12,
	op3_gain2_23_35					= 2<<12,
	op3_gain2_26_90					= 3<<12,
	op3_gain2_30_81					= 4<<12,
	op3_gain2_34_45					= 5<<12,
	op3_gain2_38_13					= 6<<12,
	op3_gain2_83_19					= 7<<12,
}sbc_Op3_gain_2_t;

typedef enum{
	op3_gain1_15_71 				= 0,
	op3_gain1_19_56					= 1<<8,
	op3_gain1_23_35					= 2<<8,
	op3_gain1_26_90					= 3<<8,
	op3_gain1_30_81					= 4<<8,
	op3_gain1_34_45					= 5<<8,
	op3_gain1_38_13					= 6<<8,
	op3_gain1_83_19					= 7<<8,
}sbc_Op3_gain_1_t;

/*!
 * @brief  Op_0cl Register macros.		0x23
 */
typedef enum{
	zcl_0_5v		 				= 0,
	zcl_1_65v						= 1<<14,
	zcl_2_5v						= 2<<14,
	zcl_Reserved					= 3<<14,
}sbc_zcl_t;

typedef enum{
	ofs_default		 				= 0x1f<<8,
}sbc_ofs_t;

/*!
 * @brief  Misc_ctr Register macros.		0x2C
 */
typedef enum{
	opX_gain2_active 				= 0x1<<7,
	opX_gain1_active 				= 0x0,
}sh_op_gain_t;



/*!
 * @brief  Sel_st_1 Register macros.		0x35
 */
typedef enum{
	st_uv_vcc		 				= 1<<15,
	st_scd_hs						= 1<<14,
	st_scd_ls						= 1<<13,
	st_uv_cb						= 1<<12,
	st_hs							= 1<<10,
	st_ls							= 1<<9,
}Sel_st_1;

/*!
 * @brief  Sel_st_2 Register macros.		0x36
 */
typedef enum{
	en_op3_gt2							= 1<<14,
	en_op3_gt1							= 1<<13,
	en_op2_gt2							= 1<<12,
	en_op2_gt1							= 1<<11,
	en_op1_gt2							= 1<<10,
	en_op1_gt1							= 1<<9,
	en_vreg_op							= 1<<8,
}Sel_st_2;

#endif /* TLE9180_CFG_H_ */
