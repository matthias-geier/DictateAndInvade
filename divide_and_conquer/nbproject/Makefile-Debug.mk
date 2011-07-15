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
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o


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
LDLIBSOPTIONS=../function_API/dist/Release/GNU-Linux-x86/libfunction_API.so ../lua_static/liblua.a ../lua_framework/dist/Release/GNU-Linux-x86/liblua_framework.so

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/divide_and_conquer

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/divide_and_conquer: ../function_API/dist/Release/GNU-Linux-x86/libfunction_API.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/divide_and_conquer: ../lua_static/liblua.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/divide_and_conquer: ../lua_framework/dist/Release/GNU-Linux-x86/liblua_framework.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/divide_and_conquer: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	g++ -ldl -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/divide_and_conquer ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/main.o: main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -g -I../function_API -I../lua_static -I../lua_framework -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/divide_and_conquer

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
