#ifndef __c10_Final_Project_v3c_h__
#define __c10_Final_Project_v3c_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c10_ResolvedFunctionInfo
#define typedef_c10_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c10_ResolvedFunctionInfo;

#endif                                 /*typedef_c10_ResolvedFunctionInfo*/

#ifndef typedef_SFc10_Final_Project_v3cInstanceStruct
#define typedef_SFc10_Final_Project_v3cInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c10_sfEvent;
  boolean_T c10_isStable;
  boolean_T c10_doneDoubleBufferReInit;
  uint8_T c10_is_active_c10_Final_Project_v3c;
} SFc10_Final_Project_v3cInstanceStruct;

#endif                                 /*typedef_SFc10_Final_Project_v3cInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c10_Final_Project_v3c_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c10_Final_Project_v3c_get_check_sum(mxArray *plhs[]);
extern void c10_Final_Project_v3c_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
