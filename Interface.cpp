#include "osvr_clientkit_Interface.h"
#include "Interface_decl.h"
#include "osvr_util_callback_OSVR_PoseCallback_decl.h"
#include "Handle.h"

#include <osvr/ClientKit/InterfaceC.h>
#include <osvr/ClientKit/InterfaceStateC.h>
#include <osvr/ClientKit/InterfaceCallbackC.h>
#include <string>
#include <iostream>
#include <osvr/Util/ClientCallbackTypesC.h>
 #ifndef INCLUDED_Interface_h_GUID_5D5B1FAD_AD72_4216_9FB6_6483D6EE7DF1
#define INCLUDED_Interface_h_GUID_5D5B1FAD_AD72_4216_9FB6_6483D6EE7DF1

OSVR_ClientInterface m_interface;
//osvr_clientkit_ContextWrapper m_context;

using namespace std;
//


Interface::Interface(){
    
}

Interface::Interface(OSVR_ClientInterface iface){
    m_interface = iface;
}

void Java_osvr_clientkit_Interface_registerCallback(JNIEnv* env, jobject obj, jobject callback, jint type, jstring path){
//    m_interface = getHandle<OSVR_ClientInterface>(env, obj);
//    std::cout << "registerCallback"<< std::endl;
    switch (type) {
        case 0: // Pose
//            PoseCallback javaCallback;
//            
//            OSVR_PoseCallback *nativeCallback = getHandle<OSVR_PoseCallback>(env, callback);
//            osvrRegisterPoseCallback(m_interface, &javaCallback.getCallback, NULL);
//            osvrRegisterPoseCallback(m_interface, javaCallback.getCallback(), NULL);
            std::cout << "register Pose Callback"<< std::endl;
            break;
    }
    
}

#endif