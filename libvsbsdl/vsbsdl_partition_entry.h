/*
 * BSD disklabel partition entry definitions
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

#if !defined( _VSBSDL_PARTITION_ENTRY_H )
#define _VSBSDL_PARTITION_ENTRY_H

#include <common.h>
#include <types.h>

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct vsbsdl_partition_entry vsbsdl_partition_entry_t;

struct vsbsdl_partition_entry
{
	/* The number of sectors
	 * Consists of 4 bytes
	 */
	uint8_t number_of_sectors[ 4 ];

	/* The start sector
	 * Consists of 4 bytes
	 */
	uint8_t start_sector[ 4 ];

	/* The file system fragement size
	 * Consists of 4 bytes
	 */
	uint8_t fragment_size[ 4 ];

	/* The file system type
	 * Consists of 1 byte
	 */
	uint8_t file_system_type;

	/* The number of file system fragments per block
	 * Consists of 1 byte
	 */
	uint8_t fragments_per_block;

	/* Unknown
	 * Consists of 2 bytes
	 */
	uint8_t unknown1[ 2 ];
};

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _VSBSDL_PARTITION_ENTRY_H ) */

