#ifndef __c4_CusakisME4901delay2_h__
#define __c4_CusakisME4901delay2_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc4_CusakisME4901delay2InstanceStruct
#define typedef_SFc4_CusakisME4901delay2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_isStable;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_CusakisME4901delay2;
} SFc4_CusakisME4901delay2InstanceStruct;

#endif                                 /*typedef_SFc4_CusakisME4901delay2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_CusakisME4901delay2_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c4_CusakisME4901delay2_get_check_sum(mxArray *plhs[]);
extern void c4_CusakisME4901delay2_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
