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
CND_PLATFORM=MinGW_32-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1065522586/Interface.o \
	${OBJECTDIR}/_ext/1065522586/InterfaceState.o \
	${OBJECTDIR}/_ext/1065522586/MinimalInit.o \
	${OBJECTDIR}/_ext/1065522586/OSVR_PoseCallback.o \
	${OBJECTDIR}/_ext/1065522586/TrackerCallback.o \
	${OBJECTDIR}/_ext/1065522586/TrackerCallbackToJava.o \
	${OBJECTDIR}/_ext/1065522586/osvr_clientkit_ContextWrapper.o \
	${OBJECTDIR}/_ext/1065522586/osvr_util_OSVR_Pose3.o \
	${OBJECTDIR}/_ext/1065522586/osvr_util_OSVR_Quaternion.o \
	${OBJECTDIR}/_ext/1065522586/osvr_util_OSVR_TimeValue.o \
	${OBJECTDIR}/_ext/1065522586/osvr_util_OSVR_Vec3.o \
	${OBJECTDIR}/_ext/1065522586/osvr_util_callback_OSVR_PoseCallback.o


# C Compiler Flags
CFLAGS=-m32 -shared

# CC Compiler Flags
CCFLAGS=-m32 -shared
CXXFLAGS=-m32 -shared

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/C/Users/Rickard/Documents/GitHub/libraries/OSVR-Core-Snapshot-v0.6-25-ga7c8941-build167-vs12-32bit/lib -losvrClientKit

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk dist/${CND_PLATFORM}/libOSVR-Java-Wrapper.${CND_DLIB_EXT}

dist/${CND_PLATFORM}/libOSVR-Java-Wrapper.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p dist/${CND_PLATFORM}
	g++ -o dist/${CND_PLATFORM}/libOSVR-Java-Wrapper.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared

${OBJECTDIR}/_ext/1065522586/Interface.o: /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/Interface.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1065522586
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/local/boost_1_59_0/ -I/C/Java/jdk1.8.0_60/include -I/C/Java/jdk1.8.0_60/include/win32 -I/C/Users/Rickard/Documents/GitHub/libraries/OSVR-Core-Snapshot-v0.6-25-ga7c8941-build167-vs12-32bit/include  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1065522586/Interface.o /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/Interface.cpp

${OBJECTDIR}/_ext/1065522586/InterfaceState.o: /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/InterfaceState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1065522586
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/local/boost_1_59_0/ -I/C/Java/jdk1.8.0_60/include -I/C/Java/jdk1.8.0_60/include/win32 -I/C/Users/Rickard/Documents/GitHub/libraries/OSVR-Core-Snapshot-v0.6-25-ga7c8941-build167-vs12-32bit/include  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1065522586/InterfaceState.o /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/InterfaceState.cpp

${OBJECTDIR}/_ext/1065522586/MinimalInit.o: /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/MinimalInit.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1065522586
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/local/boost_1_59_0/ -I/C/Java/jdk1.8.0_60/include -I/C/Java/jdk1.8.0_60/include/win32 -I/C/Users/Rickard/Documents/GitHub/libraries/OSVR-Core-Snapshot-v0.6-25-ga7c8941-build167-vs12-32bit/include  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1065522586/MinimalInit.o /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/MinimalInit.cpp

${OBJECTDIR}/_ext/1065522586/OSVR_PoseCallback.o: /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/OSVR_PoseCallback.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1065522586
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/local/boost_1_59_0/ -I/C/Java/jdk1.8.0_60/include -I/C/Java/jdk1.8.0_60/include/win32 -I/C/Users/Rickard/Documents/GitHub/libraries/OSVR-Core-Snapshot-v0.6-25-ga7c8941-build167-vs12-32bit/include  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1065522586/OSVR_PoseCallback.o /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/OSVR_PoseCallback.cpp

${OBJECTDIR}/_ext/1065522586/TrackerCallback.o: /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/TrackerCallback.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1065522586
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/local/boost_1_59_0/ -I/C/Java/jdk1.8.0_60/include -I/C/Java/jdk1.8.0_60/include/win32 -I/C/Users/Rickard/Documents/GitHub/libraries/OSVR-Core-Snapshot-v0.6-25-ga7c8941-build167-vs12-32bit/include  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1065522586/TrackerCallback.o /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/TrackerCallback.cpp

${OBJECTDIR}/_ext/1065522586/TrackerCallbackToJava.o: /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/TrackerCallbackToJava.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1065522586
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/local/boost_1_59_0/ -I/C/Java/jdk1.8.0_60/include -I/C/Java/jdk1.8.0_60/include/win32 -I/C/Users/Rickard/Documents/GitHub/libraries/OSVR-Core-Snapshot-v0.6-25-ga7c8941-build167-vs12-32bit/include  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1065522586/TrackerCallbackToJava.o /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/TrackerCallbackToJava.cpp

${OBJECTDIR}/_ext/1065522586/osvr_clientkit_ContextWrapper.o: /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/osvr_clientkit_ContextWrapper.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1065522586
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/local/boost_1_59_0/ -I/C/Java/jdk1.8.0_60/include -I/C/Java/jdk1.8.0_60/include/win32 -I/C/Users/Rickard/Documents/GitHub/libraries/OSVR-Core-Snapshot-v0.6-25-ga7c8941-build167-vs12-32bit/include  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1065522586/osvr_clientkit_ContextWrapper.o /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/osvr_clientkit_ContextWrapper.cpp

${OBJECTDIR}/_ext/1065522586/osvr_util_OSVR_Pose3.o: /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/osvr_util_OSVR_Pose3.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1065522586
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/local/boost_1_59_0/ -I/C/Java/jdk1.8.0_60/include -I/C/Java/jdk1.8.0_60/include/win32 -I/C/Users/Rickard/Documents/GitHub/libraries/OSVR-Core-Snapshot-v0.6-25-ga7c8941-build167-vs12-32bit/include  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1065522586/osvr_util_OSVR_Pose3.o /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/osvr_util_OSVR_Pose3.cpp

${OBJECTDIR}/_ext/1065522586/osvr_util_OSVR_Quaternion.o: /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/osvr_util_OSVR_Quaternion.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1065522586
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/local/boost_1_59_0/ -I/C/Java/jdk1.8.0_60/include -I/C/Java/jdk1.8.0_60/include/win32 -I/C/Users/Rickard/Documents/GitHub/libraries/OSVR-Core-Snapshot-v0.6-25-ga7c8941-build167-vs12-32bit/include  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1065522586/osvr_util_OSVR_Quaternion.o /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/osvr_util_OSVR_Quaternion.cpp

${OBJECTDIR}/_ext/1065522586/osvr_util_OSVR_TimeValue.o: /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/osvr_util_OSVR_TimeValue.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1065522586
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/local/boost_1_59_0/ -I/C/Java/jdk1.8.0_60/include -I/C/Java/jdk1.8.0_60/include/win32 -I/C/Users/Rickard/Documents/GitHub/libraries/OSVR-Core-Snapshot-v0.6-25-ga7c8941-build167-vs12-32bit/include  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1065522586/osvr_util_OSVR_TimeValue.o /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/osvr_util_OSVR_TimeValue.cpp

${OBJECTDIR}/_ext/1065522586/osvr_util_OSVR_Vec3.o: /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/osvr_util_OSVR_Vec3.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1065522586
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/local/boost_1_59_0/ -I/C/Java/jdk1.8.0_60/include -I/C/Java/jdk1.8.0_60/include/win32 -I/C/Users/Rickard/Documents/GitHub/libraries/OSVR-Core-Snapshot-v0.6-25-ga7c8941-build167-vs12-32bit/include  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1065522586/osvr_util_OSVR_Vec3.o /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/osvr_util_OSVR_Vec3.cpp

${OBJECTDIR}/_ext/1065522586/osvr_util_callback_OSVR_PoseCallback.o: /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/osvr_util_callback_OSVR_PoseCallback.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1065522586
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/local/boost_1_59_0/ -I/C/Java/jdk1.8.0_60/include -I/C/Java/jdk1.8.0_60/include/win32 -I/C/Users/Rickard/Documents/GitHub/libraries/OSVR-Core-Snapshot-v0.6-25-ga7c8941-build167-vs12-32bit/include  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1065522586/osvr_util_callback_OSVR_PoseCallback.o /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/osvr_util_callback_OSVR_PoseCallback.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} dist/${CND_PLATFORM}/libOSVR-Java-Wrapper.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
