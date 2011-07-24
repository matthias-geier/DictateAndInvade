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
	${OBJECTDIR}/sqlite3_framework.o \
	${OBJECTDIR}/buildings.o \
	${OBJECTDIR}/linked_list.o \
	${OBJECTDIR}/core.o


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
LDLIBSOPTIONS=../sqlite3/dist/Release/GNU-Linux-x86/libsqlite3.so

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libfunction_API.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libfunction_API.so: ../sqlite3/dist/Release/GNU-Linux-x86/libsqlite3.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libfunction_API.so: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -shared -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libfunction_API.so -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/sqlite3_framework.o: sqlite3_framework.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -O2 -I. -I../sqlite3 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/sqlite3_framework.o sqlite3_framework.c

${OBJECTDIR}/buildings.o: buildings.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -O2 -I. -I../sqlite3 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/buildings.o buildings.c

${OBJECTDIR}/linked_list.o: linked_list.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -O2 -I. -I../sqlite3 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/linked_list.o linked_list.c

${OBJECTDIR}/core.o: core.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -O2 -I. -I../sqlite3 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/core.o core.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libfunction_API.so

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
