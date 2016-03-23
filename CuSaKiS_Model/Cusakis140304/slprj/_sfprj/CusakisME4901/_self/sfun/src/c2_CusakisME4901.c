/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CusakisME4901_sfun.h"
#include "c2_CusakisME4901.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CusakisME4901_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[15] = { "q", "g", "Jp1", "Jo1", "Jp2",
  "Jo2", "Jp3", "Jo3", "G1", "nargin", "nargout", "qqd", "l", "m", "G" };

/* Function Declarations */
static void initialize_c2_CusakisME4901(SFc2_CusakisME4901InstanceStruct
  *chartInstance);
static void initialize_params_c2_CusakisME4901(SFc2_CusakisME4901InstanceStruct *
  chartInstance);
static void enable_c2_CusakisME4901(SFc2_CusakisME4901InstanceStruct
  *chartInstance);
static void disable_c2_CusakisME4901(SFc2_CusakisME4901InstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_CusakisME4901
  (SFc2_CusakisME4901InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_CusakisME4901
  (SFc2_CusakisME4901InstanceStruct *chartInstance);
static void set_sim_state_c2_CusakisME4901(SFc2_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_CusakisME4901(SFc2_CusakisME4901InstanceStruct
  *chartInstance);
static void sf_c2_CusakisME4901(SFc2_CusakisME4901InstanceStruct *chartInstance);
static void c2_chartstep_c2_CusakisME4901(SFc2_CusakisME4901InstanceStruct
  *chartInstance);
static void initSimStructsc2_CusakisME4901(SFc2_CusakisME4901InstanceStruct
  *chartInstance);
static void registerMessagesc2_CusakisME4901(SFc2_CusakisME4901InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_CusakisME4901InstanceStruct *chartInstance,
  const mxArray *c2_G, const char_T *c2_identifier, real_T c2_y[3]);
static void c2_b_emlrt_marshallIn(SFc2_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[3]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_emlrt_marshallIn(SFc2_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[3]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_e_emlrt_marshallIn(SFc2_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[9]);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[17]);
static void c2_eml_scalar_eg(SFc2_CusakisME4901InstanceStruct *chartInstance);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_f_emlrt_marshallIn(SFc2_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_g_emlrt_marshallIn(SFc2_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_CusakisME4901, const char_T
  *c2_identifier);
static uint8_T c2_h_emlrt_marshallIn(SFc2_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_CusakisME4901InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_CusakisME4901(SFc2_CusakisME4901InstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_CusakisME4901 = 0U;
}

static void initialize_params_c2_CusakisME4901(SFc2_CusakisME4901InstanceStruct *
  chartInstance)
{
  real_T c2_d0;
  real_T c2_d1;
  sf_set_error_prefix_string(
    "Error evaluating data 'l' in the parent workspace.\n");
  sf_mex_import_named("l", sf_mex_get_sfun_param(chartInstance->S, 0, 0), &c2_d0,
                      0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_l = c2_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'm' in the parent workspace.\n");
  sf_mex_import_named("m", sf_mex_get_sfun_param(chartInstance->S, 1, 0), &c2_d1,
                      0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_m = c2_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c2_CusakisME4901(SFc2_CusakisME4901InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_CusakisME4901(SFc2_CusakisME4901InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_CusakisME4901
  (SFc2_CusakisME4901InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_CusakisME4901
  (SFc2_CusakisME4901InstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[3];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T (*c2_G)[3];
  c2_G = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2), FALSE);
  for (c2_i0 = 0; c2_i0 < 3; c2_i0++) {
    c2_u[c2_i0] = (*c2_G)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_CusakisME4901;
  c2_b_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_CusakisME4901(SFc2_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[3];
  int32_T c2_i1;
  real_T (*c2_G)[3];
  c2_G = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "G",
                      c2_dv0);
  for (c2_i1 = 0; c2_i1 < 3; c2_i1++) {
    (*c2_G)[c2_i1] = c2_dv0[c2_i1];
  }

  chartInstance->c2_is_active_c2_CusakisME4901 = c2_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
     "is_active_c2_CusakisME4901");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_CusakisME4901(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_CusakisME4901(SFc2_CusakisME4901InstanceStruct
  *chartInstance)
{
}

static void sf_c2_CusakisME4901(SFc2_CusakisME4901InstanceStruct *chartInstance)
{
  int32_T c2_i2;
  int32_T c2_i3;
  real_T (*c2_G)[3];
  real_T (*c2_qqd)[9];
  c2_G = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i2 = 0; c2_i2 < 9; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*c2_qqd)[c2_i2], 0U);
  }

  for (c2_i3 = 0; c2_i3 < 3; c2_i3++) {
    _SFD_DATA_RANGE_CHECK((*c2_G)[c2_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c2_l, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c2_m, 3U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_CusakisME4901(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CusakisME4901MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_CusakisME4901(SFc2_CusakisME4901InstanceStruct
  *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  int32_T c2_i4;
  real_T c2_qqd[9];
  real_T c2_b_l;
  real_T c2_b_m;
  uint32_T c2_debug_family_var_map[15];
  real_T c2_q[3];
  real_T c2_g[3];
  real_T c2_Jp1[9];
  real_T c2_Jo1[9];
  real_T c2_Jp2[9];
  real_T c2_Jo2[9];
  real_T c2_Jp3[9];
  real_T c2_Jo3[9];
  real_T c2_G1[3];
  real_T c2_nargin = 3.0;
  real_T c2_nargout = 1.0;
  real_T c2_G[3];
  int32_T c2_i5;
  static real_T c2_b[3] = { 0.0, 9.81, 0.0 };

  real_T c2_A;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_y;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_a;
  real_T c2_b_b;
  real_T c2_b_y;
  real_T c2_b_A;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_c_y;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_b_a;
  real_T c2_c_b;
  real_T c2_d_y;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  static real_T c2_dv1[9] = { 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_c_a;
  real_T c2_d_b;
  real_T c2_e_y;
  real_T c2_c_A;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_f_y;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_d_a;
  real_T c2_e_b;
  real_T c2_g_y;
  real_T c2_d_A;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T c2_h_y;
  real_T c2_q_x;
  real_T c2_r_x;
  real_T c2_e_a;
  real_T c2_f_b;
  real_T c2_i_y;
  real_T c2_s_x;
  real_T c2_t_x;
  real_T c2_f_a;
  real_T c2_g_b;
  real_T c2_j_y;
  real_T c2_e_A;
  real_T c2_u_x;
  real_T c2_v_x;
  real_T c2_k_y;
  real_T c2_w_x;
  real_T c2_x_x;
  real_T c2_g_a;
  real_T c2_h_b;
  real_T c2_l_y;
  real_T c2_f_A;
  real_T c2_y_x;
  real_T c2_ab_x;
  real_T c2_m_y;
  real_T c2_bb_x;
  real_T c2_cb_x;
  real_T c2_h_a;
  real_T c2_i_b;
  real_T c2_n_y;
  int32_T c2_i9;
  int32_T c2_i10;
  int32_T c2_i11;
  static real_T c2_dv2[9] = { 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0 };

  real_T c2_db_x;
  real_T c2_eb_x;
  real_T c2_i_a;
  real_T c2_j_b;
  real_T c2_o_y;
  real_T c2_fb_x;
  real_T c2_gb_x;
  real_T c2_j_a;
  real_T c2_k_b;
  real_T c2_p_y;
  real_T c2_g_A;
  real_T c2_hb_x;
  real_T c2_ib_x;
  real_T c2_q_y;
  real_T c2_jb_x;
  real_T c2_kb_x;
  real_T c2_k_a;
  real_T c2_l_b;
  real_T c2_r_y;
  real_T c2_lb_x;
  real_T c2_mb_x;
  real_T c2_l_a;
  real_T c2_m_b;
  real_T c2_s_y;
  real_T c2_h_A;
  real_T c2_nb_x;
  real_T c2_ob_x;
  real_T c2_t_y;
  real_T c2_pb_x;
  real_T c2_qb_x;
  real_T c2_m_a;
  real_T c2_n_b;
  real_T c2_u_y;
  real_T c2_i_A;
  real_T c2_rb_x;
  real_T c2_sb_x;
  real_T c2_v_y;
  real_T c2_tb_x;
  real_T c2_ub_x;
  real_T c2_n_a;
  real_T c2_o_b;
  real_T c2_w_y;
  real_T c2_vb_x;
  real_T c2_wb_x;
  real_T c2_o_a;
  real_T c2_p_b;
  real_T c2_x_y;
  real_T c2_xb_x;
  real_T c2_yb_x;
  real_T c2_p_a;
  real_T c2_q_b;
  real_T c2_y_y;
  real_T c2_j_A;
  real_T c2_ac_x;
  real_T c2_bc_x;
  real_T c2_ab_y;
  real_T c2_cc_x;
  real_T c2_dc_x;
  real_T c2_q_a;
  real_T c2_r_b;
  real_T c2_bb_y;
  real_T c2_ec_x;
  real_T c2_fc_x;
  real_T c2_r_a;
  real_T c2_s_b;
  real_T c2_cb_y;
  real_T c2_k_A;
  real_T c2_gc_x;
  real_T c2_hc_x;
  real_T c2_db_y;
  real_T c2_ic_x;
  real_T c2_jc_x;
  real_T c2_s_a;
  real_T c2_t_b;
  real_T c2_eb_y;
  real_T c2_l_A;
  real_T c2_kc_x;
  real_T c2_lc_x;
  real_T c2_fb_y;
  real_T c2_mc_x;
  real_T c2_nc_x;
  real_T c2_t_a;
  real_T c2_u_b;
  real_T c2_gb_y;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  static real_T c2_dv3[9] = { 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0 };

  real_T c2_u_a;
  int32_T c2_i15;
  real_T c2_hb_y[3];
  int32_T c2_i16;
  real_T c2_v_b[9];
  int32_T c2_i17;
  int32_T c2_i18;
  real_T c2_ib_y[3];
  int32_T c2_i19;
  real_T c2_v_a;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  real_T c2_jb_y[3];
  int32_T c2_i24;
  real_T c2_w_a;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  real_T c2_kb_y[3];
  int32_T c2_i29;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  real_T (*c2_b_G)[3];
  real_T (*c2_b_qqd)[9];
  c2_b_G = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = chartInstance->c2_l;
  c2_b_hoistedGlobal = chartInstance->c2_m;
  for (c2_i4 = 0; c2_i4 < 9; c2_i4++) {
    c2_qqd[c2_i4] = (*c2_b_qqd)[c2_i4];
  }

  c2_b_l = c2_hoistedGlobal;
  c2_b_m = c2_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 15U, 15U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_q, 0U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_g, 1U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Jp1, 2U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Jo1, 3U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Jp2, 4U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Jo2, 5U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Jp3, 6U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Jo3, 7U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_G1, 8U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 9U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 10U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_qqd, 11U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_l, 12U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_m, 13U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_G, 14U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  c2_q[0] = c2_qqd[6];
  c2_q[1] = c2_qqd[7];
  c2_q[2] = c2_qqd[8];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  for (c2_i5 = 0; c2_i5 < 3; c2_i5++) {
    c2_g[c2_i5] = c2_b[c2_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_A = c2_b_l;
  c2_x = c2_A;
  c2_b_x = c2_x;
  c2_y = c2_b_x / 2.0;
  c2_c_x = c2_q[0];
  c2_d_x = c2_c_x;
  c2_d_x = muDoubleScalarSin(c2_d_x);
  c2_a = -c2_y;
  c2_b_b = c2_d_x;
  c2_b_y = c2_a * c2_b_b;
  c2_b_A = c2_b_l;
  c2_e_x = c2_b_A;
  c2_f_x = c2_e_x;
  c2_c_y = c2_f_x / 2.0;
  c2_g_x = c2_q[0];
  c2_h_x = c2_g_x;
  c2_h_x = muDoubleScalarCos(c2_h_x);
  c2_b_a = c2_c_y;
  c2_c_b = c2_h_x;
  c2_d_y = c2_b_a * c2_c_b;
  c2_Jp1[0] = c2_b_y;
  c2_Jp1[3] = 0.0;
  c2_Jp1[6] = 0.0;
  c2_Jp1[1] = c2_d_y;
  c2_Jp1[4] = 0.0;
  c2_Jp1[7] = 0.0;
  c2_i6 = 0;
  for (c2_i7 = 0; c2_i7 < 3; c2_i7++) {
    c2_Jp1[c2_i6 + 2] = 0.0;
    c2_i6 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i8 = 0; c2_i8 < 9; c2_i8++) {
    c2_Jo1[c2_i8] = c2_dv1[c2_i8];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  c2_i_x = c2_q[0];
  c2_j_x = c2_i_x;
  c2_j_x = muDoubleScalarSin(c2_j_x);
  c2_c_a = -c2_b_l;
  c2_d_b = c2_j_x;
  c2_e_y = c2_c_a * c2_d_b;
  c2_c_A = c2_b_l;
  c2_k_x = c2_c_A;
  c2_l_x = c2_k_x;
  c2_f_y = c2_l_x / 2.0;
  c2_m_x = c2_q[0] + c2_q[1];
  c2_n_x = c2_m_x;
  c2_n_x = muDoubleScalarSin(c2_n_x);
  c2_d_a = c2_f_y;
  c2_e_b = c2_n_x;
  c2_g_y = c2_d_a * c2_e_b;
  c2_d_A = c2_b_l;
  c2_o_x = c2_d_A;
  c2_p_x = c2_o_x;
  c2_h_y = c2_p_x / 2.0;
  c2_q_x = c2_q[0] + c2_q[1];
  c2_r_x = c2_q_x;
  c2_r_x = muDoubleScalarSin(c2_r_x);
  c2_e_a = -c2_h_y;
  c2_f_b = c2_r_x;
  c2_i_y = c2_e_a * c2_f_b;
  c2_s_x = c2_q[0];
  c2_t_x = c2_s_x;
  c2_t_x = muDoubleScalarCos(c2_t_x);
  c2_f_a = c2_b_l;
  c2_g_b = c2_t_x;
  c2_j_y = c2_f_a * c2_g_b;
  c2_e_A = c2_b_l;
  c2_u_x = c2_e_A;
  c2_v_x = c2_u_x;
  c2_k_y = c2_v_x / 2.0;
  c2_w_x = c2_q[0] + c2_q[1];
  c2_x_x = c2_w_x;
  c2_x_x = muDoubleScalarCos(c2_x_x);
  c2_g_a = c2_k_y;
  c2_h_b = c2_x_x;
  c2_l_y = c2_g_a * c2_h_b;
  c2_f_A = c2_b_l;
  c2_y_x = c2_f_A;
  c2_ab_x = c2_y_x;
  c2_m_y = c2_ab_x / 2.0;
  c2_bb_x = c2_q[0] + c2_q[1];
  c2_cb_x = c2_bb_x;
  c2_cb_x = muDoubleScalarCos(c2_cb_x);
  c2_h_a = c2_m_y;
  c2_i_b = c2_cb_x;
  c2_n_y = c2_h_a * c2_i_b;
  c2_Jp2[0] = c2_e_y - c2_g_y;
  c2_Jp2[3] = c2_i_y;
  c2_Jp2[6] = 0.0;
  c2_Jp2[1] = c2_j_y + c2_l_y;
  c2_Jp2[4] = c2_n_y;
  c2_Jp2[7] = 0.0;
  c2_i9 = 0;
  for (c2_i10 = 0; c2_i10 < 3; c2_i10++) {
    c2_Jp2[c2_i9 + 2] = 0.0;
    c2_i9 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
  for (c2_i11 = 0; c2_i11 < 9; c2_i11++) {
    c2_Jo2[c2_i11] = c2_dv2[c2_i11];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
  c2_db_x = c2_q[0];
  c2_eb_x = c2_db_x;
  c2_eb_x = muDoubleScalarSin(c2_eb_x);
  c2_i_a = -c2_b_l;
  c2_j_b = c2_eb_x;
  c2_o_y = c2_i_a * c2_j_b;
  c2_fb_x = c2_q[0] + c2_q[1];
  c2_gb_x = c2_fb_x;
  c2_gb_x = muDoubleScalarSin(c2_gb_x);
  c2_j_a = c2_b_l;
  c2_k_b = c2_gb_x;
  c2_p_y = c2_j_a * c2_k_b;
  c2_g_A = c2_b_l;
  c2_hb_x = c2_g_A;
  c2_ib_x = c2_hb_x;
  c2_q_y = c2_ib_x / 2.0;
  c2_jb_x = (c2_q[0] + c2_q[1]) + c2_q[2];
  c2_kb_x = c2_jb_x;
  c2_kb_x = muDoubleScalarSin(c2_kb_x);
  c2_k_a = c2_q_y;
  c2_l_b = c2_kb_x;
  c2_r_y = c2_k_a * c2_l_b;
  c2_lb_x = c2_q[0] + c2_q[1];
  c2_mb_x = c2_lb_x;
  c2_mb_x = muDoubleScalarSin(c2_mb_x);
  c2_l_a = -c2_b_l;
  c2_m_b = c2_mb_x;
  c2_s_y = c2_l_a * c2_m_b;
  c2_h_A = c2_b_l;
  c2_nb_x = c2_h_A;
  c2_ob_x = c2_nb_x;
  c2_t_y = c2_ob_x / 2.0;
  c2_pb_x = (c2_q[0] + c2_q[1]) + c2_q[2];
  c2_qb_x = c2_pb_x;
  c2_qb_x = muDoubleScalarSin(c2_qb_x);
  c2_m_a = c2_t_y;
  c2_n_b = c2_qb_x;
  c2_u_y = c2_m_a * c2_n_b;
  c2_i_A = c2_b_l;
  c2_rb_x = c2_i_A;
  c2_sb_x = c2_rb_x;
  c2_v_y = c2_sb_x / 2.0;
  c2_tb_x = (c2_q[0] + c2_q[1]) + c2_q[2];
  c2_ub_x = c2_tb_x;
  c2_ub_x = muDoubleScalarSin(c2_ub_x);
  c2_n_a = -c2_v_y;
  c2_o_b = c2_ub_x;
  c2_w_y = c2_n_a * c2_o_b;
  c2_vb_x = c2_q[0];
  c2_wb_x = c2_vb_x;
  c2_wb_x = muDoubleScalarCos(c2_wb_x);
  c2_o_a = c2_b_l;
  c2_p_b = c2_wb_x;
  c2_x_y = c2_o_a * c2_p_b;
  c2_xb_x = c2_q[0] + c2_q[1];
  c2_yb_x = c2_xb_x;
  c2_yb_x = muDoubleScalarCos(c2_yb_x);
  c2_p_a = c2_b_l;
  c2_q_b = c2_yb_x;
  c2_y_y = c2_p_a * c2_q_b;
  c2_j_A = c2_b_l;
  c2_ac_x = c2_j_A;
  c2_bc_x = c2_ac_x;
  c2_ab_y = c2_bc_x / 2.0;
  c2_cc_x = (c2_q[0] + c2_q[1]) + c2_q[2];
  c2_dc_x = c2_cc_x;
  c2_dc_x = muDoubleScalarCos(c2_dc_x);
  c2_q_a = c2_ab_y;
  c2_r_b = c2_dc_x;
  c2_bb_y = c2_q_a * c2_r_b;
  c2_ec_x = c2_q[0] + c2_q[1];
  c2_fc_x = c2_ec_x;
  c2_fc_x = muDoubleScalarCos(c2_fc_x);
  c2_r_a = c2_b_l;
  c2_s_b = c2_fc_x;
  c2_cb_y = c2_r_a * c2_s_b;
  c2_k_A = c2_b_l;
  c2_gc_x = c2_k_A;
  c2_hc_x = c2_gc_x;
  c2_db_y = c2_hc_x / 2.0;
  c2_ic_x = (c2_q[0] + c2_q[1]) + c2_q[2];
  c2_jc_x = c2_ic_x;
  c2_jc_x = muDoubleScalarCos(c2_jc_x);
  c2_s_a = c2_db_y;
  c2_t_b = c2_jc_x;
  c2_eb_y = c2_s_a * c2_t_b;
  c2_l_A = c2_b_l;
  c2_kc_x = c2_l_A;
  c2_lc_x = c2_kc_x;
  c2_fb_y = c2_lc_x / 2.0;
  c2_mc_x = (c2_q[0] + c2_q[1]) + c2_q[2];
  c2_nc_x = c2_mc_x;
  c2_nc_x = muDoubleScalarCos(c2_nc_x);
  c2_t_a = c2_fb_y;
  c2_u_b = c2_nc_x;
  c2_gb_y = c2_t_a * c2_u_b;
  c2_Jp3[0] = (c2_o_y - c2_p_y) - c2_r_y;
  c2_Jp3[3] = c2_s_y - c2_u_y;
  c2_Jp3[6] = c2_w_y;
  c2_Jp3[1] = (c2_x_y + c2_y_y) + c2_bb_y;
  c2_Jp3[4] = c2_cb_y + c2_eb_y;
  c2_Jp3[7] = c2_gb_y;
  c2_i12 = 0;
  for (c2_i13 = 0; c2_i13 < 3; c2_i13++) {
    c2_Jp3[c2_i12 + 2] = 0.0;
    c2_i12 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
  for (c2_i14 = 0; c2_i14 < 9; c2_i14++) {
    c2_Jo3[c2_i14] = c2_dv3[c2_i14];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 17);
  c2_u_a = c2_b_m;
  for (c2_i15 = 0; c2_i15 < 3; c2_i15++) {
    c2_hb_y[c2_i15] = c2_u_a * c2_b[c2_i15];
  }

  for (c2_i16 = 0; c2_i16 < 9; c2_i16++) {
    c2_v_b[c2_i16] = c2_Jp1[c2_i16];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  c2_i17 = 0;
  for (c2_i18 = 0; c2_i18 < 3; c2_i18++) {
    c2_ib_y[c2_i18] = 0.0;
    for (c2_i19 = 0; c2_i19 < 3; c2_i19++) {
      c2_ib_y[c2_i18] += c2_hb_y[c2_i19] * c2_v_b[c2_i19 + c2_i17];
    }

    c2_i17 += 3;
  }

  c2_v_a = c2_b_m;
  for (c2_i20 = 0; c2_i20 < 3; c2_i20++) {
    c2_hb_y[c2_i20] = c2_v_a * c2_b[c2_i20];
  }

  for (c2_i21 = 0; c2_i21 < 9; c2_i21++) {
    c2_v_b[c2_i21] = c2_Jp2[c2_i21];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  c2_i22 = 0;
  for (c2_i23 = 0; c2_i23 < 3; c2_i23++) {
    c2_jb_y[c2_i23] = 0.0;
    for (c2_i24 = 0; c2_i24 < 3; c2_i24++) {
      c2_jb_y[c2_i23] += c2_hb_y[c2_i24] * c2_v_b[c2_i24 + c2_i22];
    }

    c2_i22 += 3;
  }

  c2_w_a = c2_b_m;
  for (c2_i25 = 0; c2_i25 < 3; c2_i25++) {
    c2_hb_y[c2_i25] = c2_w_a * c2_b[c2_i25];
  }

  for (c2_i26 = 0; c2_i26 < 9; c2_i26++) {
    c2_v_b[c2_i26] = c2_Jp3[c2_i26];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  c2_i27 = 0;
  for (c2_i28 = 0; c2_i28 < 3; c2_i28++) {
    c2_kb_y[c2_i28] = 0.0;
    for (c2_i29 = 0; c2_i29 < 3; c2_i29++) {
      c2_kb_y[c2_i28] += c2_hb_y[c2_i29] * c2_v_b[c2_i29 + c2_i27];
    }

    c2_i27 += 3;
  }

  for (c2_i30 = 0; c2_i30 < 3; c2_i30++) {
    c2_G1[c2_i30] = (c2_ib_y[c2_i30] + c2_jb_y[c2_i30]) + c2_kb_y[c2_i30];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 21);
  for (c2_i31 = 0; c2_i31 < 3; c2_i31++) {
    c2_G[c2_i31] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -21);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i32 = 0; c2_i32 < 3; c2_i32++) {
    (*c2_b_G)[c2_i32] = c2_G[c2_i32];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_CusakisME4901(SFc2_CusakisME4901InstanceStruct
  *chartInstance)
{
}

static void registerMessagesc2_CusakisME4901(SFc2_CusakisME4901InstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i33;
  real_T c2_b_inData[3];
  int32_T c2_i34;
  real_T c2_u[3];
  const mxArray *c2_y = NULL;
  SFc2_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc2_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i33 = 0; c2_i33 < 3; c2_i33++) {
    c2_b_inData[c2_i33] = (*(real_T (*)[3])c2_inData)[c2_i33];
  }

  for (c2_i34 = 0; c2_i34 < 3; c2_i34++) {
    c2_u[c2_i34] = c2_b_inData[c2_i34];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_CusakisME4901InstanceStruct *chartInstance,
  const mxArray *c2_G, const char_T *c2_identifier, real_T c2_y[3])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_G), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_G);
}

static void c2_b_emlrt_marshallIn(SFc2_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[3])
{
  real_T c2_dv4[3];
  int32_T c2_i35;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv4, 1, 0, 0U, 1, 0U, 1, 3);
  for (c2_i35 = 0; c2_i35 < 3; c2_i35++) {
    c2_y[c2_i35] = c2_dv4[c2_i35];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_G;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[3];
  int32_T c2_i36;
  SFc2_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc2_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c2_G = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_G), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_G);
  for (c2_i36 = 0; c2_i36 < 3; c2_i36++) {
    (*(real_T (*)[3])c2_outData)[c2_i36] = c2_y[c2_i36];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc2_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d2;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d2, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d2;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_m;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc2_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c2_b_m = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_m), &c2_thisId);
  sf_mex_destroy(&c2_b_m);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i37;
  real_T c2_b_inData[9];
  int32_T c2_i38;
  real_T c2_u[9];
  const mxArray *c2_y = NULL;
  SFc2_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc2_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i37 = 0; c2_i37 < 9; c2_i37++) {
    c2_b_inData[c2_i37] = (*(real_T (*)[9])c2_inData)[c2_i37];
  }

  for (c2_i38 = 0; c2_i38 < 9; c2_i38++) {
    c2_u[c2_i38] = c2_b_inData[c2_i38];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 9), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i39;
  real_T c2_b_inData[3];
  int32_T c2_i40;
  real_T c2_u[3];
  const mxArray *c2_y = NULL;
  SFc2_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc2_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i39 = 0; c2_i39 < 3; c2_i39++) {
    c2_b_inData[c2_i39] = (*(real_T (*)[3])c2_inData)[c2_i39];
  }

  for (c2_i40 = 0; c2_i40 < 3; c2_i40++) {
    c2_u[c2_i40] = c2_b_inData[c2_i40];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn(SFc2_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[3])
{
  real_T c2_dv5[3];
  int32_T c2_i41;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv5, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c2_i41 = 0; c2_i41 < 3; c2_i41++) {
    c2_y[c2_i41] = c2_dv5[c2_i41];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_G1;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[3];
  int32_T c2_i42;
  SFc2_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc2_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c2_G1 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_G1), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_G1);
  for (c2_i42 = 0; c2_i42 < 3; c2_i42++) {
    (*(real_T (*)[3])c2_outData)[c2_i42] = c2_y[c2_i42];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i43;
  int32_T c2_i44;
  int32_T c2_i45;
  real_T c2_b_inData[9];
  int32_T c2_i46;
  int32_T c2_i47;
  int32_T c2_i48;
  real_T c2_u[9];
  const mxArray *c2_y = NULL;
  SFc2_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc2_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i43 = 0;
  for (c2_i44 = 0; c2_i44 < 3; c2_i44++) {
    for (c2_i45 = 0; c2_i45 < 3; c2_i45++) {
      c2_b_inData[c2_i45 + c2_i43] = (*(real_T (*)[9])c2_inData)[c2_i45 + c2_i43];
    }

    c2_i43 += 3;
  }

  c2_i46 = 0;
  for (c2_i47 = 0; c2_i47 < 3; c2_i47++) {
    for (c2_i48 = 0; c2_i48 < 3; c2_i48++) {
      c2_u[c2_i48 + c2_i46] = c2_b_inData[c2_i48 + c2_i46];
    }

    c2_i46 += 3;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_e_emlrt_marshallIn(SFc2_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[9])
{
  real_T c2_dv6[9];
  int32_T c2_i49;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv6, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c2_i49 = 0; c2_i49 < 9; c2_i49++) {
    c2_y[c2_i49] = c2_dv6[c2_i49];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Jo3;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[9];
  int32_T c2_i50;
  int32_T c2_i51;
  int32_T c2_i52;
  SFc2_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc2_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c2_Jo3 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Jo3), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Jo3);
  c2_i50 = 0;
  for (c2_i51 = 0; c2_i51 < 3; c2_i51++) {
    for (c2_i52 = 0; c2_i52 < 3; c2_i52++) {
      (*(real_T (*)[9])c2_outData)[c2_i52 + c2_i50] = c2_y[c2_i52 + c2_i50];
    }

    c2_i50 += 3;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_CusakisME4901_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[17];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i53;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 17), FALSE);
  for (c2_i53 = 0; c2_i53 < 17; c2_i53++) {
    c2_r0 = &c2_info[c2_i53];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i53);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i53);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i53);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i53);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i53);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i53);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i53);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i53);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[17])
{
  c2_info[0].context = "";
  c2_info[0].name = "mrdivide";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[0].fileTimeLo = 1357983948U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 1319762366U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[1].name = "rdivide";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[1].fileTimeLo = 1346542788U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[2].name = "eml_scalexp_compatible";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c2_info[2].fileTimeLo = 1286851196U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[3].name = "eml_div";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[3].fileTimeLo = 1313380210U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context = "";
  c2_info[4].name = "sin";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[4].fileTimeLo = 1343862786U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[5].name = "eml_scalar_sin";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c2_info[5].fileTimeLo = 1286851136U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context = "";
  c2_info[6].name = "mtimes";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[6].fileTimeLo = 1289552092U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context = "";
  c2_info[7].name = "cos";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[7].fileTimeLo = 1343862772U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[8].name = "eml_scalar_cos";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c2_info[8].fileTimeLo = 1286851122U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[9].name = "eml_index_class";
  c2_info[9].dominantType = "";
  c2_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[9].fileTimeLo = 1323202978U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[10].name = "eml_scalar_eg";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[10].fileTimeLo = 1286851196U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[11].name = "eml_xgemm";
  c2_info[11].dominantType = "char";
  c2_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[11].fileTimeLo = 1299109172U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[12].name = "eml_blas_inline";
  c2_info[12].dominantType = "";
  c2_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[12].fileTimeLo = 1299109168U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c2_info[13].name = "mtimes";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[13].fileTimeLo = 1289552092U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[14].name = "eml_index_class";
  c2_info[14].dominantType = "";
  c2_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[14].fileTimeLo = 1323202978U;
  c2_info[14].fileTimeHi = 0U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[15].name = "eml_scalar_eg";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[15].fileTimeLo = 1286851196U;
  c2_info[15].fileTimeHi = 0U;
  c2_info[15].mFileTimeLo = 0U;
  c2_info[15].mFileTimeHi = 0U;
  c2_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[16].name = "eml_refblas_xgemm";
  c2_info[16].dominantType = "char";
  c2_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[16].fileTimeLo = 1299109174U;
  c2_info[16].fileTimeHi = 0U;
  c2_info[16].mFileTimeLo = 0U;
  c2_info[16].mFileTimeHi = 0U;
}

static void c2_eml_scalar_eg(SFc2_CusakisME4901InstanceStruct *chartInstance)
{
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc2_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_f_emlrt_marshallIn(SFc2_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i54;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i54, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i54;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc2_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_g_emlrt_marshallIn(SFc2_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_CusakisME4901, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_CusakisME4901), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_CusakisME4901);
  return c2_y;
}

static uint8_T c2_h_emlrt_marshallIn(SFc2_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_CusakisME4901InstanceStruct
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

void sf_c2_CusakisME4901_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3637873649U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1061965532U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1942410086U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3604145272U);
}

mxArray *sf_c2_CusakisME4901_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("4x3KfHmyheDG6DcQf7gdxG");
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

mxArray *sf_c2_CusakisME4901_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c2_CusakisME4901(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[9],T\"G\",},{M[8],M[0],T\"is_active_c2_CusakisME4901\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_CusakisME4901_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_CusakisME4901InstanceStruct *chartInstance;
    chartInstance = (SFc2_CusakisME4901InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CusakisME4901MachineNumber_,
           2,
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
          init_script_number_translation(_CusakisME4901MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_CusakisME4901MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _CusakisME4901MachineNumber_,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,696);
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
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);

        {
          real_T (*c2_qqd)[9];
          real_T (*c2_G)[3];
          c2_G = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_qqd);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_G);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c2_l);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c2_m);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _CusakisME4901MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "cFSGGLbeJ0RLuqJ7HWvbJD";
}

static void sf_opaque_initialize_c2_CusakisME4901(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_CusakisME4901InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_CusakisME4901((SFc2_CusakisME4901InstanceStruct*)
    chartInstanceVar);
  initialize_c2_CusakisME4901((SFc2_CusakisME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_CusakisME4901(void *chartInstanceVar)
{
  enable_c2_CusakisME4901((SFc2_CusakisME4901InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_CusakisME4901(void *chartInstanceVar)
{
  disable_c2_CusakisME4901((SFc2_CusakisME4901InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_CusakisME4901(void *chartInstanceVar)
{
  sf_c2_CusakisME4901((SFc2_CusakisME4901InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_CusakisME4901(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_CusakisME4901
    ((SFc2_CusakisME4901InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_CusakisME4901();/* state var info */
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

extern void sf_internal_set_sim_state_c2_CusakisME4901(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_CusakisME4901();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_CusakisME4901((SFc2_CusakisME4901InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_CusakisME4901(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_CusakisME4901(S);
}

static void sf_opaque_set_sim_state_c2_CusakisME4901(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c2_CusakisME4901(S, st);
}

static void sf_opaque_terminate_c2_CusakisME4901(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_CusakisME4901InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CusakisME4901_optimization_info();
    }

    finalize_c2_CusakisME4901((SFc2_CusakisME4901InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_CusakisME4901((SFc2_CusakisME4901InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_CusakisME4901(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_CusakisME4901((SFc2_CusakisME4901InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_CusakisME4901(SimStruct *S)
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
    mxArray *infoStruct = load_CusakisME4901_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1817566044U));
  ssSetChecksum1(S,(2241804010U));
  ssSetChecksum2(S,(1463058515U));
  ssSetChecksum3(S,(4056075685U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_CusakisME4901(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_CusakisME4901(SimStruct *S)
{
  SFc2_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc2_CusakisME4901InstanceStruct *)utMalloc(sizeof
    (SFc2_CusakisME4901InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_CusakisME4901InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_CusakisME4901;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_CusakisME4901;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_CusakisME4901;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_CusakisME4901;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_CusakisME4901;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_CusakisME4901;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_CusakisME4901;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_CusakisME4901;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_CusakisME4901;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_CusakisME4901;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_CusakisME4901;
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

void c2_CusakisME4901_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_CusakisME4901(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_CusakisME4901(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_CusakisME4901(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_CusakisME4901_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
