/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ManipulatorME4901_sfun.h"
#include "c1_ManipulatorME4901.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ManipulatorME4901_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[8] = { "q", "nargin", "nargout", "qqd",
  "mn", "l", "C", "q_dot" };

/* Function Declarations */
static void initialize_c1_ManipulatorME4901(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance);
static void initialize_params_c1_ManipulatorME4901
  (SFc1_ManipulatorME4901InstanceStruct *chartInstance);
static void enable_c1_ManipulatorME4901(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance);
static void disable_c1_ManipulatorME4901(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_ManipulatorME4901
  (SFc1_ManipulatorME4901InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_ManipulatorME4901
  (SFc1_ManipulatorME4901InstanceStruct *chartInstance);
static void set_sim_state_c1_ManipulatorME4901
  (SFc1_ManipulatorME4901InstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_ManipulatorME4901(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance);
static void sf_c1_ManipulatorME4901(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance);
static void c1_chartstep_c1_ManipulatorME4901
  (SFc1_ManipulatorME4901InstanceStruct *chartInstance);
static void initSimStructsc1_ManipulatorME4901
  (SFc1_ManipulatorME4901InstanceStruct *chartInstance);
static void registerMessagesc1_ManipulatorME4901
  (SFc1_ManipulatorME4901InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c1_q_dot, const char_T *c1_identifier, real_T
  c1_y[3]);
static void c1_b_emlrt_marshallIn(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[3]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_c_emlrt_marshallIn(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c1_C, const char_T *c1_identifier, real_T c1_y
  [9]);
static void c1_d_emlrt_marshallIn(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[9]);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_e_emlrt_marshallIn(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[19]);
static real_T c1_abs(SFc1_ManipulatorME4901InstanceStruct *chartInstance, real_T
                     c1_x);
static real_T c1_mpower(SFc1_ManipulatorME4901InstanceStruct *chartInstance,
  real_T c1_a);
static void c1_eml_scalar_eg(SFc1_ManipulatorME4901InstanceStruct *chartInstance);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_f_emlrt_marshallIn(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_g_emlrt_marshallIn(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_ManipulatorME4901, const
  char_T *c1_identifier);
static uint8_T c1_h_emlrt_marshallIn(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_ManipulatorME4901(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_ManipulatorME4901 = 0U;
}

static void initialize_params_c1_ManipulatorME4901
  (SFc1_ManipulatorME4901InstanceStruct *chartInstance)
{
  real_T c1_d0;
  real_T c1_d1;
  sf_set_error_prefix_string(
    "Error evaluating data 'mn' in the parent workspace.\n");
  sf_mex_import_named("mn", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c1_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_mn = c1_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'l' in the parent workspace.\n");
  sf_mex_import_named("l", sf_mex_get_sfun_param(chartInstance->S, 0, 0), &c1_d1,
                      0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_l = c1_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c1_ManipulatorME4901(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_ManipulatorME4901(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_ManipulatorME4901
  (SFc1_ManipulatorME4901InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_ManipulatorME4901
  (SFc1_ManipulatorME4901InstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_u[9];
  const mxArray *c1_b_y = NULL;
  int32_T c1_i1;
  real_T c1_b_u[3];
  const mxArray *c1_c_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T (*c1_q_dot)[3];
  real_T (*c1_C)[9];
  c1_q_dot = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_C = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(3), FALSE);
  for (c1_i0 = 0; c1_i0 < 9; c1_i0++) {
    c1_u[c1_i0] = (*c1_C)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  for (c1_i1 = 0; c1_i1 < 3; c1_i1++) {
    c1_b_u[c1_i1] = (*c1_q_dot)[c1_i1];
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_ManipulatorME4901;
  c1_c_u = c1_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_ManipulatorME4901
  (SFc1_ManipulatorME4901InstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[9];
  int32_T c1_i2;
  real_T c1_dv1[3];
  int32_T c1_i3;
  real_T (*c1_C)[9];
  real_T (*c1_q_dot)[3];
  c1_q_dot = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_C = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)), "C",
                        c1_dv0);
  for (c1_i2 = 0; c1_i2 < 9; c1_i2++) {
    (*c1_C)[c1_i2] = c1_dv0[c1_i2];
  }

  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
                      "q_dot", c1_dv1);
  for (c1_i3 = 0; c1_i3 < 3; c1_i3++) {
    (*c1_q_dot)[c1_i3] = c1_dv1[c1_i3];
  }

  chartInstance->c1_is_active_c1_ManipulatorME4901 = c1_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
     "is_active_c1_ManipulatorME4901");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_ManipulatorME4901(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_ManipulatorME4901(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance)
{
}

static void sf_c1_ManipulatorME4901(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance)
{
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  real_T (*c1_q_dot)[3];
  real_T (*c1_C)[9];
  real_T (*c1_qqd)[9];
  c1_q_dot = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_C = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i4 = 0; c1_i4 < 9; c1_i4++) {
    _SFD_DATA_RANGE_CHECK((*c1_qqd)[c1_i4], 0U);
  }

  for (c1_i5 = 0; c1_i5 < 9; c1_i5++) {
    _SFD_DATA_RANGE_CHECK((*c1_C)[c1_i5], 1U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c1_mn, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_l, 3U);
  for (c1_i6 = 0; c1_i6 < 3; c1_i6++) {
    _SFD_DATA_RANGE_CHECK((*c1_q_dot)[c1_i6], 4U);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_ManipulatorME4901(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ManipulatorME4901MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_ManipulatorME4901
  (SFc1_ManipulatorME4901InstanceStruct *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  int32_T c1_i7;
  real_T c1_qqd[9];
  real_T c1_b_mn;
  real_T c1_b_l;
  uint32_T c1_debug_family_var_map[8];
  real_T c1_q[3];
  real_T c1_nargin = 3.0;
  real_T c1_nargout = 2.0;
  real_T c1_C[9];
  real_T c1_q_dot[3];
  real_T c1_a;
  real_T c1_b;
  real_T c1_y;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_b_b;
  real_T c1_b_y;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_c_b;
  real_T c1_c_y;
  real_T c1_b_a;
  real_T c1_d_b;
  real_T c1_d_y;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_c_a;
  real_T c1_e_b;
  real_T c1_e_y;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_f_b;
  real_T c1_f_y;
  real_T c1_d_a;
  real_T c1_g_b;
  real_T c1_g_y;
  real_T c1_h_b;
  real_T c1_h_y;
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_e_a;
  real_T c1_i_b;
  real_T c1_i_y;
  real_T c1_f_a;
  real_T c1_j_b;
  real_T c1_j_y;
  real_T c1_A;
  real_T c1_m_x;
  real_T c1_n_x;
  real_T c1_k_y;
  real_T c1_g_a;
  real_T c1_k_b;
  real_T c1_l_y;
  real_T c1_o_x;
  real_T c1_p_x;
  real_T c1_l_b;
  real_T c1_m_y;
  real_T c1_q_x;
  real_T c1_r_x;
  real_T c1_s_x;
  real_T c1_t_x;
  real_T c1_m_b;
  real_T c1_n_y;
  real_T c1_h_a;
  real_T c1_n_b;
  real_T c1_o_y;
  real_T c1_u_x;
  real_T c1_v_x;
  real_T c1_i_a;
  real_T c1_o_b;
  real_T c1_p_y;
  real_T c1_w_x;
  real_T c1_x_x;
  real_T c1_p_b;
  real_T c1_q_y;
  real_T c1_j_a;
  real_T c1_q_b;
  real_T c1_r_y;
  real_T c1_r_b;
  real_T c1_s_y;
  real_T c1_y_x;
  real_T c1_ab_x;
  real_T c1_k_a;
  real_T c1_s_b;
  real_T c1_t_y;
  real_T c1_l_a;
  real_T c1_t_b;
  real_T c1_u_y;
  real_T c1_b_A;
  real_T c1_bb_x;
  real_T c1_cb_x;
  real_T c1_v_y;
  real_T c1_m_a;
  real_T c1_u_b;
  real_T c1_w_y;
  real_T c1_db_x;
  real_T c1_eb_x;
  real_T c1_n_a;
  real_T c1_v_b;
  real_T c1_x_y;
  real_T c1_w_b;
  real_T c1_y_y;
  real_T c1_fb_x;
  real_T c1_gb_x;
  real_T c1_o_a;
  real_T c1_x_b;
  real_T c1_ab_y;
  real_T c1_p_a;
  real_T c1_y_b;
  real_T c1_bb_y;
  real_T c1_hb_x;
  real_T c1_ib_x;
  real_T c1_ab_b;
  real_T c1_cb_y;
  real_T c1_jb_x;
  real_T c1_kb_x;
  real_T c1_q_a;
  real_T c1_bb_b;
  real_T c1_db_y;
  real_T c1_c_A;
  real_T c1_lb_x;
  real_T c1_mb_x;
  real_T c1_eb_y;
  real_T c1_r_a;
  real_T c1_cb_b;
  real_T c1_fb_y;
  real_T c1_nb_x;
  real_T c1_ob_x;
  real_T c1_db_b;
  real_T c1_gb_y;
  real_T c1_pb_x;
  real_T c1_qb_x;
  real_T c1_s_a;
  real_T c1_eb_b;
  real_T c1_hb_y;
  real_T c1_rb_x;
  real_T c1_sb_x;
  real_T c1_t_a;
  real_T c1_fb_b;
  real_T c1_ib_y;
  real_T c1_gb_b;
  real_T c1_jb_y;
  real_T c1_tb_x;
  real_T c1_ub_x;
  real_T c1_u_a;
  real_T c1_hb_b;
  real_T c1_kb_y;
  real_T c1_v_a;
  real_T c1_ib_b;
  real_T c1_lb_y;
  real_T c1_d_A;
  real_T c1_vb_x;
  real_T c1_wb_x;
  real_T c1_mb_y;
  real_T c1_w_a;
  real_T c1_jb_b;
  real_T c1_nb_y;
  real_T c1_xb_x;
  real_T c1_yb_x;
  real_T c1_ac_x;
  real_T c1_bc_x;
  real_T c1_kb_b;
  real_T c1_ob_y;
  real_T c1_x_a;
  real_T c1_lb_b;
  real_T c1_pb_y;
  real_T c1_cc_x;
  real_T c1_dc_x;
  real_T c1_mb_b;
  real_T c1_qb_y;
  real_T c1_y_a;
  real_T c1_nb_b;
  real_T c1_rb_y;
  real_T c1_ec_x;
  real_T c1_fc_x;
  real_T c1_ab_a;
  real_T c1_ob_b;
  real_T c1_sb_y;
  real_T c1_bb_a;
  real_T c1_pb_b;
  real_T c1_tb_y;
  real_T c1_e_A;
  real_T c1_gc_x;
  real_T c1_hc_x;
  real_T c1_ub_y;
  real_T c1_cb_a;
  real_T c1_qb_b;
  real_T c1_vb_y;
  real_T c1_ic_x;
  real_T c1_jc_x;
  real_T c1_kc_x;
  real_T c1_lc_x;
  real_T c1_rb_b;
  real_T c1_wb_y;
  real_T c1_db_a;
  real_T c1_sb_b;
  real_T c1_xb_y;
  real_T c1_mc_x;
  real_T c1_nc_x;
  real_T c1_tb_b;
  real_T c1_yb_y;
  real_T c1_eb_a;
  real_T c1_ub_b;
  real_T c1_ac_y;
  real_T c1_oc_x;
  real_T c1_pc_x;
  real_T c1_fb_a;
  real_T c1_vb_b;
  real_T c1_bc_y;
  real_T c1_gb_a;
  real_T c1_wb_b;
  real_T c1_cc_y;
  real_T c1_f_A;
  real_T c1_qc_x;
  real_T c1_rc_x;
  real_T c1_dc_y;
  real_T c1_hb_a;
  real_T c1_xb_b;
  real_T c1_ec_y;
  real_T c1_sc_x;
  real_T c1_tc_x;
  real_T c1_yb_b;
  real_T c1_fc_y;
  real_T c1_ib_a;
  real_T c1_ac_b;
  real_T c1_gc_y;
  real_T c1_uc_x;
  real_T c1_vc_x;
  real_T c1_jb_a;
  real_T c1_bc_b;
  real_T c1_hc_y;
  real_T c1_wc_x;
  real_T c1_xc_x;
  real_T c1_cc_b;
  real_T c1_ic_y;
  real_T c1_kb_a;
  real_T c1_dc_b;
  real_T c1_jc_y;
  real_T c1_lb_a;
  real_T c1_ec_b;
  real_T c1_kc_y;
  real_T c1_yc_x;
  real_T c1_ad_x;
  real_T c1_bd_x;
  real_T c1_cd_x;
  real_T c1_fc_b;
  real_T c1_lc_y;
  real_T c1_dd_x;
  real_T c1_ed_x;
  real_T c1_gc_b;
  real_T c1_mc_y;
  real_T c1_mb_a;
  real_T c1_hc_b;
  real_T c1_nc_y;
  real_T c1_g_A;
  real_T c1_fd_x;
  real_T c1_gd_x;
  real_T c1_oc_y;
  real_T c1_nb_a;
  real_T c1_ic_b;
  real_T c1_pc_y;
  real_T c1_hd_x;
  real_T c1_id_x;
  real_T c1_jc_b;
  real_T c1_qc_y;
  real_T c1_ob_a;
  real_T c1_kc_b;
  real_T c1_rc_y;
  real_T c1_jd_x;
  real_T c1_kd_x;
  real_T c1_pb_a;
  real_T c1_lc_b;
  real_T c1_sc_y;
  real_T c1_ld_x;
  real_T c1_md_x;
  real_T c1_mc_b;
  real_T c1_tc_y;
  real_T c1_qb_a;
  real_T c1_nc_b;
  real_T c1_uc_y;
  real_T c1_rb_a;
  real_T c1_oc_b;
  real_T c1_vc_y;
  real_T c1_nd_x;
  real_T c1_od_x;
  real_T c1_pd_x;
  real_T c1_qd_x;
  real_T c1_pc_b;
  real_T c1_wc_y;
  real_T c1_rd_x;
  real_T c1_sd_x;
  real_T c1_qc_b;
  real_T c1_xc_y;
  real_T c1_sb_a;
  real_T c1_rc_b;
  real_T c1_yc_y;
  real_T c1_h_A;
  real_T c1_td_x;
  real_T c1_ud_x;
  real_T c1_ad_y;
  real_T c1_tb_a;
  real_T c1_sc_b;
  real_T c1_bd_y;
  real_T c1_vd_x;
  real_T c1_wd_x;
  real_T c1_ub_a;
  real_T c1_tc_b;
  real_T c1_cd_y;
  real_T c1_vb_a;
  real_T c1_uc_b;
  real_T c1_dd_y;
  real_T c1_xd_x;
  real_T c1_yd_x;
  real_T c1_wb_a;
  real_T c1_vc_b;
  real_T c1_ed_y;
  real_T c1_i_A;
  real_T c1_ae_x;
  real_T c1_be_x;
  real_T c1_fd_y;
  real_T c1_xb_a;
  real_T c1_wc_b;
  real_T c1_gd_y;
  real_T c1_ce_x;
  real_T c1_de_x;
  real_T c1_yb_a;
  real_T c1_xc_b;
  real_T c1_hd_y;
  real_T c1_ac_a;
  real_T c1_yc_b;
  real_T c1_id_y;
  real_T c1_ee_x;
  real_T c1_fe_x;
  real_T c1_bc_a;
  real_T c1_ad_b;
  real_T c1_jd_y;
  real_T c1_j_A;
  real_T c1_ge_x;
  real_T c1_he_x;
  real_T c1_kd_y;
  real_T c1_ie_x;
  real_T c1_je_x;
  real_T c1_cc_a;
  real_T c1_bd_b;
  real_T c1_ld_y;
  real_T c1_dc_a;
  real_T c1_cd_b;
  real_T c1_md_y;
  real_T c1_ec_a;
  real_T c1_dd_b;
  real_T c1_nd_y;
  real_T c1_ke_x;
  real_T c1_le_x;
  real_T c1_fc_a;
  real_T c1_ed_b;
  real_T c1_od_y;
  real_T c1_k_A;
  real_T c1_me_x;
  real_T c1_ne_x;
  real_T c1_pd_y;
  real_T c1_oe_x;
  real_T c1_pe_x;
  real_T c1_gc_a;
  real_T c1_fd_b;
  real_T c1_qd_y;
  real_T c1_hc_a;
  real_T c1_gd_b;
  real_T c1_rd_y;
  real_T c1_qe_x;
  real_T c1_re_x;
  real_T c1_ic_a;
  real_T c1_hd_b;
  real_T c1_sd_y;
  real_T c1_jc_a;
  real_T c1_id_b;
  real_T c1_td_y;
  real_T c1_l_A;
  real_T c1_se_x;
  real_T c1_te_x;
  real_T c1_ud_y;
  real_T c1_ue_x;
  real_T c1_ve_x;
  real_T c1_kc_a;
  real_T c1_jd_b;
  real_T c1_vd_y;
  real_T c1_lc_a;
  real_T c1_kd_b;
  real_T c1_wd_y;
  real_T c1_m_A;
  real_T c1_we_x;
  real_T c1_xe_x;
  real_T c1_xd_y;
  real_T c1_ld_b;
  real_T c1_yd_y;
  real_T c1_ye_x;
  real_T c1_af_x;
  real_T c1_mc_a;
  real_T c1_md_b;
  real_T c1_ae_y;
  real_T c1_nc_a;
  real_T c1_nd_b;
  real_T c1_be_y;
  real_T c1_n_A;
  real_T c1_bf_x;
  real_T c1_cf_x;
  real_T c1_ce_y;
  real_T c1_oc_a;
  real_T c1_od_b;
  real_T c1_de_y;
  real_T c1_df_x;
  real_T c1_ef_x;
  real_T c1_pc_a;
  real_T c1_pd_b;
  real_T c1_ee_y;
  real_T c1_qc_a;
  real_T c1_qd_b;
  real_T c1_fe_y;
  real_T c1_o_A;
  real_T c1_ff_x;
  real_T c1_gf_x;
  real_T c1_ge_y;
  real_T c1_hf_x;
  real_T c1_if_x;
  real_T c1_rc_a;
  real_T c1_rd_b;
  real_T c1_he_y;
  real_T c1_sc_a;
  real_T c1_sd_b;
  real_T c1_ie_y;
  real_T c1_tc_a;
  real_T c1_td_b;
  real_T c1_je_y;
  real_T c1_p_A;
  real_T c1_jf_x;
  real_T c1_kf_x;
  real_T c1_ke_y;
  real_T c1_lf_x;
  real_T c1_mf_x;
  real_T c1_uc_a;
  real_T c1_ud_b;
  real_T c1_le_y;
  real_T c1_vc_a;
  real_T c1_vd_b;
  real_T c1_me_y;
  real_T c1_nf_x;
  real_T c1_of_x;
  real_T c1_wd_b;
  real_T c1_ne_y;
  real_T c1_pf_x;
  real_T c1_qf_x;
  real_T c1_wc_a;
  real_T c1_xd_b;
  real_T c1_oe_y;
  real_T c1_q_A;
  real_T c1_rf_x;
  real_T c1_sf_x;
  real_T c1_pe_y;
  real_T c1_tf_x;
  real_T c1_uf_x;
  real_T c1_xc_a;
  real_T c1_yd_b;
  real_T c1_qe_y;
  real_T c1_yc_a;
  real_T c1_ae_b;
  real_T c1_re_y;
  real_T c1_vf_x;
  real_T c1_wf_x;
  real_T c1_be_b;
  real_T c1_se_y;
  real_T c1_xf_x;
  real_T c1_yf_x;
  real_T c1_ad_a;
  real_T c1_ce_b;
  real_T c1_te_y;
  real_T c1_r_A;
  real_T c1_ag_x;
  real_T c1_bg_x;
  real_T c1_ue_y;
  real_T c1_bd_a;
  real_T c1_de_b;
  real_T c1_ve_y;
  real_T c1_cg_x;
  real_T c1_dg_x;
  real_T c1_eg_x;
  real_T c1_fg_x;
  real_T c1_ee_b;
  real_T c1_we_y;
  real_T c1_cd_a;
  real_T c1_fe_b;
  real_T c1_xe_y;
  real_T c1_gg_x;
  real_T c1_hg_x;
  real_T c1_ig_x;
  real_T c1_jg_x;
  real_T c1_ge_b;
  real_T c1_ye_y;
  real_T c1_kg_x;
  real_T c1_lg_x;
  real_T c1_he_b;
  real_T c1_af_y;
  real_T c1_dd_a;
  real_T c1_ie_b;
  real_T c1_bf_y;
  real_T c1_s_A;
  real_T c1_mg_x;
  real_T c1_ng_x;
  real_T c1_cf_y;
  real_T c1_ed_a;
  real_T c1_je_b;
  real_T c1_df_y;
  real_T c1_og_x;
  real_T c1_pg_x;
  real_T c1_qg_x;
  real_T c1_rg_x;
  real_T c1_ke_b;
  real_T c1_ef_y;
  real_T c1_fd_a;
  real_T c1_le_b;
  real_T c1_ff_y;
  real_T c1_sg_x;
  real_T c1_tg_x;
  real_T c1_ug_x;
  real_T c1_vg_x;
  real_T c1_me_b;
  real_T c1_gf_y;
  real_T c1_wg_x;
  real_T c1_xg_x;
  real_T c1_ne_b;
  real_T c1_hf_y;
  real_T c1_gd_a;
  real_T c1_oe_b;
  real_T c1_if_y;
  real_T c1_t_A;
  real_T c1_yg_x;
  real_T c1_ah_x;
  real_T c1_jf_y;
  real_T c1_hd_a;
  real_T c1_pe_b;
  real_T c1_kf_y;
  real_T c1_bh_x;
  real_T c1_ch_x;
  real_T c1_id_a;
  real_T c1_qe_b;
  real_T c1_lf_y;
  real_T c1_jd_a;
  real_T c1_re_b;
  real_T c1_mf_y;
  real_T c1_u_A;
  real_T c1_dh_x;
  real_T c1_eh_x;
  real_T c1_nf_y;
  real_T c1_kd_a;
  real_T c1_se_b;
  real_T c1_of_y;
  real_T c1_fh_x;
  real_T c1_gh_x;
  real_T c1_hh_x;
  real_T c1_ih_x;
  real_T c1_te_b;
  real_T c1_pf_y;
  real_T c1_ld_a;
  real_T c1_ue_b;
  real_T c1_qf_y;
  real_T c1_jh_x;
  real_T c1_kh_x;
  real_T c1_ve_b;
  real_T c1_rf_y;
  real_T c1_lh_x;
  real_T c1_mh_x;
  real_T c1_nh_x;
  real_T c1_oh_x;
  real_T c1_we_b;
  real_T c1_sf_y;
  real_T c1_md_a;
  real_T c1_xe_b;
  real_T c1_tf_y;
  real_T c1_v_A;
  real_T c1_ph_x;
  real_T c1_qh_x;
  real_T c1_uf_y;
  real_T c1_nd_a;
  real_T c1_ye_b;
  real_T c1_vf_y;
  real_T c1_rh_x;
  real_T c1_sh_x;
  real_T c1_th_x;
  real_T c1_uh_x;
  real_T c1_af_b;
  real_T c1_wf_y;
  real_T c1_od_a;
  real_T c1_bf_b;
  real_T c1_xf_y;
  real_T c1_vh_x;
  real_T c1_wh_x;
  real_T c1_cf_b;
  real_T c1_yf_y;
  real_T c1_xh_x;
  real_T c1_yh_x;
  real_T c1_ai_x;
  real_T c1_bi_x;
  real_T c1_df_b;
  real_T c1_ag_y;
  real_T c1_pd_a;
  real_T c1_ef_b;
  real_T c1_bg_y;
  real_T c1_w_A;
  real_T c1_ci_x;
  real_T c1_di_x;
  real_T c1_cg_y;
  real_T c1_ei_x;
  real_T c1_fi_x;
  real_T c1_qd_a;
  real_T c1_ff_b;
  real_T c1_dg_y;
  real_T c1_rd_a;
  real_T c1_gf_b;
  real_T c1_eg_y;
  real_T c1_gi_x;
  real_T c1_hi_x;
  real_T c1_ii_x;
  real_T c1_ji_x;
  real_T c1_hf_b;
  real_T c1_fg_y;
  real_T c1_sd_a;
  real_T c1_if_b;
  real_T c1_gg_y;
  real_T c1_x_A;
  real_T c1_ki_x;
  real_T c1_li_x;
  real_T c1_hg_y;
  real_T c1_jf_b;
  real_T c1_ig_y;
  real_T c1_mi_x;
  real_T c1_ni_x;
  real_T c1_td_a;
  real_T c1_kf_b;
  real_T c1_jg_y;
  real_T c1_ud_a;
  real_T c1_lf_b;
  real_T c1_kg_y;
  real_T c1_vd_a;
  real_T c1_mf_b;
  real_T c1_lg_y;
  real_T c1_y_A;
  real_T c1_oi_x;
  real_T c1_pi_x;
  real_T c1_mg_y;
  real_T c1_qi_x;
  real_T c1_ri_x;
  real_T c1_wd_a;
  real_T c1_nf_b;
  real_T c1_ng_y;
  real_T c1_xd_a;
  real_T c1_of_b;
  real_T c1_og_y;
  real_T c1_si_x;
  real_T c1_ti_x;
  real_T c1_ui_x;
  real_T c1_vi_x;
  real_T c1_pf_b;
  real_T c1_pg_y;
  real_T c1_yd_a;
  real_T c1_qf_b;
  real_T c1_qg_y;
  real_T c1_ab_A;
  real_T c1_wi_x;
  real_T c1_xi_x;
  real_T c1_rg_y;
  real_T c1_rf_b;
  real_T c1_sg_y;
  real_T c1_yi_x;
  real_T c1_aj_x;
  real_T c1_ae_a;
  real_T c1_sf_b;
  real_T c1_tg_y;
  real_T c1_be_a;
  real_T c1_tf_b;
  real_T c1_ug_y;
  real_T c1_ce_a;
  real_T c1_uf_b;
  real_T c1_vg_y;
  real_T c1_bb_A;
  real_T c1_bj_x;
  real_T c1_cj_x;
  real_T c1_wg_y;
  real_T c1_dj_x;
  real_T c1_ej_x;
  real_T c1_de_a;
  real_T c1_vf_b;
  real_T c1_xg_y;
  real_T c1_ee_a;
  real_T c1_wf_b;
  real_T c1_yg_y;
  real_T c1_fe_a;
  real_T c1_xf_b;
  real_T c1_ah_y;
  real_T c1_cb_A;
  real_T c1_fj_x;
  real_T c1_gj_x;
  real_T c1_bh_y;
  real_T c1_hj_x;
  real_T c1_ij_x;
  real_T c1_ge_a;
  real_T c1_yf_b;
  real_T c1_ch_y;
  real_T c1_he_a;
  real_T c1_ag_b;
  real_T c1_dh_y;
  real_T c1_db_A;
  real_T c1_jj_x;
  real_T c1_kj_x;
  real_T c1_eh_y;
  real_T c1_ie_a;
  real_T c1_bg_b;
  real_T c1_fh_y;
  real_T c1_lj_x;
  real_T c1_mj_x;
  real_T c1_cg_b;
  real_T c1_gh_y;
  real_T c1_nj_x;
  real_T c1_oj_x;
  real_T c1_dg_b;
  real_T c1_hh_y;
  real_T c1_je_a;
  real_T c1_eg_b;
  real_T c1_ih_y;
  real_T c1_eb_A;
  real_T c1_pj_x;
  real_T c1_qj_x;
  real_T c1_jh_y;
  real_T c1_ke_a;
  real_T c1_fg_b;
  real_T c1_kh_y;
  real_T c1_rj_x;
  real_T c1_sj_x;
  real_T c1_gg_b;
  real_T c1_lh_y;
  real_T c1_le_a;
  real_T c1_hg_b;
  real_T c1_mh_y;
  real_T c1_tj_x;
  real_T c1_uj_x;
  real_T c1_ig_b;
  real_T c1_nh_y;
  real_T c1_me_a;
  real_T c1_jg_b;
  real_T c1_oh_y;
  real_T c1_vj_x;
  real_T c1_wj_x;
  real_T c1_ne_a;
  real_T c1_kg_b;
  real_T c1_ph_y;
  real_T c1_oe_a;
  real_T c1_lg_b;
  real_T c1_qh_y;
  real_T c1_fb_A;
  real_T c1_xj_x;
  real_T c1_yj_x;
  real_T c1_rh_y;
  real_T c1_pe_a;
  real_T c1_mg_b;
  real_T c1_sh_y;
  real_T c1_ak_x;
  real_T c1_bk_x;
  real_T c1_qe_a;
  real_T c1_ng_b;
  real_T c1_th_y;
  real_T c1_gb_A;
  real_T c1_ck_x;
  real_T c1_dk_x;
  real_T c1_uh_y;
  real_T c1_re_a;
  real_T c1_og_b;
  real_T c1_vh_y;
  real_T c1_ek_x;
  real_T c1_fk_x;
  real_T c1_se_a;
  real_T c1_pg_b;
  real_T c1_wh_y;
  real_T c1_hb_A;
  real_T c1_gk_x;
  real_T c1_hk_x;
  real_T c1_xh_y;
  real_T c1_ik_x;
  real_T c1_jk_x;
  real_T c1_te_a;
  real_T c1_qg_b;
  real_T c1_yh_y;
  real_T c1_ue_a;
  real_T c1_rg_b;
  real_T c1_ai_y;
  real_T c1_kk_x;
  real_T c1_lk_x;
  real_T c1_mk_x;
  real_T c1_nk_x;
  real_T c1_sg_b;
  real_T c1_bi_y;
  real_T c1_ok_x;
  real_T c1_pk_x;
  real_T c1_tg_b;
  real_T c1_ci_y;
  real_T c1_ve_a;
  real_T c1_ug_b;
  real_T c1_di_y;
  real_T c1_ib_A;
  real_T c1_qk_x;
  real_T c1_rk_x;
  real_T c1_ei_y;
  real_T c1_sk_x;
  real_T c1_tk_x;
  real_T c1_we_a;
  real_T c1_vg_b;
  real_T c1_fi_y;
  real_T c1_xe_a;
  real_T c1_wg_b;
  real_T c1_gi_y;
  real_T c1_uk_x;
  real_T c1_vk_x;
  real_T c1_xg_b;
  real_T c1_hi_y;
  real_T c1_wk_x;
  real_T c1_xk_x;
  real_T c1_yk_x;
  real_T c1_al_x;
  real_T c1_yg_b;
  real_T c1_ii_y;
  real_T c1_ye_a;
  real_T c1_ah_b;
  real_T c1_ji_y;
  real_T c1_jb_A;
  real_T c1_bl_x;
  real_T c1_cl_x;
  real_T c1_ki_y;
  real_T c1_dl_x;
  real_T c1_el_x;
  real_T c1_af_a;
  real_T c1_bh_b;
  real_T c1_li_y;
  real_T c1_bf_a;
  real_T c1_ch_b;
  real_T c1_mi_y;
  real_T c1_fl_x;
  real_T c1_gl_x;
  real_T c1_dh_b;
  real_T c1_ni_y;
  real_T c1_hl_x;
  real_T c1_il_x;
  real_T c1_jl_x;
  real_T c1_kl_x;
  real_T c1_eh_b;
  real_T c1_oi_y;
  real_T c1_cf_a;
  real_T c1_fh_b;
  real_T c1_pi_y;
  real_T c1_kb_A;
  real_T c1_ll_x;
  real_T c1_ml_x;
  real_T c1_qi_y;
  real_T c1_nl_x;
  real_T c1_ol_x;
  real_T c1_df_a;
  real_T c1_gh_b;
  real_T c1_ri_y;
  real_T c1_ef_a;
  real_T c1_hh_b;
  real_T c1_si_y;
  real_T c1_pl_x;
  real_T c1_ql_x;
  real_T c1_rl_x;
  real_T c1_sl_x;
  real_T c1_ih_b;
  real_T c1_ti_y;
  real_T c1_tl_x;
  real_T c1_ul_x;
  real_T c1_jh_b;
  real_T c1_ui_y;
  real_T c1_ff_a;
  real_T c1_kh_b;
  real_T c1_vi_y;
  real_T c1_lb_A;
  real_T c1_vl_x;
  real_T c1_wl_x;
  real_T c1_wi_y;
  real_T c1_xl_x;
  real_T c1_yl_x;
  real_T c1_gf_a;
  real_T c1_lh_b;
  real_T c1_xi_y;
  real_T c1_hf_a;
  real_T c1_mh_b;
  real_T c1_yi_y;
  real_T c1_mb_A;
  real_T c1_am_x;
  real_T c1_bm_x;
  real_T c1_aj_y;
  real_T c1_nh_b;
  real_T c1_bj_y;
  real_T c1_cm_x;
  real_T c1_dm_x;
  real_T c1_if_a;
  real_T c1_oh_b;
  real_T c1_cj_y;
  real_T c1_jf_a;
  real_T c1_ph_b;
  real_T c1_dj_y;
  real_T c1_nb_A;
  real_T c1_em_x;
  real_T c1_fm_x;
  real_T c1_ej_y;
  real_T c1_kf_a;
  real_T c1_qh_b;
  real_T c1_fj_y;
  real_T c1_gm_x;
  real_T c1_hm_x;
  real_T c1_im_x;
  real_T c1_jm_x;
  real_T c1_rh_b;
  real_T c1_gj_y;
  real_T c1_lf_a;
  real_T c1_sh_b;
  real_T c1_hj_y;
  real_T c1_km_x;
  real_T c1_lm_x;
  real_T c1_mf_a;
  real_T c1_th_b;
  real_T c1_ij_y;
  real_T c1_mm_x;
  real_T c1_nm_x;
  real_T c1_uh_b;
  real_T c1_jj_y;
  real_T c1_nf_a;
  real_T c1_vh_b;
  real_T c1_kj_y;
  real_T c1_wh_b;
  real_T c1_lj_y;
  real_T c1_om_x;
  real_T c1_pm_x;
  real_T c1_of_a;
  real_T c1_xh_b;
  real_T c1_mj_y;
  real_T c1_pf_a;
  real_T c1_yh_b;
  real_T c1_nj_y;
  real_T c1_ob_A;
  real_T c1_qm_x;
  real_T c1_rm_x;
  real_T c1_oj_y;
  real_T c1_sm_x;
  real_T c1_tm_x;
  real_T c1_qf_a;
  real_T c1_ai_b;
  real_T c1_pj_y;
  real_T c1_rf_a;
  real_T c1_bi_b;
  real_T c1_qj_y;
  real_T c1_um_x;
  real_T c1_vm_x;
  real_T c1_ci_b;
  real_T c1_rj_y;
  real_T c1_wm_x;
  real_T c1_xm_x;
  real_T c1_sf_a;
  real_T c1_di_b;
  real_T c1_sj_y;
  real_T c1_pb_A;
  real_T c1_ym_x;
  real_T c1_an_x;
  real_T c1_tj_y;
  real_T c1_bn_x;
  real_T c1_cn_x;
  real_T c1_tf_a;
  real_T c1_ei_b;
  real_T c1_uj_y;
  real_T c1_uf_a;
  real_T c1_fi_b;
  real_T c1_vj_y;
  real_T c1_dn_x;
  real_T c1_en_x;
  real_T c1_gi_b;
  real_T c1_wj_y;
  real_T c1_fn_x;
  real_T c1_gn_x;
  real_T c1_vf_a;
  real_T c1_hi_b;
  real_T c1_xj_y;
  real_T c1_qb_A;
  real_T c1_hn_x;
  real_T c1_in_x;
  real_T c1_yj_y;
  real_T c1_wf_a;
  real_T c1_ii_b;
  real_T c1_ak_y;
  real_T c1_jn_x;
  real_T c1_kn_x;
  real_T c1_ln_x;
  real_T c1_mn_x;
  real_T c1_ji_b;
  real_T c1_bk_y;
  real_T c1_xf_a;
  real_T c1_ki_b;
  real_T c1_ck_y;
  real_T c1_nn_x;
  real_T c1_on_x;
  real_T c1_pn_x;
  real_T c1_qn_x;
  real_T c1_li_b;
  real_T c1_dk_y;
  real_T c1_rn_x;
  real_T c1_sn_x;
  real_T c1_mi_b;
  real_T c1_ek_y;
  real_T c1_yf_a;
  real_T c1_ni_b;
  real_T c1_fk_y;
  real_T c1_rb_A;
  real_T c1_tn_x;
  real_T c1_un_x;
  real_T c1_gk_y;
  real_T c1_ag_a;
  real_T c1_oi_b;
  real_T c1_hk_y;
  real_T c1_vn_x;
  real_T c1_wn_x;
  real_T c1_xn_x;
  real_T c1_yn_x;
  real_T c1_pi_b;
  real_T c1_ik_y;
  real_T c1_bg_a;
  real_T c1_qi_b;
  real_T c1_jk_y;
  real_T c1_ao_x;
  real_T c1_bo_x;
  real_T c1_co_x;
  real_T c1_do_x;
  real_T c1_ri_b;
  real_T c1_kk_y;
  real_T c1_eo_x;
  real_T c1_fo_x;
  real_T c1_si_b;
  real_T c1_lk_y;
  real_T c1_cg_a;
  real_T c1_ti_b;
  real_T c1_mk_y;
  real_T c1_sb_A;
  real_T c1_go_x;
  real_T c1_ho_x;
  real_T c1_nk_y;
  real_T c1_dg_a;
  real_T c1_ui_b;
  real_T c1_ok_y;
  real_T c1_io_x;
  real_T c1_jo_x;
  real_T c1_eg_a;
  real_T c1_vi_b;
  real_T c1_pk_y;
  real_T c1_ko_x;
  real_T c1_lo_x;
  real_T c1_wi_b;
  real_T c1_qk_y;
  real_T c1_fg_a;
  real_T c1_xi_b;
  real_T c1_rk_y;
  real_T c1_gg_a;
  real_T c1_yi_b;
  real_T c1_sk_y;
  real_T c1_mo_x;
  real_T c1_no_x;
  real_T c1_oo_x;
  real_T c1_po_x;
  real_T c1_aj_b;
  real_T c1_tk_y;
  real_T c1_qo_x;
  real_T c1_ro_x;
  real_T c1_bj_b;
  real_T c1_uk_y;
  real_T c1_hg_a;
  real_T c1_cj_b;
  real_T c1_vk_y;
  real_T c1_tb_A;
  real_T c1_so_x;
  real_T c1_to_x;
  real_T c1_wk_y;
  real_T c1_ig_a;
  real_T c1_dj_b;
  real_T c1_xk_y;
  real_T c1_uo_x;
  real_T c1_vo_x;
  real_T c1_jg_a;
  real_T c1_ej_b;
  real_T c1_yk_y;
  real_T c1_wo_x;
  real_T c1_xo_x;
  real_T c1_fj_b;
  real_T c1_al_y;
  real_T c1_kg_a;
  real_T c1_gj_b;
  real_T c1_bl_y;
  real_T c1_lg_a;
  real_T c1_hj_b;
  real_T c1_cl_y;
  real_T c1_yo_x;
  real_T c1_ap_x;
  real_T c1_bp_x;
  real_T c1_cp_x;
  real_T c1_ij_b;
  real_T c1_dl_y;
  real_T c1_dp_x;
  real_T c1_ep_x;
  real_T c1_jj_b;
  real_T c1_el_y;
  real_T c1_mg_a;
  real_T c1_kj_b;
  real_T c1_fl_y;
  real_T c1_ub_A;
  real_T c1_fp_x;
  real_T c1_gp_x;
  real_T c1_gl_y;
  real_T c1_ng_a;
  real_T c1_lj_b;
  real_T c1_hl_y;
  real_T c1_hp_x;
  real_T c1_ip_x;
  real_T c1_jp_x;
  real_T c1_kp_x;
  real_T c1_mj_b;
  real_T c1_il_y;
  real_T c1_og_a;
  real_T c1_nj_b;
  real_T c1_jl_y;
  real_T c1_lp_x;
  real_T c1_mp_x;
  real_T c1_oj_b;
  real_T c1_kl_y;
  real_T c1_np_x;
  real_T c1_op_x;
  real_T c1_pp_x;
  real_T c1_qp_x;
  real_T c1_pj_b;
  real_T c1_ll_y;
  real_T c1_pg_a;
  real_T c1_qj_b;
  real_T c1_ml_y;
  real_T c1_vb_A;
  real_T c1_rp_x;
  real_T c1_sp_x;
  real_T c1_nl_y;
  real_T c1_qg_a;
  real_T c1_rj_b;
  real_T c1_ol_y;
  real_T c1_tp_x;
  real_T c1_up_x;
  real_T c1_vp_x;
  real_T c1_wp_x;
  real_T c1_sj_b;
  real_T c1_pl_y;
  real_T c1_rg_a;
  real_T c1_tj_b;
  real_T c1_ql_y;
  real_T c1_xp_x;
  real_T c1_yp_x;
  real_T c1_uj_b;
  real_T c1_rl_y;
  real_T c1_aq_x;
  real_T c1_bq_x;
  real_T c1_cq_x;
  real_T c1_dq_x;
  real_T c1_vj_b;
  real_T c1_sl_y;
  real_T c1_sg_a;
  real_T c1_wj_b;
  real_T c1_tl_y;
  real_T c1_wb_A;
  real_T c1_eq_x;
  real_T c1_fq_x;
  real_T c1_ul_y;
  real_T c1_gq_x;
  real_T c1_hq_x;
  real_T c1_tg_a;
  real_T c1_xj_b;
  real_T c1_vl_y;
  real_T c1_ug_a;
  real_T c1_yj_b;
  real_T c1_wl_y;
  real_T c1_iq_x;
  real_T c1_jq_x;
  real_T c1_kq_x;
  real_T c1_lq_x;
  real_T c1_ak_b;
  real_T c1_xl_y;
  real_T c1_vg_a;
  real_T c1_bk_b;
  real_T c1_yl_y;
  real_T c1_xb_A;
  real_T c1_mq_x;
  real_T c1_nq_x;
  real_T c1_am_y;
  real_T c1_oq_x;
  real_T c1_pq_x;
  real_T c1_wg_a;
  real_T c1_ck_b;
  real_T c1_bm_y;
  real_T c1_xg_a;
  real_T c1_dk_b;
  real_T c1_cm_y;
  real_T c1_qq_x;
  real_T c1_rq_x;
  real_T c1_sq_x;
  real_T c1_tq_x;
  real_T c1_ek_b;
  real_T c1_dm_y;
  real_T c1_yg_a;
  real_T c1_fk_b;
  real_T c1_em_y;
  real_T c1_yb_A;
  real_T c1_uq_x;
  real_T c1_vq_x;
  real_T c1_fm_y;
  real_T c1_wq_x;
  real_T c1_xq_x;
  real_T c1_ah_a;
  real_T c1_gk_b;
  real_T c1_gm_y;
  real_T c1_bh_a;
  real_T c1_hk_b;
  real_T c1_hm_y;
  real_T c1_yq_x;
  real_T c1_ar_x;
  real_T c1_ch_a;
  real_T c1_ik_b;
  real_T c1_im_y;
  real_T c1_jk_b;
  real_T c1_jm_y;
  real_T c1_br_x;
  real_T c1_cr_x;
  real_T c1_dh_a;
  real_T c1_kk_b;
  real_T c1_km_y;
  real_T c1_eh_a;
  real_T c1_lk_b;
  real_T c1_lm_y;
  real_T c1_ac_A;
  real_T c1_dr_x;
  real_T c1_er_x;
  real_T c1_mm_y;
  real_T c1_fr_x;
  real_T c1_gr_x;
  real_T c1_fh_a;
  real_T c1_mk_b;
  real_T c1_nm_y;
  real_T c1_gh_a;
  real_T c1_nk_b;
  real_T c1_om_y;
  real_T c1_hr_x;
  real_T c1_ir_x;
  real_T c1_hh_a;
  real_T c1_ok_b;
  real_T c1_pm_y;
  real_T c1_pk_b;
  real_T c1_qm_y;
  real_T c1_jr_x;
  real_T c1_kr_x;
  real_T c1_ih_a;
  real_T c1_qk_b;
  real_T c1_rm_y;
  real_T c1_jh_a;
  real_T c1_rk_b;
  real_T c1_sm_y;
  real_T c1_bc_A;
  real_T c1_lr_x;
  real_T c1_mr_x;
  real_T c1_tm_y;
  real_T c1_kh_a;
  real_T c1_sk_b;
  real_T c1_um_y;
  real_T c1_nr_x;
  real_T c1_or_x;
  real_T c1_pr_x;
  real_T c1_qr_x;
  real_T c1_tk_b;
  real_T c1_vm_y;
  real_T c1_lh_a;
  real_T c1_uk_b;
  real_T c1_wm_y;
  real_T c1_rr_x;
  real_T c1_sr_x;
  real_T c1_mh_a;
  real_T c1_vk_b;
  real_T c1_xm_y;
  real_T c1_tr_x;
  real_T c1_ur_x;
  real_T c1_wk_b;
  real_T c1_ym_y;
  real_T c1_nh_a;
  real_T c1_xk_b;
  real_T c1_an_y;
  real_T c1_yk_b;
  real_T c1_bn_y;
  real_T c1_vr_x;
  real_T c1_wr_x;
  real_T c1_oh_a;
  real_T c1_al_b;
  real_T c1_cn_y;
  real_T c1_ph_a;
  real_T c1_bl_b;
  real_T c1_dn_y;
  real_T c1_cc_A;
  real_T c1_xr_x;
  real_T c1_yr_x;
  real_T c1_en_y;
  real_T c1_as_x;
  real_T c1_bs_x;
  real_T c1_qh_a;
  real_T c1_cl_b;
  real_T c1_fn_y;
  real_T c1_rh_a;
  real_T c1_dl_b;
  real_T c1_gn_y;
  real_T c1_sh_a;
  real_T c1_el_b;
  real_T c1_hn_y;
  real_T c1_cs_x;
  real_T c1_ds_x;
  real_T c1_es_x;
  real_T c1_fs_x;
  real_T c1_fl_b;
  real_T c1_in_y;
  real_T c1_th_a;
  real_T c1_gl_b;
  real_T c1_jn_y;
  real_T c1_dc_A;
  real_T c1_gs_x;
  real_T c1_hs_x;
  real_T c1_kn_y;
  real_T c1_is_x;
  real_T c1_js_x;
  real_T c1_uh_a;
  real_T c1_hl_b;
  real_T c1_ln_y;
  real_T c1_vh_a;
  real_T c1_il_b;
  real_T c1_mn_y;
  real_T c1_wh_a;
  real_T c1_jl_b;
  real_T c1_nn_y;
  real_T c1_ks_x;
  real_T c1_ls_x;
  real_T c1_ms_x;
  real_T c1_ns_x;
  real_T c1_kl_b;
  real_T c1_on_y;
  real_T c1_xh_a;
  real_T c1_ll_b;
  real_T c1_pn_y;
  real_T c1_ec_A;
  real_T c1_os_x;
  real_T c1_ps_x;
  real_T c1_qn_y;
  real_T c1_qs_x;
  real_T c1_rs_x;
  real_T c1_yh_a;
  real_T c1_ml_b;
  real_T c1_rn_y;
  real_T c1_ss_x;
  real_T c1_ts_x;
  real_T c1_ai_a;
  real_T c1_nl_b;
  real_T c1_sn_y;
  real_T c1_bi_a;
  real_T c1_ol_b;
  real_T c1_tn_y;
  real_T c1_fc_A;
  real_T c1_us_x;
  real_T c1_vs_x;
  real_T c1_un_y;
  real_T c1_ws_x;
  real_T c1_xs_x;
  real_T c1_ci_a;
  real_T c1_pl_b;
  real_T c1_vn_y;
  real_T c1_ys_x;
  real_T c1_at_x;
  real_T c1_di_a;
  real_T c1_ql_b;
  real_T c1_wn_y;
  real_T c1_ei_a;
  real_T c1_rl_b;
  real_T c1_xn_y;
  real_T c1_gc_A;
  real_T c1_bt_x;
  real_T c1_ct_x;
  real_T c1_yn_y;
  real_T c1_fi_a;
  real_T c1_sl_b;
  real_T c1_ao_y;
  real_T c1_dt_x;
  real_T c1_et_x;
  real_T c1_ft_x;
  real_T c1_gt_x;
  real_T c1_tl_b;
  real_T c1_bo_y;
  real_T c1_gi_a;
  real_T c1_ul_b;
  real_T c1_co_y;
  real_T c1_ht_x;
  real_T c1_it_x;
  real_T c1_jt_x;
  real_T c1_kt_x;
  real_T c1_vl_b;
  real_T c1_do_y;
  real_T c1_lt_x;
  real_T c1_mt_x;
  real_T c1_wl_b;
  real_T c1_eo_y;
  real_T c1_hi_a;
  real_T c1_xl_b;
  real_T c1_fo_y;
  real_T c1_hc_A;
  real_T c1_nt_x;
  real_T c1_ot_x;
  real_T c1_go_y;
  real_T c1_ii_a;
  real_T c1_yl_b;
  real_T c1_ho_y;
  real_T c1_pt_x;
  real_T c1_qt_x;
  real_T c1_rt_x;
  real_T c1_st_x;
  real_T c1_am_b;
  real_T c1_io_y;
  real_T c1_ji_a;
  real_T c1_bm_b;
  real_T c1_jo_y;
  real_T c1_tt_x;
  real_T c1_ut_x;
  real_T c1_vt_x;
  real_T c1_wt_x;
  real_T c1_cm_b;
  real_T c1_ko_y;
  real_T c1_xt_x;
  real_T c1_yt_x;
  real_T c1_dm_b;
  real_T c1_lo_y;
  real_T c1_ki_a;
  real_T c1_em_b;
  real_T c1_mo_y;
  real_T c1_ic_A;
  real_T c1_au_x;
  real_T c1_bu_x;
  real_T c1_no_y;
  real_T c1_li_a;
  real_T c1_fm_b;
  real_T c1_oo_y;
  real_T c1_cu_x;
  real_T c1_du_x;
  real_T c1_eu_x;
  real_T c1_fu_x;
  real_T c1_gm_b;
  real_T c1_po_y;
  real_T c1_mi_a;
  real_T c1_hm_b;
  real_T c1_qo_y;
  real_T c1_gu_x;
  real_T c1_hu_x;
  real_T c1_ni_a;
  real_T c1_im_b;
  real_T c1_ro_y;
  real_T c1_iu_x;
  real_T c1_ju_x;
  real_T c1_jm_b;
  real_T c1_so_y;
  real_T c1_oi_a;
  real_T c1_km_b;
  real_T c1_to_y;
  real_T c1_pi_a;
  real_T c1_lm_b;
  real_T c1_uo_y;
  real_T c1_jc_A;
  real_T c1_ku_x;
  real_T c1_lu_x;
  real_T c1_vo_y;
  real_T c1_qi_a;
  real_T c1_mm_b;
  real_T c1_wo_y;
  real_T c1_mu_x;
  real_T c1_nu_x;
  real_T c1_ou_x;
  real_T c1_pu_x;
  real_T c1_nm_b;
  real_T c1_xo_y;
  real_T c1_ri_a;
  real_T c1_om_b;
  real_T c1_yo_y;
  real_T c1_qu_x;
  real_T c1_ru_x;
  real_T c1_si_a;
  real_T c1_pm_b;
  real_T c1_ap_y;
  real_T c1_su_x;
  real_T c1_tu_x;
  real_T c1_qm_b;
  real_T c1_bp_y;
  real_T c1_ti_a;
  real_T c1_rm_b;
  real_T c1_cp_y;
  real_T c1_ui_a;
  real_T c1_sm_b;
  real_T c1_dp_y;
  real_T c1_kc_A;
  real_T c1_uu_x;
  real_T c1_vu_x;
  real_T c1_ep_y;
  real_T c1_vi_a;
  real_T c1_tm_b;
  real_T c1_fp_y;
  real_T c1_wu_x;
  real_T c1_xu_x;
  real_T c1_yu_x;
  real_T c1_av_x;
  real_T c1_um_b;
  real_T c1_gp_y;
  real_T c1_wi_a;
  real_T c1_vm_b;
  real_T c1_hp_y;
  real_T c1_bv_x;
  real_T c1_cv_x;
  real_T c1_xi_a;
  real_T c1_wm_b;
  real_T c1_ip_y;
  real_T c1_dv_x;
  real_T c1_ev_x;
  real_T c1_xm_b;
  real_T c1_jp_y;
  real_T c1_yi_a;
  real_T c1_ym_b;
  real_T c1_kp_y;
  real_T c1_aj_a;
  real_T c1_an_b;
  real_T c1_lp_y;
  real_T c1_lc_A;
  real_T c1_fv_x;
  real_T c1_gv_x;
  real_T c1_mp_y;
  real_T c1_bj_a;
  real_T c1_bn_b;
  real_T c1_np_y;
  real_T c1_hv_x;
  real_T c1_iv_x;
  real_T c1_jv_x;
  real_T c1_kv_x;
  real_T c1_cn_b;
  real_T c1_op_y;
  real_T c1_cj_a;
  real_T c1_dn_b;
  real_T c1_pp_y;
  real_T c1_lv_x;
  real_T c1_mv_x;
  real_T c1_dj_a;
  real_T c1_en_b;
  real_T c1_qp_y;
  real_T c1_nv_x;
  real_T c1_ov_x;
  real_T c1_fn_b;
  real_T c1_rp_y;
  real_T c1_ej_a;
  real_T c1_gn_b;
  real_T c1_sp_y;
  real_T c1_fj_a;
  real_T c1_hn_b;
  real_T c1_tp_y;
  real_T c1_mc_A;
  real_T c1_pv_x;
  real_T c1_qv_x;
  real_T c1_up_y;
  real_T c1_rv_x;
  real_T c1_sv_x;
  real_T c1_gj_a;
  real_T c1_in_b;
  real_T c1_vp_y;
  real_T c1_hj_a;
  real_T c1_jn_b;
  real_T c1_wp_y;
  real_T c1_tv_x;
  real_T c1_uv_x;
  real_T c1_vv_x;
  real_T c1_wv_x;
  real_T c1_kn_b;
  real_T c1_xp_y;
  real_T c1_ij_a;
  real_T c1_ln_b;
  real_T c1_yp_y;
  real_T c1_nc_A;
  real_T c1_xv_x;
  real_T c1_yv_x;
  real_T c1_aq_y;
  real_T c1_aw_x;
  real_T c1_bw_x;
  real_T c1_jj_a;
  real_T c1_mn_b;
  real_T c1_bq_y;
  real_T c1_kj_a;
  real_T c1_nn_b;
  real_T c1_cq_y;
  real_T c1_cw_x;
  real_T c1_dw_x;
  real_T c1_ew_x;
  real_T c1_fw_x;
  real_T c1_on_b;
  real_T c1_dq_y;
  real_T c1_lj_a;
  real_T c1_pn_b;
  real_T c1_eq_y;
  real_T c1_oc_A;
  real_T c1_gw_x;
  real_T c1_hw_x;
  real_T c1_fq_y;
  real_T c1_mj_a;
  real_T c1_qn_b;
  real_T c1_gq_y;
  real_T c1_iw_x;
  real_T c1_jw_x;
  real_T c1_kw_x;
  real_T c1_lw_x;
  real_T c1_rn_b;
  real_T c1_hq_y;
  real_T c1_nj_a;
  real_T c1_sn_b;
  real_T c1_iq_y;
  real_T c1_mw_x;
  real_T c1_nw_x;
  real_T c1_ow_x;
  real_T c1_pw_x;
  real_T c1_tn_b;
  real_T c1_jq_y;
  real_T c1_oj_a;
  real_T c1_un_b;
  real_T c1_kq_y;
  real_T c1_pc_A;
  real_T c1_qw_x;
  real_T c1_rw_x;
  real_T c1_lq_y;
  real_T c1_pj_a;
  real_T c1_vn_b;
  real_T c1_mq_y;
  real_T c1_sw_x;
  real_T c1_tw_x;
  real_T c1_uw_x;
  real_T c1_vw_x;
  real_T c1_wn_b;
  real_T c1_nq_y;
  real_T c1_qj_a;
  real_T c1_xn_b;
  real_T c1_oq_y;
  real_T c1_ww_x;
  real_T c1_xw_x;
  real_T c1_yw_x;
  real_T c1_ax_x;
  real_T c1_yn_b;
  real_T c1_pq_y;
  real_T c1_rj_a;
  real_T c1_ao_b;
  real_T c1_qq_y;
  real_T c1_qc_A;
  real_T c1_bx_x;
  real_T c1_cx_x;
  real_T c1_rq_y;
  real_T c1_dx_x;
  real_T c1_ex_x;
  real_T c1_sj_a;
  real_T c1_bo_b;
  real_T c1_sq_y;
  real_T c1_fx_x;
  real_T c1_gx_x;
  real_T c1_tj_a;
  real_T c1_co_b;
  real_T c1_tq_y;
  real_T c1_uj_a;
  real_T c1_do_b;
  real_T c1_uq_y;
  real_T c1_vj_a;
  real_T c1_eo_b;
  real_T c1_vq_y;
  real_T c1_rc_A;
  real_T c1_hx_x;
  real_T c1_ix_x;
  real_T c1_wq_y;
  real_T c1_jx_x;
  real_T c1_kx_x;
  real_T c1_wj_a;
  real_T c1_fo_b;
  real_T c1_xq_y;
  real_T c1_lx_x;
  real_T c1_mx_x;
  real_T c1_xj_a;
  real_T c1_go_b;
  real_T c1_yq_y;
  real_T c1_yj_a;
  real_T c1_ho_b;
  real_T c1_ar_y;
  real_T c1_ak_a;
  real_T c1_io_b;
  real_T c1_br_y;
  real_T c1_sc_A;
  real_T c1_nx_x;
  real_T c1_ox_x;
  real_T c1_cr_y;
  real_T c1_px_x;
  real_T c1_qx_x;
  real_T c1_bk_a;
  real_T c1_jo_b;
  real_T c1_dr_y;
  real_T c1_rx_x;
  real_T c1_sx_x;
  real_T c1_ck_a;
  real_T c1_ko_b;
  real_T c1_er_y;
  real_T c1_dk_a;
  real_T c1_lo_b;
  real_T c1_fr_y;
  real_T c1_ek_a;
  real_T c1_mo_b;
  real_T c1_gr_y;
  real_T c1_tc_A;
  real_T c1_tx_x;
  real_T c1_ux_x;
  real_T c1_hr_y;
  real_T c1_vx_x;
  real_T c1_wx_x;
  real_T c1_fk_a;
  real_T c1_no_b;
  real_T c1_ir_y;
  real_T c1_xx_x;
  real_T c1_yx_x;
  real_T c1_gk_a;
  real_T c1_oo_b;
  real_T c1_jr_y;
  real_T c1_hk_a;
  real_T c1_po_b;
  real_T c1_kr_y;
  real_T c1_ik_a;
  real_T c1_qo_b;
  real_T c1_lr_y;
  real_T c1_uc_A;
  real_T c1_ay_x;
  real_T c1_by_x;
  real_T c1_mr_y;
  real_T c1_jk_a;
  real_T c1_ro_b;
  real_T c1_nr_y;
  real_T c1_cy_x;
  real_T c1_dy_x;
  real_T c1_so_b;
  real_T c1_or_y;
  real_T c1_kk_a;
  real_T c1_to_b;
  real_T c1_pr_y;
  real_T c1_ey_x;
  real_T c1_fy_x;
  real_T c1_lk_a;
  real_T c1_uo_b;
  real_T c1_qr_y;
  real_T c1_mk_a;
  real_T c1_vo_b;
  real_T c1_rr_y;
  real_T c1_vc_A;
  real_T c1_gy_x;
  real_T c1_hy_x;
  real_T c1_sr_y;
  real_T c1_nk_a;
  real_T c1_wo_b;
  real_T c1_tr_y;
  real_T c1_iy_x;
  real_T c1_jy_x;
  real_T c1_ok_a;
  real_T c1_xo_b;
  real_T c1_ur_y;
  real_T c1_wc_A;
  real_T c1_ky_x;
  real_T c1_ly_x;
  real_T c1_vr_y;
  real_T c1_my_x;
  real_T c1_ny_x;
  real_T c1_pk_a;
  real_T c1_yo_b;
  real_T c1_wr_y;
  real_T c1_qk_a;
  real_T c1_ap_b;
  real_T c1_xr_y;
  real_T c1_oy_x;
  real_T c1_py_x;
  real_T c1_qy_x;
  real_T c1_ry_x;
  real_T c1_bp_b;
  real_T c1_yr_y;
  real_T c1_sy_x;
  real_T c1_ty_x;
  real_T c1_cp_b;
  real_T c1_as_y;
  real_T c1_rk_a;
  real_T c1_dp_b;
  real_T c1_bs_y;
  real_T c1_xc_A;
  real_T c1_uy_x;
  real_T c1_vy_x;
  real_T c1_cs_y;
  real_T c1_wy_x;
  real_T c1_xy_x;
  real_T c1_sk_a;
  real_T c1_ep_b;
  real_T c1_ds_y;
  real_T c1_tk_a;
  real_T c1_fp_b;
  real_T c1_es_y;
  real_T c1_yy_x;
  real_T c1_aab_x;
  real_T c1_bab_x;
  real_T c1_cab_x;
  real_T c1_gp_b;
  real_T c1_fs_y;
  real_T c1_uk_a;
  real_T c1_hp_b;
  real_T c1_gs_y;
  real_T c1_yc_A;
  real_T c1_dab_x;
  real_T c1_eab_x;
  real_T c1_hs_y;
  real_T c1_fab_x;
  real_T c1_gab_x;
  real_T c1_vk_a;
  real_T c1_ip_b;
  real_T c1_is_y;
  real_T c1_wk_a;
  real_T c1_jp_b;
  real_T c1_js_y;
  real_T c1_hab_x;
  real_T c1_iab_x;
  real_T c1_jab_x;
  real_T c1_kab_x;
  real_T c1_kp_b;
  real_T c1_ks_y;
  real_T c1_xk_a;
  real_T c1_lp_b;
  real_T c1_ls_y;
  real_T c1_ad_A;
  real_T c1_lab_x;
  real_T c1_mab_x;
  real_T c1_ms_y;
  real_T c1_nab_x;
  real_T c1_oab_x;
  real_T c1_yk_a;
  real_T c1_mp_b;
  real_T c1_ns_y;
  real_T c1_al_a;
  real_T c1_np_b;
  real_T c1_os_y;
  real_T c1_pab_x;
  real_T c1_qab_x;
  real_T c1_rab_x;
  real_T c1_sab_x;
  real_T c1_op_b;
  real_T c1_ps_y;
  real_T c1_tab_x;
  real_T c1_uab_x;
  real_T c1_pp_b;
  real_T c1_qs_y;
  real_T c1_bl_a;
  real_T c1_qp_b;
  real_T c1_rs_y;
  real_T c1_bd_A;
  real_T c1_vab_x;
  real_T c1_wab_x;
  real_T c1_ss_y;
  real_T c1_xab_x;
  real_T c1_yab_x;
  real_T c1_cl_a;
  real_T c1_rp_b;
  real_T c1_ts_y;
  real_T c1_dl_a;
  real_T c1_sp_b;
  real_T c1_us_y;
  real_T c1_cd_A;
  real_T c1_abb_x;
  real_T c1_bbb_x;
  real_T c1_vs_y;
  real_T c1_el_a;
  real_T c1_tp_b;
  real_T c1_ws_y;
  real_T c1_cbb_x;
  real_T c1_dbb_x;
  real_T c1_up_b;
  real_T c1_xs_y;
  real_T c1_ebb_x;
  real_T c1_fbb_x;
  real_T c1_vp_b;
  real_T c1_ys_y;
  real_T c1_fl_a;
  real_T c1_wp_b;
  real_T c1_at_y;
  real_T c1_dd_A;
  real_T c1_gbb_x;
  real_T c1_hbb_x;
  real_T c1_bt_y;
  real_T c1_gl_a;
  real_T c1_xp_b;
  real_T c1_ct_y;
  real_T c1_ibb_x;
  real_T c1_jbb_x;
  real_T c1_hl_a;
  real_T c1_yp_b;
  real_T c1_dt_y;
  real_T c1_ed_A;
  real_T c1_kbb_x;
  real_T c1_lbb_x;
  real_T c1_et_y;
  real_T c1_il_a;
  real_T c1_aq_b;
  real_T c1_ft_y;
  real_T c1_mbb_x;
  real_T c1_nbb_x;
  real_T c1_jl_a;
  real_T c1_bq_b;
  real_T c1_gt_y;
  real_T c1_fd_A;
  real_T c1_obb_x;
  real_T c1_pbb_x;
  real_T c1_ht_y;
  real_T c1_qbb_x;
  real_T c1_rbb_x;
  real_T c1_kl_a;
  real_T c1_cq_b;
  real_T c1_it_y;
  real_T c1_ll_a;
  real_T c1_dq_b;
  real_T c1_jt_y;
  real_T c1_sbb_x;
  real_T c1_tbb_x;
  real_T c1_ubb_x;
  real_T c1_vbb_x;
  real_T c1_eq_b;
  real_T c1_kt_y;
  real_T c1_wbb_x;
  real_T c1_xbb_x;
  real_T c1_fq_b;
  real_T c1_lt_y;
  real_T c1_ml_a;
  real_T c1_gq_b;
  real_T c1_mt_y;
  real_T c1_gd_A;
  real_T c1_ybb_x;
  real_T c1_acb_x;
  real_T c1_nt_y;
  real_T c1_bcb_x;
  real_T c1_ccb_x;
  real_T c1_nl_a;
  real_T c1_hq_b;
  real_T c1_ot_y;
  real_T c1_ol_a;
  real_T c1_iq_b;
  real_T c1_pt_y;
  real_T c1_dcb_x;
  real_T c1_ecb_x;
  real_T c1_jq_b;
  real_T c1_qt_y;
  real_T c1_fcb_x;
  real_T c1_gcb_x;
  real_T c1_hcb_x;
  real_T c1_icb_x;
  real_T c1_kq_b;
  real_T c1_rt_y;
  real_T c1_pl_a;
  real_T c1_lq_b;
  real_T c1_st_y;
  real_T c1_hd_A;
  real_T c1_jcb_x;
  real_T c1_kcb_x;
  real_T c1_tt_y;
  real_T c1_lcb_x;
  real_T c1_mcb_x;
  real_T c1_ql_a;
  real_T c1_mq_b;
  real_T c1_ut_y;
  real_T c1_rl_a;
  real_T c1_nq_b;
  real_T c1_vt_y;
  real_T c1_ncb_x;
  real_T c1_ocb_x;
  real_T c1_oq_b;
  real_T c1_wt_y;
  real_T c1_pcb_x;
  real_T c1_qcb_x;
  real_T c1_rcb_x;
  real_T c1_scb_x;
  real_T c1_pq_b;
  real_T c1_xt_y;
  real_T c1_sl_a;
  real_T c1_qq_b;
  real_T c1_yt_y;
  real_T c1_id_A;
  real_T c1_tcb_x;
  real_T c1_ucb_x;
  real_T c1_au_y;
  real_T c1_vcb_x;
  real_T c1_wcb_x;
  real_T c1_tl_a;
  real_T c1_rq_b;
  real_T c1_bu_y;
  real_T c1_ul_a;
  real_T c1_sq_b;
  real_T c1_cu_y;
  real_T c1_xcb_x;
  real_T c1_ycb_x;
  real_T c1_vl_a;
  real_T c1_tq_b;
  real_T c1_du_y;
  real_T c1_adb_x;
  real_T c1_bdb_x;
  real_T c1_uq_b;
  real_T c1_eu_y;
  real_T c1_wl_a;
  real_T c1_vq_b;
  real_T c1_fu_y;
  real_T c1_wq_b;
  real_T c1_gu_y;
  real_T c1_cdb_x;
  real_T c1_ddb_x;
  real_T c1_xl_a;
  real_T c1_xq_b;
  real_T c1_hu_y;
  real_T c1_yl_a;
  real_T c1_yq_b;
  real_T c1_iu_y;
  real_T c1_jd_A;
  real_T c1_edb_x;
  real_T c1_fdb_x;
  real_T c1_ju_y;
  real_T c1_gdb_x;
  real_T c1_hdb_x;
  real_T c1_am_a;
  real_T c1_ar_b;
  real_T c1_ku_y;
  real_T c1_bm_a;
  real_T c1_br_b;
  real_T c1_lu_y;
  real_T c1_idb_x;
  real_T c1_jdb_x;
  real_T c1_cm_a;
  real_T c1_cr_b;
  real_T c1_mu_y;
  real_T c1_kdb_x;
  real_T c1_ldb_x;
  real_T c1_dr_b;
  real_T c1_nu_y;
  real_T c1_dm_a;
  real_T c1_er_b;
  real_T c1_ou_y;
  real_T c1_fr_b;
  real_T c1_pu_y;
  real_T c1_mdb_x;
  real_T c1_ndb_x;
  real_T c1_em_a;
  real_T c1_gr_b;
  real_T c1_qu_y;
  real_T c1_fm_a;
  real_T c1_hr_b;
  real_T c1_ru_y;
  real_T c1_kd_A;
  real_T c1_odb_x;
  real_T c1_pdb_x;
  real_T c1_su_y;
  real_T c1_qdb_x;
  real_T c1_rdb_x;
  real_T c1_gm_a;
  real_T c1_ir_b;
  real_T c1_tu_y;
  real_T c1_hm_a;
  real_T c1_jr_b;
  real_T c1_uu_y;
  real_T c1_sdb_x;
  real_T c1_tdb_x;
  real_T c1_udb_x;
  real_T c1_vdb_x;
  real_T c1_kr_b;
  real_T c1_vu_y;
  real_T c1_wdb_x;
  real_T c1_xdb_x;
  real_T c1_lr_b;
  real_T c1_wu_y;
  real_T c1_im_a;
  real_T c1_mr_b;
  real_T c1_xu_y;
  real_T c1_ld_A;
  real_T c1_ydb_x;
  real_T c1_aeb_x;
  real_T c1_yu_y;
  real_T c1_beb_x;
  real_T c1_ceb_x;
  real_T c1_jm_a;
  real_T c1_nr_b;
  real_T c1_av_y;
  real_T c1_km_a;
  real_T c1_or_b;
  real_T c1_bv_y;
  real_T c1_deb_x;
  real_T c1_eeb_x;
  real_T c1_feb_x;
  real_T c1_geb_x;
  real_T c1_pr_b;
  real_T c1_cv_y;
  real_T c1_heb_x;
  real_T c1_ieb_x;
  real_T c1_qr_b;
  real_T c1_dv_y;
  real_T c1_lm_a;
  real_T c1_rr_b;
  real_T c1_ev_y;
  real_T c1_mm_a;
  real_T c1_sr_b;
  real_T c1_fv_y;
  real_T c1_md_A;
  real_T c1_jeb_x;
  real_T c1_keb_x;
  real_T c1_gv_y;
  real_T c1_leb_x;
  real_T c1_meb_x;
  real_T c1_nm_a;
  real_T c1_tr_b;
  real_T c1_hv_y;
  real_T c1_om_a;
  real_T c1_ur_b;
  real_T c1_iv_y;
  real_T c1_neb_x;
  real_T c1_oeb_x;
  real_T c1_peb_x;
  real_T c1_qeb_x;
  real_T c1_vr_b;
  real_T c1_jv_y;
  real_T c1_reb_x;
  real_T c1_seb_x;
  real_T c1_wr_b;
  real_T c1_kv_y;
  real_T c1_pm_a;
  real_T c1_xr_b;
  real_T c1_lv_y;
  real_T c1_qm_a;
  real_T c1_yr_b;
  real_T c1_mv_y;
  real_T c1_nd_A;
  real_T c1_teb_x;
  real_T c1_ueb_x;
  real_T c1_nv_y;
  real_T c1_rm_a;
  real_T c1_as_b;
  real_T c1_ov_y;
  real_T c1_veb_x;
  real_T c1_web_x;
  real_T c1_sm_a;
  real_T c1_bs_b;
  real_T c1_pv_y;
  real_T c1_od_A;
  real_T c1_xeb_x;
  real_T c1_yeb_x;
  real_T c1_qv_y;
  real_T c1_afb_x;
  real_T c1_bfb_x;
  real_T c1_tm_a;
  real_T c1_cs_b;
  real_T c1_rv_y;
  real_T c1_um_a;
  real_T c1_ds_b;
  real_T c1_sv_y;
  real_T c1_cfb_x;
  real_T c1_dfb_x;
  real_T c1_efb_x;
  real_T c1_ffb_x;
  real_T c1_es_b;
  real_T c1_tv_y;
  real_T c1_gfb_x;
  real_T c1_hfb_x;
  real_T c1_fs_b;
  real_T c1_uv_y;
  real_T c1_vm_a;
  real_T c1_gs_b;
  real_T c1_vv_y;
  real_T c1_pd_A;
  real_T c1_ifb_x;
  real_T c1_jfb_x;
  real_T c1_wv_y;
  real_T c1_kfb_x;
  real_T c1_lfb_x;
  real_T c1_wm_a;
  real_T c1_hs_b;
  real_T c1_xv_y;
  real_T c1_xm_a;
  real_T c1_is_b;
  real_T c1_yv_y;
  real_T c1_mfb_x;
  real_T c1_nfb_x;
  real_T c1_ym_a;
  real_T c1_js_b;
  real_T c1_aw_y;
  real_T c1_ofb_x;
  real_T c1_pfb_x;
  real_T c1_ks_b;
  real_T c1_bw_y;
  real_T c1_an_a;
  real_T c1_ls_b;
  real_T c1_cw_y;
  real_T c1_bn_a;
  real_T c1_ms_b;
  real_T c1_dw_y;
  real_T c1_qd_A;
  real_T c1_qfb_x;
  real_T c1_rfb_x;
  real_T c1_ew_y;
  real_T c1_sfb_x;
  real_T c1_tfb_x;
  real_T c1_cn_a;
  real_T c1_ns_b;
  real_T c1_fw_y;
  real_T c1_dn_a;
  real_T c1_os_b;
  real_T c1_gw_y;
  real_T c1_ufb_x;
  real_T c1_vfb_x;
  real_T c1_en_a;
  real_T c1_ps_b;
  real_T c1_hw_y;
  real_T c1_wfb_x;
  real_T c1_xfb_x;
  real_T c1_qs_b;
  real_T c1_iw_y;
  real_T c1_fn_a;
  real_T c1_rs_b;
  real_T c1_jw_y;
  real_T c1_gn_a;
  real_T c1_ss_b;
  real_T c1_kw_y;
  real_T c1_rd_A;
  real_T c1_yfb_x;
  real_T c1_agb_x;
  real_T c1_lw_y;
  real_T c1_bgb_x;
  real_T c1_cgb_x;
  real_T c1_hn_a;
  real_T c1_ts_b;
  real_T c1_mw_y;
  real_T c1_in_a;
  real_T c1_us_b;
  real_T c1_nw_y;
  real_T c1_dgb_x;
  real_T c1_egb_x;
  real_T c1_fgb_x;
  real_T c1_ggb_x;
  real_T c1_vs_b;
  real_T c1_ow_y;
  real_T c1_jn_a;
  real_T c1_ws_b;
  real_T c1_pw_y;
  real_T c1_sd_A;
  real_T c1_hgb_x;
  real_T c1_igb_x;
  real_T c1_qw_y;
  real_T c1_jgb_x;
  real_T c1_kgb_x;
  real_T c1_kn_a;
  real_T c1_xs_b;
  real_T c1_rw_y;
  real_T c1_ln_a;
  real_T c1_ys_b;
  real_T c1_sw_y;
  real_T c1_lgb_x;
  real_T c1_mgb_x;
  real_T c1_ngb_x;
  real_T c1_ogb_x;
  real_T c1_at_b;
  real_T c1_tw_y;
  real_T c1_mn_a;
  real_T c1_bt_b;
  real_T c1_uw_y;
  real_T c1_td_A;
  real_T c1_pgb_x;
  real_T c1_qgb_x;
  real_T c1_vw_y;
  real_T c1_rgb_x;
  real_T c1_sgb_x;
  real_T c1_nn_a;
  real_T c1_ct_b;
  real_T c1_ww_y;
  real_T c1_tgb_x;
  real_T c1_ugb_x;
  real_T c1_xw_y;
  real_T c1_on_a;
  real_T c1_dt_b;
  real_T c1_yw_y;
  real_T c1_vgb_x;
  real_T c1_wgb_x;
  real_T c1_xgb_x;
  real_T c1_ygb_x;
  real_T c1_et_b;
  real_T c1_ax_y;
  real_T c1_ahb_x;
  real_T c1_bhb_x;
  real_T c1_ft_b;
  real_T c1_bx_y;
  real_T c1_pn_a;
  real_T c1_gt_b;
  real_T c1_cx_y;
  real_T c1_ud_A;
  real_T c1_chb_x;
  real_T c1_dhb_x;
  real_T c1_dx_y;
  real_T c1_ehb_x;
  real_T c1_fhb_x;
  real_T c1_qn_a;
  real_T c1_ht_b;
  real_T c1_ex_y;
  real_T c1_ghb_x;
  real_T c1_hhb_x;
  real_T c1_fx_y;
  real_T c1_rn_a;
  real_T c1_it_b;
  real_T c1_gx_y;
  real_T c1_ihb_x;
  real_T c1_jhb_x;
  real_T c1_khb_x;
  real_T c1_lhb_x;
  real_T c1_jt_b;
  real_T c1_hx_y;
  real_T c1_sn_a;
  real_T c1_kt_b;
  real_T c1_ix_y;
  real_T c1_tn_a;
  real_T c1_lt_b;
  real_T c1_jx_y;
  real_T c1_vd_A;
  real_T c1_mhb_x;
  real_T c1_nhb_x;
  real_T c1_kx_y;
  real_T c1_ohb_x;
  real_T c1_phb_x;
  real_T c1_un_a;
  real_T c1_mt_b;
  real_T c1_lx_y;
  real_T c1_qhb_x;
  real_T c1_rhb_x;
  real_T c1_mx_y;
  real_T c1_vn_a;
  real_T c1_nt_b;
  real_T c1_nx_y;
  real_T c1_shb_x;
  real_T c1_thb_x;
  real_T c1_uhb_x;
  real_T c1_vhb_x;
  real_T c1_ot_b;
  real_T c1_ox_y;
  real_T c1_wn_a;
  real_T c1_pt_b;
  real_T c1_px_y;
  real_T c1_xn_a;
  real_T c1_qt_b;
  real_T c1_qx_y;
  real_T c1_wd_A;
  real_T c1_whb_x;
  real_T c1_xhb_x;
  real_T c1_rx_y;
  real_T c1_yhb_x;
  real_T c1_aib_x;
  real_T c1_yn_a;
  real_T c1_rt_b;
  real_T c1_sx_y;
  real_T c1_bib_x;
  real_T c1_cib_x;
  real_T c1_tx_y;
  real_T c1_ao_a;
  real_T c1_st_b;
  real_T c1_ux_y;
  real_T c1_bo_a;
  real_T c1_tt_b;
  real_T c1_vx_y;
  real_T c1_xd_A;
  real_T c1_dib_x;
  real_T c1_eib_x;
  real_T c1_wx_y;
  real_T c1_fib_x;
  real_T c1_gib_x;
  real_T c1_co_a;
  real_T c1_ut_b;
  real_T c1_xx_y;
  real_T c1_hib_x;
  real_T c1_iib_x;
  real_T c1_yx_y;
  real_T c1_do_a;
  real_T c1_vt_b;
  real_T c1_ay_y;
  real_T c1_jib_x;
  real_T c1_kib_x;
  real_T c1_lib_x;
  real_T c1_mib_x;
  real_T c1_wt_b;
  real_T c1_by_y;
  real_T c1_nib_x;
  real_T c1_oib_x;
  real_T c1_xt_b;
  real_T c1_cy_y;
  real_T c1_eo_a;
  real_T c1_yt_b;
  real_T c1_dy_y;
  real_T c1_yd_A;
  real_T c1_pib_x;
  real_T c1_qib_x;
  real_T c1_ey_y;
  real_T c1_rib_x;
  real_T c1_sib_x;
  real_T c1_fo_a;
  real_T c1_au_b;
  real_T c1_fy_y;
  real_T c1_tib_x;
  real_T c1_uib_x;
  real_T c1_go_a;
  real_T c1_bu_b;
  real_T c1_gy_y;
  real_T c1_vib_x;
  real_T c1_wib_x;
  real_T c1_hy_y;
  real_T c1_ho_a;
  real_T c1_cu_b;
  real_T c1_iy_y;
  real_T c1_ae_A;
  real_T c1_xib_x;
  real_T c1_yib_x;
  real_T c1_jy_y;
  real_T c1_ajb_x;
  real_T c1_bjb_x;
  real_T c1_io_a;
  real_T c1_du_b;
  real_T c1_ky_y;
  real_T c1_cjb_x;
  real_T c1_djb_x;
  real_T c1_jo_a;
  real_T c1_eu_b;
  real_T c1_ly_y;
  real_T c1_ejb_x;
  real_T c1_fjb_x;
  real_T c1_my_y;
  real_T c1_ko_a;
  real_T c1_fu_b;
  real_T c1_ny_y;
  real_T c1_be_A;
  real_T c1_gjb_x;
  real_T c1_hjb_x;
  real_T c1_oy_y;
  real_T c1_ijb_x;
  real_T c1_jjb_x;
  real_T c1_lo_a;
  real_T c1_gu_b;
  real_T c1_py_y;
  real_T c1_kjb_x;
  real_T c1_ljb_x;
  real_T c1_qy_y;
  real_T c1_mo_a;
  real_T c1_hu_b;
  real_T c1_ry_y;
  real_T c1_mjb_x;
  real_T c1_njb_x;
  real_T c1_ojb_x;
  real_T c1_pjb_x;
  real_T c1_iu_b;
  real_T c1_sy_y;
  real_T c1_no_a;
  real_T c1_ju_b;
  real_T c1_ty_y;
  real_T c1_ce_A;
  real_T c1_qjb_x;
  real_T c1_rjb_x;
  real_T c1_uy_y;
  real_T c1_sjb_x;
  real_T c1_tjb_x;
  real_T c1_oo_a;
  real_T c1_ku_b;
  real_T c1_vy_y;
  real_T c1_ujb_x;
  real_T c1_vjb_x;
  real_T c1_wy_y;
  real_T c1_po_a;
  real_T c1_lu_b;
  real_T c1_xy_y;
  real_T c1_wjb_x;
  real_T c1_xjb_x;
  real_T c1_yjb_x;
  real_T c1_akb_x;
  real_T c1_mu_b;
  real_T c1_yy_y;
  real_T c1_qo_a;
  real_T c1_nu_b;
  real_T c1_aab_y;
  real_T c1_de_A;
  real_T c1_bkb_x;
  real_T c1_ckb_x;
  real_T c1_bab_y;
  real_T c1_dkb_x;
  real_T c1_ekb_x;
  real_T c1_ro_a;
  real_T c1_ou_b;
  real_T c1_cab_y;
  real_T c1_fkb_x;
  real_T c1_gkb_x;
  real_T c1_dab_y;
  real_T c1_so_a;
  real_T c1_pu_b;
  real_T c1_eab_y;
  real_T c1_hkb_x;
  real_T c1_ikb_x;
  real_T c1_jkb_x;
  real_T c1_kkb_x;
  real_T c1_qu_b;
  real_T c1_fab_y;
  real_T c1_lkb_x;
  real_T c1_mkb_x;
  real_T c1_ru_b;
  real_T c1_gab_y;
  real_T c1_to_a;
  real_T c1_su_b;
  real_T c1_hab_y;
  real_T c1_ee_A;
  real_T c1_nkb_x;
  real_T c1_okb_x;
  real_T c1_iab_y;
  int32_T c1_i8;
  int32_T c1_i9;
  real_T (*c1_b_C)[9];
  real_T (*c1_b_q_dot)[3];
  real_T (*c1_b_qqd)[9];
  c1_b_q_dot = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_C = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = chartInstance->c1_mn;
  c1_b_hoistedGlobal = chartInstance->c1_l;
  for (c1_i7 = 0; c1_i7 < 9; c1_i7++) {
    c1_qqd[c1_i7] = (*c1_b_qqd)[c1_i7];
  }

  c1_b_mn = c1_hoistedGlobal;
  c1_b_l = c1_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_q, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 1U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_qqd, 3U, c1_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_mn, 4U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_l, 5U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_C, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_q_dot, 7U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 2);
  c1_q[0] = c1_qqd[6];
  c1_q[1] = c1_qqd[7];
  c1_q[2] = c1_qqd[8];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  c1_q_dot[0] = c1_qqd[3];
  c1_q_dot[1] = c1_qqd[4];
  c1_q_dot[2] = c1_qqd[5];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_a = c1_b_mn;
  c1_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_y = c1_a * c1_b;
  c1_x = c1_q[0];
  c1_b_x = c1_x;
  c1_b_x = muDoubleScalarSin(c1_b_x);
  c1_b_b = c1_b_x;
  c1_b_y = 2.0 * c1_b_b;
  c1_c_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_d_x = c1_c_x;
  c1_d_x = muDoubleScalarSin(c1_d_x);
  c1_e_x = c1_q[0] + c1_q[1];
  c1_f_x = c1_e_x;
  c1_f_x = muDoubleScalarSin(c1_f_x);
  c1_c_b = c1_f_x;
  c1_c_y = 2.0 * c1_c_b;
  c1_b_a = c1_y;
  c1_d_b = (c1_b_y + c1_d_x) + c1_c_y;
  c1_d_y = c1_b_a * c1_d_b;
  c1_g_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_h_x = c1_g_x;
  c1_h_x = muDoubleScalarCos(c1_h_x);
  c1_c_a = c1_h_x;
  c1_e_b = (c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2];
  c1_e_y = c1_c_a * c1_e_b;
  c1_i_x = c1_q[0] + c1_q[1];
  c1_j_x = c1_i_x;
  c1_j_x = muDoubleScalarCos(c1_j_x);
  c1_f_b = c1_j_x;
  c1_f_y = 2.0 * c1_f_b;
  c1_d_a = c1_f_y;
  c1_g_b = c1_q_dot[0] + c1_q_dot[1];
  c1_g_y = c1_d_a * c1_g_b;
  c1_h_b = c1_q_dot[0];
  c1_h_y = 2.0 * c1_h_b;
  c1_k_x = c1_q[0];
  c1_l_x = c1_k_x;
  c1_l_x = muDoubleScalarCos(c1_l_x);
  c1_e_a = c1_h_y;
  c1_i_b = c1_l_x;
  c1_i_y = c1_e_a * c1_i_b;
  c1_f_a = c1_d_y;
  c1_j_b = (c1_e_y + c1_g_y) + c1_i_y;
  c1_j_y = c1_f_a * c1_j_b;
  c1_A = c1_j_y;
  c1_m_x = c1_A;
  c1_n_x = c1_m_x;
  c1_k_y = c1_n_x / 8.0;
  c1_g_a = c1_b_mn;
  c1_k_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_l_y = c1_g_a * c1_k_b;
  c1_o_x = c1_q[0];
  c1_p_x = c1_o_x;
  c1_p_x = muDoubleScalarCos(c1_p_x);
  c1_l_b = c1_p_x;
  c1_m_y = 2.0 * c1_l_b;
  c1_q_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_r_x = c1_q_x;
  c1_r_x = muDoubleScalarCos(c1_r_x);
  c1_s_x = c1_q[0] + c1_q[1];
  c1_t_x = c1_s_x;
  c1_t_x = muDoubleScalarCos(c1_t_x);
  c1_m_b = c1_t_x;
  c1_n_y = 2.0 * c1_m_b;
  c1_h_a = c1_l_y;
  c1_n_b = (c1_m_y + c1_r_x) + c1_n_y;
  c1_o_y = c1_h_a * c1_n_b;
  c1_u_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_v_x = c1_u_x;
  c1_v_x = muDoubleScalarSin(c1_v_x);
  c1_i_a = c1_v_x;
  c1_o_b = (c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2];
  c1_p_y = c1_i_a * c1_o_b;
  c1_w_x = c1_q[0] + c1_q[1];
  c1_x_x = c1_w_x;
  c1_x_x = muDoubleScalarSin(c1_x_x);
  c1_p_b = c1_x_x;
  c1_q_y = 2.0 * c1_p_b;
  c1_j_a = c1_q_y;
  c1_q_b = c1_q_dot[0] + c1_q_dot[1];
  c1_r_y = c1_j_a * c1_q_b;
  c1_r_b = c1_q_dot[0];
  c1_s_y = 2.0 * c1_r_b;
  c1_y_x = c1_q[0];
  c1_ab_x = c1_y_x;
  c1_ab_x = muDoubleScalarSin(c1_ab_x);
  c1_k_a = c1_s_y;
  c1_s_b = c1_ab_x;
  c1_t_y = c1_k_a * c1_s_b;
  c1_l_a = c1_o_y;
  c1_t_b = (c1_p_y + c1_r_y) + c1_t_y;
  c1_u_y = c1_l_a * c1_t_b;
  c1_b_A = c1_u_y;
  c1_bb_x = c1_b_A;
  c1_cb_x = c1_bb_x;
  c1_v_y = c1_cb_x / 8.0;
  c1_m_a = c1_b_mn;
  c1_u_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_w_y = c1_m_a * c1_u_b;
  c1_db_x = c1_q[0] + c1_q[1];
  c1_eb_x = c1_db_x;
  c1_eb_x = muDoubleScalarCos(c1_eb_x);
  c1_n_a = c1_eb_x;
  c1_v_b = c1_q_dot[0] + c1_q_dot[1];
  c1_x_y = c1_n_a * c1_v_b;
  c1_w_b = c1_q_dot[0];
  c1_y_y = 2.0 * c1_w_b;
  c1_fb_x = c1_q[0];
  c1_gb_x = c1_fb_x;
  c1_gb_x = muDoubleScalarCos(c1_gb_x);
  c1_o_a = c1_y_y;
  c1_x_b = c1_gb_x;
  c1_ab_y = c1_o_a * c1_x_b;
  c1_p_a = c1_w_y;
  c1_y_b = c1_x_y + c1_ab_y;
  c1_bb_y = c1_p_a * c1_y_b;
  c1_hb_x = c1_q[0];
  c1_ib_x = c1_hb_x;
  c1_ib_x = muDoubleScalarSin(c1_ib_x);
  c1_ab_b = c1_ib_x;
  c1_cb_y = 2.0 * c1_ab_b;
  c1_jb_x = c1_q[0] + c1_q[1];
  c1_kb_x = c1_jb_x;
  c1_kb_x = muDoubleScalarSin(c1_kb_x);
  c1_q_a = c1_bb_y;
  c1_bb_b = c1_cb_y + c1_kb_x;
  c1_db_y = c1_q_a * c1_bb_b;
  c1_c_A = c1_db_y;
  c1_lb_x = c1_c_A;
  c1_mb_x = c1_lb_x;
  c1_eb_y = c1_mb_x / 8.0;
  c1_r_a = c1_b_mn;
  c1_cb_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_fb_y = c1_r_a * c1_cb_b;
  c1_nb_x = c1_q[0];
  c1_ob_x = c1_nb_x;
  c1_ob_x = muDoubleScalarCos(c1_ob_x);
  c1_db_b = c1_ob_x;
  c1_gb_y = 2.0 * c1_db_b;
  c1_pb_x = c1_q[0] + c1_q[1];
  c1_qb_x = c1_pb_x;
  c1_qb_x = muDoubleScalarCos(c1_qb_x);
  c1_s_a = c1_fb_y;
  c1_eb_b = c1_gb_y + c1_qb_x;
  c1_hb_y = c1_s_a * c1_eb_b;
  c1_rb_x = c1_q[0] + c1_q[1];
  c1_sb_x = c1_rb_x;
  c1_sb_x = muDoubleScalarSin(c1_sb_x);
  c1_t_a = c1_sb_x;
  c1_fb_b = c1_q_dot[0] + c1_q_dot[1];
  c1_ib_y = c1_t_a * c1_fb_b;
  c1_gb_b = c1_q_dot[0];
  c1_jb_y = 2.0 * c1_gb_b;
  c1_tb_x = c1_q[0];
  c1_ub_x = c1_tb_x;
  c1_ub_x = muDoubleScalarSin(c1_ub_x);
  c1_u_a = c1_jb_y;
  c1_hb_b = c1_ub_x;
  c1_kb_y = c1_u_a * c1_hb_b;
  c1_v_a = c1_hb_y;
  c1_ib_b = c1_ib_y + c1_kb_y;
  c1_lb_y = c1_v_a * c1_ib_b;
  c1_d_A = c1_lb_y;
  c1_vb_x = c1_d_A;
  c1_wb_x = c1_vb_x;
  c1_mb_y = c1_wb_x / 8.0;
  c1_w_a = c1_b_mn;
  c1_jb_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_nb_y = c1_w_a * c1_jb_b;
  c1_xb_x = c1_q[0] + c1_q[1];
  c1_yb_x = c1_xb_x;
  c1_yb_x = muDoubleScalarCos(c1_yb_x);
  c1_ac_x = c1_q[0];
  c1_bc_x = c1_ac_x;
  c1_bc_x = muDoubleScalarCos(c1_bc_x);
  c1_kb_b = c1_bc_x;
  c1_ob_y = 2.0 * c1_kb_b;
  c1_x_a = c1_nb_y;
  c1_lb_b = c1_yb_x + c1_ob_y;
  c1_pb_y = c1_x_a * c1_lb_b;
  c1_cc_x = c1_q[0];
  c1_dc_x = c1_cc_x;
  c1_dc_x = muDoubleScalarSin(c1_dc_x);
  c1_mb_b = c1_dc_x;
  c1_qb_y = 2.0 * c1_mb_b;
  c1_y_a = c1_qb_y;
  c1_nb_b = c1_q_dot[0];
  c1_rb_y = c1_y_a * c1_nb_b;
  c1_ec_x = c1_q[0] + c1_q[1];
  c1_fc_x = c1_ec_x;
  c1_fc_x = muDoubleScalarSin(c1_fc_x);
  c1_ab_a = c1_fc_x;
  c1_ob_b = c1_q_dot[0] + c1_q_dot[1];
  c1_sb_y = c1_ab_a * c1_ob_b;
  c1_bb_a = c1_pb_y;
  c1_pb_b = c1_rb_y + c1_sb_y;
  c1_tb_y = c1_bb_a * c1_pb_b;
  c1_e_A = c1_tb_y;
  c1_gc_x = c1_e_A;
  c1_hc_x = c1_gc_x;
  c1_ub_y = c1_hc_x / 8.0;
  c1_cb_a = c1_b_mn;
  c1_qb_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_vb_y = c1_cb_a * c1_qb_b;
  c1_ic_x = c1_q[0] + c1_q[1];
  c1_jc_x = c1_ic_x;
  c1_jc_x = muDoubleScalarSin(c1_jc_x);
  c1_kc_x = c1_q[0];
  c1_lc_x = c1_kc_x;
  c1_lc_x = muDoubleScalarSin(c1_lc_x);
  c1_rb_b = c1_lc_x;
  c1_wb_y = 2.0 * c1_rb_b;
  c1_db_a = c1_vb_y;
  c1_sb_b = c1_jc_x + c1_wb_y;
  c1_xb_y = c1_db_a * c1_sb_b;
  c1_mc_x = c1_q[0];
  c1_nc_x = c1_mc_x;
  c1_nc_x = muDoubleScalarCos(c1_nc_x);
  c1_tb_b = c1_nc_x;
  c1_yb_y = 2.0 * c1_tb_b;
  c1_eb_a = c1_yb_y;
  c1_ub_b = c1_q_dot[0];
  c1_ac_y = c1_eb_a * c1_ub_b;
  c1_oc_x = c1_q[0] + c1_q[1];
  c1_pc_x = c1_oc_x;
  c1_pc_x = muDoubleScalarCos(c1_pc_x);
  c1_fb_a = c1_pc_x;
  c1_vb_b = c1_q_dot[0] + c1_q_dot[1];
  c1_bc_y = c1_fb_a * c1_vb_b;
  c1_gb_a = c1_xb_y;
  c1_wb_b = c1_ac_y + c1_bc_y;
  c1_cc_y = c1_gb_a * c1_wb_b;
  c1_f_A = c1_cc_y;
  c1_qc_x = c1_f_A;
  c1_rc_x = c1_qc_x;
  c1_dc_y = c1_rc_x / 8.0;
  c1_hb_a = c1_b_mn;
  c1_xb_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_ec_y = c1_hb_a * c1_xb_b;
  c1_sc_x = c1_q[0];
  c1_tc_x = c1_sc_x;
  c1_tc_x = muDoubleScalarCos(c1_tc_x);
  c1_yb_b = c1_tc_x;
  c1_fc_y = 2.0 * c1_yb_b;
  c1_ib_a = c1_fc_y;
  c1_ac_b = c1_q_dot[0];
  c1_gc_y = c1_ib_a * c1_ac_b;
  c1_uc_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_vc_x = c1_uc_x;
  c1_vc_x = muDoubleScalarCos(c1_vc_x);
  c1_jb_a = c1_vc_x;
  c1_bc_b = (c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2];
  c1_hc_y = c1_jb_a * c1_bc_b;
  c1_wc_x = c1_q[0] + c1_q[1];
  c1_xc_x = c1_wc_x;
  c1_xc_x = muDoubleScalarCos(c1_xc_x);
  c1_cc_b = c1_xc_x;
  c1_ic_y = 2.0 * c1_cc_b;
  c1_kb_a = c1_ic_y;
  c1_dc_b = c1_q_dot[0] + c1_q_dot[1];
  c1_jc_y = c1_kb_a * c1_dc_b;
  c1_lb_a = c1_ec_y;
  c1_ec_b = (c1_gc_y + c1_hc_y) + c1_jc_y;
  c1_kc_y = c1_lb_a * c1_ec_b;
  c1_yc_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_ad_x = c1_yc_x;
  c1_ad_x = muDoubleScalarSin(c1_ad_x);
  c1_bd_x = c1_q[0] + c1_q[1];
  c1_cd_x = c1_bd_x;
  c1_cd_x = muDoubleScalarSin(c1_cd_x);
  c1_fc_b = c1_cd_x;
  c1_lc_y = 2.0 * c1_fc_b;
  c1_dd_x = c1_q[0];
  c1_ed_x = c1_dd_x;
  c1_ed_x = muDoubleScalarSin(c1_ed_x);
  c1_gc_b = c1_ed_x;
  c1_mc_y = 2.0 * c1_gc_b;
  c1_mb_a = c1_kc_y;
  c1_hc_b = (c1_ad_x + c1_lc_y) + c1_mc_y;
  c1_nc_y = c1_mb_a * c1_hc_b;
  c1_g_A = c1_nc_y;
  c1_fd_x = c1_g_A;
  c1_gd_x = c1_fd_x;
  c1_oc_y = c1_gd_x / 8.0;
  c1_nb_a = c1_b_mn;
  c1_ic_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_pc_y = c1_nb_a * c1_ic_b;
  c1_hd_x = c1_q[0];
  c1_id_x = c1_hd_x;
  c1_id_x = muDoubleScalarSin(c1_id_x);
  c1_jc_b = c1_id_x;
  c1_qc_y = 2.0 * c1_jc_b;
  c1_ob_a = c1_qc_y;
  c1_kc_b = c1_q_dot[0];
  c1_rc_y = c1_ob_a * c1_kc_b;
  c1_jd_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_kd_x = c1_jd_x;
  c1_kd_x = muDoubleScalarSin(c1_kd_x);
  c1_pb_a = c1_kd_x;
  c1_lc_b = (c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2];
  c1_sc_y = c1_pb_a * c1_lc_b;
  c1_ld_x = c1_q[0] + c1_q[1];
  c1_md_x = c1_ld_x;
  c1_md_x = muDoubleScalarSin(c1_md_x);
  c1_mc_b = c1_md_x;
  c1_tc_y = 2.0 * c1_mc_b;
  c1_qb_a = c1_tc_y;
  c1_nc_b = c1_q_dot[0] + c1_q_dot[1];
  c1_uc_y = c1_qb_a * c1_nc_b;
  c1_rb_a = c1_pc_y;
  c1_oc_b = (c1_rc_y + c1_sc_y) + c1_uc_y;
  c1_vc_y = c1_rb_a * c1_oc_b;
  c1_nd_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_od_x = c1_nd_x;
  c1_od_x = muDoubleScalarCos(c1_od_x);
  c1_pd_x = c1_q[0] + c1_q[1];
  c1_qd_x = c1_pd_x;
  c1_qd_x = muDoubleScalarCos(c1_qd_x);
  c1_pc_b = c1_qd_x;
  c1_wc_y = 2.0 * c1_pc_b;
  c1_rd_x = c1_q[0];
  c1_sd_x = c1_rd_x;
  c1_sd_x = muDoubleScalarCos(c1_sd_x);
  c1_qc_b = c1_sd_x;
  c1_xc_y = 2.0 * c1_qc_b;
  c1_sb_a = c1_vc_y;
  c1_rc_b = (c1_od_x + c1_wc_y) + c1_xc_y;
  c1_yc_y = c1_sb_a * c1_rc_b;
  c1_h_A = c1_yc_y;
  c1_td_x = c1_h_A;
  c1_ud_x = c1_td_x;
  c1_ad_y = c1_ud_x / 8.0;
  c1_tb_a = c1_b_mn;
  c1_sc_b = c1_q_dot[0];
  c1_bd_y = c1_tb_a * c1_sc_b;
  c1_vd_x = c1_q[0];
  c1_wd_x = c1_vd_x;
  c1_wd_x = muDoubleScalarCos(c1_wd_x);
  c1_ub_a = c1_bd_y;
  c1_tc_b = c1_wd_x;
  c1_cd_y = c1_ub_a * c1_tc_b;
  c1_vb_a = c1_cd_y;
  c1_uc_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_dd_y = c1_vb_a * c1_uc_b;
  c1_xd_x = c1_q[0];
  c1_yd_x = c1_xd_x;
  c1_yd_x = muDoubleScalarSin(c1_yd_x);
  c1_wb_a = c1_dd_y;
  c1_vc_b = c1_yd_x;
  c1_ed_y = c1_wb_a * c1_vc_b;
  c1_i_A = c1_ed_y;
  c1_ae_x = c1_i_A;
  c1_be_x = c1_ae_x;
  c1_fd_y = c1_be_x / 8.0;
  c1_xb_a = c1_b_mn;
  c1_wc_b = c1_q_dot[0];
  c1_gd_y = c1_xb_a * c1_wc_b;
  c1_ce_x = c1_q[0];
  c1_de_x = c1_ce_x;
  c1_de_x = muDoubleScalarSin(c1_de_x);
  c1_yb_a = c1_gd_y;
  c1_xc_b = c1_de_x;
  c1_hd_y = c1_yb_a * c1_xc_b;
  c1_ac_a = c1_hd_y;
  c1_yc_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_id_y = c1_ac_a * c1_yc_b;
  c1_ee_x = c1_q[0];
  c1_fe_x = c1_ee_x;
  c1_fe_x = muDoubleScalarCos(c1_fe_x);
  c1_bc_a = c1_id_y;
  c1_ad_b = c1_fe_x;
  c1_jd_y = c1_bc_a * c1_ad_b;
  c1_j_A = c1_jd_y;
  c1_ge_x = c1_j_A;
  c1_he_x = c1_ge_x;
  c1_kd_y = c1_he_x / 8.0;
  c1_ie_x = c1_q[0];
  c1_je_x = c1_ie_x;
  c1_je_x = muDoubleScalarCos(c1_je_x);
  c1_cc_a = c1_b_mn;
  c1_bd_b = c1_je_x;
  c1_ld_y = c1_cc_a * c1_bd_b;
  c1_dc_a = c1_ld_y;
  c1_cd_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_md_y = c1_dc_a * c1_cd_b;
  c1_ec_a = c1_md_y;
  c1_dd_b = c1_q_dot[0];
  c1_nd_y = c1_ec_a * c1_dd_b;
  c1_ke_x = c1_q[0];
  c1_le_x = c1_ke_x;
  c1_le_x = muDoubleScalarSin(c1_le_x);
  c1_fc_a = c1_nd_y;
  c1_ed_b = c1_le_x;
  c1_od_y = c1_fc_a * c1_ed_b;
  c1_k_A = c1_od_y;
  c1_me_x = c1_k_A;
  c1_ne_x = c1_me_x;
  c1_pd_y = c1_ne_x / 8.0;
  c1_oe_x = c1_q[0];
  c1_pe_x = c1_oe_x;
  c1_pe_x = muDoubleScalarSin(c1_pe_x);
  c1_gc_a = c1_b_mn;
  c1_fd_b = c1_pe_x;
  c1_qd_y = c1_gc_a * c1_fd_b;
  c1_hc_a = c1_qd_y;
  c1_gd_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_rd_y = c1_hc_a * c1_gd_b;
  c1_qe_x = c1_q[0];
  c1_re_x = c1_qe_x;
  c1_re_x = muDoubleScalarCos(c1_re_x);
  c1_ic_a = c1_rd_y;
  c1_hd_b = c1_re_x;
  c1_sd_y = c1_ic_a * c1_hd_b;
  c1_jc_a = c1_sd_y;
  c1_id_b = c1_q_dot[0];
  c1_td_y = c1_jc_a * c1_id_b;
  c1_l_A = c1_td_y;
  c1_se_x = c1_l_A;
  c1_te_x = c1_se_x;
  c1_ud_y = c1_te_x / 8.0;
  c1_ue_x = ((c1_q[0] - c1_q[1]) - c1_q[2]) - c1_q[0];
  c1_ve_x = c1_ue_x;
  c1_ve_x = muDoubleScalarSin(c1_ve_x);
  c1_kc_a = c1_b_mn;
  c1_jd_b = c1_ve_x;
  c1_vd_y = c1_kc_a * c1_jd_b;
  c1_lc_a = c1_vd_y;
  c1_kd_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_wd_y = c1_lc_a * c1_kd_b;
  c1_m_A = c1_wd_y;
  c1_we_x = c1_m_A;
  c1_xe_x = c1_we_x;
  c1_xd_y = c1_xe_x / 2.0;
  c1_ld_b = c1_b_mn;
  c1_yd_y = 3.0 * c1_ld_b;
  c1_ye_x = (c1_q[0] - c1_q[1]) - c1_q[0];
  c1_af_x = c1_ye_x;
  c1_af_x = muDoubleScalarSin(c1_af_x);
  c1_mc_a = c1_yd_y;
  c1_md_b = c1_af_x;
  c1_ae_y = c1_mc_a * c1_md_b;
  c1_nc_a = c1_ae_y;
  c1_nd_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_be_y = c1_nc_a * c1_nd_b;
  c1_n_A = c1_be_y;
  c1_bf_x = c1_n_A;
  c1_cf_x = c1_bf_x;
  c1_ce_y = c1_cf_x / 4.0;
  c1_oc_a = c1_b_mn;
  c1_od_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_de_y = c1_oc_a * c1_od_b;
  c1_df_x = (((c1_q[0] - c1_q[1]) - c1_q[2]) - c1_q[0]) + c1_q[1];
  c1_ef_x = c1_df_x;
  c1_ef_x = muDoubleScalarSin(c1_ef_x);
  c1_pc_a = c1_de_y;
  c1_pd_b = c1_ef_x;
  c1_ee_y = c1_pc_a * c1_pd_b;
  c1_qc_a = c1_ee_y;
  c1_qd_b = (((c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2]) - c1_q_dot[0]) -
    c1_q_dot[1];
  c1_fe_y = c1_qc_a * c1_qd_b;
  c1_o_A = c1_fe_y;
  c1_ff_x = c1_o_A;
  c1_gf_x = c1_ff_x;
  c1_ge_y = c1_gf_x / 4.0;
  c1_hf_x = ((((c1_q[0] - c1_q[1]) - c1_q[2]) - c1_q[0]) + c1_q[1]) + c1_q[2];
  c1_if_x = c1_hf_x;
  c1_if_x = muDoubleScalarSin(c1_if_x);
  c1_rc_a = c1_b_mn;
  c1_rd_b = c1_if_x;
  c1_he_y = c1_rc_a * c1_rd_b;
  c1_sc_a = c1_he_y;
  c1_sd_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_ie_y = c1_sc_a * c1_sd_b;
  c1_tc_a = c1_ie_y;
  c1_td_b = ((((c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2]) - c1_q_dot[0]) -
             c1_q_dot[1]) - c1_q_dot[2];
  c1_je_y = c1_tc_a * c1_td_b;
  c1_p_A = c1_je_y;
  c1_jf_x = c1_p_A;
  c1_kf_x = c1_jf_x;
  c1_ke_y = c1_kf_x / 8.0;
  c1_lf_x = c1_q[0] + c1_q[1];
  c1_mf_x = c1_lf_x;
  c1_mf_x = muDoubleScalarSin(c1_mf_x);
  c1_uc_a = c1_b_mn;
  c1_ud_b = c1_mf_x;
  c1_le_y = c1_uc_a * c1_ud_b;
  c1_vc_a = c1_le_y;
  c1_vd_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_me_y = c1_vc_a * c1_vd_b;
  c1_nf_x = c1_q[0];
  c1_of_x = c1_nf_x;
  c1_of_x = muDoubleScalarCos(c1_of_x);
  c1_wd_b = c1_of_x;
  c1_ne_y = 2.0 * c1_wd_b;
  c1_pf_x = c1_q[0] + c1_q[1];
  c1_qf_x = c1_pf_x;
  c1_qf_x = muDoubleScalarCos(c1_qf_x);
  c1_wc_a = c1_me_y;
  c1_xd_b = c1_ne_y + c1_qf_x;
  c1_oe_y = c1_wc_a * c1_xd_b;
  c1_q_A = c1_oe_y;
  c1_rf_x = c1_q_A;
  c1_sf_x = c1_rf_x;
  c1_pe_y = c1_sf_x / 8.0;
  c1_tf_x = c1_q[0] + c1_q[1];
  c1_uf_x = c1_tf_x;
  c1_uf_x = muDoubleScalarCos(c1_uf_x);
  c1_xc_a = c1_b_mn;
  c1_yd_b = c1_uf_x;
  c1_qe_y = c1_xc_a * c1_yd_b;
  c1_yc_a = c1_qe_y;
  c1_ae_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_re_y = c1_yc_a * c1_ae_b;
  c1_vf_x = c1_q[0];
  c1_wf_x = c1_vf_x;
  c1_wf_x = muDoubleScalarSin(c1_wf_x);
  c1_be_b = c1_wf_x;
  c1_se_y = 2.0 * c1_be_b;
  c1_xf_x = c1_q[0] + c1_q[1];
  c1_yf_x = c1_xf_x;
  c1_yf_x = muDoubleScalarSin(c1_yf_x);
  c1_ad_a = c1_re_y;
  c1_ce_b = c1_se_y + c1_yf_x;
  c1_te_y = c1_ad_a * c1_ce_b;
  c1_r_A = c1_te_y;
  c1_ag_x = c1_r_A;
  c1_bg_x = c1_ag_x;
  c1_ue_y = c1_bg_x / 8.0;
  c1_bd_a = c1_b_mn;
  c1_de_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_ve_y = c1_bd_a * c1_de_b;
  c1_cg_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_dg_x = c1_cg_x;
  c1_dg_x = muDoubleScalarSin(c1_dg_x);
  c1_eg_x = c1_q[0] + c1_q[1];
  c1_fg_x = c1_eg_x;
  c1_fg_x = muDoubleScalarSin(c1_fg_x);
  c1_ee_b = c1_fg_x;
  c1_we_y = 2.0 * c1_ee_b;
  c1_cd_a = c1_ve_y;
  c1_fe_b = c1_dg_x + c1_we_y;
  c1_xe_y = c1_cd_a * c1_fe_b;
  c1_gg_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_hg_x = c1_gg_x;
  c1_hg_x = muDoubleScalarCos(c1_hg_x);
  c1_ig_x = c1_q[0] + c1_q[1];
  c1_jg_x = c1_ig_x;
  c1_jg_x = muDoubleScalarCos(c1_jg_x);
  c1_ge_b = c1_jg_x;
  c1_ye_y = 2.0 * c1_ge_b;
  c1_kg_x = c1_q[0];
  c1_lg_x = c1_kg_x;
  c1_lg_x = muDoubleScalarCos(c1_lg_x);
  c1_he_b = c1_lg_x;
  c1_af_y = 2.0 * c1_he_b;
  c1_dd_a = c1_xe_y;
  c1_ie_b = (c1_hg_x + c1_ye_y) + c1_af_y;
  c1_bf_y = c1_dd_a * c1_ie_b;
  c1_s_A = c1_bf_y;
  c1_mg_x = c1_s_A;
  c1_ng_x = c1_mg_x;
  c1_cf_y = c1_ng_x / 8.0;
  c1_ed_a = c1_b_mn;
  c1_je_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_df_y = c1_ed_a * c1_je_b;
  c1_og_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_pg_x = c1_og_x;
  c1_pg_x = muDoubleScalarCos(c1_pg_x);
  c1_qg_x = c1_q[0] + c1_q[1];
  c1_rg_x = c1_qg_x;
  c1_rg_x = muDoubleScalarCos(c1_rg_x);
  c1_ke_b = c1_rg_x;
  c1_ef_y = 2.0 * c1_ke_b;
  c1_fd_a = c1_df_y;
  c1_le_b = c1_pg_x + c1_ef_y;
  c1_ff_y = c1_fd_a * c1_le_b;
  c1_sg_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_tg_x = c1_sg_x;
  c1_tg_x = muDoubleScalarSin(c1_tg_x);
  c1_ug_x = c1_q[0] + c1_q[1];
  c1_vg_x = c1_ug_x;
  c1_vg_x = muDoubleScalarSin(c1_vg_x);
  c1_me_b = c1_vg_x;
  c1_gf_y = 2.0 * c1_me_b;
  c1_wg_x = c1_q[0];
  c1_xg_x = c1_wg_x;
  c1_xg_x = muDoubleScalarSin(c1_xg_x);
  c1_ne_b = c1_xg_x;
  c1_hf_y = 2.0 * c1_ne_b;
  c1_gd_a = c1_ff_y;
  c1_oe_b = (c1_tg_x + c1_gf_y) + c1_hf_y;
  c1_if_y = c1_gd_a * c1_oe_b;
  c1_t_A = c1_if_y;
  c1_yg_x = c1_t_A;
  c1_ah_x = c1_yg_x;
  c1_jf_y = c1_ah_x / 8.0;
  c1_hd_a = c1_b_mn;
  c1_pe_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_kf_y = c1_hd_a * c1_pe_b;
  c1_bh_x = (((c1_q[0] - c1_q[1]) - c1_q[0]) + c1_q[1]) + c1_q[2];
  c1_ch_x = c1_bh_x;
  c1_ch_x = muDoubleScalarSin(c1_ch_x);
  c1_id_a = c1_kf_y;
  c1_qe_b = c1_ch_x;
  c1_lf_y = c1_id_a * c1_qe_b;
  c1_jd_a = c1_lf_y;
  c1_re_b = (((c1_q_dot[0] - c1_q_dot[1]) - c1_q_dot[0]) + c1_q_dot[1]) +
    c1_q_dot[2];
  c1_mf_y = c1_jd_a * c1_re_b;
  c1_u_A = c1_mf_y;
  c1_dh_x = c1_u_A;
  c1_eh_x = c1_dh_x;
  c1_nf_y = c1_eh_x / 4.0;
  c1_kd_a = c1_b_mn;
  c1_se_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_of_y = c1_kd_a * c1_se_b;
  c1_fh_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_gh_x = c1_fh_x;
  c1_gh_x = muDoubleScalarSin(c1_gh_x);
  c1_hh_x = c1_q[0] + c1_q[1];
  c1_ih_x = c1_hh_x;
  c1_ih_x = muDoubleScalarSin(c1_ih_x);
  c1_te_b = c1_ih_x;
  c1_pf_y = 2.0 * c1_te_b;
  c1_ld_a = c1_of_y;
  c1_ue_b = c1_gh_x + c1_pf_y;
  c1_qf_y = c1_ld_a * c1_ue_b;
  c1_jh_x = c1_q[0];
  c1_kh_x = c1_jh_x;
  c1_kh_x = muDoubleScalarCos(c1_kh_x);
  c1_ve_b = c1_kh_x;
  c1_rf_y = 2.0 * c1_ve_b;
  c1_lh_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_mh_x = c1_lh_x;
  c1_mh_x = muDoubleScalarCos(c1_mh_x);
  c1_nh_x = c1_q[0] + c1_q[1];
  c1_oh_x = c1_nh_x;
  c1_oh_x = muDoubleScalarCos(c1_oh_x);
  c1_we_b = c1_oh_x;
  c1_sf_y = 2.0 * c1_we_b;
  c1_md_a = c1_qf_y;
  c1_xe_b = (c1_rf_y + c1_mh_x) + c1_sf_y;
  c1_tf_y = c1_md_a * c1_xe_b;
  c1_v_A = c1_tf_y;
  c1_ph_x = c1_v_A;
  c1_qh_x = c1_ph_x;
  c1_uf_y = c1_qh_x / 8.0;
  c1_nd_a = c1_b_mn;
  c1_ye_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_vf_y = c1_nd_a * c1_ye_b;
  c1_rh_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_sh_x = c1_rh_x;
  c1_sh_x = muDoubleScalarCos(c1_sh_x);
  c1_th_x = c1_q[0] + c1_q[1];
  c1_uh_x = c1_th_x;
  c1_uh_x = muDoubleScalarCos(c1_uh_x);
  c1_af_b = c1_uh_x;
  c1_wf_y = 2.0 * c1_af_b;
  c1_od_a = c1_vf_y;
  c1_bf_b = c1_sh_x + c1_wf_y;
  c1_xf_y = c1_od_a * c1_bf_b;
  c1_vh_x = c1_q[0];
  c1_wh_x = c1_vh_x;
  c1_wh_x = muDoubleScalarSin(c1_wh_x);
  c1_cf_b = c1_wh_x;
  c1_yf_y = 2.0 * c1_cf_b;
  c1_xh_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_yh_x = c1_xh_x;
  c1_yh_x = muDoubleScalarSin(c1_yh_x);
  c1_ai_x = c1_q[0] + c1_q[1];
  c1_bi_x = c1_ai_x;
  c1_bi_x = muDoubleScalarSin(c1_bi_x);
  c1_df_b = c1_bi_x;
  c1_ag_y = 2.0 * c1_df_b;
  c1_pd_a = c1_xf_y;
  c1_ef_b = (c1_yf_y + c1_yh_x) + c1_ag_y;
  c1_bg_y = c1_pd_a * c1_ef_b;
  c1_w_A = c1_bg_y;
  c1_ci_x = c1_w_A;
  c1_di_x = c1_ci_x;
  c1_cg_y = c1_di_x / 8.0;
  c1_ei_x = c1_q[0] + c1_q[1];
  c1_fi_x = c1_ei_x;
  c1_fi_x = muDoubleScalarSin(c1_fi_x);
  c1_qd_a = c1_b_mn;
  c1_ff_b = c1_fi_x;
  c1_dg_y = c1_qd_a * c1_ff_b;
  c1_rd_a = c1_dg_y;
  c1_gf_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_eg_y = c1_rd_a * c1_gf_b;
  c1_gi_x = c1_q[0] + c1_q[1];
  c1_hi_x = c1_gi_x;
  c1_hi_x = muDoubleScalarCos(c1_hi_x);
  c1_ii_x = c1_q[0];
  c1_ji_x = c1_ii_x;
  c1_ji_x = muDoubleScalarCos(c1_ji_x);
  c1_hf_b = c1_ji_x;
  c1_fg_y = 2.0 * c1_hf_b;
  c1_sd_a = c1_eg_y;
  c1_if_b = c1_hi_x + c1_fg_y;
  c1_gg_y = c1_sd_a * c1_if_b;
  c1_x_A = c1_gg_y;
  c1_ki_x = c1_x_A;
  c1_li_x = c1_ki_x;
  c1_hg_y = c1_li_x / 8.0;
  c1_jf_b = c1_b_mn;
  c1_ig_y = 3.0 * c1_jf_b;
  c1_mi_x = (c1_q[0] - c1_q[1]) - c1_q[0];
  c1_ni_x = c1_mi_x;
  c1_ni_x = muDoubleScalarSin(c1_ni_x);
  c1_td_a = c1_ig_y;
  c1_kf_b = c1_ni_x;
  c1_jg_y = c1_td_a * c1_kf_b;
  c1_ud_a = c1_jg_y;
  c1_lf_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_kg_y = c1_ud_a * c1_lf_b;
  c1_vd_a = c1_kg_y;
  c1_mf_b = (c1_q_dot[0] + c1_q_dot[1]) - c1_q_dot[0];
  c1_lg_y = c1_vd_a * c1_mf_b;
  c1_y_A = c1_lg_y;
  c1_oi_x = c1_y_A;
  c1_pi_x = c1_oi_x;
  c1_mg_y = c1_pi_x / 4.0;
  c1_qi_x = c1_q[0] + c1_q[1];
  c1_ri_x = c1_qi_x;
  c1_ri_x = muDoubleScalarCos(c1_ri_x);
  c1_wd_a = c1_b_mn;
  c1_nf_b = c1_ri_x;
  c1_ng_y = c1_wd_a * c1_nf_b;
  c1_xd_a = c1_ng_y;
  c1_of_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_og_y = c1_xd_a * c1_of_b;
  c1_si_x = c1_q[0] + c1_q[1];
  c1_ti_x = c1_si_x;
  c1_ti_x = muDoubleScalarSin(c1_ti_x);
  c1_ui_x = c1_q[0];
  c1_vi_x = c1_ui_x;
  c1_vi_x = muDoubleScalarSin(c1_vi_x);
  c1_pf_b = c1_vi_x;
  c1_pg_y = 2.0 * c1_pf_b;
  c1_yd_a = c1_og_y;
  c1_qf_b = c1_ti_x + c1_pg_y;
  c1_qg_y = c1_yd_a * c1_qf_b;
  c1_ab_A = c1_qg_y;
  c1_wi_x = c1_ab_A;
  c1_xi_x = c1_wi_x;
  c1_rg_y = c1_xi_x / 8.0;
  c1_rf_b = c1_b_mn;
  c1_sg_y = 5.0 * c1_rf_b;
  c1_yi_x = ((c1_q[0] - c1_q[1]) - c1_q[0]) + c1_q[1];
  c1_aj_x = c1_yi_x;
  c1_aj_x = muDoubleScalarSin(c1_aj_x);
  c1_ae_a = c1_sg_y;
  c1_sf_b = c1_aj_x;
  c1_tg_y = c1_ae_a * c1_sf_b;
  c1_be_a = c1_tg_y;
  c1_tf_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_ug_y = c1_be_a * c1_tf_b;
  c1_ce_a = c1_ug_y;
  c1_uf_b = ((c1_q_dot[0] + c1_q_dot[1]) - c1_q_dot[0]) - c1_q_dot[1];
  c1_vg_y = c1_ce_a * c1_uf_b;
  c1_bb_A = c1_vg_y;
  c1_bj_x = c1_bb_A;
  c1_cj_x = c1_bj_x;
  c1_wg_y = c1_cj_x / 8.0;
  c1_dj_x = ((c1_q[0] - c1_q[1]) - c1_q[2]) - c1_q[0];
  c1_ej_x = c1_dj_x;
  c1_ej_x = muDoubleScalarSin(c1_ej_x);
  c1_de_a = c1_b_mn;
  c1_vf_b = c1_ej_x;
  c1_xg_y = c1_de_a * c1_vf_b;
  c1_ee_a = c1_xg_y;
  c1_wf_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_yg_y = c1_ee_a * c1_wf_b;
  c1_fe_a = c1_yg_y;
  c1_xf_b = ((c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2]) - c1_q_dot[0];
  c1_ah_y = c1_fe_a * c1_xf_b;
  c1_cb_A = c1_ah_y;
  c1_fj_x = c1_cb_A;
  c1_gj_x = c1_fj_x;
  c1_bh_y = c1_gj_x / 4.0;
  c1_hj_x = ((c1_q[0] - c1_q[1]) - c1_q[2]) - c1_q[0];
  c1_ij_x = c1_hj_x;
  c1_ij_x = muDoubleScalarSin(c1_ij_x);
  c1_ge_a = c1_b_mn;
  c1_yf_b = c1_ij_x;
  c1_ch_y = c1_ge_a * c1_yf_b;
  c1_he_a = c1_ch_y;
  c1_ag_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_dh_y = c1_he_a * c1_ag_b;
  c1_db_A = c1_dh_y;
  c1_jj_x = c1_db_A;
  c1_kj_x = c1_jj_x;
  c1_eh_y = c1_kj_x / 4.0;
  c1_ie_a = c1_b_mn;
  c1_bg_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_fh_y = c1_ie_a * c1_bg_b;
  c1_lj_x = ((c1_q[0] - c1_q[1]) - c1_q[2]) - c1_q[0];
  c1_mj_x = c1_lj_x;
  c1_mj_x = muDoubleScalarSin(c1_mj_x);
  c1_cg_b = c1_mj_x;
  c1_gh_y = 2.0 * c1_cg_b;
  c1_nj_x = (((c1_q[0] - c1_q[1]) - c1_q[2]) - c1_q[0]) + c1_q[1];
  c1_oj_x = c1_nj_x;
  c1_oj_x = muDoubleScalarSin(c1_oj_x);
  c1_dg_b = c1_oj_x;
  c1_hh_y = 2.0 * c1_dg_b;
  c1_je_a = c1_fh_y;
  c1_eg_b = c1_gh_y + c1_hh_y;
  c1_ih_y = c1_je_a * c1_eg_b;
  c1_eb_A = c1_ih_y;
  c1_pj_x = c1_eb_A;
  c1_qj_x = c1_pj_x;
  c1_jh_y = c1_qj_x / 8.0;
  c1_ke_a = c1_b_mn;
  c1_fg_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_kh_y = c1_ke_a * c1_fg_b;
  c1_rj_x = ((c1_q[0] - c1_q[1]) - c1_q[2]) - c1_q[0];
  c1_sj_x = c1_rj_x;
  c1_sj_x = muDoubleScalarSin(c1_sj_x);
  c1_gg_b = c1_sj_x;
  c1_lh_y = 2.0 * c1_gg_b;
  c1_le_a = c1_lh_y;
  c1_hg_b = ((c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2]) - c1_q_dot[0];
  c1_mh_y = c1_le_a * c1_hg_b;
  c1_tj_x = (((c1_q[0] - c1_q[1]) - c1_q[2]) - c1_q[0]) + c1_q[1];
  c1_uj_x = c1_tj_x;
  c1_uj_x = muDoubleScalarSin(c1_uj_x);
  c1_ig_b = c1_uj_x;
  c1_nh_y = 2.0 * c1_ig_b;
  c1_me_a = c1_nh_y;
  c1_jg_b = (((c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2]) - c1_q_dot[0]) -
    c1_q_dot[1];
  c1_oh_y = c1_me_a * c1_jg_b;
  c1_vj_x = ((((c1_q[0] - c1_q[1]) - c1_q[2]) - c1_q[0]) + c1_q[1]) + c1_q[2];
  c1_wj_x = c1_vj_x;
  c1_wj_x = muDoubleScalarSin(c1_wj_x);
  c1_ne_a = c1_wj_x;
  c1_kg_b = ((((c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2]) - c1_q_dot[0]) -
             c1_q_dot[1]) - c1_q_dot[2];
  c1_ph_y = c1_ne_a * c1_kg_b;
  c1_oe_a = c1_kh_y;
  c1_lg_b = (c1_mh_y + c1_oh_y) + c1_ph_y;
  c1_qh_y = c1_oe_a * c1_lg_b;
  c1_fb_A = c1_qh_y;
  c1_xj_x = c1_fb_A;
  c1_yj_x = c1_xj_x;
  c1_rh_y = c1_yj_x / 8.0;
  c1_pe_a = c1_b_mn;
  c1_mg_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_sh_y = c1_pe_a * c1_mg_b;
  c1_ak_x = (((c1_q[0] - c1_q[1]) - c1_q[2]) - c1_q[0]) + c1_q[1];
  c1_bk_x = c1_ak_x;
  c1_bk_x = muDoubleScalarSin(c1_bk_x);
  c1_qe_a = c1_sh_y;
  c1_ng_b = c1_bk_x;
  c1_th_y = c1_qe_a * c1_ng_b;
  c1_gb_A = c1_th_y;
  c1_ck_x = c1_gb_A;
  c1_dk_x = c1_ck_x;
  c1_uh_y = c1_dk_x / 4.0;
  c1_re_a = c1_b_mn;
  c1_og_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_vh_y = c1_re_a * c1_og_b;
  c1_ek_x = (((c1_q[0] - c1_q[1]) - c1_q[0]) + c1_q[1]) + c1_q[2];
  c1_fk_x = c1_ek_x;
  c1_fk_x = muDoubleScalarSin(c1_fk_x);
  c1_se_a = c1_vh_y;
  c1_pg_b = c1_fk_x;
  c1_wh_y = c1_se_a * c1_pg_b;
  c1_hb_A = c1_wh_y;
  c1_gk_x = c1_hb_A;
  c1_hk_x = c1_gk_x;
  c1_xh_y = c1_hk_x / 4.0;
  c1_ik_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_jk_x = c1_ik_x;
  c1_jk_x = muDoubleScalarCos(c1_jk_x);
  c1_te_a = c1_b_mn;
  c1_qg_b = c1_jk_x;
  c1_yh_y = c1_te_a * c1_qg_b;
  c1_ue_a = c1_yh_y;
  c1_rg_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_ai_y = c1_ue_a * c1_rg_b;
  c1_kk_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_lk_x = c1_kk_x;
  c1_lk_x = muDoubleScalarSin(c1_lk_x);
  c1_mk_x = c1_q[0] + c1_q[1];
  c1_nk_x = c1_mk_x;
  c1_nk_x = muDoubleScalarSin(c1_nk_x);
  c1_sg_b = c1_nk_x;
  c1_bi_y = 2.0 * c1_sg_b;
  c1_ok_x = c1_q[0];
  c1_pk_x = c1_ok_x;
  c1_pk_x = muDoubleScalarSin(c1_pk_x);
  c1_tg_b = c1_pk_x;
  c1_ci_y = 2.0 * c1_tg_b;
  c1_ve_a = c1_ai_y;
  c1_ug_b = (c1_lk_x + c1_bi_y) + c1_ci_y;
  c1_di_y = c1_ve_a * c1_ug_b;
  c1_ib_A = c1_di_y;
  c1_qk_x = c1_ib_A;
  c1_rk_x = c1_qk_x;
  c1_ei_y = c1_rk_x / 8.0;
  c1_sk_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_tk_x = c1_sk_x;
  c1_tk_x = muDoubleScalarSin(c1_tk_x);
  c1_we_a = c1_b_mn;
  c1_vg_b = c1_tk_x;
  c1_fi_y = c1_we_a * c1_vg_b;
  c1_xe_a = c1_fi_y;
  c1_wg_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_gi_y = c1_xe_a * c1_wg_b;
  c1_uk_x = c1_q[0];
  c1_vk_x = c1_uk_x;
  c1_vk_x = muDoubleScalarCos(c1_vk_x);
  c1_xg_b = c1_vk_x;
  c1_hi_y = 2.0 * c1_xg_b;
  c1_wk_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_xk_x = c1_wk_x;
  c1_xk_x = muDoubleScalarCos(c1_xk_x);
  c1_yk_x = c1_q[0] + c1_q[1];
  c1_al_x = c1_yk_x;
  c1_al_x = muDoubleScalarCos(c1_al_x);
  c1_yg_b = c1_al_x;
  c1_ii_y = 2.0 * c1_yg_b;
  c1_ye_a = c1_gi_y;
  c1_ah_b = (c1_hi_y + c1_xk_x) + c1_ii_y;
  c1_ji_y = c1_ye_a * c1_ah_b;
  c1_jb_A = c1_ji_y;
  c1_bl_x = c1_jb_A;
  c1_cl_x = c1_bl_x;
  c1_ki_y = c1_cl_x / 8.0;
  c1_dl_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_el_x = c1_dl_x;
  c1_el_x = muDoubleScalarCos(c1_el_x);
  c1_af_a = c1_b_mn;
  c1_bh_b = c1_el_x;
  c1_li_y = c1_af_a * c1_bh_b;
  c1_bf_a = c1_li_y;
  c1_ch_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_mi_y = c1_bf_a * c1_ch_b;
  c1_fl_x = c1_q[0];
  c1_gl_x = c1_fl_x;
  c1_gl_x = muDoubleScalarSin(c1_gl_x);
  c1_dh_b = c1_gl_x;
  c1_ni_y = 2.0 * c1_dh_b;
  c1_hl_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_il_x = c1_hl_x;
  c1_il_x = muDoubleScalarSin(c1_il_x);
  c1_jl_x = c1_q[0] + c1_q[1];
  c1_kl_x = c1_jl_x;
  c1_kl_x = muDoubleScalarSin(c1_kl_x);
  c1_eh_b = c1_kl_x;
  c1_oi_y = 2.0 * c1_eh_b;
  c1_cf_a = c1_mi_y;
  c1_fh_b = (c1_ni_y + c1_il_x) + c1_oi_y;
  c1_pi_y = c1_cf_a * c1_fh_b;
  c1_kb_A = c1_pi_y;
  c1_ll_x = c1_kb_A;
  c1_ml_x = c1_ll_x;
  c1_qi_y = c1_ml_x / 8.0;
  c1_nl_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_ol_x = c1_nl_x;
  c1_ol_x = muDoubleScalarSin(c1_ol_x);
  c1_df_a = c1_b_mn;
  c1_gh_b = c1_ol_x;
  c1_ri_y = c1_df_a * c1_gh_b;
  c1_ef_a = c1_ri_y;
  c1_hh_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_si_y = c1_ef_a * c1_hh_b;
  c1_pl_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_ql_x = c1_pl_x;
  c1_ql_x = muDoubleScalarCos(c1_ql_x);
  c1_rl_x = c1_q[0] + c1_q[1];
  c1_sl_x = c1_rl_x;
  c1_sl_x = muDoubleScalarCos(c1_sl_x);
  c1_ih_b = c1_sl_x;
  c1_ti_y = 2.0 * c1_ih_b;
  c1_tl_x = c1_q[0];
  c1_ul_x = c1_tl_x;
  c1_ul_x = muDoubleScalarCos(c1_ul_x);
  c1_jh_b = c1_ul_x;
  c1_ui_y = 2.0 * c1_jh_b;
  c1_ff_a = c1_si_y;
  c1_kh_b = (c1_ql_x + c1_ti_y) + c1_ui_y;
  c1_vi_y = c1_ff_a * c1_kh_b;
  c1_lb_A = c1_vi_y;
  c1_vl_x = c1_lb_A;
  c1_wl_x = c1_vl_x;
  c1_wi_y = c1_wl_x / 8.0;
  c1_xl_x = ((c1_q[0] - c1_q[1]) - c1_q[2]) - c1_q[0];
  c1_yl_x = c1_xl_x;
  c1_yl_x = muDoubleScalarSin(c1_yl_x);
  c1_gf_a = c1_b_mn;
  c1_lh_b = c1_yl_x;
  c1_xi_y = c1_gf_a * c1_lh_b;
  c1_hf_a = c1_xi_y;
  c1_mh_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_yi_y = c1_hf_a * c1_mh_b;
  c1_mb_A = c1_yi_y;
  c1_am_x = c1_mb_A;
  c1_bm_x = c1_am_x;
  c1_aj_y = c1_bm_x / 2.0;
  c1_nh_b = c1_b_mn;
  c1_bj_y = 3.0 * c1_nh_b;
  c1_cm_x = (c1_q[0] - c1_q[1]) - c1_q[0];
  c1_dm_x = c1_cm_x;
  c1_dm_x = muDoubleScalarSin(c1_dm_x);
  c1_if_a = c1_bj_y;
  c1_oh_b = c1_dm_x;
  c1_cj_y = c1_if_a * c1_oh_b;
  c1_jf_a = c1_cj_y;
  c1_ph_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_dj_y = c1_jf_a * c1_ph_b;
  c1_nb_A = c1_dj_y;
  c1_em_x = c1_nb_A;
  c1_fm_x = c1_em_x;
  c1_ej_y = c1_fm_x / 4.0;
  c1_kf_a = c1_b_mn;
  c1_qh_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_fj_y = c1_kf_a * c1_qh_b;
  c1_gm_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_hm_x = c1_gm_x;
  c1_hm_x = muDoubleScalarCos(c1_hm_x);
  c1_im_x = c1_q[0] + c1_q[1];
  c1_jm_x = c1_im_x;
  c1_jm_x = muDoubleScalarCos(c1_jm_x);
  c1_rh_b = c1_jm_x;
  c1_gj_y = 2.0 * c1_rh_b;
  c1_lf_a = c1_fj_y;
  c1_sh_b = c1_hm_x + c1_gj_y;
  c1_hj_y = c1_lf_a * c1_sh_b;
  c1_km_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_lm_x = c1_km_x;
  c1_lm_x = muDoubleScalarSin(c1_lm_x);
  c1_mf_a = c1_lm_x;
  c1_th_b = (c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2];
  c1_ij_y = c1_mf_a * c1_th_b;
  c1_mm_x = c1_q[0] + c1_q[1];
  c1_nm_x = c1_mm_x;
  c1_nm_x = muDoubleScalarSin(c1_nm_x);
  c1_uh_b = c1_nm_x;
  c1_jj_y = 2.0 * c1_uh_b;
  c1_nf_a = c1_jj_y;
  c1_vh_b = c1_q_dot[0] + c1_q_dot[1];
  c1_kj_y = c1_nf_a * c1_vh_b;
  c1_wh_b = c1_q_dot[0];
  c1_lj_y = 2.0 * c1_wh_b;
  c1_om_x = c1_q[0];
  c1_pm_x = c1_om_x;
  c1_pm_x = muDoubleScalarSin(c1_pm_x);
  c1_of_a = c1_lj_y;
  c1_xh_b = c1_pm_x;
  c1_mj_y = c1_of_a * c1_xh_b;
  c1_pf_a = c1_hj_y;
  c1_yh_b = (c1_ij_y + c1_kj_y) + c1_mj_y;
  c1_nj_y = c1_pf_a * c1_yh_b;
  c1_ob_A = c1_nj_y;
  c1_qm_x = c1_ob_A;
  c1_rm_x = c1_qm_x;
  c1_oj_y = c1_rm_x / 8.0;
  c1_sm_x = c1_q[0] + c1_q[1];
  c1_tm_x = c1_sm_x;
  c1_tm_x = muDoubleScalarSin(c1_tm_x);
  c1_qf_a = c1_b_mn;
  c1_ai_b = c1_tm_x;
  c1_pj_y = c1_qf_a * c1_ai_b;
  c1_rf_a = c1_pj_y;
  c1_bi_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_qj_y = c1_rf_a * c1_bi_b;
  c1_um_x = c1_q[0];
  c1_vm_x = c1_um_x;
  c1_vm_x = muDoubleScalarCos(c1_vm_x);
  c1_ci_b = c1_vm_x;
  c1_rj_y = 2.0 * c1_ci_b;
  c1_wm_x = c1_q[0] + c1_q[1];
  c1_xm_x = c1_wm_x;
  c1_xm_x = muDoubleScalarCos(c1_xm_x);
  c1_sf_a = c1_qj_y;
  c1_di_b = c1_rj_y + c1_xm_x;
  c1_sj_y = c1_sf_a * c1_di_b;
  c1_pb_A = c1_sj_y;
  c1_ym_x = c1_pb_A;
  c1_an_x = c1_ym_x;
  c1_tj_y = c1_an_x / 8.0;
  c1_bn_x = c1_q[0] + c1_q[1];
  c1_cn_x = c1_bn_x;
  c1_cn_x = muDoubleScalarCos(c1_cn_x);
  c1_tf_a = c1_b_mn;
  c1_ei_b = c1_cn_x;
  c1_uj_y = c1_tf_a * c1_ei_b;
  c1_uf_a = c1_uj_y;
  c1_fi_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_vj_y = c1_uf_a * c1_fi_b;
  c1_dn_x = c1_q[0];
  c1_en_x = c1_dn_x;
  c1_en_x = muDoubleScalarSin(c1_en_x);
  c1_gi_b = c1_en_x;
  c1_wj_y = 2.0 * c1_gi_b;
  c1_fn_x = c1_q[0] + c1_q[1];
  c1_gn_x = c1_fn_x;
  c1_gn_x = muDoubleScalarSin(c1_gn_x);
  c1_vf_a = c1_vj_y;
  c1_hi_b = c1_wj_y + c1_gn_x;
  c1_xj_y = c1_vf_a * c1_hi_b;
  c1_qb_A = c1_xj_y;
  c1_hn_x = c1_qb_A;
  c1_in_x = c1_hn_x;
  c1_yj_y = c1_in_x / 8.0;
  c1_wf_a = c1_b_mn;
  c1_ii_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_ak_y = c1_wf_a * c1_ii_b;
  c1_jn_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_kn_x = c1_jn_x;
  c1_kn_x = muDoubleScalarSin(c1_kn_x);
  c1_ln_x = c1_q[0] + c1_q[1];
  c1_mn_x = c1_ln_x;
  c1_mn_x = muDoubleScalarSin(c1_mn_x);
  c1_ji_b = c1_mn_x;
  c1_bk_y = 2.0 * c1_ji_b;
  c1_xf_a = c1_ak_y;
  c1_ki_b = c1_kn_x + c1_bk_y;
  c1_ck_y = c1_xf_a * c1_ki_b;
  c1_nn_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_on_x = c1_nn_x;
  c1_on_x = muDoubleScalarCos(c1_on_x);
  c1_pn_x = c1_q[0] + c1_q[1];
  c1_qn_x = c1_pn_x;
  c1_qn_x = muDoubleScalarCos(c1_qn_x);
  c1_li_b = c1_qn_x;
  c1_dk_y = 2.0 * c1_li_b;
  c1_rn_x = c1_q[0];
  c1_sn_x = c1_rn_x;
  c1_sn_x = muDoubleScalarCos(c1_sn_x);
  c1_mi_b = c1_sn_x;
  c1_ek_y = 2.0 * c1_mi_b;
  c1_yf_a = c1_ck_y;
  c1_ni_b = (c1_on_x + c1_dk_y) + c1_ek_y;
  c1_fk_y = c1_yf_a * c1_ni_b;
  c1_rb_A = c1_fk_y;
  c1_tn_x = c1_rb_A;
  c1_un_x = c1_tn_x;
  c1_gk_y = c1_un_x / 8.0;
  c1_ag_a = c1_b_mn;
  c1_oi_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_hk_y = c1_ag_a * c1_oi_b;
  c1_vn_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_wn_x = c1_vn_x;
  c1_wn_x = muDoubleScalarCos(c1_wn_x);
  c1_xn_x = c1_q[0] + c1_q[1];
  c1_yn_x = c1_xn_x;
  c1_yn_x = muDoubleScalarCos(c1_yn_x);
  c1_pi_b = c1_yn_x;
  c1_ik_y = 2.0 * c1_pi_b;
  c1_bg_a = c1_hk_y;
  c1_qi_b = c1_wn_x + c1_ik_y;
  c1_jk_y = c1_bg_a * c1_qi_b;
  c1_ao_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_bo_x = c1_ao_x;
  c1_bo_x = muDoubleScalarSin(c1_bo_x);
  c1_co_x = c1_q[0] + c1_q[1];
  c1_do_x = c1_co_x;
  c1_do_x = muDoubleScalarSin(c1_do_x);
  c1_ri_b = c1_do_x;
  c1_kk_y = 2.0 * c1_ri_b;
  c1_eo_x = c1_q[0];
  c1_fo_x = c1_eo_x;
  c1_fo_x = muDoubleScalarSin(c1_fo_x);
  c1_si_b = c1_fo_x;
  c1_lk_y = 2.0 * c1_si_b;
  c1_cg_a = c1_jk_y;
  c1_ti_b = (c1_bo_x + c1_kk_y) + c1_lk_y;
  c1_mk_y = c1_cg_a * c1_ti_b;
  c1_sb_A = c1_mk_y;
  c1_go_x = c1_sb_A;
  c1_ho_x = c1_go_x;
  c1_nk_y = c1_ho_x / 8.0;
  c1_dg_a = c1_b_mn;
  c1_ui_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_ok_y = c1_dg_a * c1_ui_b;
  c1_io_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_jo_x = c1_io_x;
  c1_jo_x = muDoubleScalarSin(c1_jo_x);
  c1_eg_a = c1_jo_x;
  c1_vi_b = (c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2];
  c1_pk_y = c1_eg_a * c1_vi_b;
  c1_ko_x = c1_q[0] + c1_q[1];
  c1_lo_x = c1_ko_x;
  c1_lo_x = muDoubleScalarSin(c1_lo_x);
  c1_wi_b = c1_lo_x;
  c1_qk_y = 2.0 * c1_wi_b;
  c1_fg_a = c1_qk_y;
  c1_xi_b = c1_q_dot[0] + c1_q_dot[1];
  c1_rk_y = c1_fg_a * c1_xi_b;
  c1_gg_a = c1_ok_y;
  c1_yi_b = c1_pk_y + c1_rk_y;
  c1_sk_y = c1_gg_a * c1_yi_b;
  c1_mo_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_no_x = c1_mo_x;
  c1_no_x = muDoubleScalarCos(c1_no_x);
  c1_oo_x = c1_q[0] + c1_q[1];
  c1_po_x = c1_oo_x;
  c1_po_x = muDoubleScalarCos(c1_po_x);
  c1_aj_b = c1_po_x;
  c1_tk_y = 2.0 * c1_aj_b;
  c1_qo_x = c1_q[0];
  c1_ro_x = c1_qo_x;
  c1_ro_x = muDoubleScalarCos(c1_ro_x);
  c1_bj_b = c1_ro_x;
  c1_uk_y = 2.0 * c1_bj_b;
  c1_hg_a = c1_sk_y;
  c1_cj_b = (c1_no_x + c1_tk_y) + c1_uk_y;
  c1_vk_y = c1_hg_a * c1_cj_b;
  c1_tb_A = c1_vk_y;
  c1_so_x = c1_tb_A;
  c1_to_x = c1_so_x;
  c1_wk_y = c1_to_x / 8.0;
  c1_ig_a = c1_b_mn;
  c1_dj_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_xk_y = c1_ig_a * c1_dj_b;
  c1_uo_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_vo_x = c1_uo_x;
  c1_vo_x = muDoubleScalarCos(c1_vo_x);
  c1_jg_a = c1_vo_x;
  c1_ej_b = (c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2];
  c1_yk_y = c1_jg_a * c1_ej_b;
  c1_wo_x = c1_q[0] + c1_q[1];
  c1_xo_x = c1_wo_x;
  c1_xo_x = muDoubleScalarCos(c1_xo_x);
  c1_fj_b = c1_xo_x;
  c1_al_y = 2.0 * c1_fj_b;
  c1_kg_a = c1_al_y;
  c1_gj_b = c1_q_dot[0] + c1_q_dot[1];
  c1_bl_y = c1_kg_a * c1_gj_b;
  c1_lg_a = c1_xk_y;
  c1_hj_b = c1_yk_y + c1_bl_y;
  c1_cl_y = c1_lg_a * c1_hj_b;
  c1_yo_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_ap_x = c1_yo_x;
  c1_ap_x = muDoubleScalarSin(c1_ap_x);
  c1_bp_x = c1_q[0] + c1_q[1];
  c1_cp_x = c1_bp_x;
  c1_cp_x = muDoubleScalarSin(c1_cp_x);
  c1_ij_b = c1_cp_x;
  c1_dl_y = 2.0 * c1_ij_b;
  c1_dp_x = c1_q[0];
  c1_ep_x = c1_dp_x;
  c1_ep_x = muDoubleScalarSin(c1_ep_x);
  c1_jj_b = c1_ep_x;
  c1_el_y = 2.0 * c1_jj_b;
  c1_mg_a = c1_cl_y;
  c1_kj_b = (c1_ap_x + c1_dl_y) + c1_el_y;
  c1_fl_y = c1_mg_a * c1_kj_b;
  c1_ub_A = c1_fl_y;
  c1_fp_x = c1_ub_A;
  c1_gp_x = c1_fp_x;
  c1_gl_y = c1_gp_x / 8.0;
  c1_ng_a = c1_b_mn;
  c1_lj_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_hl_y = c1_ng_a * c1_lj_b;
  c1_hp_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_ip_x = c1_hp_x;
  c1_ip_x = muDoubleScalarSin(c1_ip_x);
  c1_jp_x = c1_q[0] + c1_q[1];
  c1_kp_x = c1_jp_x;
  c1_kp_x = muDoubleScalarSin(c1_kp_x);
  c1_mj_b = c1_kp_x;
  c1_il_y = 2.0 * c1_mj_b;
  c1_og_a = c1_hl_y;
  c1_nj_b = c1_ip_x + c1_il_y;
  c1_jl_y = c1_og_a * c1_nj_b;
  c1_lp_x = c1_q[0];
  c1_mp_x = c1_lp_x;
  c1_mp_x = muDoubleScalarCos(c1_mp_x);
  c1_oj_b = c1_mp_x;
  c1_kl_y = 2.0 * c1_oj_b;
  c1_np_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_op_x = c1_np_x;
  c1_op_x = muDoubleScalarCos(c1_op_x);
  c1_pp_x = c1_q[0] + c1_q[1];
  c1_qp_x = c1_pp_x;
  c1_qp_x = muDoubleScalarCos(c1_qp_x);
  c1_pj_b = c1_qp_x;
  c1_ll_y = 2.0 * c1_pj_b;
  c1_pg_a = c1_jl_y;
  c1_qj_b = (c1_kl_y + c1_op_x) + c1_ll_y;
  c1_ml_y = c1_pg_a * c1_qj_b;
  c1_vb_A = c1_ml_y;
  c1_rp_x = c1_vb_A;
  c1_sp_x = c1_rp_x;
  c1_nl_y = c1_sp_x / 8.0;
  c1_qg_a = c1_b_mn;
  c1_rj_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_ol_y = c1_qg_a * c1_rj_b;
  c1_tp_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_up_x = c1_tp_x;
  c1_up_x = muDoubleScalarCos(c1_up_x);
  c1_vp_x = c1_q[0] + c1_q[1];
  c1_wp_x = c1_vp_x;
  c1_wp_x = muDoubleScalarCos(c1_wp_x);
  c1_sj_b = c1_wp_x;
  c1_pl_y = 2.0 * c1_sj_b;
  c1_rg_a = c1_ol_y;
  c1_tj_b = c1_up_x + c1_pl_y;
  c1_ql_y = c1_rg_a * c1_tj_b;
  c1_xp_x = c1_q[0];
  c1_yp_x = c1_xp_x;
  c1_yp_x = muDoubleScalarSin(c1_yp_x);
  c1_uj_b = c1_yp_x;
  c1_rl_y = 2.0 * c1_uj_b;
  c1_aq_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_bq_x = c1_aq_x;
  c1_bq_x = muDoubleScalarSin(c1_bq_x);
  c1_cq_x = c1_q[0] + c1_q[1];
  c1_dq_x = c1_cq_x;
  c1_dq_x = muDoubleScalarSin(c1_dq_x);
  c1_vj_b = c1_dq_x;
  c1_sl_y = 2.0 * c1_vj_b;
  c1_sg_a = c1_ql_y;
  c1_wj_b = (c1_rl_y + c1_bq_x) + c1_sl_y;
  c1_tl_y = c1_sg_a * c1_wj_b;
  c1_wb_A = c1_tl_y;
  c1_eq_x = c1_wb_A;
  c1_fq_x = c1_eq_x;
  c1_ul_y = c1_fq_x / 8.0;
  c1_gq_x = c1_q[0] + c1_q[1];
  c1_hq_x = c1_gq_x;
  c1_hq_x = muDoubleScalarSin(c1_hq_x);
  c1_tg_a = c1_b_mn;
  c1_xj_b = c1_hq_x;
  c1_vl_y = c1_tg_a * c1_xj_b;
  c1_ug_a = c1_vl_y;
  c1_yj_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_wl_y = c1_ug_a * c1_yj_b;
  c1_iq_x = c1_q[0] + c1_q[1];
  c1_jq_x = c1_iq_x;
  c1_jq_x = muDoubleScalarCos(c1_jq_x);
  c1_kq_x = c1_q[0];
  c1_lq_x = c1_kq_x;
  c1_lq_x = muDoubleScalarCos(c1_lq_x);
  c1_ak_b = c1_lq_x;
  c1_xl_y = 2.0 * c1_ak_b;
  c1_vg_a = c1_wl_y;
  c1_bk_b = c1_jq_x + c1_xl_y;
  c1_yl_y = c1_vg_a * c1_bk_b;
  c1_xb_A = c1_yl_y;
  c1_mq_x = c1_xb_A;
  c1_nq_x = c1_mq_x;
  c1_am_y = c1_nq_x / 8.0;
  c1_oq_x = c1_q[0] + c1_q[1];
  c1_pq_x = c1_oq_x;
  c1_pq_x = muDoubleScalarCos(c1_pq_x);
  c1_wg_a = c1_b_mn;
  c1_ck_b = c1_pq_x;
  c1_bm_y = c1_wg_a * c1_ck_b;
  c1_xg_a = c1_bm_y;
  c1_dk_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_cm_y = c1_xg_a * c1_dk_b;
  c1_qq_x = c1_q[0] + c1_q[1];
  c1_rq_x = c1_qq_x;
  c1_rq_x = muDoubleScalarSin(c1_rq_x);
  c1_sq_x = c1_q[0];
  c1_tq_x = c1_sq_x;
  c1_tq_x = muDoubleScalarSin(c1_tq_x);
  c1_ek_b = c1_tq_x;
  c1_dm_y = 2.0 * c1_ek_b;
  c1_yg_a = c1_cm_y;
  c1_fk_b = c1_rq_x + c1_dm_y;
  c1_em_y = c1_yg_a * c1_fk_b;
  c1_yb_A = c1_em_y;
  c1_uq_x = c1_yb_A;
  c1_vq_x = c1_uq_x;
  c1_fm_y = c1_vq_x / 8.0;
  c1_wq_x = c1_q[0] + c1_q[1];
  c1_xq_x = c1_wq_x;
  c1_xq_x = muDoubleScalarSin(c1_xq_x);
  c1_ah_a = c1_b_mn;
  c1_gk_b = c1_xq_x;
  c1_gm_y = c1_ah_a * c1_gk_b;
  c1_bh_a = c1_gm_y;
  c1_hk_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_hm_y = c1_bh_a * c1_hk_b;
  c1_yq_x = c1_q[0] + c1_q[1];
  c1_ar_x = c1_yq_x;
  c1_ar_x = muDoubleScalarCos(c1_ar_x);
  c1_ch_a = c1_ar_x;
  c1_ik_b = c1_q_dot[0] + c1_q_dot[1];
  c1_im_y = c1_ch_a * c1_ik_b;
  c1_jk_b = c1_q_dot[0];
  c1_jm_y = 2.0 * c1_jk_b;
  c1_br_x = c1_q[0];
  c1_cr_x = c1_br_x;
  c1_cr_x = muDoubleScalarCos(c1_cr_x);
  c1_dh_a = c1_jm_y;
  c1_kk_b = c1_cr_x;
  c1_km_y = c1_dh_a * c1_kk_b;
  c1_eh_a = c1_hm_y;
  c1_lk_b = c1_im_y + c1_km_y;
  c1_lm_y = c1_eh_a * c1_lk_b;
  c1_ac_A = c1_lm_y;
  c1_dr_x = c1_ac_A;
  c1_er_x = c1_dr_x;
  c1_mm_y = c1_er_x / 8.0;
  c1_fr_x = c1_q[0] + c1_q[1];
  c1_gr_x = c1_fr_x;
  c1_gr_x = muDoubleScalarCos(c1_gr_x);
  c1_fh_a = c1_b_mn;
  c1_mk_b = c1_gr_x;
  c1_nm_y = c1_fh_a * c1_mk_b;
  c1_gh_a = c1_nm_y;
  c1_nk_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_om_y = c1_gh_a * c1_nk_b;
  c1_hr_x = c1_q[0] + c1_q[1];
  c1_ir_x = c1_hr_x;
  c1_ir_x = muDoubleScalarSin(c1_ir_x);
  c1_hh_a = c1_ir_x;
  c1_ok_b = c1_q_dot[0] + c1_q_dot[1];
  c1_pm_y = c1_hh_a * c1_ok_b;
  c1_pk_b = c1_q_dot[0];
  c1_qm_y = 2.0 * c1_pk_b;
  c1_jr_x = c1_q[0];
  c1_kr_x = c1_jr_x;
  c1_kr_x = muDoubleScalarSin(c1_kr_x);
  c1_ih_a = c1_qm_y;
  c1_qk_b = c1_kr_x;
  c1_rm_y = c1_ih_a * c1_qk_b;
  c1_jh_a = c1_om_y;
  c1_rk_b = c1_pm_y + c1_rm_y;
  c1_sm_y = c1_jh_a * c1_rk_b;
  c1_bc_A = c1_sm_y;
  c1_lr_x = c1_bc_A;
  c1_mr_x = c1_lr_x;
  c1_tm_y = c1_mr_x / 8.0;
  c1_kh_a = c1_b_mn;
  c1_sk_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_um_y = c1_kh_a * c1_sk_b;
  c1_nr_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_or_x = c1_nr_x;
  c1_or_x = muDoubleScalarSin(c1_or_x);
  c1_pr_x = c1_q[0] + c1_q[1];
  c1_qr_x = c1_pr_x;
  c1_qr_x = muDoubleScalarSin(c1_qr_x);
  c1_tk_b = c1_qr_x;
  c1_vm_y = 2.0 * c1_tk_b;
  c1_lh_a = c1_um_y;
  c1_uk_b = c1_or_x + c1_vm_y;
  c1_wm_y = c1_lh_a * c1_uk_b;
  c1_rr_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_sr_x = c1_rr_x;
  c1_sr_x = muDoubleScalarCos(c1_sr_x);
  c1_mh_a = c1_sr_x;
  c1_vk_b = (c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2];
  c1_xm_y = c1_mh_a * c1_vk_b;
  c1_tr_x = c1_q[0] + c1_q[1];
  c1_ur_x = c1_tr_x;
  c1_ur_x = muDoubleScalarCos(c1_ur_x);
  c1_wk_b = c1_ur_x;
  c1_ym_y = 2.0 * c1_wk_b;
  c1_nh_a = c1_ym_y;
  c1_xk_b = c1_q_dot[0] + c1_q_dot[1];
  c1_an_y = c1_nh_a * c1_xk_b;
  c1_yk_b = c1_q_dot[0];
  c1_bn_y = 2.0 * c1_yk_b;
  c1_vr_x = c1_q[0];
  c1_wr_x = c1_vr_x;
  c1_wr_x = muDoubleScalarCos(c1_wr_x);
  c1_oh_a = c1_bn_y;
  c1_al_b = c1_wr_x;
  c1_cn_y = c1_oh_a * c1_al_b;
  c1_ph_a = c1_wm_y;
  c1_bl_b = (c1_xm_y + c1_an_y) + c1_cn_y;
  c1_dn_y = c1_ph_a * c1_bl_b;
  c1_cc_A = c1_dn_y;
  c1_xr_x = c1_cc_A;
  c1_yr_x = c1_xr_x;
  c1_en_y = c1_yr_x / 8.0;
  c1_as_x = c1_q[0] + c1_q[1];
  c1_bs_x = c1_as_x;
  c1_bs_x = muDoubleScalarSin(c1_bs_x);
  c1_qh_a = c1_b_mn;
  c1_cl_b = c1_bs_x;
  c1_fn_y = c1_qh_a * c1_cl_b;
  c1_rh_a = c1_fn_y;
  c1_dl_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_gn_y = c1_rh_a * c1_dl_b;
  c1_sh_a = c1_gn_y;
  c1_el_b = c1_q_dot[0] + c1_q_dot[1];
  c1_hn_y = c1_sh_a * c1_el_b;
  c1_cs_x = c1_q[0] + c1_q[1];
  c1_ds_x = c1_cs_x;
  c1_ds_x = muDoubleScalarCos(c1_ds_x);
  c1_es_x = c1_q[0];
  c1_fs_x = c1_es_x;
  c1_fs_x = muDoubleScalarCos(c1_fs_x);
  c1_fl_b = c1_fs_x;
  c1_in_y = 2.0 * c1_fl_b;
  c1_th_a = c1_hn_y;
  c1_gl_b = c1_ds_x + c1_in_y;
  c1_jn_y = c1_th_a * c1_gl_b;
  c1_dc_A = c1_jn_y;
  c1_gs_x = c1_dc_A;
  c1_hs_x = c1_gs_x;
  c1_kn_y = c1_hs_x / 8.0;
  c1_is_x = c1_q[0] + c1_q[1];
  c1_js_x = c1_is_x;
  c1_js_x = muDoubleScalarCos(c1_js_x);
  c1_uh_a = c1_b_mn;
  c1_hl_b = c1_js_x;
  c1_ln_y = c1_uh_a * c1_hl_b;
  c1_vh_a = c1_ln_y;
  c1_il_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_mn_y = c1_vh_a * c1_il_b;
  c1_wh_a = c1_mn_y;
  c1_jl_b = c1_q_dot[0] + c1_q_dot[1];
  c1_nn_y = c1_wh_a * c1_jl_b;
  c1_ks_x = c1_q[0] + c1_q[1];
  c1_ls_x = c1_ks_x;
  c1_ls_x = muDoubleScalarSin(c1_ls_x);
  c1_ms_x = c1_q[0];
  c1_ns_x = c1_ms_x;
  c1_ns_x = muDoubleScalarSin(c1_ns_x);
  c1_kl_b = c1_ns_x;
  c1_on_y = 2.0 * c1_kl_b;
  c1_xh_a = c1_nn_y;
  c1_ll_b = c1_ls_x + c1_on_y;
  c1_pn_y = c1_xh_a * c1_ll_b;
  c1_ec_A = c1_pn_y;
  c1_os_x = c1_ec_A;
  c1_ps_x = c1_os_x;
  c1_qn_y = c1_ps_x / 8.0;
  c1_qs_x = c1_q[0] + c1_q[1];
  c1_rs_x = c1_qs_x;
  c1_rs_x = muDoubleScalarSin(c1_rs_x);
  c1_yh_a = c1_b_mn;
  c1_ml_b = c1_rs_x;
  c1_rn_y = c1_yh_a * c1_ml_b;
  c1_ss_x = c1_q[0] + c1_q[1];
  c1_ts_x = c1_ss_x;
  c1_ts_x = muDoubleScalarCos(c1_ts_x);
  c1_ai_a = c1_rn_y;
  c1_nl_b = c1_ts_x;
  c1_sn_y = c1_ai_a * c1_nl_b;
  c1_bi_a = c1_sn_y;
  c1_ol_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_tn_y = c1_bi_a * c1_ol_b;
  c1_fc_A = c1_tn_y;
  c1_us_x = c1_fc_A;
  c1_vs_x = c1_us_x;
  c1_un_y = c1_vs_x / 4.0;
  c1_ws_x = c1_q[0] + c1_q[1];
  c1_xs_x = c1_ws_x;
  c1_xs_x = muDoubleScalarCos(c1_xs_x);
  c1_ci_a = c1_b_mn;
  c1_pl_b = c1_xs_x;
  c1_vn_y = c1_ci_a * c1_pl_b;
  c1_ys_x = c1_q[0] + c1_q[1];
  c1_at_x = c1_ys_x;
  c1_at_x = muDoubleScalarSin(c1_at_x);
  c1_di_a = c1_vn_y;
  c1_ql_b = c1_at_x;
  c1_wn_y = c1_di_a * c1_ql_b;
  c1_ei_a = c1_wn_y;
  c1_rl_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_xn_y = c1_ei_a * c1_rl_b;
  c1_gc_A = c1_xn_y;
  c1_bt_x = c1_gc_A;
  c1_ct_x = c1_bt_x;
  c1_yn_y = c1_ct_x / 4.0;
  c1_fi_a = c1_b_mn;
  c1_sl_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_ao_y = c1_fi_a * c1_sl_b;
  c1_dt_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_et_x = c1_dt_x;
  c1_et_x = muDoubleScalarSin(c1_et_x);
  c1_ft_x = c1_q[0] + c1_q[1];
  c1_gt_x = c1_ft_x;
  c1_gt_x = muDoubleScalarSin(c1_gt_x);
  c1_tl_b = c1_gt_x;
  c1_bo_y = 2.0 * c1_tl_b;
  c1_gi_a = c1_ao_y;
  c1_ul_b = c1_et_x + c1_bo_y;
  c1_co_y = c1_gi_a * c1_ul_b;
  c1_ht_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_it_x = c1_ht_x;
  c1_it_x = muDoubleScalarCos(c1_it_x);
  c1_jt_x = c1_q[0] + c1_q[1];
  c1_kt_x = c1_jt_x;
  c1_kt_x = muDoubleScalarCos(c1_kt_x);
  c1_vl_b = c1_kt_x;
  c1_do_y = 2.0 * c1_vl_b;
  c1_lt_x = c1_q[0];
  c1_mt_x = c1_lt_x;
  c1_mt_x = muDoubleScalarCos(c1_mt_x);
  c1_wl_b = c1_mt_x;
  c1_eo_y = 2.0 * c1_wl_b;
  c1_hi_a = c1_co_y;
  c1_xl_b = (c1_it_x + c1_do_y) + c1_eo_y;
  c1_fo_y = c1_hi_a * c1_xl_b;
  c1_hc_A = c1_fo_y;
  c1_nt_x = c1_hc_A;
  c1_ot_x = c1_nt_x;
  c1_go_y = c1_ot_x / 4.0;
  c1_ii_a = c1_b_mn;
  c1_yl_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_ho_y = c1_ii_a * c1_yl_b;
  c1_pt_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_qt_x = c1_pt_x;
  c1_qt_x = muDoubleScalarCos(c1_qt_x);
  c1_rt_x = c1_q[0] + c1_q[1];
  c1_st_x = c1_rt_x;
  c1_st_x = muDoubleScalarCos(c1_st_x);
  c1_am_b = c1_st_x;
  c1_io_y = 2.0 * c1_am_b;
  c1_ji_a = c1_ho_y;
  c1_bm_b = c1_qt_x + c1_io_y;
  c1_jo_y = c1_ji_a * c1_bm_b;
  c1_tt_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_ut_x = c1_tt_x;
  c1_ut_x = muDoubleScalarSin(c1_ut_x);
  c1_vt_x = c1_q[0] + c1_q[1];
  c1_wt_x = c1_vt_x;
  c1_wt_x = muDoubleScalarSin(c1_wt_x);
  c1_cm_b = c1_wt_x;
  c1_ko_y = 2.0 * c1_cm_b;
  c1_xt_x = c1_q[0];
  c1_yt_x = c1_xt_x;
  c1_yt_x = muDoubleScalarSin(c1_yt_x);
  c1_dm_b = c1_yt_x;
  c1_lo_y = 2.0 * c1_dm_b;
  c1_ki_a = c1_jo_y;
  c1_em_b = (c1_ut_x + c1_ko_y) + c1_lo_y;
  c1_mo_y = c1_ki_a * c1_em_b;
  c1_ic_A = c1_mo_y;
  c1_au_x = c1_ic_A;
  c1_bu_x = c1_au_x;
  c1_no_y = c1_bu_x / 4.0;
  c1_li_a = c1_b_mn;
  c1_fm_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_oo_y = c1_li_a * c1_fm_b;
  c1_cu_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_du_x = c1_cu_x;
  c1_du_x = muDoubleScalarCos(c1_du_x);
  c1_eu_x = c1_q[0] + c1_q[1];
  c1_fu_x = c1_eu_x;
  c1_fu_x = muDoubleScalarCos(c1_fu_x);
  c1_gm_b = c1_fu_x;
  c1_po_y = 2.0 * c1_gm_b;
  c1_mi_a = c1_oo_y;
  c1_hm_b = c1_du_x + c1_po_y;
  c1_qo_y = c1_mi_a * c1_hm_b;
  c1_gu_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_hu_x = c1_gu_x;
  c1_hu_x = muDoubleScalarSin(c1_hu_x);
  c1_ni_a = c1_hu_x;
  c1_im_b = (c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2];
  c1_ro_y = c1_ni_a * c1_im_b;
  c1_iu_x = c1_q[0] + c1_q[1];
  c1_ju_x = c1_iu_x;
  c1_ju_x = muDoubleScalarSin(c1_ju_x);
  c1_jm_b = c1_ju_x;
  c1_so_y = 2.0 * c1_jm_b;
  c1_oi_a = c1_so_y;
  c1_km_b = c1_q_dot[0] + c1_q_dot[1];
  c1_to_y = c1_oi_a * c1_km_b;
  c1_pi_a = c1_qo_y;
  c1_lm_b = c1_ro_y + c1_to_y;
  c1_uo_y = c1_pi_a * c1_lm_b;
  c1_jc_A = c1_uo_y;
  c1_ku_x = c1_jc_A;
  c1_lu_x = c1_ku_x;
  c1_vo_y = c1_lu_x / 8.0;
  c1_qi_a = c1_b_mn;
  c1_mm_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_wo_y = c1_qi_a * c1_mm_b;
  c1_mu_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_nu_x = c1_mu_x;
  c1_nu_x = muDoubleScalarSin(c1_nu_x);
  c1_ou_x = c1_q[0] + c1_q[1];
  c1_pu_x = c1_ou_x;
  c1_pu_x = muDoubleScalarSin(c1_pu_x);
  c1_nm_b = c1_pu_x;
  c1_xo_y = 2.0 * c1_nm_b;
  c1_ri_a = c1_wo_y;
  c1_om_b = c1_nu_x + c1_xo_y;
  c1_yo_y = c1_ri_a * c1_om_b;
  c1_qu_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_ru_x = c1_qu_x;
  c1_ru_x = muDoubleScalarCos(c1_ru_x);
  c1_si_a = c1_ru_x;
  c1_pm_b = (c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2];
  c1_ap_y = c1_si_a * c1_pm_b;
  c1_su_x = c1_q[0] + c1_q[1];
  c1_tu_x = c1_su_x;
  c1_tu_x = muDoubleScalarCos(c1_tu_x);
  c1_qm_b = c1_tu_x;
  c1_bp_y = 2.0 * c1_qm_b;
  c1_ti_a = c1_bp_y;
  c1_rm_b = c1_q_dot[0] + c1_q_dot[1];
  c1_cp_y = c1_ti_a * c1_rm_b;
  c1_ui_a = c1_yo_y;
  c1_sm_b = c1_ap_y + c1_cp_y;
  c1_dp_y = c1_ui_a * c1_sm_b;
  c1_kc_A = c1_dp_y;
  c1_uu_x = c1_kc_A;
  c1_vu_x = c1_uu_x;
  c1_ep_y = c1_vu_x / 8.0;
  c1_vi_a = c1_b_mn;
  c1_tm_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_fp_y = c1_vi_a * c1_tm_b;
  c1_wu_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_xu_x = c1_wu_x;
  c1_xu_x = muDoubleScalarCos(c1_xu_x);
  c1_yu_x = c1_q[0] + c1_q[1];
  c1_av_x = c1_yu_x;
  c1_av_x = muDoubleScalarCos(c1_av_x);
  c1_um_b = c1_av_x;
  c1_gp_y = 2.0 * c1_um_b;
  c1_wi_a = c1_fp_y;
  c1_vm_b = c1_xu_x + c1_gp_y;
  c1_hp_y = c1_wi_a * c1_vm_b;
  c1_bv_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_cv_x = c1_bv_x;
  c1_cv_x = muDoubleScalarSin(c1_cv_x);
  c1_xi_a = c1_cv_x;
  c1_wm_b = (c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2];
  c1_ip_y = c1_xi_a * c1_wm_b;
  c1_dv_x = c1_q[0] + c1_q[1];
  c1_ev_x = c1_dv_x;
  c1_ev_x = muDoubleScalarSin(c1_ev_x);
  c1_xm_b = c1_ev_x;
  c1_jp_y = 2.0 * c1_xm_b;
  c1_yi_a = c1_jp_y;
  c1_ym_b = c1_q_dot[0] + c1_q_dot[1];
  c1_kp_y = c1_yi_a * c1_ym_b;
  c1_aj_a = c1_hp_y;
  c1_an_b = c1_ip_y + c1_kp_y;
  c1_lp_y = c1_aj_a * c1_an_b;
  c1_lc_A = c1_lp_y;
  c1_fv_x = c1_lc_A;
  c1_gv_x = c1_fv_x;
  c1_mp_y = c1_gv_x / 8.0;
  c1_bj_a = c1_b_mn;
  c1_bn_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_np_y = c1_bj_a * c1_bn_b;
  c1_hv_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_iv_x = c1_hv_x;
  c1_iv_x = muDoubleScalarSin(c1_iv_x);
  c1_jv_x = c1_q[0] + c1_q[1];
  c1_kv_x = c1_jv_x;
  c1_kv_x = muDoubleScalarSin(c1_kv_x);
  c1_cn_b = c1_kv_x;
  c1_op_y = 2.0 * c1_cn_b;
  c1_cj_a = c1_np_y;
  c1_dn_b = c1_iv_x + c1_op_y;
  c1_pp_y = c1_cj_a * c1_dn_b;
  c1_lv_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_mv_x = c1_lv_x;
  c1_mv_x = muDoubleScalarCos(c1_mv_x);
  c1_dj_a = c1_mv_x;
  c1_en_b = (c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2];
  c1_qp_y = c1_dj_a * c1_en_b;
  c1_nv_x = c1_q[0] + c1_q[1];
  c1_ov_x = c1_nv_x;
  c1_ov_x = muDoubleScalarCos(c1_ov_x);
  c1_fn_b = c1_ov_x;
  c1_rp_y = 2.0 * c1_fn_b;
  c1_ej_a = c1_rp_y;
  c1_gn_b = c1_q_dot[0] + c1_q_dot[1];
  c1_sp_y = c1_ej_a * c1_gn_b;
  c1_fj_a = c1_pp_y;
  c1_hn_b = c1_qp_y + c1_sp_y;
  c1_tp_y = c1_fj_a * c1_hn_b;
  c1_mc_A = c1_tp_y;
  c1_pv_x = c1_mc_A;
  c1_qv_x = c1_pv_x;
  c1_up_y = c1_qv_x / 8.0;
  c1_rv_x = c1_q[0] + c1_q[1];
  c1_sv_x = c1_rv_x;
  c1_sv_x = muDoubleScalarSin(c1_sv_x);
  c1_gj_a = c1_b_mn;
  c1_in_b = c1_sv_x;
  c1_vp_y = c1_gj_a * c1_in_b;
  c1_hj_a = c1_vp_y;
  c1_jn_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_wp_y = c1_hj_a * c1_jn_b;
  c1_tv_x = c1_q[0] + c1_q[1];
  c1_uv_x = c1_tv_x;
  c1_uv_x = muDoubleScalarCos(c1_uv_x);
  c1_vv_x = c1_q[0];
  c1_wv_x = c1_vv_x;
  c1_wv_x = muDoubleScalarCos(c1_wv_x);
  c1_kn_b = c1_wv_x;
  c1_xp_y = 2.0 * c1_kn_b;
  c1_ij_a = c1_wp_y;
  c1_ln_b = c1_uv_x + c1_xp_y;
  c1_yp_y = c1_ij_a * c1_ln_b;
  c1_nc_A = c1_yp_y;
  c1_xv_x = c1_nc_A;
  c1_yv_x = c1_xv_x;
  c1_aq_y = c1_yv_x / 4.0;
  c1_aw_x = c1_q[0] + c1_q[1];
  c1_bw_x = c1_aw_x;
  c1_bw_x = muDoubleScalarCos(c1_bw_x);
  c1_jj_a = c1_b_mn;
  c1_mn_b = c1_bw_x;
  c1_bq_y = c1_jj_a * c1_mn_b;
  c1_kj_a = c1_bq_y;
  c1_nn_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_cq_y = c1_kj_a * c1_nn_b;
  c1_cw_x = c1_q[0] + c1_q[1];
  c1_dw_x = c1_cw_x;
  c1_dw_x = muDoubleScalarSin(c1_dw_x);
  c1_ew_x = c1_q[0];
  c1_fw_x = c1_ew_x;
  c1_fw_x = muDoubleScalarSin(c1_fw_x);
  c1_on_b = c1_fw_x;
  c1_dq_y = 2.0 * c1_on_b;
  c1_lj_a = c1_cq_y;
  c1_pn_b = c1_dw_x + c1_dq_y;
  c1_eq_y = c1_lj_a * c1_pn_b;
  c1_oc_A = c1_eq_y;
  c1_gw_x = c1_oc_A;
  c1_hw_x = c1_gw_x;
  c1_fq_y = c1_hw_x / 4.0;
  c1_mj_a = c1_b_mn;
  c1_qn_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_gq_y = c1_mj_a * c1_qn_b;
  c1_iw_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_jw_x = c1_iw_x;
  c1_jw_x = muDoubleScalarCos(c1_jw_x);
  c1_kw_x = c1_q[0] + c1_q[1];
  c1_lw_x = c1_kw_x;
  c1_lw_x = muDoubleScalarCos(c1_lw_x);
  c1_rn_b = c1_lw_x;
  c1_hq_y = 2.0 * c1_rn_b;
  c1_nj_a = c1_gq_y;
  c1_sn_b = c1_jw_x + c1_hq_y;
  c1_iq_y = c1_nj_a * c1_sn_b;
  c1_mw_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_nw_x = c1_mw_x;
  c1_nw_x = muDoubleScalarSin(c1_nw_x);
  c1_ow_x = c1_q[0] + c1_q[1];
  c1_pw_x = c1_ow_x;
  c1_pw_x = muDoubleScalarSin(c1_pw_x);
  c1_tn_b = c1_pw_x;
  c1_jq_y = 2.0 * c1_tn_b;
  c1_oj_a = c1_iq_y;
  c1_un_b = c1_nw_x + c1_jq_y;
  c1_kq_y = c1_oj_a * c1_un_b;
  c1_pc_A = c1_kq_y;
  c1_qw_x = c1_pc_A;
  c1_rw_x = c1_qw_x;
  c1_lq_y = c1_rw_x / 4.0;
  c1_pj_a = c1_b_mn;
  c1_vn_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_mq_y = c1_pj_a * c1_vn_b;
  c1_sw_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_tw_x = c1_sw_x;
  c1_tw_x = muDoubleScalarCos(c1_tw_x);
  c1_uw_x = c1_q[0] + c1_q[1];
  c1_vw_x = c1_uw_x;
  c1_vw_x = muDoubleScalarCos(c1_vw_x);
  c1_wn_b = c1_vw_x;
  c1_nq_y = 2.0 * c1_wn_b;
  c1_qj_a = c1_mq_y;
  c1_xn_b = c1_tw_x + c1_nq_y;
  c1_oq_y = c1_qj_a * c1_xn_b;
  c1_ww_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_xw_x = c1_ww_x;
  c1_xw_x = muDoubleScalarSin(c1_xw_x);
  c1_yw_x = c1_q[0] + c1_q[1];
  c1_ax_x = c1_yw_x;
  c1_ax_x = muDoubleScalarSin(c1_ax_x);
  c1_yn_b = c1_ax_x;
  c1_pq_y = 2.0 * c1_yn_b;
  c1_rj_a = c1_oq_y;
  c1_ao_b = c1_xw_x + c1_pq_y;
  c1_qq_y = c1_rj_a * c1_ao_b;
  c1_qc_A = c1_qq_y;
  c1_bx_x = c1_qc_A;
  c1_cx_x = c1_bx_x;
  c1_rq_y = c1_cx_x / 4.0;
  c1_dx_x = c1_q[0] + c1_q[1];
  c1_ex_x = c1_dx_x;
  c1_ex_x = muDoubleScalarCos(c1_ex_x);
  c1_sj_a = c1_b_mn;
  c1_bo_b = c1_ex_x;
  c1_sq_y = c1_sj_a * c1_bo_b;
  c1_fx_x = c1_q[0] + c1_q[1];
  c1_gx_x = c1_fx_x;
  c1_gx_x = muDoubleScalarSin(c1_gx_x);
  c1_tj_a = c1_sq_y;
  c1_co_b = c1_gx_x;
  c1_tq_y = c1_tj_a * c1_co_b;
  c1_uj_a = c1_tq_y;
  c1_do_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_uq_y = c1_uj_a * c1_do_b;
  c1_vj_a = c1_uq_y;
  c1_eo_b = c1_q_dot[0] + c1_q_dot[1];
  c1_vq_y = c1_vj_a * c1_eo_b;
  c1_rc_A = c1_vq_y;
  c1_hx_x = c1_rc_A;
  c1_ix_x = c1_hx_x;
  c1_wq_y = c1_ix_x / 8.0;
  c1_jx_x = c1_q[0] + c1_q[1];
  c1_kx_x = c1_jx_x;
  c1_kx_x = muDoubleScalarSin(c1_kx_x);
  c1_wj_a = c1_b_mn;
  c1_fo_b = c1_kx_x;
  c1_xq_y = c1_wj_a * c1_fo_b;
  c1_lx_x = c1_q[0] + c1_q[1];
  c1_mx_x = c1_lx_x;
  c1_mx_x = muDoubleScalarCos(c1_mx_x);
  c1_xj_a = c1_xq_y;
  c1_go_b = c1_mx_x;
  c1_yq_y = c1_xj_a * c1_go_b;
  c1_yj_a = c1_yq_y;
  c1_ho_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_ar_y = c1_yj_a * c1_ho_b;
  c1_ak_a = c1_ar_y;
  c1_io_b = c1_q_dot[0] + c1_q_dot[1];
  c1_br_y = c1_ak_a * c1_io_b;
  c1_sc_A = c1_br_y;
  c1_nx_x = c1_sc_A;
  c1_ox_x = c1_nx_x;
  c1_cr_y = c1_ox_x / 8.0;
  c1_px_x = c1_q[0] + c1_q[1];
  c1_qx_x = c1_px_x;
  c1_qx_x = muDoubleScalarCos(c1_qx_x);
  c1_bk_a = c1_b_mn;
  c1_jo_b = c1_qx_x;
  c1_dr_y = c1_bk_a * c1_jo_b;
  c1_rx_x = c1_q[0] + c1_q[1];
  c1_sx_x = c1_rx_x;
  c1_sx_x = muDoubleScalarSin(c1_sx_x);
  c1_ck_a = c1_dr_y;
  c1_ko_b = c1_sx_x;
  c1_er_y = c1_ck_a * c1_ko_b;
  c1_dk_a = c1_er_y;
  c1_lo_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_fr_y = c1_dk_a * c1_lo_b;
  c1_ek_a = c1_fr_y;
  c1_mo_b = c1_q_dot[0] + c1_q_dot[1];
  c1_gr_y = c1_ek_a * c1_mo_b;
  c1_tc_A = c1_gr_y;
  c1_tx_x = c1_tc_A;
  c1_ux_x = c1_tx_x;
  c1_hr_y = c1_ux_x / 8.0;
  c1_vx_x = c1_q[0] + c1_q[1];
  c1_wx_x = c1_vx_x;
  c1_wx_x = muDoubleScalarSin(c1_wx_x);
  c1_fk_a = c1_b_mn;
  c1_no_b = c1_wx_x;
  c1_ir_y = c1_fk_a * c1_no_b;
  c1_xx_x = c1_q[0] + c1_q[1];
  c1_yx_x = c1_xx_x;
  c1_yx_x = muDoubleScalarCos(c1_yx_x);
  c1_gk_a = c1_ir_y;
  c1_oo_b = c1_yx_x;
  c1_jr_y = c1_gk_a * c1_oo_b;
  c1_hk_a = c1_jr_y;
  c1_po_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_kr_y = c1_hk_a * c1_po_b;
  c1_ik_a = c1_kr_y;
  c1_qo_b = c1_q_dot[0] + c1_q_dot[1];
  c1_lr_y = c1_ik_a * c1_qo_b;
  c1_uc_A = c1_lr_y;
  c1_ay_x = c1_uc_A;
  c1_by_x = c1_ay_x;
  c1_mr_y = c1_by_x / 8.0;
  c1_jk_a = c1_b_mn;
  c1_ro_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_nr_y = c1_jk_a * c1_ro_b;
  c1_cy_x = (((c1_q[0] - c1_q[1]) - c1_q[2]) - c1_q[0]) + c1_q[1];
  c1_dy_x = c1_cy_x;
  c1_dy_x = muDoubleScalarSin(c1_dy_x);
  c1_so_b = c1_dy_x;
  c1_or_y = 2.0 * c1_so_b;
  c1_kk_a = c1_or_y;
  c1_to_b = (((c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2]) - c1_q_dot[0]) -
    c1_q_dot[1];
  c1_pr_y = c1_kk_a * c1_to_b;
  c1_ey_x = ((((c1_q[0] - c1_q[1]) - c1_q[2]) - c1_q[0]) + c1_q[1]) + c1_q[2];
  c1_fy_x = c1_ey_x;
  c1_fy_x = muDoubleScalarSin(c1_fy_x);
  c1_lk_a = c1_fy_x;
  c1_uo_b = ((((c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2]) - c1_q_dot[0]) -
             c1_q_dot[1]) - c1_q_dot[2];
  c1_qr_y = c1_lk_a * c1_uo_b;
  c1_mk_a = c1_nr_y;
  c1_vo_b = c1_pr_y + c1_qr_y;
  c1_rr_y = c1_mk_a * c1_vo_b;
  c1_vc_A = c1_rr_y;
  c1_gy_x = c1_vc_A;
  c1_hy_x = c1_gy_x;
  c1_sr_y = c1_hy_x / 8.0;
  c1_nk_a = c1_b_mn;
  c1_wo_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_tr_y = c1_nk_a * c1_wo_b;
  c1_iy_x = (((c1_q[0] - c1_q[1]) - c1_q[2]) - c1_q[0]) + c1_q[1];
  c1_jy_x = c1_iy_x;
  c1_jy_x = muDoubleScalarSin(c1_jy_x);
  c1_ok_a = c1_tr_y;
  c1_xo_b = c1_jy_x;
  c1_ur_y = c1_ok_a * c1_xo_b;
  c1_wc_A = c1_ur_y;
  c1_ky_x = c1_wc_A;
  c1_ly_x = c1_ky_x;
  c1_vr_y = c1_ly_x / 4.0;
  c1_my_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_ny_x = c1_my_x;
  c1_ny_x = muDoubleScalarCos(c1_ny_x);
  c1_pk_a = c1_b_mn;
  c1_yo_b = c1_ny_x;
  c1_wr_y = c1_pk_a * c1_yo_b;
  c1_qk_a = c1_wr_y;
  c1_ap_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_xr_y = c1_qk_a * c1_ap_b;
  c1_oy_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_py_x = c1_oy_x;
  c1_py_x = muDoubleScalarSin(c1_py_x);
  c1_qy_x = c1_q[0] + c1_q[1];
  c1_ry_x = c1_qy_x;
  c1_ry_x = muDoubleScalarSin(c1_ry_x);
  c1_bp_b = c1_ry_x;
  c1_yr_y = 2.0 * c1_bp_b;
  c1_sy_x = c1_q[0];
  c1_ty_x = c1_sy_x;
  c1_ty_x = muDoubleScalarSin(c1_ty_x);
  c1_cp_b = c1_ty_x;
  c1_as_y = 2.0 * c1_cp_b;
  c1_rk_a = c1_xr_y;
  c1_dp_b = (c1_py_x + c1_yr_y) + c1_as_y;
  c1_bs_y = c1_rk_a * c1_dp_b;
  c1_xc_A = c1_bs_y;
  c1_uy_x = c1_xc_A;
  c1_vy_x = c1_uy_x;
  c1_cs_y = c1_vy_x / 4.0;
  c1_wy_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_xy_x = c1_wy_x;
  c1_xy_x = muDoubleScalarSin(c1_xy_x);
  c1_sk_a = c1_b_mn;
  c1_ep_b = c1_xy_x;
  c1_ds_y = c1_sk_a * c1_ep_b;
  c1_tk_a = c1_ds_y;
  c1_fp_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_es_y = c1_tk_a * c1_fp_b;
  c1_yy_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_aab_x = c1_yy_x;
  c1_aab_x = muDoubleScalarCos(c1_aab_x);
  c1_bab_x = c1_q[0] + c1_q[1];
  c1_cab_x = c1_bab_x;
  c1_cab_x = muDoubleScalarCos(c1_cab_x);
  c1_gp_b = c1_cab_x;
  c1_fs_y = 2.0 * c1_gp_b;
  c1_uk_a = c1_es_y;
  c1_hp_b = c1_aab_x + c1_fs_y;
  c1_gs_y = c1_uk_a * c1_hp_b;
  c1_yc_A = c1_gs_y;
  c1_dab_x = c1_yc_A;
  c1_eab_x = c1_dab_x;
  c1_hs_y = c1_eab_x / 4.0;
  c1_fab_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_gab_x = c1_fab_x;
  c1_gab_x = muDoubleScalarCos(c1_gab_x);
  c1_vk_a = c1_b_mn;
  c1_ip_b = c1_gab_x;
  c1_is_y = c1_vk_a * c1_ip_b;
  c1_wk_a = c1_is_y;
  c1_jp_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_js_y = c1_wk_a * c1_jp_b;
  c1_hab_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_iab_x = c1_hab_x;
  c1_iab_x = muDoubleScalarSin(c1_iab_x);
  c1_jab_x = c1_q[0] + c1_q[1];
  c1_kab_x = c1_jab_x;
  c1_kab_x = muDoubleScalarSin(c1_kab_x);
  c1_kp_b = c1_kab_x;
  c1_ks_y = 2.0 * c1_kp_b;
  c1_xk_a = c1_js_y;
  c1_lp_b = c1_iab_x + c1_ks_y;
  c1_ls_y = c1_xk_a * c1_lp_b;
  c1_ad_A = c1_ls_y;
  c1_lab_x = c1_ad_A;
  c1_mab_x = c1_lab_x;
  c1_ms_y = c1_mab_x / 4.0;
  c1_nab_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_oab_x = c1_nab_x;
  c1_oab_x = muDoubleScalarSin(c1_oab_x);
  c1_yk_a = c1_b_mn;
  c1_mp_b = c1_oab_x;
  c1_ns_y = c1_yk_a * c1_mp_b;
  c1_al_a = c1_ns_y;
  c1_np_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_os_y = c1_al_a * c1_np_b;
  c1_pab_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_qab_x = c1_pab_x;
  c1_qab_x = muDoubleScalarCos(c1_qab_x);
  c1_rab_x = c1_q[0] + c1_q[1];
  c1_sab_x = c1_rab_x;
  c1_sab_x = muDoubleScalarCos(c1_sab_x);
  c1_op_b = c1_sab_x;
  c1_ps_y = 2.0 * c1_op_b;
  c1_tab_x = c1_q[0];
  c1_uab_x = c1_tab_x;
  c1_uab_x = muDoubleScalarCos(c1_uab_x);
  c1_pp_b = c1_uab_x;
  c1_qs_y = 2.0 * c1_pp_b;
  c1_bl_a = c1_os_y;
  c1_qp_b = (c1_qab_x + c1_ps_y) + c1_qs_y;
  c1_rs_y = c1_bl_a * c1_qp_b;
  c1_bd_A = c1_rs_y;
  c1_vab_x = c1_bd_A;
  c1_wab_x = c1_vab_x;
  c1_ss_y = c1_wab_x / 4.0;
  c1_xab_x = ((c1_q[0] - c1_q[1]) - c1_q[2]) - c1_q[0];
  c1_yab_x = c1_xab_x;
  c1_yab_x = muDoubleScalarSin(c1_yab_x);
  c1_cl_a = c1_b_mn;
  c1_rp_b = c1_yab_x;
  c1_ts_y = c1_cl_a * c1_rp_b;
  c1_dl_a = c1_ts_y;
  c1_sp_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_us_y = c1_dl_a * c1_sp_b;
  c1_cd_A = c1_us_y;
  c1_abb_x = c1_cd_A;
  c1_bbb_x = c1_abb_x;
  c1_vs_y = c1_bbb_x / 4.0;
  c1_el_a = c1_b_mn;
  c1_tp_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_ws_y = c1_el_a * c1_tp_b;
  c1_cbb_x = ((c1_q[0] - c1_q[1]) - c1_q[2]) - c1_q[0];
  c1_dbb_x = c1_cbb_x;
  c1_dbb_x = muDoubleScalarSin(c1_dbb_x);
  c1_up_b = c1_dbb_x;
  c1_xs_y = 2.0 * c1_up_b;
  c1_ebb_x = (((c1_q[0] - c1_q[1]) - c1_q[2]) - c1_q[0]) + c1_q[1];
  c1_fbb_x = c1_ebb_x;
  c1_fbb_x = muDoubleScalarSin(c1_fbb_x);
  c1_vp_b = c1_fbb_x;
  c1_ys_y = 2.0 * c1_vp_b;
  c1_fl_a = c1_ws_y;
  c1_wp_b = c1_xs_y + c1_ys_y;
  c1_at_y = c1_fl_a * c1_wp_b;
  c1_dd_A = c1_at_y;
  c1_gbb_x = c1_dd_A;
  c1_hbb_x = c1_gbb_x;
  c1_bt_y = c1_hbb_x / 8.0;
  c1_gl_a = c1_b_mn;
  c1_xp_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_ct_y = c1_gl_a * c1_xp_b;
  c1_ibb_x = (((c1_q[0] - c1_q[1]) - c1_q[2]) - c1_q[0]) + c1_q[1];
  c1_jbb_x = c1_ibb_x;
  c1_jbb_x = muDoubleScalarSin(c1_jbb_x);
  c1_hl_a = c1_ct_y;
  c1_yp_b = c1_jbb_x;
  c1_dt_y = c1_hl_a * c1_yp_b;
  c1_ed_A = c1_dt_y;
  c1_kbb_x = c1_ed_A;
  c1_lbb_x = c1_kbb_x;
  c1_et_y = c1_lbb_x / 4.0;
  c1_il_a = c1_b_mn;
  c1_aq_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_ft_y = c1_il_a * c1_aq_b;
  c1_mbb_x = (((c1_q[0] - c1_q[1]) - c1_q[0]) + c1_q[1]) + c1_q[2];
  c1_nbb_x = c1_mbb_x;
  c1_nbb_x = muDoubleScalarSin(c1_nbb_x);
  c1_jl_a = c1_ft_y;
  c1_bq_b = c1_nbb_x;
  c1_gt_y = c1_jl_a * c1_bq_b;
  c1_fd_A = c1_gt_y;
  c1_obb_x = c1_fd_A;
  c1_pbb_x = c1_obb_x;
  c1_ht_y = c1_pbb_x / 4.0;
  c1_qbb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_rbb_x = c1_qbb_x;
  c1_rbb_x = muDoubleScalarCos(c1_rbb_x);
  c1_kl_a = c1_b_mn;
  c1_cq_b = c1_rbb_x;
  c1_it_y = c1_kl_a * c1_cq_b;
  c1_ll_a = c1_it_y;
  c1_dq_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_jt_y = c1_ll_a * c1_dq_b;
  c1_sbb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_tbb_x = c1_sbb_x;
  c1_tbb_x = muDoubleScalarSin(c1_tbb_x);
  c1_ubb_x = c1_q[0] + c1_q[1];
  c1_vbb_x = c1_ubb_x;
  c1_vbb_x = muDoubleScalarSin(c1_vbb_x);
  c1_eq_b = c1_vbb_x;
  c1_kt_y = 2.0 * c1_eq_b;
  c1_wbb_x = c1_q[0];
  c1_xbb_x = c1_wbb_x;
  c1_xbb_x = muDoubleScalarSin(c1_xbb_x);
  c1_fq_b = c1_xbb_x;
  c1_lt_y = 2.0 * c1_fq_b;
  c1_ml_a = c1_jt_y;
  c1_gq_b = (c1_tbb_x + c1_kt_y) + c1_lt_y;
  c1_mt_y = c1_ml_a * c1_gq_b;
  c1_gd_A = c1_mt_y;
  c1_ybb_x = c1_gd_A;
  c1_acb_x = c1_ybb_x;
  c1_nt_y = c1_acb_x / 8.0;
  c1_bcb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_ccb_x = c1_bcb_x;
  c1_ccb_x = muDoubleScalarSin(c1_ccb_x);
  c1_nl_a = c1_b_mn;
  c1_hq_b = c1_ccb_x;
  c1_ot_y = c1_nl_a * c1_hq_b;
  c1_ol_a = c1_ot_y;
  c1_iq_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_pt_y = c1_ol_a * c1_iq_b;
  c1_dcb_x = c1_q[0];
  c1_ecb_x = c1_dcb_x;
  c1_ecb_x = muDoubleScalarCos(c1_ecb_x);
  c1_jq_b = c1_ecb_x;
  c1_qt_y = 2.0 * c1_jq_b;
  c1_fcb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_gcb_x = c1_fcb_x;
  c1_gcb_x = muDoubleScalarCos(c1_gcb_x);
  c1_hcb_x = c1_q[0] + c1_q[1];
  c1_icb_x = c1_hcb_x;
  c1_icb_x = muDoubleScalarCos(c1_icb_x);
  c1_kq_b = c1_icb_x;
  c1_rt_y = 2.0 * c1_kq_b;
  c1_pl_a = c1_pt_y;
  c1_lq_b = (c1_qt_y + c1_gcb_x) + c1_rt_y;
  c1_st_y = c1_pl_a * c1_lq_b;
  c1_hd_A = c1_st_y;
  c1_jcb_x = c1_hd_A;
  c1_kcb_x = c1_jcb_x;
  c1_tt_y = c1_kcb_x / 8.0;
  c1_lcb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_mcb_x = c1_lcb_x;
  c1_mcb_x = muDoubleScalarCos(c1_mcb_x);
  c1_ql_a = c1_b_mn;
  c1_mq_b = c1_mcb_x;
  c1_ut_y = c1_ql_a * c1_mq_b;
  c1_rl_a = c1_ut_y;
  c1_nq_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_vt_y = c1_rl_a * c1_nq_b;
  c1_ncb_x = c1_q[0];
  c1_ocb_x = c1_ncb_x;
  c1_ocb_x = muDoubleScalarSin(c1_ocb_x);
  c1_oq_b = c1_ocb_x;
  c1_wt_y = 2.0 * c1_oq_b;
  c1_pcb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_qcb_x = c1_pcb_x;
  c1_qcb_x = muDoubleScalarSin(c1_qcb_x);
  c1_rcb_x = c1_q[0] + c1_q[1];
  c1_scb_x = c1_rcb_x;
  c1_scb_x = muDoubleScalarSin(c1_scb_x);
  c1_pq_b = c1_scb_x;
  c1_xt_y = 2.0 * c1_pq_b;
  c1_sl_a = c1_vt_y;
  c1_qq_b = (c1_wt_y + c1_qcb_x) + c1_xt_y;
  c1_yt_y = c1_sl_a * c1_qq_b;
  c1_id_A = c1_yt_y;
  c1_tcb_x = c1_id_A;
  c1_ucb_x = c1_tcb_x;
  c1_au_y = c1_ucb_x / 8.0;
  c1_vcb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_wcb_x = c1_vcb_x;
  c1_wcb_x = muDoubleScalarSin(c1_wcb_x);
  c1_tl_a = c1_b_mn;
  c1_rq_b = c1_wcb_x;
  c1_bu_y = c1_tl_a * c1_rq_b;
  c1_ul_a = c1_bu_y;
  c1_sq_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_cu_y = c1_ul_a * c1_sq_b;
  c1_xcb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_ycb_x = c1_xcb_x;
  c1_ycb_x = muDoubleScalarCos(c1_ycb_x);
  c1_vl_a = c1_ycb_x;
  c1_tq_b = (c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2];
  c1_du_y = c1_vl_a * c1_tq_b;
  c1_adb_x = c1_q[0] + c1_q[1];
  c1_bdb_x = c1_adb_x;
  c1_bdb_x = muDoubleScalarCos(c1_bdb_x);
  c1_uq_b = c1_bdb_x;
  c1_eu_y = 2.0 * c1_uq_b;
  c1_wl_a = c1_eu_y;
  c1_vq_b = c1_q_dot[0] + c1_q_dot[1];
  c1_fu_y = c1_wl_a * c1_vq_b;
  c1_wq_b = c1_q_dot[0];
  c1_gu_y = 2.0 * c1_wq_b;
  c1_cdb_x = c1_q[0];
  c1_ddb_x = c1_cdb_x;
  c1_ddb_x = muDoubleScalarCos(c1_ddb_x);
  c1_xl_a = c1_gu_y;
  c1_xq_b = c1_ddb_x;
  c1_hu_y = c1_xl_a * c1_xq_b;
  c1_yl_a = c1_cu_y;
  c1_yq_b = (c1_du_y + c1_fu_y) + c1_hu_y;
  c1_iu_y = c1_yl_a * c1_yq_b;
  c1_jd_A = c1_iu_y;
  c1_edb_x = c1_jd_A;
  c1_fdb_x = c1_edb_x;
  c1_ju_y = c1_fdb_x / 8.0;
  c1_gdb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_hdb_x = c1_gdb_x;
  c1_hdb_x = muDoubleScalarCos(c1_hdb_x);
  c1_am_a = c1_b_mn;
  c1_ar_b = c1_hdb_x;
  c1_ku_y = c1_am_a * c1_ar_b;
  c1_bm_a = c1_ku_y;
  c1_br_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_lu_y = c1_bm_a * c1_br_b;
  c1_idb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_jdb_x = c1_idb_x;
  c1_jdb_x = muDoubleScalarSin(c1_jdb_x);
  c1_cm_a = c1_jdb_x;
  c1_cr_b = (c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2];
  c1_mu_y = c1_cm_a * c1_cr_b;
  c1_kdb_x = c1_q[0] + c1_q[1];
  c1_ldb_x = c1_kdb_x;
  c1_ldb_x = muDoubleScalarSin(c1_ldb_x);
  c1_dr_b = c1_ldb_x;
  c1_nu_y = 2.0 * c1_dr_b;
  c1_dm_a = c1_nu_y;
  c1_er_b = c1_q_dot[0] + c1_q_dot[1];
  c1_ou_y = c1_dm_a * c1_er_b;
  c1_fr_b = c1_q_dot[0];
  c1_pu_y = 2.0 * c1_fr_b;
  c1_mdb_x = c1_q[0];
  c1_ndb_x = c1_mdb_x;
  c1_ndb_x = muDoubleScalarSin(c1_ndb_x);
  c1_em_a = c1_pu_y;
  c1_gr_b = c1_ndb_x;
  c1_qu_y = c1_em_a * c1_gr_b;
  c1_fm_a = c1_lu_y;
  c1_hr_b = (c1_mu_y + c1_ou_y) + c1_qu_y;
  c1_ru_y = c1_fm_a * c1_hr_b;
  c1_kd_A = c1_ru_y;
  c1_odb_x = c1_kd_A;
  c1_pdb_x = c1_odb_x;
  c1_su_y = c1_pdb_x / 8.0;
  c1_qdb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_rdb_x = c1_qdb_x;
  c1_rdb_x = muDoubleScalarSin(c1_rdb_x);
  c1_gm_a = c1_b_mn;
  c1_ir_b = c1_rdb_x;
  c1_tu_y = c1_gm_a * c1_ir_b;
  c1_hm_a = c1_tu_y;
  c1_jr_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_uu_y = c1_hm_a * c1_jr_b;
  c1_sdb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_tdb_x = c1_sdb_x;
  c1_tdb_x = muDoubleScalarCos(c1_tdb_x);
  c1_udb_x = c1_q[0] + c1_q[1];
  c1_vdb_x = c1_udb_x;
  c1_vdb_x = muDoubleScalarCos(c1_vdb_x);
  c1_kr_b = c1_vdb_x;
  c1_vu_y = 2.0 * c1_kr_b;
  c1_wdb_x = c1_q[0];
  c1_xdb_x = c1_wdb_x;
  c1_xdb_x = muDoubleScalarCos(c1_xdb_x);
  c1_lr_b = c1_xdb_x;
  c1_wu_y = 2.0 * c1_lr_b;
  c1_im_a = c1_uu_y;
  c1_mr_b = (c1_tdb_x + c1_vu_y) + c1_wu_y;
  c1_xu_y = c1_im_a * c1_mr_b;
  c1_ld_A = c1_xu_y;
  c1_ydb_x = c1_ld_A;
  c1_aeb_x = c1_ydb_x;
  c1_yu_y = c1_aeb_x / 8.0;
  c1_beb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_ceb_x = c1_beb_x;
  c1_ceb_x = muDoubleScalarSin(c1_ceb_x);
  c1_jm_a = c1_b_mn;
  c1_nr_b = c1_ceb_x;
  c1_av_y = c1_jm_a * c1_nr_b;
  c1_km_a = c1_av_y;
  c1_or_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_bv_y = c1_km_a * c1_or_b;
  c1_deb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_eeb_x = c1_deb_x;
  c1_eeb_x = muDoubleScalarCos(c1_eeb_x);
  c1_feb_x = c1_q[0] + c1_q[1];
  c1_geb_x = c1_feb_x;
  c1_geb_x = muDoubleScalarCos(c1_geb_x);
  c1_pr_b = c1_geb_x;
  c1_cv_y = 2.0 * c1_pr_b;
  c1_heb_x = c1_q[0];
  c1_ieb_x = c1_heb_x;
  c1_ieb_x = muDoubleScalarCos(c1_ieb_x);
  c1_qr_b = c1_ieb_x;
  c1_dv_y = 2.0 * c1_qr_b;
  c1_lm_a = c1_bv_y;
  c1_rr_b = (c1_eeb_x + c1_cv_y) + c1_dv_y;
  c1_ev_y = c1_lm_a * c1_rr_b;
  c1_mm_a = c1_ev_y;
  c1_sr_b = (c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2];
  c1_fv_y = c1_mm_a * c1_sr_b;
  c1_md_A = c1_fv_y;
  c1_jeb_x = c1_md_A;
  c1_keb_x = c1_jeb_x;
  c1_gv_y = c1_keb_x / 8.0;
  c1_leb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_meb_x = c1_leb_x;
  c1_meb_x = muDoubleScalarCos(c1_meb_x);
  c1_nm_a = c1_b_mn;
  c1_tr_b = c1_meb_x;
  c1_hv_y = c1_nm_a * c1_tr_b;
  c1_om_a = c1_hv_y;
  c1_ur_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_iv_y = c1_om_a * c1_ur_b;
  c1_neb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_oeb_x = c1_neb_x;
  c1_oeb_x = muDoubleScalarSin(c1_oeb_x);
  c1_peb_x = c1_q[0] + c1_q[1];
  c1_qeb_x = c1_peb_x;
  c1_qeb_x = muDoubleScalarSin(c1_qeb_x);
  c1_vr_b = c1_qeb_x;
  c1_jv_y = 2.0 * c1_vr_b;
  c1_reb_x = c1_q[0];
  c1_seb_x = c1_reb_x;
  c1_seb_x = muDoubleScalarSin(c1_seb_x);
  c1_wr_b = c1_seb_x;
  c1_kv_y = 2.0 * c1_wr_b;
  c1_pm_a = c1_iv_y;
  c1_xr_b = (c1_oeb_x + c1_jv_y) + c1_kv_y;
  c1_lv_y = c1_pm_a * c1_xr_b;
  c1_qm_a = c1_lv_y;
  c1_yr_b = (c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2];
  c1_mv_y = c1_qm_a * c1_yr_b;
  c1_nd_A = c1_mv_y;
  c1_teb_x = c1_nd_A;
  c1_ueb_x = c1_teb_x;
  c1_nv_y = c1_ueb_x / 8.0;
  c1_rm_a = c1_b_mn;
  c1_as_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_ov_y = c1_rm_a * c1_as_b;
  c1_veb_x = (((c1_q[0] - c1_q[1]) - c1_q[2]) - c1_q[0]) + c1_q[1];
  c1_web_x = c1_veb_x;
  c1_web_x = muDoubleScalarSin(c1_web_x);
  c1_sm_a = c1_ov_y;
  c1_bs_b = c1_web_x;
  c1_pv_y = c1_sm_a * c1_bs_b;
  c1_od_A = c1_pv_y;
  c1_xeb_x = c1_od_A;
  c1_yeb_x = c1_xeb_x;
  c1_qv_y = c1_yeb_x / 4.0;
  c1_afb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_bfb_x = c1_afb_x;
  c1_bfb_x = muDoubleScalarCos(c1_bfb_x);
  c1_tm_a = c1_b_mn;
  c1_cs_b = c1_bfb_x;
  c1_rv_y = c1_tm_a * c1_cs_b;
  c1_um_a = c1_rv_y;
  c1_ds_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_sv_y = c1_um_a * c1_ds_b;
  c1_cfb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_dfb_x = c1_cfb_x;
  c1_dfb_x = muDoubleScalarSin(c1_dfb_x);
  c1_efb_x = c1_q[0] + c1_q[1];
  c1_ffb_x = c1_efb_x;
  c1_ffb_x = muDoubleScalarSin(c1_ffb_x);
  c1_es_b = c1_ffb_x;
  c1_tv_y = 2.0 * c1_es_b;
  c1_gfb_x = c1_q[0];
  c1_hfb_x = c1_gfb_x;
  c1_hfb_x = muDoubleScalarSin(c1_hfb_x);
  c1_fs_b = c1_hfb_x;
  c1_uv_y = 2.0 * c1_fs_b;
  c1_vm_a = c1_sv_y;
  c1_gs_b = (c1_dfb_x + c1_tv_y) + c1_uv_y;
  c1_vv_y = c1_vm_a * c1_gs_b;
  c1_pd_A = c1_vv_y;
  c1_ifb_x = c1_pd_A;
  c1_jfb_x = c1_ifb_x;
  c1_wv_y = c1_jfb_x / 4.0;
  c1_kfb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_lfb_x = c1_kfb_x;
  c1_lfb_x = muDoubleScalarSin(c1_lfb_x);
  c1_wm_a = c1_b_mn;
  c1_hs_b = c1_lfb_x;
  c1_xv_y = c1_wm_a * c1_hs_b;
  c1_xm_a = c1_xv_y;
  c1_is_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_yv_y = c1_xm_a * c1_is_b;
  c1_mfb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_nfb_x = c1_mfb_x;
  c1_nfb_x = muDoubleScalarCos(c1_nfb_x);
  c1_ym_a = c1_nfb_x;
  c1_js_b = (c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2];
  c1_aw_y = c1_ym_a * c1_js_b;
  c1_ofb_x = c1_q[0] + c1_q[1];
  c1_pfb_x = c1_ofb_x;
  c1_pfb_x = muDoubleScalarCos(c1_pfb_x);
  c1_ks_b = c1_pfb_x;
  c1_bw_y = 2.0 * c1_ks_b;
  c1_an_a = c1_bw_y;
  c1_ls_b = c1_q_dot[0] + c1_q_dot[1];
  c1_cw_y = c1_an_a * c1_ls_b;
  c1_bn_a = c1_yv_y;
  c1_ms_b = c1_aw_y + c1_cw_y;
  c1_dw_y = c1_bn_a * c1_ms_b;
  c1_qd_A = c1_dw_y;
  c1_qfb_x = c1_qd_A;
  c1_rfb_x = c1_qfb_x;
  c1_ew_y = c1_rfb_x / 8.0;
  c1_sfb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_tfb_x = c1_sfb_x;
  c1_tfb_x = muDoubleScalarCos(c1_tfb_x);
  c1_cn_a = c1_b_mn;
  c1_ns_b = c1_tfb_x;
  c1_fw_y = c1_cn_a * c1_ns_b;
  c1_dn_a = c1_fw_y;
  c1_os_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_gw_y = c1_dn_a * c1_os_b;
  c1_ufb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_vfb_x = c1_ufb_x;
  c1_vfb_x = muDoubleScalarSin(c1_vfb_x);
  c1_en_a = c1_vfb_x;
  c1_ps_b = (c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2];
  c1_hw_y = c1_en_a * c1_ps_b;
  c1_wfb_x = c1_q[0] + c1_q[1];
  c1_xfb_x = c1_wfb_x;
  c1_xfb_x = muDoubleScalarSin(c1_xfb_x);
  c1_qs_b = c1_xfb_x;
  c1_iw_y = 2.0 * c1_qs_b;
  c1_fn_a = c1_iw_y;
  c1_rs_b = c1_q_dot[0] + c1_q_dot[1];
  c1_jw_y = c1_fn_a * c1_rs_b;
  c1_gn_a = c1_gw_y;
  c1_ss_b = c1_hw_y + c1_jw_y;
  c1_kw_y = c1_gn_a * c1_ss_b;
  c1_rd_A = c1_kw_y;
  c1_yfb_x = c1_rd_A;
  c1_agb_x = c1_yfb_x;
  c1_lw_y = c1_agb_x / 8.0;
  c1_bgb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_cgb_x = c1_bgb_x;
  c1_cgb_x = muDoubleScalarSin(c1_cgb_x);
  c1_hn_a = c1_b_mn;
  c1_ts_b = c1_cgb_x;
  c1_mw_y = c1_hn_a * c1_ts_b;
  c1_in_a = c1_mw_y;
  c1_us_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_nw_y = c1_in_a * c1_us_b;
  c1_dgb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_egb_x = c1_dgb_x;
  c1_egb_x = muDoubleScalarCos(c1_egb_x);
  c1_fgb_x = c1_q[0] + c1_q[1];
  c1_ggb_x = c1_fgb_x;
  c1_ggb_x = muDoubleScalarCos(c1_ggb_x);
  c1_vs_b = c1_ggb_x;
  c1_ow_y = 2.0 * c1_vs_b;
  c1_jn_a = c1_nw_y;
  c1_ws_b = c1_egb_x + c1_ow_y;
  c1_pw_y = c1_jn_a * c1_ws_b;
  c1_sd_A = c1_pw_y;
  c1_hgb_x = c1_sd_A;
  c1_igb_x = c1_hgb_x;
  c1_qw_y = c1_igb_x / 4.0;
  c1_jgb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_kgb_x = c1_jgb_x;
  c1_kgb_x = muDoubleScalarCos(c1_kgb_x);
  c1_kn_a = c1_b_mn;
  c1_xs_b = c1_kgb_x;
  c1_rw_y = c1_kn_a * c1_xs_b;
  c1_ln_a = c1_rw_y;
  c1_ys_b = c1_mpower(chartInstance, c1_abs(chartInstance, c1_b_l));
  c1_sw_y = c1_ln_a * c1_ys_b;
  c1_lgb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_mgb_x = c1_lgb_x;
  c1_mgb_x = muDoubleScalarSin(c1_mgb_x);
  c1_ngb_x = c1_q[0] + c1_q[1];
  c1_ogb_x = c1_ngb_x;
  c1_ogb_x = muDoubleScalarSin(c1_ogb_x);
  c1_at_b = c1_ogb_x;
  c1_tw_y = 2.0 * c1_at_b;
  c1_mn_a = c1_sw_y;
  c1_bt_b = c1_mgb_x + c1_tw_y;
  c1_uw_y = c1_mn_a * c1_bt_b;
  c1_td_A = c1_uw_y;
  c1_pgb_x = c1_td_A;
  c1_qgb_x = c1_pgb_x;
  c1_vw_y = c1_qgb_x / 4.0;
  c1_rgb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_sgb_x = c1_rgb_x;
  c1_sgb_x = muDoubleScalarSin(c1_sgb_x);
  c1_nn_a = c1_b_mn;
  c1_ct_b = c1_sgb_x;
  c1_ww_y = c1_nn_a * c1_ct_b;
  c1_tgb_x = c1_b_l;
  c1_ugb_x = c1_tgb_x;
  c1_xw_y = muDoubleScalarAbs(c1_ugb_x);
  c1_on_a = c1_ww_y;
  c1_dt_b = c1_mpower(chartInstance, c1_xw_y);
  c1_yw_y = c1_on_a * c1_dt_b;
  c1_vgb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_wgb_x = c1_vgb_x;
  c1_wgb_x = muDoubleScalarCos(c1_wgb_x);
  c1_xgb_x = c1_q[0] + c1_q[1];
  c1_ygb_x = c1_xgb_x;
  c1_ygb_x = muDoubleScalarCos(c1_ygb_x);
  c1_et_b = c1_ygb_x;
  c1_ax_y = 2.0 * c1_et_b;
  c1_ahb_x = c1_q[0];
  c1_bhb_x = c1_ahb_x;
  c1_bhb_x = muDoubleScalarCos(c1_bhb_x);
  c1_ft_b = c1_bhb_x;
  c1_bx_y = 2.0 * c1_ft_b;
  c1_pn_a = c1_yw_y;
  c1_gt_b = (c1_wgb_x + c1_ax_y) + c1_bx_y;
  c1_cx_y = c1_pn_a * c1_gt_b;
  c1_ud_A = c1_cx_y;
  c1_chb_x = c1_ud_A;
  c1_dhb_x = c1_chb_x;
  c1_dx_y = c1_dhb_x / 4.0;
  c1_ehb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_fhb_x = c1_ehb_x;
  c1_fhb_x = muDoubleScalarSin(c1_fhb_x);
  c1_qn_a = c1_b_mn;
  c1_ht_b = c1_fhb_x;
  c1_ex_y = c1_qn_a * c1_ht_b;
  c1_ghb_x = c1_b_l;
  c1_hhb_x = c1_ghb_x;
  c1_fx_y = muDoubleScalarAbs(c1_hhb_x);
  c1_rn_a = c1_ex_y;
  c1_it_b = c1_mpower(chartInstance, c1_fx_y);
  c1_gx_y = c1_rn_a * c1_it_b;
  c1_ihb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_jhb_x = c1_ihb_x;
  c1_jhb_x = muDoubleScalarCos(c1_jhb_x);
  c1_khb_x = c1_q[0] + c1_q[1];
  c1_lhb_x = c1_khb_x;
  c1_lhb_x = muDoubleScalarCos(c1_lhb_x);
  c1_jt_b = c1_lhb_x;
  c1_hx_y = 2.0 * c1_jt_b;
  c1_sn_a = c1_gx_y;
  c1_kt_b = c1_jhb_x + c1_hx_y;
  c1_ix_y = c1_sn_a * c1_kt_b;
  c1_tn_a = c1_ix_y;
  c1_lt_b = (c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2];
  c1_jx_y = c1_tn_a * c1_lt_b;
  c1_vd_A = c1_jx_y;
  c1_mhb_x = c1_vd_A;
  c1_nhb_x = c1_mhb_x;
  c1_kx_y = c1_nhb_x / 8.0;
  c1_ohb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_phb_x = c1_ohb_x;
  c1_phb_x = muDoubleScalarCos(c1_phb_x);
  c1_un_a = c1_b_mn;
  c1_mt_b = c1_phb_x;
  c1_lx_y = c1_un_a * c1_mt_b;
  c1_qhb_x = c1_b_l;
  c1_rhb_x = c1_qhb_x;
  c1_mx_y = muDoubleScalarAbs(c1_rhb_x);
  c1_vn_a = c1_lx_y;
  c1_nt_b = c1_mpower(chartInstance, c1_mx_y);
  c1_nx_y = c1_vn_a * c1_nt_b;
  c1_shb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_thb_x = c1_shb_x;
  c1_thb_x = muDoubleScalarSin(c1_thb_x);
  c1_uhb_x = c1_q[0] + c1_q[1];
  c1_vhb_x = c1_uhb_x;
  c1_vhb_x = muDoubleScalarSin(c1_vhb_x);
  c1_ot_b = c1_vhb_x;
  c1_ox_y = 2.0 * c1_ot_b;
  c1_wn_a = c1_nx_y;
  c1_pt_b = c1_thb_x + c1_ox_y;
  c1_px_y = c1_wn_a * c1_pt_b;
  c1_xn_a = c1_px_y;
  c1_qt_b = (c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2];
  c1_qx_y = c1_xn_a * c1_qt_b;
  c1_wd_A = c1_qx_y;
  c1_whb_x = c1_wd_A;
  c1_xhb_x = c1_whb_x;
  c1_rx_y = c1_xhb_x / 8.0;
  c1_yhb_x = ((((c1_q[0] - c1_q[1]) - c1_q[2]) - c1_q[0]) + c1_q[1]) + c1_q[2];
  c1_aib_x = c1_yhb_x;
  c1_aib_x = muDoubleScalarSin(c1_aib_x);
  c1_yn_a = c1_b_mn;
  c1_rt_b = c1_aib_x;
  c1_sx_y = c1_yn_a * c1_rt_b;
  c1_bib_x = c1_b_l;
  c1_cib_x = c1_bib_x;
  c1_tx_y = muDoubleScalarAbs(c1_cib_x);
  c1_ao_a = c1_sx_y;
  c1_st_b = c1_mpower(chartInstance, c1_tx_y);
  c1_ux_y = c1_ao_a * c1_st_b;
  c1_bo_a = c1_ux_y;
  c1_tt_b = ((((c1_q_dot[0] + c1_q_dot[1]) + c1_q_dot[2]) - c1_q_dot[0]) -
             c1_q_dot[1]) - c1_q_dot[2];
  c1_vx_y = c1_bo_a * c1_tt_b;
  c1_xd_A = c1_vx_y;
  c1_dib_x = c1_xd_A;
  c1_eib_x = c1_dib_x;
  c1_wx_y = c1_eib_x / 8.0;
  c1_fib_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_gib_x = c1_fib_x;
  c1_gib_x = muDoubleScalarCos(c1_gib_x);
  c1_co_a = c1_b_mn;
  c1_ut_b = c1_gib_x;
  c1_xx_y = c1_co_a * c1_ut_b;
  c1_hib_x = c1_b_l;
  c1_iib_x = c1_hib_x;
  c1_yx_y = muDoubleScalarAbs(c1_iib_x);
  c1_do_a = c1_xx_y;
  c1_vt_b = c1_mpower(chartInstance, c1_yx_y);
  c1_ay_y = c1_do_a * c1_vt_b;
  c1_jib_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_kib_x = c1_jib_x;
  c1_kib_x = muDoubleScalarSin(c1_kib_x);
  c1_lib_x = c1_q[0] + c1_q[1];
  c1_mib_x = c1_lib_x;
  c1_mib_x = muDoubleScalarSin(c1_mib_x);
  c1_wt_b = c1_mib_x;
  c1_by_y = 2.0 * c1_wt_b;
  c1_nib_x = c1_q[0];
  c1_oib_x = c1_nib_x;
  c1_oib_x = muDoubleScalarSin(c1_oib_x);
  c1_xt_b = c1_oib_x;
  c1_cy_y = 2.0 * c1_xt_b;
  c1_eo_a = c1_ay_y;
  c1_yt_b = (c1_kib_x + c1_by_y) + c1_cy_y;
  c1_dy_y = c1_eo_a * c1_yt_b;
  c1_yd_A = c1_dy_y;
  c1_pib_x = c1_yd_A;
  c1_qib_x = c1_pib_x;
  c1_ey_y = c1_qib_x / 4.0;
  c1_rib_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_sib_x = c1_rib_x;
  c1_sib_x = muDoubleScalarCos(c1_sib_x);
  c1_fo_a = c1_b_mn;
  c1_au_b = c1_sib_x;
  c1_fy_y = c1_fo_a * c1_au_b;
  c1_tib_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_uib_x = c1_tib_x;
  c1_uib_x = muDoubleScalarSin(c1_uib_x);
  c1_go_a = c1_fy_y;
  c1_bu_b = c1_uib_x;
  c1_gy_y = c1_go_a * c1_bu_b;
  c1_vib_x = c1_b_l;
  c1_wib_x = c1_vib_x;
  c1_hy_y = muDoubleScalarAbs(c1_wib_x);
  c1_ho_a = c1_gy_y;
  c1_cu_b = c1_mpower(chartInstance, c1_hy_y);
  c1_iy_y = c1_ho_a * c1_cu_b;
  c1_ae_A = c1_iy_y;
  c1_xib_x = c1_ae_A;
  c1_yib_x = c1_xib_x;
  c1_jy_y = c1_yib_x / 2.0;
  c1_ajb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_bjb_x = c1_ajb_x;
  c1_bjb_x = muDoubleScalarSin(c1_bjb_x);
  c1_io_a = c1_b_mn;
  c1_du_b = c1_bjb_x;
  c1_ky_y = c1_io_a * c1_du_b;
  c1_cjb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_djb_x = c1_cjb_x;
  c1_djb_x = muDoubleScalarCos(c1_djb_x);
  c1_jo_a = c1_ky_y;
  c1_eu_b = c1_djb_x;
  c1_ly_y = c1_jo_a * c1_eu_b;
  c1_ejb_x = c1_b_l;
  c1_fjb_x = c1_ejb_x;
  c1_my_y = muDoubleScalarAbs(c1_fjb_x);
  c1_ko_a = c1_ly_y;
  c1_fu_b = c1_mpower(chartInstance, c1_my_y);
  c1_ny_y = c1_ko_a * c1_fu_b;
  c1_be_A = c1_ny_y;
  c1_gjb_x = c1_be_A;
  c1_hjb_x = c1_gjb_x;
  c1_oy_y = c1_hjb_x / 2.0;
  c1_ijb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_jjb_x = c1_ijb_x;
  c1_jjb_x = muDoubleScalarSin(c1_jjb_x);
  c1_lo_a = c1_b_mn;
  c1_gu_b = c1_jjb_x;
  c1_py_y = c1_lo_a * c1_gu_b;
  c1_kjb_x = c1_b_l;
  c1_ljb_x = c1_kjb_x;
  c1_qy_y = muDoubleScalarAbs(c1_ljb_x);
  c1_mo_a = c1_py_y;
  c1_hu_b = c1_mpower(chartInstance, c1_qy_y);
  c1_ry_y = c1_mo_a * c1_hu_b;
  c1_mjb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_njb_x = c1_mjb_x;
  c1_njb_x = muDoubleScalarCos(c1_njb_x);
  c1_ojb_x = c1_q[0] + c1_q[1];
  c1_pjb_x = c1_ojb_x;
  c1_pjb_x = muDoubleScalarCos(c1_pjb_x);
  c1_iu_b = c1_pjb_x;
  c1_sy_y = 2.0 * c1_iu_b;
  c1_no_a = c1_ry_y;
  c1_ju_b = c1_njb_x + c1_sy_y;
  c1_ty_y = c1_no_a * c1_ju_b;
  c1_ce_A = c1_ty_y;
  c1_qjb_x = c1_ce_A;
  c1_rjb_x = c1_qjb_x;
  c1_uy_y = c1_rjb_x / 4.0;
  c1_sjb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_tjb_x = c1_sjb_x;
  c1_tjb_x = muDoubleScalarCos(c1_tjb_x);
  c1_oo_a = c1_b_mn;
  c1_ku_b = c1_tjb_x;
  c1_vy_y = c1_oo_a * c1_ku_b;
  c1_ujb_x = c1_b_l;
  c1_vjb_x = c1_ujb_x;
  c1_wy_y = muDoubleScalarAbs(c1_vjb_x);
  c1_po_a = c1_vy_y;
  c1_lu_b = c1_mpower(chartInstance, c1_wy_y);
  c1_xy_y = c1_po_a * c1_lu_b;
  c1_wjb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_xjb_x = c1_wjb_x;
  c1_xjb_x = muDoubleScalarSin(c1_xjb_x);
  c1_yjb_x = c1_q[0] + c1_q[1];
  c1_akb_x = c1_yjb_x;
  c1_akb_x = muDoubleScalarSin(c1_akb_x);
  c1_mu_b = c1_akb_x;
  c1_yy_y = 2.0 * c1_mu_b;
  c1_qo_a = c1_xy_y;
  c1_nu_b = c1_xjb_x + c1_yy_y;
  c1_aab_y = c1_qo_a * c1_nu_b;
  c1_de_A = c1_aab_y;
  c1_bkb_x = c1_de_A;
  c1_ckb_x = c1_bkb_x;
  c1_bab_y = c1_ckb_x / 4.0;
  c1_dkb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_ekb_x = c1_dkb_x;
  c1_ekb_x = muDoubleScalarSin(c1_ekb_x);
  c1_ro_a = c1_b_mn;
  c1_ou_b = c1_ekb_x;
  c1_cab_y = c1_ro_a * c1_ou_b;
  c1_fkb_x = c1_b_l;
  c1_gkb_x = c1_fkb_x;
  c1_dab_y = muDoubleScalarAbs(c1_gkb_x);
  c1_so_a = c1_cab_y;
  c1_pu_b = c1_mpower(chartInstance, c1_dab_y);
  c1_eab_y = c1_so_a * c1_pu_b;
  c1_hkb_x = (c1_q[0] + c1_q[1]) + c1_q[2];
  c1_ikb_x = c1_hkb_x;
  c1_ikb_x = muDoubleScalarCos(c1_ikb_x);
  c1_jkb_x = c1_q[0] + c1_q[1];
  c1_kkb_x = c1_jkb_x;
  c1_kkb_x = muDoubleScalarCos(c1_kkb_x);
  c1_qu_b = c1_kkb_x;
  c1_fab_y = 2.0 * c1_qu_b;
  c1_lkb_x = c1_q[0];
  c1_mkb_x = c1_lkb_x;
  c1_mkb_x = muDoubleScalarCos(c1_mkb_x);
  c1_ru_b = c1_mkb_x;
  c1_gab_y = 2.0 * c1_ru_b;
  c1_to_a = c1_eab_y;
  c1_su_b = (c1_ikb_x + c1_fab_y) + c1_gab_y;
  c1_hab_y = c1_to_a * c1_su_b;
  c1_ee_A = c1_hab_y;
  c1_nkb_x = c1_ee_A;
  c1_okb_x = c1_nkb_x;
  c1_iab_y = c1_okb_x / 4.0;
  c1_C[0] = ((((((((((c1_k_y - c1_v_y) + c1_eb_y) - c1_mb_y) - c1_ub_y) +
                  c1_dc_y) + c1_oc_y) - c1_ad_y) - c1_fd_y) + c1_kd_y) + c1_pd_y)
    - c1_ud_y;
  c1_C[3] = ((((((((((((((c1_xd_y + c1_ce_y) + c1_ge_y) + c1_ke_y) - c1_pe_y) +
                      c1_ue_y) - c1_cf_y) + c1_jf_y) - c1_nf_y) - c1_uf_y) +
                 c1_cg_y) - c1_hg_y) + c1_mg_y) + c1_rg_y) + c1_wg_y) + c1_bh_y;
  c1_C[6] = (((((((c1_eh_y + c1_jh_y) + c1_rh_y) + c1_uh_y) - c1_xh_y) + c1_ei_y)
              - c1_ki_y) + c1_qi_y) - c1_wi_y;
  c1_C[1] = ((((((((((((((((c1_aj_y + c1_ej_y) - c1_oj_y) - c1_tj_y) + c1_yj_y)
                        - c1_gk_y) + c1_nk_y) - c1_wk_y) + c1_gl_y) - c1_nl_y) +
                   c1_ul_y) - c1_am_y) + c1_fm_y) + c1_mm_y) - c1_tm_y) +
              c1_en_y) - c1_kn_y) + c1_qn_y;
  c1_C[4] = ((((((((((((((c1_un_y - c1_yn_y) - c1_go_y) + c1_no_y) - c1_vo_y) +
                      c1_ep_y) - c1_mp_y) + c1_up_y) - c1_aq_y) + c1_fq_y) -
                 c1_lq_y) + c1_rq_y) + c1_wq_y) - c1_cr_y) - c1_hr_y) + c1_mr_y;
  c1_C[7] = ((((c1_sr_y + c1_vr_y) + c1_cs_y) - c1_hs_y) + c1_ms_y) - c1_ss_y;
  c1_C[2] = ((((((((((c1_vs_y + c1_bt_y) + c1_et_y) - c1_ht_y) + c1_nt_y) -
                  c1_tt_y) + c1_au_y) + c1_ju_y) - c1_su_y) - c1_yu_y) - c1_gv_y)
    + c1_nv_y;
  c1_C[5] = (((((((c1_qv_y + c1_wv_y) + c1_ew_y) - c1_lw_y) - c1_qw_y) + c1_vw_y)
              - c1_dx_y) - c1_kx_y) + c1_rx_y;
  c1_C[8] = (((((c1_wx_y + c1_ey_y) + c1_jy_y) - c1_oy_y) - c1_uy_y) + c1_bab_y)
    - c1_iab_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  for (c1_i8 = 0; c1_i8 < 9; c1_i8++) {
    (*c1_b_C)[c1_i8] = c1_C[c1_i8];
  }

  for (c1_i9 = 0; c1_i9 < 3; c1_i9++) {
    (*c1_b_q_dot)[c1_i9] = c1_q_dot[c1_i9];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_ManipulatorME4901
  (SFc1_ManipulatorME4901InstanceStruct *chartInstance)
{
}

static void registerMessagesc1_ManipulatorME4901
  (SFc1_ManipulatorME4901InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i10;
  real_T c1_b_inData[3];
  int32_T c1_i11;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc1_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i10 = 0; c1_i10 < 3; c1_i10++) {
    c1_b_inData[c1_i10] = (*(real_T (*)[3])c1_inData)[c1_i10];
  }

  for (c1_i11 = 0; c1_i11 < 3; c1_i11++) {
    c1_u[c1_i11] = c1_b_inData[c1_i11];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c1_q_dot, const char_T *c1_identifier, real_T
  c1_y[3])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_q_dot), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_q_dot);
}

static void c1_b_emlrt_marshallIn(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[3])
{
  real_T c1_dv2[3];
  int32_T c1_i12;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv2, 1, 0, 0U, 1, 0U, 1, 3);
  for (c1_i12 = 0; c1_i12 < 3; c1_i12++) {
    c1_y[c1_i12] = c1_dv2[c1_i12];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_q_dot;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[3];
  int32_T c1_i13;
  SFc1_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc1_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c1_q_dot = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_q_dot), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_q_dot);
  for (c1_i13 = 0; c1_i13 < 3; c1_i13++) {
    (*(real_T (*)[3])c1_outData)[c1_i13] = c1_y[c1_i13];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  real_T c1_b_inData[9];
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  real_T c1_u[9];
  const mxArray *c1_y = NULL;
  SFc1_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc1_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i14 = 0;
  for (c1_i15 = 0; c1_i15 < 3; c1_i15++) {
    for (c1_i16 = 0; c1_i16 < 3; c1_i16++) {
      c1_b_inData[c1_i16 + c1_i14] = (*(real_T (*)[9])c1_inData)[c1_i16 + c1_i14];
    }

    c1_i14 += 3;
  }

  c1_i17 = 0;
  for (c1_i18 = 0; c1_i18 < 3; c1_i18++) {
    for (c1_i19 = 0; c1_i19 < 3; c1_i19++) {
      c1_u[c1_i19 + c1_i17] = c1_b_inData[c1_i19 + c1_i17];
    }

    c1_i17 += 3;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_c_emlrt_marshallIn(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c1_C, const char_T *c1_identifier, real_T c1_y
  [9])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_C), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_C);
}

static void c1_d_emlrt_marshallIn(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[9])
{
  real_T c1_dv3[9];
  int32_T c1_i20;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv3, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c1_i20 = 0; c1_i20 < 9; c1_i20++) {
    c1_y[c1_i20] = c1_dv3[c1_i20];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_C;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[9];
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  SFc1_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc1_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c1_C = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_C), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_C);
  c1_i21 = 0;
  for (c1_i22 = 0; c1_i22 < 3; c1_i22++) {
    for (c1_i23 = 0; c1_i23 < 3; c1_i23++) {
      (*(real_T (*)[9])c1_outData)[c1_i23 + c1_i21] = c1_y[c1_i23 + c1_i21];
    }

    c1_i21 += 3;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc1_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_e_emlrt_marshallIn(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d2;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d2, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d2;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_l;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc1_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c1_b_l = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_l), &c1_thisId);
  sf_mex_destroy(&c1_b_l);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i24;
  real_T c1_b_inData[9];
  int32_T c1_i25;
  real_T c1_u[9];
  const mxArray *c1_y = NULL;
  SFc1_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc1_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i24 = 0; c1_i24 < 9; c1_i24++) {
    c1_b_inData[c1_i24] = (*(real_T (*)[9])c1_inData)[c1_i24];
  }

  for (c1_i25 = 0; c1_i25 < 9; c1_i25++) {
    c1_u[c1_i25] = c1_b_inData[c1_i25];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 9), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

const mxArray *sf_c1_ManipulatorME4901_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[19];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i26;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 19), FALSE);
  for (c1_i26 = 0; c1_i26 < 19; c1_i26++) {
    c1_r0 = &c1_info[c1_i26];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i26);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i26);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i26);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i26);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i26);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i26);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i26);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i26);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[19])
{
  c1_info[0].context = "";
  c1_info[0].name = "abs";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[0].fileTimeLo = 1343862766U;
  c1_info[0].fileTimeHi = 0U;
  c1_info[0].mFileTimeLo = 0U;
  c1_info[0].mFileTimeHi = 0U;
  c1_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[1].name = "eml_scalar_abs";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[1].fileTimeLo = 1286851112U;
  c1_info[1].fileTimeHi = 0U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context = "";
  c1_info[2].name = "mpower";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[2].fileTimeLo = 1286851242U;
  c1_info[2].fileTimeHi = 0U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[3].name = "power";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[3].fileTimeLo = 1348224330U;
  c1_info[3].fileTimeHi = 0U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[4].name = "eml_scalar_eg";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[4].fileTimeLo = 1286851196U;
  c1_info[4].fileTimeHi = 0U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[5].name = "eml_scalexp_alloc";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[5].fileTimeLo = 1352457260U;
  c1_info[5].fileTimeHi = 0U;
  c1_info[5].mFileTimeLo = 0U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[6].name = "floor";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[6].fileTimeLo = 1343862780U;
  c1_info[6].fileTimeHi = 0U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[7].name = "eml_scalar_floor";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[7].fileTimeLo = 1286851126U;
  c1_info[7].fileTimeHi = 0U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c1_info[8].name = "eml_scalar_eg";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[8].fileTimeLo = 1286851196U;
  c1_info[8].fileTimeHi = 0U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c1_info[9].name = "mtimes";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[9].fileTimeLo = 1289552092U;
  c1_info[9].fileTimeHi = 0U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context = "";
  c1_info[10].name = "mtimes";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[10].fileTimeLo = 1289552092U;
  c1_info[10].fileTimeHi = 0U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context = "";
  c1_info[11].name = "sin";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[11].fileTimeLo = 1343862786U;
  c1_info[11].fileTimeHi = 0U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[12].name = "eml_scalar_sin";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c1_info[12].fileTimeLo = 1286851136U;
  c1_info[12].fileTimeHi = 0U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context = "";
  c1_info[13].name = "cos";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[13].fileTimeLo = 1343862772U;
  c1_info[13].fileTimeHi = 0U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
  c1_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[14].name = "eml_scalar_cos";
  c1_info[14].dominantType = "double";
  c1_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c1_info[14].fileTimeLo = 1286851122U;
  c1_info[14].fileTimeHi = 0U;
  c1_info[14].mFileTimeLo = 0U;
  c1_info[14].mFileTimeHi = 0U;
  c1_info[15].context = "";
  c1_info[15].name = "mrdivide";
  c1_info[15].dominantType = "double";
  c1_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[15].fileTimeLo = 1357983948U;
  c1_info[15].fileTimeHi = 0U;
  c1_info[15].mFileTimeLo = 1319762366U;
  c1_info[15].mFileTimeHi = 0U;
  c1_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[16].name = "rdivide";
  c1_info[16].dominantType = "double";
  c1_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[16].fileTimeLo = 1346542788U;
  c1_info[16].fileTimeHi = 0U;
  c1_info[16].mFileTimeLo = 0U;
  c1_info[16].mFileTimeHi = 0U;
  c1_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[17].name = "eml_scalexp_compatible";
  c1_info[17].dominantType = "double";
  c1_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c1_info[17].fileTimeLo = 1286851196U;
  c1_info[17].fileTimeHi = 0U;
  c1_info[17].mFileTimeLo = 0U;
  c1_info[17].mFileTimeHi = 0U;
  c1_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[18].name = "eml_div";
  c1_info[18].dominantType = "double";
  c1_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[18].fileTimeLo = 1313380210U;
  c1_info[18].fileTimeHi = 0U;
  c1_info[18].mFileTimeLo = 0U;
  c1_info[18].mFileTimeHi = 0U;
}

static real_T c1_abs(SFc1_ManipulatorME4901InstanceStruct *chartInstance, real_T
                     c1_x)
{
  real_T c1_b_x;
  c1_b_x = c1_x;
  return muDoubleScalarAbs(c1_b_x);
}

static real_T c1_mpower(SFc1_ManipulatorME4901InstanceStruct *chartInstance,
  real_T c1_a)
{
  real_T c1_b_a;
  real_T c1_c_a;
  real_T c1_ak;
  real_T c1_d_a;
  real_T c1_e_a;
  real_T c1_b;
  c1_b_a = c1_a;
  c1_c_a = c1_b_a;
  c1_eml_scalar_eg(chartInstance);
  c1_ak = c1_c_a;
  c1_d_a = c1_ak;
  c1_eml_scalar_eg(chartInstance);
  c1_e_a = c1_d_a;
  c1_b = c1_d_a;
  return c1_e_a * c1_b;
}

static void c1_eml_scalar_eg(SFc1_ManipulatorME4901InstanceStruct *chartInstance)
{
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc1_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_f_emlrt_marshallIn(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i27;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i27, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i27;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc1_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_g_emlrt_marshallIn(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_ManipulatorME4901, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_ManipulatorME4901), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_ManipulatorME4901);
  return c1_y;
}

static uint8_T c1_h_emlrt_marshallIn(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_ManipulatorME4901InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c1_ManipulatorME4901_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3843986552U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3127651809U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2718620663U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3652689248U);
}

mxArray *sf_c1_ManipulatorME4901_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("35YgniRQzAlpSCpVVCp6zF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(9);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_ManipulatorME4901_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_ManipulatorME4901(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[8],T\"C\",},{M[1],M[12],T\"q_dot\",},{M[8],M[0],T\"is_active_c1_ManipulatorME4901\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_ManipulatorME4901_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_ManipulatorME4901InstanceStruct *chartInstance;
    chartInstance = (SFc1_ManipulatorME4901InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ManipulatorME4901MachineNumber_,
           1,
           1,
           1,
           5,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_ManipulatorME4901MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_ManipulatorME4901MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ManipulatorME4901MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"qqd");
          _SFD_SET_DATA_PROPS(1,2,0,1,"C");
          _SFD_SET_DATA_PROPS(2,10,0,0,"mn");
          _SFD_SET_DATA_PROPS(3,10,0,0,"l");
          _SFD_SET_DATA_PROPS(4,2,0,1,"q_dot");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,16829);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)
            c1_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)c1_c_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          real_T (*c1_qqd)[9];
          real_T (*c1_C)[9];
          real_T (*c1_q_dot)[3];
          c1_q_dot = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c1_C = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_qqd);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_C);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c1_mn);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c1_l);
          _SFD_SET_DATA_VALUE_PTR(4U, *c1_q_dot);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ManipulatorME4901MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "4qFMEHVEjuYWw9rmKQw8TB";
}

static void sf_opaque_initialize_c1_ManipulatorME4901(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_ManipulatorME4901InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_ManipulatorME4901((SFc1_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
  initialize_c1_ManipulatorME4901((SFc1_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_ManipulatorME4901(void *chartInstanceVar)
{
  enable_c1_ManipulatorME4901((SFc1_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_ManipulatorME4901(void *chartInstanceVar)
{
  disable_c1_ManipulatorME4901((SFc1_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_ManipulatorME4901(void *chartInstanceVar)
{
  sf_c1_ManipulatorME4901((SFc1_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_ManipulatorME4901(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_ManipulatorME4901
    ((SFc1_ManipulatorME4901InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_ManipulatorME4901();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_ManipulatorME4901(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_ManipulatorME4901();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_ManipulatorME4901((SFc1_ManipulatorME4901InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_ManipulatorME4901(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_ManipulatorME4901(S);
}

static void sf_opaque_set_sim_state_c1_ManipulatorME4901(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_ManipulatorME4901(S, st);
}

static void sf_opaque_terminate_c1_ManipulatorME4901(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_ManipulatorME4901InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ManipulatorME4901_optimization_info();
    }

    finalize_c1_ManipulatorME4901((SFc1_ManipulatorME4901InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_ManipulatorME4901((SFc1_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_ManipulatorME4901(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_ManipulatorME4901((SFc1_ManipulatorME4901InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_ManipulatorME4901(SimStruct *S)
{
  /* Actual parameters from chart:
     l mn
   */
  const char_T *rtParamNames[] = { "l", "mn" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for l*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for mn*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ManipulatorME4901_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(180717517U));
  ssSetChecksum1(S,(2748165577U));
  ssSetChecksum2(S,(3932819350U));
  ssSetChecksum3(S,(3396734043U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_ManipulatorME4901(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_ManipulatorME4901(SimStruct *S)
{
  SFc1_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc1_ManipulatorME4901InstanceStruct *)utMalloc(sizeof
    (SFc1_ManipulatorME4901InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_ManipulatorME4901InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_ManipulatorME4901;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_ManipulatorME4901;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_ManipulatorME4901;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_ManipulatorME4901;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_ManipulatorME4901;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_ManipulatorME4901;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_ManipulatorME4901;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_ManipulatorME4901;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_ManipulatorME4901;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_ManipulatorME4901;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_ManipulatorME4901;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_ManipulatorME4901_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_ManipulatorME4901(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_ManipulatorME4901(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_ManipulatorME4901(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_ManipulatorME4901_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
