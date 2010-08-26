/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) <year>  <name of author>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*/

#ifndef ENDIAN_HPP
#define ENDIAN_HPP

#include "Types.hpp"
#include "RefPtr.hpp"

namespace cul {

/**
* endian swap for unsigned short
*/
inline void endian_swap(ushort& x)
{
    x = (x>>8) | (x<<8);
}

/**
* endian swap for unsigned int
*/
inline void endian_swap(uint& x)
{
    x = (x>>24) | 
        ((x<<8) & 0x00FF0000) |
        ((x>>8) & 0x0000FF00) |
        (x<<24);
}

/*
// __int64 for MSVC, "long long" for gcc
inline void endian_swap(unsigned __int64& x)
{
    x = (x>>56) | 
        ((x<<40) & 0x00FF000000000000) |
        ((x<<24) & 0x0000FF0000000000) |
        ((x<<8)  & 0x000000FF00000000) |
        ((x>>8)  & 0x00000000FF000000) |
        ((x>>24) & 0x0000000000FF0000) |
        ((x>>40) & 0x000000000000FF00) |
        (x<<56);
}
*/

/**
* is a big endian system
*/
inline bool is_bigendian()
{
    const int i = 1;
    return ((*(char*)&i) == 0);
}

/**
* is a little endian system
*/
inline bool is_littleendian()
{
    return !is_bigendian();
}

} //end namespace cul

#endif // ENDIAN_HPP
