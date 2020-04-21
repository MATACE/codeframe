#include "service.h"

#ifdef __cplusplus
extern "C" {
#endif

using namespace std;

int DrvInit()
{
    Service Service;
    
    Service.Start();
}

#ifdef __cplusplus
}
#endif