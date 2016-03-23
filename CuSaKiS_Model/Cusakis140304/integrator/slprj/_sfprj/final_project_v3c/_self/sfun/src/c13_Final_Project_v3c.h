#ifndef __c13_Final_Project_v3c_h__
#define __c13_Final_Project_v3c_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc13_Final_Project_v3cInstanceStruct
#define typedef_SFc13_Final_Project_v3cInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c13_sfEvent;
  boolean_T c13_isStable;
  boolean_T c13_doneDoubleBufferReInit;
  uint8_T c13_is_active_c13_Final_Project_v3c;
} SFc13_Final_Project_v3cInstanceStruct;

#endif                                 /*typedef_SFc13_Final_Project_v3cInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c13_Final_Project_v3c_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c13_Final_Project_v3c_get_check_sum(mxArray *plhs[]);
extern void c13_Final_Project_v3c_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
