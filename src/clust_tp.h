#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER clust_provider

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./clust_tp.h"

#if !defined(_CLUST_TP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _CLUST_TP_H

#include <lttng/tracepoint.h>

TRACEPOINT_EVENT(
		clust_provider,
		cl_function,
    TP_ARGS(
        char*, my_string_arg
    ),
    TP_FIELDS(
        ctf_string(my_string_field, my_string_arg)
    )
)

#endif /* _CLUST_TP_H */

#include <lttng/tracepoint-event.h>
