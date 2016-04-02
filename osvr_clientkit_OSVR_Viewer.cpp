#include "osvr_clientkit_OSVR_Viewer_decl.h"
#include "Handle.h"

#include <string>
#include <iostream>


void Java_osvr_clientkit_OSVR_1Viewer_initializeNative(JNIEnv * env, jobject obj){
    
//    osvr::clientkit::Viewer viewer;
//    setHandle(env, obj, &viewer);
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
    setHandle(env, holder, &eye);
    return (jobject) &holder;
}

jobject Java_osvr_clientkit_OSVR_1Viewer_getSurface(JNIEnv* env, jobject obj, jint eyeIndex, jint surfaceIndex, jobject holder){
    osvr::clientkit::Viewer *viewer = getHandle<osvr::clientkit::Viewer>(env, obj);
    osvr::clientkit::Surface surface = viewer->getSurface(eyeIndex, surfaceIndex);
    setHandle(env, holder, &surface);
    return (jobject) &holder;
}

void Java_osvr_clientkit_OSVR_1Viewer_disposeNative(JNIEnv * env, jobject obj){
    osvr::clientkit::Viewer *viewer = getHandle<osvr::clientkit::Viewer>(env, obj);
    setHandle<jlong>(env, obj, 0);
    delete viewer;
}

jlong Java_osvr_clientkit_OSVR_1Viewer_getViewerID(JNIEnv * env, jobject obj){
    osvr::clientkit::Viewer *viewer = getHandle<osvr::clientkit::Viewer>(env, obj);
    std::cout << "getViewerID"<< std::endl;
    std::cout << viewer<< std::endl;
    std::cout << viewer->getViewerID()<< std::endl;
    
    return (jlong) viewer->getViewerID();
}