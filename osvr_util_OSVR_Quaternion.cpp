#include "osvr_util_OSVR_Quaternion_decl.h"
#include "Handle.h"

//osvr_util_OSVR_Quaternion::osvr_util_OSVR_Quaternion(){
//    
//}

void Java_osvr_util_OSVR_1Quaternion_initializeNative(JNIEnv * env, jobject obj){
    OSVR_Quaternion quat;
    setHandle(env, obj, &quat);
}

void Java_osvr_util_OSVR_1Quaternion_disposeNative(JNIEnv* env, jobject obj){
    jobject *quat = getHandle<jobject>(env, obj);
    jfieldID fieldID = env->GetFieldID(env->GetObjectClass(obj), "data", "[D");
    jdoubleArray jdata = (jdoubleArray)env->GetObjectField(obj, fieldID);
    double* elem = env->GetDoubleArrayElements(jdata, 0);
    env->ReleaseDoubleArrayElements(jdata, (jdouble*)elem, 0);
    setHandle<jlong>(env, obj, 0);
    delete quat;
}