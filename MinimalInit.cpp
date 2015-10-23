#include "osvr_java_examples_clients_MinimalInit.h"
#include <osvr/ClientKit/ClientKit.h>

/* Standard includes */
#include <iostream>

jint
Java_osvr_java_examples_clients_MinimalInit_main(JNIEnv *env, jobject obj)
{
    osvr::clientkit::ClientContext context("com.osvr.exampleclients.MinimalInit");
    std::cout << "OK, library initialized." << std::endl;

    // Pretend that this is your application's mainloop.
    for (int i = 0; i < 1000000; ++i) {
        context.update();
    }
    std::cout << "Library shut down, exiting." << std::endl;
    return 0;
}
