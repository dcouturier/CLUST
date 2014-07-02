/*
 * clust.h
 *
 *  Created on: Jun 18, 2014
 *      Author: david
 */

#ifndef CLUST_H_
#define CLUST_H_

#include <CL/cl.h>

#ifdef __cplusplus
extern "C" {
#endif


#define LIB_NAME "libCLUST"
#define LIBCL_NAME "libOpenCL.so"

#define LIBCL_GET_PLATFORM_IDS_STR "clGetPlatformIDs"
#define LIBCL_GET_PLATFORM_INFO_STR "clGetPlatformInfo"
#define LIBCL_GET_DEVICE_IDS_STR "clGetDeviceIDs"
#define LIBCL_GET_DEVICE_INFO_STR "clGetDeviceInfo"
#define LIBCL_CREATE_CONTEXT_STR "clCreateContext"
#define LIBCL_CREATE_CONTEXT_FROM_TYPE_STR "clCreateContextFromType"
#define LIBCL_RETAIN_CONTEXT_STR "clRetainContext"
#define LIBCL_RELEASE_CONTEXT_STR "clReleaseContext"
#define LIBCL_GET_CONTEXT_INFO_STR "clGetContextInfo"
#define LIBCL_CREATE_COMMAND_QUEUE_STR "clCreateCommandQueue"
#define LIBCL_RETAIN_COMMAND_QUEUE_STR "clRetainCommandQueue"
#define LIBCL_RELEASE_COMMAND_QUEUE_STR "clReleaseCommandQueue"
#define LIBCL_GET_COMMAND_QUEUE_STR "clGetCommandQueueInfo"
#ifdef CL_USE_DEPRECATED_OPENCL_1_0_APIS
#define LIBCL_SET_COMMAND_QUEUE_PROPERTY_STR "clSetCommandQueueProperty"
#endif /* CL_USE_DEPRECATED_OPENCL_1_0_APIS */
#define LIBCL_CREATE_BUFFER_STR "clCreateBuffer"
#define LIBCL_CREATE_SUB_BUFFER_STR "clCreateSubBuffer"
#define LIBCL_CREATE_IMAGE_2D_STR "clCreateImage2D"
#define LIBCL_CREATE_IMAGE_3D_STR "clCreateImage3D"
#define LIBCL_RETAIN_MEM_OBJECT_STR "clRetainMemObject"
#define LIBCL_RELEASE_MEM_OBJECT_STR "clReleaseMemObject"
#define LIBCL_GET_SUPPORTED_IMAGE_FORMATS_STR "clGetSupportedImageFormats"
#define LIBCL_GET_MEM_OBJECT_INFO_STR "clGetMemObjectInfo"
#define LIBCL_GET_IMAGE_INFO_STR "clGetImageInfo"
#define LIBCL_SET_MEM_OBJECT_DESTRUCTOR_CALLBACK_STR "clSetMemObjectDestructorCallback"
#define LIBCL_CREATE_SAMPLER_STR "clCreateSampler"
#define LIBCL_RETAIN_SAMPLER_STR "clRetainSampler"
#define LIBCL_RELEASE_SAMPLER_STR "clReleaseSampler"
#define LIBCL_GET_SAMPLER_INFO_STR "clGetSamplerInfo"
#define LIBCL_CREATE_PROGRAM_WITH_SOURCE_STR "clCreateProgramWithSource"
#define LIBCL_CREATE_PROGRAM_WITH_BINARY_STR "clCreateProgramWithBinary"
#define LIBCL_RETAIN_PROGRAM_STR "clRetainProgram"
#define LIBCL_RELEASE_PROGRAM_STR "clReleaseProgram"
#define LIBCL_BUILD_PROGRAM_STR "clBuildProgram"
#define LIBCL_UNLOAD_COMPILER_STR "clUnloadCompiler"
#define LIBCL_GET_PROGRAM_INFO_STR "clGetProgramInfo"
#define LIBCL_GET_PROGRAM_BUILD_INFO_STR "clGetProgramBuildInfo"
#define LIBCL_CREATE_KERNEL_STR "clCreateKernel"
#define LIBCL_CREATE_KERNEL_IN_PROGRAM_STR "clCreateKernelsInProgram"
#define LIBCL_RETAIN_KERNEL_STR "clRetainKernel"
#define LIBCL_RELEASE_KERNEL_STR "clReleaseKernel"
#define LIBCL_SET_KERNEL_ARG_STR "clSetKernelArg"
#define LIBCL_GET_KERNEL_INFO_STR "clGetKernelInfo"
#define LIBCL_GET_KERNEL_WORK_GROUP_INFO_STR "clGetKernelWorkGroupInfo"
#define LIBCL_WAIT_FOR_EVENTS_STR "clWaitForEvents"
#define LIBCL_GET_EVENT_INFO_STR "clGetEventInfo"
#define LIBCL_CREATE_USER_EVENT_STR "clCreateUserEvent"
#define LIBCL_RETAIN_EVENT_STR "clRetainEvent"
#define LIBCL_RELEASE_EVENT_STR "clReleaseEvent"
#define LIBCL_SET_USER_EVENT_STATUS_STR "clSetUserEventStatus"
#define LIBCL_SET_EVENT_CALLBACK_STR "clSetEventCallback"
#define LIBCL_GET_EVENT_PROFILING_INFO_STR "clGetEventProfilingInfo"
#define LIBCL_FLUSH_STR "clFlush"
#define LIBCL_FINISH_STR "clFinish"
#define LIBCL_ENQUEUE_READ_BUFFER_STR "clEnqueueReadBuffer"
#define LIBCL_ENQUEUE_READ_BUFFER_RECT_STR "clEnqueueReadBufferRect"
#define LIBCL_ENQUEUE_WRITE_BUFFER_STR "clEnqueueWriteBuffer"
#define LIBCL_ENQUEUE_WRITE_BUFFER_RECT_STR "clEnqueueWriteBufferRect"
#define LIBCL_ENQUEUE_COPY_BUFFER_STR "clEnqueueCopyBuffer"
#define LIBCL_ENQUEUE_COPY_BUFFER_RECT_STR "clEnqueueCopyBufferRect"
#define LIBCL_ENQUEUE_READ_IMAGE_STR "clEnqueueReadImage"
#define LIBCL_ENQUEUE_WRITE_IMAGE_STR "clEnqueueWriteImage"
#define LIBCL_ENQUEUE_COPY_IMAGE_STR "clEnqueueCopyImage"
#define LIBCL_ENQUEUE_COPY_IMAGE_TO_BUFFER_STR "clEnqueueCopyImageToBuffer"
#define LIBCL_ENQUEUE_COPY_STR "clEnqueueCopyBufferToImage"
#define LIBCL_ENQUEUE__STR "clEnqueueMapBuffer"
#define LIBCL_ENQUEUE__STR "clEnqueueMapImage"
#define LIBCL_ENQUEUE__STR "clEnqueueUnmapMemObject"
#define LIBCL_ENQUEUE__STR "clEnqueueNDRangeKernel"
#define LIBCL_ENQUEUE__STR "clEnqueueTask"
#define LIBCL_ENQUEUE__STR "clEnqueueNativeKernel"
#define LIBCL_ENQUEUE__STR "clEnqueueMarker"
#define LIBCL_ENQUEUE__STR "clEnqueueWaitForEvents"
#define LIBCL_ENQUEUE__STR "clEnqueueBarrier"
#define LIBCL__STR "clGetExtensionFunctionAddress"

#define ENABLE_FUNCTION_BEGIN	1
#define ENABLE_FUNCTION_END 	1

// OpenCL version 1.1: https://www.khronos.org/registry/cl/api/1.1/cl.h
/* Platform API */
typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_clGetPlatformIDs) (
		cl_uint          /* num_entries */,
		cl_platform_id * /* platforms */,
		cl_uint *        /* num_platforms */) CL_API_SUFFIX__VERSION_1_0;

extern cl_api_call_clGetPlatformIDs libCL_clGetPlatformIDs;
extern CL_API_ENTRY cl_int CL_API_CALL
clGetPlatformIDs(cl_uint          /* num_entries */,
		cl_platform_id * /* platforms */,
		cl_uint *        /* num_platforms */) CL_API_SUFFIX__VERSION_1_0;



typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_clGetPlatformInfo) (
		cl_platform_id   /* platform */,
		cl_platform_info /* param_name */,
		size_t           /* param_value_size */,
		void *           /* param_value */,
		size_t *         /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clGetPlatformInfo libCL_clGetPlatformInfo;
extern CL_API_ENTRY cl_int CL_API_CALL
clGetPlatformInfo(cl_platform_id   /* platform */,
		cl_platform_info /* param_name */,
		size_t           /* param_value_size */,
		void *           /* param_value */,
		size_t *         /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;



/* Device APIs */
typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_clGetDeviceIDs) (
		cl_platform_id   /* platform */,
		cl_device_type   /* device_type */,
		cl_uint          /* num_entries */,
		cl_device_id *   /* devices */,
		cl_uint *        /* num_devices */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clGetDeviceIDs libCL_clGetDeviceIDs;
extern CL_API_ENTRY cl_int CL_API_CALL
clGetDeviceIDs(cl_platform_id   /* platform */,
		cl_device_type   /* device_type */,
		cl_uint          /* num_entries */,
		cl_device_id *   /* devices */,
		cl_uint *        /* num_devices */) CL_API_SUFFIX__VERSION_1_0;



typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_clGetDeviceInfo) (
		cl_device_id    /* device */,
		cl_device_info  /* param_name */,
		size_t          /* param_value_size */,
		void *          /* param_value */,
		size_t *        /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clGetDeviceInfo libCL_clGetDeviceInfo;
extern CL_API_ENTRY cl_int CL_API_CALL
clGetDeviceInfo(cl_device_id    /* device */,
		cl_device_info  /* param_name */,
		size_t          /* param_value_size */,
		void *          /* param_value */,
		size_t *        /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;




/* Context APIs  */
typedef CL_API_ENTRY cl_context CL_API_CALL (*cl_api_call_clCreateContext) (
		const cl_context_properties * /* properties */,
		cl_uint                       /* num_devices */,
		const cl_device_id *          /* devices */,
		void (CL_CALLBACK * /* pfn_notify */)(const char *, const void *, size_t, void *),
		void *                        /* user_data */,
		cl_int *                      /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clCreateContext libCL_clCreateContext;
extern CL_API_ENTRY cl_context CL_API_CALL
clCreateContext(const cl_context_properties * /* properties */,
		cl_uint                       /* num_devices */,
		const cl_device_id *          /* devices */,
		void (CL_CALLBACK * /* pfn_notify */)(const char *, const void *, size_t, void *),
		void *                        /* user_data */,
		cl_int *                      /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;



typedef CL_API_ENTRY cl_context CL_API_CALL (*cl_api_call_clCreateContextFromType) (
		const cl_context_properties * /* properties */,
		cl_device_type                /* device_type */,
		void (CL_CALLBACK *     /* pfn_notify*/ )(const char *, const void *, size_t, void *),
		void *                        /* user_data */,
		cl_int *                      /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clCreateContextFromType libCL_clCreateContextFromType;
extern CL_API_ENTRY cl_context CL_API_CALL
clCreateContextFromType(const cl_context_properties * /* properties */,
		cl_device_type                /* device_type */,
		void (CL_CALLBACK *     /* pfn_notify*/ )(const char *, const void *, size_t, void *),
		void *                        /* user_data */,
		cl_int *                      /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;



typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_clRetainContext) (
		cl_context /* context */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clRetainContext libCL_clRetainContext;
extern CL_API_ENTRY cl_int CL_API_CALL
clRetainContext(cl_context /* context */) CL_API_SUFFIX__VERSION_1_0;



typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_clReleaseContext) (
		cl_context /* context */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clReleaseContext libCL_clReleaseContext;
extern CL_API_ENTRY cl_int CL_API_CALL
clReleaseContext(cl_context /* context */) CL_API_SUFFIX__VERSION_1_0;



typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_clGetContextInfo) (
		cl_context         /* context */,
		cl_context_info    /* param_name */,
		size_t             /* param_value_size */,
		void *             /* param_value */,
		size_t *           /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clGetContextInfo libCL_clGetContextInfo;
extern CL_API_ENTRY cl_int CL_API_CALL
clGetContextInfo(cl_context         /* context */,
		cl_context_info    /* param_name */,
		size_t             /* param_value_size */,
		void *             /* param_value */,
		size_t *           /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;



/* Command Queue APIs */
typedef CL_API_ENTRY cl_command_queue CL_API_CALL (*cl_api_call_clCreateCommandQueue) (
		cl_context                     /* context */,
		cl_device_id                   /* device */,
		cl_command_queue_properties    /* properties */,
		cl_int *                       /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clCreateCommandQueue libCL_clCreateCommandQueue;
extern CL_API_ENTRY cl_command_queue CL_API_CALL
clCreateCommandQueue(cl_context                     /* context */,
		cl_device_id                   /* device */,
		cl_command_queue_properties    /* properties */,
		cl_int *                       /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;



typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_clRetainCommandQueue) (
		cl_command_queue /* command_queue */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clRetainCommandQueue libCL_clRetainCommandQueue;
extern CL_API_ENTRY cl_int CL_API_CALL
clRetainCommandQueue(cl_command_queue /* command_queue */) CL_API_SUFFIX__VERSION_1_0;



typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_clReleaseCommandQueue) (
		cl_command_queue /* command_queue */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clReleaseCommandQueue libCL_clReleaseCommandQueue;
extern CL_API_ENTRY cl_int CL_API_CALL
clReleaseCommandQueue(cl_command_queue /* command_queue */) CL_API_SUFFIX__VERSION_1_0;



typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_clGetCommandQueueInfo) (
		cl_command_queue      /* command_queue */,
		cl_command_queue_info /* param_name */,
		size_t                /* param_value_size */,
		void *                /* param_value */,
		size_t *              /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clGetCommandQueueInfo libCL_clGetCommandQueueInfo;
extern CL_API_ENTRY cl_int CL_API_CALL
clGetCommandQueueInfo(cl_command_queue      /* command_queue */,
		cl_command_queue_info /* param_name */,
		size_t                /* param_value_size */,
		void *                /* param_value */,
		size_t *              /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;



#ifdef CL_USE_DEPRECATED_OPENCL_1_0_APIS
#warning CL_USE_DEPRECATED_OPENCL_1_0_APIS is defined. These APIs are unsupported and untested in OpenCL 1.1!
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
typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_clSetCommandQueueProperty) (
		cl_command_queue              /* command_queue */,
		cl_command_queue_properties   /* properties */,
		cl_bool                        /* enable */,
		cl_command_queue_properties * /* old_properties */) CL_EXT_SUFFIX__VERSION_1_0_DEPRECATED;
extern cl_api_call_clSetCommandQueueProperty libCL_clSetCommandQueueProperty;
extern CL_API_ENTRY cl_int CL_API_CALL
clSetCommandQueueProperty(cl_command_queue              /* command_queue */,
		cl_command_queue_properties   /* properties */,
		cl_bool                        /* enable */,
		cl_command_queue_properties * /* old_properties */) CL_EXT_SUFFIX__VERSION_1_0_DEPRECATED;
#endif /* CL_USE_DEPRECATED_OPENCL_1_0_APIS */


/* Memory Object APIs */
typedef CL_API_ENTRY cl_mem CL_API_CALL (*cl_api_call_clCreateBuffer) (
		cl_context   /* context */,
		cl_mem_flags /* flags */,
		size_t       /* size */,
		void *       /* host_ptr */,
		cl_int *     /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clCreateBuffer libCL_clCreateBuffer;
extern CL_API_ENTRY cl_mem CL_API_CALL
clCreateBuffer(cl_context   /* context */,
		cl_mem_flags /* flags */,
		size_t       /* size */,
		void *       /* host_ptr */,
		cl_int *     /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;



typedef CL_API_ENTRY cl_mem CL_API_CALL (*cl_api_call_clCreateSubBuffer) (
		cl_mem                   /* buffer */,
		cl_mem_flags             /* flags */,
		cl_buffer_create_type    /* buffer_create_type */,
		const void *             /* buffer_create_info */,
		cl_int *                 /* errcode_ret */) CL_API_SUFFIX__VERSION_1_1;
extern cl_api_call_clCreateSubBuffer libCL_clCreateSubBuffer;
extern CL_API_ENTRY cl_mem CL_API_CALL
clCreateSubBuffer(
		cl_mem                   /* buffer */,
		cl_mem_flags             /* flags */,
		cl_buffer_create_type    /* buffer_create_type */,
		const void *             /* buffer_create_info */,
		cl_int *                 /* errcode_ret */) CL_API_SUFFIX__VERSION_1_1;



typedef CL_API_ENTRY cl_mem CL_API_CALL (*cl_api_call_clCreateImage2D) (
		cl_context              /* context */,
		cl_mem_flags            /* flags */,
		const cl_image_format * /* image_format */,
		size_t                  /* image_width */,
		size_t                  /* image_height */,
		size_t                  /* image_row_pitch */,
		void *                  /* host_ptr */,
		cl_int *                /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clCreateImage2D libCL_clCreateImage2D;
extern CL_API_ENTRY cl_mem CL_API_CALL
clCreateImage2D(
		cl_context              /* context */,
		cl_mem_flags            /* flags */,
		const cl_image_format * /* image_format */,
		size_t                  /* image_width */,
		size_t                  /* image_height */,
		size_t                  /* image_row_pitch */,
		void *                  /* host_ptr */,
		cl_int *                /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;



typedef CL_API_ENTRY cl_mem CL_API_CALL (*cl_api_call_clCreateImage3D) (
		cl_context              /* context */,
				cl_mem_flags            /* flags */,
				const cl_image_format * /* image_format */,
				size_t                  /* image_width */,
				size_t                  /* image_height */,
				size_t                  /* image_depth */,
				size_t                  /* image_row_pitch */,
				size_t                  /* image_slice_pitch */,
				void *                  /* host_ptr */,
				cl_int *                /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clCreateImage3D libCL_clCreateImage3D;
extern CL_API_ENTRY cl_mem CL_API_CALL
clCreateImage3D(cl_context              /* context */,
		cl_mem_flags            /* flags */,
		const cl_image_format * /* image_format */,
		size_t                  /* image_width */,
		size_t                  /* image_height */,
		size_t                  /* image_depth */,
		size_t                  /* image_row_pitch */,
		size_t                  /* image_slice_pitch */,
		void *                  /* host_ptr */,
		cl_int *                /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;

typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_clRetainMemObject) (
		cl_mem /* memobj */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clRetainMemObject libCL_clRetainMemObject;
extern CL_API_ENTRY cl_int CL_API_CALL
clRetainMemObject(cl_mem /* memobj */) CL_API_SUFFIX__VERSION_1_0;



typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_clReleaseMemObject) (
		cl_mem /* memobj */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clReleaseMemObject libCL_clReleaseMemObject;
extern CL_API_ENTRY cl_int CL_API_CALL
clReleaseMemObject(cl_mem /* memobj */) CL_API_SUFFIX__VERSION_1_0;



typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_clGetSupportedImageFormats) (
		cl_context           /* context */,
				cl_mem_flags         /* flags */,
				cl_mem_object_type   /* image_type */,
				cl_uint              /* num_entries */,
				cl_image_format *    /* image_formats */,
				cl_uint *            /* num_image_formats */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clGetSupportedImageFormats libCL_clGetSupportedImageFormats;
extern CL_API_ENTRY cl_int CL_API_CALL
clGetSupportedImageFormats(cl_context           /* context */,
		cl_mem_flags         /* flags */,
		cl_mem_object_type   /* image_type */,
		cl_uint              /* num_entries */,
		cl_image_format *    /* image_formats */,
		cl_uint *            /* num_image_formats */) CL_API_SUFFIX__VERSION_1_0;



typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_clGetMemObjectInfo) (
		cl_mem           /* memobj */,
				cl_mem_info      /* param_name */,
				size_t           /* param_value_size */,
				void *           /* param_value */,
				size_t *         /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clGetMemObjectInfo libCL_clGetMemObjectInfo;
extern CL_API_ENTRY cl_int CL_API_CALL
clGetMemObjectInfo(cl_mem           /* memobj */,
		cl_mem_info      /* param_name */,
		size_t           /* param_value_size */,
		void *           /* param_value */,
		size_t *         /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;



typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_clGetImageInfo) (
		cl_mem           /* image */,
				cl_image_info    /* param_name */,
				size_t           /* param_value_size */,
				void *           /* param_value */,
				size_t *         /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clGetImageInfo libCL_clGetImageInfo;
extern CL_API_ENTRY cl_int CL_API_CALL
clGetImageInfo(cl_mem           /* image */,
		cl_image_info    /* param_name */,
		size_t           /* param_value_size */,
		void *           /* param_value */,
		size_t *         /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;



typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_clSetMemObjectDestructorCallback) (
		cl_mem /* memobj */,
				void (CL_CALLBACK * /*pfn_notify*/)( cl_mem /* memobj */, void* /*user_data*/),
				void * /*user_data */ )             CL_API_SUFFIX__VERSION_1_1;
extern cl_api_call_clSetMemObjectDestructorCallback libCL_clSetMemObjectDestructorCallback;
extern CL_API_ENTRY cl_int CL_API_CALL
clSetMemObjectDestructorCallback(  cl_mem /* memobj */,
		void (CL_CALLBACK * /*pfn_notify*/)( cl_mem /* memobj */, void* /*user_data*/),
		void * /*user_data */ )             CL_API_SUFFIX__VERSION_1_1;

/* Sampler APIs  */
typedef CL_API_ENTRY cl_sampler CL_API_CALL (*cl_api_call_clCreateSampler) (
		cl_context          /* context */,
				cl_bool             /* normalized_coords */,
				cl_addressing_mode  /* addressing_mode */,
				cl_filter_mode      /* filter_mode */,
				cl_int *            /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clCreateSampler libCL_clCreateSampler;
extern CL_API_ENTRY cl_sampler CL_API_CALL
clCreateSampler(cl_context          /* context */,
		cl_bool             /* normalized_coords */,
		cl_addressing_mode  /* addressing_mode */,
		cl_filter_mode      /* filter_mode */,
		cl_int *            /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;



typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_clRetainSampler) (
		cl_sampler /* sampler */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clRetainSampler libCL_clRetainSampler;
extern CL_API_ENTRY cl_int CL_API_CALL
clRetainSampler(cl_sampler /* sampler */) CL_API_SUFFIX__VERSION_1_0;



typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_clReleaseSampler) (
		cl_sampler /* sampler */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clReleaseSampler libCL_clReleaseSampler;
extern CL_API_ENTRY cl_int CL_API_CALL
clReleaseSampler(cl_sampler /* sampler */) CL_API_SUFFIX__VERSION_1_0;



typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_clGetSamplerInfo) (
		cl_sampler         /* sampler */,
				cl_sampler_info    /* param_name */,
				size_t             /* param_value_size */,
				void *             /* param_value */,
				size_t *           /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clGetSamplerInfo libCL_clGetSamplerInfo;
extern CL_API_ENTRY cl_int CL_API_CALL
clGetSamplerInfo(cl_sampler         /* sampler */,
		cl_sampler_info    /* param_name */,
		size_t             /* param_value_size */,
		void *             /* param_value */,
		size_t *           /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;



/* Program Object APIs  */
typedef CL_API_ENTRY cl_program CL_API_CALL (*cl_api_call_clCreateProgramWithSource) (
		cl_context        /* context */,
				cl_uint           /* count */,
				const char **     /* strings */,
				const size_t *    /* lengths */,
				cl_int *          /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clCreateProgramWithSource libCL_clCreateProgramWithSource;
extern CL_API_ENTRY cl_program CL_API_CALL
clCreateProgramWithSource(cl_context        /* context */,
		cl_uint           /* count */,
		const char **     /* strings */,
		const size_t *    /* lengths */,
		cl_int *          /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;



typedef CL_API_ENTRY cl_program CL_API_CALL (*cl_api_call_clCreateProgramWithBinary) (
		cl_context                     /* context */,
				cl_uint                        /* num_devices */,
				const cl_device_id *           /* device_list */,
				const size_t *                 /* lengths */,
				const unsigned char **         /* binaries */,
				cl_int *                       /* binary_status */,
				cl_int *                       /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clCreateProgramWithBinary libCL_clCreateProgramWithBinary;
extern CL_API_ENTRY cl_program CL_API_CALL
clCreateProgramWithBinary(cl_context                     /* context */,
		cl_uint                        /* num_devices */,
		const cl_device_id *           /* device_list */,
		const size_t *                 /* lengths */,
		const unsigned char **         /* binaries */,
		cl_int *                       /* binary_status */,
		cl_int *                       /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;



typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_clRetainProgram) (
		cl_program /* program */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clRetainProgram libCL_clRetainProgram;
extern CL_API_ENTRY cl_int CL_API_CALL
clRetainProgram(cl_program /* program */) CL_API_SUFFIX__VERSION_1_0;



typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_clReleaseProgram) (
		cl_program /* program */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clReleaseProgram libCL_clReleaseProgram;
extern CL_API_ENTRY cl_int CL_API_CALL
clReleaseProgram(cl_program /* program */) CL_API_SUFFIX__VERSION_1_0;



typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_clBuildProgram) (
		cl_program           /* program */,
				cl_uint              /* num_devices */,
				const cl_device_id * /* device_list */,
				const char *         /* options */,
				void (CL_CALLBACK *  /* pfn_notify */)(cl_program /* program */, void * /* user_data */),
				void *               /* user_data */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clBuildProgram libCL_clBuildProgram;
extern CL_API_ENTRY cl_int CL_API_CALL
clBuildProgram(cl_program           /* program */,
		cl_uint              /* num_devices */,
		const cl_device_id * /* device_list */,
		const char *         /* options */,
		void (CL_CALLBACK *  /* pfn_notify */)(cl_program /* program */, void * /* user_data */),
		void *               /* user_data */) CL_API_SUFFIX__VERSION_1_0;



typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_clUnloadCompiler) (
		void) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clUnloadCompiler libCL_clUnloadCompiler;
extern CL_API_ENTRY cl_int CL_API_CALL
clUnloadCompiler(void) CL_API_SUFFIX__VERSION_1_0;



typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_clGetProgramInfo) (
		cl_program         /* program */,
				cl_program_info    /* param_name */,
				size_t             /* param_value_size */,
				void *             /* param_value */,
				size_t *           /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clGetProgramInfo libCL_clGetProgramInfo;
extern CL_API_ENTRY cl_int CL_API_CALL
clGetProgramInfo(cl_program         /* program */,
		cl_program_info    /* param_name */,
		size_t             /* param_value_size */,
		void *             /* param_value */,
		size_t *           /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;



typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_clGetProgramBuildInfo) (
		cl_program            /* program */,
				cl_device_id          /* device */,
				cl_program_build_info /* param_name */,
				size_t                /* param_value_size */,
				void *                /* param_value */,
				size_t *              /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;
extern cl_api_call_clGetProgramBuildInfo libCL_clGetProgramBuildInfo;
extern CL_API_ENTRY cl_int CL_API_CALL
clGetProgramBuildInfo(cl_program            /* program */,
		cl_device_id          /* device */,
		cl_program_build_info /* param_name */,
		size_t                /* param_value_size */,
		void *                /* param_value */,
		size_t *              /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;
//
///* Kernel Object APIs */
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_kernel CL_API_CALL
//clCreateKernel(cl_program      /* program */,
//		const char *    /* kernel_name */,
//		cl_int *        /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clCreateKernelsInProgram(cl_program     /* program */,
//		cl_uint        /* num_kernels */,
//		cl_kernel *    /* kernels */,
//		cl_uint *      /* num_kernels_ret */) CL_API_SUFFIX__VERSION_1_0;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clRetainKernel(cl_kernel    /* kernel */) CL_API_SUFFIX__VERSION_1_0;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clReleaseKernel(cl_kernel   /* kernel */) CL_API_SUFFIX__VERSION_1_0;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clSetKernelArg(cl_kernel    /* kernel */,
//		cl_uint      /* arg_index */,
//		size_t       /* arg_size */,
//		const void * /* arg_value */) CL_API_SUFFIX__VERSION_1_0;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clGetKernelInfo(cl_kernel       /* kernel */,
//		cl_kernel_info  /* param_name */,
//		size_t          /* param_value_size */,
//		void *          /* param_value */,
//		size_t *        /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clGetKernelWorkGroupInfo(cl_kernel                  /* kernel */,
//		cl_device_id               /* device */,
//		cl_kernel_work_group_info  /* param_name */,
//		size_t                     /* param_value_size */,
//		void *                     /* param_value */,
//		size_t *                   /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;
//
///* Event Object APIs  */
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clWaitForEvents(cl_uint             /* num_events */,
//		const cl_event *    /* event_list */) CL_API_SUFFIX__VERSION_1_0;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clGetEventInfo(cl_event         /* event */,
//		cl_event_info    /* param_name */,
//		size_t           /* param_value_size */,
//		void *           /* param_value */,
//		size_t *         /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_event CL_API_CALL
//clCreateUserEvent(cl_context    /* context */,
//		cl_int *      /* errcode_ret */) CL_API_SUFFIX__VERSION_1_1;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clRetainEvent(cl_event /* event */) CL_API_SUFFIX__VERSION_1_0;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clReleaseEvent(cl_event /* event */) CL_API_SUFFIX__VERSION_1_0;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clSetUserEventStatus(cl_event   /* event */,
//		cl_int     /* execution_status */) CL_API_SUFFIX__VERSION_1_1;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clSetEventCallback( cl_event    /* event */,
//		cl_int      /* command_exec_callback_type */,
//		void (CL_CALLBACK * /* pfn_notify */)(cl_event, cl_int, void *),
//		void *      /* user_data */) CL_API_SUFFIX__VERSION_1_1;
//
///* Profiling APIs  */
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clGetEventProfilingInfo(cl_event            /* event */,
//		cl_profiling_info   /* param_name */,
//		size_t              /* param_value_size */,
//		void *              /* param_value */,
//		size_t *            /* param_value_size_ret */) CL_API_SUFFIX__VERSION_1_0;
//
///* Flush and Finish APIs */
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clFlush(cl_command_queue /* command_queue */) CL_API_SUFFIX__VERSION_1_0;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clFinish(cl_command_queue /* command_queue */) CL_API_SUFFIX__VERSION_1_0;
//
///* Enqueued Commands APIs */
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueReadBuffer(cl_command_queue    /* command_queue */,
//		cl_mem              /* buffer */,
//		cl_bool             /* blocking_read */,
//		size_t              /* offset */,
//		size_t              /* cb */,
//		void *              /* ptr */,
//		cl_uint             /* num_events_in_wait_list */,
//		const cl_event *    /* event_wait_list */,
//		cl_event *          /* event */) CL_API_SUFFIX__VERSION_1_0;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueReadBufferRect(cl_command_queue    /* command_queue */,
//		cl_mem              /* buffer */,
//		cl_bool             /* blocking_read */,
//		const size_t *      /* buffer_origin */,
//		const size_t *      /* host_origin */,
//		const size_t *      /* region */,
//		size_t              /* buffer_row_pitch */,
//		size_t              /* buffer_slice_pitch */,
//		size_t              /* host_row_pitch */,
//		size_t              /* host_slice_pitch */,
//		void *              /* ptr */,
//		cl_uint             /* num_events_in_wait_list */,
//		const cl_event *    /* event_wait_list */,
//		cl_event *          /* event */) CL_API_SUFFIX__VERSION_1_1;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueWriteBuffer(cl_command_queue   /* command_queue */,
//		cl_mem             /* buffer */,
//		cl_bool            /* blocking_write */,
//		size_t             /* offset */,
//		size_t             /* cb */,
//		const void *       /* ptr */,
//		cl_uint            /* num_events_in_wait_list */,
//		const cl_event *   /* event_wait_list */,
//		cl_event *         /* event */) CL_API_SUFFIX__VERSION_1_0;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueWriteBufferRect(cl_command_queue    /* command_queue */,
//		cl_mem              /* buffer */,
//		cl_bool             /* blocking_write */,
//		const size_t *      /* buffer_origin */,
//		const size_t *      /* host_origin */,
//		const size_t *      /* region */,
//		size_t              /* buffer_row_pitch */,
//		size_t              /* buffer_slice_pitch */,
//		size_t              /* host_row_pitch */,
//		size_t              /* host_slice_pitch */,
//		const void *        /* ptr */,
//		cl_uint             /* num_events_in_wait_list */,
//		const cl_event *    /* event_wait_list */,
//		cl_event *          /* event */) CL_API_SUFFIX__VERSION_1_1;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueCopyBuffer(cl_command_queue    /* command_queue */,
//		cl_mem              /* src_buffer */,
//		cl_mem              /* dst_buffer */,
//		size_t              /* src_offset */,
//		size_t              /* dst_offset */,
//		size_t              /* cb */,
//		cl_uint             /* num_events_in_wait_list */,
//		const cl_event *    /* event_wait_list */,
//		cl_event *          /* event */) CL_API_SUFFIX__VERSION_1_0;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueCopyBufferRect(cl_command_queue    /* command_queue */,
//		cl_mem              /* src_buffer */,
//		cl_mem              /* dst_buffer */,
//		const size_t *      /* src_origin */,
//		const size_t *      /* dst_origin */,
//		const size_t *      /* region */,
//		size_t              /* src_row_pitch */,
//		size_t              /* src_slice_pitch */,
//		size_t              /* dst_row_pitch */,
//		size_t              /* dst_slice_pitch */,
//		cl_uint             /* num_events_in_wait_list */,
//		const cl_event *    /* event_wait_list */,
//		cl_event *          /* event */) CL_API_SUFFIX__VERSION_1_1;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueReadImage(cl_command_queue     /* command_queue */,
//		cl_mem               /* image */,
//		cl_bool              /* blocking_read */,
//		const size_t *       /* origin[3] */,
//		const size_t *       /* region[3] */,
//		size_t               /* row_pitch */,
//		size_t               /* slice_pitch */,
//		void *               /* ptr */,
//		cl_uint              /* num_events_in_wait_list */,
//		const cl_event *     /* event_wait_list */,
//		cl_event *           /* event */) CL_API_SUFFIX__VERSION_1_0;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueWriteImage(cl_command_queue    /* command_queue */,
//		cl_mem              /* image */,
//		cl_bool             /* blocking_write */,
//		const size_t *      /* origin[3] */,
//		const size_t *      /* region[3] */,
//		size_t              /* input_row_pitch */,
//		size_t              /* input_slice_pitch */,
//		const void *        /* ptr */,
//		cl_uint             /* num_events_in_wait_list */,
//		const cl_event *    /* event_wait_list */,
//		cl_event *          /* event */) CL_API_SUFFIX__VERSION_1_0;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueCopyImage(cl_command_queue     /* command_queue */,
//		cl_mem               /* src_image */,
//		cl_mem               /* dst_image */,
//		const size_t *       /* src_origin[3] */,
//		const size_t *       /* dst_origin[3] */,
//		const size_t *       /* region[3] */,
//		cl_uint              /* num_events_in_wait_list */,
//		const cl_event *     /* event_wait_list */,
//		cl_event *           /* event */) CL_API_SUFFIX__VERSION_1_0;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueCopyImageToBuffer(cl_command_queue /* command_queue */,
//		cl_mem           /* src_image */,
//		cl_mem           /* dst_buffer */,
//		const size_t *   /* src_origin[3] */,
//		const size_t *   /* region[3] */,
//		size_t           /* dst_offset */,
//		cl_uint          /* num_events_in_wait_list */,
//		const cl_event * /* event_wait_list */,
//		cl_event *       /* event */) CL_API_SUFFIX__VERSION_1_0;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueCopyBufferToImage(cl_command_queue /* command_queue */,
//		cl_mem           /* src_buffer */,
//		cl_mem           /* dst_image */,
//		size_t           /* src_offset */,
//		const size_t *   /* dst_origin[3] */,
//		const size_t *   /* region[3] */,
//		cl_uint          /* num_events_in_wait_list */,
//		const cl_event * /* event_wait_list */,
//		cl_event *       /* event */) CL_API_SUFFIX__VERSION_1_0;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY void * CL_API_CALL
//clEnqueueMapBuffer(cl_command_queue /* command_queue */,
//		cl_mem           /* buffer */,
//		cl_bool          /* blocking_map */,
//		cl_map_flags     /* map_flags */,
//		size_t           /* offset */,
//		size_t           /* cb */,
//		cl_uint          /* num_events_in_wait_list */,
//		const cl_event * /* event_wait_list */,
//		cl_event *       /* event */,
//		cl_int *         /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY void * CL_API_CALL
//clEnqueueMapImage(cl_command_queue  /* command_queue */,
//		cl_mem            /* image */,
//		cl_bool           /* blocking_map */,
//		cl_map_flags      /* map_flags */,
//		const size_t *    /* origin[3] */,
//		const size_t *    /* region[3] */,
//		size_t *          /* image_row_pitch */,
//		size_t *          /* image_slice_pitch */,
//		cl_uint           /* num_events_in_wait_list */,
//		const cl_event *  /* event_wait_list */,
//		cl_event *        /* event */,
//		cl_int *          /* errcode_ret */) CL_API_SUFFIX__VERSION_1_0;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueUnmapMemObject(cl_command_queue /* command_queue */,
//		cl_mem           /* memobj */,
//		void *           /* mapped_ptr */,
//		cl_uint          /* num_events_in_wait_list */,
//		const cl_event *  /* event_wait_list */,
//		cl_event *        /* event */) CL_API_SUFFIX__VERSION_1_0;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueNDRangeKernel(cl_command_queue /* command_queue */,
//		cl_kernel        /* kernel */,
//		cl_uint          /* work_dim */,
//		const size_t *   /* global_work_offset */,
//		const size_t *   /* global_work_size */,
//		const size_t *   /* local_work_size */,
//		cl_uint          /* num_events_in_wait_list */,
//		const cl_event * /* event_wait_list */,
//		cl_event *       /* event */) CL_API_SUFFIX__VERSION_1_0;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueTask(cl_command_queue  /* command_queue */,
//		cl_kernel         /* kernel */,
//		cl_uint           /* num_events_in_wait_list */,
//		const cl_event *  /* event_wait_list */,
//		cl_event *        /* event */) CL_API_SUFFIX__VERSION_1_0;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueNativeKernel(cl_command_queue  /* command_queue */,
//		void (*user_func)(void *),
//		void *            /* args */,
//		size_t            /* cb_args */,
//		cl_uint           /* num_mem_objects */,
//		const cl_mem *    /* mem_list */,
//		const void **     /* args_mem_loc */,
//		cl_uint           /* num_events_in_wait_list */,
//		const cl_event *  /* event_wait_list */,
//		cl_event *        /* event */) CL_API_SUFFIX__VERSION_1_0;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueMarker(cl_command_queue    /* command_queue */,
//		cl_event *          /* event */) CL_API_SUFFIX__VERSION_1_0;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueWaitForEvents(cl_command_queue /* command_queue */,
//		cl_uint          /* num_events */,
//		const cl_event * /* event_list */) CL_API_SUFFIX__VERSION_1_0;
//
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY cl_int CL_API_CALL
//clEnqueueBarrier(cl_command_queue /* command_queue */) CL_API_SUFFIX__VERSION_1_0;
//
///* Extension function access
// *
// * Returns the extension function address for the given function name,
// * or NULL if a valid function can not be found.  The client must
// * check to make sure the address is not NULL, before using or
// * calling the returned function address.
// */
//typedef CL_API_ENTRY cl_int CL_API_CALL (*cl_api_call_) (
//
//extern cl_api_call_ libCL_;
//extern CL_API_ENTRY void * CL_API_CALL clGetExtensionFunctionAddress(const char * /* func_name */) CL_API_SUFFIX__VERSION_1_0;


extern void init_libcl_symbols();

#ifdef __cplusplus
}
#endif

#endif /* CLUST_H_ */
