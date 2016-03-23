/* Include files */

#include "Final_Project_v3c_sfun.h"
#include "Final_Project_v3c_sfun_debug_macros.h"
#include "c1_Final_Project_v3c.h"
#include "c2_Final_Project_v3c.h"
#include "c3_Final_Project_v3c.h"
#include "c4_Final_Project_v3c.h"
#include "c5_Final_Project_v3c.h"
#include "c6_Final_Project_v3c.h"
#include "c7_Final_Project_v3c.h"
#include "c8_Final_Project_v3c.h"
#include "c9_Final_Project_v3c.h"
#include "c10_Final_Project_v3c.h"
#include "c11_Final_Project_v3c.h"
#include "c12_Final_Project_v3c.h"
#include "c13_Final_Project_v3c.h"
#include "c14_Final_Project_v3c.h"
#include "c15_Final_Project_v3c.h"
#include "c16_Final_Project_v3c.h"
#include "c17_Final_Project_v3c.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Final_Project_v3cMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void Final_Project_v3c_initializer(void)
{
}

void Final_Project_v3c_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Final_Project_v3c_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_Final_Project_v3c_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_Final_Project_v3c_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_Final_Project_v3c_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_Final_Project_v3c_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_Final_Project_v3c_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_Final_Project_v3c_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_Final_Project_v3c_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_Final_Project_v3c_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_Final_Project_v3c_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_Final_Project_v3c_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_Final_Project_v3c_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_Final_Project_v3c_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_Final_Project_v3c_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_Final_Project_v3c_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_Final_Project_v3c_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_Final_Project_v3c_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_Final_Project_v3c_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_Final_Project_v3c_process_check_sum_call( int nlhs, mxArray *
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2658958503U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2522646768U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1161394237U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(240544826U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3880613497U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(764966748U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1057030321U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2960524448U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_Final_Project_v3c_get_check_sum(mxArray *plhs[]);
          sf_c1_Final_Project_v3c_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_Final_Project_v3c_get_check_sum(mxArray *plhs[]);
          sf_c2_Final_Project_v3c_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_Final_Project_v3c_get_check_sum(mxArray *plhs[]);
          sf_c3_Final_Project_v3c_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_Final_Project_v3c_get_check_sum(mxArray *plhs[]);
          sf_c4_Final_Project_v3c_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_Final_Project_v3c_get_check_sum(mxArray *plhs[]);
          sf_c5_Final_Project_v3c_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_Final_Project_v3c_get_check_sum(mxArray *plhs[]);
          sf_c6_Final_Project_v3c_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_Final_Project_v3c_get_check_sum(mxArray *plhs[]);
          sf_c7_Final_Project_v3c_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_Final_Project_v3c_get_check_sum(mxArray *plhs[]);
          sf_c8_Final_Project_v3c_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_Final_Project_v3c_get_check_sum(mxArray *plhs[]);
          sf_c9_Final_Project_v3c_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_Final_Project_v3c_get_check_sum(mxArray *plhs[]);
          sf_c10_Final_Project_v3c_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_Final_Project_v3c_get_check_sum(mxArray *plhs[]);
          sf_c11_Final_Project_v3c_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_Final_Project_v3c_get_check_sum(mxArray *plhs[]);
          sf_c12_Final_Project_v3c_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_Final_Project_v3c_get_check_sum(mxArray *plhs[]);
          sf_c13_Final_Project_v3c_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_Final_Project_v3c_get_check_sum(mxArray *plhs[]);
          sf_c14_Final_Project_v3c_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_Final_Project_v3c_get_check_sum(mxArray *plhs[]);
          sf_c15_Final_Project_v3c_get_check_sum(plhs);
          break;
        }

       case 16:
        {
          extern void sf_c16_Final_Project_v3c_get_check_sum(mxArray *plhs[]);
          sf_c16_Final_Project_v3c_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_Final_Project_v3c_get_check_sum(mxArray *plhs[]);
          sf_c17_Final_Project_v3c_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3516254429U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1645684536U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3452337497U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3527496581U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Final_Project_v3c_autoinheritance_info( int nlhs, mxArray *
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
        if (strcmp(aiChksum, "RJe3UHVmsmgoRfSj8DblbG") == 0) {
          extern mxArray *sf_c1_Final_Project_v3c_get_autoinheritance_info(void);
          plhs[0] = sf_c1_Final_Project_v3c_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "4x3KfHmyheDG6DcQf7gdxG") == 0) {
          extern mxArray *sf_c2_Final_Project_v3c_get_autoinheritance_info(void);
          plhs[0] = sf_c2_Final_Project_v3c_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "RJe3UHVmsmgoRfSj8DblbG") == 0) {
          extern mxArray *sf_c3_Final_Project_v3c_get_autoinheritance_info(void);
          plhs[0] = sf_c3_Final_Project_v3c_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "sNQz0rVOSCc44rkQK4rDUE") == 0) {
          extern mxArray *sf_c4_Final_Project_v3c_get_autoinheritance_info(void);
          plhs[0] = sf_c4_Final_Project_v3c_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "TW8t40PgRuQAkAMgWLb6cF") == 0) {
          extern mxArray *sf_c5_Final_Project_v3c_get_autoinheritance_info(void);
          plhs[0] = sf_c5_Final_Project_v3c_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "Z2djM3VukHfGYv5e8oiPZ") == 0) {
          extern mxArray *sf_c6_Final_Project_v3c_get_autoinheritance_info(void);
          plhs[0] = sf_c6_Final_Project_v3c_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "K60cLzR0YsAVAqBSpmYR7") == 0) {
          extern mxArray *sf_c7_Final_Project_v3c_get_autoinheritance_info(void);
          plhs[0] = sf_c7_Final_Project_v3c_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "JNLGkgXTnpzZbirYeNDGzC") == 0) {
          extern mxArray *sf_c8_Final_Project_v3c_get_autoinheritance_info(void);
          plhs[0] = sf_c8_Final_Project_v3c_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "L0tW3SXnEcC0nHp1Zpqn2F") == 0) {
          extern mxArray *sf_c9_Final_Project_v3c_get_autoinheritance_info(void);
          plhs[0] = sf_c9_Final_Project_v3c_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "Zys44DVuqYjNLhmthvm7NC") == 0) {
          extern mxArray *sf_c10_Final_Project_v3c_get_autoinheritance_info(void);
          plhs[0] = sf_c10_Final_Project_v3c_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "p9LCBntkNywvtnolqv8NMH") == 0) {
          extern mxArray *sf_c11_Final_Project_v3c_get_autoinheritance_info(void);
          plhs[0] = sf_c11_Final_Project_v3c_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "wryUZp3f619imD943iLc8") == 0) {
          extern mxArray *sf_c12_Final_Project_v3c_get_autoinheritance_info(void);
          plhs[0] = sf_c12_Final_Project_v3c_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "QeMGcCE76dxJQQwbQ9On5F") == 0) {
          extern mxArray *sf_c13_Final_Project_v3c_get_autoinheritance_info(void);
          plhs[0] = sf_c13_Final_Project_v3c_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "ZEJ4AuSlTUFbT0q5bqk2SB") == 0) {
          extern mxArray *sf_c14_Final_Project_v3c_get_autoinheritance_info(void);
          plhs[0] = sf_c14_Final_Project_v3c_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "e60V2aNf9Df0MwIwxeDJLB") == 0) {
          extern mxArray *sf_c15_Final_Project_v3c_get_autoinheritance_info(void);
          plhs[0] = sf_c15_Final_Project_v3c_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 16:
      {
        if (strcmp(aiChksum, "Kp1xowPSfXFBuSBkQEcUWE") == 0) {
          extern mxArray *sf_c16_Final_Project_v3c_get_autoinheritance_info(void);
          plhs[0] = sf_c16_Final_Project_v3c_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 17:
      {
        if (strcmp(aiChksum, "GkC8n8AWs2U6BZMv5p3uMB") == 0) {
          extern mxArray *sf_c17_Final_Project_v3c_get_autoinheritance_info(void);
          plhs[0] = sf_c17_Final_Project_v3c_get_autoinheritance_info();
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

unsigned int sf_Final_Project_v3c_get_eml_resolved_functions_info( int nlhs,
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
          *sf_c1_Final_Project_v3c_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_Final_Project_v3c_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_Final_Project_v3c_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_Final_Project_v3c_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_Final_Project_v3c_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_Final_Project_v3c_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_Final_Project_v3c_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_Final_Project_v3c_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_Final_Project_v3c_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_Final_Project_v3c_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_Final_Project_v3c_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_Final_Project_v3c_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_Final_Project_v3c_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_Final_Project_v3c_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_Final_Project_v3c_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_Final_Project_v3c_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_Final_Project_v3c_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_Final_Project_v3c_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_Final_Project_v3c_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_Final_Project_v3c_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_Final_Project_v3c_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_Final_Project_v3c_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_Final_Project_v3c_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_Final_Project_v3c_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_Final_Project_v3c_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_Final_Project_v3c_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray
          *sf_c14_Final_Project_v3c_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_Final_Project_v3c_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray
          *sf_c15_Final_Project_v3c_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_Final_Project_v3c_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray
          *sf_c16_Final_Project_v3c_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_Final_Project_v3c_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray
          *sf_c17_Final_Project_v3c_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_Final_Project_v3c_get_eml_resolved_functions_info();
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

unsigned int sf_Final_Project_v3c_third_party_uses_info( int nlhs, mxArray *
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
        if (strcmp(tpChksum, "8Te0ySh4TOH0jimSK39k5C") == 0) {
          extern mxArray *sf_c1_Final_Project_v3c_third_party_uses_info(void);
          plhs[0] = sf_c1_Final_Project_v3c_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "cFSGGLbeJ0RLuqJ7HWvbJD") == 0) {
          extern mxArray *sf_c2_Final_Project_v3c_third_party_uses_info(void);
          plhs[0] = sf_c2_Final_Project_v3c_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "8Te0ySh4TOH0jimSK39k5C") == 0) {
          extern mxArray *sf_c3_Final_Project_v3c_third_party_uses_info(void);
          plhs[0] = sf_c3_Final_Project_v3c_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "SbA7bWycDUQePX7JgrhD7C") == 0) {
          extern mxArray *sf_c4_Final_Project_v3c_third_party_uses_info(void);
          plhs[0] = sf_c4_Final_Project_v3c_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "Orrps1wqmwSbVoWrbQbME") == 0) {
          extern mxArray *sf_c5_Final_Project_v3c_third_party_uses_info(void);
          plhs[0] = sf_c5_Final_Project_v3c_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "eoXHpL8faFc5uHWrBc2bD") == 0) {
          extern mxArray *sf_c6_Final_Project_v3c_third_party_uses_info(void);
          plhs[0] = sf_c6_Final_Project_v3c_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "x0ZVWwVX8RCRkWGUJ4NAhE") == 0) {
          extern mxArray *sf_c7_Final_Project_v3c_third_party_uses_info(void);
          plhs[0] = sf_c7_Final_Project_v3c_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "PnCXUHacOfFoUt1MyJn0N") == 0) {
          extern mxArray *sf_c8_Final_Project_v3c_third_party_uses_info(void);
          plhs[0] = sf_c8_Final_Project_v3c_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "hmdv1LIlVhhRQYn9BKf5dF") == 0) {
          extern mxArray *sf_c9_Final_Project_v3c_third_party_uses_info(void);
          plhs[0] = sf_c9_Final_Project_v3c_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "EIaBGLVu7V9utDa9XO87vE") == 0) {
          extern mxArray *sf_c10_Final_Project_v3c_third_party_uses_info(void);
          plhs[0] = sf_c10_Final_Project_v3c_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "5S6PX6llcflD7hqYRl0IcG") == 0) {
          extern mxArray *sf_c11_Final_Project_v3c_third_party_uses_info(void);
          plhs[0] = sf_c11_Final_Project_v3c_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "pC5XaSMGKVuBCHOjpNEGiC") == 0) {
          extern mxArray *sf_c12_Final_Project_v3c_third_party_uses_info(void);
          plhs[0] = sf_c12_Final_Project_v3c_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "aHQ8LyJM7EgDZWAk6SYxdD") == 0) {
          extern mxArray *sf_c13_Final_Project_v3c_third_party_uses_info(void);
          plhs[0] = sf_c13_Final_Project_v3c_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "WpsYK5f2xmfeW7REhZBF6G") == 0) {
          extern mxArray *sf_c14_Final_Project_v3c_third_party_uses_info(void);
          plhs[0] = sf_c14_Final_Project_v3c_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "MM66NkKECEwrlZVbIg79EF") == 0) {
          extern mxArray *sf_c15_Final_Project_v3c_third_party_uses_info(void);
          plhs[0] = sf_c15_Final_Project_v3c_third_party_uses_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "boxuTahpCREaBaJNBTeFqH") == 0) {
          extern mxArray *sf_c16_Final_Project_v3c_third_party_uses_info(void);
          plhs[0] = sf_c16_Final_Project_v3c_third_party_uses_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "Kz2xVW8iK0FieuCFKlUlkH") == 0) {
          extern mxArray *sf_c17_Final_Project_v3c_third_party_uses_info(void);
          plhs[0] = sf_c17_Final_Project_v3c_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void Final_Project_v3c_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _Final_Project_v3cMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "Final_Project_v3c","sfun",0,17,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _Final_Project_v3cMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _Final_Project_v3cMachineNumber_,0);
}

void Final_Project_v3c_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Final_Project_v3c_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "Final_Project_v3c", "Final_Project_v3c");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Final_Project_v3c_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
