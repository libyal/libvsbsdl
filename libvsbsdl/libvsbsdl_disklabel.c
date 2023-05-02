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

#include <common.h>
#include <byte_stream.h>
#include <memory.h>
#include <types.h>

#include "libvsbsdl_disklabel.h"
#include "libvsbsdl_libbfio.h"
#include "libvsbsdl_libcdata.h"
#include "libvsbsdl_libcerror.h"
#include "libvsbsdl_libcnotify.h"
#include "libvsbsdl_partition_entry.h"

#include "vsbsdl_disklabel.h"
#include "vsbsdl_partition_entry.h"

/* Creates a disklabel
 * Make sure the value disklabel is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libvsbsdl_disklabel_initialize(
     libvsbsdl_disklabel_t **disklabel,
     libcerror_error_t **error )
{
	static char *function = "libvsbsdl_disklabel_initialize";

	if( disklabel == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid disklabel.",
		 function );

		return( -1 );
	}
	if( *disklabel != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid disklabel value already set.",
		 function );

		return( -1 );
	}
	*disklabel = memory_allocate_structure(
	              libvsbsdl_disklabel_t );

	if( *disklabel == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create disklabel.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *disklabel,
	     0,
	     sizeof( libvsbsdl_disklabel_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear disklabel.",
		 function );

		memory_free(
		 *disklabel );

		*disklabel = NULL;

		return( -1 );
	}
	if( libcdata_array_initialize(
	     &( ( *disklabel )->partition_entries ),
	     0,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
		 "%s: unable to create partition entries array.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *disklabel != NULL )
	{
		memory_free(
		 *disklabel );

		*disklabel = NULL;
	}
	return( -1 );
}

/* Frees a disklabel
 * Returns 1 if successful or -1 on error
 */
int libvsbsdl_disklabel_free(
     libvsbsdl_disklabel_t **disklabel,
     libcerror_error_t **error )
{
	static char *function = "libvsbsdl_disklabel_free";
	int result            = 1;

	if( disklabel == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid disklabel.",
		 function );

		return( -1 );
	}
	if( *disklabel != NULL )
	{
		if( libcdata_array_free(
		     &( ( *disklabel )->partition_entries ),
		     (int (*)(intptr_t **, libcerror_error_t **)) &libvsbsdl_partition_entry_free,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
			 "%s: unable to free the partition entries array.",
			 function );

			result = -1;
		}
		memory_free(
		 *disklabel );

		*disklabel = NULL;
	}
	return( result );
}

/* Reads a disklabel
 * Returns 1 if successful or -1 on error
 */
int libvsbsdl_disklabel_read_data(
     libvsbsdl_disklabel_t *disklabel,
     const uint8_t *data,
     size_t data_size,
     libcerror_error_t **error )
{
	libvsbsdl_partition_entry_t *partition_entry = NULL;
	static char *function                        = "libvsbsdl_disklabel_read_data";
	size_t data_offset                           = 0;
	uint16_t number_of_partition_entries         = 0;
	uint16_t partition_entry_index               = 0;
	int entry_index                              = 0;

#if defined( HAVE_DEBUG_OUTPUT )
	uint32_t value_32bit                         = 0;
	uint16_t value_16bit                         = 0;
#endif

	if( disklabel == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid disklabel.",
		 function );

		return( -1 );
	}
	if( data == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid data.",
		 function );

		return( -1 );
	}
	if( ( data_size < sizeof( vsmbr_disklabel_header_t ) )
	 || ( data_size > (size_t) SSIZE_MAX ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid data size value out of bounds.",
		 function );

		return( -1 );
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: disklabel data:\n",
		 function );
		libcnotify_print_data(
		 data,
		 data_size,
		 LIBCNOTIFY_PRINT_DATA_FLAG_GROUP_DATA );
	}
#endif
	if( memory_compare(
	     ( (vsmbr_disklabel_header_t *) data )->signature1,
	     "WEV\x82",
	     4 ) != 0 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_UNSUPPORTED_VALUE,
		 "%s: invalid signature.",
		 function );

		return( -1 );
	}
	if( memory_compare(
	     ( (vsmbr_disklabel_header_t *) data )->signature2,
	     "WEV\x82",
	     4 ) != 0 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_UNSUPPORTED_VALUE,
		 "%s: invalid signature.",
		 function );

		return( -1 );
	}
	byte_stream_copy_to_uint32_little_endian(
	 ( (vsmbr_disklabel_header_t *) data )->bytes_per_sector,
	 disklabel->bytes_per_sector );

	byte_stream_copy_to_uint16_little_endian(
	 ( (vsmbr_disklabel_header_t *) data )->number_of_partition_entries,
	 number_of_partition_entries );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: signature1\t\t\t\t: %c%c%c\\x%02" PRIx8 "\n",
		 function,
		 ( (vsmbr_disklabel_header_t *) data )->signature1[ 0 ],
		 ( (vsmbr_disklabel_header_t *) data )->signature1[ 1 ],
		 ( (vsmbr_disklabel_header_t *) data )->signature1[ 2 ],
		 ( (vsmbr_disklabel_header_t *) data )->signature1[ 3 ] );

		byte_stream_copy_to_uint16_little_endian(
		 ( (vsmbr_disklabel_header_t *) data )->drive_type,
		 value_16bit );
		libcnotify_printf(
		 "%s: drive type\t\t\t\t: %" PRIu16 "\n",
		 function,
		 value_16bit );

		byte_stream_copy_to_uint16_little_endian(
		 ( (vsmbr_disklabel_header_t *) data )->drive_sub_type,
		 value_16bit );
		libcnotify_printf(
		 "%s: drive sub type\t\t\t\t: %" PRIu16 "\n",
		 function,
		 value_16bit );

		libcnotify_printf(
		 "%s: drive type name:\n",
		 function );
		libcnotify_print_data(
		 ( (vsmbr_disklabel_header_t *) data )->drive_type_name,
		 16,
		 0 );

		libcnotify_printf(
		 "%s: unknown1:\n",
		 function );
		libcnotify_print_data(
		 ( (vsmbr_disklabel_header_t *) data )->unknown1,
		 16,
		 0 );

		libcnotify_printf(
		 "%s: bytes per sector\t\t\t\t: %" PRIu32 "\n",
		 function,
		 disklabel->bytes_per_sector );

		byte_stream_copy_to_uint32_little_endian(
		 ( (vsmbr_disklabel_header_t *) data )->sectors_per_track,
		 value_32bit );
		libcnotify_printf(
		 "%s: sectors per track\t\t\t: %" PRIu32 "\n",
		 function,
		 value_32bit );

		byte_stream_copy_to_uint32_little_endian(
		 ( (vsmbr_disklabel_header_t *) data )->tracks_per_cylinder,
		 value_32bit );
		libcnotify_printf(
		 "%s: tracks per cylinder\t\t\t: %" PRIu32 "\n",
		 function,
		 value_32bit );

		byte_stream_copy_to_uint32_little_endian(
		 ( (vsmbr_disklabel_header_t *) data )->cylinders_per_unit,
		 value_32bit );
		libcnotify_printf(
		 "%s: cylinders per unit\t\t\t: %" PRIu32 "\n",
		 function,
		 value_32bit );

		byte_stream_copy_to_uint32_little_endian(
		 ( (vsmbr_disklabel_header_t *) data )->sectors_per_cylinder,
		 value_32bit );
		libcnotify_printf(
		 "%s: sectors per cylinder\t\t\t: %" PRIu32 "\n",
		 function,
		 value_32bit );

		byte_stream_copy_to_uint32_little_endian(
		 ( (vsmbr_disklabel_header_t *) data )->sectors_per_unit,
		 value_32bit );
		libcnotify_printf(
		 "%s: sectors per unit\t\t\t\t: %" PRIu32 "\n",
		 function,
		 value_32bit );

		byte_stream_copy_to_uint16_little_endian(
		 ( (vsmbr_disklabel_header_t *) data )->spare_sectors_per_track,
		 value_16bit );
		libcnotify_printf(
		 "%s: spare sectors per track\t\t\t: %" PRIu16 "\n",
		 function,
		 value_16bit );

		byte_stream_copy_to_uint16_little_endian(
		 ( (vsmbr_disklabel_header_t *) data )->spare_sectors_per_cylinder,
		 value_16bit );
		libcnotify_printf(
		 "%s: spare sectors per cylinder\t\t: %" PRIu16 "\n",
		 function,
		 value_16bit );

		byte_stream_copy_to_uint32_little_endian(
		 ( (vsmbr_disklabel_header_t *) data )->alternate_sectors_per_unit,
		 value_32bit );
		libcnotify_printf(
		 "%s: alternate sectors per unit\t\t: %" PRIu32 "\n",
		 function,
		 value_32bit );

		byte_stream_copy_to_uint16_little_endian(
		 ( (vsmbr_disklabel_header_t *) data )->unknown2,
		 value_16bit );
		libcnotify_printf(
		 "%s: unknown2\t\t\t\t\t: 0x%04" PRIx16 "\n",
		 function,
		 value_16bit );

		byte_stream_copy_to_uint16_little_endian(
		 ( (vsmbr_disklabel_header_t *) data )->unknown3,
		 value_16bit );
		libcnotify_printf(
		 "%s: unknown3\t\t\t\t\t: 0x%04" PRIx16 "\n",
		 function,
		 value_16bit );

		byte_stream_copy_to_uint16_little_endian(
		 ( (vsmbr_disklabel_header_t *) data )->unknown4,
		 value_16bit );
		libcnotify_printf(
		 "%s: unknown4\t\t\t\t\t: 0x%04" PRIx16 "\n",
		 function,
		 value_16bit );

		byte_stream_copy_to_uint16_little_endian(
		 ( (vsmbr_disklabel_header_t *) data )->unknown5,
		 value_16bit );
		libcnotify_printf(
		 "%s: unknown5\t\t\t\t\t: 0x%04" PRIx16 "\n",
		 function,
		 value_16bit );

		byte_stream_copy_to_uint32_little_endian(
		 ( (vsmbr_disklabel_header_t *) data )->unknown6,
		 value_32bit );
		libcnotify_printf(
		 "%s: unknown6\t\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

		byte_stream_copy_to_uint32_little_endian(
		 ( (vsmbr_disklabel_header_t *) data )->unknown7,
		 value_32bit );
		libcnotify_printf(
		 "%s: unknown7\t\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

		byte_stream_copy_to_uint32_little_endian(
		 ( (vsmbr_disklabel_header_t *) data )->flags,
		 value_32bit );
		libcnotify_printf(
		 "%s: flags\t\t\t\t\t: 0x%08" PRIx32 "\n",
		 function,
		 value_32bit );

		libcnotify_printf(
		 "%s: unknown8:\n",
		 function );
		libcnotify_print_data(
		 ( (vsmbr_disklabel_header_t *) data )->unknown8,
		 20,
		 0 );

		libcnotify_printf(
		 "%s: unknown9:\n",
		 function );
		libcnotify_print_data(
		 ( (vsmbr_disklabel_header_t *) data )->unknown9,
		 20,
		 0 );

		libcnotify_printf(
		 "%s: signature2\t\t\t\t: %c%c%c\\x%02" PRIx8 "\n",
		 function,
		 ( (vsmbr_disklabel_header_t *) data )->signature2[ 0 ],
		 ( (vsmbr_disklabel_header_t *) data )->signature2[ 1 ],
		 ( (vsmbr_disklabel_header_t *) data )->signature2[ 2 ],
		 ( (vsmbr_disklabel_header_t *) data )->signature2[ 3 ] );

		byte_stream_copy_to_uint16_little_endian(
		 ( (vsmbr_disklabel_header_t *) data )->checksum,
		 value_16bit );
		libcnotify_printf(
		 "%s: checksum\t\t\t\t\t: 0x%04" PRIx16 "\n",
		 function,
		 value_16bit );

		libcnotify_printf(
		 "%s: number of partition entries\t\t: %" PRIu16 "\n",
		 function,
		 number_of_partition_entries );

		byte_stream_copy_to_uint32_little_endian(
		 ( (vsmbr_disklabel_header_t *) data )->boot_area_size,
		 value_32bit );
		libcnotify_printf(
		 "%s: boot area size\t\t\t\t: %" PRIu32 "\n",
		 function,
		 value_32bit );

		byte_stream_copy_to_uint32_little_endian(
		 ( (vsmbr_disklabel_header_t *) data )->maximum_superblock_size,
		 value_32bit );
		libcnotify_printf(
		 "%s: maximum superblock size\t\t\t: %" PRIu32 "\n",
		 function,
		 value_32bit );

		libcnotify_printf(
		 "\n" );
	}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

	data_offset = sizeof( vsmbr_disklabel_header_t );

	if( ( number_of_partition_entries != 8 )
	 && ( number_of_partition_entries != 16 ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported number of partition entries value.",
		 function );

		return( -1 );
	}
	if( number_of_partition_entries > ( ( data_size - data_offset ) / sizeof( vsbsdl_partition_entry_t ) ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid number of partition entries value out of bounds.",
		 function );

		return( -1 );
	}
	for( partition_entry_index = 0;
	     partition_entry_index < number_of_partition_entries;
	     partition_entry_index++ )
	{
		if( libvsbsdl_partition_entry_initialize(
		     &partition_entry,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
			 "%s: unable to create partition entry: %" PRIu16 ".",
			 function,
			 partition_entry_index );

			goto on_error;
		}
		partition_entry->index = partition_entry_index;

		if( libvsbsdl_partition_entry_read_data(
		     partition_entry,
		     &( data[ data_offset ] ),
		     sizeof( vsbsdl_partition_entry_t ),
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_IO,
			 LIBCERROR_IO_ERROR_READ_FAILED,
			 "%s: unable to read partition entry: %" PRIu16 " data.",
			 function,
			 partition_entry_index );

			goto on_error;
		}
		if( partition_entry->number_of_sectors == 0 )
		{
			if( libvsbsdl_partition_entry_free(
			     &partition_entry,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
				 "%s: unable to free partition entry: %" PRIu16 ".",
				 function,
				 partition_entry_index );

				goto on_error;
			}
		}
		else
		{
			if( libcdata_array_append_entry(
			     disklabel->partition_entries,
			     &entry_index,
			     (intptr_t *) partition_entry,
			     error ) != 1 )
			{
				libcerror_error_set(
				 error,
				 LIBCERROR_ERROR_DOMAIN_RUNTIME,
				 LIBCERROR_RUNTIME_ERROR_APPEND_FAILED,
				 "%s: unable to append partition entry: %" PRIu16 " to array.",
				 function,
				 partition_entry_index );

				goto on_error;
			}
			partition_entry->index = partition_entry_index;

			partition_entry = NULL;
		}
		data_offset += sizeof( vsbsdl_partition_entry_t );
	}
	return( 1 );

on_error:
	if( partition_entry != NULL )
	{
		libvsbsdl_partition_entry_free(
		 &partition_entry,
		 NULL );
	}
	libcdata_array_empty(
	 disklabel->partition_entries,
	 (int (*)(intptr_t **, libcerror_error_t **)) &libvsbsdl_partition_entry_free,
	 NULL );

	return( -1 );
}

/* Reads a disklabel
 * Returns 1 if successful or -1 on error
 */
int libvsbsdl_disklabel_read_file_io_handle(
     libvsbsdl_disklabel_t *disklabel,
     libbfio_handle_t *file_io_handle,
     off64_t file_offset,
     libcerror_error_t **error )
{
	uint8_t disklabel_data[ 512 ];

	static char *function = "libvsbsdl_disklabel_read_file_io_handle";
	ssize_t read_count    = 0;

	if( disklabel == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid disklabel.",
		 function );

		return( -1 );
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: reading disklabel at offset: %" PRIi64 " (0x%08" PRIx64 ").\n",
		 function,
		 file_offset,
		 file_offset );
	}
#endif
	read_count = libbfio_handle_read_buffer_at_offset(
	              file_io_handle,
	              disklabel_data,
	              512,
	              file_offset,
	              error );

	if( read_count != (ssize_t) 512 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_IO,
		 LIBCERROR_IO_ERROR_READ_FAILED,
		 "%s: unable to read disklabel data at offset: %" PRIi64 " (0x%08" PRIx64 ").",
		 function,
		 file_offset,
		 file_offset );

		return( -1 );
	}
	if( libvsbsdl_disklabel_read_data(
	     disklabel,
	     disklabel_data,
	     512,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_IO,
		 LIBCERROR_IO_ERROR_READ_FAILED,
		 "%s: unable to read disklabel.",
		 function );

		return( -1 );
	}
	return( 1 );
}

/* Retrieves the bytes per sector
 * Returns 1 if successful or -1 on error
 */
int libvsbsdl_disklabel_get_bytes_per_sector(
     libvsbsdl_disklabel_t *disklabel,
     uint32_t *bytes_per_sector,
     libcerror_error_t **error )
{
	static char *function = "libvsbsdl_disklabel_get_bytes_per_sector";

	if( disklabel == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid disklabel.",
		 function );

		return( -1 );
	}
	if( bytes_per_sector == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid bytes per sector.",
		 function );

		return( -1 );
	}
	*bytes_per_sector = disklabel->bytes_per_sector;

	return( 1 );
}

/* Retrieves the number of partition entries
 * Returns 1 if successful or -1 on error
 */
int libvsbsdl_disklabel_get_number_of_partition_entries(
     libvsbsdl_disklabel_t *disklabel,
     int *number_of_partition_entries,
     libcerror_error_t **error )
{
	static char *function = "libvsbsdl_disklabel_get_number_of_partition_entries";

	if( disklabel == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid disklabel.",
		 function );

		return( -1 );
	}
	if( libcdata_array_get_number_of_entries(
	     disklabel->partition_entries,
	     number_of_partition_entries,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve number of partition entries from array.",
		 function );

		return( -1 );
	}
	return( 1 );
}

/* Retrieves a specific partition entry
 * Returns 1 if successful or -1 on error
 */
int libvsbsdl_disklabel_get_partition_entry_by_index(
     libvsbsdl_disklabel_t *disklabel,
     int partition_entry_index,
     libvsbsdl_partition_entry_t **partition_entry,
     libcerror_error_t **error )
{
	static char *function = "libvsbsdl_disklabel_get_partition_entry_by_index";

	if( disklabel == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid disklabel.",
		 function );

		return( -1 );
	}
	if( libcdata_array_get_entry_by_index(
	     disklabel->partition_entries,
	     partition_entry_index,
	     (intptr_t **) partition_entry,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve partition entry: %d from array.",
		 function,
		 partition_entry_index );

		return( -1 );
	}
	return( 1 );
}

