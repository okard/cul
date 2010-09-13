/*
    C++ Utility Library

    Copyright (c) 2010  okard

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
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
