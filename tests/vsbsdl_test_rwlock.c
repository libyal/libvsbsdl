/*
 * Read/Write lock functions for testing
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

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include <errno.h>

#if defined( HAVE_GNU_DL_DLSYM ) && defined( __GNUC__ )
#define __USE_GNU
#include <dlfcn.h>
#undef __USE_GNU
#endif

#include "vsbsdl_test_rwlock.h"

#if defined( HAVE_VSBSDL_TEST_RWLOCK )

static int (*vsbsdl_test_real_pthread_rwlock_init)(pthread_rwlock_t *, const pthread_rwlockattr_t *) = NULL;
static int (*vsbsdl_test_real_pthread_rwlock_destroy)(pthread_rwlock_t *)                            = NULL;
static int (*vsbsdl_test_real_pthread_rwlock_rdlock)(pthread_rwlock_t *)                             = NULL;
static int (*vsbsdl_test_real_pthread_rwlock_wrlock)(pthread_rwlock_t *)                             = NULL;
static int (*vsbsdl_test_real_pthread_rwlock_unlock)(pthread_rwlock_t *)                             = NULL;

int vsbsdl_test_pthread_rwlock_init_attempts_before_fail                                             = -1;
int vsbsdl_test_pthread_rwlock_destroy_attempts_before_fail                                          = -1;
int vsbsdl_test_pthread_rwlock_rdlock_attempts_before_fail                                           = -1;
int vsbsdl_test_pthread_rwlock_wrlock_attempts_before_fail                                           = -1;
int vsbsdl_test_pthread_rwlock_unlock_attempts_before_fail                                           = -1;

#if defined( TODO )

/* TODO currently disabled since this causes the tests to segfault on Ubuntu 14.04
 */

/* Custom pthread_rwlock_init for testing error cases
 * Returns 0 if successful or an error value otherwise
 */
int pthread_rwlock_init(
     pthread_rwlock_t *rwlock,
     const pthread_rwlockattr_t *attr )
{
	int result = 0;

	if( vsbsdl_test_real_pthread_rwlock_init == NULL )
	{
		vsbsdl_test_real_pthread_rwlock_init = dlsym(
		                                       RTLD_NEXT,
		                                       "pthread_rwlock_init" );
	}
	if( vsbsdl_test_pthread_rwlock_init_attempts_before_fail == 0 )
	{
		vsbsdl_test_pthread_rwlock_init_attempts_before_fail = -1;

		return( EBUSY );
	}
	else if( vsbsdl_test_pthread_rwlock_init_attempts_before_fail > 0 )
	{
		vsbsdl_test_pthread_rwlock_init_attempts_before_fail--;
	}
	result = vsbsdl_test_real_pthread_rwlock_init(
	          rwlock,
	          attr );

	return( result );
}

#endif /* defined( TODO ) */

/* Custom pthread_rwlock_destroy for testing error cases
 * Returns 0 if successful or an error value otherwise
 */
int pthread_rwlock_destroy(
     pthread_rwlock_t *rwlock )
{
	int result = 0;

	if( vsbsdl_test_real_pthread_rwlock_destroy == NULL )
	{
		vsbsdl_test_real_pthread_rwlock_destroy = dlsym(
		                                          RTLD_NEXT,
		                                          "pthread_rwlock_destroy" );
	}
	if( vsbsdl_test_pthread_rwlock_destroy_attempts_before_fail == 0 )
	{
		vsbsdl_test_pthread_rwlock_destroy_attempts_before_fail = -1;

		return( EBUSY );
	}
	else if( vsbsdl_test_pthread_rwlock_destroy_attempts_before_fail > 0 )
	{
		vsbsdl_test_pthread_rwlock_destroy_attempts_before_fail--;
	}
	result = vsbsdl_test_real_pthread_rwlock_destroy(
	          rwlock );

	return( result );
}

/* Custom pthread_rwlock_rdlock for testing error cases
 * Returns 0 if successful or an error value otherwise
 */
int pthread_rwlock_rdlock(
     pthread_rwlock_t *rwlock )
{
	int result = 0;

	if( vsbsdl_test_real_pthread_rwlock_rdlock == NULL )
	{
		vsbsdl_test_real_pthread_rwlock_rdlock = dlsym(
		                                         RTLD_NEXT,
		                                         "pthread_rwlock_rdlock" );
	}
	if( vsbsdl_test_pthread_rwlock_rdlock_attempts_before_fail == 0 )
	{
		vsbsdl_test_pthread_rwlock_rdlock_attempts_before_fail = -1;

		return( EBUSY );
	}
	else if( vsbsdl_test_pthread_rwlock_rdlock_attempts_before_fail > 0 )
	{
		vsbsdl_test_pthread_rwlock_rdlock_attempts_before_fail--;
	}
	result = vsbsdl_test_real_pthread_rwlock_rdlock(
	          rwlock );

	return( result );
}

/* Custom pthread_rwlock_wrlock for testing error cases
 * Returns 0 if successful or an error value otherwise
 */
int pthread_rwlock_wrlock(
     pthread_rwlock_t *rwlock )
{
	int result = 0;

	if( vsbsdl_test_real_pthread_rwlock_wrlock == NULL )
	{
		vsbsdl_test_real_pthread_rwlock_wrlock = dlsym(
		                                         RTLD_NEXT,
		                                         "pthread_rwlock_wrlock" );
	}
	if( vsbsdl_test_pthread_rwlock_wrlock_attempts_before_fail == 0 )
	{
		vsbsdl_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		return( EBUSY );
	}
	else if( vsbsdl_test_pthread_rwlock_wrlock_attempts_before_fail > 0 )
	{
		vsbsdl_test_pthread_rwlock_wrlock_attempts_before_fail--;
	}
	result = vsbsdl_test_real_pthread_rwlock_wrlock(
	          rwlock );

	return( result );
}

/* Custom pthread_rwlock_unlock for testing error cases
 * Returns 0 if successful or an error value otherwise
 */
int pthread_rwlock_unlock(
     pthread_rwlock_t *rwlock )
{
	int result = 0;

	if( vsbsdl_test_real_pthread_rwlock_unlock == NULL )
	{
		vsbsdl_test_real_pthread_rwlock_unlock = dlsym(
		                                         RTLD_NEXT,
		                                         "pthread_rwlock_unlock" );
	}
	if( vsbsdl_test_pthread_rwlock_unlock_attempts_before_fail == 0 )
	{
		/* Unlock the lock otherwise it can enter a nondeterministic state
		 */
		vsbsdl_test_real_pthread_rwlock_unlock(
		 rwlock );

		vsbsdl_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		return( EBUSY );
	}
	else if( vsbsdl_test_pthread_rwlock_unlock_attempts_before_fail > 0 )
	{
		vsbsdl_test_pthread_rwlock_unlock_attempts_before_fail--;
	}
	result = vsbsdl_test_real_pthread_rwlock_unlock(
	          rwlock );

	return( result );
}

#endif /* defined( HAVE_VSBSDL_TEST_RWLOCK ) */

