/* 
 * File:   Interface_decl.h
 * Author: Rickard
 *
 * Created on den 22 oktober 2015, 11:16
 */

#ifndef INTERFACE_DECL_H
#define	INTERFACE_DECL_H

#include <osvr/Util/ClientCallbackTypesC.h>
#include <osvr/Util/ClientOpaqueTypesC.h>
#include <osvr/Util/BoostDeletable.h>

class Interface{
private:
//    OSVR_ClientInterface m_interface;
//    osvr_clientkit_ContextWrapper m_context;
//    util::boost_util::DeletableList m_deletables;
  public:
      Interface();
      Interface(OSVR_ClientInterface iface);
      void Java_osvr_clientkit_Interface_registerCallback(JNIEnv* env, jobject obj, jobject callback, jint type, jstring path);
};

#endif	/* INTERFACE_DECL_H */

