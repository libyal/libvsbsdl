/*
 * Python object definition of the sequence and iterator object of partitions
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

#if !defined( _PYVSBSDL_PARTITIONS_H )
#define _PYVSBSDL_PARTITIONS_H

#include <common.h>
#include <types.h>

#include "pyvsbsdl_libvsbsdl.h"
#include "pyvsbsdl_python.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct pyvsbsdl_partitions pyvsbsdl_partitions_t;

struct pyvsbsdl_partitions
{
	/* Python object initialization
	 */
	PyObject_HEAD

	/* The parent object
	 */
	PyObject *parent_object;

	/* The get item by index callback function
	 */
	PyObject* (*get_item_by_index)(
	             PyObject *parent_object,
	             int index );

	/* The current index
	 */
	int current_index;

	/* The number of items
	 */
	int number_of_items;
};

extern PyTypeObject pyvsbsdl_partitions_type_object;

PyObject *pyvsbsdl_partitions_new(
           PyObject *parent_object,
           PyObject* (*get_item_by_index)(
                        PyObject *parent_object,
                        int index ),
           int number_of_items );

int pyvsbsdl_partitions_init(
     pyvsbsdl_partitions_t *sequence_object );

void pyvsbsdl_partitions_free(
      pyvsbsdl_partitions_t *sequence_object );

Py_ssize_t pyvsbsdl_partitions_len(
            pyvsbsdl_partitions_t *sequence_object );

PyObject *pyvsbsdl_partitions_getitem(
           pyvsbsdl_partitions_t *sequence_object,
           Py_ssize_t item_index );

PyObject *pyvsbsdl_partitions_iter(
           pyvsbsdl_partitions_t *sequence_object );

PyObject *pyvsbsdl_partitions_iternext(
           pyvsbsdl_partitions_t *sequence_object );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _PYVSBSDL_PARTITIONS_H ) */

