
#include <osvr/ClientKit/Display.h>
#include "osvr_clientkit_DisplayC.h"
#include "DataObjectUtil.h"
#include "Handle.h"
#include <string>
#include <iostream>

#define ZERO 0
#define VIEWMAT_LEN 16
#define VIEWPORT_LENGTH 4

jint Java_osvr_clientkit_DisplayC_osvrClientGetNumViewers(JNIEnv * env, jobject obj, jobject displayHandle){
     osvr::clientkit::DisplayConfig *display = getHandle<osvr::clientkit::DisplayConfig>(env, displayHandle);
    OSVR_ViewerCount viewers;
    osvrClientGetNumViewers(display->getDisplayConfig(), &viewers);
    return (jint) viewers;
}

jint Java_osvr_clientkit_DisplayC_osvrClientGetNumEyesForViewer
  (JNIEnv * env, jobject obj, jobject displayHandle, jint viewer){
    osvr::clientkit::DisplayConfig *display = getHandle<osvr::clientkit::DisplayConfig>(env, displayHandle);
    OSVR_ViewerCount viewerC = static_cast<OSVR_ViewerCount>(viewer);
    OSVR_EyeCount eyes;
    osvrClientGetNumEyesForViewer(display->getDisplayConfig(), viewerC, &eyes);
    return (jint) eyes;
}

jint Java_osvr_clientkit_DisplayC_osvrClientGetNumSurfacesForViewerEye
  (JNIEnv * env, jobject obj, jobject displayHandle, jint viewer, jint eye){
    osvr::clientkit::DisplayConfig *display = getHandle<osvr::clientkit::DisplayConfig>(env, displayHandle);
    OSVR_ViewerCount viewerC = static_cast<OSVR_ViewerCount>(viewer);
    OSVR_EyeCount eyeC = static_cast<OSVR_EyeCount>(eye);
    OSVR_SurfaceCount surfaces;
    osvrClientGetNumSurfacesForViewerEye(display->getDisplayConfig(), viewerC, eyeC, &surfaces);
    return surfaces;
}
        
void Java_osvr_clientkit_DisplayC_osvrClientGetRelativeViewportForViewerEyeSurface
  (JNIEnv * env, jobject obj, jobject displayHandle, jint viewer, jint eye, jint surface, jintArray viewport){
    osvr::clientkit::DisplayConfig *display = getHandle<osvr::clientkit::DisplayConfig>(env, displayHandle);
    OSVR_ViewportDimension mat[VIEWPORT_LENGTH] = { };
    OSVR_ViewerCount viewerC = static_cast<OSVR_ViewerCount>(viewer);
    OSVR_EyeCount eyeC = static_cast<OSVR_EyeCount>(eye);
    OSVR_SurfaceCount surfaceC = static_cast<OSVR_SurfaceCount>(surface);
    OSVR_ReturnCode ret =
                osvrClientGetRelativeViewportForViewerEyeSurface(
                    display->getDisplayConfig(), viewerC, eyeC, surfaceC, &mat[0],
                    &mat[1], &mat[2], &mat[3]);
    if(ret != OSVR_RETURN_SUCCESS){
        
    }
    setViewportData(env, obj, mat, viewport);
}

void Java_osvr_clientkit_DisplayC_osvrClientGetViewerEyeViewMatrixf(JNIEnv * env, jobject obj, jobject displayHandle, jint viewer, jint eye, jint flags, jfloatArray viewMatrix){
    osvr::clientkit::DisplayConfig *display = getHandle<osvr::clientkit::DisplayConfig>(env, displayHandle);
    float mat[VIEWMAT_LEN] = { };
    OSVR_ViewerCount viewerC = static_cast<OSVR_ViewerCount>(viewer);
    OSVR_EyeCount eyeC = static_cast<OSVR_EyeCount>(eye);
    OSVR_ReturnCode ret = osvrClientGetViewerEyeViewMatrixf(display->getDisplayConfig(), viewerC, eyeC, 0, mat);
    if(ret != OSVR_RETURN_SUCCESS){
        
    }
    setMatrixData(env, obj, mat, viewMatrix);
}

void Java_osvr_clientkit_DisplayC_osvrClientGetViewerEyeSurfaceProjectionMatrixf(JNIEnv * env, jobject obj, jobject displayHandle, jint viewer, jint eye, jint surface, jfloat near, jfloat far, jint flags, jfloatArray projMatrix){
    osvr::clientkit::DisplayConfig *display = getHandle<osvr::clientkit::DisplayConfig>(env, displayHandle);
    float mat[VIEWMAT_LEN] = { };
    OSVR_ViewerCount viewerC = static_cast<OSVR_ViewerCount>(viewer);
    OSVR_EyeCount eyeC = static_cast<OSVR_EyeCount>(eye);
    OSVR_SurfaceCount surfaceC = static_cast<OSVR_SurfaceCount>(surface);
    OSVR_ReturnCode ret = osvrClientGetViewerEyeSurfaceProjectionMatrixf(display->getDisplayConfig(), viewerC, eyeC, surfaceC, near, far, OSVR_MATRIX_COLMAJOR | OSVR_MATRIX_COLVECTORS |
                        OSVR_MATRIX_SIGNEDZ | OSVR_MATRIX_RHINPUT, mat);
    if(ret != OSVR_RETURN_SUCCESS){
        
    }
    setMatrixData(env, obj, mat, projMatrix);
}