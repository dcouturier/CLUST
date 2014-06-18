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
int var = 0;

__attribute__((constructor)) void libCLUST() {
	printf("hello lib!\n");
	init_libcl_symbols();
}

static void init_libcl_symbols() {
	void* libcl_ptr;

	dlerror();
	libcl_ptr = dlopen(LIBCL_NAME, RTLD_LAZY);

	if(!libcl_ptr) {
		fprintf(stderr, "%s: Unable to load %s", LIB_NAME, LIBCL_NAME);
		exit(EXIT_FAILURE);
	}

	dlerror();
	*(void**)(&libCL_clGetDeviceIDs) = dlsym(libcl_ptr, LIBCL_GET_DEVICE_IDS_STR);
	if(!libCL_clGetDeviceIDs) {
		fprintf(stderr, "%s: Unable to load %s", LIB_NAME, LIBCL_GET_DEVICE_IDS_STR);
		exit(EXIT_FAILURE);
	}

	//	arbitrary libCL_clGetDeviceIDs;
	//	*(void**)(&libCL_clGetDeviceIDs) = dlsym(libcl_ptr, LIBCL_GET_DEVICE_IDS_STR);
	//	libCL_clGetDeviceIDs();
#ifdef DEBUG
	fprintf(stdout, "symbols initialized!\n");
#endif
}

void doStuff() {
	printf("doing stuff!\n");
}
