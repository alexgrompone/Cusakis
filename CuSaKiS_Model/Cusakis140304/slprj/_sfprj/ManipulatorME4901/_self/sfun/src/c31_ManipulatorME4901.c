/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ManipulatorME4901_sfun.h"
#include "c31_ManipulatorME4901.h"
#include <string.h>
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
static const char * c31_debug_family_names[26] = { "BaseV", "M1V", "M2V", "M3V",
  "EndV", "OtherV", "nargin", "nargout", "Base", "M1", "M2", "M3", "End",
  "other", "HiBase", "LoBase", "HiM1", "LoM1", "HiM2", "LoM2", "HiM3", "LoM3",
  "HiEnd", "LoEnd", "HiO", "LoO" };

/* Function Declarations */
static void initialize_c31_ManipulatorME4901
  (SFc31_ManipulatorME4901InstanceStruct *chartInstance);
static void initialize_params_c31_ManipulatorME4901
  (SFc31_ManipulatorME4901InstanceStruct *chartInstance);
static void enable_c31_ManipulatorME4901(SFc31_ManipulatorME4901InstanceStruct
  *chartInstance);
static void disable_c31_ManipulatorME4901(SFc31_ManipulatorME4901InstanceStruct *
  chartInstance);
static void c31_update_debugger_state_c31_ManipulatorME4901
  (SFc31_ManipulatorME4901InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c31_ManipulatorME4901
  (SFc31_ManipulatorME4901InstanceStruct *chartInstance);
static void set_sim_state_c31_ManipulatorME4901
  (SFc31_ManipulatorME4901InstanceStruct *chartInstance, const mxArray *c31_st);
static void finalize_c31_ManipulatorME4901(SFc31_ManipulatorME4901InstanceStruct
  *chartInstance);
static void sf_c31_ManipulatorME4901(SFc31_ManipulatorME4901InstanceStruct
  *chartInstance);
static void initSimStructsc31_ManipulatorME4901
  (SFc31_ManipulatorME4901InstanceStruct *chartInstance);
static void registerMessagesc31_ManipulatorME4901
  (SFc31_ManipulatorME4901InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c31_machineNumber, uint32_T
  c31_chartNumber);
static const mxArray *c31_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData);
static uint8_T c31_emlrt_marshallIn(SFc31_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c31_LoO, const char_T *c31_identifier);
static uint8_T c31_b_emlrt_marshallIn(SFc31_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId);
static void c31_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData);
static const mxArray *c31_b_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData);
static real_T c31_c_emlrt_marshallIn(SFc31_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId);
static void c31_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData);
static const mxArray *c31_c_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData);
static void c31_d_emlrt_marshallIn(SFc31_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId,
  uint8_T c31_y[2]);
static void c31_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData);
static void c31_typecast(SFc31_ManipulatorME4901InstanceStruct *chartInstance,
  int16_T c31_x, uint8_T c31_y[2]);
static const mxArray *c31_d_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData);
static int32_T c31_e_emlrt_marshallIn(SFc31_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId);
static void c31_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData);
static void init_dsm_address_info(SFc31_ManipulatorME4901InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c31_ManipulatorME4901
  (SFc31_ManipulatorME4901InstanceStruct *chartInstance)
{
  chartInstance->c31_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c31_is_active_c31_ManipulatorME4901 = 0U;
}

static void initialize_params_c31_ManipulatorME4901
  (SFc31_ManipulatorME4901InstanceStruct *chartInstance)
{
}

static void enable_c31_ManipulatorME4901(SFc31_ManipulatorME4901InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c31_ManipulatorME4901(SFc31_ManipulatorME4901InstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c31_update_debugger_state_c31_ManipulatorME4901
  (SFc31_ManipulatorME4901InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c31_ManipulatorME4901
  (SFc31_ManipulatorME4901InstanceStruct *chartInstance)
{
  const mxArray *c31_st;
  const mxArray *c31_y = NULL;
  uint8_T c31_hoistedGlobal;
  uint8_T c31_u;
  const mxArray *c31_b_y = NULL;
  uint8_T c31_b_hoistedGlobal;
  uint8_T c31_b_u;
  const mxArray *c31_c_y = NULL;
  uint8_T c31_c_hoistedGlobal;
  uint8_T c31_c_u;
  const mxArray *c31_d_y = NULL;
  uint8_T c31_d_hoistedGlobal;
  uint8_T c31_d_u;
  const mxArray *c31_e_y = NULL;
  uint8_T c31_e_hoistedGlobal;
  uint8_T c31_e_u;
  const mxArray *c31_f_y = NULL;
  uint8_T c31_f_hoistedGlobal;
  uint8_T c31_f_u;
  const mxArray *c31_g_y = NULL;
  uint8_T c31_g_hoistedGlobal;
  uint8_T c31_g_u;
  const mxArray *c31_h_y = NULL;
  uint8_T c31_h_hoistedGlobal;
  uint8_T c31_h_u;
  const mxArray *c31_i_y = NULL;
  uint8_T c31_i_hoistedGlobal;
  uint8_T c31_i_u;
  const mxArray *c31_j_y = NULL;
  uint8_T c31_j_hoistedGlobal;
  uint8_T c31_j_u;
  const mxArray *c31_k_y = NULL;
  uint8_T c31_k_hoistedGlobal;
  uint8_T c31_k_u;
  const mxArray *c31_l_y = NULL;
  uint8_T c31_l_hoistedGlobal;
  uint8_T c31_l_u;
  const mxArray *c31_m_y = NULL;
  uint8_T c31_m_hoistedGlobal;
  uint8_T c31_m_u;
  const mxArray *c31_n_y = NULL;
  uint8_T *c31_HiBase;
  uint8_T *c31_HiEnd;
  uint8_T *c31_HiM1;
  uint8_T *c31_HiM2;
  uint8_T *c31_HiM3;
  uint8_T *c31_HiO;
  uint8_T *c31_LoBase;
  uint8_T *c31_LoEnd;
  uint8_T *c31_LoM1;
  uint8_T *c31_LoM2;
  uint8_T *c31_LoM3;
  uint8_T *c31_LoO;
  c31_LoO = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c31_HiO = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c31_LoEnd = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c31_HiEnd = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c31_LoM3 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c31_HiM3 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c31_LoM2 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c31_HiM2 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c31_LoM1 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c31_HiM1 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c31_LoBase = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c31_HiBase = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c31_st = NULL;
  c31_st = NULL;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_createcellarray(13), FALSE);
  c31_hoistedGlobal = *c31_HiBase;
  c31_u = c31_hoistedGlobal;
  c31_b_y = NULL;
  sf_mex_assign(&c31_b_y, sf_mex_create("y", &c31_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c31_y, 0, c31_b_y);
  c31_b_hoistedGlobal = *c31_HiEnd;
  c31_b_u = c31_b_hoistedGlobal;
  c31_c_y = NULL;
  sf_mex_assign(&c31_c_y, sf_mex_create("y", &c31_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c31_y, 1, c31_c_y);
  c31_c_hoistedGlobal = *c31_HiM1;
  c31_c_u = c31_c_hoistedGlobal;
  c31_d_y = NULL;
  sf_mex_assign(&c31_d_y, sf_mex_create("y", &c31_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c31_y, 2, c31_d_y);
  c31_d_hoistedGlobal = *c31_HiM2;
  c31_d_u = c31_d_hoistedGlobal;
  c31_e_y = NULL;
  sf_mex_assign(&c31_e_y, sf_mex_create("y", &c31_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c31_y, 3, c31_e_y);
  c31_e_hoistedGlobal = *c31_HiM3;
  c31_e_u = c31_e_hoistedGlobal;
  c31_f_y = NULL;
  sf_mex_assign(&c31_f_y, sf_mex_create("y", &c31_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c31_y, 4, c31_f_y);
  c31_f_hoistedGlobal = *c31_HiO;
  c31_f_u = c31_f_hoistedGlobal;
  c31_g_y = NULL;
  sf_mex_assign(&c31_g_y, sf_mex_create("y", &c31_f_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c31_y, 5, c31_g_y);
  c31_g_hoistedGlobal = *c31_LoBase;
  c31_g_u = c31_g_hoistedGlobal;
  c31_h_y = NULL;
  sf_mex_assign(&c31_h_y, sf_mex_create("y", &c31_g_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c31_y, 6, c31_h_y);
  c31_h_hoistedGlobal = *c31_LoEnd;
  c31_h_u = c31_h_hoistedGlobal;
  c31_i_y = NULL;
  sf_mex_assign(&c31_i_y, sf_mex_create("y", &c31_h_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c31_y, 7, c31_i_y);
  c31_i_hoistedGlobal = *c31_LoM1;
  c31_i_u = c31_i_hoistedGlobal;
  c31_j_y = NULL;
  sf_mex_assign(&c31_j_y, sf_mex_create("y", &c31_i_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c31_y, 8, c31_j_y);
  c31_j_hoistedGlobal = *c31_LoM2;
  c31_j_u = c31_j_hoistedGlobal;
  c31_k_y = NULL;
  sf_mex_assign(&c31_k_y, sf_mex_create("y", &c31_j_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c31_y, 9, c31_k_y);
  c31_k_hoistedGlobal = *c31_LoM3;
  c31_k_u = c31_k_hoistedGlobal;
  c31_l_y = NULL;
  sf_mex_assign(&c31_l_y, sf_mex_create("y", &c31_k_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c31_y, 10, c31_l_y);
  c31_l_hoistedGlobal = *c31_LoO;
  c31_l_u = c31_l_hoistedGlobal;
  c31_m_y = NULL;
  sf_mex_assign(&c31_m_y, sf_mex_create("y", &c31_l_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c31_y, 11, c31_m_y);
  c31_m_hoistedGlobal = chartInstance->c31_is_active_c31_ManipulatorME4901;
  c31_m_u = c31_m_hoistedGlobal;
  c31_n_y = NULL;
  sf_mex_assign(&c31_n_y, sf_mex_create("y", &c31_m_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c31_y, 12, c31_n_y);
  sf_mex_assign(&c31_st, c31_y, FALSE);
  return c31_st;
}

static void set_sim_state_c31_ManipulatorME4901
  (SFc31_ManipulatorME4901InstanceStruct *chartInstance, const mxArray *c31_st)
{
  const mxArray *c31_u;
  uint8_T *c31_HiBase;
  uint8_T *c31_HiEnd;
  uint8_T *c31_HiM1;
  uint8_T *c31_HiM2;
  uint8_T *c31_HiM3;
  uint8_T *c31_HiO;
  uint8_T *c31_LoBase;
  uint8_T *c31_LoEnd;
  uint8_T *c31_LoM1;
  uint8_T *c31_LoM2;
  uint8_T *c31_LoM3;
  uint8_T *c31_LoO;
  c31_LoO = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c31_HiO = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c31_LoEnd = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c31_HiEnd = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c31_LoM3 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c31_HiM3 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c31_LoM2 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c31_HiM2 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c31_LoM1 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c31_HiM1 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c31_LoBase = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c31_HiBase = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c31_doneDoubleBufferReInit = TRUE;
  c31_u = sf_mex_dup(c31_st);
  *c31_HiBase = c31_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c31_u, 0)), "HiBase");
  *c31_HiEnd = c31_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c31_u, 1)), "HiEnd");
  *c31_HiM1 = c31_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c31_u, 2)), "HiM1");
  *c31_HiM2 = c31_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c31_u, 3)), "HiM2");
  *c31_HiM3 = c31_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c31_u, 4)), "HiM3");
  *c31_HiO = c31_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c31_u,
    5)), "HiO");
  *c31_LoBase = c31_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c31_u, 6)), "LoBase");
  *c31_LoEnd = c31_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c31_u, 7)), "LoEnd");
  *c31_LoM1 = c31_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c31_u, 8)), "LoM1");
  *c31_LoM2 = c31_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c31_u, 9)), "LoM2");
  *c31_LoM3 = c31_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c31_u, 10)), "LoM3");
  *c31_LoO = c31_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c31_u,
    11)), "LoO");
  chartInstance->c31_is_active_c31_ManipulatorME4901 = c31_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c31_u, 12)),
     "is_active_c31_ManipulatorME4901");
  sf_mex_destroy(&c31_u);
  c31_update_debugger_state_c31_ManipulatorME4901(chartInstance);
  sf_mex_destroy(&c31_st);
}

static void finalize_c31_ManipulatorME4901(SFc31_ManipulatorME4901InstanceStruct
  *chartInstance)
{
}

static void sf_c31_ManipulatorME4901(SFc31_ManipulatorME4901InstanceStruct
  *chartInstance)
{
  real_T c31_hoistedGlobal;
  real_T c31_b_hoistedGlobal;
  real_T c31_c_hoistedGlobal;
  real_T c31_d_hoistedGlobal;
  real_T c31_e_hoistedGlobal;
  uint8_T c31_f_hoistedGlobal;
  real_T c31_Base;
  real_T c31_M1;
  real_T c31_M2;
  real_T c31_M3;
  real_T c31_End;
  uint8_T c31_other;
  uint32_T c31_debug_family_var_map[26];
  uint8_T c31_BaseV[2];
  uint8_T c31_M1V[2];
  uint8_T c31_M2V[2];
  uint8_T c31_M3V[2];
  uint8_T c31_EndV[2];
  uint8_T c31_OtherV[2];
  real_T c31_nargin = 6.0;
  real_T c31_nargout = 12.0;
  uint8_T c31_HiBase;
  uint8_T c31_LoBase;
  uint8_T c31_HiM1;
  uint8_T c31_LoM1;
  uint8_T c31_HiM2;
  uint8_T c31_LoM2;
  uint8_T c31_HiM3;
  uint8_T c31_LoM3;
  uint8_T c31_HiEnd;
  uint8_T c31_LoEnd;
  uint8_T c31_HiO;
  uint8_T c31_LoO;
  real_T c31_d0;
  int16_T c31_i0;
  uint8_T c31_uv0[2];
  int32_T c31_i1;
  real_T c31_d1;
  int16_T c31_i2;
  uint8_T c31_uv1[2];
  int32_T c31_i3;
  real_T c31_d2;
  int16_T c31_i4;
  uint8_T c31_uv2[2];
  int32_T c31_i5;
  real_T c31_d3;
  int16_T c31_i6;
  uint8_T c31_uv3[2];
  int32_T c31_i7;
  real_T c31_d4;
  int16_T c31_i8;
  uint8_T c31_uv4[2];
  int32_T c31_i9;
  uint8_T c31_uv5[2];
  int32_T c31_i10;
  real_T *c31_b_Base;
  uint8_T *c31_b_HiBase;
  real_T *c31_b_M1;
  uint8_T *c31_b_LoBase;
  uint8_T *c31_b_HiM1;
  uint8_T *c31_b_LoM1;
  real_T *c31_b_M2;
  real_T *c31_b_M3;
  real_T *c31_b_End;
  uint8_T *c31_b_HiM2;
  uint8_T *c31_b_LoM2;
  uint8_T *c31_b_HiM3;
  uint8_T *c31_b_LoM3;
  uint8_T *c31_b_HiEnd;
  uint8_T *c31_b_LoEnd;
  uint8_T *c31_b_other;
  uint8_T *c31_b_HiO;
  uint8_T *c31_b_LoO;
  c31_b_LoO = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c31_b_HiO = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c31_b_other = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c31_b_LoEnd = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c31_b_HiEnd = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c31_b_LoM3 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c31_b_HiM3 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c31_b_LoM2 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c31_b_HiM2 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c31_b_End = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c31_b_M3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c31_b_M2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c31_b_LoM1 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c31_b_HiM1 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c31_b_LoBase = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c31_b_M1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c31_b_HiBase = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c31_b_Base = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 30U, chartInstance->c31_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c31_b_Base, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c31_b_HiBase, 1U);
  _SFD_DATA_RANGE_CHECK(*c31_b_M1, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*c31_b_LoBase, 3U);
  _SFD_DATA_RANGE_CHECK((real_T)*c31_b_HiM1, 4U);
  _SFD_DATA_RANGE_CHECK((real_T)*c31_b_LoM1, 5U);
  _SFD_DATA_RANGE_CHECK(*c31_b_M2, 6U);
  _SFD_DATA_RANGE_CHECK(*c31_b_M3, 7U);
  _SFD_DATA_RANGE_CHECK(*c31_b_End, 8U);
  _SFD_DATA_RANGE_CHECK((real_T)*c31_b_HiM2, 9U);
  _SFD_DATA_RANGE_CHECK((real_T)*c31_b_LoM2, 10U);
  _SFD_DATA_RANGE_CHECK((real_T)*c31_b_HiM3, 11U);
  _SFD_DATA_RANGE_CHECK((real_T)*c31_b_LoM3, 12U);
  _SFD_DATA_RANGE_CHECK((real_T)*c31_b_HiEnd, 13U);
  _SFD_DATA_RANGE_CHECK((real_T)*c31_b_LoEnd, 14U);
  _SFD_DATA_RANGE_CHECK((real_T)*c31_b_other, 15U);
  _SFD_DATA_RANGE_CHECK((real_T)*c31_b_HiO, 16U);
  _SFD_DATA_RANGE_CHECK((real_T)*c31_b_LoO, 17U);
  chartInstance->c31_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 30U, chartInstance->c31_sfEvent);
  c31_hoistedGlobal = *c31_b_Base;
  c31_b_hoistedGlobal = *c31_b_M1;
  c31_c_hoistedGlobal = *c31_b_M2;
  c31_d_hoistedGlobal = *c31_b_M3;
  c31_e_hoistedGlobal = *c31_b_End;
  c31_f_hoistedGlobal = *c31_b_other;
  c31_Base = c31_hoistedGlobal;
  c31_M1 = c31_b_hoistedGlobal;
  c31_M2 = c31_c_hoistedGlobal;
  c31_M3 = c31_d_hoistedGlobal;
  c31_End = c31_e_hoistedGlobal;
  c31_other = c31_f_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 26U, 26U, c31_debug_family_names,
    c31_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c31_BaseV, 0U, c31_c_sf_marshallOut,
    c31_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c31_M1V, 1U, c31_c_sf_marshallOut,
    c31_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c31_M2V, 2U, c31_c_sf_marshallOut,
    c31_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c31_M3V, 3U, c31_c_sf_marshallOut,
    c31_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c31_EndV, 4U, c31_c_sf_marshallOut,
    c31_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c31_OtherV, 5U, c31_c_sf_marshallOut,
    c31_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_nargin, 6U, c31_b_sf_marshallOut,
    c31_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_nargout, 7U, c31_b_sf_marshallOut,
    c31_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c31_Base, 8U, c31_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c31_M1, 9U, c31_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c31_M2, 10U, c31_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c31_M3, 11U, c31_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c31_End, 12U, c31_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c31_other, 13U, c31_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_HiBase, 14U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_LoBase, 15U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_HiM1, 16U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_LoM1, 17U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_HiM2, 18U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_LoM2, 19U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_HiM3, 20U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_LoM3, 21U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_HiEnd, 22U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_LoEnd, 23U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_HiO, 24U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c31_LoO, 25U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 5);
  c31_d0 = muDoubleScalarRound(c31_Base);
  if (c31_d0 < 32768.0) {
    if (CV_SATURATION_EVAL(4, 0, 0, 1, c31_d0 >= -32768.0)) {
      c31_i0 = (int16_T)c31_d0;
    } else {
      c31_i0 = MIN_int16_T;
    }
  } else if (CV_SATURATION_EVAL(4, 0, 0, 0, c31_d0 >= 32768.0)) {
    c31_i0 = MAX_int16_T;
  } else {
    c31_i0 = 0;
  }

  c31_typecast(chartInstance, c31_i0, c31_uv0);
  for (c31_i1 = 0; c31_i1 < 2; c31_i1++) {
    c31_BaseV[c31_i1] = c31_uv0[c31_i1];
  }

  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 6);
  c31_d1 = muDoubleScalarRound(c31_M1);
  if (c31_d1 < 32768.0) {
    if (CV_SATURATION_EVAL(4, 0, 1, 1, c31_d1 >= -32768.0)) {
      c31_i2 = (int16_T)c31_d1;
    } else {
      c31_i2 = MIN_int16_T;
    }
  } else if (CV_SATURATION_EVAL(4, 0, 1, 0, c31_d1 >= 32768.0)) {
    c31_i2 = MAX_int16_T;
  } else {
    c31_i2 = 0;
  }

  c31_typecast(chartInstance, c31_i2, c31_uv1);
  for (c31_i3 = 0; c31_i3 < 2; c31_i3++) {
    c31_M1V[c31_i3] = c31_uv1[c31_i3];
  }

  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 7);
  c31_d2 = muDoubleScalarRound(c31_M2);
  if (c31_d2 < 32768.0) {
    if (CV_SATURATION_EVAL(4, 0, 2, 1, c31_d2 >= -32768.0)) {
      c31_i4 = (int16_T)c31_d2;
    } else {
      c31_i4 = MIN_int16_T;
    }
  } else if (CV_SATURATION_EVAL(4, 0, 2, 0, c31_d2 >= 32768.0)) {
    c31_i4 = MAX_int16_T;
  } else {
    c31_i4 = 0;
  }

  c31_typecast(chartInstance, c31_i4, c31_uv2);
  for (c31_i5 = 0; c31_i5 < 2; c31_i5++) {
    c31_M2V[c31_i5] = c31_uv2[c31_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 8);
  c31_d3 = muDoubleScalarRound(c31_M3);
  if (c31_d3 < 32768.0) {
    if (CV_SATURATION_EVAL(4, 0, 3, 1, c31_d3 >= -32768.0)) {
      c31_i6 = (int16_T)c31_d3;
    } else {
      c31_i6 = MIN_int16_T;
    }
  } else if (CV_SATURATION_EVAL(4, 0, 3, 0, c31_d3 >= 32768.0)) {
    c31_i6 = MAX_int16_T;
  } else {
    c31_i6 = 0;
  }

  c31_typecast(chartInstance, c31_i6, c31_uv3);
  for (c31_i7 = 0; c31_i7 < 2; c31_i7++) {
    c31_M3V[c31_i7] = c31_uv3[c31_i7];
  }

  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 9);
  c31_d4 = muDoubleScalarRound(c31_End);
  if (c31_d4 < 32768.0) {
    if (CV_SATURATION_EVAL(4, 0, 4, 1, c31_d4 >= -32768.0)) {
      c31_i8 = (int16_T)c31_d4;
    } else {
      c31_i8 = MIN_int16_T;
    }
  } else if (CV_SATURATION_EVAL(4, 0, 4, 0, c31_d4 >= 32768.0)) {
    c31_i8 = MAX_int16_T;
  } else {
    c31_i8 = 0;
  }

  c31_typecast(chartInstance, c31_i8, c31_uv4);
  for (c31_i9 = 0; c31_i9 < 2; c31_i9++) {
    c31_EndV[c31_i9] = c31_uv4[c31_i9];
  }

  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 10);
  c31_typecast(chartInstance, (int16_T)c31_other, c31_uv5);
  for (c31_i10 = 0; c31_i10 < 2; c31_i10++) {
    c31_OtherV[c31_i10] = c31_uv5[c31_i10];
  }

  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 13);
  c31_HiBase = c31_BaseV[1];
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 14);
  c31_LoBase = c31_BaseV[0];
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 15);
  c31_HiM1 = c31_M1V[1];
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 16);
  c31_LoM1 = c31_M1V[0];
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 17);
  c31_HiM2 = c31_M2V[1];
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 18);
  c31_LoM2 = c31_M2V[0];
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 19);
  c31_HiM3 = c31_M3V[1];
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 20);
  c31_LoM3 = c31_M3V[0];
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 21);
  c31_HiEnd = c31_EndV[1];
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 22);
  c31_LoEnd = c31_EndV[0];
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 23);
  c31_HiO = c31_OtherV[1];
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, 24);
  c31_LoO = c31_OtherV[0];
  _SFD_EML_CALL(0U, chartInstance->c31_sfEvent, -24);
  _SFD_SYMBOL_SCOPE_POP();
  *c31_b_HiBase = c31_HiBase;
  *c31_b_LoBase = c31_LoBase;
  *c31_b_HiM1 = c31_HiM1;
  *c31_b_LoM1 = c31_LoM1;
  *c31_b_HiM2 = c31_HiM2;
  *c31_b_LoM2 = c31_LoM2;
  *c31_b_HiM3 = c31_HiM3;
  *c31_b_LoM3 = c31_LoM3;
  *c31_b_HiEnd = c31_HiEnd;
  *c31_b_LoEnd = c31_LoEnd;
  *c31_b_HiO = c31_HiO;
  *c31_b_LoO = c31_LoO;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 30U, chartInstance->c31_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ManipulatorME4901MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc31_ManipulatorME4901
  (SFc31_ManipulatorME4901InstanceStruct *chartInstance)
{
}

static void registerMessagesc31_ManipulatorME4901
  (SFc31_ManipulatorME4901InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c31_machineNumber, uint32_T
  c31_chartNumber)
{
}

static const mxArray *c31_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData)
{
  const mxArray *c31_mxArrayOutData = NULL;
  uint8_T c31_u;
  const mxArray *c31_y = NULL;
  SFc31_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc31_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c31_mxArrayOutData = NULL;
  c31_u = *(uint8_T *)c31_inData;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", &c31_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c31_mxArrayOutData, c31_y, FALSE);
  return c31_mxArrayOutData;
}

static uint8_T c31_emlrt_marshallIn(SFc31_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c31_LoO, const char_T *c31_identifier)
{
  uint8_T c31_y;
  emlrtMsgIdentifier c31_thisId;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_y = c31_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_LoO), &c31_thisId);
  sf_mex_destroy(&c31_LoO);
  return c31_y;
}

static uint8_T c31_b_emlrt_marshallIn(SFc31_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId)
{
  uint8_T c31_y;
  uint8_T c31_u0;
  sf_mex_import(c31_parentId, sf_mex_dup(c31_u), &c31_u0, 1, 3, 0U, 0, 0U, 0);
  c31_y = c31_u0;
  sf_mex_destroy(&c31_u);
  return c31_y;
}

static void c31_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData)
{
  const mxArray *c31_LoO;
  const char_T *c31_identifier;
  emlrtMsgIdentifier c31_thisId;
  uint8_T c31_y;
  SFc31_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc31_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c31_LoO = sf_mex_dup(c31_mxArrayInData);
  c31_identifier = c31_varName;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_y = c31_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_LoO), &c31_thisId);
  sf_mex_destroy(&c31_LoO);
  *(uint8_T *)c31_outData = c31_y;
  sf_mex_destroy(&c31_mxArrayInData);
}

static const mxArray *c31_b_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData)
{
  const mxArray *c31_mxArrayOutData = NULL;
  real_T c31_u;
  const mxArray *c31_y = NULL;
  SFc31_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc31_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c31_mxArrayOutData = NULL;
  c31_u = *(real_T *)c31_inData;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", &c31_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c31_mxArrayOutData, c31_y, FALSE);
  return c31_mxArrayOutData;
}

static real_T c31_c_emlrt_marshallIn(SFc31_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId)
{
  real_T c31_y;
  real_T c31_d5;
  sf_mex_import(c31_parentId, sf_mex_dup(c31_u), &c31_d5, 1, 0, 0U, 0, 0U, 0);
  c31_y = c31_d5;
  sf_mex_destroy(&c31_u);
  return c31_y;
}

static void c31_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData)
{
  const mxArray *c31_nargout;
  const char_T *c31_identifier;
  emlrtMsgIdentifier c31_thisId;
  real_T c31_y;
  SFc31_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc31_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c31_nargout = sf_mex_dup(c31_mxArrayInData);
  c31_identifier = c31_varName;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_y = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_nargout),
    &c31_thisId);
  sf_mex_destroy(&c31_nargout);
  *(real_T *)c31_outData = c31_y;
  sf_mex_destroy(&c31_mxArrayInData);
}

static const mxArray *c31_c_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData)
{
  const mxArray *c31_mxArrayOutData = NULL;
  int32_T c31_i11;
  uint8_T c31_b_inData[2];
  int32_T c31_i12;
  uint8_T c31_u[2];
  const mxArray *c31_y = NULL;
  SFc31_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc31_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c31_mxArrayOutData = NULL;
  for (c31_i11 = 0; c31_i11 < 2; c31_i11++) {
    c31_b_inData[c31_i11] = (*(uint8_T (*)[2])c31_inData)[c31_i11];
  }

  for (c31_i12 = 0; c31_i12 < 2; c31_i12++) {
    c31_u[c31_i12] = c31_b_inData[c31_i12];
  }

  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", c31_u, 3, 0U, 1U, 0U, 2, 1, 2), FALSE);
  sf_mex_assign(&c31_mxArrayOutData, c31_y, FALSE);
  return c31_mxArrayOutData;
}

static void c31_d_emlrt_marshallIn(SFc31_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId,
  uint8_T c31_y[2])
{
  uint8_T c31_uv6[2];
  int32_T c31_i13;
  sf_mex_import(c31_parentId, sf_mex_dup(c31_u), c31_uv6, 1, 3, 0U, 1, 0U, 2, 1,
                2);
  for (c31_i13 = 0; c31_i13 < 2; c31_i13++) {
    c31_y[c31_i13] = c31_uv6[c31_i13];
  }

  sf_mex_destroy(&c31_u);
}

static void c31_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData)
{
  const mxArray *c31_OtherV;
  const char_T *c31_identifier;
  emlrtMsgIdentifier c31_thisId;
  uint8_T c31_y[2];
  int32_T c31_i14;
  SFc31_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc31_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c31_OtherV = sf_mex_dup(c31_mxArrayInData);
  c31_identifier = c31_varName;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_OtherV), &c31_thisId,
    c31_y);
  sf_mex_destroy(&c31_OtherV);
  for (c31_i14 = 0; c31_i14 < 2; c31_i14++) {
    (*(uint8_T (*)[2])c31_outData)[c31_i14] = c31_y[c31_i14];
  }

  sf_mex_destroy(&c31_mxArrayInData);
}

const mxArray *sf_c31_ManipulatorME4901_get_eml_resolved_functions_info(void)
{
  const mxArray *c31_nameCaptureInfo;
  c31_ResolvedFunctionInfo c31_info[8];
  c31_ResolvedFunctionInfo (*c31_b_info)[8];
  const mxArray *c31_m0 = NULL;
  int32_T c31_i15;
  c31_ResolvedFunctionInfo *c31_r0;
  c31_nameCaptureInfo = NULL;
  c31_nameCaptureInfo = NULL;
  c31_b_info = (c31_ResolvedFunctionInfo (*)[8])c31_info;
  (*c31_b_info)[0].context = "";
  (*c31_b_info)[0].name = "typecast";
  (*c31_b_info)[0].dominantType = "int16";
  (*c31_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m";
  (*c31_b_info)[0].fileTimeLo = 1323202976U;
  (*c31_b_info)[0].fileTimeHi = 0U;
  (*c31_b_info)[0].mFileTimeLo = 0U;
  (*c31_b_info)[0].mFileTimeHi = 0U;
  (*c31_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element";
  (*c31_b_info)[1].name = "eml_int_nbits";
  (*c31_b_info)[1].dominantType = "char";
  (*c31_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_nbits.m";
  (*c31_b_info)[1].fileTimeLo = 1323202978U;
  (*c31_b_info)[1].fileTimeHi = 0U;
  (*c31_b_info)[1].mFileTimeLo = 0U;
  (*c31_b_info)[1].mFileTimeHi = 0U;
  (*c31_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element";
  (*c31_b_info)[2].name = "eml_index_rdivide";
  (*c31_b_info)[2].dominantType = "uint8";
  (*c31_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  (*c31_b_info)[2].fileTimeLo = 1286851180U;
  (*c31_b_info)[2].fileTimeHi = 0U;
  (*c31_b_info)[2].mFileTimeLo = 0U;
  (*c31_b_info)[2].mFileTimeHi = 0U;
  (*c31_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  (*c31_b_info)[3].name = "eml_index_class";
  (*c31_b_info)[3].dominantType = "";
  (*c31_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c31_b_info)[3].fileTimeLo = 1323202978U;
  (*c31_b_info)[3].fileTimeHi = 0U;
  (*c31_b_info)[3].mFileTimeLo = 0U;
  (*c31_b_info)[3].mFileTimeHi = 0U;
  (*c31_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m";
  (*c31_b_info)[4].name = "eml_index_times";
  (*c31_b_info)[4].dominantType = "double";
  (*c31_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  (*c31_b_info)[4].fileTimeLo = 1286851180U;
  (*c31_b_info)[4].fileTimeHi = 0U;
  (*c31_b_info)[4].mFileTimeLo = 0U;
  (*c31_b_info)[4].mFileTimeHi = 0U;
  (*c31_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  (*c31_b_info)[5].name = "eml_index_class";
  (*c31_b_info)[5].dominantType = "";
  (*c31_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c31_b_info)[5].fileTimeLo = 1323202978U;
  (*c31_b_info)[5].fileTimeHi = 0U;
  (*c31_b_info)[5].mFileTimeLo = 0U;
  (*c31_b_info)[5].mFileTimeHi = 0U;
  (*c31_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m";
  (*c31_b_info)[6].name = "eml_index_rdivide";
  (*c31_b_info)[6].dominantType = "coder.internal.indexInt";
  (*c31_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  (*c31_b_info)[6].fileTimeLo = 1286851180U;
  (*c31_b_info)[6].fileTimeHi = 0U;
  (*c31_b_info)[6].mFileTimeLo = 0U;
  (*c31_b_info)[6].mFileTimeHi = 0U;
  (*c31_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m";
  (*c31_b_info)[7].name = "eml_index_times";
  (*c31_b_info)[7].dominantType = "coder.internal.indexInt";
  (*c31_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  (*c31_b_info)[7].fileTimeLo = 1286851180U;
  (*c31_b_info)[7].fileTimeHi = 0U;
  (*c31_b_info)[7].mFileTimeLo = 0U;
  (*c31_b_info)[7].mFileTimeHi = 0U;
  sf_mex_assign(&c31_m0, sf_mex_createstruct("nameCaptureInfo", 1, 8), FALSE);
  for (c31_i15 = 0; c31_i15 < 8; c31_i15++) {
    c31_r0 = &c31_info[c31_i15];
    sf_mex_addfield(c31_m0, sf_mex_create("nameCaptureInfo", c31_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c31_r0->context)), "context", "nameCaptureInfo",
                    c31_i15);
    sf_mex_addfield(c31_m0, sf_mex_create("nameCaptureInfo", c31_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c31_r0->name)), "name", "nameCaptureInfo",
                    c31_i15);
    sf_mex_addfield(c31_m0, sf_mex_create("nameCaptureInfo",
      c31_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c31_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c31_i15);
    sf_mex_addfield(c31_m0, sf_mex_create("nameCaptureInfo", c31_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c31_r0->resolved)), "resolved",
                    "nameCaptureInfo", c31_i15);
    sf_mex_addfield(c31_m0, sf_mex_create("nameCaptureInfo", &c31_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c31_i15);
    sf_mex_addfield(c31_m0, sf_mex_create("nameCaptureInfo", &c31_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c31_i15);
    sf_mex_addfield(c31_m0, sf_mex_create("nameCaptureInfo",
      &c31_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c31_i15);
    sf_mex_addfield(c31_m0, sf_mex_create("nameCaptureInfo",
      &c31_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c31_i15);
  }

  sf_mex_assign(&c31_nameCaptureInfo, c31_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c31_nameCaptureInfo);
  return c31_nameCaptureInfo;
}

static void c31_typecast(SFc31_ManipulatorME4901InstanceStruct *chartInstance,
  int16_T c31_x, uint8_T c31_y[2])
{
  memcpy(&c31_y[0], &c31_x, 2U);
}

static const mxArray *c31_d_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData)
{
  const mxArray *c31_mxArrayOutData = NULL;
  int32_T c31_u;
  const mxArray *c31_y = NULL;
  SFc31_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc31_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c31_mxArrayOutData = NULL;
  c31_u = *(int32_T *)c31_inData;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", &c31_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c31_mxArrayOutData, c31_y, FALSE);
  return c31_mxArrayOutData;
}

static int32_T c31_e_emlrt_marshallIn(SFc31_ManipulatorME4901InstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId)
{
  int32_T c31_y;
  int32_T c31_i16;
  sf_mex_import(c31_parentId, sf_mex_dup(c31_u), &c31_i16, 1, 6, 0U, 0, 0U, 0);
  c31_y = c31_i16;
  sf_mex_destroy(&c31_u);
  return c31_y;
}

static void c31_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData)
{
  const mxArray *c31_b_sfEvent;
  const char_T *c31_identifier;
  emlrtMsgIdentifier c31_thisId;
  int32_T c31_y;
  SFc31_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc31_ManipulatorME4901InstanceStruct *)chartInstanceVoid;
  c31_b_sfEvent = sf_mex_dup(c31_mxArrayInData);
  c31_identifier = c31_varName;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_y = c31_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_b_sfEvent),
    &c31_thisId);
  sf_mex_destroy(&c31_b_sfEvent);
  *(int32_T *)c31_outData = c31_y;
  sf_mex_destroy(&c31_mxArrayInData);
}

static void init_dsm_address_info(SFc31_ManipulatorME4901InstanceStruct
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

void sf_c31_ManipulatorME4901_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1469284726U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(195967109U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2225140548U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1917864129U);
}

mxArray *sf_c31_ManipulatorME4901_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Vfs5UyJS8SijFS4EK8cNiG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,12,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c31_ManipulatorME4901_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c31_ManipulatorME4901(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[5],T\"HiBase\",},{M[1],M[17],T\"HiEnd\",},{M[1],M[8],T\"HiM1\",},{M[1],M[13],T\"HiM2\",},{M[1],M[15],T\"HiM3\",},{M[1],M[20],T\"HiO\",},{M[1],M[7],T\"LoBase\",},{M[1],M[18],T\"LoEnd\",},{M[1],M[9],T\"LoM1\",},{M[1],M[14],T\"LoM2\",}}",
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[16],T\"LoM3\",},{M[1],M[21],T\"LoO\",},{M[8],M[0],T\"is_active_c31_ManipulatorME4901\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 13, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c31_ManipulatorME4901_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc31_ManipulatorME4901InstanceStruct *chartInstance;
    chartInstance = (SFc31_ManipulatorME4901InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ManipulatorME4901MachineNumber_,
           31,
           1,
           1,
           18,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"Base");
          _SFD_SET_DATA_PROPS(1,2,0,1,"HiBase");
          _SFD_SET_DATA_PROPS(2,1,1,0,"M1");
          _SFD_SET_DATA_PROPS(3,2,0,1,"LoBase");
          _SFD_SET_DATA_PROPS(4,2,0,1,"HiM1");
          _SFD_SET_DATA_PROPS(5,2,0,1,"LoM1");
          _SFD_SET_DATA_PROPS(6,1,1,0,"M2");
          _SFD_SET_DATA_PROPS(7,1,1,0,"M3");
          _SFD_SET_DATA_PROPS(8,1,1,0,"End");
          _SFD_SET_DATA_PROPS(9,2,0,1,"HiM2");
          _SFD_SET_DATA_PROPS(10,2,0,1,"LoM2");
          _SFD_SET_DATA_PROPS(11,2,0,1,"HiM3");
          _SFD_SET_DATA_PROPS(12,2,0,1,"LoM3");
          _SFD_SET_DATA_PROPS(13,2,0,1,"HiEnd");
          _SFD_SET_DATA_PROPS(14,2,0,1,"LoEnd");
          _SFD_SET_DATA_PROPS(15,1,1,0,"other");
          _SFD_SET_DATA_PROPS(16,2,0,1,"HiO");
          _SFD_SET_DATA_PROPS(17,2,0,1,"LoO");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,5,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,501);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,133,-1,144);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,168,-1,177);
        _SFD_CV_INIT_EML_SATURATION(0,1,2,201,-1,210);
        _SFD_CV_INIT_EML_SATURATION(0,1,3,234,-1,243);
        _SFD_CV_INIT_EML_SATURATION(0,1,4,268,-1,278);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)c31_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)c31_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)c31_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)c31_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)c31_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)c31_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)c31_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)c31_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)c31_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)c31_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)c31_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)c31_sf_marshallIn);

        {
          real_T *c31_Base;
          uint8_T *c31_HiBase;
          real_T *c31_M1;
          uint8_T *c31_LoBase;
          uint8_T *c31_HiM1;
          uint8_T *c31_LoM1;
          real_T *c31_M2;
          real_T *c31_M3;
          real_T *c31_End;
          uint8_T *c31_HiM2;
          uint8_T *c31_LoM2;
          uint8_T *c31_HiM3;
          uint8_T *c31_LoM3;
          uint8_T *c31_HiEnd;
          uint8_T *c31_LoEnd;
          uint8_T *c31_other;
          uint8_T *c31_HiO;
          uint8_T *c31_LoO;
          c31_LoO = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 12);
          c31_HiO = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 11);
          c31_other = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c31_LoEnd = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 10);
          c31_HiEnd = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 9);
          c31_LoM3 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 8);
          c31_HiM3 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c31_LoM2 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c31_HiM2 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c31_End = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c31_M3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c31_M2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c31_LoM1 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c31_HiM1 = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c31_LoBase = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c31_M1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c31_HiBase = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c31_Base = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c31_Base);
          _SFD_SET_DATA_VALUE_PTR(1U, c31_HiBase);
          _SFD_SET_DATA_VALUE_PTR(2U, c31_M1);
          _SFD_SET_DATA_VALUE_PTR(3U, c31_LoBase);
          _SFD_SET_DATA_VALUE_PTR(4U, c31_HiM1);
          _SFD_SET_DATA_VALUE_PTR(5U, c31_LoM1);
          _SFD_SET_DATA_VALUE_PTR(6U, c31_M2);
          _SFD_SET_DATA_VALUE_PTR(7U, c31_M3);
          _SFD_SET_DATA_VALUE_PTR(8U, c31_End);
          _SFD_SET_DATA_VALUE_PTR(9U, c31_HiM2);
          _SFD_SET_DATA_VALUE_PTR(10U, c31_LoM2);
          _SFD_SET_DATA_VALUE_PTR(11U, c31_HiM3);
          _SFD_SET_DATA_VALUE_PTR(12U, c31_LoM3);
          _SFD_SET_DATA_VALUE_PTR(13U, c31_HiEnd);
          _SFD_SET_DATA_VALUE_PTR(14U, c31_LoEnd);
          _SFD_SET_DATA_VALUE_PTR(15U, c31_other);
          _SFD_SET_DATA_VALUE_PTR(16U, c31_HiO);
          _SFD_SET_DATA_VALUE_PTR(17U, c31_LoO);
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
  return "Uc35GwAh4lCtMDZg1CtRDE";
}

static void sf_opaque_initialize_c31_ManipulatorME4901(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc31_ManipulatorME4901InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c31_ManipulatorME4901((SFc31_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
  initialize_c31_ManipulatorME4901((SFc31_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c31_ManipulatorME4901(void *chartInstanceVar)
{
  enable_c31_ManipulatorME4901((SFc31_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c31_ManipulatorME4901(void *chartInstanceVar)
{
  disable_c31_ManipulatorME4901((SFc31_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c31_ManipulatorME4901(void *chartInstanceVar)
{
  sf_c31_ManipulatorME4901((SFc31_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c31_ManipulatorME4901(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c31_ManipulatorME4901
    ((SFc31_ManipulatorME4901InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c31_ManipulatorME4901();/* state var info */
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

extern void sf_internal_set_sim_state_c31_ManipulatorME4901(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c31_ManipulatorME4901();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c31_ManipulatorME4901((SFc31_ManipulatorME4901InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c31_ManipulatorME4901(SimStruct* S)
{
  return sf_internal_get_sim_state_c31_ManipulatorME4901(S);
}

static void sf_opaque_set_sim_state_c31_ManipulatorME4901(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c31_ManipulatorME4901(S, st);
}

static void sf_opaque_terminate_c31_ManipulatorME4901(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc31_ManipulatorME4901InstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ManipulatorME4901_optimization_info();
    }

    finalize_c31_ManipulatorME4901((SFc31_ManipulatorME4901InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc31_ManipulatorME4901((SFc31_ManipulatorME4901InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c31_ManipulatorME4901(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c31_ManipulatorME4901
      ((SFc31_ManipulatorME4901InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c31_ManipulatorME4901(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ManipulatorME4901_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      31);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,31,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,31,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,31);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,31,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,31,12);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=12; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,31);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2606103702U));
  ssSetChecksum1(S,(4096155050U));
  ssSetChecksum2(S,(4006813653U));
  ssSetChecksum3(S,(1631646765U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c31_ManipulatorME4901(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c31_ManipulatorME4901(SimStruct *S)
{
  SFc31_ManipulatorME4901InstanceStruct *chartInstance;
  chartInstance = (SFc31_ManipulatorME4901InstanceStruct *)utMalloc(sizeof
    (SFc31_ManipulatorME4901InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc31_ManipulatorME4901InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c31_ManipulatorME4901;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c31_ManipulatorME4901;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c31_ManipulatorME4901;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c31_ManipulatorME4901;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c31_ManipulatorME4901;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c31_ManipulatorME4901;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c31_ManipulatorME4901;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c31_ManipulatorME4901;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c31_ManipulatorME4901;
  chartInstance->chartInfo.mdlStart = mdlStart_c31_ManipulatorME4901;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c31_ManipulatorME4901;
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

void c31_ManipulatorME4901_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c31_ManipulatorME4901(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c31_ManipulatorME4901(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c31_ManipulatorME4901(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c31_ManipulatorME4901_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
