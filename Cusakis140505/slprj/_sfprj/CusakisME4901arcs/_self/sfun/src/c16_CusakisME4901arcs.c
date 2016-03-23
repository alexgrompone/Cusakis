/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CusakisME4901arcs_sfun.h"
#include "c16_CusakisME4901arcs.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CusakisME4901arcs_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c16_debug_family_names[11] = { "theta", "nargin", "nargout",
  "u1", "u2", "u3", "u4", "u5", "u6", "y", "R" };

/* Function Declarations */
static void initialize_c16_CusakisME4901arcs
  (SFc16_CusakisME4901arcsInstanceStruct *chartInstance);
static void initialize_params_c16_CusakisME4901arcs
  (SFc16_CusakisME4901arcsInstanceStruct *chartInstance);
static void enable_c16_CusakisME4901arcs(SFc16_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void disable_c16_CusakisME4901arcs(SFc16_CusakisME4901arcsInstanceStruct *
  chartInstance);
static void c16_update_debugger_state_c16_CusakisME4901arcs
  (SFc16_CusakisME4901arcsInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c16_CusakisME4901arcs
  (SFc16_CusakisME4901arcsInstanceStruct *chartInstance);
static void set_sim_state_c16_CusakisME4901arcs
  (SFc16_CusakisME4901arcsInstanceStruct *chartInstance, const mxArray *c16_st);
static void finalize_c16_CusakisME4901arcs(SFc16_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void sf_c16_CusakisME4901arcs(SFc16_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void initSimStructsc16_CusakisME4901arcs
  (SFc16_CusakisME4901arcsInstanceStruct *chartInstance);
static void registerMessagesc16_CusakisME4901arcs
  (SFc16_CusakisME4901arcsInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber);
static const mxArray *c16_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static void c16_emlrt_marshallIn(SFc16_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c16_R, const char_T *c16_identifier, real_T
  c16_y[4]);
static void c16_b_emlrt_marshallIn(SFc16_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId,
  real_T c16_y[4]);
static void c16_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_b_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static void c16_c_emlrt_marshallIn(SFc16_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c16_y, const char_T *c16_identifier, real_T
  c16_b_y[9]);
static void c16_d_emlrt_marshallIn(SFc16_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId,
  real_T c16_y[9]);
static void c16_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_c_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static real_T c16_e_emlrt_marshallIn(SFc16_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_d_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static int32_T c16_f_emlrt_marshallIn(SFc16_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static uint8_T c16_g_emlrt_marshallIn(SFc16_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c16_b_is_active_c16_CusakisME4901arcs, const
  char_T *c16_identifier);
static uint8_T c16_h_emlrt_marshallIn(SFc16_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void init_dsm_address_info(SFc16_CusakisME4901arcsInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c16_CusakisME4901arcs
  (SFc16_CusakisME4901arcsInstanceStruct *chartInstance)
{
  chartInstance->c16_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c16_is_active_c16_CusakisME4901arcs = 0U;
}

static void initialize_params_c16_CusakisME4901arcs
  (SFc16_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static void enable_c16_CusakisME4901arcs(SFc16_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c16_CusakisME4901arcs(SFc16_CusakisME4901arcsInstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c16_update_debugger_state_c16_CusakisME4901arcs
  (SFc16_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c16_CusakisME4901arcs
  (SFc16_CusakisME4901arcsInstanceStruct *chartInstance)
{
  const mxArray *c16_st;
  const mxArray *c16_y = NULL;
  int32_T c16_i0;
  real_T c16_u[4];
  const mxArray *c16_b_y = NULL;
  int32_T c16_i1;
  real_T c16_b_u[9];
  const mxArray *c16_c_y = NULL;
  uint8_T c16_hoistedGlobal;
  uint8_T c16_c_u;
  const mxArray *c16_d_y = NULL;
  real_T (*c16_e_y)[9];
  real_T (*c16_R)[4];
  c16_R = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c16_e_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c16_st = NULL;
  c16_st = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_createcellarray(3), FALSE);
  for (c16_i0 = 0; c16_i0 < 4; c16_i0++) {
    c16_u[c16_i0] = (*c16_R)[c16_i0];
  }

  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 2, 2, 2),
                FALSE);
  sf_mex_setcell(c16_y, 0, c16_b_y);
  for (c16_i1 = 0; c16_i1 < 9; c16_i1++) {
    c16_b_u[c16_i1] = (*c16_e_y)[c16_i1];
  }

  c16_c_y = NULL;
  sf_mex_assign(&c16_c_y, sf_mex_create("y", c16_b_u, 0, 0U, 1U, 0U, 1, 9),
                FALSE);
  sf_mex_setcell(c16_y, 1, c16_c_y);
  c16_hoistedGlobal = chartInstance->c16_is_active_c16_CusakisME4901arcs;
  c16_c_u = c16_hoistedGlobal;
  c16_d_y = NULL;
  sf_mex_assign(&c16_d_y, sf_mex_create("y", &c16_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c16_y, 2, c16_d_y);
  sf_mex_assign(&c16_st, c16_y, FALSE);
  return c16_st;
}

static void set_sim_state_c16_CusakisME4901arcs
  (SFc16_CusakisME4901arcsInstanceStruct *chartInstance, const mxArray *c16_st)
{
  const mxArray *c16_u;
  real_T c16_dv0[4];
  int32_T c16_i2;
  real_T c16_dv1[9];
  int32_T c16_i3;
  real_T (*c16_R)[4];
  real_T (*c16_y)[9];
  c16_R = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c16_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c16_doneDoubleBufferReInit = TRUE;
  c16_u = sf_mex_dup(c16_st);
  c16_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c16_u, 0)), "R",
                       c16_dv0);
  for (c16_i2 = 0; c16_i2 < 4; c16_i2++) {
    (*c16_R)[c16_i2] = c16_dv0[c16_i2];
  }

  c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c16_u, 1)),
    "y", c16_dv1);
  for (c16_i3 = 0; c16_i3 < 9; c16_i3++) {
    (*c16_y)[c16_i3] = c16_dv1[c16_i3];
  }

  chartInstance->c16_is_active_c16_CusakisME4901arcs = c16_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c16_u, 2)),
     "is_active_c16_CusakisME4901arcs");
  sf_mex_destroy(&c16_u);
  c16_update_debugger_state_c16_CusakisME4901arcs(chartInstance);
  sf_mex_destroy(&c16_st);
}

static void finalize_c16_CusakisME4901arcs(SFc16_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
}

static void sf_c16_CusakisME4901arcs(SFc16_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
  int32_T c16_i4;
  int32_T c16_i5;
  real_T c16_hoistedGlobal;
  real_T c16_b_hoistedGlobal;
  real_T c16_c_hoistedGlobal;
  real_T c16_d_hoistedGlobal;
  real_T c16_e_hoistedGlobal;
  real_T c16_f_hoistedGlobal;
  real_T c16_u1;
  real_T c16_u2;
  real_T c16_u3;
  real_T c16_u4;
  real_T c16_u5;
  real_T c16_u6;
  uint32_T c16_debug_family_var_map[11];
  real_T c16_theta;
  real_T c16_nargin = 6.0;
  real_T c16_nargout = 2.0;
  real_T c16_y[9];
  real_T c16_R[4];
  real_T c16_x;
  real_T c16_b_x;
  real_T c16_c_x;
  real_T c16_d_x;
  real_T c16_e_x;
  real_T c16_f_x;
  real_T c16_g_x;
  real_T c16_h_x;
  int32_T c16_i6;
  int32_T c16_i7;
  real_T *c16_b_u1;
  real_T *c16_b_u2;
  real_T *c16_b_u3;
  real_T *c16_b_u4;
  real_T *c16_b_u5;
  real_T *c16_b_u6;
  real_T (*c16_b_y)[9];
  real_T (*c16_b_R)[4];
  c16_b_u6 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c16_b_u5 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c16_b_u4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c16_b_u3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c16_b_u2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c16_b_R = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c16_b_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c16_b_u1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 15U, chartInstance->c16_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c16_b_u1, 0U);
  for (c16_i4 = 0; c16_i4 < 9; c16_i4++) {
    _SFD_DATA_RANGE_CHECK((*c16_b_y)[c16_i4], 1U);
  }

  for (c16_i5 = 0; c16_i5 < 4; c16_i5++) {
    _SFD_DATA_RANGE_CHECK((*c16_b_R)[c16_i5], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*c16_b_u2, 3U);
  _SFD_DATA_RANGE_CHECK(*c16_b_u3, 4U);
  _SFD_DATA_RANGE_CHECK(*c16_b_u4, 5U);
  _SFD_DATA_RANGE_CHECK(*c16_b_u5, 6U);
  _SFD_DATA_RANGE_CHECK(*c16_b_u6, 7U);
  chartInstance->c16_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 15U, chartInstance->c16_sfEvent);
  c16_hoistedGlobal = *c16_b_u1;
  c16_b_hoistedGlobal = *c16_b_u2;
  c16_c_hoistedGlobal = *c16_b_u3;
  c16_d_hoistedGlobal = *c16_b_u4;
  c16_e_hoistedGlobal = *c16_b_u5;
  c16_f_hoistedGlobal = *c16_b_u6;
  c16_u1 = c16_hoistedGlobal;
  c16_u2 = c16_b_hoistedGlobal;
  c16_u3 = c16_c_hoistedGlobal;
  c16_u4 = c16_d_hoistedGlobal;
  c16_u5 = c16_e_hoistedGlobal;
  c16_u6 = c16_f_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c16_debug_family_names,
    c16_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_theta, 0U, c16_c_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargin, 1U, c16_c_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargout, 2U, c16_c_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_u1, 3U, c16_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_u2, 4U, c16_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_u3, 5U, c16_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_u4, 6U, c16_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_u5, 7U, c16_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_u6, 8U, c16_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c16_y, 9U, c16_b_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c16_R, 10U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 6);
  c16_y[0] = c16_u1;
  c16_y[1] = c16_u2;
  c16_y[2] = 0.0;
  c16_y[3] = c16_u4;
  c16_y[4] = c16_u5;
  c16_y[5] = 0.0;
  c16_y[6] = 0.0;
  c16_y[7] = 0.0;
  c16_y[8] = c16_u6;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 7);
  c16_theta = c16_u3;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 9);
  c16_x = c16_theta;
  c16_b_x = c16_x;
  c16_b_x = muDoubleScalarCos(c16_b_x);
  c16_c_x = c16_theta;
  c16_d_x = c16_c_x;
  c16_d_x = muDoubleScalarSin(c16_d_x);
  c16_e_x = c16_theta;
  c16_f_x = c16_e_x;
  c16_f_x = muDoubleScalarSin(c16_f_x);
  c16_g_x = c16_theta;
  c16_h_x = c16_g_x;
  c16_h_x = muDoubleScalarCos(c16_h_x);
  c16_R[0] = c16_b_x;
  c16_R[2] = -c16_d_x;
  c16_R[1] = c16_f_x;
  c16_R[3] = c16_h_x;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, -9);
  _SFD_SYMBOL_SCOPE_POP();
  for (c16_i6 = 0; c16_i6 < 9; c16_i6++) {
    (*c16_b_y)[c16_i6] = c16_y[c16_i6];
  }

  for (c16_i7 = 0; c16_i7 < 4; c16_i7++) {
    (*c16_b_R)[c16_i7] = c16_R[c16_i7];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c16_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CusakisME4901arcsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc16_CusakisME4901arcs
  (SFc16_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static void registerMessagesc16_CusakisME4901arcs
  (SFc16_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber)
{
}

static const mxArray *c16_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_i8;
  int32_T c16_i9;
  int32_T c16_i10;
  real_T c16_b_inData[4];
  int32_T c16_i11;
  int32_T c16_i12;
  int32_T c16_i13;
  real_T c16_u[4];
  const mxArray *c16_y = NULL;
  SFc16_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc16_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_i8 = 0;
  for (c16_i9 = 0; c16_i9 < 2; c16_i9++) {
    for (c16_i10 = 0; c16_i10 < 2; c16_i10++) {
      c16_b_inData[c16_i10 + c16_i8] = (*(real_T (*)[4])c16_inData)[c16_i10 +
        c16_i8];
    }

    c16_i8 += 2;
  }

  c16_i11 = 0;
  for (c16_i12 = 0; c16_i12 < 2; c16_i12++) {
    for (c16_i13 = 0; c16_i13 < 2; c16_i13++) {
      c16_u[c16_i13 + c16_i11] = c16_b_inData[c16_i13 + c16_i11];
    }

    c16_i11 += 2;
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static void c16_emlrt_marshallIn(SFc16_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c16_R, const char_T *c16_identifier, real_T
  c16_y[4])
{
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_R), &c16_thisId, c16_y);
  sf_mex_destroy(&c16_R);
}

static void c16_b_emlrt_marshallIn(SFc16_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId,
  real_T c16_y[4])
{
  real_T c16_dv2[4];
  int32_T c16_i14;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), c16_dv2, 1, 0, 0U, 1, 0U, 2, 2,
                2);
  for (c16_i14 = 0; c16_i14 < 4; c16_i14++) {
    c16_y[c16_i14] = c16_dv2[c16_i14];
  }

  sf_mex_destroy(&c16_u);
}

static void c16_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_R;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y[4];
  int32_T c16_i15;
  int32_T c16_i16;
  int32_T c16_i17;
  SFc16_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc16_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c16_R = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_R), &c16_thisId, c16_y);
  sf_mex_destroy(&c16_R);
  c16_i15 = 0;
  for (c16_i16 = 0; c16_i16 < 2; c16_i16++) {
    for (c16_i17 = 0; c16_i17 < 2; c16_i17++) {
      (*(real_T (*)[4])c16_outData)[c16_i17 + c16_i15] = c16_y[c16_i17 + c16_i15];
    }

    c16_i15 += 2;
  }

  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_b_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_i18;
  real_T c16_b_inData[9];
  int32_T c16_i19;
  real_T c16_u[9];
  const mxArray *c16_y = NULL;
  SFc16_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc16_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  for (c16_i18 = 0; c16_i18 < 9; c16_i18++) {
    c16_b_inData[c16_i18] = (*(real_T (*)[9])c16_inData)[c16_i18];
  }

  for (c16_i19 = 0; c16_i19 < 9; c16_i19++) {
    c16_u[c16_i19] = c16_b_inData[c16_i19];
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 1, 9), FALSE);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static void c16_c_emlrt_marshallIn(SFc16_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c16_y, const char_T *c16_identifier, real_T
  c16_b_y[9])
{
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_y), &c16_thisId, c16_b_y);
  sf_mex_destroy(&c16_y);
}

static void c16_d_emlrt_marshallIn(SFc16_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId,
  real_T c16_y[9])
{
  real_T c16_dv3[9];
  int32_T c16_i20;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), c16_dv3, 1, 0, 0U, 1, 0U, 1, 9);
  for (c16_i20 = 0; c16_i20 < 9; c16_i20++) {
    c16_y[c16_i20] = c16_dv3[c16_i20];
  }

  sf_mex_destroy(&c16_u);
}

static void c16_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_y;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_b_y[9];
  int32_T c16_i21;
  SFc16_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc16_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c16_y = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_y), &c16_thisId, c16_b_y);
  sf_mex_destroy(&c16_y);
  for (c16_i21 = 0; c16_i21 < 9; c16_i21++) {
    (*(real_T (*)[9])c16_outData)[c16_i21] = c16_b_y[c16_i21];
  }

  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_c_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  real_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc16_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(real_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static real_T c16_e_emlrt_marshallIn(SFc16_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  real_T c16_y;
  real_T c16_d0;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_d0, 1, 0, 0U, 0, 0U, 0);
  c16_y = c16_d0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_nargout;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y;
  SFc16_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc16_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c16_nargout = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_nargout),
    &c16_thisId);
  sf_mex_destroy(&c16_nargout);
  *(real_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

const mxArray *sf_c16_CusakisME4901arcs_get_eml_resolved_functions_info(void)
{
  const mxArray *c16_nameCaptureInfo;
  c16_ResolvedFunctionInfo c16_info[4];
  c16_ResolvedFunctionInfo (*c16_b_info)[4];
  const mxArray *c16_m0 = NULL;
  int32_T c16_i22;
  c16_ResolvedFunctionInfo *c16_r0;
  c16_nameCaptureInfo = NULL;
  c16_nameCaptureInfo = NULL;
  c16_b_info = (c16_ResolvedFunctionInfo (*)[4])c16_info;
  (*c16_b_info)[0].context = "";
  (*c16_b_info)[0].name = "cos";
  (*c16_b_info)[0].dominantType = "double";
  (*c16_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c16_b_info)[0].fileTimeLo = 1343862772U;
  (*c16_b_info)[0].fileTimeHi = 0U;
  (*c16_b_info)[0].mFileTimeLo = 0U;
  (*c16_b_info)[0].mFileTimeHi = 0U;
  (*c16_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c16_b_info)[1].name = "eml_scalar_cos";
  (*c16_b_info)[1].dominantType = "double";
  (*c16_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c16_b_info)[1].fileTimeLo = 1286851122U;
  (*c16_b_info)[1].fileTimeHi = 0U;
  (*c16_b_info)[1].mFileTimeLo = 0U;
  (*c16_b_info)[1].mFileTimeHi = 0U;
  (*c16_b_info)[2].context = "";
  (*c16_b_info)[2].name = "sin";
  (*c16_b_info)[2].dominantType = "double";
  (*c16_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c16_b_info)[2].fileTimeLo = 1343862786U;
  (*c16_b_info)[2].fileTimeHi = 0U;
  (*c16_b_info)[2].mFileTimeLo = 0U;
  (*c16_b_info)[2].mFileTimeHi = 0U;
  (*c16_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c16_b_info)[3].name = "eml_scalar_sin";
  (*c16_b_info)[3].dominantType = "double";
  (*c16_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c16_b_info)[3].fileTimeLo = 1286851136U;
  (*c16_b_info)[3].fileTimeHi = 0U;
  (*c16_b_info)[3].mFileTimeLo = 0U;
  (*c16_b_info)[3].mFileTimeHi = 0U;
  sf_mex_assign(&c16_m0, sf_mex_createstruct("nameCaptureInfo", 1, 4), FALSE);
  for (c16_i22 = 0; c16_i22 < 4; c16_i22++) {
    c16_r0 = &c16_info[c16_i22];
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", c16_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c16_r0->context)), "context", "nameCaptureInfo",
                    c16_i22);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", c16_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c16_r0->name)), "name", "nameCaptureInfo",
                    c16_i22);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo",
      c16_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c16_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c16_i22);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", c16_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c16_r0->resolved)), "resolved",
                    "nameCaptureInfo", c16_i22);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", &c16_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c16_i22);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", &c16_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c16_i22);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo",
      &c16_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c16_i22);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo",
      &c16_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c16_i22);
  }

  sf_mex_assign(&c16_nameCaptureInfo, c16_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c16_nameCaptureInfo);
  return c16_nameCaptureInfo;
}

static const mxArray *c16_d_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc16_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(int32_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static int32_T c16_f_emlrt_marshallIn(SFc16_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  int32_T c16_y;
  int32_T c16_i23;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_i23, 1, 6, 0U, 0, 0U, 0);
  c16_y = c16_i23;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_b_sfEvent;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  int32_T c16_y;
  SFc16_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc16_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c16_b_sfEvent = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_sfEvent),
    &c16_thisId);
  sf_mex_destroy(&c16_b_sfEvent);
  *(int32_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static uint8_T c16_g_emlrt_marshallIn(SFc16_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c16_b_is_active_c16_CusakisME4901arcs, const
  char_T *c16_identifier)
{
  uint8_T c16_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c16_b_is_active_c16_CusakisME4901arcs), &c16_thisId);
  sf_mex_destroy(&c16_b_is_active_c16_CusakisME4901arcs);
  return c16_y;
}

static uint8_T c16_h_emlrt_marshallIn(SFc16_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  uint8_T c16_y;
  uint8_T c16_u0;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_u0, 1, 3, 0U, 0, 0U, 0);
  c16_y = c16_u0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void init_dsm_address_info(SFc16_CusakisME4901arcsInstanceStruct
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

void sf_c16_CusakisME4901arcs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2566699593U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1694481937U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1179106232U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2451364766U);
}

mxArray *sf_c16_CusakisME4901arcs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Kp1xowPSfXFBuSBkQEcUWE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(2);
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

mxArray *sf_c16_CusakisME4901arcs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c16_CusakisME4901arcs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[6],T\"R\",},{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c16_CusakisME4901arcs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c16_CusakisME4901arcs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc16_CusakisME4901arcsInstanceStruct *chartInstance;
    chartInstance = (SFc16_CusakisME4901arcsInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CusakisME4901arcsMachineNumber_,
           16,
           1,
           1,
           8,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"u1");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,2,0,1,"R");
          _SFD_SET_DATA_PROPS(3,1,1,0,"u2");
          _SFD_SET_DATA_PROPS(4,1,1,0,"u3");
          _SFD_SET_DATA_PROPS(5,1,1,0,"u4");
          _SFD_SET_DATA_PROPS(6,1,1,0,"u5");
          _SFD_SET_DATA_PROPS(7,1,1,0,"u6");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,196);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c16_b_sf_marshallOut,(MexInFcnForType)
            c16_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)
            c16_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c16_u1;
          real_T *c16_u2;
          real_T *c16_u3;
          real_T *c16_u4;
          real_T *c16_u5;
          real_T *c16_u6;
          real_T (*c16_y)[9];
          real_T (*c16_R)[4];
          c16_u6 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c16_u5 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c16_u4 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c16_u3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c16_u2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c16_R = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
          c16_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c16_u1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c16_u1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c16_y);
          _SFD_SET_DATA_VALUE_PTR(2U, *c16_R);
          _SFD_SET_DATA_VALUE_PTR(3U, c16_u2);
          _SFD_SET_DATA_VALUE_PTR(4U, c16_u3);
          _SFD_SET_DATA_VALUE_PTR(5U, c16_u4);
          _SFD_SET_DATA_VALUE_PTR(6U, c16_u5);
          _SFD_SET_DATA_VALUE_PTR(7U, c16_u6);
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
  return "boxuTahpCREaBaJNBTeFqH";
}

static void sf_opaque_initialize_c16_CusakisME4901arcs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc16_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c16_CusakisME4901arcs((SFc16_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
  initialize_c16_CusakisME4901arcs((SFc16_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c16_CusakisME4901arcs(void *chartInstanceVar)
{
  enable_c16_CusakisME4901arcs((SFc16_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c16_CusakisME4901arcs(void *chartInstanceVar)
{
  disable_c16_CusakisME4901arcs((SFc16_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c16_CusakisME4901arcs(void *chartInstanceVar)
{
  sf_c16_CusakisME4901arcs((SFc16_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c16_CusakisME4901arcs(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c16_CusakisME4901arcs
    ((SFc16_CusakisME4901arcsInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c16_CusakisME4901arcs();/* state var info */
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

extern void sf_internal_set_sim_state_c16_CusakisME4901arcs(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c16_CusakisME4901arcs();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c16_CusakisME4901arcs((SFc16_CusakisME4901arcsInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c16_CusakisME4901arcs(SimStruct* S)
{
  return sf_internal_get_sim_state_c16_CusakisME4901arcs(S);
}

static void sf_opaque_set_sim_state_c16_CusakisME4901arcs(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c16_CusakisME4901arcs(S, st);
}

static void sf_opaque_terminate_c16_CusakisME4901arcs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc16_CusakisME4901arcsInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CusakisME4901arcs_optimization_info();
    }

    finalize_c16_CusakisME4901arcs((SFc16_CusakisME4901arcsInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc16_CusakisME4901arcs((SFc16_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c16_CusakisME4901arcs(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c16_CusakisME4901arcs
      ((SFc16_CusakisME4901arcsInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c16_CusakisME4901arcs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CusakisME4901arcs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      16);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,16,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,16,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,16);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,16,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,16,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,16);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2428259624U));
  ssSetChecksum1(S,(3799107158U));
  ssSetChecksum2(S,(1671135232U));
  ssSetChecksum3(S,(808003525U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c16_CusakisME4901arcs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c16_CusakisME4901arcs(SimStruct *S)
{
  SFc16_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc16_CusakisME4901arcsInstanceStruct *)utMalloc(sizeof
    (SFc16_CusakisME4901arcsInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc16_CusakisME4901arcsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c16_CusakisME4901arcs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c16_CusakisME4901arcs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c16_CusakisME4901arcs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c16_CusakisME4901arcs;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c16_CusakisME4901arcs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c16_CusakisME4901arcs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c16_CusakisME4901arcs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c16_CusakisME4901arcs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c16_CusakisME4901arcs;
  chartInstance->chartInfo.mdlStart = mdlStart_c16_CusakisME4901arcs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c16_CusakisME4901arcs;
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

void c16_CusakisME4901arcs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c16_CusakisME4901arcs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c16_CusakisME4901arcs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c16_CusakisME4901arcs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c16_CusakisME4901arcs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
