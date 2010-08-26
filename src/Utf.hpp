/*
    C++ Utility Library
    Copyright (C) 2010  okard

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

#ifndef UTF_H
#define UTF_H

#include "Types.hpp"

namespace cul {

/**
* Encoding Types
*/
enum Encoding
{
    ///ASCII Encoding
    ASCII, 
    /// UTF8 Encoding
    UTF8, 
    /// UTF16 Big Endian Encoding
    UTF16BE, 
    /// UTF16 Little Endian Encoding
    UTF16LE, 
    /// UTF32 Big Endian Encoding
    UTF32BE, 
    /// UTF32 Little Endian Encoding
    UTF32LE
};

/*
UTF-8                   EF BB BF
UTF-16 Big Endian       FE FF
UTF-16 Little Endian    FF FE
UTF-32 Big Endian       00 00 FE FF
UTF-32 Little Endian    FF FE 00 00
*/
const byte UTF8_BOM[] = {0xEF, 0xBB, 0xBF};
const byte UTF16BE_BOM[] = {0xFE, 0xFF};
const byte UTF16LE_BOM[] = {0xFF, 0xFE};
const byte UTF32BE_BOM[] = {0x00, 0x00, 0xFE, 0xFF};
const byte UTF32LE_BOM[] = {0xFF, 0xFE, 0x00, 0x00};

/**
* checks if the given utf8 byte is an ascii character 
*/
inline bool utf8_isascii(byte b)
{
    return (b & 0x80 == 0x00);
};

/**
* checks if the given byte is an utf extend character 10xxxxxx
*/
inline bool utf8_isutf(byte b)
{
    return (b & 0xC0 == 0x80);
};

/**
* return the startbyte of an utf8 byte
* 0xxxxxxx = 1
* 1xxxxxxx = 1
* 11xxxxxx = 2
* 111xxxxx = 3
* 1111xxxx = 4
*/
inline ubyte utf8_startbyte(byte b)
{
    return (b & 0xC0 == 0xC0) ? 2 : ((b & 0xE0) == 0xE0) ? 3 : ((b & 0xF0) == 0xF0) ? 4 : 1;
}

// utf follow byte 10xx xxxx
// utf no ascii start 11->2, 111->3, 1111-> 4 

} // end namespace cul

#endif // UTF_H
