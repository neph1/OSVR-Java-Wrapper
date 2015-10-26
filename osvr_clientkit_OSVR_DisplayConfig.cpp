#include "osvr_clientkit_OSVR_DisplayConfig_decl.h"

#include "Handle.h"

#include <string>
#include <iostream>

void Java_osvr_clientkit_OSVR_1DisplayConfig_initializeNative(JNIEnv * env, jobject obj, jobject jcontext){
    OSVR_ClientContext *context = getHandle<OSVR_ClientContext>(env, jcontext);
    osvr::clientkit::ClientContext clientContext(*context);
    osvr::clientkit::DisplayConfig config = osvr::clientkit::DisplayConfig(clientContext);
    std::cout << "DisplayConfig_initializeNative"<< std::endl;
    setHandle(env, obj, &config);
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
    osvr::clientkit::DisplayConfig *display = getHandle<osvr::clientkit::DisplayConfig>(env, obj);
    OSVR_ViewerCount numViewers = display->getNumViewers();
    return (jint) numViewers;
}

jobject Java_osvr_clientkit_OSVR_1DisplayConfig_getViewer(JNIEnv * env, jobject obj, jint viewerIndex, jobject holder){
    osvr::clientkit::DisplayConfig *display = getHandle<osvr::clientkit::DisplayConfig>(env, obj);
    osvr::clientkit::Viewer viewer = display->getViewer(viewerIndex);
    if(NULL == holder){
        jclass cls = env->FindClass("Losvr/clientkit/OSVR_Viewer;");
        jmethodID constructor = env->GetMethodID(cls, "<init>", "()V");
        holder = env->NewObject(cls, constructor);
        std::cout << "Created holder "<< std::endl;
    }
    
    setHandle(env, holder, &viewer);
    return (jobject) &holder;
}

jobject Java_osvr_clientkit_OSVR_1DisplayConfig_getEye(JNIEnv* env, jobject obj, jint viewerIndex, jint eyeIndex, jobject holder){
    osvr::clientkit::DisplayConfig *display = getHandle<osvr::clientkit::DisplayConfig>(env, obj);
    osvr::clientkit::Eye eye = display->getEye(viewerIndex, eyeIndex);
    if(NULL == holder){
        jclass cls = env->FindClass("Losvr/clientkit/OSVR_Eye;");
        jmethodID constructor = env->GetMethodID(cls, "<init>", "()V");
        holder = env->NewObject(cls, constructor);
    }
    setHandle(env, holder, &eye);
    return (jobject) &holder;
}

jobject Java_osvr_clientkit_OSVR_1DisplayConfig_getSurface(JNIEnv* env, jobject obj, jint viewerIndex, jint eyeIndex, jint surfaceIndex, jobject holder){
    osvr::clientkit::DisplayConfig *display = getHandle<osvr::clientkit::DisplayConfig>(env, obj);
    osvr::clientkit::Surface surface = display->getSurface(viewerIndex, eyeIndex, surfaceIndex);
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

