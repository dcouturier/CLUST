/*
 * clustfunctions.h
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

#ifndef CLUSTFUNCTIONS_H_
#define CLUSTFUNCTIONS_H_

#include <CL/cl.h>

void clustInit();
void clustContextCreated(cl_command_queue context);


#endif /* CLUSTFUNCTIONS_H_ */
