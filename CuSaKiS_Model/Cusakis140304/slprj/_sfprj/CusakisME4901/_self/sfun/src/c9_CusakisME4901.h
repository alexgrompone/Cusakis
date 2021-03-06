#ifndef __c9_CusakisME4901_h__
#define __c9_CusakisME4901_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc9_CusakisME4901InstanceStruct
#define typedef_SFc9_CusakisME4901InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c9_sfEvent;
  boolean_T c9_isStable;
  boolean_T c9_doneDoubleBufferReInit;
  uint8_T c9_is_active_c9_CusakisME4901;
} SFc9_CusakisME4901InstanceStruct;

#endif                                 /*typedef_SFc9_CusakisME4901InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c9_CusakisME4901_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c9_CusakisME4901_get_check_sum(mxArray *plhs[]);
extern void c9_CusakisME4901_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
