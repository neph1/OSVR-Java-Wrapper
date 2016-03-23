/* 
 * File:   osvr_java_util_callback_PoseCallback_decl.h
 * Author: Rickard
 *
 * Created on den 22 oktober 2015, 13:25
 */
#include "osvr_util_callback_OSVR_PoseCallback.h"
#include <osvr/Util/TimeValueC.h>
#include <osvr/Util/ClientReportTypesC.h>
#include <osvr/Util/ClientCallbackTypesC.h>

#ifndef OSVR_UTIL_CALLBACK_POSECALLBACK_DECL_H
#define	OSVR_UTIL_CALLBACK_POSECALLBACK_DECL_H

class PoseCallback{
private:
//    OSVR_PoseCallback callback;
public:
    PoseCallback();
    
    PoseCallback(OSVR_PoseCallback callback);
    
    callback(void * /*userdata*/,
                       const OSVR_TimeValue * /*timestamp*/,
                       const OSVR_PoseReport *report);
    
    OSVR_PoseCallback getCallback();
};

#endif	/* OSVR_JAVA_UTIL_CALLBACK_POSECALLBACK_DECL_H */

