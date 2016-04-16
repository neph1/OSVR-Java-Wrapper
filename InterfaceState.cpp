
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

jint Java_osvr_clientkit_InterfaceState_osvrGetPoseState(JNIEnv* env, jobject obj, jlong interfaceHandle, jobject timestate, jobject pose){
    OSVR_ClientInterface interfaceNative = reinterpret_cast<OSVR_ClientInterface >(interfaceHandle);
//    OSVR_PoseState state;
    OSVR_PoseState *state = getHandle<OSVR_PoseState>(env, pose);
    OSVR_TimeValue timestamp;
//    OSVR_TimeValue *timestamp = getHandle<OSVR_TimeValue>(env, timestate);
    OSVR_ReturnCode res = osvrGetPoseState(interfaceNative, &timestamp, state);
    if (OSVR_RETURN_SUCCESS != res) {
        return (jint)OSVR_RETURN_FAILURE;
    }
    setPose3Data(env, pose, *state);
    return (jint)OSVR_RETURN_SUCCESS;
}

//jint Java_osvr_clientkit_InterfaceState_osvrGetPoseState(JNIEnv* env, jobject obj, jobject interface, jobject timestate, jobject pose){
//    OSVR_ClientInterface interfaceNative = getHandle<OSVR_ClientInterface>(env, interface);
//    OSVR_PoseState state;
////    OSVR_PoseState *state = getHandle<OSVR_PoseState>(env, pose);
//    OSVR_TimeValue timestamp;
//    //OSVR_TimeValue *timestamp = getHandle<OSVR_TimeValue>(env, timestate);
//    std::cout << "GetPoseState" << std::endl;
//    std::cout << interfaceNative << std::endl;
//    OSVR_ReturnCode res = osvrGetPoseState(interfaceNative, &timestamp, &state);
//    if (OSVR_RETURN_SUCCESS != res) {
//        std::cout << "No pose state!"<< std::endl;
//        return (jint)0;
//    }
//    setPose3Data(env, pose, state);
//    return (jint)1;
//}

jint Java_osvr_clientkit_InterfaceState_osvrGetPositionState(JNIEnv* env, jobject obj, jlong interfaceHandle, jobject timestate, jobject position){
    OSVR_ClientInterface interfaceNative = reinterpret_cast<OSVR_ClientInterface >(interfaceHandle);
    OSVR_PositionState *state = getHandle<OSVR_PositionState>(env, position);
    OSVR_TimeValue timestamp ;//= getHandle<OSVR_TimeValue>(env, pose);
    OSVR_ReturnCode res = osvrGetPositionState(interfaceNative, &timestamp, state);
    if (OSVR_RETURN_SUCCESS != res) {
        std::cout << "No orientation state!"<< std::endl;
        return (jint)0;
    }
    setVec3Data(env, position, *state);
    return (jint)1;
}

jint Java_osvr_clientkit_InterfaceState_osvrGetOrientationState(JNIEnv* env, jobject obj, jlong interfaceHandle, jobject timestate, jobject orientation){
    OSVR_ClientInterface interfaceNative = reinterpret_cast<OSVR_ClientInterface >(interfaceHandle);
    OSVR_OrientationState *state = getHandle<OSVR_OrientationState>(env, orientation);
    OSVR_TimeValue timestamp ;//= getHandle<OSVR_TimeValue>(env, pose);
    OSVR_ReturnCode res = osvrGetOrientationState(interfaceNative, &timestamp, state);
    if (OSVR_RETURN_SUCCESS != res) {
        std::cout << "No orientation state!"<< std::endl;
        return (jint)0;
    }
    setQuatData(env, orientation, *state);
    return (jint)1;
}

jint Java_osvr_clientkit_InterfaceState_osvrGetButtonState(JNIEnv* env, jobject obj, jlong interfaceHandle, jobject timestate, jobject button){
    OSVR_ClientInterface interfaceNative = reinterpret_cast<OSVR_ClientInterface >(interfaceHandle);
    OSVR_ButtonState *state = getHandle<OSVR_ButtonState>(env, button);
    OSVR_TimeValue timestamp ;//= getHandle<OSVR_TimeValue>(env, pose);
    OSVR_ReturnCode res = osvrGetButtonState(interfaceNative, &timestamp, state);
    if (OSVR_RETURN_SUCCESS != res) {
        std::cout << "No orientation state!"<< std::endl;
        return (jint)0;
    }
    setButtonData(env, button, *state);
    return (jint)1;
}

//jint Java_osvr_clientkit_InterfaceState_osvrGetPositionState(JNIEnv* env, jobject obj, jobject interface, jobject timestate, jobject position){
//    std::cout << "InterfaceState_osvrGetPositionState"<< std::endl;
//    OSVR_ClientInterface *interfaceNative = getHandle<OSVR_ClientInterface>(env, interface);
//    OSVR_PositionState *state = getHandle<OSVR_PositionState>(env, position);
//    OSVR_TimeValue timestamp ;//= getHandle<OSVR_TimeValue>(env, pose);
//    int i = osvrGetPositionState(*interfaceNative, &timestamp, state);
//    setVec3Data(env, position, *state);
//    return (jint)i;
//}

void Java_osvr_clientkit_InterfaceState_releaseFloatArray(JNIEnv *env, jobject obj, jfloatArray jArray){
    float* elem = env->GetFloatArrayElements(jArray, 0);
    env->ReleaseFloatArrayElements(jArray, (jfloat*)elem, 0);
}

void Java_osvr_clientkit_InterfaceState_releaseDoubleArray(JNIEnv *env, jobject obj, jdoubleArray jArray){
    double* elem = env->GetDoubleArrayElements(jArray, 0);
    env->ReleaseDoubleArrayElements(jArray, (jdouble*)elem, 0);
}

void Java_osvr_clientkit_InterfaceState_releaseIntArray(JNIEnv *env, jobject obj, jintArray jArray){
    jint* elem = env->GetIntArrayElements(jArray, 0);
    env->ReleaseIntArrayElements(jArray, (jint*)elem, 0);
}
