/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ManipulatorME4901_sfun.h"
#include "c3_ManipulatorME4901.h"
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
static const char * c3_debug_family_names[8] = { "q", "nargin", "nargout", "qqd",
  "m", "l", "C", "q_dot" };

/* Function Declarations */
static void initialize_c3_ManipulatorME4901(SFc3_ManipulatorME4901InstanceStruct
  *chartInstance);
static void initialize_params_c3_ManipulatorME4901
  (SFc3_ManipulatorME4901InstanceStruct *chartInstance);
static void enable_c3_ManipulatorME4901(SFc3_ManipulatorME4901InstanceStruct
  *chartInstance);
static void disable_c3_ManipulatorME4901(SFc3_ManipulatorME4901InstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_ManipulatorME4901
  (SFc3_ManipulatorME4901InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_ManipulatorME4901
  (SFc3_ManipulatorME4901InstanceStruct *chartInstance);
static void set_sim_state_c3_ManipulatorME4901
  (SFc3_ManipulatorME4901InstanceStruct *chartInstance, const mxArray *c3_st);
static void finalize_c3_ManipulatorME4901(SFc3_ManipulatorME4901InstanceStruct
  *chartInstance);
static void sf_c3_ManipulatorME4901(SFc3_ManipulatorME4901InstanceStruct
  *chartInstance);
static void c3_chartstep_c3_ManipulatorME4901
  (SFc3_ManipulatorME4901InstanceStruct *chartInstance);
static void initSimStructsc3_ManipulatorME4901
  (SFc3_ManipulatorME4901InstanceStruct *chartInstance);
static void registerMessagesc3_ManipulatorME4901
  (SFc3_ManipulatorME4901InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static void c3_emlrt_marshallIn(SFc3_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c3_q_dot, const char_T *c3_identifier, real_T
  c3_y[3]);
static void c3_b_emlrt_marshallIn(SFc3_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[3]);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_c_emlrt_marshallIn(SFc3_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c3_C, const char_T *c3_identifier, real_T c3_y
  [9]);
static void c3_d_emlrt_marshallIn(SFc3_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[9]);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_e_emlrt_marshallIn(SFc3_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[19]);
static real_T c3_abs(SFc3_ManipulatorME4901InstanceStruct *chartInstance, real_T
                     c3_x);
static real_T c3_mpower(SFc3_ManipulatorME4901InstanceStruct *chartInstance,
  real_T c3_a);
static void c3_eml_scalar_eg(SFc3_ManipulatorME4901InstanceStruct *chartInstance);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_f_emlrt_marshallIn(SFc3_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_g_emlrt_marshallIn(SFc3_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_ManipulatorME4901, const
  char_T *c3_identifier);
static uint8_T c3_h_emlrt_marshallIn(SFc3_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_ManipulatorME4901InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_ManipulatorME4901(SFc3_ManipulatorME4901InstanceStruct
  *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_ManipulatorME4901 = 0U;
}

static void initialize_params_c3_ManipulatorME4901
  (SFc3_ManipulatorME4901InstanceStruct *chartInstance)
{
  real_T c3_d0;
  real_T c3_d1;
  sf_set_error_prefix_string(
    "Error evaluating data 'm' in the parent workspace.\n");
  sf_mex_import_named("m", sf_mex_get_sfun_param(chartInstance->S, 1, 0), &c3_d0,
                      0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_m = c3_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'l' in the parent workspace.\n");
  sf_mex_import_named("l", sf_mex_get_sfun_param(chartInstance->S, 0, 0), &c3_d1,
                      0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_l = c3_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c3_ManipulatorME4901(SFc3_ManipulatorME4901InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_ManipulatorME4901(SFc3_ManipulatorME4901InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_ManipulatorME4901
  (SFc3_ManipulatorME4901InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c3_ManipulatorME4901
  (SFc3_ManipulatorME4901InstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  int32_T c3_i0;
  real_T c3_u[9];
  const mxArray *c3_b_y = NULL;
  int32_T c3_i1;
  real_T c3_b_u[3];
  const mxArray *c3_c_y = NULL;
  uint8_T c3_hoistedGlobal;
  uint8_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T (*c3_q_dot)[3];
  real_T (*c3_C)[9];
  c3_q_dot = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_C = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(3), FALSE);
  for (c3_i0 = 0; c3_i0 < 9; c3_i0++) {
    c3_u[c3_i0] = (*c3_C)[c3_i0];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  for (c3_i1 = 0; c3_i1 < 3; c3_i1++) {
    c3_b_u[c3_i1] = (*c3_q_dot)[c3_i1];
  }

  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_b_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_hoistedGlobal = chartInstance->c3_is_active_c3_ManipulatorME4901;
  c3_c_u = c3_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_ManipulatorME4901
  (SFc3_ManipulatorME4901InstanceStruct *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[9];
  int32_T c3_i2;
  real_T c3_dv1[3];
  int32_T c3_i3;
  real_T (*c3_C)[9];
  real_T (*c3_q_dot)[3];
  c3_q_dot = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_C = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)), "C",
                        c3_dv0);
  for (c3_i2 = 0; c3_i2 < 9; c3_i2++) {
    (*c3_C)[c3_i2] = c3_dv0[c3_i2];
  }

  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
                      "q_dot", c3_dv1);
  for (c3_i3 = 0; c3_i3 < 3; c3_i3++) {
    (*c3_q_dot)[c3_i3] = c3_dv1[c3_i3];
  }

  chartInstance->c3_is_active_c3_ManipulatorME4901 = c3_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 2)),
     "is_active_c3_ManipulatorME4901");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_ManipulatorME4901(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_ManipulatorME4901(SFc3_ManipulatorME4901InstanceStruct
  *chartInstance)
{
}

static void sf_c3_ManipulatorME4901(SFc3_ManipulatorME4901InstanceStruct
  *chartInstance)
{
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_i6;
  real_T (*c3_q_dot)[3];
  real_T (*c3_C)[9];
  real_T (*c3_qqd)[9];
  c3_q_dot = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_C = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  for (c3_i4 = 0; c3_i4 < 9; c3_i4++) {
    _SFD_DATA_RANGE_CHECK((*c3_qqd)[c3_i4], 0U);
  }

  for (c3_i5 = 0; c3_i5 < 9; c3_i5++) {
    _SFD_DATA_RANGE_CHECK((*c3_C)[c3_i5], 1U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c3_m, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_l, 3U);
  for (c3_i6 = 0; c3_i6 < 3; c3_i6++) {
    _SFD_DATA_RANGE_CHECK((*c3_q_dot)[c3_i6], 4U);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_ManipulatorME4901(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ManipulatorME4901MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_ManipulatorME4901
  (SFc3_ManipulatorME4901InstanceStruct *chartInstance)
{
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  int32_T c3_i7;
  real_T c3_qqd[9];
  real_T c3_b_m;
  real_T c3_b_l;
  uint32_T c3_debug_family_var_map[8];
  real_T c3_q[3];
  real_T c3_nargin = 3.0;
  real_T c3_nargout = 2.0;
  real_T c3_C[9];
  real_T c3_q_dot[3];
  real_T c3_a;
  real_T c3_b;
  real_T c3_y;
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_b_b;
  real_T c3_b_y;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_c_b;
  real_T c3_c_y;
  real_T c3_b_a;
  real_T c3_d_b;
  real_T c3_d_y;
  real_T c3_g_x;
  real_T c3_h_x;
  real_T c3_c_a;
  real_T c3_e_b;
  real_T c3_e_y;
  real_T c3_i_x;
  real_T c3_j_x;
  real_T c3_f_b;
  real_T c3_f_y;
  real_T c3_d_a;
  real_T c3_g_b;
  real_T c3_g_y;
  real_T c3_h_b;
  real_T c3_h_y;
  real_T c3_k_x;
  real_T c3_l_x;
  real_T c3_e_a;
  real_T c3_i_b;
  real_T c3_i_y;
  real_T c3_f_a;
  real_T c3_j_b;
  real_T c3_j_y;
  real_T c3_A;
  real_T c3_m_x;
  real_T c3_n_x;
  real_T c3_k_y;
  real_T c3_g_a;
  real_T c3_k_b;
  real_T c3_l_y;
  real_T c3_o_x;
  real_T c3_p_x;
  real_T c3_l_b;
  real_T c3_m_y;
  real_T c3_q_x;
  real_T c3_r_x;
  real_T c3_s_x;
  real_T c3_t_x;
  real_T c3_m_b;
  real_T c3_n_y;
  real_T c3_h_a;
  real_T c3_n_b;
  real_T c3_o_y;
  real_T c3_u_x;
  real_T c3_v_x;
  real_T c3_i_a;
  real_T c3_o_b;
  real_T c3_p_y;
  real_T c3_w_x;
  real_T c3_x_x;
  real_T c3_p_b;
  real_T c3_q_y;
  real_T c3_j_a;
  real_T c3_q_b;
  real_T c3_r_y;
  real_T c3_r_b;
  real_T c3_s_y;
  real_T c3_y_x;
  real_T c3_ab_x;
  real_T c3_k_a;
  real_T c3_s_b;
  real_T c3_t_y;
  real_T c3_l_a;
  real_T c3_t_b;
  real_T c3_u_y;
  real_T c3_b_A;
  real_T c3_bb_x;
  real_T c3_cb_x;
  real_T c3_v_y;
  real_T c3_m_a;
  real_T c3_u_b;
  real_T c3_w_y;
  real_T c3_db_x;
  real_T c3_eb_x;
  real_T c3_n_a;
  real_T c3_v_b;
  real_T c3_x_y;
  real_T c3_w_b;
  real_T c3_y_y;
  real_T c3_fb_x;
  real_T c3_gb_x;
  real_T c3_o_a;
  real_T c3_x_b;
  real_T c3_ab_y;
  real_T c3_p_a;
  real_T c3_y_b;
  real_T c3_bb_y;
  real_T c3_hb_x;
  real_T c3_ib_x;
  real_T c3_ab_b;
  real_T c3_cb_y;
  real_T c3_jb_x;
  real_T c3_kb_x;
  real_T c3_q_a;
  real_T c3_bb_b;
  real_T c3_db_y;
  real_T c3_c_A;
  real_T c3_lb_x;
  real_T c3_mb_x;
  real_T c3_eb_y;
  real_T c3_r_a;
  real_T c3_cb_b;
  real_T c3_fb_y;
  real_T c3_nb_x;
  real_T c3_ob_x;
  real_T c3_db_b;
  real_T c3_gb_y;
  real_T c3_pb_x;
  real_T c3_qb_x;
  real_T c3_s_a;
  real_T c3_eb_b;
  real_T c3_hb_y;
  real_T c3_rb_x;
  real_T c3_sb_x;
  real_T c3_t_a;
  real_T c3_fb_b;
  real_T c3_ib_y;
  real_T c3_gb_b;
  real_T c3_jb_y;
  real_T c3_tb_x;
  real_T c3_ub_x;
  real_T c3_u_a;
  real_T c3_hb_b;
  real_T c3_kb_y;
  real_T c3_v_a;
  real_T c3_ib_b;
  real_T c3_lb_y;
  real_T c3_d_A;
  real_T c3_vb_x;
  real_T c3_wb_x;
  real_T c3_mb_y;
  real_T c3_w_a;
  real_T c3_jb_b;
  real_T c3_nb_y;
  real_T c3_xb_x;
  real_T c3_yb_x;
  real_T c3_ac_x;
  real_T c3_bc_x;
  real_T c3_kb_b;
  real_T c3_ob_y;
  real_T c3_x_a;
  real_T c3_lb_b;
  real_T c3_pb_y;
  real_T c3_cc_x;
  real_T c3_dc_x;
  real_T c3_mb_b;
  real_T c3_qb_y;
  real_T c3_y_a;
  real_T c3_nb_b;
  real_T c3_rb_y;
  real_T c3_ec_x;
  real_T c3_fc_x;
  real_T c3_ab_a;
  real_T c3_ob_b;
  real_T c3_sb_y;
  real_T c3_bb_a;
  real_T c3_pb_b;
  real_T c3_tb_y;
  real_T c3_e_A;
  real_T c3_gc_x;
  real_T c3_hc_x;
  real_T c3_ub_y;
  real_T c3_cb_a;
  real_T c3_qb_b;
  real_T c3_vb_y;
  real_T c3_ic_x;
  real_T c3_jc_x;
  real_T c3_kc_x;
  real_T c3_lc_x;
  real_T c3_rb_b;
  real_T c3_wb_y;
  real_T c3_db_a;
  real_T c3_sb_b;
  real_T c3_xb_y;
  real_T c3_mc_x;
  real_T c3_nc_x;
  real_T c3_tb_b;
  real_T c3_yb_y;
  real_T c3_eb_a;
  real_T c3_ub_b;
  real_T c3_ac_y;
  real_T c3_oc_x;
  real_T c3_pc_x;
  real_T c3_fb_a;
  real_T c3_vb_b;
  real_T c3_bc_y;
  real_T c3_gb_a;
  real_T c3_wb_b;
  real_T c3_cc_y;
  real_T c3_f_A;
  real_T c3_qc_x;
  real_T c3_rc_x;
  real_T c3_dc_y;
  real_T c3_hb_a;
  real_T c3_xb_b;
  real_T c3_ec_y;
  real_T c3_sc_x;
  real_T c3_tc_x;
  real_T c3_yb_b;
  real_T c3_fc_y;
  real_T c3_ib_a;
  real_T c3_ac_b;
  real_T c3_gc_y;
  real_T c3_uc_x;
  real_T c3_vc_x;
  real_T c3_jb_a;
  real_T c3_bc_b;
  real_T c3_hc_y;
  real_T c3_wc_x;
  real_T c3_xc_x;
  real_T c3_cc_b;
  real_T c3_ic_y;
  real_T c3_kb_a;
  real_T c3_dc_b;
  real_T c3_jc_y;
  real_T c3_lb_a;
  real_T c3_ec_b;
  real_T c3_kc_y;
  real_T c3_yc_x;
  real_T c3_ad_x;
  real_T c3_bd_x;
  real_T c3_cd_x;
  real_T c3_fc_b;
  real_T c3_lc_y;
  real_T c3_dd_x;
  real_T c3_ed_x;
  real_T c3_gc_b;
  real_T c3_mc_y;
  real_T c3_mb_a;
  real_T c3_hc_b;
  real_T c3_nc_y;
  real_T c3_g_A;
  real_T c3_fd_x;
  real_T c3_gd_x;
  real_T c3_oc_y;
  real_T c3_nb_a;
  real_T c3_ic_b;
  real_T c3_pc_y;
  real_T c3_hd_x;
  real_T c3_id_x;
  real_T c3_jc_b;
  real_T c3_qc_y;
  real_T c3_ob_a;
  real_T c3_kc_b;
  real_T c3_rc_y;
  real_T c3_jd_x;
  real_T c3_kd_x;
  real_T c3_pb_a;
  real_T c3_lc_b;
  real_T c3_sc_y;
  real_T c3_ld_x;
  real_T c3_md_x;
  real_T c3_mc_b;
  real_T c3_tc_y;
  real_T c3_qb_a;
  real_T c3_nc_b;
  real_T c3_uc_y;
  real_T c3_rb_a;
  real_T c3_oc_b;
  real_T c3_vc_y;
  real_T c3_nd_x;
  real_T c3_od_x;
  real_T c3_pd_x;
  real_T c3_qd_x;
  real_T c3_pc_b;
  real_T c3_wc_y;
  real_T c3_rd_x;
  real_T c3_sd_x;
  real_T c3_qc_b;
  real_T c3_xc_y;
  real_T c3_sb_a;
  real_T c3_rc_b;
  real_T c3_yc_y;
  real_T c3_h_A;
  real_T c3_td_x;
  real_T c3_ud_x;
  real_T c3_ad_y;
  real_T c3_tb_a;
  real_T c3_sc_b;
  real_T c3_bd_y;
  real_T c3_vd_x;
  real_T c3_wd_x;
  real_T c3_ub_a;
  real_T c3_tc_b;
  real_T c3_cd_y;
  real_T c3_vb_a;
  real_T c3_uc_b;
  real_T c3_dd_y;
  real_T c3_xd_x;
  real_T c3_yd_x;
  real_T c3_wb_a;
  real_T c3_vc_b;
  real_T c3_ed_y;
  real_T c3_i_A;
  real_T c3_ae_x;
  real_T c3_be_x;
  real_T c3_fd_y;
  real_T c3_xb_a;
  real_T c3_wc_b;
  real_T c3_gd_y;
  real_T c3_ce_x;
  real_T c3_de_x;
  real_T c3_yb_a;
  real_T c3_xc_b;
  real_T c3_hd_y;
  real_T c3_ac_a;
  real_T c3_yc_b;
  real_T c3_id_y;
  real_T c3_ee_x;
  real_T c3_fe_x;
  real_T c3_bc_a;
  real_T c3_ad_b;
  real_T c3_jd_y;
  real_T c3_j_A;
  real_T c3_ge_x;
  real_T c3_he_x;
  real_T c3_kd_y;
  real_T c3_ie_x;
  real_T c3_je_x;
  real_T c3_cc_a;
  real_T c3_bd_b;
  real_T c3_ld_y;
  real_T c3_dc_a;
  real_T c3_cd_b;
  real_T c3_md_y;
  real_T c3_ec_a;
  real_T c3_dd_b;
  real_T c3_nd_y;
  real_T c3_ke_x;
  real_T c3_le_x;
  real_T c3_fc_a;
  real_T c3_ed_b;
  real_T c3_od_y;
  real_T c3_k_A;
  real_T c3_me_x;
  real_T c3_ne_x;
  real_T c3_pd_y;
  real_T c3_oe_x;
  real_T c3_pe_x;
  real_T c3_gc_a;
  real_T c3_fd_b;
  real_T c3_qd_y;
  real_T c3_hc_a;
  real_T c3_gd_b;
  real_T c3_rd_y;
  real_T c3_qe_x;
  real_T c3_re_x;
  real_T c3_ic_a;
  real_T c3_hd_b;
  real_T c3_sd_y;
  real_T c3_jc_a;
  real_T c3_id_b;
  real_T c3_td_y;
  real_T c3_l_A;
  real_T c3_se_x;
  real_T c3_te_x;
  real_T c3_ud_y;
  real_T c3_ue_x;
  real_T c3_ve_x;
  real_T c3_kc_a;
  real_T c3_jd_b;
  real_T c3_vd_y;
  real_T c3_lc_a;
  real_T c3_kd_b;
  real_T c3_wd_y;
  real_T c3_m_A;
  real_T c3_we_x;
  real_T c3_xe_x;
  real_T c3_xd_y;
  real_T c3_ld_b;
  real_T c3_yd_y;
  real_T c3_ye_x;
  real_T c3_af_x;
  real_T c3_mc_a;
  real_T c3_md_b;
  real_T c3_ae_y;
  real_T c3_nc_a;
  real_T c3_nd_b;
  real_T c3_be_y;
  real_T c3_n_A;
  real_T c3_bf_x;
  real_T c3_cf_x;
  real_T c3_ce_y;
  real_T c3_oc_a;
  real_T c3_od_b;
  real_T c3_de_y;
  real_T c3_df_x;
  real_T c3_ef_x;
  real_T c3_pc_a;
  real_T c3_pd_b;
  real_T c3_ee_y;
  real_T c3_qc_a;
  real_T c3_qd_b;
  real_T c3_fe_y;
  real_T c3_o_A;
  real_T c3_ff_x;
  real_T c3_gf_x;
  real_T c3_ge_y;
  real_T c3_hf_x;
  real_T c3_if_x;
  real_T c3_rc_a;
  real_T c3_rd_b;
  real_T c3_he_y;
  real_T c3_sc_a;
  real_T c3_sd_b;
  real_T c3_ie_y;
  real_T c3_tc_a;
  real_T c3_td_b;
  real_T c3_je_y;
  real_T c3_p_A;
  real_T c3_jf_x;
  real_T c3_kf_x;
  real_T c3_ke_y;
  real_T c3_lf_x;
  real_T c3_mf_x;
  real_T c3_uc_a;
  real_T c3_ud_b;
  real_T c3_le_y;
  real_T c3_vc_a;
  real_T c3_vd_b;
  real_T c3_me_y;
  real_T c3_nf_x;
  real_T c3_of_x;
  real_T c3_wd_b;
  real_T c3_ne_y;
  real_T c3_pf_x;
  real_T c3_qf_x;
  real_T c3_wc_a;
  real_T c3_xd_b;
  real_T c3_oe_y;
  real_T c3_q_A;
  real_T c3_rf_x;
  real_T c3_sf_x;
  real_T c3_pe_y;
  real_T c3_tf_x;
  real_T c3_uf_x;
  real_T c3_xc_a;
  real_T c3_yd_b;
  real_T c3_qe_y;
  real_T c3_yc_a;
  real_T c3_ae_b;
  real_T c3_re_y;
  real_T c3_vf_x;
  real_T c3_wf_x;
  real_T c3_be_b;
  real_T c3_se_y;
  real_T c3_xf_x;
  real_T c3_yf_x;
  real_T c3_ad_a;
  real_T c3_ce_b;
  real_T c3_te_y;
  real_T c3_r_A;
  real_T c3_ag_x;
  real_T c3_bg_x;
  real_T c3_ue_y;
  real_T c3_bd_a;
  real_T c3_de_b;
  real_T c3_ve_y;
  real_T c3_cg_x;
  real_T c3_dg_x;
  real_T c3_eg_x;
  real_T c3_fg_x;
  real_T c3_ee_b;
  real_T c3_we_y;
  real_T c3_cd_a;
  real_T c3_fe_b;
  real_T c3_xe_y;
  real_T c3_gg_x;
  real_T c3_hg_x;
  real_T c3_ig_x;
  real_T c3_jg_x;
  real_T c3_ge_b;
  real_T c3_ye_y;
  real_T c3_kg_x;
  real_T c3_lg_x;
  real_T c3_he_b;
  real_T c3_af_y;
  real_T c3_dd_a;
  real_T c3_ie_b;
  real_T c3_bf_y;
  real_T c3_s_A;
  real_T c3_mg_x;
  real_T c3_ng_x;
  real_T c3_cf_y;
  real_T c3_ed_a;
  real_T c3_je_b;
  real_T c3_df_y;
  real_T c3_og_x;
  real_T c3_pg_x;
  real_T c3_qg_x;
  real_T c3_rg_x;
  real_T c3_ke_b;
  real_T c3_ef_y;
  real_T c3_fd_a;
  real_T c3_le_b;
  real_T c3_ff_y;
  real_T c3_sg_x;
  real_T c3_tg_x;
  real_T c3_ug_x;
  real_T c3_vg_x;
  real_T c3_me_b;
  real_T c3_gf_y;
  real_T c3_wg_x;
  real_T c3_xg_x;
  real_T c3_ne_b;
  real_T c3_hf_y;
  real_T c3_gd_a;
  real_T c3_oe_b;
  real_T c3_if_y;
  real_T c3_t_A;
  real_T c3_yg_x;
  real_T c3_ah_x;
  real_T c3_jf_y;
  real_T c3_hd_a;
  real_T c3_pe_b;
  real_T c3_kf_y;
  real_T c3_bh_x;
  real_T c3_ch_x;
  real_T c3_id_a;
  real_T c3_qe_b;
  real_T c3_lf_y;
  real_T c3_jd_a;
  real_T c3_re_b;
  real_T c3_mf_y;
  real_T c3_u_A;
  real_T c3_dh_x;
  real_T c3_eh_x;
  real_T c3_nf_y;
  real_T c3_kd_a;
  real_T c3_se_b;
  real_T c3_of_y;
  real_T c3_fh_x;
  real_T c3_gh_x;
  real_T c3_hh_x;
  real_T c3_ih_x;
  real_T c3_te_b;
  real_T c3_pf_y;
  real_T c3_ld_a;
  real_T c3_ue_b;
  real_T c3_qf_y;
  real_T c3_jh_x;
  real_T c3_kh_x;
  real_T c3_ve_b;
  real_T c3_rf_y;
  real_T c3_lh_x;
  real_T c3_mh_x;
  real_T c3_nh_x;
  real_T c3_oh_x;
  real_T c3_we_b;
  real_T c3_sf_y;
  real_T c3_md_a;
  real_T c3_xe_b;
  real_T c3_tf_y;
  real_T c3_v_A;
  real_T c3_ph_x;
  real_T c3_qh_x;
  real_T c3_uf_y;
  real_T c3_nd_a;
  real_T c3_ye_b;
  real_T c3_vf_y;
  real_T c3_rh_x;
  real_T c3_sh_x;
  real_T c3_th_x;
  real_T c3_uh_x;
  real_T c3_af_b;
  real_T c3_wf_y;
  real_T c3_od_a;
  real_T c3_bf_b;
  real_T c3_xf_y;
  real_T c3_vh_x;
  real_T c3_wh_x;
  real_T c3_cf_b;
  real_T c3_yf_y;
  real_T c3_xh_x;
  real_T c3_yh_x;
  real_T c3_ai_x;
  real_T c3_bi_x;
  real_T c3_df_b;
  real_T c3_ag_y;
  real_T c3_pd_a;
  real_T c3_ef_b;
  real_T c3_bg_y;
  real_T c3_w_A;
  real_T c3_ci_x;
  real_T c3_di_x;
  real_T c3_cg_y;
  real_T c3_ei_x;
  real_T c3_fi_x;
  real_T c3_qd_a;
  real_T c3_ff_b;
  real_T c3_dg_y;
  real_T c3_rd_a;
  real_T c3_gf_b;
  real_T c3_eg_y;
  real_T c3_gi_x;
  real_T c3_hi_x;
  real_T c3_ii_x;
  real_T c3_ji_x;
  real_T c3_hf_b;
  real_T c3_fg_y;
  real_T c3_sd_a;
  real_T c3_if_b;
  real_T c3_gg_y;
  real_T c3_x_A;
  real_T c3_ki_x;
  real_T c3_li_x;
  real_T c3_hg_y;
  real_T c3_jf_b;
  real_T c3_ig_y;
  real_T c3_mi_x;
  real_T c3_ni_x;
  real_T c3_td_a;
  real_T c3_kf_b;
  real_T c3_jg_y;
  real_T c3_ud_a;
  real_T c3_lf_b;
  real_T c3_kg_y;
  real_T c3_vd_a;
  real_T c3_mf_b;
  real_T c3_lg_y;
  real_T c3_y_A;
  real_T c3_oi_x;
  real_T c3_pi_x;
  real_T c3_mg_y;
  real_T c3_qi_x;
  real_T c3_ri_x;
  real_T c3_wd_a;
  real_T c3_nf_b;
  real_T c3_ng_y;
  real_T c3_xd_a;
  real_T c3_of_b;
  real_T c3_og_y;
  real_T c3_si_x;
  real_T c3_ti_x;
  real_T c3_ui_x;
  real_T c3_vi_x;
  real_T c3_pf_b;
  real_T c3_pg_y;
  real_T c3_yd_a;
  real_T c3_qf_b;
  real_T c3_qg_y;
  real_T c3_ab_A;
  real_T c3_wi_x;
  real_T c3_xi_x;
  real_T c3_rg_y;
  real_T c3_rf_b;
  real_T c3_sg_y;
  real_T c3_yi_x;
  real_T c3_aj_x;
  real_T c3_ae_a;
  real_T c3_sf_b;
  real_T c3_tg_y;
  real_T c3_be_a;
  real_T c3_tf_b;
  real_T c3_ug_y;
  real_T c3_ce_a;
  real_T c3_uf_b;
  real_T c3_vg_y;
  real_T c3_bb_A;
  real_T c3_bj_x;
  real_T c3_cj_x;
  real_T c3_wg_y;
  real_T c3_dj_x;
  real_T c3_ej_x;
  real_T c3_de_a;
  real_T c3_vf_b;
  real_T c3_xg_y;
  real_T c3_ee_a;
  real_T c3_wf_b;
  real_T c3_yg_y;
  real_T c3_fe_a;
  real_T c3_xf_b;
  real_T c3_ah_y;
  real_T c3_cb_A;
  real_T c3_fj_x;
  real_T c3_gj_x;
  real_T c3_bh_y;
  real_T c3_hj_x;
  real_T c3_ij_x;
  real_T c3_ge_a;
  real_T c3_yf_b;
  real_T c3_ch_y;
  real_T c3_he_a;
  real_T c3_ag_b;
  real_T c3_dh_y;
  real_T c3_db_A;
  real_T c3_jj_x;
  real_T c3_kj_x;
  real_T c3_eh_y;
  real_T c3_ie_a;
  real_T c3_bg_b;
  real_T c3_fh_y;
  real_T c3_lj_x;
  real_T c3_mj_x;
  real_T c3_cg_b;
  real_T c3_gh_y;
  real_T c3_nj_x;
  real_T c3_oj_x;
  real_T c3_dg_b;
  real_T c3_hh_y;
  real_T c3_je_a;
  real_T c3_eg_b;
  real_T c3_ih_y;
  real_T c3_eb_A;
  real_T c3_pj_x;
  real_T c3_qj_x;
  real_T c3_jh_y;
  real_T c3_ke_a;
  real_T c3_fg_b;
  real_T c3_kh_y;
  real_T c3_rj_x;
  real_T c3_sj_x;
  real_T c3_gg_b;
  real_T c3_lh_y;
  real_T c3_le_a;
  real_T c3_hg_b;
  real_T c3_mh_y;
  real_T c3_tj_x;
  real_T c3_uj_x;
  real_T c3_ig_b;
  real_T c3_nh_y;
  real_T c3_me_a;
  real_T c3_jg_b;
  real_T c3_oh_y;
  real_T c3_vj_x;
  real_T c3_wj_x;
  real_T c3_ne_a;
  real_T c3_kg_b;
  real_T c3_ph_y;
  real_T c3_oe_a;
  real_T c3_lg_b;
  real_T c3_qh_y;
  real_T c3_fb_A;
  real_T c3_xj_x;
  real_T c3_yj_x;
  real_T c3_rh_y;
  real_T c3_pe_a;
  real_T c3_mg_b;
  real_T c3_sh_y;
  real_T c3_ak_x;
  real_T c3_bk_x;
  real_T c3_qe_a;
  real_T c3_ng_b;
  real_T c3_th_y;
  real_T c3_gb_A;
  real_T c3_ck_x;
  real_T c3_dk_x;
  real_T c3_uh_y;
  real_T c3_re_a;
  real_T c3_og_b;
  real_T c3_vh_y;
  real_T c3_ek_x;
  real_T c3_fk_x;
  real_T c3_se_a;
  real_T c3_pg_b;
  real_T c3_wh_y;
  real_T c3_hb_A;
  real_T c3_gk_x;
  real_T c3_hk_x;
  real_T c3_xh_y;
  real_T c3_ik_x;
  real_T c3_jk_x;
  real_T c3_te_a;
  real_T c3_qg_b;
  real_T c3_yh_y;
  real_T c3_ue_a;
  real_T c3_rg_b;
  real_T c3_ai_y;
  real_T c3_kk_x;
  real_T c3_lk_x;
  real_T c3_mk_x;
  real_T c3_nk_x;
  real_T c3_sg_b;
  real_T c3_bi_y;
  real_T c3_ok_x;
  real_T c3_pk_x;
  real_T c3_tg_b;
  real_T c3_ci_y;
  real_T c3_ve_a;
  real_T c3_ug_b;
  real_T c3_di_y;
  real_T c3_ib_A;
  real_T c3_qk_x;
  real_T c3_rk_x;
  real_T c3_ei_y;
  real_T c3_sk_x;
  real_T c3_tk_x;
  real_T c3_we_a;
  real_T c3_vg_b;
  real_T c3_fi_y;
  real_T c3_xe_a;
  real_T c3_wg_b;
  real_T c3_gi_y;
  real_T c3_uk_x;
  real_T c3_vk_x;
  real_T c3_xg_b;
  real_T c3_hi_y;
  real_T c3_wk_x;
  real_T c3_xk_x;
  real_T c3_yk_x;
  real_T c3_al_x;
  real_T c3_yg_b;
  real_T c3_ii_y;
  real_T c3_ye_a;
  real_T c3_ah_b;
  real_T c3_ji_y;
  real_T c3_jb_A;
  real_T c3_bl_x;
  real_T c3_cl_x;
  real_T c3_ki_y;
  real_T c3_dl_x;
  real_T c3_el_x;
  real_T c3_af_a;
  real_T c3_bh_b;
  real_T c3_li_y;
  real_T c3_bf_a;
  real_T c3_ch_b;
  real_T c3_mi_y;
  real_T c3_fl_x;
  real_T c3_gl_x;
  real_T c3_dh_b;
  real_T c3_ni_y;
  real_T c3_hl_x;
  real_T c3_il_x;
  real_T c3_jl_x;
  real_T c3_kl_x;
  real_T c3_eh_b;
  real_T c3_oi_y;
  real_T c3_cf_a;
  real_T c3_fh_b;
  real_T c3_pi_y;
  real_T c3_kb_A;
  real_T c3_ll_x;
  real_T c3_ml_x;
  real_T c3_qi_y;
  real_T c3_nl_x;
  real_T c3_ol_x;
  real_T c3_df_a;
  real_T c3_gh_b;
  real_T c3_ri_y;
  real_T c3_ef_a;
  real_T c3_hh_b;
  real_T c3_si_y;
  real_T c3_pl_x;
  real_T c3_ql_x;
  real_T c3_rl_x;
  real_T c3_sl_x;
  real_T c3_ih_b;
  real_T c3_ti_y;
  real_T c3_tl_x;
  real_T c3_ul_x;
  real_T c3_jh_b;
  real_T c3_ui_y;
  real_T c3_ff_a;
  real_T c3_kh_b;
  real_T c3_vi_y;
  real_T c3_lb_A;
  real_T c3_vl_x;
  real_T c3_wl_x;
  real_T c3_wi_y;
  real_T c3_xl_x;
  real_T c3_yl_x;
  real_T c3_gf_a;
  real_T c3_lh_b;
  real_T c3_xi_y;
  real_T c3_hf_a;
  real_T c3_mh_b;
  real_T c3_yi_y;
  real_T c3_mb_A;
  real_T c3_am_x;
  real_T c3_bm_x;
  real_T c3_aj_y;
  real_T c3_nh_b;
  real_T c3_bj_y;
  real_T c3_cm_x;
  real_T c3_dm_x;
  real_T c3_if_a;
  real_T c3_oh_b;
  real_T c3_cj_y;
  real_T c3_jf_a;
  real_T c3_ph_b;
  real_T c3_dj_y;
  real_T c3_nb_A;
  real_T c3_em_x;
  real_T c3_fm_x;
  real_T c3_ej_y;
  real_T c3_kf_a;
  real_T c3_qh_b;
  real_T c3_fj_y;
  real_T c3_gm_x;
  real_T c3_hm_x;
  real_T c3_im_x;
  real_T c3_jm_x;
  real_T c3_rh_b;
  real_T c3_gj_y;
  real_T c3_lf_a;
  real_T c3_sh_b;
  real_T c3_hj_y;
  real_T c3_km_x;
  real_T c3_lm_x;
  real_T c3_mf_a;
  real_T c3_th_b;
  real_T c3_ij_y;
  real_T c3_mm_x;
  real_T c3_nm_x;
  real_T c3_uh_b;
  real_T c3_jj_y;
  real_T c3_nf_a;
  real_T c3_vh_b;
  real_T c3_kj_y;
  real_T c3_wh_b;
  real_T c3_lj_y;
  real_T c3_om_x;
  real_T c3_pm_x;
  real_T c3_of_a;
  real_T c3_xh_b;
  real_T c3_mj_y;
  real_T c3_pf_a;
  real_T c3_yh_b;
  real_T c3_nj_y;
  real_T c3_ob_A;
  real_T c3_qm_x;
  real_T c3_rm_x;
  real_T c3_oj_y;
  real_T c3_sm_x;
  real_T c3_tm_x;
  real_T c3_qf_a;
  real_T c3_ai_b;
  real_T c3_pj_y;
  real_T c3_rf_a;
  real_T c3_bi_b;
  real_T c3_qj_y;
  real_T c3_um_x;
  real_T c3_vm_x;
  real_T c3_ci_b;
  real_T c3_rj_y;
  real_T c3_wm_x;
  real_T c3_xm_x;
  real_T c3_sf_a;
  real_T c3_di_b;
  real_T c3_sj_y;
  real_T c3_pb_A;
  real_T c3_ym_x;
  real_T c3_an_x;
  real_T c3_tj_y;
  real_T c3_bn_x;
  real_T c3_cn_x;
  real_T c3_tf_a;
  real_T c3_ei_b;
  real_T c3_uj_y;
  real_T c3_uf_a;
  real_T c3_fi_b;
  real_T c3_vj_y;
  real_T c3_dn_x;
  real_T c3_en_x;
  real_T c3_gi_b;
  real_T c3_wj_y;
  real_T c3_fn_x;
  real_T c3_gn_x;
  real_T c3_vf_a;
  real_T c3_hi_b;
  real_T c3_xj_y;
  real_T c3_qb_A;
  real_T c3_hn_x;
  real_T c3_in_x;
  real_T c3_yj_y;
  real_T c3_wf_a;
  real_T c3_ii_b;
  real_T c3_ak_y;
  real_T c3_jn_x;
  real_T c3_kn_x;
  real_T c3_ln_x;
  real_T c3_mn_x;
  real_T c3_ji_b;
  real_T c3_bk_y;
  real_T c3_xf_a;
  real_T c3_ki_b;
  real_T c3_ck_y;
  real_T c3_nn_x;
  real_T c3_on_x;
  real_T c3_pn_x;
  real_T c3_qn_x;
  real_T c3_li_b;
  real_T c3_dk_y;
  real_T c3_rn_x;
  real_T c3_sn_x;
  real_T c3_mi_b;
  real_T c3_ek_y;
  real_T c3_yf_a;
  real_T c3_ni_b;
  real_T c3_fk_y;
  real_T c3_rb_A;
  real_T c3_tn_x;
  real_T c3_un_x;
  real_T c3_gk_y;
  real_T c3_ag_a;
  real_T c3_oi_b;
  real_T c3_hk_y;
  real_T c3_vn_x;
  real_T c3_wn_x;
  real_T c3_xn_x;
  real_T c3_yn_x;
  real_T c3_pi_b;
  real_T c3_ik_y;
  real_T c3_bg_a;
  real_T c3_qi_b;
  real_T c3_jk_y;
  real_T c3_ao_x;
  real_T c3_bo_x;
  real_T c3_co_x;
  real_T c3_do_x;
  real_T c3_ri_b;
  real_T c3_kk_y;
  real_T c3_eo_x;
  real_T c3_fo_x;
  real_T c3_si_b;
  real_T c3_lk_y;
  real_T c3_cg_a;
  real_T c3_ti_b;
  real_T c3_mk_y;
  real_T c3_sb_A;
  real_T c3_go_x;
  real_T c3_ho_x;
  real_T c3_nk_y;
  real_T c3_dg_a;
  real_T c3_ui_b;
  real_T c3_ok_y;
  real_T c3_io_x;
  real_T c3_jo_x;
  real_T c3_eg_a;
  real_T c3_vi_b;
  real_T c3_pk_y;
  real_T c3_ko_x;
  real_T c3_lo_x;
  real_T c3_wi_b;
  real_T c3_qk_y;
  real_T c3_fg_a;
  real_T c3_xi_b;
  real_T c3_rk_y;
  real_T c3_gg_a;
  real_T c3_yi_b;
  real_T c3_sk_y;
  real_T c3_mo_x;
  real_T c3_no_x;
  real_T c3_oo_x;
  real_T c3_po_x;
  real_T c3_aj_b;
  real_T c3_tk_y;
  real_T c3_qo_x;
  real_T c3_ro_x;
  real_T c3_bj_b;
  real_T c3_uk_y;
  real_T c3_hg_a;
  real_T c3_cj_b;
  real_T c3_vk_y;
  real_T c3_tb_A;
  real_T c3_so_x;
  real_T c3_to_x;
  real_T c3_wk_y;
  real_T c3_ig_a;
  real_T c3_dj_b;
  real_T c3_xk_y;
  real_T c3_uo_x;
  real_T c3_vo_x;
  real_T c3_jg_a;
  real_T c3_ej_b;
  real_T c3_yk_y;
  real_T c3_wo_x;
  real_T c3_xo_x;
  real_T c3_fj_b;
  real_T c3_al_y;
  real_T c3_kg_a;
  real_T c3_gj_b;
  real_T c3_bl_y;
  real_T c3_lg_a;
  real_T c3_hj_b;
  real_T c3_cl_y;
  real_T c3_yo_x;
  real_T c3_ap_x;
  real_T c3_bp_x;
  real_T c3_cp_x;
  real_T c3_ij_b;
  real_T c3_dl_y;
  real_T c3_dp_x;
  real_T c3_ep_x;
  real_T c3_jj_b;
  real_T c3_el_y;
  real_T c3_mg_a;
  real_T c3_kj_b;
  real_T c3_fl_y;
  real_T c3_ub_A;
  real_T c3_fp_x;
  real_T c3_gp_x;
  real_T c3_gl_y;
  real_T c3_ng_a;
  real_T c3_lj_b;
  real_T c3_hl_y;
  real_T c3_hp_x;
  real_T c3_ip_x;
  real_T c3_jp_x;
  real_T c3_kp_x;
  real_T c3_mj_b;
  real_T c3_il_y;
  real_T c3_og_a;
  real_T c3_nj_b;
  real_T c3_jl_y;
  real_T c3_lp_x;
  real_T c3_mp_x;
  real_T c3_oj_b;
  real_T c3_kl_y;
  real_T c3_np_x;
  real_T c3_op_x;
  real_T c3_pp_x;
  real_T c3_qp_x;
  real_T c3_pj_b;
  real_T c3_ll_y;
  real_T c3_pg_a;
  real_T c3_qj_b;
  real_T c3_ml_y;
  real_T c3_vb_A;
  real_T c3_rp_x;
  real_T c3_sp_x;
  real_T c3_nl_y;
  real_T c3_qg_a;
  real_T c3_rj_b;
  real_T c3_ol_y;
  real_T c3_tp_x;
  real_T c3_up_x;
  real_T c3_vp_x;
  real_T c3_wp_x;
  real_T c3_sj_b;
  real_T c3_pl_y;
  real_T c3_rg_a;
  real_T c3_tj_b;
  real_T c3_ql_y;
  real_T c3_xp_x;
  real_T c3_yp_x;
  real_T c3_uj_b;
  real_T c3_rl_y;
  real_T c3_aq_x;
  real_T c3_bq_x;
  real_T c3_cq_x;
  real_T c3_dq_x;
  real_T c3_vj_b;
  real_T c3_sl_y;
  real_T c3_sg_a;
  real_T c3_wj_b;
  real_T c3_tl_y;
  real_T c3_wb_A;
  real_T c3_eq_x;
  real_T c3_fq_x;
  real_T c3_ul_y;
  real_T c3_gq_x;
  real_T c3_hq_x;
  real_T c3_tg_a;
  real_T c3_xj_b;
  real_T c3_vl_y;
  real_T c3_ug_a;
  real_T c3_yj_b;
  real_T c3_wl_y;
  real_T c3_iq_x;
  real_T c3_jq_x;
  real_T c3_kq_x;
  real_T c3_lq_x;
  real_T c3_ak_b;
  real_T c3_xl_y;
  real_T c3_vg_a;
  real_T c3_bk_b;
  real_T c3_yl_y;
  real_T c3_xb_A;
  real_T c3_mq_x;
  real_T c3_nq_x;
  real_T c3_am_y;
  real_T c3_oq_x;
  real_T c3_pq_x;
  real_T c3_wg_a;
  real_T c3_ck_b;
  real_T c3_bm_y;
  real_T c3_xg_a;
  real_T c3_dk_b;
  real_T c3_cm_y;
  real_T c3_qq_x;
  real_T c3_rq_x;
  real_T c3_sq_x;
  real_T c3_tq_x;
  real_T c3_ek_b;
  real_T c3_dm_y;
  real_T c3_yg_a;
  real_T c3_fk_b;
  real_T c3_em_y;
  real_T c3_yb_A;
  real_T c3_uq_x;
  real_T c3_vq_x;
  real_T c3_fm_y;
  real_T c3_wq_x;
  real_T c3_xq_x;
  real_T c3_ah_a;
  real_T c3_gk_b;
  real_T c3_gm_y;
  real_T c3_bh_a;
  real_T c3_hk_b;
  real_T c3_hm_y;
  real_T c3_yq_x;
  real_T c3_ar_x;
  real_T c3_ch_a;
  real_T c3_ik_b;
  real_T c3_im_y;
  real_T c3_jk_b;
  real_T c3_jm_y;
  real_T c3_br_x;
  real_T c3_cr_x;
  real_T c3_dh_a;
  real_T c3_kk_b;
  real_T c3_km_y;
  real_T c3_eh_a;
  real_T c3_lk_b;
  real_T c3_lm_y;
  real_T c3_ac_A;
  real_T c3_dr_x;
  real_T c3_er_x;
  real_T c3_mm_y;
  real_T c3_fr_x;
  real_T c3_gr_x;
  real_T c3_fh_a;
  real_T c3_mk_b;
  real_T c3_nm_y;
  real_T c3_gh_a;
  real_T c3_nk_b;
  real_T c3_om_y;
  real_T c3_hr_x;
  real_T c3_ir_x;
  real_T c3_hh_a;
  real_T c3_ok_b;
  real_T c3_pm_y;
  real_T c3_pk_b;
  real_T c3_qm_y;
  real_T c3_jr_x;
  real_T c3_kr_x;
  real_T c3_ih_a;
  real_T c3_qk_b;
  real_T c3_rm_y;
  real_T c3_jh_a;
  real_T c3_rk_b;
  real_T c3_sm_y;
  real_T c3_bc_A;
  real_T c3_lr_x;
  real_T c3_mr_x;
  real_T c3_tm_y;
  real_T c3_kh_a;
  real_T c3_sk_b;
  real_T c3_um_y;
  real_T c3_nr_x;
  real_T c3_or_x;
  real_T c3_pr_x;
  real_T c3_qr_x;
  real_T c3_tk_b;
  real_T c3_vm_y;
  real_T c3_lh_a;
  real_T c3_uk_b;
  real_T c3_wm_y;
  real_T c3_rr_x;
  real_T c3_sr_x;
  real_T c3_mh_a;
  real_T c3_vk_b;
  real_T c3_xm_y;
  real_T c3_tr_x;
  real_T c3_ur_x;
  real_T c3_wk_b;
  real_T c3_ym_y;
  real_T c3_nh_a;
  real_T c3_xk_b;
  real_T c3_an_y;
  real_T c3_yk_b;
  real_T c3_bn_y;
  real_T c3_vr_x;
  real_T c3_wr_x;
  real_T c3_oh_a;
  real_T c3_al_b;
  real_T c3_cn_y;
  real_T c3_ph_a;
  real_T c3_bl_b;
  real_T c3_dn_y;
  real_T c3_cc_A;
  real_T c3_xr_x;
  real_T c3_yr_x;
  real_T c3_en_y;
  real_T c3_as_x;
  real_T c3_bs_x;
  real_T c3_qh_a;
  real_T c3_cl_b;
  real_T c3_fn_y;
  real_T c3_rh_a;
  real_T c3_dl_b;
  real_T c3_gn_y;
  real_T c3_sh_a;
  real_T c3_el_b;
  real_T c3_hn_y;
  real_T c3_cs_x;
  real_T c3_ds_x;
  real_T c3_es_x;
  real_T c3_fs_x;
  real_T c3_fl_b;
  real_T c3_in_y;
  real_T c3_th_a;
  real_T c3_gl_b;
  real_T c3_jn_y;
  real_T c3_dc_A;
  real_T c3_gs_x;
  real_T c3_hs_x;
  real_T c3_kn_y;
  real_T c3_is_x;
  real_T c3_js_x;
  real_T c3_uh_a;
  real_T c3_hl_b;
  real_T c3_ln_y;
  real_T c3_vh_a;
  real_T c3_il_b;
  real_T c3_mn_y;
  real_T c3_wh_a;
  real_T c3_jl_b;
  real_T c3_nn_y;
  real_T c3_ks_x;
  real_T c3_ls_x;
  real_T c3_ms_x;
  real_T c3_ns_x;
  real_T c3_kl_b;
  real_T c3_on_y;
  real_T c3_xh_a;
  real_T c3_ll_b;
  real_T c3_pn_y;
  real_T c3_ec_A;
  real_T c3_os_x;
  real_T c3_ps_x;
  real_T c3_qn_y;
  real_T c3_qs_x;
  real_T c3_rs_x;
  real_T c3_yh_a;
  real_T c3_ml_b;
  real_T c3_rn_y;
  real_T c3_ss_x;
  real_T c3_ts_x;
  real_T c3_ai_a;
  real_T c3_nl_b;
  real_T c3_sn_y;
  real_T c3_bi_a;
  real_T c3_ol_b;
  real_T c3_tn_y;
  real_T c3_fc_A;
  real_T c3_us_x;
  real_T c3_vs_x;
  real_T c3_un_y;
  real_T c3_ws_x;
  real_T c3_xs_x;
  real_T c3_ci_a;
  real_T c3_pl_b;
  real_T c3_vn_y;
  real_T c3_ys_x;
  real_T c3_at_x;
  real_T c3_di_a;
  real_T c3_ql_b;
  real_T c3_wn_y;
  real_T c3_ei_a;
  real_T c3_rl_b;
  real_T c3_xn_y;
  real_T c3_gc_A;
  real_T c3_bt_x;
  real_T c3_ct_x;
  real_T c3_yn_y;
  real_T c3_fi_a;
  real_T c3_sl_b;
  real_T c3_ao_y;
  real_T c3_dt_x;
  real_T c3_et_x;
  real_T c3_ft_x;
  real_T c3_gt_x;
  real_T c3_tl_b;
  real_T c3_bo_y;
  real_T c3_gi_a;
  real_T c3_ul_b;
  real_T c3_co_y;
  real_T c3_ht_x;
  real_T c3_it_x;
  real_T c3_jt_x;
  real_T c3_kt_x;
  real_T c3_vl_b;
  real_T c3_do_y;
  real_T c3_lt_x;
  real_T c3_mt_x;
  real_T c3_wl_b;
  real_T c3_eo_y;
  real_T c3_hi_a;
  real_T c3_xl_b;
  real_T c3_fo_y;
  real_T c3_hc_A;
  real_T c3_nt_x;
  real_T c3_ot_x;
  real_T c3_go_y;
  real_T c3_ii_a;
  real_T c3_yl_b;
  real_T c3_ho_y;
  real_T c3_pt_x;
  real_T c3_qt_x;
  real_T c3_rt_x;
  real_T c3_st_x;
  real_T c3_am_b;
  real_T c3_io_y;
  real_T c3_ji_a;
  real_T c3_bm_b;
  real_T c3_jo_y;
  real_T c3_tt_x;
  real_T c3_ut_x;
  real_T c3_vt_x;
  real_T c3_wt_x;
  real_T c3_cm_b;
  real_T c3_ko_y;
  real_T c3_xt_x;
  real_T c3_yt_x;
  real_T c3_dm_b;
  real_T c3_lo_y;
  real_T c3_ki_a;
  real_T c3_em_b;
  real_T c3_mo_y;
  real_T c3_ic_A;
  real_T c3_au_x;
  real_T c3_bu_x;
  real_T c3_no_y;
  real_T c3_li_a;
  real_T c3_fm_b;
  real_T c3_oo_y;
  real_T c3_cu_x;
  real_T c3_du_x;
  real_T c3_eu_x;
  real_T c3_fu_x;
  real_T c3_gm_b;
  real_T c3_po_y;
  real_T c3_mi_a;
  real_T c3_hm_b;
  real_T c3_qo_y;
  real_T c3_gu_x;
  real_T c3_hu_x;
  real_T c3_ni_a;
  real_T c3_im_b;
  real_T c3_ro_y;
  real_T c3_iu_x;
  real_T c3_ju_x;
  real_T c3_jm_b;
  real_T c3_so_y;
  real_T c3_oi_a;
  real_T c3_km_b;
  real_T c3_to_y;
  real_T c3_pi_a;
  real_T c3_lm_b;
  real_T c3_uo_y;
  real_T c3_jc_A;
  real_T c3_ku_x;
  real_T c3_lu_x;
  real_T c3_vo_y;
  real_T c3_qi_a;
  real_T c3_mm_b;
  real_T c3_wo_y;
  real_T c3_mu_x;
  real_T c3_nu_x;
  real_T c3_ou_x;
  real_T c3_pu_x;
  real_T c3_nm_b;
  real_T c3_xo_y;
  real_T c3_ri_a;
  real_T c3_om_b;
  real_T c3_yo_y;
  real_T c3_qu_x;
  real_T c3_ru_x;
  real_T c3_si_a;
  real_T c3_pm_b;
  real_T c3_ap_y;
  real_T c3_su_x;
  real_T c3_tu_x;
  real_T c3_qm_b;
  real_T c3_bp_y;
  real_T c3_ti_a;
  real_T c3_rm_b;
  real_T c3_cp_y;
  real_T c3_ui_a;
  real_T c3_sm_b;
  real_T c3_dp_y;
  real_T c3_kc_A;
  real_T c3_uu_x;
  real_T c3_vu_x;
  real_T c3_ep_y;
  real_T c3_vi_a;
  real_T c3_tm_b;
  real_T c3_fp_y;
  real_T c3_wu_x;
  real_T c3_xu_x;
  real_T c3_yu_x;
  real_T c3_av_x;
  real_T c3_um_b;
  real_T c3_gp_y;
  real_T c3_wi_a;
  real_T c3_vm_b;
  real_T c3_hp_y;
  real_T c3_bv_x;
  real_T c3_cv_x;
  real_T c3_xi_a;
  real_T c3_wm_b;
  real_T c3_ip_y;
  real_T c3_dv_x;
  real_T c3_ev_x;
  real_T c3_xm_b;
  real_T c3_jp_y;
  real_T c3_yi_a;
  real_T c3_ym_b;
  real_T c3_kp_y;
  real_T c3_aj_a;
  real_T c3_an_b;
  real_T c3_lp_y;
  real_T c3_lc_A;
  real_T c3_fv_x;
  real_T c3_gv_x;
  real_T c3_mp_y;
  real_T c3_bj_a;
  real_T c3_bn_b;
  real_T c3_np_y;
  real_T c3_hv_x;
  real_T c3_iv_x;
  real_T c3_jv_x;
  real_T c3_kv_x;
  real_T c3_cn_b;
  real_T c3_op_y;
  real_T c3_cj_a;
  real_T c3_dn_b;
  real_T c3_pp_y;
  real_T c3_lv_x;
  real_T c3_mv_x;
  real_T c3_dj_a;
  real_T c3_en_b;
  real_T c3_qp_y;
  real_T c3_nv_x;
  real_T c3_ov_x;
  real_T c3_fn_b;
  real_T c3_rp_y;
  real_T c3_ej_a;
  real_T c3_gn_b;
  real_T c3_sp_y;
  real_T c3_fj_a;
  real_T c3_hn_b;
  real_T c3_tp_y;
  real_T c3_mc_A;
  real_T c3_pv_x;
  real_T c3_qv_x;
  real_T c3_up_y;
  real_T c3_rv_x;
  real_T c3_sv_x;
  real_T c3_gj_a;
  real_T c3_in_b;
  real_T c3_vp_y;
  real_T c3_hj_a;
  real_T c3_jn_b;
  real_T c3_wp_y;
  real_T c3_tv_x;
  real_T c3_uv_x;
  real_T c3_vv_x;
  real_T c3_wv_x;
  real_T c3_kn_b;
  real_T c3_xp_y;
  real_T c3_ij_a;
  real_T c3_ln_b;
  real_T c3_yp_y;
  real_T c3_nc_A;
  real_T c3_xv_x;
  real_T c3_yv_x;
  real_T c3_aq_y;
  real_T c3_aw_x;
  real_T c3_bw_x;
  real_T c3_jj_a;
  real_T c3_mn_b;
  real_T c3_bq_y;
  real_T c3_kj_a;
  real_T c3_nn_b;
  real_T c3_cq_y;
  real_T c3_cw_x;
  real_T c3_dw_x;
  real_T c3_ew_x;
  real_T c3_fw_x;
  real_T c3_on_b;
  real_T c3_dq_y;
  real_T c3_lj_a;
  real_T c3_pn_b;
  real_T c3_eq_y;
  real_T c3_oc_A;
  real_T c3_gw_x;
  real_T c3_hw_x;
  real_T c3_fq_y;
  real_T c3_mj_a;
  real_T c3_qn_b;
  real_T c3_gq_y;
  real_T c3_iw_x;
  real_T c3_jw_x;
  real_T c3_kw_x;
  real_T c3_lw_x;
  real_T c3_rn_b;
  real_T c3_hq_y;
  real_T c3_nj_a;
  real_T c3_sn_b;
  real_T c3_iq_y;
  real_T c3_mw_x;
  real_T c3_nw_x;
  real_T c3_ow_x;
  real_T c3_pw_x;
  real_T c3_tn_b;
  real_T c3_jq_y;
  real_T c3_oj_a;
  real_T c3_un_b;
  real_T c3_kq_y;
  real_T c3_pc_A;
  real_T c3_qw_x;
  real_T c3_rw_x;
  real_T c3_lq_y;
  real_T c3_pj_a;
  real_T c3_vn_b;
  real_T c3_mq_y;
  real_T c3_sw_x;
  real_T c3_tw_x;
  real_T c3_uw_x;
  real_T c3_vw_x;
  real_T c3_wn_b;
  real_T c3_nq_y;
  real_T c3_qj_a;
  real_T c3_xn_b;
  real_T c3_oq_y;
  real_T c3_ww_x;
  real_T c3_xw_x;
  real_T c3_yw_x;
  real_T c3_ax_x;
  real_T c3_yn_b;
  real_T c3_pq_y;
  real_T c3_rj_a;
  real_T c3_ao_b;
  real_T c3_qq_y;
  real_T c3_qc_A;
  real_T c3_bx_x;
  real_T c3_cx_x;
  real_T c3_rq_y;
  real_T c3_dx_x;
  real_T c3_ex_x;
  real_T c3_sj_a;
  real_T c3_bo_b;
  real_T c3_sq_y;
  real_T c3_fx_x;
  real_T c3_gx_x;
  real_T c3_tj_a;
  real_T c3_co_b;
  real_T c3_tq_y;
  real_T c3_uj_a;
  real_T c3_do_b;
  real_T c3_uq_y;
  real_T c3_vj_a;
  real_T c3_eo_b;
  real_T c3_vq_y;
  real_T c3_rc_A;
  real_T c3_hx_x;
  real_T c3_ix_x;
  real_T c3_wq_y;
  real_T c3_jx_x;
  real_T c3_kx_x;
  real_T c3_wj_a;
  real_T c3_fo_b;
  real_T c3_xq_y;
  real_T c3_lx_x;
  real_T c3_mx_x;
  real_T c3_xj_a;
  real_T c3_go_b;
  real_T c3_yq_y;
  real_T c3_yj_a;
  real_T c3_ho_b;
  real_T c3_ar_y;
  real_T c3_ak_a;
  real_T c3_io_b;
  real_T c3_br_y;
  real_T c3_sc_A;
  real_T c3_nx_x;
  real_T c3_ox_x;
  real_T c3_cr_y;
  real_T c3_px_x;
  real_T c3_qx_x;
  real_T c3_bk_a;
  real_T c3_jo_b;
  real_T c3_dr_y;
  real_T c3_rx_x;
  real_T c3_sx_x;
  real_T c3_ck_a;
  real_T c3_ko_b;
  real_T c3_er_y;
  real_T c3_dk_a;
  real_T c3_lo_b;
  real_T c3_fr_y;
  real_T c3_ek_a;
  real_T c3_mo_b;
  real_T c3_gr_y;
  real_T c3_tc_A;
  real_T c3_tx_x;
  real_T c3_ux_x;
  real_T c3_hr_y;
  real_T c3_vx_x;
  real_T c3_wx_x;
  real_T c3_fk_a;
  real_T c3_no_b;
  real_T c3_ir_y;
  real_T c3_xx_x;
  real_T c3_yx_x;
  real_T c3_gk_a;
  real_T c3_oo_b;
  real_T c3_jr_y;
  real_T c3_hk_a;
  real_T c3_po_b;
  real_T c3_kr_y;
  real_T c3_ik_a;
  real_T c3_qo_b;
  real_T c3_lr_y;
  real_T c3_uc_A;
  real_T c3_ay_x;
  real_T c3_by_x;
  real_T c3_mr_y;
  real_T c3_jk_a;
  real_T c3_ro_b;
  real_T c3_nr_y;
  real_T c3_cy_x;
  real_T c3_dy_x;
  real_T c3_so_b;
  real_T c3_or_y;
  real_T c3_kk_a;
  real_T c3_to_b;
  real_T c3_pr_y;
  real_T c3_ey_x;
  real_T c3_fy_x;
  real_T c3_lk_a;
  real_T c3_uo_b;
  real_T c3_qr_y;
  real_T c3_mk_a;
  real_T c3_vo_b;
  real_T c3_rr_y;
  real_T c3_vc_A;
  real_T c3_gy_x;
  real_T c3_hy_x;
  real_T c3_sr_y;
  real_T c3_nk_a;
  real_T c3_wo_b;
  real_T c3_tr_y;
  real_T c3_iy_x;
  real_T c3_jy_x;
  real_T c3_ok_a;
  real_T c3_xo_b;
  real_T c3_ur_y;
  real_T c3_wc_A;
  real_T c3_ky_x;
  real_T c3_ly_x;
  real_T c3_vr_y;
  real_T c3_my_x;
  real_T c3_ny_x;
  real_T c3_pk_a;
  real_T c3_yo_b;
  real_T c3_wr_y;
  real_T c3_qk_a;
  real_T c3_ap_b;
  real_T c3_xr_y;
  real_T c3_oy_x;
  real_T c3_py_x;
  real_T c3_qy_x;
  real_T c3_ry_x;
  real_T c3_bp_b;
  real_T c3_yr_y;
  real_T c3_sy_x;
  real_T c3_ty_x;
  real_T c3_cp_b;
  real_T c3_as_y;
  real_T c3_rk_a;
  real_T c3_dp_b;
  real_T c3_bs_y;
  real_T c3_xc_A;
  real_T c3_uy_x;
  real_T c3_vy_x;
  real_T c3_cs_y;
  real_T c3_wy_x;
  real_T c3_xy_x;
  real_T c3_sk_a;
  real_T c3_ep_b;
  real_T c3_ds_y;
  real_T c3_tk_a;
  real_T c3_fp_b;
  real_T c3_es_y;
  real_T c3_yy_x;
  real_T c3_aab_x;
  real_T c3_bab_x;
  real_T c3_cab_x;
  real_T c3_gp_b;
  real_T c3_fs_y;
  real_T c3_uk_a;
  real_T c3_hp_b;
  real_T c3_gs_y;
  real_T c3_yc_A;
  real_T c3_dab_x;
  real_T c3_eab_x;
  real_T c3_hs_y;
  real_T c3_fab_x;
  real_T c3_gab_x;
  real_T c3_vk_a;
  real_T c3_ip_b;
  real_T c3_is_y;
  real_T c3_wk_a;
  real_T c3_jp_b;
  real_T c3_js_y;
  real_T c3_hab_x;
  real_T c3_iab_x;
  real_T c3_jab_x;
  real_T c3_kab_x;
  real_T c3_kp_b;
  real_T c3_ks_y;
  real_T c3_xk_a;
  real_T c3_lp_b;
  real_T c3_ls_y;
  real_T c3_ad_A;
  real_T c3_lab_x;
  real_T c3_mab_x;
  real_T c3_ms_y;
  real_T c3_nab_x;
  real_T c3_oab_x;
  real_T c3_yk_a;
  real_T c3_mp_b;
  real_T c3_ns_y;
  real_T c3_al_a;
  real_T c3_np_b;
  real_T c3_os_y;
  real_T c3_pab_x;
  real_T c3_qab_x;
  real_T c3_rab_x;
  real_T c3_sab_x;
  real_T c3_op_b;
  real_T c3_ps_y;
  real_T c3_tab_x;
  real_T c3_uab_x;
  real_T c3_pp_b;
  real_T c3_qs_y;
  real_T c3_bl_a;
  real_T c3_qp_b;
  real_T c3_rs_y;
  real_T c3_bd_A;
  real_T c3_vab_x;
  real_T c3_wab_x;
  real_T c3_ss_y;
  real_T c3_xab_x;
  real_T c3_yab_x;
  real_T c3_cl_a;
  real_T c3_rp_b;
  real_T c3_ts_y;
  real_T c3_dl_a;
  real_T c3_sp_b;
  real_T c3_us_y;
  real_T c3_cd_A;
  real_T c3_abb_x;
  real_T c3_bbb_x;
  real_T c3_vs_y;
  real_T c3_el_a;
  real_T c3_tp_b;
  real_T c3_ws_y;
  real_T c3_cbb_x;
  real_T c3_dbb_x;
  real_T c3_up_b;
  real_T c3_xs_y;
  real_T c3_ebb_x;
  real_T c3_fbb_x;
  real_T c3_vp_b;
  real_T c3_ys_y;
  real_T c3_fl_a;
  real_T c3_wp_b;
  real_T c3_at_y;
  real_T c3_dd_A;
  real_T c3_gbb_x;
  real_T c3_hbb_x;
  real_T c3_bt_y;
  real_T c3_gl_a;
  real_T c3_xp_b;
  real_T c3_ct_y;
  real_T c3_ibb_x;
  real_T c3_jbb_x;
  real_T c3_hl_a;
  real_T c3_yp_b;
  real_T c3_dt_y;
  real_T c3_ed_A;
  real_T c3_kbb_x;
  real_T c3_lbb_x;
  real_T c3_et_y;
  real_T c3_il_a;
  real_T c3_aq_b;
  real_T c3_ft_y;
  real_T c3_mbb_x;
  real_T c3_nbb_x;
  real_T c3_jl_a;
  real_T c3_bq_b;
  real_T c3_gt_y;
  real_T c3_fd_A;
  real_T c3_obb_x;
  real_T c3_pbb_x;
  real_T c3_ht_y;
  real_T c3_qbb_x;
  real_T c3_rbb_x;
  real_T c3_kl_a;
  real_T c3_cq_b;
  real_T c3_it_y;
  real_T c3_ll_a;
  real_T c3_dq_b;
  real_T c3_jt_y;
  real_T c3_sbb_x;
  real_T c3_tbb_x;
  real_T c3_ubb_x;
  real_T c3_vbb_x;
  real_T c3_eq_b;
  real_T c3_kt_y;
  real_T c3_wbb_x;
  real_T c3_xbb_x;
  real_T c3_fq_b;
  real_T c3_lt_y;
  real_T c3_ml_a;
  real_T c3_gq_b;
  real_T c3_mt_y;
  real_T c3_gd_A;
  real_T c3_ybb_x;
  real_T c3_acb_x;
  real_T c3_nt_y;
  real_T c3_bcb_x;
  real_T c3_ccb_x;
  real_T c3_nl_a;
  real_T c3_hq_b;
  real_T c3_ot_y;
  real_T c3_ol_a;
  real_T c3_iq_b;
  real_T c3_pt_y;
  real_T c3_dcb_x;
  real_T c3_ecb_x;
  real_T c3_jq_b;
  real_T c3_qt_y;
  real_T c3_fcb_x;
  real_T c3_gcb_x;
  real_T c3_hcb_x;
  real_T c3_icb_x;
  real_T c3_kq_b;
  real_T c3_rt_y;
  real_T c3_pl_a;
  real_T c3_lq_b;
  real_T c3_st_y;
  real_T c3_hd_A;
  real_T c3_jcb_x;
  real_T c3_kcb_x;
  real_T c3_tt_y;
  real_T c3_lcb_x;
  real_T c3_mcb_x;
  real_T c3_ql_a;
  real_T c3_mq_b;
  real_T c3_ut_y;
  real_T c3_rl_a;
  real_T c3_nq_b;
  real_T c3_vt_y;
  real_T c3_ncb_x;
  real_T c3_ocb_x;
  real_T c3_oq_b;
  real_T c3_wt_y;
  real_T c3_pcb_x;
  real_T c3_qcb_x;
  real_T c3_rcb_x;
  real_T c3_scb_x;
  real_T c3_pq_b;
  real_T c3_xt_y;
  real_T c3_sl_a;
  real_T c3_qq_b;
  real_T c3_yt_y;
  real_T c3_id_A;
  real_T c3_tcb_x;
  real_T c3_ucb_x;
  real_T c3_au_y;
  real_T c3_vcb_x;
  real_T c3_wcb_x;
  real_T c3_tl_a;
  real_T c3_rq_b;
  real_T c3_bu_y;
  real_T c3_ul_a;
  real_T c3_sq_b;
  real_T c3_cu_y;
  real_T c3_xcb_x;
  real_T c3_ycb_x;
  real_T c3_vl_a;
  real_T c3_tq_b;
  real_T c3_du_y;
  real_T c3_adb_x;
  real_T c3_bdb_x;
  real_T c3_uq_b;
  real_T c3_eu_y;
  real_T c3_wl_a;
  real_T c3_vq_b;
  real_T c3_fu_y;
  real_T c3_wq_b;
  real_T c3_gu_y;
  real_T c3_cdb_x;
  real_T c3_ddb_x;
  real_T c3_xl_a;
  real_T c3_xq_b;
  real_T c3_hu_y;
  real_T c3_yl_a;
  real_T c3_yq_b;
  real_T c3_iu_y;
  real_T c3_jd_A;
  real_T c3_edb_x;
  real_T c3_fdb_x;
  real_T c3_ju_y;
  real_T c3_gdb_x;
  real_T c3_hdb_x;
  real_T c3_am_a;
  real_T c3_ar_b;
  real_T c3_ku_y;
  real_T c3_bm_a;
  real_T c3_br_b;
  real_T c3_lu_y;
  real_T c3_idb_x;
  real_T c3_jdb_x;
  real_T c3_cm_a;
  real_T c3_cr_b;
  real_T c3_mu_y;
  real_T c3_kdb_x;
  real_T c3_ldb_x;
  real_T c3_dr_b;
  real_T c3_nu_y;
  real_T c3_dm_a;
  real_T c3_er_b;
  real_T c3_ou_y;
  real_T c3_fr_b;
  real_T c3_pu_y;
  real_T c3_mdb_x;
  real_T c3_ndb_x;
  real_T c3_em_a;
  real_T c3_gr_b;
  real_T c3_qu_y;
  real_T c3_fm_a;
  real_T c3_hr_b;
  real_T c3_ru_y;
  real_T c3_kd_A;
  real_T c3_odb_x;
  real_T c3_pdb_x;
  real_T c3_su_y;
  real_T c3_qdb_x;
  real_T c3_rdb_x;
  real_T c3_gm_a;
  real_T c3_ir_b;
  real_T c3_tu_y;
  real_T c3_hm_a;
  real_T c3_jr_b;
  real_T c3_uu_y;
  real_T c3_sdb_x;
  real_T c3_tdb_x;
  real_T c3_udb_x;
  real_T c3_vdb_x;
  real_T c3_kr_b;
  real_T c3_vu_y;
  real_T c3_wdb_x;
  real_T c3_xdb_x;
  real_T c3_lr_b;
  real_T c3_wu_y;
  real_T c3_im_a;
  real_T c3_mr_b;
  real_T c3_xu_y;
  real_T c3_ld_A;
  real_T c3_ydb_x;
  real_T c3_aeb_x;
  real_T c3_yu_y;
  real_T c3_beb_x;
  real_T c3_ceb_x;
  real_T c3_jm_a;
  real_T c3_nr_b;
  real_T c3_av_y;
  real_T c3_km_a;
  real_T c3_or_b;
  real_T c3_bv_y;
  real_T c3_deb_x;
  real_T c3_eeb_x;
  real_T c3_feb_x;
  real_T c3_geb_x;
  real_T c3_pr_b;
  real_T c3_cv_y;
  real_T c3_heb_x;
  real_T c3_ieb_x;
  real_T c3_qr_b;
  real_T c3_dv_y;
  real_T c3_lm_a;
  real_T c3_rr_b;
  real_T c3_ev_y;
  real_T c3_mm_a;
  real_T c3_sr_b;
  real_T c3_fv_y;
  real_T c3_md_A;
  real_T c3_jeb_x;
  real_T c3_keb_x;
  real_T c3_gv_y;
  real_T c3_leb_x;
  real_T c3_meb_x;
  real_T c3_nm_a;
  real_T c3_tr_b;
  real_T c3_hv_y;
  real_T c3_om_a;
  real_T c3_ur_b;
  real_T c3_iv_y;
  real_T c3_neb_x;
  real_T c3_oeb_x;
  real_T c3_peb_x;
  real_T c3_qeb_x;
  real_T c3_vr_b;
  real_T c3_jv_y;
  real_T c3_reb_x;
  real_T c3_seb_x;
  real_T c3_wr_b;
  real_T c3_kv_y;
  real_T c3_pm_a;
  real_T c3_xr_b;
  real_T c3_lv_y;
  real_T c3_qm_a;
  real_T c3_yr_b;
  real_T c3_mv_y;
  real_T c3_nd_A;
  real_T c3_teb_x;
  real_T c3_ueb_x;
  real_T c3_nv_y;
  real_T c3_rm_a;
  real_T c3_as_b;
  real_T c3_ov_y;
  real_T c3_veb_x;
  real_T c3_web_x;
  real_T c3_sm_a;
  real_T c3_bs_b;
  real_T c3_pv_y;
  real_T c3_od_A;
  real_T c3_xeb_x;
  real_T c3_yeb_x;
  real_T c3_qv_y;
  real_T c3_afb_x;
  real_T c3_bfb_x;
  real_T c3_tm_a;
  real_T c3_cs_b;
  real_T c3_rv_y;
  real_T c3_um_a;
  real_T c3_ds_b;
  real_T c3_sv_y;
  real_T c3_cfb_x;
  real_T c3_dfb_x;
  real_T c3_efb_x;
  real_T c3_ffb_x;
  real_T c3_es_b;
  real_T c3_tv_y;
  real_T c3_gfb_x;
  real_T c3_hfb_x;
  real_T c3_fs_b;
  real_T c3_uv_y;
  real_T c3_vm_a;
  real_T c3_gs_b;
  real_T c3_vv_y;
  real_T c3_pd_A;
  real_T c3_ifb_x;
  real_T c3_jfb_x;
  real_T c3_wv_y;
  real_T c3_kfb_x;
  real_T c3_lfb_x;
  real_T c3_wm_a;
  real_T c3_hs_b;
  real_T c3_xv_y;
  real_T c3_xm_a;
  real_T c3_is_b;
  real_T c3_yv_y;
  real_T c3_mfb_x;
  real_T c3_nfb_x;
  real_T c3_ym_a;
  real_T c3_js_b;
  real_T c3_aw_y;
  real_T c3_ofb_x;
  real_T c3_pfb_x;
  real_T c3_ks_b;
  real_T c3_bw_y;
  real_T c3_an_a;
  real_T c3_ls_b;
  real_T c3_cw_y;
  real_T c3_bn_a;
  real_T c3_ms_b;
  real_T c3_dw_y;
  real_T c3_qd_A;
  real_T c3_qfb_x;
  real_T c3_rfb_x;
  real_T c3_ew_y;
  real_T c3_sfb_x;
  real_T c3_tfb_x;
  real_T c3_cn_a;
  real_T c3_ns_b;
  real_T c3_fw_y;
  real_T c3_dn_a;
  real_T c3_os_b;
  real_T c3_gw_y;
  real_T c3_ufb_x;
  real_T c3_vfb_x;
  real_T c3_en_a;
  real_T c3_ps_b;
  real_T c3_hw_y;
  real_T c3_wfb_x;
  real_T c3_xfb_x;
  real_T c3_qs_b;
  real_T c3_iw_y;
  real_T c3_fn_a;
  real_T c3_rs_b;
  real_T c3_jw_y;
  real_T c3_gn_a;
  real_T c3_ss_b;
  real_T c3_kw_y;
  real_T c3_rd_A;
  real_T c3_yfb_x;
  real_T c3_agb_x;
  real_T c3_lw_y;
  real_T c3_bgb_x;
  real_T c3_cgb_x;
  real_T c3_hn_a;
  real_T c3_ts_b;
  real_T c3_mw_y;
  real_T c3_in_a;
  real_T c3_us_b;
  real_T c3_nw_y;
  real_T c3_dgb_x;
  real_T c3_egb_x;
  real_T c3_fgb_x;
  real_T c3_ggb_x;
  real_T c3_vs_b;
  real_T c3_ow_y;
  real_T c3_jn_a;
  real_T c3_ws_b;
  real_T c3_pw_y;
  real_T c3_sd_A;
  real_T c3_hgb_x;
  real_T c3_igb_x;
  real_T c3_qw_y;
  real_T c3_jgb_x;
  real_T c3_kgb_x;
  real_T c3_kn_a;
  real_T c3_xs_b;
  real_T c3_rw_y;
  real_T c3_ln_a;
  real_T c3_ys_b;
  real_T c3_sw_y;
  real_T c3_lgb_x;
  real_T c3_mgb_x;
  real_T c3_ngb_x;
  real_T c3_ogb_x;
  real_T c3_at_b;
  real_T c3_tw_y;
  real_T c3_mn_a;
  real_T c3_bt_b;
  real_T c3_uw_y;
  real_T c3_td_A;
  real_T c3_pgb_x;
  real_T c3_qgb_x;
  real_T c3_vw_y;
  real_T c3_rgb_x;
  real_T c3_sgb_x;
  real_T c3_nn_a;
  real_T c3_ct_b;
  real_T c3_ww_y;
  real_T c3_tgb_x;
  real_T c3_ugb_x;
  real_T c3_xw_y;
  real_T c3_on_a;
  real_T c3_dt_b;
  real_T c3_yw_y;
  real_T c3_vgb_x;
  real_T c3_wgb_x;
  real_T c3_xgb_x;
  real_T c3_ygb_x;
  real_T c3_et_b;
  real_T c3_ax_y;
  real_T c3_ahb_x;
  real_T c3_bhb_x;
  real_T c3_ft_b;
  real_T c3_bx_y;
  real_T c3_pn_a;
  real_T c3_gt_b;
  real_T c3_cx_y;
  real_T c3_ud_A;
  real_T c3_chb_x;
  real_T c3_dhb_x;
  real_T c3_dx_y;
  real_T c3_ehb_x;
  real_T c3_fhb_x;
  real_T c3_qn_a;
  real_T c3_ht_b;
  real_T c3_ex_y;
  real_T c3_ghb_x;
  real_T c3_hhb_x;
  real_T c3_fx_y;
  real_T c3_rn_a;
  real_T c3_it_b;
  real_T c3_gx_y;
  real_T c3_ihb_x;
  real_T c3_jhb_x;
  real_T c3_khb_x;
  real_T c3_lhb_x;
  real_T c3_jt_b;
  real_T c3_hx_y;
  real_T c3_sn_a;
  real_T c3_kt_b;
  real_T c3_ix_y;
  real_T c3_tn_a;
  real_T c3_lt_b;
  real_T c3_jx_y;
  real_T c3_vd_A;
  real_T c3_mhb_x;
  real_T c3_nhb_x;
  real_T c3_kx_y;
  real_T c3_ohb_x;
  real_T c3_phb_x;
  real_T c3_un_a;
  real_T c3_mt_b;
  real_T c3_lx_y;
  real_T c3_qhb_x;
  real_T c3_rhb_x;
  real_T c3_mx_y;
  real_T c3_vn_a;
  real_T c3_nt_b;
  real_T c3_nx_y;
  real_T c3_shb_x;
  real_T c3_thb_x;
  real_T c3_uhb_x;
  real_T c3_vhb_x;
  real_T c3_ot_b;
  real_T c3_ox_y;
  real_T c3_wn_a;
  real_T c3_pt_b;
  real_T c3_px_y;
  real_T c3_xn_a;
  real_T c3_qt_b;
  real_T c3_qx_y;
  real_T c3_wd_A;
  real_T c3_whb_x;
  real_T c3_xhb_x;
  real_T c3_rx_y;
  real_T c3_yhb_x;
  real_T c3_aib_x;
  real_T c3_yn_a;
  real_T c3_rt_b;
  real_T c3_sx_y;
  real_T c3_bib_x;
  real_T c3_cib_x;
  real_T c3_tx_y;
  real_T c3_ao_a;
  real_T c3_st_b;
  real_T c3_ux_y;
  real_T c3_bo_a;
  real_T c3_tt_b;
  real_T c3_vx_y;
  real_T c3_xd_A;
  real_T c3_dib_x;
  real_T c3_eib_x;
  real_T c3_wx_y;
  real_T c3_fib_x;
  real_T c3_gib_x;
  real_T c3_co_a;
  real_T c3_ut_b;
  real_T c3_xx_y;
  real_T c3_hib_x;
  real_T c3_iib_x;
  real_T c3_yx_y;
  real_T c3_do_a;
  real_T c3_vt_b;
  real_T c3_ay_y;
  real_T c3_jib_x;
  real_T c3_kib_x;
  real_T c3_lib_x;
  real_T c3_mib_x;
  real_T c3_wt_b;
  real_T c3_by_y;
  real_T c3_nib_x;
  real_T c3_oib_x;
  real_T c3_xt_b;
  real_T c3_cy_y;
  real_T c3_eo_a;
  real_T c3_yt_b;
  real_T c3_dy_y;
  real_T c3_yd_A;
  real_T c3_pib_x;
  real_T c3_qib_x;
  real_T c3_ey_y;
  real_T c3_rib_x;
  real_T c3_sib_x;
  real_T c3_fo_a;
  real_T c3_au_b;
  real_T c3_fy_y;
  real_T c3_tib_x;
  real_T c3_uib_x;
  real_T c3_go_a;
  real_T c3_bu_b;
  real_T c3_gy_y;
  real_T c3_vib_x;
  real_T c3_wib_x;
  real_T c3_hy_y;
  real_T c3_ho_a;
  real_T c3_cu_b;
  real_T c3_iy_y;
  real_T c3_ae_A;
  real_T c3_xib_x;
  real_T c3_yib_x;
  real_T c3_jy_y;
  real_T c3_ajb_x;
  real_T c3_bjb_x;
  real_T c3_io_a;
  real_T c3_du_b;
  real_T c3_ky_y;
  real_T c3_cjb_x;
  real_T c3_djb_x;
  real_T c3_jo_a;
  real_T c3_eu_b;
  real_T c3_ly_y;
  real_T c3_ejb_x;
  real_T c3_fjb_x;
  real_T c3_my_y;
  real_T c3_ko_a;
  real_T c3_fu_b;
  real_T c3_ny_y;
  real_T c3_be_A;
  real_T c3_gjb_x;
  real_T c3_hjb_x;
  real_T c3_oy_y;
  real_T c3_ijb_x;
  real_T c3_jjb_x;
  real_T c3_lo_a;
  real_T c3_gu_b;
  real_T c3_py_y;
  real_T c3_kjb_x;
  real_T c3_ljb_x;
  real_T c3_qy_y;
  real_T c3_mo_a;
  real_T c3_hu_b;
  real_T c3_ry_y;
  real_T c3_mjb_x;
  real_T c3_njb_x;
  real_T c3_ojb_x;
  real_T c3_pjb_x;
  real_T c3_iu_b;
  real_T c3_sy_y;
  real_T c3_no_a;
  real_T c3_ju_b;
  real_T c3_ty_y;
  real_T c3_ce_A;
  real_T c3_qjb_x;
  real_T c3_rjb_x;
  real_T c3_uy_y;
  real_T c3_sjb_x;
  real_T c3_tjb_x;
  real_T c3_oo_a;
  real_T c3_ku_b;
  real_T c3_vy_y;
  real_T c3_ujb_x;
  real_T c3_vjb_x;
  real_T c3_wy_y;
  real_T c3_po_a;
  real_T c3_lu_b;
  real_T c3_xy_y;
  real_T c3_wjb_x;
  real_T c3_xjb_x;
  real_T c3_yjb_x;
  real_T c3_akb_x;
  real_T c3_mu_b;
  real_T c3_yy_y;
  real_T c3_qo_a;
  real_T c3_nu_b;
  real_T c3_aab_y;
  real_T c3_de_A;
  real_T c3_bkb_x;
  real_T c3_ckb_x;
  real_T c3_bab_y;
  real_T c3_dkb_x;
  real_T c3_ekb_x;
  real_T c3_ro_a;
  real_T c3_ou_b;
  real_T c3_cab_y;
  real_T c3_fkb_x;
  real_T c3_gkb_x;
  real_T c3_dab_y;
  real_T c3_so_a;
  real_T c3_pu_b;
  real_T c3_eab_y;
  real_T c3_hkb_x;
  real_T c3_ikb_x;
  real_T c3_jkb_x;
  real_T c3_kkb_x;
  real_T c3_qu_b;
  real_T c3_fab_y;
  real_T c3_lkb_x;
  real_T c3_mkb_x;
  real_T c3_ru_b;
  real_T c3_gab_y;
  real_T c3_to_a;
  real_T c3_su_b;
  real_T c3_hab_y;
  real_T c3_ee_A;
  real_T c3_nkb_x;
  real_T c3_okb_x;
  real_T c3_iab_y;
  int32_T c3_i8;
  int32_T c3_i9;
  real_T (*c3_b_C)[9];
  real_T (*c3_b_q_dot)[3];
  real_T (*c3_b_qqd)[9];
  c3_b_q_dot = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_b_C = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = chartInstance->c3_m;
  c3_b_hoistedGlobal = chartInstance->c3_l;
  for (c3_i7 = 0; c3_i7 < 9; c3_i7++) {
    c3_qqd[c3_i7] = (*c3_b_qqd)[c3_i7];
  }

  c3_b_m = c3_hoistedGlobal;
  c3_b_l = c3_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_q, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 1U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 2U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_qqd, 3U, c3_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_m, 4U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_l, 5U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_C, 6U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_q_dot, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 2);
  c3_q[0] = c3_qqd[6];
  c3_q[1] = c3_qqd[7];
  c3_q[2] = c3_qqd[8];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 3);
  c3_q_dot[0] = c3_qqd[3];
  c3_q_dot[1] = c3_qqd[4];
  c3_q_dot[2] = c3_qqd[5];
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_a = c3_b_m;
  c3_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_y = c3_a * c3_b;
  c3_x = c3_q[0];
  c3_b_x = c3_x;
  c3_b_x = muDoubleScalarSin(c3_b_x);
  c3_b_b = c3_b_x;
  c3_b_y = 2.0 * c3_b_b;
  c3_c_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_d_x = c3_c_x;
  c3_d_x = muDoubleScalarSin(c3_d_x);
  c3_e_x = c3_q[0] + c3_q[1];
  c3_f_x = c3_e_x;
  c3_f_x = muDoubleScalarSin(c3_f_x);
  c3_c_b = c3_f_x;
  c3_c_y = 2.0 * c3_c_b;
  c3_b_a = c3_y;
  c3_d_b = (c3_b_y + c3_d_x) + c3_c_y;
  c3_d_y = c3_b_a * c3_d_b;
  c3_g_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_h_x = c3_g_x;
  c3_h_x = muDoubleScalarCos(c3_h_x);
  c3_c_a = c3_h_x;
  c3_e_b = (c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2];
  c3_e_y = c3_c_a * c3_e_b;
  c3_i_x = c3_q[0] + c3_q[1];
  c3_j_x = c3_i_x;
  c3_j_x = muDoubleScalarCos(c3_j_x);
  c3_f_b = c3_j_x;
  c3_f_y = 2.0 * c3_f_b;
  c3_d_a = c3_f_y;
  c3_g_b = c3_q_dot[0] + c3_q_dot[1];
  c3_g_y = c3_d_a * c3_g_b;
  c3_h_b = c3_q_dot[0];
  c3_h_y = 2.0 * c3_h_b;
  c3_k_x = c3_q[0];
  c3_l_x = c3_k_x;
  c3_l_x = muDoubleScalarCos(c3_l_x);
  c3_e_a = c3_h_y;
  c3_i_b = c3_l_x;
  c3_i_y = c3_e_a * c3_i_b;
  c3_f_a = c3_d_y;
  c3_j_b = (c3_e_y + c3_g_y) + c3_i_y;
  c3_j_y = c3_f_a * c3_j_b;
  c3_A = c3_j_y;
  c3_m_x = c3_A;
  c3_n_x = c3_m_x;
  c3_k_y = c3_n_x / 8.0;
  c3_g_a = c3_b_m;
  c3_k_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_l_y = c3_g_a * c3_k_b;
  c3_o_x = c3_q[0];
  c3_p_x = c3_o_x;
  c3_p_x = muDoubleScalarCos(c3_p_x);
  c3_l_b = c3_p_x;
  c3_m_y = 2.0 * c3_l_b;
  c3_q_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_r_x = c3_q_x;
  c3_r_x = muDoubleScalarCos(c3_r_x);
  c3_s_x = c3_q[0] + c3_q[1];
  c3_t_x = c3_s_x;
  c3_t_x = muDoubleScalarCos(c3_t_x);
  c3_m_b = c3_t_x;
  c3_n_y = 2.0 * c3_m_b;
  c3_h_a = c3_l_y;
  c3_n_b = (c3_m_y + c3_r_x) + c3_n_y;
  c3_o_y = c3_h_a * c3_n_b;
  c3_u_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_v_x = c3_u_x;
  c3_v_x = muDoubleScalarSin(c3_v_x);
  c3_i_a = c3_v_x;
  c3_o_b = (c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2];
  c3_p_y = c3_i_a * c3_o_b;
  c3_w_x = c3_q[0] + c3_q[1];
  c3_x_x = c3_w_x;
  c3_x_x = muDoubleScalarSin(c3_x_x);
  c3_p_b = c3_x_x;
  c3_q_y = 2.0 * c3_p_b;
  c3_j_a = c3_q_y;
  c3_q_b = c3_q_dot[0] + c3_q_dot[1];
  c3_r_y = c3_j_a * c3_q_b;
  c3_r_b = c3_q_dot[0];
  c3_s_y = 2.0 * c3_r_b;
  c3_y_x = c3_q[0];
  c3_ab_x = c3_y_x;
  c3_ab_x = muDoubleScalarSin(c3_ab_x);
  c3_k_a = c3_s_y;
  c3_s_b = c3_ab_x;
  c3_t_y = c3_k_a * c3_s_b;
  c3_l_a = c3_o_y;
  c3_t_b = (c3_p_y + c3_r_y) + c3_t_y;
  c3_u_y = c3_l_a * c3_t_b;
  c3_b_A = c3_u_y;
  c3_bb_x = c3_b_A;
  c3_cb_x = c3_bb_x;
  c3_v_y = c3_cb_x / 8.0;
  c3_m_a = c3_b_m;
  c3_u_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_w_y = c3_m_a * c3_u_b;
  c3_db_x = c3_q[0] + c3_q[1];
  c3_eb_x = c3_db_x;
  c3_eb_x = muDoubleScalarCos(c3_eb_x);
  c3_n_a = c3_eb_x;
  c3_v_b = c3_q_dot[0] + c3_q_dot[1];
  c3_x_y = c3_n_a * c3_v_b;
  c3_w_b = c3_q_dot[0];
  c3_y_y = 2.0 * c3_w_b;
  c3_fb_x = c3_q[0];
  c3_gb_x = c3_fb_x;
  c3_gb_x = muDoubleScalarCos(c3_gb_x);
  c3_o_a = c3_y_y;
  c3_x_b = c3_gb_x;
  c3_ab_y = c3_o_a * c3_x_b;
  c3_p_a = c3_w_y;
  c3_y_b = c3_x_y + c3_ab_y;
  c3_bb_y = c3_p_a * c3_y_b;
  c3_hb_x = c3_q[0];
  c3_ib_x = c3_hb_x;
  c3_ib_x = muDoubleScalarSin(c3_ib_x);
  c3_ab_b = c3_ib_x;
  c3_cb_y = 2.0 * c3_ab_b;
  c3_jb_x = c3_q[0] + c3_q[1];
  c3_kb_x = c3_jb_x;
  c3_kb_x = muDoubleScalarSin(c3_kb_x);
  c3_q_a = c3_bb_y;
  c3_bb_b = c3_cb_y + c3_kb_x;
  c3_db_y = c3_q_a * c3_bb_b;
  c3_c_A = c3_db_y;
  c3_lb_x = c3_c_A;
  c3_mb_x = c3_lb_x;
  c3_eb_y = c3_mb_x / 8.0;
  c3_r_a = c3_b_m;
  c3_cb_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_fb_y = c3_r_a * c3_cb_b;
  c3_nb_x = c3_q[0];
  c3_ob_x = c3_nb_x;
  c3_ob_x = muDoubleScalarCos(c3_ob_x);
  c3_db_b = c3_ob_x;
  c3_gb_y = 2.0 * c3_db_b;
  c3_pb_x = c3_q[0] + c3_q[1];
  c3_qb_x = c3_pb_x;
  c3_qb_x = muDoubleScalarCos(c3_qb_x);
  c3_s_a = c3_fb_y;
  c3_eb_b = c3_gb_y + c3_qb_x;
  c3_hb_y = c3_s_a * c3_eb_b;
  c3_rb_x = c3_q[0] + c3_q[1];
  c3_sb_x = c3_rb_x;
  c3_sb_x = muDoubleScalarSin(c3_sb_x);
  c3_t_a = c3_sb_x;
  c3_fb_b = c3_q_dot[0] + c3_q_dot[1];
  c3_ib_y = c3_t_a * c3_fb_b;
  c3_gb_b = c3_q_dot[0];
  c3_jb_y = 2.0 * c3_gb_b;
  c3_tb_x = c3_q[0];
  c3_ub_x = c3_tb_x;
  c3_ub_x = muDoubleScalarSin(c3_ub_x);
  c3_u_a = c3_jb_y;
  c3_hb_b = c3_ub_x;
  c3_kb_y = c3_u_a * c3_hb_b;
  c3_v_a = c3_hb_y;
  c3_ib_b = c3_ib_y + c3_kb_y;
  c3_lb_y = c3_v_a * c3_ib_b;
  c3_d_A = c3_lb_y;
  c3_vb_x = c3_d_A;
  c3_wb_x = c3_vb_x;
  c3_mb_y = c3_wb_x / 8.0;
  c3_w_a = c3_b_m;
  c3_jb_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_nb_y = c3_w_a * c3_jb_b;
  c3_xb_x = c3_q[0] + c3_q[1];
  c3_yb_x = c3_xb_x;
  c3_yb_x = muDoubleScalarCos(c3_yb_x);
  c3_ac_x = c3_q[0];
  c3_bc_x = c3_ac_x;
  c3_bc_x = muDoubleScalarCos(c3_bc_x);
  c3_kb_b = c3_bc_x;
  c3_ob_y = 2.0 * c3_kb_b;
  c3_x_a = c3_nb_y;
  c3_lb_b = c3_yb_x + c3_ob_y;
  c3_pb_y = c3_x_a * c3_lb_b;
  c3_cc_x = c3_q[0];
  c3_dc_x = c3_cc_x;
  c3_dc_x = muDoubleScalarSin(c3_dc_x);
  c3_mb_b = c3_dc_x;
  c3_qb_y = 2.0 * c3_mb_b;
  c3_y_a = c3_qb_y;
  c3_nb_b = c3_q_dot[0];
  c3_rb_y = c3_y_a * c3_nb_b;
  c3_ec_x = c3_q[0] + c3_q[1];
  c3_fc_x = c3_ec_x;
  c3_fc_x = muDoubleScalarSin(c3_fc_x);
  c3_ab_a = c3_fc_x;
  c3_ob_b = c3_q_dot[0] + c3_q_dot[1];
  c3_sb_y = c3_ab_a * c3_ob_b;
  c3_bb_a = c3_pb_y;
  c3_pb_b = c3_rb_y + c3_sb_y;
  c3_tb_y = c3_bb_a * c3_pb_b;
  c3_e_A = c3_tb_y;
  c3_gc_x = c3_e_A;
  c3_hc_x = c3_gc_x;
  c3_ub_y = c3_hc_x / 8.0;
  c3_cb_a = c3_b_m;
  c3_qb_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_vb_y = c3_cb_a * c3_qb_b;
  c3_ic_x = c3_q[0] + c3_q[1];
  c3_jc_x = c3_ic_x;
  c3_jc_x = muDoubleScalarSin(c3_jc_x);
  c3_kc_x = c3_q[0];
  c3_lc_x = c3_kc_x;
  c3_lc_x = muDoubleScalarSin(c3_lc_x);
  c3_rb_b = c3_lc_x;
  c3_wb_y = 2.0 * c3_rb_b;
  c3_db_a = c3_vb_y;
  c3_sb_b = c3_jc_x + c3_wb_y;
  c3_xb_y = c3_db_a * c3_sb_b;
  c3_mc_x = c3_q[0];
  c3_nc_x = c3_mc_x;
  c3_nc_x = muDoubleScalarCos(c3_nc_x);
  c3_tb_b = c3_nc_x;
  c3_yb_y = 2.0 * c3_tb_b;
  c3_eb_a = c3_yb_y;
  c3_ub_b = c3_q_dot[0];
  c3_ac_y = c3_eb_a * c3_ub_b;
  c3_oc_x = c3_q[0] + c3_q[1];
  c3_pc_x = c3_oc_x;
  c3_pc_x = muDoubleScalarCos(c3_pc_x);
  c3_fb_a = c3_pc_x;
  c3_vb_b = c3_q_dot[0] + c3_q_dot[1];
  c3_bc_y = c3_fb_a * c3_vb_b;
  c3_gb_a = c3_xb_y;
  c3_wb_b = c3_ac_y + c3_bc_y;
  c3_cc_y = c3_gb_a * c3_wb_b;
  c3_f_A = c3_cc_y;
  c3_qc_x = c3_f_A;
  c3_rc_x = c3_qc_x;
  c3_dc_y = c3_rc_x / 8.0;
  c3_hb_a = c3_b_m;
  c3_xb_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_ec_y = c3_hb_a * c3_xb_b;
  c3_sc_x = c3_q[0];
  c3_tc_x = c3_sc_x;
  c3_tc_x = muDoubleScalarCos(c3_tc_x);
  c3_yb_b = c3_tc_x;
  c3_fc_y = 2.0 * c3_yb_b;
  c3_ib_a = c3_fc_y;
  c3_ac_b = c3_q_dot[0];
  c3_gc_y = c3_ib_a * c3_ac_b;
  c3_uc_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_vc_x = c3_uc_x;
  c3_vc_x = muDoubleScalarCos(c3_vc_x);
  c3_jb_a = c3_vc_x;
  c3_bc_b = (c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2];
  c3_hc_y = c3_jb_a * c3_bc_b;
  c3_wc_x = c3_q[0] + c3_q[1];
  c3_xc_x = c3_wc_x;
  c3_xc_x = muDoubleScalarCos(c3_xc_x);
  c3_cc_b = c3_xc_x;
  c3_ic_y = 2.0 * c3_cc_b;
  c3_kb_a = c3_ic_y;
  c3_dc_b = c3_q_dot[0] + c3_q_dot[1];
  c3_jc_y = c3_kb_a * c3_dc_b;
  c3_lb_a = c3_ec_y;
  c3_ec_b = (c3_gc_y + c3_hc_y) + c3_jc_y;
  c3_kc_y = c3_lb_a * c3_ec_b;
  c3_yc_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_ad_x = c3_yc_x;
  c3_ad_x = muDoubleScalarSin(c3_ad_x);
  c3_bd_x = c3_q[0] + c3_q[1];
  c3_cd_x = c3_bd_x;
  c3_cd_x = muDoubleScalarSin(c3_cd_x);
  c3_fc_b = c3_cd_x;
  c3_lc_y = 2.0 * c3_fc_b;
  c3_dd_x = c3_q[0];
  c3_ed_x = c3_dd_x;
  c3_ed_x = muDoubleScalarSin(c3_ed_x);
  c3_gc_b = c3_ed_x;
  c3_mc_y = 2.0 * c3_gc_b;
  c3_mb_a = c3_kc_y;
  c3_hc_b = (c3_ad_x + c3_lc_y) + c3_mc_y;
  c3_nc_y = c3_mb_a * c3_hc_b;
  c3_g_A = c3_nc_y;
  c3_fd_x = c3_g_A;
  c3_gd_x = c3_fd_x;
  c3_oc_y = c3_gd_x / 8.0;
  c3_nb_a = c3_b_m;
  c3_ic_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_pc_y = c3_nb_a * c3_ic_b;
  c3_hd_x = c3_q[0];
  c3_id_x = c3_hd_x;
  c3_id_x = muDoubleScalarSin(c3_id_x);
  c3_jc_b = c3_id_x;
  c3_qc_y = 2.0 * c3_jc_b;
  c3_ob_a = c3_qc_y;
  c3_kc_b = c3_q_dot[0];
  c3_rc_y = c3_ob_a * c3_kc_b;
  c3_jd_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_kd_x = c3_jd_x;
  c3_kd_x = muDoubleScalarSin(c3_kd_x);
  c3_pb_a = c3_kd_x;
  c3_lc_b = (c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2];
  c3_sc_y = c3_pb_a * c3_lc_b;
  c3_ld_x = c3_q[0] + c3_q[1];
  c3_md_x = c3_ld_x;
  c3_md_x = muDoubleScalarSin(c3_md_x);
  c3_mc_b = c3_md_x;
  c3_tc_y = 2.0 * c3_mc_b;
  c3_qb_a = c3_tc_y;
  c3_nc_b = c3_q_dot[0] + c3_q_dot[1];
  c3_uc_y = c3_qb_a * c3_nc_b;
  c3_rb_a = c3_pc_y;
  c3_oc_b = (c3_rc_y + c3_sc_y) + c3_uc_y;
  c3_vc_y = c3_rb_a * c3_oc_b;
  c3_nd_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_od_x = c3_nd_x;
  c3_od_x = muDoubleScalarCos(c3_od_x);
  c3_pd_x = c3_q[0] + c3_q[1];
  c3_qd_x = c3_pd_x;
  c3_qd_x = muDoubleScalarCos(c3_qd_x);
  c3_pc_b = c3_qd_x;
  c3_wc_y = 2.0 * c3_pc_b;
  c3_rd_x = c3_q[0];
  c3_sd_x = c3_rd_x;
  c3_sd_x = muDoubleScalarCos(c3_sd_x);
  c3_qc_b = c3_sd_x;
  c3_xc_y = 2.0 * c3_qc_b;
  c3_sb_a = c3_vc_y;
  c3_rc_b = (c3_od_x + c3_wc_y) + c3_xc_y;
  c3_yc_y = c3_sb_a * c3_rc_b;
  c3_h_A = c3_yc_y;
  c3_td_x = c3_h_A;
  c3_ud_x = c3_td_x;
  c3_ad_y = c3_ud_x / 8.0;
  c3_tb_a = c3_b_m;
  c3_sc_b = c3_q_dot[0];
  c3_bd_y = c3_tb_a * c3_sc_b;
  c3_vd_x = c3_q[0];
  c3_wd_x = c3_vd_x;
  c3_wd_x = muDoubleScalarCos(c3_wd_x);
  c3_ub_a = c3_bd_y;
  c3_tc_b = c3_wd_x;
  c3_cd_y = c3_ub_a * c3_tc_b;
  c3_vb_a = c3_cd_y;
  c3_uc_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_dd_y = c3_vb_a * c3_uc_b;
  c3_xd_x = c3_q[0];
  c3_yd_x = c3_xd_x;
  c3_yd_x = muDoubleScalarSin(c3_yd_x);
  c3_wb_a = c3_dd_y;
  c3_vc_b = c3_yd_x;
  c3_ed_y = c3_wb_a * c3_vc_b;
  c3_i_A = c3_ed_y;
  c3_ae_x = c3_i_A;
  c3_be_x = c3_ae_x;
  c3_fd_y = c3_be_x / 8.0;
  c3_xb_a = c3_b_m;
  c3_wc_b = c3_q_dot[0];
  c3_gd_y = c3_xb_a * c3_wc_b;
  c3_ce_x = c3_q[0];
  c3_de_x = c3_ce_x;
  c3_de_x = muDoubleScalarSin(c3_de_x);
  c3_yb_a = c3_gd_y;
  c3_xc_b = c3_de_x;
  c3_hd_y = c3_yb_a * c3_xc_b;
  c3_ac_a = c3_hd_y;
  c3_yc_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_id_y = c3_ac_a * c3_yc_b;
  c3_ee_x = c3_q[0];
  c3_fe_x = c3_ee_x;
  c3_fe_x = muDoubleScalarCos(c3_fe_x);
  c3_bc_a = c3_id_y;
  c3_ad_b = c3_fe_x;
  c3_jd_y = c3_bc_a * c3_ad_b;
  c3_j_A = c3_jd_y;
  c3_ge_x = c3_j_A;
  c3_he_x = c3_ge_x;
  c3_kd_y = c3_he_x / 8.0;
  c3_ie_x = c3_q[0];
  c3_je_x = c3_ie_x;
  c3_je_x = muDoubleScalarCos(c3_je_x);
  c3_cc_a = c3_b_m;
  c3_bd_b = c3_je_x;
  c3_ld_y = c3_cc_a * c3_bd_b;
  c3_dc_a = c3_ld_y;
  c3_cd_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_md_y = c3_dc_a * c3_cd_b;
  c3_ec_a = c3_md_y;
  c3_dd_b = c3_q_dot[0];
  c3_nd_y = c3_ec_a * c3_dd_b;
  c3_ke_x = c3_q[0];
  c3_le_x = c3_ke_x;
  c3_le_x = muDoubleScalarSin(c3_le_x);
  c3_fc_a = c3_nd_y;
  c3_ed_b = c3_le_x;
  c3_od_y = c3_fc_a * c3_ed_b;
  c3_k_A = c3_od_y;
  c3_me_x = c3_k_A;
  c3_ne_x = c3_me_x;
  c3_pd_y = c3_ne_x / 8.0;
  c3_oe_x = c3_q[0];
  c3_pe_x = c3_oe_x;
  c3_pe_x = muDoubleScalarSin(c3_pe_x);
  c3_gc_a = c3_b_m;
  c3_fd_b = c3_pe_x;
  c3_qd_y = c3_gc_a * c3_fd_b;
  c3_hc_a = c3_qd_y;
  c3_gd_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_rd_y = c3_hc_a * c3_gd_b;
  c3_qe_x = c3_q[0];
  c3_re_x = c3_qe_x;
  c3_re_x = muDoubleScalarCos(c3_re_x);
  c3_ic_a = c3_rd_y;
  c3_hd_b = c3_re_x;
  c3_sd_y = c3_ic_a * c3_hd_b;
  c3_jc_a = c3_sd_y;
  c3_id_b = c3_q_dot[0];
  c3_td_y = c3_jc_a * c3_id_b;
  c3_l_A = c3_td_y;
  c3_se_x = c3_l_A;
  c3_te_x = c3_se_x;
  c3_ud_y = c3_te_x / 8.0;
  c3_ue_x = ((c3_q[0] - c3_q[1]) - c3_q[2]) - c3_q[0];
  c3_ve_x = c3_ue_x;
  c3_ve_x = muDoubleScalarSin(c3_ve_x);
  c3_kc_a = c3_b_m;
  c3_jd_b = c3_ve_x;
  c3_vd_y = c3_kc_a * c3_jd_b;
  c3_lc_a = c3_vd_y;
  c3_kd_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_wd_y = c3_lc_a * c3_kd_b;
  c3_m_A = c3_wd_y;
  c3_we_x = c3_m_A;
  c3_xe_x = c3_we_x;
  c3_xd_y = c3_xe_x / 2.0;
  c3_ld_b = c3_b_m;
  c3_yd_y = 3.0 * c3_ld_b;
  c3_ye_x = (c3_q[0] - c3_q[1]) - c3_q[0];
  c3_af_x = c3_ye_x;
  c3_af_x = muDoubleScalarSin(c3_af_x);
  c3_mc_a = c3_yd_y;
  c3_md_b = c3_af_x;
  c3_ae_y = c3_mc_a * c3_md_b;
  c3_nc_a = c3_ae_y;
  c3_nd_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_be_y = c3_nc_a * c3_nd_b;
  c3_n_A = c3_be_y;
  c3_bf_x = c3_n_A;
  c3_cf_x = c3_bf_x;
  c3_ce_y = c3_cf_x / 4.0;
  c3_oc_a = c3_b_m;
  c3_od_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_de_y = c3_oc_a * c3_od_b;
  c3_df_x = (((c3_q[0] - c3_q[1]) - c3_q[2]) - c3_q[0]) + c3_q[1];
  c3_ef_x = c3_df_x;
  c3_ef_x = muDoubleScalarSin(c3_ef_x);
  c3_pc_a = c3_de_y;
  c3_pd_b = c3_ef_x;
  c3_ee_y = c3_pc_a * c3_pd_b;
  c3_qc_a = c3_ee_y;
  c3_qd_b = (((c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2]) - c3_q_dot[0]) -
    c3_q_dot[1];
  c3_fe_y = c3_qc_a * c3_qd_b;
  c3_o_A = c3_fe_y;
  c3_ff_x = c3_o_A;
  c3_gf_x = c3_ff_x;
  c3_ge_y = c3_gf_x / 4.0;
  c3_hf_x = ((((c3_q[0] - c3_q[1]) - c3_q[2]) - c3_q[0]) + c3_q[1]) + c3_q[2];
  c3_if_x = c3_hf_x;
  c3_if_x = muDoubleScalarSin(c3_if_x);
  c3_rc_a = c3_b_m;
  c3_rd_b = c3_if_x;
  c3_he_y = c3_rc_a * c3_rd_b;
  c3_sc_a = c3_he_y;
  c3_sd_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_ie_y = c3_sc_a * c3_sd_b;
  c3_tc_a = c3_ie_y;
  c3_td_b = ((((c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2]) - c3_q_dot[0]) -
             c3_q_dot[1]) - c3_q_dot[2];
  c3_je_y = c3_tc_a * c3_td_b;
  c3_p_A = c3_je_y;
  c3_jf_x = c3_p_A;
  c3_kf_x = c3_jf_x;
  c3_ke_y = c3_kf_x / 8.0;
  c3_lf_x = c3_q[0] + c3_q[1];
  c3_mf_x = c3_lf_x;
  c3_mf_x = muDoubleScalarSin(c3_mf_x);
  c3_uc_a = c3_b_m;
  c3_ud_b = c3_mf_x;
  c3_le_y = c3_uc_a * c3_ud_b;
  c3_vc_a = c3_le_y;
  c3_vd_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_me_y = c3_vc_a * c3_vd_b;
  c3_nf_x = c3_q[0];
  c3_of_x = c3_nf_x;
  c3_of_x = muDoubleScalarCos(c3_of_x);
  c3_wd_b = c3_of_x;
  c3_ne_y = 2.0 * c3_wd_b;
  c3_pf_x = c3_q[0] + c3_q[1];
  c3_qf_x = c3_pf_x;
  c3_qf_x = muDoubleScalarCos(c3_qf_x);
  c3_wc_a = c3_me_y;
  c3_xd_b = c3_ne_y + c3_qf_x;
  c3_oe_y = c3_wc_a * c3_xd_b;
  c3_q_A = c3_oe_y;
  c3_rf_x = c3_q_A;
  c3_sf_x = c3_rf_x;
  c3_pe_y = c3_sf_x / 8.0;
  c3_tf_x = c3_q[0] + c3_q[1];
  c3_uf_x = c3_tf_x;
  c3_uf_x = muDoubleScalarCos(c3_uf_x);
  c3_xc_a = c3_b_m;
  c3_yd_b = c3_uf_x;
  c3_qe_y = c3_xc_a * c3_yd_b;
  c3_yc_a = c3_qe_y;
  c3_ae_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_re_y = c3_yc_a * c3_ae_b;
  c3_vf_x = c3_q[0];
  c3_wf_x = c3_vf_x;
  c3_wf_x = muDoubleScalarSin(c3_wf_x);
  c3_be_b = c3_wf_x;
  c3_se_y = 2.0 * c3_be_b;
  c3_xf_x = c3_q[0] + c3_q[1];
  c3_yf_x = c3_xf_x;
  c3_yf_x = muDoubleScalarSin(c3_yf_x);
  c3_ad_a = c3_re_y;
  c3_ce_b = c3_se_y + c3_yf_x;
  c3_te_y = c3_ad_a * c3_ce_b;
  c3_r_A = c3_te_y;
  c3_ag_x = c3_r_A;
  c3_bg_x = c3_ag_x;
  c3_ue_y = c3_bg_x / 8.0;
  c3_bd_a = c3_b_m;
  c3_de_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_ve_y = c3_bd_a * c3_de_b;
  c3_cg_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_dg_x = c3_cg_x;
  c3_dg_x = muDoubleScalarSin(c3_dg_x);
  c3_eg_x = c3_q[0] + c3_q[1];
  c3_fg_x = c3_eg_x;
  c3_fg_x = muDoubleScalarSin(c3_fg_x);
  c3_ee_b = c3_fg_x;
  c3_we_y = 2.0 * c3_ee_b;
  c3_cd_a = c3_ve_y;
  c3_fe_b = c3_dg_x + c3_we_y;
  c3_xe_y = c3_cd_a * c3_fe_b;
  c3_gg_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_hg_x = c3_gg_x;
  c3_hg_x = muDoubleScalarCos(c3_hg_x);
  c3_ig_x = c3_q[0] + c3_q[1];
  c3_jg_x = c3_ig_x;
  c3_jg_x = muDoubleScalarCos(c3_jg_x);
  c3_ge_b = c3_jg_x;
  c3_ye_y = 2.0 * c3_ge_b;
  c3_kg_x = c3_q[0];
  c3_lg_x = c3_kg_x;
  c3_lg_x = muDoubleScalarCos(c3_lg_x);
  c3_he_b = c3_lg_x;
  c3_af_y = 2.0 * c3_he_b;
  c3_dd_a = c3_xe_y;
  c3_ie_b = (c3_hg_x + c3_ye_y) + c3_af_y;
  c3_bf_y = c3_dd_a * c3_ie_b;
  c3_s_A = c3_bf_y;
  c3_mg_x = c3_s_A;
  c3_ng_x = c3_mg_x;
  c3_cf_y = c3_ng_x / 8.0;
  c3_ed_a = c3_b_m;
  c3_je_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_df_y = c3_ed_a * c3_je_b;
  c3_og_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_pg_x = c3_og_x;
  c3_pg_x = muDoubleScalarCos(c3_pg_x);
  c3_qg_x = c3_q[0] + c3_q[1];
  c3_rg_x = c3_qg_x;
  c3_rg_x = muDoubleScalarCos(c3_rg_x);
  c3_ke_b = c3_rg_x;
  c3_ef_y = 2.0 * c3_ke_b;
  c3_fd_a = c3_df_y;
  c3_le_b = c3_pg_x + c3_ef_y;
  c3_ff_y = c3_fd_a * c3_le_b;
  c3_sg_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_tg_x = c3_sg_x;
  c3_tg_x = muDoubleScalarSin(c3_tg_x);
  c3_ug_x = c3_q[0] + c3_q[1];
  c3_vg_x = c3_ug_x;
  c3_vg_x = muDoubleScalarSin(c3_vg_x);
  c3_me_b = c3_vg_x;
  c3_gf_y = 2.0 * c3_me_b;
  c3_wg_x = c3_q[0];
  c3_xg_x = c3_wg_x;
  c3_xg_x = muDoubleScalarSin(c3_xg_x);
  c3_ne_b = c3_xg_x;
  c3_hf_y = 2.0 * c3_ne_b;
  c3_gd_a = c3_ff_y;
  c3_oe_b = (c3_tg_x + c3_gf_y) + c3_hf_y;
  c3_if_y = c3_gd_a * c3_oe_b;
  c3_t_A = c3_if_y;
  c3_yg_x = c3_t_A;
  c3_ah_x = c3_yg_x;
  c3_jf_y = c3_ah_x / 8.0;
  c3_hd_a = c3_b_m;
  c3_pe_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_kf_y = c3_hd_a * c3_pe_b;
  c3_bh_x = (((c3_q[0] - c3_q[1]) - c3_q[0]) + c3_q[1]) + c3_q[2];
  c3_ch_x = c3_bh_x;
  c3_ch_x = muDoubleScalarSin(c3_ch_x);
  c3_id_a = c3_kf_y;
  c3_qe_b = c3_ch_x;
  c3_lf_y = c3_id_a * c3_qe_b;
  c3_jd_a = c3_lf_y;
  c3_re_b = (((c3_q_dot[0] - c3_q_dot[1]) - c3_q_dot[0]) + c3_q_dot[1]) +
    c3_q_dot[2];
  c3_mf_y = c3_jd_a * c3_re_b;
  c3_u_A = c3_mf_y;
  c3_dh_x = c3_u_A;
  c3_eh_x = c3_dh_x;
  c3_nf_y = c3_eh_x / 4.0;
  c3_kd_a = c3_b_m;
  c3_se_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_of_y = c3_kd_a * c3_se_b;
  c3_fh_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_gh_x = c3_fh_x;
  c3_gh_x = muDoubleScalarSin(c3_gh_x);
  c3_hh_x = c3_q[0] + c3_q[1];
  c3_ih_x = c3_hh_x;
  c3_ih_x = muDoubleScalarSin(c3_ih_x);
  c3_te_b = c3_ih_x;
  c3_pf_y = 2.0 * c3_te_b;
  c3_ld_a = c3_of_y;
  c3_ue_b = c3_gh_x + c3_pf_y;
  c3_qf_y = c3_ld_a * c3_ue_b;
  c3_jh_x = c3_q[0];
  c3_kh_x = c3_jh_x;
  c3_kh_x = muDoubleScalarCos(c3_kh_x);
  c3_ve_b = c3_kh_x;
  c3_rf_y = 2.0 * c3_ve_b;
  c3_lh_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_mh_x = c3_lh_x;
  c3_mh_x = muDoubleScalarCos(c3_mh_x);
  c3_nh_x = c3_q[0] + c3_q[1];
  c3_oh_x = c3_nh_x;
  c3_oh_x = muDoubleScalarCos(c3_oh_x);
  c3_we_b = c3_oh_x;
  c3_sf_y = 2.0 * c3_we_b;
  c3_md_a = c3_qf_y;
  c3_xe_b = (c3_rf_y + c3_mh_x) + c3_sf_y;
  c3_tf_y = c3_md_a * c3_xe_b;
  c3_v_A = c3_tf_y;
  c3_ph_x = c3_v_A;
  c3_qh_x = c3_ph_x;
  c3_uf_y = c3_qh_x / 8.0;
  c3_nd_a = c3_b_m;
  c3_ye_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_vf_y = c3_nd_a * c3_ye_b;
  c3_rh_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_sh_x = c3_rh_x;
  c3_sh_x = muDoubleScalarCos(c3_sh_x);
  c3_th_x = c3_q[0] + c3_q[1];
  c3_uh_x = c3_th_x;
  c3_uh_x = muDoubleScalarCos(c3_uh_x);
  c3_af_b = c3_uh_x;
  c3_wf_y = 2.0 * c3_af_b;
  c3_od_a = c3_vf_y;
  c3_bf_b = c3_sh_x + c3_wf_y;
  c3_xf_y = c3_od_a * c3_bf_b;
  c3_vh_x = c3_q[0];
  c3_wh_x = c3_vh_x;
  c3_wh_x = muDoubleScalarSin(c3_wh_x);
  c3_cf_b = c3_wh_x;
  c3_yf_y = 2.0 * c3_cf_b;
  c3_xh_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_yh_x = c3_xh_x;
  c3_yh_x = muDoubleScalarSin(c3_yh_x);
  c3_ai_x = c3_q[0] + c3_q[1];
  c3_bi_x = c3_ai_x;
  c3_bi_x = muDoubleScalarSin(c3_bi_x);
  c3_df_b = c3_bi_x;
  c3_ag_y = 2.0 * c3_df_b;
  c3_pd_a = c3_xf_y;
  c3_ef_b = (c3_yf_y + c3_yh_x) + c3_ag_y;
  c3_bg_y = c3_pd_a * c3_ef_b;
  c3_w_A = c3_bg_y;
  c3_ci_x = c3_w_A;
  c3_di_x = c3_ci_x;
  c3_cg_y = c3_di_x / 8.0;
  c3_ei_x = c3_q[0] + c3_q[1];
  c3_fi_x = c3_ei_x;
  c3_fi_x = muDoubleScalarSin(c3_fi_x);
  c3_qd_a = c3_b_m;
  c3_ff_b = c3_fi_x;
  c3_dg_y = c3_qd_a * c3_ff_b;
  c3_rd_a = c3_dg_y;
  c3_gf_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_eg_y = c3_rd_a * c3_gf_b;
  c3_gi_x = c3_q[0] + c3_q[1];
  c3_hi_x = c3_gi_x;
  c3_hi_x = muDoubleScalarCos(c3_hi_x);
  c3_ii_x = c3_q[0];
  c3_ji_x = c3_ii_x;
  c3_ji_x = muDoubleScalarCos(c3_ji_x);
  c3_hf_b = c3_ji_x;
  c3_fg_y = 2.0 * c3_hf_b;
  c3_sd_a = c3_eg_y;
  c3_if_b = c3_hi_x + c3_fg_y;
  c3_gg_y = c3_sd_a * c3_if_b;
  c3_x_A = c3_gg_y;
  c3_ki_x = c3_x_A;
  c3_li_x = c3_ki_x;
  c3_hg_y = c3_li_x / 8.0;
  c3_jf_b = c3_b_m;
  c3_ig_y = 3.0 * c3_jf_b;
  c3_mi_x = (c3_q[0] - c3_q[1]) - c3_q[0];
  c3_ni_x = c3_mi_x;
  c3_ni_x = muDoubleScalarSin(c3_ni_x);
  c3_td_a = c3_ig_y;
  c3_kf_b = c3_ni_x;
  c3_jg_y = c3_td_a * c3_kf_b;
  c3_ud_a = c3_jg_y;
  c3_lf_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_kg_y = c3_ud_a * c3_lf_b;
  c3_vd_a = c3_kg_y;
  c3_mf_b = (c3_q_dot[0] + c3_q_dot[1]) - c3_q_dot[0];
  c3_lg_y = c3_vd_a * c3_mf_b;
  c3_y_A = c3_lg_y;
  c3_oi_x = c3_y_A;
  c3_pi_x = c3_oi_x;
  c3_mg_y = c3_pi_x / 4.0;
  c3_qi_x = c3_q[0] + c3_q[1];
  c3_ri_x = c3_qi_x;
  c3_ri_x = muDoubleScalarCos(c3_ri_x);
  c3_wd_a = c3_b_m;
  c3_nf_b = c3_ri_x;
  c3_ng_y = c3_wd_a * c3_nf_b;
  c3_xd_a = c3_ng_y;
  c3_of_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_og_y = c3_xd_a * c3_of_b;
  c3_si_x = c3_q[0] + c3_q[1];
  c3_ti_x = c3_si_x;
  c3_ti_x = muDoubleScalarSin(c3_ti_x);
  c3_ui_x = c3_q[0];
  c3_vi_x = c3_ui_x;
  c3_vi_x = muDoubleScalarSin(c3_vi_x);
  c3_pf_b = c3_vi_x;
  c3_pg_y = 2.0 * c3_pf_b;
  c3_yd_a = c3_og_y;
  c3_qf_b = c3_ti_x + c3_pg_y;
  c3_qg_y = c3_yd_a * c3_qf_b;
  c3_ab_A = c3_qg_y;
  c3_wi_x = c3_ab_A;
  c3_xi_x = c3_wi_x;
  c3_rg_y = c3_xi_x / 8.0;
  c3_rf_b = c3_b_m;
  c3_sg_y = 5.0 * c3_rf_b;
  c3_yi_x = ((c3_q[0] - c3_q[1]) - c3_q[0]) + c3_q[1];
  c3_aj_x = c3_yi_x;
  c3_aj_x = muDoubleScalarSin(c3_aj_x);
  c3_ae_a = c3_sg_y;
  c3_sf_b = c3_aj_x;
  c3_tg_y = c3_ae_a * c3_sf_b;
  c3_be_a = c3_tg_y;
  c3_tf_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_ug_y = c3_be_a * c3_tf_b;
  c3_ce_a = c3_ug_y;
  c3_uf_b = ((c3_q_dot[0] + c3_q_dot[1]) - c3_q_dot[0]) - c3_q_dot[1];
  c3_vg_y = c3_ce_a * c3_uf_b;
  c3_bb_A = c3_vg_y;
  c3_bj_x = c3_bb_A;
  c3_cj_x = c3_bj_x;
  c3_wg_y = c3_cj_x / 8.0;
  c3_dj_x = ((c3_q[0] - c3_q[1]) - c3_q[2]) - c3_q[0];
  c3_ej_x = c3_dj_x;
  c3_ej_x = muDoubleScalarSin(c3_ej_x);
  c3_de_a = c3_b_m;
  c3_vf_b = c3_ej_x;
  c3_xg_y = c3_de_a * c3_vf_b;
  c3_ee_a = c3_xg_y;
  c3_wf_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_yg_y = c3_ee_a * c3_wf_b;
  c3_fe_a = c3_yg_y;
  c3_xf_b = ((c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2]) - c3_q_dot[0];
  c3_ah_y = c3_fe_a * c3_xf_b;
  c3_cb_A = c3_ah_y;
  c3_fj_x = c3_cb_A;
  c3_gj_x = c3_fj_x;
  c3_bh_y = c3_gj_x / 4.0;
  c3_hj_x = ((c3_q[0] - c3_q[1]) - c3_q[2]) - c3_q[0];
  c3_ij_x = c3_hj_x;
  c3_ij_x = muDoubleScalarSin(c3_ij_x);
  c3_ge_a = c3_b_m;
  c3_yf_b = c3_ij_x;
  c3_ch_y = c3_ge_a * c3_yf_b;
  c3_he_a = c3_ch_y;
  c3_ag_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_dh_y = c3_he_a * c3_ag_b;
  c3_db_A = c3_dh_y;
  c3_jj_x = c3_db_A;
  c3_kj_x = c3_jj_x;
  c3_eh_y = c3_kj_x / 4.0;
  c3_ie_a = c3_b_m;
  c3_bg_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_fh_y = c3_ie_a * c3_bg_b;
  c3_lj_x = ((c3_q[0] - c3_q[1]) - c3_q[2]) - c3_q[0];
  c3_mj_x = c3_lj_x;
  c3_mj_x = muDoubleScalarSin(c3_mj_x);
  c3_cg_b = c3_mj_x;
  c3_gh_y = 2.0 * c3_cg_b;
  c3_nj_x = (((c3_q[0] - c3_q[1]) - c3_q[2]) - c3_q[0]) + c3_q[1];
  c3_oj_x = c3_nj_x;
  c3_oj_x = muDoubleScalarSin(c3_oj_x);
  c3_dg_b = c3_oj_x;
  c3_hh_y = 2.0 * c3_dg_b;
  c3_je_a = c3_fh_y;
  c3_eg_b = c3_gh_y + c3_hh_y;
  c3_ih_y = c3_je_a * c3_eg_b;
  c3_eb_A = c3_ih_y;
  c3_pj_x = c3_eb_A;
  c3_qj_x = c3_pj_x;
  c3_jh_y = c3_qj_x / 8.0;
  c3_ke_a = c3_b_m;
  c3_fg_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_kh_y = c3_ke_a * c3_fg_b;
  c3_rj_x = ((c3_q[0] - c3_q[1]) - c3_q[2]) - c3_q[0];
  c3_sj_x = c3_rj_x;
  c3_sj_x = muDoubleScalarSin(c3_sj_x);
  c3_gg_b = c3_sj_x;
  c3_lh_y = 2.0 * c3_gg_b;
  c3_le_a = c3_lh_y;
  c3_hg_b = ((c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2]) - c3_q_dot[0];
  c3_mh_y = c3_le_a * c3_hg_b;
  c3_tj_x = (((c3_q[0] - c3_q[1]) - c3_q[2]) - c3_q[0]) + c3_q[1];
  c3_uj_x = c3_tj_x;
  c3_uj_x = muDoubleScalarSin(c3_uj_x);
  c3_ig_b = c3_uj_x;
  c3_nh_y = 2.0 * c3_ig_b;
  c3_me_a = c3_nh_y;
  c3_jg_b = (((c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2]) - c3_q_dot[0]) -
    c3_q_dot[1];
  c3_oh_y = c3_me_a * c3_jg_b;
  c3_vj_x = ((((c3_q[0] - c3_q[1]) - c3_q[2]) - c3_q[0]) + c3_q[1]) + c3_q[2];
  c3_wj_x = c3_vj_x;
  c3_wj_x = muDoubleScalarSin(c3_wj_x);
  c3_ne_a = c3_wj_x;
  c3_kg_b = ((((c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2]) - c3_q_dot[0]) -
             c3_q_dot[1]) - c3_q_dot[2];
  c3_ph_y = c3_ne_a * c3_kg_b;
  c3_oe_a = c3_kh_y;
  c3_lg_b = (c3_mh_y + c3_oh_y) + c3_ph_y;
  c3_qh_y = c3_oe_a * c3_lg_b;
  c3_fb_A = c3_qh_y;
  c3_xj_x = c3_fb_A;
  c3_yj_x = c3_xj_x;
  c3_rh_y = c3_yj_x / 8.0;
  c3_pe_a = c3_b_m;
  c3_mg_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_sh_y = c3_pe_a * c3_mg_b;
  c3_ak_x = (((c3_q[0] - c3_q[1]) - c3_q[2]) - c3_q[0]) + c3_q[1];
  c3_bk_x = c3_ak_x;
  c3_bk_x = muDoubleScalarSin(c3_bk_x);
  c3_qe_a = c3_sh_y;
  c3_ng_b = c3_bk_x;
  c3_th_y = c3_qe_a * c3_ng_b;
  c3_gb_A = c3_th_y;
  c3_ck_x = c3_gb_A;
  c3_dk_x = c3_ck_x;
  c3_uh_y = c3_dk_x / 4.0;
  c3_re_a = c3_b_m;
  c3_og_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_vh_y = c3_re_a * c3_og_b;
  c3_ek_x = (((c3_q[0] - c3_q[1]) - c3_q[0]) + c3_q[1]) + c3_q[2];
  c3_fk_x = c3_ek_x;
  c3_fk_x = muDoubleScalarSin(c3_fk_x);
  c3_se_a = c3_vh_y;
  c3_pg_b = c3_fk_x;
  c3_wh_y = c3_se_a * c3_pg_b;
  c3_hb_A = c3_wh_y;
  c3_gk_x = c3_hb_A;
  c3_hk_x = c3_gk_x;
  c3_xh_y = c3_hk_x / 4.0;
  c3_ik_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_jk_x = c3_ik_x;
  c3_jk_x = muDoubleScalarCos(c3_jk_x);
  c3_te_a = c3_b_m;
  c3_qg_b = c3_jk_x;
  c3_yh_y = c3_te_a * c3_qg_b;
  c3_ue_a = c3_yh_y;
  c3_rg_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_ai_y = c3_ue_a * c3_rg_b;
  c3_kk_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_lk_x = c3_kk_x;
  c3_lk_x = muDoubleScalarSin(c3_lk_x);
  c3_mk_x = c3_q[0] + c3_q[1];
  c3_nk_x = c3_mk_x;
  c3_nk_x = muDoubleScalarSin(c3_nk_x);
  c3_sg_b = c3_nk_x;
  c3_bi_y = 2.0 * c3_sg_b;
  c3_ok_x = c3_q[0];
  c3_pk_x = c3_ok_x;
  c3_pk_x = muDoubleScalarSin(c3_pk_x);
  c3_tg_b = c3_pk_x;
  c3_ci_y = 2.0 * c3_tg_b;
  c3_ve_a = c3_ai_y;
  c3_ug_b = (c3_lk_x + c3_bi_y) + c3_ci_y;
  c3_di_y = c3_ve_a * c3_ug_b;
  c3_ib_A = c3_di_y;
  c3_qk_x = c3_ib_A;
  c3_rk_x = c3_qk_x;
  c3_ei_y = c3_rk_x / 8.0;
  c3_sk_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_tk_x = c3_sk_x;
  c3_tk_x = muDoubleScalarSin(c3_tk_x);
  c3_we_a = c3_b_m;
  c3_vg_b = c3_tk_x;
  c3_fi_y = c3_we_a * c3_vg_b;
  c3_xe_a = c3_fi_y;
  c3_wg_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_gi_y = c3_xe_a * c3_wg_b;
  c3_uk_x = c3_q[0];
  c3_vk_x = c3_uk_x;
  c3_vk_x = muDoubleScalarCos(c3_vk_x);
  c3_xg_b = c3_vk_x;
  c3_hi_y = 2.0 * c3_xg_b;
  c3_wk_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_xk_x = c3_wk_x;
  c3_xk_x = muDoubleScalarCos(c3_xk_x);
  c3_yk_x = c3_q[0] + c3_q[1];
  c3_al_x = c3_yk_x;
  c3_al_x = muDoubleScalarCos(c3_al_x);
  c3_yg_b = c3_al_x;
  c3_ii_y = 2.0 * c3_yg_b;
  c3_ye_a = c3_gi_y;
  c3_ah_b = (c3_hi_y + c3_xk_x) + c3_ii_y;
  c3_ji_y = c3_ye_a * c3_ah_b;
  c3_jb_A = c3_ji_y;
  c3_bl_x = c3_jb_A;
  c3_cl_x = c3_bl_x;
  c3_ki_y = c3_cl_x / 8.0;
  c3_dl_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_el_x = c3_dl_x;
  c3_el_x = muDoubleScalarCos(c3_el_x);
  c3_af_a = c3_b_m;
  c3_bh_b = c3_el_x;
  c3_li_y = c3_af_a * c3_bh_b;
  c3_bf_a = c3_li_y;
  c3_ch_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_mi_y = c3_bf_a * c3_ch_b;
  c3_fl_x = c3_q[0];
  c3_gl_x = c3_fl_x;
  c3_gl_x = muDoubleScalarSin(c3_gl_x);
  c3_dh_b = c3_gl_x;
  c3_ni_y = 2.0 * c3_dh_b;
  c3_hl_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_il_x = c3_hl_x;
  c3_il_x = muDoubleScalarSin(c3_il_x);
  c3_jl_x = c3_q[0] + c3_q[1];
  c3_kl_x = c3_jl_x;
  c3_kl_x = muDoubleScalarSin(c3_kl_x);
  c3_eh_b = c3_kl_x;
  c3_oi_y = 2.0 * c3_eh_b;
  c3_cf_a = c3_mi_y;
  c3_fh_b = (c3_ni_y + c3_il_x) + c3_oi_y;
  c3_pi_y = c3_cf_a * c3_fh_b;
  c3_kb_A = c3_pi_y;
  c3_ll_x = c3_kb_A;
  c3_ml_x = c3_ll_x;
  c3_qi_y = c3_ml_x / 8.0;
  c3_nl_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_ol_x = c3_nl_x;
  c3_ol_x = muDoubleScalarSin(c3_ol_x);
  c3_df_a = c3_b_m;
  c3_gh_b = c3_ol_x;
  c3_ri_y = c3_df_a * c3_gh_b;
  c3_ef_a = c3_ri_y;
  c3_hh_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_si_y = c3_ef_a * c3_hh_b;
  c3_pl_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_ql_x = c3_pl_x;
  c3_ql_x = muDoubleScalarCos(c3_ql_x);
  c3_rl_x = c3_q[0] + c3_q[1];
  c3_sl_x = c3_rl_x;
  c3_sl_x = muDoubleScalarCos(c3_sl_x);
  c3_ih_b = c3_sl_x;
  c3_ti_y = 2.0 * c3_ih_b;
  c3_tl_x = c3_q[0];
  c3_ul_x = c3_tl_x;
  c3_ul_x = muDoubleScalarCos(c3_ul_x);
  c3_jh_b = c3_ul_x;
  c3_ui_y = 2.0 * c3_jh_b;
  c3_ff_a = c3_si_y;
  c3_kh_b = (c3_ql_x + c3_ti_y) + c3_ui_y;
  c3_vi_y = c3_ff_a * c3_kh_b;
  c3_lb_A = c3_vi_y;
  c3_vl_x = c3_lb_A;
  c3_wl_x = c3_vl_x;
  c3_wi_y = c3_wl_x / 8.0;
  c3_xl_x = ((c3_q[0] - c3_q[1]) - c3_q[2]) - c3_q[0];
  c3_yl_x = c3_xl_x;
  c3_yl_x = muDoubleScalarSin(c3_yl_x);
  c3_gf_a = c3_b_m;
  c3_lh_b = c3_yl_x;
  c3_xi_y = c3_gf_a * c3_lh_b;
  c3_hf_a = c3_xi_y;
  c3_mh_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_yi_y = c3_hf_a * c3_mh_b;
  c3_mb_A = c3_yi_y;
  c3_am_x = c3_mb_A;
  c3_bm_x = c3_am_x;
  c3_aj_y = c3_bm_x / 2.0;
  c3_nh_b = c3_b_m;
  c3_bj_y = 3.0 * c3_nh_b;
  c3_cm_x = (c3_q[0] - c3_q[1]) - c3_q[0];
  c3_dm_x = c3_cm_x;
  c3_dm_x = muDoubleScalarSin(c3_dm_x);
  c3_if_a = c3_bj_y;
  c3_oh_b = c3_dm_x;
  c3_cj_y = c3_if_a * c3_oh_b;
  c3_jf_a = c3_cj_y;
  c3_ph_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_dj_y = c3_jf_a * c3_ph_b;
  c3_nb_A = c3_dj_y;
  c3_em_x = c3_nb_A;
  c3_fm_x = c3_em_x;
  c3_ej_y = c3_fm_x / 4.0;
  c3_kf_a = c3_b_m;
  c3_qh_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_fj_y = c3_kf_a * c3_qh_b;
  c3_gm_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_hm_x = c3_gm_x;
  c3_hm_x = muDoubleScalarCos(c3_hm_x);
  c3_im_x = c3_q[0] + c3_q[1];
  c3_jm_x = c3_im_x;
  c3_jm_x = muDoubleScalarCos(c3_jm_x);
  c3_rh_b = c3_jm_x;
  c3_gj_y = 2.0 * c3_rh_b;
  c3_lf_a = c3_fj_y;
  c3_sh_b = c3_hm_x + c3_gj_y;
  c3_hj_y = c3_lf_a * c3_sh_b;
  c3_km_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_lm_x = c3_km_x;
  c3_lm_x = muDoubleScalarSin(c3_lm_x);
  c3_mf_a = c3_lm_x;
  c3_th_b = (c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2];
  c3_ij_y = c3_mf_a * c3_th_b;
  c3_mm_x = c3_q[0] + c3_q[1];
  c3_nm_x = c3_mm_x;
  c3_nm_x = muDoubleScalarSin(c3_nm_x);
  c3_uh_b = c3_nm_x;
  c3_jj_y = 2.0 * c3_uh_b;
  c3_nf_a = c3_jj_y;
  c3_vh_b = c3_q_dot[0] + c3_q_dot[1];
  c3_kj_y = c3_nf_a * c3_vh_b;
  c3_wh_b = c3_q_dot[0];
  c3_lj_y = 2.0 * c3_wh_b;
  c3_om_x = c3_q[0];
  c3_pm_x = c3_om_x;
  c3_pm_x = muDoubleScalarSin(c3_pm_x);
  c3_of_a = c3_lj_y;
  c3_xh_b = c3_pm_x;
  c3_mj_y = c3_of_a * c3_xh_b;
  c3_pf_a = c3_hj_y;
  c3_yh_b = (c3_ij_y + c3_kj_y) + c3_mj_y;
  c3_nj_y = c3_pf_a * c3_yh_b;
  c3_ob_A = c3_nj_y;
  c3_qm_x = c3_ob_A;
  c3_rm_x = c3_qm_x;
  c3_oj_y = c3_rm_x / 8.0;
  c3_sm_x = c3_q[0] + c3_q[1];
  c3_tm_x = c3_sm_x;
  c3_tm_x = muDoubleScalarSin(c3_tm_x);
  c3_qf_a = c3_b_m;
  c3_ai_b = c3_tm_x;
  c3_pj_y = c3_qf_a * c3_ai_b;
  c3_rf_a = c3_pj_y;
  c3_bi_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_qj_y = c3_rf_a * c3_bi_b;
  c3_um_x = c3_q[0];
  c3_vm_x = c3_um_x;
  c3_vm_x = muDoubleScalarCos(c3_vm_x);
  c3_ci_b = c3_vm_x;
  c3_rj_y = 2.0 * c3_ci_b;
  c3_wm_x = c3_q[0] + c3_q[1];
  c3_xm_x = c3_wm_x;
  c3_xm_x = muDoubleScalarCos(c3_xm_x);
  c3_sf_a = c3_qj_y;
  c3_di_b = c3_rj_y + c3_xm_x;
  c3_sj_y = c3_sf_a * c3_di_b;
  c3_pb_A = c3_sj_y;
  c3_ym_x = c3_pb_A;
  c3_an_x = c3_ym_x;
  c3_tj_y = c3_an_x / 8.0;
  c3_bn_x = c3_q[0] + c3_q[1];
  c3_cn_x = c3_bn_x;
  c3_cn_x = muDoubleScalarCos(c3_cn_x);
  c3_tf_a = c3_b_m;
  c3_ei_b = c3_cn_x;
  c3_uj_y = c3_tf_a * c3_ei_b;
  c3_uf_a = c3_uj_y;
  c3_fi_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_vj_y = c3_uf_a * c3_fi_b;
  c3_dn_x = c3_q[0];
  c3_en_x = c3_dn_x;
  c3_en_x = muDoubleScalarSin(c3_en_x);
  c3_gi_b = c3_en_x;
  c3_wj_y = 2.0 * c3_gi_b;
  c3_fn_x = c3_q[0] + c3_q[1];
  c3_gn_x = c3_fn_x;
  c3_gn_x = muDoubleScalarSin(c3_gn_x);
  c3_vf_a = c3_vj_y;
  c3_hi_b = c3_wj_y + c3_gn_x;
  c3_xj_y = c3_vf_a * c3_hi_b;
  c3_qb_A = c3_xj_y;
  c3_hn_x = c3_qb_A;
  c3_in_x = c3_hn_x;
  c3_yj_y = c3_in_x / 8.0;
  c3_wf_a = c3_b_m;
  c3_ii_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_ak_y = c3_wf_a * c3_ii_b;
  c3_jn_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_kn_x = c3_jn_x;
  c3_kn_x = muDoubleScalarSin(c3_kn_x);
  c3_ln_x = c3_q[0] + c3_q[1];
  c3_mn_x = c3_ln_x;
  c3_mn_x = muDoubleScalarSin(c3_mn_x);
  c3_ji_b = c3_mn_x;
  c3_bk_y = 2.0 * c3_ji_b;
  c3_xf_a = c3_ak_y;
  c3_ki_b = c3_kn_x + c3_bk_y;
  c3_ck_y = c3_xf_a * c3_ki_b;
  c3_nn_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_on_x = c3_nn_x;
  c3_on_x = muDoubleScalarCos(c3_on_x);
  c3_pn_x = c3_q[0] + c3_q[1];
  c3_qn_x = c3_pn_x;
  c3_qn_x = muDoubleScalarCos(c3_qn_x);
  c3_li_b = c3_qn_x;
  c3_dk_y = 2.0 * c3_li_b;
  c3_rn_x = c3_q[0];
  c3_sn_x = c3_rn_x;
  c3_sn_x = muDoubleScalarCos(c3_sn_x);
  c3_mi_b = c3_sn_x;
  c3_ek_y = 2.0 * c3_mi_b;
  c3_yf_a = c3_ck_y;
  c3_ni_b = (c3_on_x + c3_dk_y) + c3_ek_y;
  c3_fk_y = c3_yf_a * c3_ni_b;
  c3_rb_A = c3_fk_y;
  c3_tn_x = c3_rb_A;
  c3_un_x = c3_tn_x;
  c3_gk_y = c3_un_x / 8.0;
  c3_ag_a = c3_b_m;
  c3_oi_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_hk_y = c3_ag_a * c3_oi_b;
  c3_vn_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_wn_x = c3_vn_x;
  c3_wn_x = muDoubleScalarCos(c3_wn_x);
  c3_xn_x = c3_q[0] + c3_q[1];
  c3_yn_x = c3_xn_x;
  c3_yn_x = muDoubleScalarCos(c3_yn_x);
  c3_pi_b = c3_yn_x;
  c3_ik_y = 2.0 * c3_pi_b;
  c3_bg_a = c3_hk_y;
  c3_qi_b = c3_wn_x + c3_ik_y;
  c3_jk_y = c3_bg_a * c3_qi_b;
  c3_ao_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_bo_x = c3_ao_x;
  c3_bo_x = muDoubleScalarSin(c3_bo_x);
  c3_co_x = c3_q[0] + c3_q[1];
  c3_do_x = c3_co_x;
  c3_do_x = muDoubleScalarSin(c3_do_x);
  c3_ri_b = c3_do_x;
  c3_kk_y = 2.0 * c3_ri_b;
  c3_eo_x = c3_q[0];
  c3_fo_x = c3_eo_x;
  c3_fo_x = muDoubleScalarSin(c3_fo_x);
  c3_si_b = c3_fo_x;
  c3_lk_y = 2.0 * c3_si_b;
  c3_cg_a = c3_jk_y;
  c3_ti_b = (c3_bo_x + c3_kk_y) + c3_lk_y;
  c3_mk_y = c3_cg_a * c3_ti_b;
  c3_sb_A = c3_mk_y;
  c3_go_x = c3_sb_A;
  c3_ho_x = c3_go_x;
  c3_nk_y = c3_ho_x / 8.0;
  c3_dg_a = c3_b_m;
  c3_ui_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_ok_y = c3_dg_a * c3_ui_b;
  c3_io_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_jo_x = c3_io_x;
  c3_jo_x = muDoubleScalarSin(c3_jo_x);
  c3_eg_a = c3_jo_x;
  c3_vi_b = (c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2];
  c3_pk_y = c3_eg_a * c3_vi_b;
  c3_ko_x = c3_q[0] + c3_q[1];
  c3_lo_x = c3_ko_x;
  c3_lo_x = muDoubleScalarSin(c3_lo_x);
  c3_wi_b = c3_lo_x;
  c3_qk_y = 2.0 * c3_wi_b;
  c3_fg_a = c3_qk_y;
  c3_xi_b = c3_q_dot[0] + c3_q_dot[1];
  c3_rk_y = c3_fg_a * c3_xi_b;
  c3_gg_a = c3_ok_y;
  c3_yi_b = c3_pk_y + c3_rk_y;
  c3_sk_y = c3_gg_a * c3_yi_b;
  c3_mo_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_no_x = c3_mo_x;
  c3_no_x = muDoubleScalarCos(c3_no_x);
  c3_oo_x = c3_q[0] + c3_q[1];
  c3_po_x = c3_oo_x;
  c3_po_x = muDoubleScalarCos(c3_po_x);
  c3_aj_b = c3_po_x;
  c3_tk_y = 2.0 * c3_aj_b;
  c3_qo_x = c3_q[0];
  c3_ro_x = c3_qo_x;
  c3_ro_x = muDoubleScalarCos(c3_ro_x);
  c3_bj_b = c3_ro_x;
  c3_uk_y = 2.0 * c3_bj_b;
  c3_hg_a = c3_sk_y;
  c3_cj_b = (c3_no_x + c3_tk_y) + c3_uk_y;
  c3_vk_y = c3_hg_a * c3_cj_b;
  c3_tb_A = c3_vk_y;
  c3_so_x = c3_tb_A;
  c3_to_x = c3_so_x;
  c3_wk_y = c3_to_x / 8.0;
  c3_ig_a = c3_b_m;
  c3_dj_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_xk_y = c3_ig_a * c3_dj_b;
  c3_uo_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_vo_x = c3_uo_x;
  c3_vo_x = muDoubleScalarCos(c3_vo_x);
  c3_jg_a = c3_vo_x;
  c3_ej_b = (c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2];
  c3_yk_y = c3_jg_a * c3_ej_b;
  c3_wo_x = c3_q[0] + c3_q[1];
  c3_xo_x = c3_wo_x;
  c3_xo_x = muDoubleScalarCos(c3_xo_x);
  c3_fj_b = c3_xo_x;
  c3_al_y = 2.0 * c3_fj_b;
  c3_kg_a = c3_al_y;
  c3_gj_b = c3_q_dot[0] + c3_q_dot[1];
  c3_bl_y = c3_kg_a * c3_gj_b;
  c3_lg_a = c3_xk_y;
  c3_hj_b = c3_yk_y + c3_bl_y;
  c3_cl_y = c3_lg_a * c3_hj_b;
  c3_yo_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_ap_x = c3_yo_x;
  c3_ap_x = muDoubleScalarSin(c3_ap_x);
  c3_bp_x = c3_q[0] + c3_q[1];
  c3_cp_x = c3_bp_x;
  c3_cp_x = muDoubleScalarSin(c3_cp_x);
  c3_ij_b = c3_cp_x;
  c3_dl_y = 2.0 * c3_ij_b;
  c3_dp_x = c3_q[0];
  c3_ep_x = c3_dp_x;
  c3_ep_x = muDoubleScalarSin(c3_ep_x);
  c3_jj_b = c3_ep_x;
  c3_el_y = 2.0 * c3_jj_b;
  c3_mg_a = c3_cl_y;
  c3_kj_b = (c3_ap_x + c3_dl_y) + c3_el_y;
  c3_fl_y = c3_mg_a * c3_kj_b;
  c3_ub_A = c3_fl_y;
  c3_fp_x = c3_ub_A;
  c3_gp_x = c3_fp_x;
  c3_gl_y = c3_gp_x / 8.0;
  c3_ng_a = c3_b_m;
  c3_lj_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_hl_y = c3_ng_a * c3_lj_b;
  c3_hp_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_ip_x = c3_hp_x;
  c3_ip_x = muDoubleScalarSin(c3_ip_x);
  c3_jp_x = c3_q[0] + c3_q[1];
  c3_kp_x = c3_jp_x;
  c3_kp_x = muDoubleScalarSin(c3_kp_x);
  c3_mj_b = c3_kp_x;
  c3_il_y = 2.0 * c3_mj_b;
  c3_og_a = c3_hl_y;
  c3_nj_b = c3_ip_x + c3_il_y;
  c3_jl_y = c3_og_a * c3_nj_b;
  c3_lp_x = c3_q[0];
  c3_mp_x = c3_lp_x;
  c3_mp_x = muDoubleScalarCos(c3_mp_x);
  c3_oj_b = c3_mp_x;
  c3_kl_y = 2.0 * c3_oj_b;
  c3_np_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_op_x = c3_np_x;
  c3_op_x = muDoubleScalarCos(c3_op_x);
  c3_pp_x = c3_q[0] + c3_q[1];
  c3_qp_x = c3_pp_x;
  c3_qp_x = muDoubleScalarCos(c3_qp_x);
  c3_pj_b = c3_qp_x;
  c3_ll_y = 2.0 * c3_pj_b;
  c3_pg_a = c3_jl_y;
  c3_qj_b = (c3_kl_y + c3_op_x) + c3_ll_y;
  c3_ml_y = c3_pg_a * c3_qj_b;
  c3_vb_A = c3_ml_y;
  c3_rp_x = c3_vb_A;
  c3_sp_x = c3_rp_x;
  c3_nl_y = c3_sp_x / 8.0;
  c3_qg_a = c3_b_m;
  c3_rj_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_ol_y = c3_qg_a * c3_rj_b;
  c3_tp_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_up_x = c3_tp_x;
  c3_up_x = muDoubleScalarCos(c3_up_x);
  c3_vp_x = c3_q[0] + c3_q[1];
  c3_wp_x = c3_vp_x;
  c3_wp_x = muDoubleScalarCos(c3_wp_x);
  c3_sj_b = c3_wp_x;
  c3_pl_y = 2.0 * c3_sj_b;
  c3_rg_a = c3_ol_y;
  c3_tj_b = c3_up_x + c3_pl_y;
  c3_ql_y = c3_rg_a * c3_tj_b;
  c3_xp_x = c3_q[0];
  c3_yp_x = c3_xp_x;
  c3_yp_x = muDoubleScalarSin(c3_yp_x);
  c3_uj_b = c3_yp_x;
  c3_rl_y = 2.0 * c3_uj_b;
  c3_aq_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_bq_x = c3_aq_x;
  c3_bq_x = muDoubleScalarSin(c3_bq_x);
  c3_cq_x = c3_q[0] + c3_q[1];
  c3_dq_x = c3_cq_x;
  c3_dq_x = muDoubleScalarSin(c3_dq_x);
  c3_vj_b = c3_dq_x;
  c3_sl_y = 2.0 * c3_vj_b;
  c3_sg_a = c3_ql_y;
  c3_wj_b = (c3_rl_y + c3_bq_x) + c3_sl_y;
  c3_tl_y = c3_sg_a * c3_wj_b;
  c3_wb_A = c3_tl_y;
  c3_eq_x = c3_wb_A;
  c3_fq_x = c3_eq_x;
  c3_ul_y = c3_fq_x / 8.0;
  c3_gq_x = c3_q[0] + c3_q[1];
  c3_hq_x = c3_gq_x;
  c3_hq_x = muDoubleScalarSin(c3_hq_x);
  c3_tg_a = c3_b_m;
  c3_xj_b = c3_hq_x;
  c3_vl_y = c3_tg_a * c3_xj_b;
  c3_ug_a = c3_vl_y;
  c3_yj_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_wl_y = c3_ug_a * c3_yj_b;
  c3_iq_x = c3_q[0] + c3_q[1];
  c3_jq_x = c3_iq_x;
  c3_jq_x = muDoubleScalarCos(c3_jq_x);
  c3_kq_x = c3_q[0];
  c3_lq_x = c3_kq_x;
  c3_lq_x = muDoubleScalarCos(c3_lq_x);
  c3_ak_b = c3_lq_x;
  c3_xl_y = 2.0 * c3_ak_b;
  c3_vg_a = c3_wl_y;
  c3_bk_b = c3_jq_x + c3_xl_y;
  c3_yl_y = c3_vg_a * c3_bk_b;
  c3_xb_A = c3_yl_y;
  c3_mq_x = c3_xb_A;
  c3_nq_x = c3_mq_x;
  c3_am_y = c3_nq_x / 8.0;
  c3_oq_x = c3_q[0] + c3_q[1];
  c3_pq_x = c3_oq_x;
  c3_pq_x = muDoubleScalarCos(c3_pq_x);
  c3_wg_a = c3_b_m;
  c3_ck_b = c3_pq_x;
  c3_bm_y = c3_wg_a * c3_ck_b;
  c3_xg_a = c3_bm_y;
  c3_dk_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_cm_y = c3_xg_a * c3_dk_b;
  c3_qq_x = c3_q[0] + c3_q[1];
  c3_rq_x = c3_qq_x;
  c3_rq_x = muDoubleScalarSin(c3_rq_x);
  c3_sq_x = c3_q[0];
  c3_tq_x = c3_sq_x;
  c3_tq_x = muDoubleScalarSin(c3_tq_x);
  c3_ek_b = c3_tq_x;
  c3_dm_y = 2.0 * c3_ek_b;
  c3_yg_a = c3_cm_y;
  c3_fk_b = c3_rq_x + c3_dm_y;
  c3_em_y = c3_yg_a * c3_fk_b;
  c3_yb_A = c3_em_y;
  c3_uq_x = c3_yb_A;
  c3_vq_x = c3_uq_x;
  c3_fm_y = c3_vq_x / 8.0;
  c3_wq_x = c3_q[0] + c3_q[1];
  c3_xq_x = c3_wq_x;
  c3_xq_x = muDoubleScalarSin(c3_xq_x);
  c3_ah_a = c3_b_m;
  c3_gk_b = c3_xq_x;
  c3_gm_y = c3_ah_a * c3_gk_b;
  c3_bh_a = c3_gm_y;
  c3_hk_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_hm_y = c3_bh_a * c3_hk_b;
  c3_yq_x = c3_q[0] + c3_q[1];
  c3_ar_x = c3_yq_x;
  c3_ar_x = muDoubleScalarCos(c3_ar_x);
  c3_ch_a = c3_ar_x;
  c3_ik_b = c3_q_dot[0] + c3_q_dot[1];
  c3_im_y = c3_ch_a * c3_ik_b;
  c3_jk_b = c3_q_dot[0];
  c3_jm_y = 2.0 * c3_jk_b;
  c3_br_x = c3_q[0];
  c3_cr_x = c3_br_x;
  c3_cr_x = muDoubleScalarCos(c3_cr_x);
  c3_dh_a = c3_jm_y;
  c3_kk_b = c3_cr_x;
  c3_km_y = c3_dh_a * c3_kk_b;
  c3_eh_a = c3_hm_y;
  c3_lk_b = c3_im_y + c3_km_y;
  c3_lm_y = c3_eh_a * c3_lk_b;
  c3_ac_A = c3_lm_y;
  c3_dr_x = c3_ac_A;
  c3_er_x = c3_dr_x;
  c3_mm_y = c3_er_x / 8.0;
  c3_fr_x = c3_q[0] + c3_q[1];
  c3_gr_x = c3_fr_x;
  c3_gr_x = muDoubleScalarCos(c3_gr_x);
  c3_fh_a = c3_b_m;
  c3_mk_b = c3_gr_x;
  c3_nm_y = c3_fh_a * c3_mk_b;
  c3_gh_a = c3_nm_y;
  c3_nk_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_om_y = c3_gh_a * c3_nk_b;
  c3_hr_x = c3_q[0] + c3_q[1];
  c3_ir_x = c3_hr_x;
  c3_ir_x = muDoubleScalarSin(c3_ir_x);
  c3_hh_a = c3_ir_x;
  c3_ok_b = c3_q_dot[0] + c3_q_dot[1];
  c3_pm_y = c3_hh_a * c3_ok_b;
  c3_pk_b = c3_q_dot[0];
  c3_qm_y = 2.0 * c3_pk_b;
  c3_jr_x = c3_q[0];
  c3_kr_x = c3_jr_x;
  c3_kr_x = muDoubleScalarSin(c3_kr_x);
  c3_ih_a = c3_qm_y;
  c3_qk_b = c3_kr_x;
  c3_rm_y = c3_ih_a * c3_qk_b;
  c3_jh_a = c3_om_y;
  c3_rk_b = c3_pm_y + c3_rm_y;
  c3_sm_y = c3_jh_a * c3_rk_b;
  c3_bc_A = c3_sm_y;
  c3_lr_x = c3_bc_A;
  c3_mr_x = c3_lr_x;
  c3_tm_y = c3_mr_x / 8.0;
  c3_kh_a = c3_b_m;
  c3_sk_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_um_y = c3_kh_a * c3_sk_b;
  c3_nr_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_or_x = c3_nr_x;
  c3_or_x = muDoubleScalarSin(c3_or_x);
  c3_pr_x = c3_q[0] + c3_q[1];
  c3_qr_x = c3_pr_x;
  c3_qr_x = muDoubleScalarSin(c3_qr_x);
  c3_tk_b = c3_qr_x;
  c3_vm_y = 2.0 * c3_tk_b;
  c3_lh_a = c3_um_y;
  c3_uk_b = c3_or_x + c3_vm_y;
  c3_wm_y = c3_lh_a * c3_uk_b;
  c3_rr_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_sr_x = c3_rr_x;
  c3_sr_x = muDoubleScalarCos(c3_sr_x);
  c3_mh_a = c3_sr_x;
  c3_vk_b = (c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2];
  c3_xm_y = c3_mh_a * c3_vk_b;
  c3_tr_x = c3_q[0] + c3_q[1];
  c3_ur_x = c3_tr_x;
  c3_ur_x = muDoubleScalarCos(c3_ur_x);
  c3_wk_b = c3_ur_x;
  c3_ym_y = 2.0 * c3_wk_b;
  c3_nh_a = c3_ym_y;
  c3_xk_b = c3_q_dot[0] + c3_q_dot[1];
  c3_an_y = c3_nh_a * c3_xk_b;
  c3_yk_b = c3_q_dot[0];
  c3_bn_y = 2.0 * c3_yk_b;
  c3_vr_x = c3_q[0];
  c3_wr_x = c3_vr_x;
  c3_wr_x = muDoubleScalarCos(c3_wr_x);
  c3_oh_a = c3_bn_y;
  c3_al_b = c3_wr_x;
  c3_cn_y = c3_oh_a * c3_al_b;
  c3_ph_a = c3_wm_y;
  c3_bl_b = (c3_xm_y + c3_an_y) + c3_cn_y;
  c3_dn_y = c3_ph_a * c3_bl_b;
  c3_cc_A = c3_dn_y;
  c3_xr_x = c3_cc_A;
  c3_yr_x = c3_xr_x;
  c3_en_y = c3_yr_x / 8.0;
  c3_as_x = c3_q[0] + c3_q[1];
  c3_bs_x = c3_as_x;
  c3_bs_x = muDoubleScalarSin(c3_bs_x);
  c3_qh_a = c3_b_m;
  c3_cl_b = c3_bs_x;
  c3_fn_y = c3_qh_a * c3_cl_b;
  c3_rh_a = c3_fn_y;
  c3_dl_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_gn_y = c3_rh_a * c3_dl_b;
  c3_sh_a = c3_gn_y;
  c3_el_b = c3_q_dot[0] + c3_q_dot[1];
  c3_hn_y = c3_sh_a * c3_el_b;
  c3_cs_x = c3_q[0] + c3_q[1];
  c3_ds_x = c3_cs_x;
  c3_ds_x = muDoubleScalarCos(c3_ds_x);
  c3_es_x = c3_q[0];
  c3_fs_x = c3_es_x;
  c3_fs_x = muDoubleScalarCos(c3_fs_x);
  c3_fl_b = c3_fs_x;
  c3_in_y = 2.0 * c3_fl_b;
  c3_th_a = c3_hn_y;
  c3_gl_b = c3_ds_x + c3_in_y;
  c3_jn_y = c3_th_a * c3_gl_b;
  c3_dc_A = c3_jn_y;
  c3_gs_x = c3_dc_A;
  c3_hs_x = c3_gs_x;
  c3_kn_y = c3_hs_x / 8.0;
  c3_is_x = c3_q[0] + c3_q[1];
  c3_js_x = c3_is_x;
  c3_js_x = muDoubleScalarCos(c3_js_x);
  c3_uh_a = c3_b_m;
  c3_hl_b = c3_js_x;
  c3_ln_y = c3_uh_a * c3_hl_b;
  c3_vh_a = c3_ln_y;
  c3_il_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_mn_y = c3_vh_a * c3_il_b;
  c3_wh_a = c3_mn_y;
  c3_jl_b = c3_q_dot[0] + c3_q_dot[1];
  c3_nn_y = c3_wh_a * c3_jl_b;
  c3_ks_x = c3_q[0] + c3_q[1];
  c3_ls_x = c3_ks_x;
  c3_ls_x = muDoubleScalarSin(c3_ls_x);
  c3_ms_x = c3_q[0];
  c3_ns_x = c3_ms_x;
  c3_ns_x = muDoubleScalarSin(c3_ns_x);
  c3_kl_b = c3_ns_x;
  c3_on_y = 2.0 * c3_kl_b;
  c3_xh_a = c3_nn_y;
  c3_ll_b = c3_ls_x + c3_on_y;
  c3_pn_y = c3_xh_a * c3_ll_b;
  c3_ec_A = c3_pn_y;
  c3_os_x = c3_ec_A;
  c3_ps_x = c3_os_x;
  c3_qn_y = c3_ps_x / 8.0;
  c3_qs_x = c3_q[0] + c3_q[1];
  c3_rs_x = c3_qs_x;
  c3_rs_x = muDoubleScalarSin(c3_rs_x);
  c3_yh_a = c3_b_m;
  c3_ml_b = c3_rs_x;
  c3_rn_y = c3_yh_a * c3_ml_b;
  c3_ss_x = c3_q[0] + c3_q[1];
  c3_ts_x = c3_ss_x;
  c3_ts_x = muDoubleScalarCos(c3_ts_x);
  c3_ai_a = c3_rn_y;
  c3_nl_b = c3_ts_x;
  c3_sn_y = c3_ai_a * c3_nl_b;
  c3_bi_a = c3_sn_y;
  c3_ol_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_tn_y = c3_bi_a * c3_ol_b;
  c3_fc_A = c3_tn_y;
  c3_us_x = c3_fc_A;
  c3_vs_x = c3_us_x;
  c3_un_y = c3_vs_x / 4.0;
  c3_ws_x = c3_q[0] + c3_q[1];
  c3_xs_x = c3_ws_x;
  c3_xs_x = muDoubleScalarCos(c3_xs_x);
  c3_ci_a = c3_b_m;
  c3_pl_b = c3_xs_x;
  c3_vn_y = c3_ci_a * c3_pl_b;
  c3_ys_x = c3_q[0] + c3_q[1];
  c3_at_x = c3_ys_x;
  c3_at_x = muDoubleScalarSin(c3_at_x);
  c3_di_a = c3_vn_y;
  c3_ql_b = c3_at_x;
  c3_wn_y = c3_di_a * c3_ql_b;
  c3_ei_a = c3_wn_y;
  c3_rl_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_xn_y = c3_ei_a * c3_rl_b;
  c3_gc_A = c3_xn_y;
  c3_bt_x = c3_gc_A;
  c3_ct_x = c3_bt_x;
  c3_yn_y = c3_ct_x / 4.0;
  c3_fi_a = c3_b_m;
  c3_sl_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_ao_y = c3_fi_a * c3_sl_b;
  c3_dt_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_et_x = c3_dt_x;
  c3_et_x = muDoubleScalarSin(c3_et_x);
  c3_ft_x = c3_q[0] + c3_q[1];
  c3_gt_x = c3_ft_x;
  c3_gt_x = muDoubleScalarSin(c3_gt_x);
  c3_tl_b = c3_gt_x;
  c3_bo_y = 2.0 * c3_tl_b;
  c3_gi_a = c3_ao_y;
  c3_ul_b = c3_et_x + c3_bo_y;
  c3_co_y = c3_gi_a * c3_ul_b;
  c3_ht_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_it_x = c3_ht_x;
  c3_it_x = muDoubleScalarCos(c3_it_x);
  c3_jt_x = c3_q[0] + c3_q[1];
  c3_kt_x = c3_jt_x;
  c3_kt_x = muDoubleScalarCos(c3_kt_x);
  c3_vl_b = c3_kt_x;
  c3_do_y = 2.0 * c3_vl_b;
  c3_lt_x = c3_q[0];
  c3_mt_x = c3_lt_x;
  c3_mt_x = muDoubleScalarCos(c3_mt_x);
  c3_wl_b = c3_mt_x;
  c3_eo_y = 2.0 * c3_wl_b;
  c3_hi_a = c3_co_y;
  c3_xl_b = (c3_it_x + c3_do_y) + c3_eo_y;
  c3_fo_y = c3_hi_a * c3_xl_b;
  c3_hc_A = c3_fo_y;
  c3_nt_x = c3_hc_A;
  c3_ot_x = c3_nt_x;
  c3_go_y = c3_ot_x / 4.0;
  c3_ii_a = c3_b_m;
  c3_yl_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_ho_y = c3_ii_a * c3_yl_b;
  c3_pt_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_qt_x = c3_pt_x;
  c3_qt_x = muDoubleScalarCos(c3_qt_x);
  c3_rt_x = c3_q[0] + c3_q[1];
  c3_st_x = c3_rt_x;
  c3_st_x = muDoubleScalarCos(c3_st_x);
  c3_am_b = c3_st_x;
  c3_io_y = 2.0 * c3_am_b;
  c3_ji_a = c3_ho_y;
  c3_bm_b = c3_qt_x + c3_io_y;
  c3_jo_y = c3_ji_a * c3_bm_b;
  c3_tt_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_ut_x = c3_tt_x;
  c3_ut_x = muDoubleScalarSin(c3_ut_x);
  c3_vt_x = c3_q[0] + c3_q[1];
  c3_wt_x = c3_vt_x;
  c3_wt_x = muDoubleScalarSin(c3_wt_x);
  c3_cm_b = c3_wt_x;
  c3_ko_y = 2.0 * c3_cm_b;
  c3_xt_x = c3_q[0];
  c3_yt_x = c3_xt_x;
  c3_yt_x = muDoubleScalarSin(c3_yt_x);
  c3_dm_b = c3_yt_x;
  c3_lo_y = 2.0 * c3_dm_b;
  c3_ki_a = c3_jo_y;
  c3_em_b = (c3_ut_x + c3_ko_y) + c3_lo_y;
  c3_mo_y = c3_ki_a * c3_em_b;
  c3_ic_A = c3_mo_y;
  c3_au_x = c3_ic_A;
  c3_bu_x = c3_au_x;
  c3_no_y = c3_bu_x / 4.0;
  c3_li_a = c3_b_m;
  c3_fm_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_oo_y = c3_li_a * c3_fm_b;
  c3_cu_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_du_x = c3_cu_x;
  c3_du_x = muDoubleScalarCos(c3_du_x);
  c3_eu_x = c3_q[0] + c3_q[1];
  c3_fu_x = c3_eu_x;
  c3_fu_x = muDoubleScalarCos(c3_fu_x);
  c3_gm_b = c3_fu_x;
  c3_po_y = 2.0 * c3_gm_b;
  c3_mi_a = c3_oo_y;
  c3_hm_b = c3_du_x + c3_po_y;
  c3_qo_y = c3_mi_a * c3_hm_b;
  c3_gu_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_hu_x = c3_gu_x;
  c3_hu_x = muDoubleScalarSin(c3_hu_x);
  c3_ni_a = c3_hu_x;
  c3_im_b = (c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2];
  c3_ro_y = c3_ni_a * c3_im_b;
  c3_iu_x = c3_q[0] + c3_q[1];
  c3_ju_x = c3_iu_x;
  c3_ju_x = muDoubleScalarSin(c3_ju_x);
  c3_jm_b = c3_ju_x;
  c3_so_y = 2.0 * c3_jm_b;
  c3_oi_a = c3_so_y;
  c3_km_b = c3_q_dot[0] + c3_q_dot[1];
  c3_to_y = c3_oi_a * c3_km_b;
  c3_pi_a = c3_qo_y;
  c3_lm_b = c3_ro_y + c3_to_y;
  c3_uo_y = c3_pi_a * c3_lm_b;
  c3_jc_A = c3_uo_y;
  c3_ku_x = c3_jc_A;
  c3_lu_x = c3_ku_x;
  c3_vo_y = c3_lu_x / 8.0;
  c3_qi_a = c3_b_m;
  c3_mm_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_wo_y = c3_qi_a * c3_mm_b;
  c3_mu_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_nu_x = c3_mu_x;
  c3_nu_x = muDoubleScalarSin(c3_nu_x);
  c3_ou_x = c3_q[0] + c3_q[1];
  c3_pu_x = c3_ou_x;
  c3_pu_x = muDoubleScalarSin(c3_pu_x);
  c3_nm_b = c3_pu_x;
  c3_xo_y = 2.0 * c3_nm_b;
  c3_ri_a = c3_wo_y;
  c3_om_b = c3_nu_x + c3_xo_y;
  c3_yo_y = c3_ri_a * c3_om_b;
  c3_qu_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_ru_x = c3_qu_x;
  c3_ru_x = muDoubleScalarCos(c3_ru_x);
  c3_si_a = c3_ru_x;
  c3_pm_b = (c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2];
  c3_ap_y = c3_si_a * c3_pm_b;
  c3_su_x = c3_q[0] + c3_q[1];
  c3_tu_x = c3_su_x;
  c3_tu_x = muDoubleScalarCos(c3_tu_x);
  c3_qm_b = c3_tu_x;
  c3_bp_y = 2.0 * c3_qm_b;
  c3_ti_a = c3_bp_y;
  c3_rm_b = c3_q_dot[0] + c3_q_dot[1];
  c3_cp_y = c3_ti_a * c3_rm_b;
  c3_ui_a = c3_yo_y;
  c3_sm_b = c3_ap_y + c3_cp_y;
  c3_dp_y = c3_ui_a * c3_sm_b;
  c3_kc_A = c3_dp_y;
  c3_uu_x = c3_kc_A;
  c3_vu_x = c3_uu_x;
  c3_ep_y = c3_vu_x / 8.0;
  c3_vi_a = c3_b_m;
  c3_tm_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_fp_y = c3_vi_a * c3_tm_b;
  c3_wu_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_xu_x = c3_wu_x;
  c3_xu_x = muDoubleScalarCos(c3_xu_x);
  c3_yu_x = c3_q[0] + c3_q[1];
  c3_av_x = c3_yu_x;
  c3_av_x = muDoubleScalarCos(c3_av_x);
  c3_um_b = c3_av_x;
  c3_gp_y = 2.0 * c3_um_b;
  c3_wi_a = c3_fp_y;
  c3_vm_b = c3_xu_x + c3_gp_y;
  c3_hp_y = c3_wi_a * c3_vm_b;
  c3_bv_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_cv_x = c3_bv_x;
  c3_cv_x = muDoubleScalarSin(c3_cv_x);
  c3_xi_a = c3_cv_x;
  c3_wm_b = (c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2];
  c3_ip_y = c3_xi_a * c3_wm_b;
  c3_dv_x = c3_q[0] + c3_q[1];
  c3_ev_x = c3_dv_x;
  c3_ev_x = muDoubleScalarSin(c3_ev_x);
  c3_xm_b = c3_ev_x;
  c3_jp_y = 2.0 * c3_xm_b;
  c3_yi_a = c3_jp_y;
  c3_ym_b = c3_q_dot[0] + c3_q_dot[1];
  c3_kp_y = c3_yi_a * c3_ym_b;
  c3_aj_a = c3_hp_y;
  c3_an_b = c3_ip_y + c3_kp_y;
  c3_lp_y = c3_aj_a * c3_an_b;
  c3_lc_A = c3_lp_y;
  c3_fv_x = c3_lc_A;
  c3_gv_x = c3_fv_x;
  c3_mp_y = c3_gv_x / 8.0;
  c3_bj_a = c3_b_m;
  c3_bn_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_np_y = c3_bj_a * c3_bn_b;
  c3_hv_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_iv_x = c3_hv_x;
  c3_iv_x = muDoubleScalarSin(c3_iv_x);
  c3_jv_x = c3_q[0] + c3_q[1];
  c3_kv_x = c3_jv_x;
  c3_kv_x = muDoubleScalarSin(c3_kv_x);
  c3_cn_b = c3_kv_x;
  c3_op_y = 2.0 * c3_cn_b;
  c3_cj_a = c3_np_y;
  c3_dn_b = c3_iv_x + c3_op_y;
  c3_pp_y = c3_cj_a * c3_dn_b;
  c3_lv_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_mv_x = c3_lv_x;
  c3_mv_x = muDoubleScalarCos(c3_mv_x);
  c3_dj_a = c3_mv_x;
  c3_en_b = (c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2];
  c3_qp_y = c3_dj_a * c3_en_b;
  c3_nv_x = c3_q[0] + c3_q[1];
  c3_ov_x = c3_nv_x;
  c3_ov_x = muDoubleScalarCos(c3_ov_x);
  c3_fn_b = c3_ov_x;
  c3_rp_y = 2.0 * c3_fn_b;
  c3_ej_a = c3_rp_y;
  c3_gn_b = c3_q_dot[0] + c3_q_dot[1];
  c3_sp_y = c3_ej_a * c3_gn_b;
  c3_fj_a = c3_pp_y;
  c3_hn_b = c3_qp_y + c3_sp_y;
  c3_tp_y = c3_fj_a * c3_hn_b;
  c3_mc_A = c3_tp_y;
  c3_pv_x = c3_mc_A;
  c3_qv_x = c3_pv_x;
  c3_up_y = c3_qv_x / 8.0;
  c3_rv_x = c3_q[0] + c3_q[1];
  c3_sv_x = c3_rv_x;
  c3_sv_x = muDoubleScalarSin(c3_sv_x);
  c3_gj_a = c3_b_m;
  c3_in_b = c3_sv_x;
  c3_vp_y = c3_gj_a * c3_in_b;
  c3_hj_a = c3_vp_y;
  c3_jn_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_wp_y = c3_hj_a * c3_jn_b;
  c3_tv_x = c3_q[0] + c3_q[1];
  c3_uv_x = c3_tv_x;
  c3_uv_x = muDoubleScalarCos(c3_uv_x);
  c3_vv_x = c3_q[0];
  c3_wv_x = c3_vv_x;
  c3_wv_x = muDoubleScalarCos(c3_wv_x);
  c3_kn_b = c3_wv_x;
  c3_xp_y = 2.0 * c3_kn_b;
  c3_ij_a = c3_wp_y;
  c3_ln_b = c3_uv_x + c3_xp_y;
  c3_yp_y = c3_ij_a * c3_ln_b;
  c3_nc_A = c3_yp_y;
  c3_xv_x = c3_nc_A;
  c3_yv_x = c3_xv_x;
  c3_aq_y = c3_yv_x / 4.0;
  c3_aw_x = c3_q[0] + c3_q[1];
  c3_bw_x = c3_aw_x;
  c3_bw_x = muDoubleScalarCos(c3_bw_x);
  c3_jj_a = c3_b_m;
  c3_mn_b = c3_bw_x;
  c3_bq_y = c3_jj_a * c3_mn_b;
  c3_kj_a = c3_bq_y;
  c3_nn_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_cq_y = c3_kj_a * c3_nn_b;
  c3_cw_x = c3_q[0] + c3_q[1];
  c3_dw_x = c3_cw_x;
  c3_dw_x = muDoubleScalarSin(c3_dw_x);
  c3_ew_x = c3_q[0];
  c3_fw_x = c3_ew_x;
  c3_fw_x = muDoubleScalarSin(c3_fw_x);
  c3_on_b = c3_fw_x;
  c3_dq_y = 2.0 * c3_on_b;
  c3_lj_a = c3_cq_y;
  c3_pn_b = c3_dw_x + c3_dq_y;
  c3_eq_y = c3_lj_a * c3_pn_b;
  c3_oc_A = c3_eq_y;
  c3_gw_x = c3_oc_A;
  c3_hw_x = c3_gw_x;
  c3_fq_y = c3_hw_x / 4.0;
  c3_mj_a = c3_b_m;
  c3_qn_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_gq_y = c3_mj_a * c3_qn_b;
  c3_iw_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_jw_x = c3_iw_x;
  c3_jw_x = muDoubleScalarCos(c3_jw_x);
  c3_kw_x = c3_q[0] + c3_q[1];
  c3_lw_x = c3_kw_x;
  c3_lw_x = muDoubleScalarCos(c3_lw_x);
  c3_rn_b = c3_lw_x;
  c3_hq_y = 2.0 * c3_rn_b;
  c3_nj_a = c3_gq_y;
  c3_sn_b = c3_jw_x + c3_hq_y;
  c3_iq_y = c3_nj_a * c3_sn_b;
  c3_mw_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_nw_x = c3_mw_x;
  c3_nw_x = muDoubleScalarSin(c3_nw_x);
  c3_ow_x = c3_q[0] + c3_q[1];
  c3_pw_x = c3_ow_x;
  c3_pw_x = muDoubleScalarSin(c3_pw_x);
  c3_tn_b = c3_pw_x;
  c3_jq_y = 2.0 * c3_tn_b;
  c3_oj_a = c3_iq_y;
  c3_un_b = c3_nw_x + c3_jq_y;
  c3_kq_y = c3_oj_a * c3_un_b;
  c3_pc_A = c3_kq_y;
  c3_qw_x = c3_pc_A;
  c3_rw_x = c3_qw_x;
  c3_lq_y = c3_rw_x / 4.0;
  c3_pj_a = c3_b_m;
  c3_vn_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_mq_y = c3_pj_a * c3_vn_b;
  c3_sw_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_tw_x = c3_sw_x;
  c3_tw_x = muDoubleScalarCos(c3_tw_x);
  c3_uw_x = c3_q[0] + c3_q[1];
  c3_vw_x = c3_uw_x;
  c3_vw_x = muDoubleScalarCos(c3_vw_x);
  c3_wn_b = c3_vw_x;
  c3_nq_y = 2.0 * c3_wn_b;
  c3_qj_a = c3_mq_y;
  c3_xn_b = c3_tw_x + c3_nq_y;
  c3_oq_y = c3_qj_a * c3_xn_b;
  c3_ww_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_xw_x = c3_ww_x;
  c3_xw_x = muDoubleScalarSin(c3_xw_x);
  c3_yw_x = c3_q[0] + c3_q[1];
  c3_ax_x = c3_yw_x;
  c3_ax_x = muDoubleScalarSin(c3_ax_x);
  c3_yn_b = c3_ax_x;
  c3_pq_y = 2.0 * c3_yn_b;
  c3_rj_a = c3_oq_y;
  c3_ao_b = c3_xw_x + c3_pq_y;
  c3_qq_y = c3_rj_a * c3_ao_b;
  c3_qc_A = c3_qq_y;
  c3_bx_x = c3_qc_A;
  c3_cx_x = c3_bx_x;
  c3_rq_y = c3_cx_x / 4.0;
  c3_dx_x = c3_q[0] + c3_q[1];
  c3_ex_x = c3_dx_x;
  c3_ex_x = muDoubleScalarCos(c3_ex_x);
  c3_sj_a = c3_b_m;
  c3_bo_b = c3_ex_x;
  c3_sq_y = c3_sj_a * c3_bo_b;
  c3_fx_x = c3_q[0] + c3_q[1];
  c3_gx_x = c3_fx_x;
  c3_gx_x = muDoubleScalarSin(c3_gx_x);
  c3_tj_a = c3_sq_y;
  c3_co_b = c3_gx_x;
  c3_tq_y = c3_tj_a * c3_co_b;
  c3_uj_a = c3_tq_y;
  c3_do_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_uq_y = c3_uj_a * c3_do_b;
  c3_vj_a = c3_uq_y;
  c3_eo_b = c3_q_dot[0] + c3_q_dot[1];
  c3_vq_y = c3_vj_a * c3_eo_b;
  c3_rc_A = c3_vq_y;
  c3_hx_x = c3_rc_A;
  c3_ix_x = c3_hx_x;
  c3_wq_y = c3_ix_x / 8.0;
  c3_jx_x = c3_q[0] + c3_q[1];
  c3_kx_x = c3_jx_x;
  c3_kx_x = muDoubleScalarSin(c3_kx_x);
  c3_wj_a = c3_b_m;
  c3_fo_b = c3_kx_x;
  c3_xq_y = c3_wj_a * c3_fo_b;
  c3_lx_x = c3_q[0] + c3_q[1];
  c3_mx_x = c3_lx_x;
  c3_mx_x = muDoubleScalarCos(c3_mx_x);
  c3_xj_a = c3_xq_y;
  c3_go_b = c3_mx_x;
  c3_yq_y = c3_xj_a * c3_go_b;
  c3_yj_a = c3_yq_y;
  c3_ho_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_ar_y = c3_yj_a * c3_ho_b;
  c3_ak_a = c3_ar_y;
  c3_io_b = c3_q_dot[0] + c3_q_dot[1];
  c3_br_y = c3_ak_a * c3_io_b;
  c3_sc_A = c3_br_y;
  c3_nx_x = c3_sc_A;
  c3_ox_x = c3_nx_x;
  c3_cr_y = c3_ox_x / 8.0;
  c3_px_x = c3_q[0] + c3_q[1];
  c3_qx_x = c3_px_x;
  c3_qx_x = muDoubleScalarCos(c3_qx_x);
  c3_bk_a = c3_b_m;
  c3_jo_b = c3_qx_x;
  c3_dr_y = c3_bk_a * c3_jo_b;
  c3_rx_x = c3_q[0] + c3_q[1];
  c3_sx_x = c3_rx_x;
  c3_sx_x = muDoubleScalarSin(c3_sx_x);
  c3_ck_a = c3_dr_y;
  c3_ko_b = c3_sx_x;
  c3_er_y = c3_ck_a * c3_ko_b;
  c3_dk_a = c3_er_y;
  c3_lo_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_fr_y = c3_dk_a * c3_lo_b;
  c3_ek_a = c3_fr_y;
  c3_mo_b = c3_q_dot[0] + c3_q_dot[1];
  c3_gr_y = c3_ek_a * c3_mo_b;
  c3_tc_A = c3_gr_y;
  c3_tx_x = c3_tc_A;
  c3_ux_x = c3_tx_x;
  c3_hr_y = c3_ux_x / 8.0;
  c3_vx_x = c3_q[0] + c3_q[1];
  c3_wx_x = c3_vx_x;
  c3_wx_x = muDoubleScalarSin(c3_wx_x);
  c3_fk_a = c3_b_m;
  c3_no_b = c3_wx_x;
  c3_ir_y = c3_fk_a * c3_no_b;
  c3_xx_x = c3_q[0] + c3_q[1];
  c3_yx_x = c3_xx_x;
  c3_yx_x = muDoubleScalarCos(c3_yx_x);
  c3_gk_a = c3_ir_y;
  c3_oo_b = c3_yx_x;
  c3_jr_y = c3_gk_a * c3_oo_b;
  c3_hk_a = c3_jr_y;
  c3_po_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_kr_y = c3_hk_a * c3_po_b;
  c3_ik_a = c3_kr_y;
  c3_qo_b = c3_q_dot[0] + c3_q_dot[1];
  c3_lr_y = c3_ik_a * c3_qo_b;
  c3_uc_A = c3_lr_y;
  c3_ay_x = c3_uc_A;
  c3_by_x = c3_ay_x;
  c3_mr_y = c3_by_x / 8.0;
  c3_jk_a = c3_b_m;
  c3_ro_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_nr_y = c3_jk_a * c3_ro_b;
  c3_cy_x = (((c3_q[0] - c3_q[1]) - c3_q[2]) - c3_q[0]) + c3_q[1];
  c3_dy_x = c3_cy_x;
  c3_dy_x = muDoubleScalarSin(c3_dy_x);
  c3_so_b = c3_dy_x;
  c3_or_y = 2.0 * c3_so_b;
  c3_kk_a = c3_or_y;
  c3_to_b = (((c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2]) - c3_q_dot[0]) -
    c3_q_dot[1];
  c3_pr_y = c3_kk_a * c3_to_b;
  c3_ey_x = ((((c3_q[0] - c3_q[1]) - c3_q[2]) - c3_q[0]) + c3_q[1]) + c3_q[2];
  c3_fy_x = c3_ey_x;
  c3_fy_x = muDoubleScalarSin(c3_fy_x);
  c3_lk_a = c3_fy_x;
  c3_uo_b = ((((c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2]) - c3_q_dot[0]) -
             c3_q_dot[1]) - c3_q_dot[2];
  c3_qr_y = c3_lk_a * c3_uo_b;
  c3_mk_a = c3_nr_y;
  c3_vo_b = c3_pr_y + c3_qr_y;
  c3_rr_y = c3_mk_a * c3_vo_b;
  c3_vc_A = c3_rr_y;
  c3_gy_x = c3_vc_A;
  c3_hy_x = c3_gy_x;
  c3_sr_y = c3_hy_x / 8.0;
  c3_nk_a = c3_b_m;
  c3_wo_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_tr_y = c3_nk_a * c3_wo_b;
  c3_iy_x = (((c3_q[0] - c3_q[1]) - c3_q[2]) - c3_q[0]) + c3_q[1];
  c3_jy_x = c3_iy_x;
  c3_jy_x = muDoubleScalarSin(c3_jy_x);
  c3_ok_a = c3_tr_y;
  c3_xo_b = c3_jy_x;
  c3_ur_y = c3_ok_a * c3_xo_b;
  c3_wc_A = c3_ur_y;
  c3_ky_x = c3_wc_A;
  c3_ly_x = c3_ky_x;
  c3_vr_y = c3_ly_x / 4.0;
  c3_my_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_ny_x = c3_my_x;
  c3_ny_x = muDoubleScalarCos(c3_ny_x);
  c3_pk_a = c3_b_m;
  c3_yo_b = c3_ny_x;
  c3_wr_y = c3_pk_a * c3_yo_b;
  c3_qk_a = c3_wr_y;
  c3_ap_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_xr_y = c3_qk_a * c3_ap_b;
  c3_oy_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_py_x = c3_oy_x;
  c3_py_x = muDoubleScalarSin(c3_py_x);
  c3_qy_x = c3_q[0] + c3_q[1];
  c3_ry_x = c3_qy_x;
  c3_ry_x = muDoubleScalarSin(c3_ry_x);
  c3_bp_b = c3_ry_x;
  c3_yr_y = 2.0 * c3_bp_b;
  c3_sy_x = c3_q[0];
  c3_ty_x = c3_sy_x;
  c3_ty_x = muDoubleScalarSin(c3_ty_x);
  c3_cp_b = c3_ty_x;
  c3_as_y = 2.0 * c3_cp_b;
  c3_rk_a = c3_xr_y;
  c3_dp_b = (c3_py_x + c3_yr_y) + c3_as_y;
  c3_bs_y = c3_rk_a * c3_dp_b;
  c3_xc_A = c3_bs_y;
  c3_uy_x = c3_xc_A;
  c3_vy_x = c3_uy_x;
  c3_cs_y = c3_vy_x / 4.0;
  c3_wy_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_xy_x = c3_wy_x;
  c3_xy_x = muDoubleScalarSin(c3_xy_x);
  c3_sk_a = c3_b_m;
  c3_ep_b = c3_xy_x;
  c3_ds_y = c3_sk_a * c3_ep_b;
  c3_tk_a = c3_ds_y;
  c3_fp_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_es_y = c3_tk_a * c3_fp_b;
  c3_yy_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_aab_x = c3_yy_x;
  c3_aab_x = muDoubleScalarCos(c3_aab_x);
  c3_bab_x = c3_q[0] + c3_q[1];
  c3_cab_x = c3_bab_x;
  c3_cab_x = muDoubleScalarCos(c3_cab_x);
  c3_gp_b = c3_cab_x;
  c3_fs_y = 2.0 * c3_gp_b;
  c3_uk_a = c3_es_y;
  c3_hp_b = c3_aab_x + c3_fs_y;
  c3_gs_y = c3_uk_a * c3_hp_b;
  c3_yc_A = c3_gs_y;
  c3_dab_x = c3_yc_A;
  c3_eab_x = c3_dab_x;
  c3_hs_y = c3_eab_x / 4.0;
  c3_fab_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_gab_x = c3_fab_x;
  c3_gab_x = muDoubleScalarCos(c3_gab_x);
  c3_vk_a = c3_b_m;
  c3_ip_b = c3_gab_x;
  c3_is_y = c3_vk_a * c3_ip_b;
  c3_wk_a = c3_is_y;
  c3_jp_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_js_y = c3_wk_a * c3_jp_b;
  c3_hab_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_iab_x = c3_hab_x;
  c3_iab_x = muDoubleScalarSin(c3_iab_x);
  c3_jab_x = c3_q[0] + c3_q[1];
  c3_kab_x = c3_jab_x;
  c3_kab_x = muDoubleScalarSin(c3_kab_x);
  c3_kp_b = c3_kab_x;
  c3_ks_y = 2.0 * c3_kp_b;
  c3_xk_a = c3_js_y;
  c3_lp_b = c3_iab_x + c3_ks_y;
  c3_ls_y = c3_xk_a * c3_lp_b;
  c3_ad_A = c3_ls_y;
  c3_lab_x = c3_ad_A;
  c3_mab_x = c3_lab_x;
  c3_ms_y = c3_mab_x / 4.0;
  c3_nab_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_oab_x = c3_nab_x;
  c3_oab_x = muDoubleScalarSin(c3_oab_x);
  c3_yk_a = c3_b_m;
  c3_mp_b = c3_oab_x;
  c3_ns_y = c3_yk_a * c3_mp_b;
  c3_al_a = c3_ns_y;
  c3_np_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_os_y = c3_al_a * c3_np_b;
  c3_pab_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_qab_x = c3_pab_x;
  c3_qab_x = muDoubleScalarCos(c3_qab_x);
  c3_rab_x = c3_q[0] + c3_q[1];
  c3_sab_x = c3_rab_x;
  c3_sab_x = muDoubleScalarCos(c3_sab_x);
  c3_op_b = c3_sab_x;
  c3_ps_y = 2.0 * c3_op_b;
  c3_tab_x = c3_q[0];
  c3_uab_x = c3_tab_x;
  c3_uab_x = muDoubleScalarCos(c3_uab_x);
  c3_pp_b = c3_uab_x;
  c3_qs_y = 2.0 * c3_pp_b;
  c3_bl_a = c3_os_y;
  c3_qp_b = (c3_qab_x + c3_ps_y) + c3_qs_y;
  c3_rs_y = c3_bl_a * c3_qp_b;
  c3_bd_A = c3_rs_y;
  c3_vab_x = c3_bd_A;
  c3_wab_x = c3_vab_x;
  c3_ss_y = c3_wab_x / 4.0;
  c3_xab_x = ((c3_q[0] - c3_q[1]) - c3_q[2]) - c3_q[0];
  c3_yab_x = c3_xab_x;
  c3_yab_x = muDoubleScalarSin(c3_yab_x);
  c3_cl_a = c3_b_m;
  c3_rp_b = c3_yab_x;
  c3_ts_y = c3_cl_a * c3_rp_b;
  c3_dl_a = c3_ts_y;
  c3_sp_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_us_y = c3_dl_a * c3_sp_b;
  c3_cd_A = c3_us_y;
  c3_abb_x = c3_cd_A;
  c3_bbb_x = c3_abb_x;
  c3_vs_y = c3_bbb_x / 4.0;
  c3_el_a = c3_b_m;
  c3_tp_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_ws_y = c3_el_a * c3_tp_b;
  c3_cbb_x = ((c3_q[0] - c3_q[1]) - c3_q[2]) - c3_q[0];
  c3_dbb_x = c3_cbb_x;
  c3_dbb_x = muDoubleScalarSin(c3_dbb_x);
  c3_up_b = c3_dbb_x;
  c3_xs_y = 2.0 * c3_up_b;
  c3_ebb_x = (((c3_q[0] - c3_q[1]) - c3_q[2]) - c3_q[0]) + c3_q[1];
  c3_fbb_x = c3_ebb_x;
  c3_fbb_x = muDoubleScalarSin(c3_fbb_x);
  c3_vp_b = c3_fbb_x;
  c3_ys_y = 2.0 * c3_vp_b;
  c3_fl_a = c3_ws_y;
  c3_wp_b = c3_xs_y + c3_ys_y;
  c3_at_y = c3_fl_a * c3_wp_b;
  c3_dd_A = c3_at_y;
  c3_gbb_x = c3_dd_A;
  c3_hbb_x = c3_gbb_x;
  c3_bt_y = c3_hbb_x / 8.0;
  c3_gl_a = c3_b_m;
  c3_xp_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_ct_y = c3_gl_a * c3_xp_b;
  c3_ibb_x = (((c3_q[0] - c3_q[1]) - c3_q[2]) - c3_q[0]) + c3_q[1];
  c3_jbb_x = c3_ibb_x;
  c3_jbb_x = muDoubleScalarSin(c3_jbb_x);
  c3_hl_a = c3_ct_y;
  c3_yp_b = c3_jbb_x;
  c3_dt_y = c3_hl_a * c3_yp_b;
  c3_ed_A = c3_dt_y;
  c3_kbb_x = c3_ed_A;
  c3_lbb_x = c3_kbb_x;
  c3_et_y = c3_lbb_x / 4.0;
  c3_il_a = c3_b_m;
  c3_aq_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_ft_y = c3_il_a * c3_aq_b;
  c3_mbb_x = (((c3_q[0] - c3_q[1]) - c3_q[0]) + c3_q[1]) + c3_q[2];
  c3_nbb_x = c3_mbb_x;
  c3_nbb_x = muDoubleScalarSin(c3_nbb_x);
  c3_jl_a = c3_ft_y;
  c3_bq_b = c3_nbb_x;
  c3_gt_y = c3_jl_a * c3_bq_b;
  c3_fd_A = c3_gt_y;
  c3_obb_x = c3_fd_A;
  c3_pbb_x = c3_obb_x;
  c3_ht_y = c3_pbb_x / 4.0;
  c3_qbb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_rbb_x = c3_qbb_x;
  c3_rbb_x = muDoubleScalarCos(c3_rbb_x);
  c3_kl_a = c3_b_m;
  c3_cq_b = c3_rbb_x;
  c3_it_y = c3_kl_a * c3_cq_b;
  c3_ll_a = c3_it_y;
  c3_dq_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_jt_y = c3_ll_a * c3_dq_b;
  c3_sbb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_tbb_x = c3_sbb_x;
  c3_tbb_x = muDoubleScalarSin(c3_tbb_x);
  c3_ubb_x = c3_q[0] + c3_q[1];
  c3_vbb_x = c3_ubb_x;
  c3_vbb_x = muDoubleScalarSin(c3_vbb_x);
  c3_eq_b = c3_vbb_x;
  c3_kt_y = 2.0 * c3_eq_b;
  c3_wbb_x = c3_q[0];
  c3_xbb_x = c3_wbb_x;
  c3_xbb_x = muDoubleScalarSin(c3_xbb_x);
  c3_fq_b = c3_xbb_x;
  c3_lt_y = 2.0 * c3_fq_b;
  c3_ml_a = c3_jt_y;
  c3_gq_b = (c3_tbb_x + c3_kt_y) + c3_lt_y;
  c3_mt_y = c3_ml_a * c3_gq_b;
  c3_gd_A = c3_mt_y;
  c3_ybb_x = c3_gd_A;
  c3_acb_x = c3_ybb_x;
  c3_nt_y = c3_acb_x / 8.0;
  c3_bcb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_ccb_x = c3_bcb_x;
  c3_ccb_x = muDoubleScalarSin(c3_ccb_x);
  c3_nl_a = c3_b_m;
  c3_hq_b = c3_ccb_x;
  c3_ot_y = c3_nl_a * c3_hq_b;
  c3_ol_a = c3_ot_y;
  c3_iq_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_pt_y = c3_ol_a * c3_iq_b;
  c3_dcb_x = c3_q[0];
  c3_ecb_x = c3_dcb_x;
  c3_ecb_x = muDoubleScalarCos(c3_ecb_x);
  c3_jq_b = c3_ecb_x;
  c3_qt_y = 2.0 * c3_jq_b;
  c3_fcb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_gcb_x = c3_fcb_x;
  c3_gcb_x = muDoubleScalarCos(c3_gcb_x);
  c3_hcb_x = c3_q[0] + c3_q[1];
  c3_icb_x = c3_hcb_x;
  c3_icb_x = muDoubleScalarCos(c3_icb_x);
  c3_kq_b = c3_icb_x;
  c3_rt_y = 2.0 * c3_kq_b;
  c3_pl_a = c3_pt_y;
  c3_lq_b = (c3_qt_y + c3_gcb_x) + c3_rt_y;
  c3_st_y = c3_pl_a * c3_lq_b;
  c3_hd_A = c3_st_y;
  c3_jcb_x = c3_hd_A;
  c3_kcb_x = c3_jcb_x;
  c3_tt_y = c3_kcb_x / 8.0;
  c3_lcb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_mcb_x = c3_lcb_x;
  c3_mcb_x = muDoubleScalarCos(c3_mcb_x);
  c3_ql_a = c3_b_m;
  c3_mq_b = c3_mcb_x;
  c3_ut_y = c3_ql_a * c3_mq_b;
  c3_rl_a = c3_ut_y;
  c3_nq_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_vt_y = c3_rl_a * c3_nq_b;
  c3_ncb_x = c3_q[0];
  c3_ocb_x = c3_ncb_x;
  c3_ocb_x = muDoubleScalarSin(c3_ocb_x);
  c3_oq_b = c3_ocb_x;
  c3_wt_y = 2.0 * c3_oq_b;
  c3_pcb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_qcb_x = c3_pcb_x;
  c3_qcb_x = muDoubleScalarSin(c3_qcb_x);
  c3_rcb_x = c3_q[0] + c3_q[1];
  c3_scb_x = c3_rcb_x;
  c3_scb_x = muDoubleScalarSin(c3_scb_x);
  c3_pq_b = c3_scb_x;
  c3_xt_y = 2.0 * c3_pq_b;
  c3_sl_a = c3_vt_y;
  c3_qq_b = (c3_wt_y + c3_qcb_x) + c3_xt_y;
  c3_yt_y = c3_sl_a * c3_qq_b;
  c3_id_A = c3_yt_y;
  c3_tcb_x = c3_id_A;
  c3_ucb_x = c3_tcb_x;
  c3_au_y = c3_ucb_x / 8.0;
  c3_vcb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_wcb_x = c3_vcb_x;
  c3_wcb_x = muDoubleScalarSin(c3_wcb_x);
  c3_tl_a = c3_b_m;
  c3_rq_b = c3_wcb_x;
  c3_bu_y = c3_tl_a * c3_rq_b;
  c3_ul_a = c3_bu_y;
  c3_sq_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_cu_y = c3_ul_a * c3_sq_b;
  c3_xcb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_ycb_x = c3_xcb_x;
  c3_ycb_x = muDoubleScalarCos(c3_ycb_x);
  c3_vl_a = c3_ycb_x;
  c3_tq_b = (c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2];
  c3_du_y = c3_vl_a * c3_tq_b;
  c3_adb_x = c3_q[0] + c3_q[1];
  c3_bdb_x = c3_adb_x;
  c3_bdb_x = muDoubleScalarCos(c3_bdb_x);
  c3_uq_b = c3_bdb_x;
  c3_eu_y = 2.0 * c3_uq_b;
  c3_wl_a = c3_eu_y;
  c3_vq_b = c3_q_dot[0] + c3_q_dot[1];
  c3_fu_y = c3_wl_a * c3_vq_b;
  c3_wq_b = c3_q_dot[0];
  c3_gu_y = 2.0 * c3_wq_b;
  c3_cdb_x = c3_q[0];
  c3_ddb_x = c3_cdb_x;
  c3_ddb_x = muDoubleScalarCos(c3_ddb_x);
  c3_xl_a = c3_gu_y;
  c3_xq_b = c3_ddb_x;
  c3_hu_y = c3_xl_a * c3_xq_b;
  c3_yl_a = c3_cu_y;
  c3_yq_b = (c3_du_y + c3_fu_y) + c3_hu_y;
  c3_iu_y = c3_yl_a * c3_yq_b;
  c3_jd_A = c3_iu_y;
  c3_edb_x = c3_jd_A;
  c3_fdb_x = c3_edb_x;
  c3_ju_y = c3_fdb_x / 8.0;
  c3_gdb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_hdb_x = c3_gdb_x;
  c3_hdb_x = muDoubleScalarCos(c3_hdb_x);
  c3_am_a = c3_b_m;
  c3_ar_b = c3_hdb_x;
  c3_ku_y = c3_am_a * c3_ar_b;
  c3_bm_a = c3_ku_y;
  c3_br_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_lu_y = c3_bm_a * c3_br_b;
  c3_idb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_jdb_x = c3_idb_x;
  c3_jdb_x = muDoubleScalarSin(c3_jdb_x);
  c3_cm_a = c3_jdb_x;
  c3_cr_b = (c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2];
  c3_mu_y = c3_cm_a * c3_cr_b;
  c3_kdb_x = c3_q[0] + c3_q[1];
  c3_ldb_x = c3_kdb_x;
  c3_ldb_x = muDoubleScalarSin(c3_ldb_x);
  c3_dr_b = c3_ldb_x;
  c3_nu_y = 2.0 * c3_dr_b;
  c3_dm_a = c3_nu_y;
  c3_er_b = c3_q_dot[0] + c3_q_dot[1];
  c3_ou_y = c3_dm_a * c3_er_b;
  c3_fr_b = c3_q_dot[0];
  c3_pu_y = 2.0 * c3_fr_b;
  c3_mdb_x = c3_q[0];
  c3_ndb_x = c3_mdb_x;
  c3_ndb_x = muDoubleScalarSin(c3_ndb_x);
  c3_em_a = c3_pu_y;
  c3_gr_b = c3_ndb_x;
  c3_qu_y = c3_em_a * c3_gr_b;
  c3_fm_a = c3_lu_y;
  c3_hr_b = (c3_mu_y + c3_ou_y) + c3_qu_y;
  c3_ru_y = c3_fm_a * c3_hr_b;
  c3_kd_A = c3_ru_y;
  c3_odb_x = c3_kd_A;
  c3_pdb_x = c3_odb_x;
  c3_su_y = c3_pdb_x / 8.0;
  c3_qdb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_rdb_x = c3_qdb_x;
  c3_rdb_x = muDoubleScalarSin(c3_rdb_x);
  c3_gm_a = c3_b_m;
  c3_ir_b = c3_rdb_x;
  c3_tu_y = c3_gm_a * c3_ir_b;
  c3_hm_a = c3_tu_y;
  c3_jr_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_uu_y = c3_hm_a * c3_jr_b;
  c3_sdb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_tdb_x = c3_sdb_x;
  c3_tdb_x = muDoubleScalarCos(c3_tdb_x);
  c3_udb_x = c3_q[0] + c3_q[1];
  c3_vdb_x = c3_udb_x;
  c3_vdb_x = muDoubleScalarCos(c3_vdb_x);
  c3_kr_b = c3_vdb_x;
  c3_vu_y = 2.0 * c3_kr_b;
  c3_wdb_x = c3_q[0];
  c3_xdb_x = c3_wdb_x;
  c3_xdb_x = muDoubleScalarCos(c3_xdb_x);
  c3_lr_b = c3_xdb_x;
  c3_wu_y = 2.0 * c3_lr_b;
  c3_im_a = c3_uu_y;
  c3_mr_b = (c3_tdb_x + c3_vu_y) + c3_wu_y;
  c3_xu_y = c3_im_a * c3_mr_b;
  c3_ld_A = c3_xu_y;
  c3_ydb_x = c3_ld_A;
  c3_aeb_x = c3_ydb_x;
  c3_yu_y = c3_aeb_x / 8.0;
  c3_beb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_ceb_x = c3_beb_x;
  c3_ceb_x = muDoubleScalarSin(c3_ceb_x);
  c3_jm_a = c3_b_m;
  c3_nr_b = c3_ceb_x;
  c3_av_y = c3_jm_a * c3_nr_b;
  c3_km_a = c3_av_y;
  c3_or_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_bv_y = c3_km_a * c3_or_b;
  c3_deb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_eeb_x = c3_deb_x;
  c3_eeb_x = muDoubleScalarCos(c3_eeb_x);
  c3_feb_x = c3_q[0] + c3_q[1];
  c3_geb_x = c3_feb_x;
  c3_geb_x = muDoubleScalarCos(c3_geb_x);
  c3_pr_b = c3_geb_x;
  c3_cv_y = 2.0 * c3_pr_b;
  c3_heb_x = c3_q[0];
  c3_ieb_x = c3_heb_x;
  c3_ieb_x = muDoubleScalarCos(c3_ieb_x);
  c3_qr_b = c3_ieb_x;
  c3_dv_y = 2.0 * c3_qr_b;
  c3_lm_a = c3_bv_y;
  c3_rr_b = (c3_eeb_x + c3_cv_y) + c3_dv_y;
  c3_ev_y = c3_lm_a * c3_rr_b;
  c3_mm_a = c3_ev_y;
  c3_sr_b = (c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2];
  c3_fv_y = c3_mm_a * c3_sr_b;
  c3_md_A = c3_fv_y;
  c3_jeb_x = c3_md_A;
  c3_keb_x = c3_jeb_x;
  c3_gv_y = c3_keb_x / 8.0;
  c3_leb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_meb_x = c3_leb_x;
  c3_meb_x = muDoubleScalarCos(c3_meb_x);
  c3_nm_a = c3_b_m;
  c3_tr_b = c3_meb_x;
  c3_hv_y = c3_nm_a * c3_tr_b;
  c3_om_a = c3_hv_y;
  c3_ur_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_iv_y = c3_om_a * c3_ur_b;
  c3_neb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_oeb_x = c3_neb_x;
  c3_oeb_x = muDoubleScalarSin(c3_oeb_x);
  c3_peb_x = c3_q[0] + c3_q[1];
  c3_qeb_x = c3_peb_x;
  c3_qeb_x = muDoubleScalarSin(c3_qeb_x);
  c3_vr_b = c3_qeb_x;
  c3_jv_y = 2.0 * c3_vr_b;
  c3_reb_x = c3_q[0];
  c3_seb_x = c3_reb_x;
  c3_seb_x = muDoubleScalarSin(c3_seb_x);
  c3_wr_b = c3_seb_x;
  c3_kv_y = 2.0 * c3_wr_b;
  c3_pm_a = c3_iv_y;
  c3_xr_b = (c3_oeb_x + c3_jv_y) + c3_kv_y;
  c3_lv_y = c3_pm_a * c3_xr_b;
  c3_qm_a = c3_lv_y;
  c3_yr_b = (c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2];
  c3_mv_y = c3_qm_a * c3_yr_b;
  c3_nd_A = c3_mv_y;
  c3_teb_x = c3_nd_A;
  c3_ueb_x = c3_teb_x;
  c3_nv_y = c3_ueb_x / 8.0;
  c3_rm_a = c3_b_m;
  c3_as_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_ov_y = c3_rm_a * c3_as_b;
  c3_veb_x = (((c3_q[0] - c3_q[1]) - c3_q[2]) - c3_q[0]) + c3_q[1];
  c3_web_x = c3_veb_x;
  c3_web_x = muDoubleScalarSin(c3_web_x);
  c3_sm_a = c3_ov_y;
  c3_bs_b = c3_web_x;
  c3_pv_y = c3_sm_a * c3_bs_b;
  c3_od_A = c3_pv_y;
  c3_xeb_x = c3_od_A;
  c3_yeb_x = c3_xeb_x;
  c3_qv_y = c3_yeb_x / 4.0;
  c3_afb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_bfb_x = c3_afb_x;
  c3_bfb_x = muDoubleScalarCos(c3_bfb_x);
  c3_tm_a = c3_b_m;
  c3_cs_b = c3_bfb_x;
  c3_rv_y = c3_tm_a * c3_cs_b;
  c3_um_a = c3_rv_y;
  c3_ds_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_sv_y = c3_um_a * c3_ds_b;
  c3_cfb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_dfb_x = c3_cfb_x;
  c3_dfb_x = muDoubleScalarSin(c3_dfb_x);
  c3_efb_x = c3_q[0] + c3_q[1];
  c3_ffb_x = c3_efb_x;
  c3_ffb_x = muDoubleScalarSin(c3_ffb_x);
  c3_es_b = c3_ffb_x;
  c3_tv_y = 2.0 * c3_es_b;
  c3_gfb_x = c3_q[0];
  c3_hfb_x = c3_gfb_x;
  c3_hfb_x = muDoubleScalarSin(c3_hfb_x);
  c3_fs_b = c3_hfb_x;
  c3_uv_y = 2.0 * c3_fs_b;
  c3_vm_a = c3_sv_y;
  c3_gs_b = (c3_dfb_x + c3_tv_y) + c3_uv_y;
  c3_vv_y = c3_vm_a * c3_gs_b;
  c3_pd_A = c3_vv_y;
  c3_ifb_x = c3_pd_A;
  c3_jfb_x = c3_ifb_x;
  c3_wv_y = c3_jfb_x / 4.0;
  c3_kfb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_lfb_x = c3_kfb_x;
  c3_lfb_x = muDoubleScalarSin(c3_lfb_x);
  c3_wm_a = c3_b_m;
  c3_hs_b = c3_lfb_x;
  c3_xv_y = c3_wm_a * c3_hs_b;
  c3_xm_a = c3_xv_y;
  c3_is_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_yv_y = c3_xm_a * c3_is_b;
  c3_mfb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_nfb_x = c3_mfb_x;
  c3_nfb_x = muDoubleScalarCos(c3_nfb_x);
  c3_ym_a = c3_nfb_x;
  c3_js_b = (c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2];
  c3_aw_y = c3_ym_a * c3_js_b;
  c3_ofb_x = c3_q[0] + c3_q[1];
  c3_pfb_x = c3_ofb_x;
  c3_pfb_x = muDoubleScalarCos(c3_pfb_x);
  c3_ks_b = c3_pfb_x;
  c3_bw_y = 2.0 * c3_ks_b;
  c3_an_a = c3_bw_y;
  c3_ls_b = c3_q_dot[0] + c3_q_dot[1];
  c3_cw_y = c3_an_a * c3_ls_b;
  c3_bn_a = c3_yv_y;
  c3_ms_b = c3_aw_y + c3_cw_y;
  c3_dw_y = c3_bn_a * c3_ms_b;
  c3_qd_A = c3_dw_y;
  c3_qfb_x = c3_qd_A;
  c3_rfb_x = c3_qfb_x;
  c3_ew_y = c3_rfb_x / 8.0;
  c3_sfb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_tfb_x = c3_sfb_x;
  c3_tfb_x = muDoubleScalarCos(c3_tfb_x);
  c3_cn_a = c3_b_m;
  c3_ns_b = c3_tfb_x;
  c3_fw_y = c3_cn_a * c3_ns_b;
  c3_dn_a = c3_fw_y;
  c3_os_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_gw_y = c3_dn_a * c3_os_b;
  c3_ufb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_vfb_x = c3_ufb_x;
  c3_vfb_x = muDoubleScalarSin(c3_vfb_x);
  c3_en_a = c3_vfb_x;
  c3_ps_b = (c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2];
  c3_hw_y = c3_en_a * c3_ps_b;
  c3_wfb_x = c3_q[0] + c3_q[1];
  c3_xfb_x = c3_wfb_x;
  c3_xfb_x = muDoubleScalarSin(c3_xfb_x);
  c3_qs_b = c3_xfb_x;
  c3_iw_y = 2.0 * c3_qs_b;
  c3_fn_a = c3_iw_y;
  c3_rs_b = c3_q_dot[0] + c3_q_dot[1];
  c3_jw_y = c3_fn_a * c3_rs_b;
  c3_gn_a = c3_gw_y;
  c3_ss_b = c3_hw_y + c3_jw_y;
  c3_kw_y = c3_gn_a * c3_ss_b;
  c3_rd_A = c3_kw_y;
  c3_yfb_x = c3_rd_A;
  c3_agb_x = c3_yfb_x;
  c3_lw_y = c3_agb_x / 8.0;
  c3_bgb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_cgb_x = c3_bgb_x;
  c3_cgb_x = muDoubleScalarSin(c3_cgb_x);
  c3_hn_a = c3_b_m;
  c3_ts_b = c3_cgb_x;
  c3_mw_y = c3_hn_a * c3_ts_b;
  c3_in_a = c3_mw_y;
  c3_us_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_nw_y = c3_in_a * c3_us_b;
  c3_dgb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_egb_x = c3_dgb_x;
  c3_egb_x = muDoubleScalarCos(c3_egb_x);
  c3_fgb_x = c3_q[0] + c3_q[1];
  c3_ggb_x = c3_fgb_x;
  c3_ggb_x = muDoubleScalarCos(c3_ggb_x);
  c3_vs_b = c3_ggb_x;
  c3_ow_y = 2.0 * c3_vs_b;
  c3_jn_a = c3_nw_y;
  c3_ws_b = c3_egb_x + c3_ow_y;
  c3_pw_y = c3_jn_a * c3_ws_b;
  c3_sd_A = c3_pw_y;
  c3_hgb_x = c3_sd_A;
  c3_igb_x = c3_hgb_x;
  c3_qw_y = c3_igb_x / 4.0;
  c3_jgb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_kgb_x = c3_jgb_x;
  c3_kgb_x = muDoubleScalarCos(c3_kgb_x);
  c3_kn_a = c3_b_m;
  c3_xs_b = c3_kgb_x;
  c3_rw_y = c3_kn_a * c3_xs_b;
  c3_ln_a = c3_rw_y;
  c3_ys_b = c3_mpower(chartInstance, c3_abs(chartInstance, c3_b_l));
  c3_sw_y = c3_ln_a * c3_ys_b;
  c3_lgb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_mgb_x = c3_lgb_x;
  c3_mgb_x = muDoubleScalarSin(c3_mgb_x);
  c3_ngb_x = c3_q[0] + c3_q[1];
  c3_ogb_x = c3_ngb_x;
  c3_ogb_x = muDoubleScalarSin(c3_ogb_x);
  c3_at_b = c3_ogb_x;
  c3_tw_y = 2.0 * c3_at_b;
  c3_mn_a = c3_sw_y;
  c3_bt_b = c3_mgb_x + c3_tw_y;
  c3_uw_y = c3_mn_a * c3_bt_b;
  c3_td_A = c3_uw_y;
  c3_pgb_x = c3_td_A;
  c3_qgb_x = c3_pgb_x;
  c3_vw_y = c3_qgb_x / 4.0;
  c3_rgb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_sgb_x = c3_rgb_x;
  c3_sgb_x = muDoubleScalarSin(c3_sgb_x);
  c3_nn_a = c3_b_m;
  c3_ct_b = c3_sgb_x;
  c3_ww_y = c3_nn_a * c3_ct_b;
  c3_tgb_x = c3_b_l;
  c3_ugb_x = c3_tgb_x;
  c3_xw_y = muDoubleScalarAbs(c3_ugb_x);
  c3_on_a = c3_ww_y;
  c3_dt_b = c3_mpower(chartInstance, c3_xw_y);
  c3_yw_y = c3_on_a * c3_dt_b;
  c3_vgb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_wgb_x = c3_vgb_x;
  c3_wgb_x = muDoubleScalarCos(c3_wgb_x);
  c3_xgb_x = c3_q[0] + c3_q[1];
  c3_ygb_x = c3_xgb_x;
  c3_ygb_x = muDoubleScalarCos(c3_ygb_x);
  c3_et_b = c3_ygb_x;
  c3_ax_y = 2.0 * c3_et_b;
  c3_ahb_x = c3_q[0];
  c3_bhb_x = c3_ahb_x;
  c3_bhb_x = muDoubleScalarCos(c3_bhb_x);
  c3_ft_b = c3_bhb_x;
  c3_bx_y = 2.0 * c3_ft_b;
  c3_pn_a = c3_yw_y;
  c3_gt_b = (c3_wgb_x + c3_ax_y) + c3_bx_y;
  c3_cx_y = c3_pn_a * c3_gt_b;
  c3_ud_A = c3_cx_y;
  c3_chb_x = c3_ud_A;
  c3_dhb_x = c3_chb_x;
  c3_dx_y = c3_dhb_x / 4.0;
  c3_ehb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_fhb_x = c3_ehb_x;
  c3_fhb_x = muDoubleScalarSin(c3_fhb_x);
  c3_qn_a = c3_b_m;
  c3_ht_b = c3_fhb_x;
  c3_ex_y = c3_qn_a * c3_ht_b;
  c3_ghb_x = c3_b_l;
  c3_hhb_x = c3_ghb_x;
  c3_fx_y = muDoubleScalarAbs(c3_hhb_x);
  c3_rn_a = c3_ex_y;
  c3_it_b = c3_mpower(chartInstance, c3_fx_y);
  c3_gx_y = c3_rn_a * c3_it_b;
  c3_ihb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_jhb_x = c3_ihb_x;
  c3_jhb_x = muDoubleScalarCos(c3_jhb_x);
  c3_khb_x = c3_q[0] + c3_q[1];
  c3_lhb_x = c3_khb_x;
  c3_lhb_x = muDoubleScalarCos(c3_lhb_x);
  c3_jt_b = c3_lhb_x;
  c3_hx_y = 2.0 * c3_jt_b;
  c3_sn_a = c3_gx_y;
  c3_kt_b = c3_jhb_x + c3_hx_y;
  c3_ix_y = c3_sn_a * c3_kt_b;
  c3_tn_a = c3_ix_y;
  c3_lt_b = (c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2];
  c3_jx_y = c3_tn_a * c3_lt_b;
  c3_vd_A = c3_jx_y;
  c3_mhb_x = c3_vd_A;
  c3_nhb_x = c3_mhb_x;
  c3_kx_y = c3_nhb_x / 8.0;
  c3_ohb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_phb_x = c3_ohb_x;
  c3_phb_x = muDoubleScalarCos(c3_phb_x);
  c3_un_a = c3_b_m;
  c3_mt_b = c3_phb_x;
  c3_lx_y = c3_un_a * c3_mt_b;
  c3_qhb_x = c3_b_l;
  c3_rhb_x = c3_qhb_x;
  c3_mx_y = muDoubleScalarAbs(c3_rhb_x);
  c3_vn_a = c3_lx_y;
  c3_nt_b = c3_mpower(chartInstance, c3_mx_y);
  c3_nx_y = c3_vn_a * c3_nt_b;
  c3_shb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_thb_x = c3_shb_x;
  c3_thb_x = muDoubleScalarSin(c3_thb_x);
  c3_uhb_x = c3_q[0] + c3_q[1];
  c3_vhb_x = c3_uhb_x;
  c3_vhb_x = muDoubleScalarSin(c3_vhb_x);
  c3_ot_b = c3_vhb_x;
  c3_ox_y = 2.0 * c3_ot_b;
  c3_wn_a = c3_nx_y;
  c3_pt_b = c3_thb_x + c3_ox_y;
  c3_px_y = c3_wn_a * c3_pt_b;
  c3_xn_a = c3_px_y;
  c3_qt_b = (c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2];
  c3_qx_y = c3_xn_a * c3_qt_b;
  c3_wd_A = c3_qx_y;
  c3_whb_x = c3_wd_A;
  c3_xhb_x = c3_whb_x;
  c3_rx_y = c3_xhb_x / 8.0;
  c3_yhb_x = ((((c3_q[0] - c3_q[1]) - c3_q[2]) - c3_q[0]) + c3_q[1]) + c3_q[2];
  c3_aib_x = c3_yhb_x;
  c3_aib_x = muDoubleScalarSin(c3_aib_x);
  c3_yn_a = c3_b_m;
  c3_rt_b = c3_aib_x;
  c3_sx_y = c3_yn_a * c3_rt_b;
  c3_bib_x = c3_b_l;
  c3_cib_x = c3_bib_x;
  c3_tx_y = muDoubleScalarAbs(c3_cib_x);
  c3_ao_a = c3_sx_y;
  c3_st_b = c3_mpower(chartInstance, c3_tx_y);
  c3_ux_y = c3_ao_a * c3_st_b;
  c3_bo_a = c3_ux_y;
  c3_tt_b = ((((c3_q_dot[0] + c3_q_dot[1]) + c3_q_dot[2]) - c3_q_dot[0]) -
             c3_q_dot[1]) - c3_q_dot[2];
  c3_vx_y = c3_bo_a * c3_tt_b;
  c3_xd_A = c3_vx_y;
  c3_dib_x = c3_xd_A;
  c3_eib_x = c3_dib_x;
  c3_wx_y = c3_eib_x / 8.0;
  c3_fib_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_gib_x = c3_fib_x;
  c3_gib_x = muDoubleScalarCos(c3_gib_x);
  c3_co_a = c3_b_m;
  c3_ut_b = c3_gib_x;
  c3_xx_y = c3_co_a * c3_ut_b;
  c3_hib_x = c3_b_l;
  c3_iib_x = c3_hib_x;
  c3_yx_y = muDoubleScalarAbs(c3_iib_x);
  c3_do_a = c3_xx_y;
  c3_vt_b = c3_mpower(chartInstance, c3_yx_y);
  c3_ay_y = c3_do_a * c3_vt_b;
  c3_jib_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_kib_x = c3_jib_x;
  c3_kib_x = muDoubleScalarSin(c3_kib_x);
  c3_lib_x = c3_q[0] + c3_q[1];
  c3_mib_x = c3_lib_x;
  c3_mib_x = muDoubleScalarSin(c3_mib_x);
  c3_wt_b = c3_mib_x;
  c3_by_y = 2.0 * c3_wt_b;
  c3_nib_x = c3_q[0];
  c3_oib_x = c3_nib_x;
  c3_oib_x = muDoubleScalarSin(c3_oib_x);
  c3_xt_b = c3_oib_x;
  c3_cy_y = 2.0 * c3_xt_b;
  c3_eo_a = c3_ay_y;
  c3_yt_b = (c3_kib_x + c3_by_y) + c3_cy_y;
  c3_dy_y = c3_eo_a * c3_yt_b;
  c3_yd_A = c3_dy_y;
  c3_pib_x = c3_yd_A;
  c3_qib_x = c3_pib_x;
  c3_ey_y = c3_qib_x / 4.0;
  c3_rib_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_sib_x = c3_rib_x;
  c3_sib_x = muDoubleScalarCos(c3_sib_x);
  c3_fo_a = c3_b_m;
  c3_au_b = c3_sib_x;
  c3_fy_y = c3_fo_a * c3_au_b;
  c3_tib_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_uib_x = c3_tib_x;
  c3_uib_x = muDoubleScalarSin(c3_uib_x);
  c3_go_a = c3_fy_y;
  c3_bu_b = c3_uib_x;
  c3_gy_y = c3_go_a * c3_bu_b;
  c3_vib_x = c3_b_l;
  c3_wib_x = c3_vib_x;
  c3_hy_y = muDoubleScalarAbs(c3_wib_x);
  c3_ho_a = c3_gy_y;
  c3_cu_b = c3_mpower(chartInstance, c3_hy_y);
  c3_iy_y = c3_ho_a * c3_cu_b;
  c3_ae_A = c3_iy_y;
  c3_xib_x = c3_ae_A;
  c3_yib_x = c3_xib_x;
  c3_jy_y = c3_yib_x / 2.0;
  c3_ajb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_bjb_x = c3_ajb_x;
  c3_bjb_x = muDoubleScalarSin(c3_bjb_x);
  c3_io_a = c3_b_m;
  c3_du_b = c3_bjb_x;
  c3_ky_y = c3_io_a * c3_du_b;
  c3_cjb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_djb_x = c3_cjb_x;
  c3_djb_x = muDoubleScalarCos(c3_djb_x);
  c3_jo_a = c3_ky_y;
  c3_eu_b = c3_djb_x;
  c3_ly_y = c3_jo_a * c3_eu_b;
  c3_ejb_x = c3_b_l;
  c3_fjb_x = c3_ejb_x;
  c3_my_y = muDoubleScalarAbs(c3_fjb_x);
  c3_ko_a = c3_ly_y;
  c3_fu_b = c3_mpower(chartInstance, c3_my_y);
  c3_ny_y = c3_ko_a * c3_fu_b;
  c3_be_A = c3_ny_y;
  c3_gjb_x = c3_be_A;
  c3_hjb_x = c3_gjb_x;
  c3_oy_y = c3_hjb_x / 2.0;
  c3_ijb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_jjb_x = c3_ijb_x;
  c3_jjb_x = muDoubleScalarSin(c3_jjb_x);
  c3_lo_a = c3_b_m;
  c3_gu_b = c3_jjb_x;
  c3_py_y = c3_lo_a * c3_gu_b;
  c3_kjb_x = c3_b_l;
  c3_ljb_x = c3_kjb_x;
  c3_qy_y = muDoubleScalarAbs(c3_ljb_x);
  c3_mo_a = c3_py_y;
  c3_hu_b = c3_mpower(chartInstance, c3_qy_y);
  c3_ry_y = c3_mo_a * c3_hu_b;
  c3_mjb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_njb_x = c3_mjb_x;
  c3_njb_x = muDoubleScalarCos(c3_njb_x);
  c3_ojb_x = c3_q[0] + c3_q[1];
  c3_pjb_x = c3_ojb_x;
  c3_pjb_x = muDoubleScalarCos(c3_pjb_x);
  c3_iu_b = c3_pjb_x;
  c3_sy_y = 2.0 * c3_iu_b;
  c3_no_a = c3_ry_y;
  c3_ju_b = c3_njb_x + c3_sy_y;
  c3_ty_y = c3_no_a * c3_ju_b;
  c3_ce_A = c3_ty_y;
  c3_qjb_x = c3_ce_A;
  c3_rjb_x = c3_qjb_x;
  c3_uy_y = c3_rjb_x / 4.0;
  c3_sjb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_tjb_x = c3_sjb_x;
  c3_tjb_x = muDoubleScalarCos(c3_tjb_x);
  c3_oo_a = c3_b_m;
  c3_ku_b = c3_tjb_x;
  c3_vy_y = c3_oo_a * c3_ku_b;
  c3_ujb_x = c3_b_l;
  c3_vjb_x = c3_ujb_x;
  c3_wy_y = muDoubleScalarAbs(c3_vjb_x);
  c3_po_a = c3_vy_y;
  c3_lu_b = c3_mpower(chartInstance, c3_wy_y);
  c3_xy_y = c3_po_a * c3_lu_b;
  c3_wjb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_xjb_x = c3_wjb_x;
  c3_xjb_x = muDoubleScalarSin(c3_xjb_x);
  c3_yjb_x = c3_q[0] + c3_q[1];
  c3_akb_x = c3_yjb_x;
  c3_akb_x = muDoubleScalarSin(c3_akb_x);
  c3_mu_b = c3_akb_x;
  c3_yy_y = 2.0 * c3_mu_b;
  c3_qo_a = c3_xy_y;
  c3_nu_b = c3_xjb_x + c3_yy_y;
  c3_aab_y = c3_qo_a * c3_nu_b;
  c3_de_A = c3_aab_y;
  c3_bkb_x = c3_de_A;
  c3_ckb_x = c3_bkb_x;
  c3_bab_y = c3_ckb_x / 4.0;
  c3_dkb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_ekb_x = c3_dkb_x;
  c3_ekb_x = muDoubleScalarSin(c3_ekb_x);
  c3_ro_a = c3_b_m;
  c3_ou_b = c3_ekb_x;
  c3_cab_y = c3_ro_a * c3_ou_b;
  c3_fkb_x = c3_b_l;
  c3_gkb_x = c3_fkb_x;
  c3_dab_y = muDoubleScalarAbs(c3_gkb_x);
  c3_so_a = c3_cab_y;
  c3_pu_b = c3_mpower(chartInstance, c3_dab_y);
  c3_eab_y = c3_so_a * c3_pu_b;
  c3_hkb_x = (c3_q[0] + c3_q[1]) + c3_q[2];
  c3_ikb_x = c3_hkb_x;
  c3_ikb_x = muDoubleScalarCos(c3_ikb_x);
  c3_jkb_x = c3_q[0] + c3_q[1];
  c3_kkb_x = c3_jkb_x;
  c3_kkb_x = muDoubleScalarCos(c3_kkb_x);
  c3_qu_b = c3_kkb_x;
  c3_fab_y = 2.0 * c3_qu_b;
  c3_lkb_x = c3_q[0];
  c3_mkb_x = c3_lkb_x;
  c3_mkb_x = muDoubleScalarCos(c3_mkb_x);
  c3_ru_b = c3_mkb_x;
  c3_gab_y = 2.0 * c3_ru_b;
  c3_to_a = c3_eab_y;
  c3_su_b = (c3_ikb_x + c3_fab_y) + c3_gab_y;
  c3_hab_y = c3_to_a * c3_su_b;
  c3_ee_A = c3_hab_y;
  c3_nkb_x = c3_ee_A;
  c3_okb_x = c3_nkb_x;
  c3_iab_y = c3_okb_x / 4.0;
  c3_C[0] = ((((((((((c3_k_y - c3_v_y) + c3_eb_y) - c3_mb_y) - c3_ub_y) +
                  c3_dc_y) + c3_oc_y) - c3_ad_y) - c3_fd_y) + c3_kd_y) + c3_pd_y)
    - c3_ud_y;
  c3_C[3] = ((((((((((((((c3_xd_y + c3_ce_y) + c3_ge_y) + c3_ke_y) - c3_pe_y) +
                      c3_ue_y) - c3_cf_y) + c3_jf_y) - c3_nf_y) - c3_uf_y) +
                 c3_cg_y) - c3_hg_y) + c3_mg_y) + c3_rg_y) + c3_wg_y) + c3_bh_y;
  c3_C[6] = (((((((c3_eh_y + c3_jh_y) + c3_rh_y) + c3_uh_y) - c3_xh_y) + c3_ei_y)
              - c3_ki_y) + c3_qi_y) - c3_wi_y;
  c3_C[1] = ((((((((((((((((c3_aj_y + c3_ej_y) - c3_oj_y) - c3_tj_y) + c3_yj_y)
                        - c3_gk_y) + c3_nk_y) - c3_wk_y) + c3_gl_y) - c3_nl_y) +
                   c3_ul_y) - c3_am_y) + c3_fm_y) + c3_mm_y) - c3_tm_y) +
              c3_en_y) - c3_kn_y) + c3_qn_y;
  c3_C[4] = ((((((((((((((c3_un_y - c3_yn_y) - c3_go_y) + c3_no_y) - c3_vo_y) +
                      c3_ep_y) - c3_mp_y) + c3_up_y) - c3_aq_y) + c3_fq_y) -
                 c3_lq_y) + c3_rq_y) + c3_wq_y) - c3_cr_y) - c3_hr_y) + c3_mr_y;
  c3_C[7] = ((((c3_sr_y + c3_vr_y) + c3_cs_y) - c3_hs_y) + c3_ms_y) - c3_ss_y;
  c3_C[2] = ((((((((((c3_vs_y + c3_bt_y) + c3_et_y) - c3_ht_y) + c3_nt_y) -
                  c3_tt_y) + c3_au_y) + c3_ju_y) - c3_su_y) - c3_yu_y) - c3_gv_y)
    + c3_nv_y;
  c3_C[5] = (((((((c3_qv_y + c3_wv_y) + c3_ew_y) - c3_lw_y) - c3_qw_y) + c3_vw_y)
              - c3_dx_y) - c3_kx_y) + c3_rx_y;
  c3_C[8] = (((((c3_wx_y + c3_ey_y) + c3_jy_y) - c3_oy_y) - c3_uy_y) + c3_bab_y)
    - c3_iab_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  for (c3_i8 = 0; c3_i8 < 9; c3_i8++) {
    (*c3_b_C)[c3_i8] = c3_C[c3_i8];
  }

  for (c3_i9 = 0; c3_i9 < 3; c3_i9++) {
    (*c3_b_q_dot)[c3_i9] = c3_q_dot[c3_i9];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_ManipulatorME4901
  (SFc3_ManipulatorME4901InstanceStruct *chartInstance)
{
}

static void registerMessagesc3_ManipulatorME4901
  (SFc3_ManipulatorME4901InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i10;
  real_T c3_b_inData[3];
  int32_T c3_i11;
  real_T c3_u[3];
  const mxArray *c3_y = NULL;
  SFc3_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc3_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i10 = 0; c3_i10 < 3; c3_i10++) {
    c3_b_inData[c3_i10] = (*(real_T (*)[3])c3_inData)[c3_i10];
  }

  for (c3_i11 = 0; c3_i11 < 3; c3_i11++) {
    c3_u[c3_i11] = c3_b_inData[c3_i11];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_emlrt_marshallIn(SFc3_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c3_q_dot, const char_T *c3_identifier, real_T
  c3_y[3])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_q_dot), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_q_dot);
}

static void c3_b_emlrt_marshallIn(SFc3_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[3])
{
  real_T c3_dv2[3];
  int32_T c3_i12;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv2, 1, 0, 0U, 1, 0U, 1, 3);
  for (c3_i12 = 0; c3_i12 < 3; c3_i12++) {
    c3_y[c3_i12] = c3_dv2[c3_i12];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_q_dot;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[3];
  int32_T c3_i13;
  SFc3_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc3_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c3_q_dot = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_q_dot), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_q_dot);
  for (c3_i13 = 0; c3_i13 < 3; c3_i13++) {
    (*(real_T (*)[3])c3_outData)[c3_i13] = c3_y[c3_i13];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i14;
  int32_T c3_i15;
  int32_T c3_i16;
  real_T c3_b_inData[9];
  int32_T c3_i17;
  int32_T c3_i18;
  int32_T c3_i19;
  real_T c3_u[9];
  const mxArray *c3_y = NULL;
  SFc3_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc3_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i14 = 0;
  for (c3_i15 = 0; c3_i15 < 3; c3_i15++) {
    for (c3_i16 = 0; c3_i16 < 3; c3_i16++) {
      c3_b_inData[c3_i16 + c3_i14] = (*(real_T (*)[9])c3_inData)[c3_i16 + c3_i14];
    }

    c3_i14 += 3;
  }

  c3_i17 = 0;
  for (c3_i18 = 0; c3_i18 < 3; c3_i18++) {
    for (c3_i19 = 0; c3_i19 < 3; c3_i19++) {
      c3_u[c3_i19 + c3_i17] = c3_b_inData[c3_i19 + c3_i17];
    }

    c3_i17 += 3;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_c_emlrt_marshallIn(SFc3_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c3_C, const char_T *c3_identifier, real_T c3_y
  [9])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_C), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_C);
}

static void c3_d_emlrt_marshallIn(SFc3_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[9])
{
  real_T c3_dv3[9];
  int32_T c3_i20;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv3, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c3_i20 = 0; c3_i20 < 9; c3_i20++) {
    c3_y[c3_i20] = c3_dv3[c3_i20];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_C;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[9];
  int32_T c3_i21;
  int32_T c3_i22;
  int32_T c3_i23;
  SFc3_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc3_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c3_C = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_C), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_C);
  c3_i21 = 0;
  for (c3_i22 = 0; c3_i22 < 3; c3_i22++) {
    for (c3_i23 = 0; c3_i23 < 3; c3_i23++) {
      (*(real_T (*)[9])c3_outData)[c3_i23 + c3_i21] = c3_y[c3_i23 + c3_i21];
    }

    c3_i21 += 3;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc3_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_e_emlrt_marshallIn(SFc3_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d2;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d2, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d2;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_l;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc3_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c3_b_l = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_l), &c3_thisId);
  sf_mex_destroy(&c3_b_l);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i24;
  real_T c3_b_inData[9];
  int32_T c3_i25;
  real_T c3_u[9];
  const mxArray *c3_y = NULL;
  SFc3_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc3_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i24 = 0; c3_i24 < 9; c3_i24++) {
    c3_b_inData[c3_i24] = (*(real_T (*)[9])c3_inData)[c3_i24];
  }

  for (c3_i25 = 0; c3_i25 < 9; c3_i25++) {
    c3_u[c3_i25] = c3_b_inData[c3_i25];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 9), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

const mxArray *sf_c3_ManipulatorME4901_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[19];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i26;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 19), FALSE);
  for (c3_i26 = 0; c3_i26 < 19; c3_i26++) {
    c3_r0 = &c3_info[c3_i26];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i26);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i26);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i26);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i26);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i26);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i26);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i26);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i26);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[19])
{
  c3_info[0].context = "";
  c3_info[0].name = "abs";
  c3_info[0].dominantType = "double";
  c3_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[0].fileTimeLo = 1343862766U;
  c3_info[0].fileTimeHi = 0U;
  c3_info[0].mFileTimeLo = 0U;
  c3_info[0].mFileTimeHi = 0U;
  c3_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[1].name = "eml_scalar_abs";
  c3_info[1].dominantType = "double";
  c3_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c3_info[1].fileTimeLo = 1286851112U;
  c3_info[1].fileTimeHi = 0U;
  c3_info[1].mFileTimeLo = 0U;
  c3_info[1].mFileTimeHi = 0U;
  c3_info[2].context = "";
  c3_info[2].name = "mpower";
  c3_info[2].dominantType = "double";
  c3_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[2].fileTimeLo = 1286851242U;
  c3_info[2].fileTimeHi = 0U;
  c3_info[2].mFileTimeLo = 0U;
  c3_info[2].mFileTimeHi = 0U;
  c3_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[3].name = "power";
  c3_info[3].dominantType = "double";
  c3_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c3_info[3].fileTimeLo = 1348224330U;
  c3_info[3].fileTimeHi = 0U;
  c3_info[3].mFileTimeLo = 0U;
  c3_info[3].mFileTimeHi = 0U;
  c3_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c3_info[4].name = "eml_scalar_eg";
  c3_info[4].dominantType = "double";
  c3_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[4].fileTimeLo = 1286851196U;
  c3_info[4].fileTimeHi = 0U;
  c3_info[4].mFileTimeLo = 0U;
  c3_info[4].mFileTimeHi = 0U;
  c3_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c3_info[5].name = "eml_scalexp_alloc";
  c3_info[5].dominantType = "double";
  c3_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[5].fileTimeLo = 1352457260U;
  c3_info[5].fileTimeHi = 0U;
  c3_info[5].mFileTimeLo = 0U;
  c3_info[5].mFileTimeHi = 0U;
  c3_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c3_info[6].name = "floor";
  c3_info[6].dominantType = "double";
  c3_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c3_info[6].fileTimeLo = 1343862780U;
  c3_info[6].fileTimeHi = 0U;
  c3_info[6].mFileTimeLo = 0U;
  c3_info[6].mFileTimeHi = 0U;
  c3_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c3_info[7].name = "eml_scalar_floor";
  c3_info[7].dominantType = "double";
  c3_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c3_info[7].fileTimeLo = 1286851126U;
  c3_info[7].fileTimeHi = 0U;
  c3_info[7].mFileTimeLo = 0U;
  c3_info[7].mFileTimeHi = 0U;
  c3_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c3_info[8].name = "eml_scalar_eg";
  c3_info[8].dominantType = "double";
  c3_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[8].fileTimeLo = 1286851196U;
  c3_info[8].fileTimeHi = 0U;
  c3_info[8].mFileTimeLo = 0U;
  c3_info[8].mFileTimeHi = 0U;
  c3_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c3_info[9].name = "mtimes";
  c3_info[9].dominantType = "double";
  c3_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[9].fileTimeLo = 1289552092U;
  c3_info[9].fileTimeHi = 0U;
  c3_info[9].mFileTimeLo = 0U;
  c3_info[9].mFileTimeHi = 0U;
  c3_info[10].context = "";
  c3_info[10].name = "mtimes";
  c3_info[10].dominantType = "double";
  c3_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[10].fileTimeLo = 1289552092U;
  c3_info[10].fileTimeHi = 0U;
  c3_info[10].mFileTimeLo = 0U;
  c3_info[10].mFileTimeHi = 0U;
  c3_info[11].context = "";
  c3_info[11].name = "sin";
  c3_info[11].dominantType = "double";
  c3_info[11].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c3_info[11].fileTimeLo = 1343862786U;
  c3_info[11].fileTimeHi = 0U;
  c3_info[11].mFileTimeLo = 0U;
  c3_info[11].mFileTimeHi = 0U;
  c3_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c3_info[12].name = "eml_scalar_sin";
  c3_info[12].dominantType = "double";
  c3_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c3_info[12].fileTimeLo = 1286851136U;
  c3_info[12].fileTimeHi = 0U;
  c3_info[12].mFileTimeLo = 0U;
  c3_info[12].mFileTimeHi = 0U;
  c3_info[13].context = "";
  c3_info[13].name = "cos";
  c3_info[13].dominantType = "double";
  c3_info[13].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[13].fileTimeLo = 1343862772U;
  c3_info[13].fileTimeHi = 0U;
  c3_info[13].mFileTimeLo = 0U;
  c3_info[13].mFileTimeHi = 0U;
  c3_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c3_info[14].name = "eml_scalar_cos";
  c3_info[14].dominantType = "double";
  c3_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c3_info[14].fileTimeLo = 1286851122U;
  c3_info[14].fileTimeHi = 0U;
  c3_info[14].mFileTimeLo = 0U;
  c3_info[14].mFileTimeHi = 0U;
  c3_info[15].context = "";
  c3_info[15].name = "mrdivide";
  c3_info[15].dominantType = "double";
  c3_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[15].fileTimeLo = 1357983948U;
  c3_info[15].fileTimeHi = 0U;
  c3_info[15].mFileTimeLo = 1319762366U;
  c3_info[15].mFileTimeHi = 0U;
  c3_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[16].name = "rdivide";
  c3_info[16].dominantType = "double";
  c3_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[16].fileTimeLo = 1346542788U;
  c3_info[16].fileTimeHi = 0U;
  c3_info[16].mFileTimeLo = 0U;
  c3_info[16].mFileTimeHi = 0U;
  c3_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[17].name = "eml_scalexp_compatible";
  c3_info[17].dominantType = "double";
  c3_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c3_info[17].fileTimeLo = 1286851196U;
  c3_info[17].fileTimeHi = 0U;
  c3_info[17].mFileTimeLo = 0U;
  c3_info[17].mFileTimeHi = 0U;
  c3_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[18].name = "eml_div";
  c3_info[18].dominantType = "double";
  c3_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[18].fileTimeLo = 1313380210U;
  c3_info[18].fileTimeHi = 0U;
  c3_info[18].mFileTimeLo = 0U;
  c3_info[18].mFileTimeHi = 0U;
}

static real_T c3_abs(SFc3_ManipulatorME4901InstanceStruct *chartInstance, real_T
                     c3_x)
{
  real_T c3_b_x;
  c3_b_x = c3_x;
  return muDoubleScalarAbs(c3_b_x);
}

static real_T c3_mpower(SFc3_ManipulatorME4901InstanceStruct *chartInstance,
  real_T c3_a)
{
  real_T c3_b_a;
  real_T c3_c_a;
  real_T c3_ak;
  real_T c3_d_a;
  real_T c3_e_a;
  real_T c3_b;
  c3_b_a = c3_a;
  c3_c_a = c3_b_a;
  c3_eml_scalar_eg(chartInstance);
  c3_ak = c3_c_a;
  c3_d_a = c3_ak;
  c3_eml_scalar_eg(chartInstance);
  c3_e_a = c3_d_a;
  c3_b = c3_d_a;
  return c3_e_a * c3_b;
}

static void c3_eml_scalar_eg(SFc3_ManipulatorME4901InstanceStruct *chartInstance)
{
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc3_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_f_emlrt_marshallIn(SFc3_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i27;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i27, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i27;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc3_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_ManipulatorME4901, const
  char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_ManipulatorME4901), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_ManipulatorME4901);
  return c3_y;
}

static uint8_T c3_h_emlrt_marshallIn(SFc3_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_ManipulatorME4901InstanceStruct
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

void sf_c3_ManipulatorME4901_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2821364122U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1757459990U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3205845015U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3472464457U);
}

mxArray *sf_c3_ManipulatorME4901_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("RJe3UHVmsmgoRfSj8DblbG");
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

mxArray *sf_c3_ManipulatorME4901_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c3_ManipulatorME4901(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[8],T\"C\",},{M[1],M[12],T\"q_dot\",},{M[8],M[0],T\"is_active_c3_ManipulatorME4901\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_ManipulatorME4901_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_ManipulatorME4901InstanceStruct *chartInstance;
    chartInstance = (SFc3_ManipulatorME4901InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ManipulatorME4901MachineNumber_,
           3,
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
          _SFD_SET_DATA_PROPS(2,10,0,0,"m");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,16722);
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
            1.0,0,0,(MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)
            c3_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)c3_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)c3_c_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        {
          real_T (*c3_qqd)[9];
          real_T (*c3_C)[9];
          real_T (*c3_q_dot)[3];
          c3_q_dot = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c3_C = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c3_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c3_qqd);
          _SFD_SET_DATA_VALUE_PTR(1U, *c3_C);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c3_m);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c3_l);
          _SFD_SET_DATA_VALUE_PTR(4U, *c3_q_dot);
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
  return "8Te0ySh4TOH0jimSK39k5C";
}

static void sf_opaque_initialize_c3_ManipulatorME4901(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_ManipulatorME4901InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_ManipulatorME4901((SFc3_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
  initialize_c3_ManipulatorME4901((SFc3_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_ManipulatorME4901(void *chartInstanceVar)
{
  enable_c3_ManipulatorME4901((SFc3_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_ManipulatorME4901(void *chartInstanceVar)
{
  disable_c3_ManipulatorME4901((SFc3_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_ManipulatorME4901(void *chartInstanceVar)
{
  sf_c3_ManipulatorME4901((SFc3_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_ManipulatorME4901(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_ManipulatorME4901
    ((SFc3_ManipulatorME4901InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_ManipulatorME4901();/* state var info */
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

extern void sf_internal_set_sim_state_c3_ManipulatorME4901(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_ManipulatorME4901();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_ManipulatorME4901((SFc3_ManipulatorME4901InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_ManipulatorME4901(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_ManipulatorME4901(S);
}

static void sf_opaque_set_sim_state_c3_ManipulatorME4901(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c3_ManipulatorME4901(S, st);
}

static void sf_opaque_terminate_c3_ManipulatorME4901(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_ManipulatorME4901InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ManipulatorME4901_optimization_info();
    }

    finalize_c3_ManipulatorME4901((SFc3_ManipulatorME4901InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_ManipulatorME4901((SFc3_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_ManipulatorME4901(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_ManipulatorME4901((SFc3_ManipulatorME4901InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_ManipulatorME4901(SimStruct *S)
{
  /* Actual parameters from chart:
     l m
   */
  const char_T *rtParamNames[] = { "l", "m" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for l*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for m*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ManipulatorME4901_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(104924794U));
  ssSetChecksum1(S,(2671152133U));
  ssSetChecksum2(S,(4225628533U));
  ssSetChecksum3(S,(188903199U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_ManipulatorME4901(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_ManipulatorME4901(SimStruct *S)
{
  SFc3_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc3_ManipulatorME4901InstanceStruct *)utMalloc(sizeof
    (SFc3_ManipulatorME4901InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_ManipulatorME4901InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_ManipulatorME4901;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_ManipulatorME4901;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_ManipulatorME4901;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_ManipulatorME4901;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_ManipulatorME4901;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_ManipulatorME4901;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_ManipulatorME4901;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_ManipulatorME4901;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_ManipulatorME4901;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_ManipulatorME4901;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_ManipulatorME4901;
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

void c3_ManipulatorME4901_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_ManipulatorME4901(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_ManipulatorME4901(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_ManipulatorME4901(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_ManipulatorME4901_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
