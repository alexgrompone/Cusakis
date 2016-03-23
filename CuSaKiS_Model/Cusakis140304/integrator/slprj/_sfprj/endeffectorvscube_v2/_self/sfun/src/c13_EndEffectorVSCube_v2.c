/* Include files */

#include <stddef.h>
#include "blas.h"
#include "EndEffectorVSCube_v2_sfun.h"
#include "c13_EndEffectorVSCube_v2.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "EndEffectorVSCube_v2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c13_debug_family_names[11] = { "nargin", "nargout",
  "collision", "x", "Vcm_an", "Vcm_bn", "W_an", "W_bn", "docking", "reset", "X"
};

/* Function Declarations */
static void initialize_c13_EndEffectorVSCube_v2
  (SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void initialize_params_c13_EndEffectorVSCube_v2
  (SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void enable_c13_EndEffectorVSCube_v2
  (SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void disable_c13_EndEffectorVSCube_v2
  (SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void c13_update_debugger_state_c13_EndEffectorVSCube_v2
  (SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c13_EndEffectorVSCube_v2
  (SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void set_sim_state_c13_EndEffectorVSCube_v2
  (SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance, const mxArray
   *c13_st);
static void finalize_c13_EndEffectorVSCube_v2
  (SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void sf_c13_EndEffectorVSCube_v2(SFc13_EndEffectorVSCube_v2InstanceStruct
  *chartInstance);
static void initSimStructsc13_EndEffectorVSCube_v2
  (SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void registerMessagesc13_EndEffectorVSCube_v2
  (SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber);
static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static void c13_emlrt_marshallIn(SFc13_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c13_X, const char_T *c13_identifier, real_T
  c13_y[10]);
static void c13_b_emlrt_marshallIn(SFc13_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
  real_T c13_y[10]);
static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static real_T c13_c_emlrt_marshallIn(SFc13_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c13_reset, const char_T *c13_identifier);
static real_T c13_d_emlrt_marshallIn(SFc13_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static const mxArray *c13_d_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static int32_T c13_e_emlrt_marshallIn(SFc13_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static uint8_T c13_f_emlrt_marshallIn(SFc13_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c13_b_is_active_c13_EndEffectorVSCube_v2, const
  char_T *c13_identifier);
static uint8_T c13_g_emlrt_marshallIn(SFc13_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void init_dsm_address_info(SFc13_EndEffectorVSCube_v2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c13_EndEffectorVSCube_v2
  (SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
  chartInstance->c13_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c13_is_active_c13_EndEffectorVSCube_v2 = 0U;
}

static void initialize_params_c13_EndEffectorVSCube_v2
  (SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static void enable_c13_EndEffectorVSCube_v2
  (SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c13_EndEffectorVSCube_v2
  (SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c13_update_debugger_state_c13_EndEffectorVSCube_v2
  (SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c13_EndEffectorVSCube_v2
  (SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
  const mxArray *c13_st;
  const mxArray *c13_y = NULL;
  int32_T c13_i0;
  real_T c13_u[10];
  const mxArray *c13_b_y = NULL;
  real_T c13_hoistedGlobal;
  real_T c13_b_u;
  const mxArray *c13_c_y = NULL;
  uint8_T c13_b_hoistedGlobal;
  uint8_T c13_c_u;
  const mxArray *c13_d_y = NULL;
  real_T *c13_reset;
  real_T (*c13_X)[10];
  c13_X = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 2);
  c13_reset = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c13_st = NULL;
  c13_st = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createcellarray(3), FALSE);
  for (c13_i0 = 0; c13_i0 < 10; c13_i0++) {
    c13_u[c13_i0] = (*c13_X)[c13_i0];
  }

  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", c13_u, 0, 0U, 1U, 0U, 1, 10), FALSE);
  sf_mex_setcell(c13_y, 0, c13_b_y);
  c13_hoistedGlobal = *c13_reset;
  c13_b_u = c13_hoistedGlobal;
  c13_c_y = NULL;
  sf_mex_assign(&c13_c_y, sf_mex_create("y", &c13_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c13_y, 1, c13_c_y);
  c13_b_hoistedGlobal = chartInstance->c13_is_active_c13_EndEffectorVSCube_v2;
  c13_c_u = c13_b_hoistedGlobal;
  c13_d_y = NULL;
  sf_mex_assign(&c13_d_y, sf_mex_create("y", &c13_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c13_y, 2, c13_d_y);
  sf_mex_assign(&c13_st, c13_y, FALSE);
  return c13_st;
}

static void set_sim_state_c13_EndEffectorVSCube_v2
  (SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance, const mxArray
   *c13_st)
{
  const mxArray *c13_u;
  real_T c13_dv0[10];
  int32_T c13_i1;
  real_T *c13_reset;
  real_T (*c13_X)[10];
  c13_X = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 2);
  c13_reset = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c13_doneDoubleBufferReInit = TRUE;
  c13_u = sf_mex_dup(c13_st);
  c13_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 0)), "X",
                       c13_dv0);
  for (c13_i1 = 0; c13_i1 < 10; c13_i1++) {
    (*c13_X)[c13_i1] = c13_dv0[c13_i1];
  }

  *c13_reset = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c13_u, 1)), "reset");
  chartInstance->c13_is_active_c13_EndEffectorVSCube_v2 = c13_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 2)),
     "is_active_c13_EndEffectorVSCube_v2");
  sf_mex_destroy(&c13_u);
  c13_update_debugger_state_c13_EndEffectorVSCube_v2(chartInstance);
  sf_mex_destroy(&c13_st);
}

static void finalize_c13_EndEffectorVSCube_v2
  (SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static void sf_c13_EndEffectorVSCube_v2(SFc13_EndEffectorVSCube_v2InstanceStruct
  *chartInstance)
{
  int32_T c13_i2;
  int32_T c13_i3;
  int32_T c13_i4;
  int32_T c13_i5;
  int32_T c13_i6;
  int32_T c13_i7;
  real_T c13_hoistedGlobal;
  real_T c13_b_hoistedGlobal;
  real_T c13_collision;
  int32_T c13_i8;
  real_T c13_x[10];
  int32_T c13_i9;
  real_T c13_Vcm_an[3];
  int32_T c13_i10;
  real_T c13_Vcm_bn[3];
  int32_T c13_i11;
  real_T c13_W_an[3];
  int32_T c13_i12;
  real_T c13_W_bn[3];
  real_T c13_docking;
  uint32_T c13_debug_family_var_map[11];
  real_T c13_nargin = 7.0;
  real_T c13_nargout = 2.0;
  real_T c13_reset;
  real_T c13_X[10];
  int32_T c13_i13;
  int32_T c13_i14;
  real_T c13_u;
  const mxArray *c13_y = NULL;
  real_T c13_b_u;
  const mxArray *c13_b_y = NULL;
  int32_T c13_i15;
  int32_T c13_i16;
  real_T *c13_b_reset;
  real_T *c13_b_collision;
  real_T *c13_b_docking;
  real_T (*c13_b_X)[10];
  real_T (*c13_b_W_bn)[3];
  real_T (*c13_b_W_an)[3];
  real_T (*c13_b_Vcm_bn)[3];
  real_T (*c13_b_Vcm_an)[3];
  real_T (*c13_b_x)[10];
  c13_b_docking = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c13_b_W_bn = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 5);
  c13_b_W_an = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
  c13_b_Vcm_bn = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c13_b_Vcm_an = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c13_b_x = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 1);
  c13_b_X = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 2);
  c13_b_collision = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c13_b_reset = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 10U, chartInstance->c13_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c13_b_reset, 0U);
  _SFD_DATA_RANGE_CHECK(*c13_b_collision, 1U);
  for (c13_i2 = 0; c13_i2 < 10; c13_i2++) {
    _SFD_DATA_RANGE_CHECK((*c13_b_X)[c13_i2], 2U);
  }

  for (c13_i3 = 0; c13_i3 < 10; c13_i3++) {
    _SFD_DATA_RANGE_CHECK((*c13_b_x)[c13_i3], 3U);
  }

  for (c13_i4 = 0; c13_i4 < 3; c13_i4++) {
    _SFD_DATA_RANGE_CHECK((*c13_b_Vcm_an)[c13_i4], 4U);
  }

  for (c13_i5 = 0; c13_i5 < 3; c13_i5++) {
    _SFD_DATA_RANGE_CHECK((*c13_b_Vcm_bn)[c13_i5], 5U);
  }

  for (c13_i6 = 0; c13_i6 < 3; c13_i6++) {
    _SFD_DATA_RANGE_CHECK((*c13_b_W_an)[c13_i6], 6U);
  }

  for (c13_i7 = 0; c13_i7 < 3; c13_i7++) {
    _SFD_DATA_RANGE_CHECK((*c13_b_W_bn)[c13_i7], 7U);
  }

  _SFD_DATA_RANGE_CHECK(*c13_b_docking, 8U);
  chartInstance->c13_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c13_sfEvent);
  c13_hoistedGlobal = *c13_b_collision;
  c13_b_hoistedGlobal = *c13_b_docking;
  c13_collision = c13_hoistedGlobal;
  for (c13_i8 = 0; c13_i8 < 10; c13_i8++) {
    c13_x[c13_i8] = (*c13_b_x)[c13_i8];
  }

  for (c13_i9 = 0; c13_i9 < 3; c13_i9++) {
    c13_Vcm_an[c13_i9] = (*c13_b_Vcm_an)[c13_i9];
  }

  for (c13_i10 = 0; c13_i10 < 3; c13_i10++) {
    c13_Vcm_bn[c13_i10] = (*c13_b_Vcm_bn)[c13_i10];
  }

  for (c13_i11 = 0; c13_i11 < 3; c13_i11++) {
    c13_W_an[c13_i11] = (*c13_b_W_an)[c13_i11];
  }

  for (c13_i12 = 0; c13_i12 < 3; c13_i12++) {
    c13_W_bn[c13_i12] = (*c13_b_W_bn)[c13_i12];
  }

  c13_docking = c13_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c13_debug_family_names,
    c13_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargin, 0U, c13_b_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargout, 1U, c13_b_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_collision, 2U, c13_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c13_x, 3U, c13_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c13_Vcm_an, 4U, c13_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c13_Vcm_bn, 5U, c13_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c13_W_an, 6U, c13_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c13_W_bn, 7U, c13_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_docking, 8U, c13_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_reset, 9U, c13_b_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_X, 10U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 4);
  for (c13_i13 = 0; c13_i13 < 10; c13_i13++) {
    c13_X[c13_i13] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 5);
  if (CV_EML_IF(0, 1, 0, c13_docking == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 6);
    for (c13_i14 = 0; c13_i14 < 10; c13_i14++) {
      c13_X[c13_i14] = c13_x[c13_i14];
    }

    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 7);
    c13_reset = 0.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 9);
    if (CV_EML_IF(0, 1, 1, c13_collision == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 10);
      c13_x[2] = c13_Vcm_an[0];
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 11);
      c13_x[3] = c13_Vcm_an[1];
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 12);
      c13_x[4] = c13_W_an[2];
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 14);
      c13_x[7] = c13_Vcm_bn[0];
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 15);
      c13_x[8] = c13_Vcm_bn[1];
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 16);
      c13_x[9] = c13_W_bn[2];
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 17);
      sf_mex_printf("%s =\\n", "ans");
      c13_u = c13_W_an[2];
      c13_y = NULL;
      sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), FALSE);
      sf_mex_call_debug("disp", 0U, 1U, 14, c13_y);
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 18);
      sf_mex_printf("%s =\\n", "ans");
      c13_b_u = c13_W_bn[2];
      c13_b_y = NULL;
      sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_b_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      sf_mex_call_debug("disp", 0U, 1U, 14, c13_b_y);
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 19);
      c13_reset = 1.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 21);
      c13_reset = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 28);
    for (c13_i15 = 0; c13_i15 < 10; c13_i15++) {
      c13_X[c13_i15] = c13_x[c13_i15];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, -28);
  _SFD_SYMBOL_SCOPE_POP();
  *c13_b_reset = c13_reset;
  for (c13_i16 = 0; c13_i16 < 10; c13_i16++) {
    (*c13_b_X)[c13_i16] = c13_X[c13_i16];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c13_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_EndEffectorVSCube_v2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc13_EndEffectorVSCube_v2
  (SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static void registerMessagesc13_EndEffectorVSCube_v2
  (SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber)
{
}

static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_i17;
  real_T c13_b_inData[10];
  int32_T c13_i18;
  real_T c13_u[10];
  const mxArray *c13_y = NULL;
  SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc13_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  for (c13_i17 = 0; c13_i17 < 10; c13_i17++) {
    c13_b_inData[c13_i17] = (*(real_T (*)[10])c13_inData)[c13_i17];
  }

  for (c13_i18 = 0; c13_i18 < 10; c13_i18++) {
    c13_u[c13_i18] = c13_b_inData[c13_i18];
  }

  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_u, 0, 0U, 1U, 0U, 1, 10), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static void c13_emlrt_marshallIn(SFc13_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c13_X, const char_T *c13_identifier, real_T
  c13_y[10])
{
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_X), &c13_thisId, c13_y);
  sf_mex_destroy(&c13_X);
}

static void c13_b_emlrt_marshallIn(SFc13_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
  real_T c13_y[10])
{
  real_T c13_dv1[10];
  int32_T c13_i19;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), c13_dv1, 1, 0, 0U, 1, 0U, 1, 10);
  for (c13_i19 = 0; c13_i19 < 10; c13_i19++) {
    c13_y[c13_i19] = c13_dv1[c13_i19];
  }

  sf_mex_destroy(&c13_u);
}

static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_X;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y[10];
  int32_T c13_i20;
  SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc13_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c13_X = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_X), &c13_thisId, c13_y);
  sf_mex_destroy(&c13_X);
  for (c13_i20 = 0; c13_i20 < 10; c13_i20++) {
    (*(real_T (*)[10])c13_outData)[c13_i20] = c13_y[c13_i20];
  }

  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  real_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc13_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(real_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static real_T c13_c_emlrt_marshallIn(SFc13_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c13_reset, const char_T *c13_identifier)
{
  real_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_reset),
    &c13_thisId);
  sf_mex_destroy(&c13_reset);
  return c13_y;
}

static real_T c13_d_emlrt_marshallIn(SFc13_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  real_T c13_y;
  real_T c13_d0;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_d0, 1, 0, 0U, 0, 0U, 0);
  c13_y = c13_d0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_reset;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y;
  SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc13_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c13_reset = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_reset),
    &c13_thisId);
  sf_mex_destroy(&c13_reset);
  *(real_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_i21;
  real_T c13_b_inData[3];
  int32_T c13_i22;
  real_T c13_u[3];
  const mxArray *c13_y = NULL;
  SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc13_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  for (c13_i21 = 0; c13_i21 < 3; c13_i21++) {
    c13_b_inData[c13_i21] = (*(real_T (*)[3])c13_inData)[c13_i21];
  }

  for (c13_i22 = 0; c13_i22 < 3; c13_i22++) {
    c13_u[c13_i22] = c13_b_inData[c13_i22];
  }

  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

const mxArray *sf_c13_EndEffectorVSCube_v2_get_eml_resolved_functions_info(void)
{
  const mxArray *c13_nameCaptureInfo = NULL;
  c13_nameCaptureInfo = NULL;
  sf_mex_assign(&c13_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c13_nameCaptureInfo;
}

static const mxArray *c13_d_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc13_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(int32_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static int32_T c13_e_emlrt_marshallIn(SFc13_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  int32_T c13_y;
  int32_T c13_i23;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_i23, 1, 6, 0U, 0, 0U, 0);
  c13_y = c13_i23;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_sfEvent;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  int32_T c13_y;
  SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc13_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c13_b_sfEvent = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_sfEvent),
    &c13_thisId);
  sf_mex_destroy(&c13_b_sfEvent);
  *(int32_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static uint8_T c13_f_emlrt_marshallIn(SFc13_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c13_b_is_active_c13_EndEffectorVSCube_v2, const
  char_T *c13_identifier)
{
  uint8_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c13_b_is_active_c13_EndEffectorVSCube_v2), &c13_thisId);
  sf_mex_destroy(&c13_b_is_active_c13_EndEffectorVSCube_v2);
  return c13_y;
}

static uint8_T c13_g_emlrt_marshallIn(SFc13_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  uint8_T c13_y;
  uint8_T c13_u0;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_u0, 1, 3, 0U, 0, 0U, 0);
  c13_y = c13_u0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void init_dsm_address_info(SFc13_EndEffectorVSCube_v2InstanceStruct
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

void sf_c13_EndEffectorVSCube_v2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2130540641U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3099956658U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1390927451U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3125704206U);
}

mxArray *sf_c13_EndEffectorVSCube_v2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("biOOrcbGsRvbxTyr5fprID");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

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
      pr[0] = (double)(10);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
      pr[0] = (double)(10);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c13_EndEffectorVSCube_v2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c13_EndEffectorVSCube_v2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"X\",},{M[1],M[11],T\"reset\",},{M[8],M[0],T\"is_active_c13_EndEffectorVSCube_v2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c13_EndEffectorVSCube_v2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance;
    chartInstance = (SFc13_EndEffectorVSCube_v2InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _EndEffectorVSCube_v2MachineNumber_,
           13,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"reset");
          _SFD_SET_DATA_PROPS(1,1,1,0,"collision");
          _SFD_SET_DATA_PROPS(2,2,0,1,"X");
          _SFD_SET_DATA_PROPS(3,1,1,0,"x");
          _SFD_SET_DATA_PROPS(4,1,1,0,"Vcm_an");
          _SFD_SET_DATA_PROPS(5,1,1,0,"Vcm_bn");
          _SFD_SET_DATA_PROPS(6,1,1,0,"W_an");
          _SFD_SET_DATA_PROPS(7,1,1,0,"W_bn");
          _SFD_SET_DATA_PROPS(8,1,1,0,"docking");
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
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,430);
        _SFD_CV_INIT_EML_IF(0,1,0,92,106,129,429);
        _SFD_CV_INIT_EML_IF(0,1,1,138,154,358,396);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_b_sf_marshallOut,(MexInFcnForType)
          c13_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)
            c13_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c13_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c13_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c13_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c13_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c13_reset;
          real_T *c13_collision;
          real_T *c13_docking;
          real_T (*c13_X)[10];
          real_T (*c13_x)[10];
          real_T (*c13_Vcm_an)[3];
          real_T (*c13_Vcm_bn)[3];
          real_T (*c13_W_an)[3];
          real_T (*c13_W_bn)[3];
          c13_docking = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c13_W_bn = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 5);
          c13_W_an = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
          c13_Vcm_bn = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
          c13_Vcm_an = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
          c13_x = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 1);
          c13_X = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 2);
          c13_collision = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c13_reset = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c13_reset);
          _SFD_SET_DATA_VALUE_PTR(1U, c13_collision);
          _SFD_SET_DATA_VALUE_PTR(2U, *c13_X);
          _SFD_SET_DATA_VALUE_PTR(3U, *c13_x);
          _SFD_SET_DATA_VALUE_PTR(4U, *c13_Vcm_an);
          _SFD_SET_DATA_VALUE_PTR(5U, *c13_Vcm_bn);
          _SFD_SET_DATA_VALUE_PTR(6U, *c13_W_an);
          _SFD_SET_DATA_VALUE_PTR(7U, *c13_W_bn);
          _SFD_SET_DATA_VALUE_PTR(8U, c13_docking);
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
  return "GZnyPbzPZdwNCrjGfpQrwC";
}

static void sf_opaque_initialize_c13_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc13_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c13_EndEffectorVSCube_v2
    ((SFc13_EndEffectorVSCube_v2InstanceStruct*) chartInstanceVar);
  initialize_c13_EndEffectorVSCube_v2((SFc13_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c13_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  enable_c13_EndEffectorVSCube_v2((SFc13_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c13_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  disable_c13_EndEffectorVSCube_v2((SFc13_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c13_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  sf_c13_EndEffectorVSCube_v2((SFc13_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c13_EndEffectorVSCube_v2
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c13_EndEffectorVSCube_v2
    ((SFc13_EndEffectorVSCube_v2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c13_EndEffectorVSCube_v2();/* state var info */
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

extern void sf_internal_set_sim_state_c13_EndEffectorVSCube_v2(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c13_EndEffectorVSCube_v2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c13_EndEffectorVSCube_v2
    ((SFc13_EndEffectorVSCube_v2InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c13_EndEffectorVSCube_v2(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c13_EndEffectorVSCube_v2(S);
}

static void sf_opaque_set_sim_state_c13_EndEffectorVSCube_v2(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c13_EndEffectorVSCube_v2(S, st);
}

static void sf_opaque_terminate_c13_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc13_EndEffectorVSCube_v2InstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_EndEffectorVSCube_v2_optimization_info();
    }

    finalize_c13_EndEffectorVSCube_v2((SFc13_EndEffectorVSCube_v2InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc13_EndEffectorVSCube_v2
    ((SFc13_EndEffectorVSCube_v2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c13_EndEffectorVSCube_v2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c13_EndEffectorVSCube_v2
      ((SFc13_EndEffectorVSCube_v2InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c13_EndEffectorVSCube_v2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_EndEffectorVSCube_v2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      13);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,13,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,13,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,13);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,13,7);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,13,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 7; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,13);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2414613329U));
  ssSetChecksum1(S,(3967906975U));
  ssSetChecksum2(S,(2573687165U));
  ssSetChecksum3(S,(3500551201U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c13_EndEffectorVSCube_v2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c13_EndEffectorVSCube_v2(SimStruct *S)
{
  SFc13_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc13_EndEffectorVSCube_v2InstanceStruct *)utMalloc(sizeof
    (SFc13_EndEffectorVSCube_v2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc13_EndEffectorVSCube_v2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c13_EndEffectorVSCube_v2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c13_EndEffectorVSCube_v2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c13_EndEffectorVSCube_v2;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c13_EndEffectorVSCube_v2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c13_EndEffectorVSCube_v2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c13_EndEffectorVSCube_v2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c13_EndEffectorVSCube_v2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c13_EndEffectorVSCube_v2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c13_EndEffectorVSCube_v2;
  chartInstance->chartInfo.mdlStart = mdlStart_c13_EndEffectorVSCube_v2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c13_EndEffectorVSCube_v2;
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

void c13_EndEffectorVSCube_v2_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c13_EndEffectorVSCube_v2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c13_EndEffectorVSCube_v2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c13_EndEffectorVSCube_v2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c13_EndEffectorVSCube_v2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
