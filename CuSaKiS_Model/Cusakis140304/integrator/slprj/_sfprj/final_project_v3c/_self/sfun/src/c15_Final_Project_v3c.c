/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Final_Project_v3c_sfun.h"
#include "c15_Final_Project_v3c.h"
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
static const char * c15_debug_family_names[10] = { "xb", "yb", "thetab",
  "thetabb", "nargin", "nargout", "qqd", "lb", "l", "state_3link" };

/* Function Declarations */
static void initialize_c15_Final_Project_v3c
  (SFc15_Final_Project_v3cInstanceStruct *chartInstance);
static void initialize_params_c15_Final_Project_v3c
  (SFc15_Final_Project_v3cInstanceStruct *chartInstance);
static void enable_c15_Final_Project_v3c(SFc15_Final_Project_v3cInstanceStruct
  *chartInstance);
static void disable_c15_Final_Project_v3c(SFc15_Final_Project_v3cInstanceStruct *
  chartInstance);
static void c15_update_debugger_state_c15_Final_Project_v3c
  (SFc15_Final_Project_v3cInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c15_Final_Project_v3c
  (SFc15_Final_Project_v3cInstanceStruct *chartInstance);
static void set_sim_state_c15_Final_Project_v3c
  (SFc15_Final_Project_v3cInstanceStruct *chartInstance, const mxArray *c15_st);
static void finalize_c15_Final_Project_v3c(SFc15_Final_Project_v3cInstanceStruct
  *chartInstance);
static void sf_c15_Final_Project_v3c(SFc15_Final_Project_v3cInstanceStruct
  *chartInstance);
static void c15_chartstep_c15_Final_Project_v3c
  (SFc15_Final_Project_v3cInstanceStruct *chartInstance);
static void initSimStructsc15_Final_Project_v3c
  (SFc15_Final_Project_v3cInstanceStruct *chartInstance);
static void registerMessagesc15_Final_Project_v3c
  (SFc15_Final_Project_v3cInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber);
static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_emlrt_marshallIn(SFc15_Final_Project_v3cInstanceStruct
  *chartInstance, const mxArray *c15_state_3link, const char_T *c15_identifier,
  real_T c15_y[6]);
static void c15_b_emlrt_marshallIn(SFc15_Final_Project_v3cInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[6]);
static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static real_T c15_c_emlrt_marshallIn(SFc15_Final_Project_v3cInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static const mxArray *c15_d_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static int32_T c15_d_emlrt_marshallIn(SFc15_Final_Project_v3cInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static uint8_T c15_e_emlrt_marshallIn(SFc15_Final_Project_v3cInstanceStruct
  *chartInstance, const mxArray *c15_b_is_active_c15_Final_Project_v3c, const
  char_T *c15_identifier);
static uint8_T c15_f_emlrt_marshallIn(SFc15_Final_Project_v3cInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void init_dsm_address_info(SFc15_Final_Project_v3cInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c15_Final_Project_v3c
  (SFc15_Final_Project_v3cInstanceStruct *chartInstance)
{
  chartInstance->c15_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c15_is_active_c15_Final_Project_v3c = 0U;
}

static void initialize_params_c15_Final_Project_v3c
  (SFc15_Final_Project_v3cInstanceStruct *chartInstance)
{
  real_T c15_d0;
  real_T c15_d1;
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
}

static void enable_c15_Final_Project_v3c(SFc15_Final_Project_v3cInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c15_Final_Project_v3c(SFc15_Final_Project_v3cInstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c15_update_debugger_state_c15_Final_Project_v3c
  (SFc15_Final_Project_v3cInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c15_Final_Project_v3c
  (SFc15_Final_Project_v3cInstanceStruct *chartInstance)
{
  const mxArray *c15_st;
  const mxArray *c15_y = NULL;
  int32_T c15_i0;
  real_T c15_u[6];
  const mxArray *c15_b_y = NULL;
  uint8_T c15_hoistedGlobal;
  uint8_T c15_b_u;
  const mxArray *c15_c_y = NULL;
  real_T (*c15_state_3link)[6];
  c15_state_3link = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c15_st = NULL;
  c15_st = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_createcellarray(2), FALSE);
  for (c15_i0 = 0; c15_i0 < 6; c15_i0++) {
    c15_u[c15_i0] = (*c15_state_3link)[c15_i0];
  }

  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_setcell(c15_y, 0, c15_b_y);
  c15_hoistedGlobal = chartInstance->c15_is_active_c15_Final_Project_v3c;
  c15_b_u = c15_hoistedGlobal;
  c15_c_y = NULL;
  sf_mex_assign(&c15_c_y, sf_mex_create("y", &c15_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c15_y, 1, c15_c_y);
  sf_mex_assign(&c15_st, c15_y, FALSE);
  return c15_st;
}

static void set_sim_state_c15_Final_Project_v3c
  (SFc15_Final_Project_v3cInstanceStruct *chartInstance, const mxArray *c15_st)
{
  const mxArray *c15_u;
  real_T c15_dv0[6];
  int32_T c15_i1;
  real_T (*c15_state_3link)[6];
  c15_state_3link = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c15_doneDoubleBufferReInit = TRUE;
  c15_u = sf_mex_dup(c15_st);
  c15_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 0)),
                       "state_3link", c15_dv0);
  for (c15_i1 = 0; c15_i1 < 6; c15_i1++) {
    (*c15_state_3link)[c15_i1] = c15_dv0[c15_i1];
  }

  chartInstance->c15_is_active_c15_Final_Project_v3c = c15_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 1)),
     "is_active_c15_Final_Project_v3c");
  sf_mex_destroy(&c15_u);
  c15_update_debugger_state_c15_Final_Project_v3c(chartInstance);
  sf_mex_destroy(&c15_st);
}

static void finalize_c15_Final_Project_v3c(SFc15_Final_Project_v3cInstanceStruct
  *chartInstance)
{
}

static void sf_c15_Final_Project_v3c(SFc15_Final_Project_v3cInstanceStruct
  *chartInstance)
{
  int32_T c15_i2;
  int32_T c15_i3;
  real_T (*c15_state_3link)[6];
  real_T (*c15_qqd)[9];
  c15_state_3link = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c15_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 14U, chartInstance->c15_sfEvent);
  for (c15_i2 = 0; c15_i2 < 9; c15_i2++) {
    _SFD_DATA_RANGE_CHECK((*c15_qqd)[c15_i2], 0U);
  }

  for (c15_i3 = 0; c15_i3 < 6; c15_i3++) {
    _SFD_DATA_RANGE_CHECK((*c15_state_3link)[c15_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c15_lb, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c15_l, 3U);
  chartInstance->c15_sfEvent = CALL_EVENT;
  c15_chartstep_c15_Final_Project_v3c(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Final_Project_v3cMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c15_chartstep_c15_Final_Project_v3c
  (SFc15_Final_Project_v3cInstanceStruct *chartInstance)
{
  real_T c15_hoistedGlobal;
  real_T c15_b_hoistedGlobal;
  int32_T c15_i4;
  real_T c15_qqd[9];
  real_T c15_b_lb;
  real_T c15_b_l;
  uint32_T c15_debug_family_var_map[10];
  real_T c15_xb;
  real_T c15_yb;
  real_T c15_thetab;
  real_T c15_thetabb;
  real_T c15_nargin = 3.0;
  real_T c15_nargout = 1.0;
  real_T c15_state_3link[6];
  int32_T c15_i5;
  real_T c15_a;
  real_T c15_y;
  real_T c15_x;
  real_T c15_b_x;
  real_T c15_b_a;
  real_T c15_b;
  real_T c15_b_y;
  real_T c15_c_x;
  real_T c15_d_x;
  real_T c15_c_a;
  real_T c15_b_b;
  real_T c15_c_y;
  real_T c15_A;
  real_T c15_e_x;
  real_T c15_f_x;
  real_T c15_d_y;
  real_T c15_g_x;
  real_T c15_h_x;
  real_T c15_d_a;
  real_T c15_c_b;
  real_T c15_e_y;
  real_T c15_e_a;
  real_T c15_f_y;
  real_T c15_i_x;
  real_T c15_j_x;
  real_T c15_f_a;
  real_T c15_d_b;
  real_T c15_g_y;
  real_T c15_k_x;
  real_T c15_l_x;
  real_T c15_g_a;
  real_T c15_e_b;
  real_T c15_h_y;
  real_T c15_b_A;
  real_T c15_m_x;
  real_T c15_n_x;
  real_T c15_i_y;
  real_T c15_o_x;
  real_T c15_p_x;
  real_T c15_h_a;
  real_T c15_f_b;
  real_T c15_j_y;
  real_T c15_i_a;
  real_T c15_k_y;
  real_T c15_j_a;
  real_T c15_l_y;
  real_T c15_k_a;
  real_T c15_g_b;
  real_T c15_m_y;
  real_T c15_q_x;
  real_T c15_r_x;
  real_T c15_l_a;
  real_T c15_h_b;
  real_T c15_n_y;
  real_T c15_m_a;
  real_T c15_i_b;
  real_T c15_o_y;
  real_T c15_s_x;
  real_T c15_t_x;
  real_T c15_n_a;
  real_T c15_j_b;
  real_T c15_p_y;
  real_T c15_c_A;
  real_T c15_u_x;
  real_T c15_v_x;
  real_T c15_q_y;
  real_T c15_o_a;
  real_T c15_k_b;
  real_T c15_r_y;
  real_T c15_w_x;
  real_T c15_x_x;
  real_T c15_p_a;
  real_T c15_l_b;
  real_T c15_s_y;
  real_T c15_q_a;
  real_T c15_t_y;
  real_T c15_r_a;
  real_T c15_u_y;
  real_T c15_s_a;
  real_T c15_m_b;
  real_T c15_v_y;
  real_T c15_y_x;
  real_T c15_ab_x;
  real_T c15_t_a;
  real_T c15_n_b;
  real_T c15_w_y;
  real_T c15_u_a;
  real_T c15_o_b;
  real_T c15_x_y;
  real_T c15_bb_x;
  real_T c15_cb_x;
  real_T c15_v_a;
  real_T c15_p_b;
  real_T c15_y_y;
  real_T c15_d_A;
  real_T c15_db_x;
  real_T c15_eb_x;
  real_T c15_ab_y;
  real_T c15_w_a;
  real_T c15_q_b;
  real_T c15_bb_y;
  real_T c15_fb_x;
  real_T c15_gb_x;
  real_T c15_x_a;
  real_T c15_r_b;
  real_T c15_cb_y;
  int32_T c15_i6;
  real_T (*c15_b_state_3link)[6];
  real_T (*c15_b_qqd)[9];
  c15_b_state_3link = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c15_b_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 14U, chartInstance->c15_sfEvent);
  c15_hoistedGlobal = chartInstance->c15_lb;
  c15_b_hoistedGlobal = chartInstance->c15_l;
  for (c15_i4 = 0; c15_i4 < 9; c15_i4++) {
    c15_qqd[c15_i4] = (*c15_b_qqd)[c15_i4];
  }

  c15_b_lb = c15_hoistedGlobal;
  c15_b_l = c15_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c15_debug_family_names,
    c15_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_xb, 0U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_yb, 1U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_thetab, 2U, c15_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_thetabb, 3U, c15_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargin, 4U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargout, 5U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c15_qqd, 6U, c15_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_lb, 7U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_b_l, 8U, c15_b_sf_marshallOut,
    c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_state_3link, 9U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 6);
  c15_xb = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 7);
  c15_yb = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 8);
  c15_thetab = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 9);
  c15_thetabb = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 11);
  for (c15_i5 = 0; c15_i5 < 6; c15_i5++) {
    c15_state_3link[c15_i5] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 13);
  c15_a = c15_b_lb;
  c15_y = c15_a;
  c15_x = c15_qqd[6] + c15_thetab;
  c15_b_x = c15_x;
  c15_b_x = muDoubleScalarCos(c15_b_x);
  c15_b_a = c15_b_l;
  c15_b = c15_b_x;
  c15_b_y = c15_b_a * c15_b;
  c15_c_x = (c15_qqd[7] + c15_qqd[6]) + c15_thetab;
  c15_d_x = c15_c_x;
  c15_d_x = muDoubleScalarCos(c15_d_x);
  c15_c_a = c15_b_l;
  c15_b_b = c15_d_x;
  c15_c_y = c15_c_a * c15_b_b;
  c15_A = c15_b_l;
  c15_e_x = c15_A;
  c15_f_x = c15_e_x;
  c15_d_y = c15_f_x / 2.0;
  c15_g_x = ((c15_qqd[8] + c15_qqd[7]) + c15_qqd[6]) + c15_thetab;
  c15_h_x = c15_g_x;
  c15_h_x = muDoubleScalarCos(c15_h_x);
  c15_d_a = c15_d_y;
  c15_c_b = c15_h_x;
  c15_e_y = c15_d_a * c15_c_b;
  c15_state_3link[0] = ((c15_y + c15_b_y) + c15_c_y) + c15_e_y;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 14);
  c15_e_a = c15_b_lb;
  c15_f_y = c15_e_a * 0.0;
  c15_i_x = c15_qqd[6] + c15_thetab;
  c15_j_x = c15_i_x;
  c15_j_x = muDoubleScalarSin(c15_j_x);
  c15_f_a = c15_b_l;
  c15_d_b = c15_j_x;
  c15_g_y = c15_f_a * c15_d_b;
  c15_k_x = (c15_qqd[7] + c15_qqd[6]) + c15_thetab;
  c15_l_x = c15_k_x;
  c15_l_x = muDoubleScalarSin(c15_l_x);
  c15_g_a = c15_b_l;
  c15_e_b = c15_l_x;
  c15_h_y = c15_g_a * c15_e_b;
  c15_b_A = c15_b_l;
  c15_m_x = c15_b_A;
  c15_n_x = c15_m_x;
  c15_i_y = c15_n_x / 2.0;
  c15_o_x = ((c15_qqd[8] + c15_qqd[7]) + c15_qqd[6]) + c15_thetab;
  c15_p_x = c15_o_x;
  c15_p_x = muDoubleScalarSin(c15_p_x);
  c15_h_a = c15_i_y;
  c15_f_b = c15_p_x;
  c15_j_y = c15_h_a * c15_f_b;
  c15_state_3link[1] = ((c15_f_y + c15_g_y) + c15_h_y) + c15_j_y;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 15);
  c15_state_3link[2] = ((c15_qqd[8] + c15_qqd[7]) + c15_qqd[6]) + c15_thetab;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 16);
  c15_i_a = -c15_b_lb;
  c15_k_y = c15_i_a * 0.0;
  c15_j_a = c15_k_y;
  c15_l_y = c15_j_a * 0.0;
  c15_k_a = c15_b_l;
  c15_g_b = c15_qqd[3] + c15_thetabb;
  c15_m_y = c15_k_a * c15_g_b;
  c15_q_x = c15_qqd[6] + c15_thetab;
  c15_r_x = c15_q_x;
  c15_r_x = muDoubleScalarSin(c15_r_x);
  c15_l_a = c15_m_y;
  c15_h_b = c15_r_x;
  c15_n_y = c15_l_a * c15_h_b;
  c15_m_a = c15_b_l;
  c15_i_b = (c15_qqd[3] + c15_qqd[4]) + c15_thetabb;
  c15_o_y = c15_m_a * c15_i_b;
  c15_s_x = (c15_qqd[7] + c15_qqd[6]) + c15_thetab;
  c15_t_x = c15_s_x;
  c15_t_x = muDoubleScalarSin(c15_t_x);
  c15_n_a = c15_o_y;
  c15_j_b = c15_t_x;
  c15_p_y = c15_n_a * c15_j_b;
  c15_c_A = c15_b_l;
  c15_u_x = c15_c_A;
  c15_v_x = c15_u_x;
  c15_q_y = c15_v_x / 2.0;
  c15_o_a = c15_q_y;
  c15_k_b = ((c15_qqd[3] + c15_qqd[4]) + c15_qqd[5]) + c15_thetabb;
  c15_r_y = c15_o_a * c15_k_b;
  c15_w_x = ((c15_qqd[8] + c15_qqd[7]) + c15_qqd[6]) + c15_thetab;
  c15_x_x = c15_w_x;
  c15_x_x = muDoubleScalarSin(c15_x_x);
  c15_p_a = c15_r_y;
  c15_l_b = c15_x_x;
  c15_s_y = c15_p_a * c15_l_b;
  c15_state_3link[3] = ((c15_l_y - c15_n_y) - c15_p_y) - c15_s_y;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 17);
  c15_q_a = c15_b_lb;
  c15_t_y = c15_q_a * 0.0;
  c15_r_a = c15_t_y;
  c15_u_y = c15_r_a;
  c15_s_a = c15_b_l;
  c15_m_b = c15_qqd[3] + c15_thetabb;
  c15_v_y = c15_s_a * c15_m_b;
  c15_y_x = c15_qqd[6] + c15_thetab;
  c15_ab_x = c15_y_x;
  c15_ab_x = muDoubleScalarCos(c15_ab_x);
  c15_t_a = c15_v_y;
  c15_n_b = c15_ab_x;
  c15_w_y = c15_t_a * c15_n_b;
  c15_u_a = c15_b_l;
  c15_o_b = (c15_qqd[3] + c15_qqd[4]) + c15_thetabb;
  c15_x_y = c15_u_a * c15_o_b;
  c15_bb_x = (c15_qqd[7] + c15_qqd[6]) + c15_thetab;
  c15_cb_x = c15_bb_x;
  c15_cb_x = muDoubleScalarCos(c15_cb_x);
  c15_v_a = c15_x_y;
  c15_p_b = c15_cb_x;
  c15_y_y = c15_v_a * c15_p_b;
  c15_d_A = c15_b_l;
  c15_db_x = c15_d_A;
  c15_eb_x = c15_db_x;
  c15_ab_y = c15_eb_x / 2.0;
  c15_w_a = c15_ab_y;
  c15_q_b = ((c15_qqd[3] + c15_qqd[4]) + c15_qqd[5]) + c15_thetabb;
  c15_bb_y = c15_w_a * c15_q_b;
  c15_fb_x = ((c15_qqd[8] + c15_qqd[7]) + c15_qqd[6]) + c15_thetab;
  c15_gb_x = c15_fb_x;
  c15_gb_x = muDoubleScalarCos(c15_gb_x);
  c15_x_a = c15_bb_y;
  c15_r_b = c15_gb_x;
  c15_cb_y = c15_x_a * c15_r_b;
  c15_state_3link[4] = ((c15_u_y + c15_w_y) + c15_y_y) + c15_cb_y;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 18);
  c15_state_3link[5] = ((c15_qqd[3] + c15_qqd[4]) + c15_qqd[5]) + c15_thetabb;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, -18);
  _SFD_SYMBOL_SCOPE_POP();
  for (c15_i6 = 0; c15_i6 < 6; c15_i6++) {
    (*c15_b_state_3link)[c15_i6] = c15_state_3link[c15_i6];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c15_sfEvent);
}

static void initSimStructsc15_Final_Project_v3c
  (SFc15_Final_Project_v3cInstanceStruct *chartInstance)
{
}

static void registerMessagesc15_Final_Project_v3c
  (SFc15_Final_Project_v3cInstanceStruct *chartInstance)
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
  int32_T c15_i7;
  real_T c15_b_inData[6];
  int32_T c15_i8;
  real_T c15_u[6];
  const mxArray *c15_y = NULL;
  SFc15_Final_Project_v3cInstanceStruct *chartInstance;
  chartInstance = (SFc15_Final_Project_v3cInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i7 = 0; c15_i7 < 6; c15_i7++) {
    c15_b_inData[c15_i7] = (*(real_T (*)[6])c15_inData)[c15_i7];
  }

  for (c15_i8 = 0; c15_i8 < 6; c15_i8++) {
    c15_u[c15_i8] = c15_b_inData[c15_i8];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, FALSE);
  return c15_mxArrayOutData;
}

static void c15_emlrt_marshallIn(SFc15_Final_Project_v3cInstanceStruct
  *chartInstance, const mxArray *c15_state_3link, const char_T *c15_identifier,
  real_T c15_y[6])
{
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_state_3link), &c15_thisId,
    c15_y);
  sf_mex_destroy(&c15_state_3link);
}

static void c15_b_emlrt_marshallIn(SFc15_Final_Project_v3cInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[6])
{
  real_T c15_dv1[6];
  int32_T c15_i9;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv1, 1, 0, 0U, 1, 0U, 1, 6);
  for (c15_i9 = 0; c15_i9 < 6; c15_i9++) {
    c15_y[c15_i9] = c15_dv1[c15_i9];
  }

  sf_mex_destroy(&c15_u);
}

static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_state_3link;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y[6];
  int32_T c15_i10;
  SFc15_Final_Project_v3cInstanceStruct *chartInstance;
  chartInstance = (SFc15_Final_Project_v3cInstanceStruct *)chartInstanceVoid;
  c15_state_3link = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_state_3link), &c15_thisId,
    c15_y);
  sf_mex_destroy(&c15_state_3link);
  for (c15_i10 = 0; c15_i10 < 6; c15_i10++) {
    (*(real_T (*)[6])c15_outData)[c15_i10] = c15_y[c15_i10];
  }

  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  real_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_Final_Project_v3cInstanceStruct *chartInstance;
  chartInstance = (SFc15_Final_Project_v3cInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(real_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, FALSE);
  return c15_mxArrayOutData;
}

static real_T c15_c_emlrt_marshallIn(SFc15_Final_Project_v3cInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  real_T c15_y;
  real_T c15_d2;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_d2, 1, 0, 0U, 0, 0U, 0);
  c15_y = c15_d2;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_l;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y;
  SFc15_Final_Project_v3cInstanceStruct *chartInstance;
  chartInstance = (SFc15_Final_Project_v3cInstanceStruct *)chartInstanceVoid;
  c15_b_l = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_l), &c15_thisId);
  sf_mex_destroy(&c15_b_l);
  *(real_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i11;
  real_T c15_b_inData[9];
  int32_T c15_i12;
  real_T c15_u[9];
  const mxArray *c15_y = NULL;
  SFc15_Final_Project_v3cInstanceStruct *chartInstance;
  chartInstance = (SFc15_Final_Project_v3cInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i11 = 0; c15_i11 < 9; c15_i11++) {
    c15_b_inData[c15_i11] = (*(real_T (*)[9])c15_inData)[c15_i11];
  }

  for (c15_i12 = 0; c15_i12 < 9; c15_i12++) {
    c15_u[c15_i12] = c15_b_inData[c15_i12];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 1, 9), FALSE);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, FALSE);
  return c15_mxArrayOutData;
}

const mxArray *sf_c15_Final_Project_v3c_get_eml_resolved_functions_info(void)
{
  const mxArray *c15_nameCaptureInfo;
  c15_ResolvedFunctionInfo c15_info[9];
  c15_ResolvedFunctionInfo (*c15_b_info)[9];
  const mxArray *c15_m0 = NULL;
  int32_T c15_i13;
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
  for (c15_i13 = 0; c15_i13 < 9; c15_i13++) {
    c15_r0 = &c15_info[c15_i13];
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", c15_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c15_r0->context)), "context", "nameCaptureInfo",
                    c15_i13);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", c15_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c15_r0->name)), "name", "nameCaptureInfo",
                    c15_i13);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo",
      c15_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c15_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c15_i13);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", c15_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c15_r0->resolved)), "resolved",
                    "nameCaptureInfo", c15_i13);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", &c15_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c15_i13);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo", &c15_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c15_i13);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo",
      &c15_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c15_i13);
    sf_mex_addfield(c15_m0, sf_mex_create("nameCaptureInfo",
      &c15_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c15_i13);
  }

  sf_mex_assign(&c15_nameCaptureInfo, c15_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c15_nameCaptureInfo);
  return c15_nameCaptureInfo;
}

static const mxArray *c15_d_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_Final_Project_v3cInstanceStruct *chartInstance;
  chartInstance = (SFc15_Final_Project_v3cInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(int32_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, FALSE);
  return c15_mxArrayOutData;
}

static int32_T c15_d_emlrt_marshallIn(SFc15_Final_Project_v3cInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  int32_T c15_y;
  int32_T c15_i14;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_i14, 1, 6, 0U, 0, 0U, 0);
  c15_y = c15_i14;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_sfEvent;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  int32_T c15_y;
  SFc15_Final_Project_v3cInstanceStruct *chartInstance;
  chartInstance = (SFc15_Final_Project_v3cInstanceStruct *)chartInstanceVoid;
  c15_b_sfEvent = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_sfEvent),
    &c15_thisId);
  sf_mex_destroy(&c15_b_sfEvent);
  *(int32_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static uint8_T c15_e_emlrt_marshallIn(SFc15_Final_Project_v3cInstanceStruct
  *chartInstance, const mxArray *c15_b_is_active_c15_Final_Project_v3c, const
  char_T *c15_identifier)
{
  uint8_T c15_y;
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c15_b_is_active_c15_Final_Project_v3c), &c15_thisId);
  sf_mex_destroy(&c15_b_is_active_c15_Final_Project_v3c);
  return c15_y;
}

static uint8_T c15_f_emlrt_marshallIn(SFc15_Final_Project_v3cInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  uint8_T c15_y;
  uint8_T c15_u0;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_u0, 1, 3, 0U, 0, 0U, 0);
  c15_y = c15_u0;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void init_dsm_address_info(SFc15_Final_Project_v3cInstanceStruct
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

void sf_c15_Final_Project_v3c_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2633997542U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3470592191U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1806209860U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1591999735U);
}

mxArray *sf_c15_Final_Project_v3c_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("e60V2aNf9Df0MwIwxeDJLB");
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c15_Final_Project_v3c_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c15_Final_Project_v3c(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"state_3link\",},{M[8],M[0],T\"is_active_c15_Final_Project_v3c\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c15_Final_Project_v3c_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc15_Final_Project_v3cInstanceStruct *chartInstance;
    chartInstance = (SFc15_Final_Project_v3cInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Final_Project_v3cMachineNumber_,
           15,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"qqd");
          _SFD_SET_DATA_PROPS(1,2,0,1,"state_3link");
          _SFD_SET_DATA_PROPS(2,10,0,0,"lb");
          _SFD_SET_DATA_PROPS(3,10,0,0,"l");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1201);
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
            1.0,0,0,(MexFcnForType)c15_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)
            c15_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_b_sf_marshallOut,(MexInFcnForType)
          c15_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_b_sf_marshallOut,(MexInFcnForType)
          c15_b_sf_marshallIn);

        {
          real_T (*c15_qqd)[9];
          real_T (*c15_state_3link)[6];
          c15_state_3link = (real_T (*)[6])ssGetOutputPortSignal
            (chartInstance->S, 1);
          c15_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c15_qqd);
          _SFD_SET_DATA_VALUE_PTR(1U, *c15_state_3link);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c15_lb);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c15_l);
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
  return "MM66NkKECEwrlZVbIg79EF";
}

static void sf_opaque_initialize_c15_Final_Project_v3c(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc15_Final_Project_v3cInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c15_Final_Project_v3c((SFc15_Final_Project_v3cInstanceStruct*)
    chartInstanceVar);
  initialize_c15_Final_Project_v3c((SFc15_Final_Project_v3cInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c15_Final_Project_v3c(void *chartInstanceVar)
{
  enable_c15_Final_Project_v3c((SFc15_Final_Project_v3cInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c15_Final_Project_v3c(void *chartInstanceVar)
{
  disable_c15_Final_Project_v3c((SFc15_Final_Project_v3cInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c15_Final_Project_v3c(void *chartInstanceVar)
{
  sf_c15_Final_Project_v3c((SFc15_Final_Project_v3cInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c15_Final_Project_v3c(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c15_Final_Project_v3c
    ((SFc15_Final_Project_v3cInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c15_Final_Project_v3c();/* state var info */
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

extern void sf_internal_set_sim_state_c15_Final_Project_v3c(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c15_Final_Project_v3c();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c15_Final_Project_v3c((SFc15_Final_Project_v3cInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c15_Final_Project_v3c(SimStruct* S)
{
  return sf_internal_get_sim_state_c15_Final_Project_v3c(S);
}

static void sf_opaque_set_sim_state_c15_Final_Project_v3c(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c15_Final_Project_v3c(S, st);
}

static void sf_opaque_terminate_c15_Final_Project_v3c(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc15_Final_Project_v3cInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Final_Project_v3c_optimization_info();
    }

    finalize_c15_Final_Project_v3c((SFc15_Final_Project_v3cInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc15_Final_Project_v3c((SFc15_Final_Project_v3cInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c15_Final_Project_v3c(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c15_Final_Project_v3c
      ((SFc15_Final_Project_v3cInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c15_Final_Project_v3c(SimStruct *S)
{
  /* Actual parameters from chart:
     l lb
   */
  const char_T *rtParamNames[] = { "l", "lb" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for l*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for lb*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Final_Project_v3c_optimization_info();
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,15,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,15,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,15);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(576499673U));
  ssSetChecksum1(S,(1379106122U));
  ssSetChecksum2(S,(2183875695U));
  ssSetChecksum3(S,(949486780U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c15_Final_Project_v3c(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c15_Final_Project_v3c(SimStruct *S)
{
  SFc15_Final_Project_v3cInstanceStruct *chartInstance;
  chartInstance = (SFc15_Final_Project_v3cInstanceStruct *)utMalloc(sizeof
    (SFc15_Final_Project_v3cInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc15_Final_Project_v3cInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c15_Final_Project_v3c;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c15_Final_Project_v3c;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c15_Final_Project_v3c;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c15_Final_Project_v3c;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c15_Final_Project_v3c;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c15_Final_Project_v3c;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c15_Final_Project_v3c;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c15_Final_Project_v3c;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c15_Final_Project_v3c;
  chartInstance->chartInfo.mdlStart = mdlStart_c15_Final_Project_v3c;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c15_Final_Project_v3c;
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

void c15_Final_Project_v3c_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c15_Final_Project_v3c(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c15_Final_Project_v3c(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c15_Final_Project_v3c(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c15_Final_Project_v3c_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
