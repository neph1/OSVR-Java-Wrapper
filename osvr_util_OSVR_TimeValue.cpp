#include "osvr_util_OSVR_TimeValue_decl.h"
#include "Handle.h"
#include <string>
#include <iostream>

//osvr_util_OSVR_TimeValue::osvr_util_OSVR_TimeValue(){
//    
//}

void Java_osvr_util_OSVR_1TimeValue_initializeNative(JNIEnv * env, jobject obj){
    OSVR_TimeValue quat;
    setHandle(env, obj, &quat);
}

void Java_osvr_util_OSVR_1TimeValue_disposeNative(JNIEnv* env, jobject obj){
    jobject *time = getHandle<jobject>(env, obj);
    setHandle<jlong>(env, obj, 0);
    delete time;
}