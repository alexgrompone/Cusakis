/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CusakisME4901arcs_sfun.h"
#include "c14_CusakisME4901arcs.h"
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
static const char * c14_debug_family_names[5] = { "nargin", "nargout", "u", "y",
  "R" };

/* Function Declarations */
static void initialize_c14_CusakisME4901arcs
  (SFc14_CusakisME4901arcsInstanceStruct *chartInstance);
static void initialize_params_c14_CusakisME4901arcs
  (SFc14_CusakisME4901arcsInstanceStruct *chartInstance);
static void enable_c14_CusakisME4901arcs(SFc14_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void disable_c14_CusakisME4901arcs(SFc14_CusakisME4901arcsInstanceStruct *
  chartInstance);
static void c14_update_debugger_state_c14_CusakisME4901arcs
  (SFc14_CusakisME4901arcsInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c14_CusakisME4901arcs
  (SFc14_CusakisME4901arcsInstanceStruct *chartInstance);
static void set_sim_state_c14_CusakisME4901arcs
  (SFc14_CusakisME4901arcsInstanceStruct *chartInstance, const mxArray *c14_st);
static void finalize_c14_CusakisME4901arcs(SFc14_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void sf_c14_CusakisME4901arcs(SFc14_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void initSimStructsc14_CusakisME4901arcs
  (SFc14_CusakisME4901arcsInstanceStruct *chartInstance);
static void registerMessagesc14_CusakisME4901arcs
  (SFc14_CusakisME4901arcsInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber);
static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static void c14_emlrt_marshallIn(SFc14_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c14_R, const char_T *c14_identifier, real_T
  c14_y[4]);
static void c14_b_emlrt_marshallIn(SFc14_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[4]);
static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static void c14_c_emlrt_marshallIn(SFc14_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c14_y, const char_T *c14_identifier, real_T
  c14_b_y[9]);
static void c14_d_emlrt_marshallIn(SFc14_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[9]);
static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_c_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static const mxArray *c14_d_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static real_T c14_e_emlrt_marshallIn(SFc14_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_e_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static int32_T c14_f_emlrt_marshallIn(SFc14_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static uint8_T c14_g_emlrt_marshallIn(SFc14_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c14_b_is_active_c14_CusakisME4901arcs, const
  char_T *c14_identifier);
static uint8_T c14_h_emlrt_marshallIn(SFc14_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void init_dsm_address_info(SFc14_CusakisME4901arcsInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c14_CusakisME4901arcs
  (SFc14_CusakisME4901arcsInstanceStruct *chartInstance)
{
  chartInstance->c14_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c14_is_active_c14_CusakisME4901arcs = 0U;
}

static void initialize_params_c14_CusakisME4901arcs
  (SFc14_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static void enable_c14_CusakisME4901arcs(SFc14_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c14_CusakisME4901arcs(SFc14_CusakisME4901arcsInstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c14_update_debugger_state_c14_CusakisME4901arcs
  (SFc14_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c14_CusakisME4901arcs
  (SFc14_CusakisME4901arcsInstanceStruct *chartInstance)
{
  const mxArray *c14_st;
  const mxArray *c14_y = NULL;
  int32_T c14_i0;
  real_T c14_u[4];
  const mxArray *c14_b_y = NULL;
  int32_T c14_i1;
  real_T c14_b_u[9];
  const mxArray *c14_c_y = NULL;
  uint8_T c14_hoistedGlobal;
  uint8_T c14_c_u;
  const mxArray *c14_d_y = NULL;
  real_T (*c14_e_y)[9];
  real_T (*c14_R)[4];
  c14_R = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c14_e_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c14_st = NULL;
  c14_st = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_createcellarray(3), FALSE);
  for (c14_i0 = 0; c14_i0 < 4; c14_i0++) {
    c14_u[c14_i0] = (*c14_R)[c14_i0];
  }

  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 2, 2, 2),
                FALSE);
  sf_mex_setcell(c14_y, 0, c14_b_y);
  for (c14_i1 = 0; c14_i1 < 9; c14_i1++) {
    c14_b_u[c14_i1] = (*c14_e_y)[c14_i1];
  }

  c14_c_y = NULL;
  sf_mex_assign(&c14_c_y, sf_mex_create("y", c14_b_u, 0, 0U, 1U, 0U, 1, 9),
                FALSE);
  sf_mex_setcell(c14_y, 1, c14_c_y);
  c14_hoistedGlobal = chartInstance->c14_is_active_c14_CusakisME4901arcs;
  c14_c_u = c14_hoistedGlobal;
  c14_d_y = NULL;
  sf_mex_assign(&c14_d_y, sf_mex_create("y", &c14_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c14_y, 2, c14_d_y);
  sf_mex_assign(&c14_st, c14_y, FALSE);
  return c14_st;
}

static void set_sim_state_c14_CusakisME4901arcs
  (SFc14_CusakisME4901arcsInstanceStruct *chartInstance, const mxArray *c14_st)
{
  const mxArray *c14_u;
  real_T c14_dv0[4];
  int32_T c14_i2;
  real_T c14_dv1[9];
  int32_T c14_i3;
  real_T (*c14_R)[4];
  real_T (*c14_y)[9];
  c14_R = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c14_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c14_doneDoubleBufferReInit = TRUE;
  c14_u = sf_mex_dup(c14_st);
  c14_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 0)), "R",
                       c14_dv0);
  for (c14_i2 = 0; c14_i2 < 4; c14_i2++) {
    (*c14_R)[c14_i2] = c14_dv0[c14_i2];
  }

  c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 1)),
    "y", c14_dv1);
  for (c14_i3 = 0; c14_i3 < 9; c14_i3++) {
    (*c14_y)[c14_i3] = c14_dv1[c14_i3];
  }

  chartInstance->c14_is_active_c14_CusakisME4901arcs = c14_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 2)),
     "is_active_c14_CusakisME4901arcs");
  sf_mex_destroy(&c14_u);
  c14_update_debugger_state_c14_CusakisME4901arcs(chartInstance);
  sf_mex_destroy(&c14_st);
}

static void finalize_c14_CusakisME4901arcs(SFc14_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
}

static void sf_c14_CusakisME4901arcs(SFc14_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
  int32_T c14_i4;
  int32_T c14_i5;
  int32_T c14_i6;
  int32_T c14_i7;
  real_T c14_u[6];
  uint32_T c14_debug_family_var_map[5];
  real_T c14_nargin = 1.0;
  real_T c14_nargout = 2.0;
  real_T c14_y[9];
  real_T c14_R[4];
  real_T c14_x;
  real_T c14_b_x;
  real_T c14_c_x;
  real_T c14_d_x;
  real_T c14_e_x;
  real_T c14_f_x;
  real_T c14_g_x;
  real_T c14_h_x;
  int32_T c14_i8;
  int32_T c14_i9;
  real_T (*c14_b_y)[9];
  real_T (*c14_b_R)[4];
  real_T (*c14_b_u)[6];
  c14_b_R = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c14_b_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c14_b_u = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 13U, chartInstance->c14_sfEvent);
  for (c14_i4 = 0; c14_i4 < 6; c14_i4++) {
    _SFD_DATA_RANGE_CHECK((*c14_b_u)[c14_i4], 0U);
  }

  for (c14_i5 = 0; c14_i5 < 9; c14_i5++) {
    _SFD_DATA_RANGE_CHECK((*c14_b_y)[c14_i5], 1U);
  }

  for (c14_i6 = 0; c14_i6 < 4; c14_i6++) {
    _SFD_DATA_RANGE_CHECK((*c14_b_R)[c14_i6], 2U);
  }

  chartInstance->c14_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 13U, chartInstance->c14_sfEvent);
  for (c14_i7 = 0; c14_i7 < 6; c14_i7++) {
    c14_u[c14_i7] = (*c14_b_u)[c14_i7];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c14_debug_family_names,
    c14_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_nargin, 0U, c14_d_sf_marshallOut,
    c14_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_nargout, 1U, c14_d_sf_marshallOut,
    c14_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c14_u, 2U, c14_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c14_y, 3U, c14_b_sf_marshallOut,
    c14_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c14_R, 4U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 4);
  c14_y[0] = c14_u[0];
  c14_y[1] = c14_u[1];
  c14_y[2] = 0.0;
  c14_y[3] = c14_u[3];
  c14_y[4] = c14_u[4];
  c14_y[5] = 0.0;
  c14_y[6] = 0.0;
  c14_y[7] = 0.0;
  c14_y[8] = c14_u[5];
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 8);
  c14_x = c14_u[2];
  c14_b_x = c14_x;
  c14_b_x = muDoubleScalarCos(c14_b_x);
  c14_c_x = c14_u[2];
  c14_d_x = c14_c_x;
  c14_d_x = muDoubleScalarSin(c14_d_x);
  c14_e_x = c14_u[2];
  c14_f_x = c14_e_x;
  c14_f_x = muDoubleScalarSin(c14_f_x);
  c14_g_x = c14_u[2];
  c14_h_x = c14_g_x;
  c14_h_x = muDoubleScalarCos(c14_h_x);
  c14_R[0] = c14_b_x;
  c14_R[2] = -c14_d_x;
  c14_R[1] = c14_f_x;
  c14_R[3] = c14_h_x;
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, -8);
  _SFD_SYMBOL_SCOPE_POP();
  for (c14_i8 = 0; c14_i8 < 9; c14_i8++) {
    (*c14_b_y)[c14_i8] = c14_y[c14_i8];
  }

  for (c14_i9 = 0; c14_i9 < 4; c14_i9++) {
    (*c14_b_R)[c14_i9] = c14_R[c14_i9];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c14_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CusakisME4901arcsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc14_CusakisME4901arcs
  (SFc14_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static void registerMessagesc14_CusakisME4901arcs
  (SFc14_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber)
{
}

static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i10;
  int32_T c14_i11;
  int32_T c14_i12;
  real_T c14_b_inData[4];
  int32_T c14_i13;
  int32_T c14_i14;
  int32_T c14_i15;
  real_T c14_u[4];
  const mxArray *c14_y = NULL;
  SFc14_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc14_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_i10 = 0;
  for (c14_i11 = 0; c14_i11 < 2; c14_i11++) {
    for (c14_i12 = 0; c14_i12 < 2; c14_i12++) {
      c14_b_inData[c14_i12 + c14_i10] = (*(real_T (*)[4])c14_inData)[c14_i12 +
        c14_i10];
    }

    c14_i10 += 2;
  }

  c14_i13 = 0;
  for (c14_i14 = 0; c14_i14 < 2; c14_i14++) {
    for (c14_i15 = 0; c14_i15 < 2; c14_i15++) {
      c14_u[c14_i15 + c14_i13] = c14_b_inData[c14_i15 + c14_i13];
    }

    c14_i13 += 2;
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, FALSE);
  return c14_mxArrayOutData;
}

static void c14_emlrt_marshallIn(SFc14_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c14_R, const char_T *c14_identifier, real_T
  c14_y[4])
{
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_R), &c14_thisId, c14_y);
  sf_mex_destroy(&c14_R);
}

static void c14_b_emlrt_marshallIn(SFc14_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[4])
{
  real_T c14_dv2[4];
  int32_T c14_i16;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), c14_dv2, 1, 0, 0U, 1, 0U, 2, 2,
                2);
  for (c14_i16 = 0; c14_i16 < 4; c14_i16++) {
    c14_y[c14_i16] = c14_dv2[c14_i16];
  }

  sf_mex_destroy(&c14_u);
}

static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_R;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y[4];
  int32_T c14_i17;
  int32_T c14_i18;
  int32_T c14_i19;
  SFc14_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc14_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c14_R = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_R), &c14_thisId, c14_y);
  sf_mex_destroy(&c14_R);
  c14_i17 = 0;
  for (c14_i18 = 0; c14_i18 < 2; c14_i18++) {
    for (c14_i19 = 0; c14_i19 < 2; c14_i19++) {
      (*(real_T (*)[4])c14_outData)[c14_i19 + c14_i17] = c14_y[c14_i19 + c14_i17];
    }

    c14_i17 += 2;
  }

  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i20;
  real_T c14_b_inData[9];
  int32_T c14_i21;
  real_T c14_u[9];
  const mxArray *c14_y = NULL;
  SFc14_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc14_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  for (c14_i20 = 0; c14_i20 < 9; c14_i20++) {
    c14_b_inData[c14_i20] = (*(real_T (*)[9])c14_inData)[c14_i20];
  }

  for (c14_i21 = 0; c14_i21 < 9; c14_i21++) {
    c14_u[c14_i21] = c14_b_inData[c14_i21];
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 1, 9), FALSE);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, FALSE);
  return c14_mxArrayOutData;
}

static void c14_c_emlrt_marshallIn(SFc14_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c14_y, const char_T *c14_identifier, real_T
  c14_b_y[9])
{
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_y), &c14_thisId, c14_b_y);
  sf_mex_destroy(&c14_y);
}

static void c14_d_emlrt_marshallIn(SFc14_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[9])
{
  real_T c14_dv3[9];
  int32_T c14_i22;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), c14_dv3, 1, 0, 0U, 1, 0U, 1, 9);
  for (c14_i22 = 0; c14_i22 < 9; c14_i22++) {
    c14_y[c14_i22] = c14_dv3[c14_i22];
  }

  sf_mex_destroy(&c14_u);
}

static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_y;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_b_y[9];
  int32_T c14_i23;
  SFc14_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc14_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c14_y = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_y), &c14_thisId, c14_b_y);
  sf_mex_destroy(&c14_y);
  for (c14_i23 = 0; c14_i23 < 9; c14_i23++) {
    (*(real_T (*)[9])c14_outData)[c14_i23] = c14_b_y[c14_i23];
  }

  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_c_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i24;
  real_T c14_b_inData[6];
  int32_T c14_i25;
  real_T c14_u[6];
  const mxArray *c14_y = NULL;
  SFc14_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc14_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  for (c14_i24 = 0; c14_i24 < 6; c14_i24++) {
    c14_b_inData[c14_i24] = (*(real_T (*)[6])c14_inData)[c14_i24];
  }

  for (c14_i25 = 0; c14_i25 < 6; c14_i25++) {
    c14_u[c14_i25] = c14_b_inData[c14_i25];
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, FALSE);
  return c14_mxArrayOutData;
}

static const mxArray *c14_d_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  real_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc14_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(real_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, FALSE);
  return c14_mxArrayOutData;
}

static real_T c14_e_emlrt_marshallIn(SFc14_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  real_T c14_y;
  real_T c14_d0;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_d0, 1, 0, 0U, 0, 0U, 0);
  c14_y = c14_d0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_nargout;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y;
  SFc14_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc14_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c14_nargout = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_nargout),
    &c14_thisId);
  sf_mex_destroy(&c14_nargout);
  *(real_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

const mxArray *sf_c14_CusakisME4901arcs_get_eml_resolved_functions_info(void)
{
  const mxArray *c14_nameCaptureInfo;
  c14_ResolvedFunctionInfo c14_info[4];
  c14_ResolvedFunctionInfo (*c14_b_info)[4];
  const mxArray *c14_m0 = NULL;
  int32_T c14_i26;
  c14_ResolvedFunctionInfo *c14_r0;
  c14_nameCaptureInfo = NULL;
  c14_nameCaptureInfo = NULL;
  c14_b_info = (c14_ResolvedFunctionInfo (*)[4])c14_info;
  (*c14_b_info)[0].context = "";
  (*c14_b_info)[0].name = "cos";
  (*c14_b_info)[0].dominantType = "double";
  (*c14_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c14_b_info)[0].fileTimeLo = 1343862772U;
  (*c14_b_info)[0].fileTimeHi = 0U;
  (*c14_b_info)[0].mFileTimeLo = 0U;
  (*c14_b_info)[0].mFileTimeHi = 0U;
  (*c14_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c14_b_info)[1].name = "eml_scalar_cos";
  (*c14_b_info)[1].dominantType = "double";
  (*c14_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c14_b_info)[1].fileTimeLo = 1286851122U;
  (*c14_b_info)[1].fileTimeHi = 0U;
  (*c14_b_info)[1].mFileTimeLo = 0U;
  (*c14_b_info)[1].mFileTimeHi = 0U;
  (*c14_b_info)[2].context = "";
  (*c14_b_info)[2].name = "sin";
  (*c14_b_info)[2].dominantType = "double";
  (*c14_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c14_b_info)[2].fileTimeLo = 1343862786U;
  (*c14_b_info)[2].fileTimeHi = 0U;
  (*c14_b_info)[2].mFileTimeLo = 0U;
  (*c14_b_info)[2].mFileTimeHi = 0U;
  (*c14_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c14_b_info)[3].name = "eml_scalar_sin";
  (*c14_b_info)[3].dominantType = "double";
  (*c14_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c14_b_info)[3].fileTimeLo = 1286851136U;
  (*c14_b_info)[3].fileTimeHi = 0U;
  (*c14_b_info)[3].mFileTimeLo = 0U;
  (*c14_b_info)[3].mFileTimeHi = 0U;
  sf_mex_assign(&c14_m0, sf_mex_createstruct("nameCaptureInfo", 1, 4), FALSE);
  for (c14_i26 = 0; c14_i26 < 4; c14_i26++) {
    c14_r0 = &c14_info[c14_i26];
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", c14_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c14_r0->context)), "context", "nameCaptureInfo",
                    c14_i26);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", c14_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c14_r0->name)), "name", "nameCaptureInfo",
                    c14_i26);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo",
      c14_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c14_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c14_i26);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", c14_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c14_r0->resolved)), "resolved",
                    "nameCaptureInfo", c14_i26);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", &c14_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c14_i26);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", &c14_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c14_i26);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo",
      &c14_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c14_i26);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo",
      &c14_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c14_i26);
  }

  sf_mex_assign(&c14_nameCaptureInfo, c14_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c14_nameCaptureInfo);
  return c14_nameCaptureInfo;
}

static const mxArray *c14_e_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc14_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(int32_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, FALSE);
  return c14_mxArrayOutData;
}

static int32_T c14_f_emlrt_marshallIn(SFc14_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  int32_T c14_y;
  int32_T c14_i27;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_i27, 1, 6, 0U, 0, 0U, 0);
  c14_y = c14_i27;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_b_sfEvent;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  int32_T c14_y;
  SFc14_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc14_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c14_b_sfEvent = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_sfEvent),
    &c14_thisId);
  sf_mex_destroy(&c14_b_sfEvent);
  *(int32_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static uint8_T c14_g_emlrt_marshallIn(SFc14_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c14_b_is_active_c14_CusakisME4901arcs, const
  char_T *c14_identifier)
{
  uint8_T c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c14_b_is_active_c14_CusakisME4901arcs), &c14_thisId);
  sf_mex_destroy(&c14_b_is_active_c14_CusakisME4901arcs);
  return c14_y;
}

static uint8_T c14_h_emlrt_marshallIn(SFc14_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  uint8_T c14_y;
  uint8_T c14_u0;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_u0, 1, 3, 0U, 0, 0U, 0);
  c14_y = c14_u0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void init_dsm_address_info(SFc14_CusakisME4901arcsInstanceStruct
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

void sf_c14_CusakisME4901arcs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3999668525U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2697575527U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2905023308U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1753810094U);
}

mxArray *sf_c14_CusakisME4901arcs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ZEJ4AuSlTUFbT0q5bqk2SB");
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

mxArray *sf_c14_CusakisME4901arcs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c14_CusakisME4901arcs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[6],T\"R\",},{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c14_CusakisME4901arcs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c14_CusakisME4901arcs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc14_CusakisME4901arcsInstanceStruct *chartInstance;
    chartInstance = (SFc14_CusakisME4901arcsInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CusakisME4901arcsMachineNumber_,
           14,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,2,0,1,"R");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,140);
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
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c14_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c14_b_sf_marshallOut,(MexInFcnForType)
            c14_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c14_sf_marshallOut,(MexInFcnForType)
            c14_sf_marshallIn);
        }

        {
          real_T (*c14_u)[6];
          real_T (*c14_y)[9];
          real_T (*c14_R)[4];
          c14_R = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
          c14_y = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c14_u = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c14_u);
          _SFD_SET_DATA_VALUE_PTR(1U, *c14_y);
          _SFD_SET_DATA_VALUE_PTR(2U, *c14_R);
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
  return "WpsYK5f2xmfeW7REhZBF6G";
}

static void sf_opaque_initialize_c14_CusakisME4901arcs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc14_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c14_CusakisME4901arcs((SFc14_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
  initialize_c14_CusakisME4901arcs((SFc14_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c14_CusakisME4901arcs(void *chartInstanceVar)
{
  enable_c14_CusakisME4901arcs((SFc14_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c14_CusakisME4901arcs(void *chartInstanceVar)
{
  disable_c14_CusakisME4901arcs((SFc14_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c14_CusakisME4901arcs(void *chartInstanceVar)
{
  sf_c14_CusakisME4901arcs((SFc14_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c14_CusakisME4901arcs(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c14_CusakisME4901arcs
    ((SFc14_CusakisME4901arcsInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c14_CusakisME4901arcs();/* state var info */
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

extern void sf_internal_set_sim_state_c14_CusakisME4901arcs(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c14_CusakisME4901arcs();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c14_CusakisME4901arcs((SFc14_CusakisME4901arcsInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c14_CusakisME4901arcs(SimStruct* S)
{
  return sf_internal_get_sim_state_c14_CusakisME4901arcs(S);
}

static void sf_opaque_set_sim_state_c14_CusakisME4901arcs(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c14_CusakisME4901arcs(S, st);
}

static void sf_opaque_terminate_c14_CusakisME4901arcs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc14_CusakisME4901arcsInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CusakisME4901arcs_optimization_info();
    }

    finalize_c14_CusakisME4901arcs((SFc14_CusakisME4901arcsInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc14_CusakisME4901arcs((SFc14_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c14_CusakisME4901arcs(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c14_CusakisME4901arcs
      ((SFc14_CusakisME4901arcsInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c14_CusakisME4901arcs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CusakisME4901arcs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      14);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,14,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,14,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,14);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,14,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,14,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,14);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4219623756U));
  ssSetChecksum1(S,(2137227374U));
  ssSetChecksum2(S,(1849566621U));
  ssSetChecksum3(S,(857704460U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c14_CusakisME4901arcs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c14_CusakisME4901arcs(SimStruct *S)
{
  SFc14_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc14_CusakisME4901arcsInstanceStruct *)utMalloc(sizeof
    (SFc14_CusakisME4901arcsInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc14_CusakisME4901arcsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c14_CusakisME4901arcs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c14_CusakisME4901arcs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c14_CusakisME4901arcs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c14_CusakisME4901arcs;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c14_CusakisME4901arcs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c14_CusakisME4901arcs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c14_CusakisME4901arcs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c14_CusakisME4901arcs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c14_CusakisME4901arcs;
  chartInstance->chartInfo.mdlStart = mdlStart_c14_CusakisME4901arcs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c14_CusakisME4901arcs;
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

void c14_CusakisME4901arcs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c14_CusakisME4901arcs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c14_CusakisME4901arcs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c14_CusakisME4901arcs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c14_CusakisME4901arcs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
