/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CusakisME4901_sfun.h"
#include "c26_CusakisME4901.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CusakisME4901_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c26_debug_family_names[5] = { "nargin", "nargout", "Ve",
  "Vlinkcoll", "Ve_out" };

/* Function Declarations */
static void initialize_c26_CusakisME4901(SFc26_CusakisME4901InstanceStruct
  *chartInstance);
static void initialize_params_c26_CusakisME4901
  (SFc26_CusakisME4901InstanceStruct *chartInstance);
static void enable_c26_CusakisME4901(SFc26_CusakisME4901InstanceStruct
  *chartInstance);
static void disable_c26_CusakisME4901(SFc26_CusakisME4901InstanceStruct
  *chartInstance);
static void c26_update_debugger_state_c26_CusakisME4901
  (SFc26_CusakisME4901InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c26_CusakisME4901
  (SFc26_CusakisME4901InstanceStruct *chartInstance);
static void set_sim_state_c26_CusakisME4901(SFc26_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c26_st);
static void finalize_c26_CusakisME4901(SFc26_CusakisME4901InstanceStruct
  *chartInstance);
static void sf_c26_CusakisME4901(SFc26_CusakisME4901InstanceStruct
  *chartInstance);
static void initSimStructsc26_CusakisME4901(SFc26_CusakisME4901InstanceStruct
  *chartInstance);
static void registerMessagesc26_CusakisME4901(SFc26_CusakisME4901InstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c26_machineNumber, uint32_T
  c26_chartNumber);
static const mxArray *c26_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static void c26_emlrt_marshallIn(SFc26_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c26_Ve_out, const char_T *c26_identifier,
  real_T c26_y[6]);
static void c26_b_emlrt_marshallIn(SFc26_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  real_T c26_y[6]);
static void c26_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData);
static const mxArray *c26_b_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static real_T c26_c_emlrt_marshallIn(SFc26_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId);
static void c26_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData);
static const mxArray *c26_c_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static int32_T c26_d_emlrt_marshallIn(SFc26_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId);
static void c26_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData);
static uint8_T c26_e_emlrt_marshallIn(SFc26_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c26_b_is_active_c26_CusakisME4901, const char_T
  *c26_identifier);
static uint8_T c26_f_emlrt_marshallIn(SFc26_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId);
static void init_dsm_address_info(SFc26_CusakisME4901InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c26_CusakisME4901(SFc26_CusakisME4901InstanceStruct
  *chartInstance)
{
  chartInstance->c26_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c26_is_active_c26_CusakisME4901 = 0U;
}

static void initialize_params_c26_CusakisME4901
  (SFc26_CusakisME4901InstanceStruct *chartInstance)
{
}

static void enable_c26_CusakisME4901(SFc26_CusakisME4901InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c26_CusakisME4901(SFc26_CusakisME4901InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c26_update_debugger_state_c26_CusakisME4901
  (SFc26_CusakisME4901InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c26_CusakisME4901
  (SFc26_CusakisME4901InstanceStruct *chartInstance)
{
  const mxArray *c26_st;
  const mxArray *c26_y = NULL;
  int32_T c26_i0;
  real_T c26_u[6];
  const mxArray *c26_b_y = NULL;
  uint8_T c26_hoistedGlobal;
  uint8_T c26_b_u;
  const mxArray *c26_c_y = NULL;
  real_T (*c26_Ve_out)[6];
  c26_Ve_out = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c26_st = NULL;
  c26_st = NULL;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_createcellarray(2), FALSE);
  for (c26_i0 = 0; c26_i0 < 6; c26_i0++) {
    c26_u[c26_i0] = (*c26_Ve_out)[c26_i0];
  }

  c26_b_y = NULL;
  sf_mex_assign(&c26_b_y, sf_mex_create("y", c26_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_setcell(c26_y, 0, c26_b_y);
  c26_hoistedGlobal = chartInstance->c26_is_active_c26_CusakisME4901;
  c26_b_u = c26_hoistedGlobal;
  c26_c_y = NULL;
  sf_mex_assign(&c26_c_y, sf_mex_create("y", &c26_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c26_y, 1, c26_c_y);
  sf_mex_assign(&c26_st, c26_y, FALSE);
  return c26_st;
}

static void set_sim_state_c26_CusakisME4901(SFc26_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c26_st)
{
  const mxArray *c26_u;
  real_T c26_dv0[6];
  int32_T c26_i1;
  real_T (*c26_Ve_out)[6];
  c26_Ve_out = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c26_doneDoubleBufferReInit = TRUE;
  c26_u = sf_mex_dup(c26_st);
  c26_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c26_u, 0)),
                       "Ve_out", c26_dv0);
  for (c26_i1 = 0; c26_i1 < 6; c26_i1++) {
    (*c26_Ve_out)[c26_i1] = c26_dv0[c26_i1];
  }

  chartInstance->c26_is_active_c26_CusakisME4901 = c26_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c26_u, 1)),
     "is_active_c26_CusakisME4901");
  sf_mex_destroy(&c26_u);
  c26_update_debugger_state_c26_CusakisME4901(chartInstance);
  sf_mex_destroy(&c26_st);
}

static void finalize_c26_CusakisME4901(SFc26_CusakisME4901InstanceStruct
  *chartInstance)
{
}

static void sf_c26_CusakisME4901(SFc26_CusakisME4901InstanceStruct
  *chartInstance)
{
  int32_T c26_i2;
  int32_T c26_i3;
  int32_T c26_i4;
  int32_T c26_i5;
  real_T c26_Ve[6];
  int32_T c26_i6;
  real_T c26_Vlinkcoll[6];
  uint32_T c26_debug_family_var_map[5];
  real_T c26_nargin = 2.0;
  real_T c26_nargout = 1.0;
  real_T c26_Ve_out[6];
  int32_T c26_i7;
  int32_T c26_i8;
  real_T (*c26_b_Ve_out)[6];
  real_T (*c26_b_Vlinkcoll)[6];
  real_T (*c26_b_Ve)[6];
  c26_b_Ve_out = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c26_b_Vlinkcoll = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
  c26_b_Ve = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 24U, chartInstance->c26_sfEvent);
  for (c26_i2 = 0; c26_i2 < 6; c26_i2++) {
    _SFD_DATA_RANGE_CHECK((*c26_b_Ve)[c26_i2], 0U);
  }

  for (c26_i3 = 0; c26_i3 < 6; c26_i3++) {
    _SFD_DATA_RANGE_CHECK((*c26_b_Vlinkcoll)[c26_i3], 1U);
  }

  for (c26_i4 = 0; c26_i4 < 6; c26_i4++) {
    _SFD_DATA_RANGE_CHECK((*c26_b_Ve_out)[c26_i4], 2U);
  }

  chartInstance->c26_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 24U, chartInstance->c26_sfEvent);
  for (c26_i5 = 0; c26_i5 < 6; c26_i5++) {
    c26_Ve[c26_i5] = (*c26_b_Ve)[c26_i5];
  }

  for (c26_i6 = 0; c26_i6 < 6; c26_i6++) {
    c26_Vlinkcoll[c26_i6] = (*c26_b_Vlinkcoll)[c26_i6];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c26_debug_family_names,
    c26_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_nargin, 0U, c26_b_sf_marshallOut,
    c26_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c26_nargout, 1U, c26_b_sf_marshallOut,
    c26_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c26_Ve, 2U, c26_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c26_Vlinkcoll, 3U, c26_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c26_Ve_out, 4U, c26_sf_marshallOut,
    c26_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 6);
  for (c26_i7 = 0; c26_i7 < 6; c26_i7++) {
    c26_Ve_out[c26_i7] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 8);
  c26_Ve_out[0] = c26_Ve[0] + c26_Vlinkcoll[0];
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 10);
  c26_Ve_out[1] = c26_Ve[1] + c26_Vlinkcoll[1];
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, 12);
  c26_Ve_out[5] = c26_Ve[5] + c26_Vlinkcoll[5];
  _SFD_EML_CALL(0U, chartInstance->c26_sfEvent, -12);
  _SFD_SYMBOL_SCOPE_POP();
  for (c26_i8 = 0; c26_i8 < 6; c26_i8++) {
    (*c26_b_Ve_out)[c26_i8] = c26_Ve_out[c26_i8];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, chartInstance->c26_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CusakisME4901MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc26_CusakisME4901(SFc26_CusakisME4901InstanceStruct
  *chartInstance)
{
}

static void registerMessagesc26_CusakisME4901(SFc26_CusakisME4901InstanceStruct *
  chartInstance)
{
}

static void init_script_number_translation(uint32_T c26_machineNumber, uint32_T
  c26_chartNumber)
{
}

static const mxArray *c26_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  int32_T c26_i9;
  real_T c26_b_inData[6];
  int32_T c26_i10;
  real_T c26_u[6];
  const mxArray *c26_y = NULL;
  SFc26_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc26_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  for (c26_i9 = 0; c26_i9 < 6; c26_i9++) {
    c26_b_inData[c26_i9] = (*(real_T (*)[6])c26_inData)[c26_i9];
  }

  for (c26_i10 = 0; c26_i10 < 6; c26_i10++) {
    c26_u[c26_i10] = c26_b_inData[c26_i10];
  }

  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", c26_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, FALSE);
  return c26_mxArrayOutData;
}

static void c26_emlrt_marshallIn(SFc26_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c26_Ve_out, const char_T *c26_identifier,
  real_T c26_y[6])
{
  emlrtMsgIdentifier c26_thisId;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_Ve_out), &c26_thisId,
    c26_y);
  sf_mex_destroy(&c26_Ve_out);
}

static void c26_b_emlrt_marshallIn(SFc26_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  real_T c26_y[6])
{
  real_T c26_dv1[6];
  int32_T c26_i11;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), c26_dv1, 1, 0, 0U, 1, 0U, 1, 6);
  for (c26_i11 = 0; c26_i11 < 6; c26_i11++) {
    c26_y[c26_i11] = c26_dv1[c26_i11];
  }

  sf_mex_destroy(&c26_u);
}

static void c26_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData)
{
  const mxArray *c26_Ve_out;
  const char_T *c26_identifier;
  emlrtMsgIdentifier c26_thisId;
  real_T c26_y[6];
  int32_T c26_i12;
  SFc26_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc26_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c26_Ve_out = sf_mex_dup(c26_mxArrayInData);
  c26_identifier = c26_varName;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_Ve_out), &c26_thisId,
    c26_y);
  sf_mex_destroy(&c26_Ve_out);
  for (c26_i12 = 0; c26_i12 < 6; c26_i12++) {
    (*(real_T (*)[6])c26_outData)[c26_i12] = c26_y[c26_i12];
  }

  sf_mex_destroy(&c26_mxArrayInData);
}

static const mxArray *c26_b_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  real_T c26_u;
  const mxArray *c26_y = NULL;
  SFc26_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc26_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  c26_u = *(real_T *)c26_inData;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", &c26_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, FALSE);
  return c26_mxArrayOutData;
}

static real_T c26_c_emlrt_marshallIn(SFc26_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId)
{
  real_T c26_y;
  real_T c26_d0;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), &c26_d0, 1, 0, 0U, 0, 0U, 0);
  c26_y = c26_d0;
  sf_mex_destroy(&c26_u);
  return c26_y;
}

static void c26_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData)
{
  const mxArray *c26_nargout;
  const char_T *c26_identifier;
  emlrtMsgIdentifier c26_thisId;
  real_T c26_y;
  SFc26_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc26_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c26_nargout = sf_mex_dup(c26_mxArrayInData);
  c26_identifier = c26_varName;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_y = c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_nargout),
    &c26_thisId);
  sf_mex_destroy(&c26_nargout);
  *(real_T *)c26_outData = c26_y;
  sf_mex_destroy(&c26_mxArrayInData);
}

const mxArray *sf_c26_CusakisME4901_get_eml_resolved_functions_info(void)
{
  const mxArray *c26_nameCaptureInfo = NULL;
  c26_nameCaptureInfo = NULL;
  sf_mex_assign(&c26_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c26_nameCaptureInfo;
}

static const mxArray *c26_c_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  int32_T c26_u;
  const mxArray *c26_y = NULL;
  SFc26_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc26_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  c26_u = *(int32_T *)c26_inData;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", &c26_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, FALSE);
  return c26_mxArrayOutData;
}

static int32_T c26_d_emlrt_marshallIn(SFc26_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId)
{
  int32_T c26_y;
  int32_T c26_i13;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), &c26_i13, 1, 6, 0U, 0, 0U, 0);
  c26_y = c26_i13;
  sf_mex_destroy(&c26_u);
  return c26_y;
}

static void c26_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData)
{
  const mxArray *c26_b_sfEvent;
  const char_T *c26_identifier;
  emlrtMsgIdentifier c26_thisId;
  int32_T c26_y;
  SFc26_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc26_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c26_b_sfEvent = sf_mex_dup(c26_mxArrayInData);
  c26_identifier = c26_varName;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_y = c26_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_b_sfEvent),
    &c26_thisId);
  sf_mex_destroy(&c26_b_sfEvent);
  *(int32_T *)c26_outData = c26_y;
  sf_mex_destroy(&c26_mxArrayInData);
}

static uint8_T c26_e_emlrt_marshallIn(SFc26_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c26_b_is_active_c26_CusakisME4901, const char_T
  *c26_identifier)
{
  uint8_T c26_y;
  emlrtMsgIdentifier c26_thisId;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_y = c26_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c26_b_is_active_c26_CusakisME4901), &c26_thisId);
  sf_mex_destroy(&c26_b_is_active_c26_CusakisME4901);
  return c26_y;
}

static uint8_T c26_f_emlrt_marshallIn(SFc26_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId)
{
  uint8_T c26_y;
  uint8_T c26_u0;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), &c26_u0, 1, 3, 0U, 0, 0U, 0);
  c26_y = c26_u0;
  sf_mex_destroy(&c26_u);
  return c26_y;
}

static void init_dsm_address_info(SFc26_CusakisME4901InstanceStruct
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

void sf_c26_CusakisME4901_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3041200793U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3451566094U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1252686615U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1652695697U);
}

mxArray *sf_c26_CusakisME4901_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("9uJUayJNzbmOohM7O3UG9E");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c26_CusakisME4901_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c26_CusakisME4901(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Ve_out\",},{M[8],M[0],T\"is_active_c26_CusakisME4901\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c26_CusakisME4901_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc26_CusakisME4901InstanceStruct *chartInstance;
    chartInstance = (SFc26_CusakisME4901InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CusakisME4901MachineNumber_,
           26,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"Ve");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Vlinkcoll");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Ve_out");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,211);
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
            1.0,0,0,(MexFcnForType)c26_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c26_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c26_sf_marshallOut,(MexInFcnForType)
            c26_sf_marshallIn);
        }

        {
          real_T (*c26_Ve)[6];
          real_T (*c26_Vlinkcoll)[6];
          real_T (*c26_Ve_out)[6];
          c26_Ve_out = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c26_Vlinkcoll = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S,
            1);
          c26_Ve = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c26_Ve);
          _SFD_SET_DATA_VALUE_PTR(1U, *c26_Vlinkcoll);
          _SFD_SET_DATA_VALUE_PTR(2U, *c26_Ve_out);
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
  return "VqL1p2PjRjiknK0ofHblAD";
}

static void sf_opaque_initialize_c26_CusakisME4901(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc26_CusakisME4901InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c26_CusakisME4901((SFc26_CusakisME4901InstanceStruct*)
    chartInstanceVar);
  initialize_c26_CusakisME4901((SFc26_CusakisME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c26_CusakisME4901(void *chartInstanceVar)
{
  enable_c26_CusakisME4901((SFc26_CusakisME4901InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c26_CusakisME4901(void *chartInstanceVar)
{
  disable_c26_CusakisME4901((SFc26_CusakisME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c26_CusakisME4901(void *chartInstanceVar)
{
  sf_c26_CusakisME4901((SFc26_CusakisME4901InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c26_CusakisME4901(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c26_CusakisME4901
    ((SFc26_CusakisME4901InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c26_CusakisME4901();/* state var info */
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

extern void sf_internal_set_sim_state_c26_CusakisME4901(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c26_CusakisME4901();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c26_CusakisME4901((SFc26_CusakisME4901InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c26_CusakisME4901(SimStruct* S)
{
  return sf_internal_get_sim_state_c26_CusakisME4901(S);
}

static void sf_opaque_set_sim_state_c26_CusakisME4901(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c26_CusakisME4901(S, st);
}

static void sf_opaque_terminate_c26_CusakisME4901(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc26_CusakisME4901InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CusakisME4901_optimization_info();
    }

    finalize_c26_CusakisME4901((SFc26_CusakisME4901InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc26_CusakisME4901((SFc26_CusakisME4901InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c26_CusakisME4901(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c26_CusakisME4901((SFc26_CusakisME4901InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c26_CusakisME4901(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CusakisME4901_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      26);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,26,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,26,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,26);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,26,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,26,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,26);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2680952203U));
  ssSetChecksum1(S,(2162449599U));
  ssSetChecksum2(S,(1975402995U));
  ssSetChecksum3(S,(4223923846U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c26_CusakisME4901(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c26_CusakisME4901(SimStruct *S)
{
  SFc26_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc26_CusakisME4901InstanceStruct *)utMalloc(sizeof
    (SFc26_CusakisME4901InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc26_CusakisME4901InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c26_CusakisME4901;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c26_CusakisME4901;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c26_CusakisME4901;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c26_CusakisME4901;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c26_CusakisME4901;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c26_CusakisME4901;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c26_CusakisME4901;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c26_CusakisME4901;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c26_CusakisME4901;
  chartInstance->chartInfo.mdlStart = mdlStart_c26_CusakisME4901;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c26_CusakisME4901;
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

void c26_CusakisME4901_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c26_CusakisME4901(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c26_CusakisME4901(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c26_CusakisME4901(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c26_CusakisME4901_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
