/*
 * Library partition_entry type test program
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
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "vsbsdl_test_libcerror.h"
#include "vsbsdl_test_libvsbsdl.h"
#include "vsbsdl_test_macros.h"
#include "vsbsdl_test_memory.h"
#include "vsbsdl_test_unused.h"

#include "../libvsbsdl/libvsbsdl_partition_entry.h"

uint8_t vsbsdl_test_partition_entry_data1[ 16 ] = {
	0xf0, 0x1f, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

#if defined( __GNUC__ ) && !defined( LIBVSBSDL_DLL_IMPORT )

/* Tests the libvsbsdl_partition_entry_initialize function
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_partition_entry_initialize(
     void )
{
	libcerror_error_t *error                     = NULL;
	libvsbsdl_partition_entry_t *partition_entry = NULL;
	int result                                   = 0;

#if defined( HAVE_VSBSDL_TEST_MEMORY )
	int number_of_malloc_fail_tests              = 1;
	int number_of_memset_fail_tests              = 1;
	int test_number                              = 0;
#endif

	/* Test regular cases
	 */
	result = libvsbsdl_partition_entry_initialize(
	          &partition_entry,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "partition_entry",
	 partition_entry );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libvsbsdl_partition_entry_free(
	          &partition_entry,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "partition_entry",
	 partition_entry );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libvsbsdl_partition_entry_initialize(
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

	partition_entry = (libvsbsdl_partition_entry_t *) 0x12345678UL;

	result = libvsbsdl_partition_entry_initialize(
	          &partition_entry,
	          &error );

	partition_entry = NULL;

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
		/* Test libvsbsdl_partition_entry_initialize with malloc failing
		 */
		vsbsdl_test_malloc_attempts_before_fail = test_number;

		result = libvsbsdl_partition_entry_initialize(
		          &partition_entry,
		          &error );

		if( vsbsdl_test_malloc_attempts_before_fail != -1 )
		{
			vsbsdl_test_malloc_attempts_before_fail = -1;

			if( partition_entry != NULL )
			{
				libvsbsdl_partition_entry_free(
				 &partition_entry,
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
			 "partition_entry",
			 partition_entry );

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
		/* Test libvsbsdl_partition_entry_initialize with memset failing
		 */
		vsbsdl_test_memset_attempts_before_fail = test_number;

		result = libvsbsdl_partition_entry_initialize(
		          &partition_entry,
		          &error );

		if( vsbsdl_test_memset_attempts_before_fail != -1 )
		{
			vsbsdl_test_memset_attempts_before_fail = -1;

			if( partition_entry != NULL )
			{
				libvsbsdl_partition_entry_free(
				 &partition_entry,
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
			 "partition_entry",
			 partition_entry );

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
	if( partition_entry != NULL )
	{
		libvsbsdl_partition_entry_free(
		 &partition_entry,
		 NULL );
	}
	return( 0 );
}

/* Tests the libvsbsdl_partition_entry_free function
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_partition_entry_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libvsbsdl_partition_entry_free(
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

/* Tests the libvsbsdl_partition_entry_read_data function
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_partition_entry_read_data(
     void )
{
	libcerror_error_t *error                     = NULL;
	libvsbsdl_partition_entry_t *partition_entry = NULL;
	int result                                   = 0;

	/* Initialize test
	 */
	result = libvsbsdl_partition_entry_initialize(
	          &partition_entry,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "partition_entry",
	 partition_entry );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libvsbsdl_partition_entry_read_data(
	          partition_entry,
	          vsbsdl_test_partition_entry_data1,
	          16,
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
	result = libvsbsdl_partition_entry_read_data(
	          NULL,
	          vsbsdl_test_partition_entry_data1,
	          16,
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

	result = libvsbsdl_partition_entry_read_data(
	          partition_entry,
	          NULL,
	          16,
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

	result = libvsbsdl_partition_entry_read_data(
	          partition_entry,
	          vsbsdl_test_partition_entry_data1,
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

	result = libvsbsdl_partition_entry_read_data(
	          partition_entry,
	          vsbsdl_test_partition_entry_data1,
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

	/* Clean up
	 */
	result = libvsbsdl_partition_entry_free(
	          &partition_entry,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "partition_entry",
	 partition_entry );

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
	if( partition_entry != NULL )
	{
		libvsbsdl_partition_entry_free(
		 &partition_entry,
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
	VSBSDL_TEST_UNREFERENCED_PARAMETER( argc )
	VSBSDL_TEST_UNREFERENCED_PARAMETER( argv )

#if defined( __GNUC__ ) && !defined( LIBVSBSDL_DLL_IMPORT )

	VSBSDL_TEST_RUN(
	 "libvsbsdl_partition_entry_initialize",
	 vsbsdl_test_partition_entry_initialize );

	VSBSDL_TEST_RUN(
	 "libvsbsdl_partition_entry_free",
	 vsbsdl_test_partition_entry_free );

	VSBSDL_TEST_RUN(
	 "libvsbsdl_partition_entry_read_data",
	 vsbsdl_test_partition_entry_read_data );

#endif /* defined( __GNUC__ ) && !defined( LIBVSBSDL_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

#if defined( __GNUC__ ) && !defined( LIBVSBSDL_DLL_IMPORT )

on_error:
	return( EXIT_FAILURE );

#endif /* defined( __GNUC__ ) && !defined( LIBVSBSDL_DLL_IMPORT ) */
}

