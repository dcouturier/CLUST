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
        int, api_call_id_arg, int, start_arg
    ),
    TP_FIELDS(
    	ctf_integer(unsigned char, api_call_id_field, api_call_id_arg)
        ctf_integer(bool, boolfield, start_arg)
    )
)

TRACEPOINT_EVENT(
		clust_provider,
		clust_device_event,
    TP_ARGS(
        ulong, queue_arg, int, command_arg, ulong, start_arg, ulong, end_arg
    ),
    TP_FIELDS(
            ctf_integer(ulong, queue_field, queue_arg)
            ctf_integer(int, command_field, command_arg)
            ctf_integer(ulong, start_field, start_arg)
            ctf_integer(ulong, end_field, end_arg)
    )
)

#endif /* _CLUST_TP_H */

#include <lttng/tracepoint-event.h>
