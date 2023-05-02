/*
 * Library volume type test program
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
#include <narrow_string.h>
#include <system_string.h>
#include <types.h>
#include <wide_string.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "vsbsdl_test_functions.h"
#include "vsbsdl_test_getopt.h"
#include "vsbsdl_test_libbfio.h"
#include "vsbsdl_test_libcerror.h"
#include "vsbsdl_test_libvsbsdl.h"
#include "vsbsdl_test_macros.h"
#include "vsbsdl_test_memory.h"
#include "vsbsdl_test_unused.h"

#if defined( __GNUC__ ) && !defined( LIBVSBSDL_DLL_IMPORT )
#include "../libvsbsdl/libvsbsdl_volume.h"
#endif

#if defined( HAVE_WIDE_SYSTEM_CHARACTER ) && SIZEOF_WCHAR_T != 2 && SIZEOF_WCHAR_T != 4
#error Unsupported size of wchar_t
#endif

/* Define to make vsbsdl_test_volume generate verbose output
#define VSBSDL_TEST_VOLUME_VERBOSE
 */

#if !defined( LIBVSBSDL_HAVE_BFIO )

LIBVSBSDL_EXTERN \
int libvsbsdl_check_volume_signature_file_io_handle(
     libbfio_handle_t *file_io_handle,
     libcerror_error_t **error );

LIBVSBSDL_EXTERN \
int libvsbsdl_volume_open_file_io_handle(
     libvsbsdl_volume_t *volume,
     libbfio_handle_t *file_io_handle,
     int access_flags,
     libvsbsdl_error_t **error );

#endif /* !defined( LIBVSBSDL_HAVE_BFIO ) */

/* Creates and opens a source volume
 * Returns 1 if successful or -1 on error
 */
int vsbsdl_test_volume_open_source(
     libvsbsdl_volume_t **volume,
     libbfio_handle_t *file_io_handle,
     libcerror_error_t **error )
{
	static char *function = "vsbsdl_test_volume_open_source";
	int result            = 0;

	if( volume == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid volume.",
		 function );

		return( -1 );
	}
	if( file_io_handle == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid file IO handle.",
		 function );

		return( -1 );
	}
	if( libvsbsdl_volume_initialize(
	     volume,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
		 "%s: unable to initialize volume.",
		 function );

		goto on_error;
	}
	result = libvsbsdl_volume_open_file_io_handle(
	          *volume,
	          file_io_handle,
	          LIBVSBSDL_OPEN_READ,
	          error );

	if( result != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_IO,
		 LIBCERROR_IO_ERROR_OPEN_FAILED,
		 "%s: unable to open volume.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *volume != NULL )
	{
		libvsbsdl_volume_free(
		 volume,
		 NULL );
	}
	return( -1 );
}

/* Closes and frees a source volume
 * Returns 1 if successful or -1 on error
 */
int vsbsdl_test_volume_close_source(
     libvsbsdl_volume_t **volume,
     libcerror_error_t **error )
{
	static char *function = "vsbsdl_test_volume_close_source";
	int result            = 0;

	if( volume == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid volume.",
		 function );

		return( -1 );
	}
	if( libvsbsdl_volume_close(
	     *volume,
	     error ) != 0 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_IO,
		 LIBCERROR_IO_ERROR_CLOSE_FAILED,
		 "%s: unable to close volume.",
		 function );

		result = -1;
	}
	if( libvsbsdl_volume_free(
	     volume,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
		 "%s: unable to free volume.",
		 function );

		result = -1;
	}
	return( result );
}

/* Tests the libvsbsdl_volume_initialize function
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_volume_initialize(
     void )
{
	libcerror_error_t *error        = NULL;
	libvsbsdl_volume_t *volume       = NULL;
	int result                      = 0;

#if defined( HAVE_VSBSDL_TEST_MEMORY )
	int number_of_malloc_fail_tests = 3;
	int number_of_memset_fail_tests = 1;
	int test_number                 = 0;
#endif

	/* Test regular cases
	 */
	result = libvsbsdl_volume_initialize(
	          &volume,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "volume",
	 volume );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libvsbsdl_volume_free(
	          &volume,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "volume",
	 volume );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libvsbsdl_volume_initialize(
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

	volume = (libvsbsdl_volume_t *) 0x12345678UL;

	result = libvsbsdl_volume_initialize(
	          &volume,
	          &error );

	volume = NULL;

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
		/* Test libvsbsdl_volume_initialize with malloc failing
		 */
		vsbsdl_test_malloc_attempts_before_fail = test_number;

		result = libvsbsdl_volume_initialize(
		          &volume,
		          &error );

		if( vsbsdl_test_malloc_attempts_before_fail != -1 )
		{
			vsbsdl_test_malloc_attempts_before_fail = -1;

			if( volume != NULL )
			{
				libvsbsdl_volume_free(
				 &volume,
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
			 "volume",
			 volume );

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
		/* Test libvsbsdl_volume_initialize with memset failing
		 */
		vsbsdl_test_memset_attempts_before_fail = test_number;

		result = libvsbsdl_volume_initialize(
		          &volume,
		          &error );

		if( vsbsdl_test_memset_attempts_before_fail != -1 )
		{
			vsbsdl_test_memset_attempts_before_fail = -1;

			if( volume != NULL )
			{
				libvsbsdl_volume_free(
				 &volume,
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
			 "volume",
			 volume );

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
	if( volume != NULL )
	{
		libvsbsdl_volume_free(
		 &volume,
		 NULL );
	}
	return( 0 );
}

/* Tests the libvsbsdl_volume_free function
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_volume_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libvsbsdl_volume_free(
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

/* Tests the libvsbsdl_volume_open function
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_volume_open(
     const system_character_t *source )
{
	char narrow_source[ 256 ];

	libcerror_error_t *error  = NULL;
	libvsbsdl_volume_t *volume = NULL;
	int result                = 0;

	/* Initialize test
	 */
	result = vsbsdl_test_get_narrow_source(
	          source,
	          narrow_source,
	          256,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libvsbsdl_volume_initialize(
	          &volume,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "volume",
	 volume );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test open
	 */
	result = libvsbsdl_volume_open(
	          volume,
	          narrow_source,
	          LIBVSBSDL_OPEN_READ,
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
	result = libvsbsdl_volume_open(
	          NULL,
	          narrow_source,
	          LIBVSBSDL_OPEN_READ,
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

	result = libvsbsdl_volume_open(
	          volume,
	          NULL,
	          LIBVSBSDL_OPEN_READ,
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

	result = libvsbsdl_volume_open(
	          volume,
	          narrow_source,
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

	/* Test open when already opened
	 */
	result = libvsbsdl_volume_open(
	          volume,
	          narrow_source,
	          LIBVSBSDL_OPEN_READ,
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
	result = libvsbsdl_volume_free(
	          &volume,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "volume",
	 volume );

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
	if( volume != NULL )
	{
		libvsbsdl_volume_free(
		 &volume,
		 NULL );
	}
	return( 0 );
}

#if defined( HAVE_WIDE_CHARACTER_TYPE )

/* Tests the libvsbsdl_volume_open_wide function
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_volume_open_wide(
     const system_character_t *source )
{
	wchar_t wide_source[ 256 ];

	libcerror_error_t *error  = NULL;
	libvsbsdl_volume_t *volume = NULL;
	int result                = 0;

	/* Initialize test
	 */
	result = vsbsdl_test_get_wide_source(
	          source,
	          wide_source,
	          256,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libvsbsdl_volume_initialize(
	          &volume,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "volume",
	 volume );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test open
	 */
	result = libvsbsdl_volume_open_wide(
	          volume,
	          wide_source,
	          LIBVSBSDL_OPEN_READ,
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
	result = libvsbsdl_volume_open_wide(
	          NULL,
	          wide_source,
	          LIBVSBSDL_OPEN_READ,
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

	result = libvsbsdl_volume_open_wide(
	          volume,
	          NULL,
	          LIBVSBSDL_OPEN_READ,
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

	result = libvsbsdl_volume_open_wide(
	          volume,
	          wide_source,
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

	/* Test open when already opened
	 */
	result = libvsbsdl_volume_open_wide(
	          volume,
	          wide_source,
	          LIBVSBSDL_OPEN_READ,
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
	result = libvsbsdl_volume_free(
	          &volume,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "volume",
	 volume );

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
	if( volume != NULL )
	{
		libvsbsdl_volume_free(
		 &volume,
		 NULL );
	}
	return( 0 );
}

#endif /* defined( HAVE_WIDE_CHARACTER_TYPE ) */

/* Tests the libvsbsdl_volume_open_file_io_handle function
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_volume_open_file_io_handle(
     const system_character_t *source )
{
	libbfio_handle_t *file_io_handle = NULL;
	libcerror_error_t *error         = NULL;
	libvsbsdl_volume_t *volume        = NULL;
	size_t string_length             = 0;
	int result                       = 0;

	/* Initialize test
	 */
	result = libbfio_file_initialize(
	          &file_io_handle,
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

	string_length = system_string_length(
	                 source );

#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
	result = libbfio_file_set_name_wide(
	          file_io_handle,
	          source,
	          string_length,
	          &error );
#else
	result = libbfio_file_set_name(
	          file_io_handle,
	          source,
	          string_length,
	          &error );
#endif
	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        VSBSDL_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libvsbsdl_volume_initialize(
	          &volume,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "volume",
	 volume );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test open
	 */
	result = libvsbsdl_volume_open_file_io_handle(
	          volume,
	          file_io_handle,
	          LIBVSBSDL_OPEN_READ,
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
	result = libvsbsdl_volume_open_file_io_handle(
	          NULL,
	          file_io_handle,
	          LIBVSBSDL_OPEN_READ,
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

	result = libvsbsdl_volume_open_file_io_handle(
	          volume,
	          NULL,
	          LIBVSBSDL_OPEN_READ,
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

	result = libvsbsdl_volume_open_file_io_handle(
	          volume,
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

	/* Test open when already opened
	 */
	result = libvsbsdl_volume_open_file_io_handle(
	          volume,
	          file_io_handle,
	          LIBVSBSDL_OPEN_READ,
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
	result = libvsbsdl_volume_free(
	          &volume,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "volume",
	 volume );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libbfio_handle_free(
	          &file_io_handle,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
         "file_io_handle",
         file_io_handle );

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
	if( volume != NULL )
	{
		libvsbsdl_volume_free(
		 &volume,
		 NULL );
	}
	if( file_io_handle != NULL )
	{
		libbfio_handle_free(
		 &file_io_handle,
		 NULL );
	}
	return( 0 );
}

/* Tests the libvsbsdl_volume_close function
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_volume_close(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libvsbsdl_volume_close(
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

/* Tests the libvsbsdl_volume_open and libvsbsdl_volume_close functions
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_volume_open_close(
     const system_character_t *source )
{
	libcerror_error_t *error  = NULL;
	libvsbsdl_volume_t *volume = NULL;
	int result                = 0;

	/* Initialize test
	 */
	result = libvsbsdl_volume_initialize(
	          &volume,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "volume",
	 volume );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test open and close
	 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
	result = libvsbsdl_volume_open_wide(
	          volume,
	          source,
	          LIBVSBSDL_OPEN_READ,
	          &error );
#else
	result = libvsbsdl_volume_open(
	          volume,
	          source,
	          LIBVSBSDL_OPEN_READ,
	          &error );
#endif

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libvsbsdl_volume_close(
	          volume,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test open and close a second time to validate clean up on close
	 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
	result = libvsbsdl_volume_open_wide(
	          volume,
	          source,
	          LIBVSBSDL_OPEN_READ,
	          &error );
#else
	result = libvsbsdl_volume_open(
	          volume,
	          source,
	          LIBVSBSDL_OPEN_READ,
	          &error );
#endif

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libvsbsdl_volume_close(
	          volume,
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
	result = libvsbsdl_volume_free(
	          &volume,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "volume",
	 volume );

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
	if( volume != NULL )
	{
		libvsbsdl_volume_free(
		 &volume,
		 NULL );
	}
	return( 0 );
}

/* Tests the libvsbsdl_volume_signal_abort function
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_volume_signal_abort(
     libvsbsdl_volume_t *volume )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = libvsbsdl_volume_signal_abort(
	          volume,
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
	result = libvsbsdl_volume_signal_abort(
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

/* Tests the libvsbsdl_volume_get_bytes_per_sector function
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_volume_get_bytes_per_sector(
     libvsbsdl_volume_t *volume )
{
	libcerror_error_t *error  = NULL;
	uint32_t bytes_per_sector = 0;
	int result                = 0;

	/* Test regular cases
	 */
	result = libvsbsdl_volume_get_bytes_per_sector(
	          volume,
	          &bytes_per_sector,
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
	result = libvsbsdl_volume_get_bytes_per_sector(
	          NULL,
	          &bytes_per_sector,
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

	result = libvsbsdl_volume_get_bytes_per_sector(
	          volume,
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

/* Tests the libvsbsdl_volume_get_number_of_partitions function
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_volume_get_number_of_partitions(
     libvsbsdl_volume_t *volume )
{
	libcerror_error_t *error = NULL;
	int number_of_partitions = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libvsbsdl_volume_get_number_of_partitions(
	          volume,
	          &number_of_partitions,
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
	result = libvsbsdl_volume_get_number_of_partitions(
	          NULL,
	          &number_of_partitions,
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

	result = libvsbsdl_volume_get_number_of_partitions(
	          volume,
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

/* Tests the libvsbsdl_volume_get_partition_by_index function
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_volume_get_partition_by_index(
     libvsbsdl_volume_t *volume )
{
	libcerror_error_t *error                 = NULL;
	libvsbsdl_partition_t *partition_by_index = 0;
	int number_of_partitions                 = 0;
	int result                               = 0;

	/* Test regular cases
	 */
	result = libvsbsdl_volume_get_number_of_partitions(
	          volume,
	          &number_of_partitions,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	if( number_of_partitions == 0 )
	{
		return( 1 );
	}
	result = libvsbsdl_volume_get_partition_by_index(
	          volume,
	          0,
	          &partition_by_index,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "partition_by_index",
	 partition_by_index );

	result = libvsbsdl_partition_free(
	          &partition_by_index,
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
	result = libvsbsdl_volume_get_partition_by_index(
	          NULL,
	          0,
	          &partition_by_index,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "partition_by_index",
	 partition_by_index );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libvsbsdl_volume_get_partition_by_index(
	          volume,
	          -1,
	          &partition_by_index,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "partition_by_index",
	 partition_by_index );

	VSBSDL_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libvsbsdl_volume_get_partition_by_index(
	          volume,
	          0,
	          NULL,
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	VSBSDL_TEST_ASSERT_IS_NULL(
	 "partition_by_index",
	 partition_by_index );

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

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc,
     wchar_t * const argv[] )
#else
int main(
     int argc,
     char * const argv[] )
#endif
{
	libbfio_handle_t *file_io_handle = NULL;
	libcerror_error_t *error         = NULL;
	libvsbsdl_volume_t *volume        = NULL;
	system_character_t *source       = NULL;
	system_integer_t option          = 0;
	size_t string_length             = 0;
	int result                       = 0;

	while( ( option = vsbsdl_test_getopt(
	                   argc,
	                   argv,
	                   _SYSTEM_STRING( "" ) ) ) != (system_integer_t) -1 )
	{
		switch( option )
		{
			case (system_integer_t) '?':
			default:
				fprintf(
				 stderr,
				 "Invalid argument: %" PRIs_SYSTEM ".\n",
				 argv[ optind - 1 ] );

				return( EXIT_FAILURE );
		}
	}
	if( optind < argc )
	{
		source = argv[ optind ];
	}
#if defined( HAVE_DEBUG_OUTPUT ) && defined( VSBSDL_TEST_VOLUME_VERBOSE )
	libvsbsdl_notify_set_verbose(
	 1 );
	libvsbsdl_notify_set_stream(
	 stderr,
	 NULL );
#endif

	VSBSDL_TEST_RUN(
	 "libvsbsdl_volume_initialize",
	 vsbsdl_test_volume_initialize );

	VSBSDL_TEST_RUN(
	 "libvsbsdl_volume_free",
	 vsbsdl_test_volume_free );

#if !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 )
	if( source != NULL )
	{
		result = libbfio_file_initialize(
		          &file_io_handle,
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

		string_length = system_string_length(
		                 source );

#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
		result = libbfio_file_set_name_wide(
		          file_io_handle,
		          source,
		          string_length,
		          &error );
#else
		result = libbfio_file_set_name(
		          file_io_handle,
		          source,
		          string_length,
		          &error );
#endif
		VSBSDL_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

	        VSBSDL_TEST_ASSERT_IS_NULL(
	         "error",
	         error );

		result = libvsbsdl_check_volume_signature_file_io_handle(
		          file_io_handle,
		          &error );

		VSBSDL_TEST_ASSERT_NOT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		VSBSDL_TEST_ASSERT_IS_NULL(
		 "error",
		 error );
	}
	if( result != 0 )
	{
		VSBSDL_TEST_RUN_WITH_ARGS(
		 "libvsbsdl_volume_open",
		 vsbsdl_test_volume_open,
		 source );

#if defined( HAVE_WIDE_CHARACTER_TYPE )

		VSBSDL_TEST_RUN_WITH_ARGS(
		 "libvsbsdl_volume_open_wide",
		 vsbsdl_test_volume_open_wide,
		 source );

#endif /* defined( HAVE_WIDE_CHARACTER_TYPE ) */

		VSBSDL_TEST_RUN_WITH_ARGS(
		 "libvsbsdl_volume_open_file_io_handle",
		 vsbsdl_test_volume_open_file_io_handle,
		 source );

		VSBSDL_TEST_RUN(
		 "libvsbsdl_volume_close",
		 vsbsdl_test_volume_close );

		VSBSDL_TEST_RUN_WITH_ARGS(
		 "libvsbsdl_volume_open_close",
		 vsbsdl_test_volume_open_close,
		 source );

		/* Initialize volume for tests
		 */
		result = vsbsdl_test_volume_open_source(
		          &volume,
		          file_io_handle,
		          &error );

		VSBSDL_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		VSBSDL_TEST_ASSERT_IS_NOT_NULL(
		 "volume",
		 volume );

		VSBSDL_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		VSBSDL_TEST_RUN_WITH_ARGS(
		 "libvsbsdl_volume_signal_abort",
		 vsbsdl_test_volume_signal_abort,
		 volume );

#if defined( __GNUC__ ) && !defined( LIBVSBSDL_DLL_IMPORT )

		/* TODO: add tests for libvsbsdl_volume_open_read */

		/* TODO: add tests for libvsbsdl_volume_read_partition_entries */

#endif /* defined( __GNUC__ ) && !defined( LIBVSBSDL_DLL_IMPORT ) */

		VSBSDL_TEST_RUN_WITH_ARGS(
		 "libvsbsdl_volume_get_bytes_per_sector",
		 vsbsdl_test_volume_get_bytes_per_sector,
		 volume );

		VSBSDL_TEST_RUN_WITH_ARGS(
		 "libvsbsdl_volume_get_number_of_partitions",
		 vsbsdl_test_volume_get_number_of_partitions,
		 volume );

		VSBSDL_TEST_RUN_WITH_ARGS(
		 "libvsbsdl_volume_get_partition_by_index",
		 vsbsdl_test_volume_get_partition_by_index,
		 volume );

		/* Clean up
		 */
		result = vsbsdl_test_volume_close_source(
		          &volume,
		          &error );

		VSBSDL_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 0 );

		VSBSDL_TEST_ASSERT_IS_NULL(
		 "volume",
		 volume );

		VSBSDL_TEST_ASSERT_IS_NULL(
		 "error",
		 error );
	}
	if( file_io_handle != NULL )
	{
		result = libbfio_handle_free(
		          &file_io_handle,
		          &error );

		VSBSDL_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		VSBSDL_TEST_ASSERT_IS_NULL(
	         "file_io_handle",
	         file_io_handle );

	        VSBSDL_TEST_ASSERT_IS_NULL(
	         "error",
	         error );
	}
#endif /* !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 ) */

	return( EXIT_SUCCESS );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( volume != NULL )
	{
		libvsbsdl_volume_free(
		 &volume,
		 NULL );
	}
	if( file_io_handle != NULL )
	{
		libbfio_handle_free(
		 &file_io_handle,
		 NULL );
	}
	return( EXIT_FAILURE );
}

