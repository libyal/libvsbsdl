/*
 * Python object wrapper of libvsbsdl_volume_t
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

#if !defined( _PYVSBSDL_VOLUME_H )
#define _PYVSBSDL_VOLUME_H

#include <common.h>
#include <types.h>

#include "pyvsbsdl_libbfio.h"
#include "pyvsbsdl_libvsbsdl.h"
#include "pyvsbsdl_python.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct pyvsbsdl_volume pyvsbsdl_volume_t;

struct pyvsbsdl_volume
{
	/* Python object initialization
	 */
	PyObject_HEAD

	/* The libvsbsdl volume
	 */
	libvsbsdl_volume_t *volume;

	/* The libbfio file IO handle
	 */
	libbfio_handle_t *file_io_handle;
};

extern PyMethodDef pyvsbsdl_volume_object_methods[];
extern PyTypeObject pyvsbsdl_volume_type_object;

int pyvsbsdl_volume_init(
     pyvsbsdl_volume_t *pyvsbsdl_volume );

void pyvsbsdl_volume_free(
      pyvsbsdl_volume_t *pyvsbsdl_volume );

PyObject *pyvsbsdl_volume_signal_abort(
           pyvsbsdl_volume_t *pyvsbsdl_volume,
           PyObject *arguments );

PyObject *pyvsbsdl_volume_open(
           pyvsbsdl_volume_t *pyvsbsdl_volume,
           PyObject *arguments,
           PyObject *keywords );

PyObject *pyvsbsdl_volume_open_file_object(
           pyvsbsdl_volume_t *pyvsbsdl_volume,
           PyObject *arguments,
           PyObject *keywords );

PyObject *pyvsbsdl_volume_close(
           pyvsbsdl_volume_t *pyvsbsdl_volume,
           PyObject *arguments );

PyObject *pyvsbsdl_volume_get_bytes_per_sector(
           pyvsbsdl_volume_t *pyvsbsdl_volume,
           PyObject *arguments );

PyObject *pyvsbsdl_volume_get_number_of_partitions(
           pyvsbsdl_volume_t *pyvsbsdl_volume,
           PyObject *arguments );

PyObject *pyvsbsdl_volume_get_partition_by_index(
           PyObject *pyvsbsdl_volume,
           int partition_index );

PyObject *pyvsbsdl_volume_get_partition(
           pyvsbsdl_volume_t *pyvsbsdl_volume,
           PyObject *arguments,
           PyObject *keywords );

PyObject *pyvsbsdl_volume_get_partitions(
           pyvsbsdl_volume_t *pyvsbsdl_volume,
           PyObject *arguments );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _PYVSBSDL_VOLUME_H ) */

