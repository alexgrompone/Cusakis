/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CusakisME4901arcs2_sfun.h"
#include "c5_CusakisME4901arcs2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CusakisME4901arcs2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c5_debug_family_names[17] = { "q", "I", "Jp1", "Jo1", "Jp2",
  "Jo2", "Jp3", "Jo3", "H1", "H2", "H3", "nargin", "nargout", "qqd", "l", "m",
  "H" };

/* Function Declarations */
static void initialize_c5_CusakisME4901arcs2
  (SFc5_CusakisME4901arcs2InstanceStruct *chartInstance);
static void initialize_params_c5_CusakisME4901arcs2
  (SFc5_CusakisME4901arcs2InstanceStruct *chartInstance);
static void enable_c5_CusakisME4901arcs2(SFc5_CusakisME4901arcs2InstanceStruct
  *chartInstance);
static void disable_c5_CusakisME4901arcs2(SFc5_CusakisME4901arcs2InstanceStruct *
  chartInstance);
static void c5_update_debugger_state_c5_CusakisME4901arcs2
  (SFc5_CusakisME4901arcs2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_CusakisME4901arcs2
  (SFc5_CusakisME4901arcs2InstanceStruct *chartInstance);
static void set_sim_state_c5_CusakisME4901arcs2
  (SFc5_CusakisME4901arcs2InstanceStruct *chartInstance, const mxArray *c5_st);
static void finalize_c5_CusakisME4901arcs2(SFc5_CusakisME4901arcs2InstanceStruct
  *chartInstance);
static void sf_c5_CusakisME4901arcs2(SFc5_CusakisME4901arcs2InstanceStruct
  *chartInstance);
static void c5_chartstep_c5_CusakisME4901arcs2
  (SFc5_CusakisME4901arcs2InstanceStruct *chartInstance);
static void initSimStructsc5_CusakisME4901arcs2
  (SFc5_CusakisME4901arcs2InstanceStruct *chartInstance);
static void registerMessagesc5_CusakisME4901arcs2
  (SFc5_CusakisME4901arcs2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static void c5_emlrt_marshallIn(SFc5_CusakisME4901arcs2InstanceStruct
  *chartInstance, const mxArray *c5_H, const char_T *c5_identifier, real_T c5_y
  [9]);
static void c5_b_emlrt_marshallIn(SFc5_CusakisME4901arcs2InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[9]);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static real_T c5_c_emlrt_marshallIn(SFc5_CusakisME4901arcs2InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_d_emlrt_marshallIn(SFc5_CusakisME4901arcs2InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[3]);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[25]);
static real_T c5_mpower(SFc5_CusakisME4901arcs2InstanceStruct *chartInstance,
  real_T c5_a);
static void c5_eml_scalar_eg(SFc5_CusakisME4901arcs2InstanceStruct
  *chartInstance);
static void c5_b_eml_scalar_eg(SFc5_CusakisME4901arcs2InstanceStruct
  *chartInstance);
static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_e_emlrt_marshallIn(SFc5_CusakisME4901arcs2InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_f_emlrt_marshallIn(SFc5_CusakisME4901arcs2InstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_CusakisME4901arcs2, const
  char_T *c5_identifier);
static uint8_T c5_g_emlrt_marshallIn(SFc5_CusakisME4901arcs2InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_CusakisME4901arcs2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_CusakisME4901arcs2
  (SFc5_CusakisME4901arcs2InstanceStruct *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c5_is_active_c5_CusakisME4901arcs2 = 0U;
}

static void initialize_params_c5_CusakisME4901arcs2
  (SFc5_CusakisME4901arcs2InstanceStruct *chartInstance)
{
  real_T c5_d0;
  real_T c5_d1;
  sf_set_error_prefix_string(
    "Error evaluating data 'l' in the parent workspace.\n");
  sf_mex_import_named("l", sf_mex_get_sfun_param(chartInstance->S, 0, 0), &c5_d0,
                      0, 0, 0U, 0, 0U, 0);
  chartInstance->c5_l = c5_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'm' in the parent workspace.\n");
  sf_mex_import_named("m", sf_mex_get_sfun_param(chartInstance->S, 1, 0), &c5_d1,
                      0, 0, 0U, 0, 0U, 0);
  chartInstance->c5_m = c5_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c5_CusakisME4901arcs2(SFc5_CusakisME4901arcs2InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_CusakisME4901arcs2(SFc5_CusakisME4901arcs2InstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_CusakisME4901arcs2
  (SFc5_CusakisME4901arcs2InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c5_CusakisME4901arcs2
  (SFc5_CusakisME4901arcs2InstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  int32_T c5_i0;
  real_T c5_u[9];
  const mxArray *c5_b_y = NULL;
  uint8_T c5_hoistedGlobal;
  uint8_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T (*c5_H)[9];
  c5_H = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(2), FALSE);
  for (c5_i0 = 0; c5_i0 < 9; c5_i0++) {
    c5_u[c5_i0] = (*c5_H)[c5_i0];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_hoistedGlobal = chartInstance->c5_is_active_c5_CusakisME4901arcs2;
  c5_b_u = c5_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  sf_mex_assign(&c5_st, c5_y, FALSE);
  return c5_st;
}

static void set_sim_state_c5_CusakisME4901arcs2
  (SFc5_CusakisME4901arcs2InstanceStruct *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T c5_dv0[9];
  int32_T c5_i1;
  real_T (*c5_H)[9];
  c5_H = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)), "H",
                      c5_dv0);
  for (c5_i1 = 0; c5_i1 < 9; c5_i1++) {
    (*c5_H)[c5_i1] = c5_dv0[c5_i1];
  }

  chartInstance->c5_is_active_c5_CusakisME4901arcs2 = c5_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)),
     "is_active_c5_CusakisME4901arcs2");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_CusakisME4901arcs2(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_CusakisME4901arcs2(SFc5_CusakisME4901arcs2InstanceStruct
  *chartInstance)
{
}

static void sf_c5_CusakisME4901arcs2(SFc5_CusakisME4901arcs2InstanceStruct
  *chartInstance)
{
  int32_T c5_i2;
  int32_T c5_i3;
  real_T (*c5_qqd)[9];
  real_T (*c5_H)[9];
  c5_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  c5_H = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  for (c5_i2 = 0; c5_i2 < 9; c5_i2++) {
    _SFD_DATA_RANGE_CHECK((*c5_H)[c5_i2], 0U);
  }

  for (c5_i3 = 0; c5_i3 < 9; c5_i3++) {
    _SFD_DATA_RANGE_CHECK((*c5_qqd)[c5_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c5_l, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c5_m, 3U);
  chartInstance->c5_sfEvent = CALL_EVENT;
  c5_chartstep_c5_CusakisME4901arcs2(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CusakisME4901arcs2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c5_chartstep_c5_CusakisME4901arcs2
  (SFc5_CusakisME4901arcs2InstanceStruct *chartInstance)
{
  real_T c5_hoistedGlobal;
  real_T c5_b_hoistedGlobal;
  int32_T c5_i4;
  real_T c5_qqd[9];
  real_T c5_b_l;
  real_T c5_b_m;
  uint32_T c5_debug_family_var_map[17];
  real_T c5_q[3];
  real_T c5_I;
  real_T c5_Jp1[9];
  real_T c5_Jo1[9];
  real_T c5_Jp2[9];
  real_T c5_Jo2[9];
  real_T c5_Jp3[9];
  real_T c5_Jo3[9];
  real_T c5_H1[9];
  real_T c5_H2[9];
  real_T c5_H3[9];
  real_T c5_nargin = 3.0;
  real_T c5_nargout = 1.0;
  real_T c5_H[9];
  real_T c5_b;
  real_T c5_y;
  real_T c5_a;
  real_T c5_b_b;
  real_T c5_A;
  real_T c5_x;
  real_T c5_b_x;
  real_T c5_b_y;
  real_T c5_c_x;
  real_T c5_d_x;
  real_T c5_b_a;
  real_T c5_c_b;
  real_T c5_c_y;
  real_T c5_b_A;
  real_T c5_e_x;
  real_T c5_f_x;
  real_T c5_d_y;
  real_T c5_g_x;
  real_T c5_h_x;
  real_T c5_c_a;
  real_T c5_d_b;
  real_T c5_e_y;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  static real_T c5_e_b[9] = { 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  real_T c5_i_x;
  real_T c5_j_x;
  real_T c5_d_a;
  real_T c5_f_b;
  real_T c5_f_y;
  real_T c5_c_A;
  real_T c5_k_x;
  real_T c5_l_x;
  real_T c5_g_y;
  real_T c5_m_x;
  real_T c5_n_x;
  real_T c5_e_a;
  real_T c5_g_b;
  real_T c5_h_y;
  real_T c5_d_A;
  real_T c5_o_x;
  real_T c5_p_x;
  real_T c5_i_y;
  real_T c5_q_x;
  real_T c5_r_x;
  real_T c5_f_a;
  real_T c5_h_b;
  real_T c5_j_y;
  real_T c5_s_x;
  real_T c5_t_x;
  real_T c5_g_a;
  real_T c5_i_b;
  real_T c5_k_y;
  real_T c5_e_A;
  real_T c5_u_x;
  real_T c5_v_x;
  real_T c5_l_y;
  real_T c5_w_x;
  real_T c5_x_x;
  real_T c5_h_a;
  real_T c5_j_b;
  real_T c5_m_y;
  real_T c5_f_A;
  real_T c5_y_x;
  real_T c5_ab_x;
  real_T c5_n_y;
  real_T c5_bb_x;
  real_T c5_cb_x;
  real_T c5_i_a;
  real_T c5_k_b;
  real_T c5_o_y;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i10;
  static real_T c5_l_b[9] = { 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0 };

  real_T c5_db_x;
  real_T c5_eb_x;
  real_T c5_j_a;
  real_T c5_m_b;
  real_T c5_p_y;
  real_T c5_fb_x;
  real_T c5_gb_x;
  real_T c5_k_a;
  real_T c5_n_b;
  real_T c5_q_y;
  real_T c5_g_A;
  real_T c5_hb_x;
  real_T c5_ib_x;
  real_T c5_r_y;
  real_T c5_jb_x;
  real_T c5_kb_x;
  real_T c5_l_a;
  real_T c5_o_b;
  real_T c5_s_y;
  real_T c5_lb_x;
  real_T c5_mb_x;
  real_T c5_m_a;
  real_T c5_p_b;
  real_T c5_t_y;
  real_T c5_h_A;
  real_T c5_nb_x;
  real_T c5_ob_x;
  real_T c5_u_y;
  real_T c5_pb_x;
  real_T c5_qb_x;
  real_T c5_n_a;
  real_T c5_q_b;
  real_T c5_v_y;
  real_T c5_i_A;
  real_T c5_rb_x;
  real_T c5_sb_x;
  real_T c5_w_y;
  real_T c5_tb_x;
  real_T c5_ub_x;
  real_T c5_o_a;
  real_T c5_r_b;
  real_T c5_x_y;
  real_T c5_vb_x;
  real_T c5_wb_x;
  real_T c5_p_a;
  real_T c5_s_b;
  real_T c5_y_y;
  real_T c5_xb_x;
  real_T c5_yb_x;
  real_T c5_q_a;
  real_T c5_t_b;
  real_T c5_ab_y;
  real_T c5_j_A;
  real_T c5_ac_x;
  real_T c5_bc_x;
  real_T c5_bb_y;
  real_T c5_cc_x;
  real_T c5_dc_x;
  real_T c5_r_a;
  real_T c5_u_b;
  real_T c5_cb_y;
  real_T c5_ec_x;
  real_T c5_fc_x;
  real_T c5_s_a;
  real_T c5_v_b;
  real_T c5_db_y;
  real_T c5_k_A;
  real_T c5_gc_x;
  real_T c5_hc_x;
  real_T c5_eb_y;
  real_T c5_ic_x;
  real_T c5_jc_x;
  real_T c5_t_a;
  real_T c5_w_b;
  real_T c5_fb_y;
  real_T c5_l_A;
  real_T c5_kc_x;
  real_T c5_lc_x;
  real_T c5_gb_y;
  real_T c5_mc_x;
  real_T c5_nc_x;
  real_T c5_u_a;
  real_T c5_x_b;
  real_T c5_hb_y;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  static real_T c5_y_b[9] = { 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0 };

  real_T c5_v_a;
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  int32_T c5_i17;
  real_T c5_ab_b[9];
  int32_T c5_i18;
  int32_T c5_i19;
  real_T c5_bb_b[9];
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  real_T c5_ib_y[9];
  int32_T c5_i23;
  int32_T c5_i24;
  real_T c5_cb_b;
  int32_T c5_i25;
  static real_T c5_w_a[9] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0 };

  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i30;
  int32_T c5_i31;
  real_T c5_x_a;
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i35;
  int32_T c5_i36;
  int32_T c5_i37;
  int32_T c5_i38;
  int32_T c5_i39;
  int32_T c5_i40;
  int32_T c5_i41;
  int32_T c5_i42;
  real_T c5_db_b;
  int32_T c5_i43;
  static real_T c5_y_a[9] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0 };

  int32_T c5_i44;
  int32_T c5_i45;
  int32_T c5_i46;
  int32_T c5_i47;
  int32_T c5_i48;
  int32_T c5_i49;
  real_T c5_ab_a;
  int32_T c5_i50;
  int32_T c5_i51;
  int32_T c5_i52;
  int32_T c5_i53;
  int32_T c5_i54;
  int32_T c5_i55;
  int32_T c5_i56;
  int32_T c5_i57;
  int32_T c5_i58;
  int32_T c5_i59;
  int32_T c5_i60;
  real_T c5_eb_b;
  int32_T c5_i61;
  static real_T c5_bb_a[9] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0 };

  int32_T c5_i62;
  int32_T c5_i63;
  int32_T c5_i64;
  int32_T c5_i65;
  int32_T c5_i66;
  int32_T c5_i67;
  int32_T c5_i68;
  int32_T c5_i69;
  real_T (*c5_b_H)[9];
  real_T (*c5_b_qqd)[9];
  c5_b_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  c5_b_H = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = chartInstance->c5_l;
  c5_b_hoistedGlobal = chartInstance->c5_m;
  for (c5_i4 = 0; c5_i4 < 9; c5_i4++) {
    c5_qqd[c5_i4] = (*c5_b_qqd)[c5_i4];
  }

  c5_b_l = c5_hoistedGlobal;
  c5_b_m = c5_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 17U, 17U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_q, 0U, c5_d_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_I, 1U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_Jp1, 2U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_Jo1, 3U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_Jp2, 4U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_Jo2, 5U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_Jp3, 6U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_Jo3, 7U, c5_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_H1, 8U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_H2, 9U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_H3, 10U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 11U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 12U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_qqd, 13U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_l, 14U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_m, 15U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_H, 16U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 3);
  c5_q[0] = c5_qqd[6];
  c5_q[1] = c5_qqd[7];
  c5_q[2] = c5_qqd[8];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 4);
  c5_b = c5_b_m;
  c5_y = 0.083333333333333329 * c5_b;
  c5_a = c5_y;
  c5_b_b = c5_mpower(chartInstance, c5_b_l);
  c5_I = c5_a * c5_b_b;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 6);
  c5_A = c5_b_l;
  c5_x = c5_A;
  c5_b_x = c5_x;
  c5_b_y = c5_b_x / 2.0;
  c5_c_x = c5_q[0];
  c5_d_x = c5_c_x;
  c5_d_x = muDoubleScalarSin(c5_d_x);
  c5_b_a = -c5_b_y;
  c5_c_b = c5_d_x;
  c5_c_y = c5_b_a * c5_c_b;
  c5_b_A = c5_b_l;
  c5_e_x = c5_b_A;
  c5_f_x = c5_e_x;
  c5_d_y = c5_f_x / 2.0;
  c5_g_x = c5_q[0];
  c5_h_x = c5_g_x;
  c5_h_x = muDoubleScalarCos(c5_h_x);
  c5_c_a = c5_d_y;
  c5_d_b = c5_h_x;
  c5_e_y = c5_c_a * c5_d_b;
  c5_Jp1[0] = c5_c_y;
  c5_Jp1[3] = 0.0;
  c5_Jp1[6] = 0.0;
  c5_Jp1[1] = c5_e_y;
  c5_Jp1[4] = 0.0;
  c5_Jp1[7] = 0.0;
  c5_i5 = 0;
  for (c5_i6 = 0; c5_i6 < 3; c5_i6++) {
    c5_Jp1[c5_i5 + 2] = 0.0;
    c5_i5 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 7);
  for (c5_i7 = 0; c5_i7 < 9; c5_i7++) {
    c5_Jo1[c5_i7] = c5_e_b[c5_i7];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 9);
  c5_i_x = c5_q[0];
  c5_j_x = c5_i_x;
  c5_j_x = muDoubleScalarSin(c5_j_x);
  c5_d_a = -c5_b_l;
  c5_f_b = c5_j_x;
  c5_f_y = c5_d_a * c5_f_b;
  c5_c_A = c5_b_l;
  c5_k_x = c5_c_A;
  c5_l_x = c5_k_x;
  c5_g_y = c5_l_x / 2.0;
  c5_m_x = c5_q[0] + c5_q[1];
  c5_n_x = c5_m_x;
  c5_n_x = muDoubleScalarSin(c5_n_x);
  c5_e_a = c5_g_y;
  c5_g_b = c5_n_x;
  c5_h_y = c5_e_a * c5_g_b;
  c5_d_A = c5_b_l;
  c5_o_x = c5_d_A;
  c5_p_x = c5_o_x;
  c5_i_y = c5_p_x / 2.0;
  c5_q_x = c5_q[0] + c5_q[1];
  c5_r_x = c5_q_x;
  c5_r_x = muDoubleScalarSin(c5_r_x);
  c5_f_a = -c5_i_y;
  c5_h_b = c5_r_x;
  c5_j_y = c5_f_a * c5_h_b;
  c5_s_x = c5_q[0];
  c5_t_x = c5_s_x;
  c5_t_x = muDoubleScalarCos(c5_t_x);
  c5_g_a = c5_b_l;
  c5_i_b = c5_t_x;
  c5_k_y = c5_g_a * c5_i_b;
  c5_e_A = c5_b_l;
  c5_u_x = c5_e_A;
  c5_v_x = c5_u_x;
  c5_l_y = c5_v_x / 2.0;
  c5_w_x = c5_q[0] + c5_q[1];
  c5_x_x = c5_w_x;
  c5_x_x = muDoubleScalarCos(c5_x_x);
  c5_h_a = c5_l_y;
  c5_j_b = c5_x_x;
  c5_m_y = c5_h_a * c5_j_b;
  c5_f_A = c5_b_l;
  c5_y_x = c5_f_A;
  c5_ab_x = c5_y_x;
  c5_n_y = c5_ab_x / 2.0;
  c5_bb_x = c5_q[0] + c5_q[1];
  c5_cb_x = c5_bb_x;
  c5_cb_x = muDoubleScalarCos(c5_cb_x);
  c5_i_a = c5_n_y;
  c5_k_b = c5_cb_x;
  c5_o_y = c5_i_a * c5_k_b;
  c5_Jp2[0] = c5_f_y - c5_h_y;
  c5_Jp2[3] = c5_j_y;
  c5_Jp2[6] = 0.0;
  c5_Jp2[1] = c5_k_y + c5_m_y;
  c5_Jp2[4] = c5_o_y;
  c5_Jp2[7] = 0.0;
  c5_i8 = 0;
  for (c5_i9 = 0; c5_i9 < 3; c5_i9++) {
    c5_Jp2[c5_i8 + 2] = 0.0;
    c5_i8 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i10 = 0; c5_i10 < 9; c5_i10++) {
    c5_Jo2[c5_i10] = c5_l_b[c5_i10];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 12);
  c5_db_x = c5_q[0];
  c5_eb_x = c5_db_x;
  c5_eb_x = muDoubleScalarSin(c5_eb_x);
  c5_j_a = -c5_b_l;
  c5_m_b = c5_eb_x;
  c5_p_y = c5_j_a * c5_m_b;
  c5_fb_x = c5_q[0] + c5_q[1];
  c5_gb_x = c5_fb_x;
  c5_gb_x = muDoubleScalarSin(c5_gb_x);
  c5_k_a = c5_b_l;
  c5_n_b = c5_gb_x;
  c5_q_y = c5_k_a * c5_n_b;
  c5_g_A = c5_b_l;
  c5_hb_x = c5_g_A;
  c5_ib_x = c5_hb_x;
  c5_r_y = c5_ib_x / 2.0;
  c5_jb_x = (c5_q[0] + c5_q[1]) + c5_q[2];
  c5_kb_x = c5_jb_x;
  c5_kb_x = muDoubleScalarSin(c5_kb_x);
  c5_l_a = c5_r_y;
  c5_o_b = c5_kb_x;
  c5_s_y = c5_l_a * c5_o_b;
  c5_lb_x = c5_q[0] + c5_q[1];
  c5_mb_x = c5_lb_x;
  c5_mb_x = muDoubleScalarSin(c5_mb_x);
  c5_m_a = -c5_b_l;
  c5_p_b = c5_mb_x;
  c5_t_y = c5_m_a * c5_p_b;
  c5_h_A = c5_b_l;
  c5_nb_x = c5_h_A;
  c5_ob_x = c5_nb_x;
  c5_u_y = c5_ob_x / 2.0;
  c5_pb_x = (c5_q[0] + c5_q[1]) + c5_q[2];
  c5_qb_x = c5_pb_x;
  c5_qb_x = muDoubleScalarSin(c5_qb_x);
  c5_n_a = c5_u_y;
  c5_q_b = c5_qb_x;
  c5_v_y = c5_n_a * c5_q_b;
  c5_i_A = c5_b_l;
  c5_rb_x = c5_i_A;
  c5_sb_x = c5_rb_x;
  c5_w_y = c5_sb_x / 2.0;
  c5_tb_x = (c5_q[0] + c5_q[1]) + c5_q[2];
  c5_ub_x = c5_tb_x;
  c5_ub_x = muDoubleScalarSin(c5_ub_x);
  c5_o_a = -c5_w_y;
  c5_r_b = c5_ub_x;
  c5_x_y = c5_o_a * c5_r_b;
  c5_vb_x = c5_q[0];
  c5_wb_x = c5_vb_x;
  c5_wb_x = muDoubleScalarCos(c5_wb_x);
  c5_p_a = c5_b_l;
  c5_s_b = c5_wb_x;
  c5_y_y = c5_p_a * c5_s_b;
  c5_xb_x = c5_q[0] + c5_q[1];
  c5_yb_x = c5_xb_x;
  c5_yb_x = muDoubleScalarCos(c5_yb_x);
  c5_q_a = c5_b_l;
  c5_t_b = c5_yb_x;
  c5_ab_y = c5_q_a * c5_t_b;
  c5_j_A = c5_b_l;
  c5_ac_x = c5_j_A;
  c5_bc_x = c5_ac_x;
  c5_bb_y = c5_bc_x / 2.0;
  c5_cc_x = (c5_q[0] + c5_q[1]) + c5_q[2];
  c5_dc_x = c5_cc_x;
  c5_dc_x = muDoubleScalarCos(c5_dc_x);
  c5_r_a = c5_bb_y;
  c5_u_b = c5_dc_x;
  c5_cb_y = c5_r_a * c5_u_b;
  c5_ec_x = c5_q[0] + c5_q[1];
  c5_fc_x = c5_ec_x;
  c5_fc_x = muDoubleScalarCos(c5_fc_x);
  c5_s_a = c5_b_l;
  c5_v_b = c5_fc_x;
  c5_db_y = c5_s_a * c5_v_b;
  c5_k_A = c5_b_l;
  c5_gc_x = c5_k_A;
  c5_hc_x = c5_gc_x;
  c5_eb_y = c5_hc_x / 2.0;
  c5_ic_x = (c5_q[0] + c5_q[1]) + c5_q[2];
  c5_jc_x = c5_ic_x;
  c5_jc_x = muDoubleScalarCos(c5_jc_x);
  c5_t_a = c5_eb_y;
  c5_w_b = c5_jc_x;
  c5_fb_y = c5_t_a * c5_w_b;
  c5_l_A = c5_b_l;
  c5_kc_x = c5_l_A;
  c5_lc_x = c5_kc_x;
  c5_gb_y = c5_lc_x / 2.0;
  c5_mc_x = (c5_q[0] + c5_q[1]) + c5_q[2];
  c5_nc_x = c5_mc_x;
  c5_nc_x = muDoubleScalarCos(c5_nc_x);
  c5_u_a = c5_gb_y;
  c5_x_b = c5_nc_x;
  c5_hb_y = c5_u_a * c5_x_b;
  c5_Jp3[0] = (c5_p_y - c5_q_y) - c5_s_y;
  c5_Jp3[3] = c5_t_y - c5_v_y;
  c5_Jp3[6] = c5_x_y;
  c5_Jp3[1] = (c5_y_y + c5_ab_y) + c5_cb_y;
  c5_Jp3[4] = c5_db_y + c5_fb_y;
  c5_Jp3[7] = c5_hb_y;
  c5_i11 = 0;
  for (c5_i12 = 0; c5_i12 < 3; c5_i12++) {
    c5_Jp3[c5_i11 + 2] = 0.0;
    c5_i11 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 13);
  for (c5_i13 = 0; c5_i13 < 9; c5_i13++) {
    c5_Jo3[c5_i13] = c5_y_b[c5_i13];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 17);
  c5_v_a = c5_b_m;
  c5_i14 = 0;
  for (c5_i15 = 0; c5_i15 < 3; c5_i15++) {
    c5_i16 = 0;
    for (c5_i17 = 0; c5_i17 < 3; c5_i17++) {
      c5_ab_b[c5_i17 + c5_i14] = c5_Jp1[c5_i16 + c5_i15];
      c5_i16 += 3;
    }

    c5_i14 += 3;
  }

  for (c5_i18 = 0; c5_i18 < 9; c5_i18++) {
    c5_ab_b[c5_i18] *= c5_v_a;
  }

  for (c5_i19 = 0; c5_i19 < 9; c5_i19++) {
    c5_bb_b[c5_i19] = c5_Jp1[c5_i19];
  }

  c5_b_eml_scalar_eg(chartInstance);
  c5_b_eml_scalar_eg(chartInstance);
  for (c5_i20 = 0; c5_i20 < 3; c5_i20++) {
    c5_i21 = 0;
    for (c5_i22 = 0; c5_i22 < 3; c5_i22++) {
      c5_ib_y[c5_i21 + c5_i20] = 0.0;
      c5_i23 = 0;
      for (c5_i24 = 0; c5_i24 < 3; c5_i24++) {
        c5_ib_y[c5_i21 + c5_i20] += c5_ab_b[c5_i23 + c5_i20] * c5_bb_b[c5_i24 +
          c5_i21];
        c5_i23 += 3;
      }

      c5_i21 += 3;
    }
  }

  c5_cb_b = c5_I;
  for (c5_i25 = 0; c5_i25 < 9; c5_i25++) {
    c5_ab_b[c5_i25] = c5_w_a[c5_i25] * c5_cb_b;
  }

  c5_b_eml_scalar_eg(chartInstance);
  c5_b_eml_scalar_eg(chartInstance);
  for (c5_i26 = 0; c5_i26 < 3; c5_i26++) {
    c5_i27 = 0;
    for (c5_i28 = 0; c5_i28 < 3; c5_i28++) {
      c5_bb_b[c5_i27 + c5_i26] = 0.0;
      c5_i29 = 0;
      for (c5_i30 = 0; c5_i30 < 3; c5_i30++) {
        c5_bb_b[c5_i27 + c5_i26] += c5_ab_b[c5_i29 + c5_i26] * c5_e_b[c5_i30 +
          c5_i27];
        c5_i29 += 3;
      }

      c5_i27 += 3;
    }
  }

  for (c5_i31 = 0; c5_i31 < 9; c5_i31++) {
    c5_H1[c5_i31] = c5_ib_y[c5_i31] + c5_bb_b[c5_i31];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 18);
  c5_x_a = c5_b_m;
  c5_i32 = 0;
  for (c5_i33 = 0; c5_i33 < 3; c5_i33++) {
    c5_i34 = 0;
    for (c5_i35 = 0; c5_i35 < 3; c5_i35++) {
      c5_ab_b[c5_i35 + c5_i32] = c5_Jp2[c5_i34 + c5_i33];
      c5_i34 += 3;
    }

    c5_i32 += 3;
  }

  for (c5_i36 = 0; c5_i36 < 9; c5_i36++) {
    c5_ab_b[c5_i36] *= c5_x_a;
  }

  for (c5_i37 = 0; c5_i37 < 9; c5_i37++) {
    c5_bb_b[c5_i37] = c5_Jp2[c5_i37];
  }

  c5_b_eml_scalar_eg(chartInstance);
  c5_b_eml_scalar_eg(chartInstance);
  for (c5_i38 = 0; c5_i38 < 3; c5_i38++) {
    c5_i39 = 0;
    for (c5_i40 = 0; c5_i40 < 3; c5_i40++) {
      c5_ib_y[c5_i39 + c5_i38] = 0.0;
      c5_i41 = 0;
      for (c5_i42 = 0; c5_i42 < 3; c5_i42++) {
        c5_ib_y[c5_i39 + c5_i38] += c5_ab_b[c5_i41 + c5_i38] * c5_bb_b[c5_i42 +
          c5_i39];
        c5_i41 += 3;
      }

      c5_i39 += 3;
    }
  }

  c5_db_b = c5_I;
  for (c5_i43 = 0; c5_i43 < 9; c5_i43++) {
    c5_ab_b[c5_i43] = c5_y_a[c5_i43] * c5_db_b;
  }

  c5_b_eml_scalar_eg(chartInstance);
  c5_b_eml_scalar_eg(chartInstance);
  for (c5_i44 = 0; c5_i44 < 3; c5_i44++) {
    c5_i45 = 0;
    for (c5_i46 = 0; c5_i46 < 3; c5_i46++) {
      c5_bb_b[c5_i45 + c5_i44] = 0.0;
      c5_i47 = 0;
      for (c5_i48 = 0; c5_i48 < 3; c5_i48++) {
        c5_bb_b[c5_i45 + c5_i44] += c5_ab_b[c5_i47 + c5_i44] * c5_l_b[c5_i48 +
          c5_i45];
        c5_i47 += 3;
      }

      c5_i45 += 3;
    }
  }

  for (c5_i49 = 0; c5_i49 < 9; c5_i49++) {
    c5_H2[c5_i49] = c5_ib_y[c5_i49] + c5_bb_b[c5_i49];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 19);
  c5_ab_a = c5_b_m;
  c5_i50 = 0;
  for (c5_i51 = 0; c5_i51 < 3; c5_i51++) {
    c5_i52 = 0;
    for (c5_i53 = 0; c5_i53 < 3; c5_i53++) {
      c5_ab_b[c5_i53 + c5_i50] = c5_Jp3[c5_i52 + c5_i51];
      c5_i52 += 3;
    }

    c5_i50 += 3;
  }

  for (c5_i54 = 0; c5_i54 < 9; c5_i54++) {
    c5_ab_b[c5_i54] *= c5_ab_a;
  }

  for (c5_i55 = 0; c5_i55 < 9; c5_i55++) {
    c5_bb_b[c5_i55] = c5_Jp3[c5_i55];
  }

  c5_b_eml_scalar_eg(chartInstance);
  c5_b_eml_scalar_eg(chartInstance);
  for (c5_i56 = 0; c5_i56 < 3; c5_i56++) {
    c5_i57 = 0;
    for (c5_i58 = 0; c5_i58 < 3; c5_i58++) {
      c5_ib_y[c5_i57 + c5_i56] = 0.0;
      c5_i59 = 0;
      for (c5_i60 = 0; c5_i60 < 3; c5_i60++) {
        c5_ib_y[c5_i57 + c5_i56] += c5_ab_b[c5_i59 + c5_i56] * c5_bb_b[c5_i60 +
          c5_i57];
        c5_i59 += 3;
      }

      c5_i57 += 3;
    }
  }

  c5_eb_b = c5_I;
  for (c5_i61 = 0; c5_i61 < 9; c5_i61++) {
    c5_ab_b[c5_i61] = c5_bb_a[c5_i61] * c5_eb_b;
  }

  c5_b_eml_scalar_eg(chartInstance);
  c5_b_eml_scalar_eg(chartInstance);
  for (c5_i62 = 0; c5_i62 < 3; c5_i62++) {
    c5_i63 = 0;
    for (c5_i64 = 0; c5_i64 < 3; c5_i64++) {
      c5_bb_b[c5_i63 + c5_i62] = 0.0;
      c5_i65 = 0;
      for (c5_i66 = 0; c5_i66 < 3; c5_i66++) {
        c5_bb_b[c5_i63 + c5_i62] += c5_ab_b[c5_i65 + c5_i62] * c5_y_b[c5_i66 +
          c5_i63];
        c5_i65 += 3;
      }

      c5_i63 += 3;
    }
  }

  for (c5_i67 = 0; c5_i67 < 9; c5_i67++) {
    c5_H3[c5_i67] = c5_ib_y[c5_i67] + c5_bb_b[c5_i67];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 21);
  for (c5_i68 = 0; c5_i68 < 9; c5_i68++) {
    c5_H[c5_i68] = (c5_H1[c5_i68] + c5_H2[c5_i68]) + c5_H3[c5_i68];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -21);
  _SFD_SYMBOL_SCOPE_POP();
  for (c5_i69 = 0; c5_i69 < 9; c5_i69++) {
    (*c5_b_H)[c5_i69] = c5_H[c5_i69];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
}

static void initSimStructsc5_CusakisME4901arcs2
  (SFc5_CusakisME4901arcs2InstanceStruct *chartInstance)
{
}

static void registerMessagesc5_CusakisME4901arcs2
  (SFc5_CusakisME4901arcs2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i70;
  int32_T c5_i71;
  int32_T c5_i72;
  real_T c5_b_inData[9];
  int32_T c5_i73;
  int32_T c5_i74;
  int32_T c5_i75;
  real_T c5_u[9];
  const mxArray *c5_y = NULL;
  SFc5_CusakisME4901arcs2InstanceStruct *chartInstance;
  chartInstance = (SFc5_CusakisME4901arcs2InstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i70 = 0;
  for (c5_i71 = 0; c5_i71 < 3; c5_i71++) {
    for (c5_i72 = 0; c5_i72 < 3; c5_i72++) {
      c5_b_inData[c5_i72 + c5_i70] = (*(real_T (*)[9])c5_inData)[c5_i72 + c5_i70];
    }

    c5_i70 += 3;
  }

  c5_i73 = 0;
  for (c5_i74 = 0; c5_i74 < 3; c5_i74++) {
    for (c5_i75 = 0; c5_i75 < 3; c5_i75++) {
      c5_u[c5_i75 + c5_i73] = c5_b_inData[c5_i75 + c5_i73];
    }

    c5_i73 += 3;
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static void c5_emlrt_marshallIn(SFc5_CusakisME4901arcs2InstanceStruct
  *chartInstance, const mxArray *c5_H, const char_T *c5_identifier, real_T c5_y
  [9])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_H), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_H);
}

static void c5_b_emlrt_marshallIn(SFc5_CusakisME4901arcs2InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[9])
{
  real_T c5_dv1[9];
  int32_T c5_i76;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv1, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c5_i76 = 0; c5_i76 < 9; c5_i76++) {
    c5_y[c5_i76] = c5_dv1[c5_i76];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_H;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[9];
  int32_T c5_i77;
  int32_T c5_i78;
  int32_T c5_i79;
  SFc5_CusakisME4901arcs2InstanceStruct *chartInstance;
  chartInstance = (SFc5_CusakisME4901arcs2InstanceStruct *)chartInstanceVoid;
  c5_H = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_H), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_H);
  c5_i77 = 0;
  for (c5_i78 = 0; c5_i78 < 3; c5_i78++) {
    for (c5_i79 = 0; c5_i79 < 3; c5_i79++) {
      (*(real_T (*)[9])c5_outData)[c5_i79 + c5_i77] = c5_y[c5_i79 + c5_i77];
    }

    c5_i77 += 3;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_CusakisME4901arcs2InstanceStruct *chartInstance;
  chartInstance = (SFc5_CusakisME4901arcs2InstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static real_T c5_c_emlrt_marshallIn(SFc5_CusakisME4901arcs2InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d2;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d2, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d2;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_m;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_CusakisME4901arcs2InstanceStruct *chartInstance;
  chartInstance = (SFc5_CusakisME4901arcs2InstanceStruct *)chartInstanceVoid;
  c5_b_m = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_m), &c5_thisId);
  sf_mex_destroy(&c5_b_m);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i80;
  real_T c5_b_inData[9];
  int32_T c5_i81;
  real_T c5_u[9];
  const mxArray *c5_y = NULL;
  SFc5_CusakisME4901arcs2InstanceStruct *chartInstance;
  chartInstance = (SFc5_CusakisME4901arcs2InstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i80 = 0; c5_i80 < 9; c5_i80++) {
    c5_b_inData[c5_i80] = (*(real_T (*)[9])c5_inData)[c5_i80];
  }

  for (c5_i81 = 0; c5_i81 < 9; c5_i81++) {
    c5_u[c5_i81] = c5_b_inData[c5_i81];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 9), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i82;
  real_T c5_b_inData[3];
  int32_T c5_i83;
  real_T c5_u[3];
  const mxArray *c5_y = NULL;
  SFc5_CusakisME4901arcs2InstanceStruct *chartInstance;
  chartInstance = (SFc5_CusakisME4901arcs2InstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i82 = 0; c5_i82 < 3; c5_i82++) {
    c5_b_inData[c5_i82] = (*(real_T (*)[3])c5_inData)[c5_i82];
  }

  for (c5_i83 = 0; c5_i83 < 3; c5_i83++) {
    c5_u[c5_i83] = c5_b_inData[c5_i83];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static void c5_d_emlrt_marshallIn(SFc5_CusakisME4901arcs2InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[3])
{
  real_T c5_dv2[3];
  int32_T c5_i84;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv2, 1, 0, 0U, 1, 0U, 1, 3);
  for (c5_i84 = 0; c5_i84 < 3; c5_i84++) {
    c5_y[c5_i84] = c5_dv2[c5_i84];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_q;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[3];
  int32_T c5_i85;
  SFc5_CusakisME4901arcs2InstanceStruct *chartInstance;
  chartInstance = (SFc5_CusakisME4901arcs2InstanceStruct *)chartInstanceVoid;
  c5_q = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_q), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_q);
  for (c5_i85 = 0; c5_i85 < 3; c5_i85++) {
    (*(real_T (*)[3])c5_outData)[c5_i85] = c5_y[c5_i85];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_CusakisME4901arcs2_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo;
  c5_ResolvedFunctionInfo c5_info[25];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i86;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  c5_info_helper(c5_info);
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 25), FALSE);
  for (c5_i86 = 0; c5_i86 < 25; c5_i86++) {
    c5_r0 = &c5_info[c5_i86];
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->context)), "context", "nameCaptureInfo",
                    c5_i86);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c5_r0->name)), "name", "nameCaptureInfo", c5_i86);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c5_i86);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved", "nameCaptureInfo",
                    c5_i86);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c5_i86);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c5_i86);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c5_i86);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c5_i86);
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[25])
{
  c5_info[0].context = "";
  c5_info[0].name = "mrdivide";
  c5_info[0].dominantType = "double";
  c5_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[0].fileTimeLo = 1357983948U;
  c5_info[0].fileTimeHi = 0U;
  c5_info[0].mFileTimeLo = 1319762366U;
  c5_info[0].mFileTimeHi = 0U;
  c5_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[1].name = "rdivide";
  c5_info[1].dominantType = "double";
  c5_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[1].fileTimeLo = 1346542788U;
  c5_info[1].fileTimeHi = 0U;
  c5_info[1].mFileTimeLo = 0U;
  c5_info[1].mFileTimeHi = 0U;
  c5_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[2].name = "eml_scalexp_compatible";
  c5_info[2].dominantType = "double";
  c5_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c5_info[2].fileTimeLo = 1286851196U;
  c5_info[2].fileTimeHi = 0U;
  c5_info[2].mFileTimeLo = 0U;
  c5_info[2].mFileTimeHi = 0U;
  c5_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[3].name = "eml_div";
  c5_info[3].dominantType = "double";
  c5_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c5_info[3].fileTimeLo = 1313380210U;
  c5_info[3].fileTimeHi = 0U;
  c5_info[3].mFileTimeLo = 0U;
  c5_info[3].mFileTimeHi = 0U;
  c5_info[4].context = "";
  c5_info[4].name = "mtimes";
  c5_info[4].dominantType = "double";
  c5_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[4].fileTimeLo = 1289552092U;
  c5_info[4].fileTimeHi = 0U;
  c5_info[4].mFileTimeLo = 0U;
  c5_info[4].mFileTimeHi = 0U;
  c5_info[5].context = "";
  c5_info[5].name = "mpower";
  c5_info[5].dominantType = "double";
  c5_info[5].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c5_info[5].fileTimeLo = 1286851242U;
  c5_info[5].fileTimeHi = 0U;
  c5_info[5].mFileTimeLo = 0U;
  c5_info[5].mFileTimeHi = 0U;
  c5_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c5_info[6].name = "power";
  c5_info[6].dominantType = "double";
  c5_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c5_info[6].fileTimeLo = 1348224330U;
  c5_info[6].fileTimeHi = 0U;
  c5_info[6].mFileTimeLo = 0U;
  c5_info[6].mFileTimeHi = 0U;
  c5_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c5_info[7].name = "eml_scalar_eg";
  c5_info[7].dominantType = "double";
  c5_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[7].fileTimeLo = 1286851196U;
  c5_info[7].fileTimeHi = 0U;
  c5_info[7].mFileTimeLo = 0U;
  c5_info[7].mFileTimeHi = 0U;
  c5_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c5_info[8].name = "eml_scalexp_alloc";
  c5_info[8].dominantType = "double";
  c5_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c5_info[8].fileTimeLo = 1352457260U;
  c5_info[8].fileTimeHi = 0U;
  c5_info[8].mFileTimeLo = 0U;
  c5_info[8].mFileTimeHi = 0U;
  c5_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c5_info[9].name = "floor";
  c5_info[9].dominantType = "double";
  c5_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c5_info[9].fileTimeLo = 1343862780U;
  c5_info[9].fileTimeHi = 0U;
  c5_info[9].mFileTimeLo = 0U;
  c5_info[9].mFileTimeHi = 0U;
  c5_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c5_info[10].name = "eml_scalar_floor";
  c5_info[10].dominantType = "double";
  c5_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c5_info[10].fileTimeLo = 1286851126U;
  c5_info[10].fileTimeHi = 0U;
  c5_info[10].mFileTimeLo = 0U;
  c5_info[10].mFileTimeHi = 0U;
  c5_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c5_info[11].name = "eml_scalar_eg";
  c5_info[11].dominantType = "double";
  c5_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[11].fileTimeLo = 1286851196U;
  c5_info[11].fileTimeHi = 0U;
  c5_info[11].mFileTimeLo = 0U;
  c5_info[11].mFileTimeHi = 0U;
  c5_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c5_info[12].name = "mtimes";
  c5_info[12].dominantType = "double";
  c5_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[12].fileTimeLo = 1289552092U;
  c5_info[12].fileTimeHi = 0U;
  c5_info[12].mFileTimeLo = 0U;
  c5_info[12].mFileTimeHi = 0U;
  c5_info[13].context = "";
  c5_info[13].name = "sin";
  c5_info[13].dominantType = "double";
  c5_info[13].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c5_info[13].fileTimeLo = 1343862786U;
  c5_info[13].fileTimeHi = 0U;
  c5_info[13].mFileTimeLo = 0U;
  c5_info[13].mFileTimeHi = 0U;
  c5_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c5_info[14].name = "eml_scalar_sin";
  c5_info[14].dominantType = "double";
  c5_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c5_info[14].fileTimeLo = 1286851136U;
  c5_info[14].fileTimeHi = 0U;
  c5_info[14].mFileTimeLo = 0U;
  c5_info[14].mFileTimeHi = 0U;
  c5_info[15].context = "";
  c5_info[15].name = "cos";
  c5_info[15].dominantType = "double";
  c5_info[15].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c5_info[15].fileTimeLo = 1343862772U;
  c5_info[15].fileTimeHi = 0U;
  c5_info[15].mFileTimeLo = 0U;
  c5_info[15].mFileTimeHi = 0U;
  c5_info[16].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c5_info[16].name = "eml_scalar_cos";
  c5_info[16].dominantType = "double";
  c5_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c5_info[16].fileTimeLo = 1286851122U;
  c5_info[16].fileTimeHi = 0U;
  c5_info[16].mFileTimeLo = 0U;
  c5_info[16].mFileTimeHi = 0U;
  c5_info[17].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[17].name = "eml_index_class";
  c5_info[17].dominantType = "";
  c5_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[17].fileTimeLo = 1323202978U;
  c5_info[17].fileTimeHi = 0U;
  c5_info[17].mFileTimeLo = 0U;
  c5_info[17].mFileTimeHi = 0U;
  c5_info[18].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[18].name = "eml_scalar_eg";
  c5_info[18].dominantType = "double";
  c5_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[18].fileTimeLo = 1286851196U;
  c5_info[18].fileTimeHi = 0U;
  c5_info[18].mFileTimeLo = 0U;
  c5_info[18].mFileTimeHi = 0U;
  c5_info[19].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[19].name = "eml_xgemm";
  c5_info[19].dominantType = "char";
  c5_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c5_info[19].fileTimeLo = 1299109172U;
  c5_info[19].fileTimeHi = 0U;
  c5_info[19].mFileTimeLo = 0U;
  c5_info[19].mFileTimeHi = 0U;
  c5_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c5_info[20].name = "eml_blas_inline";
  c5_info[20].dominantType = "";
  c5_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c5_info[20].fileTimeLo = 1299109168U;
  c5_info[20].fileTimeHi = 0U;
  c5_info[20].mFileTimeLo = 0U;
  c5_info[20].mFileTimeHi = 0U;
  c5_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c5_info[21].name = "mtimes";
  c5_info[21].dominantType = "double";
  c5_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[21].fileTimeLo = 1289552092U;
  c5_info[21].fileTimeHi = 0U;
  c5_info[21].mFileTimeLo = 0U;
  c5_info[21].mFileTimeHi = 0U;
  c5_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c5_info[22].name = "eml_index_class";
  c5_info[22].dominantType = "";
  c5_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[22].fileTimeLo = 1323202978U;
  c5_info[22].fileTimeHi = 0U;
  c5_info[22].mFileTimeLo = 0U;
  c5_info[22].mFileTimeHi = 0U;
  c5_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c5_info[23].name = "eml_scalar_eg";
  c5_info[23].dominantType = "double";
  c5_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[23].fileTimeLo = 1286851196U;
  c5_info[23].fileTimeHi = 0U;
  c5_info[23].mFileTimeLo = 0U;
  c5_info[23].mFileTimeHi = 0U;
  c5_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c5_info[24].name = "eml_refblas_xgemm";
  c5_info[24].dominantType = "char";
  c5_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c5_info[24].fileTimeLo = 1299109174U;
  c5_info[24].fileTimeHi = 0U;
  c5_info[24].mFileTimeLo = 0U;
  c5_info[24].mFileTimeHi = 0U;
}

static real_T c5_mpower(SFc5_CusakisME4901arcs2InstanceStruct *chartInstance,
  real_T c5_a)
{
  real_T c5_b_a;
  real_T c5_c_a;
  real_T c5_ak;
  real_T c5_d_a;
  real_T c5_e_a;
  real_T c5_b;
  c5_b_a = c5_a;
  c5_c_a = c5_b_a;
  c5_eml_scalar_eg(chartInstance);
  c5_ak = c5_c_a;
  c5_d_a = c5_ak;
  c5_eml_scalar_eg(chartInstance);
  c5_e_a = c5_d_a;
  c5_b = c5_d_a;
  return c5_e_a * c5_b;
}

static void c5_eml_scalar_eg(SFc5_CusakisME4901arcs2InstanceStruct
  *chartInstance)
{
}

static void c5_b_eml_scalar_eg(SFc5_CusakisME4901arcs2InstanceStruct
  *chartInstance)
{
}

static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_CusakisME4901arcs2InstanceStruct *chartInstance;
  chartInstance = (SFc5_CusakisME4901arcs2InstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static int32_T c5_e_emlrt_marshallIn(SFc5_CusakisME4901arcs2InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i87;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i87, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i87;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_CusakisME4901arcs2InstanceStruct *chartInstance;
  chartInstance = (SFc5_CusakisME4901arcs2InstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_f_emlrt_marshallIn(SFc5_CusakisME4901arcs2InstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_CusakisME4901arcs2, const
  char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_CusakisME4901arcs2), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_CusakisME4901arcs2);
  return c5_y;
}

static uint8_T c5_g_emlrt_marshallIn(SFc5_CusakisME4901arcs2InstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info(SFc5_CusakisME4901arcs2InstanceStruct
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

void sf_c5_CusakisME4901arcs2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(428513229U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3067952579U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2174108080U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2769620146U);
}

mxArray *sf_c5_CusakisME4901arcs2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("nkkqiyFtWsjvKdtuf4tTbH");
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

mxArray *sf_c5_CusakisME4901arcs2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c5_CusakisME4901arcs2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"H\",},{M[8],M[0],T\"is_active_c5_CusakisME4901arcs2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_CusakisME4901arcs2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_CusakisME4901arcs2InstanceStruct *chartInstance;
    chartInstance = (SFc5_CusakisME4901arcs2InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CusakisME4901arcs2MachineNumber_,
           5,
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
          init_script_number_translation(_CusakisME4901arcs2MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_CusakisME4901arcs2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _CusakisME4901arcs2MachineNumber_,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,899);
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
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)c5_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)c5_b_sf_marshallIn);

        {
          real_T (*c5_H)[9];
          real_T (*c5_qqd)[9];
          c5_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          c5_H = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c5_H);
          _SFD_SET_DATA_VALUE_PTR(1U, *c5_qqd);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c5_l);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c5_m);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _CusakisME4901arcs2MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "wX6Dn2J8NGA9u2Nkja8aMG";
}

static void sf_opaque_initialize_c5_CusakisME4901arcs2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_CusakisME4901arcs2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_CusakisME4901arcs2((SFc5_CusakisME4901arcs2InstanceStruct*)
    chartInstanceVar);
  initialize_c5_CusakisME4901arcs2((SFc5_CusakisME4901arcs2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_CusakisME4901arcs2(void *chartInstanceVar)
{
  enable_c5_CusakisME4901arcs2((SFc5_CusakisME4901arcs2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c5_CusakisME4901arcs2(void *chartInstanceVar)
{
  disable_c5_CusakisME4901arcs2((SFc5_CusakisME4901arcs2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c5_CusakisME4901arcs2(void *chartInstanceVar)
{
  sf_c5_CusakisME4901arcs2((SFc5_CusakisME4901arcs2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_CusakisME4901arcs2(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_CusakisME4901arcs2
    ((SFc5_CusakisME4901arcs2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_CusakisME4901arcs2();/* state var info */
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

extern void sf_internal_set_sim_state_c5_CusakisME4901arcs2(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_CusakisME4901arcs2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_CusakisME4901arcs2((SFc5_CusakisME4901arcs2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_CusakisME4901arcs2(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_CusakisME4901arcs2(S);
}

static void sf_opaque_set_sim_state_c5_CusakisME4901arcs2(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c5_CusakisME4901arcs2(S, st);
}

static void sf_opaque_terminate_c5_CusakisME4901arcs2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_CusakisME4901arcs2InstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CusakisME4901arcs2_optimization_info();
    }

    finalize_c5_CusakisME4901arcs2((SFc5_CusakisME4901arcs2InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_CusakisME4901arcs2((SFc5_CusakisME4901arcs2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_CusakisME4901arcs2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_CusakisME4901arcs2
      ((SFc5_CusakisME4901arcs2InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_CusakisME4901arcs2(SimStruct *S)
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
    mxArray *infoStruct = load_CusakisME4901arcs2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,5,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,5);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1190487002U));
  ssSetChecksum1(S,(1242930075U));
  ssSetChecksum2(S,(3020138111U));
  ssSetChecksum3(S,(89102967U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_CusakisME4901arcs2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_CusakisME4901arcs2(SimStruct *S)
{
  SFc5_CusakisME4901arcs2InstanceStruct *chartInstance;
  chartInstance = (SFc5_CusakisME4901arcs2InstanceStruct *)utMalloc(sizeof
    (SFc5_CusakisME4901arcs2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_CusakisME4901arcs2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_CusakisME4901arcs2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_CusakisME4901arcs2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_CusakisME4901arcs2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_CusakisME4901arcs2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c5_CusakisME4901arcs2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_CusakisME4901arcs2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_CusakisME4901arcs2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_CusakisME4901arcs2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_CusakisME4901arcs2;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_CusakisME4901arcs2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_CusakisME4901arcs2;
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

void c5_CusakisME4901arcs2_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_CusakisME4901arcs2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_CusakisME4901arcs2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_CusakisME4901arcs2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_CusakisME4901arcs2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
