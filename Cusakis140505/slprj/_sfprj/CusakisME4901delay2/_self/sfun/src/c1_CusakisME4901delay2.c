/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CusakisME4901delay2_sfun.h"
#include "c1_CusakisME4901delay2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CusakisME4901delay2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[20] = { "r", "Xf", "Xi", "DeltaSC",
  "alpha", "Sl", "Sr", "R", "alpha1", "nargin", "nargout", "SCtransl", "phase",
  "intRot", "SCold", "f13", "f24", "Vel", "Rot", "SCold1" };

/* Function Declarations */
static void initialize_c1_CusakisME4901delay2
  (SFc1_CusakisME4901delay2InstanceStruct *chartInstance);
static void initialize_params_c1_CusakisME4901delay2
  (SFc1_CusakisME4901delay2InstanceStruct *chartInstance);
static void enable_c1_CusakisME4901delay2(SFc1_CusakisME4901delay2InstanceStruct
  *chartInstance);
static void disable_c1_CusakisME4901delay2
  (SFc1_CusakisME4901delay2InstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_CusakisME4901delay2
  (SFc1_CusakisME4901delay2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_CusakisME4901delay2
  (SFc1_CusakisME4901delay2InstanceStruct *chartInstance);
static void set_sim_state_c1_CusakisME4901delay2
  (SFc1_CusakisME4901delay2InstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_CusakisME4901delay2
  (SFc1_CusakisME4901delay2InstanceStruct *chartInstance);
static void sf_c1_CusakisME4901delay2(SFc1_CusakisME4901delay2InstanceStruct
  *chartInstance);
static void c1_chartstep_c1_CusakisME4901delay2
  (SFc1_CusakisME4901delay2InstanceStruct *chartInstance);
static void initSimStructsc1_CusakisME4901delay2
  (SFc1_CusakisME4901delay2InstanceStruct *chartInstance);
static void registerMessagesc1_CusakisME4901delay2
  (SFc1_CusakisME4901delay2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_CusakisME4901delay2InstanceStruct
  *chartInstance, const mxArray *c1_SCold1, const char_T *c1_identifier, real_T
  c1_y[3]);
static void c1_b_emlrt_marshallIn(SFc1_CusakisME4901delay2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[3]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn(SFc1_CusakisME4901delay2InstanceStruct
  *chartInstance, const mxArray *c1_Rot, const char_T *c1_identifier);
static real_T c1_d_emlrt_marshallIn(SFc1_CusakisME4901delay2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_e_emlrt_marshallIn(SFc1_CusakisME4901delay2InstanceStruct
  *chartInstance, const mxArray *c1_Vel, const char_T *c1_identifier, real_T
  c1_y[2]);
static void c1_f_emlrt_marshallIn(SFc1_CusakisME4901delay2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[2]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[20]);
static void c1_eml_scalar_eg(SFc1_CusakisME4901delay2InstanceStruct
  *chartInstance);
static real_T c1_mpower(SFc1_CusakisME4901delay2InstanceStruct *chartInstance,
  real_T c1_a);
static void c1_eml_error(SFc1_CusakisME4901delay2InstanceStruct *chartInstance);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_g_emlrt_marshallIn(SFc1_CusakisME4901delay2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_h_emlrt_marshallIn(SFc1_CusakisME4901delay2InstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_CusakisME4901delay2, const
  char_T *c1_identifier);
static uint8_T c1_i_emlrt_marshallIn(SFc1_CusakisME4901delay2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_CusakisME4901delay2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_CusakisME4901delay2
  (SFc1_CusakisME4901delay2InstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_CusakisME4901delay2 = 0U;
}

static void initialize_params_c1_CusakisME4901delay2
  (SFc1_CusakisME4901delay2InstanceStruct *chartInstance)
{
  real_T c1_d0;
  real_T c1_d1;
  sf_set_error_prefix_string(
    "Error evaluating data 'f13' in the parent workspace.\n");
  sf_mex_import_named("f13", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c1_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_f13 = c1_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'f24' in the parent workspace.\n");
  sf_mex_import_named("f24", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c1_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c1_f24 = c1_d1;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c1_CusakisME4901delay2(SFc1_CusakisME4901delay2InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_CusakisME4901delay2
  (SFc1_CusakisME4901delay2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_CusakisME4901delay2
  (SFc1_CusakisME4901delay2InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_CusakisME4901delay2
  (SFc1_CusakisME4901delay2InstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  int32_T c1_i0;
  real_T c1_b_u[3];
  const mxArray *c1_c_y = NULL;
  int32_T c1_i1;
  real_T c1_c_u[2];
  const mxArray *c1_d_y = NULL;
  uint8_T c1_b_hoistedGlobal;
  uint8_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  real_T *c1_Rot;
  real_T (*c1_Vel)[2];
  real_T (*c1_SCold1)[3];
  c1_SCold1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_Rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_Vel = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(4), FALSE);
  c1_hoistedGlobal = *c1_Rot;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  for (c1_i0 = 0; c1_i0 < 3; c1_i0++) {
    c1_b_u[c1_i0] = (*c1_SCold1)[c1_i0];
  }

  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_c_u[c1_i1] = (*c1_Vel)[c1_i1];
  }

  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_b_hoistedGlobal = chartInstance->c1_is_active_c1_CusakisME4901delay2;
  c1_d_u = c1_b_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_CusakisME4901delay2
  (SFc1_CusakisME4901delay2InstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[3];
  int32_T c1_i2;
  real_T c1_dv1[2];
  int32_T c1_i3;
  real_T *c1_Rot;
  real_T (*c1_SCold1)[3];
  real_T (*c1_Vel)[2];
  c1_SCold1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_Rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_Vel = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_Rot = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    0)), "Rot");
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
                      "SCold1", c1_dv0);
  for (c1_i2 = 0; c1_i2 < 3; c1_i2++) {
    (*c1_SCold1)[c1_i2] = c1_dv0[c1_i2];
  }

  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
                        "Vel", c1_dv1);
  for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
    (*c1_Vel)[c1_i3] = c1_dv1[c1_i3];
  }

  chartInstance->c1_is_active_c1_CusakisME4901delay2 = c1_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 3)),
     "is_active_c1_CusakisME4901delay2");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_CusakisME4901delay2(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_CusakisME4901delay2
  (SFc1_CusakisME4901delay2InstanceStruct *chartInstance)
{
}

static void sf_c1_CusakisME4901delay2(SFc1_CusakisME4901delay2InstanceStruct
  *chartInstance)
{
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  real_T *c1_phase;
  real_T *c1_intRot;
  real_T *c1_Rot;
  real_T (*c1_SCold1)[3];
  real_T (*c1_Vel)[2];
  real_T (*c1_SCold)[3];
  real_T (*c1_SCtransl)[3];
  c1_SCold1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_Rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_Vel = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_SCold = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c1_intRot = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_phase = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_SCtransl = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i4 = 0; c1_i4 < 3; c1_i4++) {
    _SFD_DATA_RANGE_CHECK((*c1_SCtransl)[c1_i4], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_phase, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_intRot, 2U);
  for (c1_i5 = 0; c1_i5 < 3; c1_i5++) {
    _SFD_DATA_RANGE_CHECK((*c1_SCold)[c1_i5], 3U);
  }

  for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
    _SFD_DATA_RANGE_CHECK((*c1_Vel)[c1_i6], 4U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_Rot, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_f13, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_f24, 7U);
  for (c1_i7 = 0; c1_i7 < 3; c1_i7++) {
    _SFD_DATA_RANGE_CHECK((*c1_SCold1)[c1_i7], 8U);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_CusakisME4901delay2(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CusakisME4901delay2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_CusakisME4901delay2
  (SFc1_CusakisME4901delay2InstanceStruct *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  real_T c1_d_hoistedGlobal;
  int32_T c1_i8;
  real_T c1_SCtransl[3];
  real_T c1_phase;
  real_T c1_intRot;
  int32_T c1_i9;
  real_T c1_SCold[3];
  real_T c1_b_f13;
  real_T c1_b_f24;
  uint32_T c1_debug_family_var_map[20];
  real_T c1_r;
  real_T c1_Xf[2];
  real_T c1_Xi[3];
  real_T c1_DeltaSC[2];
  real_T c1_alpha;
  real_T c1_Sl;
  real_T c1_Sr;
  real_T c1_R;
  real_T c1_alpha1;
  real_T c1_nargin = 6.0;
  real_T c1_nargout = 3.0;
  real_T c1_Vel[2];
  real_T c1_Rot;
  real_T c1_SCold1[3];
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  real_T c1_y;
  real_T c1_x;
  real_T c1_b_y;
  real_T c1_b_x;
  real_T c1_a;
  real_T c1_b_a;
  real_T c1_c_a;
  real_T c1_d_a;
  real_T c1_e_a;
  real_T c1_f_a;
  real_T c1_g_a;
  real_T c1_h_a;
  real_T c1_A;
  real_T c1_B;
  real_T c1_c_x;
  real_T c1_c_y;
  real_T c1_d_x;
  real_T c1_d_y;
  real_T c1_e_y;
  real_T c1_b_A;
  real_T c1_b_B;
  real_T c1_e_x;
  real_T c1_f_y;
  real_T c1_f_x;
  real_T c1_g_y;
  real_T c1_h_y;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_c_A;
  real_T c1_c_B;
  real_T c1_i_x;
  real_T c1_i_y;
  real_T c1_j_x;
  real_T c1_j_y;
  real_T c1_k_y;
  real_T c1_d_A;
  real_T c1_d_B;
  real_T c1_k_x;
  real_T c1_l_y;
  real_T c1_l_x;
  real_T c1_m_y;
  real_T c1_n_y;
  int32_T c1_i17;
  real_T c1_i_a;
  real_T c1_j_a;
  real_T c1_k_a;
  real_T c1_l_a;
  real_T c1_m_a;
  real_T c1_n_a;
  real_T c1_o_a;
  real_T c1_p_a;
  real_T c1_e_A;
  real_T c1_e_B;
  real_T c1_m_x;
  real_T c1_o_y;
  real_T c1_n_x;
  real_T c1_p_y;
  real_T c1_q_y;
  real_T c1_f_A;
  real_T c1_f_B;
  real_T c1_o_x;
  real_T c1_r_y;
  real_T c1_p_x;
  real_T c1_s_y;
  real_T c1_t_y;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i20;
  real_T *c1_b_Rot;
  real_T *c1_b_intRot;
  real_T *c1_b_phase;
  real_T (*c1_b_Vel)[2];
  real_T (*c1_b_SCold1)[3];
  real_T (*c1_b_SCold)[3];
  real_T (*c1_b_SCtransl)[3];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  boolean_T guard5 = FALSE;
  boolean_T guard6 = FALSE;
  c1_b_SCold1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c1_b_Rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_Vel = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_SCold = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_intRot = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_phase = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_SCtransl = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_phase;
  c1_b_hoistedGlobal = *c1_b_intRot;
  c1_c_hoistedGlobal = chartInstance->c1_f13;
  c1_d_hoistedGlobal = chartInstance->c1_f24;
  for (c1_i8 = 0; c1_i8 < 3; c1_i8++) {
    c1_SCtransl[c1_i8] = (*c1_b_SCtransl)[c1_i8];
  }

  c1_phase = c1_hoistedGlobal;
  c1_intRot = c1_b_hoistedGlobal;
  for (c1_i9 = 0; c1_i9 < 3; c1_i9++) {
    c1_SCold[c1_i9] = (*c1_b_SCold)[c1_i9];
  }

  c1_b_f13 = c1_c_hoistedGlobal;
  c1_b_f24 = c1_d_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 20U, 20U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_r, 0U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Xf, 1U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Xi, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_DeltaSC, 3U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_alpha, 4U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_Sl, 5U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_Sr, 6U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_R, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_alpha1, 8U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 9U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 10U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_SCtransl, 11U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_phase, 12U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_intRot, 13U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_SCold, 14U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_f13, 15U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_f24, 16U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Vel, 17U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_Rot, 18U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_SCold1, 19U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_r = 0.13;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
  if (CV_EML_IF(0, 1, 0, c1_phase == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
    for (c1_i10 = 0; c1_i10 < 3; c1_i10++) {
      c1_SCold1[c1_i10] = c1_SCold[c1_i10];
    }

    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
    for (c1_i11 = 0; c1_i11 < 2; c1_i11++) {
      c1_Vel[c1_i11] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
    c1_Rot = 0.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 15);
    if (CV_EML_IF(0, 1, 1, c1_phase == 2.0)) {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
      for (c1_i12 = 0; c1_i12 < 2; c1_i12++) {
        c1_Xf[c1_i12] = c1_SCtransl[c1_i12];
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
      for (c1_i13 = 0; c1_i13 < 3; c1_i13++) {
        c1_Xi[c1_i13] = c1_SCold[c1_i13];
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 19);
      c1_DeltaSC[0] = c1_Xf[0] - c1_Xi[0];
      c1_DeltaSC[1] = c1_Xf[1] - c1_Xi[1];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
      c1_y = c1_DeltaSC[1];
      c1_x = c1_DeltaSC[0];
      c1_eml_scalar_eg(chartInstance);
      c1_b_y = c1_y;
      c1_b_x = c1_x;
      c1_alpha = muDoubleScalarAtan2(c1_b_y, c1_b_x);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 23);
      guard4 = FALSE;
      if (CV_EML_COND(0, 1, 0, c1_alpha >= 0.0)) {
        if (CV_EML_COND(0, 1, 1, c1_alpha < 1.57)) {
          CV_EML_MCDC(0, 1, 0, TRUE);
          CV_EML_IF(0, 1, 2, TRUE);
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
          c1_a = c1_alpha;
          c1_Sl = c1_a * -0.13;
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 25);
          c1_b_a = c1_alpha;
          c1_Sr = c1_b_a * 0.13;
        } else {
          guard4 = TRUE;
        }
      } else {
        guard4 = TRUE;
      }

      if (guard4 == TRUE) {
        CV_EML_MCDC(0, 1, 0, FALSE);
        CV_EML_IF(0, 1, 2, FALSE);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 26);
        guard5 = FALSE;
        if (CV_EML_COND(0, 1, 2, c1_alpha >= 1.57)) {
          if (CV_EML_COND(0, 1, 3, c1_alpha <= 3.14)) {
            CV_EML_MCDC(0, 1, 1, TRUE);
            CV_EML_IF(0, 1, 3, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 27);
            c1_c_a = c1_alpha;
            c1_Sl = c1_c_a * -0.13;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 28);
            c1_d_a = c1_alpha;
            c1_Sr = c1_d_a * 0.13;
          } else {
            guard5 = TRUE;
          }
        } else {
          guard5 = TRUE;
        }

        if (guard5 == TRUE) {
          CV_EML_MCDC(0, 1, 1, FALSE);
          CV_EML_IF(0, 1, 3, FALSE);
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 29);
          guard6 = FALSE;
          if (CV_EML_COND(0, 1, 4, c1_alpha < 0.0)) {
            if (CV_EML_COND(0, 1, 5, c1_alpha > -1.57)) {
              CV_EML_MCDC(0, 1, 2, TRUE);
              CV_EML_IF(0, 1, 4, TRUE);
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 30);
              c1_e_a = -c1_alpha;
              c1_Sl = c1_e_a * 0.13;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 31);
              c1_f_a = -c1_alpha;
              c1_Sr = c1_f_a * -0.13;
            } else {
              guard6 = TRUE;
            }
          } else {
            guard6 = TRUE;
          }

          if (guard6 == TRUE) {
            CV_EML_MCDC(0, 1, 2, FALSE);
            CV_EML_IF(0, 1, 4, FALSE);
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 33);
            c1_g_a = -c1_alpha;
            c1_Sl = c1_g_a * 0.13;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 34);
            c1_h_a = -c1_alpha;
            c1_Sr = c1_h_a * -0.13;
          }
        }
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 38);
      c1_A = c1_Sr;
      c1_B = c1_b_f24;
      c1_c_x = c1_A;
      c1_c_y = c1_B;
      c1_d_x = c1_c_x;
      c1_d_y = c1_c_y;
      c1_e_y = c1_d_x / c1_d_y;
      c1_b_A = c1_Sl;
      c1_b_B = c1_b_f24;
      c1_e_x = c1_b_A;
      c1_f_y = c1_b_B;
      c1_f_x = c1_e_x;
      c1_g_y = c1_f_y;
      c1_h_y = c1_f_x / c1_g_y;
      c1_Vel[0] = c1_e_y;
      c1_Vel[1] = c1_h_y;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 39);
      c1_Rot = -c1_alpha;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 40);
      for (c1_i14 = 0; c1_i14 < 3; c1_i14++) {
        c1_SCold1[c1_i14] = c1_SCold[c1_i14];
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 41);
      c1_SCold1[2] = -c1_alpha;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 42);
      if (CV_EML_IF(0, 1, 5, c1_phase == 3.0)) {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 44);
        for (c1_i15 = 0; c1_i15 < 2; c1_i15++) {
          c1_Xf[c1_i15] = c1_SCtransl[c1_i15];
        }

        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 45);
        for (c1_i16 = 0; c1_i16 < 3; c1_i16++) {
          c1_Xi[c1_i16] = c1_SCold[c1_i16];
        }

        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 46);
        c1_DeltaSC[0] = c1_Xf[0] - c1_Xi[0];
        c1_DeltaSC[1] = c1_Xf[1] - c1_Xi[1];
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 47);
        c1_g_x = c1_mpower(chartInstance, c1_DeltaSC[0]) + c1_mpower
          (chartInstance, c1_DeltaSC[1]);
        c1_R = c1_g_x;
        if (c1_R < 0.0) {
          c1_eml_error(chartInstance);
        }

        c1_h_x = c1_R;
        c1_R = c1_h_x;
        c1_R = muDoubleScalarSqrt(c1_R);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 49);
        c1_c_A = c1_R;
        c1_c_B = c1_b_f13;
        c1_i_x = c1_c_A;
        c1_i_y = c1_c_B;
        c1_j_x = c1_i_x;
        c1_j_y = c1_i_y;
        c1_k_y = c1_j_x / c1_j_y;
        c1_d_A = c1_R;
        c1_d_B = c1_b_f13;
        c1_k_x = c1_d_A;
        c1_l_y = c1_d_B;
        c1_l_x = c1_k_x;
        c1_m_y = c1_l_y;
        c1_n_y = c1_l_x / c1_m_y;
        c1_Vel[0] = c1_k_y;
        c1_Vel[1] = c1_n_y;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 50);
        c1_Rot = c1_SCtransl[2] + c1_SCold[2];
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 51);
        for (c1_i17 = 0; c1_i17 < 3; c1_i17++) {
          c1_SCold1[c1_i17] = c1_SCold[c1_i17];
        }
      } else {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 54);
        c1_alpha1 = -c1_intRot;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 55);
        guard1 = FALSE;
        if (CV_EML_COND(0, 1, 6, c1_alpha1 >= 0.0)) {
          if (CV_EML_COND(0, 1, 7, c1_alpha1 < 1.57)) {
            CV_EML_MCDC(0, 1, 3, TRUE);
            CV_EML_IF(0, 1, 6, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 56);
            c1_i_a = c1_alpha1;
            c1_Sl = c1_i_a * -0.13;
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 57);
            c1_j_a = c1_alpha1;
            c1_Sr = c1_j_a * 0.13;
          } else {
            guard1 = TRUE;
          }
        } else {
          guard1 = TRUE;
        }

        if (guard1 == TRUE) {
          CV_EML_MCDC(0, 1, 3, FALSE);
          CV_EML_IF(0, 1, 6, FALSE);
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 58);
          guard2 = FALSE;
          if (CV_EML_COND(0, 1, 8, c1_alpha1 >= 1.57)) {
            if (CV_EML_COND(0, 1, 9, c1_alpha1 <= 3.14)) {
              CV_EML_MCDC(0, 1, 4, TRUE);
              CV_EML_IF(0, 1, 7, TRUE);
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 59);
              c1_k_a = c1_alpha1;
              c1_Sl = c1_k_a * -0.13;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 60);
              c1_l_a = c1_alpha1;
              c1_Sr = c1_l_a * 0.13;
            } else {
              guard2 = TRUE;
            }
          } else {
            guard2 = TRUE;
          }

          if (guard2 == TRUE) {
            CV_EML_MCDC(0, 1, 4, FALSE);
            CV_EML_IF(0, 1, 7, FALSE);
            _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 61);
            guard3 = FALSE;
            if (CV_EML_COND(0, 1, 10, c1_alpha1 < 0.0)) {
              if (CV_EML_COND(0, 1, 11, c1_alpha1 > -1.57)) {
                CV_EML_MCDC(0, 1, 5, TRUE);
                CV_EML_IF(0, 1, 8, TRUE);
                _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 62);
                c1_m_a = -c1_alpha1;
                c1_Sl = c1_m_a * 0.13;
                _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 63);
                c1_n_a = -c1_alpha1;
                c1_Sr = c1_n_a * -0.13;
              } else {
                guard3 = TRUE;
              }
            } else {
              guard3 = TRUE;
            }

            if (guard3 == TRUE) {
              CV_EML_MCDC(0, 1, 5, FALSE);
              CV_EML_IF(0, 1, 8, FALSE);
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 65);
              c1_o_a = -c1_alpha1;
              c1_Sl = c1_o_a * 0.13;
              _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 66);
              c1_p_a = -c1_alpha1;
              c1_Sr = c1_p_a * -0.13;
            }
          }
        }

        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 70);
        c1_e_A = c1_Sr;
        c1_e_B = c1_b_f24;
        c1_m_x = c1_e_A;
        c1_o_y = c1_e_B;
        c1_n_x = c1_m_x;
        c1_p_y = c1_o_y;
        c1_q_y = c1_n_x / c1_p_y;
        c1_f_A = c1_Sl;
        c1_f_B = c1_b_f24;
        c1_o_x = c1_f_A;
        c1_r_y = c1_f_B;
        c1_p_x = c1_o_x;
        c1_s_y = c1_r_y;
        c1_t_y = c1_p_x / c1_s_y;
        c1_Vel[0] = c1_q_y;
        c1_Vel[1] = c1_t_y;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 71);
        c1_Rot = -c1_alpha1;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 72);
        for (c1_i18 = 0; c1_i18 < 2; c1_i18++) {
          c1_SCold1[c1_i18] = c1_SCtransl[c1_i18];
        }

        c1_SCold1[2] = 0.0;
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -72);
  _SFD_SYMBOL_SCOPE_POP();
  for (c1_i19 = 0; c1_i19 < 2; c1_i19++) {
    (*c1_b_Vel)[c1_i19] = c1_Vel[c1_i19];
  }

  *c1_b_Rot = c1_Rot;
  for (c1_i20 = 0; c1_i20 < 3; c1_i20++) {
    (*c1_b_SCold1)[c1_i20] = c1_SCold1[c1_i20];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_CusakisME4901delay2
  (SFc1_CusakisME4901delay2InstanceStruct *chartInstance)
{
}

static void registerMessagesc1_CusakisME4901delay2
  (SFc1_CusakisME4901delay2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i21;
  real_T c1_b_inData[3];
  int32_T c1_i22;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_CusakisME4901delay2InstanceStruct *chartInstance;
  chartInstance = (SFc1_CusakisME4901delay2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i21 = 0; c1_i21 < 3; c1_i21++) {
    c1_b_inData[c1_i21] = (*(real_T (*)[3])c1_inData)[c1_i21];
  }

  for (c1_i22 = 0; c1_i22 < 3; c1_i22++) {
    c1_u[c1_i22] = c1_b_inData[c1_i22];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_CusakisME4901delay2InstanceStruct
  *chartInstance, const mxArray *c1_SCold1, const char_T *c1_identifier, real_T
  c1_y[3])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_SCold1), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_SCold1);
}

static void c1_b_emlrt_marshallIn(SFc1_CusakisME4901delay2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[3])
{
  real_T c1_dv2[3];
  int32_T c1_i23;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv2, 1, 0, 0U, 1, 0U, 1, 3);
  for (c1_i23 = 0; c1_i23 < 3; c1_i23++) {
    c1_y[c1_i23] = c1_dv2[c1_i23];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_SCold1;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[3];
  int32_T c1_i24;
  SFc1_CusakisME4901delay2InstanceStruct *chartInstance;
  chartInstance = (SFc1_CusakisME4901delay2InstanceStruct *)chartInstanceVoid;
  c1_SCold1 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_SCold1), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_SCold1);
  for (c1_i24 = 0; c1_i24 < 3; c1_i24++) {
    (*(real_T (*)[3])c1_outData)[c1_i24] = c1_y[c1_i24];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_CusakisME4901delay2InstanceStruct *chartInstance;
  chartInstance = (SFc1_CusakisME4901delay2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn(SFc1_CusakisME4901delay2InstanceStruct
  *chartInstance, const mxArray *c1_Rot, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Rot), &c1_thisId);
  sf_mex_destroy(&c1_Rot);
  return c1_y;
}

static real_T c1_d_emlrt_marshallIn(SFc1_CusakisME4901delay2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d2;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d2, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d2;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Rot;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_CusakisME4901delay2InstanceStruct *chartInstance;
  chartInstance = (SFc1_CusakisME4901delay2InstanceStruct *)chartInstanceVoid;
  c1_Rot = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Rot), &c1_thisId);
  sf_mex_destroy(&c1_Rot);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i25;
  real_T c1_b_inData[2];
  int32_T c1_i26;
  real_T c1_u[2];
  const mxArray *c1_y = NULL;
  SFc1_CusakisME4901delay2InstanceStruct *chartInstance;
  chartInstance = (SFc1_CusakisME4901delay2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i25 = 0; c1_i25 < 2; c1_i25++) {
    c1_b_inData[c1_i25] = (*(real_T (*)[2])c1_inData)[c1_i25];
  }

  for (c1_i26 = 0; c1_i26 < 2; c1_i26++) {
    c1_u[c1_i26] = c1_b_inData[c1_i26];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_e_emlrt_marshallIn(SFc1_CusakisME4901delay2InstanceStruct
  *chartInstance, const mxArray *c1_Vel, const char_T *c1_identifier, real_T
  c1_y[2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Vel), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Vel);
}

static void c1_f_emlrt_marshallIn(SFc1_CusakisME4901delay2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[2])
{
  real_T c1_dv3[2];
  int32_T c1_i27;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv3, 1, 0, 0U, 1, 0U, 1, 2);
  for (c1_i27 = 0; c1_i27 < 2; c1_i27++) {
    c1_y[c1_i27] = c1_dv3[c1_i27];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Vel;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[2];
  int32_T c1_i28;
  SFc1_CusakisME4901delay2InstanceStruct *chartInstance;
  chartInstance = (SFc1_CusakisME4901delay2InstanceStruct *)chartInstanceVoid;
  c1_Vel = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Vel), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Vel);
  for (c1_i28 = 0; c1_i28 < 2; c1_i28++) {
    (*(real_T (*)[2])c1_outData)[c1_i28] = c1_y[c1_i28];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_CusakisME4901delay2_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[20];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i29;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 20), FALSE);
  for (c1_i29 = 0; c1_i29 < 20; c1_i29++) {
    c1_r0 = &c1_info[c1_i29];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i29);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i29);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i29);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i29);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i29);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i29);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i29);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i29);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[20])
{
  c1_info[0].context = "";
  c1_info[0].name = "atan2";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c1_info[0].fileTimeLo = 1343862772U;
  c1_info[0].fileTimeHi = 0U;
  c1_info[0].mFileTimeLo = 0U;
  c1_info[0].mFileTimeHi = 0U;
  c1_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c1_info[1].name = "eml_scalar_eg";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[1].fileTimeLo = 1286851196U;
  c1_info[1].fileTimeHi = 0U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c1_info[2].name = "eml_scalexp_alloc";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[2].fileTimeLo = 1352457260U;
  c1_info[2].fileTimeHi = 0U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c1_info[3].name = "eml_scalar_atan2";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m";
  c1_info[3].fileTimeLo = 1286851120U;
  c1_info[3].fileTimeHi = 0U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context = "";
  c1_info[4].name = "mtimes";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[4].fileTimeLo = 1289552092U;
  c1_info[4].fileTimeHi = 0U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context = "";
  c1_info[5].name = "mrdivide";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[5].fileTimeLo = 1357983948U;
  c1_info[5].fileTimeHi = 0U;
  c1_info[5].mFileTimeLo = 1319762366U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[6].name = "rdivide";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[6].fileTimeLo = 1346542788U;
  c1_info[6].fileTimeHi = 0U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[7].name = "eml_scalexp_compatible";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c1_info[7].fileTimeLo = 1286851196U;
  c1_info[7].fileTimeHi = 0U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[8].name = "eml_div";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[8].fileTimeLo = 1313380210U;
  c1_info[8].fileTimeHi = 0U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context = "";
  c1_info[9].name = "mpower";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[9].fileTimeLo = 1286851242U;
  c1_info[9].fileTimeHi = 0U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[10].name = "power";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[10].fileTimeLo = 1348224330U;
  c1_info[10].fileTimeHi = 0U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[11].name = "eml_scalar_eg";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[11].fileTimeLo = 1286851196U;
  c1_info[11].fileTimeHi = 0U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[12].name = "eml_scalexp_alloc";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[12].fileTimeLo = 1352457260U;
  c1_info[12].fileTimeHi = 0U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[13].name = "floor";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[13].fileTimeLo = 1343862780U;
  c1_info[13].fileTimeHi = 0U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
  c1_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[14].name = "eml_scalar_floor";
  c1_info[14].dominantType = "double";
  c1_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[14].fileTimeLo = 1286851126U;
  c1_info[14].fileTimeHi = 0U;
  c1_info[14].mFileTimeLo = 0U;
  c1_info[14].mFileTimeHi = 0U;
  c1_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c1_info[15].name = "eml_scalar_eg";
  c1_info[15].dominantType = "double";
  c1_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[15].fileTimeLo = 1286851196U;
  c1_info[15].fileTimeHi = 0U;
  c1_info[15].mFileTimeLo = 0U;
  c1_info[15].mFileTimeHi = 0U;
  c1_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c1_info[16].name = "mtimes";
  c1_info[16].dominantType = "double";
  c1_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[16].fileTimeLo = 1289552092U;
  c1_info[16].fileTimeHi = 0U;
  c1_info[16].mFileTimeLo = 0U;
  c1_info[16].mFileTimeHi = 0U;
  c1_info[17].context = "";
  c1_info[17].name = "sqrt";
  c1_info[17].dominantType = "double";
  c1_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[17].fileTimeLo = 1343862786U;
  c1_info[17].fileTimeHi = 0U;
  c1_info[17].mFileTimeLo = 0U;
  c1_info[17].mFileTimeHi = 0U;
  c1_info[18].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[18].name = "eml_error";
  c1_info[18].dominantType = "char";
  c1_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[18].fileTimeLo = 1343862758U;
  c1_info[18].fileTimeHi = 0U;
  c1_info[18].mFileTimeLo = 0U;
  c1_info[18].mFileTimeHi = 0U;
  c1_info[19].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[19].name = "eml_scalar_sqrt";
  c1_info[19].dominantType = "double";
  c1_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c1_info[19].fileTimeLo = 1286851138U;
  c1_info[19].fileTimeHi = 0U;
  c1_info[19].mFileTimeLo = 0U;
  c1_info[19].mFileTimeHi = 0U;
}

static void c1_eml_scalar_eg(SFc1_CusakisME4901delay2InstanceStruct
  *chartInstance)
{
}

static real_T c1_mpower(SFc1_CusakisME4901delay2InstanceStruct *chartInstance,
  real_T c1_a)
{
  real_T c1_b_a;
  real_T c1_c_a;
  real_T c1_ak;
  real_T c1_d_a;
  real_T c1_e_a;
  real_T c1_b;
  c1_b_a = c1_a;
  c1_c_a = c1_b_a;
  c1_eml_scalar_eg(chartInstance);
  c1_ak = c1_c_a;
  c1_d_a = c1_ak;
  c1_eml_scalar_eg(chartInstance);
  c1_e_a = c1_d_a;
  c1_b = c1_d_a;
  return c1_e_a * c1_b;
}

static void c1_eml_error(SFc1_CusakisME4901delay2InstanceStruct *chartInstance)
{
  int32_T c1_i30;
  static char_T c1_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c1_u[30];
  const mxArray *c1_y = NULL;
  int32_T c1_i31;
  static char_T c1_cv1[4] = { 's', 'q', 'r', 't' };

  char_T c1_b_u[4];
  const mxArray *c1_b_y = NULL;
  for (c1_i30 = 0; c1_i30 < 30; c1_i30++) {
    c1_u[c1_i30] = c1_cv0[c1_i30];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  for (c1_i31 = 0; c1_i31 < 4; c1_i31++) {
    c1_b_u[c1_i31] = c1_cv1[c1_i31];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c1_y, 14, c1_b_y));
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_CusakisME4901delay2InstanceStruct *chartInstance;
  chartInstance = (SFc1_CusakisME4901delay2InstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_g_emlrt_marshallIn(SFc1_CusakisME4901delay2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i32;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i32, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i32;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_CusakisME4901delay2InstanceStruct *chartInstance;
  chartInstance = (SFc1_CusakisME4901delay2InstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_h_emlrt_marshallIn(SFc1_CusakisME4901delay2InstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_CusakisME4901delay2, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_CusakisME4901delay2), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_CusakisME4901delay2);
  return c1_y;
}

static uint8_T c1_i_emlrt_marshallIn(SFc1_CusakisME4901delay2InstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_CusakisME4901delay2InstanceStruct
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

void sf_c1_CusakisME4901delay2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2850450634U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(861255777U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3578893682U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2311602002U);
}

mxArray *sf_c1_CusakisME4901delay2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("DlQrn7fiI8JcVnbvjHGfqE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
      pr[0] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_CusakisME4901delay2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_CusakisME4901delay2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[22],T\"Rot\",},{M[1],M[31],T\"SCold1\",},{M[1],M[5],T\"Vel\",},{M[8],M[0],T\"is_active_c1_CusakisME4901delay2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_CusakisME4901delay2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_CusakisME4901delay2InstanceStruct *chartInstance;
    chartInstance = (SFc1_CusakisME4901delay2InstanceStruct *) ((ChartInfoStruct
      *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CusakisME4901delay2MachineNumber_,
           1,
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
          init_script_number_translation(_CusakisME4901delay2MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_CusakisME4901delay2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _CusakisME4901delay2MachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"SCtransl");
          _SFD_SET_DATA_PROPS(1,1,1,0,"phase");
          _SFD_SET_DATA_PROPS(2,1,1,0,"intRot");
          _SFD_SET_DATA_PROPS(3,1,1,0,"SCold");
          _SFD_SET_DATA_PROPS(4,2,0,1,"Vel");
          _SFD_SET_DATA_PROPS(5,2,0,1,"Rot");
          _SFD_SET_DATA_PROPS(6,10,0,0,"f13");
          _SFD_SET_DATA_PROPS(7,10,0,0,"f24");
          _SFD_SET_DATA_PROPS(8,2,0,1,"SCold1");
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
        _SFD_CV_INIT_EML(0,1,1,9,0,0,0,0,0,12,6);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2213);
        _SFD_CV_INIT_EML_IF(0,1,0,182,193,327,2208);
        _SFD_CV_INIT_EML_IF(0,1,1,327,342,1152,2208);
        _SFD_CV_INIT_EML_IF(0,1,2,609,635,685,910);
        _SFD_CV_INIT_EML_IF(0,1,3,685,719,769,910);
        _SFD_CV_INIT_EML_IF(0,1,4,769,799,851,910);
        _SFD_CV_INIT_EML_IF(0,1,5,1152,1167,1570,2208);
        _SFD_CV_INIT_EML_IF(0,1,6,1656,1684,1736,1972);
        _SFD_CV_INIT_EML_IF(0,1,7,1736,1772,1824,1972);
        _SFD_CV_INIT_EML_IF(0,1,8,1824,1856,1910,1972);

        {
          static int condStart[] = { 612, 624 };

          static int condEnd[] = { 620, 635 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,612,635,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 692, 707 };

          static int condEnd[] = { 703, 719 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,692,719,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 776, 787 };

          static int condEnd[] = { 783, 799 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,2,776,799,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1659, 1672 };

          static int condEnd[] = { 1668, 1684 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,3,1659,1684,2,6,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1743, 1759 };

          static int condEnd[] = { 1755, 1772 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,4,1743,1772,2,8,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1831, 1843 };

          static int condEnd[] = { 1839, 1856 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,5,1831,1856,2,10,&(condStart[0]),&(condEnd[0]),
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

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)
            c1_c_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          real_T *c1_phase;
          real_T *c1_intRot;
          real_T *c1_Rot;
          real_T (*c1_SCtransl)[3];
          real_T (*c1_SCold)[3];
          real_T (*c1_Vel)[2];
          real_T (*c1_SCold1)[3];
          c1_SCold1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
          c1_Rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_Vel = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_SCold = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
          c1_intRot = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_phase = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_SCtransl = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_SCtransl);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_phase);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_intRot);
          _SFD_SET_DATA_VALUE_PTR(3U, *c1_SCold);
          _SFD_SET_DATA_VALUE_PTR(4U, *c1_Vel);
          _SFD_SET_DATA_VALUE_PTR(5U, c1_Rot);
          _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c1_f13);
          _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c1_f24);
          _SFD_SET_DATA_VALUE_PTR(8U, *c1_SCold1);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _CusakisME4901delay2MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "VwIvUVJ7mbEUjk9KIEjjME";
}

static void sf_opaque_initialize_c1_CusakisME4901delay2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_CusakisME4901delay2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_CusakisME4901delay2
    ((SFc1_CusakisME4901delay2InstanceStruct*) chartInstanceVar);
  initialize_c1_CusakisME4901delay2((SFc1_CusakisME4901delay2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_CusakisME4901delay2(void *chartInstanceVar)
{
  enable_c1_CusakisME4901delay2((SFc1_CusakisME4901delay2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_CusakisME4901delay2(void *chartInstanceVar)
{
  disable_c1_CusakisME4901delay2((SFc1_CusakisME4901delay2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_CusakisME4901delay2(void *chartInstanceVar)
{
  sf_c1_CusakisME4901delay2((SFc1_CusakisME4901delay2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_CusakisME4901delay2(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_CusakisME4901delay2
    ((SFc1_CusakisME4901delay2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_CusakisME4901delay2();/* state var info */
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

extern void sf_internal_set_sim_state_c1_CusakisME4901delay2(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_CusakisME4901delay2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_CusakisME4901delay2((SFc1_CusakisME4901delay2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_CusakisME4901delay2(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c1_CusakisME4901delay2(S);
}

static void sf_opaque_set_sim_state_c1_CusakisME4901delay2(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_CusakisME4901delay2(S, st);
}

static void sf_opaque_terminate_c1_CusakisME4901delay2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_CusakisME4901delay2InstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CusakisME4901delay2_optimization_info();
    }

    finalize_c1_CusakisME4901delay2((SFc1_CusakisME4901delay2InstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_CusakisME4901delay2((SFc1_CusakisME4901delay2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_CusakisME4901delay2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_CusakisME4901delay2
      ((SFc1_CusakisME4901delay2InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_CusakisME4901delay2(SimStruct *S)
{
  /* Actual parameters from chart:
     f13 f24
   */
  const char_T *rtParamNames[] = { "f13", "f24" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for f13*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for f24*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CusakisME4901delay2_optimization_info();
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3643165620U));
  ssSetChecksum1(S,(3342152071U));
  ssSetChecksum2(S,(2611385242U));
  ssSetChecksum3(S,(198196816U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_CusakisME4901delay2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_CusakisME4901delay2(SimStruct *S)
{
  SFc1_CusakisME4901delay2InstanceStruct *chartInstance;
  chartInstance = (SFc1_CusakisME4901delay2InstanceStruct *)utMalloc(sizeof
    (SFc1_CusakisME4901delay2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_CusakisME4901delay2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_CusakisME4901delay2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_CusakisME4901delay2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_CusakisME4901delay2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_CusakisME4901delay2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_CusakisME4901delay2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_CusakisME4901delay2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_CusakisME4901delay2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_CusakisME4901delay2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_CusakisME4901delay2;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_CusakisME4901delay2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_CusakisME4901delay2;
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

void c1_CusakisME4901delay2_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_CusakisME4901delay2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_CusakisME4901delay2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_CusakisME4901delay2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_CusakisME4901delay2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
