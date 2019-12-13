#include "service.h"
#include "codeframe.h"

using namespace std;

extern "C" {
    Service Service;

    int ServiceDrvInit(void* param)
    {
        /// Start service threads.
        SERVICE_PARAM_T* pServiceParam = (SERVICE_PARAM_T*)param;

        int ret = Service.Config(pServiceParam->glog_path);
        if (ret < 0) {
            printf("Error: The glog file path not exist.\n");
            return -1;
        }

        Service.Start();
    }
}