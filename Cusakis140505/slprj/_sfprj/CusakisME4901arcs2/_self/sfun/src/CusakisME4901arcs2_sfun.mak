# ------------------- Required for MSVC nmake ---------------------------------
# This file should be included at the top of a MAKEFILE as follows:


!include <ntwin32.mak>

MACHINE     = CusakisME4901arcs2
TARGET      = sfun
CHART_SRCS 	= c1_CusakisME4901arcs2.c c2_CusakisME4901arcs2.c c3_CusakisME4901arcs2.c c4_CusakisME4901arcs2.c c5_CusakisME4901arcs2.c c6_CusakisME4901arcs2.c c7_CusakisME4901arcs2.c c8_CusakisME4901arcs2.c c9_CusakisME4901arcs2.c c10_CusakisME4901arcs2.c c11_CusakisME4901arcs2.c c12_CusakisME4901arcs2.c c13_CusakisME4901arcs2.c c14_CusakisME4901arcs2.c c15_CusakisME4901arcs2.c c16_CusakisME4901arcs2.c c17_CusakisME4901arcs2.c c18_CusakisME4901arcs2.c c19_CusakisME4901arcs2.c c20_CusakisME4901arcs2.c c21_CusakisME4901arcs2.c c22_CusakisME4901arcs2.c c23_CusakisME4901arcs2.c c24_CusakisME4901arcs2.c c25_CusakisME4901arcs2.c c26_CusakisME4901arcs2.c c27_CusakisME4901arcs2.c c28_CusakisME4901arcs2.c c29_CusakisME4901arcs2.c c30_CusakisME4901arcs2.c c31_CusakisME4901arcs2.c c32_CusakisME4901arcs2.c c33_CusakisME4901arcs2.c c34_CusakisME4901arcs2.c c35_CusakisME4901arcs2.c
MACHINE_SRC	= CusakisME4901arcs2_sfun.c
MACHINE_REG = CusakisME4901arcs2_sfun_registry.c
MAKEFILE    = CusakisME4901arcs2_sfun.mak
MATLAB_ROOT	= C:\Program Files\MATLAB\R2013a
BUILDARGS   =

#--------------------------- Tool Specifications ------------------------------
#
#
MSVC_ROOT1 = $(MSDEVDIR:SharedIDE=vc)
MSVC_ROOT2 = $(MSVC_ROOT1:SHAREDIDE=vc)
MSVC_ROOT  = $(MSVC_ROOT2:sharedide=vc)

# Compiler tool locations, CC, LD, LIBCMD:
CC     = cl.exe
LD     = link.exe
LIBCMD = lib.exe
#------------------------------ Include/Lib Path ------------------------------

USER_INCLUDES   = 
AUX_INCLUDES   = 
ML_INCLUDES     = /I "C:\Program Files\MATLAB\R2013a\extern\include"
SL_INCLUDES     = /I "C:\Program Files\MATLAB\R2013a\simulink\include"
SF_INCLUDES     = /I "C:\Program Files\MATLAB\R2013a\stateflow\c\mex\include" /I "C:\Program Files\MATLAB\R2013a\stateflow\c\debugger\include"

COMPILER_INCLUDES = /I "$(MSVC_ROOT)\include"

THIRD_PARTY_INCLUDES   = 
INCLUDE_PATH = $(USER_INCLUDES) $(AUX_INCLUDES) $(ML_INCLUDES)\
 $(SL_INCLUDES) $(SF_INCLUDES) $(THIRD_PARTY_INCLUDES)
LIB_PATH     = "$(MSVC_ROOT)\lib"

CFLAGS = /c /Zp8 /GR /W3 /EHs /D_CRT_SECURE_NO_DEPRECATE /D_SCL_SECURE_NO_DEPRECATE /D_SECURE_SCL=0 /DMATLAB_MEX_FILE /nologo /MD 
LDFLAGS = /nologo /MANIFEST /dll /OPT:NOREF /export:mexFunction  
#----------------------------- Source Files -----------------------------------

REQ_SRCS  =  $(MACHINE_SRC) $(MACHINE_REG) $(CHART_SRCS)

USER_ABS_OBJS =

AUX_ABS_OBJS =

REQ_OBJS = $(REQ_SRCS:.cpp=.obj)
REQ_OBJS2 = $(REQ_OBJS:.c=.obj)
OBJS = $(REQ_OBJS2) $(USER_ABS_OBJS) $(AUX_ABS_OBJS)
OBJLIST_FILE = CusakisME4901arcs2_sfun.mol
SFCLIB = "C:\Program Files\MATLAB\R2013a\stateflow\c\mex\lib\win32\sfc_mexmsvc80.lib" "C:\Program Files\MATLAB\R2013a\stateflow\c\debugger\lib\win32\sfc_debugmsvc80.lib" 
AUX_LNK_OBJS =     
USER_LIBS = 
LINK_MACHINE_LIBS = 
BLAS_LIBS = "C:\Program Files\MATLAB\R2013a\extern\lib\win32\microsoft\libmwblas.lib" 
THIRD_PARTY_LIBS = 

#--------------------------------- Rules --------------------------------------

MEX_FILE_NAME_WO_EXT = $(MACHINE)_$(TARGET)
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexw32
MEX_FILE_CSF =
all : $(MEX_FILE_NAME) $(MEX_FILE_CSF)

TMWLIB = "C:\Program Files\MATLAB\R2013a\extern\lib\win32\microsoft\libmx.lib" "C:\Program Files\MATLAB\R2013a\extern\lib\win32\microsoft\libmex.lib" "C:\Program Files\MATLAB\R2013a\extern\lib\win32\microsoft\libmat.lib" "C:\Program Files\MATLAB\R2013a\extern\lib\win32\microsoft\libfixedpoint.lib" "C:\Program Files\MATLAB\R2013a\extern\lib\win32\microsoft\libut.lib" "C:\Program Files\MATLAB\R2013a\extern\lib\win32\microsoft\libmwmathutil.lib" "C:\Program Files\MATLAB\R2013a\extern\lib\win32\microsoft\libemlrt.lib" "C:\Program Files\MATLAB\R2013a\lib\win32\libippmwipt.lib" 

$(MEX_FILE_NAME) : $(MAKEFILE) $(OBJS) $(SFCLIB) $(AUX_LNK_OBJS) $(USER_LIBS) $(THIRD_PARTY_LIBS)
 @echo ### Linking ...
 $(LD) $(LDFLAGS) /OUT:$(MEX_FILE_NAME) /map:"$(MEX_FILE_NAME_WO_EXT).map"\
  $(USER_LIBS) $(SFCLIB) $(AUX_LNK_OBJS)\
  $(TMWLIB) $(LINK_MACHINE_LIBS) $(DSP_LIBS) $(BLAS_LIBS) $(THIRD_PARTY_LIBS)\
  @$(OBJLIST_FILE)
     mt -outputresource:"$(MEX_FILE_NAME);2" -manifest "$(MEX_FILE_NAME).manifest"
	@echo ### Created $@

.c.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

.cpp.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

