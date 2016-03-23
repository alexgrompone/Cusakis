/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CusakisME4901arcs_sfun.h"
#include "c22_CusakisME4901arcs.h"
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
static const char * c22_debug_family_names[8] = { "w", "x", "z", "y", "nargin",
  "nargout", "t", "orbit" };

/* Function Declarations */
static void initialize_c22_CusakisME4901arcs
  (SFc22_CusakisME4901arcsInstanceStruct *chartInstance);
static void initialize_params_c22_CusakisME4901arcs
  (SFc22_CusakisME4901arcsInstanceStruct *chartInstance);
static void enable_c22_CusakisME4901arcs(SFc22_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void disable_c22_CusakisME4901arcs(SFc22_CusakisME4901arcsInstanceStruct *
  chartInstance);
static void c22_update_debugger_state_c22_CusakisME4901arcs
  (SFc22_CusakisME4901arcsInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c22_CusakisME4901arcs
  (SFc22_CusakisME4901arcsInstanceStruct *chartInstance);
static void set_sim_state_c22_CusakisME4901arcs
  (SFc22_CusakisME4901arcsInstanceStruct *chartInstance, const mxArray *c22_st);
static void finalize_c22_CusakisME4901arcs(SFc22_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void sf_c22_CusakisME4901arcs(SFc22_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void initSimStructsc22_CusakisME4901arcs
  (SFc22_CusakisME4901arcsInstanceStruct *chartInstance);
static void registerMessagesc22_CusakisME4901arcs
  (SFc22_CusakisME4901arcsInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c22_machineNumber, uint32_T
  c22_chartNumber);
static const mxArray *c22_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static void c22_emlrt_marshallIn(SFc22_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c22_orbit, const char_T *c22_identifier, real_T
  c22_y[3]);
static void c22_b_emlrt_marshallIn(SFc22_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId,
  real_T c22_y[3]);
static void c22_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static const mxArray *c22_b_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static real_T c22_c_emlrt_marshallIn(SFc22_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void c22_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static const mxArray *c22_c_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static int32_T c22_d_emlrt_marshallIn(SFc22_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void c22_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static uint8_T c22_e_emlrt_marshallIn(SFc22_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c22_b_is_active_c22_CusakisME4901arcs, const
  char_T *c22_identifier);
static uint8_T c22_f_emlrt_marshallIn(SFc22_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void init_dsm_address_info(SFc22_CusakisME4901arcsInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c22_CusakisME4901arcs
  (SFc22_CusakisME4901arcsInstanceStruct *chartInstance)
{
  chartInstance->c22_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c22_is_active_c22_CusakisME4901arcs = 0U;
}

static void initialize_params_c22_CusakisME4901arcs
  (SFc22_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static void enable_c22_CusakisME4901arcs(SFc22_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c22_CusakisME4901arcs(SFc22_CusakisME4901arcsInstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c22_update_debugger_state_c22_CusakisME4901arcs
  (SFc22_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c22_CusakisME4901arcs
  (SFc22_CusakisME4901arcsInstanceStruct *chartInstance)
{
  const mxArray *c22_st;
  const mxArray *c22_y = NULL;
  int32_T c22_i0;
  real_T c22_u[3];
  const mxArray *c22_b_y = NULL;
  uint8_T c22_hoistedGlobal;
  uint8_T c22_b_u;
  const mxArray *c22_c_y = NULL;
  real_T (*c22_orbit)[3];
  c22_orbit = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c22_st = NULL;
  c22_st = NULL;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_createcellarray(2), FALSE);
  for (c22_i0 = 0; c22_i0 < 3; c22_i0++) {
    c22_u[c22_i0] = (*c22_orbit)[c22_i0];
  }

  c22_b_y = NULL;
  sf_mex_assign(&c22_b_y, sf_mex_create("y", c22_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c22_y, 0, c22_b_y);
  c22_hoistedGlobal = chartInstance->c22_is_active_c22_CusakisME4901arcs;
  c22_b_u = c22_hoistedGlobal;
  c22_c_y = NULL;
  sf_mex_assign(&c22_c_y, sf_mex_create("y", &c22_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c22_y, 1, c22_c_y);
  sf_mex_assign(&c22_st, c22_y, FALSE);
  return c22_st;
}

static void set_sim_state_c22_CusakisME4901arcs
  (SFc22_CusakisME4901arcsInstanceStruct *chartInstance, const mxArray *c22_st)
{
  const mxArray *c22_u;
  real_T c22_dv0[3];
  int32_T c22_i1;
  real_T (*c22_orbit)[3];
  c22_orbit = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c22_doneDoubleBufferReInit = TRUE;
  c22_u = sf_mex_dup(c22_st);
  c22_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c22_u, 0)),
                       "orbit", c22_dv0);
  for (c22_i1 = 0; c22_i1 < 3; c22_i1++) {
    (*c22_orbit)[c22_i1] = c22_dv0[c22_i1];
  }

  chartInstance->c22_is_active_c22_CusakisME4901arcs = c22_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c22_u, 1)),
     "is_active_c22_CusakisME4901arcs");
  sf_mex_destroy(&c22_u);
  c22_update_debugger_state_c22_CusakisME4901arcs(chartInstance);
  sf_mex_destroy(&c22_st);
}

static void finalize_c22_CusakisME4901arcs(SFc22_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
}

static void sf_c22_CusakisME4901arcs(SFc22_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
  int32_T c22_i2;
  real_T c22_hoistedGlobal;
  real_T c22_t;
  uint32_T c22_debug_family_var_map[8];
  real_T c22_w;
  real_T c22_x;
  real_T c22_z;
  real_T c22_y;
  real_T c22_nargin = 1.0;
  real_T c22_nargout = 1.0;
  real_T c22_orbit[3];
  real_T c22_b;
  real_T c22_b_y;
  real_T c22_b_x;
  real_T c22_c_x;
  real_T c22_b_b;
  real_T c22_c_y;
  real_T c22_d_x;
  real_T c22_e_x;
  int32_T c22_i3;
  int32_T c22_i4;
  real_T *c22_b_t;
  real_T (*c22_b_orbit)[3];
  c22_b_orbit = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c22_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 21U, chartInstance->c22_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c22_b_t, 0U);
  for (c22_i2 = 0; c22_i2 < 3; c22_i2++) {
    _SFD_DATA_RANGE_CHECK((*c22_b_orbit)[c22_i2], 1U);
  }

  chartInstance->c22_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 21U, chartInstance->c22_sfEvent);
  c22_hoistedGlobal = *c22_b_t;
  c22_t = c22_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c22_debug_family_names,
    c22_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c22_w, 0U, c22_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_x, 1U, c22_b_sf_marshallOut,
    c22_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_z, 2U, c22_b_sf_marshallOut,
    c22_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_y, 3U, c22_b_sf_marshallOut,
    c22_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_nargin, 4U, c22_b_sf_marshallOut,
    c22_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_nargout, 5U, c22_b_sf_marshallOut,
    c22_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c22_t, 6U, c22_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c22_orbit, 7U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 6);
  c22_w = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 8);
  c22_b = c22_t;
  c22_b_y = 0.01 * c22_b;
  c22_b_x = c22_b_y;
  c22_x = c22_b_x;
  c22_c_x = c22_x;
  c22_x = c22_c_x;
  c22_x = muDoubleScalarCos(c22_x);
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 10);
  c22_b_b = c22_t;
  c22_c_y = 0.01 * c22_b_b;
  c22_d_x = c22_c_y;
  c22_z = c22_d_x;
  c22_e_x = c22_z;
  c22_z = c22_e_x;
  c22_z = muDoubleScalarSin(c22_z);
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 12);
  c22_y = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, 16);
  for (c22_i3 = 0; c22_i3 < 3; c22_i3++) {
    c22_orbit[c22_i3] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c22_sfEvent, -16);
  _SFD_SYMBOL_SCOPE_POP();
  for (c22_i4 = 0; c22_i4 < 3; c22_i4++) {
    (*c22_b_orbit)[c22_i4] = c22_orbit[c22_i4];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, chartInstance->c22_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CusakisME4901arcsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc22_CusakisME4901arcs
  (SFc22_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static void registerMessagesc22_CusakisME4901arcs
  (SFc22_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c22_machineNumber, uint32_T
  c22_chartNumber)
{
}

static const mxArray *c22_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  int32_T c22_i5;
  real_T c22_b_inData[3];
  int32_T c22_i6;
  real_T c22_u[3];
  const mxArray *c22_y = NULL;
  SFc22_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc22_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  for (c22_i5 = 0; c22_i5 < 3; c22_i5++) {
    c22_b_inData[c22_i5] = (*(real_T (*)[3])c22_inData)[c22_i5];
  }

  for (c22_i6 = 0; c22_i6 < 3; c22_i6++) {
    c22_u[c22_i6] = c22_b_inData[c22_i6];
  }

  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", c22_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, FALSE);
  return c22_mxArrayOutData;
}

static void c22_emlrt_marshallIn(SFc22_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c22_orbit, const char_T *c22_identifier, real_T
  c22_y[3])
{
  emlrtMsgIdentifier c22_thisId;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_orbit), &c22_thisId,
    c22_y);
  sf_mex_destroy(&c22_orbit);
}

static void c22_b_emlrt_marshallIn(SFc22_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId,
  real_T c22_y[3])
{
  real_T c22_dv1[3];
  int32_T c22_i7;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), c22_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c22_i7 = 0; c22_i7 < 3; c22_i7++) {
    c22_y[c22_i7] = c22_dv1[c22_i7];
  }

  sf_mex_destroy(&c22_u);
}

static void c22_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_orbit;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  real_T c22_y[3];
  int32_T c22_i8;
  SFc22_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc22_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c22_orbit = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_orbit), &c22_thisId,
    c22_y);
  sf_mex_destroy(&c22_orbit);
  for (c22_i8 = 0; c22_i8 < 3; c22_i8++) {
    (*(real_T (*)[3])c22_outData)[c22_i8] = c22_y[c22_i8];
  }

  sf_mex_destroy(&c22_mxArrayInData);
}

static const mxArray *c22_b_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  real_T c22_u;
  const mxArray *c22_y = NULL;
  SFc22_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc22_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_u = *(real_T *)c22_inData;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, FALSE);
  return c22_mxArrayOutData;
}

static real_T c22_c_emlrt_marshallIn(SFc22_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  real_T c22_y;
  real_T c22_d0;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_d0, 1, 0, 0U, 0, 0U, 0);
  c22_y = c22_d0;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void c22_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_nargout;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  real_T c22_y;
  SFc22_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc22_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c22_nargout = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_nargout),
    &c22_thisId);
  sf_mex_destroy(&c22_nargout);
  *(real_T *)c22_outData = c22_y;
  sf_mex_destroy(&c22_mxArrayInData);
}

const mxArray *sf_c22_CusakisME4901arcs_get_eml_resolved_functions_info(void)
{
  const mxArray *c22_nameCaptureInfo;
  c22_ResolvedFunctionInfo c22_info[5];
  c22_ResolvedFunctionInfo (*c22_b_info)[5];
  const mxArray *c22_m0 = NULL;
  int32_T c22_i9;
  c22_ResolvedFunctionInfo *c22_r0;
  c22_nameCaptureInfo = NULL;
  c22_nameCaptureInfo = NULL;
  c22_b_info = (c22_ResolvedFunctionInfo (*)[5])c22_info;
  (*c22_b_info)[0].context = "";
  (*c22_b_info)[0].name = "mtimes";
  (*c22_b_info)[0].dominantType = "double";
  (*c22_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c22_b_info)[0].fileTimeLo = 1289552092U;
  (*c22_b_info)[0].fileTimeHi = 0U;
  (*c22_b_info)[0].mFileTimeLo = 0U;
  (*c22_b_info)[0].mFileTimeHi = 0U;
  (*c22_b_info)[1].context = "";
  (*c22_b_info)[1].name = "cos";
  (*c22_b_info)[1].dominantType = "double";
  (*c22_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c22_b_info)[1].fileTimeLo = 1343862772U;
  (*c22_b_info)[1].fileTimeHi = 0U;
  (*c22_b_info)[1].mFileTimeLo = 0U;
  (*c22_b_info)[1].mFileTimeHi = 0U;
  (*c22_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c22_b_info)[2].name = "eml_scalar_cos";
  (*c22_b_info)[2].dominantType = "double";
  (*c22_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c22_b_info)[2].fileTimeLo = 1286851122U;
  (*c22_b_info)[2].fileTimeHi = 0U;
  (*c22_b_info)[2].mFileTimeLo = 0U;
  (*c22_b_info)[2].mFileTimeHi = 0U;
  (*c22_b_info)[3].context = "";
  (*c22_b_info)[3].name = "sin";
  (*c22_b_info)[3].dominantType = "double";
  (*c22_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c22_b_info)[3].fileTimeLo = 1343862786U;
  (*c22_b_info)[3].fileTimeHi = 0U;
  (*c22_b_info)[3].mFileTimeLo = 0U;
  (*c22_b_info)[3].mFileTimeHi = 0U;
  (*c22_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c22_b_info)[4].name = "eml_scalar_sin";
  (*c22_b_info)[4].dominantType = "double";
  (*c22_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c22_b_info)[4].fileTimeLo = 1286851136U;
  (*c22_b_info)[4].fileTimeHi = 0U;
  (*c22_b_info)[4].mFileTimeLo = 0U;
  (*c22_b_info)[4].mFileTimeHi = 0U;
  sf_mex_assign(&c22_m0, sf_mex_createstruct("nameCaptureInfo", 1, 5), FALSE);
  for (c22_i9 = 0; c22_i9 < 5; c22_i9++) {
    c22_r0 = &c22_info[c22_i9];
    sf_mex_addfield(c22_m0, sf_mex_create("nameCaptureInfo", c22_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c22_r0->context)), "context", "nameCaptureInfo",
                    c22_i9);
    sf_mex_addfield(c22_m0, sf_mex_create("nameCaptureInfo", c22_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c22_r0->name)), "name", "nameCaptureInfo", c22_i9);
    sf_mex_addfield(c22_m0, sf_mex_create("nameCaptureInfo",
      c22_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c22_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c22_i9);
    sf_mex_addfield(c22_m0, sf_mex_create("nameCaptureInfo", c22_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c22_r0->resolved)), "resolved",
                    "nameCaptureInfo", c22_i9);
    sf_mex_addfield(c22_m0, sf_mex_create("nameCaptureInfo", &c22_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c22_i9);
    sf_mex_addfield(c22_m0, sf_mex_create("nameCaptureInfo", &c22_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c22_i9);
    sf_mex_addfield(c22_m0, sf_mex_create("nameCaptureInfo",
      &c22_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c22_i9);
    sf_mex_addfield(c22_m0, sf_mex_create("nameCaptureInfo",
      &c22_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c22_i9);
  }

  sf_mex_assign(&c22_nameCaptureInfo, c22_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c22_nameCaptureInfo);
  return c22_nameCaptureInfo;
}

static const mxArray *c22_c_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  int32_T c22_u;
  const mxArray *c22_y = NULL;
  SFc22_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc22_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_u = *(int32_T *)c22_inData;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, FALSE);
  return c22_mxArrayOutData;
}

static int32_T c22_d_emlrt_marshallIn(SFc22_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  int32_T c22_y;
  int32_T c22_i10;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_i10, 1, 6, 0U, 0, 0U, 0);
  c22_y = c22_i10;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void c22_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_b_sfEvent;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  int32_T c22_y;
  SFc22_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc22_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c22_b_sfEvent = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_b_sfEvent),
    &c22_thisId);
  sf_mex_destroy(&c22_b_sfEvent);
  *(int32_T *)c22_outData = c22_y;
  sf_mex_destroy(&c22_mxArrayInData);
}

static uint8_T c22_e_emlrt_marshallIn(SFc22_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c22_b_is_active_c22_CusakisME4901arcs, const
  char_T *c22_identifier)
{
  uint8_T c22_y;
  emlrtMsgIdentifier c22_thisId;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c22_b_is_active_c22_CusakisME4901arcs), &c22_thisId);
  sf_mex_destroy(&c22_b_is_active_c22_CusakisME4901arcs);
  return c22_y;
}

static uint8_T c22_f_emlrt_marshallIn(SFc22_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  uint8_T c22_y;
  uint8_T c22_u0;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_u0, 1, 3, 0U, 0, 0U, 0);
  c22_y = c22_u0;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void init_dsm_address_info(SFc22_CusakisME4901arcsInstanceStruct
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

void sf_c22_CusakisME4901arcs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4171967348U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3281304200U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2064117021U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(437639388U);
}

mxArray *sf_c22_CusakisME4901arcs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("IVT45se0gGzlopYveqmmXC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
      pr[0] = (double)(3);
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

mxArray *sf_c22_CusakisME4901arcs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c22_CusakisME4901arcs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"orbit\",},{M[8],M[0],T\"is_active_c22_CusakisME4901arcs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c22_CusakisME4901arcs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc22_CusakisME4901arcsInstanceStruct *chartInstance;
    chartInstance = (SFc22_CusakisME4901arcsInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CusakisME4901arcsMachineNumber_,
           22,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"t");
          _SFD_SET_DATA_PROPS(1,2,0,1,"orbit");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,113);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c22_sf_marshallOut,(MexInFcnForType)
            c22_sf_marshallIn);
        }

        {
          real_T *c22_t;
          real_T (*c22_orbit)[3];
          c22_orbit = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c22_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c22_t);
          _SFD_SET_DATA_VALUE_PTR(1U, *c22_orbit);
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
  return "3mEcB2TzYYlAJKZOrIN9yG";
}

static void sf_opaque_initialize_c22_CusakisME4901arcs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc22_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c22_CusakisME4901arcs((SFc22_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
  initialize_c22_CusakisME4901arcs((SFc22_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c22_CusakisME4901arcs(void *chartInstanceVar)
{
  enable_c22_CusakisME4901arcs((SFc22_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c22_CusakisME4901arcs(void *chartInstanceVar)
{
  disable_c22_CusakisME4901arcs((SFc22_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c22_CusakisME4901arcs(void *chartInstanceVar)
{
  sf_c22_CusakisME4901arcs((SFc22_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c22_CusakisME4901arcs(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c22_CusakisME4901arcs
    ((SFc22_CusakisME4901arcsInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c22_CusakisME4901arcs();/* state var info */
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

extern void sf_internal_set_sim_state_c22_CusakisME4901arcs(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c22_CusakisME4901arcs();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c22_CusakisME4901arcs((SFc22_CusakisME4901arcsInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c22_CusakisME4901arcs(SimStruct* S)
{
  return sf_internal_get_sim_state_c22_CusakisME4901arcs(S);
}

static void sf_opaque_set_sim_state_c22_CusakisME4901arcs(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c22_CusakisME4901arcs(S, st);
}

static void sf_opaque_terminate_c22_CusakisME4901arcs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc22_CusakisME4901arcsInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CusakisME4901arcs_optimization_info();
    }

    finalize_c22_CusakisME4901arcs((SFc22_CusakisME4901arcsInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc22_CusakisME4901arcs((SFc22_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c22_CusakisME4901arcs(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c22_CusakisME4901arcs
      ((SFc22_CusakisME4901arcsInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c22_CusakisME4901arcs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CusakisME4901arcs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      22);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,22,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,22,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,22);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,22,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,22,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,22);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(940536677U));
  ssSetChecksum1(S,(937794820U));
  ssSetChecksum2(S,(324438326U));
  ssSetChecksum3(S,(271504803U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c22_CusakisME4901arcs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c22_CusakisME4901arcs(SimStruct *S)
{
  SFc22_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc22_CusakisME4901arcsInstanceStruct *)utMalloc(sizeof
    (SFc22_CusakisME4901arcsInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc22_CusakisME4901arcsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c22_CusakisME4901arcs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c22_CusakisME4901arcs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c22_CusakisME4901arcs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c22_CusakisME4901arcs;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c22_CusakisME4901arcs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c22_CusakisME4901arcs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c22_CusakisME4901arcs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c22_CusakisME4901arcs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c22_CusakisME4901arcs;
  chartInstance->chartInfo.mdlStart = mdlStart_c22_CusakisME4901arcs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c22_CusakisME4901arcs;
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

void c22_CusakisME4901arcs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c22_CusakisME4901arcs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c22_CusakisME4901arcs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c22_CusakisME4901arcs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c22_CusakisME4901arcs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
