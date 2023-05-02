/*
 * The disklabel functions
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

#if !defined( _LIBVSBSDL_DISK_LABEL_H )
#define _LIBVSBSDL_DISK_LABEL_H

#include <common.h>
#include <types.h>

#include "libvsbsdl_libbfio.h"
#include "libvsbsdl_libcdata.h"
#include "libvsbsdl_libcerror.h"
#include "libvsbsdl_partition_entry.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libvsbsdl_disklabel libvsbsdl_disklabel_t;

struct libvsbsdl_disklabel
{
	/* Number of bytes per sector
	 */
	uint32_t bytes_per_sector;

	/* The partition entries array
	 */
	libcdata_array_t *partition_entries;
};

int libvsbsdl_disklabel_initialize(
     libvsbsdl_disklabel_t **disklabel,
     libcerror_error_t **error );

int libvsbsdl_disklabel_free(
     libvsbsdl_disklabel_t **disklabel,
     libcerror_error_t **error );

int libvsbsdl_disklabel_read_data(
     libvsbsdl_disklabel_t *disklabel,
     const uint8_t *data,
     size_t data_size,
     libcerror_error_t **error );

int libvsbsdl_disklabel_read_file_io_handle(
     libvsbsdl_disklabel_t *disklabel,
     libbfio_handle_t *file_io_handle,
     off64_t file_offset,
     libcerror_error_t **error );

int libvsbsdl_disklabel_get_bytes_per_sector(
     libvsbsdl_disklabel_t *disklabel,
     uint32_t *bytes_per_sector,
     libcerror_error_t **error );

int libvsbsdl_disklabel_get_number_of_partition_entries(
     libvsbsdl_disklabel_t *disklabel,
     int *number_of_partition_entries,
     libcerror_error_t **error );

int libvsbsdl_disklabel_get_partition_entry_by_index(
     libvsbsdl_disklabel_t *disklabel,
     int partition_entry_index,
     libvsbsdl_partition_entry_t **partition_entry,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBVSBSDL_DISK_LABEL_H ) */

