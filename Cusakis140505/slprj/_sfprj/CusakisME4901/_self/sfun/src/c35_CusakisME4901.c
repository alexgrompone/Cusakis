/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CusakisME4901_sfun.h"
#include "c35_CusakisME4901.h"
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
static const char * c35_debug_family_names[15] = { "r", "V", "alpha",
  "timetrasl", "nargin", "nargout", "SCtranslation", "SCrotation", "timer",
  "timerot", "VelR", "VelL", "base", "timem", "timerotm" };

/* Function Declarations */
static void initialize_c35_CusakisME4901(SFc35_CusakisME4901InstanceStruct
  *chartInstance);
static void initialize_params_c35_CusakisME4901
  (SFc35_CusakisME4901InstanceStruct *chartInstance);
static void enable_c35_CusakisME4901(SFc35_CusakisME4901InstanceStruct
  *chartInstance);
static void disable_c35_CusakisME4901(SFc35_CusakisME4901InstanceStruct
  *chartInstance);
static void c35_update_debugger_state_c35_CusakisME4901
  (SFc35_CusakisME4901InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c35_CusakisME4901
  (SFc35_CusakisME4901InstanceStruct *chartInstance);
static void set_sim_state_c35_CusakisME4901(SFc35_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c35_st);
static void finalize_c35_CusakisME4901(SFc35_CusakisME4901InstanceStruct
  *chartInstance);
static void sf_c35_CusakisME4901(SFc35_CusakisME4901InstanceStruct
  *chartInstance);
static void c35_chartstep_c35_CusakisME4901(SFc35_CusakisME4901InstanceStruct
  *chartInstance);
static void initSimStructsc35_CusakisME4901(SFc35_CusakisME4901InstanceStruct
  *chartInstance);
static void registerMessagesc35_CusakisME4901(SFc35_CusakisME4901InstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c35_machineNumber, uint32_T
  c35_chartNumber);
static const mxArray *c35_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static real_T c35_emlrt_marshallIn(SFc35_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c35_timerotm, const char_T *c35_identifier);
static real_T c35_b_emlrt_marshallIn(SFc35_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void c35_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static const mxArray *c35_b_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static void c35_info_helper(c35_ResolvedFunctionInfo c35_info[23]);
static real_T c35_mpower(SFc35_CusakisME4901InstanceStruct *chartInstance,
  real_T c35_a);
static void c35_eml_scalar_eg(SFc35_CusakisME4901InstanceStruct *chartInstance);
static void c35_eml_error(SFc35_CusakisME4901InstanceStruct *chartInstance);
static void c35_b_eml_error(SFc35_CusakisME4901InstanceStruct *chartInstance);
static const mxArray *c35_c_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static int32_T c35_c_emlrt_marshallIn(SFc35_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void c35_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static uint8_T c35_d_emlrt_marshallIn(SFc35_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c35_b_is_active_c35_CusakisME4901, const char_T
  *c35_identifier);
static uint8_T c35_e_emlrt_marshallIn(SFc35_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void init_dsm_address_info(SFc35_CusakisME4901InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c35_CusakisME4901(SFc35_CusakisME4901InstanceStruct
  *chartInstance)
{
  chartInstance->c35_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c35_is_active_c35_CusakisME4901 = 0U;
}

static void initialize_params_c35_CusakisME4901
  (SFc35_CusakisME4901InstanceStruct *chartInstance)
{
}

static void enable_c35_CusakisME4901(SFc35_CusakisME4901InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c35_CusakisME4901(SFc35_CusakisME4901InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c35_update_debugger_state_c35_CusakisME4901
  (SFc35_CusakisME4901InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c35_CusakisME4901
  (SFc35_CusakisME4901InstanceStruct *chartInstance)
{
  const mxArray *c35_st;
  const mxArray *c35_y = NULL;
  real_T c35_hoistedGlobal;
  real_T c35_u;
  const mxArray *c35_b_y = NULL;
  real_T c35_b_hoistedGlobal;
  real_T c35_b_u;
  const mxArray *c35_c_y = NULL;
  real_T c35_c_hoistedGlobal;
  real_T c35_c_u;
  const mxArray *c35_d_y = NULL;
  real_T c35_d_hoistedGlobal;
  real_T c35_d_u;
  const mxArray *c35_e_y = NULL;
  real_T c35_e_hoistedGlobal;
  real_T c35_e_u;
  const mxArray *c35_f_y = NULL;
  uint8_T c35_f_hoistedGlobal;
  uint8_T c35_f_u;
  const mxArray *c35_g_y = NULL;
  real_T *c35_VelL;
  real_T *c35_VelR;
  real_T *c35_base;
  real_T *c35_timem;
  real_T *c35_timerotm;
  c35_timerotm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c35_timem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c35_base = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c35_VelL = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c35_VelR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c35_st = NULL;
  c35_st = NULL;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_createcellarray(6), FALSE);
  c35_hoistedGlobal = *c35_VelL;
  c35_u = c35_hoistedGlobal;
  c35_b_y = NULL;
  sf_mex_assign(&c35_b_y, sf_mex_create("y", &c35_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c35_y, 0, c35_b_y);
  c35_b_hoistedGlobal = *c35_VelR;
  c35_b_u = c35_b_hoistedGlobal;
  c35_c_y = NULL;
  sf_mex_assign(&c35_c_y, sf_mex_create("y", &c35_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c35_y, 1, c35_c_y);
  c35_c_hoistedGlobal = *c35_base;
  c35_c_u = c35_c_hoistedGlobal;
  c35_d_y = NULL;
  sf_mex_assign(&c35_d_y, sf_mex_create("y", &c35_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c35_y, 2, c35_d_y);
  c35_d_hoistedGlobal = *c35_timem;
  c35_d_u = c35_d_hoistedGlobal;
  c35_e_y = NULL;
  sf_mex_assign(&c35_e_y, sf_mex_create("y", &c35_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c35_y, 3, c35_e_y);
  c35_e_hoistedGlobal = *c35_timerotm;
  c35_e_u = c35_e_hoistedGlobal;
  c35_f_y = NULL;
  sf_mex_assign(&c35_f_y, sf_mex_create("y", &c35_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c35_y, 4, c35_f_y);
  c35_f_hoistedGlobal = chartInstance->c35_is_active_c35_CusakisME4901;
  c35_f_u = c35_f_hoistedGlobal;
  c35_g_y = NULL;
  sf_mex_assign(&c35_g_y, sf_mex_create("y", &c35_f_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c35_y, 5, c35_g_y);
  sf_mex_assign(&c35_st, c35_y, FALSE);
  return c35_st;
}

static void set_sim_state_c35_CusakisME4901(SFc35_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c35_st)
{
  const mxArray *c35_u;
  real_T *c35_VelL;
  real_T *c35_VelR;
  real_T *c35_base;
  real_T *c35_timem;
  real_T *c35_timerotm;
  c35_timerotm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c35_timem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c35_base = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c35_VelL = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c35_VelR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c35_doneDoubleBufferReInit = TRUE;
  c35_u = sf_mex_dup(c35_st);
  *c35_VelL = c35_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c35_u, 0)), "VelL");
  *c35_VelR = c35_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c35_u, 1)), "VelR");
  *c35_base = c35_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c35_u, 2)), "base");
  *c35_timem = c35_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c35_u, 3)), "timem");
  *c35_timerotm = c35_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c35_u, 4)), "timerotm");
  chartInstance->c35_is_active_c35_CusakisME4901 = c35_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c35_u, 5)),
     "is_active_c35_CusakisME4901");
  sf_mex_destroy(&c35_u);
  c35_update_debugger_state_c35_CusakisME4901(chartInstance);
  sf_mex_destroy(&c35_st);
}

static void finalize_c35_CusakisME4901(SFc35_CusakisME4901InstanceStruct
  *chartInstance)
{
}

static void sf_c35_CusakisME4901(SFc35_CusakisME4901InstanceStruct
  *chartInstance)
{
  int32_T c35_i0;
  real_T *c35_SCrotation;
  real_T *c35_VelR;
  real_T *c35_timer;
  real_T *c35_VelL;
  real_T *c35_base;
  real_T *c35_timem;
  real_T *c35_timerotm;
  real_T *c35_timerot;
  real_T (*c35_SCtranslation)[2];
  c35_timerot = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c35_timerotm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c35_timem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c35_base = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c35_VelL = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c35_timer = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c35_VelR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c35_SCrotation = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c35_SCtranslation = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 25U, chartInstance->c35_sfEvent);
  for (c35_i0 = 0; c35_i0 < 2; c35_i0++) {
    _SFD_DATA_RANGE_CHECK((*c35_SCtranslation)[c35_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c35_SCrotation, 1U);
  _SFD_DATA_RANGE_CHECK(*c35_VelR, 2U);
  _SFD_DATA_RANGE_CHECK(*c35_timer, 3U);
  _SFD_DATA_RANGE_CHECK(*c35_VelL, 4U);
  _SFD_DATA_RANGE_CHECK(*c35_base, 5U);
  _SFD_DATA_RANGE_CHECK(*c35_timem, 6U);
  _SFD_DATA_RANGE_CHECK(*c35_timerotm, 7U);
  _SFD_DATA_RANGE_CHECK(*c35_timerot, 8U);
  chartInstance->c35_sfEvent = CALL_EVENT;
  c35_chartstep_c35_CusakisME4901(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CusakisME4901MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c35_chartstep_c35_CusakisME4901(SFc35_CusakisME4901InstanceStruct
  *chartInstance)
{
  real_T c35_hoistedGlobal;
  real_T c35_b_hoistedGlobal;
  real_T c35_c_hoistedGlobal;
  int32_T c35_i1;
  real_T c35_SCtranslation[2];
  real_T c35_SCrotation;
  real_T c35_timer;
  real_T c35_timerot;
  uint32_T c35_debug_family_var_map[15];
  real_T c35_r;
  real_T c35_V;
  real_T c35_alpha;
  real_T c35_timetrasl;
  real_T c35_nargin = 4.0;
  real_T c35_nargout = 5.0;
  real_T c35_VelR;
  real_T c35_VelL;
  real_T c35_base;
  real_T c35_timem;
  real_T c35_timerotm;
  real_T c35_x;
  real_T c35_b_x;
  real_T c35_c_x;
  real_T c35_d_x;
  real_T c35_y;
  real_T c35_A;
  real_T c35_B;
  real_T c35_e_x;
  real_T c35_b_y;
  real_T c35_f_x;
  real_T c35_c_y;
  real_T c35_d_y;
  real_T c35_g_x;
  real_T c35_h_x;
  real_T c35_i_x;
  real_T c35_j_x;
  real_T c35_e_y;
  real_T c35_b;
  real_T c35_f_y;
  real_T c35_b_A;
  real_T c35_k_x;
  real_T c35_l_x;
  real_T c35_g_y;
  real_T c35_m_x;
  real_T c35_n_x;
  real_T c35_a;
  real_T c35_b_a;
  real_T c35_o_x;
  real_T c35_p_x;
  real_T c35_c_a;
  real_T c35_h_y;
  real_T c35_d_a;
  real_T c35_q_x;
  real_T c35_r_x;
  real_T c35_e_a;
  real_T c35_i_y;
  real_T c35_f_a;
  real_T *c35_b_timerotm;
  real_T *c35_b_timem;
  real_T *c35_b_base;
  real_T *c35_b_VelL;
  real_T *c35_b_VelR;
  real_T *c35_b_timerot;
  real_T *c35_b_timer;
  real_T *c35_b_SCrotation;
  real_T (*c35_b_SCtranslation)[2];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  c35_b_timerot = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c35_b_timerotm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c35_b_timem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c35_b_base = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c35_b_VelL = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c35_b_timer = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c35_b_VelR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c35_b_SCrotation = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c35_b_SCtranslation = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 25U, chartInstance->c35_sfEvent);
  c35_hoistedGlobal = *c35_b_SCrotation;
  c35_b_hoistedGlobal = *c35_b_timer;
  c35_c_hoistedGlobal = *c35_b_timerot;
  for (c35_i1 = 0; c35_i1 < 2; c35_i1++) {
    c35_SCtranslation[c35_i1] = (*c35_b_SCtranslation)[c35_i1];
  }

  c35_SCrotation = c35_hoistedGlobal;
  c35_timer = c35_b_hoistedGlobal;
  c35_timerot = c35_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 15U, 15U, c35_debug_family_names,
    c35_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c35_r, 0U, c35_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_V, 1U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_alpha, 2U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_timetrasl, 3U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_nargin, 4U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_nargout, 5U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c35_SCtranslation, 6U, c35_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c35_SCrotation, 7U, c35_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c35_timer, 8U, c35_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c35_timerot, 9U, c35_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_VelR, 10U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_VelL, 11U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_base, 12U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_timem, 13U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_timerotm, 14U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 7);
  c35_r = 0.13;
  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 10);
  c35_x = c35_mpower(chartInstance, c35_SCtranslation[0]) + c35_mpower
    (chartInstance, c35_SCtranslation[1]);
  c35_V = c35_x;
  if (c35_V < 0.0) {
    c35_eml_error(chartInstance);
  }

  c35_b_x = c35_V;
  c35_V = c35_b_x;
  c35_V = muDoubleScalarSqrt(c35_V);
  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 13);
  c35_c_x = c35_V;
  c35_d_x = c35_c_x;
  c35_y = muDoubleScalarAbs(c35_d_x);
  if (CV_EML_IF(0, 1, 0, c35_y > 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 14);
    c35_A = c35_SCtranslation[1];
    c35_B = c35_V;
    c35_e_x = c35_A;
    c35_b_y = c35_B;
    c35_f_x = c35_e_x;
    c35_c_y = c35_b_y;
    c35_d_y = c35_f_x / c35_c_y;
    c35_g_x = c35_d_y;
    c35_alpha = c35_g_x;
    guard3 = FALSE;
    if (c35_alpha < -1.0) {
      guard3 = TRUE;
    } else {
      if (1.0 < c35_alpha) {
        guard3 = TRUE;
      }
    }

    if (guard3 == TRUE) {
      c35_b_eml_error(chartInstance);
    }

    c35_h_x = c35_alpha;
    c35_alpha = c35_h_x;
    c35_alpha = muDoubleScalarAsin(c35_alpha);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 16);
    c35_alpha = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 19);
  c35_base = c35_SCrotation - c35_alpha;
  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 21);
  c35_VelR = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 23);
  c35_VelL = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 25);
  c35_timetrasl = 0.5;
  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 27);
  guard1 = FALSE;
  if (CV_EML_COND(0, 1, 0, c35_timer < c35_timerot + c35_timetrasl)) {
    if (CV_EML_COND(0, 1, 1, c35_timer > (c35_timerot + c35_timetrasl) - 0.01))
    {
      CV_EML_MCDC(0, 1, 0, TRUE);
      CV_EML_IF(0, 1, 1, TRUE);
      _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 28);
      c35_timerotm = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 29);
      c35_i_x = c35_alpha;
      c35_j_x = c35_i_x;
      c35_e_y = muDoubleScalarAbs(c35_j_x);
      if (CV_EML_IF(0, 1, 2, c35_e_y > 0.0)) {
        _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 30);
        c35_b = c35_alpha;
        c35_f_y = 0.13 * c35_b;
        c35_b_A = c35_f_y;
        c35_k_x = c35_b_A;
        c35_l_x = c35_k_x;
        c35_g_y = c35_l_x / 0.5;
        c35_m_x = c35_g_y;
        c35_n_x = c35_m_x;
        c35_timerotm = muDoubleScalarAbs(c35_n_x);
      }

      _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 32);
      c35_timem = 0.0;
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(0, 1, 0, FALSE);
    CV_EML_IF(0, 1, 1, FALSE);
    _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 33);
    if (CV_EML_IF(0, 1, 3, c35_timer < c35_timerot)) {
      _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 35);
      c35_a = -c35_V;
      c35_VelR = c35_a * 1000.0;
      _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 36);
      c35_b_a = c35_V;
      c35_VelL = c35_b_a * 1000.0;
      _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 37);
      c35_timem = c35_timer + 0.01;
      _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 38);
      c35_timerotm = c35_timerot;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 39);
      guard2 = FALSE;
      if (CV_EML_COND(0, 1, 2, c35_timer > c35_timerot)) {
        if (CV_EML_COND(0, 1, 3, c35_timer < c35_timerot + c35_timetrasl)) {
          CV_EML_MCDC(0, 1, 1, TRUE);
          CV_EML_IF(0, 1, 4, TRUE);
          _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 41);
          c35_o_x = c35_alpha;
          c35_p_x = c35_o_x;
          c35_p_x = muDoubleScalarSign(c35_p_x);
          c35_c_a = -c35_p_x;
          c35_h_y = c35_c_a * 0.5;
          c35_d_a = c35_h_y;
          c35_VelR = c35_d_a * 1000.0;
          _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 42);
          c35_q_x = c35_alpha;
          c35_r_x = c35_q_x;
          c35_r_x = muDoubleScalarSign(c35_r_x);
          c35_e_a = c35_r_x;
          c35_i_y = c35_e_a * 0.5;
          c35_f_a = c35_i_y;
          c35_VelL = c35_f_a * 1000.0;
          _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 43);
          c35_timem = c35_timer + 0.01;
          _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 44);
          c35_timerotm = c35_timerot;
        } else {
          guard2 = TRUE;
        }
      } else {
        guard2 = TRUE;
      }

      if (guard2 == TRUE) {
        CV_EML_MCDC(0, 1, 1, FALSE);
        CV_EML_IF(0, 1, 4, FALSE);
        _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 46);
        c35_VelR = 0.0;
        _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 47);
        c35_VelL = 0.0;
        _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 48);
        c35_timem = c35_timer + 0.01;
        _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 49);
        c35_timerotm = c35_timerot;
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, -49);
  _SFD_SYMBOL_SCOPE_POP();
  *c35_b_VelR = c35_VelR;
  *c35_b_VelL = c35_VelL;
  *c35_b_base = c35_base;
  *c35_b_timem = c35_timem;
  *c35_b_timerotm = c35_timerotm;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 25U, chartInstance->c35_sfEvent);
}

static void initSimStructsc35_CusakisME4901(SFc35_CusakisME4901InstanceStruct
  *chartInstance)
{
}

static void registerMessagesc35_CusakisME4901(SFc35_CusakisME4901InstanceStruct *
  chartInstance)
{
}

static void init_script_number_translation(uint32_T c35_machineNumber, uint32_T
  c35_chartNumber)
{
}

static const mxArray *c35_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  real_T c35_u;
  const mxArray *c35_y = NULL;
  SFc35_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc35_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  c35_u = *(real_T *)c35_inData;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", &c35_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, FALSE);
  return c35_mxArrayOutData;
}

static real_T c35_emlrt_marshallIn(SFc35_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c35_timerotm, const char_T *c35_identifier)
{
  real_T c35_y;
  emlrtMsgIdentifier c35_thisId;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_timerotm),
    &c35_thisId);
  sf_mex_destroy(&c35_timerotm);
  return c35_y;
}

static real_T c35_b_emlrt_marshallIn(SFc35_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  real_T c35_y;
  real_T c35_d0;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), &c35_d0, 1, 0, 0U, 0, 0U, 0);
  c35_y = c35_d0;
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void c35_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_timerotm;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  real_T c35_y;
  SFc35_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc35_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c35_timerotm = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_timerotm),
    &c35_thisId);
  sf_mex_destroy(&c35_timerotm);
  *(real_T *)c35_outData = c35_y;
  sf_mex_destroy(&c35_mxArrayInData);
}

static const mxArray *c35_b_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_i2;
  real_T c35_b_inData[2];
  int32_T c35_i3;
  real_T c35_u[2];
  const mxArray *c35_y = NULL;
  SFc35_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc35_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  for (c35_i2 = 0; c35_i2 < 2; c35_i2++) {
    c35_b_inData[c35_i2] = (*(real_T (*)[2])c35_inData)[c35_i2];
  }

  for (c35_i3 = 0; c35_i3 < 2; c35_i3++) {
    c35_u[c35_i3] = c35_b_inData[c35_i3];
  }

  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, FALSE);
  return c35_mxArrayOutData;
}

const mxArray *sf_c35_CusakisME4901_get_eml_resolved_functions_info(void)
{
  const mxArray *c35_nameCaptureInfo;
  c35_ResolvedFunctionInfo c35_info[23];
  const mxArray *c35_m0 = NULL;
  int32_T c35_i4;
  c35_ResolvedFunctionInfo *c35_r0;
  c35_nameCaptureInfo = NULL;
  c35_nameCaptureInfo = NULL;
  c35_info_helper(c35_info);
  sf_mex_assign(&c35_m0, sf_mex_createstruct("nameCaptureInfo", 1, 23), FALSE);
  for (c35_i4 = 0; c35_i4 < 23; c35_i4++) {
    c35_r0 = &c35_info[c35_i4];
    sf_mex_addfield(c35_m0, sf_mex_create("nameCaptureInfo", c35_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c35_r0->context)), "context", "nameCaptureInfo",
                    c35_i4);
    sf_mex_addfield(c35_m0, sf_mex_create("nameCaptureInfo", c35_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c35_r0->name)), "name", "nameCaptureInfo", c35_i4);
    sf_mex_addfield(c35_m0, sf_mex_create("nameCaptureInfo",
      c35_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c35_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c35_i4);
    sf_mex_addfield(c35_m0, sf_mex_create("nameCaptureInfo", c35_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c35_r0->resolved)), "resolved",
                    "nameCaptureInfo", c35_i4);
    sf_mex_addfield(c35_m0, sf_mex_create("nameCaptureInfo", &c35_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c35_i4);
    sf_mex_addfield(c35_m0, sf_mex_create("nameCaptureInfo", &c35_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c35_i4);
    sf_mex_addfield(c35_m0, sf_mex_create("nameCaptureInfo",
      &c35_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c35_i4);
    sf_mex_addfield(c35_m0, sf_mex_create("nameCaptureInfo",
      &c35_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c35_i4);
  }

  sf_mex_assign(&c35_nameCaptureInfo, c35_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c35_nameCaptureInfo);
  return c35_nameCaptureInfo;
}

static void c35_info_helper(c35_ResolvedFunctionInfo c35_info[23])
{
  c35_info[0].context = "";
  c35_info[0].name = "mpower";
  c35_info[0].dominantType = "double";
  c35_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c35_info[0].fileTimeLo = 1286851242U;
  c35_info[0].fileTimeHi = 0U;
  c35_info[0].mFileTimeLo = 0U;
  c35_info[0].mFileTimeHi = 0U;
  c35_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c35_info[1].name = "power";
  c35_info[1].dominantType = "double";
  c35_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c35_info[1].fileTimeLo = 1348224330U;
  c35_info[1].fileTimeHi = 0U;
  c35_info[1].mFileTimeLo = 0U;
  c35_info[1].mFileTimeHi = 0U;
  c35_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c35_info[2].name = "eml_scalar_eg";
  c35_info[2].dominantType = "double";
  c35_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c35_info[2].fileTimeLo = 1286851196U;
  c35_info[2].fileTimeHi = 0U;
  c35_info[2].mFileTimeLo = 0U;
  c35_info[2].mFileTimeHi = 0U;
  c35_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c35_info[3].name = "eml_scalexp_alloc";
  c35_info[3].dominantType = "double";
  c35_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c35_info[3].fileTimeLo = 1352457260U;
  c35_info[3].fileTimeHi = 0U;
  c35_info[3].mFileTimeLo = 0U;
  c35_info[3].mFileTimeHi = 0U;
  c35_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c35_info[4].name = "floor";
  c35_info[4].dominantType = "double";
  c35_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c35_info[4].fileTimeLo = 1343862780U;
  c35_info[4].fileTimeHi = 0U;
  c35_info[4].mFileTimeLo = 0U;
  c35_info[4].mFileTimeHi = 0U;
  c35_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c35_info[5].name = "eml_scalar_floor";
  c35_info[5].dominantType = "double";
  c35_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c35_info[5].fileTimeLo = 1286851126U;
  c35_info[5].fileTimeHi = 0U;
  c35_info[5].mFileTimeLo = 0U;
  c35_info[5].mFileTimeHi = 0U;
  c35_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c35_info[6].name = "eml_scalar_eg";
  c35_info[6].dominantType = "double";
  c35_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c35_info[6].fileTimeLo = 1286851196U;
  c35_info[6].fileTimeHi = 0U;
  c35_info[6].mFileTimeLo = 0U;
  c35_info[6].mFileTimeHi = 0U;
  c35_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c35_info[7].name = "mtimes";
  c35_info[7].dominantType = "double";
  c35_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c35_info[7].fileTimeLo = 1289552092U;
  c35_info[7].fileTimeHi = 0U;
  c35_info[7].mFileTimeLo = 0U;
  c35_info[7].mFileTimeHi = 0U;
  c35_info[8].context = "";
  c35_info[8].name = "sqrt";
  c35_info[8].dominantType = "double";
  c35_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c35_info[8].fileTimeLo = 1343862786U;
  c35_info[8].fileTimeHi = 0U;
  c35_info[8].mFileTimeLo = 0U;
  c35_info[8].mFileTimeHi = 0U;
  c35_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c35_info[9].name = "eml_error";
  c35_info[9].dominantType = "char";
  c35_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c35_info[9].fileTimeLo = 1343862758U;
  c35_info[9].fileTimeHi = 0U;
  c35_info[9].mFileTimeLo = 0U;
  c35_info[9].mFileTimeHi = 0U;
  c35_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c35_info[10].name = "eml_scalar_sqrt";
  c35_info[10].dominantType = "double";
  c35_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c35_info[10].fileTimeLo = 1286851138U;
  c35_info[10].fileTimeHi = 0U;
  c35_info[10].mFileTimeLo = 0U;
  c35_info[10].mFileTimeHi = 0U;
  c35_info[11].context = "";
  c35_info[11].name = "abs";
  c35_info[11].dominantType = "double";
  c35_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c35_info[11].fileTimeLo = 1343862766U;
  c35_info[11].fileTimeHi = 0U;
  c35_info[11].mFileTimeLo = 0U;
  c35_info[11].mFileTimeHi = 0U;
  c35_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c35_info[12].name = "eml_scalar_abs";
  c35_info[12].dominantType = "double";
  c35_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c35_info[12].fileTimeLo = 1286851112U;
  c35_info[12].fileTimeHi = 0U;
  c35_info[12].mFileTimeLo = 0U;
  c35_info[12].mFileTimeHi = 0U;
  c35_info[13].context = "";
  c35_info[13].name = "mrdivide";
  c35_info[13].dominantType = "double";
  c35_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c35_info[13].fileTimeLo = 1357983948U;
  c35_info[13].fileTimeHi = 0U;
  c35_info[13].mFileTimeLo = 1319762366U;
  c35_info[13].mFileTimeHi = 0U;
  c35_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c35_info[14].name = "rdivide";
  c35_info[14].dominantType = "double";
  c35_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c35_info[14].fileTimeLo = 1346542788U;
  c35_info[14].fileTimeHi = 0U;
  c35_info[14].mFileTimeLo = 0U;
  c35_info[14].mFileTimeHi = 0U;
  c35_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c35_info[15].name = "eml_scalexp_compatible";
  c35_info[15].dominantType = "double";
  c35_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c35_info[15].fileTimeLo = 1286851196U;
  c35_info[15].fileTimeHi = 0U;
  c35_info[15].mFileTimeLo = 0U;
  c35_info[15].mFileTimeHi = 0U;
  c35_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c35_info[16].name = "eml_div";
  c35_info[16].dominantType = "double";
  c35_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c35_info[16].fileTimeLo = 1313380210U;
  c35_info[16].fileTimeHi = 0U;
  c35_info[16].mFileTimeLo = 0U;
  c35_info[16].mFileTimeHi = 0U;
  c35_info[17].context = "";
  c35_info[17].name = "asin";
  c35_info[17].dominantType = "double";
  c35_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m";
  c35_info[17].fileTimeLo = 1343862770U;
  c35_info[17].fileTimeHi = 0U;
  c35_info[17].mFileTimeLo = 0U;
  c35_info[17].mFileTimeHi = 0U;
  c35_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m";
  c35_info[18].name = "eml_error";
  c35_info[18].dominantType = "char";
  c35_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c35_info[18].fileTimeLo = 1343862758U;
  c35_info[18].fileTimeHi = 0U;
  c35_info[18].mFileTimeLo = 0U;
  c35_info[18].mFileTimeHi = 0U;
  c35_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m";
  c35_info[19].name = "eml_scalar_asin";
  c35_info[19].dominantType = "double";
  c35_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_asin.m";
  c35_info[19].fileTimeLo = 1343862776U;
  c35_info[19].fileTimeHi = 0U;
  c35_info[19].mFileTimeLo = 0U;
  c35_info[19].mFileTimeHi = 0U;
  c35_info[20].context = "";
  c35_info[20].name = "mtimes";
  c35_info[20].dominantType = "double";
  c35_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c35_info[20].fileTimeLo = 1289552092U;
  c35_info[20].fileTimeHi = 0U;
  c35_info[20].mFileTimeLo = 0U;
  c35_info[20].mFileTimeHi = 0U;
  c35_info[21].context = "";
  c35_info[21].name = "sign";
  c35_info[21].dominantType = "double";
  c35_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c35_info[21].fileTimeLo = 1354400464U;
  c35_info[21].fileTimeHi = 0U;
  c35_info[21].mFileTimeLo = 0U;
  c35_info[21].mFileTimeHi = 0U;
  c35_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  c35_info[22].name = "eml_scalar_sign";
  c35_info[22].dominantType = "double";
  c35_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c35_info[22].fileTimeLo = 1354400464U;
  c35_info[22].fileTimeHi = 0U;
  c35_info[22].mFileTimeLo = 0U;
  c35_info[22].mFileTimeHi = 0U;
}

static real_T c35_mpower(SFc35_CusakisME4901InstanceStruct *chartInstance,
  real_T c35_a)
{
  real_T c35_b_a;
  real_T c35_c_a;
  real_T c35_ak;
  real_T c35_d_a;
  real_T c35_e_a;
  real_T c35_b;
  c35_b_a = c35_a;
  c35_c_a = c35_b_a;
  c35_eml_scalar_eg(chartInstance);
  c35_ak = c35_c_a;
  c35_d_a = c35_ak;
  c35_eml_scalar_eg(chartInstance);
  c35_e_a = c35_d_a;
  c35_b = c35_d_a;
  return c35_e_a * c35_b;
}

static void c35_eml_scalar_eg(SFc35_CusakisME4901InstanceStruct *chartInstance)
{
}

static void c35_eml_error(SFc35_CusakisME4901InstanceStruct *chartInstance)
{
  int32_T c35_i5;
  static char_T c35_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c35_u[30];
  const mxArray *c35_y = NULL;
  int32_T c35_i6;
  static char_T c35_cv1[4] = { 's', 'q', 'r', 't' };

  char_T c35_b_u[4];
  const mxArray *c35_b_y = NULL;
  for (c35_i5 = 0; c35_i5 < 30; c35_i5++) {
    c35_u[c35_i5] = c35_cv0[c35_i5];
  }

  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 10, 0U, 1U, 0U, 2, 1, 30),
                FALSE);
  for (c35_i6 = 0; c35_i6 < 4; c35_i6++) {
    c35_b_u[c35_i6] = c35_cv1[c35_i6];
  }

  c35_b_y = NULL;
  sf_mex_assign(&c35_b_y, sf_mex_create("y", c35_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c35_y, 14, c35_b_y));
}

static void c35_b_eml_error(SFc35_CusakisME4901InstanceStruct *chartInstance)
{
  int32_T c35_i7;
  static char_T c35_cv2[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c35_u[30];
  const mxArray *c35_y = NULL;
  int32_T c35_i8;
  static char_T c35_cv3[4] = { 'a', 's', 'i', 'n' };

  char_T c35_b_u[4];
  const mxArray *c35_b_y = NULL;
  for (c35_i7 = 0; c35_i7 < 30; c35_i7++) {
    c35_u[c35_i7] = c35_cv2[c35_i7];
  }

  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 10, 0U, 1U, 0U, 2, 1, 30),
                FALSE);
  for (c35_i8 = 0; c35_i8 < 4; c35_i8++) {
    c35_b_u[c35_i8] = c35_cv3[c35_i8];
  }

  c35_b_y = NULL;
  sf_mex_assign(&c35_b_y, sf_mex_create("y", c35_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c35_y, 14, c35_b_y));
}

static const mxArray *c35_c_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_u;
  const mxArray *c35_y = NULL;
  SFc35_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc35_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  c35_u = *(int32_T *)c35_inData;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", &c35_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, FALSE);
  return c35_mxArrayOutData;
}

static int32_T c35_c_emlrt_marshallIn(SFc35_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  int32_T c35_y;
  int32_T c35_i9;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), &c35_i9, 1, 6, 0U, 0, 0U, 0);
  c35_y = c35_i9;
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void c35_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_b_sfEvent;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  int32_T c35_y;
  SFc35_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc35_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c35_b_sfEvent = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_b_sfEvent),
    &c35_thisId);
  sf_mex_destroy(&c35_b_sfEvent);
  *(int32_T *)c35_outData = c35_y;
  sf_mex_destroy(&c35_mxArrayInData);
}

static uint8_T c35_d_emlrt_marshallIn(SFc35_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c35_b_is_active_c35_CusakisME4901, const char_T
  *c35_identifier)
{
  uint8_T c35_y;
  emlrtMsgIdentifier c35_thisId;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c35_b_is_active_c35_CusakisME4901), &c35_thisId);
  sf_mex_destroy(&c35_b_is_active_c35_CusakisME4901);
  return c35_y;
}

static uint8_T c35_e_emlrt_marshallIn(SFc35_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  uint8_T c35_y;
  uint8_T c35_u0;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), &c35_u0, 1, 3, 0U, 0, 0U, 0);
  c35_y = c35_u0;
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void init_dsm_address_info(SFc35_CusakisME4901InstanceStruct
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

void sf_c35_CusakisME4901_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3352719093U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(376844096U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2538533537U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3384303022U);
}

mxArray *sf_c35_CusakisME4901_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("kGhXNlkPsLSwy9sn5CnTZH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c35_CusakisME4901_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c35_CusakisME4901(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[7],T\"VelL\",},{M[1],M[5],T\"VelR\",},{M[1],M[8],T\"base\",},{M[1],M[11],T\"timem\",},{M[1],M[12],T\"timerotm\",},{M[8],M[0],T\"is_active_c35_CusakisME4901\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c35_CusakisME4901_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc35_CusakisME4901InstanceStruct *chartInstance;
    chartInstance = (SFc35_CusakisME4901InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CusakisME4901MachineNumber_,
           35,
           1,
           1,
           9,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"SCtranslation");
          _SFD_SET_DATA_PROPS(1,1,1,0,"SCrotation");
          _SFD_SET_DATA_PROPS(2,2,0,1,"VelR");
          _SFD_SET_DATA_PROPS(3,1,1,0,"timer");
          _SFD_SET_DATA_PROPS(4,2,0,1,"VelL");
          _SFD_SET_DATA_PROPS(5,2,0,1,"base");
          _SFD_SET_DATA_PROPS(6,2,0,1,"timem");
          _SFD_SET_DATA_PROPS(7,2,0,1,"timerotm");
          _SFD_SET_DATA_PROPS(8,1,1,0,"timerot");
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
        _SFD_CV_INIT_EML(0,1,1,5,0,0,0,0,0,4,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1199);
        _SFD_CV_INIT_EML_IF(0,1,0,354,365,404,427);
        _SFD_CV_INIT_EML_IF(0,1,1,570,629,759,1196);
        _SFD_CV_INIT_EML_IF(0,1,2,650,665,-1,745);
        _SFD_CV_INIT_EML_IF(0,1,3,759,779,910,1196);
        _SFD_CV_INIT_EML_IF(0,1,4,910,957,1120,1196);

        {
          static int condStart[] = { 573, 601 };

          static int condEnd[] = { 596, 629 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,573,629,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 917, 934 };

          static int condEnd[] = { 930, 957 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,917,957,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

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
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c35_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)c35_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)c35_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)c35_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)c35_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)c35_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c35_SCrotation;
          real_T *c35_VelR;
          real_T *c35_timer;
          real_T *c35_VelL;
          real_T *c35_base;
          real_T *c35_timem;
          real_T *c35_timerotm;
          real_T *c35_timerot;
          real_T (*c35_SCtranslation)[2];
          c35_timerot = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c35_timerotm = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c35_timem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c35_base = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c35_VelL = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c35_timer = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c35_VelR = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c35_SCrotation = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c35_SCtranslation = (real_T (*)[2])ssGetInputPortSignal
            (chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c35_SCtranslation);
          _SFD_SET_DATA_VALUE_PTR(1U, c35_SCrotation);
          _SFD_SET_DATA_VALUE_PTR(2U, c35_VelR);
          _SFD_SET_DATA_VALUE_PTR(3U, c35_timer);
          _SFD_SET_DATA_VALUE_PTR(4U, c35_VelL);
          _SFD_SET_DATA_VALUE_PTR(5U, c35_base);
          _SFD_SET_DATA_VALUE_PTR(6U, c35_timem);
          _SFD_SET_DATA_VALUE_PTR(7U, c35_timerotm);
          _SFD_SET_DATA_VALUE_PTR(8U, c35_timerot);
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
  return "oQiGQms2NBHBDhLK4YAJvH";
}

static void sf_opaque_initialize_c35_CusakisME4901(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc35_CusakisME4901InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c35_CusakisME4901((SFc35_CusakisME4901InstanceStruct*)
    chartInstanceVar);
  initialize_c35_CusakisME4901((SFc35_CusakisME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c35_CusakisME4901(void *chartInstanceVar)
{
  enable_c35_CusakisME4901((SFc35_CusakisME4901InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c35_CusakisME4901(void *chartInstanceVar)
{
  disable_c35_CusakisME4901((SFc35_CusakisME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c35_CusakisME4901(void *chartInstanceVar)
{
  sf_c35_CusakisME4901((SFc35_CusakisME4901InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c35_CusakisME4901(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c35_CusakisME4901
    ((SFc35_CusakisME4901InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c35_CusakisME4901();/* state var info */
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

extern void sf_internal_set_sim_state_c35_CusakisME4901(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c35_CusakisME4901();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c35_CusakisME4901((SFc35_CusakisME4901InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c35_CusakisME4901(SimStruct* S)
{
  return sf_internal_get_sim_state_c35_CusakisME4901(S);
}

static void sf_opaque_set_sim_state_c35_CusakisME4901(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c35_CusakisME4901(S, st);
}

static void sf_opaque_terminate_c35_CusakisME4901(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc35_CusakisME4901InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CusakisME4901_optimization_info();
    }

    finalize_c35_CusakisME4901((SFc35_CusakisME4901InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc35_CusakisME4901((SFc35_CusakisME4901InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c35_CusakisME4901(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c35_CusakisME4901((SFc35_CusakisME4901InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c35_CusakisME4901(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CusakisME4901_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      35);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,35,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,35,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,35);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,35,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,35,5);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=5; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,35);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1808869740U));
  ssSetChecksum1(S,(977113586U));
  ssSetChecksum2(S,(1811391348U));
  ssSetChecksum3(S,(2224849112U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c35_CusakisME4901(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c35_CusakisME4901(SimStruct *S)
{
  SFc35_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc35_CusakisME4901InstanceStruct *)utMalloc(sizeof
    (SFc35_CusakisME4901InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc35_CusakisME4901InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c35_CusakisME4901;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c35_CusakisME4901;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c35_CusakisME4901;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c35_CusakisME4901;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c35_CusakisME4901;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c35_CusakisME4901;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c35_CusakisME4901;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c35_CusakisME4901;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c35_CusakisME4901;
  chartInstance->chartInfo.mdlStart = mdlStart_c35_CusakisME4901;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c35_CusakisME4901;
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

void c35_CusakisME4901_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c35_CusakisME4901(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c35_CusakisME4901(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c35_CusakisME4901(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c35_CusakisME4901_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
