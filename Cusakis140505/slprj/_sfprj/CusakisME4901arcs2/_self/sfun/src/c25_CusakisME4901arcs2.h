#ifndef __c25_CusakisME4901arcs2_h__
#define __c25_CusakisME4901arcs2_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c25_ResolvedFunctionInfo
#define typedef_c25_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c25_ResolvedFunctionInfo;

#endif                                 /*typedef_c25_ResolvedFunctionInfo*/

#ifndef typedef_SFc25_CusakisME4901arcs2InstanceStruct
#define typedef_SFc25_CusakisME4901arcs2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c25_sfEvent;
  boolean_T c25_isStable;
  boolean_T c25_doneDoubleBufferReInit;
  uint8_T c25_is_active_c25_CusakisME4901arcs2;
  real_T c25_mt;
  real_T c25_mb;
  real_T c25_m;
} SFc25_CusakisME4901arcs2InstanceStruct;

#endif                                 /*typedef_SFc25_CusakisME4901arcs2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c25_CusakisME4901arcs2_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c25_CusakisME4901arcs2_get_check_sum(mxArray *plhs[]);
extern void c25_CusakisME4901arcs2_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
