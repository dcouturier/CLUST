/*
 * clust.c
 *
 *  Created on: Jun 18, 2014
 *      Author: david
 */

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <GL/gl.h>

#include "clust.h"

cl_api_call_clGetPlatformIDs libCL_clGetPlatformIDs;
cl_api_call_clGetPlatformInfo libCL_clGetPlatformInfo;
cl_api_call_clGetDeviceIDs libCL_clGetDeviceIDs;
cl_api_call_clGetDeviceInfo libCL_clGetDeviceInfo;
cl_api_call_clCreateContext libCL_clCreateContext;
cl_api_call_clCreateContextFromType libCL_clCreateContextFromType;
cl_api_call_clRetainContext libCL_clRetainContext;
cl_api_call_clReleaseContext libCL_clReleaseContext;
cl_api_call_clGetContextInfo libCL_clGetContextInfo;
cl_api_call_clCreateCommandQueue libCL_clCreateCommandQueue;
cl_api_call_clRetainCommandQueue libCL_clRetainCommandQueue;
cl_api_call_clReleaseCommandQueue libCL_clReleaseCommandQueue;
cl_api_call_clGetCommandQueueInfo libCL_clGetCommandQueueInfo;

__attribute__((constructor)) void libCLUST() {
#ifdef DEBUG
	fprintf(stdout, "%s: OpenCL Symbols being replaced...\n", LIB_NAME);
#endif
	init_libcl_symbols();
}

void* dlSymFunction(void* libPtr, const char* functionName) {
	void* ptr;
	*(void**)(&ptr) = dlsym(libPtr, LIBCL_GET_PLATFORM_IDS_STR);
	if(!ptr) {
		fprintf(stderr, "%s: Unable to load %s", LIB_NAME, functionName);
		exit(EXIT_FAILURE);
	}
	return ptr;
}

void init_libcl_symbols() {
	void* libcl_ptr;

	dlerror();
	libcl_ptr = dlopen(LIBCL_NAME, RTLD_LAZY);

	if(!libcl_ptr) {
		fprintf(stderr, "%s: Unable to load %s", LIB_NAME, LIBCL_NAME);
		exit(EXIT_FAILURE);
	}

	dlerror();
	libCL_clGetPlatformIDs = (cl_api_call_clGetPlatformIDs) dlSymFunction(libcl_ptr, LIBCL_GET_PLATFORM_IDS_STR);
	libCL_clGetPlatformInfo = (cl_api_call_clGetPlatformInfo) dlSymFunction(libcl_ptr, LIBCL_GET_PLATFORM_INFO_STR);
	libCL_clGetDeviceIDs = (cl_api_call_clGetDeviceIDs) dlSymFunction(libcl_ptr, LIBCL_GET_DEVICE_IDS_STR);
	libCL_clGetDeviceInfo = (cl_api_call_clGetDeviceInfo) dlSymFunction(libcl_ptr, LIBCL_GET_DEVICE_INFO_STR);
	libCL_clCreateContext = (cl_api_call_clCreateContext) dlSymFunction(libcl_ptr, LIBCL_CREATE_CONTEXT_STR);
	libCL_clCreateContextFromType = (cl_api_call_clCreateContextFromType) dlSymFunction(libcl_ptr, LIBCL_CREATE_CONTEXT_FROM_TYPE_STR);
	libCL_clRetainContext = (cl_api_call_clRetainContext) dlSymFunction(libcl_ptr, LIBCL_RETAIN_CONTEXT_STR);
	libCL_clReleaseContext = (cl_api_call_clReleaseContext) dlSymFunction(libcl_ptr, LIBCL_RELEASE_CONTEXT_STR);
	libCL_clGetContextInfo = (cl_api_call_clGetContextInfo) dlSymFunction(libcl_ptr, LIBCL_GET_CONTEXT_INFO_STR);
	libCL_clCreateCommandQueue = (cl_api_call_clCreateCommandQueue) dlSymFunction(libcl_ptr, LIBCL_CREATE_COMMAND_QUEUE_STR);
	libCL_clRetainCommandQueue = (cl_api_call_clRetainCommandQueue) dlSymFunction(libcl_ptr, LIBCL_RETAIN_COMMAND_QUEUE_STR);
	libCL_clReleaseCommandQueue = (cl_api_call_clReleaseCommandQueue) dlSymFunction(libcl_ptr, LIBCL_RELEASE_COMMAND_QUEUE_STR);
	libCL_clGetCommandQueueInfo = (cl_api_call_clGetCommandQueueInfo) dlSymFunction(libcl_ptr, LIBCL_GET_COMMAND_QUEUE_STR);
//	libCL_cl = (cl_api_call_cl) dlsymFunction(libcl_ptr, LIBCL_);

#ifdef DEBUG
	fprintf(stdout, "%s: Symbols initialized!\n", LIB_NAME);
#endif
}

CL_API_ENTRY cl_int CL_API_CALL clGetPlatformIDs(cl_uint num_entries, cl_platform_id * platforms, cl_uint * num_platforms) CL_API_SUFFIX__VERSION_1_0 {
#ifdef DEBUG
	fprintf(stdout, "%s: %s\n", LIB_NAME, LIBCL_GET_PLATFORM_IDS_STR);
	fflush(stdout);
#endif
	return libCL_clGetPlatformIDs(num_entries,platforms,num_platforms);
}
CL_API_ENTRY cl_int CL_API_CALL clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) CL_API_SUFFIX__VERSION_1_0 {
#ifdef DEBUG
	fprintf(stdout, "%s: %s(%d, %s, %d, %d, %d)\n", LIB_NAME, LIBCL_GET_PLATFORM_INFO_STR, platform, param_name, param_value_size, param_value, *param_value_size_ret);
	fflush(stdout);
#endif
	return libCL_clGetPlatformInfo(platform, param_name, param_value_size, &param_value, param_value_size_ret);
}
CL_API_ENTRY cl_int CL_API_CALL clGetDeviceIDs(cl_platform_id platform, cl_device_type device_type, cl_uint num_entries, cl_device_id * devices, cl_uint * num_devices) CL_API_SUFFIX__VERSION_1_0 {
#ifdef DEBUG
	fprintf(stdout, "%s: %s\n", LIB_NAME, LIBCL_GET_DEVICE_IDS_STR);
	fflush(stdout);
#endif
	return libCL_clGetDeviceIDs(platform, device_type, num_entries, devices, num_devices);
}
CL_API_ENTRY cl_int CL_API_CALL clGetDeviceInfo(cl_device_id device, cl_device_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret ) CL_API_SUFFIX__VERSION_1_0 {
#ifdef DEBUG
	fprintf(stdout, "%s: %s\n", LIB_NAME, LIBCL_GET_DEVICE_INFO_STR);
	fflush(stdout);
#endif
	return libCL_clGetDeviceInfo(device, param_name, param_value_size, param_value, param_value_size_ret);
}
CL_API_ENTRY cl_context CL_API_CALL clCreateContext(const cl_context_properties * properties, cl_uint num_devices, const cl_device_id * devices, void (CL_CALLBACK * pfn_notify )(const char *, const void *, size_t, void *), void * user_data, cl_int * errcode_ret ) CL_API_SUFFIX__VERSION_1_0 {
#ifdef DEBUG
	fprintf(stdout, "%s: %s\n", LIB_NAME, LIBCL_CREATE_CONTEXT_STR);
	fflush(stdout);
#endif
	return libCL_clCreateContext(properties, num_devices, devices, pfn_notify, user_data, errcode_ret);
}
CL_API_ENTRY cl_context CL_API_CALL clCreateContextFromType(const cl_context_properties * properties, cl_device_type device_type, void (CL_CALLBACK * pfn_notify )(const char *, const void *, size_t, void *), void * user_data, cl_int * errcode_ret ) CL_API_SUFFIX__VERSION_1_0 {
#ifdef DEBUG
	fprintf(stdout, "%s: %s\n", LIB_NAME, LIBCL_CREATE_CONTEXT_FROM_TYPE_STR);
	fflush(stdout);
#endif
	return libCL_clCreateContextFromType(properties, device_type, pfn_notify, user_data, errcode_ret);
}
CL_API_ENTRY cl_int CL_API_CALL clRetainContext(cl_context context ) CL_API_SUFFIX__VERSION_1_0 {
#ifdef DEBUG
	fprintf(stdout, "%s: %s\n", LIB_NAME, LIBCL_RETAIN_CONTEXT_STR);
	fflush(stdout);
#endif
	return libCL_clRetainContext(context);
}
CL_API_ENTRY cl_int CL_API_CALL clReleaseContext(cl_context context ) CL_API_SUFFIX__VERSION_1_0 {
#ifdef DEBUG
	fprintf(stdout, "%s: %s\n", LIB_NAME, LIBCL_RELEASE_CONTEXT_STR);
	fflush(stdout);
#endif
	return libCL_clReleaseContext(context);
}
CL_API_ENTRY cl_int CL_API_CALL clGetContextInfo(cl_context context, cl_context_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret ) CL_API_SUFFIX__VERSION_1_0 {
#ifdef DEBUG
	fprintf(stdout, "%s: %s\n", LIB_NAME, LIBCL_GET_CONTEXT_INFO_STR);
	fflush(stdout);
#endif
	return libCL_clGetContextInfo(context, param_name, param_value_size, param_value, param_value_size_ret);
}
CL_API_ENTRY cl_command_queue CL_API_CALL clCreateCommandQueue(cl_context context, cl_device_id device, cl_command_queue_properties properties, cl_int * errcode_ret ) CL_API_SUFFIX__VERSION_1_0 {
#ifdef DEBUG
	fprintf(stdout, "%s: %s\n", LIB_NAME, LIBCL_CREATE_COMMAND_QUEUE_STR);
	fflush(stdout);
#endif
	return libCL_clCreateCommandQueue(context, device, properties, errcode_ret);
}
CL_API_ENTRY cl_int CL_API_CALL clRetainCommandQueue(cl_command_queue command_queue ) CL_API_SUFFIX__VERSION_1_0 {
#ifdef DEBUG
	fprintf(stdout, "%s: %s\n", LIB_NAME, LIBCL_RETAIN_COMMAND_QUEUE_STR);
	fflush(stdout);
#endif
	return libCL_clRetainCommandQueue(command_queue);
}
CL_API_ENTRY cl_int CL_API_CALL clReleaseCommandQueue(cl_command_queue command_queue ) CL_API_SUFFIX__VERSION_1_0 {
#ifdef DEBUG
	fprintf(stdout, "%s: %s\n", LIB_NAME, LIBCL_RELEASE_COMMAND_QUEUE_STR);
	fflush(stdout);
#endif
	return libCL_clReleaseCommandQueue(command_queue);
}
CL_API_ENTRY cl_int CL_API_CALL clGetCommandQueueInfo(cl_command_queue command_queue, cl_command_queue_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret ) CL_API_SUFFIX__VERSION_1_0 {
#ifdef DEBUG
	fprintf(stdout, "%s: %s\n", LIB_NAME, LIBCL_GET_COMMAND_QUEUE_STR);
	fflush(stdout);
#endif
	return libCL_clGetCommandQueueInfo(command_queue, param_name, param_value_size, param_value, param_value_size_ret);
}


void doStuff() {
	printf("doing stuff!\n");
}
