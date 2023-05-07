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

#include <common.h>
#include <memory.h>
#include <types.h>

#include "libvsbsdl_definitions.h"
#include "libvsbsdl_io_handle.h"
#include "libvsbsdl_libbfio.h"
#include "libvsbsdl_libcerror.h"
#include "libvsbsdl_libcthreads.h"
#include "libvsbsdl_libfcache.h"
#include "libvsbsdl_libfdata.h"
#include "libvsbsdl_partition.h"
#include "libvsbsdl_partition_entry.h"
#include "libvsbsdl_sector_data.h"
#include "libvsbsdl_types.h"
#include "libvsbsdl_unused.h"

/* Creates a partition
 * Make sure the value partition is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
int libvsbsdl_partition_initialize(
     libvsbsdl_partition_t **partition,
     libvsbsdl_io_handle_t *io_handle,
     libbfio_handle_t *file_io_handle,
     libvsbsdl_partition_entry_t *partition_entry,
     libcerror_error_t **error )
{
	libvsbsdl_internal_partition_t *internal_partition = NULL;
	static char *function                              = "libvsbsdl_partition_initialize";
	size64_t partition_size                            = 0;
	off64_t partition_offset                           = 0;
	int element_index                                  = 0;

	if( partition == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid partition.",
		 function );

		return( -1 );
	}
	if( *partition != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid partition value already set.",
		 function );

		return( -1 );
	}
	if( io_handle == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid IO handle.",
		 function );

		return( -1 );
	}
	if( io_handle->bytes_per_sector == 0 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid IO handle - bytes per sector value out of bounds.",
		 function );

		return( -1 );
	}
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
	internal_partition = memory_allocate_structure(
	                      libvsbsdl_internal_partition_t );

	if( internal_partition == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
		 "%s: unable to create partition.",
		 function );

		goto on_error;
	}
	if( memory_set(
	     internal_partition,
	     0,
	     sizeof( libvsbsdl_internal_partition_t ) ) == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_MEMORY,
		 LIBCERROR_MEMORY_ERROR_SET_FAILED,
		 "%s: unable to clear partition.",
		 function );

		memory_free(
		 internal_partition );

		return( -1 );
	}
	if( libvsbsdl_partition_entry_get_start_sector(
	     partition_entry,
	     (uint32_t *) &partition_offset,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve partition start sector.",
		 function );

		goto on_error;
	}
	if( partition_offset > ( (off64_t) INT64_MAX / io_handle->bytes_per_sector ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid partition offset value out of bounds.",
		 function );

		goto on_error;
	}
	partition_offset *= io_handle->bytes_per_sector;

	if( libvsbsdl_partition_entry_get_number_of_sectors(
	     partition_entry,
	     (uint32_t *) &partition_size,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve partition number of sectors.",
		 function );

		goto on_error;
	}
	partition_size *= io_handle->bytes_per_sector;

	if( libfdata_vector_initialize(
	     &( internal_partition->sectors_vector ),
	     io_handle->bytes_per_sector,
	     NULL,
	     NULL,
	     NULL,
	     (int (*)(intptr_t *, intptr_t *, libfdata_vector_t *, libfdata_cache_t *, int, int, off64_t, size64_t, uint32_t, uint8_t, libcerror_error_t **)) &libvsbsdl_partition_read_element_data,
	     NULL,
	     LIBFDATA_DATA_HANDLE_FLAG_NON_MANAGED,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
		 "%s: unable to create sectors vector.",
		 function );

		goto on_error;
	}
	if( libfdata_vector_append_segment(
	     internal_partition->sectors_vector,
	     &element_index,
	     0,
	     partition_offset,
	     partition_size,
	     0,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_APPEND_FAILED,
		 "%s: unable to append segment to sectors vector.",
		 function );

		goto on_error;
	}
	if( libfcache_cache_initialize(
	     &( internal_partition->sectors_cache ),
	     LIBVSBSDL_MAXIMUM_CACHE_ENTRIES_SECTORS,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
		 "%s: unable to create sectors cache.",
		 function );

		goto on_error;
	}
#if defined( HAVE_MULTI_THREAD_SUPPORT )
	if( libcthreads_read_write_lock_initialize(
	     &( internal_partition->read_write_lock ),
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
		 "%s: unable to initialize read/write lock.",
		 function );

		goto on_error;
	}
#endif
	internal_partition->file_io_handle  = file_io_handle;
	internal_partition->partition_entry = partition_entry;
	internal_partition->offset          = partition_offset;
	internal_partition->size            = partition_size;

	*partition = (libvsbsdl_partition_t *) internal_partition;

	return( 1 );

on_error:
	if( internal_partition != NULL )
	{
		if( internal_partition->sectors_vector != NULL )
		{
			libfdata_vector_free(
			 &( internal_partition->sectors_vector ),
			 NULL );
		}
		memory_free(
		 internal_partition );
	}
	return( -1 );
}

/* Frees a partition
 * Returns 1 if successful or -1 on error
 */
int libvsbsdl_partition_free(
     libvsbsdl_partition_t **partition,
     libcerror_error_t **error )
{
	libvsbsdl_internal_partition_t *internal_partition = NULL;
	static char *function                              = "libvsbsdl_partition_free";
	int result                                         = 1;

	if( partition == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid partition.",
		 function );

		return( -1 );
	}
	if( *partition != NULL )
	{
		internal_partition = (libvsbsdl_internal_partition_t *) *partition;
		*partition         = NULL;

		/* The file_io_handle and partition_entry references are freed elsewhere
		 */
		if( libfdata_vector_free(
		     &( internal_partition->sectors_vector ),
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
			 "%s: unable to free sectors vector.",
			 function );

			result = -1;
		}
		if( libfcache_cache_free(
		     &( internal_partition->sectors_cache ),
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
			 "%s: unable to free sectors cache.",
			 function );

			result = -1;
		}
#if defined( HAVE_MULTI_THREAD_SUPPORT )
		if( libcthreads_read_write_lock_free(
		     &( internal_partition->read_write_lock ),
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
			 "%s: unable to free read/write lock.",
			 function );

			result = -1;
		}
#endif
		memory_free(
		 internal_partition );
	}
	return( result );
}

/* Retrieves the partition entry index
 * Returns 1 if successful or -1 on error
 */
int libvsbsdl_partition_get_entry_index(
     libvsbsdl_partition_t *partition,
     uint16_t *entry_index,
     libcerror_error_t **error )
{
	libvsbsdl_internal_partition_t *internal_partition = NULL;
	static char *function                              = "libvsbsdl_partition_get_entry_index";
	int result                                         = 1;

	if( partition == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid partition.",
		 function );

		return( -1 );
	}
	internal_partition = (libvsbsdl_internal_partition_t *) partition;

#if defined( HAVE_MULTI_THREAD_SUPPORT )
	if( libcthreads_read_write_lock_grab_for_read(
	     internal_partition->read_write_lock,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to grab read/write lock for reading.",
		 function );

		return( -1 );
	}
#endif
	if( libvsbsdl_partition_entry_get_entry_index(
	     internal_partition->partition_entry,
	     entry_index,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve entry index.",
		 function );

		result = -1;
	}
#if defined( HAVE_MULTI_THREAD_SUPPORT )
	if( libcthreads_read_write_lock_release_for_read(
	     internal_partition->read_write_lock,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to release read/write lock for reading.",
		 function );

		return( -1 );
	}
#endif
	return( result );
}

/* Retrieves the ASCII encoded string of the partition name
 * Returns 1 if successful or -1 on error
 */
int libvsbsdl_partition_get_name_string(
     libvsbsdl_partition_t *partition,
     char *string,
     size_t string_size,
     libcerror_error_t **error )
{
	libvsbsdl_internal_partition_t *internal_partition = NULL;
	static char *function                              = "libvsbsdl_partition_get_name_string";
	uint16_t entry_index                               = 0;
	int result                                         = 1;

	if( partition == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid partition.",
		 function );

		return( -1 );
	}
	internal_partition = (libvsbsdl_internal_partition_t *) partition;

	if( string == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid string.",
		 function );

		return( -1 );
	}
	if( ( string_size < 2 )
	 || ( string_size > (size_t) SSIZE_MAX ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid string size value out of bounds.",
		 function );

		return( -1 );
	}
#if defined( HAVE_MULTI_THREAD_SUPPORT )
	if( libcthreads_read_write_lock_grab_for_read(
	     internal_partition->read_write_lock,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to grab read/write lock for reading.",
		 function );

		return( -1 );
	}
#endif
	if( libvsbsdl_partition_entry_get_entry_index(
	     internal_partition->partition_entry,
	     &entry_index,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
		 "%s: unable to retrieve entry index.",
		 function );

		result = -1;
	}
	else
	{
		string[ 0 ] = 'a' + (char) entry_index;
		string[ 1 ] = 0;
	}
#if defined( HAVE_MULTI_THREAD_SUPPORT )
	if( libcthreads_read_write_lock_release_for_read(
	     internal_partition->read_write_lock,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to release read/write lock for reading.",
		 function );

		return( -1 );
	}
#endif
	return( result );
}

/* Retrieves the partition offset relative to the start of the volume
 * Returns 1 if successful or -1 on error
 */
int libvsbsdl_partition_get_volume_offset(
     libvsbsdl_partition_t *partition,
     off64_t *volume_offset,
     libcerror_error_t **error )
{
	libvsbsdl_internal_partition_t *internal_partition = NULL;
	static char *function                              = "libvsbsdl_partition_get_volume_offset";

	if( partition == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid partition.",
		 function );

		return( -1 );
	}
	internal_partition = (libvsbsdl_internal_partition_t *) partition;

	if( volume_offset == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid volume offset.",
		 function );

		return( -1 );
	}
#if defined( HAVE_MULTI_THREAD_SUPPORT )
	if( libcthreads_read_write_lock_grab_for_read(
	     internal_partition->read_write_lock,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to grab read/write lock for reading.",
		 function );

		return( -1 );
	}
#endif
	*volume_offset = internal_partition->offset;

#if defined( HAVE_MULTI_THREAD_SUPPORT )
	if( libcthreads_read_write_lock_release_for_read(
	     internal_partition->read_write_lock,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to release read/write lock for reading.",
		 function );

		return( -1 );
	}
#endif
	return( 1 );
}

/* Reads (partition) data at the current offset into a buffer using a Basic File IO (bfio) handle
 * This function is not multi-thread safe acquire write lock before call
 * Returns the number of bytes read or -1 on error
 */
ssize_t libvsbsdl_internal_partition_read_buffer_from_file_io_handle(
         libvsbsdl_internal_partition_t *internal_partition,
         libbfio_handle_t *file_io_handle,
         void *buffer,
         size_t buffer_size,
         libcerror_error_t **error )
{
	libvsbsdl_sector_data_t *sector_data = NULL;
	static char *function                = "libvsbsdl_internal_partition_read_buffer_from_file_io_handle";
	size_t buffer_offset                 = 0;
	size_t read_size                     = 0;
	off64_t current_offset               = 0;
	off64_t element_data_offset          = 0;

	if( internal_partition == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid partition.",
		 function );

		return( -1 );
	}
	if( internal_partition->current_offset < 0 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid partition - current offset value out of bounds.",
		 function );

		return( -1 );
	}
	if( buffer == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid buffer.",
		 function );

		return( -1 );
	}
	if( buffer_size > (size_t) SSIZE_MAX )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: invalid buffer size value exceeds maximum.",
		 function );

		return( -1 );
	}
	if( buffer_size == 0 )
	{
		return( 0 );
	}
	if( (size64_t) internal_partition->current_offset >= internal_partition->size )
	{
		return( 0 );
	}
	if( (size64_t) buffer_size > ( internal_partition->size - internal_partition->current_offset ) )
	{
		buffer_size = (size_t) ( internal_partition->size - internal_partition->current_offset );
	}
	current_offset = internal_partition->current_offset;

	while( buffer_size > 0 )
	{
		if( libfdata_vector_get_element_value_at_offset(
		     internal_partition->sectors_vector,
		     (intptr_t *) file_io_handle,
		     (libfdata_cache_t *) internal_partition->sectors_cache,
		     current_offset,
		     &element_data_offset,
		     (intptr_t **) &sector_data,
		     0,
		     error ) != 1 )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
			 "%s: unable to retrieve sector data at offset: %" PRIi64 " (0x%08" PRIx64 ").",
			 function,
			 current_offset,
			 current_offset );

			return( -1 );
		}
		if( sector_data == NULL )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_VALUE_MISSING,
			 "%s: missing sector data.",
			 function );

			return( -1 );
		}
		read_size = sector_data->data_size - (size_t) element_data_offset;

		if( buffer_size < read_size )
		{
			read_size = buffer_size;
		}
		if( memory_copy(
		     &( ( (uint8_t *) buffer )[ buffer_offset ] ),
		     &( sector_data->data[ element_data_offset ] ),
		     read_size ) == NULL )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_MEMORY,
			 LIBCERROR_MEMORY_ERROR_COPY_FAILED,
			 "%s: unable to copy sector data.",
			 function );

			return( -1 );
		}
		current_offset += read_size;
		buffer_offset  += read_size;
		buffer_size    -= read_size;
	}
	internal_partition->current_offset = current_offset;

	return( (ssize_t) buffer_offset );
}

/* Reads (partition) data at the current offset into a buffer
 * Returns the number of bytes read or -1 on error
 */
ssize_t libvsbsdl_partition_read_buffer(
         libvsbsdl_partition_t *partition,
         void *buffer,
         size_t buffer_size,
         libcerror_error_t **error )
{
	libvsbsdl_internal_partition_t *internal_partition = NULL;
	static char *function                              = "libvsbsdl_partition_read_buffer";
	ssize_t read_count                                 = 0;

	if( partition == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid partition.",
		 function );

		return( -1 );
	}
	internal_partition = (libvsbsdl_internal_partition_t *) partition;

#if defined( HAVE_MULTI_THREAD_SUPPORT )
	if( libcthreads_read_write_lock_grab_for_write(
	     internal_partition->read_write_lock,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to grab read/write lock for writing.",
		 function );

		return( -1 );
	}
#endif
	read_count = libvsbsdl_internal_partition_read_buffer_from_file_io_handle(
		      internal_partition,
		      internal_partition->file_io_handle,
		      buffer,
		      buffer_size,
		      error );

	if( read_count == -1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_IO,
		 LIBCERROR_IO_ERROR_READ_FAILED,
		 "%s: unable to read buffer from partition.",
		 function );

		read_count = -1;
	}
#if defined( HAVE_MULTI_THREAD_SUPPORT )
	if( libcthreads_read_write_lock_release_for_write(
	     internal_partition->read_write_lock,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to release read/write lock for writing.",
		 function );

		return( -1 );
	}
#endif
	return( read_count );
}

/* Reads (partition) data at a specific offset
 * Returns the number of bytes read or -1 on error
 */
ssize_t libvsbsdl_partition_read_buffer_at_offset(
         libvsbsdl_partition_t *partition,
         void *buffer,
         size_t buffer_size,
         off64_t offset,
         libcerror_error_t **error )
{
	libvsbsdl_internal_partition_t *internal_partition = NULL;
	static char *function                              = "libvsbsdl_partition_read_buffer_at_offset";
	ssize_t read_count                                 = 0;

	if( partition == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid partition.",
		 function );

		return( -1 );
	}
	internal_partition = (libvsbsdl_internal_partition_t *) partition;

#if defined( HAVE_MULTI_THREAD_SUPPORT )
	if( libcthreads_read_write_lock_grab_for_write(
	     internal_partition->read_write_lock,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to grab read/write lock for writing.",
		 function );

		return( -1 );
	}
#endif
	if( libvsbsdl_internal_partition_seek_offset(
	     internal_partition,
	     offset,
	     SEEK_SET,
	     error ) == -1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_IO,
		 LIBCERROR_IO_ERROR_SEEK_FAILED,
		 "%s: unable to seek offset.",
		 function );

		goto on_error;
	}
	read_count = libvsbsdl_internal_partition_read_buffer_from_file_io_handle(
		      internal_partition,
		      internal_partition->file_io_handle,
		      buffer,
		      buffer_size,
		      error );

	if( read_count == -1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_IO,
		 LIBCERROR_IO_ERROR_READ_FAILED,
		 "%s: unable to read buffer.",
		 function );

		goto on_error;
	}
#if defined( HAVE_MULTI_THREAD_SUPPORT )
	if( libcthreads_read_write_lock_release_for_write(
	     internal_partition->read_write_lock,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to release read/write lock for writing.",
		 function );

		return( -1 );
	}
#endif
	return( read_count );

on_error:
#if defined( HAVE_MULTI_THREAD_SUPPORT )
	libcthreads_read_write_lock_release_for_write(
	 internal_partition->read_write_lock,
	 NULL );
#endif
	return( -1 );
}

/* Seeks a certain offset of the (partition) data
 * This function is not multi-thread safe acquire write lock before call
 * Returns the offset if seek is successful or -1 on error
 */
off64_t libvsbsdl_internal_partition_seek_offset(
         libvsbsdl_internal_partition_t *internal_partition,
         off64_t offset,
         int whence,
         libcerror_error_t **error )
{
	static char *function = "libvsbsdl_internal_partition_seek_offset";

	if( internal_partition == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid partition.",
		 function );

		return( -1 );
	}
	if( ( whence != SEEK_CUR )
	 && ( whence != SEEK_END )
	 && ( whence != SEEK_SET ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_UNSUPPORTED_VALUE,
		 "%s: unsupported whence.",
		 function );

		return( -1 );
	}
	if( whence == SEEK_CUR )
	{
		offset += internal_partition->current_offset;
	}
	else if( whence == SEEK_END )
	{
		offset += (off64_t) internal_partition->size;
	}
	if( offset < 0 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid offset value out of bounds.",
		 function );

		return( -1 );
	}
	internal_partition->current_offset = offset;

	return( offset );
}

/* Seeks a certain offset of the (partition) data
 * Returns the offset if seek is successful or -1 on error
 */
off64_t libvsbsdl_partition_seek_offset(
         libvsbsdl_partition_t *partition,
         off64_t offset,
         int whence,
         libcerror_error_t **error )
{
	libvsbsdl_internal_partition_t *internal_partition = NULL;
	static char *function                              = "libvsbsdl_partition_seek_offset";

	if( partition == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid partition.",
		 function );

		return( -1 );
	}
	internal_partition = (libvsbsdl_internal_partition_t *) partition;

#if defined( HAVE_MULTI_THREAD_SUPPORT )
	if( libcthreads_read_write_lock_grab_for_write(
	     internal_partition->read_write_lock,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to grab read/write lock for writing.",
		 function );

		return( -1 );
	}
#endif
	offset = libvsbsdl_internal_partition_seek_offset(
	          internal_partition,
	          offset,
	          whence,
	          error );

	if( offset == -1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_IO,
		 LIBCERROR_IO_ERROR_SEEK_FAILED,
		 "%s: unable to seek offset.",
		 function );

		offset = -1;
	}
#if defined( HAVE_MULTI_THREAD_SUPPORT )
	if( libcthreads_read_write_lock_release_for_write(
	     internal_partition->read_write_lock,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to release read/write lock for writing.",
		 function );

		return( -1 );
	}
#endif
	return( offset );
}

/* Retrieves the current offset
 * Returns 1 if successful or -1 on error
 */
int libvsbsdl_partition_get_offset(
     libvsbsdl_partition_t *partition,
     off64_t *offset,
     libcerror_error_t **error )
{
	libvsbsdl_internal_partition_t *internal_partition = NULL;
	static char *function                              = "libvsbsdl_partition_get_offset";

	if( partition == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid partition.",
		 function );

		return( -1 );
	}
	internal_partition = (libvsbsdl_internal_partition_t *) partition;

	if( offset == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid offset.",
		 function );

		return( -1 );
	}
#if defined( HAVE_MULTI_THREAD_SUPPORT )
	if( libcthreads_read_write_lock_grab_for_read(
	     internal_partition->read_write_lock,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to grab read/write lock for reading.",
		 function );

		return( -1 );
	}
#endif
	*offset = internal_partition->current_offset;

#if defined( HAVE_MULTI_THREAD_SUPPORT )
	if( libcthreads_read_write_lock_release_for_read(
	     internal_partition->read_write_lock,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to release read/write lock for reading.",
		 function );

		return( -1 );
	}
#endif
	return( 1 );
}

/* Retrieves the partition size
 * Returns 1 if successful or -1 on error
 */
int libvsbsdl_partition_get_size(
     libvsbsdl_partition_t *partition,
     size64_t *size,
     libcerror_error_t **error )
{
	libvsbsdl_internal_partition_t *internal_partition = NULL;
	static char *function                              = "libvsbsdl_partition_get_size";

	if( partition == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid partition.",
		 function );

		return( -1 );
	}
	internal_partition = (libvsbsdl_internal_partition_t *) partition;

	if( size == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid size.",
		 function );

		return( -1 );
	}
#if defined( HAVE_MULTI_THREAD_SUPPORT )
	if( libcthreads_read_write_lock_grab_for_read(
	     internal_partition->read_write_lock,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to grab read/write lock for reading.",
		 function );

		return( -1 );
	}
#endif
	*size = internal_partition->size;

#if defined( HAVE_MULTI_THREAD_SUPPORT )
	if( libcthreads_read_write_lock_release_for_read(
	     internal_partition->read_write_lock,
	     error ) != 1 )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to release read/write lock for reading.",
		 function );

		return( -1 );
	}
#endif
	return( 1 );
}

