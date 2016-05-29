#include "osvr_clientkit_OSVR_Viewer_decl.h"
#include "Handle.h"

#include <string>
#include <iostream>


void Java_osvr_clientkit_OSVR_1Viewer_initializeNative(JNIEnv * env, jobject obj){
    
//    osvr::clientkit::Viewer *viewer;
//    setHandle(env, obj, &viewer);
}

jint Java_osvr_clientkit_OSVR_1Viewer_getNumEyes(JNIEnv* env, jobject obj){
    osvr::clientkit::Viewer *viewer = getHandle<osvr::clientkit::Viewer>(env, obj);
    std::cout << "Viewer_getNumEyes"<< std::endl;
//    OSVR_EyeCount eyes;
//            OSVR_ReturnCode ret =
//                osvrClientGetNumEyesForViewer(viewer->getDisplayConfig(), 0, &eyes);
//            if (ret != OSVR_RETURN_SUCCESS) {
//                std::cout <<"Couldn't get number of eyes in this "
//                                   "display for the given viewer!"<< std::endl;
//            }
    OSVR_EyeCount numEyes = viewer->getNumEyes();
    std::cout << "numEyes "<< std::endl;
    std::cout << numEyes << std::endl;
    return (jint) numEyes;
}

jobject Java_osvr_clientkit_OSVR_1Viewer_getEye(JNIEnv* env, jobject obj, jint eyeIndex, jobject holder){
    osvr::clientkit::Viewer *viewer = getHandle<osvr::clientkit::Viewer>(env, obj);
    osvr::clientkit::Viewer v = *viewer;
    osvr::clientkit::Eye eye = viewer->getEye(static_cast<OSVR_EyeCount>(eyeIndex));
    jclass c = env->GetObjectClass(holder);
    jfieldID fieldID = env->GetFieldID(c, "eyeID", "I");
    env->SetIntField(holder, fieldID, eye.getEyeID());
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

jint Java_osvr_clientkit_OSVR_1Viewer_getViewerID(JNIEnv * env, jobject obj){
    osvr::clientkit::Viewer *viewer = getHandle<osvr::clientkit::Viewer>(env, obj);
    std::cout << "getViewerID"<< std::endl;
    std::cout << viewer->getViewerID()<< std::endl;
    return (jint) viewer->getViewerID();
}