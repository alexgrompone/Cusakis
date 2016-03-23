/* Include files */

#include "EndEffectorVSCube_v2_sfun.h"
#include "EndEffectorVSCube_v2_sfun_debug_macros.h"
#include "c1_EndEffectorVSCube_v2.h"
#include "c2_EndEffectorVSCube_v2.h"
#include "c3_EndEffectorVSCube_v2.h"
#include "c4_EndEffectorVSCube_v2.h"
#include "c6_EndEffectorVSCube_v2.h"
#include "c7_EndEffectorVSCube_v2.h"
#include "c8_EndEffectorVSCube_v2.h"
#include "c10_EndEffectorVSCube_v2.h"
#include "c11_EndEffectorVSCube_v2.h"
#include "c12_EndEffectorVSCube_v2.h"
#include "c13_EndEffectorVSCube_v2.h"
#include "c14_EndEffectorVSCube_v2.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _EndEffectorVSCube_v2MachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void EndEffectorVSCube_v2_initializer(void)
{
}

void EndEffectorVSCube_v2_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_EndEffectorVSCube_v2_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_EndEffectorVSCube_v2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_EndEffectorVSCube_v2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_EndEffectorVSCube_v2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_EndEffectorVSCube_v2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_EndEffectorVSCube_v2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_EndEffectorVSCube_v2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_EndEffectorVSCube_v2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_EndEffectorVSCube_v2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_EndEffectorVSCube_v2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_EndEffectorVSCube_v2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_EndEffectorVSCube_v2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_EndEffectorVSCube_v2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_EndEffectorVSCube_v2_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2319316804U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3175950417U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(627690327U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1077072192U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2429242807U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3272878693U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3866338255U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4291462255U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_EndEffectorVSCube_v2_get_check_sum(mxArray *plhs[]);
          sf_c1_EndEffectorVSCube_v2_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_EndEffectorVSCube_v2_get_check_sum(mxArray *plhs[]);
          sf_c2_EndEffectorVSCube_v2_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_EndEffectorVSCube_v2_get_check_sum(mxArray *plhs[]);
          sf_c3_EndEffectorVSCube_v2_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_EndEffectorVSCube_v2_get_check_sum(mxArray *plhs[]);
          sf_c4_EndEffectorVSCube_v2_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_EndEffectorVSCube_v2_get_check_sum(mxArray *plhs[]);
          sf_c6_EndEffectorVSCube_v2_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_EndEffectorVSCube_v2_get_check_sum(mxArray *plhs[]);
          sf_c7_EndEffectorVSCube_v2_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_EndEffectorVSCube_v2_get_check_sum(mxArray *plhs[]);
          sf_c8_EndEffectorVSCube_v2_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_EndEffectorVSCube_v2_get_check_sum(mxArray *plhs[]);
          sf_c10_EndEffectorVSCube_v2_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_EndEffectorVSCube_v2_get_check_sum(mxArray *plhs[]);
          sf_c11_EndEffectorVSCube_v2_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_EndEffectorVSCube_v2_get_check_sum(mxArray *plhs[]);
          sf_c12_EndEffectorVSCube_v2_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_EndEffectorVSCube_v2_get_check_sum(mxArray *plhs[]);
          sf_c13_EndEffectorVSCube_v2_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_EndEffectorVSCube_v2_get_check_sum(mxArray *plhs[]);
          sf_c14_EndEffectorVSCube_v2_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3564696471U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(678668628U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1090454852U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3896867807U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3543500750U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3288453336U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(87194578U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(296095060U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_EndEffectorVSCube_v2_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "zEFfBXs7DgDIHR8btFLu4C") == 0) {
          extern mxArray *sf_c1_EndEffectorVSCube_v2_get_autoinheritance_info
            (void);
          plhs[0] = sf_c1_EndEffectorVSCube_v2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "BhsEsOF5yilbgdXwWeNFWC") == 0) {
          extern mxArray *sf_c2_EndEffectorVSCube_v2_get_autoinheritance_info
            (void);
          plhs[0] = sf_c2_EndEffectorVSCube_v2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "6Xdo2sLtvOCcPP6lS4BQ9D") == 0) {
          extern mxArray *sf_c3_EndEffectorVSCube_v2_get_autoinheritance_info
            (void);
          plhs[0] = sf_c3_EndEffectorVSCube_v2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "Zwjh9nxtouEmxdwCJjIeO") == 0) {
          extern mxArray *sf_c4_EndEffectorVSCube_v2_get_autoinheritance_info
            (void);
          plhs[0] = sf_c4_EndEffectorVSCube_v2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "J7fND3jtJnJYgvlO1lXaWD") == 0) {
          extern mxArray *sf_c6_EndEffectorVSCube_v2_get_autoinheritance_info
            (void);
          plhs[0] = sf_c6_EndEffectorVSCube_v2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "J7fND3jtJnJYgvlO1lXaWD") == 0) {
          extern mxArray *sf_c7_EndEffectorVSCube_v2_get_autoinheritance_info
            (void);
          plhs[0] = sf_c7_EndEffectorVSCube_v2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "6Xdo2sLtvOCcPP6lS4BQ9D") == 0) {
          extern mxArray *sf_c8_EndEffectorVSCube_v2_get_autoinheritance_info
            (void);
          plhs[0] = sf_c8_EndEffectorVSCube_v2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "wryUZp3f619imD943iLc8") == 0) {
          extern mxArray *sf_c10_EndEffectorVSCube_v2_get_autoinheritance_info
            (void);
          plhs[0] = sf_c10_EndEffectorVSCube_v2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "p9LCBntkNywvtnolqv8NMH") == 0) {
          extern mxArray *sf_c11_EndEffectorVSCube_v2_get_autoinheritance_info
            (void);
          plhs[0] = sf_c11_EndEffectorVSCube_v2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "r084EQARoOj782WfPmI5bF") == 0) {
          extern mxArray *sf_c12_EndEffectorVSCube_v2_get_autoinheritance_info
            (void);
          plhs[0] = sf_c12_EndEffectorVSCube_v2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "biOOrcbGsRvbxTyr5fprID") == 0) {
          extern mxArray *sf_c13_EndEffectorVSCube_v2_get_autoinheritance_info
            (void);
          plhs[0] = sf_c13_EndEffectorVSCube_v2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "6Xdo2sLtvOCcPP6lS4BQ9D") == 0) {
          extern mxArray *sf_c14_EndEffectorVSCube_v2_get_autoinheritance_info
            (void);
          plhs[0] = sf_c14_EndEffectorVSCube_v2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_EndEffectorVSCube_v2_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_EndEffectorVSCube_v2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_EndEffectorVSCube_v2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_EndEffectorVSCube_v2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_EndEffectorVSCube_v2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_EndEffectorVSCube_v2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_EndEffectorVSCube_v2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_EndEffectorVSCube_v2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_EndEffectorVSCube_v2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_EndEffectorVSCube_v2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_EndEffectorVSCube_v2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_EndEffectorVSCube_v2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_EndEffectorVSCube_v2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_EndEffectorVSCube_v2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_EndEffectorVSCube_v2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_EndEffectorVSCube_v2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_EndEffectorVSCube_v2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_EndEffectorVSCube_v2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_EndEffectorVSCube_v2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_EndEffectorVSCube_v2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_EndEffectorVSCube_v2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_EndEffectorVSCube_v2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_EndEffectorVSCube_v2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray
          *sf_c14_EndEffectorVSCube_v2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_EndEffectorVSCube_v2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_EndEffectorVSCube_v2_third_party_uses_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "TKz7UhtsYvVT15jCWqRNJF") == 0) {
          extern mxArray *sf_c1_EndEffectorVSCube_v2_third_party_uses_info(void);
          plhs[0] = sf_c1_EndEffectorVSCube_v2_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "Wu5mA16AQmqJHQLyjtsNnB") == 0) {
          extern mxArray *sf_c2_EndEffectorVSCube_v2_third_party_uses_info(void);
          plhs[0] = sf_c2_EndEffectorVSCube_v2_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "5W4FjGfBE5tqQobLwG22fF") == 0) {
          extern mxArray *sf_c3_EndEffectorVSCube_v2_third_party_uses_info(void);
          plhs[0] = sf_c3_EndEffectorVSCube_v2_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "52Mvmm1cYof6QU7RlINbJB") == 0) {
          extern mxArray *sf_c4_EndEffectorVSCube_v2_third_party_uses_info(void);
          plhs[0] = sf_c4_EndEffectorVSCube_v2_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "TP6KGzK2yMvL1qHWDP9KUH") == 0) {
          extern mxArray *sf_c6_EndEffectorVSCube_v2_third_party_uses_info(void);
          plhs[0] = sf_c6_EndEffectorVSCube_v2_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "TP6KGzK2yMvL1qHWDP9KUH") == 0) {
          extern mxArray *sf_c7_EndEffectorVSCube_v2_third_party_uses_info(void);
          plhs[0] = sf_c7_EndEffectorVSCube_v2_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "5W4FjGfBE5tqQobLwG22fF") == 0) {
          extern mxArray *sf_c8_EndEffectorVSCube_v2_third_party_uses_info(void);
          plhs[0] = sf_c8_EndEffectorVSCube_v2_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "pC5XaSMGKVuBCHOjpNEGiC") == 0) {
          extern mxArray *sf_c10_EndEffectorVSCube_v2_third_party_uses_info(void);
          plhs[0] = sf_c10_EndEffectorVSCube_v2_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "5S6PX6llcflD7hqYRl0IcG") == 0) {
          extern mxArray *sf_c11_EndEffectorVSCube_v2_third_party_uses_info(void);
          plhs[0] = sf_c11_EndEffectorVSCube_v2_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "99TOJTrZin4YfB4OZhY3bE") == 0) {
          extern mxArray *sf_c12_EndEffectorVSCube_v2_third_party_uses_info(void);
          plhs[0] = sf_c12_EndEffectorVSCube_v2_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "GZnyPbzPZdwNCrjGfpQrwC") == 0) {
          extern mxArray *sf_c13_EndEffectorVSCube_v2_third_party_uses_info(void);
          plhs[0] = sf_c13_EndEffectorVSCube_v2_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "5W4FjGfBE5tqQobLwG22fF") == 0) {
          extern mxArray *sf_c14_EndEffectorVSCube_v2_third_party_uses_info(void);
          plhs[0] = sf_c14_EndEffectorVSCube_v2_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void EndEffectorVSCube_v2_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _EndEffectorVSCube_v2MachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"EndEffectorVSCube_v2","sfun",0,12,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _EndEffectorVSCube_v2MachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _EndEffectorVSCube_v2MachineNumber_,0);
}

void EndEffectorVSCube_v2_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_EndEffectorVSCube_v2_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "EndEffectorVSCube_v2", "EndEffectorVSCube_v2");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_EndEffectorVSCube_v2_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
