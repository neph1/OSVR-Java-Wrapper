#include "osvr_clientkit_DisplayHelper.h"
#include "DataObjectUtil.h"
#include "Handle.h"
#include "osvr_clientkit_OSVR_Eye_decl.h"
#include "osvr_clientkit_OSVR_DisplayConfig.h"
#include "osvr_clientkit_OSVR_Viewer_decl.h"
#include "osvr_util_OSVR_DataObject.h"
#include <iostream>
#include <string>

class DisplayHelper{
    
};

void Java_osvr_clientkit_DisplayHelper_initializeNative(JNIEnv * env, jobject obj){
    DisplayHelper helper;
    std::cout << "DisplayHelper_initializeNative"<< std::endl;
    setHandle(env, obj, &helper);
}


jboolean Java_osvr_clientkit_DisplayHelper_getViewMatrix(JNIEnv * env, jobject obj, jlong displayHandle, jlong viewerHandle, jint eyeHandle, jfloatArray matrix){
    OSVR_DisplayConfig display = reinterpret_cast<OSVR_DisplayConfig >(displayHandle);
    OSVR_ViewerCount viewer = (uint32_t) 0;
    OSVR_EyeCount eye = 0;
    std::cout << "getViewMatrix 1"<< std::endl;
    std::cout << viewer<< std::endl;
    std::cout << eye<< std::endl;
//    osvr::clientkit::Eye eyeObject(display, viewer, eye);
    std::cout << "getViewMatrix 2"<< std::endl;
    float mat[OSVR_MATRIX_SIZE] = { };
//    bool ret = eyeObject.getViewMatrix(OSVR_MATRIX_COLMAJOR | OSVR_MATRIX_COLVECTORS, mat);
    OSVR_ReturnCode ret = osvrClientGetViewerEyeViewMatrixf(
                display, viewer, (uint8_t) 0, OSVR_MATRIX_COLMAJOR | OSVR_MATRIX_COLVECTORS, mat);
    std::cout << "getViewMatrix 3"<< std::endl;
    if(!ret){
        std::cout << "No viewmatrix found"<< std::endl;
        return false;
    }
    std::cout << "getViewMatrix 3"<< std::endl;
    setViewMatrixData(env, obj, mat, matrix);
}

void Java_osvr_util_OSVR_DisplayHelper_disposeNative(JNIEnv* env, jobject obj){
    jobject *helper = getHandle<jobject>(env, obj);
    setHandle<jlong>(env, obj, 0);
    delete helper;
}