/* Include files */

#include <stddef.h>
#include "blas.h"
#include "EndEffectorVSCube_v2_sfun.h"
#include "c12_EndEffectorVSCube_v2.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "EndEffectorVSCube_v2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c12_debug_family_names[6] = { "nargin", "nargout", "docking",
  "dock_switch", "command_dock", "k" };

/* Function Declarations */
static void initialize_c12_EndEffectorVSCube_v2
  (SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void initialize_params_c12_EndEffectorVSCube_v2
  (SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void enable_c12_EndEffectorVSCube_v2
  (SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void disable_c12_EndEffectorVSCube_v2
  (SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void c12_update_debugger_state_c12_EndEffectorVSCube_v2
  (SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c12_EndEffectorVSCube_v2
  (SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void set_sim_state_c12_EndEffectorVSCube_v2
  (SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance, const mxArray
   *c12_st);
static void finalize_c12_EndEffectorVSCube_v2
  (SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void sf_c12_EndEffectorVSCube_v2(SFc12_EndEffectorVSCube_v2InstanceStruct
  *chartInstance);
static void initSimStructsc12_EndEffectorVSCube_v2
  (SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void registerMessagesc12_EndEffectorVSCube_v2
  (SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber);
static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static real_T c12_emlrt_marshallIn(SFc12_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c12_b_k, const char_T *c12_identifier);
static real_T c12_b_emlrt_marshallIn(SFc12_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static real_T c12_c_emlrt_marshallIn(SFc12_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c12_command_dock, const char_T *c12_identifier);
static real_T c12_d_emlrt_marshallIn(SFc12_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static int32_T c12_e_emlrt_marshallIn(SFc12_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static uint8_T c12_f_emlrt_marshallIn(SFc12_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c12_b_is_active_c12_EndEffectorVSCube_v2, const
  char_T *c12_identifier);
static uint8_T c12_g_emlrt_marshallIn(SFc12_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void init_dsm_address_info(SFc12_EndEffectorVSCube_v2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c12_EndEffectorVSCube_v2
  (SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
  chartInstance->c12_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c12_k_not_empty = FALSE;
  chartInstance->c12_is_active_c12_EndEffectorVSCube_v2 = 0U;
}

static void initialize_params_c12_EndEffectorVSCube_v2
  (SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static void enable_c12_EndEffectorVSCube_v2
  (SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c12_EndEffectorVSCube_v2
  (SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c12_update_debugger_state_c12_EndEffectorVSCube_v2
  (SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c12_EndEffectorVSCube_v2
  (SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
  const mxArray *c12_st;
  const mxArray *c12_y = NULL;
  real_T c12_hoistedGlobal;
  real_T c12_u;
  const mxArray *c12_b_y = NULL;
  real_T c12_b_hoistedGlobal;
  real_T c12_b_u;
  const mxArray *c12_c_y = NULL;
  uint8_T c12_c_hoistedGlobal;
  uint8_T c12_c_u;
  const mxArray *c12_d_y = NULL;
  real_T *c12_command_dock;
  c12_command_dock = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c12_st = NULL;
  c12_st = NULL;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_createcellarray(3), FALSE);
  c12_hoistedGlobal = *c12_command_dock;
  c12_u = c12_hoistedGlobal;
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c12_y, 0, c12_b_y);
  c12_b_hoistedGlobal = chartInstance->c12_k;
  c12_b_u = c12_b_hoistedGlobal;
  c12_c_y = NULL;
  if (!chartInstance->c12_k_not_empty) {
    sf_mex_assign(&c12_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c12_c_y, sf_mex_create("y", &c12_b_u, 0, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c12_y, 1, c12_c_y);
  c12_c_hoistedGlobal = chartInstance->c12_is_active_c12_EndEffectorVSCube_v2;
  c12_c_u = c12_c_hoistedGlobal;
  c12_d_y = NULL;
  sf_mex_assign(&c12_d_y, sf_mex_create("y", &c12_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c12_y, 2, c12_d_y);
  sf_mex_assign(&c12_st, c12_y, FALSE);
  return c12_st;
}

static void set_sim_state_c12_EndEffectorVSCube_v2
  (SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance, const mxArray
   *c12_st)
{
  const mxArray *c12_u;
  real_T *c12_command_dock;
  c12_command_dock = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c12_doneDoubleBufferReInit = TRUE;
  c12_u = sf_mex_dup(c12_st);
  *c12_command_dock = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 0)), "command_dock");
  chartInstance->c12_k = c12_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 1)), "k");
  chartInstance->c12_is_active_c12_EndEffectorVSCube_v2 = c12_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 2)),
     "is_active_c12_EndEffectorVSCube_v2");
  sf_mex_destroy(&c12_u);
  c12_update_debugger_state_c12_EndEffectorVSCube_v2(chartInstance);
  sf_mex_destroy(&c12_st);
}

static void finalize_c12_EndEffectorVSCube_v2
  (SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static void sf_c12_EndEffectorVSCube_v2(SFc12_EndEffectorVSCube_v2InstanceStruct
  *chartInstance)
{
  real_T c12_hoistedGlobal;
  real_T c12_b_hoistedGlobal;
  real_T c12_docking;
  real_T c12_dock_switch;
  uint32_T c12_debug_family_var_map[6];
  real_T c12_nargin = 2.0;
  real_T c12_nargout = 1.0;
  real_T c12_command_dock;
  real_T *c12_b_docking;
  real_T *c12_b_command_dock;
  real_T *c12_b_dock_switch;
  boolean_T guard1 = FALSE;
  c12_b_dock_switch = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c12_b_command_dock = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c12_b_docking = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, chartInstance->c12_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c12_b_docking, 0U);
  _SFD_DATA_RANGE_CHECK(*c12_b_command_dock, 1U);
  _SFD_DATA_RANGE_CHECK(*c12_b_dock_switch, 2U);
  chartInstance->c12_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c12_sfEvent);
  c12_hoistedGlobal = *c12_b_docking;
  c12_b_hoistedGlobal = *c12_b_dock_switch;
  c12_docking = c12_hoistedGlobal;
  c12_dock_switch = c12_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c12_debug_family_names,
    c12_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_nargin, 0U, c12_b_sf_marshallOut,
    c12_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_nargout, 1U, c12_b_sf_marshallOut,
    c12_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_docking, 2U, c12_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_dock_switch, 3U, c12_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_command_dock, 4U,
    c12_b_sf_marshallOut, c12_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c12_k, 5U,
    c12_sf_marshallOut, c12_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 2);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 3);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c12_k_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 4);
    chartInstance->c12_k = 0.0;
    chartInstance->c12_k_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 6);
  c12_command_dock = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 9);
  guard1 = FALSE;
  if (CV_EML_COND(0, 1, 0, c12_docking == 1.0)) {
    if (CV_EML_COND(0, 1, 1, c12_dock_switch == 1.0)) {
      CV_EML_MCDC(0, 1, 0, TRUE);
      CV_EML_IF(0, 1, 1, TRUE);
      _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 10);
      c12_command_dock = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 11);
      chartInstance->c12_k = 5.0;
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(0, 1, 0, FALSE);
    CV_EML_IF(0, 1, 1, FALSE);
    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 13);
    c12_command_dock = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, -13);
  _SFD_SYMBOL_SCOPE_POP();
  *c12_b_command_dock = c12_command_dock;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c12_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_EndEffectorVSCube_v2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc12_EndEffectorVSCube_v2
  (SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static void registerMessagesc12_EndEffectorVSCube_v2
  (SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber)
{
}

static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  real_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc12_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(real_T *)c12_inData;
  c12_y = NULL;
  if (!chartInstance->c12_k_not_empty) {
    sf_mex_assign(&c12_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static real_T c12_emlrt_marshallIn(SFc12_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c12_b_k, const char_T *c12_identifier)
{
  real_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_k), &c12_thisId);
  sf_mex_destroy(&c12_b_k);
  return c12_y;
}

static real_T c12_b_emlrt_marshallIn(SFc12_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  real_T c12_y;
  real_T c12_d0;
  if (mxIsEmpty(c12_u)) {
    chartInstance->c12_k_not_empty = FALSE;
  } else {
    chartInstance->c12_k_not_empty = TRUE;
    sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_d0, 1, 0, 0U, 0, 0U, 0);
    c12_y = c12_d0;
  }

  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_k;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y;
  SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc12_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c12_b_k = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_k), &c12_thisId);
  sf_mex_destroy(&c12_b_k);
  *(real_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  real_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc12_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(real_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static real_T c12_c_emlrt_marshallIn(SFc12_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c12_command_dock, const char_T *c12_identifier)
{
  real_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_command_dock),
    &c12_thisId);
  sf_mex_destroy(&c12_command_dock);
  return c12_y;
}

static real_T c12_d_emlrt_marshallIn(SFc12_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  real_T c12_y;
  real_T c12_d1;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_d1, 1, 0, 0U, 0, 0U, 0);
  c12_y = c12_d1;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_command_dock;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y;
  SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc12_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c12_command_dock = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_command_dock),
    &c12_thisId);
  sf_mex_destroy(&c12_command_dock);
  *(real_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

const mxArray *sf_c12_EndEffectorVSCube_v2_get_eml_resolved_functions_info(void)
{
  const mxArray *c12_nameCaptureInfo = NULL;
  c12_nameCaptureInfo = NULL;
  sf_mex_assign(&c12_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c12_nameCaptureInfo;
}

static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc12_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(int32_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static int32_T c12_e_emlrt_marshallIn(SFc12_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  int32_T c12_y;
  int32_T c12_i0;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_i0, 1, 6, 0U, 0, 0U, 0);
  c12_y = c12_i0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_sfEvent;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  int32_T c12_y;
  SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc12_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c12_b_sfEvent = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_sfEvent),
    &c12_thisId);
  sf_mex_destroy(&c12_b_sfEvent);
  *(int32_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static uint8_T c12_f_emlrt_marshallIn(SFc12_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c12_b_is_active_c12_EndEffectorVSCube_v2, const
  char_T *c12_identifier)
{
  uint8_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c12_b_is_active_c12_EndEffectorVSCube_v2), &c12_thisId);
  sf_mex_destroy(&c12_b_is_active_c12_EndEffectorVSCube_v2);
  return c12_y;
}

static uint8_T c12_g_emlrt_marshallIn(SFc12_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  uint8_T c12_y;
  uint8_T c12_u0;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_u0, 1, 3, 0U, 0, 0U, 0);
  c12_y = c12_u0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void init_dsm_address_info(SFc12_EndEffectorVSCube_v2InstanceStruct
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

void sf_c12_EndEffectorVSCube_v2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1629247734U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1906655756U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(350472212U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2048402579U);
}

mxArray *sf_c12_EndEffectorVSCube_v2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("r084EQARoOj782WfPmI5bF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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

mxArray *sf_c12_EndEffectorVSCube_v2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c12_EndEffectorVSCube_v2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"command_dock\",},{M[4],M[0],T\"k\",S'l','i','p'{{M1x2[62 63],M[0],}}},{M[8],M[0],T\"is_active_c12_EndEffectorVSCube_v2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c12_EndEffectorVSCube_v2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance;
    chartInstance = (SFc12_EndEffectorVSCube_v2InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _EndEffectorVSCube_v2MachineNumber_,
           12,
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
          init_script_number_translation(_EndEffectorVSCube_v2MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_EndEffectorVSCube_v2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _EndEffectorVSCube_v2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"docking");
          _SFD_SET_DATA_PROPS(1,2,0,1,"command_dock");
          _SFD_SET_DATA_PROPS(2,1,1,0,"dock_switch");
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
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,374);
        _SFD_CV_INIT_EML_IF(0,1,0,64,77,-1,90);
        _SFD_CV_INIT_EML_IF(0,1,1,109,144,176,206);

        {
          static int condStart[] = { 112, 128 };

          static int condEnd[] = { 124, 144 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,112,144,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)
          c12_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c12_docking;
          real_T *c12_command_dock;
          real_T *c12_dock_switch;
          c12_dock_switch = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c12_command_dock = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c12_docking = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c12_docking);
          _SFD_SET_DATA_VALUE_PTR(1U, c12_command_dock);
          _SFD_SET_DATA_VALUE_PTR(2U, c12_dock_switch);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _EndEffectorVSCube_v2MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "99TOJTrZin4YfB4OZhY3bE";
}

static void sf_opaque_initialize_c12_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc12_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c12_EndEffectorVSCube_v2
    ((SFc12_EndEffectorVSCube_v2InstanceStruct*) chartInstanceVar);
  initialize_c12_EndEffectorVSCube_v2((SFc12_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c12_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  enable_c12_EndEffectorVSCube_v2((SFc12_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c12_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  disable_c12_EndEffectorVSCube_v2((SFc12_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c12_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  sf_c12_EndEffectorVSCube_v2((SFc12_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c12_EndEffectorVSCube_v2
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c12_EndEffectorVSCube_v2
    ((SFc12_EndEffectorVSCube_v2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c12_EndEffectorVSCube_v2();/* state var info */
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

extern void sf_internal_set_sim_state_c12_EndEffectorVSCube_v2(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c12_EndEffectorVSCube_v2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c12_EndEffectorVSCube_v2
    ((SFc12_EndEffectorVSCube_v2InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c12_EndEffectorVSCube_v2(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c12_EndEffectorVSCube_v2(S);
}

static void sf_opaque_set_sim_state_c12_EndEffectorVSCube_v2(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c12_EndEffectorVSCube_v2(S, st);
}

static void sf_opaque_terminate_c12_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc12_EndEffectorVSCube_v2InstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_EndEffectorVSCube_v2_optimization_info();
    }

    finalize_c12_EndEffectorVSCube_v2((SFc12_EndEffectorVSCube_v2InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc12_EndEffectorVSCube_v2
    ((SFc12_EndEffectorVSCube_v2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c12_EndEffectorVSCube_v2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c12_EndEffectorVSCube_v2
      ((SFc12_EndEffectorVSCube_v2InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c12_EndEffectorVSCube_v2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_EndEffectorVSCube_v2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      12);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,12,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,12,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,12);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,12,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,12,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,12);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3210708631U));
  ssSetChecksum1(S,(82742231U));
  ssSetChecksum2(S,(1609928224U));
  ssSetChecksum3(S,(3801109687U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c12_EndEffectorVSCube_v2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c12_EndEffectorVSCube_v2(SimStruct *S)
{
  SFc12_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc12_EndEffectorVSCube_v2InstanceStruct *)utMalloc(sizeof
    (SFc12_EndEffectorVSCube_v2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc12_EndEffectorVSCube_v2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c12_EndEffectorVSCube_v2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c12_EndEffectorVSCube_v2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c12_EndEffectorVSCube_v2;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c12_EndEffectorVSCube_v2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c12_EndEffectorVSCube_v2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c12_EndEffectorVSCube_v2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c12_EndEffectorVSCube_v2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c12_EndEffectorVSCube_v2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c12_EndEffectorVSCube_v2;
  chartInstance->chartInfo.mdlStart = mdlStart_c12_EndEffectorVSCube_v2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c12_EndEffectorVSCube_v2;
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

void c12_EndEffectorVSCube_v2_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c12_EndEffectorVSCube_v2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c12_EndEffectorVSCube_v2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c12_EndEffectorVSCube_v2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c12_EndEffectorVSCube_v2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
