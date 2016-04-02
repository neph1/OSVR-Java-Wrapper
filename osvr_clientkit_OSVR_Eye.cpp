#include "osvr_clientkit_OSVR_Eye_decl.h"

#include "Handle.h"
#include "DataObjectUtil.h"
#include <string>
#include <iostream>
osvr::clientkit::Eye* m_eye;
void Eye(osvr::clientkit::Eye* eye ){
    m_eye = eye;
}

void Java_osvr_clientkit_OSVR_1Ee_initializeNative(JNIEnv * env, jobject obj){
//    osvr::clientkit::Viewer viewer;
//    setHandle(env, obj, &viewer);
    
}

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
     std::cout << "getViewMatrix 2"<< std::endl;
    float mat[OSVR_MATRIX_SIZE] = { };
    bool ret = eye->getViewMatrix(OSVR_MATRIX_COLMAJOR | OSVR_MATRIX_COLVECTORS, mat);
    std::cout << "getViewMatrix 3"<< std::endl;
    if(!ret){
        std::cout << "No viewmatrix found"<< std::endl;
        return false;
    }
    std::cout << "getViewMatrix 3"<< std::endl;
    setViewMatrixData(env, obj, mat, matrix);
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