/** @file
    @brief Header

    @date 2014

    @author
    Sensics, Inc.
    <http://sensics.com/osvr>
*/

// Copyright 2014 Sensics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//#include "osvr_clientkit_Context.h"

#ifndef INCLUDED_Context_h_GUID_DD0155F5_61A4_4A76_8C2E_D9614C7A9EBD
#define INCLUDED_Context_h_GUID_DD0155F5_61A4_4A76_8C2E_D9614C7A9EBD

#include "osvr_clientkit_ContextWrapper.h"
#include "osvr_clientkit_Interface.h"
#include "Interface_decl.h"
#include "Handle.h"
#include <osvr/ClientKit/ContextC.h>
#include <osvr/ClientKit/InterfaceC.h>
#include <osvr/ClientKit/ParametersC.h>
#include <boost/noncopyable.hpp>
#include <osvr/Util/StringBufferBuilder.h>

// Standard includes
#include <string>
#include <iostream>

// Library/third-party includes
// - none
using namespace std;

class osvr_clientkit_ContextWrapper{
    private:
        
    public:
};

OSVR_ClientContext m_context;

jlong Java_osvr_clientkit_ContextWrapper_initializeNative(JNIEnv* env, jobject obj, jstring contextName){
//    osvr::clientkit::ClientContext context(env->GetStringUTFChars( contextName, NULL));
    const char *nameString = env->GetStringUTFChars(contextName, NULL);
    m_context = OSVR_ClientContext(osvrClientInit(nameString));
    setHandle(env, obj, &m_context);
    std::cout << "initializeNative"<< std::endl;
    env->ReleaseStringUTFChars(contextName, nameString);
//    m_Context = &context;
    return (jlong) &m_context;
}

void Java_osvr_clientkit_ContextWrapper_updateNative(JNIEnv* env, jobject obj) {
    //OSVR_ClientContext *m_context = getHandle<OSVR_ClientContext>(env, obj);
    OSVR_ReturnCode ret = osvrClientUpdate(m_context);
    if (OSVR_RETURN_SUCCESS != ret) {
        throw std::runtime_error("Error updating context.");
    }
}

jboolean Java_osvr_clientkit_ContextWrapper_checkStatus(JNIEnv* env, jobject obj) {
    //OSVR_ClientContext *m_context = getHandle<OSVR_ClientContext>(env, obj);
    return osvrClientCheckStatus(m_context) == OSVR_RETURN_SUCCESS;
}

void Java_osvr_clientkit_ContextWrapper_dispose(JNIEnv* env, jobject obj){
    jobject *context = getHandle<jobject>(env, obj);
    setHandle<jlong>(env, obj, 0);
    std::cout << "dispose"<< std::endl;
    delete context;
}

jlong Java_osvr_clientkit_ContextWrapper_getInterface(JNIEnv* env, jobject obj, jstring path, jobject interfaceHolder){
//    OSVR_ClientContext *m_context = getHandle<OSVR_ClientContext>(env, obj);
    OSVR_ClientInterface *interface = getHandle<OSVR_ClientInterface>(env, interfaceHolder);
    const char *pathString = env->GetStringUTFChars(path, NULL);
    OSVR_ReturnCode ret =
        osvrClientGetInterface(m_context, pathString, interface);
    if (OSVR_RETURN_SUCCESS != ret) {
        throw std::runtime_error(
            "Couldn't create interface because the path was invalid.");
    }
    env->ReleaseStringUTFChars(path, pathString);
    std::cout << "getInterface"<< std::endl;
//    Interface interfaceWrapper(interface);
    setHandle(env, interfaceHolder, *interface);
    return (jlong) 0;
}

jstring Java_osvr_clientkit_ContextWrapper_getStringParameter(JNIEnv* env, jobject obj, jstring paramName){
    const char *paramString = env->GetStringUTFChars(paramName, NULL);
    OSVR_ClientContext *m_context = getHandle<OSVR_ClientContext>(env, obj);
    
    size_t length = 0;
        OSVR_ReturnCode ret = osvrClientGetStringParameterLength(
            *m_context, paramString, &length);
        if (OSVR_RETURN_SUCCESS != ret) {
            throw std::runtime_error(
                "Invalid context or null reference to length variable.");
        }

        if (0 == length) {
            return env->NewStringUTF("");
        }

        osvr::util::StringBufferBuilder buf;

        ret = osvrClientGetStringParameter(*m_context, paramString,
                                           buf.getBufferOfSize(length), length);
        if (OSVR_RETURN_SUCCESS != ret) {
            throw std::runtime_error("Invalid context, null reference to "
                                     "buffer, or buffer is too small.");
        }
        env->ReleaseStringUTFChars(paramName, paramString);
        return env->NewStringUTF(buf.str().c_str());
}

#endif // INCLUDED_Context_h_GUID_DD0155F5_61A4_4A76_8C2E_D9614C7A9EBD

