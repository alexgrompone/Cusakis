/**************************************************************************
 *  Gateway S-Function between Simulink and C Code to enable              *
 *  RS-232 interface to command the iRobot Create                                                                    *
 *                                                                        *
 *  Alessio Grompone, Octavio Perez                                                      *
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
#define NO_INPUTS               (2) /* number of inputs */

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
        
        /* Output Ports */
        ssSetNumOutputPorts(S, NO_OUTPUTS);
        /* Output Port 1 */
        ssSetOutputPortWidth(S, 0, 1);
        ssSetOutputPortDataType(S, 0, SS_INT32);
        /* Output Port 2 */
        ssSetOutputPortWidth(S, 1, 1);
        ssSetOutputPortDataType(S, 1, SS_INT32);
        /* Output Port 3 */
       // ssSetOutputPortWidth(S, 2, 1);
       // ssSetOutputPortDataType(S, 2, SS_INT32);

        
        
        /* Input Ports */
        ssSetNumInputPorts(S, NO_INPUTS);
        /* Input Port1 */
        ssSetInputPortWidth(S,0,1);
        ssSetInputPortDirectFeedThrough(S,0,1);
        /* Input Port2 */
        ssSetInputPortWidth(S,1,1);
        ssSetInputPortDirectFeedThrough(S,1,1);
  

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
    int command_p1;
    int restime1;
    
    //int selectmotor;
    
    /* Pointer Command Variables */
    InputRealPtrsType pcommand_p1;
    InputRealPtrsType prestime1;
    
   
    
    /* Command Strings */
    char comstring1[20];
    char current1[10];
    char resetcomm[10];
    
    /* Buf Strings */
    char buf1[20];
     char err1[20];
    

    /* Flag_position Variables */
    int flag_position1;
    
    /* Position Variables */
    int position1;
  
    //double position1;
   
    
    /* line strings */
   static char line1[40];

    /* r,i,t_wait index */
    int r;

    int i;

//     int lc;
 int t_wait1 = 2500;                /* waiting time for motor 1 */

    
    /* Request Position Strings */
    char reqposition1[10];
    
    /*my attempt to read encoder*/
    char str[50];

    
    /* Serial port Outputs */
    //real_T *posout1 = (real_T *)(ssGetOutputPortSignal(S,0));
    
    int_T *posout1 = (int_T *)(ssGetOutputPortSignal(S,0));
    int_T *pos_flag1 = (int_T *)(ssGetOutputPortSignal(S,1));
 //   int_T *mot_num = (int_T *)(ssGetOutputPortSignal(S,2));   /* sending the motor number */
    
    
    /* Sizes */
    size_t l1; 
    size_t l1_r;
    size_t nbytes1;
    size_t nbytes1_r;
    ssize_t bytes_written1;
    ssize_t bytes_written1_r;

    
  
    /* Get the Input Command for motor 1 */
    pcommand_p1 = ssGetInputPortRealSignalPtrs(S,0);    
    command_p1 = *pcommand_p1[0];
    prestime1 = ssGetInputPortRealSignalPtrs(S,1);    
    restime1 = *prestime1[0];
    
    
    if (rs232ports[port])
    {
#ifndef _WIN32



    /* Combine the Command String 1 */
    
    
    strcpy(comstring1,"/1");            /* address of motor 1 */
   
    if (restime1>0)
    {
     sprintf(resetcomm,"%d",restime1);    
     strcat(comstring1,"z");           /* Reset to zero position */
     strcat(comstring1,resetcomm); 
    }          
    else if (command_p1<0)
    {  
    sprintf(current1,"%d",-command_p1);
    strcat(comstring1,"h");            /* Endless relative motion in negative direction */
    strcat(comstring1,current1); 
    strcat(comstring1,"D0");
    } 
    else 
    {
     sprintf(current1,"%d",command_p1);    
     strcat(comstring1,"h");           /* Endless relative motion in positive direction */
     strcat(comstring1,current1);
     strcat(comstring1,"P0");
    }



    
   //printf("\n Command motor 1 : %d \n", command_p1);
    
    strcat(comstring1,"R");             /* Run the string */
    l1 = strlen(comstring1);
    
    
    /* Send Command to the Motor 1 */
    

    comstring1[l1] = '\n';              /* new line */
    comstring1[l1+1] = '\r';            /* carriage return : the string is complete and should be parsed */
    
    nbytes1 = strlen(comstring1);
    
    bytes_written1 = write(fh, comstring1, nbytes1);

    
  usleep(t_wait1);//
    
//    printf("\n command di 1 d is : %d \n", comstring1);
   //printf("\n command di 1 f is : %f \n", comstring1);
 //  printf("\n command di 1 s is : %s \n", comstring1);
    

    /* *********** First Req Position ************* */

     
    strcpy(reqposition1,"/1?8");                   /* '?8' allow to request immediately the position */
    
    l1_r = strlen(reqposition1);

    reqposition1[l1_r+1] = '\n';
    reqposition1[l1_r+2] = '\r';

    nbytes1_r = strlen(reqposition1);
  
    bytes_written1_r = write(fh, reqposition1, nbytes1_r+3);
    
   // printf("\n request command is : %s \n", reqposition1); 
    /* wait before read from serial port */
   
    
   usleep(t_wait1);//

    /* ******** Read From Serial Port 1 *********** */

    r = read(fh, line1, sizeof(line1));
    //printf("\n feedback= %c \n", line1);
   /* read the answer */ 
    //sscanf(line1,"%s %s",err1,buf1);
   sscanf(line1,"%s",buf1);
    /* keep just the numbers */
    
   for( i=0 ; i<4 ; i++)    {buf1[i] = ' ';}
    //     buf1[strlen(buf1)-1] = ' '; 
    
    flag_position1=sscanf(buf1,"%d",&position1); //d
  

    if (flag_position1 == 1)            /* good sscanf */
    {
        *posout1 = position1;
        *pos_flag1 = flag_position1;
    }
    else                                /* bad sscanf */
    {
        *posout1 = position1;
        *pos_flag1 = 0;
    }
    
    
   printf("\n position of motor 1 is : %s \n", buf1);
  //printf("\n octavio suggests: %s %s \n",err1,buf1);          
   
//    r = read(fh, line1c, sizeof(line1c));
     
   /* read the answer */ 
    
// usleep(t_wait1);// no use
  #endif
    }
}

/* Termination */    

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
    
    strcpy(final1,"/1T\n\r");
    
    bytes_final1 = strlen(final1);
    
    final_written1 = write(fh, final1, bytes_final1);
    
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
