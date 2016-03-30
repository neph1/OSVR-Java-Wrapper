#include "osvr_clientkit_OSVR_Eye_decl.h"

#include "Handle.h"
#include "DataObjectUtil.h"
#include <string>
#include <iostream>
jint Java_osvr_clientkit_OSVR_1Eye_getNumSurfaces(JNIEnv * env, jobject obj){
    osvr::clientkit::Eye *eye = getHandle<osvr::clientkit::Eye>(env, obj);
    OSVR_ViewerCount numSurfaces = eye->getNumSurfaces();
    return (jint) numSurfaces;
}

jobject Java_osvr_clientkit_OSVR_1Eye_getSurface(JNIEnv* env, jobject obj, jint surfaceIndex, jobject holder){
    osvr::clientkit::Eye *eye = getHandle<osvr::clientkit::Eye>(env, obj);
    osvr::clientkit::Surface surface = eye->getSurface(surfaceIndex);
    if(NULL == holder){
        jclass cls = env->FindClass("Losvr/clientkit/OSVR_Surface;");
        jmethodID constructor = env->GetMethodID(cls, "<init>", "()V");
        holder = env->NewObject(cls, constructor);
    }
    setHandle(env, holder, &surface);
    return (jobject) &holder;
}

jboolean Java_osvr_clientkit_OSVR_1Eye_getPose(JNIEnv * env, jobject obj){
    return false;
}

jboolean Java_osvr_clientkit_OSVR_1Eye_getViewMatrix(JNIEnv* env, jobject obj, jint flags, jfloatArray matrix){
    std::cout << "getViewMatrix"<< std::endl;
    osvr::clientkit::Eye *eye = getHandle<osvr::clientkit::Eye>(env, obj);
    std::cout << eye<< std::endl;
    float mat[16];
    bool ret = eye->getViewMatrix(flags, mat);
    if(!ret){
        std::cout << "No viewmatrix found"<< std::endl;
        return false;
    }
    setViewMatrixData(env, obj, mat, matrix);
    return true;
}

void Java_osvr_clientkit_OSVR_1Eye_disposeNative(JNIEnv * env, jobject obj){
    osvr::clientkit::Eye *eye = getHandle<osvr::clientkit::Eye>(env, obj);
    setHandle<jlong>(env, obj, 0);
    delete eye;
}