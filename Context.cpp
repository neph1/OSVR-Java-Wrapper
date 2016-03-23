
#include "osvr_clientkit_Context.h"

#ifndef INCLUDED_Context_h_GUID_DD0155F5_61A4_4A76_8C2E_D9614C7A9EBD
#define INCLUDED_Context_h_GUID_DD0155F5_61A4_4A76_8C2E_D9614C7A9EBD

// Internal Includes
#include <osvr/ClientKit/ContextC.h>
#include <osvr/ClientKit/ParametersC.h>
#include "Interface.h"
#include <osvr/Util/StringBufferBuilder.h>
#include "Handle.h"
// Library/third-party includes
// - none

// Standard includes
#include <string>
#include <stdexcept>
#include <iostream>
class{
    OSVR_ClientContext m_context;
    
    Context(const char applicationIdentifier[],
                                        uint32_t flags)
        : m_context(osvrClientInit(applicationIdentifier, flags)) {}

   Context(OSVR_ClientContext context)
        : m_context(context) {}

    ~ClientContext() { osvrClientShutdown(m_context); }
    
    void update() {
        printf("Update in ClientCOntext");
        OSVR_ReturnCode ret = osvrClientUpdate(m_context);
        if (OSVR_RETURN_SUCCESS != ret) {
            throw std::runtime_error("Error updating context.");
        }
    }

    Interface getInterface(const std::string &path) {
        OSVR_ClientInterface interface = NULL;
        OSVR_ReturnCode ret =
            osvrClientGetInterface(m_context, path.c_str(), &interface);
        if (OSVR_RETURN_SUCCESS != ret) {
            throw std::runtime_error(
                "Couldn't create interface because the path was invalid.");
        }

        return Interface(*this, interface);
    }

    jstring
    Java_osvr_clientkit_Context_getStringParameter(JNIEnv* env, jobject, jstring path) {
        size_t length = 0;
        OSVR_ReturnCode ret = osvrClientGetStringParameterLength(
            m_context, env->GetStringUTFChars( path , NULL ), &length);
        if (OSVR_RETURN_SUCCESS != ret) {
            throw std::runtime_error(
                "Invalid context or null reference to length variable.");
        }

        if (0 == length) {
            return env->NewStringUTF("");
        }

        util::StringBufferBuilder buf;

        ret = osvrClientGetStringParameter(m_context, env->GetStringUTFChars( path , NULL ),
                                           buf.getBufferOfSize(length), length);
        if (OSVR_RETURN_SUCCESS != ret) {
            throw std::runtime_error("Invalid context, null reference to "
                                     "buffer, or buffer is too small.");
        }
        jstring string = env->NewStringUTF(buf.str().c_str());
        return string;
    }

    void free(Interface &iface) {
        OSVR_ReturnCode ret = osvrClientFreeInterface(m_context, iface.get());
        if (OSVR_RETURN_SUCCESS != ret) {
            throw std::logic_error(
                "Could not free interface: either null or already freed!");
        }
        // Null out the interface.
        iface = Interface(*this, NULL);
    }

    OSVR_ClientContext get() { return m_context; }

    jboolean
    Java_osvr_clientkit_Context_checkStatus(JNIEnv*, jobject) const {
        return osvrClientCheckStatus(m_context) == OSVR_RETURN_SUCCESS;
    }
    
    void
    Java_osvr_clientkit_Context_dispose(JNIEnv* env, jobject obj){
    jobject *context = getHandle<jobject>(env, obj);
    setHandle<jlong>(env, obj, 0);
    delete context;
    }
 
}