
#include <osvr/ClientKit/Display.h>
#include "osvr_clientkit_DisplayC.h"
#include "DataObjectUtil.h"
#include "Handle.h"
#include <string>
#include <iostream>

#define ZERO 0
#define VIEWMAT_LEN 16
#define VIEWPORT_LENGTH 4

OSVR_DisplayConfig m_display;

void Java_osvr_clientkit_DisplayC_initializeNative(JNIEnv * env, jobject obj, jobject jcontext){
//    OSVR_ClientContext *context = getHandle<OSVR_ClientContext>(env, jcontext);
//    OSVR_DisplayConfig cfg = NULL;
//    OSVR_ReturnCode result = osvrClientGetDisplay(*context, &cfg);
//    osvr::clientkit::UnderlyingDisplayConfigPtr ret(cfg, &osvrClientFreeDisplay);
//    osvr::clientkit::DisplayConfig displayConfig  = osvr::clientkit::DisplayConfig(ret);
//    m_display = displayConfig.getDisplayConfig();
}

void Java_osvr_clientkit_DisplayC_setDisplayConfigNative(JNIEnv * env, jobject obj, jobject displayHandle){
    osvr::clientkit::DisplayConfig *display = getHandle<osvr::clientkit::DisplayConfig>(env, displayHandle);
    m_display = display->getDisplayConfig();
    std::cout << "Java_osvr_clientkit_DisplayC_setDisplayConfigNative"<< std::endl;
    std::cout << m_display<< std::endl;
}

jint Java_osvr_clientkit_DisplayC_osvrClientGetNumViewers(JNIEnv * env, jobject obj, jobject displayHandle){
//     osvr::clientkit::DisplayConfig *display = getHandle<osvr::clientkit::DisplayConfig>(env, displayHandle);
    OSVR_ViewerCount viewers;
    osvrClientGetNumViewers(m_display, &viewers);
    return (jint) viewers;
}

jint Java_osvr_clientkit_DisplayC_osvrClientGetNumEyesForViewer
  (JNIEnv * env, jobject obj, jobject displayHandle, jint viewer){
//    osvr::clientkit::DisplayConfig *display = getHandle<osvr::clientkit::DisplayConfig>(env, displayHandle);
    OSVR_ViewerCount viewerC = static_cast<OSVR_ViewerCount>(viewer);
    OSVR_EyeCount eyes;
    osvrClientGetNumEyesForViewer(m_display, viewerC, &eyes);
    return (jint) eyes;
}

jint Java_osvr_clientkit_DisplayC_osvrClientGetNumSurfacesForViewerEye
  (JNIEnv * env, jobject obj, jobject displayHandle, jint viewer, jint eye){
//    osvr::clientkit::DisplayConfig *display = getHandle<osvr::clientkit::DisplayConfig>(env, displayHandle);
    OSVR_ViewerCount viewerC = static_cast<OSVR_ViewerCount>(viewer);
    OSVR_EyeCount eyeC = static_cast<OSVR_EyeCount>(eye);
    OSVR_SurfaceCount surfaces;
    osvrClientGetNumSurfacesForViewerEye(m_display, viewerC, eyeC, &surfaces);
    return surfaces;
}
        
void Java_osvr_clientkit_DisplayC_osvrClientGetRelativeViewportForViewerEyeSurface
  (JNIEnv * env, jobject obj, jobject displayHandle, jint viewer, jint eye, jint surface, jintArray viewport){
//    osvr::clientkit::DisplayConfig *display = getHandle<osvr::clientkit::DisplayConfig>(env, displayHandle);
    OSVR_ViewportDimension mat[VIEWPORT_LENGTH] = { };
    OSVR_ViewerCount viewerC = static_cast<OSVR_ViewerCount>(viewer);
    OSVR_EyeCount eyeC = static_cast<OSVR_EyeCount>(eye);
    OSVR_SurfaceCount surfaceC = static_cast<OSVR_SurfaceCount>(surface);
    OSVR_ReturnCode ret =
                osvrClientGetRelativeViewportForViewerEyeSurface(
                    m_display, viewerC, eyeC, surfaceC, &mat[0],
                    &mat[1], &mat[2], &mat[3]);
    if(ret != OSVR_RETURN_SUCCESS){
        
    }
    setViewportData(env, obj, mat, viewport);
}

void Java_osvr_clientkit_DisplayC_osvrClientGetViewerEyeViewMatrixf(JNIEnv * env, jobject obj, jobject displayHandle, jint viewer, jint eye, jint flags, jfloatArray viewMatrix){
//    osvr::clientkit::DisplayConfig *display = getHandle<osvr::clientkit::DisplayConfig>(env, displayHandle);
    float mat[VIEWMAT_LEN] = { };
    OSVR_ViewerCount viewerC = static_cast<OSVR_ViewerCount>(viewer);
    OSVR_EyeCount eyeC = static_cast<OSVR_EyeCount>(eye);
    OSVR_ReturnCode ret = osvrClientGetViewerEyeViewMatrixf(m_display, viewerC, eyeC, 0, mat);
    if(ret != OSVR_RETURN_SUCCESS){
        
    }
    setMatrixData(env, obj, mat, viewMatrix);
}

void Java_osvr_clientkit_DisplayC_osvrClientGetViewerEyeSurfaceProjectionMatrixf(JNIEnv * env, jobject obj, jobject displayHandle, jint viewer, jint eye, jint surface, jfloat near, jfloat far, jint flags, jfloatArray projMatrix){
//    osvr::clientkit::DisplayConfig *display = getHandle<osvr::clientkit::DisplayConfig>(env, displayHandle);
    float mat[VIEWMAT_LEN] = { };
    OSVR_ViewerCount viewerC = static_cast<OSVR_ViewerCount>(viewer);
    OSVR_EyeCount eyeC = static_cast<OSVR_EyeCount>(eye);
    OSVR_SurfaceCount surfaceC = static_cast<OSVR_SurfaceCount>(surface);
    OSVR_ReturnCode ret = osvrClientGetViewerEyeSurfaceProjectionMatrixf(m_display, viewerC, eyeC, surfaceC, near, far, OSVR_MATRIX_COLMAJOR | OSVR_MATRIX_COLVECTORS |
                        OSVR_MATRIX_SIGNEDZ | OSVR_MATRIX_RHINPUT, mat);
    if(ret != OSVR_RETURN_SUCCESS){
        
    }
    setMatrixData(env, obj, mat, projMatrix);
}

jboolean Java_osvr_clientkit_DisplayC_osvrClientDoesViewerEyeSurfaceWantDistortion(JNIEnv * env, jobject obj, jobject displayHandle, jint viewer, jint eye, jint surface){
//    osvr::clientkit::DisplayConfig *display = getHandle<osvr::clientkit::DisplayConfig>(env, displayHandle);
    OSVR_ViewerCount viewerC = static_cast<OSVR_ViewerCount>(viewer);
    OSVR_EyeCount eyeC = static_cast<OSVR_EyeCount>(eye);
    OSVR_SurfaceCount surfaceC = static_cast<OSVR_SurfaceCount>(surface);
    OSVR_CBool distortionRequested;
    OSVR_ReturnCode ret = osvrClientDoesViewerEyeSurfaceWantDistortion(m_display, viewerC, eyeC, surfaceC, &distortionRequested);
    if (OSVR_RETURN_SUCCESS != ret) {
        return false;
    }
    return (distortionRequested == OSVR_TRUE);
}

jint Java_osvr_clientkit_DisplayC_osvrClientGetViewerEyeSurfaceRadialDistortionPriority(JNIEnv * env, jobject obj, jobject displayHandle, jint viewer, jint eye, jint surface){
//    osvr::clientkit::DisplayConfig *display = getHandle<osvr::clientkit::DisplayConfig>(env, displayHandle);
    OSVR_ViewerCount viewerC = static_cast<OSVR_ViewerCount>(viewer);
    OSVR_EyeCount eyeC = static_cast<OSVR_EyeCount>(eye);
    OSVR_SurfaceCount surfaceC = static_cast<OSVR_SurfaceCount>(surface);
    OSVR_DistortionPriority priority;
    OSVR_ReturnCode ret = osvrClientGetViewerEyeSurfaceRadialDistortionPriority(m_display, viewerC, eyeC, surfaceC, &priority);
    if (OSVR_RETURN_SUCCESS != ret) {
        return -1;
    }
    return (jint) priority;
}

void Java_osvr_clientkit_DisplayC_osvrClientGetViewerEyeSurfaceRadialDistortion(JNIEnv * env, jobject obj, jobject displayHandle, jint viewer, jint eye, jint surface, jobject jparams){
//    osvr::clientkit::DisplayConfig *display = getHandle<osvr::clientkit::DisplayConfig>(env, displayHandle);
    OSVR_ViewerCount viewerC = static_cast<OSVR_ViewerCount>(viewer);
    OSVR_EyeCount eyeC = static_cast<OSVR_EyeCount>(eye);
    OSVR_SurfaceCount surfaceC = static_cast<OSVR_SurfaceCount>(surface);
    OSVR_RadialDistortionParameters params;
    OSVR_ReturnCode ret = osvrClientGetViewerEyeSurfaceRadialDistortion(m_display, viewerC, eyeC, surfaceC, &params);
    if (OSVR_RETURN_SUCCESS != ret) {
       
    }
    setDistortionParameters(env, jparams, params);
}

void Java_osvr_clientkit_DisplayC_releaseFloatArray(JNIEnv *env, jobject obj, jfloatArray jArray){
    float* elem = env->GetFloatArrayElements(jArray, 0);
    env->ReleaseFloatArrayElements(jArray, (jfloat*)elem, 0);
}

void Java_osvr_clientkit_DisplayC_releaseDoubleArray(JNIEnv *env, jobject obj, jdoubleArray jArray){
    double* elem = env->GetDoubleArrayElements(jArray, 0);
    env->ReleaseDoubleArrayElements(jArray, (jdouble*)elem, 0);
}

void Java_osvr_clientkit_DisplayC_releaseIntArray(JNIEnv *env, jobject obj, jintArray jArray){
    jint* elem = env->GetIntArrayElements(jArray, 0);
    env->ReleaseIntArrayElements(jArray, (jint*)elem, 0);
}