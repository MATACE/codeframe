#ifndef SERVICE_H
#define SERVICE_H

// C library
#include <glog/logging.h>
#include <stdio.h>

// C++ library
#include <iostream>
#include <string>
#include <map>

// Ownself library

// Using namespace
using namespace std;

// Class 
class Service
{
public:
    Service();
    virtual ~Service();
    /**
     *  @name Config Glog.
     */
    int  Config(string GlogFilePath);

    /**
     * @name Start And Stop. 
     */
    int  Start(void);
    int  Stop(void);

    /**
     * @name Demo thread. 
     */
    void ServiceRun(void);
    
private:
    typedef std::map<std::string, pthread_t> ThreadMap;
    ThreadMap tm_;

};

#endif // SERVICE_H