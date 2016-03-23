/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CusakisME4901arcs_sfun.h"
#include "c9_CusakisME4901arcs.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CusakisME4901arcs_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c9_debug_family_names[7] = { "nargin", "nargout", "Axes",
  "Buttons", "u", "but", "j" };

/* Function Declarations */
static void initialize_c9_CusakisME4901arcs(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void initialize_params_c9_CusakisME4901arcs
  (SFc9_CusakisME4901arcsInstanceStruct *chartInstance);
static void enable_c9_CusakisME4901arcs(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void disable_c9_CusakisME4901arcs(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void c9_update_debugger_state_c9_CusakisME4901arcs
  (SFc9_CusakisME4901arcsInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_CusakisME4901arcs
  (SFc9_CusakisME4901arcsInstanceStruct *chartInstance);
static void set_sim_state_c9_CusakisME4901arcs
  (SFc9_CusakisME4901arcsInstanceStruct *chartInstance, const mxArray *c9_st);
static void finalize_c9_CusakisME4901arcs(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void sf_c9_CusakisME4901arcs(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void initSimStructsc9_CusakisME4901arcs
  (SFc9_CusakisME4901arcsInstanceStruct *chartInstance);
static void registerMessagesc9_CusakisME4901arcs
  (SFc9_CusakisME4901arcsInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static real_T c9_emlrt_marshallIn(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c9_j, const char_T *c9_identifier);
static real_T c9_b_emlrt_marshallIn(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_c_emlrt_marshallIn(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c9_but, const char_T *c9_identifier, real_T
  c9_y[4]);
static void c9_d_emlrt_marshallIn(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[4]);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_e_emlrt_marshallIn(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c9_u, const char_T *c9_identifier, real_T c9_y
  [2]);
static void c9_f_emlrt_marshallIn(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[2]);
static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_f_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_g_emlrt_marshallIn(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint8_T c9_h_emlrt_marshallIn(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c9_b_is_active_c9_CusakisME4901arcs, const
  char_T *c9_identifier);
static uint8_T c9_i_emlrt_marshallIn(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void init_dsm_address_info(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c9_CusakisME4901arcs(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c9_is_active_c9_CusakisME4901arcs = 0U;
}

static void initialize_params_c9_CusakisME4901arcs
  (SFc9_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static void enable_c9_CusakisME4901arcs(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c9_CusakisME4901arcs(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c9_update_debugger_state_c9_CusakisME4901arcs
  (SFc9_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c9_CusakisME4901arcs
  (SFc9_CusakisME4901arcsInstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  int32_T c9_i0;
  real_T c9_u[4];
  const mxArray *c9_b_y = NULL;
  real_T c9_hoistedGlobal;
  real_T c9_b_u;
  const mxArray *c9_c_y = NULL;
  int32_T c9_i1;
  real_T c9_c_u[2];
  const mxArray *c9_d_y = NULL;
  uint8_T c9_b_hoistedGlobal;
  uint8_T c9_d_u;
  const mxArray *c9_e_y = NULL;
  real_T *c9_j;
  real_T (*c9_e_u)[2];
  real_T (*c9_but)[4];
  c9_j = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_but = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c9_e_u = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellarray(4), FALSE);
  for (c9_i0 = 0; c9_i0 < 4; c9_i0++) {
    c9_u[c9_i0] = (*c9_but)[c9_i0];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_hoistedGlobal = *c9_j;
  c9_b_u = c9_hoistedGlobal;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  for (c9_i1 = 0; c9_i1 < 2; c9_i1++) {
    c9_c_u[c9_i1] = (*c9_e_u)[c9_i1];
  }

  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_c_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_setcell(c9_y, 2, c9_d_y);
  c9_b_hoistedGlobal = chartInstance->c9_is_active_c9_CusakisME4901arcs;
  c9_d_u = c9_b_hoistedGlobal;
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 3, c9_e_y);
  sf_mex_assign(&c9_st, c9_y, FALSE);
  return c9_st;
}

static void set_sim_state_c9_CusakisME4901arcs
  (SFc9_CusakisME4901arcsInstanceStruct *chartInstance, const mxArray *c9_st)
{
  const mxArray *c9_u;
  real_T c9_dv0[4];
  int32_T c9_i2;
  real_T c9_dv1[2];
  int32_T c9_i3;
  real_T *c9_j;
  real_T (*c9_but)[4];
  real_T (*c9_b_u)[2];
  c9_j = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_but = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c9_b_u = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c9_doneDoubleBufferReInit = TRUE;
  c9_u = sf_mex_dup(c9_st);
  c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 0)),
                        "but", c9_dv0);
  for (c9_i2 = 0; c9_i2 < 4; c9_i2++) {
    (*c9_but)[c9_i2] = c9_dv0[c9_i2];
  }

  *c9_j = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 1)),
    "j");
  c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 2)), "u",
                        c9_dv1);
  for (c9_i3 = 0; c9_i3 < 2; c9_i3++) {
    (*c9_b_u)[c9_i3] = c9_dv1[c9_i3];
  }

  chartInstance->c9_is_active_c9_CusakisME4901arcs = c9_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 3)),
     "is_active_c9_CusakisME4901arcs");
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_CusakisME4901arcs(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_CusakisME4901arcs(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
}

static void sf_c9_CusakisME4901arcs(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
  int32_T c9_i4;
  int32_T c9_i5;
  int32_T c9_i6;
  int32_T c9_i7;
  int32_T c9_i8;
  real_T c9_Axes[5];
  int32_T c9_i9;
  boolean_T c9_Buttons[10];
  uint32_T c9_debug_family_var_map[7];
  real_T c9_nargin = 2.0;
  real_T c9_nargout = 3.0;
  real_T c9_u[2];
  real_T c9_but[4];
  real_T c9_j;
  int32_T c9_i10;
  int32_T c9_i11;
  int32_T c9_i12;
  int32_T c9_i13;
  int32_T c9_i14;
  int32_T c9_i15;
  static real_T c9_dv2[4] = { 1.0, 0.0, 0.0, 0.0 };

  int32_T c9_i16;
  static real_T c9_dv3[4] = { 0.0, 1.0, 0.0, 0.0 };

  int32_T c9_i17;
  static real_T c9_dv4[4] = { 0.0, 0.0, 1.0, 0.0 };

  int32_T c9_i18;
  static real_T c9_dv5[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T c9_i19;
  int32_T c9_i20;
  int32_T c9_i21;
  real_T *c9_b_j;
  real_T (*c9_b_u)[2];
  real_T (*c9_b_but)[4];
  boolean_T (*c9_b_Buttons)[10];
  real_T (*c9_b_Axes)[5];
  c9_b_j = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_b_Buttons = (boolean_T (*)[10])ssGetInputPortSignal(chartInstance->S, 1);
  c9_b_Axes = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 0);
  c9_b_but = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c9_b_u = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  for (c9_i4 = 0; c9_i4 < 2; c9_i4++) {
    _SFD_DATA_RANGE_CHECK((*c9_b_u)[c9_i4], 0U);
  }

  for (c9_i5 = 0; c9_i5 < 4; c9_i5++) {
    _SFD_DATA_RANGE_CHECK((*c9_b_but)[c9_i5], 1U);
  }

  for (c9_i6 = 0; c9_i6 < 5; c9_i6++) {
    _SFD_DATA_RANGE_CHECK((*c9_b_Axes)[c9_i6], 2U);
  }

  for (c9_i7 = 0; c9_i7 < 10; c9_i7++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c9_b_Buttons)[c9_i7], 3U);
  }

  _SFD_DATA_RANGE_CHECK(*c9_b_j, 4U);
  chartInstance->c9_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  for (c9_i8 = 0; c9_i8 < 5; c9_i8++) {
    c9_Axes[c9_i8] = (*c9_b_Axes)[c9_i8];
  }

  for (c9_i9 = 0; c9_i9 < 10; c9_i9++) {
    c9_Buttons[c9_i9] = (*c9_b_Buttons)[c9_i9];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c9_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_Axes, 2U, c9_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_Buttons, 3U, c9_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_u, 4U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_but, 5U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_j, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 9);
  if (CV_EML_IF(0, 1, 0, c9_Axes[1] == -1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 11);
    for (c9_i10 = 0; c9_i10 < 2; c9_i10++) {
      c9_u[c9_i10] = 1.0 - (real_T)c9_i10;
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 12);
    if (CV_EML_IF(0, 1, 1, c9_Axes[1] == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 14);
      for (c9_i11 = 0; c9_i11 < 2; c9_i11++) {
        c9_u[c9_i11] = -1.0 + (real_T)c9_i11;
      }
    } else {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 15);
      if (CV_EML_IF(0, 1, 2, c9_Axes[0] == -1.0)) {
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 17);
        for (c9_i12 = 0; c9_i12 < 2; c9_i12++) {
          c9_u[c9_i12] = (real_T)c9_i12;
        }
      } else {
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 18);
        if (CV_EML_IF(0, 1, 3, c9_Axes[0] == 1.0)) {
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 20);
          for (c9_i13 = 0; c9_i13 < 2; c9_i13++) {
            c9_u[c9_i13] = 0.0 - (real_T)c9_i13;
          }
        } else {
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 23);
          for (c9_i14 = 0; c9_i14 < 2; c9_i14++) {
            c9_u[c9_i14] = 0.0;
          }
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 26);
  if (CV_EML_IF(0, 1, 4, (real_T)c9_Buttons[4] == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 27);
    c9_j = 1.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 29);
    if (CV_EML_IF(0, 1, 5, (real_T)c9_Buttons[5] == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 30);
      c9_j = -1.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 32);
      c9_j = 0.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 36);
  if (CV_EML_IF(0, 1, 6, (real_T)c9_Buttons[0] == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 38);
    for (c9_i15 = 0; c9_i15 < 4; c9_i15++) {
      c9_but[c9_i15] = c9_dv2[c9_i15];
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 39);
    if (CV_EML_IF(0, 1, 7, (real_T)c9_Buttons[1] == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 41);
      for (c9_i16 = 0; c9_i16 < 4; c9_i16++) {
        c9_but[c9_i16] = c9_dv3[c9_i16];
      }
    } else {
      _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 42);
      if (CV_EML_IF(0, 1, 8, (real_T)c9_Buttons[2] == 1.0)) {
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 44);
        for (c9_i17 = 0; c9_i17 < 4; c9_i17++) {
          c9_but[c9_i17] = c9_dv4[c9_i17];
        }
      } else {
        _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 45);
        if (CV_EML_IF(0, 1, 9, (real_T)c9_Buttons[3] == 1.0)) {
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 47);
          for (c9_i18 = 0; c9_i18 < 4; c9_i18++) {
            c9_but[c9_i18] = c9_dv5[c9_i18];
          }
        } else {
          _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 50);
          for (c9_i19 = 0; c9_i19 < 4; c9_i19++) {
            c9_but[c9_i19] = 0.0;
          }
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -50);
  _SFD_SYMBOL_SCOPE_POP();
  for (c9_i20 = 0; c9_i20 < 2; c9_i20++) {
    (*c9_b_u)[c9_i20] = c9_u[c9_i20];
  }

  for (c9_i21 = 0; c9_i21 < 4; c9_i21++) {
    (*c9_b_but)[c9_i21] = c9_but[c9_i21];
  }

  *c9_b_j = c9_j;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CusakisME4901arcsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc9_CusakisME4901arcs
  (SFc9_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static void registerMessagesc9_CusakisME4901arcs
  (SFc9_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber)
{
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc9_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static real_T c9_emlrt_marshallIn(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c9_j, const char_T *c9_identifier)
{
  real_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_j), &c9_thisId);
  sf_mex_destroy(&c9_j);
  return c9_y;
}

static real_T c9_b_emlrt_marshallIn(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d0, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_j;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc9_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c9_j = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_j), &c9_thisId);
  sf_mex_destroy(&c9_j);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i22;
  real_T c9_b_inData[4];
  int32_T c9_i23;
  real_T c9_u[4];
  const mxArray *c9_y = NULL;
  SFc9_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc9_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i22 = 0; c9_i22 < 4; c9_i22++) {
    c9_b_inData[c9_i22] = (*(real_T (*)[4])c9_inData)[c9_i22];
  }

  for (c9_i23 = 0; c9_i23 < 4; c9_i23++) {
    c9_u[c9_i23] = c9_b_inData[c9_i23];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static void c9_c_emlrt_marshallIn(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c9_but, const char_T *c9_identifier, real_T
  c9_y[4])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_but), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_but);
}

static void c9_d_emlrt_marshallIn(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[4])
{
  real_T c9_dv6[4];
  int32_T c9_i24;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv6, 1, 0, 0U, 1, 0U, 1, 4);
  for (c9_i24 = 0; c9_i24 < 4; c9_i24++) {
    c9_y[c9_i24] = c9_dv6[c9_i24];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_but;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[4];
  int32_T c9_i25;
  SFc9_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc9_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c9_but = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_but), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_but);
  for (c9_i25 = 0; c9_i25 < 4; c9_i25++) {
    (*(real_T (*)[4])c9_outData)[c9_i25] = c9_y[c9_i25];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i26;
  real_T c9_b_inData[2];
  int32_T c9_i27;
  real_T c9_u[2];
  const mxArray *c9_y = NULL;
  SFc9_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc9_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i26 = 0; c9_i26 < 2; c9_i26++) {
    c9_b_inData[c9_i26] = (*(real_T (*)[2])c9_inData)[c9_i26];
  }

  for (c9_i27 = 0; c9_i27 < 2; c9_i27++) {
    c9_u[c9_i27] = c9_b_inData[c9_i27];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static void c9_e_emlrt_marshallIn(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c9_u, const char_T *c9_identifier, real_T c9_y
  [2])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_u), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_u);
}

static void c9_f_emlrt_marshallIn(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[2])
{
  real_T c9_dv7[2];
  int32_T c9_i28;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv7, 1, 0, 0U, 1, 0U, 1, 2);
  for (c9_i28 = 0; c9_i28 < 2; c9_i28++) {
    c9_y[c9_i28] = c9_dv7[c9_i28];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_u;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[2];
  int32_T c9_i29;
  SFc9_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc9_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c9_u = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_u), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_u);
  for (c9_i29 = 0; c9_i29 < 2; c9_i29++) {
    (*(real_T (*)[2])c9_outData)[c9_i29] = c9_y[c9_i29];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i30;
  boolean_T c9_b_inData[10];
  int32_T c9_i31;
  boolean_T c9_u[10];
  const mxArray *c9_y = NULL;
  SFc9_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc9_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i30 = 0; c9_i30 < 10; c9_i30++) {
    c9_b_inData[c9_i30] = (*(boolean_T (*)[10])c9_inData)[c9_i30];
  }

  for (c9_i31 = 0; c9_i31 < 10; c9_i31++) {
    c9_u[c9_i31] = c9_b_inData[c9_i31];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 11, 0U, 1U, 0U, 1, 10), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i32;
  real_T c9_b_inData[5];
  int32_T c9_i33;
  real_T c9_u[5];
  const mxArray *c9_y = NULL;
  SFc9_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc9_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i32 = 0; c9_i32 < 5; c9_i32++) {
    c9_b_inData[c9_i32] = (*(real_T (*)[5])c9_inData)[c9_i32];
  }

  for (c9_i33 = 0; c9_i33 < 5; c9_i33++) {
    c9_u[c9_i33] = c9_b_inData[c9_i33];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 5), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

const mxArray *sf_c9_CusakisME4901arcs_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  sf_mex_assign(&c9_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c9_nameCaptureInfo;
}

static const mxArray *c9_f_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc9_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static int32_T c9_g_emlrt_marshallIn(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i34;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i34, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i34;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc9_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint8_T c9_h_emlrt_marshallIn(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c9_b_is_active_c9_CusakisME4901arcs, const
  char_T *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_is_active_c9_CusakisME4901arcs), &c9_thisId);
  sf_mex_destroy(&c9_b_is_active_c9_CusakisME4901arcs);
  return c9_y;
}

static uint8_T c9_i_emlrt_marshallIn(SFc9_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void init_dsm_address_info(SFc9_CusakisME4901arcsInstanceStruct
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

void sf_c9_CusakisME4901arcs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(885516569U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(414610246U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2148356569U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2928703295U);
}

mxArray *sf_c9_CusakisME4901arcs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("HZ0vqAZelhjx3fSnYOWjIG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
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
      pr[0] = (double)(10);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
      pr[0] = (double)(4);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c9_CusakisME4901arcs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c9_CusakisME4901arcs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[5],T\"but\",},{M[1],M[10],T\"j\",},{M[1],M[4],T\"u\",},{M[8],M[0],T\"is_active_c9_CusakisME4901arcs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_CusakisME4901arcs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_CusakisME4901arcsInstanceStruct *chartInstance;
    chartInstance = (SFc9_CusakisME4901arcsInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CusakisME4901arcsMachineNumber_,
           9,
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
          init_script_number_translation(_CusakisME4901arcsMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_CusakisME4901arcsMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _CusakisME4901arcsMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"but");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Axes");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Buttons");
          _SFD_SET_DATA_PROPS(4,2,0,1,"j");
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
        _SFD_CV_INIT_EML(0,1,1,10,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,732);
        _SFD_CV_INIT_EML_IF(0,1,0,176,190,212,391);
        _SFD_CV_INIT_EML_IF(0,1,1,212,229,261,391);
        _SFD_CV_INIT_EML_IF(0,1,2,261,280,304,391);
        _SFD_CV_INIT_EML_IF(0,1,3,304,322,349,391);
        _SFD_CV_INIT_EML_IF(0,1,4,393,409,415,468);
        _SFD_CV_INIT_EML_IF(0,1,5,420,436,447,464);
        _SFD_CV_INIT_EML_IF(0,1,6,470,486,519,728);
        _SFD_CV_INIT_EML_IF(0,1,7,519,539,572,728);
        _SFD_CV_INIT_EML_IF(0,1,8,572,592,625,728);
        _SFD_CV_INIT_EML_IF(0,1,9,625,645,678,728);
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
            1.0,0,0,(MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)
            c9_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)
            c9_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);

        {
          real_T *c9_j;
          real_T (*c9_u)[2];
          real_T (*c9_but)[4];
          real_T (*c9_Axes)[5];
          boolean_T (*c9_Buttons)[10];
          c9_j = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c9_Buttons = (boolean_T (*)[10])ssGetInputPortSignal(chartInstance->S,
            1);
          c9_Axes = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 0);
          c9_but = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
          c9_u = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c9_u);
          _SFD_SET_DATA_VALUE_PTR(1U, *c9_but);
          _SFD_SET_DATA_VALUE_PTR(2U, *c9_Axes);
          _SFD_SET_DATA_VALUE_PTR(3U, *c9_Buttons);
          _SFD_SET_DATA_VALUE_PTR(4U, c9_j);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _CusakisME4901arcsMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "K6y7h29thaVbbPI2nWNicH";
}

static void sf_opaque_initialize_c9_CusakisME4901arcs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c9_CusakisME4901arcs((SFc9_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
  initialize_c9_CusakisME4901arcs((SFc9_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c9_CusakisME4901arcs(void *chartInstanceVar)
{
  enable_c9_CusakisME4901arcs((SFc9_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c9_CusakisME4901arcs(void *chartInstanceVar)
{
  disable_c9_CusakisME4901arcs((SFc9_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c9_CusakisME4901arcs(void *chartInstanceVar)
{
  sf_c9_CusakisME4901arcs((SFc9_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c9_CusakisME4901arcs(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c9_CusakisME4901arcs
    ((SFc9_CusakisME4901arcsInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_CusakisME4901arcs();/* state var info */
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

extern void sf_internal_set_sim_state_c9_CusakisME4901arcs(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_CusakisME4901arcs();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_CusakisME4901arcs((SFc9_CusakisME4901arcsInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c9_CusakisME4901arcs(SimStruct* S)
{
  return sf_internal_get_sim_state_c9_CusakisME4901arcs(S);
}

static void sf_opaque_set_sim_state_c9_CusakisME4901arcs(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c9_CusakisME4901arcs(S, st);
}

static void sf_opaque_terminate_c9_CusakisME4901arcs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_CusakisME4901arcsInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CusakisME4901arcs_optimization_info();
    }

    finalize_c9_CusakisME4901arcs((SFc9_CusakisME4901arcsInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_CusakisME4901arcs((SFc9_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_CusakisME4901arcs(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_CusakisME4901arcs((SFc9_CusakisME4901arcsInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_CusakisME4901arcs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CusakisME4901arcs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,9,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,9);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,9,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(705850205U));
  ssSetChecksum1(S,(837732762U));
  ssSetChecksum2(S,(2412611858U));
  ssSetChecksum3(S,(3331960822U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c9_CusakisME4901arcs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_CusakisME4901arcs(SimStruct *S)
{
  SFc9_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc9_CusakisME4901arcsInstanceStruct *)utMalloc(sizeof
    (SFc9_CusakisME4901arcsInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_CusakisME4901arcsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_CusakisME4901arcs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_CusakisME4901arcs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_CusakisME4901arcs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c9_CusakisME4901arcs;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c9_CusakisME4901arcs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_CusakisME4901arcs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_CusakisME4901arcs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_CusakisME4901arcs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_CusakisME4901arcs;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_CusakisME4901arcs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_CusakisME4901arcs;
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

void c9_CusakisME4901arcs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_CusakisME4901arcs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_CusakisME4901arcs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_CusakisME4901arcs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_CusakisME4901arcs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
