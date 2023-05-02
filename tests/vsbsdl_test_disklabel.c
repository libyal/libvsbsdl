/*
 * Library disklabel type test program
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
#include <byte_stream.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "vsbsdl_test_functions.h"
#include "vsbsdl_test_libcerror.h"
#include "vsbsdl_test_libvsbsdl.h"
#include "vsbsdl_test_macros.h"
#include "vsbsdl_test_memory.h"
#include "vsbsdl_test_unused.h"

#include "../libvsbsdl/libvsbsdl_disklabel.h"
#include "../libvsbsdl/libvsbsdl_partition_entry.h"

uint8_t vsbsdl_test_disklabel_data1[ 512 ] = {
	0x57, 0x45, 0x56, 0x82, 0x00, 0x00, 0x00, 0x00, 0x61, 0x6d, 0x6e, 0x65, 0x73, 0x69, 0x61, 0x63,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x3f, 0x00, 0x00, 0x00,
	0x01, 0x00, 0x00, 0x00, 0x82, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x0e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x57, 0x45, 0x56, 0x82, 0x67, 0x31, 0x08, 0x00, 0x00, 0x20, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xf0, 0x1f, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

#if defined( __GNUC__ ) && !defined( LIBVSBSDL_DLL_IMPORT )

/* Tests the libvsbsdl_disklabel_initialize function
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_disklabel_initialize(
     void )
{
	libcerror_error_t *error         = NULL;
	libvsbsdl_disklabel_t *disklabel = NULL;
	int result                       = 0;

#if defined( HAVE_VSBSDL_TEST_MEMORY )
	int number_of_malloc_fail_tests  = 1;
	int number_of_memset_fail_tests  = 1;
	int test_number                  = 0;
#endif

	/* Test regular cases
	 */
	result = libvsbsdl_disklabel_initialize(
	          &disklabel,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "disklabel",
	 disklabel );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libvsbsdl_disklabel_free(
	          &disklabel,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "disklabel",
	 disklabel );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libvsbsdl_disklabel_initialize(
	          NULL,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	disklabel = (libvsbsdl_disklabel_t *) 0x12345678UL;

	result = libvsbsdl_disklabel_initialize(
	          &disklabel,
	          &error );

	disklabel = NULL;

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_VSBSDL_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libvsbsdl_disklabel_initialize with malloc failing
		 */
		vsbsdl_test_malloc_attempts_before_fail = test_number;

		result = libvsbsdl_disklabel_initialize(
		          &disklabel,
		          &error );

		if( vsbsdl_test_malloc_attempts_before_fail != -1 )
		{
			vsbsdl_test_malloc_attempts_before_fail = -1;

			if( disklabel != NULL )
			{
				libvsbsdl_disklabel_free(
				 &disklabel,
				 NULL );
			}
		}
		else
		{
			VSBSDL_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			VSBSDL_TEST_ASSERT_IS_NULL(
			 "disklabel",
			 disklabel );

			VSBSDL_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test libvsbsdl_disklabel_initialize with memset failing
		 */
		vsbsdl_test_memset_attempts_before_fail = test_number;

		result = libvsbsdl_disklabel_initialize(
		          &disklabel,
		          &error );

		if( vsbsdl_test_memset_attempts_before_fail != -1 )
		{
			vsbsdl_test_memset_attempts_before_fail = -1;

			if( disklabel != NULL )
			{
				libvsbsdl_disklabel_free(
				 &disklabel,
				 NULL );
			}
		}
		else
		{
			VSBSDL_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			VSBSDL_TEST_ASSERT_IS_NULL(
			 "disklabel",
			 disklabel );

			VSBSDL_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_VSBSDL_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( disklabel != NULL )
	{
		libvsbsdl_disklabel_free(
		 &disklabel,
		 NULL );
	}
	return( 0 );
}

/* Tests the libvsbsdl_disklabel_free function
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_disklabel_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libvsbsdl_disklabel_free(
	          NULL,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libvsbsdl_disklabel_read_data function
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_disklabel_read_data(
     void )
{
	libcerror_error_t *error         = NULL;
	libvsbsdl_disklabel_t *disklabel = NULL;
	int result                       = 0;

	/* Initialize test
	 */
	result = libvsbsdl_disklabel_initialize(
	          &disklabel,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "disklabel",
	 disklabel );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libvsbsdl_disklabel_read_data(
	          disklabel,
	          vsbsdl_test_disklabel_data1,
	          512,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libvsbsdl_disklabel_read_data(
	          NULL,
	          vsbsdl_test_disklabel_data1,
	          512,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libvsbsdl_disklabel_read_data(
	          disklabel,
	          NULL,
	          512,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libvsbsdl_disklabel_read_data(
	          disklabel,
	          vsbsdl_test_disklabel_data1,
	          (size_t) SSIZE_MAX + 1,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libvsbsdl_disklabel_read_data(
	          disklabel,
	          vsbsdl_test_disklabel_data1,
	          0,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Test error case where signature is invalid
	 */
	byte_stream_copy_from_uint32_little_endian(
	 vsbsdl_test_disklabel_data1,
	 0xffffffffUL );

	result = libvsbsdl_disklabel_read_data(
	          disklabel,
	          vsbsdl_test_disklabel_data1,
	          512,
	          &error );

	byte_stream_copy_from_uint32_little_endian(
	 vsbsdl_test_disklabel_data1,
	 0x82564557UL );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_VSBSDL_TEST_MEMORY )

	/* Test libvsbsdl_disklabel_read_data with malloc failing in libvsbsdl_partition_entry_initialize
	 */
	vsbsdl_test_malloc_attempts_before_fail = 0;

	result = libvsbsdl_disklabel_read_data(
	          disklabel,
	          vsbsdl_test_disklabel_data1,
	          512,
	          &error );

	if( vsbsdl_test_malloc_attempts_before_fail != -1 )
	{
		vsbsdl_test_malloc_attempts_before_fail = -1;
	}
	else
	{
		VSBSDL_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		VSBSDL_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_VSBSDL_TEST_MEMORY ) */

/* TODO test with libvsbsdl_partition_entry_read_data failing */

/* TODO test with libcdata_array_append_entry failing */

	/* Clean up
	 */
	result = libvsbsdl_disklabel_free(
	          &disklabel,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "disklabel",
	 disklabel );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( disklabel != NULL )
	{
		libvsbsdl_disklabel_free(
		 &disklabel,
		 NULL );
	}
	return( 0 );
}

/* Tests the libvsbsdl_disklabel_get_number_of_partition_entries function
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_disklabel_get_number_of_partition_entries(
     libvsbsdl_disklabel_t *disklabel )
{
	libcerror_error_t *error        = NULL;
	int number_of_partition_entries = 0;
	int result                      = 0;

	/* Test regular cases
	 */
	result = libvsbsdl_disklabel_get_number_of_partition_entries(
	          disklabel,
	          &number_of_partition_entries,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libvsbsdl_disklabel_get_number_of_partition_entries(
	          NULL,
	          &number_of_partition_entries,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libvsbsdl_disklabel_get_number_of_partition_entries(
	          disklabel,
	          NULL,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libvsbsdl_disklabel_get_partition_entry_by_index function
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_disklabel_get_partition_entry_by_index(
     libvsbsdl_disklabel_t *disklabel )
{
	libcerror_error_t *error                     = NULL;
	libvsbsdl_partition_entry_t *partition_entry = 0;
	int result                                   = 0;

	/* Test regular cases
	 */
	result = libvsbsdl_disklabel_get_partition_entry_by_index(
	          disklabel,
	          0,
	          &partition_entry,
	          &error );

	VSBSDL_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "partition_entry",
	 partition_entry );

	partition_entry = NULL;

	/* Test error cases
	 */
	result = libvsbsdl_disklabel_get_partition_entry_by_index(
	          NULL,
	          0,
	          &partition_entry,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "partition_entry",
	 partition_entry );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libvsbsdl_disklabel_get_partition_entry_by_index(
	          disklabel,
	          -1,
	          &partition_entry,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "partition_entry",
	 partition_entry );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libvsbsdl_disklabel_get_partition_entry_by_index(
	          disklabel,
	          0,
	          NULL,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "partition_entry",
	 partition_entry );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libvsbsdl_disklabel_read_file_io_handle function
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_disklabel_read_file_io_handle(
     void )
{
	libbfio_handle_t *file_io_handle = NULL;
	libcerror_error_t *error         = NULL;
	libvsbsdl_disklabel_t *disklabel = NULL;
	int result                       = 0;

	/* Initialize test
	 */
	result = libvsbsdl_disklabel_initialize(
	          &disklabel,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "disklabel",
	 disklabel );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Initialize file IO handle
	 */
	result = vsbsdl_test_open_file_io_handle(
	          &file_io_handle,
	          vsbsdl_test_disklabel_data1,
	          512,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "file_io_handle",
	 file_io_handle );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libvsbsdl_disklabel_read_file_io_handle(
	          disklabel,
	          file_io_handle,
	          0,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libvsbsdl_disklabel_read_file_io_handle(
	          NULL,
	          file_io_handle,
	          0,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libvsbsdl_disklabel_read_file_io_handle(
	          disklabel,
	          NULL,
	          0,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libvsbsdl_disklabel_read_file_io_handle(
	          disklabel,
	          file_io_handle,
	          -1,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up file IO handle
	 */
	result = vsbsdl_test_close_file_io_handle(
	          &file_io_handle,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test data too small
	 */
	result = vsbsdl_test_open_file_io_handle(
	          &file_io_handle,
	          vsbsdl_test_disklabel_data1,
	          8,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "file_io_handle",
	 file_io_handle );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libvsbsdl_disklabel_read_file_io_handle(
	          disklabel,
	          file_io_handle,
	          0,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = vsbsdl_test_close_file_io_handle(
	          &file_io_handle,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test data invalid
	 */
	result = vsbsdl_test_open_file_io_handle(
	          &file_io_handle,
	          vsbsdl_test_disklabel_data1,
	          512,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "file_io_handle",
	 file_io_handle );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	byte_stream_copy_from_uint32_little_endian(
	 vsbsdl_test_disklabel_data1,
	 0xffffffffUL );

	result = libvsbsdl_disklabel_read_file_io_handle(
	          disklabel,
	          file_io_handle,
	          0,
	          &error );

	byte_stream_copy_from_uint32_little_endian(
	 vsbsdl_test_disklabel_data1,
	 0x82564557UL );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = vsbsdl_test_close_file_io_handle(
	          &file_io_handle,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Clean up
	 */
	result = libvsbsdl_disklabel_free(
	          &disklabel,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "disklabel",
	 disklabel );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( file_io_handle != NULL )
	{
		libbfio_handle_free(
		 &file_io_handle,
		 NULL );
	}
	if( disklabel != NULL )
	{
		libvsbsdl_disklabel_free(
		 &disklabel,
		 NULL );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) && !defined( LIBVSBSDL_DLL_IMPORT ) */

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc VSBSDL_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] VSBSDL_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc VSBSDL_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] VSBSDL_TEST_ATTRIBUTE_UNUSED )
#endif
{
#if defined( __GNUC__ ) && !defined( LIBVSBSDL_DLL_IMPORT )
	libcerror_error_t *error         = NULL;
	libvsbsdl_disklabel_t *disklabel = NULL;
	int result                       = 0;
#endif

	VSBSDL_TEST_UNREFERENCED_PARAMETER( argc )
	VSBSDL_TEST_UNREFERENCED_PARAMETER( argv )

#if defined( __GNUC__ ) && !defined( LIBVSBSDL_DLL_IMPORT )

	VSBSDL_TEST_RUN(
	 "libvsbsdl_disklabel_initialize",
	 vsbsdl_test_disklabel_initialize );

	VSBSDL_TEST_RUN(
	 "libvsbsdl_disklabel_free",
	 vsbsdl_test_disklabel_free );

	VSBSDL_TEST_RUN(
	 "libvsbsdl_disklabel_read_data",
	 vsbsdl_test_disklabel_read_data );

	VSBSDL_TEST_RUN(
	 "libvsbsdl_disklabel_read_file_io_handle",
	 vsbsdl_test_disklabel_read_file_io_handle );

#if !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 )

	/* Initialize disklabel for tests
	 */
	result = libvsbsdl_disklabel_initialize(
	          &disklabel,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "disklabel",
	 disklabel );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libvsbsdl_disklabel_read_data(
	          disklabel,
	          vsbsdl_test_disklabel_data1,
	          512,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	VSBSDL_TEST_RUN_WITH_ARGS(
	 "libvsbsdl_disklabel_get_number_of_partition_entries",
	 vsbsdl_test_disklabel_get_number_of_partition_entries,
	 disklabel );

	VSBSDL_TEST_RUN_WITH_ARGS(
	 "libvsbsdl_disklabel_get_partition_entry_by_index",
	 vsbsdl_test_disklabel_get_partition_entry_by_index,
	 disklabel );

	/* Clean up
	 */
	result = libvsbsdl_disklabel_free(
	          &disklabel,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "disklabel",
	 disklabel );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

#endif /* !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 ) */

#endif /* defined( __GNUC__ ) && !defined( LIBVSBSDL_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

#if defined( __GNUC__ ) && !defined( LIBVSBSDL_DLL_IMPORT )

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( disklabel != NULL )
	{
		libvsbsdl_disklabel_free(
		 &disklabel,
		 NULL );
	}
	return( EXIT_FAILURE );

#endif /* defined( __GNUC__ ) && !defined( LIBVSBSDL_DLL_IMPORT ) */
}

