/* Include files */
#include "irobotcomunicationjoy2_sfun.h"
#include "c2_irobotcomunicationjoy2.h"
#define CHARTINSTANCE_CHARTNUMBER       (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER    (chartInstance.instanceNumber)
#include "irobotcomunicationjoy2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_IN_NO_ACTIVE_CHILD           (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc2_irobotcomunicationjoy2InstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c2_irobotcomunicationjoy2(void);
static void initialize_params_c2_irobotcomunicationjoy2(void);
static void enable_c2_irobotcomunicationjoy2(void);
static void disable_c2_irobotcomunicationjoy2(void);
static void finalize_c2_irobotcomunicationjoy2(void);
static void sf_c2_irobotcomunicationjoy2(void);
static void c2_c2_irobotcomunicationjoy2(void);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
 c2_chartNumber);
static real_T c2_rem(real_T c2_x, real_T c2_y);
static real_T c2_mpower(real_T c2_a);
static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_c_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_d_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_e_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_f_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_g_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_h_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_i_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_j_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_k_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_l_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_m_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_n_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_o_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_p_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_q_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_r_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_s_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_t_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_u_sf_marshall(void *c2_chartInstance, void *c2_u);
static const mxArray *c2_v_sf_marshall(void *c2_chartInstance, void *c2_u);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[49]);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c2_irobotcomunicationjoy2(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c2_is_active_c2_irobotcomunicationjoy2 = 0U;
}

static void initialize_params_c2_irobotcomunicationjoy2(void)
{
}

static void enable_c2_irobotcomunicationjoy2(void)
{
}

static void disable_c2_irobotcomunicationjoy2(void)
{
}

static void finalize_c2_irobotcomunicationjoy2(void)
{
}

static void sf_c2_irobotcomunicationjoy2(void)
{
  uint8_T c2_previousEvent;
  real_T *c2_VelR;
  real_T *c2_VelL;
  real_T *c2_hiR;
  real_T *c2_lowR;
  real_T *c2_hiL;
  real_T *c2_lowL;
  c2_VelL = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c2_hiR = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_lowL = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c2_VelR = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c2_hiL = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c2_lowR = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_DATA_RANGE_CHECK(*c2_VelR, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_VelL, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_hiR, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_lowR, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_hiL, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_lowL, 1U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c2_c2_irobotcomunicationjoy2();
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_irobotcomunicationjoy2MachineNumber_,
   chartInstance.chartNumber, chartInstance.
   instanceNumber);
}

static void c2_c2_irobotcomunicationjoy2(void)
{
  real_T c2_VelR;
  real_T c2_VelL;
  real_T c2_unegl;
  real_T c2_zl;
  real_T c2_nl;
  real_T c2_ll[2];
  real_T c2_il;
  real_T c2_dl;
  real_T c2_Bl[4];
  real_T c2_Al[4];
  real_T c2_uneg;
  real_T c2_z;
  real_T c2_n;
  real_T c2_l[2];
  real_T c2_i;
  real_T c2_d;
  real_T c2_B[4];
  real_T c2_A[4];
  real_T c2_lowL;
  real_T c2_hiL;
  real_T c2_lowR;
  real_T c2_hiR;
  int32_T c2_i0;
  int32_T c2_i1;
  real_T c2_b_A;
  real_T c2_b_B;
  real_T c2_x;
  real_T c2_y;
  real_T c2_b_x;
  int32_T c2_i2;
  static real_T c2_dv0[2] = { 4.0, 1.0 };
  real_T c2_d0;
  real_T c2_b_z;
  int32_T c2_i3;
  int32_T c2_i4;
  real_T c2_c_A;
  real_T c2_c_B;
  real_T c2_c_x;
  real_T c2_b_y;
  real_T c2_d_x;
  int32_T c2_i5;
  real_T c2_d1;
  real_T c2_c_z;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  real_T c2_d_A;
  real_T c2_d_B;
  real_T c2_e_x;
  real_T c2_c_y;
  real_T c2_f_x;
  int32_T c2_i10;
  real_T c2_d2;
  real_T c2_b_zl;
  int32_T c2_i11;
  int32_T c2_i12;
  real_T c2_e_A;
  real_T c2_e_B;
  real_T c2_g_x;
  real_T c2_d_y;
  real_T c2_h_x;
  int32_T c2_i13;
  real_T c2_d3;
  real_T c2_c_zl;
  int32_T c2_i14;
  int32_T c2_i15;
  real_T *c2_b_VelR;
  real_T *c2_b_VelL;
  real_T *c2_b_hiR;
  real_T *c2_b_lowR;
  real_T *c2_b_hiL;
  real_T *c2_b_lowL;
  c2_b_VelL = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c2_b_hiR = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_b_lowL = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
  c2_b_VelR = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c2_b_hiL = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c2_b_lowR = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,1);
  c2_VelR = *c2_b_VelR;
  c2_VelL = *c2_b_VelL;
  sf_debug_symbol_scope_push(22U, 0U);
  sf_debug_symbol_scope_add("unegl", &c2_unegl, c2_v_sf_marshall);
  sf_debug_symbol_scope_add("zl", &c2_zl, c2_u_sf_marshall);
  sf_debug_symbol_scope_add("nl", &c2_nl, c2_t_sf_marshall);
  sf_debug_symbol_scope_add("ll", &c2_ll, c2_s_sf_marshall);
  sf_debug_symbol_scope_add("il", &c2_il, c2_r_sf_marshall);
  sf_debug_symbol_scope_add("dl", &c2_dl, c2_q_sf_marshall);
  sf_debug_symbol_scope_add("Bl", &c2_Bl, c2_p_sf_marshall);
  sf_debug_symbol_scope_add("Al", &c2_Al, c2_o_sf_marshall);
  sf_debug_symbol_scope_add("uneg", &c2_uneg, c2_n_sf_marshall);
  sf_debug_symbol_scope_add("z", &c2_z, c2_m_sf_marshall);
  sf_debug_symbol_scope_add("n", &c2_n, c2_l_sf_marshall);
  sf_debug_symbol_scope_add("l", &c2_l, c2_k_sf_marshall);
  sf_debug_symbol_scope_add("i", &c2_i, c2_j_sf_marshall);
  sf_debug_symbol_scope_add("d", &c2_d, c2_i_sf_marshall);
  sf_debug_symbol_scope_add("B", &c2_B, c2_h_sf_marshall);
  sf_debug_symbol_scope_add("A", &c2_A, c2_g_sf_marshall);
  sf_debug_symbol_scope_add("lowL", &c2_lowL, c2_f_sf_marshall);
  sf_debug_symbol_scope_add("hiL", &c2_hiL, c2_e_sf_marshall);
  sf_debug_symbol_scope_add("lowR", &c2_lowR, c2_d_sf_marshall);
  sf_debug_symbol_scope_add("hiR", &c2_hiR, c2_c_sf_marshall);
  sf_debug_symbol_scope_add("VelL", &c2_VelL, c2_b_sf_marshall);
  sf_debug_symbol_scope_add("VelR", &c2_VelR, c2_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,10);
  if(CV_EML_IF(0, 0, c2_VelR > 0.0)) {
    /*  Alessio Grompone january 2014 */
    /*  Spacecraft Robotics Laboratory, Naval Postgraduate School */
    /* Converts Wheels velocities first to hex then to two decimals as required by iRobot Create */
    /* Right Wheel Conversion */
    /* decimal to numeric hex vector */
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,12);
    for(c2_i0 = 0; c2_i0 < 4; c2_i0 = c2_i0 + 1) {
      c2_A[c2_i0] = 0.0;
    }
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,13);
    for(c2_i1 = 0; c2_i1 < 4; c2_i1 = c2_i1 + 1) {
      c2_B[c2_i1] = 0.0;
    }
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,14);
    c2_d = c2_VelR;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,15);
    c2_i = 1.0;
    while(CV_EML_WHILE(0, 0, c2_d > 16.0)) {
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,17);
      c2_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
       (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 4, 1, 0) - 1] = c2_rem(c2_d,
       16.0);
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,18);
      c2_b_A = c2_d;
      c2_b_B = 16.0;
      c2_x = c2_b_A;
      c2_y = c2_b_B;
      c2_b_x = c2_x / c2_y;
      c2_d = c2_b_x;
      c2_d = floor(c2_d);
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,19);
      c2_i = c2_i + 1.0;
      sf_mex_listen_for_ctrl_c(chartInstance.S);
    }
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,21);
    c2_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
     (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 4, 1, 0) - 1] = c2_d;
    /* inverted numeric hex vector */
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,22);
    for(c2_i2 = 0; c2_i2 < 2; c2_i2 = c2_i2 + 1) {
      c2_l[c2_i2] = c2_dv0[c2_i2];
    }
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,23);
    c2_n = 5.0;
    c2_d0 = 1.0;
    c2_z = c2_d0;
    c2_b_z = c2_d0;
    while(c2_b_z <= 4.0) {
      c2_z = c2_b_z;
      CV_EML_FOR(0, 0, 1);
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,25);
      c2_B[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B",
       (int32_T)_SFD_INTEGER_CHECK("z", c2_z), 1, 4, 1, 0) - 1] = c2_A[(int32_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("", c2_n -
        c2_z), 1, 4, 1, 0) - 1];
      c2_b_z = c2_b_z + 1.0;
      sf_mex_listen_for_ctrl_c(chartInstance.S);
    }
    CV_EML_FOR(0, 0, 0);
    /* numeric hex vector to 2 decimal values */
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,28);
    c2_hiR = c2_B[0] * 16.0 + c2_B[1];
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,29);
    c2_lowR = c2_B[2] * 16.0 + c2_B[3];
  } else {
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,30);
    if(CV_EML_IF(0, 1, c2_VelR < 0.0)) {
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,31);
      c2_uneg = c2_VelR + c2_mpower(2.0);
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,32);
      for(c2_i3 = 0; c2_i3 < 4; c2_i3 = c2_i3 + 1) {
        c2_A[c2_i3] = 0.0;
      }
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,33);
      for(c2_i4 = 0; c2_i4 < 4; c2_i4 = c2_i4 + 1) {
        c2_B[c2_i4] = 0.0;
      }
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,34);
      c2_d = c2_uneg;
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,35);
      c2_i = 1.0;
      while(CV_EML_WHILE(0, 1, c2_d > 16.0)) {
        _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,37);
        c2_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
         (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 4, 1, 0) - 1] = c2_rem(c2_d,
         16.0);
        _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,38);
        c2_c_A = c2_d;
        c2_c_B = 16.0;
        c2_c_x = c2_c_A;
        c2_b_y = c2_c_B;
        c2_d_x = c2_c_x / c2_b_y;
        c2_d = c2_d_x;
        c2_d = floor(c2_d);
        _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,39);
        c2_i = c2_i + 1.0;
        sf_mex_listen_for_ctrl_c(chartInstance.S);
      }
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,41);
      c2_A[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("A",
       (int32_T)_SFD_INTEGER_CHECK("i", c2_i), 1, 4, 1, 0) - 1] = c2_d;
      /* inverted numeric hex vector */
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,42);
      for(c2_i5 = 0; c2_i5 < 2; c2_i5 = c2_i5 + 1) {
        c2_l[c2_i5] = c2_dv0[c2_i5];
      }
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,43);
      c2_n = 4.0;
      c2_d1 = 0.0;
      c2_z = c2_d1;
      c2_c_z = c2_d1;
      while(c2_c_z <= 3.0) {
        c2_z = c2_c_z;
        CV_EML_FOR(0, 1, 1);
        _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,45);
        c2_B[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("B",
         (int32_T)_SFD_INTEGER_CHECK("", c2_z + 1.0), 1, 4, 1, 0) - 1] =
          c2_A[(int32_T)
          _SFD_EML_ARRAY_BOUNDS_CHECK("A", (int32_T)_SFD_INTEGER_CHECK("", c2_n
          - c2_z), 1, 4, 1, 0) - 1];
        c2_c_z = c2_c_z + 1.0;
        sf_mex_listen_for_ctrl_c(chartInstance.S);
      }
      CV_EML_FOR(0, 1, 0);
      /* numeric hex vector to 2 decimal values */
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,48);
      c2_hiR = c2_B[0] * 16.0 + c2_B[1];
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,49);
      c2_lowR = c2_B[2] * 16.0 + c2_B[3];
    } else {
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,51);
      c2_uneg = c2_VelR + c2_mpower(2.0);
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,52);
      for(c2_i6 = 0; c2_i6 < 4; c2_i6 = c2_i6 + 1) {
        c2_A[c2_i6] = 0.0;
      }
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,53);
      for(c2_i7 = 0; c2_i7 < 4; c2_i7 = c2_i7 + 1) {
        c2_B[c2_i7] = 0.0;
      }
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,54);
      c2_d = c2_uneg;
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,55);
      c2_i = 1.0;
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,56);
      c2_hiR = 0.0;
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,57);
      c2_lowR = 0.0;
    }
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,60);
  if(CV_EML_IF(0, 2, c2_VelL > 0.0)) {
    /* decimal to numeric hex vector */
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,62);
    for(c2_i8 = 0; c2_i8 < 4; c2_i8 = c2_i8 + 1) {
      c2_Al[c2_i8] = 0.0;
    }
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,63);
    for(c2_i9 = 0; c2_i9 < 4; c2_i9 = c2_i9 + 1) {
      c2_Bl[c2_i9] = 0.0;
    }
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,64);
    c2_dl = c2_VelL;
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,65);
    c2_il = 1.0;
    while(CV_EML_WHILE(0, 2, c2_dl > 16.0)) {
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,67);
      c2_Al[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Al",
       (int32_T)_SFD_INTEGER_CHECK("il", c2_il), 1, 4, 1, 0) - 1] =
      c2_rem(c2_dl, 16.0);
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,68);
      c2_d_A = c2_dl;
      c2_d_B = 16.0;
      c2_e_x = c2_d_A;
      c2_c_y = c2_d_B;
      c2_f_x = c2_e_x / c2_c_y;
      c2_dl = c2_f_x;
      c2_dl = floor(c2_dl);
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,69);
      c2_il = c2_il + 1.0;
      sf_mex_listen_for_ctrl_c(chartInstance.S);
    }
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,71);
    c2_Al[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Al",
     (int32_T)_SFD_INTEGER_CHECK("il", c2_il), 1, 4, 1, 0) - 1] = c2_dl;
    /* inverted numeric hex vector */
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,72);
    for(c2_i10 = 0; c2_i10 < 2; c2_i10 = c2_i10 + 1) {
      c2_ll[c2_i10] = c2_dv0[c2_i10];
    }
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,73);
    c2_nl = 5.0;
    c2_d2 = 1.0;
    c2_zl = c2_d2;
    c2_b_zl = c2_d2;
    while(c2_b_zl <= 4.0) {
      c2_zl = c2_b_zl;
      CV_EML_FOR(0, 2, 1);
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,75);
      c2_Bl[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Bl",
       (int32_T)_SFD_INTEGER_CHECK("zl", c2_zl), 1, 4, 1, 0) - 1] =
        c2_Al[(int32_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("Al", (int32_T)_SFD_INTEGER_CHECK("", c2_nl
        - c2_zl), 1, 4, 1, 0) - 1];
      c2_b_zl = c2_b_zl + 1.0;
      sf_mex_listen_for_ctrl_c(chartInstance.S);
    }
    CV_EML_FOR(0, 2, 0);
    /* numeric hex vector to 2 decimal values */
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,78);
    c2_hiL = c2_Bl[0] * 16.0 + c2_Bl[1];
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,79);
    c2_lowL = c2_Bl[2] * 16.0 + c2_Bl[3];
  } else {
    _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,80);
    if(CV_EML_IF(0, 3, c2_VelL < 0.0)) {
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,81);
      c2_unegl = c2_VelL + c2_mpower(2.0);
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,82);
      for(c2_i11 = 0; c2_i11 < 4; c2_i11 = c2_i11 + 1) {
        c2_Al[c2_i11] = 0.0;
      }
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,83);
      for(c2_i12 = 0; c2_i12 < 4; c2_i12 = c2_i12 + 1) {
        c2_Bl[c2_i12] = 0.0;
      }
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,84);
      c2_dl = c2_unegl;
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,85);
      c2_il = 1.0;
      while(CV_EML_WHILE(0, 3, c2_dl > 16.0)) {
        _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,87);
        c2_Al[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Al",
         (int32_T)_SFD_INTEGER_CHECK("il", c2_il), 1, 4, 1, 0) - 1] =
          c2_rem(c2_dl, 16.0);
        _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,88);
        c2_e_A = c2_dl;
        c2_e_B = 16.0;
        c2_g_x = c2_e_A;
        c2_d_y = c2_e_B;
        c2_h_x = c2_g_x / c2_d_y;
        c2_dl = c2_h_x;
        c2_dl = floor(c2_dl);
        _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,89);
        c2_il = c2_il + 1.0;
        sf_mex_listen_for_ctrl_c(chartInstance.S);
      }
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,91);
      c2_Al[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Al",
       (int32_T)_SFD_INTEGER_CHECK("il", c2_il), 1, 4, 1, 0) - 1] = c2_dl;
      /* inverted numeric hex vector */
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,92);
      for(c2_i13 = 0; c2_i13 < 2; c2_i13 = c2_i13 + 1) {
        c2_ll[c2_i13] = c2_dv0[c2_i13];
      }
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,93);
      c2_nl = 4.0;
      c2_d3 = 0.0;
      c2_zl = c2_d3;
      c2_c_zl = c2_d3;
      while(c2_c_zl <= 3.0) {
        c2_zl = c2_c_zl;
        CV_EML_FOR(0, 3, 1);
        _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,95);
        c2_Bl[(int32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Bl",
         (int32_T)_SFD_INTEGER_CHECK("", c2_zl + 1.0), 1, 4, 1, 0) - 1] =
          c2_Al[(int32_T)
          _SFD_EML_ARRAY_BOUNDS_CHECK("Al", (int32_T)_SFD_INTEGER_CHECK("",
          c2_nl - c2_zl), 1, 4, 1, 0) - 1];
        c2_c_zl = c2_c_zl + 1.0;
        sf_mex_listen_for_ctrl_c(chartInstance.S);
      }
      CV_EML_FOR(0, 3, 0);
      /* numeric hex vector to 2 decimal values */
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,98);
      c2_hiL = c2_Bl[0] * 16.0 + c2_Bl[1];
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,99);
      c2_lowL = c2_Bl[2] * 16.0 + c2_Bl[3];
    } else {
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,101);
      c2_unegl = c2_VelL + c2_mpower(2.0);
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,102);
      for(c2_i14 = 0; c2_i14 < 4; c2_i14 = c2_i14 + 1) {
        c2_Al[c2_i14] = 0.0;
      }
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,103);
      for(c2_i15 = 0; c2_i15 < 4; c2_i15 = c2_i15 + 1) {
        c2_Bl[c2_i15] = 0.0;
      }
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,104);
      c2_dl = c2_unegl;
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,105);
      c2_il = 1.0;
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,106);
      c2_hiL = 0.0;
      _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,107);
      c2_lowL = 0.0;
    }
  }
  _SFD_EML_CALL(STATE_DURING_DURING_ACTION_TAG,0,-107);
  sf_debug_symbol_scope_pop();
  *c2_b_hiR = c2_hiR;
  *c2_b_lowR = c2_lowR;
  *c2_b_hiL = c2_hiL;
  *c2_b_lowL = c2_lowL;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
 c2_chartNumber)
{
}

static real_T c2_rem(real_T c2_x, real_T c2_y)
{
  real_T c2_b_x;
  real_T c2_xk;
  real_T c2_c_x;
  real_T c2_yk;
  real_T c2_A;
  real_T c2_B;
  real_T c2_d_x;
  real_T c2_b_y;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  c2_b_x = c2_x;
  c2_xk = c2_b_x;
  c2_c_x = c2_y;
  c2_yk = c2_c_x;
  c2_A = c2_xk;
  c2_B = c2_yk;
  c2_d_x = c2_A;
  c2_b_y = c2_B;
  c2_e_x = c2_d_x / c2_b_y;
  c2_f_x = c2_e_x;
  c2_g_x = c2_f_x;
  c2_f_x = c2_g_x;
  if(c2_f_x > 0.0) {
    c2_f_x = floor(c2_f_x);
  } else {
    c2_f_x = ceil(c2_f_x);
  }
  return c2_xk - c2_f_x * c2_yk;
}

static real_T c2_mpower(real_T c2_a)
{
  real_T c2_b_a;
  real_T c2_b;
  real_T c2_ak;
  real_T c2_bk;
  real_T c2_x;
  real_T c2_b_x;
  int32_T c2_i16;
  static char c2_cv0[32] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'p', 'o', 'w', 'e', 'r', ':',
    'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };
  char c2_x1[32];
  int32_T c2_i17;
  static char c2_cv1[102] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm', 'p'
    , 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e', 's',
    'u', 'l', 't', 's', ',',
    ' ', 'm', 'a', 'k', 'e', ' ', 'a', 't', ' ', 'l', 'e', 'a', 's', 't', ' ',
    'o', 'n', 'e', ' ', 'i', 'n'
    , 'p', 'u', 't', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ',', ' ', 'e', '.',
    'g', '.', ' ', '\'', 'p',
    'o', 'w', 'e', 'r', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'a', ')',
    ',', 'b', ')', '\'', '.' };
  char c2_x2[102];
  int32_T c2_i18;
  char c2_u[32];
  const mxArray *c2_y = NULL;
  int32_T c2_i19;
  char c2_b_u[102];
  const mxArray *c2_b_y = NULL;
  c2_b_a = c2_a;
  c2_b = 16.0;
  c2_ak = c2_b_a;
  c2_bk = c2_b;
  if(c2_ak < 0.0) {
    c2_x = c2_bk;
    c2_b_x = c2_x;
    c2_b_x = floor(c2_b_x);
    if(c2_b_x != c2_bk) {
      for(c2_i16 = 0; c2_i16 < 32; c2_i16 = c2_i16 + 1) {
        c2_x1[c2_i16] = c2_cv0[c2_i16];
      }
      for(c2_i17 = 0; c2_i17 < 102; c2_i17 = c2_i17 + 1) {
        c2_x2[c2_i17] = c2_cv1[c2_i17];
      }
      for(c2_i18 = 0; c2_i18 < 32; c2_i18 = c2_i18 + 1) {
        c2_u[c2_i18] = c2_x1[c2_i18];
      }
      c2_y = NULL;
      sf_mex_assign(&c2_y, sf_mex_create(&c2_u, "y", 8, 0U, 1U, 2, 1, 32));
      for(c2_i19 = 0; c2_i19 < 102; c2_i19 = c2_i19 + 1) {
        c2_b_u[c2_i19] = c2_x2[c2_i19];
      }
      c2_b_y = NULL;
      sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 8, 0U, 1U, 2, 1, 102));
      sf_mex_call("error", 0U, 2U, 14, c2_y, 14, c2_b_y);
    }
  }
  return pow(c2_ak, c2_bk);
}

static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_b_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_c_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_d_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_e_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_f_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_g_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i20;
  real_T c2_b_u[4];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  for(c2_i20 = 0; c2_i20 < 4; c2_i20 = c2_i20 + 1) {
    c2_b_u[c2_i20] = (*((real_T (*)[4])c2_u))[c2_i20];
  }
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 1U, 1, 4));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_h_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i21;
  real_T c2_b_u[4];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  for(c2_i21 = 0; c2_i21 < 4; c2_i21 = c2_i21 + 1) {
    c2_b_u[c2_i21] = (*((real_T (*)[4])c2_u))[c2_i21];
  }
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 1U, 1, 4));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_i_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_j_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_k_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i22;
  real_T c2_b_u[2];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  for(c2_i22 = 0; c2_i22 < 2; c2_i22 = c2_i22 + 1) {
    c2_b_u[c2_i22] = (*((real_T (*)[2])c2_u))[c2_i22];
  }
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 1U, 2, 1, 2));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_l_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_m_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_n_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_o_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i23;
  real_T c2_b_u[4];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  for(c2_i23 = 0; c2_i23 < 4; c2_i23 = c2_i23 + 1) {
    c2_b_u[c2_i23] = (*((real_T (*)[4])c2_u))[c2_i23];
  }
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 1U, 1, 4));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_p_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i24;
  real_T c2_b_u[4];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  for(c2_i24 = 0; c2_i24 < 4; c2_i24 = c2_i24 + 1) {
    c2_b_u[c2_i24] = (*((real_T (*)[4])c2_u))[c2_i24];
  }
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 1U, 1, 4));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_q_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_r_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_s_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i25;
  real_T c2_b_u[2];
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  for(c2_i25 = 0; c2_i25 < 2; c2_i25 = c2_i25 + 1) {
    c2_b_u[c2_i25] = (*((real_T (*)[2])c2_u))[c2_i25];
  }
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 1U, 2, 1, 2));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_t_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_u_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_v_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create(&c2_b_u, "y", 0, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray *sf_c2_irobotcomunicationjoy2_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[49];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i26;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 49));
  for(c2_i26 = 0; c2_i26 < 49; c2_i26 = c2_i26 + 1) {
    c2_r0 = &c2_info[c2_i26];
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->context, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
     "nameCaptureInfo", c2_i26);
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->name, "nameCaptureInfo", 13, 0U,
      0U, 2, 1, strlen(c2_r0->name)), "name",
     "nameCaptureInfo", c2_i26);
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->dominantType, "nameCaptureInfo",
      13, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
     "dominantType", "nameCaptureInfo", c2_i26);
    sf_mex_addfield(c2_m0, sf_mex_create(c2_r0->resolved, "nameCaptureInfo", 13,
      0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved",
     "nameCaptureInfo", c2_i26);
    sf_mex_addfield(c2_m0, sf_mex_create(&c2_r0->fileLength, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileLength", "nameCaptureInfo", c2_i26);
    sf_mex_addfield(c2_m0, sf_mex_create(&c2_r0->fileTime1, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i26);
    sf_mex_addfield(c2_m0, sf_mex_create(&c2_r0->fileTime2, "nameCaptureInfo",
      7, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i26);
  }
  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[49])
{
  c2_info[0].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[0].name = "double";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[B]double";
  c2_info[0].fileLength = 0U;
  c2_info[0].fileTime1 = 0U;
  c2_info[0].fileTime2 = 0U;
  c2_info[1].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c2_info[1].name = "lt";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved = "[B]lt";
  c2_info[1].fileLength = 0U;
  c2_info[1].fileTime1 = 0U;
  c2_info[1].fileTime2 = 0U;
  c2_info[2].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[2].name = "isnumeric";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isnumeric.m";
  c2_info[2].fileLength = 250U;
  c2_info[2].fileTime1 = 1160446622U;
  c2_info[2].fileTime2 = 0U;
  c2_info[3].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c2_info[3].name = "isstruct";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isstruct.m";
  c2_info[3].fileLength = 179U;
  c2_info[3].fileTime1 = 1160446623U;
  c2_info[3].fileTime2 = 0U;
  c2_info[4].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c2_info[4].name = "eml_is_integer_class";
  c2_info[4].dominantType = "char";
  c2_info[4].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m";
  c2_info[4].fileLength = 462U;
  c2_info[4].fileTime1 = 1160446744U;
  c2_info[4].fileTime2 = 0U;
  c2_info[5].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/check_arg";
  c2_info[5].name = "true";
  c2_info[5].dominantType = "";
  c2_info[5].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/true.m";
  c2_info[5].fileLength = 625U;
  c2_info[5].fileTime1 = 1163970786U;
  c2_info[5].fileTime2 = 0U;
  c2_info[6].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[6].name = "mrdivide";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[6].fileLength = 653U;
  c2_info[6].fileTime1 = 1160446802U;
  c2_info[6].fileTime2 = 0U;
  c2_info[7].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/check_arg";
  c2_info[7].name = "isvector";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isvector.m";
  c2_info[7].fileLength = 284U;
  c2_info[7].fileTime1 = 1160446705U;
  c2_info[7].fileTime2 = 0U;
  c2_info[8].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[8].name = "eml_assert";
  c2_info[8].dominantType = "char";
  c2_info[8].resolved = "[B]eml_assert";
  c2_info[8].fileLength = 0U;
  c2_info[8].fileTime1 = 0U;
  c2_info[8].fileTime2 = 0U;
  c2_info[9].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_size.m";
  c2_info[9].name = "eml_scalexp_compatible";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c2_info[9].fileLength = 422U;
  c2_info[9].fileTime1 = 1160446754U;
  c2_info[9].fileTime2 = 0U;
  c2_info[10].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[10].name = "eml_error";
  c2_info[10].dominantType = "char";
  c2_info[10].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[10].fileLength = 585U;
  c2_info[10].fileTime1 = 1177099719U;
  c2_info[10].fileTime2 = 0U;
  c2_info[11].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[11].name = "ge";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved = "[B]ge";
  c2_info[11].fileLength = 0U;
  c2_info[11].fileTime1 = 0U;
  c2_info[11].fileTime2 = 0U;
  c2_info[12].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[12].name = "eml_scalexp_size";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_size.m";
  c2_info[12].fileLength = 923U;
  c2_info[12].fileTime1 = 1160446755U;
  c2_info[12].fileTime2 = 0U;
  c2_info[13].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/fix.m";
  c2_info[13].name = "isempty";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved = "[B]isempty";
  c2_info[13].fileLength = 0U;
  c2_info[13].fileTime1 = 0U;
  c2_info[13].fileTime2 = 0U;
  c2_info[14].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[14].name = "eml_numel";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_numel.m";
  c2_info[14].fileLength = 278U;
  c2_info[14].fileTime1 = 1163970801U;
  c2_info[14].fileTime2 = 0U;
  c2_info[15].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[15].name = "minus";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved = "[B]minus";
  c2_info[15].fileLength = 0U;
  c2_info[15].fileTime1 = 0U;
  c2_info[15].fileTime2 = 0U;
  c2_info[16].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c2_info[16].name = "logical";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved = "[B]logical";
  c2_info[16].fileLength = 0U;
  c2_info[16].fileTime1 = 0U;
  c2_info[16].fileTime2 = 0U;
  c2_info[17].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c2_info[17].name = "strcmp";
  c2_info[17].dominantType = "char";
  c2_info[17].resolved = "[B]strcmp";
  c2_info[17].fileLength = 0U;
  c2_info[17].fileTime1 = 0U;
  c2_info[17].fileTime2 = 0U;
  c2_info[18].context = "";
  c2_info[18].name = "floor";
  c2_info[18].dominantType = "double";
  c2_info[18].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[18].fileLength = 595U;
  c2_info[18].fileTime1 = 1163970735U;
  c2_info[18].fileTime2 = 0U;
  c2_info[19].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/check_arg";
  c2_info[19].name = "real";
  c2_info[19].dominantType = "double";
  c2_info[19].resolved = "[B]real";
  c2_info[19].fileLength = 0U;
  c2_info[19].fileTime1 = 0U;
  c2_info[19].fileTime2 = 0U;
  c2_info[20].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/check_arg";
  c2_info[20].name = "ne";
  c2_info[20].dominantType = "double";
  c2_info[20].resolved = "[B]ne";
  c2_info[20].fileLength = 0U;
  c2_info[20].fileTime1 = 0U;
  c2_info[20].fileTime2 = 0U;
  c2_info[21].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[21].name = "mtimes";
  c2_info[21].dominantType = "double";
  c2_info[21].resolved = "[B]mtimes";
  c2_info[21].fileLength = 0U;
  c2_info[21].fileTime1 = 0U;
  c2_info[21].fileTime2 = 0U;
  c2_info[22].context = "";
  c2_info[22].name = "rem";
  c2_info[22].dominantType = "double";
  c2_info[22].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[22].fileLength = 1228U;
  c2_info[22].fileTime1 = 1182204961U;
  c2_info[22].fileTime2 = 0U;
  c2_info[23].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c2_info[23].name = "plus";
  c2_info[23].dominantType = "double";
  c2_info[23].resolved = "[B]plus";
  c2_info[23].fileLength = 0U;
  c2_info[23].fileTime1 = 0U;
  c2_info[23].fileTime2 = 0U;
  c2_info[24].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c2_info[24].name = "isscalar";
  c2_info[24].dominantType = "double";
  c2_info[24].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isscalar.m";
  c2_info[24].fileLength = 243U;
  c2_info[24].fileTime1 = 1160446704U;
  c2_info[24].fileTime2 = 0U;
  c2_info[25].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c2_info[25].name = "ischar";
  c2_info[25].dominantType = "char";
  c2_info[25].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/strfun/ischar.m";
  c2_info[25].fileLength = 244U;
  c2_info[25].fileTime1 = 1160446833U;
  c2_info[25].fileTime2 = 0U;
  c2_info[26].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[26].name = "nargin";
  c2_info[26].dominantType = "";
  c2_info[26].resolved = "[B]nargin";
  c2_info[26].fileLength = 0U;
  c2_info[26].fileTime1 = 0U;
  c2_info[26].fileTime2 = 0U;
  c2_info[27].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[27].name = "power";
  c2_info[27].dominantType = "double";
  c2_info[27].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[27].fileLength = 4842U;
  c2_info[27].fileTime1 = 1177099746U;
  c2_info[27].fileTime2 = 0U;
  c2_info[28].context = "";
  c2_info[28].name = "mpower";
  c2_info[28].dominantType = "double";
  c2_info[28].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[28].fileLength = 3116U;
  c2_info[28].fileTime1 = 1177099745U;
  c2_info[28].fileTime2 = 0U;
  c2_info[29].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isnumeric.m";
  c2_info[29].name = "isa";
  c2_info[29].dominantType = "double";
  c2_info[29].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c2_info[29].fileLength = 791U;
  c2_info[29].fileTime1 = 1160446618U;
  c2_info[29].fileTime2 = 0U;
  c2_info[30].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isscalar.m";
  c2_info[30].name = "length";
  c2_info[30].dominantType = "double";
  c2_info[30].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[30].fileLength = 347U;
  c2_info[30].fileTime1 = 1163970770U;
  c2_info[30].fileTime2 = 0U;
  c2_info[31].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c2_info[31].name = "cast";
  c2_info[31].dominantType = "double";
  c2_info[31].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[31].fileLength = 907U;
  c2_info[31].fileTime1 = 1160446617U;
  c2_info[31].fileTime2 = 0U;
  c2_info[32].context = "";
  c2_info[32].name = "gt";
  c2_info[32].dominantType = "double";
  c2_info[32].resolved = "[B]gt";
  c2_info[32].fileLength = 0U;
  c2_info[32].fileTime1 = 0U;
  c2_info[32].fileTime2 = 0U;
  c2_info[33].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/check_arg";
  c2_info[33].name = "false";
  c2_info[33].dominantType = "";
  c2_info[33].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c2_info[33].fileLength = 631U;
  c2_info[33].fileTime1 = 1163970765U;
  c2_info[33].fileTime2 = 0U;
  c2_info[34].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c2_info[34].name = "eml_is_float_class";
  c2_info[34].dominantType = "char";
  c2_info[34].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c2_info[34].fileLength = 273U;
  c2_info[34].fileTime1 = 1160446743U;
  c2_info[34].fileTime2 = 0U;
  c2_info[35].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[35].name = "size";
  c2_info[35].dominantType = "double";
  c2_info[35].resolved = "[B]size";
  c2_info[35].fileLength = 0U;
  c2_info[35].fileTime1 = 0U;
  c2_info[35].fileTime2 = 0U;
  c2_info[36].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/check_arg";
  c2_info[36].name = "imag";
  c2_info[36].dominantType = "double";
  c2_info[36].resolved = "[B]imag";
  c2_info[36].fileLength = 0U;
  c2_info[36].fileTime1 = 0U;
  c2_info[36].fileTime2 = 0U;
  c2_info[37].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[37].name = "fix";
  c2_info[37].dominantType = "double";
  c2_info[37].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/fix.m";
  c2_info[37].fileLength = 785U;
  c2_info[37].fileTime1 = 1163970734U;
  c2_info[37].fileTime2 = 0U;
  c2_info[38].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c2_info[38].name = "class";
  c2_info[38].dominantType = "char";
  c2_info[38].resolved = "[B]class";
  c2_info[38].fileLength = 0U;
  c2_info[38].fileTime1 = 0U;
  c2_info[38].fileTime2 = 0U;
  c2_info[39].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_numel.m";
  c2_info[39].name = "numel";
  c2_info[39].dominantType = "double";
  c2_info[39].resolved = "[B]numel";
  c2_info[39].fileLength = 0U;
  c2_info[39].fileTime1 = 0U;
  c2_info[39].fileTime2 = 0U;
  c2_info[40].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[40].name = "eml_alloc";
  c2_info[40].dominantType = "double";
  c2_info[40].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c2_info[40].fileLength = 2151U;
  c2_info[40].fileTime1 = 1179464469U;
  c2_info[40].fileTime2 = 0U;
  c2_info[41].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_alloc.m";
  c2_info[41].name = "eml_assert_valid_size_arg";
  c2_info[41].dominantType = "double";
  c2_info[41].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[41].fileLength = 1097U;
  c2_info[41].fileTime1 = 1163970787U;
  c2_info[41].fileTime2 = 0U;
  c2_info[42].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/isvector.m";
  c2_info[42].name = "ndims";
  c2_info[42].dominantType = "double";
  c2_info[42].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/ndims.m";
  c2_info[42].fileLength = 236U;
  c2_info[42].fileTime1 = 1163970775U;
  c2_info[42].fileTime2 = 0U;
  c2_info[43].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[43].name = "rdivide";
  c2_info[43].dominantType = "double";
  c2_info[43].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[43].fileLength = 4533U;
  c2_info[43].fileTime1 = 1177099747U;
  c2_info[43].fileTime2 = 0U;
  c2_info[44].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[44].name = "isinteger";
  c2_info[44].dominantType = "double";
  c2_info[44].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isinteger.m";
  c2_info[44].fileLength = 254U;
  c2_info[44].fileTime1 = 1160446620U;
  c2_info[44].fileTime2 = 0U;
  c2_info[45].context = "";
  c2_info[45].name = "zeros";
  c2_info[45].dominantType = "double";
  c2_info[45].resolved = "[B]zeros";
  c2_info[45].fileLength = 0U;
  c2_info[45].fileTime1 = 0U;
  c2_info[45].fileTime2 = 0U;
  c2_info[46].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/rem.m";
  c2_info[46].name = "isreal";
  c2_info[46].dominantType = "double";
  c2_info[46].resolved = "[B]isreal";
  c2_info[46].fileLength = 0U;
  c2_info[46].fileTime1 = 0U;
  c2_info[46].fileTime2 = 0U;
  c2_info[47].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m/check_arg";
  c2_info[47].name = "isfloat";
  c2_info[47].dominantType = "double";
  c2_info[47].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isfloat.m";
  c2_info[47].fileLength = 182U;
  c2_info[47].fileTime1 = 1160446619U;
  c2_info[47].fileTime2 = 0U;
  c2_info[48].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/isa.m";
  c2_info[48].name = "eq";
  c2_info[48].dominantType = "double";
  c2_info[48].resolved = "[B]eq";
  c2_info[48].fileLength = 0U;
  c2_info[48].fileTime1 = 0U;
  c2_info[48].fileTime2 = 0U;
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c2_irobotcomunicationjoy2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1984646189U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(640526829U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3521648002U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(181788790U);
}

mxArray *sf_c2_irobotcomunicationjoy2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] =
  {"checksum","inputs","parameters","outputs"};
  mxArray *mxAutoinheritanceInfo =
  mxCreateStructMatrix(1,1,4,autoinheritanceFields);
  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(215008530U);
    pr[1] = (double)(3480072634U);
    pr[2] = (double)(2941572896U);
    pr[3] = (double)(2545128382U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
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
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }
    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }
  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,mxREAL));
  }
  {
    const char *dataFields[] = {"size","type","complexity"};
    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);
    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }
    {
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
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
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
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
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
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
      const char *typeFields[] = {"base","aliasId","fixpt"};
      mxArray *mxType = mxCreateStructMatrix(1,1,3,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"aliasId",mxCreateDoubleScalar(0));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }
    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }
  return(mxAutoinheritanceInfo);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
 fullDebuggerInitialization)
{
  if(ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
    /* do this only if simulation is starting */
    if(!sim_mode_is_rtw_gen(S)) {
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent =
          sf_debug_initialize_chart(_irobotcomunicationjoy2MachineNumber_,
         2,
         1,
         1,
         6,
         0,
         0,
         0,
         0,
         0,
         &(chartInstance.chartNumber),
         &(chartInstance.instanceNumber),
         ssGetPath(S),
         (void *)S);
        if(chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_irobotcomunicationjoy2MachineNumber_,chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_irobotcomunicationjoy2MachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_irobotcomunicationjoy2MachineNumber_,
           chartInstance.chartNumber,
           0,
           0,
           0);

          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"VelR",0,c2_sf_marshall);
          _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"VelL",0,c2_b_sf_marshall);
          _SFD_SET_DATA_PROPS(2,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"hiR",0,c2_c_sf_marshall);
          _SFD_SET_DATA_PROPS(5,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"lowR",0,c2_d_sf_marshall);
          _SFD_SET_DATA_PROPS(0,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"hiL",0,c2_e_sf_marshall);
          _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"lowL",0,c2_f_sf_marshall);
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }
        _SFD_CV_INIT_CHART(0,0,0,0);
        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,4,0,4,4,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2083);
        _SFD_CV_INIT_EML_IF(0,0,257,266,646,1136);
        _SFD_CV_INIT_EML_IF(0,1,646,659,1026,1136);
        _SFD_CV_INIT_EML_IF(0,2,1138,1147,1556,2082);
        _SFD_CV_INIT_EML_IF(0,3,1556,1569,1968,2082);
        _SFD_CV_INIT_EML_FOR(0,0,518,528,556);
        _SFD_CV_INIT_EML_FOR(0,1,894,906,936);
        _SFD_CV_INIT_EML_FOR(0,2,1418,1429,1462);
        _SFD_CV_INIT_EML_FOR(0,3,1825,1839,1874);
        _SFD_CV_INIT_EML_WHILE(0,0,363,374,443);
        _SFD_CV_INIT_EML_WHILE(0,1,741,752,821);
        _SFD_CV_INIT_EML_WHILE(0,2,1248,1260,1336);
        _SFD_CV_INIT_EML_WHILE(0,3,1657,1669,1745);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if(chartAlreadyPresent==0)
        {
          _SFD_TRANS_COV_MAPS(0,
           0,NULL,NULL,
           0,NULL,NULL,
           1,NULL,NULL,
           0,NULL,NULL);
        }

        {
          real_T *c2_VelR;
          real_T *c2_VelL;
          real_T *c2_hiR;
          real_T *c2_lowR;
          real_T *c2_hiL;
          real_T *c2_lowL;
          c2_VelL = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c2_hiR = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c2_lowL = (real_T *)ssGetOutputPortSignal(chartInstance.S, 4);
          c2_VelR = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          c2_hiL = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
          c2_lowR = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_VelR);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_VelL);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_hiR);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_lowR);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_hiL);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_lowL);
        }
      }
    }
  } else {
    sf_debug_reset_current_state_configuration(_irobotcomunicationjoy2MachineNumber_,chartInstance.chartNumber,chartInstance.instanceNumber);
  }
}

static void sf_opaque_initialize_c2_irobotcomunicationjoy2(void
 *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c2_irobotcomunicationjoy2();
  initialize_c2_irobotcomunicationjoy2();
}

static void sf_opaque_enable_c2_irobotcomunicationjoy2(void *chartInstanceVar)
{
  enable_c2_irobotcomunicationjoy2();
}

static void sf_opaque_disable_c2_irobotcomunicationjoy2(void *chartInstanceVar)
{
  disable_c2_irobotcomunicationjoy2();
}

static void sf_opaque_gateway_c2_irobotcomunicationjoy2(void *chartInstanceVar)
{
  sf_c2_irobotcomunicationjoy2();
}

static void sf_opaque_terminate_c2_irobotcomunicationjoy2(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) ||
   sim_mode_is_external(chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }
  finalize_c2_irobotcomunicationjoy2();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_irobotcomunicationjoy2(SimStruct *S)
{
  int i;
  for(i=0;i<ssGetNumRunTimeParams(S);i++) {
    if(ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }
  if(sf_machine_global_initializer_called()) {
    initialize_params_c2_irobotcomunicationjoy2();
  }
}

static void mdlSetWorkWidths_c2_irobotcomunicationjoy2(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("irobotcomunicationjoy2",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("irobotcomunicationjoy2",2,"gatewayCannotBeInlinedMultipleTimes"));
    if(chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"irobotcomunicationjoy2",2,2);
      sf_mark_chart_reusable_outputs(S,"irobotcomunicationjoy2",2,4);
    }
    sf_set_rtw_dwork_info(S,"irobotcomunicationjoy2",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(3313771702U));
  ssSetChecksum1(S,(1761486425U));
  ssSetChecksum2(S,(3031315401U));
  ssSetChecksum3(S,(62487330U));

  ssSetmdlDerivatives(S, NULL);

  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_irobotcomunicationjoy2(SimStruct *S)
{
  if(sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "irobotcomunicationjoy2", 2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_irobotcomunicationjoy2(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_irobotcomunicationjoy2;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c2_irobotcomunicationjoy2;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c2_irobotcomunicationjoy2;
  chartInstance.chartInfo.enableChart =
    sf_opaque_enable_c2_irobotcomunicationjoy2;
  chartInstance.chartInfo.disableChart =
    sf_opaque_disable_c2_irobotcomunicationjoy2;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c2_irobotcomunicationjoy2;
  chartInstance.chartInfo.mdlStart = mdlStart_c2_irobotcomunicationjoy2;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_irobotcomunicationjoy2;
  chartInstance.chartInfo.extModeExec = NULL;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo))); /* register the chart instance with simstruct */

  if(!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info();
  }
  chart_debug_initialization(S,1);
}

void c2_irobotcomunicationjoy2_method_dispatcher(SimStruct *S, int_T method,
 void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_irobotcomunicationjoy2(S);
    break;
   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_irobotcomunicationjoy2(S);
    break;
   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_irobotcomunicationjoy2(S);
    break;
   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
     "Error calling c2_irobotcomunicationjoy2_method_dispatcher.\n"
     "Can't handle method %d.\n", method);
    break;
  }
}

