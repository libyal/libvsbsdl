/*
 * The volume functions
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

#if !defined( _LIBVSBSDL_VOLUME_H )
#define _LIBVSBSDL_VOLUME_H

#include <common.h>
#include <types.h>

#include "libvsbsdl_disklabel.h"
#include "libvsbsdl_extern.h"
#include "libvsbsdl_io_handle.h"
#include "libvsbsdl_libbfio.h"
#include "libvsbsdl_libcdata.h"
#include "libvsbsdl_libcerror.h"
#include "libvsbsdl_libcthreads.h"
#include "libvsbsdl_types.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libvsbsdl_internal_volume libvsbsdl_internal_volume_t;

struct libvsbsdl_internal_volume
{
	/* The volume size
	 */
	size64_t size;

	/* The disklabel
	 */
	libvsbsdl_disklabel_t *disklabel;

	/* The IO handle
	 */
	libvsbsdl_io_handle_t *io_handle;

	/* The file IO handle
	 */
	libbfio_handle_t *file_io_handle;

	/* Value to indicate if the file IO handle was created inside the library
	 */
	uint8_t file_io_handle_created_in_library;

	/* Value to indicate if the file IO handle was opened inside the library
	 */
	uint8_t file_io_handle_opened_in_library;

#if defined( HAVE_LIBVSBSDL_MULTI_THREAD_SUPPORT )
	/* The read/write lock
	 */
	libcthreads_read_write_lock_t *read_write_lock;
#endif
};

LIBVSBSDL_EXTERN \
int libvsbsdl_volume_initialize(
     libvsbsdl_volume_t **volume,
     libcerror_error_t **error );

LIBVSBSDL_EXTERN \
int libvsbsdl_volume_free(
     libvsbsdl_volume_t **volume,
     libcerror_error_t **error );

LIBVSBSDL_EXTERN \
int libvsbsdl_volume_signal_abort(
     libvsbsdl_volume_t *volume,
     libcerror_error_t **error );

LIBVSBSDL_EXTERN \
int libvsbsdl_volume_open(
     libvsbsdl_volume_t *volume,
     char const *filename,
     int access_flags,
     libcerror_error_t **error );

#if defined( HAVE_WIDE_CHARACTER_TYPE )

LIBVSBSDL_EXTERN \
int libvsbsdl_volume_open_wide(
     libvsbsdl_volume_t *volume,
     wchar_t const *filename,
     int access_flags,
     libcerror_error_t **error );

#endif /* defined( HAVE_WIDE_CHARACTER_TYPE ) */

LIBVSBSDL_EXTERN \
int libvsbsdl_volume_open_file_io_handle(
     libvsbsdl_volume_t *volume,
     libbfio_handle_t *file_io_handle,
     int access_flags,
     libcerror_error_t **error );

LIBVSBSDL_EXTERN \
int libvsbsdl_volume_close(
     libvsbsdl_volume_t *volume,
     libcerror_error_t **error );

int libvsbsdl_internal_volume_open_read(
     libvsbsdl_internal_volume_t *internal_volume,
     libbfio_handle_t *file_io_handle,
     libcerror_error_t **error );

LIBVSBSDL_EXTERN \
int libvsbsdl_volume_get_bytes_per_sector(
     libvsbsdl_volume_t *volume,
     uint32_t *bytes_per_sector,
     libcerror_error_t **error );

LIBVSBSDL_EXTERN \
int libvsbsdl_volume_get_number_of_partitions(
     libvsbsdl_volume_t *volume,
     int *number_of_partitions,
     libcerror_error_t **error );

LIBVSBSDL_EXTERN \
int libvsbsdl_volume_get_partition_by_index(
     libvsbsdl_volume_t *volume,
     int partition_index,
     libvsbsdl_partition_t **partition,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBVSBSDL_VOLUME_H ) */

