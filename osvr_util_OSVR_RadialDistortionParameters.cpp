#include "osvr_util_OSVR_RadialDistortionParameters_decl.h"
#include "Handle.h"

void Java_osvr_util_OSVR_1RadialDistortionParameters_initializeNative(JNIEnv * env, jobject obj){
    OSVR_RadialDistortionParameters params;
    setHandle(env, obj, &params);
}

void Java_osvr_util_OSVR_1RadialDistortionParameters_disposeNative(JNIEnv* env, jobject obj){
    jobject *vec = getHandle<jobject>(env, obj);
    setHandle<jlong>(env, obj, 0);
    delete vec;
}