/*
 * clustfunctions.c
 *
 *  Created on: Jul 15, 2014
 *
 * This library is meant to be used as an LD_PRELOAD before launching any
 * software that uses OpenCL. It then allows to record the calls to the
 * OpenCL functions with LTTng-ust events. In addition to recording the
 * calls to the OpenCL API, it will use (and require) NVIDIA's CUPTI
 * library to record data transfers between host and device as well as
 * kernel execution metrics.
 *
 * Copyright (C) 2014-2015 David Couturier <david.couturier@polymtl.ca>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; only
 * version 2.1 of the License.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "clust.h"
#include "clustfunctions.h"

#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

#if ENABLE_AMD_GPU_PERF_API == 1
#include <GPUPerfAPI.h>
#include <GPUPerfAPIFunctionTypes.h>
#endif

#define BUFFER_SIZE 10240

#define CL_CHECK(_expr)                                                         \
   do {                                                                         \
     cl_int _err = _expr;                                                       \
     if (_err == CL_SUCCESS)                                                    \
       break;                                                                   \
     fprintf(stderr, "%s: OpenCL Error: '%s' returned %d!\n", LIB_NAME,  #_expr, (int)_err);   \
     goto error;                                                                  \
   } while (0)

#ifndef DEBUG
#define debug(M, ...)
#else
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define FREE(ptr)                               \
  do {                                          \
    free(ptr);                                  \
    (ptr) = NULL;                               \
  } while(0)

void* lib = NULL;
void clustInit() {
	cl_uint i = 0;
	cl_uint j = 0;

	cl_device_id* devices = NULL;

	cl_uint numPlatforms = 0;
	CL_CHECK(libCL_clGetPlatformIDs(0, NULL, &numPlatforms));
	cl_platform_id* platforms = (cl_platform_id*)malloc(numPlatforms*sizeof(cl_platform_id));
	CL_CHECK(libCL_clGetPlatformIDs(numPlatforms, platforms, &numPlatforms));
	debug("Found %d platform%s:", numPlatforms, (numPlatforms > 1)? "s":"");
	for(i = 0; i < numPlatforms; i++) {
		debug("\tPlatform #%d", i + 1);
		char namebuffer[BUFFER_SIZE];
		char profilebuffer[BUFFER_SIZE];
		char versionbuffer[BUFFER_SIZE];
		char vendorbuffer[BUFFER_SIZE];
		char extensionsbuffer[BUFFER_SIZE];
		CL_CHECK(libCL_clGetPlatformInfo(platforms[i], CL_PLATFORM_NAME, BUFFER_SIZE, namebuffer, NULL));
		debug("\t\tName: %s", namebuffer);
		CL_CHECK(libCL_clGetPlatformInfo(platforms[i], CL_PLATFORM_PROFILE, BUFFER_SIZE, profilebuffer, NULL));
		debug("\t\tProfile: %s", profilebuffer);
		CL_CHECK(libCL_clGetPlatformInfo(platforms[i], CL_PLATFORM_VERSION, BUFFER_SIZE, versionbuffer, NULL));
		debug("\t\tVersion: %s", versionbuffer);
		CL_CHECK(libCL_clGetPlatformInfo(platforms[i], CL_PLATFORM_VENDOR, BUFFER_SIZE, vendorbuffer, NULL));
		debug("\t\tVendor: %s", vendorbuffer);
		CL_CHECK(libCL_clGetPlatformInfo(platforms[i], CL_PLATFORM_EXTENSIONS, BUFFER_SIZE, extensionsbuffer, NULL));
		debug("\t\tExtensions: %s", extensionsbuffer);

		cl_uint numDevices = 0;
		CL_CHECK(libCL_clGetDeviceIDs(platforms[i], CL_DEVICE_AVAILABLE, 0, NULL, &numDevices));
		devices = (cl_device_id*)malloc(numDevices*sizeof(cl_device_id));
		CL_CHECK(libCL_clGetDeviceIDs(platforms[i], CL_DEVICE_AVAILABLE, numDevices, devices, &numDevices));
		debug("\t\tFound %d device%s:", numDevices, (numDevices > 1)?"s":"");
		for(j = 0; j < numDevices; j++) {
			debug("\t\t\tDevice #%d:", j + 1);
			char devnameBuffer[BUFFER_SIZE];
			cl_device_type* devType = (cl_device_type*)malloc(sizeof(cl_device_type));
			CL_CHECK(libCL_clGetDeviceInfo(devices[j], CL_DEVICE_NAME, BUFFER_SIZE, devnameBuffer, NULL));
			debug("\t\t\t\tName: %s", devnameBuffer);
			CL_CHECK(libCL_clGetDeviceInfo(devices[j], CL_DEVICE_TYPE, sizeof(cl_device_type), devType, NULL));
			debug("\t\t\t\tType: %s", (*devType == CL_DEVICE_TYPE_CPU)?"CPU":((*devType == CL_DEVICE_TYPE_GPU)?"GPU":((*devType == CL_DEVICE_TYPE_ACCELERATOR)?"Accelerator":"DEFAULT")));
		}

		if(strstr(vendorbuffer, "AMD") || strstr(namebuffer, "AMD")) {
			// AMD DEVICE(S)
		} else if(strstr(vendorbuffer, "NVIDIA") || strstr(namebuffer, "NVIDIA")) {
			fprintf(stdout, "I :      %s\n", strstr(vendorbuffer, "AMD"));
		} else {
			fprintf(stdout, "%s: Unsupported platform: %s\n", LIB_NAME, namebuffer);
		}

		if(devices) FREE(devices);
	}
#if ENABLE_AMD_GPU_PERF_API == 1
	//GPA_Status ret = GPA_Initialize();
//	if(ret != GPA_STATUS_OK) {
//		fprintf(stderr, "%s: Error initializing GPUPerfAPI\n", LIB_NAME);
//		exit(EXIT_FAILURE);
//	}

	lib = dlopen("libGPUPerfAPICL.so", RTLD_LAZY);
	if(!lib) {
			fprintf(stderr, "%s: Unable to load %s\n", LIB_NAME, "libGPUPerfAPICL.so");
			exit(EXIT_FAILURE);
	}
	GPA_InitializePtrType initz = dlsym(lib, "GPA_Initialize");

	initz();
#endif
error:
	FREE(devices);
	FREE(platforms);
}

void clustContextCreated(cl_command_queue context) {
#if ENABLE_AMD_GPU_PERF_API == 1
	fprintf(stdout, "Context = %p\n", context);
	fflush(stdout);

		GPA_OpenContextPtrType initz = dlsym(lib, "GPA_OpenContext");
		initz(context);
		fprintf(stdout, "ssss = %p\n", context);
		fflush(stdout);
	GPA_Status ret = GPA_OpenContext(context);
	if(ret != GPA_STATUS_OK) {
		if(ret == GPA_STATUS_ERROR_COUNTERS_ALREADY_OPEN){
			fprintf(stdout, "YOUPPI\n");

			gpa_uint32 count = 0;
			ret = GPA_GetNumCounters(&count);
			if(ret == GPA_STATUS_OK) {
				fprintf(stdout, "Counter count = %d\n", count);
				int i = 0;
				const char* name = "";
				for(;i < count; i++) {
					GPA_GetCounterName(i, &name);
					fprintf(stdout, "Name = %s\n", name);
				}
			}

		} else {
			fprintf(stdout, "PATATE: %d\n", ret);
		}
	}
	/*
	gpa_uint32 count = 0;

	fprintf(stdout, "Context = %p\n", context);
	fflush(stdout);
	//GPA_GetNumCounters(&count);
	fprintf(stdout, "Count = %d\n", count);*/
#endif
}
