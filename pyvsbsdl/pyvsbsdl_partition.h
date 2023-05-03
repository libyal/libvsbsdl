/*
 * Python object wrapper of libvsbsdl_partition_t
 *
 * Copyright (C) 2023, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#if !defined( _PYVSBSDL_PARTITION_H )
#define _PYVSBSDL_PARTITION_H

#include <common.h>
#include <types.h>

#include "pyvsbsdl_libvsbsdl.h"
#include "pyvsbsdl_python.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct pyvsbsdl_partition pyvsbsdl_partition_t;

struct pyvsbsdl_partition
{
	/* Python object initialization
	 */
	PyObject_HEAD

	/* The libvsbsdl partition
	 */
	libvsbsdl_partition_t *partition;

	/* The parent object
	 */
	PyObject *parent_object;
};

extern PyMethodDef pyvsbsdl_partition_object_methods[];
extern PyTypeObject pyvsbsdl_partition_type_object;

PyObject *pyvsbsdl_partition_new(
           libvsbsdl_partition_t *partition,
           PyObject *parent_object );

int pyvsbsdl_partition_init(
     pyvsbsdl_partition_t *pyvsbsdl_partition );

void pyvsbsdl_partition_free(
      pyvsbsdl_partition_t *pyvsbsdl_partition );

PyObject *pyvsbsdl_partition_get_entry_index(
           pyvsbsdl_partition_t *pyvsbsdl_partition,
           PyObject *arguments );

PyObject *pyvsbsdl_partition_get_name_string(
           pyvsbsdl_partition_t *pyvsbsdl_partition,
           PyObject *arguments );

PyObject *pyvsbsdl_partition_get_volume_offset(
           pyvsbsdl_partition_t *pyvsbsdl_partition,
           PyObject *arguments );

PyObject *pyvsbsdl_partition_read_buffer(
           pyvsbsdl_partition_t *pyvsbsdl_partition,
           PyObject *arguments,
           PyObject *keywords );

PyObject *pyvsbsdl_partition_read_buffer_at_offset(
           pyvsbsdl_partition_t *pyvsbsdl_partition,
           PyObject *arguments,
           PyObject *keywords );

PyObject *pyvsbsdl_partition_seek_offset(
           pyvsbsdl_partition_t *pyvsbsdl_partition,
           PyObject *arguments,
           PyObject *keywords );

PyObject *pyvsbsdl_partition_get_offset(
           pyvsbsdl_partition_t *pyvsbsdl_partition,
           PyObject *arguments );

PyObject *pyvsbsdl_partition_get_size(
           pyvsbsdl_partition_t *pyvsbsdl_partition,
           PyObject *arguments );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _PYVSBSDL_PARTITION_H ) */

