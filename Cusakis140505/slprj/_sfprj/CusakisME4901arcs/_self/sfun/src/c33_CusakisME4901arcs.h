#ifndef __c33_CusakisME4901arcs_h__
#define __c33_CusakisME4901arcs_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c33_ResolvedFunctionInfo
#define typedef_c33_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c33_ResolvedFunctionInfo;

#endif                                 /*typedef_c33_ResolvedFunctionInfo*/

#ifndef typedef_SFc33_CusakisME4901arcsInstanceStruct
#define typedef_SFc33_CusakisME4901arcsInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c33_sfEvent;
  boolean_T c33_isStable;
  boolean_T c33_doneDoubleBufferReInit;
  uint8_T c33_is_active_c33_CusakisME4901arcs;
} SFc33_CusakisME4901arcsInstanceStruct;

#endif                                 /*typedef_SFc33_CusakisME4901arcsInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c33_CusakisME4901arcs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c33_CusakisME4901arcs_get_check_sum(mxArray *plhs[]);
extern void c33_CusakisME4901arcs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
