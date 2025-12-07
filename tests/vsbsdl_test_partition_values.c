/*
 * Library partition_values type test program
 *
 * Copyright (C) 2023-2025, Joachim Metz <joachim.metz@gmail.com>
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

#include "../libvsbsdl/libvsbsdl_partition_values.h"

#if defined( __GNUC__ ) && !defined( LIBVSBSDL_DLL_IMPORT )

/* Tests the libvsbsdl_partition_values_initialize function
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_partition_values_initialize(
     void )
{
	libcerror_error_t *error                      = NULL;
	libvsbsdl_partition_values_t *partition_values = NULL;
	int result                                    = 0;

#if defined( HAVE_VSBSDL_TEST_MEMORY )
	int number_of_malloc_fail_tests               = 1;
	int number_of_memset_fail_tests               = 1;
	int test_number                               = 0;
#endif

	/* Test regular cases
	 */
	result = libvsbsdl_partition_values_initialize(
	          &partition_values,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "partition_values",
	 partition_values );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libvsbsdl_partition_values_free(
	          &partition_values,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "partition_values",
	 partition_values );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libvsbsdl_partition_values_initialize(
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

	partition_values = (libvsbsdl_partition_values_t *) 0x12345678UL;

	result = libvsbsdl_partition_values_initialize(
	          &partition_values,
	          &error );

	partition_values = NULL;

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
		/* Test libvsbsdl_partition_values_initialize with malloc failing
		 */
		vsbsdl_test_malloc_attempts_before_fail = test_number;

		result = libvsbsdl_partition_values_initialize(
		          &partition_values,
		          &error );

		if( vsbsdl_test_malloc_attempts_before_fail != -1 )
		{
			vsbsdl_test_malloc_attempts_before_fail = -1;

			if( partition_values != NULL )
			{
				libvsbsdl_partition_values_free(
				 &partition_values,
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
			 "partition_values",
			 partition_values );

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
		/* Test libvsbsdl_partition_values_initialize with memset failing
		 */
		vsbsdl_test_memset_attempts_before_fail = test_number;

		result = libvsbsdl_partition_values_initialize(
		          &partition_values,
		          &error );

		if( vsbsdl_test_memset_attempts_before_fail != -1 )
		{
			vsbsdl_test_memset_attempts_before_fail = -1;

			if( partition_values != NULL )
			{
				libvsbsdl_partition_values_free(
				 &partition_values,
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
			 "partition_values",
			 partition_values );

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
	if( partition_values != NULL )
	{
		libvsbsdl_partition_values_free(
		 &partition_values,
		 NULL );
	}
	return( 0 );
}

/* Tests the libvsbsdl_partition_values_free function
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_partition_values_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libvsbsdl_partition_values_free(
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

/* Tests the libvsbsdl_partition_values_get_type function
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_partition_values_get_type(
     void )
{
	libcerror_error_t *error                      = NULL;
	libvsbsdl_partition_values_t *partition_values = NULL;
	uint8_t type                                  = 0;
	int result                                    = 0;

	/* Initialize test
	 */
	result = libvsbsdl_partition_values_initialize(
	          &partition_values,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "partition_values",
	 partition_values );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libvsbsdl_partition_values_get_type(
	          partition_values,
	          &type,
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
	result = libvsbsdl_partition_values_get_type(
	          NULL,
	          &type,
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

	result = libvsbsdl_partition_values_get_type(
	          partition_values,
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

	/* Clean up
	 */
	result = libvsbsdl_partition_values_free(
	          &partition_values,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "partition_values",
	 partition_values );

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
	if( partition_values != NULL )
	{
		libvsbsdl_partition_values_free(
		 &partition_values,
		 NULL );
	}
	return( 0 );
}

/* Tests the libvsbsdl_partition_values_get_sector_number function
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_partition_values_get_sector_number(
     void )
{
	libcerror_error_t *error                      = NULL;
	libvsbsdl_partition_values_t *partition_values = NULL;
	uint32_t sector_number                        = 0;
	int result                                    = 0;

	/* Initialize test
	 */
	result = libvsbsdl_partition_values_initialize(
	          &partition_values,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "partition_values",
	 partition_values );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libvsbsdl_partition_values_get_sector_number(
	          partition_values,
	          &sector_number,
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
	result = libvsbsdl_partition_values_get_sector_number(
	          NULL,
	          &sector_number,
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

	result = libvsbsdl_partition_values_get_sector_number(
	          partition_values,
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

	/* Clean up
	 */
	result = libvsbsdl_partition_values_free(
	          &partition_values,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "partition_values",
	 partition_values );

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
	if( partition_values != NULL )
	{
		libvsbsdl_partition_values_free(
		 &partition_values,
		 NULL );
	}
	return( 0 );
}

/* Tests the libvsbsdl_partition_values_get_number_of_sectors function
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_partition_values_get_number_of_sectors(
     void )
{
	libcerror_error_t *error                      = NULL;
	libvsbsdl_partition_values_t *partition_values = NULL;
	uint32_t number_of_sectors                    = 0;
	int result                                    = 0;

	/* Initialize test
	 */
	result = libvsbsdl_partition_values_initialize(
	          &partition_values,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "partition_values",
	 partition_values );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libvsbsdl_partition_values_get_number_of_sectors(
	          partition_values,
	          &number_of_sectors,
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
	result = libvsbsdl_partition_values_get_number_of_sectors(
	          NULL,
	          &number_of_sectors,
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

	result = libvsbsdl_partition_values_get_number_of_sectors(
	          partition_values,
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

	/* Clean up
	 */
	result = libvsbsdl_partition_values_free(
	          &partition_values,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "partition_values",
	 partition_values );

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
	if( partition_values != NULL )
	{
		libvsbsdl_partition_values_free(
		 &partition_values,
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
	 "libvsbsdl_partition_values_initialize",
	 vsbsdl_test_partition_values_initialize );

	VSBSDL_TEST_RUN(
	 "libvsbsdl_partition_values_free",
	 vsbsdl_test_partition_values_free );

	VSBSDL_TEST_RUN(
	 "libvsbsdl_partition_values_get_type",
	 vsbsdl_test_partition_values_get_type );

	VSBSDL_TEST_RUN(
	 "libvsbsdl_partition_values_get_sector_number",
	 vsbsdl_test_partition_values_get_sector_number );

	VSBSDL_TEST_RUN(
	 "libvsbsdl_partition_values_get_number_of_sectors",
	 vsbsdl_test_partition_values_get_number_of_sectors );

#endif /* defined( __GNUC__ ) && !defined( LIBVSBSDL_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

#if defined( __GNUC__ ) && !defined( LIBVSBSDL_DLL_IMPORT )

on_error:
	return( EXIT_FAILURE );

#endif /* defined( __GNUC__ ) && !defined( LIBVSBSDL_DLL_IMPORT ) */
}

