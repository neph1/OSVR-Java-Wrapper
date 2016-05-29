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

jobject Java_osvr_clientkit_OSVR_1Surface_getRelativeViewport(JNIEnv * env, jobject obj, jobject viewportHolder){
    osvr::clientkit::Surface *surface = getHandle<osvr::clientkit::Surface>(env, obj);
    std::cout << "getRelativeViewport 1"<< std::endl;
    std::cout << surface->getSurfaceID()<< std::endl;
    std::cout << surface->getDisplayConfig()<< std::endl;
    std::cout << surface->getViewerID()<< std::endl;
    std::cout << surface->getEyeID()<< std::endl;
    osvr::clientkit::RelativeViewport vp = surface->getRelativeViewport();
    std::cout << "getRelativeViewport 2"<< std::endl;
    
    setHandle(env, viewportHolder, &vp);
    std::cout << "getRelativeViewport 3"<< std::endl;
    return NULL;
}

jobject Java_osvr_clientkit_OSVR_1Surface_getRadialDistortion(JNIEnv * env, jobject obj){
    return NULL;
}


void Java_osvr_clientkit_OSVR_1Surface_disposeNative(JNIEnv * env, jobject obj){
    osvr::clientkit::Surface *surface = getHandle<osvr::clientkit::Surface>(env, obj);
    setHandle<jlong>(env, obj, 0);
    delete surface;
}

jint Java_osvr_clientkit_OSVR_1Surface_getSurfaceID(JNIEnv * env, jobject obj){
    osvr::clientkit::Surface *surface = getHandle<osvr::clientkit::Surface>(env, obj);
    return (jint) surface->getEyeID();
}

void Java_osvr_clientkit_OSVR_1Surface_getProjectionMatrix(JNIEnv* env, jobject obj, jfloat zNear, jfloat zFar, jint flags, jfloatArray matrix){
    
}