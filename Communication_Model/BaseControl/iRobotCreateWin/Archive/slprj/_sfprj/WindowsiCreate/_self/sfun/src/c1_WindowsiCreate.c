/* Include files */

#include <stddef.h>
#include "blas.h"
#include "WindowsiCreate_sfun.h"
#include "c1_WindowsiCreate.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "WindowsiCreate_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[13] = { "nargin", "nargout", "memR",
  "memL", "u", "RotationVel", "LinearVel", "loopm", "countm", "Right", "Left",
  "loop", "count" };

/* Function Declarations */
static void initialize_c1_WindowsiCreate(SFc1_WindowsiCreateInstanceStruct
  *chartInstance);
static void initialize_params_c1_WindowsiCreate
  (SFc1_WindowsiCreateInstanceStruct *chartInstance);
static void enable_c1_WindowsiCreate(SFc1_WindowsiCreateInstanceStruct
  *chartInstance);
static void disable_c1_WindowsiCreate(SFc1_WindowsiCreateInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_WindowsiCreate
  (SFc1_WindowsiCreateInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_WindowsiCreate
  (SFc1_WindowsiCreateInstanceStruct *chartInstance);
static void set_sim_state_c1_WindowsiCreate(SFc1_WindowsiCreateInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_WindowsiCreate(SFc1_WindowsiCreateInstanceStruct
  *chartInstance);
static void sf_c1_WindowsiCreate(SFc1_WindowsiCreateInstanceStruct
  *chartInstance);
static void initSimStructsc1_WindowsiCreate(SFc1_WindowsiCreateInstanceStruct
  *chartInstance);
static void registerMessagesc1_WindowsiCreate(SFc1_WindowsiCreateInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_WindowsiCreateInstanceStruct
  *chartInstance, const mxArray *c1_count, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_WindowsiCreateInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_c_emlrt_marshallIn(SFc1_WindowsiCreateInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_d_emlrt_marshallIn(SFc1_WindowsiCreateInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_WindowsiCreate, const char_T *
  c1_identifier);
static uint8_T c1_e_emlrt_marshallIn(SFc1_WindowsiCreateInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_WindowsiCreateInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_WindowsiCreate(SFc1_WindowsiCreateInstanceStruct
  *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_WindowsiCreate = 0U;
}

static void initialize_params_c1_WindowsiCreate
  (SFc1_WindowsiCreateInstanceStruct *chartInstance)
{
}

static void enable_c1_WindowsiCreate(SFc1_WindowsiCreateInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_WindowsiCreate(SFc1_WindowsiCreateInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_WindowsiCreate
  (SFc1_WindowsiCreateInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_WindowsiCreate
  (SFc1_WindowsiCreateInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_c_hoistedGlobal;
  real_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_d_hoistedGlobal;
  real_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  uint8_T c1_e_hoistedGlobal;
  uint8_T c1_e_u;
  const mxArray *c1_f_y = NULL;
  real_T *c1_Left;
  real_T *c1_Right;
  real_T *c1_count;
  real_T *c1_loop;
  c1_count = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_loop = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_Left = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_Right = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(5), FALSE);
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
  c1_c_hoistedGlobal = *c1_count;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = *c1_loop;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_e_hoistedGlobal = chartInstance->c1_is_active_c1_WindowsiCreate;
  c1_e_u = c1_e_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_WindowsiCreate(SFc1_WindowsiCreateInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_Left;
  real_T *c1_Right;
  real_T *c1_count;
  real_T *c1_loop;
  c1_count = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_loop = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_Left = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_Right = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_Left = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    0)), "Left");
  *c1_Right = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    1)), "Right");
  *c1_count = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    2)), "count");
  *c1_loop = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    3)), "loop");
  chartInstance->c1_is_active_c1_WindowsiCreate = c1_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 4)),
     "is_active_c1_WindowsiCreate");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_WindowsiCreate(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_WindowsiCreate(SFc1_WindowsiCreateInstanceStruct
  *chartInstance)
{
}

static void sf_c1_WindowsiCreate(SFc1_WindowsiCreateInstanceStruct
  *chartInstance)
{
  int32_T c1_i0;
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  real_T c1_d_hoistedGlobal;
  real_T c1_e_hoistedGlobal;
  real_T c1_f_hoistedGlobal;
  real_T c1_memR;
  real_T c1_memL;
  int32_T c1_i1;
  real_T c1_u[2];
  real_T c1_RotationVel;
  real_T c1_LinearVel;
  real_T c1_loopm;
  real_T c1_countm;
  uint32_T c1_debug_family_var_map[13];
  real_T c1_nargin = 7.0;
  real_T c1_nargout = 4.0;
  real_T c1_Right;
  real_T c1_Left;
  real_T c1_loop;
  real_T c1_count;
  real_T *c1_b_memR;
  real_T *c1_b_memL;
  real_T *c1_b_RotationVel;
  real_T *c1_b_LinearVel;
  real_T *c1_b_loopm;
  real_T *c1_b_countm;
  real_T *c1_b_Right;
  real_T *c1_b_Left;
  real_T *c1_b_loop;
  real_T *c1_b_count;
  real_T (*c1_b_u)[2];
  boolean_T guard1 = FALSE;
  c1_b_count = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_b_loop = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_b_Left = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_Right = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_countm = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c1_b_loopm = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c1_b_LinearVel = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_b_RotationVel = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_u = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_memL = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_memR = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_b_memR, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_b_memL, 1U);
  for (c1_i0 = 0; c1_i0 < 2; c1_i0++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_u)[c1_i0], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_b_RotationVel, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_b_LinearVel, 4U);
  _SFD_DATA_RANGE_CHECK(*c1_b_loopm, 5U);
  _SFD_DATA_RANGE_CHECK(*c1_b_countm, 6U);
  _SFD_DATA_RANGE_CHECK(*c1_b_Right, 7U);
  _SFD_DATA_RANGE_CHECK(*c1_b_Left, 8U);
  _SFD_DATA_RANGE_CHECK(*c1_b_loop, 9U);
  _SFD_DATA_RANGE_CHECK(*c1_b_count, 10U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_memR;
  c1_b_hoistedGlobal = *c1_b_memL;
  c1_c_hoistedGlobal = *c1_b_RotationVel;
  c1_d_hoistedGlobal = *c1_b_LinearVel;
  c1_e_hoistedGlobal = *c1_b_loopm;
  c1_f_hoistedGlobal = *c1_b_countm;
  c1_memR = c1_hoistedGlobal;
  c1_memL = c1_b_hoistedGlobal;
  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_u[c1_i1] = (*c1_b_u)[c1_i1];
  }

  c1_RotationVel = c1_c_hoistedGlobal;
  c1_LinearVel = c1_d_hoistedGlobal;
  c1_loopm = c1_e_hoistedGlobal;
  c1_countm = c1_f_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_memR, 2U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_memL, 3U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_u, 4U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_RotationVel, 5U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_LinearVel, 6U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_loopm, 7U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_countm, 8U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_Right, 9U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_Left, 10U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_loop, 11U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_count, 12U, c1_sf_marshallOut,
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

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 31);
  if (CV_EML_IF(0, 1, 4, c1_loopm == 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 33);
    guard1 = FALSE;
    if (CV_EML_COND(0, 1, 0, c1_Right == c1_memR)) {
      if (CV_EML_COND(0, 1, 1, c1_Left == c1_memL)) {
        CV_EML_MCDC(0, 1, 0, TRUE);
        CV_EML_IF(0, 1, 5, TRUE);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 34);
        c1_loop = 0.0;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 35);
        c1_count = 0.0;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 36);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 37);
      } else {
        guard1 = TRUE;
      }
    } else {
      guard1 = TRUE;
    }

    if (guard1 == TRUE) {
      CV_EML_MCDC(0, 1, 0, FALSE);
      CV_EML_IF(0, 1, 5, FALSE);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 39);
      c1_loop = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 40);
      c1_count = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 41);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 42);
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 46);
    if (CV_EML_IF(0, 1, 6, c1_countm == 7.0)) {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 47);
      c1_loop = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 48);
      c1_count = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 49);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 50);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 52);
      c1_loop = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 53);
      c1_count = c1_countm + 1.0;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 54);
      c1_Right = c1_memR;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 55);
      c1_Left = c1_memL;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -55);
  _SFD_SYMBOL_SCOPE_POP();
  *c1_b_Right = c1_Right;
  *c1_b_Left = c1_Left;
  *c1_b_loop = c1_loop;
  *c1_b_count = c1_count;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_WindowsiCreateMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc1_WindowsiCreate(SFc1_WindowsiCreateInstanceStruct
  *chartInstance)
{
}

static void registerMessagesc1_WindowsiCreate(SFc1_WindowsiCreateInstanceStruct *
  chartInstance)
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
  SFc1_WindowsiCreateInstanceStruct *chartInstance;
  chartInstance = (SFc1_WindowsiCreateInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_WindowsiCreateInstanceStruct
  *chartInstance, const mxArray *c1_count, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_count), &c1_thisId);
  sf_mex_destroy(&c1_count);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_WindowsiCreateInstanceStruct
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
  const mxArray *c1_count;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_WindowsiCreateInstanceStruct *chartInstance;
  chartInstance = (SFc1_WindowsiCreateInstanceStruct *)chartInstanceVoid;
  c1_count = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_count), &c1_thisId);
  sf_mex_destroy(&c1_count);
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
  SFc1_WindowsiCreateInstanceStruct *chartInstance;
  chartInstance = (SFc1_WindowsiCreateInstanceStruct *)chartInstanceVoid;
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

const mxArray *sf_c1_WindowsiCreate_get_eml_resolved_functions_info(void)
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
  SFc1_WindowsiCreateInstanceStruct *chartInstance;
  chartInstance = (SFc1_WindowsiCreateInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_c_emlrt_marshallIn(SFc1_WindowsiCreateInstanceStruct
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
  SFc1_WindowsiCreateInstanceStruct *chartInstance;
  chartInstance = (SFc1_WindowsiCreateInstanceStruct *)chartInstanceVoid;
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

static uint8_T c1_d_emlrt_marshallIn(SFc1_WindowsiCreateInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_WindowsiCreate, const char_T *
  c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_WindowsiCreate), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_WindowsiCreate);
  return c1_y;
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_WindowsiCreateInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_WindowsiCreateInstanceStruct
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

void sf_c1_WindowsiCreate_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3758738652U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3771731957U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1865285831U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2891085555U);
}

mxArray *sf_c1_WindowsiCreate_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("QakVTfsLBNWL32DTWYzXsE");
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
      pr[0] = (double)(2);
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

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_WindowsiCreate_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_WindowsiCreate(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[10],T\"Left\",},{M[1],M[9],T\"Right\",},{M[1],M[11],T\"count\",},{M[1],M[14],T\"loop\",},{M[8],M[0],T\"is_active_c1_WindowsiCreate\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_WindowsiCreate_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_WindowsiCreateInstanceStruct *chartInstance;
    chartInstance = (SFc1_WindowsiCreateInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _WindowsiCreateMachineNumber_,
           1,
           1,
           1,
           11,
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
          init_script_number_translation(_WindowsiCreateMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_WindowsiCreateMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _WindowsiCreateMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"memR");
          _SFD_SET_DATA_PROPS(1,1,1,0,"memL");
          _SFD_SET_DATA_PROPS(2,1,1,0,"u");
          _SFD_SET_DATA_PROPS(3,1,1,0,"RotationVel");
          _SFD_SET_DATA_PROPS(4,1,1,0,"LinearVel");
          _SFD_SET_DATA_PROPS(5,1,1,0,"loopm");
          _SFD_SET_DATA_PROPS(6,1,1,0,"countm");
          _SFD_SET_DATA_PROPS(7,2,0,1,"Right");
          _SFD_SET_DATA_PROPS(8,2,0,1,"Left");
          _SFD_SET_DATA_PROPS(9,2,0,1,"loop");
          _SFD_SET_DATA_PROPS(10,2,0,1,"count");
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
        _SFD_CV_INIT_EML(0,1,1,7,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1082);
        _SFD_CV_INIT_EML_IF(0,1,0,213,223,275,370);
        _SFD_CV_INIT_EML_IF(0,1,1,275,290,343,370);
        _SFD_CV_INIT_EML_IF(0,1,2,376,386,445,558);
        _SFD_CV_INIT_EML_IF(0,1,3,445,460,517,558);
        _SFD_CV_INIT_EML_IF(0,1,4,632,643,850,1078);
        _SFD_CV_INIT_EML_IF(0,1,5,653,681,759,844);
        _SFD_CV_INIT_EML_IF(0,1,6,859,871,966,1074);

        {
          static int condStart[] = { 656, 671 };

          static int condEnd[] = { 667, 681 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,656,681,2,0,&(condStart[0]),&(condEnd[0]),
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
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          real_T *c1_memR;
          real_T *c1_memL;
          real_T *c1_RotationVel;
          real_T *c1_LinearVel;
          real_T *c1_loopm;
          real_T *c1_countm;
          real_T *c1_Right;
          real_T *c1_Left;
          real_T *c1_loop;
          real_T *c1_count;
          real_T (*c1_u)[2];
          c1_count = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c1_loop = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c1_Left = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_Right = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_countm = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c1_loopm = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c1_LinearVel = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c1_RotationVel = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c1_u = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 2);
          c1_memL = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_memR = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_memR);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_memL);
          _SFD_SET_DATA_VALUE_PTR(2U, *c1_u);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_RotationVel);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_LinearVel);
          _SFD_SET_DATA_VALUE_PTR(5U, c1_loopm);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_countm);
          _SFD_SET_DATA_VALUE_PTR(7U, c1_Right);
          _SFD_SET_DATA_VALUE_PTR(8U, c1_Left);
          _SFD_SET_DATA_VALUE_PTR(9U, c1_loop);
          _SFD_SET_DATA_VALUE_PTR(10U, c1_count);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _WindowsiCreateMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "wmZL9QGAcgJURPBViSdUJF";
}

static void sf_opaque_initialize_c1_WindowsiCreate(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_WindowsiCreateInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_WindowsiCreate((SFc1_WindowsiCreateInstanceStruct*)
    chartInstanceVar);
  initialize_c1_WindowsiCreate((SFc1_WindowsiCreateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_WindowsiCreate(void *chartInstanceVar)
{
  enable_c1_WindowsiCreate((SFc1_WindowsiCreateInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_WindowsiCreate(void *chartInstanceVar)
{
  disable_c1_WindowsiCreate((SFc1_WindowsiCreateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_WindowsiCreate(void *chartInstanceVar)
{
  sf_c1_WindowsiCreate((SFc1_WindowsiCreateInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_WindowsiCreate(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_WindowsiCreate
    ((SFc1_WindowsiCreateInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_WindowsiCreate();/* state var info */
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

extern void sf_internal_set_sim_state_c1_WindowsiCreate(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_WindowsiCreate();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_WindowsiCreate((SFc1_WindowsiCreateInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_WindowsiCreate(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_WindowsiCreate(S);
}

static void sf_opaque_set_sim_state_c1_WindowsiCreate(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_WindowsiCreate(S, st);
}

static void sf_opaque_terminate_c1_WindowsiCreate(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_WindowsiCreateInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_WindowsiCreate_optimization_info();
    }

    finalize_c1_WindowsiCreate((SFc1_WindowsiCreateInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_WindowsiCreate((SFc1_WindowsiCreateInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_WindowsiCreate(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_WindowsiCreate((SFc1_WindowsiCreateInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_WindowsiCreate(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_WindowsiCreate_optimization_info();
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
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,7);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,4);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 7; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2482016793U));
  ssSetChecksum1(S,(3861783746U));
  ssSetChecksum2(S,(652083099U));
  ssSetChecksum3(S,(214269397U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_WindowsiCreate(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_WindowsiCreate(SimStruct *S)
{
  SFc1_WindowsiCreateInstanceStruct *chartInstance;
  chartInstance = (SFc1_WindowsiCreateInstanceStruct *)utMalloc(sizeof
    (SFc1_WindowsiCreateInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_WindowsiCreateInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_WindowsiCreate;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_WindowsiCreate;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_WindowsiCreate;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_WindowsiCreate;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_WindowsiCreate;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_WindowsiCreate;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_WindowsiCreate;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_WindowsiCreate;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_WindowsiCreate;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_WindowsiCreate;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_WindowsiCreate;
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

void c1_WindowsiCreate_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_WindowsiCreate(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_WindowsiCreate(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_WindowsiCreate(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_WindowsiCreate_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
