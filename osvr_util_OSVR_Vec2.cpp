#include "osvr_util_OSVR_Vec2_decl.h"
#include "Handle.h"
#include "DataObjectUtil.h"

#define LEN 2

void Java_osvr_util_OSVR_1Vec2_initializeNative(JNIEnv * env, jobject obj){
    OSVR_Vec2 quat;
    setHandle(env, obj, &quat);
}

void Java_osvr_util_OSVR_1Vec2_disposeNative(JNIEnv* env, jobject obj){
    jobject *vec = getHandle<jobject>(env, obj);
    jfieldID fieldID = env->GetFieldID(env->GetObjectClass(obj), "data", "[D");
    jdoubleArray jdata = (jdoubleArray)env->GetObjectField(obj, fieldID);
    double* elem = env->GetDoubleArrayElements(jdata, 0);
    env->ReleaseDoubleArrayElements(jdata, (jdouble*)elem, 0);
    setHandle<jlong>(env, obj, 0);
    delete vec;
}