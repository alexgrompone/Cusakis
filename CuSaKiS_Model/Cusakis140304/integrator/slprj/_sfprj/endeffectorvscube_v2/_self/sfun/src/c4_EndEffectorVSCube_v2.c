/* Include files */

#include <stddef.h>
#include "blas.h"
#include "EndEffectorVSCube_v2_sfun.h"
#include "c4_EndEffectorVSCube_v2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "EndEffectorVSCube_v2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c4_debug_family_names[38] = { "ma", "mb", "Ia", "Ib", "dt",
  "g", "x_a", "y_a", "vx_a", "vy_a", "w_a", "x_b", "y_b", "vx_b", "vy_b", "w_b",
  "Xcm_a", "Vcm_a", "W_a", "Xcm_b", "Vcm_b", "W_b", "Rbi_a_3", "Xcmc_k",
  "Vcmc_k", "Itot", "Wcmc_k", "nargin", "nargout", "Xcm", "Rbi_a", "ma_mb_Ia_Ib",
  "rcmAB_i", "scma_b", "rcmAB_b", "dx", "Xcmc_ki", "dxcm" };

/* Function Declarations */
static void initialize_c4_EndEffectorVSCube_v2
  (SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void initialize_params_c4_EndEffectorVSCube_v2
  (SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void enable_c4_EndEffectorVSCube_v2
  (SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void disable_c4_EndEffectorVSCube_v2
  (SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_EndEffectorVSCube_v2
  (SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_EndEffectorVSCube_v2
  (SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void set_sim_state_c4_EndEffectorVSCube_v2
  (SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance, const mxArray *c4_st);
static void finalize_c4_EndEffectorVSCube_v2
  (SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void sf_c4_EndEffectorVSCube_v2(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance);
static void c4_chartstep_c4_EndEffectorVSCube_v2
  (SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void initSimStructsc4_EndEffectorVSCube_v2
  (SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void registerMessagesc4_EndEffectorVSCube_v2
  (SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_emlrt_marshallIn(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c4_dxcm, const char_T *c4_identifier, real_T
  c4_y[5]);
static void c4_b_emlrt_marshallIn(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[5]);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_c_emlrt_marshallIn(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c4_dx, const char_T *c4_identifier, real_T
  c4_y[10]);
static void c4_d_emlrt_marshallIn(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[10]);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_e_emlrt_marshallIn(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c4_rcmAB_b, const char_T *c4_identifier, real_T
  c4_y[3]);
static void c4_f_emlrt_marshallIn(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[3]);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_g_emlrt_marshallIn(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_g_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_h_emlrt_marshallIn(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[9]);
static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[29]);
static void c4_eml_scalar_eg(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance);
static real_T c4_inv(SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance,
                     real_T c4_x);
static void c4_eml_warning(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance);
static void c4_b_eml_warning(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, char_T c4_varargin_2[14]);
static void c4_cross(SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance,
                     real_T c4_a[3], real_T c4_b[3], real_T c4_c[3]);
static void c4_i_emlrt_marshallIn(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c4_sprintf, const char_T *c4_identifier, char_T
  c4_y[14]);
static void c4_j_emlrt_marshallIn(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  char_T c4_y[14]);
static const mxArray *c4_h_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_k_emlrt_marshallIn(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_l_emlrt_marshallIn(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_EndEffectorVSCube_v2, const
  char_T *c4_identifier);
static uint8_T c4_m_emlrt_marshallIn(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_EndEffectorVSCube_v2
  (SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_is_active_c4_EndEffectorVSCube_v2 = 0U;
}

static void initialize_params_c4_EndEffectorVSCube_v2
  (SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static void enable_c4_EndEffectorVSCube_v2
  (SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_EndEffectorVSCube_v2
  (SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_EndEffectorVSCube_v2
  (SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c4_EndEffectorVSCube_v2
  (SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  int32_T c4_i0;
  real_T c4_u[5];
  const mxArray *c4_b_y = NULL;
  int32_T c4_i1;
  real_T c4_b_u[10];
  const mxArray *c4_c_y = NULL;
  int32_T c4_i2;
  real_T c4_c_u[5];
  const mxArray *c4_d_y = NULL;
  int32_T c4_i3;
  real_T c4_d_u[3];
  const mxArray *c4_e_y = NULL;
  int32_T c4_i4;
  real_T c4_e_u[3];
  const mxArray *c4_f_y = NULL;
  int32_T c4_i5;
  real_T c4_f_u[3];
  const mxArray *c4_g_y = NULL;
  uint8_T c4_hoistedGlobal;
  uint8_T c4_g_u;
  const mxArray *c4_h_y = NULL;
  real_T (*c4_scma_b)[3];
  real_T (*c4_rcmAB_i)[3];
  real_T (*c4_rcmAB_b)[3];
  real_T (*c4_dxcm)[5];
  real_T (*c4_dx)[10];
  real_T (*c4_Xcmc_ki)[5];
  c4_dxcm = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 6);
  c4_Xcmc_ki = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 5);
  c4_dx = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 4);
  c4_rcmAB_b = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c4_scma_b = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c4_rcmAB_i = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(7), FALSE);
  for (c4_i0 = 0; c4_i0 < 5; c4_i0++) {
    c4_u[c4_i0] = (*c4_Xcmc_ki)[c4_i0];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 5), FALSE);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  for (c4_i1 = 0; c4_i1 < 10; c4_i1++) {
    c4_b_u[c4_i1] = (*c4_dx)[c4_i1];
  }

  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_u, 0, 0U, 1U, 0U, 1, 10), FALSE);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  for (c4_i2 = 0; c4_i2 < 5; c4_i2++) {
    c4_c_u[c4_i2] = (*c4_dxcm)[c4_i2];
  }

  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_c_u, 0, 0U, 1U, 0U, 1, 5), FALSE);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  for (c4_i3 = 0; c4_i3 < 3; c4_i3++) {
    c4_d_u[c4_i3] = (*c4_rcmAB_b)[c4_i3];
  }

  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_d_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c4_y, 3, c4_e_y);
  for (c4_i4 = 0; c4_i4 < 3; c4_i4++) {
    c4_e_u[c4_i4] = (*c4_rcmAB_i)[c4_i4];
  }

  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", c4_e_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c4_y, 4, c4_f_y);
  for (c4_i5 = 0; c4_i5 < 3; c4_i5++) {
    c4_f_u[c4_i5] = (*c4_scma_b)[c4_i5];
  }

  c4_g_y = NULL;
  sf_mex_assign(&c4_g_y, sf_mex_create("y", c4_f_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c4_y, 5, c4_g_y);
  c4_hoistedGlobal = chartInstance->c4_is_active_c4_EndEffectorVSCube_v2;
  c4_g_u = c4_hoistedGlobal;
  c4_h_y = NULL;
  sf_mex_assign(&c4_h_y, sf_mex_create("y", &c4_g_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 6, c4_h_y);
  sf_mex_assign(&c4_st, c4_y, FALSE);
  return c4_st;
}

static void set_sim_state_c4_EndEffectorVSCube_v2
  (SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv0[5];
  int32_T c4_i6;
  real_T c4_dv1[10];
  int32_T c4_i7;
  real_T c4_dv2[5];
  int32_T c4_i8;
  real_T c4_dv3[3];
  int32_T c4_i9;
  real_T c4_dv4[3];
  int32_T c4_i10;
  real_T c4_dv5[3];
  int32_T c4_i11;
  real_T (*c4_Xcmc_ki)[5];
  real_T (*c4_dx)[10];
  real_T (*c4_dxcm)[5];
  real_T (*c4_rcmAB_b)[3];
  real_T (*c4_rcmAB_i)[3];
  real_T (*c4_scma_b)[3];
  c4_dxcm = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 6);
  c4_Xcmc_ki = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 5);
  c4_dx = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 4);
  c4_rcmAB_b = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c4_scma_b = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c4_rcmAB_i = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)),
                      "Xcmc_ki", c4_dv0);
  for (c4_i6 = 0; c4_i6 < 5; c4_i6++) {
    (*c4_Xcmc_ki)[c4_i6] = c4_dv0[c4_i6];
  }

  c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)), "dx",
                        c4_dv1);
  for (c4_i7 = 0; c4_i7 < 10; c4_i7++) {
    (*c4_dx)[c4_i7] = c4_dv1[c4_i7];
  }

  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 2)), "dxcm",
                      c4_dv2);
  for (c4_i8 = 0; c4_i8 < 5; c4_i8++) {
    (*c4_dxcm)[c4_i8] = c4_dv2[c4_i8];
  }

  c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 3)),
                        "rcmAB_b", c4_dv3);
  for (c4_i9 = 0; c4_i9 < 3; c4_i9++) {
    (*c4_rcmAB_b)[c4_i9] = c4_dv3[c4_i9];
  }

  c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 4)),
                        "rcmAB_i", c4_dv4);
  for (c4_i10 = 0; c4_i10 < 3; c4_i10++) {
    (*c4_rcmAB_i)[c4_i10] = c4_dv4[c4_i10];
  }

  c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 5)),
                        "scma_b", c4_dv5);
  for (c4_i11 = 0; c4_i11 < 3; c4_i11++) {
    (*c4_scma_b)[c4_i11] = c4_dv5[c4_i11];
  }

  chartInstance->c4_is_active_c4_EndEffectorVSCube_v2 = c4_l_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 6)),
     "is_active_c4_EndEffectorVSCube_v2");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_EndEffectorVSCube_v2(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_EndEffectorVSCube_v2
  (SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static void sf_c4_EndEffectorVSCube_v2(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance)
{
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i20;
  real_T (*c4_dxcm)[5];
  real_T (*c4_ma_mb_Ia_Ib)[4];
  real_T (*c4_Xcmc_ki)[5];
  real_T (*c4_dx)[10];
  real_T (*c4_Rbi_a)[4];
  real_T (*c4_Xcm)[10];
  real_T (*c4_rcmAB_b)[3];
  real_T (*c4_scma_b)[3];
  real_T (*c4_rcmAB_i)[3];
  c4_dxcm = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 6);
  c4_ma_mb_Ia_Ib = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 2);
  c4_Xcmc_ki = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 5);
  c4_dx = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 4);
  c4_Rbi_a = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
  c4_Xcm = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 0);
  c4_rcmAB_b = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c4_scma_b = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c4_rcmAB_i = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  for (c4_i12 = 0; c4_i12 < 3; c4_i12++) {
    _SFD_DATA_RANGE_CHECK((*c4_rcmAB_i)[c4_i12], 0U);
  }

  for (c4_i13 = 0; c4_i13 < 3; c4_i13++) {
    _SFD_DATA_RANGE_CHECK((*c4_scma_b)[c4_i13], 1U);
  }

  for (c4_i14 = 0; c4_i14 < 3; c4_i14++) {
    _SFD_DATA_RANGE_CHECK((*c4_rcmAB_b)[c4_i14], 2U);
  }

  for (c4_i15 = 0; c4_i15 < 10; c4_i15++) {
    _SFD_DATA_RANGE_CHECK((*c4_Xcm)[c4_i15], 3U);
  }

  for (c4_i16 = 0; c4_i16 < 4; c4_i16++) {
    _SFD_DATA_RANGE_CHECK((*c4_Rbi_a)[c4_i16], 4U);
  }

  for (c4_i17 = 0; c4_i17 < 10; c4_i17++) {
    _SFD_DATA_RANGE_CHECK((*c4_dx)[c4_i17], 5U);
  }

  for (c4_i18 = 0; c4_i18 < 5; c4_i18++) {
    _SFD_DATA_RANGE_CHECK((*c4_Xcmc_ki)[c4_i18], 6U);
  }

  for (c4_i19 = 0; c4_i19 < 4; c4_i19++) {
    _SFD_DATA_RANGE_CHECK((*c4_ma_mb_Ia_Ib)[c4_i19], 7U);
  }

  for (c4_i20 = 0; c4_i20 < 5; c4_i20++) {
    _SFD_DATA_RANGE_CHECK((*c4_dxcm)[c4_i20], 8U);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  c4_chartstep_c4_EndEffectorVSCube_v2(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_EndEffectorVSCube_v2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c4_chartstep_c4_EndEffectorVSCube_v2
  (SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
  int32_T c4_i21;
  real_T c4_Xcm[10];
  int32_T c4_i22;
  real_T c4_Rbi_a[4];
  int32_T c4_i23;
  real_T c4_ma_mb_Ia_Ib[4];
  uint32_T c4_debug_family_var_map[38];
  real_T c4_ma;
  real_T c4_mb;
  real_T c4_Ia;
  real_T c4_Ib;
  real_T c4_dt;
  real_T c4_g;
  real_T c4_x_a;
  real_T c4_y_a;
  real_T c4_vx_a;
  real_T c4_vy_a;
  real_T c4_w_a;
  real_T c4_x_b;
  real_T c4_y_b;
  real_T c4_vx_b;
  real_T c4_vy_b;
  real_T c4_w_b;
  real_T c4_Xcm_a[3];
  real_T c4_Vcm_a[3];
  real_T c4_W_a[3];
  real_T c4_Xcm_b[3];
  real_T c4_Vcm_b[3];
  real_T c4_W_b[3];
  real_T c4_Rbi_a_3[9];
  real_T c4_Xcmc_k[3];
  real_T c4_Vcmc_k[3];
  real_T c4_Itot;
  real_T c4_Wcmc_k[3];
  real_T c4_nargin = 3.0;
  real_T c4_nargout = 6.0;
  real_T c4_rcmAB_i[3];
  real_T c4_scma_b[3];
  real_T c4_rcmAB_b[3];
  real_T c4_dx[10];
  real_T c4_Xcmc_ki[5];
  real_T c4_dxcm[5];
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  real_T c4_b_x_a[3];
  int32_T c4_i28;
  real_T c4_b_vx_a[3];
  int32_T c4_i29;
  real_T c4_dv6[3];
  int32_T c4_i30;
  real_T c4_b_x_b[3];
  int32_T c4_i31;
  real_T c4_b_vx_b[3];
  int32_T c4_i32;
  real_T c4_dv7[3];
  int32_T c4_i33;
  int32_T c4_i34;
  real_T c4_dv8[2];
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
  int32_T c4_i39;
  int32_T c4_i40;
  int32_T c4_i41;
  static real_T c4_dv9[3] = { 0.0, 0.0, 1.0 };

  int32_T c4_i42;
  int32_T c4_i43;
  int32_T c4_i44;
  int32_T c4_i45;
  int32_T c4_i46;
  real_T c4_a[9];
  int32_T c4_i47;
  real_T c4_b[3];
  int32_T c4_i48;
  int32_T c4_i49;
  int32_T c4_i50;
  real_T c4_C[3];
  int32_T c4_i51;
  int32_T c4_i52;
  int32_T c4_i53;
  int32_T c4_i54;
  int32_T c4_i55;
  int32_T c4_i56;
  real_T c4_b_a;
  int32_T c4_i57;
  int32_T c4_i58;
  real_T c4_c_a;
  int32_T c4_i59;
  real_T c4_b_b[3];
  int32_T c4_i60;
  int32_T c4_i61;
  real_T c4_B;
  real_T c4_y;
  real_T c4_b_y;
  int32_T c4_i62;
  real_T c4_d_a;
  int32_T c4_i63;
  int32_T c4_i64;
  real_T c4_e_a;
  int32_T c4_i65;
  int32_T c4_i66;
  int32_T c4_i67;
  real_T c4_b_B;
  real_T c4_c_y;
  real_T c4_d_y;
  int32_T c4_i68;
  real_T c4_f_a;
  int32_T c4_i69;
  int32_T c4_i70;
  real_T c4_g_a;
  int32_T c4_i71;
  int32_T c4_i72;
  real_T c4_h_a;
  int32_T c4_i73;
  int32_T c4_i74;
  real_T c4_i_a;
  int32_T c4_i75;
  real_T c4_c_b[3];
  int32_T c4_i76;
  real_T c4_j_a;
  int32_T c4_i77;
  real_T c4_d_b[3];
  int32_T c4_i78;
  real_T c4_k_a;
  int32_T c4_i79;
  real_T c4_b_Xcm_a[3];
  int32_T c4_i80;
  real_T c4_b_C[3];
  real_T c4_dv10[3];
  int32_T c4_i81;
  real_T c4_b_Xcm_b[3];
  int32_T c4_i82;
  real_T c4_e_b[3];
  int32_T c4_i83;
  real_T c4_b_Xcmc_k[3];
  int32_T c4_i84;
  real_T c4_f_b[3];
  int32_T c4_i85;
  int32_T c4_i86;
  int32_T c4_i87;
  int32_T c4_i88;
  int32_T c4_i89;
  int32_T c4_i90;
  int32_T c4_i91;
  int32_T c4_i92;
  int32_T c4_i93;
  int32_T c4_i94;
  int32_T c4_i95;
  int32_T c4_i96;
  int32_T c4_i97;
  int32_T c4_i98;
  int32_T c4_i99;
  int32_T c4_i100;
  int32_T c4_i101;
  int32_T c4_i102;
  int32_T c4_i103;
  int32_T c4_i104;
  int32_T c4_i105;
  int32_T c4_i106;
  int32_T c4_i107;
  int32_T c4_i108;
  real_T (*c4_b_rcmAB_i)[3];
  real_T (*c4_b_scma_b)[3];
  real_T (*c4_b_rcmAB_b)[3];
  real_T (*c4_b_dx)[10];
  real_T (*c4_b_Xcmc_ki)[5];
  real_T (*c4_b_dxcm)[5];
  real_T (*c4_b_ma_mb_Ia_Ib)[4];
  real_T (*c4_b_Rbi_a)[4];
  real_T (*c4_b_Xcm)[10];
  c4_b_dxcm = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 6);
  c4_b_ma_mb_Ia_Ib = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 2);
  c4_b_Xcmc_ki = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 5);
  c4_b_dx = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 4);
  c4_b_Rbi_a = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
  c4_b_Xcm = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 0);
  c4_b_rcmAB_b = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c4_b_scma_b = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c4_b_rcmAB_i = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  for (c4_i21 = 0; c4_i21 < 10; c4_i21++) {
    c4_Xcm[c4_i21] = (*c4_b_Xcm)[c4_i21];
  }

  for (c4_i22 = 0; c4_i22 < 4; c4_i22++) {
    c4_Rbi_a[c4_i22] = (*c4_b_Rbi_a)[c4_i22];
  }

  for (c4_i23 = 0; c4_i23 < 4; c4_i23++) {
    c4_ma_mb_Ia_Ib[c4_i23] = (*c4_b_ma_mb_Ia_Ib)[c4_i23];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 38U, 38U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_ma, 0U, c4_f_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_mb, 1U, c4_f_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_Ia, 2U, c4_f_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_Ib, 3U, c4_f_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_dt, 4U, c4_f_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_g, 5U, c4_f_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_x_a, 6U, c4_f_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_y_a, 7U, c4_f_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_vx_a, 8U, c4_f_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_vy_a, 9U, c4_f_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_w_a, 10U, c4_f_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_x_b, 11U, c4_f_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_y_b, 12U, c4_f_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_vx_b, 13U, c4_f_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_vy_b, 14U, c4_f_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_w_b, 15U, c4_f_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_Xcm_a, 16U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_Vcm_a, 17U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_W_a, 18U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_Xcm_b, 19U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_Vcm_b, 20U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_W_b, 21U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_Rbi_a_3, 22U, c4_g_sf_marshallOut,
    c4_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_Xcmc_k, 23U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_Vcmc_k, 24U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_Itot, 25U, c4_f_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_Wcmc_k, 26U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 27U, c4_f_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 28U, c4_f_sf_marshallOut,
    c4_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_Xcm, 29U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_Rbi_a, 30U, c4_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_ma_mb_Ia_Ib, 31U, c4_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_rcmAB_i, 32U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_scma_b, 33U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_rcmAB_b, 34U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_dx, 35U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_Xcmc_ki, 36U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_dxcm, 37U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 3);
  c4_ma = c4_ma_mb_Ia_Ib[0];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_mb = c4_ma_mb_Ia_Ib[1];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 5);
  c4_Ia = c4_ma_mb_Ia_Ib[2];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 6);
  c4_Ib = c4_ma_mb_Ia_Ib[3];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 7);
  for (c4_i24 = 0; c4_i24 < 3; c4_i24++) {
    c4_rcmAB_b[c4_i24] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i25 = 0; c4_i25 < 3; c4_i25++) {
    c4_scma_b[c4_i25] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 12);
  c4_dt = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 15);
  for (c4_i26 = 0; c4_i26 < 10; c4_i26++) {
    c4_dx[c4_i26] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 16);
  for (c4_i27 = 0; c4_i27 < 5; c4_i27++) {
    c4_dxcm[c4_i27] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 18);
  c4_g = -0.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 22);
  c4_x_a = c4_Xcm[0];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 23);
  c4_y_a = c4_Xcm[1];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 24);
  c4_vx_a = c4_Xcm[2];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 25);
  c4_vy_a = c4_Xcm[3];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 26);
  c4_w_a = c4_Xcm[4];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 29);
  c4_x_b = c4_Xcm[5];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 30);
  c4_y_b = c4_Xcm[6];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 31);
  c4_vx_b = c4_Xcm[7];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 32);
  c4_vy_b = c4_Xcm[8];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 33);
  c4_w_b = c4_Xcm[9];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 35);
  c4_dx[0] = c4_vx_a;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 36);
  c4_dx[1] = c4_vy_a;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 37);
  c4_dx[2] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 38);
  c4_dx[3] = c4_g;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 39);
  c4_dx[4] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 40);
  c4_dx[5] = c4_vx_b;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 41);
  c4_dx[6] = c4_vy_b;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 42);
  c4_dx[7] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 43);
  c4_dx[8] = c4_g;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 44);
  c4_dx[9] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 51);
  c4_b_x_a[0] = c4_x_a;
  c4_b_x_a[1] = c4_y_a;
  c4_b_x_a[2] = 0.0;
  for (c4_i28 = 0; c4_i28 < 3; c4_i28++) {
    c4_Xcm_a[c4_i28] = c4_b_x_a[c4_i28];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 52);
  c4_b_vx_a[0] = c4_vx_a;
  c4_b_vx_a[1] = c4_vy_a;
  c4_b_vx_a[2] = 0.0;
  for (c4_i29 = 0; c4_i29 < 3; c4_i29++) {
    c4_Vcm_a[c4_i29] = c4_b_vx_a[c4_i29];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 53);
  c4_dv6[0] = 0.0;
  c4_dv6[1] = 0.0;
  c4_dv6[2] = c4_w_a;
  for (c4_i30 = 0; c4_i30 < 3; c4_i30++) {
    c4_W_a[c4_i30] = c4_dv6[c4_i30];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 55);
  c4_b_x_b[0] = c4_x_b;
  c4_b_x_b[1] = c4_y_b;
  c4_b_x_b[2] = 0.0;
  for (c4_i31 = 0; c4_i31 < 3; c4_i31++) {
    c4_Xcm_b[c4_i31] = c4_b_x_b[c4_i31];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 56);
  c4_b_vx_b[0] = c4_vx_b;
  c4_b_vx_b[1] = c4_vy_b;
  c4_b_vx_b[2] = 0.0;
  for (c4_i32 = 0; c4_i32 < 3; c4_i32++) {
    c4_Vcm_b[c4_i32] = c4_b_vx_b[c4_i32];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 57);
  c4_dv7[0] = 0.0;
  c4_dv7[1] = 0.0;
  c4_dv7[2] = c4_w_b;
  for (c4_i33 = 0; c4_i33 < 3; c4_i33++) {
    c4_W_b[c4_i33] = c4_dv7[c4_i33];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 60);
  for (c4_i34 = 0; c4_i34 < 2; c4_i34++) {
    c4_dv8[c4_i34] = 0.0;
  }

  c4_i35 = 0;
  c4_i36 = 0;
  for (c4_i37 = 0; c4_i37 < 2; c4_i37++) {
    for (c4_i38 = 0; c4_i38 < 2; c4_i38++) {
      c4_Rbi_a_3[c4_i38 + c4_i35] = c4_Rbi_a[c4_i38 + c4_i36];
    }

    c4_i35 += 3;
    c4_i36 += 2;
  }

  for (c4_i39 = 0; c4_i39 < 2; c4_i39++) {
    c4_Rbi_a_3[c4_i39 + 6] = c4_dv8[c4_i39];
  }

  c4_i40 = 0;
  for (c4_i41 = 0; c4_i41 < 3; c4_i41++) {
    c4_Rbi_a_3[c4_i40 + 2] = c4_dv9[c4_i41];
    c4_i40 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 62);
  for (c4_i42 = 0; c4_i42 < 3; c4_i42++) {
    c4_rcmAB_i[c4_i42] = c4_Xcm_b[c4_i42] - c4_Xcm_a[c4_i42];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 64);
  c4_i43 = 0;
  for (c4_i44 = 0; c4_i44 < 3; c4_i44++) {
    c4_i45 = 0;
    for (c4_i46 = 0; c4_i46 < 3; c4_i46++) {
      c4_a[c4_i46 + c4_i43] = c4_Rbi_a_3[c4_i45 + c4_i44];
      c4_i45 += 3;
    }

    c4_i43 += 3;
  }

  for (c4_i47 = 0; c4_i47 < 3; c4_i47++) {
    c4_b[c4_i47] = c4_rcmAB_i[c4_i47];
  }

  c4_eml_scalar_eg(chartInstance);
  c4_eml_scalar_eg(chartInstance);
  for (c4_i48 = 0; c4_i48 < 3; c4_i48++) {
    c4_rcmAB_b[c4_i48] = 0.0;
  }

  for (c4_i49 = 0; c4_i49 < 3; c4_i49++) {
    c4_rcmAB_b[c4_i49] = 0.0;
  }

  for (c4_i50 = 0; c4_i50 < 3; c4_i50++) {
    c4_C[c4_i50] = c4_rcmAB_b[c4_i50];
  }

  for (c4_i51 = 0; c4_i51 < 3; c4_i51++) {
    c4_rcmAB_b[c4_i51] = c4_C[c4_i51];
  }

  for (c4_i52 = 0; c4_i52 < 3; c4_i52++) {
    c4_C[c4_i52] = c4_rcmAB_b[c4_i52];
  }

  for (c4_i53 = 0; c4_i53 < 3; c4_i53++) {
    c4_rcmAB_b[c4_i53] = c4_C[c4_i53];
  }

  for (c4_i54 = 0; c4_i54 < 3; c4_i54++) {
    c4_rcmAB_b[c4_i54] = 0.0;
    c4_i55 = 0;
    for (c4_i56 = 0; c4_i56 < 3; c4_i56++) {
      c4_rcmAB_b[c4_i54] += c4_a[c4_i55 + c4_i54] * c4_b[c4_i56];
      c4_i55 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 68);
  c4_b_a = c4_ma;
  for (c4_i57 = 0; c4_i57 < 3; c4_i57++) {
    c4_b[c4_i57] = c4_Xcm_a[c4_i57];
  }

  for (c4_i58 = 0; c4_i58 < 3; c4_i58++) {
    c4_b[c4_i58] *= c4_b_a;
  }

  c4_c_a = c4_mb;
  for (c4_i59 = 0; c4_i59 < 3; c4_i59++) {
    c4_b_b[c4_i59] = c4_Xcm_b[c4_i59];
  }

  for (c4_i60 = 0; c4_i60 < 3; c4_i60++) {
    c4_b_b[c4_i60] *= c4_c_a;
  }

  for (c4_i61 = 0; c4_i61 < 3; c4_i61++) {
    c4_b[c4_i61] += c4_b_b[c4_i61];
  }

  c4_B = c4_ma + c4_mb;
  c4_y = c4_B;
  c4_b_y = c4_y;
  for (c4_i62 = 0; c4_i62 < 3; c4_i62++) {
    c4_Xcmc_k[c4_i62] = c4_b[c4_i62] / c4_b_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 69);
  c4_d_a = c4_ma;
  for (c4_i63 = 0; c4_i63 < 3; c4_i63++) {
    c4_b[c4_i63] = c4_Vcm_a[c4_i63];
  }

  for (c4_i64 = 0; c4_i64 < 3; c4_i64++) {
    c4_b[c4_i64] *= c4_d_a;
  }

  c4_e_a = c4_mb;
  for (c4_i65 = 0; c4_i65 < 3; c4_i65++) {
    c4_b_b[c4_i65] = c4_Vcm_b[c4_i65];
  }

  for (c4_i66 = 0; c4_i66 < 3; c4_i66++) {
    c4_b_b[c4_i66] *= c4_e_a;
  }

  for (c4_i67 = 0; c4_i67 < 3; c4_i67++) {
    c4_b[c4_i67] += c4_b_b[c4_i67];
  }

  c4_b_B = c4_ma + c4_mb;
  c4_c_y = c4_b_B;
  c4_d_y = c4_c_y;
  for (c4_i68 = 0; c4_i68 < 3; c4_i68++) {
    c4_Vcmc_k[c4_i68] = c4_b[c4_i68] / c4_d_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 71);
  c4_Itot = c4_Ia + c4_Ib;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 72);
  c4_f_a = c4_Ia;
  for (c4_i69 = 0; c4_i69 < 3; c4_i69++) {
    c4_b[c4_i69] = c4_W_a[c4_i69];
  }

  for (c4_i70 = 0; c4_i70 < 3; c4_i70++) {
    c4_b[c4_i70] *= c4_f_a;
  }

  c4_g_a = c4_Ib;
  for (c4_i71 = 0; c4_i71 < 3; c4_i71++) {
    c4_b_b[c4_i71] = c4_W_b[c4_i71];
  }

  for (c4_i72 = 0; c4_i72 < 3; c4_i72++) {
    c4_b_b[c4_i72] *= c4_g_a;
  }

  c4_h_a = c4_ma;
  for (c4_i73 = 0; c4_i73 < 3; c4_i73++) {
    c4_C[c4_i73] = c4_Vcm_a[c4_i73];
  }

  for (c4_i74 = 0; c4_i74 < 3; c4_i74++) {
    c4_C[c4_i74] *= c4_h_a;
  }

  c4_i_a = c4_ma;
  for (c4_i75 = 0; c4_i75 < 3; c4_i75++) {
    c4_c_b[c4_i75] = c4_Vcm_b[c4_i75];
  }

  for (c4_i76 = 0; c4_i76 < 3; c4_i76++) {
    c4_c_b[c4_i76] *= c4_i_a;
  }

  c4_j_a = c4_ma + c4_mb;
  for (c4_i77 = 0; c4_i77 < 3; c4_i77++) {
    c4_d_b[c4_i77] = c4_Vcmc_k[c4_i77];
  }

  for (c4_i78 = 0; c4_i78 < 3; c4_i78++) {
    c4_d_b[c4_i78] *= c4_j_a;
  }

  c4_k_a = c4_inv(chartInstance, c4_Itot);
  for (c4_i79 = 0; c4_i79 < 3; c4_i79++) {
    c4_b_Xcm_a[c4_i79] = c4_Xcm_a[c4_i79];
  }

  for (c4_i80 = 0; c4_i80 < 3; c4_i80++) {
    c4_b_C[c4_i80] = c4_C[c4_i80];
  }

  c4_cross(chartInstance, c4_b_Xcm_a, c4_b_C, c4_dv10);
  for (c4_i81 = 0; c4_i81 < 3; c4_i81++) {
    c4_b_Xcm_b[c4_i81] = c4_Xcm_b[c4_i81];
  }

  for (c4_i82 = 0; c4_i82 < 3; c4_i82++) {
    c4_e_b[c4_i82] = c4_c_b[c4_i82];
  }

  c4_cross(chartInstance, c4_b_Xcm_b, c4_e_b, c4_c_b);
  for (c4_i83 = 0; c4_i83 < 3; c4_i83++) {
    c4_b_Xcmc_k[c4_i83] = c4_Xcmc_k[c4_i83];
  }

  for (c4_i84 = 0; c4_i84 < 3; c4_i84++) {
    c4_f_b[c4_i84] = c4_d_b[c4_i84];
  }

  c4_cross(chartInstance, c4_b_Xcmc_k, c4_f_b, c4_C);
  for (c4_i85 = 0; c4_i85 < 3; c4_i85++) {
    c4_b[c4_i85] = (((c4_b[c4_i85] + c4_b_b[c4_i85]) + c4_dv10[c4_i85]) +
                    c4_c_b[c4_i85]) - c4_C[c4_i85];
  }

  for (c4_i86 = 0; c4_i86 < 3; c4_i86++) {
    c4_Wcmc_k[c4_i86] = c4_k_a * c4_b[c4_i86];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 76);
  for (c4_i87 = 0; c4_i87 < 2; c4_i87++) {
    c4_Xcmc_ki[c4_i87] = c4_Xcmc_k[c4_i87];
  }

  for (c4_i88 = 0; c4_i88 < 2; c4_i88++) {
    c4_Xcmc_ki[c4_i88 + 2] = c4_Vcmc_k[c4_i88];
  }

  c4_Xcmc_ki[4] = c4_Wcmc_k[2];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 83);
  c4_i89 = 0;
  for (c4_i90 = 0; c4_i90 < 3; c4_i90++) {
    c4_i91 = 0;
    for (c4_i92 = 0; c4_i92 < 3; c4_i92++) {
      c4_a[c4_i92 + c4_i89] = c4_Rbi_a_3[c4_i91 + c4_i90];
      c4_i91 += 3;
    }

    c4_i89 += 3;
  }

  for (c4_i93 = 0; c4_i93 < 3; c4_i93++) {
    c4_b[c4_i93] = c4_Xcm_a[c4_i93] - c4_Xcmc_k[c4_i93];
  }

  c4_eml_scalar_eg(chartInstance);
  c4_eml_scalar_eg(chartInstance);
  for (c4_i94 = 0; c4_i94 < 3; c4_i94++) {
    c4_scma_b[c4_i94] = 0.0;
  }

  for (c4_i95 = 0; c4_i95 < 3; c4_i95++) {
    c4_scma_b[c4_i95] = 0.0;
  }

  for (c4_i96 = 0; c4_i96 < 3; c4_i96++) {
    c4_C[c4_i96] = c4_scma_b[c4_i96];
  }

  for (c4_i97 = 0; c4_i97 < 3; c4_i97++) {
    c4_scma_b[c4_i97] = c4_C[c4_i97];
  }

  for (c4_i98 = 0; c4_i98 < 3; c4_i98++) {
    c4_C[c4_i98] = c4_scma_b[c4_i98];
  }

  for (c4_i99 = 0; c4_i99 < 3; c4_i99++) {
    c4_scma_b[c4_i99] = c4_C[c4_i99];
  }

  for (c4_i100 = 0; c4_i100 < 3; c4_i100++) {
    c4_scma_b[c4_i100] = 0.0;
    c4_i101 = 0;
    for (c4_i102 = 0; c4_i102 < 3; c4_i102++) {
      c4_scma_b[c4_i100] += c4_a[c4_i101 + c4_i100] * c4_b[c4_i102];
      c4_i101 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 87);
  c4_dxcm[0] = c4_Vcmc_k[0];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 88);
  c4_dxcm[1] = c4_Vcmc_k[1];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 89);
  c4_dxcm[2] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 90);
  c4_dxcm[3] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 91);
  c4_dxcm[4] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -91);
  _SFD_SYMBOL_SCOPE_POP();
  for (c4_i103 = 0; c4_i103 < 3; c4_i103++) {
    (*c4_b_rcmAB_i)[c4_i103] = c4_rcmAB_i[c4_i103];
  }

  for (c4_i104 = 0; c4_i104 < 3; c4_i104++) {
    (*c4_b_scma_b)[c4_i104] = c4_scma_b[c4_i104];
  }

  for (c4_i105 = 0; c4_i105 < 3; c4_i105++) {
    (*c4_b_rcmAB_b)[c4_i105] = c4_rcmAB_b[c4_i105];
  }

  for (c4_i106 = 0; c4_i106 < 10; c4_i106++) {
    (*c4_b_dx)[c4_i106] = c4_dx[c4_i106];
  }

  for (c4_i107 = 0; c4_i107 < 5; c4_i107++) {
    (*c4_b_Xcmc_ki)[c4_i107] = c4_Xcmc_ki[c4_i107];
  }

  for (c4_i108 = 0; c4_i108 < 5; c4_i108++) {
    (*c4_b_dxcm)[c4_i108] = c4_dxcm[c4_i108];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
}

static void initSimStructsc4_EndEffectorVSCube_v2
  (SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static void registerMessagesc4_EndEffectorVSCube_v2
  (SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i109;
  real_T c4_b_inData[5];
  int32_T c4_i110;
  real_T c4_u[5];
  const mxArray *c4_y = NULL;
  SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc4_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i109 = 0; c4_i109 < 5; c4_i109++) {
    c4_b_inData[c4_i109] = (*(real_T (*)[5])c4_inData)[c4_i109];
  }

  for (c4_i110 = 0; c4_i110 < 5; c4_i110++) {
    c4_u[c4_i110] = c4_b_inData[c4_i110];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 5), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_emlrt_marshallIn(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c4_dxcm, const char_T *c4_identifier, real_T
  c4_y[5])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_dxcm), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_dxcm);
}

static void c4_b_emlrt_marshallIn(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[5])
{
  real_T c4_dv11[5];
  int32_T c4_i111;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv11, 1, 0, 0U, 1, 0U, 1, 5);
  for (c4_i111 = 0; c4_i111 < 5; c4_i111++) {
    c4_y[c4_i111] = c4_dv11[c4_i111];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_dxcm;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[5];
  int32_T c4_i112;
  SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc4_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c4_dxcm = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_dxcm), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_dxcm);
  for (c4_i112 = 0; c4_i112 < 5; c4_i112++) {
    (*(real_T (*)[5])c4_outData)[c4_i112] = c4_y[c4_i112];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i113;
  real_T c4_b_inData[10];
  int32_T c4_i114;
  real_T c4_u[10];
  const mxArray *c4_y = NULL;
  SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc4_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i113 = 0; c4_i113 < 10; c4_i113++) {
    c4_b_inData[c4_i113] = (*(real_T (*)[10])c4_inData)[c4_i113];
  }

  for (c4_i114 = 0; c4_i114 < 10; c4_i114++) {
    c4_u[c4_i114] = c4_b_inData[c4_i114];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 10), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_c_emlrt_marshallIn(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c4_dx, const char_T *c4_identifier, real_T
  c4_y[10])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_dx), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_dx);
}

static void c4_d_emlrt_marshallIn(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[10])
{
  real_T c4_dv12[10];
  int32_T c4_i115;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv12, 1, 0, 0U, 1, 0U, 1, 10);
  for (c4_i115 = 0; c4_i115 < 10; c4_i115++) {
    c4_y[c4_i115] = c4_dv12[c4_i115];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_dx;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[10];
  int32_T c4_i116;
  SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc4_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c4_dx = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_dx), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_dx);
  for (c4_i116 = 0; c4_i116 < 10; c4_i116++) {
    (*(real_T (*)[10])c4_outData)[c4_i116] = c4_y[c4_i116];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i117;
  real_T c4_b_inData[3];
  int32_T c4_i118;
  real_T c4_u[3];
  const mxArray *c4_y = NULL;
  SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc4_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i117 = 0; c4_i117 < 3; c4_i117++) {
    c4_b_inData[c4_i117] = (*(real_T (*)[3])c4_inData)[c4_i117];
  }

  for (c4_i118 = 0; c4_i118 < 3; c4_i118++) {
    c4_u[c4_i118] = c4_b_inData[c4_i118];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_e_emlrt_marshallIn(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c4_rcmAB_b, const char_T *c4_identifier, real_T
  c4_y[3])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_rcmAB_b), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_rcmAB_b);
}

static void c4_f_emlrt_marshallIn(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[3])
{
  real_T c4_dv13[3];
  int32_T c4_i119;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv13, 1, 0, 0U, 1, 0U, 1, 3);
  for (c4_i119 = 0; c4_i119 < 3; c4_i119++) {
    c4_y[c4_i119] = c4_dv13[c4_i119];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_rcmAB_b;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[3];
  int32_T c4_i120;
  SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc4_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c4_rcmAB_b = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_rcmAB_b), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_rcmAB_b);
  for (c4_i120 = 0; c4_i120 < 3; c4_i120++) {
    (*(real_T (*)[3])c4_outData)[c4_i120] = c4_y[c4_i120];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i121;
  real_T c4_b_inData[4];
  int32_T c4_i122;
  real_T c4_u[4];
  const mxArray *c4_y = NULL;
  SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc4_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i121 = 0; c4_i121 < 4; c4_i121++) {
    c4_b_inData[c4_i121] = (*(real_T (*)[4])c4_inData)[c4_i121];
  }

  for (c4_i122 = 0; c4_i122 < 4; c4_i122++) {
    c4_u[c4_i122] = c4_b_inData[c4_i122];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i123;
  int32_T c4_i124;
  int32_T c4_i125;
  real_T c4_b_inData[4];
  int32_T c4_i126;
  int32_T c4_i127;
  int32_T c4_i128;
  real_T c4_u[4];
  const mxArray *c4_y = NULL;
  SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc4_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_i123 = 0;
  for (c4_i124 = 0; c4_i124 < 2; c4_i124++) {
    for (c4_i125 = 0; c4_i125 < 2; c4_i125++) {
      c4_b_inData[c4_i125 + c4_i123] = (*(real_T (*)[4])c4_inData)[c4_i125 +
        c4_i123];
    }

    c4_i123 += 2;
  }

  c4_i126 = 0;
  for (c4_i127 = 0; c4_i127 < 2; c4_i127++) {
    for (c4_i128 = 0; c4_i128 < 2; c4_i128++) {
      c4_u[c4_i128 + c4_i126] = c4_b_inData[c4_i128 + c4_i126];
    }

    c4_i126 += 2;
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc4_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real_T c4_g_emlrt_marshallIn(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_nargout;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc4_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c4_nargout = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_g_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i129;
  int32_T c4_i130;
  int32_T c4_i131;
  real_T c4_b_inData[9];
  int32_T c4_i132;
  int32_T c4_i133;
  int32_T c4_i134;
  real_T c4_u[9];
  const mxArray *c4_y = NULL;
  SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc4_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_i129 = 0;
  for (c4_i130 = 0; c4_i130 < 3; c4_i130++) {
    for (c4_i131 = 0; c4_i131 < 3; c4_i131++) {
      c4_b_inData[c4_i131 + c4_i129] = (*(real_T (*)[9])c4_inData)[c4_i131 +
        c4_i129];
    }

    c4_i129 += 3;
  }

  c4_i132 = 0;
  for (c4_i133 = 0; c4_i133 < 3; c4_i133++) {
    for (c4_i134 = 0; c4_i134 < 3; c4_i134++) {
      c4_u[c4_i134 + c4_i132] = c4_b_inData[c4_i134 + c4_i132];
    }

    c4_i132 += 3;
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_h_emlrt_marshallIn(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[9])
{
  real_T c4_dv14[9];
  int32_T c4_i135;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv14, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c4_i135 = 0; c4_i135 < 9; c4_i135++) {
    c4_y[c4_i135] = c4_dv14[c4_i135];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_Rbi_a_3;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[9];
  int32_T c4_i136;
  int32_T c4_i137;
  int32_T c4_i138;
  SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc4_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c4_Rbi_a_3 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_Rbi_a_3), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_Rbi_a_3);
  c4_i136 = 0;
  for (c4_i137 = 0; c4_i137 < 3; c4_i137++) {
    for (c4_i138 = 0; c4_i138 < 3; c4_i138++) {
      (*(real_T (*)[9])c4_outData)[c4_i138 + c4_i136] = c4_y[c4_i138 + c4_i136];
    }

    c4_i136 += 3;
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_EndEffectorVSCube_v2_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo;
  c4_ResolvedFunctionInfo c4_info[29];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i139;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  c4_info_helper(c4_info);
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 29), FALSE);
  for (c4_i139 = 0; c4_i139 < 29; c4_i139++) {
    c4_r0 = &c4_info[c4_i139];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context", "nameCaptureInfo",
                    c4_i139);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name", "nameCaptureInfo", c4_i139);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c4_i139);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved", "nameCaptureInfo",
                    c4_i139);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c4_i139);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c4_i139);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c4_i139);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c4_i139);
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[29])
{
  c4_info[0].context = "";
  c4_info[0].name = "mtimes";
  c4_info[0].dominantType = "double";
  c4_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[0].fileTimeLo = 1289552092U;
  c4_info[0].fileTimeHi = 0U;
  c4_info[0].mFileTimeLo = 0U;
  c4_info[0].mFileTimeHi = 0U;
  c4_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[1].name = "eml_index_class";
  c4_info[1].dominantType = "";
  c4_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c4_info[1].fileTimeLo = 1323202978U;
  c4_info[1].fileTimeHi = 0U;
  c4_info[1].mFileTimeLo = 0U;
  c4_info[1].mFileTimeHi = 0U;
  c4_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[2].name = "eml_scalar_eg";
  c4_info[2].dominantType = "double";
  c4_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c4_info[2].fileTimeLo = 1286851196U;
  c4_info[2].fileTimeHi = 0U;
  c4_info[2].mFileTimeLo = 0U;
  c4_info[2].mFileTimeHi = 0U;
  c4_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[3].name = "eml_xgemm";
  c4_info[3].dominantType = "char";
  c4_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c4_info[3].fileTimeLo = 1299109172U;
  c4_info[3].fileTimeHi = 0U;
  c4_info[3].mFileTimeLo = 0U;
  c4_info[3].mFileTimeHi = 0U;
  c4_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c4_info[4].name = "eml_blas_inline";
  c4_info[4].dominantType = "";
  c4_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c4_info[4].fileTimeLo = 1299109168U;
  c4_info[4].fileTimeHi = 0U;
  c4_info[4].mFileTimeLo = 0U;
  c4_info[4].mFileTimeHi = 0U;
  c4_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c4_info[5].name = "mtimes";
  c4_info[5].dominantType = "double";
  c4_info[5].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[5].fileTimeLo = 1289552092U;
  c4_info[5].fileTimeHi = 0U;
  c4_info[5].mFileTimeLo = 0U;
  c4_info[5].mFileTimeHi = 0U;
  c4_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c4_info[6].name = "eml_index_class";
  c4_info[6].dominantType = "";
  c4_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c4_info[6].fileTimeLo = 1323202978U;
  c4_info[6].fileTimeHi = 0U;
  c4_info[6].mFileTimeLo = 0U;
  c4_info[6].mFileTimeHi = 0U;
  c4_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c4_info[7].name = "eml_scalar_eg";
  c4_info[7].dominantType = "double";
  c4_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c4_info[7].fileTimeLo = 1286851196U;
  c4_info[7].fileTimeHi = 0U;
  c4_info[7].mFileTimeLo = 0U;
  c4_info[7].mFileTimeHi = 0U;
  c4_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c4_info[8].name = "eml_refblas_xgemm";
  c4_info[8].dominantType = "char";
  c4_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c4_info[8].fileTimeLo = 1299109174U;
  c4_info[8].fileTimeHi = 0U;
  c4_info[8].mFileTimeLo = 0U;
  c4_info[8].mFileTimeHi = 0U;
  c4_info[9].context = "";
  c4_info[9].name = "mrdivide";
  c4_info[9].dominantType = "double";
  c4_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c4_info[9].fileTimeLo = 1357983948U;
  c4_info[9].fileTimeHi = 0U;
  c4_info[9].mFileTimeLo = 1319762366U;
  c4_info[9].mFileTimeHi = 0U;
  c4_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c4_info[10].name = "rdivide";
  c4_info[10].dominantType = "double";
  c4_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c4_info[10].fileTimeLo = 1346542788U;
  c4_info[10].fileTimeHi = 0U;
  c4_info[10].mFileTimeLo = 0U;
  c4_info[10].mFileTimeHi = 0U;
  c4_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c4_info[11].name = "eml_scalexp_compatible";
  c4_info[11].dominantType = "double";
  c4_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c4_info[11].fileTimeLo = 1286851196U;
  c4_info[11].fileTimeHi = 0U;
  c4_info[11].mFileTimeLo = 0U;
  c4_info[11].mFileTimeHi = 0U;
  c4_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c4_info[12].name = "eml_div";
  c4_info[12].dominantType = "double";
  c4_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c4_info[12].fileTimeLo = 1313380210U;
  c4_info[12].fileTimeHi = 0U;
  c4_info[12].mFileTimeLo = 0U;
  c4_info[12].mFileTimeHi = 0U;
  c4_info[13].context = "";
  c4_info[13].name = "inv";
  c4_info[13].dominantType = "double";
  c4_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c4_info[13].fileTimeLo = 1305350400U;
  c4_info[13].fileTimeHi = 0U;
  c4_info[13].mFileTimeLo = 0U;
  c4_info[13].mFileTimeHi = 0U;
  c4_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c4_info[14].name = "eml_div";
  c4_info[14].dominantType = "double";
  c4_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c4_info[14].fileTimeLo = 1313380210U;
  c4_info[14].fileTimeHi = 0U;
  c4_info[14].mFileTimeLo = 0U;
  c4_info[14].mFileTimeHi = 0U;
  c4_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c4_info[15].name = "norm";
  c4_info[15].dominantType = "double";
  c4_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c4_info[15].fileTimeLo = 1336554494U;
  c4_info[15].fileTimeHi = 0U;
  c4_info[15].mFileTimeLo = 0U;
  c4_info[15].mFileTimeHi = 0U;
  c4_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c4_info[16].name = "abs";
  c4_info[16].dominantType = "double";
  c4_info[16].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c4_info[16].fileTimeLo = 1343862766U;
  c4_info[16].fileTimeHi = 0U;
  c4_info[16].mFileTimeLo = 0U;
  c4_info[16].mFileTimeHi = 0U;
  c4_info[17].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c4_info[17].name = "eml_scalar_abs";
  c4_info[17].dominantType = "double";
  c4_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c4_info[17].fileTimeLo = 1286851112U;
  c4_info[17].fileTimeHi = 0U;
  c4_info[17].mFileTimeLo = 0U;
  c4_info[17].mFileTimeHi = 0U;
  c4_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c4_info[18].name = "mtimes";
  c4_info[18].dominantType = "double";
  c4_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[18].fileTimeLo = 1289552092U;
  c4_info[18].fileTimeHi = 0U;
  c4_info[18].mFileTimeLo = 0U;
  c4_info[18].mFileTimeHi = 0U;
  c4_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c4_info[19].name = "eml_warning";
  c4_info[19].dominantType = "char";
  c4_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c4_info[19].fileTimeLo = 1286851202U;
  c4_info[19].fileTimeHi = 0U;
  c4_info[19].mFileTimeLo = 0U;
  c4_info[19].mFileTimeHi = 0U;
  c4_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c4_info[20].name = "isnan";
  c4_info[20].dominantType = "double";
  c4_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c4_info[20].fileTimeLo = 1286851160U;
  c4_info[20].fileTimeHi = 0U;
  c4_info[20].mFileTimeLo = 0U;
  c4_info[20].mFileTimeHi = 0U;
  c4_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c4_info[21].name = "eps";
  c4_info[21].dominantType = "char";
  c4_info[21].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c4_info[21].fileTimeLo = 1326760396U;
  c4_info[21].fileTimeHi = 0U;
  c4_info[21].mFileTimeLo = 0U;
  c4_info[21].mFileTimeHi = 0U;
  c4_info[22].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c4_info[22].name = "eml_is_float_class";
  c4_info[22].dominantType = "char";
  c4_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c4_info[22].fileTimeLo = 1286851182U;
  c4_info[22].fileTimeHi = 0U;
  c4_info[22].mFileTimeLo = 0U;
  c4_info[22].mFileTimeHi = 0U;
  c4_info[23].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c4_info[23].name = "eml_eps";
  c4_info[23].dominantType = "char";
  c4_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c4_info[23].fileTimeLo = 1326760396U;
  c4_info[23].fileTimeHi = 0U;
  c4_info[23].mFileTimeLo = 0U;
  c4_info[23].mFileTimeHi = 0U;
  c4_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c4_info[24].name = "eml_float_model";
  c4_info[24].dominantType = "char";
  c4_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c4_info[24].fileTimeLo = 1326760396U;
  c4_info[24].fileTimeHi = 0U;
  c4_info[24].mFileTimeLo = 0U;
  c4_info[24].mFileTimeHi = 0U;
  c4_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c4_info[25].name = "eml_flt2str";
  c4_info[25].dominantType = "double";
  c4_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c4_info[25].fileTimeLo = 1309483596U;
  c4_info[25].fileTimeHi = 0U;
  c4_info[25].mFileTimeLo = 0U;
  c4_info[25].mFileTimeHi = 0U;
  c4_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c4_info[26].name = "char";
  c4_info[26].dominantType = "double";
  c4_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m";
  c4_info[26].fileTimeLo = 1319762368U;
  c4_info[26].fileTimeHi = 0U;
  c4_info[26].mFileTimeLo = 0U;
  c4_info[26].mFileTimeHi = 0U;
  c4_info[27].context = "";
  c4_info[27].name = "cross";
  c4_info[27].dominantType = "double";
  c4_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c4_info[27].fileTimeLo = 1286851242U;
  c4_info[27].fileTimeHi = 0U;
  c4_info[27].mFileTimeLo = 0U;
  c4_info[27].mFileTimeHi = 0U;
  c4_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c4_info[28].name = "mtimes";
  c4_info[28].dominantType = "double";
  c4_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[28].fileTimeLo = 1289552092U;
  c4_info[28].fileTimeHi = 0U;
  c4_info[28].mFileTimeLo = 0U;
  c4_info[28].mFileTimeHi = 0U;
}

static void c4_eml_scalar_eg(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance)
{
}

static real_T c4_inv(SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance,
                     real_T c4_x)
{
  real_T c4_y;
  real_T c4_b_y;
  real_T c4_b_x;
  real_T c4_xinv;
  real_T c4_c_x;
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_n1x;
  real_T c4_f_x;
  real_T c4_g_x;
  real_T c4_h_x;
  real_T c4_n1xinv;
  real_T c4_a;
  real_T c4_b;
  real_T c4_c_y;
  real_T c4_rc;
  real_T c4_i_x;
  boolean_T c4_b_b;
  real_T c4_j_x;
  int32_T c4_i140;
  static char_T c4_cv0[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c4_u[8];
  const mxArray *c4_d_y = NULL;
  real_T c4_b_u;
  const mxArray *c4_e_y = NULL;
  real_T c4_c_u;
  const mxArray *c4_f_y = NULL;
  real_T c4_d_u;
  const mxArray *c4_g_y = NULL;
  char_T c4_str[14];
  int32_T c4_i141;
  char_T c4_b_str[14];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  c4_b_y = c4_x;
  c4_y = 1.0 / c4_b_y;
  c4_b_x = c4_x;
  c4_xinv = c4_y;
  c4_c_x = c4_b_x;
  c4_d_x = c4_c_x;
  c4_e_x = c4_d_x;
  c4_n1x = muDoubleScalarAbs(c4_e_x);
  c4_f_x = c4_xinv;
  c4_g_x = c4_f_x;
  c4_h_x = c4_g_x;
  c4_n1xinv = muDoubleScalarAbs(c4_h_x);
  c4_a = c4_n1x;
  c4_b = c4_n1xinv;
  c4_c_y = c4_a * c4_b;
  c4_rc = 1.0 / c4_c_y;
  guard1 = FALSE;
  guard2 = FALSE;
  if (c4_n1x == 0.0) {
    guard2 = TRUE;
  } else if (c4_n1xinv == 0.0) {
    guard2 = TRUE;
  } else if (c4_rc == 0.0) {
    guard1 = TRUE;
  } else {
    c4_i_x = c4_rc;
    c4_b_b = muDoubleScalarIsNaN(c4_i_x);
    guard3 = FALSE;
    if (c4_b_b) {
      guard3 = TRUE;
    } else {
      if (c4_rc < 2.2204460492503131E-16) {
        guard3 = TRUE;
      }
    }

    if (guard3 == TRUE) {
      c4_j_x = c4_rc;
      for (c4_i140 = 0; c4_i140 < 8; c4_i140++) {
        c4_u[c4_i140] = c4_cv0[c4_i140];
      }

      c4_d_y = NULL;
      sf_mex_assign(&c4_d_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 8),
                    FALSE);
      c4_b_u = 14.0;
      c4_e_y = NULL;
      sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c4_c_u = 6.0;
      c4_f_y = NULL;
      sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c4_d_u = c4_j_x;
      c4_g_y = NULL;
      sf_mex_assign(&c4_g_y, sf_mex_create("y", &c4_d_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c4_i_emlrt_marshallIn(chartInstance, sf_mex_call_debug("sprintf", 1U, 2U,
        14, sf_mex_call_debug("sprintf", 1U, 3U, 14, c4_d_y, 14, c4_e_y, 14,
        c4_f_y), 14, c4_g_y), "sprintf", c4_str);
      for (c4_i141 = 0; c4_i141 < 14; c4_i141++) {
        c4_b_str[c4_i141] = c4_str[c4_i141];
      }

      c4_b_eml_warning(chartInstance, c4_b_str);
    }
  }

  if (guard2 == TRUE) {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    c4_eml_warning(chartInstance);
  }

  return c4_y;
}

static void c4_eml_warning(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance)
{
  int32_T c4_i142;
  static char_T c4_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c4_u[27];
  const mxArray *c4_y = NULL;
  for (c4_i142 = 0; c4_i142 < 27; c4_i142++) {
    c4_u[c4_i142] = c4_varargin_1[c4_i142];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 27), FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c4_y));
}

static void c4_b_eml_warning(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, char_T c4_varargin_2[14])
{
  int32_T c4_i143;
  static char_T c4_varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c4_u[33];
  const mxArray *c4_y = NULL;
  int32_T c4_i144;
  char_T c4_b_u[14];
  const mxArray *c4_b_y = NULL;
  for (c4_i143 = 0; c4_i143 < 33; c4_i143++) {
    c4_u[c4_i143] = c4_varargin_1[c4_i143];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 10, 0U, 1U, 0U, 2, 1, 33), FALSE);
  for (c4_i144 = 0; c4_i144 < 14; c4_i144++) {
    c4_b_u[c4_i144] = c4_varargin_2[c4_i144];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
    14, c4_y, 14, c4_b_y));
}

static void c4_cross(SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance,
                     real_T c4_a[3], real_T c4_b[3], real_T c4_c[3])
{
  real_T c4_b_a;
  real_T c4_b_b;
  real_T c4_y;
  real_T c4_c_a;
  real_T c4_c_b;
  real_T c4_b_y;
  real_T c4_c1;
  real_T c4_d_a;
  real_T c4_d_b;
  real_T c4_c_y;
  real_T c4_e_a;
  real_T c4_e_b;
  real_T c4_d_y;
  real_T c4_c2;
  real_T c4_f_a;
  real_T c4_f_b;
  real_T c4_e_y;
  real_T c4_g_a;
  real_T c4_g_b;
  real_T c4_f_y;
  real_T c4_c3;
  c4_b_a = c4_a[1];
  c4_b_b = c4_b[2];
  c4_y = c4_b_a * c4_b_b;
  c4_c_a = c4_a[2];
  c4_c_b = c4_b[1];
  c4_b_y = c4_c_a * c4_c_b;
  c4_c1 = c4_y - c4_b_y;
  c4_d_a = c4_a[2];
  c4_d_b = c4_b[0];
  c4_c_y = c4_d_a * c4_d_b;
  c4_e_a = c4_a[0];
  c4_e_b = c4_b[2];
  c4_d_y = c4_e_a * c4_e_b;
  c4_c2 = c4_c_y - c4_d_y;
  c4_f_a = c4_a[0];
  c4_f_b = c4_b[1];
  c4_e_y = c4_f_a * c4_f_b;
  c4_g_a = c4_a[1];
  c4_g_b = c4_b[0];
  c4_f_y = c4_g_a * c4_g_b;
  c4_c3 = c4_e_y - c4_f_y;
  c4_c[0] = c4_c1;
  c4_c[1] = c4_c2;
  c4_c[2] = c4_c3;
}

static void c4_i_emlrt_marshallIn(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c4_sprintf, const char_T *c4_identifier, char_T
  c4_y[14])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_sprintf), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_sprintf);
}

static void c4_j_emlrt_marshallIn(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  char_T c4_y[14])
{
  char_T c4_cv1[14];
  int32_T c4_i145;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_cv1, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c4_i145 = 0; c4_i145 < 14; c4_i145++) {
    c4_y[c4_i145] = c4_cv1[c4_i145];
  }

  sf_mex_destroy(&c4_u);
}

static const mxArray *c4_h_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc4_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static int32_T c4_k_emlrt_marshallIn(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i146;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i146, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i146;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc4_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_l_emlrt_marshallIn(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_EndEffectorVSCube_v2, const
  char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_m_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_EndEffectorVSCube_v2), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_EndEffectorVSCube_v2);
  return c4_y;
}

static uint8_T c4_m_emlrt_marshallIn(SFc4_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_EndEffectorVSCube_v2InstanceStruct
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

void sf_c4_EndEffectorVSCube_v2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1880234699U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(479680879U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(528835650U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3074770780U);
}

mxArray *sf_c4_EndEffectorVSCube_v2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Zwjh9nxtouEmxdwCJjIeO");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
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
      pr[0] = (double)(2);
      pr[1] = (double)(2);
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
      pr[0] = (double)(4);
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

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(10);
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
      pr[0] = (double)(5);
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
      pr[0] = (double)(5);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_EndEffectorVSCube_v2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c4_EndEffectorVSCube_v2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[43],T\"Xcmc_ki\",},{M[1],M[31],T\"dx\",},{M[1],M[42],T\"dxcm\",},{M[1],M[39],T\"rcmAB_b\",},{M[1],M[44],T\"rcmAB_i\",},{M[1],M[40],T\"scma_b\",},{M[8],M[0],T\"is_active_c4_EndEffectorVSCube_v2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_EndEffectorVSCube_v2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance;
    chartInstance = (SFc4_EndEffectorVSCube_v2InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _EndEffectorVSCube_v2MachineNumber_,
           4,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"rcmAB_i");
          _SFD_SET_DATA_PROPS(1,2,0,1,"scma_b");
          _SFD_SET_DATA_PROPS(2,2,0,1,"rcmAB_b");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Xcm");
          _SFD_SET_DATA_PROPS(4,1,1,0,"Rbi_a");
          _SFD_SET_DATA_PROPS(5,2,0,1,"dx");
          _SFD_SET_DATA_PROPS(6,2,0,1,"Xcmc_ki");
          _SFD_SET_DATA_PROPS(7,1,1,0,"ma_mb_Ia_Ib");
          _SFD_SET_DATA_PROPS(8,2,0,1,"dxcm");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1338);
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
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)
            c4_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)
            c4_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)
            c4_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)
            c4_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        {
          real_T (*c4_rcmAB_i)[3];
          real_T (*c4_scma_b)[3];
          real_T (*c4_rcmAB_b)[3];
          real_T (*c4_Xcm)[10];
          real_T (*c4_Rbi_a)[4];
          real_T (*c4_dx)[10];
          real_T (*c4_Xcmc_ki)[5];
          real_T (*c4_ma_mb_Ia_Ib)[4];
          real_T (*c4_dxcm)[5];
          c4_dxcm = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 6);
          c4_ma_mb_Ia_Ib = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S,
            2);
          c4_Xcmc_ki = (real_T (*)[5])ssGetOutputPortSignal(chartInstance->S, 5);
          c4_dx = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 4);
          c4_Rbi_a = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
          c4_Xcm = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 0);
          c4_rcmAB_b = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
          c4_scma_b = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c4_rcmAB_i = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c4_rcmAB_i);
          _SFD_SET_DATA_VALUE_PTR(1U, *c4_scma_b);
          _SFD_SET_DATA_VALUE_PTR(2U, *c4_rcmAB_b);
          _SFD_SET_DATA_VALUE_PTR(3U, *c4_Xcm);
          _SFD_SET_DATA_VALUE_PTR(4U, *c4_Rbi_a);
          _SFD_SET_DATA_VALUE_PTR(5U, *c4_dx);
          _SFD_SET_DATA_VALUE_PTR(6U, *c4_Xcmc_ki);
          _SFD_SET_DATA_VALUE_PTR(7U, *c4_ma_mb_Ia_Ib);
          _SFD_SET_DATA_VALUE_PTR(8U, *c4_dxcm);
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
  return "52Mvmm1cYof6QU7RlINbJB";
}

static void sf_opaque_initialize_c4_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_EndEffectorVSCube_v2
    ((SFc4_EndEffectorVSCube_v2InstanceStruct*) chartInstanceVar);
  initialize_c4_EndEffectorVSCube_v2((SFc4_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  enable_c4_EndEffectorVSCube_v2((SFc4_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c4_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  disable_c4_EndEffectorVSCube_v2((SFc4_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  sf_c4_EndEffectorVSCube_v2((SFc4_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_EndEffectorVSCube_v2
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_EndEffectorVSCube_v2
    ((SFc4_EndEffectorVSCube_v2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_EndEffectorVSCube_v2();/* state var info */
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

extern void sf_internal_set_sim_state_c4_EndEffectorVSCube_v2(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_EndEffectorVSCube_v2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_EndEffectorVSCube_v2((SFc4_EndEffectorVSCube_v2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_EndEffectorVSCube_v2(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c4_EndEffectorVSCube_v2(S);
}

static void sf_opaque_set_sim_state_c4_EndEffectorVSCube_v2(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c4_EndEffectorVSCube_v2(S, st);
}

static void sf_opaque_terminate_c4_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_EndEffectorVSCube_v2InstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_EndEffectorVSCube_v2_optimization_info();
    }

    finalize_c4_EndEffectorVSCube_v2((SFc4_EndEffectorVSCube_v2InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_EndEffectorVSCube_v2((SFc4_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_EndEffectorVSCube_v2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_EndEffectorVSCube_v2
      ((SFc4_EndEffectorVSCube_v2InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_EndEffectorVSCube_v2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_EndEffectorVSCube_v2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,4,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,6);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=6; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1917188578U));
  ssSetChecksum1(S,(1489141513U));
  ssSetChecksum2(S,(4147389460U));
  ssSetChecksum3(S,(3742996793U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_EndEffectorVSCube_v2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_EndEffectorVSCube_v2(SimStruct *S)
{
  SFc4_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc4_EndEffectorVSCube_v2InstanceStruct *)utMalloc(sizeof
    (SFc4_EndEffectorVSCube_v2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_EndEffectorVSCube_v2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_EndEffectorVSCube_v2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_EndEffectorVSCube_v2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_EndEffectorVSCube_v2;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c4_EndEffectorVSCube_v2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c4_EndEffectorVSCube_v2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_EndEffectorVSCube_v2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_EndEffectorVSCube_v2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_EndEffectorVSCube_v2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_EndEffectorVSCube_v2;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_EndEffectorVSCube_v2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_EndEffectorVSCube_v2;
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

void c4_EndEffectorVSCube_v2_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_EndEffectorVSCube_v2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_EndEffectorVSCube_v2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_EndEffectorVSCube_v2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_EndEffectorVSCube_v2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
