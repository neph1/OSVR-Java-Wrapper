#include "osvr_util_callback_OSVR_PoseCallback.h"
#include "Handle.h"
#include <osvr/Util/ClientCallbackTypesC.h>

void Java_osvr_util_callback_OSVR_1PoseCallback_initializeNative(JNIEnv* env, jobject obj){
    OSVR_PoseCallback callback;
    
    setHandle(env, obj, &callback);
}


