/*
 * Library to access the BSD disklabel volume system
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

#if !defined( _LIBVSBSDL_H )
#define _LIBVSBSDL_H

#include <libvsbsdl/codepage.h>
#include <libvsbsdl/definitions.h>
#include <libvsbsdl/error.h>
#include <libvsbsdl/extern.h>
#include <libvsbsdl/features.h>
#include <libvsbsdl/types.h>

#include <stdio.h>

#if defined( LIBVSBSDL_HAVE_BFIO )
#include <libbfio.h>
#endif

#if defined( __cplusplus )
extern "C" {
#endif

/* -------------------------------------------------------------------------
 * Support functions
 * ------------------------------------------------------------------------- */

/* Returns the library version
 */
LIBVSBSDL_EXTERN \
const char *libvsbsdl_get_version(
             void );

/* Returns the access flags for reading
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_get_access_flags_read(
     void );

/* Returns the access flags for reading and writing
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_get_access_flags_read_write(
     void );

/* Returns the access flags for writing
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_get_access_flags_write(
     void );

/* Retrieves the narrow system string codepage
 * A value of 0 represents no codepage, UTF-8 encoding is used instead
 * Returns 1 if successful or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_get_codepage(
     int *codepage,
     libvsbsdl_error_t **error );

/* Sets the narrow system string codepage
 * A value of 0 represents no codepage, UTF-8 encoding is used instead
 * Returns 1 if successful or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_set_codepage(
     int codepage,
     libvsbsdl_error_t **error );

/* Determines if a volume contains a BSD disklabel signature
 * Returns 1 if true, 0 if not or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_check_volume_signature(
     const char *filename,
     libvsbsdl_error_t **error );

#if defined( LIBVSBSDL_HAVE_WIDE_CHARACTER_TYPE )

/* Determines if a volume contains a BSD disklabel signature
 * Returns 1 if true, 0 if not or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_check_volume_signature_wide(
     const wchar_t *filename,
     libvsbsdl_error_t **error );

#endif /* defined( LIBVSBSDL_HAVE_WIDE_CHARACTER_TYPE ) */

#if defined( LIBVSBSDL_HAVE_BFIO )

/* Determines if a volume contains a BSD disklabel signature using a Basic File IO (bfio) handle
 * Returns 1 if true, 0 if not or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_check_volume_signature_file_io_handle(
     libbfio_handle_t *file_io_handle,
     libvsbsdl_error_t **error );

#endif /* defined( LIBVSBSDL_HAVE_BFIO ) */

/* -------------------------------------------------------------------------
 * Notify functions
 * ------------------------------------------------------------------------- */

/* Sets the verbose notification
 */
LIBVSBSDL_EXTERN \
void libvsbsdl_notify_set_verbose(
      int verbose );

/* Sets the notification stream
 * Returns 1 if successful or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_notify_set_stream(
     FILE *stream,
     libvsbsdl_error_t **error );

/* Opens the notification stream using a filename
 * The stream is opened in append mode
 * Returns 1 if successful or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_notify_stream_open(
     const char *filename,
     libvsbsdl_error_t **error );

/* Closes the notification stream if opened using a filename
 * Returns 0 if successful or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_notify_stream_close(
     libvsbsdl_error_t **error );

/* -------------------------------------------------------------------------
 * Error functions
 * ------------------------------------------------------------------------- */

/* Frees an error
 */
LIBVSBSDL_EXTERN \
void libvsbsdl_error_free(
      libvsbsdl_error_t **error );

/* Prints a descriptive string of the error to the stream
 * Returns the number of printed characters if successful or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_error_fprint(
     libvsbsdl_error_t *error,
     FILE *stream );

/* Prints a descriptive string of the error to the string
 * The end-of-string character is not included in the return value
 * Returns the number of printed characters if successful or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_error_sprint(
     libvsbsdl_error_t *error,
     char *string,
     size_t size );

/* Prints a backtrace of the error to the stream
 * Returns the number of printed characters if successful or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_error_backtrace_fprint(
     libvsbsdl_error_t *error,
     FILE *stream );

/* Prints a backtrace of the error to the string
 * The end-of-string character is not included in the return value
 * Returns the number of printed characters if successful or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_error_backtrace_sprint(
     libvsbsdl_error_t *error,
     char *string,
     size_t size );

/* -------------------------------------------------------------------------
 * Volume functions
 * ------------------------------------------------------------------------- */

/* Creates a volume
 * Make sure the value volume is referencing, is set to NULL
 * Returns 1 if successful or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_volume_initialize(
     libvsbsdl_volume_t **volume,
     libvsbsdl_error_t **error );

/* Frees a volume
 * Returns 1 if successful or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_volume_free(
     libvsbsdl_volume_t **volume,
     libvsbsdl_error_t **error );

/* Signals a volume to abort its current activity
 * Returns 1 if successful or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_volume_signal_abort(
     libvsbsdl_volume_t *volume,
     libvsbsdl_error_t **error );

/* Opens a volume
 * Returns 1 if successful or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_volume_open(
     libvsbsdl_volume_t *volume,
     const char *filename,
     int access_flags,
     libvsbsdl_error_t **error );

#if defined( LIBVSBSDL_HAVE_WIDE_CHARACTER_TYPE )

/* Opens a volume
 * Returns 1 if successful or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_volume_open_wide(
     libvsbsdl_volume_t *volume,
     const wchar_t *filename,
     int access_flags,
     libvsbsdl_error_t **error );

#endif /* defined( LIBVSBSDL_HAVE_WIDE_CHARACTER_TYPE ) */

#if defined( LIBVSBSDL_HAVE_BFIO )

/* Opens a volume using a Basic File IO (bfio) handle
 * Returns 1 if successful or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_volume_open_file_io_handle(
     libvsbsdl_volume_t *volume,
     libbfio_handle_t *file_io_handle,
     int access_flags,
     libvsbsdl_error_t **error );

#endif /* defined( LIBVSBSDL_HAVE_BFIO ) */

/* Closes a volume
 * Returns 0 if successful or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_volume_close(
     libvsbsdl_volume_t *volume,
     libvsbsdl_error_t **error );

/* Retrieves the number of bytes per sector
 * Returns 1 if successful or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_volume_get_bytes_per_sector(
     libvsbsdl_volume_t *volume,
     uint32_t *bytes_per_sector,
     libvsbsdl_error_t **error );

/* Retrieves the number of partitions
 * Returns 1 if successful or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_volume_get_number_of_partitions(
     libvsbsdl_volume_t *volume,
     int *number_of_partitions,
     libvsbsdl_error_t **error );

/* Retrieves a specific partition
 * Returns 1 if successful or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_volume_get_partition_by_index(
     libvsbsdl_volume_t *volume,
     int partition_index,
     libvsbsdl_partition_t **partition,
     libvsbsdl_error_t **error );

/* -------------------------------------------------------------------------
 * Partition functions
 * ------------------------------------------------------------------------- */

/* Frees a partition
 * Returns 1 if successful or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_partition_free(
     libvsbsdl_partition_t **partition,
     libvsbsdl_error_t **error );

/* Retrieves the partition entry index
 * Returns 1 if successful or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_partition_get_entry_index(
     libvsbsdl_partition_t *partition,
     uint16_t *entry_index,
     libvsbsdl_error_t **error );

/* Retrieves the ASCII encoded string of the partition name
 * Returns 1 if successful or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_partition_get_name_string(
     libvsbsdl_partition_t *partition,
     char *string,
     size_t string_size,
     libvsbsdl_error_t **error );

/* Retrieves the partition offset relative to the start of the volume
 * Returns 1 if successful or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_partition_get_volume_offset(
     libvsbsdl_partition_t *partition,
     off64_t *volume_offset,
     libvsbsdl_error_t **error );

/* Reads (partition) data at the current offset into a buffer
 * Returns the number of bytes read or -1 on error
 */
LIBVSBSDL_EXTERN \
ssize_t libvsbsdl_partition_read_buffer(
         libvsbsdl_partition_t *partition,
         void *buffer,
         size_t buffer_size,
         libvsbsdl_error_t **error );

/* Reads (partition) data at a specific offset
 * Returns the number of bytes read or -1 on error
 */
LIBVSBSDL_EXTERN \
ssize_t libvsbsdl_partition_read_buffer_at_offset(
         libvsbsdl_partition_t *partition,
         void *buffer,
         size_t buffer_size,
         off64_t offset,
         libvsbsdl_error_t **error );

/* Seeks a certain offset of the (partition) data
 * Returns the offset if seek is successful or -1 on error
 */
LIBVSBSDL_EXTERN \
off64_t libvsbsdl_partition_seek_offset(
         libvsbsdl_partition_t *partition,
         off64_t offset,
         int whence,
         libvsbsdl_error_t **error );

/* Retrieves the current offset
 * Returns 1 if successful or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_partition_get_offset(
     libvsbsdl_partition_t *partition,
     off64_t *offset,
     libvsbsdl_error_t **error );

/* Retrieves the partition size
 * Returns 1 if successful or -1 on error
 */
LIBVSBSDL_EXTERN \
int libvsbsdl_partition_get_size(
     libvsbsdl_partition_t *partition,
     size64_t *size,
     libvsbsdl_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBVSBSDL_H ) */

