#ifndef __c12_CusakisME4901arcs_h__
#define __c12_CusakisME4901arcs_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c12_ResolvedFunctionInfo
#define typedef_c12_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c12_ResolvedFunctionInfo;

#endif                                 /*typedef_c12_ResolvedFunctionInfo*/

#ifndef typedef_SFc12_CusakisME4901arcsInstanceStruct
#define typedef_SFc12_CusakisME4901arcsInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c12_sfEvent;
  boolean_T c12_isStable;
  boolean_T c12_doneDoubleBufferReInit;
  uint8_T c12_is_active_c12_CusakisME4901arcs;
} SFc12_CusakisME4901arcsInstanceStruct;

#endif                                 /*typedef_SFc12_CusakisME4901arcsInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c12_CusakisME4901arcs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c12_CusakisME4901arcs_get_check_sum(mxArray *plhs[]);
extern void c12_CusakisME4901arcs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
