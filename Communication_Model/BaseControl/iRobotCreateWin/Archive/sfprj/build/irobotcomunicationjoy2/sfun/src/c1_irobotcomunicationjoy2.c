/* Include files */
#include "irobotcomunicationjoy2_sfun.h"
#include "c1_irobotcomunicationjoy2.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "irobotcomunicationjoy2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c1_IN_NO_ACTIVE_CHILD           (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc1_irobotcomunicationjoy2InstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c1_irobotcomunicationjoy2(void);
static void initialize_params_c1_irobotcomunicationjoy2(void);
static void enable_c1_irobotcomunicationjoy2(void);
static void disable_c1_irobotcomunicationjoy2(void);
static void finalize_c1_irobotcomunicationjoy2(void);
static void sf_c1_irobotcomunicationjoy2(void);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
 c1_chartNumber);
static const mxArray *c1_sf_marshall(void *c1_chartInstance, void *c1_u);
static const mxArray *c1_b_sf_marshall(void *c1_chartInstance, void *c1_u);
static const mxArray *c1_c_sf_marshall(void *c1_chartInstance, void *c1_u);
static const mxArray *c1_d_sf_marshall(void *c1_chartInstance, void *c1_u);
static const mxArray *c1_e_sf_marshall(void *c1_chartInstance, void *c1_u);
static const mxArray *c1_f_sf_marshall(void *c1_chartInstance, void *c1_u);
static const mxArray *c1_g_sf_marshall(void *c1_chartInstance, void *c1_u);
static const mxArray *c1_h_sf_marshall(void *c1_chartInstance, void *c1_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c1_irobotcomunicationjoy2(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c1_is_active_c1_irobotcomunicationjoy2 = 0U;
}

static void initialize_params_c1_irobotcomunicationjoy2(void)
{
}

static void enable_c1_irobotcomunicationjoy2(void)
{
}

static void disable_c1_irobotcomunicationjoy2(void)
{
}

static void finalize_c1_irobotcomunicationjoy2(void)
{
}

static void sf_c1_irobotcomunicationjoy2(void)
{
  int32_T c1_i0;
  uint8_T c1_previousEvent;
  real_T c1_memR;
  real_T c1_memL;
  int32_T c1_i1;
  real_T c1_u[2];
  real_T c1_RotationVel;
  real_T c1_LinearVel;
  real_T c1_enabler;
  real_T c1_Left;
  real_T c1_Right;
  real_T *c1_b_memR;
  real_T *c1_b_memL;
  real_T *c1_b_RotationVel;
  real_T *c1_b_LinearVel;
  real_T *c1_b_Right;
  real_T *c1_b_Left;
  real_T *c1_b_enabler;
  real_T (*c1_b_u)[2];
  c1_b_memL = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c1_b_RotationVel = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
  c1_b_enabler = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c1_b_u = (real_T (*)[2])ssGetInputPortSignal(chartInstance.S, 2);
  c1_b_Right = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c1_b_LinearVel = (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
  c1_b_Left = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c1_b_memR = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_DATA_RANGE_CHECK(*c1_b_memR, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_b_memL, 6U);
  for(c1_i0 = 0; c1_i0 < 2; c1_i0 = c1_i0 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_b_u)[c1_i0], 4U);
  }
  _SFD_DATA_RANGE_CHECK(*c1_b_RotationVel, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_b_LinearVel, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_b_Right, 7U);
  _SFD_DATA_RANGE_CHECK(*c1_b_Left, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_b_enabler, 5U);
  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  c1_memR = *c1_b_memR;
  c1_memL = *c1_b_memL;
  for(c1_i1 = 0; c1_i1 < 2; c1_i1 = c1_i1 + 1) {
    c1_u[c1_i1] = (*c1_b_u)[c1_i1];
  }
  c1_RotationVel = *c1_b_RotationVel;
  c1_LinearVel = *c1_b_LinearVel;
  sf_debug_symbol_scope_push(8U, 0U);
  sf_debug_symbol_scope_add("enabler", &c1_enabler, c1_h_sf_marshall);
  sf_debug_symbol_scope_add("Left", &c1_Left, c1_g_sf_marshall);
  sf_debug_symbol_scope_add("Right", &c1_Right, c1_f_sf_marshall);
  sf_debug_symbol_scope_add("LinearVel", &c1_LinearVel, c1_e_sf_marshall);
  sf_debug_symbol_scope_add("RotationVel", &c1_RotationVel, c1_d_sf_marshall);
  sf_debug_symbol_scope_add("u", &c1_u, c1_c_sf_marshall);
  sf_debug_symbol_scope_add("memL", &c1_memL, c1_b_sf_marshall);
  sf_debug_symbol_scope_add("memR", &c1_memR, c1_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,6);
  if(CV_EML_IF(0, 0, c1_u[0] == -1.0)) {
    /*  This block supports the Embedded MATLAB subset. */
    /*  See the help menu for details.  */
    /* turn right */
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,7);
    c1_Right = -c1_RotationVel;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,8);
    c1_Left = c1_RotationVel;
  } else {
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,9);
    if(CV_EML_IF(0, 1, c1_u[0] == 1.0)) {
      /* turn left    */
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,10);
      c1_Right = c1_RotationVel;
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,11);
      c1_Left = -c1_RotationVel;
    } else {
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,13);
      c1_Right = 0.0;
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,14);
      c1_Left = 0.0;
    }
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,19);
  if(CV_EML_IF(0, 2, c1_u[1] == 1.0)) {
    /* backwards */
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,20);
    c1_Right = (-c1_LinearVel) + c1_Right;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,21);
    c1_Left = (-c1_LinearVel) + c1_Left;
  } else {
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,22);
    if(CV_EML_IF(0, 3, c1_u[1] == -1.0)) {
      /* forward    */
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,23);
      c1_Right = c1_LinearVel + c1_Right;
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,24);
      c1_Left = c1_LinearVel + c1_Left;
    } else {
      /* stop    */
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,26);
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,27);
    }
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,32);
  if(CV_EML_COND(0, 0, c1_memR == c1_Right)) {
    if(CV_EML_COND(0, 1, c1_memL == c1_Left)) {
      CV_EML_MCDC(0, 0, true);
      CV_EML_IF(0, 4, true);
      /* Enabler for the S-Function */
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,33);
      c1_enabler = 0.0;
      goto label_1;
    }
  }
  CV_EML_MCDC(0, 0, false);
  CV_EML_IF(0, 4, false);
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,35);
  c1_enabler = 1.0;
  label_1:;
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,-35);
  sf_debug_symbol_scope_pop();
  *c1_b_Right = c1_Right;
  *c1_b_Left = c1_Left;
  *c1_b_enabler = c1_enabler;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c1_previousEvent;
  sf_debug_check_for_state_inconsistency(_irobotcomunicationjoy2MachineNumber_,
   chartInstance.chartNumber, chartInstance.
   instanceNumber);
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
 c1_chartNumber)
{
}

static const mxArray *c1_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create(&c1_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_b_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create(&c1_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_c_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i2;
  real_T c1_b_u[2];
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  for(c1_i2 = 0; c1_i2 < 2; c1_i2 = c1_i2 + 1) {
    c1_b_u[c1_i2] = (*((real_T (*)[2])c1_u))[c1_i2];
  }
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create(&c1_b_u, "y", 0, 0U, 1U, 1, 2));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_d_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create(&c1_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_e_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create(&c1_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_f_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create(&c1_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_g_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create(&c1_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_h_sf_marshall(void *c1_chartInstance, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create(&c1_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

const mxArray *sf_c1_irobotcomunicationjoy2_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_ResolvedFunctionInfo c1_info[3];
  c1_ResolvedFunctionInfo (*c1_b_info)[3];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i3;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_b_info = &c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "uminus";
  (*c1_b_info)[0].dominantType = "double";
  (*c1_b_info)[0].resolved = "[B]uminus";
  (*c1_b_info)[0].fileLength = 0U;
  (*c1_b_info)[0].fileTime1 = 0U;
  (*c1_b_info)[0].fileTime2 = 0U;
  (*c1_b_info)[1].context = "";
  (*c1_b_info)[1].name = "eq";
  (*c1_b_info)[1].dominantType = "double";
  (*c1_b_info)[1].resolved = "[B]eq";
  (*c1_b_info)[1].fileLength = 0U;
  (*c1_b_info)[1].fileTime1 = 0U;
  (*c1_b_info)[1].fileTime2 = 0U;
  (*c1_b_info)[2].context = "";
  (*c1_b_info)[2].name = "plus";
  (*c1_b_info)[2].dominantType = "double";
  (*c1_b_info)[2].resolved = "[B]plus";
  (*c1_b_info)[2].fileLength = 0U;
  (*c1_b_info)[2].fileTime1 = 0U;
  (*c1_b_info)[2].fileTime2 = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 3));
  for(c1_i3 = 0; c1_i3 < 3; c1_i3 = c1_i3 + 1) {
    c1_r0 = &c1_info[c1_i3];
    sf_mex_addfield(c1_m0, sf_mex_create(c1_r0->context, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c1_r0->context)), "context",
     "nameCaptureInfo", c1_i3);
    sf_mex_addfield(c1_m0, sf_mex_create(c1_r0->name, "nameCaptureInfo", 13, 0U,
      0U, 2, 1, strlen(c1_r0->name)), "name",
     "nameCaptureInfo", c1_i3);
    sf_mex_addfield(c1_m0, sf_mex_create(c1_r0->dominantType, "nameCaptureInfo",
      13, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)),
     "dominantType", "nameCaptureInfo", c1_i3);
    sf_mex_addfield(c1_m0, sf_mex_create(c1_r0->resolved, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved",
     "nameCaptureInfo", c1_i3);
    sf_mex_addfield(c1_m0, sf_mex_create(&c1_r0->fileLength, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileLength", "nameCaptureInfo", c1_i3);
    sf_mex_addfield(c1_m0, sf_mex_create(&c1_r0->fileTime1, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c1_i3);
    sf_mex_addfield(c1_m0, sf_mex_create(&c1_r0->fileTime2, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c1_i3);
  }
  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c1_irobotcomunicationjoy2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2379488021U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1120198907U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3007378034U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2516117691U);
}

mxArray *sf_c1_irobotcomunicationjoy2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] =
  {"checksum","inputs","parameters","outputs"};
  mxArray *mxAutoinheritanceInfo =
  mxCreateStructMatrix(1,1,4,autoinheritanceFields);
  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2088876647U);
    pr[1] = (double)(104607204U);
    pr[2] = (double)(1918598505U);
    pr[3] = (double)(2881202693U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
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
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }
    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
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
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
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
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }
    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }
  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,mxREAL));
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
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
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
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
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }
    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }
  return(mxAutoinheritanceInfo);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
 fullDebuggerInitialization)
{
  if(ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
    /* do this only if simulation is starting */
    if(!sim_mode_is_rtw_gen(S)) {
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent =
          sf_debug_initialize_chart(_irobotcomunicationjoy2MachineNumber_,
         1,
         1,
         1,
         8,
         0,
         0,
         0,
         0,
         0,
         &(chartInstance.chartNumber),
         &(chartInstance.instanceNumber),
         ssGetPath(S),
         (void *)S);
        if(chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_irobotcomunicationjoy2MachineNumber_,chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_irobotcomunicationjoy2MachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_irobotcomunicationjoy2MachineNumber_,
           chartInstance.chartNumber,
           0,
           0,
           0);

          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"memR",0,c1_sf_marshall);
          _SFD_SET_DATA_PROPS(6,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"memL",0,c1_b_sf_marshall);
          {
            unsigned int dimVector[1];
            dimVector[0]= 2;
            _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,1.0,0,"u",0,c1_c_sf_marshall);
          }
          _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"RotationVel",0,c1_d_sf_marshall);
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"LinearVel",0,c1_e_sf_marshall);
          _SFD_SET_DATA_PROPS(7,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Right",0,c1_f_sf_marshall);
          _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Left",0,c1_g_sf_marshall);
          _SFD_SET_DATA_PROPS(5,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"enabler",0,c1_h_sf_marshall);
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }
        _SFD_CV_INIT_CHART(0,0,0,0);
        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,5,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,607);
        _SFD_CV_INIT_EML_IF(0,0,157,168,220,314);
        _SFD_CV_INIT_EML_IF(0,1,220,234,287,314);
        _SFD_CV_INIT_EML_IF(0,2,322,332,391,504);
        _SFD_CV_INIT_EML_IF(0,3,391,406,463,504);
        _SFD_CV_INIT_EML_IF(0,4,536,564,582,605);
        {
          static int condStart[] = {539,554};
          static int condEnd[] = {550,564};
          static int pfixExpr[] = {0,1,-3};
          _SFD_CV_INIT_EML_MCDC(0,0,539,564,2,0,&(condStart[0]),&(condEnd[0]),3,&(pfixExpr[0]));
        }
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(0,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL,
           0,NULL,NULL);
        }

        {
          real_T *c1_memR;
          real_T *c1_memL;
          real_T (*c1_u)[2];
          real_T *c1_RotationVel;
          real_T *c1_LinearVel;
          real_T *c1_Right;
          real_T *c1_Left;
          real_T *c1_enabler;
          c1_memL = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c1_RotationVel = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
          c1_enabler = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
          c1_u = (real_T (*)[2])ssGetInputPortSignal(chartInstance.S, 2);
          c1_Right = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c1_LinearVel = (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
          c1_Left = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
          c1_memR = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_memR);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_memL);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_u);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_RotationVel);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_LinearVel);
          _SFD_SET_DATA_VALUE_PTR(7U, c1_Right);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_Left);
          _SFD_SET_DATA_VALUE_PTR(5U, c1_enabler);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_irobotcomunicationjoy2MachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c1_irobotcomunicationjoy2(void
 *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c1_irobotcomunicationjoy2();
  initialize_c1_irobotcomunicationjoy2();
}

static void sf_opaque_enable_c1_irobotcomunicationjoy2(void *chartInstanceVar)
{
  enable_c1_irobotcomunicationjoy2();
}

static void sf_opaque_disable_c1_irobotcomunicationjoy2(void *chartInstanceVar)
{
  disable_c1_irobotcomunicationjoy2();
}

static void sf_opaque_gateway_c1_irobotcomunicationjoy2(void *chartInstanceVar)
{
  sf_c1_irobotcomunicationjoy2();
}

static void sf_opaque_terminate_c1_irobotcomunicationjoy2(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) ||
   sim_mode_is_external(chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }
  finalize_c1_irobotcomunicationjoy2();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_irobotcomunicationjoy2(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  if(sf_machine_global_initializer_called()) {
    initialize_params_c1_irobotcomunicationjoy2();
  }
}

static void mdlSetWorkWidths_c1_irobotcomunicationjoy2(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("irobotcomunicationjoy2",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("irobotcomunicationjoy2",1,"gatewayCannotBeInlinedMultipleTimes"));
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"irobotcomunicationjoy2",1,5);
      sf_mark_chart_reusable_outputs(S,"irobotcomunicationjoy2",1,3);
    }
    sf_set_rtw_dwork_info(S,"irobotcomunicationjoy2",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(3976491193U));
  ssSetChecksum1(S,(982383311U));
  ssSetChecksum2(S,(471695210U));
  ssSetChecksum3(S,(3671074126U));

  ssSetmdlDerivatives(S, NULL);

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_irobotcomunicationjoy2(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "irobotcomunicationjoy2", 1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_irobotcomunicationjoy2(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_irobotcomunicationjoy2;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c1_irobotcomunicationjoy2;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c1_irobotcomunicationjoy2;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c1_irobotcomunicationjoy2;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c1_irobotcomunicationjoy2;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c1_irobotcomunicationjoy2;
  chartInstance.chartInfo.mdlStart = mdlStart_c1_irobotcomunicationjoy2;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_irobotcomunicationjoy2;
  chartInstance.chartInfo.extModeExec = NULL;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo))); /* register the chart instance with simstruct */

  if(!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info();
  }
  chart_debug_initialization(S,1);
}

void c1_irobotcomunicationjoy2_method_dispatcher(SimStruct *S, int_T method,
 void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_irobotcomunicationjoy2(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_irobotcomunicationjoy2(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_irobotcomunicationjoy2(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c1_irobotcomunicationjoy2_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

