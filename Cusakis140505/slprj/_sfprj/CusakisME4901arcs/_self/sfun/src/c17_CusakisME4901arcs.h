#ifndef __c17_CusakisME4901arcs_h__
#define __c17_CusakisME4901arcs_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc17_CusakisME4901arcsInstanceStruct
#define typedef_SFc17_CusakisME4901arcsInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c17_sfEvent;
  boolean_T c17_isStable;
  boolean_T c17_doneDoubleBufferReInit;
  uint8_T c17_is_active_c17_CusakisME4901arcs;
} SFc17_CusakisME4901arcsInstanceStruct;

#endif                                 /*typedef_SFc17_CusakisME4901arcsInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c17_CusakisME4901arcs_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c17_CusakisME4901arcs_get_check_sum(mxArray *plhs[]);
extern void c17_CusakisME4901arcs_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
