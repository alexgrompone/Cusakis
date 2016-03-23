/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CusakisME4901arcs_sfun.h"
#include "c20_CusakisME4901arcs.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CusakisME4901arcs_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c20_debug_family_names[35] = { "q1", "q2", "q3", "qd1",
  "qd2", "qd3", "base_x", "base_y", "bth", "Hb", "Hbm", "Jm", "Jb", "EE",
  "invJstar", "A", "lambmax", "Sigma", "lamb2", "nargin", "nargout", "qqd",
  "q3rd", "Ve", "SC", "l", "m", "I", "lb", "mb", "Ib", "qd_req", "qd_reqW",
  "Jstar", "SCnew" };

/* Function Declarations */
static void initialize_c20_CusakisME4901arcs
  (SFc20_CusakisME4901arcsInstanceStruct *chartInstance);
static void initialize_params_c20_CusakisME4901arcs
  (SFc20_CusakisME4901arcsInstanceStruct *chartInstance);
static void enable_c20_CusakisME4901arcs(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void disable_c20_CusakisME4901arcs(SFc20_CusakisME4901arcsInstanceStruct *
  chartInstance);
static void c20_update_debugger_state_c20_CusakisME4901arcs
  (SFc20_CusakisME4901arcsInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c20_CusakisME4901arcs
  (SFc20_CusakisME4901arcsInstanceStruct *chartInstance);
static void set_sim_state_c20_CusakisME4901arcs
  (SFc20_CusakisME4901arcsInstanceStruct *chartInstance, const mxArray *c20_st);
static void finalize_c20_CusakisME4901arcs(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void sf_c20_CusakisME4901arcs(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void c20_chartstep_c20_CusakisME4901arcs
  (SFc20_CusakisME4901arcsInstanceStruct *chartInstance);
static void initSimStructsc20_CusakisME4901arcs
  (SFc20_CusakisME4901arcsInstanceStruct *chartInstance);
static void registerMessagesc20_CusakisME4901arcs
  (SFc20_CusakisME4901arcsInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber);
static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static void c20_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_SCnew, const char_T *c20_identifier, real_T
  c20_y[6]);
static void c20_b_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[6]);
static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static void c20_c_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_Jstar, const char_T *c20_identifier, real_T
  c20_y[18]);
static void c20_d_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[18]);
static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static void c20_e_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_qd_reqW, const char_T *c20_identifier,
  real_T c20_y[3]);
static void c20_f_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[3]);
static void c20_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_d_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static real_T c20_g_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_e_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static const mxArray *c20_f_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static void c20_h_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[18]);
static void c20_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_g_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static void c20_i_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[36]);
static void c20_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static void c20_info_helper(c20_ResolvedFunctionInfo c20_info[281]);
static void c20_b_info_helper(c20_ResolvedFunctionInfo c20_info[281]);
static void c20_c_info_helper(c20_ResolvedFunctionInfo c20_info[281]);
static void c20_d_info_helper(c20_ResolvedFunctionInfo c20_info[281]);
static void c20_e_info_helper(c20_ResolvedFunctionInfo c20_info[281]);
static real_T c20_eml_div(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x, real_T c20_y);
static real_T c20_mpower(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_a);
static void c20_eml_scalar_eg(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void c20_inv(SFc20_CusakisME4901arcsInstanceStruct *chartInstance, real_T
                    c20_x[36], real_T c20_y[36]);
static void c20_invNxN(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[36], real_T c20_y[36]);
static void c20_realmin(SFc20_CusakisME4901arcsInstanceStruct *chartInstance);
static void c20_eps(SFc20_CusakisME4901arcsInstanceStruct *chartInstance);
static void c20_eml_matlab_zgetrf(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, real_T c20_A[36], real_T c20_b_A[36], int32_T c20_ipiv[6],
  int32_T *c20_info);
static real_T c20_abs(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
                      real_T c20_x);
static void c20_check_forloop_overflow_error
  (SFc20_CusakisME4901arcsInstanceStruct *chartInstance, boolean_T c20_overflow);
static void c20_below_threshold(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void c20_eml_xger(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_b_m, int32_T c20_n, real_T c20_alpha1, int32_T c20_ix0, int32_T
  c20_iy0, real_T c20_A[36], int32_T c20_ia0, real_T c20_b_A[36]);
static void c20_b_eml_scalar_eg(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void c20_eml_xtrsm(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_A[36], real_T c20_B[36], real_T c20_b_B[36]);
static real_T c20_norm(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[36]);
static void c20_eml_warning(SFc20_CusakisME4901arcsInstanceStruct *chartInstance);
static void c20_b_eml_warning(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, char_T c20_varargin_2[14]);
static void c20_c_eml_scalar_eg(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void c20_d_eml_scalar_eg(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void c20_e_eml_scalar_eg(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void c20_f_eml_scalar_eg(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void c20_pinv(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
                     real_T c20_A[18], real_T c20_X[18]);
static void c20_eml_error(SFc20_CusakisME4901arcsInstanceStruct *chartInstance);
static void c20_eml_xgesvd(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_A[18], real_T c20_U[18], real_T c20_S[3], real_T c20_V[9]);
static real_T c20_eml_xnrm2(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_x[18], int32_T c20_ix0);
static void c20_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[18], int32_T c20_ix0, real_T
  c20_b_x[18]);
static real_T c20_eml_xdotc(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_x[18], int32_T c20_ix0, real_T c20_y[18], int32_T
  c20_iy0);
static void c20_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, int32_T c20_ix0, real_T c20_y[18], int32_T
  c20_iy0, real_T c20_b_y[18]);
static real_T c20_b_eml_xnrm2(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, int32_T c20_n, real_T c20_x[3], int32_T c20_ix0);
static void c20_b_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[3], int32_T c20_ix0, real_T c20_b_x
  [3]);
static void c20_b_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[18], int32_T c20_ix0, real_T c20_y[6],
  int32_T c20_iy0, real_T c20_b_y[6]);
static void c20_c_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[6], int32_T c20_ix0, real_T c20_y[18],
  int32_T c20_iy0, real_T c20_b_y[18]);
static real_T c20_b_eml_xdotc(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, int32_T c20_n, real_T c20_x[9], int32_T c20_ix0, real_T c20_y
  [9], int32_T c20_iy0);
static void c20_d_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, int32_T c20_ix0, real_T c20_y[9], int32_T c20_iy0,
  real_T c20_b_y[9]);
static void c20_g_eml_scalar_eg(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void c20_c_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_a, real_T c20_x[18], int32_T c20_ix0, real_T c20_b_x[18]);
static void c20_d_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_a, real_T c20_x[9], int32_T c20_ix0, real_T c20_b_x[9]);
static void c20_b_eml_error(SFc20_CusakisME4901arcsInstanceStruct *chartInstance);
static real_T c20_sqrt(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x);
static void c20_c_eml_error(SFc20_CusakisME4901arcsInstanceStruct *chartInstance);
static void c20_eml_xrotg(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_a, real_T c20_b, real_T *c20_b_a, real_T *c20_b_b, real_T *c20_c,
  real_T *c20_s);
static void c20_eml_xrot(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[9], int32_T c20_ix0, int32_T c20_iy0, real_T c20_c, real_T c20_s,
  real_T c20_b_x[9]);
static void c20_b_eml_xrot(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[18], int32_T c20_ix0, int32_T c20_iy0, real_T c20_c, real_T c20_s,
  real_T c20_b_x[18]);
static void c20_eml_xswap(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[9], int32_T c20_ix0, int32_T c20_iy0, real_T c20_b_x[9]);
static void c20_b_eml_xswap(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[18], int32_T c20_ix0, int32_T c20_iy0, real_T c20_b_x[18]);
static void c20_eml_xgemm(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_k, real_T c20_A[9], real_T c20_B[18], real_T c20_C[18], real_T
  c20_b_C[18]);
static void c20_h_eml_scalar_eg(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void c20_svd(SFc20_CusakisME4901arcsInstanceStruct *chartInstance, real_T
                    c20_A[18], real_T c20_U[3]);
static void c20_eml_matlab_zsvdc(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, real_T c20_A[18], real_T c20_S[3]);
static void c20_i_eml_scalar_eg(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void c20_b_pinv(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_A[36], real_T c20_X[36]);
static void c20_b_eml_xgesvd(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, real_T c20_A[36], real_T c20_U[36], real_T c20_S[6], real_T
  c20_V[36]);
static real_T c20_c_eml_xnrm2(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, int32_T c20_n, real_T c20_x[36], int32_T c20_ix0);
static void c20_e_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[36], int32_T c20_ix0, real_T
  c20_b_x[36]);
static real_T c20_c_eml_xdotc(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, int32_T c20_n, real_T c20_x[36], int32_T c20_ix0, real_T
  c20_y[36], int32_T c20_iy0);
static void c20_e_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, int32_T c20_ix0, real_T c20_y[36], int32_T
  c20_iy0, real_T c20_b_y[36]);
static real_T c20_d_eml_xnrm2(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, int32_T c20_n, real_T c20_x[6], int32_T c20_ix0);
static void c20_f_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[6], int32_T c20_ix0, real_T c20_b_x
  [6]);
static void c20_f_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[36], int32_T c20_ix0, real_T c20_y[6],
  int32_T c20_iy0, real_T c20_b_y[6]);
static void c20_g_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[6], int32_T c20_ix0, real_T c20_y[36],
  int32_T c20_iy0, real_T c20_b_y[36]);
static void c20_g_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_a, real_T c20_x[36], int32_T c20_ix0, real_T c20_b_x[36]);
static void c20_c_eml_xrot(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[36], int32_T c20_ix0, int32_T c20_iy0, real_T c20_c, real_T c20_s,
  real_T c20_b_x[36]);
static void c20_c_eml_xswap(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[36], int32_T c20_ix0, int32_T c20_iy0, real_T c20_b_x[36]);
static void c20_b_eml_xgemm(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_k, real_T c20_A[36], real_T c20_B[36], real_T c20_C[36], real_T
  c20_b_C[36]);
static void c20_j_eml_scalar_eg(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void c20_j_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_sprintf, const char_T *c20_identifier,
  char_T c20_y[14]);
static void c20_k_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  char_T c20_y[14]);
static const mxArray *c20_h_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static int32_T c20_l_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static uint8_T c20_m_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_b_is_active_c20_CusakisME4901arcs, const
  char_T *c20_identifier);
static uint8_T c20_n_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_b_eml_matlab_zgetrf(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, real_T c20_A[36], int32_T c20_ipiv[6], int32_T *c20_info);
static void c20_b_eml_xger(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_b_m, int32_T c20_n, real_T c20_alpha1, int32_T c20_ix0, int32_T
  c20_iy0, real_T c20_A[36], int32_T c20_ia0);
static void c20_b_eml_xtrsm(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_A[36], real_T c20_B[36]);
static void c20_h_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[18], int32_T c20_ix0);
static void c20_h_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, int32_T c20_ix0, real_T c20_y[18], int32_T
  c20_iy0);
static void c20_i_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[3], int32_T c20_ix0);
static void c20_i_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[18], int32_T c20_ix0, real_T c20_y[6],
  int32_T c20_iy0);
static void c20_j_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[6], int32_T c20_ix0, real_T c20_y[18],
  int32_T c20_iy0);
static void c20_k_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, int32_T c20_ix0, real_T c20_y[9], int32_T c20_iy0);
static void c20_j_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_a, real_T c20_x[18], int32_T c20_ix0);
static void c20_k_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_a, real_T c20_x[9], int32_T c20_ix0);
static void c20_b_sqrt(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T *c20_x);
static void c20_b_eml_xrotg(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T *c20_a, real_T *c20_b, real_T *c20_c, real_T *c20_s);
static void c20_d_eml_xrot(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[9], int32_T c20_ix0, int32_T c20_iy0, real_T c20_c, real_T c20_s);
static void c20_e_eml_xrot(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[18], int32_T c20_ix0, int32_T c20_iy0, real_T c20_c, real_T c20_s);
static void c20_d_eml_xswap(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[9], int32_T c20_ix0, int32_T c20_iy0);
static void c20_e_eml_xswap(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[18], int32_T c20_ix0, int32_T c20_iy0);
static void c20_c_eml_xgemm(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_k, real_T c20_A[9], real_T c20_B[18], real_T c20_C[18]);
static void c20_l_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[36], int32_T c20_ix0);
static void c20_l_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, int32_T c20_ix0, real_T c20_y[36], int32_T
  c20_iy0);
static void c20_m_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[6], int32_T c20_ix0);
static void c20_m_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[36], int32_T c20_ix0, real_T c20_y[6],
  int32_T c20_iy0);
static void c20_n_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[6], int32_T c20_ix0, real_T c20_y[36],
  int32_T c20_iy0);
static void c20_n_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_a, real_T c20_x[36], int32_T c20_ix0);
static void c20_f_eml_xrot(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[36], int32_T c20_ix0, int32_T c20_iy0, real_T c20_c, real_T c20_s);
static void c20_f_eml_xswap(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[36], int32_T c20_ix0, int32_T c20_iy0);
static void c20_d_eml_xgemm(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_k, real_T c20_A[36], real_T c20_B[36], real_T c20_C[36]);
static void init_dsm_address_info(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c20_CusakisME4901arcs
  (SFc20_CusakisME4901arcsInstanceStruct *chartInstance)
{
  chartInstance->c20_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c20_is_active_c20_CusakisME4901arcs = 0U;
}

static void initialize_params_c20_CusakisME4901arcs
  (SFc20_CusakisME4901arcsInstanceStruct *chartInstance)
{
  real_T c20_d0;
  real_T c20_d1;
  real_T c20_d2;
  real_T c20_d3;
  real_T c20_d4;
  real_T c20_d5;
  sf_set_error_prefix_string(
    "Error evaluating data 'l' in the parent workspace.\n");
  sf_mex_import_named("l", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      &c20_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c20_l = c20_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'm' in the parent workspace.\n");
  sf_mex_import_named("m", sf_mex_get_sfun_param(chartInstance->S, 4, 0),
                      &c20_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c20_m = c20_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'I' in the parent workspace.\n");
  sf_mex_import_named("I", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c20_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c20_I = c20_d2;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'lb' in the parent workspace.\n");
  sf_mex_import_named("lb", sf_mex_get_sfun_param(chartInstance->S, 3, 0),
                      &c20_d3, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c20_lb = c20_d3;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'mb' in the parent workspace.\n");
  sf_mex_import_named("mb", sf_mex_get_sfun_param(chartInstance->S, 5, 0),
                      &c20_d4, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c20_mb = c20_d4;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'Ib' in the parent workspace.\n");
  sf_mex_import_named("Ib", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c20_d5, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c20_Ib = c20_d5;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c20_CusakisME4901arcs(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c20_CusakisME4901arcs(SFc20_CusakisME4901arcsInstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c20_update_debugger_state_c20_CusakisME4901arcs
  (SFc20_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c20_CusakisME4901arcs
  (SFc20_CusakisME4901arcsInstanceStruct *chartInstance)
{
  const mxArray *c20_st;
  const mxArray *c20_y = NULL;
  int32_T c20_i0;
  real_T c20_u[18];
  const mxArray *c20_b_y = NULL;
  int32_T c20_i1;
  real_T c20_b_u[6];
  const mxArray *c20_c_y = NULL;
  int32_T c20_i2;
  real_T c20_c_u[3];
  const mxArray *c20_d_y = NULL;
  int32_T c20_i3;
  real_T c20_d_u[3];
  const mxArray *c20_e_y = NULL;
  uint8_T c20_hoistedGlobal;
  uint8_T c20_e_u;
  const mxArray *c20_f_y = NULL;
  real_T (*c20_qd_reqW)[3];
  real_T (*c20_qd_req)[3];
  real_T (*c20_SCnew)[6];
  real_T (*c20_Jstar)[18];
  c20_SCnew = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 4);
  c20_Jstar = (real_T (*)[18])ssGetOutputPortSignal(chartInstance->S, 3);
  c20_qd_reqW = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c20_qd_req = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c20_st = NULL;
  c20_st = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_createcellarray(5), FALSE);
  for (c20_i0 = 0; c20_i0 < 18; c20_i0++) {
    c20_u[c20_i0] = (*c20_Jstar)[c20_i0];
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 2, 6, 3),
                FALSE);
  sf_mex_setcell(c20_y, 0, c20_b_y);
  for (c20_i1 = 0; c20_i1 < 6; c20_i1++) {
    c20_b_u[c20_i1] = (*c20_SCnew)[c20_i1];
  }

  c20_c_y = NULL;
  sf_mex_assign(&c20_c_y, sf_mex_create("y", c20_b_u, 0, 0U, 1U, 0U, 1, 6),
                FALSE);
  sf_mex_setcell(c20_y, 1, c20_c_y);
  for (c20_i2 = 0; c20_i2 < 3; c20_i2++) {
    c20_c_u[c20_i2] = (*c20_qd_req)[c20_i2];
  }

  c20_d_y = NULL;
  sf_mex_assign(&c20_d_y, sf_mex_create("y", c20_c_u, 0, 0U, 1U, 0U, 1, 3),
                FALSE);
  sf_mex_setcell(c20_y, 2, c20_d_y);
  for (c20_i3 = 0; c20_i3 < 3; c20_i3++) {
    c20_d_u[c20_i3] = (*c20_qd_reqW)[c20_i3];
  }

  c20_e_y = NULL;
  sf_mex_assign(&c20_e_y, sf_mex_create("y", c20_d_u, 0, 0U, 1U, 0U, 1, 3),
                FALSE);
  sf_mex_setcell(c20_y, 3, c20_e_y);
  c20_hoistedGlobal = chartInstance->c20_is_active_c20_CusakisME4901arcs;
  c20_e_u = c20_hoistedGlobal;
  c20_f_y = NULL;
  sf_mex_assign(&c20_f_y, sf_mex_create("y", &c20_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c20_y, 4, c20_f_y);
  sf_mex_assign(&c20_st, c20_y, FALSE);
  return c20_st;
}

static void set_sim_state_c20_CusakisME4901arcs
  (SFc20_CusakisME4901arcsInstanceStruct *chartInstance, const mxArray *c20_st)
{
  const mxArray *c20_u;
  real_T c20_dv0[18];
  int32_T c20_i4;
  real_T c20_dv1[6];
  int32_T c20_i5;
  real_T c20_dv2[3];
  int32_T c20_i6;
  real_T c20_dv3[3];
  int32_T c20_i7;
  real_T (*c20_Jstar)[18];
  real_T (*c20_SCnew)[6];
  real_T (*c20_qd_req)[3];
  real_T (*c20_qd_reqW)[3];
  c20_SCnew = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 4);
  c20_Jstar = (real_T (*)[18])ssGetOutputPortSignal(chartInstance->S, 3);
  c20_qd_reqW = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c20_qd_req = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c20_doneDoubleBufferReInit = TRUE;
  c20_u = sf_mex_dup(c20_st);
  c20_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 0)),
    "Jstar", c20_dv0);
  for (c20_i4 = 0; c20_i4 < 18; c20_i4++) {
    (*c20_Jstar)[c20_i4] = c20_dv0[c20_i4];
  }

  c20_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 1)),
                       "SCnew", c20_dv1);
  for (c20_i5 = 0; c20_i5 < 6; c20_i5++) {
    (*c20_SCnew)[c20_i5] = c20_dv1[c20_i5];
  }

  c20_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 2)),
    "qd_req", c20_dv2);
  for (c20_i6 = 0; c20_i6 < 3; c20_i6++) {
    (*c20_qd_req)[c20_i6] = c20_dv2[c20_i6];
  }

  c20_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 3)),
    "qd_reqW", c20_dv3);
  for (c20_i7 = 0; c20_i7 < 3; c20_i7++) {
    (*c20_qd_reqW)[c20_i7] = c20_dv3[c20_i7];
  }

  chartInstance->c20_is_active_c20_CusakisME4901arcs = c20_m_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 4)),
     "is_active_c20_CusakisME4901arcs");
  sf_mex_destroy(&c20_u);
  c20_update_debugger_state_c20_CusakisME4901arcs(chartInstance);
  sf_mex_destroy(&c20_st);
}

static void finalize_c20_CusakisME4901arcs(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
}

static void sf_c20_CusakisME4901arcs(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
  int32_T c20_i8;
  int32_T c20_i9;
  int32_T c20_i10;
  int32_T c20_i11;
  int32_T c20_i12;
  int32_T c20_i13;
  int32_T c20_i14;
  real_T *c20_q3rd;
  real_T (*c20_SCnew)[6];
  real_T (*c20_Jstar)[18];
  real_T (*c20_SC)[6];
  real_T (*c20_Ve)[6];
  real_T (*c20_qqd)[9];
  real_T (*c20_qd_reqW)[3];
  real_T (*c20_qd_req)[3];
  c20_SCnew = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 4);
  c20_Jstar = (real_T (*)[18])ssGetOutputPortSignal(chartInstance->S, 3);
  c20_SC = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 3);
  c20_Ve = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
  c20_q3rd = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c20_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  c20_qd_reqW = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c20_qd_req = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 19U, chartInstance->c20_sfEvent);
  for (c20_i8 = 0; c20_i8 < 3; c20_i8++) {
    _SFD_DATA_RANGE_CHECK((*c20_qd_req)[c20_i8], 0U);
  }

  for (c20_i9 = 0; c20_i9 < 3; c20_i9++) {
    _SFD_DATA_RANGE_CHECK((*c20_qd_reqW)[c20_i9], 1U);
  }

  for (c20_i10 = 0; c20_i10 < 9; c20_i10++) {
    _SFD_DATA_RANGE_CHECK((*c20_qqd)[c20_i10], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*c20_q3rd, 3U);
  for (c20_i11 = 0; c20_i11 < 6; c20_i11++) {
    _SFD_DATA_RANGE_CHECK((*c20_Ve)[c20_i11], 4U);
  }

  for (c20_i12 = 0; c20_i12 < 6; c20_i12++) {
    _SFD_DATA_RANGE_CHECK((*c20_SC)[c20_i12], 5U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c20_l, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c20_m, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c20_I, 8U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c20_lb, 9U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c20_mb, 10U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c20_Ib, 11U);
  for (c20_i13 = 0; c20_i13 < 18; c20_i13++) {
    _SFD_DATA_RANGE_CHECK((*c20_Jstar)[c20_i13], 12U);
  }

  for (c20_i14 = 0; c20_i14 < 6; c20_i14++) {
    _SFD_DATA_RANGE_CHECK((*c20_SCnew)[c20_i14], 13U);
  }

  chartInstance->c20_sfEvent = CALL_EVENT;
  c20_chartstep_c20_CusakisME4901arcs(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CusakisME4901arcsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c20_chartstep_c20_CusakisME4901arcs
  (SFc20_CusakisME4901arcsInstanceStruct *chartInstance)
{
  real_T c20_hoistedGlobal;
  real_T c20_b_hoistedGlobal;
  real_T c20_c_hoistedGlobal;
  real_T c20_d_hoistedGlobal;
  real_T c20_e_hoistedGlobal;
  real_T c20_f_hoistedGlobal;
  real_T c20_g_hoistedGlobal;
  int32_T c20_i15;
  real_T c20_qqd[9];
  real_T c20_q3rd;
  int32_T c20_i16;
  real_T c20_Ve[6];
  int32_T c20_i17;
  real_T c20_SC[6];
  real_T c20_b_l;
  real_T c20_b_m;
  real_T c20_b_I;
  real_T c20_b_lb;
  real_T c20_b_mb;
  real_T c20_b_Ib;
  uint32_T c20_debug_family_var_map[35];
  real_T c20_q1;
  real_T c20_q2;
  real_T c20_q3;
  real_T c20_qd1;
  real_T c20_qd2;
  real_T c20_qd3;
  real_T c20_base_x;
  real_T c20_base_y;
  real_T c20_bth;
  real_T c20_Hb[36];
  real_T c20_Hbm[18];
  real_T c20_Jm[18];
  real_T c20_Jb[36];
  real_T c20_EE[3];
  real_T c20_invJstar[18];
  real_T c20_A[3];
  real_T c20_lambmax;
  real_T c20_Sigma;
  real_T c20_lamb2;
  real_T c20_nargin = 10.0;
  real_T c20_nargout = 4.0;
  real_T c20_qd_req[3];
  real_T c20_qd_reqW[3];
  real_T c20_Jstar[18];
  real_T c20_SCnew[6];
  real_T c20_b;
  real_T c20_y;
  real_T c20_b_b;
  real_T c20_b_y;
  real_T c20_a;
  real_T c20_c_b;
  real_T c20_c_y;
  real_T c20_d_b;
  real_T c20_d_y;
  real_T c20_b_A;
  real_T c20_B;
  real_T c20_x;
  real_T c20_e_y;
  real_T c20_b_x;
  real_T c20_f_y;
  real_T c20_g_y;
  real_T c20_e_b;
  real_T c20_h_y;
  real_T c20_c_x;
  real_T c20_d_x;
  real_T c20_b_a;
  real_T c20_f_b;
  real_T c20_i_y;
  real_T c20_c_A;
  real_T c20_e_x;
  real_T c20_f_x;
  real_T c20_j_y;
  real_T c20_g_b;
  real_T c20_k_y;
  real_T c20_g_x;
  real_T c20_h_x;
  real_T c20_c_a;
  real_T c20_h_b;
  real_T c20_l_y;
  real_T c20_d_A;
  real_T c20_i_x;
  real_T c20_j_x;
  real_T c20_m_y;
  real_T c20_i_b;
  real_T c20_n_y;
  real_T c20_k_x;
  real_T c20_l_x;
  real_T c20_d_a;
  real_T c20_j_b;
  real_T c20_o_y;
  real_T c20_k_b;
  real_T c20_p_y;
  real_T c20_m_x;
  real_T c20_n_x;
  real_T c20_e_a;
  real_T c20_l_b;
  real_T c20_q_y;
  real_T c20_e_A;
  real_T c20_o_x;
  real_T c20_p_x;
  real_T c20_r_y;
  real_T c20_f_a;
  real_T c20_m_b;
  real_T c20_s_y;
  real_T c20_n_b;
  real_T c20_t_y;
  real_T c20_f_A;
  real_T c20_b_B;
  real_T c20_q_x;
  real_T c20_u_y;
  real_T c20_r_x;
  real_T c20_v_y;
  real_T c20_w_y;
  real_T c20_g_a;
  real_T c20_o_b;
  real_T c20_x_y;
  real_T c20_p_b;
  real_T c20_y_y;
  real_T c20_q_b;
  real_T c20_ab_y;
  real_T c20_h_a;
  real_T c20_r_b;
  real_T c20_bb_y;
  real_T c20_s_b;
  real_T c20_cb_y;
  real_T c20_g_A;
  real_T c20_c_B;
  real_T c20_s_x;
  real_T c20_db_y;
  real_T c20_t_x;
  real_T c20_eb_y;
  real_T c20_fb_y;
  real_T c20_t_b;
  real_T c20_gb_y;
  real_T c20_u_x;
  real_T c20_v_x;
  real_T c20_i_a;
  real_T c20_u_b;
  real_T c20_hb_y;
  real_T c20_h_A;
  real_T c20_w_x;
  real_T c20_x_x;
  real_T c20_ib_y;
  real_T c20_v_b;
  real_T c20_jb_y;
  real_T c20_y_x;
  real_T c20_ab_x;
  real_T c20_j_a;
  real_T c20_w_b;
  real_T c20_kb_y;
  real_T c20_i_A;
  real_T c20_bb_x;
  real_T c20_cb_x;
  real_T c20_lb_y;
  real_T c20_x_b;
  real_T c20_mb_y;
  real_T c20_db_x;
  real_T c20_eb_x;
  real_T c20_k_a;
  real_T c20_y_b;
  real_T c20_nb_y;
  real_T c20_ab_b;
  real_T c20_ob_y;
  real_T c20_fb_x;
  real_T c20_gb_x;
  real_T c20_l_a;
  real_T c20_bb_b;
  real_T c20_pb_y;
  real_T c20_j_A;
  real_T c20_hb_x;
  real_T c20_ib_x;
  real_T c20_qb_y;
  real_T c20_m_a;
  real_T c20_cb_b;
  real_T c20_rb_y;
  real_T c20_db_b;
  real_T c20_sb_y;
  real_T c20_k_A;
  real_T c20_d_B;
  real_T c20_jb_x;
  real_T c20_tb_y;
  real_T c20_kb_x;
  real_T c20_ub_y;
  real_T c20_vb_y;
  real_T c20_n_a;
  real_T c20_eb_b;
  real_T c20_wb_y;
  real_T c20_fb_b;
  real_T c20_xb_y;
  real_T c20_gb_b;
  real_T c20_yb_y;
  real_T c20_o_a;
  real_T c20_hb_b;
  real_T c20_ac_y;
  real_T c20_ib_b;
  real_T c20_bc_y;
  real_T c20_l_A;
  real_T c20_e_B;
  real_T c20_lb_x;
  real_T c20_cc_y;
  real_T c20_mb_x;
  real_T c20_dc_y;
  real_T c20_ec_y;
  real_T c20_jb_b;
  real_T c20_fc_y;
  real_T c20_nb_x;
  real_T c20_ob_x;
  real_T c20_p_a;
  real_T c20_kb_b;
  real_T c20_gc_y;
  real_T c20_m_A;
  real_T c20_pb_x;
  real_T c20_qb_x;
  real_T c20_hc_y;
  real_T c20_lb_b;
  real_T c20_ic_y;
  real_T c20_rb_x;
  real_T c20_sb_x;
  real_T c20_q_a;
  real_T c20_mb_b;
  real_T c20_jc_y;
  real_T c20_n_A;
  real_T c20_tb_x;
  real_T c20_ub_x;
  real_T c20_kc_y;
  real_T c20_nb_b;
  real_T c20_lc_y;
  real_T c20_vb_x;
  real_T c20_wb_x;
  real_T c20_r_a;
  real_T c20_ob_b;
  real_T c20_mc_y;
  real_T c20_pb_b;
  real_T c20_nc_y;
  real_T c20_xb_x;
  real_T c20_yb_x;
  real_T c20_s_a;
  real_T c20_qb_b;
  real_T c20_oc_y;
  real_T c20_o_A;
  real_T c20_ac_x;
  real_T c20_bc_x;
  real_T c20_pc_y;
  real_T c20_t_a;
  real_T c20_rb_b;
  real_T c20_qc_y;
  real_T c20_sb_b;
  real_T c20_rc_y;
  real_T c20_p_A;
  real_T c20_f_B;
  real_T c20_cc_x;
  real_T c20_sc_y;
  real_T c20_dc_x;
  real_T c20_tc_y;
  real_T c20_uc_y;
  real_T c20_u_a;
  real_T c20_tb_b;
  real_T c20_vc_y;
  real_T c20_ub_b;
  real_T c20_wc_y;
  real_T c20_v_a;
  real_T c20_vb_b;
  real_T c20_xc_y;
  real_T c20_wb_b;
  real_T c20_yc_y;
  real_T c20_q_A;
  real_T c20_g_B;
  real_T c20_ec_x;
  real_T c20_ad_y;
  real_T c20_fc_x;
  real_T c20_bd_y;
  real_T c20_cd_y;
  real_T c20_xb_b;
  real_T c20_dd_y;
  real_T c20_gc_x;
  real_T c20_hc_x;
  real_T c20_w_a;
  real_T c20_yb_b;
  real_T c20_ed_y;
  real_T c20_r_A;
  real_T c20_ic_x;
  real_T c20_jc_x;
  real_T c20_fd_y;
  real_T c20_ac_b;
  real_T c20_gd_y;
  real_T c20_kc_x;
  real_T c20_lc_x;
  real_T c20_x_a;
  real_T c20_bc_b;
  real_T c20_hd_y;
  real_T c20_s_A;
  real_T c20_mc_x;
  real_T c20_nc_x;
  real_T c20_id_y;
  real_T c20_cc_b;
  real_T c20_jd_y;
  real_T c20_oc_x;
  real_T c20_pc_x;
  real_T c20_y_a;
  real_T c20_dc_b;
  real_T c20_kd_y;
  real_T c20_ec_b;
  real_T c20_ld_y;
  real_T c20_qc_x;
  real_T c20_rc_x;
  real_T c20_ab_a;
  real_T c20_fc_b;
  real_T c20_md_y;
  real_T c20_t_A;
  real_T c20_sc_x;
  real_T c20_tc_x;
  real_T c20_nd_y;
  real_T c20_bb_a;
  real_T c20_gc_b;
  real_T c20_od_y;
  real_T c20_hc_b;
  real_T c20_pd_y;
  real_T c20_u_A;
  real_T c20_h_B;
  real_T c20_uc_x;
  real_T c20_qd_y;
  real_T c20_vc_x;
  real_T c20_rd_y;
  real_T c20_sd_y;
  real_T c20_cb_a;
  real_T c20_ic_b;
  real_T c20_td_y;
  real_T c20_jc_b;
  real_T c20_ud_y;
  real_T c20_db_a;
  real_T c20_kc_b;
  real_T c20_vd_y;
  real_T c20_lc_b;
  real_T c20_wd_y;
  real_T c20_v_A;
  real_T c20_i_B;
  real_T c20_wc_x;
  real_T c20_xd_y;
  real_T c20_xc_x;
  real_T c20_yd_y;
  real_T c20_ae_y;
  real_T c20_mc_b;
  real_T c20_be_y;
  real_T c20_yc_x;
  real_T c20_ad_x;
  real_T c20_eb_a;
  real_T c20_nc_b;
  real_T c20_ce_y;
  real_T c20_w_A;
  real_T c20_bd_x;
  real_T c20_cd_x;
  real_T c20_de_y;
  real_T c20_oc_b;
  real_T c20_ee_y;
  real_T c20_dd_x;
  real_T c20_ed_x;
  real_T c20_fb_a;
  real_T c20_pc_b;
  real_T c20_fe_y;
  real_T c20_x_A;
  real_T c20_fd_x;
  real_T c20_gd_x;
  real_T c20_ge_y;
  real_T c20_qc_b;
  real_T c20_he_y;
  real_T c20_hd_x;
  real_T c20_id_x;
  real_T c20_gb_a;
  real_T c20_rc_b;
  real_T c20_ie_y;
  real_T c20_sc_b;
  real_T c20_je_y;
  real_T c20_jd_x;
  real_T c20_kd_x;
  real_T c20_hb_a;
  real_T c20_tc_b;
  real_T c20_ke_y;
  real_T c20_y_A;
  real_T c20_ld_x;
  real_T c20_md_x;
  real_T c20_le_y;
  real_T c20_ib_a;
  real_T c20_uc_b;
  real_T c20_me_y;
  real_T c20_vc_b;
  real_T c20_ne_y;
  real_T c20_ab_A;
  real_T c20_j_B;
  real_T c20_nd_x;
  real_T c20_oe_y;
  real_T c20_od_x;
  real_T c20_pe_y;
  real_T c20_qe_y;
  real_T c20_jb_a;
  real_T c20_wc_b;
  real_T c20_re_y;
  real_T c20_xc_b;
  real_T c20_se_y;
  real_T c20_pd_x;
  real_T c20_qd_x;
  real_T c20_kb_a;
  real_T c20_yc_b;
  real_T c20_te_y;
  real_T c20_rd_x;
  real_T c20_sd_x;
  real_T c20_lb_a;
  real_T c20_ad_b;
  real_T c20_ue_y;
  real_T c20_td_x;
  real_T c20_ud_x;
  real_T c20_mb_a;
  real_T c20_bd_b;
  real_T c20_ve_y;
  real_T c20_bb_A;
  real_T c20_vd_x;
  real_T c20_wd_x;
  real_T c20_we_y;
  real_T c20_nb_a;
  real_T c20_cd_b;
  real_T c20_xe_y;
  real_T c20_xd_x;
  real_T c20_yd_x;
  real_T c20_ob_a;
  real_T c20_dd_b;
  real_T c20_ye_y;
  real_T c20_cb_A;
  real_T c20_ae_x;
  real_T c20_be_x;
  real_T c20_af_y;
  real_T c20_ce_x;
  real_T c20_de_x;
  real_T c20_pb_a;
  real_T c20_ed_b;
  real_T c20_bf_y;
  real_T c20_qb_a;
  real_T c20_fd_b;
  real_T c20_cf_y;
  real_T c20_ee_x;
  real_T c20_fe_x;
  real_T c20_rb_a;
  real_T c20_gd_b;
  real_T c20_df_y;
  real_T c20_db_A;
  real_T c20_ge_x;
  real_T c20_he_x;
  real_T c20_ef_y;
  real_T c20_ie_x;
  real_T c20_je_x;
  real_T c20_sb_a;
  real_T c20_hd_b;
  real_T c20_ff_y;
  real_T c20_ke_x;
  real_T c20_le_x;
  real_T c20_tb_a;
  real_T c20_id_b;
  real_T c20_gf_y;
  real_T c20_me_x;
  real_T c20_ne_x;
  real_T c20_ub_a;
  real_T c20_jd_b;
  real_T c20_hf_y;
  real_T c20_vb_a;
  real_T c20_kd_b;
  real_T c20_if_y;
  real_T c20_ld_b;
  real_T c20_jf_y;
  real_T c20_oe_x;
  real_T c20_pe_x;
  real_T c20_wb_a;
  real_T c20_md_b;
  real_T c20_kf_y;
  real_T c20_qe_x;
  real_T c20_re_x;
  real_T c20_xb_a;
  real_T c20_nd_b;
  real_T c20_lf_y;
  real_T c20_se_x;
  real_T c20_te_x;
  real_T c20_yb_a;
  real_T c20_od_b;
  real_T c20_mf_y;
  real_T c20_eb_A;
  real_T c20_ue_x;
  real_T c20_ve_x;
  real_T c20_nf_y;
  real_T c20_ac_a;
  real_T c20_pd_b;
  real_T c20_of_y;
  real_T c20_we_x;
  real_T c20_xe_x;
  real_T c20_bc_a;
  real_T c20_qd_b;
  real_T c20_pf_y;
  real_T c20_ye_x;
  real_T c20_af_x;
  real_T c20_cc_a;
  real_T c20_rd_b;
  real_T c20_qf_y;
  real_T c20_bf_x;
  real_T c20_cf_x;
  real_T c20_dc_a;
  real_T c20_sd_b;
  real_T c20_rf_y;
  real_T c20_fb_A;
  real_T c20_df_x;
  real_T c20_ef_x;
  real_T c20_sf_y;
  real_T c20_ec_a;
  real_T c20_td_b;
  real_T c20_tf_y;
  real_T c20_ff_x;
  real_T c20_gf_x;
  real_T c20_fc_a;
  real_T c20_ud_b;
  real_T c20_uf_y;
  real_T c20_gb_A;
  real_T c20_hf_x;
  real_T c20_if_x;
  real_T c20_vf_y;
  real_T c20_jf_x;
  real_T c20_kf_x;
  real_T c20_gc_a;
  real_T c20_vd_b;
  real_T c20_wf_y;
  real_T c20_hc_a;
  real_T c20_wd_b;
  real_T c20_xf_y;
  real_T c20_lf_x;
  real_T c20_mf_x;
  real_T c20_ic_a;
  real_T c20_xd_b;
  real_T c20_yf_y;
  real_T c20_hb_A;
  real_T c20_nf_x;
  real_T c20_of_x;
  real_T c20_ag_y;
  real_T c20_pf_x;
  real_T c20_qf_x;
  real_T c20_jc_a;
  real_T c20_yd_b;
  real_T c20_bg_y;
  real_T c20_kc_a;
  real_T c20_ae_b;
  real_T c20_cg_y;
  real_T c20_rf_x;
  real_T c20_sf_x;
  real_T c20_lc_a;
  real_T c20_be_b;
  real_T c20_dg_y;
  real_T c20_ib_A;
  real_T c20_tf_x;
  real_T c20_uf_x;
  real_T c20_eg_y;
  real_T c20_vf_x;
  real_T c20_wf_x;
  real_T c20_mc_a;
  real_T c20_ce_b;
  real_T c20_fg_y;
  real_T c20_xf_x;
  real_T c20_yf_x;
  real_T c20_nc_a;
  real_T c20_de_b;
  real_T c20_gg_y;
  real_T c20_ag_x;
  real_T c20_bg_x;
  real_T c20_oc_a;
  real_T c20_ee_b;
  real_T c20_hg_y;
  real_T c20_pc_a;
  real_T c20_fe_b;
  real_T c20_ig_y;
  real_T c20_cg_x;
  real_T c20_dg_x;
  real_T c20_qc_a;
  real_T c20_ge_b;
  real_T c20_jg_y;
  real_T c20_jb_A;
  real_T c20_eg_x;
  real_T c20_fg_x;
  real_T c20_kg_y;
  real_T c20_gg_x;
  real_T c20_hg_x;
  real_T c20_rc_a;
  real_T c20_he_b;
  real_T c20_lg_y;
  real_T c20_ig_x;
  real_T c20_jg_x;
  real_T c20_sc_a;
  real_T c20_ie_b;
  real_T c20_mg_y;
  real_T c20_kg_x;
  real_T c20_lg_x;
  real_T c20_tc_a;
  real_T c20_je_b;
  real_T c20_ng_y;
  real_T c20_uc_a;
  real_T c20_ke_b;
  real_T c20_og_y;
  real_T c20_le_b;
  real_T c20_pg_y;
  real_T c20_me_b;
  real_T c20_qg_y;
  real_T c20_vc_a;
  real_T c20_ne_b;
  real_T c20_rg_y;
  real_T c20_oe_b;
  real_T c20_sg_y;
  real_T c20_kb_A;
  real_T c20_k_B;
  real_T c20_mg_x;
  real_T c20_tg_y;
  real_T c20_ng_x;
  real_T c20_ug_y;
  real_T c20_vg_y;
  real_T c20_pe_b;
  real_T c20_wg_y;
  real_T c20_og_x;
  real_T c20_pg_x;
  real_T c20_wc_a;
  real_T c20_qe_b;
  real_T c20_xg_y;
  real_T c20_lb_A;
  real_T c20_qg_x;
  real_T c20_rg_x;
  real_T c20_yg_y;
  real_T c20_re_b;
  real_T c20_ah_y;
  real_T c20_sg_x;
  real_T c20_tg_x;
  real_T c20_xc_a;
  real_T c20_se_b;
  real_T c20_bh_y;
  real_T c20_mb_A;
  real_T c20_ug_x;
  real_T c20_vg_x;
  real_T c20_ch_y;
  real_T c20_te_b;
  real_T c20_dh_y;
  real_T c20_wg_x;
  real_T c20_xg_x;
  real_T c20_yc_a;
  real_T c20_ue_b;
  real_T c20_eh_y;
  real_T c20_ve_b;
  real_T c20_fh_y;
  real_T c20_yg_x;
  real_T c20_ah_x;
  real_T c20_ad_a;
  real_T c20_we_b;
  real_T c20_gh_y;
  real_T c20_nb_A;
  real_T c20_bh_x;
  real_T c20_ch_x;
  real_T c20_hh_y;
  real_T c20_bd_a;
  real_T c20_xe_b;
  real_T c20_ih_y;
  real_T c20_ye_b;
  real_T c20_jh_y;
  real_T c20_ob_A;
  real_T c20_l_B;
  real_T c20_dh_x;
  real_T c20_kh_y;
  real_T c20_eh_x;
  real_T c20_lh_y;
  real_T c20_mh_y;
  real_T c20_cd_a;
  real_T c20_af_b;
  real_T c20_nh_y;
  real_T c20_bf_b;
  real_T c20_oh_y;
  real_T c20_fh_x;
  real_T c20_gh_x;
  real_T c20_dd_a;
  real_T c20_cf_b;
  real_T c20_ph_y;
  real_T c20_hh_x;
  real_T c20_ih_x;
  real_T c20_ed_a;
  real_T c20_df_b;
  real_T c20_qh_y;
  real_T c20_jh_x;
  real_T c20_kh_x;
  real_T c20_fd_a;
  real_T c20_ef_b;
  real_T c20_rh_y;
  real_T c20_pb_A;
  real_T c20_lh_x;
  real_T c20_mh_x;
  real_T c20_sh_y;
  real_T c20_gd_a;
  real_T c20_ff_b;
  real_T c20_th_y;
  real_T c20_nh_x;
  real_T c20_oh_x;
  real_T c20_hd_a;
  real_T c20_gf_b;
  real_T c20_uh_y;
  real_T c20_ph_x;
  real_T c20_qh_x;
  real_T c20_id_a;
  real_T c20_hf_b;
  real_T c20_vh_y;
  real_T c20_rh_x;
  real_T c20_sh_x;
  real_T c20_jd_a;
  real_T c20_if_b;
  real_T c20_wh_y;
  real_T c20_qb_A;
  real_T c20_th_x;
  real_T c20_uh_x;
  real_T c20_xh_y;
  real_T c20_kd_a;
  real_T c20_jf_b;
  real_T c20_yh_y;
  real_T c20_vh_x;
  real_T c20_wh_x;
  real_T c20_ld_a;
  real_T c20_kf_b;
  real_T c20_ai_y;
  real_T c20_rb_A;
  real_T c20_xh_x;
  real_T c20_yh_x;
  real_T c20_bi_y;
  real_T c20_ai_x;
  real_T c20_bi_x;
  real_T c20_md_a;
  real_T c20_lf_b;
  real_T c20_ci_y;
  real_T c20_nd_a;
  real_T c20_mf_b;
  real_T c20_di_y;
  real_T c20_ci_x;
  real_T c20_di_x;
  real_T c20_od_a;
  real_T c20_nf_b;
  real_T c20_ei_y;
  real_T c20_sb_A;
  real_T c20_ei_x;
  real_T c20_fi_x;
  real_T c20_fi_y;
  real_T c20_gi_x;
  real_T c20_hi_x;
  real_T c20_pd_a;
  real_T c20_of_b;
  real_T c20_gi_y;
  real_T c20_qd_a;
  real_T c20_pf_b;
  real_T c20_hi_y;
  real_T c20_ii_x;
  real_T c20_ji_x;
  real_T c20_rd_a;
  real_T c20_qf_b;
  real_T c20_ii_y;
  real_T c20_tb_A;
  real_T c20_ki_x;
  real_T c20_li_x;
  real_T c20_ji_y;
  real_T c20_mi_x;
  real_T c20_ni_x;
  real_T c20_sd_a;
  real_T c20_rf_b;
  real_T c20_ki_y;
  real_T c20_oi_x;
  real_T c20_pi_x;
  real_T c20_td_a;
  real_T c20_sf_b;
  real_T c20_li_y;
  real_T c20_qi_x;
  real_T c20_ri_x;
  real_T c20_ud_a;
  real_T c20_tf_b;
  real_T c20_mi_y;
  real_T c20_vd_a;
  real_T c20_uf_b;
  real_T c20_ni_y;
  real_T c20_si_x;
  real_T c20_ti_x;
  real_T c20_wd_a;
  real_T c20_vf_b;
  real_T c20_oi_y;
  real_T c20_ub_A;
  real_T c20_ui_x;
  real_T c20_vi_x;
  real_T c20_pi_y;
  real_T c20_wi_x;
  real_T c20_xi_x;
  real_T c20_xd_a;
  real_T c20_wf_b;
  real_T c20_qi_y;
  real_T c20_yi_x;
  real_T c20_aj_x;
  real_T c20_yd_a;
  real_T c20_xf_b;
  real_T c20_ri_y;
  real_T c20_bj_x;
  real_T c20_cj_x;
  real_T c20_ae_a;
  real_T c20_yf_b;
  real_T c20_si_y;
  real_T c20_be_a;
  real_T c20_ag_b;
  real_T c20_ti_y;
  real_T c20_bg_b;
  real_T c20_ui_y;
  real_T c20_dj_x;
  real_T c20_ej_x;
  real_T c20_ce_a;
  real_T c20_cg_b;
  real_T c20_vi_y;
  real_T c20_fj_x;
  real_T c20_gj_x;
  real_T c20_de_a;
  real_T c20_dg_b;
  real_T c20_wi_y;
  real_T c20_hj_x;
  real_T c20_ij_x;
  real_T c20_ee_a;
  real_T c20_eg_b;
  real_T c20_xi_y;
  real_T c20_vb_A;
  real_T c20_jj_x;
  real_T c20_kj_x;
  real_T c20_yi_y;
  real_T c20_fe_a;
  real_T c20_fg_b;
  real_T c20_aj_y;
  real_T c20_lj_x;
  real_T c20_mj_x;
  real_T c20_ge_a;
  real_T c20_gg_b;
  real_T c20_bj_y;
  real_T c20_wb_A;
  real_T c20_nj_x;
  real_T c20_oj_x;
  real_T c20_cj_y;
  real_T c20_pj_x;
  real_T c20_qj_x;
  real_T c20_he_a;
  real_T c20_hg_b;
  real_T c20_dj_y;
  real_T c20_ie_a;
  real_T c20_ig_b;
  real_T c20_ej_y;
  real_T c20_rj_x;
  real_T c20_sj_x;
  real_T c20_je_a;
  real_T c20_jg_b;
  real_T c20_fj_y;
  real_T c20_xb_A;
  real_T c20_tj_x;
  real_T c20_uj_x;
  real_T c20_gj_y;
  real_T c20_vj_x;
  real_T c20_wj_x;
  real_T c20_ke_a;
  real_T c20_kg_b;
  real_T c20_hj_y;
  real_T c20_xj_x;
  real_T c20_yj_x;
  real_T c20_le_a;
  real_T c20_lg_b;
  real_T c20_ij_y;
  real_T c20_ak_x;
  real_T c20_bk_x;
  real_T c20_me_a;
  real_T c20_mg_b;
  real_T c20_jj_y;
  real_T c20_ne_a;
  real_T c20_ng_b;
  real_T c20_kj_y;
  real_T c20_og_b;
  real_T c20_lj_y;
  real_T c20_pg_b;
  real_T c20_mj_y;
  real_T c20_oe_a;
  real_T c20_qg_b;
  real_T c20_nj_y;
  real_T c20_rg_b;
  real_T c20_oj_y;
  real_T c20_yb_A;
  real_T c20_m_B;
  real_T c20_ck_x;
  real_T c20_pj_y;
  real_T c20_dk_x;
  real_T c20_qj_y;
  real_T c20_rj_y;
  real_T c20_sg_b;
  real_T c20_sj_y;
  real_T c20_ek_x;
  real_T c20_fk_x;
  real_T c20_pe_a;
  real_T c20_tg_b;
  real_T c20_tj_y;
  real_T c20_ac_A;
  real_T c20_gk_x;
  real_T c20_hk_x;
  real_T c20_uj_y;
  real_T c20_ug_b;
  real_T c20_vj_y;
  real_T c20_ik_x;
  real_T c20_jk_x;
  real_T c20_qe_a;
  real_T c20_vg_b;
  real_T c20_wj_y;
  real_T c20_bc_A;
  real_T c20_kk_x;
  real_T c20_lk_x;
  real_T c20_xj_y;
  real_T c20_wg_b;
  real_T c20_yj_y;
  real_T c20_mk_x;
  real_T c20_nk_x;
  real_T c20_re_a;
  real_T c20_xg_b;
  real_T c20_ak_y;
  real_T c20_yg_b;
  real_T c20_bk_y;
  real_T c20_ok_x;
  real_T c20_pk_x;
  real_T c20_se_a;
  real_T c20_ah_b;
  real_T c20_ck_y;
  real_T c20_cc_A;
  real_T c20_qk_x;
  real_T c20_rk_x;
  real_T c20_dk_y;
  real_T c20_te_a;
  real_T c20_bh_b;
  real_T c20_ek_y;
  real_T c20_ch_b;
  real_T c20_fk_y;
  real_T c20_dc_A;
  real_T c20_n_B;
  real_T c20_sk_x;
  real_T c20_gk_y;
  real_T c20_tk_x;
  real_T c20_hk_y;
  real_T c20_ik_y;
  real_T c20_ue_a;
  real_T c20_dh_b;
  real_T c20_jk_y;
  real_T c20_eh_b;
  real_T c20_kk_y;
  real_T c20_ve_a;
  real_T c20_fh_b;
  real_T c20_lk_y;
  real_T c20_gh_b;
  real_T c20_mk_y;
  real_T c20_ec_A;
  real_T c20_o_B;
  real_T c20_uk_x;
  real_T c20_nk_y;
  real_T c20_vk_x;
  real_T c20_ok_y;
  real_T c20_pk_y;
  real_T c20_hh_b;
  real_T c20_qk_y;
  real_T c20_wk_x;
  real_T c20_xk_x;
  real_T c20_we_a;
  real_T c20_ih_b;
  real_T c20_rk_y;
  real_T c20_fc_A;
  real_T c20_yk_x;
  real_T c20_al_x;
  real_T c20_sk_y;
  real_T c20_jh_b;
  real_T c20_tk_y;
  real_T c20_bl_x;
  real_T c20_cl_x;
  real_T c20_xe_a;
  real_T c20_kh_b;
  real_T c20_uk_y;
  real_T c20_gc_A;
  real_T c20_dl_x;
  real_T c20_el_x;
  real_T c20_vk_y;
  real_T c20_lh_b;
  real_T c20_wk_y;
  real_T c20_fl_x;
  real_T c20_gl_x;
  real_T c20_ye_a;
  real_T c20_mh_b;
  real_T c20_xk_y;
  real_T c20_nh_b;
  real_T c20_yk_y;
  real_T c20_hl_x;
  real_T c20_il_x;
  real_T c20_af_a;
  real_T c20_oh_b;
  real_T c20_al_y;
  real_T c20_hc_A;
  real_T c20_jl_x;
  real_T c20_kl_x;
  real_T c20_bl_y;
  real_T c20_bf_a;
  real_T c20_ph_b;
  real_T c20_cl_y;
  real_T c20_qh_b;
  real_T c20_dl_y;
  real_T c20_ic_A;
  real_T c20_p_B;
  real_T c20_ll_x;
  real_T c20_el_y;
  real_T c20_ml_x;
  real_T c20_fl_y;
  real_T c20_gl_y;
  real_T c20_cf_a;
  real_T c20_rh_b;
  real_T c20_hl_y;
  real_T c20_sh_b;
  real_T c20_il_y;
  real_T c20_th_b;
  real_T c20_jl_y;
  real_T c20_uh_b;
  real_T c20_kl_y;
  real_T c20_nl_x;
  real_T c20_ol_x;
  real_T c20_df_a;
  real_T c20_vh_b;
  real_T c20_ll_y;
  real_T c20_pl_x;
  real_T c20_ql_x;
  real_T c20_ef_a;
  real_T c20_wh_b;
  real_T c20_ml_y;
  real_T c20_rl_x;
  real_T c20_sl_x;
  real_T c20_ff_a;
  real_T c20_xh_b;
  real_T c20_nl_y;
  real_T c20_jc_A;
  real_T c20_tl_x;
  real_T c20_ul_x;
  real_T c20_ol_y;
  real_T c20_gf_a;
  real_T c20_yh_b;
  real_T c20_pl_y;
  real_T c20_vl_x;
  real_T c20_wl_x;
  real_T c20_hf_a;
  real_T c20_ai_b;
  real_T c20_ql_y;
  real_T c20_kc_A;
  real_T c20_xl_x;
  real_T c20_yl_x;
  real_T c20_rl_y;
  real_T c20_am_x;
  real_T c20_bm_x;
  real_T c20_if_a;
  real_T c20_bi_b;
  real_T c20_sl_y;
  real_T c20_jf_a;
  real_T c20_ci_b;
  real_T c20_tl_y;
  real_T c20_cm_x;
  real_T c20_dm_x;
  real_T c20_kf_a;
  real_T c20_di_b;
  real_T c20_ul_y;
  real_T c20_em_x;
  real_T c20_fm_x;
  real_T c20_lf_a;
  real_T c20_ei_b;
  real_T c20_vl_y;
  real_T c20_gm_x;
  real_T c20_hm_x;
  real_T c20_mf_a;
  real_T c20_fi_b;
  real_T c20_wl_y;
  real_T c20_lc_A;
  real_T c20_im_x;
  real_T c20_jm_x;
  real_T c20_xl_y;
  real_T c20_nf_a;
  real_T c20_gi_b;
  real_T c20_yl_y;
  real_T c20_km_x;
  real_T c20_lm_x;
  real_T c20_of_a;
  real_T c20_hi_b;
  real_T c20_am_y;
  real_T c20_mc_A;
  real_T c20_mm_x;
  real_T c20_nm_x;
  real_T c20_bm_y;
  real_T c20_om_x;
  real_T c20_pm_x;
  real_T c20_pf_a;
  real_T c20_ii_b;
  real_T c20_cm_y;
  real_T c20_qm_x;
  real_T c20_rm_x;
  real_T c20_qf_a;
  real_T c20_ji_b;
  real_T c20_dm_y;
  real_T c20_sm_x;
  real_T c20_tm_x;
  real_T c20_rf_a;
  real_T c20_ki_b;
  real_T c20_em_y;
  real_T c20_sf_a;
  real_T c20_li_b;
  real_T c20_fm_y;
  real_T c20_um_x;
  real_T c20_vm_x;
  real_T c20_tf_a;
  real_T c20_mi_b;
  real_T c20_gm_y;
  real_T c20_nc_A;
  real_T c20_wm_x;
  real_T c20_xm_x;
  real_T c20_hm_y;
  real_T c20_ym_x;
  real_T c20_an_x;
  real_T c20_uf_a;
  real_T c20_ni_b;
  real_T c20_im_y;
  real_T c20_vf_a;
  real_T c20_oi_b;
  real_T c20_jm_y;
  real_T c20_bn_x;
  real_T c20_cn_x;
  real_T c20_wf_a;
  real_T c20_pi_b;
  real_T c20_km_y;
  real_T c20_oc_A;
  real_T c20_dn_x;
  real_T c20_en_x;
  real_T c20_lm_y;
  real_T c20_fn_x;
  real_T c20_gn_x;
  real_T c20_xf_a;
  real_T c20_qi_b;
  real_T c20_mm_y;
  real_T c20_hn_x;
  real_T c20_in_x;
  real_T c20_yf_a;
  real_T c20_ri_b;
  real_T c20_nm_y;
  real_T c20_jn_x;
  real_T c20_kn_x;
  real_T c20_ag_a;
  real_T c20_si_b;
  real_T c20_om_y;
  real_T c20_bg_a;
  real_T c20_ti_b;
  real_T c20_pm_y;
  real_T c20_ln_x;
  real_T c20_mn_x;
  real_T c20_cg_a;
  real_T c20_ui_b;
  real_T c20_qm_y;
  real_T c20_pc_A;
  real_T c20_nn_x;
  real_T c20_on_x;
  real_T c20_rm_y;
  real_T c20_vi_b;
  real_T c20_sm_y;
  real_T c20_pn_x;
  real_T c20_qn_x;
  real_T c20_dg_a;
  real_T c20_wi_b;
  real_T c20_tm_y;
  real_T c20_qc_A;
  real_T c20_rn_x;
  real_T c20_sn_x;
  real_T c20_um_y;
  real_T c20_xi_b;
  real_T c20_vm_y;
  real_T c20_tn_x;
  real_T c20_un_x;
  real_T c20_eg_a;
  real_T c20_yi_b;
  real_T c20_wm_y;
  real_T c20_rc_A;
  real_T c20_vn_x;
  real_T c20_wn_x;
  real_T c20_xm_y;
  real_T c20_fg_a;
  real_T c20_aj_b;
  real_T c20_ym_y;
  real_T c20_xn_x;
  real_T c20_yn_x;
  real_T c20_gg_a;
  real_T c20_bj_b;
  real_T c20_an_y;
  real_T c20_sc_A;
  real_T c20_ao_x;
  real_T c20_bo_x;
  real_T c20_bn_y;
  real_T c20_cj_b;
  real_T c20_cn_y;
  real_T c20_co_x;
  real_T c20_do_x;
  real_T c20_hg_a;
  real_T c20_dj_b;
  real_T c20_dn_y;
  real_T c20_tc_A;
  real_T c20_eo_x;
  real_T c20_fo_x;
  real_T c20_en_y;
  real_T c20_ig_a;
  real_T c20_ej_b;
  real_T c20_fn_y;
  real_T c20_jg_a;
  real_T c20_fj_b;
  real_T c20_gn_y;
  real_T c20_go_x;
  real_T c20_ho_x;
  real_T c20_kg_a;
  real_T c20_gj_b;
  real_T c20_hn_y;
  real_T c20_uc_A;
  real_T c20_io_x;
  real_T c20_jo_x;
  real_T c20_in_y;
  real_T c20_ko_x;
  real_T c20_lo_x;
  real_T c20_lg_a;
  real_T c20_hj_b;
  real_T c20_jn_y;
  real_T c20_vc_A;
  real_T c20_mo_x;
  real_T c20_no_x;
  real_T c20_kn_y;
  real_T c20_ij_b;
  real_T c20_ln_y;
  real_T c20_oo_x;
  real_T c20_po_x;
  real_T c20_mg_a;
  real_T c20_jj_b;
  real_T c20_mn_y;
  real_T c20_wc_A;
  real_T c20_qo_x;
  real_T c20_ro_x;
  real_T c20_nn_y;
  real_T c20_kj_b;
  real_T c20_on_y;
  real_T c20_so_x;
  real_T c20_to_x;
  real_T c20_ng_a;
  real_T c20_lj_b;
  real_T c20_pn_y;
  real_T c20_xc_A;
  real_T c20_uo_x;
  real_T c20_vo_x;
  real_T c20_qn_y;
  real_T c20_og_a;
  real_T c20_mj_b;
  real_T c20_rn_y;
  real_T c20_wo_x;
  real_T c20_xo_x;
  real_T c20_pg_a;
  real_T c20_nj_b;
  real_T c20_sn_y;
  real_T c20_yc_A;
  real_T c20_yo_x;
  real_T c20_ap_x;
  real_T c20_tn_y;
  real_T c20_oj_b;
  real_T c20_un_y;
  real_T c20_bp_x;
  real_T c20_cp_x;
  real_T c20_qg_a;
  real_T c20_pj_b;
  real_T c20_vn_y;
  real_T c20_ad_A;
  real_T c20_dp_x;
  real_T c20_ep_x;
  real_T c20_wn_y;
  real_T c20_rg_a;
  real_T c20_qj_b;
  real_T c20_xn_y;
  real_T c20_sg_a;
  real_T c20_rj_b;
  real_T c20_yn_y;
  real_T c20_fp_x;
  real_T c20_gp_x;
  real_T c20_tg_a;
  real_T c20_sj_b;
  real_T c20_ao_y;
  real_T c20_bd_A;
  real_T c20_hp_x;
  real_T c20_ip_x;
  real_T c20_bo_y;
  real_T c20_tj_b;
  real_T c20_co_y;
  real_T c20_ug_a;
  real_T c20_uj_b;
  real_T c20_do_y;
  real_T c20_jp_x;
  real_T c20_kp_x;
  real_T c20_vg_a;
  real_T c20_vj_b;
  real_T c20_eo_y;
  real_T c20_lp_x;
  real_T c20_mp_x;
  real_T c20_wg_a;
  real_T c20_wj_b;
  real_T c20_fo_y;
  real_T c20_cd_A;
  real_T c20_np_x;
  real_T c20_op_x;
  real_T c20_go_y;
  real_T c20_pp_x;
  real_T c20_qp_x;
  real_T c20_xg_a;
  real_T c20_xj_b;
  real_T c20_ho_y;
  real_T c20_yg_a;
  real_T c20_yj_b;
  real_T c20_io_y;
  real_T c20_dd_A;
  real_T c20_rp_x;
  real_T c20_sp_x;
  real_T c20_jo_y;
  real_T c20_ah_a;
  real_T c20_ak_b;
  real_T c20_ko_y;
  real_T c20_tp_x;
  real_T c20_up_x;
  real_T c20_bh_a;
  real_T c20_bk_b;
  real_T c20_lo_y;
  real_T c20_vp_x;
  real_T c20_wp_x;
  real_T c20_ch_a;
  real_T c20_ck_b;
  real_T c20_mo_y;
  real_T c20_xp_x;
  real_T c20_yp_x;
  real_T c20_dh_a;
  real_T c20_dk_b;
  real_T c20_no_y;
  real_T c20_aq_x;
  real_T c20_bq_x;
  real_T c20_eh_a;
  real_T c20_ek_b;
  real_T c20_oo_y;
  real_T c20_ed_A;
  real_T c20_cq_x;
  real_T c20_dq_x;
  real_T c20_po_y;
  real_T c20_fh_a;
  real_T c20_fk_b;
  real_T c20_qo_y;
  real_T c20_fd_A;
  real_T c20_eq_x;
  real_T c20_fq_x;
  real_T c20_ro_y;
  real_T c20_gh_a;
  real_T c20_gk_b;
  real_T c20_so_y;
  real_T c20_gq_x;
  real_T c20_hq_x;
  real_T c20_hh_a;
  real_T c20_hk_b;
  real_T c20_to_y;
  real_T c20_iq_x;
  real_T c20_jq_x;
  real_T c20_ih_a;
  real_T c20_ik_b;
  real_T c20_uo_y;
  real_T c20_gd_A;
  real_T c20_kq_x;
  real_T c20_lq_x;
  real_T c20_vo_y;
  real_T c20_mq_x;
  real_T c20_nq_x;
  real_T c20_jh_a;
  real_T c20_jk_b;
  real_T c20_wo_y;
  real_T c20_oq_x;
  real_T c20_pq_x;
  real_T c20_kh_a;
  real_T c20_kk_b;
  real_T c20_xo_y;
  real_T c20_qq_x;
  real_T c20_rq_x;
  real_T c20_lh_a;
  real_T c20_lk_b;
  real_T c20_yo_y;
  real_T c20_mh_a;
  real_T c20_mk_b;
  real_T c20_ap_y;
  real_T c20_hd_A;
  real_T c20_sq_x;
  real_T c20_tq_x;
  real_T c20_bp_y;
  real_T c20_nh_a;
  real_T c20_nk_b;
  real_T c20_cp_y;
  real_T c20_uq_x;
  real_T c20_vq_x;
  real_T c20_oh_a;
  real_T c20_ok_b;
  real_T c20_dp_y;
  real_T c20_wq_x;
  real_T c20_xq_x;
  real_T c20_ph_a;
  real_T c20_pk_b;
  real_T c20_ep_y;
  real_T c20_id_A;
  real_T c20_yq_x;
  real_T c20_ar_x;
  real_T c20_fp_y;
  real_T c20_br_x;
  real_T c20_cr_x;
  real_T c20_qh_a;
  real_T c20_qk_b;
  real_T c20_gp_y;
  real_T c20_rh_a;
  real_T c20_rk_b;
  real_T c20_hp_y;
  real_T c20_jd_A;
  real_T c20_dr_x;
  real_T c20_er_x;
  real_T c20_ip_y;
  real_T c20_sh_a;
  real_T c20_sk_b;
  real_T c20_jp_y;
  real_T c20_fr_x;
  real_T c20_gr_x;
  real_T c20_th_a;
  real_T c20_tk_b;
  real_T c20_kp_y;
  real_T c20_hr_x;
  real_T c20_ir_x;
  real_T c20_uh_a;
  real_T c20_uk_b;
  real_T c20_lp_y;
  real_T c20_kd_A;
  real_T c20_jr_x;
  real_T c20_kr_x;
  real_T c20_mp_y;
  real_T c20_lr_x;
  real_T c20_mr_x;
  real_T c20_vh_a;
  real_T c20_vk_b;
  real_T c20_np_y;
  real_T c20_nr_x;
  real_T c20_or_x;
  real_T c20_wh_a;
  real_T c20_wk_b;
  real_T c20_op_y;
  real_T c20_pr_x;
  real_T c20_qr_x;
  real_T c20_xh_a;
  real_T c20_xk_b;
  real_T c20_pp_y;
  real_T c20_yh_a;
  real_T c20_yk_b;
  real_T c20_qp_y;
  real_T c20_ld_A;
  real_T c20_rr_x;
  real_T c20_sr_x;
  real_T c20_rp_y;
  real_T c20_ai_a;
  real_T c20_al_b;
  real_T c20_sp_y;
  real_T c20_tr_x;
  real_T c20_ur_x;
  real_T c20_bi_a;
  real_T c20_bl_b;
  real_T c20_tp_y;
  real_T c20_vr_x;
  real_T c20_wr_x;
  real_T c20_ci_a;
  real_T c20_cl_b;
  real_T c20_up_y;
  real_T c20_xr_x;
  real_T c20_yr_x;
  real_T c20_di_a;
  real_T c20_dl_b;
  real_T c20_vp_y;
  real_T c20_as_x;
  real_T c20_bs_x;
  real_T c20_ei_a;
  real_T c20_el_b;
  real_T c20_wp_y;
  real_T c20_md_A;
  real_T c20_cs_x;
  real_T c20_ds_x;
  real_T c20_xp_y;
  real_T c20_fi_a;
  real_T c20_fl_b;
  real_T c20_yp_y;
  real_T c20_nd_A;
  real_T c20_es_x;
  real_T c20_fs_x;
  real_T c20_aq_y;
  real_T c20_gl_b;
  real_T c20_bq_y;
  int32_T c20_i18;
  int32_T c20_i19;
  int32_T c20_i20;
  int32_T c20_i21;
  int32_T c20_i22;
  int32_T c20_i23;
  real_T c20_gs_x;
  real_T c20_hs_x;
  real_T c20_gi_a;
  real_T c20_hl_b;
  real_T c20_cq_y;
  real_T c20_is_x;
  real_T c20_js_x;
  real_T c20_hi_a;
  real_T c20_il_b;
  real_T c20_dq_y;
  real_T c20_ks_x;
  real_T c20_ls_x;
  real_T c20_ii_a;
  real_T c20_jl_b;
  real_T c20_eq_y;
  real_T c20_ms_x;
  real_T c20_ns_x;
  real_T c20_ji_a;
  real_T c20_kl_b;
  real_T c20_fq_y;
  real_T c20_os_x;
  real_T c20_ps_x;
  real_T c20_ki_a;
  real_T c20_ll_b;
  real_T c20_gq_y;
  real_T c20_qs_x;
  real_T c20_rs_x;
  real_T c20_li_a;
  real_T c20_ml_b;
  real_T c20_hq_y;
  real_T c20_ss_x;
  real_T c20_ts_x;
  real_T c20_mi_a;
  real_T c20_nl_b;
  real_T c20_iq_y;
  real_T c20_us_x;
  real_T c20_vs_x;
  real_T c20_ni_a;
  real_T c20_ol_b;
  real_T c20_jq_y;
  real_T c20_ws_x;
  real_T c20_xs_x;
  real_T c20_oi_a;
  real_T c20_pl_b;
  real_T c20_kq_y;
  real_T c20_ys_x;
  real_T c20_at_x;
  real_T c20_pi_a;
  real_T c20_ql_b;
  real_T c20_lq_y;
  real_T c20_bt_x;
  real_T c20_ct_x;
  real_T c20_qi_a;
  real_T c20_rl_b;
  real_T c20_mq_y;
  real_T c20_dt_x;
  real_T c20_et_x;
  real_T c20_ri_a;
  real_T c20_sl_b;
  real_T c20_nq_y;
  int32_T c20_i24;
  int32_T c20_i25;
  int32_T c20_i26;
  int32_T c20_i27;
  int32_T c20_i28;
  int32_T c20_i29;
  int32_T c20_i30;
  int32_T c20_i31;
  int32_T c20_i32;
  real_T c20_b_Hb[36];
  real_T c20_si_a[36];
  int32_T c20_i33;
  int32_T c20_i34;
  real_T c20_tl_b[18];
  int32_T c20_i35;
  int32_T c20_i36;
  int32_T c20_i37;
  real_T c20_oq_y[18];
  int32_T c20_i38;
  int32_T c20_i39;
  real_T c20_ul_b[3];
  int32_T c20_i40;
  int32_T c20_i41;
  int32_T c20_i42;
  real_T c20_C[6];
  int32_T c20_i43;
  int32_T c20_i44;
  int32_T c20_i45;
  int32_T c20_i46;
  int32_T c20_i47;
  int32_T c20_i48;
  real_T c20_ft_x;
  real_T c20_gt_x;
  real_T c20_ti_a;
  real_T c20_vl_b;
  real_T c20_pq_y;
  real_T c20_ht_x;
  real_T c20_it_x;
  real_T c20_ui_a;
  real_T c20_wl_b;
  real_T c20_qq_y;
  real_T c20_jt_x;
  real_T c20_kt_x;
  real_T c20_vi_a;
  real_T c20_xl_b;
  real_T c20_rq_y;
  real_T c20_lt_x;
  real_T c20_mt_x;
  real_T c20_wi_a;
  real_T c20_yl_b;
  real_T c20_sq_y;
  real_T c20_nt_x;
  real_T c20_ot_x;
  real_T c20_xi_a;
  real_T c20_am_b;
  real_T c20_tq_y;
  real_T c20_pt_x;
  real_T c20_qt_x;
  real_T c20_yi_a;
  real_T c20_bm_b;
  real_T c20_uq_y;
  real_T c20_rt_x;
  real_T c20_st_x;
  real_T c20_aj_a;
  real_T c20_cm_b;
  real_T c20_vq_y;
  real_T c20_tt_x;
  real_T c20_ut_x;
  real_T c20_bj_a;
  real_T c20_dm_b;
  real_T c20_wq_y;
  real_T c20_vt_x;
  real_T c20_wt_x;
  real_T c20_cj_a;
  real_T c20_em_b;
  real_T c20_xq_y;
  real_T c20_xt_x;
  real_T c20_yt_x;
  real_T c20_dj_a;
  real_T c20_fm_b;
  real_T c20_yq_y;
  real_T c20_au_x;
  real_T c20_bu_x;
  real_T c20_ej_a;
  real_T c20_gm_b;
  real_T c20_ar_y;
  real_T c20_cu_x;
  real_T c20_du_x;
  real_T c20_fj_a;
  real_T c20_hm_b;
  real_T c20_br_y;
  real_T c20_eu_x;
  real_T c20_fu_x;
  real_T c20_gj_a;
  real_T c20_im_b;
  real_T c20_cr_y;
  real_T c20_gu_x;
  real_T c20_hu_x;
  real_T c20_hj_a;
  real_T c20_jm_b;
  real_T c20_dr_y;
  real_T c20_iu_x;
  real_T c20_ju_x;
  real_T c20_ij_a;
  real_T c20_km_b;
  real_T c20_er_y;
  real_T c20_ku_x;
  real_T c20_lu_x;
  real_T c20_jj_a;
  real_T c20_lm_b;
  real_T c20_fr_y;
  int32_T c20_i49;
  int32_T c20_i50;
  static real_T c20_dv4[6] = { 0.0, 0.0, 0.0, 1.0, 0.0, 0.0 };

  int32_T c20_i51;
  int32_T c20_i52;
  static real_T c20_dv5[6] = { 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 };

  int32_T c20_i53;
  int32_T c20_i54;
  static real_T c20_dv6[6] = { 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  int32_T c20_i55;
  int32_T c20_i56;
  real_T c20_c_Hb[36];
  real_T c20_mm_b[36];
  int32_T c20_i57;
  int32_T c20_i58;
  int32_T c20_i59;
  real_T c20_gr_y[36];
  int32_T c20_i60;
  int32_T c20_i61;
  int32_T c20_i62;
  int32_T c20_i63;
  int32_T c20_i64;
  int32_T c20_i65;
  int32_T c20_i66;
  int32_T c20_i67;
  int32_T c20_i68;
  int32_T c20_i69;
  real_T c20_b_Jstar[18];
  real_T c20_dv7[18];
  int32_T c20_i70;
  int32_T c20_i71;
  real_T c20_kj_a[18];
  int32_T c20_i72;
  int32_T c20_i73;
  int32_T c20_i74;
  int32_T c20_i75;
  int32_T c20_i76;
  int32_T c20_i77;
  real_T c20_c_Jstar[18];
  real_T c20_dv8[3];
  int32_T c20_i78;
  real_T c20_od_A;
  real_T c20_mu_x;
  real_T c20_nu_x;
  real_T c20_hr_y;
  real_T c20_lj_a;
  int32_T c20_i79;
  int32_T c20_i80;
  int32_T c20_i81;
  int32_T c20_i82;
  int32_T c20_i83;
  int32_T c20_i84;
  int32_T c20_i85;
  int32_T c20_i86;
  int32_T c20_i87;
  int32_T c20_i88;
  int32_T c20_i89;
  real_T c20_mj_a;
  int32_T c20_i90;
  static real_T c20_nm_b[36] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  int32_T c20_i91;
  int32_T c20_i92;
  int32_T c20_i93;
  int32_T c20_i94;
  int32_T c20_i95;
  real_T c20_ir_y[36];
  int32_T c20_i96;
  int32_T c20_i97;
  int32_T c20_i98;
  int32_T c20_i99;
  real_T c20_jr_y[18];
  int32_T c20_i100;
  int32_T c20_i101;
  int32_T c20_i102;
  int32_T c20_i103;
  int32_T c20_i104;
  int32_T c20_i105;
  int32_T c20_i106;
  int32_T c20_i107;
  int32_T c20_i108;
  int32_T c20_i109;
  int32_T c20_i110;
  real_T *c20_b_q3rd;
  real_T (*c20_b_qd_req)[3];
  real_T (*c20_b_qd_reqW)[3];
  real_T (*c20_d_Jstar)[18];
  real_T (*c20_b_SCnew)[6];
  real_T (*c20_b_SC)[6];
  real_T (*c20_b_Ve)[6];
  real_T (*c20_b_qqd)[9];
  c20_b_SCnew = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 4);
  c20_d_Jstar = (real_T (*)[18])ssGetOutputPortSignal(chartInstance->S, 3);
  c20_b_SC = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 3);
  c20_b_Ve = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
  c20_b_q3rd = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c20_b_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  c20_b_qd_reqW = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c20_b_qd_req = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 19U, chartInstance->c20_sfEvent);
  c20_hoistedGlobal = *c20_b_q3rd;
  c20_b_hoistedGlobal = chartInstance->c20_l;
  c20_c_hoistedGlobal = chartInstance->c20_m;
  c20_d_hoistedGlobal = chartInstance->c20_I;
  c20_e_hoistedGlobal = chartInstance->c20_lb;
  c20_f_hoistedGlobal = chartInstance->c20_mb;
  c20_g_hoistedGlobal = chartInstance->c20_Ib;
  for (c20_i15 = 0; c20_i15 < 9; c20_i15++) {
    c20_qqd[c20_i15] = (*c20_b_qqd)[c20_i15];
  }

  c20_q3rd = c20_hoistedGlobal;
  for (c20_i16 = 0; c20_i16 < 6; c20_i16++) {
    c20_Ve[c20_i16] = (*c20_b_Ve)[c20_i16];
  }

  for (c20_i17 = 0; c20_i17 < 6; c20_i17++) {
    c20_SC[c20_i17] = (*c20_b_SC)[c20_i17];
  }

  c20_b_l = c20_b_hoistedGlobal;
  c20_b_m = c20_c_hoistedGlobal;
  c20_b_I = c20_d_hoistedGlobal;
  c20_b_lb = c20_e_hoistedGlobal;
  c20_b_mb = c20_f_hoistedGlobal;
  c20_b_Ib = c20_g_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 35U, 35U, c20_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_q1, 0U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_q2, 1U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_q3, 2U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_qd1, 3U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_qd2, 4U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_qd3, 5U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_base_x, 6U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_base_y, 7U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_bth, 8U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_Hb, 9U, c20_g_sf_marshallOut,
    c20_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_Hbm, 10U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_Jm, 11U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_Jb, 12U, c20_g_sf_marshallOut,
    c20_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_EE, 13U, c20_c_sf_marshallOut,
    c20_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_invJstar, 14U, c20_f_sf_marshallOut,
    c20_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_A, 15U, c20_c_sf_marshallOut,
    c20_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_lambmax, 16U, c20_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_Sigma, 17U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_lamb2, 18U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 19U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 20U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_qqd, 21U, c20_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c20_q3rd, 22U, c20_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_Ve, 23U, c20_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_SC, 24U, c20_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_l, 25U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_m, 26U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_I, 27U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_lb, 28U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_mb, 29U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_Ib, 30U, c20_d_sf_marshallOut,
    c20_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_qd_req, 31U, c20_c_sf_marshallOut,
    c20_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_qd_reqW, 32U, c20_c_sf_marshallOut,
    c20_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_Jstar, 33U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_SCnew, 34U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 3);
  c20_q1 = c20_qqd[6];
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 4);
  c20_q2 = c20_qqd[7];
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 5);
  c20_q3 = c20_qqd[8];
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 6);
  c20_qd1 = c20_qqd[3];
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 7);
  c20_qd2 = c20_qqd[4];
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 8);
  c20_qd3 = c20_qqd[5];
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 11);
  c20_base_x = c20_SC[0];
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 12);
  c20_base_y = c20_SC[1];
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 13);
  c20_bth = c20_SC[5];
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 16);
  c20_b = c20_b_m;
  c20_y = 3.0 * c20_b;
  c20_b_b = c20_b_m;
  c20_b_y = 3.0 * c20_b_b;
  c20_a = c20_base_y;
  c20_c_b = c20_b_mb;
  c20_c_y = c20_a * c20_c_b;
  c20_d_b = c20_b_m;
  c20_d_y = 3.0 * c20_d_b;
  c20_b_A = c20_c_y;
  c20_B = c20_d_y + c20_b_mb;
  c20_x = c20_b_A;
  c20_e_y = c20_B;
  c20_b_x = c20_x;
  c20_f_y = c20_e_y;
  c20_g_y = c20_b_x / c20_f_y;
  c20_e_b = c20_base_y;
  c20_h_y = 3.0 * c20_e_b;
  c20_c_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_d_x = c20_c_x;
  c20_d_x = muDoubleScalarSin(c20_d_x);
  c20_b_a = c20_b_l;
  c20_f_b = c20_d_x;
  c20_i_y = c20_b_a * c20_f_b;
  c20_c_A = c20_i_y;
  c20_e_x = c20_c_A;
  c20_f_x = c20_e_x;
  c20_j_y = c20_f_x / 2.0;
  c20_g_b = c20_b_l;
  c20_k_y = 5.0 * c20_g_b;
  c20_g_x = c20_bth + c20_q1;
  c20_h_x = c20_g_x;
  c20_h_x = muDoubleScalarSin(c20_h_x);
  c20_c_a = c20_k_y;
  c20_h_b = c20_h_x;
  c20_l_y = c20_c_a * c20_h_b;
  c20_d_A = c20_l_y;
  c20_i_x = c20_d_A;
  c20_j_x = c20_i_x;
  c20_m_y = c20_j_x / 2.0;
  c20_i_b = c20_b_lb;
  c20_n_y = 3.0 * c20_i_b;
  c20_k_x = c20_bth;
  c20_l_x = c20_k_x;
  c20_l_x = muDoubleScalarSin(c20_l_x);
  c20_d_a = c20_n_y;
  c20_j_b = c20_l_x;
  c20_o_y = c20_d_a * c20_j_b;
  c20_k_b = c20_b_l;
  c20_p_y = 3.0 * c20_k_b;
  c20_m_x = (c20_bth + c20_q1) + c20_q2;
  c20_n_x = c20_m_x;
  c20_n_x = muDoubleScalarSin(c20_n_x);
  c20_e_a = c20_p_y;
  c20_l_b = c20_n_x;
  c20_q_y = c20_e_a * c20_l_b;
  c20_e_A = c20_q_y;
  c20_o_x = c20_e_A;
  c20_p_x = c20_o_x;
  c20_r_y = c20_p_x / 2.0;
  c20_f_a = c20_b_m;
  c20_m_b = (((c20_h_y + c20_j_y) + c20_m_y) + c20_o_y) + c20_r_y;
  c20_s_y = c20_f_a * c20_m_b;
  c20_n_b = c20_b_m;
  c20_t_y = 3.0 * c20_n_b;
  c20_f_A = c20_s_y;
  c20_b_B = c20_t_y + c20_b_mb;
  c20_q_x = c20_f_A;
  c20_u_y = c20_b_B;
  c20_r_x = c20_q_x;
  c20_v_y = c20_u_y;
  c20_w_y = c20_r_x / c20_v_y;
  c20_g_a = -(c20_b_y + c20_b_mb);
  c20_o_b = (c20_g_y - c20_base_y) + c20_w_y;
  c20_x_y = c20_g_a * c20_o_b;
  c20_p_b = c20_b_m;
  c20_y_y = 3.0 * c20_p_b;
  c20_q_b = c20_b_m;
  c20_ab_y = 3.0 * c20_q_b;
  c20_h_a = c20_base_x;
  c20_r_b = c20_b_mb;
  c20_bb_y = c20_h_a * c20_r_b;
  c20_s_b = c20_b_m;
  c20_cb_y = 3.0 * c20_s_b;
  c20_g_A = c20_bb_y;
  c20_c_B = c20_cb_y + c20_b_mb;
  c20_s_x = c20_g_A;
  c20_db_y = c20_c_B;
  c20_t_x = c20_s_x;
  c20_eb_y = c20_db_y;
  c20_fb_y = c20_t_x / c20_eb_y;
  c20_t_b = c20_base_x;
  c20_gb_y = 3.0 * c20_t_b;
  c20_u_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_v_x = c20_u_x;
  c20_v_x = muDoubleScalarCos(c20_v_x);
  c20_i_a = c20_b_l;
  c20_u_b = c20_v_x;
  c20_hb_y = c20_i_a * c20_u_b;
  c20_h_A = c20_hb_y;
  c20_w_x = c20_h_A;
  c20_x_x = c20_w_x;
  c20_ib_y = c20_x_x / 2.0;
  c20_v_b = c20_b_l;
  c20_jb_y = 5.0 * c20_v_b;
  c20_y_x = c20_bth + c20_q1;
  c20_ab_x = c20_y_x;
  c20_ab_x = muDoubleScalarCos(c20_ab_x);
  c20_j_a = c20_jb_y;
  c20_w_b = c20_ab_x;
  c20_kb_y = c20_j_a * c20_w_b;
  c20_i_A = c20_kb_y;
  c20_bb_x = c20_i_A;
  c20_cb_x = c20_bb_x;
  c20_lb_y = c20_cb_x / 2.0;
  c20_x_b = c20_b_lb;
  c20_mb_y = 3.0 * c20_x_b;
  c20_db_x = c20_bth;
  c20_eb_x = c20_db_x;
  c20_eb_x = muDoubleScalarCos(c20_eb_x);
  c20_k_a = c20_mb_y;
  c20_y_b = c20_eb_x;
  c20_nb_y = c20_k_a * c20_y_b;
  c20_ab_b = c20_b_l;
  c20_ob_y = 3.0 * c20_ab_b;
  c20_fb_x = (c20_bth + c20_q1) + c20_q2;
  c20_gb_x = c20_fb_x;
  c20_gb_x = muDoubleScalarCos(c20_gb_x);
  c20_l_a = c20_ob_y;
  c20_bb_b = c20_gb_x;
  c20_pb_y = c20_l_a * c20_bb_b;
  c20_j_A = c20_pb_y;
  c20_hb_x = c20_j_A;
  c20_ib_x = c20_hb_x;
  c20_qb_y = c20_ib_x / 2.0;
  c20_m_a = c20_b_m;
  c20_cb_b = (((c20_gb_y + c20_ib_y) + c20_lb_y) + c20_nb_y) + c20_qb_y;
  c20_rb_y = c20_m_a * c20_cb_b;
  c20_db_b = c20_b_m;
  c20_sb_y = 3.0 * c20_db_b;
  c20_k_A = c20_rb_y;
  c20_d_B = c20_sb_y + c20_b_mb;
  c20_jb_x = c20_k_A;
  c20_tb_y = c20_d_B;
  c20_kb_x = c20_jb_x;
  c20_ub_y = c20_tb_y;
  c20_vb_y = c20_kb_x / c20_ub_y;
  c20_n_a = c20_ab_y + c20_b_mb;
  c20_eb_b = (c20_fb_y - c20_base_x) + c20_vb_y;
  c20_wb_y = c20_n_a * c20_eb_b;
  c20_fb_b = c20_b_m;
  c20_xb_y = 3.0 * c20_fb_b;
  c20_gb_b = c20_b_m;
  c20_yb_y = 3.0 * c20_gb_b;
  c20_o_a = c20_base_y;
  c20_hb_b = c20_b_mb;
  c20_ac_y = c20_o_a * c20_hb_b;
  c20_ib_b = c20_b_m;
  c20_bc_y = 3.0 * c20_ib_b;
  c20_l_A = c20_ac_y;
  c20_e_B = c20_bc_y + c20_b_mb;
  c20_lb_x = c20_l_A;
  c20_cc_y = c20_e_B;
  c20_mb_x = c20_lb_x;
  c20_dc_y = c20_cc_y;
  c20_ec_y = c20_mb_x / c20_dc_y;
  c20_jb_b = c20_base_y;
  c20_fc_y = 3.0 * c20_jb_b;
  c20_nb_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_ob_x = c20_nb_x;
  c20_ob_x = muDoubleScalarSin(c20_ob_x);
  c20_p_a = c20_b_l;
  c20_kb_b = c20_ob_x;
  c20_gc_y = c20_p_a * c20_kb_b;
  c20_m_A = c20_gc_y;
  c20_pb_x = c20_m_A;
  c20_qb_x = c20_pb_x;
  c20_hc_y = c20_qb_x / 2.0;
  c20_lb_b = c20_b_l;
  c20_ic_y = 5.0 * c20_lb_b;
  c20_rb_x = c20_bth + c20_q1;
  c20_sb_x = c20_rb_x;
  c20_sb_x = muDoubleScalarSin(c20_sb_x);
  c20_q_a = c20_ic_y;
  c20_mb_b = c20_sb_x;
  c20_jc_y = c20_q_a * c20_mb_b;
  c20_n_A = c20_jc_y;
  c20_tb_x = c20_n_A;
  c20_ub_x = c20_tb_x;
  c20_kc_y = c20_ub_x / 2.0;
  c20_nb_b = c20_b_lb;
  c20_lc_y = 3.0 * c20_nb_b;
  c20_vb_x = c20_bth;
  c20_wb_x = c20_vb_x;
  c20_wb_x = muDoubleScalarSin(c20_wb_x);
  c20_r_a = c20_lc_y;
  c20_ob_b = c20_wb_x;
  c20_mc_y = c20_r_a * c20_ob_b;
  c20_pb_b = c20_b_l;
  c20_nc_y = 3.0 * c20_pb_b;
  c20_xb_x = (c20_bth + c20_q1) + c20_q2;
  c20_yb_x = c20_xb_x;
  c20_yb_x = muDoubleScalarSin(c20_yb_x);
  c20_s_a = c20_nc_y;
  c20_qb_b = c20_yb_x;
  c20_oc_y = c20_s_a * c20_qb_b;
  c20_o_A = c20_oc_y;
  c20_ac_x = c20_o_A;
  c20_bc_x = c20_ac_x;
  c20_pc_y = c20_bc_x / 2.0;
  c20_t_a = c20_b_m;
  c20_rb_b = (((c20_fc_y + c20_hc_y) + c20_kc_y) + c20_mc_y) + c20_pc_y;
  c20_qc_y = c20_t_a * c20_rb_b;
  c20_sb_b = c20_b_m;
  c20_rc_y = 3.0 * c20_sb_b;
  c20_p_A = c20_qc_y;
  c20_f_B = c20_rc_y + c20_b_mb;
  c20_cc_x = c20_p_A;
  c20_sc_y = c20_f_B;
  c20_dc_x = c20_cc_x;
  c20_tc_y = c20_sc_y;
  c20_uc_y = c20_dc_x / c20_tc_y;
  c20_u_a = c20_yb_y + c20_b_mb;
  c20_tb_b = (c20_ec_y - c20_base_y) + c20_uc_y;
  c20_vc_y = c20_u_a * c20_tb_b;
  c20_ub_b = c20_b_m;
  c20_wc_y = 3.0 * c20_ub_b;
  c20_v_a = c20_base_x;
  c20_vb_b = c20_b_mb;
  c20_xc_y = c20_v_a * c20_vb_b;
  c20_wb_b = c20_b_m;
  c20_yc_y = 3.0 * c20_wb_b;
  c20_q_A = c20_xc_y;
  c20_g_B = c20_yc_y + c20_b_mb;
  c20_ec_x = c20_q_A;
  c20_ad_y = c20_g_B;
  c20_fc_x = c20_ec_x;
  c20_bd_y = c20_ad_y;
  c20_cd_y = c20_fc_x / c20_bd_y;
  c20_xb_b = c20_base_x;
  c20_dd_y = 3.0 * c20_xb_b;
  c20_gc_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_hc_x = c20_gc_x;
  c20_hc_x = muDoubleScalarCos(c20_hc_x);
  c20_w_a = c20_b_l;
  c20_yb_b = c20_hc_x;
  c20_ed_y = c20_w_a * c20_yb_b;
  c20_r_A = c20_ed_y;
  c20_ic_x = c20_r_A;
  c20_jc_x = c20_ic_x;
  c20_fd_y = c20_jc_x / 2.0;
  c20_ac_b = c20_b_l;
  c20_gd_y = 5.0 * c20_ac_b;
  c20_kc_x = c20_bth + c20_q1;
  c20_lc_x = c20_kc_x;
  c20_lc_x = muDoubleScalarCos(c20_lc_x);
  c20_x_a = c20_gd_y;
  c20_bc_b = c20_lc_x;
  c20_hd_y = c20_x_a * c20_bc_b;
  c20_s_A = c20_hd_y;
  c20_mc_x = c20_s_A;
  c20_nc_x = c20_mc_x;
  c20_id_y = c20_nc_x / 2.0;
  c20_cc_b = c20_b_lb;
  c20_jd_y = 3.0 * c20_cc_b;
  c20_oc_x = c20_bth;
  c20_pc_x = c20_oc_x;
  c20_pc_x = muDoubleScalarCos(c20_pc_x);
  c20_y_a = c20_jd_y;
  c20_dc_b = c20_pc_x;
  c20_kd_y = c20_y_a * c20_dc_b;
  c20_ec_b = c20_b_l;
  c20_ld_y = 3.0 * c20_ec_b;
  c20_qc_x = (c20_bth + c20_q1) + c20_q2;
  c20_rc_x = c20_qc_x;
  c20_rc_x = muDoubleScalarCos(c20_rc_x);
  c20_ab_a = c20_ld_y;
  c20_fc_b = c20_rc_x;
  c20_md_y = c20_ab_a * c20_fc_b;
  c20_t_A = c20_md_y;
  c20_sc_x = c20_t_A;
  c20_tc_x = c20_sc_x;
  c20_nd_y = c20_tc_x / 2.0;
  c20_bb_a = c20_b_m;
  c20_gc_b = (((c20_dd_y + c20_fd_y) + c20_id_y) + c20_kd_y) + c20_nd_y;
  c20_od_y = c20_bb_a * c20_gc_b;
  c20_hc_b = c20_b_m;
  c20_pd_y = 3.0 * c20_hc_b;
  c20_u_A = c20_od_y;
  c20_h_B = c20_pd_y + c20_b_mb;
  c20_uc_x = c20_u_A;
  c20_qd_y = c20_h_B;
  c20_vc_x = c20_uc_x;
  c20_rd_y = c20_qd_y;
  c20_sd_y = c20_vc_x / c20_rd_y;
  c20_cb_a = -(c20_wc_y + c20_b_mb);
  c20_ic_b = (c20_cd_y - c20_base_x) + c20_sd_y;
  c20_td_y = c20_cb_a * c20_ic_b;
  c20_jc_b = c20_b_m;
  c20_ud_y = 3.0 * c20_jc_b;
  c20_db_a = c20_base_y;
  c20_kc_b = c20_b_mb;
  c20_vd_y = c20_db_a * c20_kc_b;
  c20_lc_b = c20_b_m;
  c20_wd_y = 3.0 * c20_lc_b;
  c20_v_A = c20_vd_y;
  c20_i_B = c20_wd_y + c20_b_mb;
  c20_wc_x = c20_v_A;
  c20_xd_y = c20_i_B;
  c20_xc_x = c20_wc_x;
  c20_yd_y = c20_xd_y;
  c20_ae_y = c20_xc_x / c20_yd_y;
  c20_mc_b = c20_base_y;
  c20_be_y = 3.0 * c20_mc_b;
  c20_yc_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_ad_x = c20_yc_x;
  c20_ad_x = muDoubleScalarSin(c20_ad_x);
  c20_eb_a = c20_b_l;
  c20_nc_b = c20_ad_x;
  c20_ce_y = c20_eb_a * c20_nc_b;
  c20_w_A = c20_ce_y;
  c20_bd_x = c20_w_A;
  c20_cd_x = c20_bd_x;
  c20_de_y = c20_cd_x / 2.0;
  c20_oc_b = c20_b_l;
  c20_ee_y = 5.0 * c20_oc_b;
  c20_dd_x = c20_bth + c20_q1;
  c20_ed_x = c20_dd_x;
  c20_ed_x = muDoubleScalarSin(c20_ed_x);
  c20_fb_a = c20_ee_y;
  c20_pc_b = c20_ed_x;
  c20_fe_y = c20_fb_a * c20_pc_b;
  c20_x_A = c20_fe_y;
  c20_fd_x = c20_x_A;
  c20_gd_x = c20_fd_x;
  c20_ge_y = c20_gd_x / 2.0;
  c20_qc_b = c20_b_lb;
  c20_he_y = 3.0 * c20_qc_b;
  c20_hd_x = c20_bth;
  c20_id_x = c20_hd_x;
  c20_id_x = muDoubleScalarSin(c20_id_x);
  c20_gb_a = c20_he_y;
  c20_rc_b = c20_id_x;
  c20_ie_y = c20_gb_a * c20_rc_b;
  c20_sc_b = c20_b_l;
  c20_je_y = 3.0 * c20_sc_b;
  c20_jd_x = (c20_bth + c20_q1) + c20_q2;
  c20_kd_x = c20_jd_x;
  c20_kd_x = muDoubleScalarSin(c20_kd_x);
  c20_hb_a = c20_je_y;
  c20_tc_b = c20_kd_x;
  c20_ke_y = c20_hb_a * c20_tc_b;
  c20_y_A = c20_ke_y;
  c20_ld_x = c20_y_A;
  c20_md_x = c20_ld_x;
  c20_le_y = c20_md_x / 2.0;
  c20_ib_a = c20_b_m;
  c20_uc_b = (((c20_be_y + c20_de_y) + c20_ge_y) + c20_ie_y) + c20_le_y;
  c20_me_y = c20_ib_a * c20_uc_b;
  c20_vc_b = c20_b_m;
  c20_ne_y = 3.0 * c20_vc_b;
  c20_ab_A = c20_me_y;
  c20_j_B = c20_ne_y + c20_b_mb;
  c20_nd_x = c20_ab_A;
  c20_oe_y = c20_j_B;
  c20_od_x = c20_nd_x;
  c20_pe_y = c20_oe_y;
  c20_qe_y = c20_od_x / c20_pe_y;
  c20_jb_a = c20_ud_y + c20_b_mb;
  c20_wc_b = (c20_ae_y - c20_base_y) + c20_qe_y;
  c20_re_y = c20_jb_a * c20_wc_b;
  c20_xc_b = c20_b_I;
  c20_se_y = 3.0 * c20_xc_b;
  c20_pd_x = c20_bth + c20_q1;
  c20_qd_x = c20_pd_x;
  c20_qd_x = muDoubleScalarSin(c20_qd_x);
  c20_kb_a = c20_b_l;
  c20_yc_b = c20_qd_x;
  c20_te_y = c20_kb_a * c20_yc_b;
  c20_rd_x = c20_bth;
  c20_sd_x = c20_rd_x;
  c20_sd_x = muDoubleScalarSin(c20_sd_x);
  c20_lb_a = c20_b_lb;
  c20_ad_b = c20_sd_x;
  c20_ue_y = c20_lb_a * c20_ad_b;
  c20_td_x = (c20_bth + c20_q1) + c20_q2;
  c20_ud_x = c20_td_x;
  c20_ud_x = muDoubleScalarSin(c20_ud_x);
  c20_mb_a = c20_b_l;
  c20_bd_b = c20_ud_x;
  c20_ve_y = c20_mb_a * c20_bd_b;
  c20_bb_A = c20_ve_y;
  c20_vd_x = c20_bb_A;
  c20_wd_x = c20_vd_x;
  c20_we_y = c20_wd_x / 2.0;
  c20_nb_a = c20_b_m;
  c20_cd_b = c20_mpower(chartInstance, (c20_te_y + c20_ue_y) + c20_we_y);
  c20_xe_y = c20_nb_a * c20_cd_b;
  c20_xd_x = c20_bth + c20_q1;
  c20_yd_x = c20_xd_x;
  c20_yd_x = muDoubleScalarSin(c20_yd_x);
  c20_ob_a = c20_b_l;
  c20_dd_b = c20_yd_x;
  c20_ye_y = c20_ob_a * c20_dd_b;
  c20_cb_A = c20_ye_y;
  c20_ae_x = c20_cb_A;
  c20_be_x = c20_ae_x;
  c20_af_y = c20_be_x / 2.0;
  c20_ce_x = c20_bth;
  c20_de_x = c20_ce_x;
  c20_de_x = muDoubleScalarSin(c20_de_x);
  c20_pb_a = c20_b_lb;
  c20_ed_b = c20_de_x;
  c20_bf_y = c20_pb_a * c20_ed_b;
  c20_qb_a = c20_b_m;
  c20_fd_b = c20_mpower(chartInstance, c20_af_y + c20_bf_y);
  c20_cf_y = c20_qb_a * c20_fd_b;
  c20_ee_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_fe_x = c20_ee_x;
  c20_fe_x = muDoubleScalarSin(c20_fe_x);
  c20_rb_a = c20_b_l;
  c20_gd_b = c20_fe_x;
  c20_df_y = c20_rb_a * c20_gd_b;
  c20_db_A = c20_df_y;
  c20_ge_x = c20_db_A;
  c20_he_x = c20_ge_x;
  c20_ef_y = c20_he_x / 2.0;
  c20_ie_x = c20_bth + c20_q1;
  c20_je_x = c20_ie_x;
  c20_je_x = muDoubleScalarSin(c20_je_x);
  c20_sb_a = c20_b_l;
  c20_hd_b = c20_je_x;
  c20_ff_y = c20_sb_a * c20_hd_b;
  c20_ke_x = c20_bth;
  c20_le_x = c20_ke_x;
  c20_le_x = muDoubleScalarSin(c20_le_x);
  c20_tb_a = c20_b_lb;
  c20_id_b = c20_le_x;
  c20_gf_y = c20_tb_a * c20_id_b;
  c20_me_x = (c20_bth + c20_q1) + c20_q2;
  c20_ne_x = c20_me_x;
  c20_ne_x = muDoubleScalarSin(c20_ne_x);
  c20_ub_a = c20_b_l;
  c20_jd_b = c20_ne_x;
  c20_hf_y = c20_ub_a * c20_jd_b;
  c20_vb_a = c20_b_m;
  c20_kd_b = c20_mpower(chartInstance, ((c20_ef_y + c20_ff_y) + c20_gf_y) +
                        c20_hf_y);
  c20_if_y = c20_vb_a * c20_kd_b;
  c20_ld_b = c20_b_I;
  c20_jf_y = 3.0 * c20_ld_b;
  c20_oe_x = c20_bth + c20_q1;
  c20_pe_x = c20_oe_x;
  c20_pe_x = muDoubleScalarCos(c20_pe_x);
  c20_wb_a = c20_b_l;
  c20_md_b = c20_pe_x;
  c20_kf_y = c20_wb_a * c20_md_b;
  c20_qe_x = c20_bth;
  c20_re_x = c20_qe_x;
  c20_re_x = muDoubleScalarCos(c20_re_x);
  c20_xb_a = c20_b_lb;
  c20_nd_b = c20_re_x;
  c20_lf_y = c20_xb_a * c20_nd_b;
  c20_se_x = (c20_bth + c20_q1) + c20_q2;
  c20_te_x = c20_se_x;
  c20_te_x = muDoubleScalarCos(c20_te_x);
  c20_yb_a = c20_b_l;
  c20_od_b = c20_te_x;
  c20_mf_y = c20_yb_a * c20_od_b;
  c20_eb_A = c20_mf_y;
  c20_ue_x = c20_eb_A;
  c20_ve_x = c20_ue_x;
  c20_nf_y = c20_ve_x / 2.0;
  c20_ac_a = c20_b_m;
  c20_pd_b = (c20_kf_y + c20_lf_y) + c20_nf_y;
  c20_of_y = c20_ac_a * c20_pd_b;
  c20_we_x = c20_bth + c20_q1;
  c20_xe_x = c20_we_x;
  c20_xe_x = muDoubleScalarSin(c20_xe_x);
  c20_bc_a = c20_b_l;
  c20_qd_b = c20_xe_x;
  c20_pf_y = c20_bc_a * c20_qd_b;
  c20_ye_x = c20_bth;
  c20_af_x = c20_ye_x;
  c20_af_x = muDoubleScalarSin(c20_af_x);
  c20_cc_a = c20_b_lb;
  c20_rd_b = c20_af_x;
  c20_qf_y = c20_cc_a * c20_rd_b;
  c20_bf_x = (c20_bth + c20_q1) + c20_q2;
  c20_cf_x = c20_bf_x;
  c20_cf_x = muDoubleScalarSin(c20_cf_x);
  c20_dc_a = c20_b_l;
  c20_sd_b = c20_cf_x;
  c20_rf_y = c20_dc_a * c20_sd_b;
  c20_fb_A = c20_rf_y;
  c20_df_x = c20_fb_A;
  c20_ef_x = c20_df_x;
  c20_sf_y = c20_ef_x / 2.0;
  c20_ec_a = c20_of_y;
  c20_td_b = (c20_pf_y + c20_qf_y) + c20_sf_y;
  c20_tf_y = c20_ec_a * c20_td_b;
  c20_ff_x = c20_bth + c20_q1;
  c20_gf_x = c20_ff_x;
  c20_gf_x = muDoubleScalarCos(c20_gf_x);
  c20_fc_a = c20_b_l;
  c20_ud_b = c20_gf_x;
  c20_uf_y = c20_fc_a * c20_ud_b;
  c20_gb_A = c20_uf_y;
  c20_hf_x = c20_gb_A;
  c20_if_x = c20_hf_x;
  c20_vf_y = c20_if_x / 2.0;
  c20_jf_x = c20_bth;
  c20_kf_x = c20_jf_x;
  c20_kf_x = muDoubleScalarCos(c20_kf_x);
  c20_gc_a = c20_b_lb;
  c20_vd_b = c20_kf_x;
  c20_wf_y = c20_gc_a * c20_vd_b;
  c20_hc_a = c20_b_m;
  c20_wd_b = c20_vf_y + c20_wf_y;
  c20_xf_y = c20_hc_a * c20_wd_b;
  c20_lf_x = c20_bth + c20_q1;
  c20_mf_x = c20_lf_x;
  c20_mf_x = muDoubleScalarSin(c20_mf_x);
  c20_ic_a = c20_b_l;
  c20_xd_b = c20_mf_x;
  c20_yf_y = c20_ic_a * c20_xd_b;
  c20_hb_A = c20_yf_y;
  c20_nf_x = c20_hb_A;
  c20_of_x = c20_nf_x;
  c20_ag_y = c20_of_x / 2.0;
  c20_pf_x = c20_bth;
  c20_qf_x = c20_pf_x;
  c20_qf_x = muDoubleScalarSin(c20_qf_x);
  c20_jc_a = c20_b_lb;
  c20_yd_b = c20_qf_x;
  c20_bg_y = c20_jc_a * c20_yd_b;
  c20_kc_a = c20_xf_y;
  c20_ae_b = c20_ag_y + c20_bg_y;
  c20_cg_y = c20_kc_a * c20_ae_b;
  c20_rf_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_sf_x = c20_rf_x;
  c20_sf_x = muDoubleScalarCos(c20_sf_x);
  c20_lc_a = c20_b_l;
  c20_be_b = c20_sf_x;
  c20_dg_y = c20_lc_a * c20_be_b;
  c20_ib_A = c20_dg_y;
  c20_tf_x = c20_ib_A;
  c20_uf_x = c20_tf_x;
  c20_eg_y = c20_uf_x / 2.0;
  c20_vf_x = c20_bth + c20_q1;
  c20_wf_x = c20_vf_x;
  c20_wf_x = muDoubleScalarCos(c20_wf_x);
  c20_mc_a = c20_b_l;
  c20_ce_b = c20_wf_x;
  c20_fg_y = c20_mc_a * c20_ce_b;
  c20_xf_x = c20_bth;
  c20_yf_x = c20_xf_x;
  c20_yf_x = muDoubleScalarCos(c20_yf_x);
  c20_nc_a = c20_b_lb;
  c20_de_b = c20_yf_x;
  c20_gg_y = c20_nc_a * c20_de_b;
  c20_ag_x = (c20_bth + c20_q1) + c20_q2;
  c20_bg_x = c20_ag_x;
  c20_bg_x = muDoubleScalarCos(c20_bg_x);
  c20_oc_a = c20_b_l;
  c20_ee_b = c20_bg_x;
  c20_hg_y = c20_oc_a * c20_ee_b;
  c20_pc_a = c20_b_m;
  c20_fe_b = ((c20_eg_y + c20_fg_y) + c20_gg_y) + c20_hg_y;
  c20_ig_y = c20_pc_a * c20_fe_b;
  c20_cg_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_dg_x = c20_cg_x;
  c20_dg_x = muDoubleScalarSin(c20_dg_x);
  c20_qc_a = c20_b_l;
  c20_ge_b = c20_dg_x;
  c20_jg_y = c20_qc_a * c20_ge_b;
  c20_jb_A = c20_jg_y;
  c20_eg_x = c20_jb_A;
  c20_fg_x = c20_eg_x;
  c20_kg_y = c20_fg_x / 2.0;
  c20_gg_x = c20_bth + c20_q1;
  c20_hg_x = c20_gg_x;
  c20_hg_x = muDoubleScalarSin(c20_hg_x);
  c20_rc_a = c20_b_l;
  c20_he_b = c20_hg_x;
  c20_lg_y = c20_rc_a * c20_he_b;
  c20_ig_x = c20_bth;
  c20_jg_x = c20_ig_x;
  c20_jg_x = muDoubleScalarSin(c20_jg_x);
  c20_sc_a = c20_b_lb;
  c20_ie_b = c20_jg_x;
  c20_mg_y = c20_sc_a * c20_ie_b;
  c20_kg_x = (c20_bth + c20_q1) + c20_q2;
  c20_lg_x = c20_kg_x;
  c20_lg_x = muDoubleScalarSin(c20_lg_x);
  c20_tc_a = c20_b_l;
  c20_je_b = c20_lg_x;
  c20_ng_y = c20_tc_a * c20_je_b;
  c20_uc_a = c20_ig_y;
  c20_ke_b = ((c20_kg_y + c20_lg_y) + c20_mg_y) + c20_ng_y;
  c20_og_y = c20_uc_a * c20_ke_b;
  c20_le_b = c20_b_I;
  c20_pg_y = 3.0 * c20_le_b;
  c20_me_b = c20_b_m;
  c20_qg_y = 3.0 * c20_me_b;
  c20_vc_a = c20_base_x;
  c20_ne_b = c20_b_mb;
  c20_rg_y = c20_vc_a * c20_ne_b;
  c20_oe_b = c20_b_m;
  c20_sg_y = 3.0 * c20_oe_b;
  c20_kb_A = c20_rg_y;
  c20_k_B = c20_sg_y + c20_b_mb;
  c20_mg_x = c20_kb_A;
  c20_tg_y = c20_k_B;
  c20_ng_x = c20_mg_x;
  c20_ug_y = c20_tg_y;
  c20_vg_y = c20_ng_x / c20_ug_y;
  c20_pe_b = c20_base_x;
  c20_wg_y = 3.0 * c20_pe_b;
  c20_og_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_pg_x = c20_og_x;
  c20_pg_x = muDoubleScalarCos(c20_pg_x);
  c20_wc_a = c20_b_l;
  c20_qe_b = c20_pg_x;
  c20_xg_y = c20_wc_a * c20_qe_b;
  c20_lb_A = c20_xg_y;
  c20_qg_x = c20_lb_A;
  c20_rg_x = c20_qg_x;
  c20_yg_y = c20_rg_x / 2.0;
  c20_re_b = c20_b_l;
  c20_ah_y = 5.0 * c20_re_b;
  c20_sg_x = c20_bth + c20_q1;
  c20_tg_x = c20_sg_x;
  c20_tg_x = muDoubleScalarCos(c20_tg_x);
  c20_xc_a = c20_ah_y;
  c20_se_b = c20_tg_x;
  c20_bh_y = c20_xc_a * c20_se_b;
  c20_mb_A = c20_bh_y;
  c20_ug_x = c20_mb_A;
  c20_vg_x = c20_ug_x;
  c20_ch_y = c20_vg_x / 2.0;
  c20_te_b = c20_b_lb;
  c20_dh_y = 3.0 * c20_te_b;
  c20_wg_x = c20_bth;
  c20_xg_x = c20_wg_x;
  c20_xg_x = muDoubleScalarCos(c20_xg_x);
  c20_yc_a = c20_dh_y;
  c20_ue_b = c20_xg_x;
  c20_eh_y = c20_yc_a * c20_ue_b;
  c20_ve_b = c20_b_l;
  c20_fh_y = 3.0 * c20_ve_b;
  c20_yg_x = (c20_bth + c20_q1) + c20_q2;
  c20_ah_x = c20_yg_x;
  c20_ah_x = muDoubleScalarCos(c20_ah_x);
  c20_ad_a = c20_fh_y;
  c20_we_b = c20_ah_x;
  c20_gh_y = c20_ad_a * c20_we_b;
  c20_nb_A = c20_gh_y;
  c20_bh_x = c20_nb_A;
  c20_ch_x = c20_bh_x;
  c20_hh_y = c20_ch_x / 2.0;
  c20_bd_a = c20_b_m;
  c20_xe_b = (((c20_wg_y + c20_yg_y) + c20_ch_y) + c20_eh_y) + c20_hh_y;
  c20_ih_y = c20_bd_a * c20_xe_b;
  c20_ye_b = c20_b_m;
  c20_jh_y = 3.0 * c20_ye_b;
  c20_ob_A = c20_ih_y;
  c20_l_B = c20_jh_y + c20_b_mb;
  c20_dh_x = c20_ob_A;
  c20_kh_y = c20_l_B;
  c20_eh_x = c20_dh_x;
  c20_lh_y = c20_kh_y;
  c20_mh_y = c20_eh_x / c20_lh_y;
  c20_cd_a = -(c20_qg_y + c20_b_mb);
  c20_af_b = (c20_vg_y - c20_base_x) + c20_mh_y;
  c20_nh_y = c20_cd_a * c20_af_b;
  c20_bf_b = c20_b_I;
  c20_oh_y = 3.0 * c20_bf_b;
  c20_fh_x = c20_bth + c20_q1;
  c20_gh_x = c20_fh_x;
  c20_gh_x = muDoubleScalarCos(c20_gh_x);
  c20_dd_a = c20_b_l;
  c20_cf_b = c20_gh_x;
  c20_ph_y = c20_dd_a * c20_cf_b;
  c20_hh_x = c20_bth;
  c20_ih_x = c20_hh_x;
  c20_ih_x = muDoubleScalarCos(c20_ih_x);
  c20_ed_a = c20_b_lb;
  c20_df_b = c20_ih_x;
  c20_qh_y = c20_ed_a * c20_df_b;
  c20_jh_x = (c20_bth + c20_q1) + c20_q2;
  c20_kh_x = c20_jh_x;
  c20_kh_x = muDoubleScalarCos(c20_kh_x);
  c20_fd_a = c20_b_l;
  c20_ef_b = c20_kh_x;
  c20_rh_y = c20_fd_a * c20_ef_b;
  c20_pb_A = c20_rh_y;
  c20_lh_x = c20_pb_A;
  c20_mh_x = c20_lh_x;
  c20_sh_y = c20_mh_x / 2.0;
  c20_gd_a = c20_b_m;
  c20_ff_b = (c20_ph_y + c20_qh_y) + c20_sh_y;
  c20_th_y = c20_gd_a * c20_ff_b;
  c20_nh_x = c20_bth + c20_q1;
  c20_oh_x = c20_nh_x;
  c20_oh_x = muDoubleScalarSin(c20_oh_x);
  c20_hd_a = c20_b_l;
  c20_gf_b = c20_oh_x;
  c20_uh_y = c20_hd_a * c20_gf_b;
  c20_ph_x = c20_bth;
  c20_qh_x = c20_ph_x;
  c20_qh_x = muDoubleScalarSin(c20_qh_x);
  c20_id_a = c20_b_lb;
  c20_hf_b = c20_qh_x;
  c20_vh_y = c20_id_a * c20_hf_b;
  c20_rh_x = (c20_bth + c20_q1) + c20_q2;
  c20_sh_x = c20_rh_x;
  c20_sh_x = muDoubleScalarSin(c20_sh_x);
  c20_jd_a = c20_b_l;
  c20_if_b = c20_sh_x;
  c20_wh_y = c20_jd_a * c20_if_b;
  c20_qb_A = c20_wh_y;
  c20_th_x = c20_qb_A;
  c20_uh_x = c20_th_x;
  c20_xh_y = c20_uh_x / 2.0;
  c20_kd_a = c20_th_y;
  c20_jf_b = (c20_uh_y + c20_vh_y) + c20_xh_y;
  c20_yh_y = c20_kd_a * c20_jf_b;
  c20_vh_x = c20_bth + c20_q1;
  c20_wh_x = c20_vh_x;
  c20_wh_x = muDoubleScalarCos(c20_wh_x);
  c20_ld_a = c20_b_l;
  c20_kf_b = c20_wh_x;
  c20_ai_y = c20_ld_a * c20_kf_b;
  c20_rb_A = c20_ai_y;
  c20_xh_x = c20_rb_A;
  c20_yh_x = c20_xh_x;
  c20_bi_y = c20_yh_x / 2.0;
  c20_ai_x = c20_bth;
  c20_bi_x = c20_ai_x;
  c20_bi_x = muDoubleScalarCos(c20_bi_x);
  c20_md_a = c20_b_lb;
  c20_lf_b = c20_bi_x;
  c20_ci_y = c20_md_a * c20_lf_b;
  c20_nd_a = c20_b_m;
  c20_mf_b = c20_bi_y + c20_ci_y;
  c20_di_y = c20_nd_a * c20_mf_b;
  c20_ci_x = c20_bth + c20_q1;
  c20_di_x = c20_ci_x;
  c20_di_x = muDoubleScalarSin(c20_di_x);
  c20_od_a = c20_b_l;
  c20_nf_b = c20_di_x;
  c20_ei_y = c20_od_a * c20_nf_b;
  c20_sb_A = c20_ei_y;
  c20_ei_x = c20_sb_A;
  c20_fi_x = c20_ei_x;
  c20_fi_y = c20_fi_x / 2.0;
  c20_gi_x = c20_bth;
  c20_hi_x = c20_gi_x;
  c20_hi_x = muDoubleScalarSin(c20_hi_x);
  c20_pd_a = c20_b_lb;
  c20_of_b = c20_hi_x;
  c20_gi_y = c20_pd_a * c20_of_b;
  c20_qd_a = c20_di_y;
  c20_pf_b = c20_fi_y + c20_gi_y;
  c20_hi_y = c20_qd_a * c20_pf_b;
  c20_ii_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_ji_x = c20_ii_x;
  c20_ji_x = muDoubleScalarCos(c20_ji_x);
  c20_rd_a = c20_b_l;
  c20_qf_b = c20_ji_x;
  c20_ii_y = c20_rd_a * c20_qf_b;
  c20_tb_A = c20_ii_y;
  c20_ki_x = c20_tb_A;
  c20_li_x = c20_ki_x;
  c20_ji_y = c20_li_x / 2.0;
  c20_mi_x = c20_bth + c20_q1;
  c20_ni_x = c20_mi_x;
  c20_ni_x = muDoubleScalarCos(c20_ni_x);
  c20_sd_a = c20_b_l;
  c20_rf_b = c20_ni_x;
  c20_ki_y = c20_sd_a * c20_rf_b;
  c20_oi_x = c20_bth;
  c20_pi_x = c20_oi_x;
  c20_pi_x = muDoubleScalarCos(c20_pi_x);
  c20_td_a = c20_b_lb;
  c20_sf_b = c20_pi_x;
  c20_li_y = c20_td_a * c20_sf_b;
  c20_qi_x = (c20_bth + c20_q1) + c20_q2;
  c20_ri_x = c20_qi_x;
  c20_ri_x = muDoubleScalarCos(c20_ri_x);
  c20_ud_a = c20_b_l;
  c20_tf_b = c20_ri_x;
  c20_mi_y = c20_ud_a * c20_tf_b;
  c20_vd_a = c20_b_m;
  c20_uf_b = ((c20_ji_y + c20_ki_y) + c20_li_y) + c20_mi_y;
  c20_ni_y = c20_vd_a * c20_uf_b;
  c20_si_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_ti_x = c20_si_x;
  c20_ti_x = muDoubleScalarSin(c20_ti_x);
  c20_wd_a = c20_b_l;
  c20_vf_b = c20_ti_x;
  c20_oi_y = c20_wd_a * c20_vf_b;
  c20_ub_A = c20_oi_y;
  c20_ui_x = c20_ub_A;
  c20_vi_x = c20_ui_x;
  c20_pi_y = c20_vi_x / 2.0;
  c20_wi_x = c20_bth + c20_q1;
  c20_xi_x = c20_wi_x;
  c20_xi_x = muDoubleScalarSin(c20_xi_x);
  c20_xd_a = c20_b_l;
  c20_wf_b = c20_xi_x;
  c20_qi_y = c20_xd_a * c20_wf_b;
  c20_yi_x = c20_bth;
  c20_aj_x = c20_yi_x;
  c20_aj_x = muDoubleScalarSin(c20_aj_x);
  c20_yd_a = c20_b_lb;
  c20_xf_b = c20_aj_x;
  c20_ri_y = c20_yd_a * c20_xf_b;
  c20_bj_x = (c20_bth + c20_q1) + c20_q2;
  c20_cj_x = c20_bj_x;
  c20_cj_x = muDoubleScalarSin(c20_cj_x);
  c20_ae_a = c20_b_l;
  c20_yf_b = c20_cj_x;
  c20_si_y = c20_ae_a * c20_yf_b;
  c20_be_a = c20_ni_y;
  c20_ag_b = ((c20_pi_y + c20_qi_y) + c20_ri_y) + c20_si_y;
  c20_ti_y = c20_be_a * c20_ag_b;
  c20_bg_b = c20_b_I;
  c20_ui_y = 3.0 * c20_bg_b;
  c20_dj_x = c20_bth + c20_q1;
  c20_ej_x = c20_dj_x;
  c20_ej_x = muDoubleScalarCos(c20_ej_x);
  c20_ce_a = c20_b_l;
  c20_cg_b = c20_ej_x;
  c20_vi_y = c20_ce_a * c20_cg_b;
  c20_fj_x = c20_bth;
  c20_gj_x = c20_fj_x;
  c20_gj_x = muDoubleScalarCos(c20_gj_x);
  c20_de_a = c20_b_lb;
  c20_dg_b = c20_gj_x;
  c20_wi_y = c20_de_a * c20_dg_b;
  c20_hj_x = (c20_bth + c20_q1) + c20_q2;
  c20_ij_x = c20_hj_x;
  c20_ij_x = muDoubleScalarCos(c20_ij_x);
  c20_ee_a = c20_b_l;
  c20_eg_b = c20_ij_x;
  c20_xi_y = c20_ee_a * c20_eg_b;
  c20_vb_A = c20_xi_y;
  c20_jj_x = c20_vb_A;
  c20_kj_x = c20_jj_x;
  c20_yi_y = c20_kj_x / 2.0;
  c20_fe_a = c20_b_m;
  c20_fg_b = c20_mpower(chartInstance, (c20_vi_y + c20_wi_y) + c20_yi_y);
  c20_aj_y = c20_fe_a * c20_fg_b;
  c20_lj_x = c20_bth + c20_q1;
  c20_mj_x = c20_lj_x;
  c20_mj_x = muDoubleScalarCos(c20_mj_x);
  c20_ge_a = c20_b_l;
  c20_gg_b = c20_mj_x;
  c20_bj_y = c20_ge_a * c20_gg_b;
  c20_wb_A = c20_bj_y;
  c20_nj_x = c20_wb_A;
  c20_oj_x = c20_nj_x;
  c20_cj_y = c20_oj_x / 2.0;
  c20_pj_x = c20_bth;
  c20_qj_x = c20_pj_x;
  c20_qj_x = muDoubleScalarCos(c20_qj_x);
  c20_he_a = c20_b_lb;
  c20_hg_b = c20_qj_x;
  c20_dj_y = c20_he_a * c20_hg_b;
  c20_ie_a = c20_b_m;
  c20_ig_b = c20_mpower(chartInstance, c20_cj_y + c20_dj_y);
  c20_ej_y = c20_ie_a * c20_ig_b;
  c20_rj_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_sj_x = c20_rj_x;
  c20_sj_x = muDoubleScalarCos(c20_sj_x);
  c20_je_a = c20_b_l;
  c20_jg_b = c20_sj_x;
  c20_fj_y = c20_je_a * c20_jg_b;
  c20_xb_A = c20_fj_y;
  c20_tj_x = c20_xb_A;
  c20_uj_x = c20_tj_x;
  c20_gj_y = c20_uj_x / 2.0;
  c20_vj_x = c20_bth + c20_q1;
  c20_wj_x = c20_vj_x;
  c20_wj_x = muDoubleScalarCos(c20_wj_x);
  c20_ke_a = c20_b_l;
  c20_kg_b = c20_wj_x;
  c20_hj_y = c20_ke_a * c20_kg_b;
  c20_xj_x = c20_bth;
  c20_yj_x = c20_xj_x;
  c20_yj_x = muDoubleScalarCos(c20_yj_x);
  c20_le_a = c20_b_lb;
  c20_lg_b = c20_yj_x;
  c20_ij_y = c20_le_a * c20_lg_b;
  c20_ak_x = (c20_bth + c20_q1) + c20_q2;
  c20_bk_x = c20_ak_x;
  c20_bk_x = muDoubleScalarCos(c20_bk_x);
  c20_me_a = c20_b_l;
  c20_mg_b = c20_bk_x;
  c20_jj_y = c20_me_a * c20_mg_b;
  c20_ne_a = c20_b_m;
  c20_ng_b = c20_mpower(chartInstance, ((c20_gj_y + c20_hj_y) + c20_ij_y) +
                        c20_jj_y);
  c20_kj_y = c20_ne_a * c20_ng_b;
  c20_og_b = c20_b_I;
  c20_lj_y = 3.0 * c20_og_b;
  c20_pg_b = c20_b_m;
  c20_mj_y = 3.0 * c20_pg_b;
  c20_oe_a = c20_base_y;
  c20_qg_b = c20_b_mb;
  c20_nj_y = c20_oe_a * c20_qg_b;
  c20_rg_b = c20_b_m;
  c20_oj_y = 3.0 * c20_rg_b;
  c20_yb_A = c20_nj_y;
  c20_m_B = c20_oj_y + c20_b_mb;
  c20_ck_x = c20_yb_A;
  c20_pj_y = c20_m_B;
  c20_dk_x = c20_ck_x;
  c20_qj_y = c20_pj_y;
  c20_rj_y = c20_dk_x / c20_qj_y;
  c20_sg_b = c20_base_y;
  c20_sj_y = 3.0 * c20_sg_b;
  c20_ek_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_fk_x = c20_ek_x;
  c20_fk_x = muDoubleScalarSin(c20_fk_x);
  c20_pe_a = c20_b_l;
  c20_tg_b = c20_fk_x;
  c20_tj_y = c20_pe_a * c20_tg_b;
  c20_ac_A = c20_tj_y;
  c20_gk_x = c20_ac_A;
  c20_hk_x = c20_gk_x;
  c20_uj_y = c20_hk_x / 2.0;
  c20_ug_b = c20_b_l;
  c20_vj_y = 5.0 * c20_ug_b;
  c20_ik_x = c20_bth + c20_q1;
  c20_jk_x = c20_ik_x;
  c20_jk_x = muDoubleScalarSin(c20_jk_x);
  c20_qe_a = c20_vj_y;
  c20_vg_b = c20_jk_x;
  c20_wj_y = c20_qe_a * c20_vg_b;
  c20_bc_A = c20_wj_y;
  c20_kk_x = c20_bc_A;
  c20_lk_x = c20_kk_x;
  c20_xj_y = c20_lk_x / 2.0;
  c20_wg_b = c20_b_lb;
  c20_yj_y = 3.0 * c20_wg_b;
  c20_mk_x = c20_bth;
  c20_nk_x = c20_mk_x;
  c20_nk_x = muDoubleScalarSin(c20_nk_x);
  c20_re_a = c20_yj_y;
  c20_xg_b = c20_nk_x;
  c20_ak_y = c20_re_a * c20_xg_b;
  c20_yg_b = c20_b_l;
  c20_bk_y = 3.0 * c20_yg_b;
  c20_ok_x = (c20_bth + c20_q1) + c20_q2;
  c20_pk_x = c20_ok_x;
  c20_pk_x = muDoubleScalarSin(c20_pk_x);
  c20_se_a = c20_bk_y;
  c20_ah_b = c20_pk_x;
  c20_ck_y = c20_se_a * c20_ah_b;
  c20_cc_A = c20_ck_y;
  c20_qk_x = c20_cc_A;
  c20_rk_x = c20_qk_x;
  c20_dk_y = c20_rk_x / 2.0;
  c20_te_a = c20_b_m;
  c20_bh_b = (((c20_sj_y + c20_uj_y) + c20_xj_y) + c20_ak_y) + c20_dk_y;
  c20_ek_y = c20_te_a * c20_bh_b;
  c20_ch_b = c20_b_m;
  c20_fk_y = 3.0 * c20_ch_b;
  c20_dc_A = c20_ek_y;
  c20_n_B = c20_fk_y + c20_b_mb;
  c20_sk_x = c20_dc_A;
  c20_gk_y = c20_n_B;
  c20_tk_x = c20_sk_x;
  c20_hk_y = c20_gk_y;
  c20_ik_y = c20_tk_x / c20_hk_y;
  c20_ue_a = -(c20_mj_y + c20_b_mb);
  c20_dh_b = (c20_rj_y - c20_base_y) + c20_ik_y;
  c20_jk_y = c20_ue_a * c20_dh_b;
  c20_eh_b = c20_b_m;
  c20_kk_y = 3.0 * c20_eh_b;
  c20_ve_a = c20_base_x;
  c20_fh_b = c20_b_mb;
  c20_lk_y = c20_ve_a * c20_fh_b;
  c20_gh_b = c20_b_m;
  c20_mk_y = 3.0 * c20_gh_b;
  c20_ec_A = c20_lk_y;
  c20_o_B = c20_mk_y + c20_b_mb;
  c20_uk_x = c20_ec_A;
  c20_nk_y = c20_o_B;
  c20_vk_x = c20_uk_x;
  c20_ok_y = c20_nk_y;
  c20_pk_y = c20_vk_x / c20_ok_y;
  c20_hh_b = c20_base_x;
  c20_qk_y = 3.0 * c20_hh_b;
  c20_wk_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_xk_x = c20_wk_x;
  c20_xk_x = muDoubleScalarCos(c20_xk_x);
  c20_we_a = c20_b_l;
  c20_ih_b = c20_xk_x;
  c20_rk_y = c20_we_a * c20_ih_b;
  c20_fc_A = c20_rk_y;
  c20_yk_x = c20_fc_A;
  c20_al_x = c20_yk_x;
  c20_sk_y = c20_al_x / 2.0;
  c20_jh_b = c20_b_l;
  c20_tk_y = 5.0 * c20_jh_b;
  c20_bl_x = c20_bth + c20_q1;
  c20_cl_x = c20_bl_x;
  c20_cl_x = muDoubleScalarCos(c20_cl_x);
  c20_xe_a = c20_tk_y;
  c20_kh_b = c20_cl_x;
  c20_uk_y = c20_xe_a * c20_kh_b;
  c20_gc_A = c20_uk_y;
  c20_dl_x = c20_gc_A;
  c20_el_x = c20_dl_x;
  c20_vk_y = c20_el_x / 2.0;
  c20_lh_b = c20_b_lb;
  c20_wk_y = 3.0 * c20_lh_b;
  c20_fl_x = c20_bth;
  c20_gl_x = c20_fl_x;
  c20_gl_x = muDoubleScalarCos(c20_gl_x);
  c20_ye_a = c20_wk_y;
  c20_mh_b = c20_gl_x;
  c20_xk_y = c20_ye_a * c20_mh_b;
  c20_nh_b = c20_b_l;
  c20_yk_y = 3.0 * c20_nh_b;
  c20_hl_x = (c20_bth + c20_q1) + c20_q2;
  c20_il_x = c20_hl_x;
  c20_il_x = muDoubleScalarCos(c20_il_x);
  c20_af_a = c20_yk_y;
  c20_oh_b = c20_il_x;
  c20_al_y = c20_af_a * c20_oh_b;
  c20_hc_A = c20_al_y;
  c20_jl_x = c20_hc_A;
  c20_kl_x = c20_jl_x;
  c20_bl_y = c20_kl_x / 2.0;
  c20_bf_a = c20_b_m;
  c20_ph_b = (((c20_qk_y + c20_sk_y) + c20_vk_y) + c20_xk_y) + c20_bl_y;
  c20_cl_y = c20_bf_a * c20_ph_b;
  c20_qh_b = c20_b_m;
  c20_dl_y = 3.0 * c20_qh_b;
  c20_ic_A = c20_cl_y;
  c20_p_B = c20_dl_y + c20_b_mb;
  c20_ll_x = c20_ic_A;
  c20_el_y = c20_p_B;
  c20_ml_x = c20_ll_x;
  c20_fl_y = c20_el_y;
  c20_gl_y = c20_ml_x / c20_fl_y;
  c20_cf_a = c20_kk_y + c20_b_mb;
  c20_rh_b = (c20_pk_y - c20_base_x) + c20_gl_y;
  c20_hl_y = c20_cf_a * c20_rh_b;
  c20_sh_b = c20_b_I;
  c20_il_y = 3.0 * c20_sh_b;
  c20_th_b = c20_b_I;
  c20_jl_y = 3.0 * c20_th_b;
  c20_uh_b = c20_b_I;
  c20_kl_y = 3.0 * c20_uh_b;
  c20_nl_x = c20_bth + c20_q1;
  c20_ol_x = c20_nl_x;
  c20_ol_x = muDoubleScalarCos(c20_ol_x);
  c20_df_a = c20_b_l;
  c20_vh_b = c20_ol_x;
  c20_ll_y = c20_df_a * c20_vh_b;
  c20_pl_x = c20_bth;
  c20_ql_x = c20_pl_x;
  c20_ql_x = muDoubleScalarCos(c20_ql_x);
  c20_ef_a = c20_b_lb;
  c20_wh_b = c20_ql_x;
  c20_ml_y = c20_ef_a * c20_wh_b;
  c20_rl_x = (c20_bth + c20_q1) + c20_q2;
  c20_sl_x = c20_rl_x;
  c20_sl_x = muDoubleScalarCos(c20_sl_x);
  c20_ff_a = c20_b_l;
  c20_xh_b = c20_sl_x;
  c20_nl_y = c20_ff_a * c20_xh_b;
  c20_jc_A = c20_nl_y;
  c20_tl_x = c20_jc_A;
  c20_ul_x = c20_tl_x;
  c20_ol_y = c20_ul_x / 2.0;
  c20_gf_a = c20_b_m;
  c20_yh_b = c20_mpower(chartInstance, (c20_ll_y + c20_ml_y) + c20_ol_y);
  c20_pl_y = c20_gf_a * c20_yh_b;
  c20_vl_x = c20_bth + c20_q1;
  c20_wl_x = c20_vl_x;
  c20_wl_x = muDoubleScalarCos(c20_wl_x);
  c20_hf_a = c20_b_l;
  c20_ai_b = c20_wl_x;
  c20_ql_y = c20_hf_a * c20_ai_b;
  c20_kc_A = c20_ql_y;
  c20_xl_x = c20_kc_A;
  c20_yl_x = c20_xl_x;
  c20_rl_y = c20_yl_x / 2.0;
  c20_am_x = c20_bth;
  c20_bm_x = c20_am_x;
  c20_bm_x = muDoubleScalarCos(c20_bm_x);
  c20_if_a = c20_b_lb;
  c20_bi_b = c20_bm_x;
  c20_sl_y = c20_if_a * c20_bi_b;
  c20_jf_a = c20_b_m;
  c20_ci_b = c20_mpower(chartInstance, c20_rl_y + c20_sl_y);
  c20_tl_y = c20_jf_a * c20_ci_b;
  c20_cm_x = c20_bth + c20_q1;
  c20_dm_x = c20_cm_x;
  c20_dm_x = muDoubleScalarSin(c20_dm_x);
  c20_kf_a = c20_b_l;
  c20_di_b = c20_dm_x;
  c20_ul_y = c20_kf_a * c20_di_b;
  c20_em_x = c20_bth;
  c20_fm_x = c20_em_x;
  c20_fm_x = muDoubleScalarSin(c20_fm_x);
  c20_lf_a = c20_b_lb;
  c20_ei_b = c20_fm_x;
  c20_vl_y = c20_lf_a * c20_ei_b;
  c20_gm_x = (c20_bth + c20_q1) + c20_q2;
  c20_hm_x = c20_gm_x;
  c20_hm_x = muDoubleScalarSin(c20_hm_x);
  c20_mf_a = c20_b_l;
  c20_fi_b = c20_hm_x;
  c20_wl_y = c20_mf_a * c20_fi_b;
  c20_lc_A = c20_wl_y;
  c20_im_x = c20_lc_A;
  c20_jm_x = c20_im_x;
  c20_xl_y = c20_jm_x / 2.0;
  c20_nf_a = c20_b_m;
  c20_gi_b = c20_mpower(chartInstance, (c20_ul_y + c20_vl_y) + c20_xl_y);
  c20_yl_y = c20_nf_a * c20_gi_b;
  c20_km_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_lm_x = c20_km_x;
  c20_lm_x = muDoubleScalarCos(c20_lm_x);
  c20_of_a = c20_b_l;
  c20_hi_b = c20_lm_x;
  c20_am_y = c20_of_a * c20_hi_b;
  c20_mc_A = c20_am_y;
  c20_mm_x = c20_mc_A;
  c20_nm_x = c20_mm_x;
  c20_bm_y = c20_nm_x / 2.0;
  c20_om_x = c20_bth + c20_q1;
  c20_pm_x = c20_om_x;
  c20_pm_x = muDoubleScalarCos(c20_pm_x);
  c20_pf_a = c20_b_l;
  c20_ii_b = c20_pm_x;
  c20_cm_y = c20_pf_a * c20_ii_b;
  c20_qm_x = c20_bth;
  c20_rm_x = c20_qm_x;
  c20_rm_x = muDoubleScalarCos(c20_rm_x);
  c20_qf_a = c20_b_lb;
  c20_ji_b = c20_rm_x;
  c20_dm_y = c20_qf_a * c20_ji_b;
  c20_sm_x = (c20_bth + c20_q1) + c20_q2;
  c20_tm_x = c20_sm_x;
  c20_tm_x = muDoubleScalarCos(c20_tm_x);
  c20_rf_a = c20_b_l;
  c20_ki_b = c20_tm_x;
  c20_em_y = c20_rf_a * c20_ki_b;
  c20_sf_a = c20_b_m;
  c20_li_b = c20_mpower(chartInstance, ((c20_bm_y + c20_cm_y) + c20_dm_y) +
                        c20_em_y);
  c20_fm_y = c20_sf_a * c20_li_b;
  c20_um_x = c20_bth + c20_q1;
  c20_vm_x = c20_um_x;
  c20_vm_x = muDoubleScalarSin(c20_vm_x);
  c20_tf_a = c20_b_l;
  c20_mi_b = c20_vm_x;
  c20_gm_y = c20_tf_a * c20_mi_b;
  c20_nc_A = c20_gm_y;
  c20_wm_x = c20_nc_A;
  c20_xm_x = c20_wm_x;
  c20_hm_y = c20_xm_x / 2.0;
  c20_ym_x = c20_bth;
  c20_an_x = c20_ym_x;
  c20_an_x = muDoubleScalarSin(c20_an_x);
  c20_uf_a = c20_b_lb;
  c20_ni_b = c20_an_x;
  c20_im_y = c20_uf_a * c20_ni_b;
  c20_vf_a = c20_b_m;
  c20_oi_b = c20_mpower(chartInstance, c20_hm_y + c20_im_y);
  c20_jm_y = c20_vf_a * c20_oi_b;
  c20_bn_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_cn_x = c20_bn_x;
  c20_cn_x = muDoubleScalarSin(c20_cn_x);
  c20_wf_a = c20_b_l;
  c20_pi_b = c20_cn_x;
  c20_km_y = c20_wf_a * c20_pi_b;
  c20_oc_A = c20_km_y;
  c20_dn_x = c20_oc_A;
  c20_en_x = c20_dn_x;
  c20_lm_y = c20_en_x / 2.0;
  c20_fn_x = c20_bth + c20_q1;
  c20_gn_x = c20_fn_x;
  c20_gn_x = muDoubleScalarSin(c20_gn_x);
  c20_xf_a = c20_b_l;
  c20_qi_b = c20_gn_x;
  c20_mm_y = c20_xf_a * c20_qi_b;
  c20_hn_x = c20_bth;
  c20_in_x = c20_hn_x;
  c20_in_x = muDoubleScalarSin(c20_in_x);
  c20_yf_a = c20_b_lb;
  c20_ri_b = c20_in_x;
  c20_nm_y = c20_yf_a * c20_ri_b;
  c20_jn_x = (c20_bth + c20_q1) + c20_q2;
  c20_kn_x = c20_jn_x;
  c20_kn_x = muDoubleScalarSin(c20_kn_x);
  c20_ag_a = c20_b_l;
  c20_si_b = c20_kn_x;
  c20_om_y = c20_ag_a * c20_si_b;
  c20_bg_a = c20_b_m;
  c20_ti_b = c20_mpower(chartInstance, ((c20_lm_y + c20_mm_y) + c20_nm_y) +
                        c20_om_y);
  c20_pm_y = c20_bg_a * c20_ti_b;
  c20_Hb[0] = c20_y + c20_b_mb;
  c20_Hb[6] = 0.0;
  c20_Hb[12] = 0.0;
  c20_Hb[18] = 0.0;
  c20_Hb[24] = 0.0;
  c20_Hb[30] = c20_x_y;
  c20_Hb[1] = 0.0;
  c20_Hb[7] = c20_y_y + c20_b_mb;
  c20_Hb[13] = 0.0;
  c20_Hb[19] = 0.0;
  c20_Hb[25] = 0.0;
  c20_Hb[31] = c20_wb_y;
  c20_Hb[2] = 0.0;
  c20_Hb[8] = 0.0;
  c20_Hb[14] = c20_xb_y + c20_b_mb;
  c20_Hb[20] = c20_vc_y;
  c20_Hb[26] = c20_td_y;
  c20_Hb[32] = 0.0;
  c20_Hb[3] = 0.0;
  c20_Hb[9] = 0.0;
  c20_Hb[15] = c20_re_y;
  c20_Hb[21] = (((c20_se_y + c20_b_Ib) + c20_xe_y) + c20_cf_y) + c20_if_y;
  c20_Hb[27] = (((c20_jf_y + c20_b_Ib) - c20_tf_y) - c20_cg_y) - c20_og_y;
  c20_Hb[33] = c20_pg_y + c20_b_Ib;
  c20_Hb[4] = 0.0;
  c20_Hb[10] = 0.0;
  c20_Hb[16] = c20_nh_y;
  c20_Hb[22] = (((c20_oh_y + c20_b_Ib) - c20_yh_y) - c20_hi_y) - c20_ti_y;
  c20_Hb[28] = (((c20_ui_y + c20_b_Ib) + c20_aj_y) + c20_ej_y) + c20_kj_y;
  c20_Hb[34] = c20_lj_y + c20_b_Ib;
  c20_Hb[5] = c20_jk_y;
  c20_Hb[11] = c20_hl_y;
  c20_Hb[17] = 0.0;
  c20_Hb[23] = c20_il_y + c20_b_Ib;
  c20_Hb[29] = c20_jl_y + c20_b_Ib;
  c20_Hb[35] = ((((((c20_kl_y + c20_b_Ib) + c20_pl_y) + c20_tl_y) + c20_yl_y) +
                 c20_fm_y) + c20_jm_y) + c20_pm_y;
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 25);
  c20_ln_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_mn_x = c20_ln_x;
  c20_mn_x = muDoubleScalarSin(c20_mn_x);
  c20_cg_a = c20_b_l;
  c20_ui_b = c20_mn_x;
  c20_qm_y = c20_cg_a * c20_ui_b;
  c20_pc_A = c20_qm_y;
  c20_nn_x = c20_pc_A;
  c20_on_x = c20_nn_x;
  c20_rm_y = c20_on_x / 2.0;
  c20_vi_b = c20_b_l;
  c20_sm_y = 5.0 * c20_vi_b;
  c20_pn_x = c20_bth + c20_q1;
  c20_qn_x = c20_pn_x;
  c20_qn_x = muDoubleScalarSin(c20_qn_x);
  c20_dg_a = c20_sm_y;
  c20_wi_b = c20_qn_x;
  c20_tm_y = c20_dg_a * c20_wi_b;
  c20_qc_A = c20_tm_y;
  c20_rn_x = c20_qc_A;
  c20_sn_x = c20_rn_x;
  c20_um_y = c20_sn_x / 2.0;
  c20_xi_b = c20_b_l;
  c20_vm_y = 3.0 * c20_xi_b;
  c20_tn_x = (c20_bth + c20_q1) + c20_q2;
  c20_un_x = c20_tn_x;
  c20_un_x = muDoubleScalarSin(c20_un_x);
  c20_eg_a = c20_vm_y;
  c20_yi_b = c20_un_x;
  c20_wm_y = c20_eg_a * c20_yi_b;
  c20_rc_A = c20_wm_y;
  c20_vn_x = c20_rc_A;
  c20_wn_x = c20_vn_x;
  c20_xm_y = c20_wn_x / 2.0;
  c20_fg_a = -c20_b_m;
  c20_aj_b = (c20_rm_y + c20_um_y) + c20_xm_y;
  c20_ym_y = c20_fg_a * c20_aj_b;
  c20_xn_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_yn_x = c20_xn_x;
  c20_yn_x = muDoubleScalarSin(c20_yn_x);
  c20_gg_a = c20_b_l;
  c20_bj_b = c20_yn_x;
  c20_an_y = c20_gg_a * c20_bj_b;
  c20_sc_A = c20_an_y;
  c20_ao_x = c20_sc_A;
  c20_bo_x = c20_ao_x;
  c20_bn_y = c20_bo_x / 2.0;
  c20_cj_b = c20_b_l;
  c20_cn_y = 3.0 * c20_cj_b;
  c20_co_x = (c20_bth + c20_q1) + c20_q2;
  c20_do_x = c20_co_x;
  c20_do_x = muDoubleScalarSin(c20_do_x);
  c20_hg_a = c20_cn_y;
  c20_dj_b = c20_do_x;
  c20_dn_y = c20_hg_a * c20_dj_b;
  c20_tc_A = c20_dn_y;
  c20_eo_x = c20_tc_A;
  c20_fo_x = c20_eo_x;
  c20_en_y = c20_fo_x / 2.0;
  c20_ig_a = -c20_b_m;
  c20_ej_b = c20_bn_y + c20_en_y;
  c20_fn_y = c20_ig_a * c20_ej_b;
  c20_jg_a = c20_b_l;
  c20_fj_b = c20_b_m;
  c20_gn_y = c20_jg_a * c20_fj_b;
  c20_go_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_ho_x = c20_go_x;
  c20_ho_x = muDoubleScalarSin(c20_ho_x);
  c20_kg_a = c20_gn_y;
  c20_gj_b = c20_ho_x;
  c20_hn_y = c20_kg_a * c20_gj_b;
  c20_uc_A = -c20_hn_y;
  c20_io_x = c20_uc_A;
  c20_jo_x = c20_io_x;
  c20_in_y = c20_jo_x / 2.0;
  c20_ko_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_lo_x = c20_ko_x;
  c20_lo_x = muDoubleScalarCos(c20_lo_x);
  c20_lg_a = c20_b_l;
  c20_hj_b = c20_lo_x;
  c20_jn_y = c20_lg_a * c20_hj_b;
  c20_vc_A = c20_jn_y;
  c20_mo_x = c20_vc_A;
  c20_no_x = c20_mo_x;
  c20_kn_y = c20_no_x / 2.0;
  c20_ij_b = c20_b_l;
  c20_ln_y = 5.0 * c20_ij_b;
  c20_oo_x = c20_bth + c20_q1;
  c20_po_x = c20_oo_x;
  c20_po_x = muDoubleScalarCos(c20_po_x);
  c20_mg_a = c20_ln_y;
  c20_jj_b = c20_po_x;
  c20_mn_y = c20_mg_a * c20_jj_b;
  c20_wc_A = c20_mn_y;
  c20_qo_x = c20_wc_A;
  c20_ro_x = c20_qo_x;
  c20_nn_y = c20_ro_x / 2.0;
  c20_kj_b = c20_b_l;
  c20_on_y = 3.0 * c20_kj_b;
  c20_so_x = (c20_bth + c20_q1) + c20_q2;
  c20_to_x = c20_so_x;
  c20_to_x = muDoubleScalarCos(c20_to_x);
  c20_ng_a = c20_on_y;
  c20_lj_b = c20_to_x;
  c20_pn_y = c20_ng_a * c20_lj_b;
  c20_xc_A = c20_pn_y;
  c20_uo_x = c20_xc_A;
  c20_vo_x = c20_uo_x;
  c20_qn_y = c20_vo_x / 2.0;
  c20_og_a = c20_b_m;
  c20_mj_b = (c20_kn_y + c20_nn_y) + c20_qn_y;
  c20_rn_y = c20_og_a * c20_mj_b;
  c20_wo_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_xo_x = c20_wo_x;
  c20_xo_x = muDoubleScalarCos(c20_xo_x);
  c20_pg_a = c20_b_l;
  c20_nj_b = c20_xo_x;
  c20_sn_y = c20_pg_a * c20_nj_b;
  c20_yc_A = c20_sn_y;
  c20_yo_x = c20_yc_A;
  c20_ap_x = c20_yo_x;
  c20_tn_y = c20_ap_x / 2.0;
  c20_oj_b = c20_b_l;
  c20_un_y = 3.0 * c20_oj_b;
  c20_bp_x = (c20_bth + c20_q1) + c20_q2;
  c20_cp_x = c20_bp_x;
  c20_cp_x = muDoubleScalarCos(c20_cp_x);
  c20_qg_a = c20_un_y;
  c20_pj_b = c20_cp_x;
  c20_vn_y = c20_qg_a * c20_pj_b;
  c20_ad_A = c20_vn_y;
  c20_dp_x = c20_ad_A;
  c20_ep_x = c20_dp_x;
  c20_wn_y = c20_ep_x / 2.0;
  c20_rg_a = c20_b_m;
  c20_qj_b = c20_tn_y + c20_wn_y;
  c20_xn_y = c20_rg_a * c20_qj_b;
  c20_sg_a = c20_b_l;
  c20_rj_b = c20_b_m;
  c20_yn_y = c20_sg_a * c20_rj_b;
  c20_fp_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_gp_x = c20_fp_x;
  c20_gp_x = muDoubleScalarCos(c20_gp_x);
  c20_tg_a = c20_yn_y;
  c20_sj_b = c20_gp_x;
  c20_ao_y = c20_tg_a * c20_sj_b;
  c20_bd_A = c20_ao_y;
  c20_hp_x = c20_bd_A;
  c20_ip_x = c20_hp_x;
  c20_bo_y = c20_ip_x / 2.0;
  c20_tj_b = c20_b_I;
  c20_co_y = 3.0 * c20_tj_b;
  c20_ug_a = c20_b_l;
  c20_uj_b = c20_b_m;
  c20_do_y = c20_ug_a * c20_uj_b;
  c20_jp_x = c20_bth + c20_q1;
  c20_kp_x = c20_jp_x;
  c20_kp_x = muDoubleScalarCos(c20_kp_x);
  c20_vg_a = c20_do_y;
  c20_vj_b = c20_kp_x;
  c20_eo_y = c20_vg_a * c20_vj_b;
  c20_lp_x = c20_bth + c20_q1;
  c20_mp_x = c20_lp_x;
  c20_mp_x = muDoubleScalarCos(c20_mp_x);
  c20_wg_a = c20_b_l;
  c20_wj_b = c20_mp_x;
  c20_fo_y = c20_wg_a * c20_wj_b;
  c20_cd_A = c20_fo_y;
  c20_np_x = c20_cd_A;
  c20_op_x = c20_np_x;
  c20_go_y = c20_op_x / 2.0;
  c20_pp_x = c20_bth;
  c20_qp_x = c20_pp_x;
  c20_qp_x = muDoubleScalarCos(c20_qp_x);
  c20_xg_a = c20_b_lb;
  c20_xj_b = c20_qp_x;
  c20_ho_y = c20_xg_a * c20_xj_b;
  c20_yg_a = c20_eo_y;
  c20_yj_b = c20_go_y + c20_ho_y;
  c20_io_y = c20_yg_a * c20_yj_b;
  c20_dd_A = c20_io_y;
  c20_rp_x = c20_dd_A;
  c20_sp_x = c20_rp_x;
  c20_jo_y = c20_sp_x / 2.0;
  c20_ah_a = c20_b_l;
  c20_ak_b = c20_b_m;
  c20_ko_y = c20_ah_a * c20_ak_b;
  c20_tp_x = c20_bth + c20_q1;
  c20_up_x = c20_tp_x;
  c20_up_x = muDoubleScalarSin(c20_up_x);
  c20_bh_a = c20_ko_y;
  c20_bk_b = c20_up_x;
  c20_lo_y = c20_bh_a * c20_bk_b;
  c20_vp_x = c20_bth + c20_q1;
  c20_wp_x = c20_vp_x;
  c20_wp_x = muDoubleScalarSin(c20_wp_x);
  c20_ch_a = c20_b_l;
  c20_ck_b = c20_wp_x;
  c20_mo_y = c20_ch_a * c20_ck_b;
  c20_xp_x = c20_bth;
  c20_yp_x = c20_xp_x;
  c20_yp_x = muDoubleScalarSin(c20_yp_x);
  c20_dh_a = c20_b_lb;
  c20_dk_b = c20_yp_x;
  c20_no_y = c20_dh_a * c20_dk_b;
  c20_aq_x = (c20_bth + c20_q1) + c20_q2;
  c20_bq_x = c20_aq_x;
  c20_bq_x = muDoubleScalarSin(c20_bq_x);
  c20_eh_a = c20_b_l;
  c20_ek_b = c20_bq_x;
  c20_oo_y = c20_eh_a * c20_ek_b;
  c20_ed_A = c20_oo_y;
  c20_cq_x = c20_ed_A;
  c20_dq_x = c20_cq_x;
  c20_po_y = c20_dq_x / 2.0;
  c20_fh_a = c20_lo_y;
  c20_fk_b = (c20_mo_y + c20_no_y) + c20_po_y;
  c20_qo_y = c20_fh_a * c20_fk_b;
  c20_fd_A = c20_qo_y;
  c20_eq_x = c20_fd_A;
  c20_fq_x = c20_eq_x;
  c20_ro_y = c20_fq_x / 2.0;
  c20_gh_a = c20_b_l;
  c20_gk_b = c20_b_m;
  c20_so_y = c20_gh_a * c20_gk_b;
  c20_gq_x = c20_bth + c20_q1;
  c20_hq_x = c20_gq_x;
  c20_hq_x = muDoubleScalarCos(c20_hq_x);
  c20_hh_a = c20_so_y;
  c20_hk_b = c20_hq_x;
  c20_to_y = c20_hh_a * c20_hk_b;
  c20_iq_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_jq_x = c20_iq_x;
  c20_jq_x = muDoubleScalarCos(c20_jq_x);
  c20_ih_a = c20_b_l;
  c20_ik_b = c20_jq_x;
  c20_uo_y = c20_ih_a * c20_ik_b;
  c20_gd_A = c20_uo_y;
  c20_kq_x = c20_gd_A;
  c20_lq_x = c20_kq_x;
  c20_vo_y = c20_lq_x / 2.0;
  c20_mq_x = c20_bth + c20_q1;
  c20_nq_x = c20_mq_x;
  c20_nq_x = muDoubleScalarCos(c20_nq_x);
  c20_jh_a = c20_b_l;
  c20_jk_b = c20_nq_x;
  c20_wo_y = c20_jh_a * c20_jk_b;
  c20_oq_x = c20_bth;
  c20_pq_x = c20_oq_x;
  c20_pq_x = muDoubleScalarCos(c20_pq_x);
  c20_kh_a = c20_b_lb;
  c20_kk_b = c20_pq_x;
  c20_xo_y = c20_kh_a * c20_kk_b;
  c20_qq_x = (c20_bth + c20_q1) + c20_q2;
  c20_rq_x = c20_qq_x;
  c20_rq_x = muDoubleScalarCos(c20_rq_x);
  c20_lh_a = c20_b_l;
  c20_lk_b = c20_rq_x;
  c20_yo_y = c20_lh_a * c20_lk_b;
  c20_mh_a = c20_to_y;
  c20_mk_b = ((c20_vo_y + c20_wo_y) + c20_xo_y) + c20_yo_y;
  c20_ap_y = c20_mh_a * c20_mk_b;
  c20_hd_A = c20_ap_y;
  c20_sq_x = c20_hd_A;
  c20_tq_x = c20_sq_x;
  c20_bp_y = c20_tq_x / 2.0;
  c20_nh_a = c20_b_l;
  c20_nk_b = c20_b_m;
  c20_cp_y = c20_nh_a * c20_nk_b;
  c20_uq_x = c20_bth + c20_q1;
  c20_vq_x = c20_uq_x;
  c20_vq_x = muDoubleScalarSin(c20_vq_x);
  c20_oh_a = c20_cp_y;
  c20_ok_b = c20_vq_x;
  c20_dp_y = c20_oh_a * c20_ok_b;
  c20_wq_x = c20_bth + c20_q1;
  c20_xq_x = c20_wq_x;
  c20_xq_x = muDoubleScalarSin(c20_xq_x);
  c20_ph_a = c20_b_l;
  c20_pk_b = c20_xq_x;
  c20_ep_y = c20_ph_a * c20_pk_b;
  c20_id_A = c20_ep_y;
  c20_yq_x = c20_id_A;
  c20_ar_x = c20_yq_x;
  c20_fp_y = c20_ar_x / 2.0;
  c20_br_x = c20_bth;
  c20_cr_x = c20_br_x;
  c20_cr_x = muDoubleScalarSin(c20_cr_x);
  c20_qh_a = c20_b_lb;
  c20_qk_b = c20_cr_x;
  c20_gp_y = c20_qh_a * c20_qk_b;
  c20_rh_a = c20_dp_y;
  c20_rk_b = c20_fp_y + c20_gp_y;
  c20_hp_y = c20_rh_a * c20_rk_b;
  c20_jd_A = c20_hp_y;
  c20_dr_x = c20_jd_A;
  c20_er_x = c20_dr_x;
  c20_ip_y = c20_er_x / 2.0;
  c20_sh_a = c20_b_l;
  c20_sk_b = c20_b_m;
  c20_jp_y = c20_sh_a * c20_sk_b;
  c20_fr_x = c20_bth + c20_q1;
  c20_gr_x = c20_fr_x;
  c20_gr_x = muDoubleScalarSin(c20_gr_x);
  c20_th_a = c20_jp_y;
  c20_tk_b = c20_gr_x;
  c20_kp_y = c20_th_a * c20_tk_b;
  c20_hr_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_ir_x = c20_hr_x;
  c20_ir_x = muDoubleScalarSin(c20_ir_x);
  c20_uh_a = c20_b_l;
  c20_uk_b = c20_ir_x;
  c20_lp_y = c20_uh_a * c20_uk_b;
  c20_kd_A = c20_lp_y;
  c20_jr_x = c20_kd_A;
  c20_kr_x = c20_jr_x;
  c20_mp_y = c20_kr_x / 2.0;
  c20_lr_x = c20_bth + c20_q1;
  c20_mr_x = c20_lr_x;
  c20_mr_x = muDoubleScalarSin(c20_mr_x);
  c20_vh_a = c20_b_l;
  c20_vk_b = c20_mr_x;
  c20_np_y = c20_vh_a * c20_vk_b;
  c20_nr_x = c20_bth;
  c20_or_x = c20_nr_x;
  c20_or_x = muDoubleScalarSin(c20_or_x);
  c20_wh_a = c20_b_lb;
  c20_wk_b = c20_or_x;
  c20_op_y = c20_wh_a * c20_wk_b;
  c20_pr_x = (c20_bth + c20_q1) + c20_q2;
  c20_qr_x = c20_pr_x;
  c20_qr_x = muDoubleScalarSin(c20_qr_x);
  c20_xh_a = c20_b_l;
  c20_xk_b = c20_qr_x;
  c20_pp_y = c20_xh_a * c20_xk_b;
  c20_yh_a = c20_kp_y;
  c20_yk_b = ((c20_mp_y + c20_np_y) + c20_op_y) + c20_pp_y;
  c20_qp_y = c20_yh_a * c20_yk_b;
  c20_ld_A = c20_qp_y;
  c20_rr_x = c20_ld_A;
  c20_sr_x = c20_rr_x;
  c20_rp_y = c20_sr_x / 2.0;
  c20_ai_a = c20_b_l;
  c20_al_b = c20_b_m;
  c20_sp_y = c20_ai_a * c20_al_b;
  c20_tr_x = c20_bth + c20_q1;
  c20_ur_x = c20_tr_x;
  c20_ur_x = muDoubleScalarCos(c20_ur_x);
  c20_bi_a = c20_sp_y;
  c20_bl_b = c20_ur_x;
  c20_tp_y = c20_bi_a * c20_bl_b;
  c20_vr_x = c20_bth + c20_q1;
  c20_wr_x = c20_vr_x;
  c20_wr_x = muDoubleScalarCos(c20_wr_x);
  c20_ci_a = c20_b_l;
  c20_cl_b = c20_wr_x;
  c20_up_y = c20_ci_a * c20_cl_b;
  c20_xr_x = c20_bth;
  c20_yr_x = c20_xr_x;
  c20_yr_x = muDoubleScalarCos(c20_yr_x);
  c20_di_a = c20_b_lb;
  c20_dl_b = c20_yr_x;
  c20_vp_y = c20_di_a * c20_dl_b;
  c20_as_x = (c20_bth + c20_q1) + c20_q2;
  c20_bs_x = c20_as_x;
  c20_bs_x = muDoubleScalarCos(c20_bs_x);
  c20_ei_a = c20_b_l;
  c20_el_b = c20_bs_x;
  c20_wp_y = c20_ei_a * c20_el_b;
  c20_md_A = c20_wp_y;
  c20_cs_x = c20_md_A;
  c20_ds_x = c20_cs_x;
  c20_xp_y = c20_ds_x / 2.0;
  c20_fi_a = c20_tp_y;
  c20_fl_b = (c20_up_y + c20_vp_y) + c20_xp_y;
  c20_yp_y = c20_fi_a * c20_fl_b;
  c20_nd_A = c20_yp_y;
  c20_es_x = c20_nd_A;
  c20_fs_x = c20_es_x;
  c20_aq_y = c20_fs_x / 2.0;
  c20_gl_b = c20_b_I;
  c20_bq_y = 2.0 * c20_gl_b;
  c20_Hbm[0] = c20_ym_y;
  c20_Hbm[6] = c20_fn_y;
  c20_Hbm[12] = c20_in_y;
  c20_Hbm[1] = c20_rn_y;
  c20_Hbm[7] = c20_xn_y;
  c20_Hbm[13] = c20_bo_y;
  c20_i18 = 0;
  for (c20_i19 = 0; c20_i19 < 3; c20_i19++) {
    c20_Hbm[c20_i18 + 2] = 0.0;
    c20_i18 += 6;
  }

  c20_i20 = 0;
  for (c20_i21 = 0; c20_i21 < 3; c20_i21++) {
    c20_Hbm[c20_i20 + 3] = 0.0;
    c20_i20 += 6;
  }

  c20_i22 = 0;
  for (c20_i23 = 0; c20_i23 < 3; c20_i23++) {
    c20_Hbm[c20_i22 + 4] = 0.0;
    c20_i22 += 6;
  }

  c20_Hbm[5] = (((((c20_co_y + c20_jo_y) + c20_ro_y) + c20_bp_y) + c20_ip_y) +
                c20_rp_y) + c20_aq_y;
  c20_Hbm[11] = c20_bq_y;
  c20_Hbm[17] = c20_b_I;
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 38);
  c20_gs_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_hs_x = c20_gs_x;
  c20_hs_x = muDoubleScalarSin(c20_hs_x);
  c20_gi_a = -c20_b_l;
  c20_hl_b = c20_hs_x;
  c20_cq_y = c20_gi_a * c20_hl_b;
  c20_is_x = c20_bth + c20_q1;
  c20_js_x = c20_is_x;
  c20_js_x = muDoubleScalarSin(c20_js_x);
  c20_hi_a = c20_b_l;
  c20_il_b = c20_js_x;
  c20_dq_y = c20_hi_a * c20_il_b;
  c20_ks_x = (c20_bth + c20_q1) + c20_q2;
  c20_ls_x = c20_ks_x;
  c20_ls_x = muDoubleScalarSin(c20_ls_x);
  c20_ii_a = c20_b_l;
  c20_jl_b = c20_ls_x;
  c20_eq_y = c20_ii_a * c20_jl_b;
  c20_ms_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_ns_x = c20_ms_x;
  c20_ns_x = muDoubleScalarSin(c20_ns_x);
  c20_ji_a = -c20_b_l;
  c20_kl_b = c20_ns_x;
  c20_fq_y = c20_ji_a * c20_kl_b;
  c20_os_x = (c20_bth + c20_q1) + c20_q2;
  c20_ps_x = c20_os_x;
  c20_ps_x = muDoubleScalarSin(c20_ps_x);
  c20_ki_a = c20_b_l;
  c20_ll_b = c20_ps_x;
  c20_gq_y = c20_ki_a * c20_ll_b;
  c20_qs_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_rs_x = c20_qs_x;
  c20_rs_x = muDoubleScalarSin(c20_rs_x);
  c20_li_a = -c20_b_l;
  c20_ml_b = c20_rs_x;
  c20_hq_y = c20_li_a * c20_ml_b;
  c20_ss_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_ts_x = c20_ss_x;
  c20_ts_x = muDoubleScalarCos(c20_ts_x);
  c20_mi_a = c20_b_l;
  c20_nl_b = c20_ts_x;
  c20_iq_y = c20_mi_a * c20_nl_b;
  c20_us_x = c20_bth + c20_q1;
  c20_vs_x = c20_us_x;
  c20_vs_x = muDoubleScalarCos(c20_vs_x);
  c20_ni_a = c20_b_l;
  c20_ol_b = c20_vs_x;
  c20_jq_y = c20_ni_a * c20_ol_b;
  c20_ws_x = (c20_bth + c20_q1) + c20_q2;
  c20_xs_x = c20_ws_x;
  c20_xs_x = muDoubleScalarCos(c20_xs_x);
  c20_oi_a = c20_b_l;
  c20_pl_b = c20_xs_x;
  c20_kq_y = c20_oi_a * c20_pl_b;
  c20_ys_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_at_x = c20_ys_x;
  c20_at_x = muDoubleScalarCos(c20_at_x);
  c20_pi_a = c20_b_l;
  c20_ql_b = c20_at_x;
  c20_lq_y = c20_pi_a * c20_ql_b;
  c20_bt_x = (c20_bth + c20_q1) + c20_q2;
  c20_ct_x = c20_bt_x;
  c20_ct_x = muDoubleScalarCos(c20_ct_x);
  c20_qi_a = c20_b_l;
  c20_rl_b = c20_ct_x;
  c20_mq_y = c20_qi_a * c20_rl_b;
  c20_dt_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_et_x = c20_dt_x;
  c20_et_x = muDoubleScalarCos(c20_et_x);
  c20_ri_a = c20_b_l;
  c20_sl_b = c20_et_x;
  c20_nq_y = c20_ri_a * c20_sl_b;
  c20_Jm[0] = (c20_cq_y - c20_dq_y) - c20_eq_y;
  c20_Jm[6] = c20_fq_y - c20_gq_y;
  c20_Jm[12] = c20_hq_y;
  c20_Jm[1] = (c20_iq_y + c20_jq_y) + c20_kq_y;
  c20_Jm[7] = c20_lq_y + c20_mq_y;
  c20_Jm[13] = c20_nq_y;
  c20_i24 = 0;
  for (c20_i25 = 0; c20_i25 < 3; c20_i25++) {
    c20_Jm[c20_i24 + 2] = 0.0;
    c20_i24 += 6;
  }

  c20_i26 = 0;
  for (c20_i27 = 0; c20_i27 < 3; c20_i27++) {
    c20_Jm[c20_i26 + 3] = 0.0;
    c20_i26 += 6;
  }

  c20_i28 = 0;
  for (c20_i29 = 0; c20_i29 < 3; c20_i29++) {
    c20_Jm[c20_i28 + 4] = 0.0;
    c20_i28 += 6;
  }

  c20_i30 = 0;
  for (c20_i31 = 0; c20_i31 < 3; c20_i31++) {
    c20_Jm[c20_i30 + 5] = 0.0;
    c20_i30 += 6;
  }

  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 46);
  for (c20_i32 = 0; c20_i32 < 36; c20_i32++) {
    c20_b_Hb[c20_i32] = c20_Hb[c20_i32];
  }

  c20_inv(chartInstance, c20_b_Hb, c20_si_a);
  for (c20_i33 = 0; c20_i33 < 36; c20_i33++) {
    c20_si_a[c20_i33] = -c20_si_a[c20_i33];
  }

  for (c20_i34 = 0; c20_i34 < 18; c20_i34++) {
    c20_tl_b[c20_i34] = c20_Hbm[c20_i34];
  }

  c20_c_eml_scalar_eg(chartInstance);
  c20_c_eml_scalar_eg(chartInstance);
  for (c20_i35 = 0; c20_i35 < 6; c20_i35++) {
    c20_i36 = 0;
    for (c20_i37 = 0; c20_i37 < 3; c20_i37++) {
      c20_oq_y[c20_i36 + c20_i35] = 0.0;
      c20_i38 = 0;
      for (c20_i39 = 0; c20_i39 < 6; c20_i39++) {
        c20_oq_y[c20_i36 + c20_i35] += c20_si_a[c20_i38 + c20_i35] *
          c20_tl_b[c20_i39 + c20_i36];
        c20_i38 += 6;
      }

      c20_i36 += 6;
    }
  }

  c20_ul_b[0] = c20_qd1;
  c20_ul_b[1] = c20_qd2;
  c20_ul_b[2] = c20_qd3;
  c20_e_eml_scalar_eg(chartInstance);
  c20_e_eml_scalar_eg(chartInstance);
  for (c20_i40 = 0; c20_i40 < 6; c20_i40++) {
    c20_SCnew[c20_i40] = 0.0;
  }

  for (c20_i41 = 0; c20_i41 < 6; c20_i41++) {
    c20_SCnew[c20_i41] = 0.0;
  }

  for (c20_i42 = 0; c20_i42 < 6; c20_i42++) {
    c20_C[c20_i42] = c20_SCnew[c20_i42];
  }

  for (c20_i43 = 0; c20_i43 < 6; c20_i43++) {
    c20_SCnew[c20_i43] = c20_C[c20_i43];
  }

  for (c20_i44 = 0; c20_i44 < 6; c20_i44++) {
    c20_C[c20_i44] = c20_SCnew[c20_i44];
  }

  for (c20_i45 = 0; c20_i45 < 6; c20_i45++) {
    c20_SCnew[c20_i45] = c20_C[c20_i45];
  }

  for (c20_i46 = 0; c20_i46 < 6; c20_i46++) {
    c20_SCnew[c20_i46] = 0.0;
    c20_i47 = 0;
    for (c20_i48 = 0; c20_i48 < 3; c20_i48++) {
      c20_SCnew[c20_i46] += c20_oq_y[c20_i47 + c20_i46] * c20_ul_b[c20_i48];
      c20_i47 += 6;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 49);
  c20_ft_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_gt_x = c20_ft_x;
  c20_gt_x = muDoubleScalarSin(c20_gt_x);
  c20_ti_a = -c20_b_l;
  c20_vl_b = c20_gt_x;
  c20_pq_y = c20_ti_a * c20_vl_b;
  c20_ht_x = c20_bth + c20_q1;
  c20_it_x = c20_ht_x;
  c20_it_x = muDoubleScalarSin(c20_it_x);
  c20_ui_a = c20_b_l;
  c20_wl_b = c20_it_x;
  c20_qq_y = c20_ui_a * c20_wl_b;
  c20_jt_x = c20_bth;
  c20_kt_x = c20_jt_x;
  c20_kt_x = muDoubleScalarSin(c20_kt_x);
  c20_vi_a = c20_b_lb;
  c20_xl_b = c20_kt_x;
  c20_rq_y = c20_vi_a * c20_xl_b;
  c20_lt_x = (c20_bth + c20_q1) + c20_q2;
  c20_mt_x = c20_lt_x;
  c20_mt_x = muDoubleScalarSin(c20_mt_x);
  c20_wi_a = c20_b_l;
  c20_yl_b = c20_mt_x;
  c20_sq_y = c20_wi_a * c20_yl_b;
  c20_nt_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_ot_x = c20_nt_x;
  c20_ot_x = muDoubleScalarCos(c20_ot_x);
  c20_xi_a = c20_b_l;
  c20_am_b = c20_ot_x;
  c20_tq_y = c20_xi_a * c20_am_b;
  c20_pt_x = c20_bth + c20_q1;
  c20_qt_x = c20_pt_x;
  c20_qt_x = muDoubleScalarCos(c20_qt_x);
  c20_yi_a = c20_b_l;
  c20_bm_b = c20_qt_x;
  c20_uq_y = c20_yi_a * c20_bm_b;
  c20_rt_x = c20_bth;
  c20_st_x = c20_rt_x;
  c20_st_x = muDoubleScalarCos(c20_st_x);
  c20_aj_a = c20_b_lb;
  c20_cm_b = c20_st_x;
  c20_vq_y = c20_aj_a * c20_cm_b;
  c20_tt_x = (c20_bth + c20_q1) + c20_q2;
  c20_ut_x = c20_tt_x;
  c20_ut_x = muDoubleScalarCos(c20_ut_x);
  c20_bj_a = c20_b_l;
  c20_dm_b = c20_ut_x;
  c20_wq_y = c20_bj_a * c20_dm_b;
  c20_vt_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_wt_x = c20_vt_x;
  c20_wt_x = muDoubleScalarSin(c20_wt_x);
  c20_cj_a = c20_b_l;
  c20_em_b = c20_wt_x;
  c20_xq_y = c20_cj_a * c20_em_b;
  c20_xt_x = c20_bth + c20_q1;
  c20_yt_x = c20_xt_x;
  c20_yt_x = muDoubleScalarSin(c20_yt_x);
  c20_dj_a = c20_b_l;
  c20_fm_b = c20_yt_x;
  c20_yq_y = c20_dj_a * c20_fm_b;
  c20_au_x = c20_bth;
  c20_bu_x = c20_au_x;
  c20_bu_x = muDoubleScalarSin(c20_bu_x);
  c20_ej_a = c20_b_lb;
  c20_gm_b = c20_bu_x;
  c20_ar_y = c20_ej_a * c20_gm_b;
  c20_cu_x = (c20_bth + c20_q1) + c20_q2;
  c20_du_x = c20_cu_x;
  c20_du_x = muDoubleScalarSin(c20_du_x);
  c20_fj_a = c20_b_l;
  c20_hm_b = c20_du_x;
  c20_br_y = c20_fj_a * c20_hm_b;
  c20_eu_x = ((c20_bth + c20_q1) + c20_q2) + c20_q3;
  c20_fu_x = c20_eu_x;
  c20_fu_x = muDoubleScalarCos(c20_fu_x);
  c20_gj_a = -c20_b_l;
  c20_im_b = c20_fu_x;
  c20_cr_y = c20_gj_a * c20_im_b;
  c20_gu_x = c20_bth + c20_q1;
  c20_hu_x = c20_gu_x;
  c20_hu_x = muDoubleScalarCos(c20_hu_x);
  c20_hj_a = c20_b_l;
  c20_jm_b = c20_hu_x;
  c20_dr_y = c20_hj_a * c20_jm_b;
  c20_iu_x = c20_bth;
  c20_ju_x = c20_iu_x;
  c20_ju_x = muDoubleScalarCos(c20_ju_x);
  c20_ij_a = c20_b_lb;
  c20_km_b = c20_ju_x;
  c20_er_y = c20_ij_a * c20_km_b;
  c20_ku_x = (c20_bth + c20_q1) + c20_q2;
  c20_lu_x = c20_ku_x;
  c20_lu_x = muDoubleScalarCos(c20_lu_x);
  c20_jj_a = c20_b_l;
  c20_lm_b = c20_lu_x;
  c20_fr_y = c20_jj_a * c20_lm_b;
  c20_Jb[0] = 1.0;
  c20_Jb[6] = 0.0;
  c20_Jb[12] = 0.0;
  c20_Jb[18] = 0.0;
  c20_Jb[24] = 0.0;
  c20_Jb[30] = ((c20_pq_y - c20_qq_y) - c20_rq_y) - c20_sq_y;
  c20_Jb[1] = 0.0;
  c20_Jb[7] = 1.0;
  c20_Jb[13] = 0.0;
  c20_Jb[19] = 0.0;
  c20_Jb[25] = 0.0;
  c20_Jb[31] = ((c20_tq_y + c20_uq_y) + c20_vq_y) + c20_wq_y;
  c20_Jb[2] = 0.0;
  c20_Jb[8] = 0.0;
  c20_Jb[14] = 1.0;
  c20_Jb[20] = ((c20_xq_y + c20_yq_y) + c20_ar_y) + c20_br_y;
  c20_Jb[26] = ((c20_cr_y - c20_dr_y) - c20_er_y) - c20_fr_y;
  c20_Jb[32] = 0.0;
  c20_i49 = 0;
  for (c20_i50 = 0; c20_i50 < 6; c20_i50++) {
    c20_Jb[c20_i49 + 3] = c20_dv4[c20_i50];
    c20_i49 += 6;
  }

  c20_i51 = 0;
  for (c20_i52 = 0; c20_i52 < 6; c20_i52++) {
    c20_Jb[c20_i51 + 4] = c20_dv5[c20_i52];
    c20_i51 += 6;
  }

  c20_i53 = 0;
  for (c20_i54 = 0; c20_i54 < 6; c20_i54++) {
    c20_Jb[c20_i53 + 5] = c20_dv6[c20_i54];
    c20_i53 += 6;
  }

  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 58);
  for (c20_i55 = 0; c20_i55 < 36; c20_i55++) {
    c20_si_a[c20_i55] = c20_Jb[c20_i55];
  }

  for (c20_i56 = 0; c20_i56 < 36; c20_i56++) {
    c20_c_Hb[c20_i56] = c20_Hb[c20_i56];
  }

  c20_inv(chartInstance, c20_c_Hb, c20_mm_b);
  c20_f_eml_scalar_eg(chartInstance);
  c20_f_eml_scalar_eg(chartInstance);
  for (c20_i57 = 0; c20_i57 < 6; c20_i57++) {
    c20_i58 = 0;
    for (c20_i59 = 0; c20_i59 < 6; c20_i59++) {
      c20_gr_y[c20_i58 + c20_i57] = 0.0;
      c20_i60 = 0;
      for (c20_i61 = 0; c20_i61 < 6; c20_i61++) {
        c20_gr_y[c20_i58 + c20_i57] += c20_si_a[c20_i60 + c20_i57] *
          c20_mm_b[c20_i61 + c20_i58];
        c20_i60 += 6;
      }

      c20_i58 += 6;
    }
  }

  for (c20_i62 = 0; c20_i62 < 18; c20_i62++) {
    c20_tl_b[c20_i62] = c20_Hbm[c20_i62];
  }

  c20_c_eml_scalar_eg(chartInstance);
  c20_c_eml_scalar_eg(chartInstance);
  for (c20_i63 = 0; c20_i63 < 6; c20_i63++) {
    c20_i64 = 0;
    for (c20_i65 = 0; c20_i65 < 3; c20_i65++) {
      c20_oq_y[c20_i64 + c20_i63] = 0.0;
      c20_i66 = 0;
      for (c20_i67 = 0; c20_i67 < 6; c20_i67++) {
        c20_oq_y[c20_i64 + c20_i63] += c20_gr_y[c20_i66 + c20_i63] *
          c20_tl_b[c20_i67 + c20_i64];
        c20_i66 += 6;
      }

      c20_i64 += 6;
    }
  }

  for (c20_i68 = 0; c20_i68 < 18; c20_i68++) {
    c20_Jstar[c20_i68] = c20_Jm[c20_i68] - c20_oq_y[c20_i68];
  }

  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 60);
  c20_EE[0] = 0.0;
  c20_EE[1] = 0.0;
  c20_EE[2] = c20_q3rd;
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 61);
  for (c20_i69 = 0; c20_i69 < 18; c20_i69++) {
    c20_b_Jstar[c20_i69] = c20_Jstar[c20_i69];
  }

  c20_pinv(chartInstance, c20_b_Jstar, c20_dv7);
  for (c20_i70 = 0; c20_i70 < 18; c20_i70++) {
    c20_invJstar[c20_i70] = c20_dv7[c20_i70];
  }

  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 62);
  for (c20_i71 = 0; c20_i71 < 18; c20_i71++) {
    c20_kj_a[c20_i71] = c20_invJstar[c20_i71];
  }

  for (c20_i72 = 0; c20_i72 < 6; c20_i72++) {
    c20_C[c20_i72] = c20_Ve[c20_i72];
  }

  c20_h_eml_scalar_eg(chartInstance);
  c20_h_eml_scalar_eg(chartInstance);
  for (c20_i73 = 0; c20_i73 < 3; c20_i73++) {
    c20_ul_b[c20_i73] = 0.0;
    c20_i74 = 0;
    for (c20_i75 = 0; c20_i75 < 6; c20_i75++) {
      c20_ul_b[c20_i73] += c20_kj_a[c20_i74 + c20_i73] * c20_C[c20_i75];
      c20_i74 += 3;
    }
  }

  for (c20_i76 = 0; c20_i76 < 3; c20_i76++) {
    c20_qd_req[c20_i76] = c20_ul_b[c20_i76] + c20_EE[c20_i76];
  }

  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 64);
  for (c20_i77 = 0; c20_i77 < 18; c20_i77++) {
    c20_c_Jstar[c20_i77] = c20_Jstar[c20_i77];
  }

  c20_svd(chartInstance, c20_c_Jstar, c20_dv8);
  for (c20_i78 = 0; c20_i78 < 3; c20_i78++) {
    c20_A[c20_i78] = c20_dv8[c20_i78];
  }

  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 65);
  c20_lambmax = 20.0;
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 66);
  c20_Sigma = c20_A[2];
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 67);
  if (CV_EML_IF(0, 1, 0, c20_Sigma >= 0.5)) {
    _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 68);
    c20_lamb2 = 0.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 70);
    c20_od_A = c20_Sigma;
    c20_mu_x = c20_od_A;
    c20_nu_x = c20_mu_x;
    c20_hr_y = c20_nu_x / 4.0;
    c20_lj_a = 1.0 - c20_mpower(chartInstance, c20_hr_y);
    c20_lamb2 = c20_lj_a * 20.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 72);
  for (c20_i79 = 0; c20_i79 < 18; c20_i79++) {
    c20_tl_b[c20_i79] = c20_Jstar[c20_i79];
  }

  c20_i80 = 0;
  for (c20_i81 = 0; c20_i81 < 6; c20_i81++) {
    c20_i82 = 0;
    for (c20_i83 = 0; c20_i83 < 3; c20_i83++) {
      c20_kj_a[c20_i83 + c20_i80] = c20_Jstar[c20_i82 + c20_i81];
      c20_i82 += 6;
    }

    c20_i80 += 3;
  }

  c20_i_eml_scalar_eg(chartInstance);
  c20_i_eml_scalar_eg(chartInstance);
  for (c20_i84 = 0; c20_i84 < 6; c20_i84++) {
    c20_i85 = 0;
    c20_i86 = 0;
    for (c20_i87 = 0; c20_i87 < 6; c20_i87++) {
      c20_gr_y[c20_i85 + c20_i84] = 0.0;
      c20_i88 = 0;
      for (c20_i89 = 0; c20_i89 < 3; c20_i89++) {
        c20_gr_y[c20_i85 + c20_i84] += c20_tl_b[c20_i88 + c20_i84] *
          c20_kj_a[c20_i89 + c20_i86];
        c20_i88 += 6;
      }

      c20_i85 += 6;
      c20_i86 += 3;
    }
  }

  c20_mj_a = c20_lamb2;
  for (c20_i90 = 0; c20_i90 < 36; c20_i90++) {
    c20_si_a[c20_i90] = c20_mj_a * c20_nm_b[c20_i90];
  }

  c20_i91 = 0;
  for (c20_i92 = 0; c20_i92 < 6; c20_i92++) {
    c20_i93 = 0;
    for (c20_i94 = 0; c20_i94 < 3; c20_i94++) {
      c20_kj_a[c20_i94 + c20_i91] = c20_Jstar[c20_i93 + c20_i92];
      c20_i93 += 6;
    }

    c20_i91 += 3;
  }

  for (c20_i95 = 0; c20_i95 < 36; c20_i95++) {
    c20_ir_y[c20_i95] = c20_gr_y[c20_i95] + c20_si_a[c20_i95];
  }

  c20_b_pinv(chartInstance, c20_ir_y, c20_mm_b);
  c20_j_eml_scalar_eg(chartInstance);
  c20_j_eml_scalar_eg(chartInstance);
  for (c20_i96 = 0; c20_i96 < 3; c20_i96++) {
    c20_i97 = 0;
    c20_i98 = 0;
    for (c20_i99 = 0; c20_i99 < 6; c20_i99++) {
      c20_jr_y[c20_i97 + c20_i96] = 0.0;
      c20_i100 = 0;
      for (c20_i101 = 0; c20_i101 < 6; c20_i101++) {
        c20_jr_y[c20_i97 + c20_i96] += c20_kj_a[c20_i100 + c20_i96] *
          c20_mm_b[c20_i101 + c20_i98];
        c20_i100 += 3;
      }

      c20_i97 += 3;
      c20_i98 += 6;
    }
  }

  for (c20_i102 = 0; c20_i102 < 6; c20_i102++) {
    c20_C[c20_i102] = c20_Ve[c20_i102];
  }

  c20_h_eml_scalar_eg(chartInstance);
  c20_h_eml_scalar_eg(chartInstance);
  for (c20_i103 = 0; c20_i103 < 3; c20_i103++) {
    c20_ul_b[c20_i103] = 0.0;
    c20_i104 = 0;
    for (c20_i105 = 0; c20_i105 < 6; c20_i105++) {
      c20_ul_b[c20_i103] += c20_jr_y[c20_i104 + c20_i103] * c20_C[c20_i105];
      c20_i104 += 3;
    }
  }

  for (c20_i106 = 0; c20_i106 < 3; c20_i106++) {
    c20_qd_reqW[c20_i106] = c20_ul_b[c20_i106] + c20_EE[c20_i106];
  }

  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, -72);
  _SFD_SYMBOL_SCOPE_POP();
  for (c20_i107 = 0; c20_i107 < 3; c20_i107++) {
    (*c20_b_qd_req)[c20_i107] = c20_qd_req[c20_i107];
  }

  for (c20_i108 = 0; c20_i108 < 3; c20_i108++) {
    (*c20_b_qd_reqW)[c20_i108] = c20_qd_reqW[c20_i108];
  }

  for (c20_i109 = 0; c20_i109 < 18; c20_i109++) {
    (*c20_d_Jstar)[c20_i109] = c20_Jstar[c20_i109];
  }

  for (c20_i110 = 0; c20_i110 < 6; c20_i110++) {
    (*c20_b_SCnew)[c20_i110] = c20_SCnew[c20_i110];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c20_sfEvent);
}

static void initSimStructsc20_CusakisME4901arcs
  (SFc20_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static void registerMessagesc20_CusakisME4901arcs
  (SFc20_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber)
{
}

static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i111;
  real_T c20_b_inData[6];
  int32_T c20_i112;
  real_T c20_u[6];
  const mxArray *c20_y = NULL;
  SFc20_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc20_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i111 = 0; c20_i111 < 6; c20_i111++) {
    c20_b_inData[c20_i111] = (*(real_T (*)[6])c20_inData)[c20_i111];
  }

  for (c20_i112 = 0; c20_i112 < 6; c20_i112++) {
    c20_u[c20_i112] = c20_b_inData[c20_i112];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, FALSE);
  return c20_mxArrayOutData;
}

static void c20_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_SCnew, const char_T *c20_identifier, real_T
  c20_y[6])
{
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_SCnew), &c20_thisId,
    c20_y);
  sf_mex_destroy(&c20_SCnew);
}

static void c20_b_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[6])
{
  real_T c20_dv9[6];
  int32_T c20_i113;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), c20_dv9, 1, 0, 0U, 1, 0U, 1, 6);
  for (c20_i113 = 0; c20_i113 < 6; c20_i113++) {
    c20_y[c20_i113] = c20_dv9[c20_i113];
  }

  sf_mex_destroy(&c20_u);
}

static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_SCnew;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y[6];
  int32_T c20_i114;
  SFc20_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc20_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c20_SCnew = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_SCnew), &c20_thisId,
    c20_y);
  sf_mex_destroy(&c20_SCnew);
  for (c20_i114 = 0; c20_i114 < 6; c20_i114++) {
    (*(real_T (*)[6])c20_outData)[c20_i114] = c20_y[c20_i114];
  }

  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i115;
  int32_T c20_i116;
  int32_T c20_i117;
  real_T c20_b_inData[18];
  int32_T c20_i118;
  int32_T c20_i119;
  int32_T c20_i120;
  real_T c20_u[18];
  const mxArray *c20_y = NULL;
  SFc20_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc20_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_i115 = 0;
  for (c20_i116 = 0; c20_i116 < 3; c20_i116++) {
    for (c20_i117 = 0; c20_i117 < 6; c20_i117++) {
      c20_b_inData[c20_i117 + c20_i115] = (*(real_T (*)[18])c20_inData)[c20_i117
        + c20_i115];
    }

    c20_i115 += 6;
  }

  c20_i118 = 0;
  for (c20_i119 = 0; c20_i119 < 3; c20_i119++) {
    for (c20_i120 = 0; c20_i120 < 6; c20_i120++) {
      c20_u[c20_i120 + c20_i118] = c20_b_inData[c20_i120 + c20_i118];
    }

    c20_i118 += 6;
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 2, 6, 3), FALSE);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, FALSE);
  return c20_mxArrayOutData;
}

static void c20_c_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_Jstar, const char_T *c20_identifier, real_T
  c20_y[18])
{
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_Jstar), &c20_thisId,
    c20_y);
  sf_mex_destroy(&c20_Jstar);
}

static void c20_d_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[18])
{
  real_T c20_dv10[18];
  int32_T c20_i121;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), c20_dv10, 1, 0, 0U, 1, 0U, 2, 6,
                3);
  for (c20_i121 = 0; c20_i121 < 18; c20_i121++) {
    c20_y[c20_i121] = c20_dv10[c20_i121];
  }

  sf_mex_destroy(&c20_u);
}

static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_Jstar;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y[18];
  int32_T c20_i122;
  int32_T c20_i123;
  int32_T c20_i124;
  SFc20_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc20_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c20_Jstar = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_Jstar), &c20_thisId,
    c20_y);
  sf_mex_destroy(&c20_Jstar);
  c20_i122 = 0;
  for (c20_i123 = 0; c20_i123 < 3; c20_i123++) {
    for (c20_i124 = 0; c20_i124 < 6; c20_i124++) {
      (*(real_T (*)[18])c20_outData)[c20_i124 + c20_i122] = c20_y[c20_i124 +
        c20_i122];
    }

    c20_i122 += 6;
  }

  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i125;
  real_T c20_b_inData[3];
  int32_T c20_i126;
  real_T c20_u[3];
  const mxArray *c20_y = NULL;
  SFc20_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc20_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i125 = 0; c20_i125 < 3; c20_i125++) {
    c20_b_inData[c20_i125] = (*(real_T (*)[3])c20_inData)[c20_i125];
  }

  for (c20_i126 = 0; c20_i126 < 3; c20_i126++) {
    c20_u[c20_i126] = c20_b_inData[c20_i126];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, FALSE);
  return c20_mxArrayOutData;
}

static void c20_e_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_qd_reqW, const char_T *c20_identifier,
  real_T c20_y[3])
{
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_qd_reqW), &c20_thisId,
    c20_y);
  sf_mex_destroy(&c20_qd_reqW);
}

static void c20_f_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[3])
{
  real_T c20_dv11[3];
  int32_T c20_i127;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), c20_dv11, 1, 0, 0U, 1, 0U, 1, 3);
  for (c20_i127 = 0; c20_i127 < 3; c20_i127++) {
    c20_y[c20_i127] = c20_dv11[c20_i127];
  }

  sf_mex_destroy(&c20_u);
}

static void c20_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_qd_reqW;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y[3];
  int32_T c20_i128;
  SFc20_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc20_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c20_qd_reqW = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_qd_reqW), &c20_thisId,
    c20_y);
  sf_mex_destroy(&c20_qd_reqW);
  for (c20_i128 = 0; c20_i128 < 3; c20_i128++) {
    (*(real_T (*)[3])c20_outData)[c20_i128] = c20_y[c20_i128];
  }

  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_d_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  real_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc20_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(real_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, FALSE);
  return c20_mxArrayOutData;
}

static real_T c20_g_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  real_T c20_y;
  real_T c20_d6;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_d6, 1, 0, 0U, 0, 0U, 0);
  c20_y = c20_d6;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_Ib;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y;
  SFc20_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc20_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c20_b_Ib = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_Ib),
    &c20_thisId);
  sf_mex_destroy(&c20_b_Ib);
  *(real_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_e_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i129;
  real_T c20_b_inData[9];
  int32_T c20_i130;
  real_T c20_u[9];
  const mxArray *c20_y = NULL;
  SFc20_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc20_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  for (c20_i129 = 0; c20_i129 < 9; c20_i129++) {
    c20_b_inData[c20_i129] = (*(real_T (*)[9])c20_inData)[c20_i129];
  }

  for (c20_i130 = 0; c20_i130 < 9; c20_i130++) {
    c20_u[c20_i130] = c20_b_inData[c20_i130];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 1, 9), FALSE);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, FALSE);
  return c20_mxArrayOutData;
}

static const mxArray *c20_f_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i131;
  int32_T c20_i132;
  int32_T c20_i133;
  real_T c20_b_inData[18];
  int32_T c20_i134;
  int32_T c20_i135;
  int32_T c20_i136;
  real_T c20_u[18];
  const mxArray *c20_y = NULL;
  SFc20_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc20_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_i131 = 0;
  for (c20_i132 = 0; c20_i132 < 6; c20_i132++) {
    for (c20_i133 = 0; c20_i133 < 3; c20_i133++) {
      c20_b_inData[c20_i133 + c20_i131] = (*(real_T (*)[18])c20_inData)[c20_i133
        + c20_i131];
    }

    c20_i131 += 3;
  }

  c20_i134 = 0;
  for (c20_i135 = 0; c20_i135 < 6; c20_i135++) {
    for (c20_i136 = 0; c20_i136 < 3; c20_i136++) {
      c20_u[c20_i136 + c20_i134] = c20_b_inData[c20_i136 + c20_i134];
    }

    c20_i134 += 3;
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 2, 3, 6), FALSE);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, FALSE);
  return c20_mxArrayOutData;
}

static void c20_h_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[18])
{
  real_T c20_dv12[18];
  int32_T c20_i137;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), c20_dv12, 1, 0, 0U, 1, 0U, 2, 3,
                6);
  for (c20_i137 = 0; c20_i137 < 18; c20_i137++) {
    c20_y[c20_i137] = c20_dv12[c20_i137];
  }

  sf_mex_destroy(&c20_u);
}

static void c20_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_invJstar;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y[18];
  int32_T c20_i138;
  int32_T c20_i139;
  int32_T c20_i140;
  SFc20_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc20_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c20_invJstar = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_invJstar), &c20_thisId,
    c20_y);
  sf_mex_destroy(&c20_invJstar);
  c20_i138 = 0;
  for (c20_i139 = 0; c20_i139 < 6; c20_i139++) {
    for (c20_i140 = 0; c20_i140 < 3; c20_i140++) {
      (*(real_T (*)[18])c20_outData)[c20_i140 + c20_i138] = c20_y[c20_i140 +
        c20_i138];
    }

    c20_i138 += 3;
  }

  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_g_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i141;
  int32_T c20_i142;
  int32_T c20_i143;
  real_T c20_b_inData[36];
  int32_T c20_i144;
  int32_T c20_i145;
  int32_T c20_i146;
  real_T c20_u[36];
  const mxArray *c20_y = NULL;
  SFc20_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc20_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_i141 = 0;
  for (c20_i142 = 0; c20_i142 < 6; c20_i142++) {
    for (c20_i143 = 0; c20_i143 < 6; c20_i143++) {
      c20_b_inData[c20_i143 + c20_i141] = (*(real_T (*)[36])c20_inData)[c20_i143
        + c20_i141];
    }

    c20_i141 += 6;
  }

  c20_i144 = 0;
  for (c20_i145 = 0; c20_i145 < 6; c20_i145++) {
    for (c20_i146 = 0; c20_i146 < 6; c20_i146++) {
      c20_u[c20_i146 + c20_i144] = c20_b_inData[c20_i146 + c20_i144];
    }

    c20_i144 += 6;
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 2, 6, 6), FALSE);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, FALSE);
  return c20_mxArrayOutData;
}

static void c20_i_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[36])
{
  real_T c20_dv13[36];
  int32_T c20_i147;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), c20_dv13, 1, 0, 0U, 1, 0U, 2, 6,
                6);
  for (c20_i147 = 0; c20_i147 < 36; c20_i147++) {
    c20_y[c20_i147] = c20_dv13[c20_i147];
  }

  sf_mex_destroy(&c20_u);
}

static void c20_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_Jb;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y[36];
  int32_T c20_i148;
  int32_T c20_i149;
  int32_T c20_i150;
  SFc20_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc20_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c20_Jb = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_Jb), &c20_thisId, c20_y);
  sf_mex_destroy(&c20_Jb);
  c20_i148 = 0;
  for (c20_i149 = 0; c20_i149 < 6; c20_i149++) {
    for (c20_i150 = 0; c20_i150 < 6; c20_i150++) {
      (*(real_T (*)[36])c20_outData)[c20_i150 + c20_i148] = c20_y[c20_i150 +
        c20_i148];
    }

    c20_i148 += 6;
  }

  sf_mex_destroy(&c20_mxArrayInData);
}

const mxArray *sf_c20_CusakisME4901arcs_get_eml_resolved_functions_info(void)
{
  const mxArray *c20_nameCaptureInfo;
  c20_ResolvedFunctionInfo c20_info[281];
  const mxArray *c20_m0 = NULL;
  int32_T c20_i151;
  c20_ResolvedFunctionInfo *c20_r0;
  c20_nameCaptureInfo = NULL;
  c20_nameCaptureInfo = NULL;
  c20_info_helper(c20_info);
  c20_b_info_helper(c20_info);
  c20_c_info_helper(c20_info);
  c20_d_info_helper(c20_info);
  c20_e_info_helper(c20_info);
  sf_mex_assign(&c20_m0, sf_mex_createstruct("nameCaptureInfo", 1, 281), FALSE);
  for (c20_i151 = 0; c20_i151 < 281; c20_i151++) {
    c20_r0 = &c20_info[c20_i151];
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", c20_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c20_r0->context)), "context", "nameCaptureInfo",
                    c20_i151);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", c20_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c20_r0->name)), "name", "nameCaptureInfo",
                    c20_i151);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo",
      c20_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c20_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c20_i151);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", c20_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c20_r0->resolved)), "resolved",
                    "nameCaptureInfo", c20_i151);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", &c20_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c20_i151);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", &c20_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c20_i151);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo",
      &c20_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c20_i151);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo",
      &c20_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c20_i151);
  }

  sf_mex_assign(&c20_nameCaptureInfo, c20_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c20_nameCaptureInfo);
  return c20_nameCaptureInfo;
}

static void c20_info_helper(c20_ResolvedFunctionInfo c20_info[281])
{
  c20_info[0].context = "";
  c20_info[0].name = "mtimes";
  c20_info[0].dominantType = "double";
  c20_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[0].fileTimeLo = 1289552092U;
  c20_info[0].fileTimeHi = 0U;
  c20_info[0].mFileTimeLo = 0U;
  c20_info[0].mFileTimeHi = 0U;
  c20_info[1].context = "";
  c20_info[1].name = "mrdivide";
  c20_info[1].dominantType = "double";
  c20_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c20_info[1].fileTimeLo = 1357983948U;
  c20_info[1].fileTimeHi = 0U;
  c20_info[1].mFileTimeLo = 1319762366U;
  c20_info[1].mFileTimeHi = 0U;
  c20_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c20_info[2].name = "rdivide";
  c20_info[2].dominantType = "double";
  c20_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c20_info[2].fileTimeLo = 1346542788U;
  c20_info[2].fileTimeHi = 0U;
  c20_info[2].mFileTimeLo = 0U;
  c20_info[2].mFileTimeHi = 0U;
  c20_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c20_info[3].name = "eml_scalexp_compatible";
  c20_info[3].dominantType = "double";
  c20_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c20_info[3].fileTimeLo = 1286851196U;
  c20_info[3].fileTimeHi = 0U;
  c20_info[3].mFileTimeLo = 0U;
  c20_info[3].mFileTimeHi = 0U;
  c20_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c20_info[4].name = "eml_div";
  c20_info[4].dominantType = "double";
  c20_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c20_info[4].fileTimeLo = 1313380210U;
  c20_info[4].fileTimeHi = 0U;
  c20_info[4].mFileTimeLo = 0U;
  c20_info[4].mFileTimeHi = 0U;
  c20_info[5].context = "";
  c20_info[5].name = "sin";
  c20_info[5].dominantType = "double";
  c20_info[5].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c20_info[5].fileTimeLo = 1343862786U;
  c20_info[5].fileTimeHi = 0U;
  c20_info[5].mFileTimeLo = 0U;
  c20_info[5].mFileTimeHi = 0U;
  c20_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c20_info[6].name = "eml_scalar_sin";
  c20_info[6].dominantType = "double";
  c20_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c20_info[6].fileTimeLo = 1286851136U;
  c20_info[6].fileTimeHi = 0U;
  c20_info[6].mFileTimeLo = 0U;
  c20_info[6].mFileTimeHi = 0U;
  c20_info[7].context = "";
  c20_info[7].name = "cos";
  c20_info[7].dominantType = "double";
  c20_info[7].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c20_info[7].fileTimeLo = 1343862772U;
  c20_info[7].fileTimeHi = 0U;
  c20_info[7].mFileTimeLo = 0U;
  c20_info[7].mFileTimeHi = 0U;
  c20_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c20_info[8].name = "eml_scalar_cos";
  c20_info[8].dominantType = "double";
  c20_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c20_info[8].fileTimeLo = 1286851122U;
  c20_info[8].fileTimeHi = 0U;
  c20_info[8].mFileTimeLo = 0U;
  c20_info[8].mFileTimeHi = 0U;
  c20_info[9].context = "";
  c20_info[9].name = "mpower";
  c20_info[9].dominantType = "double";
  c20_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c20_info[9].fileTimeLo = 1286851242U;
  c20_info[9].fileTimeHi = 0U;
  c20_info[9].mFileTimeLo = 0U;
  c20_info[9].mFileTimeHi = 0U;
  c20_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c20_info[10].name = "power";
  c20_info[10].dominantType = "double";
  c20_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c20_info[10].fileTimeLo = 1348224330U;
  c20_info[10].fileTimeHi = 0U;
  c20_info[10].mFileTimeLo = 0U;
  c20_info[10].mFileTimeHi = 0U;
  c20_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c20_info[11].name = "eml_scalar_eg";
  c20_info[11].dominantType = "double";
  c20_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c20_info[11].fileTimeLo = 1286851196U;
  c20_info[11].fileTimeHi = 0U;
  c20_info[11].mFileTimeLo = 0U;
  c20_info[11].mFileTimeHi = 0U;
  c20_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c20_info[12].name = "eml_scalexp_alloc";
  c20_info[12].dominantType = "double";
  c20_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c20_info[12].fileTimeLo = 1352457260U;
  c20_info[12].fileTimeHi = 0U;
  c20_info[12].mFileTimeLo = 0U;
  c20_info[12].mFileTimeHi = 0U;
  c20_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c20_info[13].name = "floor";
  c20_info[13].dominantType = "double";
  c20_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c20_info[13].fileTimeLo = 1343862780U;
  c20_info[13].fileTimeHi = 0U;
  c20_info[13].mFileTimeLo = 0U;
  c20_info[13].mFileTimeHi = 0U;
  c20_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c20_info[14].name = "eml_scalar_floor";
  c20_info[14].dominantType = "double";
  c20_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c20_info[14].fileTimeLo = 1286851126U;
  c20_info[14].fileTimeHi = 0U;
  c20_info[14].mFileTimeLo = 0U;
  c20_info[14].mFileTimeHi = 0U;
  c20_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c20_info[15].name = "eml_scalar_eg";
  c20_info[15].dominantType = "double";
  c20_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c20_info[15].fileTimeLo = 1286851196U;
  c20_info[15].fileTimeHi = 0U;
  c20_info[15].mFileTimeLo = 0U;
  c20_info[15].mFileTimeHi = 0U;
  c20_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c20_info[16].name = "mtimes";
  c20_info[16].dominantType = "double";
  c20_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[16].fileTimeLo = 1289552092U;
  c20_info[16].fileTimeHi = 0U;
  c20_info[16].mFileTimeLo = 0U;
  c20_info[16].mFileTimeHi = 0U;
  c20_info[17].context = "";
  c20_info[17].name = "inv";
  c20_info[17].dominantType = "double";
  c20_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c20_info[17].fileTimeLo = 1305350400U;
  c20_info[17].fileTimeHi = 0U;
  c20_info[17].mFileTimeLo = 0U;
  c20_info[17].mFileTimeHi = 0U;
  c20_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c20_info[18].name = "eml_index_class";
  c20_info[18].dominantType = "";
  c20_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[18].fileTimeLo = 1323202978U;
  c20_info[18].fileTimeHi = 0U;
  c20_info[18].mFileTimeLo = 0U;
  c20_info[18].mFileTimeHi = 0U;
  c20_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c20_info[19].name = "eml_xgetrf";
  c20_info[19].dominantType = "double";
  c20_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c20_info[19].fileTimeLo = 1286851206U;
  c20_info[19].fileTimeHi = 0U;
  c20_info[19].mFileTimeLo = 0U;
  c20_info[19].mFileTimeHi = 0U;
  c20_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c20_info[20].name = "eml_lapack_xgetrf";
  c20_info[20].dominantType = "double";
  c20_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c20_info[20].fileTimeLo = 1286851210U;
  c20_info[20].fileTimeHi = 0U;
  c20_info[20].mFileTimeLo = 0U;
  c20_info[20].mFileTimeHi = 0U;
  c20_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c20_info[21].name = "eml_matlab_zgetrf";
  c20_info[21].dominantType = "double";
  c20_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c20_info[21].fileTimeLo = 1302721394U;
  c20_info[21].fileTimeHi = 0U;
  c20_info[21].mFileTimeLo = 0U;
  c20_info[21].mFileTimeHi = 0U;
  c20_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c20_info[22].name = "realmin";
  c20_info[22].dominantType = "char";
  c20_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c20_info[22].fileTimeLo = 1307683642U;
  c20_info[22].fileTimeHi = 0U;
  c20_info[22].mFileTimeLo = 0U;
  c20_info[22].mFileTimeHi = 0U;
  c20_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c20_info[23].name = "eml_realmin";
  c20_info[23].dominantType = "char";
  c20_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c20_info[23].fileTimeLo = 1307683644U;
  c20_info[23].fileTimeHi = 0U;
  c20_info[23].mFileTimeLo = 0U;
  c20_info[23].mFileTimeHi = 0U;
  c20_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c20_info[24].name = "eml_float_model";
  c20_info[24].dominantType = "char";
  c20_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c20_info[24].fileTimeLo = 1326760396U;
  c20_info[24].fileTimeHi = 0U;
  c20_info[24].mFileTimeLo = 0U;
  c20_info[24].mFileTimeHi = 0U;
  c20_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c20_info[25].name = "eps";
  c20_info[25].dominantType = "char";
  c20_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c20_info[25].fileTimeLo = 1326760396U;
  c20_info[25].fileTimeHi = 0U;
  c20_info[25].mFileTimeLo = 0U;
  c20_info[25].mFileTimeHi = 0U;
  c20_info[26].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c20_info[26].name = "eml_is_float_class";
  c20_info[26].dominantType = "char";
  c20_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c20_info[26].fileTimeLo = 1286851182U;
  c20_info[26].fileTimeHi = 0U;
  c20_info[26].mFileTimeLo = 0U;
  c20_info[26].mFileTimeHi = 0U;
  c20_info[27].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c20_info[27].name = "eml_eps";
  c20_info[27].dominantType = "char";
  c20_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c20_info[27].fileTimeLo = 1326760396U;
  c20_info[27].fileTimeHi = 0U;
  c20_info[27].mFileTimeLo = 0U;
  c20_info[27].mFileTimeHi = 0U;
  c20_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c20_info[28].name = "eml_float_model";
  c20_info[28].dominantType = "char";
  c20_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c20_info[28].fileTimeLo = 1326760396U;
  c20_info[28].fileTimeHi = 0U;
  c20_info[28].mFileTimeLo = 0U;
  c20_info[28].mFileTimeHi = 0U;
  c20_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c20_info[29].name = "min";
  c20_info[29].dominantType = "coder.internal.indexInt";
  c20_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c20_info[29].fileTimeLo = 1311287718U;
  c20_info[29].fileTimeHi = 0U;
  c20_info[29].mFileTimeLo = 0U;
  c20_info[29].mFileTimeHi = 0U;
  c20_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c20_info[30].name = "eml_min_or_max";
  c20_info[30].dominantType = "char";
  c20_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c20_info[30].fileTimeLo = 1334103890U;
  c20_info[30].fileTimeHi = 0U;
  c20_info[30].mFileTimeLo = 0U;
  c20_info[30].mFileTimeHi = 0U;
  c20_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c20_info[31].name = "eml_scalar_eg";
  c20_info[31].dominantType = "coder.internal.indexInt";
  c20_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c20_info[31].fileTimeLo = 1286851196U;
  c20_info[31].fileTimeHi = 0U;
  c20_info[31].mFileTimeLo = 0U;
  c20_info[31].mFileTimeHi = 0U;
  c20_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c20_info[32].name = "eml_scalexp_alloc";
  c20_info[32].dominantType = "coder.internal.indexInt";
  c20_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c20_info[32].fileTimeLo = 1352457260U;
  c20_info[32].fileTimeHi = 0U;
  c20_info[32].mFileTimeLo = 0U;
  c20_info[32].mFileTimeHi = 0U;
  c20_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c20_info[33].name = "eml_index_class";
  c20_info[33].dominantType = "";
  c20_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[33].fileTimeLo = 1323202978U;
  c20_info[33].fileTimeHi = 0U;
  c20_info[33].mFileTimeLo = 0U;
  c20_info[33].mFileTimeHi = 0U;
  c20_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c20_info[34].name = "eml_scalar_eg";
  c20_info[34].dominantType = "coder.internal.indexInt";
  c20_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c20_info[34].fileTimeLo = 1286851196U;
  c20_info[34].fileTimeHi = 0U;
  c20_info[34].mFileTimeLo = 0U;
  c20_info[34].mFileTimeHi = 0U;
  c20_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c20_info[35].name = "colon";
  c20_info[35].dominantType = "double";
  c20_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c20_info[35].fileTimeLo = 1348224328U;
  c20_info[35].fileTimeHi = 0U;
  c20_info[35].mFileTimeLo = 0U;
  c20_info[35].mFileTimeHi = 0U;
  c20_info[36].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c20_info[36].name = "colon";
  c20_info[36].dominantType = "double";
  c20_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c20_info[36].fileTimeLo = 1348224328U;
  c20_info[36].fileTimeHi = 0U;
  c20_info[36].mFileTimeLo = 0U;
  c20_info[36].mFileTimeHi = 0U;
  c20_info[37].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c20_info[37].name = "floor";
  c20_info[37].dominantType = "double";
  c20_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c20_info[37].fileTimeLo = 1343862780U;
  c20_info[37].fileTimeHi = 0U;
  c20_info[37].mFileTimeLo = 0U;
  c20_info[37].mFileTimeHi = 0U;
  c20_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c20_info[38].name = "intmin";
  c20_info[38].dominantType = "char";
  c20_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c20_info[38].fileTimeLo = 1311287718U;
  c20_info[38].fileTimeHi = 0U;
  c20_info[38].mFileTimeLo = 0U;
  c20_info[38].mFileTimeHi = 0U;
  c20_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c20_info[39].name = "intmax";
  c20_info[39].dominantType = "char";
  c20_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c20_info[39].fileTimeLo = 1311287716U;
  c20_info[39].fileTimeHi = 0U;
  c20_info[39].mFileTimeLo = 0U;
  c20_info[39].mFileTimeHi = 0U;
  c20_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c20_info[40].name = "intmin";
  c20_info[40].dominantType = "char";
  c20_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c20_info[40].fileTimeLo = 1311287718U;
  c20_info[40].fileTimeHi = 0U;
  c20_info[40].mFileTimeLo = 0U;
  c20_info[40].mFileTimeHi = 0U;
  c20_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c20_info[41].name = "intmax";
  c20_info[41].dominantType = "char";
  c20_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c20_info[41].fileTimeLo = 1311287716U;
  c20_info[41].fileTimeHi = 0U;
  c20_info[41].mFileTimeLo = 0U;
  c20_info[41].mFileTimeHi = 0U;
  c20_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c20_info[42].name = "eml_isa_uint";
  c20_info[42].dominantType = "coder.internal.indexInt";
  c20_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c20_info[42].fileTimeLo = 1286851184U;
  c20_info[42].fileTimeHi = 0U;
  c20_info[42].mFileTimeLo = 0U;
  c20_info[42].mFileTimeHi = 0U;
  c20_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c20_info[43].name = "eml_unsigned_class";
  c20_info[43].dominantType = "char";
  c20_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c20_info[43].fileTimeLo = 1323202980U;
  c20_info[43].fileTimeHi = 0U;
  c20_info[43].mFileTimeLo = 0U;
  c20_info[43].mFileTimeHi = 0U;
  c20_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c20_info[44].name = "eml_index_class";
  c20_info[44].dominantType = "";
  c20_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[44].fileTimeLo = 1323202978U;
  c20_info[44].fileTimeHi = 0U;
  c20_info[44].mFileTimeLo = 0U;
  c20_info[44].mFileTimeHi = 0U;
  c20_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c20_info[45].name = "eml_index_class";
  c20_info[45].dominantType = "";
  c20_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[45].fileTimeLo = 1323202978U;
  c20_info[45].fileTimeHi = 0U;
  c20_info[45].mFileTimeLo = 0U;
  c20_info[45].mFileTimeHi = 0U;
  c20_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c20_info[46].name = "intmax";
  c20_info[46].dominantType = "char";
  c20_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c20_info[46].fileTimeLo = 1311287716U;
  c20_info[46].fileTimeHi = 0U;
  c20_info[46].mFileTimeLo = 0U;
  c20_info[46].mFileTimeHi = 0U;
  c20_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c20_info[47].name = "eml_isa_uint";
  c20_info[47].dominantType = "coder.internal.indexInt";
  c20_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c20_info[47].fileTimeLo = 1286851184U;
  c20_info[47].fileTimeHi = 0U;
  c20_info[47].mFileTimeLo = 0U;
  c20_info[47].mFileTimeHi = 0U;
  c20_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c20_info[48].name = "eml_index_plus";
  c20_info[48].dominantType = "double";
  c20_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c20_info[48].fileTimeLo = 1286851178U;
  c20_info[48].fileTimeHi = 0U;
  c20_info[48].mFileTimeLo = 0U;
  c20_info[48].mFileTimeHi = 0U;
  c20_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c20_info[49].name = "eml_index_class";
  c20_info[49].dominantType = "";
  c20_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[49].fileTimeLo = 1323202978U;
  c20_info[49].fileTimeHi = 0U;
  c20_info[49].mFileTimeLo = 0U;
  c20_info[49].mFileTimeHi = 0U;
  c20_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon";
  c20_info[50].name = "eml_int_forloop_overflow_check";
  c20_info[50].dominantType = "";
  c20_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c20_info[50].fileTimeLo = 1346542740U;
  c20_info[50].fileTimeHi = 0U;
  c20_info[50].mFileTimeLo = 0U;
  c20_info[50].mFileTimeHi = 0U;
  c20_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c20_info[51].name = "intmax";
  c20_info[51].dominantType = "char";
  c20_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c20_info[51].fileTimeLo = 1311287716U;
  c20_info[51].fileTimeHi = 0U;
  c20_info[51].mFileTimeLo = 0U;
  c20_info[51].mFileTimeHi = 0U;
  c20_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c20_info[52].name = "eml_index_class";
  c20_info[52].dominantType = "";
  c20_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[52].fileTimeLo = 1323202978U;
  c20_info[52].fileTimeHi = 0U;
  c20_info[52].mFileTimeLo = 0U;
  c20_info[52].mFileTimeHi = 0U;
  c20_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c20_info[53].name = "eml_index_plus";
  c20_info[53].dominantType = "double";
  c20_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c20_info[53].fileTimeLo = 1286851178U;
  c20_info[53].fileTimeHi = 0U;
  c20_info[53].mFileTimeLo = 0U;
  c20_info[53].mFileTimeHi = 0U;
  c20_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c20_info[54].name = "eml_int_forloop_overflow_check";
  c20_info[54].dominantType = "";
  c20_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c20_info[54].fileTimeLo = 1346542740U;
  c20_info[54].fileTimeHi = 0U;
  c20_info[54].mFileTimeLo = 0U;
  c20_info[54].mFileTimeHi = 0U;
  c20_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c20_info[55].name = "eml_index_minus";
  c20_info[55].dominantType = "double";
  c20_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c20_info[55].fileTimeLo = 1286851178U;
  c20_info[55].fileTimeHi = 0U;
  c20_info[55].mFileTimeLo = 0U;
  c20_info[55].mFileTimeHi = 0U;
  c20_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c20_info[56].name = "eml_index_class";
  c20_info[56].dominantType = "";
  c20_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[56].fileTimeLo = 1323202978U;
  c20_info[56].fileTimeHi = 0U;
  c20_info[56].mFileTimeLo = 0U;
  c20_info[56].mFileTimeHi = 0U;
  c20_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c20_info[57].name = "eml_index_minus";
  c20_info[57].dominantType = "coder.internal.indexInt";
  c20_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c20_info[57].fileTimeLo = 1286851178U;
  c20_info[57].fileTimeHi = 0U;
  c20_info[57].mFileTimeLo = 0U;
  c20_info[57].mFileTimeHi = 0U;
  c20_info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c20_info[58].name = "eml_index_times";
  c20_info[58].dominantType = "coder.internal.indexInt";
  c20_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c20_info[58].fileTimeLo = 1286851180U;
  c20_info[58].fileTimeHi = 0U;
  c20_info[58].mFileTimeLo = 0U;
  c20_info[58].mFileTimeHi = 0U;
  c20_info[59].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c20_info[59].name = "eml_index_class";
  c20_info[59].dominantType = "";
  c20_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[59].fileTimeLo = 1323202978U;
  c20_info[59].fileTimeHi = 0U;
  c20_info[59].mFileTimeLo = 0U;
  c20_info[59].mFileTimeHi = 0U;
  c20_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c20_info[60].name = "eml_index_plus";
  c20_info[60].dominantType = "coder.internal.indexInt";
  c20_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c20_info[60].fileTimeLo = 1286851178U;
  c20_info[60].fileTimeHi = 0U;
  c20_info[60].mFileTimeLo = 0U;
  c20_info[60].mFileTimeHi = 0U;
  c20_info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c20_info[61].name = "eml_ixamax";
  c20_info[61].dominantType = "double";
  c20_info[61].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c20_info[61].fileTimeLo = 1299109170U;
  c20_info[61].fileTimeHi = 0U;
  c20_info[61].mFileTimeLo = 0U;
  c20_info[61].mFileTimeHi = 0U;
  c20_info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c20_info[62].name = "eml_blas_inline";
  c20_info[62].dominantType = "";
  c20_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c20_info[62].fileTimeLo = 1299109168U;
  c20_info[62].fileTimeHi = 0U;
  c20_info[62].mFileTimeLo = 0U;
  c20_info[62].mFileTimeHi = 0U;
  c20_info[63].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m!below_threshold";
  c20_info[63].name = "length";
  c20_info[63].dominantType = "double";
  c20_info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c20_info[63].fileTimeLo = 1303178606U;
  c20_info[63].fileTimeHi = 0U;
  c20_info[63].mFileTimeLo = 0U;
  c20_info[63].mFileTimeHi = 0U;
}

static void c20_b_info_helper(c20_ResolvedFunctionInfo c20_info[281])
{
  c20_info[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength";
  c20_info[64].name = "eml_index_class";
  c20_info[64].dominantType = "";
  c20_info[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[64].fileTimeLo = 1323202978U;
  c20_info[64].fileTimeHi = 0U;
  c20_info[64].mFileTimeLo = 0U;
  c20_info[64].mFileTimeHi = 0U;
  c20_info[65].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c20_info[65].name = "eml_index_class";
  c20_info[65].dominantType = "";
  c20_info[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[65].fileTimeLo = 1323202978U;
  c20_info[65].fileTimeHi = 0U;
  c20_info[65].mFileTimeLo = 0U;
  c20_info[65].mFileTimeHi = 0U;
  c20_info[66].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c20_info[66].name = "eml_refblas_ixamax";
  c20_info[66].dominantType = "double";
  c20_info[66].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c20_info[66].fileTimeLo = 1299109170U;
  c20_info[66].fileTimeHi = 0U;
  c20_info[66].mFileTimeLo = 0U;
  c20_info[66].mFileTimeHi = 0U;
  c20_info[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c20_info[67].name = "eml_index_class";
  c20_info[67].dominantType = "";
  c20_info[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[67].fileTimeLo = 1323202978U;
  c20_info[67].fileTimeHi = 0U;
  c20_info[67].mFileTimeLo = 0U;
  c20_info[67].mFileTimeHi = 0U;
  c20_info[68].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c20_info[68].name = "eml_xcabs1";
  c20_info[68].dominantType = "double";
  c20_info[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c20_info[68].fileTimeLo = 1286851106U;
  c20_info[68].fileTimeHi = 0U;
  c20_info[68].mFileTimeLo = 0U;
  c20_info[68].mFileTimeHi = 0U;
  c20_info[69].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c20_info[69].name = "abs";
  c20_info[69].dominantType = "double";
  c20_info[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c20_info[69].fileTimeLo = 1343862766U;
  c20_info[69].fileTimeHi = 0U;
  c20_info[69].mFileTimeLo = 0U;
  c20_info[69].mFileTimeHi = 0U;
  c20_info[70].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c20_info[70].name = "eml_scalar_abs";
  c20_info[70].dominantType = "double";
  c20_info[70].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c20_info[70].fileTimeLo = 1286851112U;
  c20_info[70].fileTimeHi = 0U;
  c20_info[70].mFileTimeLo = 0U;
  c20_info[70].mFileTimeHi = 0U;
  c20_info[71].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c20_info[71].name = "eml_int_forloop_overflow_check";
  c20_info[71].dominantType = "";
  c20_info[71].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c20_info[71].fileTimeLo = 1346542740U;
  c20_info[71].fileTimeHi = 0U;
  c20_info[71].mFileTimeLo = 0U;
  c20_info[71].mFileTimeHi = 0U;
  c20_info[72].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c20_info[72].name = "eml_index_plus";
  c20_info[72].dominantType = "coder.internal.indexInt";
  c20_info[72].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c20_info[72].fileTimeLo = 1286851178U;
  c20_info[72].fileTimeHi = 0U;
  c20_info[72].mFileTimeLo = 0U;
  c20_info[72].mFileTimeHi = 0U;
  c20_info[73].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c20_info[73].name = "eml_xswap";
  c20_info[73].dominantType = "double";
  c20_info[73].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c20_info[73].fileTimeLo = 1299109178U;
  c20_info[73].fileTimeHi = 0U;
  c20_info[73].mFileTimeLo = 0U;
  c20_info[73].mFileTimeHi = 0U;
  c20_info[74].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c20_info[74].name = "eml_blas_inline";
  c20_info[74].dominantType = "";
  c20_info[74].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c20_info[74].fileTimeLo = 1299109168U;
  c20_info[74].fileTimeHi = 0U;
  c20_info[74].mFileTimeLo = 0U;
  c20_info[74].mFileTimeHi = 0U;
  c20_info[75].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c20_info[75].name = "eml_index_class";
  c20_info[75].dominantType = "";
  c20_info[75].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[75].fileTimeLo = 1323202978U;
  c20_info[75].fileTimeHi = 0U;
  c20_info[75].mFileTimeLo = 0U;
  c20_info[75].mFileTimeHi = 0U;
  c20_info[76].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c20_info[76].name = "eml_refblas_xswap";
  c20_info[76].dominantType = "double";
  c20_info[76].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c20_info[76].fileTimeLo = 1299109186U;
  c20_info[76].fileTimeHi = 0U;
  c20_info[76].mFileTimeLo = 0U;
  c20_info[76].mFileTimeHi = 0U;
  c20_info[77].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c20_info[77].name = "eml_index_class";
  c20_info[77].dominantType = "";
  c20_info[77].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[77].fileTimeLo = 1323202978U;
  c20_info[77].fileTimeHi = 0U;
  c20_info[77].mFileTimeLo = 0U;
  c20_info[77].mFileTimeHi = 0U;
  c20_info[78].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c20_info[78].name = "abs";
  c20_info[78].dominantType = "coder.internal.indexInt";
  c20_info[78].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c20_info[78].fileTimeLo = 1343862766U;
  c20_info[78].fileTimeHi = 0U;
  c20_info[78].mFileTimeLo = 0U;
  c20_info[78].mFileTimeHi = 0U;
  c20_info[79].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c20_info[79].name = "eml_scalar_abs";
  c20_info[79].dominantType = "coder.internal.indexInt";
  c20_info[79].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c20_info[79].fileTimeLo = 1286851112U;
  c20_info[79].fileTimeHi = 0U;
  c20_info[79].mFileTimeLo = 0U;
  c20_info[79].mFileTimeHi = 0U;
  c20_info[80].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c20_info[80].name = "eml_int_forloop_overflow_check";
  c20_info[80].dominantType = "";
  c20_info[80].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c20_info[80].fileTimeLo = 1346542740U;
  c20_info[80].fileTimeHi = 0U;
  c20_info[80].mFileTimeLo = 0U;
  c20_info[80].mFileTimeHi = 0U;
  c20_info[81].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c20_info[81].name = "eml_index_plus";
  c20_info[81].dominantType = "coder.internal.indexInt";
  c20_info[81].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c20_info[81].fileTimeLo = 1286851178U;
  c20_info[81].fileTimeHi = 0U;
  c20_info[81].mFileTimeLo = 0U;
  c20_info[81].mFileTimeHi = 0U;
  c20_info[82].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c20_info[82].name = "eml_div";
  c20_info[82].dominantType = "double";
  c20_info[82].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c20_info[82].fileTimeLo = 1313380210U;
  c20_info[82].fileTimeHi = 0U;
  c20_info[82].mFileTimeLo = 0U;
  c20_info[82].mFileTimeHi = 0U;
  c20_info[83].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c20_info[83].name = "eml_xgeru";
  c20_info[83].dominantType = "double";
  c20_info[83].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c20_info[83].fileTimeLo = 1299109174U;
  c20_info[83].fileTimeHi = 0U;
  c20_info[83].mFileTimeLo = 0U;
  c20_info[83].mFileTimeHi = 0U;
  c20_info[84].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c20_info[84].name = "eml_blas_inline";
  c20_info[84].dominantType = "";
  c20_info[84].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c20_info[84].fileTimeLo = 1299109168U;
  c20_info[84].fileTimeHi = 0U;
  c20_info[84].mFileTimeLo = 0U;
  c20_info[84].mFileTimeHi = 0U;
  c20_info[85].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c20_info[85].name = "eml_xger";
  c20_info[85].dominantType = "double";
  c20_info[85].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c20_info[85].fileTimeLo = 1299109174U;
  c20_info[85].fileTimeHi = 0U;
  c20_info[85].mFileTimeLo = 0U;
  c20_info[85].mFileTimeHi = 0U;
  c20_info[86].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c20_info[86].name = "eml_blas_inline";
  c20_info[86].dominantType = "";
  c20_info[86].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c20_info[86].fileTimeLo = 1299109168U;
  c20_info[86].fileTimeHi = 0U;
  c20_info[86].mFileTimeLo = 0U;
  c20_info[86].mFileTimeHi = 0U;
  c20_info[87].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c20_info[87].name = "intmax";
  c20_info[87].dominantType = "char";
  c20_info[87].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c20_info[87].fileTimeLo = 1311287716U;
  c20_info[87].fileTimeHi = 0U;
  c20_info[87].mFileTimeLo = 0U;
  c20_info[87].mFileTimeHi = 0U;
  c20_info[88].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c20_info[88].name = "min";
  c20_info[88].dominantType = "double";
  c20_info[88].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c20_info[88].fileTimeLo = 1311287718U;
  c20_info[88].fileTimeHi = 0U;
  c20_info[88].mFileTimeLo = 0U;
  c20_info[88].mFileTimeHi = 0U;
  c20_info[89].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c20_info[89].name = "eml_scalar_eg";
  c20_info[89].dominantType = "double";
  c20_info[89].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c20_info[89].fileTimeLo = 1286851196U;
  c20_info[89].fileTimeHi = 0U;
  c20_info[89].mFileTimeLo = 0U;
  c20_info[89].mFileTimeHi = 0U;
  c20_info[90].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c20_info[90].name = "eml_scalexp_alloc";
  c20_info[90].dominantType = "double";
  c20_info[90].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c20_info[90].fileTimeLo = 1352457260U;
  c20_info[90].fileTimeHi = 0U;
  c20_info[90].mFileTimeLo = 0U;
  c20_info[90].mFileTimeHi = 0U;
  c20_info[91].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c20_info[91].name = "eml_scalar_eg";
  c20_info[91].dominantType = "double";
  c20_info[91].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c20_info[91].fileTimeLo = 1286851196U;
  c20_info[91].fileTimeHi = 0U;
  c20_info[91].mFileTimeLo = 0U;
  c20_info[91].mFileTimeHi = 0U;
  c20_info[92].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c20_info[92].name = "mtimes";
  c20_info[92].dominantType = "double";
  c20_info[92].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[92].fileTimeLo = 1289552092U;
  c20_info[92].fileTimeHi = 0U;
  c20_info[92].mFileTimeLo = 0U;
  c20_info[92].mFileTimeHi = 0U;
  c20_info[93].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c20_info[93].name = "eml_index_class";
  c20_info[93].dominantType = "";
  c20_info[93].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[93].fileTimeLo = 1323202978U;
  c20_info[93].fileTimeHi = 0U;
  c20_info[93].mFileTimeLo = 0U;
  c20_info[93].mFileTimeHi = 0U;
  c20_info[94].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c20_info[94].name = "eml_refblas_xger";
  c20_info[94].dominantType = "double";
  c20_info[94].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c20_info[94].fileTimeLo = 1299109176U;
  c20_info[94].fileTimeHi = 0U;
  c20_info[94].mFileTimeLo = 0U;
  c20_info[94].mFileTimeHi = 0U;
  c20_info[95].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c20_info[95].name = "eml_refblas_xgerx";
  c20_info[95].dominantType = "char";
  c20_info[95].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c20_info[95].fileTimeLo = 1299109178U;
  c20_info[95].fileTimeHi = 0U;
  c20_info[95].mFileTimeLo = 0U;
  c20_info[95].mFileTimeHi = 0U;
  c20_info[96].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c20_info[96].name = "eml_index_class";
  c20_info[96].dominantType = "";
  c20_info[96].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[96].fileTimeLo = 1323202978U;
  c20_info[96].fileTimeHi = 0U;
  c20_info[96].mFileTimeLo = 0U;
  c20_info[96].mFileTimeHi = 0U;
  c20_info[97].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c20_info[97].name = "abs";
  c20_info[97].dominantType = "coder.internal.indexInt";
  c20_info[97].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c20_info[97].fileTimeLo = 1343862766U;
  c20_info[97].fileTimeHi = 0U;
  c20_info[97].mFileTimeLo = 0U;
  c20_info[97].mFileTimeHi = 0U;
  c20_info[98].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c20_info[98].name = "eml_index_minus";
  c20_info[98].dominantType = "double";
  c20_info[98].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c20_info[98].fileTimeLo = 1286851178U;
  c20_info[98].fileTimeHi = 0U;
  c20_info[98].mFileTimeLo = 0U;
  c20_info[98].mFileTimeHi = 0U;
  c20_info[99].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c20_info[99].name = "eml_int_forloop_overflow_check";
  c20_info[99].dominantType = "";
  c20_info[99].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c20_info[99].fileTimeLo = 1346542740U;
  c20_info[99].fileTimeHi = 0U;
  c20_info[99].mFileTimeLo = 0U;
  c20_info[99].mFileTimeHi = 0U;
  c20_info[100].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c20_info[100].name = "eml_index_plus";
  c20_info[100].dominantType = "double";
  c20_info[100].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c20_info[100].fileTimeLo = 1286851178U;
  c20_info[100].fileTimeHi = 0U;
  c20_info[100].mFileTimeLo = 0U;
  c20_info[100].mFileTimeHi = 0U;
  c20_info[101].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c20_info[101].name = "eml_index_plus";
  c20_info[101].dominantType = "coder.internal.indexInt";
  c20_info[101].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c20_info[101].fileTimeLo = 1286851178U;
  c20_info[101].fileTimeHi = 0U;
  c20_info[101].mFileTimeLo = 0U;
  c20_info[101].mFileTimeHi = 0U;
  c20_info[102].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c20_info[102].name = "eml_ipiv2perm";
  c20_info[102].dominantType = "coder.internal.indexInt";
  c20_info[102].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m";
  c20_info[102].fileTimeLo = 1286851182U;
  c20_info[102].fileTimeHi = 0U;
  c20_info[102].mFileTimeLo = 0U;
  c20_info[102].mFileTimeHi = 0U;
  c20_info[103].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m";
  c20_info[103].name = "colon";
  c20_info[103].dominantType = "double";
  c20_info[103].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c20_info[103].fileTimeLo = 1348224328U;
  c20_info[103].fileTimeHi = 0U;
  c20_info[103].mFileTimeLo = 0U;
  c20_info[103].mFileTimeHi = 0U;
  c20_info[104].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m";
  c20_info[104].name = "eml_index_class";
  c20_info[104].dominantType = "";
  c20_info[104].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[104].fileTimeLo = 1323202978U;
  c20_info[104].fileTimeHi = 0U;
  c20_info[104].mFileTimeLo = 0U;
  c20_info[104].mFileTimeHi = 0U;
  c20_info[105].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m";
  c20_info[105].name = "coder.internal.indexIntRelop";
  c20_info[105].dominantType = "";
  c20_info[105].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m";
  c20_info[105].fileTimeLo = 1326760722U;
  c20_info[105].fileTimeHi = 0U;
  c20_info[105].mFileTimeLo = 0U;
  c20_info[105].mFileTimeHi = 0U;
  c20_info[106].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass";
  c20_info[106].name = "eml_float_model";
  c20_info[106].dominantType = "char";
  c20_info[106].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c20_info[106].fileTimeLo = 1326760396U;
  c20_info[106].fileTimeHi = 0U;
  c20_info[106].mFileTimeLo = 0U;
  c20_info[106].mFileTimeHi = 0U;
  c20_info[107].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass";
  c20_info[107].name = "intmin";
  c20_info[107].dominantType = "char";
  c20_info[107].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c20_info[107].fileTimeLo = 1311287718U;
  c20_info[107].fileTimeHi = 0U;
  c20_info[107].mFileTimeLo = 0U;
  c20_info[107].mFileTimeHi = 0U;
  c20_info[108].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c20_info[108].name = "eml_int_forloop_overflow_check";
  c20_info[108].dominantType = "";
  c20_info[108].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c20_info[108].fileTimeLo = 1346542740U;
  c20_info[108].fileTimeHi = 0U;
  c20_info[108].mFileTimeLo = 0U;
  c20_info[108].mFileTimeHi = 0U;
  c20_info[109].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c20_info[109].name = "eml_index_plus";
  c20_info[109].dominantType = "double";
  c20_info[109].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c20_info[109].fileTimeLo = 1286851178U;
  c20_info[109].fileTimeHi = 0U;
  c20_info[109].mFileTimeLo = 0U;
  c20_info[109].mFileTimeHi = 0U;
  c20_info[110].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c20_info[110].name = "mtimes";
  c20_info[110].dominantType = "double";
  c20_info[110].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[110].fileTimeLo = 1289552092U;
  c20_info[110].fileTimeHi = 0U;
  c20_info[110].mFileTimeLo = 0U;
  c20_info[110].mFileTimeHi = 0U;
  c20_info[111].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c20_info[111].name = "eml_scalar_eg";
  c20_info[111].dominantType = "double";
  c20_info[111].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c20_info[111].fileTimeLo = 1286851196U;
  c20_info[111].fileTimeHi = 0U;
  c20_info[111].mFileTimeLo = 0U;
  c20_info[111].mFileTimeHi = 0U;
  c20_info[112].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c20_info[112].name = "eml_xtrsm";
  c20_info[112].dominantType = "char";
  c20_info[112].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c20_info[112].fileTimeLo = 1299109178U;
  c20_info[112].fileTimeHi = 0U;
  c20_info[112].mFileTimeLo = 0U;
  c20_info[112].mFileTimeHi = 0U;
  c20_info[113].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c20_info[113].name = "eml_blas_inline";
  c20_info[113].dominantType = "";
  c20_info[113].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c20_info[113].fileTimeLo = 1299109168U;
  c20_info[113].fileTimeHi = 0U;
  c20_info[113].mFileTimeLo = 0U;
  c20_info[113].mFileTimeHi = 0U;
  c20_info[114].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m!below_threshold";
  c20_info[114].name = "mtimes";
  c20_info[114].dominantType = "double";
  c20_info[114].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[114].fileTimeLo = 1289552092U;
  c20_info[114].fileTimeHi = 0U;
  c20_info[114].mFileTimeLo = 0U;
  c20_info[114].mFileTimeHi = 0U;
  c20_info[115].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c20_info[115].name = "eml_index_class";
  c20_info[115].dominantType = "";
  c20_info[115].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[115].fileTimeLo = 1323202978U;
  c20_info[115].fileTimeHi = 0U;
  c20_info[115].mFileTimeLo = 0U;
  c20_info[115].mFileTimeHi = 0U;
  c20_info[116].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c20_info[116].name = "eml_scalar_eg";
  c20_info[116].dominantType = "double";
  c20_info[116].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c20_info[116].fileTimeLo = 1286851196U;
  c20_info[116].fileTimeHi = 0U;
  c20_info[116].mFileTimeLo = 0U;
  c20_info[116].mFileTimeHi = 0U;
  c20_info[117].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c20_info[117].name = "eml_refblas_xtrsm";
  c20_info[117].dominantType = "char";
  c20_info[117].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c20_info[117].fileTimeLo = 1299109186U;
  c20_info[117].fileTimeHi = 0U;
  c20_info[117].mFileTimeLo = 0U;
  c20_info[117].mFileTimeHi = 0U;
  c20_info[118].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c20_info[118].name = "eml_scalar_eg";
  c20_info[118].dominantType = "double";
  c20_info[118].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c20_info[118].fileTimeLo = 1286851196U;
  c20_info[118].fileTimeHi = 0U;
  c20_info[118].mFileTimeLo = 0U;
  c20_info[118].mFileTimeHi = 0U;
  c20_info[119].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c20_info[119].name = "eml_index_minus";
  c20_info[119].dominantType = "double";
  c20_info[119].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c20_info[119].fileTimeLo = 1286851178U;
  c20_info[119].fileTimeHi = 0U;
  c20_info[119].mFileTimeLo = 0U;
  c20_info[119].mFileTimeHi = 0U;
  c20_info[120].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c20_info[120].name = "eml_index_class";
  c20_info[120].dominantType = "";
  c20_info[120].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[120].fileTimeLo = 1323202978U;
  c20_info[120].fileTimeHi = 0U;
  c20_info[120].mFileTimeLo = 0U;
  c20_info[120].mFileTimeHi = 0U;
  c20_info[121].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c20_info[121].name = "eml_int_forloop_overflow_check";
  c20_info[121].dominantType = "";
  c20_info[121].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c20_info[121].fileTimeLo = 1346542740U;
  c20_info[121].fileTimeHi = 0U;
  c20_info[121].mFileTimeLo = 0U;
  c20_info[121].mFileTimeHi = 0U;
  c20_info[122].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c20_info[122].name = "eml_index_times";
  c20_info[122].dominantType = "coder.internal.indexInt";
  c20_info[122].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c20_info[122].fileTimeLo = 1286851180U;
  c20_info[122].fileTimeHi = 0U;
  c20_info[122].mFileTimeLo = 0U;
  c20_info[122].mFileTimeHi = 0U;
  c20_info[123].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c20_info[123].name = "eml_index_plus";
  c20_info[123].dominantType = "coder.internal.indexInt";
  c20_info[123].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c20_info[123].fileTimeLo = 1286851178U;
  c20_info[123].fileTimeHi = 0U;
  c20_info[123].mFileTimeLo = 0U;
  c20_info[123].mFileTimeHi = 0U;
  c20_info[124].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c20_info[124].name = "intmin";
  c20_info[124].dominantType = "char";
  c20_info[124].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c20_info[124].fileTimeLo = 1311287718U;
  c20_info[124].fileTimeHi = 0U;
  c20_info[124].mFileTimeLo = 0U;
  c20_info[124].mFileTimeHi = 0U;
  c20_info[125].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c20_info[125].name = "eml_div";
  c20_info[125].dominantType = "double";
  c20_info[125].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c20_info[125].fileTimeLo = 1313380210U;
  c20_info[125].fileTimeHi = 0U;
  c20_info[125].mFileTimeLo = 0U;
  c20_info[125].mFileTimeHi = 0U;
  c20_info[126].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c20_info[126].name = "norm";
  c20_info[126].dominantType = "double";
  c20_info[126].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c20_info[126].fileTimeLo = 1336554494U;
  c20_info[126].fileTimeHi = 0U;
  c20_info[126].mFileTimeLo = 0U;
  c20_info[126].mFileTimeHi = 0U;
  c20_info[127].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c20_info[127].name = "abs";
  c20_info[127].dominantType = "double";
  c20_info[127].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c20_info[127].fileTimeLo = 1343862766U;
  c20_info[127].fileTimeHi = 0U;
  c20_info[127].mFileTimeLo = 0U;
  c20_info[127].mFileTimeHi = 0U;
}

static void c20_c_info_helper(c20_ResolvedFunctionInfo c20_info[281])
{
  c20_info[128].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c20_info[128].name = "isnan";
  c20_info[128].dominantType = "double";
  c20_info[128].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c20_info[128].fileTimeLo = 1286851160U;
  c20_info[128].fileTimeHi = 0U;
  c20_info[128].mFileTimeLo = 0U;
  c20_info[128].mFileTimeHi = 0U;
  c20_info[129].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c20_info[129].name = "eml_guarded_nan";
  c20_info[129].dominantType = "char";
  c20_info[129].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c20_info[129].fileTimeLo = 1286851176U;
  c20_info[129].fileTimeHi = 0U;
  c20_info[129].mFileTimeLo = 0U;
  c20_info[129].mFileTimeHi = 0U;
  c20_info[130].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c20_info[130].name = "eml_is_float_class";
  c20_info[130].dominantType = "char";
  c20_info[130].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c20_info[130].fileTimeLo = 1286851182U;
  c20_info[130].fileTimeHi = 0U;
  c20_info[130].mFileTimeLo = 0U;
  c20_info[130].mFileTimeHi = 0U;
  c20_info[131].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c20_info[131].name = "mtimes";
  c20_info[131].dominantType = "double";
  c20_info[131].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[131].fileTimeLo = 1289552092U;
  c20_info[131].fileTimeHi = 0U;
  c20_info[131].mFileTimeLo = 0U;
  c20_info[131].mFileTimeHi = 0U;
  c20_info[132].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c20_info[132].name = "eml_warning";
  c20_info[132].dominantType = "char";
  c20_info[132].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c20_info[132].fileTimeLo = 1286851202U;
  c20_info[132].fileTimeHi = 0U;
  c20_info[132].mFileTimeLo = 0U;
  c20_info[132].mFileTimeHi = 0U;
  c20_info[133].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c20_info[133].name = "isnan";
  c20_info[133].dominantType = "double";
  c20_info[133].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c20_info[133].fileTimeLo = 1286851160U;
  c20_info[133].fileTimeHi = 0U;
  c20_info[133].mFileTimeLo = 0U;
  c20_info[133].mFileTimeHi = 0U;
  c20_info[134].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c20_info[134].name = "eps";
  c20_info[134].dominantType = "char";
  c20_info[134].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c20_info[134].fileTimeLo = 1326760396U;
  c20_info[134].fileTimeHi = 0U;
  c20_info[134].mFileTimeLo = 0U;
  c20_info[134].mFileTimeHi = 0U;
  c20_info[135].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c20_info[135].name = "eml_flt2str";
  c20_info[135].dominantType = "double";
  c20_info[135].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c20_info[135].fileTimeLo = 1309483596U;
  c20_info[135].fileTimeHi = 0U;
  c20_info[135].mFileTimeLo = 0U;
  c20_info[135].mFileTimeHi = 0U;
  c20_info[136].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c20_info[136].name = "char";
  c20_info[136].dominantType = "double";
  c20_info[136].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m";
  c20_info[136].fileTimeLo = 1319762368U;
  c20_info[136].fileTimeHi = 0U;
  c20_info[136].mFileTimeLo = 0U;
  c20_info[136].mFileTimeHi = 0U;
  c20_info[137].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[137].name = "eml_index_class";
  c20_info[137].dominantType = "";
  c20_info[137].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[137].fileTimeLo = 1323202978U;
  c20_info[137].fileTimeHi = 0U;
  c20_info[137].mFileTimeLo = 0U;
  c20_info[137].mFileTimeHi = 0U;
  c20_info[138].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[138].name = "eml_scalar_eg";
  c20_info[138].dominantType = "double";
  c20_info[138].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c20_info[138].fileTimeLo = 1286851196U;
  c20_info[138].fileTimeHi = 0U;
  c20_info[138].mFileTimeLo = 0U;
  c20_info[138].mFileTimeHi = 0U;
  c20_info[139].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[139].name = "eml_xgemm";
  c20_info[139].dominantType = "char";
  c20_info[139].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c20_info[139].fileTimeLo = 1299109172U;
  c20_info[139].fileTimeHi = 0U;
  c20_info[139].mFileTimeLo = 0U;
  c20_info[139].mFileTimeHi = 0U;
  c20_info[140].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c20_info[140].name = "eml_blas_inline";
  c20_info[140].dominantType = "";
  c20_info[140].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c20_info[140].fileTimeLo = 1299109168U;
  c20_info[140].fileTimeHi = 0U;
  c20_info[140].mFileTimeLo = 0U;
  c20_info[140].mFileTimeHi = 0U;
  c20_info[141].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c20_info[141].name = "mtimes";
  c20_info[141].dominantType = "double";
  c20_info[141].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[141].fileTimeLo = 1289552092U;
  c20_info[141].fileTimeHi = 0U;
  c20_info[141].mFileTimeLo = 0U;
  c20_info[141].mFileTimeHi = 0U;
  c20_info[142].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c20_info[142].name = "eml_index_class";
  c20_info[142].dominantType = "";
  c20_info[142].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[142].fileTimeLo = 1323202978U;
  c20_info[142].fileTimeHi = 0U;
  c20_info[142].mFileTimeLo = 0U;
  c20_info[142].mFileTimeHi = 0U;
  c20_info[143].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c20_info[143].name = "eml_scalar_eg";
  c20_info[143].dominantType = "double";
  c20_info[143].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c20_info[143].fileTimeLo = 1286851196U;
  c20_info[143].fileTimeHi = 0U;
  c20_info[143].mFileTimeLo = 0U;
  c20_info[143].mFileTimeHi = 0U;
  c20_info[144].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c20_info[144].name = "eml_refblas_xgemm";
  c20_info[144].dominantType = "char";
  c20_info[144].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c20_info[144].fileTimeLo = 1299109174U;
  c20_info[144].fileTimeHi = 0U;
  c20_info[144].mFileTimeLo = 0U;
  c20_info[144].mFileTimeHi = 0U;
  c20_info[145].context = "";
  c20_info[145].name = "pinv";
  c20_info[145].dominantType = "double";
  c20_info[145].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m";
  c20_info[145].fileTimeLo = 1286851228U;
  c20_info[145].fileTimeHi = 0U;
  c20_info[145].mFileTimeLo = 0U;
  c20_info[145].mFileTimeHi = 0U;
  c20_info[146].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c20_info[146].name = "eml_index_class";
  c20_info[146].dominantType = "";
  c20_info[146].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[146].fileTimeLo = 1323202978U;
  c20_info[146].fileTimeHi = 0U;
  c20_info[146].mFileTimeLo = 0U;
  c20_info[146].mFileTimeHi = 0U;
  c20_info[147].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c20_info[147].name = "eml_scalar_eg";
  c20_info[147].dominantType = "double";
  c20_info[147].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c20_info[147].fileTimeLo = 1286851196U;
  c20_info[147].fileTimeHi = 0U;
  c20_info[147].mFileTimeLo = 0U;
  c20_info[147].mFileTimeHi = 0U;
  c20_info[148].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c20_info[148].name = "svd";
  c20_info[148].dominantType = "double";
  c20_info[148].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c20_info[148].fileTimeLo = 1286851232U;
  c20_info[148].fileTimeHi = 0U;
  c20_info[148].mFileTimeLo = 0U;
  c20_info[148].mFileTimeHi = 0U;
  c20_info[149].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c20_info[149].name = "eml_index_class";
  c20_info[149].dominantType = "";
  c20_info[149].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[149].fileTimeLo = 1323202978U;
  c20_info[149].fileTimeHi = 0U;
  c20_info[149].mFileTimeLo = 0U;
  c20_info[149].mFileTimeHi = 0U;
  c20_info[150].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c20_info[150].name = "eml_int_forloop_overflow_check";
  c20_info[150].dominantType = "";
  c20_info[150].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c20_info[150].fileTimeLo = 1346542740U;
  c20_info[150].fileTimeHi = 0U;
  c20_info[150].mFileTimeLo = 0U;
  c20_info[150].mFileTimeHi = 0U;
  c20_info[151].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c20_info[151].name = "isfinite";
  c20_info[151].dominantType = "double";
  c20_info[151].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c20_info[151].fileTimeLo = 1286851158U;
  c20_info[151].fileTimeHi = 0U;
  c20_info[151].mFileTimeLo = 0U;
  c20_info[151].mFileTimeHi = 0U;
  c20_info[152].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c20_info[152].name = "isinf";
  c20_info[152].dominantType = "double";
  c20_info[152].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c20_info[152].fileTimeLo = 1286851160U;
  c20_info[152].fileTimeHi = 0U;
  c20_info[152].mFileTimeLo = 0U;
  c20_info[152].mFileTimeHi = 0U;
  c20_info[153].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c20_info[153].name = "isnan";
  c20_info[153].dominantType = "double";
  c20_info[153].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c20_info[153].fileTimeLo = 1286851160U;
  c20_info[153].fileTimeHi = 0U;
  c20_info[153].mFileTimeLo = 0U;
  c20_info[153].mFileTimeHi = 0U;
  c20_info[154].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c20_info[154].name = "eml_error";
  c20_info[154].dominantType = "char";
  c20_info[154].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c20_info[154].fileTimeLo = 1343862758U;
  c20_info[154].fileTimeHi = 0U;
  c20_info[154].mFileTimeLo = 0U;
  c20_info[154].mFileTimeHi = 0U;
  c20_info[155].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c20_info[155].name = "eml_xgesvd";
  c20_info[155].dominantType = "double";
  c20_info[155].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m";
  c20_info[155].fileTimeLo = 1286851206U;
  c20_info[155].fileTimeHi = 0U;
  c20_info[155].mFileTimeLo = 0U;
  c20_info[155].mFileTimeHi = 0U;
  c20_info[156].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgesvd.m";
  c20_info[156].name = "eml_lapack_xgesvd";
  c20_info[156].dominantType = "double";
  c20_info[156].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m";
  c20_info[156].fileTimeLo = 1286851210U;
  c20_info[156].fileTimeHi = 0U;
  c20_info[156].mFileTimeLo = 0U;
  c20_info[156].mFileTimeHi = 0U;
  c20_info[157].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgesvd.m";
  c20_info[157].name = "eml_matlab_zsvdc";
  c20_info[157].dominantType = "double";
  c20_info[157].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c20_info[157].fileTimeLo = 1295317266U;
  c20_info[157].fileTimeHi = 0U;
  c20_info[157].mFileTimeLo = 0U;
  c20_info[157].mFileTimeHi = 0U;
  c20_info[158].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c20_info[158].name = "eml_index_class";
  c20_info[158].dominantType = "";
  c20_info[158].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[158].fileTimeLo = 1323202978U;
  c20_info[158].fileTimeHi = 0U;
  c20_info[158].mFileTimeLo = 0U;
  c20_info[158].mFileTimeHi = 0U;
  c20_info[159].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c20_info[159].name = "eml_scalar_eg";
  c20_info[159].dominantType = "double";
  c20_info[159].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c20_info[159].fileTimeLo = 1286851196U;
  c20_info[159].fileTimeHi = 0U;
  c20_info[159].mFileTimeLo = 0U;
  c20_info[159].mFileTimeHi = 0U;
  c20_info[160].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c20_info[160].name = "eml_index_plus";
  c20_info[160].dominantType = "double";
  c20_info[160].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c20_info[160].fileTimeLo = 1286851178U;
  c20_info[160].fileTimeHi = 0U;
  c20_info[160].mFileTimeLo = 0U;
  c20_info[160].mFileTimeHi = 0U;
  c20_info[161].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c20_info[161].name = "min";
  c20_info[161].dominantType = "coder.internal.indexInt";
  c20_info[161].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c20_info[161].fileTimeLo = 1311287718U;
  c20_info[161].fileTimeHi = 0U;
  c20_info[161].mFileTimeLo = 0U;
  c20_info[161].mFileTimeHi = 0U;
  c20_info[162].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c20_info[162].name = "max";
  c20_info[162].dominantType = "double";
  c20_info[162].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c20_info[162].fileTimeLo = 1311287716U;
  c20_info[162].fileTimeHi = 0U;
  c20_info[162].mFileTimeLo = 0U;
  c20_info[162].mFileTimeHi = 0U;
  c20_info[163].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c20_info[163].name = "eml_min_or_max";
  c20_info[163].dominantType = "char";
  c20_info[163].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c20_info[163].fileTimeLo = 1334103890U;
  c20_info[163].fileTimeHi = 0U;
  c20_info[163].mFileTimeLo = 0U;
  c20_info[163].mFileTimeHi = 0U;
  c20_info[164].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c20_info[164].name = "eml_relop";
  c20_info[164].dominantType = "function_handle";
  c20_info[164].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c20_info[164].fileTimeLo = 1342483582U;
  c20_info[164].fileTimeHi = 0U;
  c20_info[164].mFileTimeLo = 0U;
  c20_info[164].mFileTimeHi = 0U;
  c20_info[165].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c20_info[165].name = "coder.internal.indexIntRelop";
  c20_info[165].dominantType = "";
  c20_info[165].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m";
  c20_info[165].fileTimeLo = 1326760722U;
  c20_info[165].fileTimeHi = 0U;
  c20_info[165].mFileTimeLo = 0U;
  c20_info[165].mFileTimeHi = 0U;
  c20_info[166].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c20_info[166].name = "isnan";
  c20_info[166].dominantType = "coder.internal.indexInt";
  c20_info[166].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c20_info[166].fileTimeLo = 1286851160U;
  c20_info[166].fileTimeHi = 0U;
  c20_info[166].mFileTimeLo = 0U;
  c20_info[166].mFileTimeHi = 0U;
  c20_info[167].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c20_info[167].name = "eml_index_minus";
  c20_info[167].dominantType = "double";
  c20_info[167].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c20_info[167].fileTimeLo = 1286851178U;
  c20_info[167].fileTimeHi = 0U;
  c20_info[167].mFileTimeLo = 0U;
  c20_info[167].mFileTimeHi = 0U;
  c20_info[168].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c20_info[168].name = "max";
  c20_info[168].dominantType = "coder.internal.indexInt";
  c20_info[168].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c20_info[168].fileTimeLo = 1311287716U;
  c20_info[168].fileTimeHi = 0U;
  c20_info[168].mFileTimeLo = 0U;
  c20_info[168].mFileTimeHi = 0U;
  c20_info[169].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c20_info[169].name = "eml_int_forloop_overflow_check";
  c20_info[169].dominantType = "";
  c20_info[169].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c20_info[169].fileTimeLo = 1346542740U;
  c20_info[169].fileTimeHi = 0U;
  c20_info[169].mFileTimeLo = 0U;
  c20_info[169].mFileTimeHi = 0U;
  c20_info[170].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c20_info[170].name = "eml_index_times";
  c20_info[170].dominantType = "coder.internal.indexInt";
  c20_info[170].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c20_info[170].fileTimeLo = 1286851180U;
  c20_info[170].fileTimeHi = 0U;
  c20_info[170].mFileTimeLo = 0U;
  c20_info[170].mFileTimeHi = 0U;
  c20_info[171].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c20_info[171].name = "eml_index_plus";
  c20_info[171].dominantType = "coder.internal.indexInt";
  c20_info[171].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c20_info[171].fileTimeLo = 1286851178U;
  c20_info[171].fileTimeHi = 0U;
  c20_info[171].mFileTimeLo = 0U;
  c20_info[171].mFileTimeHi = 0U;
  c20_info[172].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c20_info[172].name = "eml_index_minus";
  c20_info[172].dominantType = "coder.internal.indexInt";
  c20_info[172].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c20_info[172].fileTimeLo = 1286851178U;
  c20_info[172].fileTimeHi = 0U;
  c20_info[172].mFileTimeLo = 0U;
  c20_info[172].mFileTimeHi = 0U;
  c20_info[173].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c20_info[173].name = "eml_xnrm2";
  c20_info[173].dominantType = "double";
  c20_info[173].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c20_info[173].fileTimeLo = 1299109176U;
  c20_info[173].fileTimeHi = 0U;
  c20_info[173].mFileTimeLo = 0U;
  c20_info[173].mFileTimeHi = 0U;
  c20_info[174].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c20_info[174].name = "eml_blas_inline";
  c20_info[174].dominantType = "";
  c20_info[174].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c20_info[174].fileTimeLo = 1299109168U;
  c20_info[174].fileTimeHi = 0U;
  c20_info[174].mFileTimeLo = 0U;
  c20_info[174].mFileTimeHi = 0U;
  c20_info[175].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m!below_threshold";
  c20_info[175].name = "length";
  c20_info[175].dominantType = "double";
  c20_info[175].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c20_info[175].fileTimeLo = 1303178606U;
  c20_info[175].fileTimeHi = 0U;
  c20_info[175].mFileTimeLo = 0U;
  c20_info[175].mFileTimeHi = 0U;
  c20_info[176].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c20_info[176].name = "eml_index_class";
  c20_info[176].dominantType = "";
  c20_info[176].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[176].fileTimeLo = 1323202978U;
  c20_info[176].fileTimeHi = 0U;
  c20_info[176].mFileTimeLo = 0U;
  c20_info[176].mFileTimeHi = 0U;
  c20_info[177].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c20_info[177].name = "eml_refblas_xnrm2";
  c20_info[177].dominantType = "double";
  c20_info[177].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c20_info[177].fileTimeLo = 1299109184U;
  c20_info[177].fileTimeHi = 0U;
  c20_info[177].mFileTimeLo = 0U;
  c20_info[177].mFileTimeHi = 0U;
  c20_info[178].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c20_info[178].name = "abs";
  c20_info[178].dominantType = "double";
  c20_info[178].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c20_info[178].fileTimeLo = 1343862766U;
  c20_info[178].fileTimeHi = 0U;
  c20_info[178].mFileTimeLo = 0U;
  c20_info[178].mFileTimeHi = 0U;
  c20_info[179].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c20_info[179].name = "realmin";
  c20_info[179].dominantType = "char";
  c20_info[179].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c20_info[179].fileTimeLo = 1307683642U;
  c20_info[179].fileTimeHi = 0U;
  c20_info[179].mFileTimeLo = 0U;
  c20_info[179].mFileTimeHi = 0U;
  c20_info[180].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c20_info[180].name = "eml_index_class";
  c20_info[180].dominantType = "";
  c20_info[180].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[180].fileTimeLo = 1323202978U;
  c20_info[180].fileTimeHi = 0U;
  c20_info[180].mFileTimeLo = 0U;
  c20_info[180].mFileTimeHi = 0U;
  c20_info[181].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c20_info[181].name = "eml_index_minus";
  c20_info[181].dominantType = "double";
  c20_info[181].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c20_info[181].fileTimeLo = 1286851178U;
  c20_info[181].fileTimeHi = 0U;
  c20_info[181].mFileTimeLo = 0U;
  c20_info[181].mFileTimeHi = 0U;
  c20_info[182].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c20_info[182].name = "eml_index_times";
  c20_info[182].dominantType = "coder.internal.indexInt";
  c20_info[182].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c20_info[182].fileTimeLo = 1286851180U;
  c20_info[182].fileTimeHi = 0U;
  c20_info[182].mFileTimeLo = 0U;
  c20_info[182].mFileTimeHi = 0U;
  c20_info[183].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c20_info[183].name = "eml_index_plus";
  c20_info[183].dominantType = "coder.internal.indexInt";
  c20_info[183].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c20_info[183].fileTimeLo = 1286851178U;
  c20_info[183].fileTimeHi = 0U;
  c20_info[183].mFileTimeLo = 0U;
  c20_info[183].mFileTimeHi = 0U;
  c20_info[184].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c20_info[184].name = "eml_int_forloop_overflow_check";
  c20_info[184].dominantType = "";
  c20_info[184].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c20_info[184].fileTimeLo = 1346542740U;
  c20_info[184].fileTimeHi = 0U;
  c20_info[184].mFileTimeLo = 0U;
  c20_info[184].mFileTimeHi = 0U;
  c20_info[185].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c20_info[185].name = "eml_div";
  c20_info[185].dominantType = "double";
  c20_info[185].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c20_info[185].fileTimeLo = 1313380210U;
  c20_info[185].fileTimeHi = 0U;
  c20_info[185].mFileTimeLo = 0U;
  c20_info[185].mFileTimeHi = 0U;
  c20_info[186].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c20_info[186].name = "eml_xscal";
  c20_info[186].dominantType = "double";
  c20_info[186].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  c20_info[186].fileTimeLo = 1299109176U;
  c20_info[186].fileTimeHi = 0U;
  c20_info[186].mFileTimeLo = 0U;
  c20_info[186].mFileTimeHi = 0U;
  c20_info[187].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  c20_info[187].name = "eml_blas_inline";
  c20_info[187].dominantType = "";
  c20_info[187].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c20_info[187].fileTimeLo = 1299109168U;
  c20_info[187].fileTimeHi = 0U;
  c20_info[187].mFileTimeLo = 0U;
  c20_info[187].mFileTimeHi = 0U;
  c20_info[188].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m!below_threshold";
  c20_info[188].name = "length";
  c20_info[188].dominantType = "double";
  c20_info[188].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c20_info[188].fileTimeLo = 1303178606U;
  c20_info[188].fileTimeHi = 0U;
  c20_info[188].mFileTimeLo = 0U;
  c20_info[188].mFileTimeHi = 0U;
  c20_info[189].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c20_info[189].name = "eml_index_class";
  c20_info[189].dominantType = "";
  c20_info[189].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[189].fileTimeLo = 1323202978U;
  c20_info[189].fileTimeHi = 0U;
  c20_info[189].mFileTimeLo = 0U;
  c20_info[189].mFileTimeHi = 0U;
  c20_info[190].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c20_info[190].name = "eml_scalar_eg";
  c20_info[190].dominantType = "double";
  c20_info[190].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c20_info[190].fileTimeLo = 1286851196U;
  c20_info[190].fileTimeHi = 0U;
  c20_info[190].mFileTimeLo = 0U;
  c20_info[190].mFileTimeHi = 0U;
  c20_info[191].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xscal.m";
  c20_info[191].name = "eml_refblas_xscal";
  c20_info[191].dominantType = "double";
  c20_info[191].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c20_info[191].fileTimeLo = 1299109184U;
  c20_info[191].fileTimeHi = 0U;
  c20_info[191].mFileTimeLo = 0U;
  c20_info[191].mFileTimeHi = 0U;
}

static void c20_d_info_helper(c20_ResolvedFunctionInfo c20_info[281])
{
  c20_info[192].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c20_info[192].name = "eml_index_class";
  c20_info[192].dominantType = "";
  c20_info[192].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[192].fileTimeLo = 1323202978U;
  c20_info[192].fileTimeHi = 0U;
  c20_info[192].mFileTimeLo = 0U;
  c20_info[192].mFileTimeHi = 0U;
  c20_info[193].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c20_info[193].name = "eml_index_minus";
  c20_info[193].dominantType = "double";
  c20_info[193].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c20_info[193].fileTimeLo = 1286851178U;
  c20_info[193].fileTimeHi = 0U;
  c20_info[193].mFileTimeLo = 0U;
  c20_info[193].mFileTimeHi = 0U;
  c20_info[194].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c20_info[194].name = "eml_index_times";
  c20_info[194].dominantType = "coder.internal.indexInt";
  c20_info[194].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c20_info[194].fileTimeLo = 1286851180U;
  c20_info[194].fileTimeHi = 0U;
  c20_info[194].mFileTimeLo = 0U;
  c20_info[194].mFileTimeHi = 0U;
  c20_info[195].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c20_info[195].name = "eml_index_plus";
  c20_info[195].dominantType = "coder.internal.indexInt";
  c20_info[195].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c20_info[195].fileTimeLo = 1286851178U;
  c20_info[195].fileTimeHi = 0U;
  c20_info[195].mFileTimeLo = 0U;
  c20_info[195].mFileTimeHi = 0U;
  c20_info[196].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xscal.m";
  c20_info[196].name = "eml_int_forloop_overflow_check";
  c20_info[196].dominantType = "";
  c20_info[196].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c20_info[196].fileTimeLo = 1346542740U;
  c20_info[196].fileTimeHi = 0U;
  c20_info[196].mFileTimeLo = 0U;
  c20_info[196].mFileTimeHi = 0U;
  c20_info[197].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c20_info[197].name = "eml_xdotc";
  c20_info[197].dominantType = "double";
  c20_info[197].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c20_info[197].fileTimeLo = 1299109172U;
  c20_info[197].fileTimeHi = 0U;
  c20_info[197].mFileTimeLo = 0U;
  c20_info[197].mFileTimeHi = 0U;
  c20_info[198].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c20_info[198].name = "eml_blas_inline";
  c20_info[198].dominantType = "";
  c20_info[198].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c20_info[198].fileTimeLo = 1299109168U;
  c20_info[198].fileTimeHi = 0U;
  c20_info[198].mFileTimeLo = 0U;
  c20_info[198].mFileTimeHi = 0U;
  c20_info[199].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m";
  c20_info[199].name = "eml_xdot";
  c20_info[199].dominantType = "double";
  c20_info[199].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c20_info[199].fileTimeLo = 1299109172U;
  c20_info[199].fileTimeHi = 0U;
  c20_info[199].mFileTimeLo = 0U;
  c20_info[199].mFileTimeHi = 0U;
  c20_info[200].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c20_info[200].name = "eml_blas_inline";
  c20_info[200].dominantType = "";
  c20_info[200].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c20_info[200].fileTimeLo = 1299109168U;
  c20_info[200].fileTimeHi = 0U;
  c20_info[200].mFileTimeLo = 0U;
  c20_info[200].mFileTimeHi = 0U;
  c20_info[201].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m!below_threshold";
  c20_info[201].name = "length";
  c20_info[201].dominantType = "double";
  c20_info[201].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c20_info[201].fileTimeLo = 1303178606U;
  c20_info[201].fileTimeHi = 0U;
  c20_info[201].mFileTimeLo = 0U;
  c20_info[201].mFileTimeHi = 0U;
  c20_info[202].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c20_info[202].name = "eml_index_class";
  c20_info[202].dominantType = "";
  c20_info[202].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[202].fileTimeLo = 1323202978U;
  c20_info[202].fileTimeHi = 0U;
  c20_info[202].mFileTimeLo = 0U;
  c20_info[202].mFileTimeHi = 0U;
  c20_info[203].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c20_info[203].name = "eml_refblas_xdot";
  c20_info[203].dominantType = "double";
  c20_info[203].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c20_info[203].fileTimeLo = 1299109172U;
  c20_info[203].fileTimeHi = 0U;
  c20_info[203].mFileTimeLo = 0U;
  c20_info[203].mFileTimeHi = 0U;
  c20_info[204].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c20_info[204].name = "eml_refblas_xdotx";
  c20_info[204].dominantType = "char";
  c20_info[204].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c20_info[204].fileTimeLo = 1299109174U;
  c20_info[204].fileTimeHi = 0U;
  c20_info[204].mFileTimeLo = 0U;
  c20_info[204].mFileTimeHi = 0U;
  c20_info[205].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c20_info[205].name = "eml_scalar_eg";
  c20_info[205].dominantType = "double";
  c20_info[205].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c20_info[205].fileTimeLo = 1286851196U;
  c20_info[205].fileTimeHi = 0U;
  c20_info[205].mFileTimeLo = 0U;
  c20_info[205].mFileTimeHi = 0U;
  c20_info[206].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c20_info[206].name = "eml_index_class";
  c20_info[206].dominantType = "";
  c20_info[206].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[206].fileTimeLo = 1323202978U;
  c20_info[206].fileTimeHi = 0U;
  c20_info[206].mFileTimeLo = 0U;
  c20_info[206].mFileTimeHi = 0U;
  c20_info[207].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c20_info[207].name = "eml_int_forloop_overflow_check";
  c20_info[207].dominantType = "";
  c20_info[207].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c20_info[207].fileTimeLo = 1346542740U;
  c20_info[207].fileTimeHi = 0U;
  c20_info[207].mFileTimeLo = 0U;
  c20_info[207].mFileTimeHi = 0U;
  c20_info[208].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c20_info[208].name = "eml_index_plus";
  c20_info[208].dominantType = "coder.internal.indexInt";
  c20_info[208].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c20_info[208].fileTimeLo = 1286851178U;
  c20_info[208].fileTimeHi = 0U;
  c20_info[208].mFileTimeLo = 0U;
  c20_info[208].mFileTimeHi = 0U;
  c20_info[209].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c20_info[209].name = "eml_xaxpy";
  c20_info[209].dominantType = "double";
  c20_info[209].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m";
  c20_info[209].fileTimeLo = 1299109170U;
  c20_info[209].fileTimeHi = 0U;
  c20_info[209].mFileTimeLo = 0U;
  c20_info[209].mFileTimeHi = 0U;
  c20_info[210].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m";
  c20_info[210].name = "eml_blas_inline";
  c20_info[210].dominantType = "";
  c20_info[210].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c20_info[210].fileTimeLo = 1299109168U;
  c20_info[210].fileTimeHi = 0U;
  c20_info[210].mFileTimeLo = 0U;
  c20_info[210].mFileTimeHi = 0U;
  c20_info[211].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m!below_threshold";
  c20_info[211].name = "length";
  c20_info[211].dominantType = "double";
  c20_info[211].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c20_info[211].fileTimeLo = 1303178606U;
  c20_info[211].fileTimeHi = 0U;
  c20_info[211].mFileTimeLo = 0U;
  c20_info[211].mFileTimeHi = 0U;
  c20_info[212].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m";
  c20_info[212].name = "eml_index_class";
  c20_info[212].dominantType = "";
  c20_info[212].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[212].fileTimeLo = 1323202978U;
  c20_info[212].fileTimeHi = 0U;
  c20_info[212].mFileTimeLo = 0U;
  c20_info[212].mFileTimeHi = 0U;
  c20_info[213].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m";
  c20_info[213].name = "eml_scalar_eg";
  c20_info[213].dominantType = "double";
  c20_info[213].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c20_info[213].fileTimeLo = 1286851196U;
  c20_info[213].fileTimeHi = 0U;
  c20_info[213].mFileTimeLo = 0U;
  c20_info[213].mFileTimeHi = 0U;
  c20_info[214].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m";
  c20_info[214].name = "eml_refblas_xaxpy";
  c20_info[214].dominantType = "double";
  c20_info[214].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c20_info[214].fileTimeLo = 1299109172U;
  c20_info[214].fileTimeHi = 0U;
  c20_info[214].mFileTimeLo = 0U;
  c20_info[214].mFileTimeHi = 0U;
  c20_info[215].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c20_info[215].name = "eml_index_class";
  c20_info[215].dominantType = "";
  c20_info[215].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[215].fileTimeLo = 1323202978U;
  c20_info[215].fileTimeHi = 0U;
  c20_info[215].mFileTimeLo = 0U;
  c20_info[215].mFileTimeHi = 0U;
  c20_info[216].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c20_info[216].name = "eml_isa_uint";
  c20_info[216].dominantType = "coder.internal.indexInt";
  c20_info[216].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c20_info[216].fileTimeLo = 1286851184U;
  c20_info[216].fileTimeHi = 0U;
  c20_info[216].mFileTimeLo = 0U;
  c20_info[216].mFileTimeHi = 0U;
  c20_info[217].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c20_info[217].name = "eml_index_minus";
  c20_info[217].dominantType = "double";
  c20_info[217].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c20_info[217].fileTimeLo = 1286851178U;
  c20_info[217].fileTimeHi = 0U;
  c20_info[217].mFileTimeLo = 0U;
  c20_info[217].mFileTimeHi = 0U;
  c20_info[218].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c20_info[218].name = "eml_int_forloop_overflow_check";
  c20_info[218].dominantType = "";
  c20_info[218].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c20_info[218].fileTimeLo = 1346542740U;
  c20_info[218].fileTimeHi = 0U;
  c20_info[218].mFileTimeLo = 0U;
  c20_info[218].mFileTimeHi = 0U;
  c20_info[219].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c20_info[219].name = "eml_index_plus";
  c20_info[219].dominantType = "double";
  c20_info[219].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c20_info[219].fileTimeLo = 1286851178U;
  c20_info[219].fileTimeHi = 0U;
  c20_info[219].mFileTimeLo = 0U;
  c20_info[219].mFileTimeHi = 0U;
  c20_info[220].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xaxpy.m";
  c20_info[220].name = "eml_index_plus";
  c20_info[220].dominantType = "coder.internal.indexInt";
  c20_info[220].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c20_info[220].fileTimeLo = 1286851178U;
  c20_info[220].fileTimeHi = 0U;
  c20_info[220].mFileTimeLo = 0U;
  c20_info[220].mFileTimeHi = 0U;
  c20_info[221].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c20_info[221].name = "abs";
  c20_info[221].dominantType = "double";
  c20_info[221].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c20_info[221].fileTimeLo = 1343862766U;
  c20_info[221].fileTimeHi = 0U;
  c20_info[221].mFileTimeLo = 0U;
  c20_info[221].mFileTimeHi = 0U;
  c20_info[222].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c20_info[222].name = "mtimes";
  c20_info[222].dominantType = "double";
  c20_info[222].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[222].fileTimeLo = 1289552092U;
  c20_info[222].fileTimeHi = 0U;
  c20_info[222].mFileTimeLo = 0U;
  c20_info[222].mFileTimeHi = 0U;
  c20_info[223].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c20_info[223].name = "realmin";
  c20_info[223].dominantType = "char";
  c20_info[223].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c20_info[223].fileTimeLo = 1307683642U;
  c20_info[223].fileTimeHi = 0U;
  c20_info[223].mFileTimeLo = 0U;
  c20_info[223].mFileTimeHi = 0U;
  c20_info[224].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c20_info[224].name = "eps";
  c20_info[224].dominantType = "char";
  c20_info[224].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c20_info[224].fileTimeLo = 1326760396U;
  c20_info[224].fileTimeHi = 0U;
  c20_info[224].mFileTimeLo = 0U;
  c20_info[224].mFileTimeHi = 0U;
  c20_info[225].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c20_info[225].name = "eml_error";
  c20_info[225].dominantType = "char";
  c20_info[225].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c20_info[225].fileTimeLo = 1343862758U;
  c20_info[225].fileTimeHi = 0U;
  c20_info[225].mFileTimeLo = 0U;
  c20_info[225].mFileTimeHi = 0U;
  c20_info[226].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c20_info[226].name = "eml_const_nonsingleton_dim";
  c20_info[226].dominantType = "double";
  c20_info[226].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c20_info[226].fileTimeLo = 1286851096U;
  c20_info[226].fileTimeHi = 0U;
  c20_info[226].mFileTimeLo = 0U;
  c20_info[226].mFileTimeHi = 0U;
  c20_info[227].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c20_info[227].name = "eml_scalar_eg";
  c20_info[227].dominantType = "double";
  c20_info[227].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c20_info[227].fileTimeLo = 1286851196U;
  c20_info[227].fileTimeHi = 0U;
  c20_info[227].mFileTimeLo = 0U;
  c20_info[227].mFileTimeHi = 0U;
  c20_info[228].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  c20_info[228].name = "eml_index_class";
  c20_info[228].dominantType = "";
  c20_info[228].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[228].fileTimeLo = 1323202978U;
  c20_info[228].fileTimeHi = 0U;
  c20_info[228].mFileTimeLo = 0U;
  c20_info[228].mFileTimeHi = 0U;
  c20_info[229].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c20_info[229].name = "eml_index_class";
  c20_info[229].dominantType = "";
  c20_info[229].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[229].fileTimeLo = 1323202978U;
  c20_info[229].fileTimeHi = 0U;
  c20_info[229].mFileTimeLo = 0U;
  c20_info[229].mFileTimeHi = 0U;
  c20_info[230].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c20_info[230].name = "isnan";
  c20_info[230].dominantType = "double";
  c20_info[230].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c20_info[230].fileTimeLo = 1286851160U;
  c20_info[230].fileTimeHi = 0U;
  c20_info[230].mFileTimeLo = 0U;
  c20_info[230].mFileTimeHi = 0U;
  c20_info[231].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c20_info[231].name = "eml_index_plus";
  c20_info[231].dominantType = "coder.internal.indexInt";
  c20_info[231].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c20_info[231].fileTimeLo = 1286851178U;
  c20_info[231].fileTimeHi = 0U;
  c20_info[231].mFileTimeLo = 0U;
  c20_info[231].mFileTimeHi = 0U;
  c20_info[232].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c20_info[232].name = "eml_int_forloop_overflow_check";
  c20_info[232].dominantType = "";
  c20_info[232].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c20_info[232].fileTimeLo = 1346542740U;
  c20_info[232].fileTimeHi = 0U;
  c20_info[232].mFileTimeLo = 0U;
  c20_info[232].mFileTimeHi = 0U;
  c20_info[233].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  c20_info[233].name = "eml_relop";
  c20_info[233].dominantType = "function_handle";
  c20_info[233].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c20_info[233].fileTimeLo = 1342483582U;
  c20_info[233].fileTimeHi = 0U;
  c20_info[233].mFileTimeLo = 0U;
  c20_info[233].mFileTimeHi = 0U;
  c20_info[234].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c20_info[234].name = "sqrt";
  c20_info[234].dominantType = "double";
  c20_info[234].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c20_info[234].fileTimeLo = 1343862786U;
  c20_info[234].fileTimeHi = 0U;
  c20_info[234].mFileTimeLo = 0U;
  c20_info[234].mFileTimeHi = 0U;
  c20_info[235].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c20_info[235].name = "eml_error";
  c20_info[235].dominantType = "char";
  c20_info[235].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c20_info[235].fileTimeLo = 1343862758U;
  c20_info[235].fileTimeHi = 0U;
  c20_info[235].mFileTimeLo = 0U;
  c20_info[235].mFileTimeHi = 0U;
  c20_info[236].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c20_info[236].name = "eml_scalar_sqrt";
  c20_info[236].dominantType = "double";
  c20_info[236].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c20_info[236].fileTimeLo = 1286851138U;
  c20_info[236].fileTimeHi = 0U;
  c20_info[236].mFileTimeLo = 0U;
  c20_info[236].mFileTimeHi = 0U;
  c20_info[237].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c20_info[237].name = "eml_xrotg";
  c20_info[237].dominantType = "double";
  c20_info[237].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m";
  c20_info[237].fileTimeLo = 1299109176U;
  c20_info[237].fileTimeHi = 0U;
  c20_info[237].mFileTimeLo = 0U;
  c20_info[237].mFileTimeHi = 0U;
  c20_info[238].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrotg.m";
  c20_info[238].name = "eml_blas_inline";
  c20_info[238].dominantType = "";
  c20_info[238].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c20_info[238].fileTimeLo = 1299109168U;
  c20_info[238].fileTimeHi = 0U;
  c20_info[238].mFileTimeLo = 0U;
  c20_info[238].mFileTimeHi = 0U;
  c20_info[239].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m";
  c20_info[239].name = "eml_refblas_xrotg";
  c20_info[239].dominantType = "double";
  c20_info[239].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c20_info[239].fileTimeLo = 1299109184U;
  c20_info[239].fileTimeHi = 0U;
  c20_info[239].mFileTimeLo = 0U;
  c20_info[239].mFileTimeHi = 0U;
  c20_info[240].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c20_info[240].name = "abs";
  c20_info[240].dominantType = "double";
  c20_info[240].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c20_info[240].fileTimeLo = 1343862766U;
  c20_info[240].fileTimeHi = 0U;
  c20_info[240].mFileTimeLo = 0U;
  c20_info[240].mFileTimeHi = 0U;
  c20_info[241].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c20_info[241].name = "mrdivide";
  c20_info[241].dominantType = "double";
  c20_info[241].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c20_info[241].fileTimeLo = 1357983948U;
  c20_info[241].fileTimeHi = 0U;
  c20_info[241].mFileTimeLo = 1319762366U;
  c20_info[241].mFileTimeHi = 0U;
  c20_info[242].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrotg.m";
  c20_info[242].name = "sqrt";
  c20_info[242].dominantType = "double";
  c20_info[242].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c20_info[242].fileTimeLo = 1343862786U;
  c20_info[242].fileTimeHi = 0U;
  c20_info[242].mFileTimeLo = 0U;
  c20_info[242].mFileTimeHi = 0U;
  c20_info[243].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrotg.m!eml_ceval_xrotg";
  c20_info[243].name = "eml_scalar_eg";
  c20_info[243].dominantType = "double";
  c20_info[243].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c20_info[243].fileTimeLo = 1286851196U;
  c20_info[243].fileTimeHi = 0U;
  c20_info[243].mFileTimeLo = 0U;
  c20_info[243].mFileTimeHi = 0U;
  c20_info[244].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c20_info[244].name = "eml_xrot";
  c20_info[244].dominantType = "double";
  c20_info[244].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrot.m";
  c20_info[244].fileTimeLo = 1299109176U;
  c20_info[244].fileTimeHi = 0U;
  c20_info[244].mFileTimeLo = 0U;
  c20_info[244].mFileTimeHi = 0U;
  c20_info[245].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xrot.m";
  c20_info[245].name = "eml_blas_inline";
  c20_info[245].dominantType = "";
  c20_info[245].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c20_info[245].fileTimeLo = 1299109168U;
  c20_info[245].fileTimeHi = 0U;
  c20_info[245].mFileTimeLo = 0U;
  c20_info[245].mFileTimeHi = 0U;
  c20_info[246].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m";
  c20_info[246].name = "eml_index_class";
  c20_info[246].dominantType = "";
  c20_info[246].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[246].fileTimeLo = 1323202978U;
  c20_info[246].fileTimeHi = 0U;
  c20_info[246].mFileTimeLo = 0U;
  c20_info[246].mFileTimeHi = 0U;
  c20_info[247].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m";
  c20_info[247].name = "eml_scalar_eg";
  c20_info[247].dominantType = "double";
  c20_info[247].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c20_info[247].fileTimeLo = 1286851196U;
  c20_info[247].fileTimeHi = 0U;
  c20_info[247].mFileTimeLo = 0U;
  c20_info[247].mFileTimeHi = 0U;
  c20_info[248].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xrot.m";
  c20_info[248].name = "eml_refblas_xrot";
  c20_info[248].dominantType = "double";
  c20_info[248].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  c20_info[248].fileTimeLo = 1299109184U;
  c20_info[248].fileTimeHi = 0U;
  c20_info[248].mFileTimeLo = 0U;
  c20_info[248].mFileTimeHi = 0U;
  c20_info[249].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  c20_info[249].name = "eml_index_class";
  c20_info[249].dominantType = "";
  c20_info[249].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[249].fileTimeLo = 1323202978U;
  c20_info[249].fileTimeHi = 0U;
  c20_info[249].mFileTimeLo = 0U;
  c20_info[249].mFileTimeHi = 0U;
  c20_info[250].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  c20_info[250].name = "eml_int_forloop_overflow_check";
  c20_info[250].dominantType = "";
  c20_info[250].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c20_info[250].fileTimeLo = 1346542740U;
  c20_info[250].fileTimeHi = 0U;
  c20_info[250].mFileTimeLo = 0U;
  c20_info[250].mFileTimeHi = 0U;
  c20_info[251].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  c20_info[251].name = "mtimes";
  c20_info[251].dominantType = "double";
  c20_info[251].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[251].fileTimeLo = 1289552092U;
  c20_info[251].fileTimeHi = 0U;
  c20_info[251].mFileTimeLo = 0U;
  c20_info[251].mFileTimeHi = 0U;
  c20_info[252].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xrot.m";
  c20_info[252].name = "eml_index_plus";
  c20_info[252].dominantType = "coder.internal.indexInt";
  c20_info[252].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c20_info[252].fileTimeLo = 1286851178U;
  c20_info[252].fileTimeHi = 0U;
  c20_info[252].mFileTimeLo = 0U;
  c20_info[252].mFileTimeHi = 0U;
  c20_info[253].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zsvdc.m";
  c20_info[253].name = "eml_xswap";
  c20_info[253].dominantType = "double";
  c20_info[253].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c20_info[253].fileTimeLo = 1299109178U;
  c20_info[253].fileTimeHi = 0U;
  c20_info[253].mFileTimeLo = 0U;
  c20_info[253].mFileTimeHi = 0U;
  c20_info[254].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c20_info[254].name = "mtimes";
  c20_info[254].dominantType = "double";
  c20_info[254].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[254].fileTimeLo = 1289552092U;
  c20_info[254].fileTimeHi = 0U;
  c20_info[254].mFileTimeLo = 0U;
  c20_info[254].mFileTimeHi = 0U;
  c20_info[255].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c20_info[255].name = "eps";
  c20_info[255].dominantType = "char";
  c20_info[255].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c20_info[255].fileTimeLo = 1326760396U;
  c20_info[255].fileTimeHi = 0U;
  c20_info[255].mFileTimeLo = 0U;
  c20_info[255].mFileTimeHi = 0U;
}

static void c20_e_info_helper(c20_ResolvedFunctionInfo c20_info[281])
{
  c20_info[256].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c20_info[256].name = "eml_int_forloop_overflow_check";
  c20_info[256].dominantType = "";
  c20_info[256].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c20_info[256].fileTimeLo = 1346542740U;
  c20_info[256].fileTimeHi = 0U;
  c20_info[256].mFileTimeLo = 0U;
  c20_info[256].mFileTimeHi = 0U;
  c20_info[257].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c20_info[257].name = "eml_index_plus";
  c20_info[257].dominantType = "double";
  c20_info[257].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c20_info[257].fileTimeLo = 1286851178U;
  c20_info[257].fileTimeHi = 0U;
  c20_info[257].mFileTimeLo = 0U;
  c20_info[257].mFileTimeHi = 0U;
  c20_info[258].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c20_info[258].name = "eml_div";
  c20_info[258].dominantType = "double";
  c20_info[258].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c20_info[258].fileTimeLo = 1313380210U;
  c20_info[258].fileTimeHi = 0U;
  c20_info[258].mFileTimeLo = 0U;
  c20_info[258].mFileTimeHi = 0U;
  c20_info[259].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c20_info[259].name = "eml_xscal";
  c20_info[259].dominantType = "double";
  c20_info[259].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xscal.m";
  c20_info[259].fileTimeLo = 1299109176U;
  c20_info[259].fileTimeHi = 0U;
  c20_info[259].mFileTimeLo = 0U;
  c20_info[259].mFileTimeHi = 0U;
  c20_info[260].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c20_info[260].name = "eml_index_plus";
  c20_info[260].dominantType = "coder.internal.indexInt";
  c20_info[260].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c20_info[260].fileTimeLo = 1286851178U;
  c20_info[260].fileTimeHi = 0U;
  c20_info[260].mFileTimeLo = 0U;
  c20_info[260].mFileTimeHi = 0U;
  c20_info[261].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/pinv.m!eml_pinv";
  c20_info[261].name = "eml_xgemm";
  c20_info[261].dominantType = "char";
  c20_info[261].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c20_info[261].fileTimeLo = 1299109172U;
  c20_info[261].fileTimeHi = 0U;
  c20_info[261].mFileTimeLo = 0U;
  c20_info[261].mFileTimeHi = 0U;
  c20_info[262].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c20_info[262].name = "min";
  c20_info[262].dominantType = "double";
  c20_info[262].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c20_info[262].fileTimeLo = 1311287718U;
  c20_info[262].fileTimeHi = 0U;
  c20_info[262].mFileTimeLo = 0U;
  c20_info[262].mFileTimeHi = 0U;
  c20_info[263].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c20_info[263].name = "eml_index_minus";
  c20_info[263].dominantType = "double";
  c20_info[263].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c20_info[263].fileTimeLo = 1286851178U;
  c20_info[263].fileTimeHi = 0U;
  c20_info[263].mFileTimeLo = 0U;
  c20_info[263].mFileTimeHi = 0U;
  c20_info[264].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c20_info[264].name = "eml_index_class";
  c20_info[264].dominantType = "";
  c20_info[264].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[264].fileTimeLo = 1323202978U;
  c20_info[264].fileTimeHi = 0U;
  c20_info[264].mFileTimeLo = 0U;
  c20_info[264].mFileTimeHi = 0U;
  c20_info[265].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c20_info[265].name = "eml_scalar_eg";
  c20_info[265].dominantType = "double";
  c20_info[265].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c20_info[265].fileTimeLo = 1286851196U;
  c20_info[265].fileTimeHi = 0U;
  c20_info[265].mFileTimeLo = 0U;
  c20_info[265].mFileTimeHi = 0U;
  c20_info[266].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c20_info[266].name = "eml_index_times";
  c20_info[266].dominantType = "coder.internal.indexInt";
  c20_info[266].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c20_info[266].fileTimeLo = 1286851180U;
  c20_info[266].fileTimeHi = 0U;
  c20_info[266].mFileTimeLo = 0U;
  c20_info[266].mFileTimeHi = 0U;
  c20_info[267].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c20_info[267].name = "eml_index_plus";
  c20_info[267].dominantType = "coder.internal.indexInt";
  c20_info[267].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c20_info[267].fileTimeLo = 1286851178U;
  c20_info[267].fileTimeHi = 0U;
  c20_info[267].mFileTimeLo = 0U;
  c20_info[267].mFileTimeHi = 0U;
  c20_info[268].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c20_info[268].name = "eml_int_forloop_overflow_check";
  c20_info[268].dominantType = "";
  c20_info[268].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c20_info[268].fileTimeLo = 1346542740U;
  c20_info[268].fileTimeHi = 0U;
  c20_info[268].mFileTimeLo = 0U;
  c20_info[268].mFileTimeHi = 0U;
  c20_info[269].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c20_info[269].name = "eml_index_plus";
  c20_info[269].dominantType = "double";
  c20_info[269].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c20_info[269].fileTimeLo = 1286851178U;
  c20_info[269].fileTimeHi = 0U;
  c20_info[269].mFileTimeLo = 0U;
  c20_info[269].mFileTimeHi = 0U;
  c20_info[270].context = "";
  c20_info[270].name = "svd";
  c20_info[270].dominantType = "double";
  c20_info[270].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/svd.m";
  c20_info[270].fileTimeLo = 1286851232U;
  c20_info[270].fileTimeHi = 0U;
  c20_info[270].mFileTimeLo = 0U;
  c20_info[270].mFileTimeHi = 0U;
  c20_info[271].context = "";
  c20_info[271].name = "eye";
  c20_info[271].dominantType = "double";
  c20_info[271].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c20_info[271].fileTimeLo = 1286851088U;
  c20_info[271].fileTimeHi = 0U;
  c20_info[271].mFileTimeLo = 0U;
  c20_info[271].mFileTimeHi = 0U;
  c20_info[272].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c20_info[272].name = "eml_assert_valid_size_arg";
  c20_info[272].dominantType = "double";
  c20_info[272].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c20_info[272].fileTimeLo = 1286851094U;
  c20_info[272].fileTimeHi = 0U;
  c20_info[272].mFileTimeLo = 0U;
  c20_info[272].mFileTimeHi = 0U;
  c20_info[273].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c20_info[273].name = "isinf";
  c20_info[273].dominantType = "double";
  c20_info[273].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c20_info[273].fileTimeLo = 1286851160U;
  c20_info[273].fileTimeHi = 0U;
  c20_info[273].mFileTimeLo = 0U;
  c20_info[273].mFileTimeHi = 0U;
  c20_info[274].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c20_info[274].name = "mtimes";
  c20_info[274].dominantType = "double";
  c20_info[274].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[274].fileTimeLo = 1289552092U;
  c20_info[274].fileTimeHi = 0U;
  c20_info[274].mFileTimeLo = 0U;
  c20_info[274].mFileTimeHi = 0U;
  c20_info[275].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c20_info[275].name = "eml_index_class";
  c20_info[275].dominantType = "";
  c20_info[275].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[275].fileTimeLo = 1323202978U;
  c20_info[275].fileTimeHi = 0U;
  c20_info[275].mFileTimeLo = 0U;
  c20_info[275].mFileTimeHi = 0U;
  c20_info[276].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c20_info[276].name = "intmax";
  c20_info[276].dominantType = "char";
  c20_info[276].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c20_info[276].fileTimeLo = 1311287716U;
  c20_info[276].fileTimeHi = 0U;
  c20_info[276].mFileTimeLo = 0U;
  c20_info[276].mFileTimeHi = 0U;
  c20_info[277].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c20_info[277].name = "eml_is_float_class";
  c20_info[277].dominantType = "char";
  c20_info[277].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c20_info[277].fileTimeLo = 1286851182U;
  c20_info[277].fileTimeHi = 0U;
  c20_info[277].mFileTimeLo = 0U;
  c20_info[277].mFileTimeHi = 0U;
  c20_info[278].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c20_info[278].name = "min";
  c20_info[278].dominantType = "double";
  c20_info[278].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c20_info[278].fileTimeLo = 1311287718U;
  c20_info[278].fileTimeHi = 0U;
  c20_info[278].mFileTimeLo = 0U;
  c20_info[278].mFileTimeHi = 0U;
  c20_info[279].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c20_info[279].name = "eml_index_class";
  c20_info[279].dominantType = "";
  c20_info[279].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[279].fileTimeLo = 1323202978U;
  c20_info[279].fileTimeHi = 0U;
  c20_info[279].mFileTimeLo = 0U;
  c20_info[279].mFileTimeHi = 0U;
  c20_info[280].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c20_info[280].name = "eml_int_forloop_overflow_check";
  c20_info[280].dominantType = "";
  c20_info[280].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c20_info[280].fileTimeLo = 1346542740U;
  c20_info[280].fileTimeHi = 0U;
  c20_info[280].mFileTimeLo = 0U;
  c20_info[280].mFileTimeHi = 0U;
}

static real_T c20_eml_div(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x, real_T c20_y)
{
  return c20_x / c20_y;
}

static real_T c20_mpower(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_a)
{
  real_T c20_b_a;
  real_T c20_c_a;
  real_T c20_ak;
  real_T c20_d_a;
  real_T c20_e_a;
  real_T c20_b;
  c20_b_a = c20_a;
  c20_c_a = c20_b_a;
  c20_eml_scalar_eg(chartInstance);
  c20_ak = c20_c_a;
  c20_d_a = c20_ak;
  c20_eml_scalar_eg(chartInstance);
  c20_e_a = c20_d_a;
  c20_b = c20_d_a;
  return c20_e_a * c20_b;
}

static void c20_eml_scalar_eg(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
}

static void c20_inv(SFc20_CusakisME4901arcsInstanceStruct *chartInstance, real_T
                    c20_x[36], real_T c20_y[36])
{
  int32_T c20_i152;
  real_T c20_b_x[36];
  int32_T c20_i153;
  real_T c20_c_x[36];
  real_T c20_n1x;
  int32_T c20_i154;
  real_T c20_b_y[36];
  real_T c20_n1xinv;
  real_T c20_a;
  real_T c20_b;
  real_T c20_c_y;
  real_T c20_rc;
  real_T c20_d_x;
  boolean_T c20_b_b;
  real_T c20_e_x;
  int32_T c20_i155;
  static char_T c20_cv0[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c20_u[8];
  const mxArray *c20_d_y = NULL;
  real_T c20_b_u;
  const mxArray *c20_e_y = NULL;
  real_T c20_c_u;
  const mxArray *c20_f_y = NULL;
  real_T c20_d_u;
  const mxArray *c20_g_y = NULL;
  char_T c20_str[14];
  int32_T c20_i156;
  char_T c20_b_str[14];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  for (c20_i152 = 0; c20_i152 < 36; c20_i152++) {
    c20_b_x[c20_i152] = c20_x[c20_i152];
  }

  c20_invNxN(chartInstance, c20_b_x, c20_y);
  for (c20_i153 = 0; c20_i153 < 36; c20_i153++) {
    c20_c_x[c20_i153] = c20_x[c20_i153];
  }

  c20_n1x = c20_norm(chartInstance, c20_c_x);
  for (c20_i154 = 0; c20_i154 < 36; c20_i154++) {
    c20_b_y[c20_i154] = c20_y[c20_i154];
  }

  c20_n1xinv = c20_norm(chartInstance, c20_b_y);
  c20_a = c20_n1x;
  c20_b = c20_n1xinv;
  c20_c_y = c20_a * c20_b;
  c20_rc = 1.0 / c20_c_y;
  guard1 = FALSE;
  guard2 = FALSE;
  if (c20_n1x == 0.0) {
    guard2 = TRUE;
  } else if (c20_n1xinv == 0.0) {
    guard2 = TRUE;
  } else if (c20_rc == 0.0) {
    guard1 = TRUE;
  } else {
    c20_d_x = c20_rc;
    c20_b_b = muDoubleScalarIsNaN(c20_d_x);
    guard3 = FALSE;
    if (c20_b_b) {
      guard3 = TRUE;
    } else {
      c20_eps(chartInstance);
      if (c20_rc < 2.2204460492503131E-16) {
        guard3 = TRUE;
      }
    }

    if (guard3 == TRUE) {
      c20_e_x = c20_rc;
      for (c20_i155 = 0; c20_i155 < 8; c20_i155++) {
        c20_u[c20_i155] = c20_cv0[c20_i155];
      }

      c20_d_y = NULL;
      sf_mex_assign(&c20_d_y, sf_mex_create("y", c20_u, 10, 0U, 1U, 0U, 2, 1, 8),
                    FALSE);
      c20_b_u = 14.0;
      c20_e_y = NULL;
      sf_mex_assign(&c20_e_y, sf_mex_create("y", &c20_b_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c20_c_u = 6.0;
      c20_f_y = NULL;
      sf_mex_assign(&c20_f_y, sf_mex_create("y", &c20_c_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c20_d_u = c20_e_x;
      c20_g_y = NULL;
      sf_mex_assign(&c20_g_y, sf_mex_create("y", &c20_d_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c20_j_emlrt_marshallIn(chartInstance, sf_mex_call_debug("sprintf", 1U, 2U,
        14, sf_mex_call_debug("sprintf", 1U, 3U, 14, c20_d_y, 14, c20_e_y, 14,
        c20_f_y), 14, c20_g_y), "sprintf", c20_str);
      for (c20_i156 = 0; c20_i156 < 14; c20_i156++) {
        c20_b_str[c20_i156] = c20_str[c20_i156];
      }

      c20_b_eml_warning(chartInstance, c20_b_str);
    }
  }

  if (guard2 == TRUE) {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    c20_eml_warning(chartInstance);
  }
}

static void c20_invNxN(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[36], real_T c20_y[36])
{
  int32_T c20_i157;
  int32_T c20_info;
  int32_T c20_ipiv[6];
  int32_T c20_i158;
  int32_T c20_p[6];
  int32_T c20_k;
  real_T c20_b_k;
  int32_T c20_ipk;
  int32_T c20_a;
  real_T c20_b;
  int32_T c20_b_a;
  real_T c20_b_b;
  int32_T c20_idx;
  real_T c20_flt;
  boolean_T c20_b_p;
  int32_T c20_pipk;
  int32_T c20_c_k;
  int32_T c20_d_k;
  int32_T c20_c;
  int32_T c20_e_k;
  boolean_T c20_overflow;
  int32_T c20_j;
  int32_T c20_b_j;
  int32_T c20_c_a;
  int32_T c20_i159;
  boolean_T c20_b_overflow;
  int32_T c20_i;
  int32_T c20_b_i;
  real_T c20_d_a;
  real_T c20_c_b;
  real_T c20_b_y;
  int32_T c20_i160;
  real_T c20_b_x[36];
  for (c20_i157 = 0; c20_i157 < 36; c20_i157++) {
    c20_y[c20_i157] = 0.0;
  }

  c20_b_eml_matlab_zgetrf(chartInstance, c20_x, c20_ipiv, &c20_info);
  for (c20_i158 = 0; c20_i158 < 6; c20_i158++) {
    c20_p[c20_i158] = 1 + c20_i158;
  }

  for (c20_k = 0; c20_k < 5; c20_k++) {
    c20_b_k = 1.0 + (real_T)c20_k;
    c20_ipk = c20_ipiv[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c20_b_k), 1, 6, 1, 0) - 1];
    c20_a = c20_ipk;
    c20_b = c20_b_k;
    c20_b_a = c20_a;
    c20_b_b = c20_b;
    c20_idx = c20_b_a;
    c20_flt = c20_b_b;
    c20_b_p = ((real_T)c20_idx > c20_flt);
    if (c20_b_p) {
      c20_pipk = c20_p[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c20_ipk), 1, 6, 1, 0) - 1];
      c20_p[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c20_ipk), 1, 6, 1, 0) - 1] = c20_p[(int32_T)(real_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c20_b_k),
        1, 6, 1, 0) - 1];
      c20_p[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c20_b_k), 1, 6, 1, 0) - 1] = c20_pipk;
    }
  }

  for (c20_c_k = 1; c20_c_k < 7; c20_c_k++) {
    c20_d_k = c20_c_k;
    c20_c = c20_p[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_d_k), 1, 6, 1, 0) - 1];
    c20_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c20_d_k), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_c), 1, 6, 2, 0) - 1)) -
      1] = 1.0;
    c20_e_k = c20_d_k;
    c20_overflow = FALSE;
    if (c20_overflow) {
      c20_check_forloop_overflow_error(chartInstance, c20_overflow);
    }

    for (c20_j = c20_e_k; c20_j < 7; c20_j++) {
      c20_b_j = c20_j;
      if (c20_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c20_b_j), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_c), 1, 6, 2, 0) - 1)) -
          1] != 0.0) {
        c20_c_a = c20_b_j;
        c20_i159 = c20_c_a;
        c20_b_overflow = FALSE;
        if (c20_b_overflow) {
          c20_check_forloop_overflow_error(chartInstance, c20_b_overflow);
        }

        for (c20_i = c20_i159 + 1; c20_i < 7; c20_i++) {
          c20_b_i = c20_i;
          c20_d_a = c20_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_j), 1, 6, 1, 0) + 6 *
                           (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_c), 1, 6, 2, 0) - 1)) - 1];
          c20_c_b = c20_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_i), 1, 6, 1, 0) + 6 *
                           (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_j), 1, 6, 2, 0) - 1)) - 1];
          c20_b_y = c20_d_a * c20_c_b;
          c20_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c20_b_i), 1, 6, 1, 0) + 6 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                    (real_T)c20_c), 1, 6, 2, 0) - 1)) - 1] = c20_y
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c20_b_i), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK
               ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_c), 1, 6, 2, 0)
               - 1)) - 1] - c20_b_y;
        }
      }
    }
  }

  for (c20_i160 = 0; c20_i160 < 36; c20_i160++) {
    c20_b_x[c20_i160] = c20_x[c20_i160];
  }

  c20_b_eml_xtrsm(chartInstance, c20_b_x, c20_y);
}

static void c20_realmin(SFc20_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static void c20_eps(SFc20_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static void c20_eml_matlab_zgetrf(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, real_T c20_A[36], real_T c20_b_A[36], int32_T c20_ipiv[6],
  int32_T *c20_info)
{
  int32_T c20_i161;
  for (c20_i161 = 0; c20_i161 < 36; c20_i161++) {
    c20_b_A[c20_i161] = c20_A[c20_i161];
  }

  c20_b_eml_matlab_zgetrf(chartInstance, c20_b_A, c20_ipiv, c20_info);
}

static real_T c20_abs(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
                      real_T c20_x)
{
  real_T c20_b_x;
  c20_b_x = c20_x;
  return muDoubleScalarAbs(c20_b_x);
}

static void c20_check_forloop_overflow_error
  (SFc20_CusakisME4901arcsInstanceStruct *chartInstance, boolean_T c20_overflow)
{
  int32_T c20_i162;
  static char_T c20_cv1[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c20_u[34];
  const mxArray *c20_y = NULL;
  int32_T c20_i163;
  static char_T c20_cv2[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't', 'e',
    'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  char_T c20_b_u[23];
  const mxArray *c20_b_y = NULL;
  if (!c20_overflow) {
  } else {
    for (c20_i162 = 0; c20_i162 < 34; c20_i162++) {
      c20_u[c20_i162] = c20_cv1[c20_i162];
    }

    c20_y = NULL;
    sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c20_i163 = 0; c20_i163 < 23; c20_i163++) {
      c20_b_u[c20_i163] = c20_cv2[c20_i163];
    }

    c20_b_y = NULL;
    sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_b_u, 10, 0U, 1U, 0U, 2, 1, 23),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c20_y, 14, c20_b_y));
  }
}

static void c20_below_threshold(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
}

static void c20_eml_xger(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_b_m, int32_T c20_n, real_T c20_alpha1, int32_T c20_ix0, int32_T
  c20_iy0, real_T c20_A[36], int32_T c20_ia0, real_T c20_b_A[36])
{
  int32_T c20_i164;
  for (c20_i164 = 0; c20_i164 < 36; c20_i164++) {
    c20_b_A[c20_i164] = c20_A[c20_i164];
  }

  c20_b_eml_xger(chartInstance, c20_b_m, c20_n, c20_alpha1, c20_ix0, c20_iy0,
                 c20_b_A, c20_ia0);
}

static void c20_b_eml_scalar_eg(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
}

static void c20_eml_xtrsm(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_A[36], real_T c20_B[36], real_T c20_b_B[36])
{
  int32_T c20_i165;
  int32_T c20_i166;
  real_T c20_b_A[36];
  for (c20_i165 = 0; c20_i165 < 36; c20_i165++) {
    c20_b_B[c20_i165] = c20_B[c20_i165];
  }

  for (c20_i166 = 0; c20_i166 < 36; c20_i166++) {
    c20_b_A[c20_i166] = c20_A[c20_i166];
  }

  c20_b_eml_xtrsm(chartInstance, c20_b_A, c20_b_B);
}

static real_T c20_norm(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[36])
{
  real_T c20_y;
  int32_T c20_j;
  real_T c20_b_j;
  real_T c20_s;
  int32_T c20_i;
  real_T c20_b_i;
  real_T c20_b_x;
  real_T c20_c_x;
  real_T c20_b_y;
  real_T c20_d_x;
  boolean_T c20_b;
  boolean_T exitg1;
  c20_y = 0.0;
  c20_j = 0;
  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c20_j < 6)) {
    c20_b_j = 1.0 + (real_T)c20_j;
    c20_s = 0.0;
    for (c20_i = 0; c20_i < 6; c20_i++) {
      c20_b_i = 1.0 + (real_T)c20_i;
      c20_b_x = c20_x[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c20_b_i), 1, 6, 1, 0) + 6 * ((int32_T)(real_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c20_b_j),
        1, 6, 2, 0) - 1)) - 1];
      c20_c_x = c20_b_x;
      c20_b_y = muDoubleScalarAbs(c20_c_x);
      c20_s += c20_b_y;
    }

    c20_d_x = c20_s;
    c20_b = muDoubleScalarIsNaN(c20_d_x);
    if (c20_b) {
      c20_y = rtNaN;
      exitg1 = TRUE;
    } else {
      if (c20_s > c20_y) {
        c20_y = c20_s;
      }

      c20_j++;
    }
  }

  return c20_y;
}

static void c20_eml_warning(SFc20_CusakisME4901arcsInstanceStruct *chartInstance)
{
  int32_T c20_i167;
  static char_T c20_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c20_u[27];
  const mxArray *c20_y = NULL;
  for (c20_i167 = 0; c20_i167 < 27; c20_i167++) {
    c20_u[c20_i167] = c20_varargin_1[c20_i167];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 10, 0U, 1U, 0U, 2, 1, 27),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c20_y));
}

static void c20_b_eml_warning(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, char_T c20_varargin_2[14])
{
  int32_T c20_i168;
  static char_T c20_varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c20_u[33];
  const mxArray *c20_y = NULL;
  int32_T c20_i169;
  char_T c20_b_u[14];
  const mxArray *c20_b_y = NULL;
  for (c20_i168 = 0; c20_i168 < 33; c20_i168++) {
    c20_u[c20_i168] = c20_varargin_1[c20_i168];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 10, 0U, 1U, 0U, 2, 1, 33),
                FALSE);
  for (c20_i169 = 0; c20_i169 < 14; c20_i169++) {
    c20_b_u[c20_i169] = c20_varargin_2[c20_i169];
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
    14, c20_y, 14, c20_b_y));
}

static void c20_c_eml_scalar_eg(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
}

static void c20_d_eml_scalar_eg(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
}

static void c20_e_eml_scalar_eg(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
}

static void c20_f_eml_scalar_eg(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
}

static void c20_pinv(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
                     real_T c20_A[18], real_T c20_X[18])
{
  int32_T c20_i170;
  int32_T c20_k;
  int32_T c20_b_k;
  real_T c20_x;
  real_T c20_b_x;
  boolean_T c20_b;
  boolean_T c20_b0;
  real_T c20_c_x;
  boolean_T c20_b_b;
  boolean_T c20_b1;
  boolean_T c20_c_b;
  int32_T c20_i171;
  real_T c20_b_A[18];
  real_T c20_V[9];
  real_T c20_s[3];
  real_T c20_U[18];
  int32_T c20_i172;
  real_T c20_S[9];
  int32_T c20_c_k;
  real_T c20_d_k;
  real_T c20_d_b;
  real_T c20_y;
  real_T c20_a;
  real_T c20_tol;
  int32_T c20_r;
  int32_T c20_e_k;
  int32_T c20_f_k;
  int32_T c20_b_a;
  int32_T c20_vcol;
  int32_T c20_b_r;
  int32_T c20_e_b;
  int32_T c20_f_b;
  boolean_T c20_overflow;
  int32_T c20_j;
  int32_T c20_b_j;
  real_T c20_b_y;
  real_T c20_z;
  int32_T c20_c_a;
  int32_T c20_i173;
  real_T c20_b_V[9];
  int32_T c20_i174;
  real_T c20_b_U[18];
  boolean_T exitg1;
  for (c20_i170 = 0; c20_i170 < 18; c20_i170++) {
    c20_X[c20_i170] = 0.0;
  }

  for (c20_k = 1; c20_k < 19; c20_k++) {
    c20_b_k = c20_k;
    c20_x = c20_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_b_k), 1, 18, 1, 0) - 1];
    c20_b_x = c20_x;
    c20_b = muDoubleScalarIsInf(c20_b_x);
    c20_b0 = !c20_b;
    c20_c_x = c20_x;
    c20_b_b = muDoubleScalarIsNaN(c20_c_x);
    c20_b1 = !c20_b_b;
    c20_c_b = (c20_b0 && c20_b1);
    if (!c20_c_b) {
      c20_eml_error(chartInstance);
    }
  }

  for (c20_i171 = 0; c20_i171 < 18; c20_i171++) {
    c20_b_A[c20_i171] = c20_A[c20_i171];
  }

  c20_eml_xgesvd(chartInstance, c20_b_A, c20_U, c20_s, c20_V);
  for (c20_i172 = 0; c20_i172 < 9; c20_i172++) {
    c20_S[c20_i172] = 0.0;
  }

  for (c20_c_k = 0; c20_c_k < 3; c20_c_k++) {
    c20_d_k = 1.0 + (real_T)c20_c_k;
    c20_S[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c20_d_k), 1, 3, 1, 0) + 3 * ((int32_T)(real_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              c20_d_k), 1, 3, 2, 0) - 1)) - 1] = c20_s[(int32_T)(real_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c20_d_k),
      1, 3, 1, 0) - 1];
  }

  c20_eps(chartInstance);
  c20_d_b = c20_S[0];
  c20_y = 6.0 * c20_d_b;
  c20_a = c20_y;
  c20_tol = c20_a * 2.2204460492503131E-16;
  c20_r = 0;
  c20_e_k = 1;
  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c20_e_k < 4)) {
    c20_f_k = c20_e_k;
    if (!(c20_S[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_f_k), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_f_k), 1, 3, 2, 0) - 1))
          - 1] > c20_tol)) {
      exitg1 = TRUE;
    } else {
      c20_b_a = c20_r + 1;
      c20_r = c20_b_a;
      c20_e_k++;
    }
  }

  if (c20_r > 0) {
    c20_vcol = 1;
    c20_b_r = c20_r;
    c20_e_b = c20_b_r;
    c20_f_b = c20_e_b;
    if (1 > c20_f_b) {
      c20_overflow = FALSE;
    } else {
      c20_overflow = (c20_f_b > 2147483646);
    }

    if (c20_overflow) {
      c20_check_forloop_overflow_error(chartInstance, c20_overflow);
    }

    for (c20_j = 1; c20_j <= c20_b_r; c20_j++) {
      c20_b_j = c20_j;
      c20_b_y = c20_S[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c20_b_j), 1, 3, 1, 0) + 3 *
                       (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c20_b_j), 1, 3, 2, 0) - 1)) - 1];
      c20_z = 1.0 / c20_b_y;
      c20_k_eml_xscal(chartInstance, c20_z, c20_V, c20_vcol);
      c20_c_a = c20_vcol + 3;
      c20_vcol = c20_c_a;
    }

    for (c20_i173 = 0; c20_i173 < 9; c20_i173++) {
      c20_b_V[c20_i173] = c20_V[c20_i173];
    }

    for (c20_i174 = 0; c20_i174 < 18; c20_i174++) {
      c20_b_U[c20_i174] = c20_U[c20_i174];
    }

    c20_c_eml_xgemm(chartInstance, c20_r, c20_b_V, c20_b_U, c20_X);
  }
}

static void c20_eml_error(SFc20_CusakisME4901arcsInstanceStruct *chartInstance)
{
  int32_T c20_i175;
  static char_T c20_cv3[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'v', 'd', '_', 'm', 'a', 't', 'r', 'i', 'x', 'W', 'i',
    't', 'h', 'N', 'a', 'N', 'I', 'n', 'f' };

  char_T c20_u[33];
  const mxArray *c20_y = NULL;
  for (c20_i175 = 0; c20_i175 < 33; c20_i175++) {
    c20_u[c20_i175] = c20_cv3[c20_i175];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 10, 0U, 1U, 0U, 2, 1, 33),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c20_y));
}

static void c20_eml_xgesvd(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_A[18], real_T c20_U[18], real_T c20_S[3], real_T c20_V[9])
{
  int32_T c20_i176;
  real_T c20_b_A[18];
  int32_T c20_i177;
  real_T c20_s[3];
  int32_T c20_i178;
  real_T c20_e[3];
  int32_T c20_i179;
  real_T c20_work[6];
  int32_T c20_i180;
  int32_T c20_i181;
  real_T c20_Vf[9];
  int32_T c20_q;
  int32_T c20_b_q;
  int32_T c20_a;
  int32_T c20_qp1;
  int32_T c20_b_a;
  int32_T c20_qm1;
  int32_T c20_b;
  int32_T c20_c;
  int32_T c20_c_a;
  int32_T c20_b_b;
  int32_T c20_qq;
  int32_T c20_c_b;
  int32_T c20_nmq;
  int32_T c20_d_a;
  int32_T c20_nmqp1;
  int32_T c20_i182;
  real_T c20_c_A[18];
  real_T c20_nrm;
  real_T c20_absx;
  real_T c20_d;
  real_T c20_y;
  real_T c20_d7;
  int32_T c20_b_qp1;
  boolean_T c20_overflow;
  int32_T c20_jj;
  int32_T c20_b_jj;
  int32_T c20_e_a;
  int32_T c20_b_c;
  int32_T c20_d_b;
  int32_T c20_c_c;
  int32_T c20_f_a;
  int32_T c20_e_b;
  int32_T c20_qjj;
  int32_T c20_i183;
  real_T c20_d_A[18];
  int32_T c20_i184;
  real_T c20_e_A[18];
  real_T c20_t;
  int32_T c20_c_q;
  boolean_T c20_b_overflow;
  int32_T c20_ii;
  int32_T c20_b_ii;
  int32_T c20_f_b;
  int32_T c20_pmq;
  int32_T c20_i185;
  real_T c20_b_e[3];
  real_T c20_b_absx;
  real_T c20_b_d;
  real_T c20_b_y;
  real_T c20_d8;
  int32_T c20_c_qp1;
  boolean_T c20_c_overflow;
  int32_T c20_c_ii;
  int32_T c20_d_qp1;
  boolean_T c20_d_overflow;
  int32_T c20_c_jj;
  int32_T c20_g_a;
  int32_T c20_d_c;
  int32_T c20_g_b;
  int32_T c20_e_c;
  int32_T c20_h_a;
  int32_T c20_h_b;
  int32_T c20_qp1jj;
  int32_T c20_i186;
  real_T c20_f_A[18];
  int32_T c20_e_qp1;
  boolean_T c20_e_overflow;
  int32_T c20_d_jj;
  int32_T c20_i_a;
  int32_T c20_f_c;
  int32_T c20_i_b;
  int32_T c20_g_c;
  int32_T c20_j_a;
  int32_T c20_j_b;
  int32_T c20_i187;
  real_T c20_b_work[6];
  int32_T c20_f_qp1;
  boolean_T c20_f_overflow;
  int32_T c20_d_ii;
  int32_T c20_b_m;
  int32_T c20_d_q;
  int32_T c20_k_a;
  int32_T c20_k_b;
  int32_T c20_l_a;
  int32_T c20_m_a;
  int32_T c20_h_c;
  int32_T c20_l_b;
  int32_T c20_i_c;
  int32_T c20_n_a;
  int32_T c20_m_b;
  int32_T c20_g_qp1;
  boolean_T c20_g_overflow;
  int32_T c20_e_jj;
  int32_T c20_o_a;
  int32_T c20_j_c;
  int32_T c20_n_b;
  int32_T c20_k_c;
  int32_T c20_p_a;
  int32_T c20_o_b;
  int32_T c20_i188;
  real_T c20_b_U[18];
  int32_T c20_i189;
  real_T c20_c_U[18];
  int32_T c20_e_q;
  boolean_T c20_h_overflow;
  int32_T c20_e_ii;
  int32_T c20_q_a;
  int32_T c20_i190;
  int32_T c20_p_b;
  int32_T c20_q_b;
  boolean_T c20_i_overflow;
  int32_T c20_f_ii;
  int32_T c20_g_ii;
  int32_T c20_f_q;
  int32_T c20_r_a;
  int32_T c20_r_b;
  int32_T c20_s_a;
  int32_T c20_l_c;
  int32_T c20_s_b;
  int32_T c20_m_c;
  int32_T c20_t_a;
  int32_T c20_t_b;
  int32_T c20_qp1q;
  int32_T c20_h_qp1;
  boolean_T c20_j_overflow;
  int32_T c20_f_jj;
  int32_T c20_u_a;
  int32_T c20_n_c;
  int32_T c20_u_b;
  int32_T c20_o_c;
  int32_T c20_v_a;
  int32_T c20_v_b;
  int32_T c20_i191;
  real_T c20_b_Vf[9];
  int32_T c20_i192;
  real_T c20_c_Vf[9];
  int32_T c20_h_ii;
  int32_T c20_g_q;
  real_T c20_rt;
  real_T c20_r;
  int32_T c20_w_a;
  int32_T c20_p_c;
  int32_T c20_w_b;
  int32_T c20_q_c;
  int32_T c20_x_b;
  int32_T c20_colq;
  int32_T c20_x_a;
  int32_T c20_r_c;
  int32_T c20_y_a;
  int32_T c20_s_c;
  real_T c20_ab_a;
  real_T c20_y_b;
  real_T c20_c_y;
  int32_T c20_ab_b;
  int32_T c20_t_c;
  int32_T c20_bb_b;
  int32_T c20_colqp1;
  real_T c20_iter;
  real_T c20_tiny;
  real_T c20_snorm;
  int32_T c20_i_ii;
  real_T c20_varargin_1;
  real_T c20_varargin_2;
  real_T c20_b_varargin_2;
  real_T c20_varargin_3;
  real_T c20_x;
  real_T c20_d_y;
  real_T c20_b_x;
  real_T c20_e_y;
  real_T c20_xk;
  real_T c20_yk;
  real_T c20_c_x;
  real_T c20_f_y;
  real_T c20_maxval;
  real_T c20_b_varargin_1;
  real_T c20_c_varargin_2;
  real_T c20_d_varargin_2;
  real_T c20_b_varargin_3;
  real_T c20_d_x;
  real_T c20_g_y;
  real_T c20_e_x;
  real_T c20_h_y;
  real_T c20_b_xk;
  real_T c20_b_yk;
  real_T c20_f_x;
  real_T c20_i_y;
  int32_T c20_bb_a;
  int32_T c20_cb_a;
  int32_T c20_i193;
  boolean_T c20_k_overflow;
  int32_T c20_j_ii;
  int32_T c20_db_a;
  int32_T c20_u_c;
  real_T c20_test0;
  real_T c20_ztest0;
  real_T c20_cb_b;
  real_T c20_j_y;
  real_T c20_db_b;
  real_T c20_k_y;
  int32_T c20_eb_a;
  int32_T c20_v_c;
  real_T c20_kase;
  int32_T c20_qs;
  int32_T c20_c_m;
  int32_T c20_h_q;
  int32_T c20_fb_a;
  int32_T c20_eb_b;
  int32_T c20_gb_a;
  int32_T c20_fb_b;
  boolean_T c20_l_overflow;
  int32_T c20_k_ii;
  real_T c20_test;
  int32_T c20_hb_a;
  int32_T c20_w_c;
  int32_T c20_ib_a;
  int32_T c20_x_c;
  real_T c20_ztest;
  real_T c20_gb_b;
  real_T c20_l_y;
  int32_T c20_jb_a;
  int32_T c20_kb_a;
  int32_T c20_y_c;
  real_T c20_f;
  int32_T c20_lb_a;
  int32_T c20_ab_c;
  int32_T c20_mb_a;
  int32_T c20_i194;
  int32_T c20_i_q;
  int32_T c20_nb_a;
  int32_T c20_hb_b;
  int32_T c20_ob_a;
  int32_T c20_ib_b;
  boolean_T c20_m_overflow;
  int32_T c20_k;
  int32_T c20_b_k;
  real_T c20_t1;
  real_T c20_b_t1;
  real_T c20_b_f;
  real_T c20_sn;
  real_T c20_cs;
  real_T c20_b_cs;
  real_T c20_b_sn;
  int32_T c20_pb_a;
  int32_T c20_km1;
  real_T c20_qb_a;
  real_T c20_jb_b;
  real_T c20_rb_a;
  real_T c20_kb_b;
  real_T c20_m_y;
  int32_T c20_sb_a;
  int32_T c20_bb_c;
  int32_T c20_lb_b;
  int32_T c20_cb_c;
  int32_T c20_mb_b;
  int32_T c20_colk;
  int32_T c20_tb_a;
  int32_T c20_db_c;
  int32_T c20_nb_b;
  int32_T c20_eb_c;
  int32_T c20_ob_b;
  int32_T c20_colm;
  int32_T c20_ub_a;
  int32_T c20_j_q;
  int32_T c20_d_m;
  int32_T c20_vb_a;
  int32_T c20_pb_b;
  int32_T c20_wb_a;
  int32_T c20_qb_b;
  boolean_T c20_n_overflow;
  int32_T c20_c_k;
  real_T c20_c_t1;
  real_T c20_unusedU0;
  real_T c20_c_sn;
  real_T c20_c_cs;
  real_T c20_xb_a;
  real_T c20_rb_b;
  real_T c20_yb_a;
  real_T c20_sb_b;
  real_T c20_n_y;
  int32_T c20_ac_a;
  int32_T c20_fb_c;
  int32_T c20_tb_b;
  int32_T c20_gb_c;
  int32_T c20_ub_b;
  int32_T c20_bc_a;
  int32_T c20_hb_c;
  int32_T c20_vb_b;
  int32_T c20_ib_c;
  int32_T c20_wb_b;
  int32_T c20_colqm1;
  int32_T c20_cc_a;
  int32_T c20_mm1;
  real_T c20_d9;
  real_T c20_d10;
  real_T c20_d11;
  real_T c20_d12;
  real_T c20_d13;
  real_T c20_c_varargin_1[5];
  int32_T c20_ixstart;
  real_T c20_mtmp;
  real_T c20_g_x;
  boolean_T c20_xb_b;
  int32_T c20_ix;
  int32_T c20_b_ix;
  real_T c20_h_x;
  boolean_T c20_yb_b;
  int32_T c20_dc_a;
  int32_T c20_i195;
  boolean_T c20_o_overflow;
  int32_T c20_c_ix;
  real_T c20_ec_a;
  real_T c20_ac_b;
  boolean_T c20_p;
  real_T c20_b_mtmp;
  real_T c20_scale;
  real_T c20_sm;
  real_T c20_smm1;
  real_T c20_emm1;
  real_T c20_sqds;
  real_T c20_eqds;
  real_T c20_fc_a;
  real_T c20_bc_b;
  real_T c20_o_y;
  real_T c20_gc_a;
  real_T c20_cc_b;
  real_T c20_p_y;
  real_T c20_dc_b;
  real_T c20_hc_a;
  real_T c20_ec_b;
  real_T c20_jb_c;
  real_T c20_ic_a;
  real_T c20_fc_b;
  real_T c20_shift;
  real_T c20_jc_a;
  real_T c20_gc_b;
  real_T c20_q_y;
  real_T c20_kc_a;
  real_T c20_hc_b;
  real_T c20_r_y;
  real_T c20_lc_a;
  real_T c20_ic_b;
  real_T c20_g;
  int32_T c20_k_q;
  int32_T c20_b_mm1;
  int32_T c20_mc_a;
  int32_T c20_jc_b;
  int32_T c20_nc_a;
  int32_T c20_kc_b;
  boolean_T c20_p_overflow;
  int32_T c20_d_k;
  int32_T c20_oc_a;
  int32_T c20_pc_a;
  int32_T c20_kp1;
  real_T c20_c_f;
  real_T c20_unusedU1;
  real_T c20_d_sn;
  real_T c20_d_cs;
  real_T c20_qc_a;
  real_T c20_lc_b;
  real_T c20_s_y;
  real_T c20_rc_a;
  real_T c20_mc_b;
  real_T c20_t_y;
  real_T c20_sc_a;
  real_T c20_nc_b;
  real_T c20_u_y;
  real_T c20_tc_a;
  real_T c20_oc_b;
  real_T c20_v_y;
  real_T c20_uc_a;
  real_T c20_pc_b;
  real_T c20_vc_a;
  real_T c20_qc_b;
  real_T c20_w_y;
  int32_T c20_wc_a;
  int32_T c20_kb_c;
  int32_T c20_rc_b;
  int32_T c20_lb_c;
  int32_T c20_sc_b;
  int32_T c20_tc_b;
  int32_T c20_mb_c;
  int32_T c20_uc_b;
  int32_T c20_colkp1;
  real_T c20_d_f;
  real_T c20_unusedU2;
  real_T c20_e_sn;
  real_T c20_e_cs;
  real_T c20_xc_a;
  real_T c20_vc_b;
  real_T c20_x_y;
  real_T c20_yc_a;
  real_T c20_wc_b;
  real_T c20_y_y;
  real_T c20_ad_a;
  real_T c20_xc_b;
  real_T c20_ab_y;
  real_T c20_bd_a;
  real_T c20_yc_b;
  real_T c20_bb_y;
  real_T c20_cd_a;
  real_T c20_ad_b;
  real_T c20_dd_a;
  real_T c20_bd_b;
  real_T c20_cb_y;
  int32_T c20_ed_a;
  int32_T c20_nb_c;
  int32_T c20_cd_b;
  int32_T c20_ob_c;
  int32_T c20_dd_b;
  int32_T c20_ed_b;
  int32_T c20_pb_c;
  int32_T c20_fd_b;
  int32_T c20_fd_a;
  int32_T c20_qb_c;
  int32_T c20_e_k;
  int32_T c20_j;
  int32_T c20_b_j;
  int32_T c20_i;
  int32_T c20_b_i;
  int32_T c20_rb_c;
  int32_T c20_gd_a;
  int32_T c20_sb_c;
  int32_T c20_gd_b;
  int32_T c20_hd_b;
  int32_T c20_hd_a;
  int32_T c20_id_a;
  int32_T c20_tb_c;
  int32_T c20_jd_a;
  int32_T c20_ub_c;
  int32_T c20_id_b;
  int32_T c20_jd_b;
  int32_T c20_vb_c;
  int32_T c20_kd_b;
  int32_T c20_ld_b;
  int32_T c20_wb_c;
  int32_T c20_kd_a;
  int32_T c20_xb_c;
  int32_T c20_md_b;
  int32_T c20_nd_b;
  int32_T c20_yb_c;
  int32_T c20_od_b;
  int32_T c20_pd_b;
  int32_T c20_ld_a;
  real_T c20_d14;
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
  for (c20_i176 = 0; c20_i176 < 18; c20_i176++) {
    c20_b_A[c20_i176] = c20_A[c20_i176];
  }

  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i177 = 0; c20_i177 < 3; c20_i177++) {
    c20_s[c20_i177] = 0.0;
  }

  for (c20_i178 = 0; c20_i178 < 3; c20_i178++) {
    c20_e[c20_i178] = 0.0;
  }

  for (c20_i179 = 0; c20_i179 < 6; c20_i179++) {
    c20_work[c20_i179] = 0.0;
  }

  for (c20_i180 = 0; c20_i180 < 18; c20_i180++) {
    c20_U[c20_i180] = 0.0;
  }

  for (c20_i181 = 0; c20_i181 < 9; c20_i181++) {
    c20_Vf[c20_i181] = 0.0;
  }

  for (c20_q = 1; c20_q < 4; c20_q++) {
    c20_b_q = c20_q;
    c20_a = c20_b_q + 1;
    c20_qp1 = c20_a;
    c20_b_a = c20_b_q;
    c20_qm1 = c20_b_a;
    c20_b = c20_qm1 - 1;
    c20_c = 6 * c20_b;
    c20_c_a = c20_b_q;
    c20_b_b = c20_c;
    c20_qq = c20_c_a + c20_b_b;
    c20_c_b = c20_b_q;
    c20_nmq = 6 - c20_c_b;
    c20_d_a = c20_nmq + 1;
    c20_nmqp1 = c20_d_a;
    if (c20_b_q <= 3) {
      for (c20_i182 = 0; c20_i182 < 18; c20_i182++) {
        c20_c_A[c20_i182] = c20_b_A[c20_i182];
      }

      c20_nrm = c20_eml_xnrm2(chartInstance, c20_nmqp1, c20_c_A, c20_qq);
      if (c20_nrm > 0.0) {
        c20_absx = c20_nrm;
        c20_d = c20_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_qq), 1, 18, 1, 0) - 1];
        if (c20_d < 0.0) {
          c20_y = -c20_absx;
        } else {
          c20_y = c20_absx;
        }

        c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 3, 1, 0) - 1] = c20_y;
        c20_d7 = c20_eml_div(chartInstance, 1.0,
                             c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 3, 1, 0) - 1]);
        c20_h_eml_xscal(chartInstance, c20_nmqp1, c20_d7, c20_b_A, c20_qq);
        c20_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_qq), 1, 18, 1, 0) - 1] =
          c20_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_qq), 1, 18, 1, 0) - 1] + 1.0;
        c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 3, 1, 0) - 1] =
          -c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 3, 1, 0) - 1];
      } else {
        c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 3, 1, 0) - 1] = 0.0;
      }
    }

    c20_b_qp1 = c20_qp1;
    c20_overflow = FALSE;
    if (c20_overflow) {
      c20_check_forloop_overflow_error(chartInstance, c20_overflow);
    }

    for (c20_jj = c20_b_qp1; c20_jj < 4; c20_jj++) {
      c20_b_jj = c20_jj;
      c20_e_a = c20_b_jj;
      c20_b_c = c20_e_a;
      c20_d_b = c20_b_c - 1;
      c20_c_c = 6 * c20_d_b;
      c20_f_a = c20_b_q;
      c20_e_b = c20_c_c;
      c20_qjj = c20_f_a + c20_e_b;
      if (c20_b_q <= 3) {
        if (c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c20_b_q), 1, 3, 1, 0) - 1] != 0.0) {
          for (c20_i183 = 0; c20_i183 < 18; c20_i183++) {
            c20_d_A[c20_i183] = c20_b_A[c20_i183];
          }

          for (c20_i184 = 0; c20_i184 < 18; c20_i184++) {
            c20_e_A[c20_i184] = c20_b_A[c20_i184];
          }

          c20_t = c20_eml_xdotc(chartInstance, c20_nmqp1, c20_d_A, c20_qq,
                                c20_e_A, c20_qjj);
          c20_t = -c20_eml_div(chartInstance, c20_t, c20_b_A
                               [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 6, 1, 0) + 6 *
            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_q), 1, 3, 2, 0) - 1)) - 1]);
          c20_h_eml_xaxpy(chartInstance, c20_nmqp1, c20_t, c20_qq, c20_b_A,
                          c20_qjj);
        }
      }

      c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c20_b_jj), 1, 3, 1, 0) - 1] =
        c20_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c20_qjj), 1, 18, 1, 0) - 1];
    }

    if (c20_b_q <= 3) {
      c20_c_q = c20_b_q;
      c20_b_overflow = FALSE;
      if (c20_b_overflow) {
        c20_check_forloop_overflow_error(chartInstance, c20_b_overflow);
      }

      for (c20_ii = c20_c_q; c20_ii < 7; c20_ii++) {
        c20_b_ii = c20_ii;
        c20_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c20_b_ii), 1, 6, 1, 0) + 6 *
               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c20_b_q), 1, 3, 2, 0) - 1)) - 1] = c20_b_A
          [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c20_b_ii), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
              "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 3, 2, 0)
             - 1)) - 1];
      }
    }

    if (c20_b_q <= 1) {
      c20_f_b = c20_b_q;
      c20_pmq = 3 - c20_f_b;
      for (c20_i185 = 0; c20_i185 < 3; c20_i185++) {
        c20_b_e[c20_i185] = c20_e[c20_i185];
      }

      c20_nrm = c20_b_eml_xnrm2(chartInstance, c20_pmq, c20_b_e, c20_qp1);
      if (c20_nrm == 0.0) {
        c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 3, 1, 0) - 1] = 0.0;
      } else {
        c20_b_absx = c20_nrm;
        c20_b_d = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_qp1), 1, 3, 1, 0) - 1];
        if (c20_b_d < 0.0) {
          c20_b_y = -c20_b_absx;
        } else {
          c20_b_y = c20_b_absx;
        }

        c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 3, 1, 0) - 1] = c20_b_y;
        c20_d8 = c20_eml_div(chartInstance, 1.0,
                             c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 3, 1, 0) - 1]);
        c20_i_eml_xscal(chartInstance, c20_pmq, c20_d8, c20_e, c20_qp1);
        c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_qp1), 1, 3, 1, 0) - 1] = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK
          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_qp1), 1, 3, 1, 0) - 1]
          + 1.0;
      }

      c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c20_b_q), 1, 3, 1, 0) - 1] = -c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 3, 1, 0) - 1];
      if (c20_qp1 <= 6) {
        if (c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c20_b_q), 1, 3, 1, 0) - 1] != 0.0) {
          c20_c_qp1 = c20_qp1;
          c20_c_overflow = FALSE;
          if (c20_c_overflow) {
            c20_check_forloop_overflow_error(chartInstance, c20_c_overflow);
          }

          for (c20_c_ii = c20_c_qp1; c20_c_ii < 7; c20_c_ii++) {
            c20_b_ii = c20_c_ii;
            c20_work[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
              ("", (real_T)c20_b_ii), 1, 6, 1, 0) - 1] = 0.0;
          }

          c20_d_qp1 = c20_qp1;
          c20_d_overflow = FALSE;
          if (c20_d_overflow) {
            c20_check_forloop_overflow_error(chartInstance, c20_d_overflow);
          }

          for (c20_c_jj = c20_d_qp1; c20_c_jj < 4; c20_c_jj++) {
            c20_b_jj = c20_c_jj;
            c20_g_a = c20_b_jj;
            c20_d_c = c20_g_a;
            c20_g_b = c20_d_c - 1;
            c20_e_c = 6 * c20_g_b;
            c20_h_a = c20_qp1;
            c20_h_b = c20_e_c;
            c20_qp1jj = c20_h_a + c20_h_b;
            for (c20_i186 = 0; c20_i186 < 18; c20_i186++) {
              c20_f_A[c20_i186] = c20_b_A[c20_i186];
            }

            c20_i_eml_xaxpy(chartInstance, c20_nmq,
                            c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c20_b_jj), 1, 3, 1, 0) - 1],
                            c20_f_A, c20_qp1jj, c20_work, c20_qp1);
          }

          c20_e_qp1 = c20_qp1;
          c20_e_overflow = FALSE;
          if (c20_e_overflow) {
            c20_check_forloop_overflow_error(chartInstance, c20_e_overflow);
          }

          for (c20_d_jj = c20_e_qp1; c20_d_jj < 4; c20_d_jj++) {
            c20_b_jj = c20_d_jj;
            c20_t = c20_eml_div(chartInstance,
                                -c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c20_b_jj), 1, 3, 1, 0) - 1],
                                c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c20_qp1), 1, 3, 1, 0) - 1]);
            c20_i_a = c20_b_jj;
            c20_f_c = c20_i_a;
            c20_i_b = c20_f_c - 1;
            c20_g_c = 6 * c20_i_b;
            c20_j_a = c20_qp1;
            c20_j_b = c20_g_c;
            c20_qp1jj = c20_j_a + c20_j_b;
            for (c20_i187 = 0; c20_i187 < 6; c20_i187++) {
              c20_b_work[c20_i187] = c20_work[c20_i187];
            }

            c20_j_eml_xaxpy(chartInstance, c20_nmq, c20_t, c20_b_work, c20_qp1,
                            c20_b_A, c20_qp1jj);
          }
        }
      }

      c20_f_qp1 = c20_qp1;
      c20_f_overflow = FALSE;
      if (c20_f_overflow) {
        c20_check_forloop_overflow_error(chartInstance, c20_f_overflow);
      }

      for (c20_d_ii = c20_f_qp1; c20_d_ii < 4; c20_d_ii++) {
        c20_b_ii = c20_d_ii;
        c20_Vf[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c20_b_ii), 1, 3, 1, 0) + 3 *
                (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c20_b_q), 1, 3, 2, 0) - 1)) - 1] =
          c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_ii), 1, 3, 1, 0) - 1];
      }
    }
  }

  c20_b_m = 3;
  c20_e[1] = c20_b_A[13];
  c20_e[2] = 0.0;
  for (c20_d_q = 3; c20_d_q > 0; c20_d_q--) {
    c20_b_q = c20_d_q;
    c20_k_a = c20_b_q;
    c20_qp1 = c20_k_a;
    c20_k_b = c20_b_q;
    c20_nmq = 6 - c20_k_b;
    c20_l_a = c20_nmq + 1;
    c20_nmqp1 = c20_l_a;
    c20_m_a = c20_b_q;
    c20_h_c = c20_m_a;
    c20_l_b = c20_h_c - 1;
    c20_i_c = 6 * c20_l_b;
    c20_n_a = c20_b_q;
    c20_m_b = c20_i_c;
    c20_qq = c20_n_a + c20_m_b;
    if (c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 3, 1, 0) - 1] != 0.0) {
      c20_g_qp1 = c20_qp1 + 1;
      c20_g_overflow = FALSE;
      if (c20_g_overflow) {
        c20_check_forloop_overflow_error(chartInstance, c20_g_overflow);
      }

      for (c20_e_jj = c20_g_qp1; c20_e_jj < 4; c20_e_jj++) {
        c20_b_jj = c20_e_jj;
        c20_o_a = c20_b_jj;
        c20_j_c = c20_o_a;
        c20_n_b = c20_j_c - 1;
        c20_k_c = 6 * c20_n_b;
        c20_p_a = c20_b_q;
        c20_o_b = c20_k_c;
        c20_qjj = c20_p_a + c20_o_b;
        for (c20_i188 = 0; c20_i188 < 18; c20_i188++) {
          c20_b_U[c20_i188] = c20_U[c20_i188];
        }

        for (c20_i189 = 0; c20_i189 < 18; c20_i189++) {
          c20_c_U[c20_i189] = c20_U[c20_i189];
        }

        c20_t = c20_eml_xdotc(chartInstance, c20_nmqp1, c20_b_U, c20_qq, c20_c_U,
                              c20_qjj);
        c20_t = -c20_eml_div(chartInstance, c20_t,
                             c20_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_qq), 1, 18, 1, 0) - 1]);
        c20_h_eml_xaxpy(chartInstance, c20_nmqp1, c20_t, c20_qq, c20_U, c20_qjj);
      }

      c20_e_q = c20_b_q;
      c20_h_overflow = FALSE;
      if (c20_h_overflow) {
        c20_check_forloop_overflow_error(chartInstance, c20_h_overflow);
      }

      for (c20_e_ii = c20_e_q; c20_e_ii < 7; c20_e_ii++) {
        c20_b_ii = c20_e_ii;
        c20_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c20_b_ii), 1, 6, 1, 0) + 6 *
               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c20_b_q), 1, 3, 2, 0) - 1)) - 1] = -c20_U
          [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c20_b_ii), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
              "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 3, 2, 0)
             - 1)) - 1];
      }

      c20_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c20_qq), 1, 18, 1, 0) - 1] = c20_U[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_qq), 1, 18, 1, 0) - 1] +
        1.0;
      c20_q_a = c20_b_q - 1;
      c20_i190 = c20_q_a;
      c20_p_b = c20_i190;
      c20_q_b = c20_p_b;
      if (1 > c20_q_b) {
        c20_i_overflow = FALSE;
      } else {
        c20_i_overflow = (c20_q_b > 2147483646);
      }

      if (c20_i_overflow) {
        c20_check_forloop_overflow_error(chartInstance, c20_i_overflow);
      }

      for (c20_f_ii = 1; c20_f_ii <= c20_i190; c20_f_ii++) {
        c20_b_ii = c20_f_ii;
        c20_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c20_b_ii), 1, 6, 1, 0) + 6 *
               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c20_b_q), 1, 3, 2, 0) - 1)) - 1] = 0.0;
      }
    } else {
      for (c20_g_ii = 1; c20_g_ii < 7; c20_g_ii++) {
        c20_b_ii = c20_g_ii;
        c20_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c20_b_ii), 1, 6, 1, 0) + 6 *
               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c20_b_q), 1, 3, 2, 0) - 1)) - 1] = 0.0;
      }

      c20_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c20_qq), 1, 18, 1, 0) - 1] = 1.0;
    }
  }

  for (c20_f_q = 3; c20_f_q > 0; c20_f_q--) {
    c20_b_q = c20_f_q;
    if (c20_b_q <= 1) {
      if (c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_q), 1, 3, 1, 0) - 1] != 0.0) {
        c20_r_a = c20_b_q + 1;
        c20_qp1 = c20_r_a;
        c20_r_b = c20_b_q;
        c20_pmq = 3 - c20_r_b;
        c20_s_a = c20_b_q;
        c20_l_c = c20_s_a;
        c20_s_b = c20_l_c - 1;
        c20_m_c = 3 * c20_s_b;
        c20_t_a = c20_qp1;
        c20_t_b = c20_m_c;
        c20_qp1q = c20_t_a + c20_t_b;
        c20_h_qp1 = c20_qp1;
        c20_j_overflow = FALSE;
        if (c20_j_overflow) {
          c20_check_forloop_overflow_error(chartInstance, c20_j_overflow);
        }

        for (c20_f_jj = c20_h_qp1; c20_f_jj < 4; c20_f_jj++) {
          c20_b_jj = c20_f_jj;
          c20_u_a = c20_b_jj;
          c20_n_c = c20_u_a;
          c20_u_b = c20_n_c - 1;
          c20_o_c = 3 * c20_u_b;
          c20_v_a = c20_qp1;
          c20_v_b = c20_o_c;
          c20_qp1jj = c20_v_a + c20_v_b;
          for (c20_i191 = 0; c20_i191 < 9; c20_i191++) {
            c20_b_Vf[c20_i191] = c20_Vf[c20_i191];
          }

          for (c20_i192 = 0; c20_i192 < 9; c20_i192++) {
            c20_c_Vf[c20_i192] = c20_Vf[c20_i192];
          }

          c20_t = c20_b_eml_xdotc(chartInstance, c20_pmq, c20_b_Vf, c20_qp1q,
            c20_c_Vf, c20_qp1jj);
          c20_t = -c20_eml_div(chartInstance, c20_t,
                               c20_Vf[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_qp1q), 1, 9, 1, 0) - 1]);
          c20_k_eml_xaxpy(chartInstance, c20_pmq, c20_t, c20_qp1q, c20_Vf,
                          c20_qp1jj);
        }
      }
    }

    for (c20_h_ii = 1; c20_h_ii < 4; c20_h_ii++) {
      c20_b_ii = c20_h_ii;
      c20_Vf[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c20_b_ii), 1, 3, 1, 0) + 3 *
              (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c20_b_q), 1, 3, 2, 0) - 1)) - 1] = 0.0;
    }

    c20_Vf[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c20_b_q), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
              "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 3, 2, 0)
             - 1)) - 1] = 1.0;
  }

  for (c20_g_q = 1; c20_g_q < 4; c20_g_q++) {
    c20_b_q = c20_g_q;
    if (c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 3, 1, 0) - 1] != 0.0) {
      c20_rt = c20_abs(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 3, 1, 0) - 1]);
      c20_r = c20_eml_div(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 3, 1, 0) - 1],
                          c20_rt);
      c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c20_b_q), 1, 3, 1, 0) - 1] = c20_rt;
      if (c20_b_q < 3) {
        c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 3, 1, 0) - 1] = c20_eml_div(chartInstance,
          c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 3, 1, 0) - 1], c20_r);
      }

      if (c20_b_q <= 6) {
        c20_w_a = c20_b_q;
        c20_p_c = c20_w_a;
        c20_w_b = c20_p_c - 1;
        c20_q_c = 6 * c20_w_b;
        c20_x_b = c20_q_c;
        c20_colq = c20_x_b;
        c20_j_eml_xscal(chartInstance, c20_r, c20_U, c20_colq + 1);
      }
    }

    if (c20_b_q < 3) {
      if (c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_q), 1, 3, 1, 0) - 1] != 0.0) {
        c20_rt = c20_abs(chartInstance, c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 3, 1, 0) - 1]);
        c20_r = c20_eml_div(chartInstance, c20_rt,
                            c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 3, 1, 0) - 1]);
        c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 3, 1, 0) - 1] = c20_rt;
        c20_x_a = c20_b_q;
        c20_r_c = c20_x_a;
        c20_y_a = c20_b_q;
        c20_s_c = c20_y_a;
        c20_ab_a = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c20_s_c + 1)), 1, 3, 1, 0) - 1];
        c20_y_b = c20_r;
        c20_c_y = c20_ab_a * c20_y_b;
        c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c20_r_c + 1)), 1, 3, 1, 0) - 1] = c20_c_y;
        c20_ab_b = c20_b_q;
        c20_t_c = 3 * c20_ab_b;
        c20_bb_b = c20_t_c;
        c20_colqp1 = c20_bb_b;
        c20_k_eml_xscal(chartInstance, c20_r, c20_Vf, c20_colqp1 + 1);
      }
    }
  }

  c20_iter = 0.0;
  c20_realmin(chartInstance);
  c20_eps(chartInstance);
  c20_tiny = c20_eml_div(chartInstance, 2.2250738585072014E-308,
    2.2204460492503131E-16);
  c20_snorm = 0.0;
  for (c20_i_ii = 1; c20_i_ii < 4; c20_i_ii++) {
    c20_b_ii = c20_i_ii;
    c20_varargin_1 = c20_abs(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_ii),
      1, 3, 1, 0) - 1]);
    c20_varargin_2 = c20_abs(chartInstance, c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_ii),
      1, 3, 1, 0) - 1]);
    c20_b_varargin_2 = c20_varargin_1;
    c20_varargin_3 = c20_varargin_2;
    c20_x = c20_b_varargin_2;
    c20_d_y = c20_varargin_3;
    c20_b_x = c20_x;
    c20_e_y = c20_d_y;
    c20_eml_scalar_eg(chartInstance);
    c20_xk = c20_b_x;
    c20_yk = c20_e_y;
    c20_c_x = c20_xk;
    c20_f_y = c20_yk;
    c20_eml_scalar_eg(chartInstance);
    c20_maxval = muDoubleScalarMax(c20_c_x, c20_f_y);
    c20_b_varargin_1 = c20_snorm;
    c20_c_varargin_2 = c20_maxval;
    c20_d_varargin_2 = c20_b_varargin_1;
    c20_b_varargin_3 = c20_c_varargin_2;
    c20_d_x = c20_d_varargin_2;
    c20_g_y = c20_b_varargin_3;
    c20_e_x = c20_d_x;
    c20_h_y = c20_g_y;
    c20_eml_scalar_eg(chartInstance);
    c20_b_xk = c20_e_x;
    c20_b_yk = c20_h_y;
    c20_f_x = c20_b_xk;
    c20_i_y = c20_b_yk;
    c20_eml_scalar_eg(chartInstance);
    c20_snorm = muDoubleScalarMax(c20_f_x, c20_i_y);
  }

  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c20_b_m > 0)) {
    if (c20_iter >= 75.0) {
      c20_b_eml_error(chartInstance);
      exitg1 = TRUE;
    } else {
      c20_bb_a = c20_b_m - 1;
      c20_b_q = c20_bb_a;
      c20_cb_a = c20_b_m;
      c20_i193 = c20_cb_a;
      c20_k_overflow = FALSE;
      if (c20_k_overflow) {
        c20_check_forloop_overflow_error(chartInstance, c20_k_overflow);
      }

      c20_j_ii = c20_i193 - 1;
      guard3 = FALSE;
      guard4 = FALSE;
      exitg5 = FALSE;
      while ((exitg5 == FALSE) && (c20_j_ii > -1)) {
        c20_b_ii = c20_j_ii;
        c20_b_q = c20_b_ii;
        if (c20_b_ii == 0) {
          exitg5 = TRUE;
        } else {
          c20_db_a = c20_b_ii;
          c20_u_c = c20_db_a;
          c20_test0 = c20_abs(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK(
            "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_ii), 1, 3, 1, 0) -
                              1]) + c20_abs(chartInstance,
            c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c20_u_c + 1)), 1, 3, 1, 0) - 1]);
          c20_ztest0 = c20_abs(chartInstance, c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
            "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_ii), 1, 3, 1, 0) -
                               1]);
          c20_eps(chartInstance);
          c20_cb_b = c20_test0;
          c20_j_y = 2.2204460492503131E-16 * c20_cb_b;
          if (c20_ztest0 <= c20_j_y) {
            guard4 = TRUE;
            exitg5 = TRUE;
          } else if (c20_ztest0 <= c20_tiny) {
            guard4 = TRUE;
            exitg5 = TRUE;
          } else {
            guard11 = FALSE;
            if (c20_iter > 20.0) {
              c20_eps(chartInstance);
              c20_db_b = c20_snorm;
              c20_k_y = 2.2204460492503131E-16 * c20_db_b;
              if (c20_ztest0 <= c20_k_y) {
                guard3 = TRUE;
                exitg5 = TRUE;
              } else {
                guard11 = TRUE;
              }
            } else {
              guard11 = TRUE;
            }

            if (guard11 == TRUE) {
              c20_j_ii--;
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
        c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_ii), 1, 3, 1, 0) - 1] = 0.0;
      }

      c20_eb_a = c20_b_m;
      c20_v_c = c20_eb_a;
      if (c20_b_q == c20_v_c - 1) {
        c20_kase = 4.0;
      } else {
        c20_qs = c20_b_m;
        c20_c_m = c20_b_m;
        c20_h_q = c20_b_q;
        c20_fb_a = c20_c_m;
        c20_eb_b = c20_h_q;
        c20_gb_a = c20_fb_a;
        c20_fb_b = c20_eb_b;
        if (c20_gb_a < c20_fb_b) {
          c20_l_overflow = FALSE;
        } else {
          c20_l_overflow = (c20_fb_b < -2147483647);
        }

        if (c20_l_overflow) {
          c20_check_forloop_overflow_error(chartInstance, c20_l_overflow);
        }

        c20_k_ii = c20_c_m;
        guard2 = FALSE;
        exitg4 = FALSE;
        while ((exitg4 == FALSE) && (c20_k_ii >= c20_h_q)) {
          c20_b_ii = c20_k_ii;
          c20_qs = c20_b_ii;
          if (c20_b_ii == c20_b_q) {
            exitg4 = TRUE;
          } else {
            c20_test = 0.0;
            if (c20_b_ii < c20_b_m) {
              c20_test = c20_abs(chartInstance,
                                 c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c20_b_ii), 1, 3, 1, 0) - 1]);
            }

            c20_hb_a = c20_b_q;
            c20_w_c = c20_hb_a;
            if (c20_b_ii > c20_w_c + 1) {
              c20_ib_a = c20_b_ii;
              c20_x_c = c20_ib_a;
              c20_test += c20_abs(chartInstance,
                                  c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)(c20_x_c - 1)), 1, 3, 1, 0) - 1]);
            }

            c20_ztest = c20_abs(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK
                                ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
              c20_b_ii), 1, 3, 1, 0) - 1]);
            c20_eps(chartInstance);
            c20_gb_b = c20_test;
            c20_l_y = 2.2204460492503131E-16 * c20_gb_b;
            if (c20_ztest <= c20_l_y) {
              guard2 = TRUE;
              exitg4 = TRUE;
            } else if (c20_ztest <= c20_tiny) {
              guard2 = TRUE;
              exitg4 = TRUE;
            } else {
              c20_k_ii--;
              guard2 = FALSE;
            }
          }
        }

        if (guard2 == TRUE) {
          c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_ii), 1, 3, 1, 0) - 1] = 0.0;
        }

        if (c20_qs == c20_b_q) {
          c20_kase = 3.0;
        } else if (c20_qs == c20_b_m) {
          c20_kase = 1.0;
        } else {
          c20_kase = 2.0;
          c20_b_q = c20_qs;
        }
      }

      c20_jb_a = c20_b_q + 1;
      c20_b_q = c20_jb_a;
      switch ((int32_T)_SFD_INTEGER_CHECK("", c20_kase)) {
       case 1:
        c20_kb_a = c20_b_m;
        c20_y_c = c20_kb_a;
        c20_f = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c20_y_c - 1)), 1, 3, 1, 0) - 1];
        c20_lb_a = c20_b_m;
        c20_ab_c = c20_lb_a;
        c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c20_ab_c - 1)), 1, 3, 1, 0) - 1] = 0.0;
        c20_mb_a = c20_b_m - 1;
        c20_i194 = c20_mb_a;
        c20_i_q = c20_b_q;
        c20_nb_a = c20_i194;
        c20_hb_b = c20_i_q;
        c20_ob_a = c20_nb_a;
        c20_ib_b = c20_hb_b;
        if (c20_ob_a < c20_ib_b) {
          c20_m_overflow = FALSE;
        } else {
          c20_m_overflow = (c20_ib_b < -2147483647);
        }

        if (c20_m_overflow) {
          c20_check_forloop_overflow_error(chartInstance, c20_m_overflow);
        }

        for (c20_k = c20_i194; c20_k >= c20_i_q; c20_k--) {
          c20_b_k = c20_k;
          c20_t1 = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 3, 1, 0) - 1];
          c20_b_t1 = c20_t1;
          c20_b_f = c20_f;
          c20_b_eml_xrotg(chartInstance, &c20_b_t1, &c20_b_f, &c20_cs, &c20_sn);
          c20_t1 = c20_b_t1;
          c20_f = c20_b_f;
          c20_b_cs = c20_cs;
          c20_b_sn = c20_sn;
          c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_k), 1, 3, 1, 0) - 1] = c20_t1;
          if (c20_b_k > c20_b_q) {
            c20_pb_a = c20_b_k - 1;
            c20_km1 = c20_pb_a;
            c20_qb_a = -c20_b_sn;
            c20_jb_b = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c20_km1), 1, 3, 1, 0) - 1];
            c20_f = c20_qb_a * c20_jb_b;
            c20_rb_a = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c20_km1), 1, 3, 1, 0) - 1];
            c20_kb_b = c20_b_cs;
            c20_m_y = c20_rb_a * c20_kb_b;
            c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c20_km1), 1, 3, 1, 0) - 1] = c20_m_y;
          }

          c20_sb_a = c20_b_k;
          c20_bb_c = c20_sb_a;
          c20_lb_b = c20_bb_c - 1;
          c20_cb_c = 3 * c20_lb_b;
          c20_mb_b = c20_cb_c;
          c20_colk = c20_mb_b;
          c20_tb_a = c20_b_m;
          c20_db_c = c20_tb_a;
          c20_nb_b = c20_db_c - 1;
          c20_eb_c = 3 * c20_nb_b;
          c20_ob_b = c20_eb_c;
          c20_colm = c20_ob_b;
          c20_d_eml_xrot(chartInstance, c20_Vf, c20_colk + 1, c20_colm + 1,
                         c20_b_cs, c20_b_sn);
        }
        break;

       case 2:
        c20_ub_a = c20_b_q - 1;
        c20_qm1 = c20_ub_a;
        c20_f = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_qm1), 1, 3, 1, 0) - 1];
        c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_qm1), 1, 3, 1, 0) - 1] = 0.0;
        c20_j_q = c20_b_q;
        c20_d_m = c20_b_m;
        c20_vb_a = c20_j_q;
        c20_pb_b = c20_d_m;
        c20_wb_a = c20_vb_a;
        c20_qb_b = c20_pb_b;
        if (c20_wb_a > c20_qb_b) {
          c20_n_overflow = FALSE;
        } else {
          c20_n_overflow = (c20_qb_b > 2147483646);
        }

        if (c20_n_overflow) {
          c20_check_forloop_overflow_error(chartInstance, c20_n_overflow);
        }

        for (c20_c_k = c20_j_q; c20_c_k <= c20_d_m; c20_c_k++) {
          c20_b_k = c20_c_k;
          c20_t1 = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 3, 1, 0) - 1];
          c20_c_t1 = c20_t1;
          c20_unusedU0 = c20_f;
          c20_b_eml_xrotg(chartInstance, &c20_c_t1, &c20_unusedU0, &c20_c_cs,
                          &c20_c_sn);
          c20_t1 = c20_c_t1;
          c20_b_cs = c20_c_cs;
          c20_b_sn = c20_c_sn;
          c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_k), 1, 3, 1, 0) - 1] = c20_t1;
          c20_xb_a = -c20_b_sn;
          c20_rb_b = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 3, 1, 0) - 1];
          c20_f = c20_xb_a * c20_rb_b;
          c20_yb_a = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 3, 1, 0) - 1];
          c20_sb_b = c20_b_cs;
          c20_n_y = c20_yb_a * c20_sb_b;
          c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_k), 1, 3, 1, 0) - 1] = c20_n_y;
          c20_ac_a = c20_b_k;
          c20_fb_c = c20_ac_a;
          c20_tb_b = c20_fb_c - 1;
          c20_gb_c = 6 * c20_tb_b;
          c20_ub_b = c20_gb_c;
          c20_colk = c20_ub_b;
          c20_bc_a = c20_qm1;
          c20_hb_c = c20_bc_a;
          c20_vb_b = c20_hb_c - 1;
          c20_ib_c = 6 * c20_vb_b;
          c20_wb_b = c20_ib_c;
          c20_colqm1 = c20_wb_b;
          c20_e_eml_xrot(chartInstance, c20_U, c20_colk + 1, c20_colqm1 + 1,
                         c20_b_cs, c20_b_sn);
        }
        break;

       case 3:
        c20_cc_a = c20_b_m - 1;
        c20_mm1 = c20_cc_a;
        c20_d9 = c20_abs(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_m), 1, 3, 1, 0) - 1]);
        c20_d10 = c20_abs(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_mm1), 1, 3, 1, 0) - 1]);
        c20_d11 = c20_abs(chartInstance, c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_mm1), 1, 3, 1, 0) - 1]);
        c20_d12 = c20_abs(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 3, 1, 0) - 1]);
        c20_d13 = c20_abs(chartInstance, c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 3, 1, 0) - 1]);
        c20_c_varargin_1[0] = c20_d9;
        c20_c_varargin_1[1] = c20_d10;
        c20_c_varargin_1[2] = c20_d11;
        c20_c_varargin_1[3] = c20_d12;
        c20_c_varargin_1[4] = c20_d13;
        c20_ixstart = 1;
        c20_mtmp = c20_c_varargin_1[0];
        c20_g_x = c20_mtmp;
        c20_xb_b = muDoubleScalarIsNaN(c20_g_x);
        if (c20_xb_b) {
          c20_ix = 2;
          exitg2 = FALSE;
          while ((exitg2 == FALSE) && (c20_ix < 6)) {
            c20_b_ix = c20_ix;
            c20_ixstart = c20_b_ix;
            c20_h_x = c20_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c20_b_ix), 1, 5, 1, 0) - 1];
            c20_yb_b = muDoubleScalarIsNaN(c20_h_x);
            if (!c20_yb_b) {
              c20_mtmp = c20_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_ix), 1, 5, 1, 0) -
                1];
              exitg2 = TRUE;
            } else {
              c20_ix++;
            }
          }
        }

        if (c20_ixstart < 5) {
          c20_dc_a = c20_ixstart;
          c20_i195 = c20_dc_a;
          c20_o_overflow = FALSE;
          if (c20_o_overflow) {
            c20_check_forloop_overflow_error(chartInstance, c20_o_overflow);
          }

          for (c20_c_ix = c20_i195 + 1; c20_c_ix < 6; c20_c_ix++) {
            c20_b_ix = c20_c_ix;
            c20_ec_a = c20_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c20_b_ix), 1, 5, 1, 0) - 1];
            c20_ac_b = c20_mtmp;
            c20_p = (c20_ec_a > c20_ac_b);
            if (c20_p) {
              c20_mtmp = c20_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_ix), 1, 5, 1, 0) -
                1];
            }
          }
        }

        c20_b_mtmp = c20_mtmp;
        c20_scale = c20_b_mtmp;
        c20_sm = c20_eml_div(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_m),
          1, 3, 1, 0) - 1], c20_scale);
        c20_smm1 = c20_eml_div(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_mm1), 1, 3, 1, 0) - 1],
          c20_scale);
        c20_emm1 = c20_eml_div(chartInstance, c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_mm1), 1, 3, 1, 0) - 1],
          c20_scale);
        c20_sqds = c20_eml_div(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 3, 1, 0) - 1],
          c20_scale);
        c20_eqds = c20_eml_div(chartInstance, c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 3, 1, 0) - 1],
          c20_scale);
        c20_fc_a = c20_smm1 + c20_sm;
        c20_bc_b = c20_smm1 - c20_sm;
        c20_o_y = c20_fc_a * c20_bc_b;
        c20_gc_a = c20_emm1;
        c20_cc_b = c20_emm1;
        c20_p_y = c20_gc_a * c20_cc_b;
        c20_dc_b = c20_eml_div(chartInstance, c20_o_y + c20_p_y, 2.0);
        c20_hc_a = c20_sm;
        c20_ec_b = c20_emm1;
        c20_jb_c = c20_hc_a * c20_ec_b;
        c20_ic_a = c20_jb_c;
        c20_fc_b = c20_jb_c;
        c20_jb_c = c20_ic_a * c20_fc_b;
        c20_shift = 0.0;
        guard1 = FALSE;
        if (c20_dc_b != 0.0) {
          guard1 = TRUE;
        } else {
          if (c20_jb_c != 0.0) {
            guard1 = TRUE;
          }
        }

        if (guard1 == TRUE) {
          c20_jc_a = c20_dc_b;
          c20_gc_b = c20_dc_b;
          c20_q_y = c20_jc_a * c20_gc_b;
          c20_shift = c20_q_y + c20_jb_c;
          c20_b_sqrt(chartInstance, &c20_shift);
          if (c20_dc_b < 0.0) {
            c20_shift = -c20_shift;
          }

          c20_shift = c20_eml_div(chartInstance, c20_jb_c, c20_dc_b + c20_shift);
        }

        c20_kc_a = c20_sqds + c20_sm;
        c20_hc_b = c20_sqds - c20_sm;
        c20_r_y = c20_kc_a * c20_hc_b;
        c20_f = c20_r_y + c20_shift;
        c20_lc_a = c20_sqds;
        c20_ic_b = c20_eqds;
        c20_g = c20_lc_a * c20_ic_b;
        c20_k_q = c20_b_q;
        c20_b_mm1 = c20_mm1;
        c20_mc_a = c20_k_q;
        c20_jc_b = c20_b_mm1;
        c20_nc_a = c20_mc_a;
        c20_kc_b = c20_jc_b;
        if (c20_nc_a > c20_kc_b) {
          c20_p_overflow = FALSE;
        } else {
          c20_p_overflow = (c20_kc_b > 2147483646);
        }

        if (c20_p_overflow) {
          c20_check_forloop_overflow_error(chartInstance, c20_p_overflow);
        }

        for (c20_d_k = c20_k_q; c20_d_k <= c20_b_mm1; c20_d_k++) {
          c20_b_k = c20_d_k;
          c20_oc_a = c20_b_k;
          c20_km1 = c20_oc_a;
          c20_pc_a = c20_b_k + 1;
          c20_kp1 = c20_pc_a;
          c20_c_f = c20_f;
          c20_unusedU1 = c20_g;
          c20_b_eml_xrotg(chartInstance, &c20_c_f, &c20_unusedU1, &c20_d_cs,
                          &c20_d_sn);
          c20_f = c20_c_f;
          c20_b_cs = c20_d_cs;
          c20_b_sn = c20_d_sn;
          if (c20_b_k > c20_b_q) {
            c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)(c20_km1 - 1)), 1, 3, 1, 0) - 1] = c20_f;
          }

          c20_qc_a = c20_b_cs;
          c20_lc_b = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 3, 1, 0) - 1];
          c20_s_y = c20_qc_a * c20_lc_b;
          c20_rc_a = c20_b_sn;
          c20_mc_b = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 3, 1, 0) - 1];
          c20_t_y = c20_rc_a * c20_mc_b;
          c20_f = c20_s_y + c20_t_y;
          c20_sc_a = c20_b_cs;
          c20_nc_b = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 3, 1, 0) - 1];
          c20_u_y = c20_sc_a * c20_nc_b;
          c20_tc_a = c20_b_sn;
          c20_oc_b = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 3, 1, 0) - 1];
          c20_v_y = c20_tc_a * c20_oc_b;
          c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_k), 1, 3, 1, 0) - 1] = c20_u_y - c20_v_y;
          c20_uc_a = c20_b_sn;
          c20_pc_b = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_kp1), 1, 3, 1, 0) - 1];
          c20_g = c20_uc_a * c20_pc_b;
          c20_vc_a = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_kp1), 1, 3, 1, 0) - 1];
          c20_qc_b = c20_b_cs;
          c20_w_y = c20_vc_a * c20_qc_b;
          c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_kp1), 1, 3, 1, 0) - 1] = c20_w_y;
          c20_wc_a = c20_b_k;
          c20_kb_c = c20_wc_a;
          c20_rc_b = c20_kb_c - 1;
          c20_lb_c = 3 * c20_rc_b;
          c20_sc_b = c20_lb_c;
          c20_colk = c20_sc_b;
          c20_tc_b = c20_b_k;
          c20_mb_c = 3 * c20_tc_b;
          c20_uc_b = c20_mb_c;
          c20_colkp1 = c20_uc_b;
          c20_d_eml_xrot(chartInstance, c20_Vf, c20_colk + 1, c20_colkp1 + 1,
                         c20_b_cs, c20_b_sn);
          c20_d_f = c20_f;
          c20_unusedU2 = c20_g;
          c20_b_eml_xrotg(chartInstance, &c20_d_f, &c20_unusedU2, &c20_e_cs,
                          &c20_e_sn);
          c20_f = c20_d_f;
          c20_b_cs = c20_e_cs;
          c20_b_sn = c20_e_sn;
          c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_k), 1, 3, 1, 0) - 1] = c20_f;
          c20_xc_a = c20_b_cs;
          c20_vc_b = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 3, 1, 0) - 1];
          c20_x_y = c20_xc_a * c20_vc_b;
          c20_yc_a = c20_b_sn;
          c20_wc_b = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_kp1), 1, 3, 1, 0) - 1];
          c20_y_y = c20_yc_a * c20_wc_b;
          c20_f = c20_x_y + c20_y_y;
          c20_ad_a = -c20_b_sn;
          c20_xc_b = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 3, 1, 0) - 1];
          c20_ab_y = c20_ad_a * c20_xc_b;
          c20_bd_a = c20_b_cs;
          c20_yc_b = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_kp1), 1, 3, 1, 0) - 1];
          c20_bb_y = c20_bd_a * c20_yc_b;
          c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_kp1), 1, 3, 1, 0) - 1] = c20_ab_y + c20_bb_y;
          c20_cd_a = c20_b_sn;
          c20_ad_b = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_kp1), 1, 3, 1, 0) - 1];
          c20_g = c20_cd_a * c20_ad_b;
          c20_dd_a = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_kp1), 1, 3, 1, 0) - 1];
          c20_bd_b = c20_b_cs;
          c20_cb_y = c20_dd_a * c20_bd_b;
          c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_kp1), 1, 3, 1, 0) - 1] = c20_cb_y;
          if (c20_b_k < 6) {
            c20_ed_a = c20_b_k;
            c20_nb_c = c20_ed_a;
            c20_cd_b = c20_nb_c - 1;
            c20_ob_c = 6 * c20_cd_b;
            c20_dd_b = c20_ob_c;
            c20_colk = c20_dd_b;
            c20_ed_b = c20_b_k;
            c20_pb_c = 6 * c20_ed_b;
            c20_fd_b = c20_pb_c;
            c20_colkp1 = c20_fd_b;
            c20_e_eml_xrot(chartInstance, c20_U, c20_colk + 1, c20_colkp1 + 1,
                           c20_b_cs, c20_b_sn);
          }
        }

        c20_fd_a = c20_b_m;
        c20_qb_c = c20_fd_a;
        c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c20_qb_c - 1)), 1, 3, 1, 0) - 1] = c20_f;
        c20_iter++;
        break;

       default:
        if (c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c20_b_q), 1, 3, 1, 0) - 1] < 0.0) {
          c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_q), 1, 3, 1, 0) - 1] =
            -c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c20_b_q), 1, 3, 1, 0) - 1];
          c20_gd_a = c20_b_q;
          c20_rb_c = c20_gd_a;
          c20_gd_b = c20_rb_c - 1;
          c20_sb_c = 3 * c20_gd_b;
          c20_hd_b = c20_sb_c;
          c20_colq = c20_hd_b;
          c20_g_eml_scalar_eg(chartInstance);
          c20_d14 = -1.0;
          c20_k_eml_xscal(chartInstance, c20_d14, c20_Vf, c20_colq + 1);
        }

        c20_hd_a = c20_b_q + 1;
        c20_qp1 = c20_hd_a;
        exitg3 = FALSE;
        while ((exitg3 == FALSE) && (c20_b_q < 3)) {
          if (c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c20_b_q), 1, 3, 1, 0) - 1] <
              c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c20_qp1), 1, 3, 1, 0) - 1]) {
            c20_rt = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 3, 1, 0) - 1];
            c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c20_b_q), 1, 3, 1, 0) - 1] =
              c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c20_qp1), 1, 3, 1, 0) - 1];
            c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c20_qp1), 1, 3, 1, 0) - 1] = c20_rt;
            if (c20_b_q < 3) {
              c20_jd_a = c20_b_q;
              c20_tb_c = c20_jd_a;
              c20_id_b = c20_tb_c - 1;
              c20_ub_c = 3 * c20_id_b;
              c20_jd_b = c20_ub_c;
              c20_colq = c20_jd_b;
              c20_kd_b = c20_b_q;
              c20_vb_c = 3 * c20_kd_b;
              c20_ld_b = c20_vb_c;
              c20_colqp1 = c20_ld_b;
              c20_d_eml_xswap(chartInstance, c20_Vf, c20_colq + 1, c20_colqp1 +
                              1);
            }

            if (c20_b_q < 6) {
              c20_kd_a = c20_b_q;
              c20_wb_c = c20_kd_a;
              c20_md_b = c20_wb_c - 1;
              c20_xb_c = 6 * c20_md_b;
              c20_nd_b = c20_xb_c;
              c20_colq = c20_nd_b;
              c20_od_b = c20_b_q;
              c20_yb_c = 6 * c20_od_b;
              c20_pd_b = c20_yb_c;
              c20_colqp1 = c20_pd_b;
              c20_e_eml_xswap(chartInstance, c20_U, c20_colq + 1, c20_colqp1 + 1);
            }

            c20_b_q = c20_qp1;
            c20_ld_a = c20_b_q + 1;
            c20_qp1 = c20_ld_a;
          } else {
            exitg3 = TRUE;
          }
        }

        c20_iter = 0.0;
        c20_id_a = c20_b_m - 1;
        c20_b_m = c20_id_a;
        break;
      }
    }
  }

  for (c20_e_k = 1; c20_e_k < 4; c20_e_k++) {
    c20_b_k = c20_e_k;
    c20_S[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_b_k), 1, 3, 1, 0) - 1] = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 3, 1, 0) - 1];
  }

  for (c20_j = 1; c20_j < 4; c20_j++) {
    c20_b_j = c20_j;
    for (c20_i = 1; c20_i < 4; c20_i++) {
      c20_b_i = c20_i;
      c20_V[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
               (real_T)c20_b_i), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
               "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_j), 1, 3, 2, 0)
              - 1)) - 1] = c20_Vf[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c20_b_i), 1, 3, 1, 0) + 3 *
        (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
        c20_b_j), 1, 3, 2, 0) - 1)) - 1];
    }
  }
}

static real_T c20_eml_xnrm2(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_x[18], int32_T c20_ix0)
{
  real_T c20_y;
  int32_T c20_b_n;
  int32_T c20_b_ix0;
  int32_T c20_c_n;
  int32_T c20_c_ix0;
  real_T c20_b_x;
  real_T c20_c_x;
  real_T c20_scale;
  int32_T c20_kstart;
  int32_T c20_a;
  int32_T c20_c;
  int32_T c20_b_a;
  int32_T c20_b_c;
  int32_T c20_c_a;
  int32_T c20_b;
  int32_T c20_kend;
  int32_T c20_b_kstart;
  int32_T c20_b_kend;
  int32_T c20_d_a;
  int32_T c20_b_b;
  int32_T c20_e_a;
  int32_T c20_c_b;
  boolean_T c20_overflow;
  int32_T c20_k;
  int32_T c20_b_k;
  real_T c20_d_x;
  real_T c20_e_x;
  real_T c20_absxk;
  real_T c20_t;
  c20_b_n = c20_n;
  c20_b_ix0 = c20_ix0;
  c20_c_n = c20_b_n;
  c20_c_ix0 = c20_b_ix0;
  c20_y = 0.0;
  if (c20_c_n < 1) {
  } else if (c20_c_n == 1) {
    c20_b_x = c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c20_c_ix0), 1, 18, 1, 0) - 1];
    c20_c_x = c20_b_x;
    c20_y = muDoubleScalarAbs(c20_c_x);
  } else {
    c20_realmin(chartInstance);
    c20_scale = 2.2250738585072014E-308;
    c20_kstart = c20_c_ix0;
    c20_a = c20_c_n;
    c20_c = c20_a;
    c20_b_a = c20_c - 1;
    c20_b_c = c20_b_a;
    c20_c_a = c20_kstart;
    c20_b = c20_b_c;
    c20_kend = c20_c_a + c20_b;
    c20_b_kstart = c20_kstart;
    c20_b_kend = c20_kend;
    c20_d_a = c20_b_kstart;
    c20_b_b = c20_b_kend;
    c20_e_a = c20_d_a;
    c20_c_b = c20_b_b;
    if (c20_e_a > c20_c_b) {
      c20_overflow = FALSE;
    } else {
      c20_overflow = (c20_c_b > 2147483646);
    }

    if (c20_overflow) {
      c20_check_forloop_overflow_error(chartInstance, c20_overflow);
    }

    for (c20_k = c20_b_kstart; c20_k <= c20_b_kend; c20_k++) {
      c20_b_k = c20_k;
      c20_d_x = c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 18, 1, 0) - 1];
      c20_e_x = c20_d_x;
      c20_absxk = muDoubleScalarAbs(c20_e_x);
      if (c20_absxk > c20_scale) {
        c20_t = c20_scale / c20_absxk;
        c20_y = 1.0 + c20_y * c20_t * c20_t;
        c20_scale = c20_absxk;
      } else {
        c20_t = c20_absxk / c20_scale;
        c20_y += c20_t * c20_t;
      }
    }

    c20_y = c20_scale * muDoubleScalarSqrt(c20_y);
  }

  return c20_y;
}

static void c20_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[18], int32_T c20_ix0, real_T
  c20_b_x[18])
{
  int32_T c20_i196;
  for (c20_i196 = 0; c20_i196 < 18; c20_i196++) {
    c20_b_x[c20_i196] = c20_x[c20_i196];
  }

  c20_h_eml_xscal(chartInstance, c20_n, c20_a, c20_b_x, c20_ix0);
}

static real_T c20_eml_xdotc(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_x[18], int32_T c20_ix0, real_T c20_y[18], int32_T
  c20_iy0)
{
  real_T c20_d;
  int32_T c20_b_n;
  int32_T c20_b_ix0;
  int32_T c20_b_iy0;
  int32_T c20_c_n;
  int32_T c20_c_ix0;
  int32_T c20_c_iy0;
  int32_T c20_d_n;
  int32_T c20_d_ix0;
  int32_T c20_d_iy0;
  int32_T c20_e_n;
  int32_T c20_e_ix0;
  int32_T c20_e_iy0;
  int32_T c20_ix;
  int32_T c20_iy;
  int32_T c20_f_n;
  int32_T c20_b;
  int32_T c20_b_b;
  boolean_T c20_overflow;
  int32_T c20_k;
  int32_T c20_a;
  int32_T c20_b_a;
  c20_b_n = c20_n;
  c20_b_ix0 = c20_ix0;
  c20_b_iy0 = c20_iy0;
  c20_c_n = c20_b_n;
  c20_c_ix0 = c20_b_ix0;
  c20_c_iy0 = c20_b_iy0;
  c20_d_n = c20_c_n;
  c20_d_ix0 = c20_c_ix0;
  c20_d_iy0 = c20_c_iy0;
  c20_e_n = c20_d_n;
  c20_e_ix0 = c20_d_ix0;
  c20_e_iy0 = c20_d_iy0;
  c20_d = 0.0;
  if (c20_e_n < 1) {
  } else {
    c20_ix = c20_e_ix0;
    c20_iy = c20_e_iy0;
    c20_f_n = c20_e_n;
    c20_b = c20_f_n;
    c20_b_b = c20_b;
    if (1 > c20_b_b) {
      c20_overflow = FALSE;
    } else {
      c20_overflow = (c20_b_b > 2147483646);
    }

    if (c20_overflow) {
      c20_check_forloop_overflow_error(chartInstance, c20_overflow);
    }

    for (c20_k = 1; c20_k <= c20_f_n; c20_k++) {
      c20_d += c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", (real_T)c20_ix), 1, 18, 1, 0) - 1] *
        c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c20_iy), 1, 18, 1, 0) - 1];
      c20_a = c20_ix + 1;
      c20_ix = c20_a;
      c20_b_a = c20_iy + 1;
      c20_iy = c20_b_a;
    }
  }

  return c20_d;
}

static void c20_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, int32_T c20_ix0, real_T c20_y[18], int32_T
  c20_iy0, real_T c20_b_y[18])
{
  int32_T c20_i197;
  for (c20_i197 = 0; c20_i197 < 18; c20_i197++) {
    c20_b_y[c20_i197] = c20_y[c20_i197];
  }

  c20_h_eml_xaxpy(chartInstance, c20_n, c20_a, c20_ix0, c20_b_y, c20_iy0);
}

static real_T c20_b_eml_xnrm2(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, int32_T c20_n, real_T c20_x[3], int32_T c20_ix0)
{
  real_T c20_y;
  int32_T c20_b_n;
  int32_T c20_b_ix0;
  int32_T c20_c_n;
  int32_T c20_c_ix0;
  real_T c20_b_x;
  real_T c20_c_x;
  real_T c20_scale;
  int32_T c20_kstart;
  int32_T c20_a;
  int32_T c20_c;
  int32_T c20_b_a;
  int32_T c20_b_c;
  int32_T c20_c_a;
  int32_T c20_b;
  int32_T c20_kend;
  int32_T c20_b_kstart;
  int32_T c20_b_kend;
  int32_T c20_d_a;
  int32_T c20_b_b;
  int32_T c20_e_a;
  int32_T c20_c_b;
  boolean_T c20_overflow;
  int32_T c20_k;
  int32_T c20_b_k;
  real_T c20_d_x;
  real_T c20_e_x;
  real_T c20_absxk;
  real_T c20_t;
  c20_b_n = c20_n;
  c20_b_ix0 = c20_ix0;
  c20_c_n = c20_b_n;
  c20_c_ix0 = c20_b_ix0;
  c20_y = 0.0;
  if (c20_c_n < 1) {
  } else if (c20_c_n == 1) {
    c20_b_x = c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c20_c_ix0), 1, 3, 1, 0) - 1];
    c20_c_x = c20_b_x;
    c20_y = muDoubleScalarAbs(c20_c_x);
  } else {
    c20_realmin(chartInstance);
    c20_scale = 2.2250738585072014E-308;
    c20_kstart = c20_c_ix0;
    c20_a = c20_c_n;
    c20_c = c20_a;
    c20_b_a = c20_c - 1;
    c20_b_c = c20_b_a;
    c20_c_a = c20_kstart;
    c20_b = c20_b_c;
    c20_kend = c20_c_a + c20_b;
    c20_b_kstart = c20_kstart;
    c20_b_kend = c20_kend;
    c20_d_a = c20_b_kstart;
    c20_b_b = c20_b_kend;
    c20_e_a = c20_d_a;
    c20_c_b = c20_b_b;
    if (c20_e_a > c20_c_b) {
      c20_overflow = FALSE;
    } else {
      c20_overflow = (c20_c_b > 2147483646);
    }

    if (c20_overflow) {
      c20_check_forloop_overflow_error(chartInstance, c20_overflow);
    }

    for (c20_k = c20_b_kstart; c20_k <= c20_b_kend; c20_k++) {
      c20_b_k = c20_k;
      c20_d_x = c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 3, 1, 0) - 1];
      c20_e_x = c20_d_x;
      c20_absxk = muDoubleScalarAbs(c20_e_x);
      if (c20_absxk > c20_scale) {
        c20_t = c20_scale / c20_absxk;
        c20_y = 1.0 + c20_y * c20_t * c20_t;
        c20_scale = c20_absxk;
      } else {
        c20_t = c20_absxk / c20_scale;
        c20_y += c20_t * c20_t;
      }
    }

    c20_y = c20_scale * muDoubleScalarSqrt(c20_y);
  }

  return c20_y;
}

static void c20_b_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[3], int32_T c20_ix0, real_T c20_b_x
  [3])
{
  int32_T c20_i198;
  for (c20_i198 = 0; c20_i198 < 3; c20_i198++) {
    c20_b_x[c20_i198] = c20_x[c20_i198];
  }

  c20_i_eml_xscal(chartInstance, c20_n, c20_a, c20_b_x, c20_ix0);
}

static void c20_b_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[18], int32_T c20_ix0, real_T c20_y[6],
  int32_T c20_iy0, real_T c20_b_y[6])
{
  int32_T c20_i199;
  int32_T c20_i200;
  real_T c20_b_x[18];
  for (c20_i199 = 0; c20_i199 < 6; c20_i199++) {
    c20_b_y[c20_i199] = c20_y[c20_i199];
  }

  for (c20_i200 = 0; c20_i200 < 18; c20_i200++) {
    c20_b_x[c20_i200] = c20_x[c20_i200];
  }

  c20_i_eml_xaxpy(chartInstance, c20_n, c20_a, c20_b_x, c20_ix0, c20_b_y,
                  c20_iy0);
}

static void c20_c_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[6], int32_T c20_ix0, real_T c20_y[18],
  int32_T c20_iy0, real_T c20_b_y[18])
{
  int32_T c20_i201;
  int32_T c20_i202;
  real_T c20_b_x[6];
  for (c20_i201 = 0; c20_i201 < 18; c20_i201++) {
    c20_b_y[c20_i201] = c20_y[c20_i201];
  }

  for (c20_i202 = 0; c20_i202 < 6; c20_i202++) {
    c20_b_x[c20_i202] = c20_x[c20_i202];
  }

  c20_j_eml_xaxpy(chartInstance, c20_n, c20_a, c20_b_x, c20_ix0, c20_b_y,
                  c20_iy0);
}

static real_T c20_b_eml_xdotc(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, int32_T c20_n, real_T c20_x[9], int32_T c20_ix0, real_T c20_y
  [9], int32_T c20_iy0)
{
  real_T c20_d;
  int32_T c20_b_n;
  int32_T c20_b_ix0;
  int32_T c20_b_iy0;
  int32_T c20_c_n;
  int32_T c20_c_ix0;
  int32_T c20_c_iy0;
  int32_T c20_d_n;
  int32_T c20_d_ix0;
  int32_T c20_d_iy0;
  int32_T c20_e_n;
  int32_T c20_e_ix0;
  int32_T c20_e_iy0;
  int32_T c20_ix;
  int32_T c20_iy;
  int32_T c20_f_n;
  int32_T c20_b;
  int32_T c20_b_b;
  boolean_T c20_overflow;
  int32_T c20_k;
  int32_T c20_a;
  int32_T c20_b_a;
  c20_b_n = c20_n;
  c20_b_ix0 = c20_ix0;
  c20_b_iy0 = c20_iy0;
  c20_c_n = c20_b_n;
  c20_c_ix0 = c20_b_ix0;
  c20_c_iy0 = c20_b_iy0;
  c20_d_n = c20_c_n;
  c20_d_ix0 = c20_c_ix0;
  c20_d_iy0 = c20_c_iy0;
  c20_e_n = c20_d_n;
  c20_e_ix0 = c20_d_ix0;
  c20_e_iy0 = c20_d_iy0;
  c20_d = 0.0;
  if (c20_e_n < 1) {
  } else {
    c20_ix = c20_e_ix0;
    c20_iy = c20_e_iy0;
    c20_f_n = c20_e_n;
    c20_b = c20_f_n;
    c20_b_b = c20_b;
    if (1 > c20_b_b) {
      c20_overflow = FALSE;
    } else {
      c20_overflow = (c20_b_b > 2147483646);
    }

    if (c20_overflow) {
      c20_check_forloop_overflow_error(chartInstance, c20_overflow);
    }

    for (c20_k = 1; c20_k <= c20_f_n; c20_k++) {
      c20_d += c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", (real_T)c20_ix), 1, 9, 1, 0) - 1] *
        c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c20_iy), 1, 9, 1, 0) - 1];
      c20_a = c20_ix + 1;
      c20_ix = c20_a;
      c20_b_a = c20_iy + 1;
      c20_iy = c20_b_a;
    }
  }

  return c20_d;
}

static void c20_d_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, int32_T c20_ix0, real_T c20_y[9], int32_T c20_iy0,
  real_T c20_b_y[9])
{
  int32_T c20_i203;
  for (c20_i203 = 0; c20_i203 < 9; c20_i203++) {
    c20_b_y[c20_i203] = c20_y[c20_i203];
  }

  c20_k_eml_xaxpy(chartInstance, c20_n, c20_a, c20_ix0, c20_b_y, c20_iy0);
}

static void c20_g_eml_scalar_eg(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
}

static void c20_c_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_a, real_T c20_x[18], int32_T c20_ix0, real_T c20_b_x[18])
{
  int32_T c20_i204;
  for (c20_i204 = 0; c20_i204 < 18; c20_i204++) {
    c20_b_x[c20_i204] = c20_x[c20_i204];
  }

  c20_j_eml_xscal(chartInstance, c20_a, c20_b_x, c20_ix0);
}

static void c20_d_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_a, real_T c20_x[9], int32_T c20_ix0, real_T c20_b_x[9])
{
  int32_T c20_i205;
  for (c20_i205 = 0; c20_i205 < 9; c20_i205++) {
    c20_b_x[c20_i205] = c20_x[c20_i205];
  }

  c20_k_eml_xscal(chartInstance, c20_a, c20_b_x, c20_ix0);
}

static void c20_b_eml_error(SFc20_CusakisME4901arcsInstanceStruct *chartInstance)
{
  int32_T c20_i206;
  static char_T c20_cv4[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 's', 'v', 'd', '_', 'N', 'o', 'C', 'o', 'n', 'v', 'e', 'r',
    'g', 'e', 'n', 'c', 'e' };

  char_T c20_u[30];
  const mxArray *c20_y = NULL;
  for (c20_i206 = 0; c20_i206 < 30; c20_i206++) {
    c20_u[c20_i206] = c20_cv4[c20_i206];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 10, 0U, 1U, 0U, 2, 1, 30),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c20_y));
}

static real_T c20_sqrt(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x)
{
  real_T c20_b_x;
  c20_b_x = c20_x;
  c20_b_sqrt(chartInstance, &c20_b_x);
  return c20_b_x;
}

static void c20_c_eml_error(SFc20_CusakisME4901arcsInstanceStruct *chartInstance)
{
  int32_T c20_i207;
  static char_T c20_cv5[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c20_u[30];
  const mxArray *c20_y = NULL;
  int32_T c20_i208;
  static char_T c20_cv6[4] = { 's', 'q', 'r', 't' };

  char_T c20_b_u[4];
  const mxArray *c20_b_y = NULL;
  for (c20_i207 = 0; c20_i207 < 30; c20_i207++) {
    c20_u[c20_i207] = c20_cv5[c20_i207];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 10, 0U, 1U, 0U, 2, 1, 30),
                FALSE);
  for (c20_i208 = 0; c20_i208 < 4; c20_i208++) {
    c20_b_u[c20_i208] = c20_cv6[c20_i208];
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c20_y, 14, c20_b_y));
}

static void c20_eml_xrotg(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_a, real_T c20_b, real_T *c20_b_a, real_T *c20_b_b, real_T *c20_c,
  real_T *c20_s)
{
  *c20_b_a = c20_a;
  *c20_b_b = c20_b;
  c20_b_eml_xrotg(chartInstance, c20_b_a, c20_b_b, c20_c, c20_s);
}

static void c20_eml_xrot(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[9], int32_T c20_ix0, int32_T c20_iy0, real_T c20_c, real_T c20_s,
  real_T c20_b_x[9])
{
  int32_T c20_i209;
  for (c20_i209 = 0; c20_i209 < 9; c20_i209++) {
    c20_b_x[c20_i209] = c20_x[c20_i209];
  }

  c20_d_eml_xrot(chartInstance, c20_b_x, c20_ix0, c20_iy0, c20_c, c20_s);
}

static void c20_b_eml_xrot(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[18], int32_T c20_ix0, int32_T c20_iy0, real_T c20_c, real_T c20_s,
  real_T c20_b_x[18])
{
  int32_T c20_i210;
  for (c20_i210 = 0; c20_i210 < 18; c20_i210++) {
    c20_b_x[c20_i210] = c20_x[c20_i210];
  }

  c20_e_eml_xrot(chartInstance, c20_b_x, c20_ix0, c20_iy0, c20_c, c20_s);
}

static void c20_eml_xswap(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[9], int32_T c20_ix0, int32_T c20_iy0, real_T c20_b_x[9])
{
  int32_T c20_i211;
  for (c20_i211 = 0; c20_i211 < 9; c20_i211++) {
    c20_b_x[c20_i211] = c20_x[c20_i211];
  }

  c20_d_eml_xswap(chartInstance, c20_b_x, c20_ix0, c20_iy0);
}

static void c20_b_eml_xswap(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[18], int32_T c20_ix0, int32_T c20_iy0, real_T c20_b_x[18])
{
  int32_T c20_i212;
  for (c20_i212 = 0; c20_i212 < 18; c20_i212++) {
    c20_b_x[c20_i212] = c20_x[c20_i212];
  }

  c20_e_eml_xswap(chartInstance, c20_b_x, c20_ix0, c20_iy0);
}

static void c20_eml_xgemm(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_k, real_T c20_A[9], real_T c20_B[18], real_T c20_C[18], real_T
  c20_b_C[18])
{
  int32_T c20_i213;
  int32_T c20_i214;
  real_T c20_b_A[9];
  int32_T c20_i215;
  real_T c20_b_B[18];
  for (c20_i213 = 0; c20_i213 < 18; c20_i213++) {
    c20_b_C[c20_i213] = c20_C[c20_i213];
  }

  for (c20_i214 = 0; c20_i214 < 9; c20_i214++) {
    c20_b_A[c20_i214] = c20_A[c20_i214];
  }

  for (c20_i215 = 0; c20_i215 < 18; c20_i215++) {
    c20_b_B[c20_i215] = c20_B[c20_i215];
  }

  c20_c_eml_xgemm(chartInstance, c20_k, c20_b_A, c20_b_B, c20_b_C);
}

static void c20_h_eml_scalar_eg(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
}

static void c20_svd(SFc20_CusakisME4901arcsInstanceStruct *chartInstance, real_T
                    c20_A[18], real_T c20_U[3])
{
  int32_T c20_k;
  int32_T c20_b_k;
  real_T c20_x;
  real_T c20_b_x;
  boolean_T c20_b;
  boolean_T c20_b2;
  real_T c20_c_x;
  boolean_T c20_b_b;
  boolean_T c20_b3;
  boolean_T c20_c_b;
  int32_T c20_i216;
  real_T c20_b_A[18];
  for (c20_k = 1; c20_k < 19; c20_k++) {
    c20_b_k = c20_k;
    c20_x = c20_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_b_k), 1, 18, 1, 0) - 1];
    c20_b_x = c20_x;
    c20_b = muDoubleScalarIsInf(c20_b_x);
    c20_b2 = !c20_b;
    c20_c_x = c20_x;
    c20_b_b = muDoubleScalarIsNaN(c20_c_x);
    c20_b3 = !c20_b_b;
    c20_c_b = (c20_b2 && c20_b3);
    if (!c20_c_b) {
      c20_eml_error(chartInstance);
    }
  }

  for (c20_i216 = 0; c20_i216 < 18; c20_i216++) {
    c20_b_A[c20_i216] = c20_A[c20_i216];
  }

  c20_eml_matlab_zsvdc(chartInstance, c20_b_A, c20_U);
}

static void c20_eml_matlab_zsvdc(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, real_T c20_A[18], real_T c20_S[3])
{
  int32_T c20_i217;
  real_T c20_s[3];
  int32_T c20_i218;
  real_T c20_e[3];
  int32_T c20_i219;
  real_T c20_work[6];
  int32_T c20_q;
  int32_T c20_b_q;
  int32_T c20_a;
  int32_T c20_qp1;
  int32_T c20_b_a;
  int32_T c20_qm1;
  int32_T c20_b;
  int32_T c20_c;
  int32_T c20_c_a;
  int32_T c20_b_b;
  int32_T c20_qq;
  int32_T c20_c_b;
  int32_T c20_nmq;
  int32_T c20_d_a;
  int32_T c20_nmqp1;
  int32_T c20_i220;
  real_T c20_b_A[18];
  real_T c20_nrm;
  real_T c20_absx;
  real_T c20_d;
  real_T c20_y;
  real_T c20_d15;
  int32_T c20_b_qp1;
  boolean_T c20_overflow;
  int32_T c20_jj;
  int32_T c20_b_jj;
  int32_T c20_e_a;
  int32_T c20_b_c;
  int32_T c20_d_b;
  int32_T c20_c_c;
  int32_T c20_f_a;
  int32_T c20_e_b;
  int32_T c20_qjj;
  int32_T c20_i221;
  real_T c20_c_A[18];
  int32_T c20_i222;
  real_T c20_d_A[18];
  real_T c20_t;
  int32_T c20_f_b;
  int32_T c20_pmq;
  int32_T c20_i223;
  real_T c20_b_e[3];
  real_T c20_b_absx;
  real_T c20_b_d;
  real_T c20_b_y;
  real_T c20_d16;
  int32_T c20_c_qp1;
  boolean_T c20_b_overflow;
  int32_T c20_ii;
  int32_T c20_b_ii;
  int32_T c20_d_qp1;
  boolean_T c20_c_overflow;
  int32_T c20_c_jj;
  int32_T c20_g_a;
  int32_T c20_d_c;
  int32_T c20_g_b;
  int32_T c20_e_c;
  int32_T c20_h_a;
  int32_T c20_h_b;
  int32_T c20_qp1jj;
  int32_T c20_i224;
  real_T c20_e_A[18];
  int32_T c20_e_qp1;
  boolean_T c20_d_overflow;
  int32_T c20_d_jj;
  int32_T c20_i_a;
  int32_T c20_f_c;
  int32_T c20_i_b;
  int32_T c20_g_c;
  int32_T c20_j_a;
  int32_T c20_j_b;
  int32_T c20_i225;
  real_T c20_b_work[6];
  int32_T c20_b_m;
  int32_T c20_c_q;
  real_T c20_rt;
  real_T c20_r;
  int32_T c20_k_a;
  int32_T c20_h_c;
  int32_T c20_l_a;
  int32_T c20_i_c;
  real_T c20_m_a;
  real_T c20_k_b;
  real_T c20_c_y;
  real_T c20_iter;
  real_T c20_tiny;
  real_T c20_snorm;
  int32_T c20_c_ii;
  real_T c20_varargin_1;
  real_T c20_varargin_2;
  real_T c20_b_varargin_2;
  real_T c20_varargin_3;
  real_T c20_x;
  real_T c20_d_y;
  real_T c20_b_x;
  real_T c20_e_y;
  real_T c20_xk;
  real_T c20_yk;
  real_T c20_c_x;
  real_T c20_f_y;
  real_T c20_maxval;
  real_T c20_b_varargin_1;
  real_T c20_c_varargin_2;
  real_T c20_d_varargin_2;
  real_T c20_b_varargin_3;
  real_T c20_d_x;
  real_T c20_g_y;
  real_T c20_e_x;
  real_T c20_h_y;
  real_T c20_b_xk;
  real_T c20_b_yk;
  real_T c20_f_x;
  real_T c20_i_y;
  int32_T c20_n_a;
  int32_T c20_o_a;
  int32_T c20_i226;
  boolean_T c20_e_overflow;
  int32_T c20_d_ii;
  int32_T c20_p_a;
  int32_T c20_j_c;
  real_T c20_test0;
  real_T c20_ztest0;
  real_T c20_l_b;
  real_T c20_j_y;
  real_T c20_m_b;
  real_T c20_k_y;
  int32_T c20_q_a;
  int32_T c20_k_c;
  real_T c20_kase;
  int32_T c20_qs;
  int32_T c20_c_m;
  int32_T c20_d_q;
  int32_T c20_r_a;
  int32_T c20_n_b;
  int32_T c20_s_a;
  int32_T c20_o_b;
  boolean_T c20_f_overflow;
  int32_T c20_e_ii;
  real_T c20_test;
  int32_T c20_t_a;
  int32_T c20_l_c;
  int32_T c20_u_a;
  int32_T c20_m_c;
  real_T c20_ztest;
  real_T c20_p_b;
  real_T c20_l_y;
  int32_T c20_v_a;
  int32_T c20_w_a;
  int32_T c20_n_c;
  real_T c20_f;
  int32_T c20_x_a;
  int32_T c20_o_c;
  int32_T c20_y_a;
  int32_T c20_i227;
  int32_T c20_e_q;
  int32_T c20_ab_a;
  int32_T c20_q_b;
  int32_T c20_bb_a;
  int32_T c20_r_b;
  boolean_T c20_g_overflow;
  int32_T c20_k;
  int32_T c20_b_k;
  real_T c20_t1;
  real_T c20_b_t1;
  real_T c20_b_f;
  real_T c20_sn;
  real_T c20_cs;
  real_T c20_b_cs;
  real_T c20_b_sn;
  int32_T c20_cb_a;
  int32_T c20_km1;
  real_T c20_db_a;
  real_T c20_s_b;
  real_T c20_eb_a;
  real_T c20_t_b;
  real_T c20_m_y;
  int32_T c20_fb_a;
  int32_T c20_f_q;
  int32_T c20_d_m;
  int32_T c20_gb_a;
  int32_T c20_u_b;
  int32_T c20_hb_a;
  int32_T c20_v_b;
  boolean_T c20_h_overflow;
  int32_T c20_c_k;
  real_T c20_c_t1;
  real_T c20_unusedU0;
  real_T c20_c_sn;
  real_T c20_c_cs;
  real_T c20_ib_a;
  real_T c20_w_b;
  real_T c20_jb_a;
  real_T c20_x_b;
  real_T c20_n_y;
  int32_T c20_kb_a;
  int32_T c20_mm1;
  real_T c20_d17;
  real_T c20_d18;
  real_T c20_d19;
  real_T c20_d20;
  real_T c20_d21;
  real_T c20_c_varargin_1[5];
  int32_T c20_ixstart;
  real_T c20_mtmp;
  real_T c20_g_x;
  boolean_T c20_y_b;
  int32_T c20_ix;
  int32_T c20_b_ix;
  real_T c20_h_x;
  boolean_T c20_ab_b;
  int32_T c20_lb_a;
  int32_T c20_i228;
  boolean_T c20_i_overflow;
  int32_T c20_c_ix;
  real_T c20_mb_a;
  real_T c20_bb_b;
  boolean_T c20_p;
  real_T c20_b_mtmp;
  real_T c20_scale;
  real_T c20_sm;
  real_T c20_smm1;
  real_T c20_emm1;
  real_T c20_sqds;
  real_T c20_eqds;
  real_T c20_nb_a;
  real_T c20_cb_b;
  real_T c20_o_y;
  real_T c20_ob_a;
  real_T c20_db_b;
  real_T c20_p_y;
  real_T c20_eb_b;
  real_T c20_pb_a;
  real_T c20_fb_b;
  real_T c20_p_c;
  real_T c20_qb_a;
  real_T c20_gb_b;
  real_T c20_shift;
  real_T c20_rb_a;
  real_T c20_hb_b;
  real_T c20_q_y;
  real_T c20_sb_a;
  real_T c20_ib_b;
  real_T c20_r_y;
  real_T c20_tb_a;
  real_T c20_jb_b;
  real_T c20_g;
  int32_T c20_g_q;
  int32_T c20_b_mm1;
  int32_T c20_ub_a;
  int32_T c20_kb_b;
  int32_T c20_vb_a;
  int32_T c20_lb_b;
  boolean_T c20_j_overflow;
  int32_T c20_d_k;
  int32_T c20_wb_a;
  int32_T c20_xb_a;
  int32_T c20_kp1;
  real_T c20_c_f;
  real_T c20_unusedU1;
  real_T c20_d_sn;
  real_T c20_d_cs;
  real_T c20_yb_a;
  real_T c20_mb_b;
  real_T c20_s_y;
  real_T c20_ac_a;
  real_T c20_nb_b;
  real_T c20_t_y;
  real_T c20_bc_a;
  real_T c20_ob_b;
  real_T c20_u_y;
  real_T c20_cc_a;
  real_T c20_pb_b;
  real_T c20_v_y;
  real_T c20_dc_a;
  real_T c20_qb_b;
  real_T c20_ec_a;
  real_T c20_rb_b;
  real_T c20_w_y;
  real_T c20_d_f;
  real_T c20_unusedU2;
  real_T c20_e_sn;
  real_T c20_e_cs;
  real_T c20_fc_a;
  real_T c20_sb_b;
  real_T c20_x_y;
  real_T c20_gc_a;
  real_T c20_tb_b;
  real_T c20_y_y;
  real_T c20_hc_a;
  real_T c20_ub_b;
  real_T c20_ab_y;
  real_T c20_ic_a;
  real_T c20_vb_b;
  real_T c20_bb_y;
  real_T c20_jc_a;
  real_T c20_wb_b;
  real_T c20_kc_a;
  real_T c20_xb_b;
  real_T c20_cb_y;
  int32_T c20_lc_a;
  int32_T c20_q_c;
  int32_T c20_e_k;
  int32_T c20_mc_a;
  int32_T c20_nc_a;
  int32_T c20_oc_a;
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
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i217 = 0; c20_i217 < 3; c20_i217++) {
    c20_s[c20_i217] = 0.0;
  }

  for (c20_i218 = 0; c20_i218 < 3; c20_i218++) {
    c20_e[c20_i218] = 0.0;
  }

  for (c20_i219 = 0; c20_i219 < 6; c20_i219++) {
    c20_work[c20_i219] = 0.0;
  }

  for (c20_q = 1; c20_q < 4; c20_q++) {
    c20_b_q = c20_q;
    c20_a = c20_b_q + 1;
    c20_qp1 = c20_a;
    c20_b_a = c20_b_q;
    c20_qm1 = c20_b_a;
    c20_b = c20_qm1 - 1;
    c20_c = 6 * c20_b;
    c20_c_a = c20_b_q;
    c20_b_b = c20_c;
    c20_qq = c20_c_a + c20_b_b;
    c20_c_b = c20_b_q;
    c20_nmq = 6 - c20_c_b;
    c20_d_a = c20_nmq + 1;
    c20_nmqp1 = c20_d_a;
    if (c20_b_q <= 3) {
      for (c20_i220 = 0; c20_i220 < 18; c20_i220++) {
        c20_b_A[c20_i220] = c20_A[c20_i220];
      }

      c20_nrm = c20_eml_xnrm2(chartInstance, c20_nmqp1, c20_b_A, c20_qq);
      if (c20_nrm > 0.0) {
        c20_absx = c20_nrm;
        c20_d = c20_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_qq), 1, 18, 1, 0) - 1];
        if (c20_d < 0.0) {
          c20_y = -c20_absx;
        } else {
          c20_y = c20_absx;
        }

        c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 3, 1, 0) - 1] = c20_y;
        c20_d15 = c20_eml_div(chartInstance, 1.0,
                              c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 3, 1, 0) - 1]);
        c20_h_eml_xscal(chartInstance, c20_nmqp1, c20_d15, c20_A, c20_qq);
        c20_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_qq), 1, 18, 1, 0) - 1] = c20_A[_SFD_EML_ARRAY_BOUNDS_CHECK
          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_qq), 1, 18, 1, 0) - 1]
          + 1.0;
        c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 3, 1, 0) - 1] =
          -c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 3, 1, 0) - 1];
      } else {
        c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 3, 1, 0) - 1] = 0.0;
      }
    }

    c20_b_qp1 = c20_qp1;
    c20_overflow = FALSE;
    if (c20_overflow) {
      c20_check_forloop_overflow_error(chartInstance, c20_overflow);
    }

    for (c20_jj = c20_b_qp1; c20_jj < 4; c20_jj++) {
      c20_b_jj = c20_jj;
      c20_e_a = c20_b_jj;
      c20_b_c = c20_e_a;
      c20_d_b = c20_b_c - 1;
      c20_c_c = 6 * c20_d_b;
      c20_f_a = c20_b_q;
      c20_e_b = c20_c_c;
      c20_qjj = c20_f_a + c20_e_b;
      if (c20_b_q <= 3) {
        if (c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c20_b_q), 1, 3, 1, 0) - 1] != 0.0) {
          for (c20_i221 = 0; c20_i221 < 18; c20_i221++) {
            c20_c_A[c20_i221] = c20_A[c20_i221];
          }

          for (c20_i222 = 0; c20_i222 < 18; c20_i222++) {
            c20_d_A[c20_i222] = c20_A[c20_i222];
          }

          c20_t = c20_eml_xdotc(chartInstance, c20_nmqp1, c20_c_A, c20_qq,
                                c20_d_A, c20_qjj);
          c20_t = -c20_eml_div(chartInstance, c20_t, c20_A
                               [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 6, 1, 0) + 6 *
            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_q), 1, 3, 2, 0) - 1)) - 1]);
          c20_h_eml_xaxpy(chartInstance, c20_nmqp1, c20_t, c20_qq, c20_A,
                          c20_qjj);
        }
      }

      c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c20_b_jj), 1, 3, 1, 0) - 1] = c20_A[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_qjj), 1, 18, 1, 0) - 1];
    }

    if (c20_b_q <= 1) {
      c20_f_b = c20_b_q;
      c20_pmq = 3 - c20_f_b;
      for (c20_i223 = 0; c20_i223 < 3; c20_i223++) {
        c20_b_e[c20_i223] = c20_e[c20_i223];
      }

      c20_nrm = c20_b_eml_xnrm2(chartInstance, c20_pmq, c20_b_e, c20_qp1);
      if (c20_nrm == 0.0) {
        c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 3, 1, 0) - 1] = 0.0;
      } else {
        c20_b_absx = c20_nrm;
        c20_b_d = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_qp1), 1, 3, 1, 0) - 1];
        if (c20_b_d < 0.0) {
          c20_b_y = -c20_b_absx;
        } else {
          c20_b_y = c20_b_absx;
        }

        c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 3, 1, 0) - 1] = c20_b_y;
        c20_d16 = c20_eml_div(chartInstance, 1.0,
                              c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 3, 1, 0) - 1]);
        c20_i_eml_xscal(chartInstance, c20_pmq, c20_d16, c20_e, c20_qp1);
        c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_qp1), 1, 3, 1, 0) - 1] = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK
          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_qp1), 1, 3, 1, 0) - 1]
          + 1.0;
      }

      c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c20_b_q), 1, 3, 1, 0) - 1] = -c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 3, 1, 0) - 1];
      if (c20_qp1 <= 6) {
        if (c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c20_b_q), 1, 3, 1, 0) - 1] != 0.0) {
          c20_c_qp1 = c20_qp1;
          c20_b_overflow = FALSE;
          if (c20_b_overflow) {
            c20_check_forloop_overflow_error(chartInstance, c20_b_overflow);
          }

          for (c20_ii = c20_c_qp1; c20_ii < 7; c20_ii++) {
            c20_b_ii = c20_ii;
            c20_work[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
              ("", (real_T)c20_b_ii), 1, 6, 1, 0) - 1] = 0.0;
          }

          c20_d_qp1 = c20_qp1;
          c20_c_overflow = FALSE;
          if (c20_c_overflow) {
            c20_check_forloop_overflow_error(chartInstance, c20_c_overflow);
          }

          for (c20_c_jj = c20_d_qp1; c20_c_jj < 4; c20_c_jj++) {
            c20_b_jj = c20_c_jj;
            c20_g_a = c20_b_jj;
            c20_d_c = c20_g_a;
            c20_g_b = c20_d_c - 1;
            c20_e_c = 6 * c20_g_b;
            c20_h_a = c20_qp1;
            c20_h_b = c20_e_c;
            c20_qp1jj = c20_h_a + c20_h_b;
            for (c20_i224 = 0; c20_i224 < 18; c20_i224++) {
              c20_e_A[c20_i224] = c20_A[c20_i224];
            }

            c20_i_eml_xaxpy(chartInstance, c20_nmq,
                            c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c20_b_jj), 1, 3, 1, 0) - 1],
                            c20_e_A, c20_qp1jj, c20_work, c20_qp1);
          }

          c20_e_qp1 = c20_qp1;
          c20_d_overflow = FALSE;
          if (c20_d_overflow) {
            c20_check_forloop_overflow_error(chartInstance, c20_d_overflow);
          }

          for (c20_d_jj = c20_e_qp1; c20_d_jj < 4; c20_d_jj++) {
            c20_b_jj = c20_d_jj;
            c20_t = c20_eml_div(chartInstance,
                                -c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c20_b_jj), 1, 3, 1, 0) - 1],
                                c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c20_qp1), 1, 3, 1, 0) - 1]);
            c20_i_a = c20_b_jj;
            c20_f_c = c20_i_a;
            c20_i_b = c20_f_c - 1;
            c20_g_c = 6 * c20_i_b;
            c20_j_a = c20_qp1;
            c20_j_b = c20_g_c;
            c20_qp1jj = c20_j_a + c20_j_b;
            for (c20_i225 = 0; c20_i225 < 6; c20_i225++) {
              c20_b_work[c20_i225] = c20_work[c20_i225];
            }

            c20_j_eml_xaxpy(chartInstance, c20_nmq, c20_t, c20_b_work, c20_qp1,
                            c20_A, c20_qp1jj);
          }
        }
      }
    }
  }

  c20_b_m = 3;
  c20_e[1] = c20_A[13];
  c20_e[2] = 0.0;
  for (c20_c_q = 1; c20_c_q < 4; c20_c_q++) {
    c20_b_q = c20_c_q;
    if (c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 3, 1, 0) - 1] != 0.0) {
      c20_rt = c20_abs(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 3, 1, 0) - 1]);
      c20_r = c20_eml_div(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 3, 1, 0) - 1],
                          c20_rt);
      c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c20_b_q), 1, 3, 1, 0) - 1] = c20_rt;
      if (c20_b_q < 3) {
        c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 3, 1, 0) - 1] = c20_eml_div(chartInstance,
          c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 3, 1, 0) - 1], c20_r);
      }
    }

    if (c20_b_q < 3) {
      if (c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_q), 1, 3, 1, 0) - 1] != 0.0) {
        c20_rt = c20_abs(chartInstance, c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 3, 1, 0) - 1]);
        c20_r = c20_eml_div(chartInstance, c20_rt,
                            c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 3, 1, 0) - 1]);
        c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 3, 1, 0) - 1] = c20_rt;
        c20_k_a = c20_b_q;
        c20_h_c = c20_k_a;
        c20_l_a = c20_b_q;
        c20_i_c = c20_l_a;
        c20_m_a = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c20_i_c + 1)), 1, 3, 1, 0) - 1];
        c20_k_b = c20_r;
        c20_c_y = c20_m_a * c20_k_b;
        c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c20_h_c + 1)), 1, 3, 1, 0) - 1] = c20_c_y;
      }
    }
  }

  c20_iter = 0.0;
  c20_realmin(chartInstance);
  c20_eps(chartInstance);
  c20_tiny = c20_eml_div(chartInstance, 2.2250738585072014E-308,
    2.2204460492503131E-16);
  c20_snorm = 0.0;
  for (c20_c_ii = 1; c20_c_ii < 4; c20_c_ii++) {
    c20_b_ii = c20_c_ii;
    c20_varargin_1 = c20_abs(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_ii),
      1, 3, 1, 0) - 1]);
    c20_varargin_2 = c20_abs(chartInstance, c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_ii),
      1, 3, 1, 0) - 1]);
    c20_b_varargin_2 = c20_varargin_1;
    c20_varargin_3 = c20_varargin_2;
    c20_x = c20_b_varargin_2;
    c20_d_y = c20_varargin_3;
    c20_b_x = c20_x;
    c20_e_y = c20_d_y;
    c20_eml_scalar_eg(chartInstance);
    c20_xk = c20_b_x;
    c20_yk = c20_e_y;
    c20_c_x = c20_xk;
    c20_f_y = c20_yk;
    c20_eml_scalar_eg(chartInstance);
    c20_maxval = muDoubleScalarMax(c20_c_x, c20_f_y);
    c20_b_varargin_1 = c20_snorm;
    c20_c_varargin_2 = c20_maxval;
    c20_d_varargin_2 = c20_b_varargin_1;
    c20_b_varargin_3 = c20_c_varargin_2;
    c20_d_x = c20_d_varargin_2;
    c20_g_y = c20_b_varargin_3;
    c20_e_x = c20_d_x;
    c20_h_y = c20_g_y;
    c20_eml_scalar_eg(chartInstance);
    c20_b_xk = c20_e_x;
    c20_b_yk = c20_h_y;
    c20_f_x = c20_b_xk;
    c20_i_y = c20_b_yk;
    c20_eml_scalar_eg(chartInstance);
    c20_snorm = muDoubleScalarMax(c20_f_x, c20_i_y);
  }

  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c20_b_m > 0)) {
    if (c20_iter >= 75.0) {
      c20_b_eml_error(chartInstance);
      exitg1 = TRUE;
    } else {
      c20_n_a = c20_b_m - 1;
      c20_b_q = c20_n_a;
      c20_o_a = c20_b_m;
      c20_i226 = c20_o_a;
      c20_e_overflow = FALSE;
      if (c20_e_overflow) {
        c20_check_forloop_overflow_error(chartInstance, c20_e_overflow);
      }

      c20_d_ii = c20_i226 - 1;
      guard3 = FALSE;
      guard4 = FALSE;
      exitg5 = FALSE;
      while ((exitg5 == FALSE) && (c20_d_ii > -1)) {
        c20_b_ii = c20_d_ii;
        c20_b_q = c20_b_ii;
        if (c20_b_ii == 0) {
          exitg5 = TRUE;
        } else {
          c20_p_a = c20_b_ii;
          c20_j_c = c20_p_a;
          c20_test0 = c20_abs(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK(
            "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_ii), 1, 3, 1, 0) -
                              1]) + c20_abs(chartInstance,
            c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c20_j_c + 1)), 1, 3, 1, 0) - 1]);
          c20_ztest0 = c20_abs(chartInstance, c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
            "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_ii), 1, 3, 1, 0) -
                               1]);
          c20_eps(chartInstance);
          c20_l_b = c20_test0;
          c20_j_y = 2.2204460492503131E-16 * c20_l_b;
          if (c20_ztest0 <= c20_j_y) {
            guard4 = TRUE;
            exitg5 = TRUE;
          } else if (c20_ztest0 <= c20_tiny) {
            guard4 = TRUE;
            exitg5 = TRUE;
          } else {
            guard11 = FALSE;
            if (c20_iter > 20.0) {
              c20_eps(chartInstance);
              c20_m_b = c20_snorm;
              c20_k_y = 2.2204460492503131E-16 * c20_m_b;
              if (c20_ztest0 <= c20_k_y) {
                guard3 = TRUE;
                exitg5 = TRUE;
              } else {
                guard11 = TRUE;
              }
            } else {
              guard11 = TRUE;
            }

            if (guard11 == TRUE) {
              c20_d_ii--;
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
        c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_ii), 1, 3, 1, 0) - 1] = 0.0;
      }

      c20_q_a = c20_b_m;
      c20_k_c = c20_q_a;
      if (c20_b_q == c20_k_c - 1) {
        c20_kase = 4.0;
      } else {
        c20_qs = c20_b_m;
        c20_c_m = c20_b_m;
        c20_d_q = c20_b_q;
        c20_r_a = c20_c_m;
        c20_n_b = c20_d_q;
        c20_s_a = c20_r_a;
        c20_o_b = c20_n_b;
        if (c20_s_a < c20_o_b) {
          c20_f_overflow = FALSE;
        } else {
          c20_f_overflow = (c20_o_b < -2147483647);
        }

        if (c20_f_overflow) {
          c20_check_forloop_overflow_error(chartInstance, c20_f_overflow);
        }

        c20_e_ii = c20_c_m;
        guard2 = FALSE;
        exitg4 = FALSE;
        while ((exitg4 == FALSE) && (c20_e_ii >= c20_d_q)) {
          c20_b_ii = c20_e_ii;
          c20_qs = c20_b_ii;
          if (c20_b_ii == c20_b_q) {
            exitg4 = TRUE;
          } else {
            c20_test = 0.0;
            if (c20_b_ii < c20_b_m) {
              c20_test = c20_abs(chartInstance,
                                 c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c20_b_ii), 1, 3, 1, 0) - 1]);
            }

            c20_t_a = c20_b_q;
            c20_l_c = c20_t_a;
            if (c20_b_ii > c20_l_c + 1) {
              c20_u_a = c20_b_ii;
              c20_m_c = c20_u_a;
              c20_test += c20_abs(chartInstance,
                                  c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)(c20_m_c - 1)), 1, 3, 1, 0) - 1]);
            }

            c20_ztest = c20_abs(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK
                                ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
              c20_b_ii), 1, 3, 1, 0) - 1]);
            c20_eps(chartInstance);
            c20_p_b = c20_test;
            c20_l_y = 2.2204460492503131E-16 * c20_p_b;
            if (c20_ztest <= c20_l_y) {
              guard2 = TRUE;
              exitg4 = TRUE;
            } else if (c20_ztest <= c20_tiny) {
              guard2 = TRUE;
              exitg4 = TRUE;
            } else {
              c20_e_ii--;
              guard2 = FALSE;
            }
          }
        }

        if (guard2 == TRUE) {
          c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_ii), 1, 3, 1, 0) - 1] = 0.0;
        }

        if (c20_qs == c20_b_q) {
          c20_kase = 3.0;
        } else if (c20_qs == c20_b_m) {
          c20_kase = 1.0;
        } else {
          c20_kase = 2.0;
          c20_b_q = c20_qs;
        }
      }

      c20_v_a = c20_b_q + 1;
      c20_b_q = c20_v_a;
      switch ((int32_T)_SFD_INTEGER_CHECK("", c20_kase)) {
       case 1:
        c20_w_a = c20_b_m;
        c20_n_c = c20_w_a;
        c20_f = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c20_n_c - 1)), 1, 3, 1, 0) - 1];
        c20_x_a = c20_b_m;
        c20_o_c = c20_x_a;
        c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c20_o_c - 1)), 1, 3, 1, 0) - 1] = 0.0;
        c20_y_a = c20_b_m - 1;
        c20_i227 = c20_y_a;
        c20_e_q = c20_b_q;
        c20_ab_a = c20_i227;
        c20_q_b = c20_e_q;
        c20_bb_a = c20_ab_a;
        c20_r_b = c20_q_b;
        if (c20_bb_a < c20_r_b) {
          c20_g_overflow = FALSE;
        } else {
          c20_g_overflow = (c20_r_b < -2147483647);
        }

        if (c20_g_overflow) {
          c20_check_forloop_overflow_error(chartInstance, c20_g_overflow);
        }

        for (c20_k = c20_i227; c20_k >= c20_e_q; c20_k--) {
          c20_b_k = c20_k;
          c20_t1 = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 3, 1, 0) - 1];
          c20_b_t1 = c20_t1;
          c20_b_f = c20_f;
          c20_b_eml_xrotg(chartInstance, &c20_b_t1, &c20_b_f, &c20_cs, &c20_sn);
          c20_t1 = c20_b_t1;
          c20_f = c20_b_f;
          c20_b_cs = c20_cs;
          c20_b_sn = c20_sn;
          c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_k), 1, 3, 1, 0) - 1] = c20_t1;
          if (c20_b_k > c20_b_q) {
            c20_cb_a = c20_b_k - 1;
            c20_km1 = c20_cb_a;
            c20_db_a = -c20_b_sn;
            c20_s_b = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c20_km1), 1, 3, 1, 0) - 1];
            c20_f = c20_db_a * c20_s_b;
            c20_eb_a = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c20_km1), 1, 3, 1, 0) - 1];
            c20_t_b = c20_b_cs;
            c20_m_y = c20_eb_a * c20_t_b;
            c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c20_km1), 1, 3, 1, 0) - 1] = c20_m_y;
          }
        }
        break;

       case 2:
        c20_fb_a = c20_b_q - 1;
        c20_qm1 = c20_fb_a;
        c20_f = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_qm1), 1, 3, 1, 0) - 1];
        c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_qm1), 1, 3, 1, 0) - 1] = 0.0;
        c20_f_q = c20_b_q;
        c20_d_m = c20_b_m;
        c20_gb_a = c20_f_q;
        c20_u_b = c20_d_m;
        c20_hb_a = c20_gb_a;
        c20_v_b = c20_u_b;
        if (c20_hb_a > c20_v_b) {
          c20_h_overflow = FALSE;
        } else {
          c20_h_overflow = (c20_v_b > 2147483646);
        }

        if (c20_h_overflow) {
          c20_check_forloop_overflow_error(chartInstance, c20_h_overflow);
        }

        for (c20_c_k = c20_f_q; c20_c_k <= c20_d_m; c20_c_k++) {
          c20_b_k = c20_c_k;
          c20_t1 = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 3, 1, 0) - 1];
          c20_c_t1 = c20_t1;
          c20_unusedU0 = c20_f;
          c20_b_eml_xrotg(chartInstance, &c20_c_t1, &c20_unusedU0, &c20_c_cs,
                          &c20_c_sn);
          c20_t1 = c20_c_t1;
          c20_b_cs = c20_c_cs;
          c20_b_sn = c20_c_sn;
          c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_k), 1, 3, 1, 0) - 1] = c20_t1;
          c20_ib_a = -c20_b_sn;
          c20_w_b = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 3, 1, 0) - 1];
          c20_f = c20_ib_a * c20_w_b;
          c20_jb_a = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 3, 1, 0) - 1];
          c20_x_b = c20_b_cs;
          c20_n_y = c20_jb_a * c20_x_b;
          c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_k), 1, 3, 1, 0) - 1] = c20_n_y;
        }
        break;

       case 3:
        c20_kb_a = c20_b_m - 1;
        c20_mm1 = c20_kb_a;
        c20_d17 = c20_abs(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_m), 1, 3, 1, 0) - 1]);
        c20_d18 = c20_abs(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_mm1), 1, 3, 1, 0) - 1]);
        c20_d19 = c20_abs(chartInstance, c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_mm1), 1, 3, 1, 0) - 1]);
        c20_d20 = c20_abs(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 3, 1, 0) - 1]);
        c20_d21 = c20_abs(chartInstance, c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 3, 1, 0) - 1]);
        c20_c_varargin_1[0] = c20_d17;
        c20_c_varargin_1[1] = c20_d18;
        c20_c_varargin_1[2] = c20_d19;
        c20_c_varargin_1[3] = c20_d20;
        c20_c_varargin_1[4] = c20_d21;
        c20_ixstart = 1;
        c20_mtmp = c20_c_varargin_1[0];
        c20_g_x = c20_mtmp;
        c20_y_b = muDoubleScalarIsNaN(c20_g_x);
        if (c20_y_b) {
          c20_ix = 2;
          exitg2 = FALSE;
          while ((exitg2 == FALSE) && (c20_ix < 6)) {
            c20_b_ix = c20_ix;
            c20_ixstart = c20_b_ix;
            c20_h_x = c20_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c20_b_ix), 1, 5, 1, 0) - 1];
            c20_ab_b = muDoubleScalarIsNaN(c20_h_x);
            if (!c20_ab_b) {
              c20_mtmp = c20_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_ix), 1, 5, 1, 0) -
                1];
              exitg2 = TRUE;
            } else {
              c20_ix++;
            }
          }
        }

        if (c20_ixstart < 5) {
          c20_lb_a = c20_ixstart;
          c20_i228 = c20_lb_a;
          c20_i_overflow = FALSE;
          if (c20_i_overflow) {
            c20_check_forloop_overflow_error(chartInstance, c20_i_overflow);
          }

          for (c20_c_ix = c20_i228 + 1; c20_c_ix < 6; c20_c_ix++) {
            c20_b_ix = c20_c_ix;
            c20_mb_a = c20_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c20_b_ix), 1, 5, 1, 0) - 1];
            c20_bb_b = c20_mtmp;
            c20_p = (c20_mb_a > c20_bb_b);
            if (c20_p) {
              c20_mtmp = c20_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_ix), 1, 5, 1, 0) -
                1];
            }
          }
        }

        c20_b_mtmp = c20_mtmp;
        c20_scale = c20_b_mtmp;
        c20_sm = c20_eml_div(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_m),
          1, 3, 1, 0) - 1], c20_scale);
        c20_smm1 = c20_eml_div(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_mm1), 1, 3, 1, 0) - 1],
          c20_scale);
        c20_emm1 = c20_eml_div(chartInstance, c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_mm1), 1, 3, 1, 0) - 1],
          c20_scale);
        c20_sqds = c20_eml_div(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 3, 1, 0) - 1],
          c20_scale);
        c20_eqds = c20_eml_div(chartInstance, c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 3, 1, 0) - 1],
          c20_scale);
        c20_nb_a = c20_smm1 + c20_sm;
        c20_cb_b = c20_smm1 - c20_sm;
        c20_o_y = c20_nb_a * c20_cb_b;
        c20_ob_a = c20_emm1;
        c20_db_b = c20_emm1;
        c20_p_y = c20_ob_a * c20_db_b;
        c20_eb_b = c20_eml_div(chartInstance, c20_o_y + c20_p_y, 2.0);
        c20_pb_a = c20_sm;
        c20_fb_b = c20_emm1;
        c20_p_c = c20_pb_a * c20_fb_b;
        c20_qb_a = c20_p_c;
        c20_gb_b = c20_p_c;
        c20_p_c = c20_qb_a * c20_gb_b;
        c20_shift = 0.0;
        guard1 = FALSE;
        if (c20_eb_b != 0.0) {
          guard1 = TRUE;
        } else {
          if (c20_p_c != 0.0) {
            guard1 = TRUE;
          }
        }

        if (guard1 == TRUE) {
          c20_rb_a = c20_eb_b;
          c20_hb_b = c20_eb_b;
          c20_q_y = c20_rb_a * c20_hb_b;
          c20_shift = c20_q_y + c20_p_c;
          c20_b_sqrt(chartInstance, &c20_shift);
          if (c20_eb_b < 0.0) {
            c20_shift = -c20_shift;
          }

          c20_shift = c20_eml_div(chartInstance, c20_p_c, c20_eb_b + c20_shift);
        }

        c20_sb_a = c20_sqds + c20_sm;
        c20_ib_b = c20_sqds - c20_sm;
        c20_r_y = c20_sb_a * c20_ib_b;
        c20_f = c20_r_y + c20_shift;
        c20_tb_a = c20_sqds;
        c20_jb_b = c20_eqds;
        c20_g = c20_tb_a * c20_jb_b;
        c20_g_q = c20_b_q;
        c20_b_mm1 = c20_mm1;
        c20_ub_a = c20_g_q;
        c20_kb_b = c20_b_mm1;
        c20_vb_a = c20_ub_a;
        c20_lb_b = c20_kb_b;
        if (c20_vb_a > c20_lb_b) {
          c20_j_overflow = FALSE;
        } else {
          c20_j_overflow = (c20_lb_b > 2147483646);
        }

        if (c20_j_overflow) {
          c20_check_forloop_overflow_error(chartInstance, c20_j_overflow);
        }

        for (c20_d_k = c20_g_q; c20_d_k <= c20_b_mm1; c20_d_k++) {
          c20_b_k = c20_d_k;
          c20_wb_a = c20_b_k;
          c20_km1 = c20_wb_a;
          c20_xb_a = c20_b_k + 1;
          c20_kp1 = c20_xb_a;
          c20_c_f = c20_f;
          c20_unusedU1 = c20_g;
          c20_b_eml_xrotg(chartInstance, &c20_c_f, &c20_unusedU1, &c20_d_cs,
                          &c20_d_sn);
          c20_f = c20_c_f;
          c20_b_cs = c20_d_cs;
          c20_b_sn = c20_d_sn;
          if (c20_b_k > c20_b_q) {
            c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)(c20_km1 - 1)), 1, 3, 1, 0) - 1] = c20_f;
          }

          c20_yb_a = c20_b_cs;
          c20_mb_b = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 3, 1, 0) - 1];
          c20_s_y = c20_yb_a * c20_mb_b;
          c20_ac_a = c20_b_sn;
          c20_nb_b = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 3, 1, 0) - 1];
          c20_t_y = c20_ac_a * c20_nb_b;
          c20_f = c20_s_y + c20_t_y;
          c20_bc_a = c20_b_cs;
          c20_ob_b = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 3, 1, 0) - 1];
          c20_u_y = c20_bc_a * c20_ob_b;
          c20_cc_a = c20_b_sn;
          c20_pb_b = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 3, 1, 0) - 1];
          c20_v_y = c20_cc_a * c20_pb_b;
          c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_k), 1, 3, 1, 0) - 1] = c20_u_y - c20_v_y;
          c20_dc_a = c20_b_sn;
          c20_qb_b = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_kp1), 1, 3, 1, 0) - 1];
          c20_g = c20_dc_a * c20_qb_b;
          c20_ec_a = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_kp1), 1, 3, 1, 0) - 1];
          c20_rb_b = c20_b_cs;
          c20_w_y = c20_ec_a * c20_rb_b;
          c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_kp1), 1, 3, 1, 0) - 1] = c20_w_y;
          c20_d_f = c20_f;
          c20_unusedU2 = c20_g;
          c20_b_eml_xrotg(chartInstance, &c20_d_f, &c20_unusedU2, &c20_e_cs,
                          &c20_e_sn);
          c20_f = c20_d_f;
          c20_b_cs = c20_e_cs;
          c20_b_sn = c20_e_sn;
          c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_k), 1, 3, 1, 0) - 1] = c20_f;
          c20_fc_a = c20_b_cs;
          c20_sb_b = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 3, 1, 0) - 1];
          c20_x_y = c20_fc_a * c20_sb_b;
          c20_gc_a = c20_b_sn;
          c20_tb_b = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_kp1), 1, 3, 1, 0) - 1];
          c20_y_y = c20_gc_a * c20_tb_b;
          c20_f = c20_x_y + c20_y_y;
          c20_hc_a = -c20_b_sn;
          c20_ub_b = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 3, 1, 0) - 1];
          c20_ab_y = c20_hc_a * c20_ub_b;
          c20_ic_a = c20_b_cs;
          c20_vb_b = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_kp1), 1, 3, 1, 0) - 1];
          c20_bb_y = c20_ic_a * c20_vb_b;
          c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_kp1), 1, 3, 1, 0) - 1] = c20_ab_y + c20_bb_y;
          c20_jc_a = c20_b_sn;
          c20_wb_b = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_kp1), 1, 3, 1, 0) - 1];
          c20_g = c20_jc_a * c20_wb_b;
          c20_kc_a = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_kp1), 1, 3, 1, 0) - 1];
          c20_xb_b = c20_b_cs;
          c20_cb_y = c20_kc_a * c20_xb_b;
          c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_kp1), 1, 3, 1, 0) - 1] = c20_cb_y;
        }

        c20_lc_a = c20_b_m;
        c20_q_c = c20_lc_a;
        c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c20_q_c - 1)), 1, 3, 1, 0) - 1] = c20_f;
        c20_iter++;
        break;

       default:
        if (c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c20_b_q), 1, 3, 1, 0) - 1] < 0.0) {
          c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_q), 1, 3, 1, 0) - 1] =
            -c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c20_b_q), 1, 3, 1, 0) - 1];
        }

        c20_mc_a = c20_b_q + 1;
        c20_qp1 = c20_mc_a;
        exitg3 = FALSE;
        while ((exitg3 == FALSE) && (c20_b_q < 3)) {
          if (c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c20_b_q), 1, 3, 1, 0) - 1] <
              c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c20_qp1), 1, 3, 1, 0) - 1]) {
            c20_rt = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 3, 1, 0) - 1];
            c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c20_b_q), 1, 3, 1, 0) - 1] =
              c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c20_qp1), 1, 3, 1, 0) - 1];
            c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c20_qp1), 1, 3, 1, 0) - 1] = c20_rt;
            c20_b_q = c20_qp1;
            c20_oc_a = c20_b_q + 1;
            c20_qp1 = c20_oc_a;
          } else {
            exitg3 = TRUE;
          }
        }

        c20_iter = 0.0;
        c20_nc_a = c20_b_m - 1;
        c20_b_m = c20_nc_a;
        break;
      }
    }
  }

  for (c20_e_k = 1; c20_e_k < 4; c20_e_k++) {
    c20_b_k = c20_e_k;
    c20_S[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_b_k), 1, 3, 1, 0) - 1] = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 3, 1, 0) - 1];
  }
}

static void c20_i_eml_scalar_eg(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
}

static void c20_b_pinv(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_A[36], real_T c20_X[36])
{
  int32_T c20_i229;
  int32_T c20_k;
  int32_T c20_b_k;
  real_T c20_x;
  real_T c20_b_x;
  boolean_T c20_b;
  boolean_T c20_b4;
  real_T c20_c_x;
  boolean_T c20_b_b;
  boolean_T c20_b5;
  boolean_T c20_c_b;
  int32_T c20_i230;
  real_T c20_b_A[36];
  real_T c20_V[36];
  real_T c20_s[6];
  real_T c20_U[36];
  int32_T c20_i231;
  real_T c20_S[36];
  int32_T c20_c_k;
  real_T c20_d_k;
  real_T c20_d_b;
  real_T c20_y;
  real_T c20_a;
  real_T c20_tol;
  int32_T c20_r;
  int32_T c20_e_k;
  int32_T c20_f_k;
  int32_T c20_b_a;
  int32_T c20_vcol;
  int32_T c20_b_r;
  int32_T c20_e_b;
  int32_T c20_f_b;
  boolean_T c20_overflow;
  int32_T c20_j;
  int32_T c20_b_j;
  real_T c20_b_y;
  real_T c20_z;
  int32_T c20_c_a;
  int32_T c20_i232;
  real_T c20_b_V[36];
  int32_T c20_i233;
  real_T c20_b_U[36];
  boolean_T exitg1;
  for (c20_i229 = 0; c20_i229 < 36; c20_i229++) {
    c20_X[c20_i229] = 0.0;
  }

  for (c20_k = 1; c20_k < 37; c20_k++) {
    c20_b_k = c20_k;
    c20_x = c20_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_b_k), 1, 36, 1, 0) - 1];
    c20_b_x = c20_x;
    c20_b = muDoubleScalarIsInf(c20_b_x);
    c20_b4 = !c20_b;
    c20_c_x = c20_x;
    c20_b_b = muDoubleScalarIsNaN(c20_c_x);
    c20_b5 = !c20_b_b;
    c20_c_b = (c20_b4 && c20_b5);
    if (!c20_c_b) {
      c20_eml_error(chartInstance);
    }
  }

  for (c20_i230 = 0; c20_i230 < 36; c20_i230++) {
    c20_b_A[c20_i230] = c20_A[c20_i230];
  }

  c20_b_eml_xgesvd(chartInstance, c20_b_A, c20_U, c20_s, c20_V);
  for (c20_i231 = 0; c20_i231 < 36; c20_i231++) {
    c20_S[c20_i231] = 0.0;
  }

  for (c20_c_k = 0; c20_c_k < 6; c20_c_k++) {
    c20_d_k = 1.0 + (real_T)c20_c_k;
    c20_S[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c20_d_k), 1, 6, 1, 0) + 6 * ((int32_T)(real_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              c20_d_k), 1, 6, 2, 0) - 1)) - 1] = c20_s[(int32_T)(real_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c20_d_k),
      1, 6, 1, 0) - 1];
  }

  c20_eps(chartInstance);
  c20_d_b = c20_S[0];
  c20_y = 6.0 * c20_d_b;
  c20_a = c20_y;
  c20_tol = c20_a * 2.2204460492503131E-16;
  c20_r = 0;
  c20_e_k = 1;
  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c20_e_k < 7)) {
    c20_f_k = c20_e_k;
    if (!(c20_S[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_f_k), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_f_k), 1, 6, 2, 0) - 1))
          - 1] > c20_tol)) {
      exitg1 = TRUE;
    } else {
      c20_b_a = c20_r + 1;
      c20_r = c20_b_a;
      c20_e_k++;
    }
  }

  if (c20_r > 0) {
    c20_vcol = 1;
    c20_b_r = c20_r;
    c20_e_b = c20_b_r;
    c20_f_b = c20_e_b;
    if (1 > c20_f_b) {
      c20_overflow = FALSE;
    } else {
      c20_overflow = (c20_f_b > 2147483646);
    }

    if (c20_overflow) {
      c20_check_forloop_overflow_error(chartInstance, c20_overflow);
    }

    for (c20_j = 1; c20_j <= c20_b_r; c20_j++) {
      c20_b_j = c20_j;
      c20_b_y = c20_S[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c20_b_j), 1, 6, 1, 0) + 6 *
                       (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c20_b_j), 1, 6, 2, 0) - 1)) - 1];
      c20_z = 1.0 / c20_b_y;
      c20_n_eml_xscal(chartInstance, c20_z, c20_V, c20_vcol);
      c20_c_a = c20_vcol + 6;
      c20_vcol = c20_c_a;
    }

    for (c20_i232 = 0; c20_i232 < 36; c20_i232++) {
      c20_b_V[c20_i232] = c20_V[c20_i232];
    }

    for (c20_i233 = 0; c20_i233 < 36; c20_i233++) {
      c20_b_U[c20_i233] = c20_U[c20_i233];
    }

    c20_d_eml_xgemm(chartInstance, c20_r, c20_b_V, c20_b_U, c20_X);
  }
}

static void c20_b_eml_xgesvd(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, real_T c20_A[36], real_T c20_U[36], real_T c20_S[6], real_T
  c20_V[36])
{
  int32_T c20_i234;
  real_T c20_b_A[36];
  int32_T c20_i235;
  real_T c20_s[6];
  int32_T c20_i236;
  real_T c20_e[6];
  int32_T c20_i237;
  real_T c20_work[6];
  int32_T c20_i238;
  int32_T c20_i239;
  real_T c20_Vf[36];
  int32_T c20_q;
  int32_T c20_b_q;
  int32_T c20_a;
  int32_T c20_qp1;
  int32_T c20_b_a;
  int32_T c20_qm1;
  int32_T c20_b;
  int32_T c20_c;
  int32_T c20_c_a;
  int32_T c20_b_b;
  int32_T c20_qq;
  int32_T c20_c_b;
  int32_T c20_nmq;
  int32_T c20_d_a;
  int32_T c20_nmqp1;
  int32_T c20_i240;
  real_T c20_c_A[36];
  real_T c20_nrm;
  real_T c20_absx;
  real_T c20_d;
  real_T c20_y;
  real_T c20_d22;
  int32_T c20_b_qp1;
  boolean_T c20_overflow;
  int32_T c20_jj;
  int32_T c20_b_jj;
  int32_T c20_e_a;
  int32_T c20_b_c;
  int32_T c20_d_b;
  int32_T c20_c_c;
  int32_T c20_f_a;
  int32_T c20_e_b;
  int32_T c20_qjj;
  int32_T c20_i241;
  real_T c20_d_A[36];
  int32_T c20_i242;
  real_T c20_e_A[36];
  real_T c20_t;
  int32_T c20_c_q;
  boolean_T c20_b_overflow;
  int32_T c20_ii;
  int32_T c20_b_ii;
  int32_T c20_f_b;
  int32_T c20_pmq;
  int32_T c20_i243;
  real_T c20_b_e[6];
  real_T c20_b_absx;
  real_T c20_b_d;
  real_T c20_b_y;
  real_T c20_d23;
  int32_T c20_c_qp1;
  boolean_T c20_c_overflow;
  int32_T c20_c_ii;
  int32_T c20_d_qp1;
  boolean_T c20_d_overflow;
  int32_T c20_c_jj;
  int32_T c20_g_a;
  int32_T c20_d_c;
  int32_T c20_g_b;
  int32_T c20_e_c;
  int32_T c20_h_a;
  int32_T c20_h_b;
  int32_T c20_qp1jj;
  int32_T c20_i244;
  real_T c20_f_A[36];
  int32_T c20_e_qp1;
  boolean_T c20_e_overflow;
  int32_T c20_d_jj;
  int32_T c20_i_a;
  int32_T c20_f_c;
  int32_T c20_i_b;
  int32_T c20_g_c;
  int32_T c20_j_a;
  int32_T c20_j_b;
  int32_T c20_i245;
  real_T c20_b_work[6];
  int32_T c20_f_qp1;
  boolean_T c20_f_overflow;
  int32_T c20_d_ii;
  int32_T c20_b_m;
  int32_T c20_e_ii;
  int32_T c20_d_q;
  int32_T c20_k_a;
  int32_T c20_k_b;
  int32_T c20_l_a;
  int32_T c20_m_a;
  int32_T c20_h_c;
  int32_T c20_l_b;
  int32_T c20_i_c;
  int32_T c20_n_a;
  int32_T c20_m_b;
  int32_T c20_g_qp1;
  boolean_T c20_g_overflow;
  int32_T c20_e_jj;
  int32_T c20_o_a;
  int32_T c20_j_c;
  int32_T c20_n_b;
  int32_T c20_k_c;
  int32_T c20_p_a;
  int32_T c20_o_b;
  int32_T c20_i246;
  real_T c20_b_U[36];
  int32_T c20_i247;
  real_T c20_c_U[36];
  int32_T c20_e_q;
  boolean_T c20_h_overflow;
  int32_T c20_f_ii;
  int32_T c20_q_a;
  int32_T c20_i248;
  int32_T c20_p_b;
  int32_T c20_q_b;
  boolean_T c20_i_overflow;
  int32_T c20_g_ii;
  int32_T c20_h_ii;
  int32_T c20_f_q;
  int32_T c20_r_a;
  int32_T c20_r_b;
  int32_T c20_s_a;
  int32_T c20_l_c;
  int32_T c20_s_b;
  int32_T c20_m_c;
  int32_T c20_t_a;
  int32_T c20_t_b;
  int32_T c20_qp1q;
  int32_T c20_h_qp1;
  boolean_T c20_j_overflow;
  int32_T c20_f_jj;
  int32_T c20_u_a;
  int32_T c20_n_c;
  int32_T c20_u_b;
  int32_T c20_o_c;
  int32_T c20_v_a;
  int32_T c20_v_b;
  int32_T c20_i249;
  real_T c20_b_Vf[36];
  int32_T c20_i250;
  real_T c20_c_Vf[36];
  int32_T c20_i_ii;
  int32_T c20_g_q;
  real_T c20_rt;
  real_T c20_r;
  int32_T c20_w_a;
  int32_T c20_p_c;
  int32_T c20_w_b;
  int32_T c20_q_c;
  int32_T c20_x_b;
  int32_T c20_colq;
  int32_T c20_x_a;
  int32_T c20_r_c;
  int32_T c20_y_a;
  int32_T c20_s_c;
  real_T c20_ab_a;
  real_T c20_y_b;
  real_T c20_c_y;
  int32_T c20_ab_b;
  int32_T c20_t_c;
  int32_T c20_bb_b;
  int32_T c20_colqp1;
  real_T c20_iter;
  real_T c20_tiny;
  real_T c20_snorm;
  int32_T c20_j_ii;
  real_T c20_varargin_1;
  real_T c20_varargin_2;
  real_T c20_b_varargin_2;
  real_T c20_varargin_3;
  real_T c20_x;
  real_T c20_d_y;
  real_T c20_b_x;
  real_T c20_e_y;
  real_T c20_xk;
  real_T c20_yk;
  real_T c20_c_x;
  real_T c20_f_y;
  real_T c20_maxval;
  real_T c20_b_varargin_1;
  real_T c20_c_varargin_2;
  real_T c20_d_varargin_2;
  real_T c20_b_varargin_3;
  real_T c20_d_x;
  real_T c20_g_y;
  real_T c20_e_x;
  real_T c20_h_y;
  real_T c20_b_xk;
  real_T c20_b_yk;
  real_T c20_f_x;
  real_T c20_i_y;
  int32_T c20_bb_a;
  int32_T c20_cb_a;
  int32_T c20_i251;
  boolean_T c20_k_overflow;
  int32_T c20_k_ii;
  int32_T c20_db_a;
  int32_T c20_u_c;
  real_T c20_test0;
  real_T c20_ztest0;
  real_T c20_cb_b;
  real_T c20_j_y;
  real_T c20_db_b;
  real_T c20_k_y;
  int32_T c20_eb_a;
  int32_T c20_v_c;
  real_T c20_kase;
  int32_T c20_qs;
  int32_T c20_c_m;
  int32_T c20_h_q;
  int32_T c20_fb_a;
  int32_T c20_eb_b;
  int32_T c20_gb_a;
  int32_T c20_fb_b;
  boolean_T c20_l_overflow;
  int32_T c20_l_ii;
  real_T c20_test;
  int32_T c20_hb_a;
  int32_T c20_w_c;
  int32_T c20_ib_a;
  int32_T c20_x_c;
  real_T c20_ztest;
  real_T c20_gb_b;
  real_T c20_l_y;
  int32_T c20_jb_a;
  int32_T c20_kb_a;
  int32_T c20_y_c;
  real_T c20_f;
  int32_T c20_lb_a;
  int32_T c20_ab_c;
  int32_T c20_mb_a;
  int32_T c20_i252;
  int32_T c20_i_q;
  int32_T c20_nb_a;
  int32_T c20_hb_b;
  int32_T c20_ob_a;
  int32_T c20_ib_b;
  boolean_T c20_m_overflow;
  int32_T c20_k;
  int32_T c20_b_k;
  real_T c20_t1;
  real_T c20_b_t1;
  real_T c20_b_f;
  real_T c20_sn;
  real_T c20_cs;
  real_T c20_b_cs;
  real_T c20_b_sn;
  int32_T c20_pb_a;
  int32_T c20_km1;
  real_T c20_qb_a;
  real_T c20_jb_b;
  real_T c20_rb_a;
  real_T c20_kb_b;
  real_T c20_m_y;
  int32_T c20_sb_a;
  int32_T c20_bb_c;
  int32_T c20_lb_b;
  int32_T c20_cb_c;
  int32_T c20_mb_b;
  int32_T c20_colk;
  int32_T c20_tb_a;
  int32_T c20_db_c;
  int32_T c20_nb_b;
  int32_T c20_eb_c;
  int32_T c20_ob_b;
  int32_T c20_colm;
  int32_T c20_ub_a;
  int32_T c20_j_q;
  int32_T c20_d_m;
  int32_T c20_vb_a;
  int32_T c20_pb_b;
  int32_T c20_wb_a;
  int32_T c20_qb_b;
  boolean_T c20_n_overflow;
  int32_T c20_c_k;
  real_T c20_c_t1;
  real_T c20_unusedU0;
  real_T c20_c_sn;
  real_T c20_c_cs;
  real_T c20_xb_a;
  real_T c20_rb_b;
  real_T c20_yb_a;
  real_T c20_sb_b;
  real_T c20_n_y;
  int32_T c20_ac_a;
  int32_T c20_fb_c;
  int32_T c20_tb_b;
  int32_T c20_gb_c;
  int32_T c20_ub_b;
  int32_T c20_bc_a;
  int32_T c20_hb_c;
  int32_T c20_vb_b;
  int32_T c20_ib_c;
  int32_T c20_wb_b;
  int32_T c20_colqm1;
  int32_T c20_cc_a;
  int32_T c20_mm1;
  real_T c20_d24;
  real_T c20_d25;
  real_T c20_d26;
  real_T c20_d27;
  real_T c20_d28;
  real_T c20_c_varargin_1[5];
  int32_T c20_ixstart;
  real_T c20_mtmp;
  real_T c20_g_x;
  boolean_T c20_xb_b;
  int32_T c20_ix;
  int32_T c20_b_ix;
  real_T c20_h_x;
  boolean_T c20_yb_b;
  int32_T c20_dc_a;
  int32_T c20_i253;
  boolean_T c20_o_overflow;
  int32_T c20_c_ix;
  real_T c20_ec_a;
  real_T c20_ac_b;
  boolean_T c20_p;
  real_T c20_b_mtmp;
  real_T c20_scale;
  real_T c20_sm;
  real_T c20_smm1;
  real_T c20_emm1;
  real_T c20_sqds;
  real_T c20_eqds;
  real_T c20_fc_a;
  real_T c20_bc_b;
  real_T c20_o_y;
  real_T c20_gc_a;
  real_T c20_cc_b;
  real_T c20_p_y;
  real_T c20_dc_b;
  real_T c20_hc_a;
  real_T c20_ec_b;
  real_T c20_jb_c;
  real_T c20_ic_a;
  real_T c20_fc_b;
  real_T c20_shift;
  real_T c20_jc_a;
  real_T c20_gc_b;
  real_T c20_q_y;
  real_T c20_kc_a;
  real_T c20_hc_b;
  real_T c20_r_y;
  real_T c20_lc_a;
  real_T c20_ic_b;
  real_T c20_g;
  int32_T c20_k_q;
  int32_T c20_b_mm1;
  int32_T c20_mc_a;
  int32_T c20_jc_b;
  int32_T c20_nc_a;
  int32_T c20_kc_b;
  boolean_T c20_p_overflow;
  int32_T c20_d_k;
  int32_T c20_oc_a;
  int32_T c20_pc_a;
  int32_T c20_kp1;
  real_T c20_c_f;
  real_T c20_unusedU1;
  real_T c20_d_sn;
  real_T c20_d_cs;
  real_T c20_qc_a;
  real_T c20_lc_b;
  real_T c20_s_y;
  real_T c20_rc_a;
  real_T c20_mc_b;
  real_T c20_t_y;
  real_T c20_sc_a;
  real_T c20_nc_b;
  real_T c20_u_y;
  real_T c20_tc_a;
  real_T c20_oc_b;
  real_T c20_v_y;
  real_T c20_uc_a;
  real_T c20_pc_b;
  real_T c20_vc_a;
  real_T c20_qc_b;
  real_T c20_w_y;
  int32_T c20_wc_a;
  int32_T c20_kb_c;
  int32_T c20_rc_b;
  int32_T c20_lb_c;
  int32_T c20_sc_b;
  int32_T c20_tc_b;
  int32_T c20_mb_c;
  int32_T c20_uc_b;
  int32_T c20_colkp1;
  real_T c20_d_f;
  real_T c20_unusedU2;
  real_T c20_e_sn;
  real_T c20_e_cs;
  real_T c20_xc_a;
  real_T c20_vc_b;
  real_T c20_x_y;
  real_T c20_yc_a;
  real_T c20_wc_b;
  real_T c20_y_y;
  real_T c20_ad_a;
  real_T c20_xc_b;
  real_T c20_ab_y;
  real_T c20_bd_a;
  real_T c20_yc_b;
  real_T c20_bb_y;
  real_T c20_cd_a;
  real_T c20_ad_b;
  real_T c20_dd_a;
  real_T c20_bd_b;
  real_T c20_cb_y;
  int32_T c20_ed_a;
  int32_T c20_nb_c;
  int32_T c20_cd_b;
  int32_T c20_ob_c;
  int32_T c20_dd_b;
  int32_T c20_ed_b;
  int32_T c20_pb_c;
  int32_T c20_fd_b;
  int32_T c20_fd_a;
  int32_T c20_qb_c;
  int32_T c20_e_k;
  int32_T c20_j;
  int32_T c20_b_j;
  int32_T c20_i;
  int32_T c20_b_i;
  int32_T c20_rb_c;
  int32_T c20_gd_a;
  int32_T c20_sb_c;
  int32_T c20_gd_b;
  int32_T c20_hd_b;
  int32_T c20_hd_a;
  int32_T c20_id_a;
  int32_T c20_tb_c;
  int32_T c20_jd_a;
  int32_T c20_ub_c;
  int32_T c20_id_b;
  int32_T c20_jd_b;
  int32_T c20_vb_c;
  int32_T c20_kd_b;
  int32_T c20_ld_b;
  int32_T c20_wb_c;
  int32_T c20_kd_a;
  int32_T c20_xb_c;
  int32_T c20_md_b;
  int32_T c20_nd_b;
  int32_T c20_yb_c;
  int32_T c20_od_b;
  int32_T c20_pd_b;
  int32_T c20_ld_a;
  real_T c20_d29;
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
  for (c20_i234 = 0; c20_i234 < 36; c20_i234++) {
    c20_b_A[c20_i234] = c20_A[c20_i234];
  }

  c20_b_eml_scalar_eg(chartInstance);
  for (c20_i235 = 0; c20_i235 < 6; c20_i235++) {
    c20_s[c20_i235] = 0.0;
  }

  for (c20_i236 = 0; c20_i236 < 6; c20_i236++) {
    c20_e[c20_i236] = 0.0;
  }

  for (c20_i237 = 0; c20_i237 < 6; c20_i237++) {
    c20_work[c20_i237] = 0.0;
  }

  for (c20_i238 = 0; c20_i238 < 36; c20_i238++) {
    c20_U[c20_i238] = 0.0;
  }

  for (c20_i239 = 0; c20_i239 < 36; c20_i239++) {
    c20_Vf[c20_i239] = 0.0;
  }

  for (c20_q = 1; c20_q < 6; c20_q++) {
    c20_b_q = c20_q;
    c20_a = c20_b_q + 1;
    c20_qp1 = c20_a;
    c20_b_a = c20_b_q;
    c20_qm1 = c20_b_a;
    c20_b = c20_qm1 - 1;
    c20_c = 6 * c20_b;
    c20_c_a = c20_b_q;
    c20_b_b = c20_c;
    c20_qq = c20_c_a + c20_b_b;
    c20_c_b = c20_b_q;
    c20_nmq = 6 - c20_c_b;
    c20_d_a = c20_nmq + 1;
    c20_nmqp1 = c20_d_a;
    if (c20_b_q <= 5) {
      for (c20_i240 = 0; c20_i240 < 36; c20_i240++) {
        c20_c_A[c20_i240] = c20_b_A[c20_i240];
      }

      c20_nrm = c20_c_eml_xnrm2(chartInstance, c20_nmqp1, c20_c_A, c20_qq);
      if (c20_nrm > 0.0) {
        c20_absx = c20_nrm;
        c20_d = c20_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_qq), 1, 36, 1, 0) - 1];
        if (c20_d < 0.0) {
          c20_y = -c20_absx;
        } else {
          c20_y = c20_absx;
        }

        c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 6, 1, 0) - 1] = c20_y;
        c20_d22 = c20_eml_div(chartInstance, 1.0,
                              c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 6, 1, 0) - 1]);
        c20_l_eml_xscal(chartInstance, c20_nmqp1, c20_d22, c20_b_A, c20_qq);
        c20_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_qq), 1, 36, 1, 0) - 1] =
          c20_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_qq), 1, 36, 1, 0) - 1] + 1.0;
        c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 6, 1, 0) - 1] =
          -c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 6, 1, 0) - 1];
      } else {
        c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 6, 1, 0) - 1] = 0.0;
      }
    }

    c20_b_qp1 = c20_qp1;
    c20_overflow = FALSE;
    if (c20_overflow) {
      c20_check_forloop_overflow_error(chartInstance, c20_overflow);
    }

    for (c20_jj = c20_b_qp1; c20_jj < 7; c20_jj++) {
      c20_b_jj = c20_jj;
      c20_e_a = c20_b_jj;
      c20_b_c = c20_e_a;
      c20_d_b = c20_b_c - 1;
      c20_c_c = 6 * c20_d_b;
      c20_f_a = c20_b_q;
      c20_e_b = c20_c_c;
      c20_qjj = c20_f_a + c20_e_b;
      if (c20_b_q <= 5) {
        if (c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c20_b_q), 1, 6, 1, 0) - 1] != 0.0) {
          for (c20_i241 = 0; c20_i241 < 36; c20_i241++) {
            c20_d_A[c20_i241] = c20_b_A[c20_i241];
          }

          for (c20_i242 = 0; c20_i242 < 36; c20_i242++) {
            c20_e_A[c20_i242] = c20_b_A[c20_i242];
          }

          c20_t = c20_c_eml_xdotc(chartInstance, c20_nmqp1, c20_d_A, c20_qq,
            c20_e_A, c20_qjj);
          c20_t = -c20_eml_div(chartInstance, c20_t, c20_b_A
                               [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 6, 1, 0) + 6 *
            (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_q), 1, 6, 2, 0) - 1)) - 1]);
          c20_l_eml_xaxpy(chartInstance, c20_nmqp1, c20_t, c20_qq, c20_b_A,
                          c20_qjj);
        }
      }

      c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c20_b_jj), 1, 6, 1, 0) - 1] =
        c20_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c20_qjj), 1, 36, 1, 0) - 1];
    }

    if (c20_b_q <= 5) {
      c20_c_q = c20_b_q;
      c20_b_overflow = FALSE;
      if (c20_b_overflow) {
        c20_check_forloop_overflow_error(chartInstance, c20_b_overflow);
      }

      for (c20_ii = c20_c_q; c20_ii < 7; c20_ii++) {
        c20_b_ii = c20_ii;
        c20_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c20_b_ii), 1, 6, 1, 0) + 6 *
               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c20_b_q), 1, 6, 2, 0) - 1)) - 1] = c20_b_A
          [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c20_b_ii), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
              "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 6, 2, 0)
             - 1)) - 1];
      }
    }

    if (c20_b_q <= 4) {
      c20_f_b = c20_b_q;
      c20_pmq = 6 - c20_f_b;
      for (c20_i243 = 0; c20_i243 < 6; c20_i243++) {
        c20_b_e[c20_i243] = c20_e[c20_i243];
      }

      c20_nrm = c20_d_eml_xnrm2(chartInstance, c20_pmq, c20_b_e, c20_qp1);
      if (c20_nrm == 0.0) {
        c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 6, 1, 0) - 1] = 0.0;
      } else {
        c20_b_absx = c20_nrm;
        c20_b_d = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_qp1), 1, 6, 1, 0) - 1];
        if (c20_b_d < 0.0) {
          c20_b_y = -c20_b_absx;
        } else {
          c20_b_y = c20_b_absx;
        }

        c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 6, 1, 0) - 1] = c20_b_y;
        c20_d23 = c20_eml_div(chartInstance, 1.0,
                              c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 6, 1, 0) - 1]);
        c20_m_eml_xscal(chartInstance, c20_pmq, c20_d23, c20_e, c20_qp1);
        c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_qp1), 1, 6, 1, 0) - 1] = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK
          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_qp1), 1, 6, 1, 0) - 1]
          + 1.0;
      }

      c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c20_b_q), 1, 6, 1, 0) - 1] = -c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 6, 1, 0) - 1];
      if (c20_qp1 <= 6) {
        if (c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c20_b_q), 1, 6, 1, 0) - 1] != 0.0) {
          c20_c_qp1 = c20_qp1;
          c20_c_overflow = FALSE;
          if (c20_c_overflow) {
            c20_check_forloop_overflow_error(chartInstance, c20_c_overflow);
          }

          for (c20_c_ii = c20_c_qp1; c20_c_ii < 7; c20_c_ii++) {
            c20_b_ii = c20_c_ii;
            c20_work[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
              ("", (real_T)c20_b_ii), 1, 6, 1, 0) - 1] = 0.0;
          }

          c20_d_qp1 = c20_qp1;
          c20_d_overflow = FALSE;
          if (c20_d_overflow) {
            c20_check_forloop_overflow_error(chartInstance, c20_d_overflow);
          }

          for (c20_c_jj = c20_d_qp1; c20_c_jj < 7; c20_c_jj++) {
            c20_b_jj = c20_c_jj;
            c20_g_a = c20_b_jj;
            c20_d_c = c20_g_a;
            c20_g_b = c20_d_c - 1;
            c20_e_c = 6 * c20_g_b;
            c20_h_a = c20_qp1;
            c20_h_b = c20_e_c;
            c20_qp1jj = c20_h_a + c20_h_b;
            for (c20_i244 = 0; c20_i244 < 36; c20_i244++) {
              c20_f_A[c20_i244] = c20_b_A[c20_i244];
            }

            c20_m_eml_xaxpy(chartInstance, c20_nmq,
                            c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c20_b_jj), 1, 6, 1, 0) - 1],
                            c20_f_A, c20_qp1jj, c20_work, c20_qp1);
          }

          c20_e_qp1 = c20_qp1;
          c20_e_overflow = FALSE;
          if (c20_e_overflow) {
            c20_check_forloop_overflow_error(chartInstance, c20_e_overflow);
          }

          for (c20_d_jj = c20_e_qp1; c20_d_jj < 7; c20_d_jj++) {
            c20_b_jj = c20_d_jj;
            c20_t = c20_eml_div(chartInstance,
                                -c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c20_b_jj), 1, 6, 1, 0) - 1],
                                c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c20_qp1), 1, 6, 1, 0) - 1]);
            c20_i_a = c20_b_jj;
            c20_f_c = c20_i_a;
            c20_i_b = c20_f_c - 1;
            c20_g_c = 6 * c20_i_b;
            c20_j_a = c20_qp1;
            c20_j_b = c20_g_c;
            c20_qp1jj = c20_j_a + c20_j_b;
            for (c20_i245 = 0; c20_i245 < 6; c20_i245++) {
              c20_b_work[c20_i245] = c20_work[c20_i245];
            }

            c20_n_eml_xaxpy(chartInstance, c20_nmq, c20_t, c20_b_work, c20_qp1,
                            c20_b_A, c20_qp1jj);
          }
        }
      }

      c20_f_qp1 = c20_qp1;
      c20_f_overflow = FALSE;
      if (c20_f_overflow) {
        c20_check_forloop_overflow_error(chartInstance, c20_f_overflow);
      }

      for (c20_d_ii = c20_f_qp1; c20_d_ii < 7; c20_d_ii++) {
        c20_b_ii = c20_d_ii;
        c20_Vf[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c20_b_ii), 1, 6, 1, 0) + 6 *
                (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c20_b_q), 1, 6, 2, 0) - 1)) - 1] =
          c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_ii), 1, 6, 1, 0) - 1];
      }
    }
  }

  c20_b_m = 6;
  c20_s[5] = c20_b_A[35];
  c20_e[4] = c20_b_A[34];
  c20_e[5] = 0.0;
  for (c20_e_ii = 1; c20_e_ii < 7; c20_e_ii++) {
    c20_b_ii = c20_e_ii;
    c20_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_b_ii), 1, 6, 1, 0) + 29] = 0.0;
  }

  c20_U[35] = 1.0;
  for (c20_d_q = 5; c20_d_q > 0; c20_d_q--) {
    c20_b_q = c20_d_q;
    c20_k_a = c20_b_q;
    c20_qp1 = c20_k_a;
    c20_k_b = c20_b_q;
    c20_nmq = 6 - c20_k_b;
    c20_l_a = c20_nmq + 1;
    c20_nmqp1 = c20_l_a;
    c20_m_a = c20_b_q;
    c20_h_c = c20_m_a;
    c20_l_b = c20_h_c - 1;
    c20_i_c = 6 * c20_l_b;
    c20_n_a = c20_b_q;
    c20_m_b = c20_i_c;
    c20_qq = c20_n_a + c20_m_b;
    if (c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 6, 1, 0) - 1] != 0.0) {
      c20_g_qp1 = c20_qp1 + 1;
      c20_g_overflow = FALSE;
      if (c20_g_overflow) {
        c20_check_forloop_overflow_error(chartInstance, c20_g_overflow);
      }

      for (c20_e_jj = c20_g_qp1; c20_e_jj < 7; c20_e_jj++) {
        c20_b_jj = c20_e_jj;
        c20_o_a = c20_b_jj;
        c20_j_c = c20_o_a;
        c20_n_b = c20_j_c - 1;
        c20_k_c = 6 * c20_n_b;
        c20_p_a = c20_b_q;
        c20_o_b = c20_k_c;
        c20_qjj = c20_p_a + c20_o_b;
        for (c20_i246 = 0; c20_i246 < 36; c20_i246++) {
          c20_b_U[c20_i246] = c20_U[c20_i246];
        }

        for (c20_i247 = 0; c20_i247 < 36; c20_i247++) {
          c20_c_U[c20_i247] = c20_U[c20_i247];
        }

        c20_t = c20_c_eml_xdotc(chartInstance, c20_nmqp1, c20_b_U, c20_qq,
          c20_c_U, c20_qjj);
        c20_t = -c20_eml_div(chartInstance, c20_t,
                             c20_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_qq), 1, 36, 1, 0) - 1]);
        c20_l_eml_xaxpy(chartInstance, c20_nmqp1, c20_t, c20_qq, c20_U, c20_qjj);
      }

      c20_e_q = c20_b_q;
      c20_h_overflow = FALSE;
      if (c20_h_overflow) {
        c20_check_forloop_overflow_error(chartInstance, c20_h_overflow);
      }

      for (c20_f_ii = c20_e_q; c20_f_ii < 7; c20_f_ii++) {
        c20_b_ii = c20_f_ii;
        c20_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c20_b_ii), 1, 6, 1, 0) + 6 *
               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c20_b_q), 1, 6, 2, 0) - 1)) - 1] = -c20_U
          [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c20_b_ii), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
              "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 6, 2, 0)
             - 1)) - 1];
      }

      c20_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c20_qq), 1, 36, 1, 0) - 1] = c20_U[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_qq), 1, 36, 1, 0) - 1] +
        1.0;
      c20_q_a = c20_b_q - 1;
      c20_i248 = c20_q_a;
      c20_p_b = c20_i248;
      c20_q_b = c20_p_b;
      if (1 > c20_q_b) {
        c20_i_overflow = FALSE;
      } else {
        c20_i_overflow = (c20_q_b > 2147483646);
      }

      if (c20_i_overflow) {
        c20_check_forloop_overflow_error(chartInstance, c20_i_overflow);
      }

      for (c20_g_ii = 1; c20_g_ii <= c20_i248; c20_g_ii++) {
        c20_b_ii = c20_g_ii;
        c20_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c20_b_ii), 1, 6, 1, 0) + 6 *
               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c20_b_q), 1, 6, 2, 0) - 1)) - 1] = 0.0;
      }
    } else {
      for (c20_h_ii = 1; c20_h_ii < 7; c20_h_ii++) {
        c20_b_ii = c20_h_ii;
        c20_U[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c20_b_ii), 1, 6, 1, 0) + 6 *
               (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c20_b_q), 1, 6, 2, 0) - 1)) - 1] = 0.0;
      }

      c20_U[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c20_qq), 1, 36, 1, 0) - 1] = 1.0;
    }
  }

  for (c20_f_q = 6; c20_f_q > 0; c20_f_q--) {
    c20_b_q = c20_f_q;
    if (c20_b_q <= 4) {
      if (c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_q), 1, 6, 1, 0) - 1] != 0.0) {
        c20_r_a = c20_b_q + 1;
        c20_qp1 = c20_r_a;
        c20_r_b = c20_b_q;
        c20_pmq = 6 - c20_r_b;
        c20_s_a = c20_b_q;
        c20_l_c = c20_s_a;
        c20_s_b = c20_l_c - 1;
        c20_m_c = 6 * c20_s_b;
        c20_t_a = c20_qp1;
        c20_t_b = c20_m_c;
        c20_qp1q = c20_t_a + c20_t_b;
        c20_h_qp1 = c20_qp1;
        c20_j_overflow = FALSE;
        if (c20_j_overflow) {
          c20_check_forloop_overflow_error(chartInstance, c20_j_overflow);
        }

        for (c20_f_jj = c20_h_qp1; c20_f_jj < 7; c20_f_jj++) {
          c20_b_jj = c20_f_jj;
          c20_u_a = c20_b_jj;
          c20_n_c = c20_u_a;
          c20_u_b = c20_n_c - 1;
          c20_o_c = 6 * c20_u_b;
          c20_v_a = c20_qp1;
          c20_v_b = c20_o_c;
          c20_qp1jj = c20_v_a + c20_v_b;
          for (c20_i249 = 0; c20_i249 < 36; c20_i249++) {
            c20_b_Vf[c20_i249] = c20_Vf[c20_i249];
          }

          for (c20_i250 = 0; c20_i250 < 36; c20_i250++) {
            c20_c_Vf[c20_i250] = c20_Vf[c20_i250];
          }

          c20_t = c20_c_eml_xdotc(chartInstance, c20_pmq, c20_b_Vf, c20_qp1q,
            c20_c_Vf, c20_qp1jj);
          c20_t = -c20_eml_div(chartInstance, c20_t,
                               c20_Vf[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_qp1q), 1, 36, 1, 0) - 1]);
          c20_l_eml_xaxpy(chartInstance, c20_pmq, c20_t, c20_qp1q, c20_Vf,
                          c20_qp1jj);
        }
      }
    }

    for (c20_i_ii = 1; c20_i_ii < 7; c20_i_ii++) {
      c20_b_ii = c20_i_ii;
      c20_Vf[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c20_b_ii), 1, 6, 1, 0) + 6 *
              (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c20_b_q), 1, 6, 2, 0) - 1)) - 1] = 0.0;
    }

    c20_Vf[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c20_b_q), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
              "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 6, 2, 0)
             - 1)) - 1] = 1.0;
  }

  for (c20_g_q = 1; c20_g_q < 7; c20_g_q++) {
    c20_b_q = c20_g_q;
    if (c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 6, 1, 0) - 1] != 0.0) {
      c20_rt = c20_abs(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 6, 1, 0) - 1]);
      c20_r = c20_eml_div(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 6, 1, 0) - 1],
                          c20_rt);
      c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c20_b_q), 1, 6, 1, 0) - 1] = c20_rt;
      if (c20_b_q < 6) {
        c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 6, 1, 0) - 1] = c20_eml_div(chartInstance,
          c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 6, 1, 0) - 1], c20_r);
      }

      if (c20_b_q <= 6) {
        c20_w_a = c20_b_q;
        c20_p_c = c20_w_a;
        c20_w_b = c20_p_c - 1;
        c20_q_c = 6 * c20_w_b;
        c20_x_b = c20_q_c;
        c20_colq = c20_x_b;
        c20_n_eml_xscal(chartInstance, c20_r, c20_U, c20_colq + 1);
      }
    }

    if (c20_b_q < 6) {
      if (c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_q), 1, 6, 1, 0) - 1] != 0.0) {
        c20_rt = c20_abs(chartInstance, c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 6, 1, 0) - 1]);
        c20_r = c20_eml_div(chartInstance, c20_rt,
                            c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 6, 1, 0) - 1]);
        c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_q), 1, 6, 1, 0) - 1] = c20_rt;
        c20_x_a = c20_b_q;
        c20_r_c = c20_x_a;
        c20_y_a = c20_b_q;
        c20_s_c = c20_y_a;
        c20_ab_a = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c20_s_c + 1)), 1, 6, 1, 0) - 1];
        c20_y_b = c20_r;
        c20_c_y = c20_ab_a * c20_y_b;
        c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c20_r_c + 1)), 1, 6, 1, 0) - 1] = c20_c_y;
        c20_ab_b = c20_b_q;
        c20_t_c = 6 * c20_ab_b;
        c20_bb_b = c20_t_c;
        c20_colqp1 = c20_bb_b;
        c20_n_eml_xscal(chartInstance, c20_r, c20_Vf, c20_colqp1 + 1);
      }
    }
  }

  c20_iter = 0.0;
  c20_realmin(chartInstance);
  c20_eps(chartInstance);
  c20_tiny = c20_eml_div(chartInstance, 2.2250738585072014E-308,
    2.2204460492503131E-16);
  c20_snorm = 0.0;
  for (c20_j_ii = 1; c20_j_ii < 7; c20_j_ii++) {
    c20_b_ii = c20_j_ii;
    c20_varargin_1 = c20_abs(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_ii),
      1, 6, 1, 0) - 1]);
    c20_varargin_2 = c20_abs(chartInstance, c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_ii),
      1, 6, 1, 0) - 1]);
    c20_b_varargin_2 = c20_varargin_1;
    c20_varargin_3 = c20_varargin_2;
    c20_x = c20_b_varargin_2;
    c20_d_y = c20_varargin_3;
    c20_b_x = c20_x;
    c20_e_y = c20_d_y;
    c20_eml_scalar_eg(chartInstance);
    c20_xk = c20_b_x;
    c20_yk = c20_e_y;
    c20_c_x = c20_xk;
    c20_f_y = c20_yk;
    c20_eml_scalar_eg(chartInstance);
    c20_maxval = muDoubleScalarMax(c20_c_x, c20_f_y);
    c20_b_varargin_1 = c20_snorm;
    c20_c_varargin_2 = c20_maxval;
    c20_d_varargin_2 = c20_b_varargin_1;
    c20_b_varargin_3 = c20_c_varargin_2;
    c20_d_x = c20_d_varargin_2;
    c20_g_y = c20_b_varargin_3;
    c20_e_x = c20_d_x;
    c20_h_y = c20_g_y;
    c20_eml_scalar_eg(chartInstance);
    c20_b_xk = c20_e_x;
    c20_b_yk = c20_h_y;
    c20_f_x = c20_b_xk;
    c20_i_y = c20_b_yk;
    c20_eml_scalar_eg(chartInstance);
    c20_snorm = muDoubleScalarMax(c20_f_x, c20_i_y);
  }

  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c20_b_m > 0)) {
    if (c20_iter >= 75.0) {
      c20_b_eml_error(chartInstance);
      exitg1 = TRUE;
    } else {
      c20_bb_a = c20_b_m - 1;
      c20_b_q = c20_bb_a;
      c20_cb_a = c20_b_m;
      c20_i251 = c20_cb_a;
      c20_k_overflow = FALSE;
      if (c20_k_overflow) {
        c20_check_forloop_overflow_error(chartInstance, c20_k_overflow);
      }

      c20_k_ii = c20_i251 - 1;
      guard3 = FALSE;
      guard4 = FALSE;
      exitg5 = FALSE;
      while ((exitg5 == FALSE) && (c20_k_ii > -1)) {
        c20_b_ii = c20_k_ii;
        c20_b_q = c20_b_ii;
        if (c20_b_ii == 0) {
          exitg5 = TRUE;
        } else {
          c20_db_a = c20_b_ii;
          c20_u_c = c20_db_a;
          c20_test0 = c20_abs(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK(
            "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_ii), 1, 6, 1, 0) -
                              1]) + c20_abs(chartInstance,
            c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c20_u_c + 1)), 1, 6, 1, 0) - 1]);
          c20_ztest0 = c20_abs(chartInstance, c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
            "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_ii), 1, 6, 1, 0) -
                               1]);
          c20_eps(chartInstance);
          c20_cb_b = c20_test0;
          c20_j_y = 2.2204460492503131E-16 * c20_cb_b;
          if (c20_ztest0 <= c20_j_y) {
            guard4 = TRUE;
            exitg5 = TRUE;
          } else if (c20_ztest0 <= c20_tiny) {
            guard4 = TRUE;
            exitg5 = TRUE;
          } else {
            guard11 = FALSE;
            if (c20_iter > 20.0) {
              c20_eps(chartInstance);
              c20_db_b = c20_snorm;
              c20_k_y = 2.2204460492503131E-16 * c20_db_b;
              if (c20_ztest0 <= c20_k_y) {
                guard3 = TRUE;
                exitg5 = TRUE;
              } else {
                guard11 = TRUE;
              }
            } else {
              guard11 = TRUE;
            }

            if (guard11 == TRUE) {
              c20_k_ii--;
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
        c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_ii), 1, 6, 1, 0) - 1] = 0.0;
      }

      c20_eb_a = c20_b_m;
      c20_v_c = c20_eb_a;
      if (c20_b_q == c20_v_c - 1) {
        c20_kase = 4.0;
      } else {
        c20_qs = c20_b_m;
        c20_c_m = c20_b_m;
        c20_h_q = c20_b_q;
        c20_fb_a = c20_c_m;
        c20_eb_b = c20_h_q;
        c20_gb_a = c20_fb_a;
        c20_fb_b = c20_eb_b;
        if (c20_gb_a < c20_fb_b) {
          c20_l_overflow = FALSE;
        } else {
          c20_l_overflow = (c20_fb_b < -2147483647);
        }

        if (c20_l_overflow) {
          c20_check_forloop_overflow_error(chartInstance, c20_l_overflow);
        }

        c20_l_ii = c20_c_m;
        guard2 = FALSE;
        exitg4 = FALSE;
        while ((exitg4 == FALSE) && (c20_l_ii >= c20_h_q)) {
          c20_b_ii = c20_l_ii;
          c20_qs = c20_b_ii;
          if (c20_b_ii == c20_b_q) {
            exitg4 = TRUE;
          } else {
            c20_test = 0.0;
            if (c20_b_ii < c20_b_m) {
              c20_test = c20_abs(chartInstance,
                                 c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c20_b_ii), 1, 6, 1, 0) - 1]);
            }

            c20_hb_a = c20_b_q;
            c20_w_c = c20_hb_a;
            if (c20_b_ii > c20_w_c + 1) {
              c20_ib_a = c20_b_ii;
              c20_x_c = c20_ib_a;
              c20_test += c20_abs(chartInstance,
                                  c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)(c20_x_c - 1)), 1, 6, 1, 0) - 1]);
            }

            c20_ztest = c20_abs(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK
                                ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
              c20_b_ii), 1, 6, 1, 0) - 1]);
            c20_eps(chartInstance);
            c20_gb_b = c20_test;
            c20_l_y = 2.2204460492503131E-16 * c20_gb_b;
            if (c20_ztest <= c20_l_y) {
              guard2 = TRUE;
              exitg4 = TRUE;
            } else if (c20_ztest <= c20_tiny) {
              guard2 = TRUE;
              exitg4 = TRUE;
            } else {
              c20_l_ii--;
              guard2 = FALSE;
            }
          }
        }

        if (guard2 == TRUE) {
          c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_ii), 1, 6, 1, 0) - 1] = 0.0;
        }

        if (c20_qs == c20_b_q) {
          c20_kase = 3.0;
        } else if (c20_qs == c20_b_m) {
          c20_kase = 1.0;
        } else {
          c20_kase = 2.0;
          c20_b_q = c20_qs;
        }
      }

      c20_jb_a = c20_b_q + 1;
      c20_b_q = c20_jb_a;
      switch ((int32_T)_SFD_INTEGER_CHECK("", c20_kase)) {
       case 1:
        c20_kb_a = c20_b_m;
        c20_y_c = c20_kb_a;
        c20_f = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)(c20_y_c - 1)), 1, 6, 1, 0) - 1];
        c20_lb_a = c20_b_m;
        c20_ab_c = c20_lb_a;
        c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c20_ab_c - 1)), 1, 6, 1, 0) - 1] = 0.0;
        c20_mb_a = c20_b_m - 1;
        c20_i252 = c20_mb_a;
        c20_i_q = c20_b_q;
        c20_nb_a = c20_i252;
        c20_hb_b = c20_i_q;
        c20_ob_a = c20_nb_a;
        c20_ib_b = c20_hb_b;
        if (c20_ob_a < c20_ib_b) {
          c20_m_overflow = FALSE;
        } else {
          c20_m_overflow = (c20_ib_b < -2147483647);
        }

        if (c20_m_overflow) {
          c20_check_forloop_overflow_error(chartInstance, c20_m_overflow);
        }

        for (c20_k = c20_i252; c20_k >= c20_i_q; c20_k--) {
          c20_b_k = c20_k;
          c20_t1 = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 6, 1, 0) - 1];
          c20_b_t1 = c20_t1;
          c20_b_f = c20_f;
          c20_b_eml_xrotg(chartInstance, &c20_b_t1, &c20_b_f, &c20_cs, &c20_sn);
          c20_t1 = c20_b_t1;
          c20_f = c20_b_f;
          c20_b_cs = c20_cs;
          c20_b_sn = c20_sn;
          c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_k), 1, 6, 1, 0) - 1] = c20_t1;
          if (c20_b_k > c20_b_q) {
            c20_pb_a = c20_b_k - 1;
            c20_km1 = c20_pb_a;
            c20_qb_a = -c20_b_sn;
            c20_jb_b = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c20_km1), 1, 6, 1, 0) - 1];
            c20_f = c20_qb_a * c20_jb_b;
            c20_rb_a = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c20_km1), 1, 6, 1, 0) - 1];
            c20_kb_b = c20_b_cs;
            c20_m_y = c20_rb_a * c20_kb_b;
            c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c20_km1), 1, 6, 1, 0) - 1] = c20_m_y;
          }

          c20_sb_a = c20_b_k;
          c20_bb_c = c20_sb_a;
          c20_lb_b = c20_bb_c - 1;
          c20_cb_c = 6 * c20_lb_b;
          c20_mb_b = c20_cb_c;
          c20_colk = c20_mb_b;
          c20_tb_a = c20_b_m;
          c20_db_c = c20_tb_a;
          c20_nb_b = c20_db_c - 1;
          c20_eb_c = 6 * c20_nb_b;
          c20_ob_b = c20_eb_c;
          c20_colm = c20_ob_b;
          c20_f_eml_xrot(chartInstance, c20_Vf, c20_colk + 1, c20_colm + 1,
                         c20_b_cs, c20_b_sn);
        }
        break;

       case 2:
        c20_ub_a = c20_b_q - 1;
        c20_qm1 = c20_ub_a;
        c20_f = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_qm1), 1, 6, 1, 0) - 1];
        c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_qm1), 1, 6, 1, 0) - 1] = 0.0;
        c20_j_q = c20_b_q;
        c20_d_m = c20_b_m;
        c20_vb_a = c20_j_q;
        c20_pb_b = c20_d_m;
        c20_wb_a = c20_vb_a;
        c20_qb_b = c20_pb_b;
        if (c20_wb_a > c20_qb_b) {
          c20_n_overflow = FALSE;
        } else {
          c20_n_overflow = (c20_qb_b > 2147483646);
        }

        if (c20_n_overflow) {
          c20_check_forloop_overflow_error(chartInstance, c20_n_overflow);
        }

        for (c20_c_k = c20_j_q; c20_c_k <= c20_d_m; c20_c_k++) {
          c20_b_k = c20_c_k;
          c20_t1 = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 6, 1, 0) - 1];
          c20_c_t1 = c20_t1;
          c20_unusedU0 = c20_f;
          c20_b_eml_xrotg(chartInstance, &c20_c_t1, &c20_unusedU0, &c20_c_cs,
                          &c20_c_sn);
          c20_t1 = c20_c_t1;
          c20_b_cs = c20_c_cs;
          c20_b_sn = c20_c_sn;
          c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_k), 1, 6, 1, 0) - 1] = c20_t1;
          c20_xb_a = -c20_b_sn;
          c20_rb_b = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 6, 1, 0) - 1];
          c20_f = c20_xb_a * c20_rb_b;
          c20_yb_a = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 6, 1, 0) - 1];
          c20_sb_b = c20_b_cs;
          c20_n_y = c20_yb_a * c20_sb_b;
          c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_k), 1, 6, 1, 0) - 1] = c20_n_y;
          c20_ac_a = c20_b_k;
          c20_fb_c = c20_ac_a;
          c20_tb_b = c20_fb_c - 1;
          c20_gb_c = 6 * c20_tb_b;
          c20_ub_b = c20_gb_c;
          c20_colk = c20_ub_b;
          c20_bc_a = c20_qm1;
          c20_hb_c = c20_bc_a;
          c20_vb_b = c20_hb_c - 1;
          c20_ib_c = 6 * c20_vb_b;
          c20_wb_b = c20_ib_c;
          c20_colqm1 = c20_wb_b;
          c20_f_eml_xrot(chartInstance, c20_U, c20_colk + 1, c20_colqm1 + 1,
                         c20_b_cs, c20_b_sn);
        }
        break;

       case 3:
        c20_cc_a = c20_b_m - 1;
        c20_mm1 = c20_cc_a;
        c20_d24 = c20_abs(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_m), 1, 6, 1, 0) - 1]);
        c20_d25 = c20_abs(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_mm1), 1, 6, 1, 0) - 1]);
        c20_d26 = c20_abs(chartInstance, c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_mm1), 1, 6, 1, 0) - 1]);
        c20_d27 = c20_abs(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 6, 1, 0) - 1]);
        c20_d28 = c20_abs(chartInstance, c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 6, 1, 0) - 1]);
        c20_c_varargin_1[0] = c20_d24;
        c20_c_varargin_1[1] = c20_d25;
        c20_c_varargin_1[2] = c20_d26;
        c20_c_varargin_1[3] = c20_d27;
        c20_c_varargin_1[4] = c20_d28;
        c20_ixstart = 1;
        c20_mtmp = c20_c_varargin_1[0];
        c20_g_x = c20_mtmp;
        c20_xb_b = muDoubleScalarIsNaN(c20_g_x);
        if (c20_xb_b) {
          c20_ix = 2;
          exitg2 = FALSE;
          while ((exitg2 == FALSE) && (c20_ix < 6)) {
            c20_b_ix = c20_ix;
            c20_ixstart = c20_b_ix;
            c20_h_x = c20_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c20_b_ix), 1, 5, 1, 0) - 1];
            c20_yb_b = muDoubleScalarIsNaN(c20_h_x);
            if (!c20_yb_b) {
              c20_mtmp = c20_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_ix), 1, 5, 1, 0) -
                1];
              exitg2 = TRUE;
            } else {
              c20_ix++;
            }
          }
        }

        if (c20_ixstart < 5) {
          c20_dc_a = c20_ixstart;
          c20_i253 = c20_dc_a;
          c20_o_overflow = FALSE;
          if (c20_o_overflow) {
            c20_check_forloop_overflow_error(chartInstance, c20_o_overflow);
          }

          for (c20_c_ix = c20_i253 + 1; c20_c_ix < 6; c20_c_ix++) {
            c20_b_ix = c20_c_ix;
            c20_ec_a = c20_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c20_b_ix), 1, 5, 1, 0) - 1];
            c20_ac_b = c20_mtmp;
            c20_p = (c20_ec_a > c20_ac_b);
            if (c20_p) {
              c20_mtmp = c20_c_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_ix), 1, 5, 1, 0) -
                1];
            }
          }
        }

        c20_b_mtmp = c20_mtmp;
        c20_scale = c20_b_mtmp;
        c20_sm = c20_eml_div(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_m),
          1, 6, 1, 0) - 1], c20_scale);
        c20_smm1 = c20_eml_div(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_mm1), 1, 6, 1, 0) - 1],
          c20_scale);
        c20_emm1 = c20_eml_div(chartInstance, c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_mm1), 1, 6, 1, 0) - 1],
          c20_scale);
        c20_sqds = c20_eml_div(chartInstance, c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 6, 1, 0) - 1],
          c20_scale);
        c20_eqds = c20_eml_div(chartInstance, c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 6, 1, 0) - 1],
          c20_scale);
        c20_fc_a = c20_smm1 + c20_sm;
        c20_bc_b = c20_smm1 - c20_sm;
        c20_o_y = c20_fc_a * c20_bc_b;
        c20_gc_a = c20_emm1;
        c20_cc_b = c20_emm1;
        c20_p_y = c20_gc_a * c20_cc_b;
        c20_dc_b = c20_eml_div(chartInstance, c20_o_y + c20_p_y, 2.0);
        c20_hc_a = c20_sm;
        c20_ec_b = c20_emm1;
        c20_jb_c = c20_hc_a * c20_ec_b;
        c20_ic_a = c20_jb_c;
        c20_fc_b = c20_jb_c;
        c20_jb_c = c20_ic_a * c20_fc_b;
        c20_shift = 0.0;
        guard1 = FALSE;
        if (c20_dc_b != 0.0) {
          guard1 = TRUE;
        } else {
          if (c20_jb_c != 0.0) {
            guard1 = TRUE;
          }
        }

        if (guard1 == TRUE) {
          c20_jc_a = c20_dc_b;
          c20_gc_b = c20_dc_b;
          c20_q_y = c20_jc_a * c20_gc_b;
          c20_shift = c20_q_y + c20_jb_c;
          c20_b_sqrt(chartInstance, &c20_shift);
          if (c20_dc_b < 0.0) {
            c20_shift = -c20_shift;
          }

          c20_shift = c20_eml_div(chartInstance, c20_jb_c, c20_dc_b + c20_shift);
        }

        c20_kc_a = c20_sqds + c20_sm;
        c20_hc_b = c20_sqds - c20_sm;
        c20_r_y = c20_kc_a * c20_hc_b;
        c20_f = c20_r_y + c20_shift;
        c20_lc_a = c20_sqds;
        c20_ic_b = c20_eqds;
        c20_g = c20_lc_a * c20_ic_b;
        c20_k_q = c20_b_q;
        c20_b_mm1 = c20_mm1;
        c20_mc_a = c20_k_q;
        c20_jc_b = c20_b_mm1;
        c20_nc_a = c20_mc_a;
        c20_kc_b = c20_jc_b;
        if (c20_nc_a > c20_kc_b) {
          c20_p_overflow = FALSE;
        } else {
          c20_p_overflow = (c20_kc_b > 2147483646);
        }

        if (c20_p_overflow) {
          c20_check_forloop_overflow_error(chartInstance, c20_p_overflow);
        }

        for (c20_d_k = c20_k_q; c20_d_k <= c20_b_mm1; c20_d_k++) {
          c20_b_k = c20_d_k;
          c20_oc_a = c20_b_k;
          c20_km1 = c20_oc_a;
          c20_pc_a = c20_b_k + 1;
          c20_kp1 = c20_pc_a;
          c20_c_f = c20_f;
          c20_unusedU1 = c20_g;
          c20_b_eml_xrotg(chartInstance, &c20_c_f, &c20_unusedU1, &c20_d_cs,
                          &c20_d_sn);
          c20_f = c20_c_f;
          c20_b_cs = c20_d_cs;
          c20_b_sn = c20_d_sn;
          if (c20_b_k > c20_b_q) {
            c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)(c20_km1 - 1)), 1, 6, 1, 0) - 1] = c20_f;
          }

          c20_qc_a = c20_b_cs;
          c20_lc_b = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 6, 1, 0) - 1];
          c20_s_y = c20_qc_a * c20_lc_b;
          c20_rc_a = c20_b_sn;
          c20_mc_b = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 6, 1, 0) - 1];
          c20_t_y = c20_rc_a * c20_mc_b;
          c20_f = c20_s_y + c20_t_y;
          c20_sc_a = c20_b_cs;
          c20_nc_b = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 6, 1, 0) - 1];
          c20_u_y = c20_sc_a * c20_nc_b;
          c20_tc_a = c20_b_sn;
          c20_oc_b = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 6, 1, 0) - 1];
          c20_v_y = c20_tc_a * c20_oc_b;
          c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_k), 1, 6, 1, 0) - 1] = c20_u_y - c20_v_y;
          c20_uc_a = c20_b_sn;
          c20_pc_b = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_kp1), 1, 6, 1, 0) - 1];
          c20_g = c20_uc_a * c20_pc_b;
          c20_vc_a = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_kp1), 1, 6, 1, 0) - 1];
          c20_qc_b = c20_b_cs;
          c20_w_y = c20_vc_a * c20_qc_b;
          c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_kp1), 1, 6, 1, 0) - 1] = c20_w_y;
          c20_wc_a = c20_b_k;
          c20_kb_c = c20_wc_a;
          c20_rc_b = c20_kb_c - 1;
          c20_lb_c = 6 * c20_rc_b;
          c20_sc_b = c20_lb_c;
          c20_colk = c20_sc_b;
          c20_tc_b = c20_b_k;
          c20_mb_c = 6 * c20_tc_b;
          c20_uc_b = c20_mb_c;
          c20_colkp1 = c20_uc_b;
          c20_f_eml_xrot(chartInstance, c20_Vf, c20_colk + 1, c20_colkp1 + 1,
                         c20_b_cs, c20_b_sn);
          c20_d_f = c20_f;
          c20_unusedU2 = c20_g;
          c20_b_eml_xrotg(chartInstance, &c20_d_f, &c20_unusedU2, &c20_e_cs,
                          &c20_e_sn);
          c20_f = c20_d_f;
          c20_b_cs = c20_e_cs;
          c20_b_sn = c20_e_sn;
          c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_k), 1, 6, 1, 0) - 1] = c20_f;
          c20_xc_a = c20_b_cs;
          c20_vc_b = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 6, 1, 0) - 1];
          c20_x_y = c20_xc_a * c20_vc_b;
          c20_yc_a = c20_b_sn;
          c20_wc_b = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_kp1), 1, 6, 1, 0) - 1];
          c20_y_y = c20_yc_a * c20_wc_b;
          c20_f = c20_x_y + c20_y_y;
          c20_ad_a = -c20_b_sn;
          c20_xc_b = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 6, 1, 0) - 1];
          c20_ab_y = c20_ad_a * c20_xc_b;
          c20_bd_a = c20_b_cs;
          c20_yc_b = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_kp1), 1, 6, 1, 0) - 1];
          c20_bb_y = c20_bd_a * c20_yc_b;
          c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_kp1), 1, 6, 1, 0) - 1] = c20_ab_y + c20_bb_y;
          c20_cd_a = c20_b_sn;
          c20_ad_b = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_kp1), 1, 6, 1, 0) - 1];
          c20_g = c20_cd_a * c20_ad_b;
          c20_dd_a = c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_kp1), 1, 6, 1, 0) - 1];
          c20_bd_b = c20_b_cs;
          c20_cb_y = c20_dd_a * c20_bd_b;
          c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_kp1), 1, 6, 1, 0) - 1] = c20_cb_y;
          if (c20_b_k < 6) {
            c20_ed_a = c20_b_k;
            c20_nb_c = c20_ed_a;
            c20_cd_b = c20_nb_c - 1;
            c20_ob_c = 6 * c20_cd_b;
            c20_dd_b = c20_ob_c;
            c20_colk = c20_dd_b;
            c20_ed_b = c20_b_k;
            c20_pb_c = 6 * c20_ed_b;
            c20_fd_b = c20_pb_c;
            c20_colkp1 = c20_fd_b;
            c20_f_eml_xrot(chartInstance, c20_U, c20_colk + 1, c20_colkp1 + 1,
                           c20_b_cs, c20_b_sn);
          }
        }

        c20_fd_a = c20_b_m;
        c20_qb_c = c20_fd_a;
        c20_e[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)(c20_qb_c - 1)), 1, 6, 1, 0) - 1] = c20_f;
        c20_iter++;
        break;

       default:
        if (c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c20_b_q), 1, 6, 1, 0) - 1] < 0.0) {
          c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_q), 1, 6, 1, 0) - 1] =
            -c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c20_b_q), 1, 6, 1, 0) - 1];
          c20_gd_a = c20_b_q;
          c20_rb_c = c20_gd_a;
          c20_gd_b = c20_rb_c - 1;
          c20_sb_c = 6 * c20_gd_b;
          c20_hd_b = c20_sb_c;
          c20_colq = c20_hd_b;
          c20_b_eml_scalar_eg(chartInstance);
          c20_d29 = -1.0;
          c20_n_eml_xscal(chartInstance, c20_d29, c20_Vf, c20_colq + 1);
        }

        c20_hd_a = c20_b_q + 1;
        c20_qp1 = c20_hd_a;
        exitg3 = FALSE;
        while ((exitg3 == FALSE) && (c20_b_q < 6)) {
          if (c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c20_b_q), 1, 6, 1, 0) - 1] <
              c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
                "", (real_T)c20_qp1), 1, 6, 1, 0) - 1]) {
            c20_rt = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c20_b_q), 1, 6, 1, 0) - 1];
            c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c20_b_q), 1, 6, 1, 0) - 1] =
              c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c20_qp1), 1, 6, 1, 0) - 1];
            c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c20_qp1), 1, 6, 1, 0) - 1] = c20_rt;
            if (c20_b_q < 6) {
              c20_jd_a = c20_b_q;
              c20_tb_c = c20_jd_a;
              c20_id_b = c20_tb_c - 1;
              c20_ub_c = 6 * c20_id_b;
              c20_jd_b = c20_ub_c;
              c20_colq = c20_jd_b;
              c20_kd_b = c20_b_q;
              c20_vb_c = 6 * c20_kd_b;
              c20_ld_b = c20_vb_c;
              c20_colqp1 = c20_ld_b;
              c20_f_eml_xswap(chartInstance, c20_Vf, c20_colq + 1, c20_colqp1 +
                              1);
            }

            if (c20_b_q < 6) {
              c20_kd_a = c20_b_q;
              c20_wb_c = c20_kd_a;
              c20_md_b = c20_wb_c - 1;
              c20_xb_c = 6 * c20_md_b;
              c20_nd_b = c20_xb_c;
              c20_colq = c20_nd_b;
              c20_od_b = c20_b_q;
              c20_yb_c = 6 * c20_od_b;
              c20_pd_b = c20_yb_c;
              c20_colqp1 = c20_pd_b;
              c20_f_eml_xswap(chartInstance, c20_U, c20_colq + 1, c20_colqp1 + 1);
            }

            c20_b_q = c20_qp1;
            c20_ld_a = c20_b_q + 1;
            c20_qp1 = c20_ld_a;
          } else {
            exitg3 = TRUE;
          }
        }

        c20_iter = 0.0;
        c20_id_a = c20_b_m - 1;
        c20_b_m = c20_id_a;
        break;
      }
    }
  }

  for (c20_e_k = 1; c20_e_k < 7; c20_e_k++) {
    c20_b_k = c20_e_k;
    c20_S[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_b_k), 1, 6, 1, 0) - 1] = c20_s[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 6, 1, 0) - 1];
  }

  for (c20_j = 1; c20_j < 7; c20_j++) {
    c20_b_j = c20_j;
    for (c20_i = 1; c20_i < 7; c20_i++) {
      c20_b_i = c20_i;
      c20_V[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
               (real_T)c20_b_i), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
               "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_j), 1, 6, 2, 0)
              - 1)) - 1] = c20_Vf[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c20_b_i), 1, 6, 1, 0) + 6 *
        (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
        c20_b_j), 1, 6, 2, 0) - 1)) - 1];
    }
  }
}

static real_T c20_c_eml_xnrm2(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, int32_T c20_n, real_T c20_x[36], int32_T c20_ix0)
{
  real_T c20_y;
  int32_T c20_b_n;
  int32_T c20_b_ix0;
  int32_T c20_c_n;
  int32_T c20_c_ix0;
  real_T c20_b_x;
  real_T c20_c_x;
  real_T c20_scale;
  int32_T c20_kstart;
  int32_T c20_a;
  int32_T c20_c;
  int32_T c20_b_a;
  int32_T c20_b_c;
  int32_T c20_c_a;
  int32_T c20_b;
  int32_T c20_kend;
  int32_T c20_b_kstart;
  int32_T c20_b_kend;
  int32_T c20_d_a;
  int32_T c20_b_b;
  int32_T c20_e_a;
  int32_T c20_c_b;
  boolean_T c20_overflow;
  int32_T c20_k;
  int32_T c20_b_k;
  real_T c20_d_x;
  real_T c20_e_x;
  real_T c20_absxk;
  real_T c20_t;
  c20_b_n = c20_n;
  c20_b_ix0 = c20_ix0;
  c20_c_n = c20_b_n;
  c20_c_ix0 = c20_b_ix0;
  c20_y = 0.0;
  if (c20_c_n < 1) {
  } else if (c20_c_n == 1) {
    c20_b_x = c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c20_c_ix0), 1, 36, 1, 0) - 1];
    c20_c_x = c20_b_x;
    c20_y = muDoubleScalarAbs(c20_c_x);
  } else {
    c20_realmin(chartInstance);
    c20_scale = 2.2250738585072014E-308;
    c20_kstart = c20_c_ix0;
    c20_a = c20_c_n;
    c20_c = c20_a;
    c20_b_a = c20_c - 1;
    c20_b_c = c20_b_a;
    c20_c_a = c20_kstart;
    c20_b = c20_b_c;
    c20_kend = c20_c_a + c20_b;
    c20_b_kstart = c20_kstart;
    c20_b_kend = c20_kend;
    c20_d_a = c20_b_kstart;
    c20_b_b = c20_b_kend;
    c20_e_a = c20_d_a;
    c20_c_b = c20_b_b;
    if (c20_e_a > c20_c_b) {
      c20_overflow = FALSE;
    } else {
      c20_overflow = (c20_c_b > 2147483646);
    }

    if (c20_overflow) {
      c20_check_forloop_overflow_error(chartInstance, c20_overflow);
    }

    for (c20_k = c20_b_kstart; c20_k <= c20_b_kend; c20_k++) {
      c20_b_k = c20_k;
      c20_d_x = c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 36, 1, 0) - 1];
      c20_e_x = c20_d_x;
      c20_absxk = muDoubleScalarAbs(c20_e_x);
      if (c20_absxk > c20_scale) {
        c20_t = c20_scale / c20_absxk;
        c20_y = 1.0 + c20_y * c20_t * c20_t;
        c20_scale = c20_absxk;
      } else {
        c20_t = c20_absxk / c20_scale;
        c20_y += c20_t * c20_t;
      }
    }

    c20_y = c20_scale * muDoubleScalarSqrt(c20_y);
  }

  return c20_y;
}

static void c20_e_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[36], int32_T c20_ix0, real_T
  c20_b_x[36])
{
  int32_T c20_i254;
  for (c20_i254 = 0; c20_i254 < 36; c20_i254++) {
    c20_b_x[c20_i254] = c20_x[c20_i254];
  }

  c20_l_eml_xscal(chartInstance, c20_n, c20_a, c20_b_x, c20_ix0);
}

static real_T c20_c_eml_xdotc(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, int32_T c20_n, real_T c20_x[36], int32_T c20_ix0, real_T
  c20_y[36], int32_T c20_iy0)
{
  real_T c20_d;
  int32_T c20_b_n;
  int32_T c20_b_ix0;
  int32_T c20_b_iy0;
  int32_T c20_c_n;
  int32_T c20_c_ix0;
  int32_T c20_c_iy0;
  int32_T c20_d_n;
  int32_T c20_d_ix0;
  int32_T c20_d_iy0;
  int32_T c20_e_n;
  int32_T c20_e_ix0;
  int32_T c20_e_iy0;
  int32_T c20_ix;
  int32_T c20_iy;
  int32_T c20_f_n;
  int32_T c20_b;
  int32_T c20_b_b;
  boolean_T c20_overflow;
  int32_T c20_k;
  int32_T c20_a;
  int32_T c20_b_a;
  c20_b_n = c20_n;
  c20_b_ix0 = c20_ix0;
  c20_b_iy0 = c20_iy0;
  c20_c_n = c20_b_n;
  c20_c_ix0 = c20_b_ix0;
  c20_c_iy0 = c20_b_iy0;
  c20_d_n = c20_c_n;
  c20_d_ix0 = c20_c_ix0;
  c20_d_iy0 = c20_c_iy0;
  c20_e_n = c20_d_n;
  c20_e_ix0 = c20_d_ix0;
  c20_e_iy0 = c20_d_iy0;
  c20_f_eml_scalar_eg(chartInstance);
  c20_d = 0.0;
  if (c20_e_n < 1) {
  } else {
    c20_ix = c20_e_ix0;
    c20_iy = c20_e_iy0;
    c20_f_n = c20_e_n;
    c20_b = c20_f_n;
    c20_b_b = c20_b;
    if (1 > c20_b_b) {
      c20_overflow = FALSE;
    } else {
      c20_overflow = (c20_b_b > 2147483646);
    }

    if (c20_overflow) {
      c20_check_forloop_overflow_error(chartInstance, c20_overflow);
    }

    for (c20_k = 1; c20_k <= c20_f_n; c20_k++) {
      c20_d += c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", (real_T)c20_ix), 1, 36, 1, 0) - 1] *
        c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c20_iy), 1, 36, 1, 0) - 1];
      c20_a = c20_ix + 1;
      c20_ix = c20_a;
      c20_b_a = c20_iy + 1;
      c20_iy = c20_b_a;
    }
  }

  return c20_d;
}

static void c20_e_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, int32_T c20_ix0, real_T c20_y[36], int32_T
  c20_iy0, real_T c20_b_y[36])
{
  int32_T c20_i255;
  for (c20_i255 = 0; c20_i255 < 36; c20_i255++) {
    c20_b_y[c20_i255] = c20_y[c20_i255];
  }

  c20_l_eml_xaxpy(chartInstance, c20_n, c20_a, c20_ix0, c20_b_y, c20_iy0);
}

static real_T c20_d_eml_xnrm2(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, int32_T c20_n, real_T c20_x[6], int32_T c20_ix0)
{
  real_T c20_y;
  int32_T c20_b_n;
  int32_T c20_b_ix0;
  int32_T c20_c_n;
  int32_T c20_c_ix0;
  real_T c20_b_x;
  real_T c20_c_x;
  real_T c20_scale;
  int32_T c20_kstart;
  int32_T c20_a;
  int32_T c20_c;
  int32_T c20_b_a;
  int32_T c20_b_c;
  int32_T c20_c_a;
  int32_T c20_b;
  int32_T c20_kend;
  int32_T c20_b_kstart;
  int32_T c20_b_kend;
  int32_T c20_d_a;
  int32_T c20_b_b;
  int32_T c20_e_a;
  int32_T c20_c_b;
  boolean_T c20_overflow;
  int32_T c20_k;
  int32_T c20_b_k;
  real_T c20_d_x;
  real_T c20_e_x;
  real_T c20_absxk;
  real_T c20_t;
  c20_b_n = c20_n;
  c20_b_ix0 = c20_ix0;
  c20_c_n = c20_b_n;
  c20_c_ix0 = c20_b_ix0;
  c20_y = 0.0;
  if (c20_c_n < 1) {
  } else if (c20_c_n == 1) {
    c20_b_x = c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c20_c_ix0), 1, 6, 1, 0) - 1];
    c20_c_x = c20_b_x;
    c20_y = muDoubleScalarAbs(c20_c_x);
  } else {
    c20_realmin(chartInstance);
    c20_scale = 2.2250738585072014E-308;
    c20_kstart = c20_c_ix0;
    c20_a = c20_c_n;
    c20_c = c20_a;
    c20_b_a = c20_c - 1;
    c20_b_c = c20_b_a;
    c20_c_a = c20_kstart;
    c20_b = c20_b_c;
    c20_kend = c20_c_a + c20_b;
    c20_b_kstart = c20_kstart;
    c20_b_kend = c20_kend;
    c20_d_a = c20_b_kstart;
    c20_b_b = c20_b_kend;
    c20_e_a = c20_d_a;
    c20_c_b = c20_b_b;
    if (c20_e_a > c20_c_b) {
      c20_overflow = FALSE;
    } else {
      c20_overflow = (c20_c_b > 2147483646);
    }

    if (c20_overflow) {
      c20_check_forloop_overflow_error(chartInstance, c20_overflow);
    }

    for (c20_k = c20_b_kstart; c20_k <= c20_b_kend; c20_k++) {
      c20_b_k = c20_k;
      c20_d_x = c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c20_b_k), 1, 6, 1, 0) - 1];
      c20_e_x = c20_d_x;
      c20_absxk = muDoubleScalarAbs(c20_e_x);
      if (c20_absxk > c20_scale) {
        c20_t = c20_scale / c20_absxk;
        c20_y = 1.0 + c20_y * c20_t * c20_t;
        c20_scale = c20_absxk;
      } else {
        c20_t = c20_absxk / c20_scale;
        c20_y += c20_t * c20_t;
      }
    }

    c20_y = c20_scale * muDoubleScalarSqrt(c20_y);
  }

  return c20_y;
}

static void c20_f_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[6], int32_T c20_ix0, real_T c20_b_x
  [6])
{
  int32_T c20_i256;
  for (c20_i256 = 0; c20_i256 < 6; c20_i256++) {
    c20_b_x[c20_i256] = c20_x[c20_i256];
  }

  c20_m_eml_xscal(chartInstance, c20_n, c20_a, c20_b_x, c20_ix0);
}

static void c20_f_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[36], int32_T c20_ix0, real_T c20_y[6],
  int32_T c20_iy0, real_T c20_b_y[6])
{
  int32_T c20_i257;
  int32_T c20_i258;
  real_T c20_b_x[36];
  for (c20_i257 = 0; c20_i257 < 6; c20_i257++) {
    c20_b_y[c20_i257] = c20_y[c20_i257];
  }

  for (c20_i258 = 0; c20_i258 < 36; c20_i258++) {
    c20_b_x[c20_i258] = c20_x[c20_i258];
  }

  c20_m_eml_xaxpy(chartInstance, c20_n, c20_a, c20_b_x, c20_ix0, c20_b_y,
                  c20_iy0);
}

static void c20_g_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[6], int32_T c20_ix0, real_T c20_y[36],
  int32_T c20_iy0, real_T c20_b_y[36])
{
  int32_T c20_i259;
  int32_T c20_i260;
  real_T c20_b_x[6];
  for (c20_i259 = 0; c20_i259 < 36; c20_i259++) {
    c20_b_y[c20_i259] = c20_y[c20_i259];
  }

  for (c20_i260 = 0; c20_i260 < 6; c20_i260++) {
    c20_b_x[c20_i260] = c20_x[c20_i260];
  }

  c20_n_eml_xaxpy(chartInstance, c20_n, c20_a, c20_b_x, c20_ix0, c20_b_y,
                  c20_iy0);
}

static void c20_g_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_a, real_T c20_x[36], int32_T c20_ix0, real_T c20_b_x[36])
{
  int32_T c20_i261;
  for (c20_i261 = 0; c20_i261 < 36; c20_i261++) {
    c20_b_x[c20_i261] = c20_x[c20_i261];
  }

  c20_n_eml_xscal(chartInstance, c20_a, c20_b_x, c20_ix0);
}

static void c20_c_eml_xrot(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[36], int32_T c20_ix0, int32_T c20_iy0, real_T c20_c, real_T c20_s,
  real_T c20_b_x[36])
{
  int32_T c20_i262;
  for (c20_i262 = 0; c20_i262 < 36; c20_i262++) {
    c20_b_x[c20_i262] = c20_x[c20_i262];
  }

  c20_f_eml_xrot(chartInstance, c20_b_x, c20_ix0, c20_iy0, c20_c, c20_s);
}

static void c20_c_eml_xswap(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[36], int32_T c20_ix0, int32_T c20_iy0, real_T c20_b_x[36])
{
  int32_T c20_i263;
  for (c20_i263 = 0; c20_i263 < 36; c20_i263++) {
    c20_b_x[c20_i263] = c20_x[c20_i263];
  }

  c20_f_eml_xswap(chartInstance, c20_b_x, c20_ix0, c20_iy0);
}

static void c20_b_eml_xgemm(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_k, real_T c20_A[36], real_T c20_B[36], real_T c20_C[36], real_T
  c20_b_C[36])
{
  int32_T c20_i264;
  int32_T c20_i265;
  real_T c20_b_A[36];
  int32_T c20_i266;
  real_T c20_b_B[36];
  for (c20_i264 = 0; c20_i264 < 36; c20_i264++) {
    c20_b_C[c20_i264] = c20_C[c20_i264];
  }

  for (c20_i265 = 0; c20_i265 < 36; c20_i265++) {
    c20_b_A[c20_i265] = c20_A[c20_i265];
  }

  for (c20_i266 = 0; c20_i266 < 36; c20_i266++) {
    c20_b_B[c20_i266] = c20_B[c20_i266];
  }

  c20_d_eml_xgemm(chartInstance, c20_k, c20_b_A, c20_b_B, c20_b_C);
}

static void c20_j_eml_scalar_eg(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
}

static void c20_j_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_sprintf, const char_T *c20_identifier,
  char_T c20_y[14])
{
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_sprintf), &c20_thisId,
    c20_y);
  sf_mex_destroy(&c20_sprintf);
}

static void c20_k_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  char_T c20_y[14])
{
  char_T c20_cv7[14];
  int32_T c20_i267;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), c20_cv7, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c20_i267 = 0; c20_i267 < 14; c20_i267++) {
    c20_y[c20_i267] = c20_cv7[c20_i267];
  }

  sf_mex_destroy(&c20_u);
}

static const mxArray *c20_h_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc20_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(int32_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, FALSE);
  return c20_mxArrayOutData;
}

static int32_T c20_l_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  int32_T c20_y;
  int32_T c20_i268;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_i268, 1, 6, 0U, 0, 0U, 0);
  c20_y = c20_i268;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_sfEvent;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  int32_T c20_y;
  SFc20_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc20_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c20_b_sfEvent = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_sfEvent),
    &c20_thisId);
  sf_mex_destroy(&c20_b_sfEvent);
  *(int32_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static uint8_T c20_m_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_b_is_active_c20_CusakisME4901arcs, const
  char_T *c20_identifier)
{
  uint8_T c20_y;
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_n_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c20_b_is_active_c20_CusakisME4901arcs), &c20_thisId);
  sf_mex_destroy(&c20_b_is_active_c20_CusakisME4901arcs);
  return c20_y;
}

static uint8_T c20_n_emlrt_marshallIn(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  uint8_T c20_y;
  uint8_T c20_u0;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_u0, 1, 3, 0U, 0, 0U, 0);
  c20_y = c20_u0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_b_eml_matlab_zgetrf(SFc20_CusakisME4901arcsInstanceStruct
  *chartInstance, real_T c20_A[36], int32_T c20_ipiv[6], int32_T *c20_info)
{
  int32_T c20_i269;
  int32_T c20_j;
  int32_T c20_b_j;
  int32_T c20_a;
  int32_T c20_jm1;
  int32_T c20_b;
  int32_T c20_mmj;
  int32_T c20_b_a;
  int32_T c20_c;
  int32_T c20_b_b;
  int32_T c20_jj;
  int32_T c20_c_a;
  int32_T c20_jp1j;
  int32_T c20_d_a;
  int32_T c20_b_c;
  int32_T c20_n;
  int32_T c20_ix0;
  int32_T c20_b_n;
  int32_T c20_b_ix0;
  int32_T c20_c_n;
  int32_T c20_c_ix0;
  int32_T c20_idxmax;
  int32_T c20_ix;
  real_T c20_x;
  real_T c20_b_x;
  real_T c20_c_x;
  real_T c20_y;
  real_T c20_d_x;
  real_T c20_e_x;
  real_T c20_b_y;
  real_T c20_smax;
  int32_T c20_d_n;
  int32_T c20_c_b;
  int32_T c20_d_b;
  boolean_T c20_overflow;
  int32_T c20_k;
  int32_T c20_b_k;
  int32_T c20_e_a;
  real_T c20_f_x;
  real_T c20_g_x;
  real_T c20_h_x;
  real_T c20_c_y;
  real_T c20_i_x;
  real_T c20_j_x;
  real_T c20_d_y;
  real_T c20_s;
  int32_T c20_f_a;
  int32_T c20_jpiv_offset;
  int32_T c20_g_a;
  int32_T c20_e_b;
  int32_T c20_jpiv;
  int32_T c20_h_a;
  int32_T c20_f_b;
  int32_T c20_c_c;
  int32_T c20_g_b;
  int32_T c20_jrow;
  int32_T c20_i_a;
  int32_T c20_h_b;
  int32_T c20_jprow;
  int32_T c20_d_ix0;
  int32_T c20_iy0;
  int32_T c20_e_ix0;
  int32_T c20_b_iy0;
  int32_T c20_f_ix0;
  int32_T c20_c_iy0;
  int32_T c20_b_ix;
  int32_T c20_iy;
  int32_T c20_c_k;
  real_T c20_temp;
  int32_T c20_j_a;
  int32_T c20_k_a;
  int32_T c20_b_jp1j;
  int32_T c20_l_a;
  int32_T c20_d_c;
  int32_T c20_m_a;
  int32_T c20_i_b;
  int32_T c20_i270;
  int32_T c20_n_a;
  int32_T c20_j_b;
  int32_T c20_o_a;
  int32_T c20_k_b;
  boolean_T c20_b_overflow;
  int32_T c20_i;
  int32_T c20_b_i;
  real_T c20_k_x;
  real_T c20_e_y;
  real_T c20_z;
  int32_T c20_l_b;
  int32_T c20_e_c;
  int32_T c20_p_a;
  int32_T c20_f_c;
  int32_T c20_q_a;
  int32_T c20_g_c;
  int32_T c20_b_m;
  int32_T c20_e_n;
  int32_T c20_g_ix0;
  int32_T c20_d_iy0;
  int32_T c20_ia0;
  real_T c20_d30;
  c20_realmin(chartInstance);
  c20_eps(chartInstance);
  for (c20_i269 = 0; c20_i269 < 6; c20_i269++) {
    c20_ipiv[c20_i269] = 1 + c20_i269;
  }

  *c20_info = 0;
  for (c20_j = 1; c20_j < 6; c20_j++) {
    c20_b_j = c20_j;
    c20_a = c20_b_j - 1;
    c20_jm1 = c20_a;
    c20_b = c20_b_j;
    c20_mmj = 6 - c20_b;
    c20_b_a = c20_jm1;
    c20_c = c20_b_a * 7;
    c20_b_b = c20_c + 1;
    c20_jj = c20_b_b;
    c20_c_a = c20_jj + 1;
    c20_jp1j = c20_c_a;
    c20_d_a = c20_mmj;
    c20_b_c = c20_d_a;
    c20_n = c20_b_c + 1;
    c20_ix0 = c20_jj;
    c20_b_n = c20_n;
    c20_b_ix0 = c20_ix0;
    c20_c_n = c20_b_n;
    c20_c_ix0 = c20_b_ix0;
    if (c20_c_n < 1) {
      c20_idxmax = 0;
    } else {
      c20_idxmax = 1;
      if (c20_c_n > 1) {
        c20_ix = c20_c_ix0;
        c20_x = c20_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_ix), 1, 36, 1, 0) - 1];
        c20_b_x = c20_x;
        c20_c_x = c20_b_x;
        c20_y = muDoubleScalarAbs(c20_c_x);
        c20_d_x = 0.0;
        c20_e_x = c20_d_x;
        c20_b_y = muDoubleScalarAbs(c20_e_x);
        c20_smax = c20_y + c20_b_y;
        c20_d_n = c20_c_n;
        c20_c_b = c20_d_n;
        c20_d_b = c20_c_b;
        if (2 > c20_d_b) {
          c20_overflow = FALSE;
        } else {
          c20_overflow = (c20_d_b > 2147483646);
        }

        if (c20_overflow) {
          c20_check_forloop_overflow_error(chartInstance, c20_overflow);
        }

        for (c20_k = 2; c20_k <= c20_d_n; c20_k++) {
          c20_b_k = c20_k;
          c20_e_a = c20_ix + 1;
          c20_ix = c20_e_a;
          c20_f_x = c20_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_ix), 1, 36, 1, 0) - 1];
          c20_g_x = c20_f_x;
          c20_h_x = c20_g_x;
          c20_c_y = muDoubleScalarAbs(c20_h_x);
          c20_i_x = 0.0;
          c20_j_x = c20_i_x;
          c20_d_y = muDoubleScalarAbs(c20_j_x);
          c20_s = c20_c_y + c20_d_y;
          if (c20_s > c20_smax) {
            c20_idxmax = c20_b_k;
            c20_smax = c20_s;
          }
        }
      }
    }

    c20_f_a = c20_idxmax - 1;
    c20_jpiv_offset = c20_f_a;
    c20_g_a = c20_jj;
    c20_e_b = c20_jpiv_offset;
    c20_jpiv = c20_g_a + c20_e_b;
    if (c20_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_jpiv), 1, 36, 1, 0) - 1] != 0.0) {
      if (c20_jpiv_offset != 0) {
        c20_h_a = c20_b_j;
        c20_f_b = c20_jpiv_offset;
        c20_c_c = c20_h_a + c20_f_b;
        c20_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_j), 1, 6, 1, 0) - 1] = c20_c_c;
        c20_g_b = c20_jm1 + 1;
        c20_jrow = c20_g_b;
        c20_i_a = c20_jrow;
        c20_h_b = c20_jpiv_offset;
        c20_jprow = c20_i_a + c20_h_b;
        c20_d_ix0 = c20_jrow;
        c20_iy0 = c20_jprow;
        c20_e_ix0 = c20_d_ix0;
        c20_b_iy0 = c20_iy0;
        c20_below_threshold(chartInstance);
        c20_f_ix0 = c20_e_ix0;
        c20_c_iy0 = c20_b_iy0;
        c20_b_ix = c20_f_ix0;
        c20_iy = c20_c_iy0;
        for (c20_c_k = 1; c20_c_k < 7; c20_c_k++) {
          c20_temp = c20_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c20_b_ix), 1, 36, 1, 0) - 1];
          c20_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_ix), 1, 36, 1, 0) - 1] =
            c20_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_iy), 1, 36, 1, 0) - 1];
          c20_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_iy), 1, 36, 1, 0) - 1] = c20_temp;
          c20_j_a = c20_b_ix + 6;
          c20_b_ix = c20_j_a;
          c20_k_a = c20_iy + 6;
          c20_iy = c20_k_a;
        }
      }

      c20_b_jp1j = c20_jp1j;
      c20_l_a = c20_mmj;
      c20_d_c = c20_l_a;
      c20_m_a = c20_jp1j;
      c20_i_b = c20_d_c - 1;
      c20_i270 = c20_m_a + c20_i_b;
      c20_n_a = c20_b_jp1j;
      c20_j_b = c20_i270;
      c20_o_a = c20_n_a;
      c20_k_b = c20_j_b;
      if (c20_o_a > c20_k_b) {
        c20_b_overflow = FALSE;
      } else {
        c20_b_overflow = (c20_k_b > 2147483646);
      }

      if (c20_b_overflow) {
        c20_check_forloop_overflow_error(chartInstance, c20_b_overflow);
      }

      for (c20_i = c20_b_jp1j; c20_i <= c20_i270; c20_i++) {
        c20_b_i = c20_i;
        c20_k_x = c20_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_b_i), 1, 36, 1, 0) - 1];
        c20_e_y = c20_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_jj), 1, 36, 1, 0) - 1];
        c20_z = c20_k_x / c20_e_y;
        c20_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_i), 1, 36, 1, 0) - 1] = c20_z;
      }
    } else {
      *c20_info = c20_b_j;
    }

    c20_l_b = c20_b_j;
    c20_e_c = 6 - c20_l_b;
    c20_p_a = c20_jj;
    c20_f_c = c20_p_a;
    c20_q_a = c20_jj;
    c20_g_c = c20_q_a;
    c20_b_m = c20_mmj;
    c20_e_n = c20_e_c;
    c20_g_ix0 = c20_jp1j;
    c20_d_iy0 = c20_f_c + 6;
    c20_ia0 = c20_g_c + 7;
    c20_d30 = -1.0;
    c20_b_eml_xger(chartInstance, c20_b_m, c20_e_n, c20_d30, c20_g_ix0,
                   c20_d_iy0, c20_A, c20_ia0);
  }

  if (*c20_info == 0) {
    if (!(c20_A[35] != 0.0)) {
      *c20_info = 6;
    }
  }
}

static void c20_b_eml_xger(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_b_m, int32_T c20_n, real_T c20_alpha1, int32_T c20_ix0, int32_T
  c20_iy0, real_T c20_A[36], int32_T c20_ia0)
{
  int32_T c20_c_m;
  int32_T c20_b_n;
  real_T c20_b_alpha1;
  int32_T c20_b_ix0;
  int32_T c20_b_iy0;
  int32_T c20_b_ia0;
  int32_T c20_d_m;
  int32_T c20_c_n;
  real_T c20_c_alpha1;
  int32_T c20_c_ix0;
  int32_T c20_c_iy0;
  int32_T c20_c_ia0;
  int32_T c20_e_m;
  int32_T c20_d_n;
  real_T c20_d_alpha1;
  int32_T c20_d_ix0;
  int32_T c20_d_iy0;
  int32_T c20_d_ia0;
  int32_T c20_ixstart;
  int32_T c20_a;
  int32_T c20_jA;
  int32_T c20_jy;
  int32_T c20_e_n;
  int32_T c20_b;
  int32_T c20_b_b;
  boolean_T c20_overflow;
  int32_T c20_j;
  real_T c20_yjy;
  real_T c20_temp;
  int32_T c20_ix;
  int32_T c20_c_b;
  int32_T c20_i271;
  int32_T c20_b_a;
  int32_T c20_d_b;
  int32_T c20_i272;
  int32_T c20_c_a;
  int32_T c20_e_b;
  int32_T c20_d_a;
  int32_T c20_f_b;
  boolean_T c20_b_overflow;
  int32_T c20_ijA;
  int32_T c20_b_ijA;
  int32_T c20_e_a;
  int32_T c20_f_a;
  int32_T c20_g_a;
  c20_c_m = c20_b_m;
  c20_b_n = c20_n;
  c20_b_alpha1 = c20_alpha1;
  c20_b_ix0 = c20_ix0;
  c20_b_iy0 = c20_iy0;
  c20_b_ia0 = c20_ia0;
  c20_d_m = c20_c_m;
  c20_c_n = c20_b_n;
  c20_c_alpha1 = c20_b_alpha1;
  c20_c_ix0 = c20_b_ix0;
  c20_c_iy0 = c20_b_iy0;
  c20_c_ia0 = c20_b_ia0;
  c20_e_m = c20_d_m;
  c20_d_n = c20_c_n;
  c20_d_alpha1 = c20_c_alpha1;
  c20_d_ix0 = c20_c_ix0;
  c20_d_iy0 = c20_c_iy0;
  c20_d_ia0 = c20_c_ia0;
  if (c20_d_alpha1 == 0.0) {
  } else {
    c20_ixstart = c20_d_ix0;
    c20_a = c20_d_ia0 - 1;
    c20_jA = c20_a;
    c20_jy = c20_d_iy0;
    c20_e_n = c20_d_n;
    c20_b = c20_e_n;
    c20_b_b = c20_b;
    if (1 > c20_b_b) {
      c20_overflow = FALSE;
    } else {
      c20_overflow = (c20_b_b > 2147483646);
    }

    if (c20_overflow) {
      c20_check_forloop_overflow_error(chartInstance, c20_overflow);
    }

    for (c20_j = 1; c20_j <= c20_e_n; c20_j++) {
      c20_yjy = c20_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c20_jy), 1, 36, 1, 0) - 1];
      if (c20_yjy != 0.0) {
        c20_temp = c20_yjy * c20_d_alpha1;
        c20_ix = c20_ixstart;
        c20_c_b = c20_jA + 1;
        c20_i271 = c20_c_b;
        c20_b_a = c20_e_m;
        c20_d_b = c20_jA;
        c20_i272 = c20_b_a + c20_d_b;
        c20_c_a = c20_i271;
        c20_e_b = c20_i272;
        c20_d_a = c20_c_a;
        c20_f_b = c20_e_b;
        if (c20_d_a > c20_f_b) {
          c20_b_overflow = FALSE;
        } else {
          c20_b_overflow = (c20_f_b > 2147483646);
        }

        if (c20_b_overflow) {
          c20_check_forloop_overflow_error(chartInstance, c20_b_overflow);
        }

        for (c20_ijA = c20_i271; c20_ijA <= c20_i272; c20_ijA++) {
          c20_b_ijA = c20_ijA;
          c20_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_ijA), 1, 36, 1, 0) - 1] =
            c20_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_ijA), 1, 36, 1, 0) - 1] +
            c20_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_ix), 1, 36, 1, 0) - 1] * c20_temp;
          c20_e_a = c20_ix + 1;
          c20_ix = c20_e_a;
        }
      }

      c20_f_a = c20_jy + 6;
      c20_jy = c20_f_a;
      c20_g_a = c20_jA + 6;
      c20_jA = c20_g_a;
    }
  }
}

static void c20_b_eml_xtrsm(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_A[36], real_T c20_B[36])
{
  int32_T c20_j;
  int32_T c20_b_j;
  int32_T c20_a;
  int32_T c20_c;
  int32_T c20_b;
  int32_T c20_b_c;
  int32_T c20_b_b;
  int32_T c20_jBcol;
  int32_T c20_k;
  int32_T c20_b_k;
  int32_T c20_b_a;
  int32_T c20_c_c;
  int32_T c20_c_b;
  int32_T c20_d_c;
  int32_T c20_d_b;
  int32_T c20_kAcol;
  int32_T c20_c_a;
  int32_T c20_e_b;
  int32_T c20_e_c;
  int32_T c20_d_a;
  int32_T c20_f_b;
  int32_T c20_f_c;
  int32_T c20_e_a;
  int32_T c20_g_b;
  int32_T c20_g_c;
  int32_T c20_f_a;
  int32_T c20_h_b;
  int32_T c20_h_c;
  real_T c20_x;
  real_T c20_y;
  real_T c20_z;
  int32_T c20_g_a;
  int32_T c20_i273;
  int32_T c20_i_b;
  int32_T c20_j_b;
  boolean_T c20_overflow;
  int32_T c20_i;
  int32_T c20_b_i;
  int32_T c20_h_a;
  int32_T c20_k_b;
  int32_T c20_i_c;
  int32_T c20_i_a;
  int32_T c20_l_b;
  int32_T c20_j_c;
  int32_T c20_j_a;
  int32_T c20_m_b;
  int32_T c20_k_c;
  int32_T c20_k_a;
  int32_T c20_n_b;
  int32_T c20_l_c;
  for (c20_j = 1; c20_j < 7; c20_j++) {
    c20_b_j = c20_j;
    c20_a = c20_b_j;
    c20_c = c20_a;
    c20_b = c20_c - 1;
    c20_b_c = 6 * c20_b;
    c20_b_b = c20_b_c;
    c20_jBcol = c20_b_b;
    for (c20_k = 6; c20_k > 0; c20_k--) {
      c20_b_k = c20_k;
      c20_b_a = c20_b_k;
      c20_c_c = c20_b_a;
      c20_c_b = c20_c_c - 1;
      c20_d_c = 6 * c20_c_b;
      c20_d_b = c20_d_c;
      c20_kAcol = c20_d_b;
      c20_c_a = c20_b_k;
      c20_e_b = c20_jBcol;
      c20_e_c = c20_c_a + c20_e_b;
      if (c20_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_e_c), 1, 36, 1, 0) - 1] != 0.0) {
        c20_d_a = c20_b_k;
        c20_f_b = c20_jBcol;
        c20_f_c = c20_d_a + c20_f_b;
        c20_e_a = c20_b_k;
        c20_g_b = c20_jBcol;
        c20_g_c = c20_e_a + c20_g_b;
        c20_f_a = c20_b_k;
        c20_h_b = c20_kAcol;
        c20_h_c = c20_f_a + c20_h_b;
        c20_x = c20_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_g_c), 1, 36, 1, 0) - 1];
        c20_y = c20_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_h_c), 1, 36, 1, 0) - 1];
        c20_z = c20_x / c20_y;
        c20_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_f_c), 1, 36, 1, 0) - 1] = c20_z;
        c20_g_a = c20_b_k - 1;
        c20_i273 = c20_g_a;
        c20_i_b = c20_i273;
        c20_j_b = c20_i_b;
        if (1 > c20_j_b) {
          c20_overflow = FALSE;
        } else {
          c20_overflow = (c20_j_b > 2147483646);
        }

        if (c20_overflow) {
          c20_check_forloop_overflow_error(chartInstance, c20_overflow);
        }

        for (c20_i = 1; c20_i <= c20_i273; c20_i++) {
          c20_b_i = c20_i;
          c20_h_a = c20_b_i;
          c20_k_b = c20_jBcol;
          c20_i_c = c20_h_a + c20_k_b;
          c20_i_a = c20_b_i;
          c20_l_b = c20_jBcol;
          c20_j_c = c20_i_a + c20_l_b;
          c20_j_a = c20_b_k;
          c20_m_b = c20_jBcol;
          c20_k_c = c20_j_a + c20_m_b;
          c20_k_a = c20_b_i;
          c20_n_b = c20_kAcol;
          c20_l_c = c20_k_a + c20_n_b;
          c20_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_i_c), 1, 36, 1, 0) - 1] =
            c20_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_j_c), 1, 36, 1, 0) - 1] -
            c20_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_k_c), 1, 36, 1, 0) - 1] *
            c20_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_l_c), 1, 36, 1, 0) - 1];
        }
      }
    }
  }
}

static void c20_h_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[18], int32_T c20_ix0)
{
  int32_T c20_b_n;
  real_T c20_b_a;
  int32_T c20_b_ix0;
  int32_T c20_c_n;
  real_T c20_c_a;
  int32_T c20_c_ix0;
  int32_T c20_d_ix0;
  int32_T c20_d_a;
  int32_T c20_c;
  int32_T c20_b;
  int32_T c20_b_c;
  int32_T c20_e_a;
  int32_T c20_b_b;
  int32_T c20_i274;
  int32_T c20_f_a;
  int32_T c20_c_b;
  int32_T c20_g_a;
  int32_T c20_d_b;
  boolean_T c20_overflow;
  int32_T c20_k;
  int32_T c20_b_k;
  c20_b_n = c20_n;
  c20_b_a = c20_a;
  c20_b_ix0 = c20_ix0;
  c20_c_n = c20_b_n;
  c20_c_a = c20_b_a;
  c20_c_ix0 = c20_b_ix0;
  c20_d_ix0 = c20_c_ix0;
  c20_d_a = c20_c_n;
  c20_c = c20_d_a;
  c20_b = c20_c - 1;
  c20_b_c = c20_b;
  c20_e_a = c20_c_ix0;
  c20_b_b = c20_b_c;
  c20_i274 = c20_e_a + c20_b_b;
  c20_f_a = c20_d_ix0;
  c20_c_b = c20_i274;
  c20_g_a = c20_f_a;
  c20_d_b = c20_c_b;
  if (c20_g_a > c20_d_b) {
    c20_overflow = FALSE;
  } else {
    c20_overflow = (c20_d_b > 2147483646);
  }

  if (c20_overflow) {
    c20_check_forloop_overflow_error(chartInstance, c20_overflow);
  }

  for (c20_k = c20_d_ix0; c20_k <= c20_i274; c20_k++) {
    c20_b_k = c20_k;
    c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_b_k), 1, 18, 1, 0) - 1] = c20_c_a *
      c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_b_k), 1, 18, 1, 0) - 1];
  }
}

static void c20_h_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, int32_T c20_ix0, real_T c20_y[18], int32_T
  c20_iy0)
{
  int32_T c20_b_n;
  real_T c20_b_a;
  int32_T c20_b_ix0;
  int32_T c20_b_iy0;
  int32_T c20_c_n;
  real_T c20_c_a;
  int32_T c20_c_ix0;
  int32_T c20_c_iy0;
  int32_T c20_d_a;
  int32_T c20_ix;
  int32_T c20_e_a;
  int32_T c20_iy;
  int32_T c20_f_a;
  int32_T c20_i275;
  int32_T c20_b;
  int32_T c20_b_b;
  boolean_T c20_overflow;
  int32_T c20_k;
  int32_T c20_g_a;
  int32_T c20_c;
  int32_T c20_h_a;
  int32_T c20_b_c;
  int32_T c20_i_a;
  int32_T c20_c_c;
  int32_T c20_j_a;
  int32_T c20_k_a;
  c20_b_n = c20_n;
  c20_b_a = c20_a;
  c20_b_ix0 = c20_ix0;
  c20_b_iy0 = c20_iy0;
  c20_c_n = c20_b_n;
  c20_c_a = c20_b_a;
  c20_c_ix0 = c20_b_ix0;
  c20_c_iy0 = c20_b_iy0;
  if (c20_c_n < 1) {
  } else if (c20_c_a == 0.0) {
  } else {
    c20_d_a = c20_c_ix0 - 1;
    c20_ix = c20_d_a;
    c20_e_a = c20_c_iy0 - 1;
    c20_iy = c20_e_a;
    c20_f_a = c20_c_n - 1;
    c20_i275 = c20_f_a;
    c20_b = c20_i275;
    c20_b_b = c20_b;
    if (0 > c20_b_b) {
      c20_overflow = FALSE;
    } else {
      c20_overflow = (c20_b_b > 2147483646);
    }

    if (c20_overflow) {
      c20_check_forloop_overflow_error(chartInstance, c20_overflow);
    }

    for (c20_k = 0; c20_k <= c20_i275; c20_k++) {
      c20_g_a = c20_iy;
      c20_c = c20_g_a;
      c20_h_a = c20_iy;
      c20_b_c = c20_h_a;
      c20_i_a = c20_ix;
      c20_c_c = c20_i_a;
      c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c20_c + 1)), 1, 18, 1, 0) - 1] =
        c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c20_b_c + 1)), 1, 18, 1, 0) - 1] + c20_c_a *
        c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c20_c_c + 1)), 1, 18, 1, 0) - 1];
      c20_j_a = c20_ix + 1;
      c20_ix = c20_j_a;
      c20_k_a = c20_iy + 1;
      c20_iy = c20_k_a;
    }
  }
}

static void c20_i_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[3], int32_T c20_ix0)
{
  int32_T c20_b_n;
  real_T c20_b_a;
  int32_T c20_b_ix0;
  int32_T c20_c_n;
  real_T c20_c_a;
  int32_T c20_c_ix0;
  int32_T c20_d_ix0;
  int32_T c20_d_a;
  int32_T c20_c;
  int32_T c20_b;
  int32_T c20_b_c;
  int32_T c20_e_a;
  int32_T c20_b_b;
  int32_T c20_i276;
  int32_T c20_f_a;
  int32_T c20_c_b;
  int32_T c20_g_a;
  int32_T c20_d_b;
  boolean_T c20_overflow;
  int32_T c20_k;
  int32_T c20_b_k;
  c20_b_n = c20_n;
  c20_b_a = c20_a;
  c20_b_ix0 = c20_ix0;
  c20_c_n = c20_b_n;
  c20_c_a = c20_b_a;
  c20_c_ix0 = c20_b_ix0;
  c20_d_ix0 = c20_c_ix0;
  c20_d_a = c20_c_n;
  c20_c = c20_d_a;
  c20_b = c20_c - 1;
  c20_b_c = c20_b;
  c20_e_a = c20_c_ix0;
  c20_b_b = c20_b_c;
  c20_i276 = c20_e_a + c20_b_b;
  c20_f_a = c20_d_ix0;
  c20_c_b = c20_i276;
  c20_g_a = c20_f_a;
  c20_d_b = c20_c_b;
  if (c20_g_a > c20_d_b) {
    c20_overflow = FALSE;
  } else {
    c20_overflow = (c20_d_b > 2147483646);
  }

  if (c20_overflow) {
    c20_check_forloop_overflow_error(chartInstance, c20_overflow);
  }

  for (c20_k = c20_d_ix0; c20_k <= c20_i276; c20_k++) {
    c20_b_k = c20_k;
    c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_b_k), 1, 3, 1, 0) - 1] = c20_c_a *
      c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_b_k), 1, 3, 1, 0) - 1];
  }
}

static void c20_i_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[18], int32_T c20_ix0, real_T c20_y[6],
  int32_T c20_iy0)
{
  int32_T c20_b_n;
  real_T c20_b_a;
  int32_T c20_b_ix0;
  int32_T c20_b_iy0;
  int32_T c20_c_n;
  real_T c20_c_a;
  int32_T c20_c_ix0;
  int32_T c20_c_iy0;
  int32_T c20_d_a;
  int32_T c20_ix;
  int32_T c20_e_a;
  int32_T c20_iy;
  int32_T c20_f_a;
  int32_T c20_i277;
  int32_T c20_b;
  int32_T c20_b_b;
  boolean_T c20_overflow;
  int32_T c20_k;
  int32_T c20_g_a;
  int32_T c20_c;
  int32_T c20_h_a;
  int32_T c20_b_c;
  int32_T c20_i_a;
  int32_T c20_c_c;
  int32_T c20_j_a;
  int32_T c20_k_a;
  c20_b_n = c20_n;
  c20_b_a = c20_a;
  c20_b_ix0 = c20_ix0;
  c20_b_iy0 = c20_iy0;
  c20_c_n = c20_b_n;
  c20_c_a = c20_b_a;
  c20_c_ix0 = c20_b_ix0;
  c20_c_iy0 = c20_b_iy0;
  if (c20_c_n < 1) {
  } else if (c20_c_a == 0.0) {
  } else {
    c20_d_a = c20_c_ix0 - 1;
    c20_ix = c20_d_a;
    c20_e_a = c20_c_iy0 - 1;
    c20_iy = c20_e_a;
    c20_f_a = c20_c_n - 1;
    c20_i277 = c20_f_a;
    c20_b = c20_i277;
    c20_b_b = c20_b;
    if (0 > c20_b_b) {
      c20_overflow = FALSE;
    } else {
      c20_overflow = (c20_b_b > 2147483646);
    }

    if (c20_overflow) {
      c20_check_forloop_overflow_error(chartInstance, c20_overflow);
    }

    for (c20_k = 0; c20_k <= c20_i277; c20_k++) {
      c20_g_a = c20_iy;
      c20_c = c20_g_a;
      c20_h_a = c20_iy;
      c20_b_c = c20_h_a;
      c20_i_a = c20_ix;
      c20_c_c = c20_i_a;
      c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c20_c + 1)), 1, 6, 1, 0) - 1] =
        c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c20_b_c + 1)), 1, 6, 1, 0) - 1] + c20_c_a *
        c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c20_c_c + 1)), 1, 18, 1, 0) - 1];
      c20_j_a = c20_ix + 1;
      c20_ix = c20_j_a;
      c20_k_a = c20_iy + 1;
      c20_iy = c20_k_a;
    }
  }
}

static void c20_j_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[6], int32_T c20_ix0, real_T c20_y[18],
  int32_T c20_iy0)
{
  int32_T c20_b_n;
  real_T c20_b_a;
  int32_T c20_b_ix0;
  int32_T c20_b_iy0;
  int32_T c20_c_n;
  real_T c20_c_a;
  int32_T c20_c_ix0;
  int32_T c20_c_iy0;
  int32_T c20_d_a;
  int32_T c20_ix;
  int32_T c20_e_a;
  int32_T c20_iy;
  int32_T c20_f_a;
  int32_T c20_i278;
  int32_T c20_b;
  int32_T c20_b_b;
  boolean_T c20_overflow;
  int32_T c20_k;
  int32_T c20_g_a;
  int32_T c20_c;
  int32_T c20_h_a;
  int32_T c20_b_c;
  int32_T c20_i_a;
  int32_T c20_c_c;
  int32_T c20_j_a;
  int32_T c20_k_a;
  c20_b_n = c20_n;
  c20_b_a = c20_a;
  c20_b_ix0 = c20_ix0;
  c20_b_iy0 = c20_iy0;
  c20_c_n = c20_b_n;
  c20_c_a = c20_b_a;
  c20_c_ix0 = c20_b_ix0;
  c20_c_iy0 = c20_b_iy0;
  if (c20_c_n < 1) {
  } else if (c20_c_a == 0.0) {
  } else {
    c20_d_a = c20_c_ix0 - 1;
    c20_ix = c20_d_a;
    c20_e_a = c20_c_iy0 - 1;
    c20_iy = c20_e_a;
    c20_f_a = c20_c_n - 1;
    c20_i278 = c20_f_a;
    c20_b = c20_i278;
    c20_b_b = c20_b;
    if (0 > c20_b_b) {
      c20_overflow = FALSE;
    } else {
      c20_overflow = (c20_b_b > 2147483646);
    }

    if (c20_overflow) {
      c20_check_forloop_overflow_error(chartInstance, c20_overflow);
    }

    for (c20_k = 0; c20_k <= c20_i278; c20_k++) {
      c20_g_a = c20_iy;
      c20_c = c20_g_a;
      c20_h_a = c20_iy;
      c20_b_c = c20_h_a;
      c20_i_a = c20_ix;
      c20_c_c = c20_i_a;
      c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c20_c + 1)), 1, 18, 1, 0) - 1] =
        c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c20_b_c + 1)), 1, 18, 1, 0) - 1] + c20_c_a *
        c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c20_c_c + 1)), 1, 6, 1, 0) - 1];
      c20_j_a = c20_ix + 1;
      c20_ix = c20_j_a;
      c20_k_a = c20_iy + 1;
      c20_iy = c20_k_a;
    }
  }
}

static void c20_k_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, int32_T c20_ix0, real_T c20_y[9], int32_T c20_iy0)
{
  int32_T c20_b_n;
  real_T c20_b_a;
  int32_T c20_b_ix0;
  int32_T c20_b_iy0;
  int32_T c20_c_n;
  real_T c20_c_a;
  int32_T c20_c_ix0;
  int32_T c20_c_iy0;
  int32_T c20_d_a;
  int32_T c20_ix;
  int32_T c20_e_a;
  int32_T c20_iy;
  int32_T c20_f_a;
  int32_T c20_i279;
  int32_T c20_b;
  int32_T c20_b_b;
  boolean_T c20_overflow;
  int32_T c20_k;
  int32_T c20_g_a;
  int32_T c20_c;
  int32_T c20_h_a;
  int32_T c20_b_c;
  int32_T c20_i_a;
  int32_T c20_c_c;
  int32_T c20_j_a;
  int32_T c20_k_a;
  c20_b_n = c20_n;
  c20_b_a = c20_a;
  c20_b_ix0 = c20_ix0;
  c20_b_iy0 = c20_iy0;
  c20_c_n = c20_b_n;
  c20_c_a = c20_b_a;
  c20_c_ix0 = c20_b_ix0;
  c20_c_iy0 = c20_b_iy0;
  if (c20_c_n < 1) {
  } else if (c20_c_a == 0.0) {
  } else {
    c20_d_a = c20_c_ix0 - 1;
    c20_ix = c20_d_a;
    c20_e_a = c20_c_iy0 - 1;
    c20_iy = c20_e_a;
    c20_f_a = c20_c_n - 1;
    c20_i279 = c20_f_a;
    c20_b = c20_i279;
    c20_b_b = c20_b;
    if (0 > c20_b_b) {
      c20_overflow = FALSE;
    } else {
      c20_overflow = (c20_b_b > 2147483646);
    }

    if (c20_overflow) {
      c20_check_forloop_overflow_error(chartInstance, c20_overflow);
    }

    for (c20_k = 0; c20_k <= c20_i279; c20_k++) {
      c20_g_a = c20_iy;
      c20_c = c20_g_a;
      c20_h_a = c20_iy;
      c20_b_c = c20_h_a;
      c20_i_a = c20_ix;
      c20_c_c = c20_i_a;
      c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c20_c + 1)), 1, 9, 1, 0) - 1] =
        c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c20_b_c + 1)), 1, 9, 1, 0) - 1] + c20_c_a *
        c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c20_c_c + 1)), 1, 9, 1, 0) - 1];
      c20_j_a = c20_ix + 1;
      c20_ix = c20_j_a;
      c20_k_a = c20_iy + 1;
      c20_iy = c20_k_a;
    }
  }
}

static void c20_j_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_a, real_T c20_x[18], int32_T c20_ix0)
{
  real_T c20_b_a;
  int32_T c20_b_ix0;
  real_T c20_c_a;
  int32_T c20_c_ix0;
  int32_T c20_d_ix0;
  int32_T c20_d_a;
  int32_T c20_i280;
  int32_T c20_e_a;
  int32_T c20_b;
  int32_T c20_f_a;
  int32_T c20_b_b;
  boolean_T c20_overflow;
  int32_T c20_k;
  int32_T c20_b_k;
  c20_b_a = c20_a;
  c20_b_ix0 = c20_ix0;
  c20_c_a = c20_b_a;
  c20_c_ix0 = c20_b_ix0;
  c20_d_ix0 = c20_c_ix0;
  c20_d_a = c20_c_ix0 + 5;
  c20_i280 = c20_d_a;
  c20_e_a = c20_d_ix0;
  c20_b = c20_i280;
  c20_f_a = c20_e_a;
  c20_b_b = c20_b;
  if (c20_f_a > c20_b_b) {
    c20_overflow = FALSE;
  } else {
    c20_overflow = (c20_b_b > 2147483646);
  }

  if (c20_overflow) {
    c20_check_forloop_overflow_error(chartInstance, c20_overflow);
  }

  for (c20_k = c20_d_ix0; c20_k <= c20_i280; c20_k++) {
    c20_b_k = c20_k;
    c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_b_k), 1, 18, 1, 0) - 1] = c20_c_a *
      c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_b_k), 1, 18, 1, 0) - 1];
  }
}

static void c20_k_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_a, real_T c20_x[9], int32_T c20_ix0)
{
  real_T c20_b_a;
  int32_T c20_b_ix0;
  real_T c20_c_a;
  int32_T c20_c_ix0;
  int32_T c20_d_ix0;
  int32_T c20_d_a;
  int32_T c20_i281;
  int32_T c20_e_a;
  int32_T c20_b;
  int32_T c20_f_a;
  int32_T c20_b_b;
  boolean_T c20_overflow;
  int32_T c20_k;
  int32_T c20_b_k;
  c20_b_a = c20_a;
  c20_b_ix0 = c20_ix0;
  c20_c_a = c20_b_a;
  c20_c_ix0 = c20_b_ix0;
  c20_d_ix0 = c20_c_ix0;
  c20_d_a = c20_c_ix0 + 2;
  c20_i281 = c20_d_a;
  c20_e_a = c20_d_ix0;
  c20_b = c20_i281;
  c20_f_a = c20_e_a;
  c20_b_b = c20_b;
  if (c20_f_a > c20_b_b) {
    c20_overflow = FALSE;
  } else {
    c20_overflow = (c20_b_b > 2147483646);
  }

  if (c20_overflow) {
    c20_check_forloop_overflow_error(chartInstance, c20_overflow);
  }

  for (c20_k = c20_d_ix0; c20_k <= c20_i281; c20_k++) {
    c20_b_k = c20_k;
    c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_b_k), 1, 9, 1, 0) - 1] = c20_c_a *
      c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_b_k), 1, 9, 1, 0) - 1];
  }
}

static void c20_b_sqrt(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T *c20_x)
{
  if (*c20_x < 0.0) {
    c20_c_eml_error(chartInstance);
  }

  *c20_x = muDoubleScalarSqrt(*c20_x);
}

static void c20_b_eml_xrotg(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T *c20_a, real_T *c20_b, real_T *c20_c, real_T *c20_s)
{
  real_T c20_b_a;
  real_T c20_b_b;
  real_T c20_c_b;
  real_T c20_c_a;
  real_T c20_d_a;
  real_T c20_d_b;
  real_T c20_e_b;
  real_T c20_e_a;
  real_T c20_b_c;
  real_T c20_b_s;
  double * c20_a_t;
  double * c20_b_t;
  double * c20_c_t;
  double * c20_s_t;
  real_T c20_c_c;
  real_T c20_c_s;
  c20_b_a = *c20_a;
  c20_b_b = *c20_b;
  c20_c_b = c20_b_b;
  c20_c_a = c20_b_a;
  c20_d_a = c20_c_a;
  c20_d_b = c20_c_b;
  c20_e_b = c20_d_b;
  c20_e_a = c20_d_a;
  c20_b_c = 0.0;
  c20_b_s = 0.0;
  c20_a_t = (double *)(&c20_e_a);
  c20_b_t = (double *)(&c20_e_b);
  c20_c_t = (double *)(&c20_b_c);
  c20_s_t = (double *)(&c20_b_s);
  drotg(c20_a_t, c20_b_t, c20_c_t, c20_s_t);
  c20_c_a = c20_e_a;
  c20_c_b = c20_e_b;
  c20_c_c = c20_b_c;
  c20_c_s = c20_b_s;
  *c20_a = c20_c_a;
  *c20_b = c20_c_b;
  *c20_c = c20_c_c;
  *c20_s = c20_c_s;
}

static void c20_d_eml_xrot(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[9], int32_T c20_ix0, int32_T c20_iy0, real_T c20_c, real_T c20_s)
{
  int32_T c20_b_ix0;
  int32_T c20_b_iy0;
  real_T c20_b_c;
  real_T c20_b_s;
  int32_T c20_c_ix0;
  int32_T c20_c_iy0;
  real_T c20_c_c;
  real_T c20_c_s;
  int32_T c20_ix;
  int32_T c20_iy;
  int32_T c20_k;
  real_T c20_a;
  real_T c20_b;
  real_T c20_y;
  real_T c20_b_a;
  real_T c20_b_b;
  real_T c20_b_y;
  real_T c20_temp;
  real_T c20_c_a;
  real_T c20_c_b;
  real_T c20_c_y;
  real_T c20_d_a;
  real_T c20_d_b;
  real_T c20_d_y;
  int32_T c20_e_a;
  int32_T c20_f_a;
  c20_b_ix0 = c20_ix0;
  c20_b_iy0 = c20_iy0;
  c20_b_c = c20_c;
  c20_b_s = c20_s;
  c20_c_ix0 = c20_b_ix0;
  c20_c_iy0 = c20_b_iy0;
  c20_c_c = c20_b_c;
  c20_c_s = c20_b_s;
  c20_ix = c20_c_ix0;
  c20_iy = c20_c_iy0;
  for (c20_k = 1; c20_k < 4; c20_k++) {
    c20_a = c20_c_c;
    c20_b = c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_ix), 1, 9, 1, 0) - 1];
    c20_y = c20_a * c20_b;
    c20_b_a = c20_c_s;
    c20_b_b = c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c20_iy), 1, 9, 1, 0) - 1];
    c20_b_y = c20_b_a * c20_b_b;
    c20_temp = c20_y + c20_b_y;
    c20_c_a = c20_c_c;
    c20_c_b = c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c20_iy), 1, 9, 1, 0) - 1];
    c20_c_y = c20_c_a * c20_c_b;
    c20_d_a = c20_c_s;
    c20_d_b = c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c20_ix), 1, 9, 1, 0) - 1];
    c20_d_y = c20_d_a * c20_d_b;
    c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_iy), 1, 9, 1, 0) - 1] = c20_c_y - c20_d_y;
    c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_ix), 1, 9, 1, 0) - 1] = c20_temp;
    c20_e_a = c20_iy + 1;
    c20_iy = c20_e_a;
    c20_f_a = c20_ix + 1;
    c20_ix = c20_f_a;
  }
}

static void c20_e_eml_xrot(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[18], int32_T c20_ix0, int32_T c20_iy0, real_T c20_c, real_T c20_s)
{
  int32_T c20_b_ix0;
  int32_T c20_b_iy0;
  real_T c20_b_c;
  real_T c20_b_s;
  int32_T c20_c_ix0;
  int32_T c20_c_iy0;
  real_T c20_c_c;
  real_T c20_c_s;
  int32_T c20_ix;
  int32_T c20_iy;
  int32_T c20_k;
  real_T c20_a;
  real_T c20_b;
  real_T c20_y;
  real_T c20_b_a;
  real_T c20_b_b;
  real_T c20_b_y;
  real_T c20_temp;
  real_T c20_c_a;
  real_T c20_c_b;
  real_T c20_c_y;
  real_T c20_d_a;
  real_T c20_d_b;
  real_T c20_d_y;
  int32_T c20_e_a;
  int32_T c20_f_a;
  c20_b_ix0 = c20_ix0;
  c20_b_iy0 = c20_iy0;
  c20_b_c = c20_c;
  c20_b_s = c20_s;
  c20_c_ix0 = c20_b_ix0;
  c20_c_iy0 = c20_b_iy0;
  c20_c_c = c20_b_c;
  c20_c_s = c20_b_s;
  c20_ix = c20_c_ix0;
  c20_iy = c20_c_iy0;
  for (c20_k = 1; c20_k < 7; c20_k++) {
    c20_a = c20_c_c;
    c20_b = c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_ix), 1, 18, 1, 0) - 1];
    c20_y = c20_a * c20_b;
    c20_b_a = c20_c_s;
    c20_b_b = c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c20_iy), 1, 18, 1, 0) - 1];
    c20_b_y = c20_b_a * c20_b_b;
    c20_temp = c20_y + c20_b_y;
    c20_c_a = c20_c_c;
    c20_c_b = c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c20_iy), 1, 18, 1, 0) - 1];
    c20_c_y = c20_c_a * c20_c_b;
    c20_d_a = c20_c_s;
    c20_d_b = c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c20_ix), 1, 18, 1, 0) - 1];
    c20_d_y = c20_d_a * c20_d_b;
    c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_iy), 1, 18, 1, 0) - 1] = c20_c_y - c20_d_y;
    c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_ix), 1, 18, 1, 0) - 1] = c20_temp;
    c20_e_a = c20_iy + 1;
    c20_iy = c20_e_a;
    c20_f_a = c20_ix + 1;
    c20_ix = c20_f_a;
  }
}

static void c20_d_eml_xswap(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[9], int32_T c20_ix0, int32_T c20_iy0)
{
  int32_T c20_b_ix0;
  int32_T c20_b_iy0;
  int32_T c20_c_ix0;
  int32_T c20_c_iy0;
  int32_T c20_ix;
  int32_T c20_iy;
  int32_T c20_k;
  real_T c20_temp;
  int32_T c20_a;
  int32_T c20_b_a;
  c20_b_ix0 = c20_ix0;
  c20_b_iy0 = c20_iy0;
  c20_c_ix0 = c20_b_ix0;
  c20_c_iy0 = c20_b_iy0;
  c20_ix = c20_c_ix0;
  c20_iy = c20_c_iy0;
  for (c20_k = 1; c20_k < 4; c20_k++) {
    c20_temp = c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
      ("", (real_T)c20_ix), 1, 9, 1, 0) - 1];
    c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_ix), 1, 9, 1, 0) - 1] = c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_iy), 1, 9, 1, 0) - 1];
    c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_iy), 1, 9, 1, 0) - 1] = c20_temp;
    c20_a = c20_ix + 1;
    c20_ix = c20_a;
    c20_b_a = c20_iy + 1;
    c20_iy = c20_b_a;
  }
}

static void c20_e_eml_xswap(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[18], int32_T c20_ix0, int32_T c20_iy0)
{
  int32_T c20_b_ix0;
  int32_T c20_b_iy0;
  int32_T c20_c_ix0;
  int32_T c20_c_iy0;
  int32_T c20_ix;
  int32_T c20_iy;
  int32_T c20_k;
  real_T c20_temp;
  int32_T c20_a;
  int32_T c20_b_a;
  c20_b_ix0 = c20_ix0;
  c20_b_iy0 = c20_iy0;
  c20_c_ix0 = c20_b_ix0;
  c20_c_iy0 = c20_b_iy0;
  c20_ix = c20_c_ix0;
  c20_iy = c20_c_iy0;
  for (c20_k = 1; c20_k < 7; c20_k++) {
    c20_temp = c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
      ("", (real_T)c20_ix), 1, 18, 1, 0) - 1];
    c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_ix), 1, 18, 1, 0) - 1] = c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_iy), 1, 18, 1, 0) - 1];
    c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_iy), 1, 18, 1, 0) - 1] = c20_temp;
    c20_a = c20_ix + 1;
    c20_ix = c20_a;
    c20_b_a = c20_iy + 1;
    c20_iy = c20_b_a;
  }
}

static void c20_c_eml_xgemm(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_k, real_T c20_A[9], real_T c20_B[18], real_T c20_C[18])
{
  int32_T c20_b_k;
  int32_T c20_c_k;
  int32_T c20_a;
  int32_T c20_km1;
  int32_T c20_cr;
  int32_T c20_b_cr;
  int32_T c20_b_a;
  int32_T c20_i282;
  int32_T c20_c_a;
  int32_T c20_i283;
  int32_T c20_d_a;
  int32_T c20_b;
  int32_T c20_e_a;
  int32_T c20_b_b;
  boolean_T c20_overflow;
  int32_T c20_ic;
  int32_T c20_b_ic;
  int32_T c20_br;
  int32_T c20_c_cr;
  int32_T c20_ar;
  int32_T c20_f_a;
  int32_T c20_b_br;
  int32_T c20_c_b;
  int32_T c20_c;
  int32_T c20_g_a;
  int32_T c20_d_b;
  int32_T c20_i284;
  int32_T c20_h_a;
  int32_T c20_e_b;
  int32_T c20_i_a;
  int32_T c20_f_b;
  boolean_T c20_b_overflow;
  int32_T c20_ib;
  int32_T c20_b_ib;
  real_T c20_temp;
  int32_T c20_ia;
  int32_T c20_j_a;
  int32_T c20_i285;
  int32_T c20_k_a;
  int32_T c20_i286;
  int32_T c20_l_a;
  int32_T c20_g_b;
  int32_T c20_m_a;
  int32_T c20_h_b;
  boolean_T c20_c_overflow;
  int32_T c20_c_ic;
  int32_T c20_n_a;
  int32_T c20_o_a;
  c20_b_k = c20_k;
  c20_c_k = c20_b_k;
  c20_a = c20_c_k;
  c20_km1 = c20_a;
  for (c20_cr = 0; c20_cr < 16; c20_cr += 3) {
    c20_b_cr = c20_cr;
    c20_b_a = c20_b_cr + 1;
    c20_i282 = c20_b_a;
    c20_c_a = c20_b_cr + 3;
    c20_i283 = c20_c_a;
    c20_d_a = c20_i282;
    c20_b = c20_i283;
    c20_e_a = c20_d_a;
    c20_b_b = c20_b;
    if (c20_e_a > c20_b_b) {
      c20_overflow = FALSE;
    } else {
      c20_overflow = (c20_b_b > 2147483646);
    }

    if (c20_overflow) {
      c20_check_forloop_overflow_error(chartInstance, c20_overflow);
    }

    for (c20_ic = c20_i282; c20_ic <= c20_i283; c20_ic++) {
      c20_b_ic = c20_ic;
      c20_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c20_b_ic), 1, 18, 1, 0) - 1] = 0.0;
    }
  }

  c20_br = 0;
  for (c20_c_cr = 0; c20_c_cr < 16; c20_c_cr += 3) {
    c20_b_cr = c20_c_cr;
    c20_ar = 0;
    c20_f_a = c20_br + 1;
    c20_br = c20_f_a;
    c20_b_br = c20_br;
    c20_c_b = c20_km1 - 1;
    c20_c = 6 * c20_c_b;
    c20_g_a = c20_br;
    c20_d_b = c20_c;
    c20_i284 = c20_g_a + c20_d_b;
    c20_h_a = c20_b_br;
    c20_e_b = c20_i284;
    c20_i_a = c20_h_a;
    c20_f_b = c20_e_b;
    if (c20_i_a > c20_f_b) {
      c20_b_overflow = FALSE;
    } else {
      c20_b_overflow = (c20_f_b > 2147483641);
    }

    if (c20_b_overflow) {
      c20_check_forloop_overflow_error(chartInstance, c20_b_overflow);
    }

    for (c20_ib = c20_b_br; c20_ib <= c20_i284; c20_ib += 6) {
      c20_b_ib = c20_ib;
      if (c20_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_ib), 1, 18, 1, 0) - 1] != 0.0) {
        c20_temp = c20_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_b_ib), 1, 18, 1, 0) - 1];
        c20_ia = c20_ar;
        c20_j_a = c20_b_cr + 1;
        c20_i285 = c20_j_a;
        c20_k_a = c20_b_cr + 3;
        c20_i286 = c20_k_a;
        c20_l_a = c20_i285;
        c20_g_b = c20_i286;
        c20_m_a = c20_l_a;
        c20_h_b = c20_g_b;
        if (c20_m_a > c20_h_b) {
          c20_c_overflow = FALSE;
        } else {
          c20_c_overflow = (c20_h_b > 2147483646);
        }

        if (c20_c_overflow) {
          c20_check_forloop_overflow_error(chartInstance, c20_c_overflow);
        }

        for (c20_c_ic = c20_i285; c20_c_ic <= c20_i286; c20_c_ic++) {
          c20_b_ic = c20_c_ic;
          c20_n_a = c20_ia + 1;
          c20_ia = c20_n_a;
          c20_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_ic), 1, 18, 1, 0) - 1] =
            c20_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_ic), 1, 18, 1, 0) - 1] + c20_temp *
            c20_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_ia), 1, 9, 1, 0) - 1];
        }
      }

      c20_o_a = c20_ar + 3;
      c20_ar = c20_o_a;
    }
  }
}

static void c20_l_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[36], int32_T c20_ix0)
{
  int32_T c20_b_n;
  real_T c20_b_a;
  int32_T c20_b_ix0;
  int32_T c20_c_n;
  real_T c20_c_a;
  int32_T c20_c_ix0;
  int32_T c20_d_ix0;
  int32_T c20_d_a;
  int32_T c20_c;
  int32_T c20_b;
  int32_T c20_b_c;
  int32_T c20_e_a;
  int32_T c20_b_b;
  int32_T c20_i287;
  int32_T c20_f_a;
  int32_T c20_c_b;
  int32_T c20_g_a;
  int32_T c20_d_b;
  boolean_T c20_overflow;
  int32_T c20_k;
  int32_T c20_b_k;
  c20_b_n = c20_n;
  c20_b_a = c20_a;
  c20_b_ix0 = c20_ix0;
  c20_c_n = c20_b_n;
  c20_c_a = c20_b_a;
  c20_c_ix0 = c20_b_ix0;
  c20_d_ix0 = c20_c_ix0;
  c20_d_a = c20_c_n;
  c20_c = c20_d_a;
  c20_b = c20_c - 1;
  c20_b_c = c20_b;
  c20_e_a = c20_c_ix0;
  c20_b_b = c20_b_c;
  c20_i287 = c20_e_a + c20_b_b;
  c20_f_a = c20_d_ix0;
  c20_c_b = c20_i287;
  c20_g_a = c20_f_a;
  c20_d_b = c20_c_b;
  if (c20_g_a > c20_d_b) {
    c20_overflow = FALSE;
  } else {
    c20_overflow = (c20_d_b > 2147483646);
  }

  if (c20_overflow) {
    c20_check_forloop_overflow_error(chartInstance, c20_overflow);
  }

  for (c20_k = c20_d_ix0; c20_k <= c20_i287; c20_k++) {
    c20_b_k = c20_k;
    c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_b_k), 1, 36, 1, 0) - 1] = c20_c_a *
      c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_b_k), 1, 36, 1, 0) - 1];
  }
}

static void c20_l_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, int32_T c20_ix0, real_T c20_y[36], int32_T
  c20_iy0)
{
  int32_T c20_b_n;
  real_T c20_b_a;
  int32_T c20_b_ix0;
  int32_T c20_b_iy0;
  int32_T c20_c_n;
  real_T c20_c_a;
  int32_T c20_c_ix0;
  int32_T c20_c_iy0;
  int32_T c20_d_a;
  int32_T c20_ix;
  int32_T c20_e_a;
  int32_T c20_iy;
  int32_T c20_f_a;
  int32_T c20_i288;
  int32_T c20_b;
  int32_T c20_b_b;
  boolean_T c20_overflow;
  int32_T c20_k;
  int32_T c20_g_a;
  int32_T c20_c;
  int32_T c20_h_a;
  int32_T c20_b_c;
  int32_T c20_i_a;
  int32_T c20_c_c;
  int32_T c20_j_a;
  int32_T c20_k_a;
  c20_b_n = c20_n;
  c20_b_a = c20_a;
  c20_b_ix0 = c20_ix0;
  c20_b_iy0 = c20_iy0;
  c20_c_n = c20_b_n;
  c20_c_a = c20_b_a;
  c20_c_ix0 = c20_b_ix0;
  c20_c_iy0 = c20_b_iy0;
  if (c20_c_n < 1) {
  } else if (c20_c_a == 0.0) {
  } else {
    c20_d_a = c20_c_ix0 - 1;
    c20_ix = c20_d_a;
    c20_e_a = c20_c_iy0 - 1;
    c20_iy = c20_e_a;
    c20_f_a = c20_c_n - 1;
    c20_i288 = c20_f_a;
    c20_b = c20_i288;
    c20_b_b = c20_b;
    if (0 > c20_b_b) {
      c20_overflow = FALSE;
    } else {
      c20_overflow = (c20_b_b > 2147483646);
    }

    if (c20_overflow) {
      c20_check_forloop_overflow_error(chartInstance, c20_overflow);
    }

    for (c20_k = 0; c20_k <= c20_i288; c20_k++) {
      c20_g_a = c20_iy;
      c20_c = c20_g_a;
      c20_h_a = c20_iy;
      c20_b_c = c20_h_a;
      c20_i_a = c20_ix;
      c20_c_c = c20_i_a;
      c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c20_c + 1)), 1, 36, 1, 0) - 1] =
        c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c20_b_c + 1)), 1, 36, 1, 0) - 1] + c20_c_a *
        c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c20_c_c + 1)), 1, 36, 1, 0) - 1];
      c20_j_a = c20_ix + 1;
      c20_ix = c20_j_a;
      c20_k_a = c20_iy + 1;
      c20_iy = c20_k_a;
    }
  }
}

static void c20_m_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[6], int32_T c20_ix0)
{
  int32_T c20_b_n;
  real_T c20_b_a;
  int32_T c20_b_ix0;
  int32_T c20_c_n;
  real_T c20_c_a;
  int32_T c20_c_ix0;
  int32_T c20_d_ix0;
  int32_T c20_d_a;
  int32_T c20_c;
  int32_T c20_b;
  int32_T c20_b_c;
  int32_T c20_e_a;
  int32_T c20_b_b;
  int32_T c20_i289;
  int32_T c20_f_a;
  int32_T c20_c_b;
  int32_T c20_g_a;
  int32_T c20_d_b;
  boolean_T c20_overflow;
  int32_T c20_k;
  int32_T c20_b_k;
  c20_b_n = c20_n;
  c20_b_a = c20_a;
  c20_b_ix0 = c20_ix0;
  c20_c_n = c20_b_n;
  c20_c_a = c20_b_a;
  c20_c_ix0 = c20_b_ix0;
  c20_d_ix0 = c20_c_ix0;
  c20_d_a = c20_c_n;
  c20_c = c20_d_a;
  c20_b = c20_c - 1;
  c20_b_c = c20_b;
  c20_e_a = c20_c_ix0;
  c20_b_b = c20_b_c;
  c20_i289 = c20_e_a + c20_b_b;
  c20_f_a = c20_d_ix0;
  c20_c_b = c20_i289;
  c20_g_a = c20_f_a;
  c20_d_b = c20_c_b;
  if (c20_g_a > c20_d_b) {
    c20_overflow = FALSE;
  } else {
    c20_overflow = (c20_d_b > 2147483646);
  }

  if (c20_overflow) {
    c20_check_forloop_overflow_error(chartInstance, c20_overflow);
  }

  for (c20_k = c20_d_ix0; c20_k <= c20_i289; c20_k++) {
    c20_b_k = c20_k;
    c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_b_k), 1, 6, 1, 0) - 1] = c20_c_a *
      c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_b_k), 1, 6, 1, 0) - 1];
  }
}

static void c20_m_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[36], int32_T c20_ix0, real_T c20_y[6],
  int32_T c20_iy0)
{
  int32_T c20_b_n;
  real_T c20_b_a;
  int32_T c20_b_ix0;
  int32_T c20_b_iy0;
  int32_T c20_c_n;
  real_T c20_c_a;
  int32_T c20_c_ix0;
  int32_T c20_c_iy0;
  int32_T c20_d_a;
  int32_T c20_ix;
  int32_T c20_e_a;
  int32_T c20_iy;
  int32_T c20_f_a;
  int32_T c20_i290;
  int32_T c20_b;
  int32_T c20_b_b;
  boolean_T c20_overflow;
  int32_T c20_k;
  int32_T c20_g_a;
  int32_T c20_c;
  int32_T c20_h_a;
  int32_T c20_b_c;
  int32_T c20_i_a;
  int32_T c20_c_c;
  int32_T c20_j_a;
  int32_T c20_k_a;
  c20_b_n = c20_n;
  c20_b_a = c20_a;
  c20_b_ix0 = c20_ix0;
  c20_b_iy0 = c20_iy0;
  c20_c_n = c20_b_n;
  c20_c_a = c20_b_a;
  c20_c_ix0 = c20_b_ix0;
  c20_c_iy0 = c20_b_iy0;
  if (c20_c_n < 1) {
  } else if (c20_c_a == 0.0) {
  } else {
    c20_d_a = c20_c_ix0 - 1;
    c20_ix = c20_d_a;
    c20_e_a = c20_c_iy0 - 1;
    c20_iy = c20_e_a;
    c20_f_a = c20_c_n - 1;
    c20_i290 = c20_f_a;
    c20_b = c20_i290;
    c20_b_b = c20_b;
    if (0 > c20_b_b) {
      c20_overflow = FALSE;
    } else {
      c20_overflow = (c20_b_b > 2147483646);
    }

    if (c20_overflow) {
      c20_check_forloop_overflow_error(chartInstance, c20_overflow);
    }

    for (c20_k = 0; c20_k <= c20_i290; c20_k++) {
      c20_g_a = c20_iy;
      c20_c = c20_g_a;
      c20_h_a = c20_iy;
      c20_b_c = c20_h_a;
      c20_i_a = c20_ix;
      c20_c_c = c20_i_a;
      c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c20_c + 1)), 1, 6, 1, 0) - 1] =
        c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c20_b_c + 1)), 1, 6, 1, 0) - 1] + c20_c_a *
        c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c20_c_c + 1)), 1, 36, 1, 0) - 1];
      c20_j_a = c20_ix + 1;
      c20_ix = c20_j_a;
      c20_k_a = c20_iy + 1;
      c20_iy = c20_k_a;
    }
  }
}

static void c20_n_eml_xaxpy(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_n, real_T c20_a, real_T c20_x[6], int32_T c20_ix0, real_T c20_y[36],
  int32_T c20_iy0)
{
  int32_T c20_b_n;
  real_T c20_b_a;
  int32_T c20_b_ix0;
  int32_T c20_b_iy0;
  int32_T c20_c_n;
  real_T c20_c_a;
  int32_T c20_c_ix0;
  int32_T c20_c_iy0;
  int32_T c20_d_a;
  int32_T c20_ix;
  int32_T c20_e_a;
  int32_T c20_iy;
  int32_T c20_f_a;
  int32_T c20_i291;
  int32_T c20_b;
  int32_T c20_b_b;
  boolean_T c20_overflow;
  int32_T c20_k;
  int32_T c20_g_a;
  int32_T c20_c;
  int32_T c20_h_a;
  int32_T c20_b_c;
  int32_T c20_i_a;
  int32_T c20_c_c;
  int32_T c20_j_a;
  int32_T c20_k_a;
  c20_b_n = c20_n;
  c20_b_a = c20_a;
  c20_b_ix0 = c20_ix0;
  c20_b_iy0 = c20_iy0;
  c20_c_n = c20_b_n;
  c20_c_a = c20_b_a;
  c20_c_ix0 = c20_b_ix0;
  c20_c_iy0 = c20_b_iy0;
  if (c20_c_n < 1) {
  } else if (c20_c_a == 0.0) {
  } else {
    c20_d_a = c20_c_ix0 - 1;
    c20_ix = c20_d_a;
    c20_e_a = c20_c_iy0 - 1;
    c20_iy = c20_e_a;
    c20_f_a = c20_c_n - 1;
    c20_i291 = c20_f_a;
    c20_b = c20_i291;
    c20_b_b = c20_b;
    if (0 > c20_b_b) {
      c20_overflow = FALSE;
    } else {
      c20_overflow = (c20_b_b > 2147483646);
    }

    if (c20_overflow) {
      c20_check_forloop_overflow_error(chartInstance, c20_overflow);
    }

    for (c20_k = 0; c20_k <= c20_i291; c20_k++) {
      c20_g_a = c20_iy;
      c20_c = c20_g_a;
      c20_h_a = c20_iy;
      c20_b_c = c20_h_a;
      c20_i_a = c20_ix;
      c20_c_c = c20_i_a;
      c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c20_c + 1)), 1, 36, 1, 0) - 1] =
        c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c20_b_c + 1)), 1, 36, 1, 0) - 1] + c20_c_a *
        c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c20_c_c + 1)), 1, 6, 1, 0) - 1];
      c20_j_a = c20_ix + 1;
      c20_ix = c20_j_a;
      c20_k_a = c20_iy + 1;
      c20_iy = c20_k_a;
    }
  }
}

static void c20_n_eml_xscal(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_a, real_T c20_x[36], int32_T c20_ix0)
{
  real_T c20_b_a;
  int32_T c20_b_ix0;
  real_T c20_c_a;
  int32_T c20_c_ix0;
  int32_T c20_d_ix0;
  int32_T c20_d_a;
  int32_T c20_i292;
  int32_T c20_e_a;
  int32_T c20_b;
  int32_T c20_f_a;
  int32_T c20_b_b;
  boolean_T c20_overflow;
  int32_T c20_k;
  int32_T c20_b_k;
  c20_b_a = c20_a;
  c20_b_ix0 = c20_ix0;
  c20_c_a = c20_b_a;
  c20_c_ix0 = c20_b_ix0;
  c20_d_ix0 = c20_c_ix0;
  c20_d_a = c20_c_ix0 + 5;
  c20_i292 = c20_d_a;
  c20_e_a = c20_d_ix0;
  c20_b = c20_i292;
  c20_f_a = c20_e_a;
  c20_b_b = c20_b;
  if (c20_f_a > c20_b_b) {
    c20_overflow = FALSE;
  } else {
    c20_overflow = (c20_b_b > 2147483646);
  }

  if (c20_overflow) {
    c20_check_forloop_overflow_error(chartInstance, c20_overflow);
  }

  for (c20_k = c20_d_ix0; c20_k <= c20_i292; c20_k++) {
    c20_b_k = c20_k;
    c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_b_k), 1, 36, 1, 0) - 1] = c20_c_a *
      c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_b_k), 1, 36, 1, 0) - 1];
  }
}

static void c20_f_eml_xrot(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[36], int32_T c20_ix0, int32_T c20_iy0, real_T c20_c, real_T c20_s)
{
  int32_T c20_b_ix0;
  int32_T c20_b_iy0;
  real_T c20_b_c;
  real_T c20_b_s;
  int32_T c20_c_ix0;
  int32_T c20_c_iy0;
  real_T c20_c_c;
  real_T c20_c_s;
  int32_T c20_ix;
  int32_T c20_iy;
  int32_T c20_k;
  real_T c20_a;
  real_T c20_b;
  real_T c20_y;
  real_T c20_b_a;
  real_T c20_b_b;
  real_T c20_b_y;
  real_T c20_temp;
  real_T c20_c_a;
  real_T c20_c_b;
  real_T c20_c_y;
  real_T c20_d_a;
  real_T c20_d_b;
  real_T c20_d_y;
  int32_T c20_e_a;
  int32_T c20_f_a;
  c20_b_ix0 = c20_ix0;
  c20_b_iy0 = c20_iy0;
  c20_b_c = c20_c;
  c20_b_s = c20_s;
  c20_c_ix0 = c20_b_ix0;
  c20_c_iy0 = c20_b_iy0;
  c20_c_c = c20_b_c;
  c20_c_s = c20_b_s;
  c20_ix = c20_c_ix0;
  c20_iy = c20_c_iy0;
  for (c20_k = 1; c20_k < 7; c20_k++) {
    c20_a = c20_c_c;
    c20_b = c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_ix), 1, 36, 1, 0) - 1];
    c20_y = c20_a * c20_b;
    c20_b_a = c20_c_s;
    c20_b_b = c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c20_iy), 1, 36, 1, 0) - 1];
    c20_b_y = c20_b_a * c20_b_b;
    c20_temp = c20_y + c20_b_y;
    c20_c_a = c20_c_c;
    c20_c_b = c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c20_iy), 1, 36, 1, 0) - 1];
    c20_c_y = c20_c_a * c20_c_b;
    c20_d_a = c20_c_s;
    c20_d_b = c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c20_ix), 1, 36, 1, 0) - 1];
    c20_d_y = c20_d_a * c20_d_b;
    c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_iy), 1, 36, 1, 0) - 1] = c20_c_y - c20_d_y;
    c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_ix), 1, 36, 1, 0) - 1] = c20_temp;
    c20_e_a = c20_iy + 1;
    c20_iy = c20_e_a;
    c20_f_a = c20_ix + 1;
    c20_ix = c20_f_a;
  }
}

static void c20_f_eml_xswap(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c20_x[36], int32_T c20_ix0, int32_T c20_iy0)
{
  int32_T c20_b_ix0;
  int32_T c20_b_iy0;
  int32_T c20_c_ix0;
  int32_T c20_c_iy0;
  int32_T c20_ix;
  int32_T c20_iy;
  int32_T c20_k;
  real_T c20_temp;
  int32_T c20_a;
  int32_T c20_b_a;
  c20_b_ix0 = c20_ix0;
  c20_b_iy0 = c20_iy0;
  c20_below_threshold(chartInstance);
  c20_c_ix0 = c20_b_ix0;
  c20_c_iy0 = c20_b_iy0;
  c20_ix = c20_c_ix0;
  c20_iy = c20_c_iy0;
  for (c20_k = 1; c20_k < 7; c20_k++) {
    c20_temp = c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
      ("", (real_T)c20_ix), 1, 36, 1, 0) - 1];
    c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_ix), 1, 36, 1, 0) - 1] = c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_iy), 1, 36, 1, 0) - 1];
    c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c20_iy), 1, 36, 1, 0) - 1] = c20_temp;
    c20_a = c20_ix + 1;
    c20_ix = c20_a;
    c20_b_a = c20_iy + 1;
    c20_iy = c20_b_a;
  }
}

static void c20_d_eml_xgemm(SFc20_CusakisME4901arcsInstanceStruct *chartInstance,
  int32_T c20_k, real_T c20_A[36], real_T c20_B[36], real_T c20_C[36])
{
  int32_T c20_b_k;
  int32_T c20_c_k;
  int32_T c20_a;
  int32_T c20_km1;
  int32_T c20_cr;
  int32_T c20_b_cr;
  int32_T c20_b_a;
  int32_T c20_i293;
  int32_T c20_c_a;
  int32_T c20_i294;
  int32_T c20_d_a;
  int32_T c20_b;
  int32_T c20_e_a;
  int32_T c20_b_b;
  boolean_T c20_overflow;
  int32_T c20_ic;
  int32_T c20_b_ic;
  int32_T c20_br;
  int32_T c20_c_cr;
  int32_T c20_ar;
  int32_T c20_f_a;
  int32_T c20_b_br;
  int32_T c20_c_b;
  int32_T c20_c;
  int32_T c20_g_a;
  int32_T c20_d_b;
  int32_T c20_i295;
  int32_T c20_h_a;
  int32_T c20_e_b;
  int32_T c20_i_a;
  int32_T c20_f_b;
  boolean_T c20_b_overflow;
  int32_T c20_ib;
  int32_T c20_b_ib;
  real_T c20_temp;
  int32_T c20_ia;
  int32_T c20_j_a;
  int32_T c20_i296;
  int32_T c20_k_a;
  int32_T c20_i297;
  int32_T c20_l_a;
  int32_T c20_g_b;
  int32_T c20_m_a;
  int32_T c20_h_b;
  boolean_T c20_c_overflow;
  int32_T c20_c_ic;
  int32_T c20_n_a;
  int32_T c20_o_a;
  c20_b_k = c20_k;
  c20_c_k = c20_b_k;
  c20_a = c20_c_k;
  c20_km1 = c20_a;
  for (c20_cr = 0; c20_cr < 31; c20_cr += 6) {
    c20_b_cr = c20_cr;
    c20_b_a = c20_b_cr + 1;
    c20_i293 = c20_b_a;
    c20_c_a = c20_b_cr + 6;
    c20_i294 = c20_c_a;
    c20_d_a = c20_i293;
    c20_b = c20_i294;
    c20_e_a = c20_d_a;
    c20_b_b = c20_b;
    if (c20_e_a > c20_b_b) {
      c20_overflow = FALSE;
    } else {
      c20_overflow = (c20_b_b > 2147483646);
    }

    if (c20_overflow) {
      c20_check_forloop_overflow_error(chartInstance, c20_overflow);
    }

    for (c20_ic = c20_i293; c20_ic <= c20_i294; c20_ic++) {
      c20_b_ic = c20_ic;
      c20_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c20_b_ic), 1, 36, 1, 0) - 1] = 0.0;
    }
  }

  c20_br = 0;
  for (c20_c_cr = 0; c20_c_cr < 31; c20_c_cr += 6) {
    c20_b_cr = c20_c_cr;
    c20_ar = 0;
    c20_f_a = c20_br + 1;
    c20_br = c20_f_a;
    c20_b_br = c20_br;
    c20_c_b = c20_km1 - 1;
    c20_c = 6 * c20_c_b;
    c20_g_a = c20_br;
    c20_d_b = c20_c;
    c20_i295 = c20_g_a + c20_d_b;
    c20_h_a = c20_b_br;
    c20_e_b = c20_i295;
    c20_i_a = c20_h_a;
    c20_f_b = c20_e_b;
    if (c20_i_a > c20_f_b) {
      c20_b_overflow = FALSE;
    } else {
      c20_b_overflow = (c20_f_b > 2147483641);
    }

    if (c20_b_overflow) {
      c20_check_forloop_overflow_error(chartInstance, c20_b_overflow);
    }

    for (c20_ib = c20_b_br; c20_ib <= c20_i295; c20_ib += 6) {
      c20_b_ib = c20_ib;
      if (c20_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_ib), 1, 36, 1, 0) - 1] != 0.0) {
        c20_temp = c20_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_b_ib), 1, 36, 1, 0) - 1];
        c20_ia = c20_ar;
        c20_j_a = c20_b_cr + 1;
        c20_i296 = c20_j_a;
        c20_k_a = c20_b_cr + 6;
        c20_i297 = c20_k_a;
        c20_l_a = c20_i296;
        c20_g_b = c20_i297;
        c20_m_a = c20_l_a;
        c20_h_b = c20_g_b;
        if (c20_m_a > c20_h_b) {
          c20_c_overflow = FALSE;
        } else {
          c20_c_overflow = (c20_h_b > 2147483646);
        }

        if (c20_c_overflow) {
          c20_check_forloop_overflow_error(chartInstance, c20_c_overflow);
        }

        for (c20_c_ic = c20_i296; c20_c_ic <= c20_i297; c20_c_ic++) {
          c20_b_ic = c20_c_ic;
          c20_n_a = c20_ia + 1;
          c20_ia = c20_n_a;
          c20_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_ic), 1, 36, 1, 0) - 1] =
            c20_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_b_ic), 1, 36, 1, 0) - 1] + c20_temp *
            c20_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_ia), 1, 36, 1, 0) - 1];
        }
      }

      c20_o_a = c20_ar + 6;
      c20_ar = c20_o_a;
    }
  }
}

static void init_dsm_address_info(SFc20_CusakisME4901arcsInstanceStruct
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

void sf_c20_CusakisME4901arcs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3775404811U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4010691266U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(881871923U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(896062794U);
}

mxArray *sf_c20_CusakisME4901arcs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("psAfe1xr5Sr93CrpUQBciF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
      pr[0] = (double)(6);
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
      pr[0] = (double)(6);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
      pr[0] = (double)(6);
      pr[1] = (double)(3);
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
      pr[0] = (double)(6);
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

mxArray *sf_c20_CusakisME4901arcs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c20_CusakisME4901arcs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[31],T\"Jstar\",},{M[1],M[32],T\"SCnew\",},{M[1],M[5],T\"qd_req\",},{M[1],M[33],T\"qd_reqW\",},{M[8],M[0],T\"is_active_c20_CusakisME4901arcs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c20_CusakisME4901arcs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc20_CusakisME4901arcsInstanceStruct *chartInstance;
    chartInstance = (SFc20_CusakisME4901arcsInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CusakisME4901arcsMachineNumber_,
           20,
           1,
           1,
           14,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"qd_req");
          _SFD_SET_DATA_PROPS(1,2,0,1,"qd_reqW");
          _SFD_SET_DATA_PROPS(2,1,1,0,"qqd");
          _SFD_SET_DATA_PROPS(3,1,1,0,"q3rd");
          _SFD_SET_DATA_PROPS(4,1,1,0,"Ve");
          _SFD_SET_DATA_PROPS(5,1,1,0,"SC");
          _SFD_SET_DATA_PROPS(6,10,0,0,"l");
          _SFD_SET_DATA_PROPS(7,10,0,0,"m");
          _SFD_SET_DATA_PROPS(8,10,0,0,"I");
          _SFD_SET_DATA_PROPS(9,10,0,0,"lb");
          _SFD_SET_DATA_PROPS(10,10,0,0,"mb");
          _SFD_SET_DATA_PROPS(11,10,0,0,"Ib");
          _SFD_SET_DATA_PROPS(12,2,0,1,"Jstar");
          _SFD_SET_DATA_PROPS(13,2,0,1,"SCnew");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,17013);
        _SFD_CV_INIT_EML_IF(0,1,0,16885,16898,16909,16950);
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
            1.0,0,0,(MexFcnForType)c20_c_sf_marshallOut,(MexInFcnForType)
            c20_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_c_sf_marshallOut,(MexInFcnForType)
            c20_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_d_sf_marshallOut,(MexInFcnForType)
          c20_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_d_sf_marshallOut,(MexInFcnForType)
          c20_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_d_sf_marshallOut,(MexInFcnForType)
          c20_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_d_sf_marshallOut,(MexInFcnForType)
          c20_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_d_sf_marshallOut,(MexInFcnForType)
          c20_d_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_d_sf_marshallOut,(MexInFcnForType)
          c20_d_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 6;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)
            c20_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)
            c20_sf_marshallIn);
        }

        {
          real_T *c20_q3rd;
          real_T (*c20_qd_req)[3];
          real_T (*c20_qd_reqW)[3];
          real_T (*c20_qqd)[9];
          real_T (*c20_Ve)[6];
          real_T (*c20_SC)[6];
          real_T (*c20_Jstar)[18];
          real_T (*c20_SCnew)[6];
          c20_SCnew = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 4);
          c20_Jstar = (real_T (*)[18])ssGetOutputPortSignal(chartInstance->S, 3);
          c20_SC = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 3);
          c20_Ve = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
          c20_q3rd = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c20_qqd = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          c20_qd_reqW = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
          c20_qd_req = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c20_qd_req);
          _SFD_SET_DATA_VALUE_PTR(1U, *c20_qd_reqW);
          _SFD_SET_DATA_VALUE_PTR(2U, *c20_qqd);
          _SFD_SET_DATA_VALUE_PTR(3U, c20_q3rd);
          _SFD_SET_DATA_VALUE_PTR(4U, *c20_Ve);
          _SFD_SET_DATA_VALUE_PTR(5U, *c20_SC);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c20_l);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c20_m);
          _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c20_I);
          _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance->c20_lb);
          _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance->c20_mb);
          _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance->c20_Ib);
          _SFD_SET_DATA_VALUE_PTR(12U, *c20_Jstar);
          _SFD_SET_DATA_VALUE_PTR(13U, *c20_SCnew);
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
  return "5Rxk1Rn6lzYXJ6JOiGKDgD";
}

static void sf_opaque_initialize_c20_CusakisME4901arcs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc20_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c20_CusakisME4901arcs((SFc20_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
  initialize_c20_CusakisME4901arcs((SFc20_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c20_CusakisME4901arcs(void *chartInstanceVar)
{
  enable_c20_CusakisME4901arcs((SFc20_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c20_CusakisME4901arcs(void *chartInstanceVar)
{
  disable_c20_CusakisME4901arcs((SFc20_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c20_CusakisME4901arcs(void *chartInstanceVar)
{
  sf_c20_CusakisME4901arcs((SFc20_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c20_CusakisME4901arcs(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c20_CusakisME4901arcs
    ((SFc20_CusakisME4901arcsInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c20_CusakisME4901arcs();/* state var info */
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

extern void sf_internal_set_sim_state_c20_CusakisME4901arcs(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c20_CusakisME4901arcs();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c20_CusakisME4901arcs((SFc20_CusakisME4901arcsInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c20_CusakisME4901arcs(SimStruct* S)
{
  return sf_internal_get_sim_state_c20_CusakisME4901arcs(S);
}

static void sf_opaque_set_sim_state_c20_CusakisME4901arcs(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c20_CusakisME4901arcs(S, st);
}

static void sf_opaque_terminate_c20_CusakisME4901arcs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc20_CusakisME4901arcsInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CusakisME4901arcs_optimization_info();
    }

    finalize_c20_CusakisME4901arcs((SFc20_CusakisME4901arcsInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc20_CusakisME4901arcs((SFc20_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c20_CusakisME4901arcs(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c20_CusakisME4901arcs
      ((SFc20_CusakisME4901arcsInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c20_CusakisME4901arcs(SimStruct *S)
{
  /* Actual parameters from chart:
     I Ib l lb m mb
   */
  const char_T *rtParamNames[] = { "I", "Ib", "l", "lb", "m", "mb" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for I*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for Ib*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for l*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for lb*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);

  /* registration for m*/
  ssRegDlgParamAsRunTimeParam(S, 4, 4, rtParamNames[4], SS_DOUBLE);

  /* registration for mb*/
  ssRegDlgParamAsRunTimeParam(S, 5, 5, rtParamNames[5], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CusakisME4901arcs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      20);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,20,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,20,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,20);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,20,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,20,4);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,20);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1248692127U));
  ssSetChecksum1(S,(1723993966U));
  ssSetChecksum2(S,(2617695372U));
  ssSetChecksum3(S,(1753961023U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c20_CusakisME4901arcs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c20_CusakisME4901arcs(SimStruct *S)
{
  SFc20_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc20_CusakisME4901arcsInstanceStruct *)utMalloc(sizeof
    (SFc20_CusakisME4901arcsInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc20_CusakisME4901arcsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c20_CusakisME4901arcs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c20_CusakisME4901arcs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c20_CusakisME4901arcs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c20_CusakisME4901arcs;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c20_CusakisME4901arcs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c20_CusakisME4901arcs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c20_CusakisME4901arcs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c20_CusakisME4901arcs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c20_CusakisME4901arcs;
  chartInstance->chartInfo.mdlStart = mdlStart_c20_CusakisME4901arcs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c20_CusakisME4901arcs;
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

void c20_CusakisME4901arcs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c20_CusakisME4901arcs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c20_CusakisME4901arcs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c20_CusakisME4901arcs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c20_CusakisME4901arcs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
