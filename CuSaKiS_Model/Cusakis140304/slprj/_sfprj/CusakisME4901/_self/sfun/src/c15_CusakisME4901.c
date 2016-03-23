/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CusakisME4901_sfun.h"
#include "c15_CusakisME4901.h"
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
static const char * c15_debug_family_names[32] = { "xb", "yb", "thetab",
  "thetabb", "M", "r0", "V", "pl1", "pl2", "pl3", "plr", "p1", "p2", "p3", "r1",
  "r2", "r3", "rg", "roc", "pr", "nargin", "nargout", "qqd", "SC", "dSC", "lb",
  "l", "mb", "m", "state_3link", "EE", "Rcm" };

/* Function Declarations */
static void initialize_c15_CusakisME4901(SFc15_CusakisME4901InstanceStruct
  *chartInstance);
static void initialize_params_c15_CusakisME4901
  (SFc15_CusakisME4901InstanceStruct *chartInstance);
static void enable_c15_CusakisME4901(SFc15_CusakisME4901InstanceStruct
  *chartInstance);
static void disable_c15_CusakisME4901(SFc15_CusakisME4901InstanceStruct
  *chartInstance);
static void c15_update_debugger_state_c15_CusakisME4901
  (SFc15_CusakisME4901InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c15_CusakisME4901
  (SFc15_CusakisME4901InstanceStruct *chartInstance);
static void set_sim_state_c15_CusakisME4901(SFc15_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c15_st);
static void finalize_c15_CusakisME4901(SFc15_CusakisME4901InstanceStruct
  *chartInstance);
static void sf_c15_CusakisME4901(SFc15_CusakisME4901InstanceStruct
  *chartInstance);
static void c15_chartstep_c15_CusakisME4901(SFc15_CusakisME4901InstanceStruct
  *chartInstance);
static void initSimStructsc15_CusakisME4901(SFc15_CusakisME4901InstanceStruct
  *chartInstance);
static void registerMessagesc15_CusakisME4901(SFc15_CusakisME4901InstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber);
static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_emlrt_marshallIn(SFc15_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c15_Rcm, const char_T *c15_identifier, real_T
  c15_y[3]);
static void c15_b_emlrt_marshallIn(SFc15_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[3]);
static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_c_emlrt_marshallIn(SFc15_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c15_EE, const char_T *c15_identifier, real_T
  c15_y[6]);
static void c15_d_emlrt_marshallIn(SFc15_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[6]);
static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static real_T c15_e_emlrt_marshallIn(SFc15_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_d_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static const mxArray *c15_e_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_f_emlrt_marshallIn(SFc15_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[12]);
static void c15_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_f_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static int32_T c15_g_emlrt_marshallIn(SFc15_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static uint8_T c15_h_emlrt_marshallIn(SFc15_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c15_b_is_active_c15_CusakisME4901, const char_T
  *c15_identifier);
static uint8_T c15_i_emlrt_marshallIn(SFc15_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void init_dsm_address_info(SFc15_CusakisME4901InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c15_CusakisME4901(SFc15_CusakisME4901InstanceStruct
  *chartInstance)
{
  chartInstance->c15_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c15_is_active_c15_CusakisME4901 = 0U;
}

static void initialize_params_c15_CusakisME4901
  (SFc15_CusakisME4901InstanceStruct *chartInstance)
{
  real_T c15_d0;
  real_T c15_d1;
  real_T c15_d2;
  real_T c15_d3;
  sf_set_error_prefix_string(
    "Error evaluating data 'lb' in the parent workspace.\n");
  sf_mex_import_named("lb", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c15_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c15_lb = c15_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'l' in the parent workspace.\n");
  sf_mex_import_named("l", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c15_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c15_l = c15_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'mb' in the parent workspace.\n");
  sf_mex_import_named("mb", sf_mex_get_sfun_param(chartInstance->S, 3, 0),
                      &c15_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c15_mb = c15_d2;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'm' in the parent workspace.\n");
  sf_mex_import_named("m", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      &c15_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c15_m = c15_d3;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c15_CusakisME4901(SFc15_CusakisME4901InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c15_CusakisME4901(SFc15_CusakisME4901InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c15_update_debugger_state_c15_CusakisME4901
  (SFc15_CusakisME4901InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c15_CusakisME4901
  (SFc15_CusakisME4901InstanceStruct *chartInstance)
{
  const mxArray *c15_st;
  const mxArray *c15_y = NULL;
  int32_T c15_i0;
  real_T c15_u[6];
  const mxArray *c15_b_y = NULL;
  int32_T c15_i1;
  real_T c15_b_u[3];
  const mxArray *c15_c_y = NULL;
  int32_T c15_i2;
  real_T c15_c_u[6];
  const mxArray *c15_d_y = NULL;
  uint8_T c15_hoistedGlobal;
  uint8_T c15_d_u;
  const mxArray *c15_e_y = NULL;
  real_T (*c15_state_3link)[6];
  real_T (*c15_Rcm)[3];
  real_T (*c15_EE)[6];
  c15_Rcm = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c15_EE = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c15_state_3link = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c15_st = NULL;
  c15_st = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_createcellarray(4), FALSE);
  for (c15_i0 = 0; c15_i0 < 6; c15_i0++) {
    c15_u[c15_i0] = (*c15_EE)[c15_i0];
  }

  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_setcell(c15_y, 0, c15_b_y);
  for (c15_i1 = 0; c15_i1 < 3; c15_i1++) {
    c15_b_u[c15_i1] = (*c15_Rcm)[c15_i1];
  }

  c15_c_y = NULL;
  sf_mex_assign(&c15_c_y, sf_mex_create("y", c15_b_u, 0, 0U, 1U, 0U, 1, 3),
                FALSE);
  sf_mex_setcell(c15_y, 1, c15_c_y);
  for (c15_i2 = 0; c15_i2 < 6; c15_i2++) {
    c15_c_u[c15_i2] = (*c15_state_3link)[c15_i2];
  }

  c15_d_y = NULL;
  sf_mex_assign(&c15_d_y, sf_mex_create("y", c15_c_u, 0, 0U, 1U, 0U, 1, 6),
                FALSE);
  sf_mex_setcell(c15_y, 2, c15_d_y);
  c15_hoistedGlobal = chartInstance->c15_is_active_c15_CusakisME4901;
  c15_d_u = c15_hoistedGlobal;
  c15_e_y = NULL;
  sf_mex_assign(&c15_e_y, sf_mex_create("y", &c15_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c15_y, 3, c15_e_y);
  sf_mex_assign(&c15_st, c15_y, FALSE);
  return c15_st;
}

static void set_sim_state_c15_CusakisME4901(SFc15_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c15_st)
{
  const mxArray *c15_u;
  real_T c15_dv0[6];
  int32_T c15_i3;
  real_T c15_dv1[3];
  int32_T c15_i4;
  real_T c15_dv2[6];
  int32_T c15_i5;
  real_T (*c15_EE)[6];
  real_T (*c15_Rcm)[3];
  real_T (*c15_state_3link)[6];
  c15_Rcm = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c15_EE = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c15_state_3link = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c15_doneDoubleBufferReInit = TRUE;
  c15_u = sf_mex_dup(c15_st);
  c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 0)),
    "EE", c15_dv0);
  for (c15_i3 = 0; c15_i3 < 6; c15_i3++) {
    (*c15_EE)[c15_i3] = c15_dv0[c15_i3];
  }

  c15_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 1)),
                       "Rcm", c15_dv1);
  for (c15_i4 = 0; c15_i4 < 3; c15_i4++) {
    (*c15_Rcm)[c15_i4] = c15_dv1[c15_i4];
  }

  c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 2)),
    "state_3link", c15_dv2);
  for (c15_i5 = 0; c15_i5 < 6; c15_i5++) {
    (*c15_state_3link)[c15_i5] = c15_dv2[c15_i5];
  }

  chartInstance->c15_is_active_c15_CusakisME4901 = c15_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 3)),
     "is_active_c15_CusakisME4901");
  sf_mex_destroy(&c15_u);
  c15_update_debugger_state_c15_CusakisME4901(chartInstance);
  sf_mex_destroy(&c15_st);
}

static void finalize_c15_CusakisME4901(SFc15_CusakisME4901InstanceStruct
  *chartInstance)
{
}

static void sf_c15_CusakisME4901(SFc15_CusakisME4901InstanceStruct
  *chartInstance)
{
  int32_T c15_i6;
  int32_T c15_i7;
  int32_T c15_i8;
  int32_T c15_i9;
  int32_T c15_i10;
  int32_T c15_i11;
  real_T (*c15_Rcm)[3];
  real_T (*c15_EE)[6];
  real_T (*c15_state_3link)[6];
  real_T (*c15_dSC)[6];
  real_T (*c15_SC)[6];
  real_T (*c15_qqd)[9];
  c15_Rcm = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c15_EE = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c15_state_3link = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c15_dSC = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
  c15_SC = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
  c15_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 14U, chartInstance->c15_sfEvent);
  for (c15_i6 = 0; c15_i6 < 9; c15_i6++) {
    _SFD_DATA_RANGE_CHECK((*c15_qqd)[c15_i6], 0U);
  }

  for (c15_i7 = 0; c15_i7 < 6; c15_i7++) {
    _SFD_DATA_RANGE_CHECK((*c15_SC)[c15_i7], 1U);
  }

  for (c15_i8 = 0; c15_i8 < 6; c15_i8++) {
    _SFD_DATA_RANGE_CHECK((*c15_dSC)[c15_i8], 2U);
  }

  for (c15_i9 = 0; c15_i9 < 6; c15_i9++) {
    _SFD_DATA_RANGE_CHECK((*c15_state_3link)[c15_i9], 3U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c15_lb, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c15_l, 5U);
  for (c15_i10 = 0; c15_i10 < 6; c15_i10++) {
    _SFD_DATA_RANGE_CHECK((*c15_EE)[c15_i10], 6U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c15_mb, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c15_m, 8U);
  for (c15_i11 = 0; c15_i11 < 3; c15_i11++) {
    _SFD_DATA_RANGE_CHECK((*c15_Rcm)[c15_i11], 9U);
  }

  chartInstance->c15_sfEvent = CALL_EVENT;
  c15_chartstep_c15_CusakisME4901(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CusakisME4901MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c15_chartstep_c15_CusakisME4901(SFc15_CusakisME4901InstanceStruct
  *chartInstance)
{
  real_T c15_hoistedGlobal;
  real_T c15_b_hoistedGlobal;
  real_T c15_c_hoistedGlobal;
  real_T c15_d_hoistedGlobal;
  int32_T c15_i12;
  real_T c15_qqd[9];
  int32_T c15_i13;
  real_T c15_SC[6];
  int32_T c15_i14;
  real_T c15_dSC[6];
  real_T c15_b_lb;
  real_T c15_b_l;
  real_T c15_b_mb;
  real_T c15_b_m;
  uint32_T c15_debug_family_var_map[32];
  real_T c15_xb;
  real_T c15_yb;
  real_T c15_thetab;
  real_T c15_thetabb;
  real_T c15_M;
  real_T c15_r0[3];
  real_T c15_V[12];
  real_T c15_pl1[3];
  real_T c15_pl2[3];
  real_T c15_pl3[3];
  real_T c15_plr[3];
  real_T c15_p1[3];
  real_T c15_p2[3];
  real_T c15_p3[3];
  real_T c15_r1[3];
  real_T c15_r2[3];
  real_T c15_r3[3];
  real_T c15_rg[3];
  real_T c15_roc[3];
  real_T c15_pr[3];
  real_T c15_nargin = 7.0;
  real_T c15_nargout = 3.0;
  real_T c15_state_3link[6];
  real_T c15_EE[6];
  real_T c15_Rcm[3];
  int32_T c15_i15;
  real_T c15_x;
  real_T c15_b_x;
  real_T c15_a;
  real_T c15_b;
  real_T c15_y;
  real_T c15_c_x;
  real_T c15_d_x;
  real_T c15_b_a;
  real_T c15_b_b;
  real_T c15_b_y;
  real_T c15_e_x;
  real_T c15_f_x;
  real_T c15_c_a;
  real_T c15_c_b;
  real_T c15_c_y;
  real_T c15_A;
  real_T c15_g_x;
  real_T c15_h_x;
  real_T c15_d_y;
  real_T c15_i_x;
  real_T c15_j_x;
  real_T c15_d_a;
  real_T c15_d_b;
  real_T c15_e_y;
  real_T c15_k_x;
  real_T c15_l_x;
  real_T c15_e_a;
  real_T c15_e_b;
  real_T c15_f_y;
  real_T c15_m_x;
  real_T c15_n_x;
  real_T c15_f_a;
  real_T c15_f_b;
  real_T c15_g_y;
  real_T c15_o_x;
  real_T c15_p_x;
  real_T c15_g_a;
  real_T c15_g_b;
  real_T c15_h_y;
  real_T c15_b_A;
  real_T c15_q_x;
  real_T c15_r_x;
  real_T c15_i_y;
  real_T c15_s_x;
  real_T c15_t_x;
  real_T c15_h_a;
  real_T c15_h_b;
  real_T c15_j_y;
  real_T c15_i_a;
  real_T c15_i_b;
  real_T c15_k_y;
  real_T c15_u_x;
  real_T c15_v_x;
  real_T c15_j_a;
  real_T c15_j_b;
  real_T c15_l_y;
  real_T c15_k_a;
  real_T c15_k_b;
  real_T c15_m_y;
  real_T c15_w_x;
  real_T c15_x_x;
  real_T c15_l_a;
  real_T c15_l_b;
  real_T c15_n_y;
  real_T c15_m_a;
  real_T c15_m_b;
  real_T c15_o_y;
  real_T c15_y_x;
  real_T c15_ab_x;
  real_T c15_n_a;
  real_T c15_n_b;
  real_T c15_p_y;
  real_T c15_c_A;
  real_T c15_bb_x;
  real_T c15_cb_x;
  real_T c15_q_y;
  real_T c15_o_a;
  real_T c15_o_b;
  real_T c15_r_y;
  real_T c15_db_x;
  real_T c15_eb_x;
  real_T c15_p_a;
  real_T c15_p_b;
  real_T c15_s_y;
  real_T c15_q_a;
  real_T c15_q_b;
  real_T c15_t_y;
  real_T c15_fb_x;
  real_T c15_gb_x;
  real_T c15_r_a;
  real_T c15_r_b;
  real_T c15_u_y;
  real_T c15_s_a;
  real_T c15_s_b;
  real_T c15_v_y;
  real_T c15_hb_x;
  real_T c15_ib_x;
  real_T c15_t_a;
  real_T c15_t_b;
  real_T c15_w_y;
  real_T c15_u_a;
  real_T c15_u_b;
  real_T c15_x_y;
  real_T c15_jb_x;
  real_T c15_kb_x;
  real_T c15_v_a;
  real_T c15_v_b;
  real_T c15_y_y;
  real_T c15_d_A;
  real_T c15_lb_x;
  real_T c15_mb_x;
  real_T c15_ab_y;
  real_T c15_w_a;
  real_T c15_w_b;
  real_T c15_bb_y;
  real_T c15_nb_x;
  real_T c15_ob_x;
  real_T c15_x_a;
  real_T c15_x_b;
  real_T c15_cb_y;
  int32_T c15_i16;
  real_T c15_pb_x;
  real_T c15_qb_x;
  real_T c15_y_a;
  real_T c15_y_b;
  real_T c15_db_y;
  real_T c15_rb_x;
  real_T c15_sb_x;
  real_T c15_ab_a;
  real_T c15_ab_b;
  real_T c15_eb_y;
  real_T c15_tb_x;
  real_T c15_ub_x;
  real_T c15_bb_a;
  real_T c15_bb_b;
  real_T c15_fb_y;
  real_T c15_vb_x;
  real_T c15_wb_x;
  real_T c15_cb_a;
  real_T c15_cb_b;
  real_T c15_gb_y;
  real_T c15_xb_x;
  real_T c15_yb_x;
  real_T c15_db_a;
  real_T c15_db_b;
  real_T c15_hb_y;
  real_T c15_ac_x;
  real_T c15_bc_x;
  real_T c15_eb_a;
  real_T c15_eb_b;
  real_T c15_ib_y;
  real_T c15_cc_x;
  real_T c15_dc_x;
  real_T c15_fb_a;
  real_T c15_fb_b;
  real_T c15_jb_y;
  real_T c15_ec_x;
  real_T c15_fc_x;
  real_T c15_gb_a;
  real_T c15_gb_b;
  real_T c15_kb_y;
  real_T c15_hb_a;
  real_T c15_hb_b;
  real_T c15_lb_y;
  real_T c15_gc_x;
  real_T c15_hc_x;
  real_T c15_ib_a;
  real_T c15_ib_b;
  real_T c15_mb_y;
  real_T c15_jb_a;
  real_T c15_jb_b;
  real_T c15_nb_y;
  real_T c15_ic_x;
  real_T c15_jc_x;
  real_T c15_kb_a;
  real_T c15_kb_b;
  real_T c15_ob_y;
  real_T c15_lb_a;
  real_T c15_lb_b;
  real_T c15_pb_y;
  real_T c15_kc_x;
  real_T c15_lc_x;
  real_T c15_mb_a;
  real_T c15_mb_b;
  real_T c15_qb_y;
  real_T c15_nb_a;
  real_T c15_nb_b;
  real_T c15_rb_y;
  real_T c15_mc_x;
  real_T c15_nc_x;
  real_T c15_ob_a;
  real_T c15_ob_b;
  real_T c15_sb_y;
  real_T c15_pb_a;
  real_T c15_pb_b;
  real_T c15_tb_y;
  real_T c15_oc_x;
  real_T c15_pc_x;
  real_T c15_qb_a;
  real_T c15_qb_b;
  real_T c15_ub_y;
  real_T c15_rb_a;
  real_T c15_rb_b;
  real_T c15_vb_y;
  real_T c15_qc_x;
  real_T c15_rc_x;
  real_T c15_sb_a;
  real_T c15_sb_b;
  real_T c15_wb_y;
  real_T c15_tb_a;
  real_T c15_tb_b;
  real_T c15_xb_y;
  real_T c15_sc_x;
  real_T c15_tc_x;
  real_T c15_ub_a;
  real_T c15_ub_b;
  real_T c15_yb_y;
  real_T c15_vb_a;
  real_T c15_vb_b;
  real_T c15_ac_y;
  real_T c15_uc_x;
  real_T c15_vc_x;
  real_T c15_wb_a;
  real_T c15_wb_b;
  real_T c15_bc_y;
  real_T c15_xb_a;
  real_T c15_cc_y;
  real_T c15_wc_x;
  real_T c15_xc_x;
  real_T c15_yb_a;
  real_T c15_xb_b;
  real_T c15_dc_y;
  real_T c15_yc_x;
  real_T c15_ad_x;
  real_T c15_ac_a;
  real_T c15_yb_b;
  real_T c15_ec_y;
  real_T c15_bd_x;
  real_T c15_cd_x;
  real_T c15_bc_a;
  real_T c15_ac_b;
  real_T c15_fc_y;
  real_T c15_dd_x;
  real_T c15_ed_x;
  real_T c15_cc_a;
  real_T c15_bc_b;
  real_T c15_gc_y;
  real_T c15_fd_x;
  real_T c15_gd_x;
  real_T c15_dc_a;
  real_T c15_cc_b;
  real_T c15_hc_y;
  real_T c15_hd_x;
  real_T c15_id_x;
  real_T c15_ec_a;
  real_T c15_dc_b;
  real_T c15_ic_y;
  real_T c15_jd_x;
  real_T c15_kd_x;
  real_T c15_fc_a;
  real_T c15_ec_b;
  real_T c15_jc_y;
  real_T c15_ld_x;
  real_T c15_md_x;
  real_T c15_gc_a;
  real_T c15_fc_b;
  real_T c15_kc_y;
  int32_T c15_i17;
  int32_T c15_i18;
  int32_T c15_i19;
  real_T c15_e_A;
  real_T c15_nd_x;
  real_T c15_od_x;
  real_T c15_lc_y;
  real_T c15_pd_x;
  real_T c15_qd_x;
  real_T c15_hc_a;
  real_T c15_gc_b;
  real_T c15_mc_y;
  real_T c15_f_A;
  real_T c15_rd_x;
  real_T c15_sd_x;
  real_T c15_nc_y;
  real_T c15_td_x;
  real_T c15_ud_x;
  real_T c15_ic_a;
  real_T c15_hc_b;
  real_T c15_oc_y;
  real_T c15_pc_y[3];
  int32_T c15_i20;
  real_T c15_g_A;
  real_T c15_vd_x;
  real_T c15_wd_x;
  real_T c15_qc_y;
  real_T c15_xd_x;
  real_T c15_yd_x;
  real_T c15_jc_a;
  real_T c15_ic_b;
  real_T c15_rc_y;
  real_T c15_h_A;
  real_T c15_ae_x;
  real_T c15_be_x;
  real_T c15_sc_y;
  real_T c15_ce_x;
  real_T c15_de_x;
  real_T c15_kc_a;
  real_T c15_jc_b;
  real_T c15_tc_y;
  real_T c15_uc_y[3];
  int32_T c15_i21;
  real_T c15_i_A;
  real_T c15_ee_x;
  real_T c15_fe_x;
  real_T c15_vc_y;
  real_T c15_ge_x;
  real_T c15_he_x;
  real_T c15_lc_a;
  real_T c15_kc_b;
  real_T c15_wc_y;
  real_T c15_j_A;
  real_T c15_ie_x;
  real_T c15_je_x;
  real_T c15_xc_y;
  real_T c15_ke_x;
  real_T c15_le_x;
  real_T c15_mc_a;
  real_T c15_lc_b;
  real_T c15_yc_y;
  real_T c15_ad_y[3];
  int32_T c15_i22;
  real_T c15_k_A;
  real_T c15_B;
  real_T c15_me_x;
  real_T c15_bd_y;
  real_T c15_ne_x;
  real_T c15_cd_y;
  real_T c15_dd_y;
  real_T c15_nc_a;
  int32_T c15_i23;
  real_T c15_mc_b[3];
  int32_T c15_i24;
  real_T c15_l_A;
  real_T c15_b_B;
  real_T c15_oe_x;
  real_T c15_ed_y;
  real_T c15_pe_x;
  real_T c15_fd_y;
  real_T c15_gd_y;
  real_T c15_oc_a;
  int32_T c15_i25;
  real_T c15_nc_b[3];
  int32_T c15_i26;
  int32_T c15_i27;
  int32_T c15_i28;
  int32_T c15_i29;
  int32_T c15_i30;
  int32_T c15_i31;
  int32_T c15_i32;
  int32_T c15_i33;
  real_T (*c15_b_state_3link)[6];
  real_T (*c15_b_EE)[6];
  real_T (*c15_b_Rcm)[3];
  real_T (*c15_b_dSC)[6];
  real_T (*c15_b_SC)[6];
  real_T (*c15_b_qqd)[9];
  c15_b_Rcm = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c15_b_EE = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
  c15_b_state_3link = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c15_b_dSC = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
  c15_b_SC = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
  c15_b_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 14U, chartInstance->c15_sfEvent);
  c15_hoistedGlobal = chartInstance->c15_lb;
  c15_b_hoistedGlobal = chartInstance->c15_l;
  c15_c_hoistedGlobal = chartInstance->c15_mb;
  c15_d_hoistedGlobal = chartInstance->c15_m;
  for (c15_i12 = 0; c15_i12 < 9; c15_i12++) {
    c15_qqd[c15_i12] = (*c15_b_qqd)[c15_i12];
  }

  for (c15_i13 = 0; c15_i13 < 6; c15_i13++) {
    c15_SC[c15_i13] = (*c15_b_SC)[c15_i13];
  }

  for (c15_i14 = 0; c15_i14 < 6; c15_i14++) {
    c15_dSC[c15_i14] = (*c15_b_dSC)[c15_i14];
  }

  c15_b_lb = c15_hoistedGlobal;
  c15_b_l = c15_b_hoistedGlobal;
  c15_b_mb = c15_c_hoistedGlobal;
  c15_b_m = c15_d_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 32U, 32U, c15_debug_family_names,
    c15_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_xb, 0U, c15_c_sf_marshallOut,
    c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_yb, 1U, c15_c_sf_marshallOut,
    c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_thetab, 2U, c15_c_sf_marshallOut,
    c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_thetabb, 3U, c15_c_sf_marshallOut,
    c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_M, 4U, c15_c_sf_marshallOut,
    c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_r0, 5U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_V, 6U, c15_e_sf_marshallOut,
    c15_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_pl1, 7U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_pl2, 8U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_pl3, 9U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_plr, 10U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_p1, 11U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_p2, 12U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_p3, 13U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_r1, 14U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_r2, 15U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_r3, 16U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_rg, 17U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_roc, 18U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_pr, 19U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargin, 20U, c15_c_sf_marshallOut,
    c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargout, 21U, c15_c_sf_marshallOut,
    c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c15_qqd, 22U, c15_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c15_SC, 23U, c15_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c15_dSC, 24U, c15_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_lb, 25U, c15_c_sf_marshallOut,
    c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_l, 26U, c15_c_sf_marshallOut,
    c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_mb, 27U, c15_c_sf_marshallOut,
    c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_m, 28U, c15_c_sf_marshallOut,
    c15_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_state_3link, 29U,
    c15_b_sf_marshallOut, c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_EE, 30U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_Rcm, 31U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 6);
  c15_xb = c15_SC[0];
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 7);
  c15_yb = c15_SC[1];
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 8);
  c15_thetab = c15_SC[5];
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 9);
  c15_thetabb = c15_dSC[5];
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 13);
  for (c15_i15 = 0; c15_i15 < 6; c15_i15++) {
    c15_state_3link[c15_i15] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 15);
  c15_x = c15_thetab;
  c15_b_x = c15_x;
  c15_b_x = muDoubleScalarCos(c15_b_x);
  c15_a = c15_b_lb;
  c15_b = c15_b_x;
  c15_y = c15_a * c15_b;
  c15_c_x = c15_qqd[6] + c15_thetab;
  c15_d_x = c15_c_x;
  c15_d_x = muDoubleScalarCos(c15_d_x);
  c15_b_a = c15_b_l;
  c15_b_b = c15_d_x;
  c15_b_y = c15_b_a * c15_b_b;
  c15_e_x = (c15_qqd[7] + c15_qqd[6]) + c15_thetab;
  c15_f_x = c15_e_x;
  c15_f_x = muDoubleScalarCos(c15_f_x);
  c15_c_a = c15_b_l;
  c15_c_b = c15_f_x;
  c15_c_y = c15_c_a * c15_c_b;
  c15_A = c15_b_l;
  c15_g_x = c15_A;
  c15_h_x = c15_g_x;
  c15_d_y = c15_h_x / 2.0;
  c15_i_x = ((c15_qqd[8] + c15_qqd[7]) + c15_qqd[6]) + c15_thetab;
  c15_j_x = c15_i_x;
  c15_j_x = muDoubleScalarCos(c15_j_x);
  c15_d_a = c15_d_y;
  c15_d_b = c15_j_x;
  c15_e_y = c15_d_a * c15_d_b;
  c15_state_3link[0] = (((c15_xb + c15_y) + c15_b_y) + c15_c_y) + c15_e_y;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 16);
  c15_k_x = c15_thetab;
  c15_l_x = c15_k_x;
  c15_l_x = muDoubleScalarSin(c15_l_x);
  c15_e_a = c15_b_lb;
  c15_e_b = c15_l_x;
  c15_f_y = c15_e_a * c15_e_b;
  c15_m_x = c15_qqd[6] + c15_thetab;
  c15_n_x = c15_m_x;
  c15_n_x = muDoubleScalarSin(c15_n_x);
  c15_f_a = c15_b_l;
  c15_f_b = c15_n_x;
  c15_g_y = c15_f_a * c15_f_b;
  c15_o_x = (c15_qqd[7] + c15_qqd[6]) + c15_thetab;
  c15_p_x = c15_o_x;
  c15_p_x = muDoubleScalarSin(c15_p_x);
  c15_g_a = c15_b_l;
  c15_g_b = c15_p_x;
  c15_h_y = c15_g_a * c15_g_b;
  c15_b_A = c15_b_l;
  c15_q_x = c15_b_A;
  c15_r_x = c15_q_x;
  c15_i_y = c15_r_x / 2.0;
  c15_s_x = ((c15_qqd[8] + c15_qqd[7]) + c15_qqd[6]) + c15_thetab;
  c15_t_x = c15_s_x;
  c15_t_x = muDoubleScalarSin(c15_t_x);
  c15_h_a = c15_i_y;
  c15_h_b = c15_t_x;
  c15_j_y = c15_h_a * c15_h_b;
  c15_state_3link[1] = (((c15_yb + c15_f_y) + c15_g_y) + c15_h_y) + c15_j_y;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 17);
  c15_state_3link[2] = ((c15_qqd[8] + c15_qqd[7]) + c15_qqd[6]) + c15_thetab;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 18);
  c15_i_a = -c15_b_lb;
  c15_i_b = c15_thetabb;
  c15_k_y = c15_i_a * c15_i_b;
  c15_u_x = c15_thetab;
  c15_v_x = c15_u_x;
  c15_v_x = muDoubleScalarSin(c15_v_x);
  c15_j_a = c15_k_y;
  c15_j_b = c15_v_x;
  c15_l_y = c15_j_a * c15_j_b;
  c15_k_a = c15_b_l;
  c15_k_b = c15_qqd[3] + c15_thetabb;
  c15_m_y = c15_k_a * c15_k_b;
  c15_w_x = c15_qqd[6] + c15_thetab;
  c15_x_x = c15_w_x;
  c15_x_x = muDoubleScalarSin(c15_x_x);
  c15_l_a = c15_m_y;
  c15_l_b = c15_x_x;
  c15_n_y = c15_l_a * c15_l_b;
  c15_m_a = c15_b_l;
  c15_m_b = (c15_qqd[3] + c15_qqd[4]) + c15_thetabb;
  c15_o_y = c15_m_a * c15_m_b;
  c15_y_x = (c15_qqd[7] + c15_qqd[6]) + c15_thetab;
  c15_ab_x = c15_y_x;
  c15_ab_x = muDoubleScalarSin(c15_ab_x);
  c15_n_a = c15_o_y;
  c15_n_b = c15_ab_x;
  c15_p_y = c15_n_a * c15_n_b;
  c15_c_A = c15_b_l;
  c15_bb_x = c15_c_A;
  c15_cb_x = c15_bb_x;
  c15_q_y = c15_cb_x / 2.0;
  c15_o_a = c15_q_y;
  c15_o_b = ((c15_qqd[3] + c15_qqd[4]) + c15_qqd[5]) + c15_thetabb;
  c15_r_y = c15_o_a * c15_o_b;
  c15_db_x = ((c15_qqd[8] + c15_qqd[7]) + c15_qqd[6]) + c15_thetab;
  c15_eb_x = c15_db_x;
  c15_eb_x = muDoubleScalarSin(c15_eb_x);
  c15_p_a = c15_r_y;
  c15_p_b = c15_eb_x;
  c15_s_y = c15_p_a * c15_p_b;
  c15_state_3link[3] = ((c15_l_y - c15_n_y) - c15_p_y) - c15_s_y;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 19);
  c15_q_a = c15_b_lb;
  c15_q_b = c15_thetabb;
  c15_t_y = c15_q_a * c15_q_b;
  c15_fb_x = c15_thetab;
  c15_gb_x = c15_fb_x;
  c15_gb_x = muDoubleScalarCos(c15_gb_x);
  c15_r_a = c15_t_y;
  c15_r_b = c15_gb_x;
  c15_u_y = c15_r_a * c15_r_b;
  c15_s_a = c15_b_l;
  c15_s_b = c15_qqd[3] + c15_thetabb;
  c15_v_y = c15_s_a * c15_s_b;
  c15_hb_x = c15_qqd[6] + c15_thetab;
  c15_ib_x = c15_hb_x;
  c15_ib_x = muDoubleScalarCos(c15_ib_x);
  c15_t_a = c15_v_y;
  c15_t_b = c15_ib_x;
  c15_w_y = c15_t_a * c15_t_b;
  c15_u_a = c15_b_l;
  c15_u_b = (c15_qqd[3] + c15_qqd[4]) + c15_thetabb;
  c15_x_y = c15_u_a * c15_u_b;
  c15_jb_x = (c15_qqd[7] + c15_qqd[6]) + c15_thetab;
  c15_kb_x = c15_jb_x;
  c15_kb_x = muDoubleScalarCos(c15_kb_x);
  c15_v_a = c15_x_y;
  c15_v_b = c15_kb_x;
  c15_y_y = c15_v_a * c15_v_b;
  c15_d_A = c15_b_l;
  c15_lb_x = c15_d_A;
  c15_mb_x = c15_lb_x;
  c15_ab_y = c15_mb_x / 2.0;
  c15_w_a = c15_ab_y;
  c15_w_b = ((c15_qqd[3] + c15_qqd[4]) + c15_qqd[5]) + c15_thetabb;
  c15_bb_y = c15_w_a * c15_w_b;
  c15_nb_x = ((c15_qqd[8] + c15_qqd[7]) + c15_qqd[6]) + c15_thetab;
  c15_ob_x = c15_nb_x;
  c15_ob_x = muDoubleScalarCos(c15_ob_x);
  c15_x_a = c15_bb_y;
  c15_x_b = c15_ob_x;
  c15_cb_y = c15_x_a * c15_x_b;
  c15_state_3link[4] = ((c15_u_y + c15_w_y) + c15_y_y) + c15_cb_y;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 20);
  c15_state_3link[5] = ((c15_qqd[3] + c15_qqd[4]) + c15_qqd[5]) + c15_thetabb;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 23);
  for (c15_i16 = 0; c15_i16 < 6; c15_i16++) {
    c15_EE[c15_i16] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 25);
  c15_pb_x = c15_thetab;
  c15_qb_x = c15_pb_x;
  c15_qb_x = muDoubleScalarCos(c15_qb_x);
  c15_y_a = c15_b_lb;
  c15_y_b = c15_qb_x;
  c15_db_y = c15_y_a * c15_y_b;
  c15_rb_x = c15_qqd[6] + c15_thetab;
  c15_sb_x = c15_rb_x;
  c15_sb_x = muDoubleScalarCos(c15_sb_x);
  c15_ab_a = c15_b_l;
  c15_ab_b = c15_sb_x;
  c15_eb_y = c15_ab_a * c15_ab_b;
  c15_tb_x = (c15_qqd[7] + c15_qqd[6]) + c15_thetab;
  c15_ub_x = c15_tb_x;
  c15_ub_x = muDoubleScalarCos(c15_ub_x);
  c15_bb_a = c15_b_l;
  c15_bb_b = c15_ub_x;
  c15_fb_y = c15_bb_a * c15_bb_b;
  c15_vb_x = ((c15_qqd[8] + c15_qqd[7]) + c15_qqd[6]) + c15_thetab;
  c15_wb_x = c15_vb_x;
  c15_wb_x = muDoubleScalarCos(c15_wb_x);
  c15_cb_a = c15_b_l;
  c15_cb_b = c15_wb_x;
  c15_gb_y = c15_cb_a * c15_cb_b;
  c15_EE[0] = (((c15_xb + c15_db_y) + c15_eb_y) + c15_fb_y) + c15_gb_y;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 26);
  c15_xb_x = c15_thetab;
  c15_yb_x = c15_xb_x;
  c15_yb_x = muDoubleScalarSin(c15_yb_x);
  c15_db_a = c15_b_lb;
  c15_db_b = c15_yb_x;
  c15_hb_y = c15_db_a * c15_db_b;
  c15_ac_x = c15_qqd[6] + c15_thetab;
  c15_bc_x = c15_ac_x;
  c15_bc_x = muDoubleScalarSin(c15_bc_x);
  c15_eb_a = c15_b_l;
  c15_eb_b = c15_bc_x;
  c15_ib_y = c15_eb_a * c15_eb_b;
  c15_cc_x = (c15_qqd[7] + c15_qqd[6]) + c15_thetab;
  c15_dc_x = c15_cc_x;
  c15_dc_x = muDoubleScalarSin(c15_dc_x);
  c15_fb_a = c15_b_l;
  c15_fb_b = c15_dc_x;
  c15_jb_y = c15_fb_a * c15_fb_b;
  c15_ec_x = ((c15_qqd[8] + c15_qqd[7]) + c15_qqd[6]) + c15_thetab;
  c15_fc_x = c15_ec_x;
  c15_fc_x = muDoubleScalarSin(c15_fc_x);
  c15_gb_a = c15_b_l;
  c15_gb_b = c15_fc_x;
  c15_kb_y = c15_gb_a * c15_gb_b;
  c15_EE[1] = (((c15_yb + c15_hb_y) + c15_ib_y) + c15_jb_y) + c15_kb_y;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 27);
  c15_EE[2] = ((c15_qqd[8] + c15_qqd[7]) + c15_qqd[6]) + c15_thetab;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 28);
  c15_hb_a = -c15_b_lb;
  c15_hb_b = c15_thetabb;
  c15_lb_y = c15_hb_a * c15_hb_b;
  c15_gc_x = c15_thetab;
  c15_hc_x = c15_gc_x;
  c15_hc_x = muDoubleScalarSin(c15_hc_x);
  c15_ib_a = c15_lb_y;
  c15_ib_b = c15_hc_x;
  c15_mb_y = c15_ib_a * c15_ib_b;
  c15_jb_a = c15_b_l;
  c15_jb_b = c15_qqd[3] + c15_thetabb;
  c15_nb_y = c15_jb_a * c15_jb_b;
  c15_ic_x = c15_qqd[6] + c15_thetab;
  c15_jc_x = c15_ic_x;
  c15_jc_x = muDoubleScalarSin(c15_jc_x);
  c15_kb_a = c15_nb_y;
  c15_kb_b = c15_jc_x;
  c15_ob_y = c15_kb_a * c15_kb_b;
  c15_lb_a = c15_b_l;
  c15_lb_b = (c15_qqd[3] + c15_qqd[4]) + c15_thetabb;
  c15_pb_y = c15_lb_a * c15_lb_b;
  c15_kc_x = (c15_qqd[7] + c15_qqd[6]) + c15_thetab;
  c15_lc_x = c15_kc_x;
  c15_lc_x = muDoubleScalarSin(c15_lc_x);
  c15_mb_a = c15_pb_y;
  c15_mb_b = c15_lc_x;
  c15_qb_y = c15_mb_a * c15_mb_b;
  c15_nb_a = c15_b_l;
  c15_nb_b = ((c15_qqd[3] + c15_qqd[4]) + c15_qqd[5]) + c15_thetabb;
  c15_rb_y = c15_nb_a * c15_nb_b;
  c15_mc_x = ((c15_qqd[8] + c15_qqd[7]) + c15_qqd[6]) + c15_thetab;
  c15_nc_x = c15_mc_x;
  c15_nc_x = muDoubleScalarSin(c15_nc_x);
  c15_ob_a = c15_rb_y;
  c15_ob_b = c15_nc_x;
  c15_sb_y = c15_ob_a * c15_ob_b;
  c15_EE[3] = ((c15_mb_y - c15_ob_y) - c15_qb_y) - c15_sb_y;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 29);
  c15_pb_a = c15_b_lb;
  c15_pb_b = c15_thetabb;
  c15_tb_y = c15_pb_a * c15_pb_b;
  c15_oc_x = c15_thetab;
  c15_pc_x = c15_oc_x;
  c15_pc_x = muDoubleScalarCos(c15_pc_x);
  c15_qb_a = c15_tb_y;
  c15_qb_b = c15_pc_x;
  c15_ub_y = c15_qb_a * c15_qb_b;
  c15_rb_a = c15_b_l;
  c15_rb_b = c15_qqd[3] + c15_thetabb;
  c15_vb_y = c15_rb_a * c15_rb_b;
  c15_qc_x = c15_qqd[6] + c15_thetab;
  c15_rc_x = c15_qc_x;
  c15_rc_x = muDoubleScalarCos(c15_rc_x);
  c15_sb_a = c15_vb_y;
  c15_sb_b = c15_rc_x;
  c15_wb_y = c15_sb_a * c15_sb_b;
  c15_tb_a = c15_b_l;
  c15_tb_b = (c15_qqd[3] + c15_qqd[4]) + c15_thetabb;
  c15_xb_y = c15_tb_a * c15_tb_b;
  c15_sc_x = (c15_qqd[7] + c15_qqd[6]) + c15_thetab;
  c15_tc_x = c15_sc_x;
  c15_tc_x = muDoubleScalarCos(c15_tc_x);
  c15_ub_a = c15_xb_y;
  c15_ub_b = c15_tc_x;
  c15_yb_y = c15_ub_a * c15_ub_b;
  c15_vb_a = c15_b_l;
  c15_vb_b = ((c15_qqd[3] + c15_qqd[4]) + c15_qqd[5]) + c15_thetabb;
  c15_ac_y = c15_vb_a * c15_vb_b;
  c15_uc_x = ((c15_qqd[8] + c15_qqd[7]) + c15_qqd[6]) + c15_thetab;
  c15_vc_x = c15_uc_x;
  c15_vc_x = muDoubleScalarCos(c15_vc_x);
  c15_wb_a = c15_ac_y;
  c15_wb_b = c15_vc_x;
  c15_bc_y = c15_wb_a * c15_wb_b;
  c15_EE[4] = ((c15_ub_y + c15_wb_y) + c15_yb_y) + c15_bc_y;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 30);
  c15_EE[5] = ((c15_qqd[3] + c15_qqd[4]) + c15_qqd[5]) + c15_thetabb;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 34);
  c15_xb_a = c15_b_m;
  c15_cc_y = c15_xb_a * 3.0;
  c15_M = c15_cc_y + c15_b_mb;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 36);
  c15_r0[0] = c15_xb;
  c15_r0[1] = c15_yb;
  c15_r0[2] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 39);
  c15_V[0] = c15_qqd[6];
  c15_V[1] = c15_qqd[3];
  c15_V[2] = c15_qqd[0];
  c15_V[3] = c15_qqd[7];
  c15_V[4] = c15_qqd[4];
  c15_V[5] = c15_qqd[1];
  c15_V[6] = c15_qqd[8];
  c15_V[7] = c15_qqd[5];
  c15_V[8] = c15_qqd[2];
  c15_V[9] = c15_thetab;
  c15_V[10] = c15_thetabb;
  c15_V[11] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 42);
  c15_wc_x = c15_V[9];
  c15_xc_x = c15_wc_x;
  c15_xc_x = muDoubleScalarCos(c15_xc_x);
  c15_yb_a = c15_b_lb;
  c15_xb_b = c15_xc_x;
  c15_dc_y = c15_yb_a * c15_xb_b;
  c15_yc_x = c15_V[9];
  c15_ad_x = c15_yc_x;
  c15_ad_x = muDoubleScalarSin(c15_ad_x);
  c15_ac_a = c15_b_lb;
  c15_yb_b = c15_ad_x;
  c15_ec_y = c15_ac_a * c15_yb_b;
  c15_pl1[0] = c15_dc_y;
  c15_pl1[1] = c15_ec_y;
  c15_pl1[2] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 43);
  c15_bd_x = c15_V[0] + c15_V[9];
  c15_cd_x = c15_bd_x;
  c15_cd_x = muDoubleScalarCos(c15_cd_x);
  c15_bc_a = c15_b_l;
  c15_ac_b = c15_cd_x;
  c15_fc_y = c15_bc_a * c15_ac_b;
  c15_dd_x = c15_V[0] + c15_V[9];
  c15_ed_x = c15_dd_x;
  c15_ed_x = muDoubleScalarSin(c15_ed_x);
  c15_cc_a = c15_b_l;
  c15_bc_b = c15_ed_x;
  c15_gc_y = c15_cc_a * c15_bc_b;
  c15_pl2[0] = c15_fc_y;
  c15_pl2[1] = c15_gc_y;
  c15_pl2[2] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 44);
  c15_fd_x = (c15_V[0] + c15_V[3]) + c15_V[9];
  c15_gd_x = c15_fd_x;
  c15_gd_x = muDoubleScalarCos(c15_gd_x);
  c15_dc_a = c15_b_l;
  c15_cc_b = c15_gd_x;
  c15_hc_y = c15_dc_a * c15_cc_b;
  c15_hd_x = (c15_V[0] + c15_V[3]) + c15_V[9];
  c15_id_x = c15_hd_x;
  c15_id_x = muDoubleScalarSin(c15_id_x);
  c15_ec_a = c15_b_l;
  c15_dc_b = c15_id_x;
  c15_ic_y = c15_ec_a * c15_dc_b;
  c15_pl3[0] = c15_hc_y;
  c15_pl3[1] = c15_ic_y;
  c15_pl3[2] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 46);
  c15_jd_x = ((c15_V[0] + c15_V[3]) + c15_V[6]) + c15_V[9];
  c15_kd_x = c15_jd_x;
  c15_kd_x = muDoubleScalarCos(c15_kd_x);
  c15_fc_a = c15_b_l;
  c15_ec_b = c15_kd_x;
  c15_jc_y = c15_fc_a * c15_ec_b;
  c15_ld_x = ((c15_V[0] + c15_V[3]) + c15_V[6]) + c15_V[9];
  c15_md_x = c15_ld_x;
  c15_md_x = muDoubleScalarSin(c15_md_x);
  c15_gc_a = c15_b_l;
  c15_fc_b = c15_md_x;
  c15_kc_y = c15_gc_a * c15_fc_b;
  c15_plr[0] = c15_jc_y;
  c15_plr[1] = c15_kc_y;
  c15_plr[2] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 50);
  for (c15_i17 = 0; c15_i17 < 3; c15_i17++) {
    c15_p1[c15_i17] = c15_r0[c15_i17] + c15_pl1[c15_i17];
  }

  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 51);
  for (c15_i18 = 0; c15_i18 < 3; c15_i18++) {
    c15_p2[c15_i18] = (c15_r0[c15_i18] + c15_pl1[c15_i18]) + c15_pl2[c15_i18];
  }

  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 52);
  for (c15_i19 = 0; c15_i19 < 3; c15_i19++) {
    c15_p3[c15_i19] = ((c15_r0[c15_i19] + c15_pl1[c15_i19]) + c15_pl2[c15_i19])
      + c15_pl3[c15_i19];
  }

  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 55);
  c15_e_A = c15_b_l;
  c15_nd_x = c15_e_A;
  c15_od_x = c15_nd_x;
  c15_lc_y = c15_od_x / 2.0;
  c15_pd_x = c15_V[0] + c15_V[9];
  c15_qd_x = c15_pd_x;
  c15_qd_x = muDoubleScalarCos(c15_qd_x);
  c15_hc_a = c15_lc_y;
  c15_gc_b = c15_qd_x;
  c15_mc_y = c15_hc_a * c15_gc_b;
  c15_f_A = c15_b_l;
  c15_rd_x = c15_f_A;
  c15_sd_x = c15_rd_x;
  c15_nc_y = c15_sd_x / 2.0;
  c15_td_x = c15_V[0] + c15_V[9];
  c15_ud_x = c15_td_x;
  c15_ud_x = muDoubleScalarSin(c15_ud_x);
  c15_ic_a = c15_nc_y;
  c15_hc_b = c15_ud_x;
  c15_oc_y = c15_ic_a * c15_hc_b;
  c15_pc_y[0] = c15_mc_y;
  c15_pc_y[1] = c15_oc_y;
  c15_pc_y[2] = 0.0;
  for (c15_i20 = 0; c15_i20 < 3; c15_i20++) {
    c15_r1[c15_i20] = c15_p1[c15_i20] + c15_pc_y[c15_i20];
  }

  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 56);
  c15_g_A = c15_b_l;
  c15_vd_x = c15_g_A;
  c15_wd_x = c15_vd_x;
  c15_qc_y = c15_wd_x / 2.0;
  c15_xd_x = (c15_V[0] + c15_V[3]) + c15_V[9];
  c15_yd_x = c15_xd_x;
  c15_yd_x = muDoubleScalarCos(c15_yd_x);
  c15_jc_a = c15_qc_y;
  c15_ic_b = c15_yd_x;
  c15_rc_y = c15_jc_a * c15_ic_b;
  c15_h_A = c15_b_l;
  c15_ae_x = c15_h_A;
  c15_be_x = c15_ae_x;
  c15_sc_y = c15_be_x / 2.0;
  c15_ce_x = (c15_V[0] + c15_V[3]) + c15_V[9];
  c15_de_x = c15_ce_x;
  c15_de_x = muDoubleScalarSin(c15_de_x);
  c15_kc_a = c15_sc_y;
  c15_jc_b = c15_de_x;
  c15_tc_y = c15_kc_a * c15_jc_b;
  c15_uc_y[0] = c15_rc_y;
  c15_uc_y[1] = c15_tc_y;
  c15_uc_y[2] = 0.0;
  for (c15_i21 = 0; c15_i21 < 3; c15_i21++) {
    c15_r2[c15_i21] = c15_p2[c15_i21] + c15_uc_y[c15_i21];
  }

  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 57);
  c15_i_A = c15_b_l;
  c15_ee_x = c15_i_A;
  c15_fe_x = c15_ee_x;
  c15_vc_y = c15_fe_x / 2.0;
  c15_ge_x = ((c15_V[0] + c15_V[3]) + c15_V[6]) + c15_V[9];
  c15_he_x = c15_ge_x;
  c15_he_x = muDoubleScalarCos(c15_he_x);
  c15_lc_a = c15_vc_y;
  c15_kc_b = c15_he_x;
  c15_wc_y = c15_lc_a * c15_kc_b;
  c15_j_A = c15_b_l;
  c15_ie_x = c15_j_A;
  c15_je_x = c15_ie_x;
  c15_xc_y = c15_je_x / 2.0;
  c15_ke_x = ((c15_V[0] + c15_V[3]) + c15_V[6]) + c15_V[9];
  c15_le_x = c15_ke_x;
  c15_le_x = muDoubleScalarSin(c15_le_x);
  c15_mc_a = c15_xc_y;
  c15_lc_b = c15_le_x;
  c15_yc_y = c15_mc_a * c15_lc_b;
  c15_ad_y[0] = c15_wc_y;
  c15_ad_y[1] = c15_yc_y;
  c15_ad_y[2] = 0.0;
  for (c15_i22 = 0; c15_i22 < 3; c15_i22++) {
    c15_r3[c15_i22] = c15_p3[c15_i22] + c15_ad_y[c15_i22];
  }

  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 60);
  c15_k_A = c15_b_mb;
  c15_B = c15_M;
  c15_me_x = c15_k_A;
  c15_bd_y = c15_B;
  c15_ne_x = c15_me_x;
  c15_cd_y = c15_bd_y;
  c15_dd_y = c15_ne_x / c15_cd_y;
  c15_nc_a = c15_dd_y;
  for (c15_i23 = 0; c15_i23 < 3; c15_i23++) {
    c15_mc_b[c15_i23] = c15_r0[c15_i23];
  }

  for (c15_i24 = 0; c15_i24 < 3; c15_i24++) {
    c15_mc_b[c15_i24] *= c15_nc_a;
  }

  c15_l_A = c15_b_m;
  c15_b_B = c15_M;
  c15_oe_x = c15_l_A;
  c15_ed_y = c15_b_B;
  c15_pe_x = c15_oe_x;
  c15_fd_y = c15_ed_y;
  c15_gd_y = c15_pe_x / c15_fd_y;
  c15_oc_a = c15_gd_y;
  for (c15_i25 = 0; c15_i25 < 3; c15_i25++) {
    c15_nc_b[c15_i25] = (c15_r1[c15_i25] + c15_r2[c15_i25]) + c15_r3[c15_i25];
  }

  for (c15_i26 = 0; c15_i26 < 3; c15_i26++) {
    c15_nc_b[c15_i26] *= c15_oc_a;
  }

  for (c15_i27 = 0; c15_i27 < 3; c15_i27++) {
    c15_rg[c15_i27] = c15_mc_b[c15_i27] + c15_nc_b[c15_i27];
  }

  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 61);
  for (c15_i28 = 0; c15_i28 < 3; c15_i28++) {
    c15_roc[c15_i28] = c15_rg[c15_i28] - c15_r0[c15_i28];
  }

  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 65);
  for (c15_i29 = 0; c15_i29 < 3; c15_i29++) {
    c15_pr[c15_i29] = (((c15_r0[c15_i29] + c15_pl1[c15_i29]) + c15_pl2[c15_i29])
                       + c15_pl3[c15_i29]) + c15_plr[c15_i29];
  }

  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 68);
  for (c15_i30 = 0; c15_i30 < 3; c15_i30++) {
    c15_Rcm[c15_i30] = c15_roc[c15_i30] - c15_pr[c15_i30];
  }

  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, -68);
  _SFD_SYMBOL_SCOPE_POP();
  for (c15_i31 = 0; c15_i31 < 6; c15_i31++) {
    (*c15_b_state_3link)[c15_i31] = c15_state_3link[c15_i31];
  }

  for (c15_i32 = 0; c15_i32 < 6; c15_i32++) {
    (*c15_b_EE)[c15_i32] = c15_EE[c15_i32];
  }

  for (c15_i33 = 0; c15_i33 < 3; c15_i33++) {
    (*c15_b_Rcm)[c15_i33] = c15_Rcm[c15_i33];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c15_sfEvent);
}

static void initSimStructsc15_CusakisME4901(SFc15_CusakisME4901InstanceStruct
  *chartInstance)
{
}

static void registerMessagesc15_CusakisME4901(SFc15_CusakisME4901InstanceStruct *
  chartInstance)
{
}

static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber)
{
}

static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i34;
  real_T c15_b_inData[3];
  int32_T c15_i35;
  real_T c15_u[3];
  const mxArray *c15_y = NULL;
  SFc15_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc15_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i34 = 0; c15_i34 < 3; c15_i34++) {
    c15_b_inData[c15_i34] = (*(real_T (*)[3])c15_inData)[c15_i34];
  }

  for (c15_i35 = 0; c15_i35 < 3; c15_i35++) {
    c15_u[c15_i35] = c15_b_inData[c15_i35];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, FALSE);
  return c15_mxArrayOutData;
}

static void c15_emlrt_marshallIn(SFc15_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c15_Rcm, const char_T *c15_identifier, real_T
  c15_y[3])
{
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_Rcm), &c15_thisId, c15_y);
  sf_mex_destroy(&c15_Rcm);
}

static void c15_b_emlrt_marshallIn(SFc15_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[3])
{
  real_T c15_dv3[3];
  int32_T c15_i36;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv3, 1, 0, 0U, 1, 0U, 1, 3);
  for (c15_i36 = 0; c15_i36 < 3; c15_i36++) {
    c15_y[c15_i36] = c15_dv3[c15_i36];
  }

  sf_mex_destroy(&c15_u);
}

static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_Rcm;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y[3];
  int32_T c15_i37;
  SFc15_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc15_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c15_Rcm = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_Rcm), &c15_thisId, c15_y);
  sf_mex_destroy(&c15_Rcm);
  for (c15_i37 = 0; c15_i37 < 3; c15_i37++) {
    (*(real_T (*)[3])c15_outData)[c15_i37] = c15_y[c15_i37];
  }

  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i38;
  real_T c15_b_inData[6];
  int32_T c15_i39;
  real_T c15_u[6];
  const mxArray *c15_y = NULL;
  SFc15_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc15_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i38 = 0; c15_i38 < 6; c15_i38++) {
    c15_b_inData[c15_i38] = (*(real_T (*)[6])c15_inData)[c15_i38];
  }

  for (c15_i39 = 0; c15_i39 < 6; c15_i39++) {
    c15_u[c15_i39] = c15_b_inData[c15_i39];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, FALSE);
  return c15_mxArrayOutData;
}

static void c15_c_emlrt_marshallIn(SFc15_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c15_EE, const char_T *c15_identifier, real_T
  c15_y[6])
{
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_EE), &c15_thisId, c15_y);
  sf_mex_destroy(&c15_EE);
}

static void c15_d_emlrt_marshallIn(SFc15_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[6])
{
  real_T c15_dv4[6];
  int32_T c15_i40;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv4, 1, 0, 0U, 1, 0U, 1, 6);
  for (c15_i40 = 0; c15_i40 < 6; c15_i40++) {
    c15_y[c15_i40] = c15_dv4[c15_i40];
  }

  sf_mex_destroy(&c15_u);
}

static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_EE;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y[6];
  int32_T c15_i41;
  SFc15_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc15_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c15_EE = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_EE), &c15_thisId, c15_y);
  sf_mex_destroy(&c15_EE);
  for (c15_i41 = 0; c15_i41 < 6; c15_i41++) {
    (*(real_T (*)[6])c15_outData)[c15_i41] = c15_y[c15_i41];
  }

  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  real_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc15_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(real_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, FALSE);
  return c15_mxArrayOutData;
}

static real_T c15_e_emlrt_marshallIn(SFc15_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  real_T c15_y;
  real_T c15_d4;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_d4, 1, 0, 0U, 0, 0U, 0);
  c15_y = c15_d4;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_m;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y;
  SFc15_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc15_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c15_b_m = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_m), &c15_thisId);
  sf_mex_destroy(&c15_b_m);
  *(real_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_d_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i42;
  real_T c15_b_inData[9];
  int32_T c15_i43;
  real_T c15_u[9];
  const mxArray *c15_y = NULL;
  SFc15_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc15_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i42 = 0; c15_i42 < 9; c15_i42++) {
    c15_b_inData[c15_i42] = (*(real_T (*)[9])c15_inData)[c15_i42];
  }

  for (c15_i43 = 0; c15_i43 < 9; c15_i43++) {
    c15_u[c15_i43] = c15_b_inData[c15_i43];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 1, 9), FALSE);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, FALSE);
  return c15_mxArrayOutData;
}

static const mxArray *c15_e_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i44;
  real_T c15_b_inData[12];
  int32_T c15_i45;
  real_T c15_u[12];
  const mxArray *c15_y = NULL;
  SFc15_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc15_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i44 = 0; c15_i44 < 12; c15_i44++) {
    c15_b_inData[c15_i44] = (*(real_T (*)[12])c15_inData)[c15_i44];
  }

  for (c15_i45 = 0; c15_i45 < 12; c15_i45++) {
    c15_u[c15_i45] = c15_b_inData[c15_i45];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 2, 1, 12),
                FALSE);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, FALSE);
  return c15_mxArrayOutData;
}

static void c15_f_emlrt_marshallIn(SFc15_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[12])
{
  real_T c15_dv5[12];
  int32_T c15_i46;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv5, 1, 0, 0U, 1, 0U, 2, 1,
                12);
  for (c15_i46 = 0; c15_i46 < 12; c15_i46++) {
    c15_y[c15_i46] = c15_dv5[c15_i46];
  }

  sf_mex_destroy(&c15_u);
}

static void c15_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_V;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y[12];
  int32_T c15_i47;
  SFc15_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc15_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c15_V = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_V), &c15_thisId, c15_y);
  sf_mex_destroy(&c15_V);
  for (c15_i47 = 0; c15_i47 < 12; c15_i47++) {
    (*(real_T (*)[12])c15_outData)[c15_i47] = c15_y[c15_i47];
  }

  sf_mex_destroy(&c15_mxArrayInData);
}

const mxArray *sf_c15_CusakisME4901_get_eml_resolved_functions_info(void)
{
  const mxArray *c15_nameCaptureInfo;
  c15_ResolvedFunctionInfo c15_info[9];
  c15_ResolvedFunctionInfo (*c15_b_info)[9];
  const mxArray *c15_m0 = NULL;
  int32_T c15_i48;
  c15_ResolvedFunctionInfo *c15_r0;
  c15_nameCaptureInfo = NULL;
  c15_nameCaptureInfo = NULL;
  c15_b_info = (c15_ResolvedFunctionInfo (*)[9])c15_info;
  (*c15_b_info)[0].context = "";
  (*c15_b_info)[0].name = "cos";
  (*c15_b_info)[0].dominantType = "double";
  (*c15_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c15_b_info)[0].fileTimeLo = 1343862772U;
  (*c15_b_info)[0].fileTimeHi = 0U;
  (*c15_b_info)[0].mFileTimeLo = 0U;
  (*c15_b_info)[0].mFileTimeHi = 0U;
  (*c15_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c15_b_info)[1].name = "eml_scalar_cos";
  (*c15_b_info)[1].dominantType = "double";
  (*c15_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c15_b_info)[1].fileTimeLo = 1286851122U;
  (*c15_b_info)[1].fileTimeHi = 0U;
  (*c15_b_info)[1].mFileTimeLo = 0U;
  (*c15_b_info)[1].mFileTimeHi = 0U;
  (*c15_b_info)[2].context = "";
  (*c15_b_info)[2].name = "mtimes";
  (*c15_b_info)[2].dominantType = "double";
  (*c15_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c15_b_info)[2].fileTimeLo = 1289552092U;
  (*c15_b_info)[2].fileTimeHi = 0U;
  (*c15_b_info)[2].mFileTimeLo = 0U;
  (*c15_b_info)[2].mFileTimeHi = 0U;
  (*c15_b_info)[3].context = "";
  (*c15_b_info)[3].name = "mrdivide";
  (*c15_b_info)[3].dominantType = "double";
  (*c15_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c15_b_info)[3].fileTimeLo = 1357983948U;
  (*c15_b_info)[3].fileTimeHi = 0U;
  (*c15_b_info)[3].mFileTimeLo = 1319762366U;
  (*c15_b_info)[3].mFileTimeHi = 0U;
  (*c15_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c15_b_info)[4].name = "rdivide";
  (*c15_b_info)[4].dominantType = "double";
  (*c15_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c15_b_info)[4].fileTimeLo = 1346542788U;
  (*c15_b_info)[4].fileTimeHi = 0U;
  (*c15_b_info)[4].mFileTimeLo = 0U;
  (*c15_b_info)[4].mFileTimeHi = 0U;
  (*c15_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c15_b_info)[5].name = "eml_scalexp_compatible";
  (*c15_b_info)[5].dominantType = "double";
  (*c15_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  (*c15_b_info)[5].fileTimeLo = 1286851196U;
  (*c15_b_info)[5].fileTimeHi = 0U;
  (*c15_b_info)[5].mFileTimeLo = 0U;
  (*c15_b_info)[5].mFileTimeHi = 0U;
  (*c15_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c15_b_info)[6].name = "eml_div";
  (*c15_b_info)[6].dominantType = "double";
  (*c15_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c15_b_info)[6].fileTimeLo = 1313380210U;
  (*c15_b_info)[6].fileTimeHi = 0U;
  (*c15_b_info)[6].mFileTimeLo = 0U;
  (*c15_b_info)[6].mFileTimeHi = 0U;
  (*c15_b_info)[7].context = "";
  (*c15_b_info)[7].name = "sin";
  (*c15_b_info)[7].dominantType = "double";
  (*c15_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c15_b_info)[7].fileTimeLo = 1343862786U;
  (*c15_b_info)[7].fileTimeHi = 0U;
  (*c15_b_info)[7].mFileTimeLo = 0U;
  (*c15_b_info)[7].mFileTimeHi = 0U;
  (*c15_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c15_b_info)[8].name = "eml_scalar_sin";
  (*c15_b_info)[8].dominantType = "double";
  (*c15_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c15_b_info)[8].fileTimeLo = 1286851136U;
  (*c15_b_info)[8].fileTimeHi = 0U;
  (*c15_b_info)[8].mFileTimeLo = 0U;
  (*c15_b_info)[8].mFileTimeHi = 0U;
  sf_mex_assign(&c15_m0, sf_mex_createstruct("nameCaptureInfo", 1, 9), FALSE);
  for (c15_i48 = 0; c15_i48 < 9; c15_i48++) {
    c15_r0 = &c15_info[c15_i48];
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", c15_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c15_r0->context)), "context", "nameCaptureInfo",
                    c15_i48);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", c15_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c15_r0->name)), "name", "nameCaptureInfo",
                    c15_i48);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo",
      c15_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c15_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c15_i48);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", c15_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c15_r0->resolved)), "resolved",
                    "nameCaptureInfo", c15_i48);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", &c15_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c15_i48);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", &c15_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c15_i48);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo",
      &c15_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c15_i48);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo",
      &c15_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c15_i48);
  }

  sf_mex_assign(&c15_nameCaptureInfo, c15_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c15_nameCaptureInfo);
  return c15_nameCaptureInfo;
}

static const mxArray *c15_f_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc15_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(int32_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, FALSE);
  return c15_mxArrayOutData;
}

static int32_T c15_g_emlrt_marshallIn(SFc15_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  int32_T c15_y;
  int32_T c15_i49;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_i49, 1, 6, 0U, 0, 0U, 0);
  c15_y = c15_i49;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_sfEvent;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  int32_T c15_y;
  SFc15_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc15_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c15_b_sfEvent = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_sfEvent),
    &c15_thisId);
  sf_mex_destroy(&c15_b_sfEvent);
  *(int32_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static uint8_T c15_h_emlrt_marshallIn(SFc15_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c15_b_is_active_c15_CusakisME4901, const char_T
  *c15_identifier)
{
  uint8_T c15_y;
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c15_b_is_active_c15_CusakisME4901), &c15_thisId);
  sf_mex_destroy(&c15_b_is_active_c15_CusakisME4901);
  return c15_y;
}

static uint8_T c15_i_emlrt_marshallIn(SFc15_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  uint8_T c15_y;
  uint8_T c15_u0;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_u0, 1, 3, 0U, 0, 0U, 0);
  c15_y = c15_u0;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void init_dsm_address_info(SFc15_CusakisME4901InstanceStruct
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

void sf_c15_CusakisME4901_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(657106782U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2276225585U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1287795013U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1799322650U);
}

mxArray *sf_c15_CusakisME4901_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("sEhU2zj82qyMk45fZwG8GG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
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
      pr[0] = (double)(6);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c15_CusakisME4901_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c15_CusakisME4901(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[8],T\"EE\",},{M[1],M[13],T\"Rcm\",},{M[1],M[5],T\"state_3link\",},{M[8],M[0],T\"is_active_c15_CusakisME4901\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c15_CusakisME4901_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc15_CusakisME4901InstanceStruct *chartInstance;
    chartInstance = (SFc15_CusakisME4901InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CusakisME4901MachineNumber_,
           15,
           1,
           1,
           10,
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
          _SFD_SET_DATA_PROPS(1,1,1,0,"SC");
          _SFD_SET_DATA_PROPS(2,1,1,0,"dSC");
          _SFD_SET_DATA_PROPS(3,2,0,1,"state_3link");
          _SFD_SET_DATA_PROPS(4,10,0,0,"lb");
          _SFD_SET_DATA_PROPS(5,10,0,0,"l");
          _SFD_SET_DATA_PROPS(6,2,0,1,"EE");
          _SFD_SET_DATA_PROPS(7,10,0,0,"mb");
          _SFD_SET_DATA_PROPS(8,10,0,0,"m");
          _SFD_SET_DATA_PROPS(9,2,0,1,"Rcm");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,3252);
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
            1.0,0,0,(MexFcnForType)c15_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c15_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c15_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c15_b_sf_marshallOut,(MexInFcnForType)
            c15_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_c_sf_marshallOut,(MexInFcnForType)
          c15_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_c_sf_marshallOut,(MexInFcnForType)
          c15_c_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c15_b_sf_marshallOut,(MexInFcnForType)
            c15_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_c_sf_marshallOut,(MexInFcnForType)
          c15_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_c_sf_marshallOut,(MexInFcnForType)
          c15_c_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)
            c15_sf_marshallIn);
        }

        {
          real_T (*c15_qqd)[9];
          real_T (*c15_SC)[6];
          real_T (*c15_dSC)[6];
          real_T (*c15_state_3link)[6];
          real_T (*c15_EE)[6];
          real_T (*c15_Rcm)[3];
          c15_Rcm = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
          c15_EE = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 2);
          c15_state_3link = (real_T (*)[6])ssGetOutputPortSignal
            (chartInstance->S, 1);
          c15_dSC = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
          c15_SC = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
          c15_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c15_qqd);
          _SFD_SET_DATA_VALUE_PTR(1U, *c15_SC);
          _SFD_SET_DATA_VALUE_PTR(2U, *c15_dSC);
          _SFD_SET_DATA_VALUE_PTR(3U, *c15_state_3link);
          _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c15_lb);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c15_l);
          _SFD_SET_DATA_VALUE_PTR(6U, *c15_EE);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c15_mb);
          _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c15_m);
          _SFD_SET_DATA_VALUE_PTR(9U, *c15_Rcm);
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
  return "rxg9m5YxCuiidZJEVbJaQF";
}

static void sf_opaque_initialize_c15_CusakisME4901(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc15_CusakisME4901InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c15_CusakisME4901((SFc15_CusakisME4901InstanceStruct*)
    chartInstanceVar);
  initialize_c15_CusakisME4901((SFc15_CusakisME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c15_CusakisME4901(void *chartInstanceVar)
{
  enable_c15_CusakisME4901((SFc15_CusakisME4901InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c15_CusakisME4901(void *chartInstanceVar)
{
  disable_c15_CusakisME4901((SFc15_CusakisME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c15_CusakisME4901(void *chartInstanceVar)
{
  sf_c15_CusakisME4901((SFc15_CusakisME4901InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c15_CusakisME4901(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c15_CusakisME4901
    ((SFc15_CusakisME4901InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c15_CusakisME4901();/* state var info */
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

extern void sf_internal_set_sim_state_c15_CusakisME4901(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c15_CusakisME4901();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c15_CusakisME4901((SFc15_CusakisME4901InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c15_CusakisME4901(SimStruct* S)
{
  return sf_internal_get_sim_state_c15_CusakisME4901(S);
}

static void sf_opaque_set_sim_state_c15_CusakisME4901(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c15_CusakisME4901(S, st);
}

static void sf_opaque_terminate_c15_CusakisME4901(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc15_CusakisME4901InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CusakisME4901_optimization_info();
    }

    finalize_c15_CusakisME4901((SFc15_CusakisME4901InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc15_CusakisME4901((SFc15_CusakisME4901InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c15_CusakisME4901(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c15_CusakisME4901((SFc15_CusakisME4901InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c15_CusakisME4901(SimStruct *S)
{
  /* Actual parameters from chart:
     l lb m mb
   */
  const char_T *rtParamNames[] = { "l", "lb", "m", "mb" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for l*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for lb*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for m*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for mb*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CusakisME4901_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      15);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,15,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,15,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,15);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,15,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,15,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,15);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(711101727U));
  ssSetChecksum1(S,(2601392206U));
  ssSetChecksum2(S,(3145971776U));
  ssSetChecksum3(S,(2259947026U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c15_CusakisME4901(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c15_CusakisME4901(SimStruct *S)
{
  SFc15_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc15_CusakisME4901InstanceStruct *)utMalloc(sizeof
    (SFc15_CusakisME4901InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc15_CusakisME4901InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c15_CusakisME4901;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c15_CusakisME4901;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c15_CusakisME4901;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c15_CusakisME4901;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c15_CusakisME4901;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c15_CusakisME4901;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c15_CusakisME4901;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c15_CusakisME4901;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c15_CusakisME4901;
  chartInstance->chartInfo.mdlStart = mdlStart_c15_CusakisME4901;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c15_CusakisME4901;
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

void c15_CusakisME4901_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c15_CusakisME4901(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c15_CusakisME4901(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c15_CusakisME4901(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c15_CusakisME4901_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
