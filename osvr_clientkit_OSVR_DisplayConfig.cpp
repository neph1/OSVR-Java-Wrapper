#include "osvr_clientkit_OSVR_DisplayConfig_decl.h"

#include "Handle.h"
#include "osvr_clientkit_OSVR_ContextWrapper_decl.h"

#include <string>
#include <iostream>

osvr::clientkit::DisplayConfig m_displayConfig;

void Java_osvr_clientkit_OSVR_1DisplayConfig_initializeNative(JNIEnv * env, jobject obj, jobject jcontext){
    OSVR_ClientContext *context = getHandle<OSVR_ClientContext>(env, jcontext);
    OSVR_DisplayConfig cfg = NULL;
    OSVR_ReturnCode result = osvrClientGetDisplay(*context, &cfg);
    osvr::clientkit::UnderlyingDisplayConfigPtr ret(cfg, &osvrClientFreeDisplay);
    m_displayConfig  = osvr::clientkit::DisplayConfig(ret);
    std::cout << "DisplayConfig_initializeNative"<< std::endl;
    std::cout << &m_displayConfig << std::endl;
    setHandle(env, obj, &m_displayConfig);
}

void Java_osvr_clientkit_OSVR_1DisplayConfig_disposeNative(JNIEnv * env, jobject obj){
    osvr::clientkit::DisplayConfig *display = getHandle<osvr::clientkit::DisplayConfig>(env, obj);
    setHandle<jlong>(env, obj, 0);
    delete display;
}

//jint Java_osvr_clientkit_OSVR_1DisplayConfig_getNumDisplayInputs(JNIEnv * env, jobject obj){
//    osvr::clientkit::DisplayConfig *display = getHandle<osvr::clientkit::DisplayConfig>(env, obj);
//    return (jint)*display->get
//}

jint Java_osvr_clientkit_OSVR_1DisplayConfig_getNumViewers(JNIEnv * env, jobject obj){
//    osvr::clientkit::DisplayConfig *display = getHandle<osvr::clientkit::DisplayConfig>(env, obj);
    OSVR_ViewerCount numViewers =  m_displayConfig.getNumViewers();
    std::cout << "DisplayConfig_getNumViewers"<< std::endl;
    std::cout << numViewers << std::endl;
    return (jint) numViewers;
}

jobject Java_osvr_clientkit_OSVR_1DisplayConfig_getViewer(JNIEnv * env, jobject obj, jint viewerIndex, jobject holder){
    osvr::clientkit::Viewer viewer = m_displayConfig.getViewer(viewerIndex);
    jclass c = env->GetObjectClass(holder);
    jfieldID fieldID = env->GetFieldID(c, "viewerID", "I");
    env->SetIntField(holder, fieldID, viewer.getViewerID());
    setHandle(env, holder, &viewer);
    return (jobject) holder;
}

jobject Java_osvr_clientkit_OSVR_1DisplayConfig_getEye(JNIEnv* env, jobject obj, jlong viewerIndex, jint eyeIndex, jobject holder){
    osvr::clientkit::Eye eye = m_displayConfig.getEye(viewerIndex, eyeIndex);
    jclass c = env->GetObjectClass(holder);
    jfieldID fieldID = env->GetFieldID(c, "eyeID", "I");
    env->SetIntField(holder, fieldID, eye.getEyeID());
    setHandle(env, holder, &eye);
    return (jobject) NULL;
}

jobject Java_osvr_clientkit_OSVR_1DisplayConfig_getSurface(JNIEnv* env, jobject obj, jint viewerIndex, jint eyeIndex, jint surfaceIndex, jobject holder){
    osvr::clientkit::Surface surface = m_displayConfig.getSurface((int)viewerIndex, (int)eyeIndex, (int)surfaceIndex);
    jclass c = env->GetObjectClass(holder);
    jfieldID fieldID = env->GetFieldID(c, "surfaceID", "I");
    env->SetIntField(holder, fieldID, surface.getSurfaceID());
    setHandle(env, holder, &surface);
    return (jobject) NULL;
}

jboolean Java_osvr_clientkit_OSVR_1DisplayConfig_valid(JNIEnv* env, jobject obj){
    return (jboolean) m_displayConfig.valid();
}

jboolean Java_osvr_clientkit_OSVR_1DisplayConfig_checkStartup(JNIEnv* env, jobject obj){
    return (jboolean) m_displayConfig.checkStartup();
}

