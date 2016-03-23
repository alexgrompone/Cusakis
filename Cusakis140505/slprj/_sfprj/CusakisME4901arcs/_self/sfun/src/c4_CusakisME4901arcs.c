/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CusakisME4901arcs_sfun.h"
#include "c4_CusakisME4901arcs.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CusakisME4901arcs_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c4_debug_family_names[15] = { "q", "g", "Jp1", "Jo1", "Jp2",
  "Jo2", "Jp3", "Jo3", "G1", "nargin", "nargout", "qqd", "l", "m", "G" };

/* Function Declarations */
static void initialize_c4_CusakisME4901arcs(SFc4_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void initialize_params_c4_CusakisME4901arcs
  (SFc4_CusakisME4901arcsInstanceStruct *chartInstance);
static void enable_c4_CusakisME4901arcs(SFc4_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void disable_c4_CusakisME4901arcs(SFc4_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void c4_update_debugger_state_c4_CusakisME4901arcs
  (SFc4_CusakisME4901arcsInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_CusakisME4901arcs
  (SFc4_CusakisME4901arcsInstanceStruct *chartInstance);
static void set_sim_state_c4_CusakisME4901arcs
  (SFc4_CusakisME4901arcsInstanceStruct *chartInstance, const mxArray *c4_st);
static void finalize_c4_CusakisME4901arcs(SFc4_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void sf_c4_CusakisME4901arcs(SFc4_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void c4_chartstep_c4_CusakisME4901arcs
  (SFc4_CusakisME4901arcsInstanceStruct *chartInstance);
static void initSimStructsc4_CusakisME4901arcs
  (SFc4_CusakisME4901arcsInstanceStruct *chartInstance);
static void registerMessagesc4_CusakisME4901arcs
  (SFc4_CusakisME4901arcsInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_emlrt_marshallIn(SFc4_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c4_G, const char_T *c4_identifier, real_T c4_y
  [3]);
static void c4_b_emlrt_marshallIn(SFc4_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[3]);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_c_emlrt_marshallIn(SFc4_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_d_emlrt_marshallIn(SFc4_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[3]);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_e_emlrt_marshallIn(SFc4_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[9]);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[17]);
static void c4_eml_scalar_eg(SFc4_CusakisME4901arcsInstanceStruct *chartInstance);
static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_f_emlrt_marshallIn(SFc4_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_g_emlrt_marshallIn(SFc4_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_CusakisME4901arcs, const
  char_T *c4_identifier);
static uint8_T c4_h_emlrt_marshallIn(SFc4_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_CusakisME4901arcsInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_CusakisME4901arcs(SFc4_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_is_active_c4_CusakisME4901arcs = 0U;
}

static void initialize_params_c4_CusakisME4901arcs
  (SFc4_CusakisME4901arcsInstanceStruct *chartInstance)
{
  real_T c4_d0;
  real_T c4_d1;
  sf_set_error_prefix_string(
    "Error evaluating data 'l' in the parent workspace.\n");
  sf_mex_import_named("l", sf_mex_get_sfun_param(chartInstance->S, 0, 0), &c4_d0,
                      0, 0, 0U, 0, 0U, 0);
  chartInstance->c4_l = c4_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'm' in the parent workspace.\n");
  sf_mex_import_named("m", sf_mex_get_sfun_param(chartInstance->S, 1, 0), &c4_d1,
                      0, 0, 0U, 0, 0U, 0);
  chartInstance->c4_m = c4_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c4_CusakisME4901arcs(SFc4_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_CusakisME4901arcs(SFc4_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_CusakisME4901arcs
  (SFc4_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c4_CusakisME4901arcs
  (SFc4_CusakisME4901arcsInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  int32_T c4_i0;
  real_T c4_u[3];
  const mxArray *c4_b_y = NULL;
  uint8_T c4_hoistedGlobal;
  uint8_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real_T (*c4_G)[3];
  c4_G = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(2), FALSE);
  for (c4_i0 = 0; c4_i0 < 3; c4_i0++) {
    c4_u[c4_i0] = (*c4_G)[c4_i0];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_hoistedGlobal = chartInstance->c4_is_active_c4_CusakisME4901arcs;
  c4_b_u = c4_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y, FALSE);
  return c4_st;
}

static void set_sim_state_c4_CusakisME4901arcs
  (SFc4_CusakisME4901arcsInstanceStruct *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv0[3];
  int32_T c4_i1;
  real_T (*c4_G)[3];
  c4_G = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)), "G",
                      c4_dv0);
  for (c4_i1 = 0; c4_i1 < 3; c4_i1++) {
    (*c4_G)[c4_i1] = c4_dv0[c4_i1];
  }

  chartInstance->c4_is_active_c4_CusakisME4901arcs = c4_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
     "is_active_c4_CusakisME4901arcs");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_CusakisME4901arcs(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_CusakisME4901arcs(SFc4_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
}

static void sf_c4_CusakisME4901arcs(SFc4_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
  int32_T c4_i2;
  int32_T c4_i3;
  real_T (*c4_G)[3];
  real_T (*c4_qqd)[9];
  c4_G = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  for (c4_i2 = 0; c4_i2 < 9; c4_i2++) {
    _SFD_DATA_RANGE_CHECK((*c4_qqd)[c4_i2], 0U);
  }

  for (c4_i3 = 0; c4_i3 < 3; c4_i3++) {
    _SFD_DATA_RANGE_CHECK((*c4_G)[c4_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c4_l, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_m, 3U);
  chartInstance->c4_sfEvent = CALL_EVENT;
  c4_chartstep_c4_CusakisME4901arcs(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CusakisME4901arcsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c4_chartstep_c4_CusakisME4901arcs
  (SFc4_CusakisME4901arcsInstanceStruct *chartInstance)
{
  real_T c4_hoistedGlobal;
  real_T c4_b_hoistedGlobal;
  int32_T c4_i4;
  real_T c4_qqd[9];
  real_T c4_b_l;
  real_T c4_b_m;
  uint32_T c4_debug_family_var_map[15];
  real_T c4_q[3];
  real_T c4_g[3];
  real_T c4_Jp1[9];
  real_T c4_Jo1[9];
  real_T c4_Jp2[9];
  real_T c4_Jo2[9];
  real_T c4_Jp3[9];
  real_T c4_Jo3[9];
  real_T c4_G1[3];
  real_T c4_nargin = 3.0;
  real_T c4_nargout = 1.0;
  real_T c4_G[3];
  int32_T c4_i5;
  static real_T c4_b[3] = { 0.0, 9.81, 0.0 };

  real_T c4_A;
  real_T c4_x;
  real_T c4_b_x;
  real_T c4_y;
  real_T c4_c_x;
  real_T c4_d_x;
  real_T c4_a;
  real_T c4_b_b;
  real_T c4_b_y;
  real_T c4_b_A;
  real_T c4_e_x;
  real_T c4_f_x;
  real_T c4_c_y;
  real_T c4_g_x;
  real_T c4_h_x;
  real_T c4_b_a;
  real_T c4_c_b;
  real_T c4_d_y;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  static real_T c4_dv1[9] = { 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  real_T c4_i_x;
  real_T c4_j_x;
  real_T c4_c_a;
  real_T c4_d_b;
  real_T c4_e_y;
  real_T c4_c_A;
  real_T c4_k_x;
  real_T c4_l_x;
  real_T c4_f_y;
  real_T c4_m_x;
  real_T c4_n_x;
  real_T c4_d_a;
  real_T c4_e_b;
  real_T c4_g_y;
  real_T c4_d_A;
  real_T c4_o_x;
  real_T c4_p_x;
  real_T c4_h_y;
  real_T c4_q_x;
  real_T c4_r_x;
  real_T c4_e_a;
  real_T c4_f_b;
  real_T c4_i_y;
  real_T c4_s_x;
  real_T c4_t_x;
  real_T c4_f_a;
  real_T c4_g_b;
  real_T c4_j_y;
  real_T c4_e_A;
  real_T c4_u_x;
  real_T c4_v_x;
  real_T c4_k_y;
  real_T c4_w_x;
  real_T c4_x_x;
  real_T c4_g_a;
  real_T c4_h_b;
  real_T c4_l_y;
  real_T c4_f_A;
  real_T c4_y_x;
  real_T c4_ab_x;
  real_T c4_m_y;
  real_T c4_bb_x;
  real_T c4_cb_x;
  real_T c4_h_a;
  real_T c4_i_b;
  real_T c4_n_y;
  int32_T c4_i9;
  int32_T c4_i10;
  int32_T c4_i11;
  static real_T c4_dv2[9] = { 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0 };

  real_T c4_db_x;
  real_T c4_eb_x;
  real_T c4_i_a;
  real_T c4_j_b;
  real_T c4_o_y;
  real_T c4_fb_x;
  real_T c4_gb_x;
  real_T c4_j_a;
  real_T c4_k_b;
  real_T c4_p_y;
  real_T c4_g_A;
  real_T c4_hb_x;
  real_T c4_ib_x;
  real_T c4_q_y;
  real_T c4_jb_x;
  real_T c4_kb_x;
  real_T c4_k_a;
  real_T c4_l_b;
  real_T c4_r_y;
  real_T c4_lb_x;
  real_T c4_mb_x;
  real_T c4_l_a;
  real_T c4_m_b;
  real_T c4_s_y;
  real_T c4_h_A;
  real_T c4_nb_x;
  real_T c4_ob_x;
  real_T c4_t_y;
  real_T c4_pb_x;
  real_T c4_qb_x;
  real_T c4_m_a;
  real_T c4_n_b;
  real_T c4_u_y;
  real_T c4_i_A;
  real_T c4_rb_x;
  real_T c4_sb_x;
  real_T c4_v_y;
  real_T c4_tb_x;
  real_T c4_ub_x;
  real_T c4_n_a;
  real_T c4_o_b;
  real_T c4_w_y;
  real_T c4_vb_x;
  real_T c4_wb_x;
  real_T c4_o_a;
  real_T c4_p_b;
  real_T c4_x_y;
  real_T c4_xb_x;
  real_T c4_yb_x;
  real_T c4_p_a;
  real_T c4_q_b;
  real_T c4_y_y;
  real_T c4_j_A;
  real_T c4_ac_x;
  real_T c4_bc_x;
  real_T c4_ab_y;
  real_T c4_cc_x;
  real_T c4_dc_x;
  real_T c4_q_a;
  real_T c4_r_b;
  real_T c4_bb_y;
  real_T c4_ec_x;
  real_T c4_fc_x;
  real_T c4_r_a;
  real_T c4_s_b;
  real_T c4_cb_y;
  real_T c4_k_A;
  real_T c4_gc_x;
  real_T c4_hc_x;
  real_T c4_db_y;
  real_T c4_ic_x;
  real_T c4_jc_x;
  real_T c4_s_a;
  real_T c4_t_b;
  real_T c4_eb_y;
  real_T c4_l_A;
  real_T c4_kc_x;
  real_T c4_lc_x;
  real_T c4_fb_y;
  real_T c4_mc_x;
  real_T c4_nc_x;
  real_T c4_t_a;
  real_T c4_u_b;
  real_T c4_gb_y;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  static real_T c4_dv3[9] = { 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0 };

  real_T c4_u_a;
  int32_T c4_i15;
  real_T c4_hb_y[3];
  int32_T c4_i16;
  real_T c4_v_b[9];
  int32_T c4_i17;
  int32_T c4_i18;
  real_T c4_ib_y[3];
  int32_T c4_i19;
  real_T c4_v_a;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  real_T c4_jb_y[3];
  int32_T c4_i24;
  real_T c4_w_a;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  real_T c4_kb_y[3];
  int32_T c4_i29;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  real_T (*c4_b_G)[3];
  real_T (*c4_b_qqd)[9];
  c4_b_G = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_b_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = chartInstance->c4_l;
  c4_b_hoistedGlobal = chartInstance->c4_m;
  for (c4_i4 = 0; c4_i4 < 9; c4_i4++) {
    c4_qqd[c4_i4] = (*c4_b_qqd)[c4_i4];
  }

  c4_b_l = c4_hoistedGlobal;
  c4_b_m = c4_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 15U, 15U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_q, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_g, 1U, c4_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_Jp1, 2U, c4_e_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_Jo1, 3U, c4_e_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_Jp2, 4U, c4_e_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_Jo2, 5U, c4_e_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_Jp3, 6U, c4_e_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_Jo3, 7U, c4_e_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_G1, 8U, c4_d_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 9U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 10U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_qqd, 11U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_l, 12U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_m, 13U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_G, 14U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 3);
  c4_q[0] = c4_qqd[6];
  c4_q[1] = c4_qqd[7];
  c4_q[2] = c4_qqd[8];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 5);
  for (c4_i5 = 0; c4_i5 < 3; c4_i5++) {
    c4_g[c4_i5] = c4_b[c4_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_A = c4_b_l;
  c4_x = c4_A;
  c4_b_x = c4_x;
  c4_y = c4_b_x / 2.0;
  c4_c_x = c4_q[0];
  c4_d_x = c4_c_x;
  c4_d_x = muDoubleScalarSin(c4_d_x);
  c4_a = -c4_y;
  c4_b_b = c4_d_x;
  c4_b_y = c4_a * c4_b_b;
  c4_b_A = c4_b_l;
  c4_e_x = c4_b_A;
  c4_f_x = c4_e_x;
  c4_c_y = c4_f_x / 2.0;
  c4_g_x = c4_q[0];
  c4_h_x = c4_g_x;
  c4_h_x = muDoubleScalarCos(c4_h_x);
  c4_b_a = c4_c_y;
  c4_c_b = c4_h_x;
  c4_d_y = c4_b_a * c4_c_b;
  c4_Jp1[0] = c4_b_y;
  c4_Jp1[3] = 0.0;
  c4_Jp1[6] = 0.0;
  c4_Jp1[1] = c4_d_y;
  c4_Jp1[4] = 0.0;
  c4_Jp1[7] = 0.0;
  c4_i6 = 0;
  for (c4_i7 = 0; c4_i7 < 3; c4_i7++) {
    c4_Jp1[c4_i6 + 2] = 0.0;
    c4_i6 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i8 = 0; c4_i8 < 9; c4_i8++) {
    c4_Jo1[c4_i8] = c4_dv1[c4_i8];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 11);
  c4_i_x = c4_q[0];
  c4_j_x = c4_i_x;
  c4_j_x = muDoubleScalarSin(c4_j_x);
  c4_c_a = -c4_b_l;
  c4_d_b = c4_j_x;
  c4_e_y = c4_c_a * c4_d_b;
  c4_c_A = c4_b_l;
  c4_k_x = c4_c_A;
  c4_l_x = c4_k_x;
  c4_f_y = c4_l_x / 2.0;
  c4_m_x = c4_q[0] + c4_q[1];
  c4_n_x = c4_m_x;
  c4_n_x = muDoubleScalarSin(c4_n_x);
  c4_d_a = c4_f_y;
  c4_e_b = c4_n_x;
  c4_g_y = c4_d_a * c4_e_b;
  c4_d_A = c4_b_l;
  c4_o_x = c4_d_A;
  c4_p_x = c4_o_x;
  c4_h_y = c4_p_x / 2.0;
  c4_q_x = c4_q[0] + c4_q[1];
  c4_r_x = c4_q_x;
  c4_r_x = muDoubleScalarSin(c4_r_x);
  c4_e_a = -c4_h_y;
  c4_f_b = c4_r_x;
  c4_i_y = c4_e_a * c4_f_b;
  c4_s_x = c4_q[0];
  c4_t_x = c4_s_x;
  c4_t_x = muDoubleScalarCos(c4_t_x);
  c4_f_a = c4_b_l;
  c4_g_b = c4_t_x;
  c4_j_y = c4_f_a * c4_g_b;
  c4_e_A = c4_b_l;
  c4_u_x = c4_e_A;
  c4_v_x = c4_u_x;
  c4_k_y = c4_v_x / 2.0;
  c4_w_x = c4_q[0] + c4_q[1];
  c4_x_x = c4_w_x;
  c4_x_x = muDoubleScalarCos(c4_x_x);
  c4_g_a = c4_k_y;
  c4_h_b = c4_x_x;
  c4_l_y = c4_g_a * c4_h_b;
  c4_f_A = c4_b_l;
  c4_y_x = c4_f_A;
  c4_ab_x = c4_y_x;
  c4_m_y = c4_ab_x / 2.0;
  c4_bb_x = c4_q[0] + c4_q[1];
  c4_cb_x = c4_bb_x;
  c4_cb_x = muDoubleScalarCos(c4_cb_x);
  c4_h_a = c4_m_y;
  c4_i_b = c4_cb_x;
  c4_n_y = c4_h_a * c4_i_b;
  c4_Jp2[0] = c4_e_y - c4_g_y;
  c4_Jp2[3] = c4_i_y;
  c4_Jp2[6] = 0.0;
  c4_Jp2[1] = c4_j_y + c4_l_y;
  c4_Jp2[4] = c4_n_y;
  c4_Jp2[7] = 0.0;
  c4_i9 = 0;
  for (c4_i10 = 0; c4_i10 < 3; c4_i10++) {
    c4_Jp2[c4_i9 + 2] = 0.0;
    c4_i9 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 12);
  for (c4_i11 = 0; c4_i11 < 9; c4_i11++) {
    c4_Jo2[c4_i11] = c4_dv2[c4_i11];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 14);
  c4_db_x = c4_q[0];
  c4_eb_x = c4_db_x;
  c4_eb_x = muDoubleScalarSin(c4_eb_x);
  c4_i_a = -c4_b_l;
  c4_j_b = c4_eb_x;
  c4_o_y = c4_i_a * c4_j_b;
  c4_fb_x = c4_q[0] + c4_q[1];
  c4_gb_x = c4_fb_x;
  c4_gb_x = muDoubleScalarSin(c4_gb_x);
  c4_j_a = c4_b_l;
  c4_k_b = c4_gb_x;
  c4_p_y = c4_j_a * c4_k_b;
  c4_g_A = c4_b_l;
  c4_hb_x = c4_g_A;
  c4_ib_x = c4_hb_x;
  c4_q_y = c4_ib_x / 2.0;
  c4_jb_x = (c4_q[0] + c4_q[1]) + c4_q[2];
  c4_kb_x = c4_jb_x;
  c4_kb_x = muDoubleScalarSin(c4_kb_x);
  c4_k_a = c4_q_y;
  c4_l_b = c4_kb_x;
  c4_r_y = c4_k_a * c4_l_b;
  c4_lb_x = c4_q[0] + c4_q[1];
  c4_mb_x = c4_lb_x;
  c4_mb_x = muDoubleScalarSin(c4_mb_x);
  c4_l_a = -c4_b_l;
  c4_m_b = c4_mb_x;
  c4_s_y = c4_l_a * c4_m_b;
  c4_h_A = c4_b_l;
  c4_nb_x = c4_h_A;
  c4_ob_x = c4_nb_x;
  c4_t_y = c4_ob_x / 2.0;
  c4_pb_x = (c4_q[0] + c4_q[1]) + c4_q[2];
  c4_qb_x = c4_pb_x;
  c4_qb_x = muDoubleScalarSin(c4_qb_x);
  c4_m_a = c4_t_y;
  c4_n_b = c4_qb_x;
  c4_u_y = c4_m_a * c4_n_b;
  c4_i_A = c4_b_l;
  c4_rb_x = c4_i_A;
  c4_sb_x = c4_rb_x;
  c4_v_y = c4_sb_x / 2.0;
  c4_tb_x = (c4_q[0] + c4_q[1]) + c4_q[2];
  c4_ub_x = c4_tb_x;
  c4_ub_x = muDoubleScalarSin(c4_ub_x);
  c4_n_a = -c4_v_y;
  c4_o_b = c4_ub_x;
  c4_w_y = c4_n_a * c4_o_b;
  c4_vb_x = c4_q[0];
  c4_wb_x = c4_vb_x;
  c4_wb_x = muDoubleScalarCos(c4_wb_x);
  c4_o_a = c4_b_l;
  c4_p_b = c4_wb_x;
  c4_x_y = c4_o_a * c4_p_b;
  c4_xb_x = c4_q[0] + c4_q[1];
  c4_yb_x = c4_xb_x;
  c4_yb_x = muDoubleScalarCos(c4_yb_x);
  c4_p_a = c4_b_l;
  c4_q_b = c4_yb_x;
  c4_y_y = c4_p_a * c4_q_b;
  c4_j_A = c4_b_l;
  c4_ac_x = c4_j_A;
  c4_bc_x = c4_ac_x;
  c4_ab_y = c4_bc_x / 2.0;
  c4_cc_x = (c4_q[0] + c4_q[1]) + c4_q[2];
  c4_dc_x = c4_cc_x;
  c4_dc_x = muDoubleScalarCos(c4_dc_x);
  c4_q_a = c4_ab_y;
  c4_r_b = c4_dc_x;
  c4_bb_y = c4_q_a * c4_r_b;
  c4_ec_x = c4_q[0] + c4_q[1];
  c4_fc_x = c4_ec_x;
  c4_fc_x = muDoubleScalarCos(c4_fc_x);
  c4_r_a = c4_b_l;
  c4_s_b = c4_fc_x;
  c4_cb_y = c4_r_a * c4_s_b;
  c4_k_A = c4_b_l;
  c4_gc_x = c4_k_A;
  c4_hc_x = c4_gc_x;
  c4_db_y = c4_hc_x / 2.0;
  c4_ic_x = (c4_q[0] + c4_q[1]) + c4_q[2];
  c4_jc_x = c4_ic_x;
  c4_jc_x = muDoubleScalarCos(c4_jc_x);
  c4_s_a = c4_db_y;
  c4_t_b = c4_jc_x;
  c4_eb_y = c4_s_a * c4_t_b;
  c4_l_A = c4_b_l;
  c4_kc_x = c4_l_A;
  c4_lc_x = c4_kc_x;
  c4_fb_y = c4_lc_x / 2.0;
  c4_mc_x = (c4_q[0] + c4_q[1]) + c4_q[2];
  c4_nc_x = c4_mc_x;
  c4_nc_x = muDoubleScalarCos(c4_nc_x);
  c4_t_a = c4_fb_y;
  c4_u_b = c4_nc_x;
  c4_gb_y = c4_t_a * c4_u_b;
  c4_Jp3[0] = (c4_o_y - c4_p_y) - c4_r_y;
  c4_Jp3[3] = c4_s_y - c4_u_y;
  c4_Jp3[6] = c4_w_y;
  c4_Jp3[1] = (c4_x_y + c4_y_y) + c4_bb_y;
  c4_Jp3[4] = c4_cb_y + c4_eb_y;
  c4_Jp3[7] = c4_gb_y;
  c4_i12 = 0;
  for (c4_i13 = 0; c4_i13 < 3; c4_i13++) {
    c4_Jp3[c4_i12 + 2] = 0.0;
    c4_i12 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 15);
  for (c4_i14 = 0; c4_i14 < 9; c4_i14++) {
    c4_Jo3[c4_i14] = c4_dv3[c4_i14];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 17);
  c4_u_a = c4_b_m;
  for (c4_i15 = 0; c4_i15 < 3; c4_i15++) {
    c4_hb_y[c4_i15] = c4_u_a * c4_b[c4_i15];
  }

  for (c4_i16 = 0; c4_i16 < 9; c4_i16++) {
    c4_v_b[c4_i16] = c4_Jp1[c4_i16];
  }

  c4_eml_scalar_eg(chartInstance);
  c4_eml_scalar_eg(chartInstance);
  c4_i17 = 0;
  for (c4_i18 = 0; c4_i18 < 3; c4_i18++) {
    c4_ib_y[c4_i18] = 0.0;
    for (c4_i19 = 0; c4_i19 < 3; c4_i19++) {
      c4_ib_y[c4_i18] += c4_hb_y[c4_i19] * c4_v_b[c4_i19 + c4_i17];
    }

    c4_i17 += 3;
  }

  c4_v_a = c4_b_m;
  for (c4_i20 = 0; c4_i20 < 3; c4_i20++) {
    c4_hb_y[c4_i20] = c4_v_a * c4_b[c4_i20];
  }

  for (c4_i21 = 0; c4_i21 < 9; c4_i21++) {
    c4_v_b[c4_i21] = c4_Jp2[c4_i21];
  }

  c4_eml_scalar_eg(chartInstance);
  c4_eml_scalar_eg(chartInstance);
  c4_i22 = 0;
  for (c4_i23 = 0; c4_i23 < 3; c4_i23++) {
    c4_jb_y[c4_i23] = 0.0;
    for (c4_i24 = 0; c4_i24 < 3; c4_i24++) {
      c4_jb_y[c4_i23] += c4_hb_y[c4_i24] * c4_v_b[c4_i24 + c4_i22];
    }

    c4_i22 += 3;
  }

  c4_w_a = c4_b_m;
  for (c4_i25 = 0; c4_i25 < 3; c4_i25++) {
    c4_hb_y[c4_i25] = c4_w_a * c4_b[c4_i25];
  }

  for (c4_i26 = 0; c4_i26 < 9; c4_i26++) {
    c4_v_b[c4_i26] = c4_Jp3[c4_i26];
  }

  c4_eml_scalar_eg(chartInstance);
  c4_eml_scalar_eg(chartInstance);
  c4_i27 = 0;
  for (c4_i28 = 0; c4_i28 < 3; c4_i28++) {
    c4_kb_y[c4_i28] = 0.0;
    for (c4_i29 = 0; c4_i29 < 3; c4_i29++) {
      c4_kb_y[c4_i28] += c4_hb_y[c4_i29] * c4_v_b[c4_i29 + c4_i27];
    }

    c4_i27 += 3;
  }

  for (c4_i30 = 0; c4_i30 < 3; c4_i30++) {
    c4_G1[c4_i30] = (c4_ib_y[c4_i30] + c4_jb_y[c4_i30]) + c4_kb_y[c4_i30];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 21);
  for (c4_i31 = 0; c4_i31 < 3; c4_i31++) {
    c4_G[c4_i31] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -21);
  _SFD_SYMBOL_SCOPE_POP();
  for (c4_i32 = 0; c4_i32 < 3; c4_i32++) {
    (*c4_b_G)[c4_i32] = c4_G[c4_i32];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
}

static void initSimStructsc4_CusakisME4901arcs
  (SFc4_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static void registerMessagesc4_CusakisME4901arcs
  (SFc4_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i33;
  real_T c4_b_inData[3];
  int32_T c4_i34;
  real_T c4_u[3];
  const mxArray *c4_y = NULL;
  SFc4_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc4_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i33 = 0; c4_i33 < 3; c4_i33++) {
    c4_b_inData[c4_i33] = (*(real_T (*)[3])c4_inData)[c4_i33];
  }

  for (c4_i34 = 0; c4_i34 < 3; c4_i34++) {
    c4_u[c4_i34] = c4_b_inData[c4_i34];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_emlrt_marshallIn(SFc4_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c4_G, const char_T *c4_identifier, real_T c4_y
  [3])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_G), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_G);
}

static void c4_b_emlrt_marshallIn(SFc4_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[3])
{
  real_T c4_dv4[3];
  int32_T c4_i35;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv4, 1, 0, 0U, 1, 0U, 1, 3);
  for (c4_i35 = 0; c4_i35 < 3; c4_i35++) {
    c4_y[c4_i35] = c4_dv4[c4_i35];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_G;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[3];
  int32_T c4_i36;
  SFc4_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc4_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c4_G = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_G), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_G);
  for (c4_i36 = 0; c4_i36 < 3; c4_i36++) {
    (*(real_T (*)[3])c4_outData)[c4_i36] = c4_y[c4_i36];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc4_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real_T c4_c_emlrt_marshallIn(SFc4_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d2;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d2, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d2;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_m;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc4_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c4_b_m = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_m), &c4_thisId);
  sf_mex_destroy(&c4_b_m);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i37;
  real_T c4_b_inData[9];
  int32_T c4_i38;
  real_T c4_u[9];
  const mxArray *c4_y = NULL;
  SFc4_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc4_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i37 = 0; c4_i37 < 9; c4_i37++) {
    c4_b_inData[c4_i37] = (*(real_T (*)[9])c4_inData)[c4_i37];
  }

  for (c4_i38 = 0; c4_i38 < 9; c4_i38++) {
    c4_u[c4_i38] = c4_b_inData[c4_i38];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 9), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i39;
  real_T c4_b_inData[3];
  int32_T c4_i40;
  real_T c4_u[3];
  const mxArray *c4_y = NULL;
  SFc4_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc4_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i39 = 0; c4_i39 < 3; c4_i39++) {
    c4_b_inData[c4_i39] = (*(real_T (*)[3])c4_inData)[c4_i39];
  }

  for (c4_i40 = 0; c4_i40 < 3; c4_i40++) {
    c4_u[c4_i40] = c4_b_inData[c4_i40];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 1, 3), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_d_emlrt_marshallIn(SFc4_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[3])
{
  real_T c4_dv5[3];
  int32_T c4_i41;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv5, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c4_i41 = 0; c4_i41 < 3; c4_i41++) {
    c4_y[c4_i41] = c4_dv5[c4_i41];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_G1;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[3];
  int32_T c4_i42;
  SFc4_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc4_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c4_G1 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_G1), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_G1);
  for (c4_i42 = 0; c4_i42 < 3; c4_i42++) {
    (*(real_T (*)[3])c4_outData)[c4_i42] = c4_y[c4_i42];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i43;
  int32_T c4_i44;
  int32_T c4_i45;
  real_T c4_b_inData[9];
  int32_T c4_i46;
  int32_T c4_i47;
  int32_T c4_i48;
  real_T c4_u[9];
  const mxArray *c4_y = NULL;
  SFc4_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc4_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_i43 = 0;
  for (c4_i44 = 0; c4_i44 < 3; c4_i44++) {
    for (c4_i45 = 0; c4_i45 < 3; c4_i45++) {
      c4_b_inData[c4_i45 + c4_i43] = (*(real_T (*)[9])c4_inData)[c4_i45 + c4_i43];
    }

    c4_i43 += 3;
  }

  c4_i46 = 0;
  for (c4_i47 = 0; c4_i47 < 3; c4_i47++) {
    for (c4_i48 = 0; c4_i48 < 3; c4_i48++) {
      c4_u[c4_i48 + c4_i46] = c4_b_inData[c4_i48 + c4_i46];
    }

    c4_i46 += 3;
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_e_emlrt_marshallIn(SFc4_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[9])
{
  real_T c4_dv6[9];
  int32_T c4_i49;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv6, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c4_i49 = 0; c4_i49 < 9; c4_i49++) {
    c4_y[c4_i49] = c4_dv6[c4_i49];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_Jo3;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[9];
  int32_T c4_i50;
  int32_T c4_i51;
  int32_T c4_i52;
  SFc4_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc4_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c4_Jo3 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_Jo3), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_Jo3);
  c4_i50 = 0;
  for (c4_i51 = 0; c4_i51 < 3; c4_i51++) {
    for (c4_i52 = 0; c4_i52 < 3; c4_i52++) {
      (*(real_T (*)[9])c4_outData)[c4_i52 + c4_i50] = c4_y[c4_i52 + c4_i50];
    }

    c4_i50 += 3;
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_CusakisME4901arcs_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo;
  c4_ResolvedFunctionInfo c4_info[17];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i53;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  c4_info_helper(c4_info);
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 17), FALSE);
  for (c4_i53 = 0; c4_i53 < 17; c4_i53++) {
    c4_r0 = &c4_info[c4_i53];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context", "nameCaptureInfo",
                    c4_i53);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name", "nameCaptureInfo", c4_i53);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c4_i53);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved", "nameCaptureInfo",
                    c4_i53);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c4_i53);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c4_i53);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c4_i53);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c4_i53);
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[17])
{
  c4_info[0].context = "";
  c4_info[0].name = "mrdivide";
  c4_info[0].dominantType = "double";
  c4_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c4_info[0].fileTimeLo = 1357983948U;
  c4_info[0].fileTimeHi = 0U;
  c4_info[0].mFileTimeLo = 1319762366U;
  c4_info[0].mFileTimeHi = 0U;
  c4_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c4_info[1].name = "rdivide";
  c4_info[1].dominantType = "double";
  c4_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c4_info[1].fileTimeLo = 1346542788U;
  c4_info[1].fileTimeHi = 0U;
  c4_info[1].mFileTimeLo = 0U;
  c4_info[1].mFileTimeHi = 0U;
  c4_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c4_info[2].name = "eml_scalexp_compatible";
  c4_info[2].dominantType = "double";
  c4_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c4_info[2].fileTimeLo = 1286851196U;
  c4_info[2].fileTimeHi = 0U;
  c4_info[2].mFileTimeLo = 0U;
  c4_info[2].mFileTimeHi = 0U;
  c4_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c4_info[3].name = "eml_div";
  c4_info[3].dominantType = "double";
  c4_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c4_info[3].fileTimeLo = 1313380210U;
  c4_info[3].fileTimeHi = 0U;
  c4_info[3].mFileTimeLo = 0U;
  c4_info[3].mFileTimeHi = 0U;
  c4_info[4].context = "";
  c4_info[4].name = "sin";
  c4_info[4].dominantType = "double";
  c4_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c4_info[4].fileTimeLo = 1343862786U;
  c4_info[4].fileTimeHi = 0U;
  c4_info[4].mFileTimeLo = 0U;
  c4_info[4].mFileTimeHi = 0U;
  c4_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c4_info[5].name = "eml_scalar_sin";
  c4_info[5].dominantType = "double";
  c4_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c4_info[5].fileTimeLo = 1286851136U;
  c4_info[5].fileTimeHi = 0U;
  c4_info[5].mFileTimeLo = 0U;
  c4_info[5].mFileTimeHi = 0U;
  c4_info[6].context = "";
  c4_info[6].name = "mtimes";
  c4_info[6].dominantType = "double";
  c4_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[6].fileTimeLo = 1289552092U;
  c4_info[6].fileTimeHi = 0U;
  c4_info[6].mFileTimeLo = 0U;
  c4_info[6].mFileTimeHi = 0U;
  c4_info[7].context = "";
  c4_info[7].name = "cos";
  c4_info[7].dominantType = "double";
  c4_info[7].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c4_info[7].fileTimeLo = 1343862772U;
  c4_info[7].fileTimeHi = 0U;
  c4_info[7].mFileTimeLo = 0U;
  c4_info[7].mFileTimeHi = 0U;
  c4_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c4_info[8].name = "eml_scalar_cos";
  c4_info[8].dominantType = "double";
  c4_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c4_info[8].fileTimeLo = 1286851122U;
  c4_info[8].fileTimeHi = 0U;
  c4_info[8].mFileTimeLo = 0U;
  c4_info[8].mFileTimeHi = 0U;
  c4_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[9].name = "eml_index_class";
  c4_info[9].dominantType = "";
  c4_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c4_info[9].fileTimeLo = 1323202978U;
  c4_info[9].fileTimeHi = 0U;
  c4_info[9].mFileTimeLo = 0U;
  c4_info[9].mFileTimeHi = 0U;
  c4_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[10].name = "eml_scalar_eg";
  c4_info[10].dominantType = "double";
  c4_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c4_info[10].fileTimeLo = 1286851196U;
  c4_info[10].fileTimeHi = 0U;
  c4_info[10].mFileTimeLo = 0U;
  c4_info[10].mFileTimeHi = 0U;
  c4_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[11].name = "eml_xgemm";
  c4_info[11].dominantType = "char";
  c4_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c4_info[11].fileTimeLo = 1299109172U;
  c4_info[11].fileTimeHi = 0U;
  c4_info[11].mFileTimeLo = 0U;
  c4_info[11].mFileTimeHi = 0U;
  c4_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c4_info[12].name = "eml_blas_inline";
  c4_info[12].dominantType = "";
  c4_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c4_info[12].fileTimeLo = 1299109168U;
  c4_info[12].fileTimeHi = 0U;
  c4_info[12].mFileTimeLo = 0U;
  c4_info[12].mFileTimeHi = 0U;
  c4_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c4_info[13].name = "mtimes";
  c4_info[13].dominantType = "double";
  c4_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[13].fileTimeLo = 1289552092U;
  c4_info[13].fileTimeHi = 0U;
  c4_info[13].mFileTimeLo = 0U;
  c4_info[13].mFileTimeHi = 0U;
  c4_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c4_info[14].name = "eml_index_class";
  c4_info[14].dominantType = "";
  c4_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c4_info[14].fileTimeLo = 1323202978U;
  c4_info[14].fileTimeHi = 0U;
  c4_info[14].mFileTimeLo = 0U;
  c4_info[14].mFileTimeHi = 0U;
  c4_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c4_info[15].name = "eml_scalar_eg";
  c4_info[15].dominantType = "double";
  c4_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c4_info[15].fileTimeLo = 1286851196U;
  c4_info[15].fileTimeHi = 0U;
  c4_info[15].mFileTimeLo = 0U;
  c4_info[15].mFileTimeHi = 0U;
  c4_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c4_info[16].name = "eml_refblas_xgemm";
  c4_info[16].dominantType = "char";
  c4_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c4_info[16].fileTimeLo = 1299109174U;
  c4_info[16].fileTimeHi = 0U;
  c4_info[16].mFileTimeLo = 0U;
  c4_info[16].mFileTimeHi = 0U;
}

static void c4_eml_scalar_eg(SFc4_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc4_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static int32_T c4_f_emlrt_marshallIn(SFc4_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i54;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i54, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i54;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc4_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_g_emlrt_marshallIn(SFc4_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_CusakisME4901arcs, const
  char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_CusakisME4901arcs), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_CusakisME4901arcs);
  return c4_y;
}

static uint8_T c4_h_emlrt_marshallIn(SFc4_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_CusakisME4901arcsInstanceStruct
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

void sf_c4_CusakisME4901arcs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1433790542U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4179083452U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1180993057U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2736307113U);
}

mxArray *sf_c4_CusakisME4901arcs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("sNQz0rVOSCc44rkQK4rDUE");
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_CusakisME4901arcs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c4_CusakisME4901arcs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[9],T\"G\",},{M[8],M[0],T\"is_active_c4_CusakisME4901arcs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_CusakisME4901arcs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_CusakisME4901arcsInstanceStruct *chartInstance;
    chartInstance = (SFc4_CusakisME4901arcsInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CusakisME4901arcsMachineNumber_,
           4,
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
          init_script_number_translation(_CusakisME4901arcsMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_CusakisME4901arcsMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _CusakisME4901arcsMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"qqd");
          _SFD_SET_DATA_PROPS(1,2,0,1,"G");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,698);
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
            1.0,0,0,(MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)c4_b_sf_marshallIn);

        {
          real_T (*c4_qqd)[9];
          real_T (*c4_G)[3];
          c4_G = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c4_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c4_qqd);
          _SFD_SET_DATA_VALUE_PTR(1U, *c4_G);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c4_l);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c4_m);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _CusakisME4901arcsMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "SbA7bWycDUQePX7JgrhD7C";
}

static void sf_opaque_initialize_c4_CusakisME4901arcs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_CusakisME4901arcs((SFc4_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
  initialize_c4_CusakisME4901arcs((SFc4_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_CusakisME4901arcs(void *chartInstanceVar)
{
  enable_c4_CusakisME4901arcs((SFc4_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c4_CusakisME4901arcs(void *chartInstanceVar)
{
  disable_c4_CusakisME4901arcs((SFc4_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_CusakisME4901arcs(void *chartInstanceVar)
{
  sf_c4_CusakisME4901arcs((SFc4_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_CusakisME4901arcs(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_CusakisME4901arcs
    ((SFc4_CusakisME4901arcsInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_CusakisME4901arcs();/* state var info */
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

extern void sf_internal_set_sim_state_c4_CusakisME4901arcs(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_CusakisME4901arcs();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_CusakisME4901arcs((SFc4_CusakisME4901arcsInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_CusakisME4901arcs(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_CusakisME4901arcs(S);
}

static void sf_opaque_set_sim_state_c4_CusakisME4901arcs(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c4_CusakisME4901arcs(S, st);
}

static void sf_opaque_terminate_c4_CusakisME4901arcs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_CusakisME4901arcsInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CusakisME4901arcs_optimization_info();
    }

    finalize_c4_CusakisME4901arcs((SFc4_CusakisME4901arcsInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_CusakisME4901arcs((SFc4_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_CusakisME4901arcs(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_CusakisME4901arcs((SFc4_CusakisME4901arcsInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_CusakisME4901arcs(SimStruct *S)
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
    mxArray *infoStruct = load_CusakisME4901arcs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,4,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(642933166U));
  ssSetChecksum1(S,(2352851884U));
  ssSetChecksum2(S,(2326180366U));
  ssSetChecksum3(S,(1657417026U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_CusakisME4901arcs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_CusakisME4901arcs(SimStruct *S)
{
  SFc4_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc4_CusakisME4901arcsInstanceStruct *)utMalloc(sizeof
    (SFc4_CusakisME4901arcsInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_CusakisME4901arcsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_CusakisME4901arcs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_CusakisME4901arcs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_CusakisME4901arcs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_CusakisME4901arcs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_CusakisME4901arcs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_CusakisME4901arcs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_CusakisME4901arcs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_CusakisME4901arcs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_CusakisME4901arcs;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_CusakisME4901arcs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_CusakisME4901arcs;
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

void c4_CusakisME4901arcs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_CusakisME4901arcs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_CusakisME4901arcs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_CusakisME4901arcs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_CusakisME4901arcs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
