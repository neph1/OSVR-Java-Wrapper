#include "osvr_clientkit_OSVR_Surface_decl.h"
#include "Handle.h"

#include <string>
#include <iostream>

void Java_osvr_clientkit_OSVR_1Surface_initializeNative(JNIEnv * env, jobject obj){
//    osvr::clientkit::Surface surface;
//    std::cout << "OSVR_Surface_initializeNative"<< std::endl;
//    setHandle(env, obj, &surface);
}

jboolean Java_osvr_clientkit_OSVR_1Surface_isDistortionRequested(JNIEnv * env, jobject obj){
    osvr::clientkit::Surface *surface = getHandle<osvr::clientkit::Surface>(env, obj);
    return surface->isDistortionRequested();
}

jobject Java_osvr_clientkit_OSVR_1Surface_getRadialDistortion(JNIEnv * env, jobject obj){
    return NULL;
}


void Java_osvr_clientkit_OSVR_1Surface_disposeNative(JNIEnv * env, jobject obj){
    osvr::clientkit::Surface *surface = getHandle<osvr::clientkit::Surface>(env, obj);
    setHandle<jlong>(env, obj, 0);
    delete surface;
}