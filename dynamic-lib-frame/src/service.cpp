#include <iostream>
#include <fstream>
#include <thread>
#include <glog/logging.h>
#include <stdio.h>
#include "service.h"

Service::Service()
{
    // TODO:
}

Service::~Service()
{
    // TODO:
    Stop();
}

/**
 * @brief Get path of glog path.
 * @param [in] GlogFilePath Glog save path.
 * @retval No description.
 */

int Service::Config(string GlogFilePath)
{
    // Init glog
    google::InitGoogleLogging("212");
    // INFO WARNING ERROR FATAL
    FLAGS_stderrthreshold = google::GLOG_INFO;
    // FLAGS_stderrthreshold = google::GLOG_WARNING;
    // FLAGS_stderrthreshold = google::GLOG_ERROR;
    // FLAGS_stderrthreshold = google::GLOG_FATAL;

    FLAGS_log_dir = GlogFilePath;
    FLAGS_logbufsecs = 0;   // Print log in real time.
    FLAGS_max_log_size = 6; // Max log size 6MB.
    FLAGS_colorlogtostderr = true; // Set glog color.

    return 1;
}

/**
 * @brief Create need Thread to start.
 */

int Service::Start(void)
{
    LOG(INFO) << "Service::Start";

    // Create thread1 to do service.
    std::thread t1(&Service::ServiceRun, this);

    // Get thread native handle.
    tm_["ServiceRun"]     = t1.native_handle();

    // Detaches the thread represented by the object from the calling thread, allowing them to execute independently from each other.
    // Both threads continue without blocking nor synchronizing in any way. Note that when either one ends execution, its resources are released.
    // After a call to this function, the thread object becomes non-joinable and can be destroyed safely.
    t1.detach();
}

/**
 * @brief Stop start create thread and free all apply.
 */

int Service::Stop(void)
{
    // Close the pthread by pthread native handle.
    pthread_cancel(tm_["ServiceRun"]);

    // Removes all elements from the map.
    tm_.clear();
    // Close glog log.
    google::ShutdownGoogleLogging();

    // Delete all new point.
}

void Service::ServiceRun(void)
{
    while (1)
    {
        // TODO:
        sleep(5);
    }
    
}