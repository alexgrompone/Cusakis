#ifndef __c21_CusakisME4901_h__
#define __c21_CusakisME4901_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c21_ResolvedFunctionInfo
#define typedef_c21_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c21_ResolvedFunctionInfo;

#endif                                 /*typedef_c21_ResolvedFunctionInfo*/

#ifndef typedef_SFc21_CusakisME4901InstanceStruct
#define typedef_SFc21_CusakisME4901InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c21_sfEvent;
  boolean_T c21_isStable;
  boolean_T c21_doneDoubleBufferReInit;
  uint8_T c21_is_active_c21_CusakisME4901;
} SFc21_CusakisME4901InstanceStruct;

#endif                                 /*typedef_SFc21_CusakisME4901InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c21_CusakisME4901_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c21_CusakisME4901_get_check_sum(mxArray *plhs[]);
extern void c21_CusakisME4901_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
