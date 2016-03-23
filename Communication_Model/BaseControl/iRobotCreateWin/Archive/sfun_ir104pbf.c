/**************************************************************************
 *  Gateway S-Function between Simulink and C Code to enable              *
 *  input/output operations of the Diamond IR-104-PBF Relay Board         *
 *                                                                        *
 *  Jason Hall, Riccardo Bevilacqua, Jim Horning                          *
 *  Spacecraft Robotics Laboratory                                        *
 *  Naval Postgraduate School, Monterey, CA                               *
 *  September 2008                                                        *
 *************************************************************************/

#define         S_FUNCTION_LEVEL    2
#undef          S_FUNCTION_NAME
#define         S_FUNCTION_NAME     sfun_ir104pbf

#include        <stddef.h>
#include        <stdlib.h>
#include        "simstruc.h" 
#include        <stdio.h>
#ifdef __linux
#include        <unistd.h>
#include        <sys/io.h> /* for glibc */
#endif

#ifdef          MATLAB_MEX_FILE
#include        "mex.h"
#endif


/* Input Arguments */
#define NUMBER_OF_ARGS          (5)
#define CHANNEL_ARG             ssGetSFcnParam(S,0)
#define RESET_ARG               ssGetSFcnParam(S,1)
#define INIT_VAL_ARG            ssGetSFcnParam(S,2)
#define SAMP_TIME_ARG           ssGetSFcnParam(S,3)
#define BASE_ARG                ssGetSFcnParam(S,4)

#define SAMP_TIME_IND           (0)
#define BASE_ADDR_IND           (0)            

#define NO_I_WORKS              (0)
#define NO_R_WORKS              (0)
#define THRESHOLD               0.5

static char_T msg[256];

#ifdef __linux__
void relay(unsigned int relay_mask, unsigned int base)
{
    int i;

    for (i = 0; i < 3; i++)
       outb((relay_mask>>8*i)&0x000000FF, base+i);
}
#endif


static void mdlInitializeSizes(SimStruct *S)
{

    int i;


    ssSetNumSFcnParams(S, NUMBER_OF_ARGS);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        sprintf(msg,"%d input args expected, %d passed", NUMBER_OF_ARGS, ssGetSFcnParamsCount(S));
        ssSetErrorStatus(S,msg);
        return;
    }

    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);

    ssSetNumInputPorts(S, mxGetN(CHANNEL_ARG));
    for (i=0;i<mxGetN(CHANNEL_ARG);i++) {
        ssSetInputPortWidth(S, i, 1);
        ssSetInputPortDirectFeedThrough(S, i, 1);
    }

    ssSetNumOutputPorts(S, 0);

    ssSetNumSampleTimes(S, 1);

    ssSetNumRWork(S, NO_R_WORKS);
    ssSetNumIWork(S, NO_I_WORKS);
    ssSetNumPWork(S, 0);

    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);

    for( i = 0 ; i < NUMBER_OF_ARGS ; i++ )
    {
        ssSetSFcnParamTunable(S,i,0);  /* None of the parameters are tunable */
    }

    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE | SS_OPTION_PLACE_ASAP);
}
 
static void mdlInitializeSampleTimes(SimStruct *S)
{
    if (mxGetPr(SAMP_TIME_ARG)[0]==-1.0)
    {
        ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
        ssSetOffsetTime(S, 0, FIXED_IN_MINOR_STEP_OFFSET);
    }
    else
    {
        ssSetSampleTime(S, 0, mxGetPr(SAMP_TIME_ARG)[0]);
        ssSetOffsetTime(S, 0, 0.0);
    }
}
 
#define MDL_START
static void mdlStart(SimStruct *S)
{
    int_T num_channels, base, i, channel, relay_mask;
         
    num_channels = mxGetN(CHANNEL_ARG);
    base=(int_T)mxGetPr(BASE_ARG)[0];

#ifdef __linux__
    if (ioperm(base, 3, 1) != 0)
    {
       return;
    }

    for (relay_mask = 0, i=0; i < num_channels; i++)
    {
        if ((uint_T)mxGetPr(INIT_VAL_ARG)[i])
        {
            channel=mxGetPr(CHANNEL_ARG)[i]-1;
            relay_mask |= 1 << channel;
        }
    }
    relay(relay_mask, base);
#endif
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
    int_T num_channels, base, i, channel, relay_mask;
    InputRealPtrsType uPtrs;
          
    num_channels = mxGetN(CHANNEL_ARG);
    base = (int_T)mxGetPr(BASE_ARG)[0];
    
    for (relay_mask = 0, i=0; i < num_channels; i++)
    {
        channel = mxGetPr(CHANNEL_ARG)[i]-1;
        uPtrs = ssGetInputPortRealSignalPtrs(S,i);
        if (*uPtrs[0]>=0.5)
            relay_mask |= 1 << channel;
    }
#ifdef __linux__
    relay(relay_mask, base);
#endif
}

static void mdlTerminate(SimStruct *S)
{
    int_T num_channels, base, i, channel, relay_mask;
          
    num_channels = mxGetN(CHANNEL_ARG);
    base = (int_T)mxGetPr(BASE_ARG)[0];
    
    /* At load time, set channels to their initial values.
     At model termination, reset resettable channels to their initial values.*/

    for (relay_mask = 0, i=0; i < num_channels; i++)
    {
        if ((uint_T)mxGetPr(RESET_ARG)[i])
        {
            channel=mxGetPr(CHANNEL_ARG)[i]-1;
            relay_mask |= 1 << channel;
        }
    }
#ifdef __linux__
    relay(relay_mask, base);
    
    if (ioperm(base, 3, 0) != 0)
        return;
#endif
}

#ifdef MATLAB_MEX_FILE  /* Is this file being compiled as a MEX-file? */
#include "simulink.c"   /* Mex glue */
#else
#include "cg_sfun.h"    /* Code generation glue */
#endif
