/**************************************************************************
 *  Supporting C Code for rs232 communication s-functions for linux that  *
 *  enable rs232 communication architecture in linux.                     *
 *                                                                        *
 *  Jason Hall, Riccardo Bevilacqua, Jim Horning                          *
 *  Spacecraft Robotics Laboratory                                        *
 *  Naval Postgraduate School, Monterey, CA                               *
 *  September 2008                                                        *
 *                                                                        *
 *************************************************************************/

#include    <termios.h>
#include    <unistd.h>
#include    <fcntl.h>
#include    <sys/ioctl.h>
#include    <sys/signal.h>
#include	<sys/wait.h>
#include    <string.h>
#include    <stdio.h>


#define     _POSIX_SOURCE	1

/* 
     CLOCAL  : local connection, no modem contol
     CREAD   : enable receiving characters
     IGNPAR  : ignore bytes with parity errors
     ICRNL   : map CR to NL (otherwise a CR input on the other computer
               will not terminate input)
     otherwise make device raw (no other input processing)
*/

static int rs232open(int port, int baudrate, int databits,
                        int stopbits, int parity)
{
    int fh;
	struct termios oldtio, newtio;
    char portname[20];
    long BAUD, DATABITS, STOPBITS, PARITYON, PARITY;
    
    
    strcpy(portname, "/dev/ttyS");
    switch(port)
    {
        case 4:
        default:
            strcat(portname, "0");  /*COM 1*/
            break;
        case 5:
            strcat(portname, "1");  /*COM 2*/
            break;
        case 6:
            strcat(portname, "6");  /*COM 3*/
            break;
        case 7:
            strcat(portname, "7");  /*COM 4*/
            break;
        case 8:
            strcat(portname, "8");  /*COM 5*/
            break;
        case 9:
            strcat(portname, "9");  /*COM 6*/
            break;
        case 10:
            strcat(portname, "10");  /*COM 7*/
            break;
        case 11:
            strcat(portname, "11");  /*COM 8*/
            break;
    }
    switch (databits)
    {
        case 8:
        default:
            DATABITS = CS8;         /*8 data bits*/
            break;
        case 7:
            DATABITS = CS7;         /*7 data bits*/
            break;
        case 6:
            DATABITS = CS6;         /*6 data bits*/
            break;
        case 5:
            DATABITS = CS5;         /*5 data bits*/
            break;
    }
    switch (stopbits)
    {
       case 1:
       default:
           STOPBITS = 0;            /*1 stop bit*/
           break;
       case 2:
           STOPBITS = CSTOPB;       /*2 stop bits*/
           break;
    }
    switch (parity)
    {
        case 0:
        default:
            PARITYON = 0;       /*none*/
            PARITY = 0;
            break;
        case 1:
            PARITYON = PARENB;  /*enable parity bit*/
            PARITY = PARODD;    /*use odd parity*/
            break;
        case 2:
            PARITYON = PARENB;  /*enable parity bit*/
            PARITY = 0;         /*use even parity*/
            break;
    }
    switch (baudrate)
    {
        case 38400:
        default:
            BAUD = B38400;
            break;
        case 115200:
            BAUD = B115200;
            break;
        case 57600:
            BAUD = B57600;
            break;
        case 19200:
            BAUD = B19200;
            break;
        case 9600:
            BAUD = B9600;
            break;
        case 4800:
            BAUD = B4800;
            break;
        case 2400:
            BAUD = B2400;
            break;
        case 1200:
            BAUD = B1200;
            break;
        case 300:
            BAUD = B300;
            break;
        case 110:
            BAUD = B110;
            break;
    }
    /* Open modem device for reading and writing and not as controlling tty
       because we don't want to get killed if linenoise sends CTRL-C.  Also,
       Non-blocking.
    */
    fh = open(portname,O_RDWR | O_NOCTTY | O_NONBLOCK);
    if(fh == -1)
    {
        return -1; /*Unable to open port*/
    }
    else
    {
        tcgetattr(fh, &oldtio);         /* save current serial port settings */
        memset(&newtio, 0, sizeof(newtio));
        newtio.c_cflag = BAUD | DATABITS | STOPBITS | PARITYON | PARITY | CLOCAL | CREAD;
        newtio.c_iflag = 0;
        newtio.c_oflag = 0;
        newtio.c_lflag = 0;
        newtio.c_cc[VMIN] = 0;
        newtio.c_cc[VTIME] = 0;
        tcflush(fh, TCIOFLUSH);
        tcsetattr(fh, TCSANOW, &newtio);
        if (!tcflush(fh, TCIOFLUSH) & !tcsetattr(fh, TCSANOW, &newtio))
        {
            fflush(stdout);
        }
    }
    return fh;
}


static int is_lf(char *buf)
{
    int i;
    int flag = -1;
    
    
    for (i = strlen(buf)-1; i >= 0; i--)
    {
        if (buf[i] == '\r')
            buf[i] = ' ';
        if (buf[i] == '\n' && flag == -1)
        {
            flag = i;
        }
    }
    return flag;    
}

static void dsp3000read(int fd, char *line, real_T* rateout, real_T* checkflag)
{
	char buf[50];
	static char hold_buf[200] = "";
	static int i = 0, h = 0;
    int r, p, c, flag = 0, flag1;
    static double rate = 0;
    static int check;
    
    r = read(fd, buf, sizeof(buf)-1);
    switch (r)
    {
        case -1:
            flag =  -1;
            break;
            
        case 0:
            flag = 0;
            break;
            
        default:
            buf[r] = 0;
            if ((p = is_lf(buf)) == -1)
            {
                strcat(hold_buf, buf);
                flag =  0;
                break;
            }
            buf[p] = 0;
            
            strcat(hold_buf, buf);
            strcpy(line, hold_buf);
            if (p < r)
            {
                strcpy(hold_buf, &buf[p+1]);
            }
            flag = 1;
            break;
    }
    switch(flag)
        {
            case -1:        /* device error*/
                *rateout = 0;
                *checkflag = -1;
                break;
                
            case 0:         /*no new line data*/
                *rateout = rate;
                *checkflag = 0;
                break;
                
            case 1:         /*new line data*/
                flag1 = sscanf(line,"%lf %d", &rate, &check);
                if (flag1 == 2)  /*good sscanf*/
                {
                    *rateout = rate;
                    *checkflag = check;
                }
                else            /*bad sscanf*/
                {
                    *rateout = rate;
                    *checkflag = 0;
                }
                break;
        }
}


static void magread(int fd, char *line, real_T* angleout, real_T* checkflag)
{
	char buf[50];
	static char hold_buf[200] = "";
	static int i = 0, h = 0, flag = 0, flag1;
    int r, p, c;
    static double angle = 0;

    r = read(fd, buf, sizeof(buf)-1);
    switch (r)
    {
        case -1:
            flag = -1;
            break;
            
        case 0:
            flag = 0;
            break;
            
        default:
            buf[r] = 0;
            for (i = 1; i < r; i++)
            {
                if (buf[i] == 'C' & buf[i-1] == '$')
                {
                    buf[i] = ' ';
                    buf[i-1] = ' ';
                    strcpy(line, buf);
                    flag = 1;
                }
            }
            break;
    }
    /*printf("flag=%d\n", flag);  fflush(stdout);*/
    switch(flag)
        {
            case -1:        /*device error*/
                *angleout = 0;
                *checkflag = -1;
                break;
                
            case 0:         /*no new line data*/
                *angleout = angle;
                *checkflag = 0;
                break;
                
            case 1:         /*new line data*/
                flag1 = sscanf(line,"%lf", &angle);
                if (flag1 == 1)  /*good sscanf*/
                {
                    *angleout = angle;
                    *checkflag = 1;
                }
                else            /*bad sscanf*/
                {
                    *angleout = angle;
                    *checkflag = 0;
                }
                break;
        }
}


static void oceanserverread(int fd, char *line, real_T* chargepercentage, real_T* checkflag)
{
	char buf[50];
	static char hold_buf[200] = "";
	static int i = 0, h = 0, flag = 0, flag1;
    int r, p, c;
    static double chrgpercent = 0;
    

    static int check;

    

    r = read(fd, buf, sizeof(buf));
    switch (r)
    {
        case -1:
            flag = -1;
            break;
            
        case 0:
            flag = 0;
            break;
            
        default:
            buf[r] = 0;
            strcat(hold_buf, buf);
            flag = 1;
            break;
    }
    
   switch(flag)
        {
            case -1:        /*device error*/
                *chargepercentage = 0;
                *checkflag = -1;
                break;
                
            case 0:         /*no new line data*/
                *chargepercentage = chrgpercent;
                *checkflag = 0;
                break;
                
            case 1:         /*new line data*/
                for (i = 1; i < strlen(hold_buf); i++)
                {
                    if (hold_buf[i] == ',' & hold_buf[i-1] == '%')
                    {
                        hold_buf[i-1] = 0;
                        strcpy(line, &hold_buf[i-4]);
                        hold_buf[0] = 0;
                        flag1 = sscanf(line,"%lf", &chrgpercent);
                        if (flag1 == 1)  /*good sscanf*/
                        {
                            *chargepercentage = chrgpercent;
                            *checkflag = 1;
                        }
                        else            /*bad sscanf*/
                        {
                            *chargepercentage = chrgpercent;
                            *checkflag = 0;
                        }
                        return;
                    }                        
                }
                *chargepercentage = chrgpercent;
                *checkflag = 0;
                break;
        }
}

static void ctsstatusread(int fh, int_T* cts_status, int_T* flag)
{
    int status;
    
    int success = ioctl(fh, TIOCMGET, &status);
	if (success == -1) /* bad data */
    {
        *cts_status = 0;
        //ssPrintf("Unable to retrieve COM port status (file handle %d): %s\n", fh, strerror(errno));
        *flag = 0;
        return;
    }
    
    /* good data */
    *flag = 1;
    
    if ((status & TIOCM_CTS) > 0)
        *cts_status = 1;
    else
        *cts_status = 0;
}
