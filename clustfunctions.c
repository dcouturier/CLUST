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

#if ENABLE_AMD_GPU_PERF_API == 1
#include <GPUPerfAPI.h>
#include <GPUPerfAPIFunctionTypes.h>
#endif

void* lib = NULL;
void clustInit() {
#if ENABLE_AMD_GPU_PERF_API == 1
	//GPA_Status ret = GPA_Initialize();
//	if(ret != GPA_STATUS_OK) {
//		fprintf(stderr, "%s: Error initializing GPUPerfAPI\n", LIB_NAME);
//		exit(EXIT_FAILURE);
//	}

	lib = dlopen("libGPUPerfAPICL.so", RTLD_LAZY);
	if(!lib) {
			fprintf(stderr, "%s: Unable to load %s\n", "libGPUPerfAPICL.so", LIBCL_NAME);
			exit(EXIT_FAILURE);
	}
	GPA_InitializePtrType initz = dlsym(lib, "GPA_Initialize");

	initz();

#endif
}

void clustContextCreated(cl_context context) {
#if ENABLE_AMD_GPU_PERF_API == 1
	fprintf(stdout, "Context = %p\n", context);
	fflush(stdout);

		GPA_InitializePtrType initz = dlsym(lib, "GPA_OpenContext");
		initz(context);
		fprintf(stdout, "ssss = %p\n", context);
		fflush(stdout);
//	GPA_Status ret = GPA_OpenContext(&context);
//	if(ret != GPA_STATUS_OK) {
//		fprintf(stdout, "PATATE\n");
//	}
	/*
	gpa_uint32 count = 0;

	fprintf(stdout, "Context = %p\n", context);
	fflush(stdout);
	//GPA_GetNumCounters(&count);
	fprintf(stdout, "Count = %d\n", count);*/
#endif
}
