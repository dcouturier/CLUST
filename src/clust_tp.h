#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER clust_provider

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./clust_tp.h"

#if !defined(_CLUST_TP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _CLUST_TP_H

#include <lttng/tracepoint.h>
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetPlatformIDs,

	TP_ARGS(
		cl_uint, num_entries,
		cl_platform_id *, platforms,
		cl_uint *, num_platforms
	),
	TP_FIELDS(
		ctf_integer(cl_uint, num_entries_field, num_entries)
		ctf_integer(cl_platform_id *, platforms_field, platforms)
		ctf_integer(cl_uint *, num_platforms_field, num_platforms)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetPlatformInfo,

	TP_ARGS(
		cl_platform_id, platform,
		cl_platform_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_platform_id, platform_field, platform)
		ctf_integer(cl_platform_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetDeviceIDs,

	TP_ARGS(
		cl_platform_id, platform,
		cl_device_type, device_type,
		cl_uint, num_entries,
		cl_device_id *, devices,
		cl_uint *, num_devices
	),
	TP_FIELDS(
		ctf_integer(cl_platform_id, platform_field, platform)
		ctf_integer(cl_device_type, device_type_field, device_type)
		ctf_integer(cl_uint, num_entries_field, num_entries)
		ctf_integer(cl_device_id *, devices_field, devices)
		ctf_integer(cl_uint *, num_devices_field, num_devices)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetDeviceInfo,

	TP_ARGS(
		cl_device_id, device,
		cl_device_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_device_id, device_field, device)
		ctf_integer(cl_device_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreateContext,

	TP_ARGS(
		const cl_context_properties *, properties,
		cl_uint, num_devices,
		const cl_device_id *, devices,
		void *, pfn_notify,
		void *, param_4,
		cl_int *, user_data
	),
	TP_FIELDS(
		ctf_integer(const cl_context_properties *, properties_field, properties)
		ctf_integer(cl_uint, num_devices_field, num_devices)
		ctf_integer(const cl_device_id *, devices_field, devices)
		ctf_integer(void *, pfn_notify_field, pfn_notify)
		ctf_integer(void *, param_4_field, param_4)
		ctf_integer(cl_int *, user_data_field, user_data)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreateContextFromType,

	TP_ARGS(
		const cl_context_properties *, properties,
		cl_device_type, device_type,
		void *, pfn_notify,
		void *, param_3,
		cl_int *, user_data
	),
	TP_FIELDS(
		ctf_integer(const cl_context_properties *, properties_field, properties)
		ctf_integer(cl_device_type, device_type_field, device_type)
		ctf_integer(void *, pfn_notify_field, pfn_notify)
		ctf_integer(void *, param_3_field, param_3)
		ctf_integer(cl_int *, user_data_field, user_data)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clRetainContext,

	TP_ARGS(
		cl_context, context
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clReleaseContext,

	TP_ARGS(
		cl_context, context
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetContextInfo,

	TP_ARGS(
		cl_context, context,
		cl_context_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
		ctf_integer(cl_context_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreateCommandQueue,

	TP_ARGS(
		cl_context, context,
		cl_device_id, device,
		cl_command_queue_properties, properties,
		cl_int *, errcode_ret
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
		ctf_integer(cl_device_id, device_field, device)
		ctf_integer(cl_command_queue_properties, properties_field, properties)
		ctf_integer(cl_int *, errcode_ret_field, errcode_ret)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clRetainCommandQueue,

	TP_ARGS(
		cl_command_queue, command_queue
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clReleaseCommandQueue,

	TP_ARGS(
		cl_command_queue, command_queue
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetCommandQueueInfo,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_command_queue_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_command_queue_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreateBuffer,

	TP_ARGS(
		cl_context, context,
		cl_mem_flags, flags,
		size_t, size,
		void *, host_ptr,
		cl_int *, errcode_ret
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
		ctf_integer(cl_mem_flags, flags_field, flags)
		ctf_integer(size_t, size_field, size)
		ctf_integer(void *, host_ptr_field, host_ptr)
		ctf_integer(cl_int *, errcode_ret_field, errcode_ret)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreateSubBuffer,

	TP_ARGS(
		cl_mem, buffer,
		cl_mem_flags, flags,
		cl_buffer_create_type, buffer_create_type,
		const void *, buffer_create_info,
		cl_int *, errcode_ret
	),
	TP_FIELDS(
		ctf_integer(cl_mem, buffer_field, buffer)
		ctf_integer(cl_mem_flags, flags_field, flags)
		ctf_integer(cl_buffer_create_type, buffer_create_type_field, buffer_create_type)
		ctf_integer(const void *, buffer_create_info_field, buffer_create_info)
		ctf_integer(cl_int *, errcode_ret_field, errcode_ret)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreateImage2D,

	TP_ARGS(
		cl_context, context,
		cl_mem_flags, flags,
		const cl_image_format *, image_format,
		size_t, image_width,
		size_t, image_height,
		size_t, image_row_pitch,
		void *, host_ptr,
		cl_int *, errcode_ret
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
		ctf_integer(cl_mem_flags, flags_field, flags)
		ctf_integer(const cl_image_format *, image_format_field, image_format)
		ctf_integer(size_t, image_width_field, image_width)
		ctf_integer(size_t, image_height_field, image_height)
		ctf_integer(size_t, image_row_pitch_field, image_row_pitch)
		ctf_integer(void *, host_ptr_field, host_ptr)
		ctf_integer(cl_int *, errcode_ret_field, errcode_ret)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreateImage3D,

	TP_ARGS(
		cl_context, context,
		cl_mem_flags, flags,
		const cl_image_format *, image_format,
		size_t, image_width,
		size_t, image_height,
		size_t, image_depth,
		size_t, image_row_pitch,
		size_t, image_slice_pitch,
		void *, host_ptr,
		cl_int *, errcode_ret
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
		ctf_integer(cl_mem_flags, flags_field, flags)
		ctf_integer(const cl_image_format *, image_format_field, image_format)
		ctf_integer(size_t, image_width_field, image_width)
		ctf_integer(size_t, image_height_field, image_height)
		ctf_integer(size_t, image_depth_field, image_depth)
		ctf_integer(size_t, image_row_pitch_field, image_row_pitch)
		ctf_integer(size_t, image_slice_pitch_field, image_slice_pitch)
		ctf_integer(void *, host_ptr_field, host_ptr)
		ctf_integer(cl_int *, errcode_ret_field, errcode_ret)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clRetainMemObject,

	TP_ARGS(
		cl_mem, memobj
	),
	TP_FIELDS(
		ctf_integer(cl_mem, memobj_field, memobj)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clReleaseMemObject,

	TP_ARGS(
		cl_mem, memobj
	),
	TP_FIELDS(
		ctf_integer(cl_mem, memobj_field, memobj)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetSupportedImageFormats,

	TP_ARGS(
		cl_context, context,
		cl_mem_flags, flags,
		cl_mem_object_type, image_type,
		cl_uint, num_entries,
		cl_image_format *, image_formats,
		cl_uint *, num_image_formats
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
		ctf_integer(cl_mem_flags, flags_field, flags)
		ctf_integer(cl_mem_object_type, image_type_field, image_type)
		ctf_integer(cl_uint, num_entries_field, num_entries)
		ctf_integer(cl_image_format *, image_formats_field, image_formats)
		ctf_integer(cl_uint *, num_image_formats_field, num_image_formats)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetMemObjectInfo,

	TP_ARGS(
		cl_mem, memobj,
		cl_mem_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_mem, memobj_field, memobj)
		ctf_integer(cl_mem_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetImageInfo,

	TP_ARGS(
		cl_mem, image,
		cl_image_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_mem, image_field, image)
		ctf_integer(cl_image_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clSetMemObjectDestructorCallback,

	TP_ARGS(
		cl_mem, memobj,
		void *, pfn_notify,
		void *, user_data
	),
	TP_FIELDS(
		ctf_integer(cl_mem, memobj_field, memobj)
		ctf_integer(void *, pfn_notify_field, pfn_notify)
		ctf_integer(void *, user_data_field, user_data)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreateSampler,

	TP_ARGS(
		cl_context, context,
		cl_bool, normalized_coords,
		cl_addressing_mode, addressing_mode,
		cl_filter_mode, filter_mode,
		cl_int *, errcode_ret
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
		ctf_integer(cl_bool, normalized_coords_field, normalized_coords)
		ctf_integer(cl_addressing_mode, addressing_mode_field, addressing_mode)
		ctf_integer(cl_filter_mode, filter_mode_field, filter_mode)
		ctf_integer(cl_int *, errcode_ret_field, errcode_ret)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clRetainSampler,

	TP_ARGS(
		cl_sampler, sampler
	),
	TP_FIELDS(
		ctf_integer(cl_sampler, sampler_field, sampler)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clReleaseSampler,

	TP_ARGS(
		cl_sampler, sampler
	),
	TP_FIELDS(
		ctf_integer(cl_sampler, sampler_field, sampler)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetSamplerInfo,

	TP_ARGS(
		cl_sampler, sampler,
		cl_sampler_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_sampler, sampler_field, sampler)
		ctf_integer(cl_sampler_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreateProgramWithSource,

	TP_ARGS(
		cl_context, context,
		cl_uint, count,
		const char **, strings,
		const size_t *, lengths,
		cl_int *, errcode_ret
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
		ctf_integer(cl_uint, count_field, count)
		ctf_integer(const char **, strings_field, strings)
		ctf_integer(const size_t *, lengths_field, lengths)
		ctf_integer(cl_int *, errcode_ret_field, errcode_ret)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreateProgramWithBinary,

	TP_ARGS(
		cl_context, context,
		cl_uint, num_devices,
		const cl_device_id *, device_list,
		const size_t *, lengths,
		const unsigned char **, binaries,
		cl_int *, binary_status,
		cl_int *, errcode_ret
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
		ctf_integer(cl_uint, num_devices_field, num_devices)
		ctf_integer(const cl_device_id *, device_list_field, device_list)
		ctf_integer(const size_t *, lengths_field, lengths)
		ctf_integer(const unsigned char **, binaries_field, binaries)
		ctf_integer(cl_int *, binary_status_field, binary_status)
		ctf_integer(cl_int *, errcode_ret_field, errcode_ret)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clRetainProgram,

	TP_ARGS(
		cl_program, program
	),
	TP_FIELDS(
		ctf_integer(cl_program, program_field, program)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clReleaseProgram,

	TP_ARGS(
		cl_program, program
	),
	TP_FIELDS(
		ctf_integer(cl_program, program_field, program)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clBuildProgram,

	TP_ARGS(
		cl_program, program,
		cl_uint, num_devices,
		const cl_device_id *, device_list,
		const char *, options,
		void *, pfn_notify,
		void *, user_data
	),
	TP_FIELDS(
		ctf_integer(cl_program, program_field, program)
		ctf_integer(cl_uint, num_devices_field, num_devices)
		ctf_integer(const cl_device_id *, device_list_field, device_list)
		ctf_integer(const char *, options_field, options)
		ctf_integer(void *, pfn_notify_field, pfn_notify)
		ctf_integer(void *, user_data_field, user_data)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clUnloadCompiler,

	TP_ARGS(
	),
	TP_FIELDS(
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetProgramInfo,

	TP_ARGS(
		cl_program, program,
		cl_program_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_program, program_field, program)
		ctf_integer(cl_program_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetProgramBuildInfo,

	TP_ARGS(
		cl_program, program,
		cl_device_id, device,
		cl_program_build_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_program, program_field, program)
		ctf_integer(cl_device_id, device_field, device)
		ctf_integer(cl_program_build_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreateKernel,

	TP_ARGS(
		cl_program, program,
		const char *, kernel_name,
		cl_int *, errcode_ret
	),
	TP_FIELDS(
		ctf_integer(cl_program, program_field, program)
		ctf_integer(const char *, kernel_name_field, kernel_name)
		ctf_integer(cl_int *, errcode_ret_field, errcode_ret)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreateKernelsInProgram,

	TP_ARGS(
		cl_program, program,
		cl_uint, num_kernels,
		cl_kernel *, kernels,
		cl_uint *, num_kernels_ret
	),
	TP_FIELDS(
		ctf_integer(cl_program, program_field, program)
		ctf_integer(cl_uint, num_kernels_field, num_kernels)
		ctf_integer(cl_kernel *, kernels_field, kernels)
		ctf_integer(cl_uint *, num_kernels_ret_field, num_kernels_ret)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clRetainKernel,

	TP_ARGS(
		cl_kernel, kernel
	),
	TP_FIELDS(
		ctf_integer(cl_kernel, kernel_field, kernel)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clReleaseKernel,

	TP_ARGS(
		cl_kernel, kernel
	),
	TP_FIELDS(
		ctf_integer(cl_kernel, kernel_field, kernel)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clSetKernelArg,

	TP_ARGS(
		cl_kernel, kernel,
		cl_uint, arg_index,
		size_t, arg_size,
		const void *, arg_value
	),
	TP_FIELDS(
		ctf_integer(cl_kernel, kernel_field, kernel)
		ctf_integer(cl_uint, arg_index_field, arg_index)
		ctf_integer(size_t, arg_size_field, arg_size)
		ctf_integer(const void *, arg_value_field, arg_value)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetKernelInfo,

	TP_ARGS(
		cl_kernel, kernel,
		cl_kernel_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_kernel, kernel_field, kernel)
		ctf_integer(cl_kernel_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetKernelWorkGroupInfo,

	TP_ARGS(
		cl_kernel, kernel,
		cl_device_id, device,
		cl_kernel_work_group_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_kernel, kernel_field, kernel)
		ctf_integer(cl_device_id, device_field, device)
		ctf_integer(cl_kernel_work_group_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clWaitForEvents,

	TP_ARGS(
		cl_uint, num_events,
		const cl_event *, event_list
	),
	TP_FIELDS(
		ctf_integer(cl_uint, num_events_field, num_events)
		ctf_integer(const cl_event *, event_list_field, event_list)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetEventInfo,

	TP_ARGS(
		cl_event, event,
		cl_event_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_event, event_field, event)
		ctf_integer(cl_event_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clCreateUserEvent,

	TP_ARGS(
		cl_context, context,
		cl_int *, errcode_ret
	),
	TP_FIELDS(
		ctf_integer(cl_context, context_field, context)
		ctf_integer(cl_int *, errcode_ret_field, errcode_ret)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clRetainEvent,

	TP_ARGS(
		cl_event, event
	),
	TP_FIELDS(
		ctf_integer(cl_event, event_field, event)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clReleaseEvent,

	TP_ARGS(
		cl_event, event
	),
	TP_FIELDS(
		ctf_integer(cl_event, event_field, event)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clSetUserEventStatus,

	TP_ARGS(
		cl_event, event,
		cl_int, execution_status
	),
	TP_FIELDS(
		ctf_integer(cl_event, event_field, event)
		ctf_integer(cl_int, execution_status_field, execution_status)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clSetEventCallback,

	TP_ARGS(
		cl_event, event,
		cl_int, command_exec_callback_type,
		void *, pfn_notify,
		void *, user_data
	),
	TP_FIELDS(
		ctf_integer(cl_event, event_field, event)
		ctf_integer(cl_int, command_exec_callback_type_field, command_exec_callback_type)
		ctf_integer(void *, pfn_notify_field, pfn_notify)
		ctf_integer(void *, user_data_field, user_data)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetEventProfilingInfo,

	TP_ARGS(
		cl_event, event,
		cl_profiling_info, param_name,
		size_t, param_value_size,
		void *, param_value,
		size_t *, param_value_size_ret
	),
	TP_FIELDS(
		ctf_integer(cl_event, event_field, event)
		ctf_integer(cl_profiling_info, param_name_field, param_name)
		ctf_integer(size_t, param_value_size_field, param_value_size)
		ctf_integer(void *, param_value_field, param_value)
		ctf_integer(size_t *, param_value_size_ret_field, param_value_size_ret)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clFlush,

	TP_ARGS(
		cl_command_queue, command_queue
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clFinish,

	TP_ARGS(
		cl_command_queue, command_queue
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueReadBuffer,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, buffer,
		cl_bool, blocking_read,
		size_t, offset,
		size_t, cb,
		void *, ptr,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, buffer_field, buffer)
		ctf_integer(cl_bool, blocking_read_field, blocking_read)
		ctf_integer(size_t, offset_field, offset)
		ctf_integer(size_t, cb_field, cb)
		ctf_integer(void *, ptr_field, ptr)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueReadBufferRect,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, buffer,
		cl_bool, blocking_read,
		const size_t *, buffer_origin,
		const size_t *, host_origin,
		const size_t *, region,
		size_t, buffer_row_pitch,
		size_t, buffer_slice_pitch,
		size_t, host_row_pitch,
		size_t, host_slice_pitch,
		void *, ptr,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, buffer_field, buffer)
		ctf_integer(cl_bool, blocking_read_field, blocking_read)
		ctf_integer(const size_t *, buffer_origin_field, buffer_origin)
		ctf_integer(const size_t *, host_origin_field, host_origin)
		ctf_integer(const size_t *, region_field, region)
		ctf_integer(size_t, buffer_row_pitch_field, buffer_row_pitch)
		ctf_integer(size_t, buffer_slice_pitch_field, buffer_slice_pitch)
		ctf_integer(size_t, host_row_pitch_field, host_row_pitch)
		ctf_integer(size_t, host_slice_pitch_field, host_slice_pitch)
		ctf_integer(void *, ptr_field, ptr)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueWriteBuffer,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, buffer,
		cl_bool, blocking_write,
		size_t, offset,
		size_t, cb,
		const void *, ptr,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, buffer_field, buffer)
		ctf_integer(cl_bool, blocking_write_field, blocking_write)
		ctf_integer(size_t, offset_field, offset)
		ctf_integer(size_t, cb_field, cb)
		ctf_integer(const void *, ptr_field, ptr)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueWriteBufferRect,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, buffer,
		cl_bool, blocking_write,
		const size_t *, buffer_origin,
		const size_t *, host_origin,
		const size_t *, region,
		size_t, buffer_row_pitch,
		size_t, buffer_slice_pitch,
		size_t, host_row_pitch,
		size_t, host_slice_pitch,
		const void *, ptr,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, buffer_field, buffer)
		ctf_integer(cl_bool, blocking_write_field, blocking_write)
		ctf_integer(const size_t *, buffer_origin_field, buffer_origin)
		ctf_integer(const size_t *, host_origin_field, host_origin)
		ctf_integer(const size_t *, region_field, region)
		ctf_integer(size_t, buffer_row_pitch_field, buffer_row_pitch)
		ctf_integer(size_t, buffer_slice_pitch_field, buffer_slice_pitch)
		ctf_integer(size_t, host_row_pitch_field, host_row_pitch)
		ctf_integer(size_t, host_slice_pitch_field, host_slice_pitch)
		ctf_integer(const void *, ptr_field, ptr)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueCopyBuffer,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, src_buffer,
		cl_mem, dst_buffer,
		size_t, src_offset,
		size_t, dst_offset,
		size_t, cb,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, src_buffer_field, src_buffer)
		ctf_integer(cl_mem, dst_buffer_field, dst_buffer)
		ctf_integer(size_t, src_offset_field, src_offset)
		ctf_integer(size_t, dst_offset_field, dst_offset)
		ctf_integer(size_t, cb_field, cb)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueCopyBufferRect,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, src_buffer,
		cl_mem, dst_buffer,
		const size_t *, src_origin,
		const size_t *, dst_origin,
		const size_t *, region,
		size_t, src_row_pitch,
		size_t, src_slice_pitch,
		size_t, dst_row_pitch,
		size_t, dst_slice_pitch,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, src_buffer_field, src_buffer)
		ctf_integer(cl_mem, dst_buffer_field, dst_buffer)
		ctf_integer(const size_t *, src_origin_field, src_origin)
		ctf_integer(const size_t *, dst_origin_field, dst_origin)
		ctf_integer(const size_t *, region_field, region)
		ctf_integer(size_t, src_row_pitch_field, src_row_pitch)
		ctf_integer(size_t, src_slice_pitch_field, src_slice_pitch)
		ctf_integer(size_t, dst_row_pitch_field, dst_row_pitch)
		ctf_integer(size_t, dst_slice_pitch_field, dst_slice_pitch)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueReadImage,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, image,
		cl_bool, blocking_read,
		const size_t *, origin,
		const size_t *, region,
		size_t, row_pitch,
		size_t, slice_pitch,
		void *, ptr,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, image_field, image)
		ctf_integer(cl_bool, blocking_read_field, blocking_read)
		ctf_integer(const size_t *, origin_field, origin)
		ctf_integer(const size_t *, region_field, region)
		ctf_integer(size_t, row_pitch_field, row_pitch)
		ctf_integer(size_t, slice_pitch_field, slice_pitch)
		ctf_integer(void *, ptr_field, ptr)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueWriteImage,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, image,
		cl_bool, blocking_write,
		const size_t *, origin,
		const size_t *, region,
		size_t, input_row_pitch,
		size_t, input_slice_pitch,
		const void *, ptr,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, image_field, image)
		ctf_integer(cl_bool, blocking_write_field, blocking_write)
		ctf_integer(const size_t *, origin_field, origin)
		ctf_integer(const size_t *, region_field, region)
		ctf_integer(size_t, input_row_pitch_field, input_row_pitch)
		ctf_integer(size_t, input_slice_pitch_field, input_slice_pitch)
		ctf_integer(const void *, ptr_field, ptr)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueCopyImage,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, src_image,
		cl_mem, dst_image,
		const size_t *, src_origin,
		const size_t *, dst_origin,
		const size_t *, region,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, src_image_field, src_image)
		ctf_integer(cl_mem, dst_image_field, dst_image)
		ctf_integer(const size_t *, src_origin_field, src_origin)
		ctf_integer(const size_t *, dst_origin_field, dst_origin)
		ctf_integer(const size_t *, region_field, region)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueCopyImageToBuffer,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, src_image,
		cl_mem, dst_buffer,
		const size_t *, src_origin,
		const size_t *, region,
		size_t, dst_offset,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, src_image_field, src_image)
		ctf_integer(cl_mem, dst_buffer_field, dst_buffer)
		ctf_integer(const size_t *, src_origin_field, src_origin)
		ctf_integer(const size_t *, region_field, region)
		ctf_integer(size_t, dst_offset_field, dst_offset)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueCopyBufferToImage,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, src_buffer,
		cl_mem, dst_image,
		size_t, src_offset,
		const size_t *, dst_origin,
		const size_t *, region,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, src_buffer_field, src_buffer)
		ctf_integer(cl_mem, dst_image_field, dst_image)
		ctf_integer(size_t, src_offset_field, src_offset)
		ctf_integer(const size_t *, dst_origin_field, dst_origin)
		ctf_integer(const size_t *, region_field, region)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueMapBuffer,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, buffer,
		cl_bool, blocking_map,
		cl_map_flags, map_flags,
		size_t, offset,
		size_t, cb,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event,
		cl_int *, errcode_ret
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, buffer_field, buffer)
		ctf_integer(cl_bool, blocking_map_field, blocking_map)
		ctf_integer(cl_map_flags, map_flags_field, map_flags)
		ctf_integer(size_t, offset_field, offset)
		ctf_integer(size_t, cb_field, cb)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
		ctf_integer(cl_int *, errcode_ret_field, errcode_ret)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueMapImage,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, image,
		cl_bool, blocking_map,
		cl_map_flags, map_flags,
		const size_t *, origin,
		const size_t *, region,
		size_t *, image_row_pitch,
		size_t *, image_slice_pitch,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event,
		cl_int *, errcode_ret
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, image_field, image)
		ctf_integer(cl_bool, blocking_map_field, blocking_map)
		ctf_integer(cl_map_flags, map_flags_field, map_flags)
		ctf_integer(const size_t *, origin_field, origin)
		ctf_integer(const size_t *, region_field, region)
		ctf_integer(size_t *, image_row_pitch_field, image_row_pitch)
		ctf_integer(size_t *, image_slice_pitch_field, image_slice_pitch)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
		ctf_integer(cl_int *, errcode_ret_field, errcode_ret)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueUnmapMemObject,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_mem, memobj,
		void *, mapped_ptr,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_mem, memobj_field, memobj)
		ctf_integer(void *, mapped_ptr_field, mapped_ptr)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueNDRangeKernel,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_kernel, kernel,
		cl_uint, work_dim,
		const size_t *, global_work_offset,
		const size_t *, global_work_size,
		const size_t *, local_work_size,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_kernel, kernel_field, kernel)
		ctf_integer(cl_uint, work_dim_field, work_dim)
		ctf_integer(const size_t *, global_work_offset_field, global_work_offset)
		ctf_integer(const size_t *, global_work_size_field, global_work_size)
		ctf_integer(const size_t *, local_work_size_field, local_work_size)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueTask,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_kernel, kernel,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_kernel, kernel_field, kernel)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueNativeKernel,

	TP_ARGS(
		cl_command_queue, command_queue,
		void (*user_func)(void *), user_func,
		void *, args,
		size_t, cb_args,
		cl_uint, num_mem_objects,
		const cl_mem *, mem_list,
		const void **, args_mem_loc,
		cl_uint, num_events_in_wait_list,
		const cl_event *, event_wait_list,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(void (*user_func)(void *), user_func_field, user_func)
		ctf_integer(void *, args_field, args)
		ctf_integer(size_t, cb_args_field, cb_args)
		ctf_integer(cl_uint, num_mem_objects_field, num_mem_objects)
		ctf_integer(const cl_mem *, mem_list_field, mem_list)
		ctf_integer(const void **, args_mem_loc_field, args_mem_loc)
		ctf_integer(cl_uint, num_events_in_wait_list_field, num_events_in_wait_list)
		ctf_integer(const cl_event *, event_wait_list_field, event_wait_list)
		ctf_integer(cl_event *, event_field, event)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueMarker,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_event *, event
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_event *, event_field, event)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueWaitForEvents,

	TP_ARGS(
		cl_command_queue, command_queue,
		cl_uint, num_events,
		const cl_event *, event_list
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
		ctf_integer(cl_uint, num_events_field, num_events)
		ctf_integer(const cl_event *, event_list_field, event_list)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clEnqueueBarrier,

	TP_ARGS(
		cl_command_queue, command_queue
	),
	TP_FIELDS(
		ctf_integer(cl_command_queue, command_queue_field, command_queue)
	)
)
TRACEPOINT_EVENT(
	/* tracepoint provider name */
	clust_provider,

	/* tracepoint/event name */
	clust_clGetExtensionFunctionAddress,

	TP_ARGS(
		const char *, func_name
	),
	TP_FIELDS(
		ctf_integer(const char *, func_name_field, func_name)
	)
)
#endif /* _CLUST_TP_H */

#include <lttng/tracepoint-event.h>
