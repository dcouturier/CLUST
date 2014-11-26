#define _GNU_SOURCE

#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>
#include "clust.h"

#define TRACEPOINT_DEFINE
#define TRACEPOINT_CREATE_PROBES
#include "clust_tp.h"

#ifdef __cplusplus
"C" {
#endif

cl_api_call_clGetPlatformIDs reallib_clGetPlatformIDs;
cl_api_call_clGetPlatformInfo reallib_clGetPlatformInfo;
cl_api_call_clGetDeviceIDs reallib_clGetDeviceIDs;
cl_api_call_clGetDeviceInfo reallib_clGetDeviceInfo;
cl_api_call_clCreateContext reallib_clCreateContext;
cl_api_call_clCreateContextFromType reallib_clCreateContextFromType;
cl_api_call_clRetainContext reallib_clRetainContext;
cl_api_call_clReleaseContext reallib_clReleaseContext;
cl_api_call_clGetContextInfo reallib_clGetContextInfo;
cl_api_call_clCreateCommandQueue reallib_clCreateCommandQueue;
cl_api_call_clRetainCommandQueue reallib_clRetainCommandQueue;
cl_api_call_clReleaseCommandQueue reallib_clReleaseCommandQueue;
cl_api_call_clGetCommandQueueInfo reallib_clGetCommandQueueInfo;
cl_api_call_clCreateBuffer reallib_clCreateBuffer;
cl_api_call_clCreateSubBuffer reallib_clCreateSubBuffer;
cl_api_call_clCreateImage2D reallib_clCreateImage2D;
cl_api_call_clCreateImage3D reallib_clCreateImage3D;
cl_api_call_clRetainMemObject reallib_clRetainMemObject;
cl_api_call_clReleaseMemObject reallib_clReleaseMemObject;
cl_api_call_clGetSupportedImageFormats reallib_clGetSupportedImageFormats;
cl_api_call_clGetMemObjectInfo reallib_clGetMemObjectInfo;
cl_api_call_clGetImageInfo reallib_clGetImageInfo;
cl_api_call_clSetMemObjectDestructorCallback reallib_clSetMemObjectDestructorCallback;
cl_api_call_clCreateSampler reallib_clCreateSampler;
cl_api_call_clRetainSampler reallib_clRetainSampler;
cl_api_call_clReleaseSampler reallib_clReleaseSampler;
cl_api_call_clGetSamplerInfo reallib_clGetSamplerInfo;
cl_api_call_clCreateProgramWithSource reallib_clCreateProgramWithSource;
cl_api_call_clCreateProgramWithBinary reallib_clCreateProgramWithBinary;
cl_api_call_clRetainProgram reallib_clRetainProgram;
cl_api_call_clReleaseProgram reallib_clReleaseProgram;
cl_api_call_clBuildProgram reallib_clBuildProgram;
cl_api_call_clUnloadCompiler reallib_clUnloadCompiler;
cl_api_call_clGetProgramInfo reallib_clGetProgramInfo;
cl_api_call_clGetProgramBuildInfo reallib_clGetProgramBuildInfo;
cl_api_call_clCreateKernel reallib_clCreateKernel;
cl_api_call_clCreateKernelsInProgram reallib_clCreateKernelsInProgram;
cl_api_call_clRetainKernel reallib_clRetainKernel;
cl_api_call_clReleaseKernel reallib_clReleaseKernel;
cl_api_call_clSetKernelArg reallib_clSetKernelArg;
cl_api_call_clGetKernelInfo reallib_clGetKernelInfo;
cl_api_call_clGetKernelWorkGroupInfo reallib_clGetKernelWorkGroupInfo;
cl_api_call_clWaitForEvents reallib_clWaitForEvents;
cl_api_call_clGetEventInfo reallib_clGetEventInfo;
cl_api_call_clCreateUserEvent reallib_clCreateUserEvent;
cl_api_call_clRetainEvent reallib_clRetainEvent;
cl_api_call_clReleaseEvent reallib_clReleaseEvent;
cl_api_call_clSetUserEventStatus reallib_clSetUserEventStatus;
cl_api_call_clSetEventCallback reallib_clSetEventCallback;
cl_api_call_clGetEventProfilingInfo reallib_clGetEventProfilingInfo;
cl_api_call_clFlush reallib_clFlush;
cl_api_call_clFinish reallib_clFinish;
cl_api_call_clEnqueueReadBuffer reallib_clEnqueueReadBuffer;
cl_api_call_clEnqueueReadBufferRect reallib_clEnqueueReadBufferRect;
cl_api_call_clEnqueueWriteBuffer reallib_clEnqueueWriteBuffer;
cl_api_call_clEnqueueWriteBufferRect reallib_clEnqueueWriteBufferRect;
cl_api_call_clEnqueueCopyBuffer reallib_clEnqueueCopyBuffer;
cl_api_call_clEnqueueCopyBufferRect reallib_clEnqueueCopyBufferRect;
cl_api_call_clEnqueueReadImage reallib_clEnqueueReadImage;
cl_api_call_clEnqueueWriteImage reallib_clEnqueueWriteImage;
cl_api_call_clEnqueueCopyImage reallib_clEnqueueCopyImage;
cl_api_call_clEnqueueCopyImageToBuffer reallib_clEnqueueCopyImageToBuffer;
cl_api_call_clEnqueueCopyBufferToImage reallib_clEnqueueCopyBufferToImage;
cl_api_call_clEnqueueMapBuffer reallib_clEnqueueMapBuffer;
cl_api_call_clEnqueueMapImage reallib_clEnqueueMapImage;
cl_api_call_clEnqueueUnmapMemObject reallib_clEnqueueUnmapMemObject;
cl_api_call_clEnqueueNDRangeKernel reallib_clEnqueueNDRangeKernel;
cl_api_call_clEnqueueTask reallib_clEnqueueTask;
cl_api_call_clEnqueueNativeKernel reallib_clEnqueueNativeKernel;
cl_api_call_clEnqueueMarker reallib_clEnqueueMarker;
cl_api_call_clEnqueueWaitForEvents reallib_clEnqueueWaitForEvents;
cl_api_call_clEnqueueBarrier reallib_clEnqueueBarrier;
cl_api_call_clGetExtensionFunctionAddress reallib_clGetExtensionFunctionAddress;


void* dlSymFunction(void* libPtr, const char* functionName) {
	void* ptr;
	*(void**)(&ptr) = dlsym(libPtr, functionName);
	if(!ptr) {
		fprintf(stderr, "%s: Unable to load %s\n", LIB_NAME, functionName);
		exit(EXIT_FAILURE);
	}
	return ptr;
}

__attribute__((constructor)) void libCLUST() {
	void* libcl_ptr;
	dlerror();
	libcl_ptr = dlopen(LIBCL_NAME, RTLD_LAZY);

	if(!libcl_ptr) {
		fprintf(stderr, "%s: Unable to load %s\n", LIB_NAME, LIBCL_NAME);
		exit(EXIT_FAILURE);
	}

	dlerror();
	reallib_clGetPlatformIDs = (cl_api_call_clGetPlatformIDs) dlSymFunction(libcl_ptr, "clGetPlatformIDs");
	reallib_clGetPlatformInfo = (cl_api_call_clGetPlatformInfo) dlSymFunction(libcl_ptr, "clGetPlatformInfo");
	reallib_clGetDeviceIDs = (cl_api_call_clGetDeviceIDs) dlSymFunction(libcl_ptr, "clGetDeviceIDs");
	reallib_clGetDeviceInfo = (cl_api_call_clGetDeviceInfo) dlSymFunction(libcl_ptr, "clGetDeviceInfo");
	reallib_clCreateContext = (cl_api_call_clCreateContext) dlSymFunction(libcl_ptr, "clCreateContext");
	reallib_clCreateContextFromType = (cl_api_call_clCreateContextFromType) dlSymFunction(libcl_ptr, "clCreateContextFromType");
	reallib_clRetainContext = (cl_api_call_clRetainContext) dlSymFunction(libcl_ptr, "clRetainContext");
	reallib_clReleaseContext = (cl_api_call_clReleaseContext) dlSymFunction(libcl_ptr, "clReleaseContext");
	reallib_clGetContextInfo = (cl_api_call_clGetContextInfo) dlSymFunction(libcl_ptr, "clGetContextInfo");
	reallib_clCreateCommandQueue = (cl_api_call_clCreateCommandQueue) dlSymFunction(libcl_ptr, "clCreateCommandQueue");
	reallib_clRetainCommandQueue = (cl_api_call_clRetainCommandQueue) dlSymFunction(libcl_ptr, "clRetainCommandQueue");
	reallib_clReleaseCommandQueue = (cl_api_call_clReleaseCommandQueue) dlSymFunction(libcl_ptr, "clReleaseCommandQueue");
	reallib_clGetCommandQueueInfo = (cl_api_call_clGetCommandQueueInfo) dlSymFunction(libcl_ptr, "clGetCommandQueueInfo");
	reallib_clCreateBuffer = (cl_api_call_clCreateBuffer) dlSymFunction(libcl_ptr, "clCreateBuffer");
	reallib_clCreateSubBuffer = (cl_api_call_clCreateSubBuffer) dlSymFunction(libcl_ptr, "clCreateSubBuffer");
	reallib_clCreateImage2D = (cl_api_call_clCreateImage2D) dlSymFunction(libcl_ptr, "clCreateImage2D");
	reallib_clCreateImage3D = (cl_api_call_clCreateImage3D) dlSymFunction(libcl_ptr, "clCreateImage3D");
	reallib_clRetainMemObject = (cl_api_call_clRetainMemObject) dlSymFunction(libcl_ptr, "clRetainMemObject");
	reallib_clReleaseMemObject = (cl_api_call_clReleaseMemObject) dlSymFunction(libcl_ptr, "clReleaseMemObject");
	reallib_clGetSupportedImageFormats = (cl_api_call_clGetSupportedImageFormats) dlSymFunction(libcl_ptr, "clGetSupportedImageFormats");
	reallib_clGetMemObjectInfo = (cl_api_call_clGetMemObjectInfo) dlSymFunction(libcl_ptr, "clGetMemObjectInfo");
	reallib_clGetImageInfo = (cl_api_call_clGetImageInfo) dlSymFunction(libcl_ptr, "clGetImageInfo");
	reallib_clSetMemObjectDestructorCallback = (cl_api_call_clSetMemObjectDestructorCallback) dlSymFunction(libcl_ptr, "clSetMemObjectDestructorCallback");
	reallib_clCreateSampler = (cl_api_call_clCreateSampler) dlSymFunction(libcl_ptr, "clCreateSampler");
	reallib_clRetainSampler = (cl_api_call_clRetainSampler) dlSymFunction(libcl_ptr, "clRetainSampler");
	reallib_clReleaseSampler = (cl_api_call_clReleaseSampler) dlSymFunction(libcl_ptr, "clReleaseSampler");
	reallib_clGetSamplerInfo = (cl_api_call_clGetSamplerInfo) dlSymFunction(libcl_ptr, "clGetSamplerInfo");
	reallib_clCreateProgramWithSource = (cl_api_call_clCreateProgramWithSource) dlSymFunction(libcl_ptr, "clCreateProgramWithSource");
	reallib_clCreateProgramWithBinary = (cl_api_call_clCreateProgramWithBinary) dlSymFunction(libcl_ptr, "clCreateProgramWithBinary");
	reallib_clRetainProgram = (cl_api_call_clRetainProgram) dlSymFunction(libcl_ptr, "clRetainProgram");
	reallib_clReleaseProgram = (cl_api_call_clReleaseProgram) dlSymFunction(libcl_ptr, "clReleaseProgram");
	reallib_clBuildProgram = (cl_api_call_clBuildProgram) dlSymFunction(libcl_ptr, "clBuildProgram");
	reallib_clUnloadCompiler = (cl_api_call_clUnloadCompiler) dlSymFunction(libcl_ptr, "clUnloadCompiler");
	reallib_clGetProgramInfo = (cl_api_call_clGetProgramInfo) dlSymFunction(libcl_ptr, "clGetProgramInfo");
	reallib_clGetProgramBuildInfo = (cl_api_call_clGetProgramBuildInfo) dlSymFunction(libcl_ptr, "clGetProgramBuildInfo");
	reallib_clCreateKernel = (cl_api_call_clCreateKernel) dlSymFunction(libcl_ptr, "clCreateKernel");
	reallib_clCreateKernelsInProgram = (cl_api_call_clCreateKernelsInProgram) dlSymFunction(libcl_ptr, "clCreateKernelsInProgram");
	reallib_clRetainKernel = (cl_api_call_clRetainKernel) dlSymFunction(libcl_ptr, "clRetainKernel");
	reallib_clReleaseKernel = (cl_api_call_clReleaseKernel) dlSymFunction(libcl_ptr, "clReleaseKernel");
	reallib_clSetKernelArg = (cl_api_call_clSetKernelArg) dlSymFunction(libcl_ptr, "clSetKernelArg");
	reallib_clGetKernelInfo = (cl_api_call_clGetKernelInfo) dlSymFunction(libcl_ptr, "clGetKernelInfo");
	reallib_clGetKernelWorkGroupInfo = (cl_api_call_clGetKernelWorkGroupInfo) dlSymFunction(libcl_ptr, "clGetKernelWorkGroupInfo");
	reallib_clWaitForEvents = (cl_api_call_clWaitForEvents) dlSymFunction(libcl_ptr, "clWaitForEvents");
	reallib_clGetEventInfo = (cl_api_call_clGetEventInfo) dlSymFunction(libcl_ptr, "clGetEventInfo");
	reallib_clCreateUserEvent = (cl_api_call_clCreateUserEvent) dlSymFunction(libcl_ptr, "clCreateUserEvent");
	reallib_clRetainEvent = (cl_api_call_clRetainEvent) dlSymFunction(libcl_ptr, "clRetainEvent");
	reallib_clReleaseEvent = (cl_api_call_clReleaseEvent) dlSymFunction(libcl_ptr, "clReleaseEvent");
	reallib_clSetUserEventStatus = (cl_api_call_clSetUserEventStatus) dlSymFunction(libcl_ptr, "clSetUserEventStatus");
	reallib_clSetEventCallback = (cl_api_call_clSetEventCallback) dlSymFunction(libcl_ptr, "clSetEventCallback");
	reallib_clGetEventProfilingInfo = (cl_api_call_clGetEventProfilingInfo) dlSymFunction(libcl_ptr, "clGetEventProfilingInfo");
	reallib_clFlush = (cl_api_call_clFlush) dlSymFunction(libcl_ptr, "clFlush");
	reallib_clFinish = (cl_api_call_clFinish) dlSymFunction(libcl_ptr, "clFinish");
	reallib_clEnqueueReadBuffer = (cl_api_call_clEnqueueReadBuffer) dlSymFunction(libcl_ptr, "clEnqueueReadBuffer");
	reallib_clEnqueueReadBufferRect = (cl_api_call_clEnqueueReadBufferRect) dlSymFunction(libcl_ptr, "clEnqueueReadBufferRect");
	reallib_clEnqueueWriteBuffer = (cl_api_call_clEnqueueWriteBuffer) dlSymFunction(libcl_ptr, "clEnqueueWriteBuffer");
	reallib_clEnqueueWriteBufferRect = (cl_api_call_clEnqueueWriteBufferRect) dlSymFunction(libcl_ptr, "clEnqueueWriteBufferRect");
	reallib_clEnqueueCopyBuffer = (cl_api_call_clEnqueueCopyBuffer) dlSymFunction(libcl_ptr, "clEnqueueCopyBuffer");
	reallib_clEnqueueCopyBufferRect = (cl_api_call_clEnqueueCopyBufferRect) dlSymFunction(libcl_ptr, "clEnqueueCopyBufferRect");
	reallib_clEnqueueReadImage = (cl_api_call_clEnqueueReadImage) dlSymFunction(libcl_ptr, "clEnqueueReadImage");
	reallib_clEnqueueWriteImage = (cl_api_call_clEnqueueWriteImage) dlSymFunction(libcl_ptr, "clEnqueueWriteImage");
	reallib_clEnqueueCopyImage = (cl_api_call_clEnqueueCopyImage) dlSymFunction(libcl_ptr, "clEnqueueCopyImage");
	reallib_clEnqueueCopyImageToBuffer = (cl_api_call_clEnqueueCopyImageToBuffer) dlSymFunction(libcl_ptr, "clEnqueueCopyImageToBuffer");
	reallib_clEnqueueCopyBufferToImage = (cl_api_call_clEnqueueCopyBufferToImage) dlSymFunction(libcl_ptr, "clEnqueueCopyBufferToImage");
	reallib_clEnqueueMapBuffer = (cl_api_call_clEnqueueMapBuffer) dlSymFunction(libcl_ptr, "clEnqueueMapBuffer");
	reallib_clEnqueueMapImage = (cl_api_call_clEnqueueMapImage) dlSymFunction(libcl_ptr, "clEnqueueMapImage");
	reallib_clEnqueueUnmapMemObject = (cl_api_call_clEnqueueUnmapMemObject) dlSymFunction(libcl_ptr, "clEnqueueUnmapMemObject");
	reallib_clEnqueueNDRangeKernel = (cl_api_call_clEnqueueNDRangeKernel) dlSymFunction(libcl_ptr, "clEnqueueNDRangeKernel");
	reallib_clEnqueueTask = (cl_api_call_clEnqueueTask) dlSymFunction(libcl_ptr, "clEnqueueTask");
	reallib_clEnqueueNativeKernel = (cl_api_call_clEnqueueNativeKernel) dlSymFunction(libcl_ptr, "clEnqueueNativeKernel");
	reallib_clEnqueueMarker = (cl_api_call_clEnqueueMarker) dlSymFunction(libcl_ptr, "clEnqueueMarker");
	reallib_clEnqueueWaitForEvents = (cl_api_call_clEnqueueWaitForEvents) dlSymFunction(libcl_ptr, "clEnqueueWaitForEvents");
	reallib_clEnqueueBarrier = (cl_api_call_clEnqueueBarrier) dlSymFunction(libcl_ptr, "clEnqueueBarrier");
	reallib_clGetExtensionFunctionAddress = (cl_api_call_clGetExtensionFunctionAddress) dlSymFunction(libcl_ptr, "clGetExtensionFunctionAddress");
}

cl_int clGetPlatformIDs(cl_uint num_entries, cl_platform_id * platforms, cl_uint * num_platforms)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetPlatformIDs, num_entries, platforms, num_platforms);
	cl_int ret = reallib_clGetPlatformIDs(num_entries, platforms, num_platforms);
	return ret;
}

cl_int clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetPlatformInfo, platform, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetPlatformInfo(platform, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

cl_int clGetDeviceIDs(cl_platform_id platform, cl_device_type device_type, cl_uint num_entries, cl_device_id * devices, cl_uint * num_devices)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetDeviceIDs, platform, device_type, num_entries, devices, num_devices);
	cl_int ret = reallib_clGetDeviceIDs(platform, device_type, num_entries, devices, num_devices);
	return ret;
}

cl_int clGetDeviceInfo(cl_device_id device, cl_device_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetDeviceInfo, device, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetDeviceInfo(device, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

cl_context clCreateContext(const cl_context_properties * properties, cl_uint num_devices, const cl_device_id * devices, void (CL_CALLBACK * pfn_notify )(const char *, const void *, size_t, void *) , void * param_4, cl_int * user_data)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clCreateContext, properties, num_devices, devices, pfn_notify, param_4, user_data);
	cl_context ret = reallib_clCreateContext(properties, num_devices, devices, pfn_notify, param_4, user_data);
	return ret;
}

cl_context clCreateContextFromType(const cl_context_properties * properties, cl_device_type device_type, void (CL_CALLBACK * pfn_notify )(const char *, const void *, size_t, void *) , void * param_3, cl_int * user_data)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clCreateContextFromType, properties, device_type, pfn_notify, param_3, user_data);
	cl_context ret = reallib_clCreateContextFromType(properties, device_type, pfn_notify, param_3, user_data);
	return ret;
}

cl_int clRetainContext(cl_context context)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clRetainContext, context);
	cl_int ret = reallib_clRetainContext(context);
	return ret;
}

cl_int clReleaseContext(cl_context context)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clReleaseContext, context);
	cl_int ret = reallib_clReleaseContext(context);
	return ret;
}

cl_int clGetContextInfo(cl_context context, cl_context_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetContextInfo, context, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetContextInfo(context, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

cl_command_queue clCreateCommandQueue(cl_context context, cl_device_id device, cl_command_queue_properties properties, cl_int * errcode_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clCreateCommandQueue, context, device, properties, errcode_ret);
	cl_command_queue ret = reallib_clCreateCommandQueue(context, device, properties, errcode_ret);
	return ret;
}

cl_int clRetainCommandQueue(cl_command_queue command_queue)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clRetainCommandQueue, command_queue);
	cl_int ret = reallib_clRetainCommandQueue(command_queue);
	return ret;
}

cl_int clReleaseCommandQueue(cl_command_queue command_queue)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clReleaseCommandQueue, command_queue);
	cl_int ret = reallib_clReleaseCommandQueue(command_queue);
	return ret;
}

cl_int clGetCommandQueueInfo(cl_command_queue command_queue, cl_command_queue_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetCommandQueueInfo, command_queue, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetCommandQueueInfo(command_queue, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

cl_mem clCreateBuffer(cl_context context, cl_mem_flags flags, size_t size, void * host_ptr, cl_int * errcode_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clCreateBuffer, context, flags, size, host_ptr, errcode_ret);
	cl_mem ret = reallib_clCreateBuffer(context, flags, size, host_ptr, errcode_ret);
	return ret;
}

cl_mem clCreateSubBuffer(cl_mem buffer, cl_mem_flags flags, cl_buffer_create_type buffer_create_type, const void * buffer_create_info, cl_int * errcode_ret)  CL_API_SUFFIX__VERSION_1_1 {
	tracepoint(clust_provider, clust_clCreateSubBuffer, buffer, flags, buffer_create_type, buffer_create_info, errcode_ret);
	cl_mem ret = reallib_clCreateSubBuffer(buffer, flags, buffer_create_type, buffer_create_info, errcode_ret);
	return ret;
}

cl_mem clCreateImage2D(cl_context context, cl_mem_flags flags, const cl_image_format * image_format, size_t image_width, size_t image_height, size_t image_row_pitch, void * host_ptr, cl_int * errcode_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clCreateImage2D, context, flags, image_format, image_width, image_height, image_row_pitch, host_ptr, errcode_ret);
	cl_mem ret = reallib_clCreateImage2D(context, flags, image_format, image_width, image_height, image_row_pitch, host_ptr, errcode_ret);
	return ret;
}

cl_mem clCreateImage3D(cl_context context, cl_mem_flags flags, const cl_image_format * image_format, size_t image_width, size_t image_height, size_t image_depth, size_t image_row_pitch, size_t image_slice_pitch, void * host_ptr, cl_int * errcode_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clCreateImage3D, context, flags, image_format, image_width, image_height, image_depth, image_row_pitch, image_slice_pitch, host_ptr, errcode_ret);
	cl_mem ret = reallib_clCreateImage3D(context, flags, image_format, image_width, image_height, image_depth, image_row_pitch, image_slice_pitch, host_ptr, errcode_ret);
	return ret;
}

cl_int clRetainMemObject(cl_mem memobj)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clRetainMemObject, memobj);
	cl_int ret = reallib_clRetainMemObject(memobj);
	return ret;
}

cl_int clReleaseMemObject(cl_mem memobj)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clReleaseMemObject, memobj);
	cl_int ret = reallib_clReleaseMemObject(memobj);
	return ret;
}

cl_int clGetSupportedImageFormats(cl_context context, cl_mem_flags flags, cl_mem_object_type image_type, cl_uint num_entries, cl_image_format * image_formats, cl_uint * num_image_formats)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetSupportedImageFormats, context, flags, image_type, num_entries, image_formats, num_image_formats);
	cl_int ret = reallib_clGetSupportedImageFormats(context, flags, image_type, num_entries, image_formats, num_image_formats);
	return ret;
}

cl_int clGetMemObjectInfo(cl_mem memobj, cl_mem_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetMemObjectInfo, memobj, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetMemObjectInfo(memobj, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

cl_int clGetImageInfo(cl_mem image, cl_image_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetImageInfo, image, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetImageInfo(image, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

cl_int clSetMemObjectDestructorCallback(cl_mem memobj, void (CL_CALLBACK * pfn_notify )( cl_mem , void* ) , void * user_data)              CL_API_SUFFIX__VERSION_1_1 {
	tracepoint(clust_provider, clust_clSetMemObjectDestructorCallback, memobj, pfn_notify, user_data);
	cl_int ret = reallib_clSetMemObjectDestructorCallback(memobj, pfn_notify, user_data);
	return ret;
}

cl_sampler clCreateSampler(cl_context context, cl_bool normalized_coords, cl_addressing_mode addressing_mode, cl_filter_mode filter_mode, cl_int * errcode_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clCreateSampler, context, normalized_coords, addressing_mode, filter_mode, errcode_ret);
	cl_sampler ret = reallib_clCreateSampler(context, normalized_coords, addressing_mode, filter_mode, errcode_ret);
	return ret;
}

cl_int clRetainSampler(cl_sampler sampler)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clRetainSampler, sampler);
	cl_int ret = reallib_clRetainSampler(sampler);
	return ret;
}

cl_int clReleaseSampler(cl_sampler sampler)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clReleaseSampler, sampler);
	cl_int ret = reallib_clReleaseSampler(sampler);
	return ret;
}

cl_int clGetSamplerInfo(cl_sampler sampler, cl_sampler_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetSamplerInfo, sampler, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetSamplerInfo(sampler, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

cl_program clCreateProgramWithSource(cl_context context, cl_uint count, const char ** strings, const size_t * lengths, cl_int * errcode_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clCreateProgramWithSource, context, count, strings, lengths, errcode_ret);
	cl_program ret = reallib_clCreateProgramWithSource(context, count, strings, lengths, errcode_ret);
	return ret;
}

cl_program clCreateProgramWithBinary(cl_context context, cl_uint num_devices, const cl_device_id * device_list, const size_t * lengths, const unsigned char ** binaries, cl_int * binary_status, cl_int * errcode_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clCreateProgramWithBinary, context, num_devices, device_list, lengths, binaries, binary_status, errcode_ret);
	cl_program ret = reallib_clCreateProgramWithBinary(context, num_devices, device_list, lengths, binaries, binary_status, errcode_ret);
	return ret;
}

cl_int clRetainProgram(cl_program program)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clRetainProgram, program);
	cl_int ret = reallib_clRetainProgram(program);
	return ret;
}

cl_int clReleaseProgram(cl_program program)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clReleaseProgram, program);
	cl_int ret = reallib_clReleaseProgram(program);
	return ret;
}

cl_int clBuildProgram(cl_program program, cl_uint num_devices, const cl_device_id * device_list, const char * options, void (CL_CALLBACK * pfn_notify )(cl_program , void * ) , void * user_data)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clBuildProgram, program, num_devices, device_list, options, pfn_notify, user_data);
	cl_int ret = reallib_clBuildProgram(program, num_devices, device_list, options, pfn_notify, user_data);
	return ret;
}

cl_int clUnloadCompiler()  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clUnloadCompiler);
	cl_int ret = reallib_clUnloadCompiler();
	return ret;
}

cl_int clGetProgramInfo(cl_program program, cl_program_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetProgramInfo, program, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetProgramInfo(program, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

cl_int clGetProgramBuildInfo(cl_program program, cl_device_id device, cl_program_build_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetProgramBuildInfo, program, device, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetProgramBuildInfo(program, device, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

cl_kernel clCreateKernel(cl_program program, const char * kernel_name, cl_int * errcode_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clCreateKernel, program, kernel_name, errcode_ret);
	cl_kernel ret = reallib_clCreateKernel(program, kernel_name, errcode_ret);
	return ret;
}

cl_int clCreateKernelsInProgram(cl_program program, cl_uint num_kernels, cl_kernel * kernels, cl_uint * num_kernels_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clCreateKernelsInProgram, program, num_kernels, kernels, num_kernels_ret);
	cl_int ret = reallib_clCreateKernelsInProgram(program, num_kernels, kernels, num_kernels_ret);
	return ret;
}

cl_int clRetainKernel(cl_kernel kernel)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clRetainKernel, kernel);
	cl_int ret = reallib_clRetainKernel(kernel);
	return ret;
}

cl_int clReleaseKernel(cl_kernel kernel)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clReleaseKernel, kernel);
	cl_int ret = reallib_clReleaseKernel(kernel);
	return ret;
}

cl_int clSetKernelArg(cl_kernel kernel, cl_uint arg_index, size_t arg_size, const void * arg_value)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clSetKernelArg, kernel, arg_index, arg_size, arg_value);
	cl_int ret = reallib_clSetKernelArg(kernel, arg_index, arg_size, arg_value);
	return ret;
}

cl_int clGetKernelInfo(cl_kernel kernel, cl_kernel_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetKernelInfo, kernel, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetKernelInfo(kernel, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

cl_int clGetKernelWorkGroupInfo(cl_kernel kernel, cl_device_id device, cl_kernel_work_group_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetKernelWorkGroupInfo, kernel, device, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetKernelWorkGroupInfo(kernel, device, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

cl_int clWaitForEvents(cl_uint num_events, const cl_event * event_list)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clWaitForEvents, num_events, event_list);
	cl_int ret = reallib_clWaitForEvents(num_events, event_list);
	return ret;
}

cl_int clGetEventInfo(cl_event event, cl_event_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetEventInfo, event, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetEventInfo(event, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

cl_event clCreateUserEvent(cl_context context, cl_int * errcode_ret)  CL_API_SUFFIX__VERSION_1_1 {
	tracepoint(clust_provider, clust_clCreateUserEvent, context, errcode_ret);
	cl_event ret = reallib_clCreateUserEvent(context, errcode_ret);
	return ret;
}

cl_int clRetainEvent(cl_event event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clRetainEvent, event);
	cl_int ret = reallib_clRetainEvent(event);
	return ret;
}

cl_int clReleaseEvent(cl_event event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clReleaseEvent, event);
	cl_int ret = reallib_clReleaseEvent(event);
	return ret;
}

cl_int clSetUserEventStatus(cl_event event, cl_int execution_status)  CL_API_SUFFIX__VERSION_1_1 {
	tracepoint(clust_provider, clust_clSetUserEventStatus, event, execution_status);
	cl_int ret = reallib_clSetUserEventStatus(event, execution_status);
	return ret;
}

cl_int clSetEventCallback(cl_event event, cl_int command_exec_callback_type, void (CL_CALLBACK * pfn_notify )(cl_event, cl_int, void *) , void * user_data)  CL_API_SUFFIX__VERSION_1_1 {
	tracepoint(clust_provider, clust_clSetEventCallback, event, command_exec_callback_type, pfn_notify, user_data);
	cl_int ret = reallib_clSetEventCallback(event, command_exec_callback_type, pfn_notify, user_data);
	return ret;
}

cl_int clGetEventProfilingInfo(cl_event event, cl_profiling_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetEventProfilingInfo, event, param_name, param_value_size, param_value, param_value_size_ret);
	cl_int ret = reallib_clGetEventProfilingInfo(event, param_name, param_value_size, param_value, param_value_size_ret);
	return ret;
}

cl_int clFlush(cl_command_queue command_queue)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clFlush, command_queue);
	cl_int ret = reallib_clFlush(command_queue);
	return ret;
}

cl_int clFinish(cl_command_queue command_queue)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clFinish, command_queue);
	cl_int ret = reallib_clFinish(command_queue);
	return ret;
}

cl_int clEnqueueReadBuffer(cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_read, size_t offset, size_t cb, void * ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueReadBuffer, command_queue, buffer, blocking_read, offset, cb, ptr, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueReadBuffer(command_queue, buffer, blocking_read, offset, cb, ptr, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

cl_int clEnqueueReadBufferRect(cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_read, const size_t * buffer_origin, const size_t * host_origin, const size_t * region, size_t buffer_row_pitch, size_t buffer_slice_pitch, size_t host_row_pitch, size_t host_slice_pitch, void * ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_1 {
	tracepoint(clust_provider, clust_clEnqueueReadBufferRect, command_queue, buffer, blocking_read, buffer_origin, host_origin, region, buffer_row_pitch, buffer_slice_pitch, host_row_pitch, host_slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueReadBufferRect(command_queue, buffer, blocking_read, buffer_origin, host_origin, region, buffer_row_pitch, buffer_slice_pitch, host_row_pitch, host_slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

cl_int clEnqueueWriteBuffer(cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_write, size_t offset, size_t cb, const void * ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueWriteBuffer, command_queue, buffer, blocking_write, offset, cb, ptr, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueWriteBuffer(command_queue, buffer, blocking_write, offset, cb, ptr, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

cl_int clEnqueueWriteBufferRect(cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_write, const size_t * buffer_origin, const size_t * host_origin, const size_t * region, size_t buffer_row_pitch, size_t buffer_slice_pitch, size_t host_row_pitch, size_t host_slice_pitch, const void * ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_1 {
	tracepoint(clust_provider, clust_clEnqueueWriteBufferRect, command_queue, buffer, blocking_write, buffer_origin, host_origin, region, buffer_row_pitch, buffer_slice_pitch, host_row_pitch, host_slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueWriteBufferRect(command_queue, buffer, blocking_write, buffer_origin, host_origin, region, buffer_row_pitch, buffer_slice_pitch, host_row_pitch, host_slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

cl_int clEnqueueCopyBuffer(cl_command_queue command_queue, cl_mem src_buffer, cl_mem dst_buffer, size_t src_offset, size_t dst_offset, size_t cb, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueCopyBuffer, command_queue, src_buffer, dst_buffer, src_offset, dst_offset, cb, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueCopyBuffer(command_queue, src_buffer, dst_buffer, src_offset, dst_offset, cb, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

cl_int clEnqueueCopyBufferRect(cl_command_queue command_queue, cl_mem src_buffer, cl_mem dst_buffer, const size_t * src_origin, const size_t * dst_origin, const size_t * region, size_t src_row_pitch, size_t src_slice_pitch, size_t dst_row_pitch, size_t dst_slice_pitch, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_1 {
	tracepoint(clust_provider, clust_clEnqueueCopyBufferRect, command_queue, src_buffer, dst_buffer, src_origin, dst_origin, region, src_row_pitch, src_slice_pitch, dst_row_pitch, dst_slice_pitch, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueCopyBufferRect(command_queue, src_buffer, dst_buffer, src_origin, dst_origin, region, src_row_pitch, src_slice_pitch, dst_row_pitch, dst_slice_pitch, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

cl_int clEnqueueReadImage(cl_command_queue command_queue, cl_mem image, cl_bool blocking_read, const size_t * origin, const size_t * region, size_t row_pitch, size_t slice_pitch, void * ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueReadImage, command_queue, image, blocking_read, origin, region, row_pitch, slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueReadImage(command_queue, image, blocking_read, &origin, &region, row_pitch, slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

cl_int clEnqueueWriteImage(cl_command_queue command_queue, cl_mem image, cl_bool blocking_write, const size_t * origin, const size_t * region, size_t input_row_pitch, size_t input_slice_pitch, const void * ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueWriteImage, command_queue, image, blocking_write, origin, region, input_row_pitch, input_slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueWriteImage(command_queue, image, blocking_write, &origin, &region, input_row_pitch, input_slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

cl_int clEnqueueCopyImage(cl_command_queue command_queue, cl_mem src_image, cl_mem dst_image, const size_t * src_origin, const size_t * dst_origin, const size_t * region, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueCopyImage, command_queue, src_image, dst_image, &src_origin, &dst_origin, &region, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueCopyImage(command_queue, src_image, dst_image, &src_origin, &dst_origin, &region, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

cl_int clEnqueueCopyImageToBuffer(cl_command_queue command_queue, cl_mem src_image, cl_mem dst_buffer, const size_t * src_origin, const size_t * region, size_t dst_offset, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueCopyImageToBuffer, command_queue, src_image, dst_buffer, src_origin, region, dst_offset, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueCopyImageToBuffer(command_queue, src_image, dst_buffer, src_origin, region, dst_offset, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

cl_int clEnqueueCopyBufferToImage(cl_command_queue command_queue, cl_mem src_buffer, cl_mem dst_image, size_t src_offset, const size_t * dst_origin, const size_t * region, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueCopyBufferToImage, command_queue, src_buffer, dst_image, src_offset, dst_origin, region, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueCopyBufferToImage(command_queue, src_buffer, dst_image, src_offset, dst_origin, region, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

void * clEnqueueMapBuffer(cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_map, cl_map_flags map_flags, size_t offset, size_t cb, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event, cl_int * errcode_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueMapBuffer, command_queue, buffer, blocking_map, map_flags, offset, cb, num_events_in_wait_list, event_wait_list, event, errcode_ret);
	void * ret = reallib_clEnqueueMapBuffer(command_queue, buffer, blocking_map, map_flags, offset, cb, num_events_in_wait_list, event_wait_list, event, errcode_ret);
	return ret;
}

void * clEnqueueMapImage(cl_command_queue command_queue, cl_mem image, cl_bool blocking_map, cl_map_flags map_flags, const size_t * origin, const size_t * region, size_t * image_row_pitch, size_t * image_slice_pitch, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event, cl_int * errcode_ret)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueMapImage, command_queue, image, blocking_map, map_flags, origin, region, image_row_pitch, image_slice_pitch, num_events_in_wait_list, event_wait_list, event, errcode_ret);
	void * ret = reallib_clEnqueueMapImage(command_queue, image, blocking_map, map_flags, origin, region, image_row_pitch, image_slice_pitch, num_events_in_wait_list, event_wait_list, event, errcode_ret);
	return ret;
}

cl_int clEnqueueUnmapMemObject(cl_command_queue command_queue, cl_mem memobj, void * mapped_ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueUnmapMemObject, command_queue, memobj, mapped_ptr, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueUnmapMemObject(command_queue, memobj, mapped_ptr, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

cl_int clEnqueueNDRangeKernel(cl_command_queue command_queue, cl_kernel kernel, cl_uint work_dim, const size_t * global_work_offset, const size_t * global_work_size, const size_t * local_work_size, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueNDRangeKernel, command_queue, kernel, work_dim, global_work_offset, global_work_size, local_work_size, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueNDRangeKernel(command_queue, kernel, work_dim, global_work_offset, global_work_size, local_work_size, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

cl_int clEnqueueTask(cl_command_queue command_queue, cl_kernel kernel, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueTask, command_queue, kernel, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueTask(command_queue, kernel, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

cl_int clEnqueueNativeKernel(cl_command_queue command_queue, void (*user_func)(void *) , void * args, size_t cb_args, cl_uint num_mem_objects, const cl_mem * mem_list, const void ** args_mem_loc, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueNativeKernel, command_queue, user_func, args, cb_args, num_mem_objects, mem_list, args_mem_loc, num_events_in_wait_list, event_wait_list, event);
	cl_int ret = reallib_clEnqueueNativeKernel(command_queue, user_func, args, cb_args, num_mem_objects, mem_list, args_mem_loc, num_events_in_wait_list, event_wait_list, event);
	return ret;
}

cl_int clEnqueueMarker(cl_command_queue command_queue, cl_event * event)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueMarker, command_queue, event);
	cl_int ret = reallib_clEnqueueMarker(command_queue, event);
	return ret;
}

cl_int clEnqueueWaitForEvents(cl_command_queue command_queue, cl_uint num_events, const cl_event * event_list)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueWaitForEvents, command_queue, num_events, event_list);
	cl_int ret = reallib_clEnqueueWaitForEvents(command_queue, num_events, event_list);
	return ret;
}

cl_int clEnqueueBarrier(cl_command_queue command_queue)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clEnqueueBarrier, command_queue);
	cl_int ret = reallib_clEnqueueBarrier(command_queue);
	return ret;
}

void * clGetExtensionFunctionAddress(const char * func_name)  CL_API_SUFFIX__VERSION_1_0 {
	tracepoint(clust_provider, clust_clGetExtensionFunctionAddress, func_name);
	void * ret = reallib_clGetExtensionFunctionAddress(func_name);
	return ret;
}

#ifdef __cplusplus
}
#endif
