/*
 * Tools signal functions test program
 *
 * Copyright (C) 2023-2024, Joachim Metz <joachim.metz@gmail.com>
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
#include "vsbsdl_test_macros.h"
#include "vsbsdl_test_unused.h"

#include "../vsbsdltools/vsbsdltools_signal.h"

void vsbsdl_test_tools_signal_handler_function(
      vsbsdltools_signal_t signal VSBSDL_TEST_ATTRIBUTE_UNUSED )
{
	VSBSDL_TEST_UNREFERENCED_PARAMETER( signal )
}

#if defined( WINAPI )

/* Tests the vsbsdltools_signal_handler function
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_tools_signal_handler(
     void )
{
	BOOL result = 0;

	/* Test regular cases
	 */
	result = vsbsdltools_signal_handler(
	          CTRL_C_EVENT );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 (int) TRUE );

	result = vsbsdltools_signal_handler(
	          CTRL_LOGOFF_EVENT );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 (int) FALSE );

	return( 1 );

on_error:
	return( 0 );
}

#if defined( _MSC_VER )

	/* TODO add tests for vsbsdltools_signal_initialize_memory_debug */

#endif /* defined( _MSC_VER ) */

#endif /* defined( WINAPI ) */

/* Tests the vsbsdltools_signal_attach function
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_tools_signal_attach(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = vsbsdltools_signal_attach(
	          vsbsdl_test_tools_signal_handler_function,
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
	result = vsbsdltools_signal_attach(
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

/* Tests the vsbsdltools_signal_detach function
 * Returns 1 if successful or 0 if not
 */
int vsbsdl_test_tools_signal_detach(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = vsbsdltools_signal_detach(
	          &error );

	VSBSDL_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

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
	return( 0 );
}

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

#if defined( WINAPI )

	VSBSDL_TEST_RUN(
	 "vsbsdltools_signal_handler",
	 vsbsdl_test_tools_signal_handler )

#if defined( _MSC_VER )

	/* TODO add tests for vsbsdltools_signal_initialize_memory_debug */

#endif /* defined( _MSC_VER ) */

#endif /* defined( WINAPI ) */

	VSBSDL_TEST_RUN(
	 "vsbsdltools_signal_attach",
	 vsbsdl_test_tools_signal_attach )

	VSBSDL_TEST_RUN(
	 "vsbsdltools_signal_detach",
	 vsbsdl_test_tools_signal_detach )

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

