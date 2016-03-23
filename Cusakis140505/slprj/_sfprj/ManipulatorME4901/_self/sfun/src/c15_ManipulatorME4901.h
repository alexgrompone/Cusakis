#ifndef __c15_ManipulatorME4901_h__
#define __c15_ManipulatorME4901_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c15_ResolvedFunctionInfo
#define typedef_c15_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c15_ResolvedFunctionInfo;

#endif                                 /*typedef_c15_ResolvedFunctionInfo*/

#ifndef typedef_SFc15_ManipulatorME4901InstanceStruct
#define typedef_SFc15_ManipulatorME4901InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c15_sfEvent;
  boolean_T c15_isStable;
  boolean_T c15_doneDoubleBufferReInit;
  uint8_T c15_is_active_c15_ManipulatorME4901;
  real_T c15_lb;
  real_T c15_l;
  real_T c15_mb;
  real_T c15_m;
} SFc15_ManipulatorME4901InstanceStruct;

#endif                                 /*typedef_SFc15_ManipulatorME4901InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c15_ManipulatorME4901_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c15_ManipulatorME4901_get_check_sum(mxArray *plhs[]);
extern void c15_ManipulatorME4901_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
