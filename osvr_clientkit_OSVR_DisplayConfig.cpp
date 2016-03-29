#include "osvr_clientkit_OSVR_DisplayConfig_decl.h"

#include "Handle.h"

#include <string>
#include <iostream>

osvr::clientkit::DisplayConfig m_displayConfig;

void Java_osvr_clientkit_OSVR_1DisplayConfig_initializeNative(JNIEnv * env, jobject obj, jobject jcontext){
    OSVR_ClientContext *context = getHandle<OSVR_ClientContext>(env, jcontext);
    osvr::clientkit::ClientContext clientContext(*context);
    m_displayConfig  = osvr::clientkit::DisplayConfig(clientContext);
//    m_displayConfig = OSVR_DisplayConfig(config);
    std::cout << "DisplayConfig_initializeNative"<< std::endl;
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
    OSVR_ViewerCount viewers;
//    osvrClientGetNumViewers(m_displayConfig, viewers);
    OSVR_ViewerCount numViewers =  m_displayConfig.getNumViewers();
    std::cout << "DisplayConfig_getNumViewers"<< std::endl;
    std::cout << viewers << std::endl;
    return (jint) viewers;
}

jobject Java_osvr_clientkit_OSVR_1DisplayConfig_getViewer(JNIEnv * env, jobject obj, jint viewerIndex, jobject holder){
    osvr::clientkit::Viewer viewer = m_displayConfig.getViewer(viewerIndex);
    setHandle(env, holder, &viewer);
    return (jobject) &holder;
}

jobject Java_osvr_clientkit_OSVR_1DisplayConfig_getEye(JNIEnv* env, jobject obj, jint viewerIndex, jint eyeIndex, jobject holder){
    osvr::clientkit::Eye eye = m_displayConfig.getEye(viewerIndex, eyeIndex);
    setHandle(env, holder, &eye);
    return (jobject) &holder;
}

jobject Java_osvr_clientkit_OSVR_1DisplayConfig_getSurface(JNIEnv* env, jobject obj, jint viewerIndex, jint eyeIndex, jint surfaceIndex, jobject holder){
//    osvr::clientkit::DisplayConfig *display = getHandle<osvr::clientkit::DisplayConfig>(env, obj);
    osvr::clientkit::Surface surface = m_displayConfig.getSurface(viewerIndex, eyeIndex, surfaceIndex);
    if(NULL == holder){
        jclass cls = env->FindClass("Losvr/clientkit/OSVR_Surface;");
        jmethodID constructor = env->GetMethodID(cls, "<init>", "()V");
        holder = env->NewObject(cls, constructor);
    }
    setHandle(env, holder, &surface);
    return (jobject) &holder;
}

jboolean Java_osvr_clientkit_OSVR_1DisplayConfig_valid(JNIEnv* env, jobject obj){
    osvr::clientkit::DisplayConfig *display = getHandle<osvr::clientkit::DisplayConfig>(env, obj);
    return (jboolean) display->valid();
}

