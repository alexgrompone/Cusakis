#ifndef __c19_ManipulatorME4901_h__
#define __c19_ManipulatorME4901_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c19_ResolvedFunctionInfo
#define typedef_c19_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c19_ResolvedFunctionInfo;

#endif                                 /*typedef_c19_ResolvedFunctionInfo*/

#ifndef typedef_SFc19_ManipulatorME4901InstanceStruct
#define typedef_SFc19_ManipulatorME4901InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c19_sfEvent;
  boolean_T c19_isStable;
  boolean_T c19_doneDoubleBufferReInit;
  uint8_T c19_is_active_c19_ManipulatorME4901;
  real_T c19_m;
  real_T c19_l;
  real_T c19_w;
} SFc19_ManipulatorME4901InstanceStruct;

#endif                                 /*typedef_SFc19_ManipulatorME4901InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c19_ManipulatorME4901_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c19_ManipulatorME4901_get_check_sum(mxArray *plhs[]);
extern void c19_ManipulatorME4901_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
