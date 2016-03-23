#include "osvr_util_callback_OSVR_PoseCallback_decl.h"
#include "Interface_decl.h"
#include <iostream>

PoseCallback::PoseCallback(){
}



void callback(void * /*userdata*/,
                       const OSVR_TimeValue * /*timestamp*/,
                       const OSVR_PoseReport *report) {
    std::cout << "Got POSE report: Position = ("
              << report->pose.translation.data[0] << ", "
              << report->pose.translation.data[1] << ", "
              << report->pose.translation.data[2] << "), orientation = ("
              << osvrQuatGetW(&(report->pose.rotation)) << ", ("
              << osvrQuatGetX(&(report->pose.rotation)) << ", "
              << osvrQuatGetY(&(report->pose.rotation)) << ", "
              << osvrQuatGetZ(&(report->pose.rotation)) << "))" << std::endl;
}

