/*
 * The partition entry functions
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

#include "libvsbsdl_debug.h"
#include "libvsbsdl_definitions.h"
#include "libvsbsdl_libcerror.h"
#include "libvsbsdl_libcnotify.h"
#include "libvsbsdl_partition_entry.h"

#include "vsbsdl_partition_entry.h"

/* Creates a partition entry
 * Make sure the value partition_entry is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libvsbsdl_partition_entry_initialize(
     libvsbsdl_partition_entry_t **partition_entry,
     libcerror_error_t **error )
{
	static char *function = "libvsbsdl_partition_entry_initialize";

	if( partition_entry == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid partition entry.",
		 function );

		return( -1 );
	}
	if( *partition_entry != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid partition entry value already set.",
		 function );

		return( -1 );
	}
	*partition_entry = memory_allocate_structure(
	                    libvsbsdl_partition_entry_t );

	if( *partition_entry == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create partition entry.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     *partition_entry,
	     0,
	     sizeof( libvsbsdl_partition_entry_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear partition entry.",
		 function );

		goto on_error;
	}
	return( 1 );

on_error:
	if( *partition_entry != NULL )
	{
		memory_free(
		 *partition_entry );

		*partition_entry = NULL;
	}
	return( -1 );
}

/* Frees a partition entry
 * Returns 1 if successful or -1 on error
 */
int libvsbsdl_partition_entry_free(
     libvsbsdl_partition_entry_t **partition_entry,
     libcerror_error_t **error )
{
	static char *function = "libvsbsdl_partition_entry_free";

	if( partition_entry == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid partition entry.",
		 function );

		return( -1 );
	}
	if( *partition_entry != NULL )
	{
		memory_free(
		 *partition_entry );

		*partition_entry = NULL;
	}
	return( 1 );
}

/* Reads a partition entry
 * Returns 1 if successful or -1 on error
 */
int libvsbsdl_partition_entry_read_data(
     libvsbsdl_partition_entry_t *partition_entry,
     const uint8_t *data,
     size_t data_size,
     libcerror_error_t **error )
{
	static char *function = "libvsbsdl_partition_entry_read_data";

#if defined( HAVE_DEBUG_OUTPUT )
	uint32_t value_32bit  = 0;
	uint16_t value_16bit  = 0;
#endif

	if( partition_entry == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid partition entry.",
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
	if( data_size != sizeof( vsbsdl_partition_entry_t) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: data size value out of bounds.",
		 function );

		return( -1 );
	}
#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: entry data:\n",
		 function );
		libcnotify_print_data(
		 data,
		 sizeof( vsbsdl_partition_entry_t ),
		 0 );
	}
#endif
	byte_stream_copy_to_uint32_little_endian(
	 ( (vsbsdl_partition_entry_t *) data )->number_of_sectors,
	 partition_entry->number_of_sectors );

	byte_stream_copy_to_uint32_little_endian(
	 ( (vsbsdl_partition_entry_t *) data )->start_sector,
	 partition_entry->start_sector );

#if defined( HAVE_DEBUG_OUTPUT )
	if( libcnotify_verbose != 0 )
	{
		libcnotify_printf(
		 "%s: number of sectors\t\t\t: %" PRIu32 "\n",
		 function,
		 partition_entry->number_of_sectors );

		libcnotify_printf(
		 "%s: start sector\t\t\t: %" PRIu32 "\n",
		 function,
		 partition_entry->start_sector );

		byte_stream_copy_to_uint32_little_endian(
		 ( (vsbsdl_partition_entry_t *) data )->fragment_size,
		 value_32bit );
		libcnotify_printf(
		 "%s: fragment size\t\t\t: %" PRIu32 "\n",
		 function,
		 value_32bit );

		libcnotify_printf(
		 "%s: file system type\t\t\t: %" PRIu8 "\n",
		 function,
		 ( (vsbsdl_partition_entry_t *) data )->file_system_type );

		libcnotify_printf(
		 "%s: fragments per block\t\t: %" PRIu8 "\n",
		 function,
		 ( (vsbsdl_partition_entry_t *) data )->fragments_per_block );

		byte_stream_copy_to_uint16_little_endian(
		 ( (vsbsdl_partition_entry_t *) data )->unknown1,
		 value_16bit );
		libcnotify_printf(
		 "%s: unknown1\t\t\t\t: 0x%04" PRIx16 "\n",
		 function,
		 value_16bit );

		libcnotify_printf(
		 "\n" );
	}
#endif /* defined( HAVE_DEBUG_OUTPUT ) */

	return( 1 );
}

/* Retrieves the partition entry index
 * Returns 1 if successful or -1 on error
 */
int libvsbsdl_partition_entry_get_entry_index(
     libvsbsdl_partition_entry_t *partition_entry,
     uint16_t *entry_index,
     libcerror_error_t **error )
{
	static char *function = "libvsbsdl_partition_entry_get_entry_index";

	if( partition_entry == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid partition entry.",
		 function );

		return( -1 );
	}
	if( entry_index == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid entry_index.",
		 function );

		return( -1 );
	}
	*entry_index = partition_entry->index;

	return( 1 );
}

/* Retrieves the partition start sector
 * Returns 1 if successful or -1 on error
 */
int libvsbsdl_partition_entry_get_start_sector(
     libvsbsdl_partition_entry_t *partition_entry,
     uint32_t *start_sector,
     libcerror_error_t **error )
{
	static char *function = "libvsbsdl_partition_entry_get_start_sector";

	if( partition_entry == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid partition entry.",
		 function );

		return( -1 );
	}
	if( start_sector == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid start sector.",
		 function );

		return( -1 );
	}
	*start_sector = partition_entry->start_sector;

	return( 1 );
}

/* Retrieves the partition number of sectors
 * Returns 1 if successful or -1 on error
 */
int libvsbsdl_partition_entry_get_number_of_sectors(
     libvsbsdl_partition_entry_t *partition_entry,
     uint32_t *number_of_sectors,
     libcerror_error_t **error )
{
	static char *function = "libvsbsdl_partition_entry_get_number_of_sectors";

	if( partition_entry == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid partition entry.",
		 function );

		return( -1 );
	}
	if( number_of_sectors == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid number of sectors.",
		 function );

		return( -1 );
	}
	*number_of_sectors = partition_entry->number_of_sectors;

	return( 1 );
}

