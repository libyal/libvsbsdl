/*
 * BSD disklabel definitions
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

#if !defined( _VSMBR_DISK_LABEL_H )
#define _VSMBR_DISK_LABEL_H

#include <common.h>
#include <types.h>

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct vsmbr_disklabel_header vsmbr_disklabel_header_t;

struct vsmbr_disklabel_header
{
	/* The signature
	 * Consists of 4 bytes
	 * Contains "WEV\x82"
	 */
	uint8_t signature1[ 4 ];

	/* The drive type
	 * Consists of 2 bytes
	 */
	uint8_t drive_type[ 2 ];

	/* The controller specific drive sub type
	 * Consists of 2 bytes
	 */
	uint8_t drive_sub_type[ 2 ];

	/* The drive type name
	 * Consists of 16 bytes
	 */
	uint8_t drive_type_name[ 16 ];

	/* Unknown
	 * Consists of 16 bytes
	 */
	uint8_t unknown1[ 16 ];

	/* The number of bytes per sector
	 * Consists of 4 bytes
	 */
	uint8_t bytes_per_sector[ 4 ];

	/* The number of data sectors per track
	 * Consists of 4 bytes
	 */
	uint8_t sectors_per_track[ 4 ];

	/* The number of track per cylinder
	 * Consists of 4 bytes
	 */
	uint8_t tracks_per_cylinder[ 4 ];

	/* The number of data cylinders per unit
	 * Consists of 4 bytes
	 */
	uint8_t cylinders_per_unit[ 4 ];

	/* The number of data sectors per cylinder
	 * Consists of 4 bytes
	 */
	uint8_t sectors_per_cylinder[ 4 ];

	/* The number of data sectors per unit
	 * Consists of 4 bytes
	 */
	uint8_t sectors_per_unit[ 4 ];

	/* The number of spare sectors per track
	 * Consists of 2 bytes
	 */
	uint8_t spare_sectors_per_track[ 2 ];

	/* The number of spare sectors per cylinder
	 * Consists of 2 bytes
	 */
	uint8_t spare_sectors_per_cylinder[ 2 ];

	/* The number of alternate sectors per unit
	 * Consists of 4 bytes
	 */
	uint8_t alternate_sectors_per_unit[ 4 ];

	/* Unknown
	 * Consists of 2 bytes
	 */
	uint8_t unknown2[ 2 ];

	/* Unknown
	 * Consists of 2 bytes
	 */
	uint8_t unknown3[ 2 ];

	/* Unknown
	 * Consists of 2 bytes
	 */
	uint8_t unknown4[ 2 ];

	/* Unknown
	 * Consists of 2 bytes
	 */
	uint8_t unknown5[ 2 ];

	/* Unknown
	 * Consists of 4 bytes
	 */
	uint8_t unknown6[ 4 ];

	/* Unknown
	 * Consists of 4 bytes
	 */
	uint8_t unknown7[ 4 ];

	/* Flags
	 * Consists of 4 bytes
	 */
	uint8_t flags[ 4 ];

	/* Unknown
	 * Consists of 20 bytes
	 */
	uint8_t unknown8[ 20 ];

	/* Unknown
	 * Consists of 20 bytes
	 */
	uint8_t unknown9[ 20 ];

	/* The signature
	 * Consists of 4 bytes
	 * Contains "WEV\x82"
	 */
	uint8_t signature2[ 4 ];

	/* Checksum
	 * Consists of 2 bytes
	 */
	uint8_t checksum[ 2 ];

	/* Number of partition entries
	 * Consists of 2 bytes
	 */
	uint8_t number_of_partition_entries[ 2 ];

	/* Boot area size
	 * Consists of 4 bytes
	 */
	uint8_t boot_area_size[ 4 ];

	/* Maximum superblock size
	 * Consists of 4 bytes
	 */
	uint8_t maximum_superblock_size[ 4 ];
};

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _VSMBR_DISK_LABEL_H ) */

