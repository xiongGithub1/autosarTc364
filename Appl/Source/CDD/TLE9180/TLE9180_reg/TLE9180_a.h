/*
 * TLE9180_a.h
 *
 *  Created on: 2023Äê6ÔÂ29ÈÕ
 *      Author: zhaopinyong
 */

#ifndef TLE9180_A_H_
#define TLE9180_A_H_

#include "TLE9180_a_regdef.h"


typedef struct SFR_TLE
{
	struct Conf_regs
	{
		Conf_Sig_TYPE		Conf_Sig_Type;
		Conf_Gen_1_TYPE		Conf_Gen_1_Type;
		Conf_Gen_2_TYPE		Conf_Gen_2_Type;
		Conf_Gen_3_TYPE		Conf_Gen_3_Type;
		Conf_wwd_TYPE		Conf_wwd_Type;
		Tl_vs_TYPE			Tl_vs_Type;
		Tl_vdh_TYPE			Tl_vdh_Type;
		Tl_cbvcc_TYPE		Tl_cbvcc_Type;
		Fm_1_TYPE			Fm_1_Type;
		Fm_2_TYPE			Fm_2_Type;
		Fm_3_TYPE			Fm_3_Type;
		Fm_4_TYPE			Fm_4_Type;
		Fm_5_TYPE			Fm_5_Type;
		Dt_hs_TYPE			Dt_hs_Type;
		Dt_ls_TYPE			Dt_ls_Type;
		Ft_1_TYPE			Ft_1_Type;
		Ft_2_TYPE			Ft_2_Type;
		Ft_3_TYPE			Ft_3_Type;
		Ft_4_TYPE			Ft_4_Type;
		Fm_6_TYPE			Fm_6_Type;
	}Conf_regs;

	struct Control_regs
	{
		Op_gain_1_TYPE		Op_gain_1_Type;
		Op_gain_2_TYPE		Op_gain_2_Type;
		Op_gain_3_TYPE		Op_gain_3_Type;
		Op_0cl_TYPE			Op_0cl_Type;
		op_con_TYPE			op_con_Type;
		Sc_ls_1_TYPE		Sc_ls_1_Type;
		Sc_ls_2_TYPE		Sc_ls_2_Type;
		Sc_ls_3_TYPE		Sc_ls_3_Type;
		Sc_hs_1_TYPE		Sc_hs_1_Type;
		Sc_hs_2_TYPE		Sc_hs_2_Type;
		Sc_hs_3_TYPE		Sc_hs_3_Type;
		Li_ctr_TYPE			Li_ctr_Type;
		Misc_ctr_TYPE		Misc_ctr_Type;
		art_tlp_TYPE		art_tlp_Type;
		art_tla_TYPE		art_tla_Type;
		art_fi_TYPE			art_fi_Type;
		art_acc_TYPE		art_acc_Type;
		art_entry_TYPE		art_entry_Type;
		nop_TYPE			nop_Type;
		Drev_mark_TYPE		Drev_mark_Type;
		Ds_mark_TYPE		Ds_mark_Type;
	}Control_regs;

	struct Self_test_regs
	{
		Sel_st_1_TYPE		Sel_st_1_Type;
		Sel_st_2_TYPE		Sel_st_2_Type;
		En_st_TYPE			En_st_Type;
	}Self_test_regs;

	struct Read_regs
	{
		Om_over_TYPE		Om_over_Type;
		Err_over_TYPE		Err_over_Type;
		Ser_TYPE			SerType;
		Err_i_1_TYPE		Err_i_1Type;
		Err_i_2_TYPE		Err_i_2_Type;
		Err_e_TYPE			Err_e_Type;
		Err_sd_TYPE			Err_sd_Type;
		Err_scd_TYPE		Err_scd_Type;
		Err_indiag_TYPE		Err_indiag_Type;
		Err_osf_TYPE		Err_osf_Type;
		Err_spiconf_TYPE	Err_spiconf_Type;
		Err_op_12_TYPE		Err_op_12_Type;
		Err_op_3_TYPE		Err_op_3_Type;
		Err_outp_TYPE		Err_outp_Type;
		dsm_ls1_TYPE		dsm_ls1_Type;
		dsm_ls2_TYPE		dsm_ls2_Type;
		dsm_ls3_TYPE		dsm_ls3_Type;
		dsm_hs1_TYPE		dsm_hs1_Type;
		dsm_hs2_TYPE		dsm_hs2_Type;
		dsm_hs3_TYPE		dsm_hs3_Type;
		Rdm_ls1_TYPE		Rdm_ls1_Type;
		Rdm_ls2_TYPE		Rdm_ls2_Type;
		Rdm_ls3_TYPE		Rdm_ls3_Type;
		Rdm_hs1_TYPE		Rdm_hs1_Type;
		Rdm_hs2_TYPE		Rdm_hs2_Type;
		Rdm_hs3_TYPE		Rdm_hs3_Type;
		temp_ls1_TYPE		temp_ls1_Type;
		temp_ls2_TYPE		temp_ls2_Type;
		temp_ls3_TYPE		temp_ls3_Type;
		temp_hs1_TYPE		temp_hs1_Type;
		temp_hs2_TYPE		temp_hs2_Type;
		temp_hs3_TYPE		temp_hs3_Type;
		wwlc_TYPE			wwlc_Type;
		res_cc1_TYPE		res_cc1_Type;
		res_cc2_TYPE		res_cc2_Type;
		res_cc3_TYPE		res_cc3_Type;
		res_vcc_TYPE		res_vcc_Type;
		res_cb_TYPE			res_cb_Type;
		res_vs_TYPE			res_vs_Type;
		res_vdh_TYPE		res_vdh_Type;
	}Read_regs;

}SFR_TLE;
extern SFR_TLE sfr_tle;

#endif /* TLE9180_A_H_ */
