#include "osvr_util_OSVR_Vec2_decl.h"
#include "Handle.h"

#define LEN 2

void Java_osvr_util_OSVR_1Vec2_initializeNative(JNIEnv * env, jobject obj){
    OSVR_Vec2 quat;
    setHandle(env, obj, &quat);
}

void Java_osvr_util_OSVR_1Vec2_disposeNative(JNIEnv* env, jobject obj){
    jobject *vec = getHandle<jobject>(env, obj);
    setHandle<jlong>(env, obj, 0);
    delete vec;
}