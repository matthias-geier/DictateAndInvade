#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/lua_framwork_lib.o \
	${OBJECTDIR}/lua_transform_array.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=../function_API/dist/Release/GNU-Linux-x86/libfunction_API.so ../lua_static/liblua.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblua_framework.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblua_framework.so: ../function_API/dist/Release/GNU-Linux-x86/libfunction_API.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblua_framework.so: ../lua_static/liblua.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblua_framework.so: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -ldl -shared -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblua_framework.so -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/lua_framwork_lib.o: lua_framwork_lib.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -O2 -I. -I../function_API -I../lua_static -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua_framwork_lib.o lua_framwork_lib.c

${OBJECTDIR}/lua_transform_array.o: lua_transform_array.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -O2 -I. -I../function_API -I../lua_static -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/lua_transform_array.o lua_transform_array.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblua_framework.so

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
