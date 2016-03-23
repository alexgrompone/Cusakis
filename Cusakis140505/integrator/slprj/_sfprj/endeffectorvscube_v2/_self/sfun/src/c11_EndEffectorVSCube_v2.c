/* Include files */

#include <stddef.h>
#include "blas.h"
#include "EndEffectorVSCube_v2_sfun.h"
#include "c11_EndEffectorVSCube_v2.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "EndEffectorVSCube_v2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c11_debug_family_names[11] = { "m", "n", "a", "MM", "i",
  "mm", "j", "nargin", "nargout", "M", "DD" };

/* Function Declarations */
static void initialize_c11_EndEffectorVSCube_v2
  (SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void initialize_params_c11_EndEffectorVSCube_v2
  (SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void enable_c11_EndEffectorVSCube_v2
  (SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void disable_c11_EndEffectorVSCube_v2
  (SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void c11_update_debugger_state_c11_EndEffectorVSCube_v2
  (SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c11_EndEffectorVSCube_v2
  (SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void set_sim_state_c11_EndEffectorVSCube_v2
  (SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance, const mxArray
   *c11_st);
static void finalize_c11_EndEffectorVSCube_v2
  (SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void sf_c11_EndEffectorVSCube_v2(SFc11_EndEffectorVSCube_v2InstanceStruct
  *chartInstance);
static void initSimStructsc11_EndEffectorVSCube_v2
  (SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void registerMessagesc11_EndEffectorVSCube_v2
  (SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber);
static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_emlrt_marshallIn(SFc11_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c11_DD, const char_T *c11_identifier, real_T
  c11_y[10]);
static void c11_b_emlrt_marshallIn(SFc11_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[10]);
static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static real_T c11_c_emlrt_marshallIn(SFc11_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int32_T c11_d_emlrt_marshallIn(SFc11_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static uint8_T c11_e_emlrt_marshallIn(SFc11_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c11_b_is_active_c11_EndEffectorVSCube_v2, const
  char_T *c11_identifier);
static uint8_T c11_f_emlrt_marshallIn(SFc11_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void init_dsm_address_info(SFc11_EndEffectorVSCube_v2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c11_EndEffectorVSCube_v2
  (SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
  chartInstance->c11_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c11_is_active_c11_EndEffectorVSCube_v2 = 0U;
}

static void initialize_params_c11_EndEffectorVSCube_v2
  (SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static void enable_c11_EndEffectorVSCube_v2
  (SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c11_EndEffectorVSCube_v2
  (SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c11_update_debugger_state_c11_EndEffectorVSCube_v2
  (SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c11_EndEffectorVSCube_v2
  (SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
  const mxArray *c11_st;
  const mxArray *c11_y = NULL;
  int32_T c11_i0;
  real_T c11_u[10];
  const mxArray *c11_b_y = NULL;
  uint8_T c11_hoistedGlobal;
  uint8_T c11_b_u;
  const mxArray *c11_c_y = NULL;
  real_T (*c11_DD)[10];
  c11_DD = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_st = NULL;
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellarray(2), FALSE);
  for (c11_i0 = 0; c11_i0 < 10; c11_i0++) {
    c11_u[c11_i0] = (*c11_DD)[c11_i0];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 10), FALSE);
  sf_mex_setcell(c11_y, 0, c11_b_y);
  c11_hoistedGlobal = chartInstance->c11_is_active_c11_EndEffectorVSCube_v2;
  c11_b_u = c11_hoistedGlobal;
  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c11_y, 1, c11_c_y);
  sf_mex_assign(&c11_st, c11_y, FALSE);
  return c11_st;
}

static void set_sim_state_c11_EndEffectorVSCube_v2
  (SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance, const mxArray
   *c11_st)
{
  const mxArray *c11_u;
  real_T c11_dv0[10];
  int32_T c11_i1;
  real_T (*c11_DD)[10];
  c11_DD = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c11_doneDoubleBufferReInit = TRUE;
  c11_u = sf_mex_dup(c11_st);
  c11_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 0)), "DD",
                       c11_dv0);
  for (c11_i1 = 0; c11_i1 < 10; c11_i1++) {
    (*c11_DD)[c11_i1] = c11_dv0[c11_i1];
  }

  chartInstance->c11_is_active_c11_EndEffectorVSCube_v2 = c11_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 1)),
     "is_active_c11_EndEffectorVSCube_v2");
  sf_mex_destroy(&c11_u);
  c11_update_debugger_state_c11_EndEffectorVSCube_v2(chartInstance);
  sf_mex_destroy(&c11_st);
}

static void finalize_c11_EndEffectorVSCube_v2
  (SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static void sf_c11_EndEffectorVSCube_v2(SFc11_EndEffectorVSCube_v2InstanceStruct
  *chartInstance)
{
  int32_T c11_i2;
  int32_T c11_i3;
  int32_T c11_i4;
  real_T c11_M[10];
  uint32_T c11_debug_family_var_map[11];
  real_T c11_m;
  real_T c11_n;
  real_T c11_a[10];
  real_T c11_MM[10];
  real_T c11_i;
  real_T c11_mm;
  real_T c11_j;
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  real_T c11_DD[10];
  int32_T c11_i5;
  int32_T c11_i6;
  int32_T c11_b_mm;
  int32_T c11_b_j;
  int32_T c11_i7;
  int32_T c11_i8;
  real_T (*c11_b_DD)[10];
  real_T (*c11_b_M)[10];
  c11_b_DD = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_b_M = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c11_sfEvent);
  for (c11_i2 = 0; c11_i2 < 10; c11_i2++) {
    _SFD_DATA_RANGE_CHECK((*c11_b_M)[c11_i2], 0U);
  }

  for (c11_i3 = 0; c11_i3 < 10; c11_i3++) {
    _SFD_DATA_RANGE_CHECK((*c11_b_DD)[c11_i3], 1U);
  }

  chartInstance->c11_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c11_sfEvent);
  for (c11_i4 = 0; c11_i4 < 10; c11_i4++) {
    c11_M[c11_i4] = (*c11_b_M)[c11_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c11_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_m, 0U, c11_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_n, 1U, c11_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_a, 2U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_MM, 3U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_i, 4U, c11_c_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_mm, 5U, c11_c_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_j, 6U, c11_c_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 7U, c11_c_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 8U, c11_c_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_M, 9U, c11_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_DD, 10U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 3);
  c11_m = 2.0;
  c11_n = 5.0;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 4);
  for (c11_i5 = 0; c11_i5 < 10; c11_i5++) {
    c11_a[c11_i5] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 5);
  for (c11_i6 = 0; c11_i6 < 10; c11_i6++) {
    c11_MM[c11_i6] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 6);
  c11_i = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_mm = 0.0;
  c11_b_mm = 0;
  while (c11_b_mm < 5) {
    c11_mm = (real_T)c11_b_mm * 2.0;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 8);
    c11_j = 1.0;
    c11_b_j = 0;
    while (c11_b_j < 2) {
      c11_j = 1.0 + (real_T)c11_b_j;
      CV_EML_FOR(0, 1, 1, 1);
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 9);
      c11_a[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
        _SFD_INTEGER_CHECK("j+mm", c11_j + c11_mm), 1, 10, 1, 0) - 1] = c11_M
        [((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("M", (int32_T)
           _SFD_INTEGER_CHECK("j", c11_j), 1, 2, 1, 0) + (((int32_T)(real_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("M", (int32_T)_SFD_INTEGER_CHECK("i",
              c11_i), 1, 5, 2, 0) - 1) << 1)) - 1];
      c11_b_j++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_EML_FOR(0, 1, 1, 0);
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 11);
    c11_i++;
    c11_b_mm++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 13);
  for (c11_i7 = 0; c11_i7 < 10; c11_i7++) {
    c11_DD[c11_i7] = c11_a[c11_i7];
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -13);
  _SFD_SYMBOL_SCOPE_POP();
  for (c11_i8 = 0; c11_i8 < 10; c11_i8++) {
    (*c11_b_DD)[c11_i8] = c11_DD[c11_i8];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c11_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_EndEffectorVSCube_v2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc11_EndEffectorVSCube_v2
  (SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static void registerMessagesc11_EndEffectorVSCube_v2
  (SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber)
{
}

static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i9;
  real_T c11_b_inData[10];
  int32_T c11_i10;
  real_T c11_u[10];
  const mxArray *c11_y = NULL;
  SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc11_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i9 = 0; c11_i9 < 10; c11_i9++) {
    c11_b_inData[c11_i9] = (*(real_T (*)[10])c11_inData)[c11_i9];
  }

  for (c11_i10 = 0; c11_i10 < 10; c11_i10++) {
    c11_u[c11_i10] = c11_b_inData[c11_i10];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 10), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static void c11_emlrt_marshallIn(SFc11_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c11_DD, const char_T *c11_identifier, real_T
  c11_y[10])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_DD), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_DD);
}

static void c11_b_emlrt_marshallIn(SFc11_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[10])
{
  real_T c11_dv1[10];
  int32_T c11_i11;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv1, 1, 0, 0U, 1, 0U, 1, 10);
  for (c11_i11 = 0; c11_i11 < 10; c11_i11++) {
    c11_y[c11_i11] = c11_dv1[c11_i11];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_DD;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[10];
  int32_T c11_i12;
  SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc11_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c11_DD = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_DD), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_DD);
  for (c11_i12 = 0; c11_i12 < 10; c11_i12++) {
    (*(real_T (*)[10])c11_outData)[c11_i12] = c11_y[c11_i12];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i13;
  int32_T c11_i14;
  int32_T c11_i15;
  real_T c11_b_inData[10];
  int32_T c11_i16;
  int32_T c11_i17;
  int32_T c11_i18;
  real_T c11_u[10];
  const mxArray *c11_y = NULL;
  SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc11_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_i13 = 0;
  for (c11_i14 = 0; c11_i14 < 5; c11_i14++) {
    for (c11_i15 = 0; c11_i15 < 2; c11_i15++) {
      c11_b_inData[c11_i15 + c11_i13] = (*(real_T (*)[10])c11_inData)[c11_i15 +
        c11_i13];
    }

    c11_i13 += 2;
  }

  c11_i16 = 0;
  for (c11_i17 = 0; c11_i17 < 5; c11_i17++) {
    for (c11_i18 = 0; c11_i18 < 2; c11_i18++) {
      c11_u[c11_i18 + c11_i16] = c11_b_inData[c11_i18 + c11_i16];
    }

    c11_i16 += 2;
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 2, 5), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc11_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static real_T c11_c_emlrt_marshallIn(SFc11_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_y;
  real_T c11_d0;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d0, 1, 0, 0U, 0, 0U, 0);
  c11_y = c11_d0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_nargout;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc11_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c11_nargout = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_nargout),
    &c11_thisId);
  sf_mex_destroy(&c11_nargout);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

const mxArray *sf_c11_EndEffectorVSCube_v2_get_eml_resolved_functions_info(void)
{
  const mxArray *c11_nameCaptureInfo;
  c11_ResolvedFunctionInfo c11_info[1];
  c11_ResolvedFunctionInfo (*c11_b_info)[1];
  const mxArray *c11_m0 = NULL;
  int32_T c11_i19;
  c11_ResolvedFunctionInfo *c11_r0;
  c11_nameCaptureInfo = NULL;
  c11_nameCaptureInfo = NULL;
  c11_b_info = (c11_ResolvedFunctionInfo (*)[1])c11_info;
  (*c11_b_info)[0].context = "";
  (*c11_b_info)[0].name = "mtimes";
  (*c11_b_info)[0].dominantType = "double";
  (*c11_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c11_b_info)[0].fileTimeLo = 1289552092U;
  (*c11_b_info)[0].fileTimeHi = 0U;
  (*c11_b_info)[0].mFileTimeLo = 0U;
  (*c11_b_info)[0].mFileTimeHi = 0U;
  sf_mex_assign(&c11_m0, sf_mex_createstruct("nameCaptureInfo", 1, 1), FALSE);
  for (c11_i19 = 0; c11_i19 < 1; c11_i19++) {
    c11_r0 = &c11_info[c11_i19];
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c11_r0->context)), "context", "nameCaptureInfo",
                    c11_i19);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c11_r0->name)), "name", "nameCaptureInfo",
                    c11_i19);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo",
      c11_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c11_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c11_i19);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c11_r0->resolved)), "resolved",
                    "nameCaptureInfo", c11_i19);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", &c11_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c11_i19);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", &c11_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c11_i19);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo",
      &c11_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c11_i19);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo",
      &c11_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c11_i19);
  }

  sf_mex_assign(&c11_nameCaptureInfo, c11_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c11_nameCaptureInfo);
  return c11_nameCaptureInfo;
}

static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc11_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int32_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static int32_T c11_d_emlrt_marshallIn(SFc11_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int32_T c11_y;
  int32_T c11_i20;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i20, 1, 6, 0U, 0, 0U, 0);
  c11_y = c11_i20;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_sfEvent;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int32_T c11_y;
  SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc11_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c11_b_sfEvent = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_sfEvent),
    &c11_thisId);
  sf_mex_destroy(&c11_b_sfEvent);
  *(int32_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static uint8_T c11_e_emlrt_marshallIn(SFc11_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c11_b_is_active_c11_EndEffectorVSCube_v2, const
  char_T *c11_identifier)
{
  uint8_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_is_active_c11_EndEffectorVSCube_v2), &c11_thisId);
  sf_mex_destroy(&c11_b_is_active_c11_EndEffectorVSCube_v2);
  return c11_y;
}

static uint8_T c11_f_emlrt_marshallIn(SFc11_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint8_T c11_y;
  uint8_T c11_u0;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u0, 1, 3, 0U, 0, 0U, 0);
  c11_y = c11_u0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void init_dsm_address_info(SFc11_EndEffectorVSCube_v2InstanceStruct
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

void sf_c11_EndEffectorVSCube_v2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3733072763U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3079868569U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1442481461U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3812815339U);
}

mxArray *sf_c11_EndEffectorVSCube_v2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("p9LCBntkNywvtnolqv8NMH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(5);
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
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

mxArray *sf_c11_EndEffectorVSCube_v2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c11_EndEffectorVSCube_v2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[15],T\"DD\",},{M[8],M[0],T\"is_active_c11_EndEffectorVSCube_v2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_EndEffectorVSCube_v2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance;
    chartInstance = (SFc11_EndEffectorVSCube_v2InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _EndEffectorVSCube_v2MachineNumber_,
           11,
           1,
           1,
           2,
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
          init_script_number_translation(_EndEffectorVSCube_v2MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_EndEffectorVSCube_v2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _EndEffectorVSCube_v2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"M");
          _SFD_SET_DATA_PROPS(1,2,0,1,"DD");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,2,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,155);
        _SFD_CV_INIT_EML_FOR(0,1,0,77,94,143);
        _SFD_CV_INIT_EML_FOR(0,1,1,94,106,132);
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
          dimVector[0]= 2;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        {
          real_T (*c11_M)[10];
          real_T (*c11_DD)[10];
          c11_DD = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 1);
          c11_M = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c11_M);
          _SFD_SET_DATA_VALUE_PTR(1U, *c11_DD);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _EndEffectorVSCube_v2MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "5S6PX6llcflD7hqYRl0IcG";
}

static void sf_opaque_initialize_c11_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc11_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c11_EndEffectorVSCube_v2
    ((SFc11_EndEffectorVSCube_v2InstanceStruct*) chartInstanceVar);
  initialize_c11_EndEffectorVSCube_v2((SFc11_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c11_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  enable_c11_EndEffectorVSCube_v2((SFc11_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c11_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  disable_c11_EndEffectorVSCube_v2((SFc11_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c11_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  sf_c11_EndEffectorVSCube_v2((SFc11_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c11_EndEffectorVSCube_v2
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c11_EndEffectorVSCube_v2
    ((SFc11_EndEffectorVSCube_v2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_EndEffectorVSCube_v2();/* state var info */
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

extern void sf_internal_set_sim_state_c11_EndEffectorVSCube_v2(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_EndEffectorVSCube_v2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c11_EndEffectorVSCube_v2
    ((SFc11_EndEffectorVSCube_v2InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c11_EndEffectorVSCube_v2(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c11_EndEffectorVSCube_v2(S);
}

static void sf_opaque_set_sim_state_c11_EndEffectorVSCube_v2(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c11_EndEffectorVSCube_v2(S, st);
}

static void sf_opaque_terminate_c11_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc11_EndEffectorVSCube_v2InstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_EndEffectorVSCube_v2_optimization_info();
    }

    finalize_c11_EndEffectorVSCube_v2((SFc11_EndEffectorVSCube_v2InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc11_EndEffectorVSCube_v2
    ((SFc11_EndEffectorVSCube_v2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_EndEffectorVSCube_v2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c11_EndEffectorVSCube_v2
      ((SFc11_EndEffectorVSCube_v2InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c11_EndEffectorVSCube_v2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_EndEffectorVSCube_v2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      11);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,11,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,11,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,11);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,11,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,11,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,11);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3827667045U));
  ssSetChecksum1(S,(3245197583U));
  ssSetChecksum2(S,(3335981080U));
  ssSetChecksum3(S,(541939895U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c11_EndEffectorVSCube_v2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c11_EndEffectorVSCube_v2(SimStruct *S)
{
  SFc11_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc11_EndEffectorVSCube_v2InstanceStruct *)utMalloc(sizeof
    (SFc11_EndEffectorVSCube_v2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc11_EndEffectorVSCube_v2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c11_EndEffectorVSCube_v2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c11_EndEffectorVSCube_v2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c11_EndEffectorVSCube_v2;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c11_EndEffectorVSCube_v2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c11_EndEffectorVSCube_v2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c11_EndEffectorVSCube_v2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c11_EndEffectorVSCube_v2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c11_EndEffectorVSCube_v2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c11_EndEffectorVSCube_v2;
  chartInstance->chartInfo.mdlStart = mdlStart_c11_EndEffectorVSCube_v2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c11_EndEffectorVSCube_v2;
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

void c11_EndEffectorVSCube_v2_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_EndEffectorVSCube_v2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_EndEffectorVSCube_v2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_EndEffectorVSCube_v2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_EndEffectorVSCube_v2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
