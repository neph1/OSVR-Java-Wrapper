#include "osvr_clientkit_OSVR_Eye_decl.h"

#include "Handle.h"
#include "DataObjectUtil.h"
#include <string>
#include <iostream>

void Java_osvr_clientkit_OSVR_1Ee_initializeNative(JNIEnv * env, jobject obj){
//    osvr::clientkit::Viewer viewer;
//    setHandle(env, obj, &viewer);
    
}

jint Java_osvr_clientkit_OSVR_1Eye_getNumSurfaces(JNIEnv * env, jobject obj){
    osvr::clientkit::Eye *eye = getHandle<osvr::clientkit::Eye>(env, obj);
    OSVR_ViewerCount numSurfaces = eye->getNumSurfaces();
    std::cout << "getNumSurfaces"<< std::endl;
    std::cout << eye<< std::endl;
    std::cout << eye->getDisplayConfig()<< std::endl;
    return (jint) numSurfaces;
}

jobject Java_osvr_clientkit_OSVR_1Eye_getSurface(JNIEnv* env, jobject obj, jint surfaceIndex, jobject holder){
    osvr::clientkit::Eye *eye = getHandle<osvr::clientkit::Eye>(env, obj);
    osvr::clientkit::Surface surface = eye->getSurface(static_cast<OSVR_SurfaceCount>(surfaceIndex));
    std::cout << "getSurface"<< std::endl;
    std::cout << eye->getDisplayConfig()<< std::endl;
    std::cout << eye->getEyeID()<< std::endl;
    std::cout << surface.getSurfaceID()<< std::endl;
    jclass c = env->GetObjectClass(holder);
    jfieldID fieldID = env->GetFieldID(c, "surfaceID", "I");
    env->SetIntField(holder, fieldID, surface.getSurfaceID());
    setHandle(env, holder, &surface);
    return (jobject) &holder;
}

jboolean Java_osvr_clientkit_OSVR_1Eye_getPose(JNIEnv * env, jobject obj){
    return false;
}

jboolean Java_osvr_clientkit_OSVR_1Eye_getViewMatrix(JNIEnv* env, jobject obj, jint flags, jfloatArray matrix){
    osvr::clientkit::Eye *eye = getHandle<osvr::clientkit::Eye>(env, obj);
    std::cout << "getViewMatrix"<< std::endl;
    std::cout << eye<< std::endl;
//    std::cout << eye->getNumSurfaces()<< std::endl;
//    std::cout << eye->getViewerID()<< std::endl;
    std::cout << eye->getDisplayConfig()<< std::endl;
    
//    osvr::clientkit::Eye e = osvr::clientkit::Eye(reinterpret_cast<OSVR_DisplayConfig>(eye->getDisplayConfig()), reinterpret_cast<OSVR_ViewerCount>(eye->getViewerID()), reinterpret_cast<OSVR_EyeCount>(eye->getEyeID()));
    
    float mat[OSVR_MATRIX_SIZE] = { };
    bool ret = eye->getViewMatrix(OSVR_MATRIX_COLMAJOR | OSVR_MATRIX_COLVECTORS, mat);
    if(!ret){
        std::cout << "No viewmatrix found"<< std::endl;
        return false;
    }
    setMatrixData(env, obj, mat, matrix);
    return true;
}

void Java_osvr_clientkit_OSVR_1Eye_disposeNative(JNIEnv * env, jobject obj){
    osvr::clientkit::Eye *eye = getHandle<osvr::clientkit::Eye>(env, obj);
    setHandle<jlong>(env, obj, 0);
    delete eye;
}

jint Java_osvr_clientkit_OSVR_1Eye_getEyeID(JNIEnv * env, jobject obj){
    osvr::clientkit::Eye *eye = getHandle<osvr::clientkit::Eye>(env, obj);
    return (jint) eye->getEyeID();
}