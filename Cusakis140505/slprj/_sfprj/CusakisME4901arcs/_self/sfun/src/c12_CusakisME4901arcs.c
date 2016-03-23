/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CusakisME4901arcs_sfun.h"
#include "c12_CusakisME4901arcs.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CusakisME4901arcs_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c12_debug_family_names[11] = { "m", "n", "a", "MM", "i",
  "mm", "j", "nargin", "nargout", "M", "DD" };

/* Function Declarations */
static void initialize_c12_CusakisME4901arcs
  (SFc12_CusakisME4901arcsInstanceStruct *chartInstance);
static void initialize_params_c12_CusakisME4901arcs
  (SFc12_CusakisME4901arcsInstanceStruct *chartInstance);
static void enable_c12_CusakisME4901arcs(SFc12_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void disable_c12_CusakisME4901arcs(SFc12_CusakisME4901arcsInstanceStruct *
  chartInstance);
static void c12_update_debugger_state_c12_CusakisME4901arcs
  (SFc12_CusakisME4901arcsInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c12_CusakisME4901arcs
  (SFc12_CusakisME4901arcsInstanceStruct *chartInstance);
static void set_sim_state_c12_CusakisME4901arcs
  (SFc12_CusakisME4901arcsInstanceStruct *chartInstance, const mxArray *c12_st);
static void finalize_c12_CusakisME4901arcs(SFc12_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void sf_c12_CusakisME4901arcs(SFc12_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void initSimStructsc12_CusakisME4901arcs
  (SFc12_CusakisME4901arcsInstanceStruct *chartInstance);
static void registerMessagesc12_CusakisME4901arcs
  (SFc12_CusakisME4901arcsInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber);
static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static void c12_emlrt_marshallIn(SFc12_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c12_DD, const char_T *c12_identifier, real_T
  c12_y[16]);
static void c12_b_emlrt_marshallIn(SFc12_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId,
  real_T c12_y[16]);
static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static real_T c12_c_emlrt_marshallIn(SFc12_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_d_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static int32_T c12_d_emlrt_marshallIn(SFc12_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static uint8_T c12_e_emlrt_marshallIn(SFc12_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c12_b_is_active_c12_CusakisME4901arcs, const
  char_T *c12_identifier);
static uint8_T c12_f_emlrt_marshallIn(SFc12_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void init_dsm_address_info(SFc12_CusakisME4901arcsInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c12_CusakisME4901arcs
  (SFc12_CusakisME4901arcsInstanceStruct *chartInstance)
{
  chartInstance->c12_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c12_is_active_c12_CusakisME4901arcs = 0U;
}

static void initialize_params_c12_CusakisME4901arcs
  (SFc12_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static void enable_c12_CusakisME4901arcs(SFc12_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c12_CusakisME4901arcs(SFc12_CusakisME4901arcsInstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c12_update_debugger_state_c12_CusakisME4901arcs
  (SFc12_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c12_CusakisME4901arcs
  (SFc12_CusakisME4901arcsInstanceStruct *chartInstance)
{
  const mxArray *c12_st;
  const mxArray *c12_y = NULL;
  int32_T c12_i0;
  real_T c12_u[16];
  const mxArray *c12_b_y = NULL;
  uint8_T c12_hoistedGlobal;
  uint8_T c12_b_u;
  const mxArray *c12_c_y = NULL;
  real_T (*c12_DD)[16];
  c12_DD = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  c12_st = NULL;
  c12_st = NULL;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_createcellarray(2), FALSE);
  for (c12_i0 = 0; c12_i0 < 16; c12_i0++) {
    c12_u[c12_i0] = (*c12_DD)[c12_i0];
  }

  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 1, 16), FALSE);
  sf_mex_setcell(c12_y, 0, c12_b_y);
  c12_hoistedGlobal = chartInstance->c12_is_active_c12_CusakisME4901arcs;
  c12_b_u = c12_hoistedGlobal;
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", &c12_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c12_y, 1, c12_c_y);
  sf_mex_assign(&c12_st, c12_y, FALSE);
  return c12_st;
}

static void set_sim_state_c12_CusakisME4901arcs
  (SFc12_CusakisME4901arcsInstanceStruct *chartInstance, const mxArray *c12_st)
{
  const mxArray *c12_u;
  real_T c12_dv0[16];
  int32_T c12_i1;
  real_T (*c12_DD)[16];
  c12_DD = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c12_doneDoubleBufferReInit = TRUE;
  c12_u = sf_mex_dup(c12_st);
  c12_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 0)), "DD",
                       c12_dv0);
  for (c12_i1 = 0; c12_i1 < 16; c12_i1++) {
    (*c12_DD)[c12_i1] = c12_dv0[c12_i1];
  }

  chartInstance->c12_is_active_c12_CusakisME4901arcs = c12_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 1)),
     "is_active_c12_CusakisME4901arcs");
  sf_mex_destroy(&c12_u);
  c12_update_debugger_state_c12_CusakisME4901arcs(chartInstance);
  sf_mex_destroy(&c12_st);
}

static void finalize_c12_CusakisME4901arcs(SFc12_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
}

static void sf_c12_CusakisME4901arcs(SFc12_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
  int32_T c12_i2;
  int32_T c12_i3;
  int32_T c12_i4;
  real_T c12_M[16];
  uint32_T c12_debug_family_var_map[11];
  real_T c12_m;
  real_T c12_n;
  real_T c12_a[16];
  real_T c12_MM[16];
  real_T c12_i;
  real_T c12_mm;
  real_T c12_j;
  real_T c12_nargin = 1.0;
  real_T c12_nargout = 1.0;
  real_T c12_DD[16];
  int32_T c12_i5;
  int32_T c12_i6;
  int32_T c12_b_mm;
  int32_T c12_b_j;
  int32_T c12_i7;
  int32_T c12_i8;
  real_T (*c12_b_DD)[16];
  real_T (*c12_b_M)[16];
  c12_b_DD = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
  c12_b_M = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 11U, chartInstance->c12_sfEvent);
  for (c12_i2 = 0; c12_i2 < 16; c12_i2++) {
    _SFD_DATA_RANGE_CHECK((*c12_b_M)[c12_i2], 0U);
  }

  for (c12_i3 = 0; c12_i3 < 16; c12_i3++) {
    _SFD_DATA_RANGE_CHECK((*c12_b_DD)[c12_i3], 1U);
  }

  chartInstance->c12_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c12_sfEvent);
  for (c12_i4 = 0; c12_i4 < 16; c12_i4++) {
    c12_M[c12_i4] = (*c12_b_M)[c12_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c12_debug_family_names,
    c12_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_m, 0U, c12_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_n, 1U, c12_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c12_a, 2U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c12_MM, 3U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_i, 4U, c12_c_sf_marshallOut,
    c12_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_mm, 5U, c12_c_sf_marshallOut,
    c12_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_j, 6U, c12_c_sf_marshallOut,
    c12_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_nargin, 7U, c12_c_sf_marshallOut,
    c12_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_nargout, 8U, c12_c_sf_marshallOut,
    c12_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c12_M, 9U, c12_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c12_DD, 10U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 3);
  c12_m = 2.0;
  c12_n = 8.0;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 4);
  for (c12_i5 = 0; c12_i5 < 16; c12_i5++) {
    c12_a[c12_i5] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 5);
  for (c12_i6 = 0; c12_i6 < 16; c12_i6++) {
    c12_MM[c12_i6] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 6);
  c12_i = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 7);
  c12_mm = 0.0;
  c12_b_mm = 0;
  while (c12_b_mm < 8) {
    c12_mm = (real_T)c12_b_mm * 2.0;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 8);
    c12_j = 1.0;
    c12_b_j = 0;
    while (c12_b_j < 2) {
      c12_j = 1.0 + (real_T)c12_b_j;
      CV_EML_FOR(0, 1, 1, 1);
      _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 9);
      c12_a[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("a", (int32_T)
        _SFD_INTEGER_CHECK("j+mm", c12_j + c12_mm), 1, 16, 1, 0) - 1] = c12_M
        [((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("M", (int32_T)
           _SFD_INTEGER_CHECK("j", c12_j), 1, 2, 1, 0) + (((int32_T)(real_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("M", (int32_T)_SFD_INTEGER_CHECK("i",
              c12_i), 1, 8, 2, 0) - 1) << 1)) - 1];
      c12_b_j++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_EML_FOR(0, 1, 1, 0);
    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 11);
    c12_i++;
    c12_b_mm++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 13);
  for (c12_i7 = 0; c12_i7 < 16; c12_i7++) {
    c12_DD[c12_i7] = c12_a[c12_i7];
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, -13);
  _SFD_SYMBOL_SCOPE_POP();
  for (c12_i8 = 0; c12_i8 < 16; c12_i8++) {
    (*c12_b_DD)[c12_i8] = c12_DD[c12_i8];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c12_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CusakisME4901arcsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc12_CusakisME4901arcs
  (SFc12_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static void registerMessagesc12_CusakisME4901arcs
  (SFc12_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber)
{
}

static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_i9;
  real_T c12_b_inData[16];
  int32_T c12_i10;
  real_T c12_u[16];
  const mxArray *c12_y = NULL;
  SFc12_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc12_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  for (c12_i9 = 0; c12_i9 < 16; c12_i9++) {
    c12_b_inData[c12_i9] = (*(real_T (*)[16])c12_inData)[c12_i9];
  }

  for (c12_i10 = 0; c12_i10 < 16; c12_i10++) {
    c12_u[c12_i10] = c12_b_inData[c12_i10];
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 1, 16), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static void c12_emlrt_marshallIn(SFc12_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c12_DD, const char_T *c12_identifier, real_T
  c12_y[16])
{
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_DD), &c12_thisId, c12_y);
  sf_mex_destroy(&c12_DD);
}

static void c12_b_emlrt_marshallIn(SFc12_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId,
  real_T c12_y[16])
{
  real_T c12_dv1[16];
  int32_T c12_i11;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), c12_dv1, 1, 0, 0U, 1, 0U, 1, 16);
  for (c12_i11 = 0; c12_i11 < 16; c12_i11++) {
    c12_y[c12_i11] = c12_dv1[c12_i11];
  }

  sf_mex_destroy(&c12_u);
}

static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_DD;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y[16];
  int32_T c12_i12;
  SFc12_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc12_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c12_DD = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_DD), &c12_thisId, c12_y);
  sf_mex_destroy(&c12_DD);
  for (c12_i12 = 0; c12_i12 < 16; c12_i12++) {
    (*(real_T (*)[16])c12_outData)[c12_i12] = c12_y[c12_i12];
  }

  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_i13;
  int32_T c12_i14;
  int32_T c12_i15;
  real_T c12_b_inData[16];
  int32_T c12_i16;
  int32_T c12_i17;
  int32_T c12_i18;
  real_T c12_u[16];
  const mxArray *c12_y = NULL;
  SFc12_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc12_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_i13 = 0;
  for (c12_i14 = 0; c12_i14 < 8; c12_i14++) {
    for (c12_i15 = 0; c12_i15 < 2; c12_i15++) {
      c12_b_inData[c12_i15 + c12_i13] = (*(real_T (*)[16])c12_inData)[c12_i15 +
        c12_i13];
    }

    c12_i13 += 2;
  }

  c12_i16 = 0;
  for (c12_i17 = 0; c12_i17 < 8; c12_i17++) {
    for (c12_i18 = 0; c12_i18 < 2; c12_i18++) {
      c12_u[c12_i18 + c12_i16] = c12_b_inData[c12_i18 + c12_i16];
    }

    c12_i16 += 2;
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 2, 2, 8), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  real_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc12_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(real_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static real_T c12_c_emlrt_marshallIn(SFc12_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  real_T c12_y;
  real_T c12_d0;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_d0, 1, 0, 0U, 0, 0U, 0);
  c12_y = c12_d0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_nargout;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y;
  SFc12_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc12_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c12_nargout = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_nargout),
    &c12_thisId);
  sf_mex_destroy(&c12_nargout);
  *(real_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

const mxArray *sf_c12_CusakisME4901arcs_get_eml_resolved_functions_info(void)
{
  const mxArray *c12_nameCaptureInfo;
  c12_ResolvedFunctionInfo c12_info[1];
  c12_ResolvedFunctionInfo (*c12_b_info)[1];
  const mxArray *c12_m0 = NULL;
  int32_T c12_i19;
  c12_ResolvedFunctionInfo *c12_r0;
  c12_nameCaptureInfo = NULL;
  c12_nameCaptureInfo = NULL;
  c12_b_info = (c12_ResolvedFunctionInfo (*)[1])c12_info;
  (*c12_b_info)[0].context = "";
  (*c12_b_info)[0].name = "mtimes";
  (*c12_b_info)[0].dominantType = "double";
  (*c12_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c12_b_info)[0].fileTimeLo = 1289552092U;
  (*c12_b_info)[0].fileTimeHi = 0U;
  (*c12_b_info)[0].mFileTimeLo = 0U;
  (*c12_b_info)[0].mFileTimeHi = 0U;
  sf_mex_assign(&c12_m0, sf_mex_createstruct("nameCaptureInfo", 1, 1), FALSE);
  for (c12_i19 = 0; c12_i19 < 1; c12_i19++) {
    c12_r0 = &c12_info[c12_i19];
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c12_r0->context)), "context", "nameCaptureInfo",
                    c12_i19);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c12_r0->name)), "name", "nameCaptureInfo",
                    c12_i19);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo",
      c12_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c12_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c12_i19);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c12_r0->resolved)), "resolved",
                    "nameCaptureInfo", c12_i19);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", &c12_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c12_i19);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", &c12_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c12_i19);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo",
      &c12_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c12_i19);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo",
      &c12_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c12_i19);
  }

  sf_mex_assign(&c12_nameCaptureInfo, c12_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c12_nameCaptureInfo);
  return c12_nameCaptureInfo;
}

static const mxArray *c12_d_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc12_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(int32_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static int32_T c12_d_emlrt_marshallIn(SFc12_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  int32_T c12_y;
  int32_T c12_i20;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_i20, 1, 6, 0U, 0, 0U, 0);
  c12_y = c12_i20;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_sfEvent;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  int32_T c12_y;
  SFc12_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc12_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c12_b_sfEvent = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_sfEvent),
    &c12_thisId);
  sf_mex_destroy(&c12_b_sfEvent);
  *(int32_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static uint8_T c12_e_emlrt_marshallIn(SFc12_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c12_b_is_active_c12_CusakisME4901arcs, const
  char_T *c12_identifier)
{
  uint8_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c12_b_is_active_c12_CusakisME4901arcs), &c12_thisId);
  sf_mex_destroy(&c12_b_is_active_c12_CusakisME4901arcs);
  return c12_y;
}

static uint8_T c12_f_emlrt_marshallIn(SFc12_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  uint8_T c12_y;
  uint8_T c12_u0;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_u0, 1, 3, 0U, 0, 0U, 0);
  c12_y = c12_u0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void init_dsm_address_info(SFc12_CusakisME4901arcsInstanceStruct
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

void sf_c12_CusakisME4901arcs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3738361218U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1901933699U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3387190573U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1805096436U);
}

mxArray *sf_c12_CusakisME4901arcs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("wryUZp3f619imD943iLc8");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(8);
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
      pr[0] = (double)(16);
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

mxArray *sf_c12_CusakisME4901arcs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c12_CusakisME4901arcs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[15],T\"DD\",},{M[8],M[0],T\"is_active_c12_CusakisME4901arcs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c12_CusakisME4901arcs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc12_CusakisME4901arcsInstanceStruct *chartInstance;
    chartInstance = (SFc12_CusakisME4901arcsInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CusakisME4901arcsMachineNumber_,
           12,
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
          dimVector[1]= 8;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 16;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)
            c12_sf_marshallIn);
        }

        {
          real_T (*c12_M)[16];
          real_T (*c12_DD)[16];
          c12_DD = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 1);
          c12_M = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c12_M);
          _SFD_SET_DATA_VALUE_PTR(1U, *c12_DD);
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
  return "pC5XaSMGKVuBCHOjpNEGiC";
}

static void sf_opaque_initialize_c12_CusakisME4901arcs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc12_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c12_CusakisME4901arcs((SFc12_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
  initialize_c12_CusakisME4901arcs((SFc12_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c12_CusakisME4901arcs(void *chartInstanceVar)
{
  enable_c12_CusakisME4901arcs((SFc12_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c12_CusakisME4901arcs(void *chartInstanceVar)
{
  disable_c12_CusakisME4901arcs((SFc12_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c12_CusakisME4901arcs(void *chartInstanceVar)
{
  sf_c12_CusakisME4901arcs((SFc12_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c12_CusakisME4901arcs(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c12_CusakisME4901arcs
    ((SFc12_CusakisME4901arcsInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c12_CusakisME4901arcs();/* state var info */
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

extern void sf_internal_set_sim_state_c12_CusakisME4901arcs(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c12_CusakisME4901arcs();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c12_CusakisME4901arcs((SFc12_CusakisME4901arcsInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c12_CusakisME4901arcs(SimStruct* S)
{
  return sf_internal_get_sim_state_c12_CusakisME4901arcs(S);
}

static void sf_opaque_set_sim_state_c12_CusakisME4901arcs(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c12_CusakisME4901arcs(S, st);
}

static void sf_opaque_terminate_c12_CusakisME4901arcs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc12_CusakisME4901arcsInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CusakisME4901arcs_optimization_info();
    }

    finalize_c12_CusakisME4901arcs((SFc12_CusakisME4901arcsInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc12_CusakisME4901arcs((SFc12_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c12_CusakisME4901arcs(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c12_CusakisME4901arcs
      ((SFc12_CusakisME4901arcsInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c12_CusakisME4901arcs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CusakisME4901arcs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      12);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,12,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,12,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,12);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,12,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,12,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,12);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1466430886U));
  ssSetChecksum1(S,(2720211981U));
  ssSetChecksum2(S,(1000568594U));
  ssSetChecksum3(S,(3452333151U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c12_CusakisME4901arcs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c12_CusakisME4901arcs(SimStruct *S)
{
  SFc12_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc12_CusakisME4901arcsInstanceStruct *)utMalloc(sizeof
    (SFc12_CusakisME4901arcsInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc12_CusakisME4901arcsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c12_CusakisME4901arcs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c12_CusakisME4901arcs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c12_CusakisME4901arcs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c12_CusakisME4901arcs;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c12_CusakisME4901arcs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c12_CusakisME4901arcs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c12_CusakisME4901arcs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c12_CusakisME4901arcs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c12_CusakisME4901arcs;
  chartInstance->chartInfo.mdlStart = mdlStart_c12_CusakisME4901arcs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c12_CusakisME4901arcs;
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

void c12_CusakisME4901arcs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c12_CusakisME4901arcs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c12_CusakisME4901arcs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c12_CusakisME4901arcs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c12_CusakisME4901arcs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
