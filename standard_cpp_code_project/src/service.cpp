#include "service.h"

Service::Service()
{
    // Set glog paramter.
    string glog_name = "pro";
    string glog_path = "./log";
    string glog_level = CMAKE_BUILD_GLOG_LOG_LEVEL;

    // Init Glog;
    GlogInit(glog_name, glog_level, glog_path);
}

Service::~Service()
{

}

void Service::Start()
{
    // Get the dynamic lib version.
    LOG(INFO) << "Dynamic Lib Version: " << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH;

    LOG(INFO) << "Service Start";

    while (1) {
        sleep(1);
    }
    
}

void Service::GlogInit(string glog_name, string glog_leve, string glog_path)
{
    // Create hte glog log path.
    if (!(access(glog_path.c_str(), F_OK) == 0)) {
        system("mkdir ./log");
    }

    // Init glog
    string c_glog_name = glog_name;
    google::InitGoogleLogging(c_glog_name.c_str());

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