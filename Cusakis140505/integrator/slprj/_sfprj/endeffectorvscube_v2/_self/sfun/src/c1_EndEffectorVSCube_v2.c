/* Include files */

#include <stddef.h>
#include "blas.h"
#include "EndEffectorVSCube_v2_sfun.h"
#include "c1_EndEffectorVSCube_v2.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "EndEffectorVSCube_v2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[36] = { "ma", "mb", "Ia", "Ib", "xyA",
  "dxyA", "wA", "xyB", "dxyB", "wB", "rcm_tot", "vcm_tot", "wcm_tot", "Rbi_a_3",
  "scma_i", "xya", "dxya", "wa", "rcmAB_i", "xyb", "dxyb", "wb", "nargin",
  "nargout", "scma_b", "rcmAB_b", "Xcm", "Xcmc_k", "docking", "ma_mb_Ia_Ib",
  "Rbi_a", "Xcm_A", "Xcm_B", "omega_a", "omega_b", "Xcm1" };

/* Function Declarations */
static void initialize_c1_EndEffectorVSCube_v2
  (SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void initialize_params_c1_EndEffectorVSCube_v2
  (SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void enable_c1_EndEffectorVSCube_v2
  (SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void disable_c1_EndEffectorVSCube_v2
  (SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_EndEffectorVSCube_v2
  (SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_EndEffectorVSCube_v2
  (SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void set_sim_state_c1_EndEffectorVSCube_v2
  (SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_EndEffectorVSCube_v2
  (SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void sf_c1_EndEffectorVSCube_v2(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance);
static void c1_chartstep_c1_EndEffectorVSCube_v2
  (SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void initSimStructsc1_EndEffectorVSCube_v2
  (SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void registerMessagesc1_EndEffectorVSCube_v2
  (SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c1_Xcm1, const char_T *c1_identifier, real_T
  c1_y[10]);
static void c1_b_emlrt_marshallIn(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[10]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c1_omega_b, const char_T *c1_identifier);
static real_T c1_d_emlrt_marshallIn(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_e_emlrt_marshallIn(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c1_Xcm_B, const char_T *c1_identifier, real_T
  c1_y[9]);
static void c1_f_emlrt_marshallIn(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[9]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_g_emlrt_marshallIn(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[3]);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_h_emlrt_marshallIn(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[2]);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_i_emlrt_marshallIn(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[9]);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_eml_scalar_eg(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance);
static void c1_b_eml_scalar_eg(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance);
static void c1_cross(SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance,
                     real_T c1_a[3], real_T c1_b[3], real_T c1_c[3]);
static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_j_emlrt_marshallIn(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_k_emlrt_marshallIn(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_EndEffectorVSCube_v2, const
  char_T *c1_identifier);
static uint8_T c1_l_emlrt_marshallIn(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_EndEffectorVSCube_v2
  (SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_EndEffectorVSCube_v2 = 0U;
}

static void initialize_params_c1_EndEffectorVSCube_v2
  (SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static void enable_c1_EndEffectorVSCube_v2
  (SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_EndEffectorVSCube_v2
  (SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_EndEffectorVSCube_v2
  (SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_EndEffectorVSCube_v2
  (SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_u[10];
  const mxArray *c1_b_y = NULL;
  int32_T c1_i1;
  real_T c1_b_u[9];
  const mxArray *c1_c_y = NULL;
  int32_T c1_i2;
  real_T c1_c_u[9];
  const mxArray *c1_d_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_e_u;
  const mxArray *c1_f_y = NULL;
  uint8_T c1_c_hoistedGlobal;
  uint8_T c1_f_u;
  const mxArray *c1_g_y = NULL;
  real_T *c1_omega_a;
  real_T *c1_omega_b;
  real_T (*c1_Xcm_B)[9];
  real_T (*c1_Xcm_A)[9];
  real_T (*c1_Xcm1)[10];
  c1_Xcm1 = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 5);
  c1_omega_b = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_omega_a = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_Xcm_B = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_Xcm_A = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(6), FALSE);
  for (c1_i0 = 0; c1_i0 < 10; c1_i0++) {
    c1_u[c1_i0] = (*c1_Xcm1)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 10), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  for (c1_i1 = 0; c1_i1 < 9; c1_i1++) {
    c1_b_u[c1_i1] = (*c1_Xcm_A)[c1_i1];
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 1, 9), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  for (c1_i2 = 0; c1_i2 < 9; c1_i2++) {
    c1_c_u[c1_i2] = (*c1_Xcm_B)[c1_i2];
  }

  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 1, 9), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_hoistedGlobal = *c1_omega_a;
  c1_d_u = c1_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_b_hoistedGlobal = *c1_omega_b;
  c1_e_u = c1_b_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_c_hoistedGlobal = chartInstance->c1_is_active_c1_EndEffectorVSCube_v2;
  c1_f_u = c1_c_hoistedGlobal;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_f_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 5, c1_g_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_EndEffectorVSCube_v2
  (SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[10];
  int32_T c1_i3;
  real_T c1_dv1[9];
  int32_T c1_i4;
  real_T c1_dv2[9];
  int32_T c1_i5;
  real_T *c1_omega_a;
  real_T *c1_omega_b;
  real_T (*c1_Xcm1)[10];
  real_T (*c1_Xcm_A)[9];
  real_T (*c1_Xcm_B)[9];
  c1_Xcm1 = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 5);
  c1_omega_b = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_omega_a = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_Xcm_B = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_Xcm_A = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)), "Xcm1",
                      c1_dv0);
  for (c1_i3 = 0; c1_i3 < 10; c1_i3++) {
    (*c1_Xcm1)[c1_i3] = c1_dv0[c1_i3];
  }

  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
                        "Xcm_A", c1_dv1);
  for (c1_i4 = 0; c1_i4 < 9; c1_i4++) {
    (*c1_Xcm_A)[c1_i4] = c1_dv1[c1_i4];
  }

  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
                        "Xcm_B", c1_dv2);
  for (c1_i5 = 0; c1_i5 < 9; c1_i5++) {
    (*c1_Xcm_B)[c1_i5] = c1_dv2[c1_i5];
  }

  *c1_omega_a = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 3)), "omega_a");
  *c1_omega_b = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 4)), "omega_b");
  chartInstance->c1_is_active_c1_EndEffectorVSCube_v2 = c1_k_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 5)),
     "is_active_c1_EndEffectorVSCube_v2");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_EndEffectorVSCube_v2(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_EndEffectorVSCube_v2
  (SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static void sf_c1_EndEffectorVSCube_v2(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance)
{
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  real_T *c1_omega_a;
  real_T *c1_omega_b;
  real_T *c1_docking;
  real_T (*c1_Rbi_a)[4];
  real_T (*c1_ma_mb_Ia_Ib)[4];
  real_T (*c1_Xcmc_k)[5];
  real_T (*c1_Xcm)[10];
  real_T (*c1_rcmAB_b)[3];
  real_T (*c1_Xcm1)[10];
  real_T (*c1_Xcm_B)[9];
  real_T (*c1_Xcm_A)[9];
  real_T (*c1_scma_b)[3];
  c1_Rbi_a = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 6);
  c1_ma_mb_Ia_Ib = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 5);
  c1_docking = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_Xcmc_k = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 3);
  c1_Xcm = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 2);
  c1_rcmAB_b = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c1_Xcm1 = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 5);
  c1_omega_b = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_omega_a = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_Xcm_B = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_Xcm_A = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_scma_b = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i6 = 0; c1_i6 < 3; c1_i6++) {
    _SFD_DATA_RANGE_CHECK((*c1_scma_b)[c1_i6], 0U);
  }

  for (c1_i7 = 0; c1_i7 < 9; c1_i7++) {
    _SFD_DATA_RANGE_CHECK((*c1_Xcm_A)[c1_i7], 1U);
  }

  for (c1_i8 = 0; c1_i8 < 9; c1_i8++) {
    _SFD_DATA_RANGE_CHECK((*c1_Xcm_B)[c1_i8], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_omega_a, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_omega_b, 4U);
  for (c1_i9 = 0; c1_i9 < 10; c1_i9++) {
    _SFD_DATA_RANGE_CHECK((*c1_Xcm1)[c1_i9], 5U);
  }

  for (c1_i10 = 0; c1_i10 < 3; c1_i10++) {
    _SFD_DATA_RANGE_CHECK((*c1_rcmAB_b)[c1_i10], 6U);
  }

  for (c1_i11 = 0; c1_i11 < 10; c1_i11++) {
    _SFD_DATA_RANGE_CHECK((*c1_Xcm)[c1_i11], 7U);
  }

  for (c1_i12 = 0; c1_i12 < 5; c1_i12++) {
    _SFD_DATA_RANGE_CHECK((*c1_Xcmc_k)[c1_i12], 8U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_docking, 9U);
  for (c1_i13 = 0; c1_i13 < 4; c1_i13++) {
    _SFD_DATA_RANGE_CHECK((*c1_ma_mb_Ia_Ib)[c1_i13], 10U);
  }

  for (c1_i14 = 0; c1_i14 < 4; c1_i14++) {
    _SFD_DATA_RANGE_CHECK((*c1_Rbi_a)[c1_i14], 11U);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_EndEffectorVSCube_v2(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_EndEffectorVSCube_v2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_EndEffectorVSCube_v2
  (SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
  real_T c1_hoistedGlobal;
  int32_T c1_i15;
  real_T c1_scma_b[3];
  int32_T c1_i16;
  real_T c1_rcmAB_b[3];
  int32_T c1_i17;
  real_T c1_Xcm[10];
  int32_T c1_i18;
  real_T c1_Xcmc_k[5];
  real_T c1_docking;
  int32_T c1_i19;
  real_T c1_ma_mb_Ia_Ib[4];
  int32_T c1_i20;
  real_T c1_Rbi_a[4];
  uint32_T c1_debug_family_var_map[36];
  real_T c1_ma;
  real_T c1_mb;
  real_T c1_Ia;
  real_T c1_Ib;
  real_T c1_xyA[2];
  real_T c1_dxyA[2];
  real_T c1_wA;
  real_T c1_xyB[2];
  real_T c1_dxyB[2];
  real_T c1_wB;
  real_T c1_rcm_tot[2];
  real_T c1_vcm_tot[3];
  real_T c1_wcm_tot[3];
  real_T c1_Rbi_a_3[9];
  real_T c1_scma_i[3];
  real_T c1_xya[2];
  real_T c1_dxya[3];
  real_T c1_wa;
  real_T c1_rcmAB_i[3];
  real_T c1_xyb[2];
  real_T c1_dxyb[3];
  real_T c1_wb;
  real_T c1_nargin = 7.0;
  real_T c1_nargout = 5.0;
  real_T c1_Xcm_A[9];
  real_T c1_Xcm_B[9];
  real_T c1_omega_a;
  real_T c1_omega_b;
  real_T c1_Xcm1[10];
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i30;
  int32_T c1_i31;
  real_T c1_dv3[3];
  int32_T c1_i32;
  int32_T c1_i33;
  real_T c1_b[2];
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i40;
  static real_T c1_dv4[3] = { 0.0, 0.0, 1.0 };

  int32_T c1_i41;
  real_T c1_a[9];
  int32_T c1_i42;
  real_T c1_b_b[3];
  int32_T c1_i43;
  int32_T c1_i44;
  int32_T c1_i45;
  real_T c1_C[3];
  int32_T c1_i46;
  int32_T c1_i47;
  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i50;
  int32_T c1_i51;
  int32_T c1_i52;
  real_T c1_b_a[4];
  int32_T c1_i53;
  int32_T c1_i54;
  real_T c1_y[2];
  int32_T c1_i55;
  int32_T c1_i56;
  int32_T c1_i57;
  int32_T c1_i58;
  real_T c1_b_wcm_tot[3];
  int32_T c1_i59;
  real_T c1_b_scma_i[3];
  int32_T c1_i60;
  int32_T c1_i61;
  int32_T c1_i62;
  int32_T c1_i63;
  int32_T c1_i64;
  int32_T c1_i65;
  int32_T c1_i66;
  int32_T c1_i67;
  int32_T c1_i68;
  int32_T c1_i69;
  int32_T c1_i70;
  int32_T c1_i71;
  int32_T c1_i72;
  int32_T c1_i73;
  real_T c1_c_wcm_tot[3];
  int32_T c1_i74;
  real_T c1_b_rcmAB_i[3];
  int32_T c1_i75;
  int32_T c1_i76;
  int32_T c1_i77;
  int32_T c1_i78;
  int32_T c1_i79;
  int32_T c1_i80;
  int32_T c1_i81;
  int32_T c1_i82;
  int32_T c1_i83;
  int32_T c1_i84;
  int32_T c1_i85;
  int32_T c1_i86;
  real_T *c1_b_docking;
  real_T *c1_b_omega_a;
  real_T *c1_b_omega_b;
  real_T (*c1_b_Xcm_A)[9];
  real_T (*c1_b_Xcm_B)[9];
  real_T (*c1_b_Xcm1)[10];
  real_T (*c1_b_Rbi_a)[4];
  real_T (*c1_b_ma_mb_Ia_Ib)[4];
  real_T (*c1_b_Xcmc_k)[5];
  real_T (*c1_b_Xcm)[10];
  real_T (*c1_b_rcmAB_b)[3];
  real_T (*c1_b_scma_b)[3];
  c1_b_Rbi_a = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 6);
  c1_b_ma_mb_Ia_Ib = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 5);
  c1_b_docking = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_b_Xcmc_k = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_Xcm = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_rcmAB_b = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_Xcm1 = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 5);
  c1_b_omega_b = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_b_omega_a = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_b_Xcm_B = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_Xcm_A = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_scma_b = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_docking;
  for (c1_i15 = 0; c1_i15 < 3; c1_i15++) {
    c1_scma_b[c1_i15] = (*c1_b_scma_b)[c1_i15];
  }

  for (c1_i16 = 0; c1_i16 < 3; c1_i16++) {
    c1_rcmAB_b[c1_i16] = (*c1_b_rcmAB_b)[c1_i16];
  }

  for (c1_i17 = 0; c1_i17 < 10; c1_i17++) {
    c1_Xcm[c1_i17] = (*c1_b_Xcm)[c1_i17];
  }

  for (c1_i18 = 0; c1_i18 < 5; c1_i18++) {
    c1_Xcmc_k[c1_i18] = (*c1_b_Xcmc_k)[c1_i18];
  }

  c1_docking = c1_hoistedGlobal;
  for (c1_i19 = 0; c1_i19 < 4; c1_i19++) {
    c1_ma_mb_Ia_Ib[c1_i19] = (*c1_b_ma_mb_Ia_Ib)[c1_i19];
  }

  for (c1_i20 = 0; c1_i20 < 4; c1_i20++) {
    c1_Rbi_a[c1_i20] = (*c1_b_Rbi_a)[c1_i20];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 36U, 36U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ma, 0U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_mb, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_Ia, 2U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_Ib, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_xyA, 4U, c1_h_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_dxyA, 5U, c1_h_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_wA, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_xyB, 7U, c1_h_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_dxyB, 8U, c1_h_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_wB, 9U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_rcm_tot, 10U, c1_h_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_vcm_tot, 11U, c1_g_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_wcm_tot, 12U, c1_g_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Rbi_a_3, 13U, c1_i_sf_marshallOut,
    c1_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_scma_i, 14U, c1_g_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_xya, 15U, c1_h_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_dxya, 16U, c1_g_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_wa, 17U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_rcmAB_i, 18U, c1_g_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_xyb, 19U, c1_h_sf_marshallOut,
    c1_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_dxyb, 20U, c1_g_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_wb, 21U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 22U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 23U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_scma_b, 24U, c1_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_rcmAB_b, 25U, c1_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_Xcm, 26U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_Xcmc_k, 27U, c1_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_docking, 28U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_ma_mb_Ia_Ib, 29U, c1_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_Rbi_a, 30U, c1_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Xcm_A, 31U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Xcm_B, 32U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_omega_a, 33U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_omega_b, 34U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Xcm1, 35U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 2);
  c1_ma = c1_ma_mb_Ia_Ib[0];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  c1_mb = c1_ma_mb_Ia_Ib[1];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_Ia = c1_ma_mb_Ia_Ib[2];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_Ib = c1_ma_mb_Ia_Ib[3];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
  c1_omega_a = c1_Xcm[4];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  c1_omega_b = c1_Xcm[9];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
  for (c1_i21 = 0; c1_i21 < 2; c1_i21++) {
    c1_xyA[c1_i21] = c1_Xcm[c1_i21];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
  for (c1_i22 = 0; c1_i22 < 2; c1_i22++) {
    c1_dxyA[c1_i22] = c1_Xcm[c1_i22 + 2];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
  c1_wA = c1_Xcm[4];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 20);
  for (c1_i23 = 0; c1_i23 < 2; c1_i23++) {
    c1_xyB[c1_i23] = c1_Xcm[c1_i23 + 5];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
  for (c1_i24 = 0; c1_i24 < 2; c1_i24++) {
    c1_dxyB[c1_i24] = c1_Xcm[c1_i24 + 7];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 22);
  c1_wB = c1_Xcm[9];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 25);
  for (c1_i25 = 0; c1_i25 < 2; c1_i25++) {
    c1_Xcm_A[c1_i25] = c1_xyA[c1_i25];
  }

  c1_Xcm_A[2] = 0.0;
  for (c1_i26 = 0; c1_i26 < 2; c1_i26++) {
    c1_Xcm_A[c1_i26 + 3] = c1_dxyA[c1_i26];
  }

  c1_Xcm_A[5] = 0.0;
  c1_Xcm_A[6] = 0.0;
  c1_Xcm_A[7] = 0.0;
  c1_Xcm_A[8] = c1_wA;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 33);
  for (c1_i27 = 0; c1_i27 < 2; c1_i27++) {
    c1_Xcm_B[c1_i27] = c1_xyB[c1_i27];
  }

  c1_Xcm_B[2] = 0.0;
  for (c1_i28 = 0; c1_i28 < 2; c1_i28++) {
    c1_Xcm_B[c1_i28 + 3] = c1_dxyB[c1_i28];
  }

  c1_Xcm_B[5] = 0.0;
  c1_Xcm_B[6] = 0.0;
  c1_Xcm_B[7] = 0.0;
  c1_Xcm_B[8] = c1_wB;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 41);
  for (c1_i29 = 0; c1_i29 < 10; c1_i29++) {
    c1_Xcm1[c1_i29] = c1_Xcm[c1_i29];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 43);
  if (CV_EML_IF(0, 1, 0, c1_docking == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 45);
    for (c1_i30 = 0; c1_i30 < 2; c1_i30++) {
      c1_rcm_tot[c1_i30] = c1_Xcmc_k[c1_i30];
    }

    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 46);
    for (c1_i31 = 0; c1_i31 < 2; c1_i31++) {
      c1_vcm_tot[c1_i31] = c1_Xcmc_k[c1_i31 + 2];
    }

    c1_vcm_tot[2] = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 48);
    c1_dv3[0] = 0.0;
    c1_dv3[1] = 0.0;
    c1_dv3[2] = c1_Xcmc_k[4];
    for (c1_i32 = 0; c1_i32 < 3; c1_i32++) {
      c1_wcm_tot[c1_i32] = c1_dv3[c1_i32];
    }

    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 50);
    for (c1_i33 = 0; c1_i33 < 2; c1_i33++) {
      c1_b[c1_i33] = 0.0;
    }

    c1_i34 = 0;
    c1_i35 = 0;
    for (c1_i36 = 0; c1_i36 < 2; c1_i36++) {
      for (c1_i37 = 0; c1_i37 < 2; c1_i37++) {
        c1_Rbi_a_3[c1_i37 + c1_i34] = c1_Rbi_a[c1_i37 + c1_i35];
      }

      c1_i34 += 3;
      c1_i35 += 2;
    }

    for (c1_i38 = 0; c1_i38 < 2; c1_i38++) {
      c1_Rbi_a_3[c1_i38 + 6] = c1_b[c1_i38];
    }

    c1_i39 = 0;
    for (c1_i40 = 0; c1_i40 < 3; c1_i40++) {
      c1_Rbi_a_3[c1_i39 + 2] = c1_dv4[c1_i40];
      c1_i39 += 3;
    }

    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 52);
    for (c1_i41 = 0; c1_i41 < 9; c1_i41++) {
      c1_a[c1_i41] = c1_Rbi_a_3[c1_i41];
    }

    for (c1_i42 = 0; c1_i42 < 3; c1_i42++) {
      c1_b_b[c1_i42] = c1_scma_b[c1_i42];
    }

    c1_eml_scalar_eg(chartInstance);
    c1_eml_scalar_eg(chartInstance);
    for (c1_i43 = 0; c1_i43 < 3; c1_i43++) {
      c1_scma_i[c1_i43] = 0.0;
    }

    for (c1_i44 = 0; c1_i44 < 3; c1_i44++) {
      c1_scma_i[c1_i44] = 0.0;
    }

    for (c1_i45 = 0; c1_i45 < 3; c1_i45++) {
      c1_C[c1_i45] = c1_scma_i[c1_i45];
    }

    for (c1_i46 = 0; c1_i46 < 3; c1_i46++) {
      c1_scma_i[c1_i46] = c1_C[c1_i46];
    }

    for (c1_i47 = 0; c1_i47 < 3; c1_i47++) {
      c1_C[c1_i47] = c1_scma_i[c1_i47];
    }

    for (c1_i48 = 0; c1_i48 < 3; c1_i48++) {
      c1_scma_i[c1_i48] = c1_C[c1_i48];
    }

    for (c1_i49 = 0; c1_i49 < 3; c1_i49++) {
      c1_scma_i[c1_i49] = 0.0;
      c1_i50 = 0;
      for (c1_i51 = 0; c1_i51 < 3; c1_i51++) {
        c1_scma_i[c1_i49] += c1_a[c1_i50 + c1_i49] * c1_b_b[c1_i51];
        c1_i50 += 3;
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 55);
    for (c1_i52 = 0; c1_i52 < 4; c1_i52++) {
      c1_b_a[c1_i52] = c1_Rbi_a[c1_i52];
    }

    for (c1_i53 = 0; c1_i53 < 2; c1_i53++) {
      c1_b[c1_i53] = c1_scma_b[c1_i53];
    }

    c1_b_eml_scalar_eg(chartInstance);
    c1_b_eml_scalar_eg(chartInstance);
    for (c1_i54 = 0; c1_i54 < 2; c1_i54++) {
      c1_y[c1_i54] = 0.0;
      c1_i55 = 0;
      for (c1_i56 = 0; c1_i56 < 2; c1_i56++) {
        c1_y[c1_i54] += c1_b_a[c1_i55 + c1_i54] * c1_b[c1_i56];
        c1_i55 += 2;
      }
    }

    for (c1_i57 = 0; c1_i57 < 2; c1_i57++) {
      c1_xya[c1_i57] = c1_rcm_tot[c1_i57] + c1_y[c1_i57];
    }

    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 56);
    for (c1_i58 = 0; c1_i58 < 3; c1_i58++) {
      c1_b_wcm_tot[c1_i58] = c1_wcm_tot[c1_i58];
    }

    for (c1_i59 = 0; c1_i59 < 3; c1_i59++) {
      c1_b_scma_i[c1_i59] = c1_scma_i[c1_i59];
    }

    c1_cross(chartInstance, c1_b_wcm_tot, c1_b_scma_i, c1_b_b);
    for (c1_i60 = 0; c1_i60 < 3; c1_i60++) {
      c1_dxya[c1_i60] = c1_vcm_tot[c1_i60] + c1_b_b[c1_i60];
    }

    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 57);
    c1_wa = c1_wcm_tot[2];
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 60);
    for (c1_i61 = 0; c1_i61 < 9; c1_i61++) {
      c1_a[c1_i61] = c1_Rbi_a_3[c1_i61];
    }

    for (c1_i62 = 0; c1_i62 < 3; c1_i62++) {
      c1_b_b[c1_i62] = c1_rcmAB_b[c1_i62];
    }

    c1_eml_scalar_eg(chartInstance);
    c1_eml_scalar_eg(chartInstance);
    for (c1_i63 = 0; c1_i63 < 3; c1_i63++) {
      c1_rcmAB_i[c1_i63] = 0.0;
    }

    for (c1_i64 = 0; c1_i64 < 3; c1_i64++) {
      c1_rcmAB_i[c1_i64] = 0.0;
    }

    for (c1_i65 = 0; c1_i65 < 3; c1_i65++) {
      c1_C[c1_i65] = c1_rcmAB_i[c1_i65];
    }

    for (c1_i66 = 0; c1_i66 < 3; c1_i66++) {
      c1_rcmAB_i[c1_i66] = c1_C[c1_i66];
    }

    for (c1_i67 = 0; c1_i67 < 3; c1_i67++) {
      c1_C[c1_i67] = c1_rcmAB_i[c1_i67];
    }

    for (c1_i68 = 0; c1_i68 < 3; c1_i68++) {
      c1_rcmAB_i[c1_i68] = c1_C[c1_i68];
    }

    for (c1_i69 = 0; c1_i69 < 3; c1_i69++) {
      c1_rcmAB_i[c1_i69] = 0.0;
      c1_i70 = 0;
      for (c1_i71 = 0; c1_i71 < 3; c1_i71++) {
        c1_rcmAB_i[c1_i69] += c1_a[c1_i70 + c1_i69] * c1_b_b[c1_i71];
        c1_i70 += 3;
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 61);
    for (c1_i72 = 0; c1_i72 < 2; c1_i72++) {
      c1_xyb[c1_i72] = c1_xya[c1_i72] + c1_rcmAB_i[c1_i72];
    }

    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 62);
    for (c1_i73 = 0; c1_i73 < 3; c1_i73++) {
      c1_c_wcm_tot[c1_i73] = c1_wcm_tot[c1_i73];
    }

    for (c1_i74 = 0; c1_i74 < 3; c1_i74++) {
      c1_b_rcmAB_i[c1_i74] = c1_rcmAB_i[c1_i74];
    }

    c1_cross(chartInstance, c1_c_wcm_tot, c1_b_rcmAB_i, c1_b_b);
    for (c1_i75 = 0; c1_i75 < 3; c1_i75++) {
      c1_dxyb[c1_i75] = c1_dxya[c1_i75] + c1_b_b[c1_i75];
    }

    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 63);
    c1_wb = c1_wa;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 67);
    for (c1_i76 = 0; c1_i76 < 2; c1_i76++) {
      c1_Xcm_A[c1_i76] = c1_xya[c1_i76];
    }

    c1_Xcm_A[2] = 0.0;
    for (c1_i77 = 0; c1_i77 < 3; c1_i77++) {
      c1_Xcm_A[c1_i77 + 3] = c1_dxya[c1_i77];
    }

    c1_Xcm_A[6] = 0.0;
    c1_Xcm_A[7] = 0.0;
    c1_Xcm_A[8] = c1_wa;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 74);
    for (c1_i78 = 0; c1_i78 < 2; c1_i78++) {
      c1_Xcm_B[c1_i78] = c1_xyb[c1_i78];
    }

    c1_Xcm_B[2] = 0.0;
    for (c1_i79 = 0; c1_i79 < 3; c1_i79++) {
      c1_Xcm_B[c1_i79 + 3] = c1_dxyb[c1_i79];
    }

    c1_Xcm_B[6] = 0.0;
    c1_Xcm_B[7] = 0.0;
    c1_Xcm_B[8] = c1_wb;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 81);
    for (c1_i80 = 0; c1_i80 < 2; c1_i80++) {
      c1_Xcm1[c1_i80] = c1_xya[c1_i80];
    }

    for (c1_i81 = 0; c1_i81 < 2; c1_i81++) {
      c1_Xcm1[c1_i81 + 2] = c1_dxya[c1_i81];
    }

    c1_Xcm1[4] = c1_wa;
    for (c1_i82 = 0; c1_i82 < 2; c1_i82++) {
      c1_Xcm1[c1_i82 + 5] = c1_xyb[c1_i82];
    }

    for (c1_i83 = 0; c1_i83 < 2; c1_i83++) {
      c1_Xcm1[c1_i83 + 7] = c1_dxyb[c1_i83];
    }

    c1_Xcm1[9] = c1_wb;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 87);
    c1_omega_a = c1_wa;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 88);
    c1_omega_b = c1_wb;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -88);
  _SFD_SYMBOL_SCOPE_POP();
  for (c1_i84 = 0; c1_i84 < 9; c1_i84++) {
    (*c1_b_Xcm_A)[c1_i84] = c1_Xcm_A[c1_i84];
  }

  for (c1_i85 = 0; c1_i85 < 9; c1_i85++) {
    (*c1_b_Xcm_B)[c1_i85] = c1_Xcm_B[c1_i85];
  }

  *c1_b_omega_a = c1_omega_a;
  *c1_b_omega_b = c1_omega_b;
  for (c1_i86 = 0; c1_i86 < 10; c1_i86++) {
    (*c1_b_Xcm1)[c1_i86] = c1_Xcm1[c1_i86];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_EndEffectorVSCube_v2
  (SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static void registerMessagesc1_EndEffectorVSCube_v2
  (SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i87;
  real_T c1_b_inData[10];
  int32_T c1_i88;
  real_T c1_u[10];
  const mxArray *c1_y = NULL;
  SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i87 = 0; c1_i87 < 10; c1_i87++) {
    c1_b_inData[c1_i87] = (*(real_T (*)[10])c1_inData)[c1_i87];
  }

  for (c1_i88 = 0; c1_i88 < 10; c1_i88++) {
    c1_u[c1_i88] = c1_b_inData[c1_i88];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 10), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c1_Xcm1, const char_T *c1_identifier, real_T
  c1_y[10])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Xcm1), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Xcm1);
}

static void c1_b_emlrt_marshallIn(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[10])
{
  real_T c1_dv5[10];
  int32_T c1_i89;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv5, 1, 0, 0U, 1, 0U, 1, 10);
  for (c1_i89 = 0; c1_i89 < 10; c1_i89++) {
    c1_y[c1_i89] = c1_dv5[c1_i89];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Xcm1;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[10];
  int32_T c1_i90;
  SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c1_Xcm1 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Xcm1), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Xcm1);
  for (c1_i90 = 0; c1_i90 < 10; c1_i90++) {
    (*(real_T (*)[10])c1_outData)[c1_i90] = c1_y[c1_i90];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c1_omega_b, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_omega_b), &c1_thisId);
  sf_mex_destroy(&c1_omega_b);
  return c1_y;
}

static real_T c1_d_emlrt_marshallIn(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_omega_b;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c1_omega_b = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_omega_b), &c1_thisId);
  sf_mex_destroy(&c1_omega_b);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i91;
  real_T c1_b_inData[9];
  int32_T c1_i92;
  real_T c1_u[9];
  const mxArray *c1_y = NULL;
  SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i91 = 0; c1_i91 < 9; c1_i91++) {
    c1_b_inData[c1_i91] = (*(real_T (*)[9])c1_inData)[c1_i91];
  }

  for (c1_i92 = 0; c1_i92 < 9; c1_i92++) {
    c1_u[c1_i92] = c1_b_inData[c1_i92];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 9), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_e_emlrt_marshallIn(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c1_Xcm_B, const char_T *c1_identifier, real_T
  c1_y[9])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Xcm_B), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Xcm_B);
}

static void c1_f_emlrt_marshallIn(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[9])
{
  real_T c1_dv6[9];
  int32_T c1_i93;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv6, 1, 0, 0U, 1, 0U, 1, 9);
  for (c1_i93 = 0; c1_i93 < 9; c1_i93++) {
    c1_y[c1_i93] = c1_dv6[c1_i93];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Xcm_B;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[9];
  int32_T c1_i94;
  SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c1_Xcm_B = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Xcm_B), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Xcm_B);
  for (c1_i94 = 0; c1_i94 < 9; c1_i94++) {
    (*(real_T (*)[9])c1_outData)[c1_i94] = c1_y[c1_i94];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i95;
  int32_T c1_i96;
  int32_T c1_i97;
  real_T c1_b_inData[4];
  int32_T c1_i98;
  int32_T c1_i99;
  int32_T c1_i100;
  real_T c1_u[4];
  const mxArray *c1_y = NULL;
  SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i95 = 0;
  for (c1_i96 = 0; c1_i96 < 2; c1_i96++) {
    for (c1_i97 = 0; c1_i97 < 2; c1_i97++) {
      c1_b_inData[c1_i97 + c1_i95] = (*(real_T (*)[4])c1_inData)[c1_i97 + c1_i95];
    }

    c1_i95 += 2;
  }

  c1_i98 = 0;
  for (c1_i99 = 0; c1_i99 < 2; c1_i99++) {
    for (c1_i100 = 0; c1_i100 < 2; c1_i100++) {
      c1_u[c1_i100 + c1_i98] = c1_b_inData[c1_i100 + c1_i98];
    }

    c1_i98 += 2;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i101;
  real_T c1_b_inData[4];
  int32_T c1_i102;
  real_T c1_u[4];
  const mxArray *c1_y = NULL;
  SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i101 = 0; c1_i101 < 4; c1_i101++) {
    c1_b_inData[c1_i101] = (*(real_T (*)[4])c1_inData)[c1_i101];
  }

  for (c1_i102 = 0; c1_i102 < 4; c1_i102++) {
    c1_u[c1_i102] = c1_b_inData[c1_i102];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i103;
  real_T c1_b_inData[5];
  int32_T c1_i104;
  real_T c1_u[5];
  const mxArray *c1_y = NULL;
  SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i103 = 0; c1_i103 < 5; c1_i103++) {
    c1_b_inData[c1_i103] = (*(real_T (*)[5])c1_inData)[c1_i103];
  }

  for (c1_i104 = 0; c1_i104 < 5; c1_i104++) {
    c1_u[c1_i104] = c1_b_inData[c1_i104];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 5), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i105;
  real_T c1_b_inData[3];
  int32_T c1_i106;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i105 = 0; c1_i105 < 3; c1_i105++) {
    c1_b_inData[c1_i105] = (*(real_T (*)[3])c1_inData)[c1_i105];
  }

  for (c1_i106 = 0; c1_i106 < 3; c1_i106++) {
    c1_u[c1_i106] = c1_b_inData[c1_i106];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_g_emlrt_marshallIn(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[3])
{
  real_T c1_dv7[3];
  int32_T c1_i107;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv7, 1, 0, 0U, 1, 0U, 1, 3);
  for (c1_i107 = 0; c1_i107 < 3; c1_i107++) {
    c1_y[c1_i107] = c1_dv7[c1_i107];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_dxyb;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[3];
  int32_T c1_i108;
  SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c1_dxyb = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_dxyb), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_dxyb);
  for (c1_i108 = 0; c1_i108 < 3; c1_i108++) {
    (*(real_T (*)[3])c1_outData)[c1_i108] = c1_y[c1_i108];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i109;
  real_T c1_b_inData[2];
  int32_T c1_i110;
  real_T c1_u[2];
  const mxArray *c1_y = NULL;
  SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i109 = 0; c1_i109 < 2; c1_i109++) {
    c1_b_inData[c1_i109] = (*(real_T (*)[2])c1_inData)[c1_i109];
  }

  for (c1_i110 = 0; c1_i110 < 2; c1_i110++) {
    c1_u[c1_i110] = c1_b_inData[c1_i110];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_h_emlrt_marshallIn(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[2])
{
  real_T c1_dv8[2];
  int32_T c1_i111;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv8, 1, 0, 0U, 1, 0U, 1, 2);
  for (c1_i111 = 0; c1_i111 < 2; c1_i111++) {
    c1_y[c1_i111] = c1_dv8[c1_i111];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_xyb;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[2];
  int32_T c1_i112;
  SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c1_xyb = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_xyb), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_xyb);
  for (c1_i112 = 0; c1_i112 < 2; c1_i112++) {
    (*(real_T (*)[2])c1_outData)[c1_i112] = c1_y[c1_i112];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i113;
  int32_T c1_i114;
  int32_T c1_i115;
  real_T c1_b_inData[9];
  int32_T c1_i116;
  int32_T c1_i117;
  int32_T c1_i118;
  real_T c1_u[9];
  const mxArray *c1_y = NULL;
  SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i113 = 0;
  for (c1_i114 = 0; c1_i114 < 3; c1_i114++) {
    for (c1_i115 = 0; c1_i115 < 3; c1_i115++) {
      c1_b_inData[c1_i115 + c1_i113] = (*(real_T (*)[9])c1_inData)[c1_i115 +
        c1_i113];
    }

    c1_i113 += 3;
  }

  c1_i116 = 0;
  for (c1_i117 = 0; c1_i117 < 3; c1_i117++) {
    for (c1_i118 = 0; c1_i118 < 3; c1_i118++) {
      c1_u[c1_i118 + c1_i116] = c1_b_inData[c1_i118 + c1_i116];
    }

    c1_i116 += 3;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_i_emlrt_marshallIn(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[9])
{
  real_T c1_dv9[9];
  int32_T c1_i119;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv9, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c1_i119 = 0; c1_i119 < 9; c1_i119++) {
    c1_y[c1_i119] = c1_dv9[c1_i119];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Rbi_a_3;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[9];
  int32_T c1_i120;
  int32_T c1_i121;
  int32_T c1_i122;
  SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c1_Rbi_a_3 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Rbi_a_3), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Rbi_a_3);
  c1_i120 = 0;
  for (c1_i121 = 0; c1_i121 < 3; c1_i121++) {
    for (c1_i122 = 0; c1_i122 < 3; c1_i122++) {
      (*(real_T (*)[9])c1_outData)[c1_i122 + c1_i120] = c1_y[c1_i122 + c1_i120];
    }

    c1_i120 += 3;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_EndEffectorVSCube_v2_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[11];
  c1_ResolvedFunctionInfo (*c1_b_info)[11];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i123;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_b_info = (c1_ResolvedFunctionInfo (*)[11])c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "mtimes";
  (*c1_b_info)[0].dominantType = "double";
  (*c1_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[0].fileTimeLo = 1289552092U;
  (*c1_b_info)[0].fileTimeHi = 0U;
  (*c1_b_info)[0].mFileTimeLo = 0U;
  (*c1_b_info)[0].mFileTimeHi = 0U;
  (*c1_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[1].name = "eml_index_class";
  (*c1_b_info)[1].dominantType = "";
  (*c1_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c1_b_info)[1].fileTimeLo = 1323202978U;
  (*c1_b_info)[1].fileTimeHi = 0U;
  (*c1_b_info)[1].mFileTimeLo = 0U;
  (*c1_b_info)[1].mFileTimeHi = 0U;
  (*c1_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[2].name = "eml_scalar_eg";
  (*c1_b_info)[2].dominantType = "double";
  (*c1_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c1_b_info)[2].fileTimeLo = 1286851196U;
  (*c1_b_info)[2].fileTimeHi = 0U;
  (*c1_b_info)[2].mFileTimeLo = 0U;
  (*c1_b_info)[2].mFileTimeHi = 0U;
  (*c1_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[3].name = "eml_xgemm";
  (*c1_b_info)[3].dominantType = "char";
  (*c1_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c1_b_info)[3].fileTimeLo = 1299109172U;
  (*c1_b_info)[3].fileTimeHi = 0U;
  (*c1_b_info)[3].mFileTimeLo = 0U;
  (*c1_b_info)[3].mFileTimeHi = 0U;
  (*c1_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c1_b_info)[4].name = "eml_blas_inline";
  (*c1_b_info)[4].dominantType = "";
  (*c1_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  (*c1_b_info)[4].fileTimeLo = 1299109168U;
  (*c1_b_info)[4].fileTimeHi = 0U;
  (*c1_b_info)[4].mFileTimeLo = 0U;
  (*c1_b_info)[4].mFileTimeHi = 0U;
  (*c1_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  (*c1_b_info)[5].name = "mtimes";
  (*c1_b_info)[5].dominantType = "double";
  (*c1_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[5].fileTimeLo = 1289552092U;
  (*c1_b_info)[5].fileTimeHi = 0U;
  (*c1_b_info)[5].mFileTimeLo = 0U;
  (*c1_b_info)[5].mFileTimeHi = 0U;
  (*c1_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c1_b_info)[6].name = "eml_index_class";
  (*c1_b_info)[6].dominantType = "";
  (*c1_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c1_b_info)[6].fileTimeLo = 1323202978U;
  (*c1_b_info)[6].fileTimeHi = 0U;
  (*c1_b_info)[6].mFileTimeLo = 0U;
  (*c1_b_info)[6].mFileTimeHi = 0U;
  (*c1_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c1_b_info)[7].name = "eml_scalar_eg";
  (*c1_b_info)[7].dominantType = "double";
  (*c1_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c1_b_info)[7].fileTimeLo = 1286851196U;
  (*c1_b_info)[7].fileTimeHi = 0U;
  (*c1_b_info)[7].mFileTimeLo = 0U;
  (*c1_b_info)[7].mFileTimeHi = 0U;
  (*c1_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c1_b_info)[8].name = "eml_refblas_xgemm";
  (*c1_b_info)[8].dominantType = "char";
  (*c1_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  (*c1_b_info)[8].fileTimeLo = 1299109174U;
  (*c1_b_info)[8].fileTimeHi = 0U;
  (*c1_b_info)[8].mFileTimeLo = 0U;
  (*c1_b_info)[8].mFileTimeHi = 0U;
  (*c1_b_info)[9].context = "";
  (*c1_b_info)[9].name = "cross";
  (*c1_b_info)[9].dominantType = "double";
  (*c1_b_info)[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  (*c1_b_info)[9].fileTimeLo = 1286851242U;
  (*c1_b_info)[9].fileTimeHi = 0U;
  (*c1_b_info)[9].mFileTimeLo = 0U;
  (*c1_b_info)[9].mFileTimeHi = 0U;
  (*c1_b_info)[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  (*c1_b_info)[10].name = "mtimes";
  (*c1_b_info)[10].dominantType = "double";
  (*c1_b_info)[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[10].fileTimeLo = 1289552092U;
  (*c1_b_info)[10].fileTimeHi = 0U;
  (*c1_b_info)[10].mFileTimeLo = 0U;
  (*c1_b_info)[10].mFileTimeHi = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 11), FALSE);
  for (c1_i123 = 0; c1_i123 < 11; c1_i123++) {
    c1_r0 = &c1_info[c1_i123];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i123);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i123);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i123);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i123);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i123);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i123);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i123);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i123);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_eml_scalar_eg(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance)
{
}

static void c1_b_eml_scalar_eg(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance)
{
}

static void c1_cross(SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance,
                     real_T c1_a[3], real_T c1_b[3], real_T c1_c[3])
{
  real_T c1_b_a;
  real_T c1_b_b;
  real_T c1_y;
  real_T c1_c_a;
  real_T c1_c_b;
  real_T c1_b_y;
  real_T c1_c1;
  real_T c1_d_a;
  real_T c1_d_b;
  real_T c1_c_y;
  real_T c1_e_a;
  real_T c1_e_b;
  real_T c1_d_y;
  real_T c1_c2;
  real_T c1_f_a;
  real_T c1_f_b;
  real_T c1_e_y;
  real_T c1_g_a;
  real_T c1_g_b;
  real_T c1_f_y;
  real_T c1_c3;
  c1_b_a = c1_a[1];
  c1_b_b = c1_b[2];
  c1_y = c1_b_a * c1_b_b;
  c1_c_a = c1_a[2];
  c1_c_b = c1_b[1];
  c1_b_y = c1_c_a * c1_c_b;
  c1_c1 = c1_y - c1_b_y;
  c1_d_a = c1_a[2];
  c1_d_b = c1_b[0];
  c1_c_y = c1_d_a * c1_d_b;
  c1_e_a = c1_a[0];
  c1_e_b = c1_b[2];
  c1_d_y = c1_e_a * c1_e_b;
  c1_c2 = c1_c_y - c1_d_y;
  c1_f_a = c1_a[0];
  c1_f_b = c1_b[1];
  c1_e_y = c1_f_a * c1_f_b;
  c1_g_a = c1_a[1];
  c1_g_b = c1_b[0];
  c1_f_y = c1_g_a * c1_g_b;
  c1_c3 = c1_e_y - c1_f_y;
  c1_c[0] = c1_c1;
  c1_c[1] = c1_c2;
  c1_c[2] = c1_c3;
}

static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_j_emlrt_marshallIn(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i124;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i124, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i124;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_k_emlrt_marshallIn(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_EndEffectorVSCube_v2, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_EndEffectorVSCube_v2), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_EndEffectorVSCube_v2);
  return c1_y;
}

static uint8_T c1_l_emlrt_marshallIn(SFc1_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_EndEffectorVSCube_v2InstanceStruct
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

void sf_c1_EndEffectorVSCube_v2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2371137669U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2145331171U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(641662140U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1400409414U);
}

mxArray *sf_c1_EndEffectorVSCube_v2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("zEFfBXs7DgDIHR8btFLu4C");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

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
      pr[0] = (double)(10);
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
      pr[0] = (double)(5);
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
      pr[0] = (double)(4);
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
      pr[0] = (double)(2);
      pr[1] = (double)(2);
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

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(9);
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
      pr[0] = (double)(9);
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
      pr[0] = (double)(10);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_EndEffectorVSCube_v2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_EndEffectorVSCube_v2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[19],T\"Xcm1\",},{M[1],M[5],T\"Xcm_A\",},{M[1],M[6],T\"Xcm_B\",},{M[1],M[8],T\"omega_a\",},{M[1],M[9],T\"omega_b\",},{M[8],M[0],T\"is_active_c1_EndEffectorVSCube_v2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_EndEffectorVSCube_v2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance;
    chartInstance = (SFc1_EndEffectorVSCube_v2InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _EndEffectorVSCube_v2MachineNumber_,
           1,
           1,
           1,
           12,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"scma_b");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Xcm_A");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Xcm_B");
          _SFD_SET_DATA_PROPS(3,2,0,1,"omega_a");
          _SFD_SET_DATA_PROPS(4,2,0,1,"omega_b");
          _SFD_SET_DATA_PROPS(5,2,0,1,"Xcm1");
          _SFD_SET_DATA_PROPS(6,1,1,0,"rcmAB_b");
          _SFD_SET_DATA_PROPS(7,1,1,0,"Xcm");
          _SFD_SET_DATA_PROPS(8,1,1,0,"Xcmc_k");
          _SFD_SET_DATA_PROPS(9,1,1,0,"docking");
          _SFD_SET_DATA_PROPS(10,1,1,0,"ma_mb_Ia_Ib");
          _SFD_SET_DATA_PROPS(11,1,1,0,"Rbi_a");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1411);
        _SFD_CV_INIT_EML_IF(0,1,0,625,641,-1,1409);
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
            1.0,0,0,(MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)
            c1_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)
            c1_c_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c1_omega_a;
          real_T *c1_omega_b;
          real_T *c1_docking;
          real_T (*c1_scma_b)[3];
          real_T (*c1_Xcm_A)[9];
          real_T (*c1_Xcm_B)[9];
          real_T (*c1_Xcm1)[10];
          real_T (*c1_rcmAB_b)[3];
          real_T (*c1_Xcm)[10];
          real_T (*c1_Xcmc_k)[5];
          real_T (*c1_ma_mb_Ia_Ib)[4];
          real_T (*c1_Rbi_a)[4];
          c1_Rbi_a = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 6);
          c1_ma_mb_Ia_Ib = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S,
            5);
          c1_docking = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c1_Xcmc_k = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 3);
          c1_Xcm = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 2);
          c1_rcmAB_b = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c1_Xcm1 = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 5);
          c1_omega_b = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c1_omega_a = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c1_Xcm_B = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
          c1_Xcm_A = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_scma_b = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_scma_b);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_Xcm_A);
          _SFD_SET_DATA_VALUE_PTR(2U, *c1_Xcm_B);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_omega_a);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_omega_b);
          _SFD_SET_DATA_VALUE_PTR(5U, *c1_Xcm1);
          _SFD_SET_DATA_VALUE_PTR(6U, *c1_rcmAB_b);
          _SFD_SET_DATA_VALUE_PTR(7U, *c1_Xcm);
          _SFD_SET_DATA_VALUE_PTR(8U, *c1_Xcmc_k);
          _SFD_SET_DATA_VALUE_PTR(9U, c1_docking);
          _SFD_SET_DATA_VALUE_PTR(10U, *c1_ma_mb_Ia_Ib);
          _SFD_SET_DATA_VALUE_PTR(11U, *c1_Rbi_a);
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
  return "TKz7UhtsYvVT15jCWqRNJF";
}

static void sf_opaque_initialize_c1_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_EndEffectorVSCube_v2
    ((SFc1_EndEffectorVSCube_v2InstanceStruct*) chartInstanceVar);
  initialize_c1_EndEffectorVSCube_v2((SFc1_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  enable_c1_EndEffectorVSCube_v2((SFc1_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  disable_c1_EndEffectorVSCube_v2((SFc1_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  sf_c1_EndEffectorVSCube_v2((SFc1_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_EndEffectorVSCube_v2
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_EndEffectorVSCube_v2
    ((SFc1_EndEffectorVSCube_v2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_EndEffectorVSCube_v2();/* state var info */
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

extern void sf_internal_set_sim_state_c1_EndEffectorVSCube_v2(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_EndEffectorVSCube_v2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_EndEffectorVSCube_v2((SFc1_EndEffectorVSCube_v2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_EndEffectorVSCube_v2(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c1_EndEffectorVSCube_v2(S);
}

static void sf_opaque_set_sim_state_c1_EndEffectorVSCube_v2(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_EndEffectorVSCube_v2(S, st);
}

static void sf_opaque_terminate_c1_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_EndEffectorVSCube_v2InstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_EndEffectorVSCube_v2_optimization_info();
    }

    finalize_c1_EndEffectorVSCube_v2((SFc1_EndEffectorVSCube_v2InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_EndEffectorVSCube_v2((SFc1_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_EndEffectorVSCube_v2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_EndEffectorVSCube_v2
      ((SFc1_EndEffectorVSCube_v2InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_EndEffectorVSCube_v2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_EndEffectorVSCube_v2_optimization_info();
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
        infoStruct,1,5);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=5; ++outPortIdx) {
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
  ssSetChecksum0(S,(2324742892U));
  ssSetChecksum1(S,(3412411300U));
  ssSetChecksum2(S,(713192472U));
  ssSetChecksum3(S,(744784054U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_EndEffectorVSCube_v2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_EndEffectorVSCube_v2(SimStruct *S)
{
  SFc1_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc1_EndEffectorVSCube_v2InstanceStruct *)utMalloc(sizeof
    (SFc1_EndEffectorVSCube_v2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_EndEffectorVSCube_v2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_EndEffectorVSCube_v2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_EndEffectorVSCube_v2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_EndEffectorVSCube_v2;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_EndEffectorVSCube_v2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_EndEffectorVSCube_v2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_EndEffectorVSCube_v2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_EndEffectorVSCube_v2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_EndEffectorVSCube_v2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_EndEffectorVSCube_v2;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_EndEffectorVSCube_v2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_EndEffectorVSCube_v2;
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

void c1_EndEffectorVSCube_v2_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_EndEffectorVSCube_v2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_EndEffectorVSCube_v2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_EndEffectorVSCube_v2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_EndEffectorVSCube_v2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
