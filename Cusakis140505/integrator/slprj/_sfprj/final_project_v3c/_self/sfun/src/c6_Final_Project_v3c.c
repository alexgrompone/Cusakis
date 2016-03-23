/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Final_Project_v3c_sfun.h"
#include "c6_Final_Project_v3c.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Final_Project_v3c_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c6_debug_family_names[17] = { "q", "I", "Jp1", "Jo1", "Jp2",
  "Jo2", "Jp3", "Jo3", "H1", "H2", "H3", "nargin", "nargout", "qqd", "l", "m",
  "H" };

/* Function Declarations */
static void initialize_c6_Final_Project_v3c(SFc6_Final_Project_v3cInstanceStruct
  *chartInstance);
static void initialize_params_c6_Final_Project_v3c
  (SFc6_Final_Project_v3cInstanceStruct *chartInstance);
static void enable_c6_Final_Project_v3c(SFc6_Final_Project_v3cInstanceStruct
  *chartInstance);
static void disable_c6_Final_Project_v3c(SFc6_Final_Project_v3cInstanceStruct
  *chartInstance);
static void c6_update_debugger_state_c6_Final_Project_v3c
  (SFc6_Final_Project_v3cInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_Final_Project_v3c
  (SFc6_Final_Project_v3cInstanceStruct *chartInstance);
static void set_sim_state_c6_Final_Project_v3c
  (SFc6_Final_Project_v3cInstanceStruct *chartInstance, const mxArray *c6_st);
static void finalize_c6_Final_Project_v3c(SFc6_Final_Project_v3cInstanceStruct
  *chartInstance);
static void sf_c6_Final_Project_v3c(SFc6_Final_Project_v3cInstanceStruct
  *chartInstance);
static void c6_chartstep_c6_Final_Project_v3c
  (SFc6_Final_Project_v3cInstanceStruct *chartInstance);
static void initSimStructsc6_Final_Project_v3c
  (SFc6_Final_Project_v3cInstanceStruct *chartInstance);
static void registerMessagesc6_Final_Project_v3c
  (SFc6_Final_Project_v3cInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static void c6_emlrt_marshallIn(SFc6_Final_Project_v3cInstanceStruct
  *chartInstance, const mxArray *c6_H, const char_T *c6_identifier, real_T c6_y
  [9]);
static void c6_b_emlrt_marshallIn(SFc6_Final_Project_v3cInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[9]);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_c_emlrt_marshallIn(SFc6_Final_Project_v3cInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_d_emlrt_marshallIn(SFc6_Final_Project_v3cInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[3]);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[25]);
static real_T c6_mpower(SFc6_Final_Project_v3cInstanceStruct *chartInstance,
  real_T c6_a);
static void c6_eml_scalar_eg(SFc6_Final_Project_v3cInstanceStruct *chartInstance);
static void c6_b_eml_scalar_eg(SFc6_Final_Project_v3cInstanceStruct
  *chartInstance);
static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_e_emlrt_marshallIn(SFc6_Final_Project_v3cInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint8_T c6_f_emlrt_marshallIn(SFc6_Final_Project_v3cInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_Final_Project_v3c, const
  char_T *c6_identifier);
static uint8_T c6_g_emlrt_marshallIn(SFc6_Final_Project_v3cInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void init_dsm_address_info(SFc6_Final_Project_v3cInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c6_Final_Project_v3c(SFc6_Final_Project_v3cInstanceStruct
  *chartInstance)
{
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c6_is_active_c6_Final_Project_v3c = 0U;
}

static void initialize_params_c6_Final_Project_v3c
  (SFc6_Final_Project_v3cInstanceStruct *chartInstance)
{
  real_T c6_d0;
  real_T c6_d1;
  sf_set_error_prefix_string(
    "Error evaluating data 'l' in the parent workspace.\n");
  sf_mex_import_named("l", sf_mex_get_sfun_param(chartInstance->S, 0, 0), &c6_d0,
                      0, 0, 0U, 0, 0U, 0);
  chartInstance->c6_l = c6_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'm' in the parent workspace.\n");
  sf_mex_import_named("m", sf_mex_get_sfun_param(chartInstance->S, 1, 0), &c6_d1,
                      0, 0, 0U, 0, 0U, 0);
  chartInstance->c6_m = c6_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c6_Final_Project_v3c(SFc6_Final_Project_v3cInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c6_Final_Project_v3c(SFc6_Final_Project_v3cInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c6_update_debugger_state_c6_Final_Project_v3c
  (SFc6_Final_Project_v3cInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c6_Final_Project_v3c
  (SFc6_Final_Project_v3cInstanceStruct *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  int32_T c6_i0;
  real_T c6_u[9];
  const mxArray *c6_b_y = NULL;
  uint8_T c6_hoistedGlobal;
  uint8_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  real_T (*c6_H)[9];
  c6_H = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellarray(2), FALSE);
  for (c6_i0 = 0; c6_i0 < 9; c6_i0++) {
    c6_u[c6_i0] = (*c6_H)[c6_i0];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_hoistedGlobal = chartInstance->c6_is_active_c6_Final_Project_v3c;
  c6_b_u = c6_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  sf_mex_assign(&c6_st, c6_y, FALSE);
  return c6_st;
}

static void set_sim_state_c6_Final_Project_v3c
  (SFc6_Final_Project_v3cInstanceStruct *chartInstance, const mxArray *c6_st)
{
  const mxArray *c6_u;
  real_T c6_dv0[9];
  int32_T c6_i1;
  real_T (*c6_H)[9];
  c6_H = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c6_doneDoubleBufferReInit = TRUE;
  c6_u = sf_mex_dup(c6_st);
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)), "H",
                      c6_dv0);
  for (c6_i1 = 0; c6_i1 < 9; c6_i1++) {
    (*c6_H)[c6_i1] = c6_dv0[c6_i1];
  }

  chartInstance->c6_is_active_c6_Final_Project_v3c = c6_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 1)),
     "is_active_c6_Final_Project_v3c");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_Final_Project_v3c(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_Final_Project_v3c(SFc6_Final_Project_v3cInstanceStruct
  *chartInstance)
{
}

static void sf_c6_Final_Project_v3c(SFc6_Final_Project_v3cInstanceStruct
  *chartInstance)
{
  int32_T c6_i2;
  int32_T c6_i3;
  real_T (*c6_qqd)[9];
  real_T (*c6_H)[9];
  c6_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  c6_H = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  for (c6_i2 = 0; c6_i2 < 9; c6_i2++) {
    _SFD_DATA_RANGE_CHECK((*c6_H)[c6_i2], 0U);
  }

  for (c6_i3 = 0; c6_i3 < 9; c6_i3++) {
    _SFD_DATA_RANGE_CHECK((*c6_qqd)[c6_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c6_l, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c6_m, 3U);
  chartInstance->c6_sfEvent = CALL_EVENT;
  c6_chartstep_c6_Final_Project_v3c(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Final_Project_v3cMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c6_chartstep_c6_Final_Project_v3c
  (SFc6_Final_Project_v3cInstanceStruct *chartInstance)
{
  real_T c6_hoistedGlobal;
  real_T c6_b_hoistedGlobal;
  int32_T c6_i4;
  real_T c6_qqd[9];
  real_T c6_b_l;
  real_T c6_b_m;
  uint32_T c6_debug_family_var_map[17];
  real_T c6_q[3];
  real_T c6_I;
  real_T c6_Jp1[9];
  real_T c6_Jo1[9];
  real_T c6_Jp2[9];
  real_T c6_Jo2[9];
  real_T c6_Jp3[9];
  real_T c6_Jo3[9];
  real_T c6_H1[9];
  real_T c6_H2[9];
  real_T c6_H3[9];
  real_T c6_nargin = 3.0;
  real_T c6_nargout = 1.0;
  real_T c6_H[9];
  real_T c6_b;
  real_T c6_y;
  real_T c6_a;
  real_T c6_b_b;
  real_T c6_A;
  real_T c6_x;
  real_T c6_b_x;
  real_T c6_b_y;
  real_T c6_c_x;
  real_T c6_d_x;
  real_T c6_b_a;
  real_T c6_c_b;
  real_T c6_c_y;
  real_T c6_b_A;
  real_T c6_e_x;
  real_T c6_f_x;
  real_T c6_d_y;
  real_T c6_g_x;
  real_T c6_h_x;
  real_T c6_c_a;
  real_T c6_d_b;
  real_T c6_e_y;
  int32_T c6_i5;
  int32_T c6_i6;
  int32_T c6_i7;
  static real_T c6_e_b[9] = { 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  real_T c6_i_x;
  real_T c6_j_x;
  real_T c6_d_a;
  real_T c6_f_b;
  real_T c6_f_y;
  real_T c6_c_A;
  real_T c6_k_x;
  real_T c6_l_x;
  real_T c6_g_y;
  real_T c6_m_x;
  real_T c6_n_x;
  real_T c6_e_a;
  real_T c6_g_b;
  real_T c6_h_y;
  real_T c6_d_A;
  real_T c6_o_x;
  real_T c6_p_x;
  real_T c6_i_y;
  real_T c6_q_x;
  real_T c6_r_x;
  real_T c6_f_a;
  real_T c6_h_b;
  real_T c6_j_y;
  real_T c6_s_x;
  real_T c6_t_x;
  real_T c6_g_a;
  real_T c6_i_b;
  real_T c6_k_y;
  real_T c6_e_A;
  real_T c6_u_x;
  real_T c6_v_x;
  real_T c6_l_y;
  real_T c6_w_x;
  real_T c6_x_x;
  real_T c6_h_a;
  real_T c6_j_b;
  real_T c6_m_y;
  real_T c6_f_A;
  real_T c6_y_x;
  real_T c6_ab_x;
  real_T c6_n_y;
  real_T c6_bb_x;
  real_T c6_cb_x;
  real_T c6_i_a;
  real_T c6_k_b;
  real_T c6_o_y;
  int32_T c6_i8;
  int32_T c6_i9;
  int32_T c6_i10;
  static real_T c6_l_b[9] = { 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0 };

  real_T c6_db_x;
  real_T c6_eb_x;
  real_T c6_j_a;
  real_T c6_m_b;
  real_T c6_p_y;
  real_T c6_fb_x;
  real_T c6_gb_x;
  real_T c6_k_a;
  real_T c6_n_b;
  real_T c6_q_y;
  real_T c6_g_A;
  real_T c6_hb_x;
  real_T c6_ib_x;
  real_T c6_r_y;
  real_T c6_jb_x;
  real_T c6_kb_x;
  real_T c6_l_a;
  real_T c6_o_b;
  real_T c6_s_y;
  real_T c6_lb_x;
  real_T c6_mb_x;
  real_T c6_m_a;
  real_T c6_p_b;
  real_T c6_t_y;
  real_T c6_h_A;
  real_T c6_nb_x;
  real_T c6_ob_x;
  real_T c6_u_y;
  real_T c6_pb_x;
  real_T c6_qb_x;
  real_T c6_n_a;
  real_T c6_q_b;
  real_T c6_v_y;
  real_T c6_i_A;
  real_T c6_rb_x;
  real_T c6_sb_x;
  real_T c6_w_y;
  real_T c6_tb_x;
  real_T c6_ub_x;
  real_T c6_o_a;
  real_T c6_r_b;
  real_T c6_x_y;
  real_T c6_vb_x;
  real_T c6_wb_x;
  real_T c6_p_a;
  real_T c6_s_b;
  real_T c6_y_y;
  real_T c6_xb_x;
  real_T c6_yb_x;
  real_T c6_q_a;
  real_T c6_t_b;
  real_T c6_ab_y;
  real_T c6_j_A;
  real_T c6_ac_x;
  real_T c6_bc_x;
  real_T c6_bb_y;
  real_T c6_cc_x;
  real_T c6_dc_x;
  real_T c6_r_a;
  real_T c6_u_b;
  real_T c6_cb_y;
  real_T c6_ec_x;
  real_T c6_fc_x;
  real_T c6_s_a;
  real_T c6_v_b;
  real_T c6_db_y;
  real_T c6_k_A;
  real_T c6_gc_x;
  real_T c6_hc_x;
  real_T c6_eb_y;
  real_T c6_ic_x;
  real_T c6_jc_x;
  real_T c6_t_a;
  real_T c6_w_b;
  real_T c6_fb_y;
  real_T c6_l_A;
  real_T c6_kc_x;
  real_T c6_lc_x;
  real_T c6_gb_y;
  real_T c6_mc_x;
  real_T c6_nc_x;
  real_T c6_u_a;
  real_T c6_x_b;
  real_T c6_hb_y;
  int32_T c6_i11;
  int32_T c6_i12;
  int32_T c6_i13;
  static real_T c6_y_b[9] = { 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0 };

  real_T c6_v_a;
  int32_T c6_i14;
  int32_T c6_i15;
  int32_T c6_i16;
  int32_T c6_i17;
  real_T c6_ab_b[9];
  int32_T c6_i18;
  int32_T c6_i19;
  real_T c6_bb_b[9];
  int32_T c6_i20;
  int32_T c6_i21;
  int32_T c6_i22;
  real_T c6_ib_y[9];
  int32_T c6_i23;
  int32_T c6_i24;
  real_T c6_cb_b;
  int32_T c6_i25;
  static real_T c6_w_a[9] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0 };

  int32_T c6_i26;
  int32_T c6_i27;
  int32_T c6_i28;
  int32_T c6_i29;
  int32_T c6_i30;
  int32_T c6_i31;
  real_T c6_x_a;
  int32_T c6_i32;
  int32_T c6_i33;
  int32_T c6_i34;
  int32_T c6_i35;
  int32_T c6_i36;
  int32_T c6_i37;
  int32_T c6_i38;
  int32_T c6_i39;
  int32_T c6_i40;
  int32_T c6_i41;
  int32_T c6_i42;
  real_T c6_db_b;
  int32_T c6_i43;
  static real_T c6_y_a[9] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0 };

  int32_T c6_i44;
  int32_T c6_i45;
  int32_T c6_i46;
  int32_T c6_i47;
  int32_T c6_i48;
  int32_T c6_i49;
  real_T c6_ab_a;
  int32_T c6_i50;
  int32_T c6_i51;
  int32_T c6_i52;
  int32_T c6_i53;
  int32_T c6_i54;
  int32_T c6_i55;
  int32_T c6_i56;
  int32_T c6_i57;
  int32_T c6_i58;
  int32_T c6_i59;
  int32_T c6_i60;
  real_T c6_eb_b;
  int32_T c6_i61;
  static real_T c6_bb_a[9] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0 };

  int32_T c6_i62;
  int32_T c6_i63;
  int32_T c6_i64;
  int32_T c6_i65;
  int32_T c6_i66;
  int32_T c6_i67;
  int32_T c6_i68;
  int32_T c6_i69;
  real_T (*c6_b_H)[9];
  real_T (*c6_b_qqd)[9];
  c6_b_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  c6_b_H = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  c6_hoistedGlobal = chartInstance->c6_l;
  c6_b_hoistedGlobal = chartInstance->c6_m;
  for (c6_i4 = 0; c6_i4 < 9; c6_i4++) {
    c6_qqd[c6_i4] = (*c6_b_qqd)[c6_i4];
  }

  c6_b_l = c6_hoistedGlobal;
  c6_b_m = c6_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 17U, 17U, c6_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_q, 0U, c6_d_sf_marshallOut,
    c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_I, 1U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_Jp1, 2U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_Jo1, 3U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_Jp2, 4U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_Jo2, 5U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_Jp3, 6U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_Jo3, 7U, c6_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_H1, 8U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_H2, 9U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_H3, 10U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 11U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 12U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_qqd, 13U, c6_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_l, 14U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_m, 15U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_H, 16U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 3);
  c6_q[0] = c6_qqd[6];
  c6_q[1] = c6_qqd[7];
  c6_q[2] = c6_qqd[8];
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_b = c6_b_m;
  c6_y = 0.083333333333333329 * c6_b;
  c6_a = c6_y;
  c6_b_b = c6_mpower(chartInstance, c6_b_l);
  c6_I = c6_a * c6_b_b;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 6);
  c6_A = c6_b_l;
  c6_x = c6_A;
  c6_b_x = c6_x;
  c6_b_y = c6_b_x / 2.0;
  c6_c_x = c6_q[0];
  c6_d_x = c6_c_x;
  c6_d_x = muDoubleScalarSin(c6_d_x);
  c6_b_a = -c6_b_y;
  c6_c_b = c6_d_x;
  c6_c_y = c6_b_a * c6_c_b;
  c6_b_A = c6_b_l;
  c6_e_x = c6_b_A;
  c6_f_x = c6_e_x;
  c6_d_y = c6_f_x / 2.0;
  c6_g_x = c6_q[0];
  c6_h_x = c6_g_x;
  c6_h_x = muDoubleScalarCos(c6_h_x);
  c6_c_a = c6_d_y;
  c6_d_b = c6_h_x;
  c6_e_y = c6_c_a * c6_d_b;
  c6_Jp1[0] = c6_c_y;
  c6_Jp1[3] = 0.0;
  c6_Jp1[6] = 0.0;
  c6_Jp1[1] = c6_e_y;
  c6_Jp1[4] = 0.0;
  c6_Jp1[7] = 0.0;
  c6_i5 = 0;
  for (c6_i6 = 0; c6_i6 < 3; c6_i6++) {
    c6_Jp1[c6_i5 + 2] = 0.0;
    c6_i5 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 7);
  for (c6_i7 = 0; c6_i7 < 9; c6_i7++) {
    c6_Jo1[c6_i7] = c6_e_b[c6_i7];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 9);
  c6_i_x = c6_q[0];
  c6_j_x = c6_i_x;
  c6_j_x = muDoubleScalarSin(c6_j_x);
  c6_d_a = -c6_b_l;
  c6_f_b = c6_j_x;
  c6_f_y = c6_d_a * c6_f_b;
  c6_c_A = c6_b_l;
  c6_k_x = c6_c_A;
  c6_l_x = c6_k_x;
  c6_g_y = c6_l_x / 2.0;
  c6_m_x = c6_q[0] + c6_q[1];
  c6_n_x = c6_m_x;
  c6_n_x = muDoubleScalarSin(c6_n_x);
  c6_e_a = c6_g_y;
  c6_g_b = c6_n_x;
  c6_h_y = c6_e_a * c6_g_b;
  c6_d_A = c6_b_l;
  c6_o_x = c6_d_A;
  c6_p_x = c6_o_x;
  c6_i_y = c6_p_x / 2.0;
  c6_q_x = c6_q[0] + c6_q[1];
  c6_r_x = c6_q_x;
  c6_r_x = muDoubleScalarSin(c6_r_x);
  c6_f_a = -c6_i_y;
  c6_h_b = c6_r_x;
  c6_j_y = c6_f_a * c6_h_b;
  c6_s_x = c6_q[0];
  c6_t_x = c6_s_x;
  c6_t_x = muDoubleScalarCos(c6_t_x);
  c6_g_a = c6_b_l;
  c6_i_b = c6_t_x;
  c6_k_y = c6_g_a * c6_i_b;
  c6_e_A = c6_b_l;
  c6_u_x = c6_e_A;
  c6_v_x = c6_u_x;
  c6_l_y = c6_v_x / 2.0;
  c6_w_x = c6_q[0] + c6_q[1];
  c6_x_x = c6_w_x;
  c6_x_x = muDoubleScalarCos(c6_x_x);
  c6_h_a = c6_l_y;
  c6_j_b = c6_x_x;
  c6_m_y = c6_h_a * c6_j_b;
  c6_f_A = c6_b_l;
  c6_y_x = c6_f_A;
  c6_ab_x = c6_y_x;
  c6_n_y = c6_ab_x / 2.0;
  c6_bb_x = c6_q[0] + c6_q[1];
  c6_cb_x = c6_bb_x;
  c6_cb_x = muDoubleScalarCos(c6_cb_x);
  c6_i_a = c6_n_y;
  c6_k_b = c6_cb_x;
  c6_o_y = c6_i_a * c6_k_b;
  c6_Jp2[0] = c6_f_y - c6_h_y;
  c6_Jp2[3] = c6_j_y;
  c6_Jp2[6] = 0.0;
  c6_Jp2[1] = c6_k_y + c6_m_y;
  c6_Jp2[4] = c6_o_y;
  c6_Jp2[7] = 0.0;
  c6_i8 = 0;
  for (c6_i9 = 0; c6_i9 < 3; c6_i9++) {
    c6_Jp2[c6_i8 + 2] = 0.0;
    c6_i8 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 10);
  for (c6_i10 = 0; c6_i10 < 9; c6_i10++) {
    c6_Jo2[c6_i10] = c6_l_b[c6_i10];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 12);
  c6_db_x = c6_q[0];
  c6_eb_x = c6_db_x;
  c6_eb_x = muDoubleScalarSin(c6_eb_x);
  c6_j_a = -c6_b_l;
  c6_m_b = c6_eb_x;
  c6_p_y = c6_j_a * c6_m_b;
  c6_fb_x = c6_q[0] + c6_q[1];
  c6_gb_x = c6_fb_x;
  c6_gb_x = muDoubleScalarSin(c6_gb_x);
  c6_k_a = c6_b_l;
  c6_n_b = c6_gb_x;
  c6_q_y = c6_k_a * c6_n_b;
  c6_g_A = c6_b_l;
  c6_hb_x = c6_g_A;
  c6_ib_x = c6_hb_x;
  c6_r_y = c6_ib_x / 2.0;
  c6_jb_x = (c6_q[0] + c6_q[1]) + c6_q[2];
  c6_kb_x = c6_jb_x;
  c6_kb_x = muDoubleScalarSin(c6_kb_x);
  c6_l_a = c6_r_y;
  c6_o_b = c6_kb_x;
  c6_s_y = c6_l_a * c6_o_b;
  c6_lb_x = c6_q[0] + c6_q[1];
  c6_mb_x = c6_lb_x;
  c6_mb_x = muDoubleScalarSin(c6_mb_x);
  c6_m_a = -c6_b_l;
  c6_p_b = c6_mb_x;
  c6_t_y = c6_m_a * c6_p_b;
  c6_h_A = c6_b_l;
  c6_nb_x = c6_h_A;
  c6_ob_x = c6_nb_x;
  c6_u_y = c6_ob_x / 2.0;
  c6_pb_x = (c6_q[0] + c6_q[1]) + c6_q[2];
  c6_qb_x = c6_pb_x;
  c6_qb_x = muDoubleScalarSin(c6_qb_x);
  c6_n_a = c6_u_y;
  c6_q_b = c6_qb_x;
  c6_v_y = c6_n_a * c6_q_b;
  c6_i_A = c6_b_l;
  c6_rb_x = c6_i_A;
  c6_sb_x = c6_rb_x;
  c6_w_y = c6_sb_x / 2.0;
  c6_tb_x = (c6_q[0] + c6_q[1]) + c6_q[2];
  c6_ub_x = c6_tb_x;
  c6_ub_x = muDoubleScalarSin(c6_ub_x);
  c6_o_a = -c6_w_y;
  c6_r_b = c6_ub_x;
  c6_x_y = c6_o_a * c6_r_b;
  c6_vb_x = c6_q[0];
  c6_wb_x = c6_vb_x;
  c6_wb_x = muDoubleScalarCos(c6_wb_x);
  c6_p_a = c6_b_l;
  c6_s_b = c6_wb_x;
  c6_y_y = c6_p_a * c6_s_b;
  c6_xb_x = c6_q[0] + c6_q[1];
  c6_yb_x = c6_xb_x;
  c6_yb_x = muDoubleScalarCos(c6_yb_x);
  c6_q_a = c6_b_l;
  c6_t_b = c6_yb_x;
  c6_ab_y = c6_q_a * c6_t_b;
  c6_j_A = c6_b_l;
  c6_ac_x = c6_j_A;
  c6_bc_x = c6_ac_x;
  c6_bb_y = c6_bc_x / 2.0;
  c6_cc_x = (c6_q[0] + c6_q[1]) + c6_q[2];
  c6_dc_x = c6_cc_x;
  c6_dc_x = muDoubleScalarCos(c6_dc_x);
  c6_r_a = c6_bb_y;
  c6_u_b = c6_dc_x;
  c6_cb_y = c6_r_a * c6_u_b;
  c6_ec_x = c6_q[0] + c6_q[1];
  c6_fc_x = c6_ec_x;
  c6_fc_x = muDoubleScalarCos(c6_fc_x);
  c6_s_a = c6_b_l;
  c6_v_b = c6_fc_x;
  c6_db_y = c6_s_a * c6_v_b;
  c6_k_A = c6_b_l;
  c6_gc_x = c6_k_A;
  c6_hc_x = c6_gc_x;
  c6_eb_y = c6_hc_x / 2.0;
  c6_ic_x = (c6_q[0] + c6_q[1]) + c6_q[2];
  c6_jc_x = c6_ic_x;
  c6_jc_x = muDoubleScalarCos(c6_jc_x);
  c6_t_a = c6_eb_y;
  c6_w_b = c6_jc_x;
  c6_fb_y = c6_t_a * c6_w_b;
  c6_l_A = c6_b_l;
  c6_kc_x = c6_l_A;
  c6_lc_x = c6_kc_x;
  c6_gb_y = c6_lc_x / 2.0;
  c6_mc_x = (c6_q[0] + c6_q[1]) + c6_q[2];
  c6_nc_x = c6_mc_x;
  c6_nc_x = muDoubleScalarCos(c6_nc_x);
  c6_u_a = c6_gb_y;
  c6_x_b = c6_nc_x;
  c6_hb_y = c6_u_a * c6_x_b;
  c6_Jp3[0] = (c6_p_y - c6_q_y) - c6_s_y;
  c6_Jp3[3] = c6_t_y - c6_v_y;
  c6_Jp3[6] = c6_x_y;
  c6_Jp3[1] = (c6_y_y + c6_ab_y) + c6_cb_y;
  c6_Jp3[4] = c6_db_y + c6_fb_y;
  c6_Jp3[7] = c6_hb_y;
  c6_i11 = 0;
  for (c6_i12 = 0; c6_i12 < 3; c6_i12++) {
    c6_Jp3[c6_i11 + 2] = 0.0;
    c6_i11 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 13);
  for (c6_i13 = 0; c6_i13 < 9; c6_i13++) {
    c6_Jo3[c6_i13] = c6_y_b[c6_i13];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 17);
  c6_v_a = c6_b_m;
  c6_i14 = 0;
  for (c6_i15 = 0; c6_i15 < 3; c6_i15++) {
    c6_i16 = 0;
    for (c6_i17 = 0; c6_i17 < 3; c6_i17++) {
      c6_ab_b[c6_i17 + c6_i14] = c6_Jp1[c6_i16 + c6_i15];
      c6_i16 += 3;
    }

    c6_i14 += 3;
  }

  for (c6_i18 = 0; c6_i18 < 9; c6_i18++) {
    c6_ab_b[c6_i18] *= c6_v_a;
  }

  for (c6_i19 = 0; c6_i19 < 9; c6_i19++) {
    c6_bb_b[c6_i19] = c6_Jp1[c6_i19];
  }

  c6_b_eml_scalar_eg(chartInstance);
  c6_b_eml_scalar_eg(chartInstance);
  for (c6_i20 = 0; c6_i20 < 3; c6_i20++) {
    c6_i21 = 0;
    for (c6_i22 = 0; c6_i22 < 3; c6_i22++) {
      c6_ib_y[c6_i21 + c6_i20] = 0.0;
      c6_i23 = 0;
      for (c6_i24 = 0; c6_i24 < 3; c6_i24++) {
        c6_ib_y[c6_i21 + c6_i20] += c6_ab_b[c6_i23 + c6_i20] * c6_bb_b[c6_i24 +
          c6_i21];
        c6_i23 += 3;
      }

      c6_i21 += 3;
    }
  }

  c6_cb_b = c6_I;
  for (c6_i25 = 0; c6_i25 < 9; c6_i25++) {
    c6_ab_b[c6_i25] = c6_w_a[c6_i25] * c6_cb_b;
  }

  c6_b_eml_scalar_eg(chartInstance);
  c6_b_eml_scalar_eg(chartInstance);
  for (c6_i26 = 0; c6_i26 < 3; c6_i26++) {
    c6_i27 = 0;
    for (c6_i28 = 0; c6_i28 < 3; c6_i28++) {
      c6_bb_b[c6_i27 + c6_i26] = 0.0;
      c6_i29 = 0;
      for (c6_i30 = 0; c6_i30 < 3; c6_i30++) {
        c6_bb_b[c6_i27 + c6_i26] += c6_ab_b[c6_i29 + c6_i26] * c6_e_b[c6_i30 +
          c6_i27];
        c6_i29 += 3;
      }

      c6_i27 += 3;
    }
  }

  for (c6_i31 = 0; c6_i31 < 9; c6_i31++) {
    c6_H1[c6_i31] = c6_ib_y[c6_i31] + c6_bb_b[c6_i31];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 18);
  c6_x_a = c6_b_m;
  c6_i32 = 0;
  for (c6_i33 = 0; c6_i33 < 3; c6_i33++) {
    c6_i34 = 0;
    for (c6_i35 = 0; c6_i35 < 3; c6_i35++) {
      c6_ab_b[c6_i35 + c6_i32] = c6_Jp2[c6_i34 + c6_i33];
      c6_i34 += 3;
    }

    c6_i32 += 3;
  }

  for (c6_i36 = 0; c6_i36 < 9; c6_i36++) {
    c6_ab_b[c6_i36] *= c6_x_a;
  }

  for (c6_i37 = 0; c6_i37 < 9; c6_i37++) {
    c6_bb_b[c6_i37] = c6_Jp2[c6_i37];
  }

  c6_b_eml_scalar_eg(chartInstance);
  c6_b_eml_scalar_eg(chartInstance);
  for (c6_i38 = 0; c6_i38 < 3; c6_i38++) {
    c6_i39 = 0;
    for (c6_i40 = 0; c6_i40 < 3; c6_i40++) {
      c6_ib_y[c6_i39 + c6_i38] = 0.0;
      c6_i41 = 0;
      for (c6_i42 = 0; c6_i42 < 3; c6_i42++) {
        c6_ib_y[c6_i39 + c6_i38] += c6_ab_b[c6_i41 + c6_i38] * c6_bb_b[c6_i42 +
          c6_i39];
        c6_i41 += 3;
      }

      c6_i39 += 3;
    }
  }

  c6_db_b = c6_I;
  for (c6_i43 = 0; c6_i43 < 9; c6_i43++) {
    c6_ab_b[c6_i43] = c6_y_a[c6_i43] * c6_db_b;
  }

  c6_b_eml_scalar_eg(chartInstance);
  c6_b_eml_scalar_eg(chartInstance);
  for (c6_i44 = 0; c6_i44 < 3; c6_i44++) {
    c6_i45 = 0;
    for (c6_i46 = 0; c6_i46 < 3; c6_i46++) {
      c6_bb_b[c6_i45 + c6_i44] = 0.0;
      c6_i47 = 0;
      for (c6_i48 = 0; c6_i48 < 3; c6_i48++) {
        c6_bb_b[c6_i45 + c6_i44] += c6_ab_b[c6_i47 + c6_i44] * c6_l_b[c6_i48 +
          c6_i45];
        c6_i47 += 3;
      }

      c6_i45 += 3;
    }
  }

  for (c6_i49 = 0; c6_i49 < 9; c6_i49++) {
    c6_H2[c6_i49] = c6_ib_y[c6_i49] + c6_bb_b[c6_i49];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 19);
  c6_ab_a = c6_b_m;
  c6_i50 = 0;
  for (c6_i51 = 0; c6_i51 < 3; c6_i51++) {
    c6_i52 = 0;
    for (c6_i53 = 0; c6_i53 < 3; c6_i53++) {
      c6_ab_b[c6_i53 + c6_i50] = c6_Jp3[c6_i52 + c6_i51];
      c6_i52 += 3;
    }

    c6_i50 += 3;
  }

  for (c6_i54 = 0; c6_i54 < 9; c6_i54++) {
    c6_ab_b[c6_i54] *= c6_ab_a;
  }

  for (c6_i55 = 0; c6_i55 < 9; c6_i55++) {
    c6_bb_b[c6_i55] = c6_Jp3[c6_i55];
  }

  c6_b_eml_scalar_eg(chartInstance);
  c6_b_eml_scalar_eg(chartInstance);
  for (c6_i56 = 0; c6_i56 < 3; c6_i56++) {
    c6_i57 = 0;
    for (c6_i58 = 0; c6_i58 < 3; c6_i58++) {
      c6_ib_y[c6_i57 + c6_i56] = 0.0;
      c6_i59 = 0;
      for (c6_i60 = 0; c6_i60 < 3; c6_i60++) {
        c6_ib_y[c6_i57 + c6_i56] += c6_ab_b[c6_i59 + c6_i56] * c6_bb_b[c6_i60 +
          c6_i57];
        c6_i59 += 3;
      }

      c6_i57 += 3;
    }
  }

  c6_eb_b = c6_I;
  for (c6_i61 = 0; c6_i61 < 9; c6_i61++) {
    c6_ab_b[c6_i61] = c6_bb_a[c6_i61] * c6_eb_b;
  }

  c6_b_eml_scalar_eg(chartInstance);
  c6_b_eml_scalar_eg(chartInstance);
  for (c6_i62 = 0; c6_i62 < 3; c6_i62++) {
    c6_i63 = 0;
    for (c6_i64 = 0; c6_i64 < 3; c6_i64++) {
      c6_bb_b[c6_i63 + c6_i62] = 0.0;
      c6_i65 = 0;
      for (c6_i66 = 0; c6_i66 < 3; c6_i66++) {
        c6_bb_b[c6_i63 + c6_i62] += c6_ab_b[c6_i65 + c6_i62] * c6_y_b[c6_i66 +
          c6_i63];
        c6_i65 += 3;
      }

      c6_i63 += 3;
    }
  }

  for (c6_i67 = 0; c6_i67 < 9; c6_i67++) {
    c6_H3[c6_i67] = c6_ib_y[c6_i67] + c6_bb_b[c6_i67];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 21);
  for (c6_i68 = 0; c6_i68 < 9; c6_i68++) {
    c6_H[c6_i68] = (c6_H1[c6_i68] + c6_H2[c6_i68]) + c6_H3[c6_i68];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -21);
  _SFD_SYMBOL_SCOPE_POP();
  for (c6_i69 = 0; c6_i69 < 9; c6_i69++) {
    (*c6_b_H)[c6_i69] = c6_H[c6_i69];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
}

static void initSimStructsc6_Final_Project_v3c
  (SFc6_Final_Project_v3cInstanceStruct *chartInstance)
{
}

static void registerMessagesc6_Final_Project_v3c
  (SFc6_Final_Project_v3cInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber)
{
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i70;
  int32_T c6_i71;
  int32_T c6_i72;
  real_T c6_b_inData[9];
  int32_T c6_i73;
  int32_T c6_i74;
  int32_T c6_i75;
  real_T c6_u[9];
  const mxArray *c6_y = NULL;
  SFc6_Final_Project_v3cInstanceStruct *chartInstance;
  chartInstance = (SFc6_Final_Project_v3cInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i70 = 0;
  for (c6_i71 = 0; c6_i71 < 3; c6_i71++) {
    for (c6_i72 = 0; c6_i72 < 3; c6_i72++) {
      c6_b_inData[c6_i72 + c6_i70] = (*(real_T (*)[9])c6_inData)[c6_i72 + c6_i70];
    }

    c6_i70 += 3;
  }

  c6_i73 = 0;
  for (c6_i74 = 0; c6_i74 < 3; c6_i74++) {
    for (c6_i75 = 0; c6_i75 < 3; c6_i75++) {
      c6_u[c6_i75 + c6_i73] = c6_b_inData[c6_i75 + c6_i73];
    }

    c6_i73 += 3;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static void c6_emlrt_marshallIn(SFc6_Final_Project_v3cInstanceStruct
  *chartInstance, const mxArray *c6_H, const char_T *c6_identifier, real_T c6_y
  [9])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_H), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_H);
}

static void c6_b_emlrt_marshallIn(SFc6_Final_Project_v3cInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[9])
{
  real_T c6_dv1[9];
  int32_T c6_i76;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv1, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c6_i76 = 0; c6_i76 < 9; c6_i76++) {
    c6_y[c6_i76] = c6_dv1[c6_i76];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_H;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[9];
  int32_T c6_i77;
  int32_T c6_i78;
  int32_T c6_i79;
  SFc6_Final_Project_v3cInstanceStruct *chartInstance;
  chartInstance = (SFc6_Final_Project_v3cInstanceStruct *)chartInstanceVoid;
  c6_H = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_H), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_H);
  c6_i77 = 0;
  for (c6_i78 = 0; c6_i78 < 3; c6_i78++) {
    for (c6_i79 = 0; c6_i79 < 3; c6_i79++) {
      (*(real_T (*)[9])c6_outData)[c6_i79 + c6_i77] = c6_y[c6_i79 + c6_i77];
    }

    c6_i77 += 3;
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_Final_Project_v3cInstanceStruct *chartInstance;
  chartInstance = (SFc6_Final_Project_v3cInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_c_emlrt_marshallIn(SFc6_Final_Project_v3cInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d2;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d2, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d2;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_m;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_Final_Project_v3cInstanceStruct *chartInstance;
  chartInstance = (SFc6_Final_Project_v3cInstanceStruct *)chartInstanceVoid;
  c6_b_m = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_m), &c6_thisId);
  sf_mex_destroy(&c6_b_m);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i80;
  real_T c6_b_inData[9];
  int32_T c6_i81;
  real_T c6_u[9];
  const mxArray *c6_y = NULL;
  SFc6_Final_Project_v3cInstanceStruct *chartInstance;
  chartInstance = (SFc6_Final_Project_v3cInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i80 = 0; c6_i80 < 9; c6_i80++) {
    c6_b_inData[c6_i80] = (*(real_T (*)[9])c6_inData)[c6_i80];
  }

  for (c6_i81 = 0; c6_i81 < 9; c6_i81++) {
    c6_u[c6_i81] = c6_b_inData[c6_i81];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 9), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i82;
  real_T c6_b_inData[3];
  int32_T c6_i83;
  real_T c6_u[3];
  const mxArray *c6_y = NULL;
  SFc6_Final_Project_v3cInstanceStruct *chartInstance;
  chartInstance = (SFc6_Final_Project_v3cInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i82 = 0; c6_i82 < 3; c6_i82++) {
    c6_b_inData[c6_i82] = (*(real_T (*)[3])c6_inData)[c6_i82];
  }

  for (c6_i83 = 0; c6_i83 < 3; c6_i83++) {
    c6_u[c6_i83] = c6_b_inData[c6_i83];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 1, 3), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static void c6_d_emlrt_marshallIn(SFc6_Final_Project_v3cInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[3])
{
  real_T c6_dv2[3];
  int32_T c6_i84;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv2, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c6_i84 = 0; c6_i84 < 3; c6_i84++) {
    c6_y[c6_i84] = c6_dv2[c6_i84];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_q;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[3];
  int32_T c6_i85;
  SFc6_Final_Project_v3cInstanceStruct *chartInstance;
  chartInstance = (SFc6_Final_Project_v3cInstanceStruct *)chartInstanceVoid;
  c6_q = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_q), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_q);
  for (c6_i85 = 0; c6_i85 < 3; c6_i85++) {
    (*(real_T (*)[3])c6_outData)[c6_i85] = c6_y[c6_i85];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray *sf_c6_Final_Project_v3c_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo;
  c6_ResolvedFunctionInfo c6_info[25];
  const mxArray *c6_m0 = NULL;
  int32_T c6_i86;
  c6_ResolvedFunctionInfo *c6_r0;
  c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  c6_info_helper(c6_info);
  sf_mex_assign(&c6_m0, sf_mex_createstruct("nameCaptureInfo", 1, 25), FALSE);
  for (c6_i86 = 0; c6_i86 < 25; c6_i86++) {
    c6_r0 = &c6_info[c6_i86];
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->context)), "context", "nameCaptureInfo",
                    c6_i86);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c6_r0->name)), "name", "nameCaptureInfo", c6_i86);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c6_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c6_i86);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->resolved)), "resolved", "nameCaptureInfo",
                    c6_i86);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c6_i86);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c6_i86);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c6_i86);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c6_i86);
  }

  sf_mex_assign(&c6_nameCaptureInfo, c6_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c6_nameCaptureInfo);
  return c6_nameCaptureInfo;
}

static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[25])
{
  c6_info[0].context = "";
  c6_info[0].name = "mrdivide";
  c6_info[0].dominantType = "double";
  c6_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c6_info[0].fileTimeLo = 1357983948U;
  c6_info[0].fileTimeHi = 0U;
  c6_info[0].mFileTimeLo = 1319762366U;
  c6_info[0].mFileTimeHi = 0U;
  c6_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c6_info[1].name = "rdivide";
  c6_info[1].dominantType = "double";
  c6_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[1].fileTimeLo = 1346542788U;
  c6_info[1].fileTimeHi = 0U;
  c6_info[1].mFileTimeLo = 0U;
  c6_info[1].mFileTimeHi = 0U;
  c6_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[2].name = "eml_scalexp_compatible";
  c6_info[2].dominantType = "double";
  c6_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c6_info[2].fileTimeLo = 1286851196U;
  c6_info[2].fileTimeHi = 0U;
  c6_info[2].mFileTimeLo = 0U;
  c6_info[2].mFileTimeHi = 0U;
  c6_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[3].name = "eml_div";
  c6_info[3].dominantType = "double";
  c6_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c6_info[3].fileTimeLo = 1313380210U;
  c6_info[3].fileTimeHi = 0U;
  c6_info[3].mFileTimeLo = 0U;
  c6_info[3].mFileTimeHi = 0U;
  c6_info[4].context = "";
  c6_info[4].name = "mtimes";
  c6_info[4].dominantType = "double";
  c6_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[4].fileTimeLo = 1289552092U;
  c6_info[4].fileTimeHi = 0U;
  c6_info[4].mFileTimeLo = 0U;
  c6_info[4].mFileTimeHi = 0U;
  c6_info[5].context = "";
  c6_info[5].name = "mpower";
  c6_info[5].dominantType = "double";
  c6_info[5].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c6_info[5].fileTimeLo = 1286851242U;
  c6_info[5].fileTimeHi = 0U;
  c6_info[5].mFileTimeLo = 0U;
  c6_info[5].mFileTimeHi = 0U;
  c6_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c6_info[6].name = "power";
  c6_info[6].dominantType = "double";
  c6_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[6].fileTimeLo = 1348224330U;
  c6_info[6].fileTimeHi = 0U;
  c6_info[6].mFileTimeLo = 0U;
  c6_info[6].mFileTimeHi = 0U;
  c6_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c6_info[7].name = "eml_scalar_eg";
  c6_info[7].dominantType = "double";
  c6_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[7].fileTimeLo = 1286851196U;
  c6_info[7].fileTimeHi = 0U;
  c6_info[7].mFileTimeLo = 0U;
  c6_info[7].mFileTimeHi = 0U;
  c6_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c6_info[8].name = "eml_scalexp_alloc";
  c6_info[8].dominantType = "double";
  c6_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c6_info[8].fileTimeLo = 1352457260U;
  c6_info[8].fileTimeHi = 0U;
  c6_info[8].mFileTimeLo = 0U;
  c6_info[8].mFileTimeHi = 0U;
  c6_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c6_info[9].name = "floor";
  c6_info[9].dominantType = "double";
  c6_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c6_info[9].fileTimeLo = 1343862780U;
  c6_info[9].fileTimeHi = 0U;
  c6_info[9].mFileTimeLo = 0U;
  c6_info[9].mFileTimeHi = 0U;
  c6_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c6_info[10].name = "eml_scalar_floor";
  c6_info[10].dominantType = "double";
  c6_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c6_info[10].fileTimeLo = 1286851126U;
  c6_info[10].fileTimeHi = 0U;
  c6_info[10].mFileTimeLo = 0U;
  c6_info[10].mFileTimeHi = 0U;
  c6_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c6_info[11].name = "eml_scalar_eg";
  c6_info[11].dominantType = "double";
  c6_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[11].fileTimeLo = 1286851196U;
  c6_info[11].fileTimeHi = 0U;
  c6_info[11].mFileTimeLo = 0U;
  c6_info[11].mFileTimeHi = 0U;
  c6_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c6_info[12].name = "mtimes";
  c6_info[12].dominantType = "double";
  c6_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[12].fileTimeLo = 1289552092U;
  c6_info[12].fileTimeHi = 0U;
  c6_info[12].mFileTimeLo = 0U;
  c6_info[12].mFileTimeHi = 0U;
  c6_info[13].context = "";
  c6_info[13].name = "sin";
  c6_info[13].dominantType = "double";
  c6_info[13].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c6_info[13].fileTimeLo = 1343862786U;
  c6_info[13].fileTimeHi = 0U;
  c6_info[13].mFileTimeLo = 0U;
  c6_info[13].mFileTimeHi = 0U;
  c6_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c6_info[14].name = "eml_scalar_sin";
  c6_info[14].dominantType = "double";
  c6_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c6_info[14].fileTimeLo = 1286851136U;
  c6_info[14].fileTimeHi = 0U;
  c6_info[14].mFileTimeLo = 0U;
  c6_info[14].mFileTimeHi = 0U;
  c6_info[15].context = "";
  c6_info[15].name = "cos";
  c6_info[15].dominantType = "double";
  c6_info[15].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c6_info[15].fileTimeLo = 1343862772U;
  c6_info[15].fileTimeHi = 0U;
  c6_info[15].mFileTimeLo = 0U;
  c6_info[15].mFileTimeHi = 0U;
  c6_info[16].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c6_info[16].name = "eml_scalar_cos";
  c6_info[16].dominantType = "double";
  c6_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c6_info[16].fileTimeLo = 1286851122U;
  c6_info[16].fileTimeHi = 0U;
  c6_info[16].mFileTimeLo = 0U;
  c6_info[16].mFileTimeHi = 0U;
  c6_info[17].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[17].name = "eml_index_class";
  c6_info[17].dominantType = "";
  c6_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[17].fileTimeLo = 1323202978U;
  c6_info[17].fileTimeHi = 0U;
  c6_info[17].mFileTimeLo = 0U;
  c6_info[17].mFileTimeHi = 0U;
  c6_info[18].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[18].name = "eml_scalar_eg";
  c6_info[18].dominantType = "double";
  c6_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[18].fileTimeLo = 1286851196U;
  c6_info[18].fileTimeHi = 0U;
  c6_info[18].mFileTimeLo = 0U;
  c6_info[18].mFileTimeHi = 0U;
  c6_info[19].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[19].name = "eml_xgemm";
  c6_info[19].dominantType = "char";
  c6_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c6_info[19].fileTimeLo = 1299109172U;
  c6_info[19].fileTimeHi = 0U;
  c6_info[19].mFileTimeLo = 0U;
  c6_info[19].mFileTimeHi = 0U;
  c6_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c6_info[20].name = "eml_blas_inline";
  c6_info[20].dominantType = "";
  c6_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c6_info[20].fileTimeLo = 1299109168U;
  c6_info[20].fileTimeHi = 0U;
  c6_info[20].mFileTimeLo = 0U;
  c6_info[20].mFileTimeHi = 0U;
  c6_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c6_info[21].name = "mtimes";
  c6_info[21].dominantType = "double";
  c6_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[21].fileTimeLo = 1289552092U;
  c6_info[21].fileTimeHi = 0U;
  c6_info[21].mFileTimeLo = 0U;
  c6_info[21].mFileTimeHi = 0U;
  c6_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c6_info[22].name = "eml_index_class";
  c6_info[22].dominantType = "";
  c6_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[22].fileTimeLo = 1323202978U;
  c6_info[22].fileTimeHi = 0U;
  c6_info[22].mFileTimeLo = 0U;
  c6_info[22].mFileTimeHi = 0U;
  c6_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c6_info[23].name = "eml_scalar_eg";
  c6_info[23].dominantType = "double";
  c6_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[23].fileTimeLo = 1286851196U;
  c6_info[23].fileTimeHi = 0U;
  c6_info[23].mFileTimeLo = 0U;
  c6_info[23].mFileTimeHi = 0U;
  c6_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c6_info[24].name = "eml_refblas_xgemm";
  c6_info[24].dominantType = "char";
  c6_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c6_info[24].fileTimeLo = 1299109174U;
  c6_info[24].fileTimeHi = 0U;
  c6_info[24].mFileTimeLo = 0U;
  c6_info[24].mFileTimeHi = 0U;
}

static real_T c6_mpower(SFc6_Final_Project_v3cInstanceStruct *chartInstance,
  real_T c6_a)
{
  real_T c6_b_a;
  real_T c6_c_a;
  real_T c6_ak;
  real_T c6_d_a;
  real_T c6_e_a;
  real_T c6_b;
  c6_b_a = c6_a;
  c6_c_a = c6_b_a;
  c6_eml_scalar_eg(chartInstance);
  c6_ak = c6_c_a;
  c6_d_a = c6_ak;
  c6_eml_scalar_eg(chartInstance);
  c6_e_a = c6_d_a;
  c6_b = c6_d_a;
  return c6_e_a * c6_b;
}

static void c6_eml_scalar_eg(SFc6_Final_Project_v3cInstanceStruct *chartInstance)
{
}

static void c6_b_eml_scalar_eg(SFc6_Final_Project_v3cInstanceStruct
  *chartInstance)
{
}

static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_Final_Project_v3cInstanceStruct *chartInstance;
  chartInstance = (SFc6_Final_Project_v3cInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static int32_T c6_e_emlrt_marshallIn(SFc6_Final_Project_v3cInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i87;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i87, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i87;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_Final_Project_v3cInstanceStruct *chartInstance;
  chartInstance = (SFc6_Final_Project_v3cInstanceStruct *)chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint8_T c6_f_emlrt_marshallIn(SFc6_Final_Project_v3cInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_Final_Project_v3c, const
  char_T *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_Final_Project_v3c), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_Final_Project_v3c);
  return c6_y;
}

static uint8_T c6_g_emlrt_marshallIn(SFc6_Final_Project_v3cInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void init_dsm_address_info(SFc6_Final_Project_v3cInstanceStruct
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

void sf_c6_Final_Project_v3c_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3460631585U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3171596921U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2788125650U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3961184854U);
}

mxArray *sf_c6_Final_Project_v3c_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Z2djM3VukHfGYv5e8oiPZ");
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

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c6_Final_Project_v3c_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c6_Final_Project_v3c(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"H\",},{M[8],M[0],T\"is_active_c6_Final_Project_v3c\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_Final_Project_v3c_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_Final_Project_v3cInstanceStruct *chartInstance;
    chartInstance = (SFc6_Final_Project_v3cInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Final_Project_v3cMachineNumber_,
           6,
           1,
           1,
           4,
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
          init_script_number_translation(_Final_Project_v3cMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Final_Project_v3cMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Final_Project_v3cMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"H");
          _SFD_SET_DATA_PROPS(1,1,1,0,"qqd");
          _SFD_SET_DATA_PROPS(2,10,0,0,"l");
          _SFD_SET_DATA_PROPS(3,10,0,0,"m");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,932);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)
            c6_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)c6_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)c6_b_sf_marshallIn);

        {
          real_T (*c6_H)[9];
          real_T (*c6_qqd)[9];
          c6_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          c6_H = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c6_H);
          _SFD_SET_DATA_VALUE_PTR(1U, *c6_qqd);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c6_l);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c6_m);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Final_Project_v3cMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "eoXHpL8faFc5uHWrBc2bD";
}

static void sf_opaque_initialize_c6_Final_Project_v3c(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_Final_Project_v3cInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c6_Final_Project_v3c((SFc6_Final_Project_v3cInstanceStruct*)
    chartInstanceVar);
  initialize_c6_Final_Project_v3c((SFc6_Final_Project_v3cInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c6_Final_Project_v3c(void *chartInstanceVar)
{
  enable_c6_Final_Project_v3c((SFc6_Final_Project_v3cInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c6_Final_Project_v3c(void *chartInstanceVar)
{
  disable_c6_Final_Project_v3c((SFc6_Final_Project_v3cInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c6_Final_Project_v3c(void *chartInstanceVar)
{
  sf_c6_Final_Project_v3c((SFc6_Final_Project_v3cInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c6_Final_Project_v3c(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_Final_Project_v3c
    ((SFc6_Final_Project_v3cInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_Final_Project_v3c();/* state var info */
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

extern void sf_internal_set_sim_state_c6_Final_Project_v3c(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_Final_Project_v3c();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_Final_Project_v3c((SFc6_Final_Project_v3cInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c6_Final_Project_v3c(SimStruct* S)
{
  return sf_internal_get_sim_state_c6_Final_Project_v3c(S);
}

static void sf_opaque_set_sim_state_c6_Final_Project_v3c(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c6_Final_Project_v3c(S, st);
}

static void sf_opaque_terminate_c6_Final_Project_v3c(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_Final_Project_v3cInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Final_Project_v3c_optimization_info();
    }

    finalize_c6_Final_Project_v3c((SFc6_Final_Project_v3cInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_Final_Project_v3c((SFc6_Final_Project_v3cInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_Final_Project_v3c(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_Final_Project_v3c((SFc6_Final_Project_v3cInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_Final_Project_v3c(SimStruct *S)
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
    mxArray *infoStruct = load_Final_Project_v3c_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,6,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,6);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,6,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1143999080U));
  ssSetChecksum1(S,(3979909538U));
  ssSetChecksum2(S,(1933129312U));
  ssSetChecksum3(S,(3246312546U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c6_Final_Project_v3c(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_Final_Project_v3c(SimStruct *S)
{
  SFc6_Final_Project_v3cInstanceStruct *chartInstance;
  chartInstance = (SFc6_Final_Project_v3cInstanceStruct *)utMalloc(sizeof
    (SFc6_Final_Project_v3cInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_Final_Project_v3cInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c6_Final_Project_v3c;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c6_Final_Project_v3c;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c6_Final_Project_v3c;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_Final_Project_v3c;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_Final_Project_v3c;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_Final_Project_v3c;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_Final_Project_v3c;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_Final_Project_v3c;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_Final_Project_v3c;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_Final_Project_v3c;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c6_Final_Project_v3c;
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

void c6_Final_Project_v3c_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_Final_Project_v3c(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_Final_Project_v3c(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_Final_Project_v3c(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_Final_Project_v3c_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
