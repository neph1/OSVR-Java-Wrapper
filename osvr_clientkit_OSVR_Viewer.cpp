#include "osvr_clientkit_OSVR_Viewer_decl.h"
#include "Handle.h"

#include <string>
#include <iostream>

void Java_osvr_clientkit_OSVR_1Viewer_initializeNative(JNIEnv*, jobject){
    
}

jint Java_osvr_clientkit_OSVR_1Viewer_getNumEyes(JNIEnv* env, jobject obj){
    osvr::clientkit::Viewer *viewer = getHandle<osvr::clientkit::Viewer>(env, obj);
    OSVR_EyeCount numEyes = viewer->getNumEyes();
    std::cout << "numEyes "<< std::endl;
    return (jint) numEyes;
}

jobject Java_osvr_clientkit_OSVR_1Viewer_getEye(JNIEnv* env, jobject obj, jint eyeIndex, jobject holder){
    std::cout << "getEye"<< std::endl;
    osvr::clientkit::Viewer *viewer = getHandle<osvr::clientkit::Viewer>(env, obj);
    std::cout << "viewer "<< std::endl;
    osvr::clientkit::Eye eye = viewer->getEye(eyeIndex);
    std::cout << "eye "<< std::endl;
    if(NULL == holder){
        jclass cls = env->FindClass("Losvr/clientkit/OSVR_Eye;");
        jmethodID constructor = env->GetMethodID(cls, "<init>", "()V");
        holder = env->NewObject(cls, constructor);
    }
    setHandle(env, holder, &eye);
    return (jobject) &holder;
}

jobject Java_osvr_clientkit_OSVR_1Viewer_getSurface(JNIEnv* env, jobject obj, jint eyeIndex, jint surfaceIndex, jobject holder){
    osvr::clientkit::Viewer *viewer = getHandle<osvr::clientkit::Viewer>(env, obj);
    osvr::clientkit::Surface surface = viewer->getSurface(eyeIndex, surfaceIndex);
    if(NULL == holder){
        jclass cls = env->FindClass("Losvr/clientkit/OSVR_Surface;");
        jmethodID constructor = env->GetMethodID(cls, "<init>", "()V");
        holder = env->NewObject(cls, constructor);
    }
    setHandle(env, holder, &surface);
    return (jobject) &holder;
}

void Java_osvr_clientkit_OSVR_1Viewer_disposeNative(JNIEnv * env, jobject obj){
    osvr::clientkit::Viewer *viewer = getHandle<osvr::clientkit::Viewer>(env, obj);
    setHandle<jlong>(env, obj, 0);
    delete viewer;
}