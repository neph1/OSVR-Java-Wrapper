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
CC=x86_64-w64-mingw32-gcc
CCC=x86_64-w64-mingw32-g++
CXX=x86_64-w64-mingw32-g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW_x64-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
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
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libOSVR-Java-Wrapper.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libOSVR-Java-Wrapper.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libOSVR-Java-Wrapper.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared

${OBJECTDIR}/_ext/1065522586/Interface.o: /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/Interface.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1065522586
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../../../../Program\ Files/Java/jdk1.7.0_25/include -I../../../../../Program\ Files/Java/jdk1.7.0_25/include/win32 -I/G/Downloads/OSVR-Core-Snapshot-v0.2-836-g4617de4-build160-vs12-64bit/include -include ../../../../../Program\ Files/Java/jdk1.7.0_25/include -include ../../../../../Program\ Files/Java/jdk1.7.0_25/include/win32 -include /G/Downloads/OSVR-Core-Snapshot-v0.2-836-g4617de4-build160-vs12-64bit/include  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1065522586/Interface.o /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/Interface.cpp

${OBJECTDIR}/_ext/1065522586/InterfaceState.o: /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/InterfaceState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1065522586
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../../../../Program\ Files/Java/jdk1.7.0_25/include -I../../../../../Program\ Files/Java/jdk1.7.0_25/include/win32 -I/G/Downloads/OSVR-Core-Snapshot-v0.2-836-g4617de4-build160-vs12-64bit/include -include ../../../../../Program\ Files/Java/jdk1.7.0_25/include -include ../../../../../Program\ Files/Java/jdk1.7.0_25/include/win32 -include /G/Downloads/OSVR-Core-Snapshot-v0.2-836-g4617de4-build160-vs12-64bit/include  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1065522586/InterfaceState.o /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/InterfaceState.cpp

${OBJECTDIR}/_ext/1065522586/MinimalInit.o: /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/MinimalInit.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1065522586
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../../../../Program\ Files/Java/jdk1.7.0_25/include -I../../../../../Program\ Files/Java/jdk1.7.0_25/include/win32 -I/G/Downloads/OSVR-Core-Snapshot-v0.2-836-g4617de4-build160-vs12-64bit/include -include ../../../../../Program\ Files/Java/jdk1.7.0_25/include -include ../../../../../Program\ Files/Java/jdk1.7.0_25/include/win32 -include /G/Downloads/OSVR-Core-Snapshot-v0.2-836-g4617de4-build160-vs12-64bit/include  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1065522586/MinimalInit.o /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/MinimalInit.cpp

${OBJECTDIR}/_ext/1065522586/OSVR_PoseCallback.o: /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/OSVR_PoseCallback.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1065522586
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../../../../Program\ Files/Java/jdk1.7.0_25/include -I../../../../../Program\ Files/Java/jdk1.7.0_25/include/win32 -I/G/Downloads/OSVR-Core-Snapshot-v0.2-836-g4617de4-build160-vs12-64bit/include -include ../../../../../Program\ Files/Java/jdk1.7.0_25/include -include ../../../../../Program\ Files/Java/jdk1.7.0_25/include/win32 -include /G/Downloads/OSVR-Core-Snapshot-v0.2-836-g4617de4-build160-vs12-64bit/include  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1065522586/OSVR_PoseCallback.o /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/OSVR_PoseCallback.cpp

${OBJECTDIR}/_ext/1065522586/TrackerCallback.o: /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/TrackerCallback.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1065522586
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../../../../Program\ Files/Java/jdk1.7.0_25/include -I../../../../../Program\ Files/Java/jdk1.7.0_25/include/win32 -I/G/Downloads/OSVR-Core-Snapshot-v0.2-836-g4617de4-build160-vs12-64bit/include -include ../../../../../Program\ Files/Java/jdk1.7.0_25/include -include ../../../../../Program\ Files/Java/jdk1.7.0_25/include/win32 -include /G/Downloads/OSVR-Core-Snapshot-v0.2-836-g4617de4-build160-vs12-64bit/include  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1065522586/TrackerCallback.o /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/TrackerCallback.cpp

${OBJECTDIR}/_ext/1065522586/TrackerCallbackToJava.o: /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/TrackerCallbackToJava.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1065522586
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../../../../Program\ Files/Java/jdk1.7.0_25/include -I../../../../../Program\ Files/Java/jdk1.7.0_25/include/win32 -I/G/Downloads/OSVR-Core-Snapshot-v0.2-836-g4617de4-build160-vs12-64bit/include -include ../../../../../Program\ Files/Java/jdk1.7.0_25/include -include ../../../../../Program\ Files/Java/jdk1.7.0_25/include/win32 -include /G/Downloads/OSVR-Core-Snapshot-v0.2-836-g4617de4-build160-vs12-64bit/include  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1065522586/TrackerCallbackToJava.o /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/TrackerCallbackToJava.cpp

${OBJECTDIR}/_ext/1065522586/osvr_clientkit_ContextWrapper.o: /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/osvr_clientkit_ContextWrapper.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1065522586
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../../../../Program\ Files/Java/jdk1.7.0_25/include -I../../../../../Program\ Files/Java/jdk1.7.0_25/include/win32 -I/G/Downloads/OSVR-Core-Snapshot-v0.2-836-g4617de4-build160-vs12-64bit/include -include ../../../../../Program\ Files/Java/jdk1.7.0_25/include -include ../../../../../Program\ Files/Java/jdk1.7.0_25/include/win32 -include /G/Downloads/OSVR-Core-Snapshot-v0.2-836-g4617de4-build160-vs12-64bit/include  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1065522586/osvr_clientkit_ContextWrapper.o /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/osvr_clientkit_ContextWrapper.cpp

${OBJECTDIR}/_ext/1065522586/osvr_util_OSVR_Pose3.o: /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/osvr_util_OSVR_Pose3.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1065522586
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../../../../Program\ Files/Java/jdk1.7.0_25/include -I../../../../../Program\ Files/Java/jdk1.7.0_25/include/win32 -I/G/Downloads/OSVR-Core-Snapshot-v0.2-836-g4617de4-build160-vs12-64bit/include -include ../../../../../Program\ Files/Java/jdk1.7.0_25/include -include ../../../../../Program\ Files/Java/jdk1.7.0_25/include/win32 -include /G/Downloads/OSVR-Core-Snapshot-v0.2-836-g4617de4-build160-vs12-64bit/include  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1065522586/osvr_util_OSVR_Pose3.o /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/osvr_util_OSVR_Pose3.cpp

${OBJECTDIR}/_ext/1065522586/osvr_util_OSVR_Quaternion.o: /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/osvr_util_OSVR_Quaternion.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1065522586
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../../../../Program\ Files/Java/jdk1.7.0_25/include -I../../../../../Program\ Files/Java/jdk1.7.0_25/include/win32 -I/G/Downloads/OSVR-Core-Snapshot-v0.2-836-g4617de4-build160-vs12-64bit/include -include ../../../../../Program\ Files/Java/jdk1.7.0_25/include -include ../../../../../Program\ Files/Java/jdk1.7.0_25/include/win32 -include /G/Downloads/OSVR-Core-Snapshot-v0.2-836-g4617de4-build160-vs12-64bit/include  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1065522586/osvr_util_OSVR_Quaternion.o /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/osvr_util_OSVR_Quaternion.cpp

${OBJECTDIR}/_ext/1065522586/osvr_util_OSVR_TimeValue.o: /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/osvr_util_OSVR_TimeValue.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1065522586
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../../../../Program\ Files/Java/jdk1.7.0_25/include -I../../../../../Program\ Files/Java/jdk1.7.0_25/include/win32 -I/G/Downloads/OSVR-Core-Snapshot-v0.2-836-g4617de4-build160-vs12-64bit/include -include ../../../../../Program\ Files/Java/jdk1.7.0_25/include -include ../../../../../Program\ Files/Java/jdk1.7.0_25/include/win32 -include /G/Downloads/OSVR-Core-Snapshot-v0.2-836-g4617de4-build160-vs12-64bit/include  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1065522586/osvr_util_OSVR_TimeValue.o /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/osvr_util_OSVR_TimeValue.cpp

${OBJECTDIR}/_ext/1065522586/osvr_util_OSVR_Vec3.o: /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/osvr_util_OSVR_Vec3.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1065522586
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../../../../Program\ Files/Java/jdk1.7.0_25/include -I../../../../../Program\ Files/Java/jdk1.7.0_25/include/win32 -I/G/Downloads/OSVR-Core-Snapshot-v0.2-836-g4617de4-build160-vs12-64bit/include -include ../../../../../Program\ Files/Java/jdk1.7.0_25/include -include ../../../../../Program\ Files/Java/jdk1.7.0_25/include/win32 -include /G/Downloads/OSVR-Core-Snapshot-v0.2-836-g4617de4-build160-vs12-64bit/include  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1065522586/osvr_util_OSVR_Vec3.o /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/osvr_util_OSVR_Vec3.cpp

${OBJECTDIR}/_ext/1065522586/osvr_util_callback_OSVR_PoseCallback.o: /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/osvr_util_callback_OSVR_PoseCallback.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1065522586
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../../../../Program\ Files/Java/jdk1.7.0_25/include -I../../../../../Program\ Files/Java/jdk1.7.0_25/include/win32 -I/G/Downloads/OSVR-Core-Snapshot-v0.2-836-g4617de4-build160-vs12-64bit/include -include ../../../../../Program\ Files/Java/jdk1.7.0_25/include -include ../../../../../Program\ Files/Java/jdk1.7.0_25/include/win32 -include /G/Downloads/OSVR-Core-Snapshot-v0.2-836-g4617de4-build160-vs12-64bit/include  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1065522586/osvr_util_callback_OSVR_PoseCallback.o /C/Users/Rickard/Documents/GitHub/OSVR-Java-Wrapper/osvr_util_callback_OSVR_PoseCallback.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libOSVR-Java-Wrapper.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
