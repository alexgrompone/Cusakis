/* Include files */

#include <stddef.h>
#include "blas.h"
#include "EndEffectorVSCube_v2_sfun.h"
#include "c2_EndEffectorVSCube_v2.h"
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
static const char * c2_debug_family_names[29] = { "nargin", "nargout", "epsilon",
  "sigma_dock", "dotsigma_dock", "Rbi_A1", "Rbi_B1", "Xcm_A", "Xcm_B", "mesh_A",
  "mesh_B", "dock_sensA", "dock_sensB", "sigma", "ma_mb_Ia_Ib", "dock_sensA_c",
  "dock_sensB_c", "n_c", "QA_c", "QB_c", "A", "B", "docking", "collision",
  "Vcm_an", "Vcm_bn", "W_an", "W_bn", "j" };

/* Function Declarations */
static void initialize_c2_EndEffectorVSCube_v2
  (SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void initialize_params_c2_EndEffectorVSCube_v2
  (SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void enable_c2_EndEffectorVSCube_v2
  (SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void disable_c2_EndEffectorVSCube_v2
  (SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_EndEffectorVSCube_v2
  (SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_EndEffectorVSCube_v2
  (SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void set_sim_state_c2_EndEffectorVSCube_v2
  (SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance, const mxArray *c2_st);
static void finalize_c2_EndEffectorVSCube_v2
  (SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void sf_c2_EndEffectorVSCube_v2(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance);
static void initSimStructsc2_EndEffectorVSCube_v2
  (SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void registerMessagesc2_EndEffectorVSCube_v2
  (SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c2_j, const char_T *c2_identifier, real_T c2_y
  [3]);
static void c2_b_emlrt_marshallIn(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[3]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c2_collision, const char_T *c2_identifier);
static real_T c2_d_emlrt_marshallIn(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_e_emlrt_marshallIn(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c2_B, const char_T *c2_identifier, real_T c2_y
  [10]);
static void c2_f_emlrt_marshallIn(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[10]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_g_emlrt_marshallIn(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c2_A, const char_T *c2_identifier, real_T c2_y
  [16]);
static void c2_h_emlrt_marshallIn(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[16]);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_i_emlrt_marshallIn(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c2_QB_c, const char_T *c2_identifier, real_T
  c2_y[2]);
static void c2_j_emlrt_marshallIn(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[2]);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[70]);
static void c2_collision_function(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, real_T c2_epsilon, real_T c2_sigma_dock, real_T
  c2_dotsigma_dock, real_T c2_Rbi_A1[4], real_T c2_Rbi_B1[4], real_T c2_Xcm_A[9],
  real_T c2_Xcm_B[9], real_T c2_mesh_A[21], real_T c2_mesh_B[12], real_T
  c2_dock_sensA[3], real_T c2_dock_sensB[3], real_T c2_sigma, real_T
  c2_ma_mb_Ia_Ib[4], real_T c2_dock_sensA_c[2], real_T c2_dock_sensB_c[2],
  real_T c2_n_c[2], real_T c2_QA_c[2], real_T c2_QB_c[2], real_T c2_A[16],
  real_T c2_B[10], real_T *c2_docking, real_T *c2_collision, real_T c2_Vcm_an[3],
  real_T c2_Vcm_bn[3], real_T c2_W_an[3], real_T c2_W_bn[3], real_T c2_j[3]);
static void c2_eml_scalar_eg(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance);
static real_T c2_dot(SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance,
                     real_T c2_a[2], real_T c2_b[2]);
static void c2_b_eml_scalar_eg(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance);
static real_T c2_norm(SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance,
                      real_T c2_x[2]);
static void c2_realmin(SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance);
static void c2_check_forloop_overflow_error
  (SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance, boolean_T c2_overflow);
static void c2_b_check_forloop_overflow_error
  (SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance, boolean_T c2_overflow);
static void c2_cross(SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance,
                     real_T c2_a[3], real_T c2_b[3], real_T c2_c[3]);
static real_T c2_b_norm(SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance,
  real_T c2_x[3]);
static real_T c2_b_dot(SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance,
  real_T c2_a[3], real_T c2_b[3]);
static void c2_c_eml_scalar_eg(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance);
static const mxArray *c2_k_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_k_emlrt_marshallIn(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_l_emlrt_marshallIn(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_EndEffectorVSCube_v2, const
  char_T *c2_identifier);
static uint8_T c2_m_emlrt_marshallIn(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_EndEffectorVSCube_v2
  (SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_EndEffectorVSCube_v2 = 0U;
}

static void initialize_params_c2_EndEffectorVSCube_v2
  (SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static void enable_c2_EndEffectorVSCube_v2
  (SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_EndEffectorVSCube_v2
  (SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_EndEffectorVSCube_v2
  (SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_EndEffectorVSCube_v2
  (SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[16];
  const mxArray *c2_b_y = NULL;
  int32_T c2_i1;
  real_T c2_b_u[10];
  const mxArray *c2_c_y = NULL;
  int32_T c2_i2;
  real_T c2_c_u[2];
  const mxArray *c2_d_y = NULL;
  int32_T c2_i3;
  real_T c2_d_u[2];
  const mxArray *c2_e_y = NULL;
  int32_T c2_i4;
  real_T c2_e_u[3];
  const mxArray *c2_f_y = NULL;
  int32_T c2_i5;
  real_T c2_f_u[3];
  const mxArray *c2_g_y = NULL;
  int32_T c2_i6;
  real_T c2_g_u[3];
  const mxArray *c2_h_y = NULL;
  int32_T c2_i7;
  real_T c2_h_u[3];
  const mxArray *c2_i_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_i_u;
  const mxArray *c2_j_y = NULL;
  int32_T c2_i8;
  real_T c2_j_u[2];
  const mxArray *c2_k_y = NULL;
  int32_T c2_i9;
  real_T c2_k_u[2];
  const mxArray *c2_l_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_l_u;
  const mxArray *c2_m_y = NULL;
  int32_T c2_i10;
  real_T c2_m_u[3];
  const mxArray *c2_n_y = NULL;
  int32_T c2_i11;
  real_T c2_n_u[2];
  const mxArray *c2_o_y = NULL;
  uint8_T c2_c_hoistedGlobal;
  uint8_T c2_o_u;
  const mxArray *c2_p_y = NULL;
  real_T *c2_collision;
  real_T *c2_docking;
  real_T (*c2_n_c)[2];
  real_T (*c2_j)[3];
  real_T (*c2_dock_sensB_c)[2];
  real_T (*c2_dock_sensA_c)[2];
  real_T (*c2_W_bn)[3];
  real_T (*c2_W_an)[3];
  real_T (*c2_Vcm_bn)[3];
  real_T (*c2_Vcm_an)[3];
  real_T (*c2_QB_c)[2];
  real_T (*c2_QA_c)[2];
  real_T (*c2_B)[10];
  real_T (*c2_A)[16];
  c2_j = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 14);
  c2_W_bn = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 13);
  c2_W_an = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 12);
  c2_Vcm_bn = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 11);
  c2_Vcm_an = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 10);
  c2_collision = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c2_docking = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c2_B = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 7);
  c2_A = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 6);
  c2_QB_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 5);
  c2_QA_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 4);
  c2_n_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_dock_sensB_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_dock_sensA_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(15), FALSE);
  for (c2_i0 = 0; c2_i0 < 16; c2_i0++) {
    c2_u[c2_i0] = (*c2_A)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 2, 8), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  for (c2_i1 = 0; c2_i1 < 10; c2_i1++) {
    c2_b_u[c2_i1] = (*c2_B)[c2_i1];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 2, 5),
                FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  for (c2_i2 = 0; c2_i2 < 2; c2_i2++) {
    c2_c_u[c2_i2] = (*c2_QA_c)[c2_i2];
  }

  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  for (c2_i3 = 0; c2_i3 < 2; c2_i3++) {
    c2_d_u[c2_i3] = (*c2_QB_c)[c2_i3];
  }

  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_d_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  for (c2_i4 = 0; c2_i4 < 3; c2_i4++) {
    c2_e_u[c2_i4] = (*c2_Vcm_an)[c2_i4];
  }

  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_e_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  for (c2_i5 = 0; c2_i5 < 3; c2_i5++) {
    c2_f_u[c2_i5] = (*c2_Vcm_bn)[c2_i5];
  }

  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_f_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c2_y, 5, c2_g_y);
  for (c2_i6 = 0; c2_i6 < 3; c2_i6++) {
    c2_g_u[c2_i6] = (*c2_W_an)[c2_i6];
  }

  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", c2_g_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c2_y, 6, c2_h_y);
  for (c2_i7 = 0; c2_i7 < 3; c2_i7++) {
    c2_h_u[c2_i7] = (*c2_W_bn)[c2_i7];
  }

  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_create("y", c2_h_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c2_y, 7, c2_i_y);
  c2_hoistedGlobal = *c2_collision;
  c2_i_u = c2_hoistedGlobal;
  c2_j_y = NULL;
  sf_mex_assign(&c2_j_y, sf_mex_create("y", &c2_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 8, c2_j_y);
  for (c2_i8 = 0; c2_i8 < 2; c2_i8++) {
    c2_j_u[c2_i8] = (*c2_dock_sensA_c)[c2_i8];
  }

  c2_k_y = NULL;
  sf_mex_assign(&c2_k_y, sf_mex_create("y", c2_j_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_setcell(c2_y, 9, c2_k_y);
  for (c2_i9 = 0; c2_i9 < 2; c2_i9++) {
    c2_k_u[c2_i9] = (*c2_dock_sensB_c)[c2_i9];
  }

  c2_l_y = NULL;
  sf_mex_assign(&c2_l_y, sf_mex_create("y", c2_k_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_setcell(c2_y, 10, c2_l_y);
  c2_b_hoistedGlobal = *c2_docking;
  c2_l_u = c2_b_hoistedGlobal;
  c2_m_y = NULL;
  sf_mex_assign(&c2_m_y, sf_mex_create("y", &c2_l_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 11, c2_m_y);
  for (c2_i10 = 0; c2_i10 < 3; c2_i10++) {
    c2_m_u[c2_i10] = (*c2_j)[c2_i10];
  }

  c2_n_y = NULL;
  sf_mex_assign(&c2_n_y, sf_mex_create("y", c2_m_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c2_y, 12, c2_n_y);
  for (c2_i11 = 0; c2_i11 < 2; c2_i11++) {
    c2_n_u[c2_i11] = (*c2_n_c)[c2_i11];
  }

  c2_o_y = NULL;
  sf_mex_assign(&c2_o_y, sf_mex_create("y", c2_n_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_setcell(c2_y, 13, c2_o_y);
  c2_c_hoistedGlobal = chartInstance->c2_is_active_c2_EndEffectorVSCube_v2;
  c2_o_u = c2_c_hoistedGlobal;
  c2_p_y = NULL;
  sf_mex_assign(&c2_p_y, sf_mex_create("y", &c2_o_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 14, c2_p_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_EndEffectorVSCube_v2
  (SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[16];
  int32_T c2_i12;
  real_T c2_dv1[10];
  int32_T c2_i13;
  real_T c2_dv2[2];
  int32_T c2_i14;
  real_T c2_dv3[2];
  int32_T c2_i15;
  real_T c2_dv4[3];
  int32_T c2_i16;
  real_T c2_dv5[3];
  int32_T c2_i17;
  real_T c2_dv6[3];
  int32_T c2_i18;
  real_T c2_dv7[3];
  int32_T c2_i19;
  real_T c2_dv8[2];
  int32_T c2_i20;
  real_T c2_dv9[2];
  int32_T c2_i21;
  real_T c2_dv10[3];
  int32_T c2_i22;
  real_T c2_dv11[2];
  int32_T c2_i23;
  real_T *c2_collision;
  real_T *c2_docking;
  real_T (*c2_A)[16];
  real_T (*c2_B)[10];
  real_T (*c2_QA_c)[2];
  real_T (*c2_QB_c)[2];
  real_T (*c2_Vcm_an)[3];
  real_T (*c2_Vcm_bn)[3];
  real_T (*c2_W_an)[3];
  real_T (*c2_W_bn)[3];
  real_T (*c2_dock_sensA_c)[2];
  real_T (*c2_dock_sensB_c)[2];
  real_T (*c2_j)[3];
  real_T (*c2_n_c)[2];
  c2_j = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 14);
  c2_W_bn = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 13);
  c2_W_an = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 12);
  c2_Vcm_bn = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 11);
  c2_Vcm_an = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 10);
  c2_collision = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c2_docking = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c2_B = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 7);
  c2_A = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 6);
  c2_QB_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 5);
  c2_QA_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 4);
  c2_n_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_dock_sensB_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_dock_sensA_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "A",
                        c2_dv0);
  for (c2_i12 = 0; c2_i12 < 16; c2_i12++) {
    (*c2_A)[c2_i12] = c2_dv0[c2_i12];
  }

  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)), "B",
                        c2_dv1);
  for (c2_i13 = 0; c2_i13 < 10; c2_i13++) {
    (*c2_B)[c2_i13] = c2_dv1[c2_i13];
  }

  c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
                        "QA_c", c2_dv2);
  for (c2_i14 = 0; c2_i14 < 2; c2_i14++) {
    (*c2_QA_c)[c2_i14] = c2_dv2[c2_i14];
  }

  c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 3)),
                        "QB_c", c2_dv3);
  for (c2_i15 = 0; c2_i15 < 2; c2_i15++) {
    (*c2_QB_c)[c2_i15] = c2_dv3[c2_i15];
  }

  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 4)),
                      "Vcm_an", c2_dv4);
  for (c2_i16 = 0; c2_i16 < 3; c2_i16++) {
    (*c2_Vcm_an)[c2_i16] = c2_dv4[c2_i16];
  }

  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 5)),
                      "Vcm_bn", c2_dv5);
  for (c2_i17 = 0; c2_i17 < 3; c2_i17++) {
    (*c2_Vcm_bn)[c2_i17] = c2_dv5[c2_i17];
  }

  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 6)), "W_an",
                      c2_dv6);
  for (c2_i18 = 0; c2_i18 < 3; c2_i18++) {
    (*c2_W_an)[c2_i18] = c2_dv6[c2_i18];
  }

  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 7)), "W_bn",
                      c2_dv7);
  for (c2_i19 = 0; c2_i19 < 3; c2_i19++) {
    (*c2_W_bn)[c2_i19] = c2_dv7[c2_i19];
  }

  *c2_collision = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 8)), "collision");
  c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 9)),
                        "dock_sensA_c", c2_dv8);
  for (c2_i20 = 0; c2_i20 < 2; c2_i20++) {
    (*c2_dock_sensA_c)[c2_i20] = c2_dv8[c2_i20];
  }

  c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 10)),
                        "dock_sensB_c", c2_dv9);
  for (c2_i21 = 0; c2_i21 < 2; c2_i21++) {
    (*c2_dock_sensB_c)[c2_i21] = c2_dv9[c2_i21];
  }

  *c2_docking = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 11)), "docking");
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 12)), "j",
                      c2_dv10);
  for (c2_i22 = 0; c2_i22 < 3; c2_i22++) {
    (*c2_j)[c2_i22] = c2_dv10[c2_i22];
  }

  c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 13)),
                        "n_c", c2_dv11);
  for (c2_i23 = 0; c2_i23 < 2; c2_i23++) {
    (*c2_n_c)[c2_i23] = c2_dv11[c2_i23];
  }

  chartInstance->c2_is_active_c2_EndEffectorVSCube_v2 = c2_l_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 14)),
     "is_active_c2_EndEffectorVSCube_v2");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_EndEffectorVSCube_v2(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_EndEffectorVSCube_v2
  (SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static void sf_c2_EndEffectorVSCube_v2(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance)
{
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  int32_T c2_i35;
  int32_T c2_i36;
  int32_T c2_i37;
  int32_T c2_i38;
  int32_T c2_i39;
  int32_T c2_i40;
  int32_T c2_i41;
  int32_T c2_i42;
  int32_T c2_i43;
  int32_T c2_i44;
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_epsilon;
  real_T c2_sigma_dock;
  real_T c2_dotsigma_dock;
  int32_T c2_i45;
  real_T c2_Rbi_A1[4];
  int32_T c2_i46;
  real_T c2_Rbi_B1[4];
  int32_T c2_i47;
  real_T c2_Xcm_A[9];
  int32_T c2_i48;
  real_T c2_Xcm_B[9];
  int32_T c2_i49;
  real_T c2_mesh_A[21];
  int32_T c2_i50;
  real_T c2_mesh_B[12];
  int32_T c2_i51;
  real_T c2_dock_sensA[3];
  int32_T c2_i52;
  real_T c2_dock_sensB[3];
  real_T c2_sigma;
  int32_T c2_i53;
  real_T c2_ma_mb_Ia_Ib[4];
  uint32_T c2_debug_family_var_map[29];
  real_T c2_nargin = 13.0;
  real_T c2_nargout = 14.0;
  real_T c2_dock_sensA_c[2];
  real_T c2_dock_sensB_c[2];
  real_T c2_n_c[2];
  real_T c2_QA_c[2];
  real_T c2_QB_c[2];
  real_T c2_A[16];
  real_T c2_B[10];
  real_T c2_docking;
  real_T c2_collision;
  real_T c2_Vcm_an[3];
  real_T c2_Vcm_bn[3];
  real_T c2_W_an[3];
  real_T c2_W_bn[3];
  real_T c2_j[3];
  int32_T c2_i54;
  real_T c2_b_Rbi_A1[4];
  int32_T c2_i55;
  real_T c2_b_Rbi_B1[4];
  int32_T c2_i56;
  real_T c2_b_Xcm_A[9];
  int32_T c2_i57;
  real_T c2_b_Xcm_B[9];
  int32_T c2_i58;
  real_T c2_b_mesh_A[21];
  int32_T c2_i59;
  real_T c2_b_mesh_B[12];
  int32_T c2_i60;
  real_T c2_b_dock_sensA[3];
  int32_T c2_i61;
  real_T c2_b_dock_sensB[3];
  int32_T c2_i62;
  real_T c2_b_ma_mb_Ia_Ib[4];
  real_T c2_b_j[3];
  real_T c2_b_W_bn[3];
  real_T c2_b_W_an[3];
  real_T c2_b_Vcm_bn[3];
  real_T c2_b_Vcm_an[3];
  real_T c2_b_collision;
  real_T c2_b_docking;
  real_T c2_b_B[10];
  real_T c2_b_A[16];
  real_T c2_b_QB_c[2];
  real_T c2_b_QA_c[2];
  real_T c2_b_n_c[2];
  real_T c2_b_dock_sensB_c[2];
  real_T c2_b_dock_sensA_c[2];
  int32_T c2_i63;
  int32_T c2_i64;
  int32_T c2_i65;
  int32_T c2_i66;
  int32_T c2_i67;
  int32_T c2_i68;
  int32_T c2_i69;
  int32_T c2_i70;
  int32_T c2_i71;
  int32_T c2_i72;
  int32_T c2_i73;
  int32_T c2_i74;
  int32_T c2_i75;
  int32_T c2_i76;
  int32_T c2_i77;
  int32_T c2_i78;
  int32_T c2_i79;
  int32_T c2_i80;
  int32_T c2_i81;
  int32_T c2_i82;
  int32_T c2_i83;
  int32_T c2_i84;
  int32_T c2_i85;
  int32_T c2_i86;
  real_T *c2_b_epsilon;
  real_T *c2_b_sigma_dock;
  real_T *c2_b_dotsigma_dock;
  real_T *c2_b_sigma;
  real_T *c2_c_docking;
  real_T *c2_c_collision;
  real_T (*c2_c_dock_sensA_c)[2];
  real_T (*c2_c_dock_sensB_c)[2];
  real_T (*c2_c_n_c)[2];
  real_T (*c2_c_QA_c)[2];
  real_T (*c2_c_QB_c)[2];
  real_T (*c2_c_A)[16];
  real_T (*c2_c_B)[10];
  real_T (*c2_c_Vcm_an)[3];
  real_T (*c2_c_Vcm_bn)[3];
  real_T (*c2_c_W_an)[3];
  real_T (*c2_c_W_bn)[3];
  real_T (*c2_c_j)[3];
  real_T (*c2_c_ma_mb_Ia_Ib)[4];
  real_T (*c2_c_dock_sensB)[3];
  real_T (*c2_c_dock_sensA)[3];
  real_T (*c2_c_mesh_B)[12];
  real_T (*c2_c_mesh_A)[21];
  real_T (*c2_c_Xcm_B)[9];
  real_T (*c2_c_Xcm_A)[9];
  real_T (*c2_c_Rbi_B1)[4];
  real_T (*c2_c_Rbi_A1)[4];
  c2_c_j = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 14);
  c2_c_W_bn = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 13);
  c2_c_W_an = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 12);
  c2_c_Vcm_bn = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 11);
  c2_c_Vcm_an = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 10);
  c2_c_collision = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c2_c_ma_mb_Ia_Ib = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 12);
  c2_c_docking = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c2_b_sigma = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c2_c_dock_sensB = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 10);
  c2_c_dock_sensA = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 9);
  c2_c_mesh_B = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 8);
  c2_c_mesh_A = (real_T (*)[21])ssGetInputPortSignal(chartInstance->S, 7);
  c2_c_Xcm_B = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 6);
  c2_c_Xcm_A = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 5);
  c2_c_B = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 7);
  c2_c_A = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 6);
  c2_c_Rbi_B1 = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 4);
  c2_c_Rbi_A1 = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_dotsigma_dock = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_sigma_dock = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_c_QB_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 5);
  c2_c_QA_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 4);
  c2_c_n_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_c_dock_sensB_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_c_dock_sensA_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_epsilon = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_b_epsilon, 0U);
  for (c2_i24 = 0; c2_i24 < 2; c2_i24++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_dock_sensA_c)[c2_i24], 1U);
  }

  for (c2_i25 = 0; c2_i25 < 2; c2_i25++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_dock_sensB_c)[c2_i25], 2U);
  }

  for (c2_i26 = 0; c2_i26 < 2; c2_i26++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_n_c)[c2_i26], 3U);
  }

  for (c2_i27 = 0; c2_i27 < 2; c2_i27++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_QA_c)[c2_i27], 4U);
  }

  for (c2_i28 = 0; c2_i28 < 2; c2_i28++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_QB_c)[c2_i28], 5U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_b_sigma_dock, 6U);
  _SFD_DATA_RANGE_CHECK(*c2_b_dotsigma_dock, 7U);
  for (c2_i29 = 0; c2_i29 < 4; c2_i29++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_Rbi_A1)[c2_i29], 8U);
  }

  for (c2_i30 = 0; c2_i30 < 4; c2_i30++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_Rbi_B1)[c2_i30], 9U);
  }

  for (c2_i31 = 0; c2_i31 < 16; c2_i31++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_A)[c2_i31], 10U);
  }

  for (c2_i32 = 0; c2_i32 < 10; c2_i32++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_B)[c2_i32], 11U);
  }

  for (c2_i33 = 0; c2_i33 < 9; c2_i33++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_Xcm_A)[c2_i33], 12U);
  }

  for (c2_i34 = 0; c2_i34 < 9; c2_i34++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_Xcm_B)[c2_i34], 13U);
  }

  for (c2_i35 = 0; c2_i35 < 21; c2_i35++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_mesh_A)[c2_i35], 14U);
  }

  for (c2_i36 = 0; c2_i36 < 12; c2_i36++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_mesh_B)[c2_i36], 15U);
  }

  for (c2_i37 = 0; c2_i37 < 3; c2_i37++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_dock_sensA)[c2_i37], 16U);
  }

  for (c2_i38 = 0; c2_i38 < 3; c2_i38++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_dock_sensB)[c2_i38], 17U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_b_sigma, 18U);
  _SFD_DATA_RANGE_CHECK(*c2_c_docking, 19U);
  for (c2_i39 = 0; c2_i39 < 4; c2_i39++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_ma_mb_Ia_Ib)[c2_i39], 20U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_c_collision, 21U);
  for (c2_i40 = 0; c2_i40 < 3; c2_i40++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_Vcm_an)[c2_i40], 22U);
  }

  for (c2_i41 = 0; c2_i41 < 3; c2_i41++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_Vcm_bn)[c2_i41], 23U);
  }

  for (c2_i42 = 0; c2_i42 < 3; c2_i42++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_W_an)[c2_i42], 24U);
  }

  for (c2_i43 = 0; c2_i43 < 3; c2_i43++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_W_bn)[c2_i43], 25U);
  }

  for (c2_i44 = 0; c2_i44 < 3; c2_i44++) {
    _SFD_DATA_RANGE_CHECK((*c2_c_j)[c2_i44], 26U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_epsilon;
  c2_b_hoistedGlobal = *c2_b_sigma_dock;
  c2_c_hoistedGlobal = *c2_b_dotsigma_dock;
  c2_d_hoistedGlobal = *c2_b_sigma;
  c2_epsilon = c2_hoistedGlobal;
  c2_sigma_dock = c2_b_hoistedGlobal;
  c2_dotsigma_dock = c2_c_hoistedGlobal;
  for (c2_i45 = 0; c2_i45 < 4; c2_i45++) {
    c2_Rbi_A1[c2_i45] = (*c2_c_Rbi_A1)[c2_i45];
  }

  for (c2_i46 = 0; c2_i46 < 4; c2_i46++) {
    c2_Rbi_B1[c2_i46] = (*c2_c_Rbi_B1)[c2_i46];
  }

  for (c2_i47 = 0; c2_i47 < 9; c2_i47++) {
    c2_Xcm_A[c2_i47] = (*c2_c_Xcm_A)[c2_i47];
  }

  for (c2_i48 = 0; c2_i48 < 9; c2_i48++) {
    c2_Xcm_B[c2_i48] = (*c2_c_Xcm_B)[c2_i48];
  }

  for (c2_i49 = 0; c2_i49 < 21; c2_i49++) {
    c2_mesh_A[c2_i49] = (*c2_c_mesh_A)[c2_i49];
  }

  for (c2_i50 = 0; c2_i50 < 12; c2_i50++) {
    c2_mesh_B[c2_i50] = (*c2_c_mesh_B)[c2_i50];
  }

  for (c2_i51 = 0; c2_i51 < 3; c2_i51++) {
    c2_dock_sensA[c2_i51] = (*c2_c_dock_sensA)[c2_i51];
  }

  for (c2_i52 = 0; c2_i52 < 3; c2_i52++) {
    c2_dock_sensB[c2_i52] = (*c2_c_dock_sensB)[c2_i52];
  }

  c2_sigma = c2_d_hoistedGlobal;
  for (c2_i53 = 0; c2_i53 < 4; c2_i53++) {
    c2_ma_mb_Ia_Ib[c2_i53] = (*c2_c_ma_mb_Ia_Ib)[c2_i53];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 29U, 29U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_epsilon, 2U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_sigma_dock, 3U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_dotsigma_dock, 4U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_Rbi_A1, 5U, c2_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_Rbi_B1, 6U, c2_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_Xcm_A, 7U, c2_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_Xcm_B, 8U, c2_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_mesh_A, 9U, c2_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_mesh_B, 10U, c2_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_dock_sensA, 11U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_dock_sensB, 12U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_sigma, 13U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_ma_mb_Ia_Ib, 14U, c2_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_dock_sensA_c, 15U, c2_e_sf_marshallOut,
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_dock_sensB_c, 16U, c2_e_sf_marshallOut,
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_n_c, 17U, c2_e_sf_marshallOut,
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_QA_c, 18U, c2_e_sf_marshallOut,
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_QB_c, 19U, c2_e_sf_marshallOut,
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_A, 20U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_B, 21U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_docking, 22U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_collision, 23U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Vcm_an, 24U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_Vcm_bn, 25U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_W_an, 26U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_W_bn, 27U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_j, 28U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  for (c2_i54 = 0; c2_i54 < 4; c2_i54++) {
    c2_b_Rbi_A1[c2_i54] = c2_Rbi_A1[c2_i54];
  }

  for (c2_i55 = 0; c2_i55 < 4; c2_i55++) {
    c2_b_Rbi_B1[c2_i55] = c2_Rbi_B1[c2_i55];
  }

  for (c2_i56 = 0; c2_i56 < 9; c2_i56++) {
    c2_b_Xcm_A[c2_i56] = c2_Xcm_A[c2_i56];
  }

  for (c2_i57 = 0; c2_i57 < 9; c2_i57++) {
    c2_b_Xcm_B[c2_i57] = c2_Xcm_B[c2_i57];
  }

  for (c2_i58 = 0; c2_i58 < 21; c2_i58++) {
    c2_b_mesh_A[c2_i58] = c2_mesh_A[c2_i58];
  }

  for (c2_i59 = 0; c2_i59 < 12; c2_i59++) {
    c2_b_mesh_B[c2_i59] = c2_mesh_B[c2_i59];
  }

  for (c2_i60 = 0; c2_i60 < 3; c2_i60++) {
    c2_b_dock_sensA[c2_i60] = c2_dock_sensA[c2_i60];
  }

  for (c2_i61 = 0; c2_i61 < 3; c2_i61++) {
    c2_b_dock_sensB[c2_i61] = c2_dock_sensB[c2_i61];
  }

  for (c2_i62 = 0; c2_i62 < 4; c2_i62++) {
    c2_b_ma_mb_Ia_Ib[c2_i62] = c2_ma_mb_Ia_Ib[c2_i62];
  }

  c2_collision_function(chartInstance, c2_epsilon, c2_sigma_dock,
                        c2_dotsigma_dock, c2_b_Rbi_A1, c2_b_Rbi_B1, c2_b_Xcm_A,
                        c2_b_Xcm_B, c2_b_mesh_A, c2_b_mesh_B, c2_b_dock_sensA,
                        c2_b_dock_sensB, c2_sigma, c2_b_ma_mb_Ia_Ib,
                        c2_b_dock_sensA_c, c2_b_dock_sensB_c, c2_b_n_c,
                        c2_b_QA_c, c2_b_QB_c, c2_b_A, c2_b_B, &c2_b_docking,
                        &c2_b_collision, c2_b_Vcm_an, c2_b_Vcm_bn, c2_b_W_an,
                        c2_b_W_bn, c2_b_j);
  for (c2_i63 = 0; c2_i63 < 2; c2_i63++) {
    c2_dock_sensA_c[c2_i63] = c2_b_dock_sensA_c[c2_i63];
  }

  for (c2_i64 = 0; c2_i64 < 2; c2_i64++) {
    c2_dock_sensB_c[c2_i64] = c2_b_dock_sensB_c[c2_i64];
  }

  for (c2_i65 = 0; c2_i65 < 2; c2_i65++) {
    c2_n_c[c2_i65] = c2_b_n_c[c2_i65];
  }

  for (c2_i66 = 0; c2_i66 < 2; c2_i66++) {
    c2_QA_c[c2_i66] = c2_b_QA_c[c2_i66];
  }

  for (c2_i67 = 0; c2_i67 < 2; c2_i67++) {
    c2_QB_c[c2_i67] = c2_b_QB_c[c2_i67];
  }

  for (c2_i68 = 0; c2_i68 < 16; c2_i68++) {
    c2_A[c2_i68] = c2_b_A[c2_i68];
  }

  for (c2_i69 = 0; c2_i69 < 10; c2_i69++) {
    c2_B[c2_i69] = c2_b_B[c2_i69];
  }

  c2_docking = c2_b_docking;
  c2_collision = c2_b_collision;
  for (c2_i70 = 0; c2_i70 < 3; c2_i70++) {
    c2_Vcm_an[c2_i70] = c2_b_Vcm_an[c2_i70];
  }

  for (c2_i71 = 0; c2_i71 < 3; c2_i71++) {
    c2_Vcm_bn[c2_i71] = c2_b_Vcm_bn[c2_i71];
  }

  for (c2_i72 = 0; c2_i72 < 3; c2_i72++) {
    c2_W_an[c2_i72] = c2_b_W_an[c2_i72];
  }

  for (c2_i73 = 0; c2_i73 < 3; c2_i73++) {
    c2_W_bn[c2_i73] = c2_b_W_bn[c2_i73];
  }

  for (c2_i74 = 0; c2_i74 < 3; c2_i74++) {
    c2_j[c2_i74] = c2_b_j[c2_i74];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i75 = 0; c2_i75 < 2; c2_i75++) {
    (*c2_c_dock_sensA_c)[c2_i75] = c2_dock_sensA_c[c2_i75];
  }

  for (c2_i76 = 0; c2_i76 < 2; c2_i76++) {
    (*c2_c_dock_sensB_c)[c2_i76] = c2_dock_sensB_c[c2_i76];
  }

  for (c2_i77 = 0; c2_i77 < 2; c2_i77++) {
    (*c2_c_n_c)[c2_i77] = c2_n_c[c2_i77];
  }

  for (c2_i78 = 0; c2_i78 < 2; c2_i78++) {
    (*c2_c_QA_c)[c2_i78] = c2_QA_c[c2_i78];
  }

  for (c2_i79 = 0; c2_i79 < 2; c2_i79++) {
    (*c2_c_QB_c)[c2_i79] = c2_QB_c[c2_i79];
  }

  for (c2_i80 = 0; c2_i80 < 16; c2_i80++) {
    (*c2_c_A)[c2_i80] = c2_A[c2_i80];
  }

  for (c2_i81 = 0; c2_i81 < 10; c2_i81++) {
    (*c2_c_B)[c2_i81] = c2_B[c2_i81];
  }

  *c2_c_docking = c2_docking;
  *c2_c_collision = c2_collision;
  for (c2_i82 = 0; c2_i82 < 3; c2_i82++) {
    (*c2_c_Vcm_an)[c2_i82] = c2_Vcm_an[c2_i82];
  }

  for (c2_i83 = 0; c2_i83 < 3; c2_i83++) {
    (*c2_c_Vcm_bn)[c2_i83] = c2_Vcm_bn[c2_i83];
  }

  for (c2_i84 = 0; c2_i84 < 3; c2_i84++) {
    (*c2_c_W_an)[c2_i84] = c2_W_an[c2_i84];
  }

  for (c2_i85 = 0; c2_i85 < 3; c2_i85++) {
    (*c2_c_W_bn)[c2_i85] = c2_W_bn[c2_i85];
  }

  for (c2_i86 = 0; c2_i86 < 3; c2_i86++) {
    (*c2_c_j)[c2_i86] = c2_j[c2_i86];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_EndEffectorVSCube_v2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_EndEffectorVSCube_v2
  (SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static void registerMessagesc2_EndEffectorVSCube_v2
  (SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i87;
  real_T c2_b_inData[3];
  int32_T c2_i88;
  real_T c2_u[3];
  const mxArray *c2_y = NULL;
  SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i87 = 0; c2_i87 < 3; c2_i87++) {
    c2_b_inData[c2_i87] = (*(real_T (*)[3])c2_inData)[c2_i87];
  }

  for (c2_i88 = 0; c2_i88 < 3; c2_i88++) {
    c2_u[c2_i88] = c2_b_inData[c2_i88];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c2_j, const char_T *c2_identifier, real_T c2_y
  [3])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_j), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_j);
}

static void c2_b_emlrt_marshallIn(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[3])
{
  real_T c2_dv12[3];
  int32_T c2_i89;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv12, 1, 0, 0U, 1, 0U, 1, 3);
  for (c2_i89 = 0; c2_i89 < 3; c2_i89++) {
    c2_y[c2_i89] = c2_dv12[c2_i89];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_j;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[3];
  int32_T c2_i90;
  SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c2_j = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_j), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_j);
  for (c2_i90 = 0; c2_i90 < 3; c2_i90++) {
    (*(real_T (*)[3])c2_outData)[c2_i90] = c2_y[c2_i90];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c2_collision, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_collision),
    &c2_thisId);
  sf_mex_destroy(&c2_collision);
  return c2_y;
}

static real_T c2_d_emlrt_marshallIn(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_collision;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c2_collision = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_collision),
    &c2_thisId);
  sf_mex_destroy(&c2_collision);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i91;
  int32_T c2_i92;
  int32_T c2_i93;
  real_T c2_b_inData[10];
  int32_T c2_i94;
  int32_T c2_i95;
  int32_T c2_i96;
  real_T c2_u[10];
  const mxArray *c2_y = NULL;
  SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i91 = 0;
  for (c2_i92 = 0; c2_i92 < 5; c2_i92++) {
    for (c2_i93 = 0; c2_i93 < 2; c2_i93++) {
      c2_b_inData[c2_i93 + c2_i91] = (*(real_T (*)[10])c2_inData)[c2_i93 +
        c2_i91];
    }

    c2_i91 += 2;
  }

  c2_i94 = 0;
  for (c2_i95 = 0; c2_i95 < 5; c2_i95++) {
    for (c2_i96 = 0; c2_i96 < 2; c2_i96++) {
      c2_u[c2_i96 + c2_i94] = c2_b_inData[c2_i96 + c2_i94];
    }

    c2_i94 += 2;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 2, 5), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_e_emlrt_marshallIn(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c2_B, const char_T *c2_identifier, real_T c2_y
  [10])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_B), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_B);
}

static void c2_f_emlrt_marshallIn(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[10])
{
  real_T c2_dv13[10];
  int32_T c2_i97;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv13, 1, 0, 0U, 1, 0U, 2, 2, 5);
  for (c2_i97 = 0; c2_i97 < 10; c2_i97++) {
    c2_y[c2_i97] = c2_dv13[c2_i97];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_B;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[10];
  int32_T c2_i98;
  int32_T c2_i99;
  int32_T c2_i100;
  SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c2_B = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_B), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_B);
  c2_i98 = 0;
  for (c2_i99 = 0; c2_i99 < 5; c2_i99++) {
    for (c2_i100 = 0; c2_i100 < 2; c2_i100++) {
      (*(real_T (*)[10])c2_outData)[c2_i100 + c2_i98] = c2_y[c2_i100 + c2_i98];
    }

    c2_i98 += 2;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i101;
  int32_T c2_i102;
  int32_T c2_i103;
  real_T c2_b_inData[16];
  int32_T c2_i104;
  int32_T c2_i105;
  int32_T c2_i106;
  real_T c2_u[16];
  const mxArray *c2_y = NULL;
  SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i101 = 0;
  for (c2_i102 = 0; c2_i102 < 8; c2_i102++) {
    for (c2_i103 = 0; c2_i103 < 2; c2_i103++) {
      c2_b_inData[c2_i103 + c2_i101] = (*(real_T (*)[16])c2_inData)[c2_i103 +
        c2_i101];
    }

    c2_i101 += 2;
  }

  c2_i104 = 0;
  for (c2_i105 = 0; c2_i105 < 8; c2_i105++) {
    for (c2_i106 = 0; c2_i106 < 2; c2_i106++) {
      c2_u[c2_i106 + c2_i104] = c2_b_inData[c2_i106 + c2_i104];
    }

    c2_i104 += 2;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 2, 8), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_g_emlrt_marshallIn(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c2_A, const char_T *c2_identifier, real_T c2_y
  [16])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_A), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_A);
}

static void c2_h_emlrt_marshallIn(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[16])
{
  real_T c2_dv14[16];
  int32_T c2_i107;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv14, 1, 0, 0U, 1, 0U, 2, 2, 8);
  for (c2_i107 = 0; c2_i107 < 16; c2_i107++) {
    c2_y[c2_i107] = c2_dv14[c2_i107];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_A;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[16];
  int32_T c2_i108;
  int32_T c2_i109;
  int32_T c2_i110;
  SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c2_A = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_A), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_A);
  c2_i108 = 0;
  for (c2_i109 = 0; c2_i109 < 8; c2_i109++) {
    for (c2_i110 = 0; c2_i110 < 2; c2_i110++) {
      (*(real_T (*)[16])c2_outData)[c2_i110 + c2_i108] = c2_y[c2_i110 + c2_i108];
    }

    c2_i108 += 2;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i111;
  real_T c2_b_inData[2];
  int32_T c2_i112;
  real_T c2_u[2];
  const mxArray *c2_y = NULL;
  SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i111 = 0; c2_i111 < 2; c2_i111++) {
    c2_b_inData[c2_i111] = (*(real_T (*)[2])c2_inData)[c2_i111];
  }

  for (c2_i112 = 0; c2_i112 < 2; c2_i112++) {
    c2_u[c2_i112] = c2_b_inData[c2_i112];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_i_emlrt_marshallIn(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c2_QB_c, const char_T *c2_identifier, real_T
  c2_y[2])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_QB_c), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_QB_c);
}

static void c2_j_emlrt_marshallIn(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[2])
{
  real_T c2_dv15[2];
  int32_T c2_i113;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv15, 1, 0, 0U, 1, 0U, 1, 2);
  for (c2_i113 = 0; c2_i113 < 2; c2_i113++) {
    c2_y[c2_i113] = c2_dv15[c2_i113];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_QB_c;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[2];
  int32_T c2_i114;
  SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c2_QB_c = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_QB_c), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_QB_c);
  for (c2_i114 = 0; c2_i114 < 2; c2_i114++) {
    (*(real_T (*)[2])c2_outData)[c2_i114] = c2_y[c2_i114];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i115;
  real_T c2_b_inData[4];
  int32_T c2_i116;
  real_T c2_u[4];
  const mxArray *c2_y = NULL;
  SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i115 = 0; c2_i115 < 4; c2_i115++) {
    c2_b_inData[c2_i115] = (*(real_T (*)[4])c2_inData)[c2_i115];
  }

  for (c2_i116 = 0; c2_i116 < 4; c2_i116++) {
    c2_u[c2_i116] = c2_b_inData[c2_i116];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i117;
  int32_T c2_i118;
  int32_T c2_i119;
  real_T c2_b_inData[12];
  int32_T c2_i120;
  int32_T c2_i121;
  int32_T c2_i122;
  real_T c2_u[12];
  const mxArray *c2_y = NULL;
  SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i117 = 0;
  for (c2_i118 = 0; c2_i118 < 4; c2_i118++) {
    for (c2_i119 = 0; c2_i119 < 3; c2_i119++) {
      c2_b_inData[c2_i119 + c2_i117] = (*(real_T (*)[12])c2_inData)[c2_i119 +
        c2_i117];
    }

    c2_i117 += 3;
  }

  c2_i120 = 0;
  for (c2_i121 = 0; c2_i121 < 4; c2_i121++) {
    for (c2_i122 = 0; c2_i122 < 3; c2_i122++) {
      c2_u[c2_i122 + c2_i120] = c2_b_inData[c2_i122 + c2_i120];
    }

    c2_i120 += 3;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 3, 4), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i123;
  int32_T c2_i124;
  int32_T c2_i125;
  real_T c2_b_inData[21];
  int32_T c2_i126;
  int32_T c2_i127;
  int32_T c2_i128;
  real_T c2_u[21];
  const mxArray *c2_y = NULL;
  SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i123 = 0;
  for (c2_i124 = 0; c2_i124 < 7; c2_i124++) {
    for (c2_i125 = 0; c2_i125 < 3; c2_i125++) {
      c2_b_inData[c2_i125 + c2_i123] = (*(real_T (*)[21])c2_inData)[c2_i125 +
        c2_i123];
    }

    c2_i123 += 3;
  }

  c2_i126 = 0;
  for (c2_i127 = 0; c2_i127 < 7; c2_i127++) {
    for (c2_i128 = 0; c2_i128 < 3; c2_i128++) {
      c2_u[c2_i128 + c2_i126] = c2_b_inData[c2_i128 + c2_i126];
    }

    c2_i126 += 3;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 3, 7), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i129;
  real_T c2_b_inData[9];
  int32_T c2_i130;
  real_T c2_u[9];
  const mxArray *c2_y = NULL;
  SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i129 = 0; c2_i129 < 9; c2_i129++) {
    c2_b_inData[c2_i129] = (*(real_T (*)[9])c2_inData)[c2_i129];
  }

  for (c2_i130 = 0; c2_i130 < 9; c2_i130++) {
    c2_u[c2_i130] = c2_b_inData[c2_i130];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 9, 1), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i131;
  int32_T c2_i132;
  int32_T c2_i133;
  real_T c2_b_inData[4];
  int32_T c2_i134;
  int32_T c2_i135;
  int32_T c2_i136;
  real_T c2_u[4];
  const mxArray *c2_y = NULL;
  SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i131 = 0;
  for (c2_i132 = 0; c2_i132 < 2; c2_i132++) {
    for (c2_i133 = 0; c2_i133 < 2; c2_i133++) {
      c2_b_inData[c2_i133 + c2_i131] = (*(real_T (*)[4])c2_inData)[c2_i133 +
        c2_i131];
    }

    c2_i131 += 2;
  }

  c2_i134 = 0;
  for (c2_i135 = 0; c2_i135 < 2; c2_i135++) {
    for (c2_i136 = 0; c2_i136 < 2; c2_i136++) {
      c2_u[c2_i136 + c2_i134] = c2_b_inData[c2_i136 + c2_i134];
    }

    c2_i134 += 2;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

const mxArray *sf_c2_EndEffectorVSCube_v2_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[70];
  c2_ResolvedFunctionInfo (*c2_b_info)[70];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i137;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  c2_b_info = (c2_ResolvedFunctionInfo (*)[70])c2_info;
  (*c2_b_info)[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  (*c2_b_info)[64].name = "eml_int_forloop_overflow_check";
  (*c2_b_info)[64].dominantType = "";
  (*c2_b_info)[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  (*c2_b_info)[64].fileTimeLo = 1346542740U;
  (*c2_b_info)[64].fileTimeHi = 0U;
  (*c2_b_info)[64].mFileTimeLo = 0U;
  (*c2_b_info)[64].mFileTimeHi = 0U;
  (*c2_b_info)[65].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  (*c2_b_info)[65].name = "eml_relop";
  (*c2_b_info)[65].dominantType = "function_handle";
  (*c2_b_info)[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  (*c2_b_info)[65].fileTimeLo = 1342483582U;
  (*c2_b_info)[65].fileTimeHi = 0U;
  (*c2_b_info)[65].mFileTimeLo = 0U;
  (*c2_b_info)[65].mFileTimeHi = 0U;
  (*c2_b_info)[66].context =
    "[E]C:/Users/Grompone/Dropbox/worknetwork/ME4901/labs4901/Final Project/Integrator/collision_function.p";
  (*c2_b_info)[66].name = "cross";
  (*c2_b_info)[66].dominantType = "double";
  (*c2_b_info)[66].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  (*c2_b_info)[66].fileTimeLo = 1286851242U;
  (*c2_b_info)[66].fileTimeHi = 0U;
  (*c2_b_info)[66].mFileTimeLo = 0U;
  (*c2_b_info)[66].mFileTimeHi = 0U;
  (*c2_b_info)[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  (*c2_b_info)[67].name = "mtimes";
  (*c2_b_info)[67].dominantType = "double";
  (*c2_b_info)[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c2_b_info)[67].fileTimeLo = 1289552092U;
  (*c2_b_info)[67].fileTimeHi = 0U;
  (*c2_b_info)[67].mFileTimeLo = 0U;
  (*c2_b_info)[67].mFileTimeHi = 0U;
  (*c2_b_info)[68].context =
    "[E]C:/Users/Grompone/Dropbox/worknetwork/ME4901/labs4901/Final Project/Integrator/collision_function.p";
  (*c2_b_info)[68].name = "mldivide";
  (*c2_b_info)[68].dominantType = "double";
  (*c2_b_info)[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  (*c2_b_info)[68].fileTimeLo = 1357983948U;
  (*c2_b_info)[68].fileTimeHi = 0U;
  (*c2_b_info)[68].mFileTimeLo = 1319762366U;
  (*c2_b_info)[68].mFileTimeHi = 0U;
  (*c2_b_info)[69].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  (*c2_b_info)[69].name = "rdivide";
  (*c2_b_info)[69].dominantType = "double";
  (*c2_b_info)[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[69].fileTimeLo = 1346542788U;
  (*c2_b_info)[69].fileTimeHi = 0U;
  (*c2_b_info)[69].mFileTimeLo = 0U;
  (*c2_b_info)[69].mFileTimeHi = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 70), FALSE);
  for (c2_i137 = 0; c2_i137 < 70; c2_i137++) {
    c2_r0 = &c2_info[c2_i137];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i137);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i137);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i137);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i137);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i137);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i137);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i137);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i137);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[70])
{
  c2_info[0].context = "";
  c2_info[0].name = "collision_function";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved =
    "[E]C:/Users/Grompone/Dropbox/worknetwork/ME4901/labs4901/Final Project/Integrator/collision_function.p";
  c2_info[0].fileTimeLo = 1370539092U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context =
    "[E]C:/Users/Grompone/Dropbox/worknetwork/ME4901/labs4901/Final Project/Integrator/collision_function.p";
  c2_info[1].name = "mtimes";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[1].fileTimeLo = 1289552092U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[2].name = "eml_index_class";
  c2_info[2].dominantType = "";
  c2_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[2].fileTimeLo = 1323202978U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[3].name = "eml_scalar_eg";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[3].fileTimeLo = 1286851196U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[4].name = "eml_xgemm";
  c2_info[4].dominantType = "char";
  c2_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[4].fileTimeLo = 1299109172U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[5].name = "eml_blas_inline";
  c2_info[5].dominantType = "";
  c2_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[5].fileTimeLo = 1299109168U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c2_info[6].name = "mtimes";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[6].fileTimeLo = 1289552092U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[7].name = "eml_index_class";
  c2_info[7].dominantType = "";
  c2_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[7].fileTimeLo = 1323202978U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[8].name = "eml_scalar_eg";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[8].fileTimeLo = 1286851196U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[9].name = "eml_refblas_xgemm";
  c2_info[9].dominantType = "char";
  c2_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[9].fileTimeLo = 1299109174U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context =
    "[E]C:/Users/Grompone/Dropbox/worknetwork/ME4901/labs4901/Final Project/Integrator/collision_function.p";
  c2_info[10].name = "length";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[10].fileTimeLo = 1303178606U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength";
  c2_info[11].name = "eml_index_class";
  c2_info[11].dominantType = "";
  c2_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[11].fileTimeLo = 1323202978U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context =
    "[E]C:/Users/Grompone/Dropbox/worknetwork/ME4901/labs4901/Final Project/Integrator/collision_function.p";
  c2_info[12].name = "dot";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c2_info[12].fileTimeLo = 1313380216U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c2_info[13].name = "isequal";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c2_info[13].fileTimeLo = 1286851158U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c2_info[14].name = "eml_isequal_core";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c2_info[14].fileTimeLo = 1286851186U;
  c2_info[14].fileTimeHi = 0U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar";
  c2_info[15].name = "isnan";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[15].fileTimeLo = 1286851160U;
  c2_info[15].fileTimeHi = 0U;
  c2_info[15].mFileTimeLo = 0U;
  c2_info[15].mFileTimeHi = 0U;
  c2_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c2_info[16].name = "eml_index_class";
  c2_info[16].dominantType = "";
  c2_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[16].fileTimeLo = 1323202978U;
  c2_info[16].fileTimeHi = 0U;
  c2_info[16].mFileTimeLo = 0U;
  c2_info[16].mFileTimeHi = 0U;
  c2_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c2_info[17].name = "eml_scalar_eg";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[17].fileTimeLo = 1286851196U;
  c2_info[17].fileTimeHi = 0U;
  c2_info[17].mFileTimeLo = 0U;
  c2_info[17].mFileTimeHi = 0U;
  c2_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m!vdot";
  c2_info[18].name = "eml_xdotc";
  c2_info[18].dominantType = "double";
  c2_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c2_info[18].fileTimeLo = 1299109172U;
  c2_info[18].fileTimeHi = 0U;
  c2_info[18].mFileTimeLo = 0U;
  c2_info[18].mFileTimeHi = 0U;
  c2_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c2_info[19].name = "eml_blas_inline";
  c2_info[19].dominantType = "";
  c2_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[19].fileTimeLo = 1299109168U;
  c2_info[19].fileTimeHi = 0U;
  c2_info[19].mFileTimeLo = 0U;
  c2_info[19].mFileTimeHi = 0U;
  c2_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c2_info[20].name = "eml_xdot";
  c2_info[20].dominantType = "double";
  c2_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c2_info[20].fileTimeLo = 1299109172U;
  c2_info[20].fileTimeHi = 0U;
  c2_info[20].mFileTimeLo = 0U;
  c2_info[20].mFileTimeHi = 0U;
  c2_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c2_info[21].name = "eml_blas_inline";
  c2_info[21].dominantType = "";
  c2_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[21].fileTimeLo = 1299109168U;
  c2_info[21].fileTimeHi = 0U;
  c2_info[21].mFileTimeLo = 0U;
  c2_info[21].mFileTimeHi = 0U;
  c2_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m!below_threshold";
  c2_info[22].name = "length";
  c2_info[22].dominantType = "double";
  c2_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[22].fileTimeLo = 1303178606U;
  c2_info[22].fileTimeHi = 0U;
  c2_info[22].mFileTimeLo = 0U;
  c2_info[22].mFileTimeHi = 0U;
  c2_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c2_info[23].name = "eml_index_class";
  c2_info[23].dominantType = "";
  c2_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[23].fileTimeLo = 1323202978U;
  c2_info[23].fileTimeHi = 0U;
  c2_info[23].mFileTimeLo = 0U;
  c2_info[23].mFileTimeHi = 0U;
  c2_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c2_info[24].name = "eml_refblas_xdot";
  c2_info[24].dominantType = "double";
  c2_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c2_info[24].fileTimeLo = 1299109172U;
  c2_info[24].fileTimeHi = 0U;
  c2_info[24].mFileTimeLo = 0U;
  c2_info[24].mFileTimeHi = 0U;
  c2_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c2_info[25].name = "eml_refblas_xdotx";
  c2_info[25].dominantType = "char";
  c2_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c2_info[25].fileTimeLo = 1299109174U;
  c2_info[25].fileTimeHi = 0U;
  c2_info[25].mFileTimeLo = 0U;
  c2_info[25].mFileTimeHi = 0U;
  c2_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c2_info[26].name = "eml_scalar_eg";
  c2_info[26].dominantType = "double";
  c2_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[26].fileTimeLo = 1286851196U;
  c2_info[26].fileTimeHi = 0U;
  c2_info[26].mFileTimeLo = 0U;
  c2_info[26].mFileTimeHi = 0U;
  c2_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c2_info[27].name = "eml_index_class";
  c2_info[27].dominantType = "";
  c2_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[27].fileTimeLo = 1323202978U;
  c2_info[27].fileTimeHi = 0U;
  c2_info[27].mFileTimeLo = 0U;
  c2_info[27].mFileTimeHi = 0U;
  c2_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c2_info[28].name = "eml_int_forloop_overflow_check";
  c2_info[28].dominantType = "";
  c2_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[28].fileTimeLo = 1346542740U;
  c2_info[28].fileTimeHi = 0U;
  c2_info[28].mFileTimeLo = 0U;
  c2_info[28].mFileTimeHi = 0U;
  c2_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c2_info[29].name = "intmax";
  c2_info[29].dominantType = "char";
  c2_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[29].fileTimeLo = 1311287716U;
  c2_info[29].fileTimeHi = 0U;
  c2_info[29].mFileTimeLo = 0U;
  c2_info[29].mFileTimeHi = 0U;
  c2_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c2_info[30].name = "eml_index_minus";
  c2_info[30].dominantType = "double";
  c2_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[30].fileTimeLo = 1286851178U;
  c2_info[30].fileTimeHi = 0U;
  c2_info[30].mFileTimeLo = 0U;
  c2_info[30].mFileTimeHi = 0U;
  c2_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[31].name = "eml_index_class";
  c2_info[31].dominantType = "";
  c2_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[31].fileTimeLo = 1323202978U;
  c2_info[31].fileTimeHi = 0U;
  c2_info[31].mFileTimeLo = 0U;
  c2_info[31].mFileTimeHi = 0U;
  c2_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c2_info[32].name = "eml_index_times";
  c2_info[32].dominantType = "coder.internal.indexInt";
  c2_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[32].fileTimeLo = 1286851180U;
  c2_info[32].fileTimeHi = 0U;
  c2_info[32].mFileTimeLo = 0U;
  c2_info[32].mFileTimeHi = 0U;
  c2_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[33].name = "eml_index_class";
  c2_info[33].dominantType = "";
  c2_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[33].fileTimeLo = 1323202978U;
  c2_info[33].fileTimeHi = 0U;
  c2_info[33].mFileTimeLo = 0U;
  c2_info[33].mFileTimeHi = 0U;
  c2_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c2_info[34].name = "eml_index_plus";
  c2_info[34].dominantType = "coder.internal.indexInt";
  c2_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[34].fileTimeLo = 1286851178U;
  c2_info[34].fileTimeHi = 0U;
  c2_info[34].mFileTimeLo = 0U;
  c2_info[34].mFileTimeHi = 0U;
  c2_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[35].name = "eml_index_class";
  c2_info[35].dominantType = "";
  c2_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[35].fileTimeLo = 1323202978U;
  c2_info[35].fileTimeHi = 0U;
  c2_info[35].mFileTimeLo = 0U;
  c2_info[35].mFileTimeHi = 0U;
  c2_info[36].context =
    "[E]C:/Users/Grompone/Dropbox/worknetwork/ME4901/labs4901/Final Project/Integrator/collision_function.p";
  c2_info[36].name = "mrdivide";
  c2_info[36].dominantType = "double";
  c2_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[36].fileTimeLo = 1357983948U;
  c2_info[36].fileTimeHi = 0U;
  c2_info[36].mFileTimeLo = 1319762366U;
  c2_info[36].mFileTimeHi = 0U;
  c2_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[37].name = "rdivide";
  c2_info[37].dominantType = "double";
  c2_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[37].fileTimeLo = 1346542788U;
  c2_info[37].fileTimeHi = 0U;
  c2_info[37].mFileTimeLo = 0U;
  c2_info[37].mFileTimeHi = 0U;
  c2_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[38].name = "eml_scalexp_compatible";
  c2_info[38].dominantType = "double";
  c2_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c2_info[38].fileTimeLo = 1286851196U;
  c2_info[38].fileTimeHi = 0U;
  c2_info[38].mFileTimeLo = 0U;
  c2_info[38].mFileTimeHi = 0U;
  c2_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[39].name = "eml_div";
  c2_info[39].dominantType = "double";
  c2_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[39].fileTimeLo = 1313380210U;
  c2_info[39].fileTimeHi = 0U;
  c2_info[39].mFileTimeLo = 0U;
  c2_info[39].mFileTimeHi = 0U;
  c2_info[40].context =
    "[E]C:/Users/Grompone/Dropbox/worknetwork/ME4901/labs4901/Final Project/Integrator/collision_function.p";
  c2_info[40].name = "norm";
  c2_info[40].dominantType = "double";
  c2_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c2_info[40].fileTimeLo = 1336554494U;
  c2_info[40].fileTimeHi = 0U;
  c2_info[40].mFileTimeLo = 0U;
  c2_info[40].mFileTimeHi = 0U;
  c2_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm";
  c2_info[41].name = "eml_index_class";
  c2_info[41].dominantType = "";
  c2_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[41].fileTimeLo = 1323202978U;
  c2_info[41].fileTimeHi = 0U;
  c2_info[41].mFileTimeLo = 0U;
  c2_info[41].mFileTimeHi = 0U;
  c2_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm";
  c2_info[42].name = "eml_xnrm2";
  c2_info[42].dominantType = "double";
  c2_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c2_info[42].fileTimeLo = 1299109176U;
  c2_info[42].fileTimeHi = 0U;
  c2_info[42].mFileTimeLo = 0U;
  c2_info[42].mFileTimeHi = 0U;
  c2_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c2_info[43].name = "eml_blas_inline";
  c2_info[43].dominantType = "";
  c2_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[43].fileTimeLo = 1299109168U;
  c2_info[43].fileTimeHi = 0U;
  c2_info[43].mFileTimeLo = 0U;
  c2_info[43].mFileTimeHi = 0U;
  c2_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c2_info[44].name = "eml_index_class";
  c2_info[44].dominantType = "";
  c2_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[44].fileTimeLo = 1323202978U;
  c2_info[44].fileTimeHi = 0U;
  c2_info[44].mFileTimeLo = 0U;
  c2_info[44].mFileTimeHi = 0U;
  c2_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c2_info[45].name = "eml_refblas_xnrm2";
  c2_info[45].dominantType = "double";
  c2_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[45].fileTimeLo = 1299109184U;
  c2_info[45].fileTimeHi = 0U;
  c2_info[45].mFileTimeLo = 0U;
  c2_info[45].mFileTimeHi = 0U;
  c2_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[46].name = "realmin";
  c2_info[46].dominantType = "char";
  c2_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c2_info[46].fileTimeLo = 1307683642U;
  c2_info[46].fileTimeHi = 0U;
  c2_info[46].mFileTimeLo = 0U;
  c2_info[46].mFileTimeHi = 0U;
  c2_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c2_info[47].name = "eml_realmin";
  c2_info[47].dominantType = "char";
  c2_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c2_info[47].fileTimeLo = 1307683644U;
  c2_info[47].fileTimeHi = 0U;
  c2_info[47].mFileTimeLo = 0U;
  c2_info[47].mFileTimeHi = 0U;
  c2_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c2_info[48].name = "eml_float_model";
  c2_info[48].dominantType = "char";
  c2_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c2_info[48].fileTimeLo = 1326760396U;
  c2_info[48].fileTimeHi = 0U;
  c2_info[48].mFileTimeLo = 0U;
  c2_info[48].mFileTimeHi = 0U;
  c2_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[49].name = "eml_index_class";
  c2_info[49].dominantType = "";
  c2_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[49].fileTimeLo = 1323202978U;
  c2_info[49].fileTimeHi = 0U;
  c2_info[49].mFileTimeLo = 0U;
  c2_info[49].mFileTimeHi = 0U;
  c2_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[50].name = "eml_index_minus";
  c2_info[50].dominantType = "double";
  c2_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[50].fileTimeLo = 1286851178U;
  c2_info[50].fileTimeHi = 0U;
  c2_info[50].mFileTimeLo = 0U;
  c2_info[50].mFileTimeHi = 0U;
  c2_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[51].name = "eml_index_times";
  c2_info[51].dominantType = "coder.internal.indexInt";
  c2_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[51].fileTimeLo = 1286851180U;
  c2_info[51].fileTimeHi = 0U;
  c2_info[51].mFileTimeLo = 0U;
  c2_info[51].mFileTimeHi = 0U;
  c2_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[52].name = "eml_index_plus";
  c2_info[52].dominantType = "coder.internal.indexInt";
  c2_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[52].fileTimeLo = 1286851178U;
  c2_info[52].fileTimeHi = 0U;
  c2_info[52].mFileTimeLo = 0U;
  c2_info[52].mFileTimeHi = 0U;
  c2_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[53].name = "eml_int_forloop_overflow_check";
  c2_info[53].dominantType = "";
  c2_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[53].fileTimeLo = 1346542740U;
  c2_info[53].fileTimeHi = 0U;
  c2_info[53].mFileTimeLo = 0U;
  c2_info[53].mFileTimeHi = 0U;
  c2_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c2_info[54].name = "abs";
  c2_info[54].dominantType = "double";
  c2_info[54].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[54].fileTimeLo = 1343862766U;
  c2_info[54].fileTimeHi = 0U;
  c2_info[54].mFileTimeLo = 0U;
  c2_info[54].mFileTimeHi = 0U;
  c2_info[55].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[55].name = "eml_scalar_abs";
  c2_info[55].dominantType = "double";
  c2_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[55].fileTimeLo = 1286851112U;
  c2_info[55].fileTimeHi = 0U;
  c2_info[55].mFileTimeLo = 0U;
  c2_info[55].mFileTimeHi = 0U;
  c2_info[56].context =
    "[E]C:/Users/Grompone/Dropbox/worknetwork/ME4901/labs4901/Final Project/Integrator/collision_function.p";
  c2_info[56].name = "min";
  c2_info[56].dominantType = "double";
  c2_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[56].fileTimeLo = 1311287718U;
  c2_info[56].fileTimeHi = 0U;
  c2_info[56].mFileTimeLo = 0U;
  c2_info[56].mFileTimeHi = 0U;
  c2_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[57].name = "eml_min_or_max";
  c2_info[57].dominantType = "char";
  c2_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[57].fileTimeLo = 1334103890U;
  c2_info[57].fileTimeHi = 0U;
  c2_info[57].mFileTimeLo = 0U;
  c2_info[57].mFileTimeHi = 0U;
  c2_info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c2_info[58].name = "eml_const_nonsingleton_dim";
  c2_info[58].dominantType = "double";
  c2_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c2_info[58].fileTimeLo = 1286851096U;
  c2_info[58].fileTimeHi = 0U;
  c2_info[58].mFileTimeLo = 0U;
  c2_info[58].mFileTimeHi = 0U;
  c2_info[59].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c2_info[59].name = "eml_scalar_eg";
  c2_info[59].dominantType = "double";
  c2_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[59].fileTimeLo = 1286851196U;
  c2_info[59].fileTimeHi = 0U;
  c2_info[59].mFileTimeLo = 0U;
  c2_info[59].mFileTimeHi = 0U;
  c2_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c2_info[60].name = "eml_index_class";
  c2_info[60].dominantType = "";
  c2_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[60].fileTimeLo = 1323202978U;
  c2_info[60].fileTimeHi = 0U;
  c2_info[60].mFileTimeLo = 0U;
  c2_info[60].mFileTimeHi = 0U;
  c2_info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c2_info[61].name = "eml_index_class";
  c2_info[61].dominantType = "";
  c2_info[61].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[61].fileTimeLo = 1323202978U;
  c2_info[61].fileTimeHi = 0U;
  c2_info[61].mFileTimeLo = 0U;
  c2_info[61].mFileTimeHi = 0U;
  c2_info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c2_info[62].name = "isnan";
  c2_info[62].dominantType = "double";
  c2_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[62].fileTimeLo = 1286851160U;
  c2_info[62].fileTimeHi = 0U;
  c2_info[62].mFileTimeLo = 0U;
  c2_info[62].mFileTimeHi = 0U;
  c2_info[63].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c2_info[63].name = "eml_index_plus";
  c2_info[63].dominantType = "coder.internal.indexInt";
  c2_info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[63].fileTimeLo = 1286851178U;
  c2_info[63].fileTimeHi = 0U;
  c2_info[63].mFileTimeLo = 0U;
  c2_info[63].mFileTimeHi = 0U;
}

static void c2_collision_function(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, real_T c2_epsilon, real_T c2_sigma_dock, real_T
  c2_dotsigma_dock, real_T c2_Rbi_A1[4], real_T c2_Rbi_B1[4], real_T c2_Xcm_A[9],
  real_T c2_Xcm_B[9], real_T c2_mesh_A[21], real_T c2_mesh_B[12], real_T
  c2_dock_sensA[3], real_T c2_dock_sensB[3], real_T c2_sigma, real_T
  c2_ma_mb_Ia_Ib[4], real_T c2_dock_sensA_c[2], real_T c2_dock_sensB_c[2],
  real_T c2_n_c[2], real_T c2_QA_c[2], real_T c2_QB_c[2], real_T c2_A[16],
  real_T c2_B[10], real_T *c2_docking, real_T *c2_collision, real_T c2_Vcm_an[3],
  real_T c2_Vcm_bn[3], real_T c2_W_an[3], real_T c2_W_bn[3], real_T c2_j[3])
{
  int32_T c2_i138;
  real_T c2_Xcm[10];
  int32_T c2_i139;
  int32_T c2_i140;
  int32_T c2_i141;
  real_T c2_b_Xcm[2];
  int32_T c2_i142;
  real_T c2_cm_a[2];
  real_T c2_c_Xcm[2];
  int32_T c2_i143;
  real_T c2_cm_b[2];
  int32_T c2_i144;
  int32_T c2_i145;
  int32_T c2_i146;
  int32_T c2_i147;
  real_T c2_A_B[14];
  int32_T c2_i148;
  int32_T c2_i149;
  int32_T c2_i150;
  int32_T c2_i151;
  real_T c2_B_B[8];
  int32_T c2_i152;
  int32_T c2_n;
  real_T c2_b_n;
  int32_T c2_c_n;
  int32_T c2_i153;
  real_T c2_b[2];
  int32_T c2_i154;
  real_T c2_r[2];
  int32_T c2_i155;
  int32_T c2_i156;
  int32_T c2_d_n;
  int32_T c2_i157;
  int32_T c2_i158;
  int32_T c2_i159;
  int32_T c2_i160;
  int32_T c2_i161;
  int32_T c2_i162;
  int32_T c2_i163;
  int32_T c2_nn;
  real_T c2_b_nn;
  int32_T c2_c_nn;
  int32_T c2_i164;
  int32_T c2_i165;
  int32_T c2_i166;
  int32_T c2_i167;
  int32_T c2_d_nn;
  int32_T c2_i168;
  int32_T c2_i169;
  int32_T c2_i170;
  int32_T c2_i171;
  int32_T c2_i172;
  int32_T c2_i173;
  int32_T c2_i174;
  int32_T c2_i175;
  int32_T c2_i176;
  int32_T c2_i177;
  int32_T c2_i178;
  int32_T c2_i179;
  int32_T c2_i180;
  int32_T c2_i181;
  int32_T c2_i182;
  int32_T c2_i183;
  int32_T c2_i184;
  real_T c2_SS[4];
  int32_T c2_i185;
  int32_T c2_i186;
  int32_T c2_i187;
  int32_T c2_i188;
  int32_T c2_i189;
  real_T c2_Qb[14];
  int32_T c2_i190;
  real_T c2_Dist[7];
  int32_T c2_i191;
  real_T c2_dist[4];
  int32_T c2_i192;
  int32_T c2_i193;
  real_T c2_min_point_B[8];
  int32_T c2_k;
  real_T c2_b_k;
  int32_T c2_i;
  real_T c2_b_i;
  int32_T c2_c_i;
  int32_T c2_d_i;
  int32_T c2_i194;
  int32_T c2_c_k;
  int32_T c2_d_k;
  int32_T c2_i195;
  int32_T c2_e_i;
  int32_T c2_e_k;
  int32_T c2_i196;
  int32_T c2_i197;
  real_T c2_b_cm_a[2];
  int32_T c2_i198;
  real_T c2_c_cm_a[2];
  real_T c2_a;
  int32_T c2_i199;
  real_T c2_d_cm_a[2];
  int32_T c2_i200;
  real_T c2_b_cm_b[2];
  real_T c2_b_b;
  int32_T c2_i201;
  real_T c2_e_cm_a[2];
  int32_T c2_i202;
  real_T c2_b_r[2];
  real_T c2_c;
  int32_T c2_i203;
  real_T c2_c_cm_b[2];
  int32_T c2_i204;
  real_T c2_d_cm_b[2];
  real_T c2_e;
  int32_T c2_i205;
  real_T c2_e_cm_b[2];
  int32_T c2_i206;
  real_T c2_c_r[2];
  real_T c2_f;
  real_T c2_b_a;
  real_T c2_c_b;
  real_T c2_y;
  real_T c2_c_a;
  real_T c2_d_b;
  real_T c2_b_y;
  real_T c2_denom;
  real_T c2_t1;
  real_T c2_d_a;
  real_T c2_e_b;
  real_T c2_c_y;
  real_T c2_e_a;
  real_T c2_f_b;
  real_T c2_d_y;
  real_T c2_b_A;
  real_T c2_b_B;
  real_T c2_x;
  real_T c2_e_y;
  real_T c2_b_x;
  real_T c2_f_y;
  real_T c2_f_a;
  real_T c2_g_b;
  real_T c2_g_y;
  real_T c2_c_A;
  real_T c2_c_B;
  real_T c2_c_x;
  real_T c2_h_y;
  real_T c2_d_x;
  real_T c2_i_y;
  real_T c2_t2;
  real_T c2_g_a;
  real_T c2_h_b;
  real_T c2_j_y;
  real_T c2_d_A;
  real_T c2_d_B;
  real_T c2_e_x;
  real_T c2_k_y;
  real_T c2_f_x;
  real_T c2_l_y;
  real_T c2_h_a;
  int32_T c2_f_i;
  int32_T c2_g_i;
  int32_T c2_i207;
  int32_T c2_i208;
  int32_T c2_h_i;
  int32_T c2_i_i;
  int32_T c2_i209;
  real_T c2_i_a;
  int32_T c2_f_k;
  int32_T c2_g_k;
  int32_T c2_i210;
  int32_T c2_i211;
  int32_T c2_j_i;
  int32_T c2_h_k;
  int32_T c2_i212;
  int32_T c2_k_i;
  int32_T c2_l_i;
  int32_T c2_i213;
  real_T c2_b_Qb[2];
  int32_T c2_ixstart;
  real_T c2_mtmp;
  int32_T c2_itmp;
  real_T c2_g_x;
  boolean_T c2_i_b;
  int32_T c2_ix;
  int32_T c2_b_ix;
  real_T c2_h_x;
  boolean_T c2_j_b;
  int32_T c2_j_a;
  int32_T c2_i214;
  boolean_T c2_overflow;
  int32_T c2_c_ix;
  real_T c2_k_a;
  real_T c2_k_b;
  boolean_T c2_p;
  int32_T c2_b_itmp;
  int32_T c2_iindx;
  int32_T c2_b_iindx;
  real_T c2_indx;
  real_T c2_i_dist;
  real_T c2_b_i_dist;
  int32_T c2_i_k;
  int32_T c2_c_i_dist;
  int32_T c2_i215;
  int32_T c2_j_k;
  int32_T c2_d_i_dist;
  int32_T c2_i216;
  int32_T c2_k_k;
  int32_T c2_l_k;
  int32_T c2_i217;
  real_T c2_b_min_point_B[2];
  int32_T c2_b_ixstart;
  real_T c2_b_mtmp;
  int32_T c2_c_itmp;
  real_T c2_i_x;
  boolean_T c2_l_b;
  int32_T c2_d_ix;
  int32_T c2_e_ix;
  real_T c2_j_x;
  boolean_T c2_m_b;
  int32_T c2_l_a;
  int32_T c2_i218;
  boolean_T c2_b_overflow;
  int32_T c2_f_ix;
  real_T c2_m_a;
  real_T c2_n_b;
  boolean_T c2_b_p;
  real_T c2_c_mtmp;
  int32_T c2_d_itmp;
  real_T c2_extremum;
  int32_T c2_c_iindx;
  real_T c2_minval;
  int32_T c2_d_iindx;
  real_T c2_b_indx;
  real_T c2_dist_f_value;
  real_T c2_kk_dist;
  real_T c2_b_dist_f_value;
  real_T c2_b_kk_dist;
  int32_T c2_c_kk_dist;
  int32_T c2_i219;
  int32_T c2_d_kk_dist;
  int32_T c2_i220;
  real_T c2_contact;
  int32_T c2_e_kk_dist;
  int32_T c2_f_kk_dist;
  int32_T c2_i221;
  int32_T c2_g_kk_dist;
  int32_T c2_h_kk_dist;
  int32_T c2_i222;
  real_T c2_e_B[2];
  real_T c2_f_B;
  real_T c2_m_y;
  real_T c2_n_y;
  int32_T c2_i223;
  real_T c2_f_cm_a[2];
  int32_T c2_i224;
  int32_T c2_i225;
  real_T c2_Si_a[3];
  int32_T c2_i226;
  real_T c2_Si_b[3];
  real_T c2_x_a;
  real_T c2_y_a;
  real_T c2_vx_a;
  real_T c2_vy_a;
  real_T c2_w_a;
  real_T c2_b_x_a[3];
  int32_T c2_i227;
  real_T c2_Xcm_a[3];
  real_T c2_b_vx_a[3];
  int32_T c2_i228;
  real_T c2_Vcm_a[3];
  real_T c2_dv16[3];
  int32_T c2_i229;
  real_T c2_W_a[3];
  real_T c2_x_b;
  real_T c2_y_b;
  real_T c2_vx_b;
  real_T c2_vy_b;
  real_T c2_w_b;
  real_T c2_b_x_b[3];
  int32_T c2_i230;
  real_T c2_Xcm_b[3];
  real_T c2_b_vx_b[3];
  int32_T c2_i231;
  real_T c2_Vcm_b[3];
  real_T c2_dv17[3];
  int32_T c2_i232;
  real_T c2_W_b[3];
  int32_T c2_i233;
  int32_T c2_i234;
  int32_T c2_i235;
  real_T c2_b_W_a[3];
  int32_T c2_i236;
  real_T c2_b_Xcm_a[3];
  real_T c2_dv18[3];
  int32_T c2_i237;
  int32_T c2_i238;
  real_T c2_b_W_b[3];
  int32_T c2_i239;
  real_T c2_b_Xcm_b[3];
  int32_T c2_i240;
  int32_T c2_i241;
  real_T c2_b_Si_a[3];
  int32_T c2_i242;
  real_T c2_b_Vcm_a[3];
  real_T c2_ma;
  real_T c2_mb;
  real_T c2_Ia;
  real_T c2_Ib;
  int32_T c2_i243;
  int32_T c2_i244;
  int32_T c2_i245;
  real_T c2_N_cb[3];
  real_T c2_c_x_a[3];
  int32_T c2_i246;
  real_T c2_c_vx_a[3];
  int32_T c2_i247;
  real_T c2_dv19[3];
  int32_T c2_i248;
  real_T c2_c_x_b[3];
  int32_T c2_i249;
  real_T c2_c_vx_b[3];
  int32_T c2_i250;
  real_T c2_dv20[3];
  int32_T c2_i251;
  int32_T c2_i252;
  int32_T c2_i253;
  int32_T c2_i254;
  real_T c2_c_W_a[3];
  int32_T c2_i255;
  real_T c2_c_Xcm_a[3];
  real_T c2_Va_c[3];
  int32_T c2_i256;
  int32_T c2_i257;
  real_T c2_c_W_b[3];
  int32_T c2_i258;
  real_T c2_c_Xcm_b[3];
  int32_T c2_i259;
  int32_T c2_i260;
  int32_T c2_i261;
  int32_T c2_i262;
  int32_T c2_i263;
  int32_T c2_i264;
  int32_T c2_i265;
  int32_T c2_i266;
  real_T c2_b_Va_c[3];
  int32_T c2_i267;
  real_T c2_b_N_cb[3];
  real_T c2_g_B;
  real_T c2_o_y;
  real_T c2_p_y;
  real_T c2_q_y;
  real_T c2_h_B;
  real_T c2_r_y;
  real_T c2_s_y;
  real_T c2_t_y;
  real_T c2_e_A;
  int32_T c2_i268;
  real_T c2_d_Xcm_a[3];
  int32_T c2_i269;
  real_T c2_c_N_cb[3];
  int32_T c2_i270;
  real_T c2_dv21[3];
  int32_T c2_i271;
  real_T c2_e_Xcm_a[3];
  real_T c2_u_y;
  real_T c2_v_y;
  int32_T c2_i272;
  real_T c2_f_A;
  int32_T c2_i273;
  real_T c2_d_Xcm_b[3];
  int32_T c2_i274;
  real_T c2_d_N_cb[3];
  int32_T c2_i275;
  real_T c2_dv22[3];
  int32_T c2_i276;
  real_T c2_e_Xcm_b[3];
  real_T c2_w_y;
  real_T c2_x_y;
  int32_T c2_i277;
  int32_T c2_i278;
  real_T c2_b_Si_b[3];
  int32_T c2_i279;
  real_T c2_e_N_cb[3];
  real_T c2_kn;
  int32_T c2_i280;
  real_T c2_c_Va_c[3];
  int32_T c2_i281;
  real_T c2_f_N_cb[3];
  real_T c2_n_a;
  real_T c2_o_b;
  real_T c2_y_y;
  real_T c2_g_A;
  real_T c2_i_B;
  real_T c2_k_x;
  real_T c2_ab_y;
  real_T c2_l_x;
  real_T c2_bb_y;
  real_T c2_jn;
  real_T c2_o_a;
  int32_T c2_i282;
  real_T c2_j_B;
  real_T c2_cb_y;
  real_T c2_db_y;
  int32_T c2_i283;
  int32_T c2_i284;
  real_T c2_h_A;
  int32_T c2_i285;
  real_T c2_f_Xcm_a[3];
  int32_T c2_i286;
  real_T c2_b_j[3];
  real_T c2_eb_y;
  real_T c2_fb_y;
  int32_T c2_i287;
  int32_T c2_i288;
  real_T c2_k_B;
  real_T c2_gb_y;
  real_T c2_hb_y;
  int32_T c2_i289;
  int32_T c2_i290;
  real_T c2_i_A;
  int32_T c2_i291;
  real_T c2_f_Xcm_b[3];
  int32_T c2_i292;
  real_T c2_c_j[3];
  real_T c2_ib_y;
  real_T c2_jb_y;
  int32_T c2_i293;
  int32_T c2_i294;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T exitg1;
  boolean_T exitg2;
  for (c2_i138 = 0; c2_i138 < 2; c2_i138++) {
    c2_Xcm[c2_i138] = c2_Xcm_A[c2_i138];
  }

  for (c2_i139 = 0; c2_i139 < 2; c2_i139++) {
    c2_Xcm[c2_i139 + 2] = c2_Xcm_A[c2_i139 + 3];
  }

  c2_Xcm[4] = c2_Xcm_A[8];
  for (c2_i140 = 0; c2_i140 < 2; c2_i140++) {
    c2_Xcm[c2_i140 + 5] = c2_Xcm_B[c2_i140];
  }

  for (c2_i141 = 0; c2_i141 < 2; c2_i141++) {
    c2_Xcm[c2_i141 + 7] = c2_Xcm_B[c2_i141 + 3];
  }

  c2_Xcm[9] = c2_Xcm_B[8];
  c2_b_Xcm[0] = c2_Xcm[0];
  c2_b_Xcm[1] = c2_Xcm[1];
  for (c2_i142 = 0; c2_i142 < 2; c2_i142++) {
    c2_cm_a[c2_i142] = c2_b_Xcm[c2_i142];
  }

  c2_c_Xcm[0] = c2_Xcm[5];
  c2_c_Xcm[1] = c2_Xcm[6];
  for (c2_i143 = 0; c2_i143 < 2; c2_i143++) {
    c2_cm_b[c2_i143] = c2_c_Xcm[c2_i143];
  }

  c2_i144 = 0;
  c2_i145 = 0;
  for (c2_i146 = 0; c2_i146 < 7; c2_i146++) {
    for (c2_i147 = 0; c2_i147 < 2; c2_i147++) {
      c2_A_B[c2_i147 + c2_i144] = c2_mesh_A[c2_i147 + c2_i145];
    }

    c2_i144 += 2;
    c2_i145 += 3;
  }

  c2_i148 = 0;
  c2_i149 = 0;
  for (c2_i150 = 0; c2_i150 < 4; c2_i150++) {
    for (c2_i151 = 0; c2_i151 < 2; c2_i151++) {
      c2_B_B[c2_i151 + c2_i148] = c2_mesh_B[c2_i151 + c2_i149];
    }

    c2_i148 += 2;
    c2_i149 += 3;
  }

  for (c2_i152 = 0; c2_i152 < 16; c2_i152++) {
    c2_A[c2_i152] = 0.0;
  }

  c2_n = 0;
  while (c2_n < 7) {
    c2_b_n = 1.0 + (real_T)c2_n;
    c2_c_n = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c2_b_n), 1, 7, 2, 0) - 1;
    for (c2_i153 = 0; c2_i153 < 2; c2_i153++) {
      c2_b[c2_i153] = c2_A_B[c2_i153 + (c2_c_n << 1)];
    }

    c2_eml_scalar_eg(chartInstance);
    c2_eml_scalar_eg(chartInstance);
    for (c2_i154 = 0; c2_i154 < 2; c2_i154++) {
      c2_r[c2_i154] = 0.0;
      c2_i155 = 0;
      for (c2_i156 = 0; c2_i156 < 2; c2_i156++) {
        c2_r[c2_i154] += c2_Rbi_A1[c2_i155 + c2_i154] * c2_b[c2_i156];
        c2_i155 += 2;
      }
    }

    c2_d_n = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c2_b_n), 1, 8, 2, 0) - 1;
    for (c2_i157 = 0; c2_i157 < 2; c2_i157++) {
      c2_A[c2_i157 + (c2_d_n << 1)] = c2_cm_a[c2_i157] + c2_r[c2_i157];
    }

    c2_n++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  for (c2_i158 = 0; c2_i158 < 2; c2_i158++) {
    c2_b[c2_i158] = c2_A_B[c2_i158];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i159 = 0; c2_i159 < 2; c2_i159++) {
    c2_r[c2_i159] = 0.0;
    c2_i160 = 0;
    for (c2_i161 = 0; c2_i161 < 2; c2_i161++) {
      c2_r[c2_i159] += c2_Rbi_A1[c2_i160 + c2_i159] * c2_b[c2_i161];
      c2_i160 += 2;
    }
  }

  for (c2_i162 = 0; c2_i162 < 2; c2_i162++) {
    c2_A[c2_i162 + 14] = c2_cm_a[c2_i162] + c2_r[c2_i162];
  }

  for (c2_i163 = 0; c2_i163 < 10; c2_i163++) {
    c2_B[c2_i163] = 0.0;
  }

  c2_nn = 0;
  while (c2_nn < 4) {
    c2_b_nn = 1.0 + (real_T)c2_nn;
    c2_c_nn = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c2_b_nn), 1, 4, 2, 0) - 1;
    for (c2_i164 = 0; c2_i164 < 2; c2_i164++) {
      c2_b[c2_i164] = c2_B_B[c2_i164 + (c2_c_nn << 1)];
    }

    c2_eml_scalar_eg(chartInstance);
    c2_eml_scalar_eg(chartInstance);
    for (c2_i165 = 0; c2_i165 < 2; c2_i165++) {
      c2_r[c2_i165] = 0.0;
      c2_i166 = 0;
      for (c2_i167 = 0; c2_i167 < 2; c2_i167++) {
        c2_r[c2_i165] += c2_Rbi_B1[c2_i166 + c2_i165] * c2_b[c2_i167];
        c2_i166 += 2;
      }
    }

    c2_d_nn = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c2_b_nn), 1, 5, 2, 0) - 1;
    for (c2_i168 = 0; c2_i168 < 2; c2_i168++) {
      c2_B[c2_i168 + (c2_d_nn << 1)] = c2_cm_b[c2_i168] + c2_r[c2_i168];
    }

    c2_nn++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  for (c2_i169 = 0; c2_i169 < 2; c2_i169++) {
    c2_b[c2_i169] = c2_B_B[c2_i169];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i170 = 0; c2_i170 < 2; c2_i170++) {
    c2_r[c2_i170] = 0.0;
    c2_i171 = 0;
    for (c2_i172 = 0; c2_i172 < 2; c2_i172++) {
      c2_r[c2_i170] += c2_Rbi_B1[c2_i171 + c2_i170] * c2_b[c2_i172];
      c2_i171 += 2;
    }
  }

  for (c2_i173 = 0; c2_i173 < 2; c2_i173++) {
    c2_B[c2_i173 + 8] = c2_cm_b[c2_i173] + c2_r[c2_i173];
  }

  for (c2_i174 = 0; c2_i174 < 2; c2_i174++) {
    c2_b[c2_i174] = c2_dock_sensA[c2_i174];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i175 = 0; c2_i175 < 2; c2_i175++) {
    c2_r[c2_i175] = 0.0;
    c2_i176 = 0;
    for (c2_i177 = 0; c2_i177 < 2; c2_i177++) {
      c2_r[c2_i175] += c2_Rbi_A1[c2_i176 + c2_i175] * c2_b[c2_i177];
      c2_i176 += 2;
    }
  }

  for (c2_i178 = 0; c2_i178 < 2; c2_i178++) {
    c2_cm_a[c2_i178] += c2_r[c2_i178];
  }

  for (c2_i179 = 0; c2_i179 < 2; c2_i179++) {
    c2_b[c2_i179] = c2_dock_sensB[c2_i179];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i180 = 0; c2_i180 < 2; c2_i180++) {
    c2_r[c2_i180] = 0.0;
    c2_i181 = 0;
    for (c2_i182 = 0; c2_i182 < 2; c2_i182++) {
      c2_r[c2_i180] += c2_Rbi_B1[c2_i181 + c2_i180] * c2_b[c2_i182];
      c2_i181 += 2;
    }
  }

  for (c2_i183 = 0; c2_i183 < 2; c2_i183++) {
    c2_cm_b[c2_i183] += c2_r[c2_i183];
  }

  for (c2_i184 = 0; c2_i184 < 2; c2_i184++) {
    c2_SS[c2_i184] = c2_cm_a[c2_i184];
  }

  for (c2_i185 = 0; c2_i185 < 2; c2_i185++) {
    c2_SS[c2_i185 + 2] = c2_cm_b[c2_i185];
  }

  for (c2_i186 = 0; c2_i186 < 2; c2_i186++) {
    c2_dock_sensA_c[c2_i186] = c2_SS[c2_i186];
  }

  for (c2_i187 = 0; c2_i187 < 2; c2_i187++) {
    c2_dock_sensB_c[c2_i187] = c2_SS[c2_i187 + 2];
  }

  for (c2_i188 = 0; c2_i188 < 14; c2_i188++) {
    c2_A_B[c2_i188] = 0.0;
  }

  for (c2_i189 = 0; c2_i189 < 14; c2_i189++) {
    c2_Qb[c2_i189] = 0.0;
  }

  for (c2_i190 = 0; c2_i190 < 7; c2_i190++) {
    c2_Dist[c2_i190] = 0.0;
  }

  for (c2_i191 = 0; c2_i191 < 4; c2_i191++) {
    c2_dist[c2_i191] = 0.0;
  }

  for (c2_i192 = 0; c2_i192 < 8; c2_i192++) {
    c2_B_B[c2_i192] = 0.0;
  }

  for (c2_i193 = 0; c2_i193 < 8; c2_i193++) {
    c2_min_point_B[c2_i193] = 0.0;
  }

  c2_k = 0;
  while (c2_k < 4) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_i = 0;
    while (c2_i < 7) {
      c2_b_i = 1.0 + (real_T)c2_i;
      c2_c_i = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_b_i + 1.0), 1, 8, 2, 0) - 1;
      c2_d_i = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_b_i), 1, 8, 2, 0) - 1;
      for (c2_i194 = 0; c2_i194 < 2; c2_i194++) {
        c2_cm_a[c2_i194] = c2_A[c2_i194 + (c2_c_i << 1)] - c2_A[c2_i194 +
          (c2_d_i << 1)];
      }

      c2_c_k = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_b_k + 1.0), 1, 5, 2, 0) - 1;
      c2_d_k = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_b_k), 1, 5, 2, 0) - 1;
      for (c2_i195 = 0; c2_i195 < 2; c2_i195++) {
        c2_cm_b[c2_i195] = c2_B[c2_i195 + (c2_c_k << 1)] - c2_B[c2_i195 +
          (c2_d_k << 1)];
      }

      c2_e_i = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_b_i), 1, 8, 2, 0) - 1;
      c2_e_k = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_b_k), 1, 5, 2, 0) - 1;
      for (c2_i196 = 0; c2_i196 < 2; c2_i196++) {
        c2_r[c2_i196] = c2_A[c2_i196 + (c2_e_i << 1)] - c2_B[c2_i196 + (c2_e_k <<
          1)];
      }

      for (c2_i197 = 0; c2_i197 < 2; c2_i197++) {
        c2_b_cm_a[c2_i197] = c2_cm_a[c2_i197];
      }

      for (c2_i198 = 0; c2_i198 < 2; c2_i198++) {
        c2_c_cm_a[c2_i198] = c2_cm_a[c2_i198];
      }

      c2_a = c2_dot(chartInstance, c2_b_cm_a, c2_c_cm_a);
      for (c2_i199 = 0; c2_i199 < 2; c2_i199++) {
        c2_d_cm_a[c2_i199] = c2_cm_a[c2_i199];
      }

      for (c2_i200 = 0; c2_i200 < 2; c2_i200++) {
        c2_b_cm_b[c2_i200] = c2_cm_b[c2_i200];
      }

      c2_b_b = c2_dot(chartInstance, c2_d_cm_a, c2_b_cm_b);
      for (c2_i201 = 0; c2_i201 < 2; c2_i201++) {
        c2_e_cm_a[c2_i201] = c2_cm_a[c2_i201];
      }

      for (c2_i202 = 0; c2_i202 < 2; c2_i202++) {
        c2_b_r[c2_i202] = c2_r[c2_i202];
      }

      c2_c = c2_dot(chartInstance, c2_e_cm_a, c2_b_r);
      for (c2_i203 = 0; c2_i203 < 2; c2_i203++) {
        c2_c_cm_b[c2_i203] = c2_cm_b[c2_i203];
      }

      for (c2_i204 = 0; c2_i204 < 2; c2_i204++) {
        c2_d_cm_b[c2_i204] = c2_cm_b[c2_i204];
      }

      c2_e = c2_dot(chartInstance, c2_c_cm_b, c2_d_cm_b);
      for (c2_i205 = 0; c2_i205 < 2; c2_i205++) {
        c2_e_cm_b[c2_i205] = c2_cm_b[c2_i205];
      }

      for (c2_i206 = 0; c2_i206 < 2; c2_i206++) {
        c2_c_r[c2_i206] = c2_r[c2_i206];
      }

      c2_f = c2_dot(chartInstance, c2_e_cm_b, c2_c_r);
      c2_b_a = c2_a;
      c2_c_b = c2_e;
      c2_y = c2_b_a * c2_c_b;
      c2_c_a = c2_b_b;
      c2_d_b = c2_b_b;
      c2_b_y = c2_c_a * c2_d_b;
      c2_denom = c2_y - c2_b_y;
      if (c2_denom == 0.0) {
        c2_t1 = 0.5;
      } else {
        c2_d_a = c2_b_b;
        c2_e_b = c2_f;
        c2_c_y = c2_d_a * c2_e_b;
        c2_e_a = c2_c;
        c2_f_b = c2_e;
        c2_d_y = c2_e_a * c2_f_b;
        c2_b_A = c2_c_y - c2_d_y;
        c2_b_B = c2_denom;
        c2_x = c2_b_A;
        c2_e_y = c2_b_B;
        c2_b_x = c2_x;
        c2_f_y = c2_e_y;
        c2_t1 = c2_b_x / c2_f_y;
        if (c2_t1 < 0.0) {
          c2_t1 = 0.0;
        } else {
          if (c2_t1 > 1.0) {
            c2_t1 = 1.0;
          }
        }
      }

      c2_f_a = c2_b_b;
      c2_g_b = c2_t1;
      c2_g_y = c2_f_a * c2_g_b;
      c2_c_A = c2_g_y + c2_f;
      c2_c_B = c2_e;
      c2_c_x = c2_c_A;
      c2_h_y = c2_c_B;
      c2_d_x = c2_c_x;
      c2_i_y = c2_h_y;
      c2_t2 = c2_d_x / c2_i_y;
      if (c2_t2 < 0.0) {
        c2_t2 = 0.0;
      } else {
        if (c2_t2 > 1.0) {
          c2_t2 = 1.0;
        }
      }

      c2_g_a = c2_b_b;
      c2_h_b = c2_t2;
      c2_j_y = c2_g_a * c2_h_b;
      c2_d_A = c2_j_y - c2_c;
      c2_d_B = c2_a;
      c2_e_x = c2_d_A;
      c2_k_y = c2_d_B;
      c2_f_x = c2_e_x;
      c2_l_y = c2_k_y;
      c2_t1 = c2_f_x / c2_l_y;
      if (c2_t1 < 0.0) {
        c2_t1 = 0.0;
      } else {
        if (c2_t1 > 1.0) {
          c2_t1 = 1.0;
        }
      }

      c2_h_a = c2_t1;
      c2_f_i = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_b_i + 1.0), 1, 8, 2, 0) - 1;
      c2_g_i = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_b_i), 1, 8, 2, 0) - 1;
      for (c2_i207 = 0; c2_i207 < 2; c2_i207++) {
        c2_b[c2_i207] = c2_A[c2_i207 + (c2_f_i << 1)] - c2_A[c2_i207 + (c2_g_i <<
          1)];
      }

      for (c2_i208 = 0; c2_i208 < 2; c2_i208++) {
        c2_b[c2_i208] *= c2_h_a;
      }

      c2_h_i = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_b_i), 1, 7, 2, 0) - 1;
      c2_i_i = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_b_i), 1, 8, 2, 0) - 1;
      for (c2_i209 = 0; c2_i209 < 2; c2_i209++) {
        c2_A_B[c2_i209 + (c2_h_i << 1)] = c2_A[c2_i209 + (c2_i_i << 1)] +
          c2_b[c2_i209];
      }

      (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c2_b_k + 1.0), 1, 5, 2, 0);
      (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c2_b_k), 1, 5, 2, 0);
      (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c2_b_k), 1, 5, 2, 0);
      (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c2_b_k), 1, 4, 2, 0);
      c2_i_a = c2_t2;
      c2_f_k = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_b_k + 1.0), 1, 5, 2, 0) - 1;
      c2_g_k = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_b_k), 1, 5, 2, 0) - 1;
      for (c2_i210 = 0; c2_i210 < 2; c2_i210++) {
        c2_b[c2_i210] = c2_B[c2_i210 + (c2_f_k << 1)] - c2_B[c2_i210 + (c2_g_k <<
          1)];
      }

      for (c2_i211 = 0; c2_i211 < 2; c2_i211++) {
        c2_b[c2_i211] *= c2_i_a;
      }

      c2_j_i = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_b_i), 1, 7, 2, 0) - 1;
      c2_h_k = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_b_k), 1, 5, 2, 0) - 1;
      for (c2_i212 = 0; c2_i212 < 2; c2_i212++) {
        c2_Qb[c2_i212 + (c2_j_i << 1)] = c2_B[c2_i212 + (c2_h_k << 1)] +
          c2_b[c2_i212];
      }

      c2_k_i = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_b_i), 1, 7, 2, 0) - 1;
      c2_l_i = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_b_i), 1, 7, 2, 0) - 1;
      for (c2_i213 = 0; c2_i213 < 2; c2_i213++) {
        c2_b_Qb[c2_i213] = c2_Qb[c2_i213 + (c2_k_i << 1)] - c2_A_B[c2_i213 +
          (c2_l_i << 1)];
      }

      c2_Dist[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_b_i), 1, 7, 1, 0) - 1] = c2_norm(chartInstance,
        c2_b_Qb);
      c2_i++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    c2_ixstart = 1;
    c2_mtmp = c2_Dist[0];
    c2_itmp = 1;
    c2_g_x = c2_mtmp;
    c2_i_b = muDoubleScalarIsNaN(c2_g_x);
    if (c2_i_b) {
      c2_ix = 2;
      exitg2 = FALSE;
      while ((exitg2 == FALSE) && (c2_ix < 8)) {
        c2_b_ix = c2_ix;
        c2_ixstart = c2_b_ix;
        c2_h_x = c2_Dist[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_b_ix), 1, 7, 1, 0) - 1];
        c2_j_b = muDoubleScalarIsNaN(c2_h_x);
        if (!c2_j_b) {
          c2_mtmp = c2_Dist[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_b_ix), 1, 7, 1, 0) - 1];
          c2_itmp = c2_b_ix;
          exitg2 = TRUE;
        } else {
          c2_ix++;
        }
      }
    }

    if (c2_ixstart < 7) {
      c2_j_a = c2_ixstart;
      c2_i214 = c2_j_a;
      c2_overflow = FALSE;
      if (c2_overflow) {
        c2_check_forloop_overflow_error(chartInstance, c2_overflow);
      }

      for (c2_c_ix = c2_i214 + 1; c2_c_ix < 8; c2_c_ix++) {
        c2_b_ix = c2_c_ix;
        c2_k_a = c2_Dist[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_b_ix), 1, 7, 1, 0) - 1];
        c2_k_b = c2_mtmp;
        c2_p = (c2_k_a < c2_k_b);
        if (c2_p) {
          c2_mtmp = c2_Dist[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_b_ix), 1, 7, 1, 0) - 1];
          c2_itmp = c2_b_ix;
        }
      }
    }

    c2_b_itmp = c2_itmp;
    c2_iindx = c2_b_itmp;
    c2_b_iindx = c2_iindx;
    c2_indx = (real_T)c2_b_iindx;
    c2_i_dist = c2_indx;
    c2_b_i_dist = c2_i_dist;
    c2_i_k = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c2_b_k), 1, 4, 2, 0) - 1;
    c2_c_i_dist = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c2_b_i_dist), 1, 7, 2, 0) - 1;
    for (c2_i215 = 0; c2_i215 < 2; c2_i215++) {
      c2_B_B[c2_i215 + (c2_i_k << 1)] = c2_A_B[c2_i215 + (c2_c_i_dist << 1)];
    }

    c2_j_k = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c2_b_k), 1, 4, 2, 0) - 1;
    c2_d_i_dist = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c2_b_i_dist), 1, 7, 2, 0) - 1;
    for (c2_i216 = 0; c2_i216 < 2; c2_i216++) {
      c2_min_point_B[c2_i216 + (c2_j_k << 1)] = c2_Qb[c2_i216 + (c2_d_i_dist <<
        1)];
    }

    c2_k_k = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c2_b_k), 1, 4, 2, 0) - 1;
    c2_l_k = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c2_b_k), 1, 4, 2, 0) - 1;
    for (c2_i217 = 0; c2_i217 < 2; c2_i217++) {
      c2_b_min_point_B[c2_i217] = c2_min_point_B[c2_i217 + (c2_k_k << 1)] -
        c2_B_B[c2_i217 + (c2_l_k << 1)];
    }

    c2_dist[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c2_b_k), 1, 4, 1, 0) - 1] = c2_norm(chartInstance,
      c2_b_min_point_B);
    c2_k++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  c2_b_ixstart = 1;
  c2_b_mtmp = c2_dist[0];
  c2_c_itmp = 1;
  c2_i_x = c2_b_mtmp;
  c2_l_b = muDoubleScalarIsNaN(c2_i_x);
  if (c2_l_b) {
    c2_d_ix = 2;
    exitg1 = FALSE;
    while ((exitg1 == FALSE) && (c2_d_ix < 5)) {
      c2_e_ix = c2_d_ix;
      c2_b_ixstart = c2_e_ix;
      c2_j_x = c2_dist[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c2_e_ix), 1, 4, 1, 0) - 1];
      c2_m_b = muDoubleScalarIsNaN(c2_j_x);
      if (!c2_m_b) {
        c2_b_mtmp = c2_dist[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_e_ix), 1, 4, 1, 0) - 1];
        c2_c_itmp = c2_e_ix;
        exitg1 = TRUE;
      } else {
        c2_d_ix++;
      }
    }
  }

  if (c2_b_ixstart < 4) {
    c2_l_a = c2_b_ixstart;
    c2_i218 = c2_l_a;
    c2_b_overflow = FALSE;
    if (c2_b_overflow) {
      c2_b_check_forloop_overflow_error(chartInstance, c2_b_overflow);
    }

    for (c2_f_ix = c2_i218 + 1; c2_f_ix < 5; c2_f_ix++) {
      c2_e_ix = c2_f_ix;
      c2_m_a = c2_dist[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c2_e_ix), 1, 4, 1, 0) - 1];
      c2_n_b = c2_b_mtmp;
      c2_b_p = (c2_m_a < c2_n_b);
      if (c2_b_p) {
        c2_b_mtmp = c2_dist[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_e_ix), 1, 4, 1, 0) - 1];
        c2_c_itmp = c2_e_ix;
      }
    }
  }

  c2_c_mtmp = c2_b_mtmp;
  c2_d_itmp = c2_c_itmp;
  c2_extremum = c2_c_mtmp;
  c2_c_iindx = c2_d_itmp;
  c2_minval = c2_extremum;
  c2_d_iindx = c2_c_iindx;
  c2_b_indx = (real_T)c2_d_iindx;
  c2_dist_f_value = c2_minval;
  c2_kk_dist = c2_b_indx;
  c2_b_dist_f_value = c2_dist_f_value;
  c2_b_kk_dist = c2_kk_dist;
  c2_c_kk_dist = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", c2_b_kk_dist), 1, 4, 2, 0) - 1;
  for (c2_i219 = 0; c2_i219 < 2; c2_i219++) {
    c2_QA_c[c2_i219] = c2_B_B[c2_i219 + (c2_c_kk_dist << 1)];
  }

  c2_d_kk_dist = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", c2_b_kk_dist), 1, 4, 2, 0) - 1;
  for (c2_i220 = 0; c2_i220 < 2; c2_i220++) {
    c2_QB_c[c2_i220] = c2_min_point_B[c2_i220 + (c2_d_kk_dist << 1)];
  }

  if (c2_b_dist_f_value < c2_sigma) {
    c2_contact = 1.0;
  } else {
    c2_contact = 0.0;
  }

  c2_e_kk_dist = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", c2_b_kk_dist + 1.0), 1, 5, 2, 0) - 1;
  c2_f_kk_dist = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", c2_b_kk_dist), 1, 5, 2, 0) - 1;
  for (c2_i221 = 0; c2_i221 < 2; c2_i221++) {
    c2_cm_a[c2_i221] = c2_B[c2_i221 + (c2_e_kk_dist << 1)] - c2_B[c2_i221 +
      (c2_f_kk_dist << 1)];
  }

  c2_g_kk_dist = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", c2_b_kk_dist + 1.0), 1, 5, 2, 0) - 1;
  c2_h_kk_dist = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", c2_b_kk_dist), 1, 5, 2, 0) - 1;
  for (c2_i222 = 0; c2_i222 < 2; c2_i222++) {
    c2_e_B[c2_i222] = c2_B[c2_i222 + (c2_g_kk_dist << 1)] - c2_B[c2_i222 +
      (c2_h_kk_dist << 1)];
  }

  c2_f_B = c2_norm(chartInstance, c2_e_B);
  c2_m_y = c2_f_B;
  c2_n_y = c2_m_y;
  for (c2_i223 = 0; c2_i223 < 2; c2_i223++) {
    c2_cm_a[c2_i223] /= c2_n_y;
  }

  c2_f_cm_a[0] = -c2_cm_a[1];
  c2_f_cm_a[1] = c2_cm_a[0];
  for (c2_i224 = 0; c2_i224 < 2; c2_i224++) {
    c2_n_c[c2_i224] = c2_f_cm_a[c2_i224];
  }

  for (c2_i225 = 0; c2_i225 < 2; c2_i225++) {
    c2_Si_a[c2_i225] = c2_dock_sensA_c[c2_i225];
  }

  c2_Si_a[2] = 0.0;
  for (c2_i226 = 0; c2_i226 < 2; c2_i226++) {
    c2_Si_b[c2_i226] = c2_dock_sensB_c[c2_i226];
  }

  c2_Si_b[2] = 0.0;
  c2_x_a = c2_Xcm[0];
  c2_y_a = c2_Xcm[1];
  c2_vx_a = c2_Xcm[2];
  c2_vy_a = c2_Xcm[3];
  c2_w_a = c2_Xcm[4];
  c2_b_x_a[0] = c2_x_a;
  c2_b_x_a[1] = c2_y_a;
  c2_b_x_a[2] = 0.0;
  for (c2_i227 = 0; c2_i227 < 3; c2_i227++) {
    c2_Xcm_a[c2_i227] = c2_b_x_a[c2_i227];
  }

  c2_b_vx_a[0] = c2_vx_a;
  c2_b_vx_a[1] = c2_vy_a;
  c2_b_vx_a[2] = 0.0;
  for (c2_i228 = 0; c2_i228 < 3; c2_i228++) {
    c2_Vcm_a[c2_i228] = c2_b_vx_a[c2_i228];
  }

  c2_dv16[0] = 0.0;
  c2_dv16[1] = 0.0;
  c2_dv16[2] = c2_w_a;
  for (c2_i229 = 0; c2_i229 < 3; c2_i229++) {
    c2_W_a[c2_i229] = c2_dv16[c2_i229];
  }

  c2_x_b = c2_Xcm[5];
  c2_y_b = c2_Xcm[6];
  c2_vx_b = c2_Xcm[7];
  c2_vy_b = c2_Xcm[8];
  c2_w_b = c2_Xcm[9];
  c2_b_x_b[0] = c2_x_b;
  c2_b_x_b[1] = c2_y_b;
  c2_b_x_b[2] = 0.0;
  for (c2_i230 = 0; c2_i230 < 3; c2_i230++) {
    c2_Xcm_b[c2_i230] = c2_b_x_b[c2_i230];
  }

  c2_b_vx_b[0] = c2_vx_b;
  c2_b_vx_b[1] = c2_vy_b;
  c2_b_vx_b[2] = 0.0;
  for (c2_i231 = 0; c2_i231 < 3; c2_i231++) {
    c2_Vcm_b[c2_i231] = c2_b_vx_b[c2_i231];
  }

  c2_dv17[0] = 0.0;
  c2_dv17[1] = 0.0;
  c2_dv17[2] = c2_w_b;
  for (c2_i232 = 0; c2_i232 < 3; c2_i232++) {
    c2_W_b[c2_i232] = c2_dv17[c2_i232];
  }

  for (c2_i233 = 0; c2_i233 < 3; c2_i233++) {
    c2_Xcm_a[c2_i233] = c2_Si_a[c2_i233] - c2_Xcm_a[c2_i233];
  }

  for (c2_i234 = 0; c2_i234 < 3; c2_i234++) {
    c2_Xcm_b[c2_i234] = c2_Si_b[c2_i234] - c2_Xcm_b[c2_i234];
  }

  for (c2_i235 = 0; c2_i235 < 3; c2_i235++) {
    c2_b_W_a[c2_i235] = c2_W_a[c2_i235];
  }

  for (c2_i236 = 0; c2_i236 < 3; c2_i236++) {
    c2_b_Xcm_a[c2_i236] = c2_Xcm_a[c2_i236];
  }

  c2_cross(chartInstance, c2_b_W_a, c2_b_Xcm_a, c2_dv18);
  for (c2_i237 = 0; c2_i237 < 3; c2_i237++) {
    c2_Vcm_a[c2_i237] += c2_dv18[c2_i237];
  }

  for (c2_i238 = 0; c2_i238 < 3; c2_i238++) {
    c2_b_W_b[c2_i238] = c2_W_b[c2_i238];
  }

  for (c2_i239 = 0; c2_i239 < 3; c2_i239++) {
    c2_b_Xcm_b[c2_i239] = c2_Xcm_b[c2_i239];
  }

  c2_cross(chartInstance, c2_b_W_b, c2_b_Xcm_b, c2_dv18);
  for (c2_i240 = 0; c2_i240 < 3; c2_i240++) {
    c2_Vcm_b[c2_i240] += c2_dv18[c2_i240];
  }

  for (c2_i241 = 0; c2_i241 < 3; c2_i241++) {
    c2_b_Si_a[c2_i241] = c2_Si_a[c2_i241] - c2_Si_b[c2_i241];
  }

  guard2 = FALSE;
  if (c2_b_norm(chartInstance, c2_b_Si_a) < c2_sigma_dock) {
    for (c2_i242 = 0; c2_i242 < 3; c2_i242++) {
      c2_b_Vcm_a[c2_i242] = c2_Vcm_a[c2_i242] - c2_Vcm_b[c2_i242];
    }

    if (c2_b_norm(chartInstance, c2_b_Vcm_a) <= c2_dotsigma_dock) {
      *c2_docking = 1.0;
    } else {
      guard2 = TRUE;
    }
  } else {
    guard2 = TRUE;
  }

  if (guard2 == TRUE) {
    *c2_docking = 0.0;
  }

  c2_ma = c2_ma_mb_Ia_Ib[0];
  c2_mb = c2_ma_mb_Ia_Ib[1];
  c2_Ia = c2_ma_mb_Ia_Ib[2];
  c2_Ib = c2_ma_mb_Ia_Ib[3];
  for (c2_i243 = 0; c2_i243 < 2; c2_i243++) {
    c2_Si_a[c2_i243] = c2_QA_c[c2_i243];
  }

  c2_Si_a[2] = 0.0;
  for (c2_i244 = 0; c2_i244 < 2; c2_i244++) {
    c2_Si_b[c2_i244] = c2_QB_c[c2_i244];
  }

  c2_Si_b[2] = 0.0;
  for (c2_i245 = 0; c2_i245 < 2; c2_i245++) {
    c2_N_cb[c2_i245] = c2_n_c[c2_i245];
  }

  c2_N_cb[2] = 0.0;
  c2_c_x_a[0] = c2_x_a;
  c2_c_x_a[1] = c2_y_a;
  c2_c_x_a[2] = 0.0;
  for (c2_i246 = 0; c2_i246 < 3; c2_i246++) {
    c2_Xcm_a[c2_i246] = c2_c_x_a[c2_i246];
  }

  c2_c_vx_a[0] = c2_vx_a;
  c2_c_vx_a[1] = c2_vy_a;
  c2_c_vx_a[2] = 0.0;
  for (c2_i247 = 0; c2_i247 < 3; c2_i247++) {
    c2_Vcm_a[c2_i247] = c2_c_vx_a[c2_i247];
  }

  c2_dv19[0] = 0.0;
  c2_dv19[1] = 0.0;
  c2_dv19[2] = c2_w_a;
  for (c2_i248 = 0; c2_i248 < 3; c2_i248++) {
    c2_W_a[c2_i248] = c2_dv19[c2_i248];
  }

  c2_c_x_b[0] = c2_x_b;
  c2_c_x_b[1] = c2_y_b;
  c2_c_x_b[2] = 0.0;
  for (c2_i249 = 0; c2_i249 < 3; c2_i249++) {
    c2_Xcm_b[c2_i249] = c2_c_x_b[c2_i249];
  }

  c2_c_vx_b[0] = c2_vx_b;
  c2_c_vx_b[1] = c2_vy_b;
  c2_c_vx_b[2] = 0.0;
  for (c2_i250 = 0; c2_i250 < 3; c2_i250++) {
    c2_Vcm_b[c2_i250] = c2_c_vx_b[c2_i250];
  }

  c2_dv20[0] = 0.0;
  c2_dv20[1] = 0.0;
  c2_dv20[2] = c2_w_b;
  for (c2_i251 = 0; c2_i251 < 3; c2_i251++) {
    c2_W_b[c2_i251] = c2_dv20[c2_i251];
  }

  for (c2_i252 = 0; c2_i252 < 3; c2_i252++) {
    c2_Xcm_a[c2_i252] = c2_Si_a[c2_i252] - c2_Xcm_a[c2_i252];
  }

  for (c2_i253 = 0; c2_i253 < 3; c2_i253++) {
    c2_Xcm_b[c2_i253] = c2_Si_b[c2_i253] - c2_Xcm_b[c2_i253];
  }

  for (c2_i254 = 0; c2_i254 < 3; c2_i254++) {
    c2_c_W_a[c2_i254] = c2_W_a[c2_i254];
  }

  for (c2_i255 = 0; c2_i255 < 3; c2_i255++) {
    c2_c_Xcm_a[c2_i255] = c2_Xcm_a[c2_i255];
  }

  c2_cross(chartInstance, c2_c_W_a, c2_c_Xcm_a, c2_Va_c);
  for (c2_i256 = 0; c2_i256 < 3; c2_i256++) {
    c2_Va_c[c2_i256] += c2_Vcm_a[c2_i256];
  }

  for (c2_i257 = 0; c2_i257 < 3; c2_i257++) {
    c2_c_W_b[c2_i257] = c2_W_b[c2_i257];
  }

  for (c2_i258 = 0; c2_i258 < 3; c2_i258++) {
    c2_c_Xcm_b[c2_i258] = c2_Xcm_b[c2_i258];
  }

  c2_cross(chartInstance, c2_c_W_b, c2_c_Xcm_b, c2_Si_a);
  for (c2_i259 = 0; c2_i259 < 3; c2_i259++) {
    c2_Si_a[c2_i259] += c2_Vcm_b[c2_i259];
  }

  for (c2_i260 = 0; c2_i260 < 3; c2_i260++) {
    c2_Va_c[c2_i260] -= c2_Si_a[c2_i260];
  }

  for (c2_i261 = 0; c2_i261 < 3; c2_i261++) {
    c2_j[c2_i261] = 0.0;
  }

  for (c2_i262 = 0; c2_i262 < 3; c2_i262++) {
    c2_Vcm_an[c2_i262] = 0.0;
  }

  for (c2_i263 = 0; c2_i263 < 3; c2_i263++) {
    c2_W_an[c2_i263] = 0.0;
  }

  for (c2_i264 = 0; c2_i264 < 3; c2_i264++) {
    c2_Vcm_bn[c2_i264] = 0.0;
  }

  for (c2_i265 = 0; c2_i265 < 3; c2_i265++) {
    c2_W_bn[c2_i265] = 0.0;
  }

  guard1 = FALSE;
  if (c2_contact == 1.0) {
    for (c2_i266 = 0; c2_i266 < 3; c2_i266++) {
      c2_b_Va_c[c2_i266] = c2_Va_c[c2_i266];
    }

    for (c2_i267 = 0; c2_i267 < 3; c2_i267++) {
      c2_b_N_cb[c2_i267] = c2_N_cb[c2_i267];
    }

    if (c2_b_dot(chartInstance, c2_b_Va_c, c2_b_N_cb) <= 0.0) {
      c2_g_B = c2_ma;
      c2_o_y = c2_g_B;
      c2_p_y = c2_o_y;
      c2_q_y = 1.0 / c2_p_y;
      c2_h_B = c2_mb;
      c2_r_y = c2_h_B;
      c2_s_y = c2_r_y;
      c2_t_y = 1.0 / c2_s_y;
      c2_e_A = c2_Ia;
      for (c2_i268 = 0; c2_i268 < 3; c2_i268++) {
        c2_d_Xcm_a[c2_i268] = c2_Xcm_a[c2_i268];
      }

      for (c2_i269 = 0; c2_i269 < 3; c2_i269++) {
        c2_c_N_cb[c2_i269] = c2_N_cb[c2_i269];
      }

      c2_cross(chartInstance, c2_d_Xcm_a, c2_c_N_cb, c2_dv18);
      for (c2_i270 = 0; c2_i270 < 3; c2_i270++) {
        c2_dv21[c2_i270] = c2_dv18[c2_i270];
      }

      for (c2_i271 = 0; c2_i271 < 3; c2_i271++) {
        c2_e_Xcm_a[c2_i271] = c2_Xcm_a[c2_i271];
      }

      c2_cross(chartInstance, c2_dv21, c2_e_Xcm_a, c2_Si_b);
      c2_u_y = c2_e_A;
      c2_v_y = c2_u_y;
      for (c2_i272 = 0; c2_i272 < 3; c2_i272++) {
        c2_Si_b[c2_i272] /= c2_v_y;
      }

      c2_f_A = c2_Ib;
      for (c2_i273 = 0; c2_i273 < 3; c2_i273++) {
        c2_d_Xcm_b[c2_i273] = c2_Xcm_b[c2_i273];
      }

      for (c2_i274 = 0; c2_i274 < 3; c2_i274++) {
        c2_d_N_cb[c2_i274] = c2_N_cb[c2_i274];
      }

      c2_cross(chartInstance, c2_d_Xcm_b, c2_d_N_cb, c2_dv18);
      for (c2_i275 = 0; c2_i275 < 3; c2_i275++) {
        c2_dv22[c2_i275] = c2_dv18[c2_i275];
      }

      for (c2_i276 = 0; c2_i276 < 3; c2_i276++) {
        c2_e_Xcm_b[c2_i276] = c2_Xcm_b[c2_i276];
      }

      c2_cross(chartInstance, c2_dv22, c2_e_Xcm_b, c2_Si_a);
      c2_w_y = c2_f_A;
      c2_x_y = c2_w_y;
      for (c2_i277 = 0; c2_i277 < 3; c2_i277++) {
        c2_Si_a[c2_i277] /= c2_x_y;
      }

      for (c2_i278 = 0; c2_i278 < 3; c2_i278++) {
        c2_b_Si_b[c2_i278] = c2_Si_b[c2_i278] + c2_Si_a[c2_i278];
      }

      for (c2_i279 = 0; c2_i279 < 3; c2_i279++) {
        c2_e_N_cb[c2_i279] = c2_N_cb[c2_i279];
      }

      c2_kn = (c2_q_y + c2_t_y) + c2_b_dot(chartInstance, c2_b_Si_b, c2_e_N_cb);
      for (c2_i280 = 0; c2_i280 < 3; c2_i280++) {
        c2_c_Va_c[c2_i280] = c2_Va_c[c2_i280];
      }

      for (c2_i281 = 0; c2_i281 < 3; c2_i281++) {
        c2_f_N_cb[c2_i281] = c2_N_cb[c2_i281];
      }

      c2_n_a = -c2_b_dot(chartInstance, c2_c_Va_c, c2_f_N_cb);
      c2_o_b = 1.0 + c2_epsilon;
      c2_y_y = c2_n_a * c2_o_b;
      c2_g_A = c2_y_y;
      c2_i_B = c2_kn;
      c2_k_x = c2_g_A;
      c2_ab_y = c2_i_B;
      c2_l_x = c2_k_x;
      c2_bb_y = c2_ab_y;
      c2_jn = c2_l_x / c2_bb_y;
      c2_o_a = c2_jn;
      for (c2_i282 = 0; c2_i282 < 3; c2_i282++) {
        c2_j[c2_i282] = c2_o_a * c2_N_cb[c2_i282];
      }

      c2_j_B = c2_ma;
      c2_cb_y = c2_j_B;
      c2_db_y = c2_cb_y;
      for (c2_i283 = 0; c2_i283 < 3; c2_i283++) {
        c2_Vcm_an[c2_i283] = c2_j[c2_i283] / c2_db_y;
      }

      for (c2_i284 = 0; c2_i284 < 3; c2_i284++) {
        c2_Vcm_an[c2_i284] += c2_Vcm_a[c2_i284];
      }

      c2_h_A = c2_Ia;
      for (c2_i285 = 0; c2_i285 < 3; c2_i285++) {
        c2_f_Xcm_a[c2_i285] = c2_Xcm_a[c2_i285];
      }

      for (c2_i286 = 0; c2_i286 < 3; c2_i286++) {
        c2_b_j[c2_i286] = c2_j[c2_i286];
      }

      c2_cross(chartInstance, c2_f_Xcm_a, c2_b_j, c2_W_an);
      c2_eb_y = c2_h_A;
      c2_fb_y = c2_eb_y;
      for (c2_i287 = 0; c2_i287 < 3; c2_i287++) {
        c2_W_an[c2_i287] /= c2_fb_y;
      }

      for (c2_i288 = 0; c2_i288 < 3; c2_i288++) {
        c2_W_an[c2_i288] += c2_W_a[c2_i288];
      }

      c2_k_B = c2_mb;
      c2_gb_y = c2_k_B;
      c2_hb_y = c2_gb_y;
      for (c2_i289 = 0; c2_i289 < 3; c2_i289++) {
        c2_Vcm_bn[c2_i289] = c2_j[c2_i289] / c2_hb_y;
      }

      for (c2_i290 = 0; c2_i290 < 3; c2_i290++) {
        c2_Vcm_bn[c2_i290] = c2_Vcm_b[c2_i290] - c2_Vcm_bn[c2_i290];
      }

      c2_i_A = c2_Ib;
      for (c2_i291 = 0; c2_i291 < 3; c2_i291++) {
        c2_f_Xcm_b[c2_i291] = c2_Xcm_b[c2_i291];
      }

      for (c2_i292 = 0; c2_i292 < 3; c2_i292++) {
        c2_c_j[c2_i292] = c2_j[c2_i292];
      }

      c2_cross(chartInstance, c2_f_Xcm_b, c2_c_j, c2_W_bn);
      c2_ib_y = c2_i_A;
      c2_jb_y = c2_ib_y;
      for (c2_i293 = 0; c2_i293 < 3; c2_i293++) {
        c2_W_bn[c2_i293] /= c2_jb_y;
      }

      for (c2_i294 = 0; c2_i294 < 3; c2_i294++) {
        c2_W_bn[c2_i294] = c2_W_b[c2_i294] - c2_W_bn[c2_i294];
      }

      *c2_collision = 1.0;
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    *c2_collision = 0.0;
  }
}

static void c2_eml_scalar_eg(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance)
{
}

static real_T c2_dot(SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance,
                     real_T c2_a[2], real_T c2_b[2])
{
  real_T c2_c;
  int32_T c2_k;
  int32_T c2_b_k;
  c2_b_eml_scalar_eg(chartInstance);
  c2_b_eml_scalar_eg(chartInstance);
  c2_c = 0.0;
  for (c2_k = 1; c2_k < 3; c2_k++) {
    c2_b_k = c2_k;
    c2_c += c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_b_k), 1, 2, 1, 0) - 1] * c2_b[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 2, 1, 0) - 1];
  }

  return c2_c;
}

static void c2_b_eml_scalar_eg(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance)
{
}

static real_T c2_norm(SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance,
                      real_T c2_x[2])
{
  real_T c2_y;
  real_T c2_scale;
  int32_T c2_k;
  int32_T c2_b_k;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_absxk;
  real_T c2_t;
  c2_y = 0.0;
  c2_realmin(chartInstance);
  c2_scale = 2.2250738585072014E-308;
  for (c2_k = 1; c2_k < 3; c2_k++) {
    c2_b_k = c2_k;
    c2_b_x = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_b_k), 1, 2, 1, 0) - 1];
    c2_c_x = c2_b_x;
    c2_absxk = muDoubleScalarAbs(c2_c_x);
    if (c2_absxk > c2_scale) {
      c2_t = c2_scale / c2_absxk;
      c2_y = 1.0 + c2_y * c2_t * c2_t;
      c2_scale = c2_absxk;
    } else {
      c2_t = c2_absxk / c2_scale;
      c2_y += c2_t * c2_t;
    }
  }

  return c2_scale * muDoubleScalarSqrt(c2_y);
}

static void c2_realmin(SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance)
{
}

static void c2_check_forloop_overflow_error
  (SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance, boolean_T c2_overflow)
{
  int32_T c2_i295;
  static char_T c2_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c2_u[34];
  const mxArray *c2_y = NULL;
  int32_T c2_i296;
  static char_T c2_cv1[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't', 'e',
    'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  char_T c2_b_u[23];
  const mxArray *c2_b_y = NULL;
  if (!c2_overflow) {
  } else {
    for (c2_i295 = 0; c2_i295 < 34; c2_i295++) {
      c2_u[c2_i295] = c2_cv0[c2_i295];
    }

    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c2_i296 = 0; c2_i296 < 23; c2_i296++) {
      c2_b_u[c2_i296] = c2_cv1[c2_i296];
    }

    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 23),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c2_y, 14, c2_b_y));
  }
}

static void c2_b_check_forloop_overflow_error
  (SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance, boolean_T c2_overflow)
{
  int32_T c2_i297;
  static char_T c2_cv2[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c2_u[34];
  const mxArray *c2_y = NULL;
  int32_T c2_i298;
  static char_T c2_cv3[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't', 'e',
    'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  char_T c2_b_u[23];
  const mxArray *c2_b_y = NULL;
  if (!c2_overflow) {
  } else {
    for (c2_i297 = 0; c2_i297 < 34; c2_i297++) {
      c2_u[c2_i297] = c2_cv2[c2_i297];
    }

    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c2_i298 = 0; c2_i298 < 23; c2_i298++) {
      c2_b_u[c2_i298] = c2_cv3[c2_i298];
    }

    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 23),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c2_y, 14, c2_b_y));
  }
}

static void c2_cross(SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance,
                     real_T c2_a[3], real_T c2_b[3], real_T c2_c[3])
{
  real_T c2_b_a;
  real_T c2_b_b;
  real_T c2_y;
  real_T c2_c_a;
  real_T c2_c_b;
  real_T c2_b_y;
  real_T c2_c1;
  real_T c2_d_a;
  real_T c2_d_b;
  real_T c2_c_y;
  real_T c2_e_a;
  real_T c2_e_b;
  real_T c2_d_y;
  real_T c2_c2;
  real_T c2_f_a;
  real_T c2_f_b;
  real_T c2_e_y;
  real_T c2_g_a;
  real_T c2_g_b;
  real_T c2_f_y;
  real_T c2_c3;
  c2_b_a = c2_a[1];
  c2_b_b = c2_b[2];
  c2_y = c2_b_a * c2_b_b;
  c2_c_a = c2_a[2];
  c2_c_b = c2_b[1];
  c2_b_y = c2_c_a * c2_c_b;
  c2_c1 = c2_y - c2_b_y;
  c2_d_a = c2_a[2];
  c2_d_b = c2_b[0];
  c2_c_y = c2_d_a * c2_d_b;
  c2_e_a = c2_a[0];
  c2_e_b = c2_b[2];
  c2_d_y = c2_e_a * c2_e_b;
  c2_c2 = c2_c_y - c2_d_y;
  c2_f_a = c2_a[0];
  c2_f_b = c2_b[1];
  c2_e_y = c2_f_a * c2_f_b;
  c2_g_a = c2_a[1];
  c2_g_b = c2_b[0];
  c2_f_y = c2_g_a * c2_g_b;
  c2_c3 = c2_e_y - c2_f_y;
  c2_c[0] = c2_c1;
  c2_c[1] = c2_c2;
  c2_c[2] = c2_c3;
}

static real_T c2_b_norm(SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance,
  real_T c2_x[3])
{
  real_T c2_y;
  real_T c2_scale;
  int32_T c2_k;
  int32_T c2_b_k;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_absxk;
  real_T c2_t;
  c2_y = 0.0;
  c2_realmin(chartInstance);
  c2_scale = 2.2250738585072014E-308;
  for (c2_k = 1; c2_k < 4; c2_k++) {
    c2_b_k = c2_k;
    c2_b_x = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_b_k), 1, 3, 1, 0) - 1];
    c2_c_x = c2_b_x;
    c2_absxk = muDoubleScalarAbs(c2_c_x);
    if (c2_absxk > c2_scale) {
      c2_t = c2_scale / c2_absxk;
      c2_y = 1.0 + c2_y * c2_t * c2_t;
      c2_scale = c2_absxk;
    } else {
      c2_t = c2_absxk / c2_scale;
      c2_y += c2_t * c2_t;
    }
  }

  return c2_scale * muDoubleScalarSqrt(c2_y);
}

static real_T c2_b_dot(SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance,
  real_T c2_a[3], real_T c2_b[3])
{
  real_T c2_c;
  int32_T c2_k;
  int32_T c2_b_k;
  c2_c_eml_scalar_eg(chartInstance);
  c2_c_eml_scalar_eg(chartInstance);
  c2_c = 0.0;
  for (c2_k = 1; c2_k < 4; c2_k++) {
    c2_b_k = c2_k;
    c2_c += c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_b_k), 1, 3, 1, 0) - 1] * c2_b[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 3, 1, 0) - 1];
  }

  return c2_c;
}

static void c2_c_eml_scalar_eg(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance)
{
}

static const mxArray *c2_k_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_k_emlrt_marshallIn(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i299;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i299, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i299;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_EndEffectorVSCube_v2InstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_l_emlrt_marshallIn(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_EndEffectorVSCube_v2, const
  char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_m_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_EndEffectorVSCube_v2), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_EndEffectorVSCube_v2);
  return c2_y;
}

static uint8_T c2_m_emlrt_marshallIn(SFc2_EndEffectorVSCube_v2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_EndEffectorVSCube_v2InstanceStruct
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

void sf_c2_EndEffectorVSCube_v2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1706962023U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2014454667U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4198607345U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(989671544U);
}

mxArray *sf_c2_EndEffectorVSCube_v2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("BhsEsOF5yilbgdXwWeNFWC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,13,3,dataFields);

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
      pr[0] = (double)(2);
      pr[1] = (double)(2);
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
      pr[0] = (double)(2);
      pr[1] = (double)(2);
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
      pr[0] = (double)(9);
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
      pr[0] = (double)(9);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(7);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(4);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,14,3,dataFields);

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
      pr[0] = (double)(2);
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
      pr[0] = (double)(2);
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
      pr[0] = (double)(2);
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
      pr[0] = (double)(2);
      pr[1] = (double)(8);
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
      pr[1] = (double)(5);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_EndEffectorVSCube_v2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c2_EndEffectorVSCube_v2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[13],T\"A\",},{M[1],M[14],T\"B\",},{M[1],M[9],T\"QA_c\",},{M[1],M[10],T\"QB_c\",},{M[1],M[29],T\"Vcm_an\",},{M[1],M[31],T\"Vcm_bn\",},{M[1],M[30],T\"W_an\",},{M[1],M[32],T\"W_bn\",},{M[1],M[28],T\"collision\",},{M[1],M[23],T\"dock_sensA_c\",}}",
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[36],T\"dock_sensB_c\",},{M[1],M[26],T\"docking\",},{M[1],M[33],T\"j\",},{M[1],M[18],T\"n_c\",},{M[8],M[0],T\"is_active_c2_EndEffectorVSCube_v2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 15, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_EndEffectorVSCube_v2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance;
    chartInstance = (SFc2_EndEffectorVSCube_v2InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _EndEffectorVSCube_v2MachineNumber_,
           2,
           1,
           1,
           27,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"epsilon");
          _SFD_SET_DATA_PROPS(1,2,0,1,"dock_sensA_c");
          _SFD_SET_DATA_PROPS(2,2,0,1,"dock_sensB_c");
          _SFD_SET_DATA_PROPS(3,2,0,1,"n_c");
          _SFD_SET_DATA_PROPS(4,2,0,1,"QA_c");
          _SFD_SET_DATA_PROPS(5,2,0,1,"QB_c");
          _SFD_SET_DATA_PROPS(6,1,1,0,"sigma_dock");
          _SFD_SET_DATA_PROPS(7,1,1,0,"dotsigma_dock");
          _SFD_SET_DATA_PROPS(8,1,1,0,"Rbi_A1");
          _SFD_SET_DATA_PROPS(9,1,1,0,"Rbi_B1");
          _SFD_SET_DATA_PROPS(10,2,0,1,"A");
          _SFD_SET_DATA_PROPS(11,2,0,1,"B");
          _SFD_SET_DATA_PROPS(12,1,1,0,"Xcm_A");
          _SFD_SET_DATA_PROPS(13,1,1,0,"Xcm_B");
          _SFD_SET_DATA_PROPS(14,1,1,0,"mesh_A");
          _SFD_SET_DATA_PROPS(15,1,1,0,"mesh_B");
          _SFD_SET_DATA_PROPS(16,1,1,0,"dock_sensA");
          _SFD_SET_DATA_PROPS(17,1,1,0,"dock_sensB");
          _SFD_SET_DATA_PROPS(18,1,1,0,"sigma");
          _SFD_SET_DATA_PROPS(19,2,0,1,"docking");
          _SFD_SET_DATA_PROPS(20,1,1,0,"ma_mb_Ia_Ib");
          _SFD_SET_DATA_PROPS(21,2,0,1,"collision");
          _SFD_SET_DATA_PROPS(22,2,0,1,"Vcm_an");
          _SFD_SET_DATA_PROPS(23,2,0,1,"Vcm_bn");
          _SFD_SET_DATA_PROPS(24,2,0,1,"W_an");
          _SFD_SET_DATA_PROPS(25,2,0,1,"W_bn");
          _SFD_SET_DATA_PROPS(26,2,0,1,"j");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,446);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_e_sf_marshallOut,(MexInFcnForType)
            c2_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_e_sf_marshallOut,(MexInFcnForType)
            c2_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_e_sf_marshallOut,(MexInFcnForType)
            c2_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_e_sf_marshallOut,(MexInFcnForType)
            c2_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_e_sf_marshallOut,(MexInFcnForType)
            c2_e_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_j_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_j_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 8;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)
            c2_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)
            c2_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 9;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_i_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 9;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_i_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 7;
          _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_h_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_g_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          real_T *c2_epsilon;
          real_T *c2_sigma_dock;
          real_T *c2_dotsigma_dock;
          real_T *c2_sigma;
          real_T *c2_docking;
          real_T *c2_collision;
          real_T (*c2_dock_sensA_c)[2];
          real_T (*c2_dock_sensB_c)[2];
          real_T (*c2_n_c)[2];
          real_T (*c2_QA_c)[2];
          real_T (*c2_QB_c)[2];
          real_T (*c2_Rbi_A1)[4];
          real_T (*c2_Rbi_B1)[4];
          real_T (*c2_A)[16];
          real_T (*c2_B)[10];
          real_T (*c2_Xcm_A)[9];
          real_T (*c2_Xcm_B)[9];
          real_T (*c2_mesh_A)[21];
          real_T (*c2_mesh_B)[12];
          real_T (*c2_dock_sensA)[3];
          real_T (*c2_dock_sensB)[3];
          real_T (*c2_ma_mb_Ia_Ib)[4];
          real_T (*c2_Vcm_an)[3];
          real_T (*c2_Vcm_bn)[3];
          real_T (*c2_W_an)[3];
          real_T (*c2_W_bn)[3];
          real_T (*c2_j)[3];
          c2_j = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 14);
          c2_W_bn = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 13);
          c2_W_an = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 12);
          c2_Vcm_bn = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 11);
          c2_Vcm_an = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 10);
          c2_collision = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
          c2_ma_mb_Ia_Ib = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S,
            12);
          c2_docking = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
          c2_sigma = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
          c2_dock_sensB = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S,
            10);
          c2_dock_sensA = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S,
            9);
          c2_mesh_B = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 8);
          c2_mesh_A = (real_T (*)[21])ssGetInputPortSignal(chartInstance->S, 7);
          c2_Xcm_B = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 6);
          c2_Xcm_A = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 5);
          c2_B = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 7);
          c2_A = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 6);
          c2_Rbi_B1 = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 4);
          c2_Rbi_A1 = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 3);
          c2_dotsigma_dock = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_sigma_dock = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_QB_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 5);
          c2_QA_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 4);
          c2_n_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 3);
          c2_dock_sensB_c = (real_T (*)[2])ssGetOutputPortSignal
            (chartInstance->S, 2);
          c2_dock_sensA_c = (real_T (*)[2])ssGetOutputPortSignal
            (chartInstance->S, 1);
          c2_epsilon = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_epsilon);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_dock_sensA_c);
          _SFD_SET_DATA_VALUE_PTR(2U, *c2_dock_sensB_c);
          _SFD_SET_DATA_VALUE_PTR(3U, *c2_n_c);
          _SFD_SET_DATA_VALUE_PTR(4U, *c2_QA_c);
          _SFD_SET_DATA_VALUE_PTR(5U, *c2_QB_c);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_sigma_dock);
          _SFD_SET_DATA_VALUE_PTR(7U, c2_dotsigma_dock);
          _SFD_SET_DATA_VALUE_PTR(8U, *c2_Rbi_A1);
          _SFD_SET_DATA_VALUE_PTR(9U, *c2_Rbi_B1);
          _SFD_SET_DATA_VALUE_PTR(10U, *c2_A);
          _SFD_SET_DATA_VALUE_PTR(11U, *c2_B);
          _SFD_SET_DATA_VALUE_PTR(12U, *c2_Xcm_A);
          _SFD_SET_DATA_VALUE_PTR(13U, *c2_Xcm_B);
          _SFD_SET_DATA_VALUE_PTR(14U, *c2_mesh_A);
          _SFD_SET_DATA_VALUE_PTR(15U, *c2_mesh_B);
          _SFD_SET_DATA_VALUE_PTR(16U, *c2_dock_sensA);
          _SFD_SET_DATA_VALUE_PTR(17U, *c2_dock_sensB);
          _SFD_SET_DATA_VALUE_PTR(18U, c2_sigma);
          _SFD_SET_DATA_VALUE_PTR(19U, c2_docking);
          _SFD_SET_DATA_VALUE_PTR(20U, *c2_ma_mb_Ia_Ib);
          _SFD_SET_DATA_VALUE_PTR(21U, c2_collision);
          _SFD_SET_DATA_VALUE_PTR(22U, *c2_Vcm_an);
          _SFD_SET_DATA_VALUE_PTR(23U, *c2_Vcm_bn);
          _SFD_SET_DATA_VALUE_PTR(24U, *c2_W_an);
          _SFD_SET_DATA_VALUE_PTR(25U, *c2_W_bn);
          _SFD_SET_DATA_VALUE_PTR(26U, *c2_j);
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
  return "Wu5mA16AQmqJHQLyjtsNnB";
}

static void sf_opaque_initialize_c2_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_EndEffectorVSCube_v2
    ((SFc2_EndEffectorVSCube_v2InstanceStruct*) chartInstanceVar);
  initialize_c2_EndEffectorVSCube_v2((SFc2_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  enable_c2_EndEffectorVSCube_v2((SFc2_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  disable_c2_EndEffectorVSCube_v2((SFc2_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  sf_c2_EndEffectorVSCube_v2((SFc2_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_EndEffectorVSCube_v2
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_EndEffectorVSCube_v2
    ((SFc2_EndEffectorVSCube_v2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_EndEffectorVSCube_v2();/* state var info */
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

extern void sf_internal_set_sim_state_c2_EndEffectorVSCube_v2(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_EndEffectorVSCube_v2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_EndEffectorVSCube_v2((SFc2_EndEffectorVSCube_v2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_EndEffectorVSCube_v2(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c2_EndEffectorVSCube_v2(S);
}

static void sf_opaque_set_sim_state_c2_EndEffectorVSCube_v2(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c2_EndEffectorVSCube_v2(S, st);
}

static void sf_opaque_terminate_c2_EndEffectorVSCube_v2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_EndEffectorVSCube_v2InstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_EndEffectorVSCube_v2_optimization_info();
    }

    finalize_c2_EndEffectorVSCube_v2((SFc2_EndEffectorVSCube_v2InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_EndEffectorVSCube_v2((SFc2_EndEffectorVSCube_v2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_EndEffectorVSCube_v2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_EndEffectorVSCube_v2
      ((SFc2_EndEffectorVSCube_v2InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_EndEffectorVSCube_v2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_EndEffectorVSCube_v2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,13);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,14);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=14; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 13; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(573710799U));
  ssSetChecksum1(S,(149676815U));
  ssSetChecksum2(S,(1188535029U));
  ssSetChecksum3(S,(3522652785U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_EndEffectorVSCube_v2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_EndEffectorVSCube_v2(SimStruct *S)
{
  SFc2_EndEffectorVSCube_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_EndEffectorVSCube_v2InstanceStruct *)utMalloc(sizeof
    (SFc2_EndEffectorVSCube_v2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_EndEffectorVSCube_v2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_EndEffectorVSCube_v2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_EndEffectorVSCube_v2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_EndEffectorVSCube_v2;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_EndEffectorVSCube_v2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_EndEffectorVSCube_v2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_EndEffectorVSCube_v2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_EndEffectorVSCube_v2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_EndEffectorVSCube_v2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_EndEffectorVSCube_v2;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_EndEffectorVSCube_v2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_EndEffectorVSCube_v2;
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

void c2_EndEffectorVSCube_v2_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_EndEffectorVSCube_v2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_EndEffectorVSCube_v2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_EndEffectorVSCube_v2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_EndEffectorVSCube_v2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
