#include "osvr_util_OSVR_Quaternion_decl.h"
#include "Handle.h"
#include <string>
#include <iostream>

//osvr_util_OSVR_Quaternion::osvr_util_OSVR_Quaternion(){
//    
//}

void Java_osvr_util_OSVR_1Quaternion_initializeNative(JNIEnv * env, jobject obj){
    OSVR_Quaternion quat;
    setHandle(env, obj, &quat);
}