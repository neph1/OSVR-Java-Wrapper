#include "osvr_util_OSVR_Vec3_decl.h"
#include "Handle.h"
#include <string>
#include <iostream>

//osvr_util_OSVR_Vec3::osvr_util_OSVR_Vec3(){
//    
//}
#define LEN 3

void Java_osvr_util_OSVR_1Vec3_initializeNative(JNIEnv * env, jobject obj){
    OSVR_Vec3 quat;
    setHandle(env, obj, &quat);
}
