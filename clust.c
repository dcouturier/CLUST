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

#ifdef __cplusplus
"C" {
#endif

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
#ifdef CL_USE_DEPRECATED_OPENCL_1_0_APIS
cl_api_call_clSetCommandQueueProperty libCL_clSetCommandQueueProperty;
#endif /* CL_USE_DEPRECATED_OPENCL_1_0_APIS */
cl_api_call_clCreateBuffer libCL_clCreateBuffer;
cl_api_call_clCreateSubBuffer libCL_clCreateSubBuffer;
cl_api_call_clCreateImage2D libCL_clCreateImage2D;
cl_api_call_clCreateImage3D libCL_clCreateImage3D;
cl_api_call_clRetainMemObject libCL_clRetainMemObject;
cl_api_call_clReleaseMemObject libCL_clReleaseMemObject;
cl_api_call_clGetSupportedImageFormats libCL_clGetSupportedImageFormats;
cl_api_call_clGetMemObjectInfo libCL_clGetMemObjectInfo;
cl_api_call_clGetImageInfo libCL_clGetImageInfo;
cl_api_call_clSetMemObjectDestructorCallback libCL_clSetMemObjectDestructorCallback;
cl_api_call_clCreateSampler libCL_clCreateSampler;
cl_api_call_clRetainSampler libCL_clRetainSampler;
cl_api_call_clReleaseSampler libCL_clReleaseSampler;
cl_api_call_clGetSamplerInfo libCL_clGetSamplerInfo;
cl_api_call_clCreateProgramWithSource libCL_clCreateProgramWithSource;
cl_api_call_clCreateProgramWithBinary libCL_clCreateProgramWithBinary;
cl_api_call_clRetainProgram libCL_clRetainProgram;
cl_api_call_clReleaseProgram libCL_clReleaseProgram;
cl_api_call_clBuildProgram libCL_clBuildProgram;
cl_api_call_clUnloadCompiler libCL_clUnloadCompiler;
cl_api_call_clGetProgramInfo libCL_clGetProgramInfo;
cl_api_call_clGetProgramBuildInfo libCL_clGetProgramBuildInfo;

__attribute__((constructor)) void libCLUST() {
#ifdef DEBUG
	fprintf(stdout, "%s: OpenCL Symbols being replaced...\n", LIB_NAME);
#endif
	init_libcl_symbols();
}

void functionBegin(const char* functionName) {
	fprintf(stdout, "%s: Calling %s\n", LIB_NAME, functionName);
}

void functionEnd(const char* functionName) {
	fprintf(stdout, "%s: %s returned.\n", LIB_NAME, functionName);
}

void* dlSymFunction(void* libPtr, const char* functionName) {
	//fprintf(stdout, "%s: Loading %s\n", LIB_NAME, functionName);
	//fprintf(stdout, "%s: libcl_ptr = %p\n", LIB_NAME, libPtr);
	void* ptr;
	*(void**)(&ptr) = dlsym(libPtr, functionName);
	if(!ptr) {
		fprintf(stderr, "%s: Unable to load %s\n", LIB_NAME, functionName);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%s: dlSymPtr = %p\n", LIB_NAME, ptr);
	return ptr;
}

void init_libcl_symbols() {
	void* libcl_ptr;

	dlerror();
	libcl_ptr = dlopen(LIBCL_NAME, RTLD_LAZY);

	if(!libcl_ptr) {
		fprintf(stderr, "%s: Unable to load %s\n", LIB_NAME, LIBCL_NAME);
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
#ifdef CL_USE_DEPRECATED_OPENCL_1_0_APIS
	libCL_clSetCommandQueueProperty = (cl_api_call_clSetCommandQueueProperty) dlSymFunction(libcl_ptr, LIBCL_SET_COMMAND_QUEUE_PROPERTY_STR);
#endif /* CL_USE_DEPRECATED_OPENCL_1_0_APIS */
	libCL_clCreateBuffer = (cl_api_call_clCreateBuffer) dlSymFunction(libcl_ptr, LIBCL_CREATE_BUFFER_STR);
	libCL_clCreateSubBuffer = (cl_api_call_clCreateSubBuffer) dlSymFunction(libcl_ptr, LIBCL_CREATE_SUB_BUFFER_STR);
	libCL_clCreateImage2D = (cl_api_call_clCreateImage2D) dlSymFunction(libcl_ptr, LIBCL_CREATE_IMAGE_2D_STR);
	libCL_clCreateImage3D = (cl_api_call_clCreateImage3D) dlSymFunction(libcl_ptr, LIBCL_CREATE_IMAGE_3D_STR);
	libCL_clRetainMemObject = (cl_api_call_clRetainMemObject) dlSymFunction(libcl_ptr, LIBCL_RETAIN_MEM_OBJECT_STR);
	libCL_clReleaseMemObject = (cl_api_call_clReleaseMemObject) dlSymFunction(libcl_ptr, LIBCL_RELEASE_MEM_OBJECT_STR);
	libCL_clGetSupportedImageFormats = (cl_api_call_clGetSupportedImageFormats) dlSymFunction(libcl_ptr, LIBCL_GET_SUPPORTED_IMAGE_FORMATS_STR);
	libCL_clGetMemObjectInfo = (cl_api_call_clGetMemObjectInfo) dlSymFunction(libcl_ptr, LIBCL_GET_MEM_OBJECT_INFO_STR);
	libCL_clGetImageInfo = (cl_api_call_clGetImageInfo) dlSymFunction(libcl_ptr, LIBCL_GET_IMAGE_INFO_STR);
	libCL_clSetMemObjectDestructorCallback = (cl_api_call_clSetMemObjectDestructorCallback) dlSymFunction(libcl_ptr, LIBCL_SET_MEM_OBJECT_DESTRUCTOR_CALLBACK_STR);
	libCL_clCreateSampler = (cl_api_call_clCreateSampler) dlSymFunction(libcl_ptr, LIBCL_CREATE_SAMPLER_STR);
	libCL_clRetainSampler = (cl_api_call_clRetainSampler) dlSymFunction(libcl_ptr, LIBCL_RETAIN_SAMPLER_STR);
	libCL_clReleaseSampler = (cl_api_call_clReleaseSampler) dlSymFunction(libcl_ptr, LIBCL_RELEASE_SAMPLER_STR);
	libCL_clGetSamplerInfo = (cl_api_call_clGetSamplerInfo) dlSymFunction(libcl_ptr, LIBCL_GET_SAMPLER_INFO_STR);
	libCL_clCreateProgramWithSource = (cl_api_call_clCreateProgramWithSource) dlSymFunction(libcl_ptr, LIBCL_CREATE_PROGRAM_WITH_SOURCE_STR);
	libCL_clCreateProgramWithBinary = (cl_api_call_clCreateProgramWithBinary) dlSymFunction(libcl_ptr, LIBCL_CREATE_PROGRAM_WITH_BINARY_STR);
	libCL_clRetainProgram = (cl_api_call_clRetainProgram) dlSymFunction(libcl_ptr, LIBCL_RETAIN_PROGRAM_STR);
	libCL_clReleaseProgram = (cl_api_call_clReleaseProgram) dlSymFunction(libcl_ptr, LIBCL_RELEASE_PROGRAM_STR);
	libCL_clBuildProgram = (cl_api_call_clBuildProgram) dlSymFunction(libcl_ptr, LIBCL_BUILD_PROGRAM_STR);
	libCL_clUnloadCompiler = (cl_api_call_clUnloadCompiler) dlSymFunction(libcl_ptr, LIBCL_UNLOAD_COMPILER_STR);
	libCL_clGetProgramInfo = (cl_api_call_clGetProgramInfo) dlSymFunction(libcl_ptr, LIBCL_GET_PROGRAM_INFO_STR);
	libCL_clGetProgramBuildInfo = (cl_api_call_clGetProgramBuildInfo) dlSymFunction(libcl_ptr, LIBCL_GET_PROGRAM_BUILD_INFO_STR);

//	libCL_cl = (cl_api_call_cl) dlsymFunction(libcl_ptr, LIBCL_);

#ifdef DEBUG
	fprintf(stdout, "%s: Symbols initialized!\n", LIB_NAME);
#endif
}

CL_API_ENTRY cl_int CL_API_CALL clGetPlatformIDs(cl_uint num_entries, cl_platform_id * platforms, cl_uint * num_platforms) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_GET_PLATFORM_IDS_STR);
#endif
	cl_int ret = libCL_clGetPlatformIDs(num_entries,platforms,num_platforms);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_GET_PLATFORM_IDS_STR);
#endif
	return ret;
}
CL_API_ENTRY cl_int CL_API_CALL clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_GET_PLATFORM_INFO_STR);
#endif
	cl_int ret = libCL_clGetPlatformInfo(platform, param_name, param_value_size, param_value, param_value_size_ret);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_GET_PLATFORM_INFO_STR);
#endif
	return ret;
}
CL_API_ENTRY cl_int CL_API_CALL clGetDeviceIDs(cl_platform_id platform, cl_device_type device_type, cl_uint num_entries, cl_device_id * devices, cl_uint * num_devices) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_GET_DEVICE_IDS_STR);
#endif
	cl_int ret = libCL_clGetDeviceIDs(platform, device_type, num_entries, devices, num_devices);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_GET_DEVICE_IDS_STR);
#endif
	return ret;
}
CL_API_ENTRY cl_int CL_API_CALL clGetDeviceInfo(cl_device_id device, cl_device_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret ) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_GET_DEVICE_INFO_STR);
#endif
	cl_int ret = libCL_clGetDeviceInfo(device, param_name, param_value_size, param_value, param_value_size_ret);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_GET_DEVICE_INFO_STR);
#endif
	return ret;
}
CL_API_ENTRY cl_context CL_API_CALL clCreateContext(const cl_context_properties * properties, cl_uint num_devices, const cl_device_id * devices, void (CL_CALLBACK * pfn_notify )(const char *, const void *, size_t, void *), void * user_data, cl_int * errcode_ret ) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_CREATE_CONTEXT_STR);
#endif
	cl_context ret = libCL_clCreateContext(properties, num_devices, devices, pfn_notify, user_data, errcode_ret);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_CREATE_CONTEXT_STR);
#endif
	return ret;
}
CL_API_ENTRY cl_context CL_API_CALL clCreateContextFromType(const cl_context_properties * properties, cl_device_type device_type, void (CL_CALLBACK * pfn_notify )(const char *, const void *, size_t, void *), void * user_data, cl_int * errcode_ret ) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_CREATE_CONTEXT_FROM_TYPE_STR);
#endif
	cl_context ret = libCL_clCreateContextFromType(properties, device_type, pfn_notify, user_data, errcode_ret);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_CREATE_CONTEXT_FROM_TYPE_STR);
#endif
	return ret;
}
CL_API_ENTRY cl_int CL_API_CALL clRetainContext(cl_context context ) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_RETAIN_CONTEXT_STR);
#endif
	cl_int ret = libCL_clRetainContext(context);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_RETAIN_CONTEXT_STR);
#endif
	return ret;
}
CL_API_ENTRY cl_int CL_API_CALL clReleaseContext(cl_context context ) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_RELEASE_CONTEXT_STR);
#endif
	cl_int ret = libCL_clReleaseContext(context);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_RELEASE_CONTEXT_STR);
#endif
	return ret;
}
CL_API_ENTRY cl_int CL_API_CALL clGetContextInfo(cl_context context, cl_context_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret ) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_GET_CONTEXT_INFO_STR);
#endif
	cl_int ret = libCL_clGetContextInfo(context, param_name, param_value_size, param_value, param_value_size_ret);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_GET_CONTEXT_INFO_STR);
#endif
	return ret;
}
CL_API_ENTRY cl_command_queue CL_API_CALL clCreateCommandQueue(cl_context context, cl_device_id device, cl_command_queue_properties properties, cl_int * errcode_ret ) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_CREATE_COMMAND_QUEUE_STR);
#endif
	cl_command_queue ret = libCL_clCreateCommandQueue(context, device, properties, errcode_ret);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_CREATE_COMMAND_QUEUE_STR);
#endif
	return ret;
}
CL_API_ENTRY cl_int CL_API_CALL clRetainCommandQueue(cl_command_queue command_queue ) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_RETAIN_COMMAND_QUEUE_STR);
#endif
	cl_int ret = libCL_clRetainCommandQueue(command_queue);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_RETAIN_COMMAND_QUEUE_STR);
#endif
	return ret;
}
CL_API_ENTRY cl_int CL_API_CALL clReleaseCommandQueue(cl_command_queue command_queue ) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_RELEASE_COMMAND_QUEUE_STR);
#endif
	cl_int ret = libCL_clReleaseCommandQueue(command_queue);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_RELEASE_COMMAND_QUEUE_STR);
#endif
	return ret;
}
CL_API_ENTRY cl_int CL_API_CALL clGetCommandQueueInfo(cl_command_queue command_queue, cl_command_queue_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret ) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_GET_COMMAND_QUEUE_STR);
#endif
	cl_int ret = libCL_clGetCommandQueueInfo(command_queue, param_name, param_value_size, param_value, param_value_size_ret);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_GET_COMMAND_QUEUE_STR);
#endif
	return ret;
}


#ifdef CL_USE_DEPRECATED_OPENCL_1_0_APIS
/*
 *  WARNING:
 *     This API introduces mutable state into the OpenCL implementation. It has been REMOVED
 *  to better facilitate thread safety.  The 1.0 API is not thread safe. It is not tested by the
 *  OpenCL 1.1 conformance test, and consequently may not work or may not work dependably.
 *  It is likely to be non-performant. Use of this API is not advised. Use at your own risk.
 *
 *  Software developers previously relying on this API are instructed to set the command queue
 *  properties when creating the queue, instead.
 */
CL_API_ENTRY cl_int CL_API_CALL
clSetCommandQueueProperty(cl_command_queue command_queue,
		cl_command_queue_properties properties,
		cl_bool enable,
		cl_command_queue_properties * old_properties) CL_EXT_SUFFIX__VERSION_1_0_DEPRECATED {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_GET_COMMAND_QUEUE_STR);
#endif
	cl_int ret = libCL_clSetCommandQueueProperty(command_queue, properties, enable, old_properties);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_GET_COMMAND_QUEUE_STR);
#endif
	return ret;
}
#endif /* CL_USE_DEPRECATED_OPENCL_1_0_APIS */


/* Memory Object APIs */
CL_API_ENTRY cl_mem CL_API_CALL clCreateBuffer(cl_context context, cl_mem_flags flags, size_t size, void * host_ptr, cl_int * errcode_ret) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_CREATE_BUFFER_STR);
#endif
	cl_mem ret = libCL_clCreateBuffer(context, flags, size, host_ptr, errcode_ret);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_CREATE_BUFFER_STR);
#endif
	return ret;
}

CL_API_ENTRY cl_mem CL_API_CALL clCreateSubBuffer(cl_mem buffer, cl_mem_flags flags, cl_buffer_create_type buffer_create_type, const void * buffer_create_info, cl_int * errcode_ret) CL_API_SUFFIX__VERSION_1_1 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_CREATE_SUB_BUFFER_STR);
#endif
	cl_mem ret = libCL_clCreateSubBuffer(buffer, flags, buffer_create_type, buffer_create_info, errcode_ret);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_CREATE_SUB_BUFFER_STR);
#endif
	return ret;
}

CL_API_ENTRY cl_mem CL_API_CALL clCreateImage2D(cl_context context, cl_mem_flags flags, const cl_image_format * image_format, size_t image_width, size_t image_height, size_t image_row_pitch, void * host_ptr, cl_int * errcode_ret) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_CREATE_IMAGE_2D_STR);
#endif
	cl_mem ret = libCL_clCreateImage2D(context, flags, image_format, image_width, image_height, image_row_pitch, host_ptr, errcode_ret) ;
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_CREATE_IMAGE_2D_STR);
#endif
	return ret;
}

CL_API_ENTRY cl_mem CL_API_CALL clCreateImage3D(cl_context context, cl_mem_flags flags, const cl_image_format * image_format, size_t image_width, size_t image_height, size_t image_depth, size_t image_row_pitch, size_t image_slice_pitch, void * host_ptr, cl_int * errcode_ret) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_CREATE_IMAGE_3D_STR);
#endif
	cl_mem ret = libCL_clCreateImage3D(context, flags, image_format, image_width, image_height, image_depth, image_row_pitch, image_slice_pitch, host_ptr, errcode_ret);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_CREATE_IMAGE_3D_STR);
#endif
	return ret;
}

CL_API_ENTRY cl_int CL_API_CALL clRetainMemObject(cl_mem memobj) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_RETAIN_MEM_OBJECT_STR);
#endif
	cl_int ret = libCL_clRetainMemObject(memobj);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_RETAIN_MEM_OBJECT_STR);
#endif
	return ret;
}

CL_API_ENTRY cl_int CL_API_CALL clReleaseMemObject(cl_mem memobj) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_RELEASE_MEM_OBJECT_STR);
#endif
	cl_int ret = libCL_clReleaseMemObject(memobj);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_RELEASE_MEM_OBJECT_STR);
#endif
	return ret;
}

CL_API_ENTRY cl_int CL_API_CALL clGetSupportedImageFormats(cl_context context, cl_mem_flags flags, cl_mem_object_type image_type, cl_uint num_entries, cl_image_format * image_formats, cl_uint * num_image_formats) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_GET_SUPPORTED_IMAGE_FORMATS_STR);
#endif
	cl_int ret = libCL_clGetSupportedImageFormats(context, flags, image_type, num_entries, image_formats, num_image_formats);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_GET_SUPPORTED_IMAGE_FORMATS_STR);
#endif
	return ret;
}

CL_API_ENTRY cl_int CL_API_CALL clGetMemObjectInfo(cl_mem memobj, cl_mem_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_GET_MEM_OBJECT_INFO_STR);
#endif
	cl_int ret = libCL_clGetMemObjectInfo(memobj, param_name, param_value_size, param_value, param_value_size_ret);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_GET_MEM_OBJECT_INFO_STR);
#endif
	return ret;
}

CL_API_ENTRY cl_int CL_API_CALL clGetImageInfo(cl_mem image, cl_image_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_GET_IMAGE_INFO_STR);
#endif
	cl_int ret = libCL_clGetImageInfo(image, param_name, param_value_size, param_value, param_value_size_ret);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_GET_IMAGE_INFO_STR);
#endif
	return ret;
}

CL_API_ENTRY cl_int CL_API_CALL clSetMemObjectDestructorCallback( cl_mem memobj, void (CL_CALLBACK * pfn_notify)( cl_mem memobj, void* user_data), void * user_data ) CL_API_SUFFIX__VERSION_1_1 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_SET_MEM_OBJECT_DESTRUCTOR_CALLBACK_STR);
#endif
	cl_int ret = libCL_clSetMemObjectDestructorCallback(memobj, pfn_notify, user_data);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_SET_MEM_OBJECT_DESTRUCTOR_CALLBACK_STR);
#endif
	return ret;
}

/* Sampler APIs */
CL_API_ENTRY cl_sampler CL_API_CALL clCreateSampler(cl_context context, cl_bool normalized_coords, cl_addressing_mode addressing_mode, cl_filter_mode filter_mode, cl_int * errcode_ret) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_CREATE_SAMPLER_STR);
#endif
	cl_sampler ret = libCL_clCreateSampler(context, normalized_coords, addressing_mode, filter_mode, errcode_ret);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_CREATE_SAMPLER_STR);
#endif
	return ret;
}

CL_API_ENTRY cl_int CL_API_CALL clRetainSampler(cl_sampler sampler) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_RETAIN_SAMPLER_STR);
#endif
	cl_int ret = libCL_clRetainSampler(sampler);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_RETAIN_SAMPLER_STR);
#endif
	return ret;
}

CL_API_ENTRY cl_int CL_API_CALL clReleaseSampler(cl_sampler sampler) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_RELEASE_SAMPLER_STR);
#endif
	cl_int ret = libCL_clReleaseSampler(sampler);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_RELEASE_SAMPLER_STR);
#endif
	return ret;
}

CL_API_ENTRY cl_int CL_API_CALL clGetSamplerInfo(cl_sampler sampler, cl_sampler_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_GET_SAMPLER_INFO_STR);
#endif
	cl_int ret = libCL_clGetSamplerInfo(sampler, param_name, param_value_size, param_value, param_value_size_ret);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_GET_SAMPLER_INFO_STR);
#endif
	return ret;
}

/* Program Object APIs */
CL_API_ENTRY cl_program CL_API_CALL clCreateProgramWithSource(cl_context context, cl_uint count, const char ** strings, const size_t * lengths, cl_int * errcode_ret) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_CREATE_PROGRAM_WITH_SOURCE_STR);
#endif
	cl_program ret = libCL_clCreateProgramWithSource(context, count, strings, lengths, errcode_ret);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_CREATE_PROGRAM_WITH_SOURCE_STR);
#endif
	return ret;
}

CL_API_ENTRY cl_program CL_API_CALL clCreateProgramWithBinary(cl_context context, cl_uint num_devices, const cl_device_id * device_list, const size_t * lengths, const unsigned char ** binaries, cl_int * binary_status, cl_int * errcode_ret) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_CREATE_PROGRAM_WITH_BINARY_STR);
#endif
	cl_program ret = libCL_clCreateProgramWithBinary(context, num_devices, device_list, lengths, binaries, binary_status, errcode_ret);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_CREATE_PROGRAM_WITH_BINARY_STR);
#endif
	return ret;
}

CL_API_ENTRY cl_int CL_API_CALL clRetainProgram(cl_program program) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_RETAIN_PROGRAM_STR);
#endif
	cl_int ret = libCL_clRetainProgram(program);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_RETAIN_PROGRAM_STR);
#endif
	return ret;
}

CL_API_ENTRY cl_int CL_API_CALL clReleaseProgram(cl_program program) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_RELEASE_PROGRAM_STR);
#endif
	cl_int ret = libCL_clReleaseProgram(program);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_RELEASE_PROGRAM_STR);
#endif
	return ret;
}

CL_API_ENTRY cl_int CL_API_CALL clBuildProgram(cl_program program, cl_uint num_devices, const cl_device_id * device_list, const char * options, void (CL_CALLBACK * pfn_notify)(cl_program program, void * user_data), void * user_data) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_BUILD_PROGRAM_STR);
#endif
	cl_int ret = libCL_clBuildProgram(program, num_devices, device_list, options, pfn_notify, user_data);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_BUILD_PROGRAM_STR);
#endif
	return ret;
}

CL_API_ENTRY cl_int CL_API_CALL clUnloadCompiler(void) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_UNLOAD_COMPILER_STR);
#endif
	cl_int ret = libCL_clUnloadCompiler();
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_UNLOAD_COMPILER_STR);
#endif
	return ret;
}

CL_API_ENTRY cl_int CL_API_CALL clGetProgramInfo(cl_program program, cl_program_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_GET_PROGRAM_INFO_STR);
#endif
	cl_int ret = libCL_clGetProgramInfo(program, param_name, param_value_size, param_value, param_value_size_ret);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_GET_PROGRAM_INFO_STR);
#endif
	return ret;
}

CL_API_ENTRY cl_int CL_API_CALL clGetProgramBuildInfo(cl_program program, cl_device_id device, cl_program_build_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) CL_API_SUFFIX__VERSION_1_0 {
#if ENABLE_FUNCTION_BEGIN != 0
	functionBegin(LIBCL_GET_PROGRAM_BUILD_INFO_STR);
#endif
	cl_int ret = libCL_clGetProgramBuildInfo(program, device, param_name, param_value_size, param_value, param_value_size_ret);
#if ENABLE_FUNCTION_END != 0
	functionEnd(LIBCL_GET_PROGRAM_BUILD_INFO_STR);
#endif
	return ret;
}
//
///* Kernel Object APIs */
//CL_API_ENTRY cl_kernel CL_API_CALL
//clCreateKernel(cl_program program,
// const char * kernel_name,
// cl_int * errcode_ret) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clCreateKernelsInProgram(cl_program program,
// cl_uint num_kernels,
// cl_kernel * kernels,
// cl_uint * num_kernels_ret) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clRetainKernel(cl_kernel kernel) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clReleaseKernel(cl_kernel kernel) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clSetKernelArg(cl_kernel kernel,
// cl_uint arg_index,
// size_t arg_size,
// const void * arg_value) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clGetKernelInfo(cl_kernel kernel,
// cl_kernel_info param_name,
// size_t param_value_size,
// void * param_value,
// size_t * param_value_size_ret) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clGetKernelWorkGroupInfo(cl_kernel kernel,
// cl_device_id device,
// cl_kernel_work_group_info param_name,
// size_t param_value_size,
// void * param_value,
// size_t * param_value_size_ret) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
///* Event Object APIs */
//CL_API_ENTRY cl_int CL_API_CALL
//clWaitForEvents(cl_uint num_events,
// const cl_event * event_list) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clGetEventInfo(cl_event event,
// cl_event_info param_name,
// size_t param_value_size,
// void * param_value,
// size_t * param_value_size_ret) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
//CL_API_ENTRY cl_event CL_API_CALL
//clCreateUserEvent(cl_context context,
// cl_int * errcode_ret) CL_API_SUFFIX__VERSION_1_1{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clRetainEvent(cl_event event) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clReleaseEvent(cl_event event) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clSetUserEventStatus(cl_event event,
// cl_int execution_status) CL_API_SUFFIX__VERSION_1_1{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clSetEventCallback( cl_event event,
// cl_int command_exec_callback_type,
// void (CL_CALLBACK * pfn_notify)(cl_event, cl_int, void *),
// void * user_data) CL_API_SUFFIX__VERSION_1_1{ return libCL_ ; }
//
///* Profiling APIs */
//CL_API_ENTRY cl_int CL_API_CALL
//clGetEventProfilingInfo(cl_event event,
// cl_profiling_info param_name,
// size_t param_value_size,
// void * param_value,
// size_t * param_value_size_ret) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
///* Flush and Finish APIs */
//CL_API_ENTRY cl_int CL_API_CALL
//clFlush(cl_command_queue command_queue) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clFinish(cl_command_queue command_queue) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
///* Enqueued Commands APIs */
//CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueReadBuffer(cl_command_queue command_queue,
// cl_mem buffer,
// cl_bool blocking_read,
// size_t offset,
// size_t cb,
// void * ptr,
// cl_uint num_events_in_wait_list,
// const cl_event * event_wait_list,
// cl_event * event) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueReadBufferRect(cl_command_queue command_queue,
// cl_mem buffer,
// cl_bool blocking_read,
// const size_t * buffer_origin,
// const size_t * host_origin,
// const size_t * region,
// size_t buffer_row_pitch,
// size_t buffer_slice_pitch,
// size_t host_row_pitch,
// size_t host_slice_pitch,
// void * ptr,
// cl_uint num_events_in_wait_list,
// const cl_event * event_wait_list,
// cl_event * event) CL_API_SUFFIX__VERSION_1_1{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueWriteBuffer(cl_command_queue command_queue,
// cl_mem buffer,
// cl_bool blocking_write,
// size_t offset,
// size_t cb,
// const void * ptr,
// cl_uint num_events_in_wait_list,
// const cl_event * event_wait_list,
// cl_event * event) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueWriteBufferRect(cl_command_queue command_queue,
// cl_mem buffer,
// cl_bool blocking_write,
// const size_t * buffer_origin,
// const size_t * host_origin,
// const size_t * region,
// size_t buffer_row_pitch,
// size_t buffer_slice_pitch,
// size_t host_row_pitch,
// size_t host_slice_pitch,
// const void * ptr,
// cl_uint num_events_in_wait_list,
// const cl_event * event_wait_list,
// cl_event * event) CL_API_SUFFIX__VERSION_1_1{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueCopyBuffer(cl_command_queue command_queue,
// cl_mem src_buffer,
// cl_mem dst_buffer,
// size_t src_offset,
// size_t dst_offset,
// size_t cb,
// cl_uint num_events_in_wait_list,
// const cl_event * event_wait_list,
// cl_event * event) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueCopyBufferRect(cl_command_queue command_queue,
// cl_mem src_buffer,
// cl_mem dst_buffer,
// const size_t * src_origin,
// const size_t * dst_origin,
// const size_t * region,
// size_t src_row_pitch,
// size_t src_slice_pitch,
// size_t dst_row_pitch,
// size_t dst_slice_pitch,
// cl_uint num_events_in_wait_list,
// const cl_event * event_wait_list,
// cl_event * event) CL_API_SUFFIX__VERSION_1_1{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueReadImage(cl_command_queue command_queue,
// cl_mem image,
// cl_bool blocking_read,
// const size_t * origin[3],
// const size_t * region[3],
// size_t row_pitch,
// size_t slice_pitch,
// void * ptr,
// cl_uint num_events_in_wait_list,
// const cl_event * event_wait_list,
// cl_event * event) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueWriteImage(cl_command_queue command_queue,
// cl_mem image,
// cl_bool blocking_write,
// const size_t * origin[3],
// const size_t * region[3],
// size_t input_row_pitch,
// size_t input_slice_pitch,
// const void * ptr,
// cl_uint num_events_in_wait_list,
// const cl_event * event_wait_list,
// cl_event * event) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueCopyImage(cl_command_queue command_queue,
// cl_mem src_image,
// cl_mem dst_image,
// const size_t * src_origin[3],
// const size_t * dst_origin[3],
// const size_t * region[3],
// cl_uint num_events_in_wait_list,
// const cl_event * event_wait_list,
// cl_event * event) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueCopyImageToBuffer(cl_command_queue command_queue,
// cl_mem src_image,
// cl_mem dst_buffer,
// const size_t * src_origin[3],
// const size_t * region[3],
// size_t dst_offset,
// cl_uint num_events_in_wait_list,
// const cl_event * event_wait_list,
// cl_event * event) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueCopyBufferToImage(cl_command_queue command_queue,
// cl_mem src_buffer,
// cl_mem dst_image,
// size_t src_offset,
// const size_t * dst_origin[3],
// const size_t * region[3],
// cl_uint num_events_in_wait_list,
// const cl_event * event_wait_list,
// cl_event * event) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
//CL_API_ENTRY void * CL_API_CALL
//clEnqueueMapBuffer(cl_command_queue command_queue,
// cl_mem buffer,
// cl_bool blocking_map,
// cl_map_flags map_flags,
// size_t offset,
// size_t cb,
// cl_uint num_events_in_wait_list,
// const cl_event * event_wait_list,
// cl_event * event,
// cl_int * errcode_ret) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
//CL_API_ENTRY void * CL_API_CALL
//clEnqueueMapImage(cl_command_queue command_queue,
// cl_mem image,
// cl_bool blocking_map,
// cl_map_flags map_flags,
// const size_t * origin[3],
// const size_t * region[3],
// size_t * image_row_pitch,
// size_t * image_slice_pitch,
// cl_uint num_events_in_wait_list,
// const cl_event * event_wait_list,
// cl_event * event,
// cl_int * errcode_ret) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueUnmapMemObject(cl_command_queue command_queue,
// cl_mem memobj,
// void * mapped_ptr,
// cl_uint num_events_in_wait_list,
// const cl_event * event_wait_list,
// cl_event * event) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueNDRangeKernel(cl_command_queue command_queue,
// cl_kernel kernel,
// cl_uint work_dim,
// const size_t * global_work_offset,
// const size_t * global_work_size,
// const size_t * local_work_size,
// cl_uint num_events_in_wait_list,
// const cl_event * event_wait_list,
// cl_event * event) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueTask(cl_command_queue command_queue,
// cl_kernel kernel,
// cl_uint num_events_in_wait_list,
// const cl_event * event_wait_list,
// cl_event * event) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueNativeKernel(cl_command_queue command_queue,
//					 void (*user_func)(void *),
// void * args,
// size_t cb_args,
// cl_uint num_mem_objects,
// const cl_mem * mem_list,
// const void ** args_mem_loc,
// cl_uint num_events_in_wait_list,
// const cl_event * event_wait_list,
// cl_event * event) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueMarker(cl_command_queue command_queue,
// cl_event * event) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueWaitForEvents(cl_command_queue command_queue,
// cl_uint num_events,
// const cl_event * event_list) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
//CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueBarrier(cl_command_queue command_queue) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//
///* Extension function access */
///*
// * Returns the extension function address for the given function name,
// * or NULL if a valid function can not be found. The client must
// * check to make sure the address is not NULL, before using or
// * calling the returned function address.
// */
//
//CL_API_ENTRY void * CL_API_CALL clGetExtensionFunctionAddress(const char * func_name) CL_API_SUFFIX__VERSION_1_0{ return libCL_ ; }
//


void doStuff() {
	printf("doing stuff!\n");
}

#ifdef __cplusplus
}
#endif
