/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class osvr_clientkit_Interface */

#ifndef _Included_osvr_clientkit_Interface
#define _Included_osvr_clientkit_Interface
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     osvr_clientkit_Interface
 * Method:    initializeNative
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_osvr_clientkit_Interface_initializeNative
  (JNIEnv *, jobject);

/*
 * Class:     osvr_clientkit_Interface
 * Method:    freeNative
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_osvr_clientkit_Interface_freeNative
  (JNIEnv *, jobject);

/*
 * Class:     osvr_clientkit_Interface
 * Method:    registerCallback
 * Signature: (Losvr/util/callback/OSVR_Callback;ILjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_osvr_clientkit_Interface_registerCallback
  (JNIEnv *, jobject, jobject, jint, jstring);

#ifdef __cplusplus
}
#endif
#endif
