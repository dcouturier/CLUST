#ifndef CLUST_H_
#define CLUST_H_

//#define __DEBUG__

#include <CL/cl.h>
#define LIB_NAME "libCLUST"
#define LIBCL_NAME "libOpenCL.so"

#ifdef __cplusplus
"C" {
#endif

typedef int bool;
enum { false, true };

#define API_CALL_CLGETPLATFORMIDS	0
#define API_CALL_CLGETPLATFORMINFO	1
#define API_CALL_CLGETDEVICEIDS	2
#define API_CALL_CLGETDEVICEINFO	3
#define API_CALL_CLCREATECONTEXT	4
#define API_CALL_CLCREATECONTEXTFROMTYPE	5
#define API_CALL_CLRETAINCONTEXT	6
#define API_CALL_CLRELEASECONTEXT	7
#define API_CALL_CLGETCONTEXTINFO	8
#define API_CALL_CLCREATECOMMANDQUEUE	9
#define API_CALL_CLRETAINCOMMANDQUEUE	10
#define API_CALL_CLRELEASECOMMANDQUEUE	11
#define API_CALL_CLGETCOMMANDQUEUEINFO	12
#define API_CALL_CLCREATEBUFFER	13
#define API_CALL_CLCREATESUBBUFFER	14
#define API_CALL_CLCREATEIMAGE2D	15
#define API_CALL_CLCREATEIMAGE3D	16
#define API_CALL_CLRETAINMEMOBJECT	17
#define API_CALL_CLRELEASEMEMOBJECT	18
#define API_CALL_CLGETSUPPORTEDIMAGEFORMATS	19
#define API_CALL_CLGETMEMOBJECTINFO	20
#define API_CALL_CLGETIMAGEINFO	21
#define API_CALL_CLSETMEMOBJECTDESTRUCTORCALLBACK	22
#define API_CALL_CLCREATESAMPLER	23
#define API_CALL_CLRETAINSAMPLER	24
#define API_CALL_CLRELEASESAMPLER	25
#define API_CALL_CLGETSAMPLERINFO	26
#define API_CALL_CLCREATEPROGRAMWITHSOURCE	27
#define API_CALL_CLCREATEPROGRAMWITHBINARY	28
#define API_CALL_CLRETAINPROGRAM	29
#define API_CALL_CLRELEASEPROGRAM	30
#define API_CALL_CLBUILDPROGRAM	31
#define API_CALL_CLUNLOADCOMPILER	32
#define API_CALL_CLGETPROGRAMINFO	33
#define API_CALL_CLGETPROGRAMBUILDINFO	34
#define API_CALL_CLCREATEKERNEL	35
#define API_CALL_CLCREATEKERNELSINPROGRAM	36
#define API_CALL_CLRETAINKERNEL	37
#define API_CALL_CLRELEASEKERNEL	38
#define API_CALL_CLSETKERNELARG	39
#define API_CALL_CLGETKERNELINFO	40
#define API_CALL_CLGETKERNELWORKGROUPINFO	41
#define API_CALL_CLWAITFOREVENTS	42
#define API_CALL_CLGETEVENTINFO	43
#define API_CALL_CLCREATEUSEREVENT	44
#define API_CALL_CLRETAINEVENT	45
#define API_CALL_CLRELEASEEVENT	46
#define API_CALL_CLSETUSEREVENTSTATUS	47
#define API_CALL_CLSETEVENTCALLBACK	48
#define API_CALL_CLGETEVENTPROFILINGINFO	49
#define API_CALL_CLFLUSH	50
#define API_CALL_CLFINISH	51
#define API_CALL_CLENQUEUEREADBUFFER	52
#define API_CALL_CLENQUEUEREADBUFFERRECT	53
#define API_CALL_CLENQUEUEWRITEBUFFER	54
#define API_CALL_CLENQUEUEWRITEBUFFERRECT	55
#define API_CALL_CLENQUEUECOPYBUFFER	56
#define API_CALL_CLENQUEUECOPYBUFFERRECT	57
#define API_CALL_CLENQUEUEREADIMAGE	58
#define API_CALL_CLENQUEUEWRITEIMAGE	59
#define API_CALL_CLENQUEUECOPYIMAGE	60
#define API_CALL_CLENQUEUECOPYIMAGETOBUFFER	61
#define API_CALL_CLENQUEUECOPYBUFFERTOIMAGE	62
#define API_CALL_CLENQUEUEMAPBUFFER	63
#define API_CALL_CLENQUEUEMAPIMAGE	64
#define API_CALL_CLENQUEUEUNMAPMEMOBJECT	65
#define API_CALL_CLENQUEUENDRANGEKERNEL	66
#define API_CALL_CLENQUEUETASK	67
#define API_CALL_CLENQUEUENATIVEKERNEL	68
#define API_CALL_CLENQUEUEMARKER	69
#define API_CALL_CLENQUEUEWAITFOREVENTS	70
#define API_CALL_CLENQUEUEBARRIER	71
#define API_CALL_CLGETEXTENSIONFUNCTIONADDRESS	72


typedef cl_int (*cl_api_call_clGetPlatformIDs) (cl_uint num_entries,cl_platform_id * platforms,cl_uint * num_platforms);
extern cl_api_call_clGetPlatformIDs reallib_clGetPlatformIDs;
extern cl_int clGetPlatformIDs(cl_uint num_entries, cl_platform_id * platforms, cl_uint * num_platforms) ;

typedef cl_int (*cl_api_call_clGetPlatformInfo) (cl_platform_id platform,cl_platform_info param_name,size_t param_value_size,void * param_value,size_t * param_value_size_ret);
extern cl_api_call_clGetPlatformInfo reallib_clGetPlatformInfo;
extern cl_int clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) ;

typedef cl_int (*cl_api_call_clGetDeviceIDs) (cl_platform_id platform,cl_device_type device_type,cl_uint num_entries,cl_device_id * devices,cl_uint * num_devices);
extern cl_api_call_clGetDeviceIDs reallib_clGetDeviceIDs;
extern cl_int clGetDeviceIDs(cl_platform_id platform, cl_device_type device_type, cl_uint num_entries, cl_device_id * devices, cl_uint * num_devices) ;

typedef cl_int (*cl_api_call_clGetDeviceInfo) (cl_device_id device,cl_device_info param_name,size_t param_value_size,void * param_value,size_t * param_value_size_ret);
extern cl_api_call_clGetDeviceInfo reallib_clGetDeviceInfo;
extern cl_int clGetDeviceInfo(cl_device_id device, cl_device_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) ;

typedef cl_context (*cl_api_call_clCreateContext) (const cl_context_properties * properties,cl_uint num_devices,const cl_device_id * devices,void (CL_CALLBACK * pfn_notify )(const char *, const void *, size_t, void *) ,void * param_4,cl_int * user_data);
extern cl_api_call_clCreateContext reallib_clCreateContext;
extern cl_context clCreateContext(const cl_context_properties * properties, cl_uint num_devices, const cl_device_id * devices, void (CL_CALLBACK * pfn_notify )(const char *, const void *, size_t, void *) , void * param_4, cl_int * user_data) ;

typedef cl_context (*cl_api_call_clCreateContextFromType) (const cl_context_properties * properties,cl_device_type device_type,void (CL_CALLBACK * pfn_notify )(const char *, const void *, size_t, void *) ,void * param_3,cl_int * user_data);
extern cl_api_call_clCreateContextFromType reallib_clCreateContextFromType;
extern cl_context clCreateContextFromType(const cl_context_properties * properties, cl_device_type device_type, void (CL_CALLBACK * pfn_notify )(const char *, const void *, size_t, void *) , void * param_3, cl_int * user_data) ;

typedef cl_int (*cl_api_call_clRetainContext) (cl_context context);
extern cl_api_call_clRetainContext reallib_clRetainContext;
extern cl_int clRetainContext(cl_context context) ;

typedef cl_int (*cl_api_call_clReleaseContext) (cl_context context);
extern cl_api_call_clReleaseContext reallib_clReleaseContext;
extern cl_int clReleaseContext(cl_context context) ;

typedef cl_int (*cl_api_call_clGetContextInfo) (cl_context context,cl_context_info param_name,size_t param_value_size,void * param_value,size_t * param_value_size_ret);
extern cl_api_call_clGetContextInfo reallib_clGetContextInfo;
extern cl_int clGetContextInfo(cl_context context, cl_context_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) ;

typedef cl_command_queue (*cl_api_call_clCreateCommandQueue) (cl_context context,cl_device_id device,cl_command_queue_properties properties,cl_int * errcode_ret);
extern cl_api_call_clCreateCommandQueue reallib_clCreateCommandQueue;
extern cl_command_queue clCreateCommandQueue(cl_context context, cl_device_id device, cl_command_queue_properties properties, cl_int * errcode_ret) ;

typedef cl_int (*cl_api_call_clRetainCommandQueue) (cl_command_queue command_queue);
extern cl_api_call_clRetainCommandQueue reallib_clRetainCommandQueue;
extern cl_int clRetainCommandQueue(cl_command_queue command_queue) ;

typedef cl_int (*cl_api_call_clReleaseCommandQueue) (cl_command_queue command_queue);
extern cl_api_call_clReleaseCommandQueue reallib_clReleaseCommandQueue;
extern cl_int clReleaseCommandQueue(cl_command_queue command_queue) ;

typedef cl_int (*cl_api_call_clGetCommandQueueInfo) (cl_command_queue command_queue,cl_command_queue_info param_name,size_t param_value_size,void * param_value,size_t * param_value_size_ret);
extern cl_api_call_clGetCommandQueueInfo reallib_clGetCommandQueueInfo;
extern cl_int clGetCommandQueueInfo(cl_command_queue command_queue, cl_command_queue_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) ;

typedef cl_mem (*cl_api_call_clCreateBuffer) (cl_context context,cl_mem_flags flags,size_t size,void * host_ptr,cl_int * errcode_ret);
extern cl_api_call_clCreateBuffer reallib_clCreateBuffer;
extern cl_mem clCreateBuffer(cl_context context, cl_mem_flags flags, size_t size, void * host_ptr, cl_int * errcode_ret) ;

typedef cl_mem (*cl_api_call_clCreateSubBuffer) (cl_mem buffer,cl_mem_flags flags,cl_buffer_create_type buffer_create_type,const void * buffer_create_info,cl_int * errcode_ret);
extern cl_api_call_clCreateSubBuffer reallib_clCreateSubBuffer;
extern cl_mem clCreateSubBuffer(cl_mem buffer, cl_mem_flags flags, cl_buffer_create_type buffer_create_type, const void * buffer_create_info, cl_int * errcode_ret) ;

typedef cl_mem (*cl_api_call_clCreateImage2D) (cl_context context,cl_mem_flags flags,const cl_image_format * image_format,size_t image_width,size_t image_height,size_t image_row_pitch,void * host_ptr,cl_int * errcode_ret);
extern cl_api_call_clCreateImage2D reallib_clCreateImage2D;
extern cl_mem clCreateImage2D(cl_context context, cl_mem_flags flags, const cl_image_format * image_format, size_t image_width, size_t image_height, size_t image_row_pitch, void * host_ptr, cl_int * errcode_ret) ;

typedef cl_mem (*cl_api_call_clCreateImage3D) (cl_context context,cl_mem_flags flags,const cl_image_format * image_format,size_t image_width,size_t image_height,size_t image_depth,size_t image_row_pitch,size_t image_slice_pitch,void * host_ptr,cl_int * errcode_ret);
extern cl_api_call_clCreateImage3D reallib_clCreateImage3D;
extern cl_mem clCreateImage3D(cl_context context, cl_mem_flags flags, const cl_image_format * image_format, size_t image_width, size_t image_height, size_t image_depth, size_t image_row_pitch, size_t image_slice_pitch, void * host_ptr, cl_int * errcode_ret) ;

typedef cl_int (*cl_api_call_clRetainMemObject) (cl_mem memobj);
extern cl_api_call_clRetainMemObject reallib_clRetainMemObject;
extern cl_int clRetainMemObject(cl_mem memobj) ;

typedef cl_int (*cl_api_call_clReleaseMemObject) (cl_mem memobj);
extern cl_api_call_clReleaseMemObject reallib_clReleaseMemObject;
extern cl_int clReleaseMemObject(cl_mem memobj) ;

typedef cl_int (*cl_api_call_clGetSupportedImageFormats) (cl_context context,cl_mem_flags flags,cl_mem_object_type image_type,cl_uint num_entries,cl_image_format * image_formats,cl_uint * num_image_formats);
extern cl_api_call_clGetSupportedImageFormats reallib_clGetSupportedImageFormats;
extern cl_int clGetSupportedImageFormats(cl_context context, cl_mem_flags flags, cl_mem_object_type image_type, cl_uint num_entries, cl_image_format * image_formats, cl_uint * num_image_formats) ;

typedef cl_int (*cl_api_call_clGetMemObjectInfo) (cl_mem memobj,cl_mem_info param_name,size_t param_value_size,void * param_value,size_t * param_value_size_ret);
extern cl_api_call_clGetMemObjectInfo reallib_clGetMemObjectInfo;
extern cl_int clGetMemObjectInfo(cl_mem memobj, cl_mem_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) ;

typedef cl_int (*cl_api_call_clGetImageInfo) (cl_mem image,cl_image_info param_name,size_t param_value_size,void * param_value,size_t * param_value_size_ret);
extern cl_api_call_clGetImageInfo reallib_clGetImageInfo;
extern cl_int clGetImageInfo(cl_mem image, cl_image_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) ;

typedef cl_int (*cl_api_call_clSetMemObjectDestructorCallback) (cl_mem memobj,void (CL_CALLBACK * pfn_notify )( cl_mem , void* ) ,void * user_data);
extern cl_api_call_clSetMemObjectDestructorCallback reallib_clSetMemObjectDestructorCallback;
extern cl_int clSetMemObjectDestructorCallback(cl_mem memobj, void (CL_CALLBACK * pfn_notify )( cl_mem , void* ) , void * user_data) ;

typedef cl_sampler (*cl_api_call_clCreateSampler) (cl_context context,cl_bool normalized_coords,cl_addressing_mode addressing_mode,cl_filter_mode filter_mode,cl_int * errcode_ret);
extern cl_api_call_clCreateSampler reallib_clCreateSampler;
extern cl_sampler clCreateSampler(cl_context context, cl_bool normalized_coords, cl_addressing_mode addressing_mode, cl_filter_mode filter_mode, cl_int * errcode_ret) ;

typedef cl_int (*cl_api_call_clRetainSampler) (cl_sampler sampler);
extern cl_api_call_clRetainSampler reallib_clRetainSampler;
extern cl_int clRetainSampler(cl_sampler sampler) ;

typedef cl_int (*cl_api_call_clReleaseSampler) (cl_sampler sampler);
extern cl_api_call_clReleaseSampler reallib_clReleaseSampler;
extern cl_int clReleaseSampler(cl_sampler sampler) ;

typedef cl_int (*cl_api_call_clGetSamplerInfo) (cl_sampler sampler,cl_sampler_info param_name,size_t param_value_size,void * param_value,size_t * param_value_size_ret);
extern cl_api_call_clGetSamplerInfo reallib_clGetSamplerInfo;
extern cl_int clGetSamplerInfo(cl_sampler sampler, cl_sampler_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) ;

typedef cl_program (*cl_api_call_clCreateProgramWithSource) (cl_context context,cl_uint count,const char ** strings,const size_t * lengths,cl_int * errcode_ret);
extern cl_api_call_clCreateProgramWithSource reallib_clCreateProgramWithSource;
extern cl_program clCreateProgramWithSource(cl_context context, cl_uint count, const char ** strings, const size_t * lengths, cl_int * errcode_ret) ;

typedef cl_program (*cl_api_call_clCreateProgramWithBinary) (cl_context context,cl_uint num_devices,const cl_device_id * device_list,const size_t * lengths,const unsigned char ** binaries,cl_int * binary_status,cl_int * errcode_ret);
extern cl_api_call_clCreateProgramWithBinary reallib_clCreateProgramWithBinary;
extern cl_program clCreateProgramWithBinary(cl_context context, cl_uint num_devices, const cl_device_id * device_list, const size_t * lengths, const unsigned char ** binaries, cl_int * binary_status, cl_int * errcode_ret) ;

typedef cl_int (*cl_api_call_clRetainProgram) (cl_program program);
extern cl_api_call_clRetainProgram reallib_clRetainProgram;
extern cl_int clRetainProgram(cl_program program) ;

typedef cl_int (*cl_api_call_clReleaseProgram) (cl_program program);
extern cl_api_call_clReleaseProgram reallib_clReleaseProgram;
extern cl_int clReleaseProgram(cl_program program) ;

typedef cl_int (*cl_api_call_clBuildProgram) (cl_program program,cl_uint num_devices,const cl_device_id * device_list,const char * options,void (CL_CALLBACK * pfn_notify )(cl_program , void * ) ,void * user_data);
extern cl_api_call_clBuildProgram reallib_clBuildProgram;
extern cl_int clBuildProgram(cl_program program, cl_uint num_devices, const cl_device_id * device_list, const char * options, void (CL_CALLBACK * pfn_notify )(cl_program , void * ) , void * user_data) ;

typedef cl_int (*cl_api_call_clUnloadCompiler) ();
extern cl_api_call_clUnloadCompiler reallib_clUnloadCompiler;
extern cl_int clUnloadCompiler() ;

typedef cl_int (*cl_api_call_clGetProgramInfo) (cl_program program,cl_program_info param_name,size_t param_value_size,void * param_value,size_t * param_value_size_ret);
extern cl_api_call_clGetProgramInfo reallib_clGetProgramInfo;
extern cl_int clGetProgramInfo(cl_program program, cl_program_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) ;

typedef cl_int (*cl_api_call_clGetProgramBuildInfo) (cl_program program,cl_device_id device,cl_program_build_info param_name,size_t param_value_size,void * param_value,size_t * param_value_size_ret);
extern cl_api_call_clGetProgramBuildInfo reallib_clGetProgramBuildInfo;
extern cl_int clGetProgramBuildInfo(cl_program program, cl_device_id device, cl_program_build_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) ;

typedef cl_kernel (*cl_api_call_clCreateKernel) (cl_program program,const char * kernel_name,cl_int * errcode_ret);
extern cl_api_call_clCreateKernel reallib_clCreateKernel;
extern cl_kernel clCreateKernel(cl_program program, const char * kernel_name, cl_int * errcode_ret) ;

typedef cl_int (*cl_api_call_clCreateKernelsInProgram) (cl_program program,cl_uint num_kernels,cl_kernel * kernels,cl_uint * num_kernels_ret);
extern cl_api_call_clCreateKernelsInProgram reallib_clCreateKernelsInProgram;
extern cl_int clCreateKernelsInProgram(cl_program program, cl_uint num_kernels, cl_kernel * kernels, cl_uint * num_kernels_ret) ;

typedef cl_int (*cl_api_call_clRetainKernel) (cl_kernel kernel);
extern cl_api_call_clRetainKernel reallib_clRetainKernel;
extern cl_int clRetainKernel(cl_kernel kernel) ;

typedef cl_int (*cl_api_call_clReleaseKernel) (cl_kernel kernel);
extern cl_api_call_clReleaseKernel reallib_clReleaseKernel;
extern cl_int clReleaseKernel(cl_kernel kernel) ;

typedef cl_int (*cl_api_call_clSetKernelArg) (cl_kernel kernel,cl_uint arg_index,size_t arg_size,const void * arg_value);
extern cl_api_call_clSetKernelArg reallib_clSetKernelArg;
extern cl_int clSetKernelArg(cl_kernel kernel, cl_uint arg_index, size_t arg_size, const void * arg_value) ;

typedef cl_int (*cl_api_call_clGetKernelInfo) (cl_kernel kernel,cl_kernel_info param_name,size_t param_value_size,void * param_value,size_t * param_value_size_ret);
extern cl_api_call_clGetKernelInfo reallib_clGetKernelInfo;
extern cl_int clGetKernelInfo(cl_kernel kernel, cl_kernel_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) ;

typedef cl_int (*cl_api_call_clGetKernelWorkGroupInfo) (cl_kernel kernel,cl_device_id device,cl_kernel_work_group_info param_name,size_t param_value_size,void * param_value,size_t * param_value_size_ret);
extern cl_api_call_clGetKernelWorkGroupInfo reallib_clGetKernelWorkGroupInfo;
extern cl_int clGetKernelWorkGroupInfo(cl_kernel kernel, cl_device_id device, cl_kernel_work_group_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) ;

typedef cl_int (*cl_api_call_clWaitForEvents) (cl_uint num_events,const cl_event * event_list);
extern cl_api_call_clWaitForEvents reallib_clWaitForEvents;
extern cl_int clWaitForEvents(cl_uint num_events, const cl_event * event_list) ;

typedef cl_int (*cl_api_call_clGetEventInfo) (cl_event event,cl_event_info param_name,size_t param_value_size,void * param_value,size_t * param_value_size_ret);
extern cl_api_call_clGetEventInfo reallib_clGetEventInfo;
extern cl_int clGetEventInfo(cl_event event, cl_event_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) ;

typedef cl_event (*cl_api_call_clCreateUserEvent) (cl_context context,cl_int * errcode_ret);
extern cl_api_call_clCreateUserEvent reallib_clCreateUserEvent;
extern cl_event clCreateUserEvent(cl_context context, cl_int * errcode_ret) ;

typedef cl_int (*cl_api_call_clRetainEvent) (cl_event event);
extern cl_api_call_clRetainEvent reallib_clRetainEvent;
extern cl_int clRetainEvent(cl_event event) ;

typedef cl_int (*cl_api_call_clReleaseEvent) (cl_event event);
extern cl_api_call_clReleaseEvent reallib_clReleaseEvent;
extern cl_int clReleaseEvent(cl_event event) ;

typedef cl_int (*cl_api_call_clSetUserEventStatus) (cl_event event,cl_int execution_status);
extern cl_api_call_clSetUserEventStatus reallib_clSetUserEventStatus;
extern cl_int clSetUserEventStatus(cl_event event, cl_int execution_status) ;

typedef cl_int (*cl_api_call_clSetEventCallback) (cl_event event,cl_int command_exec_callback_type,void (CL_CALLBACK * pfn_notify )(cl_event, cl_int, void *) ,void * user_data);
extern cl_api_call_clSetEventCallback reallib_clSetEventCallback;
extern cl_int clSetEventCallback(cl_event event, cl_int command_exec_callback_type, void (CL_CALLBACK * pfn_notify )(cl_event, cl_int, void *) , void * user_data) ;

typedef cl_int (*cl_api_call_clGetEventProfilingInfo) (cl_event event,cl_profiling_info param_name,size_t param_value_size,void * param_value,size_t * param_value_size_ret);
extern cl_api_call_clGetEventProfilingInfo reallib_clGetEventProfilingInfo;
extern cl_int clGetEventProfilingInfo(cl_event event, cl_profiling_info param_name, size_t param_value_size, void * param_value, size_t * param_value_size_ret) ;

typedef cl_int (*cl_api_call_clFlush) (cl_command_queue command_queue);
extern cl_api_call_clFlush reallib_clFlush;
extern cl_int clFlush(cl_command_queue command_queue) ;

typedef cl_int (*cl_api_call_clFinish) (cl_command_queue command_queue);
extern cl_api_call_clFinish reallib_clFinish;
extern cl_int clFinish(cl_command_queue command_queue) ;

typedef cl_int (*cl_api_call_clEnqueueReadBuffer) (cl_command_queue command_queue,cl_mem buffer,cl_bool blocking_read,size_t offset,size_t cb,void * ptr,cl_uint num_events_in_wait_list,const cl_event * event_wait_list,cl_event * event);
extern cl_api_call_clEnqueueReadBuffer reallib_clEnqueueReadBuffer;
extern cl_int clEnqueueReadBuffer(cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_read, size_t offset, size_t cb, void * ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) ;

typedef cl_int (*cl_api_call_clEnqueueReadBufferRect) (cl_command_queue command_queue,cl_mem buffer,cl_bool blocking_read,const size_t * buffer_origin,const size_t * host_origin,const size_t * region,size_t buffer_row_pitch,size_t buffer_slice_pitch,size_t host_row_pitch,size_t host_slice_pitch,void * ptr,cl_uint num_events_in_wait_list,const cl_event * event_wait_list,cl_event * event);
extern cl_api_call_clEnqueueReadBufferRect reallib_clEnqueueReadBufferRect;
extern cl_int clEnqueueReadBufferRect(cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_read, const size_t * buffer_origin, const size_t * host_origin, const size_t * region, size_t buffer_row_pitch, size_t buffer_slice_pitch, size_t host_row_pitch, size_t host_slice_pitch, void * ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) ;

typedef cl_int (*cl_api_call_clEnqueueWriteBuffer) (cl_command_queue command_queue,cl_mem buffer,cl_bool blocking_write,size_t offset,size_t cb,const void * ptr,cl_uint num_events_in_wait_list,const cl_event * event_wait_list,cl_event * event);
extern cl_api_call_clEnqueueWriteBuffer reallib_clEnqueueWriteBuffer;
extern cl_int clEnqueueWriteBuffer(cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_write, size_t offset, size_t cb, const void * ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) ;

typedef cl_int (*cl_api_call_clEnqueueWriteBufferRect) (cl_command_queue command_queue,cl_mem buffer,cl_bool blocking_write,const size_t * buffer_origin,const size_t * host_origin,const size_t * region,size_t buffer_row_pitch,size_t buffer_slice_pitch,size_t host_row_pitch,size_t host_slice_pitch,const void * ptr,cl_uint num_events_in_wait_list,const cl_event * event_wait_list,cl_event * event);
extern cl_api_call_clEnqueueWriteBufferRect reallib_clEnqueueWriteBufferRect;
extern cl_int clEnqueueWriteBufferRect(cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_write, const size_t * buffer_origin, const size_t * host_origin, const size_t * region, size_t buffer_row_pitch, size_t buffer_slice_pitch, size_t host_row_pitch, size_t host_slice_pitch, const void * ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) ;

typedef cl_int (*cl_api_call_clEnqueueCopyBuffer) (cl_command_queue command_queue,cl_mem src_buffer,cl_mem dst_buffer,size_t src_offset,size_t dst_offset,size_t cb,cl_uint num_events_in_wait_list,const cl_event * event_wait_list,cl_event * event);
extern cl_api_call_clEnqueueCopyBuffer reallib_clEnqueueCopyBuffer;
extern cl_int clEnqueueCopyBuffer(cl_command_queue command_queue, cl_mem src_buffer, cl_mem dst_buffer, size_t src_offset, size_t dst_offset, size_t cb, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) ;

typedef cl_int (*cl_api_call_clEnqueueCopyBufferRect) (cl_command_queue command_queue,cl_mem src_buffer,cl_mem dst_buffer,const size_t * src_origin,const size_t * dst_origin,const size_t * region,size_t src_row_pitch,size_t src_slice_pitch,size_t dst_row_pitch,size_t dst_slice_pitch,cl_uint num_events_in_wait_list,const cl_event * event_wait_list,cl_event * event);
extern cl_api_call_clEnqueueCopyBufferRect reallib_clEnqueueCopyBufferRect;
extern cl_int clEnqueueCopyBufferRect(cl_command_queue command_queue, cl_mem src_buffer, cl_mem dst_buffer, const size_t * src_origin, const size_t * dst_origin, const size_t * region, size_t src_row_pitch, size_t src_slice_pitch, size_t dst_row_pitch, size_t dst_slice_pitch, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) ;

typedef cl_int (*cl_api_call_clEnqueueReadImage) (cl_command_queue command_queue,cl_mem image,cl_bool blocking_read,const size_t * origin[3],const size_t * region[3],size_t row_pitch,size_t slice_pitch,void * ptr,cl_uint num_events_in_wait_list,const cl_event * event_wait_list,cl_event * event);
extern cl_api_call_clEnqueueReadImage reallib_clEnqueueReadImage;
extern cl_int clEnqueueReadImage(cl_command_queue command_queue, cl_mem image, cl_bool blocking_read, const size_t * origin, const size_t * region, size_t row_pitch, size_t slice_pitch, void * ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) ;

typedef cl_int (*cl_api_call_clEnqueueWriteImage) (cl_command_queue command_queue,cl_mem image,cl_bool blocking_write,const size_t * origin[3],const size_t * region[3],size_t input_row_pitch,size_t input_slice_pitch,const void * ptr,cl_uint num_events_in_wait_list,const cl_event * event_wait_list,cl_event * event);
extern cl_api_call_clEnqueueWriteImage reallib_clEnqueueWriteImage;
extern cl_int clEnqueueWriteImage(cl_command_queue command_queue, cl_mem image, cl_bool blocking_write, const size_t * origin, const size_t * region, size_t input_row_pitch, size_t input_slice_pitch, const void * ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) ;

typedef cl_int (*cl_api_call_clEnqueueCopyImage) (cl_command_queue command_queue,cl_mem src_image,cl_mem dst_image,const size_t * src_origin[3],const size_t * dst_origin[3],const size_t * region[3],cl_uint num_events_in_wait_list,const cl_event * event_wait_list,cl_event * event);
extern cl_api_call_clEnqueueCopyImage reallib_clEnqueueCopyImage;
extern cl_int clEnqueueCopyImage(cl_command_queue command_queue, cl_mem src_image, cl_mem dst_image, const size_t * src_origin, const size_t * dst_origin, const size_t * region, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) ;

typedef cl_int (*cl_api_call_clEnqueueCopyImageToBuffer) (cl_command_queue command_queue,cl_mem src_image,cl_mem dst_buffer,const size_t * src_origin[3],const size_t * region[3],size_t dst_offset,cl_uint num_events_in_wait_list,const cl_event * event_wait_list,cl_event * event);
extern cl_api_call_clEnqueueCopyImageToBuffer reallib_clEnqueueCopyImageToBuffer;
extern cl_int clEnqueueCopyImageToBuffer(cl_command_queue command_queue, cl_mem src_image, cl_mem dst_buffer, const size_t * src_origin, const size_t * region, size_t dst_offset, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) ;

typedef cl_int (*cl_api_call_clEnqueueCopyBufferToImage) (cl_command_queue command_queue,cl_mem src_buffer,cl_mem dst_image,size_t src_offset,const size_t * dst_origin[3],const size_t * region[3],cl_uint num_events_in_wait_list,const cl_event * event_wait_list,cl_event * event);
extern cl_api_call_clEnqueueCopyBufferToImage reallib_clEnqueueCopyBufferToImage;
extern cl_int clEnqueueCopyBufferToImage(cl_command_queue command_queue, cl_mem src_buffer, cl_mem dst_image, size_t src_offset, const size_t * dst_origin, const size_t * region, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) ;

typedef void * (*cl_api_call_clEnqueueMapBuffer) (cl_command_queue command_queue,cl_mem buffer,cl_bool blocking_map,cl_map_flags map_flags,size_t offset,size_t cb,cl_uint num_events_in_wait_list,const cl_event * event_wait_list,cl_event * event,cl_int * errcode_ret);
extern cl_api_call_clEnqueueMapBuffer reallib_clEnqueueMapBuffer;
extern void * clEnqueueMapBuffer(cl_command_queue command_queue, cl_mem buffer, cl_bool blocking_map, cl_map_flags map_flags, size_t offset, size_t cb, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event, cl_int * errcode_ret) ;

typedef void * (*cl_api_call_clEnqueueMapImage) (cl_command_queue command_queue,cl_mem image,cl_bool blocking_map,cl_map_flags map_flags,const size_t * origin[3],const size_t * region[3],size_t * image_row_pitch,size_t * image_slice_pitch,cl_uint num_events_in_wait_list,const cl_event * event_wait_list,cl_event * event,cl_int * errcode_ret);
extern cl_api_call_clEnqueueMapImage reallib_clEnqueueMapImage;
extern void * clEnqueueMapImage(cl_command_queue command_queue, cl_mem image, cl_bool blocking_map, cl_map_flags map_flags, const size_t * origin, const size_t * region, size_t * image_row_pitch, size_t * image_slice_pitch, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event, cl_int * errcode_ret) ;

typedef cl_int (*cl_api_call_clEnqueueUnmapMemObject) (cl_command_queue command_queue,cl_mem memobj,void * mapped_ptr,cl_uint num_events_in_wait_list,const cl_event * event_wait_list,cl_event * event);
extern cl_api_call_clEnqueueUnmapMemObject reallib_clEnqueueUnmapMemObject;
extern cl_int clEnqueueUnmapMemObject(cl_command_queue command_queue, cl_mem memobj, void * mapped_ptr, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) ;

typedef cl_int (*cl_api_call_clEnqueueNDRangeKernel) (cl_command_queue command_queue,cl_kernel kernel,cl_uint work_dim,const size_t * global_work_offset,const size_t * global_work_size,const size_t * local_work_size,cl_uint num_events_in_wait_list,const cl_event * event_wait_list,cl_event * event);
extern cl_api_call_clEnqueueNDRangeKernel reallib_clEnqueueNDRangeKernel;
extern cl_int clEnqueueNDRangeKernel(cl_command_queue command_queue, cl_kernel kernel, cl_uint work_dim, const size_t * global_work_offset, const size_t * global_work_size, const size_t * local_work_size, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) ;

typedef cl_int (*cl_api_call_clEnqueueTask) (cl_command_queue command_queue,cl_kernel kernel,cl_uint num_events_in_wait_list,const cl_event * event_wait_list,cl_event * event);
extern cl_api_call_clEnqueueTask reallib_clEnqueueTask;
extern cl_int clEnqueueTask(cl_command_queue command_queue, cl_kernel kernel, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) ;

typedef cl_int (*cl_api_call_clEnqueueNativeKernel) (cl_command_queue command_queue,void (*user_func)(void *) ,void * args,size_t cb_args,cl_uint num_mem_objects,const cl_mem * mem_list,const void ** args_mem_loc,cl_uint num_events_in_wait_list,const cl_event * event_wait_list,cl_event * event);
extern cl_api_call_clEnqueueNativeKernel reallib_clEnqueueNativeKernel;
extern cl_int clEnqueueNativeKernel(cl_command_queue command_queue, void (*user_func)(void *) , void * args, size_t cb_args, cl_uint num_mem_objects, const cl_mem * mem_list, const void ** args_mem_loc, cl_uint num_events_in_wait_list, const cl_event * event_wait_list, cl_event * event) ;

typedef cl_int (*cl_api_call_clEnqueueMarker) (cl_command_queue command_queue,cl_event * event);
extern cl_api_call_clEnqueueMarker reallib_clEnqueueMarker;
extern cl_int clEnqueueMarker(cl_command_queue command_queue, cl_event * event) ;

typedef cl_int (*cl_api_call_clEnqueueWaitForEvents) (cl_command_queue command_queue,cl_uint num_events,const cl_event * event_list);
extern cl_api_call_clEnqueueWaitForEvents reallib_clEnqueueWaitForEvents;
extern cl_int clEnqueueWaitForEvents(cl_command_queue command_queue, cl_uint num_events, const cl_event * event_list) ;

typedef cl_int (*cl_api_call_clEnqueueBarrier) (cl_command_queue command_queue);
extern cl_api_call_clEnqueueBarrier reallib_clEnqueueBarrier;
extern cl_int clEnqueueBarrier(cl_command_queue command_queue) ;

typedef void * (*cl_api_call_clGetExtensionFunctionAddress) (const char * func_name);
extern cl_api_call_clGetExtensionFunctionAddress reallib_clGetExtensionFunctionAddress;
extern void * clGetExtensionFunctionAddress(const char * func_name) ;



#ifdef __cplusplus
}
#endif

#endif
