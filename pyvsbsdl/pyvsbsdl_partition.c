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

#include <common.h>
#include <narrow_string.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( HAVE_WINAPI )
#include <stdlib.h>
#endif

#include "pyvsbsdl_error.h"
#include "pyvsbsdl_integer.h"
#include "pyvsbsdl_libcerror.h"
#include "pyvsbsdl_libvsbsdl.h"
#include "pyvsbsdl_partition.h"
#include "pyvsbsdl_python.h"
#include "pyvsbsdl_unused.h"

PyMethodDef pyvsbsdl_partition_object_methods[] = {

	{ "get_entry_index",
	  (PyCFunction) pyvsbsdl_partition_get_entry_index,
	  METH_NOARGS,
	  "get_entry_index() -> Integer\n"
	  "\n"
	  "Retrieves the partition entry index." },

	{ "get_name_string",
	  (PyCFunction) pyvsbsdl_partition_get_name_string,
	  METH_NOARGS,
	  "get_name_string() -> String\n"
	  "\n"
	  "Retrieves the ASCII encoded string of the partition name." },

	{ "get_volume_offset",
	  (PyCFunction) pyvsbsdl_partition_get_volume_offset,
	  METH_NOARGS,
	  "get_volume_offset() -> Integer\n"
	  "\n"
	  "Retrieves the volume offset." },

	{ "read_buffer",
	  (PyCFunction) pyvsbsdl_partition_read_buffer,
	  METH_VARARGS | METH_KEYWORDS,
	  "read_buffer(size) -> Binary string\n"
	  "\n"
	  "Reads a buffer of data." },

	{ "read_buffer_at_offset",
	  (PyCFunction) pyvsbsdl_partition_read_buffer_at_offset,
	  METH_VARARGS | METH_KEYWORDS,
	  "read_buffer_at_offset(size, offset) -> Binary string\n"
	  "\n"
	  "Reads a buffer of data at a specific offset." },

	{ "seek_offset",
	  (PyCFunction) pyvsbsdl_partition_seek_offset,
	  METH_VARARGS | METH_KEYWORDS,
	  "seek_offset(offset, whence) -> None\n"
	  "\n"
	  "Seeks an offset within the data." },

	{ "get_offset",
	  (PyCFunction) pyvsbsdl_partition_get_offset,
	  METH_NOARGS,
	  "get_offset() -> Integer\n"
	  "\n"
	  "Retrieves the current offset." },

	{ "read",
	  (PyCFunction) pyvsbsdl_partition_read_buffer,
	  METH_VARARGS | METH_KEYWORDS,
	  "read(size) -> Binary string\n"
	  "\n"
	  "Reads a buffer of data." },

	{ "seek",
	  (PyCFunction) pyvsbsdl_partition_seek_offset,
	  METH_VARARGS | METH_KEYWORDS,
	  "seek(offset, whence) -> None\n"
	  "\n"
	  "Seeks an offset within the data." },

	{ "tell",
	  (PyCFunction) pyvsbsdl_partition_get_offset,
	  METH_NOARGS,
	  "tell() -> Integer\n"
	  "\n"
	  "Retrieves the current offset." },

	{ "get_size",
	  (PyCFunction) pyvsbsdl_partition_get_size,
	  METH_NOARGS,
	  "get_size() -> Integer\n"
	  "\n"
	  "Retrieves the size." },

	/* Sentinel */
	{ NULL, NULL, 0, NULL }
};

PyGetSetDef pyvsbsdl_partition_object_get_set_definitions[] = {

	{ "entry_index",
	  (getter) pyvsbsdl_partition_get_entry_index,
	  (setter) 0,
	  "The entry index.",
	  NULL },

	{ "name_string",
	  (getter) pyvsbsdl_partition_get_name_string,
	  (setter) 0,
	  "The ASCII encoded string of the partition name.",
	  NULL },

	{ "volume_offset",
	  (getter) pyvsbsdl_partition_get_volume_offset,
	  (setter) 0,
	  "The volume offset.",
	  NULL },

	{ "size",
	  (getter) pyvsbsdl_partition_get_size,
	  (setter) 0,
	  "The size.",
	  NULL },

	/* Sentinel */
	{ NULL, NULL, NULL, NULL, NULL }
};

PyTypeObject pyvsbsdl_partition_type_object = {
	PyVarObject_HEAD_INIT( NULL, 0 )

	/* tp_name */
	"pyvsbsdl.partition",
	/* tp_basicsize */
	sizeof( pyvsbsdl_partition_t ),
	/* tp_itemsize */
	0,
	/* tp_dealloc */
	(destructor) pyvsbsdl_partition_free,
	/* tp_print */
	0,
	/* tp_getattr */
	0,
	/* tp_setattr */
	0,
	/* tp_compare */
	0,
	/* tp_repr */
	0,
	/* tp_as_number */
	0,
	/* tp_as_sequence */
	0,
	/* tp_as_mapping */
	0,
	/* tp_hash */
	0,
	/* tp_call */
	0,
	/* tp_str */
	0,
	/* tp_getattro */
	0,
	/* tp_setattro */
	0,
	/* tp_as_buffer */
	0,
	/* tp_flags */
	Py_TPFLAGS_DEFAULT,
	/* tp_doc */
	"pyvsbsdl partition object (wraps libvsbsdl_partition_t)",
	/* tp_traverse */
	0,
	/* tp_clear */
	0,
	/* tp_richcompare */
	0,
	/* tp_weaklistoffset */
	0,
	/* tp_iter */
	0,
	/* tp_iternext */
	0,
	/* tp_methods */
	pyvsbsdl_partition_object_methods,
	/* tp_members */
	0,
	/* tp_getset */
	pyvsbsdl_partition_object_get_set_definitions,
	/* tp_base */
	0,
	/* tp_dict */
	0,
	/* tp_descr_get */
	0,
	/* tp_descr_set */
	0,
	/* tp_dictoffset */
	0,
	/* tp_init */
	(initproc) pyvsbsdl_partition_init,
	/* tp_alloc */
	0,
	/* tp_new */
	0,
	/* tp_free */
	0,
	/* tp_is_gc */
	0,
	/* tp_bases */
	NULL,
	/* tp_mro */
	NULL,
	/* tp_cache */
	NULL,
	/* tp_subclasses */
	NULL,
	/* tp_weaklist */
	NULL,
	/* tp_del */
	0
};

/* Creates a new partition object
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyvsbsdl_partition_new(
           libvsbsdl_partition_t *partition,
           PyObject *parent_object )
{
	pyvsbsdl_partition_t *pyvsbsdl_partition = NULL;
	static char *function                  = "pyvsbsdl_partition_new";

	if( partition == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid partition.",
		 function );

		return( NULL );
	}
	/* PyObject_New does not invoke tp_init
	 */
	pyvsbsdl_partition = PyObject_New(
	                     struct pyvsbsdl_partition,
	                     &pyvsbsdl_partition_type_object );

	if( pyvsbsdl_partition == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize partition.",
		 function );

		goto on_error;
	}
	pyvsbsdl_partition->partition     = partition;
	pyvsbsdl_partition->parent_object = parent_object;

	if( pyvsbsdl_partition->parent_object != NULL )
	{
		Py_IncRef(
		 pyvsbsdl_partition->parent_object );
	}
	return( (PyObject *) pyvsbsdl_partition );

on_error:
	if( pyvsbsdl_partition != NULL )
	{
		Py_DecRef(
		 (PyObject *) pyvsbsdl_partition );
	}
	return( NULL );
}

/* Initializes a partition object
 * Returns 0 if successful or -1 on error
 */
int pyvsbsdl_partition_init(
     pyvsbsdl_partition_t *pyvsbsdl_partition )
{
	static char *function = "pyvsbsdl_partition_init";

	if( pyvsbsdl_partition == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid partition.",
		 function );

		return( -1 );
	}
	/* Make sure libvsbsdl partition is set to NULL
	 */
	pyvsbsdl_partition->partition = NULL;

	PyErr_Format(
	 PyExc_NotImplementedError,
	 "%s: initialize of partition not supported.",
	 function );

	return( -1 );
}

/* Frees a partition object
 */
void pyvsbsdl_partition_free(
      pyvsbsdl_partition_t *pyvsbsdl_partition )
{
	struct _typeobject *ob_type = NULL;
	libcerror_error_t *error    = NULL;
	static char *function       = "pyvsbsdl_partition_free";
	int result                  = 0;

	if( pyvsbsdl_partition == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid partition.",
		 function );

		return;
	}
	ob_type = Py_TYPE(
	           pyvsbsdl_partition );

	if( ob_type == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: missing ob_type.",
		 function );

		return;
	}
	if( ob_type->tp_free == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid ob_type - missing tp_free.",
		 function );

		return;
	}
	if( pyvsbsdl_partition->partition != NULL )
	{
		Py_BEGIN_ALLOW_THREADS

		result = libvsbsdl_partition_free(
		          &( pyvsbsdl_partition->partition ),
		          &error );

		Py_END_ALLOW_THREADS

		if( result != 1 )
		{
			pyvsbsdl_error_raise(
			 error,
			 PyExc_MemoryError,
			 "%s: unable to free libvsbsdl partition.",
			 function );

			libcerror_error_free(
			 &error );
		}
	}
	if( pyvsbsdl_partition->parent_object != NULL )
	{
		Py_DecRef(
		 pyvsbsdl_partition->parent_object );
	}
	ob_type->tp_free(
	 (PyObject*) pyvsbsdl_partition );
}

/* Retrieves the entry index
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyvsbsdl_partition_get_entry_index(
           pyvsbsdl_partition_t *pyvsbsdl_partition,
           PyObject *arguments PYVSBSDL_ATTRIBUTE_UNUSED )
{
	PyObject *integer_object = NULL;
	libcerror_error_t *error = NULL;
	static char *function    = "pyvsbsdl_partition_get_entry_index";
	uint16_t entry_index     = 0;
	int result               = 0;

	PYVSBSDL_UNREFERENCED_PARAMETER( arguments )

	if( pyvsbsdl_partition == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid partition.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libvsbsdl_partition_get_entry_index(
	          pyvsbsdl_partition->partition,
	          &entry_index,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyvsbsdl_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve entry index.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
#if PY_MAJOR_VERSION >= 3
	integer_object = PyLong_FromLong(
	                  (long) entry_index );
#else
	integer_object = PyInt_FromLong(
	                  (long) entry_index );
#endif
	return( integer_object );
}

/* Retrieves the name string
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyvsbsdl_partition_get_name_string(
           pyvsbsdl_partition_t *pyvsbsdl_partition,
           PyObject *arguments PYVSBSDL_ATTRIBUTE_UNUSED )
{
	char name[ 32 ];

	PyObject *string_object  = NULL;
	libcerror_error_t *error = NULL;
	static char *function    = "pyvsbsdl_partition_get_name_string";
	size_t name_length       = 0;
	int result               = 0;

	PYVSBSDL_UNREFERENCED_PARAMETER( arguments )

	if( pyvsbsdl_partition == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid partition.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libvsbsdl_partition_get_name_string(
		  pyvsbsdl_partition->partition,
		  name,
		  32,
		  &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyvsbsdl_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve name.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	name_length = narrow_string_length(
	               name );

	/* Pass the string length to PyUnicode_DecodeUTF8
	 * otherwise it makes the end of string character is part
	 * of the string
	 */
	string_object = PyUnicode_DecodeUTF8(
			 (char *) name,
			 (Py_ssize_t) name_length,
			 NULL );

	return( string_object );
}

/* Retrieves the volume offset
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyvsbsdl_partition_get_volume_offset(
           pyvsbsdl_partition_t *pyvsbsdl_partition,
           PyObject *arguments PYVSBSDL_ATTRIBUTE_UNUSED )
{
	PyObject *integer_object = NULL;
	libcerror_error_t *error = NULL;
	static char *function    = "pyvsbsdl_partition_get_volume_offset";
	off64_t offset           = 0;
	int result               = 0;

	PYVSBSDL_UNREFERENCED_PARAMETER( arguments )

	if( pyvsbsdl_partition == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid partition.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libvsbsdl_partition_get_volume_offset(
	          pyvsbsdl_partition->partition,
	          &offset,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		pyvsbsdl_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve volume offset.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	else if( result == 0 )
	{
		Py_IncRef(
		 Py_None );

		return( Py_None );
	}
	integer_object = pyvsbsdl_integer_signed_new_from_64bit(
	                  (int64_t) offset );

	return( integer_object );
}

/* Reads data at the current offset into a buffer
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyvsbsdl_partition_read_buffer(
           pyvsbsdl_partition_t *pyvsbsdl_partition,
           PyObject *arguments,
           PyObject *keywords )
{
	PyObject *integer_object    = NULL;
	PyObject *string_object     = NULL;
	libcerror_error_t *error    = NULL;
	char *buffer                = NULL;
	static char *function       = "pyvsbsdl_partition_read_buffer";
	static char *keyword_list[] = { "size", NULL };
	ssize_t read_count          = 0;
	int64_t read_size           = 0;
	int result                  = 0;

	if( pyvsbsdl_partition == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid partition.",
		 function );

		return( NULL );
	}
	if( PyArg_ParseTupleAndKeywords(
	     arguments,
	     keywords,
	     "|O",
	     keyword_list,
	     &integer_object ) == 0 )
	{
		return( NULL );
	}
	if( integer_object == NULL )
	{
		result = 0;
	}
	else
	{
		result = PyObject_IsInstance(
		          integer_object,
		          (PyObject *) &PyLong_Type );

		if( result == -1 )
		{
			pyvsbsdl_error_fetch_and_raise(
			 PyExc_RuntimeError,
			 "%s: unable to determine if integer object is of type long.",
			 function );

			return( NULL );
		}
#if PY_MAJOR_VERSION < 3
		else if( result == 0 )
		{
			PyErr_Clear();

			result = PyObject_IsInstance(
			          integer_object,
			          (PyObject *) &PyInt_Type );

			if( result == -1 )
			{
				pyvsbsdl_error_fetch_and_raise(
				 PyExc_RuntimeError,
				 "%s: unable to determine if integer object is of type int.",
				 function );

				return( NULL );
			}
		}
#endif
	}
	if( result != 0 )
	{
		if( pyvsbsdl_integer_signed_copy_to_64bit(
		     integer_object,
		     &read_size,
		     &error ) != 1 )
		{
			pyvsbsdl_error_raise(
			 error,
			 PyExc_ValueError,
			 "%s: unable to convert integer object into read size.",
			 function );

			libcerror_error_free(
			 &error );

			return( NULL );
		}
	}
	else if( ( integer_object == NULL )
	      || ( integer_object == Py_None ) )
	{
		Py_BEGIN_ALLOW_THREADS

		result = libvsbsdl_partition_get_size(
		          pyvsbsdl_partition->partition,
		          (size64_t *) &read_size,
		          &error );

		Py_END_ALLOW_THREADS

		if( result != 1 )
		{
			pyvsbsdl_error_raise(
			 error,
			 PyExc_IOError,
			 "%s: unable to retrieve size.",
			 function );

			libcerror_error_free(
			 &error );

			return( NULL );
		}
	}
	else
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: unsupported integer object type.",
		 function );

		return( NULL );
	}
	if( read_size == 0 )
	{
#if PY_MAJOR_VERSION >= 3
		string_object = PyBytes_FromString(
		                 "" );
#else
		string_object = PyString_FromString(
		                 "" );
#endif
		return( string_object );
	}
	if( read_size < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid read size value less than zero.",
		 function );

		return( NULL );
	}
	/* Make sure the data fits into a memory buffer
	 */
	if( ( read_size > (int64_t) INT_MAX )
	 || ( read_size > (int64_t) SSIZE_MAX ) )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid argument read size value exceeds maximum.",
		 function );

		return( NULL );
	}
#if PY_MAJOR_VERSION >= 3
	string_object = PyBytes_FromStringAndSize(
	                 NULL,
	                 (Py_ssize_t) read_size );

	buffer = PyBytes_AsString(
	          string_object );
#else
	/* Note that a size of 0 is not supported
	 */
	string_object = PyString_FromStringAndSize(
	                 NULL,
	                 (Py_ssize_t) read_size );

	buffer = PyString_AsString(
	          string_object );
#endif
	Py_BEGIN_ALLOW_THREADS

	read_count = libvsbsdl_partition_read_buffer(
	              pyvsbsdl_partition->partition,
	              (uint8_t *) buffer,
	              (size_t) read_size,
	              &error );

	Py_END_ALLOW_THREADS

	if( read_count == -1 )
	{
		pyvsbsdl_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to read data.",
		 function );

		libcerror_error_free(
		 &error );

		Py_DecRef(
		 (PyObject *) string_object );

		return( NULL );
	}
	/* Need to resize the string here in case read_size was not fully read.
	 */
#if PY_MAJOR_VERSION >= 3
	if( _PyBytes_Resize(
	     &string_object,
	     (Py_ssize_t) read_count ) != 0 )
#else
	if( _PyString_Resize(
	     &string_object,
	     (Py_ssize_t) read_count ) != 0 )
#endif
	{
		Py_DecRef(
		 (PyObject *) string_object );

		return( NULL );
	}
	return( string_object );
}

/* Reads data at a specific offset into a buffer
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyvsbsdl_partition_read_buffer_at_offset(
           pyvsbsdl_partition_t *pyvsbsdl_partition,
           PyObject *arguments,
           PyObject *keywords )
{
	PyObject *integer_object    = NULL;
	PyObject *string_object     = NULL;
	libcerror_error_t *error    = NULL;
	char *buffer                = NULL;
	static char *function       = "pyvsbsdl_partition_read_buffer_at_offset";
	static char *keyword_list[] = { "size", "offset", NULL };
	ssize_t read_count          = 0;
	off64_t read_offset         = 0;
	int64_t read_size           = 0;
	int result                  = 0;

	if( pyvsbsdl_partition == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid partition.",
		 function );

		return( NULL );
	}
	if( PyArg_ParseTupleAndKeywords(
	     arguments,
	     keywords,
	     "OL",
	     keyword_list,
	     &integer_object,
	     &read_offset ) == 0 )
	{
		return( NULL );
	}
	result = PyObject_IsInstance(
	          integer_object,
	          (PyObject *) &PyLong_Type );

	if( result == -1 )
	{
		pyvsbsdl_error_fetch_and_raise(
		 PyExc_RuntimeError,
		 "%s: unable to determine if integer object is of type long.",
		 function );

		return( NULL );
	}
#if PY_MAJOR_VERSION < 3
	else if( result == 0 )
	{
		PyErr_Clear();

		result = PyObject_IsInstance(
		          integer_object,
		          (PyObject *) &PyInt_Type );

		if( result == -1 )
		{
			pyvsbsdl_error_fetch_and_raise(
			 PyExc_RuntimeError,
			 "%s: unable to determine if integer object is of type int.",
			 function );

			return( NULL );
		}
	}
#endif
	if( result != 0 )
	{
		if( pyvsbsdl_integer_signed_copy_to_64bit(
		     integer_object,
		     &read_size,
		     &error ) != 1 )
		{
			pyvsbsdl_error_raise(
			 error,
			 PyExc_ValueError,
			 "%s: unable to convert integer object into read size.",
			 function );

			libcerror_error_free(
			 &error );

			return( NULL );
		}
	}
	else
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: unsupported integer object type.",
		 function );

		return( NULL );
	}
	if( read_size == 0 )
	{
#if PY_MAJOR_VERSION >= 3
		string_object = PyBytes_FromString(
		                 "" );
#else
		string_object = PyString_FromString(
		                 "" );
#endif
		return( string_object );
	}
	if( read_size < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid read size value less than zero.",
		 function );

		return( NULL );
	}
	/* Make sure the data fits into a memory buffer
	 */
	if( ( read_size > (int64_t) INT_MAX )
	 || ( read_size > (int64_t) SSIZE_MAX ) )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid argument read size value exceeds maximum.",
		 function );

		return( NULL );
	}
	if( read_offset < 0 )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid read offset value less than zero.",
		 function );

		return( NULL );
	}
#if PY_MAJOR_VERSION >= 3
	string_object = PyBytes_FromStringAndSize(
	                 NULL,
	                 (Py_ssize_t) read_size );

	buffer = PyBytes_AsString(
	          string_object );
#else
	/* Note that a size of 0 is not supported
	 */
	string_object = PyString_FromStringAndSize(
	                 NULL,
	                 (Py_ssize_t) read_size );

	buffer = PyString_AsString(
	          string_object );
#endif
	Py_BEGIN_ALLOW_THREADS

	read_count = libvsbsdl_partition_read_buffer_at_offset(
	              pyvsbsdl_partition->partition,
	              (uint8_t *) buffer,
	              (size_t) read_size,
	              (off64_t) read_offset,
	              &error );

	Py_END_ALLOW_THREADS

	if( read_count == -1 )
	{
		pyvsbsdl_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to read data.",
		 function );

		libcerror_error_free(
		 &error );

		Py_DecRef(
		 (PyObject *) string_object );

		return( NULL );
	}
	/* Need to resize the string here in case read_size was not fully read.
	 */
#if PY_MAJOR_VERSION >= 3
	if( _PyBytes_Resize(
	     &string_object,
	     (Py_ssize_t) read_count ) != 0 )
#else
	if( _PyString_Resize(
	     &string_object,
	     (Py_ssize_t) read_count ) != 0 )
#endif
	{
		Py_DecRef(
		 (PyObject *) string_object );

		return( NULL );
	}
	return( string_object );
}

/* Seeks a certain offset
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyvsbsdl_partition_seek_offset(
           pyvsbsdl_partition_t *pyvsbsdl_partition,
           PyObject *arguments,
           PyObject *keywords )
{
	libcerror_error_t *error    = NULL;
	static char *function       = "pyvsbsdl_partition_seek_offset";
	static char *keyword_list[] = { "offset", "whence", NULL };
	off64_t offset              = 0;
	int whence                  = 0;

	if( pyvsbsdl_partition == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid partition.",
		 function );

		return( NULL );
	}
	if( PyArg_ParseTupleAndKeywords(
	     arguments,
	     keywords,
	     "L|i",
	     keyword_list,
	     &offset,
	     &whence ) == 0 )
	{
		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	offset = libvsbsdl_partition_seek_offset(
	          pyvsbsdl_partition->partition,
	          offset,
	          whence,
	          &error );

	Py_END_ALLOW_THREADS

 	if( offset == -1 )
	{
		pyvsbsdl_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to seek offset.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	Py_IncRef(
	 Py_None );

	return( Py_None );
}

/* Retrieves the current offset
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyvsbsdl_partition_get_offset(
           pyvsbsdl_partition_t *pyvsbsdl_partition,
           PyObject *arguments PYVSBSDL_ATTRIBUTE_UNUSED )
{
	PyObject *integer_object = NULL;
	libcerror_error_t *error = NULL;
	static char *function    = "pyvsbsdl_partition_get_offset";
	off64_t offset           = 0;
	int result               = 0;

	PYVSBSDL_UNREFERENCED_PARAMETER( arguments )

	if( pyvsbsdl_partition == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid partition.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libvsbsdl_partition_get_offset(
	          pyvsbsdl_partition->partition,
	          &offset,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		pyvsbsdl_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve current offset.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	else if( result == 0 )
	{
		Py_IncRef(
		 Py_None );

		return( Py_None );
	}
	integer_object = pyvsbsdl_integer_signed_new_from_64bit(
	                  (int64_t) offset );

	return( integer_object );
}

/* Retrieves the size
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyvsbsdl_partition_get_size(
           pyvsbsdl_partition_t *pyvsbsdl_partition,
           PyObject *arguments PYVSBSDL_ATTRIBUTE_UNUSED )
{
	PyObject *integer_object = NULL;
	libcerror_error_t *error = NULL;
	static char *function    = "pyvsbsdl_partition_get_size";
	size64_t size            = 0;
	int result               = 0;

	PYVSBSDL_UNREFERENCED_PARAMETER( arguments )

	if( pyvsbsdl_partition == NULL )
	{
		PyErr_Format(
		 PyExc_ValueError,
		 "%s: invalid partition.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = libvsbsdl_partition_get_size(
	          pyvsbsdl_partition->partition,
	          &size,
	          &error );

	Py_END_ALLOW_THREADS

	if( result != 1 )
	{
		pyvsbsdl_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: failed to retrieve size.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	integer_object = pyvsbsdl_integer_unsigned_new_from_64bit(
	                  (uint64_t) size );

	return( integer_object );
}

