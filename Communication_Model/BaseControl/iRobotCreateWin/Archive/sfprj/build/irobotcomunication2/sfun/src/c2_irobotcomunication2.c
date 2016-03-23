/* Include files */
#include "irobotcomunication2_sfun.h"
#include "c2_irobotcomunication2.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "irobotcomunication2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_IN_NO_ACTIVE_CHILD           (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc2_irobotcomunication2InstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c2_irobotcomunication2(void);
static void initialize_params_c2_irobotcomunication2(void);
static void enable_c2_irobotcomunication2(void);
static void disable_c2_irobotcomunication2(void);
static void finalize_c2_irobotcomunication2(void);
static void sf_c2_irobotcomunication2(void);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
 c2_chartNumber);
static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_c_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_d_sf_marshall(void *c2_chartInstance, void *c2_u);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c2_irobotcomunication2(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c2_is_active_c2_irobotcomunication2 = 0U;
}

static void initialize_params_c2_irobotcomunication2(void)
{
}

static void enable_c2_irobotcomunication2(void)
{
}

static void disable_c2_irobotcomunication2(void)
{
}

static void finalize_c2_irobotcomunication2(void)
{
}

static void sf_c2_irobotcomunication2(void)
{
  uint8_T c2_previousEvent;
  real_T c2_u;
  real_T c2_y3;
  real_T c2_y2;
  real_T c2_y;
  real_T *c2_b_u;
  real_T *c2_b_y;
  real_T *c2_b_y2;
  real_T *c2_b_y3;
  c2_b_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_b_y2 = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c2_b_y3 = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c2_b_u = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_DATA_RANGE_CHECK(*c2_b_u, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_b_y, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_b_y2, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_b_y3, 2U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  c2_u = *c2_b_u;
  sf_debug_symbol_scope_push(4U, 0U);
  sf_debug_symbol_scope_add("y3", &c2_y3, c2_d_sf_marshall);
  sf_debug_symbol_scope_add("y2", &c2_y2, c2_c_sf_marshall);
  sf_debug_symbol_scope_add("y", &c2_y, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("u", &c2_u, c2_sf_marshall);
  CV_EML_FCN(0, 0);
  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,4);
  c2_y = 0.0;
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,5);
  c2_y2 = 0.0;
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,6);
  c2_y3 = 0.0;
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,7);
  if(CV_EML_IF(0, 0, c2_u == 5.0)) {
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,9);
    c2_y = 1.0;
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,13);
  if(CV_EML_IF(0, 1, c2_u == 6.0)) {
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,15);
    c2_y2 = 1.0;
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,18);
  if(CV_EML_IF(0, 2, c2_u == 7.0)) {
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,20);
    c2_y3 = 1.0;
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,-20);
  sf_debug_symbol_scope_pop();
  *c2_b_y = c2_y;
  *c2_b_y2 = c2_y2;
  *c2_b_y3 = c2_y3;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_irobotcomunication2MachineNumber_,
   chartInstance.chartNumber, chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
 c2_chartNumber)
{
}

static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_b_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_c_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_d_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray *sf_c2_irobotcomunication2_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[1];
  c2_ResolvedFunctionInfo (*c2_b_info)[1];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i0;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_b_info = &c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "eq";
  (*c2_b_info)[0].dominantType = "double";
  (*c2_b_info)[0].resolved = "[B]eq";
  (*c2_b_info)[0].fileLength = 0U;
  (*c2_b_info)[0].fileTime1 = 0U;
  (*c2_b_info)[0].fileTime2 = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 1));
  for(c2_i0 = 0; c2_i0 < 1; c2_i0 = c2_i0 + 1) {
    c2_r0 = &c2_info[c2_i0];
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->context, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
     "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->name, "nameCaptureInfo", 13, 0U,
      0U, 2, 1, strlen(c2_r0->name)), "name",
     "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->dominantType, "nameCaptureInfo",
      13, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
     "dominantType", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->resolved, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved",
     "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create(&c2_r0->fileLength, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileLength", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create(&c2_r0->fileTime1, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create(&c2_r0->fileTime2, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i0);
  }
  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c2_irobotcomunication2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1614717238U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3967018787U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2055701187U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2248194111U);
}

mxArray *sf_c2_irobotcomunication2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] =
  {"checksum","inputs","parameters","outputs"};
  mxArray *mxAutoinheritanceInfo =
  mxCreateStructMatrix(1,1,4,autoinheritanceFields);
  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2748074348U);
    pr[1] = (double)(4231046251U);
    pr[2] = (double)(2346412694U);
    pr[3] = (double)(1515056830U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);
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
          sf_debug_initialize_chart(_irobotcomunication2MachineNumber_,
         2,
         1,
         1,
         4,
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
          init_script_number_translation(_irobotcomunication2MachineNumber_,chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_irobotcomunication2MachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_irobotcomunication2MachineNumber_,
           chartInstance.chartNumber,
           0,
           0,
           0);

          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"u",0,c2_sf_marshall);
          _SFD_SET_DATA_PROPS(0,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"y",0,c2_b_sf_marshall);
          _SFD_SET_DATA_PROPS(3,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"y2",0,c2_c_sf_marshall);
          _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"y3",0,c2_d_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,3,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,206);
        _SFD_CV_INIT_EML_IF(0,0,129,136,-1,153);
        _SFD_CV_INIT_EML_IF(0,1,155,162,-1,180);
        _SFD_CV_INIT_EML_IF(0,2,181,188,-1,206);
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
          real_T *c2_u;
          real_T *c2_y;
          real_T *c2_y2;
          real_T *c2_y3;
          c2_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c2_y2 = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
          c2_y3 = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
          c2_u = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_u);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_y);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_y2);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_y3);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_irobotcomunication2MachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c2_irobotcomunication2(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c2_irobotcomunication2();
  initialize_c2_irobotcomunication2();
}

static void sf_opaque_enable_c2_irobotcomunication2(void *chartInstanceVar)
{
  enable_c2_irobotcomunication2();
}

static void sf_opaque_disable_c2_irobotcomunication2(void *chartInstanceVar)
{
  disable_c2_irobotcomunication2();
}

static void sf_opaque_gateway_c2_irobotcomunication2(void *chartInstanceVar)
{
  sf_c2_irobotcomunication2();
}

static void sf_opaque_terminate_c2_irobotcomunication2(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) ||
   sim_mode_is_external(chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }
  finalize_c2_irobotcomunication2();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_irobotcomunication2(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  if(sf_machine_global_initializer_called()) {
    initialize_params_c2_irobotcomunication2();
  }
}

static void mdlSetWorkWidths_c2_irobotcomunication2(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("irobotcomunication2",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("irobotcomunication2",2,"gatewayCannotBeInlinedMultipleTimes"));
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"irobotcomunication2",2,1);
      sf_mark_chart_reusable_outputs(S,"irobotcomunication2",2,3);
    }
    sf_set_rtw_dwork_info(S,"irobotcomunication2",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(1139631850U));
  ssSetChecksum1(S,(2033431585U));
  ssSetChecksum2(S,(3857291471U));
  ssSetChecksum3(S,(3593802485U));

  ssSetmdlDerivatives(S, NULL);

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_irobotcomunication2(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "irobotcomunication2", 2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_irobotcomunication2(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_irobotcomunication2;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c2_irobotcomunication2;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c2_irobotcomunication2;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c2_irobotcomunication2;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c2_irobotcomunication2;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c2_irobotcomunication2;
  chartInstance.chartInfo.mdlStart = mdlStart_c2_irobotcomunication2;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_irobotcomunication2;
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

void c2_irobotcomunication2_method_dispatcher(SimStruct *S, int_T method, void
 *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_irobotcomunication2(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_irobotcomunication2(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_irobotcomunication2(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c2_irobotcomunication2_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

