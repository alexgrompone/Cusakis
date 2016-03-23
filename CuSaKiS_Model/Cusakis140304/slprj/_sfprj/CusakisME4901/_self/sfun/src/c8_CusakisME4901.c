/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CusakisME4901_sfun.h"
#include "c8_CusakisME4901.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CusakisME4901_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c8_debug_family_names[22] = { "q", "Ja", "DDD", "DW", "Jinv",
  "qa", "EEv", "Jstar", "A", "lambmax", "Sigma", "lamb2", "nargin", "nargout",
  "Ve", "qqd", "l", "a", "EE", "qd_req", "qd_reqW", "W" };

/* Function Declarations */
static void initialize_c8_CusakisME4901(SFc8_CusakisME4901InstanceStruct
  *chartInstance);
static void initialize_params_c8_CusakisME4901(SFc8_CusakisME4901InstanceStruct *
  chartInstance);
static void enable_c8_CusakisME4901(SFc8_CusakisME4901InstanceStruct
  *chartInstance);
static void disable_c8_CusakisME4901(SFc8_CusakisME4901InstanceStruct
  *chartInstance);
static void c8_update_debugger_state_c8_CusakisME4901
  (SFc8_CusakisME4901InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c8_CusakisME4901
  (SFc8_CusakisME4901InstanceStruct *chartInstance);
static void set_sim_state_c8_CusakisME4901(SFc8_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c8_st);
static void finalize_c8_CusakisME4901(SFc8_CusakisME4901InstanceStruct
  *chartInstance);
static void sf_c8_CusakisME4901(SFc8_CusakisME4901InstanceStruct *chartInstance);
static void c8_chartstep_c8_CusakisME4901(SFc8_CusakisME4901InstanceStruct
  *chartInstance);
static void initSimStructsc8_CusakisME4901(SFc8_CusakisME4901InstanceStruct
  *chartInstance);
static void registerMessagesc8_CusakisME4901(SFc8_CusakisME4901InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber);
static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData);
static real_T c8_emlrt_marshallIn(SFc8_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c8_W, const char_T *c8_identifier);
static real_T c8_b_emlrt_marshallIn(SFc8_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_c_emlrt_marshallIn(SFc8_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c8_qd_reqW, const char_T *c8_identifier, real_T
  c8_y[3]);
static void c8_d_emlrt_marshallIn(SFc8_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[3]);
static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_e_emlrt_marshallIn(SFc8_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[2]);
static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_e_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_f_emlrt_marshallIn(SFc8_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[6]);
static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_f_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_g_emlrt_marshallIn(SFc8_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[6]);
static void c8_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_g_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_h_emlrt_marshallIn(SFc8_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[3]);
static void c8_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[247]);
static void c8_b_info_helper(c8_ResolvedFunctionInfo c8_info[247]);
static void c8_c_info_helper(c8_ResolvedFunctionInfo c8_info[247]);
static void c8_d_info_helper(c8_ResolvedFunctionInfo c8_info[247]);
static void c8_eml_scalar_eg(SFc8_CusakisME4901InstanceStruct *chartInstance);
static void c8_b_eml_scalar_eg(SFc8_CusakisME4901InstanceStruct *chartInstance);
static real_T c8_det(SFc8_CusakisME4901InstanceStruct *chartInstance, real_T
                     c8_x[4]);
static void c8_realmin(SFc8_CusakisME4901InstanceStruct *chartInstance);
static void c8_eps(SFc8_CusakisME4901InstanceStruct *chartInstance);
static void c8_eml_matlab_zgetrf(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_A[4], real_T c8_b_A[4], int32_T c8_ipiv[2], int32_T *c8_info);
static real_T c8_abs(SFc8_CusakisME4901InstanceStruct *chartInstance, real_T
                     c8_x);
static void c8_below_threshold(SFc8_CusakisME4901InstanceStruct *chartInstance);
static real_T c8_eml_div(SFc8_CusakisME4901InstanceStruct *chartInstance, real_T
  c8_x, real_T c8_y);
static void c8_eml_xger(SFc8_CusakisME4901InstanceStruct *chartInstance, real_T
  c8_A[4], real_T c8_b_A[4]);
static void c8_check_forloop_overflow_error(SFc8_CusakisME4901InstanceStruct
  *chartInstance, boolean_T c8_overflow);
static real_T c8_sqrt(SFc8_CusakisME4901InstanceStruct *chartInstance, real_T
                      c8_x);
static void c8_eml_error(SFc8_CusakisME4901InstanceStruct *chartInstance);
static real_T c8_mpower(SFc8_CusakisME4901InstanceStruct *chartInstance, real_T
  c8_b_a);
static void c8_c_eml_scalar_eg(SFc8_CusakisME4901InstanceStruct *chartInstance);
static void c8_b_eml_error(SFc8_CusakisME4901InstanceStruct *chartInstance);
static void c8_pinv(SFc8_CusakisME4901InstanceStruct *chartInstance, real_T
                    c8_A[6], real_T c8_X[6]);
static void c8_d_eml_scalar_eg(SFc8_CusakisME4901InstanceStruct *chartInstance);
static void c8_c_eml_error(SFc8_CusakisME4901InstanceStruct *chartInstance);
static void c8_eml_xgesvd(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_A[6], real_T c8_U[6], real_T c8_S[2], real_T c8_V[4]);
static real_T c8_eml_xnrm2(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_x[6], int32_T c8_ix0);
static void c8_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_b_a, real_T c8_x[6], int32_T c8_ix0, real_T c8_b_x[6]);
static real_T c8_eml_xdotc(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_x[6], int32_T c8_ix0, real_T c8_y[6], int32_T c8_iy0);
static void c8_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_b_a, int32_T c8_ix0, real_T c8_y[6], int32_T c8_iy0,
  real_T c8_b_y[6]);
static real_T c8_b_eml_xnrm2(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_x[2], int32_T c8_ix0);
static void c8_b_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_b_a, real_T c8_x[2], int32_T c8_ix0, real_T c8_b_x[2]);
static void c8_b_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_b_a, real_T c8_x[6], int32_T c8_ix0, real_T c8_y[3],
  int32_T c8_iy0, real_T c8_b_y[3]);
static void c8_c_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_b_a, real_T c8_x[3], int32_T c8_ix0, real_T c8_y[6],
  int32_T c8_iy0, real_T c8_b_y[6]);
static real_T c8_b_eml_xdotc(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_x[4], int32_T c8_ix0, real_T c8_y[4], int32_T c8_iy0);
static void c8_e_eml_scalar_eg(SFc8_CusakisME4901InstanceStruct *chartInstance);
static void c8_d_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_b_a, int32_T c8_ix0, real_T c8_y[4], int32_T c8_iy0,
  real_T c8_b_y[4]);
static void c8_c_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[6], int32_T c8_ix0, real_T c8_b_x[6]);
static void c8_d_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[4], int32_T c8_ix0, real_T c8_b_x[4]);
static void c8_b_below_threshold(SFc8_CusakisME4901InstanceStruct *chartInstance);
static void c8_d_eml_error(SFc8_CusakisME4901InstanceStruct *chartInstance);
static void c8_eml_xrotg(SFc8_CusakisME4901InstanceStruct *chartInstance, real_T
  c8_b_a, real_T c8_b, real_T *c8_c_a, real_T *c8_b_b, real_T *c8_c, real_T
  *c8_s);
static void c8_eml_xrot(SFc8_CusakisME4901InstanceStruct *chartInstance, real_T
  c8_x[4], int32_T c8_ix0, int32_T c8_iy0, real_T c8_c, real_T c8_s, real_T
  c8_b_x[4]);
static void c8_b_eml_xrot(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_x[6], int32_T c8_ix0, int32_T c8_iy0, real_T c8_c, real_T c8_s,
  real_T c8_b_x[6]);
static void c8_eml_xswap(SFc8_CusakisME4901InstanceStruct *chartInstance, real_T
  c8_x[4], int32_T c8_ix0, int32_T c8_iy0, real_T c8_b_x[4]);
static void c8_b_eml_xswap(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_x[6], int32_T c8_ix0, int32_T c8_iy0, real_T c8_b_x[6]);
static void c8_eml_xgemm(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_k, real_T c8_A[4], real_T c8_B[6], real_T c8_C[6], real_T c8_b_C[6]);
static void c8_f_eml_scalar_eg(SFc8_CusakisME4901InstanceStruct *chartInstance);
static void c8_g_eml_scalar_eg(SFc8_CusakisME4901InstanceStruct *chartInstance);
static void c8_svd(SFc8_CusakisME4901InstanceStruct *chartInstance, real_T c8_A
                   [6], real_T c8_U[2]);
static void c8_eml_matlab_zsvdc(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_A[6], real_T c8_S[2]);
static real_T c8_c_eml_xnrm2(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_x[6]);
static void c8_e_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[6], real_T c8_b_x[6]);
static real_T c8_c_eml_xdotc(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_x[6], real_T c8_y[6], int32_T c8_iy0);
static void c8_e_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_y[6], int32_T c8_iy0, real_T c8_b_y[6]);
static real_T c8_d_eml_xnrm2(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_x[3]);
static void c8_f_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[3], real_T c8_b_x[3]);
static void c8_f_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[6], int32_T c8_ix0, real_T c8_y[2], real_T c8_b_y[2]);
static void c8_g_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[2], real_T c8_y[6], int32_T c8_iy0, real_T c8_b_y[6]);
static real_T c8_b_mpower(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a);
static void c8_b_pinv(SFc8_CusakisME4901InstanceStruct *chartInstance, real_T
                      c8_A[4], real_T c8_X[4]);
static void c8_b_eml_xgesvd(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_A[4], real_T c8_U[4], real_T c8_S[2], real_T c8_V[4]);
static real_T c8_e_eml_xnrm2(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_x[4]);
static void c8_g_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[4], real_T c8_b_x[4]);
static real_T c8_d_eml_xdotc(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_x[4], real_T c8_y[4]);
static void c8_h_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_y[4], real_T c8_b_y[4]);
static void c8_b_eml_xgemm(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_k, real_T c8_A[4], real_T c8_B[4], real_T c8_C[4], real_T c8_b_C[4]);
static void c8_h_eml_scalar_eg(SFc8_CusakisME4901InstanceStruct *chartInstance);
static const mxArray *c8_h_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static int32_T c8_i_emlrt_marshallIn(SFc8_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static uint8_T c8_j_emlrt_marshallIn(SFc8_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c8_b_is_active_c8_CusakisME4901, const char_T
  *c8_identifier);
static uint8_T c8_k_emlrt_marshallIn(SFc8_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_b_eml_matlab_zgetrf(SFc8_CusakisME4901InstanceStruct
  *chartInstance, real_T c8_A[4], int32_T c8_ipiv[2], int32_T *c8_info);
static void c8_b_eml_xger(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_A[4]);
static void c8_b_sqrt(SFc8_CusakisME4901InstanceStruct *chartInstance, real_T
                      *c8_x);
static void c8_h_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_b_a, real_T c8_x[6], int32_T c8_ix0);
static void c8_i_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_b_a, int32_T c8_ix0, real_T c8_y[6], int32_T c8_iy0);
static void c8_i_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_b_a, real_T c8_x[2], int32_T c8_ix0);
static void c8_j_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_b_a, real_T c8_x[6], int32_T c8_ix0, real_T c8_y[3],
  int32_T c8_iy0);
static void c8_k_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_b_a, real_T c8_x[3], int32_T c8_ix0, real_T c8_y[6],
  int32_T c8_iy0);
static void c8_l_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_b_a, int32_T c8_ix0, real_T c8_y[4], int32_T c8_iy0);
static void c8_j_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[6], int32_T c8_ix0);
static void c8_k_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[4], int32_T c8_ix0);
static void c8_b_eml_xrotg(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T *c8_b_a, real_T *c8_b, real_T *c8_c, real_T *c8_s);
static void c8_c_eml_xrot(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_x[4], int32_T c8_ix0, int32_T c8_iy0, real_T c8_c, real_T c8_s);
static void c8_d_eml_xrot(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_x[6], int32_T c8_ix0, int32_T c8_iy0, real_T c8_c, real_T c8_s);
static void c8_c_eml_xswap(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_x[4], int32_T c8_ix0, int32_T c8_iy0);
static void c8_d_eml_xswap(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_x[6], int32_T c8_ix0, int32_T c8_iy0);
static void c8_c_eml_xgemm(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_k, real_T c8_A[4], real_T c8_B[6], real_T c8_C[6]);
static void c8_l_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[6]);
static void c8_m_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_y[6], int32_T c8_iy0);
static void c8_m_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[3]);
static void c8_n_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[6], int32_T c8_ix0, real_T c8_y[2]);
static void c8_o_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[2], real_T c8_y[6], int32_T c8_iy0);
static void c8_n_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[4]);
static void c8_p_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_y[4]);
static void c8_d_eml_xgemm(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_k, real_T c8_A[4], real_T c8_B[4], real_T c8_C[4]);
static void init_dsm_address_info(SFc8_CusakisME4901InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c8_CusakisME4901(SFc8_CusakisME4901InstanceStruct
  *chartInstance)
{
  chartInstance->c8_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c8_is_active_c8_CusakisME4901 = 0U;
}

static void initialize_params_c8_CusakisME4901(SFc8_CusakisME4901InstanceStruct *
  chartInstance)
{
  real_T c8_d0;
  real_T c8_d1;
  sf_set_error_prefix_string(
    "Error evaluating data 'l' in the parent workspace.\n");
  sf_mex_import_named("l", sf_mex_get_sfun_param(chartInstance->S, 1, 0), &c8_d0,
                      0, 0, 0U, 0, 0U, 0);
  chartInstance->c8_l = c8_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'a' in the parent workspace.\n");
  sf_mex_import_named("a", sf_mex_get_sfun_param(chartInstance->S, 0, 0), &c8_d1,
                      0, 0, 0U, 0, 0U, 0);
  chartInstance->c8_a = c8_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c8_CusakisME4901(SFc8_CusakisME4901InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c8_CusakisME4901(SFc8_CusakisME4901InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c8_update_debugger_state_c8_CusakisME4901
  (SFc8_CusakisME4901InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c8_CusakisME4901
  (SFc8_CusakisME4901InstanceStruct *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  real_T c8_hoistedGlobal;
  real_T c8_u;
  const mxArray *c8_b_y = NULL;
  int32_T c8_i0;
  real_T c8_b_u[3];
  const mxArray *c8_c_y = NULL;
  int32_T c8_i1;
  real_T c8_c_u[3];
  const mxArray *c8_d_y = NULL;
  uint8_T c8_b_hoistedGlobal;
  uint8_T c8_d_u;
  const mxArray *c8_e_y = NULL;
  real_T *c8_W;
  real_T (*c8_qd_reqW)[3];
  real_T (*c8_qd_req)[3];
  c8_W = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_qd_reqW = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c8_qd_req = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c8_st = NULL;
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellarray(4), FALSE);
  c8_hoistedGlobal = *c8_W;
  c8_u = c8_hoistedGlobal;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 0, c8_b_y);
  for (c8_i0 = 0; c8_i0 < 3; c8_i0++) {
    c8_b_u[c8_i0] = (*c8_qd_req)[c8_i0];
  }

  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", c8_b_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c8_y, 1, c8_c_y);
  for (c8_i1 = 0; c8_i1 < 3; c8_i1++) {
    c8_c_u[c8_i1] = (*c8_qd_reqW)[c8_i1];
  }

  c8_d_y = NULL;
  sf_mex_assign(&c8_d_y, sf_mex_create("y", c8_c_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c8_y, 2, c8_d_y);
  c8_b_hoistedGlobal = chartInstance->c8_is_active_c8_CusakisME4901;
  c8_d_u = c8_b_hoistedGlobal;
  c8_e_y = NULL;
  sf_mex_assign(&c8_e_y, sf_mex_create("y", &c8_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 3, c8_e_y);
  sf_mex_assign(&c8_st, c8_y, FALSE);
  return c8_st;
}

static void set_sim_state_c8_CusakisME4901(SFc8_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c8_st)
{
  const mxArray *c8_u;
  real_T c8_dv0[3];
  int32_T c8_i2;
  real_T c8_dv1[3];
  int32_T c8_i3;
  real_T *c8_W;
  real_T (*c8_qd_req)[3];
  real_T (*c8_qd_reqW)[3];
  c8_W = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_qd_reqW = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c8_qd_req = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c8_doneDoubleBufferReInit = TRUE;
  c8_u = sf_mex_dup(c8_st);
  *c8_W = c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 0)),
    "W");
  c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 1)),
                        "qd_req", c8_dv0);
  for (c8_i2 = 0; c8_i2 < 3; c8_i2++) {
    (*c8_qd_req)[c8_i2] = c8_dv0[c8_i2];
  }

  c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 2)),
                        "qd_reqW", c8_dv1);
  for (c8_i3 = 0; c8_i3 < 3; c8_i3++) {
    (*c8_qd_reqW)[c8_i3] = c8_dv1[c8_i3];
  }

  chartInstance->c8_is_active_c8_CusakisME4901 = c8_j_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 3)),
     "is_active_c8_CusakisME4901");
  sf_mex_destroy(&c8_u);
  c8_update_debugger_state_c8_CusakisME4901(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_CusakisME4901(SFc8_CusakisME4901InstanceStruct
  *chartInstance)
{
}

static void sf_c8_CusakisME4901(SFc8_CusakisME4901InstanceStruct *chartInstance)
{
  int32_T c8_i4;
  int32_T c8_i5;
  int32_T c8_i6;
  int32_T c8_i7;
  real_T *c8_W;
  real_T *c8_EE;
  real_T (*c8_qd_reqW)[3];
  real_T (*c8_qd_req)[3];
  real_T (*c8_qqd)[9];
  real_T (*c8_Ve)[2];
  c8_EE = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c8_W = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_qd_reqW = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c8_qd_req = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c8_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c8_Ve = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  for (c8_i4 = 0; c8_i4 < 2; c8_i4++) {
    _SFD_DATA_RANGE_CHECK((*c8_Ve)[c8_i4], 0U);
  }

  for (c8_i5 = 0; c8_i5 < 9; c8_i5++) {
    _SFD_DATA_RANGE_CHECK((*c8_qqd)[c8_i5], 1U);
  }

  for (c8_i6 = 0; c8_i6 < 3; c8_i6++) {
    _SFD_DATA_RANGE_CHECK((*c8_qd_req)[c8_i6], 2U);
  }

  for (c8_i7 = 0; c8_i7 < 3; c8_i7++) {
    _SFD_DATA_RANGE_CHECK((*c8_qd_reqW)[c8_i7], 3U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c8_l, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c8_a, 5U);
  _SFD_DATA_RANGE_CHECK(*c8_W, 6U);
  _SFD_DATA_RANGE_CHECK(*c8_EE, 7U);
  chartInstance->c8_sfEvent = CALL_EVENT;
  c8_chartstep_c8_CusakisME4901(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CusakisME4901MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c8_chartstep_c8_CusakisME4901(SFc8_CusakisME4901InstanceStruct
  *chartInstance)
{
  real_T c8_hoistedGlobal;
  real_T c8_b_hoistedGlobal;
  real_T c8_c_hoistedGlobal;
  int32_T c8_i8;
  real_T c8_Ve[2];
  int32_T c8_i9;
  real_T c8_qqd[9];
  real_T c8_b_l;
  real_T c8_b_a;
  real_T c8_EE;
  uint32_T c8_debug_family_var_map[22];
  real_T c8_q[3];
  real_T c8_Ja[6];
  real_T c8_DDD;
  real_T c8_DW[3];
  real_T c8_Jinv[6];
  real_T c8_qa[3];
  real_T c8_EEv[3];
  real_T c8_Jstar[6];
  real_T c8_A[2];
  real_T c8_lambmax;
  real_T c8_Sigma;
  real_T c8_lamb2;
  real_T c8_nargin = 5.0;
  real_T c8_nargout = 3.0;
  real_T c8_qd_req[3];
  real_T c8_qd_reqW[3];
  real_T c8_W;
  real_T c8_x;
  real_T c8_b_x;
  real_T c8_c_a;
  real_T c8_b;
  real_T c8_y;
  real_T c8_c_x;
  real_T c8_d_x;
  real_T c8_d_a;
  real_T c8_b_b;
  real_T c8_b_y;
  real_T c8_e_x;
  real_T c8_f_x;
  real_T c8_e_a;
  real_T c8_c_b;
  real_T c8_c_y;
  real_T c8_g_x;
  real_T c8_h_x;
  real_T c8_f_a;
  real_T c8_d_b;
  real_T c8_d_y;
  real_T c8_i_x;
  real_T c8_j_x;
  real_T c8_g_a;
  real_T c8_e_b;
  real_T c8_e_y;
  real_T c8_k_x;
  real_T c8_l_x;
  real_T c8_h_a;
  real_T c8_f_b;
  real_T c8_f_y;
  real_T c8_m_x;
  real_T c8_n_x;
  real_T c8_i_a;
  real_T c8_g_b;
  real_T c8_g_y;
  real_T c8_o_x;
  real_T c8_p_x;
  real_T c8_j_a;
  real_T c8_h_b;
  real_T c8_h_y;
  real_T c8_q_x;
  real_T c8_r_x;
  real_T c8_k_a;
  real_T c8_i_b;
  real_T c8_i_y;
  real_T c8_s_x;
  real_T c8_t_x;
  real_T c8_l_a;
  real_T c8_j_b;
  real_T c8_j_y;
  real_T c8_u_x;
  real_T c8_v_x;
  real_T c8_m_a;
  real_T c8_k_b;
  real_T c8_k_y;
  real_T c8_w_x;
  real_T c8_x_x;
  real_T c8_n_a;
  real_T c8_l_b;
  real_T c8_l_y;
  int32_T c8_i10;
  real_T c8_o_a[6];
  int32_T c8_i11;
  int32_T c8_i12;
  int32_T c8_i13;
  int32_T c8_i14;
  real_T c8_m_b[6];
  int32_T c8_i15;
  int32_T c8_i16;
  int32_T c8_i17;
  int32_T c8_i18;
  real_T c8_m_y[4];
  int32_T c8_i19;
  int32_T c8_i20;
  int32_T c8_i21;
  real_T c8_n_y[4];
  int32_T c8_i22;
  real_T c8_y_x;
  real_T c8_ab_x;
  real_T c8_bb_x;
  real_T c8_cb_x;
  real_T c8_p_a;
  real_T c8_n_b;
  real_T c8_o_y;
  real_T c8_db_x;
  real_T c8_eb_x;
  real_T c8_q_a;
  real_T c8_o_b;
  real_T c8_p_y;
  real_T c8_fb_x;
  real_T c8_gb_x;
  real_T c8_r_a;
  real_T c8_p_b;
  real_T c8_q_y;
  real_T c8_hb_x;
  real_T c8_ib_x;
  real_T c8_jb_x;
  real_T c8_kb_x;
  real_T c8_s_a;
  real_T c8_q_b;
  real_T c8_r_y;
  real_T c8_lb_x;
  real_T c8_mb_x;
  real_T c8_t_a;
  real_T c8_r_b;
  real_T c8_s_y;
  real_T c8_nb_x;
  real_T c8_ob_x;
  real_T c8_u_a;
  real_T c8_s_b;
  real_T c8_t_y;
  real_T c8_pb_x;
  real_T c8_qb_x;
  real_T c8_rb_x;
  real_T c8_sb_x;
  real_T c8_v_a;
  real_T c8_t_b;
  real_T c8_u_y;
  real_T c8_tb_x;
  real_T c8_ub_x;
  real_T c8_w_a;
  real_T c8_u_b;
  real_T c8_v_y;
  real_T c8_vb_x;
  real_T c8_wb_x;
  real_T c8_x_a;
  real_T c8_v_b;
  real_T c8_w_y;
  real_T c8_xb_x;
  real_T c8_yb_x;
  real_T c8_ac_x;
  real_T c8_bc_x;
  real_T c8_y_a;
  real_T c8_w_b;
  real_T c8_x_y;
  real_T c8_cc_x;
  real_T c8_dc_x;
  real_T c8_ab_a;
  real_T c8_x_b;
  real_T c8_y_y;
  real_T c8_ec_x;
  real_T c8_fc_x;
  real_T c8_bb_a;
  real_T c8_y_b;
  real_T c8_ab_y;
  real_T c8_gc_x;
  real_T c8_hc_x;
  real_T c8_ic_x;
  real_T c8_jc_x;
  real_T c8_cb_a;
  real_T c8_ab_b;
  real_T c8_bb_y;
  real_T c8_kc_x;
  real_T c8_lc_x;
  real_T c8_db_a;
  real_T c8_bb_b;
  real_T c8_cb_y;
  real_T c8_mc_x;
  real_T c8_nc_x;
  real_T c8_eb_a;
  real_T c8_cb_b;
  real_T c8_db_y;
  real_T c8_oc_x;
  real_T c8_pc_x;
  real_T c8_qc_x;
  real_T c8_rc_x;
  real_T c8_fb_a;
  real_T c8_db_b;
  real_T c8_eb_y;
  real_T c8_sc_x;
  real_T c8_tc_x;
  real_T c8_gb_a;
  real_T c8_eb_b;
  real_T c8_fb_y;
  real_T c8_uc_x;
  real_T c8_vc_x;
  real_T c8_hb_a;
  real_T c8_fb_b;
  real_T c8_gb_y;
  real_T c8_wc_x;
  real_T c8_xc_x;
  real_T c8_yc_x;
  real_T c8_ad_x;
  real_T c8_ib_a;
  real_T c8_gb_b;
  real_T c8_hb_y;
  real_T c8_bd_x;
  real_T c8_cd_x;
  real_T c8_jb_a;
  real_T c8_hb_b;
  real_T c8_ib_y;
  real_T c8_dd_x;
  real_T c8_ed_x;
  real_T c8_kb_a;
  real_T c8_ib_b;
  real_T c8_jb_y;
  real_T c8_fd_x;
  real_T c8_gd_x;
  real_T c8_hd_x;
  real_T c8_id_x;
  real_T c8_lb_a;
  real_T c8_jb_b;
  real_T c8_kb_y;
  real_T c8_jd_x;
  real_T c8_kd_x;
  real_T c8_mb_a;
  real_T c8_kb_b;
  real_T c8_lb_y;
  real_T c8_ld_x;
  real_T c8_md_x;
  real_T c8_nb_a;
  real_T c8_lb_b;
  real_T c8_mb_y;
  real_T c8_nd_x;
  real_T c8_od_x;
  real_T c8_pd_x;
  real_T c8_qd_x;
  real_T c8_ob_a;
  real_T c8_mb_b;
  real_T c8_nb_y;
  real_T c8_rd_x;
  real_T c8_sd_x;
  real_T c8_pb_a;
  real_T c8_nb_b;
  real_T c8_ob_y;
  real_T c8_td_x;
  real_T c8_ud_x;
  real_T c8_qb_a;
  real_T c8_ob_b;
  real_T c8_pb_y;
  real_T c8_vd_x;
  real_T c8_wd_x;
  real_T c8_xd_x;
  real_T c8_yd_x;
  real_T c8_rb_a;
  real_T c8_pb_b;
  real_T c8_qb_y;
  real_T c8_ae_x;
  real_T c8_be_x;
  real_T c8_sb_a;
  real_T c8_qb_b;
  real_T c8_rb_y;
  real_T c8_ce_x;
  real_T c8_de_x;
  real_T c8_tb_a;
  real_T c8_rb_b;
  real_T c8_sb_y;
  real_T c8_ee_x;
  real_T c8_fe_x;
  real_T c8_ge_x;
  real_T c8_he_x;
  real_T c8_ub_a;
  real_T c8_sb_b;
  real_T c8_tb_y;
  real_T c8_ie_x;
  real_T c8_je_x;
  real_T c8_vb_a;
  real_T c8_tb_b;
  real_T c8_ub_y;
  real_T c8_ke_x;
  real_T c8_le_x;
  real_T c8_wb_a;
  real_T c8_ub_b;
  real_T c8_vb_y;
  real_T c8_me_x;
  real_T c8_ne_x;
  real_T c8_oe_x;
  real_T c8_pe_x;
  real_T c8_xb_a;
  real_T c8_vb_b;
  real_T c8_wb_y;
  real_T c8_qe_x;
  real_T c8_re_x;
  real_T c8_yb_a;
  real_T c8_wb_b;
  real_T c8_xb_y;
  real_T c8_se_x;
  real_T c8_te_x;
  real_T c8_ac_a;
  real_T c8_xb_b;
  real_T c8_yb_y;
  real_T c8_ue_x;
  real_T c8_ve_x;
  real_T c8_we_x;
  real_T c8_xe_x;
  real_T c8_bc_a;
  real_T c8_yb_b;
  real_T c8_ac_y;
  real_T c8_ye_x;
  real_T c8_af_x;
  real_T c8_cc_a;
  real_T c8_ac_b;
  real_T c8_bc_y;
  real_T c8_bf_x;
  real_T c8_cf_x;
  real_T c8_dc_a;
  real_T c8_bc_b;
  real_T c8_cc_y;
  real_T c8_df_x;
  real_T c8_ef_x;
  real_T c8_ff_x;
  real_T c8_gf_x;
  real_T c8_ec_a;
  real_T c8_cc_b;
  real_T c8_dc_y;
  real_T c8_hf_x;
  real_T c8_if_x;
  real_T c8_fc_a;
  real_T c8_dc_b;
  real_T c8_ec_y;
  real_T c8_jf_x;
  real_T c8_kf_x;
  real_T c8_gc_a;
  real_T c8_ec_b;
  real_T c8_fc_y;
  real_T c8_lf_x;
  real_T c8_mf_x;
  real_T c8_nf_x;
  real_T c8_of_x;
  real_T c8_hc_a;
  real_T c8_fc_b;
  real_T c8_gc_y;
  real_T c8_pf_x;
  real_T c8_qf_x;
  real_T c8_ic_a;
  real_T c8_gc_b;
  real_T c8_hc_y;
  real_T c8_rf_x;
  real_T c8_sf_x;
  real_T c8_jc_a;
  real_T c8_hc_b;
  real_T c8_ic_y;
  real_T c8_tf_x;
  real_T c8_uf_x;
  real_T c8_vf_x;
  real_T c8_wf_x;
  real_T c8_kc_a;
  real_T c8_ic_b;
  real_T c8_jc_y;
  real_T c8_xf_x;
  real_T c8_yf_x;
  real_T c8_lc_a;
  real_T c8_jc_b;
  real_T c8_kc_y;
  real_T c8_ag_x;
  real_T c8_bg_x;
  real_T c8_mc_a;
  real_T c8_kc_b;
  real_T c8_lc_y;
  real_T c8_cg_x;
  real_T c8_dg_x;
  real_T c8_eg_x;
  real_T c8_fg_x;
  real_T c8_nc_a;
  real_T c8_lc_b;
  real_T c8_mc_y;
  real_T c8_gg_x;
  real_T c8_hg_x;
  real_T c8_oc_a;
  real_T c8_mc_b;
  real_T c8_nc_y;
  real_T c8_ig_x;
  real_T c8_jg_x;
  real_T c8_pc_a;
  real_T c8_nc_b;
  real_T c8_oc_y;
  real_T c8_kg_x;
  real_T c8_lg_x;
  real_T c8_mg_x;
  real_T c8_ng_x;
  real_T c8_qc_a;
  real_T c8_oc_b;
  real_T c8_pc_y;
  real_T c8_og_x;
  real_T c8_pg_x;
  real_T c8_rc_a;
  real_T c8_pc_b;
  real_T c8_qc_y;
  real_T c8_qg_x;
  real_T c8_rg_x;
  real_T c8_sc_a;
  real_T c8_qc_b;
  real_T c8_rc_y;
  real_T c8_sg_x;
  real_T c8_tg_x;
  real_T c8_ug_x;
  real_T c8_vg_x;
  real_T c8_tc_a;
  real_T c8_rc_b;
  real_T c8_sc_y;
  real_T c8_wg_x;
  real_T c8_xg_x;
  real_T c8_uc_a;
  real_T c8_sc_b;
  real_T c8_tc_y;
  real_T c8_yg_x;
  real_T c8_ah_x;
  real_T c8_vc_a;
  real_T c8_tc_b;
  real_T c8_uc_y;
  real_T c8_bh_x;
  real_T c8_ch_x;
  real_T c8_dh_x;
  real_T c8_eh_x;
  real_T c8_wc_a;
  real_T c8_uc_b;
  real_T c8_vc_y;
  real_T c8_fh_x;
  real_T c8_gh_x;
  real_T c8_xc_a;
  real_T c8_vc_b;
  real_T c8_wc_y;
  real_T c8_hh_x;
  real_T c8_ih_x;
  real_T c8_yc_a;
  real_T c8_wc_b;
  real_T c8_xc_y;
  real_T c8_jh_x;
  real_T c8_kh_x;
  real_T c8_lh_x;
  real_T c8_mh_x;
  real_T c8_ad_a;
  real_T c8_xc_b;
  real_T c8_yc_y;
  real_T c8_nh_x;
  real_T c8_oh_x;
  real_T c8_bd_a;
  real_T c8_yc_b;
  real_T c8_ad_y;
  real_T c8_ph_x;
  real_T c8_qh_x;
  real_T c8_cd_a;
  real_T c8_ad_b;
  real_T c8_bd_y;
  real_T c8_rh_x;
  real_T c8_sh_x;
  real_T c8_th_x;
  real_T c8_uh_x;
  real_T c8_dd_a;
  real_T c8_bd_b;
  real_T c8_cd_y;
  real_T c8_vh_x;
  real_T c8_wh_x;
  real_T c8_ed_a;
  real_T c8_cd_b;
  real_T c8_dd_y;
  real_T c8_xh_x;
  real_T c8_yh_x;
  real_T c8_fd_a;
  real_T c8_dd_b;
  real_T c8_ed_y;
  real_T c8_ai_x;
  real_T c8_bi_x;
  real_T c8_ci_x;
  real_T c8_di_x;
  real_T c8_gd_a;
  real_T c8_ed_b;
  real_T c8_fd_y;
  real_T c8_ei_x;
  real_T c8_fi_x;
  real_T c8_hd_a;
  real_T c8_fd_b;
  real_T c8_gd_y;
  real_T c8_gi_x;
  real_T c8_hi_x;
  real_T c8_id_a;
  real_T c8_gd_b;
  real_T c8_hd_y;
  real_T c8_ii_x;
  real_T c8_ji_x;
  real_T c8_ki_x;
  real_T c8_li_x;
  real_T c8_jd_a;
  real_T c8_hd_b;
  real_T c8_id_y;
  real_T c8_mi_x;
  real_T c8_ni_x;
  real_T c8_kd_a;
  real_T c8_id_b;
  real_T c8_jd_y;
  real_T c8_oi_x;
  real_T c8_pi_x;
  real_T c8_ld_a;
  real_T c8_jd_b;
  real_T c8_kd_y;
  real_T c8_qi_x;
  real_T c8_ri_x;
  real_T c8_si_x;
  real_T c8_ti_x;
  real_T c8_md_a;
  real_T c8_kd_b;
  real_T c8_ld_y;
  real_T c8_ui_x;
  real_T c8_vi_x;
  real_T c8_nd_a;
  real_T c8_ld_b;
  real_T c8_md_y;
  real_T c8_wi_x;
  real_T c8_xi_x;
  real_T c8_od_a;
  real_T c8_md_b;
  real_T c8_nd_y;
  real_T c8_yi_x;
  real_T c8_aj_x;
  real_T c8_bj_x;
  real_T c8_cj_x;
  real_T c8_pd_a;
  real_T c8_nd_b;
  real_T c8_od_y;
  real_T c8_dj_x;
  real_T c8_ej_x;
  real_T c8_qd_a;
  real_T c8_od_b;
  real_T c8_pd_y;
  real_T c8_fj_x;
  real_T c8_gj_x;
  real_T c8_rd_a;
  real_T c8_pd_b;
  real_T c8_qd_y;
  real_T c8_hj_x;
  real_T c8_ij_x;
  real_T c8_jj_x;
  real_T c8_kj_x;
  real_T c8_sd_a;
  real_T c8_qd_b;
  real_T c8_rd_y;
  real_T c8_lj_x;
  real_T c8_mj_x;
  real_T c8_td_a;
  real_T c8_rd_b;
  real_T c8_sd_y;
  real_T c8_nj_x;
  real_T c8_oj_x;
  real_T c8_ud_a;
  real_T c8_sd_b;
  real_T c8_td_y;
  real_T c8_pj_x;
  real_T c8_qj_x;
  real_T c8_rj_x;
  real_T c8_sj_x;
  real_T c8_vd_a;
  real_T c8_td_b;
  real_T c8_ud_y;
  real_T c8_tj_x;
  real_T c8_uj_x;
  real_T c8_wd_a;
  real_T c8_ud_b;
  real_T c8_vd_y;
  real_T c8_vj_x;
  real_T c8_wj_x;
  real_T c8_xd_a;
  real_T c8_vd_b;
  real_T c8_wd_y;
  real_T c8_xj_x;
  real_T c8_yj_x;
  real_T c8_wd_b;
  real_T c8_xd_y;
  real_T c8_ak_x;
  real_T c8_bk_x;
  real_T c8_yd_a;
  real_T c8_xd_b;
  real_T c8_yd_y;
  real_T c8_ck_x;
  real_T c8_dk_x;
  real_T c8_ae_a;
  real_T c8_yd_b;
  real_T c8_ae_y;
  real_T c8_ek_x;
  real_T c8_fk_x;
  real_T c8_be_a;
  real_T c8_ae_b;
  real_T c8_be_y;
  real_T c8_gk_x;
  real_T c8_hk_x;
  real_T c8_be_b;
  real_T c8_ce_y;
  real_T c8_ik_x;
  real_T c8_jk_x;
  real_T c8_ce_a;
  real_T c8_ce_b;
  real_T c8_de_y;
  real_T c8_kk_x;
  real_T c8_lk_x;
  real_T c8_de_a;
  real_T c8_de_b;
  real_T c8_ee_y;
  real_T c8_mk_x;
  real_T c8_nk_x;
  real_T c8_ee_a;
  real_T c8_ee_b;
  real_T c8_fe_y;
  real_T c8_ok_x;
  real_T c8_pk_x;
  real_T c8_fe_b;
  real_T c8_ge_y;
  real_T c8_qk_x;
  real_T c8_rk_x;
  real_T c8_fe_a;
  real_T c8_ge_b;
  real_T c8_he_y;
  real_T c8_sk_x;
  real_T c8_tk_x;
  real_T c8_ge_a;
  real_T c8_he_b;
  real_T c8_ie_y;
  real_T c8_uk_x;
  real_T c8_vk_x;
  real_T c8_he_a;
  real_T c8_ie_b;
  real_T c8_je_y;
  real_T c8_wk_x;
  real_T c8_xk_x;
  real_T c8_je_b;
  real_T c8_ke_y;
  real_T c8_yk_x;
  real_T c8_al_x;
  real_T c8_ie_a;
  real_T c8_ke_b;
  real_T c8_le_y;
  real_T c8_bl_x;
  real_T c8_cl_x;
  real_T c8_je_a;
  real_T c8_le_b;
  real_T c8_me_y;
  real_T c8_dl_x;
  real_T c8_el_x;
  real_T c8_ke_a;
  real_T c8_me_b;
  real_T c8_ne_y;
  real_T c8_fl_x;
  real_T c8_gl_x;
  real_T c8_ne_b;
  real_T c8_oe_y;
  real_T c8_hl_x;
  real_T c8_il_x;
  real_T c8_le_a;
  real_T c8_oe_b;
  real_T c8_pe_y;
  real_T c8_jl_x;
  real_T c8_kl_x;
  real_T c8_me_a;
  real_T c8_pe_b;
  real_T c8_qe_y;
  real_T c8_ll_x;
  real_T c8_ml_x;
  real_T c8_ne_a;
  real_T c8_qe_b;
  real_T c8_re_y;
  real_T c8_nl_x;
  real_T c8_ol_x;
  real_T c8_re_b;
  real_T c8_se_y;
  real_T c8_pl_x;
  real_T c8_ql_x;
  real_T c8_oe_a;
  real_T c8_se_b;
  real_T c8_te_y;
  real_T c8_rl_x;
  real_T c8_sl_x;
  real_T c8_pe_a;
  real_T c8_te_b;
  real_T c8_ue_y;
  real_T c8_tl_x;
  real_T c8_ul_x;
  real_T c8_qe_a;
  real_T c8_ue_b;
  real_T c8_ve_y;
  real_T c8_vl_x;
  real_T c8_wl_x;
  real_T c8_ve_b;
  real_T c8_we_y;
  real_T c8_xl_x;
  real_T c8_yl_x;
  real_T c8_re_a;
  real_T c8_we_b;
  real_T c8_xe_y;
  real_T c8_am_x;
  real_T c8_bm_x;
  real_T c8_se_a;
  real_T c8_xe_b;
  real_T c8_ye_y;
  real_T c8_cm_x;
  real_T c8_dm_x;
  real_T c8_te_a;
  real_T c8_ye_b;
  real_T c8_af_y;
  real_T c8_em_x;
  real_T c8_fm_x;
  real_T c8_af_b;
  real_T c8_bf_y;
  real_T c8_gm_x;
  real_T c8_hm_x;
  real_T c8_ue_a;
  real_T c8_bf_b;
  real_T c8_cf_y;
  real_T c8_im_x;
  real_T c8_jm_x;
  real_T c8_ve_a;
  real_T c8_cf_b;
  real_T c8_df_y;
  real_T c8_km_x;
  real_T c8_lm_x;
  real_T c8_we_a;
  real_T c8_df_b;
  real_T c8_ef_y;
  real_T c8_mm_x;
  real_T c8_nm_x;
  real_T c8_om_x;
  real_T c8_pm_x;
  real_T c8_xe_a;
  real_T c8_ef_b;
  real_T c8_ff_y;
  real_T c8_qm_x;
  real_T c8_rm_x;
  real_T c8_ye_a;
  real_T c8_ff_b;
  real_T c8_gf_y;
  real_T c8_sm_x;
  real_T c8_tm_x;
  real_T c8_af_a;
  real_T c8_gf_b;
  real_T c8_hf_y;
  real_T c8_um_x;
  real_T c8_vm_x;
  real_T c8_wm_x;
  real_T c8_xm_x;
  real_T c8_bf_a;
  real_T c8_hf_b;
  real_T c8_if_y;
  real_T c8_ym_x;
  real_T c8_an_x;
  real_T c8_cf_a;
  real_T c8_if_b;
  real_T c8_jf_y;
  real_T c8_bn_x;
  real_T c8_cn_x;
  real_T c8_df_a;
  real_T c8_jf_b;
  real_T c8_kf_y;
  real_T c8_dn_x;
  real_T c8_en_x;
  real_T c8_fn_x;
  real_T c8_gn_x;
  real_T c8_ef_a;
  real_T c8_kf_b;
  real_T c8_lf_y;
  real_T c8_hn_x;
  real_T c8_in_x;
  real_T c8_ff_a;
  real_T c8_lf_b;
  real_T c8_mf_y;
  real_T c8_jn_x;
  real_T c8_kn_x;
  real_T c8_gf_a;
  real_T c8_mf_b;
  real_T c8_nf_y;
  real_T c8_ln_x;
  real_T c8_mn_x;
  real_T c8_nn_x;
  real_T c8_on_x;
  real_T c8_hf_a;
  real_T c8_nf_b;
  real_T c8_of_y;
  real_T c8_pn_x;
  real_T c8_qn_x;
  real_T c8_if_a;
  real_T c8_of_b;
  real_T c8_pf_y;
  real_T c8_rn_x;
  real_T c8_sn_x;
  real_T c8_jf_a;
  real_T c8_pf_b;
  real_T c8_qf_y;
  real_T c8_tn_x;
  real_T c8_un_x;
  real_T c8_vn_x;
  real_T c8_wn_x;
  real_T c8_kf_a;
  real_T c8_qf_b;
  real_T c8_rf_y;
  real_T c8_xn_x;
  real_T c8_yn_x;
  real_T c8_lf_a;
  real_T c8_rf_b;
  real_T c8_sf_y;
  real_T c8_ao_x;
  real_T c8_bo_x;
  real_T c8_mf_a;
  real_T c8_sf_b;
  real_T c8_tf_y;
  real_T c8_co_x;
  real_T c8_do_x;
  real_T c8_eo_x;
  real_T c8_fo_x;
  real_T c8_nf_a;
  real_T c8_tf_b;
  real_T c8_uf_y;
  real_T c8_go_x;
  real_T c8_ho_x;
  real_T c8_of_a;
  real_T c8_uf_b;
  real_T c8_vf_y;
  real_T c8_io_x;
  real_T c8_jo_x;
  real_T c8_pf_a;
  real_T c8_vf_b;
  real_T c8_wf_y;
  real_T c8_ko_x;
  real_T c8_lo_x;
  real_T c8_mo_x;
  real_T c8_no_x;
  real_T c8_qf_a;
  real_T c8_wf_b;
  real_T c8_xf_y;
  real_T c8_oo_x;
  real_T c8_po_x;
  real_T c8_rf_a;
  real_T c8_xf_b;
  real_T c8_yf_y;
  real_T c8_qo_x;
  real_T c8_ro_x;
  real_T c8_sf_a;
  real_T c8_yf_b;
  real_T c8_ag_y;
  real_T c8_so_x;
  real_T c8_to_x;
  real_T c8_uo_x;
  real_T c8_vo_x;
  real_T c8_tf_a;
  real_T c8_ag_b;
  real_T c8_bg_y;
  real_T c8_wo_x;
  real_T c8_xo_x;
  real_T c8_uf_a;
  real_T c8_bg_b;
  real_T c8_cg_y;
  real_T c8_yo_x;
  real_T c8_ap_x;
  real_T c8_vf_a;
  real_T c8_cg_b;
  real_T c8_dg_y;
  real_T c8_bp_x;
  real_T c8_cp_x;
  real_T c8_dp_x;
  real_T c8_ep_x;
  real_T c8_wf_a;
  real_T c8_dg_b;
  real_T c8_eg_y;
  real_T c8_fp_x;
  real_T c8_gp_x;
  real_T c8_xf_a;
  real_T c8_eg_b;
  real_T c8_fg_y;
  real_T c8_hp_x;
  real_T c8_ip_x;
  real_T c8_yf_a;
  real_T c8_fg_b;
  real_T c8_gg_y;
  real_T c8_jp_x;
  real_T c8_kp_x;
  real_T c8_lp_x;
  real_T c8_mp_x;
  real_T c8_ag_a;
  real_T c8_gg_b;
  real_T c8_hg_y;
  real_T c8_np_x;
  real_T c8_op_x;
  real_T c8_bg_a;
  real_T c8_hg_b;
  real_T c8_ig_y;
  real_T c8_pp_x;
  real_T c8_qp_x;
  real_T c8_cg_a;
  real_T c8_ig_b;
  real_T c8_jg_y;
  real_T c8_rp_x;
  real_T c8_sp_x;
  real_T c8_tp_x;
  real_T c8_up_x;
  real_T c8_dg_a;
  real_T c8_jg_b;
  real_T c8_kg_y;
  real_T c8_vp_x;
  real_T c8_wp_x;
  real_T c8_eg_a;
  real_T c8_kg_b;
  real_T c8_lg_y;
  real_T c8_xp_x;
  real_T c8_yp_x;
  real_T c8_fg_a;
  real_T c8_lg_b;
  real_T c8_mg_y;
  real_T c8_aq_x;
  real_T c8_bq_x;
  real_T c8_cq_x;
  real_T c8_dq_x;
  real_T c8_gg_a;
  real_T c8_mg_b;
  real_T c8_ng_y;
  real_T c8_eq_x;
  real_T c8_fq_x;
  real_T c8_hg_a;
  real_T c8_ng_b;
  real_T c8_og_y;
  real_T c8_gq_x;
  real_T c8_hq_x;
  real_T c8_ig_a;
  real_T c8_og_b;
  real_T c8_pg_y;
  real_T c8_iq_x;
  real_T c8_jq_x;
  real_T c8_kq_x;
  real_T c8_lq_x;
  real_T c8_jg_a;
  real_T c8_pg_b;
  real_T c8_qg_y;
  real_T c8_mq_x;
  real_T c8_nq_x;
  real_T c8_kg_a;
  real_T c8_qg_b;
  real_T c8_rg_y;
  real_T c8_oq_x;
  real_T c8_pq_x;
  real_T c8_lg_a;
  real_T c8_rg_b;
  real_T c8_sg_y;
  real_T c8_qq_x;
  real_T c8_rq_x;
  real_T c8_sq_x;
  real_T c8_tq_x;
  real_T c8_mg_a;
  real_T c8_sg_b;
  real_T c8_tg_y;
  real_T c8_uq_x;
  real_T c8_vq_x;
  real_T c8_ng_a;
  real_T c8_tg_b;
  real_T c8_ug_y;
  real_T c8_wq_x;
  real_T c8_xq_x;
  real_T c8_og_a;
  real_T c8_ug_b;
  real_T c8_vg_y;
  real_T c8_yq_x;
  real_T c8_ar_x;
  real_T c8_br_x;
  real_T c8_cr_x;
  real_T c8_pg_a;
  real_T c8_vg_b;
  real_T c8_wg_y;
  real_T c8_dr_x;
  real_T c8_er_x;
  real_T c8_qg_a;
  real_T c8_wg_b;
  real_T c8_xg_y;
  real_T c8_fr_x;
  real_T c8_gr_x;
  real_T c8_rg_a;
  real_T c8_xg_b;
  real_T c8_yg_y;
  real_T c8_hr_x;
  real_T c8_ir_x;
  real_T c8_jr_x;
  real_T c8_kr_x;
  real_T c8_sg_a;
  real_T c8_yg_b;
  real_T c8_ah_y;
  real_T c8_lr_x;
  real_T c8_mr_x;
  real_T c8_tg_a;
  real_T c8_ah_b;
  real_T c8_bh_y;
  real_T c8_nr_x;
  real_T c8_or_x;
  real_T c8_ug_a;
  real_T c8_bh_b;
  real_T c8_ch_y;
  real_T c8_pr_x;
  real_T c8_qr_x;
  real_T c8_rr_x;
  real_T c8_sr_x;
  real_T c8_vg_a;
  real_T c8_ch_b;
  real_T c8_dh_y;
  real_T c8_tr_x;
  real_T c8_ur_x;
  real_T c8_wg_a;
  real_T c8_dh_b;
  real_T c8_eh_y;
  real_T c8_vr_x;
  real_T c8_wr_x;
  real_T c8_xg_a;
  real_T c8_eh_b;
  real_T c8_fh_y;
  real_T c8_xr_x;
  real_T c8_yr_x;
  real_T c8_as_x;
  real_T c8_bs_x;
  real_T c8_yg_a;
  real_T c8_fh_b;
  real_T c8_gh_y;
  real_T c8_cs_x;
  real_T c8_ds_x;
  real_T c8_ah_a;
  real_T c8_gh_b;
  real_T c8_hh_y;
  real_T c8_es_x;
  real_T c8_fs_x;
  real_T c8_bh_a;
  real_T c8_hh_b;
  real_T c8_ih_y;
  real_T c8_gs_x;
  real_T c8_hs_x;
  real_T c8_is_x;
  real_T c8_js_x;
  real_T c8_ch_a;
  real_T c8_ih_b;
  real_T c8_jh_y;
  real_T c8_ks_x;
  real_T c8_ls_x;
  real_T c8_dh_a;
  real_T c8_jh_b;
  real_T c8_kh_y;
  real_T c8_ms_x;
  real_T c8_ns_x;
  real_T c8_eh_a;
  real_T c8_kh_b;
  real_T c8_lh_y;
  real_T c8_os_x;
  real_T c8_ps_x;
  real_T c8_qs_x;
  real_T c8_rs_x;
  real_T c8_fh_a;
  real_T c8_lh_b;
  real_T c8_mh_y;
  real_T c8_ss_x;
  real_T c8_ts_x;
  real_T c8_gh_a;
  real_T c8_mh_b;
  real_T c8_nh_y;
  real_T c8_us_x;
  real_T c8_vs_x;
  real_T c8_hh_a;
  real_T c8_nh_b;
  real_T c8_oh_y;
  real_T c8_ws_x;
  real_T c8_xs_x;
  real_T c8_ys_x;
  real_T c8_at_x;
  real_T c8_ih_a;
  real_T c8_oh_b;
  real_T c8_ph_y;
  real_T c8_bt_x;
  real_T c8_ct_x;
  real_T c8_jh_a;
  real_T c8_ph_b;
  real_T c8_qh_y;
  real_T c8_dt_x;
  real_T c8_et_x;
  real_T c8_kh_a;
  real_T c8_qh_b;
  real_T c8_rh_y;
  real_T c8_ft_x;
  real_T c8_gt_x;
  real_T c8_ht_x;
  real_T c8_it_x;
  real_T c8_lh_a;
  real_T c8_rh_b;
  real_T c8_sh_y;
  real_T c8_jt_x;
  real_T c8_kt_x;
  real_T c8_mh_a;
  real_T c8_sh_b;
  real_T c8_th_y;
  real_T c8_lt_x;
  real_T c8_mt_x;
  real_T c8_nh_a;
  real_T c8_th_b;
  real_T c8_uh_y;
  real_T c8_nt_x;
  real_T c8_ot_x;
  real_T c8_pt_x;
  real_T c8_qt_x;
  real_T c8_oh_a;
  real_T c8_uh_b;
  real_T c8_vh_y;
  real_T c8_rt_x;
  real_T c8_st_x;
  real_T c8_ph_a;
  real_T c8_vh_b;
  real_T c8_wh_y;
  real_T c8_tt_x;
  real_T c8_ut_x;
  real_T c8_qh_a;
  real_T c8_wh_b;
  real_T c8_xh_y;
  real_T c8_vt_x;
  real_T c8_wt_x;
  real_T c8_xt_x;
  real_T c8_yt_x;
  real_T c8_rh_a;
  real_T c8_xh_b;
  real_T c8_yh_y;
  real_T c8_au_x;
  real_T c8_bu_x;
  real_T c8_sh_a;
  real_T c8_yh_b;
  real_T c8_ai_y;
  real_T c8_cu_x;
  real_T c8_du_x;
  real_T c8_th_a;
  real_T c8_ai_b;
  real_T c8_bi_y;
  real_T c8_eu_x;
  real_T c8_fu_x;
  real_T c8_bi_b;
  real_T c8_ci_y;
  real_T c8_gu_x;
  real_T c8_hu_x;
  real_T c8_uh_a;
  real_T c8_ci_b;
  real_T c8_di_y;
  real_T c8_iu_x;
  real_T c8_ju_x;
  real_T c8_vh_a;
  real_T c8_di_b;
  real_T c8_ei_y;
  real_T c8_ku_x;
  real_T c8_lu_x;
  real_T c8_wh_a;
  real_T c8_ei_b;
  real_T c8_fi_y;
  real_T c8_mu_x;
  real_T c8_nu_x;
  real_T c8_fi_b;
  real_T c8_gi_y;
  real_T c8_ou_x;
  real_T c8_pu_x;
  real_T c8_xh_a;
  real_T c8_gi_b;
  real_T c8_hi_y;
  real_T c8_qu_x;
  real_T c8_ru_x;
  real_T c8_yh_a;
  real_T c8_hi_b;
  real_T c8_ii_y;
  real_T c8_su_x;
  real_T c8_tu_x;
  real_T c8_ai_a;
  real_T c8_ii_b;
  real_T c8_ji_y;
  real_T c8_uu_x;
  real_T c8_vu_x;
  real_T c8_ji_b;
  real_T c8_ki_y;
  real_T c8_wu_x;
  real_T c8_xu_x;
  real_T c8_bi_a;
  real_T c8_ki_b;
  real_T c8_li_y;
  real_T c8_yu_x;
  real_T c8_av_x;
  real_T c8_ci_a;
  real_T c8_li_b;
  real_T c8_mi_y;
  real_T c8_bv_x;
  real_T c8_cv_x;
  real_T c8_di_a;
  real_T c8_mi_b;
  real_T c8_ni_y;
  real_T c8_dv_x;
  real_T c8_ev_x;
  real_T c8_ni_b;
  real_T c8_oi_y;
  real_T c8_fv_x;
  real_T c8_gv_x;
  real_T c8_ei_a;
  real_T c8_oi_b;
  real_T c8_pi_y;
  real_T c8_hv_x;
  real_T c8_iv_x;
  real_T c8_fi_a;
  real_T c8_pi_b;
  real_T c8_qi_y;
  real_T c8_jv_x;
  real_T c8_kv_x;
  real_T c8_gi_a;
  real_T c8_qi_b;
  real_T c8_ri_y;
  real_T c8_lv_x;
  real_T c8_mv_x;
  real_T c8_ri_b;
  real_T c8_si_y;
  real_T c8_nv_x;
  real_T c8_ov_x;
  real_T c8_hi_a;
  real_T c8_si_b;
  real_T c8_ti_y;
  real_T c8_pv_x;
  real_T c8_qv_x;
  real_T c8_ii_a;
  real_T c8_ti_b;
  real_T c8_ui_y;
  real_T c8_rv_x;
  real_T c8_sv_x;
  real_T c8_ji_a;
  real_T c8_ui_b;
  real_T c8_vi_y;
  real_T c8_tv_x;
  real_T c8_uv_x;
  real_T c8_vi_b;
  real_T c8_wi_y;
  real_T c8_vv_x;
  real_T c8_wv_x;
  real_T c8_ki_a;
  real_T c8_wi_b;
  real_T c8_xi_y;
  real_T c8_xv_x;
  real_T c8_yv_x;
  real_T c8_li_a;
  real_T c8_xi_b;
  real_T c8_yi_y;
  real_T c8_aw_x;
  real_T c8_bw_x;
  real_T c8_mi_a;
  real_T c8_yi_b;
  real_T c8_aj_y;
  real_T c8_cw_x;
  real_T c8_dw_x;
  real_T c8_aj_b;
  real_T c8_bj_y;
  real_T c8_ew_x;
  real_T c8_fw_x;
  real_T c8_ni_a;
  real_T c8_bj_b;
  real_T c8_cj_y;
  real_T c8_gw_x;
  real_T c8_hw_x;
  real_T c8_oi_a;
  real_T c8_cj_b;
  real_T c8_dj_y;
  real_T c8_iw_x;
  real_T c8_jw_x;
  real_T c8_pi_a;
  real_T c8_dj_b;
  real_T c8_ej_y;
  real_T c8_kw_x;
  real_T c8_lw_x;
  real_T c8_ej_b;
  real_T c8_fj_y;
  real_T c8_mw_x;
  real_T c8_nw_x;
  real_T c8_qi_a;
  real_T c8_fj_b;
  real_T c8_gj_y;
  real_T c8_ow_x;
  real_T c8_pw_x;
  real_T c8_ri_a;
  real_T c8_gj_b;
  real_T c8_hj_y;
  real_T c8_qw_x;
  real_T c8_rw_x;
  real_T c8_si_a;
  real_T c8_hj_b;
  real_T c8_ij_y;
  real_T c8_ij_b;
  real_T c8_jj_y;
  real_T c8_b_A;
  real_T c8_B;
  real_T c8_sw_x;
  real_T c8_kj_y;
  real_T c8_tw_x;
  real_T c8_lj_y;
  real_T c8_mj_y;
  real_T c8_uw_x;
  real_T c8_vw_x;
  real_T c8_ww_x;
  real_T c8_xw_x;
  real_T c8_ti_a;
  real_T c8_jj_b;
  real_T c8_nj_y;
  real_T c8_yw_x;
  real_T c8_ax_x;
  real_T c8_ui_a;
  real_T c8_kj_b;
  real_T c8_oj_y;
  real_T c8_bx_x;
  real_T c8_cx_x;
  real_T c8_vi_a;
  real_T c8_lj_b;
  real_T c8_pj_y;
  real_T c8_dx_x;
  real_T c8_ex_x;
  real_T c8_fx_x;
  real_T c8_gx_x;
  real_T c8_wi_a;
  real_T c8_mj_b;
  real_T c8_qj_y;
  real_T c8_hx_x;
  real_T c8_ix_x;
  real_T c8_xi_a;
  real_T c8_nj_b;
  real_T c8_rj_y;
  real_T c8_jx_x;
  real_T c8_kx_x;
  real_T c8_yi_a;
  real_T c8_oj_b;
  real_T c8_sj_y;
  real_T c8_lx_x;
  real_T c8_mx_x;
  real_T c8_nx_x;
  real_T c8_ox_x;
  real_T c8_aj_a;
  real_T c8_pj_b;
  real_T c8_tj_y;
  real_T c8_px_x;
  real_T c8_qx_x;
  real_T c8_bj_a;
  real_T c8_qj_b;
  real_T c8_uj_y;
  real_T c8_rx_x;
  real_T c8_sx_x;
  real_T c8_cj_a;
  real_T c8_rj_b;
  real_T c8_vj_y;
  real_T c8_tx_x;
  real_T c8_ux_x;
  real_T c8_vx_x;
  real_T c8_wx_x;
  real_T c8_dj_a;
  real_T c8_sj_b;
  real_T c8_wj_y;
  real_T c8_xx_x;
  real_T c8_yx_x;
  real_T c8_ej_a;
  real_T c8_tj_b;
  real_T c8_xj_y;
  real_T c8_ay_x;
  real_T c8_by_x;
  real_T c8_fj_a;
  real_T c8_uj_b;
  real_T c8_yj_y;
  real_T c8_cy_x;
  real_T c8_dy_x;
  real_T c8_ey_x;
  real_T c8_fy_x;
  real_T c8_gj_a;
  real_T c8_vj_b;
  real_T c8_ak_y;
  real_T c8_gy_x;
  real_T c8_hy_x;
  real_T c8_hj_a;
  real_T c8_wj_b;
  real_T c8_bk_y;
  real_T c8_iy_x;
  real_T c8_jy_x;
  real_T c8_ij_a;
  real_T c8_xj_b;
  real_T c8_ck_y;
  real_T c8_ky_x;
  real_T c8_ly_x;
  real_T c8_my_x;
  real_T c8_ny_x;
  real_T c8_jj_a;
  real_T c8_yj_b;
  real_T c8_dk_y;
  real_T c8_oy_x;
  real_T c8_py_x;
  real_T c8_kj_a;
  real_T c8_ak_b;
  real_T c8_ek_y;
  real_T c8_qy_x;
  real_T c8_ry_x;
  real_T c8_lj_a;
  real_T c8_bk_b;
  real_T c8_fk_y;
  real_T c8_sy_x;
  real_T c8_ty_x;
  real_T c8_uy_x;
  real_T c8_vy_x;
  real_T c8_mj_a;
  real_T c8_ck_b;
  real_T c8_gk_y;
  real_T c8_wy_x;
  real_T c8_xy_x;
  real_T c8_nj_a;
  real_T c8_dk_b;
  real_T c8_hk_y;
  real_T c8_yy_x;
  real_T c8_aab_x;
  real_T c8_oj_a;
  real_T c8_ek_b;
  real_T c8_ik_y;
  real_T c8_bab_x;
  real_T c8_cab_x;
  real_T c8_dab_x;
  real_T c8_eab_x;
  real_T c8_pj_a;
  real_T c8_fk_b;
  real_T c8_jk_y;
  real_T c8_fab_x;
  real_T c8_gab_x;
  real_T c8_qj_a;
  real_T c8_gk_b;
  real_T c8_kk_y;
  real_T c8_hab_x;
  real_T c8_iab_x;
  real_T c8_rj_a;
  real_T c8_hk_b;
  real_T c8_lk_y;
  real_T c8_jab_x;
  real_T c8_kab_x;
  real_T c8_lab_x;
  real_T c8_mab_x;
  real_T c8_sj_a;
  real_T c8_ik_b;
  real_T c8_mk_y;
  real_T c8_nab_x;
  real_T c8_oab_x;
  real_T c8_tj_a;
  real_T c8_jk_b;
  real_T c8_nk_y;
  real_T c8_pab_x;
  real_T c8_qab_x;
  real_T c8_uj_a;
  real_T c8_kk_b;
  real_T c8_ok_y;
  real_T c8_rab_x;
  real_T c8_sab_x;
  real_T c8_tab_x;
  real_T c8_uab_x;
  real_T c8_vj_a;
  real_T c8_lk_b;
  real_T c8_pk_y;
  real_T c8_vab_x;
  real_T c8_wab_x;
  real_T c8_wj_a;
  real_T c8_mk_b;
  real_T c8_qk_y;
  real_T c8_xab_x;
  real_T c8_yab_x;
  real_T c8_xj_a;
  real_T c8_nk_b;
  real_T c8_rk_y;
  real_T c8_abb_x;
  real_T c8_bbb_x;
  real_T c8_cbb_x;
  real_T c8_dbb_x;
  real_T c8_yj_a;
  real_T c8_ok_b;
  real_T c8_sk_y;
  real_T c8_ebb_x;
  real_T c8_fbb_x;
  real_T c8_ak_a;
  real_T c8_pk_b;
  real_T c8_tk_y;
  real_T c8_gbb_x;
  real_T c8_hbb_x;
  real_T c8_bk_a;
  real_T c8_qk_b;
  real_T c8_uk_y;
  real_T c8_ibb_x;
  real_T c8_jbb_x;
  real_T c8_kbb_x;
  real_T c8_lbb_x;
  real_T c8_ck_a;
  real_T c8_rk_b;
  real_T c8_vk_y;
  real_T c8_mbb_x;
  real_T c8_nbb_x;
  real_T c8_dk_a;
  real_T c8_sk_b;
  real_T c8_wk_y;
  real_T c8_obb_x;
  real_T c8_pbb_x;
  real_T c8_ek_a;
  real_T c8_tk_b;
  real_T c8_xk_y;
  real_T c8_qbb_x;
  real_T c8_rbb_x;
  real_T c8_sbb_x;
  real_T c8_tbb_x;
  real_T c8_fk_a;
  real_T c8_uk_b;
  real_T c8_yk_y;
  real_T c8_ubb_x;
  real_T c8_vbb_x;
  real_T c8_gk_a;
  real_T c8_vk_b;
  real_T c8_al_y;
  real_T c8_wbb_x;
  real_T c8_xbb_x;
  real_T c8_hk_a;
  real_T c8_wk_b;
  real_T c8_bl_y;
  real_T c8_ybb_x;
  real_T c8_acb_x;
  real_T c8_bcb_x;
  real_T c8_ccb_x;
  real_T c8_ik_a;
  real_T c8_xk_b;
  real_T c8_cl_y;
  real_T c8_dcb_x;
  real_T c8_ecb_x;
  real_T c8_jk_a;
  real_T c8_yk_b;
  real_T c8_dl_y;
  real_T c8_fcb_x;
  real_T c8_gcb_x;
  real_T c8_kk_a;
  real_T c8_al_b;
  real_T c8_el_y;
  real_T c8_hcb_x;
  real_T c8_icb_x;
  real_T c8_jcb_x;
  real_T c8_kcb_x;
  real_T c8_lk_a;
  real_T c8_bl_b;
  real_T c8_fl_y;
  real_T c8_lcb_x;
  real_T c8_mcb_x;
  real_T c8_mk_a;
  real_T c8_cl_b;
  real_T c8_gl_y;
  real_T c8_ncb_x;
  real_T c8_ocb_x;
  real_T c8_nk_a;
  real_T c8_dl_b;
  real_T c8_hl_y;
  real_T c8_pcb_x;
  real_T c8_qcb_x;
  real_T c8_rcb_x;
  real_T c8_scb_x;
  real_T c8_ok_a;
  real_T c8_el_b;
  real_T c8_il_y;
  real_T c8_tcb_x;
  real_T c8_ucb_x;
  real_T c8_pk_a;
  real_T c8_fl_b;
  real_T c8_jl_y;
  real_T c8_vcb_x;
  real_T c8_wcb_x;
  real_T c8_qk_a;
  real_T c8_gl_b;
  real_T c8_kl_y;
  real_T c8_xcb_x;
  real_T c8_ycb_x;
  real_T c8_adb_x;
  real_T c8_bdb_x;
  real_T c8_rk_a;
  real_T c8_hl_b;
  real_T c8_ll_y;
  real_T c8_cdb_x;
  real_T c8_ddb_x;
  real_T c8_sk_a;
  real_T c8_il_b;
  real_T c8_ml_y;
  real_T c8_edb_x;
  real_T c8_fdb_x;
  real_T c8_tk_a;
  real_T c8_jl_b;
  real_T c8_nl_y;
  real_T c8_gdb_x;
  real_T c8_hdb_x;
  real_T c8_idb_x;
  real_T c8_jdb_x;
  real_T c8_uk_a;
  real_T c8_kl_b;
  real_T c8_ol_y;
  real_T c8_kdb_x;
  real_T c8_ldb_x;
  real_T c8_vk_a;
  real_T c8_ll_b;
  real_T c8_pl_y;
  real_T c8_mdb_x;
  real_T c8_ndb_x;
  real_T c8_wk_a;
  real_T c8_ml_b;
  real_T c8_ql_y;
  real_T c8_odb_x;
  real_T c8_pdb_x;
  real_T c8_qdb_x;
  real_T c8_rdb_x;
  real_T c8_xk_a;
  real_T c8_nl_b;
  real_T c8_rl_y;
  real_T c8_sdb_x;
  real_T c8_tdb_x;
  real_T c8_yk_a;
  real_T c8_ol_b;
  real_T c8_sl_y;
  real_T c8_udb_x;
  real_T c8_vdb_x;
  real_T c8_al_a;
  real_T c8_pl_b;
  real_T c8_tl_y;
  real_T c8_wdb_x;
  real_T c8_xdb_x;
  real_T c8_ydb_x;
  real_T c8_aeb_x;
  real_T c8_bl_a;
  real_T c8_ql_b;
  real_T c8_ul_y;
  real_T c8_beb_x;
  real_T c8_ceb_x;
  real_T c8_cl_a;
  real_T c8_rl_b;
  real_T c8_vl_y;
  real_T c8_deb_x;
  real_T c8_eeb_x;
  real_T c8_dl_a;
  real_T c8_sl_b;
  real_T c8_wl_y;
  real_T c8_feb_x;
  real_T c8_geb_x;
  real_T c8_heb_x;
  real_T c8_ieb_x;
  real_T c8_el_a;
  real_T c8_tl_b;
  real_T c8_xl_y;
  real_T c8_jeb_x;
  real_T c8_keb_x;
  real_T c8_fl_a;
  real_T c8_ul_b;
  real_T c8_yl_y;
  real_T c8_leb_x;
  real_T c8_meb_x;
  real_T c8_gl_a;
  real_T c8_vl_b;
  real_T c8_am_y;
  real_T c8_neb_x;
  real_T c8_oeb_x;
  real_T c8_peb_x;
  real_T c8_qeb_x;
  real_T c8_hl_a;
  real_T c8_wl_b;
  real_T c8_bm_y;
  real_T c8_reb_x;
  real_T c8_seb_x;
  real_T c8_il_a;
  real_T c8_xl_b;
  real_T c8_cm_y;
  real_T c8_teb_x;
  real_T c8_ueb_x;
  real_T c8_jl_a;
  real_T c8_yl_b;
  real_T c8_dm_y;
  real_T c8_veb_x;
  real_T c8_web_x;
  real_T c8_am_b;
  real_T c8_em_y;
  real_T c8_xeb_x;
  real_T c8_yeb_x;
  real_T c8_kl_a;
  real_T c8_bm_b;
  real_T c8_fm_y;
  real_T c8_afb_x;
  real_T c8_bfb_x;
  real_T c8_ll_a;
  real_T c8_cm_b;
  real_T c8_gm_y;
  real_T c8_cfb_x;
  real_T c8_dfb_x;
  real_T c8_ml_a;
  real_T c8_dm_b;
  real_T c8_hm_y;
  real_T c8_efb_x;
  real_T c8_ffb_x;
  real_T c8_em_b;
  real_T c8_im_y;
  real_T c8_gfb_x;
  real_T c8_hfb_x;
  real_T c8_nl_a;
  real_T c8_fm_b;
  real_T c8_jm_y;
  real_T c8_ifb_x;
  real_T c8_jfb_x;
  real_T c8_ol_a;
  real_T c8_gm_b;
  real_T c8_km_y;
  real_T c8_kfb_x;
  real_T c8_lfb_x;
  real_T c8_pl_a;
  real_T c8_hm_b;
  real_T c8_lm_y;
  real_T c8_mfb_x;
  real_T c8_nfb_x;
  real_T c8_im_b;
  real_T c8_mm_y;
  real_T c8_ofb_x;
  real_T c8_pfb_x;
  real_T c8_ql_a;
  real_T c8_jm_b;
  real_T c8_nm_y;
  real_T c8_qfb_x;
  real_T c8_rfb_x;
  real_T c8_rl_a;
  real_T c8_km_b;
  real_T c8_om_y;
  real_T c8_sfb_x;
  real_T c8_tfb_x;
  real_T c8_sl_a;
  real_T c8_lm_b;
  real_T c8_pm_y;
  real_T c8_ufb_x;
  real_T c8_vfb_x;
  real_T c8_mm_b;
  real_T c8_qm_y;
  real_T c8_wfb_x;
  real_T c8_xfb_x;
  real_T c8_tl_a;
  real_T c8_nm_b;
  real_T c8_rm_y;
  real_T c8_yfb_x;
  real_T c8_agb_x;
  real_T c8_ul_a;
  real_T c8_om_b;
  real_T c8_sm_y;
  real_T c8_bgb_x;
  real_T c8_cgb_x;
  real_T c8_vl_a;
  real_T c8_pm_b;
  real_T c8_tm_y;
  real_T c8_dgb_x;
  real_T c8_egb_x;
  real_T c8_qm_b;
  real_T c8_um_y;
  real_T c8_fgb_x;
  real_T c8_ggb_x;
  real_T c8_wl_a;
  real_T c8_rm_b;
  real_T c8_vm_y;
  real_T c8_hgb_x;
  real_T c8_igb_x;
  real_T c8_xl_a;
  real_T c8_sm_b;
  real_T c8_wm_y;
  real_T c8_jgb_x;
  real_T c8_kgb_x;
  real_T c8_yl_a;
  real_T c8_tm_b;
  real_T c8_xm_y;
  real_T c8_lgb_x;
  real_T c8_mgb_x;
  real_T c8_um_b;
  real_T c8_ym_y;
  real_T c8_ngb_x;
  real_T c8_ogb_x;
  real_T c8_am_a;
  real_T c8_vm_b;
  real_T c8_an_y;
  real_T c8_pgb_x;
  real_T c8_qgb_x;
  real_T c8_bm_a;
  real_T c8_wm_b;
  real_T c8_bn_y;
  real_T c8_rgb_x;
  real_T c8_sgb_x;
  real_T c8_cm_a;
  real_T c8_xm_b;
  real_T c8_cn_y;
  real_T c8_tgb_x;
  real_T c8_ugb_x;
  real_T c8_ym_b;
  real_T c8_dn_y;
  real_T c8_vgb_x;
  real_T c8_wgb_x;
  real_T c8_dm_a;
  real_T c8_an_b;
  real_T c8_en_y;
  real_T c8_xgb_x;
  real_T c8_ygb_x;
  real_T c8_em_a;
  real_T c8_bn_b;
  real_T c8_fn_y;
  real_T c8_ahb_x;
  real_T c8_bhb_x;
  real_T c8_fm_a;
  real_T c8_cn_b;
  real_T c8_gn_y;
  real_T c8_chb_x;
  real_T c8_dhb_x;
  real_T c8_dn_b;
  real_T c8_hn_y;
  real_T c8_ehb_x;
  real_T c8_fhb_x;
  real_T c8_gm_a;
  real_T c8_en_b;
  real_T c8_in_y;
  real_T c8_ghb_x;
  real_T c8_hhb_x;
  real_T c8_hm_a;
  real_T c8_fn_b;
  real_T c8_jn_y;
  real_T c8_ihb_x;
  real_T c8_jhb_x;
  real_T c8_im_a;
  real_T c8_gn_b;
  real_T c8_kn_y;
  real_T c8_khb_x;
  real_T c8_lhb_x;
  real_T c8_hn_b;
  real_T c8_ln_y;
  real_T c8_mhb_x;
  real_T c8_nhb_x;
  real_T c8_jm_a;
  real_T c8_in_b;
  real_T c8_mn_y;
  real_T c8_ohb_x;
  real_T c8_phb_x;
  real_T c8_km_a;
  real_T c8_jn_b;
  real_T c8_nn_y;
  real_T c8_qhb_x;
  real_T c8_rhb_x;
  real_T c8_lm_a;
  real_T c8_kn_b;
  real_T c8_on_y;
  real_T c8_shb_x;
  real_T c8_thb_x;
  real_T c8_ln_b;
  real_T c8_pn_y;
  real_T c8_uhb_x;
  real_T c8_vhb_x;
  real_T c8_mm_a;
  real_T c8_mn_b;
  real_T c8_qn_y;
  real_T c8_whb_x;
  real_T c8_xhb_x;
  real_T c8_nm_a;
  real_T c8_nn_b;
  real_T c8_rn_y;
  real_T c8_yhb_x;
  real_T c8_aib_x;
  real_T c8_om_a;
  real_T c8_on_b;
  real_T c8_sn_y;
  real_T c8_bib_x;
  real_T c8_cib_x;
  real_T c8_pn_b;
  real_T c8_tn_y;
  real_T c8_dib_x;
  real_T c8_eib_x;
  real_T c8_pm_a;
  real_T c8_qn_b;
  real_T c8_un_y;
  real_T c8_fib_x;
  real_T c8_gib_x;
  real_T c8_qm_a;
  real_T c8_rn_b;
  real_T c8_vn_y;
  real_T c8_hib_x;
  real_T c8_iib_x;
  real_T c8_rm_a;
  real_T c8_sn_b;
  real_T c8_wn_y;
  real_T c8_jib_x;
  real_T c8_kib_x;
  real_T c8_tn_b;
  real_T c8_xn_y;
  real_T c8_lib_x;
  real_T c8_mib_x;
  real_T c8_sm_a;
  real_T c8_un_b;
  real_T c8_yn_y;
  real_T c8_nib_x;
  real_T c8_oib_x;
  real_T c8_tm_a;
  real_T c8_vn_b;
  real_T c8_ao_y;
  real_T c8_pib_x;
  real_T c8_qib_x;
  real_T c8_um_a;
  real_T c8_wn_b;
  real_T c8_bo_y;
  real_T c8_rib_x;
  real_T c8_sib_x;
  real_T c8_xn_b;
  real_T c8_co_y;
  real_T c8_tib_x;
  real_T c8_uib_x;
  real_T c8_vm_a;
  real_T c8_yn_b;
  real_T c8_do_y;
  real_T c8_vib_x;
  real_T c8_wib_x;
  real_T c8_wm_a;
  real_T c8_ao_b;
  real_T c8_eo_y;
  real_T c8_xib_x;
  real_T c8_yib_x;
  real_T c8_xm_a;
  real_T c8_bo_b;
  real_T c8_fo_y;
  real_T c8_ajb_x;
  real_T c8_bjb_x;
  real_T c8_co_b;
  real_T c8_go_y;
  real_T c8_cjb_x;
  real_T c8_djb_x;
  real_T c8_ym_a;
  real_T c8_do_b;
  real_T c8_ho_y;
  real_T c8_ejb_x;
  real_T c8_fjb_x;
  real_T c8_an_a;
  real_T c8_eo_b;
  real_T c8_io_y;
  real_T c8_gjb_x;
  real_T c8_hjb_x;
  real_T c8_bn_a;
  real_T c8_fo_b;
  real_T c8_jo_y;
  real_T c8_ijb_x;
  real_T c8_jjb_x;
  real_T c8_go_b;
  real_T c8_ko_y;
  real_T c8_kjb_x;
  real_T c8_ljb_x;
  real_T c8_cn_a;
  real_T c8_ho_b;
  real_T c8_lo_y;
  real_T c8_mjb_x;
  real_T c8_njb_x;
  real_T c8_dn_a;
  real_T c8_io_b;
  real_T c8_mo_y;
  real_T c8_ojb_x;
  real_T c8_pjb_x;
  real_T c8_en_a;
  real_T c8_jo_b;
  real_T c8_no_y;
  real_T c8_qjb_x;
  real_T c8_rjb_x;
  real_T c8_ko_b;
  real_T c8_oo_y;
  real_T c8_sjb_x;
  real_T c8_tjb_x;
  real_T c8_fn_a;
  real_T c8_lo_b;
  real_T c8_po_y;
  real_T c8_ujb_x;
  real_T c8_vjb_x;
  real_T c8_gn_a;
  real_T c8_mo_b;
  real_T c8_qo_y;
  real_T c8_wjb_x;
  real_T c8_xjb_x;
  real_T c8_hn_a;
  real_T c8_no_b;
  real_T c8_ro_y;
  real_T c8_yjb_x;
  real_T c8_akb_x;
  real_T c8_bkb_x;
  real_T c8_ckb_x;
  real_T c8_in_a;
  real_T c8_oo_b;
  real_T c8_so_y;
  real_T c8_dkb_x;
  real_T c8_ekb_x;
  real_T c8_jn_a;
  real_T c8_po_b;
  real_T c8_to_y;
  real_T c8_fkb_x;
  real_T c8_gkb_x;
  real_T c8_kn_a;
  real_T c8_qo_b;
  real_T c8_uo_y;
  real_T c8_hkb_x;
  real_T c8_ikb_x;
  real_T c8_jkb_x;
  real_T c8_kkb_x;
  real_T c8_ln_a;
  real_T c8_ro_b;
  real_T c8_vo_y;
  real_T c8_lkb_x;
  real_T c8_mkb_x;
  real_T c8_mn_a;
  real_T c8_so_b;
  real_T c8_wo_y;
  real_T c8_nkb_x;
  real_T c8_okb_x;
  real_T c8_nn_a;
  real_T c8_to_b;
  real_T c8_xo_y;
  real_T c8_pkb_x;
  real_T c8_qkb_x;
  real_T c8_rkb_x;
  real_T c8_skb_x;
  real_T c8_on_a;
  real_T c8_uo_b;
  real_T c8_yo_y;
  real_T c8_tkb_x;
  real_T c8_ukb_x;
  real_T c8_pn_a;
  real_T c8_vo_b;
  real_T c8_ap_y;
  real_T c8_vkb_x;
  real_T c8_wkb_x;
  real_T c8_qn_a;
  real_T c8_wo_b;
  real_T c8_bp_y;
  real_T c8_xkb_x;
  real_T c8_ykb_x;
  real_T c8_alb_x;
  real_T c8_blb_x;
  real_T c8_rn_a;
  real_T c8_xo_b;
  real_T c8_cp_y;
  real_T c8_clb_x;
  real_T c8_dlb_x;
  real_T c8_sn_a;
  real_T c8_yo_b;
  real_T c8_dp_y;
  real_T c8_elb_x;
  real_T c8_flb_x;
  real_T c8_tn_a;
  real_T c8_ap_b;
  real_T c8_ep_y;
  real_T c8_glb_x;
  real_T c8_hlb_x;
  real_T c8_ilb_x;
  real_T c8_jlb_x;
  real_T c8_un_a;
  real_T c8_bp_b;
  real_T c8_fp_y;
  real_T c8_klb_x;
  real_T c8_llb_x;
  real_T c8_vn_a;
  real_T c8_cp_b;
  real_T c8_gp_y;
  real_T c8_mlb_x;
  real_T c8_nlb_x;
  real_T c8_wn_a;
  real_T c8_dp_b;
  real_T c8_hp_y;
  real_T c8_olb_x;
  real_T c8_plb_x;
  real_T c8_qlb_x;
  real_T c8_rlb_x;
  real_T c8_xn_a;
  real_T c8_ep_b;
  real_T c8_ip_y;
  real_T c8_slb_x;
  real_T c8_tlb_x;
  real_T c8_yn_a;
  real_T c8_fp_b;
  real_T c8_jp_y;
  real_T c8_ulb_x;
  real_T c8_vlb_x;
  real_T c8_ao_a;
  real_T c8_gp_b;
  real_T c8_kp_y;
  real_T c8_wlb_x;
  real_T c8_xlb_x;
  real_T c8_ylb_x;
  real_T c8_amb_x;
  real_T c8_bo_a;
  real_T c8_hp_b;
  real_T c8_lp_y;
  real_T c8_bmb_x;
  real_T c8_cmb_x;
  real_T c8_co_a;
  real_T c8_ip_b;
  real_T c8_mp_y;
  real_T c8_dmb_x;
  real_T c8_emb_x;
  real_T c8_do_a;
  real_T c8_jp_b;
  real_T c8_np_y;
  real_T c8_fmb_x;
  real_T c8_gmb_x;
  real_T c8_hmb_x;
  real_T c8_imb_x;
  real_T c8_eo_a;
  real_T c8_kp_b;
  real_T c8_op_y;
  real_T c8_jmb_x;
  real_T c8_kmb_x;
  real_T c8_fo_a;
  real_T c8_lp_b;
  real_T c8_pp_y;
  real_T c8_lmb_x;
  real_T c8_mmb_x;
  real_T c8_go_a;
  real_T c8_mp_b;
  real_T c8_qp_y;
  real_T c8_nmb_x;
  real_T c8_omb_x;
  real_T c8_pmb_x;
  real_T c8_qmb_x;
  real_T c8_ho_a;
  real_T c8_np_b;
  real_T c8_rp_y;
  real_T c8_rmb_x;
  real_T c8_smb_x;
  real_T c8_io_a;
  real_T c8_op_b;
  real_T c8_sp_y;
  real_T c8_tmb_x;
  real_T c8_umb_x;
  real_T c8_jo_a;
  real_T c8_pp_b;
  real_T c8_tp_y;
  real_T c8_vmb_x;
  real_T c8_wmb_x;
  real_T c8_xmb_x;
  real_T c8_ymb_x;
  real_T c8_ko_a;
  real_T c8_qp_b;
  real_T c8_up_y;
  real_T c8_anb_x;
  real_T c8_bnb_x;
  real_T c8_lo_a;
  real_T c8_rp_b;
  real_T c8_vp_y;
  real_T c8_cnb_x;
  real_T c8_dnb_x;
  real_T c8_mo_a;
  real_T c8_sp_b;
  real_T c8_wp_y;
  real_T c8_enb_x;
  real_T c8_fnb_x;
  real_T c8_gnb_x;
  real_T c8_hnb_x;
  real_T c8_no_a;
  real_T c8_tp_b;
  real_T c8_xp_y;
  real_T c8_inb_x;
  real_T c8_jnb_x;
  real_T c8_oo_a;
  real_T c8_up_b;
  real_T c8_yp_y;
  real_T c8_knb_x;
  real_T c8_lnb_x;
  real_T c8_po_a;
  real_T c8_vp_b;
  real_T c8_aq_y;
  real_T c8_mnb_x;
  real_T c8_nnb_x;
  real_T c8_onb_x;
  real_T c8_pnb_x;
  real_T c8_qo_a;
  real_T c8_wp_b;
  real_T c8_bq_y;
  real_T c8_qnb_x;
  real_T c8_rnb_x;
  real_T c8_ro_a;
  real_T c8_xp_b;
  real_T c8_cq_y;
  real_T c8_snb_x;
  real_T c8_tnb_x;
  real_T c8_so_a;
  real_T c8_yp_b;
  real_T c8_dq_y;
  real_T c8_unb_x;
  real_T c8_vnb_x;
  real_T c8_wnb_x;
  real_T c8_xnb_x;
  real_T c8_to_a;
  real_T c8_aq_b;
  real_T c8_eq_y;
  real_T c8_ynb_x;
  real_T c8_aob_x;
  real_T c8_uo_a;
  real_T c8_bq_b;
  real_T c8_fq_y;
  real_T c8_bob_x;
  real_T c8_cob_x;
  real_T c8_vo_a;
  real_T c8_cq_b;
  real_T c8_gq_y;
  real_T c8_dob_x;
  real_T c8_eob_x;
  real_T c8_fob_x;
  real_T c8_gob_x;
  real_T c8_wo_a;
  real_T c8_dq_b;
  real_T c8_hq_y;
  real_T c8_hob_x;
  real_T c8_iob_x;
  real_T c8_xo_a;
  real_T c8_eq_b;
  real_T c8_iq_y;
  real_T c8_job_x;
  real_T c8_kob_x;
  real_T c8_yo_a;
  real_T c8_fq_b;
  real_T c8_jq_y;
  real_T c8_lob_x;
  real_T c8_mob_x;
  real_T c8_nob_x;
  real_T c8_oob_x;
  real_T c8_ap_a;
  real_T c8_gq_b;
  real_T c8_kq_y;
  real_T c8_pob_x;
  real_T c8_qob_x;
  real_T c8_bp_a;
  real_T c8_hq_b;
  real_T c8_lq_y;
  real_T c8_rob_x;
  real_T c8_sob_x;
  real_T c8_cp_a;
  real_T c8_iq_b;
  real_T c8_mq_y;
  real_T c8_tob_x;
  real_T c8_uob_x;
  real_T c8_vob_x;
  real_T c8_wob_x;
  real_T c8_dp_a;
  real_T c8_jq_b;
  real_T c8_nq_y;
  real_T c8_xob_x;
  real_T c8_yob_x;
  real_T c8_ep_a;
  real_T c8_kq_b;
  real_T c8_oq_y;
  real_T c8_apb_x;
  real_T c8_bpb_x;
  real_T c8_fp_a;
  real_T c8_lq_b;
  real_T c8_pq_y;
  real_T c8_cpb_x;
  real_T c8_dpb_x;
  real_T c8_epb_x;
  real_T c8_fpb_x;
  real_T c8_gp_a;
  real_T c8_mq_b;
  real_T c8_qq_y;
  real_T c8_gpb_x;
  real_T c8_hpb_x;
  real_T c8_hp_a;
  real_T c8_nq_b;
  real_T c8_rq_y;
  real_T c8_ipb_x;
  real_T c8_jpb_x;
  real_T c8_ip_a;
  real_T c8_oq_b;
  real_T c8_sq_y;
  real_T c8_kpb_x;
  real_T c8_lpb_x;
  real_T c8_mpb_x;
  real_T c8_npb_x;
  real_T c8_jp_a;
  real_T c8_pq_b;
  real_T c8_tq_y;
  real_T c8_opb_x;
  real_T c8_ppb_x;
  real_T c8_kp_a;
  real_T c8_qq_b;
  real_T c8_uq_y;
  real_T c8_qpb_x;
  real_T c8_rpb_x;
  real_T c8_lp_a;
  real_T c8_rq_b;
  real_T c8_vq_y;
  real_T c8_spb_x;
  real_T c8_tpb_x;
  real_T c8_upb_x;
  real_T c8_vpb_x;
  real_T c8_mp_a;
  real_T c8_sq_b;
  real_T c8_wq_y;
  real_T c8_wpb_x;
  real_T c8_xpb_x;
  real_T c8_np_a;
  real_T c8_tq_b;
  real_T c8_xq_y;
  real_T c8_ypb_x;
  real_T c8_aqb_x;
  real_T c8_op_a;
  real_T c8_uq_b;
  real_T c8_yq_y;
  real_T c8_bqb_x;
  real_T c8_cqb_x;
  real_T c8_dqb_x;
  real_T c8_eqb_x;
  real_T c8_pp_a;
  real_T c8_vq_b;
  real_T c8_ar_y;
  real_T c8_fqb_x;
  real_T c8_gqb_x;
  real_T c8_qp_a;
  real_T c8_wq_b;
  real_T c8_br_y;
  real_T c8_hqb_x;
  real_T c8_iqb_x;
  real_T c8_rp_a;
  real_T c8_xq_b;
  real_T c8_cr_y;
  real_T c8_jqb_x;
  real_T c8_kqb_x;
  real_T c8_lqb_x;
  real_T c8_mqb_x;
  real_T c8_sp_a;
  real_T c8_yq_b;
  real_T c8_dr_y;
  real_T c8_nqb_x;
  real_T c8_oqb_x;
  real_T c8_tp_a;
  real_T c8_ar_b;
  real_T c8_er_y;
  real_T c8_pqb_x;
  real_T c8_qqb_x;
  real_T c8_up_a;
  real_T c8_br_b;
  real_T c8_fr_y;
  real_T c8_rqb_x;
  real_T c8_sqb_x;
  real_T c8_tqb_x;
  real_T c8_uqb_x;
  real_T c8_vp_a;
  real_T c8_cr_b;
  real_T c8_gr_y;
  real_T c8_vqb_x;
  real_T c8_wqb_x;
  real_T c8_wp_a;
  real_T c8_dr_b;
  real_T c8_hr_y;
  real_T c8_xqb_x;
  real_T c8_yqb_x;
  real_T c8_xp_a;
  real_T c8_er_b;
  real_T c8_ir_y;
  real_T c8_arb_x;
  real_T c8_brb_x;
  real_T c8_fr_b;
  real_T c8_jr_y;
  real_T c8_crb_x;
  real_T c8_drb_x;
  real_T c8_yp_a;
  real_T c8_gr_b;
  real_T c8_kr_y;
  real_T c8_erb_x;
  real_T c8_frb_x;
  real_T c8_aq_a;
  real_T c8_hr_b;
  real_T c8_lr_y;
  real_T c8_grb_x;
  real_T c8_hrb_x;
  real_T c8_bq_a;
  real_T c8_ir_b;
  real_T c8_mr_y;
  real_T c8_irb_x;
  real_T c8_jrb_x;
  real_T c8_jr_b;
  real_T c8_nr_y;
  real_T c8_krb_x;
  real_T c8_lrb_x;
  real_T c8_cq_a;
  real_T c8_kr_b;
  real_T c8_or_y;
  real_T c8_mrb_x;
  real_T c8_nrb_x;
  real_T c8_dq_a;
  real_T c8_lr_b;
  real_T c8_pr_y;
  real_T c8_orb_x;
  real_T c8_prb_x;
  real_T c8_eq_a;
  real_T c8_mr_b;
  real_T c8_qr_y;
  real_T c8_qrb_x;
  real_T c8_rrb_x;
  real_T c8_nr_b;
  real_T c8_rr_y;
  real_T c8_srb_x;
  real_T c8_trb_x;
  real_T c8_fq_a;
  real_T c8_or_b;
  real_T c8_sr_y;
  real_T c8_urb_x;
  real_T c8_vrb_x;
  real_T c8_gq_a;
  real_T c8_pr_b;
  real_T c8_tr_y;
  real_T c8_wrb_x;
  real_T c8_xrb_x;
  real_T c8_hq_a;
  real_T c8_qr_b;
  real_T c8_ur_y;
  real_T c8_yrb_x;
  real_T c8_asb_x;
  real_T c8_rr_b;
  real_T c8_vr_y;
  real_T c8_bsb_x;
  real_T c8_csb_x;
  real_T c8_iq_a;
  real_T c8_sr_b;
  real_T c8_wr_y;
  real_T c8_dsb_x;
  real_T c8_esb_x;
  real_T c8_jq_a;
  real_T c8_tr_b;
  real_T c8_xr_y;
  real_T c8_fsb_x;
  real_T c8_gsb_x;
  real_T c8_kq_a;
  real_T c8_ur_b;
  real_T c8_yr_y;
  real_T c8_hsb_x;
  real_T c8_isb_x;
  real_T c8_vr_b;
  real_T c8_as_y;
  real_T c8_jsb_x;
  real_T c8_ksb_x;
  real_T c8_lq_a;
  real_T c8_wr_b;
  real_T c8_bs_y;
  real_T c8_lsb_x;
  real_T c8_msb_x;
  real_T c8_mq_a;
  real_T c8_xr_b;
  real_T c8_cs_y;
  real_T c8_nsb_x;
  real_T c8_osb_x;
  real_T c8_nq_a;
  real_T c8_yr_b;
  real_T c8_ds_y;
  real_T c8_psb_x;
  real_T c8_qsb_x;
  real_T c8_as_b;
  real_T c8_es_y;
  real_T c8_rsb_x;
  real_T c8_ssb_x;
  real_T c8_oq_a;
  real_T c8_bs_b;
  real_T c8_fs_y;
  real_T c8_tsb_x;
  real_T c8_usb_x;
  real_T c8_pq_a;
  real_T c8_cs_b;
  real_T c8_gs_y;
  real_T c8_vsb_x;
  real_T c8_wsb_x;
  real_T c8_qq_a;
  real_T c8_ds_b;
  real_T c8_hs_y;
  real_T c8_xsb_x;
  real_T c8_ysb_x;
  real_T c8_es_b;
  real_T c8_is_y;
  real_T c8_atb_x;
  real_T c8_btb_x;
  real_T c8_rq_a;
  real_T c8_fs_b;
  real_T c8_js_y;
  real_T c8_ctb_x;
  real_T c8_dtb_x;
  real_T c8_sq_a;
  real_T c8_gs_b;
  real_T c8_ks_y;
  real_T c8_etb_x;
  real_T c8_ftb_x;
  real_T c8_tq_a;
  real_T c8_hs_b;
  real_T c8_ls_y;
  real_T c8_gtb_x;
  real_T c8_htb_x;
  real_T c8_is_b;
  real_T c8_ms_y;
  real_T c8_itb_x;
  real_T c8_jtb_x;
  real_T c8_uq_a;
  real_T c8_js_b;
  real_T c8_ns_y;
  real_T c8_ktb_x;
  real_T c8_ltb_x;
  real_T c8_vq_a;
  real_T c8_ks_b;
  real_T c8_os_y;
  real_T c8_mtb_x;
  real_T c8_ntb_x;
  real_T c8_wq_a;
  real_T c8_ls_b;
  real_T c8_ps_y;
  real_T c8_ms_b;
  real_T c8_qs_y;
  real_T c8_c_A;
  real_T c8_b_B;
  real_T c8_otb_x;
  real_T c8_rs_y;
  real_T c8_ptb_x;
  real_T c8_ss_y;
  real_T c8_ts_y;
  int32_T c8_i23;
  real_T c8_b_Ja[6];
  real_T c8_dv2[6];
  int32_T c8_i24;
  real_T c8_xq_a;
  int32_T c8_i25;
  real_T c8_ns_b[3];
  int32_T c8_i26;
  int32_T c8_i27;
  int32_T c8_i28;
  real_T c8_os_b[2];
  int32_T c8_i29;
  int32_T c8_i30;
  int32_T c8_i31;
  int32_T c8_i32;
  int32_T c8_i33;
  int32_T c8_i34;
  int32_T c8_i35;
  int32_T c8_i36;
  int32_T c8_i37;
  int32_T c8_i38;
  int32_T c8_i39;
  real_T c8_b_Jstar[6];
  real_T c8_dv3[2];
  int32_T c8_i40;
  real_T c8_d_A;
  real_T c8_qtb_x;
  real_T c8_rtb_x;
  real_T c8_us_y;
  real_T c8_yq_a;
  int32_T c8_i41;
  int32_T c8_i42;
  int32_T c8_i43;
  int32_T c8_i44;
  int32_T c8_i45;
  int32_T c8_i46;
  int32_T c8_i47;
  int32_T c8_i48;
  int32_T c8_i49;
  int32_T c8_i50;
  int32_T c8_i51;
  real_T c8_ar_a;
  int32_T c8_i52;
  static real_T c8_ps_b[4] = { 1.0, 0.0, 0.0, 1.0 };

  real_T c8_vs_y[4];
  int32_T c8_i53;
  int32_T c8_i54;
  int32_T c8_i55;
  int32_T c8_i56;
  int32_T c8_i57;
  real_T c8_ws_y[4];
  int32_T c8_i58;
  int32_T c8_i59;
  int32_T c8_i60;
  int32_T c8_i61;
  real_T c8_xs_y[6];
  int32_T c8_i62;
  int32_T c8_i63;
  int32_T c8_i64;
  int32_T c8_i65;
  int32_T c8_i66;
  int32_T c8_i67;
  int32_T c8_i68;
  int32_T c8_i69;
  int32_T c8_i70;
  real_T *c8_b_EE;
  real_T *c8_b_W;
  real_T (*c8_b_qd_req)[3];
  real_T (*c8_b_qd_reqW)[3];
  real_T (*c8_b_qqd)[9];
  real_T (*c8_b_Ve)[2];
  c8_b_EE = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c8_b_W = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_b_qd_reqW = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c8_b_qd_req = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c8_b_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
  c8_b_Ve = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  c8_hoistedGlobal = chartInstance->c8_l;
  c8_b_hoistedGlobal = chartInstance->c8_a;
  c8_c_hoistedGlobal = *c8_b_EE;
  for (c8_i8 = 0; c8_i8 < 2; c8_i8++) {
    c8_Ve[c8_i8] = (*c8_b_Ve)[c8_i8];
  }

  for (c8_i9 = 0; c8_i9 < 9; c8_i9++) {
    c8_qqd[c8_i9] = (*c8_b_qqd)[c8_i9];
  }

  c8_b_l = c8_hoistedGlobal;
  c8_b_a = c8_b_hoistedGlobal;
  c8_EE = c8_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c8_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_q, 0U, c8_g_sf_marshallOut,
    c8_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_Ja, 1U, c8_e_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_DDD, 2U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_DW, 3U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_Jinv, 4U, c8_f_sf_marshallOut,
    c8_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_qa, 5U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_EEv, 6U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_Jstar, 7U, c8_e_sf_marshallOut,
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_A, 8U, c8_d_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_lambmax, 9U, c8_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_Sigma, 10U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_lamb2, 11U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 12U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 13U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_Ve, 14U, c8_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_qqd, 15U, c8_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_l, 16U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_a, 17U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c8_EE, 18U, c8_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_qd_req, 19U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_qd_reqW, 20U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_W, 21U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 8);
  c8_q[0] = c8_qqd[6];
  c8_q[1] = c8_qqd[7];
  c8_q[2] = c8_qqd[8];
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 12);
  c8_x = c8_q[0];
  c8_b_x = c8_x;
  c8_b_x = muDoubleScalarSin(c8_b_x);
  c8_c_a = c8_b_l;
  c8_b = c8_b_x;
  c8_y = c8_c_a * c8_b;
  c8_c_x = c8_q[0] + c8_q[1];
  c8_d_x = c8_c_x;
  c8_d_x = muDoubleScalarSin(c8_d_x);
  c8_d_a = c8_b_l;
  c8_b_b = c8_d_x;
  c8_b_y = c8_d_a * c8_b_b;
  c8_e_x = (c8_q[0] + c8_q[1]) + c8_q[2];
  c8_f_x = c8_e_x;
  c8_f_x = muDoubleScalarSin(c8_f_x);
  c8_e_a = c8_b_l;
  c8_c_b = c8_f_x;
  c8_c_y = c8_e_a * c8_c_b;
  c8_g_x = c8_q[0] + c8_q[1];
  c8_h_x = c8_g_x;
  c8_h_x = muDoubleScalarSin(c8_h_x);
  c8_f_a = c8_b_l;
  c8_d_b = c8_h_x;
  c8_d_y = c8_f_a * c8_d_b;
  c8_i_x = (c8_q[0] + c8_q[1]) + c8_q[2];
  c8_j_x = c8_i_x;
  c8_j_x = muDoubleScalarSin(c8_j_x);
  c8_g_a = c8_b_l;
  c8_e_b = c8_j_x;
  c8_e_y = c8_g_a * c8_e_b;
  c8_k_x = (c8_q[0] + c8_q[1]) + c8_q[2];
  c8_l_x = c8_k_x;
  c8_l_x = muDoubleScalarSin(c8_l_x);
  c8_h_a = -c8_b_l;
  c8_f_b = c8_l_x;
  c8_f_y = c8_h_a * c8_f_b;
  c8_m_x = c8_q[0];
  c8_n_x = c8_m_x;
  c8_n_x = muDoubleScalarCos(c8_n_x);
  c8_i_a = c8_b_l;
  c8_g_b = c8_n_x;
  c8_g_y = c8_i_a * c8_g_b;
  c8_o_x = c8_q[0] + c8_q[1];
  c8_p_x = c8_o_x;
  c8_p_x = muDoubleScalarCos(c8_p_x);
  c8_j_a = c8_b_l;
  c8_h_b = c8_p_x;
  c8_h_y = c8_j_a * c8_h_b;
  c8_q_x = (c8_q[0] + c8_q[1]) + c8_q[2];
  c8_r_x = c8_q_x;
  c8_r_x = muDoubleScalarCos(c8_r_x);
  c8_k_a = c8_b_l;
  c8_i_b = c8_r_x;
  c8_i_y = c8_k_a * c8_i_b;
  c8_s_x = c8_q[0] + c8_q[1];
  c8_t_x = c8_s_x;
  c8_t_x = muDoubleScalarCos(c8_t_x);
  c8_l_a = c8_b_l;
  c8_j_b = c8_t_x;
  c8_j_y = c8_l_a * c8_j_b;
  c8_u_x = (c8_q[0] + c8_q[1]) + c8_q[2];
  c8_v_x = c8_u_x;
  c8_v_x = muDoubleScalarCos(c8_v_x);
  c8_m_a = c8_b_l;
  c8_k_b = c8_v_x;
  c8_k_y = c8_m_a * c8_k_b;
  c8_w_x = (c8_q[0] + c8_q[1]) + c8_q[2];
  c8_x_x = c8_w_x;
  c8_x_x = muDoubleScalarCos(c8_x_x);
  c8_n_a = c8_b_l;
  c8_l_b = c8_x_x;
  c8_l_y = c8_n_a * c8_l_b;
  c8_Ja[0] = -((c8_y + c8_b_y) + c8_c_y);
  c8_Ja[2] = -(c8_d_y + c8_e_y);
  c8_Ja[4] = c8_f_y;
  c8_Ja[1] = (c8_g_y + c8_h_y) + c8_i_y;
  c8_Ja[3] = c8_j_y + c8_k_y;
  c8_Ja[5] = c8_l_y;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 15);
  for (c8_i10 = 0; c8_i10 < 6; c8_i10++) {
    c8_o_a[c8_i10] = c8_Ja[c8_i10];
  }

  c8_i11 = 0;
  for (c8_i12 = 0; c8_i12 < 2; c8_i12++) {
    c8_i13 = 0;
    for (c8_i14 = 0; c8_i14 < 3; c8_i14++) {
      c8_m_b[c8_i14 + c8_i11] = c8_Ja[c8_i13 + c8_i12];
      c8_i13 += 2;
    }

    c8_i11 += 3;
  }

  c8_eml_scalar_eg(chartInstance);
  c8_eml_scalar_eg(chartInstance);
  for (c8_i15 = 0; c8_i15 < 2; c8_i15++) {
    c8_i16 = 0;
    c8_i17 = 0;
    for (c8_i18 = 0; c8_i18 < 2; c8_i18++) {
      c8_m_y[c8_i16 + c8_i15] = 0.0;
      c8_i19 = 0;
      for (c8_i20 = 0; c8_i20 < 3; c8_i20++) {
        c8_m_y[c8_i16 + c8_i15] += c8_o_a[c8_i19 + c8_i15] * c8_m_b[c8_i20 +
          c8_i17];
        c8_i19 += 2;
      }

      c8_i16 += 2;
      c8_i17 += 3;
    }
  }

  for (c8_i21 = 0; c8_i21 < 4; c8_i21++) {
    c8_n_y[c8_i21] = c8_m_y[c8_i21];
  }

  c8_DDD = c8_det(chartInstance, c8_n_y);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 18);
  c8_W = c8_DDD;
  c8_b_sqrt(chartInstance, &c8_W);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 19);
  if (CV_EML_IF(0, 1, 0, c8_q[1] == 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 21);
    for (c8_i22 = 0; c8_i22 < 3; c8_i22++) {
      c8_DW[c8_i22] = 0.0;
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 24);
    c8_y_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ab_x = c8_y_x;
    c8_ab_x = muDoubleScalarCos(c8_ab_x);
    c8_bb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_cb_x = c8_bb_x;
    c8_cb_x = muDoubleScalarCos(c8_cb_x);
    c8_p_a = c8_ab_x;
    c8_n_b = c8_cb_x;
    c8_o_y = c8_p_a * c8_n_b;
    c8_db_x = c8_q[0] + c8_q[1];
    c8_eb_x = c8_db_x;
    c8_eb_x = muDoubleScalarSin(c8_eb_x);
    c8_q_a = c8_o_y;
    c8_o_b = c8_eb_x;
    c8_p_y = c8_q_a * c8_o_b;
    c8_fb_x = c8_q[0];
    c8_gb_x = c8_fb_x;
    c8_gb_x = muDoubleScalarCos(c8_gb_x);
    c8_r_a = c8_p_y;
    c8_p_b = c8_gb_x;
    c8_q_y = c8_r_a * c8_p_b;
    c8_hb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ib_x = c8_hb_x;
    c8_ib_x = muDoubleScalarCos(c8_ib_x);
    c8_jb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_kb_x = c8_jb_x;
    c8_kb_x = muDoubleScalarSin(c8_kb_x);
    c8_s_a = c8_ib_x;
    c8_q_b = c8_kb_x;
    c8_r_y = c8_s_a * c8_q_b;
    c8_lb_x = c8_q[0] + c8_q[1];
    c8_mb_x = c8_lb_x;
    c8_mb_x = muDoubleScalarCos(c8_mb_x);
    c8_t_a = c8_r_y;
    c8_r_b = c8_mb_x;
    c8_s_y = c8_t_a * c8_r_b;
    c8_nb_x = c8_q[0];
    c8_ob_x = c8_nb_x;
    c8_ob_x = muDoubleScalarCos(c8_ob_x);
    c8_u_a = c8_s_y;
    c8_s_b = c8_ob_x;
    c8_t_y = c8_u_a * c8_s_b;
    c8_pb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_qb_x = c8_pb_x;
    c8_qb_x = muDoubleScalarCos(c8_qb_x);
    c8_rb_x = c8_q[0];
    c8_sb_x = c8_rb_x;
    c8_sb_x = muDoubleScalarSin(c8_sb_x);
    c8_v_a = c8_qb_x;
    c8_t_b = c8_sb_x;
    c8_u_y = c8_v_a * c8_t_b;
    c8_tb_x = c8_q[0] + c8_q[1];
    c8_ub_x = c8_tb_x;
    c8_ub_x = muDoubleScalarSin(c8_ub_x);
    c8_w_a = c8_u_y;
    c8_u_b = c8_ub_x;
    c8_v_y = c8_w_a * c8_u_b;
    c8_vb_x = c8_q[0];
    c8_wb_x = c8_vb_x;
    c8_wb_x = muDoubleScalarSin(c8_wb_x);
    c8_x_a = c8_v_y;
    c8_v_b = c8_wb_x;
    c8_w_y = c8_x_a * c8_v_b;
    c8_xb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_yb_x = c8_xb_x;
    c8_yb_x = muDoubleScalarSin(c8_yb_x);
    c8_ac_x = c8_q[0];
    c8_bc_x = c8_ac_x;
    c8_bc_x = muDoubleScalarCos(c8_bc_x);
    c8_y_a = c8_yb_x;
    c8_w_b = c8_bc_x;
    c8_x_y = c8_y_a * c8_w_b;
    c8_cc_x = c8_q[0] + c8_q[1];
    c8_dc_x = c8_cc_x;
    c8_dc_x = muDoubleScalarSin(c8_dc_x);
    c8_ab_a = c8_x_y;
    c8_x_b = c8_dc_x;
    c8_y_y = c8_ab_a * c8_x_b;
    c8_ec_x = c8_q[0];
    c8_fc_x = c8_ec_x;
    c8_fc_x = muDoubleScalarSin(c8_fc_x);
    c8_bb_a = c8_y_y;
    c8_y_b = c8_fc_x;
    c8_ab_y = c8_bb_a * c8_y_b;
    c8_gc_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_hc_x = c8_gc_x;
    c8_hc_x = muDoubleScalarSin(c8_hc_x);
    c8_ic_x = c8_q[0];
    c8_jc_x = c8_ic_x;
    c8_jc_x = muDoubleScalarSin(c8_jc_x);
    c8_cb_a = c8_hc_x;
    c8_ab_b = c8_jc_x;
    c8_bb_y = c8_cb_a * c8_ab_b;
    c8_kc_x = c8_q[0] + c8_q[1];
    c8_lc_x = c8_kc_x;
    c8_lc_x = muDoubleScalarCos(c8_lc_x);
    c8_db_a = c8_bb_y;
    c8_bb_b = c8_lc_x;
    c8_cb_y = c8_db_a * c8_bb_b;
    c8_mc_x = c8_q[0];
    c8_nc_x = c8_mc_x;
    c8_nc_x = muDoubleScalarSin(c8_nc_x);
    c8_eb_a = c8_cb_y;
    c8_cb_b = c8_nc_x;
    c8_db_y = c8_eb_a * c8_cb_b;
    c8_oc_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_pc_x = c8_oc_x;
    c8_pc_x = muDoubleScalarSin(c8_pc_x);
    c8_qc_x = c8_q[0];
    c8_rc_x = c8_qc_x;
    c8_rc_x = muDoubleScalarSin(c8_rc_x);
    c8_fb_a = c8_pc_x;
    c8_db_b = c8_rc_x;
    c8_eb_y = c8_fb_a * c8_db_b;
    c8_sc_x = c8_q[0] + c8_q[1];
    c8_tc_x = c8_sc_x;
    c8_tc_x = muDoubleScalarSin(c8_tc_x);
    c8_gb_a = c8_eb_y;
    c8_eb_b = c8_tc_x;
    c8_fb_y = c8_gb_a * c8_eb_b;
    c8_uc_x = c8_q[0];
    c8_vc_x = c8_uc_x;
    c8_vc_x = muDoubleScalarCos(c8_vc_x);
    c8_hb_a = c8_fb_y;
    c8_fb_b = c8_vc_x;
    c8_gb_y = c8_hb_a * c8_fb_b;
    c8_wc_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_xc_x = c8_wc_x;
    c8_xc_x = muDoubleScalarSin(c8_xc_x);
    c8_yc_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ad_x = c8_yc_x;
    c8_ad_x = muDoubleScalarCos(c8_ad_x);
    c8_ib_a = c8_xc_x;
    c8_gb_b = c8_ad_x;
    c8_hb_y = c8_ib_a * c8_gb_b;
    c8_bd_x = c8_q[0] + c8_q[1];
    c8_cd_x = c8_bd_x;
    c8_cd_x = muDoubleScalarSin(c8_cd_x);
    c8_jb_a = c8_hb_y;
    c8_hb_b = c8_cd_x;
    c8_ib_y = c8_jb_a * c8_hb_b;
    c8_dd_x = c8_q[0];
    c8_ed_x = c8_dd_x;
    c8_ed_x = muDoubleScalarSin(c8_ed_x);
    c8_kb_a = c8_ib_y;
    c8_ib_b = c8_ed_x;
    c8_jb_y = c8_kb_a * c8_ib_b;
    c8_fd_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_gd_x = c8_fd_x;
    c8_gd_x = muDoubleScalarSin(c8_gd_x);
    c8_hd_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_id_x = c8_hd_x;
    c8_id_x = muDoubleScalarSin(c8_id_x);
    c8_lb_a = c8_gd_x;
    c8_jb_b = c8_id_x;
    c8_kb_y = c8_lb_a * c8_jb_b;
    c8_jd_x = c8_q[0] + c8_q[1];
    c8_kd_x = c8_jd_x;
    c8_kd_x = muDoubleScalarCos(c8_kd_x);
    c8_mb_a = c8_kb_y;
    c8_kb_b = c8_kd_x;
    c8_lb_y = c8_mb_a * c8_kb_b;
    c8_ld_x = c8_q[0];
    c8_md_x = c8_ld_x;
    c8_md_x = muDoubleScalarSin(c8_md_x);
    c8_nb_a = c8_lb_y;
    c8_lb_b = c8_md_x;
    c8_mb_y = c8_nb_a * c8_lb_b;
    c8_nd_x = c8_q[0];
    c8_od_x = c8_nd_x;
    c8_od_x = muDoubleScalarCos(c8_od_x);
    c8_pd_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_qd_x = c8_pd_x;
    c8_qd_x = muDoubleScalarCos(c8_qd_x);
    c8_ob_a = c8_od_x;
    c8_mb_b = c8_qd_x;
    c8_nb_y = c8_ob_a * c8_mb_b;
    c8_rd_x = c8_q[0] + c8_q[1];
    c8_sd_x = c8_rd_x;
    c8_sd_x = muDoubleScalarCos(c8_sd_x);
    c8_pb_a = c8_nb_y;
    c8_nb_b = c8_sd_x;
    c8_ob_y = c8_pb_a * c8_nb_b;
    c8_td_x = c8_q[0];
    c8_ud_x = c8_td_x;
    c8_ud_x = muDoubleScalarSin(c8_ud_x);
    c8_qb_a = c8_ob_y;
    c8_ob_b = c8_ud_x;
    c8_pb_y = c8_qb_a * c8_ob_b;
    c8_vd_x = c8_q[0];
    c8_wd_x = c8_vd_x;
    c8_wd_x = muDoubleScalarCos(c8_wd_x);
    c8_xd_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_yd_x = c8_xd_x;
    c8_yd_x = muDoubleScalarCos(c8_yd_x);
    c8_rb_a = c8_wd_x;
    c8_pb_b = c8_yd_x;
    c8_qb_y = c8_rb_a * c8_pb_b;
    c8_ae_x = c8_q[0] + c8_q[1];
    c8_be_x = c8_ae_x;
    c8_be_x = muDoubleScalarSin(c8_be_x);
    c8_sb_a = c8_qb_y;
    c8_qb_b = c8_be_x;
    c8_rb_y = c8_sb_a * c8_qb_b;
    c8_ce_x = c8_q[0];
    c8_de_x = c8_ce_x;
    c8_de_x = muDoubleScalarCos(c8_de_x);
    c8_tb_a = c8_rb_y;
    c8_rb_b = c8_de_x;
    c8_sb_y = c8_tb_a * c8_rb_b;
    c8_ee_x = c8_q[0];
    c8_fe_x = c8_ee_x;
    c8_fe_x = muDoubleScalarCos(c8_fe_x);
    c8_ge_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_he_x = c8_ge_x;
    c8_he_x = muDoubleScalarSin(c8_he_x);
    c8_ub_a = c8_fe_x;
    c8_sb_b = c8_he_x;
    c8_tb_y = c8_ub_a * c8_sb_b;
    c8_ie_x = c8_q[0] + c8_q[1];
    c8_je_x = c8_ie_x;
    c8_je_x = muDoubleScalarCos(c8_je_x);
    c8_vb_a = c8_tb_y;
    c8_tb_b = c8_je_x;
    c8_ub_y = c8_vb_a * c8_tb_b;
    c8_ke_x = c8_q[0];
    c8_le_x = c8_ke_x;
    c8_le_x = muDoubleScalarCos(c8_le_x);
    c8_wb_a = c8_ub_y;
    c8_ub_b = c8_le_x;
    c8_vb_y = c8_wb_a * c8_ub_b;
    c8_me_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ne_x = c8_me_x;
    c8_ne_x = muDoubleScalarCos(c8_ne_x);
    c8_oe_x = c8_q[0];
    c8_pe_x = c8_oe_x;
    c8_pe_x = muDoubleScalarSin(c8_pe_x);
    c8_xb_a = c8_ne_x;
    c8_vb_b = c8_pe_x;
    c8_wb_y = c8_xb_a * c8_vb_b;
    c8_qe_x = c8_q[0] + c8_q[1];
    c8_re_x = c8_qe_x;
    c8_re_x = muDoubleScalarCos(c8_re_x);
    c8_yb_a = c8_wb_y;
    c8_wb_b = c8_re_x;
    c8_xb_y = c8_yb_a * c8_wb_b;
    c8_se_x = c8_q[0];
    c8_te_x = c8_se_x;
    c8_te_x = muDoubleScalarCos(c8_te_x);
    c8_ac_a = c8_xb_y;
    c8_xb_b = c8_te_x;
    c8_yb_y = c8_ac_a * c8_xb_b;
    c8_ue_x = c8_q[0];
    c8_ve_x = c8_ue_x;
    c8_ve_x = muDoubleScalarCos(c8_ve_x);
    c8_we_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_xe_x = c8_we_x;
    c8_xe_x = muDoubleScalarSin(c8_xe_x);
    c8_bc_a = c8_ve_x;
    c8_yb_b = c8_xe_x;
    c8_ac_y = c8_bc_a * c8_yb_b;
    c8_ye_x = c8_q[0] + c8_q[1];
    c8_af_x = c8_ye_x;
    c8_af_x = muDoubleScalarSin(c8_af_x);
    c8_cc_a = c8_ac_y;
    c8_ac_b = c8_af_x;
    c8_bc_y = c8_cc_a * c8_ac_b;
    c8_bf_x = c8_q[0];
    c8_cf_x = c8_bf_x;
    c8_cf_x = muDoubleScalarSin(c8_cf_x);
    c8_dc_a = c8_bc_y;
    c8_bc_b = c8_cf_x;
    c8_cc_y = c8_dc_a * c8_bc_b;
    c8_df_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ef_x = c8_df_x;
    c8_ef_x = muDoubleScalarCos(c8_ef_x);
    c8_ff_x = c8_q[0];
    c8_gf_x = c8_ff_x;
    c8_gf_x = muDoubleScalarSin(c8_gf_x);
    c8_ec_a = c8_ef_x;
    c8_cc_b = c8_gf_x;
    c8_dc_y = c8_ec_a * c8_cc_b;
    c8_hf_x = c8_q[0] + c8_q[1];
    c8_if_x = c8_hf_x;
    c8_if_x = muDoubleScalarSin(c8_if_x);
    c8_fc_a = c8_dc_y;
    c8_dc_b = c8_if_x;
    c8_ec_y = c8_fc_a * c8_dc_b;
    c8_jf_x = c8_q[0];
    c8_kf_x = c8_jf_x;
    c8_kf_x = muDoubleScalarSin(c8_kf_x);
    c8_gc_a = c8_ec_y;
    c8_ec_b = c8_kf_x;
    c8_fc_y = c8_gc_a * c8_ec_b;
    c8_lf_x = c8_q[0];
    c8_mf_x = c8_lf_x;
    c8_mf_x = muDoubleScalarSin(c8_mf_x);
    c8_nf_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_of_x = c8_nf_x;
    c8_of_x = muDoubleScalarSin(c8_of_x);
    c8_hc_a = c8_mf_x;
    c8_fc_b = c8_of_x;
    c8_gc_y = c8_hc_a * c8_fc_b;
    c8_pf_x = c8_q[0] + c8_q[1];
    c8_qf_x = c8_pf_x;
    c8_qf_x = muDoubleScalarCos(c8_qf_x);
    c8_ic_a = c8_gc_y;
    c8_gc_b = c8_qf_x;
    c8_hc_y = c8_ic_a * c8_gc_b;
    c8_rf_x = c8_q[0];
    c8_sf_x = c8_rf_x;
    c8_sf_x = muDoubleScalarSin(c8_sf_x);
    c8_jc_a = c8_hc_y;
    c8_hc_b = c8_sf_x;
    c8_ic_y = c8_jc_a * c8_hc_b;
    c8_tf_x = c8_q[0];
    c8_uf_x = c8_tf_x;
    c8_uf_x = muDoubleScalarSin(c8_uf_x);
    c8_vf_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_wf_x = c8_vf_x;
    c8_wf_x = muDoubleScalarSin(c8_wf_x);
    c8_kc_a = c8_uf_x;
    c8_ic_b = c8_wf_x;
    c8_jc_y = c8_kc_a * c8_ic_b;
    c8_xf_x = c8_q[0] + c8_q[1];
    c8_yf_x = c8_xf_x;
    c8_yf_x = muDoubleScalarSin(c8_yf_x);
    c8_lc_a = c8_jc_y;
    c8_jc_b = c8_yf_x;
    c8_kc_y = c8_lc_a * c8_jc_b;
    c8_ag_x = c8_q[0];
    c8_bg_x = c8_ag_x;
    c8_bg_x = muDoubleScalarCos(c8_bg_x);
    c8_mc_a = c8_kc_y;
    c8_kc_b = c8_bg_x;
    c8_lc_y = c8_mc_a * c8_kc_b;
    c8_cg_x = c8_q[0];
    c8_dg_x = c8_cg_x;
    c8_dg_x = muDoubleScalarCos(c8_dg_x);
    c8_eg_x = c8_q[0] + c8_q[1];
    c8_fg_x = c8_eg_x;
    c8_fg_x = muDoubleScalarCos(c8_fg_x);
    c8_nc_a = c8_dg_x;
    c8_lc_b = c8_fg_x;
    c8_mc_y = c8_nc_a * c8_lc_b;
    c8_gg_x = c8_q[0] + c8_q[1];
    c8_hg_x = c8_gg_x;
    c8_hg_x = muDoubleScalarCos(c8_hg_x);
    c8_oc_a = c8_mc_y;
    c8_mc_b = c8_hg_x;
    c8_nc_y = c8_oc_a * c8_mc_b;
    c8_ig_x = c8_q[0];
    c8_jg_x = c8_ig_x;
    c8_jg_x = muDoubleScalarSin(c8_jg_x);
    c8_pc_a = c8_nc_y;
    c8_nc_b = c8_jg_x;
    c8_oc_y = c8_pc_a * c8_nc_b;
    c8_kg_x = c8_q[0];
    c8_lg_x = c8_kg_x;
    c8_lg_x = muDoubleScalarCos(c8_lg_x);
    c8_mg_x = c8_q[0] + c8_q[1];
    c8_ng_x = c8_mg_x;
    c8_ng_x = muDoubleScalarCos(c8_ng_x);
    c8_qc_a = c8_lg_x;
    c8_oc_b = c8_ng_x;
    c8_pc_y = c8_qc_a * c8_oc_b;
    c8_og_x = c8_q[0] + c8_q[1];
    c8_pg_x = c8_og_x;
    c8_pg_x = muDoubleScalarSin(c8_pg_x);
    c8_rc_a = c8_pc_y;
    c8_pc_b = c8_pg_x;
    c8_qc_y = c8_rc_a * c8_pc_b;
    c8_qg_x = c8_q[0];
    c8_rg_x = c8_qg_x;
    c8_rg_x = muDoubleScalarCos(c8_rg_x);
    c8_sc_a = c8_qc_y;
    c8_qc_b = c8_rg_x;
    c8_rc_y = c8_sc_a * c8_qc_b;
    c8_sg_x = c8_q[0];
    c8_tg_x = c8_sg_x;
    c8_tg_x = muDoubleScalarCos(c8_tg_x);
    c8_ug_x = c8_q[0] + c8_q[1];
    c8_vg_x = c8_ug_x;
    c8_vg_x = muDoubleScalarSin(c8_vg_x);
    c8_tc_a = c8_tg_x;
    c8_rc_b = c8_vg_x;
    c8_sc_y = c8_tc_a * c8_rc_b;
    c8_wg_x = c8_q[0] + c8_q[1];
    c8_xg_x = c8_wg_x;
    c8_xg_x = muDoubleScalarCos(c8_xg_x);
    c8_uc_a = c8_sc_y;
    c8_sc_b = c8_xg_x;
    c8_tc_y = c8_uc_a * c8_sc_b;
    c8_yg_x = c8_q[0];
    c8_ah_x = c8_yg_x;
    c8_ah_x = muDoubleScalarCos(c8_ah_x);
    c8_vc_a = c8_tc_y;
    c8_tc_b = c8_ah_x;
    c8_uc_y = c8_vc_a * c8_tc_b;
    c8_bh_x = c8_q[0];
    c8_ch_x = c8_bh_x;
    c8_ch_x = muDoubleScalarSin(c8_ch_x);
    c8_dh_x = c8_q[0] + c8_q[1];
    c8_eh_x = c8_dh_x;
    c8_eh_x = muDoubleScalarCos(c8_eh_x);
    c8_wc_a = c8_ch_x;
    c8_uc_b = c8_eh_x;
    c8_vc_y = c8_wc_a * c8_uc_b;
    c8_fh_x = c8_q[0] + c8_q[1];
    c8_gh_x = c8_fh_x;
    c8_gh_x = muDoubleScalarCos(c8_gh_x);
    c8_xc_a = c8_vc_y;
    c8_vc_b = c8_gh_x;
    c8_wc_y = c8_xc_a * c8_vc_b;
    c8_hh_x = c8_q[0];
    c8_ih_x = c8_hh_x;
    c8_ih_x = muDoubleScalarCos(c8_ih_x);
    c8_yc_a = c8_wc_y;
    c8_wc_b = c8_ih_x;
    c8_xc_y = c8_yc_a * c8_wc_b;
    c8_jh_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_kh_x = c8_jh_x;
    c8_kh_x = muDoubleScalarCos(c8_kh_x);
    c8_lh_x = c8_q[0];
    c8_mh_x = c8_lh_x;
    c8_mh_x = muDoubleScalarCos(c8_mh_x);
    c8_ad_a = c8_kh_x;
    c8_xc_b = c8_mh_x;
    c8_yc_y = c8_ad_a * c8_xc_b;
    c8_nh_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_oh_x = c8_nh_x;
    c8_oh_x = muDoubleScalarCos(c8_oh_x);
    c8_bd_a = c8_yc_y;
    c8_yc_b = c8_oh_x;
    c8_ad_y = c8_bd_a * c8_yc_b;
    c8_ph_x = c8_q[0] + c8_q[1];
    c8_qh_x = c8_ph_x;
    c8_qh_x = muDoubleScalarSin(c8_qh_x);
    c8_cd_a = c8_ad_y;
    c8_ad_b = c8_qh_x;
    c8_bd_y = c8_cd_a * c8_ad_b;
    c8_rh_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_sh_x = c8_rh_x;
    c8_sh_x = muDoubleScalarSin(c8_sh_x);
    c8_th_x = c8_q[0];
    c8_uh_x = c8_th_x;
    c8_uh_x = muDoubleScalarCos(c8_uh_x);
    c8_dd_a = c8_sh_x;
    c8_bd_b = c8_uh_x;
    c8_cd_y = c8_dd_a * c8_bd_b;
    c8_vh_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_wh_x = c8_vh_x;
    c8_wh_x = muDoubleScalarCos(c8_wh_x);
    c8_ed_a = c8_cd_y;
    c8_cd_b = c8_wh_x;
    c8_dd_y = c8_ed_a * c8_cd_b;
    c8_xh_x = c8_q[0] + c8_q[1];
    c8_yh_x = c8_xh_x;
    c8_yh_x = muDoubleScalarCos(c8_yh_x);
    c8_fd_a = c8_dd_y;
    c8_dd_b = c8_yh_x;
    c8_ed_y = c8_fd_a * c8_dd_b;
    c8_ai_x = c8_q[0];
    c8_bi_x = c8_ai_x;
    c8_bi_x = muDoubleScalarCos(c8_bi_x);
    c8_ci_x = c8_q[0] + c8_q[1];
    c8_di_x = c8_ci_x;
    c8_di_x = muDoubleScalarSin(c8_di_x);
    c8_gd_a = c8_bi_x;
    c8_ed_b = c8_di_x;
    c8_fd_y = c8_gd_a * c8_ed_b;
    c8_ei_x = c8_q[0] + c8_q[1];
    c8_fi_x = c8_ei_x;
    c8_fi_x = muDoubleScalarSin(c8_fi_x);
    c8_hd_a = c8_fd_y;
    c8_fd_b = c8_fi_x;
    c8_gd_y = c8_hd_a * c8_fd_b;
    c8_gi_x = c8_q[0];
    c8_hi_x = c8_gi_x;
    c8_hi_x = muDoubleScalarSin(c8_hi_x);
    c8_id_a = c8_gd_y;
    c8_gd_b = c8_hi_x;
    c8_hd_y = c8_id_a * c8_gd_b;
    c8_ii_x = c8_q[0];
    c8_ji_x = c8_ii_x;
    c8_ji_x = muDoubleScalarSin(c8_ji_x);
    c8_ki_x = c8_q[0] + c8_q[1];
    c8_li_x = c8_ki_x;
    c8_li_x = muDoubleScalarCos(c8_li_x);
    c8_jd_a = c8_ji_x;
    c8_hd_b = c8_li_x;
    c8_id_y = c8_jd_a * c8_hd_b;
    c8_mi_x = c8_q[0] + c8_q[1];
    c8_ni_x = c8_mi_x;
    c8_ni_x = muDoubleScalarSin(c8_ni_x);
    c8_kd_a = c8_id_y;
    c8_id_b = c8_ni_x;
    c8_jd_y = c8_kd_a * c8_id_b;
    c8_oi_x = c8_q[0];
    c8_pi_x = c8_oi_x;
    c8_pi_x = muDoubleScalarSin(c8_pi_x);
    c8_ld_a = c8_jd_y;
    c8_jd_b = c8_pi_x;
    c8_kd_y = c8_ld_a * c8_jd_b;
    c8_qi_x = c8_q[0];
    c8_ri_x = c8_qi_x;
    c8_ri_x = muDoubleScalarSin(c8_ri_x);
    c8_si_x = c8_q[0] + c8_q[1];
    c8_ti_x = c8_si_x;
    c8_ti_x = muDoubleScalarSin(c8_ti_x);
    c8_md_a = c8_ri_x;
    c8_kd_b = c8_ti_x;
    c8_ld_y = c8_md_a * c8_kd_b;
    c8_ui_x = c8_q[0] + c8_q[1];
    c8_vi_x = c8_ui_x;
    c8_vi_x = muDoubleScalarCos(c8_vi_x);
    c8_nd_a = c8_ld_y;
    c8_ld_b = c8_vi_x;
    c8_md_y = c8_nd_a * c8_ld_b;
    c8_wi_x = c8_q[0];
    c8_xi_x = c8_wi_x;
    c8_xi_x = muDoubleScalarSin(c8_xi_x);
    c8_od_a = c8_md_y;
    c8_md_b = c8_xi_x;
    c8_nd_y = c8_od_a * c8_md_b;
    c8_yi_x = c8_q[0];
    c8_aj_x = c8_yi_x;
    c8_aj_x = muDoubleScalarSin(c8_aj_x);
    c8_bj_x = c8_q[0] + c8_q[1];
    c8_cj_x = c8_bj_x;
    c8_cj_x = muDoubleScalarSin(c8_cj_x);
    c8_pd_a = c8_aj_x;
    c8_nd_b = c8_cj_x;
    c8_od_y = c8_pd_a * c8_nd_b;
    c8_dj_x = c8_q[0] + c8_q[1];
    c8_ej_x = c8_dj_x;
    c8_ej_x = muDoubleScalarSin(c8_ej_x);
    c8_qd_a = c8_od_y;
    c8_od_b = c8_ej_x;
    c8_pd_y = c8_qd_a * c8_od_b;
    c8_fj_x = c8_q[0];
    c8_gj_x = c8_fj_x;
    c8_gj_x = muDoubleScalarCos(c8_gj_x);
    c8_rd_a = c8_pd_y;
    c8_pd_b = c8_gj_x;
    c8_qd_y = c8_rd_a * c8_pd_b;
    c8_hj_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ij_x = c8_hj_x;
    c8_ij_x = muDoubleScalarCos(c8_ij_x);
    c8_jj_x = c8_q[0];
    c8_kj_x = c8_jj_x;
    c8_kj_x = muDoubleScalarSin(c8_kj_x);
    c8_sd_a = c8_ij_x;
    c8_qd_b = c8_kj_x;
    c8_rd_y = c8_sd_a * c8_qd_b;
    c8_lj_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_mj_x = c8_lj_x;
    c8_mj_x = muDoubleScalarSin(c8_mj_x);
    c8_td_a = c8_rd_y;
    c8_rd_b = c8_mj_x;
    c8_sd_y = c8_td_a * c8_rd_b;
    c8_nj_x = c8_q[0] + c8_q[1];
    c8_oj_x = c8_nj_x;
    c8_oj_x = muDoubleScalarSin(c8_oj_x);
    c8_ud_a = c8_sd_y;
    c8_sd_b = c8_oj_x;
    c8_td_y = c8_ud_a * c8_sd_b;
    c8_pj_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_qj_x = c8_pj_x;
    c8_qj_x = muDoubleScalarSin(c8_qj_x);
    c8_rj_x = c8_q[0];
    c8_sj_x = c8_rj_x;
    c8_sj_x = muDoubleScalarSin(c8_sj_x);
    c8_vd_a = c8_qj_x;
    c8_td_b = c8_sj_x;
    c8_ud_y = c8_vd_a * c8_td_b;
    c8_tj_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_uj_x = c8_tj_x;
    c8_uj_x = muDoubleScalarSin(c8_uj_x);
    c8_wd_a = c8_ud_y;
    c8_ud_b = c8_uj_x;
    c8_vd_y = c8_wd_a * c8_ud_b;
    c8_vj_x = c8_q[0] + c8_q[1];
    c8_wj_x = c8_vj_x;
    c8_wj_x = muDoubleScalarCos(c8_wj_x);
    c8_xd_a = c8_vd_y;
    c8_vd_b = c8_wj_x;
    c8_wd_y = c8_xd_a * c8_vd_b;
    c8_xj_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_yj_x = c8_xj_x;
    c8_yj_x = muDoubleScalarCos(c8_yj_x);
    c8_wd_b = c8_yj_x;
    c8_xd_y = 2.0 * c8_wd_b;
    c8_ak_x = c8_q[0];
    c8_bk_x = c8_ak_x;
    c8_bk_x = muDoubleScalarCos(c8_bk_x);
    c8_yd_a = c8_xd_y;
    c8_xd_b = c8_bk_x;
    c8_yd_y = c8_yd_a * c8_xd_b;
    c8_ck_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_dk_x = c8_ck_x;
    c8_dk_x = muDoubleScalarCos(c8_dk_x);
    c8_ae_a = c8_yd_y;
    c8_yd_b = c8_dk_x;
    c8_ae_y = c8_ae_a * c8_yd_b;
    c8_ek_x = c8_q[0];
    c8_fk_x = c8_ek_x;
    c8_fk_x = muDoubleScalarSin(c8_fk_x);
    c8_be_a = c8_ae_y;
    c8_ae_b = c8_fk_x;
    c8_be_y = c8_be_a * c8_ae_b;
    c8_gk_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_hk_x = c8_gk_x;
    c8_hk_x = muDoubleScalarCos(c8_hk_x);
    c8_be_b = c8_hk_x;
    c8_ce_y = 2.0 * c8_be_b;
    c8_ik_x = c8_q[0];
    c8_jk_x = c8_ik_x;
    c8_jk_x = muDoubleScalarCos(c8_jk_x);
    c8_ce_a = c8_ce_y;
    c8_ce_b = c8_jk_x;
    c8_de_y = c8_ce_a * c8_ce_b;
    c8_kk_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_lk_x = c8_kk_x;
    c8_lk_x = muDoubleScalarSin(c8_lk_x);
    c8_de_a = c8_de_y;
    c8_de_b = c8_lk_x;
    c8_ee_y = c8_de_a * c8_de_b;
    c8_mk_x = c8_q[0];
    c8_nk_x = c8_mk_x;
    c8_nk_x = muDoubleScalarCos(c8_nk_x);
    c8_ee_a = c8_ee_y;
    c8_ee_b = c8_nk_x;
    c8_fe_y = c8_ee_a * c8_ee_b;
    c8_ok_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_pk_x = c8_ok_x;
    c8_pk_x = muDoubleScalarCos(c8_pk_x);
    c8_fe_b = c8_pk_x;
    c8_ge_y = 2.0 * c8_fe_b;
    c8_qk_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_rk_x = c8_qk_x;
    c8_rk_x = muDoubleScalarCos(c8_rk_x);
    c8_fe_a = c8_ge_y;
    c8_ge_b = c8_rk_x;
    c8_he_y = c8_fe_a * c8_ge_b;
    c8_sk_x = c8_q[0];
    c8_tk_x = c8_sk_x;
    c8_tk_x = muDoubleScalarSin(c8_tk_x);
    c8_ge_a = c8_he_y;
    c8_he_b = c8_tk_x;
    c8_ie_y = c8_ge_a * c8_he_b;
    c8_uk_x = c8_q[0];
    c8_vk_x = c8_uk_x;
    c8_vk_x = muDoubleScalarCos(c8_vk_x);
    c8_he_a = c8_ie_y;
    c8_ie_b = c8_vk_x;
    c8_je_y = c8_he_a * c8_ie_b;
    c8_wk_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_xk_x = c8_wk_x;
    c8_xk_x = muDoubleScalarSin(c8_xk_x);
    c8_je_b = c8_xk_x;
    c8_ke_y = 2.0 * c8_je_b;
    c8_yk_x = c8_q[0];
    c8_al_x = c8_yk_x;
    c8_al_x = muDoubleScalarCos(c8_al_x);
    c8_ie_a = c8_ke_y;
    c8_ke_b = c8_al_x;
    c8_le_y = c8_ie_a * c8_ke_b;
    c8_bl_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_cl_x = c8_bl_x;
    c8_cl_x = muDoubleScalarCos(c8_cl_x);
    c8_je_a = c8_le_y;
    c8_le_b = c8_cl_x;
    c8_me_y = c8_je_a * c8_le_b;
    c8_dl_x = c8_q[0];
    c8_el_x = c8_dl_x;
    c8_el_x = muDoubleScalarCos(c8_el_x);
    c8_ke_a = c8_me_y;
    c8_me_b = c8_el_x;
    c8_ne_y = c8_ke_a * c8_me_b;
    c8_fl_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_gl_x = c8_fl_x;
    c8_gl_x = muDoubleScalarCos(c8_gl_x);
    c8_ne_b = c8_gl_x;
    c8_oe_y = 2.0 * c8_ne_b;
    c8_hl_x = c8_q[0];
    c8_il_x = c8_hl_x;
    c8_il_x = muDoubleScalarSin(c8_il_x);
    c8_le_a = c8_oe_y;
    c8_oe_b = c8_il_x;
    c8_pe_y = c8_le_a * c8_oe_b;
    c8_jl_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_kl_x = c8_jl_x;
    c8_kl_x = muDoubleScalarSin(c8_kl_x);
    c8_me_a = c8_pe_y;
    c8_pe_b = c8_kl_x;
    c8_qe_y = c8_me_a * c8_pe_b;
    c8_ll_x = c8_q[0];
    c8_ml_x = c8_ll_x;
    c8_ml_x = muDoubleScalarSin(c8_ml_x);
    c8_ne_a = c8_qe_y;
    c8_qe_b = c8_ml_x;
    c8_re_y = c8_ne_a * c8_qe_b;
    c8_nl_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ol_x = c8_nl_x;
    c8_ol_x = muDoubleScalarSin(c8_ol_x);
    c8_re_b = c8_ol_x;
    c8_se_y = 2.0 * c8_re_b;
    c8_pl_x = c8_q[0];
    c8_ql_x = c8_pl_x;
    c8_ql_x = muDoubleScalarCos(c8_ql_x);
    c8_oe_a = c8_se_y;
    c8_se_b = c8_ql_x;
    c8_te_y = c8_oe_a * c8_se_b;
    c8_rl_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_sl_x = c8_rl_x;
    c8_sl_x = muDoubleScalarSin(c8_sl_x);
    c8_pe_a = c8_te_y;
    c8_te_b = c8_sl_x;
    c8_ue_y = c8_pe_a * c8_te_b;
    c8_tl_x = c8_q[0];
    c8_ul_x = c8_tl_x;
    c8_ul_x = muDoubleScalarSin(c8_ul_x);
    c8_qe_a = c8_ue_y;
    c8_ue_b = c8_ul_x;
    c8_ve_y = c8_qe_a * c8_ue_b;
    c8_vl_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_wl_x = c8_vl_x;
    c8_wl_x = muDoubleScalarSin(c8_wl_x);
    c8_ve_b = c8_wl_x;
    c8_we_y = 2.0 * c8_ve_b;
    c8_xl_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_yl_x = c8_xl_x;
    c8_yl_x = muDoubleScalarCos(c8_yl_x);
    c8_re_a = c8_we_y;
    c8_we_b = c8_yl_x;
    c8_xe_y = c8_re_a * c8_we_b;
    c8_am_x = c8_q[0];
    c8_bm_x = c8_am_x;
    c8_bm_x = muDoubleScalarSin(c8_bm_x);
    c8_se_a = c8_xe_y;
    c8_xe_b = c8_bm_x;
    c8_ye_y = c8_se_a * c8_xe_b;
    c8_cm_x = c8_q[0];
    c8_dm_x = c8_cm_x;
    c8_dm_x = muDoubleScalarSin(c8_dm_x);
    c8_te_a = c8_ye_y;
    c8_ye_b = c8_dm_x;
    c8_af_y = c8_te_a * c8_ye_b;
    c8_em_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_fm_x = c8_em_x;
    c8_fm_x = muDoubleScalarSin(c8_fm_x);
    c8_af_b = c8_fm_x;
    c8_bf_y = 2.0 * c8_af_b;
    c8_gm_x = c8_q[0];
    c8_hm_x = c8_gm_x;
    c8_hm_x = muDoubleScalarSin(c8_hm_x);
    c8_ue_a = c8_bf_y;
    c8_bf_b = c8_hm_x;
    c8_cf_y = c8_ue_a * c8_bf_b;
    c8_im_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_jm_x = c8_im_x;
    c8_jm_x = muDoubleScalarSin(c8_jm_x);
    c8_ve_a = c8_cf_y;
    c8_cf_b = c8_jm_x;
    c8_df_y = c8_ve_a * c8_cf_b;
    c8_km_x = c8_q[0];
    c8_lm_x = c8_km_x;
    c8_lm_x = muDoubleScalarCos(c8_lm_x);
    c8_we_a = c8_df_y;
    c8_df_b = c8_lm_x;
    c8_ef_y = c8_we_a * c8_df_b;
    c8_mm_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_nm_x = c8_mm_x;
    c8_nm_x = muDoubleScalarCos(c8_nm_x);
    c8_om_x = c8_q[0];
    c8_pm_x = c8_om_x;
    c8_pm_x = muDoubleScalarCos(c8_pm_x);
    c8_xe_a = c8_nm_x;
    c8_ef_b = c8_pm_x;
    c8_ff_y = c8_xe_a * c8_ef_b;
    c8_qm_x = c8_q[0] + c8_q[1];
    c8_rm_x = c8_qm_x;
    c8_rm_x = muDoubleScalarCos(c8_rm_x);
    c8_ye_a = c8_ff_y;
    c8_ff_b = c8_rm_x;
    c8_gf_y = c8_ye_a * c8_ff_b;
    c8_sm_x = c8_q[0];
    c8_tm_x = c8_sm_x;
    c8_tm_x = muDoubleScalarSin(c8_tm_x);
    c8_af_a = c8_gf_y;
    c8_gf_b = c8_tm_x;
    c8_hf_y = c8_af_a * c8_gf_b;
    c8_um_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_vm_x = c8_um_x;
    c8_vm_x = muDoubleScalarCos(c8_vm_x);
    c8_wm_x = c8_q[0];
    c8_xm_x = c8_wm_x;
    c8_xm_x = muDoubleScalarCos(c8_xm_x);
    c8_bf_a = c8_vm_x;
    c8_hf_b = c8_xm_x;
    c8_if_y = c8_bf_a * c8_hf_b;
    c8_ym_x = c8_q[0] + c8_q[1];
    c8_an_x = c8_ym_x;
    c8_an_x = muDoubleScalarSin(c8_an_x);
    c8_cf_a = c8_if_y;
    c8_if_b = c8_an_x;
    c8_jf_y = c8_cf_a * c8_if_b;
    c8_bn_x = c8_q[0];
    c8_cn_x = c8_bn_x;
    c8_cn_x = muDoubleScalarCos(c8_cn_x);
    c8_df_a = c8_jf_y;
    c8_jf_b = c8_cn_x;
    c8_kf_y = c8_df_a * c8_jf_b;
    c8_dn_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_en_x = c8_dn_x;
    c8_en_x = muDoubleScalarCos(c8_en_x);
    c8_fn_x = c8_q[0];
    c8_gn_x = c8_fn_x;
    c8_gn_x = muDoubleScalarSin(c8_gn_x);
    c8_ef_a = c8_en_x;
    c8_kf_b = c8_gn_x;
    c8_lf_y = c8_ef_a * c8_kf_b;
    c8_hn_x = c8_q[0] + c8_q[1];
    c8_in_x = c8_hn_x;
    c8_in_x = muDoubleScalarCos(c8_in_x);
    c8_ff_a = c8_lf_y;
    c8_lf_b = c8_in_x;
    c8_mf_y = c8_ff_a * c8_lf_b;
    c8_jn_x = c8_q[0];
    c8_kn_x = c8_jn_x;
    c8_kn_x = muDoubleScalarCos(c8_kn_x);
    c8_gf_a = c8_mf_y;
    c8_mf_b = c8_kn_x;
    c8_nf_y = c8_gf_a * c8_mf_b;
    c8_ln_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_mn_x = c8_ln_x;
    c8_mn_x = muDoubleScalarSin(c8_mn_x);
    c8_nn_x = c8_q[0];
    c8_on_x = c8_nn_x;
    c8_on_x = muDoubleScalarCos(c8_on_x);
    c8_hf_a = c8_mn_x;
    c8_nf_b = c8_on_x;
    c8_of_y = c8_hf_a * c8_nf_b;
    c8_pn_x = c8_q[0] + c8_q[1];
    c8_qn_x = c8_pn_x;
    c8_qn_x = muDoubleScalarCos(c8_qn_x);
    c8_if_a = c8_of_y;
    c8_of_b = c8_qn_x;
    c8_pf_y = c8_if_a * c8_of_b;
    c8_rn_x = c8_q[0];
    c8_sn_x = c8_rn_x;
    c8_sn_x = muDoubleScalarCos(c8_sn_x);
    c8_jf_a = c8_pf_y;
    c8_pf_b = c8_sn_x;
    c8_qf_y = c8_jf_a * c8_pf_b;
    c8_tn_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_un_x = c8_tn_x;
    c8_un_x = muDoubleScalarCos(c8_un_x);
    c8_vn_x = c8_q[0];
    c8_wn_x = c8_vn_x;
    c8_wn_x = muDoubleScalarSin(c8_wn_x);
    c8_kf_a = c8_un_x;
    c8_qf_b = c8_wn_x;
    c8_rf_y = c8_kf_a * c8_qf_b;
    c8_xn_x = c8_q[0] + c8_q[1];
    c8_yn_x = c8_xn_x;
    c8_yn_x = muDoubleScalarCos(c8_yn_x);
    c8_lf_a = c8_rf_y;
    c8_rf_b = c8_yn_x;
    c8_sf_y = c8_lf_a * c8_rf_b;
    c8_ao_x = c8_q[0];
    c8_bo_x = c8_ao_x;
    c8_bo_x = muDoubleScalarSin(c8_bo_x);
    c8_mf_a = c8_sf_y;
    c8_sf_b = c8_bo_x;
    c8_tf_y = c8_mf_a * c8_sf_b;
    c8_co_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_do_x = c8_co_x;
    c8_do_x = muDoubleScalarCos(c8_do_x);
    c8_eo_x = c8_q[0];
    c8_fo_x = c8_eo_x;
    c8_fo_x = muDoubleScalarCos(c8_fo_x);
    c8_nf_a = c8_do_x;
    c8_tf_b = c8_fo_x;
    c8_uf_y = c8_nf_a * c8_tf_b;
    c8_go_x = c8_q[0] + c8_q[1];
    c8_ho_x = c8_go_x;
    c8_ho_x = muDoubleScalarSin(c8_ho_x);
    c8_of_a = c8_uf_y;
    c8_uf_b = c8_ho_x;
    c8_vf_y = c8_of_a * c8_uf_b;
    c8_io_x = c8_q[0];
    c8_jo_x = c8_io_x;
    c8_jo_x = muDoubleScalarSin(c8_jo_x);
    c8_pf_a = c8_vf_y;
    c8_vf_b = c8_jo_x;
    c8_wf_y = c8_pf_a * c8_vf_b;
    c8_ko_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_lo_x = c8_ko_x;
    c8_lo_x = muDoubleScalarSin(c8_lo_x);
    c8_mo_x = c8_q[0];
    c8_no_x = c8_mo_x;
    c8_no_x = muDoubleScalarCos(c8_no_x);
    c8_qf_a = c8_lo_x;
    c8_wf_b = c8_no_x;
    c8_xf_y = c8_qf_a * c8_wf_b;
    c8_oo_x = c8_q[0] + c8_q[1];
    c8_po_x = c8_oo_x;
    c8_po_x = muDoubleScalarSin(c8_po_x);
    c8_rf_a = c8_xf_y;
    c8_xf_b = c8_po_x;
    c8_yf_y = c8_rf_a * c8_xf_b;
    c8_qo_x = c8_q[0];
    c8_ro_x = c8_qo_x;
    c8_ro_x = muDoubleScalarCos(c8_ro_x);
    c8_sf_a = c8_yf_y;
    c8_yf_b = c8_ro_x;
    c8_ag_y = c8_sf_a * c8_yf_b;
    c8_so_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_to_x = c8_so_x;
    c8_to_x = muDoubleScalarSin(c8_to_x);
    c8_uo_x = c8_q[0];
    c8_vo_x = c8_uo_x;
    c8_vo_x = muDoubleScalarSin(c8_vo_x);
    c8_tf_a = c8_to_x;
    c8_ag_b = c8_vo_x;
    c8_bg_y = c8_tf_a * c8_ag_b;
    c8_wo_x = c8_q[0] + c8_q[1];
    c8_xo_x = c8_wo_x;
    c8_xo_x = muDoubleScalarCos(c8_xo_x);
    c8_uf_a = c8_bg_y;
    c8_bg_b = c8_xo_x;
    c8_cg_y = c8_uf_a * c8_bg_b;
    c8_yo_x = c8_q[0];
    c8_ap_x = c8_yo_x;
    c8_ap_x = muDoubleScalarCos(c8_ap_x);
    c8_vf_a = c8_cg_y;
    c8_cg_b = c8_ap_x;
    c8_dg_y = c8_vf_a * c8_cg_b;
    c8_bp_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_cp_x = c8_bp_x;
    c8_cp_x = muDoubleScalarCos(c8_cp_x);
    c8_dp_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ep_x = c8_dp_x;
    c8_ep_x = muDoubleScalarCos(c8_ep_x);
    c8_wf_a = c8_cp_x;
    c8_dg_b = c8_ep_x;
    c8_eg_y = c8_wf_a * c8_dg_b;
    c8_fp_x = c8_q[0] + c8_q[1];
    c8_gp_x = c8_fp_x;
    c8_gp_x = muDoubleScalarSin(c8_gp_x);
    c8_xf_a = c8_eg_y;
    c8_eg_b = c8_gp_x;
    c8_fg_y = c8_xf_a * c8_eg_b;
    c8_hp_x = c8_q[0];
    c8_ip_x = c8_hp_x;
    c8_ip_x = muDoubleScalarSin(c8_ip_x);
    c8_yf_a = c8_fg_y;
    c8_fg_b = c8_ip_x;
    c8_gg_y = c8_yf_a * c8_fg_b;
    c8_jp_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_kp_x = c8_jp_x;
    c8_kp_x = muDoubleScalarCos(c8_kp_x);
    c8_lp_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_mp_x = c8_lp_x;
    c8_mp_x = muDoubleScalarSin(c8_mp_x);
    c8_ag_a = c8_kp_x;
    c8_gg_b = c8_mp_x;
    c8_hg_y = c8_ag_a * c8_gg_b;
    c8_np_x = c8_q[0] + c8_q[1];
    c8_op_x = c8_np_x;
    c8_op_x = muDoubleScalarCos(c8_op_x);
    c8_bg_a = c8_hg_y;
    c8_hg_b = c8_op_x;
    c8_ig_y = c8_bg_a * c8_hg_b;
    c8_pp_x = c8_q[0];
    c8_qp_x = c8_pp_x;
    c8_qp_x = muDoubleScalarSin(c8_qp_x);
    c8_cg_a = c8_ig_y;
    c8_ig_b = c8_qp_x;
    c8_jg_y = c8_cg_a * c8_ig_b;
    c8_rp_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_sp_x = c8_rp_x;
    c8_sp_x = muDoubleScalarSin(c8_sp_x);
    c8_tp_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_up_x = c8_tp_x;
    c8_up_x = muDoubleScalarCos(c8_up_x);
    c8_dg_a = c8_sp_x;
    c8_jg_b = c8_up_x;
    c8_kg_y = c8_dg_a * c8_jg_b;
    c8_vp_x = c8_q[0] + c8_q[1];
    c8_wp_x = c8_vp_x;
    c8_wp_x = muDoubleScalarSin(c8_wp_x);
    c8_eg_a = c8_kg_y;
    c8_kg_b = c8_wp_x;
    c8_lg_y = c8_eg_a * c8_kg_b;
    c8_xp_x = c8_q[0];
    c8_yp_x = c8_xp_x;
    c8_yp_x = muDoubleScalarCos(c8_yp_x);
    c8_fg_a = c8_lg_y;
    c8_lg_b = c8_yp_x;
    c8_mg_y = c8_fg_a * c8_lg_b;
    c8_aq_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_bq_x = c8_aq_x;
    c8_bq_x = muDoubleScalarSin(c8_bq_x);
    c8_cq_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_dq_x = c8_cq_x;
    c8_dq_x = muDoubleScalarSin(c8_dq_x);
    c8_gg_a = c8_bq_x;
    c8_mg_b = c8_dq_x;
    c8_ng_y = c8_gg_a * c8_mg_b;
    c8_eq_x = c8_q[0] + c8_q[1];
    c8_fq_x = c8_eq_x;
    c8_fq_x = muDoubleScalarCos(c8_fq_x);
    c8_hg_a = c8_ng_y;
    c8_ng_b = c8_fq_x;
    c8_og_y = c8_hg_a * c8_ng_b;
    c8_gq_x = c8_q[0];
    c8_hq_x = c8_gq_x;
    c8_hq_x = muDoubleScalarCos(c8_hq_x);
    c8_ig_a = c8_og_y;
    c8_og_b = c8_hq_x;
    c8_pg_y = c8_ig_a * c8_og_b;
    c8_iq_x = c8_q[0];
    c8_jq_x = c8_iq_x;
    c8_jq_x = muDoubleScalarCos(c8_jq_x);
    c8_kq_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_lq_x = c8_kq_x;
    c8_lq_x = muDoubleScalarSin(c8_lq_x);
    c8_jg_a = c8_jq_x;
    c8_pg_b = c8_lq_x;
    c8_qg_y = c8_jg_a * c8_pg_b;
    c8_mq_x = c8_q[0] + c8_q[1];
    c8_nq_x = c8_mq_x;
    c8_nq_x = muDoubleScalarCos(c8_nq_x);
    c8_kg_a = c8_qg_y;
    c8_qg_b = c8_nq_x;
    c8_rg_y = c8_kg_a * c8_qg_b;
    c8_oq_x = c8_q[0];
    c8_pq_x = c8_oq_x;
    c8_pq_x = muDoubleScalarSin(c8_pq_x);
    c8_lg_a = c8_rg_y;
    c8_rg_b = c8_pq_x;
    c8_sg_y = c8_lg_a * c8_rg_b;
    c8_qq_x = c8_q[0];
    c8_rq_x = c8_qq_x;
    c8_rq_x = muDoubleScalarCos(c8_rq_x);
    c8_sq_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_tq_x = c8_sq_x;
    c8_tq_x = muDoubleScalarSin(c8_tq_x);
    c8_mg_a = c8_rq_x;
    c8_sg_b = c8_tq_x;
    c8_tg_y = c8_mg_a * c8_sg_b;
    c8_uq_x = c8_q[0] + c8_q[1];
    c8_vq_x = c8_uq_x;
    c8_vq_x = muDoubleScalarSin(c8_vq_x);
    c8_ng_a = c8_tg_y;
    c8_tg_b = c8_vq_x;
    c8_ug_y = c8_ng_a * c8_tg_b;
    c8_wq_x = c8_q[0];
    c8_xq_x = c8_wq_x;
    c8_xq_x = muDoubleScalarCos(c8_xq_x);
    c8_og_a = c8_ug_y;
    c8_ug_b = c8_xq_x;
    c8_vg_y = c8_og_a * c8_ug_b;
    c8_yq_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ar_x = c8_yq_x;
    c8_ar_x = muDoubleScalarCos(c8_ar_x);
    c8_br_x = c8_q[0];
    c8_cr_x = c8_br_x;
    c8_cr_x = muDoubleScalarSin(c8_cr_x);
    c8_pg_a = c8_ar_x;
    c8_vg_b = c8_cr_x;
    c8_wg_y = c8_pg_a * c8_vg_b;
    c8_dr_x = c8_q[0] + c8_q[1];
    c8_er_x = c8_dr_x;
    c8_er_x = muDoubleScalarCos(c8_er_x);
    c8_qg_a = c8_wg_y;
    c8_wg_b = c8_er_x;
    c8_xg_y = c8_qg_a * c8_wg_b;
    c8_fr_x = c8_q[0];
    c8_gr_x = c8_fr_x;
    c8_gr_x = muDoubleScalarSin(c8_gr_x);
    c8_rg_a = c8_xg_y;
    c8_xg_b = c8_gr_x;
    c8_yg_y = c8_rg_a * c8_xg_b;
    c8_hr_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ir_x = c8_hr_x;
    c8_ir_x = muDoubleScalarCos(c8_ir_x);
    c8_jr_x = c8_q[0];
    c8_kr_x = c8_jr_x;
    c8_kr_x = muDoubleScalarSin(c8_kr_x);
    c8_sg_a = c8_ir_x;
    c8_yg_b = c8_kr_x;
    c8_ah_y = c8_sg_a * c8_yg_b;
    c8_lr_x = c8_q[0] + c8_q[1];
    c8_mr_x = c8_lr_x;
    c8_mr_x = muDoubleScalarSin(c8_mr_x);
    c8_tg_a = c8_ah_y;
    c8_ah_b = c8_mr_x;
    c8_bh_y = c8_tg_a * c8_ah_b;
    c8_nr_x = c8_q[0];
    c8_or_x = c8_nr_x;
    c8_or_x = muDoubleScalarCos(c8_or_x);
    c8_ug_a = c8_bh_y;
    c8_bh_b = c8_or_x;
    c8_ch_y = c8_ug_a * c8_bh_b;
    c8_pr_x = c8_q[0];
    c8_qr_x = c8_pr_x;
    c8_qr_x = muDoubleScalarCos(c8_qr_x);
    c8_rr_x = c8_q[0] + c8_q[1];
    c8_sr_x = c8_rr_x;
    c8_sr_x = muDoubleScalarSin(c8_sr_x);
    c8_vg_a = c8_qr_x;
    c8_ch_b = c8_sr_x;
    c8_dh_y = c8_vg_a * c8_ch_b;
    c8_tr_x = c8_q[0] + c8_q[1];
    c8_ur_x = c8_tr_x;
    c8_ur_x = muDoubleScalarCos(c8_ur_x);
    c8_wg_a = c8_dh_y;
    c8_dh_b = c8_ur_x;
    c8_eh_y = c8_wg_a * c8_dh_b;
    c8_vr_x = c8_q[0];
    c8_wr_x = c8_vr_x;
    c8_wr_x = muDoubleScalarSin(c8_wr_x);
    c8_xg_a = c8_eh_y;
    c8_eh_b = c8_wr_x;
    c8_fh_y = c8_xg_a * c8_eh_b;
    c8_xr_x = c8_q[0];
    c8_yr_x = c8_xr_x;
    c8_yr_x = muDoubleScalarCos(c8_yr_x);
    c8_as_x = c8_q[0] + c8_q[1];
    c8_bs_x = c8_as_x;
    c8_bs_x = muDoubleScalarSin(c8_bs_x);
    c8_yg_a = c8_yr_x;
    c8_fh_b = c8_bs_x;
    c8_gh_y = c8_yg_a * c8_fh_b;
    c8_cs_x = c8_q[0] + c8_q[1];
    c8_ds_x = c8_cs_x;
    c8_ds_x = muDoubleScalarSin(c8_ds_x);
    c8_ah_a = c8_gh_y;
    c8_gh_b = c8_ds_x;
    c8_hh_y = c8_ah_a * c8_gh_b;
    c8_es_x = c8_q[0];
    c8_fs_x = c8_es_x;
    c8_fs_x = muDoubleScalarCos(c8_fs_x);
    c8_bh_a = c8_hh_y;
    c8_hh_b = c8_fs_x;
    c8_ih_y = c8_bh_a * c8_hh_b;
    c8_gs_x = c8_q[0];
    c8_hs_x = c8_gs_x;
    c8_hs_x = muDoubleScalarSin(c8_hs_x);
    c8_is_x = c8_q[0] + c8_q[1];
    c8_js_x = c8_is_x;
    c8_js_x = muDoubleScalarCos(c8_js_x);
    c8_ch_a = c8_hs_x;
    c8_ih_b = c8_js_x;
    c8_jh_y = c8_ch_a * c8_ih_b;
    c8_ks_x = c8_q[0] + c8_q[1];
    c8_ls_x = c8_ks_x;
    c8_ls_x = muDoubleScalarCos(c8_ls_x);
    c8_dh_a = c8_jh_y;
    c8_jh_b = c8_ls_x;
    c8_kh_y = c8_dh_a * c8_jh_b;
    c8_ms_x = c8_q[0];
    c8_ns_x = c8_ms_x;
    c8_ns_x = muDoubleScalarSin(c8_ns_x);
    c8_eh_a = c8_kh_y;
    c8_kh_b = c8_ns_x;
    c8_lh_y = c8_eh_a * c8_kh_b;
    c8_os_x = c8_q[0];
    c8_ps_x = c8_os_x;
    c8_ps_x = muDoubleScalarSin(c8_ps_x);
    c8_qs_x = c8_q[0] + c8_q[1];
    c8_rs_x = c8_qs_x;
    c8_rs_x = muDoubleScalarCos(c8_rs_x);
    c8_fh_a = c8_ps_x;
    c8_lh_b = c8_rs_x;
    c8_mh_y = c8_fh_a * c8_lh_b;
    c8_ss_x = c8_q[0] + c8_q[1];
    c8_ts_x = c8_ss_x;
    c8_ts_x = muDoubleScalarSin(c8_ts_x);
    c8_gh_a = c8_mh_y;
    c8_mh_b = c8_ts_x;
    c8_nh_y = c8_gh_a * c8_mh_b;
    c8_us_x = c8_q[0];
    c8_vs_x = c8_us_x;
    c8_vs_x = muDoubleScalarCos(c8_vs_x);
    c8_hh_a = c8_nh_y;
    c8_nh_b = c8_vs_x;
    c8_oh_y = c8_hh_a * c8_nh_b;
    c8_ws_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_xs_x = c8_ws_x;
    c8_xs_x = muDoubleScalarCos(c8_xs_x);
    c8_ys_x = c8_q[0];
    c8_at_x = c8_ys_x;
    c8_at_x = muDoubleScalarCos(c8_at_x);
    c8_ih_a = c8_xs_x;
    c8_oh_b = c8_at_x;
    c8_ph_y = c8_ih_a * c8_oh_b;
    c8_bt_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ct_x = c8_bt_x;
    c8_ct_x = muDoubleScalarSin(c8_ct_x);
    c8_jh_a = c8_ph_y;
    c8_ph_b = c8_ct_x;
    c8_qh_y = c8_jh_a * c8_ph_b;
    c8_dt_x = c8_q[0] + c8_q[1];
    c8_et_x = c8_dt_x;
    c8_et_x = muDoubleScalarSin(c8_et_x);
    c8_kh_a = c8_qh_y;
    c8_qh_b = c8_et_x;
    c8_rh_y = c8_kh_a * c8_qh_b;
    c8_ft_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_gt_x = c8_ft_x;
    c8_gt_x = muDoubleScalarCos(c8_gt_x);
    c8_ht_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_it_x = c8_ht_x;
    c8_it_x = muDoubleScalarCos(c8_it_x);
    c8_lh_a = c8_gt_x;
    c8_rh_b = c8_it_x;
    c8_sh_y = c8_lh_a * c8_rh_b;
    c8_jt_x = c8_q[0];
    c8_kt_x = c8_jt_x;
    c8_kt_x = muDoubleScalarSin(c8_kt_x);
    c8_mh_a = c8_sh_y;
    c8_sh_b = c8_kt_x;
    c8_th_y = c8_mh_a * c8_sh_b;
    c8_lt_x = c8_q[0] + c8_q[1];
    c8_mt_x = c8_lt_x;
    c8_mt_x = muDoubleScalarSin(c8_mt_x);
    c8_nh_a = c8_th_y;
    c8_th_b = c8_mt_x;
    c8_uh_y = c8_nh_a * c8_th_b;
    c8_nt_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ot_x = c8_nt_x;
    c8_ot_x = muDoubleScalarSin(c8_ot_x);
    c8_pt_x = c8_q[0];
    c8_qt_x = c8_pt_x;
    c8_qt_x = muDoubleScalarCos(c8_qt_x);
    c8_oh_a = c8_ot_x;
    c8_uh_b = c8_qt_x;
    c8_vh_y = c8_oh_a * c8_uh_b;
    c8_rt_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_st_x = c8_rt_x;
    c8_st_x = muDoubleScalarSin(c8_st_x);
    c8_ph_a = c8_vh_y;
    c8_vh_b = c8_st_x;
    c8_wh_y = c8_ph_a * c8_vh_b;
    c8_tt_x = c8_q[0] + c8_q[1];
    c8_ut_x = c8_tt_x;
    c8_ut_x = muDoubleScalarCos(c8_ut_x);
    c8_qh_a = c8_wh_y;
    c8_wh_b = c8_ut_x;
    c8_xh_y = c8_qh_a * c8_wh_b;
    c8_vt_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_wt_x = c8_vt_x;
    c8_wt_x = muDoubleScalarSin(c8_wt_x);
    c8_xt_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_yt_x = c8_xt_x;
    c8_yt_x = muDoubleScalarCos(c8_yt_x);
    c8_rh_a = c8_wt_x;
    c8_xh_b = c8_yt_x;
    c8_yh_y = c8_rh_a * c8_xh_b;
    c8_au_x = c8_q[0];
    c8_bu_x = c8_au_x;
    c8_bu_x = muDoubleScalarSin(c8_bu_x);
    c8_sh_a = c8_yh_y;
    c8_yh_b = c8_bu_x;
    c8_ai_y = c8_sh_a * c8_yh_b;
    c8_cu_x = c8_q[0] + c8_q[1];
    c8_du_x = c8_cu_x;
    c8_du_x = muDoubleScalarCos(c8_du_x);
    c8_th_a = c8_ai_y;
    c8_ai_b = c8_du_x;
    c8_bi_y = c8_th_a * c8_ai_b;
    c8_eu_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_fu_x = c8_eu_x;
    c8_fu_x = muDoubleScalarCos(c8_fu_x);
    c8_bi_b = c8_fu_x;
    c8_ci_y = 2.0 * c8_bi_b;
    c8_gu_x = c8_q[0];
    c8_hu_x = c8_gu_x;
    c8_hu_x = muDoubleScalarCos(c8_hu_x);
    c8_uh_a = c8_ci_y;
    c8_ci_b = c8_hu_x;
    c8_di_y = c8_uh_a * c8_ci_b;
    c8_iu_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ju_x = c8_iu_x;
    c8_ju_x = muDoubleScalarSin(c8_ju_x);
    c8_vh_a = c8_di_y;
    c8_di_b = c8_ju_x;
    c8_ei_y = c8_vh_a * c8_di_b;
    c8_ku_x = c8_q[0];
    c8_lu_x = c8_ku_x;
    c8_lu_x = muDoubleScalarSin(c8_lu_x);
    c8_wh_a = c8_ei_y;
    c8_ei_b = c8_lu_x;
    c8_fi_y = c8_wh_a * c8_ei_b;
    c8_mu_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_nu_x = c8_mu_x;
    c8_nu_x = muDoubleScalarCos(c8_nu_x);
    c8_fi_b = c8_nu_x;
    c8_gi_y = 2.0 * c8_fi_b;
    c8_ou_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_pu_x = c8_ou_x;
    c8_pu_x = muDoubleScalarCos(c8_pu_x);
    c8_xh_a = c8_gi_y;
    c8_gi_b = c8_pu_x;
    c8_hi_y = c8_xh_a * c8_gi_b;
    c8_qu_x = c8_q[0];
    c8_ru_x = c8_qu_x;
    c8_ru_x = muDoubleScalarSin(c8_ru_x);
    c8_yh_a = c8_hi_y;
    c8_hi_b = c8_ru_x;
    c8_ii_y = c8_yh_a * c8_hi_b;
    c8_su_x = c8_q[0];
    c8_tu_x = c8_su_x;
    c8_tu_x = muDoubleScalarSin(c8_tu_x);
    c8_ai_a = c8_ii_y;
    c8_ii_b = c8_tu_x;
    c8_ji_y = c8_ai_a * c8_ii_b;
    c8_uu_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_vu_x = c8_uu_x;
    c8_vu_x = muDoubleScalarSin(c8_vu_x);
    c8_ji_b = c8_vu_x;
    c8_ki_y = 2.0 * c8_ji_b;
    c8_wu_x = c8_q[0];
    c8_xu_x = c8_wu_x;
    c8_xu_x = muDoubleScalarCos(c8_xu_x);
    c8_bi_a = c8_ki_y;
    c8_ki_b = c8_xu_x;
    c8_li_y = c8_bi_a * c8_ki_b;
    c8_yu_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_av_x = c8_yu_x;
    c8_av_x = muDoubleScalarSin(c8_av_x);
    c8_ci_a = c8_li_y;
    c8_li_b = c8_av_x;
    c8_mi_y = c8_ci_a * c8_li_b;
    c8_bv_x = c8_q[0];
    c8_cv_x = c8_bv_x;
    c8_cv_x = muDoubleScalarCos(c8_cv_x);
    c8_di_a = c8_mi_y;
    c8_mi_b = c8_cv_x;
    c8_ni_y = c8_di_a * c8_mi_b;
    c8_dv_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ev_x = c8_dv_x;
    c8_ev_x = muDoubleScalarSin(c8_ev_x);
    c8_ni_b = c8_ev_x;
    c8_oi_y = 2.0 * c8_ni_b;
    c8_fv_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_gv_x = c8_fv_x;
    c8_gv_x = muDoubleScalarCos(c8_gv_x);
    c8_ei_a = c8_oi_y;
    c8_oi_b = c8_gv_x;
    c8_pi_y = c8_ei_a * c8_oi_b;
    c8_hv_x = c8_q[0];
    c8_iv_x = c8_hv_x;
    c8_iv_x = muDoubleScalarSin(c8_iv_x);
    c8_fi_a = c8_pi_y;
    c8_pi_b = c8_iv_x;
    c8_qi_y = c8_fi_a * c8_pi_b;
    c8_jv_x = c8_q[0];
    c8_kv_x = c8_jv_x;
    c8_kv_x = muDoubleScalarCos(c8_kv_x);
    c8_gi_a = c8_qi_y;
    c8_qi_b = c8_kv_x;
    c8_ri_y = c8_gi_a * c8_qi_b;
    c8_lv_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_mv_x = c8_lv_x;
    c8_mv_x = muDoubleScalarCos(c8_mv_x);
    c8_ri_b = c8_mv_x;
    c8_si_y = 2.0 * c8_ri_b;
    c8_nv_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ov_x = c8_nv_x;
    c8_ov_x = muDoubleScalarCos(c8_ov_x);
    c8_hi_a = c8_si_y;
    c8_si_b = c8_ov_x;
    c8_ti_y = c8_hi_a * c8_si_b;
    c8_pv_x = c8_q[0] + c8_q[1];
    c8_qv_x = c8_pv_x;
    c8_qv_x = muDoubleScalarSin(c8_qv_x);
    c8_ii_a = c8_ti_y;
    c8_ti_b = c8_qv_x;
    c8_ui_y = c8_ii_a * c8_ti_b;
    c8_rv_x = c8_q[0] + c8_q[1];
    c8_sv_x = c8_rv_x;
    c8_sv_x = muDoubleScalarSin(c8_sv_x);
    c8_ji_a = c8_ui_y;
    c8_ui_b = c8_sv_x;
    c8_vi_y = c8_ji_a * c8_ui_b;
    c8_tv_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_uv_x = c8_tv_x;
    c8_uv_x = muDoubleScalarCos(c8_uv_x);
    c8_vi_b = c8_uv_x;
    c8_wi_y = 2.0 * c8_vi_b;
    c8_vv_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_wv_x = c8_vv_x;
    c8_wv_x = muDoubleScalarSin(c8_wv_x);
    c8_ki_a = c8_wi_y;
    c8_wi_b = c8_wv_x;
    c8_xi_y = c8_ki_a * c8_wi_b;
    c8_xv_x = c8_q[0] + c8_q[1];
    c8_yv_x = c8_xv_x;
    c8_yv_x = muDoubleScalarCos(c8_yv_x);
    c8_li_a = c8_xi_y;
    c8_xi_b = c8_yv_x;
    c8_yi_y = c8_li_a * c8_xi_b;
    c8_aw_x = c8_q[0] + c8_q[1];
    c8_bw_x = c8_aw_x;
    c8_bw_x = muDoubleScalarSin(c8_bw_x);
    c8_mi_a = c8_yi_y;
    c8_yi_b = c8_bw_x;
    c8_aj_y = c8_mi_a * c8_yi_b;
    c8_cw_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_dw_x = c8_cw_x;
    c8_dw_x = muDoubleScalarSin(c8_dw_x);
    c8_aj_b = c8_dw_x;
    c8_bj_y = 2.0 * c8_aj_b;
    c8_ew_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_fw_x = c8_ew_x;
    c8_fw_x = muDoubleScalarCos(c8_fw_x);
    c8_ni_a = c8_bj_y;
    c8_bj_b = c8_fw_x;
    c8_cj_y = c8_ni_a * c8_bj_b;
    c8_gw_x = c8_q[0] + c8_q[1];
    c8_hw_x = c8_gw_x;
    c8_hw_x = muDoubleScalarSin(c8_hw_x);
    c8_oi_a = c8_cj_y;
    c8_cj_b = c8_hw_x;
    c8_dj_y = c8_oi_a * c8_cj_b;
    c8_iw_x = c8_q[0] + c8_q[1];
    c8_jw_x = c8_iw_x;
    c8_jw_x = muDoubleScalarCos(c8_jw_x);
    c8_pi_a = c8_dj_y;
    c8_dj_b = c8_jw_x;
    c8_ej_y = c8_pi_a * c8_dj_b;
    c8_kw_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_lw_x = c8_kw_x;
    c8_lw_x = muDoubleScalarSin(c8_lw_x);
    c8_ej_b = c8_lw_x;
    c8_fj_y = 2.0 * c8_ej_b;
    c8_mw_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_nw_x = c8_mw_x;
    c8_nw_x = muDoubleScalarSin(c8_nw_x);
    c8_qi_a = c8_fj_y;
    c8_fj_b = c8_nw_x;
    c8_gj_y = c8_qi_a * c8_fj_b;
    c8_ow_x = c8_q[0] + c8_q[1];
    c8_pw_x = c8_ow_x;
    c8_pw_x = muDoubleScalarCos(c8_pw_x);
    c8_ri_a = c8_gj_y;
    c8_gj_b = c8_pw_x;
    c8_hj_y = c8_ri_a * c8_gj_b;
    c8_qw_x = c8_q[0] + c8_q[1];
    c8_rw_x = c8_qw_x;
    c8_rw_x = muDoubleScalarCos(c8_rw_x);
    c8_si_a = c8_hj_y;
    c8_hj_b = c8_rw_x;
    c8_ij_y = c8_si_a * c8_hj_b;
    c8_ij_b = c8_mpower(chartInstance, ((((((((((((((((((((((((((c8_tf_y -
      c8_wf_y) + c8_ag_y) - c8_dg_y) + c8_gg_y) - c8_jg_y) - c8_mg_y) + c8_pg_y)
      - c8_sg_y) + c8_vg_y) + c8_yg_y) - c8_ch_y) - c8_fh_y) + c8_ih_y) +
      c8_lh_y) - c8_oh_y) - c8_rh_y) + c8_uh_y) + c8_xh_y) - c8_bi_y) - c8_fi_y)
      + c8_ji_y) + c8_ni_y) - c8_ri_y) + c8_vi_y) - c8_aj_y) - c8_ej_y) +
                        c8_ij_y);
    c8_jj_y = 2.0 * c8_ij_b;
    c8_b_A = -(((((((((((((((((((((((((((((((((((((((c8_q_y - c8_t_y) + c8_w_y)
      - c8_ab_y) + c8_db_y) - c8_gb_y) + c8_jb_y) - c8_mb_y) + c8_pb_y) -
      c8_sb_y) - c8_vb_y) + c8_yb_y) - c8_cc_y) + c8_fc_y) + c8_ic_y) - c8_lc_y)
      + c8_oc_y) - c8_rc_y) - c8_uc_y) + c8_xc_y) + c8_bd_y) - c8_ed_y) -
      c8_hd_y) + c8_kd_y) + c8_nd_y) - c8_qd_y) + c8_td_y) - c8_wd_y) + c8_be_y)
                         - c8_fe_y) + c8_je_y) - c8_ne_y) + c8_re_y) - c8_ve_y)
                    + c8_af_y) - c8_ef_y) + c8_hf_y) - c8_kf_y) + c8_nf_y) -
               c8_qf_y);
    c8_B = c8_jj_y;
    c8_sw_x = c8_b_A;
    c8_kj_y = c8_B;
    c8_tw_x = c8_sw_x;
    c8_lj_y = c8_kj_y;
    c8_mj_y = c8_tw_x / c8_lj_y;
    c8_uw_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_vw_x = c8_uw_x;
    c8_vw_x = muDoubleScalarCos(c8_vw_x);
    c8_ww_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_xw_x = c8_ww_x;
    c8_xw_x = muDoubleScalarCos(c8_xw_x);
    c8_ti_a = c8_vw_x;
    c8_jj_b = c8_xw_x;
    c8_nj_y = c8_ti_a * c8_jj_b;
    c8_yw_x = c8_q[0] + c8_q[1];
    c8_ax_x = c8_yw_x;
    c8_ax_x = muDoubleScalarCos(c8_ax_x);
    c8_ui_a = c8_nj_y;
    c8_kj_b = c8_ax_x;
    c8_oj_y = c8_ui_a * c8_kj_b;
    c8_bx_x = c8_q[0];
    c8_cx_x = c8_bx_x;
    c8_cx_x = muDoubleScalarSin(c8_cx_x);
    c8_vi_a = c8_oj_y;
    c8_lj_b = c8_cx_x;
    c8_pj_y = c8_vi_a * c8_lj_b;
    c8_dx_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ex_x = c8_dx_x;
    c8_ex_x = muDoubleScalarCos(c8_ex_x);
    c8_fx_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_gx_x = c8_fx_x;
    c8_gx_x = muDoubleScalarCos(c8_gx_x);
    c8_wi_a = c8_ex_x;
    c8_mj_b = c8_gx_x;
    c8_qj_y = c8_wi_a * c8_mj_b;
    c8_hx_x = c8_q[0] + c8_q[1];
    c8_ix_x = c8_hx_x;
    c8_ix_x = muDoubleScalarSin(c8_ix_x);
    c8_xi_a = c8_qj_y;
    c8_nj_b = c8_ix_x;
    c8_rj_y = c8_xi_a * c8_nj_b;
    c8_jx_x = c8_q[0];
    c8_kx_x = c8_jx_x;
    c8_kx_x = muDoubleScalarCos(c8_kx_x);
    c8_yi_a = c8_rj_y;
    c8_oj_b = c8_kx_x;
    c8_sj_y = c8_yi_a * c8_oj_b;
    c8_lx_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_mx_x = c8_lx_x;
    c8_mx_x = muDoubleScalarCos(c8_mx_x);
    c8_nx_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ox_x = c8_nx_x;
    c8_ox_x = muDoubleScalarSin(c8_ox_x);
    c8_aj_a = c8_mx_x;
    c8_pj_b = c8_ox_x;
    c8_tj_y = c8_aj_a * c8_pj_b;
    c8_px_x = c8_q[0] + c8_q[1];
    c8_qx_x = c8_px_x;
    c8_qx_x = muDoubleScalarCos(c8_qx_x);
    c8_bj_a = c8_tj_y;
    c8_qj_b = c8_qx_x;
    c8_uj_y = c8_bj_a * c8_qj_b;
    c8_rx_x = c8_q[0];
    c8_sx_x = c8_rx_x;
    c8_sx_x = muDoubleScalarCos(c8_sx_x);
    c8_cj_a = c8_uj_y;
    c8_rj_b = c8_sx_x;
    c8_vj_y = c8_cj_a * c8_rj_b;
    c8_tx_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ux_x = c8_tx_x;
    c8_ux_x = muDoubleScalarSin(c8_ux_x);
    c8_vx_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_wx_x = c8_vx_x;
    c8_wx_x = muDoubleScalarCos(c8_wx_x);
    c8_dj_a = c8_ux_x;
    c8_sj_b = c8_wx_x;
    c8_wj_y = c8_dj_a * c8_sj_b;
    c8_xx_x = c8_q[0] + c8_q[1];
    c8_yx_x = c8_xx_x;
    c8_yx_x = muDoubleScalarCos(c8_yx_x);
    c8_ej_a = c8_wj_y;
    c8_tj_b = c8_yx_x;
    c8_xj_y = c8_ej_a * c8_tj_b;
    c8_ay_x = c8_q[0];
    c8_by_x = c8_ay_x;
    c8_by_x = muDoubleScalarCos(c8_by_x);
    c8_fj_a = c8_xj_y;
    c8_uj_b = c8_by_x;
    c8_yj_y = c8_fj_a * c8_uj_b;
    c8_cy_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_dy_x = c8_cy_x;
    c8_dy_x = muDoubleScalarSin(c8_dy_x);
    c8_ey_x = c8_q[0];
    c8_fy_x = c8_ey_x;
    c8_fy_x = muDoubleScalarCos(c8_fy_x);
    c8_gj_a = c8_dy_x;
    c8_vj_b = c8_fy_x;
    c8_ak_y = c8_gj_a * c8_vj_b;
    c8_gy_x = c8_q[0] + c8_q[1];
    c8_hy_x = c8_gy_x;
    c8_hy_x = muDoubleScalarSin(c8_hy_x);
    c8_hj_a = c8_ak_y;
    c8_wj_b = c8_hy_x;
    c8_bk_y = c8_hj_a * c8_wj_b;
    c8_iy_x = c8_q[0];
    c8_jy_x = c8_iy_x;
    c8_jy_x = muDoubleScalarSin(c8_jy_x);
    c8_ij_a = c8_bk_y;
    c8_xj_b = c8_jy_x;
    c8_ck_y = c8_ij_a * c8_xj_b;
    c8_ky_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ly_x = c8_ky_x;
    c8_ly_x = muDoubleScalarSin(c8_ly_x);
    c8_my_x = c8_q[0];
    c8_ny_x = c8_my_x;
    c8_ny_x = muDoubleScalarSin(c8_ny_x);
    c8_jj_a = c8_ly_x;
    c8_yj_b = c8_ny_x;
    c8_dk_y = c8_jj_a * c8_yj_b;
    c8_oy_x = c8_q[0] + c8_q[1];
    c8_py_x = c8_oy_x;
    c8_py_x = muDoubleScalarCos(c8_py_x);
    c8_kj_a = c8_dk_y;
    c8_ak_b = c8_py_x;
    c8_ek_y = c8_kj_a * c8_ak_b;
    c8_qy_x = c8_q[0];
    c8_ry_x = c8_qy_x;
    c8_ry_x = muDoubleScalarSin(c8_ry_x);
    c8_lj_a = c8_ek_y;
    c8_bk_b = c8_ry_x;
    c8_fk_y = c8_lj_a * c8_bk_b;
    c8_sy_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ty_x = c8_sy_x;
    c8_ty_x = muDoubleScalarCos(c8_ty_x);
    c8_uy_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_vy_x = c8_uy_x;
    c8_vy_x = muDoubleScalarSin(c8_vy_x);
    c8_mj_a = c8_ty_x;
    c8_ck_b = c8_vy_x;
    c8_gk_y = c8_mj_a * c8_ck_b;
    c8_wy_x = c8_q[0] + c8_q[1];
    c8_xy_x = c8_wy_x;
    c8_xy_x = muDoubleScalarSin(c8_xy_x);
    c8_nj_a = c8_gk_y;
    c8_dk_b = c8_xy_x;
    c8_hk_y = c8_nj_a * c8_dk_b;
    c8_yy_x = c8_q[0];
    c8_aab_x = c8_yy_x;
    c8_aab_x = muDoubleScalarSin(c8_aab_x);
    c8_oj_a = c8_hk_y;
    c8_ek_b = c8_aab_x;
    c8_ik_y = c8_oj_a * c8_ek_b;
    c8_bab_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_cab_x = c8_bab_x;
    c8_cab_x = muDoubleScalarSin(c8_cab_x);
    c8_dab_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_eab_x = c8_dab_x;
    c8_eab_x = muDoubleScalarCos(c8_eab_x);
    c8_pj_a = c8_cab_x;
    c8_fk_b = c8_eab_x;
    c8_jk_y = c8_pj_a * c8_fk_b;
    c8_fab_x = c8_q[0] + c8_q[1];
    c8_gab_x = c8_fab_x;
    c8_gab_x = muDoubleScalarSin(c8_gab_x);
    c8_qj_a = c8_jk_y;
    c8_gk_b = c8_gab_x;
    c8_kk_y = c8_qj_a * c8_gk_b;
    c8_hab_x = c8_q[0];
    c8_iab_x = c8_hab_x;
    c8_iab_x = muDoubleScalarSin(c8_iab_x);
    c8_rj_a = c8_kk_y;
    c8_hk_b = c8_iab_x;
    c8_lk_y = c8_rj_a * c8_hk_b;
    c8_jab_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_kab_x = c8_jab_x;
    c8_kab_x = muDoubleScalarSin(c8_kab_x);
    c8_lab_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_mab_x = c8_lab_x;
    c8_mab_x = muDoubleScalarSin(c8_mab_x);
    c8_sj_a = c8_kab_x;
    c8_ik_b = c8_mab_x;
    c8_mk_y = c8_sj_a * c8_ik_b;
    c8_nab_x = c8_q[0] + c8_q[1];
    c8_oab_x = c8_nab_x;
    c8_oab_x = muDoubleScalarCos(c8_oab_x);
    c8_tj_a = c8_mk_y;
    c8_jk_b = c8_oab_x;
    c8_nk_y = c8_tj_a * c8_jk_b;
    c8_pab_x = c8_q[0];
    c8_qab_x = c8_pab_x;
    c8_qab_x = muDoubleScalarSin(c8_qab_x);
    c8_uj_a = c8_nk_y;
    c8_kk_b = c8_qab_x;
    c8_ok_y = c8_uj_a * c8_kk_b;
    c8_rab_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_sab_x = c8_rab_x;
    c8_sab_x = muDoubleScalarSin(c8_sab_x);
    c8_tab_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_uab_x = c8_tab_x;
    c8_uab_x = muDoubleScalarSin(c8_uab_x);
    c8_vj_a = c8_sab_x;
    c8_lk_b = c8_uab_x;
    c8_pk_y = c8_vj_a * c8_lk_b;
    c8_vab_x = c8_q[0] + c8_q[1];
    c8_wab_x = c8_vab_x;
    c8_wab_x = muDoubleScalarSin(c8_wab_x);
    c8_wj_a = c8_pk_y;
    c8_mk_b = c8_wab_x;
    c8_qk_y = c8_wj_a * c8_mk_b;
    c8_xab_x = c8_q[0];
    c8_yab_x = c8_xab_x;
    c8_yab_x = muDoubleScalarCos(c8_yab_x);
    c8_xj_a = c8_qk_y;
    c8_nk_b = c8_yab_x;
    c8_rk_y = c8_xj_a * c8_nk_b;
    c8_abb_x = c8_q[0];
    c8_bbb_x = c8_abb_x;
    c8_bbb_x = muDoubleScalarCos(c8_bbb_x);
    c8_cbb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_dbb_x = c8_cbb_x;
    c8_dbb_x = muDoubleScalarCos(c8_dbb_x);
    c8_yj_a = c8_bbb_x;
    c8_ok_b = c8_dbb_x;
    c8_sk_y = c8_yj_a * c8_ok_b;
    c8_ebb_x = c8_q[0] + c8_q[1];
    c8_fbb_x = c8_ebb_x;
    c8_fbb_x = muDoubleScalarCos(c8_fbb_x);
    c8_ak_a = c8_sk_y;
    c8_pk_b = c8_fbb_x;
    c8_tk_y = c8_ak_a * c8_pk_b;
    c8_gbb_x = c8_q[0];
    c8_hbb_x = c8_gbb_x;
    c8_hbb_x = muDoubleScalarSin(c8_hbb_x);
    c8_bk_a = c8_tk_y;
    c8_qk_b = c8_hbb_x;
    c8_uk_y = c8_bk_a * c8_qk_b;
    c8_ibb_x = c8_q[0];
    c8_jbb_x = c8_ibb_x;
    c8_jbb_x = muDoubleScalarCos(c8_jbb_x);
    c8_kbb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_lbb_x = c8_kbb_x;
    c8_lbb_x = muDoubleScalarCos(c8_lbb_x);
    c8_ck_a = c8_jbb_x;
    c8_rk_b = c8_lbb_x;
    c8_vk_y = c8_ck_a * c8_rk_b;
    c8_mbb_x = c8_q[0] + c8_q[1];
    c8_nbb_x = c8_mbb_x;
    c8_nbb_x = muDoubleScalarSin(c8_nbb_x);
    c8_dk_a = c8_vk_y;
    c8_sk_b = c8_nbb_x;
    c8_wk_y = c8_dk_a * c8_sk_b;
    c8_obb_x = c8_q[0];
    c8_pbb_x = c8_obb_x;
    c8_pbb_x = muDoubleScalarCos(c8_pbb_x);
    c8_ek_a = c8_wk_y;
    c8_tk_b = c8_pbb_x;
    c8_xk_y = c8_ek_a * c8_tk_b;
    c8_qbb_x = c8_q[0];
    c8_rbb_x = c8_qbb_x;
    c8_rbb_x = muDoubleScalarSin(c8_rbb_x);
    c8_sbb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_tbb_x = c8_sbb_x;
    c8_tbb_x = muDoubleScalarSin(c8_tbb_x);
    c8_fk_a = c8_rbb_x;
    c8_uk_b = c8_tbb_x;
    c8_yk_y = c8_fk_a * c8_uk_b;
    c8_ubb_x = c8_q[0] + c8_q[1];
    c8_vbb_x = c8_ubb_x;
    c8_vbb_x = muDoubleScalarCos(c8_vbb_x);
    c8_gk_a = c8_yk_y;
    c8_vk_b = c8_vbb_x;
    c8_al_y = c8_gk_a * c8_vk_b;
    c8_wbb_x = c8_q[0];
    c8_xbb_x = c8_wbb_x;
    c8_xbb_x = muDoubleScalarSin(c8_xbb_x);
    c8_hk_a = c8_al_y;
    c8_wk_b = c8_xbb_x;
    c8_bl_y = c8_hk_a * c8_wk_b;
    c8_ybb_x = c8_q[0];
    c8_acb_x = c8_ybb_x;
    c8_acb_x = muDoubleScalarSin(c8_acb_x);
    c8_bcb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ccb_x = c8_bcb_x;
    c8_ccb_x = muDoubleScalarSin(c8_ccb_x);
    c8_ik_a = c8_acb_x;
    c8_xk_b = c8_ccb_x;
    c8_cl_y = c8_ik_a * c8_xk_b;
    c8_dcb_x = c8_q[0] + c8_q[1];
    c8_ecb_x = c8_dcb_x;
    c8_ecb_x = muDoubleScalarSin(c8_ecb_x);
    c8_jk_a = c8_cl_y;
    c8_yk_b = c8_ecb_x;
    c8_dl_y = c8_jk_a * c8_yk_b;
    c8_fcb_x = c8_q[0];
    c8_gcb_x = c8_fcb_x;
    c8_gcb_x = muDoubleScalarCos(c8_gcb_x);
    c8_kk_a = c8_dl_y;
    c8_al_b = c8_gcb_x;
    c8_el_y = c8_kk_a * c8_al_b;
    c8_hcb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_icb_x = c8_hcb_x;
    c8_icb_x = muDoubleScalarCos(c8_icb_x);
    c8_jcb_x = c8_q[0];
    c8_kcb_x = c8_jcb_x;
    c8_kcb_x = muDoubleScalarCos(c8_kcb_x);
    c8_lk_a = c8_icb_x;
    c8_bl_b = c8_kcb_x;
    c8_fl_y = c8_lk_a * c8_bl_b;
    c8_lcb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_mcb_x = c8_lcb_x;
    c8_mcb_x = muDoubleScalarCos(c8_mcb_x);
    c8_mk_a = c8_fl_y;
    c8_cl_b = c8_mcb_x;
    c8_gl_y = c8_mk_a * c8_cl_b;
    c8_ncb_x = c8_q[0] + c8_q[1];
    c8_ocb_x = c8_ncb_x;
    c8_ocb_x = muDoubleScalarSin(c8_ocb_x);
    c8_nk_a = c8_gl_y;
    c8_dl_b = c8_ocb_x;
    c8_hl_y = c8_nk_a * c8_dl_b;
    c8_pcb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_qcb_x = c8_pcb_x;
    c8_qcb_x = muDoubleScalarCos(c8_qcb_x);
    c8_rcb_x = c8_q[0];
    c8_scb_x = c8_rcb_x;
    c8_scb_x = muDoubleScalarCos(c8_scb_x);
    c8_ok_a = c8_qcb_x;
    c8_el_b = c8_scb_x;
    c8_il_y = c8_ok_a * c8_el_b;
    c8_tcb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ucb_x = c8_tcb_x;
    c8_ucb_x = muDoubleScalarSin(c8_ucb_x);
    c8_pk_a = c8_il_y;
    c8_fl_b = c8_ucb_x;
    c8_jl_y = c8_pk_a * c8_fl_b;
    c8_vcb_x = c8_q[0] + c8_q[1];
    c8_wcb_x = c8_vcb_x;
    c8_wcb_x = muDoubleScalarCos(c8_wcb_x);
    c8_qk_a = c8_jl_y;
    c8_gl_b = c8_wcb_x;
    c8_kl_y = c8_qk_a * c8_gl_b;
    c8_xcb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ycb_x = c8_xcb_x;
    c8_ycb_x = muDoubleScalarCos(c8_ycb_x);
    c8_adb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_bdb_x = c8_adb_x;
    c8_bdb_x = muDoubleScalarCos(c8_bdb_x);
    c8_rk_a = c8_ycb_x;
    c8_hl_b = c8_bdb_x;
    c8_ll_y = c8_rk_a * c8_hl_b;
    c8_cdb_x = c8_q[0];
    c8_ddb_x = c8_cdb_x;
    c8_ddb_x = muDoubleScalarSin(c8_ddb_x);
    c8_sk_a = c8_ll_y;
    c8_il_b = c8_ddb_x;
    c8_ml_y = c8_sk_a * c8_il_b;
    c8_edb_x = c8_q[0] + c8_q[1];
    c8_fdb_x = c8_edb_x;
    c8_fdb_x = muDoubleScalarCos(c8_fdb_x);
    c8_tk_a = c8_ml_y;
    c8_jl_b = c8_fdb_x;
    c8_nl_y = c8_tk_a * c8_jl_b;
    c8_gdb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_hdb_x = c8_gdb_x;
    c8_hdb_x = muDoubleScalarSin(c8_hdb_x);
    c8_idb_x = c8_q[0];
    c8_jdb_x = c8_idb_x;
    c8_jdb_x = muDoubleScalarCos(c8_jdb_x);
    c8_uk_a = c8_hdb_x;
    c8_kl_b = c8_jdb_x;
    c8_ol_y = c8_uk_a * c8_kl_b;
    c8_kdb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ldb_x = c8_kdb_x;
    c8_ldb_x = muDoubleScalarCos(c8_ldb_x);
    c8_vk_a = c8_ol_y;
    c8_ll_b = c8_ldb_x;
    c8_pl_y = c8_vk_a * c8_ll_b;
    c8_mdb_x = c8_q[0] + c8_q[1];
    c8_ndb_x = c8_mdb_x;
    c8_ndb_x = muDoubleScalarCos(c8_ndb_x);
    c8_wk_a = c8_pl_y;
    c8_ml_b = c8_ndb_x;
    c8_ql_y = c8_wk_a * c8_ml_b;
    c8_odb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_pdb_x = c8_odb_x;
    c8_pdb_x = muDoubleScalarCos(c8_pdb_x);
    c8_qdb_x = c8_q[0];
    c8_rdb_x = c8_qdb_x;
    c8_rdb_x = muDoubleScalarSin(c8_rdb_x);
    c8_xk_a = c8_pdb_x;
    c8_nl_b = c8_rdb_x;
    c8_rl_y = c8_xk_a * c8_nl_b;
    c8_sdb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_tdb_x = c8_sdb_x;
    c8_tdb_x = muDoubleScalarSin(c8_tdb_x);
    c8_yk_a = c8_rl_y;
    c8_ol_b = c8_tdb_x;
    c8_sl_y = c8_yk_a * c8_ol_b;
    c8_udb_x = c8_q[0] + c8_q[1];
    c8_vdb_x = c8_udb_x;
    c8_vdb_x = muDoubleScalarSin(c8_vdb_x);
    c8_al_a = c8_sl_y;
    c8_pl_b = c8_vdb_x;
    c8_tl_y = c8_al_a * c8_pl_b;
    c8_wdb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_xdb_x = c8_wdb_x;
    c8_xdb_x = muDoubleScalarSin(c8_xdb_x);
    c8_ydb_x = c8_q[0];
    c8_aeb_x = c8_ydb_x;
    c8_aeb_x = muDoubleScalarCos(c8_aeb_x);
    c8_bl_a = c8_xdb_x;
    c8_ql_b = c8_aeb_x;
    c8_ul_y = c8_bl_a * c8_ql_b;
    c8_beb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ceb_x = c8_beb_x;
    c8_ceb_x = muDoubleScalarSin(c8_ceb_x);
    c8_cl_a = c8_ul_y;
    c8_rl_b = c8_ceb_x;
    c8_vl_y = c8_cl_a * c8_rl_b;
    c8_deb_x = c8_q[0] + c8_q[1];
    c8_eeb_x = c8_deb_x;
    c8_eeb_x = muDoubleScalarSin(c8_eeb_x);
    c8_dl_a = c8_vl_y;
    c8_sl_b = c8_eeb_x;
    c8_wl_y = c8_dl_a * c8_sl_b;
    c8_feb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_geb_x = c8_feb_x;
    c8_geb_x = muDoubleScalarSin(c8_geb_x);
    c8_heb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ieb_x = c8_heb_x;
    c8_ieb_x = muDoubleScalarCos(c8_ieb_x);
    c8_el_a = c8_geb_x;
    c8_tl_b = c8_ieb_x;
    c8_xl_y = c8_el_a * c8_tl_b;
    c8_jeb_x = c8_q[0];
    c8_keb_x = c8_jeb_x;
    c8_keb_x = muDoubleScalarSin(c8_keb_x);
    c8_fl_a = c8_xl_y;
    c8_ul_b = c8_keb_x;
    c8_yl_y = c8_fl_a * c8_ul_b;
    c8_leb_x = c8_q[0] + c8_q[1];
    c8_meb_x = c8_leb_x;
    c8_meb_x = muDoubleScalarSin(c8_meb_x);
    c8_gl_a = c8_yl_y;
    c8_vl_b = c8_meb_x;
    c8_am_y = c8_gl_a * c8_vl_b;
    c8_neb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_oeb_x = c8_neb_x;
    c8_oeb_x = muDoubleScalarSin(c8_oeb_x);
    c8_peb_x = c8_q[0];
    c8_qeb_x = c8_peb_x;
    c8_qeb_x = muDoubleScalarSin(c8_qeb_x);
    c8_hl_a = c8_oeb_x;
    c8_wl_b = c8_qeb_x;
    c8_bm_y = c8_hl_a * c8_wl_b;
    c8_reb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_seb_x = c8_reb_x;
    c8_seb_x = muDoubleScalarSin(c8_seb_x);
    c8_il_a = c8_bm_y;
    c8_xl_b = c8_seb_x;
    c8_cm_y = c8_il_a * c8_xl_b;
    c8_teb_x = c8_q[0] + c8_q[1];
    c8_ueb_x = c8_teb_x;
    c8_ueb_x = muDoubleScalarCos(c8_ueb_x);
    c8_jl_a = c8_cm_y;
    c8_yl_b = c8_ueb_x;
    c8_dm_y = c8_jl_a * c8_yl_b;
    c8_veb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_web_x = c8_veb_x;
    c8_web_x = muDoubleScalarCos(c8_web_x);
    c8_am_b = c8_web_x;
    c8_em_y = 2.0 * c8_am_b;
    c8_xeb_x = c8_q[0];
    c8_yeb_x = c8_xeb_x;
    c8_yeb_x = muDoubleScalarCos(c8_yeb_x);
    c8_kl_a = c8_em_y;
    c8_bm_b = c8_yeb_x;
    c8_fm_y = c8_kl_a * c8_bm_b;
    c8_afb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_bfb_x = c8_afb_x;
    c8_bfb_x = muDoubleScalarCos(c8_bfb_x);
    c8_ll_a = c8_fm_y;
    c8_cm_b = c8_bfb_x;
    c8_gm_y = c8_ll_a * c8_cm_b;
    c8_cfb_x = c8_q[0];
    c8_dfb_x = c8_cfb_x;
    c8_dfb_x = muDoubleScalarSin(c8_dfb_x);
    c8_ml_a = c8_gm_y;
    c8_dm_b = c8_dfb_x;
    c8_hm_y = c8_ml_a * c8_dm_b;
    c8_efb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ffb_x = c8_efb_x;
    c8_ffb_x = muDoubleScalarCos(c8_ffb_x);
    c8_em_b = c8_ffb_x;
    c8_im_y = 2.0 * c8_em_b;
    c8_gfb_x = c8_q[0];
    c8_hfb_x = c8_gfb_x;
    c8_hfb_x = muDoubleScalarCos(c8_hfb_x);
    c8_nl_a = c8_im_y;
    c8_fm_b = c8_hfb_x;
    c8_jm_y = c8_nl_a * c8_fm_b;
    c8_ifb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_jfb_x = c8_ifb_x;
    c8_jfb_x = muDoubleScalarSin(c8_jfb_x);
    c8_ol_a = c8_jm_y;
    c8_gm_b = c8_jfb_x;
    c8_km_y = c8_ol_a * c8_gm_b;
    c8_kfb_x = c8_q[0];
    c8_lfb_x = c8_kfb_x;
    c8_lfb_x = muDoubleScalarCos(c8_lfb_x);
    c8_pl_a = c8_km_y;
    c8_hm_b = c8_lfb_x;
    c8_lm_y = c8_pl_a * c8_hm_b;
    c8_mfb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_nfb_x = c8_mfb_x;
    c8_nfb_x = muDoubleScalarCos(c8_nfb_x);
    c8_im_b = c8_nfb_x;
    c8_mm_y = 2.0 * c8_im_b;
    c8_ofb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_pfb_x = c8_ofb_x;
    c8_pfb_x = muDoubleScalarCos(c8_pfb_x);
    c8_ql_a = c8_mm_y;
    c8_jm_b = c8_pfb_x;
    c8_nm_y = c8_ql_a * c8_jm_b;
    c8_qfb_x = c8_q[0];
    c8_rfb_x = c8_qfb_x;
    c8_rfb_x = muDoubleScalarSin(c8_rfb_x);
    c8_rl_a = c8_nm_y;
    c8_km_b = c8_rfb_x;
    c8_om_y = c8_rl_a * c8_km_b;
    c8_sfb_x = c8_q[0];
    c8_tfb_x = c8_sfb_x;
    c8_tfb_x = muDoubleScalarCos(c8_tfb_x);
    c8_sl_a = c8_om_y;
    c8_lm_b = c8_tfb_x;
    c8_pm_y = c8_sl_a * c8_lm_b;
    c8_ufb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_vfb_x = c8_ufb_x;
    c8_vfb_x = muDoubleScalarSin(c8_vfb_x);
    c8_mm_b = c8_vfb_x;
    c8_qm_y = 2.0 * c8_mm_b;
    c8_wfb_x = c8_q[0];
    c8_xfb_x = c8_wfb_x;
    c8_xfb_x = muDoubleScalarCos(c8_xfb_x);
    c8_tl_a = c8_qm_y;
    c8_nm_b = c8_xfb_x;
    c8_rm_y = c8_tl_a * c8_nm_b;
    c8_yfb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_agb_x = c8_yfb_x;
    c8_agb_x = muDoubleScalarCos(c8_agb_x);
    c8_ul_a = c8_rm_y;
    c8_om_b = c8_agb_x;
    c8_sm_y = c8_ul_a * c8_om_b;
    c8_bgb_x = c8_q[0];
    c8_cgb_x = c8_bgb_x;
    c8_cgb_x = muDoubleScalarCos(c8_cgb_x);
    c8_vl_a = c8_sm_y;
    c8_pm_b = c8_cgb_x;
    c8_tm_y = c8_vl_a * c8_pm_b;
    c8_dgb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_egb_x = c8_dgb_x;
    c8_egb_x = muDoubleScalarCos(c8_egb_x);
    c8_qm_b = c8_egb_x;
    c8_um_y = 2.0 * c8_qm_b;
    c8_fgb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ggb_x = c8_fgb_x;
    c8_ggb_x = muDoubleScalarCos(c8_ggb_x);
    c8_wl_a = c8_um_y;
    c8_rm_b = c8_ggb_x;
    c8_vm_y = c8_wl_a * c8_rm_b;
    c8_hgb_x = c8_q[0] + c8_q[1];
    c8_igb_x = c8_hgb_x;
    c8_igb_x = muDoubleScalarCos(c8_igb_x);
    c8_xl_a = c8_vm_y;
    c8_sm_b = c8_igb_x;
    c8_wm_y = c8_xl_a * c8_sm_b;
    c8_jgb_x = c8_q[0] + c8_q[1];
    c8_kgb_x = c8_jgb_x;
    c8_kgb_x = muDoubleScalarSin(c8_kgb_x);
    c8_yl_a = c8_wm_y;
    c8_tm_b = c8_kgb_x;
    c8_xm_y = c8_yl_a * c8_tm_b;
    c8_lgb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_mgb_x = c8_lgb_x;
    c8_mgb_x = muDoubleScalarCos(c8_mgb_x);
    c8_um_b = c8_mgb_x;
    c8_ym_y = 2.0 * c8_um_b;
    c8_ngb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ogb_x = c8_ngb_x;
    c8_ogb_x = muDoubleScalarCos(c8_ogb_x);
    c8_am_a = c8_ym_y;
    c8_vm_b = c8_ogb_x;
    c8_an_y = c8_am_a * c8_vm_b;
    c8_pgb_x = c8_q[0] + c8_q[1];
    c8_qgb_x = c8_pgb_x;
    c8_qgb_x = muDoubleScalarSin(c8_qgb_x);
    c8_bm_a = c8_an_y;
    c8_wm_b = c8_qgb_x;
    c8_bn_y = c8_bm_a * c8_wm_b;
    c8_rgb_x = c8_q[0] + c8_q[1];
    c8_sgb_x = c8_rgb_x;
    c8_sgb_x = muDoubleScalarCos(c8_sgb_x);
    c8_cm_a = c8_bn_y;
    c8_xm_b = c8_sgb_x;
    c8_cn_y = c8_cm_a * c8_xm_b;
    c8_tgb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ugb_x = c8_tgb_x;
    c8_ugb_x = muDoubleScalarCos(c8_ugb_x);
    c8_ym_b = c8_ugb_x;
    c8_dn_y = 2.0 * c8_ym_b;
    c8_vgb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_wgb_x = c8_vgb_x;
    c8_wgb_x = muDoubleScalarSin(c8_wgb_x);
    c8_dm_a = c8_dn_y;
    c8_an_b = c8_wgb_x;
    c8_en_y = c8_dm_a * c8_an_b;
    c8_xgb_x = c8_q[0] + c8_q[1];
    c8_ygb_x = c8_xgb_x;
    c8_ygb_x = muDoubleScalarCos(c8_ygb_x);
    c8_em_a = c8_en_y;
    c8_bn_b = c8_ygb_x;
    c8_fn_y = c8_em_a * c8_bn_b;
    c8_ahb_x = c8_q[0] + c8_q[1];
    c8_bhb_x = c8_ahb_x;
    c8_bhb_x = muDoubleScalarCos(c8_bhb_x);
    c8_fm_a = c8_fn_y;
    c8_cn_b = c8_bhb_x;
    c8_gn_y = c8_fm_a * c8_cn_b;
    c8_chb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_dhb_x = c8_chb_x;
    c8_dhb_x = muDoubleScalarSin(c8_dhb_x);
    c8_dn_b = c8_dhb_x;
    c8_hn_y = 2.0 * c8_dn_b;
    c8_ehb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_fhb_x = c8_ehb_x;
    c8_fhb_x = muDoubleScalarCos(c8_fhb_x);
    c8_gm_a = c8_hn_y;
    c8_en_b = c8_fhb_x;
    c8_in_y = c8_gm_a * c8_en_b;
    c8_ghb_x = c8_q[0] + c8_q[1];
    c8_hhb_x = c8_ghb_x;
    c8_hhb_x = muDoubleScalarCos(c8_hhb_x);
    c8_hm_a = c8_in_y;
    c8_fn_b = c8_hhb_x;
    c8_jn_y = c8_hm_a * c8_fn_b;
    c8_ihb_x = c8_q[0] + c8_q[1];
    c8_jhb_x = c8_ihb_x;
    c8_jhb_x = muDoubleScalarCos(c8_jhb_x);
    c8_im_a = c8_jn_y;
    c8_gn_b = c8_jhb_x;
    c8_kn_y = c8_im_a * c8_gn_b;
    c8_khb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_lhb_x = c8_khb_x;
    c8_lhb_x = muDoubleScalarCos(c8_lhb_x);
    c8_hn_b = c8_lhb_x;
    c8_ln_y = 2.0 * c8_hn_b;
    c8_mhb_x = c8_q[0];
    c8_nhb_x = c8_mhb_x;
    c8_nhb_x = muDoubleScalarSin(c8_nhb_x);
    c8_jm_a = c8_ln_y;
    c8_in_b = c8_nhb_x;
    c8_mn_y = c8_jm_a * c8_in_b;
    c8_ohb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_phb_x = c8_ohb_x;
    c8_phb_x = muDoubleScalarSin(c8_phb_x);
    c8_km_a = c8_mn_y;
    c8_jn_b = c8_phb_x;
    c8_nn_y = c8_km_a * c8_jn_b;
    c8_qhb_x = c8_q[0];
    c8_rhb_x = c8_qhb_x;
    c8_rhb_x = muDoubleScalarSin(c8_rhb_x);
    c8_lm_a = c8_nn_y;
    c8_kn_b = c8_rhb_x;
    c8_on_y = c8_lm_a * c8_kn_b;
    c8_shb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_thb_x = c8_shb_x;
    c8_thb_x = muDoubleScalarSin(c8_thb_x);
    c8_ln_b = c8_thb_x;
    c8_pn_y = 2.0 * c8_ln_b;
    c8_uhb_x = c8_q[0];
    c8_vhb_x = c8_uhb_x;
    c8_vhb_x = muDoubleScalarCos(c8_vhb_x);
    c8_mm_a = c8_pn_y;
    c8_mn_b = c8_vhb_x;
    c8_qn_y = c8_mm_a * c8_mn_b;
    c8_whb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_xhb_x = c8_whb_x;
    c8_xhb_x = muDoubleScalarSin(c8_xhb_x);
    c8_nm_a = c8_qn_y;
    c8_nn_b = c8_xhb_x;
    c8_rn_y = c8_nm_a * c8_nn_b;
    c8_yhb_x = c8_q[0];
    c8_aib_x = c8_yhb_x;
    c8_aib_x = muDoubleScalarSin(c8_aib_x);
    c8_om_a = c8_rn_y;
    c8_on_b = c8_aib_x;
    c8_sn_y = c8_om_a * c8_on_b;
    c8_bib_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_cib_x = c8_bib_x;
    c8_cib_x = muDoubleScalarSin(c8_cib_x);
    c8_pn_b = c8_cib_x;
    c8_tn_y = 2.0 * c8_pn_b;
    c8_dib_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_eib_x = c8_dib_x;
    c8_eib_x = muDoubleScalarCos(c8_eib_x);
    c8_pm_a = c8_tn_y;
    c8_qn_b = c8_eib_x;
    c8_un_y = c8_pm_a * c8_qn_b;
    c8_fib_x = c8_q[0];
    c8_gib_x = c8_fib_x;
    c8_gib_x = muDoubleScalarSin(c8_gib_x);
    c8_qm_a = c8_un_y;
    c8_rn_b = c8_gib_x;
    c8_vn_y = c8_qm_a * c8_rn_b;
    c8_hib_x = c8_q[0];
    c8_iib_x = c8_hib_x;
    c8_iib_x = muDoubleScalarSin(c8_iib_x);
    c8_rm_a = c8_vn_y;
    c8_sn_b = c8_iib_x;
    c8_wn_y = c8_rm_a * c8_sn_b;
    c8_jib_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_kib_x = c8_jib_x;
    c8_kib_x = muDoubleScalarSin(c8_kib_x);
    c8_tn_b = c8_kib_x;
    c8_xn_y = 2.0 * c8_tn_b;
    c8_lib_x = c8_q[0];
    c8_mib_x = c8_lib_x;
    c8_mib_x = muDoubleScalarSin(c8_mib_x);
    c8_sm_a = c8_xn_y;
    c8_un_b = c8_mib_x;
    c8_yn_y = c8_sm_a * c8_un_b;
    c8_nib_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_oib_x = c8_nib_x;
    c8_oib_x = muDoubleScalarSin(c8_oib_x);
    c8_tm_a = c8_yn_y;
    c8_vn_b = c8_oib_x;
    c8_ao_y = c8_tm_a * c8_vn_b;
    c8_pib_x = c8_q[0];
    c8_qib_x = c8_pib_x;
    c8_qib_x = muDoubleScalarCos(c8_qib_x);
    c8_um_a = c8_ao_y;
    c8_wn_b = c8_qib_x;
    c8_bo_y = c8_um_a * c8_wn_b;
    c8_rib_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_sib_x = c8_rib_x;
    c8_sib_x = muDoubleScalarCos(c8_sib_x);
    c8_xn_b = c8_sib_x;
    c8_co_y = 2.0 * c8_xn_b;
    c8_tib_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_uib_x = c8_tib_x;
    c8_uib_x = muDoubleScalarSin(c8_uib_x);
    c8_vm_a = c8_co_y;
    c8_yn_b = c8_uib_x;
    c8_do_y = c8_vm_a * c8_yn_b;
    c8_vib_x = c8_q[0] + c8_q[1];
    c8_wib_x = c8_vib_x;
    c8_wib_x = muDoubleScalarSin(c8_wib_x);
    c8_wm_a = c8_do_y;
    c8_ao_b = c8_wib_x;
    c8_eo_y = c8_wm_a * c8_ao_b;
    c8_xib_x = c8_q[0] + c8_q[1];
    c8_yib_x = c8_xib_x;
    c8_yib_x = muDoubleScalarSin(c8_yib_x);
    c8_xm_a = c8_eo_y;
    c8_bo_b = c8_yib_x;
    c8_fo_y = c8_xm_a * c8_bo_b;
    c8_ajb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_bjb_x = c8_ajb_x;
    c8_bjb_x = muDoubleScalarSin(c8_bjb_x);
    c8_co_b = c8_bjb_x;
    c8_go_y = 2.0 * c8_co_b;
    c8_cjb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_djb_x = c8_cjb_x;
    c8_djb_x = muDoubleScalarCos(c8_djb_x);
    c8_ym_a = c8_go_y;
    c8_do_b = c8_djb_x;
    c8_ho_y = c8_ym_a * c8_do_b;
    c8_ejb_x = c8_q[0] + c8_q[1];
    c8_fjb_x = c8_ejb_x;
    c8_fjb_x = muDoubleScalarSin(c8_fjb_x);
    c8_an_a = c8_ho_y;
    c8_eo_b = c8_fjb_x;
    c8_io_y = c8_an_a * c8_eo_b;
    c8_gjb_x = c8_q[0] + c8_q[1];
    c8_hjb_x = c8_gjb_x;
    c8_hjb_x = muDoubleScalarSin(c8_hjb_x);
    c8_bn_a = c8_io_y;
    c8_fo_b = c8_hjb_x;
    c8_jo_y = c8_bn_a * c8_fo_b;
    c8_ijb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_jjb_x = c8_ijb_x;
    c8_jjb_x = muDoubleScalarSin(c8_jjb_x);
    c8_go_b = c8_jjb_x;
    c8_ko_y = 2.0 * c8_go_b;
    c8_kjb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ljb_x = c8_kjb_x;
    c8_ljb_x = muDoubleScalarSin(c8_ljb_x);
    c8_cn_a = c8_ko_y;
    c8_ho_b = c8_ljb_x;
    c8_lo_y = c8_cn_a * c8_ho_b;
    c8_mjb_x = c8_q[0] + c8_q[1];
    c8_njb_x = c8_mjb_x;
    c8_njb_x = muDoubleScalarCos(c8_njb_x);
    c8_dn_a = c8_lo_y;
    c8_io_b = c8_njb_x;
    c8_mo_y = c8_dn_a * c8_io_b;
    c8_ojb_x = c8_q[0] + c8_q[1];
    c8_pjb_x = c8_ojb_x;
    c8_pjb_x = muDoubleScalarSin(c8_pjb_x);
    c8_en_a = c8_mo_y;
    c8_jo_b = c8_pjb_x;
    c8_no_y = c8_en_a * c8_jo_b;
    c8_qjb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_rjb_x = c8_qjb_x;
    c8_rjb_x = muDoubleScalarSin(c8_rjb_x);
    c8_ko_b = c8_rjb_x;
    c8_oo_y = 2.0 * c8_ko_b;
    c8_sjb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_tjb_x = c8_sjb_x;
    c8_tjb_x = muDoubleScalarSin(c8_tjb_x);
    c8_fn_a = c8_oo_y;
    c8_lo_b = c8_tjb_x;
    c8_po_y = c8_fn_a * c8_lo_b;
    c8_ujb_x = c8_q[0] + c8_q[1];
    c8_vjb_x = c8_ujb_x;
    c8_vjb_x = muDoubleScalarSin(c8_vjb_x);
    c8_gn_a = c8_po_y;
    c8_mo_b = c8_vjb_x;
    c8_qo_y = c8_gn_a * c8_mo_b;
    c8_wjb_x = c8_q[0] + c8_q[1];
    c8_xjb_x = c8_wjb_x;
    c8_xjb_x = muDoubleScalarCos(c8_xjb_x);
    c8_hn_a = c8_qo_y;
    c8_no_b = c8_xjb_x;
    c8_ro_y = c8_hn_a * c8_no_b;
    c8_yjb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_akb_x = c8_yjb_x;
    c8_akb_x = muDoubleScalarCos(c8_akb_x);
    c8_bkb_x = c8_q[0];
    c8_ckb_x = c8_bkb_x;
    c8_ckb_x = muDoubleScalarCos(c8_ckb_x);
    c8_in_a = c8_akb_x;
    c8_oo_b = c8_ckb_x;
    c8_so_y = c8_in_a * c8_oo_b;
    c8_dkb_x = c8_q[0] + c8_q[1];
    c8_ekb_x = c8_dkb_x;
    c8_ekb_x = muDoubleScalarSin(c8_ekb_x);
    c8_jn_a = c8_so_y;
    c8_po_b = c8_ekb_x;
    c8_to_y = c8_jn_a * c8_po_b;
    c8_fkb_x = c8_q[0];
    c8_gkb_x = c8_fkb_x;
    c8_gkb_x = muDoubleScalarCos(c8_gkb_x);
    c8_kn_a = c8_to_y;
    c8_qo_b = c8_gkb_x;
    c8_uo_y = c8_kn_a * c8_qo_b;
    c8_hkb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ikb_x = c8_hkb_x;
    c8_ikb_x = muDoubleScalarCos(c8_ikb_x);
    c8_jkb_x = c8_q[0];
    c8_kkb_x = c8_jkb_x;
    c8_kkb_x = muDoubleScalarSin(c8_kkb_x);
    c8_ln_a = c8_ikb_x;
    c8_ro_b = c8_kkb_x;
    c8_vo_y = c8_ln_a * c8_ro_b;
    c8_lkb_x = c8_q[0] + c8_q[1];
    c8_mkb_x = c8_lkb_x;
    c8_mkb_x = muDoubleScalarCos(c8_mkb_x);
    c8_mn_a = c8_vo_y;
    c8_so_b = c8_mkb_x;
    c8_wo_y = c8_mn_a * c8_so_b;
    c8_nkb_x = c8_q[0];
    c8_okb_x = c8_nkb_x;
    c8_okb_x = muDoubleScalarCos(c8_okb_x);
    c8_nn_a = c8_wo_y;
    c8_to_b = c8_okb_x;
    c8_xo_y = c8_nn_a * c8_to_b;
    c8_pkb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_qkb_x = c8_pkb_x;
    c8_qkb_x = muDoubleScalarCos(c8_qkb_x);
    c8_rkb_x = c8_q[0];
    c8_skb_x = c8_rkb_x;
    c8_skb_x = muDoubleScalarSin(c8_skb_x);
    c8_on_a = c8_qkb_x;
    c8_uo_b = c8_skb_x;
    c8_yo_y = c8_on_a * c8_uo_b;
    c8_tkb_x = c8_q[0] + c8_q[1];
    c8_ukb_x = c8_tkb_x;
    c8_ukb_x = muDoubleScalarCos(c8_ukb_x);
    c8_pn_a = c8_yo_y;
    c8_vo_b = c8_ukb_x;
    c8_ap_y = c8_pn_a * c8_vo_b;
    c8_vkb_x = c8_q[0];
    c8_wkb_x = c8_vkb_x;
    c8_wkb_x = muDoubleScalarSin(c8_wkb_x);
    c8_qn_a = c8_ap_y;
    c8_wo_b = c8_wkb_x;
    c8_bp_y = c8_qn_a * c8_wo_b;
    c8_xkb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ykb_x = c8_xkb_x;
    c8_ykb_x = muDoubleScalarCos(c8_ykb_x);
    c8_alb_x = c8_q[0];
    c8_blb_x = c8_alb_x;
    c8_blb_x = muDoubleScalarCos(c8_blb_x);
    c8_rn_a = c8_ykb_x;
    c8_xo_b = c8_blb_x;
    c8_cp_y = c8_rn_a * c8_xo_b;
    c8_clb_x = c8_q[0] + c8_q[1];
    c8_dlb_x = c8_clb_x;
    c8_dlb_x = muDoubleScalarSin(c8_dlb_x);
    c8_sn_a = c8_cp_y;
    c8_yo_b = c8_dlb_x;
    c8_dp_y = c8_sn_a * c8_yo_b;
    c8_elb_x = c8_q[0];
    c8_flb_x = c8_elb_x;
    c8_flb_x = muDoubleScalarSin(c8_flb_x);
    c8_tn_a = c8_dp_y;
    c8_ap_b = c8_flb_x;
    c8_ep_y = c8_tn_a * c8_ap_b;
    c8_glb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_hlb_x = c8_glb_x;
    c8_hlb_x = muDoubleScalarSin(c8_hlb_x);
    c8_ilb_x = c8_q[0];
    c8_jlb_x = c8_ilb_x;
    c8_jlb_x = muDoubleScalarCos(c8_jlb_x);
    c8_un_a = c8_hlb_x;
    c8_bp_b = c8_jlb_x;
    c8_fp_y = c8_un_a * c8_bp_b;
    c8_klb_x = c8_q[0] + c8_q[1];
    c8_llb_x = c8_klb_x;
    c8_llb_x = muDoubleScalarSin(c8_llb_x);
    c8_vn_a = c8_fp_y;
    c8_cp_b = c8_llb_x;
    c8_gp_y = c8_vn_a * c8_cp_b;
    c8_mlb_x = c8_q[0];
    c8_nlb_x = c8_mlb_x;
    c8_nlb_x = muDoubleScalarCos(c8_nlb_x);
    c8_wn_a = c8_gp_y;
    c8_dp_b = c8_nlb_x;
    c8_hp_y = c8_wn_a * c8_dp_b;
    c8_olb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_plb_x = c8_olb_x;
    c8_plb_x = muDoubleScalarSin(c8_plb_x);
    c8_qlb_x = c8_q[0];
    c8_rlb_x = c8_qlb_x;
    c8_rlb_x = muDoubleScalarSin(c8_rlb_x);
    c8_xn_a = c8_plb_x;
    c8_ep_b = c8_rlb_x;
    c8_ip_y = c8_xn_a * c8_ep_b;
    c8_slb_x = c8_q[0] + c8_q[1];
    c8_tlb_x = c8_slb_x;
    c8_tlb_x = muDoubleScalarCos(c8_tlb_x);
    c8_yn_a = c8_ip_y;
    c8_fp_b = c8_tlb_x;
    c8_jp_y = c8_yn_a * c8_fp_b;
    c8_ulb_x = c8_q[0];
    c8_vlb_x = c8_ulb_x;
    c8_vlb_x = muDoubleScalarCos(c8_vlb_x);
    c8_ao_a = c8_jp_y;
    c8_gp_b = c8_vlb_x;
    c8_kp_y = c8_ao_a * c8_gp_b;
    c8_wlb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_xlb_x = c8_wlb_x;
    c8_xlb_x = muDoubleScalarCos(c8_xlb_x);
    c8_ylb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_amb_x = c8_ylb_x;
    c8_amb_x = muDoubleScalarCos(c8_amb_x);
    c8_bo_a = c8_xlb_x;
    c8_hp_b = c8_amb_x;
    c8_lp_y = c8_bo_a * c8_hp_b;
    c8_bmb_x = c8_q[0] + c8_q[1];
    c8_cmb_x = c8_bmb_x;
    c8_cmb_x = muDoubleScalarSin(c8_cmb_x);
    c8_co_a = c8_lp_y;
    c8_ip_b = c8_cmb_x;
    c8_mp_y = c8_co_a * c8_ip_b;
    c8_dmb_x = c8_q[0];
    c8_emb_x = c8_dmb_x;
    c8_emb_x = muDoubleScalarSin(c8_emb_x);
    c8_do_a = c8_mp_y;
    c8_jp_b = c8_emb_x;
    c8_np_y = c8_do_a * c8_jp_b;
    c8_fmb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_gmb_x = c8_fmb_x;
    c8_gmb_x = muDoubleScalarCos(c8_gmb_x);
    c8_hmb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_imb_x = c8_hmb_x;
    c8_imb_x = muDoubleScalarSin(c8_imb_x);
    c8_eo_a = c8_gmb_x;
    c8_kp_b = c8_imb_x;
    c8_op_y = c8_eo_a * c8_kp_b;
    c8_jmb_x = c8_q[0] + c8_q[1];
    c8_kmb_x = c8_jmb_x;
    c8_kmb_x = muDoubleScalarCos(c8_kmb_x);
    c8_fo_a = c8_op_y;
    c8_lp_b = c8_kmb_x;
    c8_pp_y = c8_fo_a * c8_lp_b;
    c8_lmb_x = c8_q[0];
    c8_mmb_x = c8_lmb_x;
    c8_mmb_x = muDoubleScalarSin(c8_mmb_x);
    c8_go_a = c8_pp_y;
    c8_mp_b = c8_mmb_x;
    c8_qp_y = c8_go_a * c8_mp_b;
    c8_nmb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_omb_x = c8_nmb_x;
    c8_omb_x = muDoubleScalarSin(c8_omb_x);
    c8_pmb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_qmb_x = c8_pmb_x;
    c8_qmb_x = muDoubleScalarCos(c8_qmb_x);
    c8_ho_a = c8_omb_x;
    c8_np_b = c8_qmb_x;
    c8_rp_y = c8_ho_a * c8_np_b;
    c8_rmb_x = c8_q[0] + c8_q[1];
    c8_smb_x = c8_rmb_x;
    c8_smb_x = muDoubleScalarSin(c8_smb_x);
    c8_io_a = c8_rp_y;
    c8_op_b = c8_smb_x;
    c8_sp_y = c8_io_a * c8_op_b;
    c8_tmb_x = c8_q[0];
    c8_umb_x = c8_tmb_x;
    c8_umb_x = muDoubleScalarCos(c8_umb_x);
    c8_jo_a = c8_sp_y;
    c8_pp_b = c8_umb_x;
    c8_tp_y = c8_jo_a * c8_pp_b;
    c8_vmb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_wmb_x = c8_vmb_x;
    c8_wmb_x = muDoubleScalarSin(c8_wmb_x);
    c8_xmb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ymb_x = c8_xmb_x;
    c8_ymb_x = muDoubleScalarSin(c8_ymb_x);
    c8_ko_a = c8_wmb_x;
    c8_qp_b = c8_ymb_x;
    c8_up_y = c8_ko_a * c8_qp_b;
    c8_anb_x = c8_q[0] + c8_q[1];
    c8_bnb_x = c8_anb_x;
    c8_bnb_x = muDoubleScalarCos(c8_bnb_x);
    c8_lo_a = c8_up_y;
    c8_rp_b = c8_bnb_x;
    c8_vp_y = c8_lo_a * c8_rp_b;
    c8_cnb_x = c8_q[0];
    c8_dnb_x = c8_cnb_x;
    c8_dnb_x = muDoubleScalarCos(c8_dnb_x);
    c8_mo_a = c8_vp_y;
    c8_sp_b = c8_dnb_x;
    c8_wp_y = c8_mo_a * c8_sp_b;
    c8_enb_x = c8_q[0];
    c8_fnb_x = c8_enb_x;
    c8_fnb_x = muDoubleScalarCos(c8_fnb_x);
    c8_gnb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_hnb_x = c8_gnb_x;
    c8_hnb_x = muDoubleScalarSin(c8_hnb_x);
    c8_no_a = c8_fnb_x;
    c8_tp_b = c8_hnb_x;
    c8_xp_y = c8_no_a * c8_tp_b;
    c8_inb_x = c8_q[0] + c8_q[1];
    c8_jnb_x = c8_inb_x;
    c8_jnb_x = muDoubleScalarCos(c8_jnb_x);
    c8_oo_a = c8_xp_y;
    c8_up_b = c8_jnb_x;
    c8_yp_y = c8_oo_a * c8_up_b;
    c8_knb_x = c8_q[0];
    c8_lnb_x = c8_knb_x;
    c8_lnb_x = muDoubleScalarSin(c8_lnb_x);
    c8_po_a = c8_yp_y;
    c8_vp_b = c8_lnb_x;
    c8_aq_y = c8_po_a * c8_vp_b;
    c8_mnb_x = c8_q[0];
    c8_nnb_x = c8_mnb_x;
    c8_nnb_x = muDoubleScalarCos(c8_nnb_x);
    c8_onb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_pnb_x = c8_onb_x;
    c8_pnb_x = muDoubleScalarSin(c8_pnb_x);
    c8_qo_a = c8_nnb_x;
    c8_wp_b = c8_pnb_x;
    c8_bq_y = c8_qo_a * c8_wp_b;
    c8_qnb_x = c8_q[0] + c8_q[1];
    c8_rnb_x = c8_qnb_x;
    c8_rnb_x = muDoubleScalarSin(c8_rnb_x);
    c8_ro_a = c8_bq_y;
    c8_xp_b = c8_rnb_x;
    c8_cq_y = c8_ro_a * c8_xp_b;
    c8_snb_x = c8_q[0];
    c8_tnb_x = c8_snb_x;
    c8_tnb_x = muDoubleScalarCos(c8_tnb_x);
    c8_so_a = c8_cq_y;
    c8_yp_b = c8_tnb_x;
    c8_dq_y = c8_so_a * c8_yp_b;
    c8_unb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_vnb_x = c8_unb_x;
    c8_vnb_x = muDoubleScalarCos(c8_vnb_x);
    c8_wnb_x = c8_q[0];
    c8_xnb_x = c8_wnb_x;
    c8_xnb_x = muDoubleScalarSin(c8_xnb_x);
    c8_to_a = c8_vnb_x;
    c8_aq_b = c8_xnb_x;
    c8_eq_y = c8_to_a * c8_aq_b;
    c8_ynb_x = c8_q[0] + c8_q[1];
    c8_aob_x = c8_ynb_x;
    c8_aob_x = muDoubleScalarCos(c8_aob_x);
    c8_uo_a = c8_eq_y;
    c8_bq_b = c8_aob_x;
    c8_fq_y = c8_uo_a * c8_bq_b;
    c8_bob_x = c8_q[0];
    c8_cob_x = c8_bob_x;
    c8_cob_x = muDoubleScalarSin(c8_cob_x);
    c8_vo_a = c8_fq_y;
    c8_cq_b = c8_cob_x;
    c8_gq_y = c8_vo_a * c8_cq_b;
    c8_dob_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_eob_x = c8_dob_x;
    c8_eob_x = muDoubleScalarCos(c8_eob_x);
    c8_fob_x = c8_q[0];
    c8_gob_x = c8_fob_x;
    c8_gob_x = muDoubleScalarSin(c8_gob_x);
    c8_wo_a = c8_eob_x;
    c8_dq_b = c8_gob_x;
    c8_hq_y = c8_wo_a * c8_dq_b;
    c8_hob_x = c8_q[0] + c8_q[1];
    c8_iob_x = c8_hob_x;
    c8_iob_x = muDoubleScalarSin(c8_iob_x);
    c8_xo_a = c8_hq_y;
    c8_eq_b = c8_iob_x;
    c8_iq_y = c8_xo_a * c8_eq_b;
    c8_job_x = c8_q[0];
    c8_kob_x = c8_job_x;
    c8_kob_x = muDoubleScalarCos(c8_kob_x);
    c8_yo_a = c8_iq_y;
    c8_fq_b = c8_kob_x;
    c8_jq_y = c8_yo_a * c8_fq_b;
    c8_lob_x = c8_q[0];
    c8_mob_x = c8_lob_x;
    c8_mob_x = muDoubleScalarCos(c8_mob_x);
    c8_nob_x = c8_q[0] + c8_q[1];
    c8_oob_x = c8_nob_x;
    c8_oob_x = muDoubleScalarSin(c8_oob_x);
    c8_ap_a = c8_mob_x;
    c8_gq_b = c8_oob_x;
    c8_kq_y = c8_ap_a * c8_gq_b;
    c8_pob_x = c8_q[0] + c8_q[1];
    c8_qob_x = c8_pob_x;
    c8_qob_x = muDoubleScalarCos(c8_qob_x);
    c8_bp_a = c8_kq_y;
    c8_hq_b = c8_qob_x;
    c8_lq_y = c8_bp_a * c8_hq_b;
    c8_rob_x = c8_q[0];
    c8_sob_x = c8_rob_x;
    c8_sob_x = muDoubleScalarSin(c8_sob_x);
    c8_cp_a = c8_lq_y;
    c8_iq_b = c8_sob_x;
    c8_mq_y = c8_cp_a * c8_iq_b;
    c8_tob_x = c8_q[0];
    c8_uob_x = c8_tob_x;
    c8_uob_x = muDoubleScalarCos(c8_uob_x);
    c8_vob_x = c8_q[0] + c8_q[1];
    c8_wob_x = c8_vob_x;
    c8_wob_x = muDoubleScalarSin(c8_wob_x);
    c8_dp_a = c8_uob_x;
    c8_jq_b = c8_wob_x;
    c8_nq_y = c8_dp_a * c8_jq_b;
    c8_xob_x = c8_q[0] + c8_q[1];
    c8_yob_x = c8_xob_x;
    c8_yob_x = muDoubleScalarSin(c8_yob_x);
    c8_ep_a = c8_nq_y;
    c8_kq_b = c8_yob_x;
    c8_oq_y = c8_ep_a * c8_kq_b;
    c8_apb_x = c8_q[0];
    c8_bpb_x = c8_apb_x;
    c8_bpb_x = muDoubleScalarCos(c8_bpb_x);
    c8_fp_a = c8_oq_y;
    c8_lq_b = c8_bpb_x;
    c8_pq_y = c8_fp_a * c8_lq_b;
    c8_cpb_x = c8_q[0];
    c8_dpb_x = c8_cpb_x;
    c8_dpb_x = muDoubleScalarSin(c8_dpb_x);
    c8_epb_x = c8_q[0] + c8_q[1];
    c8_fpb_x = c8_epb_x;
    c8_fpb_x = muDoubleScalarCos(c8_fpb_x);
    c8_gp_a = c8_dpb_x;
    c8_mq_b = c8_fpb_x;
    c8_qq_y = c8_gp_a * c8_mq_b;
    c8_gpb_x = c8_q[0] + c8_q[1];
    c8_hpb_x = c8_gpb_x;
    c8_hpb_x = muDoubleScalarCos(c8_hpb_x);
    c8_hp_a = c8_qq_y;
    c8_nq_b = c8_hpb_x;
    c8_rq_y = c8_hp_a * c8_nq_b;
    c8_ipb_x = c8_q[0];
    c8_jpb_x = c8_ipb_x;
    c8_jpb_x = muDoubleScalarSin(c8_jpb_x);
    c8_ip_a = c8_rq_y;
    c8_oq_b = c8_jpb_x;
    c8_sq_y = c8_ip_a * c8_oq_b;
    c8_kpb_x = c8_q[0];
    c8_lpb_x = c8_kpb_x;
    c8_lpb_x = muDoubleScalarSin(c8_lpb_x);
    c8_mpb_x = c8_q[0] + c8_q[1];
    c8_npb_x = c8_mpb_x;
    c8_npb_x = muDoubleScalarCos(c8_npb_x);
    c8_jp_a = c8_lpb_x;
    c8_pq_b = c8_npb_x;
    c8_tq_y = c8_jp_a * c8_pq_b;
    c8_opb_x = c8_q[0] + c8_q[1];
    c8_ppb_x = c8_opb_x;
    c8_ppb_x = muDoubleScalarSin(c8_ppb_x);
    c8_kp_a = c8_tq_y;
    c8_qq_b = c8_ppb_x;
    c8_uq_y = c8_kp_a * c8_qq_b;
    c8_qpb_x = c8_q[0];
    c8_rpb_x = c8_qpb_x;
    c8_rpb_x = muDoubleScalarCos(c8_rpb_x);
    c8_lp_a = c8_uq_y;
    c8_rq_b = c8_rpb_x;
    c8_vq_y = c8_lp_a * c8_rq_b;
    c8_spb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_tpb_x = c8_spb_x;
    c8_tpb_x = muDoubleScalarCos(c8_tpb_x);
    c8_upb_x = c8_q[0];
    c8_vpb_x = c8_upb_x;
    c8_vpb_x = muDoubleScalarCos(c8_vpb_x);
    c8_mp_a = c8_tpb_x;
    c8_sq_b = c8_vpb_x;
    c8_wq_y = c8_mp_a * c8_sq_b;
    c8_wpb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_xpb_x = c8_wpb_x;
    c8_xpb_x = muDoubleScalarSin(c8_xpb_x);
    c8_np_a = c8_wq_y;
    c8_tq_b = c8_xpb_x;
    c8_xq_y = c8_np_a * c8_tq_b;
    c8_ypb_x = c8_q[0] + c8_q[1];
    c8_aqb_x = c8_ypb_x;
    c8_aqb_x = muDoubleScalarSin(c8_aqb_x);
    c8_op_a = c8_xq_y;
    c8_uq_b = c8_aqb_x;
    c8_yq_y = c8_op_a * c8_uq_b;
    c8_bqb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_cqb_x = c8_bqb_x;
    c8_cqb_x = muDoubleScalarCos(c8_cqb_x);
    c8_dqb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_eqb_x = c8_dqb_x;
    c8_eqb_x = muDoubleScalarCos(c8_eqb_x);
    c8_pp_a = c8_cqb_x;
    c8_vq_b = c8_eqb_x;
    c8_ar_y = c8_pp_a * c8_vq_b;
    c8_fqb_x = c8_q[0];
    c8_gqb_x = c8_fqb_x;
    c8_gqb_x = muDoubleScalarSin(c8_gqb_x);
    c8_qp_a = c8_ar_y;
    c8_wq_b = c8_gqb_x;
    c8_br_y = c8_qp_a * c8_wq_b;
    c8_hqb_x = c8_q[0] + c8_q[1];
    c8_iqb_x = c8_hqb_x;
    c8_iqb_x = muDoubleScalarSin(c8_iqb_x);
    c8_rp_a = c8_br_y;
    c8_xq_b = c8_iqb_x;
    c8_cr_y = c8_rp_a * c8_xq_b;
    c8_jqb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_kqb_x = c8_jqb_x;
    c8_kqb_x = muDoubleScalarSin(c8_kqb_x);
    c8_lqb_x = c8_q[0];
    c8_mqb_x = c8_lqb_x;
    c8_mqb_x = muDoubleScalarCos(c8_mqb_x);
    c8_sp_a = c8_kqb_x;
    c8_yq_b = c8_mqb_x;
    c8_dr_y = c8_sp_a * c8_yq_b;
    c8_nqb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_oqb_x = c8_nqb_x;
    c8_oqb_x = muDoubleScalarSin(c8_oqb_x);
    c8_tp_a = c8_dr_y;
    c8_ar_b = c8_oqb_x;
    c8_er_y = c8_tp_a * c8_ar_b;
    c8_pqb_x = c8_q[0] + c8_q[1];
    c8_qqb_x = c8_pqb_x;
    c8_qqb_x = muDoubleScalarCos(c8_qqb_x);
    c8_up_a = c8_er_y;
    c8_br_b = c8_qqb_x;
    c8_fr_y = c8_up_a * c8_br_b;
    c8_rqb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_sqb_x = c8_rqb_x;
    c8_sqb_x = muDoubleScalarSin(c8_sqb_x);
    c8_tqb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_uqb_x = c8_tqb_x;
    c8_uqb_x = muDoubleScalarCos(c8_uqb_x);
    c8_vp_a = c8_sqb_x;
    c8_cr_b = c8_uqb_x;
    c8_gr_y = c8_vp_a * c8_cr_b;
    c8_vqb_x = c8_q[0];
    c8_wqb_x = c8_vqb_x;
    c8_wqb_x = muDoubleScalarSin(c8_wqb_x);
    c8_wp_a = c8_gr_y;
    c8_dr_b = c8_wqb_x;
    c8_hr_y = c8_wp_a * c8_dr_b;
    c8_xqb_x = c8_q[0] + c8_q[1];
    c8_yqb_x = c8_xqb_x;
    c8_yqb_x = muDoubleScalarCos(c8_yqb_x);
    c8_xp_a = c8_hr_y;
    c8_er_b = c8_yqb_x;
    c8_ir_y = c8_xp_a * c8_er_b;
    c8_arb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_brb_x = c8_arb_x;
    c8_brb_x = muDoubleScalarCos(c8_brb_x);
    c8_fr_b = c8_brb_x;
    c8_jr_y = 2.0 * c8_fr_b;
    c8_crb_x = c8_q[0];
    c8_drb_x = c8_crb_x;
    c8_drb_x = muDoubleScalarCos(c8_drb_x);
    c8_yp_a = c8_jr_y;
    c8_gr_b = c8_drb_x;
    c8_kr_y = c8_yp_a * c8_gr_b;
    c8_erb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_frb_x = c8_erb_x;
    c8_frb_x = muDoubleScalarSin(c8_frb_x);
    c8_aq_a = c8_kr_y;
    c8_hr_b = c8_frb_x;
    c8_lr_y = c8_aq_a * c8_hr_b;
    c8_grb_x = c8_q[0];
    c8_hrb_x = c8_grb_x;
    c8_hrb_x = muDoubleScalarSin(c8_hrb_x);
    c8_bq_a = c8_lr_y;
    c8_ir_b = c8_hrb_x;
    c8_mr_y = c8_bq_a * c8_ir_b;
    c8_irb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_jrb_x = c8_irb_x;
    c8_jrb_x = muDoubleScalarCos(c8_jrb_x);
    c8_jr_b = c8_jrb_x;
    c8_nr_y = 2.0 * c8_jr_b;
    c8_krb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_lrb_x = c8_krb_x;
    c8_lrb_x = muDoubleScalarCos(c8_lrb_x);
    c8_cq_a = c8_nr_y;
    c8_kr_b = c8_lrb_x;
    c8_or_y = c8_cq_a * c8_kr_b;
    c8_mrb_x = c8_q[0];
    c8_nrb_x = c8_mrb_x;
    c8_nrb_x = muDoubleScalarSin(c8_nrb_x);
    c8_dq_a = c8_or_y;
    c8_lr_b = c8_nrb_x;
    c8_pr_y = c8_dq_a * c8_lr_b;
    c8_orb_x = c8_q[0];
    c8_prb_x = c8_orb_x;
    c8_prb_x = muDoubleScalarSin(c8_prb_x);
    c8_eq_a = c8_pr_y;
    c8_mr_b = c8_prb_x;
    c8_qr_y = c8_eq_a * c8_mr_b;
    c8_qrb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_rrb_x = c8_qrb_x;
    c8_rrb_x = muDoubleScalarSin(c8_rrb_x);
    c8_nr_b = c8_rrb_x;
    c8_rr_y = 2.0 * c8_nr_b;
    c8_srb_x = c8_q[0];
    c8_trb_x = c8_srb_x;
    c8_trb_x = muDoubleScalarCos(c8_trb_x);
    c8_fq_a = c8_rr_y;
    c8_or_b = c8_trb_x;
    c8_sr_y = c8_fq_a * c8_or_b;
    c8_urb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_vrb_x = c8_urb_x;
    c8_vrb_x = muDoubleScalarSin(c8_vrb_x);
    c8_gq_a = c8_sr_y;
    c8_pr_b = c8_vrb_x;
    c8_tr_y = c8_gq_a * c8_pr_b;
    c8_wrb_x = c8_q[0];
    c8_xrb_x = c8_wrb_x;
    c8_xrb_x = muDoubleScalarCos(c8_xrb_x);
    c8_hq_a = c8_tr_y;
    c8_qr_b = c8_xrb_x;
    c8_ur_y = c8_hq_a * c8_qr_b;
    c8_yrb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_asb_x = c8_yrb_x;
    c8_asb_x = muDoubleScalarSin(c8_asb_x);
    c8_rr_b = c8_asb_x;
    c8_vr_y = 2.0 * c8_rr_b;
    c8_bsb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_csb_x = c8_bsb_x;
    c8_csb_x = muDoubleScalarCos(c8_csb_x);
    c8_iq_a = c8_vr_y;
    c8_sr_b = c8_csb_x;
    c8_wr_y = c8_iq_a * c8_sr_b;
    c8_dsb_x = c8_q[0];
    c8_esb_x = c8_dsb_x;
    c8_esb_x = muDoubleScalarSin(c8_esb_x);
    c8_jq_a = c8_wr_y;
    c8_tr_b = c8_esb_x;
    c8_xr_y = c8_jq_a * c8_tr_b;
    c8_fsb_x = c8_q[0];
    c8_gsb_x = c8_fsb_x;
    c8_gsb_x = muDoubleScalarCos(c8_gsb_x);
    c8_kq_a = c8_xr_y;
    c8_ur_b = c8_gsb_x;
    c8_yr_y = c8_kq_a * c8_ur_b;
    c8_hsb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_isb_x = c8_hsb_x;
    c8_isb_x = muDoubleScalarCos(c8_isb_x);
    c8_vr_b = c8_isb_x;
    c8_as_y = 2.0 * c8_vr_b;
    c8_jsb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ksb_x = c8_jsb_x;
    c8_ksb_x = muDoubleScalarCos(c8_ksb_x);
    c8_lq_a = c8_as_y;
    c8_wr_b = c8_ksb_x;
    c8_bs_y = c8_lq_a * c8_wr_b;
    c8_lsb_x = c8_q[0] + c8_q[1];
    c8_msb_x = c8_lsb_x;
    c8_msb_x = muDoubleScalarSin(c8_msb_x);
    c8_mq_a = c8_bs_y;
    c8_xr_b = c8_msb_x;
    c8_cs_y = c8_mq_a * c8_xr_b;
    c8_nsb_x = c8_q[0] + c8_q[1];
    c8_osb_x = c8_nsb_x;
    c8_osb_x = muDoubleScalarSin(c8_osb_x);
    c8_nq_a = c8_cs_y;
    c8_yr_b = c8_osb_x;
    c8_ds_y = c8_nq_a * c8_yr_b;
    c8_psb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_qsb_x = c8_psb_x;
    c8_qsb_x = muDoubleScalarCos(c8_qsb_x);
    c8_as_b = c8_qsb_x;
    c8_es_y = 2.0 * c8_as_b;
    c8_rsb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ssb_x = c8_rsb_x;
    c8_ssb_x = muDoubleScalarSin(c8_ssb_x);
    c8_oq_a = c8_es_y;
    c8_bs_b = c8_ssb_x;
    c8_fs_y = c8_oq_a * c8_bs_b;
    c8_tsb_x = c8_q[0] + c8_q[1];
    c8_usb_x = c8_tsb_x;
    c8_usb_x = muDoubleScalarCos(c8_usb_x);
    c8_pq_a = c8_fs_y;
    c8_cs_b = c8_usb_x;
    c8_gs_y = c8_pq_a * c8_cs_b;
    c8_vsb_x = c8_q[0] + c8_q[1];
    c8_wsb_x = c8_vsb_x;
    c8_wsb_x = muDoubleScalarSin(c8_wsb_x);
    c8_qq_a = c8_gs_y;
    c8_ds_b = c8_wsb_x;
    c8_hs_y = c8_qq_a * c8_ds_b;
    c8_xsb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_ysb_x = c8_xsb_x;
    c8_ysb_x = muDoubleScalarSin(c8_ysb_x);
    c8_es_b = c8_ysb_x;
    c8_is_y = 2.0 * c8_es_b;
    c8_atb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_btb_x = c8_atb_x;
    c8_btb_x = muDoubleScalarCos(c8_btb_x);
    c8_rq_a = c8_is_y;
    c8_fs_b = c8_btb_x;
    c8_js_y = c8_rq_a * c8_fs_b;
    c8_ctb_x = c8_q[0] + c8_q[1];
    c8_dtb_x = c8_ctb_x;
    c8_dtb_x = muDoubleScalarSin(c8_dtb_x);
    c8_sq_a = c8_js_y;
    c8_gs_b = c8_dtb_x;
    c8_ks_y = c8_sq_a * c8_gs_b;
    c8_etb_x = c8_q[0] + c8_q[1];
    c8_ftb_x = c8_etb_x;
    c8_ftb_x = muDoubleScalarCos(c8_ftb_x);
    c8_tq_a = c8_ks_y;
    c8_hs_b = c8_ftb_x;
    c8_ls_y = c8_tq_a * c8_hs_b;
    c8_gtb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_htb_x = c8_gtb_x;
    c8_htb_x = muDoubleScalarSin(c8_htb_x);
    c8_is_b = c8_htb_x;
    c8_ms_y = 2.0 * c8_is_b;
    c8_itb_x = (c8_q[0] + c8_q[1]) + c8_q[2];
    c8_jtb_x = c8_itb_x;
    c8_jtb_x = muDoubleScalarSin(c8_jtb_x);
    c8_uq_a = c8_ms_y;
    c8_js_b = c8_jtb_x;
    c8_ns_y = c8_uq_a * c8_js_b;
    c8_ktb_x = c8_q[0] + c8_q[1];
    c8_ltb_x = c8_ktb_x;
    c8_ltb_x = muDoubleScalarCos(c8_ltb_x);
    c8_vq_a = c8_ns_y;
    c8_ks_b = c8_ltb_x;
    c8_os_y = c8_vq_a * c8_ks_b;
    c8_mtb_x = c8_q[0] + c8_q[1];
    c8_ntb_x = c8_mtb_x;
    c8_ntb_x = muDoubleScalarCos(c8_ntb_x);
    c8_wq_a = c8_os_y;
    c8_ls_b = c8_ntb_x;
    c8_ps_y = c8_wq_a * c8_ls_b;
    c8_ms_b = c8_mpower(chartInstance, ((((((((((((((((((((((((((c8_bp_y -
      c8_ep_y) + c8_hp_y) - c8_kp_y) + c8_np_y) - c8_qp_y) - c8_tp_y) + c8_wp_y)
      - c8_aq_y) + c8_dq_y) + c8_gq_y) - c8_jq_y) - c8_mq_y) + c8_pq_y) +
      c8_sq_y) - c8_vq_y) - c8_yq_y) + c8_cr_y) + c8_fr_y) - c8_ir_y) - c8_mr_y)
      + c8_qr_y) + c8_ur_y) - c8_yr_y) + c8_ds_y) - c8_hs_y) - c8_ls_y) +
                        c8_ps_y);
    c8_qs_y = 2.0 * c8_ms_b;
    c8_c_A = -(((((((((((((((((((((((((((((((((((((((c8_pj_y + c8_sj_y) -
      c8_vj_y) - c8_yj_y) - c8_ck_y) + c8_fk_y) + c8_ik_y) + c8_lk_y) - c8_ok_y)
      - c8_rk_y) + c8_uk_y) - c8_xk_y) + c8_bl_y) - c8_el_y) + c8_hl_y) -
      c8_kl_y) + c8_nl_y) - c8_ql_y) + c8_tl_y) - c8_wl_y) + c8_am_y) - c8_dm_y)
      + c8_hm_y) - c8_lm_y) + c8_pm_y) - c8_tm_y) + c8_xm_y) + c8_cn_y) -
                          c8_gn_y) - c8_kn_y) + c8_on_y) - c8_sn_y) + c8_wn_y) -
                     c8_bo_y) + c8_fo_y) + c8_jo_y) - c8_no_y) - c8_ro_y) -
                c8_uo_y) + c8_xo_y);
    c8_b_B = c8_qs_y;
    c8_otb_x = c8_c_A;
    c8_rs_y = c8_b_B;
    c8_ptb_x = c8_otb_x;
    c8_ss_y = c8_rs_y;
    c8_ts_y = c8_ptb_x / c8_ss_y;
    c8_DW[0] = 0.0;
    c8_DW[1] = c8_mj_y;
    c8_DW[2] = c8_ts_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 28);
  for (c8_i23 = 0; c8_i23 < 6; c8_i23++) {
    c8_b_Ja[c8_i23] = c8_Ja[c8_i23];
  }

  c8_pinv(chartInstance, c8_b_Ja, c8_dv2);
  for (c8_i24 = 0; c8_i24 < 6; c8_i24++) {
    c8_Jinv[c8_i24] = c8_dv2[c8_i24];
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 30);
  c8_xq_a = c8_b_a;
  for (c8_i25 = 0; c8_i25 < 3; c8_i25++) {
    c8_ns_b[c8_i25] = c8_DW[c8_i25];
  }

  for (c8_i26 = 0; c8_i26 < 3; c8_i26++) {
    c8_qa[c8_i26] = c8_xq_a * c8_ns_b[c8_i26];
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 32);
  for (c8_i27 = 0; c8_i27 < 6; c8_i27++) {
    c8_m_b[c8_i27] = c8_Jinv[c8_i27];
  }

  for (c8_i28 = 0; c8_i28 < 2; c8_i28++) {
    c8_os_b[c8_i28] = c8_Ve[c8_i28];
  }

  c8_g_eml_scalar_eg(chartInstance);
  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i29 = 0; c8_i29 < 3; c8_i29++) {
    c8_qd_req[c8_i29] = 0.0;
  }

  for (c8_i30 = 0; c8_i30 < 3; c8_i30++) {
    c8_qd_req[c8_i30] = 0.0;
  }

  for (c8_i31 = 0; c8_i31 < 3; c8_i31++) {
    c8_ns_b[c8_i31] = c8_qd_req[c8_i31];
  }

  for (c8_i32 = 0; c8_i32 < 3; c8_i32++) {
    c8_qd_req[c8_i32] = c8_ns_b[c8_i32];
  }

  for (c8_i33 = 0; c8_i33 < 3; c8_i33++) {
    c8_ns_b[c8_i33] = c8_qd_req[c8_i33];
  }

  for (c8_i34 = 0; c8_i34 < 3; c8_i34++) {
    c8_qd_req[c8_i34] = c8_ns_b[c8_i34];
  }

  for (c8_i35 = 0; c8_i35 < 3; c8_i35++) {
    c8_qd_req[c8_i35] = 0.0;
    c8_i36 = 0;
    for (c8_i37 = 0; c8_i37 < 2; c8_i37++) {
      c8_qd_req[c8_i35] += c8_m_b[c8_i36 + c8_i35] * c8_os_b[c8_i37];
      c8_i36 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 34);
  c8_EEv[0] = 0.0;
  c8_EEv[1] = 0.0;
  c8_EEv[2] = c8_EE;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 35);
  c8_qd_req[2] += c8_EE;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 39);
  for (c8_i38 = 0; c8_i38 < 6; c8_i38++) {
    c8_Jstar[c8_i38] = c8_Ja[c8_i38];
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 40);
  for (c8_i39 = 0; c8_i39 < 6; c8_i39++) {
    c8_b_Jstar[c8_i39] = c8_Jstar[c8_i39];
  }

  c8_svd(chartInstance, c8_b_Jstar, c8_dv3);
  for (c8_i40 = 0; c8_i40 < 2; c8_i40++) {
    c8_A[c8_i40] = c8_dv3[c8_i40];
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 41);
  c8_lambmax = 20.0;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 42);
  c8_Sigma = c8_A[1];
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 43);
  if (CV_EML_IF(0, 1, 1, c8_Sigma >= 0.5)) {
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 44);
    c8_lamb2 = 0.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 46);
    c8_d_A = c8_Sigma;
    c8_qtb_x = c8_d_A;
    c8_rtb_x = c8_qtb_x;
    c8_us_y = c8_rtb_x / 4.0;
    c8_yq_a = 1.0 - c8_b_mpower(chartInstance, c8_us_y);
    c8_lamb2 = c8_yq_a * 20.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 48);
  for (c8_i41 = 0; c8_i41 < 6; c8_i41++) {
    c8_o_a[c8_i41] = c8_Jstar[c8_i41];
  }

  c8_i42 = 0;
  for (c8_i43 = 0; c8_i43 < 2; c8_i43++) {
    c8_i44 = 0;
    for (c8_i45 = 0; c8_i45 < 3; c8_i45++) {
      c8_m_b[c8_i45 + c8_i42] = c8_Jstar[c8_i44 + c8_i43];
      c8_i44 += 2;
    }

    c8_i42 += 3;
  }

  c8_eml_scalar_eg(chartInstance);
  c8_eml_scalar_eg(chartInstance);
  for (c8_i46 = 0; c8_i46 < 2; c8_i46++) {
    c8_i47 = 0;
    c8_i48 = 0;
    for (c8_i49 = 0; c8_i49 < 2; c8_i49++) {
      c8_m_y[c8_i47 + c8_i46] = 0.0;
      c8_i50 = 0;
      for (c8_i51 = 0; c8_i51 < 3; c8_i51++) {
        c8_m_y[c8_i47 + c8_i46] += c8_o_a[c8_i50 + c8_i46] * c8_m_b[c8_i51 +
          c8_i48];
        c8_i50 += 2;
      }

      c8_i47 += 2;
      c8_i48 += 3;
    }
  }

  c8_ar_a = c8_lamb2;
  for (c8_i52 = 0; c8_i52 < 4; c8_i52++) {
    c8_vs_y[c8_i52] = c8_ar_a * c8_ps_b[c8_i52];
  }

  c8_i53 = 0;
  for (c8_i54 = 0; c8_i54 < 2; c8_i54++) {
    c8_i55 = 0;
    for (c8_i56 = 0; c8_i56 < 3; c8_i56++) {
      c8_m_b[c8_i56 + c8_i53] = c8_Jstar[c8_i55 + c8_i54];
      c8_i55 += 2;
    }

    c8_i53 += 3;
  }

  for (c8_i57 = 0; c8_i57 < 4; c8_i57++) {
    c8_ws_y[c8_i57] = c8_m_y[c8_i57] + c8_vs_y[c8_i57];
  }

  c8_b_pinv(chartInstance, c8_ws_y, c8_m_y);
  c8_h_eml_scalar_eg(chartInstance);
  c8_h_eml_scalar_eg(chartInstance);
  for (c8_i58 = 0; c8_i58 < 3; c8_i58++) {
    c8_i59 = 0;
    c8_i60 = 0;
    for (c8_i61 = 0; c8_i61 < 2; c8_i61++) {
      c8_xs_y[c8_i59 + c8_i58] = 0.0;
      c8_i62 = 0;
      for (c8_i63 = 0; c8_i63 < 2; c8_i63++) {
        c8_xs_y[c8_i59 + c8_i58] += c8_m_b[c8_i62 + c8_i58] * c8_m_y[c8_i63 +
          c8_i60];
        c8_i62 += 3;
      }

      c8_i59 += 3;
      c8_i60 += 2;
    }
  }

  for (c8_i64 = 0; c8_i64 < 2; c8_i64++) {
    c8_os_b[c8_i64] = c8_Ve[c8_i64];
  }

  c8_g_eml_scalar_eg(chartInstance);
  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i65 = 0; c8_i65 < 3; c8_i65++) {
    c8_ns_b[c8_i65] = 0.0;
    c8_i66 = 0;
    for (c8_i67 = 0; c8_i67 < 2; c8_i67++) {
      c8_ns_b[c8_i65] += c8_xs_y[c8_i66 + c8_i65] * c8_os_b[c8_i67];
      c8_i66 += 3;
    }
  }

  for (c8_i68 = 0; c8_i68 < 3; c8_i68++) {
    c8_qd_reqW[c8_i68] = c8_ns_b[c8_i68] + c8_EEv[c8_i68];
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -48);
  _SFD_SYMBOL_SCOPE_POP();
  for (c8_i69 = 0; c8_i69 < 3; c8_i69++) {
    (*c8_b_qd_req)[c8_i69] = c8_qd_req[c8_i69];
  }

  for (c8_i70 = 0; c8_i70 < 3; c8_i70++) {
    (*c8_b_qd_reqW)[c8_i70] = c8_qd_reqW[c8_i70];
  }

  *c8_b_W = c8_W;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
}

static void initSimStructsc8_CusakisME4901(SFc8_CusakisME4901InstanceStruct
  *chartInstance)
{
}

static void registerMessagesc8_CusakisME4901(SFc8_CusakisME4901InstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber)
{
}

static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  real_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc8_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(real_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static real_T c8_emlrt_marshallIn(SFc8_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c8_W, const char_T *c8_identifier)
{
  real_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_W), &c8_thisId);
  sf_mex_destroy(&c8_W);
  return c8_y;
}

static real_T c8_b_emlrt_marshallIn(SFc8_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_y;
  real_T c8_d2;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_d2, 1, 0, 0U, 0, 0U, 0);
  c8_y = c8_d2;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_W;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y;
  SFc8_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc8_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c8_W = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_W), &c8_thisId);
  sf_mex_destroy(&c8_W);
  *(real_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i71;
  real_T c8_b_inData[3];
  int32_T c8_i72;
  real_T c8_u[3];
  const mxArray *c8_y = NULL;
  SFc8_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc8_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i71 = 0; c8_i71 < 3; c8_i71++) {
    c8_b_inData[c8_i71] = (*(real_T (*)[3])c8_inData)[c8_i71];
  }

  for (c8_i72 = 0; c8_i72 < 3; c8_i72++) {
    c8_u[c8_i72] = c8_b_inData[c8_i72];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static void c8_c_emlrt_marshallIn(SFc8_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c8_qd_reqW, const char_T *c8_identifier, real_T
  c8_y[3])
{
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_qd_reqW), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_qd_reqW);
}

static void c8_d_emlrt_marshallIn(SFc8_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[3])
{
  real_T c8_dv4[3];
  int32_T c8_i73;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dv4, 1, 0, 0U, 1, 0U, 1, 3);
  for (c8_i73 = 0; c8_i73 < 3; c8_i73++) {
    c8_y[c8_i73] = c8_dv4[c8_i73];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_qd_reqW;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y[3];
  int32_T c8_i74;
  SFc8_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc8_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c8_qd_reqW = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_qd_reqW), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_qd_reqW);
  for (c8_i74 = 0; c8_i74 < 3; c8_i74++) {
    (*(real_T (*)[3])c8_outData)[c8_i74] = c8_y[c8_i74];
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i75;
  real_T c8_b_inData[9];
  int32_T c8_i76;
  real_T c8_u[9];
  const mxArray *c8_y = NULL;
  SFc8_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc8_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i75 = 0; c8_i75 < 9; c8_i75++) {
    c8_b_inData[c8_i75] = (*(real_T (*)[9])c8_inData)[c8_i75];
  }

  for (c8_i76 = 0; c8_i76 < 9; c8_i76++) {
    c8_u[c8_i76] = c8_b_inData[c8_i76];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 9), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i77;
  real_T c8_b_inData[2];
  int32_T c8_i78;
  real_T c8_u[2];
  const mxArray *c8_y = NULL;
  SFc8_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc8_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i77 = 0; c8_i77 < 2; c8_i77++) {
    c8_b_inData[c8_i77] = (*(real_T (*)[2])c8_inData)[c8_i77];
  }

  for (c8_i78 = 0; c8_i78 < 2; c8_i78++) {
    c8_u[c8_i78] = c8_b_inData[c8_i78];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static void c8_e_emlrt_marshallIn(SFc8_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[2])
{
  real_T c8_dv5[2];
  int32_T c8_i79;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dv5, 1, 0, 0U, 1, 0U, 1, 2);
  for (c8_i79 = 0; c8_i79 < 2; c8_i79++) {
    c8_y[c8_i79] = c8_dv5[c8_i79];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_A;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y[2];
  int32_T c8_i80;
  SFc8_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc8_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c8_A = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_A), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_A);
  for (c8_i80 = 0; c8_i80 < 2; c8_i80++) {
    (*(real_T (*)[2])c8_outData)[c8_i80] = c8_y[c8_i80];
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_e_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i81;
  int32_T c8_i82;
  int32_T c8_i83;
  real_T c8_b_inData[6];
  int32_T c8_i84;
  int32_T c8_i85;
  int32_T c8_i86;
  real_T c8_u[6];
  const mxArray *c8_y = NULL;
  SFc8_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc8_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_i81 = 0;
  for (c8_i82 = 0; c8_i82 < 3; c8_i82++) {
    for (c8_i83 = 0; c8_i83 < 2; c8_i83++) {
      c8_b_inData[c8_i83 + c8_i81] = (*(real_T (*)[6])c8_inData)[c8_i83 + c8_i81];
    }

    c8_i81 += 2;
  }

  c8_i84 = 0;
  for (c8_i85 = 0; c8_i85 < 3; c8_i85++) {
    for (c8_i86 = 0; c8_i86 < 2; c8_i86++) {
      c8_u[c8_i86 + c8_i84] = c8_b_inData[c8_i86 + c8_i84];
    }

    c8_i84 += 2;
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 2, 2, 3), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static void c8_f_emlrt_marshallIn(SFc8_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[6])
{
  real_T c8_dv6[6];
  int32_T c8_i87;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dv6, 1, 0, 0U, 1, 0U, 2, 2, 3);
  for (c8_i87 = 0; c8_i87 < 6; c8_i87++) {
    c8_y[c8_i87] = c8_dv6[c8_i87];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_Jstar;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y[6];
  int32_T c8_i88;
  int32_T c8_i89;
  int32_T c8_i90;
  SFc8_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc8_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c8_Jstar = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_Jstar), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_Jstar);
  c8_i88 = 0;
  for (c8_i89 = 0; c8_i89 < 3; c8_i89++) {
    for (c8_i90 = 0; c8_i90 < 2; c8_i90++) {
      (*(real_T (*)[6])c8_outData)[c8_i90 + c8_i88] = c8_y[c8_i90 + c8_i88];
    }

    c8_i88 += 2;
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_f_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i91;
  int32_T c8_i92;
  int32_T c8_i93;
  real_T c8_b_inData[6];
  int32_T c8_i94;
  int32_T c8_i95;
  int32_T c8_i96;
  real_T c8_u[6];
  const mxArray *c8_y = NULL;
  SFc8_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc8_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_i91 = 0;
  for (c8_i92 = 0; c8_i92 < 2; c8_i92++) {
    for (c8_i93 = 0; c8_i93 < 3; c8_i93++) {
      c8_b_inData[c8_i93 + c8_i91] = (*(real_T (*)[6])c8_inData)[c8_i93 + c8_i91];
    }

    c8_i91 += 3;
  }

  c8_i94 = 0;
  for (c8_i95 = 0; c8_i95 < 2; c8_i95++) {
    for (c8_i96 = 0; c8_i96 < 3; c8_i96++) {
      c8_u[c8_i96 + c8_i94] = c8_b_inData[c8_i96 + c8_i94];
    }

    c8_i94 += 3;
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 2, 3, 2), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static void c8_g_emlrt_marshallIn(SFc8_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[6])
{
  real_T c8_dv7[6];
  int32_T c8_i97;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dv7, 1, 0, 0U, 1, 0U, 2, 3, 2);
  for (c8_i97 = 0; c8_i97 < 6; c8_i97++) {
    c8_y[c8_i97] = c8_dv7[c8_i97];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_Jinv;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y[6];
  int32_T c8_i98;
  int32_T c8_i99;
  int32_T c8_i100;
  SFc8_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc8_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c8_Jinv = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_Jinv), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_Jinv);
  c8_i98 = 0;
  for (c8_i99 = 0; c8_i99 < 2; c8_i99++) {
    for (c8_i100 = 0; c8_i100 < 3; c8_i100++) {
      (*(real_T (*)[6])c8_outData)[c8_i100 + c8_i98] = c8_y[c8_i100 + c8_i98];
    }

    c8_i98 += 3;
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_g_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i101;
  real_T c8_b_inData[3];
  int32_T c8_i102;
  real_T c8_u[3];
  const mxArray *c8_y = NULL;
  SFc8_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc8_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i101 = 0; c8_i101 < 3; c8_i101++) {
    c8_b_inData[c8_i101] = (*(real_T (*)[3])c8_inData)[c8_i101];
  }

  for (c8_i102 = 0; c8_i102 < 3; c8_i102++) {
    c8_u[c8_i102] = c8_b_inData[c8_i102];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 2, 1, 3), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static void c8_h_emlrt_marshallIn(SFc8_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[3])
{
  real_T c8_dv8[3];
  int32_T c8_i103;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dv8, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c8_i103 = 0; c8_i103 < 3; c8_i103++) {
    c8_y[c8_i103] = c8_dv8[c8_i103];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_q;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y[3];
  int32_T c8_i104;
  SFc8_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc8_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c8_q = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_q), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_q);
  for (c8_i104 = 0; c8_i104 < 3; c8_i104++) {
    (*(real_T (*)[3])c8_outData)[c8_i104] = c8_y[c8_i104];
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

const mxArray *sf_c8_CusakisME4901_get_eml_resolved_functions_info(void)
{
  const mxArray *c8_nameCaptureInfo;
  c8_ResolvedFunctionInfo c8_info[247];
  const mxArray *c8_m0 = NULL;
  int32_T c8_i105;
  c8_ResolvedFunctionInfo *c8_r0;
  c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  c8_info_helper(c8_info);
  c8_b_info_helper(c8_info);
  c8_c_info_helper(c8_info);
  c8_d_info_helper(c8_info);
  sf_mex_assign(&c8_m0, sf_mex_createstruct("nameCaptureInfo", 1, 247), FALSE);
  for (c8_i105 = 0; c8_i105 < 247; c8_i105++) {
    c8_r0 = &c8_info[c8_i105];
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->context)), "context", "nameCaptureInfo",
                    c8_i105);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c8_r0->name)), "name", "nameCaptureInfo", c8_i105);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c8_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c8_i105);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->resolved)), "resolved", "nameCaptureInfo",
                    c8_i105);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c8_i105);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c8_i105);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c8_i105);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c8_i105);
  }

  sf_mex_assign(&c8_nameCaptureInfo, c8_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c8_nameCaptureInfo);
  return c8_nameCaptureInfo;
}

static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[247])
{
  c8_info[0].context = "";
  c8_info[0].name = "sin";
  c8_info[0].dominantType = "double";
  c8_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c8_info[0].fileTimeLo = 1343862786U;
  c8_info[0].fileTimeHi = 0U;
  c8_info[0].mFileTimeLo = 0U;
  c8_info[0].mFileTimeHi = 0U;
  c8_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c8_info[1].name = "eml_scalar_sin";
  c8_info[1].dominantType = "double";
  c8_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c8_info[1].fileTimeLo = 1286851136U;
  c8_info[1].fileTimeHi = 0U;
  c8_info[1].mFileTimeLo = 0U;
  c8_info[1].mFileTimeHi = 0U;
  c8_info[2].context = "";
  c8_info[2].name = "mtimes";
  c8_info[2].dominantType = "double";
  c8_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[2].fileTimeLo = 1289552092U;
  c8_info[2].fileTimeHi = 0U;
  c8_info[2].mFileTimeLo = 0U;
  c8_info[2].mFileTimeHi = 0U;
  c8_info[3].context = "";
  c8_info[3].name = "cos";
  c8_info[3].dominantType = "double";
  c8_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c8_info[3].fileTimeLo = 1343862772U;
  c8_info[3].fileTimeHi = 0U;
  c8_info[3].mFileTimeLo = 0U;
  c8_info[3].mFileTimeHi = 0U;
  c8_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c8_info[4].name = "eml_scalar_cos";
  c8_info[4].dominantType = "double";
  c8_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c8_info[4].fileTimeLo = 1286851122U;
  c8_info[4].fileTimeHi = 0U;
  c8_info[4].mFileTimeLo = 0U;
  c8_info[4].mFileTimeHi = 0U;
  c8_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[5].name = "eml_index_class";
  c8_info[5].dominantType = "";
  c8_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[5].fileTimeLo = 1323202978U;
  c8_info[5].fileTimeHi = 0U;
  c8_info[5].mFileTimeLo = 0U;
  c8_info[5].mFileTimeHi = 0U;
  c8_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[6].name = "eml_scalar_eg";
  c8_info[6].dominantType = "double";
  c8_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[6].fileTimeLo = 1286851196U;
  c8_info[6].fileTimeHi = 0U;
  c8_info[6].mFileTimeLo = 0U;
  c8_info[6].mFileTimeHi = 0U;
  c8_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[7].name = "eml_xgemm";
  c8_info[7].dominantType = "char";
  c8_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c8_info[7].fileTimeLo = 1299109172U;
  c8_info[7].fileTimeHi = 0U;
  c8_info[7].mFileTimeLo = 0U;
  c8_info[7].mFileTimeHi = 0U;
  c8_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c8_info[8].name = "eml_blas_inline";
  c8_info[8].dominantType = "";
  c8_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c8_info[8].fileTimeLo = 1299109168U;
  c8_info[8].fileTimeHi = 0U;
  c8_info[8].mFileTimeLo = 0U;
  c8_info[8].mFileTimeHi = 0U;
  c8_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c8_info[9].name = "mtimes";
  c8_info[9].dominantType = "double";
  c8_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[9].fileTimeLo = 1289552092U;
  c8_info[9].fileTimeHi = 0U;
  c8_info[9].mFileTimeLo = 0U;
  c8_info[9].mFileTimeHi = 0U;
  c8_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c8_info[10].name = "eml_index_class";
  c8_info[10].dominantType = "";
  c8_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[10].fileTimeLo = 1323202978U;
  c8_info[10].fileTimeHi = 0U;
  c8_info[10].mFileTimeLo = 0U;
  c8_info[10].mFileTimeHi = 0U;
  c8_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c8_info[11].name = "eml_scalar_eg";
  c8_info[11].dominantType = "double";
  c8_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[11].fileTimeLo = 1286851196U;
  c8_info[11].fileTimeHi = 0U;
  c8_info[11].mFileTimeLo = 0U;
  c8_info[11].mFileTimeHi = 0U;
  c8_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c8_info[12].name = "eml_refblas_xgemm";
  c8_info[12].dominantType = "char";
  c8_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c8_info[12].fileTimeLo = 1299109174U;
  c8_info[12].fileTimeHi = 0U;
  c8_info[12].mFileTimeLo = 0U;
  c8_info[12].mFileTimeHi = 0U;
  c8_info[13].context = "";
  c8_info[13].name = "det";
  c8_info[13].dominantType = "double";
  c8_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/det.m";
  c8_info[13].fileTimeLo = 1286851222U;
  c8_info[13].fileTimeHi = 0U;
  c8_info[13].mFileTimeLo = 0U;
  c8_info[13].mFileTimeHi = 0U;
  c8_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/det.m";
  c8_info[14].name = "eml_index_class";
  c8_info[14].dominantType = "";
  c8_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[14].fileTimeLo = 1323202978U;
  c8_info[14].fileTimeHi = 0U;
  c8_info[14].mFileTimeLo = 0U;
  c8_info[14].mFileTimeHi = 0U;
  c8_info[15].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/det.m";
  c8_info[15].name = "eml_xgetrf";
  c8_info[15].dominantType = "double";
  c8_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c8_info[15].fileTimeLo = 1286851206U;
  c8_info[15].fileTimeHi = 0U;
  c8_info[15].mFileTimeLo = 0U;
  c8_info[15].mFileTimeHi = 0U;
  c8_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c8_info[16].name = "eml_lapack_xgetrf";
  c8_info[16].dominantType = "double";
  c8_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c8_info[16].fileTimeLo = 1286851210U;
  c8_info[16].fileTimeHi = 0U;
  c8_info[16].mFileTimeLo = 0U;
  c8_info[16].mFileTimeHi = 0U;
  c8_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c8_info[17].name = "eml_matlab_zgetrf";
  c8_info[17].dominantType = "double";
  c8_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[17].fileTimeLo = 1302721394U;
  c8_info[17].fileTimeHi = 0U;
  c8_info[17].mFileTimeLo = 0U;
  c8_info[17].mFileTimeHi = 0U;
  c8_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[18].name = "realmin";
  c8_info[18].dominantType = "char";
  c8_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c8_info[18].fileTimeLo = 1307683642U;
  c8_info[18].fileTimeHi = 0U;
  c8_info[18].mFileTimeLo = 0U;
  c8_info[18].mFileTimeHi = 0U;
  c8_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c8_info[19].name = "eml_realmin";
  c8_info[19].dominantType = "char";
  c8_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c8_info[19].fileTimeLo = 1307683644U;
  c8_info[19].fileTimeHi = 0U;
  c8_info[19].mFileTimeLo = 0U;
  c8_info[19].mFileTimeHi = 0U;
  c8_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c8_info[20].name = "eml_float_model";
  c8_info[20].dominantType = "char";
  c8_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c8_info[20].fileTimeLo = 1326760396U;
  c8_info[20].fileTimeHi = 0U;
  c8_info[20].mFileTimeLo = 0U;
  c8_info[20].mFileTimeHi = 0U;
  c8_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[21].name = "eps";
  c8_info[21].dominantType = "char";
  c8_info[21].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c8_info[21].fileTimeLo = 1326760396U;
  c8_info[21].fileTimeHi = 0U;
  c8_info[21].mFileTimeLo = 0U;
  c8_info[21].mFileTimeHi = 0U;
  c8_info[22].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c8_info[22].name = "eml_is_float_class";
  c8_info[22].dominantType = "char";
  c8_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c8_info[22].fileTimeLo = 1286851182U;
  c8_info[22].fileTimeHi = 0U;
  c8_info[22].mFileTimeLo = 0U;
  c8_info[22].mFileTimeHi = 0U;
  c8_info[23].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c8_info[23].name = "eml_eps";
  c8_info[23].dominantType = "char";
  c8_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c8_info[23].fileTimeLo = 1326760396U;
  c8_info[23].fileTimeHi = 0U;
  c8_info[23].mFileTimeLo = 0U;
  c8_info[23].mFileTimeHi = 0U;
  c8_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c8_info[24].name = "eml_float_model";
  c8_info[24].dominantType = "char";
  c8_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c8_info[24].fileTimeLo = 1326760396U;
  c8_info[24].fileTimeHi = 0U;
  c8_info[24].mFileTimeLo = 0U;
  c8_info[24].mFileTimeHi = 0U;
  c8_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[25].name = "min";
  c8_info[25].dominantType = "coder.internal.indexInt";
  c8_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c8_info[25].fileTimeLo = 1311287718U;
  c8_info[25].fileTimeHi = 0U;
  c8_info[25].mFileTimeLo = 0U;
  c8_info[25].mFileTimeHi = 0U;
  c8_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c8_info[26].name = "eml_min_or_max";
  c8_info[26].dominantType = "char";
  c8_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c8_info[26].fileTimeLo = 1334103890U;
  c8_info[26].fileTimeHi = 0U;
  c8_info[26].mFileTimeLo = 0U;
  c8_info[26].mFileTimeHi = 0U;
  c8_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c8_info[27].name = "eml_scalar_eg";
  c8_info[27].dominantType = "coder.internal.indexInt";
  c8_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[27].fileTimeLo = 1286851196U;
  c8_info[27].fileTimeHi = 0U;
  c8_info[27].mFileTimeLo = 0U;
  c8_info[27].mFileTimeHi = 0U;
  c8_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c8_info[28].name = "eml_scalexp_alloc";
  c8_info[28].dominantType = "coder.internal.indexInt";
  c8_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c8_info[28].fileTimeLo = 1352457260U;
  c8_info[28].fileTimeHi = 0U;
  c8_info[28].mFileTimeLo = 0U;
  c8_info[28].mFileTimeHi = 0U;
  c8_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c8_info[29].name = "eml_index_class";
  c8_info[29].dominantType = "";
  c8_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[29].fileTimeLo = 1323202978U;
  c8_info[29].fileTimeHi = 0U;
  c8_info[29].mFileTimeLo = 0U;
  c8_info[29].mFileTimeHi = 0U;
  c8_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c8_info[30].name = "eml_scalar_eg";
  c8_info[30].dominantType = "coder.internal.indexInt";
  c8_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[30].fileTimeLo = 1286851196U;
  c8_info[30].fileTimeHi = 0U;
  c8_info[30].mFileTimeLo = 0U;
  c8_info[30].mFileTimeHi = 0U;
  c8_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[31].name = "colon";
  c8_info[31].dominantType = "double";
  c8_info[31].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c8_info[31].fileTimeLo = 1348224328U;
  c8_info[31].fileTimeHi = 0U;
  c8_info[31].mFileTimeLo = 0U;
  c8_info[31].mFileTimeHi = 0U;
  c8_info[32].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c8_info[32].name = "colon";
  c8_info[32].dominantType = "double";
  c8_info[32].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c8_info[32].fileTimeLo = 1348224328U;
  c8_info[32].fileTimeHi = 0U;
  c8_info[32].mFileTimeLo = 0U;
  c8_info[32].mFileTimeHi = 0U;
  c8_info[33].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c8_info[33].name = "floor";
  c8_info[33].dominantType = "double";
  c8_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c8_info[33].fileTimeLo = 1343862780U;
  c8_info[33].fileTimeHi = 0U;
  c8_info[33].mFileTimeLo = 0U;
  c8_info[33].mFileTimeHi = 0U;
  c8_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c8_info[34].name = "eml_scalar_floor";
  c8_info[34].dominantType = "double";
  c8_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c8_info[34].fileTimeLo = 1286851126U;
  c8_info[34].fileTimeHi = 0U;
  c8_info[34].mFileTimeLo = 0U;
  c8_info[34].mFileTimeHi = 0U;
  c8_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c8_info[35].name = "intmin";
  c8_info[35].dominantType = "char";
  c8_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c8_info[35].fileTimeLo = 1311287718U;
  c8_info[35].fileTimeHi = 0U;
  c8_info[35].mFileTimeLo = 0U;
  c8_info[35].mFileTimeHi = 0U;
  c8_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c8_info[36].name = "intmax";
  c8_info[36].dominantType = "char";
  c8_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c8_info[36].fileTimeLo = 1311287716U;
  c8_info[36].fileTimeHi = 0U;
  c8_info[36].mFileTimeLo = 0U;
  c8_info[36].mFileTimeHi = 0U;
  c8_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c8_info[37].name = "intmin";
  c8_info[37].dominantType = "char";
  c8_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c8_info[37].fileTimeLo = 1311287718U;
  c8_info[37].fileTimeHi = 0U;
  c8_info[37].mFileTimeLo = 0U;
  c8_info[37].mFileTimeHi = 0U;
  c8_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c8_info[38].name = "intmax";
  c8_info[38].dominantType = "char";
  c8_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c8_info[38].fileTimeLo = 1311287716U;
  c8_info[38].fileTimeHi = 0U;
  c8_info[38].mFileTimeLo = 0U;
  c8_info[38].mFileTimeHi = 0U;
  c8_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c8_info[39].name = "eml_isa_uint";
  c8_info[39].dominantType = "coder.internal.indexInt";
  c8_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c8_info[39].fileTimeLo = 1286851184U;
  c8_info[39].fileTimeHi = 0U;
  c8_info[39].mFileTimeLo = 0U;
  c8_info[39].mFileTimeHi = 0U;
  c8_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c8_info[40].name = "eml_unsigned_class";
  c8_info[40].dominantType = "char";
  c8_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c8_info[40].fileTimeLo = 1323202980U;
  c8_info[40].fileTimeHi = 0U;
  c8_info[40].mFileTimeLo = 0U;
  c8_info[40].mFileTimeHi = 0U;
  c8_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c8_info[41].name = "eml_index_class";
  c8_info[41].dominantType = "";
  c8_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[41].fileTimeLo = 1323202978U;
  c8_info[41].fileTimeHi = 0U;
  c8_info[41].mFileTimeLo = 0U;
  c8_info[41].mFileTimeHi = 0U;
  c8_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c8_info[42].name = "eml_index_class";
  c8_info[42].dominantType = "";
  c8_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[42].fileTimeLo = 1323202978U;
  c8_info[42].fileTimeHi = 0U;
  c8_info[42].mFileTimeLo = 0U;
  c8_info[42].mFileTimeHi = 0U;
  c8_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c8_info[43].name = "intmax";
  c8_info[43].dominantType = "char";
  c8_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c8_info[43].fileTimeLo = 1311287716U;
  c8_info[43].fileTimeHi = 0U;
  c8_info[43].mFileTimeLo = 0U;
  c8_info[43].mFileTimeHi = 0U;
  c8_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c8_info[44].name = "eml_isa_uint";
  c8_info[44].dominantType = "coder.internal.indexInt";
  c8_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c8_info[44].fileTimeLo = 1286851184U;
  c8_info[44].fileTimeHi = 0U;
  c8_info[44].mFileTimeLo = 0U;
  c8_info[44].mFileTimeHi = 0U;
  c8_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c8_info[45].name = "eml_index_plus";
  c8_info[45].dominantType = "double";
  c8_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[45].fileTimeLo = 1286851178U;
  c8_info[45].fileTimeHi = 0U;
  c8_info[45].mFileTimeLo = 0U;
  c8_info[45].mFileTimeHi = 0U;
  c8_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[46].name = "eml_index_class";
  c8_info[46].dominantType = "";
  c8_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[46].fileTimeLo = 1323202978U;
  c8_info[46].fileTimeHi = 0U;
  c8_info[46].mFileTimeLo = 0U;
  c8_info[46].mFileTimeHi = 0U;
  c8_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[47].name = "eml_index_class";
  c8_info[47].dominantType = "";
  c8_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[47].fileTimeLo = 1323202978U;
  c8_info[47].fileTimeHi = 0U;
  c8_info[47].mFileTimeLo = 0U;
  c8_info[47].mFileTimeHi = 0U;
  c8_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[48].name = "eml_index_plus";
  c8_info[48].dominantType = "double";
  c8_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[48].fileTimeLo = 1286851178U;
  c8_info[48].fileTimeHi = 0U;
  c8_info[48].mFileTimeLo = 0U;
  c8_info[48].mFileTimeHi = 0U;
  c8_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[49].name = "eml_index_minus";
  c8_info[49].dominantType = "double";
  c8_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c8_info[49].fileTimeLo = 1286851178U;
  c8_info[49].fileTimeHi = 0U;
  c8_info[49].mFileTimeLo = 0U;
  c8_info[49].mFileTimeHi = 0U;
  c8_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c8_info[50].name = "eml_index_class";
  c8_info[50].dominantType = "";
  c8_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[50].fileTimeLo = 1323202978U;
  c8_info[50].fileTimeHi = 0U;
  c8_info[50].mFileTimeLo = 0U;
  c8_info[50].mFileTimeHi = 0U;
  c8_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[51].name = "eml_index_minus";
  c8_info[51].dominantType = "coder.internal.indexInt";
  c8_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c8_info[51].fileTimeLo = 1286851178U;
  c8_info[51].fileTimeHi = 0U;
  c8_info[51].mFileTimeLo = 0U;
  c8_info[51].mFileTimeHi = 0U;
  c8_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[52].name = "eml_index_times";
  c8_info[52].dominantType = "coder.internal.indexInt";
  c8_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c8_info[52].fileTimeLo = 1286851180U;
  c8_info[52].fileTimeHi = 0U;
  c8_info[52].mFileTimeLo = 0U;
  c8_info[52].mFileTimeHi = 0U;
  c8_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c8_info[53].name = "eml_index_class";
  c8_info[53].dominantType = "";
  c8_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[53].fileTimeLo = 1323202978U;
  c8_info[53].fileTimeHi = 0U;
  c8_info[53].mFileTimeLo = 0U;
  c8_info[53].mFileTimeHi = 0U;
  c8_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[54].name = "eml_index_plus";
  c8_info[54].dominantType = "coder.internal.indexInt";
  c8_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[54].fileTimeLo = 1286851178U;
  c8_info[54].fileTimeHi = 0U;
  c8_info[54].mFileTimeLo = 0U;
  c8_info[54].mFileTimeHi = 0U;
  c8_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[55].name = "eml_ixamax";
  c8_info[55].dominantType = "double";
  c8_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c8_info[55].fileTimeLo = 1299109170U;
  c8_info[55].fileTimeHi = 0U;
  c8_info[55].mFileTimeLo = 0U;
  c8_info[55].mFileTimeHi = 0U;
  c8_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c8_info[56].name = "eml_blas_inline";
  c8_info[56].dominantType = "";
  c8_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c8_info[56].fileTimeLo = 1299109168U;
  c8_info[56].fileTimeHi = 0U;
  c8_info[56].mFileTimeLo = 0U;
  c8_info[56].mFileTimeHi = 0U;
  c8_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c8_info[57].name = "eml_index_class";
  c8_info[57].dominantType = "";
  c8_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[57].fileTimeLo = 1323202978U;
  c8_info[57].fileTimeHi = 0U;
  c8_info[57].mFileTimeLo = 0U;
  c8_info[57].mFileTimeHi = 0U;
  c8_info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c8_info[58].name = "eml_refblas_ixamax";
  c8_info[58].dominantType = "double";
  c8_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c8_info[58].fileTimeLo = 1299109170U;
  c8_info[58].fileTimeHi = 0U;
  c8_info[58].mFileTimeLo = 0U;
  c8_info[58].mFileTimeHi = 0U;
  c8_info[59].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c8_info[59].name = "eml_index_class";
  c8_info[59].dominantType = "";
  c8_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[59].fileTimeLo = 1323202978U;
  c8_info[59].fileTimeHi = 0U;
  c8_info[59].mFileTimeLo = 0U;
  c8_info[59].mFileTimeHi = 0U;
  c8_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c8_info[60].name = "eml_xcabs1";
  c8_info[60].dominantType = "double";
  c8_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c8_info[60].fileTimeLo = 1286851106U;
  c8_info[60].fileTimeHi = 0U;
  c8_info[60].mFileTimeLo = 0U;
  c8_info[60].mFileTimeHi = 0U;
  c8_info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c8_info[61].name = "abs";
  c8_info[61].dominantType = "double";
  c8_info[61].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[61].fileTimeLo = 1343862766U;
  c8_info[61].fileTimeHi = 0U;
  c8_info[61].mFileTimeLo = 0U;
  c8_info[61].mFileTimeHi = 0U;
  c8_info[62].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[62].name = "eml_scalar_abs";
  c8_info[62].dominantType = "double";
  c8_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c8_info[62].fileTimeLo = 1286851112U;
  c8_info[62].fileTimeHi = 0U;
  c8_info[62].mFileTimeLo = 0U;
  c8_info[62].mFileTimeHi = 0U;
  c8_info[63].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c8_info[63].name = "eml_index_plus";
  c8_info[63].dominantType = "coder.internal.indexInt";
  c8_info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[63].fileTimeLo = 1286851178U;
  c8_info[63].fileTimeHi = 0U;
  c8_info[63].mFileTimeLo = 0U;
  c8_info[63].mFileTimeHi = 0U;
}

static void c8_b_info_helper(c8_ResolvedFunctionInfo c8_info[247])
{
  c8_info[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[64].name = "eml_xswap";
  c8_info[64].dominantType = "double";
  c8_info[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c8_info[64].fileTimeLo = 1299109178U;
  c8_info[64].fileTimeHi = 0U;
  c8_info[64].mFileTimeLo = 0U;
  c8_info[64].mFileTimeHi = 0U;
  c8_info[65].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c8_info[65].name = "eml_blas_inline";
  c8_info[65].dominantType = "";
  c8_info[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c8_info[65].fileTimeLo = 1299109168U;
  c8_info[65].fileTimeHi = 0U;
  c8_info[65].mFileTimeLo = 0U;
  c8_info[65].mFileTimeHi = 0U;
  c8_info[66].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c8_info[66].name = "eml_index_class";
  c8_info[66].dominantType = "";
  c8_info[66].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[66].fileTimeLo = 1323202978U;
  c8_info[66].fileTimeHi = 0U;
  c8_info[66].mFileTimeLo = 0U;
  c8_info[66].mFileTimeHi = 0U;
  c8_info[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c8_info[67].name = "eml_refblas_xswap";
  c8_info[67].dominantType = "double";
  c8_info[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c8_info[67].fileTimeLo = 1299109186U;
  c8_info[67].fileTimeHi = 0U;
  c8_info[67].mFileTimeLo = 0U;
  c8_info[67].mFileTimeHi = 0U;
  c8_info[68].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c8_info[68].name = "eml_index_class";
  c8_info[68].dominantType = "";
  c8_info[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[68].fileTimeLo = 1323202978U;
  c8_info[68].fileTimeHi = 0U;
  c8_info[68].mFileTimeLo = 0U;
  c8_info[68].mFileTimeHi = 0U;
  c8_info[69].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c8_info[69].name = "abs";
  c8_info[69].dominantType = "coder.internal.indexInt";
  c8_info[69].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[69].fileTimeLo = 1343862766U;
  c8_info[69].fileTimeHi = 0U;
  c8_info[69].mFileTimeLo = 0U;
  c8_info[69].mFileTimeHi = 0U;
  c8_info[70].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[70].name = "eml_scalar_abs";
  c8_info[70].dominantType = "coder.internal.indexInt";
  c8_info[70].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c8_info[70].fileTimeLo = 1286851112U;
  c8_info[70].fileTimeHi = 0U;
  c8_info[70].mFileTimeLo = 0U;
  c8_info[70].mFileTimeHi = 0U;
  c8_info[71].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c8_info[71].name = "eml_int_forloop_overflow_check";
  c8_info[71].dominantType = "";
  c8_info[71].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c8_info[71].fileTimeLo = 1346542740U;
  c8_info[71].fileTimeHi = 0U;
  c8_info[71].mFileTimeLo = 0U;
  c8_info[71].mFileTimeHi = 0U;
  c8_info[72].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c8_info[72].name = "intmax";
  c8_info[72].dominantType = "char";
  c8_info[72].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c8_info[72].fileTimeLo = 1311287716U;
  c8_info[72].fileTimeHi = 0U;
  c8_info[72].mFileTimeLo = 0U;
  c8_info[72].mFileTimeHi = 0U;
  c8_info[73].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c8_info[73].name = "eml_index_plus";
  c8_info[73].dominantType = "coder.internal.indexInt";
  c8_info[73].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[73].fileTimeLo = 1286851178U;
  c8_info[73].fileTimeHi = 0U;
  c8_info[73].mFileTimeLo = 0U;
  c8_info[73].mFileTimeHi = 0U;
  c8_info[74].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[74].name = "eml_div";
  c8_info[74].dominantType = "double";
  c8_info[74].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c8_info[74].fileTimeLo = 1313380210U;
  c8_info[74].fileTimeHi = 0U;
  c8_info[74].mFileTimeLo = 0U;
  c8_info[74].mFileTimeHi = 0U;
  c8_info[75].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[75].name = "eml_xgeru";
  c8_info[75].dominantType = "double";
  c8_info[75].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c8_info[75].fileTimeLo = 1299109174U;
  c8_info[75].fileTimeHi = 0U;
  c8_info[75].mFileTimeLo = 0U;
  c8_info[75].mFileTimeHi = 0U;
  c8_info[76].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c8_info[76].name = "eml_blas_inline";
  c8_info[76].dominantType = "";
  c8_info[76].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c8_info[76].fileTimeLo = 1299109168U;
  c8_info[76].fileTimeHi = 0U;
  c8_info[76].mFileTimeLo = 0U;
  c8_info[76].mFileTimeHi = 0U;
  c8_info[77].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c8_info[77].name = "eml_xger";
  c8_info[77].dominantType = "double";
  c8_info[77].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c8_info[77].fileTimeLo = 1299109174U;
  c8_info[77].fileTimeHi = 0U;
  c8_info[77].mFileTimeLo = 0U;
  c8_info[77].mFileTimeHi = 0U;
  c8_info[78].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c8_info[78].name = "eml_blas_inline";
  c8_info[78].dominantType = "";
  c8_info[78].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c8_info[78].fileTimeLo = 1299109168U;
  c8_info[78].fileTimeHi = 0U;
  c8_info[78].mFileTimeLo = 0U;
  c8_info[78].mFileTimeHi = 0U;
  c8_info[79].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c8_info[79].name = "mtimes";
  c8_info[79].dominantType = "double";
  c8_info[79].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[79].fileTimeLo = 1289552092U;
  c8_info[79].fileTimeHi = 0U;
  c8_info[79].mFileTimeLo = 0U;
  c8_info[79].mFileTimeHi = 0U;
  c8_info[80].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c8_info[80].name = "eml_index_class";
  c8_info[80].dominantType = "";
  c8_info[80].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[80].fileTimeLo = 1323202978U;
  c8_info[80].fileTimeHi = 0U;
  c8_info[80].mFileTimeLo = 0U;
  c8_info[80].mFileTimeHi = 0U;
  c8_info[81].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c8_info[81].name = "eml_refblas_xger";
  c8_info[81].dominantType = "double";
  c8_info[81].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c8_info[81].fileTimeLo = 1299109176U;
  c8_info[81].fileTimeHi = 0U;
  c8_info[81].mFileTimeLo = 0U;
  c8_info[81].mFileTimeHi = 0U;
  c8_info[82].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c8_info[82].name = "eml_refblas_xgerx";
  c8_info[82].dominantType = "char";
  c8_info[82].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c8_info[82].fileTimeLo = 1299109178U;
  c8_info[82].fileTimeHi = 0U;
  c8_info[82].mFileTimeLo = 0U;
  c8_info[82].mFileTimeHi = 0U;
  c8_info[83].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c8_info[83].name = "eml_index_class";
  c8_info[83].dominantType = "";
  c8_info[83].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[83].fileTimeLo = 1323202978U;
  c8_info[83].fileTimeHi = 0U;
  c8_info[83].mFileTimeLo = 0U;
  c8_info[83].mFileTimeHi = 0U;
  c8_info[84].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c8_info[84].name = "abs";
  c8_info[84].dominantType = "coder.internal.indexInt";
  c8_info[84].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[84].fileTimeLo = 1343862766U;
  c8_info[84].fileTimeHi = 0U;
  c8_info[84].mFileTimeLo = 0U;
  c8_info[84].mFileTimeHi = 0U;
  c8_info[85].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c8_info[85].name = "eml_index_minus";
  c8_info[85].dominantType = "double";
  c8_info[85].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c8_info[85].fileTimeLo = 1286851178U;
  c8_info[85].fileTimeHi = 0U;
  c8_info[85].mFileTimeLo = 0U;
  c8_info[85].mFileTimeHi = 0U;
  c8_info[86].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c8_info[86].name = "eml_index_plus";
  c8_info[86].dominantType = "double";
  c8_info[86].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[86].fileTimeLo = 1286851178U;
  c8_info[86].fileTimeHi = 0U;
  c8_info[86].mFileTimeLo = 0U;
  c8_info[86].mFileTimeHi = 0U;
  c8_info[87].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c8_info[87].name = "eml_index_plus";
  c8_info[87].dominantType = "coder.internal.indexInt";
  c8_info[87].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[87].fileTimeLo = 1286851178U;
  c8_info[87].fileTimeHi = 0U;
  c8_info[87].mFileTimeLo = 0U;
  c8_info[87].mFileTimeHi = 0U;
  c8_info[88].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c8_info[88].name = "eml_int_forloop_overflow_check";
  c8_info[88].dominantType = "";
  c8_info[88].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c8_info[88].fileTimeLo = 1346542740U;
  c8_info[88].fileTimeHi = 0U;
  c8_info[88].mFileTimeLo = 0U;
  c8_info[88].mFileTimeHi = 0U;
  c8_info[89].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/det.m";
  c8_info[89].name = "mtimes";
  c8_info[89].dominantType = "double";
  c8_info[89].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[89].fileTimeLo = 1289552092U;
  c8_info[89].fileTimeHi = 0U;
  c8_info[89].mFileTimeLo = 0U;
  c8_info[89].mFileTimeHi = 0U;
  c8_info[90].context = "";
  c8_info[90].name = "sqrt";
  c8_info[90].dominantType = "double";
  c8_info[90].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c8_info[90].fileTimeLo = 1343862786U;
  c8_info[90].fileTimeHi = 0U;
  c8_info[90].mFileTimeLo = 0U;
  c8_info[90].mFileTimeHi = 0U;
  c8_info[91].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c8_info[91].name = "eml_error";
  c8_info[91].dominantType = "char";
  c8_info[91].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c8_info[91].fileTimeLo = 1343862758U;
  c8_info[91].fileTimeHi = 0U;
  c8_info[91].mFileTimeLo = 0U;
  c8_info[91].mFileTimeHi = 0U;
  c8_info[92].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c8_info[92].name = "eml_scalar_sqrt";
  c8_info[92].dominantType = "double";
  c8_info[92].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c8_info[92].fileTimeLo = 1286851138U;
  c8_info[92].fileTimeHi = 0U;
  c8_info[92].mFileTimeLo = 0U;
  c8_info[92].mFileTimeHi = 0U;
  c8_info[93].context = "";
  c8_info[93].name = "mrdivide";
  c8_info[93].dominantType = "double";
  c8_info[93].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c8_info[93].fileTimeLo = 1357983948U;
  c8_info[93].fileTimeHi = 0U;
  c8_info[93].mFileTimeLo = 1319762366U;
  c8_info[93].mFileTimeHi = 0U;
  c8_info[94].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c8_info[94].name = "rdivide";
  c8_info[94].dominantType = "double";
  c8_info[94].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c8_info[94].fileTimeLo = 1346542788U;
  c8_info[94].fileTimeHi = 0U;
  c8_info[94].mFileTimeLo = 0U;
  c8_info[94].mFileTimeHi = 0U;
  c8_info[95].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c8_info[95].name = "eml_scalexp_compatible";
  c8_info[95].dominantType = "double";
  c8_info[95].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c8_info[95].fileTimeLo = 1286851196U;
  c8_info[95].fileTimeHi = 0U;
  c8_info[95].mFileTimeLo = 0U;
  c8_info[95].mFileTimeHi = 0U;
  c8_info[96].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c8_info[96].name = "eml_div";
  c8_info[96].dominantType = "double";
  c8_info[96].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c8_info[96].fileTimeLo = 1313380210U;
  c8_info[96].fileTimeHi = 0U;
  c8_info[96].mFileTimeLo = 0U;
  c8_info[96].mFileTimeHi = 0U;
  c8_info[97].context = "";
  c8_info[97].name = "mpower";
  c8_info[97].dominantType = "double";
  c8_info[97].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c8_info[97].fileTimeLo = 1286851242U;
  c8_info[97].fileTimeHi = 0U;
  c8_info[97].mFileTimeLo = 0U;
  c8_info[97].mFileTimeHi = 0U;
  c8_info[98].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c8_info[98].name = "power";
  c8_info[98].dominantType = "double";
  c8_info[98].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c8_info[98].fileTimeLo = 1348224330U;
  c8_info[98].fileTimeHi = 0U;
  c8_info[98].mFileTimeLo = 0U;
  c8_info[98].mFileTimeHi = 0U;
  c8_info[99].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c8_info[99].name = "eml_scalar_eg";
  c8_info[99].dominantType = "double";
  c8_info[99].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[99].fileTimeLo = 1286851196U;
  c8_info[99].fileTimeHi = 0U;
  c8_info[99].mFileTimeLo = 0U;
  c8_info[99].mFileTimeHi = 0U;
  c8_info[100].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c8_info[100].name = "eml_scalexp_alloc";
  c8_info[100].dominantType = "double";
  c8_info[100].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c8_info[100].fileTimeLo = 1352457260U;
  c8_info[100].fileTimeHi = 0U;
  c8_info[100].mFileTimeLo = 0U;
  c8_info[100].mFileTimeHi = 0U;
  c8_info[101].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c8_info[101].name = "floor";
  c8_info[101].dominantType = "double";
  c8_info[101].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c8_info[101].fileTimeLo = 1343862780U;
  c8_info[101].fileTimeHi = 0U;
  c8_info[101].mFileTimeLo = 0U;
  c8_info[101].mFileTimeHi = 0U;
  c8_info[102].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c8_info[102].name = "eml_error";
  c8_info[102].dominantType = "char";
  c8_info[102].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c8_info[102].fileTimeLo = 1343862758U;
  c8_info[102].fileTimeHi = 0U;
  c8_info[102].mFileTimeLo = 0U;
  c8_info[102].mFileTimeHi = 0U;
  c8_info[103].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c8_info[103].name = "eml_scalar_eg";
  c8_info[103].dominantType = "double";
  c8_info[103].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[103].fileTimeLo = 1286851196U;
  c8_info[103].fileTimeHi = 0U;
  c8_info[103].mFileTimeLo = 0U;
  c8_info[103].mFileTimeHi = 0U;
  c8_info[104].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c8_info[104].name = "sqrt";
  c8_info[104].dominantType = "double";
  c8_info[104].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c8_info[104].fileTimeLo = 1343862786U;
  c8_info[104].fileTimeHi = 0U;
  c8_info[104].mFileTimeLo = 0U;
  c8_info[104].mFileTimeHi = 0U;
  c8_info[105].context = "";
  c8_info[105].name = "pinv";
  c8_info[105].dominantType = "double";
  c8_info[105].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m";
  c8_info[105].fileTimeLo = 1286851228U;
  c8_info[105].fileTimeHi = 0U;
  c8_info[105].mFileTimeLo = 0U;
  c8_info[105].mFileTimeHi = 0U;
  c8_info[106].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c8_info[106].name = "eml_index_class";
  c8_info[106].dominantType = "";
  c8_info[106].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[106].fileTimeLo = 1323202978U;
  c8_info[106].fileTimeHi = 0U;
  c8_info[106].mFileTimeLo = 0U;
  c8_info[106].mFileTimeHi = 0U;
  c8_info[107].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c8_info[107].name = "eml_scalar_eg";
  c8_info[107].dominantType = "double";
  c8_info[107].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[107].fileTimeLo = 1286851196U;
  c8_info[107].fileTimeHi = 0U;
  c8_info[107].mFileTimeLo = 0U;
  c8_info[107].mFileTimeHi = 0U;
  c8_info[108].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c8_info[108].name = "svd";
  c8_info[108].dominantType = "double";
  c8_info[108].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c8_info[108].fileTimeLo = 1286851232U;
  c8_info[108].fileTimeHi = 0U;
  c8_info[108].mFileTimeLo = 0U;
  c8_info[108].mFileTimeHi = 0U;
  c8_info[109].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c8_info[109].name = "eml_index_class";
  c8_info[109].dominantType = "";
  c8_info[109].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[109].fileTimeLo = 1323202978U;
  c8_info[109].fileTimeHi = 0U;
  c8_info[109].mFileTimeLo = 0U;
  c8_info[109].mFileTimeHi = 0U;
  c8_info[110].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c8_info[110].name = "eml_int_forloop_overflow_check";
  c8_info[110].dominantType = "";
  c8_info[110].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c8_info[110].fileTimeLo = 1346542740U;
  c8_info[110].fileTimeHi = 0U;
  c8_info[110].mFileTimeLo = 0U;
  c8_info[110].mFileTimeHi = 0U;
  c8_info[111].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c8_info[111].name = "isfinite";
  c8_info[111].dominantType = "double";
  c8_info[111].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c8_info[111].fileTimeLo = 1286851158U;
  c8_info[111].fileTimeHi = 0U;
  c8_info[111].mFileTimeLo = 0U;
  c8_info[111].mFileTimeHi = 0U;
  c8_info[112].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c8_info[112].name = "isinf";
  c8_info[112].dominantType = "double";
  c8_info[112].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c8_info[112].fileTimeLo = 1286851160U;
  c8_info[112].fileTimeHi = 0U;
  c8_info[112].mFileTimeLo = 0U;
  c8_info[112].mFileTimeHi = 0U;
  c8_info[113].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c8_info[113].name = "isnan";
  c8_info[113].dominantType = "double";
  c8_info[113].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c8_info[113].fileTimeLo = 1286851160U;
  c8_info[113].fileTimeHi = 0U;
  c8_info[113].mFileTimeLo = 0U;
  c8_info[113].mFileTimeHi = 0U;
  c8_info[114].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c8_info[114].name = "eml_error";
  c8_info[114].dominantType = "char";
  c8_info[114].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c8_info[114].fileTimeLo = 1343862758U;
  c8_info[114].fileTimeHi = 0U;
  c8_info[114].mFileTimeLo = 0U;
  c8_info[114].mFileTimeHi = 0U;
  c8_info[115].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c8_info[115].name = "eml_xgesvd";
  c8_info[115].dominantType = "double";
  c8_info[115].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m";
  c8_info[115].fileTimeLo = 1286851206U;
  c8_info[115].fileTimeHi = 0U;
  c8_info[115].mFileTimeLo = 0U;
  c8_info[115].mFileTimeHi = 0U;
  c8_info[116].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m";
  c8_info[116].name = "eml_lapack_xgesvd";
  c8_info[116].dominantType = "double";
  c8_info[116].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m";
  c8_info[116].fileTimeLo = 1286851210U;
  c8_info[116].fileTimeHi = 0U;
  c8_info[116].mFileTimeLo = 0U;
  c8_info[116].mFileTimeHi = 0U;
  c8_info[117].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m";
  c8_info[117].name = "eml_matlab_zsvdc";
  c8_info[117].dominantType = "double";
  c8_info[117].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c8_info[117].fileTimeLo = 1295317266U;
  c8_info[117].fileTimeHi = 0U;
  c8_info[117].mFileTimeLo = 0U;
  c8_info[117].mFileTimeHi = 0U;
  c8_info[118].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c8_info[118].name = "eml_index_class";
  c8_info[118].dominantType = "";
  c8_info[118].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[118].fileTimeLo = 1323202978U;
  c8_info[118].fileTimeHi = 0U;
  c8_info[118].mFileTimeLo = 0U;
  c8_info[118].mFileTimeHi = 0U;
  c8_info[119].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c8_info[119].name = "eml_scalar_eg";
  c8_info[119].dominantType = "double";
  c8_info[119].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[119].fileTimeLo = 1286851196U;
  c8_info[119].fileTimeHi = 0U;
  c8_info[119].mFileTimeLo = 0U;
  c8_info[119].mFileTimeHi = 0U;
  c8_info[120].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c8_info[120].name = "eml_index_plus";
  c8_info[120].dominantType = "double";
  c8_info[120].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[120].fileTimeLo = 1286851178U;
  c8_info[120].fileTimeHi = 0U;
  c8_info[120].mFileTimeLo = 0U;
  c8_info[120].mFileTimeHi = 0U;
  c8_info[121].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c8_info[121].name = "min";
  c8_info[121].dominantType = "coder.internal.indexInt";
  c8_info[121].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c8_info[121].fileTimeLo = 1311287718U;
  c8_info[121].fileTimeHi = 0U;
  c8_info[121].mFileTimeLo = 0U;
  c8_info[121].mFileTimeHi = 0U;
  c8_info[122].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c8_info[122].name = "max";
  c8_info[122].dominantType = "double";
  c8_info[122].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c8_info[122].fileTimeLo = 1311287716U;
  c8_info[122].fileTimeHi = 0U;
  c8_info[122].mFileTimeLo = 0U;
  c8_info[122].mFileTimeHi = 0U;
  c8_info[123].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c8_info[123].name = "eml_min_or_max";
  c8_info[123].dominantType = "char";
  c8_info[123].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c8_info[123].fileTimeLo = 1334103890U;
  c8_info[123].fileTimeHi = 0U;
  c8_info[123].mFileTimeLo = 0U;
  c8_info[123].mFileTimeHi = 0U;
  c8_info[124].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c8_info[124].name = "eml_scalar_eg";
  c8_info[124].dominantType = "double";
  c8_info[124].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[124].fileTimeLo = 1286851196U;
  c8_info[124].fileTimeHi = 0U;
  c8_info[124].mFileTimeLo = 0U;
  c8_info[124].mFileTimeHi = 0U;
  c8_info[125].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c8_info[125].name = "eml_scalexp_alloc";
  c8_info[125].dominantType = "double";
  c8_info[125].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c8_info[125].fileTimeLo = 1352457260U;
  c8_info[125].fileTimeHi = 0U;
  c8_info[125].mFileTimeLo = 0U;
  c8_info[125].mFileTimeHi = 0U;
  c8_info[126].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c8_info[126].name = "eml_scalar_eg";
  c8_info[126].dominantType = "double";
  c8_info[126].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[126].fileTimeLo = 1286851196U;
  c8_info[126].fileTimeHi = 0U;
  c8_info[126].mFileTimeLo = 0U;
  c8_info[126].mFileTimeHi = 0U;
  c8_info[127].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c8_info[127].name = "eml_relop";
  c8_info[127].dominantType = "function_handle";
  c8_info[127].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c8_info[127].fileTimeLo = 1342483582U;
  c8_info[127].fileTimeHi = 0U;
  c8_info[127].mFileTimeLo = 0U;
  c8_info[127].mFileTimeHi = 0U;
}

static void c8_c_info_helper(c8_ResolvedFunctionInfo c8_info[247])
{
  c8_info[128].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c8_info[128].name = "coder.internal.indexIntRelop";
  c8_info[128].dominantType = "";
  c8_info[128].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m";
  c8_info[128].fileTimeLo = 1326760722U;
  c8_info[128].fileTimeHi = 0U;
  c8_info[128].mFileTimeLo = 0U;
  c8_info[128].mFileTimeHi = 0U;
  c8_info[129].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass";
  c8_info[129].name = "eml_float_model";
  c8_info[129].dominantType = "char";
  c8_info[129].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c8_info[129].fileTimeLo = 1326760396U;
  c8_info[129].fileTimeHi = 0U;
  c8_info[129].mFileTimeLo = 0U;
  c8_info[129].mFileTimeHi = 0U;
  c8_info[130].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass";
  c8_info[130].name = "intmin";
  c8_info[130].dominantType = "char";
  c8_info[130].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c8_info[130].fileTimeLo = 1311287718U;
  c8_info[130].fileTimeHi = 0U;
  c8_info[130].mFileTimeLo = 0U;
  c8_info[130].mFileTimeHi = 0U;
  c8_info[131].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c8_info[131].name = "isnan";
  c8_info[131].dominantType = "coder.internal.indexInt";
  c8_info[131].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c8_info[131].fileTimeLo = 1286851160U;
  c8_info[131].fileTimeHi = 0U;
  c8_info[131].mFileTimeLo = 0U;
  c8_info[131].mFileTimeHi = 0U;
  c8_info[132].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c8_info[132].name = "eml_index_minus";
  c8_info[132].dominantType = "double";
  c8_info[132].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c8_info[132].fileTimeLo = 1286851178U;
  c8_info[132].fileTimeHi = 0U;
  c8_info[132].mFileTimeLo = 0U;
  c8_info[132].mFileTimeHi = 0U;
  c8_info[133].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c8_info[133].name = "max";
  c8_info[133].dominantType = "coder.internal.indexInt";
  c8_info[133].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c8_info[133].fileTimeLo = 1311287716U;
  c8_info[133].fileTimeHi = 0U;
  c8_info[133].mFileTimeLo = 0U;
  c8_info[133].mFileTimeHi = 0U;
  c8_info[134].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c8_info[134].name = "eml_int_forloop_overflow_check";
  c8_info[134].dominantType = "";
  c8_info[134].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c8_info[134].fileTimeLo = 1346542740U;
  c8_info[134].fileTimeHi = 0U;
  c8_info[134].mFileTimeLo = 0U;
  c8_info[134].mFileTimeHi = 0U;
  c8_info[135].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c8_info[135].name = "eml_index_times";
  c8_info[135].dominantType = "coder.internal.indexInt";
  c8_info[135].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c8_info[135].fileTimeLo = 1286851180U;
  c8_info[135].fileTimeHi = 0U;
  c8_info[135].mFileTimeLo = 0U;
  c8_info[135].mFileTimeHi = 0U;
  c8_info[136].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c8_info[136].name = "eml_index_plus";
  c8_info[136].dominantType = "coder.internal.indexInt";
  c8_info[136].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[136].fileTimeLo = 1286851178U;
  c8_info[136].fileTimeHi = 0U;
  c8_info[136].mFileTimeLo = 0U;
  c8_info[136].mFileTimeHi = 0U;
  c8_info[137].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c8_info[137].name = "eml_index_minus";
  c8_info[137].dominantType = "coder.internal.indexInt";
  c8_info[137].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c8_info[137].fileTimeLo = 1286851178U;
  c8_info[137].fileTimeHi = 0U;
  c8_info[137].mFileTimeLo = 0U;
  c8_info[137].mFileTimeHi = 0U;
  c8_info[138].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c8_info[138].name = "eml_xnrm2";
  c8_info[138].dominantType = "double";
  c8_info[138].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c8_info[138].fileTimeLo = 1299109176U;
  c8_info[138].fileTimeHi = 0U;
  c8_info[138].mFileTimeLo = 0U;
  c8_info[138].mFileTimeHi = 0U;
  c8_info[139].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c8_info[139].name = "eml_blas_inline";
  c8_info[139].dominantType = "";
  c8_info[139].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c8_info[139].fileTimeLo = 1299109168U;
  c8_info[139].fileTimeHi = 0U;
  c8_info[139].mFileTimeLo = 0U;
  c8_info[139].mFileTimeHi = 0U;
  c8_info[140].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m!below_threshold";
  c8_info[140].name = "length";
  c8_info[140].dominantType = "double";
  c8_info[140].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c8_info[140].fileTimeLo = 1303178606U;
  c8_info[140].fileTimeHi = 0U;
  c8_info[140].mFileTimeLo = 0U;
  c8_info[140].mFileTimeHi = 0U;
  c8_info[141].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength";
  c8_info[141].name = "eml_index_class";
  c8_info[141].dominantType = "";
  c8_info[141].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[141].fileTimeLo = 1323202978U;
  c8_info[141].fileTimeHi = 0U;
  c8_info[141].mFileTimeLo = 0U;
  c8_info[141].mFileTimeHi = 0U;
  c8_info[142].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c8_info[142].name = "eml_index_class";
  c8_info[142].dominantType = "";
  c8_info[142].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[142].fileTimeLo = 1323202978U;
  c8_info[142].fileTimeHi = 0U;
  c8_info[142].mFileTimeLo = 0U;
  c8_info[142].mFileTimeHi = 0U;
  c8_info[143].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c8_info[143].name = "eml_refblas_xnrm2";
  c8_info[143].dominantType = "double";
  c8_info[143].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[143].fileTimeLo = 1299109184U;
  c8_info[143].fileTimeHi = 0U;
  c8_info[143].mFileTimeLo = 0U;
  c8_info[143].mFileTimeHi = 0U;
  c8_info[144].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[144].name = "abs";
  c8_info[144].dominantType = "double";
  c8_info[144].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[144].fileTimeLo = 1343862766U;
  c8_info[144].fileTimeHi = 0U;
  c8_info[144].mFileTimeLo = 0U;
  c8_info[144].mFileTimeHi = 0U;
  c8_info[145].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[145].name = "realmin";
  c8_info[145].dominantType = "char";
  c8_info[145].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c8_info[145].fileTimeLo = 1307683642U;
  c8_info[145].fileTimeHi = 0U;
  c8_info[145].mFileTimeLo = 0U;
  c8_info[145].mFileTimeHi = 0U;
  c8_info[146].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[146].name = "eml_index_class";
  c8_info[146].dominantType = "";
  c8_info[146].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[146].fileTimeLo = 1323202978U;
  c8_info[146].fileTimeHi = 0U;
  c8_info[146].mFileTimeLo = 0U;
  c8_info[146].mFileTimeHi = 0U;
  c8_info[147].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[147].name = "eml_index_minus";
  c8_info[147].dominantType = "double";
  c8_info[147].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c8_info[147].fileTimeLo = 1286851178U;
  c8_info[147].fileTimeHi = 0U;
  c8_info[147].mFileTimeLo = 0U;
  c8_info[147].mFileTimeHi = 0U;
  c8_info[148].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[148].name = "eml_index_times";
  c8_info[148].dominantType = "coder.internal.indexInt";
  c8_info[148].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c8_info[148].fileTimeLo = 1286851180U;
  c8_info[148].fileTimeHi = 0U;
  c8_info[148].mFileTimeLo = 0U;
  c8_info[148].mFileTimeHi = 0U;
  c8_info[149].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[149].name = "eml_index_plus";
  c8_info[149].dominantType = "coder.internal.indexInt";
  c8_info[149].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[149].fileTimeLo = 1286851178U;
  c8_info[149].fileTimeHi = 0U;
  c8_info[149].mFileTimeLo = 0U;
  c8_info[149].mFileTimeHi = 0U;
  c8_info[150].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[150].name = "eml_int_forloop_overflow_check";
  c8_info[150].dominantType = "";
  c8_info[150].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c8_info[150].fileTimeLo = 1346542740U;
  c8_info[150].fileTimeHi = 0U;
  c8_info[150].mFileTimeLo = 0U;
  c8_info[150].mFileTimeHi = 0U;
  c8_info[151].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c8_info[151].name = "eml_div";
  c8_info[151].dominantType = "double";
  c8_info[151].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c8_info[151].fileTimeLo = 1313380210U;
  c8_info[151].fileTimeHi = 0U;
  c8_info[151].mFileTimeLo = 0U;
  c8_info[151].mFileTimeHi = 0U;
  c8_info[152].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c8_info[152].name = "eml_xscal";
  c8_info[152].dominantType = "double";
  c8_info[152].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  c8_info[152].fileTimeLo = 1299109176U;
  c8_info[152].fileTimeHi = 0U;
  c8_info[152].mFileTimeLo = 0U;
  c8_info[152].mFileTimeHi = 0U;
  c8_info[153].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  c8_info[153].name = "eml_blas_inline";
  c8_info[153].dominantType = "";
  c8_info[153].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c8_info[153].fileTimeLo = 1299109168U;
  c8_info[153].fileTimeHi = 0U;
  c8_info[153].mFileTimeLo = 0U;
  c8_info[153].mFileTimeHi = 0U;
  c8_info[154].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m!below_threshold";
  c8_info[154].name = "length";
  c8_info[154].dominantType = "double";
  c8_info[154].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c8_info[154].fileTimeLo = 1303178606U;
  c8_info[154].fileTimeHi = 0U;
  c8_info[154].mFileTimeLo = 0U;
  c8_info[154].mFileTimeHi = 0U;
  c8_info[155].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c8_info[155].name = "eml_index_class";
  c8_info[155].dominantType = "";
  c8_info[155].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[155].fileTimeLo = 1323202978U;
  c8_info[155].fileTimeHi = 0U;
  c8_info[155].mFileTimeLo = 0U;
  c8_info[155].mFileTimeHi = 0U;
  c8_info[156].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c8_info[156].name = "eml_scalar_eg";
  c8_info[156].dominantType = "double";
  c8_info[156].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[156].fileTimeLo = 1286851196U;
  c8_info[156].fileTimeHi = 0U;
  c8_info[156].mFileTimeLo = 0U;
  c8_info[156].mFileTimeHi = 0U;
  c8_info[157].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c8_info[157].name = "eml_refblas_xscal";
  c8_info[157].dominantType = "double";
  c8_info[157].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c8_info[157].fileTimeLo = 1299109184U;
  c8_info[157].fileTimeHi = 0U;
  c8_info[157].mFileTimeLo = 0U;
  c8_info[157].mFileTimeHi = 0U;
  c8_info[158].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c8_info[158].name = "eml_index_class";
  c8_info[158].dominantType = "";
  c8_info[158].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[158].fileTimeLo = 1323202978U;
  c8_info[158].fileTimeHi = 0U;
  c8_info[158].mFileTimeLo = 0U;
  c8_info[158].mFileTimeHi = 0U;
  c8_info[159].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c8_info[159].name = "eml_index_minus";
  c8_info[159].dominantType = "double";
  c8_info[159].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c8_info[159].fileTimeLo = 1286851178U;
  c8_info[159].fileTimeHi = 0U;
  c8_info[159].mFileTimeLo = 0U;
  c8_info[159].mFileTimeHi = 0U;
  c8_info[160].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c8_info[160].name = "eml_index_times";
  c8_info[160].dominantType = "coder.internal.indexInt";
  c8_info[160].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c8_info[160].fileTimeLo = 1286851180U;
  c8_info[160].fileTimeHi = 0U;
  c8_info[160].mFileTimeLo = 0U;
  c8_info[160].mFileTimeHi = 0U;
  c8_info[161].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c8_info[161].name = "eml_index_plus";
  c8_info[161].dominantType = "coder.internal.indexInt";
  c8_info[161].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[161].fileTimeLo = 1286851178U;
  c8_info[161].fileTimeHi = 0U;
  c8_info[161].mFileTimeLo = 0U;
  c8_info[161].mFileTimeHi = 0U;
  c8_info[162].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c8_info[162].name = "eml_int_forloop_overflow_check";
  c8_info[162].dominantType = "";
  c8_info[162].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c8_info[162].fileTimeLo = 1346542740U;
  c8_info[162].fileTimeHi = 0U;
  c8_info[162].mFileTimeLo = 0U;
  c8_info[162].mFileTimeHi = 0U;
  c8_info[163].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c8_info[163].name = "eml_xdotc";
  c8_info[163].dominantType = "double";
  c8_info[163].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c8_info[163].fileTimeLo = 1299109172U;
  c8_info[163].fileTimeHi = 0U;
  c8_info[163].mFileTimeLo = 0U;
  c8_info[163].mFileTimeHi = 0U;
  c8_info[164].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c8_info[164].name = "eml_blas_inline";
  c8_info[164].dominantType = "";
  c8_info[164].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c8_info[164].fileTimeLo = 1299109168U;
  c8_info[164].fileTimeHi = 0U;
  c8_info[164].mFileTimeLo = 0U;
  c8_info[164].mFileTimeHi = 0U;
  c8_info[165].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c8_info[165].name = "eml_xdot";
  c8_info[165].dominantType = "double";
  c8_info[165].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c8_info[165].fileTimeLo = 1299109172U;
  c8_info[165].fileTimeHi = 0U;
  c8_info[165].mFileTimeLo = 0U;
  c8_info[165].mFileTimeHi = 0U;
  c8_info[166].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c8_info[166].name = "eml_blas_inline";
  c8_info[166].dominantType = "";
  c8_info[166].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c8_info[166].fileTimeLo = 1299109168U;
  c8_info[166].fileTimeHi = 0U;
  c8_info[166].mFileTimeLo = 0U;
  c8_info[166].mFileTimeHi = 0U;
  c8_info[167].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m!below_threshold";
  c8_info[167].name = "length";
  c8_info[167].dominantType = "double";
  c8_info[167].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c8_info[167].fileTimeLo = 1303178606U;
  c8_info[167].fileTimeHi = 0U;
  c8_info[167].mFileTimeLo = 0U;
  c8_info[167].mFileTimeHi = 0U;
  c8_info[168].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c8_info[168].name = "eml_index_class";
  c8_info[168].dominantType = "";
  c8_info[168].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[168].fileTimeLo = 1323202978U;
  c8_info[168].fileTimeHi = 0U;
  c8_info[168].mFileTimeLo = 0U;
  c8_info[168].mFileTimeHi = 0U;
  c8_info[169].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c8_info[169].name = "eml_refblas_xdot";
  c8_info[169].dominantType = "double";
  c8_info[169].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c8_info[169].fileTimeLo = 1299109172U;
  c8_info[169].fileTimeHi = 0U;
  c8_info[169].mFileTimeLo = 0U;
  c8_info[169].mFileTimeHi = 0U;
  c8_info[170].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c8_info[170].name = "eml_refblas_xdotx";
  c8_info[170].dominantType = "char";
  c8_info[170].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c8_info[170].fileTimeLo = 1299109174U;
  c8_info[170].fileTimeHi = 0U;
  c8_info[170].mFileTimeLo = 0U;
  c8_info[170].mFileTimeHi = 0U;
  c8_info[171].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c8_info[171].name = "eml_scalar_eg";
  c8_info[171].dominantType = "double";
  c8_info[171].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[171].fileTimeLo = 1286851196U;
  c8_info[171].fileTimeHi = 0U;
  c8_info[171].mFileTimeLo = 0U;
  c8_info[171].mFileTimeHi = 0U;
  c8_info[172].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c8_info[172].name = "eml_index_class";
  c8_info[172].dominantType = "";
  c8_info[172].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[172].fileTimeLo = 1323202978U;
  c8_info[172].fileTimeHi = 0U;
  c8_info[172].mFileTimeLo = 0U;
  c8_info[172].mFileTimeHi = 0U;
  c8_info[173].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c8_info[173].name = "eml_int_forloop_overflow_check";
  c8_info[173].dominantType = "";
  c8_info[173].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c8_info[173].fileTimeLo = 1346542740U;
  c8_info[173].fileTimeHi = 0U;
  c8_info[173].mFileTimeLo = 0U;
  c8_info[173].mFileTimeHi = 0U;
  c8_info[174].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c8_info[174].name = "eml_index_plus";
  c8_info[174].dominantType = "coder.internal.indexInt";
  c8_info[174].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[174].fileTimeLo = 1286851178U;
  c8_info[174].fileTimeHi = 0U;
  c8_info[174].mFileTimeLo = 0U;
  c8_info[174].mFileTimeHi = 0U;
  c8_info[175].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c8_info[175].name = "eml_xaxpy";
  c8_info[175].dominantType = "double";
  c8_info[175].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m";
  c8_info[175].fileTimeLo = 1299109170U;
  c8_info[175].fileTimeHi = 0U;
  c8_info[175].mFileTimeLo = 0U;
  c8_info[175].mFileTimeHi = 0U;
  c8_info[176].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m";
  c8_info[176].name = "eml_blas_inline";
  c8_info[176].dominantType = "";
  c8_info[176].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c8_info[176].fileTimeLo = 1299109168U;
  c8_info[176].fileTimeHi = 0U;
  c8_info[176].mFileTimeLo = 0U;
  c8_info[176].mFileTimeHi = 0U;
  c8_info[177].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m!below_threshold";
  c8_info[177].name = "length";
  c8_info[177].dominantType = "double";
  c8_info[177].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c8_info[177].fileTimeLo = 1303178606U;
  c8_info[177].fileTimeHi = 0U;
  c8_info[177].mFileTimeLo = 0U;
  c8_info[177].mFileTimeHi = 0U;
  c8_info[178].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m";
  c8_info[178].name = "eml_index_class";
  c8_info[178].dominantType = "";
  c8_info[178].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[178].fileTimeLo = 1323202978U;
  c8_info[178].fileTimeHi = 0U;
  c8_info[178].mFileTimeLo = 0U;
  c8_info[178].mFileTimeHi = 0U;
  c8_info[179].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m";
  c8_info[179].name = "eml_scalar_eg";
  c8_info[179].dominantType = "double";
  c8_info[179].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[179].fileTimeLo = 1286851196U;
  c8_info[179].fileTimeHi = 0U;
  c8_info[179].mFileTimeLo = 0U;
  c8_info[179].mFileTimeHi = 0U;
  c8_info[180].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m";
  c8_info[180].name = "eml_refblas_xaxpy";
  c8_info[180].dominantType = "double";
  c8_info[180].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c8_info[180].fileTimeLo = 1299109172U;
  c8_info[180].fileTimeHi = 0U;
  c8_info[180].mFileTimeLo = 0U;
  c8_info[180].mFileTimeHi = 0U;
  c8_info[181].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c8_info[181].name = "eml_index_class";
  c8_info[181].dominantType = "";
  c8_info[181].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[181].fileTimeLo = 1323202978U;
  c8_info[181].fileTimeHi = 0U;
  c8_info[181].mFileTimeLo = 0U;
  c8_info[181].mFileTimeHi = 0U;
  c8_info[182].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c8_info[182].name = "eml_isa_uint";
  c8_info[182].dominantType = "coder.internal.indexInt";
  c8_info[182].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c8_info[182].fileTimeLo = 1286851184U;
  c8_info[182].fileTimeHi = 0U;
  c8_info[182].mFileTimeLo = 0U;
  c8_info[182].mFileTimeHi = 0U;
  c8_info[183].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c8_info[183].name = "eml_index_minus";
  c8_info[183].dominantType = "double";
  c8_info[183].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c8_info[183].fileTimeLo = 1286851178U;
  c8_info[183].fileTimeHi = 0U;
  c8_info[183].mFileTimeLo = 0U;
  c8_info[183].mFileTimeHi = 0U;
  c8_info[184].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c8_info[184].name = "eml_int_forloop_overflow_check";
  c8_info[184].dominantType = "";
  c8_info[184].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c8_info[184].fileTimeLo = 1346542740U;
  c8_info[184].fileTimeHi = 0U;
  c8_info[184].mFileTimeLo = 0U;
  c8_info[184].mFileTimeHi = 0U;
  c8_info[185].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c8_info[185].name = "eml_index_plus";
  c8_info[185].dominantType = "double";
  c8_info[185].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[185].fileTimeLo = 1286851178U;
  c8_info[185].fileTimeHi = 0U;
  c8_info[185].mFileTimeLo = 0U;
  c8_info[185].mFileTimeHi = 0U;
  c8_info[186].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c8_info[186].name = "eml_index_plus";
  c8_info[186].dominantType = "coder.internal.indexInt";
  c8_info[186].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[186].fileTimeLo = 1286851178U;
  c8_info[186].fileTimeHi = 0U;
  c8_info[186].mFileTimeLo = 0U;
  c8_info[186].mFileTimeHi = 0U;
  c8_info[187].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c8_info[187].name = "intmin";
  c8_info[187].dominantType = "char";
  c8_info[187].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c8_info[187].fileTimeLo = 1311287718U;
  c8_info[187].fileTimeHi = 0U;
  c8_info[187].mFileTimeLo = 0U;
  c8_info[187].mFileTimeHi = 0U;
  c8_info[188].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c8_info[188].name = "abs";
  c8_info[188].dominantType = "double";
  c8_info[188].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[188].fileTimeLo = 1343862766U;
  c8_info[188].fileTimeHi = 0U;
  c8_info[188].mFileTimeLo = 0U;
  c8_info[188].mFileTimeHi = 0U;
  c8_info[189].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c8_info[189].name = "mtimes";
  c8_info[189].dominantType = "double";
  c8_info[189].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[189].fileTimeLo = 1289552092U;
  c8_info[189].fileTimeHi = 0U;
  c8_info[189].mFileTimeLo = 0U;
  c8_info[189].mFileTimeHi = 0U;
  c8_info[190].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c8_info[190].name = "realmin";
  c8_info[190].dominantType = "char";
  c8_info[190].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c8_info[190].fileTimeLo = 1307683642U;
  c8_info[190].fileTimeHi = 0U;
  c8_info[190].mFileTimeLo = 0U;
  c8_info[190].mFileTimeHi = 0U;
  c8_info[191].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c8_info[191].name = "eps";
  c8_info[191].dominantType = "char";
  c8_info[191].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c8_info[191].fileTimeLo = 1326760396U;
  c8_info[191].fileTimeHi = 0U;
  c8_info[191].mFileTimeLo = 0U;
  c8_info[191].mFileTimeHi = 0U;
}

static void c8_d_info_helper(c8_ResolvedFunctionInfo c8_info[247])
{
  c8_info[192].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c8_info[192].name = "eml_error";
  c8_info[192].dominantType = "char";
  c8_info[192].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c8_info[192].fileTimeLo = 1343862758U;
  c8_info[192].fileTimeHi = 0U;
  c8_info[192].mFileTimeLo = 0U;
  c8_info[192].mFileTimeHi = 0U;
  c8_info[193].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c8_info[193].name = "eml_const_nonsingleton_dim";
  c8_info[193].dominantType = "double";
  c8_info[193].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c8_info[193].fileTimeLo = 1286851096U;
  c8_info[193].fileTimeHi = 0U;
  c8_info[193].mFileTimeLo = 0U;
  c8_info[193].mFileTimeHi = 0U;
  c8_info[194].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c8_info[194].name = "eml_scalar_eg";
  c8_info[194].dominantType = "double";
  c8_info[194].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[194].fileTimeLo = 1286851196U;
  c8_info[194].fileTimeHi = 0U;
  c8_info[194].mFileTimeLo = 0U;
  c8_info[194].mFileTimeHi = 0U;
  c8_info[195].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c8_info[195].name = "eml_index_class";
  c8_info[195].dominantType = "";
  c8_info[195].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[195].fileTimeLo = 1323202978U;
  c8_info[195].fileTimeHi = 0U;
  c8_info[195].mFileTimeLo = 0U;
  c8_info[195].mFileTimeHi = 0U;
  c8_info[196].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c8_info[196].name = "eml_index_class";
  c8_info[196].dominantType = "";
  c8_info[196].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[196].fileTimeLo = 1323202978U;
  c8_info[196].fileTimeHi = 0U;
  c8_info[196].mFileTimeLo = 0U;
  c8_info[196].mFileTimeHi = 0U;
  c8_info[197].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c8_info[197].name = "isnan";
  c8_info[197].dominantType = "double";
  c8_info[197].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c8_info[197].fileTimeLo = 1286851160U;
  c8_info[197].fileTimeHi = 0U;
  c8_info[197].mFileTimeLo = 0U;
  c8_info[197].mFileTimeHi = 0U;
  c8_info[198].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c8_info[198].name = "eml_index_plus";
  c8_info[198].dominantType = "coder.internal.indexInt";
  c8_info[198].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[198].fileTimeLo = 1286851178U;
  c8_info[198].fileTimeHi = 0U;
  c8_info[198].mFileTimeLo = 0U;
  c8_info[198].mFileTimeHi = 0U;
  c8_info[199].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c8_info[199].name = "eml_int_forloop_overflow_check";
  c8_info[199].dominantType = "";
  c8_info[199].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c8_info[199].fileTimeLo = 1346542740U;
  c8_info[199].fileTimeHi = 0U;
  c8_info[199].mFileTimeLo = 0U;
  c8_info[199].mFileTimeHi = 0U;
  c8_info[200].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c8_info[200].name = "eml_relop";
  c8_info[200].dominantType = "function_handle";
  c8_info[200].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c8_info[200].fileTimeLo = 1342483582U;
  c8_info[200].fileTimeHi = 0U;
  c8_info[200].mFileTimeLo = 0U;
  c8_info[200].mFileTimeHi = 0U;
  c8_info[201].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c8_info[201].name = "sqrt";
  c8_info[201].dominantType = "double";
  c8_info[201].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c8_info[201].fileTimeLo = 1343862786U;
  c8_info[201].fileTimeHi = 0U;
  c8_info[201].mFileTimeLo = 0U;
  c8_info[201].mFileTimeHi = 0U;
  c8_info[202].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c8_info[202].name = "eml_xrotg";
  c8_info[202].dominantType = "double";
  c8_info[202].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m";
  c8_info[202].fileTimeLo = 1299109176U;
  c8_info[202].fileTimeHi = 0U;
  c8_info[202].mFileTimeLo = 0U;
  c8_info[202].mFileTimeHi = 0U;
  c8_info[203].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m";
  c8_info[203].name = "eml_blas_inline";
  c8_info[203].dominantType = "";
  c8_info[203].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c8_info[203].fileTimeLo = 1299109168U;
  c8_info[203].fileTimeHi = 0U;
  c8_info[203].mFileTimeLo = 0U;
  c8_info[203].mFileTimeHi = 0U;
  c8_info[204].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m";
  c8_info[204].name = "eml_refblas_xrotg";
  c8_info[204].dominantType = "double";
  c8_info[204].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c8_info[204].fileTimeLo = 1299109184U;
  c8_info[204].fileTimeHi = 0U;
  c8_info[204].mFileTimeLo = 0U;
  c8_info[204].mFileTimeHi = 0U;
  c8_info[205].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c8_info[205].name = "abs";
  c8_info[205].dominantType = "double";
  c8_info[205].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[205].fileTimeLo = 1343862766U;
  c8_info[205].fileTimeHi = 0U;
  c8_info[205].mFileTimeLo = 0U;
  c8_info[205].mFileTimeHi = 0U;
  c8_info[206].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c8_info[206].name = "mrdivide";
  c8_info[206].dominantType = "double";
  c8_info[206].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c8_info[206].fileTimeLo = 1357983948U;
  c8_info[206].fileTimeHi = 0U;
  c8_info[206].mFileTimeLo = 1319762366U;
  c8_info[206].mFileTimeHi = 0U;
  c8_info[207].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c8_info[207].name = "sqrt";
  c8_info[207].dominantType = "double";
  c8_info[207].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c8_info[207].fileTimeLo = 1343862786U;
  c8_info[207].fileTimeHi = 0U;
  c8_info[207].mFileTimeLo = 0U;
  c8_info[207].mFileTimeHi = 0U;
  c8_info[208].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m!eml_ceval_xrotg";
  c8_info[208].name = "eml_scalar_eg";
  c8_info[208].dominantType = "double";
  c8_info[208].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[208].fileTimeLo = 1286851196U;
  c8_info[208].fileTimeHi = 0U;
  c8_info[208].mFileTimeLo = 0U;
  c8_info[208].mFileTimeHi = 0U;
  c8_info[209].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c8_info[209].name = "eml_xrot";
  c8_info[209].dominantType = "double";
  c8_info[209].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrot.m";
  c8_info[209].fileTimeLo = 1299109176U;
  c8_info[209].fileTimeHi = 0U;
  c8_info[209].mFileTimeLo = 0U;
  c8_info[209].mFileTimeHi = 0U;
  c8_info[210].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrot.m";
  c8_info[210].name = "eml_blas_inline";
  c8_info[210].dominantType = "";
  c8_info[210].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c8_info[210].fileTimeLo = 1299109168U;
  c8_info[210].fileTimeHi = 0U;
  c8_info[210].mFileTimeLo = 0U;
  c8_info[210].mFileTimeHi = 0U;
  c8_info[211].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m";
  c8_info[211].name = "eml_index_class";
  c8_info[211].dominantType = "";
  c8_info[211].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[211].fileTimeLo = 1323202978U;
  c8_info[211].fileTimeHi = 0U;
  c8_info[211].mFileTimeLo = 0U;
  c8_info[211].mFileTimeHi = 0U;
  c8_info[212].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m";
  c8_info[212].name = "eml_scalar_eg";
  c8_info[212].dominantType = "double";
  c8_info[212].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[212].fileTimeLo = 1286851196U;
  c8_info[212].fileTimeHi = 0U;
  c8_info[212].mFileTimeLo = 0U;
  c8_info[212].mFileTimeHi = 0U;
  c8_info[213].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m";
  c8_info[213].name = "eml_refblas_xrot";
  c8_info[213].dominantType = "double";
  c8_info[213].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  c8_info[213].fileTimeLo = 1299109184U;
  c8_info[213].fileTimeHi = 0U;
  c8_info[213].mFileTimeLo = 0U;
  c8_info[213].mFileTimeHi = 0U;
  c8_info[214].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  c8_info[214].name = "eml_index_class";
  c8_info[214].dominantType = "";
  c8_info[214].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[214].fileTimeLo = 1323202978U;
  c8_info[214].fileTimeHi = 0U;
  c8_info[214].mFileTimeLo = 0U;
  c8_info[214].mFileTimeHi = 0U;
  c8_info[215].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  c8_info[215].name = "eml_int_forloop_overflow_check";
  c8_info[215].dominantType = "";
  c8_info[215].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c8_info[215].fileTimeLo = 1346542740U;
  c8_info[215].fileTimeHi = 0U;
  c8_info[215].mFileTimeLo = 0U;
  c8_info[215].mFileTimeHi = 0U;
  c8_info[216].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  c8_info[216].name = "mtimes";
  c8_info[216].dominantType = "double";
  c8_info[216].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[216].fileTimeLo = 1289552092U;
  c8_info[216].fileTimeHi = 0U;
  c8_info[216].mFileTimeLo = 0U;
  c8_info[216].mFileTimeHi = 0U;
  c8_info[217].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  c8_info[217].name = "eml_index_plus";
  c8_info[217].dominantType = "coder.internal.indexInt";
  c8_info[217].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[217].fileTimeLo = 1286851178U;
  c8_info[217].fileTimeHi = 0U;
  c8_info[217].mFileTimeLo = 0U;
  c8_info[217].mFileTimeHi = 0U;
  c8_info[218].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c8_info[218].name = "eml_xswap";
  c8_info[218].dominantType = "double";
  c8_info[218].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c8_info[218].fileTimeLo = 1299109178U;
  c8_info[218].fileTimeHi = 0U;
  c8_info[218].mFileTimeLo = 0U;
  c8_info[218].mFileTimeHi = 0U;
  c8_info[219].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c8_info[219].name = "mtimes";
  c8_info[219].dominantType = "double";
  c8_info[219].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[219].fileTimeLo = 1289552092U;
  c8_info[219].fileTimeHi = 0U;
  c8_info[219].mFileTimeLo = 0U;
  c8_info[219].mFileTimeHi = 0U;
  c8_info[220].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c8_info[220].name = "eps";
  c8_info[220].dominantType = "char";
  c8_info[220].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c8_info[220].fileTimeLo = 1326760396U;
  c8_info[220].fileTimeHi = 0U;
  c8_info[220].mFileTimeLo = 0U;
  c8_info[220].mFileTimeHi = 0U;
  c8_info[221].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c8_info[221].name = "eml_int_forloop_overflow_check";
  c8_info[221].dominantType = "";
  c8_info[221].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c8_info[221].fileTimeLo = 1346542740U;
  c8_info[221].fileTimeHi = 0U;
  c8_info[221].mFileTimeLo = 0U;
  c8_info[221].mFileTimeHi = 0U;
  c8_info[222].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c8_info[222].name = "eml_index_plus";
  c8_info[222].dominantType = "double";
  c8_info[222].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[222].fileTimeLo = 1286851178U;
  c8_info[222].fileTimeHi = 0U;
  c8_info[222].mFileTimeLo = 0U;
  c8_info[222].mFileTimeHi = 0U;
  c8_info[223].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c8_info[223].name = "eml_div";
  c8_info[223].dominantType = "double";
  c8_info[223].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c8_info[223].fileTimeLo = 1313380210U;
  c8_info[223].fileTimeHi = 0U;
  c8_info[223].mFileTimeLo = 0U;
  c8_info[223].mFileTimeHi = 0U;
  c8_info[224].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c8_info[224].name = "eml_xscal";
  c8_info[224].dominantType = "double";
  c8_info[224].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  c8_info[224].fileTimeLo = 1299109176U;
  c8_info[224].fileTimeHi = 0U;
  c8_info[224].mFileTimeLo = 0U;
  c8_info[224].mFileTimeHi = 0U;
  c8_info[225].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c8_info[225].name = "eml_index_plus";
  c8_info[225].dominantType = "coder.internal.indexInt";
  c8_info[225].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[225].fileTimeLo = 1286851178U;
  c8_info[225].fileTimeHi = 0U;
  c8_info[225].mFileTimeLo = 0U;
  c8_info[225].mFileTimeHi = 0U;
  c8_info[226].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c8_info[226].name = "eml_xgemm";
  c8_info[226].dominantType = "char";
  c8_info[226].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c8_info[226].fileTimeLo = 1299109172U;
  c8_info[226].fileTimeHi = 0U;
  c8_info[226].mFileTimeLo = 0U;
  c8_info[226].mFileTimeHi = 0U;
  c8_info[227].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c8_info[227].name = "min";
  c8_info[227].dominantType = "double";
  c8_info[227].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c8_info[227].fileTimeLo = 1311287718U;
  c8_info[227].fileTimeHi = 0U;
  c8_info[227].mFileTimeLo = 0U;
  c8_info[227].mFileTimeHi = 0U;
  c8_info[228].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c8_info[228].name = "eml_index_minus";
  c8_info[228].dominantType = "double";
  c8_info[228].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c8_info[228].fileTimeLo = 1286851178U;
  c8_info[228].fileTimeHi = 0U;
  c8_info[228].mFileTimeLo = 0U;
  c8_info[228].mFileTimeHi = 0U;
  c8_info[229].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c8_info[229].name = "eml_index_class";
  c8_info[229].dominantType = "";
  c8_info[229].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[229].fileTimeLo = 1323202978U;
  c8_info[229].fileTimeHi = 0U;
  c8_info[229].mFileTimeLo = 0U;
  c8_info[229].mFileTimeHi = 0U;
  c8_info[230].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c8_info[230].name = "eml_scalar_eg";
  c8_info[230].dominantType = "double";
  c8_info[230].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[230].fileTimeLo = 1286851196U;
  c8_info[230].fileTimeHi = 0U;
  c8_info[230].mFileTimeLo = 0U;
  c8_info[230].mFileTimeHi = 0U;
  c8_info[231].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c8_info[231].name = "eml_index_times";
  c8_info[231].dominantType = "coder.internal.indexInt";
  c8_info[231].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c8_info[231].fileTimeLo = 1286851180U;
  c8_info[231].fileTimeHi = 0U;
  c8_info[231].mFileTimeLo = 0U;
  c8_info[231].mFileTimeHi = 0U;
  c8_info[232].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c8_info[232].name = "eml_index_plus";
  c8_info[232].dominantType = "coder.internal.indexInt";
  c8_info[232].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[232].fileTimeLo = 1286851178U;
  c8_info[232].fileTimeHi = 0U;
  c8_info[232].mFileTimeLo = 0U;
  c8_info[232].mFileTimeHi = 0U;
  c8_info[233].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c8_info[233].name = "eml_int_forloop_overflow_check";
  c8_info[233].dominantType = "";
  c8_info[233].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c8_info[233].fileTimeLo = 1346542740U;
  c8_info[233].fileTimeHi = 0U;
  c8_info[233].mFileTimeLo = 0U;
  c8_info[233].mFileTimeHi = 0U;
  c8_info[234].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c8_info[234].name = "eml_index_plus";
  c8_info[234].dominantType = "double";
  c8_info[234].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[234].fileTimeLo = 1286851178U;
  c8_info[234].fileTimeHi = 0U;
  c8_info[234].mFileTimeLo = 0U;
  c8_info[234].mFileTimeHi = 0U;
  c8_info[235].context = "";
  c8_info[235].name = "svd";
  c8_info[235].dominantType = "double";
  c8_info[235].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c8_info[235].fileTimeLo = 1286851232U;
  c8_info[235].fileTimeHi = 0U;
  c8_info[235].mFileTimeLo = 0U;
  c8_info[235].mFileTimeHi = 0U;
  c8_info[236].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c8_info[236].name = "mtimes";
  c8_info[236].dominantType = "double";
  c8_info[236].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[236].fileTimeLo = 1289552092U;
  c8_info[236].fileTimeHi = 0U;
  c8_info[236].mFileTimeLo = 0U;
  c8_info[236].mFileTimeHi = 0U;
  c8_info[237].context = "";
  c8_info[237].name = "eye";
  c8_info[237].dominantType = "double";
  c8_info[237].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c8_info[237].fileTimeLo = 1286851088U;
  c8_info[237].fileTimeHi = 0U;
  c8_info[237].mFileTimeLo = 0U;
  c8_info[237].mFileTimeHi = 0U;
  c8_info[238].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c8_info[238].name = "eml_assert_valid_size_arg";
  c8_info[238].dominantType = "double";
  c8_info[238].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c8_info[238].fileTimeLo = 1286851094U;
  c8_info[238].fileTimeHi = 0U;
  c8_info[238].mFileTimeLo = 0U;
  c8_info[238].mFileTimeHi = 0U;
  c8_info[239].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c8_info[239].name = "isinf";
  c8_info[239].dominantType = "double";
  c8_info[239].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c8_info[239].fileTimeLo = 1286851160U;
  c8_info[239].fileTimeHi = 0U;
  c8_info[239].mFileTimeLo = 0U;
  c8_info[239].mFileTimeHi = 0U;
  c8_info[240].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c8_info[240].name = "mtimes";
  c8_info[240].dominantType = "double";
  c8_info[240].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[240].fileTimeLo = 1289552092U;
  c8_info[240].fileTimeHi = 0U;
  c8_info[240].mFileTimeLo = 0U;
  c8_info[240].mFileTimeHi = 0U;
  c8_info[241].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c8_info[241].name = "eml_index_class";
  c8_info[241].dominantType = "";
  c8_info[241].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[241].fileTimeLo = 1323202978U;
  c8_info[241].fileTimeHi = 0U;
  c8_info[241].mFileTimeLo = 0U;
  c8_info[241].mFileTimeHi = 0U;
  c8_info[242].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c8_info[242].name = "intmax";
  c8_info[242].dominantType = "char";
  c8_info[242].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c8_info[242].fileTimeLo = 1311287716U;
  c8_info[242].fileTimeHi = 0U;
  c8_info[242].mFileTimeLo = 0U;
  c8_info[242].mFileTimeHi = 0U;
  c8_info[243].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c8_info[243].name = "eml_is_float_class";
  c8_info[243].dominantType = "char";
  c8_info[243].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c8_info[243].fileTimeLo = 1286851182U;
  c8_info[243].fileTimeHi = 0U;
  c8_info[243].mFileTimeLo = 0U;
  c8_info[243].mFileTimeHi = 0U;
  c8_info[244].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c8_info[244].name = "min";
  c8_info[244].dominantType = "double";
  c8_info[244].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c8_info[244].fileTimeLo = 1311287718U;
  c8_info[244].fileTimeHi = 0U;
  c8_info[244].mFileTimeLo = 0U;
  c8_info[244].mFileTimeHi = 0U;
  c8_info[245].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c8_info[245].name = "eml_index_class";
  c8_info[245].dominantType = "";
  c8_info[245].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[245].fileTimeLo = 1323202978U;
  c8_info[245].fileTimeHi = 0U;
  c8_info[245].mFileTimeLo = 0U;
  c8_info[245].mFileTimeHi = 0U;
  c8_info[246].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c8_info[246].name = "eml_int_forloop_overflow_check";
  c8_info[246].dominantType = "";
  c8_info[246].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c8_info[246].fileTimeLo = 1346542740U;
  c8_info[246].fileTimeHi = 0U;
  c8_info[246].mFileTimeLo = 0U;
  c8_info[246].mFileTimeHi = 0U;
}

static void c8_eml_scalar_eg(SFc8_CusakisME4901InstanceStruct *chartInstance)
{
}

static void c8_b_eml_scalar_eg(SFc8_CusakisME4901InstanceStruct *chartInstance)
{
}

static real_T c8_det(SFc8_CusakisME4901InstanceStruct *chartInstance, real_T
                     c8_x[4])
{
  real_T c8_y;
  int32_T c8_info;
  int32_T c8_ipiv[2];
  real_T c8_b_a;
  real_T c8_b;
  boolean_T c8_isodd;
  c8_b_eml_matlab_zgetrf(chartInstance, c8_x, c8_ipiv, &c8_info);
  c8_y = c8_x[0];
  c8_b_a = c8_y;
  c8_b = c8_x[3];
  c8_y = c8_b_a * c8_b;
  c8_isodd = FALSE;
  if (c8_ipiv[0] > 1) {
    c8_isodd = TRUE;
  }

  if (c8_isodd) {
    c8_y = -c8_y;
  }

  return c8_y;
}

static void c8_realmin(SFc8_CusakisME4901InstanceStruct *chartInstance)
{
}

static void c8_eps(SFc8_CusakisME4901InstanceStruct *chartInstance)
{
}

static void c8_eml_matlab_zgetrf(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_A[4], real_T c8_b_A[4], int32_T c8_ipiv[2], int32_T *c8_info)
{
  int32_T c8_i106;
  for (c8_i106 = 0; c8_i106 < 4; c8_i106++) {
    c8_b_A[c8_i106] = c8_A[c8_i106];
  }

  c8_b_eml_matlab_zgetrf(chartInstance, c8_b_A, c8_ipiv, c8_info);
}

static real_T c8_abs(SFc8_CusakisME4901InstanceStruct *chartInstance, real_T
                     c8_x)
{
  real_T c8_b_x;
  c8_b_x = c8_x;
  return muDoubleScalarAbs(c8_b_x);
}

static void c8_below_threshold(SFc8_CusakisME4901InstanceStruct *chartInstance)
{
}

static real_T c8_eml_div(SFc8_CusakisME4901InstanceStruct *chartInstance, real_T
  c8_x, real_T c8_y)
{
  return c8_x / c8_y;
}

static void c8_eml_xger(SFc8_CusakisME4901InstanceStruct *chartInstance, real_T
  c8_A[4], real_T c8_b_A[4])
{
  int32_T c8_i107;
  for (c8_i107 = 0; c8_i107 < 4; c8_i107++) {
    c8_b_A[c8_i107] = c8_A[c8_i107];
  }

  c8_b_eml_xger(chartInstance, c8_b_A);
}

static void c8_check_forloop_overflow_error(SFc8_CusakisME4901InstanceStruct
  *chartInstance, boolean_T c8_overflow)
{
  int32_T c8_i108;
  static char_T c8_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c8_u[34];
  const mxArray *c8_y = NULL;
  int32_T c8_i109;
  static char_T c8_cv1[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't', 'e',
    'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  char_T c8_b_u[23];
  const mxArray *c8_b_y = NULL;
  if (!c8_overflow) {
  } else {
    for (c8_i108 = 0; c8_i108 < 34; c8_i108++) {
      c8_u[c8_i108] = c8_cv0[c8_i108];
    }

    c8_y = NULL;
    sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c8_i109 = 0; c8_i109 < 23; c8_i109++) {
      c8_b_u[c8_i109] = c8_cv1[c8_i109];
    }

    c8_b_y = NULL;
    sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_b_u, 10, 0U, 1U, 0U, 2, 1, 23),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c8_y, 14, c8_b_y));
  }
}

static real_T c8_sqrt(SFc8_CusakisME4901InstanceStruct *chartInstance, real_T
                      c8_x)
{
  real_T c8_b_x;
  c8_b_x = c8_x;
  c8_b_sqrt(chartInstance, &c8_b_x);
  return c8_b_x;
}

static void c8_eml_error(SFc8_CusakisME4901InstanceStruct *chartInstance)
{
  int32_T c8_i110;
  static char_T c8_cv2[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c8_u[30];
  const mxArray *c8_y = NULL;
  int32_T c8_i111;
  static char_T c8_cv3[4] = { 's', 'q', 'r', 't' };

  char_T c8_b_u[4];
  const mxArray *c8_b_y = NULL;
  for (c8_i110 = 0; c8_i110 < 30; c8_i110++) {
    c8_u[c8_i110] = c8_cv2[c8_i110];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  for (c8_i111 = 0; c8_i111 < 4; c8_i111++) {
    c8_b_u[c8_i111] = c8_cv3[c8_i111];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c8_y, 14, c8_b_y));
}

static real_T c8_mpower(SFc8_CusakisME4901InstanceStruct *chartInstance, real_T
  c8_b_a)
{
  real_T c8_c;
  real_T c8_c_a;
  real_T c8_d_a;
  real_T c8_ak;
  real_T c8_e_a;
  real_T c8_x;
  c8_c_a = c8_b_a;
  c8_d_a = c8_c_a;
  c8_c_eml_scalar_eg(chartInstance);
  c8_ak = c8_d_a;
  if (c8_ak < 0.0) {
    c8_b_eml_error(chartInstance);
  }

  c8_e_a = c8_ak;
  c8_c_eml_scalar_eg(chartInstance);
  c8_x = c8_e_a;
  c8_c = c8_x;
  if (c8_c < 0.0) {
    c8_eml_error(chartInstance);
  }

  return muDoubleScalarSqrt(c8_c);
}

static void c8_c_eml_scalar_eg(SFc8_CusakisME4901InstanceStruct *chartInstance)
{
}

static void c8_b_eml_error(SFc8_CusakisME4901InstanceStruct *chartInstance)
{
  int32_T c8_i112;
  static char_T c8_cv4[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c8_u[31];
  const mxArray *c8_y = NULL;
  for (c8_i112 = 0; c8_i112 < 31; c8_i112++) {
    c8_u[c8_i112] = c8_cv4[c8_i112];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 31), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c8_y));
}

static void c8_pinv(SFc8_CusakisME4901InstanceStruct *chartInstance, real_T
                    c8_A[6], real_T c8_X[6])
{
  int32_T c8_i113;
  int32_T c8_i114;
  int32_T c8_i115;
  int32_T c8_i116;
  real_T c8_U[6];
  int32_T c8_i117;
  real_T c8_b_X[6];
  int32_T c8_k;
  int32_T c8_b_k;
  real_T c8_x;
  real_T c8_b_x;
  boolean_T c8_b;
  boolean_T c8_b0;
  real_T c8_c_x;
  boolean_T c8_b_b;
  boolean_T c8_b1;
  boolean_T c8_c_b;
  int32_T c8_i118;
  real_T c8_b_U[6];
  real_T c8_V[4];
  real_T c8_s[2];
  int32_T c8_i119;
  real_T c8_S[4];
  int32_T c8_c_k;
  real_T c8_d_k;
  real_T c8_d_b;
  real_T c8_y;
  real_T c8_b_a;
  real_T c8_tol;
  int32_T c8_r;
  int32_T c8_e_k;
  int32_T c8_f_k;
  int32_T c8_c_a;
  int32_T c8_vcol;
  int32_T c8_b_r;
  int32_T c8_e_b;
  int32_T c8_f_b;
  boolean_T c8_overflow;
  int32_T c8_j;
  int32_T c8_b_j;
  real_T c8_b_y;
  real_T c8_z;
  int32_T c8_d_a;
  int32_T c8_i120;
  real_T c8_b_V[4];
  int32_T c8_i121;
  real_T c8_c_U[6];
  int32_T c8_i122;
  int32_T c8_i123;
  int32_T c8_i124;
  int32_T c8_i125;
  boolean_T exitg1;
  c8_i113 = 0;
  for (c8_i114 = 0; c8_i114 < 2; c8_i114++) {
    c8_i115 = 0;
    for (c8_i116 = 0; c8_i116 < 3; c8_i116++) {
      c8_U[c8_i116 + c8_i113] = c8_A[c8_i115 + c8_i114];
      c8_i115 += 2;
    }

    c8_i113 += 3;
  }

  for (c8_i117 = 0; c8_i117 < 6; c8_i117++) {
    c8_b_X[c8_i117] = 0.0;
  }

  for (c8_k = 1; c8_k < 7; c8_k++) {
    c8_b_k = c8_k;
    c8_x = c8_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c8_b_k), 1, 6, 1, 0) - 1];
    c8_b_x = c8_x;
    c8_b = muDoubleScalarIsInf(c8_b_x);
    c8_b0 = !c8_b;
    c8_c_x = c8_x;
    c8_b_b = muDoubleScalarIsNaN(c8_c_x);
    c8_b1 = !c8_b_b;
    c8_c_b = (c8_b0 && c8_b1);
    if (!c8_c_b) {
      c8_c_eml_error(chartInstance);
    }
  }

  for (c8_i118 = 0; c8_i118 < 6; c8_i118++) {
    c8_b_U[c8_i118] = c8_U[c8_i118];
  }

  c8_eml_xgesvd(chartInstance, c8_b_U, c8_U, c8_s, c8_V);
  for (c8_i119 = 0; c8_i119 < 4; c8_i119++) {
    c8_S[c8_i119] = 0.0;
  }

  for (c8_c_k = 0; c8_c_k < 2; c8_c_k++) {
    c8_d_k = 1.0 + (real_T)c8_c_k;
    c8_S[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", c8_d_k), 1, 2, 1, 0) + (((int32_T)(real_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              c8_d_k), 1, 2, 2, 0) - 1) << 1)) - 1] = c8_s[(int32_T)(real_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c8_d_k), 1,
      2, 1, 0) - 1];
  }

  c8_eps(chartInstance);
  c8_d_b = c8_S[0];
  c8_y = 3.0 * c8_d_b;
  c8_b_a = c8_y;
  c8_tol = c8_b_a * 2.2204460492503131E-16;
  c8_r = 0;
  c8_e_k = 1;
  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c8_e_k < 3)) {
    c8_f_k = c8_e_k;
    if (!(c8_S[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_f_k), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_f_k), 1, 2, 2, 0) - 1) <<
           1)) - 1] > c8_tol)) {
      exitg1 = TRUE;
    } else {
      c8_c_a = c8_r + 1;
      c8_r = c8_c_a;
      c8_e_k++;
    }
  }

  if (c8_r > 0) {
    c8_vcol = 1;
    c8_b_r = c8_r;
    c8_e_b = c8_b_r;
    c8_f_b = c8_e_b;
    if (1 > c8_f_b) {
      c8_overflow = FALSE;
    } else {
      c8_overflow = (c8_f_b > 2147483646);
    }

    if (c8_overflow) {
      c8_check_forloop_overflow_error(chartInstance, c8_overflow);
    }

    for (c8_j = 1; c8_j <= c8_b_r; c8_j++) {
      c8_b_j = c8_j;
      c8_b_y = c8_S[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c8_b_j), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c8_b_j), 1, 2, 2, 0) - 1) << 1)) - 1];
      c8_z = 1.0 / c8_b_y;
      c8_k_eml_xscal(chartInstance, c8_z, c8_V, c8_vcol);
      c8_d_a = c8_vcol + 2;
      c8_vcol = c8_d_a;
    }

    for (c8_i120 = 0; c8_i120 < 4; c8_i120++) {
      c8_b_V[c8_i120] = c8_V[c8_i120];
    }

    for (c8_i121 = 0; c8_i121 < 6; c8_i121++) {
      c8_c_U[c8_i121] = c8_U[c8_i121];
    }

    c8_c_eml_xgemm(chartInstance, c8_r, c8_b_V, c8_c_U, c8_b_X);
  }

  c8_i122 = 0;
  for (c8_i123 = 0; c8_i123 < 2; c8_i123++) {
    c8_i124 = 0;
    for (c8_i125 = 0; c8_i125 < 3; c8_i125++) {
      c8_X[c8_i125 + c8_i122] = c8_b_X[c8_i124 + c8_i123];
      c8_i124 += 2;
    }

    c8_i122 += 3;
  }
}

static void c8_d_eml_scalar_eg(SFc8_CusakisME4901InstanceStruct *chartInstance)
{
}

static void c8_c_eml_error(SFc8_CusakisME4901InstanceStruct *chartInstance)
{
  int32_T c8_i126;
  static char_T c8_cv5[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'v', 'd', '_', 'm', 'a', 't', 'r', 'i', 'x', 'W', 'i',
    't', 'h', 'N', 'a', 'N', 'I', 'n', 'f' };

  char_T c8_u[33];
  const mxArray *c8_y = NULL;
  for (c8_i126 = 0; c8_i126 < 33; c8_i126++) {
    c8_u[c8_i126] = c8_cv5[c8_i126];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 33), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c8_y));
}

static void c8_eml_xgesvd(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_A[6], real_T c8_U[6], real_T c8_S[2], real_T c8_V[4])
{
  int32_T c8_i127;
  real_T c8_b_A[6];
  int32_T c8_i128;
  real_T c8_s[2];
  int32_T c8_i129;
  real_T c8_e[2];
  int32_T c8_i130;
  real_T c8_work[3];
  int32_T c8_i131;
  int32_T c8_i132;
  real_T c8_Vf[4];
  int32_T c8_q;
  int32_T c8_b_q;
  int32_T c8_b_a;
  int32_T c8_qp1;
  int32_T c8_c_a;
  int32_T c8_qm1;
  int32_T c8_b;
  int32_T c8_c;
  int32_T c8_d_a;
  int32_T c8_b_b;
  int32_T c8_qq;
  int32_T c8_c_b;
  int32_T c8_nmq;
  int32_T c8_e_a;
  int32_T c8_nmqp1;
  int32_T c8_i133;
  real_T c8_c_A[6];
  real_T c8_nrm;
  real_T c8_absx;
  real_T c8_d;
  real_T c8_y;
  real_T c8_d3;
  int32_T c8_b_qp1;
  boolean_T c8_overflow;
  int32_T c8_jj;
  int32_T c8_b_jj;
  int32_T c8_f_a;
  int32_T c8_b_c;
  int32_T c8_d_b;
  int32_T c8_c_c;
  int32_T c8_g_a;
  int32_T c8_e_b;
  int32_T c8_qjj;
  int32_T c8_i134;
  real_T c8_d_A[6];
  int32_T c8_i135;
  real_T c8_e_A[6];
  real_T c8_t;
  int32_T c8_c_q;
  boolean_T c8_b_overflow;
  int32_T c8_ii;
  int32_T c8_b_ii;
  int32_T c8_f_b;
  int32_T c8_pmq;
  int32_T c8_i136;
  real_T c8_b_e[2];
  real_T c8_b_absx;
  real_T c8_b_d;
  real_T c8_b_y;
  real_T c8_d4;
  int32_T c8_c_qp1;
  boolean_T c8_c_overflow;
  int32_T c8_c_ii;
  int32_T c8_d_qp1;
  boolean_T c8_d_overflow;
  int32_T c8_c_jj;
  int32_T c8_h_a;
  int32_T c8_d_c;
  int32_T c8_g_b;
  int32_T c8_e_c;
  int32_T c8_i_a;
  int32_T c8_h_b;
  int32_T c8_qp1jj;
  int32_T c8_i137;
  real_T c8_f_A[6];
  int32_T c8_e_qp1;
  boolean_T c8_e_overflow;
  int32_T c8_d_jj;
  int32_T c8_j_a;
  int32_T c8_f_c;
  int32_T c8_i_b;
  int32_T c8_g_c;
  int32_T c8_k_a;
  int32_T c8_j_b;
  int32_T c8_i138;
  real_T c8_b_work[3];
  int32_T c8_f_qp1;
  boolean_T c8_f_overflow;
  int32_T c8_d_ii;
  int32_T c8_m;
  int32_T c8_d_q;
  int32_T c8_l_a;
  int32_T c8_k_b;
  int32_T c8_m_a;
  int32_T c8_n_a;
  int32_T c8_h_c;
  int32_T c8_l_b;
  int32_T c8_i_c;
  int32_T c8_o_a;
  int32_T c8_m_b;
  int32_T c8_g_qp1;
  boolean_T c8_g_overflow;
  int32_T c8_e_jj;
  int32_T c8_p_a;
  int32_T c8_j_c;
  int32_T c8_n_b;
  int32_T c8_k_c;
  int32_T c8_q_a;
  int32_T c8_o_b;
  int32_T c8_i139;
  real_T c8_b_U[6];
  int32_T c8_i140;
  real_T c8_c_U[6];
  int32_T c8_e_q;
  boolean_T c8_h_overflow;
  int32_T c8_e_ii;
  int32_T c8_r_a;
  int32_T c8_i141;
  int32_T c8_p_b;
  int32_T c8_q_b;
  boolean_T c8_i_overflow;
  int32_T c8_f_ii;
  int32_T c8_g_ii;
  int32_T c8_f_q;
  int32_T c8_s_a;
  int32_T c8_r_b;
  int32_T c8_t_a;
  int32_T c8_l_c;
  int32_T c8_s_b;
  int32_T c8_m_c;
  int32_T c8_u_a;
  int32_T c8_t_b;
  int32_T c8_qp1q;
  int32_T c8_h_qp1;
  boolean_T c8_j_overflow;
  int32_T c8_f_jj;
  int32_T c8_v_a;
  int32_T c8_n_c;
  int32_T c8_u_b;
  int32_T c8_o_c;
  int32_T c8_w_a;
  int32_T c8_v_b;
  int32_T c8_i142;
  real_T c8_b_Vf[4];
  int32_T c8_i143;
  real_T c8_c_Vf[4];
  int32_T c8_h_ii;
  int32_T c8_g_q;
  real_T c8_rt;
  real_T c8_r;
  int32_T c8_x_a;
  int32_T c8_p_c;
  int32_T c8_w_b;
  int32_T c8_q_c;
  int32_T c8_x_b;
  int32_T c8_colq;
  int32_T c8_y_a;
  int32_T c8_r_c;
  int32_T c8_ab_a;
  int32_T c8_s_c;
  real_T c8_bb_a;
  real_T c8_y_b;
  real_T c8_c_y;
  int32_T c8_ab_b;
  int32_T c8_t_c;
  int32_T c8_bb_b;
  int32_T c8_colqp1;
  real_T c8_iter;
  real_T c8_tiny;
  real_T c8_snorm;
  int32_T c8_i_ii;
  real_T c8_varargin_1;
  real_T c8_varargin_2;
  real_T c8_b_varargin_2;
  real_T c8_varargin_3;
  real_T c8_x;
  real_T c8_d_y;
  real_T c8_b_x;
  real_T c8_e_y;
  real_T c8_xk;
  real_T c8_yk;
  real_T c8_c_x;
  real_T c8_f_y;
  real_T c8_maxval;
  real_T c8_b_varargin_1;
  real_T c8_c_varargin_2;
  real_T c8_d_varargin_2;
  real_T c8_b_varargin_3;
  real_T c8_d_x;
  real_T c8_g_y;
  real_T c8_e_x;
  real_T c8_h_y;
  real_T c8_b_xk;
  real_T c8_b_yk;
  real_T c8_f_x;
  real_T c8_i_y;
  int32_T c8_cb_a;
  int32_T c8_db_a;
  int32_T c8_i144;
  boolean_T c8_k_overflow;
  int32_T c8_j_ii;
  int32_T c8_eb_a;
  int32_T c8_u_c;
  real_T c8_test0;
  real_T c8_ztest0;
  real_T c8_cb_b;
  real_T c8_j_y;
  real_T c8_db_b;
  real_T c8_k_y;
  int32_T c8_fb_a;
  int32_T c8_v_c;
  real_T c8_kase;
  int32_T c8_qs;
  int32_T c8_b_m;
  int32_T c8_h_q;
  int32_T c8_gb_a;
  int32_T c8_eb_b;
  int32_T c8_hb_a;
  int32_T c8_fb_b;
  boolean_T c8_l_overflow;
  int32_T c8_k_ii;
  real_T c8_test;
  int32_T c8_ib_a;
  int32_T c8_w_c;
  int32_T c8_jb_a;
  int32_T c8_x_c;
  real_T c8_ztest;
  real_T c8_gb_b;
  real_T c8_l_y;
  int32_T c8_kb_a;
  int32_T c8_lb_a;
  int32_T c8_y_c;
  real_T c8_f;
  int32_T c8_mb_a;
  int32_T c8_ab_c;
  int32_T c8_nb_a;
  int32_T c8_i145;
  int32_T c8_i_q;
  int32_T c8_ob_a;
  int32_T c8_hb_b;
  int32_T c8_pb_a;
  int32_T c8_ib_b;
  boolean_T c8_m_overflow;
  int32_T c8_k;
  int32_T c8_b_k;
  real_T c8_t1;
  real_T c8_b_t1;
  real_T c8_b_f;
  real_T c8_sn;
  real_T c8_cs;
  real_T c8_b_cs;
  real_T c8_b_sn;
  int32_T c8_qb_a;
  int32_T c8_km1;
  real_T c8_rb_a;
  real_T c8_jb_b;
  real_T c8_sb_a;
  real_T c8_kb_b;
  real_T c8_m_y;
  int32_T c8_tb_a;
  int32_T c8_bb_c;
  int32_T c8_lb_b;
  int32_T c8_cb_c;
  int32_T c8_mb_b;
  int32_T c8_colk;
  int32_T c8_ub_a;
  int32_T c8_db_c;
  int32_T c8_nb_b;
  int32_T c8_eb_c;
  int32_T c8_ob_b;
  int32_T c8_colm;
  int32_T c8_vb_a;
  int32_T c8_j_q;
  int32_T c8_c_m;
  int32_T c8_wb_a;
  int32_T c8_pb_b;
  int32_T c8_xb_a;
  int32_T c8_qb_b;
  boolean_T c8_n_overflow;
  int32_T c8_c_k;
  real_T c8_c_t1;
  real_T c8_unusedU0;
  real_T c8_c_sn;
  real_T c8_c_cs;
  real_T c8_yb_a;
  real_T c8_rb_b;
  real_T c8_ac_a;
  real_T c8_sb_b;
  real_T c8_n_y;
  int32_T c8_bc_a;
  int32_T c8_fb_c;
  int32_T c8_tb_b;
  int32_T c8_gb_c;
  int32_T c8_ub_b;
  int32_T c8_cc_a;
  int32_T c8_hb_c;
  int32_T c8_vb_b;
  int32_T c8_ib_c;
  int32_T c8_wb_b;
  int32_T c8_colqm1;
  int32_T c8_dc_a;
  int32_T c8_mm1;
  real_T c8_d5;
  real_T c8_d6;
  real_T c8_d7;
  real_T c8_d8;
  real_T c8_d9;
  real_T c8_c_varargin_1[5];
  int32_T c8_ixstart;
  real_T c8_mtmp;
  real_T c8_g_x;
  boolean_T c8_xb_b;
  int32_T c8_ix;
  int32_T c8_b_ix;
  real_T c8_h_x;
  boolean_T c8_yb_b;
  int32_T c8_ec_a;
  int32_T c8_i146;
  boolean_T c8_o_overflow;
  int32_T c8_c_ix;
  real_T c8_fc_a;
  real_T c8_ac_b;
  boolean_T c8_p;
  real_T c8_b_mtmp;
  real_T c8_scale;
  real_T c8_sm;
  real_T c8_smm1;
  real_T c8_emm1;
  real_T c8_sqds;
  real_T c8_eqds;
  real_T c8_gc_a;
  real_T c8_bc_b;
  real_T c8_o_y;
  real_T c8_hc_a;
  real_T c8_cc_b;
  real_T c8_p_y;
  real_T c8_dc_b;
  real_T c8_ic_a;
  real_T c8_ec_b;
  real_T c8_jb_c;
  real_T c8_jc_a;
  real_T c8_fc_b;
  real_T c8_shift;
  real_T c8_kc_a;
  real_T c8_gc_b;
  real_T c8_q_y;
  real_T c8_lc_a;
  real_T c8_hc_b;
  real_T c8_r_y;
  real_T c8_mc_a;
  real_T c8_ic_b;
  real_T c8_g;
  int32_T c8_k_q;
  int32_T c8_b_mm1;
  int32_T c8_nc_a;
  int32_T c8_jc_b;
  int32_T c8_oc_a;
  int32_T c8_kc_b;
  boolean_T c8_p_overflow;
  int32_T c8_d_k;
  int32_T c8_pc_a;
  int32_T c8_qc_a;
  int32_T c8_kp1;
  real_T c8_c_f;
  real_T c8_unusedU1;
  real_T c8_d_sn;
  real_T c8_d_cs;
  real_T c8_rc_a;
  real_T c8_lc_b;
  real_T c8_s_y;
  real_T c8_sc_a;
  real_T c8_mc_b;
  real_T c8_t_y;
  real_T c8_tc_a;
  real_T c8_nc_b;
  real_T c8_u_y;
  real_T c8_uc_a;
  real_T c8_oc_b;
  real_T c8_v_y;
  real_T c8_vc_a;
  real_T c8_pc_b;
  real_T c8_wc_a;
  real_T c8_qc_b;
  real_T c8_w_y;
  int32_T c8_xc_a;
  int32_T c8_kb_c;
  int32_T c8_rc_b;
  int32_T c8_lb_c;
  int32_T c8_sc_b;
  int32_T c8_tc_b;
  int32_T c8_mb_c;
  int32_T c8_uc_b;
  int32_T c8_colkp1;
  real_T c8_d_f;
  real_T c8_unusedU2;
  real_T c8_e_sn;
  real_T c8_e_cs;
  real_T c8_yc_a;
  real_T c8_vc_b;
  real_T c8_x_y;
  real_T c8_ad_a;
  real_T c8_wc_b;
  real_T c8_y_y;
  real_T c8_bd_a;
  real_T c8_xc_b;
  real_T c8_ab_y;
  real_T c8_cd_a;
  real_T c8_yc_b;
  real_T c8_bb_y;
  real_T c8_dd_a;
  real_T c8_ad_b;
  real_T c8_ed_a;
  real_T c8_bd_b;
  real_T c8_cb_y;
  int32_T c8_fd_a;
  int32_T c8_nb_c;
  int32_T c8_cd_b;
  int32_T c8_ob_c;
  int32_T c8_dd_b;
  int32_T c8_ed_b;
  int32_T c8_pb_c;
  int32_T c8_fd_b;
  int32_T c8_gd_a;
  int32_T c8_qb_c;
  int32_T c8_e_k;
  int32_T c8_j;
  int32_T c8_b_j;
  int32_T c8_i;
  int32_T c8_b_i;
  int32_T c8_rb_c;
  int32_T c8_hd_a;
  int32_T c8_sb_c;
  int32_T c8_gd_b;
  int32_T c8_hd_b;
  int32_T c8_id_a;
  int32_T c8_jd_a;
  int32_T c8_tb_c;
  int32_T c8_kd_a;
  int32_T c8_ub_c;
  int32_T c8_id_b;
  int32_T c8_jd_b;
  int32_T c8_vb_c;
  int32_T c8_kd_b;
  int32_T c8_ld_b;
  int32_T c8_wb_c;
  int32_T c8_ld_a;
  int32_T c8_xb_c;
  int32_T c8_md_b;
  int32_T c8_nd_b;
  int32_T c8_yb_c;
  int32_T c8_od_b;
  int32_T c8_pd_b;
  int32_T c8_md_a;
  real_T c8_d10;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T exitg4;
  boolean_T exitg5;
  boolean_T guard11 = FALSE;
  for (c8_i127 = 0; c8_i127 < 6; c8_i127++) {
    c8_b_A[c8_i127] = c8_A[c8_i127];
  }

  c8_d_eml_scalar_eg(chartInstance);
  for (c8_i128 = 0; c8_i128 < 2; c8_i128++) {
    c8_s[c8_i128] = 0.0;
  }

  for (c8_i129 = 0; c8_i129 < 2; c8_i129++) {
    c8_e[c8_i129] = 0.0;
  }

  for (c8_i130 = 0; c8_i130 < 3; c8_i130++) {
    c8_work[c8_i130] = 0.0;
  }

  for (c8_i131 = 0; c8_i131 < 6; c8_i131++) {
    c8_U[c8_i131] = 0.0;
  }

  for (c8_i132 = 0; c8_i132 < 4; c8_i132++) {
    c8_Vf[c8_i132] = 0.0;
  }

  for (c8_q = 1; c8_q < 3; c8_q++) {
    c8_b_q = c8_q;
    c8_b_a = c8_b_q + 1;
    c8_qp1 = c8_b_a;
    c8_c_a = c8_b_q;
    c8_qm1 = c8_c_a;
    c8_b = c8_qm1 - 1;
    c8_c = 3 * c8_b;
    c8_d_a = c8_b_q;
    c8_b_b = c8_c;
    c8_qq = c8_d_a + c8_b_b;
    c8_c_b = c8_b_q;
    c8_nmq = 3 - c8_c_b;
    c8_e_a = c8_nmq + 1;
    c8_nmqp1 = c8_e_a;
    if (c8_b_q <= 2) {
      for (c8_i133 = 0; c8_i133 < 6; c8_i133++) {
        c8_c_A[c8_i133] = c8_b_A[c8_i133];
      }

      c8_nrm = c8_eml_xnrm2(chartInstance, c8_nmqp1, c8_c_A, c8_qq);
      if (c8_nrm > 0.0) {
        c8_absx = c8_nrm;
        c8_d = c8_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c8_qq), 1, 6, 1, 0) - 1];
        if (c8_d < 0.0) {
          c8_y = -c8_absx;
        } else {
          c8_y = c8_absx;
        }

        c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_q), 1, 2, 1, 0) - 1] = c8_y;
        c8_d3 = c8_eml_div(chartInstance, 1.0, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 2, 1, 0) - 1]);
        c8_h_eml_xscal(chartInstance, c8_nmqp1, c8_d3, c8_b_A, c8_qq);
        c8_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_qq), 1, 6, 1, 0) - 1] = c8_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_qq), 1, 6, 1, 0) - 1] +
          1.0;
        c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_q), 1, 2, 1, 0) - 1] = -c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 2, 1, 0) - 1];
      } else {
        c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_q), 1, 2, 1, 0) - 1] = 0.0;
      }
    }

    c8_b_qp1 = c8_qp1;
    c8_overflow = FALSE;
    if (c8_overflow) {
      c8_check_forloop_overflow_error(chartInstance, c8_overflow);
    }

    for (c8_jj = c8_b_qp1; c8_jj < 3; c8_jj++) {
      c8_b_jj = c8_jj;
      c8_f_a = c8_b_jj;
      c8_b_c = c8_f_a;
      c8_d_b = c8_b_c - 1;
      c8_c_c = 3 * c8_d_b;
      c8_g_a = c8_b_q;
      c8_e_b = c8_c_c;
      c8_qjj = c8_g_a + c8_e_b;
      if (c8_b_q <= 2) {
        if (c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c8_b_q), 1, 2, 1, 0) - 1] != 0.0) {
          for (c8_i134 = 0; c8_i134 < 6; c8_i134++) {
            c8_d_A[c8_i134] = c8_b_A[c8_i134];
          }

          for (c8_i135 = 0; c8_i135 < 6; c8_i135++) {
            c8_e_A[c8_i135] = c8_b_A[c8_i135];
          }

          c8_t = c8_eml_xdotc(chartInstance, c8_nmqp1, c8_d_A, c8_qq, c8_e_A,
                              c8_qjj);
          c8_t = -c8_eml_div(chartInstance, c8_t, c8_b_A
                             [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 3, 1, 0) + 3 *
                               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 2, 2, 0) - 1)) - 1]);
          c8_i_eml_xaxpy(chartInstance, c8_nmqp1, c8_t, c8_qq, c8_b_A, c8_qjj);
        }
      }

      c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c8_b_jj), 1, 2, 1, 0) - 1] = c8_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_qjj), 1, 6, 1, 0) - 1];
    }

    if (c8_b_q <= 2) {
      c8_c_q = c8_b_q;
      c8_b_overflow = FALSE;
      if (c8_b_overflow) {
        c8_check_forloop_overflow_error(chartInstance, c8_b_overflow);
      }

      for (c8_ii = c8_c_q; c8_ii < 4; c8_ii++) {
        c8_b_ii = c8_ii;
        c8_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c8_b_ii), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK
               ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 2, 2, 0)
               - 1)) - 1] = c8_b_A[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c8_b_ii), 1, 3, 1, 0) + 3 *
          (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_q), 1, 2, 2, 0) - 1)) - 1];
      }
    }

    if (c8_b_q <= 0) {
      c8_f_b = c8_b_q;
      c8_pmq = 2 - c8_f_b;
      for (c8_i136 = 0; c8_i136 < 2; c8_i136++) {
        c8_b_e[c8_i136] = c8_e[c8_i136];
      }

      c8_nrm = c8_b_eml_xnrm2(chartInstance, c8_pmq, c8_b_e, c8_qp1);
      if (c8_nrm == 0.0) {
        c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_q), 1, 2, 1, 0) - 1] = 0.0;
      } else {
        c8_b_absx = c8_nrm;
        c8_b_d = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c8_qp1), 1, 2, 1, 0) - 1];
        if (c8_b_d < 0.0) {
          c8_b_y = -c8_b_absx;
        } else {
          c8_b_y = c8_b_absx;
        }

        c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_q), 1, 2, 1, 0) - 1] = c8_b_y;
        c8_d4 = c8_eml_div(chartInstance, 1.0, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 2, 1, 0) - 1]);
        c8_i_eml_xscal(chartInstance, c8_pmq, c8_d4, c8_e, c8_qp1);
        c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_qp1), 1, 2, 1, 0) - 1] = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_qp1), 1, 2, 1, 0) - 1]
          + 1.0;
      }

      c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c8_b_q), 1, 2, 1, 0) - 1] = -c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 2, 1, 0) - 1];
      if (c8_qp1 <= 3) {
        if (c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c8_b_q), 1, 2, 1, 0) - 1] != 0.0) {
          c8_c_qp1 = c8_qp1;
          c8_c_overflow = FALSE;
          if (c8_c_overflow) {
            c8_check_forloop_overflow_error(chartInstance, c8_c_overflow);
          }

          for (c8_c_ii = c8_c_qp1; c8_c_ii < 4; c8_c_ii++) {
            c8_b_ii = c8_c_ii;
            c8_work[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c8_b_ii), 1, 3, 1, 0) - 1] = 0.0;
          }

          c8_d_qp1 = c8_qp1;
          c8_d_overflow = FALSE;
          if (c8_d_overflow) {
            c8_check_forloop_overflow_error(chartInstance, c8_d_overflow);
          }

          for (c8_c_jj = c8_d_qp1; c8_c_jj < 3; c8_c_jj++) {
            c8_b_jj = c8_c_jj;
            c8_h_a = c8_b_jj;
            c8_d_c = c8_h_a;
            c8_g_b = c8_d_c - 1;
            c8_e_c = 3 * c8_g_b;
            c8_i_a = c8_qp1;
            c8_h_b = c8_e_c;
            c8_qp1jj = c8_i_a + c8_h_b;
            for (c8_i137 = 0; c8_i137 < 6; c8_i137++) {
              c8_f_A[c8_i137] = c8_b_A[c8_i137];
            }

            c8_j_eml_xaxpy(chartInstance, c8_nmq,
                           c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c8_b_jj), 1, 2, 1, 0) - 1], c8_f_A,
                           c8_qp1jj, c8_work, c8_qp1);
          }

          c8_e_qp1 = c8_qp1;
          c8_e_overflow = FALSE;
          if (c8_e_overflow) {
            c8_check_forloop_overflow_error(chartInstance, c8_e_overflow);
          }

          for (c8_d_jj = c8_e_qp1; c8_d_jj < 3; c8_d_jj++) {
            c8_b_jj = c8_d_jj;
            c8_t = c8_eml_div(chartInstance, -c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
              "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_jj), 1, 2, 1, 0)
                              - 1], c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_qp1), 1, 2, 1, 0) - 1]);
            c8_j_a = c8_b_jj;
            c8_f_c = c8_j_a;
            c8_i_b = c8_f_c - 1;
            c8_g_c = 3 * c8_i_b;
            c8_k_a = c8_qp1;
            c8_j_b = c8_g_c;
            c8_qp1jj = c8_k_a + c8_j_b;
            for (c8_i138 = 0; c8_i138 < 3; c8_i138++) {
              c8_b_work[c8_i138] = c8_work[c8_i138];
            }

            c8_k_eml_xaxpy(chartInstance, c8_nmq, c8_t, c8_b_work, c8_qp1,
                           c8_b_A, c8_qp1jj);
          }
        }
      }

      c8_f_qp1 = c8_qp1;
      c8_f_overflow = FALSE;
      if (c8_f_overflow) {
        c8_check_forloop_overflow_error(chartInstance, c8_f_overflow);
      }

      for (c8_d_ii = c8_f_qp1; c8_d_ii < 3; c8_d_ii++) {
        c8_b_ii = c8_d_ii;
        c8_Vf[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c8_b_ii), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK(
                  "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 2, 2,
                  0) - 1) << 1)) - 1] = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_ii), 1, 2, 1, 0) - 1];
      }
    }
  }

  c8_m = 2;
  c8_e[0] = c8_b_A[3];
  c8_e[1] = 0.0;
  for (c8_d_q = 2; c8_d_q > 0; c8_d_q--) {
    c8_b_q = c8_d_q;
    c8_l_a = c8_b_q;
    c8_qp1 = c8_l_a;
    c8_k_b = c8_b_q;
    c8_nmq = 3 - c8_k_b;
    c8_m_a = c8_nmq + 1;
    c8_nmqp1 = c8_m_a;
    c8_n_a = c8_b_q;
    c8_h_c = c8_n_a;
    c8_l_b = c8_h_c - 1;
    c8_i_c = 3 * c8_l_b;
    c8_o_a = c8_b_q;
    c8_m_b = c8_i_c;
    c8_qq = c8_o_a + c8_m_b;
    if (c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_q), 1, 2, 1, 0) - 1] != 0.0) {
      c8_g_qp1 = c8_qp1 + 1;
      c8_g_overflow = FALSE;
      if (c8_g_overflow) {
        c8_check_forloop_overflow_error(chartInstance, c8_g_overflow);
      }

      for (c8_e_jj = c8_g_qp1; c8_e_jj < 3; c8_e_jj++) {
        c8_b_jj = c8_e_jj;
        c8_p_a = c8_b_jj;
        c8_j_c = c8_p_a;
        c8_n_b = c8_j_c - 1;
        c8_k_c = 3 * c8_n_b;
        c8_q_a = c8_b_q;
        c8_o_b = c8_k_c;
        c8_qjj = c8_q_a + c8_o_b;
        for (c8_i139 = 0; c8_i139 < 6; c8_i139++) {
          c8_b_U[c8_i139] = c8_U[c8_i139];
        }

        for (c8_i140 = 0; c8_i140 < 6; c8_i140++) {
          c8_c_U[c8_i140] = c8_U[c8_i140];
        }

        c8_t = c8_eml_xdotc(chartInstance, c8_nmqp1, c8_b_U, c8_qq, c8_c_U,
                            c8_qjj);
        c8_t = -c8_eml_div(chartInstance, c8_t, c8_U[_SFD_EML_ARRAY_BOUNDS_CHECK
                           ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_qq),
                            1, 6, 1, 0) - 1]);
        c8_i_eml_xaxpy(chartInstance, c8_nmqp1, c8_t, c8_qq, c8_U, c8_qjj);
      }

      c8_e_q = c8_b_q;
      c8_h_overflow = FALSE;
      if (c8_h_overflow) {
        c8_check_forloop_overflow_error(chartInstance, c8_h_overflow);
      }

      for (c8_e_ii = c8_e_q; c8_e_ii < 4; c8_e_ii++) {
        c8_b_ii = c8_e_ii;
        c8_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c8_b_ii), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK
               ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 2, 2, 0)
               - 1)) - 1] = -c8_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c8_b_ii), 1, 3, 1, 0) + 3 *
          (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_q), 1, 2, 2, 0) - 1)) - 1];
      }

      c8_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c8_qq), 1, 6, 1, 0) - 1] = c8_U[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_qq), 1, 6, 1, 0) - 1] + 1.0;
      c8_r_a = c8_b_q - 1;
      c8_i141 = c8_r_a;
      c8_p_b = c8_i141;
      c8_q_b = c8_p_b;
      if (1 > c8_q_b) {
        c8_i_overflow = FALSE;
      } else {
        c8_i_overflow = (c8_q_b > 2147483646);
      }

      if (c8_i_overflow) {
        c8_check_forloop_overflow_error(chartInstance, c8_i_overflow);
      }

      for (c8_f_ii = 1; c8_f_ii <= c8_i141; c8_f_ii++) {
        c8_b_ii = c8_f_ii;
        c8_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c8_b_ii), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK
               ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 2, 2, 0)
               - 1)) - 1] = 0.0;
      }
    } else {
      for (c8_g_ii = 1; c8_g_ii < 4; c8_g_ii++) {
        c8_b_ii = c8_g_ii;
        c8_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c8_b_ii), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK
               ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 2, 2, 0)
               - 1)) - 1] = 0.0;
      }

      c8_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c8_qq), 1, 6, 1, 0) - 1] = 1.0;
    }
  }

  for (c8_f_q = 2; c8_f_q > 0; c8_f_q--) {
    c8_b_q = c8_f_q;
    if (c8_b_q <= 0) {
      if (c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_q), 1, 2, 1, 0) - 1] != 0.0) {
        c8_s_a = c8_b_q + 1;
        c8_qp1 = c8_s_a;
        c8_r_b = c8_b_q;
        c8_pmq = 2 - c8_r_b;
        c8_t_a = c8_b_q;
        c8_l_c = c8_t_a;
        c8_s_b = c8_l_c - 1;
        c8_m_c = c8_s_b << 1;
        c8_u_a = c8_qp1;
        c8_t_b = c8_m_c;
        c8_qp1q = c8_u_a + c8_t_b;
        c8_h_qp1 = c8_qp1;
        c8_j_overflow = FALSE;
        if (c8_j_overflow) {
          c8_check_forloop_overflow_error(chartInstance, c8_j_overflow);
        }

        for (c8_f_jj = c8_h_qp1; c8_f_jj < 3; c8_f_jj++) {
          c8_b_jj = c8_f_jj;
          c8_v_a = c8_b_jj;
          c8_n_c = c8_v_a;
          c8_u_b = c8_n_c - 1;
          c8_o_c = c8_u_b << 1;
          c8_w_a = c8_qp1;
          c8_v_b = c8_o_c;
          c8_qp1jj = c8_w_a + c8_v_b;
          for (c8_i142 = 0; c8_i142 < 4; c8_i142++) {
            c8_b_Vf[c8_i142] = c8_Vf[c8_i142];
          }

          for (c8_i143 = 0; c8_i143 < 4; c8_i143++) {
            c8_c_Vf[c8_i143] = c8_Vf[c8_i143];
          }

          c8_t = c8_b_eml_xdotc(chartInstance, c8_pmq, c8_b_Vf, c8_qp1q, c8_c_Vf,
                                c8_qp1jj);
          c8_t = -c8_eml_div(chartInstance, c8_t,
                             c8_Vf[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_qp1q), 1, 4, 1, 0) - 1]);
          c8_l_eml_xaxpy(chartInstance, c8_pmq, c8_t, c8_qp1q, c8_Vf, c8_qp1jj);
        }
      }
    }

    for (c8_h_ii = 1; c8_h_ii < 3; c8_h_ii++) {
      c8_b_ii = c8_h_ii;
      c8_Vf[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
               (real_T)c8_b_ii), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 2, 2, 0) - 1)
              << 1)) - 1] = 0.0;
    }

    c8_Vf[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c8_b_q), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 2, 2, 0) - 1) <<
            1)) - 1] = 1.0;
  }

  for (c8_g_q = 1; c8_g_q < 3; c8_g_q++) {
    c8_b_q = c8_g_q;
    if (c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_q), 1, 2, 1, 0) - 1] != 0.0) {
      c8_rt = c8_abs(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 2, 1, 0) - 1]);
      c8_r = c8_eml_div(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 2, 1, 0) - 1], c8_rt);
      c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c8_b_q), 1, 2, 1, 0) - 1] = c8_rt;
      if (c8_b_q < 2) {
        c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_q), 1, 2, 1, 0) - 1] = c8_eml_div(chartInstance,
          c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_q), 1, 2, 1, 0) - 1], c8_r);
      }

      if (c8_b_q <= 3) {
        c8_x_a = c8_b_q;
        c8_p_c = c8_x_a;
        c8_w_b = c8_p_c - 1;
        c8_q_c = 3 * c8_w_b;
        c8_x_b = c8_q_c;
        c8_colq = c8_x_b;
        c8_j_eml_xscal(chartInstance, c8_r, c8_U, c8_colq + 1);
      }
    }

    if (c8_b_q < 2) {
      if (c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_q), 1, 2, 1, 0) - 1] != 0.0) {
        c8_rt = c8_abs(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 2, 1, 0) - 1]);
        c8_r = c8_eml_div(chartInstance, c8_rt, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK
                          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q),
                           1, 2, 1, 0) - 1]);
        c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_q), 1, 2, 1, 0) - 1] = c8_rt;
        c8_y_a = c8_b_q;
        c8_r_c = c8_y_a;
        c8_ab_a = c8_b_q;
        c8_s_c = c8_ab_a;
        c8_bb_a = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c8_s_c + 1)), 1, 2, 1, 0) - 1];
        c8_y_b = c8_r;
        c8_c_y = c8_bb_a * c8_y_b;
        c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c8_r_c + 1)), 1, 2, 1, 0) - 1] = c8_c_y;
        c8_ab_b = c8_b_q;
        c8_t_c = c8_ab_b << 1;
        c8_bb_b = c8_t_c;
        c8_colqp1 = c8_bb_b;
        c8_k_eml_xscal(chartInstance, c8_r, c8_Vf, c8_colqp1 + 1);
      }
    }
  }

  c8_iter = 0.0;
  c8_realmin(chartInstance);
  c8_eps(chartInstance);
  c8_tiny = c8_eml_div(chartInstance, 2.2250738585072014E-308,
                       2.2204460492503131E-16);
  c8_snorm = 0.0;
  for (c8_i_ii = 1; c8_i_ii < 3; c8_i_ii++) {
    c8_b_ii = c8_i_ii;
    c8_varargin_1 = c8_abs(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_ii), 1, 2, 1, 0) - 1]);
    c8_varargin_2 = c8_abs(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_ii), 1, 2, 1, 0) - 1]);
    c8_b_varargin_2 = c8_varargin_1;
    c8_varargin_3 = c8_varargin_2;
    c8_x = c8_b_varargin_2;
    c8_d_y = c8_varargin_3;
    c8_b_x = c8_x;
    c8_e_y = c8_d_y;
    c8_c_eml_scalar_eg(chartInstance);
    c8_xk = c8_b_x;
    c8_yk = c8_e_y;
    c8_c_x = c8_xk;
    c8_f_y = c8_yk;
    c8_c_eml_scalar_eg(chartInstance);
    c8_maxval = muDoubleScalarMax(c8_c_x, c8_f_y);
    c8_b_varargin_1 = c8_snorm;
    c8_c_varargin_2 = c8_maxval;
    c8_d_varargin_2 = c8_b_varargin_1;
    c8_b_varargin_3 = c8_c_varargin_2;
    c8_d_x = c8_d_varargin_2;
    c8_g_y = c8_b_varargin_3;
    c8_e_x = c8_d_x;
    c8_h_y = c8_g_y;
    c8_c_eml_scalar_eg(chartInstance);
    c8_b_xk = c8_e_x;
    c8_b_yk = c8_h_y;
    c8_f_x = c8_b_xk;
    c8_i_y = c8_b_yk;
    c8_c_eml_scalar_eg(chartInstance);
    c8_snorm = muDoubleScalarMax(c8_f_x, c8_i_y);
  }

  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c8_m > 0)) {
    if (c8_iter >= 75.0) {
      c8_d_eml_error(chartInstance);
      exitg1 = TRUE;
    } else {
      c8_cb_a = c8_m - 1;
      c8_b_q = c8_cb_a;
      c8_db_a = c8_m;
      c8_i144 = c8_db_a;
      c8_k_overflow = FALSE;
      if (c8_k_overflow) {
        c8_check_forloop_overflow_error(chartInstance, c8_k_overflow);
      }

      c8_j_ii = c8_i144 - 1;
      guard3 = FALSE;
      guard4 = FALSE;
      exitg5 = FALSE;
      while ((exitg5 == FALSE) && (c8_j_ii > -1)) {
        c8_b_ii = c8_j_ii;
        c8_b_q = c8_b_ii;
        if (c8_b_ii == 0) {
          exitg5 = TRUE;
        } else {
          c8_eb_a = c8_b_ii;
          c8_u_c = c8_eb_a;
          c8_test0 = c8_abs(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_ii), 1,
            2, 1, 0) - 1]) + c8_abs(chartInstance,
            c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                                      (real_T)(c8_u_c + 1)), 1, 2, 1, 0) - 1]);
          c8_ztest0 = c8_abs(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_ii),
            1, 2, 1, 0) - 1]);
          c8_eps(chartInstance);
          c8_cb_b = c8_test0;
          c8_j_y = 2.2204460492503131E-16 * c8_cb_b;
          if (c8_ztest0 <= c8_j_y) {
            guard4 = TRUE;
            exitg5 = TRUE;
          } else if (c8_ztest0 <= c8_tiny) {
            guard4 = TRUE;
            exitg5 = TRUE;
          } else {
            guard11 = FALSE;
            if (c8_iter > 20.0) {
              c8_eps(chartInstance);
              c8_db_b = c8_snorm;
              c8_k_y = 2.2204460492503131E-16 * c8_db_b;
              if (c8_ztest0 <= c8_k_y) {
                guard3 = TRUE;
                exitg5 = TRUE;
              } else {
                guard11 = TRUE;
              }
            } else {
              guard11 = TRUE;
            }

            if (guard11 == TRUE) {
              c8_j_ii--;
              guard3 = FALSE;
              guard4 = FALSE;
            }
          }
        }
      }

      if (guard4 == TRUE) {
        guard3 = TRUE;
      }

      if (guard3 == TRUE) {
        c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_ii), 1, 2, 1, 0) - 1] = 0.0;
      }

      c8_fb_a = c8_m;
      c8_v_c = c8_fb_a;
      if (c8_b_q == c8_v_c - 1) {
        c8_kase = 4.0;
      } else {
        c8_qs = c8_m;
        c8_b_m = c8_m;
        c8_h_q = c8_b_q;
        c8_gb_a = c8_b_m;
        c8_eb_b = c8_h_q;
        c8_hb_a = c8_gb_a;
        c8_fb_b = c8_eb_b;
        if (c8_hb_a < c8_fb_b) {
          c8_l_overflow = FALSE;
        } else {
          c8_l_overflow = (c8_fb_b < -2147483647);
        }

        if (c8_l_overflow) {
          c8_check_forloop_overflow_error(chartInstance, c8_l_overflow);
        }

        c8_k_ii = c8_b_m;
        guard2 = FALSE;
        exitg4 = FALSE;
        while ((exitg4 == FALSE) && (c8_k_ii >= c8_h_q)) {
          c8_b_ii = c8_k_ii;
          c8_qs = c8_b_ii;
          if (c8_b_ii == c8_b_q) {
            exitg4 = TRUE;
          } else {
            c8_test = 0.0;
            if (c8_b_ii < c8_m) {
              c8_test = c8_abs(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
                "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_ii), 1, 2, 1, 0)
                               - 1]);
            }

            c8_ib_a = c8_b_q;
            c8_w_c = c8_ib_a;
            if (c8_b_ii > c8_w_c + 1) {
              c8_jb_a = c8_b_ii;
              c8_x_c = c8_jb_a;
              c8_test += c8_abs(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
                "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c8_x_c - 1)), 1, 2,
                1, 0) - 1]);
            }

            c8_ztest = c8_abs(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                               (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_ii),
              1, 2, 1, 0) - 1]);
            c8_eps(chartInstance);
            c8_gb_b = c8_test;
            c8_l_y = 2.2204460492503131E-16 * c8_gb_b;
            if (c8_ztest <= c8_l_y) {
              guard2 = TRUE;
              exitg4 = TRUE;
            } else if (c8_ztest <= c8_tiny) {
              guard2 = TRUE;
              exitg4 = TRUE;
            } else {
              c8_k_ii--;
              guard2 = FALSE;
            }
          }
        }

        if (guard2 == TRUE) {
          c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_ii), 1, 2, 1, 0) - 1] = 0.0;
        }

        if (c8_qs == c8_b_q) {
          c8_kase = 3.0;
        } else if (c8_qs == c8_m) {
          c8_kase = 1.0;
        } else {
          c8_kase = 2.0;
          c8_b_q = c8_qs;
        }
      }

      c8_kb_a = c8_b_q + 1;
      c8_b_q = c8_kb_a;
      switch ((int32_T)_SFD_INTEGER_CHECK("", c8_kase)) {
       case 1:
        c8_lb_a = c8_m;
        c8_y_c = c8_lb_a;
        c8_f = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)(c8_y_c - 1)), 1, 2, 1, 0) - 1];
        c8_mb_a = c8_m;
        c8_ab_c = c8_mb_a;
        c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c8_ab_c - 1)), 1, 2, 1, 0) - 1] = 0.0;
        c8_nb_a = c8_m - 1;
        c8_i145 = c8_nb_a;
        c8_i_q = c8_b_q;
        c8_ob_a = c8_i145;
        c8_hb_b = c8_i_q;
        c8_pb_a = c8_ob_a;
        c8_ib_b = c8_hb_b;
        if (c8_pb_a < c8_ib_b) {
          c8_m_overflow = FALSE;
        } else {
          c8_m_overflow = (c8_ib_b < -2147483647);
        }

        if (c8_m_overflow) {
          c8_check_forloop_overflow_error(chartInstance, c8_m_overflow);
        }

        for (c8_k = c8_i145; c8_k >= c8_i_q; c8_k--) {
          c8_b_k = c8_k;
          c8_t1 = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 2, 1, 0) - 1];
          c8_b_t1 = c8_t1;
          c8_b_f = c8_f;
          c8_b_eml_xrotg(chartInstance, &c8_b_t1, &c8_b_f, &c8_cs, &c8_sn);
          c8_t1 = c8_b_t1;
          c8_f = c8_b_f;
          c8_b_cs = c8_cs;
          c8_b_sn = c8_sn;
          c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_k), 1, 2, 1, 0) - 1] = c8_t1;
          if (c8_b_k > c8_b_q) {
            c8_qb_a = c8_b_k - 1;
            c8_km1 = c8_qb_a;
            c8_rb_a = -c8_b_sn;
            c8_jb_b = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c8_km1), 1, 2, 1, 0) - 1];
            c8_f = c8_rb_a * c8_jb_b;
            c8_sb_a = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c8_km1), 1, 2, 1, 0) - 1];
            c8_kb_b = c8_b_cs;
            c8_m_y = c8_sb_a * c8_kb_b;
            c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c8_km1), 1, 2, 1, 0) - 1] = c8_m_y;
          }

          c8_tb_a = c8_b_k;
          c8_bb_c = c8_tb_a;
          c8_lb_b = c8_bb_c - 1;
          c8_cb_c = c8_lb_b << 1;
          c8_mb_b = c8_cb_c;
          c8_colk = c8_mb_b;
          c8_ub_a = c8_m;
          c8_db_c = c8_ub_a;
          c8_nb_b = c8_db_c - 1;
          c8_eb_c = c8_nb_b << 1;
          c8_ob_b = c8_eb_c;
          c8_colm = c8_ob_b;
          c8_c_eml_xrot(chartInstance, c8_Vf, c8_colk + 1, c8_colm + 1, c8_b_cs,
                        c8_b_sn);
        }
        break;

       case 2:
        c8_vb_a = c8_b_q - 1;
        c8_qm1 = c8_vb_a;
        c8_f = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c8_qm1), 1, 2, 1, 0) - 1];
        c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_qm1), 1, 2, 1, 0) - 1] = 0.0;
        c8_j_q = c8_b_q;
        c8_c_m = c8_m;
        c8_wb_a = c8_j_q;
        c8_pb_b = c8_c_m;
        c8_xb_a = c8_wb_a;
        c8_qb_b = c8_pb_b;
        if (c8_xb_a > c8_qb_b) {
          c8_n_overflow = FALSE;
        } else {
          c8_n_overflow = (c8_qb_b > 2147483646);
        }

        if (c8_n_overflow) {
          c8_check_forloop_overflow_error(chartInstance, c8_n_overflow);
        }

        for (c8_c_k = c8_j_q; c8_c_k <= c8_c_m; c8_c_k++) {
          c8_b_k = c8_c_k;
          c8_t1 = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 2, 1, 0) - 1];
          c8_c_t1 = c8_t1;
          c8_unusedU0 = c8_f;
          c8_b_eml_xrotg(chartInstance, &c8_c_t1, &c8_unusedU0, &c8_c_cs,
                         &c8_c_sn);
          c8_t1 = c8_c_t1;
          c8_b_cs = c8_c_cs;
          c8_b_sn = c8_c_sn;
          c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_k), 1, 2, 1, 0) - 1] = c8_t1;
          c8_yb_a = -c8_b_sn;
          c8_rb_b = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 2, 1, 0) - 1];
          c8_f = c8_yb_a * c8_rb_b;
          c8_ac_a = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 2, 1, 0) - 1];
          c8_sb_b = c8_b_cs;
          c8_n_y = c8_ac_a * c8_sb_b;
          c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_k), 1, 2, 1, 0) - 1] = c8_n_y;
          c8_bc_a = c8_b_k;
          c8_fb_c = c8_bc_a;
          c8_tb_b = c8_fb_c - 1;
          c8_gb_c = 3 * c8_tb_b;
          c8_ub_b = c8_gb_c;
          c8_colk = c8_ub_b;
          c8_cc_a = c8_qm1;
          c8_hb_c = c8_cc_a;
          c8_vb_b = c8_hb_c - 1;
          c8_ib_c = 3 * c8_vb_b;
          c8_wb_b = c8_ib_c;
          c8_colqm1 = c8_wb_b;
          c8_d_eml_xrot(chartInstance, c8_U, c8_colk + 1, c8_colqm1 + 1, c8_b_cs,
                        c8_b_sn);
        }
        break;

       case 3:
        c8_dc_a = c8_m - 1;
        c8_mm1 = c8_dc_a;
        c8_d5 = c8_abs(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_m), 1, 2, 1, 0) - 1]);
        c8_d6 = c8_abs(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_mm1), 1, 2, 1, 0) - 1]);
        c8_d7 = c8_abs(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_mm1), 1, 2, 1, 0) - 1]);
        c8_d8 = c8_abs(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 2, 1, 0) - 1]);
        c8_d9 = c8_abs(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 2, 1, 0) - 1]);
        c8_c_varargin_1[0] = c8_d5;
        c8_c_varargin_1[1] = c8_d6;
        c8_c_varargin_1[2] = c8_d7;
        c8_c_varargin_1[3] = c8_d8;
        c8_c_varargin_1[4] = c8_d9;
        c8_ixstart = 1;
        c8_mtmp = c8_c_varargin_1[0];
        c8_g_x = c8_mtmp;
        c8_xb_b = muDoubleScalarIsNaN(c8_g_x);
        if (c8_xb_b) {
          c8_ix = 2;
          exitg2 = FALSE;
          while ((exitg2 == FALSE) && (c8_ix < 6)) {
            c8_b_ix = c8_ix;
            c8_ixstart = c8_b_ix;
            c8_h_x = c8_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c8_b_ix), 1, 5, 1, 0) - 1];
            c8_yb_b = muDoubleScalarIsNaN(c8_h_x);
            if (!c8_yb_b) {
              c8_mtmp = c8_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c8_b_ix), 1, 5, 1, 0) - 1];
              exitg2 = TRUE;
            } else {
              c8_ix++;
            }
          }
        }

        if (c8_ixstart < 5) {
          c8_ec_a = c8_ixstart;
          c8_i146 = c8_ec_a;
          c8_o_overflow = FALSE;
          if (c8_o_overflow) {
            c8_check_forloop_overflow_error(chartInstance, c8_o_overflow);
          }

          for (c8_c_ix = c8_i146 + 1; c8_c_ix < 6; c8_c_ix++) {
            c8_b_ix = c8_c_ix;
            c8_fc_a = c8_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c8_b_ix), 1, 5, 1, 0) - 1];
            c8_ac_b = c8_mtmp;
            c8_p = (c8_fc_a > c8_ac_b);
            if (c8_p) {
              c8_mtmp = c8_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c8_b_ix), 1, 5, 1, 0) - 1];
            }
          }
        }

        c8_b_mtmp = c8_mtmp;
        c8_scale = c8_b_mtmp;
        c8_sm = c8_eml_div(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_m), 1, 2, 1, 0) - 1],
                           c8_scale);
        c8_smm1 = c8_eml_div(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_mm1), 1,
          2, 1, 0) - 1], c8_scale);
        c8_emm1 = c8_eml_div(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_mm1), 1,
          2, 1, 0) - 1], c8_scale);
        c8_sqds = c8_eml_div(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1,
          2, 1, 0) - 1], c8_scale);
        c8_eqds = c8_eml_div(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1,
          2, 1, 0) - 1], c8_scale);
        c8_gc_a = c8_smm1 + c8_sm;
        c8_bc_b = c8_smm1 - c8_sm;
        c8_o_y = c8_gc_a * c8_bc_b;
        c8_hc_a = c8_emm1;
        c8_cc_b = c8_emm1;
        c8_p_y = c8_hc_a * c8_cc_b;
        c8_dc_b = c8_eml_div(chartInstance, c8_o_y + c8_p_y, 2.0);
        c8_ic_a = c8_sm;
        c8_ec_b = c8_emm1;
        c8_jb_c = c8_ic_a * c8_ec_b;
        c8_jc_a = c8_jb_c;
        c8_fc_b = c8_jb_c;
        c8_jb_c = c8_jc_a * c8_fc_b;
        c8_shift = 0.0;
        guard1 = FALSE;
        if (c8_dc_b != 0.0) {
          guard1 = TRUE;
        } else {
          if (c8_jb_c != 0.0) {
            guard1 = TRUE;
          }
        }

        if (guard1 == TRUE) {
          c8_kc_a = c8_dc_b;
          c8_gc_b = c8_dc_b;
          c8_q_y = c8_kc_a * c8_gc_b;
          c8_shift = c8_q_y + c8_jb_c;
          c8_b_sqrt(chartInstance, &c8_shift);
          if (c8_dc_b < 0.0) {
            c8_shift = -c8_shift;
          }

          c8_shift = c8_eml_div(chartInstance, c8_jb_c, c8_dc_b + c8_shift);
        }

        c8_lc_a = c8_sqds + c8_sm;
        c8_hc_b = c8_sqds - c8_sm;
        c8_r_y = c8_lc_a * c8_hc_b;
        c8_f = c8_r_y + c8_shift;
        c8_mc_a = c8_sqds;
        c8_ic_b = c8_eqds;
        c8_g = c8_mc_a * c8_ic_b;
        c8_k_q = c8_b_q;
        c8_b_mm1 = c8_mm1;
        c8_nc_a = c8_k_q;
        c8_jc_b = c8_b_mm1;
        c8_oc_a = c8_nc_a;
        c8_kc_b = c8_jc_b;
        if (c8_oc_a > c8_kc_b) {
          c8_p_overflow = FALSE;
        } else {
          c8_p_overflow = (c8_kc_b > 2147483646);
        }

        if (c8_p_overflow) {
          c8_check_forloop_overflow_error(chartInstance, c8_p_overflow);
        }

        for (c8_d_k = c8_k_q; c8_d_k <= c8_b_mm1; c8_d_k++) {
          c8_b_k = c8_d_k;
          c8_pc_a = c8_b_k;
          c8_km1 = c8_pc_a;
          c8_qc_a = c8_b_k + 1;
          c8_kp1 = c8_qc_a;
          c8_c_f = c8_f;
          c8_unusedU1 = c8_g;
          c8_b_eml_xrotg(chartInstance, &c8_c_f, &c8_unusedU1, &c8_d_cs,
                         &c8_d_sn);
          c8_f = c8_c_f;
          c8_b_cs = c8_d_cs;
          c8_b_sn = c8_d_sn;
          if (c8_b_k > c8_b_q) {
            c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)(c8_km1 - 1)), 1, 2, 1, 0) - 1] = c8_f;
          }

          c8_rc_a = c8_b_cs;
          c8_lc_b = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 2, 1, 0) - 1];
          c8_s_y = c8_rc_a * c8_lc_b;
          c8_sc_a = c8_b_sn;
          c8_mc_b = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 2, 1, 0) - 1];
          c8_t_y = c8_sc_a * c8_mc_b;
          c8_f = c8_s_y + c8_t_y;
          c8_tc_a = c8_b_cs;
          c8_nc_b = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 2, 1, 0) - 1];
          c8_u_y = c8_tc_a * c8_nc_b;
          c8_uc_a = c8_b_sn;
          c8_oc_b = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 2, 1, 0) - 1];
          c8_v_y = c8_uc_a * c8_oc_b;
          c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_k), 1, 2, 1, 0) - 1] = c8_u_y - c8_v_y;
          c8_vc_a = c8_b_sn;
          c8_pc_b = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_kp1), 1, 2, 1, 0) - 1];
          c8_g = c8_vc_a * c8_pc_b;
          c8_wc_a = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_kp1), 1, 2, 1, 0) - 1];
          c8_qc_b = c8_b_cs;
          c8_w_y = c8_wc_a * c8_qc_b;
          c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_kp1), 1, 2, 1, 0) - 1] = c8_w_y;
          c8_xc_a = c8_b_k;
          c8_kb_c = c8_xc_a;
          c8_rc_b = c8_kb_c - 1;
          c8_lb_c = c8_rc_b << 1;
          c8_sc_b = c8_lb_c;
          c8_colk = c8_sc_b;
          c8_tc_b = c8_b_k;
          c8_mb_c = c8_tc_b << 1;
          c8_uc_b = c8_mb_c;
          c8_colkp1 = c8_uc_b;
          c8_c_eml_xrot(chartInstance, c8_Vf, c8_colk + 1, c8_colkp1 + 1,
                        c8_b_cs, c8_b_sn);
          c8_d_f = c8_f;
          c8_unusedU2 = c8_g;
          c8_b_eml_xrotg(chartInstance, &c8_d_f, &c8_unusedU2, &c8_e_cs,
                         &c8_e_sn);
          c8_f = c8_d_f;
          c8_b_cs = c8_e_cs;
          c8_b_sn = c8_e_sn;
          c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_k), 1, 2, 1, 0) - 1] = c8_f;
          c8_yc_a = c8_b_cs;
          c8_vc_b = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 2, 1, 0) - 1];
          c8_x_y = c8_yc_a * c8_vc_b;
          c8_ad_a = c8_b_sn;
          c8_wc_b = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_kp1), 1, 2, 1, 0) - 1];
          c8_y_y = c8_ad_a * c8_wc_b;
          c8_f = c8_x_y + c8_y_y;
          c8_bd_a = -c8_b_sn;
          c8_xc_b = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 2, 1, 0) - 1];
          c8_ab_y = c8_bd_a * c8_xc_b;
          c8_cd_a = c8_b_cs;
          c8_yc_b = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_kp1), 1, 2, 1, 0) - 1];
          c8_bb_y = c8_cd_a * c8_yc_b;
          c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_kp1), 1, 2, 1, 0) - 1] = c8_ab_y + c8_bb_y;
          c8_dd_a = c8_b_sn;
          c8_ad_b = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_kp1), 1, 2, 1, 0) - 1];
          c8_g = c8_dd_a * c8_ad_b;
          c8_ed_a = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_kp1), 1, 2, 1, 0) - 1];
          c8_bd_b = c8_b_cs;
          c8_cb_y = c8_ed_a * c8_bd_b;
          c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_kp1), 1, 2, 1, 0) - 1] = c8_cb_y;
          if (c8_b_k < 3) {
            c8_fd_a = c8_b_k;
            c8_nb_c = c8_fd_a;
            c8_cd_b = c8_nb_c - 1;
            c8_ob_c = 3 * c8_cd_b;
            c8_dd_b = c8_ob_c;
            c8_colk = c8_dd_b;
            c8_ed_b = c8_b_k;
            c8_pb_c = 3 * c8_ed_b;
            c8_fd_b = c8_pb_c;
            c8_colkp1 = c8_fd_b;
            c8_d_eml_xrot(chartInstance, c8_U, c8_colk + 1, c8_colkp1 + 1,
                          c8_b_cs, c8_b_sn);
          }
        }

        c8_gd_a = c8_m;
        c8_qb_c = c8_gd_a;
        c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c8_qb_c - 1)), 1, 2, 1, 0) - 1] = c8_f;
        c8_iter++;
        break;

       default:
        if (c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c8_b_q), 1, 2, 1, 0) - 1] < 0.0) {
          c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_q), 1, 2, 1, 0) - 1] =
            -c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_q), 1, 2, 1, 0) - 1];
          c8_hd_a = c8_b_q;
          c8_rb_c = c8_hd_a;
          c8_gd_b = c8_rb_c - 1;
          c8_sb_c = c8_gd_b << 1;
          c8_hd_b = c8_sb_c;
          c8_colq = c8_hd_b;
          c8_b_eml_scalar_eg(chartInstance);
          c8_d10 = -1.0;
          c8_k_eml_xscal(chartInstance, c8_d10, c8_Vf, c8_colq + 1);
        }

        c8_id_a = c8_b_q + 1;
        c8_qp1 = c8_id_a;
        exitg3 = FALSE;
        while ((exitg3 == FALSE) && (c8_b_q < 2)) {
          if (c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c8_b_q), 1, 2, 1, 0) - 1] <
              c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c8_qp1), 1, 2, 1, 0) - 1]) {
            c8_rt = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 2, 1, 0) - 1];
            c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c8_b_q), 1, 2, 1, 0) - 1] =
              c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c8_qp1), 1, 2, 1, 0) - 1];
            c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c8_qp1), 1, 2, 1, 0) - 1] = c8_rt;
            if (c8_b_q < 2) {
              c8_kd_a = c8_b_q;
              c8_tb_c = c8_kd_a;
              c8_id_b = c8_tb_c - 1;
              c8_ub_c = c8_id_b << 1;
              c8_jd_b = c8_ub_c;
              c8_colq = c8_jd_b;
              c8_kd_b = c8_b_q;
              c8_vb_c = c8_kd_b << 1;
              c8_ld_b = c8_vb_c;
              c8_colqp1 = c8_ld_b;
              c8_c_eml_xswap(chartInstance, c8_Vf, c8_colq + 1, c8_colqp1 + 1);
            }

            if (c8_b_q < 3) {
              c8_ld_a = c8_b_q;
              c8_wb_c = c8_ld_a;
              c8_md_b = c8_wb_c - 1;
              c8_xb_c = 3 * c8_md_b;
              c8_nd_b = c8_xb_c;
              c8_colq = c8_nd_b;
              c8_od_b = c8_b_q;
              c8_yb_c = 3 * c8_od_b;
              c8_pd_b = c8_yb_c;
              c8_colqp1 = c8_pd_b;
              c8_d_eml_xswap(chartInstance, c8_U, c8_colq + 1, c8_colqp1 + 1);
            }

            c8_b_q = c8_qp1;
            c8_md_a = c8_b_q + 1;
            c8_qp1 = c8_md_a;
          } else {
            exitg3 = TRUE;
          }
        }

        c8_iter = 0.0;
        c8_jd_a = c8_m - 1;
        c8_m = c8_jd_a;
        break;
      }
    }
  }

  for (c8_e_k = 1; c8_e_k < 3; c8_e_k++) {
    c8_b_k = c8_e_k;
    c8_S[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c8_b_k), 1, 2, 1, 0) - 1] = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 2, 1, 0) - 1];
  }

  for (c8_j = 1; c8_j < 3; c8_j++) {
    c8_b_j = c8_j;
    for (c8_i = 1; c8_i < 3; c8_i++) {
      c8_b_i = c8_i;
      c8_V[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c8_b_i), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
               (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_j), 1, 2, 2, 0) - 1)
             << 1)) - 1] = c8_Vf[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c8_b_i), 1, 2, 1, 0) +
        ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c8_b_j), 1, 2, 2, 0) - 1) << 1)) - 1];
    }
  }
}

static real_T c8_eml_xnrm2(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_x[6], int32_T c8_ix0)
{
  real_T c8_y;
  int32_T c8_b_n;
  int32_T c8_b_ix0;
  int32_T c8_c_n;
  int32_T c8_c_ix0;
  real_T c8_b_x;
  real_T c8_c_x;
  real_T c8_scale;
  int32_T c8_kstart;
  int32_T c8_b_a;
  int32_T c8_c;
  int32_T c8_c_a;
  int32_T c8_b_c;
  int32_T c8_d_a;
  int32_T c8_b;
  int32_T c8_kend;
  int32_T c8_b_kstart;
  int32_T c8_b_kend;
  int32_T c8_e_a;
  int32_T c8_b_b;
  int32_T c8_f_a;
  int32_T c8_c_b;
  boolean_T c8_overflow;
  int32_T c8_k;
  int32_T c8_b_k;
  real_T c8_d_x;
  real_T c8_e_x;
  real_T c8_absxk;
  real_T c8_t;
  c8_b_n = c8_n;
  c8_b_ix0 = c8_ix0;
  c8_c_n = c8_b_n;
  c8_c_ix0 = c8_b_ix0;
  c8_y = 0.0;
  if (c8_c_n < 1) {
  } else if (c8_c_n == 1) {
    c8_b_x = c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c8_c_ix0), 1, 6, 1, 0) - 1];
    c8_c_x = c8_b_x;
    c8_y = muDoubleScalarAbs(c8_c_x);
  } else {
    c8_realmin(chartInstance);
    c8_scale = 2.2250738585072014E-308;
    c8_kstart = c8_c_ix0;
    c8_b_a = c8_c_n;
    c8_c = c8_b_a;
    c8_c_a = c8_c - 1;
    c8_b_c = c8_c_a;
    c8_d_a = c8_kstart;
    c8_b = c8_b_c;
    c8_kend = c8_d_a + c8_b;
    c8_b_kstart = c8_kstart;
    c8_b_kend = c8_kend;
    c8_e_a = c8_b_kstart;
    c8_b_b = c8_b_kend;
    c8_f_a = c8_e_a;
    c8_c_b = c8_b_b;
    if (c8_f_a > c8_c_b) {
      c8_overflow = FALSE;
    } else {
      c8_overflow = (c8_c_b > 2147483646);
    }

    if (c8_overflow) {
      c8_check_forloop_overflow_error(chartInstance, c8_overflow);
    }

    for (c8_k = c8_b_kstart; c8_k <= c8_b_kend; c8_k++) {
      c8_b_k = c8_k;
      c8_d_x = c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c8_b_k), 1, 6, 1, 0) - 1];
      c8_e_x = c8_d_x;
      c8_absxk = muDoubleScalarAbs(c8_e_x);
      if (c8_absxk > c8_scale) {
        c8_t = c8_scale / c8_absxk;
        c8_y = 1.0 + c8_y * c8_t * c8_t;
        c8_scale = c8_absxk;
      } else {
        c8_t = c8_absxk / c8_scale;
        c8_y += c8_t * c8_t;
      }
    }

    c8_y = c8_scale * muDoubleScalarSqrt(c8_y);
  }

  return c8_y;
}

static void c8_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_b_a, real_T c8_x[6], int32_T c8_ix0, real_T c8_b_x[6])
{
  int32_T c8_i147;
  for (c8_i147 = 0; c8_i147 < 6; c8_i147++) {
    c8_b_x[c8_i147] = c8_x[c8_i147];
  }

  c8_h_eml_xscal(chartInstance, c8_n, c8_b_a, c8_b_x, c8_ix0);
}

static real_T c8_eml_xdotc(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_x[6], int32_T c8_ix0, real_T c8_y[6], int32_T c8_iy0)
{
  real_T c8_d;
  int32_T c8_b_n;
  int32_T c8_b_ix0;
  int32_T c8_b_iy0;
  int32_T c8_c_n;
  int32_T c8_c_ix0;
  int32_T c8_c_iy0;
  int32_T c8_d_n;
  int32_T c8_d_ix0;
  int32_T c8_d_iy0;
  int32_T c8_e_n;
  int32_T c8_e_ix0;
  int32_T c8_e_iy0;
  int32_T c8_ix;
  int32_T c8_iy;
  int32_T c8_f_n;
  int32_T c8_b;
  int32_T c8_b_b;
  boolean_T c8_overflow;
  int32_T c8_k;
  int32_T c8_b_a;
  int32_T c8_c_a;
  c8_b_n = c8_n;
  c8_b_ix0 = c8_ix0;
  c8_b_iy0 = c8_iy0;
  c8_c_n = c8_b_n;
  c8_c_ix0 = c8_b_ix0;
  c8_c_iy0 = c8_b_iy0;
  c8_d_n = c8_c_n;
  c8_d_ix0 = c8_c_ix0;
  c8_d_iy0 = c8_c_iy0;
  c8_e_n = c8_d_n;
  c8_e_ix0 = c8_d_ix0;
  c8_e_iy0 = c8_d_iy0;
  c8_d = 0.0;
  if (c8_e_n < 1) {
  } else {
    c8_ix = c8_e_ix0;
    c8_iy = c8_e_iy0;
    c8_f_n = c8_e_n;
    c8_b = c8_f_n;
    c8_b_b = c8_b;
    if (1 > c8_b_b) {
      c8_overflow = FALSE;
    } else {
      c8_overflow = (c8_b_b > 2147483646);
    }

    if (c8_overflow) {
      c8_check_forloop_overflow_error(chartInstance, c8_overflow);
    }

    for (c8_k = 1; c8_k <= c8_f_n; c8_k++) {
      c8_d += c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c8_ix), 1, 6, 1, 0) - 1] * c8_y[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_iy), 1, 6, 1, 0) - 1];
      c8_b_a = c8_ix + 1;
      c8_ix = c8_b_a;
      c8_c_a = c8_iy + 1;
      c8_iy = c8_c_a;
    }
  }

  return c8_d;
}

static void c8_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_b_a, int32_T c8_ix0, real_T c8_y[6], int32_T c8_iy0,
  real_T c8_b_y[6])
{
  int32_T c8_i148;
  for (c8_i148 = 0; c8_i148 < 6; c8_i148++) {
    c8_b_y[c8_i148] = c8_y[c8_i148];
  }

  c8_i_eml_xaxpy(chartInstance, c8_n, c8_b_a, c8_ix0, c8_b_y, c8_iy0);
}

static real_T c8_b_eml_xnrm2(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_x[2], int32_T c8_ix0)
{
  real_T c8_y;
  int32_T c8_b_n;
  int32_T c8_b_ix0;
  int32_T c8_c_n;
  int32_T c8_c_ix0;
  real_T c8_b_x;
  real_T c8_c_x;
  real_T c8_scale;
  int32_T c8_kstart;
  int32_T c8_b_a;
  int32_T c8_c;
  int32_T c8_c_a;
  int32_T c8_b_c;
  int32_T c8_d_a;
  int32_T c8_b;
  int32_T c8_kend;
  int32_T c8_b_kstart;
  int32_T c8_b_kend;
  int32_T c8_e_a;
  int32_T c8_b_b;
  int32_T c8_f_a;
  int32_T c8_c_b;
  boolean_T c8_overflow;
  int32_T c8_k;
  int32_T c8_b_k;
  real_T c8_d_x;
  real_T c8_e_x;
  real_T c8_absxk;
  real_T c8_t;
  c8_b_n = c8_n;
  c8_b_ix0 = c8_ix0;
  c8_c_n = c8_b_n;
  c8_c_ix0 = c8_b_ix0;
  c8_y = 0.0;
  if (c8_c_n < 1) {
  } else if (c8_c_n == 1) {
    c8_b_x = c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c8_c_ix0), 1, 2, 1, 0) - 1];
    c8_c_x = c8_b_x;
    c8_y = muDoubleScalarAbs(c8_c_x);
  } else {
    c8_realmin(chartInstance);
    c8_scale = 2.2250738585072014E-308;
    c8_kstart = c8_c_ix0;
    c8_b_a = c8_c_n;
    c8_c = c8_b_a;
    c8_c_a = c8_c - 1;
    c8_b_c = c8_c_a;
    c8_d_a = c8_kstart;
    c8_b = c8_b_c;
    c8_kend = c8_d_a + c8_b;
    c8_b_kstart = c8_kstart;
    c8_b_kend = c8_kend;
    c8_e_a = c8_b_kstart;
    c8_b_b = c8_b_kend;
    c8_f_a = c8_e_a;
    c8_c_b = c8_b_b;
    if (c8_f_a > c8_c_b) {
      c8_overflow = FALSE;
    } else {
      c8_overflow = (c8_c_b > 2147483646);
    }

    if (c8_overflow) {
      c8_check_forloop_overflow_error(chartInstance, c8_overflow);
    }

    for (c8_k = c8_b_kstart; c8_k <= c8_b_kend; c8_k++) {
      c8_b_k = c8_k;
      c8_d_x = c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c8_b_k), 1, 2, 1, 0) - 1];
      c8_e_x = c8_d_x;
      c8_absxk = muDoubleScalarAbs(c8_e_x);
      if (c8_absxk > c8_scale) {
        c8_t = c8_scale / c8_absxk;
        c8_y = 1.0 + c8_y * c8_t * c8_t;
        c8_scale = c8_absxk;
      } else {
        c8_t = c8_absxk / c8_scale;
        c8_y += c8_t * c8_t;
      }
    }

    c8_y = c8_scale * muDoubleScalarSqrt(c8_y);
  }

  return c8_y;
}

static void c8_b_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_b_a, real_T c8_x[2], int32_T c8_ix0, real_T c8_b_x[2])
{
  int32_T c8_i149;
  for (c8_i149 = 0; c8_i149 < 2; c8_i149++) {
    c8_b_x[c8_i149] = c8_x[c8_i149];
  }

  c8_i_eml_xscal(chartInstance, c8_n, c8_b_a, c8_b_x, c8_ix0);
}

static void c8_b_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_b_a, real_T c8_x[6], int32_T c8_ix0, real_T c8_y[3],
  int32_T c8_iy0, real_T c8_b_y[3])
{
  int32_T c8_i150;
  int32_T c8_i151;
  real_T c8_b_x[6];
  for (c8_i150 = 0; c8_i150 < 3; c8_i150++) {
    c8_b_y[c8_i150] = c8_y[c8_i150];
  }

  for (c8_i151 = 0; c8_i151 < 6; c8_i151++) {
    c8_b_x[c8_i151] = c8_x[c8_i151];
  }

  c8_j_eml_xaxpy(chartInstance, c8_n, c8_b_a, c8_b_x, c8_ix0, c8_b_y, c8_iy0);
}

static void c8_c_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_b_a, real_T c8_x[3], int32_T c8_ix0, real_T c8_y[6],
  int32_T c8_iy0, real_T c8_b_y[6])
{
  int32_T c8_i152;
  int32_T c8_i153;
  real_T c8_b_x[3];
  for (c8_i152 = 0; c8_i152 < 6; c8_i152++) {
    c8_b_y[c8_i152] = c8_y[c8_i152];
  }

  for (c8_i153 = 0; c8_i153 < 3; c8_i153++) {
    c8_b_x[c8_i153] = c8_x[c8_i153];
  }

  c8_k_eml_xaxpy(chartInstance, c8_n, c8_b_a, c8_b_x, c8_ix0, c8_b_y, c8_iy0);
}

static real_T c8_b_eml_xdotc(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_x[4], int32_T c8_ix0, real_T c8_y[4], int32_T c8_iy0)
{
  real_T c8_d;
  int32_T c8_b_n;
  int32_T c8_b_ix0;
  int32_T c8_b_iy0;
  int32_T c8_c_n;
  int32_T c8_c_ix0;
  int32_T c8_c_iy0;
  int32_T c8_d_n;
  int32_T c8_d_ix0;
  int32_T c8_d_iy0;
  int32_T c8_e_n;
  int32_T c8_e_ix0;
  int32_T c8_e_iy0;
  int32_T c8_ix;
  int32_T c8_iy;
  int32_T c8_f_n;
  int32_T c8_b;
  int32_T c8_b_b;
  boolean_T c8_overflow;
  int32_T c8_k;
  int32_T c8_b_a;
  int32_T c8_c_a;
  c8_b_n = c8_n;
  c8_b_ix0 = c8_ix0;
  c8_b_iy0 = c8_iy0;
  c8_c_n = c8_b_n;
  c8_c_ix0 = c8_b_ix0;
  c8_c_iy0 = c8_b_iy0;
  c8_d_n = c8_c_n;
  c8_d_ix0 = c8_c_ix0;
  c8_d_iy0 = c8_c_iy0;
  c8_e_n = c8_d_n;
  c8_e_ix0 = c8_d_ix0;
  c8_e_iy0 = c8_d_iy0;
  c8_e_eml_scalar_eg(chartInstance);
  c8_d = 0.0;
  if (c8_e_n < 1) {
  } else {
    c8_ix = c8_e_ix0;
    c8_iy = c8_e_iy0;
    c8_f_n = c8_e_n;
    c8_b = c8_f_n;
    c8_b_b = c8_b;
    if (1 > c8_b_b) {
      c8_overflow = FALSE;
    } else {
      c8_overflow = (c8_b_b > 2147483646);
    }

    if (c8_overflow) {
      c8_check_forloop_overflow_error(chartInstance, c8_overflow);
    }

    for (c8_k = 1; c8_k <= c8_f_n; c8_k++) {
      c8_d += c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c8_ix), 1, 4, 1, 0) - 1] * c8_y[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_iy), 1, 4, 1, 0) - 1];
      c8_b_a = c8_ix + 1;
      c8_ix = c8_b_a;
      c8_c_a = c8_iy + 1;
      c8_iy = c8_c_a;
    }
  }

  return c8_d;
}

static void c8_e_eml_scalar_eg(SFc8_CusakisME4901InstanceStruct *chartInstance)
{
}

static void c8_d_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_b_a, int32_T c8_ix0, real_T c8_y[4], int32_T c8_iy0,
  real_T c8_b_y[4])
{
  int32_T c8_i154;
  for (c8_i154 = 0; c8_i154 < 4; c8_i154++) {
    c8_b_y[c8_i154] = c8_y[c8_i154];
  }

  c8_l_eml_xaxpy(chartInstance, c8_n, c8_b_a, c8_ix0, c8_b_y, c8_iy0);
}

static void c8_c_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[6], int32_T c8_ix0, real_T c8_b_x[6])
{
  int32_T c8_i155;
  for (c8_i155 = 0; c8_i155 < 6; c8_i155++) {
    c8_b_x[c8_i155] = c8_x[c8_i155];
  }

  c8_j_eml_xscal(chartInstance, c8_b_a, c8_b_x, c8_ix0);
}

static void c8_d_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[4], int32_T c8_ix0, real_T c8_b_x[4])
{
  int32_T c8_i156;
  for (c8_i156 = 0; c8_i156 < 4; c8_i156++) {
    c8_b_x[c8_i156] = c8_x[c8_i156];
  }

  c8_k_eml_xscal(chartInstance, c8_b_a, c8_b_x, c8_ix0);
}

static void c8_b_below_threshold(SFc8_CusakisME4901InstanceStruct *chartInstance)
{
}

static void c8_d_eml_error(SFc8_CusakisME4901InstanceStruct *chartInstance)
{
  int32_T c8_i157;
  static char_T c8_cv6[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'v', 'd', '_', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r',
    'g', 'e', 'n', 'c', 'e' };

  char_T c8_u[30];
  const mxArray *c8_y = NULL;
  for (c8_i157 = 0; c8_i157 < 30; c8_i157++) {
    c8_u[c8_i157] = c8_cv6[c8_i157];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c8_y));
}

static void c8_eml_xrotg(SFc8_CusakisME4901InstanceStruct *chartInstance, real_T
  c8_b_a, real_T c8_b, real_T *c8_c_a, real_T *c8_b_b, real_T *c8_c, real_T
  *c8_s)
{
  *c8_c_a = c8_b_a;
  *c8_b_b = c8_b;
  c8_b_eml_xrotg(chartInstance, c8_c_a, c8_b_b, c8_c, c8_s);
}

static void c8_eml_xrot(SFc8_CusakisME4901InstanceStruct *chartInstance, real_T
  c8_x[4], int32_T c8_ix0, int32_T c8_iy0, real_T c8_c, real_T c8_s, real_T
  c8_b_x[4])
{
  int32_T c8_i158;
  for (c8_i158 = 0; c8_i158 < 4; c8_i158++) {
    c8_b_x[c8_i158] = c8_x[c8_i158];
  }

  c8_c_eml_xrot(chartInstance, c8_b_x, c8_ix0, c8_iy0, c8_c, c8_s);
}

static void c8_b_eml_xrot(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_x[6], int32_T c8_ix0, int32_T c8_iy0, real_T c8_c, real_T c8_s,
  real_T c8_b_x[6])
{
  int32_T c8_i159;
  for (c8_i159 = 0; c8_i159 < 6; c8_i159++) {
    c8_b_x[c8_i159] = c8_x[c8_i159];
  }

  c8_d_eml_xrot(chartInstance, c8_b_x, c8_ix0, c8_iy0, c8_c, c8_s);
}

static void c8_eml_xswap(SFc8_CusakisME4901InstanceStruct *chartInstance, real_T
  c8_x[4], int32_T c8_ix0, int32_T c8_iy0, real_T c8_b_x[4])
{
  int32_T c8_i160;
  for (c8_i160 = 0; c8_i160 < 4; c8_i160++) {
    c8_b_x[c8_i160] = c8_x[c8_i160];
  }

  c8_c_eml_xswap(chartInstance, c8_b_x, c8_ix0, c8_iy0);
}

static void c8_b_eml_xswap(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_x[6], int32_T c8_ix0, int32_T c8_iy0, real_T c8_b_x[6])
{
  int32_T c8_i161;
  for (c8_i161 = 0; c8_i161 < 6; c8_i161++) {
    c8_b_x[c8_i161] = c8_x[c8_i161];
  }

  c8_d_eml_xswap(chartInstance, c8_b_x, c8_ix0, c8_iy0);
}

static void c8_eml_xgemm(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_k, real_T c8_A[4], real_T c8_B[6], real_T c8_C[6], real_T c8_b_C[6])
{
  int32_T c8_i162;
  int32_T c8_i163;
  real_T c8_b_A[4];
  int32_T c8_i164;
  real_T c8_b_B[6];
  for (c8_i162 = 0; c8_i162 < 6; c8_i162++) {
    c8_b_C[c8_i162] = c8_C[c8_i162];
  }

  for (c8_i163 = 0; c8_i163 < 4; c8_i163++) {
    c8_b_A[c8_i163] = c8_A[c8_i163];
  }

  for (c8_i164 = 0; c8_i164 < 6; c8_i164++) {
    c8_b_B[c8_i164] = c8_B[c8_i164];
  }

  c8_c_eml_xgemm(chartInstance, c8_k, c8_b_A, c8_b_B, c8_b_C);
}

static void c8_f_eml_scalar_eg(SFc8_CusakisME4901InstanceStruct *chartInstance)
{
}

static void c8_g_eml_scalar_eg(SFc8_CusakisME4901InstanceStruct *chartInstance)
{
}

static void c8_svd(SFc8_CusakisME4901InstanceStruct *chartInstance, real_T c8_A
                   [6], real_T c8_U[2])
{
  int32_T c8_k;
  int32_T c8_b_k;
  real_T c8_x;
  real_T c8_b_x;
  boolean_T c8_b;
  boolean_T c8_b2;
  real_T c8_c_x;
  boolean_T c8_b_b;
  boolean_T c8_b3;
  boolean_T c8_c_b;
  int32_T c8_i165;
  real_T c8_b_A[6];
  for (c8_k = 1; c8_k < 7; c8_k++) {
    c8_b_k = c8_k;
    c8_x = c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c8_b_k), 1, 6, 1, 0) - 1];
    c8_b_x = c8_x;
    c8_b = muDoubleScalarIsInf(c8_b_x);
    c8_b2 = !c8_b;
    c8_c_x = c8_x;
    c8_b_b = muDoubleScalarIsNaN(c8_c_x);
    c8_b3 = !c8_b_b;
    c8_c_b = (c8_b2 && c8_b3);
    if (!c8_c_b) {
      c8_c_eml_error(chartInstance);
    }
  }

  for (c8_i165 = 0; c8_i165 < 6; c8_i165++) {
    c8_b_A[c8_i165] = c8_A[c8_i165];
  }

  c8_eml_matlab_zsvdc(chartInstance, c8_b_A, c8_U);
}

static void c8_eml_matlab_zsvdc(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_A[6], real_T c8_S[2])
{
  int32_T c8_i166;
  real_T c8_e[3];
  int32_T c8_i167;
  real_T c8_work[2];
  int32_T c8_i168;
  real_T c8_b_A[6];
  real_T c8_nrm;
  real_T c8_absx;
  real_T c8_d;
  real_T c8_y;
  real_T c8_s[3];
  real_T c8_d11;
  int32_T c8_jj;
  int32_T c8_b_jj;
  int32_T c8_b_a;
  int32_T c8_c;
  int32_T c8_b;
  int32_T c8_b_c;
  int32_T c8_b_b;
  int32_T c8_qjj;
  int32_T c8_i169;
  real_T c8_c_A[6];
  int32_T c8_i170;
  real_T c8_d_A[6];
  real_T c8_t;
  int32_T c8_i171;
  real_T c8_b_e[3];
  real_T c8_b_absx;
  real_T c8_b_d;
  real_T c8_b_y;
  real_T c8_d12;
  int32_T c8_c_jj;
  int32_T c8_c_a;
  int32_T c8_c_c;
  int32_T c8_c_b;
  int32_T c8_d_c;
  int32_T c8_d_b;
  int32_T c8_qp1jj;
  int32_T c8_i172;
  real_T c8_e_A[6];
  int32_T c8_d_jj;
  int32_T c8_d_a;
  int32_T c8_e_c;
  int32_T c8_e_b;
  int32_T c8_f_c;
  int32_T c8_f_b;
  int32_T c8_i173;
  real_T c8_b_work[2];
  int32_T c8_m;
  int32_T c8_q;
  int32_T c8_b_q;
  real_T c8_rt;
  real_T c8_r;
  int32_T c8_e_a;
  int32_T c8_g_c;
  int32_T c8_f_a;
  int32_T c8_h_c;
  real_T c8_g_a;
  real_T c8_g_b;
  real_T c8_c_y;
  real_T c8_iter;
  real_T c8_tiny;
  real_T c8_snorm;
  int32_T c8_ii;
  int32_T c8_b_ii;
  real_T c8_varargin_1;
  real_T c8_varargin_2;
  real_T c8_b_varargin_2;
  real_T c8_varargin_3;
  real_T c8_x;
  real_T c8_d_y;
  real_T c8_b_x;
  real_T c8_e_y;
  real_T c8_xk;
  real_T c8_yk;
  real_T c8_c_x;
  real_T c8_f_y;
  real_T c8_maxval;
  real_T c8_b_varargin_1;
  real_T c8_c_varargin_2;
  real_T c8_d_varargin_2;
  real_T c8_b_varargin_3;
  real_T c8_d_x;
  real_T c8_g_y;
  real_T c8_e_x;
  real_T c8_h_y;
  real_T c8_b_xk;
  real_T c8_b_yk;
  real_T c8_f_x;
  real_T c8_i_y;
  int32_T c8_h_a;
  int32_T c8_i_a;
  int32_T c8_i174;
  boolean_T c8_overflow;
  int32_T c8_c_ii;
  int32_T c8_j_a;
  int32_T c8_i_c;
  real_T c8_test0;
  real_T c8_ztest0;
  real_T c8_h_b;
  real_T c8_j_y;
  real_T c8_i_b;
  real_T c8_k_y;
  int32_T c8_k_a;
  int32_T c8_j_c;
  real_T c8_kase;
  int32_T c8_qs;
  int32_T c8_b_m;
  int32_T c8_c_q;
  int32_T c8_l_a;
  int32_T c8_j_b;
  int32_T c8_m_a;
  int32_T c8_k_b;
  boolean_T c8_b_overflow;
  int32_T c8_d_ii;
  real_T c8_test;
  int32_T c8_n_a;
  int32_T c8_k_c;
  int32_T c8_o_a;
  int32_T c8_l_c;
  real_T c8_ztest;
  real_T c8_l_b;
  real_T c8_l_y;
  int32_T c8_p_a;
  int32_T c8_q_a;
  int32_T c8_m_c;
  real_T c8_f;
  int32_T c8_r_a;
  int32_T c8_n_c;
  int32_T c8_s_a;
  int32_T c8_i175;
  int32_T c8_d_q;
  int32_T c8_t_a;
  int32_T c8_m_b;
  int32_T c8_u_a;
  int32_T c8_n_b;
  boolean_T c8_c_overflow;
  int32_T c8_k;
  int32_T c8_b_k;
  real_T c8_t1;
  real_T c8_b_t1;
  real_T c8_b_f;
  real_T c8_sn;
  real_T c8_cs;
  real_T c8_b_cs;
  real_T c8_b_sn;
  int32_T c8_v_a;
  int32_T c8_km1;
  real_T c8_w_a;
  real_T c8_o_b;
  real_T c8_x_a;
  real_T c8_p_b;
  real_T c8_m_y;
  int32_T c8_y_a;
  int32_T c8_qm1;
  int32_T c8_e_q;
  int32_T c8_c_m;
  int32_T c8_ab_a;
  int32_T c8_q_b;
  int32_T c8_bb_a;
  int32_T c8_r_b;
  boolean_T c8_d_overflow;
  int32_T c8_c_k;
  real_T c8_c_t1;
  real_T c8_unusedU0;
  real_T c8_c_sn;
  real_T c8_c_cs;
  real_T c8_cb_a;
  real_T c8_s_b;
  real_T c8_db_a;
  real_T c8_t_b;
  real_T c8_n_y;
  int32_T c8_eb_a;
  int32_T c8_mm1;
  real_T c8_d13;
  real_T c8_d14;
  real_T c8_d15;
  real_T c8_d16;
  real_T c8_d17;
  real_T c8_c_varargin_1[5];
  int32_T c8_ixstart;
  real_T c8_mtmp;
  real_T c8_g_x;
  boolean_T c8_u_b;
  int32_T c8_ix;
  int32_T c8_b_ix;
  real_T c8_h_x;
  boolean_T c8_v_b;
  int32_T c8_fb_a;
  int32_T c8_i176;
  boolean_T c8_e_overflow;
  int32_T c8_c_ix;
  real_T c8_gb_a;
  real_T c8_w_b;
  boolean_T c8_p;
  real_T c8_b_mtmp;
  real_T c8_scale;
  real_T c8_sm;
  real_T c8_smm1;
  real_T c8_emm1;
  real_T c8_sqds;
  real_T c8_eqds;
  real_T c8_hb_a;
  real_T c8_x_b;
  real_T c8_o_y;
  real_T c8_ib_a;
  real_T c8_y_b;
  real_T c8_p_y;
  real_T c8_ab_b;
  real_T c8_jb_a;
  real_T c8_bb_b;
  real_T c8_o_c;
  real_T c8_kb_a;
  real_T c8_cb_b;
  real_T c8_shift;
  real_T c8_lb_a;
  real_T c8_db_b;
  real_T c8_q_y;
  real_T c8_mb_a;
  real_T c8_eb_b;
  real_T c8_r_y;
  real_T c8_nb_a;
  real_T c8_fb_b;
  real_T c8_g;
  int32_T c8_f_q;
  int32_T c8_b_mm1;
  int32_T c8_ob_a;
  int32_T c8_gb_b;
  int32_T c8_pb_a;
  int32_T c8_hb_b;
  boolean_T c8_f_overflow;
  int32_T c8_d_k;
  int32_T c8_qb_a;
  int32_T c8_rb_a;
  int32_T c8_kp1;
  real_T c8_c_f;
  real_T c8_unusedU1;
  real_T c8_d_sn;
  real_T c8_d_cs;
  real_T c8_sb_a;
  real_T c8_ib_b;
  real_T c8_s_y;
  real_T c8_tb_a;
  real_T c8_jb_b;
  real_T c8_t_y;
  real_T c8_ub_a;
  real_T c8_kb_b;
  real_T c8_u_y;
  real_T c8_vb_a;
  real_T c8_lb_b;
  real_T c8_v_y;
  real_T c8_wb_a;
  real_T c8_mb_b;
  real_T c8_xb_a;
  real_T c8_nb_b;
  real_T c8_w_y;
  real_T c8_d_f;
  real_T c8_unusedU2;
  real_T c8_e_sn;
  real_T c8_e_cs;
  real_T c8_yb_a;
  real_T c8_ob_b;
  real_T c8_x_y;
  real_T c8_ac_a;
  real_T c8_pb_b;
  real_T c8_y_y;
  real_T c8_bc_a;
  real_T c8_qb_b;
  real_T c8_ab_y;
  real_T c8_cc_a;
  real_T c8_rb_b;
  real_T c8_bb_y;
  real_T c8_dc_a;
  real_T c8_sb_b;
  real_T c8_ec_a;
  real_T c8_tb_b;
  real_T c8_cb_y;
  int32_T c8_fc_a;
  int32_T c8_p_c;
  int32_T c8_e_k;
  int32_T c8_qp1;
  int32_T c8_gc_a;
  int32_T c8_hc_a;
  int32_T c8_ic_a;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T exitg4;
  boolean_T exitg5;
  boolean_T guard11 = FALSE;
  c8_f_eml_scalar_eg(chartInstance);
  for (c8_i166 = 0; c8_i166 < 3; c8_i166++) {
    c8_e[c8_i166] = 0.0;
  }

  for (c8_i167 = 0; c8_i167 < 2; c8_i167++) {
    c8_work[c8_i167] = 0.0;
  }

  for (c8_i168 = 0; c8_i168 < 6; c8_i168++) {
    c8_b_A[c8_i168] = c8_A[c8_i168];
  }

  c8_nrm = c8_c_eml_xnrm2(chartInstance, c8_b_A);
  if (c8_nrm > 0.0) {
    c8_absx = c8_nrm;
    c8_d = c8_A[0];
    if (c8_d < 0.0) {
      c8_y = -c8_absx;
    } else {
      c8_y = c8_absx;
    }

    c8_s[0] = c8_y;
    c8_d11 = c8_eml_div(chartInstance, 1.0, c8_s[0]);
    c8_l_eml_xscal(chartInstance, c8_d11, c8_A);
    c8_A[0]++;
    c8_s[0] = -c8_s[0];
  } else {
    c8_s[0] = 0.0;
  }

  for (c8_jj = 2; c8_jj < 4; c8_jj++) {
    c8_b_jj = c8_jj;
    c8_b_a = c8_b_jj;
    c8_c = c8_b_a;
    c8_b = c8_c - 1;
    c8_b_c = c8_b << 1;
    c8_b_b = c8_b_c + 1;
    c8_qjj = c8_b_b;
    if (c8_s[0] != 0.0) {
      for (c8_i169 = 0; c8_i169 < 6; c8_i169++) {
        c8_c_A[c8_i169] = c8_A[c8_i169];
      }

      for (c8_i170 = 0; c8_i170 < 6; c8_i170++) {
        c8_d_A[c8_i170] = c8_A[c8_i170];
      }

      c8_t = c8_c_eml_xdotc(chartInstance, c8_c_A, c8_d_A, c8_qjj);
      c8_t = -c8_eml_div(chartInstance, c8_t, c8_A[0]);
      c8_m_eml_xaxpy(chartInstance, c8_t, c8_A, c8_qjj);
    }

    c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c8_b_jj), 1, 3, 1, 0) - 1] = c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c8_qjj), 1, 6, 1, 0) - 1];
  }

  for (c8_i171 = 0; c8_i171 < 3; c8_i171++) {
    c8_b_e[c8_i171] = c8_e[c8_i171];
  }

  c8_nrm = c8_d_eml_xnrm2(chartInstance, c8_b_e);
  if (c8_nrm == 0.0) {
    c8_e[0] = 0.0;
  } else {
    c8_b_absx = c8_nrm;
    c8_b_d = c8_e[1];
    if (c8_b_d < 0.0) {
      c8_b_y = -c8_b_absx;
    } else {
      c8_b_y = c8_b_absx;
    }

    c8_e[0] = c8_b_y;
    c8_d12 = c8_eml_div(chartInstance, 1.0, c8_e[0]);
    c8_m_eml_xscal(chartInstance, c8_d12, c8_e);
    c8_e[1]++;
  }

  c8_e[0] = -c8_e[0];
  if (c8_e[0] != 0.0) {
    c8_work[1] = 0.0;
    for (c8_c_jj = 2; c8_c_jj < 4; c8_c_jj++) {
      c8_b_jj = c8_c_jj;
      c8_c_a = c8_b_jj;
      c8_c_c = c8_c_a;
      c8_c_b = c8_c_c - 1;
      c8_d_c = c8_c_b << 1;
      c8_d_b = c8_d_c;
      c8_qp1jj = c8_d_b;
      for (c8_i172 = 0; c8_i172 < 6; c8_i172++) {
        c8_e_A[c8_i172] = c8_A[c8_i172];
      }

      c8_n_eml_xaxpy(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_jj), 1, 3, 1, 0) - 1],
                     c8_e_A, c8_qp1jj + 2, c8_work);
    }

    for (c8_d_jj = 2; c8_d_jj < 4; c8_d_jj++) {
      c8_b_jj = c8_d_jj;
      c8_t = c8_eml_div(chartInstance, -c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_jj), 1, 3, 1, 0) - 1],
                        c8_e[1]);
      c8_d_a = c8_b_jj;
      c8_e_c = c8_d_a;
      c8_e_b = c8_e_c - 1;
      c8_f_c = c8_e_b << 1;
      c8_f_b = c8_f_c;
      c8_qp1jj = c8_f_b;
      for (c8_i173 = 0; c8_i173 < 2; c8_i173++) {
        c8_b_work[c8_i173] = c8_work[c8_i173];
      }

      c8_o_eml_xaxpy(chartInstance, c8_t, c8_b_work, c8_A, c8_qp1jj + 2);
    }
  }

  c8_m = 3;
  c8_s[1] = c8_A[3];
  c8_s[2] = 0.0;
  c8_e[1] = c8_A[5];
  c8_e[2] = 0.0;
  for (c8_q = 1; c8_q < 4; c8_q++) {
    c8_b_q = c8_q;
    if (c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_q), 1, 3, 1, 0) - 1] != 0.0) {
      c8_rt = c8_abs(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 3, 1, 0) - 1]);
      c8_r = c8_eml_div(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 3, 1, 0) - 1], c8_rt);
      c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c8_b_q), 1, 3, 1, 0) - 1] = c8_rt;
      if (c8_b_q < 3) {
        c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_q), 1, 3, 1, 0) - 1] = c8_eml_div(chartInstance,
          c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_q), 1, 3, 1, 0) - 1], c8_r);
      }
    }

    if (c8_b_q < 3) {
      if (c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_q), 1, 3, 1, 0) - 1] != 0.0) {
        c8_rt = c8_abs(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 3, 1, 0) - 1]);
        c8_r = c8_eml_div(chartInstance, c8_rt, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK
                          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q),
                           1, 3, 1, 0) - 1]);
        c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_q), 1, 3, 1, 0) - 1] = c8_rt;
        c8_e_a = c8_b_q;
        c8_g_c = c8_e_a;
        c8_f_a = c8_b_q;
        c8_h_c = c8_f_a;
        c8_g_a = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c8_h_c + 1)), 1, 3, 1, 0) - 1];
        c8_g_b = c8_r;
        c8_c_y = c8_g_a * c8_g_b;
        c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c8_g_c + 1)), 1, 3, 1, 0) - 1] = c8_c_y;
      }
    }
  }

  c8_iter = 0.0;
  c8_realmin(chartInstance);
  c8_eps(chartInstance);
  c8_tiny = c8_eml_div(chartInstance, 2.2250738585072014E-308,
                       2.2204460492503131E-16);
  c8_snorm = 0.0;
  for (c8_ii = 1; c8_ii < 4; c8_ii++) {
    c8_b_ii = c8_ii;
    c8_varargin_1 = c8_abs(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_ii), 1, 3, 1, 0) - 1]);
    c8_varargin_2 = c8_abs(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_ii), 1, 3, 1, 0) - 1]);
    c8_b_varargin_2 = c8_varargin_1;
    c8_varargin_3 = c8_varargin_2;
    c8_x = c8_b_varargin_2;
    c8_d_y = c8_varargin_3;
    c8_b_x = c8_x;
    c8_e_y = c8_d_y;
    c8_c_eml_scalar_eg(chartInstance);
    c8_xk = c8_b_x;
    c8_yk = c8_e_y;
    c8_c_x = c8_xk;
    c8_f_y = c8_yk;
    c8_c_eml_scalar_eg(chartInstance);
    c8_maxval = muDoubleScalarMax(c8_c_x, c8_f_y);
    c8_b_varargin_1 = c8_snorm;
    c8_c_varargin_2 = c8_maxval;
    c8_d_varargin_2 = c8_b_varargin_1;
    c8_b_varargin_3 = c8_c_varargin_2;
    c8_d_x = c8_d_varargin_2;
    c8_g_y = c8_b_varargin_3;
    c8_e_x = c8_d_x;
    c8_h_y = c8_g_y;
    c8_c_eml_scalar_eg(chartInstance);
    c8_b_xk = c8_e_x;
    c8_b_yk = c8_h_y;
    c8_f_x = c8_b_xk;
    c8_i_y = c8_b_yk;
    c8_c_eml_scalar_eg(chartInstance);
    c8_snorm = muDoubleScalarMax(c8_f_x, c8_i_y);
  }

  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c8_m > 0)) {
    if (c8_iter >= 75.0) {
      c8_d_eml_error(chartInstance);
      exitg1 = TRUE;
    } else {
      c8_h_a = c8_m - 1;
      c8_b_q = c8_h_a;
      c8_i_a = c8_m;
      c8_i174 = c8_i_a;
      c8_overflow = FALSE;
      if (c8_overflow) {
        c8_check_forloop_overflow_error(chartInstance, c8_overflow);
      }

      c8_c_ii = c8_i174 - 1;
      guard3 = FALSE;
      guard4 = FALSE;
      exitg5 = FALSE;
      while ((exitg5 == FALSE) && (c8_c_ii > -1)) {
        c8_b_ii = c8_c_ii;
        c8_b_q = c8_b_ii;
        if (c8_b_ii == 0) {
          exitg5 = TRUE;
        } else {
          c8_j_a = c8_b_ii;
          c8_i_c = c8_j_a;
          c8_test0 = c8_abs(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_ii), 1,
            3, 1, 0) - 1]) + c8_abs(chartInstance,
            c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                                      (real_T)(c8_i_c + 1)), 1, 3, 1, 0) - 1]);
          c8_ztest0 = c8_abs(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_ii),
            1, 3, 1, 0) - 1]);
          c8_eps(chartInstance);
          c8_h_b = c8_test0;
          c8_j_y = 2.2204460492503131E-16 * c8_h_b;
          if (c8_ztest0 <= c8_j_y) {
            guard4 = TRUE;
            exitg5 = TRUE;
          } else if (c8_ztest0 <= c8_tiny) {
            guard4 = TRUE;
            exitg5 = TRUE;
          } else {
            guard11 = FALSE;
            if (c8_iter > 20.0) {
              c8_eps(chartInstance);
              c8_i_b = c8_snorm;
              c8_k_y = 2.2204460492503131E-16 * c8_i_b;
              if (c8_ztest0 <= c8_k_y) {
                guard3 = TRUE;
                exitg5 = TRUE;
              } else {
                guard11 = TRUE;
              }
            } else {
              guard11 = TRUE;
            }

            if (guard11 == TRUE) {
              c8_c_ii--;
              guard3 = FALSE;
              guard4 = FALSE;
            }
          }
        }
      }

      if (guard4 == TRUE) {
        guard3 = TRUE;
      }

      if (guard3 == TRUE) {
        c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_ii), 1, 3, 1, 0) - 1] = 0.0;
      }

      c8_k_a = c8_m;
      c8_j_c = c8_k_a;
      if (c8_b_q == c8_j_c - 1) {
        c8_kase = 4.0;
      } else {
        c8_qs = c8_m;
        c8_b_m = c8_m;
        c8_c_q = c8_b_q;
        c8_l_a = c8_b_m;
        c8_j_b = c8_c_q;
        c8_m_a = c8_l_a;
        c8_k_b = c8_j_b;
        if (c8_m_a < c8_k_b) {
          c8_b_overflow = FALSE;
        } else {
          c8_b_overflow = (c8_k_b < -2147483647);
        }

        if (c8_b_overflow) {
          c8_check_forloop_overflow_error(chartInstance, c8_b_overflow);
        }

        c8_d_ii = c8_b_m;
        guard2 = FALSE;
        exitg4 = FALSE;
        while ((exitg4 == FALSE) && (c8_d_ii >= c8_c_q)) {
          c8_b_ii = c8_d_ii;
          c8_qs = c8_b_ii;
          if (c8_b_ii == c8_b_q) {
            exitg4 = TRUE;
          } else {
            c8_test = 0.0;
            if (c8_b_ii < c8_m) {
              c8_test = c8_abs(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
                "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_ii), 1, 3, 1, 0)
                               - 1]);
            }

            c8_n_a = c8_b_q;
            c8_k_c = c8_n_a;
            if (c8_b_ii > c8_k_c + 1) {
              c8_o_a = c8_b_ii;
              c8_l_c = c8_o_a;
              c8_test += c8_abs(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
                "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c8_l_c - 1)), 1, 3,
                1, 0) - 1]);
            }

            c8_ztest = c8_abs(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                               (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_ii),
              1, 3, 1, 0) - 1]);
            c8_eps(chartInstance);
            c8_l_b = c8_test;
            c8_l_y = 2.2204460492503131E-16 * c8_l_b;
            if (c8_ztest <= c8_l_y) {
              guard2 = TRUE;
              exitg4 = TRUE;
            } else if (c8_ztest <= c8_tiny) {
              guard2 = TRUE;
              exitg4 = TRUE;
            } else {
              c8_d_ii--;
              guard2 = FALSE;
            }
          }
        }

        if (guard2 == TRUE) {
          c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_ii), 1, 3, 1, 0) - 1] = 0.0;
        }

        if (c8_qs == c8_b_q) {
          c8_kase = 3.0;
        } else if (c8_qs == c8_m) {
          c8_kase = 1.0;
        } else {
          c8_kase = 2.0;
          c8_b_q = c8_qs;
        }
      }

      c8_p_a = c8_b_q + 1;
      c8_b_q = c8_p_a;
      switch ((int32_T)_SFD_INTEGER_CHECK("", c8_kase)) {
       case 1:
        c8_q_a = c8_m;
        c8_m_c = c8_q_a;
        c8_f = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)(c8_m_c - 1)), 1, 3, 1, 0) - 1];
        c8_r_a = c8_m;
        c8_n_c = c8_r_a;
        c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c8_n_c - 1)), 1, 3, 1, 0) - 1] = 0.0;
        c8_s_a = c8_m - 1;
        c8_i175 = c8_s_a;
        c8_d_q = c8_b_q;
        c8_t_a = c8_i175;
        c8_m_b = c8_d_q;
        c8_u_a = c8_t_a;
        c8_n_b = c8_m_b;
        if (c8_u_a < c8_n_b) {
          c8_c_overflow = FALSE;
        } else {
          c8_c_overflow = (c8_n_b < -2147483647);
        }

        if (c8_c_overflow) {
          c8_check_forloop_overflow_error(chartInstance, c8_c_overflow);
        }

        for (c8_k = c8_i175; c8_k >= c8_d_q; c8_k--) {
          c8_b_k = c8_k;
          c8_t1 = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 3, 1, 0) - 1];
          c8_b_t1 = c8_t1;
          c8_b_f = c8_f;
          c8_b_eml_xrotg(chartInstance, &c8_b_t1, &c8_b_f, &c8_cs, &c8_sn);
          c8_t1 = c8_b_t1;
          c8_f = c8_b_f;
          c8_b_cs = c8_cs;
          c8_b_sn = c8_sn;
          c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_k), 1, 3, 1, 0) - 1] = c8_t1;
          if (c8_b_k > c8_b_q) {
            c8_v_a = c8_b_k - 1;
            c8_km1 = c8_v_a;
            c8_w_a = -c8_b_sn;
            c8_o_b = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c8_km1), 1, 3, 1, 0) - 1];
            c8_f = c8_w_a * c8_o_b;
            c8_x_a = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c8_km1), 1, 3, 1, 0) - 1];
            c8_p_b = c8_b_cs;
            c8_m_y = c8_x_a * c8_p_b;
            c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c8_km1), 1, 3, 1, 0) - 1] = c8_m_y;
          }
        }
        break;

       case 2:
        c8_y_a = c8_b_q - 1;
        c8_qm1 = c8_y_a;
        c8_f = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c8_qm1), 1, 3, 1, 0) - 1];
        c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_qm1), 1, 3, 1, 0) - 1] = 0.0;
        c8_e_q = c8_b_q;
        c8_c_m = c8_m;
        c8_ab_a = c8_e_q;
        c8_q_b = c8_c_m;
        c8_bb_a = c8_ab_a;
        c8_r_b = c8_q_b;
        if (c8_bb_a > c8_r_b) {
          c8_d_overflow = FALSE;
        } else {
          c8_d_overflow = (c8_r_b > 2147483646);
        }

        if (c8_d_overflow) {
          c8_check_forloop_overflow_error(chartInstance, c8_d_overflow);
        }

        for (c8_c_k = c8_e_q; c8_c_k <= c8_c_m; c8_c_k++) {
          c8_b_k = c8_c_k;
          c8_t1 = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 3, 1, 0) - 1];
          c8_c_t1 = c8_t1;
          c8_unusedU0 = c8_f;
          c8_b_eml_xrotg(chartInstance, &c8_c_t1, &c8_unusedU0, &c8_c_cs,
                         &c8_c_sn);
          c8_t1 = c8_c_t1;
          c8_b_cs = c8_c_cs;
          c8_b_sn = c8_c_sn;
          c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_k), 1, 3, 1, 0) - 1] = c8_t1;
          c8_cb_a = -c8_b_sn;
          c8_s_b = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 3, 1, 0) - 1];
          c8_f = c8_cb_a * c8_s_b;
          c8_db_a = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 3, 1, 0) - 1];
          c8_t_b = c8_b_cs;
          c8_n_y = c8_db_a * c8_t_b;
          c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_k), 1, 3, 1, 0) - 1] = c8_n_y;
        }
        break;

       case 3:
        c8_eb_a = c8_m - 1;
        c8_mm1 = c8_eb_a;
        c8_d13 = c8_abs(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_m), 1, 3, 1, 0) - 1]);
        c8_d14 = c8_abs(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_mm1), 1, 3, 1, 0) - 1]);
        c8_d15 = c8_abs(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_mm1), 1, 3, 1, 0) - 1]);
        c8_d16 = c8_abs(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 3, 1, 0) - 1]);
        c8_d17 = c8_abs(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 3, 1, 0) - 1]);
        c8_c_varargin_1[0] = c8_d13;
        c8_c_varargin_1[1] = c8_d14;
        c8_c_varargin_1[2] = c8_d15;
        c8_c_varargin_1[3] = c8_d16;
        c8_c_varargin_1[4] = c8_d17;
        c8_ixstart = 1;
        c8_mtmp = c8_c_varargin_1[0];
        c8_g_x = c8_mtmp;
        c8_u_b = muDoubleScalarIsNaN(c8_g_x);
        if (c8_u_b) {
          c8_ix = 2;
          exitg2 = FALSE;
          while ((exitg2 == FALSE) && (c8_ix < 6)) {
            c8_b_ix = c8_ix;
            c8_ixstart = c8_b_ix;
            c8_h_x = c8_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c8_b_ix), 1, 5, 1, 0) - 1];
            c8_v_b = muDoubleScalarIsNaN(c8_h_x);
            if (!c8_v_b) {
              c8_mtmp = c8_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c8_b_ix), 1, 5, 1, 0) - 1];
              exitg2 = TRUE;
            } else {
              c8_ix++;
            }
          }
        }

        if (c8_ixstart < 5) {
          c8_fb_a = c8_ixstart;
          c8_i176 = c8_fb_a;
          c8_e_overflow = FALSE;
          if (c8_e_overflow) {
            c8_check_forloop_overflow_error(chartInstance, c8_e_overflow);
          }

          for (c8_c_ix = c8_i176 + 1; c8_c_ix < 6; c8_c_ix++) {
            c8_b_ix = c8_c_ix;
            c8_gb_a = c8_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c8_b_ix), 1, 5, 1, 0) - 1];
            c8_w_b = c8_mtmp;
            c8_p = (c8_gb_a > c8_w_b);
            if (c8_p) {
              c8_mtmp = c8_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c8_b_ix), 1, 5, 1, 0) - 1];
            }
          }
        }

        c8_b_mtmp = c8_mtmp;
        c8_scale = c8_b_mtmp;
        c8_sm = c8_eml_div(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_m), 1, 3, 1, 0) - 1],
                           c8_scale);
        c8_smm1 = c8_eml_div(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_mm1), 1,
          3, 1, 0) - 1], c8_scale);
        c8_emm1 = c8_eml_div(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_mm1), 1,
          3, 1, 0) - 1], c8_scale);
        c8_sqds = c8_eml_div(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1,
          3, 1, 0) - 1], c8_scale);
        c8_eqds = c8_eml_div(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1,
          3, 1, 0) - 1], c8_scale);
        c8_hb_a = c8_smm1 + c8_sm;
        c8_x_b = c8_smm1 - c8_sm;
        c8_o_y = c8_hb_a * c8_x_b;
        c8_ib_a = c8_emm1;
        c8_y_b = c8_emm1;
        c8_p_y = c8_ib_a * c8_y_b;
        c8_ab_b = c8_eml_div(chartInstance, c8_o_y + c8_p_y, 2.0);
        c8_jb_a = c8_sm;
        c8_bb_b = c8_emm1;
        c8_o_c = c8_jb_a * c8_bb_b;
        c8_kb_a = c8_o_c;
        c8_cb_b = c8_o_c;
        c8_o_c = c8_kb_a * c8_cb_b;
        c8_shift = 0.0;
        guard1 = FALSE;
        if (c8_ab_b != 0.0) {
          guard1 = TRUE;
        } else {
          if (c8_o_c != 0.0) {
            guard1 = TRUE;
          }
        }

        if (guard1 == TRUE) {
          c8_lb_a = c8_ab_b;
          c8_db_b = c8_ab_b;
          c8_q_y = c8_lb_a * c8_db_b;
          c8_shift = c8_q_y + c8_o_c;
          c8_b_sqrt(chartInstance, &c8_shift);
          if (c8_ab_b < 0.0) {
            c8_shift = -c8_shift;
          }

          c8_shift = c8_eml_div(chartInstance, c8_o_c, c8_ab_b + c8_shift);
        }

        c8_mb_a = c8_sqds + c8_sm;
        c8_eb_b = c8_sqds - c8_sm;
        c8_r_y = c8_mb_a * c8_eb_b;
        c8_f = c8_r_y + c8_shift;
        c8_nb_a = c8_sqds;
        c8_fb_b = c8_eqds;
        c8_g = c8_nb_a * c8_fb_b;
        c8_f_q = c8_b_q;
        c8_b_mm1 = c8_mm1;
        c8_ob_a = c8_f_q;
        c8_gb_b = c8_b_mm1;
        c8_pb_a = c8_ob_a;
        c8_hb_b = c8_gb_b;
        if (c8_pb_a > c8_hb_b) {
          c8_f_overflow = FALSE;
        } else {
          c8_f_overflow = (c8_hb_b > 2147483646);
        }

        if (c8_f_overflow) {
          c8_check_forloop_overflow_error(chartInstance, c8_f_overflow);
        }

        for (c8_d_k = c8_f_q; c8_d_k <= c8_b_mm1; c8_d_k++) {
          c8_b_k = c8_d_k;
          c8_qb_a = c8_b_k;
          c8_km1 = c8_qb_a;
          c8_rb_a = c8_b_k + 1;
          c8_kp1 = c8_rb_a;
          c8_c_f = c8_f;
          c8_unusedU1 = c8_g;
          c8_b_eml_xrotg(chartInstance, &c8_c_f, &c8_unusedU1, &c8_d_cs,
                         &c8_d_sn);
          c8_f = c8_c_f;
          c8_b_cs = c8_d_cs;
          c8_b_sn = c8_d_sn;
          if (c8_b_k > c8_b_q) {
            c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)(c8_km1 - 1)), 1, 3, 1, 0) - 1] = c8_f;
          }

          c8_sb_a = c8_b_cs;
          c8_ib_b = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 3, 1, 0) - 1];
          c8_s_y = c8_sb_a * c8_ib_b;
          c8_tb_a = c8_b_sn;
          c8_jb_b = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 3, 1, 0) - 1];
          c8_t_y = c8_tb_a * c8_jb_b;
          c8_f = c8_s_y + c8_t_y;
          c8_ub_a = c8_b_cs;
          c8_kb_b = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 3, 1, 0) - 1];
          c8_u_y = c8_ub_a * c8_kb_b;
          c8_vb_a = c8_b_sn;
          c8_lb_b = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 3, 1, 0) - 1];
          c8_v_y = c8_vb_a * c8_lb_b;
          c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_k), 1, 3, 1, 0) - 1] = c8_u_y - c8_v_y;
          c8_wb_a = c8_b_sn;
          c8_mb_b = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_kp1), 1, 3, 1, 0) - 1];
          c8_g = c8_wb_a * c8_mb_b;
          c8_xb_a = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_kp1), 1, 3, 1, 0) - 1];
          c8_nb_b = c8_b_cs;
          c8_w_y = c8_xb_a * c8_nb_b;
          c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_kp1), 1, 3, 1, 0) - 1] = c8_w_y;
          c8_d_f = c8_f;
          c8_unusedU2 = c8_g;
          c8_b_eml_xrotg(chartInstance, &c8_d_f, &c8_unusedU2, &c8_e_cs,
                         &c8_e_sn);
          c8_f = c8_d_f;
          c8_b_cs = c8_e_cs;
          c8_b_sn = c8_e_sn;
          c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_k), 1, 3, 1, 0) - 1] = c8_f;
          c8_yb_a = c8_b_cs;
          c8_ob_b = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 3, 1, 0) - 1];
          c8_x_y = c8_yb_a * c8_ob_b;
          c8_ac_a = c8_b_sn;
          c8_pb_b = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_kp1), 1, 3, 1, 0) - 1];
          c8_y_y = c8_ac_a * c8_pb_b;
          c8_f = c8_x_y + c8_y_y;
          c8_bc_a = -c8_b_sn;
          c8_qb_b = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 3, 1, 0) - 1];
          c8_ab_y = c8_bc_a * c8_qb_b;
          c8_cc_a = c8_b_cs;
          c8_rb_b = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_kp1), 1, 3, 1, 0) - 1];
          c8_bb_y = c8_cc_a * c8_rb_b;
          c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_kp1), 1, 3, 1, 0) - 1] = c8_ab_y + c8_bb_y;
          c8_dc_a = c8_b_sn;
          c8_sb_b = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_kp1), 1, 3, 1, 0) - 1];
          c8_g = c8_dc_a * c8_sb_b;
          c8_ec_a = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_kp1), 1, 3, 1, 0) - 1];
          c8_tb_b = c8_b_cs;
          c8_cb_y = c8_ec_a * c8_tb_b;
          c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_kp1), 1, 3, 1, 0) - 1] = c8_cb_y;
        }

        c8_fc_a = c8_m;
        c8_p_c = c8_fc_a;
        c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c8_p_c - 1)), 1, 3, 1, 0) - 1] = c8_f;
        c8_iter++;
        break;

       default:
        if (c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c8_b_q), 1, 3, 1, 0) - 1] < 0.0) {
          c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_q), 1, 3, 1, 0) - 1] =
            -c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_q), 1, 3, 1, 0) - 1];
        }

        c8_gc_a = c8_b_q + 1;
        c8_qp1 = c8_gc_a;
        exitg3 = FALSE;
        while ((exitg3 == FALSE) && (c8_b_q < 3)) {
          if (c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c8_b_q), 1, 3, 1, 0) - 1] <
              c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c8_qp1), 1, 3, 1, 0) - 1]) {
            c8_rt = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 3, 1, 0) - 1];
            c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c8_b_q), 1, 3, 1, 0) - 1] =
              c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c8_qp1), 1, 3, 1, 0) - 1];
            c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c8_qp1), 1, 3, 1, 0) - 1] = c8_rt;
            c8_b_q = c8_qp1;
            c8_ic_a = c8_b_q + 1;
            c8_qp1 = c8_ic_a;
          } else {
            exitg3 = TRUE;
          }
        }

        c8_iter = 0.0;
        c8_hc_a = c8_m - 1;
        c8_m = c8_hc_a;
        break;
      }
    }
  }

  for (c8_e_k = 1; c8_e_k < 3; c8_e_k++) {
    c8_b_k = c8_e_k;
    c8_S[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c8_b_k), 1, 2, 1, 0) - 1] = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 3, 1, 0) - 1];
  }
}

static real_T c8_c_eml_xnrm2(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_x[6])
{
  real_T c8_y;
  real_T c8_scale;
  int32_T c8_k;
  int32_T c8_b_k;
  real_T c8_b_x;
  real_T c8_c_x;
  real_T c8_absxk;
  real_T c8_t;
  c8_y = 0.0;
  c8_realmin(chartInstance);
  c8_scale = 2.2250738585072014E-308;
  for (c8_k = 1; c8_k < 3; c8_k++) {
    c8_b_k = c8_k;
    c8_b_x = c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c8_b_k), 1, 6, 1, 0) - 1];
    c8_c_x = c8_b_x;
    c8_absxk = muDoubleScalarAbs(c8_c_x);
    if (c8_absxk > c8_scale) {
      c8_t = c8_scale / c8_absxk;
      c8_y = 1.0 + c8_y * c8_t * c8_t;
      c8_scale = c8_absxk;
    } else {
      c8_t = c8_absxk / c8_scale;
      c8_y += c8_t * c8_t;
    }
  }

  return c8_scale * muDoubleScalarSqrt(c8_y);
}

static void c8_e_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[6], real_T c8_b_x[6])
{
  int32_T c8_i177;
  for (c8_i177 = 0; c8_i177 < 6; c8_i177++) {
    c8_b_x[c8_i177] = c8_x[c8_i177];
  }

  c8_l_eml_xscal(chartInstance, c8_b_a, c8_b_x);
}

static real_T c8_c_eml_xdotc(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_x[6], real_T c8_y[6], int32_T c8_iy0)
{
  real_T c8_d;
  int32_T c8_b_iy0;
  int32_T c8_c_iy0;
  int32_T c8_d_iy0;
  int32_T c8_e_iy0;
  int32_T c8_ix;
  int32_T c8_iy;
  int32_T c8_k;
  int32_T c8_b_a;
  int32_T c8_c_a;
  c8_b_iy0 = c8_iy0;
  c8_c_iy0 = c8_b_iy0;
  c8_d_iy0 = c8_c_iy0;
  c8_e_iy0 = c8_d_iy0;
  c8_d = 0.0;
  c8_ix = 1;
  c8_iy = c8_e_iy0;
  for (c8_k = 1; c8_k < 3; c8_k++) {
    c8_d += c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c8_ix), 1, 6, 1, 0) - 1] * c8_y[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_iy), 1, 6, 1, 0) - 1];
    c8_b_a = c8_ix + 1;
    c8_ix = c8_b_a;
    c8_c_a = c8_iy + 1;
    c8_iy = c8_c_a;
  }

  return c8_d;
}

static void c8_e_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_y[6], int32_T c8_iy0, real_T c8_b_y[6])
{
  int32_T c8_i178;
  for (c8_i178 = 0; c8_i178 < 6; c8_i178++) {
    c8_b_y[c8_i178] = c8_y[c8_i178];
  }

  c8_m_eml_xaxpy(chartInstance, c8_b_a, c8_b_y, c8_iy0);
}

static real_T c8_d_eml_xnrm2(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_x[3])
{
  real_T c8_y;
  real_T c8_scale;
  int32_T c8_k;
  int32_T c8_b_k;
  real_T c8_b_x;
  real_T c8_c_x;
  real_T c8_absxk;
  real_T c8_t;
  c8_y = 0.0;
  c8_realmin(chartInstance);
  c8_scale = 2.2250738585072014E-308;
  for (c8_k = 2; c8_k < 4; c8_k++) {
    c8_b_k = c8_k;
    c8_b_x = c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c8_b_k), 1, 3, 1, 0) - 1];
    c8_c_x = c8_b_x;
    c8_absxk = muDoubleScalarAbs(c8_c_x);
    if (c8_absxk > c8_scale) {
      c8_t = c8_scale / c8_absxk;
      c8_y = 1.0 + c8_y * c8_t * c8_t;
      c8_scale = c8_absxk;
    } else {
      c8_t = c8_absxk / c8_scale;
      c8_y += c8_t * c8_t;
    }
  }

  return c8_scale * muDoubleScalarSqrt(c8_y);
}

static void c8_f_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[3], real_T c8_b_x[3])
{
  int32_T c8_i179;
  for (c8_i179 = 0; c8_i179 < 3; c8_i179++) {
    c8_b_x[c8_i179] = c8_x[c8_i179];
  }

  c8_m_eml_xscal(chartInstance, c8_b_a, c8_b_x);
}

static void c8_f_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[6], int32_T c8_ix0, real_T c8_y[2], real_T c8_b_y[2])
{
  int32_T c8_i180;
  int32_T c8_i181;
  real_T c8_b_x[6];
  for (c8_i180 = 0; c8_i180 < 2; c8_i180++) {
    c8_b_y[c8_i180] = c8_y[c8_i180];
  }

  for (c8_i181 = 0; c8_i181 < 6; c8_i181++) {
    c8_b_x[c8_i181] = c8_x[c8_i181];
  }

  c8_n_eml_xaxpy(chartInstance, c8_b_a, c8_b_x, c8_ix0, c8_b_y);
}

static void c8_g_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[2], real_T c8_y[6], int32_T c8_iy0, real_T c8_b_y[6])
{
  int32_T c8_i182;
  int32_T c8_i183;
  real_T c8_b_x[2];
  for (c8_i182 = 0; c8_i182 < 6; c8_i182++) {
    c8_b_y[c8_i182] = c8_y[c8_i182];
  }

  for (c8_i183 = 0; c8_i183 < 2; c8_i183++) {
    c8_b_x[c8_i183] = c8_x[c8_i183];
  }

  c8_o_eml_xaxpy(chartInstance, c8_b_a, c8_b_x, c8_b_y, c8_iy0);
}

static real_T c8_b_mpower(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a)
{
  real_T c8_c_a;
  real_T c8_d_a;
  real_T c8_ak;
  real_T c8_e_a;
  real_T c8_f_a;
  real_T c8_b;
  c8_c_a = c8_b_a;
  c8_d_a = c8_c_a;
  c8_c_eml_scalar_eg(chartInstance);
  c8_ak = c8_d_a;
  c8_e_a = c8_ak;
  c8_c_eml_scalar_eg(chartInstance);
  c8_f_a = c8_e_a;
  c8_b = c8_e_a;
  return c8_f_a * c8_b;
}

static void c8_b_pinv(SFc8_CusakisME4901InstanceStruct *chartInstance, real_T
                      c8_A[4], real_T c8_X[4])
{
  int32_T c8_i184;
  int32_T c8_k;
  int32_T c8_b_k;
  real_T c8_x;
  real_T c8_b_x;
  boolean_T c8_b;
  boolean_T c8_b4;
  real_T c8_c_x;
  boolean_T c8_b_b;
  boolean_T c8_b5;
  boolean_T c8_c_b;
  int32_T c8_i185;
  real_T c8_b_A[4];
  real_T c8_V[4];
  real_T c8_s[2];
  real_T c8_U[4];
  int32_T c8_i186;
  real_T c8_S[4];
  int32_T c8_c_k;
  real_T c8_d_k;
  real_T c8_d_b;
  real_T c8_y;
  real_T c8_b_a;
  real_T c8_tol;
  int32_T c8_r;
  int32_T c8_e_k;
  int32_T c8_f_k;
  int32_T c8_c_a;
  int32_T c8_vcol;
  int32_T c8_b_r;
  int32_T c8_e_b;
  int32_T c8_f_b;
  boolean_T c8_overflow;
  int32_T c8_j;
  int32_T c8_b_j;
  real_T c8_b_y;
  real_T c8_z;
  int32_T c8_d_a;
  int32_T c8_i187;
  real_T c8_b_V[4];
  int32_T c8_i188;
  real_T c8_b_U[4];
  boolean_T exitg1;
  for (c8_i184 = 0; c8_i184 < 4; c8_i184++) {
    c8_X[c8_i184] = 0.0;
  }

  for (c8_k = 1; c8_k < 5; c8_k++) {
    c8_b_k = c8_k;
    c8_x = c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c8_b_k), 1, 4, 1, 0) - 1];
    c8_b_x = c8_x;
    c8_b = muDoubleScalarIsInf(c8_b_x);
    c8_b4 = !c8_b;
    c8_c_x = c8_x;
    c8_b_b = muDoubleScalarIsNaN(c8_c_x);
    c8_b5 = !c8_b_b;
    c8_c_b = (c8_b4 && c8_b5);
    if (!c8_c_b) {
      c8_c_eml_error(chartInstance);
    }
  }

  for (c8_i185 = 0; c8_i185 < 4; c8_i185++) {
    c8_b_A[c8_i185] = c8_A[c8_i185];
  }

  c8_b_eml_xgesvd(chartInstance, c8_b_A, c8_U, c8_s, c8_V);
  for (c8_i186 = 0; c8_i186 < 4; c8_i186++) {
    c8_S[c8_i186] = 0.0;
  }

  for (c8_c_k = 0; c8_c_k < 2; c8_c_k++) {
    c8_d_k = 1.0 + (real_T)c8_c_k;
    c8_S[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", c8_d_k), 1, 2, 1, 0) + (((int32_T)(real_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              c8_d_k), 1, 2, 2, 0) - 1) << 1)) - 1] = c8_s[(int32_T)(real_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c8_d_k), 1,
      2, 1, 0) - 1];
  }

  c8_eps(chartInstance);
  c8_d_b = c8_S[0];
  c8_y = 2.0 * c8_d_b;
  c8_b_a = c8_y;
  c8_tol = c8_b_a * 2.2204460492503131E-16;
  c8_r = 0;
  c8_e_k = 1;
  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c8_e_k < 3)) {
    c8_f_k = c8_e_k;
    if (!(c8_S[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_f_k), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_f_k), 1, 2, 2, 0) - 1) <<
           1)) - 1] > c8_tol)) {
      exitg1 = TRUE;
    } else {
      c8_c_a = c8_r + 1;
      c8_r = c8_c_a;
      c8_e_k++;
    }
  }

  if (c8_r > 0) {
    c8_vcol = 1;
    c8_b_r = c8_r;
    c8_e_b = c8_b_r;
    c8_f_b = c8_e_b;
    if (1 > c8_f_b) {
      c8_overflow = FALSE;
    } else {
      c8_overflow = (c8_f_b > 2147483646);
    }

    if (c8_overflow) {
      c8_check_forloop_overflow_error(chartInstance, c8_overflow);
    }

    for (c8_j = 1; c8_j <= c8_b_r; c8_j++) {
      c8_b_j = c8_j;
      c8_b_y = c8_S[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c8_b_j), 1, 2, 1, 0) +
                     ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c8_b_j), 1, 2, 2, 0) - 1) << 1)) - 1];
      c8_z = 1.0 / c8_b_y;
      c8_k_eml_xscal(chartInstance, c8_z, c8_V, c8_vcol);
      c8_d_a = c8_vcol + 2;
      c8_vcol = c8_d_a;
    }

    for (c8_i187 = 0; c8_i187 < 4; c8_i187++) {
      c8_b_V[c8_i187] = c8_V[c8_i187];
    }

    for (c8_i188 = 0; c8_i188 < 4; c8_i188++) {
      c8_b_U[c8_i188] = c8_U[c8_i188];
    }

    c8_d_eml_xgemm(chartInstance, c8_r, c8_b_V, c8_b_U, c8_X);
  }
}

static void c8_b_eml_xgesvd(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_A[4], real_T c8_U[4], real_T c8_S[2], real_T c8_V[4])
{
  int32_T c8_i189;
  real_T c8_b_A[4];
  int32_T c8_i190;
  int32_T c8_i191;
  real_T c8_Vf[4];
  int32_T c8_i192;
  real_T c8_c_A[4];
  real_T c8_nrm;
  real_T c8_absx;
  real_T c8_d;
  real_T c8_y;
  real_T c8_s[2];
  real_T c8_d18;
  int32_T c8_i193;
  real_T c8_d_A[4];
  int32_T c8_i194;
  real_T c8_e_A[4];
  real_T c8_t;
  int32_T c8_ii;
  int32_T c8_b_ii;
  int32_T c8_m;
  real_T c8_e[2];
  int32_T c8_c_ii;
  int32_T c8_i195;
  real_T c8_b_U[4];
  int32_T c8_i196;
  real_T c8_c_U[4];
  int32_T c8_d_ii;
  int32_T c8_e_ii;
  int32_T c8_q;
  int32_T c8_b_q;
  int32_T c8_b_a;
  int32_T c8_qp1;
  int32_T c8_b;
  int32_T c8_pmq;
  int32_T c8_c_a;
  int32_T c8_c;
  int32_T c8_b_b;
  int32_T c8_b_c;
  int32_T c8_d_a;
  int32_T c8_c_b;
  int32_T c8_qp1q;
  int32_T c8_b_qp1;
  boolean_T c8_overflow;
  int32_T c8_jj;
  int32_T c8_b_jj;
  int32_T c8_e_a;
  int32_T c8_c_c;
  int32_T c8_d_b;
  int32_T c8_d_c;
  int32_T c8_f_a;
  int32_T c8_e_b;
  int32_T c8_qp1jj;
  int32_T c8_i197;
  real_T c8_b_Vf[4];
  int32_T c8_i198;
  real_T c8_c_Vf[4];
  int32_T c8_f_ii;
  int32_T c8_c_q;
  real_T c8_rt;
  real_T c8_r;
  int32_T c8_g_a;
  int32_T c8_e_c;
  int32_T c8_f_b;
  int32_T c8_f_c;
  int32_T c8_g_b;
  int32_T c8_colq;
  int32_T c8_h_a;
  int32_T c8_g_c;
  int32_T c8_i_a;
  int32_T c8_h_c;
  real_T c8_j_a;
  real_T c8_h_b;
  real_T c8_b_y;
  int32_T c8_i_b;
  int32_T c8_i_c;
  int32_T c8_j_b;
  int32_T c8_colqp1;
  real_T c8_iter;
  real_T c8_tiny;
  real_T c8_snorm;
  int32_T c8_g_ii;
  real_T c8_varargin_1;
  real_T c8_varargin_2;
  real_T c8_b_varargin_2;
  real_T c8_varargin_3;
  real_T c8_x;
  real_T c8_c_y;
  real_T c8_b_x;
  real_T c8_d_y;
  real_T c8_xk;
  real_T c8_yk;
  real_T c8_c_x;
  real_T c8_e_y;
  real_T c8_maxval;
  real_T c8_b_varargin_1;
  real_T c8_c_varargin_2;
  real_T c8_d_varargin_2;
  real_T c8_b_varargin_3;
  real_T c8_d_x;
  real_T c8_f_y;
  real_T c8_e_x;
  real_T c8_g_y;
  real_T c8_b_xk;
  real_T c8_b_yk;
  real_T c8_f_x;
  real_T c8_h_y;
  int32_T c8_k_a;
  int32_T c8_l_a;
  int32_T c8_i199;
  boolean_T c8_b_overflow;
  int32_T c8_h_ii;
  int32_T c8_m_a;
  int32_T c8_j_c;
  real_T c8_test0;
  real_T c8_ztest0;
  real_T c8_k_b;
  real_T c8_i_y;
  real_T c8_l_b;
  real_T c8_j_y;
  int32_T c8_n_a;
  int32_T c8_k_c;
  real_T c8_kase;
  int32_T c8_qs;
  int32_T c8_b_m;
  int32_T c8_d_q;
  int32_T c8_o_a;
  int32_T c8_m_b;
  int32_T c8_p_a;
  int32_T c8_n_b;
  boolean_T c8_c_overflow;
  int32_T c8_i_ii;
  real_T c8_test;
  int32_T c8_q_a;
  int32_T c8_l_c;
  int32_T c8_r_a;
  int32_T c8_m_c;
  real_T c8_ztest;
  real_T c8_o_b;
  real_T c8_k_y;
  int32_T c8_s_a;
  int32_T c8_t_a;
  int32_T c8_n_c;
  real_T c8_f;
  int32_T c8_u_a;
  int32_T c8_o_c;
  int32_T c8_v_a;
  int32_T c8_i200;
  int32_T c8_e_q;
  int32_T c8_w_a;
  int32_T c8_p_b;
  int32_T c8_x_a;
  int32_T c8_q_b;
  boolean_T c8_d_overflow;
  int32_T c8_k;
  int32_T c8_b_k;
  real_T c8_t1;
  real_T c8_b_t1;
  real_T c8_b_f;
  real_T c8_sn;
  real_T c8_cs;
  real_T c8_b_cs;
  real_T c8_b_sn;
  int32_T c8_y_a;
  int32_T c8_km1;
  real_T c8_ab_a;
  real_T c8_r_b;
  real_T c8_bb_a;
  real_T c8_s_b;
  real_T c8_l_y;
  int32_T c8_cb_a;
  int32_T c8_p_c;
  int32_T c8_t_b;
  int32_T c8_q_c;
  int32_T c8_u_b;
  int32_T c8_colk;
  int32_T c8_db_a;
  int32_T c8_r_c;
  int32_T c8_v_b;
  int32_T c8_s_c;
  int32_T c8_w_b;
  int32_T c8_colm;
  int32_T c8_eb_a;
  int32_T c8_qm1;
  int32_T c8_f_q;
  int32_T c8_c_m;
  int32_T c8_fb_a;
  int32_T c8_x_b;
  int32_T c8_gb_a;
  int32_T c8_y_b;
  boolean_T c8_e_overflow;
  int32_T c8_c_k;
  real_T c8_c_t1;
  real_T c8_unusedU0;
  real_T c8_c_sn;
  real_T c8_c_cs;
  real_T c8_hb_a;
  real_T c8_ab_b;
  real_T c8_ib_a;
  real_T c8_bb_b;
  real_T c8_m_y;
  int32_T c8_jb_a;
  int32_T c8_t_c;
  int32_T c8_cb_b;
  int32_T c8_u_c;
  int32_T c8_db_b;
  int32_T c8_kb_a;
  int32_T c8_v_c;
  int32_T c8_eb_b;
  int32_T c8_w_c;
  int32_T c8_fb_b;
  int32_T c8_colqm1;
  int32_T c8_lb_a;
  int32_T c8_mm1;
  real_T c8_d19;
  real_T c8_d20;
  real_T c8_d21;
  real_T c8_d22;
  real_T c8_d23;
  real_T c8_c_varargin_1[5];
  int32_T c8_ixstart;
  real_T c8_mtmp;
  real_T c8_g_x;
  boolean_T c8_gb_b;
  int32_T c8_ix;
  int32_T c8_b_ix;
  real_T c8_h_x;
  boolean_T c8_hb_b;
  int32_T c8_mb_a;
  int32_T c8_i201;
  boolean_T c8_f_overflow;
  int32_T c8_c_ix;
  real_T c8_nb_a;
  real_T c8_ib_b;
  boolean_T c8_p;
  real_T c8_b_mtmp;
  real_T c8_scale;
  real_T c8_sm;
  real_T c8_smm1;
  real_T c8_emm1;
  real_T c8_sqds;
  real_T c8_eqds;
  real_T c8_ob_a;
  real_T c8_jb_b;
  real_T c8_n_y;
  real_T c8_pb_a;
  real_T c8_kb_b;
  real_T c8_o_y;
  real_T c8_lb_b;
  real_T c8_qb_a;
  real_T c8_mb_b;
  real_T c8_x_c;
  real_T c8_rb_a;
  real_T c8_nb_b;
  real_T c8_shift;
  real_T c8_sb_a;
  real_T c8_ob_b;
  real_T c8_p_y;
  real_T c8_tb_a;
  real_T c8_pb_b;
  real_T c8_q_y;
  real_T c8_ub_a;
  real_T c8_qb_b;
  real_T c8_g;
  int32_T c8_g_q;
  int32_T c8_b_mm1;
  int32_T c8_vb_a;
  int32_T c8_rb_b;
  int32_T c8_wb_a;
  int32_T c8_sb_b;
  boolean_T c8_g_overflow;
  int32_T c8_d_k;
  int32_T c8_xb_a;
  int32_T c8_yb_a;
  int32_T c8_kp1;
  real_T c8_c_f;
  real_T c8_unusedU1;
  real_T c8_d_sn;
  real_T c8_d_cs;
  real_T c8_ac_a;
  real_T c8_tb_b;
  real_T c8_r_y;
  real_T c8_bc_a;
  real_T c8_ub_b;
  real_T c8_s_y;
  real_T c8_cc_a;
  real_T c8_vb_b;
  real_T c8_t_y;
  real_T c8_dc_a;
  real_T c8_wb_b;
  real_T c8_u_y;
  real_T c8_ec_a;
  real_T c8_xb_b;
  real_T c8_fc_a;
  real_T c8_yb_b;
  real_T c8_v_y;
  int32_T c8_gc_a;
  int32_T c8_y_c;
  int32_T c8_ac_b;
  int32_T c8_ab_c;
  int32_T c8_bc_b;
  int32_T c8_cc_b;
  int32_T c8_bb_c;
  int32_T c8_dc_b;
  int32_T c8_colkp1;
  real_T c8_d_f;
  real_T c8_unusedU2;
  real_T c8_e_sn;
  real_T c8_e_cs;
  real_T c8_hc_a;
  real_T c8_ec_b;
  real_T c8_w_y;
  real_T c8_ic_a;
  real_T c8_fc_b;
  real_T c8_x_y;
  real_T c8_jc_a;
  real_T c8_gc_b;
  real_T c8_y_y;
  real_T c8_kc_a;
  real_T c8_hc_b;
  real_T c8_ab_y;
  real_T c8_lc_a;
  real_T c8_ic_b;
  real_T c8_mc_a;
  real_T c8_jc_b;
  real_T c8_bb_y;
  int32_T c8_nc_a;
  int32_T c8_cb_c;
  int32_T c8_kc_b;
  int32_T c8_db_c;
  int32_T c8_lc_b;
  int32_T c8_mc_b;
  int32_T c8_eb_c;
  int32_T c8_nc_b;
  int32_T c8_oc_a;
  int32_T c8_fb_c;
  int32_T c8_e_k;
  int32_T c8_j;
  int32_T c8_b_j;
  int32_T c8_i;
  int32_T c8_b_i;
  int32_T c8_gb_c;
  int32_T c8_pc_a;
  int32_T c8_hb_c;
  int32_T c8_oc_b;
  int32_T c8_pc_b;
  int32_T c8_qc_a;
  int32_T c8_rc_a;
  int32_T c8_ib_c;
  int32_T c8_sc_a;
  int32_T c8_jb_c;
  int32_T c8_qc_b;
  int32_T c8_rc_b;
  int32_T c8_kb_c;
  int32_T c8_sc_b;
  int32_T c8_tc_b;
  int32_T c8_lb_c;
  int32_T c8_tc_a;
  int32_T c8_mb_c;
  int32_T c8_uc_b;
  int32_T c8_vc_b;
  int32_T c8_nb_c;
  int32_T c8_wc_b;
  int32_T c8_xc_b;
  int32_T c8_uc_a;
  real_T c8_d24;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T exitg4;
  boolean_T exitg5;
  boolean_T guard11 = FALSE;
  for (c8_i189 = 0; c8_i189 < 4; c8_i189++) {
    c8_b_A[c8_i189] = c8_A[c8_i189];
  }

  c8_b_eml_scalar_eg(chartInstance);
  for (c8_i190 = 0; c8_i190 < 4; c8_i190++) {
    c8_U[c8_i190] = 0.0;
  }

  for (c8_i191 = 0; c8_i191 < 4; c8_i191++) {
    c8_Vf[c8_i191] = 0.0;
  }

  for (c8_i192 = 0; c8_i192 < 4; c8_i192++) {
    c8_c_A[c8_i192] = c8_b_A[c8_i192];
  }

  c8_nrm = c8_e_eml_xnrm2(chartInstance, c8_c_A);
  if (c8_nrm > 0.0) {
    c8_absx = c8_nrm;
    c8_d = c8_b_A[0];
    if (c8_d < 0.0) {
      c8_y = -c8_absx;
    } else {
      c8_y = c8_absx;
    }

    c8_s[0] = c8_y;
    c8_d18 = c8_eml_div(chartInstance, 1.0, c8_s[0]);
    c8_n_eml_xscal(chartInstance, c8_d18, c8_b_A);
    c8_b_A[0]++;
    c8_s[0] = -c8_s[0];
  } else {
    c8_s[0] = 0.0;
  }

  if (c8_s[0] != 0.0) {
    for (c8_i193 = 0; c8_i193 < 4; c8_i193++) {
      c8_d_A[c8_i193] = c8_b_A[c8_i193];
    }

    for (c8_i194 = 0; c8_i194 < 4; c8_i194++) {
      c8_e_A[c8_i194] = c8_b_A[c8_i194];
    }

    c8_t = c8_d_eml_xdotc(chartInstance, c8_d_A, c8_e_A);
    c8_t = -c8_eml_div(chartInstance, c8_t, c8_b_A[0]);
    c8_p_eml_xaxpy(chartInstance, c8_t, c8_b_A);
  }

  for (c8_ii = 1; c8_ii < 3; c8_ii++) {
    c8_b_ii = c8_ii;
    c8_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c8_b_ii), 1, 2, 1, 0) - 1] = c8_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_ii), 1, 2, 1, 0) - 1];
  }

  c8_m = 2;
  c8_s[1] = c8_b_A[3];
  c8_e[0] = c8_b_A[2];
  c8_e[1] = 0.0;
  for (c8_c_ii = 1; c8_c_ii < 3; c8_c_ii++) {
    c8_b_ii = c8_c_ii;
    c8_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c8_b_ii), 1, 2, 1, 0) + 1] = 0.0;
  }

  c8_U[3] = 1.0;
  if (c8_s[0] != 0.0) {
    for (c8_i195 = 0; c8_i195 < 4; c8_i195++) {
      c8_b_U[c8_i195] = c8_U[c8_i195];
    }

    for (c8_i196 = 0; c8_i196 < 4; c8_i196++) {
      c8_c_U[c8_i196] = c8_U[c8_i196];
    }

    c8_t = c8_d_eml_xdotc(chartInstance, c8_b_U, c8_c_U);
    c8_t = -c8_eml_div(chartInstance, c8_t, c8_U[0]);
    c8_p_eml_xaxpy(chartInstance, c8_t, c8_U);
    for (c8_d_ii = 1; c8_d_ii < 3; c8_d_ii++) {
      c8_b_ii = c8_d_ii;
      c8_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c8_b_ii), 1, 2, 1, 0) - 1] = -c8_U[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_ii), 1, 2, 1, 0) - 1];
    }

    c8_U[0]++;
  } else {
    for (c8_e_ii = 1; c8_e_ii < 3; c8_e_ii++) {
      c8_b_ii = c8_e_ii;
      c8_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c8_b_ii), 1, 2, 1, 0) - 1] = 0.0;
    }

    c8_U[0] = 1.0;
  }

  for (c8_q = 2; c8_q > 0; c8_q--) {
    c8_b_q = c8_q;
    if (c8_b_q <= 0) {
      if (c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_q), 1, 2, 1, 0) - 1] != 0.0) {
        c8_b_a = c8_b_q + 1;
        c8_qp1 = c8_b_a;
        c8_b = c8_b_q;
        c8_pmq = 2 - c8_b;
        c8_c_a = c8_b_q;
        c8_c = c8_c_a;
        c8_b_b = c8_c - 1;
        c8_b_c = c8_b_b << 1;
        c8_d_a = c8_qp1;
        c8_c_b = c8_b_c;
        c8_qp1q = c8_d_a + c8_c_b;
        c8_b_qp1 = c8_qp1;
        c8_overflow = FALSE;
        if (c8_overflow) {
          c8_check_forloop_overflow_error(chartInstance, c8_overflow);
        }

        for (c8_jj = c8_b_qp1; c8_jj < 3; c8_jj++) {
          c8_b_jj = c8_jj;
          c8_e_a = c8_b_jj;
          c8_c_c = c8_e_a;
          c8_d_b = c8_c_c - 1;
          c8_d_c = c8_d_b << 1;
          c8_f_a = c8_qp1;
          c8_e_b = c8_d_c;
          c8_qp1jj = c8_f_a + c8_e_b;
          for (c8_i197 = 0; c8_i197 < 4; c8_i197++) {
            c8_b_Vf[c8_i197] = c8_Vf[c8_i197];
          }

          for (c8_i198 = 0; c8_i198 < 4; c8_i198++) {
            c8_c_Vf[c8_i198] = c8_Vf[c8_i198];
          }

          c8_t = c8_b_eml_xdotc(chartInstance, c8_pmq, c8_b_Vf, c8_qp1q, c8_c_Vf,
                                c8_qp1jj);
          c8_t = -c8_eml_div(chartInstance, c8_t,
                             c8_Vf[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_qp1q), 1, 4, 1, 0) - 1]);
          c8_l_eml_xaxpy(chartInstance, c8_pmq, c8_t, c8_qp1q, c8_Vf, c8_qp1jj);
        }
      }
    }

    for (c8_f_ii = 1; c8_f_ii < 3; c8_f_ii++) {
      c8_b_ii = c8_f_ii;
      c8_Vf[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
               (real_T)c8_b_ii), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 2, 2, 0) - 1)
              << 1)) - 1] = 0.0;
    }

    c8_Vf[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c8_b_q), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 2, 2, 0) - 1) <<
            1)) - 1] = 1.0;
  }

  for (c8_c_q = 1; c8_c_q < 3; c8_c_q++) {
    c8_b_q = c8_c_q;
    if (c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_q), 1, 2, 1, 0) - 1] != 0.0) {
      c8_rt = c8_abs(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 2, 1, 0) - 1]);
      c8_r = c8_eml_div(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 2, 1, 0) - 1], c8_rt);
      c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c8_b_q), 1, 2, 1, 0) - 1] = c8_rt;
      if (c8_b_q < 2) {
        c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_q), 1, 2, 1, 0) - 1] = c8_eml_div(chartInstance,
          c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_q), 1, 2, 1, 0) - 1], c8_r);
      }

      if (c8_b_q <= 2) {
        c8_g_a = c8_b_q;
        c8_e_c = c8_g_a;
        c8_f_b = c8_e_c - 1;
        c8_f_c = c8_f_b << 1;
        c8_g_b = c8_f_c;
        c8_colq = c8_g_b;
        c8_k_eml_xscal(chartInstance, c8_r, c8_U, c8_colq + 1);
      }
    }

    if (c8_b_q < 2) {
      if (c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_q), 1, 2, 1, 0) - 1] != 0.0) {
        c8_rt = c8_abs(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 2, 1, 0) - 1]);
        c8_r = c8_eml_div(chartInstance, c8_rt, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK
                          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q),
                           1, 2, 1, 0) - 1]);
        c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_q), 1, 2, 1, 0) - 1] = c8_rt;
        c8_h_a = c8_b_q;
        c8_g_c = c8_h_a;
        c8_i_a = c8_b_q;
        c8_h_c = c8_i_a;
        c8_j_a = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c8_h_c + 1)), 1, 2, 1, 0) - 1];
        c8_h_b = c8_r;
        c8_b_y = c8_j_a * c8_h_b;
        c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c8_g_c + 1)), 1, 2, 1, 0) - 1] = c8_b_y;
        c8_i_b = c8_b_q;
        c8_i_c = c8_i_b << 1;
        c8_j_b = c8_i_c;
        c8_colqp1 = c8_j_b;
        c8_k_eml_xscal(chartInstance, c8_r, c8_Vf, c8_colqp1 + 1);
      }
    }
  }

  c8_iter = 0.0;
  c8_realmin(chartInstance);
  c8_eps(chartInstance);
  c8_tiny = c8_eml_div(chartInstance, 2.2250738585072014E-308,
                       2.2204460492503131E-16);
  c8_snorm = 0.0;
  for (c8_g_ii = 1; c8_g_ii < 3; c8_g_ii++) {
    c8_b_ii = c8_g_ii;
    c8_varargin_1 = c8_abs(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_ii), 1, 2, 1, 0) - 1]);
    c8_varargin_2 = c8_abs(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_ii), 1, 2, 1, 0) - 1]);
    c8_b_varargin_2 = c8_varargin_1;
    c8_varargin_3 = c8_varargin_2;
    c8_x = c8_b_varargin_2;
    c8_c_y = c8_varargin_3;
    c8_b_x = c8_x;
    c8_d_y = c8_c_y;
    c8_c_eml_scalar_eg(chartInstance);
    c8_xk = c8_b_x;
    c8_yk = c8_d_y;
    c8_c_x = c8_xk;
    c8_e_y = c8_yk;
    c8_c_eml_scalar_eg(chartInstance);
    c8_maxval = muDoubleScalarMax(c8_c_x, c8_e_y);
    c8_b_varargin_1 = c8_snorm;
    c8_c_varargin_2 = c8_maxval;
    c8_d_varargin_2 = c8_b_varargin_1;
    c8_b_varargin_3 = c8_c_varargin_2;
    c8_d_x = c8_d_varargin_2;
    c8_f_y = c8_b_varargin_3;
    c8_e_x = c8_d_x;
    c8_g_y = c8_f_y;
    c8_c_eml_scalar_eg(chartInstance);
    c8_b_xk = c8_e_x;
    c8_b_yk = c8_g_y;
    c8_f_x = c8_b_xk;
    c8_h_y = c8_b_yk;
    c8_c_eml_scalar_eg(chartInstance);
    c8_snorm = muDoubleScalarMax(c8_f_x, c8_h_y);
  }

  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c8_m > 0)) {
    if (c8_iter >= 75.0) {
      c8_d_eml_error(chartInstance);
      exitg1 = TRUE;
    } else {
      c8_k_a = c8_m - 1;
      c8_b_q = c8_k_a;
      c8_l_a = c8_m;
      c8_i199 = c8_l_a;
      c8_b_overflow = FALSE;
      if (c8_b_overflow) {
        c8_check_forloop_overflow_error(chartInstance, c8_b_overflow);
      }

      c8_h_ii = c8_i199 - 1;
      guard3 = FALSE;
      guard4 = FALSE;
      exitg5 = FALSE;
      while ((exitg5 == FALSE) && (c8_h_ii > -1)) {
        c8_b_ii = c8_h_ii;
        c8_b_q = c8_b_ii;
        if (c8_b_ii == 0) {
          exitg5 = TRUE;
        } else {
          c8_m_a = c8_b_ii;
          c8_j_c = c8_m_a;
          c8_test0 = c8_abs(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_ii), 1,
            2, 1, 0) - 1]) + c8_abs(chartInstance,
            c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                                      (real_T)(c8_j_c + 1)), 1, 2, 1, 0) - 1]);
          c8_ztest0 = c8_abs(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_ii),
            1, 2, 1, 0) - 1]);
          c8_eps(chartInstance);
          c8_k_b = c8_test0;
          c8_i_y = 2.2204460492503131E-16 * c8_k_b;
          if (c8_ztest0 <= c8_i_y) {
            guard4 = TRUE;
            exitg5 = TRUE;
          } else if (c8_ztest0 <= c8_tiny) {
            guard4 = TRUE;
            exitg5 = TRUE;
          } else {
            guard11 = FALSE;
            if (c8_iter > 20.0) {
              c8_eps(chartInstance);
              c8_l_b = c8_snorm;
              c8_j_y = 2.2204460492503131E-16 * c8_l_b;
              if (c8_ztest0 <= c8_j_y) {
                guard3 = TRUE;
                exitg5 = TRUE;
              } else {
                guard11 = TRUE;
              }
            } else {
              guard11 = TRUE;
            }

            if (guard11 == TRUE) {
              c8_h_ii--;
              guard3 = FALSE;
              guard4 = FALSE;
            }
          }
        }
      }

      if (guard4 == TRUE) {
        guard3 = TRUE;
      }

      if (guard3 == TRUE) {
        c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_ii), 1, 2, 1, 0) - 1] = 0.0;
      }

      c8_n_a = c8_m;
      c8_k_c = c8_n_a;
      if (c8_b_q == c8_k_c - 1) {
        c8_kase = 4.0;
      } else {
        c8_qs = c8_m;
        c8_b_m = c8_m;
        c8_d_q = c8_b_q;
        c8_o_a = c8_b_m;
        c8_m_b = c8_d_q;
        c8_p_a = c8_o_a;
        c8_n_b = c8_m_b;
        if (c8_p_a < c8_n_b) {
          c8_c_overflow = FALSE;
        } else {
          c8_c_overflow = (c8_n_b < -2147483647);
        }

        if (c8_c_overflow) {
          c8_check_forloop_overflow_error(chartInstance, c8_c_overflow);
        }

        c8_i_ii = c8_b_m;
        guard2 = FALSE;
        exitg4 = FALSE;
        while ((exitg4 == FALSE) && (c8_i_ii >= c8_d_q)) {
          c8_b_ii = c8_i_ii;
          c8_qs = c8_b_ii;
          if (c8_b_ii == c8_b_q) {
            exitg4 = TRUE;
          } else {
            c8_test = 0.0;
            if (c8_b_ii < c8_m) {
              c8_test = c8_abs(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
                "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_ii), 1, 2, 1, 0)
                               - 1]);
            }

            c8_q_a = c8_b_q;
            c8_l_c = c8_q_a;
            if (c8_b_ii > c8_l_c + 1) {
              c8_r_a = c8_b_ii;
              c8_m_c = c8_r_a;
              c8_test += c8_abs(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
                "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c8_m_c - 1)), 1, 2,
                1, 0) - 1]);
            }

            c8_ztest = c8_abs(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                               (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_ii),
              1, 2, 1, 0) - 1]);
            c8_eps(chartInstance);
            c8_o_b = c8_test;
            c8_k_y = 2.2204460492503131E-16 * c8_o_b;
            if (c8_ztest <= c8_k_y) {
              guard2 = TRUE;
              exitg4 = TRUE;
            } else if (c8_ztest <= c8_tiny) {
              guard2 = TRUE;
              exitg4 = TRUE;
            } else {
              c8_i_ii--;
              guard2 = FALSE;
            }
          }
        }

        if (guard2 == TRUE) {
          c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_ii), 1, 2, 1, 0) - 1] = 0.0;
        }

        if (c8_qs == c8_b_q) {
          c8_kase = 3.0;
        } else if (c8_qs == c8_m) {
          c8_kase = 1.0;
        } else {
          c8_kase = 2.0;
          c8_b_q = c8_qs;
        }
      }

      c8_s_a = c8_b_q + 1;
      c8_b_q = c8_s_a;
      switch ((int32_T)_SFD_INTEGER_CHECK("", c8_kase)) {
       case 1:
        c8_t_a = c8_m;
        c8_n_c = c8_t_a;
        c8_f = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)(c8_n_c - 1)), 1, 2, 1, 0) - 1];
        c8_u_a = c8_m;
        c8_o_c = c8_u_a;
        c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c8_o_c - 1)), 1, 2, 1, 0) - 1] = 0.0;
        c8_v_a = c8_m - 1;
        c8_i200 = c8_v_a;
        c8_e_q = c8_b_q;
        c8_w_a = c8_i200;
        c8_p_b = c8_e_q;
        c8_x_a = c8_w_a;
        c8_q_b = c8_p_b;
        if (c8_x_a < c8_q_b) {
          c8_d_overflow = FALSE;
        } else {
          c8_d_overflow = (c8_q_b < -2147483647);
        }

        if (c8_d_overflow) {
          c8_check_forloop_overflow_error(chartInstance, c8_d_overflow);
        }

        for (c8_k = c8_i200; c8_k >= c8_e_q; c8_k--) {
          c8_b_k = c8_k;
          c8_t1 = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 2, 1, 0) - 1];
          c8_b_t1 = c8_t1;
          c8_b_f = c8_f;
          c8_b_eml_xrotg(chartInstance, &c8_b_t1, &c8_b_f, &c8_cs, &c8_sn);
          c8_t1 = c8_b_t1;
          c8_f = c8_b_f;
          c8_b_cs = c8_cs;
          c8_b_sn = c8_sn;
          c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_k), 1, 2, 1, 0) - 1] = c8_t1;
          if (c8_b_k > c8_b_q) {
            c8_y_a = c8_b_k - 1;
            c8_km1 = c8_y_a;
            c8_ab_a = -c8_b_sn;
            c8_r_b = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c8_km1), 1, 2, 1, 0) - 1];
            c8_f = c8_ab_a * c8_r_b;
            c8_bb_a = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c8_km1), 1, 2, 1, 0) - 1];
            c8_s_b = c8_b_cs;
            c8_l_y = c8_bb_a * c8_s_b;
            c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c8_km1), 1, 2, 1, 0) - 1] = c8_l_y;
          }

          c8_cb_a = c8_b_k;
          c8_p_c = c8_cb_a;
          c8_t_b = c8_p_c - 1;
          c8_q_c = c8_t_b << 1;
          c8_u_b = c8_q_c;
          c8_colk = c8_u_b;
          c8_db_a = c8_m;
          c8_r_c = c8_db_a;
          c8_v_b = c8_r_c - 1;
          c8_s_c = c8_v_b << 1;
          c8_w_b = c8_s_c;
          c8_colm = c8_w_b;
          c8_c_eml_xrot(chartInstance, c8_Vf, c8_colk + 1, c8_colm + 1, c8_b_cs,
                        c8_b_sn);
        }
        break;

       case 2:
        c8_eb_a = c8_b_q - 1;
        c8_qm1 = c8_eb_a;
        c8_f = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c8_qm1), 1, 2, 1, 0) - 1];
        c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_qm1), 1, 2, 1, 0) - 1] = 0.0;
        c8_f_q = c8_b_q;
        c8_c_m = c8_m;
        c8_fb_a = c8_f_q;
        c8_x_b = c8_c_m;
        c8_gb_a = c8_fb_a;
        c8_y_b = c8_x_b;
        if (c8_gb_a > c8_y_b) {
          c8_e_overflow = FALSE;
        } else {
          c8_e_overflow = (c8_y_b > 2147483646);
        }

        if (c8_e_overflow) {
          c8_check_forloop_overflow_error(chartInstance, c8_e_overflow);
        }

        for (c8_c_k = c8_f_q; c8_c_k <= c8_c_m; c8_c_k++) {
          c8_b_k = c8_c_k;
          c8_t1 = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 2, 1, 0) - 1];
          c8_c_t1 = c8_t1;
          c8_unusedU0 = c8_f;
          c8_b_eml_xrotg(chartInstance, &c8_c_t1, &c8_unusedU0, &c8_c_cs,
                         &c8_c_sn);
          c8_t1 = c8_c_t1;
          c8_b_cs = c8_c_cs;
          c8_b_sn = c8_c_sn;
          c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_k), 1, 2, 1, 0) - 1] = c8_t1;
          c8_hb_a = -c8_b_sn;
          c8_ab_b = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 2, 1, 0) - 1];
          c8_f = c8_hb_a * c8_ab_b;
          c8_ib_a = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 2, 1, 0) - 1];
          c8_bb_b = c8_b_cs;
          c8_m_y = c8_ib_a * c8_bb_b;
          c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_k), 1, 2, 1, 0) - 1] = c8_m_y;
          c8_jb_a = c8_b_k;
          c8_t_c = c8_jb_a;
          c8_cb_b = c8_t_c - 1;
          c8_u_c = c8_cb_b << 1;
          c8_db_b = c8_u_c;
          c8_colk = c8_db_b;
          c8_kb_a = c8_qm1;
          c8_v_c = c8_kb_a;
          c8_eb_b = c8_v_c - 1;
          c8_w_c = c8_eb_b << 1;
          c8_fb_b = c8_w_c;
          c8_colqm1 = c8_fb_b;
          c8_c_eml_xrot(chartInstance, c8_U, c8_colk + 1, c8_colqm1 + 1, c8_b_cs,
                        c8_b_sn);
        }
        break;

       case 3:
        c8_lb_a = c8_m - 1;
        c8_mm1 = c8_lb_a;
        c8_d19 = c8_abs(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_m), 1, 2, 1, 0) - 1]);
        c8_d20 = c8_abs(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_mm1), 1, 2, 1, 0) - 1]);
        c8_d21 = c8_abs(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_mm1), 1, 2, 1, 0) - 1]);
        c8_d22 = c8_abs(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 2, 1, 0) - 1]);
        c8_d23 = c8_abs(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 2, 1, 0) - 1]);
        c8_c_varargin_1[0] = c8_d19;
        c8_c_varargin_1[1] = c8_d20;
        c8_c_varargin_1[2] = c8_d21;
        c8_c_varargin_1[3] = c8_d22;
        c8_c_varargin_1[4] = c8_d23;
        c8_ixstart = 1;
        c8_mtmp = c8_c_varargin_1[0];
        c8_g_x = c8_mtmp;
        c8_gb_b = muDoubleScalarIsNaN(c8_g_x);
        if (c8_gb_b) {
          c8_ix = 2;
          exitg2 = FALSE;
          while ((exitg2 == FALSE) && (c8_ix < 6)) {
            c8_b_ix = c8_ix;
            c8_ixstart = c8_b_ix;
            c8_h_x = c8_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c8_b_ix), 1, 5, 1, 0) - 1];
            c8_hb_b = muDoubleScalarIsNaN(c8_h_x);
            if (!c8_hb_b) {
              c8_mtmp = c8_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c8_b_ix), 1, 5, 1, 0) - 1];
              exitg2 = TRUE;
            } else {
              c8_ix++;
            }
          }
        }

        if (c8_ixstart < 5) {
          c8_mb_a = c8_ixstart;
          c8_i201 = c8_mb_a;
          c8_f_overflow = FALSE;
          if (c8_f_overflow) {
            c8_check_forloop_overflow_error(chartInstance, c8_f_overflow);
          }

          for (c8_c_ix = c8_i201 + 1; c8_c_ix < 6; c8_c_ix++) {
            c8_b_ix = c8_c_ix;
            c8_nb_a = c8_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c8_b_ix), 1, 5, 1, 0) - 1];
            c8_ib_b = c8_mtmp;
            c8_p = (c8_nb_a > c8_ib_b);
            if (c8_p) {
              c8_mtmp = c8_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c8_b_ix), 1, 5, 1, 0) - 1];
            }
          }
        }

        c8_b_mtmp = c8_mtmp;
        c8_scale = c8_b_mtmp;
        c8_sm = c8_eml_div(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_m), 1, 2, 1, 0) - 1],
                           c8_scale);
        c8_smm1 = c8_eml_div(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_mm1), 1,
          2, 1, 0) - 1], c8_scale);
        c8_emm1 = c8_eml_div(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_mm1), 1,
          2, 1, 0) - 1], c8_scale);
        c8_sqds = c8_eml_div(chartInstance, c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1,
          2, 1, 0) - 1], c8_scale);
        c8_eqds = c8_eml_div(chartInstance, c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1,
          2, 1, 0) - 1], c8_scale);
        c8_ob_a = c8_smm1 + c8_sm;
        c8_jb_b = c8_smm1 - c8_sm;
        c8_n_y = c8_ob_a * c8_jb_b;
        c8_pb_a = c8_emm1;
        c8_kb_b = c8_emm1;
        c8_o_y = c8_pb_a * c8_kb_b;
        c8_lb_b = c8_eml_div(chartInstance, c8_n_y + c8_o_y, 2.0);
        c8_qb_a = c8_sm;
        c8_mb_b = c8_emm1;
        c8_x_c = c8_qb_a * c8_mb_b;
        c8_rb_a = c8_x_c;
        c8_nb_b = c8_x_c;
        c8_x_c = c8_rb_a * c8_nb_b;
        c8_shift = 0.0;
        guard1 = FALSE;
        if (c8_lb_b != 0.0) {
          guard1 = TRUE;
        } else {
          if (c8_x_c != 0.0) {
            guard1 = TRUE;
          }
        }

        if (guard1 == TRUE) {
          c8_sb_a = c8_lb_b;
          c8_ob_b = c8_lb_b;
          c8_p_y = c8_sb_a * c8_ob_b;
          c8_shift = c8_p_y + c8_x_c;
          c8_b_sqrt(chartInstance, &c8_shift);
          if (c8_lb_b < 0.0) {
            c8_shift = -c8_shift;
          }

          c8_shift = c8_eml_div(chartInstance, c8_x_c, c8_lb_b + c8_shift);
        }

        c8_tb_a = c8_sqds + c8_sm;
        c8_pb_b = c8_sqds - c8_sm;
        c8_q_y = c8_tb_a * c8_pb_b;
        c8_f = c8_q_y + c8_shift;
        c8_ub_a = c8_sqds;
        c8_qb_b = c8_eqds;
        c8_g = c8_ub_a * c8_qb_b;
        c8_g_q = c8_b_q;
        c8_b_mm1 = c8_mm1;
        c8_vb_a = c8_g_q;
        c8_rb_b = c8_b_mm1;
        c8_wb_a = c8_vb_a;
        c8_sb_b = c8_rb_b;
        if (c8_wb_a > c8_sb_b) {
          c8_g_overflow = FALSE;
        } else {
          c8_g_overflow = (c8_sb_b > 2147483646);
        }

        if (c8_g_overflow) {
          c8_check_forloop_overflow_error(chartInstance, c8_g_overflow);
        }

        for (c8_d_k = c8_g_q; c8_d_k <= c8_b_mm1; c8_d_k++) {
          c8_b_k = c8_d_k;
          c8_xb_a = c8_b_k;
          c8_km1 = c8_xb_a;
          c8_yb_a = c8_b_k + 1;
          c8_kp1 = c8_yb_a;
          c8_c_f = c8_f;
          c8_unusedU1 = c8_g;
          c8_b_eml_xrotg(chartInstance, &c8_c_f, &c8_unusedU1, &c8_d_cs,
                         &c8_d_sn);
          c8_f = c8_c_f;
          c8_b_cs = c8_d_cs;
          c8_b_sn = c8_d_sn;
          if (c8_b_k > c8_b_q) {
            c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)(c8_km1 - 1)), 1, 2, 1, 0) - 1] = c8_f;
          }

          c8_ac_a = c8_b_cs;
          c8_tb_b = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 2, 1, 0) - 1];
          c8_r_y = c8_ac_a * c8_tb_b;
          c8_bc_a = c8_b_sn;
          c8_ub_b = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 2, 1, 0) - 1];
          c8_s_y = c8_bc_a * c8_ub_b;
          c8_f = c8_r_y + c8_s_y;
          c8_cc_a = c8_b_cs;
          c8_vb_b = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 2, 1, 0) - 1];
          c8_t_y = c8_cc_a * c8_vb_b;
          c8_dc_a = c8_b_sn;
          c8_wb_b = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 2, 1, 0) - 1];
          c8_u_y = c8_dc_a * c8_wb_b;
          c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_k), 1, 2, 1, 0) - 1] = c8_t_y - c8_u_y;
          c8_ec_a = c8_b_sn;
          c8_xb_b = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_kp1), 1, 2, 1, 0) - 1];
          c8_g = c8_ec_a * c8_xb_b;
          c8_fc_a = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_kp1), 1, 2, 1, 0) - 1];
          c8_yb_b = c8_b_cs;
          c8_v_y = c8_fc_a * c8_yb_b;
          c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_kp1), 1, 2, 1, 0) - 1] = c8_v_y;
          c8_gc_a = c8_b_k;
          c8_y_c = c8_gc_a;
          c8_ac_b = c8_y_c - 1;
          c8_ab_c = c8_ac_b << 1;
          c8_bc_b = c8_ab_c;
          c8_colk = c8_bc_b;
          c8_cc_b = c8_b_k;
          c8_bb_c = c8_cc_b << 1;
          c8_dc_b = c8_bb_c;
          c8_colkp1 = c8_dc_b;
          c8_c_eml_xrot(chartInstance, c8_Vf, c8_colk + 1, c8_colkp1 + 1,
                        c8_b_cs, c8_b_sn);
          c8_d_f = c8_f;
          c8_unusedU2 = c8_g;
          c8_b_eml_xrotg(chartInstance, &c8_d_f, &c8_unusedU2, &c8_e_cs,
                         &c8_e_sn);
          c8_f = c8_d_f;
          c8_b_cs = c8_e_cs;
          c8_b_sn = c8_e_sn;
          c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_k), 1, 2, 1, 0) - 1] = c8_f;
          c8_hc_a = c8_b_cs;
          c8_ec_b = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 2, 1, 0) - 1];
          c8_w_y = c8_hc_a * c8_ec_b;
          c8_ic_a = c8_b_sn;
          c8_fc_b = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_kp1), 1, 2, 1, 0) - 1];
          c8_x_y = c8_ic_a * c8_fc_b;
          c8_f = c8_w_y + c8_x_y;
          c8_jc_a = -c8_b_sn;
          c8_gc_b = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 2, 1, 0) - 1];
          c8_y_y = c8_jc_a * c8_gc_b;
          c8_kc_a = c8_b_cs;
          c8_hc_b = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_kp1), 1, 2, 1, 0) - 1];
          c8_ab_y = c8_kc_a * c8_hc_b;
          c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_kp1), 1, 2, 1, 0) - 1] = c8_y_y + c8_ab_y;
          c8_lc_a = c8_b_sn;
          c8_ic_b = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_kp1), 1, 2, 1, 0) - 1];
          c8_g = c8_lc_a * c8_ic_b;
          c8_mc_a = c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c8_kp1), 1, 2, 1, 0) - 1];
          c8_jc_b = c8_b_cs;
          c8_bb_y = c8_mc_a * c8_jc_b;
          c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_kp1), 1, 2, 1, 0) - 1] = c8_bb_y;
          if (c8_b_k < 2) {
            c8_nc_a = c8_b_k;
            c8_cb_c = c8_nc_a;
            c8_kc_b = c8_cb_c - 1;
            c8_db_c = c8_kc_b << 1;
            c8_lc_b = c8_db_c;
            c8_colk = c8_lc_b;
            c8_mc_b = c8_b_k;
            c8_eb_c = c8_mc_b << 1;
            c8_nc_b = c8_eb_c;
            c8_colkp1 = c8_nc_b;
            c8_c_eml_xrot(chartInstance, c8_U, c8_colk + 1, c8_colkp1 + 1,
                          c8_b_cs, c8_b_sn);
          }
        }

        c8_oc_a = c8_m;
        c8_fb_c = c8_oc_a;
        c8_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c8_fb_c - 1)), 1, 2, 1, 0) - 1] = c8_f;
        c8_iter++;
        break;

       default:
        if (c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c8_b_q), 1, 2, 1, 0) - 1] < 0.0) {
          c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_q), 1, 2, 1, 0) - 1] =
            -c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_q), 1, 2, 1, 0) - 1];
          c8_pc_a = c8_b_q;
          c8_gb_c = c8_pc_a;
          c8_oc_b = c8_gb_c - 1;
          c8_hb_c = c8_oc_b << 1;
          c8_pc_b = c8_hb_c;
          c8_colq = c8_pc_b;
          c8_b_eml_scalar_eg(chartInstance);
          c8_d24 = -1.0;
          c8_k_eml_xscal(chartInstance, c8_d24, c8_Vf, c8_colq + 1);
        }

        c8_qc_a = c8_b_q + 1;
        c8_qp1 = c8_qc_a;
        exitg3 = FALSE;
        while ((exitg3 == FALSE) && (c8_b_q < 2)) {
          if (c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c8_b_q), 1, 2, 1, 0) - 1] <
              c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c8_qp1), 1, 2, 1, 0) - 1]) {
            c8_rt = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c8_b_q), 1, 2, 1, 0) - 1];
            c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c8_b_q), 1, 2, 1, 0) - 1] =
              c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c8_qp1), 1, 2, 1, 0) - 1];
            c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c8_qp1), 1, 2, 1, 0) - 1] = c8_rt;
            if (c8_b_q < 2) {
              c8_sc_a = c8_b_q;
              c8_ib_c = c8_sc_a;
              c8_qc_b = c8_ib_c - 1;
              c8_jb_c = c8_qc_b << 1;
              c8_rc_b = c8_jb_c;
              c8_colq = c8_rc_b;
              c8_sc_b = c8_b_q;
              c8_kb_c = c8_sc_b << 1;
              c8_tc_b = c8_kb_c;
              c8_colqp1 = c8_tc_b;
              c8_c_eml_xswap(chartInstance, c8_Vf, c8_colq + 1, c8_colqp1 + 1);
            }

            if (c8_b_q < 2) {
              c8_tc_a = c8_b_q;
              c8_lb_c = c8_tc_a;
              c8_uc_b = c8_lb_c - 1;
              c8_mb_c = c8_uc_b << 1;
              c8_vc_b = c8_mb_c;
              c8_colq = c8_vc_b;
              c8_wc_b = c8_b_q;
              c8_nb_c = c8_wc_b << 1;
              c8_xc_b = c8_nb_c;
              c8_colqp1 = c8_xc_b;
              c8_c_eml_xswap(chartInstance, c8_U, c8_colq + 1, c8_colqp1 + 1);
            }

            c8_b_q = c8_qp1;
            c8_uc_a = c8_b_q + 1;
            c8_qp1 = c8_uc_a;
          } else {
            exitg3 = TRUE;
          }
        }

        c8_iter = 0.0;
        c8_rc_a = c8_m - 1;
        c8_m = c8_rc_a;
        break;
      }
    }
  }

  for (c8_e_k = 1; c8_e_k < 3; c8_e_k++) {
    c8_b_k = c8_e_k;
    c8_S[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c8_b_k), 1, 2, 1, 0) - 1] = c8_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 2, 1, 0) - 1];
  }

  for (c8_j = 1; c8_j < 3; c8_j++) {
    c8_b_j = c8_j;
    for (c8_i = 1; c8_i < 3; c8_i++) {
      c8_b_i = c8_i;
      c8_V[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c8_b_i), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
               (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_j), 1, 2, 2, 0) - 1)
             << 1)) - 1] = c8_Vf[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c8_b_i), 1, 2, 1, 0) +
        ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c8_b_j), 1, 2, 2, 0) - 1) << 1)) - 1];
    }
  }
}

static real_T c8_e_eml_xnrm2(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_x[4])
{
  real_T c8_y;
  real_T c8_scale;
  int32_T c8_k;
  int32_T c8_b_k;
  real_T c8_b_x;
  real_T c8_c_x;
  real_T c8_absxk;
  real_T c8_t;
  c8_y = 0.0;
  c8_realmin(chartInstance);
  c8_scale = 2.2250738585072014E-308;
  for (c8_k = 1; c8_k < 3; c8_k++) {
    c8_b_k = c8_k;
    c8_b_x = c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c8_b_k), 1, 4, 1, 0) - 1];
    c8_c_x = c8_b_x;
    c8_absxk = muDoubleScalarAbs(c8_c_x);
    if (c8_absxk > c8_scale) {
      c8_t = c8_scale / c8_absxk;
      c8_y = 1.0 + c8_y * c8_t * c8_t;
      c8_scale = c8_absxk;
    } else {
      c8_t = c8_absxk / c8_scale;
      c8_y += c8_t * c8_t;
    }
  }

  return c8_scale * muDoubleScalarSqrt(c8_y);
}

static void c8_g_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[4], real_T c8_b_x[4])
{
  int32_T c8_i202;
  for (c8_i202 = 0; c8_i202 < 4; c8_i202++) {
    c8_b_x[c8_i202] = c8_x[c8_i202];
  }

  c8_n_eml_xscal(chartInstance, c8_b_a, c8_b_x);
}

static real_T c8_d_eml_xdotc(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_x[4], real_T c8_y[4])
{
  real_T c8_d;
  int32_T c8_ix;
  int32_T c8_iy;
  int32_T c8_k;
  int32_T c8_b_a;
  int32_T c8_c_a;
  c8_e_eml_scalar_eg(chartInstance);
  c8_d = 0.0;
  c8_ix = 1;
  c8_iy = 3;
  for (c8_k = 1; c8_k < 3; c8_k++) {
    c8_d += c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c8_ix), 1, 4, 1, 0) - 1] * c8_y[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_iy), 1, 4, 1, 0) - 1];
    c8_b_a = c8_ix + 1;
    c8_ix = c8_b_a;
    c8_c_a = c8_iy + 1;
    c8_iy = c8_c_a;
  }

  return c8_d;
}

static void c8_h_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_y[4], real_T c8_b_y[4])
{
  int32_T c8_i203;
  for (c8_i203 = 0; c8_i203 < 4; c8_i203++) {
    c8_b_y[c8_i203] = c8_y[c8_i203];
  }

  c8_p_eml_xaxpy(chartInstance, c8_b_a, c8_b_y);
}

static void c8_b_eml_xgemm(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_k, real_T c8_A[4], real_T c8_B[4], real_T c8_C[4], real_T c8_b_C[4])
{
  int32_T c8_i204;
  int32_T c8_i205;
  real_T c8_b_A[4];
  int32_T c8_i206;
  real_T c8_b_B[4];
  for (c8_i204 = 0; c8_i204 < 4; c8_i204++) {
    c8_b_C[c8_i204] = c8_C[c8_i204];
  }

  for (c8_i205 = 0; c8_i205 < 4; c8_i205++) {
    c8_b_A[c8_i205] = c8_A[c8_i205];
  }

  for (c8_i206 = 0; c8_i206 < 4; c8_i206++) {
    c8_b_B[c8_i206] = c8_B[c8_i206];
  }

  c8_d_eml_xgemm(chartInstance, c8_k, c8_b_A, c8_b_B, c8_b_C);
}

static void c8_h_eml_scalar_eg(SFc8_CusakisME4901InstanceStruct *chartInstance)
{
}

static const mxArray *c8_h_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc8_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(int32_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static int32_T c8_i_emlrt_marshallIn(SFc8_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int32_T c8_y;
  int32_T c8_i207;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i207, 1, 6, 0U, 0, 0U, 0);
  c8_y = c8_i207;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_sfEvent;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_y;
  SFc8_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc8_CusakisME4901InstanceStruct *)chartInstanceVoid;
  c8_b_sfEvent = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_sfEvent),
    &c8_thisId);
  sf_mex_destroy(&c8_b_sfEvent);
  *(int32_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static uint8_T c8_j_emlrt_marshallIn(SFc8_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c8_b_is_active_c8_CusakisME4901, const char_T
  *c8_identifier)
{
  uint8_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_is_active_c8_CusakisME4901), &c8_thisId);
  sf_mex_destroy(&c8_b_is_active_c8_CusakisME4901);
  return c8_y;
}

static uint8_T c8_k_emlrt_marshallIn(SFc8_CusakisME4901InstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_y;
  uint8_T c8_u0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u0, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_u0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_b_eml_matlab_zgetrf(SFc8_CusakisME4901InstanceStruct
  *chartInstance, real_T c8_A[4], int32_T c8_ipiv[2], int32_T *c8_info)
{
  int32_T c8_i208;
  int32_T c8_idxmax;
  real_T c8_x;
  real_T c8_b_x;
  real_T c8_c_x;
  real_T c8_y;
  real_T c8_d_x;
  real_T c8_e_x;
  real_T c8_b_y;
  real_T c8_smax;
  real_T c8_f_x;
  real_T c8_g_x;
  real_T c8_h_x;
  real_T c8_c_y;
  real_T c8_i_x;
  real_T c8_j_x;
  real_T c8_d_y;
  real_T c8_s;
  int32_T c8_b_a;
  int32_T c8_jpiv_offset;
  int32_T c8_b;
  int32_T c8_jpiv;
  int32_T c8_b_b;
  int32_T c8_c;
  int32_T c8_c_b;
  int32_T c8_jprow;
  int32_T c8_iy0;
  int32_T c8_b_iy0;
  int32_T c8_c_iy0;
  int32_T c8_ix;
  int32_T c8_iy;
  int32_T c8_k;
  real_T c8_temp;
  int32_T c8_c_a;
  int32_T c8_d_a;
  real_T c8_k_x;
  real_T c8_e_y;
  real_T c8_z;
  c8_realmin(chartInstance);
  c8_eps(chartInstance);
  for (c8_i208 = 0; c8_i208 < 2; c8_i208++) {
    c8_ipiv[c8_i208] = 1 + c8_i208;
  }

  *c8_info = 0;
  c8_idxmax = 1;
  c8_x = c8_A[0];
  c8_b_x = c8_x;
  c8_c_x = c8_b_x;
  c8_y = muDoubleScalarAbs(c8_c_x);
  c8_d_x = 0.0;
  c8_e_x = c8_d_x;
  c8_b_y = muDoubleScalarAbs(c8_e_x);
  c8_smax = c8_y + c8_b_y;
  c8_f_x = c8_A[1];
  c8_g_x = c8_f_x;
  c8_h_x = c8_g_x;
  c8_c_y = muDoubleScalarAbs(c8_h_x);
  c8_i_x = 0.0;
  c8_j_x = c8_i_x;
  c8_d_y = muDoubleScalarAbs(c8_j_x);
  c8_s = c8_c_y + c8_d_y;
  if (c8_s > c8_smax) {
    c8_idxmax = 2;
  }

  c8_b_a = c8_idxmax - 1;
  c8_jpiv_offset = c8_b_a;
  c8_b = c8_jpiv_offset;
  c8_jpiv = c8_b;
  if (c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c8_jpiv + 1)), 1, 4, 1, 0) - 1] != 0.0) {
    if (c8_jpiv_offset != 0) {
      c8_b_b = c8_jpiv_offset;
      c8_c = c8_b_b;
      c8_ipiv[0] = c8_c + 1;
      c8_c_b = c8_jpiv_offset;
      c8_jprow = c8_c_b;
      c8_iy0 = c8_jprow + 1;
      c8_b_iy0 = c8_iy0;
      c8_below_threshold(chartInstance);
      c8_c_iy0 = c8_b_iy0;
      c8_ix = 1;
      c8_iy = c8_c_iy0;
      for (c8_k = 1; c8_k < 3; c8_k++) {
        c8_temp = c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c8_ix), 1, 4, 1, 0) - 1];
        c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_ix), 1, 4, 1, 0) - 1] = c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_iy), 1, 4, 1, 0) - 1];
        c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_iy), 1, 4, 1, 0) - 1] = c8_temp;
        c8_c_a = c8_ix + 2;
        c8_ix = c8_c_a;
        c8_d_a = c8_iy + 2;
        c8_iy = c8_d_a;
      }
    }

    c8_k_x = c8_A[1];
    c8_e_y = c8_A[0];
    c8_z = c8_k_x / c8_e_y;
    c8_A[1] = c8_z;
  } else {
    *c8_info = 1;
  }

  c8_b_eml_xger(chartInstance, c8_A);
  if (*c8_info == 0) {
    if (!(c8_A[3] != 0.0)) {
      *c8_info = 2;
    }
  }
}

static void c8_b_eml_xger(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_A[4])
{
  real_T c8_yjy;
  real_T c8_temp;
  int32_T c8_ix;
  int32_T c8_ijA;
  int32_T c8_b_ijA;
  int32_T c8_b_a;
  c8_yjy = c8_A[2];
  if (c8_yjy != 0.0) {
    c8_temp = -c8_yjy;
    c8_ix = 2;
    for (c8_ijA = 4; c8_ijA < 5; c8_ijA++) {
      c8_b_ijA = c8_ijA;
      c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c8_b_ijA), 1, 4, 1, 0) - 1] = c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_ijA), 1, 4, 1, 0) - 1]
        + c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c8_ix), 1, 4, 1, 0) - 1] * c8_temp;
      c8_b_a = c8_ix + 1;
      c8_ix = c8_b_a;
    }
  }
}

static void c8_b_sqrt(SFc8_CusakisME4901InstanceStruct *chartInstance, real_T
                      *c8_x)
{
  if (*c8_x < 0.0) {
    c8_eml_error(chartInstance);
  }

  *c8_x = muDoubleScalarSqrt(*c8_x);
}

static void c8_h_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_b_a, real_T c8_x[6], int32_T c8_ix0)
{
  int32_T c8_b_n;
  real_T c8_c_a;
  int32_T c8_b_ix0;
  int32_T c8_c_n;
  real_T c8_d_a;
  int32_T c8_c_ix0;
  int32_T c8_d_ix0;
  int32_T c8_e_a;
  int32_T c8_c;
  int32_T c8_b;
  int32_T c8_b_c;
  int32_T c8_f_a;
  int32_T c8_b_b;
  int32_T c8_i209;
  int32_T c8_g_a;
  int32_T c8_c_b;
  int32_T c8_h_a;
  int32_T c8_d_b;
  boolean_T c8_overflow;
  int32_T c8_k;
  int32_T c8_b_k;
  c8_b_n = c8_n;
  c8_c_a = c8_b_a;
  c8_b_ix0 = c8_ix0;
  c8_c_n = c8_b_n;
  c8_d_a = c8_c_a;
  c8_c_ix0 = c8_b_ix0;
  c8_d_ix0 = c8_c_ix0;
  c8_e_a = c8_c_n;
  c8_c = c8_e_a;
  c8_b = c8_c - 1;
  c8_b_c = c8_b;
  c8_f_a = c8_c_ix0;
  c8_b_b = c8_b_c;
  c8_i209 = c8_f_a + c8_b_b;
  c8_g_a = c8_d_ix0;
  c8_c_b = c8_i209;
  c8_h_a = c8_g_a;
  c8_d_b = c8_c_b;
  if (c8_h_a > c8_d_b) {
    c8_overflow = FALSE;
  } else {
    c8_overflow = (c8_d_b > 2147483646);
  }

  if (c8_overflow) {
    c8_check_forloop_overflow_error(chartInstance, c8_overflow);
  }

  for (c8_k = c8_d_ix0; c8_k <= c8_i209; c8_k++) {
    c8_b_k = c8_k;
    c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c8_b_k), 1, 6, 1, 0) - 1] = c8_d_a * c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 6, 1, 0) - 1];
  }
}

static void c8_i_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_b_a, int32_T c8_ix0, real_T c8_y[6], int32_T c8_iy0)
{
  int32_T c8_b_n;
  real_T c8_c_a;
  int32_T c8_b_ix0;
  int32_T c8_b_iy0;
  int32_T c8_c_n;
  real_T c8_d_a;
  int32_T c8_c_ix0;
  int32_T c8_c_iy0;
  int32_T c8_e_a;
  int32_T c8_ix;
  int32_T c8_f_a;
  int32_T c8_iy;
  int32_T c8_g_a;
  int32_T c8_i210;
  int32_T c8_b;
  int32_T c8_b_b;
  boolean_T c8_overflow;
  int32_T c8_k;
  int32_T c8_h_a;
  int32_T c8_c;
  int32_T c8_i_a;
  int32_T c8_b_c;
  int32_T c8_j_a;
  int32_T c8_c_c;
  int32_T c8_k_a;
  int32_T c8_l_a;
  c8_b_n = c8_n;
  c8_c_a = c8_b_a;
  c8_b_ix0 = c8_ix0;
  c8_b_iy0 = c8_iy0;
  c8_c_n = c8_b_n;
  c8_d_a = c8_c_a;
  c8_c_ix0 = c8_b_ix0;
  c8_c_iy0 = c8_b_iy0;
  if (c8_c_n < 1) {
  } else if (c8_d_a == 0.0) {
  } else {
    c8_e_a = c8_c_ix0 - 1;
    c8_ix = c8_e_a;
    c8_f_a = c8_c_iy0 - 1;
    c8_iy = c8_f_a;
    c8_g_a = c8_c_n - 1;
    c8_i210 = c8_g_a;
    c8_b = c8_i210;
    c8_b_b = c8_b;
    if (0 > c8_b_b) {
      c8_overflow = FALSE;
    } else {
      c8_overflow = (c8_b_b > 2147483646);
    }

    if (c8_overflow) {
      c8_check_forloop_overflow_error(chartInstance, c8_overflow);
    }

    for (c8_k = 0; c8_k <= c8_i210; c8_k++) {
      c8_h_a = c8_iy;
      c8_c = c8_h_a;
      c8_i_a = c8_iy;
      c8_b_c = c8_i_a;
      c8_j_a = c8_ix;
      c8_c_c = c8_j_a;
      c8_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c8_c + 1)), 1, 6, 1, 0) - 1] = c8_y[_SFD_EML_ARRAY_BOUNDS_CHECK
        ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c8_b_c + 1)), 1, 6, 1, 0)
        - 1] + c8_d_a * c8_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)(c8_c_c + 1)), 1, 6, 1, 0) - 1];
      c8_k_a = c8_ix + 1;
      c8_ix = c8_k_a;
      c8_l_a = c8_iy + 1;
      c8_iy = c8_l_a;
    }
  }
}

static void c8_i_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_b_a, real_T c8_x[2], int32_T c8_ix0)
{
  int32_T c8_b_n;
  real_T c8_c_a;
  int32_T c8_b_ix0;
  int32_T c8_c_n;
  real_T c8_d_a;
  int32_T c8_c_ix0;
  int32_T c8_d_ix0;
  int32_T c8_e_a;
  int32_T c8_c;
  int32_T c8_b;
  int32_T c8_b_c;
  int32_T c8_f_a;
  int32_T c8_b_b;
  int32_T c8_i211;
  int32_T c8_g_a;
  int32_T c8_c_b;
  int32_T c8_h_a;
  int32_T c8_d_b;
  boolean_T c8_overflow;
  int32_T c8_k;
  int32_T c8_b_k;
  c8_b_n = c8_n;
  c8_c_a = c8_b_a;
  c8_b_ix0 = c8_ix0;
  c8_c_n = c8_b_n;
  c8_d_a = c8_c_a;
  c8_c_ix0 = c8_b_ix0;
  c8_d_ix0 = c8_c_ix0;
  c8_e_a = c8_c_n;
  c8_c = c8_e_a;
  c8_b = c8_c - 1;
  c8_b_c = c8_b;
  c8_f_a = c8_c_ix0;
  c8_b_b = c8_b_c;
  c8_i211 = c8_f_a + c8_b_b;
  c8_g_a = c8_d_ix0;
  c8_c_b = c8_i211;
  c8_h_a = c8_g_a;
  c8_d_b = c8_c_b;
  if (c8_h_a > c8_d_b) {
    c8_overflow = FALSE;
  } else {
    c8_overflow = (c8_d_b > 2147483646);
  }

  if (c8_overflow) {
    c8_check_forloop_overflow_error(chartInstance, c8_overflow);
  }

  for (c8_k = c8_d_ix0; c8_k <= c8_i211; c8_k++) {
    c8_b_k = c8_k;
    c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c8_b_k), 1, 2, 1, 0) - 1] = c8_d_a * c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 2, 1, 0) - 1];
  }
}

static void c8_j_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_b_a, real_T c8_x[6], int32_T c8_ix0, real_T c8_y[3],
  int32_T c8_iy0)
{
  int32_T c8_b_n;
  real_T c8_c_a;
  int32_T c8_b_ix0;
  int32_T c8_b_iy0;
  int32_T c8_c_n;
  real_T c8_d_a;
  int32_T c8_c_ix0;
  int32_T c8_c_iy0;
  int32_T c8_e_a;
  int32_T c8_ix;
  int32_T c8_f_a;
  int32_T c8_iy;
  int32_T c8_g_a;
  int32_T c8_i212;
  int32_T c8_b;
  int32_T c8_b_b;
  boolean_T c8_overflow;
  int32_T c8_k;
  int32_T c8_h_a;
  int32_T c8_c;
  int32_T c8_i_a;
  int32_T c8_b_c;
  int32_T c8_j_a;
  int32_T c8_c_c;
  int32_T c8_k_a;
  int32_T c8_l_a;
  c8_b_n = c8_n;
  c8_c_a = c8_b_a;
  c8_b_ix0 = c8_ix0;
  c8_b_iy0 = c8_iy0;
  c8_c_n = c8_b_n;
  c8_d_a = c8_c_a;
  c8_c_ix0 = c8_b_ix0;
  c8_c_iy0 = c8_b_iy0;
  if (c8_c_n < 1) {
  } else if (c8_d_a == 0.0) {
  } else {
    c8_e_a = c8_c_ix0 - 1;
    c8_ix = c8_e_a;
    c8_f_a = c8_c_iy0 - 1;
    c8_iy = c8_f_a;
    c8_g_a = c8_c_n - 1;
    c8_i212 = c8_g_a;
    c8_b = c8_i212;
    c8_b_b = c8_b;
    if (0 > c8_b_b) {
      c8_overflow = FALSE;
    } else {
      c8_overflow = (c8_b_b > 2147483646);
    }

    if (c8_overflow) {
      c8_check_forloop_overflow_error(chartInstance, c8_overflow);
    }

    for (c8_k = 0; c8_k <= c8_i212; c8_k++) {
      c8_h_a = c8_iy;
      c8_c = c8_h_a;
      c8_i_a = c8_iy;
      c8_b_c = c8_i_a;
      c8_j_a = c8_ix;
      c8_c_c = c8_j_a;
      c8_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c8_c + 1)), 1, 3, 1, 0) - 1] = c8_y[_SFD_EML_ARRAY_BOUNDS_CHECK
        ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c8_b_c + 1)), 1, 3, 1, 0)
        - 1] + c8_d_a * c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)(c8_c_c + 1)), 1, 6, 1, 0) - 1];
      c8_k_a = c8_ix + 1;
      c8_ix = c8_k_a;
      c8_l_a = c8_iy + 1;
      c8_iy = c8_l_a;
    }
  }
}

static void c8_k_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_b_a, real_T c8_x[3], int32_T c8_ix0, real_T c8_y[6],
  int32_T c8_iy0)
{
  int32_T c8_b_n;
  real_T c8_c_a;
  int32_T c8_b_ix0;
  int32_T c8_b_iy0;
  int32_T c8_c_n;
  real_T c8_d_a;
  int32_T c8_c_ix0;
  int32_T c8_c_iy0;
  int32_T c8_e_a;
  int32_T c8_ix;
  int32_T c8_f_a;
  int32_T c8_iy;
  int32_T c8_g_a;
  int32_T c8_i213;
  int32_T c8_b;
  int32_T c8_b_b;
  boolean_T c8_overflow;
  int32_T c8_k;
  int32_T c8_h_a;
  int32_T c8_c;
  int32_T c8_i_a;
  int32_T c8_b_c;
  int32_T c8_j_a;
  int32_T c8_c_c;
  int32_T c8_k_a;
  int32_T c8_l_a;
  c8_b_n = c8_n;
  c8_c_a = c8_b_a;
  c8_b_ix0 = c8_ix0;
  c8_b_iy0 = c8_iy0;
  c8_c_n = c8_b_n;
  c8_d_a = c8_c_a;
  c8_c_ix0 = c8_b_ix0;
  c8_c_iy0 = c8_b_iy0;
  if (c8_c_n < 1) {
  } else if (c8_d_a == 0.0) {
  } else {
    c8_e_a = c8_c_ix0 - 1;
    c8_ix = c8_e_a;
    c8_f_a = c8_c_iy0 - 1;
    c8_iy = c8_f_a;
    c8_g_a = c8_c_n - 1;
    c8_i213 = c8_g_a;
    c8_b = c8_i213;
    c8_b_b = c8_b;
    if (0 > c8_b_b) {
      c8_overflow = FALSE;
    } else {
      c8_overflow = (c8_b_b > 2147483646);
    }

    if (c8_overflow) {
      c8_check_forloop_overflow_error(chartInstance, c8_overflow);
    }

    for (c8_k = 0; c8_k <= c8_i213; c8_k++) {
      c8_h_a = c8_iy;
      c8_c = c8_h_a;
      c8_i_a = c8_iy;
      c8_b_c = c8_i_a;
      c8_j_a = c8_ix;
      c8_c_c = c8_j_a;
      c8_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c8_c + 1)), 1, 6, 1, 0) - 1] = c8_y[_SFD_EML_ARRAY_BOUNDS_CHECK
        ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c8_b_c + 1)), 1, 6, 1, 0)
        - 1] + c8_d_a * c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)(c8_c_c + 1)), 1, 3, 1, 0) - 1];
      c8_k_a = c8_ix + 1;
      c8_ix = c8_k_a;
      c8_l_a = c8_iy + 1;
      c8_iy = c8_l_a;
    }
  }
}

static void c8_l_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_b_a, int32_T c8_ix0, real_T c8_y[4], int32_T c8_iy0)
{
  int32_T c8_b_n;
  real_T c8_c_a;
  int32_T c8_b_ix0;
  int32_T c8_b_iy0;
  int32_T c8_c_n;
  real_T c8_d_a;
  int32_T c8_c_ix0;
  int32_T c8_c_iy0;
  int32_T c8_e_a;
  int32_T c8_ix;
  int32_T c8_f_a;
  int32_T c8_iy;
  int32_T c8_g_a;
  int32_T c8_i214;
  int32_T c8_b;
  int32_T c8_b_b;
  boolean_T c8_overflow;
  int32_T c8_k;
  int32_T c8_h_a;
  int32_T c8_c;
  int32_T c8_i_a;
  int32_T c8_b_c;
  int32_T c8_j_a;
  int32_T c8_c_c;
  int32_T c8_k_a;
  int32_T c8_l_a;
  c8_b_n = c8_n;
  c8_c_a = c8_b_a;
  c8_b_ix0 = c8_ix0;
  c8_b_iy0 = c8_iy0;
  c8_c_n = c8_b_n;
  c8_d_a = c8_c_a;
  c8_c_ix0 = c8_b_ix0;
  c8_c_iy0 = c8_b_iy0;
  if (c8_c_n < 1) {
  } else if (c8_d_a == 0.0) {
  } else {
    c8_e_a = c8_c_ix0 - 1;
    c8_ix = c8_e_a;
    c8_f_a = c8_c_iy0 - 1;
    c8_iy = c8_f_a;
    c8_g_a = c8_c_n - 1;
    c8_i214 = c8_g_a;
    c8_b = c8_i214;
    c8_b_b = c8_b;
    if (0 > c8_b_b) {
      c8_overflow = FALSE;
    } else {
      c8_overflow = (c8_b_b > 2147483646);
    }

    if (c8_overflow) {
      c8_check_forloop_overflow_error(chartInstance, c8_overflow);
    }

    for (c8_k = 0; c8_k <= c8_i214; c8_k++) {
      c8_h_a = c8_iy;
      c8_c = c8_h_a;
      c8_i_a = c8_iy;
      c8_b_c = c8_i_a;
      c8_j_a = c8_ix;
      c8_c_c = c8_j_a;
      c8_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c8_c + 1)), 1, 4, 1, 0) - 1] = c8_y[_SFD_EML_ARRAY_BOUNDS_CHECK
        ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c8_b_c + 1)), 1, 4, 1, 0)
        - 1] + c8_d_a * c8_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)(c8_c_c + 1)), 1, 4, 1, 0) - 1];
      c8_k_a = c8_ix + 1;
      c8_ix = c8_k_a;
      c8_l_a = c8_iy + 1;
      c8_iy = c8_l_a;
    }
  }
}

static void c8_j_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[6], int32_T c8_ix0)
{
  real_T c8_c_a;
  int32_T c8_b_ix0;
  real_T c8_d_a;
  int32_T c8_c_ix0;
  int32_T c8_d_ix0;
  int32_T c8_e_a;
  int32_T c8_i215;
  int32_T c8_f_a;
  int32_T c8_b;
  int32_T c8_g_a;
  int32_T c8_b_b;
  boolean_T c8_overflow;
  int32_T c8_k;
  int32_T c8_b_k;
  c8_c_a = c8_b_a;
  c8_b_ix0 = c8_ix0;
  c8_d_a = c8_c_a;
  c8_c_ix0 = c8_b_ix0;
  c8_d_ix0 = c8_c_ix0;
  c8_e_a = c8_c_ix0 + 2;
  c8_i215 = c8_e_a;
  c8_f_a = c8_d_ix0;
  c8_b = c8_i215;
  c8_g_a = c8_f_a;
  c8_b_b = c8_b;
  if (c8_g_a > c8_b_b) {
    c8_overflow = FALSE;
  } else {
    c8_overflow = (c8_b_b > 2147483646);
  }

  if (c8_overflow) {
    c8_check_forloop_overflow_error(chartInstance, c8_overflow);
  }

  for (c8_k = c8_d_ix0; c8_k <= c8_i215; c8_k++) {
    c8_b_k = c8_k;
    c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c8_b_k), 1, 6, 1, 0) - 1] = c8_d_a * c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 6, 1, 0) - 1];
  }
}

static void c8_k_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[4], int32_T c8_ix0)
{
  real_T c8_c_a;
  int32_T c8_b_ix0;
  real_T c8_d_a;
  int32_T c8_c_ix0;
  int32_T c8_d_ix0;
  int32_T c8_e_a;
  int32_T c8_i216;
  int32_T c8_f_a;
  int32_T c8_b;
  int32_T c8_g_a;
  int32_T c8_b_b;
  boolean_T c8_overflow;
  int32_T c8_k;
  int32_T c8_b_k;
  c8_c_a = c8_b_a;
  c8_b_ix0 = c8_ix0;
  c8_b_below_threshold(chartInstance);
  c8_d_a = c8_c_a;
  c8_c_ix0 = c8_b_ix0;
  c8_d_ix0 = c8_c_ix0;
  c8_e_a = c8_c_ix0 + 1;
  c8_i216 = c8_e_a;
  c8_f_a = c8_d_ix0;
  c8_b = c8_i216;
  c8_g_a = c8_f_a;
  c8_b_b = c8_b;
  if (c8_g_a > c8_b_b) {
    c8_overflow = FALSE;
  } else {
    c8_overflow = (c8_b_b > 2147483646);
  }

  if (c8_overflow) {
    c8_check_forloop_overflow_error(chartInstance, c8_overflow);
  }

  for (c8_k = c8_d_ix0; c8_k <= c8_i216; c8_k++) {
    c8_b_k = c8_k;
    c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c8_b_k), 1, 4, 1, 0) - 1] = c8_d_a * c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 4, 1, 0) - 1];
  }
}

static void c8_b_eml_xrotg(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T *c8_b_a, real_T *c8_b, real_T *c8_c, real_T *c8_s)
{
  real_T c8_c_a;
  real_T c8_b_b;
  real_T c8_c_b;
  real_T c8_d_a;
  real_T c8_e_a;
  real_T c8_d_b;
  real_T c8_e_b;
  real_T c8_f_a;
  real_T c8_b_c;
  real_T c8_b_s;
  double * c8_a_t;
  double * c8_b_t;
  double * c8_c_t;
  double * c8_s_t;
  real_T c8_c_c;
  real_T c8_c_s;
  c8_c_a = *c8_b_a;
  c8_b_b = *c8_b;
  c8_c_b = c8_b_b;
  c8_d_a = c8_c_a;
  c8_e_a = c8_d_a;
  c8_d_b = c8_c_b;
  c8_e_b = c8_d_b;
  c8_f_a = c8_e_a;
  c8_b_c = 0.0;
  c8_b_s = 0.0;
  c8_a_t = (double *)(&c8_f_a);
  c8_b_t = (double *)(&c8_e_b);
  c8_c_t = (double *)(&c8_b_c);
  c8_s_t = (double *)(&c8_b_s);
  drotg(c8_a_t, c8_b_t, c8_c_t, c8_s_t);
  c8_d_a = c8_f_a;
  c8_c_b = c8_e_b;
  c8_c_c = c8_b_c;
  c8_c_s = c8_b_s;
  *c8_b_a = c8_d_a;
  *c8_b = c8_c_b;
  *c8_c = c8_c_c;
  *c8_s = c8_c_s;
}

static void c8_c_eml_xrot(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_x[4], int32_T c8_ix0, int32_T c8_iy0, real_T c8_c, real_T c8_s)
{
  int32_T c8_b_ix0;
  int32_T c8_b_iy0;
  real_T c8_b_c;
  real_T c8_b_s;
  int32_T c8_c_ix0;
  int32_T c8_c_iy0;
  real_T c8_c_c;
  real_T c8_c_s;
  int32_T c8_ix;
  int32_T c8_iy;
  int32_T c8_k;
  real_T c8_b_a;
  real_T c8_b;
  real_T c8_y;
  real_T c8_c_a;
  real_T c8_b_b;
  real_T c8_b_y;
  real_T c8_temp;
  real_T c8_d_a;
  real_T c8_c_b;
  real_T c8_c_y;
  real_T c8_e_a;
  real_T c8_d_b;
  real_T c8_d_y;
  int32_T c8_f_a;
  int32_T c8_g_a;
  c8_b_ix0 = c8_ix0;
  c8_b_iy0 = c8_iy0;
  c8_b_c = c8_c;
  c8_b_s = c8_s;
  c8_c_ix0 = c8_b_ix0;
  c8_c_iy0 = c8_b_iy0;
  c8_c_c = c8_b_c;
  c8_c_s = c8_b_s;
  c8_ix = c8_c_ix0;
  c8_iy = c8_c_iy0;
  for (c8_k = 1; c8_k < 3; c8_k++) {
    c8_b_a = c8_c_c;
    c8_b = c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c8_ix), 1, 4, 1, 0) - 1];
    c8_y = c8_b_a * c8_b;
    c8_c_a = c8_c_s;
    c8_b_b = c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c8_iy), 1, 4, 1, 0) - 1];
    c8_b_y = c8_c_a * c8_b_b;
    c8_temp = c8_y + c8_b_y;
    c8_d_a = c8_c_c;
    c8_c_b = c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c8_iy), 1, 4, 1, 0) - 1];
    c8_c_y = c8_d_a * c8_c_b;
    c8_e_a = c8_c_s;
    c8_d_b = c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c8_ix), 1, 4, 1, 0) - 1];
    c8_d_y = c8_e_a * c8_d_b;
    c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c8_iy), 1, 4, 1, 0) - 1] = c8_c_y - c8_d_y;
    c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c8_ix), 1, 4, 1, 0) - 1] = c8_temp;
    c8_f_a = c8_iy + 1;
    c8_iy = c8_f_a;
    c8_g_a = c8_ix + 1;
    c8_ix = c8_g_a;
  }
}

static void c8_d_eml_xrot(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_x[6], int32_T c8_ix0, int32_T c8_iy0, real_T c8_c, real_T c8_s)
{
  int32_T c8_b_ix0;
  int32_T c8_b_iy0;
  real_T c8_b_c;
  real_T c8_b_s;
  int32_T c8_c_ix0;
  int32_T c8_c_iy0;
  real_T c8_c_c;
  real_T c8_c_s;
  int32_T c8_ix;
  int32_T c8_iy;
  int32_T c8_k;
  real_T c8_b_a;
  real_T c8_b;
  real_T c8_y;
  real_T c8_c_a;
  real_T c8_b_b;
  real_T c8_b_y;
  real_T c8_temp;
  real_T c8_d_a;
  real_T c8_c_b;
  real_T c8_c_y;
  real_T c8_e_a;
  real_T c8_d_b;
  real_T c8_d_y;
  int32_T c8_f_a;
  int32_T c8_g_a;
  c8_b_ix0 = c8_ix0;
  c8_b_iy0 = c8_iy0;
  c8_b_c = c8_c;
  c8_b_s = c8_s;
  c8_c_ix0 = c8_b_ix0;
  c8_c_iy0 = c8_b_iy0;
  c8_c_c = c8_b_c;
  c8_c_s = c8_b_s;
  c8_ix = c8_c_ix0;
  c8_iy = c8_c_iy0;
  for (c8_k = 1; c8_k < 4; c8_k++) {
    c8_b_a = c8_c_c;
    c8_b = c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c8_ix), 1, 6, 1, 0) - 1];
    c8_y = c8_b_a * c8_b;
    c8_c_a = c8_c_s;
    c8_b_b = c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c8_iy), 1, 6, 1, 0) - 1];
    c8_b_y = c8_c_a * c8_b_b;
    c8_temp = c8_y + c8_b_y;
    c8_d_a = c8_c_c;
    c8_c_b = c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c8_iy), 1, 6, 1, 0) - 1];
    c8_c_y = c8_d_a * c8_c_b;
    c8_e_a = c8_c_s;
    c8_d_b = c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c8_ix), 1, 6, 1, 0) - 1];
    c8_d_y = c8_e_a * c8_d_b;
    c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c8_iy), 1, 6, 1, 0) - 1] = c8_c_y - c8_d_y;
    c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c8_ix), 1, 6, 1, 0) - 1] = c8_temp;
    c8_f_a = c8_iy + 1;
    c8_iy = c8_f_a;
    c8_g_a = c8_ix + 1;
    c8_ix = c8_g_a;
  }
}

static void c8_c_eml_xswap(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_x[4], int32_T c8_ix0, int32_T c8_iy0)
{
  int32_T c8_b_ix0;
  int32_T c8_b_iy0;
  int32_T c8_c_ix0;
  int32_T c8_c_iy0;
  int32_T c8_ix;
  int32_T c8_iy;
  int32_T c8_k;
  real_T c8_temp;
  int32_T c8_b_a;
  int32_T c8_c_a;
  c8_b_ix0 = c8_ix0;
  c8_b_iy0 = c8_iy0;
  c8_below_threshold(chartInstance);
  c8_c_ix0 = c8_b_ix0;
  c8_c_iy0 = c8_b_iy0;
  c8_ix = c8_c_ix0;
  c8_iy = c8_c_iy0;
  for (c8_k = 1; c8_k < 3; c8_k++) {
    c8_temp = c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c8_ix), 1, 4, 1, 0) - 1];
    c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c8_ix), 1, 4, 1, 0) - 1] = c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c8_iy), 1, 4, 1, 0) - 1];
    c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c8_iy), 1, 4, 1, 0) - 1] = c8_temp;
    c8_b_a = c8_ix + 1;
    c8_ix = c8_b_a;
    c8_c_a = c8_iy + 1;
    c8_iy = c8_c_a;
  }
}

static void c8_d_eml_xswap(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_x[6], int32_T c8_ix0, int32_T c8_iy0)
{
  int32_T c8_b_ix0;
  int32_T c8_b_iy0;
  int32_T c8_c_ix0;
  int32_T c8_c_iy0;
  int32_T c8_ix;
  int32_T c8_iy;
  int32_T c8_k;
  real_T c8_temp;
  int32_T c8_b_a;
  int32_T c8_c_a;
  c8_b_ix0 = c8_ix0;
  c8_b_iy0 = c8_iy0;
  c8_c_ix0 = c8_b_ix0;
  c8_c_iy0 = c8_b_iy0;
  c8_ix = c8_c_ix0;
  c8_iy = c8_c_iy0;
  for (c8_k = 1; c8_k < 4; c8_k++) {
    c8_temp = c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c8_ix), 1, 6, 1, 0) - 1];
    c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c8_ix), 1, 6, 1, 0) - 1] = c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c8_iy), 1, 6, 1, 0) - 1];
    c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c8_iy), 1, 6, 1, 0) - 1] = c8_temp;
    c8_b_a = c8_ix + 1;
    c8_ix = c8_b_a;
    c8_c_a = c8_iy + 1;
    c8_iy = c8_c_a;
  }
}

static void c8_c_eml_xgemm(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_k, real_T c8_A[4], real_T c8_B[6], real_T c8_C[6])
{
  int32_T c8_b_k;
  int32_T c8_c_k;
  int32_T c8_b_a;
  int32_T c8_km1;
  int32_T c8_cr;
  int32_T c8_b_cr;
  int32_T c8_c_a;
  int32_T c8_i217;
  int32_T c8_d_a;
  int32_T c8_i218;
  int32_T c8_e_a;
  int32_T c8_b;
  int32_T c8_f_a;
  int32_T c8_b_b;
  boolean_T c8_overflow;
  int32_T c8_ic;
  int32_T c8_b_ic;
  int32_T c8_br;
  int32_T c8_c_cr;
  int32_T c8_ar;
  int32_T c8_g_a;
  int32_T c8_b_br;
  int32_T c8_c_b;
  int32_T c8_c;
  int32_T c8_h_a;
  int32_T c8_d_b;
  int32_T c8_i219;
  int32_T c8_i_a;
  int32_T c8_e_b;
  int32_T c8_j_a;
  int32_T c8_f_b;
  boolean_T c8_b_overflow;
  int32_T c8_ib;
  int32_T c8_b_ib;
  real_T c8_temp;
  int32_T c8_ia;
  int32_T c8_k_a;
  int32_T c8_i220;
  int32_T c8_l_a;
  int32_T c8_i221;
  int32_T c8_m_a;
  int32_T c8_g_b;
  int32_T c8_n_a;
  int32_T c8_h_b;
  boolean_T c8_c_overflow;
  int32_T c8_c_ic;
  int32_T c8_o_a;
  int32_T c8_p_a;
  c8_b_k = c8_k;
  c8_c_k = c8_b_k;
  c8_b_a = c8_c_k;
  c8_km1 = c8_b_a;
  for (c8_cr = 0; c8_cr < 5; c8_cr += 2) {
    c8_b_cr = c8_cr;
    c8_c_a = c8_b_cr + 1;
    c8_i217 = c8_c_a;
    c8_d_a = c8_b_cr + 2;
    c8_i218 = c8_d_a;
    c8_e_a = c8_i217;
    c8_b = c8_i218;
    c8_f_a = c8_e_a;
    c8_b_b = c8_b;
    if (c8_f_a > c8_b_b) {
      c8_overflow = FALSE;
    } else {
      c8_overflow = (c8_b_b > 2147483646);
    }

    if (c8_overflow) {
      c8_check_forloop_overflow_error(chartInstance, c8_overflow);
    }

    for (c8_ic = c8_i217; c8_ic <= c8_i218; c8_ic++) {
      c8_b_ic = c8_ic;
      c8_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c8_b_ic), 1, 6, 1, 0) - 1] = 0.0;
    }
  }

  c8_br = 0;
  for (c8_c_cr = 0; c8_c_cr < 5; c8_c_cr += 2) {
    c8_b_cr = c8_c_cr;
    c8_ar = 0;
    c8_g_a = c8_br + 1;
    c8_br = c8_g_a;
    c8_b_br = c8_br;
    c8_c_b = c8_km1 - 1;
    c8_c = 3 * c8_c_b;
    c8_h_a = c8_br;
    c8_d_b = c8_c;
    c8_i219 = c8_h_a + c8_d_b;
    c8_i_a = c8_b_br;
    c8_e_b = c8_i219;
    c8_j_a = c8_i_a;
    c8_f_b = c8_e_b;
    if (c8_j_a > c8_f_b) {
      c8_b_overflow = FALSE;
    } else {
      c8_b_overflow = (c8_f_b > 2147483644);
    }

    if (c8_b_overflow) {
      c8_check_forloop_overflow_error(chartInstance, c8_b_overflow);
    }

    for (c8_ib = c8_b_br; c8_ib <= c8_i219; c8_ib += 3) {
      c8_b_ib = c8_ib;
      if (c8_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_ib), 1, 6, 1, 0) - 1] != 0.0) {
        c8_temp = c8_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c8_b_ib), 1, 6, 1, 0) - 1];
        c8_ia = c8_ar;
        c8_k_a = c8_b_cr + 1;
        c8_i220 = c8_k_a;
        c8_l_a = c8_b_cr + 2;
        c8_i221 = c8_l_a;
        c8_m_a = c8_i220;
        c8_g_b = c8_i221;
        c8_n_a = c8_m_a;
        c8_h_b = c8_g_b;
        if (c8_n_a > c8_h_b) {
          c8_c_overflow = FALSE;
        } else {
          c8_c_overflow = (c8_h_b > 2147483646);
        }

        if (c8_c_overflow) {
          c8_check_forloop_overflow_error(chartInstance, c8_c_overflow);
        }

        for (c8_c_ic = c8_i220; c8_c_ic <= c8_i221; c8_c_ic++) {
          c8_b_ic = c8_c_ic;
          c8_o_a = c8_ia + 1;
          c8_ia = c8_o_a;
          c8_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_ic), 1, 6, 1, 0) - 1] =
            c8_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_ic), 1, 6, 1, 0) - 1] + c8_temp *
            c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_ia), 1, 4, 1, 0) - 1];
        }
      }

      c8_p_a = c8_ar + 2;
      c8_ar = c8_p_a;
    }
  }
}

static void c8_l_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[6])
{
  real_T c8_c_a;
  real_T c8_d_a;
  int32_T c8_k;
  int32_T c8_b_k;
  c8_c_a = c8_b_a;
  c8_d_a = c8_c_a;
  for (c8_k = 1; c8_k < 3; c8_k++) {
    c8_b_k = c8_k;
    c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c8_b_k), 1, 6, 1, 0) - 1] = c8_d_a * c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 6, 1, 0) - 1];
  }
}

static void c8_m_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_y[6], int32_T c8_iy0)
{
  real_T c8_c_a;
  int32_T c8_b_iy0;
  real_T c8_d_a;
  int32_T c8_c_iy0;
  int32_T c8_ix;
  int32_T c8_e_a;
  int32_T c8_iy;
  int32_T c8_k;
  int32_T c8_f_a;
  int32_T c8_c;
  int32_T c8_g_a;
  int32_T c8_b_c;
  int32_T c8_h_a;
  int32_T c8_c_c;
  int32_T c8_i_a;
  int32_T c8_j_a;
  c8_c_a = c8_b_a;
  c8_b_iy0 = c8_iy0;
  c8_d_a = c8_c_a;
  c8_c_iy0 = c8_b_iy0;
  if (c8_d_a == 0.0) {
  } else {
    c8_ix = 0;
    c8_e_a = c8_c_iy0 - 1;
    c8_iy = c8_e_a;
    for (c8_k = 0; c8_k < 2; c8_k++) {
      c8_f_a = c8_iy;
      c8_c = c8_f_a;
      c8_g_a = c8_iy;
      c8_b_c = c8_g_a;
      c8_h_a = c8_ix;
      c8_c_c = c8_h_a;
      c8_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c8_c + 1)), 1, 6, 1, 0) - 1] = c8_y[_SFD_EML_ARRAY_BOUNDS_CHECK
        ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c8_b_c + 1)), 1, 6, 1, 0)
        - 1] + c8_d_a * c8_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)(c8_c_c + 1)), 1, 6, 1, 0) - 1];
      c8_i_a = c8_ix + 1;
      c8_ix = c8_i_a;
      c8_j_a = c8_iy + 1;
      c8_iy = c8_j_a;
    }
  }
}

static void c8_m_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[3])
{
  real_T c8_c_a;
  real_T c8_d_a;
  int32_T c8_k;
  int32_T c8_b_k;
  c8_c_a = c8_b_a;
  c8_d_a = c8_c_a;
  for (c8_k = 2; c8_k < 4; c8_k++) {
    c8_b_k = c8_k;
    c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c8_b_k), 1, 3, 1, 0) - 1] = c8_d_a * c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 3, 1, 0) - 1];
  }
}

static void c8_n_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[6], int32_T c8_ix0, real_T c8_y[2])
{
  real_T c8_c_a;
  int32_T c8_b_ix0;
  real_T c8_d_a;
  int32_T c8_c_ix0;
  int32_T c8_e_a;
  int32_T c8_ix;
  int32_T c8_f_a;
  int32_T c8_c;
  c8_c_a = c8_b_a;
  c8_b_ix0 = c8_ix0;
  c8_d_a = c8_c_a;
  c8_c_ix0 = c8_b_ix0;
  if (c8_d_a == 0.0) {
  } else {
    c8_e_a = c8_c_ix0;
    c8_ix = c8_e_a;
    c8_f_a = c8_ix - 1;
    c8_c = c8_f_a;
    c8_y[1] += c8_d_a * c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)(c8_c + 1)), 1, 6, 1, 0) - 1];
  }
}

static void c8_o_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[2], real_T c8_y[6], int32_T c8_iy0)
{
  real_T c8_c_a;
  int32_T c8_b_iy0;
  real_T c8_d_a;
  int32_T c8_c_iy0;
  int32_T c8_e_a;
  int32_T c8_iy;
  int32_T c8_f_a;
  int32_T c8_c;
  int32_T c8_g_a;
  int32_T c8_b_c;
  c8_c_a = c8_b_a;
  c8_b_iy0 = c8_iy0;
  c8_d_a = c8_c_a;
  c8_c_iy0 = c8_b_iy0;
  if (c8_d_a == 0.0) {
  } else {
    c8_e_a = c8_c_iy0 - 1;
    c8_iy = c8_e_a;
    c8_f_a = c8_iy;
    c8_c = c8_f_a;
    c8_g_a = c8_iy;
    c8_b_c = c8_g_a;
    c8_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
                                      (c8_c + 1)), 1, 6, 1, 0) - 1] =
      c8_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)(c8_b_c + 1)), 1, 6, 1, 0) - 1] + c8_d_a * c8_x[1];
  }
}

static void c8_n_eml_xscal(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_x[4])
{
  real_T c8_c_a;
  real_T c8_d_a;
  int32_T c8_k;
  int32_T c8_b_k;
  c8_c_a = c8_b_a;
  c8_b_below_threshold(chartInstance);
  c8_d_a = c8_c_a;
  for (c8_k = 1; c8_k < 3; c8_k++) {
    c8_b_k = c8_k;
    c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c8_b_k), 1, 4, 1, 0) - 1] = c8_d_a * c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_k), 1, 4, 1, 0) - 1];
  }
}

static void c8_p_eml_xaxpy(SFc8_CusakisME4901InstanceStruct *chartInstance,
  real_T c8_b_a, real_T c8_y[4])
{
  real_T c8_c_a;
  real_T c8_d_a;
  int32_T c8_ix;
  int32_T c8_iy;
  int32_T c8_k;
  int32_T c8_e_a;
  int32_T c8_c;
  int32_T c8_f_a;
  int32_T c8_b_c;
  int32_T c8_g_a;
  int32_T c8_c_c;
  int32_T c8_h_a;
  int32_T c8_i_a;
  c8_c_a = c8_b_a;
  c8_d_a = c8_c_a;
  if (c8_d_a == 0.0) {
  } else {
    c8_ix = 0;
    c8_iy = 2;
    for (c8_k = 0; c8_k < 2; c8_k++) {
      c8_e_a = c8_iy;
      c8_c = c8_e_a;
      c8_f_a = c8_iy;
      c8_b_c = c8_f_a;
      c8_g_a = c8_ix;
      c8_c_c = c8_g_a;
      c8_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c8_c + 1)), 1, 4, 1, 0) - 1] = c8_y[_SFD_EML_ARRAY_BOUNDS_CHECK
        ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c8_b_c + 1)), 1, 4, 1, 0)
        - 1] + c8_d_a * c8_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)(c8_c_c + 1)), 1, 4, 1, 0) - 1];
      c8_h_a = c8_ix + 1;
      c8_ix = c8_h_a;
      c8_i_a = c8_iy + 1;
      c8_iy = c8_i_a;
    }
  }
}

static void c8_d_eml_xgemm(SFc8_CusakisME4901InstanceStruct *chartInstance,
  int32_T c8_k, real_T c8_A[4], real_T c8_B[4], real_T c8_C[4])
{
  int32_T c8_b_k;
  int32_T c8_c_k;
  int32_T c8_b_a;
  int32_T c8_km1;
  int32_T c8_cr;
  int32_T c8_b_cr;
  int32_T c8_c_a;
  int32_T c8_i222;
  int32_T c8_d_a;
  int32_T c8_i223;
  int32_T c8_e_a;
  int32_T c8_b;
  int32_T c8_f_a;
  int32_T c8_b_b;
  boolean_T c8_overflow;
  int32_T c8_ic;
  int32_T c8_b_ic;
  int32_T c8_br;
  int32_T c8_c_cr;
  int32_T c8_ar;
  int32_T c8_g_a;
  int32_T c8_b_br;
  int32_T c8_c_b;
  int32_T c8_c;
  int32_T c8_h_a;
  int32_T c8_d_b;
  int32_T c8_i224;
  int32_T c8_i_a;
  int32_T c8_e_b;
  int32_T c8_j_a;
  int32_T c8_f_b;
  boolean_T c8_b_overflow;
  int32_T c8_ib;
  int32_T c8_b_ib;
  real_T c8_temp;
  int32_T c8_ia;
  int32_T c8_k_a;
  int32_T c8_i225;
  int32_T c8_l_a;
  int32_T c8_i226;
  int32_T c8_m_a;
  int32_T c8_g_b;
  int32_T c8_n_a;
  int32_T c8_h_b;
  boolean_T c8_c_overflow;
  int32_T c8_c_ic;
  int32_T c8_o_a;
  int32_T c8_p_a;
  c8_b_k = c8_k;
  c8_c_k = c8_b_k;
  c8_b_a = c8_c_k;
  c8_km1 = c8_b_a;
  for (c8_cr = 0; c8_cr < 3; c8_cr += 2) {
    c8_b_cr = c8_cr;
    c8_c_a = c8_b_cr + 1;
    c8_i222 = c8_c_a;
    c8_d_a = c8_b_cr + 2;
    c8_i223 = c8_d_a;
    c8_e_a = c8_i222;
    c8_b = c8_i223;
    c8_f_a = c8_e_a;
    c8_b_b = c8_b;
    if (c8_f_a > c8_b_b) {
      c8_overflow = FALSE;
    } else {
      c8_overflow = (c8_b_b > 2147483646);
    }

    if (c8_overflow) {
      c8_check_forloop_overflow_error(chartInstance, c8_overflow);
    }

    for (c8_ic = c8_i222; c8_ic <= c8_i223; c8_ic++) {
      c8_b_ic = c8_ic;
      c8_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c8_b_ic), 1, 4, 1, 0) - 1] = 0.0;
    }
  }

  c8_br = 0;
  for (c8_c_cr = 0; c8_c_cr < 3; c8_c_cr += 2) {
    c8_b_cr = c8_c_cr;
    c8_ar = 0;
    c8_g_a = c8_br + 1;
    c8_br = c8_g_a;
    c8_b_br = c8_br;
    c8_c_b = c8_km1 - 1;
    c8_c = c8_c_b << 1;
    c8_h_a = c8_br;
    c8_d_b = c8_c;
    c8_i224 = c8_h_a + c8_d_b;
    c8_i_a = c8_b_br;
    c8_e_b = c8_i224;
    c8_j_a = c8_i_a;
    c8_f_b = c8_e_b;
    if (c8_j_a > c8_f_b) {
      c8_b_overflow = FALSE;
    } else {
      c8_b_overflow = (c8_f_b > 2147483645);
    }

    if (c8_b_overflow) {
      c8_check_forloop_overflow_error(chartInstance, c8_b_overflow);
    }

    for (c8_ib = c8_b_br; c8_ib <= c8_i224; c8_ib += 2) {
      c8_b_ib = c8_ib;
      if (c8_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_ib), 1, 4, 1, 0) - 1] != 0.0) {
        c8_temp = c8_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c8_b_ib), 1, 4, 1, 0) - 1];
        c8_ia = c8_ar;
        c8_k_a = c8_b_cr + 1;
        c8_i225 = c8_k_a;
        c8_l_a = c8_b_cr + 2;
        c8_i226 = c8_l_a;
        c8_m_a = c8_i225;
        c8_g_b = c8_i226;
        c8_n_a = c8_m_a;
        c8_h_b = c8_g_b;
        if (c8_n_a > c8_h_b) {
          c8_c_overflow = FALSE;
        } else {
          c8_c_overflow = (c8_h_b > 2147483646);
        }

        if (c8_c_overflow) {
          c8_check_forloop_overflow_error(chartInstance, c8_c_overflow);
        }

        for (c8_c_ic = c8_i225; c8_c_ic <= c8_i226; c8_c_ic++) {
          c8_b_ic = c8_c_ic;
          c8_o_a = c8_ia + 1;
          c8_ia = c8_o_a;
          c8_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_ic), 1, 4, 1, 0) - 1] =
            c8_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_ic), 1, 4, 1, 0) - 1] + c8_temp *
            c8_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_ia), 1, 4, 1, 0) - 1];
        }
      }

      c8_p_a = c8_ar + 2;
      c8_ar = c8_p_a;
    }
  }
}

static void init_dsm_address_info(SFc8_CusakisME4901InstanceStruct
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

void sf_c8_CusakisME4901_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2138953973U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2716486869U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(924567679U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2559924286U);
}

mxArray *sf_c8_CusakisME4901_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("QVCDDrWtifw0pMBhZfWznH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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

mxArray *sf_c8_CusakisME4901_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c8_CusakisME4901(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[14],T\"W\",},{M[1],M[5],T\"qd_req\",},{M[1],M[17],T\"qd_reqW\",},{M[8],M[0],T\"is_active_c8_CusakisME4901\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_CusakisME4901_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_CusakisME4901InstanceStruct *chartInstance;
    chartInstance = (SFc8_CusakisME4901InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CusakisME4901MachineNumber_,
           8,
           1,
           1,
           8,
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
          init_script_number_translation(_CusakisME4901MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_CusakisME4901MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _CusakisME4901MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Ve");
          _SFD_SET_DATA_PROPS(1,1,1,0,"qqd");
          _SFD_SET_DATA_PROPS(2,2,0,1,"qd_req");
          _SFD_SET_DATA_PROPS(3,2,0,1,"qd_reqW");
          _SFD_SET_DATA_PROPS(4,10,0,0,"l");
          _SFD_SET_DATA_PROPS(5,10,0,0,"a");
          _SFD_SET_DATA_PROPS(6,2,0,1,"W");
          _SFD_SET_DATA_PROPS(7,1,1,0,"EE");
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
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,19961);
        _SFD_CV_INIT_EML_IF(0,1,0,617,627,649,19578);
        _SFD_CV_INIT_EML_IF(0,1,1,19828,19841,19852,19893);
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
            1.0,0,0,(MexFcnForType)c8_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)
            c8_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)
            c8_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)c8_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)c8_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)c8_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c8_W;
          real_T *c8_EE;
          real_T (*c8_Ve)[2];
          real_T (*c8_qqd)[9];
          real_T (*c8_qd_req)[3];
          real_T (*c8_qd_reqW)[3];
          c8_EE = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c8_W = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c8_qd_reqW = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c8_qd_req = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c8_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 1);
          c8_Ve = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c8_Ve);
          _SFD_SET_DATA_VALUE_PTR(1U, *c8_qqd);
          _SFD_SET_DATA_VALUE_PTR(2U, *c8_qd_req);
          _SFD_SET_DATA_VALUE_PTR(3U, *c8_qd_reqW);
          _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c8_l);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c8_a);
          _SFD_SET_DATA_VALUE_PTR(6U, c8_W);
          _SFD_SET_DATA_VALUE_PTR(7U, c8_EE);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _CusakisME4901MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "g0F4d1bNcO6HbbBF0es7bE";
}

static void sf_opaque_initialize_c8_CusakisME4901(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc8_CusakisME4901InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c8_CusakisME4901((SFc8_CusakisME4901InstanceStruct*)
    chartInstanceVar);
  initialize_c8_CusakisME4901((SFc8_CusakisME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c8_CusakisME4901(void *chartInstanceVar)
{
  enable_c8_CusakisME4901((SFc8_CusakisME4901InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c8_CusakisME4901(void *chartInstanceVar)
{
  disable_c8_CusakisME4901((SFc8_CusakisME4901InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c8_CusakisME4901(void *chartInstanceVar)
{
  sf_c8_CusakisME4901((SFc8_CusakisME4901InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c8_CusakisME4901(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c8_CusakisME4901
    ((SFc8_CusakisME4901InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_CusakisME4901();/* state var info */
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

extern void sf_internal_set_sim_state_c8_CusakisME4901(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_CusakisME4901();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c8_CusakisME4901((SFc8_CusakisME4901InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c8_CusakisME4901(SimStruct* S)
{
  return sf_internal_get_sim_state_c8_CusakisME4901(S);
}

static void sf_opaque_set_sim_state_c8_CusakisME4901(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c8_CusakisME4901(S, st);
}

static void sf_opaque_terminate_c8_CusakisME4901(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_CusakisME4901InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CusakisME4901_optimization_info();
    }

    finalize_c8_CusakisME4901((SFc8_CusakisME4901InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_CusakisME4901((SFc8_CusakisME4901InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_CusakisME4901(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_CusakisME4901((SFc8_CusakisME4901InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c8_CusakisME4901(SimStruct *S)
{
  /* Actual parameters from chart:
     a l
   */
  const char_T *rtParamNames[] = { "a", "l" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for a*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for l*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CusakisME4901_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,8,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,8,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,8);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,8,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,8,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(497149363U));
  ssSetChecksum1(S,(4233209474U));
  ssSetChecksum2(S,(1510491720U));
  ssSetChecksum3(S,(656630108U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c8_CusakisME4901(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_CusakisME4901(SimStruct *S)
{
  SFc8_CusakisME4901InstanceStruct *chartInstance;
  chartInstance = (SFc8_CusakisME4901InstanceStruct *)utMalloc(sizeof
    (SFc8_CusakisME4901InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc8_CusakisME4901InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c8_CusakisME4901;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_CusakisME4901;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c8_CusakisME4901;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c8_CusakisME4901;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c8_CusakisME4901;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_CusakisME4901;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_CusakisME4901;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_CusakisME4901;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_CusakisME4901;
  chartInstance->chartInfo.mdlStart = mdlStart_c8_CusakisME4901;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c8_CusakisME4901;
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

void c8_CusakisME4901_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_CusakisME4901(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_CusakisME4901(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_CusakisME4901(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_CusakisME4901_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
