/*
 * bit7z - A C++ static library to interface with the 7-zip DLLs.
 * Copyright (c) 2014-2021  Riccardo Ostani - All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * Bit7z is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with bit7z; if not, see https://www.gnu.org/licenses/.
 */

#ifndef BITARCHIVEITEMOFFSET_HPP
#define BITARCHIVEITEMOFFSET_HPP

#include "bitarchiveitem.hpp"

namespace bit7z {
class BitInputArchive;

/**
 * @brief The BitArchiveItemOffset class represents an archived item but doesn't store its properties.
 */
class BitArchiveItemOffset final : public BitArchiveItem {
    public:
        BitArchiveItemOffset& operator++() noexcept;

        BitArchiveItemOffset operator++( int ) noexcept;

        bool operator==( const BitArchiveItemOffset& other ) const noexcept;

        bool operator!=( const BitArchiveItemOffset& other ) const noexcept;

        /**
         * @brief Gets the specified item property.
         *
         * @param property  the property to be retrieved.
         *
         * @return the value of the item property, if available, or an empty BitPropVariant.
         */
        BIT7Z_NODISCARD BitPropVariant itemProperty( BitProperty property ) const override;

    private:
        /* Note: a pointer, instead of a reference, allows this class, and hence BitInputArchive::const_iterator,
         * to be CopyConstructible so that stl algorithms can be used with const_iterator! */
        const BitInputArchive* mArc;

        BitArchiveItemOffset( uint32_t item_index, const BitInputArchive& item_arc ) noexcept;

        friend class BitInputArchive;
};
}  // namespace bit7z

#endif // BITARCHIVEITEMOFFSET_HPP
