/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ManipulatorME4901_sfun.h"
#include "c10_ManipulatorME4901.h"
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
static const char * c10_debug_family_names[29] = { "nargin", "nargout",
  "epsilon", "sigma_dock", "dotsigma_dock", "Rbi_A1", "Rbi_B1", "Xcm_A", "Xcm_B",
  "mesh_A", "mesh_B", "dock_sensA", "dock_sensB", "sigma", "ma_mb_Ia_Ib",
  "dock_sensA_c", "dock_sensB_c", "n_c", "QA_c", "QB_c", "A", "B", "docking",
  "collision", "Vcm_an", "Vcm_bn", "W_an", "W_bn", "j" };

/* Function Declarations */
static void initialize_c10_ManipulatorME4901
  (SFc10_ManipulatorME4901InstanceStruct *chartInstance);
static void initialize_params_c10_ManipulatorME4901
  (SFc10_ManipulatorME4901InstanceStruct *chartInstance);
static void enable_c10_ManipulatorME4901(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance);
static void disable_c10_ManipulatorME4901(SFc10_ManipulatorME4901InstanceStruct *
  chartInstance);
static void c10_update_debugger_state_c10_ManipulatorME4901
  (SFc10_ManipulatorME4901InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c10_ManipulatorME4901
  (SFc10_ManipulatorME4901InstanceStruct *chartInstance);
static void set_sim_state_c10_ManipulatorME4901
  (SFc10_ManipulatorME4901InstanceStruct *chartInstance, const mxArray *c10_st);
static void finalize_c10_ManipulatorME4901(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance);
static void sf_c10_ManipulatorME4901(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance);
static void initSimStructsc10_ManipulatorME4901
  (SFc10_ManipulatorME4901InstanceStruct *chartInstance);
static void registerMessagesc10_ManipulatorME4901
  (SFc10_ManipulatorME4901InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber);
static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_emlrt_marshallIn(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c10_j, const char_T *c10_identifier, real_T
  c10_y[3]);
static void c10_b_emlrt_marshallIn(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[3]);
static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static real_T c10_c_emlrt_marshallIn(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c10_collision, const char_T *c10_identifier);
static real_T c10_d_emlrt_marshallIn(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_e_emlrt_marshallIn(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c10_B, const char_T *c10_identifier, real_T
  c10_y[10]);
static void c10_f_emlrt_marshallIn(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[10]);
static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_g_emlrt_marshallIn(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c10_A, const char_T *c10_identifier, real_T
  c10_y[16]);
static void c10_h_emlrt_marshallIn(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[16]);
static void c10_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_e_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_i_emlrt_marshallIn(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c10_QB_c, const char_T *c10_identifier, real_T
  c10_y[2]);
static void c10_j_emlrt_marshallIn(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[2]);
static void c10_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_f_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_g_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_h_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_i_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_j_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_k_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_info_helper(c10_ResolvedFunctionInfo c10_info[70]);
static void c10_collision_function(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, real_T c10_epsilon, real_T c10_sigma_dock, real_T
  c10_dotsigma_dock, real_T c10_Rbi_A1[4], real_T c10_Rbi_B1[4], real_T
  c10_Xcm_A[9], real_T c10_Xcm_B[9], real_T c10_mesh_A[21], real_T c10_mesh_B[12],
  real_T c10_dock_sensA[3], real_T c10_dock_sensB[3], real_T c10_sigma, real_T
  c10_ma_mb_Ia_Ib[4], real_T c10_dock_sensA_c[2], real_T c10_dock_sensB_c[2],
  real_T c10_n_c[2], real_T c10_QA_c[2], real_T c10_QB_c[2], real_T c10_A[16],
  real_T c10_B[10], real_T *c10_docking, real_T *c10_collision, real_T
  c10_Vcm_an[3], real_T c10_Vcm_bn[3], real_T c10_W_an[3], real_T c10_W_bn[3],
  real_T c10_j[3]);
static void c10_eml_scalar_eg(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance);
static real_T c10_dot(SFc10_ManipulatorME4901InstanceStruct *chartInstance,
                      real_T c10_a[2], real_T c10_b[2]);
static void c10_b_eml_scalar_eg(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance);
static real_T c10_norm(SFc10_ManipulatorME4901InstanceStruct *chartInstance,
  real_T c10_x[2]);
static void c10_realmin(SFc10_ManipulatorME4901InstanceStruct *chartInstance);
static void c10_check_forloop_overflow_error
  (SFc10_ManipulatorME4901InstanceStruct *chartInstance, boolean_T c10_overflow);
static void c10_b_check_forloop_overflow_error
  (SFc10_ManipulatorME4901InstanceStruct *chartInstance, boolean_T c10_overflow);
static void c10_cross(SFc10_ManipulatorME4901InstanceStruct *chartInstance,
                      real_T c10_a[3], real_T c10_b[3], real_T c10_c[3]);
static real_T c10_b_norm(SFc10_ManipulatorME4901InstanceStruct *chartInstance,
  real_T c10_x[3]);
static real_T c10_b_dot(SFc10_ManipulatorME4901InstanceStruct *chartInstance,
  real_T c10_a[3], real_T c10_b[3]);
static void c10_c_eml_scalar_eg(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance);
static const mxArray *c10_l_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static int32_T c10_k_emlrt_marshallIn(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static uint8_T c10_l_emlrt_marshallIn(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c10_b_is_active_c10_ManipulatorME4901, const
  char_T *c10_identifier);
static uint8_T c10_m_emlrt_marshallIn(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void init_dsm_address_info(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c10_ManipulatorME4901
  (SFc10_ManipulatorME4901InstanceStruct *chartInstance)
{
  chartInstance->c10_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c10_is_active_c10_ManipulatorME4901 = 0U;
}

static void initialize_params_c10_ManipulatorME4901
  (SFc10_ManipulatorME4901InstanceStruct *chartInstance)
{
}

static void enable_c10_ManipulatorME4901(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c10_ManipulatorME4901(SFc10_ManipulatorME4901InstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c10_update_debugger_state_c10_ManipulatorME4901
  (SFc10_ManipulatorME4901InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c10_ManipulatorME4901
  (SFc10_ManipulatorME4901InstanceStruct *chartInstance)
{
  const mxArray *c10_st;
  const mxArray *c10_y = NULL;
  int32_T c10_i0;
  real_T c10_u[16];
  const mxArray *c10_b_y = NULL;
  int32_T c10_i1;
  real_T c10_b_u[10];
  const mxArray *c10_c_y = NULL;
  int32_T c10_i2;
  real_T c10_c_u[2];
  const mxArray *c10_d_y = NULL;
  int32_T c10_i3;
  real_T c10_d_u[2];
  const mxArray *c10_e_y = NULL;
  int32_T c10_i4;
  real_T c10_e_u[3];
  const mxArray *c10_f_y = NULL;
  int32_T c10_i5;
  real_T c10_f_u[3];
  const mxArray *c10_g_y = NULL;
  int32_T c10_i6;
  real_T c10_g_u[3];
  const mxArray *c10_h_y = NULL;
  int32_T c10_i7;
  real_T c10_h_u[3];
  const mxArray *c10_i_y = NULL;
  real_T c10_hoistedGlobal;
  real_T c10_i_u;
  const mxArray *c10_j_y = NULL;
  int32_T c10_i8;
  real_T c10_j_u[2];
  const mxArray *c10_k_y = NULL;
  int32_T c10_i9;
  real_T c10_k_u[2];
  const mxArray *c10_l_y = NULL;
  real_T c10_b_hoistedGlobal;
  real_T c10_l_u;
  const mxArray *c10_m_y = NULL;
  int32_T c10_i10;
  real_T c10_m_u[3];
  const mxArray *c10_n_y = NULL;
  int32_T c10_i11;
  real_T c10_n_u[2];
  const mxArray *c10_o_y = NULL;
  uint8_T c10_c_hoistedGlobal;
  uint8_T c10_o_u;
  const mxArray *c10_p_y = NULL;
  real_T *c10_collision;
  real_T *c10_docking;
  real_T (*c10_n_c)[2];
  real_T (*c10_j)[3];
  real_T (*c10_dock_sensB_c)[2];
  real_T (*c10_dock_sensA_c)[2];
  real_T (*c10_W_bn)[3];
  real_T (*c10_W_an)[3];
  real_T (*c10_Vcm_bn)[3];
  real_T (*c10_Vcm_an)[3];
  real_T (*c10_QB_c)[2];
  real_T (*c10_QA_c)[2];
  real_T (*c10_B)[10];
  real_T (*c10_A)[16];
  c10_j = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 14);
  c10_W_bn = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 13);
  c10_W_an = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 12);
  c10_Vcm_bn = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 11);
  c10_Vcm_an = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 10);
  c10_collision = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c10_docking = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c10_B = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 7);
  c10_A = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 6);
  c10_QB_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 5);
  c10_QA_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 4);
  c10_n_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 3);
  c10_dock_sensB_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 2);
  c10_dock_sensA_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c10_st = NULL;
  c10_st = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createcellarray(15), FALSE);
  for (c10_i0 = 0; c10_i0 < 16; c10_i0++) {
    c10_u[c10_i0] = (*c10_A)[c10_i0];
  }

  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 2, 2, 8),
                FALSE);
  sf_mex_setcell(c10_y, 0, c10_b_y);
  for (c10_i1 = 0; c10_i1 < 10; c10_i1++) {
    c10_b_u[c10_i1] = (*c10_B)[c10_i1];
  }

  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", c10_b_u, 0, 0U, 1U, 0U, 2, 2, 5),
                FALSE);
  sf_mex_setcell(c10_y, 1, c10_c_y);
  for (c10_i2 = 0; c10_i2 < 2; c10_i2++) {
    c10_c_u[c10_i2] = (*c10_QA_c)[c10_i2];
  }

  c10_d_y = NULL;
  sf_mex_assign(&c10_d_y, sf_mex_create("y", c10_c_u, 0, 0U, 1U, 0U, 1, 2),
                FALSE);
  sf_mex_setcell(c10_y, 2, c10_d_y);
  for (c10_i3 = 0; c10_i3 < 2; c10_i3++) {
    c10_d_u[c10_i3] = (*c10_QB_c)[c10_i3];
  }

  c10_e_y = NULL;
  sf_mex_assign(&c10_e_y, sf_mex_create("y", c10_d_u, 0, 0U, 1U, 0U, 1, 2),
                FALSE);
  sf_mex_setcell(c10_y, 3, c10_e_y);
  for (c10_i4 = 0; c10_i4 < 3; c10_i4++) {
    c10_e_u[c10_i4] = (*c10_Vcm_an)[c10_i4];
  }

  c10_f_y = NULL;
  sf_mex_assign(&c10_f_y, sf_mex_create("y", c10_e_u, 0, 0U, 1U, 0U, 1, 3),
                FALSE);
  sf_mex_setcell(c10_y, 4, c10_f_y);
  for (c10_i5 = 0; c10_i5 < 3; c10_i5++) {
    c10_f_u[c10_i5] = (*c10_Vcm_bn)[c10_i5];
  }

  c10_g_y = NULL;
  sf_mex_assign(&c10_g_y, sf_mex_create("y", c10_f_u, 0, 0U, 1U, 0U, 1, 3),
                FALSE);
  sf_mex_setcell(c10_y, 5, c10_g_y);
  for (c10_i6 = 0; c10_i6 < 3; c10_i6++) {
    c10_g_u[c10_i6] = (*c10_W_an)[c10_i6];
  }

  c10_h_y = NULL;
  sf_mex_assign(&c10_h_y, sf_mex_create("y", c10_g_u, 0, 0U, 1U, 0U, 1, 3),
                FALSE);
  sf_mex_setcell(c10_y, 6, c10_h_y);
  for (c10_i7 = 0; c10_i7 < 3; c10_i7++) {
    c10_h_u[c10_i7] = (*c10_W_bn)[c10_i7];
  }

  c10_i_y = NULL;
  sf_mex_assign(&c10_i_y, sf_mex_create("y", c10_h_u, 0, 0U, 1U, 0U, 1, 3),
                FALSE);
  sf_mex_setcell(c10_y, 7, c10_i_y);
  c10_hoistedGlobal = *c10_collision;
  c10_i_u = c10_hoistedGlobal;
  c10_j_y = NULL;
  sf_mex_assign(&c10_j_y, sf_mex_create("y", &c10_i_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c10_y, 8, c10_j_y);
  for (c10_i8 = 0; c10_i8 < 2; c10_i8++) {
    c10_j_u[c10_i8] = (*c10_dock_sensA_c)[c10_i8];
  }

  c10_k_y = NULL;
  sf_mex_assign(&c10_k_y, sf_mex_create("y", c10_j_u, 0, 0U, 1U, 0U, 1, 2),
                FALSE);
  sf_mex_setcell(c10_y, 9, c10_k_y);
  for (c10_i9 = 0; c10_i9 < 2; c10_i9++) {
    c10_k_u[c10_i9] = (*c10_dock_sensB_c)[c10_i9];
  }

  c10_l_y = NULL;
  sf_mex_assign(&c10_l_y, sf_mex_create("y", c10_k_u, 0, 0U, 1U, 0U, 1, 2),
                FALSE);
  sf_mex_setcell(c10_y, 10, c10_l_y);
  c10_b_hoistedGlobal = *c10_docking;
  c10_l_u = c10_b_hoistedGlobal;
  c10_m_y = NULL;
  sf_mex_assign(&c10_m_y, sf_mex_create("y", &c10_l_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c10_y, 11, c10_m_y);
  for (c10_i10 = 0; c10_i10 < 3; c10_i10++) {
    c10_m_u[c10_i10] = (*c10_j)[c10_i10];
  }

  c10_n_y = NULL;
  sf_mex_assign(&c10_n_y, sf_mex_create("y", c10_m_u, 0, 0U, 1U, 0U, 1, 3),
                FALSE);
  sf_mex_setcell(c10_y, 12, c10_n_y);
  for (c10_i11 = 0; c10_i11 < 2; c10_i11++) {
    c10_n_u[c10_i11] = (*c10_n_c)[c10_i11];
  }

  c10_o_y = NULL;
  sf_mex_assign(&c10_o_y, sf_mex_create("y", c10_n_u, 0, 0U, 1U, 0U, 1, 2),
                FALSE);
  sf_mex_setcell(c10_y, 13, c10_o_y);
  c10_c_hoistedGlobal = chartInstance->c10_is_active_c10_ManipulatorME4901;
  c10_o_u = c10_c_hoistedGlobal;
  c10_p_y = NULL;
  sf_mex_assign(&c10_p_y, sf_mex_create("y", &c10_o_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c10_y, 14, c10_p_y);
  sf_mex_assign(&c10_st, c10_y, FALSE);
  return c10_st;
}

static void set_sim_state_c10_ManipulatorME4901
  (SFc10_ManipulatorME4901InstanceStruct *chartInstance, const mxArray *c10_st)
{
  const mxArray *c10_u;
  real_T c10_dv0[16];
  int32_T c10_i12;
  real_T c10_dv1[10];
  int32_T c10_i13;
  real_T c10_dv2[2];
  int32_T c10_i14;
  real_T c10_dv3[2];
  int32_T c10_i15;
  real_T c10_dv4[3];
  int32_T c10_i16;
  real_T c10_dv5[3];
  int32_T c10_i17;
  real_T c10_dv6[3];
  int32_T c10_i18;
  real_T c10_dv7[3];
  int32_T c10_i19;
  real_T c10_dv8[2];
  int32_T c10_i20;
  real_T c10_dv9[2];
  int32_T c10_i21;
  real_T c10_dv10[3];
  int32_T c10_i22;
  real_T c10_dv11[2];
  int32_T c10_i23;
  real_T *c10_collision;
  real_T *c10_docking;
  real_T (*c10_A)[16];
  real_T (*c10_B)[10];
  real_T (*c10_QA_c)[2];
  real_T (*c10_QB_c)[2];
  real_T (*c10_Vcm_an)[3];
  real_T (*c10_Vcm_bn)[3];
  real_T (*c10_W_an)[3];
  real_T (*c10_W_bn)[3];
  real_T (*c10_dock_sensA_c)[2];
  real_T (*c10_dock_sensB_c)[2];
  real_T (*c10_j)[3];
  real_T (*c10_n_c)[2];
  c10_j = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 14);
  c10_W_bn = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 13);
  c10_W_an = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 12);
  c10_Vcm_bn = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 11);
  c10_Vcm_an = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 10);
  c10_collision = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c10_docking = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c10_B = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 7);
  c10_A = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 6);
  c10_QB_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 5);
  c10_QA_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 4);
  c10_n_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 3);
  c10_dock_sensB_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 2);
  c10_dock_sensA_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c10_doneDoubleBufferReInit = TRUE;
  c10_u = sf_mex_dup(c10_st);
  c10_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 0)),
    "A", c10_dv0);
  for (c10_i12 = 0; c10_i12 < 16; c10_i12++) {
    (*c10_A)[c10_i12] = c10_dv0[c10_i12];
  }

  c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 1)),
    "B", c10_dv1);
  for (c10_i13 = 0; c10_i13 < 10; c10_i13++) {
    (*c10_B)[c10_i13] = c10_dv1[c10_i13];
  }

  c10_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 2)),
    "QA_c", c10_dv2);
  for (c10_i14 = 0; c10_i14 < 2; c10_i14++) {
    (*c10_QA_c)[c10_i14] = c10_dv2[c10_i14];
  }

  c10_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 3)),
    "QB_c", c10_dv3);
  for (c10_i15 = 0; c10_i15 < 2; c10_i15++) {
    (*c10_QB_c)[c10_i15] = c10_dv3[c10_i15];
  }

  c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 4)),
                       "Vcm_an", c10_dv4);
  for (c10_i16 = 0; c10_i16 < 3; c10_i16++) {
    (*c10_Vcm_an)[c10_i16] = c10_dv4[c10_i16];
  }

  c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 5)),
                       "Vcm_bn", c10_dv5);
  for (c10_i17 = 0; c10_i17 < 3; c10_i17++) {
    (*c10_Vcm_bn)[c10_i17] = c10_dv5[c10_i17];
  }

  c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 6)),
                       "W_an", c10_dv6);
  for (c10_i18 = 0; c10_i18 < 3; c10_i18++) {
    (*c10_W_an)[c10_i18] = c10_dv6[c10_i18];
  }

  c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 7)),
                       "W_bn", c10_dv7);
  for (c10_i19 = 0; c10_i19 < 3; c10_i19++) {
    (*c10_W_bn)[c10_i19] = c10_dv7[c10_i19];
  }

  *c10_collision = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c10_u, 8)), "collision");
  c10_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 9)),
    "dock_sensA_c", c10_dv8);
  for (c10_i20 = 0; c10_i20 < 2; c10_i20++) {
    (*c10_dock_sensA_c)[c10_i20] = c10_dv8[c10_i20];
  }

  c10_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 10)),
    "dock_sensB_c", c10_dv9);
  for (c10_i21 = 0; c10_i21 < 2; c10_i21++) {
    (*c10_dock_sensB_c)[c10_i21] = c10_dv9[c10_i21];
  }

  *c10_docking = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c10_u, 11)), "docking");
  c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 12)), "j",
                       c10_dv10);
  for (c10_i22 = 0; c10_i22 < 3; c10_i22++) {
    (*c10_j)[c10_i22] = c10_dv10[c10_i22];
  }

  c10_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 13)),
    "n_c", c10_dv11);
  for (c10_i23 = 0; c10_i23 < 2; c10_i23++) {
    (*c10_n_c)[c10_i23] = c10_dv11[c10_i23];
  }

  chartInstance->c10_is_active_c10_ManipulatorME4901 = c10_l_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 14)),
     "is_active_c10_ManipulatorME4901");
  sf_mex_destroy(&c10_u);
  c10_update_debugger_state_c10_ManipulatorME4901(chartInstance);
  sf_mex_destroy(&c10_st);
}

static void finalize_c10_ManipulatorME4901(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance)
{
}

static void sf_c10_ManipulatorME4901(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance)
{
  int32_T c10_i24;
  int32_T c10_i25;
  int32_T c10_i26;
  int32_T c10_i27;
  int32_T c10_i28;
  int32_T c10_i29;
  int32_T c10_i30;
  int32_T c10_i31;
  int32_T c10_i32;
  int32_T c10_i33;
  int32_T c10_i34;
  int32_T c10_i35;
  int32_T c10_i36;
  int32_T c10_i37;
  int32_T c10_i38;
  int32_T c10_i39;
  int32_T c10_i40;
  int32_T c10_i41;
  int32_T c10_i42;
  int32_T c10_i43;
  int32_T c10_i44;
  real_T c10_hoistedGlobal;
  real_T c10_b_hoistedGlobal;
  real_T c10_c_hoistedGlobal;
  real_T c10_d_hoistedGlobal;
  real_T c10_epsilon;
  real_T c10_sigma_dock;
  real_T c10_dotsigma_dock;
  int32_T c10_i45;
  real_T c10_Rbi_A1[4];
  int32_T c10_i46;
  real_T c10_Rbi_B1[4];
  int32_T c10_i47;
  real_T c10_Xcm_A[9];
  int32_T c10_i48;
  real_T c10_Xcm_B[9];
  int32_T c10_i49;
  real_T c10_mesh_A[21];
  int32_T c10_i50;
  real_T c10_mesh_B[12];
  int32_T c10_i51;
  real_T c10_dock_sensA[3];
  int32_T c10_i52;
  real_T c10_dock_sensB[3];
  real_T c10_sigma;
  int32_T c10_i53;
  real_T c10_ma_mb_Ia_Ib[4];
  uint32_T c10_debug_family_var_map[29];
  real_T c10_nargin = 13.0;
  real_T c10_nargout = 14.0;
  real_T c10_dock_sensA_c[2];
  real_T c10_dock_sensB_c[2];
  real_T c10_n_c[2];
  real_T c10_QA_c[2];
  real_T c10_QB_c[2];
  real_T c10_A[16];
  real_T c10_B[10];
  real_T c10_docking;
  real_T c10_collision;
  real_T c10_Vcm_an[3];
  real_T c10_Vcm_bn[3];
  real_T c10_W_an[3];
  real_T c10_W_bn[3];
  real_T c10_j[3];
  int32_T c10_i54;
  real_T c10_b_Rbi_A1[4];
  int32_T c10_i55;
  real_T c10_b_Rbi_B1[4];
  int32_T c10_i56;
  real_T c10_b_Xcm_A[9];
  int32_T c10_i57;
  real_T c10_b_Xcm_B[9];
  int32_T c10_i58;
  real_T c10_b_mesh_A[21];
  int32_T c10_i59;
  real_T c10_b_mesh_B[12];
  int32_T c10_i60;
  real_T c10_b_dock_sensA[3];
  int32_T c10_i61;
  real_T c10_b_dock_sensB[3];
  int32_T c10_i62;
  real_T c10_b_ma_mb_Ia_Ib[4];
  real_T c10_b_j[3];
  real_T c10_b_W_bn[3];
  real_T c10_b_W_an[3];
  real_T c10_b_Vcm_bn[3];
  real_T c10_b_Vcm_an[3];
  real_T c10_b_collision;
  real_T c10_b_docking;
  real_T c10_b_B[10];
  real_T c10_b_A[16];
  real_T c10_b_QB_c[2];
  real_T c10_b_QA_c[2];
  real_T c10_b_n_c[2];
  real_T c10_b_dock_sensB_c[2];
  real_T c10_b_dock_sensA_c[2];
  int32_T c10_i63;
  int32_T c10_i64;
  int32_T c10_i65;
  int32_T c10_i66;
  int32_T c10_i67;
  int32_T c10_i68;
  int32_T c10_i69;
  int32_T c10_i70;
  int32_T c10_i71;
  int32_T c10_i72;
  int32_T c10_i73;
  int32_T c10_i74;
  int32_T c10_i75;
  int32_T c10_i76;
  int32_T c10_i77;
  int32_T c10_i78;
  int32_T c10_i79;
  int32_T c10_i80;
  int32_T c10_i81;
  int32_T c10_i82;
  int32_T c10_i83;
  int32_T c10_i84;
  int32_T c10_i85;
  int32_T c10_i86;
  real_T *c10_b_epsilon;
  real_T *c10_b_sigma_dock;
  real_T *c10_b_dotsigma_dock;
  real_T *c10_b_sigma;
  real_T *c10_c_docking;
  real_T *c10_c_collision;
  real_T (*c10_c_dock_sensA_c)[2];
  real_T (*c10_c_dock_sensB_c)[2];
  real_T (*c10_c_n_c)[2];
  real_T (*c10_c_QA_c)[2];
  real_T (*c10_c_QB_c)[2];
  real_T (*c10_c_A)[16];
  real_T (*c10_c_B)[10];
  real_T (*c10_c_Vcm_an)[3];
  real_T (*c10_c_Vcm_bn)[3];
  real_T (*c10_c_W_an)[3];
  real_T (*c10_c_W_bn)[3];
  real_T (*c10_c_j)[3];
  real_T (*c10_c_ma_mb_Ia_Ib)[4];
  real_T (*c10_c_dock_sensB)[3];
  real_T (*c10_c_dock_sensA)[3];
  real_T (*c10_c_mesh_B)[12];
  real_T (*c10_c_mesh_A)[21];
  real_T (*c10_c_Xcm_B)[9];
  real_T (*c10_c_Xcm_A)[9];
  real_T (*c10_c_Rbi_B1)[4];
  real_T (*c10_c_Rbi_A1)[4];
  c10_c_j = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 14);
  c10_c_W_bn = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 13);
  c10_c_W_an = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 12);
  c10_c_Vcm_bn = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 11);
  c10_c_Vcm_an = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 10);
  c10_c_collision = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c10_c_ma_mb_Ia_Ib = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 12);
  c10_c_docking = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c10_b_sigma = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c10_c_dock_sensB = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 10);
  c10_c_dock_sensA = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 9);
  c10_c_mesh_B = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 8);
  c10_c_mesh_A = (real_T (*)[21])ssGetInputPortSignal(chartInstance->S, 7);
  c10_c_Xcm_B = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 6);
  c10_c_Xcm_A = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 5);
  c10_c_B = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 7);
  c10_c_A = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 6);
  c10_c_Rbi_B1 = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 4);
  c10_c_Rbi_A1 = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 3);
  c10_b_dotsigma_dock = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c10_b_sigma_dock = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c10_c_QB_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 5);
  c10_c_QA_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 4);
  c10_c_n_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 3);
  c10_c_dock_sensB_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 2);
  c10_c_dock_sensA_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c10_b_epsilon = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, chartInstance->c10_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c10_b_epsilon, 0U);
  for (c10_i24 = 0; c10_i24 < 2; c10_i24++) {
    _SFD_DATA_RANGE_CHECK((*c10_c_dock_sensA_c)[c10_i24], 1U);
  }

  for (c10_i25 = 0; c10_i25 < 2; c10_i25++) {
    _SFD_DATA_RANGE_CHECK((*c10_c_dock_sensB_c)[c10_i25], 2U);
  }

  for (c10_i26 = 0; c10_i26 < 2; c10_i26++) {
    _SFD_DATA_RANGE_CHECK((*c10_c_n_c)[c10_i26], 3U);
  }

  for (c10_i27 = 0; c10_i27 < 2; c10_i27++) {
    _SFD_DATA_RANGE_CHECK((*c10_c_QA_c)[c10_i27], 4U);
  }

  for (c10_i28 = 0; c10_i28 < 2; c10_i28++) {
    _SFD_DATA_RANGE_CHECK((*c10_c_QB_c)[c10_i28], 5U);
  }

  _SFD_DATA_RANGE_CHECK(*c10_b_sigma_dock, 6U);
  _SFD_DATA_RANGE_CHECK(*c10_b_dotsigma_dock, 7U);
  for (c10_i29 = 0; c10_i29 < 4; c10_i29++) {
    _SFD_DATA_RANGE_CHECK((*c10_c_Rbi_A1)[c10_i29], 8U);
  }

  for (c10_i30 = 0; c10_i30 < 4; c10_i30++) {
    _SFD_DATA_RANGE_CHECK((*c10_c_Rbi_B1)[c10_i30], 9U);
  }

  for (c10_i31 = 0; c10_i31 < 16; c10_i31++) {
    _SFD_DATA_RANGE_CHECK((*c10_c_A)[c10_i31], 10U);
  }

  for (c10_i32 = 0; c10_i32 < 10; c10_i32++) {
    _SFD_DATA_RANGE_CHECK((*c10_c_B)[c10_i32], 11U);
  }

  for (c10_i33 = 0; c10_i33 < 9; c10_i33++) {
    _SFD_DATA_RANGE_CHECK((*c10_c_Xcm_A)[c10_i33], 12U);
  }

  for (c10_i34 = 0; c10_i34 < 9; c10_i34++) {
    _SFD_DATA_RANGE_CHECK((*c10_c_Xcm_B)[c10_i34], 13U);
  }

  for (c10_i35 = 0; c10_i35 < 21; c10_i35++) {
    _SFD_DATA_RANGE_CHECK((*c10_c_mesh_A)[c10_i35], 14U);
  }

  for (c10_i36 = 0; c10_i36 < 12; c10_i36++) {
    _SFD_DATA_RANGE_CHECK((*c10_c_mesh_B)[c10_i36], 15U);
  }

  for (c10_i37 = 0; c10_i37 < 3; c10_i37++) {
    _SFD_DATA_RANGE_CHECK((*c10_c_dock_sensA)[c10_i37], 16U);
  }

  for (c10_i38 = 0; c10_i38 < 3; c10_i38++) {
    _SFD_DATA_RANGE_CHECK((*c10_c_dock_sensB)[c10_i38], 17U);
  }

  _SFD_DATA_RANGE_CHECK(*c10_b_sigma, 18U);
  _SFD_DATA_RANGE_CHECK(*c10_c_docking, 19U);
  for (c10_i39 = 0; c10_i39 < 4; c10_i39++) {
    _SFD_DATA_RANGE_CHECK((*c10_c_ma_mb_Ia_Ib)[c10_i39], 20U);
  }

  _SFD_DATA_RANGE_CHECK(*c10_c_collision, 21U);
  for (c10_i40 = 0; c10_i40 < 3; c10_i40++) {
    _SFD_DATA_RANGE_CHECK((*c10_c_Vcm_an)[c10_i40], 22U);
  }

  for (c10_i41 = 0; c10_i41 < 3; c10_i41++) {
    _SFD_DATA_RANGE_CHECK((*c10_c_Vcm_bn)[c10_i41], 23U);
  }

  for (c10_i42 = 0; c10_i42 < 3; c10_i42++) {
    _SFD_DATA_RANGE_CHECK((*c10_c_W_an)[c10_i42], 24U);
  }

  for (c10_i43 = 0; c10_i43 < 3; c10_i43++) {
    _SFD_DATA_RANGE_CHECK((*c10_c_W_bn)[c10_i43], 25U);
  }

  for (c10_i44 = 0; c10_i44 < 3; c10_i44++) {
    _SFD_DATA_RANGE_CHECK((*c10_c_j)[c10_i44], 26U);
  }

  chartInstance->c10_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c10_sfEvent);
  c10_hoistedGlobal = *c10_b_epsilon;
  c10_b_hoistedGlobal = *c10_b_sigma_dock;
  c10_c_hoistedGlobal = *c10_b_dotsigma_dock;
  c10_d_hoistedGlobal = *c10_b_sigma;
  c10_epsilon = c10_hoistedGlobal;
  c10_sigma_dock = c10_b_hoistedGlobal;
  c10_dotsigma_dock = c10_c_hoistedGlobal;
  for (c10_i45 = 0; c10_i45 < 4; c10_i45++) {
    c10_Rbi_A1[c10_i45] = (*c10_c_Rbi_A1)[c10_i45];
  }

  for (c10_i46 = 0; c10_i46 < 4; c10_i46++) {
    c10_Rbi_B1[c10_i46] = (*c10_c_Rbi_B1)[c10_i46];
  }

  for (c10_i47 = 0; c10_i47 < 9; c10_i47++) {
    c10_Xcm_A[c10_i47] = (*c10_c_Xcm_A)[c10_i47];
  }

  for (c10_i48 = 0; c10_i48 < 9; c10_i48++) {
    c10_Xcm_B[c10_i48] = (*c10_c_Xcm_B)[c10_i48];
  }

  for (c10_i49 = 0; c10_i49 < 21; c10_i49++) {
    c10_mesh_A[c10_i49] = (*c10_c_mesh_A)[c10_i49];
  }

  for (c10_i50 = 0; c10_i50 < 12; c10_i50++) {
    c10_mesh_B[c10_i50] = (*c10_c_mesh_B)[c10_i50];
  }

  for (c10_i51 = 0; c10_i51 < 3; c10_i51++) {
    c10_dock_sensA[c10_i51] = (*c10_c_dock_sensA)[c10_i51];
  }

  for (c10_i52 = 0; c10_i52 < 3; c10_i52++) {
    c10_dock_sensB[c10_i52] = (*c10_c_dock_sensB)[c10_i52];
  }

  c10_sigma = c10_d_hoistedGlobal;
  for (c10_i53 = 0; c10_i53 < 4; c10_i53++) {
    c10_ma_mb_Ia_Ib[c10_i53] = (*c10_c_ma_mb_Ia_Ib)[c10_i53];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 29U, 29U, c10_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 0U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 1U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_epsilon, 2U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_sigma_dock, 3U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_dotsigma_dock, 4U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_Rbi_A1, 5U, c10_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_Rbi_B1, 6U, c10_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_Xcm_A, 7U, c10_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_Xcm_B, 8U, c10_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_mesh_A, 9U, c10_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_mesh_B, 10U, c10_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_dock_sensA, 11U, c10_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_dock_sensB, 12U, c10_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_sigma, 13U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_ma_mb_Ia_Ib, 14U, c10_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_dock_sensA_c, 15U,
    c10_e_sf_marshallOut, c10_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_dock_sensB_c, 16U,
    c10_e_sf_marshallOut, c10_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_n_c, 17U, c10_e_sf_marshallOut,
    c10_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_QA_c, 18U, c10_e_sf_marshallOut,
    c10_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_QB_c, 19U, c10_e_sf_marshallOut,
    c10_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_A, 20U, c10_d_sf_marshallOut,
    c10_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_B, 21U, c10_c_sf_marshallOut,
    c10_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_docking, 22U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_collision, 23U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_Vcm_an, 24U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_Vcm_bn, 25U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_W_an, 26U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_W_bn, 27U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_j, 28U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 3);
  for (c10_i54 = 0; c10_i54 < 4; c10_i54++) {
    c10_b_Rbi_A1[c10_i54] = c10_Rbi_A1[c10_i54];
  }

  for (c10_i55 = 0; c10_i55 < 4; c10_i55++) {
    c10_b_Rbi_B1[c10_i55] = c10_Rbi_B1[c10_i55];
  }

  for (c10_i56 = 0; c10_i56 < 9; c10_i56++) {
    c10_b_Xcm_A[c10_i56] = c10_Xcm_A[c10_i56];
  }

  for (c10_i57 = 0; c10_i57 < 9; c10_i57++) {
    c10_b_Xcm_B[c10_i57] = c10_Xcm_B[c10_i57];
  }

  for (c10_i58 = 0; c10_i58 < 21; c10_i58++) {
    c10_b_mesh_A[c10_i58] = c10_mesh_A[c10_i58];
  }

  for (c10_i59 = 0; c10_i59 < 12; c10_i59++) {
    c10_b_mesh_B[c10_i59] = c10_mesh_B[c10_i59];
  }

  for (c10_i60 = 0; c10_i60 < 3; c10_i60++) {
    c10_b_dock_sensA[c10_i60] = c10_dock_sensA[c10_i60];
  }

  for (c10_i61 = 0; c10_i61 < 3; c10_i61++) {
    c10_b_dock_sensB[c10_i61] = c10_dock_sensB[c10_i61];
  }

  for (c10_i62 = 0; c10_i62 < 4; c10_i62++) {
    c10_b_ma_mb_Ia_Ib[c10_i62] = c10_ma_mb_Ia_Ib[c10_i62];
  }

  c10_collision_function(chartInstance, c10_epsilon, c10_sigma_dock,
    c10_dotsigma_dock, c10_b_Rbi_A1, c10_b_Rbi_B1, c10_b_Xcm_A, c10_b_Xcm_B,
    c10_b_mesh_A, c10_b_mesh_B, c10_b_dock_sensA, c10_b_dock_sensB, c10_sigma,
    c10_b_ma_mb_Ia_Ib, c10_b_dock_sensA_c, c10_b_dock_sensB_c, c10_b_n_c,
    c10_b_QA_c, c10_b_QB_c, c10_b_A, c10_b_B, &c10_b_docking, &c10_b_collision,
    c10_b_Vcm_an, c10_b_Vcm_bn, c10_b_W_an, c10_b_W_bn, c10_b_j);
  for (c10_i63 = 0; c10_i63 < 2; c10_i63++) {
    c10_dock_sensA_c[c10_i63] = c10_b_dock_sensA_c[c10_i63];
  }

  for (c10_i64 = 0; c10_i64 < 2; c10_i64++) {
    c10_dock_sensB_c[c10_i64] = c10_b_dock_sensB_c[c10_i64];
  }

  for (c10_i65 = 0; c10_i65 < 2; c10_i65++) {
    c10_n_c[c10_i65] = c10_b_n_c[c10_i65];
  }

  for (c10_i66 = 0; c10_i66 < 2; c10_i66++) {
    c10_QA_c[c10_i66] = c10_b_QA_c[c10_i66];
  }

  for (c10_i67 = 0; c10_i67 < 2; c10_i67++) {
    c10_QB_c[c10_i67] = c10_b_QB_c[c10_i67];
  }

  for (c10_i68 = 0; c10_i68 < 16; c10_i68++) {
    c10_A[c10_i68] = c10_b_A[c10_i68];
  }

  for (c10_i69 = 0; c10_i69 < 10; c10_i69++) {
    c10_B[c10_i69] = c10_b_B[c10_i69];
  }

  c10_docking = c10_b_docking;
  c10_collision = c10_b_collision;
  for (c10_i70 = 0; c10_i70 < 3; c10_i70++) {
    c10_Vcm_an[c10_i70] = c10_b_Vcm_an[c10_i70];
  }

  for (c10_i71 = 0; c10_i71 < 3; c10_i71++) {
    c10_Vcm_bn[c10_i71] = c10_b_Vcm_bn[c10_i71];
  }

  for (c10_i72 = 0; c10_i72 < 3; c10_i72++) {
    c10_W_an[c10_i72] = c10_b_W_an[c10_i72];
  }

  for (c10_i73 = 0; c10_i73 < 3; c10_i73++) {
    c10_W_bn[c10_i73] = c10_b_W_bn[c10_i73];
  }

  for (c10_i74 = 0; c10_i74 < 3; c10_i74++) {
    c10_j[c10_i74] = c10_b_j[c10_i74];
  }

  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c10_i75 = 0; c10_i75 < 2; c10_i75++) {
    (*c10_c_dock_sensA_c)[c10_i75] = c10_dock_sensA_c[c10_i75];
  }

  for (c10_i76 = 0; c10_i76 < 2; c10_i76++) {
    (*c10_c_dock_sensB_c)[c10_i76] = c10_dock_sensB_c[c10_i76];
  }

  for (c10_i77 = 0; c10_i77 < 2; c10_i77++) {
    (*c10_c_n_c)[c10_i77] = c10_n_c[c10_i77];
  }

  for (c10_i78 = 0; c10_i78 < 2; c10_i78++) {
    (*c10_c_QA_c)[c10_i78] = c10_QA_c[c10_i78];
  }

  for (c10_i79 = 0; c10_i79 < 2; c10_i79++) {
    (*c10_c_QB_c)[c10_i79] = c10_QB_c[c10_i79];
  }

  for (c10_i80 = 0; c10_i80 < 16; c10_i80++) {
    (*c10_c_A)[c10_i80] = c10_A[c10_i80];
  }

  for (c10_i81 = 0; c10_i81 < 10; c10_i81++) {
    (*c10_c_B)[c10_i81] = c10_B[c10_i81];
  }

  *c10_c_docking = c10_docking;
  *c10_c_collision = c10_collision;
  for (c10_i82 = 0; c10_i82 < 3; c10_i82++) {
    (*c10_c_Vcm_an)[c10_i82] = c10_Vcm_an[c10_i82];
  }

  for (c10_i83 = 0; c10_i83 < 3; c10_i83++) {
    (*c10_c_Vcm_bn)[c10_i83] = c10_Vcm_bn[c10_i83];
  }

  for (c10_i84 = 0; c10_i84 < 3; c10_i84++) {
    (*c10_c_W_an)[c10_i84] = c10_W_an[c10_i84];
  }

  for (c10_i85 = 0; c10_i85 < 3; c10_i85++) {
    (*c10_c_W_bn)[c10_i85] = c10_W_bn[c10_i85];
  }

  for (c10_i86 = 0; c10_i86 < 3; c10_i86++) {
    (*c10_c_j)[c10_i86] = c10_j[c10_i86];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c10_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ManipulatorME4901MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc10_ManipulatorME4901
  (SFc10_ManipulatorME4901InstanceStruct *chartInstance)
{
}

static void registerMessagesc10_ManipulatorME4901
  (SFc10_ManipulatorME4901InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber)
{
}

static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i87;
  real_T c10_b_inData[3];
  int32_T c10_i88;
  real_T c10_u[3];
  const mxArray *c10_y = NULL;
  SFc10_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc10_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i87 = 0; c10_i87 < 3; c10_i87++) {
    c10_b_inData[c10_i87] = (*(real_T (*)[3])c10_inData)[c10_i87];
  }

  for (c10_i88 = 0; c10_i88 < 3; c10_i88++) {
    c10_u[c10_i88] = c10_b_inData[c10_i88];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static void c10_emlrt_marshallIn(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c10_j, const char_T *c10_identifier, real_T
  c10_y[3])
{
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_j), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_j);
}

static void c10_b_emlrt_marshallIn(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[3])
{
  real_T c10_dv12[3];
  int32_T c10_i89;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv12, 1, 0, 0U, 1, 0U, 1, 3);
  for (c10_i89 = 0; c10_i89 < 3; c10_i89++) {
    c10_y[c10_i89] = c10_dv12[c10_i89];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_j;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[3];
  int32_T c10_i90;
  SFc10_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc10_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c10_j = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_j), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_j);
  for (c10_i90 = 0; c10_i90 < 3; c10_i90++) {
    (*(real_T (*)[3])c10_outData)[c10_i90] = c10_y[c10_i90];
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  real_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc10_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(real_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static real_T c10_c_emlrt_marshallIn(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c10_collision, const char_T *c10_identifier)
{
  real_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_collision),
    &c10_thisId);
  sf_mex_destroy(&c10_collision);
  return c10_y;
}

static real_T c10_d_emlrt_marshallIn(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  real_T c10_y;
  real_T c10_d0;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_d0, 1, 0, 0U, 0, 0U, 0);
  c10_y = c10_d0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_collision;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y;
  SFc10_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc10_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c10_collision = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_collision),
    &c10_thisId);
  sf_mex_destroy(&c10_collision);
  *(real_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i91;
  int32_T c10_i92;
  int32_T c10_i93;
  real_T c10_b_inData[10];
  int32_T c10_i94;
  int32_T c10_i95;
  int32_T c10_i96;
  real_T c10_u[10];
  const mxArray *c10_y = NULL;
  SFc10_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc10_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_i91 = 0;
  for (c10_i92 = 0; c10_i92 < 5; c10_i92++) {
    for (c10_i93 = 0; c10_i93 < 2; c10_i93++) {
      c10_b_inData[c10_i93 + c10_i91] = (*(real_T (*)[10])c10_inData)[c10_i93 +
        c10_i91];
    }

    c10_i91 += 2;
  }

  c10_i94 = 0;
  for (c10_i95 = 0; c10_i95 < 5; c10_i95++) {
    for (c10_i96 = 0; c10_i96 < 2; c10_i96++) {
      c10_u[c10_i96 + c10_i94] = c10_b_inData[c10_i96 + c10_i94];
    }

    c10_i94 += 2;
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 2, 2, 5), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static void c10_e_emlrt_marshallIn(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c10_B, const char_T *c10_identifier, real_T
  c10_y[10])
{
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_B), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_B);
}

static void c10_f_emlrt_marshallIn(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[10])
{
  real_T c10_dv13[10];
  int32_T c10_i97;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv13, 1, 0, 0U, 1, 0U, 2, 2,
                5);
  for (c10_i97 = 0; c10_i97 < 10; c10_i97++) {
    c10_y[c10_i97] = c10_dv13[c10_i97];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_B;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[10];
  int32_T c10_i98;
  int32_T c10_i99;
  int32_T c10_i100;
  SFc10_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc10_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c10_B = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_B), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_B);
  c10_i98 = 0;
  for (c10_i99 = 0; c10_i99 < 5; c10_i99++) {
    for (c10_i100 = 0; c10_i100 < 2; c10_i100++) {
      (*(real_T (*)[10])c10_outData)[c10_i100 + c10_i98] = c10_y[c10_i100 +
        c10_i98];
    }

    c10_i98 += 2;
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i101;
  int32_T c10_i102;
  int32_T c10_i103;
  real_T c10_b_inData[16];
  int32_T c10_i104;
  int32_T c10_i105;
  int32_T c10_i106;
  real_T c10_u[16];
  const mxArray *c10_y = NULL;
  SFc10_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc10_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_i101 = 0;
  for (c10_i102 = 0; c10_i102 < 8; c10_i102++) {
    for (c10_i103 = 0; c10_i103 < 2; c10_i103++) {
      c10_b_inData[c10_i103 + c10_i101] = (*(real_T (*)[16])c10_inData)[c10_i103
        + c10_i101];
    }

    c10_i101 += 2;
  }

  c10_i104 = 0;
  for (c10_i105 = 0; c10_i105 < 8; c10_i105++) {
    for (c10_i106 = 0; c10_i106 < 2; c10_i106++) {
      c10_u[c10_i106 + c10_i104] = c10_b_inData[c10_i106 + c10_i104];
    }

    c10_i104 += 2;
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 2, 2, 8), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static void c10_g_emlrt_marshallIn(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c10_A, const char_T *c10_identifier, real_T
  c10_y[16])
{
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_A), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_A);
}

static void c10_h_emlrt_marshallIn(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[16])
{
  real_T c10_dv14[16];
  int32_T c10_i107;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv14, 1, 0, 0U, 1, 0U, 2, 2,
                8);
  for (c10_i107 = 0; c10_i107 < 16; c10_i107++) {
    c10_y[c10_i107] = c10_dv14[c10_i107];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_A;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[16];
  int32_T c10_i108;
  int32_T c10_i109;
  int32_T c10_i110;
  SFc10_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc10_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c10_A = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_A), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_A);
  c10_i108 = 0;
  for (c10_i109 = 0; c10_i109 < 8; c10_i109++) {
    for (c10_i110 = 0; c10_i110 < 2; c10_i110++) {
      (*(real_T (*)[16])c10_outData)[c10_i110 + c10_i108] = c10_y[c10_i110 +
        c10_i108];
    }

    c10_i108 += 2;
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_e_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i111;
  real_T c10_b_inData[2];
  int32_T c10_i112;
  real_T c10_u[2];
  const mxArray *c10_y = NULL;
  SFc10_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc10_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i111 = 0; c10_i111 < 2; c10_i111++) {
    c10_b_inData[c10_i111] = (*(real_T (*)[2])c10_inData)[c10_i111];
  }

  for (c10_i112 = 0; c10_i112 < 2; c10_i112++) {
    c10_u[c10_i112] = c10_b_inData[c10_i112];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static void c10_i_emlrt_marshallIn(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c10_QB_c, const char_T *c10_identifier, real_T
  c10_y[2])
{
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_QB_c), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_QB_c);
}

static void c10_j_emlrt_marshallIn(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[2])
{
  real_T c10_dv15[2];
  int32_T c10_i113;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv15, 1, 0, 0U, 1, 0U, 1, 2);
  for (c10_i113 = 0; c10_i113 < 2; c10_i113++) {
    c10_y[c10_i113] = c10_dv15[c10_i113];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_QB_c;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[2];
  int32_T c10_i114;
  SFc10_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc10_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c10_QB_c = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_QB_c), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_QB_c);
  for (c10_i114 = 0; c10_i114 < 2; c10_i114++) {
    (*(real_T (*)[2])c10_outData)[c10_i114] = c10_y[c10_i114];
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_f_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i115;
  real_T c10_b_inData[4];
  int32_T c10_i116;
  real_T c10_u[4];
  const mxArray *c10_y = NULL;
  SFc10_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc10_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i115 = 0; c10_i115 < 4; c10_i115++) {
    c10_b_inData[c10_i115] = (*(real_T (*)[4])c10_inData)[c10_i115];
  }

  for (c10_i116 = 0; c10_i116 < 4; c10_i116++) {
    c10_u[c10_i116] = c10_b_inData[c10_i116];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static const mxArray *c10_g_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i117;
  int32_T c10_i118;
  int32_T c10_i119;
  real_T c10_b_inData[12];
  int32_T c10_i120;
  int32_T c10_i121;
  int32_T c10_i122;
  real_T c10_u[12];
  const mxArray *c10_y = NULL;
  SFc10_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc10_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_i117 = 0;
  for (c10_i118 = 0; c10_i118 < 4; c10_i118++) {
    for (c10_i119 = 0; c10_i119 < 3; c10_i119++) {
      c10_b_inData[c10_i119 + c10_i117] = (*(real_T (*)[12])c10_inData)[c10_i119
        + c10_i117];
    }

    c10_i117 += 3;
  }

  c10_i120 = 0;
  for (c10_i121 = 0; c10_i121 < 4; c10_i121++) {
    for (c10_i122 = 0; c10_i122 < 3; c10_i122++) {
      c10_u[c10_i122 + c10_i120] = c10_b_inData[c10_i122 + c10_i120];
    }

    c10_i120 += 3;
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 2, 3, 4), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static const mxArray *c10_h_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i123;
  int32_T c10_i124;
  int32_T c10_i125;
  real_T c10_b_inData[21];
  int32_T c10_i126;
  int32_T c10_i127;
  int32_T c10_i128;
  real_T c10_u[21];
  const mxArray *c10_y = NULL;
  SFc10_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc10_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_i123 = 0;
  for (c10_i124 = 0; c10_i124 < 7; c10_i124++) {
    for (c10_i125 = 0; c10_i125 < 3; c10_i125++) {
      c10_b_inData[c10_i125 + c10_i123] = (*(real_T (*)[21])c10_inData)[c10_i125
        + c10_i123];
    }

    c10_i123 += 3;
  }

  c10_i126 = 0;
  for (c10_i127 = 0; c10_i127 < 7; c10_i127++) {
    for (c10_i128 = 0; c10_i128 < 3; c10_i128++) {
      c10_u[c10_i128 + c10_i126] = c10_b_inData[c10_i128 + c10_i126];
    }

    c10_i126 += 3;
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 2, 3, 7), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static const mxArray *c10_i_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i129;
  real_T c10_b_inData[9];
  int32_T c10_i130;
  real_T c10_u[9];
  const mxArray *c10_y = NULL;
  SFc10_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc10_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i129 = 0; c10_i129 < 9; c10_i129++) {
    c10_b_inData[c10_i129] = (*(real_T (*)[9])c10_inData)[c10_i129];
  }

  for (c10_i130 = 0; c10_i130 < 9; c10_i130++) {
    c10_u[c10_i130] = c10_b_inData[c10_i130];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 2, 9, 1), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static const mxArray *c10_j_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i131;
  real_T c10_b_inData[9];
  int32_T c10_i132;
  real_T c10_u[9];
  const mxArray *c10_y = NULL;
  SFc10_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc10_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i131 = 0; c10_i131 < 9; c10_i131++) {
    c10_b_inData[c10_i131] = (*(real_T (*)[9])c10_inData)[c10_i131];
  }

  for (c10_i132 = 0; c10_i132 < 9; c10_i132++) {
    c10_u[c10_i132] = c10_b_inData[c10_i132];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 9), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static const mxArray *c10_k_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i133;
  int32_T c10_i134;
  int32_T c10_i135;
  real_T c10_b_inData[4];
  int32_T c10_i136;
  int32_T c10_i137;
  int32_T c10_i138;
  real_T c10_u[4];
  const mxArray *c10_y = NULL;
  SFc10_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc10_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_i133 = 0;
  for (c10_i134 = 0; c10_i134 < 2; c10_i134++) {
    for (c10_i135 = 0; c10_i135 < 2; c10_i135++) {
      c10_b_inData[c10_i135 + c10_i133] = (*(real_T (*)[4])c10_inData)[c10_i135
        + c10_i133];
    }

    c10_i133 += 2;
  }

  c10_i136 = 0;
  for (c10_i137 = 0; c10_i137 < 2; c10_i137++) {
    for (c10_i138 = 0; c10_i138 < 2; c10_i138++) {
      c10_u[c10_i138 + c10_i136] = c10_b_inData[c10_i138 + c10_i136];
    }

    c10_i136 += 2;
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

const mxArray *sf_c10_ManipulatorME4901_get_eml_resolved_functions_info(void)
{
  const mxArray *c10_nameCaptureInfo;
  c10_ResolvedFunctionInfo c10_info[70];
  c10_ResolvedFunctionInfo (*c10_b_info)[70];
  const mxArray *c10_m0 = NULL;
  int32_T c10_i139;
  c10_ResolvedFunctionInfo *c10_r0;
  c10_nameCaptureInfo = NULL;
  c10_nameCaptureInfo = NULL;
  c10_info_helper(c10_info);
  c10_b_info = (c10_ResolvedFunctionInfo (*)[70])c10_info;
  (*c10_b_info)[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  (*c10_b_info)[64].name = "eml_int_forloop_overflow_check";
  (*c10_b_info)[64].dominantType = "";
  (*c10_b_info)[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  (*c10_b_info)[64].fileTimeLo = 1346542740U;
  (*c10_b_info)[64].fileTimeHi = 0U;
  (*c10_b_info)[64].mFileTimeLo = 0U;
  (*c10_b_info)[64].mFileTimeHi = 0U;
  (*c10_b_info)[65].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  (*c10_b_info)[65].name = "eml_relop";
  (*c10_b_info)[65].dominantType = "function_handle";
  (*c10_b_info)[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  (*c10_b_info)[65].fileTimeLo = 1342483582U;
  (*c10_b_info)[65].fileTimeHi = 0U;
  (*c10_b_info)[65].mFileTimeLo = 0U;
  (*c10_b_info)[65].mFileTimeHi = 0U;
  (*c10_b_info)[66].context =
    "[E]C:/Users/Admin/Desktop/AlessioFiles/ManipulatorCODE/ManipulatorME4901/collision_function.p";
  (*c10_b_info)[66].name = "cross";
  (*c10_b_info)[66].dominantType = "double";
  (*c10_b_info)[66].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  (*c10_b_info)[66].fileTimeLo = 1286851242U;
  (*c10_b_info)[66].fileTimeHi = 0U;
  (*c10_b_info)[66].mFileTimeLo = 0U;
  (*c10_b_info)[66].mFileTimeHi = 0U;
  (*c10_b_info)[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  (*c10_b_info)[67].name = "mtimes";
  (*c10_b_info)[67].dominantType = "double";
  (*c10_b_info)[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c10_b_info)[67].fileTimeLo = 1289552092U;
  (*c10_b_info)[67].fileTimeHi = 0U;
  (*c10_b_info)[67].mFileTimeLo = 0U;
  (*c10_b_info)[67].mFileTimeHi = 0U;
  (*c10_b_info)[68].context =
    "[E]C:/Users/Admin/Desktop/AlessioFiles/ManipulatorCODE/ManipulatorME4901/collision_function.p";
  (*c10_b_info)[68].name = "mldivide";
  (*c10_b_info)[68].dominantType = "double";
  (*c10_b_info)[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  (*c10_b_info)[68].fileTimeLo = 1357983948U;
  (*c10_b_info)[68].fileTimeHi = 0U;
  (*c10_b_info)[68].mFileTimeLo = 1319762366U;
  (*c10_b_info)[68].mFileTimeHi = 0U;
  (*c10_b_info)[69].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  (*c10_b_info)[69].name = "rdivide";
  (*c10_b_info)[69].dominantType = "double";
  (*c10_b_info)[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c10_b_info)[69].fileTimeLo = 1346542788U;
  (*c10_b_info)[69].fileTimeHi = 0U;
  (*c10_b_info)[69].mFileTimeLo = 0U;
  (*c10_b_info)[69].mFileTimeHi = 0U;
  sf_mex_assign(&c10_m0, sf_mex_createstruct("nameCaptureInfo", 1, 70), FALSE);
  for (c10_i139 = 0; c10_i139 < 70; c10_i139++) {
    c10_r0 = &c10_info[c10_i139];
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c10_r0->context)), "context", "nameCaptureInfo",
                    c10_i139);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c10_r0->name)), "name", "nameCaptureInfo",
                    c10_i139);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo",
      c10_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c10_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c10_i139);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c10_r0->resolved)), "resolved",
                    "nameCaptureInfo", c10_i139);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c10_i139);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c10_i139);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo",
      &c10_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c10_i139);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo",
      &c10_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c10_i139);
  }

  sf_mex_assign(&c10_nameCaptureInfo, c10_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c10_nameCaptureInfo);
  return c10_nameCaptureInfo;
}

static void c10_info_helper(c10_ResolvedFunctionInfo c10_info[70])
{
  c10_info[0].context = "";
  c10_info[0].name = "collision_function";
  c10_info[0].dominantType = "double";
  c10_info[0].resolved =
    "[E]C:/Users/Admin/Desktop/AlessioFiles/ManipulatorCODE/ManipulatorME4901/collision_function.p";
  c10_info[0].fileTimeLo = 1370567892U;
  c10_info[0].fileTimeHi = 0U;
  c10_info[0].mFileTimeLo = 0U;
  c10_info[0].mFileTimeHi = 0U;
  c10_info[1].context =
    "[E]C:/Users/Admin/Desktop/AlessioFiles/ManipulatorCODE/ManipulatorME4901/collision_function.p";
  c10_info[1].name = "mtimes";
  c10_info[1].dominantType = "double";
  c10_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[1].fileTimeLo = 1289552092U;
  c10_info[1].fileTimeHi = 0U;
  c10_info[1].mFileTimeLo = 0U;
  c10_info[1].mFileTimeHi = 0U;
  c10_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[2].name = "eml_index_class";
  c10_info[2].dominantType = "";
  c10_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c10_info[2].fileTimeLo = 1323202978U;
  c10_info[2].fileTimeHi = 0U;
  c10_info[2].mFileTimeLo = 0U;
  c10_info[2].mFileTimeHi = 0U;
  c10_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[3].name = "eml_scalar_eg";
  c10_info[3].dominantType = "double";
  c10_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c10_info[3].fileTimeLo = 1286851196U;
  c10_info[3].fileTimeHi = 0U;
  c10_info[3].mFileTimeLo = 0U;
  c10_info[3].mFileTimeHi = 0U;
  c10_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[4].name = "eml_xgemm";
  c10_info[4].dominantType = "char";
  c10_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c10_info[4].fileTimeLo = 1299109172U;
  c10_info[4].fileTimeHi = 0U;
  c10_info[4].mFileTimeLo = 0U;
  c10_info[4].mFileTimeHi = 0U;
  c10_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c10_info[5].name = "eml_blas_inline";
  c10_info[5].dominantType = "";
  c10_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c10_info[5].fileTimeLo = 1299109168U;
  c10_info[5].fileTimeHi = 0U;
  c10_info[5].mFileTimeLo = 0U;
  c10_info[5].mFileTimeHi = 0U;
  c10_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c10_info[6].name = "mtimes";
  c10_info[6].dominantType = "double";
  c10_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[6].fileTimeLo = 1289552092U;
  c10_info[6].fileTimeHi = 0U;
  c10_info[6].mFileTimeLo = 0U;
  c10_info[6].mFileTimeHi = 0U;
  c10_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c10_info[7].name = "eml_index_class";
  c10_info[7].dominantType = "";
  c10_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c10_info[7].fileTimeLo = 1323202978U;
  c10_info[7].fileTimeHi = 0U;
  c10_info[7].mFileTimeLo = 0U;
  c10_info[7].mFileTimeHi = 0U;
  c10_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c10_info[8].name = "eml_scalar_eg";
  c10_info[8].dominantType = "double";
  c10_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c10_info[8].fileTimeLo = 1286851196U;
  c10_info[8].fileTimeHi = 0U;
  c10_info[8].mFileTimeLo = 0U;
  c10_info[8].mFileTimeHi = 0U;
  c10_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c10_info[9].name = "eml_refblas_xgemm";
  c10_info[9].dominantType = "char";
  c10_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c10_info[9].fileTimeLo = 1299109174U;
  c10_info[9].fileTimeHi = 0U;
  c10_info[9].mFileTimeLo = 0U;
  c10_info[9].mFileTimeHi = 0U;
  c10_info[10].context =
    "[E]C:/Users/Admin/Desktop/AlessioFiles/ManipulatorCODE/ManipulatorME4901/collision_function.p";
  c10_info[10].name = "length";
  c10_info[10].dominantType = "double";
  c10_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c10_info[10].fileTimeLo = 1303178606U;
  c10_info[10].fileTimeHi = 0U;
  c10_info[10].mFileTimeLo = 0U;
  c10_info[10].mFileTimeHi = 0U;
  c10_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength";
  c10_info[11].name = "eml_index_class";
  c10_info[11].dominantType = "";
  c10_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c10_info[11].fileTimeLo = 1323202978U;
  c10_info[11].fileTimeHi = 0U;
  c10_info[11].mFileTimeLo = 0U;
  c10_info[11].mFileTimeHi = 0U;
  c10_info[12].context =
    "[E]C:/Users/Admin/Desktop/AlessioFiles/ManipulatorCODE/ManipulatorME4901/collision_function.p";
  c10_info[12].name = "dot";
  c10_info[12].dominantType = "double";
  c10_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c10_info[12].fileTimeLo = 1313380216U;
  c10_info[12].fileTimeHi = 0U;
  c10_info[12].mFileTimeLo = 0U;
  c10_info[12].mFileTimeHi = 0U;
  c10_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c10_info[13].name = "isequal";
  c10_info[13].dominantType = "double";
  c10_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c10_info[13].fileTimeLo = 1286851158U;
  c10_info[13].fileTimeHi = 0U;
  c10_info[13].mFileTimeLo = 0U;
  c10_info[13].mFileTimeHi = 0U;
  c10_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c10_info[14].name = "eml_isequal_core";
  c10_info[14].dominantType = "double";
  c10_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c10_info[14].fileTimeLo = 1286851186U;
  c10_info[14].fileTimeHi = 0U;
  c10_info[14].mFileTimeLo = 0U;
  c10_info[14].mFileTimeHi = 0U;
  c10_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar";
  c10_info[15].name = "isnan";
  c10_info[15].dominantType = "double";
  c10_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c10_info[15].fileTimeLo = 1286851160U;
  c10_info[15].fileTimeHi = 0U;
  c10_info[15].mFileTimeLo = 0U;
  c10_info[15].mFileTimeHi = 0U;
  c10_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c10_info[16].name = "eml_index_class";
  c10_info[16].dominantType = "";
  c10_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c10_info[16].fileTimeLo = 1323202978U;
  c10_info[16].fileTimeHi = 0U;
  c10_info[16].mFileTimeLo = 0U;
  c10_info[16].mFileTimeHi = 0U;
  c10_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m";
  c10_info[17].name = "eml_scalar_eg";
  c10_info[17].dominantType = "double";
  c10_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c10_info[17].fileTimeLo = 1286851196U;
  c10_info[17].fileTimeHi = 0U;
  c10_info[17].mFileTimeLo = 0U;
  c10_info[17].mFileTimeHi = 0U;
  c10_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m!vdot";
  c10_info[18].name = "eml_xdotc";
  c10_info[18].dominantType = "double";
  c10_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c10_info[18].fileTimeLo = 1299109172U;
  c10_info[18].fileTimeHi = 0U;
  c10_info[18].mFileTimeLo = 0U;
  c10_info[18].mFileTimeHi = 0U;
  c10_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c10_info[19].name = "eml_blas_inline";
  c10_info[19].dominantType = "";
  c10_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c10_info[19].fileTimeLo = 1299109168U;
  c10_info[19].fileTimeHi = 0U;
  c10_info[19].mFileTimeLo = 0U;
  c10_info[19].mFileTimeHi = 0U;
  c10_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c10_info[20].name = "eml_xdot";
  c10_info[20].dominantType = "double";
  c10_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c10_info[20].fileTimeLo = 1299109172U;
  c10_info[20].fileTimeHi = 0U;
  c10_info[20].mFileTimeLo = 0U;
  c10_info[20].mFileTimeHi = 0U;
  c10_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c10_info[21].name = "eml_blas_inline";
  c10_info[21].dominantType = "";
  c10_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c10_info[21].fileTimeLo = 1299109168U;
  c10_info[21].fileTimeHi = 0U;
  c10_info[21].mFileTimeLo = 0U;
  c10_info[21].mFileTimeHi = 0U;
  c10_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m!below_threshold";
  c10_info[22].name = "length";
  c10_info[22].dominantType = "double";
  c10_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c10_info[22].fileTimeLo = 1303178606U;
  c10_info[22].fileTimeHi = 0U;
  c10_info[22].mFileTimeLo = 0U;
  c10_info[22].mFileTimeHi = 0U;
  c10_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c10_info[23].name = "eml_index_class";
  c10_info[23].dominantType = "";
  c10_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c10_info[23].fileTimeLo = 1323202978U;
  c10_info[23].fileTimeHi = 0U;
  c10_info[23].mFileTimeLo = 0U;
  c10_info[23].mFileTimeHi = 0U;
  c10_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c10_info[24].name = "eml_refblas_xdot";
  c10_info[24].dominantType = "double";
  c10_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c10_info[24].fileTimeLo = 1299109172U;
  c10_info[24].fileTimeHi = 0U;
  c10_info[24].mFileTimeLo = 0U;
  c10_info[24].mFileTimeHi = 0U;
  c10_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c10_info[25].name = "eml_refblas_xdotx";
  c10_info[25].dominantType = "char";
  c10_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c10_info[25].fileTimeLo = 1299109174U;
  c10_info[25].fileTimeHi = 0U;
  c10_info[25].mFileTimeLo = 0U;
  c10_info[25].mFileTimeHi = 0U;
  c10_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c10_info[26].name = "eml_scalar_eg";
  c10_info[26].dominantType = "double";
  c10_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c10_info[26].fileTimeLo = 1286851196U;
  c10_info[26].fileTimeHi = 0U;
  c10_info[26].mFileTimeLo = 0U;
  c10_info[26].mFileTimeHi = 0U;
  c10_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c10_info[27].name = "eml_index_class";
  c10_info[27].dominantType = "";
  c10_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c10_info[27].fileTimeLo = 1323202978U;
  c10_info[27].fileTimeHi = 0U;
  c10_info[27].mFileTimeLo = 0U;
  c10_info[27].mFileTimeHi = 0U;
  c10_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c10_info[28].name = "eml_int_forloop_overflow_check";
  c10_info[28].dominantType = "";
  c10_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c10_info[28].fileTimeLo = 1346542740U;
  c10_info[28].fileTimeHi = 0U;
  c10_info[28].mFileTimeLo = 0U;
  c10_info[28].mFileTimeHi = 0U;
  c10_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c10_info[29].name = "intmax";
  c10_info[29].dominantType = "char";
  c10_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c10_info[29].fileTimeLo = 1311287716U;
  c10_info[29].fileTimeHi = 0U;
  c10_info[29].mFileTimeLo = 0U;
  c10_info[29].mFileTimeHi = 0U;
  c10_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c10_info[30].name = "eml_index_minus";
  c10_info[30].dominantType = "double";
  c10_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c10_info[30].fileTimeLo = 1286851178U;
  c10_info[30].fileTimeHi = 0U;
  c10_info[30].mFileTimeLo = 0U;
  c10_info[30].mFileTimeHi = 0U;
  c10_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c10_info[31].name = "eml_index_class";
  c10_info[31].dominantType = "";
  c10_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c10_info[31].fileTimeLo = 1323202978U;
  c10_info[31].fileTimeHi = 0U;
  c10_info[31].mFileTimeLo = 0U;
  c10_info[31].mFileTimeHi = 0U;
  c10_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c10_info[32].name = "eml_index_times";
  c10_info[32].dominantType = "coder.internal.indexInt";
  c10_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c10_info[32].fileTimeLo = 1286851180U;
  c10_info[32].fileTimeHi = 0U;
  c10_info[32].mFileTimeLo = 0U;
  c10_info[32].mFileTimeHi = 0U;
  c10_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c10_info[33].name = "eml_index_class";
  c10_info[33].dominantType = "";
  c10_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c10_info[33].fileTimeLo = 1323202978U;
  c10_info[33].fileTimeHi = 0U;
  c10_info[33].mFileTimeLo = 0U;
  c10_info[33].mFileTimeHi = 0U;
  c10_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c10_info[34].name = "eml_index_plus";
  c10_info[34].dominantType = "coder.internal.indexInt";
  c10_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c10_info[34].fileTimeLo = 1286851178U;
  c10_info[34].fileTimeHi = 0U;
  c10_info[34].mFileTimeLo = 0U;
  c10_info[34].mFileTimeHi = 0U;
  c10_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c10_info[35].name = "eml_index_class";
  c10_info[35].dominantType = "";
  c10_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c10_info[35].fileTimeLo = 1323202978U;
  c10_info[35].fileTimeHi = 0U;
  c10_info[35].mFileTimeLo = 0U;
  c10_info[35].mFileTimeHi = 0U;
  c10_info[36].context =
    "[E]C:/Users/Admin/Desktop/AlessioFiles/ManipulatorCODE/ManipulatorME4901/collision_function.p";
  c10_info[36].name = "mrdivide";
  c10_info[36].dominantType = "double";
  c10_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c10_info[36].fileTimeLo = 1357983948U;
  c10_info[36].fileTimeHi = 0U;
  c10_info[36].mFileTimeLo = 1319762366U;
  c10_info[36].mFileTimeHi = 0U;
  c10_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c10_info[37].name = "rdivide";
  c10_info[37].dominantType = "double";
  c10_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[37].fileTimeLo = 1346542788U;
  c10_info[37].fileTimeHi = 0U;
  c10_info[37].mFileTimeLo = 0U;
  c10_info[37].mFileTimeHi = 0U;
  c10_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[38].name = "eml_scalexp_compatible";
  c10_info[38].dominantType = "double";
  c10_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c10_info[38].fileTimeLo = 1286851196U;
  c10_info[38].fileTimeHi = 0U;
  c10_info[38].mFileTimeLo = 0U;
  c10_info[38].mFileTimeHi = 0U;
  c10_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c10_info[39].name = "eml_div";
  c10_info[39].dominantType = "double";
  c10_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c10_info[39].fileTimeLo = 1313380210U;
  c10_info[39].fileTimeHi = 0U;
  c10_info[39].mFileTimeLo = 0U;
  c10_info[39].mFileTimeHi = 0U;
  c10_info[40].context =
    "[E]C:/Users/Admin/Desktop/AlessioFiles/ManipulatorCODE/ManipulatorME4901/collision_function.p";
  c10_info[40].name = "norm";
  c10_info[40].dominantType = "double";
  c10_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c10_info[40].fileTimeLo = 1336554494U;
  c10_info[40].fileTimeHi = 0U;
  c10_info[40].mFileTimeLo = 0U;
  c10_info[40].mFileTimeHi = 0U;
  c10_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm";
  c10_info[41].name = "eml_index_class";
  c10_info[41].dominantType = "";
  c10_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c10_info[41].fileTimeLo = 1323202978U;
  c10_info[41].fileTimeHi = 0U;
  c10_info[41].mFileTimeLo = 0U;
  c10_info[41].mFileTimeHi = 0U;
  c10_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm";
  c10_info[42].name = "eml_xnrm2";
  c10_info[42].dominantType = "double";
  c10_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c10_info[42].fileTimeLo = 1299109176U;
  c10_info[42].fileTimeHi = 0U;
  c10_info[42].mFileTimeLo = 0U;
  c10_info[42].mFileTimeHi = 0U;
  c10_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c10_info[43].name = "eml_blas_inline";
  c10_info[43].dominantType = "";
  c10_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c10_info[43].fileTimeLo = 1299109168U;
  c10_info[43].fileTimeHi = 0U;
  c10_info[43].mFileTimeLo = 0U;
  c10_info[43].mFileTimeHi = 0U;
  c10_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c10_info[44].name = "eml_index_class";
  c10_info[44].dominantType = "";
  c10_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c10_info[44].fileTimeLo = 1323202978U;
  c10_info[44].fileTimeHi = 0U;
  c10_info[44].mFileTimeLo = 0U;
  c10_info[44].mFileTimeHi = 0U;
  c10_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c10_info[45].name = "eml_refblas_xnrm2";
  c10_info[45].dominantType = "double";
  c10_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c10_info[45].fileTimeLo = 1299109184U;
  c10_info[45].fileTimeHi = 0U;
  c10_info[45].mFileTimeLo = 0U;
  c10_info[45].mFileTimeHi = 0U;
  c10_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c10_info[46].name = "realmin";
  c10_info[46].dominantType = "char";
  c10_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c10_info[46].fileTimeLo = 1307683642U;
  c10_info[46].fileTimeHi = 0U;
  c10_info[46].mFileTimeLo = 0U;
  c10_info[46].mFileTimeHi = 0U;
  c10_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c10_info[47].name = "eml_realmin";
  c10_info[47].dominantType = "char";
  c10_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c10_info[47].fileTimeLo = 1307683644U;
  c10_info[47].fileTimeHi = 0U;
  c10_info[47].mFileTimeLo = 0U;
  c10_info[47].mFileTimeHi = 0U;
  c10_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c10_info[48].name = "eml_float_model";
  c10_info[48].dominantType = "char";
  c10_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c10_info[48].fileTimeLo = 1326760396U;
  c10_info[48].fileTimeHi = 0U;
  c10_info[48].mFileTimeLo = 0U;
  c10_info[48].mFileTimeHi = 0U;
  c10_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c10_info[49].name = "eml_index_class";
  c10_info[49].dominantType = "";
  c10_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c10_info[49].fileTimeLo = 1323202978U;
  c10_info[49].fileTimeHi = 0U;
  c10_info[49].mFileTimeLo = 0U;
  c10_info[49].mFileTimeHi = 0U;
  c10_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c10_info[50].name = "eml_index_minus";
  c10_info[50].dominantType = "double";
  c10_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c10_info[50].fileTimeLo = 1286851178U;
  c10_info[50].fileTimeHi = 0U;
  c10_info[50].mFileTimeLo = 0U;
  c10_info[50].mFileTimeHi = 0U;
  c10_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c10_info[51].name = "eml_index_times";
  c10_info[51].dominantType = "coder.internal.indexInt";
  c10_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c10_info[51].fileTimeLo = 1286851180U;
  c10_info[51].fileTimeHi = 0U;
  c10_info[51].mFileTimeLo = 0U;
  c10_info[51].mFileTimeHi = 0U;
  c10_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c10_info[52].name = "eml_index_plus";
  c10_info[52].dominantType = "coder.internal.indexInt";
  c10_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c10_info[52].fileTimeLo = 1286851178U;
  c10_info[52].fileTimeHi = 0U;
  c10_info[52].mFileTimeLo = 0U;
  c10_info[52].mFileTimeHi = 0U;
  c10_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c10_info[53].name = "eml_int_forloop_overflow_check";
  c10_info[53].dominantType = "";
  c10_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c10_info[53].fileTimeLo = 1346542740U;
  c10_info[53].fileTimeHi = 0U;
  c10_info[53].mFileTimeLo = 0U;
  c10_info[53].mFileTimeHi = 0U;
  c10_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c10_info[54].name = "abs";
  c10_info[54].dominantType = "double";
  c10_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c10_info[54].fileTimeLo = 1343862766U;
  c10_info[54].fileTimeHi = 0U;
  c10_info[54].mFileTimeLo = 0U;
  c10_info[54].mFileTimeHi = 0U;
  c10_info[55].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c10_info[55].name = "eml_scalar_abs";
  c10_info[55].dominantType = "double";
  c10_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c10_info[55].fileTimeLo = 1286851112U;
  c10_info[55].fileTimeHi = 0U;
  c10_info[55].mFileTimeLo = 0U;
  c10_info[55].mFileTimeHi = 0U;
  c10_info[56].context =
    "[E]C:/Users/Admin/Desktop/AlessioFiles/ManipulatorCODE/ManipulatorME4901/collision_function.p";
  c10_info[56].name = "min";
  c10_info[56].dominantType = "double";
  c10_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c10_info[56].fileTimeLo = 1311287718U;
  c10_info[56].fileTimeHi = 0U;
  c10_info[56].mFileTimeLo = 0U;
  c10_info[56].mFileTimeHi = 0U;
  c10_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c10_info[57].name = "eml_min_or_max";
  c10_info[57].dominantType = "char";
  c10_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c10_info[57].fileTimeLo = 1334103890U;
  c10_info[57].fileTimeHi = 0U;
  c10_info[57].mFileTimeLo = 0U;
  c10_info[57].mFileTimeHi = 0U;
  c10_info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c10_info[58].name = "eml_const_nonsingleton_dim";
  c10_info[58].dominantType = "double";
  c10_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c10_info[58].fileTimeLo = 1286851096U;
  c10_info[58].fileTimeHi = 0U;
  c10_info[58].mFileTimeLo = 0U;
  c10_info[58].mFileTimeHi = 0U;
  c10_info[59].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c10_info[59].name = "eml_scalar_eg";
  c10_info[59].dominantType = "double";
  c10_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c10_info[59].fileTimeLo = 1286851196U;
  c10_info[59].fileTimeHi = 0U;
  c10_info[59].mFileTimeLo = 0U;
  c10_info[59].mFileTimeHi = 0U;
  c10_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c10_info[60].name = "eml_index_class";
  c10_info[60].dominantType = "";
  c10_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c10_info[60].fileTimeLo = 1323202978U;
  c10_info[60].fileTimeHi = 0U;
  c10_info[60].mFileTimeLo = 0U;
  c10_info[60].mFileTimeHi = 0U;
  c10_info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c10_info[61].name = "eml_index_class";
  c10_info[61].dominantType = "";
  c10_info[61].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c10_info[61].fileTimeLo = 1323202978U;
  c10_info[61].fileTimeHi = 0U;
  c10_info[61].mFileTimeLo = 0U;
  c10_info[61].mFileTimeHi = 0U;
  c10_info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c10_info[62].name = "isnan";
  c10_info[62].dominantType = "double";
  c10_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c10_info[62].fileTimeLo = 1286851160U;
  c10_info[62].fileTimeHi = 0U;
  c10_info[62].mFileTimeLo = 0U;
  c10_info[62].mFileTimeHi = 0U;
  c10_info[63].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c10_info[63].name = "eml_index_plus";
  c10_info[63].dominantType = "coder.internal.indexInt";
  c10_info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c10_info[63].fileTimeLo = 1286851178U;
  c10_info[63].fileTimeHi = 0U;
  c10_info[63].mFileTimeLo = 0U;
  c10_info[63].mFileTimeHi = 0U;
}

static void c10_collision_function(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, real_T c10_epsilon, real_T c10_sigma_dock, real_T
  c10_dotsigma_dock, real_T c10_Rbi_A1[4], real_T c10_Rbi_B1[4], real_T
  c10_Xcm_A[9], real_T c10_Xcm_B[9], real_T c10_mesh_A[21], real_T c10_mesh_B[12],
  real_T c10_dock_sensA[3], real_T c10_dock_sensB[3], real_T c10_sigma, real_T
  c10_ma_mb_Ia_Ib[4], real_T c10_dock_sensA_c[2], real_T c10_dock_sensB_c[2],
  real_T c10_n_c[2], real_T c10_QA_c[2], real_T c10_QB_c[2], real_T c10_A[16],
  real_T c10_B[10], real_T *c10_docking, real_T *c10_collision, real_T
  c10_Vcm_an[3], real_T c10_Vcm_bn[3], real_T c10_W_an[3], real_T c10_W_bn[3],
  real_T c10_j[3])
{
  int32_T c10_i140;
  real_T c10_Xcm[10];
  int32_T c10_i141;
  int32_T c10_i142;
  int32_T c10_i143;
  real_T c10_b_Xcm[2];
  int32_T c10_i144;
  real_T c10_cm_a[2];
  real_T c10_c_Xcm[2];
  int32_T c10_i145;
  real_T c10_cm_b[2];
  int32_T c10_i146;
  int32_T c10_i147;
  int32_T c10_i148;
  int32_T c10_i149;
  real_T c10_A_B[14];
  int32_T c10_i150;
  int32_T c10_i151;
  int32_T c10_i152;
  int32_T c10_i153;
  real_T c10_B_B[8];
  int32_T c10_i154;
  int32_T c10_n;
  real_T c10_b_n;
  int32_T c10_c_n;
  int32_T c10_i155;
  real_T c10_b[2];
  int32_T c10_i156;
  real_T c10_r[2];
  int32_T c10_i157;
  int32_T c10_i158;
  int32_T c10_d_n;
  int32_T c10_i159;
  int32_T c10_i160;
  int32_T c10_i161;
  int32_T c10_i162;
  int32_T c10_i163;
  int32_T c10_i164;
  int32_T c10_i165;
  int32_T c10_nn;
  real_T c10_b_nn;
  int32_T c10_c_nn;
  int32_T c10_i166;
  int32_T c10_i167;
  int32_T c10_i168;
  int32_T c10_i169;
  int32_T c10_d_nn;
  int32_T c10_i170;
  int32_T c10_i171;
  int32_T c10_i172;
  int32_T c10_i173;
  int32_T c10_i174;
  int32_T c10_i175;
  int32_T c10_i176;
  int32_T c10_i177;
  int32_T c10_i178;
  int32_T c10_i179;
  int32_T c10_i180;
  int32_T c10_i181;
  int32_T c10_i182;
  int32_T c10_i183;
  int32_T c10_i184;
  int32_T c10_i185;
  int32_T c10_i186;
  real_T c10_SS[4];
  int32_T c10_i187;
  int32_T c10_i188;
  int32_T c10_i189;
  int32_T c10_i190;
  int32_T c10_i191;
  real_T c10_Qb[14];
  int32_T c10_i192;
  real_T c10_Dist[7];
  int32_T c10_i193;
  real_T c10_dist[4];
  int32_T c10_i194;
  int32_T c10_i195;
  real_T c10_min_point_B[8];
  int32_T c10_k;
  real_T c10_b_k;
  int32_T c10_i;
  real_T c10_b_i;
  int32_T c10_c_i;
  int32_T c10_d_i;
  int32_T c10_i196;
  int32_T c10_c_k;
  int32_T c10_d_k;
  int32_T c10_i197;
  int32_T c10_e_i;
  int32_T c10_e_k;
  int32_T c10_i198;
  int32_T c10_i199;
  real_T c10_b_cm_a[2];
  int32_T c10_i200;
  real_T c10_c_cm_a[2];
  real_T c10_a;
  int32_T c10_i201;
  real_T c10_d_cm_a[2];
  int32_T c10_i202;
  real_T c10_b_cm_b[2];
  real_T c10_b_b;
  int32_T c10_i203;
  real_T c10_e_cm_a[2];
  int32_T c10_i204;
  real_T c10_b_r[2];
  real_T c10_c;
  int32_T c10_i205;
  real_T c10_c_cm_b[2];
  int32_T c10_i206;
  real_T c10_d_cm_b[2];
  real_T c10_e;
  int32_T c10_i207;
  real_T c10_e_cm_b[2];
  int32_T c10_i208;
  real_T c10_c_r[2];
  real_T c10_f;
  real_T c10_b_a;
  real_T c10_c_b;
  real_T c10_y;
  real_T c10_c_a;
  real_T c10_d_b;
  real_T c10_b_y;
  real_T c10_denom;
  real_T c10_t1;
  real_T c10_d_a;
  real_T c10_e_b;
  real_T c10_c_y;
  real_T c10_e_a;
  real_T c10_f_b;
  real_T c10_d_y;
  real_T c10_b_A;
  real_T c10_b_B;
  real_T c10_x;
  real_T c10_e_y;
  real_T c10_b_x;
  real_T c10_f_y;
  real_T c10_f_a;
  real_T c10_g_b;
  real_T c10_g_y;
  real_T c10_c_A;
  real_T c10_c_B;
  real_T c10_c_x;
  real_T c10_h_y;
  real_T c10_d_x;
  real_T c10_i_y;
  real_T c10_t2;
  real_T c10_g_a;
  real_T c10_h_b;
  real_T c10_j_y;
  real_T c10_d_A;
  real_T c10_d_B;
  real_T c10_e_x;
  real_T c10_k_y;
  real_T c10_f_x;
  real_T c10_l_y;
  real_T c10_h_a;
  int32_T c10_f_i;
  int32_T c10_g_i;
  int32_T c10_i209;
  int32_T c10_i210;
  int32_T c10_h_i;
  int32_T c10_i_i;
  int32_T c10_i211;
  real_T c10_i_a;
  int32_T c10_f_k;
  int32_T c10_g_k;
  int32_T c10_i212;
  int32_T c10_i213;
  int32_T c10_j_i;
  int32_T c10_h_k;
  int32_T c10_i214;
  int32_T c10_k_i;
  int32_T c10_l_i;
  int32_T c10_i215;
  real_T c10_b_Qb[2];
  int32_T c10_ixstart;
  real_T c10_mtmp;
  int32_T c10_itmp;
  real_T c10_g_x;
  boolean_T c10_i_b;
  int32_T c10_ix;
  int32_T c10_b_ix;
  real_T c10_h_x;
  boolean_T c10_j_b;
  int32_T c10_j_a;
  int32_T c10_i216;
  boolean_T c10_overflow;
  int32_T c10_c_ix;
  real_T c10_k_a;
  real_T c10_k_b;
  boolean_T c10_p;
  int32_T c10_b_itmp;
  int32_T c10_iindx;
  int32_T c10_b_iindx;
  real_T c10_indx;
  real_T c10_i_dist;
  real_T c10_b_i_dist;
  int32_T c10_i_k;
  int32_T c10_c_i_dist;
  int32_T c10_i217;
  int32_T c10_j_k;
  int32_T c10_d_i_dist;
  int32_T c10_i218;
  int32_T c10_k_k;
  int32_T c10_l_k;
  int32_T c10_i219;
  real_T c10_b_min_point_B[2];
  int32_T c10_b_ixstart;
  real_T c10_b_mtmp;
  int32_T c10_c_itmp;
  real_T c10_i_x;
  boolean_T c10_l_b;
  int32_T c10_d_ix;
  int32_T c10_e_ix;
  real_T c10_j_x;
  boolean_T c10_m_b;
  int32_T c10_l_a;
  int32_T c10_i220;
  boolean_T c10_b_overflow;
  int32_T c10_f_ix;
  real_T c10_m_a;
  real_T c10_n_b;
  boolean_T c10_b_p;
  real_T c10_c_mtmp;
  int32_T c10_d_itmp;
  real_T c10_extremum;
  int32_T c10_c_iindx;
  real_T c10_minval;
  int32_T c10_d_iindx;
  real_T c10_b_indx;
  real_T c10_dist_f_value;
  real_T c10_kk_dist;
  real_T c10_b_dist_f_value;
  real_T c10_b_kk_dist;
  int32_T c10_c_kk_dist;
  int32_T c10_i221;
  int32_T c10_d_kk_dist;
  int32_T c10_i222;
  real_T c10_contact;
  int32_T c10_e_kk_dist;
  int32_T c10_f_kk_dist;
  int32_T c10_i223;
  int32_T c10_g_kk_dist;
  int32_T c10_h_kk_dist;
  int32_T c10_i224;
  real_T c10_e_B[2];
  real_T c10_f_B;
  real_T c10_m_y;
  real_T c10_n_y;
  int32_T c10_i225;
  real_T c10_f_cm_a[2];
  int32_T c10_i226;
  int32_T c10_i227;
  real_T c10_Si_a[3];
  int32_T c10_i228;
  real_T c10_Si_b[3];
  real_T c10_x_a;
  real_T c10_y_a;
  real_T c10_vx_a;
  real_T c10_vy_a;
  real_T c10_w_a;
  real_T c10_b_x_a[3];
  int32_T c10_i229;
  real_T c10_Xcm_a[3];
  real_T c10_b_vx_a[3];
  int32_T c10_i230;
  real_T c10_Vcm_a[3];
  real_T c10_dv16[3];
  int32_T c10_i231;
  real_T c10_W_a[3];
  real_T c10_x_b;
  real_T c10_y_b;
  real_T c10_vx_b;
  real_T c10_vy_b;
  real_T c10_w_b;
  real_T c10_b_x_b[3];
  int32_T c10_i232;
  real_T c10_Xcm_b[3];
  real_T c10_b_vx_b[3];
  int32_T c10_i233;
  real_T c10_Vcm_b[3];
  real_T c10_dv17[3];
  int32_T c10_i234;
  real_T c10_W_b[3];
  int32_T c10_i235;
  int32_T c10_i236;
  int32_T c10_i237;
  real_T c10_b_W_a[3];
  int32_T c10_i238;
  real_T c10_b_Xcm_a[3];
  real_T c10_dv18[3];
  int32_T c10_i239;
  int32_T c10_i240;
  real_T c10_b_W_b[3];
  int32_T c10_i241;
  real_T c10_b_Xcm_b[3];
  int32_T c10_i242;
  int32_T c10_i243;
  real_T c10_b_Si_a[3];
  int32_T c10_i244;
  real_T c10_b_Vcm_a[3];
  real_T c10_ma;
  real_T c10_mb;
  real_T c10_Ia;
  real_T c10_Ib;
  int32_T c10_i245;
  int32_T c10_i246;
  int32_T c10_i247;
  real_T c10_N_cb[3];
  real_T c10_c_x_a[3];
  int32_T c10_i248;
  real_T c10_c_vx_a[3];
  int32_T c10_i249;
  real_T c10_dv19[3];
  int32_T c10_i250;
  real_T c10_c_x_b[3];
  int32_T c10_i251;
  real_T c10_c_vx_b[3];
  int32_T c10_i252;
  real_T c10_dv20[3];
  int32_T c10_i253;
  int32_T c10_i254;
  int32_T c10_i255;
  int32_T c10_i256;
  real_T c10_c_W_a[3];
  int32_T c10_i257;
  real_T c10_c_Xcm_a[3];
  real_T c10_Va_c[3];
  int32_T c10_i258;
  int32_T c10_i259;
  real_T c10_c_W_b[3];
  int32_T c10_i260;
  real_T c10_c_Xcm_b[3];
  int32_T c10_i261;
  int32_T c10_i262;
  int32_T c10_i263;
  int32_T c10_i264;
  int32_T c10_i265;
  int32_T c10_i266;
  int32_T c10_i267;
  int32_T c10_i268;
  real_T c10_b_Va_c[3];
  int32_T c10_i269;
  real_T c10_b_N_cb[3];
  real_T c10_g_B;
  real_T c10_o_y;
  real_T c10_p_y;
  real_T c10_q_y;
  real_T c10_h_B;
  real_T c10_r_y;
  real_T c10_s_y;
  real_T c10_t_y;
  real_T c10_e_A;
  int32_T c10_i270;
  real_T c10_d_Xcm_a[3];
  int32_T c10_i271;
  real_T c10_c_N_cb[3];
  int32_T c10_i272;
  real_T c10_dv21[3];
  int32_T c10_i273;
  real_T c10_e_Xcm_a[3];
  real_T c10_u_y;
  real_T c10_v_y;
  int32_T c10_i274;
  real_T c10_f_A;
  int32_T c10_i275;
  real_T c10_d_Xcm_b[3];
  int32_T c10_i276;
  real_T c10_d_N_cb[3];
  int32_T c10_i277;
  real_T c10_dv22[3];
  int32_T c10_i278;
  real_T c10_e_Xcm_b[3];
  real_T c10_w_y;
  real_T c10_x_y;
  int32_T c10_i279;
  int32_T c10_i280;
  real_T c10_b_Si_b[3];
  int32_T c10_i281;
  real_T c10_e_N_cb[3];
  real_T c10_kn;
  int32_T c10_i282;
  real_T c10_c_Va_c[3];
  int32_T c10_i283;
  real_T c10_f_N_cb[3];
  real_T c10_n_a;
  real_T c10_o_b;
  real_T c10_y_y;
  real_T c10_g_A;
  real_T c10_i_B;
  real_T c10_k_x;
  real_T c10_ab_y;
  real_T c10_l_x;
  real_T c10_bb_y;
  real_T c10_jn;
  real_T c10_o_a;
  int32_T c10_i284;
  real_T c10_j_B;
  real_T c10_cb_y;
  real_T c10_db_y;
  int32_T c10_i285;
  int32_T c10_i286;
  real_T c10_h_A;
  int32_T c10_i287;
  real_T c10_f_Xcm_a[3];
  int32_T c10_i288;
  real_T c10_b_j[3];
  real_T c10_eb_y;
  real_T c10_fb_y;
  int32_T c10_i289;
  int32_T c10_i290;
  real_T c10_k_B;
  real_T c10_gb_y;
  real_T c10_hb_y;
  int32_T c10_i291;
  int32_T c10_i292;
  real_T c10_i_A;
  int32_T c10_i293;
  real_T c10_f_Xcm_b[3];
  int32_T c10_i294;
  real_T c10_c_j[3];
  real_T c10_ib_y;
  real_T c10_jb_y;
  int32_T c10_i295;
  int32_T c10_i296;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T exitg1;
  boolean_T exitg2;
  for (c10_i140 = 0; c10_i140 < 2; c10_i140++) {
    c10_Xcm[c10_i140] = c10_Xcm_A[c10_i140];
  }

  for (c10_i141 = 0; c10_i141 < 2; c10_i141++) {
    c10_Xcm[c10_i141 + 2] = c10_Xcm_A[c10_i141 + 3];
  }

  c10_Xcm[4] = c10_Xcm_A[8];
  for (c10_i142 = 0; c10_i142 < 2; c10_i142++) {
    c10_Xcm[c10_i142 + 5] = c10_Xcm_B[c10_i142];
  }

  for (c10_i143 = 0; c10_i143 < 2; c10_i143++) {
    c10_Xcm[c10_i143 + 7] = c10_Xcm_B[c10_i143 + 3];
  }

  c10_Xcm[9] = c10_Xcm_B[8];
  c10_b_Xcm[0] = c10_Xcm[0];
  c10_b_Xcm[1] = c10_Xcm[1];
  for (c10_i144 = 0; c10_i144 < 2; c10_i144++) {
    c10_cm_a[c10_i144] = c10_b_Xcm[c10_i144];
  }

  c10_c_Xcm[0] = c10_Xcm[5];
  c10_c_Xcm[1] = c10_Xcm[6];
  for (c10_i145 = 0; c10_i145 < 2; c10_i145++) {
    c10_cm_b[c10_i145] = c10_c_Xcm[c10_i145];
  }

  c10_i146 = 0;
  c10_i147 = 0;
  for (c10_i148 = 0; c10_i148 < 7; c10_i148++) {
    for (c10_i149 = 0; c10_i149 < 2; c10_i149++) {
      c10_A_B[c10_i149 + c10_i146] = c10_mesh_A[c10_i149 + c10_i147];
    }

    c10_i146 += 2;
    c10_i147 += 3;
  }

  c10_i150 = 0;
  c10_i151 = 0;
  for (c10_i152 = 0; c10_i152 < 4; c10_i152++) {
    for (c10_i153 = 0; c10_i153 < 2; c10_i153++) {
      c10_B_B[c10_i153 + c10_i150] = c10_mesh_B[c10_i153 + c10_i151];
    }

    c10_i150 += 2;
    c10_i151 += 3;
  }

  for (c10_i154 = 0; c10_i154 < 16; c10_i154++) {
    c10_A[c10_i154] = 0.0;
  }

  c10_n = 0;
  while (c10_n < 7) {
    c10_b_n = 1.0 + (real_T)c10_n;
    c10_c_n = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c10_b_n), 1, 7, 2, 0) - 1;
    for (c10_i155 = 0; c10_i155 < 2; c10_i155++) {
      c10_b[c10_i155] = c10_A_B[c10_i155 + (c10_c_n << 1)];
    }

    c10_eml_scalar_eg(chartInstance);
    c10_eml_scalar_eg(chartInstance);
    for (c10_i156 = 0; c10_i156 < 2; c10_i156++) {
      c10_r[c10_i156] = 0.0;
      c10_i157 = 0;
      for (c10_i158 = 0; c10_i158 < 2; c10_i158++) {
        c10_r[c10_i156] += c10_Rbi_A1[c10_i157 + c10_i156] * c10_b[c10_i158];
        c10_i157 += 2;
      }
    }

    c10_d_n = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c10_b_n), 1, 8, 2, 0) - 1;
    for (c10_i159 = 0; c10_i159 < 2; c10_i159++) {
      c10_A[c10_i159 + (c10_d_n << 1)] = c10_cm_a[c10_i159] + c10_r[c10_i159];
    }

    c10_n++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  for (c10_i160 = 0; c10_i160 < 2; c10_i160++) {
    c10_b[c10_i160] = c10_A_B[c10_i160];
  }

  c10_eml_scalar_eg(chartInstance);
  c10_eml_scalar_eg(chartInstance);
  for (c10_i161 = 0; c10_i161 < 2; c10_i161++) {
    c10_r[c10_i161] = 0.0;
    c10_i162 = 0;
    for (c10_i163 = 0; c10_i163 < 2; c10_i163++) {
      c10_r[c10_i161] += c10_Rbi_A1[c10_i162 + c10_i161] * c10_b[c10_i163];
      c10_i162 += 2;
    }
  }

  for (c10_i164 = 0; c10_i164 < 2; c10_i164++) {
    c10_A[c10_i164 + 14] = c10_cm_a[c10_i164] + c10_r[c10_i164];
  }

  for (c10_i165 = 0; c10_i165 < 10; c10_i165++) {
    c10_B[c10_i165] = 0.0;
  }

  c10_nn = 0;
  while (c10_nn < 4) {
    c10_b_nn = 1.0 + (real_T)c10_nn;
    c10_c_nn = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c10_b_nn), 1, 4, 2, 0) - 1;
    for (c10_i166 = 0; c10_i166 < 2; c10_i166++) {
      c10_b[c10_i166] = c10_B_B[c10_i166 + (c10_c_nn << 1)];
    }

    c10_eml_scalar_eg(chartInstance);
    c10_eml_scalar_eg(chartInstance);
    for (c10_i167 = 0; c10_i167 < 2; c10_i167++) {
      c10_r[c10_i167] = 0.0;
      c10_i168 = 0;
      for (c10_i169 = 0; c10_i169 < 2; c10_i169++) {
        c10_r[c10_i167] += c10_Rbi_B1[c10_i168 + c10_i167] * c10_b[c10_i169];
        c10_i168 += 2;
      }
    }

    c10_d_nn = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c10_b_nn), 1, 5, 2, 0) - 1;
    for (c10_i170 = 0; c10_i170 < 2; c10_i170++) {
      c10_B[c10_i170 + (c10_d_nn << 1)] = c10_cm_b[c10_i170] + c10_r[c10_i170];
    }

    c10_nn++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  for (c10_i171 = 0; c10_i171 < 2; c10_i171++) {
    c10_b[c10_i171] = c10_B_B[c10_i171];
  }

  c10_eml_scalar_eg(chartInstance);
  c10_eml_scalar_eg(chartInstance);
  for (c10_i172 = 0; c10_i172 < 2; c10_i172++) {
    c10_r[c10_i172] = 0.0;
    c10_i173 = 0;
    for (c10_i174 = 0; c10_i174 < 2; c10_i174++) {
      c10_r[c10_i172] += c10_Rbi_B1[c10_i173 + c10_i172] * c10_b[c10_i174];
      c10_i173 += 2;
    }
  }

  for (c10_i175 = 0; c10_i175 < 2; c10_i175++) {
    c10_B[c10_i175 + 8] = c10_cm_b[c10_i175] + c10_r[c10_i175];
  }

  for (c10_i176 = 0; c10_i176 < 2; c10_i176++) {
    c10_b[c10_i176] = c10_dock_sensA[c10_i176];
  }

  c10_eml_scalar_eg(chartInstance);
  c10_eml_scalar_eg(chartInstance);
  for (c10_i177 = 0; c10_i177 < 2; c10_i177++) {
    c10_r[c10_i177] = 0.0;
    c10_i178 = 0;
    for (c10_i179 = 0; c10_i179 < 2; c10_i179++) {
      c10_r[c10_i177] += c10_Rbi_A1[c10_i178 + c10_i177] * c10_b[c10_i179];
      c10_i178 += 2;
    }
  }

  for (c10_i180 = 0; c10_i180 < 2; c10_i180++) {
    c10_cm_a[c10_i180] += c10_r[c10_i180];
  }

  for (c10_i181 = 0; c10_i181 < 2; c10_i181++) {
    c10_b[c10_i181] = c10_dock_sensB[c10_i181];
  }

  c10_eml_scalar_eg(chartInstance);
  c10_eml_scalar_eg(chartInstance);
  for (c10_i182 = 0; c10_i182 < 2; c10_i182++) {
    c10_r[c10_i182] = 0.0;
    c10_i183 = 0;
    for (c10_i184 = 0; c10_i184 < 2; c10_i184++) {
      c10_r[c10_i182] += c10_Rbi_B1[c10_i183 + c10_i182] * c10_b[c10_i184];
      c10_i183 += 2;
    }
  }

  for (c10_i185 = 0; c10_i185 < 2; c10_i185++) {
    c10_cm_b[c10_i185] += c10_r[c10_i185];
  }

  for (c10_i186 = 0; c10_i186 < 2; c10_i186++) {
    c10_SS[c10_i186] = c10_cm_a[c10_i186];
  }

  for (c10_i187 = 0; c10_i187 < 2; c10_i187++) {
    c10_SS[c10_i187 + 2] = c10_cm_b[c10_i187];
  }

  for (c10_i188 = 0; c10_i188 < 2; c10_i188++) {
    c10_dock_sensA_c[c10_i188] = c10_SS[c10_i188];
  }

  for (c10_i189 = 0; c10_i189 < 2; c10_i189++) {
    c10_dock_sensB_c[c10_i189] = c10_SS[c10_i189 + 2];
  }

  for (c10_i190 = 0; c10_i190 < 14; c10_i190++) {
    c10_A_B[c10_i190] = 0.0;
  }

  for (c10_i191 = 0; c10_i191 < 14; c10_i191++) {
    c10_Qb[c10_i191] = 0.0;
  }

  for (c10_i192 = 0; c10_i192 < 7; c10_i192++) {
    c10_Dist[c10_i192] = 0.0;
  }

  for (c10_i193 = 0; c10_i193 < 4; c10_i193++) {
    c10_dist[c10_i193] = 0.0;
  }

  for (c10_i194 = 0; c10_i194 < 8; c10_i194++) {
    c10_B_B[c10_i194] = 0.0;
  }

  for (c10_i195 = 0; c10_i195 < 8; c10_i195++) {
    c10_min_point_B[c10_i195] = 0.0;
  }

  c10_k = 0;
  while (c10_k < 4) {
    c10_b_k = 1.0 + (real_T)c10_k;
    c10_i = 0;
    while (c10_i < 7) {
      c10_b_i = 1.0 + (real_T)c10_i;
      c10_c_i = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c10_b_i + 1.0), 1, 8, 2, 0) - 1;
      c10_d_i = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c10_b_i), 1, 8, 2, 0) - 1;
      for (c10_i196 = 0; c10_i196 < 2; c10_i196++) {
        c10_cm_a[c10_i196] = c10_A[c10_i196 + (c10_c_i << 1)] - c10_A[c10_i196 +
          (c10_d_i << 1)];
      }

      c10_c_k = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c10_b_k + 1.0), 1, 5, 2, 0) - 1;
      c10_d_k = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c10_b_k), 1, 5, 2, 0) - 1;
      for (c10_i197 = 0; c10_i197 < 2; c10_i197++) {
        c10_cm_b[c10_i197] = c10_B[c10_i197 + (c10_c_k << 1)] - c10_B[c10_i197 +
          (c10_d_k << 1)];
      }

      c10_e_i = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c10_b_i), 1, 8, 2, 0) - 1;
      c10_e_k = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c10_b_k), 1, 5, 2, 0) - 1;
      for (c10_i198 = 0; c10_i198 < 2; c10_i198++) {
        c10_r[c10_i198] = c10_A[c10_i198 + (c10_e_i << 1)] - c10_B[c10_i198 +
          (c10_e_k << 1)];
      }

      for (c10_i199 = 0; c10_i199 < 2; c10_i199++) {
        c10_b_cm_a[c10_i199] = c10_cm_a[c10_i199];
      }

      for (c10_i200 = 0; c10_i200 < 2; c10_i200++) {
        c10_c_cm_a[c10_i200] = c10_cm_a[c10_i200];
      }

      c10_a = c10_dot(chartInstance, c10_b_cm_a, c10_c_cm_a);
      for (c10_i201 = 0; c10_i201 < 2; c10_i201++) {
        c10_d_cm_a[c10_i201] = c10_cm_a[c10_i201];
      }

      for (c10_i202 = 0; c10_i202 < 2; c10_i202++) {
        c10_b_cm_b[c10_i202] = c10_cm_b[c10_i202];
      }

      c10_b_b = c10_dot(chartInstance, c10_d_cm_a, c10_b_cm_b);
      for (c10_i203 = 0; c10_i203 < 2; c10_i203++) {
        c10_e_cm_a[c10_i203] = c10_cm_a[c10_i203];
      }

      for (c10_i204 = 0; c10_i204 < 2; c10_i204++) {
        c10_b_r[c10_i204] = c10_r[c10_i204];
      }

      c10_c = c10_dot(chartInstance, c10_e_cm_a, c10_b_r);
      for (c10_i205 = 0; c10_i205 < 2; c10_i205++) {
        c10_c_cm_b[c10_i205] = c10_cm_b[c10_i205];
      }

      for (c10_i206 = 0; c10_i206 < 2; c10_i206++) {
        c10_d_cm_b[c10_i206] = c10_cm_b[c10_i206];
      }

      c10_e = c10_dot(chartInstance, c10_c_cm_b, c10_d_cm_b);
      for (c10_i207 = 0; c10_i207 < 2; c10_i207++) {
        c10_e_cm_b[c10_i207] = c10_cm_b[c10_i207];
      }

      for (c10_i208 = 0; c10_i208 < 2; c10_i208++) {
        c10_c_r[c10_i208] = c10_r[c10_i208];
      }

      c10_f = c10_dot(chartInstance, c10_e_cm_b, c10_c_r);
      c10_b_a = c10_a;
      c10_c_b = c10_e;
      c10_y = c10_b_a * c10_c_b;
      c10_c_a = c10_b_b;
      c10_d_b = c10_b_b;
      c10_b_y = c10_c_a * c10_d_b;
      c10_denom = c10_y - c10_b_y;
      if (c10_denom == 0.0) {
        c10_t1 = 0.5;
      } else {
        c10_d_a = c10_b_b;
        c10_e_b = c10_f;
        c10_c_y = c10_d_a * c10_e_b;
        c10_e_a = c10_c;
        c10_f_b = c10_e;
        c10_d_y = c10_e_a * c10_f_b;
        c10_b_A = c10_c_y - c10_d_y;
        c10_b_B = c10_denom;
        c10_x = c10_b_A;
        c10_e_y = c10_b_B;
        c10_b_x = c10_x;
        c10_f_y = c10_e_y;
        c10_t1 = c10_b_x / c10_f_y;
        if (c10_t1 < 0.0) {
          c10_t1 = 0.0;
        } else {
          if (c10_t1 > 1.0) {
            c10_t1 = 1.0;
          }
        }
      }

      c10_f_a = c10_b_b;
      c10_g_b = c10_t1;
      c10_g_y = c10_f_a * c10_g_b;
      c10_c_A = c10_g_y + c10_f;
      c10_c_B = c10_e;
      c10_c_x = c10_c_A;
      c10_h_y = c10_c_B;
      c10_d_x = c10_c_x;
      c10_i_y = c10_h_y;
      c10_t2 = c10_d_x / c10_i_y;
      if (c10_t2 < 0.0) {
        c10_t2 = 0.0;
      } else {
        if (c10_t2 > 1.0) {
          c10_t2 = 1.0;
        }
      }

      c10_g_a = c10_b_b;
      c10_h_b = c10_t2;
      c10_j_y = c10_g_a * c10_h_b;
      c10_d_A = c10_j_y - c10_c;
      c10_d_B = c10_a;
      c10_e_x = c10_d_A;
      c10_k_y = c10_d_B;
      c10_f_x = c10_e_x;
      c10_l_y = c10_k_y;
      c10_t1 = c10_f_x / c10_l_y;
      if (c10_t1 < 0.0) {
        c10_t1 = 0.0;
      } else {
        if (c10_t1 > 1.0) {
          c10_t1 = 1.0;
        }
      }

      c10_h_a = c10_t1;
      c10_f_i = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c10_b_i + 1.0), 1, 8, 2, 0) - 1;
      c10_g_i = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c10_b_i), 1, 8, 2, 0) - 1;
      for (c10_i209 = 0; c10_i209 < 2; c10_i209++) {
        c10_b[c10_i209] = c10_A[c10_i209 + (c10_f_i << 1)] - c10_A[c10_i209 +
          (c10_g_i << 1)];
      }

      for (c10_i210 = 0; c10_i210 < 2; c10_i210++) {
        c10_b[c10_i210] *= c10_h_a;
      }

      c10_h_i = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c10_b_i), 1, 7, 2, 0) - 1;
      c10_i_i = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c10_b_i), 1, 8, 2, 0) - 1;
      for (c10_i211 = 0; c10_i211 < 2; c10_i211++) {
        c10_A_B[c10_i211 + (c10_h_i << 1)] = c10_A[c10_i211 + (c10_i_i << 1)] +
          c10_b[c10_i211];
      }

      (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c10_b_k + 1.0), 1, 5, 2, 0);
      (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c10_b_k), 1, 5, 2, 0);
      (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c10_b_k), 1, 5, 2, 0);
      (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c10_b_k), 1, 4, 2, 0);
      c10_i_a = c10_t2;
      c10_f_k = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c10_b_k + 1.0), 1, 5, 2, 0) - 1;
      c10_g_k = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c10_b_k), 1, 5, 2, 0) - 1;
      for (c10_i212 = 0; c10_i212 < 2; c10_i212++) {
        c10_b[c10_i212] = c10_B[c10_i212 + (c10_f_k << 1)] - c10_B[c10_i212 +
          (c10_g_k << 1)];
      }

      for (c10_i213 = 0; c10_i213 < 2; c10_i213++) {
        c10_b[c10_i213] *= c10_i_a;
      }

      c10_j_i = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c10_b_i), 1, 7, 2, 0) - 1;
      c10_h_k = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c10_b_k), 1, 5, 2, 0) - 1;
      for (c10_i214 = 0; c10_i214 < 2; c10_i214++) {
        c10_Qb[c10_i214 + (c10_j_i << 1)] = c10_B[c10_i214 + (c10_h_k << 1)] +
          c10_b[c10_i214];
      }

      c10_k_i = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c10_b_i), 1, 7, 2, 0) - 1;
      c10_l_i = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c10_b_i), 1, 7, 2, 0) - 1;
      for (c10_i215 = 0; c10_i215 < 2; c10_i215++) {
        c10_b_Qb[c10_i215] = c10_Qb[c10_i215 + (c10_k_i << 1)] -
          c10_A_B[c10_i215 + (c10_l_i << 1)];
      }

      c10_Dist[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c10_b_i), 1, 7, 1, 0) - 1] = c10_norm
        (chartInstance, c10_b_Qb);
      c10_i++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    c10_ixstart = 1;
    c10_mtmp = c10_Dist[0];
    c10_itmp = 1;
    c10_g_x = c10_mtmp;
    c10_i_b = muDoubleScalarIsNaN(c10_g_x);
    if (c10_i_b) {
      c10_ix = 2;
      exitg2 = FALSE;
      while ((exitg2 == FALSE) && (c10_ix < 8)) {
        c10_b_ix = c10_ix;
        c10_ixstart = c10_b_ix;
        c10_h_x = c10_Dist[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c10_b_ix), 1, 7, 1, 0) - 1];
        c10_j_b = muDoubleScalarIsNaN(c10_h_x);
        if (!c10_j_b) {
          c10_mtmp = c10_Dist[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c10_b_ix), 1, 7, 1, 0) - 1];
          c10_itmp = c10_b_ix;
          exitg2 = TRUE;
        } else {
          c10_ix++;
        }
      }
    }

    if (c10_ixstart < 7) {
      c10_j_a = c10_ixstart;
      c10_i216 = c10_j_a;
      c10_overflow = FALSE;
      if (c10_overflow) {
        c10_check_forloop_overflow_error(chartInstance, c10_overflow);
      }

      for (c10_c_ix = c10_i216 + 1; c10_c_ix < 8; c10_c_ix++) {
        c10_b_ix = c10_c_ix;
        c10_k_a = c10_Dist[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c10_b_ix), 1, 7, 1, 0) - 1];
        c10_k_b = c10_mtmp;
        c10_p = (c10_k_a < c10_k_b);
        if (c10_p) {
          c10_mtmp = c10_Dist[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c10_b_ix), 1, 7, 1, 0) - 1];
          c10_itmp = c10_b_ix;
        }
      }
    }

    c10_b_itmp = c10_itmp;
    c10_iindx = c10_b_itmp;
    c10_b_iindx = c10_iindx;
    c10_indx = (real_T)c10_b_iindx;
    c10_i_dist = c10_indx;
    c10_b_i_dist = c10_i_dist;
    c10_i_k = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c10_b_k), 1, 4, 2, 0) - 1;
    c10_c_i_dist = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c10_b_i_dist), 1, 7, 2, 0) - 1;
    for (c10_i217 = 0; c10_i217 < 2; c10_i217++) {
      c10_B_B[c10_i217 + (c10_i_k << 1)] = c10_A_B[c10_i217 + (c10_c_i_dist << 1)];
    }

    c10_j_k = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c10_b_k), 1, 4, 2, 0) - 1;
    c10_d_i_dist = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c10_b_i_dist), 1, 7, 2, 0) - 1;
    for (c10_i218 = 0; c10_i218 < 2; c10_i218++) {
      c10_min_point_B[c10_i218 + (c10_j_k << 1)] = c10_Qb[c10_i218 +
        (c10_d_i_dist << 1)];
    }

    c10_k_k = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c10_b_k), 1, 4, 2, 0) - 1;
    c10_l_k = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c10_b_k), 1, 4, 2, 0) - 1;
    for (c10_i219 = 0; c10_i219 < 2; c10_i219++) {
      c10_b_min_point_B[c10_i219] = c10_min_point_B[c10_i219 + (c10_k_k << 1)] -
        c10_B_B[c10_i219 + (c10_l_k << 1)];
    }

    c10_dist[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c10_b_k), 1, 4, 1, 0) - 1] = c10_norm(chartInstance,
      c10_b_min_point_B);
    c10_k++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  c10_b_ixstart = 1;
  c10_b_mtmp = c10_dist[0];
  c10_c_itmp = 1;
  c10_i_x = c10_b_mtmp;
  c10_l_b = muDoubleScalarIsNaN(c10_i_x);
  if (c10_l_b) {
    c10_d_ix = 2;
    exitg1 = FALSE;
    while ((exitg1 == FALSE) && (c10_d_ix < 5)) {
      c10_e_ix = c10_d_ix;
      c10_b_ixstart = c10_e_ix;
      c10_j_x = c10_dist[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c10_e_ix), 1, 4, 1, 0) - 1];
      c10_m_b = muDoubleScalarIsNaN(c10_j_x);
      if (!c10_m_b) {
        c10_b_mtmp = c10_dist[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c10_e_ix), 1, 4, 1, 0) - 1];
        c10_c_itmp = c10_e_ix;
        exitg1 = TRUE;
      } else {
        c10_d_ix++;
      }
    }
  }

  if (c10_b_ixstart < 4) {
    c10_l_a = c10_b_ixstart;
    c10_i220 = c10_l_a;
    c10_b_overflow = FALSE;
    if (c10_b_overflow) {
      c10_b_check_forloop_overflow_error(chartInstance, c10_b_overflow);
    }

    for (c10_f_ix = c10_i220 + 1; c10_f_ix < 5; c10_f_ix++) {
      c10_e_ix = c10_f_ix;
      c10_m_a = c10_dist[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c10_e_ix), 1, 4, 1, 0) - 1];
      c10_n_b = c10_b_mtmp;
      c10_b_p = (c10_m_a < c10_n_b);
      if (c10_b_p) {
        c10_b_mtmp = c10_dist[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c10_e_ix), 1, 4, 1, 0) - 1];
        c10_c_itmp = c10_e_ix;
      }
    }
  }

  c10_c_mtmp = c10_b_mtmp;
  c10_d_itmp = c10_c_itmp;
  c10_extremum = c10_c_mtmp;
  c10_c_iindx = c10_d_itmp;
  c10_minval = c10_extremum;
  c10_d_iindx = c10_c_iindx;
  c10_b_indx = (real_T)c10_d_iindx;
  c10_dist_f_value = c10_minval;
  c10_kk_dist = c10_b_indx;
  c10_b_dist_f_value = c10_dist_f_value;
  c10_b_kk_dist = c10_kk_dist;
  c10_c_kk_dist = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", c10_b_kk_dist), 1, 4, 2, 0) - 1;
  for (c10_i221 = 0; c10_i221 < 2; c10_i221++) {
    c10_QA_c[c10_i221] = c10_B_B[c10_i221 + (c10_c_kk_dist << 1)];
  }

  c10_d_kk_dist = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", c10_b_kk_dist), 1, 4, 2, 0) - 1;
  for (c10_i222 = 0; c10_i222 < 2; c10_i222++) {
    c10_QB_c[c10_i222] = c10_min_point_B[c10_i222 + (c10_d_kk_dist << 1)];
  }

  if (c10_b_dist_f_value < c10_sigma) {
    c10_contact = 1.0;
  } else {
    c10_contact = 0.0;
  }

  c10_e_kk_dist = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", c10_b_kk_dist + 1.0), 1, 5, 2, 0) - 1;
  c10_f_kk_dist = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", c10_b_kk_dist), 1, 5, 2, 0) - 1;
  for (c10_i223 = 0; c10_i223 < 2; c10_i223++) {
    c10_cm_a[c10_i223] = c10_B[c10_i223 + (c10_e_kk_dist << 1)] - c10_B[c10_i223
      + (c10_f_kk_dist << 1)];
  }

  c10_g_kk_dist = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", c10_b_kk_dist + 1.0), 1, 5, 2, 0) - 1;
  c10_h_kk_dist = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", c10_b_kk_dist), 1, 5, 2, 0) - 1;
  for (c10_i224 = 0; c10_i224 < 2; c10_i224++) {
    c10_e_B[c10_i224] = c10_B[c10_i224 + (c10_g_kk_dist << 1)] - c10_B[c10_i224
      + (c10_h_kk_dist << 1)];
  }

  c10_f_B = c10_norm(chartInstance, c10_e_B);
  c10_m_y = c10_f_B;
  c10_n_y = c10_m_y;
  for (c10_i225 = 0; c10_i225 < 2; c10_i225++) {
    c10_cm_a[c10_i225] /= c10_n_y;
  }

  c10_f_cm_a[0] = -c10_cm_a[1];
  c10_f_cm_a[1] = c10_cm_a[0];
  for (c10_i226 = 0; c10_i226 < 2; c10_i226++) {
    c10_n_c[c10_i226] = c10_f_cm_a[c10_i226];
  }

  for (c10_i227 = 0; c10_i227 < 2; c10_i227++) {
    c10_Si_a[c10_i227] = c10_dock_sensA_c[c10_i227];
  }

  c10_Si_a[2] = 0.0;
  for (c10_i228 = 0; c10_i228 < 2; c10_i228++) {
    c10_Si_b[c10_i228] = c10_dock_sensB_c[c10_i228];
  }

  c10_Si_b[2] = 0.0;
  c10_x_a = c10_Xcm[0];
  c10_y_a = c10_Xcm[1];
  c10_vx_a = c10_Xcm[2];
  c10_vy_a = c10_Xcm[3];
  c10_w_a = c10_Xcm[4];
  c10_b_x_a[0] = c10_x_a;
  c10_b_x_a[1] = c10_y_a;
  c10_b_x_a[2] = 0.0;
  for (c10_i229 = 0; c10_i229 < 3; c10_i229++) {
    c10_Xcm_a[c10_i229] = c10_b_x_a[c10_i229];
  }

  c10_b_vx_a[0] = c10_vx_a;
  c10_b_vx_a[1] = c10_vy_a;
  c10_b_vx_a[2] = 0.0;
  for (c10_i230 = 0; c10_i230 < 3; c10_i230++) {
    c10_Vcm_a[c10_i230] = c10_b_vx_a[c10_i230];
  }

  c10_dv16[0] = 0.0;
  c10_dv16[1] = 0.0;
  c10_dv16[2] = c10_w_a;
  for (c10_i231 = 0; c10_i231 < 3; c10_i231++) {
    c10_W_a[c10_i231] = c10_dv16[c10_i231];
  }

  c10_x_b = c10_Xcm[5];
  c10_y_b = c10_Xcm[6];
  c10_vx_b = c10_Xcm[7];
  c10_vy_b = c10_Xcm[8];
  c10_w_b = c10_Xcm[9];
  c10_b_x_b[0] = c10_x_b;
  c10_b_x_b[1] = c10_y_b;
  c10_b_x_b[2] = 0.0;
  for (c10_i232 = 0; c10_i232 < 3; c10_i232++) {
    c10_Xcm_b[c10_i232] = c10_b_x_b[c10_i232];
  }

  c10_b_vx_b[0] = c10_vx_b;
  c10_b_vx_b[1] = c10_vy_b;
  c10_b_vx_b[2] = 0.0;
  for (c10_i233 = 0; c10_i233 < 3; c10_i233++) {
    c10_Vcm_b[c10_i233] = c10_b_vx_b[c10_i233];
  }

  c10_dv17[0] = 0.0;
  c10_dv17[1] = 0.0;
  c10_dv17[2] = c10_w_b;
  for (c10_i234 = 0; c10_i234 < 3; c10_i234++) {
    c10_W_b[c10_i234] = c10_dv17[c10_i234];
  }

  for (c10_i235 = 0; c10_i235 < 3; c10_i235++) {
    c10_Xcm_a[c10_i235] = c10_Si_a[c10_i235] - c10_Xcm_a[c10_i235];
  }

  for (c10_i236 = 0; c10_i236 < 3; c10_i236++) {
    c10_Xcm_b[c10_i236] = c10_Si_b[c10_i236] - c10_Xcm_b[c10_i236];
  }

  for (c10_i237 = 0; c10_i237 < 3; c10_i237++) {
    c10_b_W_a[c10_i237] = c10_W_a[c10_i237];
  }

  for (c10_i238 = 0; c10_i238 < 3; c10_i238++) {
    c10_b_Xcm_a[c10_i238] = c10_Xcm_a[c10_i238];
  }

  c10_cross(chartInstance, c10_b_W_a, c10_b_Xcm_a, c10_dv18);
  for (c10_i239 = 0; c10_i239 < 3; c10_i239++) {
    c10_Vcm_a[c10_i239] += c10_dv18[c10_i239];
  }

  for (c10_i240 = 0; c10_i240 < 3; c10_i240++) {
    c10_b_W_b[c10_i240] = c10_W_b[c10_i240];
  }

  for (c10_i241 = 0; c10_i241 < 3; c10_i241++) {
    c10_b_Xcm_b[c10_i241] = c10_Xcm_b[c10_i241];
  }

  c10_cross(chartInstance, c10_b_W_b, c10_b_Xcm_b, c10_dv18);
  for (c10_i242 = 0; c10_i242 < 3; c10_i242++) {
    c10_Vcm_b[c10_i242] += c10_dv18[c10_i242];
  }

  for (c10_i243 = 0; c10_i243 < 3; c10_i243++) {
    c10_b_Si_a[c10_i243] = c10_Si_a[c10_i243] - c10_Si_b[c10_i243];
  }

  guard2 = FALSE;
  if (c10_b_norm(chartInstance, c10_b_Si_a) < c10_sigma_dock) {
    for (c10_i244 = 0; c10_i244 < 3; c10_i244++) {
      c10_b_Vcm_a[c10_i244] = c10_Vcm_a[c10_i244] - c10_Vcm_b[c10_i244];
    }

    if (c10_b_norm(chartInstance, c10_b_Vcm_a) <= c10_dotsigma_dock) {
      *c10_docking = 1.0;
    } else {
      guard2 = TRUE;
    }
  } else {
    guard2 = TRUE;
  }

  if (guard2 == TRUE) {
    *c10_docking = 0.0;
  }

  c10_ma = c10_ma_mb_Ia_Ib[0];
  c10_mb = c10_ma_mb_Ia_Ib[1];
  c10_Ia = c10_ma_mb_Ia_Ib[2];
  c10_Ib = c10_ma_mb_Ia_Ib[3];
  for (c10_i245 = 0; c10_i245 < 2; c10_i245++) {
    c10_Si_a[c10_i245] = c10_QA_c[c10_i245];
  }

  c10_Si_a[2] = 0.0;
  for (c10_i246 = 0; c10_i246 < 2; c10_i246++) {
    c10_Si_b[c10_i246] = c10_QB_c[c10_i246];
  }

  c10_Si_b[2] = 0.0;
  for (c10_i247 = 0; c10_i247 < 2; c10_i247++) {
    c10_N_cb[c10_i247] = c10_n_c[c10_i247];
  }

  c10_N_cb[2] = 0.0;
  c10_c_x_a[0] = c10_x_a;
  c10_c_x_a[1] = c10_y_a;
  c10_c_x_a[2] = 0.0;
  for (c10_i248 = 0; c10_i248 < 3; c10_i248++) {
    c10_Xcm_a[c10_i248] = c10_c_x_a[c10_i248];
  }

  c10_c_vx_a[0] = c10_vx_a;
  c10_c_vx_a[1] = c10_vy_a;
  c10_c_vx_a[2] = 0.0;
  for (c10_i249 = 0; c10_i249 < 3; c10_i249++) {
    c10_Vcm_a[c10_i249] = c10_c_vx_a[c10_i249];
  }

  c10_dv19[0] = 0.0;
  c10_dv19[1] = 0.0;
  c10_dv19[2] = c10_w_a;
  for (c10_i250 = 0; c10_i250 < 3; c10_i250++) {
    c10_W_a[c10_i250] = c10_dv19[c10_i250];
  }

  c10_c_x_b[0] = c10_x_b;
  c10_c_x_b[1] = c10_y_b;
  c10_c_x_b[2] = 0.0;
  for (c10_i251 = 0; c10_i251 < 3; c10_i251++) {
    c10_Xcm_b[c10_i251] = c10_c_x_b[c10_i251];
  }

  c10_c_vx_b[0] = c10_vx_b;
  c10_c_vx_b[1] = c10_vy_b;
  c10_c_vx_b[2] = 0.0;
  for (c10_i252 = 0; c10_i252 < 3; c10_i252++) {
    c10_Vcm_b[c10_i252] = c10_c_vx_b[c10_i252];
  }

  c10_dv20[0] = 0.0;
  c10_dv20[1] = 0.0;
  c10_dv20[2] = c10_w_b;
  for (c10_i253 = 0; c10_i253 < 3; c10_i253++) {
    c10_W_b[c10_i253] = c10_dv20[c10_i253];
  }

  for (c10_i254 = 0; c10_i254 < 3; c10_i254++) {
    c10_Xcm_a[c10_i254] = c10_Si_a[c10_i254] - c10_Xcm_a[c10_i254];
  }

  for (c10_i255 = 0; c10_i255 < 3; c10_i255++) {
    c10_Xcm_b[c10_i255] = c10_Si_b[c10_i255] - c10_Xcm_b[c10_i255];
  }

  for (c10_i256 = 0; c10_i256 < 3; c10_i256++) {
    c10_c_W_a[c10_i256] = c10_W_a[c10_i256];
  }

  for (c10_i257 = 0; c10_i257 < 3; c10_i257++) {
    c10_c_Xcm_a[c10_i257] = c10_Xcm_a[c10_i257];
  }

  c10_cross(chartInstance, c10_c_W_a, c10_c_Xcm_a, c10_Va_c);
  for (c10_i258 = 0; c10_i258 < 3; c10_i258++) {
    c10_Va_c[c10_i258] += c10_Vcm_a[c10_i258];
  }

  for (c10_i259 = 0; c10_i259 < 3; c10_i259++) {
    c10_c_W_b[c10_i259] = c10_W_b[c10_i259];
  }

  for (c10_i260 = 0; c10_i260 < 3; c10_i260++) {
    c10_c_Xcm_b[c10_i260] = c10_Xcm_b[c10_i260];
  }

  c10_cross(chartInstance, c10_c_W_b, c10_c_Xcm_b, c10_Si_a);
  for (c10_i261 = 0; c10_i261 < 3; c10_i261++) {
    c10_Si_a[c10_i261] += c10_Vcm_b[c10_i261];
  }

  for (c10_i262 = 0; c10_i262 < 3; c10_i262++) {
    c10_Va_c[c10_i262] -= c10_Si_a[c10_i262];
  }

  for (c10_i263 = 0; c10_i263 < 3; c10_i263++) {
    c10_j[c10_i263] = 0.0;
  }

  for (c10_i264 = 0; c10_i264 < 3; c10_i264++) {
    c10_Vcm_an[c10_i264] = 0.0;
  }

  for (c10_i265 = 0; c10_i265 < 3; c10_i265++) {
    c10_W_an[c10_i265] = 0.0;
  }

  for (c10_i266 = 0; c10_i266 < 3; c10_i266++) {
    c10_Vcm_bn[c10_i266] = 0.0;
  }

  for (c10_i267 = 0; c10_i267 < 3; c10_i267++) {
    c10_W_bn[c10_i267] = 0.0;
  }

  guard1 = FALSE;
  if (c10_contact == 1.0) {
    for (c10_i268 = 0; c10_i268 < 3; c10_i268++) {
      c10_b_Va_c[c10_i268] = c10_Va_c[c10_i268];
    }

    for (c10_i269 = 0; c10_i269 < 3; c10_i269++) {
      c10_b_N_cb[c10_i269] = c10_N_cb[c10_i269];
    }

    if (c10_b_dot(chartInstance, c10_b_Va_c, c10_b_N_cb) <= 0.0) {
      c10_g_B = c10_ma;
      c10_o_y = c10_g_B;
      c10_p_y = c10_o_y;
      c10_q_y = 1.0 / c10_p_y;
      c10_h_B = c10_mb;
      c10_r_y = c10_h_B;
      c10_s_y = c10_r_y;
      c10_t_y = 1.0 / c10_s_y;
      c10_e_A = c10_Ia;
      for (c10_i270 = 0; c10_i270 < 3; c10_i270++) {
        c10_d_Xcm_a[c10_i270] = c10_Xcm_a[c10_i270];
      }

      for (c10_i271 = 0; c10_i271 < 3; c10_i271++) {
        c10_c_N_cb[c10_i271] = c10_N_cb[c10_i271];
      }

      c10_cross(chartInstance, c10_d_Xcm_a, c10_c_N_cb, c10_dv18);
      for (c10_i272 = 0; c10_i272 < 3; c10_i272++) {
        c10_dv21[c10_i272] = c10_dv18[c10_i272];
      }

      for (c10_i273 = 0; c10_i273 < 3; c10_i273++) {
        c10_e_Xcm_a[c10_i273] = c10_Xcm_a[c10_i273];
      }

      c10_cross(chartInstance, c10_dv21, c10_e_Xcm_a, c10_Si_b);
      c10_u_y = c10_e_A;
      c10_v_y = c10_u_y;
      for (c10_i274 = 0; c10_i274 < 3; c10_i274++) {
        c10_Si_b[c10_i274] /= c10_v_y;
      }

      c10_f_A = c10_Ib;
      for (c10_i275 = 0; c10_i275 < 3; c10_i275++) {
        c10_d_Xcm_b[c10_i275] = c10_Xcm_b[c10_i275];
      }

      for (c10_i276 = 0; c10_i276 < 3; c10_i276++) {
        c10_d_N_cb[c10_i276] = c10_N_cb[c10_i276];
      }

      c10_cross(chartInstance, c10_d_Xcm_b, c10_d_N_cb, c10_dv18);
      for (c10_i277 = 0; c10_i277 < 3; c10_i277++) {
        c10_dv22[c10_i277] = c10_dv18[c10_i277];
      }

      for (c10_i278 = 0; c10_i278 < 3; c10_i278++) {
        c10_e_Xcm_b[c10_i278] = c10_Xcm_b[c10_i278];
      }

      c10_cross(chartInstance, c10_dv22, c10_e_Xcm_b, c10_Si_a);
      c10_w_y = c10_f_A;
      c10_x_y = c10_w_y;
      for (c10_i279 = 0; c10_i279 < 3; c10_i279++) {
        c10_Si_a[c10_i279] /= c10_x_y;
      }

      for (c10_i280 = 0; c10_i280 < 3; c10_i280++) {
        c10_b_Si_b[c10_i280] = c10_Si_b[c10_i280] + c10_Si_a[c10_i280];
      }

      for (c10_i281 = 0; c10_i281 < 3; c10_i281++) {
        c10_e_N_cb[c10_i281] = c10_N_cb[c10_i281];
      }

      c10_kn = (c10_q_y + c10_t_y) + c10_b_dot(chartInstance, c10_b_Si_b,
        c10_e_N_cb);
      for (c10_i282 = 0; c10_i282 < 3; c10_i282++) {
        c10_c_Va_c[c10_i282] = c10_Va_c[c10_i282];
      }

      for (c10_i283 = 0; c10_i283 < 3; c10_i283++) {
        c10_f_N_cb[c10_i283] = c10_N_cb[c10_i283];
      }

      c10_n_a = -c10_b_dot(chartInstance, c10_c_Va_c, c10_f_N_cb);
      c10_o_b = 1.0 + c10_epsilon;
      c10_y_y = c10_n_a * c10_o_b;
      c10_g_A = c10_y_y;
      c10_i_B = c10_kn;
      c10_k_x = c10_g_A;
      c10_ab_y = c10_i_B;
      c10_l_x = c10_k_x;
      c10_bb_y = c10_ab_y;
      c10_jn = c10_l_x / c10_bb_y;
      c10_o_a = c10_jn;
      for (c10_i284 = 0; c10_i284 < 3; c10_i284++) {
        c10_j[c10_i284] = c10_o_a * c10_N_cb[c10_i284];
      }

      c10_j_B = c10_ma;
      c10_cb_y = c10_j_B;
      c10_db_y = c10_cb_y;
      for (c10_i285 = 0; c10_i285 < 3; c10_i285++) {
        c10_Vcm_an[c10_i285] = c10_j[c10_i285] / c10_db_y;
      }

      for (c10_i286 = 0; c10_i286 < 3; c10_i286++) {
        c10_Vcm_an[c10_i286] += c10_Vcm_a[c10_i286];
      }

      c10_h_A = c10_Ia;
      for (c10_i287 = 0; c10_i287 < 3; c10_i287++) {
        c10_f_Xcm_a[c10_i287] = c10_Xcm_a[c10_i287];
      }

      for (c10_i288 = 0; c10_i288 < 3; c10_i288++) {
        c10_b_j[c10_i288] = c10_j[c10_i288];
      }

      c10_cross(chartInstance, c10_f_Xcm_a, c10_b_j, c10_W_an);
      c10_eb_y = c10_h_A;
      c10_fb_y = c10_eb_y;
      for (c10_i289 = 0; c10_i289 < 3; c10_i289++) {
        c10_W_an[c10_i289] /= c10_fb_y;
      }

      for (c10_i290 = 0; c10_i290 < 3; c10_i290++) {
        c10_W_an[c10_i290] += c10_W_a[c10_i290];
      }

      c10_k_B = c10_mb;
      c10_gb_y = c10_k_B;
      c10_hb_y = c10_gb_y;
      for (c10_i291 = 0; c10_i291 < 3; c10_i291++) {
        c10_Vcm_bn[c10_i291] = c10_j[c10_i291] / c10_hb_y;
      }

      for (c10_i292 = 0; c10_i292 < 3; c10_i292++) {
        c10_Vcm_bn[c10_i292] = c10_Vcm_b[c10_i292] - c10_Vcm_bn[c10_i292];
      }

      c10_i_A = c10_Ib;
      for (c10_i293 = 0; c10_i293 < 3; c10_i293++) {
        c10_f_Xcm_b[c10_i293] = c10_Xcm_b[c10_i293];
      }

      for (c10_i294 = 0; c10_i294 < 3; c10_i294++) {
        c10_c_j[c10_i294] = c10_j[c10_i294];
      }

      c10_cross(chartInstance, c10_f_Xcm_b, c10_c_j, c10_W_bn);
      c10_ib_y = c10_i_A;
      c10_jb_y = c10_ib_y;
      for (c10_i295 = 0; c10_i295 < 3; c10_i295++) {
        c10_W_bn[c10_i295] /= c10_jb_y;
      }

      for (c10_i296 = 0; c10_i296 < 3; c10_i296++) {
        c10_W_bn[c10_i296] = c10_W_b[c10_i296] - c10_W_bn[c10_i296];
      }

      *c10_collision = 1.0;
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    *c10_collision = 0.0;
  }
}

static void c10_eml_scalar_eg(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance)
{
}

static real_T c10_dot(SFc10_ManipulatorME4901InstanceStruct *chartInstance,
                      real_T c10_a[2], real_T c10_b[2])
{
  real_T c10_c;
  int32_T c10_k;
  int32_T c10_b_k;
  c10_b_eml_scalar_eg(chartInstance);
  c10_b_eml_scalar_eg(chartInstance);
  c10_c = 0.0;
  for (c10_k = 1; c10_k < 3; c10_k++) {
    c10_b_k = c10_k;
    c10_c += c10_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c10_b_k), 1, 2, 1, 0) - 1] * c10_b[_SFD_EML_ARRAY_BOUNDS_CHECK
      ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c10_b_k), 1, 2, 1, 0) - 1];
  }

  return c10_c;
}

static void c10_b_eml_scalar_eg(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance)
{
}

static real_T c10_norm(SFc10_ManipulatorME4901InstanceStruct *chartInstance,
  real_T c10_x[2])
{
  real_T c10_y;
  real_T c10_scale;
  int32_T c10_k;
  int32_T c10_b_k;
  real_T c10_b_x;
  real_T c10_c_x;
  real_T c10_absxk;
  real_T c10_t;
  c10_y = 0.0;
  c10_realmin(chartInstance);
  c10_scale = 2.2250738585072014E-308;
  for (c10_k = 1; c10_k < 3; c10_k++) {
    c10_b_k = c10_k;
    c10_b_x = c10_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c10_b_k), 1, 2, 1, 0) - 1];
    c10_c_x = c10_b_x;
    c10_absxk = muDoubleScalarAbs(c10_c_x);
    if (c10_absxk > c10_scale) {
      c10_t = c10_scale / c10_absxk;
      c10_y = 1.0 + c10_y * c10_t * c10_t;
      c10_scale = c10_absxk;
    } else {
      c10_t = c10_absxk / c10_scale;
      c10_y += c10_t * c10_t;
    }
  }

  return c10_scale * muDoubleScalarSqrt(c10_y);
}

static void c10_realmin(SFc10_ManipulatorME4901InstanceStruct *chartInstance)
{
}

static void c10_check_forloop_overflow_error
  (SFc10_ManipulatorME4901InstanceStruct *chartInstance, boolean_T c10_overflow)
{
  int32_T c10_i297;
  static char_T c10_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c10_u[34];
  const mxArray *c10_y = NULL;
  int32_T c10_i298;
  static char_T c10_cv1[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't', 'e',
    'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  char_T c10_b_u[23];
  const mxArray *c10_b_y = NULL;
  if (!c10_overflow) {
  } else {
    for (c10_i297 = 0; c10_i297 < 34; c10_i297++) {
      c10_u[c10_i297] = c10_cv0[c10_i297];
    }

    c10_y = NULL;
    sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c10_i298 = 0; c10_i298 < 23; c10_i298++) {
      c10_b_u[c10_i298] = c10_cv1[c10_i298];
    }

    c10_b_y = NULL;
    sf_mex_assign(&c10_b_y, sf_mex_create("y", c10_b_u, 10, 0U, 1U, 0U, 2, 1, 23),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c10_y, 14, c10_b_y));
  }
}

static void c10_b_check_forloop_overflow_error
  (SFc10_ManipulatorME4901InstanceStruct *chartInstance, boolean_T c10_overflow)
{
  int32_T c10_i299;
  static char_T c10_cv2[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c10_u[34];
  const mxArray *c10_y = NULL;
  int32_T c10_i300;
  static char_T c10_cv3[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't', 'e',
    'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  char_T c10_b_u[23];
  const mxArray *c10_b_y = NULL;
  if (!c10_overflow) {
  } else {
    for (c10_i299 = 0; c10_i299 < 34; c10_i299++) {
      c10_u[c10_i299] = c10_cv2[c10_i299];
    }

    c10_y = NULL;
    sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c10_i300 = 0; c10_i300 < 23; c10_i300++) {
      c10_b_u[c10_i300] = c10_cv3[c10_i300];
    }

    c10_b_y = NULL;
    sf_mex_assign(&c10_b_y, sf_mex_create("y", c10_b_u, 10, 0U, 1U, 0U, 2, 1, 23),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c10_y, 14, c10_b_y));
  }
}

static void c10_cross(SFc10_ManipulatorME4901InstanceStruct *chartInstance,
                      real_T c10_a[3], real_T c10_b[3], real_T c10_c[3])
{
  real_T c10_b_a;
  real_T c10_b_b;
  real_T c10_y;
  real_T c10_c_a;
  real_T c10_c_b;
  real_T c10_b_y;
  real_T c10_c1;
  real_T c10_d_a;
  real_T c10_d_b;
  real_T c10_c_y;
  real_T c10_e_a;
  real_T c10_e_b;
  real_T c10_d_y;
  real_T c10_c2;
  real_T c10_f_a;
  real_T c10_f_b;
  real_T c10_e_y;
  real_T c10_g_a;
  real_T c10_g_b;
  real_T c10_f_y;
  real_T c10_c3;
  c10_b_a = c10_a[1];
  c10_b_b = c10_b[2];
  c10_y = c10_b_a * c10_b_b;
  c10_c_a = c10_a[2];
  c10_c_b = c10_b[1];
  c10_b_y = c10_c_a * c10_c_b;
  c10_c1 = c10_y - c10_b_y;
  c10_d_a = c10_a[2];
  c10_d_b = c10_b[0];
  c10_c_y = c10_d_a * c10_d_b;
  c10_e_a = c10_a[0];
  c10_e_b = c10_b[2];
  c10_d_y = c10_e_a * c10_e_b;
  c10_c2 = c10_c_y - c10_d_y;
  c10_f_a = c10_a[0];
  c10_f_b = c10_b[1];
  c10_e_y = c10_f_a * c10_f_b;
  c10_g_a = c10_a[1];
  c10_g_b = c10_b[0];
  c10_f_y = c10_g_a * c10_g_b;
  c10_c3 = c10_e_y - c10_f_y;
  c10_c[0] = c10_c1;
  c10_c[1] = c10_c2;
  c10_c[2] = c10_c3;
}

static real_T c10_b_norm(SFc10_ManipulatorME4901InstanceStruct *chartInstance,
  real_T c10_x[3])
{
  real_T c10_y;
  real_T c10_scale;
  int32_T c10_k;
  int32_T c10_b_k;
  real_T c10_b_x;
  real_T c10_c_x;
  real_T c10_absxk;
  real_T c10_t;
  c10_y = 0.0;
  c10_realmin(chartInstance);
  c10_scale = 2.2250738585072014E-308;
  for (c10_k = 1; c10_k < 4; c10_k++) {
    c10_b_k = c10_k;
    c10_b_x = c10_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c10_b_k), 1, 3, 1, 0) - 1];
    c10_c_x = c10_b_x;
    c10_absxk = muDoubleScalarAbs(c10_c_x);
    if (c10_absxk > c10_scale) {
      c10_t = c10_scale / c10_absxk;
      c10_y = 1.0 + c10_y * c10_t * c10_t;
      c10_scale = c10_absxk;
    } else {
      c10_t = c10_absxk / c10_scale;
      c10_y += c10_t * c10_t;
    }
  }

  return c10_scale * muDoubleScalarSqrt(c10_y);
}

static real_T c10_b_dot(SFc10_ManipulatorME4901InstanceStruct *chartInstance,
  real_T c10_a[3], real_T c10_b[3])
{
  real_T c10_c;
  int32_T c10_k;
  int32_T c10_b_k;
  c10_c_eml_scalar_eg(chartInstance);
  c10_c_eml_scalar_eg(chartInstance);
  c10_c = 0.0;
  for (c10_k = 1; c10_k < 4; c10_k++) {
    c10_b_k = c10_k;
    c10_c += c10_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c10_b_k), 1, 3, 1, 0) - 1] * c10_b[_SFD_EML_ARRAY_BOUNDS_CHECK
      ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c10_b_k), 1, 3, 1, 0) - 1];
  }

  return c10_c;
}

static void c10_c_eml_scalar_eg(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance)
{
}

static const mxArray *c10_l_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc10_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(int32_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static int32_T c10_k_emlrt_marshallIn(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  int32_T c10_y;
  int32_T c10_i301;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_i301, 1, 6, 0U, 0, 0U, 0);
  c10_y = c10_i301;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_sfEvent;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  int32_T c10_y;
  SFc10_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc10_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c10_b_sfEvent = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_sfEvent),
    &c10_thisId);
  sf_mex_destroy(&c10_b_sfEvent);
  *(int32_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static uint8_T c10_l_emlrt_marshallIn(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c10_b_is_active_c10_ManipulatorME4901, const
  char_T *c10_identifier)
{
  uint8_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_m_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_b_is_active_c10_ManipulatorME4901), &c10_thisId);
  sf_mex_destroy(&c10_b_is_active_c10_ManipulatorME4901);
  return c10_y;
}

static uint8_T c10_m_emlrt_marshallIn(SFc10_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  uint8_T c10_y;
  uint8_T c10_u0;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_u0, 1, 3, 0U, 0, 0U, 0);
  c10_y = c10_u0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void init_dsm_address_info(SFc10_ManipulatorME4901InstanceStruct
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

void sf_c10_ManipulatorME4901_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2801986435U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1023194807U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3083137268U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3528811354U);
}

mxArray *sf_c10_ManipulatorME4901_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Zys44DVuqYjNLhmthvm7NC");
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

mxArray *sf_c10_ManipulatorME4901_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c10_ManipulatorME4901(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[13],T\"A\",},{M[1],M[14],T\"B\",},{M[1],M[9],T\"QA_c\",},{M[1],M[10],T\"QB_c\",},{M[1],M[29],T\"Vcm_an\",},{M[1],M[31],T\"Vcm_bn\",},{M[1],M[30],T\"W_an\",},{M[1],M[32],T\"W_bn\",},{M[1],M[28],T\"collision\",},{M[1],M[23],T\"dock_sensA_c\",}}",
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[36],T\"dock_sensB_c\",},{M[1],M[26],T\"docking\",},{M[1],M[33],T\"j\",},{M[1],M[18],T\"n_c\",},{M[8],M[0],T\"is_active_c10_ManipulatorME4901\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 15, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_ManipulatorME4901_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc10_ManipulatorME4901InstanceStruct *chartInstance;
    chartInstance = (SFc10_ManipulatorME4901InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ManipulatorME4901MachineNumber_,
           10,
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
          (MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_e_sf_marshallOut,(MexInFcnForType)
            c10_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_e_sf_marshallOut,(MexInFcnForType)
            c10_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_e_sf_marshallOut,(MexInFcnForType)
            c10_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_e_sf_marshallOut,(MexInFcnForType)
            c10_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_e_sf_marshallOut,(MexInFcnForType)
            c10_e_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_k_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_k_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 8;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_d_sf_marshallOut,(MexInFcnForType)
            c10_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_c_sf_marshallOut,(MexInFcnForType)
            c10_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_j_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 9;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_i_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 7;
          _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_h_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_g_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)
          c10_b_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)
          c10_b_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)
            c10_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)
            c10_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)
            c10_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)
            c10_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)
            c10_sf_marshallIn);
        }

        {
          real_T *c10_epsilon;
          real_T *c10_sigma_dock;
          real_T *c10_dotsigma_dock;
          real_T *c10_sigma;
          real_T *c10_docking;
          real_T *c10_collision;
          real_T (*c10_dock_sensA_c)[2];
          real_T (*c10_dock_sensB_c)[2];
          real_T (*c10_n_c)[2];
          real_T (*c10_QA_c)[2];
          real_T (*c10_QB_c)[2];
          real_T (*c10_Rbi_A1)[4];
          real_T (*c10_Rbi_B1)[4];
          real_T (*c10_A)[16];
          real_T (*c10_B)[10];
          real_T (*c10_Xcm_A)[9];
          real_T (*c10_Xcm_B)[9];
          real_T (*c10_mesh_A)[21];
          real_T (*c10_mesh_B)[12];
          real_T (*c10_dock_sensA)[3];
          real_T (*c10_dock_sensB)[3];
          real_T (*c10_ma_mb_Ia_Ib)[4];
          real_T (*c10_Vcm_an)[3];
          real_T (*c10_Vcm_bn)[3];
          real_T (*c10_W_an)[3];
          real_T (*c10_W_bn)[3];
          real_T (*c10_j)[3];
          c10_j = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 14);
          c10_W_bn = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 13);
          c10_W_an = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 12);
          c10_Vcm_bn = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 11);
          c10_Vcm_an = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 10);
          c10_collision = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
          c10_ma_mb_Ia_Ib = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S,
            12);
          c10_docking = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
          c10_sigma = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
          c10_dock_sensB = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S,
            10);
          c10_dock_sensA = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S,
            9);
          c10_mesh_B = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 8);
          c10_mesh_A = (real_T (*)[21])ssGetInputPortSignal(chartInstance->S, 7);
          c10_Xcm_B = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 6);
          c10_Xcm_A = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 5);
          c10_B = (real_T (*)[10])ssGetOutputPortSignal(chartInstance->S, 7);
          c10_A = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 6);
          c10_Rbi_B1 = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 4);
          c10_Rbi_A1 = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 3);
          c10_dotsigma_dock = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c10_sigma_dock = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c10_QB_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 5);
          c10_QA_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 4);
          c10_n_c = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 3);
          c10_dock_sensB_c = (real_T (*)[2])ssGetOutputPortSignal
            (chartInstance->S, 2);
          c10_dock_sensA_c = (real_T (*)[2])ssGetOutputPortSignal
            (chartInstance->S, 1);
          c10_epsilon = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c10_epsilon);
          _SFD_SET_DATA_VALUE_PTR(1U, *c10_dock_sensA_c);
          _SFD_SET_DATA_VALUE_PTR(2U, *c10_dock_sensB_c);
          _SFD_SET_DATA_VALUE_PTR(3U, *c10_n_c);
          _SFD_SET_DATA_VALUE_PTR(4U, *c10_QA_c);
          _SFD_SET_DATA_VALUE_PTR(5U, *c10_QB_c);
          _SFD_SET_DATA_VALUE_PTR(6U, c10_sigma_dock);
          _SFD_SET_DATA_VALUE_PTR(7U, c10_dotsigma_dock);
          _SFD_SET_DATA_VALUE_PTR(8U, *c10_Rbi_A1);
          _SFD_SET_DATA_VALUE_PTR(9U, *c10_Rbi_B1);
          _SFD_SET_DATA_VALUE_PTR(10U, *c10_A);
          _SFD_SET_DATA_VALUE_PTR(11U, *c10_B);
          _SFD_SET_DATA_VALUE_PTR(12U, *c10_Xcm_A);
          _SFD_SET_DATA_VALUE_PTR(13U, *c10_Xcm_B);
          _SFD_SET_DATA_VALUE_PTR(14U, *c10_mesh_A);
          _SFD_SET_DATA_VALUE_PTR(15U, *c10_mesh_B);
          _SFD_SET_DATA_VALUE_PTR(16U, *c10_dock_sensA);
          _SFD_SET_DATA_VALUE_PTR(17U, *c10_dock_sensB);
          _SFD_SET_DATA_VALUE_PTR(18U, c10_sigma);
          _SFD_SET_DATA_VALUE_PTR(19U, c10_docking);
          _SFD_SET_DATA_VALUE_PTR(20U, *c10_ma_mb_Ia_Ib);
          _SFD_SET_DATA_VALUE_PTR(21U, c10_collision);
          _SFD_SET_DATA_VALUE_PTR(22U, *c10_Vcm_an);
          _SFD_SET_DATA_VALUE_PTR(23U, *c10_Vcm_bn);
          _SFD_SET_DATA_VALUE_PTR(24U, *c10_W_an);
          _SFD_SET_DATA_VALUE_PTR(25U, *c10_W_bn);
          _SFD_SET_DATA_VALUE_PTR(26U, *c10_j);
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
  return "EIaBGLVu7V9utDa9XO87vE";
}

static void sf_opaque_initialize_c10_ManipulatorME4901(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc10_ManipulatorME4901InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c10_ManipulatorME4901((SFc10_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
  initialize_c10_ManipulatorME4901((SFc10_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c10_ManipulatorME4901(void *chartInstanceVar)
{
  enable_c10_ManipulatorME4901((SFc10_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c10_ManipulatorME4901(void *chartInstanceVar)
{
  disable_c10_ManipulatorME4901((SFc10_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c10_ManipulatorME4901(void *chartInstanceVar)
{
  sf_c10_ManipulatorME4901((SFc10_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c10_ManipulatorME4901(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c10_ManipulatorME4901
    ((SFc10_ManipulatorME4901InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c10_ManipulatorME4901();/* state var info */
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

extern void sf_internal_set_sim_state_c10_ManipulatorME4901(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c10_ManipulatorME4901();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c10_ManipulatorME4901((SFc10_ManipulatorME4901InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c10_ManipulatorME4901(SimStruct* S)
{
  return sf_internal_get_sim_state_c10_ManipulatorME4901(S);
}

static void sf_opaque_set_sim_state_c10_ManipulatorME4901(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c10_ManipulatorME4901(S, st);
}

static void sf_opaque_terminate_c10_ManipulatorME4901(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc10_ManipulatorME4901InstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ManipulatorME4901_optimization_info();
    }

    finalize_c10_ManipulatorME4901((SFc10_ManipulatorME4901InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc10_ManipulatorME4901((SFc10_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_ManipulatorME4901(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c10_ManipulatorME4901
      ((SFc10_ManipulatorME4901InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c10_ManipulatorME4901(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ManipulatorME4901_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      10);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,10,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,10,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,10);
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
        infoStruct,10,13);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,10,14);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,10);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3136076572U));
  ssSetChecksum1(S,(2033250070U));
  ssSetChecksum2(S,(476202300U));
  ssSetChecksum3(S,(1586261472U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c10_ManipulatorME4901(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c10_ManipulatorME4901(SimStruct *S)
{
  SFc10_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc10_ManipulatorME4901InstanceStruct *)utMalloc(sizeof
    (SFc10_ManipulatorME4901InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc10_ManipulatorME4901InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c10_ManipulatorME4901;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c10_ManipulatorME4901;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c10_ManipulatorME4901;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c10_ManipulatorME4901;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c10_ManipulatorME4901;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c10_ManipulatorME4901;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c10_ManipulatorME4901;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_ManipulatorME4901;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c10_ManipulatorME4901;
  chartInstance->chartInfo.mdlStart = mdlStart_c10_ManipulatorME4901;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c10_ManipulatorME4901;
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

void c10_ManipulatorME4901_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_ManipulatorME4901(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_ManipulatorME4901(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_ManipulatorME4901(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_ManipulatorME4901_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
