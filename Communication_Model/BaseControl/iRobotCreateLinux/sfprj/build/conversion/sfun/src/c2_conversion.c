/* Include files */
#include "conversion_sfun.h"
#include "c2_conversion.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "conversion_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_IN_NO_ACTIVE_CHILD           (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc2_conversionInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c2_conversion(void);
static void initialize_params_c2_conversion(void);
static void enable_c2_conversion(void);
static void disable_c2_conversion(void);
static void finalize_c2_conversion(void);
static void sf_c2_conversion(void);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
 c2_chartNumber);
static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_c_sf_marshall(void *c2_chartInstance, void *c2_u);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[20]);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c2_conversion(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c2_is_active_c2_conversion = 0U;
}

static void initialize_params_c2_conversion(void)
{
}

static void enable_c2_conversion(void)
{
}

static void disable_c2_conversion(void)
{
}

static void finalize_c2_conversion(void)
{
}

static void sf_c2_conversion(void)
{
  uint8_T c2_previousEvent;
  uint8_T c2_u;
  uint8_T c2_low;
  uint8_T c2_hi;
  uint8_T c2_a;
  real_T c2_b;
  real_T c2_x;
  real_T c2_d0;
  real_T c2_d1;
  uint8_T c2_r;
  uint8_T c2_b_a;
  real_T c2_b_b;
  real_T c2_b_x;
  real_T c2_d2;
  real_T c2_d3;
  uint8_T c2_b_r;
  uint8_T *c2_b_u;
  uint8_T *c2_b_hi;
  uint8_T *c2_b_low;
  c2_b_low = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c2_b_u = (uint8_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c2_b_hi = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_b_u, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_b_hi, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_b_low, 2U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  c2_u = *c2_b_u;
  sf_debug_symbol_scope_push(3U, 0U);
  sf_debug_symbol_scope_add("low", &c2_low, c2_c_sf_marshall);
  sf_debug_symbol_scope_add("hi", &c2_hi, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("u", &c2_u, c2_sf_marshall);
  CV_EML_FCN(0, 0);
  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  /* a=unint8(u); */
  /* format hex */
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,8);
  c2_a = c2_u;
  c2_b = 128.0;
  c2_x = c2_b;
  c2_d0 = _SFD_NOT_NAN_CHECK("x", c2_x);
  c2_d1 = c2_d0 < 0.0 ? ceil(c2_d0 - 0.5) : floor(c2_d0 + 0.5);
  c2_r = (uint8_T)(c2_d1 <= 255.0 ? c2_d1 >= 0.0 ? c2_d1 : 0.0 : 255.0);
  c2_hi = (uint8_T)(c2_a & c2_r);
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,9);
  c2_b_a = c2_u;
  c2_b_b = 1.0;
  c2_b_x = c2_b_b;
  c2_d2 = _SFD_NOT_NAN_CHECK("x", c2_b_x);
  c2_d3 = c2_d2 < 0.0 ? ceil(c2_d2 - 0.5) : floor(c2_d2 + 0.5);
  c2_b_r = (uint8_T)(c2_d3 <= 255.0 ? c2_d3 >= 0.0 ? c2_d3 : 0.0 : 255.0);
  c2_low = (uint8_T)(c2_b_a & c2_b_r);
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,-9);
  sf_debug_symbol_scope_pop();
  *c2_b_hi = c2_hi;
  *c2_b_low = c2_low;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_conversionMachineNumber_,
   chartInstance.chartNumber, chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
 c2_chartNumber)
{
}

static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  uint8_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((uint8_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 3, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_b_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  uint8_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((uint8_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 3, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_c_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  uint8_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((uint8_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 3, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray *sf_c2_conversion_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[20];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i0;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 20));
  for(c2_i0 = 0; c2_i0 < 20; c2_i0 = c2_i0 + 1) {
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

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[20])
{
  c2_info[0].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isscalar.m";
  c2_info[0].name = "gt";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[B]gt";
  c2_info[0].fileLength = 0U;
  c2_info[0].fileTime1 = 0U;
  c2_info[0].fileTime2 = 0U;
  c2_info[1].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[1].name = "ischar";
  c2_info[1].dominantType = "char";
  c2_info[1].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/strfun/ischar.m";
  c2_info[1].fileLength = 244U;
  c2_info[1].fileTime1 = 1160446833U;
  c2_info[1].fileTime2 = 0U;
  c2_info[2].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[2].name = "ge";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved = "[B]ge";
  c2_info[2].fileLength = 0U;
  c2_info[2].fileTime1 = 0U;
  c2_info[2].fileTime2 = 0U;
  c2_info[3].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c2_info[3].name = "class";
  c2_info[3].dominantType = "char";
  c2_info[3].resolved = "[B]class";
  c2_info[3].fileLength = 0U;
  c2_info[3].fileTime1 = 0U;
  c2_info[3].fileTime2 = 0U;
  c2_info[4].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c2_info[4].name = "strcmp";
  c2_info[4].dominantType = "char";
  c2_info[4].resolved = "[B]strcmp";
  c2_info[4].fileLength = 0U;
  c2_info[4].fileTime1 = 0U;
  c2_info[4].fileTime2 = 0U;
  c2_info[5].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/bitand.m";
  c2_info[5].name = "eq";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved = "[B]eq";
  c2_info[5].fileLength = 0U;
  c2_info[5].fileTime1 = 0U;
  c2_info[5].fileTime2 = 0U;
  c2_info[6].context = "";
  c2_info[6].name = "bitand";
  c2_info[6].dominantType = "uint8";
  c2_info[6].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/bitand.m";
  c2_info[6].fileLength = 1048U;
  c2_info[6].fileTime1 = 1160446790U;
  c2_info[6].fileTime2 = 0U;
  c2_info[7].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/bitand.m";
  c2_info[7].name = "isreal";
  c2_info[7].dominantType = "uint8";
  c2_info[7].resolved = "[B]isreal";
  c2_info[7].fileLength = 0U;
  c2_info[7].fileTime1 = 0U;
  c2_info[7].fileTime2 = 0U;
  c2_info[8].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/bitand.m";
  c2_info[8].name = "eml_isa_uint";
  c2_info[8].dominantType = "uint8";
  c2_info[8].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c2_info[8].fileLength = 288U;
  c2_info[8].fileTime1 = 1163970797U;
  c2_info[8].fileTime2 = 0U;
  c2_info[9].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[9].name = "uint8";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved = "[B]uint8";
  c2_info[9].fileLength = 0U;
  c2_info[9].fileTime1 = 0U;
  c2_info[9].fileTime2 = 0U;
  c2_info[10].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/bitand.m";
  c2_info[10].name = "cast";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[10].fileLength = 907U;
  c2_info[10].fileTime1 = 1160446617U;
  c2_info[10].fileTime2 = 0U;
  c2_info[11].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_numel.m";
  c2_info[11].name = "numel";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved = "[B]numel";
  c2_info[11].fileLength = 0U;
  c2_info[11].fileTime1 = 0U;
  c2_info[11].fileTime2 = 0U;
  c2_info[12].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/bitand.m";
  c2_info[12].name = "eml_assert";
  c2_info[12].dominantType = "char";
  c2_info[12].resolved = "[B]eml_assert";
  c2_info[12].fileLength = 0U;
  c2_info[12].fileTime1 = 0U;
  c2_info[12].fileTime2 = 0U;
  c2_info[13].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c2_info[13].name = "isscalar";
  c2_info[13].dominantType = "uint8";
  c2_info[13].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isscalar.m";
  c2_info[13].fileLength = 243U;
  c2_info[13].fileTime1 = 1160446704U;
  c2_info[13].fileTime2 = 0U;
  c2_info[14].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/bitand.m";
  c2_info[14].name = "eml_scalexp_compatible";
  c2_info[14].dominantType = "uint8";
  c2_info[14].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c2_info[14].fileLength = 422U;
  c2_info[14].fileTime1 = 1160446754U;
  c2_info[14].fileTime2 = 0U;
  c2_info[15].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c2_info[15].name = "isa";
  c2_info[15].dominantType = "uint8";
  c2_info[15].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c2_info[15].fileLength = 791U;
  c2_info[15].fileTime1 = 1160446618U;
  c2_info[15].fileTime2 = 0U;
  c2_info[16].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[16].name = "size";
  c2_info[16].dominantType = "uint8";
  c2_info[16].resolved = "[B]size";
  c2_info[16].fileLength = 0U;
  c2_info[16].fileTime1 = 0U;
  c2_info[16].fileTime2 = 0U;
  c2_info[17].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[17].name = "eml_numel";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_numel.m";
  c2_info[17].fileLength = 278U;
  c2_info[17].fileTime1 = 1163970801U;
  c2_info[17].fileTime2 = 0U;
  c2_info[18].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isscalar.m";
  c2_info[18].name = "length";
  c2_info[18].dominantType = "uint8";
  c2_info[18].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[18].fileLength = 347U;
  c2_info[18].fileTime1 = 1163970770U;
  c2_info[18].fileTime2 = 0U;
  c2_info[19].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/bitand.m";
  c2_info[19].name = "nargin";
  c2_info[19].dominantType = "";
  c2_info[19].resolved = "[B]nargin";
  c2_info[19].fileLength = 0U;
  c2_info[19].fileTime1 = 0U;
  c2_info[19].fileTime2 = 0U;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c2_conversion_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2628641525U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(518949932U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2658079867U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3798851045U);
}

mxArray *sf_c2_conversion_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] =
  {"checksum","inputs","parameters","outputs"};
  mxArray *mxAutoinheritanceInfo =
  mxCreateStructMatrix(1,1,4,autoinheritanceFields);
  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1799703331U);
    pr[1] = (double)(3129361015U);
    pr[2] = (double)(697983440U);
    pr[3] = (double)(683904776U);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(3));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
          sf_debug_initialize_chart(_conversionMachineNumber_,
         2,
         1,
         1,
         3,
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
          init_script_number_translation(_conversionMachineNumber_,chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_conversionMachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_conversionMachineNumber_,
           chartInstance.chartNumber,
           0,
           0,
           0);

          _SFD_SET_DATA_PROPS(1,1,1,0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"u",0,c2_sf_marshall);
          _SFD_SET_DATA_PROPS(0,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"hi",0,c2_b_sf_marshall);
          _SFD_SET_DATA_PROPS(2,2,0,1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,"low",0,c2_c_sf_marshall);
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
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,173);
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
          uint8_T *c2_u;
          uint8_T *c2_hi;
          uint8_T *c2_low;
          c2_low = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 2);
          c2_u = (uint8_T *)ssGetInputPortSignal(chartInstance.S, 0);
          c2_hi = (uint8_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_u);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_hi);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_low);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_conversionMachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c2_conversion(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c2_conversion();
  initialize_c2_conversion();
}

static void sf_opaque_enable_c2_conversion(void *chartInstanceVar)
{
  enable_c2_conversion();
}

static void sf_opaque_disable_c2_conversion(void *chartInstanceVar)
{
  disable_c2_conversion();
}

static void sf_opaque_gateway_c2_conversion(void *chartInstanceVar)
{
  sf_c2_conversion();
}

static void sf_opaque_terminate_c2_conversion(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) ||
   sim_mode_is_external(chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }
  finalize_c2_conversion();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_conversion(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  if(sf_machine_global_initializer_called()) {
    initialize_params_c2_conversion();
  }
}

static void mdlSetWorkWidths_c2_conversion(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("conversion",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("conversion",2,"gatewayCannotBeInlinedMultipleTimes"));
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"conversion",2,1);
      sf_mark_chart_reusable_outputs(S,"conversion",2,2);
    }
    sf_set_rtw_dwork_info(S,"conversion",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(2136539489U));
  ssSetChecksum1(S,(4223633763U));
  ssSetChecksum2(S,(3135089549U));
  ssSetChecksum3(S,(496029122U));

  ssSetmdlDerivatives(S, NULL);

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_conversion(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "conversion", 2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_conversion(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway = sf_opaque_gateway_c2_conversion;
  chartInstance.chartInfo.initializeChart = sf_opaque_initialize_c2_conversion;
  chartInstance.chartInfo.terminateChart = sf_opaque_terminate_c2_conversion;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c2_conversion;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c2_conversion;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c2_conversion;
  chartInstance.chartInfo.mdlStart = mdlStart_c2_conversion;
  chartInstance.chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_conversion;
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

void c2_conversion_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_conversion(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_conversion(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_conversion(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c2_conversion_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

