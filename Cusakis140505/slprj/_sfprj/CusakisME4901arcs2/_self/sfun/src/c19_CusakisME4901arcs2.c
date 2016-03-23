/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CusakisME4901arcs2_sfun.h"
#include "c19_CusakisME4901arcs2.h"
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
static const char * c19_debug_family_names[13] = { "theta1", "theta_dot1",
  "theta2", "theta_dot2", "theta3", "theta_dot3", "nargin", "nargout", "u", "m",
  "l", "w", "T" };

/* Function Declarations */
static void initialize_c19_CusakisME4901arcs2
  (SFc19_CusakisME4901arcs2InstanceStruct *chartInstance);
static void initialize_params_c19_CusakisME4901arcs2
  (SFc19_CusakisME4901arcs2InstanceStruct *chartInstance);
static void enable_c19_CusakisME4901arcs2(SFc19_CusakisME4901arcs2InstanceStruct
  *chartInstance);
static void disable_c19_CusakisME4901arcs2
  (SFc19_CusakisME4901arcs2InstanceStruct *chartInstance);
static void c19_update_debugger_state_c19_CusakisME4901arcs2
  (SFc19_CusakisME4901arcs2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c19_CusakisME4901arcs2
  (SFc19_CusakisME4901arcs2InstanceStruct *chartInstance);
static void set_sim_state_c19_CusakisME4901arcs2
  (SFc19_CusakisME4901arcs2InstanceStruct *chartInstance, const mxArray *c19_st);
static void finalize_c19_CusakisME4901arcs2
  (SFc19_CusakisME4901arcs2InstanceStruct *chartInstance);
static void sf_c19_CusakisME4901arcs2(SFc19_CusakisME4901arcs2InstanceStruct
  *chartInstance);
static void c19_chartstep_c19_CusakisME4901arcs2
  (SFc19_CusakisME4901arcs2InstanceStruct *chartInstance);
static void initSimStructsc19_CusakisME4901arcs2
  (SFc19_CusakisME4901arcs2InstanceStruct *chartInstance);
static void registerMessagesc19_CusakisME4901arcs2
  (SFc19_CusakisME4901arcs2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber);
static const mxArray *c19_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static real_T c19_emlrt_marshallIn(SFc19_CusakisME4901arcs2InstanceStruct
  *chartInstance, const mxArray *c19_T, const char_T *c19_identifier);
static real_T c19_b_emlrt_marshallIn(SFc19_CusakisME4901arcs2InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_b_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static void c19_info_helper(c19_ResolvedFunctionInfo c19_info[18]);
static real_T c19_power(SFc19_CusakisME4901arcs2InstanceStruct *chartInstance,
  real_T c19_a);
static void c19_eml_scalar_eg(SFc19_CusakisME4901arcs2InstanceStruct
  *chartInstance);
static const mxArray *c19_c_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static int32_T c19_c_emlrt_marshallIn(SFc19_CusakisME4901arcs2InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static uint8_T c19_d_emlrt_marshallIn(SFc19_CusakisME4901arcs2InstanceStruct
  *chartInstance, const mxArray *c19_b_is_active_c19_CusakisME4901arcs2, const
  char_T *c19_identifier);
static uint8_T c19_e_emlrt_marshallIn(SFc19_CusakisME4901arcs2InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void init_dsm_address_info(SFc19_CusakisME4901arcs2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c19_CusakisME4901arcs2
  (SFc19_CusakisME4901arcs2InstanceStruct *chartInstance)
{
  chartInstance->c19_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c19_is_active_c19_CusakisME4901arcs2 = 0U;
}

static void initialize_params_c19_CusakisME4901arcs2
  (SFc19_CusakisME4901arcs2InstanceStruct *chartInstance)
{
  real_T c19_d0;
  real_T c19_d1;
  real_T c19_d2;
  sf_set_error_prefix_string(
    "Error evaluating data 'm' in the parent workspace.\n");
  sf_mex_import_named("m", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c19_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c19_m = c19_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'l' in the parent workspace.\n");
  sf_mex_import_named("l", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c19_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c19_l = c19_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'w' in the parent workspace.\n");
  sf_mex_import_named("w", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      &c19_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c19_w = c19_d2;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c19_CusakisME4901arcs2(SFc19_CusakisME4901arcs2InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c19_CusakisME4901arcs2
  (SFc19_CusakisME4901arcs2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c19_update_debugger_state_c19_CusakisME4901arcs2
  (SFc19_CusakisME4901arcs2InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c19_CusakisME4901arcs2
  (SFc19_CusakisME4901arcs2InstanceStruct *chartInstance)
{
  const mxArray *c19_st;
  const mxArray *c19_y = NULL;
  real_T c19_hoistedGlobal;
  real_T c19_u;
  const mxArray *c19_b_y = NULL;
  uint8_T c19_b_hoistedGlobal;
  uint8_T c19_b_u;
  const mxArray *c19_c_y = NULL;
  real_T *c19_T;
  c19_T = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c19_st = NULL;
  c19_st = NULL;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_createcellarray(2), FALSE);
  c19_hoistedGlobal = *c19_T;
  c19_u = c19_hoistedGlobal;
  c19_b_y = NULL;
  sf_mex_assign(&c19_b_y, sf_mex_create("y", &c19_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c19_y, 0, c19_b_y);
  c19_b_hoistedGlobal = chartInstance->c19_is_active_c19_CusakisME4901arcs2;
  c19_b_u = c19_b_hoistedGlobal;
  c19_c_y = NULL;
  sf_mex_assign(&c19_c_y, sf_mex_create("y", &c19_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c19_y, 1, c19_c_y);
  sf_mex_assign(&c19_st, c19_y, FALSE);
  return c19_st;
}

static void set_sim_state_c19_CusakisME4901arcs2
  (SFc19_CusakisME4901arcs2InstanceStruct *chartInstance, const mxArray *c19_st)
{
  const mxArray *c19_u;
  real_T *c19_T;
  c19_T = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c19_doneDoubleBufferReInit = TRUE;
  c19_u = sf_mex_dup(c19_st);
  *c19_T = c19_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c19_u,
    0)), "T");
  chartInstance->c19_is_active_c19_CusakisME4901arcs2 = c19_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c19_u, 1)),
     "is_active_c19_CusakisME4901arcs2");
  sf_mex_destroy(&c19_u);
  c19_update_debugger_state_c19_CusakisME4901arcs2(chartInstance);
  sf_mex_destroy(&c19_st);
}

static void finalize_c19_CusakisME4901arcs2
  (SFc19_CusakisME4901arcs2InstanceStruct *chartInstance)
{
}

static void sf_c19_CusakisME4901arcs2(SFc19_CusakisME4901arcs2InstanceStruct
  *chartInstance)
{
  int32_T c19_i0;
  real_T *c19_T;
  real_T (*c19_u)[6];
  c19_u = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  c19_T = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 18U, chartInstance->c19_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c19_T, 0U);
  for (c19_i0 = 0; c19_i0 < 6; c19_i0++) {
    _SFD_DATA_RANGE_CHECK((*c19_u)[c19_i0], 1U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c19_m, 2U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c19_l, 3U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c19_w, 4U);
  chartInstance->c19_sfEvent = CALL_EVENT;
  c19_chartstep_c19_CusakisME4901arcs2(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CusakisME4901arcs2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c19_chartstep_c19_CusakisME4901arcs2
  (SFc19_CusakisME4901arcs2InstanceStruct *chartInstance)
{
  real_T c19_hoistedGlobal;
  real_T c19_b_hoistedGlobal;
  real_T c19_c_hoistedGlobal;
  int32_T c19_i1;
  real_T c19_u[6];
  real_T c19_b_m;
  real_T c19_b_l;
  real_T c19_b_w;
  uint32_T c19_debug_family_var_map[13];
  real_T c19_theta1;
  real_T c19_theta_dot1;
  real_T c19_theta2;
  real_T c19_theta_dot2;
  real_T c19_theta3;
  real_T c19_theta_dot3;
  real_T c19_nargin = 4.0;
  real_T c19_nargout = 1.0;
  real_T c19_T;
  real_T c19_a;
  real_T c19_b;
  real_T c19_y;
  real_T c19_x;
  real_T c19_b_x;
  real_T c19_b_a;
  real_T c19_b_b;
  real_T c19_b_y;
  real_T c19_c_x;
  real_T c19_d_x;
  real_T c19_c_a;
  real_T c19_c_b;
  real_T c19_c_y;
  real_T c19_e_x;
  real_T c19_f_x;
  real_T c19_A;
  real_T c19_g_x;
  real_T c19_h_x;
  real_T c19_d_y;
  real_T c19_d_a;
  real_T c19_d_b;
  real_T c19_e_y;
  real_T c19_i_x;
  real_T c19_j_x;
  real_T c19_e_a;
  real_T c19_e_b;
  real_T c19_f_y;
  real_T c19_k_x;
  real_T c19_l_x;
  real_T c19_f_a;
  real_T c19_f_b;
  real_T c19_g_y;
  real_T c19_m_x;
  real_T c19_n_x;
  real_T c19_b_A;
  real_T c19_o_x;
  real_T c19_p_x;
  real_T c19_h_y;
  real_T c19_g_a;
  real_T c19_g_b;
  real_T c19_i_y;
  real_T c19_c_A;
  real_T c19_q_x;
  real_T c19_r_x;
  real_T c19_j_y;
  real_T c19_h_a;
  real_T c19_h_b;
  real_T c19_k_y;
  real_T c19_s_x;
  real_T c19_t_x;
  real_T c19_i_a;
  real_T c19_i_b;
  real_T c19_l_y;
  real_T c19_u_x;
  real_T c19_v_x;
  real_T c19_d_A;
  real_T c19_w_x;
  real_T c19_x_x;
  real_T c19_m_y;
  real_T c19_j_a;
  real_T c19_j_b;
  real_T c19_n_y;
  real_T c19_y_x;
  real_T c19_ab_x;
  real_T c19_k_a;
  real_T c19_k_b;
  real_T c19_o_y;
  real_T c19_bb_x;
  real_T c19_cb_x;
  real_T c19_e_A;
  real_T c19_db_x;
  real_T c19_eb_x;
  real_T c19_p_y;
  real_T c19_l_a;
  real_T c19_l_b;
  real_T c19_q_y;
  real_T c19_f_A;
  real_T c19_fb_x;
  real_T c19_gb_x;
  real_T c19_r_y;
  real_T c19_m_a;
  real_T c19_c;
  real_T c19_n_a;
  real_T c19_m_b;
  real_T c19_s_y;
  real_T c19_o_a;
  real_T c19_n_b;
  real_T c19_t_y;
  real_T c19_g_A;
  real_T c19_hb_x;
  real_T c19_ib_x;
  real_T c19_u_y;
  real_T c19_p_a;
  real_T c19_o_b;
  real_T c19_v_y;
  real_T c19_q_a;
  real_T c19_b_c;
  real_T c19_r_a;
  real_T c19_c_c;
  real_T c19_s_a;
  real_T c19_p_b;
  real_T c19_w_y;
  real_T c19_h_A;
  real_T c19_jb_x;
  real_T c19_kb_x;
  real_T c19_x_y;
  real_T c19_t_a;
  real_T c19_q_b;
  real_T c19_y_y;
  real_T c19_u_a;
  real_T c19_d_c;
  real_T c19_v_a;
  real_T c19_e_c;
  real_T c19_w_a;
  real_T c19_r_b;
  real_T c19_ab_y;
  real_T c19_i_A;
  real_T c19_lb_x;
  real_T c19_mb_x;
  real_T c19_bb_y;
  real_T c19_x_a;
  real_T c19_s_b;
  real_T c19_cb_y;
  real_T c19_y_a;
  real_T c19_f_c;
  real_T c19_ab_a;
  real_T c19_g_c;
  real_T c19_bb_a;
  real_T c19_t_b;
  real_T c19_db_y;
  real_T c19_j_A;
  real_T c19_nb_x;
  real_T c19_ob_x;
  real_T c19_eb_y;
  real_T *c19_b_T;
  real_T (*c19_b_u)[6];
  c19_b_u = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  c19_b_T = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 18U, chartInstance->c19_sfEvent);
  c19_hoistedGlobal = chartInstance->c19_m;
  c19_b_hoistedGlobal = chartInstance->c19_l;
  c19_c_hoistedGlobal = chartInstance->c19_w;
  for (c19_i1 = 0; c19_i1 < 6; c19_i1++) {
    c19_u[c19_i1] = (*c19_b_u)[c19_i1];
  }

  c19_b_m = c19_hoistedGlobal;
  c19_b_l = c19_b_hoistedGlobal;
  c19_b_w = c19_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c19_debug_family_names,
    c19_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_theta1, 0U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_theta_dot1, 1U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_theta2, 2U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_theta_dot2, 3U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_theta3, 4U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_theta_dot3, 5U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_nargin, 6U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_nargout, 7U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c19_u, 8U, c19_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_b_m, 9U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_b_l, 10U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_b_w, 11U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c19_T, 12U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 5);
  c19_theta1 = c19_u[0];
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 6);
  c19_theta_dot1 = c19_u[1];
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 7);
  c19_theta2 = c19_theta1 + c19_u[2];
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 8);
  c19_theta_dot2 = c19_theta_dot1 + c19_u[3];
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 9);
  c19_theta3 = c19_theta2 + c19_u[4];
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 10);
  c19_theta_dot3 = c19_theta_dot2 + c19_u[5];
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 17);
  c19_a = c19_theta_dot1;
  c19_b = c19_b_l;
  c19_y = c19_a * c19_b;
  c19_x = c19_theta1;
  c19_b_x = c19_x;
  c19_b_x = muDoubleScalarSin(c19_b_x);
  c19_b_a = c19_theta_dot2;
  c19_b_b = c19_b_l;
  c19_b_y = c19_b_a * c19_b_b;
  c19_c_x = c19_theta2;
  c19_d_x = c19_c_x;
  c19_d_x = muDoubleScalarSin(c19_d_x);
  c19_c_a = c19_theta_dot3;
  c19_c_b = c19_b_l;
  c19_c_y = c19_c_a * c19_c_b;
  c19_e_x = c19_theta3;
  c19_f_x = c19_e_x;
  c19_f_x = muDoubleScalarSin(c19_f_x);
  c19_A = c19_c_y * c19_f_x;
  c19_g_x = c19_A;
  c19_h_x = c19_g_x;
  c19_d_y = c19_h_x / 2.0;
  c19_d_a = c19_theta_dot1;
  c19_d_b = c19_b_l;
  c19_e_y = c19_d_a * c19_d_b;
  c19_i_x = c19_theta1;
  c19_j_x = c19_i_x;
  c19_j_x = muDoubleScalarCos(c19_j_x);
  c19_e_a = c19_theta_dot2;
  c19_e_b = c19_b_l;
  c19_f_y = c19_e_a * c19_e_b;
  c19_k_x = c19_theta2;
  c19_l_x = c19_k_x;
  c19_l_x = muDoubleScalarCos(c19_l_x);
  c19_f_a = c19_theta_dot3;
  c19_f_b = c19_b_l;
  c19_g_y = c19_f_a * c19_f_b;
  c19_m_x = c19_theta3;
  c19_n_x = c19_m_x;
  c19_n_x = muDoubleScalarCos(c19_n_x);
  c19_b_A = c19_g_y * c19_n_x;
  c19_o_x = c19_b_A;
  c19_p_x = c19_o_x;
  c19_h_y = c19_p_x / 2.0;
  c19_g_a = c19_b_m;
  c19_g_b = c19_power(chartInstance, (c19_y * c19_b_x + c19_b_y * c19_d_x) +
                      c19_d_y) + c19_power(chartInstance, (c19_e_y * c19_j_x +
    c19_f_y * c19_l_x) + c19_h_y);
  c19_i_y = c19_g_a * c19_g_b;
  c19_c_A = c19_i_y;
  c19_q_x = c19_c_A;
  c19_r_x = c19_q_x;
  c19_j_y = c19_r_x / 2.0;
  c19_h_a = c19_theta_dot1;
  c19_h_b = c19_b_l;
  c19_k_y = c19_h_a * c19_h_b;
  c19_s_x = c19_theta1;
  c19_t_x = c19_s_x;
  c19_t_x = muDoubleScalarCos(c19_t_x);
  c19_i_a = c19_theta_dot2;
  c19_i_b = c19_b_l;
  c19_l_y = c19_i_a * c19_i_b;
  c19_u_x = c19_theta2;
  c19_v_x = c19_u_x;
  c19_v_x = muDoubleScalarCos(c19_v_x);
  c19_d_A = c19_l_y * c19_v_x;
  c19_w_x = c19_d_A;
  c19_x_x = c19_w_x;
  c19_m_y = c19_x_x / 2.0;
  c19_j_a = c19_theta_dot1;
  c19_j_b = c19_b_l;
  c19_n_y = c19_j_a * c19_j_b;
  c19_y_x = c19_theta1;
  c19_ab_x = c19_y_x;
  c19_ab_x = muDoubleScalarSin(c19_ab_x);
  c19_k_a = c19_theta_dot2;
  c19_k_b = c19_b_l;
  c19_o_y = c19_k_a * c19_k_b;
  c19_bb_x = c19_theta2;
  c19_cb_x = c19_bb_x;
  c19_cb_x = muDoubleScalarSin(c19_cb_x);
  c19_e_A = c19_o_y * c19_cb_x;
  c19_db_x = c19_e_A;
  c19_eb_x = c19_db_x;
  c19_p_y = c19_eb_x / 2.0;
  c19_l_a = c19_b_m;
  c19_l_b = c19_power(chartInstance, c19_k_y * c19_t_x + c19_m_y) + c19_power
    (chartInstance, c19_n_y * c19_ab_x + c19_p_y);
  c19_q_y = c19_l_a * c19_l_b;
  c19_f_A = c19_q_y;
  c19_fb_x = c19_f_A;
  c19_gb_x = c19_fb_x;
  c19_r_y = c19_gb_x / 2.0;
  c19_m_a = c19_b_l;
  c19_c = c19_power(chartInstance, c19_m_a);
  c19_n_a = c19_power(chartInstance, c19_theta_dot1);
  c19_m_b = c19_c;
  c19_s_y = c19_n_a * c19_m_b;
  c19_o_a = c19_s_y;
  c19_n_b = c19_b_m;
  c19_t_y = c19_o_a * c19_n_b;
  c19_g_A = c19_t_y;
  c19_hb_x = c19_g_A;
  c19_ib_x = c19_hb_x;
  c19_u_y = c19_ib_x / 8.0;
  c19_p_a = c19_power(chartInstance, c19_theta_dot1);
  c19_o_b = c19_b_m;
  c19_v_y = c19_p_a * c19_o_b;
  c19_q_a = c19_b_l;
  c19_b_c = c19_power(chartInstance, c19_q_a);
  c19_r_a = c19_b_w;
  c19_c_c = c19_power(chartInstance, c19_r_a);
  c19_s_a = c19_v_y;
  c19_p_b = c19_b_c + c19_c_c;
  c19_w_y = c19_s_a * c19_p_b;
  c19_h_A = c19_w_y;
  c19_jb_x = c19_h_A;
  c19_kb_x = c19_jb_x;
  c19_x_y = c19_kb_x / 24.0;
  c19_t_a = c19_power(chartInstance, c19_theta_dot2);
  c19_q_b = c19_b_m;
  c19_y_y = c19_t_a * c19_q_b;
  c19_u_a = c19_b_l;
  c19_d_c = c19_power(chartInstance, c19_u_a);
  c19_v_a = c19_b_w;
  c19_e_c = c19_power(chartInstance, c19_v_a);
  c19_w_a = c19_y_y;
  c19_r_b = c19_d_c + c19_e_c;
  c19_ab_y = c19_w_a * c19_r_b;
  c19_i_A = c19_ab_y;
  c19_lb_x = c19_i_A;
  c19_mb_x = c19_lb_x;
  c19_bb_y = c19_mb_x / 24.0;
  c19_x_a = c19_power(chartInstance, c19_theta_dot3);
  c19_s_b = c19_b_m;
  c19_cb_y = c19_x_a * c19_s_b;
  c19_y_a = c19_b_l;
  c19_f_c = c19_power(chartInstance, c19_y_a);
  c19_ab_a = c19_b_w;
  c19_g_c = c19_power(chartInstance, c19_ab_a);
  c19_bb_a = c19_cb_y;
  c19_t_b = c19_f_c + c19_g_c;
  c19_db_y = c19_bb_a * c19_t_b;
  c19_j_A = c19_db_y;
  c19_nb_x = c19_j_A;
  c19_ob_x = c19_nb_x;
  c19_eb_y = c19_ob_x / 24.0;
  c19_T = ((((c19_j_y + c19_r_y) + c19_u_y) + c19_x_y) + c19_bb_y) + c19_eb_y;
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, -17);
  _SFD_SYMBOL_SCOPE_POP();
  *c19_b_T = c19_T;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c19_sfEvent);
}

static void initSimStructsc19_CusakisME4901arcs2
  (SFc19_CusakisME4901arcs2InstanceStruct *chartInstance)
{
}

static void registerMessagesc19_CusakisME4901arcs2
  (SFc19_CusakisME4901arcs2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber)
{
}

static const mxArray *c19_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  real_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_CusakisME4901arcs2InstanceStruct *chartInstance;
  chartInstance = (SFc19_CusakisME4901arcs2InstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(real_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, FALSE);
  return c19_mxArrayOutData;
}

static real_T c19_emlrt_marshallIn(SFc19_CusakisME4901arcs2InstanceStruct
  *chartInstance, const mxArray *c19_T, const char_T *c19_identifier)
{
  real_T c19_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_T), &c19_thisId);
  sf_mex_destroy(&c19_T);
  return c19_y;
}

static real_T c19_b_emlrt_marshallIn(SFc19_CusakisME4901arcs2InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  real_T c19_y;
  real_T c19_d3;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_d3, 1, 0, 0U, 0, 0U, 0);
  c19_y = c19_d3;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_T;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_y;
  SFc19_CusakisME4901arcs2InstanceStruct *chartInstance;
  chartInstance = (SFc19_CusakisME4901arcs2InstanceStruct *)chartInstanceVoid;
  c19_T = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_T), &c19_thisId);
  sf_mex_destroy(&c19_T);
  *(real_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_b_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_i2;
  real_T c19_b_inData[6];
  int32_T c19_i3;
  real_T c19_u[6];
  const mxArray *c19_y = NULL;
  SFc19_CusakisME4901arcs2InstanceStruct *chartInstance;
  chartInstance = (SFc19_CusakisME4901arcs2InstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  for (c19_i2 = 0; c19_i2 < 6; c19_i2++) {
    c19_b_inData[c19_i2] = (*(real_T (*)[6])c19_inData)[c19_i2];
  }

  for (c19_i3 = 0; c19_i3 < 6; c19_i3++) {
    c19_u[c19_i3] = c19_b_inData[c19_i3];
  }

  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", c19_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, FALSE);
  return c19_mxArrayOutData;
}

const mxArray *sf_c19_CusakisME4901arcs2_get_eml_resolved_functions_info(void)
{
  const mxArray *c19_nameCaptureInfo;
  c19_ResolvedFunctionInfo c19_info[18];
  const mxArray *c19_m0 = NULL;
  int32_T c19_i4;
  c19_ResolvedFunctionInfo *c19_r0;
  c19_nameCaptureInfo = NULL;
  c19_nameCaptureInfo = NULL;
  c19_info_helper(c19_info);
  sf_mex_assign(&c19_m0, sf_mex_createstruct("nameCaptureInfo", 1, 18), FALSE);
  for (c19_i4 = 0; c19_i4 < 18; c19_i4++) {
    c19_r0 = &c19_info[c19_i4];
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", c19_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c19_r0->context)), "context", "nameCaptureInfo",
                    c19_i4);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", c19_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c19_r0->name)), "name", "nameCaptureInfo", c19_i4);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo",
      c19_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c19_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c19_i4);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", c19_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c19_r0->resolved)), "resolved",
                    "nameCaptureInfo", c19_i4);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", &c19_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c19_i4);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", &c19_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c19_i4);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo",
      &c19_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c19_i4);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo",
      &c19_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c19_i4);
  }

  sf_mex_assign(&c19_nameCaptureInfo, c19_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c19_nameCaptureInfo);
  return c19_nameCaptureInfo;
}

static void c19_info_helper(c19_ResolvedFunctionInfo c19_info[18])
{
  c19_info[0].context = "";
  c19_info[0].name = "mtimes";
  c19_info[0].dominantType = "double";
  c19_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c19_info[0].fileTimeLo = 1289552092U;
  c19_info[0].fileTimeHi = 0U;
  c19_info[0].mFileTimeLo = 0U;
  c19_info[0].mFileTimeHi = 0U;
  c19_info[1].context = "";
  c19_info[1].name = "sin";
  c19_info[1].dominantType = "double";
  c19_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c19_info[1].fileTimeLo = 1343862786U;
  c19_info[1].fileTimeHi = 0U;
  c19_info[1].mFileTimeLo = 0U;
  c19_info[1].mFileTimeHi = 0U;
  c19_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c19_info[2].name = "eml_scalar_sin";
  c19_info[2].dominantType = "double";
  c19_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c19_info[2].fileTimeLo = 1286851136U;
  c19_info[2].fileTimeHi = 0U;
  c19_info[2].mFileTimeLo = 0U;
  c19_info[2].mFileTimeHi = 0U;
  c19_info[3].context = "";
  c19_info[3].name = "mrdivide";
  c19_info[3].dominantType = "double";
  c19_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c19_info[3].fileTimeLo = 1357983948U;
  c19_info[3].fileTimeHi = 0U;
  c19_info[3].mFileTimeLo = 1319762366U;
  c19_info[3].mFileTimeHi = 0U;
  c19_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c19_info[4].name = "rdivide";
  c19_info[4].dominantType = "double";
  c19_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c19_info[4].fileTimeLo = 1346542788U;
  c19_info[4].fileTimeHi = 0U;
  c19_info[4].mFileTimeLo = 0U;
  c19_info[4].mFileTimeHi = 0U;
  c19_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c19_info[5].name = "eml_scalexp_compatible";
  c19_info[5].dominantType = "double";
  c19_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c19_info[5].fileTimeLo = 1286851196U;
  c19_info[5].fileTimeHi = 0U;
  c19_info[5].mFileTimeLo = 0U;
  c19_info[5].mFileTimeHi = 0U;
  c19_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c19_info[6].name = "eml_div";
  c19_info[6].dominantType = "double";
  c19_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c19_info[6].fileTimeLo = 1313380210U;
  c19_info[6].fileTimeHi = 0U;
  c19_info[6].mFileTimeLo = 0U;
  c19_info[6].mFileTimeHi = 0U;
  c19_info[7].context = "";
  c19_info[7].name = "power";
  c19_info[7].dominantType = "double";
  c19_info[7].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c19_info[7].fileTimeLo = 1348224330U;
  c19_info[7].fileTimeHi = 0U;
  c19_info[7].mFileTimeLo = 0U;
  c19_info[7].mFileTimeHi = 0U;
  c19_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c19_info[8].name = "eml_scalar_eg";
  c19_info[8].dominantType = "double";
  c19_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c19_info[8].fileTimeLo = 1286851196U;
  c19_info[8].fileTimeHi = 0U;
  c19_info[8].mFileTimeLo = 0U;
  c19_info[8].mFileTimeHi = 0U;
  c19_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c19_info[9].name = "eml_scalexp_alloc";
  c19_info[9].dominantType = "double";
  c19_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c19_info[9].fileTimeLo = 1352457260U;
  c19_info[9].fileTimeHi = 0U;
  c19_info[9].mFileTimeLo = 0U;
  c19_info[9].mFileTimeHi = 0U;
  c19_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c19_info[10].name = "floor";
  c19_info[10].dominantType = "double";
  c19_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c19_info[10].fileTimeLo = 1343862780U;
  c19_info[10].fileTimeHi = 0U;
  c19_info[10].mFileTimeLo = 0U;
  c19_info[10].mFileTimeHi = 0U;
  c19_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c19_info[11].name = "eml_scalar_floor";
  c19_info[11].dominantType = "double";
  c19_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c19_info[11].fileTimeLo = 1286851126U;
  c19_info[11].fileTimeHi = 0U;
  c19_info[11].mFileTimeLo = 0U;
  c19_info[11].mFileTimeHi = 0U;
  c19_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c19_info[12].name = "eml_scalar_eg";
  c19_info[12].dominantType = "double";
  c19_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c19_info[12].fileTimeLo = 1286851196U;
  c19_info[12].fileTimeHi = 0U;
  c19_info[12].mFileTimeLo = 0U;
  c19_info[12].mFileTimeHi = 0U;
  c19_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c19_info[13].name = "mtimes";
  c19_info[13].dominantType = "double";
  c19_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c19_info[13].fileTimeLo = 1289552092U;
  c19_info[13].fileTimeHi = 0U;
  c19_info[13].mFileTimeLo = 0U;
  c19_info[13].mFileTimeHi = 0U;
  c19_info[14].context = "";
  c19_info[14].name = "cos";
  c19_info[14].dominantType = "double";
  c19_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c19_info[14].fileTimeLo = 1343862772U;
  c19_info[14].fileTimeHi = 0U;
  c19_info[14].mFileTimeLo = 0U;
  c19_info[14].mFileTimeHi = 0U;
  c19_info[15].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c19_info[15].name = "eml_scalar_cos";
  c19_info[15].dominantType = "double";
  c19_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c19_info[15].fileTimeLo = 1286851122U;
  c19_info[15].fileTimeHi = 0U;
  c19_info[15].mFileTimeLo = 0U;
  c19_info[15].mFileTimeHi = 0U;
  c19_info[16].context = "";
  c19_info[16].name = "mpower";
  c19_info[16].dominantType = "double";
  c19_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c19_info[16].fileTimeLo = 1286851242U;
  c19_info[16].fileTimeHi = 0U;
  c19_info[16].mFileTimeLo = 0U;
  c19_info[16].mFileTimeHi = 0U;
  c19_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c19_info[17].name = "power";
  c19_info[17].dominantType = "double";
  c19_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c19_info[17].fileTimeLo = 1348224330U;
  c19_info[17].fileTimeHi = 0U;
  c19_info[17].mFileTimeLo = 0U;
  c19_info[17].mFileTimeHi = 0U;
}

static real_T c19_power(SFc19_CusakisME4901arcs2InstanceStruct *chartInstance,
  real_T c19_a)
{
  real_T c19_b_a;
  real_T c19_ak;
  real_T c19_c_a;
  real_T c19_d_a;
  real_T c19_b;
  c19_b_a = c19_a;
  c19_eml_scalar_eg(chartInstance);
  c19_ak = c19_b_a;
  c19_c_a = c19_ak;
  c19_eml_scalar_eg(chartInstance);
  c19_d_a = c19_c_a;
  c19_b = c19_c_a;
  return c19_d_a * c19_b;
}

static void c19_eml_scalar_eg(SFc19_CusakisME4901arcs2InstanceStruct
  *chartInstance)
{
}

static const mxArray *c19_c_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_CusakisME4901arcs2InstanceStruct *chartInstance;
  chartInstance = (SFc19_CusakisME4901arcs2InstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(int32_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, FALSE);
  return c19_mxArrayOutData;
}

static int32_T c19_c_emlrt_marshallIn(SFc19_CusakisME4901arcs2InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  int32_T c19_y;
  int32_T c19_i5;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_i5, 1, 6, 0U, 0, 0U, 0);
  c19_y = c19_i5;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_b_sfEvent;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  int32_T c19_y;
  SFc19_CusakisME4901arcs2InstanceStruct *chartInstance;
  chartInstance = (SFc19_CusakisME4901arcs2InstanceStruct *)chartInstanceVoid;
  c19_b_sfEvent = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_sfEvent),
    &c19_thisId);
  sf_mex_destroy(&c19_b_sfEvent);
  *(int32_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static uint8_T c19_d_emlrt_marshallIn(SFc19_CusakisME4901arcs2InstanceStruct
  *chartInstance, const mxArray *c19_b_is_active_c19_CusakisME4901arcs2, const
  char_T *c19_identifier)
{
  uint8_T c19_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c19_b_is_active_c19_CusakisME4901arcs2), &c19_thisId);
  sf_mex_destroy(&c19_b_is_active_c19_CusakisME4901arcs2);
  return c19_y;
}

static uint8_T c19_e_emlrt_marshallIn(SFc19_CusakisME4901arcs2InstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  uint8_T c19_y;
  uint8_T c19_u0;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_u0, 1, 3, 0U, 0, 0U, 0);
  c19_y = c19_u0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void init_dsm_address_info(SFc19_CusakisME4901arcs2InstanceStruct
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

void sf_c19_CusakisME4901arcs2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2006944913U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2910473162U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1207884516U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(295805465U);
}

mxArray *sf_c19_CusakisME4901arcs2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("uncRnkF2Sy8qoHgaK4jhp");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c19_CusakisME4901arcs2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c19_CusakisME4901arcs2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[6],T\"T\",},{M[8],M[0],T\"is_active_c19_CusakisME4901arcs2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c19_CusakisME4901arcs2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc19_CusakisME4901arcs2InstanceStruct *chartInstance;
    chartInstance = (SFc19_CusakisME4901arcs2InstanceStruct *) ((ChartInfoStruct
      *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CusakisME4901arcs2MachineNumber_,
           19,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"T");
          _SFD_SET_DATA_PROPS(1,1,1,0,"u");
          _SFD_SET_DATA_PROPS(2,10,0,0,"m");
          _SFD_SET_DATA_PROPS(3,10,0,0,"l");
          _SFD_SET_DATA_PROPS(4,10,0,0,"w");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,669);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_sf_marshallOut,(MexInFcnForType)c19_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c19_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_sf_marshallOut,(MexInFcnForType)c19_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_sf_marshallOut,(MexInFcnForType)c19_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_sf_marshallOut,(MexInFcnForType)c19_sf_marshallIn);

        {
          real_T *c19_T;
          real_T (*c19_u)[6];
          c19_u = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          c19_T = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c19_T);
          _SFD_SET_DATA_VALUE_PTR(1U, *c19_u);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c19_m);
          _SFD_SET_DATA_VALUE_PTR(3U, &chartInstance->c19_l);
          _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c19_w);
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
  return "cfeE0qk8FWVP67gG6zbr5B";
}

static void sf_opaque_initialize_c19_CusakisME4901arcs2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc19_CusakisME4901arcs2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c19_CusakisME4901arcs2
    ((SFc19_CusakisME4901arcs2InstanceStruct*) chartInstanceVar);
  initialize_c19_CusakisME4901arcs2((SFc19_CusakisME4901arcs2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c19_CusakisME4901arcs2(void *chartInstanceVar)
{
  enable_c19_CusakisME4901arcs2((SFc19_CusakisME4901arcs2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c19_CusakisME4901arcs2(void *chartInstanceVar)
{
  disable_c19_CusakisME4901arcs2((SFc19_CusakisME4901arcs2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c19_CusakisME4901arcs2(void *chartInstanceVar)
{
  sf_c19_CusakisME4901arcs2((SFc19_CusakisME4901arcs2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c19_CusakisME4901arcs2(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c19_CusakisME4901arcs2
    ((SFc19_CusakisME4901arcs2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c19_CusakisME4901arcs2();/* state var info */
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

extern void sf_internal_set_sim_state_c19_CusakisME4901arcs2(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c19_CusakisME4901arcs2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c19_CusakisME4901arcs2((SFc19_CusakisME4901arcs2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c19_CusakisME4901arcs2(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c19_CusakisME4901arcs2(S);
}

static void sf_opaque_set_sim_state_c19_CusakisME4901arcs2(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c19_CusakisME4901arcs2(S, st);
}

static void sf_opaque_terminate_c19_CusakisME4901arcs2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc19_CusakisME4901arcs2InstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CusakisME4901arcs2_optimization_info();
    }

    finalize_c19_CusakisME4901arcs2((SFc19_CusakisME4901arcs2InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc19_CusakisME4901arcs2((SFc19_CusakisME4901arcs2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c19_CusakisME4901arcs2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c19_CusakisME4901arcs2
      ((SFc19_CusakisME4901arcs2InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c19_CusakisME4901arcs2(SimStruct *S)
{
  /* Actual parameters from chart:
     l m w
   */
  const char_T *rtParamNames[] = { "l", "m", "w" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for l*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for m*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for w*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CusakisME4901arcs2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      19);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,19,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,19,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,19);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,19,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,19,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,19);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3375404467U));
  ssSetChecksum1(S,(2814116937U));
  ssSetChecksum2(S,(1497506832U));
  ssSetChecksum3(S,(483389757U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c19_CusakisME4901arcs2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c19_CusakisME4901arcs2(SimStruct *S)
{
  SFc19_CusakisME4901arcs2InstanceStruct *chartInstance;
  chartInstance = (SFc19_CusakisME4901arcs2InstanceStruct *)utMalloc(sizeof
    (SFc19_CusakisME4901arcs2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc19_CusakisME4901arcs2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c19_CusakisME4901arcs2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c19_CusakisME4901arcs2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c19_CusakisME4901arcs2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c19_CusakisME4901arcs2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c19_CusakisME4901arcs2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c19_CusakisME4901arcs2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c19_CusakisME4901arcs2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c19_CusakisME4901arcs2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c19_CusakisME4901arcs2;
  chartInstance->chartInfo.mdlStart = mdlStart_c19_CusakisME4901arcs2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c19_CusakisME4901arcs2;
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

void c19_CusakisME4901arcs2_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c19_CusakisME4901arcs2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c19_CusakisME4901arcs2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c19_CusakisME4901arcs2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c19_CusakisME4901arcs2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
