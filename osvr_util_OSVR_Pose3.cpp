#include "osvr_util_OSVR_Pose3_decl.h"
#include "Handle.h"
#include <string>
#include <iostream>

//osvr_util_OSVR_Pose3::osvr_util_OSVR_Pose3(){
//    
//}

void Java_osvr_util_OSVR_1Pose3_initializeNative(JNIEnv* env, jobject obj){
    OSVR_Pose3 quat;
    setHandle(env, obj, &quat);
}

void Java_osvr_util_OSVR_1Pose3_disposeNative(JNIEnv* env, jobject obj){
    jobject *pose = getHandle<jobject>(env, obj);
    setHandle<jlong>(env, obj, 0);
    delete pose;
}
