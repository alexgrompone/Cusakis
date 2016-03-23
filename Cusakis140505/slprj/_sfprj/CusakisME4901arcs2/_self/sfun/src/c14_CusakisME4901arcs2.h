#ifndef __c14_CusakisME4901arcs2_h__
#define __c14_CusakisME4901arcs2_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c14_ResolvedFunctionInfo
#define typedef_c14_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c14_ResolvedFunctionInfo;

#endif                                 /*typedef_c14_ResolvedFunctionInfo*/

#ifndef typedef_SFc14_CusakisME4901arcs2InstanceStruct
#define typedef_SFc14_CusakisME4901arcs2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c14_sfEvent;
  boolean_T c14_isStable;
  boolean_T c14_doneDoubleBufferReInit;
  uint8_T c14_is_active_c14_CusakisME4901arcs2;
} SFc14_CusakisME4901arcs2InstanceStruct;

#endif                                 /*typedef_SFc14_CusakisME4901arcs2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c14_CusakisME4901arcs2_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c14_CusakisME4901arcs2_get_check_sum(mxArray *plhs[]);
extern void c14_CusakisME4901arcs2_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
