/* Include files */
#include "irobotcomunication_sfun.h"
#include "c4_irobotcomunication.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "irobotcomunication_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c4_IN_NO_ACTIVE_CHILD           (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc4_irobotcomunicationInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c4_irobotcomunication(void);
static void initialize_params_c4_irobotcomunication(void);
static void enable_c4_irobotcomunication(void);
static void disable_c4_irobotcomunication(void);
static void finalize_c4_irobotcomunication(void);
static void sf_c4_irobotcomunication(void);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
 c4_chartNumber);
static const mxArray *c4_sf_marshall(void *c4_chartInstance, void *c4_u);
static const mxArray *c4_b_sf_marshall(void *c4_chartInstance, void *c4_u);
static const mxArray *c4_c_sf_marshall(void *c4_chartInstance, void *c4_u);
static const mxArray *c4_d_sf_marshall(void *c4_chartInstance, void *c4_u);
static const mxArray *c4_e_sf_marshall(void *c4_chartInstance, void *c4_u);
static const mxArray *c4_f_sf_marshall(void *c4_chartInstance, void *c4_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c4_irobotcomunication(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c4_is_active_c4_irobotcomunication = 0U;
}

static void initialize_params_c4_irobotcomunication(void)
{
}

static void enable_c4_irobotcomunication(void)
{
}

static void disable_c4_irobotcomunication(void)
{
}

static void finalize_c4_irobotcomunication(void)
{
}

static void sf_c4_irobotcomunication(void)
{
  uint8_T c4_previousEvent;
  real_T c4_xyt;
  real_T c4_swit;
  real_T c4_mem1;
  real_T c4_mem2;
  real_T c4_xyt1;
  real_T c4_xytRC;
  real_T *c4_b_xyt;
  real_T *c4_b_swit;
  real_T *c4_b_mem1;
  real_T *c4_b_xytRC;
  real_T *c4_b_xyt1;
  real_T *c4_b_mem2;
  c4_b_swit = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c4_b_mem1 = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
  c4_b_xyt1 = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c4_b_xytRC = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c4_b_mem2 = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
  c4_b_xyt = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_DATA_RANGE_CHECK(*c4_b_xyt, 5U);
  _SFD_DATA_RANGE_CHECK(*c4_b_swit, 2U);
  _SFD_DATA_RANGE_CHECK(*c4_b_mem1, 3U);
  _SFD_DATA_RANGE_CHECK(*c4_b_xytRC, 4U);
  _SFD_DATA_RANGE_CHECK(*c4_b_xyt1, 1U);
  _SFD_DATA_RANGE_CHECK(*c4_b_mem2, 0U);
  c4_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,1);
  c4_xyt = *c4_b_xyt;
  c4_swit = *c4_b_swit;
  c4_mem1 = *c4_b_mem1;
  c4_mem2 = *c4_b_mem2;
  sf_debug_symbol_scope_push(6U, 0U);
  sf_debug_symbol_scope_add("xyt1", &c4_xyt1, c4_f_sf_marshall);
  sf_debug_symbol_scope_add("xytRC", &c4_xytRC, c4_e_sf_marshall);
  sf_debug_symbol_scope_add("mem2", &c4_mem2, c4_d_sf_marshall);
  sf_debug_symbol_scope_add("mem1", &c4_mem1, c4_c_sf_marshall);
  sf_debug_symbol_scope_add("swit", &c4_swit, c4_b_sf_marshall);
  sf_debug_symbol_scope_add("xyt", &c4_xyt, c4_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,3);
  if(CV_EML_IF(0, 0, c4_swit == 0.0)) {
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,5);
    c4_xyt1 = c4_xyt;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,7);
    c4_xytRC = c4_mem1;
  } else {
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,11);
    c4_xytRC = c4_xyt;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,13);
    c4_xyt1 = c4_mem2;
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,-13);
  sf_debug_symbol_scope_pop();
  *c4_b_xytRC = c4_xytRC;
  *c4_b_xyt1 = c4_xyt1;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
  _sfEvent_ = c4_previousEvent;
  sf_debug_check_for_state_inconsistency(_irobotcomunicationMachineNumber_,
   chartInstance.chartNumber, chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
 c4_chartNumber)
{
}

static const mxArray *c4_sf_marshall(void *c4_chartInstance, void *c4_u)
{
  const mxArray *c4_y = NULL;
  real_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  c4_y = NULL;
  c4_b_u = *((real_T *)c4_u);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create(&c4_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static const mxArray *c4_b_sf_marshall(void *c4_chartInstance, void *c4_u)
{
  const mxArray *c4_y = NULL;
  real_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  c4_y = NULL;
  c4_b_u = *((real_T *)c4_u);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create(&c4_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static const mxArray *c4_c_sf_marshall(void *c4_chartInstance, void *c4_u)
{
  const mxArray *c4_y = NULL;
  real_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  c4_y = NULL;
  c4_b_u = *((real_T *)c4_u);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create(&c4_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static const mxArray *c4_d_sf_marshall(void *c4_chartInstance, void *c4_u)
{
  const mxArray *c4_y = NULL;
  real_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  c4_y = NULL;
  c4_b_u = *((real_T *)c4_u);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create(&c4_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static const mxArray *c4_e_sf_marshall(void *c4_chartInstance, void *c4_u)
{
  const mxArray *c4_y = NULL;
  real_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  c4_y = NULL;
  c4_b_u = *((real_T *)c4_u);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create(&c4_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static const mxArray *c4_f_sf_marshall(void *c4_chartInstance, void *c4_u)
{
  const mxArray *c4_y = NULL;
  real_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  c4_y = NULL;
  c4_b_u = *((real_T *)c4_u);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create(&c4_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

const mxArray *sf_c4_irobotcomunication_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_ResolvedFunctionInfo c4_info[1];
  c4_ResolvedFunctionInfo (*c4_b_info)[1];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i0;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_b_info = &c4_info;
  (*c4_b_info)[0].context = "";
  (*c4_b_info)[0].name = "eq";
  (*c4_b_info)[0].dominantType = "double";
  (*c4_b_info)[0].resolved = "[B]eq";
  (*c4_b_info)[0].fileLength = 0U;
  (*c4_b_info)[0].fileTime1 = 0U;
  (*c4_b_info)[0].fileTime2 = 0U;
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 1));
  for(c4_i0 = 0; c4_i0 < 1; c4_i0 = c4_i0 + 1) {
    c4_r0 = &c4_info[c4_i0];
    sf_mex_addfield(c4_m0, sf_mex_create(c4_r0->context, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c4_r0->context)), "context",
     "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create(c4_r0->name, "nameCaptureInfo", 13, 0U,
      0U, 2, 1, strlen(c4_r0->name)), "name",
     "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create(c4_r0->dominantType, "nameCaptureInfo",
      13, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)),
     "dominantType", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create(c4_r0->resolved, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved",
     "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create(&c4_r0->fileLength, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileLength", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create(&c4_r0->fileTime1, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create(&c4_r0->fileTime2, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c4_i0);
  }
  sf_mex_assign(&c4_nameCaptureInfo, c4_m0);
  return c4_nameCaptureInfo;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c4_irobotcomunication_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4041851946U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3956541040U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3128103184U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2486278282U);
}

mxArray *sf_c4_irobotcomunication_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] =
  {"checksum","inputs","parameters","outputs"};
  mxArray *mxAutoinheritanceInfo =
  mxCreateStructMatrix(1,1,4,autoinheritanceFields);
  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(811490681U);
    pr[1] = (double)(3435778646U);
    pr[2] = (double)(3588812554U);
    pr[3] = (double)(4141108626U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }
  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,mxREAL));
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);
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
          sf_debug_initialize_chart(_irobotcomunicationMachineNumber_,
         4,
         1,
         1,
         6,
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
          init_script_number_translation(_irobotcomunicationMachineNumber_,chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_irobotcomunicationMachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_irobotcomunicationMachineNumber_,
           chartInstance.chartNumber,
           0,
           0,
           0);

          _SFD_SET_DATA_PROPS(5,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"xyt",0,c4_sf_marshall);
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"swit",0,c4_b_sf_marshall);
          _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"mem1",0,c4_c_sf_marshall);
          _SFD_SET_DATA_PROPS(4,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"xytRC",0,c4_e_sf_marshall);
          _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"xyt1",0,c4_f_sf_marshall);
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"mem2",0,c4_d_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,168);
        _SFD_CV_INIT_EML_IF(0,0,56,68,110,163);
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
          real_T *c4_xyt;
          real_T *c4_swit;
          real_T *c4_mem1;
          real_T *c4_xytRC;
          real_T *c4_xyt1;
          real_T *c4_mem2;
          c4_swit = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c4_mem1 = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
          c4_xyt1 = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
          c4_xytRC = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c4_mem2 = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
          c4_xyt = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          _SFD_SET_DATA_VALUE_PTR(5U, c4_xyt);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_swit);
          _SFD_SET_DATA_VALUE_PTR(3U, c4_mem1);
          _SFD_SET_DATA_VALUE_PTR(4U, c4_xytRC);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_xyt1);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_mem2);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_irobotcomunicationMachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c4_irobotcomunication(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c4_irobotcomunication();
  initialize_c4_irobotcomunication();
}

static void sf_opaque_enable_c4_irobotcomunication(void *chartInstanceVar)
{
  enable_c4_irobotcomunication();
}

static void sf_opaque_disable_c4_irobotcomunication(void *chartInstanceVar)
{
  disable_c4_irobotcomunication();
}

static void sf_opaque_gateway_c4_irobotcomunication(void *chartInstanceVar)
{
  sf_c4_irobotcomunication();
}

static void sf_opaque_terminate_c4_irobotcomunication(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) ||
   sim_mode_is_external(chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }
  finalize_c4_irobotcomunication();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_irobotcomunication(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  if(sf_machine_global_initializer_called()) {
    initialize_params_c4_irobotcomunication();
  }
}

static void mdlSetWorkWidths_c4_irobotcomunication(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("irobotcomunication",4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("irobotcomunication",4,"gatewayCannotBeInlinedMultipleTimes"));
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"irobotcomunication",4,4);
      sf_mark_chart_reusable_outputs(S,"irobotcomunication",4,2);
    }
    sf_set_rtw_dwork_info(S,"irobotcomunication",4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(4274326854U));
  ssSetChecksum1(S,(3990813887U));
  ssSetChecksum2(S,(3636803522U));
  ssSetChecksum3(S,(3910453793U));

  ssSetmdlDerivatives(S, NULL);

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c4_irobotcomunication(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "irobotcomunication", 4);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_irobotcomunication(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_irobotcomunication;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c4_irobotcomunication;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c4_irobotcomunication;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c4_irobotcomunication;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c4_irobotcomunication;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c4_irobotcomunication;
  chartInstance.chartInfo.mdlStart = mdlStart_c4_irobotcomunication;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_irobotcomunication;
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

void c4_irobotcomunication_method_dispatcher(SimStruct *S, int_T method, void
 *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_irobotcomunication(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_irobotcomunication(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_irobotcomunication(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c4_irobotcomunication_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

