/**************************************************************************
 *  Gateway S-Function between Simulink and C Code to enable              *
 *  RS-232 interface to command the iRobot Create                                                                    *
 *                                                                        *
 *  Alessio Grompone,                                                      *
 *  Spacecraft Robotics Laboratory                                        *
 *  Naval Postgraduate School, Monterey, CA                               *
 *  January 2014                                                          *
 *                                                                        *
 *  Based on the program developed on September 2008 by                   *
 *  Simone Chesi and Veronica Pellegrini  
 *                                                                        *
 *************************************************************************/


#define         S_FUNCTION_LEVEL        2
#undef          S_FUNCTION_NAME
#define         S_FUNCTION_NAME         create1

#include        <stdio.h>
#include        <string.h>
#include        <math.h>
#include        <stdlib.h>
#include        "simstruc.h"
#ifdef          __linux
#include        "rs232com.c"            /* rs232 communication c code*/
#endif

#ifdef MATLAB_MEX_FILE
#include "mex.h"
#endif

/* Input Arguments */
#define NUMBER_OF_ARGS        	(6)
#define PORT_ARG             	ssGetSFcnParam(S,0)
#define BAUDRATE_ARG 	        ssGetSFcnParam(S,1)
#define DATABIT_ARG           	ssGetSFcnParam(S,2)
#define STOPBIT_ARG             ssGetSFcnParam(S,3)
#define PARITY_ARG 	            ssGetSFcnParam(S,4)
#define SAMPTIME_ARG           	ssGetSFcnParam(S,5)

#define NO_I_WORKS              (6) /* number of integer work variables */
#define NO_R_WORKS              (1) /* number of real work variables */
#define NO_P_WORKS              (6) /* number of pointer work variables */
#define NO_D_WORKS              (0) 
#define NO_M_WORKS              (0) /* number of mode work vector elements */
#define NO_OUTPUTS              (2) /* number of outputs */
#define NO_INPUTS               (4) /* number of inputs */

#define PORT_WIDTH              ((int_T)mxGetPr(RECBUF_ARG)[0])


static char_T msg[256];
static int rs232ports[8]={0,0,0,0,0,0,0,0};

static void mdlInitializeSizes(SimStruct *S)
{
        ssSetNumSFcnParams(S, NUMBER_OF_ARGS);  /* Number of expected parameters */
        if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
            sprintf(msg,"Wrong number of input arguments passed.\n"
                    "%d arguments are expected\n", NUMBER_OF_ARGS);
            ssSetErrorStatus(S,msg);
            return;
        }
        
        /* Set-up size information */
        ssSetNumContStates(S, 0);
        ssSetNumDiscStates(S, 0);
        
        ssSetNumOutputPorts(S, NO_OUTPUTS);
                /* Output Port 1 */
        ssSetOutputPortWidth(S, 0, 1);
        ssSetOutputPortDataType(S, 0, SS_INT32);
        /* Output Port 2 */
        ssSetOutputPortWidth(S, 1, 1);
        ssSetOutputPortDataType(S, 1, SS_INT32);
        
        
        /* Input Ports */
        ssSetNumInputPorts(S, NO_INPUTS);
        /* Input Port1 */
        ssSetInputPortWidth(S,0,1);
        ssSetInputPortDirectFeedThrough(S,0,1);
        /* Input Port2 */
        ssSetInputPortWidth(S,1,1);
        ssSetInputPortDirectFeedThrough(S,1,1);
          /* Input Port3 */
        ssSetInputPortWidth(S,2,1);
        ssSetInputPortDirectFeedThrough(S,2,1);
        /* Input Port4 */
        ssSetInputPortWidth(S,3,1);
        ssSetInputPortDirectFeedThrough(S,3,1);
        

        /* Number of Sample Time */
        ssSetNumSampleTimes(S, 1);
        
        /* Define the Variables */
        ssSetNumRWork(S, NO_R_WORKS);
        ssSetNumIWork(S, NO_I_WORKS);
        ssSetNumPWork(S, NO_P_WORKS);
        ssSetNumDWork(S, NO_D_WORKS);
        
        ssSetNumModes(S, 0);   
        ssSetNumNonsampledZCs(S, 0);      /* number of nonsampled zero crossings   */
        
        ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE | SS_OPTION_PLACE_ASAP);
}
 

/* Initialize Sample Time */

static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, mxGetPr(SAMPTIME_ARG)[0]);
    ssSetOffsetTime(S, 0, 0.0);
}


/* Define and Open the Serial Port */

#define MDL_START
static void mdlStart(SimStruct * S)
{      
    int baudrates[]={115200,57600,38400,19200,9600,4800,2400,1200,300,110};
    int fh, port, baudrate, databits, stopbits, parity;
    
    port = ((int_T)mxGetPr(PORT_ARG)[0])+3;
    baudrate = baudrates[((int_T)mxGetPr(BAUDRATE_ARG)[0])-1];
    databits = 9-((int_T)mxGetPr(DATABIT_ARG)[0]);
    stopbits = (int_T)mxGetPr(STOPBIT_ARG)[0];
    parity = ((int_T)mxGetPr(PARITY_ARG)[0])-1;
#ifdef __linux__
    fh = rs232open(port, baudrate, databits, stopbits, parity);
#endif
    ssSetIWorkValue(S, 0, fh);
    ssSetIWorkValue(S, 1, port);
    rs232ports[port] = 1;  
}




/* Outputs Computing */

static void mdlOutputs(SimStruct *S, int_T tid)
{
    int fh = ssGetIWorkValue(S, 0);
    int port = ssGetIWorkValue(S, 1);
    
    /* Command Position Variables */
    int highleft;
    int lowleft;
    int highright;
    int lowright; 

    //int selectmotor;
    
    /* Pointer Command Variables */
    InputRealPtrsType phighleft;
    InputRealPtrsType plowleft;
    InputRealPtrsType phighright;
    InputRealPtrsType plowright;
   

    /* Buf Strings */
    char buf1[20];
    char err1[20];
    int t_wait1 = 25000;
    
    /* Sizes */
    size_t l1; 
    size_t l2; 
    size_t nbytes1;
    size_t nbytes2;
   

    /* Get the Input Command for motor 1 */
    phighleft = ssGetInputPortRealSignalPtrs(S,0);    
    highleft = *phighleft[0]; 
    plowleft = ssGetInputPortRealSignalPtrs(S,1);    
    lowleft = *plowleft[0];
    phighright = ssGetInputPortRealSignalPtrs(S,2);    
    highright = *phighright[0];
    plowright = ssGetInputPortRealSignalPtrs(S,3);    
    lowright = *plowright[0];
    
    
    unsigned char cmd[]={128,131};
    unsigned char cmd2[]={145,highright,lowright,highleft,lowleft};
    
    
    if (rs232ports[port])
    {
#ifndef _WIN32

    /* Combine the Command String 1 */
    
   int bytes_written1 = write(fh, cmd, 7);
    
 usleep(t_wait1);//  

   int bytes_written2 = write(fh, cmd2, 5);
   
#endif
    }
} 

    
   static void mdlTerminate(SimStruct *S)
{    
    int fh = ssGetIWorkValue(S, 0);
    int port = ssGetIWorkValue(S, 1);
   // int selectmotor1;
    char final1 [20];  
    size_t bytes_final1;

    ssize_t final_written1;
int t_wait = 1000;           /* Common stopping time */ 
    /* Stopping motor 1 */
    
//     strcpy(final1,"/1T\n\r");
    
//     bytes_final1 = strlen(final1);
//     
//     final_written1 = write(fh, final1, bytes_final1);
    
// usleep(t_wait);
 
#ifndef _WIN32
    if (!close(fh))
    {
        fflush(stdout);
        rs232ports[port] = 0;
    }
#endif
}


#ifdef	MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif
