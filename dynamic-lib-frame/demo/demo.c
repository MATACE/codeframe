#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dlfcn.h>
#include "codeframe.h"

typedef int (*FuncType_CodeFramDrvInit)(void* param);

/**
 * @brief Loading dynamic library.
 */
void *LoadDLL(char *dllname)
{
	void *handle;
	handle = dlopen(dllname, RTLD_LAZY | RTLD_GLOBAL);
	if (!handle) {
		printf("%s->%s\n", dllname, dlerror());
		return NULL;
	}

	return handle;
}

/**
 * @brief Close dynamic library.
 */
int ReLoadDLL(void *handle)
{
	return dlclose(handle);
}

/**
 *@brief Get api from dynamic library. 
 */
void *GetDLLAPI(void *handle, const char *symbol)
{
	void *api;
	api = (void*)dlsym(handle, symbol);
	if (!api) {
		printf("%s->%s%d\n", symbol, dlerror(), __LINE__);
		ReLoadDLL(handle);
		return NULL;
	}

	return api;
}

int main(int argc, char const *argv[])
{
	void *handle;
	void *api;

    // NOTE: If your project program need anyohter library then add them as the follow format. 
    // Add the glog dynamic libs.
	LoadDLL("libglog.so.0");

	handle = LoadDLL("./libcodeframe.so.1");
	if (!handle) {
		printf("%s->%d err\n", __func__, __LINE__);
		return -13;
	}

	// Get CodeFrame Api form CodeFrame.so.1 library.
	FuncType_CodeFramDrvInit ServiceDrvInit = GetDLLAPI(handle, "ServiceDrvInit");
	if (!ServiceDrvInit) {
		printf("%s->%d err\n", __func__, __LINE__);
		return -13;
	}

	SERVICE_PARAM_T param;
	// Set the save glog log path.
	strcpy(param.glog_path, "./log");

	// Run Service
	ServiceDrvInit(&param);

	while (1)
	{
		sleep(1);
	}
    
	return 0;
}
