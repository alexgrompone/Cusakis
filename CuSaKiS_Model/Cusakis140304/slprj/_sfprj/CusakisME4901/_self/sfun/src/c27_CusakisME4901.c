/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CusakisME4901_sfun.h"
#include "c27_CusakisME4901.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CusakisME4901_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c27_debug_family_names[5] = { "udeg", "nargin", "nargout",
  "u", "y" };

/* Function Declarations */
static void initialize_c27_CusakisME4901(SFc27_CusakisME4901InstanceStruct
  *chartInstance);
static void initialize_params_c27_CusakisME4901
  (SFc27_CusakisME4901InstanceStruct *chartInstance);
static void enable_c27_CusakisME4901(SFc27_CusakisME4901InstanceStruct
  *chartInstance);
static void disable_c27_CusakisME4901(SFc27_CusakisME4901InstanceStruct
  *chartInstance);
static void c27_update_debugger_state_c27_CusakisME4901
  (SFc27_CusakisME4901InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c27_CusakisME4901
  (SFc27_CusakisME4901InstanceStruct *chartInstance);
static void set_sim_state_c27_CusakisME4901(SFc27_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c27_st);
static void finalize_c27_CusakisME4901(SFc27_CusakisME4901InstanceStruct
  *chartInstance);
static void sf_c27_CusakisME4901(SFc27_CusakisME4901InstanceStruct
  *chartInstance);
static void initSimStructsc27_CusakisME4901(SFc27_CusakisME4901InstanceStruct
  *chartInstance);
static void registerMessagesc27_CusakisME4901(SFc27_CusakisME4901InstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c27_machineNumber, uint32_T
  c27_chartNumber);
static const mxArray *c27_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static real_T c27_emlrt_marshallIn(SFc27_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c27_y, const char_T *c27_identifier);
static real_T c27_b_emlrt_marshallIn(SFc27_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void c27_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static const mxArray *c27_b_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static int32_T c27_c_emlrt_marshallIn(SFc27_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void c27_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static uint8_T c27_d_emlrt_marshallIn(SFc27_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c27_b_is_active_c27_CusakisME4901, const char_T
  *c27_identifier);
static uint8_T c27_e_emlrt_marshallIn(SFc27_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void init_dsm_address_info(SFc27_CusakisME4901InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c27_CusakisME4901(SFc27_CusakisME4901InstanceStruct
  *chartInstance)
{
  chartInstance->c27_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c27_is_active_c27_CusakisME4901 = 0U;
}

static void initialize_params_c27_CusakisME4901
  (SFc27_CusakisME4901InstanceStruct *chartInstance)
{
}

static void enable_c27_CusakisME4901(SFc27_CusakisME4901InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c27_CusakisME4901(SFc27_CusakisME4901InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c27_update_debugger_state_c27_CusakisME4901
  (SFc27_CusakisME4901InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c27_CusakisME4901
  (SFc27_CusakisME4901InstanceStruct *chartInstance)
{
  const mxArray *c27_st;
  const mxArray *c27_y = NULL;
  real_T c27_hoistedGlobal;
  real_T c27_u;
  const mxArray *c27_b_y = NULL;
  uint8_T c27_b_hoistedGlobal;
  uint8_T c27_b_u;
  const mxArray *c27_c_y = NULL;
  real_T *c27_d_y;
  c27_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c27_st = NULL;
  c27_st = NULL;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_createcellarray(2), FALSE);
  c27_hoistedGlobal = *c27_d_y;
  c27_u = c27_hoistedGlobal;
  c27_b_y = NULL;
  sf_mex_assign(&c27_b_y, sf_mex_create("y", &c27_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c27_y, 0, c27_b_y);
  c27_b_hoistedGlobal = chartInstance->c27_is_active_c27_CusakisME4901;
  c27_b_u = c27_b_hoistedGlobal;
  c27_c_y = NULL;
  sf_mex_assign(&c27_c_y, sf_mex_create("y", &c27_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c27_y, 1, c27_c_y);
  sf_mex_assign(&c27_st, c27_y, FALSE);
  return c27_st;
}

static void set_sim_state_c27_CusakisME4901(SFc27_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c27_st)
{
  const mxArray *c27_u;
  real_T *c27_y;
  c27_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c27_doneDoubleBufferReInit = TRUE;
  c27_u = sf_mex_dup(c27_st);
  *c27_y = c27_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c27_u,
    0)), "y");
  chartInstance->c27_is_active_c27_CusakisME4901 = c27_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c27_u, 1)),
     "is_active_c27_CusakisME4901");
  sf_mex_destroy(&c27_u);
  c27_update_debugger_state_c27_CusakisME4901(chartInstance);
  sf_mex_destroy(&c27_st);
}

static void finalize_c27_CusakisME4901(SFc27_CusakisME4901InstanceStruct
  *chartInstance)
{
}

static void sf_c27_CusakisME4901(SFc27_CusakisME4901InstanceStruct
  *chartInstance)
{
  real_T c27_hoistedGlobal;
  real_T c27_u;
  uint32_T c27_debug_family_var_map[5];
  real_T c27_udeg;
  real_T c27_nargin = 1.0;
  real_T c27_nargout = 1.0;
  real_T c27_y;
  real_T c27_a;
  real_T c27_b_y;
  real_T c27_A;
  real_T c27_x;
  real_T c27_b_x;
  real_T c27_b_a;
  real_T *c27_b_u;
  real_T *c27_c_y;
  c27_c_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c27_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 26U, chartInstance->c27_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c27_b_u, 0U);
  _SFD_DATA_RANGE_CHECK(*c27_c_y, 1U);
  chartInstance->c27_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 26U, chartInstance->c27_sfEvent);
  c27_hoistedGlobal = *c27_b_u;
  c27_u = c27_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c27_debug_family_names,
    c27_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_udeg, 0U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_nargin, 1U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_nargout, 2U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c27_u, 3U, c27_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c27_y, 4U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 3);
  c27_a = c27_u;
  c27_b_y = c27_a * 180.0;
  c27_A = c27_b_y;
  c27_x = c27_A;
  c27_b_x = c27_x;
  c27_udeg = c27_b_x / 3.1415926535897931;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, 6);
  c27_b_a = c27_udeg + 180.0;
  c27_y = c27_b_a * 10.0;
  _SFD_EML_CALL(0U, chartInstance->c27_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
  *c27_c_y = c27_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, chartInstance->c27_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CusakisME4901MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc27_CusakisME4901(SFc27_CusakisME4901InstanceStruct
  *chartInstance)
{
}

static void registerMessagesc27_CusakisME4901(SFc27_CusakisME4901InstanceStruct *
  chartInstance)
{
}

static void init_script_number_translation(uint32_T c27_machineNumber, uint32_T
  c27_chartNumber)
{
}

static const mxArray *c27_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  real_T c27_u;
  const mxArray *c27_y = NULL;
  SFc27_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc27_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_u = *(real_T *)c27_inData;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", &c27_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, FALSE);
  return c27_mxArrayOutData;
}

static real_T c27_emlrt_marshallIn(SFc27_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c27_y, const char_T *c27_identifier)
{
  real_T c27_b_y;
  emlrtMsgIdentifier c27_thisId;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_b_y = c27_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_y), &c27_thisId);
  sf_mex_destroy(&c27_y);
  return c27_b_y;
}

static real_T c27_b_emlrt_marshallIn(SFc27_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  real_T c27_y;
  real_T c27_d0;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_d0, 1, 0, 0U, 0, 0U, 0);
  c27_y = c27_d0;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void c27_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_y;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  real_T c27_b_y;
  SFc27_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc27_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c27_y = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_b_y = c27_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_y), &c27_thisId);
  sf_mex_destroy(&c27_y);
  *(real_T *)c27_outData = c27_b_y;
  sf_mex_destroy(&c27_mxArrayInData);
}

const mxArray *sf_c27_CusakisME4901_get_eml_resolved_functions_info(void)
{
  const mxArray *c27_nameCaptureInfo;
  c27_ResolvedFunctionInfo c27_info[5];
  c27_ResolvedFunctionInfo (*c27_b_info)[5];
  const mxArray *c27_m0 = NULL;
  int32_T c27_i0;
  c27_ResolvedFunctionInfo *c27_r0;
  c27_nameCaptureInfo = NULL;
  c27_nameCaptureInfo = NULL;
  c27_b_info = (c27_ResolvedFunctionInfo (*)[5])c27_info;
  (*c27_b_info)[0].context = "";
  (*c27_b_info)[0].name = "mtimes";
  (*c27_b_info)[0].dominantType = "double";
  (*c27_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c27_b_info)[0].fileTimeLo = 1289552092U;
  (*c27_b_info)[0].fileTimeHi = 0U;
  (*c27_b_info)[0].mFileTimeLo = 0U;
  (*c27_b_info)[0].mFileTimeHi = 0U;
  (*c27_b_info)[1].context = "";
  (*c27_b_info)[1].name = "mrdivide";
  (*c27_b_info)[1].dominantType = "double";
  (*c27_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c27_b_info)[1].fileTimeLo = 1357983948U;
  (*c27_b_info)[1].fileTimeHi = 0U;
  (*c27_b_info)[1].mFileTimeLo = 1319762366U;
  (*c27_b_info)[1].mFileTimeHi = 0U;
  (*c27_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c27_b_info)[2].name = "rdivide";
  (*c27_b_info)[2].dominantType = "double";
  (*c27_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c27_b_info)[2].fileTimeLo = 1346542788U;
  (*c27_b_info)[2].fileTimeHi = 0U;
  (*c27_b_info)[2].mFileTimeLo = 0U;
  (*c27_b_info)[2].mFileTimeHi = 0U;
  (*c27_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c27_b_info)[3].name = "eml_scalexp_compatible";
  (*c27_b_info)[3].dominantType = "double";
  (*c27_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  (*c27_b_info)[3].fileTimeLo = 1286851196U;
  (*c27_b_info)[3].fileTimeHi = 0U;
  (*c27_b_info)[3].mFileTimeLo = 0U;
  (*c27_b_info)[3].mFileTimeHi = 0U;
  (*c27_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c27_b_info)[4].name = "eml_div";
  (*c27_b_info)[4].dominantType = "double";
  (*c27_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c27_b_info)[4].fileTimeLo = 1313380210U;
  (*c27_b_info)[4].fileTimeHi = 0U;
  (*c27_b_info)[4].mFileTimeLo = 0U;
  (*c27_b_info)[4].mFileTimeHi = 0U;
  sf_mex_assign(&c27_m0, sf_mex_createstruct("nameCaptureInfo", 1, 5), FALSE);
  for (c27_i0 = 0; c27_i0 < 5; c27_i0++) {
    c27_r0 = &c27_info[c27_i0];
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo", c27_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c27_r0->context)), "context", "nameCaptureInfo",
                    c27_i0);
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo", c27_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c27_r0->name)), "name", "nameCaptureInfo", c27_i0);
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo",
      c27_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c27_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c27_i0);
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo", c27_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c27_r0->resolved)), "resolved",
                    "nameCaptureInfo", c27_i0);
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo", &c27_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c27_i0);
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo", &c27_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c27_i0);
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo",
      &c27_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c27_i0);
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo",
      &c27_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c27_i0);
  }

  sf_mex_assign(&c27_nameCaptureInfo, c27_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c27_nameCaptureInfo);
  return c27_nameCaptureInfo;
}

static const mxArray *c27_b_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_u;
  const mxArray *c27_y = NULL;
  SFc27_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc27_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_u = *(int32_T *)c27_inData;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", &c27_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, FALSE);
  return c27_mxArrayOutData;
}

static int32_T c27_c_emlrt_marshallIn(SFc27_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  int32_T c27_y;
  int32_T c27_i1;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_i1, 1, 6, 0U, 0, 0U, 0);
  c27_y = c27_i1;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void c27_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_b_sfEvent;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  int32_T c27_y;
  SFc27_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc27_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c27_b_sfEvent = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_b_sfEvent),
    &c27_thisId);
  sf_mex_destroy(&c27_b_sfEvent);
  *(int32_T *)c27_outData = c27_y;
  sf_mex_destroy(&c27_mxArrayInData);
}

static uint8_T c27_d_emlrt_marshallIn(SFc27_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c27_b_is_active_c27_CusakisME4901, const char_T
  *c27_identifier)
{
  uint8_T c27_y;
  emlrtMsgIdentifier c27_thisId;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c27_b_is_active_c27_CusakisME4901), &c27_thisId);
  sf_mex_destroy(&c27_b_is_active_c27_CusakisME4901);
  return c27_y;
}

static uint8_T c27_e_emlrt_marshallIn(SFc27_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  uint8_T c27_y;
  uint8_T c27_u0;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_u0, 1, 3, 0U, 0, 0U, 0);
  c27_y = c27_u0;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void init_dsm_address_info(SFc27_CusakisME4901InstanceStruct
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

void sf_c27_CusakisME4901_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1809874585U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4023982945U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(262276434U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4252197008U);
}

mxArray *sf_c27_CusakisME4901_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("RbnxZvgLRaPQ4Xy3B45UH");
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

mxArray *sf_c27_CusakisME4901_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c27_CusakisME4901(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c27_CusakisME4901\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c27_CusakisME4901_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc27_CusakisME4901InstanceStruct *chartInstance;
    chartInstance = (SFc27_CusakisME4901InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CusakisME4901MachineNumber_,
           27,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,118);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_sf_marshallOut,(MexInFcnForType)c27_sf_marshallIn);

        {
          real_T *c27_u;
          real_T *c27_y;
          c27_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c27_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c27_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c27_y);
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
  return "xpw4gj12KrwWNOpC3jnNIH";
}

static void sf_opaque_initialize_c27_CusakisME4901(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc27_CusakisME4901InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c27_CusakisME4901((SFc27_CusakisME4901InstanceStruct*)
    chartInstanceVar);
  initialize_c27_CusakisME4901((SFc27_CusakisME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c27_CusakisME4901(void *chartInstanceVar)
{
  enable_c27_CusakisME4901((SFc27_CusakisME4901InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c27_CusakisME4901(void *chartInstanceVar)
{
  disable_c27_CusakisME4901((SFc27_CusakisME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c27_CusakisME4901(void *chartInstanceVar)
{
  sf_c27_CusakisME4901((SFc27_CusakisME4901InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c27_CusakisME4901(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c27_CusakisME4901
    ((SFc27_CusakisME4901InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c27_CusakisME4901();/* state var info */
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

extern void sf_internal_set_sim_state_c27_CusakisME4901(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c27_CusakisME4901();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c27_CusakisME4901((SFc27_CusakisME4901InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c27_CusakisME4901(SimStruct* S)
{
  return sf_internal_get_sim_state_c27_CusakisME4901(S);
}

static void sf_opaque_set_sim_state_c27_CusakisME4901(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c27_CusakisME4901(S, st);
}

static void sf_opaque_terminate_c27_CusakisME4901(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc27_CusakisME4901InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CusakisME4901_optimization_info();
    }

    finalize_c27_CusakisME4901((SFc27_CusakisME4901InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc27_CusakisME4901((SFc27_CusakisME4901InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c27_CusakisME4901(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c27_CusakisME4901((SFc27_CusakisME4901InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c27_CusakisME4901(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CusakisME4901_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      27);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,27,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,27,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,27);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,27,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,27,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,27);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1344329610U));
  ssSetChecksum1(S,(2072811305U));
  ssSetChecksum2(S,(1623890176U));
  ssSetChecksum3(S,(188459415U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c27_CusakisME4901(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c27_CusakisME4901(SimStruct *S)
{
  SFc27_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc27_CusakisME4901InstanceStruct *)utMalloc(sizeof
    (SFc27_CusakisME4901InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc27_CusakisME4901InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c27_CusakisME4901;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c27_CusakisME4901;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c27_CusakisME4901;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c27_CusakisME4901;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c27_CusakisME4901;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c27_CusakisME4901;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c27_CusakisME4901;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c27_CusakisME4901;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c27_CusakisME4901;
  chartInstance->chartInfo.mdlStart = mdlStart_c27_CusakisME4901;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c27_CusakisME4901;
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

void c27_CusakisME4901_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c27_CusakisME4901(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c27_CusakisME4901(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c27_CusakisME4901(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c27_CusakisME4901_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
