/* Include files */

#include <stddef.h>
#include "blas.h"
#include "WindowsiCreate_sfun.h"
#include "c2_WindowsiCreate.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "WindowsiCreate_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[27] = { "DataV", "A", "B", "d", "i",
  "l", "n", "z", "hiR", "lowR", "uneg", "Al", "Bl", "dl", "il", "ll", "nl", "zl",
  "hiL", "lowL", "unegl", "nargin", "nargout", "VelR", "VelL", "in", "Data" };

/* Function Declarations */
static void initialize_c2_WindowsiCreate(SFc2_WindowsiCreateInstanceStruct
  *chartInstance);
static void initialize_params_c2_WindowsiCreate
  (SFc2_WindowsiCreateInstanceStruct *chartInstance);
static void enable_c2_WindowsiCreate(SFc2_WindowsiCreateInstanceStruct
  *chartInstance);
static void disable_c2_WindowsiCreate(SFc2_WindowsiCreateInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_WindowsiCreate
  (SFc2_WindowsiCreateInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_WindowsiCreate
  (SFc2_WindowsiCreateInstanceStruct *chartInstance);
static void set_sim_state_c2_WindowsiCreate(SFc2_WindowsiCreateInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_WindowsiCreate(SFc2_WindowsiCreateInstanceStruct
  *chartInstance);
static void sf_c2_WindowsiCreate(SFc2_WindowsiCreateInstanceStruct
  *chartInstance);
static void c2_chartstep_c2_WindowsiCreate(SFc2_WindowsiCreateInstanceStruct
  *chartInstance);
static void initSimStructsc2_WindowsiCreate(SFc2_WindowsiCreateInstanceStruct
  *chartInstance);
static void registerMessagesc2_WindowsiCreate(SFc2_WindowsiCreateInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_WindowsiCreateInstanceStruct
  *chartInstance, const mxArray *c2_Data, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_WindowsiCreateInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn(SFc2_WindowsiCreateInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[4]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_emlrt_marshallIn(SFc2_WindowsiCreateInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[7]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[16]);
static real_T c2_rem(SFc2_WindowsiCreateInstanceStruct *chartInstance, real_T
                     c2_x, real_T c2_y);
static void c2_eml_scalar_eg(SFc2_WindowsiCreateInstanceStruct *chartInstance);
static real_T c2_mpower(SFc2_WindowsiCreateInstanceStruct *chartInstance, real_T
  c2_a);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_e_emlrt_marshallIn(SFc2_WindowsiCreateInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_f_emlrt_marshallIn(SFc2_WindowsiCreateInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_WindowsiCreate, const char_T *
  c2_identifier);
static uint8_T c2_g_emlrt_marshallIn(SFc2_WindowsiCreateInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_WindowsiCreateInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_WindowsiCreate(SFc2_WindowsiCreateInstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_WindowsiCreate = 0U;
}

static void initialize_params_c2_WindowsiCreate
  (SFc2_WindowsiCreateInstanceStruct *chartInstance)
{
}

static void enable_c2_WindowsiCreate(SFc2_WindowsiCreateInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_WindowsiCreate(SFc2_WindowsiCreateInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_WindowsiCreate
  (SFc2_WindowsiCreateInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_WindowsiCreate
  (SFc2_WindowsiCreateInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T *c2_Data;
  c2_Data = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2), FALSE);
  c2_hoistedGlobal = *c2_Data;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = chartInstance->c2_is_active_c2_WindowsiCreate;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_WindowsiCreate(SFc2_WindowsiCreateInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_Data;
  c2_Data = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_Data = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    0)), "Data");
  chartInstance->c2_is_active_c2_WindowsiCreate = c2_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
     "is_active_c2_WindowsiCreate");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_WindowsiCreate(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_WindowsiCreate(SFc2_WindowsiCreateInstanceStruct
  *chartInstance)
{
}

static void sf_c2_WindowsiCreate(SFc2_WindowsiCreateInstanceStruct
  *chartInstance)
{
  real_T *c2_VelR;
  real_T *c2_VelL;
  real_T *c2_Data;
  real_T *c2_in;
  c2_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_Data = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_VelL = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_VelR = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_VelR, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_VelL, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_Data, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_in, 3U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_WindowsiCreate(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_WindowsiCreateMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_WindowsiCreate(SFc2_WindowsiCreateInstanceStruct
  *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_VelR;
  real_T c2_VelL;
  real_T c2_in;
  uint32_T c2_debug_family_var_map[27];
  real_T c2_DataV[7];
  real_T c2_A[4];
  real_T c2_B[4];
  real_T c2_d;
  real_T c2_i;
  real_T c2_l[2];
  real_T c2_n;
  real_T c2_z;
  real_T c2_hiR;
  real_T c2_lowR;
  real_T c2_uneg;
  real_T c2_Al[4];
  real_T c2_Bl[4];
  real_T c2_dl;
  real_T c2_il;
  real_T c2_ll[2];
  real_T c2_nl;
  real_T c2_zl;
  real_T c2_hiL;
  real_T c2_lowL;
  real_T c2_unegl;
  real_T c2_nargin = 3.0;
  real_T c2_nargout = 1.0;
  real_T c2_Data;
  int32_T c2_i0;
  int32_T c2_i1;
  int32_T c2_i2;
  real_T c2_b_A;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_y;
  real_T c2_c_x;
  real_T c2_d_x;
  int32_T c2_i3;
  int32_T c2_b_z;
  real_T c2_a;
  real_T c2_b_y;
  real_T c2_b_a;
  real_T c2_c_y;
  int32_T c2_i4;
  int32_T c2_i5;
  real_T c2_c_A;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_d_y;
  real_T c2_g_x;
  real_T c2_h_x;
  int32_T c2_i6;
  int32_T c2_c_z;
  real_T c2_c_a;
  real_T c2_e_y;
  real_T c2_d_a;
  real_T c2_f_y;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i10;
  real_T c2_d_A;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_g_y;
  real_T c2_k_x;
  real_T c2_l_x;
  int32_T c2_i11;
  int32_T c2_b_zl;
  real_T c2_e_a;
  real_T c2_h_y;
  real_T c2_f_a;
  real_T c2_i_y;
  int32_T c2_i12;
  int32_T c2_i13;
  real_T c2_e_A;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_j_y;
  real_T c2_o_x;
  real_T c2_p_x;
  int32_T c2_i14;
  int32_T c2_c_zl;
  real_T c2_g_a;
  real_T c2_k_y;
  real_T c2_h_a;
  real_T c2_l_y;
  int32_T c2_i15;
  int32_T c2_i16;
  real_T *c2_b_in;
  real_T *c2_b_VelL;
  real_T *c2_b_VelR;
  real_T *c2_b_Data;
  c2_b_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_Data = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_VelL = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_VelR = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_VelR;
  c2_b_hoistedGlobal = *c2_b_VelL;
  c2_c_hoistedGlobal = *c2_b_in;
  c2_VelR = c2_hoistedGlobal;
  c2_VelL = c2_b_hoistedGlobal;
  c2_in = c2_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 27U, 27U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_DataV, 0U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_A, 1U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_B, 2U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_d, 3U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_i, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_l, 5U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_n, 6U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_z, 7U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_hiR, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_lowR, 9U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_uneg, 10U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Al, 11U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Bl, 12U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dl, 13U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_il, 14U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_ll, 15U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_nl, 16U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_zl, 17U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_hiL, 18U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_lowL, 19U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_unegl, 20U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 21U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 22U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_VelR, 23U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_VelL, 24U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_in, 25U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_Data, 26U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i0 = 0; c2_i0 < 7; c2_i0++) {
    c2_DataV[c2_i0] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  if (CV_EML_IF(0, 1, 0, c2_VelR > 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
    for (c2_i1 = 0; c2_i1 < 4; c2_i1++) {
      c2_A[c2_i1] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
    for (c2_i2 = 0; c2_i2 < 4; c2_i2++) {
      c2_B[c2_i2] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
    c2_d = c2_VelR;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
    c2_i = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
    while (CV_EML_WHILE(0, 1, 0, c2_d > 16.0)) {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 17);
      c2_A[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)
        _SFD_INTEGER_CHECK("i", c2_i), 1, 4, 1, 0) - 1] = c2_rem(chartInstance,
        c2_d, 16.0);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
      c2_b_A = c2_d;
      c2_x = c2_b_A;
      c2_b_x = c2_x;
      c2_y = c2_b_x / 16.0;
      c2_c_x = c2_y;
      c2_d = c2_c_x;
      c2_d_x = c2_d;
      c2_d = c2_d_x;
      c2_d = muDoubleScalarFloor(c2_d);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
      c2_i++;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 21);
    c2_A[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)
      _SFD_INTEGER_CHECK("i", c2_i), 1, 4, 1, 0) - 1] = c2_d;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
    for (c2_i3 = 0; c2_i3 < 2; c2_i3++) {
      c2_l[c2_i3] = 4.0 + -3.0 * (real_T)c2_i3;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
    c2_n = 5.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
    c2_z = 1.0;
    c2_b_z = 0;
    while (c2_b_z < 4) {
      c2_z = 1.0 + (real_T)c2_b_z;
      CV_EML_FOR(0, 1, 0, 1);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 25);
      c2_B[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", (int32_T)
        _SFD_INTEGER_CHECK("z", c2_z), 1, 4, 1, 0) - 1] = c2_A[(int32_T)(real_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("n-z", c2_n
        - c2_z), 1, 4, 1, 0) - 1];
      c2_b_z++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_EML_FOR(0, 1, 0, 0);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 28);
    c2_a = c2_B[0];
    c2_b_y = c2_a * 16.0;
    c2_hiR = c2_b_y + c2_B[1];
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 29);
    c2_b_a = c2_B[2];
    c2_c_y = c2_b_a * 16.0;
    c2_lowR = c2_c_y + c2_B[3];
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 30);
    if (CV_EML_IF(0, 1, 1, c2_VelR < 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 31);
      c2_uneg = c2_VelR + c2_mpower(chartInstance, 2.0);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
      for (c2_i4 = 0; c2_i4 < 4; c2_i4++) {
        c2_A[c2_i4] = 0.0;
      }

      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
      for (c2_i5 = 0; c2_i5 < 4; c2_i5++) {
        c2_B[c2_i5] = 0.0;
      }

      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 34);
      c2_d = c2_uneg;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 35);
      c2_i = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 36);
      while (CV_EML_WHILE(0, 1, 1, c2_d > 16.0)) {
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 37);
        c2_A[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)
          _SFD_INTEGER_CHECK("i", c2_i), 1, 4, 1, 0) - 1] = c2_rem(chartInstance,
          c2_d, 16.0);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 38);
        c2_c_A = c2_d;
        c2_e_x = c2_c_A;
        c2_f_x = c2_e_x;
        c2_d_y = c2_f_x / 16.0;
        c2_g_x = c2_d_y;
        c2_d = c2_g_x;
        c2_h_x = c2_d;
        c2_d = c2_h_x;
        c2_d = muDoubleScalarFloor(c2_d);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 39);
        c2_i++;
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 36);
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 41);
      c2_A[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)
        _SFD_INTEGER_CHECK("i", c2_i), 1, 4, 1, 0) - 1] = c2_d;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 42);
      for (c2_i6 = 0; c2_i6 < 2; c2_i6++) {
        c2_l[c2_i6] = 4.0 + -3.0 * (real_T)c2_i6;
      }

      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 43);
      c2_n = 4.0;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 44);
      c2_z = 0.0;
      c2_c_z = 0;
      while (c2_c_z < 4) {
        c2_z = (real_T)c2_c_z;
        CV_EML_FOR(0, 1, 1, 1);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 45);
        c2_B[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B", (int32_T)
          _SFD_INTEGER_CHECK("z+1", c2_z + 1.0), 1, 4, 1, 0) - 1] = c2_A
          [(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)
          _SFD_INTEGER_CHECK("n-z", c2_n - c2_z), 1, 4, 1, 0) - 1];
        c2_c_z++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 1, 0);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 48);
      c2_c_a = c2_B[0];
      c2_e_y = c2_c_a * 16.0;
      c2_hiR = c2_e_y + c2_B[1];
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 49);
      c2_d_a = c2_B[2];
      c2_f_y = c2_d_a * 16.0;
      c2_lowR = c2_f_y + c2_B[3];
    } else {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 51);
      c2_uneg = c2_VelR + c2_mpower(chartInstance, 2.0);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 52);
      for (c2_i7 = 0; c2_i7 < 4; c2_i7++) {
        c2_A[c2_i7] = 0.0;
      }

      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 53);
      for (c2_i8 = 0; c2_i8 < 4; c2_i8++) {
        c2_B[c2_i8] = 0.0;
      }

      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 54);
      c2_d = c2_uneg;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 55);
      c2_i = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 56);
      c2_hiR = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 57);
      c2_lowR = 0.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 60);
  if (CV_EML_IF(0, 1, 2, c2_VelL > 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 62);
    for (c2_i9 = 0; c2_i9 < 4; c2_i9++) {
      c2_Al[c2_i9] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 63);
    for (c2_i10 = 0; c2_i10 < 4; c2_i10++) {
      c2_Bl[c2_i10] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 64);
    c2_dl = c2_VelL;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 65);
    c2_il = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 66);
    while (CV_EML_WHILE(0, 1, 2, c2_dl > 16.0)) {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 67);
      c2_Al[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Al", (int32_T)
        _SFD_INTEGER_CHECK("il", c2_il), 1, 4, 1, 0) - 1] = c2_rem(chartInstance,
        c2_dl, 16.0);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 68);
      c2_d_A = c2_dl;
      c2_i_x = c2_d_A;
      c2_j_x = c2_i_x;
      c2_g_y = c2_j_x / 16.0;
      c2_k_x = c2_g_y;
      c2_dl = c2_k_x;
      c2_l_x = c2_dl;
      c2_dl = c2_l_x;
      c2_dl = muDoubleScalarFloor(c2_dl);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 69);
      c2_il++;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 66);
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 71);
    c2_Al[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Al", (int32_T)
      _SFD_INTEGER_CHECK("il", c2_il), 1, 4, 1, 0) - 1] = c2_dl;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 72);
    for (c2_i11 = 0; c2_i11 < 2; c2_i11++) {
      c2_ll[c2_i11] = 4.0 + -3.0 * (real_T)c2_i11;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 73);
    c2_nl = 5.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 74);
    c2_zl = 1.0;
    c2_b_zl = 0;
    while (c2_b_zl < 4) {
      c2_zl = 1.0 + (real_T)c2_b_zl;
      CV_EML_FOR(0, 1, 2, 1);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 75);
      c2_Bl[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Bl", (int32_T)
        _SFD_INTEGER_CHECK("zl", c2_zl), 1, 4, 1, 0) - 1] = c2_Al[(int32_T)
        (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Al", (int32_T)_SFD_INTEGER_CHECK(
        "nl-zl", c2_nl - c2_zl), 1, 4, 1, 0) - 1];
      c2_b_zl++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_EML_FOR(0, 1, 2, 0);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 78);
    c2_e_a = c2_Bl[0];
    c2_h_y = c2_e_a * 16.0;
    c2_hiL = c2_h_y + c2_Bl[1];
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 79);
    c2_f_a = c2_Bl[2];
    c2_i_y = c2_f_a * 16.0;
    c2_lowL = c2_i_y + c2_Bl[3];
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 80);
    if (CV_EML_IF(0, 1, 3, c2_VelL < 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 81);
      c2_unegl = c2_VelL + c2_mpower(chartInstance, 2.0);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 82);
      for (c2_i12 = 0; c2_i12 < 4; c2_i12++) {
        c2_Al[c2_i12] = 0.0;
      }

      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 83);
      for (c2_i13 = 0; c2_i13 < 4; c2_i13++) {
        c2_Bl[c2_i13] = 0.0;
      }

      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 84);
      c2_dl = c2_unegl;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 85);
      c2_il = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 86);
      while (CV_EML_WHILE(0, 1, 3, c2_dl > 16.0)) {
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 87);
        c2_Al[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Al", (int32_T)
          _SFD_INTEGER_CHECK("il", c2_il), 1, 4, 1, 0) - 1] = c2_rem
          (chartInstance, c2_dl, 16.0);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 88);
        c2_e_A = c2_dl;
        c2_m_x = c2_e_A;
        c2_n_x = c2_m_x;
        c2_j_y = c2_n_x / 16.0;
        c2_o_x = c2_j_y;
        c2_dl = c2_o_x;
        c2_p_x = c2_dl;
        c2_dl = c2_p_x;
        c2_dl = muDoubleScalarFloor(c2_dl);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 89);
        c2_il++;
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 86);
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 91);
      c2_Al[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Al", (int32_T)
        _SFD_INTEGER_CHECK("il", c2_il), 1, 4, 1, 0) - 1] = c2_dl;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 92);
      for (c2_i14 = 0; c2_i14 < 2; c2_i14++) {
        c2_ll[c2_i14] = 4.0 + -3.0 * (real_T)c2_i14;
      }

      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 93);
      c2_nl = 4.0;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 94);
      c2_zl = 0.0;
      c2_c_zl = 0;
      while (c2_c_zl < 4) {
        c2_zl = (real_T)c2_c_zl;
        CV_EML_FOR(0, 1, 3, 1);
        _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 95);
        c2_Bl[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Bl", (int32_T)
          _SFD_INTEGER_CHECK("zl+1", c2_zl + 1.0), 1, 4, 1, 0) - 1] = c2_Al
          [(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Al", (int32_T)
          _SFD_INTEGER_CHECK("nl-zl", c2_nl - c2_zl), 1, 4, 1, 0) - 1];
        c2_c_zl++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 3, 0);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 98);
      c2_g_a = c2_Bl[0];
      c2_k_y = c2_g_a * 16.0;
      c2_hiL = c2_k_y + c2_Bl[1];
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 99);
      c2_h_a = c2_Bl[2];
      c2_l_y = c2_h_a * 16.0;
      c2_lowL = c2_l_y + c2_Bl[3];
    } else {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 101);
      c2_unegl = c2_VelL + c2_mpower(chartInstance, 2.0);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 102);
      for (c2_i15 = 0; c2_i15 < 4; c2_i15++) {
        c2_Al[c2_i15] = 0.0;
      }

      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 103);
      for (c2_i16 = 0; c2_i16 < 4; c2_i16++) {
        c2_Bl[c2_i16] = 0.0;
      }

      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 104);
      c2_dl = c2_unegl;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 105);
      c2_il = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 106);
      c2_hiL = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 107);
      c2_lowL = 0.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 112);
  c2_DataV[0] = 128.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 113);
  c2_DataV[1] = 131.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 114);
  c2_DataV[2] = 145.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 115);
  c2_DataV[3] = c2_hiR;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 116);
  c2_DataV[4] = c2_lowR;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 117);
  c2_DataV[5] = c2_hiL;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 118);
  c2_DataV[6] = c2_lowL;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 120);
  if (CV_EML_IF(0, 1, 4, c2_in > 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 121);
    c2_Data = c2_DataV[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("DataV",
      (int32_T)_SFD_INTEGER_CHECK("in", c2_in), 1, 7, 1, 0) - 1];
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 123);
    c2_Data = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -123);
  _SFD_SYMBOL_SCOPE_POP();
  *c2_b_Data = c2_Data;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_WindowsiCreate(SFc2_WindowsiCreateInstanceStruct
  *chartInstance)
{
}

static void registerMessagesc2_WindowsiCreate(SFc2_WindowsiCreateInstanceStruct *
  chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_WindowsiCreateInstanceStruct *chartInstance;
  chartInstance = (SFc2_WindowsiCreateInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_WindowsiCreateInstanceStruct
  *chartInstance, const mxArray *c2_Data, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Data), &c2_thisId);
  sf_mex_destroy(&c2_Data);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_WindowsiCreateInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Data;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_WindowsiCreateInstanceStruct *chartInstance;
  chartInstance = (SFc2_WindowsiCreateInstanceStruct *)chartInstanceVoid;
  c2_Data = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Data), &c2_thisId);
  sf_mex_destroy(&c2_Data);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i17;
  real_T c2_b_inData[2];
  int32_T c2_i18;
  real_T c2_u[2];
  const mxArray *c2_y = NULL;
  SFc2_WindowsiCreateInstanceStruct *chartInstance;
  chartInstance = (SFc2_WindowsiCreateInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i17 = 0; c2_i17 < 2; c2_i17++) {
    c2_b_inData[c2_i17] = (*(real_T (*)[2])c2_inData)[c2_i17];
  }

  for (c2_i18 = 0; c2_i18 < 2; c2_i18++) {
    c2_u[c2_i18] = c2_b_inData[c2_i18];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 2), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i19;
  real_T c2_b_inData[4];
  int32_T c2_i20;
  real_T c2_u[4];
  const mxArray *c2_y = NULL;
  SFc2_WindowsiCreateInstanceStruct *chartInstance;
  chartInstance = (SFc2_WindowsiCreateInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i19 = 0; c2_i19 < 4; c2_i19++) {
    c2_b_inData[c2_i19] = (*(real_T (*)[4])c2_inData)[c2_i19];
  }

  for (c2_i20 = 0; c2_i20 < 4; c2_i20++) {
    c2_u[c2_i20] = c2_b_inData[c2_i20];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn(SFc2_WindowsiCreateInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[4])
{
  real_T c2_dv0[4];
  int32_T c2_i21;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv0, 1, 0, 0U, 1, 0U, 1, 4);
  for (c2_i21 = 0; c2_i21 < 4; c2_i21++) {
    c2_y[c2_i21] = c2_dv0[c2_i21];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Bl;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[4];
  int32_T c2_i22;
  SFc2_WindowsiCreateInstanceStruct *chartInstance;
  chartInstance = (SFc2_WindowsiCreateInstanceStruct *)chartInstanceVoid;
  c2_Bl = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Bl), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Bl);
  for (c2_i22 = 0; c2_i22 < 4; c2_i22++) {
    (*(real_T (*)[4])c2_outData)[c2_i22] = c2_y[c2_i22];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i23;
  real_T c2_b_inData[7];
  int32_T c2_i24;
  real_T c2_u[7];
  const mxArray *c2_y = NULL;
  SFc2_WindowsiCreateInstanceStruct *chartInstance;
  chartInstance = (SFc2_WindowsiCreateInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i23 = 0; c2_i23 < 7; c2_i23++) {
    c2_b_inData[c2_i23] = (*(real_T (*)[7])c2_inData)[c2_i23];
  }

  for (c2_i24 = 0; c2_i24 < 7; c2_i24++) {
    c2_u[c2_i24] = c2_b_inData[c2_i24];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 7), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn(SFc2_WindowsiCreateInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[7])
{
  real_T c2_dv1[7];
  int32_T c2_i25;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv1, 1, 0, 0U, 1, 0U, 2, 1, 7);
  for (c2_i25 = 0; c2_i25 < 7; c2_i25++) {
    c2_y[c2_i25] = c2_dv1[c2_i25];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_DataV;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[7];
  int32_T c2_i26;
  SFc2_WindowsiCreateInstanceStruct *chartInstance;
  chartInstance = (SFc2_WindowsiCreateInstanceStruct *)chartInstanceVoid;
  c2_DataV = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_DataV), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_DataV);
  for (c2_i26 = 0; c2_i26 < 7; c2_i26++) {
    (*(real_T (*)[7])c2_outData)[c2_i26] = c2_y[c2_i26];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_WindowsiCreate_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[16];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i27;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 16), FALSE);
  for (c2_i27 = 0; c2_i27 < 16; c2_i27++) {
    c2_r0 = &c2_info[c2_i27];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i27);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i27);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i27);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i27);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i27);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i27);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i27);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i27);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[16])
{
  c2_info[0].context = "";
  c2_info[0].name = "rem";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[0].fileTimeLo = 1343862784U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[1].name = "eml_scalar_eg";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[1].fileTimeLo = 1286851196U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[2].name = "eml_scalexp_alloc";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[2].fileTimeLo = 1352457260U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context = "";
  c2_info[3].name = "mrdivide";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[3].fileTimeLo = 1357983948U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 1319762366U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[4].name = "rdivide";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[4].fileTimeLo = 1346542788U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[5].name = "eml_scalexp_compatible";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c2_info[5].fileTimeLo = 1286851196U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[6].name = "eml_div";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[6].fileTimeLo = 1313380210U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context = "";
  c2_info[7].name = "floor";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[7].fileTimeLo = 1343862780U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[8].name = "eml_scalar_floor";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[8].fileTimeLo = 1286851126U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context = "";
  c2_info[9].name = "mtimes";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[9].fileTimeLo = 1289552092U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context = "";
  c2_info[10].name = "mpower";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[10].fileTimeLo = 1286851242U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[11].name = "power";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[11].fileTimeLo = 1348224330U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[12].name = "eml_scalar_eg";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[12].fileTimeLo = 1286851196U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[13].name = "eml_scalexp_alloc";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[13].fileTimeLo = 1352457260U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c2_info[14].name = "floor";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[14].fileTimeLo = 1343862780U;
  c2_info[14].fileTimeHi = 0U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c2_info[15].name = "eml_scalar_eg";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[15].fileTimeLo = 1286851196U;
  c2_info[15].fileTimeHi = 0U;
  c2_info[15].mFileTimeLo = 0U;
  c2_info[15].mFileTimeHi = 0U;
}

static real_T c2_rem(SFc2_WindowsiCreateInstanceStruct *chartInstance, real_T
                     c2_x, real_T c2_y)
{
  real_T c2_xk;
  real_T c2_yk;
  c2_eml_scalar_eg(chartInstance);
  c2_xk = c2_x;
  c2_yk = c2_y;
  return muDoubleScalarRem(c2_xk, c2_yk);
}

static void c2_eml_scalar_eg(SFc2_WindowsiCreateInstanceStruct *chartInstance)
{
}

static real_T c2_mpower(SFc2_WindowsiCreateInstanceStruct *chartInstance, real_T
  c2_a)
{
  real_T c2_b_a;
  real_T c2_c_a;
  real_T c2_ak;
  real_T c2_d_a;
  real_T c2_ar;
  c2_b_a = c2_a;
  c2_c_a = c2_b_a;
  c2_eml_scalar_eg(chartInstance);
  c2_ak = c2_c_a;
  c2_d_a = c2_ak;
  c2_eml_scalar_eg(chartInstance);
  c2_ar = c2_d_a;
  return muDoubleScalarPower(c2_ar, 16.0);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_WindowsiCreateInstanceStruct *chartInstance;
  chartInstance = (SFc2_WindowsiCreateInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_e_emlrt_marshallIn(SFc2_WindowsiCreateInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i28;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i28, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i28;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_WindowsiCreateInstanceStruct *chartInstance;
  chartInstance = (SFc2_WindowsiCreateInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_WindowsiCreateInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_WindowsiCreate, const char_T *
  c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_WindowsiCreate), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_WindowsiCreate);
  return c2_y;
}

static uint8_T c2_g_emlrt_marshallIn(SFc2_WindowsiCreateInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_WindowsiCreateInstanceStruct
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

void sf_c2_WindowsiCreate_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(918012255U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1249433190U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3734248313U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3301901037U);
}

mxArray *sf_c2_WindowsiCreate_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("notCA3C54EcmHRskGGdNCC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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

mxArray *sf_c2_WindowsiCreate_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c2_WindowsiCreate(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[6],T\"Data\",},{M[8],M[0],T\"is_active_c2_WindowsiCreate\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_WindowsiCreate_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_WindowsiCreateInstanceStruct *chartInstance;
    chartInstance = (SFc2_WindowsiCreateInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _WindowsiCreateMachineNumber_,
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
          init_script_number_translation(_WindowsiCreateMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_WindowsiCreateMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _WindowsiCreateMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"VelR");
          _SFD_SET_DATA_PROPS(1,1,1,0,"VelL");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Data");
          _SFD_SET_DATA_PROPS(3,1,1,0,"in");
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
        _SFD_CV_INIT_EML(0,1,1,5,0,0,0,4,4,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2257);
        _SFD_CV_INIT_EML_IF(0,1,0,283,292,672,1162);
        _SFD_CV_INIT_EML_IF(0,1,1,672,685,1052,1162);
        _SFD_CV_INIT_EML_IF(0,1,2,1164,1173,1582,2108);
        _SFD_CV_INIT_EML_IF(0,1,3,1582,1595,1994,2108);
        _SFD_CV_INIT_EML_IF(0,1,4,2213,2220,2237,2253);
        _SFD_CV_INIT_EML_FOR(0,1,0,544,554,582);
        _SFD_CV_INIT_EML_FOR(0,1,1,920,932,962);
        _SFD_CV_INIT_EML_FOR(0,1,2,1444,1455,1488);
        _SFD_CV_INIT_EML_FOR(0,1,3,1851,1865,1900);
        _SFD_CV_INIT_EML_WHILE(0,1,0,389,400,469);
        _SFD_CV_INIT_EML_WHILE(0,1,1,767,778,847);
        _SFD_CV_INIT_EML_WHILE(0,1,2,1274,1286,1362);
        _SFD_CV_INIT_EML_WHILE(0,1,3,1683,1695,1771);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c2_VelR;
          real_T *c2_VelL;
          real_T *c2_Data;
          real_T *c2_in;
          c2_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_Data = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_VelL = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_VelR = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_VelR);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_VelL);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_Data);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_in);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _WindowsiCreateMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "5k00oVAj33VpptCK4gIk6";
}

static void sf_opaque_initialize_c2_WindowsiCreate(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_WindowsiCreateInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_WindowsiCreate((SFc2_WindowsiCreateInstanceStruct*)
    chartInstanceVar);
  initialize_c2_WindowsiCreate((SFc2_WindowsiCreateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_WindowsiCreate(void *chartInstanceVar)
{
  enable_c2_WindowsiCreate((SFc2_WindowsiCreateInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_WindowsiCreate(void *chartInstanceVar)
{
  disable_c2_WindowsiCreate((SFc2_WindowsiCreateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_WindowsiCreate(void *chartInstanceVar)
{
  sf_c2_WindowsiCreate((SFc2_WindowsiCreateInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_WindowsiCreate(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_WindowsiCreate
    ((SFc2_WindowsiCreateInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_WindowsiCreate();/* state var info */
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

extern void sf_internal_set_sim_state_c2_WindowsiCreate(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_WindowsiCreate();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_WindowsiCreate((SFc2_WindowsiCreateInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_WindowsiCreate(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_WindowsiCreate(S);
}

static void sf_opaque_set_sim_state_c2_WindowsiCreate(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c2_WindowsiCreate(S, st);
}

static void sf_opaque_terminate_c2_WindowsiCreate(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_WindowsiCreateInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_WindowsiCreate_optimization_info();
    }

    finalize_c2_WindowsiCreate((SFc2_WindowsiCreateInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_WindowsiCreate((SFc2_WindowsiCreateInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_WindowsiCreate(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_WindowsiCreate((SFc2_WindowsiCreateInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_WindowsiCreate(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_WindowsiCreate_optimization_info();
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
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,3);
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
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2494109667U));
  ssSetChecksum1(S,(3413856962U));
  ssSetChecksum2(S,(1523701543U));
  ssSetChecksum3(S,(3649071457U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_WindowsiCreate(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_WindowsiCreate(SimStruct *S)
{
  SFc2_WindowsiCreateInstanceStruct *chartInstance;
  chartInstance = (SFc2_WindowsiCreateInstanceStruct *)utMalloc(sizeof
    (SFc2_WindowsiCreateInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_WindowsiCreateInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_WindowsiCreate;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_WindowsiCreate;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_WindowsiCreate;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_WindowsiCreate;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_WindowsiCreate;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_WindowsiCreate;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_WindowsiCreate;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_WindowsiCreate;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_WindowsiCreate;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_WindowsiCreate;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_WindowsiCreate;
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

void c2_WindowsiCreate_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_WindowsiCreate(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_WindowsiCreate(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_WindowsiCreate(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_WindowsiCreate_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
