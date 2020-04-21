#ifndef SERVICE_H_
#define SERVICE_H_

#include <iostream>

#include <glog/logging.h>

using namespace std;

class Service
{

public:
    Service();
    virtual ~Service();

    void Start();
    void GlogInit(string glog_name, string glog_leve, string glog_path);
};

#endif //SERVICE_H_