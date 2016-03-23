/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CusakisME4901_sfun.h"
#include "c32_CusakisME4901.h"
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
static const char * c32_debug_family_names[6] = { "tempsum", "temp", "data",
  "nargin", "nargout", "checksum" };

/* Function Declarations */
static void initialize_c32_CusakisME4901(SFc32_CusakisME4901InstanceStruct
  *chartInstance);
static void initialize_params_c32_CusakisME4901
  (SFc32_CusakisME4901InstanceStruct *chartInstance);
static void enable_c32_CusakisME4901(SFc32_CusakisME4901InstanceStruct
  *chartInstance);
static void disable_c32_CusakisME4901(SFc32_CusakisME4901InstanceStruct
  *chartInstance);
static void c32_update_debugger_state_c32_CusakisME4901
  (SFc32_CusakisME4901InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c32_CusakisME4901
  (SFc32_CusakisME4901InstanceStruct *chartInstance);
static void set_sim_state_c32_CusakisME4901(SFc32_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c32_st);
static void finalize_c32_CusakisME4901(SFc32_CusakisME4901InstanceStruct
  *chartInstance);
static void sf_c32_CusakisME4901(SFc32_CusakisME4901InstanceStruct
  *chartInstance);
static void c32_chartstep_c32_CusakisME4901(SFc32_CusakisME4901InstanceStruct
  *chartInstance);
static void initSimStructsc32_CusakisME4901(SFc32_CusakisME4901InstanceStruct
  *chartInstance);
static void registerMessagesc32_CusakisME4901(SFc32_CusakisME4901InstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c32_machineNumber, uint32_T
  c32_chartNumber);
static const mxArray *c32_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData);
static uint8_T c32_emlrt_marshallIn(SFc32_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c32_checksum, const char_T *c32_identifier);
static uint8_T c32_b_emlrt_marshallIn(SFc32_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId);
static void c32_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData);
static const mxArray *c32_b_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData);
static const mxArray *c32_c_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData);
static real_T c32_c_emlrt_marshallIn(SFc32_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId);
static void c32_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData);
static const mxArray *c32_d_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData);
static void c32_d_emlrt_marshallIn(SFc32_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId,
  int16_T c32_y[13]);
static void c32_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData);
static void c32_info_helper(c32_ResolvedFunctionInfo c32_info[20]);
static void c32_eml_scalar_eg(SFc32_CusakisME4901InstanceStruct *chartInstance);
static const mxArray *c32_e_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData);
static int32_T c32_e_emlrt_marshallIn(SFc32_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId);
static void c32_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData);
static void init_dsm_address_info(SFc32_CusakisME4901InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c32_CusakisME4901(SFc32_CusakisME4901InstanceStruct
  *chartInstance)
{
  chartInstance->c32_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c32_is_active_c32_CusakisME4901 = 0U;
}

static void initialize_params_c32_CusakisME4901
  (SFc32_CusakisME4901InstanceStruct *chartInstance)
{
}

static void enable_c32_CusakisME4901(SFc32_CusakisME4901InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c32_CusakisME4901(SFc32_CusakisME4901InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c32_update_debugger_state_c32_CusakisME4901
  (SFc32_CusakisME4901InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c32_CusakisME4901
  (SFc32_CusakisME4901InstanceStruct *chartInstance)
{
  const mxArray *c32_st;
  const mxArray *c32_y = NULL;
  uint8_T c32_hoistedGlobal;
  uint8_T c32_u;
  const mxArray *c32_b_y = NULL;
  uint8_T c32_b_hoistedGlobal;
  uint8_T c32_b_u;
  const mxArray *c32_c_y = NULL;
  uint8_T *c32_checksum;
  c32_checksum = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c32_st = NULL;
  c32_st = NULL;
  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_createcellarray(2), FALSE);
  c32_hoistedGlobal = *c32_checksum;
  c32_u = c32_hoistedGlobal;
  c32_b_y = NULL;
  sf_mex_assign(&c32_b_y, sf_mex_create("y", &c32_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c32_y, 0, c32_b_y);
  c32_b_hoistedGlobal = chartInstance->c32_is_active_c32_CusakisME4901;
  c32_b_u = c32_b_hoistedGlobal;
  c32_c_y = NULL;
  sf_mex_assign(&c32_c_y, sf_mex_create("y", &c32_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c32_y, 1, c32_c_y);
  sf_mex_assign(&c32_st, c32_y, FALSE);
  return c32_st;
}

static void set_sim_state_c32_CusakisME4901(SFc32_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c32_st)
{
  const mxArray *c32_u;
  uint8_T *c32_checksum;
  c32_checksum = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c32_doneDoubleBufferReInit = TRUE;
  c32_u = sf_mex_dup(c32_st);
  *c32_checksum = c32_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c32_u, 0)), "checksum");
  chartInstance->c32_is_active_c32_CusakisME4901 = c32_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c32_u, 1)),
     "is_active_c32_CusakisME4901");
  sf_mex_destroy(&c32_u);
  c32_update_debugger_state_c32_CusakisME4901(chartInstance);
  sf_mex_destroy(&c32_st);
}

static void finalize_c32_CusakisME4901(SFc32_CusakisME4901InstanceStruct
  *chartInstance)
{
}

static void sf_c32_CusakisME4901(SFc32_CusakisME4901InstanceStruct
  *chartInstance)
{
  int32_T c32_i0;
  uint8_T *c32_checksum;
  uint8_T (*c32_data)[13];
  c32_checksum = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c32_data = (uint8_T (*)[13])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 31U, chartInstance->c32_sfEvent);
  for (c32_i0 = 0; c32_i0 < 13; c32_i0++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c32_data)[c32_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*c32_checksum, 1U);
  chartInstance->c32_sfEvent = CALL_EVENT;
  c32_chartstep_c32_CusakisME4901(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CusakisME4901MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c32_chartstep_c32_CusakisME4901(SFc32_CusakisME4901InstanceStruct
  *chartInstance)
{
  int32_T c32_i1;
  uint8_T c32_data[13];
  uint32_T c32_debug_family_var_map[6];
  real_T c32_tempsum;
  real_T c32_temp;
  int16_T c32_b_data[13];
  real_T c32_nargin = 1.0;
  real_T c32_nargout = 1.0;
  uint8_T c32_checksum;
  int32_T c32_i2;
  int32_T c32_i3;
  int16_T c32_x[13];
  int32_T c32_k;
  int32_T c32_b_k;
  real_T c32_b_x;
  real_T c32_xk;
  real_T c32_c_x;
  real_T c32_d_x;
  real_T c32_e_x;
  real_T c32_r;
  real_T c32_d0;
  uint8_T c32_u0;
  uint8_T *c32_b_checksum;
  uint8_T (*c32_c_data)[13];
  c32_b_checksum = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c32_c_data = (uint8_T (*)[13])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 31U, chartInstance->c32_sfEvent);
  for (c32_i1 = 0; c32_i1 < 13; c32_i1++) {
    c32_data[c32_i1] = (*c32_c_data)[c32_i1];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 7U, c32_debug_family_names,
    c32_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c32_tempsum, 0U, c32_c_sf_marshallOut,
    c32_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c32_temp, 1U, c32_c_sf_marshallOut,
    c32_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c32_b_data, MAX_uint32_T,
    c32_d_sf_marshallOut, c32_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c32_nargin, 3U, c32_c_sf_marshallOut,
    c32_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c32_nargout, 4U, c32_c_sf_marshallOut,
    c32_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c32_data, 2U, c32_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c32_checksum, 5U, c32_sf_marshallOut,
    c32_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, 4);
  for (c32_i2 = 0; c32_i2 < 13; c32_i2++) {
    c32_b_data[c32_i2] = c32_data[c32_i2];
  }

  _SFD_SYMBOL_SWITCH(2U, 2U);
  _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, 5);
  for (c32_i3 = 0; c32_i3 < 13; c32_i3++) {
    c32_x[c32_i3] = c32_b_data[c32_i3];
  }

  c32_tempsum = (real_T)c32_x[0];
  for (c32_k = 2; c32_k < 14; c32_k++) {
    c32_b_k = c32_k;
    c32_tempsum += (real_T)c32_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c32_b_k), 1, 13, 1, 0) - 1];
  }

  _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, 6);
  c32_b_x = c32_tempsum;
  c32_eml_scalar_eg(chartInstance);
  c32_xk = c32_b_x;
  c32_c_x = c32_xk;
  c32_eml_scalar_eg(chartInstance);
  c32_d_x = c32_c_x / 256.0;
  c32_e_x = c32_d_x;
  c32_e_x = muDoubleScalarFloor(c32_e_x);
  c32_r = c32_c_x - c32_e_x * 256.0;
  c32_temp = 255.0 - c32_r;
  _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, 8);
  c32_d0 = muDoubleScalarRound(c32_temp);
  if (c32_d0 < 256.0) {
    if (CV_SATURATION_EVAL(4, 0, 0, 1, c32_d0 >= 0.0)) {
      c32_u0 = (uint8_T)c32_d0;
    } else {
      c32_u0 = 0U;
    }
  } else if (CV_SATURATION_EVAL(4, 0, 0, 0, c32_d0 >= 256.0)) {
    c32_u0 = MAX_uint8_T;
  } else {
    c32_u0 = 0U;
  }

  c32_checksum = c32_u0;
  _SFD_EML_CALL(0U, chartInstance->c32_sfEvent, -8);
  _SFD_SYMBOL_SCOPE_POP();
  *c32_b_checksum = c32_checksum;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 31U, chartInstance->c32_sfEvent);
}

static void initSimStructsc32_CusakisME4901(SFc32_CusakisME4901InstanceStruct
  *chartInstance)
{
}

static void registerMessagesc32_CusakisME4901(SFc32_CusakisME4901InstanceStruct *
  chartInstance)
{
}

static void init_script_number_translation(uint32_T c32_machineNumber, uint32_T
  c32_chartNumber)
{
}

static const mxArray *c32_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData)
{
  const mxArray *c32_mxArrayOutData = NULL;
  uint8_T c32_u;
  const mxArray *c32_y = NULL;
  SFc32_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc32_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c32_mxArrayOutData = NULL;
  c32_u = *(uint8_T *)c32_inData;
  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", &c32_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c32_mxArrayOutData, c32_y, FALSE);
  return c32_mxArrayOutData;
}

static uint8_T c32_emlrt_marshallIn(SFc32_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c32_checksum, const char_T *c32_identifier)
{
  uint8_T c32_y;
  emlrtMsgIdentifier c32_thisId;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_y = c32_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c32_checksum),
    &c32_thisId);
  sf_mex_destroy(&c32_checksum);
  return c32_y;
}

static uint8_T c32_b_emlrt_marshallIn(SFc32_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId)
{
  uint8_T c32_y;
  uint8_T c32_u1;
  sf_mex_import(c32_parentId, sf_mex_dup(c32_u), &c32_u1, 1, 3, 0U, 0, 0U, 0);
  c32_y = c32_u1;
  sf_mex_destroy(&c32_u);
  return c32_y;
}

static void c32_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData)
{
  const mxArray *c32_checksum;
  const char_T *c32_identifier;
  emlrtMsgIdentifier c32_thisId;
  uint8_T c32_y;
  SFc32_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc32_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c32_checksum = sf_mex_dup(c32_mxArrayInData);
  c32_identifier = c32_varName;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_y = c32_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c32_checksum),
    &c32_thisId);
  sf_mex_destroy(&c32_checksum);
  *(uint8_T *)c32_outData = c32_y;
  sf_mex_destroy(&c32_mxArrayInData);
}

static const mxArray *c32_b_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData)
{
  const mxArray *c32_mxArrayOutData = NULL;
  int32_T c32_i4;
  uint8_T c32_b_inData[13];
  int32_T c32_i5;
  uint8_T c32_u[13];
  const mxArray *c32_y = NULL;
  SFc32_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc32_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c32_mxArrayOutData = NULL;
  for (c32_i4 = 0; c32_i4 < 13; c32_i4++) {
    c32_b_inData[c32_i4] = (*(uint8_T (*)[13])c32_inData)[c32_i4];
  }

  for (c32_i5 = 0; c32_i5 < 13; c32_i5++) {
    c32_u[c32_i5] = c32_b_inData[c32_i5];
  }

  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", c32_u, 3, 0U, 1U, 0U, 1, 13), FALSE);
  sf_mex_assign(&c32_mxArrayOutData, c32_y, FALSE);
  return c32_mxArrayOutData;
}

static const mxArray *c32_c_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData)
{
  const mxArray *c32_mxArrayOutData = NULL;
  real_T c32_u;
  const mxArray *c32_y = NULL;
  SFc32_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc32_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c32_mxArrayOutData = NULL;
  c32_u = *(real_T *)c32_inData;
  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", &c32_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c32_mxArrayOutData, c32_y, FALSE);
  return c32_mxArrayOutData;
}

static real_T c32_c_emlrt_marshallIn(SFc32_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId)
{
  real_T c32_y;
  real_T c32_d1;
  sf_mex_import(c32_parentId, sf_mex_dup(c32_u), &c32_d1, 1, 0, 0U, 0, 0U, 0);
  c32_y = c32_d1;
  sf_mex_destroy(&c32_u);
  return c32_y;
}

static void c32_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData)
{
  const mxArray *c32_nargout;
  const char_T *c32_identifier;
  emlrtMsgIdentifier c32_thisId;
  real_T c32_y;
  SFc32_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc32_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c32_nargout = sf_mex_dup(c32_mxArrayInData);
  c32_identifier = c32_varName;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_y = c32_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c32_nargout),
    &c32_thisId);
  sf_mex_destroy(&c32_nargout);
  *(real_T *)c32_outData = c32_y;
  sf_mex_destroy(&c32_mxArrayInData);
}

static const mxArray *c32_d_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData)
{
  const mxArray *c32_mxArrayOutData = NULL;
  int32_T c32_i6;
  int16_T c32_b_inData[13];
  int32_T c32_i7;
  int16_T c32_u[13];
  const mxArray *c32_y = NULL;
  SFc32_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc32_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c32_mxArrayOutData = NULL;
  for (c32_i6 = 0; c32_i6 < 13; c32_i6++) {
    c32_b_inData[c32_i6] = (*(int16_T (*)[13])c32_inData)[c32_i6];
  }

  for (c32_i7 = 0; c32_i7 < 13; c32_i7++) {
    c32_u[c32_i7] = c32_b_inData[c32_i7];
  }

  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", c32_u, 4, 0U, 1U, 0U, 1, 13), FALSE);
  sf_mex_assign(&c32_mxArrayOutData, c32_y, FALSE);
  return c32_mxArrayOutData;
}

static void c32_d_emlrt_marshallIn(SFc32_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId,
  int16_T c32_y[13])
{
  int16_T c32_iv0[13];
  int32_T c32_i8;
  sf_mex_import(c32_parentId, sf_mex_dup(c32_u), c32_iv0, 1, 4, 0U, 1, 0U, 1, 13);
  for (c32_i8 = 0; c32_i8 < 13; c32_i8++) {
    c32_y[c32_i8] = c32_iv0[c32_i8];
  }

  sf_mex_destroy(&c32_u);
}

static void c32_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData)
{
  const mxArray *c32_data;
  const char_T *c32_identifier;
  emlrtMsgIdentifier c32_thisId;
  int16_T c32_y[13];
  int32_T c32_i9;
  SFc32_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc32_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c32_data = sf_mex_dup(c32_mxArrayInData);
  c32_identifier = c32_varName;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c32_data), &c32_thisId, c32_y);
  sf_mex_destroy(&c32_data);
  for (c32_i9 = 0; c32_i9 < 13; c32_i9++) {
    (*(int16_T (*)[13])c32_outData)[c32_i9] = c32_y[c32_i9];
  }

  sf_mex_destroy(&c32_mxArrayInData);
}

const mxArray *sf_c32_CusakisME4901_get_eml_resolved_functions_info(void)
{
  const mxArray *c32_nameCaptureInfo;
  c32_ResolvedFunctionInfo c32_info[20];
  const mxArray *c32_m0 = NULL;
  int32_T c32_i10;
  c32_ResolvedFunctionInfo *c32_r0;
  c32_nameCaptureInfo = NULL;
  c32_nameCaptureInfo = NULL;
  c32_info_helper(c32_info);
  sf_mex_assign(&c32_m0, sf_mex_createstruct("nameCaptureInfo", 1, 20), FALSE);
  for (c32_i10 = 0; c32_i10 < 20; c32_i10++) {
    c32_r0 = &c32_info[c32_i10];
    sf_mex_addfield(c32_m0, sf_mex_create("nameCaptureInfo", c32_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c32_r0->context)), "context", "nameCaptureInfo",
                    c32_i10);
    sf_mex_addfield(c32_m0, sf_mex_create("nameCaptureInfo", c32_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c32_r0->name)), "name", "nameCaptureInfo",
                    c32_i10);
    sf_mex_addfield(c32_m0, sf_mex_create("nameCaptureInfo",
      c32_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c32_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c32_i10);
    sf_mex_addfield(c32_m0, sf_mex_create("nameCaptureInfo", c32_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c32_r0->resolved)), "resolved",
                    "nameCaptureInfo", c32_i10);
    sf_mex_addfield(c32_m0, sf_mex_create("nameCaptureInfo", &c32_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c32_i10);
    sf_mex_addfield(c32_m0, sf_mex_create("nameCaptureInfo", &c32_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c32_i10);
    sf_mex_addfield(c32_m0, sf_mex_create("nameCaptureInfo",
      &c32_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c32_i10);
    sf_mex_addfield(c32_m0, sf_mex_create("nameCaptureInfo",
      &c32_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c32_i10);
  }

  sf_mex_assign(&c32_nameCaptureInfo, c32_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c32_nameCaptureInfo);
  return c32_nameCaptureInfo;
}

static void c32_info_helper(c32_ResolvedFunctionInfo c32_info[20])
{
  c32_info[0].context = "";
  c32_info[0].name = "sum";
  c32_info[0].dominantType = "int16";
  c32_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c32_info[0].fileTimeLo = 1314769012U;
  c32_info[0].fileTimeHi = 0U;
  c32_info[0].mFileTimeLo = 0U;
  c32_info[0].mFileTimeHi = 0U;
  c32_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c32_info[1].name = "isequal";
  c32_info[1].dominantType = "int16";
  c32_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c32_info[1].fileTimeLo = 1286851158U;
  c32_info[1].fileTimeHi = 0U;
  c32_info[1].mFileTimeLo = 0U;
  c32_info[1].mFileTimeHi = 0U;
  c32_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c32_info[2].name = "eml_isequal_core";
  c32_info[2].dominantType = "int16";
  c32_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c32_info[2].fileTimeLo = 1286851186U;
  c32_info[2].fileTimeHi = 0U;
  c32_info[2].mFileTimeLo = 0U;
  c32_info[2].mFileTimeHi = 0U;
  c32_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c32_info[3].name = "eml_const_nonsingleton_dim";
  c32_info[3].dominantType = "int16";
  c32_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c32_info[3].fileTimeLo = 1286851096U;
  c32_info[3].fileTimeHi = 0U;
  c32_info[3].mFileTimeLo = 0U;
  c32_info[3].mFileTimeHi = 0U;
  c32_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c32_info[4].name = "eml_scalar_eg";
  c32_info[4].dominantType = "double";
  c32_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c32_info[4].fileTimeLo = 1286851196U;
  c32_info[4].fileTimeHi = 0U;
  c32_info[4].mFileTimeLo = 0U;
  c32_info[4].mFileTimeHi = 0U;
  c32_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c32_info[5].name = "eml_index_class";
  c32_info[5].dominantType = "";
  c32_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c32_info[5].fileTimeLo = 1323202978U;
  c32_info[5].fileTimeHi = 0U;
  c32_info[5].mFileTimeLo = 0U;
  c32_info[5].mFileTimeHi = 0U;
  c32_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c32_info[6].name = "eml_int_forloop_overflow_check";
  c32_info[6].dominantType = "";
  c32_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c32_info[6].fileTimeLo = 1346542740U;
  c32_info[6].fileTimeHi = 0U;
  c32_info[6].mFileTimeLo = 0U;
  c32_info[6].mFileTimeHi = 0U;
  c32_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c32_info[7].name = "intmax";
  c32_info[7].dominantType = "char";
  c32_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c32_info[7].fileTimeLo = 1311287716U;
  c32_info[7].fileTimeHi = 0U;
  c32_info[7].mFileTimeLo = 0U;
  c32_info[7].mFileTimeHi = 0U;
  c32_info[8].context = "";
  c32_info[8].name = "mod";
  c32_info[8].dominantType = "double";
  c32_info[8].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c32_info[8].fileTimeLo = 1343862782U;
  c32_info[8].fileTimeHi = 0U;
  c32_info[8].mFileTimeLo = 0U;
  c32_info[8].mFileTimeHi = 0U;
  c32_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c32_info[9].name = "eml_scalar_eg";
  c32_info[9].dominantType = "double";
  c32_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c32_info[9].fileTimeLo = 1286851196U;
  c32_info[9].fileTimeHi = 0U;
  c32_info[9].mFileTimeLo = 0U;
  c32_info[9].mFileTimeHi = 0U;
  c32_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c32_info[10].name = "eml_scalexp_alloc";
  c32_info[10].dominantType = "double";
  c32_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c32_info[10].fileTimeLo = 1352457260U;
  c32_info[10].fileTimeHi = 0U;
  c32_info[10].mFileTimeLo = 0U;
  c32_info[10].mFileTimeHi = 0U;
  c32_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c32_info[11].name = "eml_scalar_eg";
  c32_info[11].dominantType = "double";
  c32_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c32_info[11].fileTimeLo = 1286851196U;
  c32_info[11].fileTimeHi = 0U;
  c32_info[11].mFileTimeLo = 0U;
  c32_info[11].mFileTimeHi = 0U;
  c32_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c32_info[12].name = "eml_scalar_floor";
  c32_info[12].dominantType = "double";
  c32_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c32_info[12].fileTimeLo = 1286851126U;
  c32_info[12].fileTimeHi = 0U;
  c32_info[12].mFileTimeLo = 0U;
  c32_info[12].mFileTimeHi = 0U;
  c32_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c32_info[13].name = "eml_scalar_round";
  c32_info[13].dominantType = "double";
  c32_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c32_info[13].fileTimeLo = 1307683638U;
  c32_info[13].fileTimeHi = 0U;
  c32_info[13].mFileTimeLo = 0U;
  c32_info[13].mFileTimeHi = 0U;
  c32_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c32_info[14].name = "eml_scalar_abs";
  c32_info[14].dominantType = "double";
  c32_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c32_info[14].fileTimeLo = 1286851112U;
  c32_info[14].fileTimeHi = 0U;
  c32_info[14].mFileTimeLo = 0U;
  c32_info[14].mFileTimeHi = 0U;
  c32_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c32_info[15].name = "eps";
  c32_info[15].dominantType = "char";
  c32_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c32_info[15].fileTimeLo = 1326760396U;
  c32_info[15].fileTimeHi = 0U;
  c32_info[15].mFileTimeLo = 0U;
  c32_info[15].mFileTimeHi = 0U;
  c32_info[16].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c32_info[16].name = "eml_is_float_class";
  c32_info[16].dominantType = "char";
  c32_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c32_info[16].fileTimeLo = 1286851182U;
  c32_info[16].fileTimeHi = 0U;
  c32_info[16].mFileTimeLo = 0U;
  c32_info[16].mFileTimeHi = 0U;
  c32_info[17].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c32_info[17].name = "eml_eps";
  c32_info[17].dominantType = "char";
  c32_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c32_info[17].fileTimeLo = 1326760396U;
  c32_info[17].fileTimeHi = 0U;
  c32_info[17].mFileTimeLo = 0U;
  c32_info[17].mFileTimeHi = 0U;
  c32_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c32_info[18].name = "eml_float_model";
  c32_info[18].dominantType = "char";
  c32_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c32_info[18].fileTimeLo = 1326760396U;
  c32_info[18].fileTimeHi = 0U;
  c32_info[18].mFileTimeLo = 0U;
  c32_info[18].mFileTimeHi = 0U;
  c32_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c32_info[19].name = "mtimes";
  c32_info[19].dominantType = "double";
  c32_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c32_info[19].fileTimeLo = 1289552092U;
  c32_info[19].fileTimeHi = 0U;
  c32_info[19].mFileTimeLo = 0U;
  c32_info[19].mFileTimeHi = 0U;
}

static void c32_eml_scalar_eg(SFc32_CusakisME4901InstanceStruct *chartInstance)
{
}

static const mxArray *c32_e_sf_marshallOut(void *chartInstanceVoid, void
  *c32_inData)
{
  const mxArray *c32_mxArrayOutData = NULL;
  int32_T c32_u;
  const mxArray *c32_y = NULL;
  SFc32_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc32_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c32_mxArrayOutData = NULL;
  c32_u = *(int32_T *)c32_inData;
  c32_y = NULL;
  sf_mex_assign(&c32_y, sf_mex_create("y", &c32_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c32_mxArrayOutData, c32_y, FALSE);
  return c32_mxArrayOutData;
}

static int32_T c32_e_emlrt_marshallIn(SFc32_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c32_u, const emlrtMsgIdentifier *c32_parentId)
{
  int32_T c32_y;
  int32_T c32_i11;
  sf_mex_import(c32_parentId, sf_mex_dup(c32_u), &c32_i11, 1, 6, 0U, 0, 0U, 0);
  c32_y = c32_i11;
  sf_mex_destroy(&c32_u);
  return c32_y;
}

static void c32_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c32_mxArrayInData, const char_T *c32_varName, void *c32_outData)
{
  const mxArray *c32_b_sfEvent;
  const char_T *c32_identifier;
  emlrtMsgIdentifier c32_thisId;
  int32_T c32_y;
  SFc32_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc32_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c32_b_sfEvent = sf_mex_dup(c32_mxArrayInData);
  c32_identifier = c32_varName;
  c32_thisId.fIdentifier = c32_identifier;
  c32_thisId.fParent = NULL;
  c32_y = c32_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c32_b_sfEvent),
    &c32_thisId);
  sf_mex_destroy(&c32_b_sfEvent);
  *(int32_T *)c32_outData = c32_y;
  sf_mex_destroy(&c32_mxArrayInData);
}

static void init_dsm_address_info(SFc32_CusakisME4901InstanceStruct
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

void sf_c32_CusakisME4901_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3963142421U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(526871893U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3978822059U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4198702505U);
}

mxArray *sf_c32_CusakisME4901_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("oExZX8VDuxS8CtRFgj6rzF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(13);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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

mxArray *sf_c32_CusakisME4901_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c32_CusakisME4901(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"checksum\",},{M[8],M[0],T\"is_active_c32_CusakisME4901\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c32_CusakisME4901_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc32_CusakisME4901InstanceStruct *chartInstance;
    chartInstance = (SFc32_CusakisME4901InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CusakisME4901MachineNumber_,
           32,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"data");
          _SFD_SET_DATA_PROPS(1,2,0,1,"checksum");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,172);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,160,-1,171);
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
          dimVector[0]= 13;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c32_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c32_sf_marshallOut,(MexInFcnForType)c32_sf_marshallIn);

        {
          uint8_T *c32_checksum;
          uint8_T (*c32_data)[13];
          c32_checksum = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c32_data = (uint8_T (*)[13])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c32_data);
          _SFD_SET_DATA_VALUE_PTR(1U, c32_checksum);
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
  return "DsloSdHY4yUTaKJliP4ZYE";
}

static void sf_opaque_initialize_c32_CusakisME4901(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc32_CusakisME4901InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c32_CusakisME4901((SFc32_CusakisME4901InstanceStruct*)
    chartInstanceVar);
  initialize_c32_CusakisME4901((SFc32_CusakisME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c32_CusakisME4901(void *chartInstanceVar)
{
  enable_c32_CusakisME4901((SFc32_CusakisME4901InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c32_CusakisME4901(void *chartInstanceVar)
{
  disable_c32_CusakisME4901((SFc32_CusakisME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c32_CusakisME4901(void *chartInstanceVar)
{
  sf_c32_CusakisME4901((SFc32_CusakisME4901InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c32_CusakisME4901(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c32_CusakisME4901
    ((SFc32_CusakisME4901InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c32_CusakisME4901();/* state var info */
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

extern void sf_internal_set_sim_state_c32_CusakisME4901(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c32_CusakisME4901();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c32_CusakisME4901((SFc32_CusakisME4901InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c32_CusakisME4901(SimStruct* S)
{
  return sf_internal_get_sim_state_c32_CusakisME4901(S);
}

static void sf_opaque_set_sim_state_c32_CusakisME4901(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c32_CusakisME4901(S, st);
}

static void sf_opaque_terminate_c32_CusakisME4901(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc32_CusakisME4901InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CusakisME4901_optimization_info();
    }

    finalize_c32_CusakisME4901((SFc32_CusakisME4901InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc32_CusakisME4901((SFc32_CusakisME4901InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c32_CusakisME4901(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c32_CusakisME4901((SFc32_CusakisME4901InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c32_CusakisME4901(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CusakisME4901_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      32);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,32,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,32,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,32);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,32,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,32,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,32);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1315591294U));
  ssSetChecksum1(S,(2362572557U));
  ssSetChecksum2(S,(4173694828U));
  ssSetChecksum3(S,(152162699U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c32_CusakisME4901(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c32_CusakisME4901(SimStruct *S)
{
  SFc32_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc32_CusakisME4901InstanceStruct *)utMalloc(sizeof
    (SFc32_CusakisME4901InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc32_CusakisME4901InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c32_CusakisME4901;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c32_CusakisME4901;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c32_CusakisME4901;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c32_CusakisME4901;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c32_CusakisME4901;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c32_CusakisME4901;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c32_CusakisME4901;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c32_CusakisME4901;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c32_CusakisME4901;
  chartInstance->chartInfo.mdlStart = mdlStart_c32_CusakisME4901;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c32_CusakisME4901;
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

void c32_CusakisME4901_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c32_CusakisME4901(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c32_CusakisME4901(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c32_CusakisME4901(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c32_CusakisME4901_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
