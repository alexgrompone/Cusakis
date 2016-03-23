/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ManipulatorME4901_sfun.h"
#include "c33_ManipulatorME4901.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ManipulatorME4901_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c33_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

/* Function Declarations */
static void initialize_c33_ManipulatorME4901
  (SFc33_ManipulatorME4901InstanceStruct *chartInstance);
static void initialize_params_c33_ManipulatorME4901
  (SFc33_ManipulatorME4901InstanceStruct *chartInstance);
static void enable_c33_ManipulatorME4901(SFc33_ManipulatorME4901InstanceStruct
  *chartInstance);
static void disable_c33_ManipulatorME4901(SFc33_ManipulatorME4901InstanceStruct *
  chartInstance);
static void c33_update_debugger_state_c33_ManipulatorME4901
  (SFc33_ManipulatorME4901InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c33_ManipulatorME4901
  (SFc33_ManipulatorME4901InstanceStruct *chartInstance);
static void set_sim_state_c33_ManipulatorME4901
  (SFc33_ManipulatorME4901InstanceStruct *chartInstance, const mxArray *c33_st);
static void finalize_c33_ManipulatorME4901(SFc33_ManipulatorME4901InstanceStruct
  *chartInstance);
static void sf_c33_ManipulatorME4901(SFc33_ManipulatorME4901InstanceStruct
  *chartInstance);
static void initSimStructsc33_ManipulatorME4901
  (SFc33_ManipulatorME4901InstanceStruct *chartInstance);
static void registerMessagesc33_ManipulatorME4901
  (SFc33_ManipulatorME4901InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c33_machineNumber, uint32_T
  c33_chartNumber);
static const mxArray *c33_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static uint8_T c33_emlrt_marshallIn(SFc33_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c33_y, const char_T *c33_identifier);
static uint8_T c33_b_emlrt_marshallIn(SFc33_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId);
static void c33_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static const mxArray *c33_b_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static real_T c33_c_emlrt_marshallIn(SFc33_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId);
static void c33_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static const mxArray *c33_c_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static int32_T c33_d_emlrt_marshallIn(SFc33_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId);
static void c33_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static void init_dsm_address_info(SFc33_ManipulatorME4901InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c33_ManipulatorME4901
  (SFc33_ManipulatorME4901InstanceStruct *chartInstance)
{
  chartInstance->c33_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c33_is_active_c33_ManipulatorME4901 = 0U;
}

static void initialize_params_c33_ManipulatorME4901
  (SFc33_ManipulatorME4901InstanceStruct *chartInstance)
{
}

static void enable_c33_ManipulatorME4901(SFc33_ManipulatorME4901InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c33_ManipulatorME4901(SFc33_ManipulatorME4901InstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c33_update_debugger_state_c33_ManipulatorME4901
  (SFc33_ManipulatorME4901InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c33_ManipulatorME4901
  (SFc33_ManipulatorME4901InstanceStruct *chartInstance)
{
  const mxArray *c33_st;
  const mxArray *c33_y = NULL;
  uint8_T c33_hoistedGlobal;
  uint8_T c33_u;
  const mxArray *c33_b_y = NULL;
  uint8_T c33_b_hoistedGlobal;
  uint8_T c33_b_u;
  const mxArray *c33_c_y = NULL;
  uint8_T *c33_d_y;
  c33_d_y = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c33_st = NULL;
  c33_st = NULL;
  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_createcellarray(2), FALSE);
  c33_hoistedGlobal = *c33_d_y;
  c33_u = c33_hoistedGlobal;
  c33_b_y = NULL;
  sf_mex_assign(&c33_b_y, sf_mex_create("y", &c33_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c33_y, 0, c33_b_y);
  c33_b_hoistedGlobal = chartInstance->c33_is_active_c33_ManipulatorME4901;
  c33_b_u = c33_b_hoistedGlobal;
  c33_c_y = NULL;
  sf_mex_assign(&c33_c_y, sf_mex_create("y", &c33_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c33_y, 1, c33_c_y);
  sf_mex_assign(&c33_st, c33_y, FALSE);
  return c33_st;
}

static void set_sim_state_c33_ManipulatorME4901
  (SFc33_ManipulatorME4901InstanceStruct *chartInstance, const mxArray *c33_st)
{
  const mxArray *c33_u;
  uint8_T *c33_y;
  c33_y = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c33_doneDoubleBufferReInit = TRUE;
  c33_u = sf_mex_dup(c33_st);
  *c33_y = c33_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c33_u,
    0)), "y");
  chartInstance->c33_is_active_c33_ManipulatorME4901 = c33_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c33_u, 1)),
     "is_active_c33_ManipulatorME4901");
  sf_mex_destroy(&c33_u);
  c33_update_debugger_state_c33_ManipulatorME4901(chartInstance);
  sf_mex_destroy(&c33_st);
}

static void finalize_c33_ManipulatorME4901(SFc33_ManipulatorME4901InstanceStruct
  *chartInstance)
{
}

static void sf_c33_ManipulatorME4901(SFc33_ManipulatorME4901InstanceStruct
  *chartInstance)
{
  uint8_T c33_hoistedGlobal;
  uint8_T c33_u;
  uint32_T c33_debug_family_var_map[4];
  real_T c33_nargin = 1.0;
  real_T c33_nargout = 1.0;
  uint8_T c33_y;
  uint32_T c33_u0;
  uint8_T c33_a;
  uint32_T c33_u1;
  uint8_T *c33_b_u;
  uint8_T *c33_b_y;
  c33_b_y = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c33_b_u = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 32U, chartInstance->c33_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c33_b_u, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c33_b_y, 1U);
  chartInstance->c33_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 32U, chartInstance->c33_sfEvent);
  c33_hoistedGlobal = *c33_b_u;
  c33_u = c33_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c33_debug_family_names,
    c33_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c33_nargin, 0U, c33_b_sf_marshallOut,
    c33_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c33_nargout, 1U, c33_b_sf_marshallOut,
    c33_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c33_u, 2U, c33_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c33_y, 3U, c33_sf_marshallOut,
    c33_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, 6);
  c33_u0 = (uint32_T)c33_u + 180U;
  if (CV_SATURATION_EVAL(4, 0, 1, 0, c33_u0 > 255U)) {
    c33_u0 = 255U;
  }

  c33_a = (uint8_T)c33_u0;
  c33_u1 = (uint32_T)c33_a * 10U;
  if (CV_SATURATION_EVAL(4, 0, 0, 0, c33_u1 > 255U)) {
    c33_u1 = 255U;
  }

  c33_y = (uint8_T)c33_u1;
  _SFD_EML_CALL(0U, chartInstance->c33_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
  *c33_b_y = c33_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 32U, chartInstance->c33_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ManipulatorME4901MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc33_ManipulatorME4901
  (SFc33_ManipulatorME4901InstanceStruct *chartInstance)
{
}

static void registerMessagesc33_ManipulatorME4901
  (SFc33_ManipulatorME4901InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c33_machineNumber, uint32_T
  c33_chartNumber)
{
}

static const mxArray *c33_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  uint8_T c33_u;
  const mxArray *c33_y = NULL;
  SFc33_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc33_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  c33_u = *(uint8_T *)c33_inData;
  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_create("y", &c33_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c33_mxArrayOutData, c33_y, FALSE);
  return c33_mxArrayOutData;
}

static uint8_T c33_emlrt_marshallIn(SFc33_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c33_y, const char_T *c33_identifier)
{
  uint8_T c33_b_y;
  emlrtMsgIdentifier c33_thisId;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_b_y = c33_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_y), &c33_thisId);
  sf_mex_destroy(&c33_y);
  return c33_b_y;
}

static uint8_T c33_b_emlrt_marshallIn(SFc33_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId)
{
  uint8_T c33_y;
  uint8_T c33_u2;
  sf_mex_import(c33_parentId, sf_mex_dup(c33_u), &c33_u2, 1, 3, 0U, 0, 0U, 0);
  c33_y = c33_u2;
  sf_mex_destroy(&c33_u);
  return c33_y;
}

static void c33_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_y;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  uint8_T c33_b_y;
  SFc33_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc33_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c33_y = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_b_y = c33_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_y), &c33_thisId);
  sf_mex_destroy(&c33_y);
  *(uint8_T *)c33_outData = c33_b_y;
  sf_mex_destroy(&c33_mxArrayInData);
}

static const mxArray *c33_b_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  real_T c33_u;
  const mxArray *c33_y = NULL;
  SFc33_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc33_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  c33_u = *(real_T *)c33_inData;
  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_create("y", &c33_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c33_mxArrayOutData, c33_y, FALSE);
  return c33_mxArrayOutData;
}

static real_T c33_c_emlrt_marshallIn(SFc33_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId)
{
  real_T c33_y;
  real_T c33_d0;
  sf_mex_import(c33_parentId, sf_mex_dup(c33_u), &c33_d0, 1, 0, 0U, 0, 0U, 0);
  c33_y = c33_d0;
  sf_mex_destroy(&c33_u);
  return c33_y;
}

static void c33_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_nargout;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  real_T c33_y;
  SFc33_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc33_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c33_nargout = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_y = c33_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_nargout),
    &c33_thisId);
  sf_mex_destroy(&c33_nargout);
  *(real_T *)c33_outData = c33_y;
  sf_mex_destroy(&c33_mxArrayInData);
}

const mxArray *sf_c33_ManipulatorME4901_get_eml_resolved_functions_info(void)
{
  const mxArray *c33_nameCaptureInfo;
  c33_ResolvedFunctionInfo c33_info[1];
  c33_ResolvedFunctionInfo (*c33_b_info)[1];
  const mxArray *c33_m0 = NULL;
  int32_T c33_i0;
  c33_ResolvedFunctionInfo *c33_r0;
  c33_nameCaptureInfo = NULL;
  c33_nameCaptureInfo = NULL;
  c33_b_info = (c33_ResolvedFunctionInfo (*)[1])c33_info;
  (*c33_b_info)[0].context = "";
  (*c33_b_info)[0].name = "mtimes";
  (*c33_b_info)[0].dominantType = "uint8";
  (*c33_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c33_b_info)[0].fileTimeLo = 1289552092U;
  (*c33_b_info)[0].fileTimeHi = 0U;
  (*c33_b_info)[0].mFileTimeLo = 0U;
  (*c33_b_info)[0].mFileTimeHi = 0U;
  sf_mex_assign(&c33_m0, sf_mex_createstruct("nameCaptureInfo", 1, 1), FALSE);
  for (c33_i0 = 0; c33_i0 < 1; c33_i0++) {
    c33_r0 = &c33_info[c33_i0];
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo", c33_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c33_r0->context)), "context", "nameCaptureInfo",
                    c33_i0);
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo", c33_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c33_r0->name)), "name", "nameCaptureInfo", c33_i0);
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo",
      c33_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c33_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c33_i0);
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo", c33_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c33_r0->resolved)), "resolved",
                    "nameCaptureInfo", c33_i0);
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo", &c33_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c33_i0);
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo", &c33_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c33_i0);
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo",
      &c33_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c33_i0);
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo",
      &c33_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c33_i0);
  }

  sf_mex_assign(&c33_nameCaptureInfo, c33_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c33_nameCaptureInfo);
  return c33_nameCaptureInfo;
}

static const mxArray *c33_c_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  int32_T c33_u;
  const mxArray *c33_y = NULL;
  SFc33_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc33_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  c33_u = *(int32_T *)c33_inData;
  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_create("y", &c33_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c33_mxArrayOutData, c33_y, FALSE);
  return c33_mxArrayOutData;
}

static int32_T c33_d_emlrt_marshallIn(SFc33_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId)
{
  int32_T c33_y;
  int32_T c33_i1;
  sf_mex_import(c33_parentId, sf_mex_dup(c33_u), &c33_i1, 1, 6, 0U, 0, 0U, 0);
  c33_y = c33_i1;
  sf_mex_destroy(&c33_u);
  return c33_y;
}

static void c33_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_b_sfEvent;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  int32_T c33_y;
  SFc33_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc33_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c33_b_sfEvent = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_y = c33_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_b_sfEvent),
    &c33_thisId);
  sf_mex_destroy(&c33_b_sfEvent);
  *(int32_T *)c33_outData = c33_y;
  sf_mex_destroy(&c33_mxArrayInData);
}

static void init_dsm_address_info(SFc33_ManipulatorME4901InstanceStruct
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

void sf_c33_ManipulatorME4901_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2754587946U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(186936493U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3744807673U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2960229818U);
}

mxArray *sf_c33_ManipulatorME4901_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("8UxgvLQlDqyiTwElDSiAMB");
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

mxArray *sf_c33_ManipulatorME4901_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c33_ManipulatorME4901(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c33_ManipulatorME4901\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c33_ManipulatorME4901_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc33_ManipulatorME4901InstanceStruct *chartInstance;
    chartInstance = (SFc33_ManipulatorME4901InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ManipulatorME4901MachineNumber_,
           33,
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
          init_script_number_translation(_ManipulatorME4901MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_ManipulatorME4901MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ManipulatorME4901MachineNumber_,
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
        _SFD_CV_INIT_EML(0,1,1,0,0,2,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,101);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,90,-1,100);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,91,-1,96);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c33_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c33_sf_marshallOut,(MexInFcnForType)c33_sf_marshallIn);

        {
          uint8_T *c33_u;
          uint8_T *c33_y;
          c33_y = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c33_u = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c33_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c33_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ManipulatorME4901MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "OZFNlBxfVq6Ggz0PfmeUAD";
}

static void sf_opaque_initialize_c33_ManipulatorME4901(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc33_ManipulatorME4901InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c33_ManipulatorME4901((SFc33_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
  initialize_c33_ManipulatorME4901((SFc33_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c33_ManipulatorME4901(void *chartInstanceVar)
{
  enable_c33_ManipulatorME4901((SFc33_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c33_ManipulatorME4901(void *chartInstanceVar)
{
  disable_c33_ManipulatorME4901((SFc33_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c33_ManipulatorME4901(void *chartInstanceVar)
{
  sf_c33_ManipulatorME4901((SFc33_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c33_ManipulatorME4901(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c33_ManipulatorME4901
    ((SFc33_ManipulatorME4901InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c33_ManipulatorME4901();/* state var info */
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

extern void sf_internal_set_sim_state_c33_ManipulatorME4901(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c33_ManipulatorME4901();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c33_ManipulatorME4901((SFc33_ManipulatorME4901InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c33_ManipulatorME4901(SimStruct* S)
{
  return sf_internal_get_sim_state_c33_ManipulatorME4901(S);
}

static void sf_opaque_set_sim_state_c33_ManipulatorME4901(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c33_ManipulatorME4901(S, st);
}

static void sf_opaque_terminate_c33_ManipulatorME4901(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc33_ManipulatorME4901InstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ManipulatorME4901_optimization_info();
    }

    finalize_c33_ManipulatorME4901((SFc33_ManipulatorME4901InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc33_ManipulatorME4901((SFc33_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c33_ManipulatorME4901(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c33_ManipulatorME4901
      ((SFc33_ManipulatorME4901InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c33_ManipulatorME4901(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ManipulatorME4901_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      33);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,33,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,33,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,33);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,33,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,33,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,33);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1907314715U));
  ssSetChecksum1(S,(1579311535U));
  ssSetChecksum2(S,(2881625835U));
  ssSetChecksum3(S,(288808131U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c33_ManipulatorME4901(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c33_ManipulatorME4901(SimStruct *S)
{
  SFc33_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc33_ManipulatorME4901InstanceStruct *)utMalloc(sizeof
    (SFc33_ManipulatorME4901InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc33_ManipulatorME4901InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c33_ManipulatorME4901;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c33_ManipulatorME4901;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c33_ManipulatorME4901;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c33_ManipulatorME4901;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c33_ManipulatorME4901;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c33_ManipulatorME4901;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c33_ManipulatorME4901;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c33_ManipulatorME4901;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c33_ManipulatorME4901;
  chartInstance->chartInfo.mdlStart = mdlStart_c33_ManipulatorME4901;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c33_ManipulatorME4901;
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

void c33_ManipulatorME4901_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c33_ManipulatorME4901(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c33_ManipulatorME4901(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c33_ManipulatorME4901(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c33_ManipulatorME4901_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
