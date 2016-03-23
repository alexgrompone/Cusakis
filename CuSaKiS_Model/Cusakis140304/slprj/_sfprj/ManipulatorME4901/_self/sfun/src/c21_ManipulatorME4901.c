/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ManipulatorME4901_sfun.h"
#include "c21_ManipulatorME4901.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ManipulatorME4901_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c21_debug_family_names[14] = { "a", "b", "c", "nargin",
  "nargout", "t1", "t2", "t3", "qd1", "qd2", "qd3", "Mem", "E", "Etot" };

/* Function Declarations */
static void initialize_c21_ManipulatorME4901
  (SFc21_ManipulatorME4901InstanceStruct *chartInstance);
static void initialize_params_c21_ManipulatorME4901
  (SFc21_ManipulatorME4901InstanceStruct *chartInstance);
static void enable_c21_ManipulatorME4901(SFc21_ManipulatorME4901InstanceStruct
  *chartInstance);
static void disable_c21_ManipulatorME4901(SFc21_ManipulatorME4901InstanceStruct *
  chartInstance);
static void c21_update_debugger_state_c21_ManipulatorME4901
  (SFc21_ManipulatorME4901InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c21_ManipulatorME4901
  (SFc21_ManipulatorME4901InstanceStruct *chartInstance);
static void set_sim_state_c21_ManipulatorME4901
  (SFc21_ManipulatorME4901InstanceStruct *chartInstance, const mxArray *c21_st);
static void finalize_c21_ManipulatorME4901(SFc21_ManipulatorME4901InstanceStruct
  *chartInstance);
static void sf_c21_ManipulatorME4901(SFc21_ManipulatorME4901InstanceStruct
  *chartInstance);
static void initSimStructsc21_ManipulatorME4901
  (SFc21_ManipulatorME4901InstanceStruct *chartInstance);
static void registerMessagesc21_ManipulatorME4901
  (SFc21_ManipulatorME4901InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c21_machineNumber, uint32_T
  c21_chartNumber);
static const mxArray *c21_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static real_T c21_emlrt_marshallIn(SFc21_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c21_Etot, const char_T *c21_identifier);
static real_T c21_b_emlrt_marshallIn(SFc21_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void c21_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static const mxArray *c21_b_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static int32_T c21_c_emlrt_marshallIn(SFc21_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void c21_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static uint8_T c21_d_emlrt_marshallIn(SFc21_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c21_b_is_active_c21_ManipulatorME4901, const
  char_T *c21_identifier);
static uint8_T c21_e_emlrt_marshallIn(SFc21_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void init_dsm_address_info(SFc21_ManipulatorME4901InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c21_ManipulatorME4901
  (SFc21_ManipulatorME4901InstanceStruct *chartInstance)
{
  chartInstance->c21_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c21_is_active_c21_ManipulatorME4901 = 0U;
}

static void initialize_params_c21_ManipulatorME4901
  (SFc21_ManipulatorME4901InstanceStruct *chartInstance)
{
}

static void enable_c21_ManipulatorME4901(SFc21_ManipulatorME4901InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c21_ManipulatorME4901(SFc21_ManipulatorME4901InstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c21_update_debugger_state_c21_ManipulatorME4901
  (SFc21_ManipulatorME4901InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c21_ManipulatorME4901
  (SFc21_ManipulatorME4901InstanceStruct *chartInstance)
{
  const mxArray *c21_st;
  const mxArray *c21_y = NULL;
  real_T c21_hoistedGlobal;
  real_T c21_u;
  const mxArray *c21_b_y = NULL;
  real_T c21_b_hoistedGlobal;
  real_T c21_b_u;
  const mxArray *c21_c_y = NULL;
  uint8_T c21_c_hoistedGlobal;
  uint8_T c21_c_u;
  const mxArray *c21_d_y = NULL;
  real_T *c21_E;
  real_T *c21_Etot;
  c21_Etot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c21_E = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c21_st = NULL;
  c21_st = NULL;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_createcellarray(3), FALSE);
  c21_hoistedGlobal = *c21_E;
  c21_u = c21_hoistedGlobal;
  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", &c21_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c21_y, 0, c21_b_y);
  c21_b_hoistedGlobal = *c21_Etot;
  c21_b_u = c21_b_hoistedGlobal;
  c21_c_y = NULL;
  sf_mex_assign(&c21_c_y, sf_mex_create("y", &c21_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c21_y, 1, c21_c_y);
  c21_c_hoistedGlobal = chartInstance->c21_is_active_c21_ManipulatorME4901;
  c21_c_u = c21_c_hoistedGlobal;
  c21_d_y = NULL;
  sf_mex_assign(&c21_d_y, sf_mex_create("y", &c21_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c21_y, 2, c21_d_y);
  sf_mex_assign(&c21_st, c21_y, FALSE);
  return c21_st;
}

static void set_sim_state_c21_ManipulatorME4901
  (SFc21_ManipulatorME4901InstanceStruct *chartInstance, const mxArray *c21_st)
{
  const mxArray *c21_u;
  real_T *c21_E;
  real_T *c21_Etot;
  c21_Etot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c21_E = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c21_doneDoubleBufferReInit = TRUE;
  c21_u = sf_mex_dup(c21_st);
  *c21_E = c21_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c21_u,
    0)), "E");
  *c21_Etot = c21_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c21_u, 1)), "Etot");
  chartInstance->c21_is_active_c21_ManipulatorME4901 = c21_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c21_u, 2)),
     "is_active_c21_ManipulatorME4901");
  sf_mex_destroy(&c21_u);
  c21_update_debugger_state_c21_ManipulatorME4901(chartInstance);
  sf_mex_destroy(&c21_st);
}

static void finalize_c21_ManipulatorME4901(SFc21_ManipulatorME4901InstanceStruct
  *chartInstance)
{
}

static void sf_c21_ManipulatorME4901(SFc21_ManipulatorME4901InstanceStruct
  *chartInstance)
{
  real_T c21_hoistedGlobal;
  real_T c21_b_hoistedGlobal;
  real_T c21_c_hoistedGlobal;
  real_T c21_d_hoistedGlobal;
  real_T c21_e_hoistedGlobal;
  real_T c21_f_hoistedGlobal;
  real_T c21_g_hoistedGlobal;
  real_T c21_t1;
  real_T c21_t2;
  real_T c21_t3;
  real_T c21_qd1;
  real_T c21_qd2;
  real_T c21_qd3;
  real_T c21_Mem;
  uint32_T c21_debug_family_var_map[14];
  real_T c21_a;
  real_T c21_b;
  real_T c21_c;
  real_T c21_nargin = 7.0;
  real_T c21_nargout = 2.0;
  real_T c21_E;
  real_T c21_Etot;
  real_T c21_b_a;
  real_T c21_b_b;
  real_T c21_y;
  real_T c21_x;
  real_T c21_b_x;
  real_T c21_c_a;
  real_T c21_c_b;
  real_T c21_b_y;
  real_T c21_c_x;
  real_T c21_d_x;
  real_T c21_d_a;
  real_T c21_d_b;
  real_T c21_c_y;
  real_T c21_e_x;
  real_T c21_f_x;
  real_T *c21_b_E;
  real_T *c21_b_t1;
  real_T *c21_b_t2;
  real_T *c21_b_t3;
  real_T *c21_b_qd1;
  real_T *c21_b_qd2;
  real_T *c21_b_qd3;
  real_T *c21_b_Mem;
  real_T *c21_b_Etot;
  c21_b_Etot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c21_b_Mem = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c21_b_qd3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c21_b_qd2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c21_b_qd1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c21_b_t3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c21_b_t2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c21_b_t1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c21_b_E = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 20U, chartInstance->c21_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c21_b_E, 0U);
  _SFD_DATA_RANGE_CHECK(*c21_b_t1, 1U);
  _SFD_DATA_RANGE_CHECK(*c21_b_t2, 2U);
  _SFD_DATA_RANGE_CHECK(*c21_b_t3, 3U);
  _SFD_DATA_RANGE_CHECK(*c21_b_qd1, 4U);
  _SFD_DATA_RANGE_CHECK(*c21_b_qd2, 5U);
  _SFD_DATA_RANGE_CHECK(*c21_b_qd3, 6U);
  _SFD_DATA_RANGE_CHECK(*c21_b_Mem, 7U);
  _SFD_DATA_RANGE_CHECK(*c21_b_Etot, 8U);
  chartInstance->c21_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 20U, chartInstance->c21_sfEvent);
  c21_hoistedGlobal = *c21_b_t1;
  c21_b_hoistedGlobal = *c21_b_t2;
  c21_c_hoistedGlobal = *c21_b_t3;
  c21_d_hoistedGlobal = *c21_b_qd1;
  c21_e_hoistedGlobal = *c21_b_qd2;
  c21_f_hoistedGlobal = *c21_b_qd3;
  c21_g_hoistedGlobal = *c21_b_Mem;
  c21_t1 = c21_hoistedGlobal;
  c21_t2 = c21_b_hoistedGlobal;
  c21_t3 = c21_c_hoistedGlobal;
  c21_qd1 = c21_d_hoistedGlobal;
  c21_qd2 = c21_e_hoistedGlobal;
  c21_qd3 = c21_f_hoistedGlobal;
  c21_Mem = c21_g_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 14U, c21_debug_family_names,
    c21_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_a, 0U, c21_sf_marshallOut,
    c21_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_b, 1U, c21_sf_marshallOut,
    c21_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_c, 2U, c21_sf_marshallOut,
    c21_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_nargin, 3U, c21_sf_marshallOut,
    c21_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_nargout, 4U, c21_sf_marshallOut,
    c21_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c21_t1, 5U, c21_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c21_t2, 6U, c21_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c21_t3, 7U, c21_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c21_qd1, 8U, c21_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c21_qd2, 9U, c21_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c21_qd3, 10U, c21_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c21_Mem, 11U, c21_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_E, 12U, c21_sf_marshallOut,
    c21_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_Etot, 13U, c21_sf_marshallOut,
    c21_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 5);
  c21_b_a = c21_t1;
  c21_b_b = c21_qd1;
  c21_y = c21_b_a * c21_b_b;
  c21_x = c21_y;
  c21_b_x = c21_x;
  c21_a = muDoubleScalarAbs(c21_b_x);
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 7);
  c21_c_a = c21_t2;
  c21_c_b = c21_qd2;
  c21_b_y = c21_c_a * c21_c_b;
  c21_c_x = c21_b_y;
  c21_d_x = c21_c_x;
  c21_b = muDoubleScalarAbs(c21_d_x);
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 9);
  c21_d_a = c21_t3;
  c21_d_b = c21_qd3;
  c21_c_y = c21_d_a * c21_d_b;
  c21_e_x = c21_c_y;
  c21_f_x = c21_e_x;
  c21_c = muDoubleScalarAbs(c21_f_x);
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 12);
  c21_E = (c21_a + c21_b) + c21_c;
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 15);
  c21_Etot = c21_E + c21_Mem;
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, -15);
  _SFD_SYMBOL_SCOPE_POP();
  *c21_b_E = c21_E;
  *c21_b_Etot = c21_Etot;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, chartInstance->c21_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ManipulatorME4901MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc21_ManipulatorME4901
  (SFc21_ManipulatorME4901InstanceStruct *chartInstance)
{
}

static void registerMessagesc21_ManipulatorME4901
  (SFc21_ManipulatorME4901InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c21_machineNumber, uint32_T
  c21_chartNumber)
{
}

static const mxArray *c21_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  real_T c21_u;
  const mxArray *c21_y = NULL;
  SFc21_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc21_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_u = *(real_T *)c21_inData;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", &c21_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, FALSE);
  return c21_mxArrayOutData;
}

static real_T c21_emlrt_marshallIn(SFc21_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c21_Etot, const char_T *c21_identifier)
{
  real_T c21_y;
  emlrtMsgIdentifier c21_thisId;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_Etot),
    &c21_thisId);
  sf_mex_destroy(&c21_Etot);
  return c21_y;
}

static real_T c21_b_emlrt_marshallIn(SFc21_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  real_T c21_y;
  real_T c21_d0;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_d0, 1, 0, 0U, 0, 0U, 0);
  c21_y = c21_d0;
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static void c21_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_Etot;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  real_T c21_y;
  SFc21_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc21_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c21_Etot = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_Etot),
    &c21_thisId);
  sf_mex_destroy(&c21_Etot);
  *(real_T *)c21_outData = c21_y;
  sf_mex_destroy(&c21_mxArrayInData);
}

const mxArray *sf_c21_ManipulatorME4901_get_eml_resolved_functions_info(void)
{
  const mxArray *c21_nameCaptureInfo;
  c21_ResolvedFunctionInfo c21_info[3];
  c21_ResolvedFunctionInfo (*c21_b_info)[3];
  const mxArray *c21_m0 = NULL;
  int32_T c21_i0;
  c21_ResolvedFunctionInfo *c21_r0;
  c21_nameCaptureInfo = NULL;
  c21_nameCaptureInfo = NULL;
  c21_b_info = (c21_ResolvedFunctionInfo (*)[3])c21_info;
  (*c21_b_info)[0].context = "";
  (*c21_b_info)[0].name = "mtimes";
  (*c21_b_info)[0].dominantType = "double";
  (*c21_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c21_b_info)[0].fileTimeLo = 1289552092U;
  (*c21_b_info)[0].fileTimeHi = 0U;
  (*c21_b_info)[0].mFileTimeLo = 0U;
  (*c21_b_info)[0].mFileTimeHi = 0U;
  (*c21_b_info)[1].context = "";
  (*c21_b_info)[1].name = "abs";
  (*c21_b_info)[1].dominantType = "double";
  (*c21_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c21_b_info)[1].fileTimeLo = 1343862766U;
  (*c21_b_info)[1].fileTimeHi = 0U;
  (*c21_b_info)[1].mFileTimeLo = 0U;
  (*c21_b_info)[1].mFileTimeHi = 0U;
  (*c21_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c21_b_info)[2].name = "eml_scalar_abs";
  (*c21_b_info)[2].dominantType = "double";
  (*c21_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  (*c21_b_info)[2].fileTimeLo = 1286851112U;
  (*c21_b_info)[2].fileTimeHi = 0U;
  (*c21_b_info)[2].mFileTimeLo = 0U;
  (*c21_b_info)[2].mFileTimeHi = 0U;
  sf_mex_assign(&c21_m0, sf_mex_createstruct("nameCaptureInfo", 1, 3), FALSE);
  for (c21_i0 = 0; c21_i0 < 3; c21_i0++) {
    c21_r0 = &c21_info[c21_i0];
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", c21_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c21_r0->context)), "context", "nameCaptureInfo",
                    c21_i0);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", c21_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c21_r0->name)), "name", "nameCaptureInfo", c21_i0);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo",
      c21_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c21_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c21_i0);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", c21_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c21_r0->resolved)), "resolved",
                    "nameCaptureInfo", c21_i0);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", &c21_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c21_i0);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", &c21_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c21_i0);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo",
      &c21_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c21_i0);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo",
      &c21_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c21_i0);
  }

  sf_mex_assign(&c21_nameCaptureInfo, c21_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c21_nameCaptureInfo);
  return c21_nameCaptureInfo;
}

static const mxArray *c21_b_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  int32_T c21_u;
  const mxArray *c21_y = NULL;
  SFc21_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc21_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_u = *(int32_T *)c21_inData;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", &c21_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, FALSE);
  return c21_mxArrayOutData;
}

static int32_T c21_c_emlrt_marshallIn(SFc21_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  int32_T c21_y;
  int32_T c21_i1;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_i1, 1, 6, 0U, 0, 0U, 0);
  c21_y = c21_i1;
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static void c21_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_b_sfEvent;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  int32_T c21_y;
  SFc21_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc21_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c21_b_sfEvent = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_sfEvent),
    &c21_thisId);
  sf_mex_destroy(&c21_b_sfEvent);
  *(int32_T *)c21_outData = c21_y;
  sf_mex_destroy(&c21_mxArrayInData);
}

static uint8_T c21_d_emlrt_marshallIn(SFc21_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c21_b_is_active_c21_ManipulatorME4901, const
  char_T *c21_identifier)
{
  uint8_T c21_y;
  emlrtMsgIdentifier c21_thisId;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c21_b_is_active_c21_ManipulatorME4901), &c21_thisId);
  sf_mex_destroy(&c21_b_is_active_c21_ManipulatorME4901);
  return c21_y;
}

static uint8_T c21_e_emlrt_marshallIn(SFc21_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  uint8_T c21_y;
  uint8_T c21_u0;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_u0, 1, 3, 0U, 0, 0U, 0);
  c21_y = c21_u0;
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static void init_dsm_address_info(SFc21_ManipulatorME4901InstanceStruct
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

void sf_c21_ManipulatorME4901_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3499992804U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2588532821U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2494918590U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2175526354U);
}

mxArray *sf_c21_ManipulatorME4901_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("OhEHVCUweW4fPSHuVgsH1G");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
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

mxArray *sf_c21_ManipulatorME4901_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c21_ManipulatorME4901(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[6],T\"E\",},{M[1],M[12],T\"Etot\",},{M[8],M[0],T\"is_active_c21_ManipulatorME4901\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c21_ManipulatorME4901_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc21_ManipulatorME4901InstanceStruct *chartInstance;
    chartInstance = (SFc21_ManipulatorME4901InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ManipulatorME4901MachineNumber_,
           21,
           1,
           1,
           9,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"E");
          _SFD_SET_DATA_PROPS(1,1,1,0,"t1");
          _SFD_SET_DATA_PROPS(2,1,1,0,"t2");
          _SFD_SET_DATA_PROPS(3,1,1,0,"t3");
          _SFD_SET_DATA_PROPS(4,1,1,0,"qd1");
          _SFD_SET_DATA_PROPS(5,1,1,0,"qd2");
          _SFD_SET_DATA_PROPS(6,1,1,0,"qd3");
          _SFD_SET_DATA_PROPS(7,1,1,0,"Mem");
          _SFD_SET_DATA_PROPS(8,2,0,1,"Etot");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,135);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c21_sf_marshallOut,(MexInFcnForType)c21_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c21_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c21_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c21_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c21_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c21_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c21_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c21_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c21_sf_marshallOut,(MexInFcnForType)c21_sf_marshallIn);

        {
          real_T *c21_E;
          real_T *c21_t1;
          real_T *c21_t2;
          real_T *c21_t3;
          real_T *c21_qd1;
          real_T *c21_qd2;
          real_T *c21_qd3;
          real_T *c21_Mem;
          real_T *c21_Etot;
          c21_Etot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c21_Mem = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c21_qd3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c21_qd2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c21_qd1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c21_t3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c21_t2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c21_t1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c21_E = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c21_E);
          _SFD_SET_DATA_VALUE_PTR(1U, c21_t1);
          _SFD_SET_DATA_VALUE_PTR(2U, c21_t2);
          _SFD_SET_DATA_VALUE_PTR(3U, c21_t3);
          _SFD_SET_DATA_VALUE_PTR(4U, c21_qd1);
          _SFD_SET_DATA_VALUE_PTR(5U, c21_qd2);
          _SFD_SET_DATA_VALUE_PTR(6U, c21_qd3);
          _SFD_SET_DATA_VALUE_PTR(7U, c21_Mem);
          _SFD_SET_DATA_VALUE_PTR(8U, c21_Etot);
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
  return "AqEKPyUKh5PbOLDiddboQB";
}

static void sf_opaque_initialize_c21_ManipulatorME4901(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc21_ManipulatorME4901InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c21_ManipulatorME4901((SFc21_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
  initialize_c21_ManipulatorME4901((SFc21_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c21_ManipulatorME4901(void *chartInstanceVar)
{
  enable_c21_ManipulatorME4901((SFc21_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c21_ManipulatorME4901(void *chartInstanceVar)
{
  disable_c21_ManipulatorME4901((SFc21_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c21_ManipulatorME4901(void *chartInstanceVar)
{
  sf_c21_ManipulatorME4901((SFc21_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c21_ManipulatorME4901(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c21_ManipulatorME4901
    ((SFc21_ManipulatorME4901InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c21_ManipulatorME4901();/* state var info */
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

extern void sf_internal_set_sim_state_c21_ManipulatorME4901(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c21_ManipulatorME4901();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c21_ManipulatorME4901((SFc21_ManipulatorME4901InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c21_ManipulatorME4901(SimStruct* S)
{
  return sf_internal_get_sim_state_c21_ManipulatorME4901(S);
}

static void sf_opaque_set_sim_state_c21_ManipulatorME4901(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c21_ManipulatorME4901(S, st);
}

static void sf_opaque_terminate_c21_ManipulatorME4901(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc21_ManipulatorME4901InstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ManipulatorME4901_optimization_info();
    }

    finalize_c21_ManipulatorME4901((SFc21_ManipulatorME4901InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc21_ManipulatorME4901((SFc21_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c21_ManipulatorME4901(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c21_ManipulatorME4901
      ((SFc21_ManipulatorME4901InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c21_ManipulatorME4901(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ManipulatorME4901_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      21);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,21,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,21,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,21);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,21,7);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,21,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 7; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,21);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1964587563U));
  ssSetChecksum1(S,(4081618987U));
  ssSetChecksum2(S,(2389893486U));
  ssSetChecksum3(S,(270112379U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c21_ManipulatorME4901(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c21_ManipulatorME4901(SimStruct *S)
{
  SFc21_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc21_ManipulatorME4901InstanceStruct *)utMalloc(sizeof
    (SFc21_ManipulatorME4901InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc21_ManipulatorME4901InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c21_ManipulatorME4901;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c21_ManipulatorME4901;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c21_ManipulatorME4901;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c21_ManipulatorME4901;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c21_ManipulatorME4901;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c21_ManipulatorME4901;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c21_ManipulatorME4901;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c21_ManipulatorME4901;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c21_ManipulatorME4901;
  chartInstance->chartInfo.mdlStart = mdlStart_c21_ManipulatorME4901;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c21_ManipulatorME4901;
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

void c21_ManipulatorME4901_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c21_ManipulatorME4901(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c21_ManipulatorME4901(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c21_ManipulatorME4901(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c21_ManipulatorME4901_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
