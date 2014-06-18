/*
 * clust.h
 *
 *  Created on: Jun 18, 2014
 *      Author: david
 */

#ifndef CLUST_H_
#define CLUST_H_

#include <CL/cl.h>

#define LIB_NAME "libCLUST"
#define LIBCL_NAME "libGL.so"

#define LIBCL_GET_PLATFORM_IDS_STR "clGetPlatformIDs"
#define LIBCL_GET_DEVICE_IDS_STR "clGetDeviceIDs"

// OpenCL version 1.2: https://www.khronos.org/registry/cl/api/1.2/cl.h

typedef void* (*cl_api_call_clGetPlatformIDs)(cl_uint          /* num_entries */,
        cl_platform_id * /* platforms */,
        cl_uint *        /* num_platforms */) CL_API_SUFFIX__VERSION_1_0;

typedef void* (*cl_api_call_clGetPlatformInfo)(cl_platform_id   /* platform */,
        cl_platform_info /* param_name */,
        size_t           /* param_value_size */,
        void *           /* param_value */,
        size_t *         /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;

typedef void* (*cl_api_call_clGetDeviceIDs)(cl_platform_id   /* platform */,
        cl_device_type   /* device_type */,
        cl_uint          /* num_entries */,
        cl_device_id *   /* devices */,
        cl_uint *        /* num_devices */) CL_API_SUFFIX__VERSION_1_0;

cl_api_call_clGetPlatformIDs libCL_clGetPlatformIDs;
cl_api_call_clGetPlatformInfo libCL_clGetPlatformInfo;
cl_api_call_clGetDeviceIDs libCL_clGetDeviceIDs;

static void init_libcl_symbols();
void doStuff();

#endif /* CLUST_H_ */
