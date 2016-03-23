/* Include files */

#include <stddef.h>
#include "blas.h"
#include "WindowsiCreateNew_sfun.h"
#include "c1_WindowsiCreateNew.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "WindowsiCreateNew_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[7] = { "nargin", "nargout", "u",
  "RotationVel", "LinearVel", "Right", "Left" };

/* Function Declarations */
static void initialize_c1_WindowsiCreateNew(SFc1_WindowsiCreateNewInstanceStruct
  *chartInstance);
static void initialize_params_c1_WindowsiCreateNew
  (SFc1_WindowsiCreateNewInstanceStruct *chartInstance);
static void enable_c1_WindowsiCreateNew(SFc1_WindowsiCreateNewInstanceStruct
  *chartInstance);
static void disable_c1_WindowsiCreateNew(SFc1_WindowsiCreateNewInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_WindowsiCreateNew
  (SFc1_WindowsiCreateNewInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_WindowsiCreateNew
  (SFc1_WindowsiCreateNewInstanceStruct *chartInstance);
static void set_sim_state_c1_WindowsiCreateNew
  (SFc1_WindowsiCreateNewInstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_WindowsiCreateNew(SFc1_WindowsiCreateNewInstanceStruct
  *chartInstance);
static void sf_c1_WindowsiCreateNew(SFc1_WindowsiCreateNewInstanceStruct
  *chartInstance);
static void initSimStructsc1_WindowsiCreateNew
  (SFc1_WindowsiCreateNewInstanceStruct *chartInstance);
static void registerMessagesc1_WindowsiCreateNew
  (SFc1_WindowsiCreateNewInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_WindowsiCreateNewInstanceStruct
  *chartInstance, const mxArray *c1_Left, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_WindowsiCreateNewInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_c_emlrt_marshallIn(SFc1_WindowsiCreateNewInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_d_emlrt_marshallIn(SFc1_WindowsiCreateNewInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_WindowsiCreateNew, const
  char_T *c1_identifier);
static uint8_T c1_e_emlrt_marshallIn(SFc1_WindowsiCreateNewInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_WindowsiCreateNewInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_WindowsiCreateNew(SFc1_WindowsiCreateNewInstanceStruct
  *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_WindowsiCreateNew = 0U;
}

static void initialize_params_c1_WindowsiCreateNew
  (SFc1_WindowsiCreateNewInstanceStruct *chartInstance)
{
}

static void enable_c1_WindowsiCreateNew(SFc1_WindowsiCreateNewInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_WindowsiCreateNew(SFc1_WindowsiCreateNewInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_WindowsiCreateNew
  (SFc1_WindowsiCreateNewInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_WindowsiCreateNew
  (SFc1_WindowsiCreateNewInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  uint8_T c1_c_hoistedGlobal;
  uint8_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T *c1_Left;
  real_T *c1_Right;
  c1_Left = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_Right = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(3), FALSE);
  c1_hoistedGlobal = *c1_Left;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_Right;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = chartInstance->c1_is_active_c1_WindowsiCreateNew;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_WindowsiCreateNew
  (SFc1_WindowsiCreateNewInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_Left;
  real_T *c1_Right;
  c1_Left = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_Right = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_Left = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    0)), "Left");
  *c1_Right = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    1)), "Right");
  chartInstance->c1_is_active_c1_WindowsiCreateNew = c1_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
     "is_active_c1_WindowsiCreateNew");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_WindowsiCreateNew(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_WindowsiCreateNew(SFc1_WindowsiCreateNewInstanceStruct
  *chartInstance)
{
}

static void sf_c1_WindowsiCreateNew(SFc1_WindowsiCreateNewInstanceStruct
  *chartInstance)
{
  int32_T c1_i0;
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  int32_T c1_i1;
  real_T c1_u[2];
  real_T c1_RotationVel;
  real_T c1_LinearVel;
  uint32_T c1_debug_family_var_map[7];
  real_T c1_nargin = 3.0;
  real_T c1_nargout = 2.0;
  real_T c1_Right;
  real_T c1_Left;
  real_T *c1_b_RotationVel;
  real_T *c1_b_LinearVel;
  real_T *c1_b_Right;
  real_T *c1_b_Left;
  real_T (*c1_b_u)[2];
  c1_b_Left = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_Right = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_LinearVel = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_RotationVel = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_u = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i0 = 0; c1_i0 < 2; c1_i0++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_u)[c1_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_b_RotationVel, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_b_LinearVel, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_b_Right, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_b_Left, 4U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_RotationVel;
  c1_b_hoistedGlobal = *c1_b_LinearVel;
  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_u[c1_i1] = (*c1_b_u)[c1_i1];
  }

  c1_RotationVel = c1_hoistedGlobal;
  c1_LinearVel = c1_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_u, 2U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_RotationVel, 3U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_LinearVel, 4U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_Right, 5U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_Left, 6U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  if (CV_EML_IF(0, 1, 0, c1_u[0] == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
    c1_Right = -c1_RotationVel;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
    c1_Left = c1_RotationVel;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
    if (CV_EML_IF(0, 1, 1, c1_u[0] == -1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
      c1_Right = c1_RotationVel;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
      c1_Left = -c1_RotationVel;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
      c1_Right = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
      c1_Left = 0.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
  if (CV_EML_IF(0, 1, 2, c1_u[1] == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
    c1_Right += -c1_LinearVel;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 19);
    c1_Left += -c1_LinearVel;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 20);
    if (CV_EML_IF(0, 1, 3, c1_u[1] == -1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
      c1_Right += c1_LinearVel;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 22);
      c1_Left += c1_LinearVel;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 25);
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -25);
  _SFD_SYMBOL_SCOPE_POP();
  *c1_b_Right = c1_Right;
  *c1_b_Left = c1_Left;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_WindowsiCreateNewMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc1_WindowsiCreateNew
  (SFc1_WindowsiCreateNewInstanceStruct *chartInstance)
{
}

static void registerMessagesc1_WindowsiCreateNew
  (SFc1_WindowsiCreateNewInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_WindowsiCreateNewInstanceStruct *chartInstance;
  chartInstance = (SFc1_WindowsiCreateNewInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_WindowsiCreateNewInstanceStruct
  *chartInstance, const mxArray *c1_Left, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Left), &c1_thisId);
  sf_mex_destroy(&c1_Left);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_WindowsiCreateNewInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Left;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_WindowsiCreateNewInstanceStruct *chartInstance;
  chartInstance = (SFc1_WindowsiCreateNewInstanceStruct *)chartInstanceVoid;
  c1_Left = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Left), &c1_thisId);
  sf_mex_destroy(&c1_Left);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i2;
  real_T c1_b_inData[2];
  int32_T c1_i3;
  real_T c1_u[2];
  const mxArray *c1_y = NULL;
  SFc1_WindowsiCreateNewInstanceStruct *chartInstance;
  chartInstance = (SFc1_WindowsiCreateNewInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
    c1_b_inData[c1_i2] = (*(real_T (*)[2])c1_inData)[c1_i2];
  }

  for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
    c1_u[c1_i3] = c1_b_inData[c1_i3];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

const mxArray *sf_c1_WindowsiCreateNew_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_WindowsiCreateNewInstanceStruct *chartInstance;
  chartInstance = (SFc1_WindowsiCreateNewInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_c_emlrt_marshallIn(SFc1_WindowsiCreateNewInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i4;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i4, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i4;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_WindowsiCreateNewInstanceStruct *chartInstance;
  chartInstance = (SFc1_WindowsiCreateNewInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_d_emlrt_marshallIn(SFc1_WindowsiCreateNewInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_WindowsiCreateNew, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_WindowsiCreateNew), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_WindowsiCreateNew);
  return c1_y;
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_WindowsiCreateNewInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_WindowsiCreateNewInstanceStruct
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

void sf_c1_WindowsiCreateNew_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1410632989U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1972529078U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2799488411U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3187754249U);
}

mxArray *sf_c1_WindowsiCreateNew_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("qYGuPzg6qbCLYwLSTDfm1E");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_WindowsiCreateNew_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_WindowsiCreateNew(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[10],T\"Left\",},{M[1],M[9],T\"Right\",},{M[8],M[0],T\"is_active_c1_WindowsiCreateNew\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_WindowsiCreateNew_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_WindowsiCreateNewInstanceStruct *chartInstance;
    chartInstance = (SFc1_WindowsiCreateNewInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _WindowsiCreateNewMachineNumber_,
           1,
           1,
           1,
           5,
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
          init_script_number_translation(_WindowsiCreateNewMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_WindowsiCreateNewMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _WindowsiCreateNewMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,1,1,0,"RotationVel");
          _SFD_SET_DATA_PROPS(2,1,1,0,"LinearVel");
          _SFD_SET_DATA_PROPS(3,2,0,1,"Right");
          _SFD_SET_DATA_PROPS(4,2,0,1,"Left");
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
        _SFD_CV_INIT_EML(0,1,1,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,529);
        _SFD_CV_INIT_EML_IF(0,1,0,179,189,241,336);
        _SFD_CV_INIT_EML_IF(0,1,1,241,256,309,336);
        _SFD_CV_INIT_EML_IF(0,1,2,342,352,411,524);
        _SFD_CV_INIT_EML_IF(0,1,3,411,426,483,524);
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
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          real_T *c1_RotationVel;
          real_T *c1_LinearVel;
          real_T *c1_Right;
          real_T *c1_Left;
          real_T (*c1_u)[2];
          c1_Left = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_Right = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_LinearVel = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_RotationVel = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_u = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_RotationVel);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_LinearVel);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_Right);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_Left);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _WindowsiCreateNewMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "4VM0cbqAT6wjLDg93Bj1AF";
}

static void sf_opaque_initialize_c1_WindowsiCreateNew(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_WindowsiCreateNewInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_WindowsiCreateNew((SFc1_WindowsiCreateNewInstanceStruct*)
    chartInstanceVar);
  initialize_c1_WindowsiCreateNew((SFc1_WindowsiCreateNewInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_WindowsiCreateNew(void *chartInstanceVar)
{
  enable_c1_WindowsiCreateNew((SFc1_WindowsiCreateNewInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_WindowsiCreateNew(void *chartInstanceVar)
{
  disable_c1_WindowsiCreateNew((SFc1_WindowsiCreateNewInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_WindowsiCreateNew(void *chartInstanceVar)
{
  sf_c1_WindowsiCreateNew((SFc1_WindowsiCreateNewInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_WindowsiCreateNew(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_WindowsiCreateNew
    ((SFc1_WindowsiCreateNewInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_WindowsiCreateNew();/* state var info */
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

extern void sf_internal_set_sim_state_c1_WindowsiCreateNew(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_WindowsiCreateNew();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_WindowsiCreateNew((SFc1_WindowsiCreateNewInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_WindowsiCreateNew(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_WindowsiCreateNew(S);
}

static void sf_opaque_set_sim_state_c1_WindowsiCreateNew(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_WindowsiCreateNew(S, st);
}

static void sf_opaque_terminate_c1_WindowsiCreateNew(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_WindowsiCreateNewInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_WindowsiCreateNew_optimization_info();
    }

    finalize_c1_WindowsiCreateNew((SFc1_WindowsiCreateNewInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_WindowsiCreateNew((SFc1_WindowsiCreateNewInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_WindowsiCreateNew(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_WindowsiCreateNew((SFc1_WindowsiCreateNewInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_WindowsiCreateNew(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_WindowsiCreateNew_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3506926066U));
  ssSetChecksum1(S,(940672224U));
  ssSetChecksum2(S,(1012076049U));
  ssSetChecksum3(S,(4146470778U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_WindowsiCreateNew(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_WindowsiCreateNew(SimStruct *S)
{
  SFc1_WindowsiCreateNewInstanceStruct *chartInstance;
  chartInstance = (SFc1_WindowsiCreateNewInstanceStruct *)utMalloc(sizeof
    (SFc1_WindowsiCreateNewInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_WindowsiCreateNewInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_WindowsiCreateNew;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_WindowsiCreateNew;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_WindowsiCreateNew;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_WindowsiCreateNew;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_WindowsiCreateNew;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_WindowsiCreateNew;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_WindowsiCreateNew;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_WindowsiCreateNew;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_WindowsiCreateNew;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_WindowsiCreateNew;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_WindowsiCreateNew;
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

void c1_WindowsiCreateNew_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_WindowsiCreateNew(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_WindowsiCreateNew(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_WindowsiCreateNew(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_WindowsiCreateNew_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
