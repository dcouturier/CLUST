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
//#define LIBCL__STR ""
//#define LIBCL__STR ""
//#define LIBCL__STR ""

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



extern void init_libcl_symbols();

#endif /* CLUST_H_ */
