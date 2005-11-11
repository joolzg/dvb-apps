/*
 * section and descriptor parser
 *
 * Copyright (C) 2005 Kenneth Aafloy (kenneth@linuxtv.org)
 * Copyright (C) 2005 Andrew de Quincey (adq_dvb@lidskialf.net)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#ifndef _UCSI_DVB_NETWORK_NAME_DESCRIPTOR
#define _UCSI_DVB_NETWORK_NAME_DESCRIPTOR 1

#include <ucsi/descriptor.h>
#include <ucsi/endianops.h>

/**
 * dvb_network_name_descriptor structure.
 */
struct dvb_network_name_descriptor {
	struct descriptor d;

	/* char name[] */
} packed;

/**
 * Process a dvb_network_name_descriptor.
 *
 * @param d Generic descriptor pointer.
 * @return dvb_network_name_descriptor pointer, or NULL on error.
 */
static inline struct dvb_network_name_descriptor*
	dvb_network_name_descriptor_codec(struct descriptor* d)
{
	return (struct dvb_network_name_descriptor*) d;
}

/**
 * Accessor for the name field in a dvb_network_name_descriptor.
 *
 * @param d dvb_network_name_descriptor pointer.
 * @return Pointer to the field.
 */
static inline uint8_t *
	dvb_network_name_descriptor_name(struct dvb_network_name_descriptor *d)
{
	return (uint8_t *) d + sizeof(struct dvb_network_name_descriptor);
}

/**
 * Calculate the length of the name field in a dvb_network_name_descriptor.
 *
 * @param d dvb_network_name_descriptor pointer.
 * @return Length of the field in bytes.
 */
static inline int
	dvb_network_name_descriptor_name_length(struct dvb_network_name_descriptor *d)
{
	return d->d.len;
}

#endif