/* Include files */

#include <stddef.h>
#include "blas.h"
#include "CusakisME4901arcs_sfun.h"
#include "c35_CusakisME4901arcs.h"
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
static const char * c35_debug_family_names[23] = { "R", "Sl", "Sr", "r",
  "Rotation", "Xf", "Xi", "D", "alpha", "nargin", "nargout", "SCtranslation",
  "baseoutm", "Velm", "timer", "NewPos", "basem", "Vel", "timem", "NP", "base",
  "baseout", "enable" };

/* Function Declarations */
static void initialize_c35_CusakisME4901arcs
  (SFc35_CusakisME4901arcsInstanceStruct *chartInstance);
static void initialize_params_c35_CusakisME4901arcs
  (SFc35_CusakisME4901arcsInstanceStruct *chartInstance);
static void enable_c35_CusakisME4901arcs(SFc35_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void disable_c35_CusakisME4901arcs(SFc35_CusakisME4901arcsInstanceStruct *
  chartInstance);
static void c35_update_debugger_state_c35_CusakisME4901arcs
  (SFc35_CusakisME4901arcsInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c35_CusakisME4901arcs
  (SFc35_CusakisME4901arcsInstanceStruct *chartInstance);
static void set_sim_state_c35_CusakisME4901arcs
  (SFc35_CusakisME4901arcsInstanceStruct *chartInstance, const mxArray *c35_st);
static void finalize_c35_CusakisME4901arcs(SFc35_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void sf_c35_CusakisME4901arcs(SFc35_CusakisME4901arcsInstanceStruct
  *chartInstance);
static void c35_chartstep_c35_CusakisME4901arcs
  (SFc35_CusakisME4901arcsInstanceStruct *chartInstance);
static void initSimStructsc35_CusakisME4901arcs
  (SFc35_CusakisME4901arcsInstanceStruct *chartInstance);
static void registerMessagesc35_CusakisME4901arcs
  (SFc35_CusakisME4901arcsInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c35_machineNumber, uint32_T
  c35_chartNumber);
static const mxArray *c35_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static real_T c35_emlrt_marshallIn(SFc35_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c35_enable, const char_T *c35_identifier);
static real_T c35_b_emlrt_marshallIn(SFc35_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void c35_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static const mxArray *c35_b_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static void c35_c_emlrt_marshallIn(SFc35_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c35_NP, const char_T *c35_identifier, real_T
  c35_y[2]);
static void c35_d_emlrt_marshallIn(SFc35_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[2]);
static void c35_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static const mxArray *c35_c_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static void c35_e_emlrt_marshallIn(SFc35_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[4]);
static void c35_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static void c35_info_helper(c35_ResolvedFunctionInfo c35_info[33]);
static void c35_eml_scalar_eg(SFc35_CusakisME4901arcsInstanceStruct
  *chartInstance);
static real_T c35_mpower(SFc35_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c35_a);
static void c35_b_eml_scalar_eg(SFc35_CusakisME4901arcsInstanceStruct
  *chartInstance);
static real_T c35_sqrt(SFc35_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c35_x);
static void c35_eml_error(SFc35_CusakisME4901arcsInstanceStruct *chartInstance);
static real_T c35_abs(SFc35_CusakisME4901arcsInstanceStruct *chartInstance,
                      real_T c35_x);
static real_T c35_asin(SFc35_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c35_x);
static void c35_b_eml_error(SFc35_CusakisME4901arcsInstanceStruct *chartInstance);
static const mxArray *c35_d_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static int32_T c35_f_emlrt_marshallIn(SFc35_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void c35_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static uint8_T c35_g_emlrt_marshallIn(SFc35_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c35_b_is_active_c35_CusakisME4901arcs, const
  char_T *c35_identifier);
static uint8_T c35_h_emlrt_marshallIn(SFc35_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void c35_b_sqrt(SFc35_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T *c35_x);
static void c35_b_asin(SFc35_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T *c35_x);
static void init_dsm_address_info(SFc35_CusakisME4901arcsInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c35_CusakisME4901arcs
  (SFc35_CusakisME4901arcsInstanceStruct *chartInstance)
{
  chartInstance->c35_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c35_is_active_c35_CusakisME4901arcs = 0U;
}

static void initialize_params_c35_CusakisME4901arcs
  (SFc35_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static void enable_c35_CusakisME4901arcs(SFc35_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c35_CusakisME4901arcs(SFc35_CusakisME4901arcsInstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c35_update_debugger_state_c35_CusakisME4901arcs
  (SFc35_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c35_CusakisME4901arcs
  (SFc35_CusakisME4901arcsInstanceStruct *chartInstance)
{
  const mxArray *c35_st;
  const mxArray *c35_y = NULL;
  int32_T c35_i0;
  real_T c35_u[2];
  const mxArray *c35_b_y = NULL;
  int32_T c35_i1;
  real_T c35_b_u[2];
  const mxArray *c35_c_y = NULL;
  real_T c35_hoistedGlobal;
  real_T c35_c_u;
  const mxArray *c35_d_y = NULL;
  real_T c35_b_hoistedGlobal;
  real_T c35_d_u;
  const mxArray *c35_e_y = NULL;
  real_T c35_c_hoistedGlobal;
  real_T c35_e_u;
  const mxArray *c35_f_y = NULL;
  real_T c35_d_hoistedGlobal;
  real_T c35_f_u;
  const mxArray *c35_g_y = NULL;
  uint8_T c35_e_hoistedGlobal;
  uint8_T c35_g_u;
  const mxArray *c35_h_y = NULL;
  real_T *c35_base;
  real_T *c35_baseout;
  real_T *c35_enable;
  real_T *c35_timem;
  real_T (*c35_Vel)[2];
  real_T (*c35_NP)[2];
  c35_enable = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c35_baseout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c35_base = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c35_NP = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 3);
  c35_timem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c35_Vel = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c35_st = NULL;
  c35_st = NULL;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_createcellarray(7), FALSE);
  for (c35_i0 = 0; c35_i0 < 2; c35_i0++) {
    c35_u[c35_i0] = (*c35_NP)[c35_i0];
  }

  c35_b_y = NULL;
  sf_mex_assign(&c35_b_y, sf_mex_create("y", c35_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_setcell(c35_y, 0, c35_b_y);
  for (c35_i1 = 0; c35_i1 < 2; c35_i1++) {
    c35_b_u[c35_i1] = (*c35_Vel)[c35_i1];
  }

  c35_c_y = NULL;
  sf_mex_assign(&c35_c_y, sf_mex_create("y", c35_b_u, 0, 0U, 1U, 0U, 1, 2),
                FALSE);
  sf_mex_setcell(c35_y, 1, c35_c_y);
  c35_hoistedGlobal = *c35_base;
  c35_c_u = c35_hoistedGlobal;
  c35_d_y = NULL;
  sf_mex_assign(&c35_d_y, sf_mex_create("y", &c35_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c35_y, 2, c35_d_y);
  c35_b_hoistedGlobal = *c35_baseout;
  c35_d_u = c35_b_hoistedGlobal;
  c35_e_y = NULL;
  sf_mex_assign(&c35_e_y, sf_mex_create("y", &c35_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c35_y, 3, c35_e_y);
  c35_c_hoistedGlobal = *c35_enable;
  c35_e_u = c35_c_hoistedGlobal;
  c35_f_y = NULL;
  sf_mex_assign(&c35_f_y, sf_mex_create("y", &c35_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c35_y, 4, c35_f_y);
  c35_d_hoistedGlobal = *c35_timem;
  c35_f_u = c35_d_hoistedGlobal;
  c35_g_y = NULL;
  sf_mex_assign(&c35_g_y, sf_mex_create("y", &c35_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c35_y, 5, c35_g_y);
  c35_e_hoistedGlobal = chartInstance->c35_is_active_c35_CusakisME4901arcs;
  c35_g_u = c35_e_hoistedGlobal;
  c35_h_y = NULL;
  sf_mex_assign(&c35_h_y, sf_mex_create("y", &c35_g_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c35_y, 6, c35_h_y);
  sf_mex_assign(&c35_st, c35_y, FALSE);
  return c35_st;
}

static void set_sim_state_c35_CusakisME4901arcs
  (SFc35_CusakisME4901arcsInstanceStruct *chartInstance, const mxArray *c35_st)
{
  const mxArray *c35_u;
  real_T c35_dv0[2];
  int32_T c35_i2;
  real_T c35_dv1[2];
  int32_T c35_i3;
  real_T *c35_base;
  real_T *c35_baseout;
  real_T *c35_enable;
  real_T *c35_timem;
  real_T (*c35_NP)[2];
  real_T (*c35_Vel)[2];
  c35_enable = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c35_baseout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c35_base = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c35_NP = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 3);
  c35_timem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c35_Vel = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c35_doneDoubleBufferReInit = TRUE;
  c35_u = sf_mex_dup(c35_st);
  c35_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c35_u, 0)),
    "NP", c35_dv0);
  for (c35_i2 = 0; c35_i2 < 2; c35_i2++) {
    (*c35_NP)[c35_i2] = c35_dv0[c35_i2];
  }

  c35_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c35_u, 1)),
    "Vel", c35_dv1);
  for (c35_i3 = 0; c35_i3 < 2; c35_i3++) {
    (*c35_Vel)[c35_i3] = c35_dv1[c35_i3];
  }

  *c35_base = c35_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c35_u, 2)), "base");
  *c35_baseout = c35_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c35_u, 3)), "baseout");
  *c35_enable = c35_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c35_u, 4)), "enable");
  *c35_timem = c35_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c35_u, 5)), "timem");
  chartInstance->c35_is_active_c35_CusakisME4901arcs = c35_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c35_u, 6)),
     "is_active_c35_CusakisME4901arcs");
  sf_mex_destroy(&c35_u);
  c35_update_debugger_state_c35_CusakisME4901arcs(chartInstance);
  sf_mex_destroy(&c35_st);
}

static void finalize_c35_CusakisME4901arcs(SFc35_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
}

static void sf_c35_CusakisME4901arcs(SFc35_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
  int32_T c35_i4;
  int32_T c35_i5;
  int32_T c35_i6;
  int32_T c35_i7;
  int32_T c35_i8;
  real_T *c35_baseoutm;
  real_T *c35_timer;
  real_T *c35_basem;
  real_T *c35_timem;
  real_T *c35_base;
  real_T *c35_baseout;
  real_T *c35_enable;
  real_T (*c35_NP)[2];
  real_T (*c35_Vel)[2];
  real_T (*c35_NewPos)[2];
  real_T (*c35_Velm)[2];
  real_T (*c35_SCtranslation)[2];
  c35_enable = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c35_baseout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c35_base = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c35_NP = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 3);
  c35_timem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c35_Vel = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c35_basem = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c35_NewPos = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 4);
  c35_timer = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c35_Velm = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 2);
  c35_baseoutm = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c35_SCtranslation = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 34U, chartInstance->c35_sfEvent);
  for (c35_i4 = 0; c35_i4 < 2; c35_i4++) {
    _SFD_DATA_RANGE_CHECK((*c35_SCtranslation)[c35_i4], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c35_baseoutm, 1U);
  for (c35_i5 = 0; c35_i5 < 2; c35_i5++) {
    _SFD_DATA_RANGE_CHECK((*c35_Velm)[c35_i5], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*c35_timer, 3U);
  for (c35_i6 = 0; c35_i6 < 2; c35_i6++) {
    _SFD_DATA_RANGE_CHECK((*c35_NewPos)[c35_i6], 4U);
  }

  _SFD_DATA_RANGE_CHECK(*c35_basem, 5U);
  for (c35_i7 = 0; c35_i7 < 2; c35_i7++) {
    _SFD_DATA_RANGE_CHECK((*c35_Vel)[c35_i7], 6U);
  }

  _SFD_DATA_RANGE_CHECK(*c35_timem, 7U);
  for (c35_i8 = 0; c35_i8 < 2; c35_i8++) {
    _SFD_DATA_RANGE_CHECK((*c35_NP)[c35_i8], 8U);
  }

  _SFD_DATA_RANGE_CHECK(*c35_base, 9U);
  _SFD_DATA_RANGE_CHECK(*c35_baseout, 10U);
  _SFD_DATA_RANGE_CHECK(*c35_enable, 11U);
  chartInstance->c35_sfEvent = CALL_EVENT;
  c35_chartstep_c35_CusakisME4901arcs(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_CusakisME4901arcsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c35_chartstep_c35_CusakisME4901arcs
  (SFc35_CusakisME4901arcsInstanceStruct *chartInstance)
{
  real_T c35_hoistedGlobal;
  real_T c35_b_hoistedGlobal;
  real_T c35_c_hoistedGlobal;
  int32_T c35_i9;
  real_T c35_SCtranslation[2];
  real_T c35_baseoutm;
  int32_T c35_i10;
  real_T c35_Velm[2];
  real_T c35_timer;
  int32_T c35_i11;
  real_T c35_NewPos[2];
  real_T c35_basem;
  uint32_T c35_debug_family_var_map[23];
  real_T c35_R;
  real_T c35_Sl;
  real_T c35_Sr;
  real_T c35_r;
  real_T c35_Rotation[4];
  real_T c35_Xf[2];
  real_T c35_Xi[2];
  real_T c35_D;
  real_T c35_alpha;
  real_T c35_nargin = 6.0;
  real_T c35_nargout = 6.0;
  real_T c35_Vel[2];
  real_T c35_timem;
  real_T c35_NP[2];
  real_T c35_base;
  real_T c35_baseout;
  real_T c35_enable;
  real_T c35_x;
  real_T c35_b_x;
  real_T c35_c_x;
  real_T c35_d_x;
  real_T c35_e_x;
  real_T c35_f_x;
  real_T c35_g_x;
  real_T c35_h_x;
  int32_T c35_i12;
  real_T c35_a[4];
  real_T c35_b[2];
  int32_T c35_i13;
  int32_T c35_i14;
  int32_T c35_i15;
  real_T c35_C[2];
  int32_T c35_i16;
  int32_T c35_i17;
  int32_T c35_i18;
  int32_T c35_i19;
  int32_T c35_i20;
  int32_T c35_i21;
  int32_T c35_i22;
  int32_T c35_i23;
  int32_T c35_i24;
  int32_T c35_i25;
  int32_T c35_i26;
  int32_T c35_i27;
  int32_T c35_i28;
  int32_T c35_i29;
  int32_T c35_i30;
  int32_T c35_i31;
  int32_T c35_i32;
  real_T c35_A;
  real_T c35_B;
  real_T c35_i_x;
  real_T c35_y;
  real_T c35_j_x;
  real_T c35_b_y;
  real_T c35_c_y;
  real_T c35_b_A;
  real_T c35_k_x;
  real_T c35_l_x;
  real_T c35_d_y;
  real_T c35_b_b;
  real_T c35_e_y;
  real_T c35_c_A;
  real_T c35_m_x;
  real_T c35_n_x;
  real_T c35_f_y;
  real_T c35_o_x;
  real_T c35_p_x;
  real_T c35_b_B;
  real_T c35_g_y;
  real_T c35_h_y;
  real_T c35_i_y;
  real_T c35_b_a;
  real_T c35_c_b;
  real_T c35_d_b;
  real_T c35_j_y;
  real_T c35_c_a;
  real_T c35_e_b;
  real_T c35_f_b;
  real_T c35_k_y;
  real_T c35_d_a;
  real_T c35_g_b;
  real_T c35_d_A;
  real_T c35_q_x;
  real_T c35_r_x;
  real_T c35_l_y;
  real_T c35_h_b;
  real_T c35_m_y;
  real_T c35_e_A;
  real_T c35_s_x;
  real_T c35_t_x;
  real_T c35_n_y;
  real_T c35_u_x;
  real_T c35_v_x;
  real_T c35_c_B;
  real_T c35_o_y;
  real_T c35_p_y;
  real_T c35_q_y;
  real_T c35_e_a;
  real_T c35_i_b;
  real_T c35_j_b;
  real_T c35_r_y;
  real_T c35_f_a;
  real_T c35_k_b;
  real_T c35_l_b;
  real_T c35_s_y;
  real_T c35_g_a;
  real_T c35_m_b;
  real_T c35_f_A;
  real_T c35_w_x;
  real_T c35_x_x;
  real_T c35_t_y;
  real_T c35_n_b;
  real_T c35_u_y;
  real_T c35_g_A;
  real_T c35_y_x;
  real_T c35_ab_x;
  real_T c35_v_y;
  real_T c35_bb_x;
  real_T c35_cb_x;
  real_T c35_d_B;
  real_T c35_w_y;
  real_T c35_x_y;
  real_T c35_y_y;
  real_T c35_h_a;
  real_T c35_o_b;
  real_T c35_p_b;
  real_T c35_ab_y;
  real_T c35_i_a;
  real_T c35_q_b;
  real_T c35_r_b;
  real_T c35_bb_y;
  real_T c35_j_a;
  real_T c35_s_b;
  real_T c35_h_A;
  real_T c35_db_x;
  real_T c35_eb_x;
  real_T c35_cb_y;
  real_T c35_t_b;
  real_T c35_db_y;
  real_T c35_i_A;
  real_T c35_fb_x;
  real_T c35_gb_x;
  real_T c35_eb_y;
  real_T c35_hb_x;
  real_T c35_ib_x;
  real_T c35_e_B;
  real_T c35_fb_y;
  real_T c35_gb_y;
  real_T c35_hb_y;
  real_T c35_k_a;
  real_T c35_u_b;
  real_T c35_v_b;
  real_T c35_ib_y;
  real_T c35_l_a;
  real_T c35_w_b;
  real_T c35_x_b;
  real_T c35_jb_y;
  real_T c35_m_a;
  real_T c35_y_b;
  real_T c35_ab_b;
  real_T c35_kb_y;
  real_T c35_n_a;
  real_T c35_lb_y;
  real_T c35_j_A;
  real_T c35_jb_x;
  real_T c35_kb_x;
  real_T c35_mb_y;
  real_T c35_o_a;
  real_T c35_nb_y;
  real_T c35_k_A;
  real_T c35_lb_x;
  real_T c35_mb_x;
  real_T c35_ob_y;
  int32_T c35_i33;
  int32_T c35_i34;
  real_T c35_p_a;
  real_T c35_q_a;
  real_T c35_r_a;
  real_T c35_pb_y;
  real_T c35_l_A;
  real_T c35_nb_x;
  real_T c35_ob_x;
  real_T c35_qb_y;
  real_T c35_s_a;
  real_T c35_rb_y;
  real_T c35_m_A;
  real_T c35_pb_x;
  real_T c35_qb_x;
  real_T c35_sb_y;
  int32_T c35_i35;
  real_T c35_n_A;
  real_T c35_rb_x;
  real_T c35_sb_x;
  real_T c35_tb_y;
  int32_T c35_i36;
  int32_T c35_i37;
  int32_T c35_i38;
  int32_T c35_i39;
  real_T *c35_b_baseoutm;
  real_T *c35_b_timer;
  real_T *c35_b_basem;
  real_T *c35_b_timem;
  real_T *c35_b_base;
  real_T *c35_b_baseout;
  real_T *c35_b_enable;
  real_T (*c35_b_Vel)[2];
  real_T (*c35_b_NP)[2];
  real_T (*c35_b_NewPos)[2];
  real_T (*c35_b_Velm)[2];
  real_T (*c35_b_SCtranslation)[2];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  boolean_T guard5 = FALSE;
  boolean_T guard6 = FALSE;
  c35_b_enable = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c35_b_baseout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c35_b_base = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c35_b_NP = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 3);
  c35_b_timem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c35_b_Vel = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c35_b_basem = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c35_b_NewPos = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 4);
  c35_b_timer = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c35_b_Velm = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 2);
  c35_b_baseoutm = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c35_b_SCtranslation = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 34U, chartInstance->c35_sfEvent);
  c35_hoistedGlobal = *c35_b_baseoutm;
  c35_b_hoistedGlobal = *c35_b_timer;
  c35_c_hoistedGlobal = *c35_b_basem;
  for (c35_i9 = 0; c35_i9 < 2; c35_i9++) {
    c35_SCtranslation[c35_i9] = (*c35_b_SCtranslation)[c35_i9];
  }

  c35_baseoutm = c35_hoistedGlobal;
  for (c35_i10 = 0; c35_i10 < 2; c35_i10++) {
    c35_Velm[c35_i10] = (*c35_b_Velm)[c35_i10];
  }

  c35_timer = c35_b_hoistedGlobal;
  for (c35_i11 = 0; c35_i11 < 2; c35_i11++) {
    c35_NewPos[c35_i11] = (*c35_b_NewPos)[c35_i11];
  }

  c35_basem = c35_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 23U, 23U, c35_debug_family_names,
    c35_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_R, 0U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_Sl, 1U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_Sr, 2U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c35_r, 3U, c35_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c35_Rotation, 4U, c35_c_sf_marshallOut,
    c35_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c35_Xf, 5U, c35_b_sf_marshallOut,
    c35_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c35_Xi, 6U, c35_b_sf_marshallOut,
    c35_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_D, 7U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_alpha, 8U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_nargin, 9U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_nargout, 10U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c35_SCtranslation, 11U, c35_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c35_baseoutm, 12U, c35_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c35_Velm, 13U, c35_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c35_timer, 14U, c35_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c35_NewPos, 15U, c35_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c35_basem, 16U, c35_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c35_Vel, 17U, c35_b_sf_marshallOut,
    c35_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_timem, 18U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c35_NP, 19U, c35_b_sf_marshallOut,
    c35_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_base, 20U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_baseout, 21U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c35_enable, 22U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 12);
  c35_R = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 13);
  c35_Sl = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 14);
  c35_Sr = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 15);
  c35_r = 0.13;
  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 16);
  if (CV_EML_IF(0, 1, 0, c35_timer == 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 19);
    c35_x = c35_basem;
    c35_b_x = c35_x;
    c35_b_x = muDoubleScalarCos(c35_b_x);
    c35_c_x = c35_basem;
    c35_d_x = c35_c_x;
    c35_d_x = muDoubleScalarSin(c35_d_x);
    c35_e_x = c35_basem;
    c35_f_x = c35_e_x;
    c35_f_x = muDoubleScalarSin(c35_f_x);
    c35_g_x = c35_basem;
    c35_h_x = c35_g_x;
    c35_h_x = muDoubleScalarCos(c35_h_x);
    c35_Rotation[0] = c35_b_x;
    c35_Rotation[2] = -c35_d_x;
    c35_Rotation[1] = c35_f_x;
    c35_Rotation[3] = c35_h_x;
    _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 21);
    for (c35_i12 = 0; c35_i12 < 4; c35_i12++) {
      c35_a[c35_i12] = c35_Rotation[c35_i12];
    }

    c35_b[0] = c35_SCtranslation[0];
    c35_b[1] = c35_SCtranslation[1];
    c35_eml_scalar_eg(chartInstance);
    c35_eml_scalar_eg(chartInstance);
    for (c35_i13 = 0; c35_i13 < 2; c35_i13++) {
      c35_Xf[c35_i13] = 0.0;
    }

    for (c35_i14 = 0; c35_i14 < 2; c35_i14++) {
      c35_Xf[c35_i14] = 0.0;
    }

    for (c35_i15 = 0; c35_i15 < 2; c35_i15++) {
      c35_C[c35_i15] = c35_Xf[c35_i15];
    }

    for (c35_i16 = 0; c35_i16 < 2; c35_i16++) {
      c35_Xf[c35_i16] = c35_C[c35_i16];
    }

    for (c35_i17 = 0; c35_i17 < 2; c35_i17++) {
      c35_C[c35_i17] = c35_Xf[c35_i17];
    }

    for (c35_i18 = 0; c35_i18 < 2; c35_i18++) {
      c35_Xf[c35_i18] = c35_C[c35_i18];
    }

    for (c35_i19 = 0; c35_i19 < 2; c35_i19++) {
      c35_Xf[c35_i19] = 0.0;
      c35_i20 = 0;
      for (c35_i21 = 0; c35_i21 < 2; c35_i21++) {
        c35_Xf[c35_i19] += c35_a[c35_i20 + c35_i19] * c35_b[c35_i21];
        c35_i20 += 2;
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 22);
    for (c35_i22 = 0; c35_i22 < 4; c35_i22++) {
      c35_a[c35_i22] = c35_Rotation[c35_i22];
    }

    for (c35_i23 = 0; c35_i23 < 2; c35_i23++) {
      c35_b[c35_i23] = c35_NewPos[c35_i23];
    }

    c35_eml_scalar_eg(chartInstance);
    c35_eml_scalar_eg(chartInstance);
    for (c35_i24 = 0; c35_i24 < 2; c35_i24++) {
      c35_Xi[c35_i24] = 0.0;
    }

    for (c35_i25 = 0; c35_i25 < 2; c35_i25++) {
      c35_Xi[c35_i25] = 0.0;
    }

    for (c35_i26 = 0; c35_i26 < 2; c35_i26++) {
      c35_C[c35_i26] = c35_Xi[c35_i26];
    }

    for (c35_i27 = 0; c35_i27 < 2; c35_i27++) {
      c35_Xi[c35_i27] = c35_C[c35_i27];
    }

    for (c35_i28 = 0; c35_i28 < 2; c35_i28++) {
      c35_C[c35_i28] = c35_Xi[c35_i28];
    }

    for (c35_i29 = 0; c35_i29 < 2; c35_i29++) {
      c35_Xi[c35_i29] = c35_C[c35_i29];
    }

    for (c35_i30 = 0; c35_i30 < 2; c35_i30++) {
      c35_Xi[c35_i30] = 0.0;
      c35_i31 = 0;
      for (c35_i32 = 0; c35_i32 < 2; c35_i32++) {
        c35_Xi[c35_i30] += c35_a[c35_i31 + c35_i30] * c35_b[c35_i32];
        c35_i31 += 2;
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 24);
    c35_D = c35_mpower(chartInstance, c35_Xf[0] - c35_Xi[0]) + c35_mpower
      (chartInstance, c35_Xf[1] - c35_Xi[1]);
    c35_b_sqrt(chartInstance, &c35_D);
    _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 25);
    if (CV_EML_IF(0, 1, 1, c35_abs(chartInstance, c35_Xf[1] - c35_Xi[1]) > 0.0))
    {
      _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 26);
      c35_A = c35_Xf[1] - c35_Xi[1];
      c35_B = c35_D;
      c35_i_x = c35_A;
      c35_y = c35_B;
      c35_j_x = c35_i_x;
      c35_b_y = c35_y;
      c35_c_y = c35_j_x / c35_b_y;
      c35_alpha = c35_c_y;
      c35_b_asin(chartInstance, &c35_alpha);
    } else {
      _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 28);
      c35_alpha = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 30);
    guard3 = FALSE;
    if (CV_EML_COND(0, 1, 0, c35_Xf[0] > c35_Xi[0])) {
      if (CV_EML_COND(0, 1, 1, c35_Xf[1] > c35_Xi[1])) {
        CV_EML_MCDC(0, 1, 0, TRUE);
        CV_EML_IF(0, 1, 2, TRUE);
        _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 31);
        c35_b_A = c35_D;
        c35_k_x = c35_b_A;
        c35_l_x = c35_k_x;
        c35_d_y = c35_l_x / 2.0;
        c35_b_b = c35_alpha;
        c35_e_y = 2.0 * c35_b_b;
        c35_c_A = 3.1415926535897931 - c35_e_y;
        c35_m_x = c35_c_A;
        c35_n_x = c35_m_x;
        c35_f_y = c35_n_x / 2.0;
        c35_o_x = c35_f_y;
        c35_p_x = c35_o_x;
        c35_p_x = muDoubleScalarSin(c35_p_x);
        c35_b_B = c35_p_x;
        c35_g_y = c35_b_B;
        c35_h_y = c35_g_y;
        c35_i_y = 1.0 / c35_h_y;
        c35_b_a = c35_d_y;
        c35_c_b = c35_i_y;
        c35_R = c35_b_a * c35_c_b;
        _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 32);
        c35_d_b = c35_alpha;
        c35_j_y = 2.0 * c35_d_b;
        c35_c_a = 3.1415926535897931 - c35_j_y;
        c35_e_b = c35_R + c35_r;
        c35_Sl = c35_c_a * c35_e_b;
        _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 33);
        c35_f_b = c35_alpha;
        c35_k_y = 2.0 * c35_f_b;
        c35_d_a = 3.1415926535897931 - c35_k_y;
        c35_g_b = c35_R - c35_r;
        c35_Sr = c35_d_a * c35_g_b;
      } else {
        guard3 = TRUE;
      }
    } else {
      guard3 = TRUE;
    }

    if (guard3 == TRUE) {
      CV_EML_MCDC(0, 1, 0, FALSE);
      CV_EML_IF(0, 1, 2, FALSE);
      _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 34);
      guard4 = FALSE;
      if (CV_EML_COND(0, 1, 2, c35_Xf[0] < c35_Xi[0])) {
        if (CV_EML_COND(0, 1, 3, c35_Xf[1] > c35_Xi[1])) {
          CV_EML_MCDC(0, 1, 1, TRUE);
          CV_EML_IF(0, 1, 3, TRUE);
          _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 35);
          c35_d_A = c35_D;
          c35_q_x = c35_d_A;
          c35_r_x = c35_q_x;
          c35_l_y = c35_r_x / 2.0;
          c35_h_b = c35_alpha;
          c35_m_y = 2.0 * c35_h_b;
          c35_e_A = 3.1415926535897931 - c35_m_y;
          c35_s_x = c35_e_A;
          c35_t_x = c35_s_x;
          c35_n_y = c35_t_x / 2.0;
          c35_u_x = c35_n_y;
          c35_v_x = c35_u_x;
          c35_v_x = muDoubleScalarSin(c35_v_x);
          c35_c_B = c35_v_x;
          c35_o_y = c35_c_B;
          c35_p_y = c35_o_y;
          c35_q_y = 1.0 / c35_p_y;
          c35_e_a = c35_l_y;
          c35_i_b = c35_q_y;
          c35_R = c35_e_a * c35_i_b;
          _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 36);
          c35_j_b = c35_alpha;
          c35_r_y = 2.0 * c35_j_b;
          c35_f_a = 3.1415926535897931 - c35_r_y;
          c35_k_b = c35_R - c35_r;
          c35_Sl = c35_f_a * c35_k_b;
          _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 37);
          c35_l_b = c35_alpha;
          c35_s_y = 2.0 * c35_l_b;
          c35_g_a = 3.1415926535897931 - c35_s_y;
          c35_m_b = c35_R + c35_r;
          c35_Sr = c35_g_a * c35_m_b;
        } else {
          guard4 = TRUE;
        }
      } else {
        guard4 = TRUE;
      }

      if (guard4 == TRUE) {
        CV_EML_MCDC(0, 1, 1, FALSE);
        CV_EML_IF(0, 1, 3, FALSE);
        _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 38);
        guard5 = FALSE;
        if (CV_EML_COND(0, 1, 4, c35_Xf[0] < c35_Xi[0])) {
          if (CV_EML_COND(0, 1, 5, c35_Xf[1] < c35_Xi[1])) {
            CV_EML_MCDC(0, 1, 2, TRUE);
            CV_EML_IF(0, 1, 4, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 39);
            c35_f_A = c35_D;
            c35_w_x = c35_f_A;
            c35_x_x = c35_w_x;
            c35_t_y = c35_x_x / 2.0;
            c35_n_b = c35_alpha;
            c35_u_y = 2.0 * c35_n_b;
            c35_g_A = 3.1415926535897931 + c35_u_y;
            c35_y_x = c35_g_A;
            c35_ab_x = c35_y_x;
            c35_v_y = c35_ab_x / 2.0;
            c35_bb_x = c35_v_y;
            c35_cb_x = c35_bb_x;
            c35_cb_x = muDoubleScalarSin(c35_cb_x);
            c35_d_B = c35_cb_x;
            c35_w_y = c35_d_B;
            c35_x_y = c35_w_y;
            c35_y_y = 1.0 / c35_x_y;
            c35_h_a = c35_t_y;
            c35_o_b = c35_y_y;
            c35_R = c35_h_a * c35_o_b;
            _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 40);
            c35_p_b = c35_alpha;
            c35_ab_y = 2.0 * c35_p_b;
            c35_i_a = -(3.1415926535897931 + c35_ab_y);
            c35_q_b = c35_R - c35_r;
            c35_Sl = c35_i_a * c35_q_b;
            _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 41);
            c35_r_b = c35_alpha;
            c35_bb_y = 2.0 * c35_r_b;
            c35_j_a = -(3.1415926535897931 + c35_bb_y);
            c35_s_b = c35_R + c35_r;
            c35_Sr = c35_j_a * c35_s_b;
          } else {
            guard5 = TRUE;
          }
        } else {
          guard5 = TRUE;
        }

        if (guard5 == TRUE) {
          CV_EML_MCDC(0, 1, 2, FALSE);
          CV_EML_IF(0, 1, 4, FALSE);
          _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 42);
          guard6 = FALSE;
          if (CV_EML_COND(0, 1, 6, c35_Xf[0] > c35_Xi[0])) {
            if (CV_EML_COND(0, 1, 7, c35_Xf[1] < c35_Xi[1])) {
              CV_EML_MCDC(0, 1, 3, TRUE);
              CV_EML_IF(0, 1, 5, TRUE);
              _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 43);
              c35_h_A = c35_D;
              c35_db_x = c35_h_A;
              c35_eb_x = c35_db_x;
              c35_cb_y = c35_eb_x / 2.0;
              c35_t_b = c35_alpha;
              c35_db_y = 2.0 * c35_t_b;
              c35_i_A = 3.1415926535897931 + c35_db_y;
              c35_fb_x = c35_i_A;
              c35_gb_x = c35_fb_x;
              c35_eb_y = c35_gb_x / 2.0;
              c35_hb_x = c35_eb_y;
              c35_ib_x = c35_hb_x;
              c35_ib_x = muDoubleScalarSin(c35_ib_x);
              c35_e_B = c35_ib_x;
              c35_fb_y = c35_e_B;
              c35_gb_y = c35_fb_y;
              c35_hb_y = 1.0 / c35_gb_y;
              c35_k_a = c35_cb_y;
              c35_u_b = c35_hb_y;
              c35_R = c35_k_a * c35_u_b;
              _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 44);
              c35_v_b = c35_alpha;
              c35_ib_y = 2.0 * c35_v_b;
              c35_l_a = -(3.1415926535897931 + c35_ib_y);
              c35_w_b = c35_R + c35_r;
              c35_Sl = c35_l_a * c35_w_b;
              _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 45);
              c35_x_b = c35_alpha;
              c35_jb_y = 2.0 * c35_x_b;
              c35_m_a = -(3.1415926535897931 + c35_jb_y);
              c35_y_b = c35_R - c35_r;
              c35_Sr = c35_m_a * c35_y_b;
            } else {
              guard6 = TRUE;
            }
          } else {
            guard6 = TRUE;
          }

          if (guard6 == TRUE) {
            CV_EML_MCDC(0, 1, 3, FALSE);
            CV_EML_IF(0, 1, 5, FALSE);
          }
        }
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 47);
    c35_ab_b = c35_alpha;
    c35_kb_y = 2.0 * c35_ab_b;
    c35_base = c35_kb_y + c35_basem;
    _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 48);
    c35_baseout = c35_base;
    _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 49);
    c35_NP[0] = c35_SCtranslation[0];
    c35_NP[1] = c35_SCtranslation[1];
    _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 51);
    c35_n_a = c35_Sr;
    c35_lb_y = c35_n_a * 1000.0;
    c35_j_A = c35_lb_y;
    c35_jb_x = c35_j_A;
    c35_kb_x = c35_jb_x;
    c35_mb_y = c35_kb_x / 2.0;
    c35_o_a = c35_Sl;
    c35_nb_y = c35_o_a * 1000.0;
    c35_k_A = c35_nb_y;
    c35_lb_x = c35_k_A;
    c35_mb_x = c35_lb_x;
    c35_ob_y = c35_mb_x / 2.0;
    c35_Vel[0] = c35_mb_y;
    c35_Vel[1] = c35_ob_y;
    _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 52);
    c35_timem = c35_timer + 0.01;
    _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 53);
    c35_enable = 1.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 54);
    guard1 = FALSE;
    if (CV_EML_COND(0, 1, 8, c35_timer >= 0.01)) {
      if (CV_EML_COND(0, 1, 9, c35_timer <= 2.0)) {
        CV_EML_MCDC(0, 1, 4, TRUE);
        CV_EML_IF(0, 1, 6, TRUE);
        _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 55);
        for (c35_i33 = 0; c35_i33 < 2; c35_i33++) {
          c35_Vel[c35_i33] = c35_Velm[c35_i33];
        }

        _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 56);
        for (c35_i34 = 0; c35_i34 < 2; c35_i34++) {
          c35_NP[c35_i34] = c35_NewPos[c35_i34];
        }

        _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 57);
        c35_base = c35_basem;
        _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 58);
        c35_baseout = c35_base;
        _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 59);
        c35_timem = c35_timer + 0.01;
        _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 60);
        c35_enable = 0.0;
      } else {
        guard1 = TRUE;
      }
    } else {
      guard1 = TRUE;
    }

    if (guard1 == TRUE) {
      CV_EML_MCDC(0, 1, 4, FALSE);
      CV_EML_IF(0, 1, 6, FALSE);
      _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 61);
      guard2 = FALSE;
      if (CV_EML_COND(0, 1, 10, c35_timer > 2.0)) {
        if (CV_EML_COND(0, 1, 11, c35_timer <= 3.0)) {
          CV_EML_MCDC(0, 1, 5, TRUE);
          CV_EML_IF(0, 1, 7, TRUE);
          _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 62);
          c35_p_a = -c35_basem;
          c35_Sl = c35_p_a * 0.13;
          _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 63);
          c35_q_a = c35_basem;
          c35_Sr = c35_q_a * 0.13;
          _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 64);
          c35_r_a = c35_Sr;
          c35_pb_y = c35_r_a * 1000.0;
          c35_l_A = c35_pb_y;
          c35_nb_x = c35_l_A;
          c35_ob_x = c35_nb_x;
          c35_qb_y = c35_ob_x;
          c35_s_a = c35_Sl;
          c35_rb_y = c35_s_a * 1000.0;
          c35_m_A = c35_rb_y;
          c35_pb_x = c35_m_A;
          c35_qb_x = c35_pb_x;
          c35_sb_y = c35_qb_x;
          c35_Vel[0] = c35_qb_y;
          c35_Vel[1] = c35_sb_y;
          _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 65);
          for (c35_i35 = 0; c35_i35 < 2; c35_i35++) {
            c35_NP[c35_i35] = c35_NewPos[c35_i35];
          }

          _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 66);
          c35_base = c35_basem;
          _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 67);
          c35_n_A = c35_base;
          c35_rb_x = c35_n_A;
          c35_sb_x = c35_rb_x;
          c35_tb_y = c35_sb_x / 100.0;
          c35_baseout = c35_baseoutm - c35_tb_y;
          _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 68);
          c35_timem = c35_timer + 0.01;
          _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 69);
          c35_enable = 0.0;
        } else {
          guard2 = TRUE;
        }
      } else {
        guard2 = TRUE;
      }

      if (guard2 == TRUE) {
        CV_EML_MCDC(0, 1, 5, FALSE);
        CV_EML_IF(0, 1, 7, FALSE);
        _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 71);
        for (c35_i36 = 0; c35_i36 < 2; c35_i36++) {
          c35_Vel[c35_i36] = 0.0;
        }

        _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 72);
        for (c35_i37 = 0; c35_i37 < 2; c35_i37++) {
          c35_NP[c35_i37] = c35_NewPos[c35_i37];
        }

        _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 73);
        c35_base = 0.0;
        _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 74);
        c35_baseout = c35_base;
        _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 75);
        c35_timem = 0.0;
        _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, 76);
        c35_enable = 0.0;
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c35_sfEvent, -76);
  _SFD_SYMBOL_SCOPE_POP();
  for (c35_i38 = 0; c35_i38 < 2; c35_i38++) {
    (*c35_b_Vel)[c35_i38] = c35_Vel[c35_i38];
  }

  *c35_b_timem = c35_timem;
  for (c35_i39 = 0; c35_i39 < 2; c35_i39++) {
    (*c35_b_NP)[c35_i39] = c35_NP[c35_i39];
  }

  *c35_b_base = c35_base;
  *c35_b_baseout = c35_baseout;
  *c35_b_enable = c35_enable;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 34U, chartInstance->c35_sfEvent);
}

static void initSimStructsc35_CusakisME4901arcs
  (SFc35_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static void registerMessagesc35_CusakisME4901arcs
  (SFc35_CusakisME4901arcsInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c35_machineNumber, uint32_T
  c35_chartNumber)
{
}

static const mxArray *c35_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  real_T c35_u;
  const mxArray *c35_y = NULL;
  SFc35_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc35_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  c35_u = *(real_T *)c35_inData;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", &c35_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, FALSE);
  return c35_mxArrayOutData;
}

static real_T c35_emlrt_marshallIn(SFc35_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c35_enable, const char_T *c35_identifier)
{
  real_T c35_y;
  emlrtMsgIdentifier c35_thisId;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_enable),
    &c35_thisId);
  sf_mex_destroy(&c35_enable);
  return c35_y;
}

static real_T c35_b_emlrt_marshallIn(SFc35_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  real_T c35_y;
  real_T c35_d0;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), &c35_d0, 1, 0, 0U, 0, 0U, 0);
  c35_y = c35_d0;
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void c35_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_enable;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  real_T c35_y;
  SFc35_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc35_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c35_enable = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_enable),
    &c35_thisId);
  sf_mex_destroy(&c35_enable);
  *(real_T *)c35_outData = c35_y;
  sf_mex_destroy(&c35_mxArrayInData);
}

static const mxArray *c35_b_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_i40;
  real_T c35_b_inData[2];
  int32_T c35_i41;
  real_T c35_u[2];
  const mxArray *c35_y = NULL;
  SFc35_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc35_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  for (c35_i40 = 0; c35_i40 < 2; c35_i40++) {
    c35_b_inData[c35_i40] = (*(real_T (*)[2])c35_inData)[c35_i40];
  }

  for (c35_i41 = 0; c35_i41 < 2; c35_i41++) {
    c35_u[c35_i41] = c35_b_inData[c35_i41];
  }

  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, FALSE);
  return c35_mxArrayOutData;
}

static void c35_c_emlrt_marshallIn(SFc35_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c35_NP, const char_T *c35_identifier, real_T
  c35_y[2])
{
  emlrtMsgIdentifier c35_thisId;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_NP), &c35_thisId, c35_y);
  sf_mex_destroy(&c35_NP);
}

static void c35_d_emlrt_marshallIn(SFc35_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[2])
{
  real_T c35_dv2[2];
  int32_T c35_i42;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), c35_dv2, 1, 0, 0U, 1, 0U, 1, 2);
  for (c35_i42 = 0; c35_i42 < 2; c35_i42++) {
    c35_y[c35_i42] = c35_dv2[c35_i42];
  }

  sf_mex_destroy(&c35_u);
}

static void c35_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_NP;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  real_T c35_y[2];
  int32_T c35_i43;
  SFc35_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc35_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c35_NP = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_NP), &c35_thisId, c35_y);
  sf_mex_destroy(&c35_NP);
  for (c35_i43 = 0; c35_i43 < 2; c35_i43++) {
    (*(real_T (*)[2])c35_outData)[c35_i43] = c35_y[c35_i43];
  }

  sf_mex_destroy(&c35_mxArrayInData);
}

static const mxArray *c35_c_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_i44;
  int32_T c35_i45;
  int32_T c35_i46;
  real_T c35_b_inData[4];
  int32_T c35_i47;
  int32_T c35_i48;
  int32_T c35_i49;
  real_T c35_u[4];
  const mxArray *c35_y = NULL;
  SFc35_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc35_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  c35_i44 = 0;
  for (c35_i45 = 0; c35_i45 < 2; c35_i45++) {
    for (c35_i46 = 0; c35_i46 < 2; c35_i46++) {
      c35_b_inData[c35_i46 + c35_i44] = (*(real_T (*)[4])c35_inData)[c35_i46 +
        c35_i44];
    }

    c35_i44 += 2;
  }

  c35_i47 = 0;
  for (c35_i48 = 0; c35_i48 < 2; c35_i48++) {
    for (c35_i49 = 0; c35_i49 < 2; c35_i49++) {
      c35_u[c35_i49 + c35_i47] = c35_b_inData[c35_i49 + c35_i47];
    }

    c35_i47 += 2;
  }

  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, FALSE);
  return c35_mxArrayOutData;
}

static void c35_e_emlrt_marshallIn(SFc35_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId,
  real_T c35_y[4])
{
  real_T c35_dv3[4];
  int32_T c35_i50;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), c35_dv3, 1, 0, 0U, 1, 0U, 2, 2,
                2);
  for (c35_i50 = 0; c35_i50 < 4; c35_i50++) {
    c35_y[c35_i50] = c35_dv3[c35_i50];
  }

  sf_mex_destroy(&c35_u);
}

static void c35_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_Rotation;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  real_T c35_y[4];
  int32_T c35_i51;
  int32_T c35_i52;
  int32_T c35_i53;
  SFc35_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc35_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c35_Rotation = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_Rotation), &c35_thisId,
    c35_y);
  sf_mex_destroy(&c35_Rotation);
  c35_i51 = 0;
  for (c35_i52 = 0; c35_i52 < 2; c35_i52++) {
    for (c35_i53 = 0; c35_i53 < 2; c35_i53++) {
      (*(real_T (*)[4])c35_outData)[c35_i53 + c35_i51] = c35_y[c35_i53 + c35_i51];
    }

    c35_i51 += 2;
  }

  sf_mex_destroy(&c35_mxArrayInData);
}

const mxArray *sf_c35_CusakisME4901arcs_get_eml_resolved_functions_info(void)
{
  const mxArray *c35_nameCaptureInfo;
  c35_ResolvedFunctionInfo c35_info[33];
  const mxArray *c35_m0 = NULL;
  int32_T c35_i54;
  c35_ResolvedFunctionInfo *c35_r0;
  c35_nameCaptureInfo = NULL;
  c35_nameCaptureInfo = NULL;
  c35_info_helper(c35_info);
  sf_mex_assign(&c35_m0, sf_mex_createstruct("nameCaptureInfo", 1, 33), FALSE);
  for (c35_i54 = 0; c35_i54 < 33; c35_i54++) {
    c35_r0 = &c35_info[c35_i54];
    sf_mex_addfield(c35_m0, sf_mex_create("nameCaptureInfo", c35_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c35_r0->context)), "context", "nameCaptureInfo",
                    c35_i54);
    sf_mex_addfield(c35_m0, sf_mex_create("nameCaptureInfo", c35_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c35_r0->name)), "name", "nameCaptureInfo",
                    c35_i54);
    sf_mex_addfield(c35_m0, sf_mex_create("nameCaptureInfo",
      c35_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c35_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c35_i54);
    sf_mex_addfield(c35_m0, sf_mex_create("nameCaptureInfo", c35_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c35_r0->resolved)), "resolved",
                    "nameCaptureInfo", c35_i54);
    sf_mex_addfield(c35_m0, sf_mex_create("nameCaptureInfo", &c35_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c35_i54);
    sf_mex_addfield(c35_m0, sf_mex_create("nameCaptureInfo", &c35_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c35_i54);
    sf_mex_addfield(c35_m0, sf_mex_create("nameCaptureInfo",
      &c35_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c35_i54);
    sf_mex_addfield(c35_m0, sf_mex_create("nameCaptureInfo",
      &c35_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c35_i54);
  }

  sf_mex_assign(&c35_nameCaptureInfo, c35_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c35_nameCaptureInfo);
  return c35_nameCaptureInfo;
}

static void c35_info_helper(c35_ResolvedFunctionInfo c35_info[33])
{
  c35_info[0].context = "";
  c35_info[0].name = "cos";
  c35_info[0].dominantType = "double";
  c35_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c35_info[0].fileTimeLo = 1343862772U;
  c35_info[0].fileTimeHi = 0U;
  c35_info[0].mFileTimeLo = 0U;
  c35_info[0].mFileTimeHi = 0U;
  c35_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c35_info[1].name = "eml_scalar_cos";
  c35_info[1].dominantType = "double";
  c35_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c35_info[1].fileTimeLo = 1286851122U;
  c35_info[1].fileTimeHi = 0U;
  c35_info[1].mFileTimeLo = 0U;
  c35_info[1].mFileTimeHi = 0U;
  c35_info[2].context = "";
  c35_info[2].name = "sin";
  c35_info[2].dominantType = "double";
  c35_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c35_info[2].fileTimeLo = 1343862786U;
  c35_info[2].fileTimeHi = 0U;
  c35_info[2].mFileTimeLo = 0U;
  c35_info[2].mFileTimeHi = 0U;
  c35_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c35_info[3].name = "eml_scalar_sin";
  c35_info[3].dominantType = "double";
  c35_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c35_info[3].fileTimeLo = 1286851136U;
  c35_info[3].fileTimeHi = 0U;
  c35_info[3].mFileTimeLo = 0U;
  c35_info[3].mFileTimeHi = 0U;
  c35_info[4].context = "";
  c35_info[4].name = "mtimes";
  c35_info[4].dominantType = "double";
  c35_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c35_info[4].fileTimeLo = 1289552092U;
  c35_info[4].fileTimeHi = 0U;
  c35_info[4].mFileTimeLo = 0U;
  c35_info[4].mFileTimeHi = 0U;
  c35_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c35_info[5].name = "eml_index_class";
  c35_info[5].dominantType = "";
  c35_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c35_info[5].fileTimeLo = 1323202978U;
  c35_info[5].fileTimeHi = 0U;
  c35_info[5].mFileTimeLo = 0U;
  c35_info[5].mFileTimeHi = 0U;
  c35_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c35_info[6].name = "eml_scalar_eg";
  c35_info[6].dominantType = "double";
  c35_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c35_info[6].fileTimeLo = 1286851196U;
  c35_info[6].fileTimeHi = 0U;
  c35_info[6].mFileTimeLo = 0U;
  c35_info[6].mFileTimeHi = 0U;
  c35_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c35_info[7].name = "eml_xgemm";
  c35_info[7].dominantType = "char";
  c35_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c35_info[7].fileTimeLo = 1299109172U;
  c35_info[7].fileTimeHi = 0U;
  c35_info[7].mFileTimeLo = 0U;
  c35_info[7].mFileTimeHi = 0U;
  c35_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c35_info[8].name = "eml_blas_inline";
  c35_info[8].dominantType = "";
  c35_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c35_info[8].fileTimeLo = 1299109168U;
  c35_info[8].fileTimeHi = 0U;
  c35_info[8].mFileTimeLo = 0U;
  c35_info[8].mFileTimeHi = 0U;
  c35_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c35_info[9].name = "mtimes";
  c35_info[9].dominantType = "double";
  c35_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c35_info[9].fileTimeLo = 1289552092U;
  c35_info[9].fileTimeHi = 0U;
  c35_info[9].mFileTimeLo = 0U;
  c35_info[9].mFileTimeHi = 0U;
  c35_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c35_info[10].name = "eml_index_class";
  c35_info[10].dominantType = "";
  c35_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c35_info[10].fileTimeLo = 1323202978U;
  c35_info[10].fileTimeHi = 0U;
  c35_info[10].mFileTimeLo = 0U;
  c35_info[10].mFileTimeHi = 0U;
  c35_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c35_info[11].name = "eml_scalar_eg";
  c35_info[11].dominantType = "double";
  c35_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c35_info[11].fileTimeLo = 1286851196U;
  c35_info[11].fileTimeHi = 0U;
  c35_info[11].mFileTimeLo = 0U;
  c35_info[11].mFileTimeHi = 0U;
  c35_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c35_info[12].name = "eml_refblas_xgemm";
  c35_info[12].dominantType = "char";
  c35_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c35_info[12].fileTimeLo = 1299109174U;
  c35_info[12].fileTimeHi = 0U;
  c35_info[12].mFileTimeLo = 0U;
  c35_info[12].mFileTimeHi = 0U;
  c35_info[13].context = "";
  c35_info[13].name = "mpower";
  c35_info[13].dominantType = "double";
  c35_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c35_info[13].fileTimeLo = 1286851242U;
  c35_info[13].fileTimeHi = 0U;
  c35_info[13].mFileTimeLo = 0U;
  c35_info[13].mFileTimeHi = 0U;
  c35_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c35_info[14].name = "power";
  c35_info[14].dominantType = "double";
  c35_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c35_info[14].fileTimeLo = 1348224330U;
  c35_info[14].fileTimeHi = 0U;
  c35_info[14].mFileTimeLo = 0U;
  c35_info[14].mFileTimeHi = 0U;
  c35_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c35_info[15].name = "eml_scalar_eg";
  c35_info[15].dominantType = "double";
  c35_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c35_info[15].fileTimeLo = 1286851196U;
  c35_info[15].fileTimeHi = 0U;
  c35_info[15].mFileTimeLo = 0U;
  c35_info[15].mFileTimeHi = 0U;
  c35_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c35_info[16].name = "eml_scalexp_alloc";
  c35_info[16].dominantType = "double";
  c35_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c35_info[16].fileTimeLo = 1352457260U;
  c35_info[16].fileTimeHi = 0U;
  c35_info[16].mFileTimeLo = 0U;
  c35_info[16].mFileTimeHi = 0U;
  c35_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c35_info[17].name = "floor";
  c35_info[17].dominantType = "double";
  c35_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c35_info[17].fileTimeLo = 1343862780U;
  c35_info[17].fileTimeHi = 0U;
  c35_info[17].mFileTimeLo = 0U;
  c35_info[17].mFileTimeHi = 0U;
  c35_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c35_info[18].name = "eml_scalar_floor";
  c35_info[18].dominantType = "double";
  c35_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c35_info[18].fileTimeLo = 1286851126U;
  c35_info[18].fileTimeHi = 0U;
  c35_info[18].mFileTimeLo = 0U;
  c35_info[18].mFileTimeHi = 0U;
  c35_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c35_info[19].name = "eml_scalar_eg";
  c35_info[19].dominantType = "double";
  c35_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c35_info[19].fileTimeLo = 1286851196U;
  c35_info[19].fileTimeHi = 0U;
  c35_info[19].mFileTimeLo = 0U;
  c35_info[19].mFileTimeHi = 0U;
  c35_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  c35_info[20].name = "mtimes";
  c35_info[20].dominantType = "double";
  c35_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c35_info[20].fileTimeLo = 1289552092U;
  c35_info[20].fileTimeHi = 0U;
  c35_info[20].mFileTimeLo = 0U;
  c35_info[20].mFileTimeHi = 0U;
  c35_info[21].context = "";
  c35_info[21].name = "sqrt";
  c35_info[21].dominantType = "double";
  c35_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c35_info[21].fileTimeLo = 1343862786U;
  c35_info[21].fileTimeHi = 0U;
  c35_info[21].mFileTimeLo = 0U;
  c35_info[21].mFileTimeHi = 0U;
  c35_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c35_info[22].name = "eml_error";
  c35_info[22].dominantType = "char";
  c35_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c35_info[22].fileTimeLo = 1343862758U;
  c35_info[22].fileTimeHi = 0U;
  c35_info[22].mFileTimeLo = 0U;
  c35_info[22].mFileTimeHi = 0U;
  c35_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c35_info[23].name = "eml_scalar_sqrt";
  c35_info[23].dominantType = "double";
  c35_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c35_info[23].fileTimeLo = 1286851138U;
  c35_info[23].fileTimeHi = 0U;
  c35_info[23].mFileTimeLo = 0U;
  c35_info[23].mFileTimeHi = 0U;
  c35_info[24].context = "";
  c35_info[24].name = "abs";
  c35_info[24].dominantType = "double";
  c35_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c35_info[24].fileTimeLo = 1343862766U;
  c35_info[24].fileTimeHi = 0U;
  c35_info[24].mFileTimeLo = 0U;
  c35_info[24].mFileTimeHi = 0U;
  c35_info[25].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c35_info[25].name = "eml_scalar_abs";
  c35_info[25].dominantType = "double";
  c35_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c35_info[25].fileTimeLo = 1286851112U;
  c35_info[25].fileTimeHi = 0U;
  c35_info[25].mFileTimeLo = 0U;
  c35_info[25].mFileTimeHi = 0U;
  c35_info[26].context = "";
  c35_info[26].name = "mrdivide";
  c35_info[26].dominantType = "double";
  c35_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c35_info[26].fileTimeLo = 1357983948U;
  c35_info[26].fileTimeHi = 0U;
  c35_info[26].mFileTimeLo = 1319762366U;
  c35_info[26].mFileTimeHi = 0U;
  c35_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c35_info[27].name = "rdivide";
  c35_info[27].dominantType = "double";
  c35_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c35_info[27].fileTimeLo = 1346542788U;
  c35_info[27].fileTimeHi = 0U;
  c35_info[27].mFileTimeLo = 0U;
  c35_info[27].mFileTimeHi = 0U;
  c35_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c35_info[28].name = "eml_scalexp_compatible";
  c35_info[28].dominantType = "double";
  c35_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c35_info[28].fileTimeLo = 1286851196U;
  c35_info[28].fileTimeHi = 0U;
  c35_info[28].mFileTimeLo = 0U;
  c35_info[28].mFileTimeHi = 0U;
  c35_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c35_info[29].name = "eml_div";
  c35_info[29].dominantType = "double";
  c35_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c35_info[29].fileTimeLo = 1313380210U;
  c35_info[29].fileTimeHi = 0U;
  c35_info[29].mFileTimeLo = 0U;
  c35_info[29].mFileTimeHi = 0U;
  c35_info[30].context = "";
  c35_info[30].name = "asin";
  c35_info[30].dominantType = "double";
  c35_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m";
  c35_info[30].fileTimeLo = 1343862770U;
  c35_info[30].fileTimeHi = 0U;
  c35_info[30].mFileTimeLo = 0U;
  c35_info[30].mFileTimeHi = 0U;
  c35_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m";
  c35_info[31].name = "eml_error";
  c35_info[31].dominantType = "char";
  c35_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c35_info[31].fileTimeLo = 1343862758U;
  c35_info[31].fileTimeHi = 0U;
  c35_info[31].mFileTimeLo = 0U;
  c35_info[31].mFileTimeHi = 0U;
  c35_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m";
  c35_info[32].name = "eml_scalar_asin";
  c35_info[32].dominantType = "double";
  c35_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_asin.m";
  c35_info[32].fileTimeLo = 1343862776U;
  c35_info[32].fileTimeHi = 0U;
  c35_info[32].mFileTimeLo = 0U;
  c35_info[32].mFileTimeHi = 0U;
}

static void c35_eml_scalar_eg(SFc35_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
}

static real_T c35_mpower(SFc35_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c35_a)
{
  real_T c35_b_a;
  real_T c35_c_a;
  real_T c35_ak;
  real_T c35_d_a;
  real_T c35_e_a;
  real_T c35_b;
  c35_b_a = c35_a;
  c35_c_a = c35_b_a;
  c35_b_eml_scalar_eg(chartInstance);
  c35_ak = c35_c_a;
  c35_d_a = c35_ak;
  c35_b_eml_scalar_eg(chartInstance);
  c35_e_a = c35_d_a;
  c35_b = c35_d_a;
  return c35_e_a * c35_b;
}

static void c35_b_eml_scalar_eg(SFc35_CusakisME4901arcsInstanceStruct
  *chartInstance)
{
}

static real_T c35_sqrt(SFc35_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c35_x)
{
  real_T c35_b_x;
  c35_b_x = c35_x;
  c35_b_sqrt(chartInstance, &c35_b_x);
  return c35_b_x;
}

static void c35_eml_error(SFc35_CusakisME4901arcsInstanceStruct *chartInstance)
{
  int32_T c35_i55;
  static char_T c35_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c35_u[30];
  const mxArray *c35_y = NULL;
  int32_T c35_i56;
  static char_T c35_cv1[4] = { 's', 'q', 'r', 't' };

  char_T c35_b_u[4];
  const mxArray *c35_b_y = NULL;
  for (c35_i55 = 0; c35_i55 < 30; c35_i55++) {
    c35_u[c35_i55] = c35_cv0[c35_i55];
  }

  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 10, 0U, 1U, 0U, 2, 1, 30),
                FALSE);
  for (c35_i56 = 0; c35_i56 < 4; c35_i56++) {
    c35_b_u[c35_i56] = c35_cv1[c35_i56];
  }

  c35_b_y = NULL;
  sf_mex_assign(&c35_b_y, sf_mex_create("y", c35_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c35_y, 14, c35_b_y));
}

static real_T c35_abs(SFc35_CusakisME4901arcsInstanceStruct *chartInstance,
                      real_T c35_x)
{
  real_T c35_b_x;
  c35_b_x = c35_x;
  return muDoubleScalarAbs(c35_b_x);
}

static real_T c35_asin(SFc35_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T c35_x)
{
  real_T c35_b_x;
  c35_b_x = c35_x;
  c35_b_asin(chartInstance, &c35_b_x);
  return c35_b_x;
}

static void c35_b_eml_error(SFc35_CusakisME4901arcsInstanceStruct *chartInstance)
{
  int32_T c35_i57;
  static char_T c35_cv2[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c35_u[30];
  const mxArray *c35_y = NULL;
  int32_T c35_i58;
  static char_T c35_cv3[4] = { 'a', 's', 'i', 'n' };

  char_T c35_b_u[4];
  const mxArray *c35_b_y = NULL;
  for (c35_i57 = 0; c35_i57 < 30; c35_i57++) {
    c35_u[c35_i57] = c35_cv2[c35_i57];
  }

  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", c35_u, 10, 0U, 1U, 0U, 2, 1, 30),
                FALSE);
  for (c35_i58 = 0; c35_i58 < 4; c35_i58++) {
    c35_b_u[c35_i58] = c35_cv3[c35_i58];
  }

  c35_b_y = NULL;
  sf_mex_assign(&c35_b_y, sf_mex_create("y", c35_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c35_y, 14, c35_b_y));
}

static const mxArray *c35_d_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_u;
  const mxArray *c35_y = NULL;
  SFc35_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc35_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  c35_u = *(int32_T *)c35_inData;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", &c35_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, FALSE);
  return c35_mxArrayOutData;
}

static int32_T c35_f_emlrt_marshallIn(SFc35_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  int32_T c35_y;
  int32_T c35_i59;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), &c35_i59, 1, 6, 0U, 0, 0U, 0);
  c35_y = c35_i59;
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void c35_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_b_sfEvent;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  int32_T c35_y;
  SFc35_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc35_CusakisME4901arcsInstanceStruct *)chartInstanceVoid;
  c35_b_sfEvent = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_b_sfEvent),
    &c35_thisId);
  sf_mex_destroy(&c35_b_sfEvent);
  *(int32_T *)c35_outData = c35_y;
  sf_mex_destroy(&c35_mxArrayInData);
}

static uint8_T c35_g_emlrt_marshallIn(SFc35_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c35_b_is_active_c35_CusakisME4901arcs, const
  char_T *c35_identifier)
{
  uint8_T c35_y;
  emlrtMsgIdentifier c35_thisId;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c35_b_is_active_c35_CusakisME4901arcs), &c35_thisId);
  sf_mex_destroy(&c35_b_is_active_c35_CusakisME4901arcs);
  return c35_y;
}

static uint8_T c35_h_emlrt_marshallIn(SFc35_CusakisME4901arcsInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  uint8_T c35_y;
  uint8_T c35_u0;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), &c35_u0, 1, 3, 0U, 0, 0U, 0);
  c35_y = c35_u0;
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void c35_b_sqrt(SFc35_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T *c35_x)
{
  if (*c35_x < 0.0) {
    c35_eml_error(chartInstance);
  }

  *c35_x = muDoubleScalarSqrt(*c35_x);
}

static void c35_b_asin(SFc35_CusakisME4901arcsInstanceStruct *chartInstance,
  real_T *c35_x)
{
  boolean_T guard1 = FALSE;
  guard1 = FALSE;
  if (*c35_x < -1.0) {
    guard1 = TRUE;
  } else {
    if (1.0 < *c35_x) {
      guard1 = TRUE;
    }
  }

  if (guard1 == TRUE) {
    c35_b_eml_error(chartInstance);
  }

  *c35_x = muDoubleScalarAsin(*c35_x);
}

static void init_dsm_address_info(SFc35_CusakisME4901arcsInstanceStruct
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

void sf_c35_CusakisME4901arcs_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3526501207U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1871299338U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1925555127U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4238966368U);
}

mxArray *sf_c35_CusakisME4901arcs_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("4iP0gvr0IbJNHs7nbXRFVB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c35_CusakisME4901arcs_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c35_CusakisME4901arcs(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[7],T\"NP\",},{M[1],M[5],T\"Vel\",},{M[1],M[8],T\"base\",},{M[1],M[16],T\"baseout\",},{M[1],M[15],T\"enable\",},{M[1],M[11],T\"timem\",},{M[8],M[0],T\"is_active_c35_CusakisME4901arcs\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c35_CusakisME4901arcs_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc35_CusakisME4901arcsInstanceStruct *chartInstance;
    chartInstance = (SFc35_CusakisME4901arcsInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _CusakisME4901arcsMachineNumber_,
           35,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"SCtranslation");
          _SFD_SET_DATA_PROPS(1,1,1,0,"baseoutm");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Velm");
          _SFD_SET_DATA_PROPS(3,1,1,0,"timer");
          _SFD_SET_DATA_PROPS(4,1,1,0,"NewPos");
          _SFD_SET_DATA_PROPS(5,1,1,0,"basem");
          _SFD_SET_DATA_PROPS(6,2,0,1,"Vel");
          _SFD_SET_DATA_PROPS(7,2,0,1,"timem");
          _SFD_SET_DATA_PROPS(8,2,0,1,"NP");
          _SFD_SET_DATA_PROPS(9,2,0,1,"base");
          _SFD_SET_DATA_PROPS(10,2,0,1,"baseout");
          _SFD_SET_DATA_PROPS(11,2,0,1,"enable");
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
        _SFD_CV_INIT_EML(0,1,1,8,0,0,0,0,0,12,6);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1932);
        _SFD_CV_INIT_EML_IF(0,1,0,312,323,1406,1929);
        _SFD_CV_INIT_EML_IF(0,1,1,532,553,591,618);
        _SFD_CV_INIT_EML_IF(0,1,2,624,653,770,803);
        _SFD_CV_INIT_EML_IF(0,1,3,770,803,913,1207);
        _SFD_CV_INIT_EML_IF(0,1,4,913,946,1058,1207);
        _SFD_CV_INIT_EML_IF(0,1,5,1058,1092,-1,1092);
        _SFD_CV_INIT_EML_IF(0,1,6,1406,1436,1538,1929);
        _SFD_CV_INIT_EML_IF(0,1,7,1538,1564,1822,1929);

        {
          static int condStart[] = { 627, 642 };

          static int condEnd[] = { 638, 653 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,627,653,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 777, 792 };

          static int condEnd[] = { 788, 803 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,777,803,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 920, 935 };

          static int condEnd[] = { 931, 946 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,2,920,946,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1066, 1081 };

          static int condEnd[] = { 1077, 1092 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,3,1066,1092,2,6,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1413, 1428 };

          static int condEnd[] = { 1424, 1436 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,4,1413,1436,2,8,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1545, 1556 };

          static int condEnd[] = { 1552, 1564 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,5,1545,1564,2,10,&(condStart[0]),&(condEnd[0]),
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
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c35_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c35_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c35_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c35_b_sf_marshallOut,(MexInFcnForType)
            c35_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)c35_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c35_b_sf_marshallOut,(MexInFcnForType)
            c35_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)c35_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)c35_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)c35_sf_marshallIn);

        {
          real_T *c35_baseoutm;
          real_T *c35_timer;
          real_T *c35_basem;
          real_T *c35_timem;
          real_T *c35_base;
          real_T *c35_baseout;
          real_T *c35_enable;
          real_T (*c35_SCtranslation)[2];
          real_T (*c35_Velm)[2];
          real_T (*c35_NewPos)[2];
          real_T (*c35_Vel)[2];
          real_T (*c35_NP)[2];
          c35_enable = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c35_baseout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c35_base = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c35_NP = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 3);
          c35_timem = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c35_Vel = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
          c35_basem = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c35_NewPos = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 4);
          c35_timer = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c35_Velm = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 2);
          c35_baseoutm = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c35_SCtranslation = (real_T (*)[2])ssGetInputPortSignal
            (chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c35_SCtranslation);
          _SFD_SET_DATA_VALUE_PTR(1U, c35_baseoutm);
          _SFD_SET_DATA_VALUE_PTR(2U, *c35_Velm);
          _SFD_SET_DATA_VALUE_PTR(3U, c35_timer);
          _SFD_SET_DATA_VALUE_PTR(4U, *c35_NewPos);
          _SFD_SET_DATA_VALUE_PTR(5U, c35_basem);
          _SFD_SET_DATA_VALUE_PTR(6U, *c35_Vel);
          _SFD_SET_DATA_VALUE_PTR(7U, c35_timem);
          _SFD_SET_DATA_VALUE_PTR(8U, *c35_NP);
          _SFD_SET_DATA_VALUE_PTR(9U, c35_base);
          _SFD_SET_DATA_VALUE_PTR(10U, c35_baseout);
          _SFD_SET_DATA_VALUE_PTR(11U, c35_enable);
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
  return "VsoO5NG8N7Jxmyt3xvhuYB";
}

static void sf_opaque_initialize_c35_CusakisME4901arcs(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc35_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c35_CusakisME4901arcs((SFc35_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
  initialize_c35_CusakisME4901arcs((SFc35_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c35_CusakisME4901arcs(void *chartInstanceVar)
{
  enable_c35_CusakisME4901arcs((SFc35_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c35_CusakisME4901arcs(void *chartInstanceVar)
{
  disable_c35_CusakisME4901arcs((SFc35_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c35_CusakisME4901arcs(void *chartInstanceVar)
{
  sf_c35_CusakisME4901arcs((SFc35_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c35_CusakisME4901arcs(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c35_CusakisME4901arcs
    ((SFc35_CusakisME4901arcsInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c35_CusakisME4901arcs();/* state var info */
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

extern void sf_internal_set_sim_state_c35_CusakisME4901arcs(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c35_CusakisME4901arcs();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c35_CusakisME4901arcs((SFc35_CusakisME4901arcsInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c35_CusakisME4901arcs(SimStruct* S)
{
  return sf_internal_get_sim_state_c35_CusakisME4901arcs(S);
}

static void sf_opaque_set_sim_state_c35_CusakisME4901arcs(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c35_CusakisME4901arcs(S, st);
}

static void sf_opaque_terminate_c35_CusakisME4901arcs(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc35_CusakisME4901arcsInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_CusakisME4901arcs_optimization_info();
    }

    finalize_c35_CusakisME4901arcs((SFc35_CusakisME4901arcsInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc35_CusakisME4901arcs((SFc35_CusakisME4901arcsInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c35_CusakisME4901arcs(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c35_CusakisME4901arcs
      ((SFc35_CusakisME4901arcsInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c35_CusakisME4901arcs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CusakisME4901arcs_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      35);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,35,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,35,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,35);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,35,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,35,6);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=6; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,35);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2286373585U));
  ssSetChecksum1(S,(1726077423U));
  ssSetChecksum2(S,(2858968940U));
  ssSetChecksum3(S,(3972536689U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c35_CusakisME4901arcs(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c35_CusakisME4901arcs(SimStruct *S)
{
  SFc35_CusakisME4901arcsInstanceStruct *chartInstance;
  chartInstance = (SFc35_CusakisME4901arcsInstanceStruct *)utMalloc(sizeof
    (SFc35_CusakisME4901arcsInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc35_CusakisME4901arcsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c35_CusakisME4901arcs;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c35_CusakisME4901arcs;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c35_CusakisME4901arcs;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c35_CusakisME4901arcs;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c35_CusakisME4901arcs;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c35_CusakisME4901arcs;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c35_CusakisME4901arcs;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c35_CusakisME4901arcs;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c35_CusakisME4901arcs;
  chartInstance->chartInfo.mdlStart = mdlStart_c35_CusakisME4901arcs;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c35_CusakisME4901arcs;
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

void c35_CusakisME4901arcs_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c35_CusakisME4901arcs(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c35_CusakisME4901arcs(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c35_CusakisME4901arcs(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c35_CusakisME4901arcs_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
