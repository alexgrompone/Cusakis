/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Final_Project_v3b_sfun.h"
#include "c7_Final_Project_v3b.h"
#include <math.h>
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Final_Project_v3b_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c7_debug_family_names[9] = { "q", "Ja", "Ra", "Sa", "nargin",
  "nargout", "qqd", "l", "Ya" };

/* Function Declarations */
static void initialize_c7_Final_Project_v3b(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance);
static void initialize_params_c7_Final_Project_v3b
  (SFc7_Final_Project_v3bInstanceStruct *chartInstance);
static void enable_c7_Final_Project_v3b(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance);
static void disable_c7_Final_Project_v3b(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance);
static void c7_update_debugger_state_c7_Final_Project_v3b
  (SFc7_Final_Project_v3bInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c7_Final_Project_v3b
  (SFc7_Final_Project_v3bInstanceStruct *chartInstance);
static void set_sim_state_c7_Final_Project_v3b
  (SFc7_Final_Project_v3bInstanceStruct *chartInstance, const mxArray *c7_st);
static void finalize_c7_Final_Project_v3b(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance);
static void sf_c7_Final_Project_v3b(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance);
static void initSimStructsc7_Final_Project_v3b
  (SFc7_Final_Project_v3bInstanceStruct *chartInstance);
static void registerMessagesc7_Final_Project_v3b
  (SFc7_Final_Project_v3bInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData);
static real_T c7_emlrt_marshallIn(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance, const mxArray *c7_Ya, const char_T *c7_identifier);
static real_T c7_b_emlrt_marshallIn(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static void c7_c_emlrt_marshallIn(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_y[2]);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static void c7_d_emlrt_marshallIn(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_y[6]);
static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_e_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static void c7_e_emlrt_marshallIn(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_y[3]);
static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static void c7_info_helper(c7_ResolvedFunctionInfo c7_info[134]);
static void c7_b_info_helper(c7_ResolvedFunctionInfo c7_info[134]);
static void c7_c_info_helper(c7_ResolvedFunctionInfo c7_info[134]);
static real_T c7_rank(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
                      real_T c7_A[6]);
static void c7_eml_error(SFc7_Final_Project_v3bInstanceStruct *chartInstance);
static void c7_eml_matlab_zsvdc(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance, real_T c7_A[6], real_T c7_S[2]);
static void c7_eml_scalar_eg(SFc7_Final_Project_v3bInstanceStruct *chartInstance);
static real_T c7_eml_xnrm2(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_x[6]);
static void c7_realmin(SFc7_Final_Project_v3bInstanceStruct *chartInstance);
static void c7_eml_realmin(SFc7_Final_Project_v3bInstanceStruct *chartInstance);
static real_T c7_abs(SFc7_Final_Project_v3bInstanceStruct *chartInstance, real_T
                     c7_x);
static real_T c7_eml_div(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_x, real_T c7_y);
static void c7_eml_xscal(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_a, real_T c7_x[6], real_T c7_b_x[6]);
static real_T c7_eml_xdotc(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_x[6], real_T c7_y[6], int32_T c7_iy0);
static void c7_eml_xaxpy(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_a, real_T c7_y[6], int32_T c7_iy0, real_T c7_b_y[6]);
static real_T c7_b_eml_xnrm2(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_x[3]);
static void c7_b_eml_xscal(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_a, real_T c7_x[3], real_T c7_b_x[3]);
static void c7_b_eml_xaxpy(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_a, real_T c7_x[6], int32_T c7_ix0, real_T c7_y[2], real_T c7_b_y[2]);
static void c7_c_eml_xaxpy(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_a, real_T c7_x[2], real_T c7_y[6], int32_T c7_iy0, real_T c7_b_y[6]);
static void c7_eps(SFc7_Final_Project_v3bInstanceStruct *chartInstance);
static void c7_b_eml_scalar_eg(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance);
static void c7_b_eml_error(SFc7_Final_Project_v3bInstanceStruct *chartInstance);
static void c7_check_forloop_overflow_error(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance, boolean_T c7_overflow);
static void c7_b_check_forloop_overflow_error
  (SFc7_Final_Project_v3bInstanceStruct *chartInstance, boolean_T c7_overflow);
static real_T c7_sqrt(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
                      real_T c7_x);
static void c7_c_eml_error(SFc7_Final_Project_v3bInstanceStruct *chartInstance);
static void c7_eml_xrotg(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_a, real_T c7_b, real_T *c7_b_a, real_T *c7_b_b, real_T *c7_c, real_T
  *c7_s);
static const mxArray *c7_f_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int32_T c7_f_emlrt_marshallIn(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static uint8_T c7_g_emlrt_marshallIn(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance, const mxArray *c7_b_is_active_c7_Final_Project_v3b, const
  char_T *c7_identifier);
static uint8_T c7_h_emlrt_marshallIn(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_c_eml_xscal(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_a, real_T c7_x[6]);
static void c7_d_eml_xaxpy(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_a, real_T c7_y[6], int32_T c7_iy0);
static void c7_d_eml_xscal(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_a, real_T c7_x[3]);
static void c7_e_eml_xaxpy(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_a, real_T c7_x[6], int32_T c7_ix0, real_T c7_y[2]);
static void c7_f_eml_xaxpy(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_a, real_T c7_x[2], real_T c7_y[6], int32_T c7_iy0);
static void c7_b_sqrt(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
                      real_T *c7_x);
static void c7_b_eml_xrotg(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T *c7_a, real_T *c7_b, real_T *c7_c, real_T *c7_s);
static void init_dsm_address_info(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c7_Final_Project_v3b(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance)
{
  chartInstance->c7_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c7_is_active_c7_Final_Project_v3b = 0U;
}

static void initialize_params_c7_Final_Project_v3b
  (SFc7_Final_Project_v3bInstanceStruct *chartInstance)
{
  real_T c7_d0;
  sf_set_error_prefix_string(
    "Error evaluating data 'l' in the parent workspace.\n");
  sf_mex_import_named("l", sf_mex_get_sfun_param(chartInstance->S, 0, 0), &c7_d0,
                      0, 0, 0U, 0, 0U, 0);
  chartInstance->c7_l = c7_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c7_Final_Project_v3b(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c7_Final_Project_v3b(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c7_update_debugger_state_c7_Final_Project_v3b
  (SFc7_Final_Project_v3bInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c7_Final_Project_v3b
  (SFc7_Final_Project_v3bInstanceStruct *chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_y = NULL;
  real_T c7_hoistedGlobal;
  real_T c7_u;
  const mxArray *c7_b_y = NULL;
  uint8_T c7_b_hoistedGlobal;
  uint8_T c7_b_u;
  const mxArray *c7_c_y = NULL;
  real_T *c7_Ya;
  c7_Ya = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c7_st = NULL;
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellarray(2), FALSE);
  c7_hoistedGlobal = *c7_Ya;
  c7_u = c7_hoistedGlobal;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_b_hoistedGlobal = chartInstance->c7_is_active_c7_Final_Project_v3b;
  c7_b_u = c7_b_hoistedGlobal;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 1, c7_c_y);
  sf_mex_assign(&c7_st, c7_y, FALSE);
  return c7_st;
}

static void set_sim_state_c7_Final_Project_v3b
  (SFc7_Final_Project_v3bInstanceStruct *chartInstance, const mxArray *c7_st)
{
  const mxArray *c7_u;
  real_T *c7_Ya;
  c7_Ya = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c7_doneDoubleBufferReInit = TRUE;
  c7_u = sf_mex_dup(c7_st);
  *c7_Ya = c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 0)),
    "Ya");
  chartInstance->c7_is_active_c7_Final_Project_v3b = c7_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 1)),
     "is_active_c7_Final_Project_v3b");
  sf_mex_destroy(&c7_u);
  c7_update_debugger_state_c7_Final_Project_v3b(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_Final_Project_v3b(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance)
{
}

static void sf_c7_Final_Project_v3b(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance)
{
  int32_T c7_i0;
  real_T c7_hoistedGlobal;
  int32_T c7_i1;
  real_T c7_qqd[9];
  real_T c7_b_l;
  uint32_T c7_debug_family_var_map[9];
  real_T c7_q[3];
  real_T c7_Ja[6];
  real_T c7_Ra;
  real_T c7_Sa[2];
  real_T c7_nargin = 2.0;
  real_T c7_nargout = 1.0;
  real_T c7_Ya;
  real_T c7_x;
  real_T c7_b_x;
  real_T c7_a;
  real_T c7_b;
  real_T c7_y;
  real_T c7_c_x;
  real_T c7_d_x;
  real_T c7_b_a;
  real_T c7_b_b;
  real_T c7_b_y;
  real_T c7_e_x;
  real_T c7_f_x;
  real_T c7_c_a;
  real_T c7_c_b;
  real_T c7_c_y;
  real_T c7_g_x;
  real_T c7_h_x;
  real_T c7_d_a;
  real_T c7_d_b;
  real_T c7_d_y;
  real_T c7_i_x;
  real_T c7_j_x;
  real_T c7_e_a;
  real_T c7_e_b;
  real_T c7_e_y;
  real_T c7_k_x;
  real_T c7_l_x;
  real_T c7_f_a;
  real_T c7_f_b;
  real_T c7_f_y;
  real_T c7_m_x;
  real_T c7_n_x;
  real_T c7_g_a;
  real_T c7_g_b;
  real_T c7_g_y;
  real_T c7_o_x;
  real_T c7_p_x;
  real_T c7_h_a;
  real_T c7_h_b;
  real_T c7_h_y;
  real_T c7_q_x;
  real_T c7_r_x;
  real_T c7_i_a;
  real_T c7_i_b;
  real_T c7_i_y;
  real_T c7_s_x;
  real_T c7_t_x;
  real_T c7_j_a;
  real_T c7_j_b;
  real_T c7_j_y;
  real_T c7_u_x;
  real_T c7_v_x;
  real_T c7_k_a;
  real_T c7_k_b;
  real_T c7_k_y;
  real_T c7_w_x;
  real_T c7_x_x;
  real_T c7_l_a;
  real_T c7_l_b;
  real_T c7_l_y;
  int32_T c7_i2;
  real_T c7_b_Ja[6];
  int32_T c7_i3;
  real_T *c7_b_Ya;
  real_T (*c7_b_qqd)[9];
  c7_b_Ya = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c7_b_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  for (c7_i0 = 0; c7_i0 < 9; c7_i0++) {
    _SFD_DATA_RANGE_CHECK((*c7_b_qqd)[c7_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c7_b_Ya, 1U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c7_l, 2U);
  chartInstance->c7_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  c7_hoistedGlobal = chartInstance->c7_l;
  for (c7_i1 = 0; c7_i1 < 9; c7_i1++) {
    c7_qqd[c7_i1] = (*c7_b_qqd)[c7_i1];
  }

  c7_b_l = c7_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c7_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_q, 0U, c7_e_sf_marshallOut,
    c7_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_Ja, 1U, c7_d_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_Ra, 2U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_Sa, 3U, c7_c_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 4U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 5U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_qqd, 6U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_l, 7U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_Ya, 8U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_q[0] = c7_qqd[6];
  c7_q[1] = c7_qqd[7];
  c7_q[2] = c7_qqd[8];
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 9);
  c7_x = c7_q[0];
  c7_b_x = c7_x;
  c7_b_x = muDoubleScalarSin(c7_b_x);
  c7_a = c7_b_l;
  c7_b = c7_b_x;
  c7_y = c7_a * c7_b;
  c7_c_x = c7_q[0] + c7_q[1];
  c7_d_x = c7_c_x;
  c7_d_x = muDoubleScalarSin(c7_d_x);
  c7_b_a = c7_b_l;
  c7_b_b = c7_d_x;
  c7_b_y = c7_b_a * c7_b_b;
  c7_e_x = (c7_q[0] + c7_q[1]) + c7_q[2];
  c7_f_x = c7_e_x;
  c7_f_x = muDoubleScalarSin(c7_f_x);
  c7_c_a = c7_b_l;
  c7_c_b = c7_f_x;
  c7_c_y = c7_c_a * c7_c_b;
  c7_g_x = c7_q[0] + c7_q[1];
  c7_h_x = c7_g_x;
  c7_h_x = muDoubleScalarSin(c7_h_x);
  c7_d_a = c7_b_l;
  c7_d_b = c7_h_x;
  c7_d_y = c7_d_a * c7_d_b;
  c7_i_x = (c7_q[0] + c7_q[1]) + c7_q[2];
  c7_j_x = c7_i_x;
  c7_j_x = muDoubleScalarSin(c7_j_x);
  c7_e_a = c7_b_l;
  c7_e_b = c7_j_x;
  c7_e_y = c7_e_a * c7_e_b;
  c7_k_x = (c7_q[0] + c7_q[1]) + c7_q[2];
  c7_l_x = c7_k_x;
  c7_l_x = muDoubleScalarSin(c7_l_x);
  c7_f_a = -c7_b_l;
  c7_f_b = c7_l_x;
  c7_f_y = c7_f_a * c7_f_b;
  c7_m_x = c7_q[0];
  c7_n_x = c7_m_x;
  c7_n_x = muDoubleScalarCos(c7_n_x);
  c7_g_a = c7_b_l;
  c7_g_b = c7_n_x;
  c7_g_y = c7_g_a * c7_g_b;
  c7_o_x = c7_q[0] + c7_q[1];
  c7_p_x = c7_o_x;
  c7_p_x = muDoubleScalarCos(c7_p_x);
  c7_h_a = c7_b_l;
  c7_h_b = c7_p_x;
  c7_h_y = c7_h_a * c7_h_b;
  c7_q_x = (c7_q[0] + c7_q[1]) + c7_q[2];
  c7_r_x = c7_q_x;
  c7_r_x = muDoubleScalarCos(c7_r_x);
  c7_i_a = c7_b_l;
  c7_i_b = c7_r_x;
  c7_i_y = c7_i_a * c7_i_b;
  c7_s_x = c7_q[0] + c7_q[1];
  c7_t_x = c7_s_x;
  c7_t_x = muDoubleScalarCos(c7_t_x);
  c7_j_a = c7_b_l;
  c7_j_b = c7_t_x;
  c7_j_y = c7_j_a * c7_j_b;
  c7_u_x = (c7_q[0] + c7_q[1]) + c7_q[2];
  c7_v_x = c7_u_x;
  c7_v_x = muDoubleScalarCos(c7_v_x);
  c7_k_a = c7_b_l;
  c7_k_b = c7_v_x;
  c7_k_y = c7_k_a * c7_k_b;
  c7_w_x = (c7_q[0] + c7_q[1]) + c7_q[2];
  c7_x_x = c7_w_x;
  c7_x_x = muDoubleScalarCos(c7_x_x);
  c7_l_a = c7_b_l;
  c7_l_b = c7_x_x;
  c7_l_y = c7_l_a * c7_l_b;
  c7_Ja[0] = -((c7_y + c7_b_y) + c7_c_y);
  c7_Ja[2] = -(c7_d_y + c7_e_y);
  c7_Ja[4] = c7_f_y;
  c7_Ja[1] = (c7_g_y + c7_h_y) + c7_i_y;
  c7_Ja[3] = c7_j_y + c7_k_y;
  c7_Ja[5] = c7_l_y;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 12);
  for (c7_i2 = 0; c7_i2 < 6; c7_i2++) {
    c7_b_Ja[c7_i2] = c7_Ja[c7_i2];
  }

  c7_Ra = c7_rank(chartInstance, c7_b_Ja);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 13);
  for (c7_i3 = 0; c7_i3 < 2; c7_i3++) {
    c7_Sa[c7_i3] = 2.0 + (real_T)c7_i3;
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 15);
  if (CV_EML_IF(0, 1, 0, c7_Ra < c7_Sa[0])) {
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 17);
    c7_Ya = 0.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 21);
    c7_Ya = 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -21);
  _SFD_SYMBOL_SCOPE_POP();
  *c7_b_Ya = c7_Ya;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Final_Project_v3bMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc7_Final_Project_v3b
  (SFc7_Final_Project_v3bInstanceStruct *chartInstance)
{
}

static void registerMessagesc7_Final_Project_v3b
  (SFc7_Final_Project_v3bInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber)
{
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_Final_Project_v3bInstanceStruct *chartInstance;
  chartInstance = (SFc7_Final_Project_v3bInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static real_T c7_emlrt_marshallIn(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance, const mxArray *c7_Ya, const char_T *c7_identifier)
{
  real_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_Ya), &c7_thisId);
  sf_mex_destroy(&c7_Ya);
  return c7_y;
}

static real_T c7_b_emlrt_marshallIn(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d1;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_d1, 1, 0, 0U, 0, 0U, 0);
  c7_y = c7_d1;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_Ya;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y;
  SFc7_Final_Project_v3bInstanceStruct *chartInstance;
  chartInstance = (SFc7_Final_Project_v3bInstanceStruct *)chartInstanceVoid;
  c7_Ya = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_Ya), &c7_thisId);
  sf_mex_destroy(&c7_Ya);
  *(real_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i4;
  real_T c7_b_inData[9];
  int32_T c7_i5;
  real_T c7_u[9];
  const mxArray *c7_y = NULL;
  SFc7_Final_Project_v3bInstanceStruct *chartInstance;
  chartInstance = (SFc7_Final_Project_v3bInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i4 = 0; c7_i4 < 9; c7_i4++) {
    c7_b_inData[c7_i4] = (*(real_T (*)[9])c7_inData)[c7_i4];
  }

  for (c7_i5 = 0; c7_i5 < 9; c7_i5++) {
    c7_u[c7_i5] = c7_b_inData[c7_i5];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 9), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i6;
  real_T c7_b_inData[2];
  int32_T c7_i7;
  real_T c7_u[2];
  const mxArray *c7_y = NULL;
  SFc7_Final_Project_v3bInstanceStruct *chartInstance;
  chartInstance = (SFc7_Final_Project_v3bInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i6 = 0; c7_i6 < 2; c7_i6++) {
    c7_b_inData[c7_i6] = (*(real_T (*)[2])c7_inData)[c7_i6];
  }

  for (c7_i7 = 0; c7_i7 < 2; c7_i7++) {
    c7_u[c7_i7] = c7_b_inData[c7_i7];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 2, 1, 2), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static void c7_c_emlrt_marshallIn(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_y[2])
{
  real_T c7_dv0[2];
  int32_T c7_i8;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_dv0, 1, 0, 0U, 1, 0U, 2, 1, 2);
  for (c7_i8 = 0; c7_i8 < 2; c7_i8++) {
    c7_y[c7_i8] = c7_dv0[c7_i8];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_Sa;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y[2];
  int32_T c7_i9;
  SFc7_Final_Project_v3bInstanceStruct *chartInstance;
  chartInstance = (SFc7_Final_Project_v3bInstanceStruct *)chartInstanceVoid;
  c7_Sa = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_Sa), &c7_thisId, c7_y);
  sf_mex_destroy(&c7_Sa);
  for (c7_i9 = 0; c7_i9 < 2; c7_i9++) {
    (*(real_T (*)[2])c7_outData)[c7_i9] = c7_y[c7_i9];
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i10;
  int32_T c7_i11;
  int32_T c7_i12;
  real_T c7_b_inData[6];
  int32_T c7_i13;
  int32_T c7_i14;
  int32_T c7_i15;
  real_T c7_u[6];
  const mxArray *c7_y = NULL;
  SFc7_Final_Project_v3bInstanceStruct *chartInstance;
  chartInstance = (SFc7_Final_Project_v3bInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_i10 = 0;
  for (c7_i11 = 0; c7_i11 < 3; c7_i11++) {
    for (c7_i12 = 0; c7_i12 < 2; c7_i12++) {
      c7_b_inData[c7_i12 + c7_i10] = (*(real_T (*)[6])c7_inData)[c7_i12 + c7_i10];
    }

    c7_i10 += 2;
  }

  c7_i13 = 0;
  for (c7_i14 = 0; c7_i14 < 3; c7_i14++) {
    for (c7_i15 = 0; c7_i15 < 2; c7_i15++) {
      c7_u[c7_i15 + c7_i13] = c7_b_inData[c7_i15 + c7_i13];
    }

    c7_i13 += 2;
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 2, 2, 3), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static void c7_d_emlrt_marshallIn(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_y[6])
{
  real_T c7_dv1[6];
  int32_T c7_i16;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_dv1, 1, 0, 0U, 1, 0U, 2, 2, 3);
  for (c7_i16 = 0; c7_i16 < 6; c7_i16++) {
    c7_y[c7_i16] = c7_dv1[c7_i16];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_Ja;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y[6];
  int32_T c7_i17;
  int32_T c7_i18;
  int32_T c7_i19;
  SFc7_Final_Project_v3bInstanceStruct *chartInstance;
  chartInstance = (SFc7_Final_Project_v3bInstanceStruct *)chartInstanceVoid;
  c7_Ja = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_Ja), &c7_thisId, c7_y);
  sf_mex_destroy(&c7_Ja);
  c7_i17 = 0;
  for (c7_i18 = 0; c7_i18 < 3; c7_i18++) {
    for (c7_i19 = 0; c7_i19 < 2; c7_i19++) {
      (*(real_T (*)[6])c7_outData)[c7_i19 + c7_i17] = c7_y[c7_i19 + c7_i17];
    }

    c7_i17 += 2;
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_e_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i20;
  real_T c7_b_inData[3];
  int32_T c7_i21;
  real_T c7_u[3];
  const mxArray *c7_y = NULL;
  SFc7_Final_Project_v3bInstanceStruct *chartInstance;
  chartInstance = (SFc7_Final_Project_v3bInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i20 = 0; c7_i20 < 3; c7_i20++) {
    c7_b_inData[c7_i20] = (*(real_T (*)[3])c7_inData)[c7_i20];
  }

  for (c7_i21 = 0; c7_i21 < 3; c7_i21++) {
    c7_u[c7_i21] = c7_b_inData[c7_i21];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 2, 1, 3), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static void c7_e_emlrt_marshallIn(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_y[3])
{
  real_T c7_dv2[3];
  int32_T c7_i22;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_dv2, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c7_i22 = 0; c7_i22 < 3; c7_i22++) {
    c7_y[c7_i22] = c7_dv2[c7_i22];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_q;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y[3];
  int32_T c7_i23;
  SFc7_Final_Project_v3bInstanceStruct *chartInstance;
  chartInstance = (SFc7_Final_Project_v3bInstanceStruct *)chartInstanceVoid;
  c7_q = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_q), &c7_thisId, c7_y);
  sf_mex_destroy(&c7_q);
  for (c7_i23 = 0; c7_i23 < 3; c7_i23++) {
    (*(real_T (*)[3])c7_outData)[c7_i23] = c7_y[c7_i23];
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

const mxArray *sf_c7_Final_Project_v3b_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo;
  c7_ResolvedFunctionInfo c7_info[134];
  const mxArray *c7_m0 = NULL;
  int32_T c7_i24;
  c7_ResolvedFunctionInfo *c7_r0;
  c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  c7_info_helper(c7_info);
  c7_b_info_helper(c7_info);
  c7_c_info_helper(c7_info);
  sf_mex_assign(&c7_m0, sf_mex_createstruct("nameCaptureInfo", 1, 134), FALSE);
  for (c7_i24 = 0; c7_i24 < 134; c7_i24++) {
    c7_r0 = &c7_info[c7_i24];
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->context)), "context", "nameCaptureInfo",
                    c7_i24);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c7_r0->name)), "name", "nameCaptureInfo", c7_i24);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c7_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c7_i24);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->resolved)), "resolved", "nameCaptureInfo",
                    c7_i24);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c7_i24);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c7_i24);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c7_i24);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c7_i24);
  }

  sf_mex_assign(&c7_nameCaptureInfo, c7_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c7_nameCaptureInfo);
  return c7_nameCaptureInfo;
}

static void c7_info_helper(c7_ResolvedFunctionInfo c7_info[134])
{
  c7_info[0].context = "";
  c7_info[0].name = "sin";
  c7_info[0].dominantType = "double";
  c7_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c7_info[0].fileTimeLo = 1343862786U;
  c7_info[0].fileTimeHi = 0U;
  c7_info[0].mFileTimeLo = 0U;
  c7_info[0].mFileTimeHi = 0U;
  c7_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c7_info[1].name = "eml_scalar_sin";
  c7_info[1].dominantType = "double";
  c7_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c7_info[1].fileTimeLo = 1286851136U;
  c7_info[1].fileTimeHi = 0U;
  c7_info[1].mFileTimeLo = 0U;
  c7_info[1].mFileTimeHi = 0U;
  c7_info[2].context = "";
  c7_info[2].name = "mtimes";
  c7_info[2].dominantType = "double";
  c7_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c7_info[2].fileTimeLo = 1289552092U;
  c7_info[2].fileTimeHi = 0U;
  c7_info[2].mFileTimeLo = 0U;
  c7_info[2].mFileTimeHi = 0U;
  c7_info[3].context = "";
  c7_info[3].name = "cos";
  c7_info[3].dominantType = "double";
  c7_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c7_info[3].fileTimeLo = 1343862772U;
  c7_info[3].fileTimeHi = 0U;
  c7_info[3].mFileTimeLo = 0U;
  c7_info[3].mFileTimeHi = 0U;
  c7_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c7_info[4].name = "eml_scalar_cos";
  c7_info[4].dominantType = "double";
  c7_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c7_info[4].fileTimeLo = 1286851122U;
  c7_info[4].fileTimeHi = 0U;
  c7_info[4].mFileTimeLo = 0U;
  c7_info[4].mFileTimeHi = 0U;
  c7_info[5].context = "";
  c7_info[5].name = "rank";
  c7_info[5].dominantType = "double";
  c7_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/rank.m";
  c7_info[5].fileTimeLo = 1286851230U;
  c7_info[5].fileTimeHi = 0U;
  c7_info[5].mFileTimeLo = 0U;
  c7_info[5].mFileTimeHi = 0U;
  c7_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/rank.m";
  c7_info[6].name = "svd";
  c7_info[6].dominantType = "double";
  c7_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c7_info[6].fileTimeLo = 1286851232U;
  c7_info[6].fileTimeHi = 0U;
  c7_info[6].mFileTimeLo = 0U;
  c7_info[6].mFileTimeHi = 0U;
  c7_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c7_info[7].name = "eml_index_class";
  c7_info[7].dominantType = "";
  c7_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[7].fileTimeLo = 1323202978U;
  c7_info[7].fileTimeHi = 0U;
  c7_info[7].mFileTimeLo = 0U;
  c7_info[7].mFileTimeHi = 0U;
  c7_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c7_info[8].name = "eml_int_forloop_overflow_check";
  c7_info[8].dominantType = "";
  c7_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c7_info[8].fileTimeLo = 1346542740U;
  c7_info[8].fileTimeHi = 0U;
  c7_info[8].mFileTimeLo = 0U;
  c7_info[8].mFileTimeHi = 0U;
  c7_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c7_info[9].name = "intmax";
  c7_info[9].dominantType = "char";
  c7_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c7_info[9].fileTimeLo = 1311287716U;
  c7_info[9].fileTimeHi = 0U;
  c7_info[9].mFileTimeLo = 0U;
  c7_info[9].mFileTimeHi = 0U;
  c7_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c7_info[10].name = "isfinite";
  c7_info[10].dominantType = "double";
  c7_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c7_info[10].fileTimeLo = 1286851158U;
  c7_info[10].fileTimeHi = 0U;
  c7_info[10].mFileTimeLo = 0U;
  c7_info[10].mFileTimeHi = 0U;
  c7_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c7_info[11].name = "isinf";
  c7_info[11].dominantType = "double";
  c7_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c7_info[11].fileTimeLo = 1286851160U;
  c7_info[11].fileTimeHi = 0U;
  c7_info[11].mFileTimeLo = 0U;
  c7_info[11].mFileTimeHi = 0U;
  c7_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c7_info[12].name = "isnan";
  c7_info[12].dominantType = "double";
  c7_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c7_info[12].fileTimeLo = 1286851160U;
  c7_info[12].fileTimeHi = 0U;
  c7_info[12].mFileTimeLo = 0U;
  c7_info[12].mFileTimeHi = 0U;
  c7_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c7_info[13].name = "eml_error";
  c7_info[13].dominantType = "char";
  c7_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c7_info[13].fileTimeLo = 1343862758U;
  c7_info[13].fileTimeHi = 0U;
  c7_info[13].mFileTimeLo = 0U;
  c7_info[13].mFileTimeHi = 0U;
  c7_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c7_info[14].name = "eml_xgesvd";
  c7_info[14].dominantType = "double";
  c7_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m";
  c7_info[14].fileTimeLo = 1286851206U;
  c7_info[14].fileTimeHi = 0U;
  c7_info[14].mFileTimeLo = 0U;
  c7_info[14].mFileTimeHi = 0U;
  c7_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m";
  c7_info[15].name = "eml_lapack_xgesvd";
  c7_info[15].dominantType = "double";
  c7_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m";
  c7_info[15].fileTimeLo = 1286851210U;
  c7_info[15].fileTimeHi = 0U;
  c7_info[15].mFileTimeLo = 0U;
  c7_info[15].mFileTimeHi = 0U;
  c7_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m";
  c7_info[16].name = "eml_matlab_zsvdc";
  c7_info[16].dominantType = "double";
  c7_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c7_info[16].fileTimeLo = 1295317266U;
  c7_info[16].fileTimeHi = 0U;
  c7_info[16].mFileTimeLo = 0U;
  c7_info[16].mFileTimeHi = 0U;
  c7_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c7_info[17].name = "eml_index_class";
  c7_info[17].dominantType = "";
  c7_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[17].fileTimeLo = 1323202978U;
  c7_info[17].fileTimeHi = 0U;
  c7_info[17].mFileTimeLo = 0U;
  c7_info[17].mFileTimeHi = 0U;
  c7_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c7_info[18].name = "eml_scalar_eg";
  c7_info[18].dominantType = "double";
  c7_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[18].fileTimeLo = 1286851196U;
  c7_info[18].fileTimeHi = 0U;
  c7_info[18].mFileTimeLo = 0U;
  c7_info[18].mFileTimeHi = 0U;
  c7_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c7_info[19].name = "eml_index_plus";
  c7_info[19].dominantType = "double";
  c7_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c7_info[19].fileTimeLo = 1286851178U;
  c7_info[19].fileTimeHi = 0U;
  c7_info[19].mFileTimeLo = 0U;
  c7_info[19].mFileTimeHi = 0U;
  c7_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c7_info[20].name = "eml_index_class";
  c7_info[20].dominantType = "";
  c7_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[20].fileTimeLo = 1323202978U;
  c7_info[20].fileTimeHi = 0U;
  c7_info[20].mFileTimeLo = 0U;
  c7_info[20].mFileTimeHi = 0U;
  c7_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c7_info[21].name = "min";
  c7_info[21].dominantType = "coder.internal.indexInt";
  c7_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c7_info[21].fileTimeLo = 1311287718U;
  c7_info[21].fileTimeHi = 0U;
  c7_info[21].mFileTimeLo = 0U;
  c7_info[21].mFileTimeHi = 0U;
  c7_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c7_info[22].name = "eml_min_or_max";
  c7_info[22].dominantType = "char";
  c7_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c7_info[22].fileTimeLo = 1334103890U;
  c7_info[22].fileTimeHi = 0U;
  c7_info[22].mFileTimeLo = 0U;
  c7_info[22].mFileTimeHi = 0U;
  c7_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c7_info[23].name = "eml_scalar_eg";
  c7_info[23].dominantType = "coder.internal.indexInt";
  c7_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[23].fileTimeLo = 1286851196U;
  c7_info[23].fileTimeHi = 0U;
  c7_info[23].mFileTimeLo = 0U;
  c7_info[23].mFileTimeHi = 0U;
  c7_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c7_info[24].name = "eml_scalexp_alloc";
  c7_info[24].dominantType = "coder.internal.indexInt";
  c7_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c7_info[24].fileTimeLo = 1352457260U;
  c7_info[24].fileTimeHi = 0U;
  c7_info[24].mFileTimeLo = 0U;
  c7_info[24].mFileTimeHi = 0U;
  c7_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c7_info[25].name = "eml_index_class";
  c7_info[25].dominantType = "";
  c7_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[25].fileTimeLo = 1323202978U;
  c7_info[25].fileTimeHi = 0U;
  c7_info[25].mFileTimeLo = 0U;
  c7_info[25].mFileTimeHi = 0U;
  c7_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c7_info[26].name = "eml_scalar_eg";
  c7_info[26].dominantType = "coder.internal.indexInt";
  c7_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[26].fileTimeLo = 1286851196U;
  c7_info[26].fileTimeHi = 0U;
  c7_info[26].mFileTimeLo = 0U;
  c7_info[26].mFileTimeHi = 0U;
  c7_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c7_info[27].name = "max";
  c7_info[27].dominantType = "double";
  c7_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c7_info[27].fileTimeLo = 1311287716U;
  c7_info[27].fileTimeHi = 0U;
  c7_info[27].mFileTimeLo = 0U;
  c7_info[27].mFileTimeHi = 0U;
  c7_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c7_info[28].name = "eml_min_or_max";
  c7_info[28].dominantType = "char";
  c7_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c7_info[28].fileTimeLo = 1334103890U;
  c7_info[28].fileTimeHi = 0U;
  c7_info[28].mFileTimeLo = 0U;
  c7_info[28].mFileTimeHi = 0U;
  c7_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c7_info[29].name = "eml_scalar_eg";
  c7_info[29].dominantType = "double";
  c7_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[29].fileTimeLo = 1286851196U;
  c7_info[29].fileTimeHi = 0U;
  c7_info[29].mFileTimeLo = 0U;
  c7_info[29].mFileTimeHi = 0U;
  c7_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c7_info[30].name = "eml_scalexp_alloc";
  c7_info[30].dominantType = "double";
  c7_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c7_info[30].fileTimeLo = 1352457260U;
  c7_info[30].fileTimeHi = 0U;
  c7_info[30].mFileTimeLo = 0U;
  c7_info[30].mFileTimeHi = 0U;
  c7_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c7_info[31].name = "eml_scalar_eg";
  c7_info[31].dominantType = "double";
  c7_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[31].fileTimeLo = 1286851196U;
  c7_info[31].fileTimeHi = 0U;
  c7_info[31].mFileTimeLo = 0U;
  c7_info[31].mFileTimeHi = 0U;
  c7_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c7_info[32].name = "eml_relop";
  c7_info[32].dominantType = "function_handle";
  c7_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c7_info[32].fileTimeLo = 1342483582U;
  c7_info[32].fileTimeHi = 0U;
  c7_info[32].mFileTimeLo = 0U;
  c7_info[32].mFileTimeHi = 0U;
  c7_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c7_info[33].name = "coder.internal.indexIntRelop";
  c7_info[33].dominantType = "";
  c7_info[33].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m";
  c7_info[33].fileTimeLo = 1326760722U;
  c7_info[33].fileTimeHi = 0U;
  c7_info[33].mFileTimeLo = 0U;
  c7_info[33].mFileTimeHi = 0U;
  c7_info[34].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass";
  c7_info[34].name = "eml_float_model";
  c7_info[34].dominantType = "char";
  c7_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c7_info[34].fileTimeLo = 1326760396U;
  c7_info[34].fileTimeHi = 0U;
  c7_info[34].mFileTimeLo = 0U;
  c7_info[34].mFileTimeHi = 0U;
  c7_info[35].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass";
  c7_info[35].name = "intmin";
  c7_info[35].dominantType = "char";
  c7_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c7_info[35].fileTimeLo = 1311287718U;
  c7_info[35].fileTimeHi = 0U;
  c7_info[35].mFileTimeLo = 0U;
  c7_info[35].mFileTimeHi = 0U;
  c7_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c7_info[36].name = "isnan";
  c7_info[36].dominantType = "coder.internal.indexInt";
  c7_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c7_info[36].fileTimeLo = 1286851160U;
  c7_info[36].fileTimeHi = 0U;
  c7_info[36].mFileTimeLo = 0U;
  c7_info[36].mFileTimeHi = 0U;
  c7_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c7_info[37].name = "eml_index_minus";
  c7_info[37].dominantType = "double";
  c7_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c7_info[37].fileTimeLo = 1286851178U;
  c7_info[37].fileTimeHi = 0U;
  c7_info[37].mFileTimeLo = 0U;
  c7_info[37].mFileTimeHi = 0U;
  c7_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c7_info[38].name = "eml_index_class";
  c7_info[38].dominantType = "";
  c7_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[38].fileTimeLo = 1323202978U;
  c7_info[38].fileTimeHi = 0U;
  c7_info[38].mFileTimeLo = 0U;
  c7_info[38].mFileTimeHi = 0U;
  c7_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c7_info[39].name = "max";
  c7_info[39].dominantType = "coder.internal.indexInt";
  c7_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c7_info[39].fileTimeLo = 1311287716U;
  c7_info[39].fileTimeHi = 0U;
  c7_info[39].mFileTimeLo = 0U;
  c7_info[39].mFileTimeHi = 0U;
  c7_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c7_info[40].name = "eml_index_times";
  c7_info[40].dominantType = "coder.internal.indexInt";
  c7_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c7_info[40].fileTimeLo = 1286851180U;
  c7_info[40].fileTimeHi = 0U;
  c7_info[40].mFileTimeLo = 0U;
  c7_info[40].mFileTimeHi = 0U;
  c7_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c7_info[41].name = "eml_index_class";
  c7_info[41].dominantType = "";
  c7_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[41].fileTimeLo = 1323202978U;
  c7_info[41].fileTimeHi = 0U;
  c7_info[41].mFileTimeLo = 0U;
  c7_info[41].mFileTimeHi = 0U;
  c7_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c7_info[42].name = "eml_index_plus";
  c7_info[42].dominantType = "coder.internal.indexInt";
  c7_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c7_info[42].fileTimeLo = 1286851178U;
  c7_info[42].fileTimeHi = 0U;
  c7_info[42].mFileTimeLo = 0U;
  c7_info[42].mFileTimeHi = 0U;
  c7_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c7_info[43].name = "eml_index_minus";
  c7_info[43].dominantType = "coder.internal.indexInt";
  c7_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c7_info[43].fileTimeLo = 1286851178U;
  c7_info[43].fileTimeHi = 0U;
  c7_info[43].mFileTimeLo = 0U;
  c7_info[43].mFileTimeHi = 0U;
  c7_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c7_info[44].name = "eml_xnrm2";
  c7_info[44].dominantType = "double";
  c7_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c7_info[44].fileTimeLo = 1299109176U;
  c7_info[44].fileTimeHi = 0U;
  c7_info[44].mFileTimeLo = 0U;
  c7_info[44].mFileTimeHi = 0U;
  c7_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c7_info[45].name = "eml_blas_inline";
  c7_info[45].dominantType = "";
  c7_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c7_info[45].fileTimeLo = 1299109168U;
  c7_info[45].fileTimeHi = 0U;
  c7_info[45].mFileTimeLo = 0U;
  c7_info[45].mFileTimeHi = 0U;
  c7_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c7_info[46].name = "eml_index_class";
  c7_info[46].dominantType = "";
  c7_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[46].fileTimeLo = 1323202978U;
  c7_info[46].fileTimeHi = 0U;
  c7_info[46].mFileTimeLo = 0U;
  c7_info[46].mFileTimeHi = 0U;
  c7_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c7_info[47].name = "eml_refblas_xnrm2";
  c7_info[47].dominantType = "double";
  c7_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c7_info[47].fileTimeLo = 1299109184U;
  c7_info[47].fileTimeHi = 0U;
  c7_info[47].mFileTimeLo = 0U;
  c7_info[47].mFileTimeHi = 0U;
  c7_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c7_info[48].name = "realmin";
  c7_info[48].dominantType = "char";
  c7_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c7_info[48].fileTimeLo = 1307683642U;
  c7_info[48].fileTimeHi = 0U;
  c7_info[48].mFileTimeLo = 0U;
  c7_info[48].mFileTimeHi = 0U;
  c7_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c7_info[49].name = "eml_realmin";
  c7_info[49].dominantType = "char";
  c7_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c7_info[49].fileTimeLo = 1307683644U;
  c7_info[49].fileTimeHi = 0U;
  c7_info[49].mFileTimeLo = 0U;
  c7_info[49].mFileTimeHi = 0U;
  c7_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c7_info[50].name = "eml_float_model";
  c7_info[50].dominantType = "char";
  c7_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c7_info[50].fileTimeLo = 1326760396U;
  c7_info[50].fileTimeHi = 0U;
  c7_info[50].mFileTimeLo = 0U;
  c7_info[50].mFileTimeHi = 0U;
  c7_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c7_info[51].name = "eml_index_class";
  c7_info[51].dominantType = "";
  c7_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[51].fileTimeLo = 1323202978U;
  c7_info[51].fileTimeHi = 0U;
  c7_info[51].mFileTimeLo = 0U;
  c7_info[51].mFileTimeHi = 0U;
  c7_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c7_info[52].name = "eml_index_minus";
  c7_info[52].dominantType = "double";
  c7_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c7_info[52].fileTimeLo = 1286851178U;
  c7_info[52].fileTimeHi = 0U;
  c7_info[52].mFileTimeLo = 0U;
  c7_info[52].mFileTimeHi = 0U;
  c7_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c7_info[53].name = "eml_index_times";
  c7_info[53].dominantType = "coder.internal.indexInt";
  c7_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c7_info[53].fileTimeLo = 1286851180U;
  c7_info[53].fileTimeHi = 0U;
  c7_info[53].mFileTimeLo = 0U;
  c7_info[53].mFileTimeHi = 0U;
  c7_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c7_info[54].name = "eml_index_plus";
  c7_info[54].dominantType = "coder.internal.indexInt";
  c7_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c7_info[54].fileTimeLo = 1286851178U;
  c7_info[54].fileTimeHi = 0U;
  c7_info[54].mFileTimeLo = 0U;
  c7_info[54].mFileTimeHi = 0U;
  c7_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c7_info[55].name = "eml_int_forloop_overflow_check";
  c7_info[55].dominantType = "";
  c7_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c7_info[55].fileTimeLo = 1346542740U;
  c7_info[55].fileTimeHi = 0U;
  c7_info[55].mFileTimeLo = 0U;
  c7_info[55].mFileTimeHi = 0U;
  c7_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c7_info[56].name = "abs";
  c7_info[56].dominantType = "double";
  c7_info[56].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c7_info[56].fileTimeLo = 1343862766U;
  c7_info[56].fileTimeHi = 0U;
  c7_info[56].mFileTimeLo = 0U;
  c7_info[56].mFileTimeHi = 0U;
  c7_info[57].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c7_info[57].name = "eml_scalar_abs";
  c7_info[57].dominantType = "double";
  c7_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c7_info[57].fileTimeLo = 1286851112U;
  c7_info[57].fileTimeHi = 0U;
  c7_info[57].mFileTimeLo = 0U;
  c7_info[57].mFileTimeHi = 0U;
  c7_info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c7_info[58].name = "eml_div";
  c7_info[58].dominantType = "double";
  c7_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c7_info[58].fileTimeLo = 1313380210U;
  c7_info[58].fileTimeHi = 0U;
  c7_info[58].mFileTimeLo = 0U;
  c7_info[58].mFileTimeHi = 0U;
  c7_info[59].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c7_info[59].name = "eml_xscal";
  c7_info[59].dominantType = "double";
  c7_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  c7_info[59].fileTimeLo = 1299109176U;
  c7_info[59].fileTimeHi = 0U;
  c7_info[59].mFileTimeLo = 0U;
  c7_info[59].mFileTimeHi = 0U;
  c7_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  c7_info[60].name = "eml_blas_inline";
  c7_info[60].dominantType = "";
  c7_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c7_info[60].fileTimeLo = 1299109168U;
  c7_info[60].fileTimeHi = 0U;
  c7_info[60].mFileTimeLo = 0U;
  c7_info[60].mFileTimeHi = 0U;
  c7_info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c7_info[61].name = "eml_index_class";
  c7_info[61].dominantType = "";
  c7_info[61].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[61].fileTimeLo = 1323202978U;
  c7_info[61].fileTimeHi = 0U;
  c7_info[61].mFileTimeLo = 0U;
  c7_info[61].mFileTimeHi = 0U;
  c7_info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c7_info[62].name = "eml_scalar_eg";
  c7_info[62].dominantType = "double";
  c7_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[62].fileTimeLo = 1286851196U;
  c7_info[62].fileTimeHi = 0U;
  c7_info[62].mFileTimeLo = 0U;
  c7_info[62].mFileTimeHi = 0U;
  c7_info[63].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c7_info[63].name = "eml_refblas_xscal";
  c7_info[63].dominantType = "double";
  c7_info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c7_info[63].fileTimeLo = 1299109184U;
  c7_info[63].fileTimeHi = 0U;
  c7_info[63].mFileTimeLo = 0U;
  c7_info[63].mFileTimeHi = 0U;
}

static void c7_b_info_helper(c7_ResolvedFunctionInfo c7_info[134])
{
  c7_info[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c7_info[64].name = "eml_index_class";
  c7_info[64].dominantType = "";
  c7_info[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[64].fileTimeLo = 1323202978U;
  c7_info[64].fileTimeHi = 0U;
  c7_info[64].mFileTimeLo = 0U;
  c7_info[64].mFileTimeHi = 0U;
  c7_info[65].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c7_info[65].name = "eml_index_minus";
  c7_info[65].dominantType = "double";
  c7_info[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c7_info[65].fileTimeLo = 1286851178U;
  c7_info[65].fileTimeHi = 0U;
  c7_info[65].mFileTimeLo = 0U;
  c7_info[65].mFileTimeHi = 0U;
  c7_info[66].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c7_info[66].name = "eml_index_times";
  c7_info[66].dominantType = "coder.internal.indexInt";
  c7_info[66].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c7_info[66].fileTimeLo = 1286851180U;
  c7_info[66].fileTimeHi = 0U;
  c7_info[66].mFileTimeLo = 0U;
  c7_info[66].mFileTimeHi = 0U;
  c7_info[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c7_info[67].name = "eml_index_plus";
  c7_info[67].dominantType = "coder.internal.indexInt";
  c7_info[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c7_info[67].fileTimeLo = 1286851178U;
  c7_info[67].fileTimeHi = 0U;
  c7_info[67].mFileTimeLo = 0U;
  c7_info[67].mFileTimeHi = 0U;
  c7_info[68].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c7_info[68].name = "eml_int_forloop_overflow_check";
  c7_info[68].dominantType = "";
  c7_info[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c7_info[68].fileTimeLo = 1346542740U;
  c7_info[68].fileTimeHi = 0U;
  c7_info[68].mFileTimeLo = 0U;
  c7_info[68].mFileTimeHi = 0U;
  c7_info[69].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c7_info[69].name = "eml_int_forloop_overflow_check";
  c7_info[69].dominantType = "";
  c7_info[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c7_info[69].fileTimeLo = 1346542740U;
  c7_info[69].fileTimeHi = 0U;
  c7_info[69].mFileTimeLo = 0U;
  c7_info[69].mFileTimeHi = 0U;
  c7_info[70].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c7_info[70].name = "eml_xdotc";
  c7_info[70].dominantType = "double";
  c7_info[70].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c7_info[70].fileTimeLo = 1299109172U;
  c7_info[70].fileTimeHi = 0U;
  c7_info[70].mFileTimeLo = 0U;
  c7_info[70].mFileTimeHi = 0U;
  c7_info[71].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c7_info[71].name = "eml_blas_inline";
  c7_info[71].dominantType = "";
  c7_info[71].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c7_info[71].fileTimeLo = 1299109168U;
  c7_info[71].fileTimeHi = 0U;
  c7_info[71].mFileTimeLo = 0U;
  c7_info[71].mFileTimeHi = 0U;
  c7_info[72].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c7_info[72].name = "eml_xdot";
  c7_info[72].dominantType = "double";
  c7_info[72].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c7_info[72].fileTimeLo = 1299109172U;
  c7_info[72].fileTimeHi = 0U;
  c7_info[72].mFileTimeLo = 0U;
  c7_info[72].mFileTimeHi = 0U;
  c7_info[73].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c7_info[73].name = "eml_blas_inline";
  c7_info[73].dominantType = "";
  c7_info[73].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c7_info[73].fileTimeLo = 1299109168U;
  c7_info[73].fileTimeHi = 0U;
  c7_info[73].mFileTimeLo = 0U;
  c7_info[73].mFileTimeHi = 0U;
  c7_info[74].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c7_info[74].name = "eml_index_class";
  c7_info[74].dominantType = "";
  c7_info[74].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[74].fileTimeLo = 1323202978U;
  c7_info[74].fileTimeHi = 0U;
  c7_info[74].mFileTimeLo = 0U;
  c7_info[74].mFileTimeHi = 0U;
  c7_info[75].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c7_info[75].name = "eml_refblas_xdot";
  c7_info[75].dominantType = "double";
  c7_info[75].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c7_info[75].fileTimeLo = 1299109172U;
  c7_info[75].fileTimeHi = 0U;
  c7_info[75].mFileTimeLo = 0U;
  c7_info[75].mFileTimeHi = 0U;
  c7_info[76].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c7_info[76].name = "eml_refblas_xdotx";
  c7_info[76].dominantType = "char";
  c7_info[76].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c7_info[76].fileTimeLo = 1299109174U;
  c7_info[76].fileTimeHi = 0U;
  c7_info[76].mFileTimeLo = 0U;
  c7_info[76].mFileTimeHi = 0U;
  c7_info[77].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c7_info[77].name = "eml_scalar_eg";
  c7_info[77].dominantType = "double";
  c7_info[77].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[77].fileTimeLo = 1286851196U;
  c7_info[77].fileTimeHi = 0U;
  c7_info[77].mFileTimeLo = 0U;
  c7_info[77].mFileTimeHi = 0U;
  c7_info[78].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c7_info[78].name = "eml_index_class";
  c7_info[78].dominantType = "";
  c7_info[78].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[78].fileTimeLo = 1323202978U;
  c7_info[78].fileTimeHi = 0U;
  c7_info[78].mFileTimeLo = 0U;
  c7_info[78].mFileTimeHi = 0U;
  c7_info[79].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c7_info[79].name = "eml_int_forloop_overflow_check";
  c7_info[79].dominantType = "";
  c7_info[79].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c7_info[79].fileTimeLo = 1346542740U;
  c7_info[79].fileTimeHi = 0U;
  c7_info[79].mFileTimeLo = 0U;
  c7_info[79].mFileTimeHi = 0U;
  c7_info[80].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c7_info[80].name = "eml_index_plus";
  c7_info[80].dominantType = "coder.internal.indexInt";
  c7_info[80].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c7_info[80].fileTimeLo = 1286851178U;
  c7_info[80].fileTimeHi = 0U;
  c7_info[80].mFileTimeLo = 0U;
  c7_info[80].mFileTimeHi = 0U;
  c7_info[81].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c7_info[81].name = "eml_xaxpy";
  c7_info[81].dominantType = "double";
  c7_info[81].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m";
  c7_info[81].fileTimeLo = 1299109170U;
  c7_info[81].fileTimeHi = 0U;
  c7_info[81].mFileTimeLo = 0U;
  c7_info[81].mFileTimeHi = 0U;
  c7_info[82].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m";
  c7_info[82].name = "eml_blas_inline";
  c7_info[82].dominantType = "";
  c7_info[82].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c7_info[82].fileTimeLo = 1299109168U;
  c7_info[82].fileTimeHi = 0U;
  c7_info[82].mFileTimeLo = 0U;
  c7_info[82].mFileTimeHi = 0U;
  c7_info[83].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m";
  c7_info[83].name = "eml_index_class";
  c7_info[83].dominantType = "";
  c7_info[83].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[83].fileTimeLo = 1323202978U;
  c7_info[83].fileTimeHi = 0U;
  c7_info[83].mFileTimeLo = 0U;
  c7_info[83].mFileTimeHi = 0U;
  c7_info[84].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m";
  c7_info[84].name = "eml_scalar_eg";
  c7_info[84].dominantType = "double";
  c7_info[84].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[84].fileTimeLo = 1286851196U;
  c7_info[84].fileTimeHi = 0U;
  c7_info[84].mFileTimeLo = 0U;
  c7_info[84].mFileTimeHi = 0U;
  c7_info[85].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m";
  c7_info[85].name = "eml_refblas_xaxpy";
  c7_info[85].dominantType = "double";
  c7_info[85].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c7_info[85].fileTimeLo = 1299109172U;
  c7_info[85].fileTimeHi = 0U;
  c7_info[85].mFileTimeLo = 0U;
  c7_info[85].mFileTimeHi = 0U;
  c7_info[86].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c7_info[86].name = "eml_index_class";
  c7_info[86].dominantType = "";
  c7_info[86].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[86].fileTimeLo = 1323202978U;
  c7_info[86].fileTimeHi = 0U;
  c7_info[86].mFileTimeLo = 0U;
  c7_info[86].mFileTimeHi = 0U;
  c7_info[87].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c7_info[87].name = "eml_isa_uint";
  c7_info[87].dominantType = "coder.internal.indexInt";
  c7_info[87].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c7_info[87].fileTimeLo = 1286851184U;
  c7_info[87].fileTimeHi = 0U;
  c7_info[87].mFileTimeLo = 0U;
  c7_info[87].mFileTimeHi = 0U;
  c7_info[88].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c7_info[88].name = "eml_index_minus";
  c7_info[88].dominantType = "double";
  c7_info[88].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c7_info[88].fileTimeLo = 1286851178U;
  c7_info[88].fileTimeHi = 0U;
  c7_info[88].mFileTimeLo = 0U;
  c7_info[88].mFileTimeHi = 0U;
  c7_info[89].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c7_info[89].name = "eml_int_forloop_overflow_check";
  c7_info[89].dominantType = "";
  c7_info[89].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c7_info[89].fileTimeLo = 1346542740U;
  c7_info[89].fileTimeHi = 0U;
  c7_info[89].mFileTimeLo = 0U;
  c7_info[89].mFileTimeHi = 0U;
  c7_info[90].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c7_info[90].name = "eml_index_plus";
  c7_info[90].dominantType = "double";
  c7_info[90].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c7_info[90].fileTimeLo = 1286851178U;
  c7_info[90].fileTimeHi = 0U;
  c7_info[90].mFileTimeLo = 0U;
  c7_info[90].mFileTimeHi = 0U;
  c7_info[91].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c7_info[91].name = "eml_index_plus";
  c7_info[91].dominantType = "coder.internal.indexInt";
  c7_info[91].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c7_info[91].fileTimeLo = 1286851178U;
  c7_info[91].fileTimeHi = 0U;
  c7_info[91].mFileTimeLo = 0U;
  c7_info[91].mFileTimeHi = 0U;
  c7_info[92].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c7_info[92].name = "abs";
  c7_info[92].dominantType = "double";
  c7_info[92].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c7_info[92].fileTimeLo = 1343862766U;
  c7_info[92].fileTimeHi = 0U;
  c7_info[92].mFileTimeLo = 0U;
  c7_info[92].mFileTimeHi = 0U;
  c7_info[93].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c7_info[93].name = "mtimes";
  c7_info[93].dominantType = "double";
  c7_info[93].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c7_info[93].fileTimeLo = 1289552092U;
  c7_info[93].fileTimeHi = 0U;
  c7_info[93].mFileTimeLo = 0U;
  c7_info[93].mFileTimeHi = 0U;
  c7_info[94].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c7_info[94].name = "realmin";
  c7_info[94].dominantType = "char";
  c7_info[94].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c7_info[94].fileTimeLo = 1307683642U;
  c7_info[94].fileTimeHi = 0U;
  c7_info[94].mFileTimeLo = 0U;
  c7_info[94].mFileTimeHi = 0U;
  c7_info[95].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c7_info[95].name = "eps";
  c7_info[95].dominantType = "char";
  c7_info[95].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c7_info[95].fileTimeLo = 1326760396U;
  c7_info[95].fileTimeHi = 0U;
  c7_info[95].mFileTimeLo = 0U;
  c7_info[95].mFileTimeHi = 0U;
  c7_info[96].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c7_info[96].name = "eml_is_float_class";
  c7_info[96].dominantType = "char";
  c7_info[96].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c7_info[96].fileTimeLo = 1286851182U;
  c7_info[96].fileTimeHi = 0U;
  c7_info[96].mFileTimeLo = 0U;
  c7_info[96].mFileTimeHi = 0U;
  c7_info[97].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c7_info[97].name = "eml_eps";
  c7_info[97].dominantType = "char";
  c7_info[97].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c7_info[97].fileTimeLo = 1326760396U;
  c7_info[97].fileTimeHi = 0U;
  c7_info[97].mFileTimeLo = 0U;
  c7_info[97].mFileTimeHi = 0U;
  c7_info[98].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c7_info[98].name = "eml_float_model";
  c7_info[98].dominantType = "char";
  c7_info[98].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c7_info[98].fileTimeLo = 1326760396U;
  c7_info[98].fileTimeHi = 0U;
  c7_info[98].mFileTimeLo = 0U;
  c7_info[98].mFileTimeHi = 0U;
  c7_info[99].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c7_info[99].name = "eml_error";
  c7_info[99].dominantType = "char";
  c7_info[99].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c7_info[99].fileTimeLo = 1343862758U;
  c7_info[99].fileTimeHi = 0U;
  c7_info[99].mFileTimeLo = 0U;
  c7_info[99].mFileTimeHi = 0U;
  c7_info[100].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c7_info[100].name = "intmin";
  c7_info[100].dominantType = "char";
  c7_info[100].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c7_info[100].fileTimeLo = 1311287718U;
  c7_info[100].fileTimeHi = 0U;
  c7_info[100].mFileTimeLo = 0U;
  c7_info[100].mFileTimeHi = 0U;
  c7_info[101].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c7_info[101].name = "eml_const_nonsingleton_dim";
  c7_info[101].dominantType = "double";
  c7_info[101].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c7_info[101].fileTimeLo = 1286851096U;
  c7_info[101].fileTimeHi = 0U;
  c7_info[101].mFileTimeLo = 0U;
  c7_info[101].mFileTimeHi = 0U;
  c7_info[102].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c7_info[102].name = "eml_scalar_eg";
  c7_info[102].dominantType = "double";
  c7_info[102].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[102].fileTimeLo = 1286851196U;
  c7_info[102].fileTimeHi = 0U;
  c7_info[102].mFileTimeLo = 0U;
  c7_info[102].mFileTimeHi = 0U;
  c7_info[103].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c7_info[103].name = "eml_index_class";
  c7_info[103].dominantType = "";
  c7_info[103].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[103].fileTimeLo = 1323202978U;
  c7_info[103].fileTimeHi = 0U;
  c7_info[103].mFileTimeLo = 0U;
  c7_info[103].mFileTimeHi = 0U;
  c7_info[104].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c7_info[104].name = "eml_index_class";
  c7_info[104].dominantType = "";
  c7_info[104].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[104].fileTimeLo = 1323202978U;
  c7_info[104].fileTimeHi = 0U;
  c7_info[104].mFileTimeLo = 0U;
  c7_info[104].mFileTimeHi = 0U;
  c7_info[105].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c7_info[105].name = "isnan";
  c7_info[105].dominantType = "double";
  c7_info[105].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c7_info[105].fileTimeLo = 1286851160U;
  c7_info[105].fileTimeHi = 0U;
  c7_info[105].mFileTimeLo = 0U;
  c7_info[105].mFileTimeHi = 0U;
  c7_info[106].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c7_info[106].name = "eml_index_plus";
  c7_info[106].dominantType = "coder.internal.indexInt";
  c7_info[106].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c7_info[106].fileTimeLo = 1286851178U;
  c7_info[106].fileTimeHi = 0U;
  c7_info[106].mFileTimeLo = 0U;
  c7_info[106].mFileTimeHi = 0U;
  c7_info[107].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c7_info[107].name = "eml_int_forloop_overflow_check";
  c7_info[107].dominantType = "";
  c7_info[107].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c7_info[107].fileTimeLo = 1346542740U;
  c7_info[107].fileTimeHi = 0U;
  c7_info[107].mFileTimeLo = 0U;
  c7_info[107].mFileTimeHi = 0U;
  c7_info[108].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c7_info[108].name = "eml_relop";
  c7_info[108].dominantType = "function_handle";
  c7_info[108].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c7_info[108].fileTimeLo = 1342483582U;
  c7_info[108].fileTimeHi = 0U;
  c7_info[108].mFileTimeLo = 0U;
  c7_info[108].mFileTimeHi = 0U;
  c7_info[109].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c7_info[109].name = "sqrt";
  c7_info[109].dominantType = "double";
  c7_info[109].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c7_info[109].fileTimeLo = 1343862786U;
  c7_info[109].fileTimeHi = 0U;
  c7_info[109].mFileTimeLo = 0U;
  c7_info[109].mFileTimeHi = 0U;
  c7_info[110].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c7_info[110].name = "eml_error";
  c7_info[110].dominantType = "char";
  c7_info[110].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c7_info[110].fileTimeLo = 1343862758U;
  c7_info[110].fileTimeHi = 0U;
  c7_info[110].mFileTimeLo = 0U;
  c7_info[110].mFileTimeHi = 0U;
  c7_info[111].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c7_info[111].name = "eml_scalar_sqrt";
  c7_info[111].dominantType = "double";
  c7_info[111].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c7_info[111].fileTimeLo = 1286851138U;
  c7_info[111].fileTimeHi = 0U;
  c7_info[111].mFileTimeLo = 0U;
  c7_info[111].mFileTimeHi = 0U;
  c7_info[112].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c7_info[112].name = "eml_xrotg";
  c7_info[112].dominantType = "double";
  c7_info[112].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m";
  c7_info[112].fileTimeLo = 1299109176U;
  c7_info[112].fileTimeHi = 0U;
  c7_info[112].mFileTimeLo = 0U;
  c7_info[112].mFileTimeHi = 0U;
  c7_info[113].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m";
  c7_info[113].name = "eml_blas_inline";
  c7_info[113].dominantType = "";
  c7_info[113].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c7_info[113].fileTimeLo = 1299109168U;
  c7_info[113].fileTimeHi = 0U;
  c7_info[113].mFileTimeLo = 0U;
  c7_info[113].mFileTimeHi = 0U;
  c7_info[114].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m";
  c7_info[114].name = "eml_refblas_xrotg";
  c7_info[114].dominantType = "double";
  c7_info[114].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c7_info[114].fileTimeLo = 1299109184U;
  c7_info[114].fileTimeHi = 0U;
  c7_info[114].mFileTimeLo = 0U;
  c7_info[114].mFileTimeHi = 0U;
  c7_info[115].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c7_info[115].name = "abs";
  c7_info[115].dominantType = "double";
  c7_info[115].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c7_info[115].fileTimeLo = 1343862766U;
  c7_info[115].fileTimeHi = 0U;
  c7_info[115].mFileTimeLo = 0U;
  c7_info[115].mFileTimeHi = 0U;
  c7_info[116].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c7_info[116].name = "mrdivide";
  c7_info[116].dominantType = "double";
  c7_info[116].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c7_info[116].fileTimeLo = 1357983948U;
  c7_info[116].fileTimeHi = 0U;
  c7_info[116].mFileTimeLo = 1319762366U;
  c7_info[116].mFileTimeHi = 0U;
  c7_info[117].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c7_info[117].name = "rdivide";
  c7_info[117].dominantType = "double";
  c7_info[117].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[117].fileTimeLo = 1346542788U;
  c7_info[117].fileTimeHi = 0U;
  c7_info[117].mFileTimeLo = 0U;
  c7_info[117].mFileTimeHi = 0U;
  c7_info[118].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[118].name = "eml_scalexp_compatible";
  c7_info[118].dominantType = "double";
  c7_info[118].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c7_info[118].fileTimeLo = 1286851196U;
  c7_info[118].fileTimeHi = 0U;
  c7_info[118].mFileTimeLo = 0U;
  c7_info[118].mFileTimeHi = 0U;
  c7_info[119].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[119].name = "eml_div";
  c7_info[119].dominantType = "double";
  c7_info[119].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c7_info[119].fileTimeLo = 1313380210U;
  c7_info[119].fileTimeHi = 0U;
  c7_info[119].mFileTimeLo = 0U;
  c7_info[119].mFileTimeHi = 0U;
  c7_info[120].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c7_info[120].name = "sqrt";
  c7_info[120].dominantType = "double";
  c7_info[120].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c7_info[120].fileTimeLo = 1343862786U;
  c7_info[120].fileTimeHi = 0U;
  c7_info[120].mFileTimeLo = 0U;
  c7_info[120].mFileTimeHi = 0U;
  c7_info[121].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m!eml_ceval_xrotg";
  c7_info[121].name = "eml_scalar_eg";
  c7_info[121].dominantType = "double";
  c7_info[121].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[121].fileTimeLo = 1286851196U;
  c7_info[121].fileTimeHi = 0U;
  c7_info[121].mFileTimeLo = 0U;
  c7_info[121].mFileTimeHi = 0U;
  c7_info[122].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/rank.m";
  c7_info[122].name = "length";
  c7_info[122].dominantType = "double";
  c7_info[122].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c7_info[122].fileTimeLo = 1303178606U;
  c7_info[122].fileTimeHi = 0U;
  c7_info[122].mFileTimeLo = 0U;
  c7_info[122].mFileTimeHi = 0U;
  c7_info[123].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength";
  c7_info[123].name = "eml_index_class";
  c7_info[123].dominantType = "";
  c7_info[123].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[123].fileTimeLo = 1323202978U;
  c7_info[123].fileTimeHi = 0U;
  c7_info[123].mFileTimeLo = 0U;
  c7_info[123].mFileTimeHi = 0U;
  c7_info[124].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/rank.m";
  c7_info[124].name = "eps";
  c7_info[124].dominantType = "double";
  c7_info[124].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c7_info[124].fileTimeLo = 1326760396U;
  c7_info[124].fileTimeHi = 0U;
  c7_info[124].mFileTimeLo = 0U;
  c7_info[124].mFileTimeHi = 0U;
  c7_info[125].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c7_info[125].name = "eml_mantissa_nbits";
  c7_info[125].dominantType = "char";
  c7_info[125].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_mantissa_nbits.m";
  c7_info[125].fileTimeLo = 1307683642U;
  c7_info[125].fileTimeHi = 0U;
  c7_info[125].mFileTimeLo = 0U;
  c7_info[125].mFileTimeHi = 0U;
  c7_info[126].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_mantissa_nbits.m";
  c7_info[126].name = "eml_float_model";
  c7_info[126].dominantType = "char";
  c7_info[126].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c7_info[126].fileTimeLo = 1326760396U;
  c7_info[126].fileTimeHi = 0U;
  c7_info[126].mFileTimeLo = 0U;
  c7_info[126].mFileTimeHi = 0U;
  c7_info[127].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c7_info[127].name = "eml_realmin";
  c7_info[127].dominantType = "char";
  c7_info[127].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c7_info[127].fileTimeLo = 1307683644U;
  c7_info[127].fileTimeHi = 0U;
  c7_info[127].mFileTimeLo = 0U;
  c7_info[127].mFileTimeHi = 0U;
}

static void c7_c_info_helper(c7_ResolvedFunctionInfo c7_info[134])
{
  c7_info[128].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c7_info[128].name = "eml_realmin_denormal";
  c7_info[128].dominantType = "char";
  c7_info[128].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin_denormal.m";
  c7_info[128].fileTimeLo = 1326760398U;
  c7_info[128].fileTimeHi = 0U;
  c7_info[128].mFileTimeLo = 0U;
  c7_info[128].mFileTimeHi = 0U;
  c7_info[129].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin_denormal.m";
  c7_info[129].name = "eml_float_model";
  c7_info[129].dominantType = "char";
  c7_info[129].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c7_info[129].fileTimeLo = 1326760396U;
  c7_info[129].fileTimeHi = 0U;
  c7_info[129].mFileTimeLo = 0U;
  c7_info[129].mFileTimeHi = 0U;
  c7_info[130].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c7_info[130].name = "abs";
  c7_info[130].dominantType = "double";
  c7_info[130].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c7_info[130].fileTimeLo = 1343862766U;
  c7_info[130].fileTimeHi = 0U;
  c7_info[130].mFileTimeLo = 0U;
  c7_info[130].mFileTimeHi = 0U;
  c7_info[131].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c7_info[131].name = "isfinite";
  c7_info[131].dominantType = "double";
  c7_info[131].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c7_info[131].fileTimeLo = 1286851158U;
  c7_info[131].fileTimeHi = 0U;
  c7_info[131].mFileTimeLo = 0U;
  c7_info[131].mFileTimeHi = 0U;
  c7_info[132].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c7_info[132].name = "eml_guarded_nan";
  c7_info[132].dominantType = "";
  c7_info[132].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c7_info[132].fileTimeLo = 1286851176U;
  c7_info[132].fileTimeHi = 0U;
  c7_info[132].mFileTimeLo = 0U;
  c7_info[132].mFileTimeHi = 0U;
  c7_info[133].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/rank.m";
  c7_info[133].name = "mtimes";
  c7_info[133].dominantType = "double";
  c7_info[133].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c7_info[133].fileTimeLo = 1289552092U;
  c7_info[133].fileTimeHi = 0U;
  c7_info[133].mFileTimeLo = 0U;
  c7_info[133].mFileTimeHi = 0U;
}

static real_T c7_rank(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
                      real_T c7_A[6])
{
  real_T c7_r;
  int32_T c7_k;
  int32_T c7_b_k;
  real_T c7_x;
  real_T c7_b_x;
  boolean_T c7_b;
  boolean_T c7_b0;
  real_T c7_c_x;
  boolean_T c7_b_b;
  boolean_T c7_b1;
  boolean_T c7_c_b;
  int32_T c7_i25;
  real_T c7_b_A[6];
  real_T c7_s[2];
  real_T c7_d_x;
  real_T c7_e_x;
  real_T c7_f_x;
  real_T c7_absxk;
  real_T c7_g_x;
  real_T c7_h_x;
  boolean_T c7_d_b;
  boolean_T c7_b2;
  real_T c7_i_x;
  boolean_T c7_e_b;
  boolean_T c7_b3;
  boolean_T c7_f_b;
  real_T c7_b_r;
  int32_T c7_exponent;
  int32_T c7_b_exponent;
  int32_T c7_c_exponent;
  real_T c7_g_b;
  real_T c7_tol;
  int32_T c7_c_k;
  real_T c7_d_k;
  boolean_T exitg1;
  c7_r = 0.0;
  for (c7_k = 1; c7_k < 7; c7_k++) {
    c7_b_k = c7_k;
    c7_x = c7_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c7_b_k), 1, 6, 1, 0) - 1];
    c7_b_x = c7_x;
    c7_b = muDoubleScalarIsInf(c7_b_x);
    c7_b0 = !c7_b;
    c7_c_x = c7_x;
    c7_b_b = muDoubleScalarIsNaN(c7_c_x);
    c7_b1 = !c7_b_b;
    c7_c_b = (c7_b0 && c7_b1);
    if (!c7_c_b) {
      c7_eml_error(chartInstance);
    }
  }

  for (c7_i25 = 0; c7_i25 < 6; c7_i25++) {
    c7_b_A[c7_i25] = c7_A[c7_i25];
  }

  c7_eml_matlab_zsvdc(chartInstance, c7_b_A, c7_s);
  c7_d_x = c7_s[0];
  c7_eml_realmin(chartInstance);
  c7_e_x = c7_d_x;
  c7_f_x = c7_e_x;
  c7_absxk = muDoubleScalarAbs(c7_f_x);
  c7_g_x = c7_absxk;
  c7_h_x = c7_g_x;
  c7_d_b = muDoubleScalarIsInf(c7_h_x);
  c7_b2 = !c7_d_b;
  c7_i_x = c7_g_x;
  c7_e_b = muDoubleScalarIsNaN(c7_i_x);
  c7_b3 = !c7_e_b;
  c7_f_b = (c7_b2 && c7_b3);
  if (c7_f_b) {
    if (c7_absxk <= 2.2250738585072014E-308) {
      c7_b_r = 4.94065645841247E-324;
    } else {
      frexp(c7_absxk, &c7_exponent);
      c7_b_exponent = c7_exponent;
      c7_c_exponent = c7_b_exponent;
      c7_c_exponent;
      c7_b_r = ldexp(1.0, c7_c_exponent - 53);
    }
  } else {
    c7_b_r = rtNaN;
  }

  c7_g_b = c7_b_r;
  c7_tol = 3.0 * c7_g_b;
  c7_c_k = 0;
  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c7_c_k < 2)) {
    c7_d_k = 1.0 + (real_T)c7_c_k;
    if (c7_s[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
         _SFD_INTEGER_CHECK("", c7_d_k), 1, 2, 1, 0) - 1] > c7_tol) {
      c7_r++;
      c7_c_k++;
    } else {
      exitg1 = TRUE;
    }
  }

  return c7_r;
}

static void c7_eml_error(SFc7_Final_Project_v3bInstanceStruct *chartInstance)
{
  int32_T c7_i26;
  static char_T c7_cv0[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'v', 'd', '_', 'm', 'a', 't', 'r', 'i', 'x', 'W', 'i',
    't', 'h', 'N', 'a', 'N', 'I', 'n', 'f' };

  char_T c7_u[33];
  const mxArray *c7_y = NULL;
  for (c7_i26 = 0; c7_i26 < 33; c7_i26++) {
    c7_u[c7_i26] = c7_cv0[c7_i26];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 33), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c7_y));
}

static void c7_eml_matlab_zsvdc(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance, real_T c7_A[6], real_T c7_S[2])
{
  int32_T c7_i27;
  real_T c7_e[3];
  int32_T c7_i28;
  real_T c7_work[2];
  int32_T c7_i29;
  real_T c7_b_A[6];
  real_T c7_nrm;
  real_T c7_absx;
  real_T c7_d;
  real_T c7_y;
  real_T c7_s[3];
  real_T c7_d2;
  int32_T c7_jj;
  int32_T c7_b_jj;
  int32_T c7_a;
  int32_T c7_c;
  int32_T c7_b;
  int32_T c7_b_c;
  int32_T c7_b_b;
  int32_T c7_qjj;
  int32_T c7_i30;
  real_T c7_c_A[6];
  int32_T c7_i31;
  real_T c7_d_A[6];
  real_T c7_t;
  int32_T c7_i32;
  real_T c7_b_e[3];
  real_T c7_b_absx;
  real_T c7_b_d;
  real_T c7_b_y;
  real_T c7_d3;
  int32_T c7_c_jj;
  int32_T c7_b_a;
  int32_T c7_c_c;
  int32_T c7_c_b;
  int32_T c7_d_c;
  int32_T c7_d_b;
  int32_T c7_qp1jj;
  int32_T c7_i33;
  real_T c7_e_A[6];
  int32_T c7_d_jj;
  int32_T c7_c_a;
  int32_T c7_e_c;
  int32_T c7_e_b;
  int32_T c7_f_c;
  int32_T c7_f_b;
  int32_T c7_i34;
  real_T c7_b_work[2];
  int32_T c7_m;
  int32_T c7_q;
  int32_T c7_b_q;
  real_T c7_rt;
  real_T c7_r;
  int32_T c7_d_a;
  int32_T c7_g_c;
  int32_T c7_e_a;
  int32_T c7_h_c;
  real_T c7_f_a;
  real_T c7_g_b;
  real_T c7_c_y;
  real_T c7_iter;
  real_T c7_tiny;
  real_T c7_snorm;
  int32_T c7_ii;
  int32_T c7_b_ii;
  real_T c7_varargin_1;
  real_T c7_varargin_2;
  real_T c7_b_varargin_2;
  real_T c7_varargin_3;
  real_T c7_x;
  real_T c7_d_y;
  real_T c7_b_x;
  real_T c7_e_y;
  real_T c7_xk;
  real_T c7_yk;
  real_T c7_c_x;
  real_T c7_f_y;
  real_T c7_maxval;
  real_T c7_b_varargin_1;
  real_T c7_c_varargin_2;
  real_T c7_d_varargin_2;
  real_T c7_b_varargin_3;
  real_T c7_d_x;
  real_T c7_g_y;
  real_T c7_e_x;
  real_T c7_h_y;
  real_T c7_b_xk;
  real_T c7_b_yk;
  real_T c7_f_x;
  real_T c7_i_y;
  int32_T c7_g_a;
  int32_T c7_h_a;
  int32_T c7_i35;
  boolean_T c7_overflow;
  int32_T c7_c_ii;
  int32_T c7_i_a;
  int32_T c7_i_c;
  real_T c7_test0;
  real_T c7_ztest0;
  real_T c7_h_b;
  real_T c7_j_y;
  real_T c7_i_b;
  real_T c7_k_y;
  int32_T c7_j_a;
  int32_T c7_j_c;
  real_T c7_kase;
  int32_T c7_qs;
  int32_T c7_b_m;
  int32_T c7_c_q;
  int32_T c7_k_a;
  int32_T c7_j_b;
  int32_T c7_l_a;
  int32_T c7_k_b;
  boolean_T c7_b_overflow;
  int32_T c7_d_ii;
  real_T c7_test;
  int32_T c7_m_a;
  int32_T c7_k_c;
  int32_T c7_n_a;
  int32_T c7_l_c;
  real_T c7_ztest;
  real_T c7_l_b;
  real_T c7_l_y;
  int32_T c7_o_a;
  int32_T c7_p_a;
  int32_T c7_m_c;
  real_T c7_f;
  int32_T c7_q_a;
  int32_T c7_n_c;
  int32_T c7_r_a;
  int32_T c7_i36;
  int32_T c7_d_q;
  int32_T c7_s_a;
  int32_T c7_m_b;
  int32_T c7_t_a;
  int32_T c7_n_b;
  boolean_T c7_c_overflow;
  int32_T c7_k;
  int32_T c7_b_k;
  real_T c7_t1;
  real_T c7_b_t1;
  real_T c7_b_f;
  real_T c7_sn;
  real_T c7_cs;
  real_T c7_b_cs;
  real_T c7_b_sn;
  int32_T c7_u_a;
  int32_T c7_km1;
  real_T c7_v_a;
  real_T c7_o_b;
  real_T c7_w_a;
  real_T c7_p_b;
  real_T c7_m_y;
  int32_T c7_x_a;
  int32_T c7_qm1;
  int32_T c7_e_q;
  int32_T c7_c_m;
  int32_T c7_y_a;
  int32_T c7_q_b;
  int32_T c7_ab_a;
  int32_T c7_r_b;
  boolean_T c7_d_overflow;
  int32_T c7_c_k;
  real_T c7_c_t1;
  real_T c7_unusedU0;
  real_T c7_c_sn;
  real_T c7_c_cs;
  real_T c7_bb_a;
  real_T c7_s_b;
  real_T c7_cb_a;
  real_T c7_t_b;
  real_T c7_n_y;
  int32_T c7_db_a;
  int32_T c7_mm1;
  real_T c7_d4;
  real_T c7_d5;
  real_T c7_d6;
  real_T c7_d7;
  real_T c7_d8;
  real_T c7_c_varargin_1[5];
  int32_T c7_ixstart;
  real_T c7_mtmp;
  real_T c7_g_x;
  boolean_T c7_u_b;
  int32_T c7_ix;
  int32_T c7_b_ix;
  real_T c7_h_x;
  boolean_T c7_v_b;
  int32_T c7_eb_a;
  int32_T c7_i37;
  boolean_T c7_e_overflow;
  int32_T c7_c_ix;
  real_T c7_fb_a;
  real_T c7_w_b;
  boolean_T c7_p;
  real_T c7_b_mtmp;
  real_T c7_scale;
  real_T c7_sm;
  real_T c7_smm1;
  real_T c7_emm1;
  real_T c7_sqds;
  real_T c7_eqds;
  real_T c7_gb_a;
  real_T c7_x_b;
  real_T c7_o_y;
  real_T c7_hb_a;
  real_T c7_y_b;
  real_T c7_p_y;
  real_T c7_ab_b;
  real_T c7_ib_a;
  real_T c7_bb_b;
  real_T c7_o_c;
  real_T c7_jb_a;
  real_T c7_cb_b;
  real_T c7_shift;
  real_T c7_kb_a;
  real_T c7_db_b;
  real_T c7_q_y;
  real_T c7_lb_a;
  real_T c7_eb_b;
  real_T c7_r_y;
  real_T c7_mb_a;
  real_T c7_fb_b;
  real_T c7_g;
  int32_T c7_f_q;
  int32_T c7_b_mm1;
  int32_T c7_nb_a;
  int32_T c7_gb_b;
  int32_T c7_ob_a;
  int32_T c7_hb_b;
  boolean_T c7_f_overflow;
  int32_T c7_d_k;
  int32_T c7_pb_a;
  int32_T c7_qb_a;
  int32_T c7_kp1;
  real_T c7_c_f;
  real_T c7_unusedU1;
  real_T c7_d_sn;
  real_T c7_d_cs;
  real_T c7_rb_a;
  real_T c7_ib_b;
  real_T c7_s_y;
  real_T c7_sb_a;
  real_T c7_jb_b;
  real_T c7_t_y;
  real_T c7_tb_a;
  real_T c7_kb_b;
  real_T c7_u_y;
  real_T c7_ub_a;
  real_T c7_lb_b;
  real_T c7_v_y;
  real_T c7_vb_a;
  real_T c7_mb_b;
  real_T c7_wb_a;
  real_T c7_nb_b;
  real_T c7_w_y;
  real_T c7_d_f;
  real_T c7_unusedU2;
  real_T c7_e_sn;
  real_T c7_e_cs;
  real_T c7_xb_a;
  real_T c7_ob_b;
  real_T c7_x_y;
  real_T c7_yb_a;
  real_T c7_pb_b;
  real_T c7_y_y;
  real_T c7_ac_a;
  real_T c7_qb_b;
  real_T c7_ab_y;
  real_T c7_bc_a;
  real_T c7_rb_b;
  real_T c7_bb_y;
  real_T c7_cc_a;
  real_T c7_sb_b;
  real_T c7_dc_a;
  real_T c7_tb_b;
  real_T c7_cb_y;
  int32_T c7_ec_a;
  int32_T c7_p_c;
  int32_T c7_e_k;
  int32_T c7_qp1;
  int32_T c7_fc_a;
  int32_T c7_gc_a;
  int32_T c7_hc_a;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T exitg4;
  boolean_T exitg5;
  boolean_T guard11 = FALSE;
  c7_eml_scalar_eg(chartInstance);
  for (c7_i27 = 0; c7_i27 < 3; c7_i27++) {
    c7_e[c7_i27] = 0.0;
  }

  for (c7_i28 = 0; c7_i28 < 2; c7_i28++) {
    c7_work[c7_i28] = 0.0;
  }

  for (c7_i29 = 0; c7_i29 < 6; c7_i29++) {
    c7_b_A[c7_i29] = c7_A[c7_i29];
  }

  c7_nrm = c7_eml_xnrm2(chartInstance, c7_b_A);
  if (c7_nrm > 0.0) {
    c7_absx = c7_nrm;
    c7_d = c7_A[0];
    if (c7_d < 0.0) {
      c7_y = -c7_absx;
    } else {
      c7_y = c7_absx;
    }

    c7_s[0] = c7_y;
    c7_d2 = c7_eml_div(chartInstance, 1.0, c7_s[0]);
    c7_c_eml_xscal(chartInstance, c7_d2, c7_A);
    c7_A[0]++;
    c7_s[0] = -c7_s[0];
  } else {
    c7_s[0] = 0.0;
  }

  for (c7_jj = 2; c7_jj < 4; c7_jj++) {
    c7_b_jj = c7_jj;
    c7_a = c7_b_jj;
    c7_c = c7_a;
    c7_b = c7_c - 1;
    c7_b_c = c7_b << 1;
    c7_b_b = c7_b_c + 1;
    c7_qjj = c7_b_b;
    if (c7_s[0] != 0.0) {
      for (c7_i30 = 0; c7_i30 < 6; c7_i30++) {
        c7_c_A[c7_i30] = c7_A[c7_i30];
      }

      for (c7_i31 = 0; c7_i31 < 6; c7_i31++) {
        c7_d_A[c7_i31] = c7_A[c7_i31];
      }

      c7_t = c7_eml_xdotc(chartInstance, c7_c_A, c7_d_A, c7_qjj);
      c7_t = -c7_eml_div(chartInstance, c7_t, c7_A[0]);
      c7_d_eml_xaxpy(chartInstance, c7_t, c7_A, c7_qjj);
    }

    c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c7_b_jj), 1, 3, 1, 0) - 1] = c7_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c7_qjj), 1, 6, 1, 0) - 1];
  }

  for (c7_i32 = 0; c7_i32 < 3; c7_i32++) {
    c7_b_e[c7_i32] = c7_e[c7_i32];
  }

  c7_nrm = c7_b_eml_xnrm2(chartInstance, c7_b_e);
  if (c7_nrm == 0.0) {
    c7_e[0] = 0.0;
  } else {
    c7_b_absx = c7_nrm;
    c7_b_d = c7_e[1];
    if (c7_b_d < 0.0) {
      c7_b_y = -c7_b_absx;
    } else {
      c7_b_y = c7_b_absx;
    }

    c7_e[0] = c7_b_y;
    c7_d3 = c7_eml_div(chartInstance, 1.0, c7_e[0]);
    c7_d_eml_xscal(chartInstance, c7_d3, c7_e);
    c7_e[1]++;
  }

  c7_e[0] = -c7_e[0];
  if (c7_e[0] != 0.0) {
    c7_work[1] = 0.0;
    for (c7_c_jj = 2; c7_c_jj < 4; c7_c_jj++) {
      c7_b_jj = c7_c_jj;
      c7_b_a = c7_b_jj;
      c7_c_c = c7_b_a;
      c7_c_b = c7_c_c - 1;
      c7_d_c = c7_c_b << 1;
      c7_d_b = c7_d_c;
      c7_qp1jj = c7_d_b;
      for (c7_i33 = 0; c7_i33 < 6; c7_i33++) {
        c7_e_A[c7_i33] = c7_A[c7_i33];
      }

      c7_e_eml_xaxpy(chartInstance, c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c7_b_jj), 1, 3, 1, 0) - 1],
                     c7_e_A, c7_qp1jj + 2, c7_work);
    }

    for (c7_d_jj = 2; c7_d_jj < 4; c7_d_jj++) {
      c7_b_jj = c7_d_jj;
      c7_t = c7_eml_div(chartInstance, -c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c7_b_jj), 1, 3, 1, 0) - 1],
                        c7_e[1]);
      c7_c_a = c7_b_jj;
      c7_e_c = c7_c_a;
      c7_e_b = c7_e_c - 1;
      c7_f_c = c7_e_b << 1;
      c7_f_b = c7_f_c;
      c7_qp1jj = c7_f_b;
      for (c7_i34 = 0; c7_i34 < 2; c7_i34++) {
        c7_b_work[c7_i34] = c7_work[c7_i34];
      }

      c7_f_eml_xaxpy(chartInstance, c7_t, c7_b_work, c7_A, c7_qp1jj + 2);
    }
  }

  c7_m = 3;
  c7_s[1] = c7_A[3];
  c7_s[2] = 0.0;
  c7_e[1] = c7_A[5];
  c7_e[2] = 0.0;
  for (c7_q = 1; c7_q < 4; c7_q++) {
    c7_b_q = c7_q;
    if (c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c7_b_q), 1, 3, 1, 0) - 1] != 0.0) {
      c7_rt = c7_abs(chartInstance, c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c7_b_q), 1, 3, 1, 0) - 1]);
      c7_r = c7_eml_div(chartInstance, c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c7_b_q), 1, 3, 1, 0) - 1], c7_rt);
      c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c7_b_q), 1, 3, 1, 0) - 1] = c7_rt;
      if (c7_b_q < 3) {
        c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c7_b_q), 1, 3, 1, 0) - 1] = c7_eml_div(chartInstance,
          c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c7_b_q), 1, 3, 1, 0) - 1], c7_r);
      }
    }

    if (c7_b_q < 3) {
      if (c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c7_b_q), 1, 3, 1, 0) - 1] != 0.0) {
        c7_rt = c7_abs(chartInstance, c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c7_b_q), 1, 3, 1, 0) - 1]);
        c7_r = c7_eml_div(chartInstance, c7_rt, c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK
                          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c7_b_q),
                           1, 3, 1, 0) - 1]);
        c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c7_b_q), 1, 3, 1, 0) - 1] = c7_rt;
        c7_d_a = c7_b_q;
        c7_g_c = c7_d_a;
        c7_e_a = c7_b_q;
        c7_h_c = c7_e_a;
        c7_f_a = c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c7_h_c + 1)), 1, 3, 1, 0) - 1];
        c7_g_b = c7_r;
        c7_c_y = c7_f_a * c7_g_b;
        c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c7_g_c + 1)), 1, 3, 1, 0) - 1] = c7_c_y;
      }
    }
  }

  c7_iter = 0.0;
  c7_realmin(chartInstance);
  c7_eps(chartInstance);
  c7_tiny = c7_eml_div(chartInstance, 2.2250738585072014E-308,
                       2.2204460492503131E-16);
  c7_snorm = 0.0;
  for (c7_ii = 1; c7_ii < 4; c7_ii++) {
    c7_b_ii = c7_ii;
    c7_varargin_1 = c7_abs(chartInstance, c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c7_b_ii), 1, 3, 1, 0) - 1]);
    c7_varargin_2 = c7_abs(chartInstance, c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c7_b_ii), 1, 3, 1, 0) - 1]);
    c7_b_varargin_2 = c7_varargin_1;
    c7_varargin_3 = c7_varargin_2;
    c7_x = c7_b_varargin_2;
    c7_d_y = c7_varargin_3;
    c7_b_x = c7_x;
    c7_e_y = c7_d_y;
    c7_b_eml_scalar_eg(chartInstance);
    c7_xk = c7_b_x;
    c7_yk = c7_e_y;
    c7_c_x = c7_xk;
    c7_f_y = c7_yk;
    c7_b_eml_scalar_eg(chartInstance);
    c7_maxval = muDoubleScalarMax(c7_c_x, c7_f_y);
    c7_b_varargin_1 = c7_snorm;
    c7_c_varargin_2 = c7_maxval;
    c7_d_varargin_2 = c7_b_varargin_1;
    c7_b_varargin_3 = c7_c_varargin_2;
    c7_d_x = c7_d_varargin_2;
    c7_g_y = c7_b_varargin_3;
    c7_e_x = c7_d_x;
    c7_h_y = c7_g_y;
    c7_b_eml_scalar_eg(chartInstance);
    c7_b_xk = c7_e_x;
    c7_b_yk = c7_h_y;
    c7_f_x = c7_b_xk;
    c7_i_y = c7_b_yk;
    c7_b_eml_scalar_eg(chartInstance);
    c7_snorm = muDoubleScalarMax(c7_f_x, c7_i_y);
  }

  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c7_m > 0)) {
    if (c7_iter >= 75.0) {
      c7_b_eml_error(chartInstance);
      exitg1 = TRUE;
    } else {
      c7_g_a = c7_m - 1;
      c7_b_q = c7_g_a;
      c7_h_a = c7_m;
      c7_i35 = c7_h_a;
      c7_overflow = FALSE;
      if (c7_overflow) {
        c7_check_forloop_overflow_error(chartInstance, c7_overflow);
      }

      c7_c_ii = c7_i35 - 1;
      guard3 = FALSE;
      guard4 = FALSE;
      exitg5 = FALSE;
      while ((exitg5 == FALSE) && (c7_c_ii > -1)) {
        c7_b_ii = c7_c_ii;
        c7_b_q = c7_b_ii;
        if (c7_b_ii == 0) {
          exitg5 = TRUE;
        } else {
          c7_i_a = c7_b_ii;
          c7_i_c = c7_i_a;
          c7_test0 = c7_abs(chartInstance, c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c7_b_ii), 1,
            3, 1, 0) - 1]) + c7_abs(chartInstance,
            c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                                      (real_T)(c7_i_c + 1)), 1, 3, 1, 0) - 1]);
          c7_ztest0 = c7_abs(chartInstance, c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c7_b_ii),
            1, 3, 1, 0) - 1]);
          c7_eps(chartInstance);
          c7_h_b = c7_test0;
          c7_j_y = 2.2204460492503131E-16 * c7_h_b;
          if (c7_ztest0 <= c7_j_y) {
            guard4 = TRUE;
            exitg5 = TRUE;
          } else if (c7_ztest0 <= c7_tiny) {
            guard4 = TRUE;
            exitg5 = TRUE;
          } else {
            guard11 = FALSE;
            if (c7_iter > 20.0) {
              c7_eps(chartInstance);
              c7_i_b = c7_snorm;
              c7_k_y = 2.2204460492503131E-16 * c7_i_b;
              if (c7_ztest0 <= c7_k_y) {
                guard3 = TRUE;
                exitg5 = TRUE;
              } else {
                guard11 = TRUE;
              }
            } else {
              guard11 = TRUE;
            }

            if (guard11 == TRUE) {
              c7_c_ii--;
              guard3 = FALSE;
              guard4 = FALSE;
            }
          }
        }
      }

      if (guard4 == TRUE) {
        guard3 = TRUE;
      }

      if (guard3 == TRUE) {
        c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c7_b_ii), 1, 3, 1, 0) - 1] = 0.0;
      }

      c7_j_a = c7_m;
      c7_j_c = c7_j_a;
      if (c7_b_q == c7_j_c - 1) {
        c7_kase = 4.0;
      } else {
        c7_qs = c7_m;
        c7_b_m = c7_m;
        c7_c_q = c7_b_q;
        c7_k_a = c7_b_m;
        c7_j_b = c7_c_q;
        c7_l_a = c7_k_a;
        c7_k_b = c7_j_b;
        if (c7_l_a < c7_k_b) {
          c7_b_overflow = FALSE;
        } else {
          c7_b_overflow = (c7_k_b < -2147483647);
        }

        if (c7_b_overflow) {
          c7_b_check_forloop_overflow_error(chartInstance, c7_b_overflow);
        }

        c7_d_ii = c7_b_m;
        guard2 = FALSE;
        exitg4 = FALSE;
        while ((exitg4 == FALSE) && (c7_d_ii >= c7_c_q)) {
          c7_b_ii = c7_d_ii;
          c7_qs = c7_b_ii;
          if (c7_b_ii == c7_b_q) {
            exitg4 = TRUE;
          } else {
            c7_test = 0.0;
            if (c7_b_ii < c7_m) {
              c7_test = c7_abs(chartInstance, c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
                "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c7_b_ii), 1, 3, 1, 0)
                               - 1]);
            }

            c7_m_a = c7_b_q;
            c7_k_c = c7_m_a;
            if (c7_b_ii > c7_k_c + 1) {
              c7_n_a = c7_b_ii;
              c7_l_c = c7_n_a;
              c7_test += c7_abs(chartInstance, c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
                "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c7_l_c - 1)), 1, 3,
                1, 0) - 1]);
            }

            c7_ztest = c7_abs(chartInstance, c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                               (int32_T)_SFD_INTEGER_CHECK("", (real_T)c7_b_ii),
              1, 3, 1, 0) - 1]);
            c7_eps(chartInstance);
            c7_l_b = c7_test;
            c7_l_y = 2.2204460492503131E-16 * c7_l_b;
            if (c7_ztest <= c7_l_y) {
              guard2 = TRUE;
              exitg4 = TRUE;
            } else if (c7_ztest <= c7_tiny) {
              guard2 = TRUE;
              exitg4 = TRUE;
            } else {
              c7_d_ii--;
              guard2 = FALSE;
            }
          }
        }

        if (guard2 == TRUE) {
          c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c7_b_ii), 1, 3, 1, 0) - 1] = 0.0;
        }

        if (c7_qs == c7_b_q) {
          c7_kase = 3.0;
        } else if (c7_qs == c7_m) {
          c7_kase = 1.0;
        } else {
          c7_kase = 2.0;
          c7_b_q = c7_qs;
        }
      }

      c7_o_a = c7_b_q + 1;
      c7_b_q = c7_o_a;
      switch ((int32_T)_SFD_INTEGER_CHECK("", c7_kase)) {
       case 1:
        c7_p_a = c7_m;
        c7_m_c = c7_p_a;
        c7_f = c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)(c7_m_c - 1)), 1, 3, 1, 0) - 1];
        c7_q_a = c7_m;
        c7_n_c = c7_q_a;
        c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c7_n_c - 1)), 1, 3, 1, 0) - 1] = 0.0;
        c7_r_a = c7_m - 1;
        c7_i36 = c7_r_a;
        c7_d_q = c7_b_q;
        c7_s_a = c7_i36;
        c7_m_b = c7_d_q;
        c7_t_a = c7_s_a;
        c7_n_b = c7_m_b;
        if (c7_t_a < c7_n_b) {
          c7_c_overflow = FALSE;
        } else {
          c7_c_overflow = (c7_n_b < -2147483647);
        }

        if (c7_c_overflow) {
          c7_b_check_forloop_overflow_error(chartInstance, c7_c_overflow);
        }

        for (c7_k = c7_i36; c7_k >= c7_d_q; c7_k--) {
          c7_b_k = c7_k;
          c7_t1 = c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c7_b_k), 1, 3, 1, 0) - 1];
          c7_b_t1 = c7_t1;
          c7_b_f = c7_f;
          c7_b_eml_xrotg(chartInstance, &c7_b_t1, &c7_b_f, &c7_cs, &c7_sn);
          c7_t1 = c7_b_t1;
          c7_f = c7_b_f;
          c7_b_cs = c7_cs;
          c7_b_sn = c7_sn;
          c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c7_b_k), 1, 3, 1, 0) - 1] = c7_t1;
          if (c7_b_k > c7_b_q) {
            c7_u_a = c7_b_k - 1;
            c7_km1 = c7_u_a;
            c7_v_a = -c7_b_sn;
            c7_o_b = c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c7_km1), 1, 3, 1, 0) - 1];
            c7_f = c7_v_a * c7_o_b;
            c7_w_a = c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c7_km1), 1, 3, 1, 0) - 1];
            c7_p_b = c7_b_cs;
            c7_m_y = c7_w_a * c7_p_b;
            c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c7_km1), 1, 3, 1, 0) - 1] = c7_m_y;
          }
        }
        break;

       case 2:
        c7_x_a = c7_b_q - 1;
        c7_qm1 = c7_x_a;
        c7_f = c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c7_qm1), 1, 3, 1, 0) - 1];
        c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c7_qm1), 1, 3, 1, 0) - 1] = 0.0;
        c7_e_q = c7_b_q;
        c7_c_m = c7_m;
        c7_y_a = c7_e_q;
        c7_q_b = c7_c_m;
        c7_ab_a = c7_y_a;
        c7_r_b = c7_q_b;
        if (c7_ab_a > c7_r_b) {
          c7_d_overflow = FALSE;
        } else {
          c7_d_overflow = (c7_r_b > 2147483646);
        }

        if (c7_d_overflow) {
          c7_b_check_forloop_overflow_error(chartInstance, c7_d_overflow);
        }

        for (c7_c_k = c7_e_q; c7_c_k <= c7_c_m; c7_c_k++) {
          c7_b_k = c7_c_k;
          c7_t1 = c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c7_b_k), 1, 3, 1, 0) - 1];
          c7_c_t1 = c7_t1;
          c7_unusedU0 = c7_f;
          c7_b_eml_xrotg(chartInstance, &c7_c_t1, &c7_unusedU0, &c7_c_cs,
                         &c7_c_sn);
          c7_t1 = c7_c_t1;
          c7_b_cs = c7_c_cs;
          c7_b_sn = c7_c_sn;
          c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c7_b_k), 1, 3, 1, 0) - 1] = c7_t1;
          c7_bb_a = -c7_b_sn;
          c7_s_b = c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c7_b_k), 1, 3, 1, 0) - 1];
          c7_f = c7_bb_a * c7_s_b;
          c7_cb_a = c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c7_b_k), 1, 3, 1, 0) - 1];
          c7_t_b = c7_b_cs;
          c7_n_y = c7_cb_a * c7_t_b;
          c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c7_b_k), 1, 3, 1, 0) - 1] = c7_n_y;
        }
        break;

       case 3:
        c7_db_a = c7_m - 1;
        c7_mm1 = c7_db_a;
        c7_d4 = c7_abs(chartInstance, c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c7_m), 1, 3, 1, 0) - 1]);
        c7_d5 = c7_abs(chartInstance, c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c7_mm1), 1, 3, 1, 0) - 1]);
        c7_d6 = c7_abs(chartInstance, c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c7_mm1), 1, 3, 1, 0) - 1]);
        c7_d7 = c7_abs(chartInstance, c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c7_b_q), 1, 3, 1, 0) - 1]);
        c7_d8 = c7_abs(chartInstance, c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c7_b_q), 1, 3, 1, 0) - 1]);
        c7_c_varargin_1[0] = c7_d4;
        c7_c_varargin_1[1] = c7_d5;
        c7_c_varargin_1[2] = c7_d6;
        c7_c_varargin_1[3] = c7_d7;
        c7_c_varargin_1[4] = c7_d8;
        c7_ixstart = 1;
        c7_mtmp = c7_c_varargin_1[0];
        c7_g_x = c7_mtmp;
        c7_u_b = muDoubleScalarIsNaN(c7_g_x);
        if (c7_u_b) {
          c7_ix = 2;
          exitg2 = FALSE;
          while ((exitg2 == FALSE) && (c7_ix < 6)) {
            c7_b_ix = c7_ix;
            c7_ixstart = c7_b_ix;
            c7_h_x = c7_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c7_b_ix), 1, 5, 1, 0) - 1];
            c7_v_b = muDoubleScalarIsNaN(c7_h_x);
            if (!c7_v_b) {
              c7_mtmp = c7_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c7_b_ix), 1, 5, 1, 0) - 1];
              exitg2 = TRUE;
            } else {
              c7_ix++;
            }
          }
        }

        if (c7_ixstart < 5) {
          c7_eb_a = c7_ixstart;
          c7_i37 = c7_eb_a;
          c7_e_overflow = FALSE;
          if (c7_e_overflow) {
            c7_b_check_forloop_overflow_error(chartInstance, c7_e_overflow);
          }

          for (c7_c_ix = c7_i37 + 1; c7_c_ix < 6; c7_c_ix++) {
            c7_b_ix = c7_c_ix;
            c7_fb_a = c7_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c7_b_ix), 1, 5, 1, 0) - 1];
            c7_w_b = c7_mtmp;
            c7_p = (c7_fb_a > c7_w_b);
            if (c7_p) {
              c7_mtmp = c7_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c7_b_ix), 1, 5, 1, 0) - 1];
            }
          }
        }

        c7_b_mtmp = c7_mtmp;
        c7_scale = c7_b_mtmp;
        c7_sm = c7_eml_div(chartInstance, c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c7_m), 1, 3, 1, 0) - 1],
                           c7_scale);
        c7_smm1 = c7_eml_div(chartInstance, c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c7_mm1), 1,
          3, 1, 0) - 1], c7_scale);
        c7_emm1 = c7_eml_div(chartInstance, c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c7_mm1), 1,
          3, 1, 0) - 1], c7_scale);
        c7_sqds = c7_eml_div(chartInstance, c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c7_b_q), 1,
          3, 1, 0) - 1], c7_scale);
        c7_eqds = c7_eml_div(chartInstance, c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c7_b_q), 1,
          3, 1, 0) - 1], c7_scale);
        c7_gb_a = c7_smm1 + c7_sm;
        c7_x_b = c7_smm1 - c7_sm;
        c7_o_y = c7_gb_a * c7_x_b;
        c7_hb_a = c7_emm1;
        c7_y_b = c7_emm1;
        c7_p_y = c7_hb_a * c7_y_b;
        c7_ab_b = c7_eml_div(chartInstance, c7_o_y + c7_p_y, 2.0);
        c7_ib_a = c7_sm;
        c7_bb_b = c7_emm1;
        c7_o_c = c7_ib_a * c7_bb_b;
        c7_jb_a = c7_o_c;
        c7_cb_b = c7_o_c;
        c7_o_c = c7_jb_a * c7_cb_b;
        c7_shift = 0.0;
        guard1 = FALSE;
        if (c7_ab_b != 0.0) {
          guard1 = TRUE;
        } else {
          if (c7_o_c != 0.0) {
            guard1 = TRUE;
          }
        }

        if (guard1 == TRUE) {
          c7_kb_a = c7_ab_b;
          c7_db_b = c7_ab_b;
          c7_q_y = c7_kb_a * c7_db_b;
          c7_shift = c7_q_y + c7_o_c;
          c7_b_sqrt(chartInstance, &c7_shift);
          if (c7_ab_b < 0.0) {
            c7_shift = -c7_shift;
          }

          c7_shift = c7_eml_div(chartInstance, c7_o_c, c7_ab_b + c7_shift);
        }

        c7_lb_a = c7_sqds + c7_sm;
        c7_eb_b = c7_sqds - c7_sm;
        c7_r_y = c7_lb_a * c7_eb_b;
        c7_f = c7_r_y + c7_shift;
        c7_mb_a = c7_sqds;
        c7_fb_b = c7_eqds;
        c7_g = c7_mb_a * c7_fb_b;
        c7_f_q = c7_b_q;
        c7_b_mm1 = c7_mm1;
        c7_nb_a = c7_f_q;
        c7_gb_b = c7_b_mm1;
        c7_ob_a = c7_nb_a;
        c7_hb_b = c7_gb_b;
        if (c7_ob_a > c7_hb_b) {
          c7_f_overflow = FALSE;
        } else {
          c7_f_overflow = (c7_hb_b > 2147483646);
        }

        if (c7_f_overflow) {
          c7_b_check_forloop_overflow_error(chartInstance, c7_f_overflow);
        }

        for (c7_d_k = c7_f_q; c7_d_k <= c7_b_mm1; c7_d_k++) {
          c7_b_k = c7_d_k;
          c7_pb_a = c7_b_k;
          c7_km1 = c7_pb_a;
          c7_qb_a = c7_b_k + 1;
          c7_kp1 = c7_qb_a;
          c7_c_f = c7_f;
          c7_unusedU1 = c7_g;
          c7_b_eml_xrotg(chartInstance, &c7_c_f, &c7_unusedU1, &c7_d_cs,
                         &c7_d_sn);
          c7_f = c7_c_f;
          c7_b_cs = c7_d_cs;
          c7_b_sn = c7_d_sn;
          if (c7_b_k > c7_b_q) {
            c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)(c7_km1 - 1)), 1, 3, 1, 0) - 1] = c7_f;
          }

          c7_rb_a = c7_b_cs;
          c7_ib_b = c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c7_b_k), 1, 3, 1, 0) - 1];
          c7_s_y = c7_rb_a * c7_ib_b;
          c7_sb_a = c7_b_sn;
          c7_jb_b = c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c7_b_k), 1, 3, 1, 0) - 1];
          c7_t_y = c7_sb_a * c7_jb_b;
          c7_f = c7_s_y + c7_t_y;
          c7_tb_a = c7_b_cs;
          c7_kb_b = c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c7_b_k), 1, 3, 1, 0) - 1];
          c7_u_y = c7_tb_a * c7_kb_b;
          c7_ub_a = c7_b_sn;
          c7_lb_b = c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c7_b_k), 1, 3, 1, 0) - 1];
          c7_v_y = c7_ub_a * c7_lb_b;
          c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c7_b_k), 1, 3, 1, 0) - 1] = c7_u_y - c7_v_y;
          c7_vb_a = c7_b_sn;
          c7_mb_b = c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c7_kp1), 1, 3, 1, 0) - 1];
          c7_g = c7_vb_a * c7_mb_b;
          c7_wb_a = c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c7_kp1), 1, 3, 1, 0) - 1];
          c7_nb_b = c7_b_cs;
          c7_w_y = c7_wb_a * c7_nb_b;
          c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c7_kp1), 1, 3, 1, 0) - 1] = c7_w_y;
          c7_d_f = c7_f;
          c7_unusedU2 = c7_g;
          c7_b_eml_xrotg(chartInstance, &c7_d_f, &c7_unusedU2, &c7_e_cs,
                         &c7_e_sn);
          c7_f = c7_d_f;
          c7_b_cs = c7_e_cs;
          c7_b_sn = c7_e_sn;
          c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c7_b_k), 1, 3, 1, 0) - 1] = c7_f;
          c7_xb_a = c7_b_cs;
          c7_ob_b = c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c7_b_k), 1, 3, 1, 0) - 1];
          c7_x_y = c7_xb_a * c7_ob_b;
          c7_yb_a = c7_b_sn;
          c7_pb_b = c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c7_kp1), 1, 3, 1, 0) - 1];
          c7_y_y = c7_yb_a * c7_pb_b;
          c7_f = c7_x_y + c7_y_y;
          c7_ac_a = -c7_b_sn;
          c7_qb_b = c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c7_b_k), 1, 3, 1, 0) - 1];
          c7_ab_y = c7_ac_a * c7_qb_b;
          c7_bc_a = c7_b_cs;
          c7_rb_b = c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c7_kp1), 1, 3, 1, 0) - 1];
          c7_bb_y = c7_bc_a * c7_rb_b;
          c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c7_kp1), 1, 3, 1, 0) - 1] = c7_ab_y + c7_bb_y;
          c7_cc_a = c7_b_sn;
          c7_sb_b = c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c7_kp1), 1, 3, 1, 0) - 1];
          c7_g = c7_cc_a * c7_sb_b;
          c7_dc_a = c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c7_kp1), 1, 3, 1, 0) - 1];
          c7_tb_b = c7_b_cs;
          c7_cb_y = c7_dc_a * c7_tb_b;
          c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c7_kp1), 1, 3, 1, 0) - 1] = c7_cb_y;
        }

        c7_ec_a = c7_m;
        c7_p_c = c7_ec_a;
        c7_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c7_p_c - 1)), 1, 3, 1, 0) - 1] = c7_f;
        c7_iter++;
        break;

       default:
        if (c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c7_b_q), 1, 3, 1, 0) - 1] < 0.0) {
          c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c7_b_q), 1, 3, 1, 0) - 1] =
            -c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c7_b_q), 1, 3, 1, 0) - 1];
        }

        c7_fc_a = c7_b_q + 1;
        c7_qp1 = c7_fc_a;
        exitg3 = FALSE;
        while ((exitg3 == FALSE) && (c7_b_q < 3)) {
          if (c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c7_b_q), 1, 3, 1, 0) - 1] <
              c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c7_qp1), 1, 3, 1, 0) - 1]) {
            c7_rt = c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c7_b_q), 1, 3, 1, 0) - 1];
            c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c7_b_q), 1, 3, 1, 0) - 1] =
              c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c7_qp1), 1, 3, 1, 0) - 1];
            c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c7_qp1), 1, 3, 1, 0) - 1] = c7_rt;
            c7_b_q = c7_qp1;
            c7_hc_a = c7_b_q + 1;
            c7_qp1 = c7_hc_a;
          } else {
            exitg3 = TRUE;
          }
        }

        c7_iter = 0.0;
        c7_gc_a = c7_m - 1;
        c7_m = c7_gc_a;
        break;
      }
    }
  }

  for (c7_e_k = 1; c7_e_k < 3; c7_e_k++) {
    c7_b_k = c7_e_k;
    c7_S[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c7_b_k), 1, 2, 1, 0) - 1] = c7_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c7_b_k), 1, 3, 1, 0) - 1];
  }
}

static void c7_eml_scalar_eg(SFc7_Final_Project_v3bInstanceStruct *chartInstance)
{
}

static real_T c7_eml_xnrm2(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_x[6])
{
  real_T c7_y;
  real_T c7_scale;
  int32_T c7_k;
  int32_T c7_b_k;
  real_T c7_b_x;
  real_T c7_c_x;
  real_T c7_absxk;
  real_T c7_t;
  c7_y = 0.0;
  c7_eml_realmin(chartInstance);
  c7_scale = 2.2250738585072014E-308;
  for (c7_k = 1; c7_k < 3; c7_k++) {
    c7_b_k = c7_k;
    c7_b_x = c7_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c7_b_k), 1, 6, 1, 0) - 1];
    c7_c_x = c7_b_x;
    c7_absxk = muDoubleScalarAbs(c7_c_x);
    if (c7_absxk > c7_scale) {
      c7_t = c7_scale / c7_absxk;
      c7_y = 1.0 + c7_y * c7_t * c7_t;
      c7_scale = c7_absxk;
    } else {
      c7_t = c7_absxk / c7_scale;
      c7_y += c7_t * c7_t;
    }
  }

  return c7_scale * muDoubleScalarSqrt(c7_y);
}

static void c7_realmin(SFc7_Final_Project_v3bInstanceStruct *chartInstance)
{
  c7_eml_realmin(chartInstance);
}

static void c7_eml_realmin(SFc7_Final_Project_v3bInstanceStruct *chartInstance)
{
}

static real_T c7_abs(SFc7_Final_Project_v3bInstanceStruct *chartInstance, real_T
                     c7_x)
{
  real_T c7_b_x;
  c7_b_x = c7_x;
  return muDoubleScalarAbs(c7_b_x);
}

static real_T c7_eml_div(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_x, real_T c7_y)
{
  return c7_x / c7_y;
}

static void c7_eml_xscal(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_a, real_T c7_x[6], real_T c7_b_x[6])
{
  int32_T c7_i38;
  for (c7_i38 = 0; c7_i38 < 6; c7_i38++) {
    c7_b_x[c7_i38] = c7_x[c7_i38];
  }

  c7_c_eml_xscal(chartInstance, c7_a, c7_b_x);
}

static real_T c7_eml_xdotc(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_x[6], real_T c7_y[6], int32_T c7_iy0)
{
  real_T c7_d;
  int32_T c7_b_iy0;
  int32_T c7_c_iy0;
  int32_T c7_d_iy0;
  int32_T c7_e_iy0;
  int32_T c7_ix;
  int32_T c7_iy;
  int32_T c7_k;
  int32_T c7_a;
  int32_T c7_b_a;
  c7_b_iy0 = c7_iy0;
  c7_c_iy0 = c7_b_iy0;
  c7_d_iy0 = c7_c_iy0;
  c7_e_iy0 = c7_d_iy0;
  c7_d = 0.0;
  c7_ix = 1;
  c7_iy = c7_e_iy0;
  for (c7_k = 1; c7_k < 3; c7_k++) {
    c7_d += c7_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c7_ix), 1, 6, 1, 0) - 1] * c7_y[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c7_iy), 1, 6, 1, 0) - 1];
    c7_a = c7_ix + 1;
    c7_ix = c7_a;
    c7_b_a = c7_iy + 1;
    c7_iy = c7_b_a;
  }

  return c7_d;
}

static void c7_eml_xaxpy(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_a, real_T c7_y[6], int32_T c7_iy0, real_T c7_b_y[6])
{
  int32_T c7_i39;
  for (c7_i39 = 0; c7_i39 < 6; c7_i39++) {
    c7_b_y[c7_i39] = c7_y[c7_i39];
  }

  c7_d_eml_xaxpy(chartInstance, c7_a, c7_b_y, c7_iy0);
}

static real_T c7_b_eml_xnrm2(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_x[3])
{
  real_T c7_y;
  real_T c7_scale;
  int32_T c7_k;
  int32_T c7_b_k;
  real_T c7_b_x;
  real_T c7_c_x;
  real_T c7_absxk;
  real_T c7_t;
  c7_y = 0.0;
  c7_eml_realmin(chartInstance);
  c7_scale = 2.2250738585072014E-308;
  for (c7_k = 2; c7_k < 4; c7_k++) {
    c7_b_k = c7_k;
    c7_b_x = c7_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c7_b_k), 1, 3, 1, 0) - 1];
    c7_c_x = c7_b_x;
    c7_absxk = muDoubleScalarAbs(c7_c_x);
    if (c7_absxk > c7_scale) {
      c7_t = c7_scale / c7_absxk;
      c7_y = 1.0 + c7_y * c7_t * c7_t;
      c7_scale = c7_absxk;
    } else {
      c7_t = c7_absxk / c7_scale;
      c7_y += c7_t * c7_t;
    }
  }

  return c7_scale * muDoubleScalarSqrt(c7_y);
}

static void c7_b_eml_xscal(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_a, real_T c7_x[3], real_T c7_b_x[3])
{
  int32_T c7_i40;
  for (c7_i40 = 0; c7_i40 < 3; c7_i40++) {
    c7_b_x[c7_i40] = c7_x[c7_i40];
  }

  c7_d_eml_xscal(chartInstance, c7_a, c7_b_x);
}

static void c7_b_eml_xaxpy(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_a, real_T c7_x[6], int32_T c7_ix0, real_T c7_y[2], real_T c7_b_y[2])
{
  int32_T c7_i41;
  int32_T c7_i42;
  real_T c7_b_x[6];
  for (c7_i41 = 0; c7_i41 < 2; c7_i41++) {
    c7_b_y[c7_i41] = c7_y[c7_i41];
  }

  for (c7_i42 = 0; c7_i42 < 6; c7_i42++) {
    c7_b_x[c7_i42] = c7_x[c7_i42];
  }

  c7_e_eml_xaxpy(chartInstance, c7_a, c7_b_x, c7_ix0, c7_b_y);
}

static void c7_c_eml_xaxpy(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_a, real_T c7_x[2], real_T c7_y[6], int32_T c7_iy0, real_T c7_b_y[6])
{
  int32_T c7_i43;
  int32_T c7_i44;
  real_T c7_b_x[2];
  for (c7_i43 = 0; c7_i43 < 6; c7_i43++) {
    c7_b_y[c7_i43] = c7_y[c7_i43];
  }

  for (c7_i44 = 0; c7_i44 < 2; c7_i44++) {
    c7_b_x[c7_i44] = c7_x[c7_i44];
  }

  c7_f_eml_xaxpy(chartInstance, c7_a, c7_b_x, c7_b_y, c7_iy0);
}

static void c7_eps(SFc7_Final_Project_v3bInstanceStruct *chartInstance)
{
}

static void c7_b_eml_scalar_eg(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance)
{
}

static void c7_b_eml_error(SFc7_Final_Project_v3bInstanceStruct *chartInstance)
{
  int32_T c7_i45;
  static char_T c7_cv1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'v', 'd', '_', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r',
    'g', 'e', 'n', 'c', 'e' };

  char_T c7_u[30];
  const mxArray *c7_y = NULL;
  for (c7_i45 = 0; c7_i45 < 30; c7_i45++) {
    c7_u[c7_i45] = c7_cv1[c7_i45];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c7_y));
}

static void c7_check_forloop_overflow_error(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance, boolean_T c7_overflow)
{
  int32_T c7_i46;
  static char_T c7_cv2[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c7_u[34];
  const mxArray *c7_y = NULL;
  int32_T c7_i47;
  static char_T c7_cv3[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't', 'e',
    'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  char_T c7_b_u[23];
  const mxArray *c7_b_y = NULL;
  if (!c7_overflow) {
  } else {
    for (c7_i46 = 0; c7_i46 < 34; c7_i46++) {
      c7_u[c7_i46] = c7_cv2[c7_i46];
    }

    c7_y = NULL;
    sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c7_i47 = 0; c7_i47 < 23; c7_i47++) {
      c7_b_u[c7_i47] = c7_cv3[c7_i47];
    }

    c7_b_y = NULL;
    sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_b_u, 10, 0U, 1U, 0U, 2, 1, 23),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c7_y, 14, c7_b_y));
  }
}

static void c7_b_check_forloop_overflow_error
  (SFc7_Final_Project_v3bInstanceStruct *chartInstance, boolean_T c7_overflow)
{
  int32_T c7_i48;
  static char_T c7_cv4[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c7_u[34];
  const mxArray *c7_y = NULL;
  int32_T c7_i49;
  static char_T c7_cv5[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't', 'e',
    'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  char_T c7_b_u[23];
  const mxArray *c7_b_y = NULL;
  if (!c7_overflow) {
  } else {
    for (c7_i48 = 0; c7_i48 < 34; c7_i48++) {
      c7_u[c7_i48] = c7_cv4[c7_i48];
    }

    c7_y = NULL;
    sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c7_i49 = 0; c7_i49 < 23; c7_i49++) {
      c7_b_u[c7_i49] = c7_cv5[c7_i49];
    }

    c7_b_y = NULL;
    sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_b_u, 10, 0U, 1U, 0U, 2, 1, 23),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c7_y, 14, c7_b_y));
  }
}

static real_T c7_sqrt(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
                      real_T c7_x)
{
  real_T c7_b_x;
  c7_b_x = c7_x;
  c7_b_sqrt(chartInstance, &c7_b_x);
  return c7_b_x;
}

static void c7_c_eml_error(SFc7_Final_Project_v3bInstanceStruct *chartInstance)
{
  int32_T c7_i50;
  static char_T c7_cv6[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c7_u[30];
  const mxArray *c7_y = NULL;
  int32_T c7_i51;
  static char_T c7_cv7[4] = { 's', 'q', 'r', 't' };

  char_T c7_b_u[4];
  const mxArray *c7_b_y = NULL;
  for (c7_i50 = 0; c7_i50 < 30; c7_i50++) {
    c7_u[c7_i50] = c7_cv6[c7_i50];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  for (c7_i51 = 0; c7_i51 < 4; c7_i51++) {
    c7_b_u[c7_i51] = c7_cv7[c7_i51];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c7_y, 14, c7_b_y));
}

static void c7_eml_xrotg(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_a, real_T c7_b, real_T *c7_b_a, real_T *c7_b_b, real_T *c7_c, real_T
  *c7_s)
{
  *c7_b_a = c7_a;
  *c7_b_b = c7_b;
  c7_b_eml_xrotg(chartInstance, c7_b_a, c7_b_b, c7_c, c7_s);
}

static const mxArray *c7_f_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_Final_Project_v3bInstanceStruct *chartInstance;
  chartInstance = (SFc7_Final_Project_v3bInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(int32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static int32_T c7_f_emlrt_marshallIn(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_y;
  int32_T c7_i52;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i52, 1, 6, 0U, 0, 0U, 0);
  c7_y = c7_i52;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_sfEvent;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_y;
  SFc7_Final_Project_v3bInstanceStruct *chartInstance;
  chartInstance = (SFc7_Final_Project_v3bInstanceStruct *)chartInstanceVoid;
  c7_b_sfEvent = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_sfEvent),
    &c7_thisId);
  sf_mex_destroy(&c7_b_sfEvent);
  *(int32_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static uint8_T c7_g_emlrt_marshallIn(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance, const mxArray *c7_b_is_active_c7_Final_Project_v3b, const
  char_T *c7_identifier)
{
  uint8_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_is_active_c7_Final_Project_v3b), &c7_thisId);
  sf_mex_destroy(&c7_b_is_active_c7_Final_Project_v3b);
  return c7_y;
}

static uint8_T c7_h_emlrt_marshallIn(SFc7_Final_Project_v3bInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_y;
  uint8_T c7_u0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u0, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_u0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_c_eml_xscal(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_a, real_T c7_x[6])
{
  real_T c7_b_a;
  real_T c7_c_a;
  int32_T c7_k;
  int32_T c7_b_k;
  c7_b_a = c7_a;
  c7_c_a = c7_b_a;
  for (c7_k = 1; c7_k < 3; c7_k++) {
    c7_b_k = c7_k;
    c7_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c7_b_k), 1, 6, 1, 0) - 1] = c7_c_a * c7_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c7_b_k), 1, 6, 1, 0) - 1];
  }
}

static void c7_d_eml_xaxpy(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_a, real_T c7_y[6], int32_T c7_iy0)
{
  real_T c7_b_a;
  int32_T c7_b_iy0;
  real_T c7_c_a;
  int32_T c7_c_iy0;
  int32_T c7_ix;
  int32_T c7_d_a;
  int32_T c7_iy;
  int32_T c7_k;
  int32_T c7_e_a;
  int32_T c7_c;
  int32_T c7_f_a;
  int32_T c7_b_c;
  int32_T c7_g_a;
  int32_T c7_c_c;
  int32_T c7_h_a;
  int32_T c7_i_a;
  c7_b_a = c7_a;
  c7_b_iy0 = c7_iy0;
  c7_c_a = c7_b_a;
  c7_c_iy0 = c7_b_iy0;
  if (c7_c_a == 0.0) {
  } else {
    c7_ix = 0;
    c7_d_a = c7_c_iy0 - 1;
    c7_iy = c7_d_a;
    for (c7_k = 0; c7_k < 2; c7_k++) {
      c7_e_a = c7_iy;
      c7_c = c7_e_a;
      c7_f_a = c7_iy;
      c7_b_c = c7_f_a;
      c7_g_a = c7_ix;
      c7_c_c = c7_g_a;
      c7_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c7_c + 1)), 1, 6, 1, 0) - 1] = c7_y[_SFD_EML_ARRAY_BOUNDS_CHECK
        ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c7_b_c + 1)), 1, 6, 1, 0)
        - 1] + c7_c_a * c7_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)(c7_c_c + 1)), 1, 6, 1, 0) - 1];
      c7_h_a = c7_ix + 1;
      c7_ix = c7_h_a;
      c7_i_a = c7_iy + 1;
      c7_iy = c7_i_a;
    }
  }
}

static void c7_d_eml_xscal(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_a, real_T c7_x[3])
{
  real_T c7_b_a;
  real_T c7_c_a;
  int32_T c7_k;
  int32_T c7_b_k;
  c7_b_a = c7_a;
  c7_c_a = c7_b_a;
  for (c7_k = 2; c7_k < 4; c7_k++) {
    c7_b_k = c7_k;
    c7_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c7_b_k), 1, 3, 1, 0) - 1] = c7_c_a * c7_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c7_b_k), 1, 3, 1, 0) - 1];
  }
}

static void c7_e_eml_xaxpy(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_a, real_T c7_x[6], int32_T c7_ix0, real_T c7_y[2])
{
  real_T c7_b_a;
  int32_T c7_b_ix0;
  real_T c7_c_a;
  int32_T c7_c_ix0;
  int32_T c7_d_a;
  int32_T c7_ix;
  int32_T c7_e_a;
  int32_T c7_c;
  c7_b_a = c7_a;
  c7_b_ix0 = c7_ix0;
  c7_c_a = c7_b_a;
  c7_c_ix0 = c7_b_ix0;
  if (c7_c_a == 0.0) {
  } else {
    c7_d_a = c7_c_ix0;
    c7_ix = c7_d_a;
    c7_e_a = c7_ix - 1;
    c7_c = c7_e_a;
    c7_y[1] += c7_c_a * c7_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)(c7_c + 1)), 1, 6, 1, 0) - 1];
  }
}

static void c7_f_eml_xaxpy(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T c7_a, real_T c7_x[2], real_T c7_y[6], int32_T c7_iy0)
{
  real_T c7_b_a;
  int32_T c7_b_iy0;
  real_T c7_c_a;
  int32_T c7_c_iy0;
  int32_T c7_d_a;
  int32_T c7_iy;
  int32_T c7_e_a;
  int32_T c7_c;
  int32_T c7_f_a;
  int32_T c7_b_c;
  c7_b_a = c7_a;
  c7_b_iy0 = c7_iy0;
  c7_c_a = c7_b_a;
  c7_c_iy0 = c7_b_iy0;
  if (c7_c_a == 0.0) {
  } else {
    c7_d_a = c7_c_iy0 - 1;
    c7_iy = c7_d_a;
    c7_e_a = c7_iy;
    c7_c = c7_e_a;
    c7_f_a = c7_iy;
    c7_b_c = c7_f_a;
    c7_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
                                      (c7_c + 1)), 1, 6, 1, 0) - 1] =
      c7_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)(c7_b_c + 1)), 1, 6, 1, 0) - 1] + c7_c_a * c7_x[1];
  }
}

static void c7_b_sqrt(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
                      real_T *c7_x)
{
  if (*c7_x < 0.0) {
    c7_c_eml_error(chartInstance);
  }

  *c7_x = muDoubleScalarSqrt(*c7_x);
}

static void c7_b_eml_xrotg(SFc7_Final_Project_v3bInstanceStruct *chartInstance,
  real_T *c7_a, real_T *c7_b, real_T *c7_c, real_T *c7_s)
{
  real_T c7_b_a;
  real_T c7_b_b;
  real_T c7_c_b;
  real_T c7_c_a;
  real_T c7_d_a;
  real_T c7_d_b;
  real_T c7_e_b;
  real_T c7_e_a;
  real_T c7_b_c;
  real_T c7_b_s;
  double * c7_a_t;
  double * c7_b_t;
  double * c7_c_t;
  double * c7_s_t;
  real_T c7_c_c;
  real_T c7_c_s;
  c7_b_a = *c7_a;
  c7_b_b = *c7_b;
  c7_c_b = c7_b_b;
  c7_c_a = c7_b_a;
  c7_d_a = c7_c_a;
  c7_d_b = c7_c_b;
  c7_e_b = c7_d_b;
  c7_e_a = c7_d_a;
  c7_b_c = 0.0;
  c7_b_s = 0.0;
  c7_a_t = (double *)(&c7_e_a);
  c7_b_t = (double *)(&c7_e_b);
  c7_c_t = (double *)(&c7_b_c);
  c7_s_t = (double *)(&c7_b_s);
  drotg(c7_a_t, c7_b_t, c7_c_t, c7_s_t);
  c7_c_a = c7_e_a;
  c7_c_b = c7_e_b;
  c7_c_c = c7_b_c;
  c7_c_s = c7_b_s;
  *c7_a = c7_c_a;
  *c7_b = c7_c_b;
  *c7_c = c7_c_c;
  *c7_s = c7_c_s;
}

static void init_dsm_address_info(SFc7_Final_Project_v3bInstanceStruct
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

void sf_c7_Final_Project_v3b_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1411990825U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3466908718U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(841605676U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(594988769U);
}

mxArray *sf_c7_Final_Project_v3b_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("K60cLzR0YsAVAqBSpmYR7");
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

mxArray *sf_c7_Final_Project_v3b_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c7_Final_Project_v3b(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Ya\",},{M[8],M[0],T\"is_active_c7_Final_Project_v3b\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_Final_Project_v3b_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_Final_Project_v3bInstanceStruct *chartInstance;
    chartInstance = (SFc7_Final_Project_v3bInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Final_Project_v3bMachineNumber_,
           7,
           1,
           1,
           3,
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
          init_script_number_translation(_Final_Project_v3bMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Final_Project_v3bMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Final_Project_v3bMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"qqd");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Ya");
          _SFD_SET_DATA_PROPS(2,10,0,0,"l");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,515);
        _SFD_CV_INIT_EML_IF(0,1,0,456,467,490,514);
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
            1.0,0,0,(MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);

        {
          real_T *c7_Ya;
          real_T (*c7_qqd)[9];
          c7_Ya = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c7_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c7_qqd);
          _SFD_SET_DATA_VALUE_PTR(1U, c7_Ya);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c7_l);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Final_Project_v3bMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "x0ZVWwVX8RCRkWGUJ4NAhE";
}

static void sf_opaque_initialize_c7_Final_Project_v3b(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc7_Final_Project_v3bInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c7_Final_Project_v3b((SFc7_Final_Project_v3bInstanceStruct*)
    chartInstanceVar);
  initialize_c7_Final_Project_v3b((SFc7_Final_Project_v3bInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c7_Final_Project_v3b(void *chartInstanceVar)
{
  enable_c7_Final_Project_v3b((SFc7_Final_Project_v3bInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c7_Final_Project_v3b(void *chartInstanceVar)
{
  disable_c7_Final_Project_v3b((SFc7_Final_Project_v3bInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c7_Final_Project_v3b(void *chartInstanceVar)
{
  sf_c7_Final_Project_v3b((SFc7_Final_Project_v3bInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c7_Final_Project_v3b(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c7_Final_Project_v3b
    ((SFc7_Final_Project_v3bInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_Final_Project_v3b();/* state var info */
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

extern void sf_internal_set_sim_state_c7_Final_Project_v3b(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_Final_Project_v3b();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c7_Final_Project_v3b((SFc7_Final_Project_v3bInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c7_Final_Project_v3b(SimStruct* S)
{
  return sf_internal_get_sim_state_c7_Final_Project_v3b(S);
}

static void sf_opaque_set_sim_state_c7_Final_Project_v3b(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c7_Final_Project_v3b(S, st);
}

static void sf_opaque_terminate_c7_Final_Project_v3b(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_Final_Project_v3bInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Final_Project_v3b_optimization_info();
    }

    finalize_c7_Final_Project_v3b((SFc7_Final_Project_v3bInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_Final_Project_v3b((SFc7_Final_Project_v3bInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_Final_Project_v3b(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_Final_Project_v3b((SFc7_Final_Project_v3bInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c7_Final_Project_v3b(SimStruct *S)
{
  /* Actual parameters from chart:
     l
   */
  const char_T *rtParamNames[] = { "l" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for l*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Final_Project_v3b_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,7,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,7,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,7);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,7,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,7,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2082922703U));
  ssSetChecksum1(S,(1566137659U));
  ssSetChecksum2(S,(2100468196U));
  ssSetChecksum3(S,(2092515564U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c7_Final_Project_v3b(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_Final_Project_v3b(SimStruct *S)
{
  SFc7_Final_Project_v3bInstanceStruct *chartInstance;
  chartInstance = (SFc7_Final_Project_v3bInstanceStruct *)utMalloc(sizeof
    (SFc7_Final_Project_v3bInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc7_Final_Project_v3bInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c7_Final_Project_v3b;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c7_Final_Project_v3b;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c7_Final_Project_v3b;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c7_Final_Project_v3b;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c7_Final_Project_v3b;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c7_Final_Project_v3b;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c7_Final_Project_v3b;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c7_Final_Project_v3b;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_Final_Project_v3b;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_Final_Project_v3b;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c7_Final_Project_v3b;
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

void c7_Final_Project_v3b_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_Final_Project_v3b(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_Final_Project_v3b(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_Final_Project_v3b(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_Final_Project_v3b_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
