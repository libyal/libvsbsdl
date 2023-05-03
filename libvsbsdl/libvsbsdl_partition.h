/*
 * The partition functions
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

#if !defined( _LIBVSBSDL_PARTITION_H )
#define _LIBVSBSDL_PARTITION_H

#include <common.h>
#include <types.h>

#include "libvsbsdl_extern.h"
#include "libvsbsdl_io_handle.h"
#include "libvsbsdl_libbfio.h"
#include "libvsbsdl_libcerror.h"
#include "libvsbsdl_libcthreads.h"
#include "libvsbsdl_libfcache.h"
#include "libvsbsdl_libfdata.h"
#include "libvsbsdl_partition_entry.h"
#include "libvsbsdl_types.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libvsbsdl_internal_partition libvsbsdl_internal_partition_t;

struct libvsbsdl_internal_partition
{
	/* The file IO handle
	 */
	libbfio_handle_t *file_io_handle;

	/* The partition entry
	 */
	libvsbsdl_partition_entry_t *partition_entry;

	/* The sectors vector
	 */
	libfdata_vector_t *sectors_vector;

	/* The sectors cache
	 */
	libfcache_cache_t *sectors_cache;

	/* The current offset
	 */
	off64_t current_offset;

	/* The offset
	 */
	off64_t offset;

	/* The size
	 */
	size64_t size;

#if defined( HAVE_MULTI_THREAD_SUPPORT )
	/* The read/write lock
	 */
	libcthreads_read_write_lock_t *read_write_lock;
#endif
};

int libvsbsdl_partition_initialize(
     libvsbsdl_partition_t **partition,
     libvsbsdl_io_handle_t *io_handle,
     libbfio_handle_t *file_io_handle,
     libvsbsdl_partition_entry_t *partition_entry,
     libcerror_error_t **error );

LIBVSBSDL_EXTERN \
int libvsbsdl_partition_free(
     libvsbsdl_partition_t **partition,
     libcerror_error_t **error );

LIBVSBSDL_EXTERN \
int libvsbsdl_partition_get_entry_index(
     libvsbsdl_partition_t *partition,
     uint16_t *entry_index,
     libcerror_error_t **error );

LIBVSBSDL_EXTERN \
int libvsbsdl_partition_get_name_string(
     libvsbsdl_partition_t *partition,
     char *string,
     size_t string_size,
     libcerror_error_t **error );

LIBVSBSDL_EXTERN \
int libvsbsdl_partition_get_volume_offset(
     libvsbsdl_partition_t *partition,
     off64_t *volume_offset,
     libcerror_error_t **error );

ssize_t libvsbsdl_internal_partition_read_buffer_from_file_io_handle(
         libvsbsdl_internal_partition_t *internal_partition,
         libbfio_handle_t *file_io_handle,
         void *buffer,
         size_t buffer_size,
         libcerror_error_t **error );

LIBVSBSDL_EXTERN \
ssize_t libvsbsdl_partition_read_buffer(
         libvsbsdl_partition_t *partition,
         void *buffer,
         size_t buffer_size,
         libcerror_error_t **error );

LIBVSBSDL_EXTERN \
ssize_t libvsbsdl_partition_read_buffer_at_offset(
         libvsbsdl_partition_t *partition,
         void *buffer,
         size_t buffer_size,
         off64_t offset,
         libcerror_error_t **error );

off64_t libvsbsdl_internal_partition_seek_offset(
         libvsbsdl_internal_partition_t *internal_partition,
         off64_t offset,
         int whence,
         libcerror_error_t **error );

LIBVSBSDL_EXTERN \
off64_t libvsbsdl_partition_seek_offset(
         libvsbsdl_partition_t *partition,
         off64_t offset,
         int whence,
         libcerror_error_t **error );

LIBVSBSDL_EXTERN \
int libvsbsdl_partition_get_offset(
     libvsbsdl_partition_t *partition,
     off64_t *offset,
     libcerror_error_t **error );

LIBVSBSDL_EXTERN \
int libvsbsdl_partition_get_size(
     libvsbsdl_partition_t *partition,
     size64_t *size,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBVSBSDL_PARTITION_H ) */

