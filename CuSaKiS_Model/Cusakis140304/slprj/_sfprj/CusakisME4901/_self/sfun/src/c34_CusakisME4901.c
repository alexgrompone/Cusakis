/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CusakisME4901_sfun.h"
#include "c34_CusakisME4901.h"
#include <string.h>
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
static const char * c34_debug_family_names[10] = { "R", "L", "nargin", "nargout",
  "VelR", "VelL", "HiR", "LoR", "HiL", "LoL" };

/* Function Declarations */
static void initialize_c34_CusakisME4901(SFc34_CusakisME4901InstanceStruct
  *chartInstance);
static void initialize_params_c34_CusakisME4901
  (SFc34_CusakisME4901InstanceStruct *chartInstance);
static void enable_c34_CusakisME4901(SFc34_CusakisME4901InstanceStruct
  *chartInstance);
static void disable_c34_CusakisME4901(SFc34_CusakisME4901InstanceStruct
  *chartInstance);
static void c34_update_debugger_state_c34_CusakisME4901
  (SFc34_CusakisME4901InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c34_CusakisME4901
  (SFc34_CusakisME4901InstanceStruct *chartInstance);
static void set_sim_state_c34_CusakisME4901(SFc34_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c34_st);
static void finalize_c34_CusakisME4901(SFc34_CusakisME4901InstanceStruct
  *chartInstance);
static void sf_c34_CusakisME4901(SFc34_CusakisME4901InstanceStruct
  *chartInstance);
static void initSimStructsc34_CusakisME4901(SFc34_CusakisME4901InstanceStruct
  *chartInstance);
static void registerMessagesc34_CusakisME4901(SFc34_CusakisME4901InstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c34_machineNumber, uint32_T
  c34_chartNumber);
static const mxArray *c34_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData);
static uint8_T c34_emlrt_marshallIn(SFc34_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c34_LoL, const char_T *c34_identifier);
static uint8_T c34_b_emlrt_marshallIn(SFc34_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId);
static void c34_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData);
static const mxArray *c34_b_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData);
static real_T c34_c_emlrt_marshallIn(SFc34_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId);
static void c34_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData);
static const mxArray *c34_c_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData);
static void c34_d_emlrt_marshallIn(SFc34_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId,
  uint8_T c34_y[2]);
static void c34_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData);
static void c34_typecast(SFc34_CusakisME4901InstanceStruct *chartInstance,
  int16_T c34_x, uint8_T c34_y[2]);
static const mxArray *c34_d_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData);
static int32_T c34_e_emlrt_marshallIn(SFc34_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId);
static void c34_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData);
static void init_dsm_address_info(SFc34_CusakisME4901InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c34_CusakisME4901(SFc34_CusakisME4901InstanceStruct
  *chartInstance)
{
  chartInstance->c34_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c34_is_active_c34_CusakisME4901 = 0U;
}

static void initialize_params_c34_CusakisME4901
  (SFc34_CusakisME4901InstanceStruct *chartInstance)
{
}

static void enable_c34_CusakisME4901(SFc34_CusakisME4901InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c34_CusakisME4901(SFc34_CusakisME4901InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c34_update_debugger_state_c34_CusakisME4901
  (SFc34_CusakisME4901InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c34_CusakisME4901
  (SFc34_CusakisME4901InstanceStruct *chartInstance)
{
  const mxArray *c34_st;
  const mxArray *c34_y = NULL;
  uint8_T c34_hoistedGlobal;
  uint8_T c34_u;
  const mxArray *c34_b_y = NULL;
  uint8_T c34_b_hoistedGlobal;
  uint8_T c34_b_u;
  const mxArray *c34_c_y = NULL;
  uint8_T c34_c_hoistedGlobal;
  uint8_T c34_c_u;
  const mxArray *c34_d_y = NULL;
  uint8_T c34_d_hoistedGlobal;
  uint8_T c34_d_u;
  const mxArray *c34_e_y = NULL;
  uint8_T c34_e_hoistedGlobal;
  uint8_T c34_e_u;
  const mxArray *c34_f_y = NULL;
  uint8_T *c34_HiL;
  uint8_T *c34_HiR;
  uint8_T *c34_LoL;
  uint8_T *c34_LoR;
  c34_LoL = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c34_HiL = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c34_LoR = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c34_HiR = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c34_st = NULL;
  c34_st = NULL;
  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_createcellarray(5), FALSE);
  c34_hoistedGlobal = *c34_HiL;
  c34_u = c34_hoistedGlobal;
  c34_b_y = NULL;
  sf_mex_assign(&c34_b_y, sf_mex_create("y", &c34_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c34_y, 0, c34_b_y);
  c34_b_hoistedGlobal = *c34_HiR;
  c34_b_u = c34_b_hoistedGlobal;
  c34_c_y = NULL;
  sf_mex_assign(&c34_c_y, sf_mex_create("y", &c34_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c34_y, 1, c34_c_y);
  c34_c_hoistedGlobal = *c34_LoL;
  c34_c_u = c34_c_hoistedGlobal;
  c34_d_y = NULL;
  sf_mex_assign(&c34_d_y, sf_mex_create("y", &c34_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c34_y, 2, c34_d_y);
  c34_d_hoistedGlobal = *c34_LoR;
  c34_d_u = c34_d_hoistedGlobal;
  c34_e_y = NULL;
  sf_mex_assign(&c34_e_y, sf_mex_create("y", &c34_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c34_y, 3, c34_e_y);
  c34_e_hoistedGlobal = chartInstance->c34_is_active_c34_CusakisME4901;
  c34_e_u = c34_e_hoistedGlobal;
  c34_f_y = NULL;
  sf_mex_assign(&c34_f_y, sf_mex_create("y", &c34_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c34_y, 4, c34_f_y);
  sf_mex_assign(&c34_st, c34_y, FALSE);
  return c34_st;
}

static void set_sim_state_c34_CusakisME4901(SFc34_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c34_st)
{
  const mxArray *c34_u;
  uint8_T *c34_HiL;
  uint8_T *c34_HiR;
  uint8_T *c34_LoL;
  uint8_T *c34_LoR;
  c34_LoL = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c34_HiL = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c34_LoR = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c34_HiR = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c34_doneDoubleBufferReInit = TRUE;
  c34_u = sf_mex_dup(c34_st);
  *c34_HiL = c34_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c34_u,
    0)), "HiL");
  *c34_HiR = c34_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c34_u,
    1)), "HiR");
  *c34_LoL = c34_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c34_u,
    2)), "LoL");
  *c34_LoR = c34_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c34_u,
    3)), "LoR");
  chartInstance->c34_is_active_c34_CusakisME4901 = c34_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c34_u, 4)),
     "is_active_c34_CusakisME4901");
  sf_mex_destroy(&c34_u);
  c34_update_debugger_state_c34_CusakisME4901(chartInstance);
  sf_mex_destroy(&c34_st);
}

static void finalize_c34_CusakisME4901(SFc34_CusakisME4901InstanceStruct
  *chartInstance)
{
}

static void sf_c34_CusakisME4901(SFc34_CusakisME4901InstanceStruct
  *chartInstance)
{
  real_T c34_hoistedGlobal;
  real_T c34_b_hoistedGlobal;
  real_T c34_VelR;
  real_T c34_VelL;
  uint32_T c34_debug_family_var_map[10];
  uint8_T c34_R[2];
  uint8_T c34_L[2];
  real_T c34_nargin = 2.0;
  real_T c34_nargout = 4.0;
  uint8_T c34_HiR;
  uint8_T c34_LoR;
  uint8_T c34_HiL;
  uint8_T c34_LoL;
  real_T c34_d0;
  int16_T c34_i0;
  uint8_T c34_uv0[2];
  int32_T c34_i1;
  real_T c34_d1;
  int16_T c34_i2;
  uint8_T c34_uv1[2];
  int32_T c34_i3;
  real_T *c34_b_VelR;
  uint8_T *c34_b_HiR;
  real_T *c34_b_VelL;
  uint8_T *c34_b_LoR;
  uint8_T *c34_b_HiL;
  uint8_T *c34_b_LoL;
  c34_b_LoL = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c34_b_HiL = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c34_b_LoR = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c34_b_VelL = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c34_b_HiR = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c34_b_VelR = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 33U, chartInstance->c34_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c34_b_VelR, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c34_b_HiR, 1U);
  _SFD_DATA_RANGE_CHECK(*c34_b_VelL, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*c34_b_LoR, 3U);
  _SFD_DATA_RANGE_CHECK((real_T)*c34_b_HiL, 4U);
  _SFD_DATA_RANGE_CHECK((real_T)*c34_b_LoL, 5U);
  chartInstance->c34_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 33U, chartInstance->c34_sfEvent);
  c34_hoistedGlobal = *c34_b_VelR;
  c34_b_hoistedGlobal = *c34_b_VelL;
  c34_VelR = c34_hoistedGlobal;
  c34_VelL = c34_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c34_debug_family_names,
    c34_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c34_R, 0U, c34_c_sf_marshallOut,
    c34_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c34_L, 1U, c34_c_sf_marshallOut,
    c34_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c34_nargin, 2U, c34_b_sf_marshallOut,
    c34_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c34_nargout, 3U, c34_b_sf_marshallOut,
    c34_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c34_VelR, 4U, c34_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c34_VelL, 5U, c34_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c34_HiR, 6U, c34_sf_marshallOut,
    c34_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c34_LoR, 7U, c34_sf_marshallOut,
    c34_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c34_HiL, 8U, c34_sf_marshallOut,
    c34_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c34_LoL, 9U, c34_sf_marshallOut,
    c34_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 6);
  c34_d0 = muDoubleScalarRound(c34_VelR);
  if (c34_d0 < 32768.0) {
    if (CV_SATURATION_EVAL(4, 0, 1, 1, c34_d0 >= -32768.0)) {
      c34_i0 = (int16_T)c34_d0;
    } else {
      c34_i0 = MIN_int16_T;
    }
  } else if (CV_SATURATION_EVAL(4, 0, 1, 0, c34_d0 >= 32768.0)) {
    c34_i0 = MAX_int16_T;
  } else {
    c34_i0 = 0;
  }

  c34_typecast(chartInstance, c34_i0, c34_uv0);
  for (c34_i1 = 0; c34_i1 < 2; c34_i1++) {
    c34_R[c34_i1] = c34_uv0[c34_i1];
  }

  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 9);
  c34_HiR = c34_R[1];
  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 10);
  c34_LoR = c34_R[0];
  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 12);
  c34_d1 = muDoubleScalarRound(c34_VelL);
  if (c34_d1 < 32768.0) {
    if (CV_SATURATION_EVAL(4, 0, 0, 1, c34_d1 >= -32768.0)) {
      c34_i2 = (int16_T)c34_d1;
    } else {
      c34_i2 = MIN_int16_T;
    }
  } else if (CV_SATURATION_EVAL(4, 0, 0, 0, c34_d1 >= 32768.0)) {
    c34_i2 = MAX_int16_T;
  } else {
    c34_i2 = 0;
  }

  c34_typecast(chartInstance, c34_i2, c34_uv1);
  for (c34_i3 = 0; c34_i3 < 2; c34_i3++) {
    c34_L[c34_i3] = c34_uv1[c34_i3];
  }

  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 15);
  c34_HiL = c34_L[1];
  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, 16);
  c34_LoL = c34_L[0];
  _SFD_EML_CALL(0U, chartInstance->c34_sfEvent, -16);
  _SFD_SYMBOL_SCOPE_POP();
  *c34_b_HiR = c34_HiR;
  *c34_b_LoR = c34_LoR;
  *c34_b_HiL = c34_HiL;
  *c34_b_LoL = c34_LoL;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 33U, chartInstance->c34_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CusakisME4901MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc34_CusakisME4901(SFc34_CusakisME4901InstanceStruct
  *chartInstance)
{
}

static void registerMessagesc34_CusakisME4901(SFc34_CusakisME4901InstanceStruct *
  chartInstance)
{
}

static void init_script_number_translation(uint32_T c34_machineNumber, uint32_T
  c34_chartNumber)
{
}

static const mxArray *c34_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData)
{
  const mxArray *c34_mxArrayOutData = NULL;
  uint8_T c34_u;
  const mxArray *c34_y = NULL;
  SFc34_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc34_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c34_mxArrayOutData = NULL;
  c34_u = *(uint8_T *)c34_inData;
  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_create("y", &c34_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c34_mxArrayOutData, c34_y, FALSE);
  return c34_mxArrayOutData;
}

static uint8_T c34_emlrt_marshallIn(SFc34_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c34_LoL, const char_T *c34_identifier)
{
  uint8_T c34_y;
  emlrtMsgIdentifier c34_thisId;
  c34_thisId.fIdentifier = c34_identifier;
  c34_thisId.fParent = NULL;
  c34_y = c34_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c34_LoL), &c34_thisId);
  sf_mex_destroy(&c34_LoL);
  return c34_y;
}

static uint8_T c34_b_emlrt_marshallIn(SFc34_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId)
{
  uint8_T c34_y;
  uint8_T c34_u0;
  sf_mex_import(c34_parentId, sf_mex_dup(c34_u), &c34_u0, 1, 3, 0U, 0, 0U, 0);
  c34_y = c34_u0;
  sf_mex_destroy(&c34_u);
  return c34_y;
}

static void c34_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData)
{
  const mxArray *c34_LoL;
  const char_T *c34_identifier;
  emlrtMsgIdentifier c34_thisId;
  uint8_T c34_y;
  SFc34_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc34_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c34_LoL = sf_mex_dup(c34_mxArrayInData);
  c34_identifier = c34_varName;
  c34_thisId.fIdentifier = c34_identifier;
  c34_thisId.fParent = NULL;
  c34_y = c34_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c34_LoL), &c34_thisId);
  sf_mex_destroy(&c34_LoL);
  *(uint8_T *)c34_outData = c34_y;
  sf_mex_destroy(&c34_mxArrayInData);
}

static const mxArray *c34_b_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData)
{
  const mxArray *c34_mxArrayOutData = NULL;
  real_T c34_u;
  const mxArray *c34_y = NULL;
  SFc34_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc34_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c34_mxArrayOutData = NULL;
  c34_u = *(real_T *)c34_inData;
  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_create("y", &c34_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c34_mxArrayOutData, c34_y, FALSE);
  return c34_mxArrayOutData;
}

static real_T c34_c_emlrt_marshallIn(SFc34_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId)
{
  real_T c34_y;
  real_T c34_d2;
  sf_mex_import(c34_parentId, sf_mex_dup(c34_u), &c34_d2, 1, 0, 0U, 0, 0U, 0);
  c34_y = c34_d2;
  sf_mex_destroy(&c34_u);
  return c34_y;
}

static void c34_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData)
{
  const mxArray *c34_nargout;
  const char_T *c34_identifier;
  emlrtMsgIdentifier c34_thisId;
  real_T c34_y;
  SFc34_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc34_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c34_nargout = sf_mex_dup(c34_mxArrayInData);
  c34_identifier = c34_varName;
  c34_thisId.fIdentifier = c34_identifier;
  c34_thisId.fParent = NULL;
  c34_y = c34_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c34_nargout),
    &c34_thisId);
  sf_mex_destroy(&c34_nargout);
  *(real_T *)c34_outData = c34_y;
  sf_mex_destroy(&c34_mxArrayInData);
}

static const mxArray *c34_c_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData)
{
  const mxArray *c34_mxArrayOutData = NULL;
  int32_T c34_i4;
  uint8_T c34_b_inData[2];
  int32_T c34_i5;
  uint8_T c34_u[2];
  const mxArray *c34_y = NULL;
  SFc34_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc34_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c34_mxArrayOutData = NULL;
  for (c34_i4 = 0; c34_i4 < 2; c34_i4++) {
    c34_b_inData[c34_i4] = (*(uint8_T (*)[2])c34_inData)[c34_i4];
  }

  for (c34_i5 = 0; c34_i5 < 2; c34_i5++) {
    c34_u[c34_i5] = c34_b_inData[c34_i5];
  }

  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_create("y", c34_u, 3, 0U, 1U, 0U, 2, 1, 2), FALSE);
  sf_mex_assign(&c34_mxArrayOutData, c34_y, FALSE);
  return c34_mxArrayOutData;
}

static void c34_d_emlrt_marshallIn(SFc34_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId,
  uint8_T c34_y[2])
{
  uint8_T c34_uv2[2];
  int32_T c34_i6;
  sf_mex_import(c34_parentId, sf_mex_dup(c34_u), c34_uv2, 1, 3, 0U, 1, 0U, 2, 1,
                2);
  for (c34_i6 = 0; c34_i6 < 2; c34_i6++) {
    c34_y[c34_i6] = c34_uv2[c34_i6];
  }

  sf_mex_destroy(&c34_u);
}

static void c34_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData)
{
  const mxArray *c34_L;
  const char_T *c34_identifier;
  emlrtMsgIdentifier c34_thisId;
  uint8_T c34_y[2];
  int32_T c34_i7;
  SFc34_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc34_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c34_L = sf_mex_dup(c34_mxArrayInData);
  c34_identifier = c34_varName;
  c34_thisId.fIdentifier = c34_identifier;
  c34_thisId.fParent = NULL;
  c34_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c34_L), &c34_thisId, c34_y);
  sf_mex_destroy(&c34_L);
  for (c34_i7 = 0; c34_i7 < 2; c34_i7++) {
    (*(uint8_T (*)[2])c34_outData)[c34_i7] = c34_y[c34_i7];
  }

  sf_mex_destroy(&c34_mxArrayInData);
}

const mxArray *sf_c34_CusakisME4901_get_eml_resolved_functions_info(void)
{
  const mxArray *c34_nameCaptureInfo;
  c34_ResolvedFunctionInfo c34_info[8];
  c34_ResolvedFunctionInfo (*c34_b_info)[8];
  const mxArray *c34_m0 = NULL;
  int32_T c34_i8;
  c34_ResolvedFunctionInfo *c34_r0;
  c34_nameCaptureInfo = NULL;
  c34_nameCaptureInfo = NULL;
  c34_b_info = (c34_ResolvedFunctionInfo (*)[8])c34_info;
  (*c34_b_info)[0].context = "";
  (*c34_b_info)[0].name = "typecast";
  (*c34_b_info)[0].dominantType = "int16";
  (*c34_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m";
  (*c34_b_info)[0].fileTimeLo = 1323202976U;
  (*c34_b_info)[0].fileTimeHi = 0U;
  (*c34_b_info)[0].mFileTimeLo = 0U;
  (*c34_b_info)[0].mFileTimeHi = 0U;
  (*c34_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element";
  (*c34_b_info)[1].name = "eml_int_nbits";
  (*c34_b_info)[1].dominantType = "char";
  (*c34_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_nbits.m";
  (*c34_b_info)[1].fileTimeLo = 1323202978U;
  (*c34_b_info)[1].fileTimeHi = 0U;
  (*c34_b_info)[1].mFileTimeLo = 0U;
  (*c34_b_info)[1].mFileTimeHi = 0U;
  (*c34_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element";
  (*c34_b_info)[2].name = "eml_index_rdivide";
  (*c34_b_info)[2].dominantType = "uint8";
  (*c34_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  (*c34_b_info)[2].fileTimeLo = 1286851180U;
  (*c34_b_info)[2].fileTimeHi = 0U;
  (*c34_b_info)[2].mFileTimeLo = 0U;
  (*c34_b_info)[2].mFileTimeHi = 0U;
  (*c34_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  (*c34_b_info)[3].name = "eml_index_class";
  (*c34_b_info)[3].dominantType = "";
  (*c34_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c34_b_info)[3].fileTimeLo = 1323202978U;
  (*c34_b_info)[3].fileTimeHi = 0U;
  (*c34_b_info)[3].mFileTimeLo = 0U;
  (*c34_b_info)[3].mFileTimeHi = 0U;
  (*c34_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m";
  (*c34_b_info)[4].name = "eml_index_times";
  (*c34_b_info)[4].dominantType = "double";
  (*c34_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  (*c34_b_info)[4].fileTimeLo = 1286851180U;
  (*c34_b_info)[4].fileTimeHi = 0U;
  (*c34_b_info)[4].mFileTimeLo = 0U;
  (*c34_b_info)[4].mFileTimeHi = 0U;
  (*c34_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  (*c34_b_info)[5].name = "eml_index_class";
  (*c34_b_info)[5].dominantType = "";
  (*c34_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c34_b_info)[5].fileTimeLo = 1323202978U;
  (*c34_b_info)[5].fileTimeHi = 0U;
  (*c34_b_info)[5].mFileTimeLo = 0U;
  (*c34_b_info)[5].mFileTimeHi = 0U;
  (*c34_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m";
  (*c34_b_info)[6].name = "eml_index_rdivide";
  (*c34_b_info)[6].dominantType = "coder.internal.indexInt";
  (*c34_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  (*c34_b_info)[6].fileTimeLo = 1286851180U;
  (*c34_b_info)[6].fileTimeHi = 0U;
  (*c34_b_info)[6].mFileTimeLo = 0U;
  (*c34_b_info)[6].mFileTimeHi = 0U;
  (*c34_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m";
  (*c34_b_info)[7].name = "eml_index_times";
  (*c34_b_info)[7].dominantType = "coder.internal.indexInt";
  (*c34_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  (*c34_b_info)[7].fileTimeLo = 1286851180U;
  (*c34_b_info)[7].fileTimeHi = 0U;
  (*c34_b_info)[7].mFileTimeLo = 0U;
  (*c34_b_info)[7].mFileTimeHi = 0U;
  sf_mex_assign(&c34_m0, sf_mex_createstruct("nameCaptureInfo", 1, 8), FALSE);
  for (c34_i8 = 0; c34_i8 < 8; c34_i8++) {
    c34_r0 = &c34_info[c34_i8];
    sf_mex_addfield(c34_m0, sf_mex_create("nameCaptureInfo", c34_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c34_r0->context)), "context", "nameCaptureInfo",
                    c34_i8);
    sf_mex_addfield(c34_m0, sf_mex_create("nameCaptureInfo", c34_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c34_r0->name)), "name", "nameCaptureInfo", c34_i8);
    sf_mex_addfield(c34_m0, sf_mex_create("nameCaptureInfo",
      c34_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c34_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c34_i8);
    sf_mex_addfield(c34_m0, sf_mex_create("nameCaptureInfo", c34_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c34_r0->resolved)), "resolved",
                    "nameCaptureInfo", c34_i8);
    sf_mex_addfield(c34_m0, sf_mex_create("nameCaptureInfo", &c34_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c34_i8);
    sf_mex_addfield(c34_m0, sf_mex_create("nameCaptureInfo", &c34_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c34_i8);
    sf_mex_addfield(c34_m0, sf_mex_create("nameCaptureInfo",
      &c34_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c34_i8);
    sf_mex_addfield(c34_m0, sf_mex_create("nameCaptureInfo",
      &c34_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c34_i8);
  }

  sf_mex_assign(&c34_nameCaptureInfo, c34_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c34_nameCaptureInfo);
  return c34_nameCaptureInfo;
}

static void c34_typecast(SFc34_CusakisME4901InstanceStruct *chartInstance,
  int16_T c34_x, uint8_T c34_y[2])
{
  memcpy(&c34_y[0], &c34_x, 2U);
}

static const mxArray *c34_d_sf_marshallOut(void *chartInstanceVoid, void
  *c34_inData)
{
  const mxArray *c34_mxArrayOutData = NULL;
  int32_T c34_u;
  const mxArray *c34_y = NULL;
  SFc34_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc34_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c34_mxArrayOutData = NULL;
  c34_u = *(int32_T *)c34_inData;
  c34_y = NULL;
  sf_mex_assign(&c34_y, sf_mex_create("y", &c34_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c34_mxArrayOutData, c34_y, FALSE);
  return c34_mxArrayOutData;
}

static int32_T c34_e_emlrt_marshallIn(SFc34_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c34_u, const emlrtMsgIdentifier *c34_parentId)
{
  int32_T c34_y;
  int32_T c34_i9;
  sf_mex_import(c34_parentId, sf_mex_dup(c34_u), &c34_i9, 1, 6, 0U, 0, 0U, 0);
  c34_y = c34_i9;
  sf_mex_destroy(&c34_u);
  return c34_y;
}

static void c34_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c34_mxArrayInData, const char_T *c34_varName, void *c34_outData)
{
  const mxArray *c34_b_sfEvent;
  const char_T *c34_identifier;
  emlrtMsgIdentifier c34_thisId;
  int32_T c34_y;
  SFc34_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc34_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c34_b_sfEvent = sf_mex_dup(c34_mxArrayInData);
  c34_identifier = c34_varName;
  c34_thisId.fIdentifier = c34_identifier;
  c34_thisId.fParent = NULL;
  c34_y = c34_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c34_b_sfEvent),
    &c34_thisId);
  sf_mex_destroy(&c34_b_sfEvent);
  *(int32_T *)c34_outData = c34_y;
  sf_mex_destroy(&c34_mxArrayInData);
}

static void init_dsm_address_info(SFc34_CusakisME4901InstanceStruct
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

void sf_c34_CusakisME4901_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3451091331U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3092752896U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(502318522U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1349669175U);
}

mxArray *sf_c34_CusakisME4901_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("NIwWqUN9QHPqd2RSzuTnaH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c34_CusakisME4901_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c34_CusakisME4901(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[8],T\"HiL\",},{M[1],M[5],T\"HiR\",},{M[1],M[9],T\"LoL\",},{M[1],M[7],T\"LoR\",},{M[8],M[0],T\"is_active_c34_CusakisME4901\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c34_CusakisME4901_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc34_CusakisME4901InstanceStruct *chartInstance;
    chartInstance = (SFc34_CusakisME4901InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CusakisME4901MachineNumber_,
           34,
           1,
           1,
           6,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"VelR");
          _SFD_SET_DATA_PROPS(1,2,0,1,"HiR");
          _SFD_SET_DATA_PROPS(2,1,1,0,"VelL");
          _SFD_SET_DATA_PROPS(3,2,0,1,"LoR");
          _SFD_SET_DATA_PROPS(4,2,0,1,"HiL");
          _SFD_SET_DATA_PROPS(5,2,0,1,"LoL");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,2,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,231);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,156,-1,167);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,68,-1,79);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c34_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c34_sf_marshallOut,(MexInFcnForType)c34_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c34_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c34_sf_marshallOut,(MexInFcnForType)c34_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c34_sf_marshallOut,(MexInFcnForType)c34_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c34_sf_marshallOut,(MexInFcnForType)c34_sf_marshallIn);

        {
          real_T *c34_VelR;
          uint8_T *c34_HiR;
          real_T *c34_VelL;
          uint8_T *c34_LoR;
          uint8_T *c34_HiL;
          uint8_T *c34_LoL;
          c34_LoL = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c34_HiL = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c34_LoR = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c34_VelL = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c34_HiR = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c34_VelR = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c34_VelR);
          _SFD_SET_DATA_VALUE_PTR(1U, c34_HiR);
          _SFD_SET_DATA_VALUE_PTR(2U, c34_VelL);
          _SFD_SET_DATA_VALUE_PTR(3U, c34_LoR);
          _SFD_SET_DATA_VALUE_PTR(4U, c34_HiL);
          _SFD_SET_DATA_VALUE_PTR(5U, c34_LoL);
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
  return "PkQFNtibBcZHcjouwaM2uC";
}

static void sf_opaque_initialize_c34_CusakisME4901(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc34_CusakisME4901InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c34_CusakisME4901((SFc34_CusakisME4901InstanceStruct*)
    chartInstanceVar);
  initialize_c34_CusakisME4901((SFc34_CusakisME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c34_CusakisME4901(void *chartInstanceVar)
{
  enable_c34_CusakisME4901((SFc34_CusakisME4901InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c34_CusakisME4901(void *chartInstanceVar)
{
  disable_c34_CusakisME4901((SFc34_CusakisME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c34_CusakisME4901(void *chartInstanceVar)
{
  sf_c34_CusakisME4901((SFc34_CusakisME4901InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c34_CusakisME4901(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c34_CusakisME4901
    ((SFc34_CusakisME4901InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c34_CusakisME4901();/* state var info */
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

extern void sf_internal_set_sim_state_c34_CusakisME4901(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c34_CusakisME4901();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c34_CusakisME4901((SFc34_CusakisME4901InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c34_CusakisME4901(SimStruct* S)
{
  return sf_internal_get_sim_state_c34_CusakisME4901(S);
}

static void sf_opaque_set_sim_state_c34_CusakisME4901(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c34_CusakisME4901(S, st);
}

static void sf_opaque_terminate_c34_CusakisME4901(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc34_CusakisME4901InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CusakisME4901_optimization_info();
    }

    finalize_c34_CusakisME4901((SFc34_CusakisME4901InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc34_CusakisME4901((SFc34_CusakisME4901InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c34_CusakisME4901(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c34_CusakisME4901((SFc34_CusakisME4901InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c34_CusakisME4901(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CusakisME4901_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      34);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,34,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,34,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,34);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,34,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,34,4);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,34);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(494231701U));
  ssSetChecksum1(S,(2844514483U));
  ssSetChecksum2(S,(3941769428U));
  ssSetChecksum3(S,(3780210818U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c34_CusakisME4901(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c34_CusakisME4901(SimStruct *S)
{
  SFc34_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc34_CusakisME4901InstanceStruct *)utMalloc(sizeof
    (SFc34_CusakisME4901InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc34_CusakisME4901InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c34_CusakisME4901;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c34_CusakisME4901;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c34_CusakisME4901;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c34_CusakisME4901;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c34_CusakisME4901;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c34_CusakisME4901;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c34_CusakisME4901;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c34_CusakisME4901;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c34_CusakisME4901;
  chartInstance->chartInfo.mdlStart = mdlStart_c34_CusakisME4901;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c34_CusakisME4901;
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

void c34_CusakisME4901_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c34_CusakisME4901(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c34_CusakisME4901(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c34_CusakisME4901(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c34_CusakisME4901_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
