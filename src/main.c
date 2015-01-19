#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>

#define TRACEPOINT_DEFINE
#include "clust_tp.h"

int main(int argc, char **argv) {
	printf("hello\n");
	tracepoint(clust_provider, cl_function, "ALL RIGHT!!!",0);
	cl_platform_id ids;
	cl_int count;
	clGetPlatformIDs(0, &ids, &count);
}
