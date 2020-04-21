#include "service.h"

Service::Service()
{

}

Service::~Service()
{

}

void Service::Start()
{
    // Init Glog;
    GlogInit("Study", "INFO", "./log");

    LOG(INFO) << "Service Start";

    while (1) {
        sleep(1);
    }
    
}

/**
 * @brief   Init the Glog Log.
 * @param[in]   glog_name   The glog usename.
 * @param[in]   glog_leve   The Glog log level (INFO, WARNING, ERROR, FATAL)
 * @param[in]   glog_path   The Glog log save path.
 */
void Service::GlogInit(string glog_name, string glog_leve, string glog_path)
{
    // Init glog
    google::InitGoogleLogging(glog_name.c_str());

    // INFO WARNING ERROR FATAL
    if (glog_leve == "INFO") {
        FLAGS_stderrthreshold = google::GLOG_INFO;
    } else if (glog_leve == "WARNING") {
        FLAGS_stderrthreshold = google::GLOG_WARNING;
    } else if (glog_leve == "ERROR") {
        FLAGS_stderrthreshold = google::GLOG_ERROR;
    } else if (glog_leve == "FATAL") {
        FLAGS_stderrthreshold = google::GLOG_FATAL;
    }

    FLAGS_log_dir = glog_path;
    FLAGS_logbufsecs = 0;   // Print log in real time.
    FLAGS_max_log_size = 6; // Max log size 6MB.
    FLAGS_colorlogtostderr = true;
}