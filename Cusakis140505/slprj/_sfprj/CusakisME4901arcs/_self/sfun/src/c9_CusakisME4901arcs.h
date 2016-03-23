#ifndef __c9_CusakisME4901arcs_h__
#define __c9_CusakisME4901arcs_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc9_CusakisME4901arcsInstanceStruct
#define typedef_SFc9_CusakisME4901arcsInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c9_sfEvent;
  boolean_T c9_isStable;
  boolean_T c9_doneDoubleBufferReInit;
  uint8_T c9_is_active_c9_CusakisME4901arcs;
} SFc9_CusakisME4901arcsInstanceStruct;

#endif                                 /*typedef_SFc9_CusakisME4901arcsInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c9_CusakisME4901arcs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c9_CusakisME4901arcs_get_check_sum(mxArray *plhs[]);
extern void c9_CusakisME4901arcs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif