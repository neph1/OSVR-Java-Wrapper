
#include "osvr_clientkit_InterfaceState_decl.h"
#include <osvr/ClientKit/InterfaceStateC.h>
#include "Handle.h"
#include "osvr_util_OSVR_Quaternion_decl.h"
#include "DataObjectUtil.h"
#include <iostream>

InterfaceState::InterfaceState(){
    
}
OSVR_Quaternion tempQuat;

void Java_osvr_clientkit_InterfaceState_initializeNative(JNIEnv* env, jobject obj){
    InterfaceState interfaceState;
    std::cout << "InterfaceState_initializeNative"<< std::endl;
    setHandle(env, obj, &interfaceState);
}

jint Java_osvr_clientkit_InterfaceState_osvrGetPoseState(JNIEnv* env, jobject obj, jobject interface, jobject timestate, jobject pose){
    std::cout << "InterfaceState_osvrGetPoseState"<< std::endl;
    OSVR_ClientInterface *interfaceNative = getHandle<OSVR_ClientInterface>(env, interface);
    OSVR_PoseState *state = getHandle<OSVR_PoseState>(env, pose);
    OSVR_TimeValue timestamp ;//= getHandle<OSVR_TimeValue>(env, pose);
    int i = osvrGetPoseState(*interfaceNative, &timestamp, state);
    setPose3Data(env, pose, *state);
    return (jint)i;
}

jint Java_osvr_clientkit_InterfaceState_osvrGetPositionState(JNIEnv* env, jobject obj, jobject interface, jobject timestate, jobject position){
    std::cout << "InterfaceState_osvrGetPositionState"<< std::endl;
    OSVR_ClientInterface *interfaceNative = getHandle<OSVR_ClientInterface>(env, interface);
    OSVR_PositionState *state = getHandle<OSVR_PositionState>(env, position);
    OSVR_TimeValue timestamp ;//= getHandle<OSVR_TimeValue>(env, pose);
    int i = osvrGetPositionState(*interfaceNative, &timestamp, state);
    setVec3Data(env, position, *state);
    return (jint)i;
}

void Java_osvr_clientkit_InterfaceState_disposeNative(JNIEnv* env, jobject obj){
    jobject *state = getHandle<jobject>(env, obj);
    setHandle<jlong>(env, obj, 0);
    delete state;
}
