/*
 * TLE9180_a_regdef.h
 *
 *  Created on: 2023Äê6ÔÂ29ÈÕ
 *      Author: zhaopinyong
 */

#ifndef TLE9180_A_REGDEF_H_
#define TLE9180_A_REGDEF_H_

typedef uint32 TLE_Type;


typedef struct Conf_Sig_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 CRC1				:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Conf_Sig_TYPE_Bits;


typedef union
{
	TLE_Type							U;
	Conf_Sig_TYPE_Bits					B;
} Conf_Sig_TYPE;


typedef struct Conf_Gen_1_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	boolean vcc_select		:1;
	boolean vcc_sup_off		:1;
	boolean limp_act		:1;
	boolean spi_wwd_act		:1;
	boolean in_diag_act		:1;
	uint8 tl_ot_w			:3;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Conf_Gen_1_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Conf_Gen_1_TYPE_Bits				B;
} Conf_Gen_1_TYPE;

typedef struct Conf_Gen_2_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	boolean en_op1			:1;
	boolean en_op2			:1;
	boolean en_op3			:1;
	boolean en_vdh3			:1;
	boolean dis_sd_vdh		:1;
	boolean dis_ov_ld_vdh	:1;
	boolean dis_ov_bh		:1;
	boolean tl_oc_op		:1;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Conf_Gen_2_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Conf_Gen_2_TYPE_Bits				B;
} Conf_Gen_2_TYPE;

typedef struct Conf_Gen_3_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	boolean art_scd			:1;
	uint8 apc_conf			:2;
	uint8 apc_tact			:3;
	boolean en_ART			:1;
	boolean Res				:1;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Conf_Gen_3_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Conf_Gen_3_TYPE_Bits				B;
} Conf_Gen_3_TYPE;

typedef struct Conf_wwd_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 wwd_tp			:2;
	uint8 wwd_ratio			:3;
	uint8 wwd_count			:3;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Conf_wwd_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Conf_wwd_TYPE_Bits					B;
} Conf_wwd_TYPE;

typedef struct Tl_vs_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 tl_uv_vs			:4;
	uint8 tl_ov_vs			:4;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Tl_vs_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Tl_vs_TYPE_Bits						B;
} Tl_vs_TYPE;

typedef struct Tl_vdh_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 tl_uv_vdh			:4;
	uint8 tl_ov_vdh			:4;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Tl_vdh_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Tl_vdh_TYPE_Bits					B;
} Tl_vdh_TYPE;

typedef struct Tl_cbvcc_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 tl_uv_vcc			:2;
	uint8 tl_ov_vcc			:2;
	uint8 tl_uv_cb			:4;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Tl_cbvcc_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Tl_vdh_TYPE_Bits					B;
} Tl_cbvcc_TYPE;

typedef struct Fm_1_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 fm_uv_bs			:2;
	uint8 Res				:2;
	boolean fm_cp2_off		:1;
	boolean Res_5			:1;
	uint8 fm_uv_cb			:2;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Fm_1_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Fm_1_TYPE_Bits						B;
} Fm_1_TYPE;

typedef struct Fm_2_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 fm_ot_w			:2;
	uint8 Res				:2;
	uint8 fm_spi_wwd		:2;
	uint8 fm_act_apc		:2;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Fm_2_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Fm_2_TYPE_Bits						B;
} Fm_2_TYPE;

typedef struct Fm_3_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 fm_uv_vcc			:2;
	uint8 fm_uv_vdh			:2;
	uint8 fm_uv_vs			:2;
	uint8 Res				:2;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Fm_3_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Fm_3_TYPE_Bits						B;
} Fm_3_TYPE;

typedef struct Fm_4_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 fm_ov_vcc			:2;
	uint8 fm_ov_vdh			:3;
	uint8 fm_ov_vs			:2;
	boolean Res				:1;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Fm_4_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Fm_4_TYPE_Bits						B;
} Fm_4_TYPE;

typedef struct Fm_5_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 fm_in_diag		:2;
	uint8 fm_osfb			:2;
	boolean fm_outp_ol		:1;
	uint8 fm_scd			:3;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Fm_5_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Fm_5_TYPE_Bits						B;
} Fm_5_TYPE;

typedef struct Dt_hs_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 dths				:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Dt_hs_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Dt_hs_TYPE_Bits						B;
} Dt_hs_TYPE;

typedef struct Dt_ls_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 dtls				:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Dt_ls_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Dt_ls_TYPE_Bits						B;
} Dt_ls_TYPE;

typedef struct Ft_1_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 f_uv_vs			:2;
	uint8 f_uv_vdh			:2;
	uint8 f_uv_cb			:2;
	uint8 f_uv_bs			:2;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Ft_1_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Ft_1_TYPE_Bits						B;
} Ft_1_TYPE;

typedef struct Ft_2_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 f_ov_vs			:2;
	uint8 f_ov_vdh			:2;
	uint8 f_ov_vcc			:2;
	uint8 f_uv_vcc			:2;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Ft_2_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Ft_2_TYPE_Bits						B;
} Ft_2_TYPE;

typedef struct Ft_3_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 f_fi_scd			:2;
	uint8 f_bl_scd			:3;
	uint8 f_ot_w			:2;
	boolean f_ot_sd			:1;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Ft_3_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Ft_3_TYPE_Bits						B;
} Ft_3_TYPE;

typedef struct Ft_4_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 f_oc_op			:2;
	uint8 Res				:6;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Ft_4_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Ft_4_TYPE_Bits						B;
} Ft_4_TYPE;

typedef struct Fm_6_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 fm_oc_op1			:2;
	uint8 fm_oc_op2			:2;
	uint8 fm_oc_op3			:2;
	uint8 Res				:2;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Fm_6_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Fm_6_TYPE_Bits						B;
} Fm_6_TYPE;

typedef struct Op_gain_1_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 op2_gain1			:3;
	boolean Res				:1;
	uint8 op1_gain1			:3;
	boolean Res_7			:1;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Op_gain_1_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Op_gain_1_TYPE_Bits					B;
} Op_gain_1_TYPE;

typedef struct Op_gain_2_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 op2_gain2			:3;
	boolean Res				:1;
	uint8 op1_gain2			:3;
	boolean Res_7			:1;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Op_gain_2_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Op_gain_2_TYPE_Bits					B;
} Op_gain_2_TYPE;

typedef struct Op_gain_3_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 op3_gain1			:3;
	boolean Res				:1;
	uint8 op3_gain2			:3;
	boolean Res_7			:1;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Op_gain_3_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Op_gain_3_TYPE_Bits					B;
} Op_gain_3_TYPE;

typedef struct Op_0cl_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 ofs				:6;
	uint8 zcl				:2;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Op_0cl_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Op_0cl_TYPE_Bits					B;
} Op_0cl_TYPE;

typedef struct op_con_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	boolean op3_cal_n		:1;
	boolean zop2_cal_ncl	:1;
	boolean op1_cal_n		:1;
	uint8 Res				:2;
	boolean op3_cal			:1;
	boolean op2_cal			:1;
	boolean op1_cal			:1;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} op_con_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	op_con_TYPE_Bits					B;
} op_con_TYPE;

typedef struct Sc_ls_1_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 sc_ls_1			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Sc_ls_1_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Sc_ls_1_TYPE_Bits					B;
} Sc_ls_1_TYPE;

typedef struct Sc_ls_2_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 sc_ls_2			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Sc_ls_2_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Sc_ls_2_TYPE_Bits					B;
} Sc_ls_2_TYPE;

typedef struct Sc_ls_3_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 sc_ls_3			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Sc_ls_3_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Sc_ls_3_TYPE_Bits					B;
} Sc_ls_3_TYPE;

typedef struct Sc_hs_1_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 sc_hs_1			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Sc_hs_1_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Sc_hs_1_TYPE_Bits					B;
} Sc_hs_1_TYPE;

typedef struct Sc_hs_2_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 sc_hs_2			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Sc_hs_2_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Sc_hs_2_TYPE_Bits					B;
} Sc_hs_2_TYPE;

typedef struct Sc_hs_3_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 sc_hs_3			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Sc_hs_3_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Sc_hs_3_TYPE_Bits					B;
} Sc_hs_3_TYPE;

typedef struct Li_ctr_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	boolean dis_hb1			:1;
	boolean dis_hb2			:1;
	boolean dis_hb3			:1;
	boolean ex_limp			:1;
	boolean en_limp			:1;
	boolean en_hb1			:1;
	boolean en_hb2			:1;
	boolean en_hb3			:1;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Li_ctr_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Li_ctr_TYPE_Bits					B;
} Li_ctr_TYPE;

typedef struct Misc_ctr_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	boolean pfb				:1;
	boolean Res				:1;
	uint8 art				:2;
	uint8 Res_4				:3;
	boolean sh_op_gain		:1;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Misc_ctr_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Misc_ctr_TYPE_Bits					B;
} Misc_ctr_TYPE;

typedef struct art_tlp_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 tl_art_p			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} art_tlp_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	art_tlp_TYPE_Bits					B;
} art_tlp_TYPE;

typedef struct art_tla_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 tl_art_a			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} art_tla_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	art_tla_TYPE_Bits					B;
} art_tla_TYPE;

typedef struct art_fi_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 fi_art_tla		:4;
	uint8 fi_art_tlp		:4;


	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} art_fi_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	art_fi_TYPE_Bits					B;
} art_fi_TYPE;

typedef struct art_acc_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 acc_art_tla		:3;
	uint8 Res				:2;
	uint8 acc_art_tlp		:3;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} art_acc_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	art_acc_TYPE_Bits					B;
} art_acc_TYPE;

typedef struct art_entry_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	boolean art_en			:1;
	uint8 Res				:6;
	boolean art_dis			:1;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} art_entry_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	art_entry_TYPE_Bits					B;
} art_entry_TYPE;

typedef struct nop_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 nop				:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} nop_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	nop_TYPE_Bits					B;
} nop_TYPE;

typedef struct Drev_mark_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	boolean ls1				:1;
	boolean ls2				:1;
	boolean ls3				:1;
	boolean hs1				:1;
	boolean hs2				:1;
	boolean hs3				:1;
	uint8 Drev_acc			:2;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Drev_mark_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Drev_mark_TYPE_Bits					B;
} Drev_mark_TYPE;

typedef struct Ds_mark_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	boolean ls1				:1;
	boolean ls2				:1;
	boolean ls3				:1;
	boolean hs1				:1;
	boolean hs2				:1;
	boolean hs3				:1;
	uint8 Res				:2;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Ds_mark_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Ds_mark_TYPE_Bits					B;
} Ds_mark_TYPE;

typedef struct Sel_st_1_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	boolean Res				:1;
	boolean st_ls			:1;
	boolean st_hs			:1;
	boolean Res_3			:1;
	boolean st_uv_cb		:1;
	boolean st_scd_ls		:1;
	boolean st_scd_hs		:1;
	boolean st_uv_vcc		:1;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Sel_st_1_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Sel_st_1_TYPE_Bits					B;
} Sel_st_1_TYPE;

typedef struct Sel_st_2_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	boolean en_vreg_op		:1;
	boolean en_op1_gt1		:1;
	boolean en_op1_gt2		:1;
	boolean en_op2_gt1		:1;
	boolean en_op2_gt2		:1;
	boolean en_op3_gt1		:1;
	boolean en_op3_gt2		:1;
	boolean Res				:1;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Sel_st_2_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Sel_st_2_TYPE_Bits					B;
} Sel_st_2_TYPE;

typedef struct En_st_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	boolean en_st			:1;
	uint8 Res				:6;
	boolean dis_st			:1;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} En_st_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	En_st_TYPE_Bits						B;
} En_st_TYPE;

typedef struct Om_over_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	boolean idle_m			:1;
	boolean conf_m			:1;
	boolean conf_lock		:1;
	boolean self_test_m		:1;
	boolean soff_m			:1;
	boolean err_m			:1;
	boolean rect_m			:1;
	boolean norm_m			:1;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Om_over_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Om_over_TYPE_Bits					B;
} Om_over_TYPE;

typedef struct Err_over_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	boolean osf				:1;
	boolean op				:1;
	boolean scd				:1;
	boolean sd				:1;
	boolean indiag			:1;
	boolean outp			:1;
	boolean ext				:1;
	boolean int12			:1;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Err_over_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Err_over_TYPE_Bits					B;
} Err_over_TYPE;

typedef struct Ser_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	boolean rom				:1;
	boolean limp_on			:1;
	boolean Res				:1;
	boolean apc_act			:1;
	boolean gtm				:1;
	boolean ctrl_reg_invalid:1;
	boolean lfw				:1;
	boolean err_ot_w		:1;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Ser_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Ser_TYPE_Bits						B;
} Ser_TYPE;

typedef struct Err_i_1_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	boolean err_ov_reg1		:1;
	boolean err_uv_vcc_rom	:1;
	boolean err_uv_reg4		:1;
	boolean err_ov_reg6		:1;
	boolean err_uv_reg6		:1;
	boolean err_uv_reg5		:1;
	boolean err_uv_cb		:1;
	boolean Res				:1;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Err_i_1_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Err_i_1_TYPE_Bits					B;
} Err_i_1_TYPE;

typedef struct Err_i_2_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	boolean err_uv_bs3		:1;
	boolean err_uv_bs2		:1;
	boolean err_uv_bs1		:1;
	boolean err_cp2			:1;
	boolean err_cp1			:1;
	boolean err_ov_bs3		:1;
	boolean err_ov_bs2		:1;
	boolean Rerr_ov_bs1		:1;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Err_i_2_TYPE_Bits;
typedef union
{
	TLE_Type							U;
	Err_i_2_TYPE_Bits					B;
} Err_i_2_TYPE;

typedef struct Err_e_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	boolean err_ov_vdh		:1;
	boolean err_uv_vdh		:1;
	boolean err_ov_vs		:1;
	boolean err_uv_vs		:1;
	boolean err_uv_vcc		:1;
	boolean err_ov_vcc		:1;
	boolean err_ov_ld_vdh	:1;
	boolean Res				:1;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Err_e_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	Err_e_TYPE_Bits					B;
} Err_e_TYPE;

typedef struct Err_sd_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	boolean sd_ddp_stuck	:1;
	boolean sd_cp1			:1;
	boolean sd_ov_cp		:1;
	boolean sd_clkfail		:1;
	boolean sd_uv_cb		:1;
	boolean sd_ov_vdh		:1;
	boolean sd_ov_vs		:1;
	boolean sd_ot			:1;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Err_sd_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	Err_sd_TYPE_Bits					B;
} Err_sd_TYPE;

typedef struct Err_scd_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 Res				:2;
	boolean err_scd_ls3		:1;
	boolean err_scd_ls2		:1;
	boolean err_scd_ls1		:1;
	boolean err_scd_hs3		:1;
	boolean err_scd_hs2		:1;
	boolean err_scd_hs1		:1;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Err_scd_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	Err_scd_TYPE_Bits				B;
} Err_scd_TYPE;

typedef struct Err_indiag_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 Res				:2;
	boolean err_ind_ls3		:1;
	boolean err_ind_ls2		:1;
	boolean err_ind_ls1		:1;
	boolean err_ind_hs3		:1;
	boolean err_ind_hs2		:1;
	boolean err_ind_hs1		:1;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Err_indiag_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	Err_indiag_TYPE_Bits			B;
} Err_indiag_TYPE;

typedef struct Err_osf_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 Res				:2;
	boolean err_osf_ls1		:1;
	boolean err_osf_ls2		:1;
	boolean err_osf_ls3		:1;
	boolean err_osf_hs1		:1;
	boolean err_osf_hs2		:1;
	boolean err_osf_hs3		:1;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Err_osf_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	Err_osf_TYPE_Bits				B;
} Err_osf_TYPE;

typedef struct Err_spiconf_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	boolean err_spi_frame	:1;
	boolean err_spi_to		:1;
	boolean err_spi_wd		:1;
	boolean err_spi_crc		:1;
	boolean spi_add_invalid	:1;
	boolean conf_to			:1;
	boolean conf_sig_invalid:1;
	boolean Res				:1;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Err_spiconf_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	Err_spiconf_TYPE_Bits			B;
} Err_spiconf_TYPE;

typedef struct Err_op_12_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	boolean err_oc_op1		:1;
	boolean err_op1_uv		:1;
	boolean err_op1_ov		:1;
	boolean err_op1_calib	:1;
	boolean err_oc_op2		:1;
	boolean err_op2_uv		:1;
	boolean err_op2_ov		:1;
	boolean err_op2_calib	:1;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Err_op_12_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	Err_op_12_TYPE_Bits				B;
} Err_op_12_TYPE;

typedef struct Err_op_3_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	boolean err_oc_op3		:1;
	boolean err_op3_uv		:1;
	boolean err_op3_ov		:1;
	boolean err_op3_calib	:1;
	uint8 Res				:4;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Err_op_3_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	Err_op_3_TYPE_Bits				B;
} Err_op_3_TYPE;

typedef struct Err_outp_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	boolean err_outp_errn	:1;
	boolean err_outp_miso	:1;
	boolean err_outp_PFB1	:1;
	boolean err_outp_PFB2	:1;
	boolean err_outp_PFB3	:1;
	uint8 Res				:3;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Err_outp_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	Err_outp_TYPE_Bits				B;
} Err_outp_TYPE;

typedef struct dsm_ls1_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 dsm_ls1			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} dsm_ls1_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	dsm_ls1_TYPE_Bits				B;
} dsm_ls1_TYPE;

typedef struct dsm_ls2_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 dsm_ls2			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} dsm_ls2_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	dsm_ls2_TYPE_Bits				B;
} dsm_ls2_TYPE;

typedef struct dsm_ls3_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 dsm_ls3			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} dsm_ls3_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	dsm_ls3_TYPE_Bits				B;
} dsm_ls3_TYPE;

typedef struct dsm_hs1_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 dsm_hs1			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} dsm_hs1_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	dsm_hs1_TYPE_Bits				B;
} dsm_hs1_TYPE;

typedef struct dsm_hs2_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 dsm_hs2			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} dsm_hs2_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	dsm_hs2_TYPE_Bits				B;
} dsm_hs2_TYPE;

typedef struct dsm_hs3_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 dsm_hs2			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} dsm_hs3_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	dsm_hs3_TYPE_Bits				B;
} dsm_hs3_TYPE;

typedef struct Rdm_ls1_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 rdm_ls1			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Rdm_ls1_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	Rdm_ls1_TYPE_Bits				B;
} Rdm_ls1_TYPE;

typedef struct Rdm_ls2_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 rdm_ls2			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Rdm_ls2_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	Rdm_ls2_TYPE_Bits				B;
} Rdm_ls2_TYPE;

typedef struct Rdm_ls3_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 rdm_ls2			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Rdm_ls3_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	Rdm_ls3_TYPE_Bits				B;
} Rdm_ls3_TYPE;

typedef struct Rdm_hs1_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 rdm_hs1			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Rdm_hs1_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	Rdm_hs1_TYPE_Bits				B;
} Rdm_hs1_TYPE;

typedef struct Rdm_hs2_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 rdm_hs2			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Rdm_hs2_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	Rdm_hs2_TYPE_Bits				B;
} Rdm_hs2_TYPE;

typedef struct Rdm_hs3_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 rdm_hs3			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} Rdm_hs3_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	Rdm_hs3_TYPE_Bits				B;
} Rdm_hs3_TYPE;

typedef struct temp_ls1_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 temp_ls1			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} temp_ls1_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	temp_ls1_TYPE_Bits				B;
} temp_ls1_TYPE;

typedef struct temp_ls2_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 temp_ls2			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} temp_ls2_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	temp_ls2_TYPE_Bits				B;
} temp_ls2_TYPE;

typedef struct temp_ls3_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 temp_ls3			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} temp_ls3_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	temp_ls3_TYPE_Bits				B;
} temp_ls3_TYPE;

typedef struct temp_hs1_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 temp_hs1			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} temp_hs1_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	temp_hs1_TYPE_Bits				B;
} temp_hs1_TYPE;

typedef struct temp_hs2_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 temp_hs2			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} temp_hs2_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	temp_hs2_TYPE_Bits				B;
} temp_hs2_TYPE;

typedef struct temp_hs3_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 temp_hs3			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} temp_hs3_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	temp_hs3_TYPE_Bits				B;
} temp_hs3_TYPE;

typedef struct wwlc_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 wwlc				:5;
	uint8 Res				:3;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} wwlc_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	wwlc_TYPE_Bits					B;
} wwlc_TYPE;

typedef struct res_cc1_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 cc_lowb			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} res_cc1_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	res_cc1_TYPE_Bits				B;
} res_cc1_TYPE;

typedef struct res_cc2_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 cc_medb			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} res_cc2_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	res_cc2_TYPE_Bits				B;
} res_cc2_TYPE;

typedef struct res_cc3_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 cc_highb			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} res_cc3_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	res_cc3_TYPE_Bits				B;
} res_cc3_TYPE;

typedef struct res_vcc_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 res_vcc			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} res_vcc_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	res_vcc_TYPE_Bits				B;
} res_vcc_TYPE;

typedef struct res_cb_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 res_cb			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} res_cb_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	res_cb_TYPE_Bits				B;
} res_cb_TYPE;

typedef struct res_vs_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 res_vs			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} res_vs_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	res_vs_TYPE_Bits				B;
} res_vs_TYPE;

typedef struct res_vdh_TYPE_Bits
{
	uint8 CRC				:3;
	boolean reserved		:1;

	uint8 res_vdh			:8;

	uint8 ADDRESS			:7;
	uint8 STATUS			:5;
} res_vdh_TYPE_Bits;
typedef union
{
	TLE_Type						U;
	res_vdh_TYPE_Bits				B;
} res_vdh_TYPE;

#endif /* TLE9180_A_REGDEF_H_ */
