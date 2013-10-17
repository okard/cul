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
#pragma once
#ifndef __CUL_UTF_HPP__
#define __CUL_UTF_HPP__

#include <culcore/Types.hpp>
#include <culio/Encoding.hpp>

namespace cul {

/*
UTF-8                   EF BB BF
UTF-16 Big Endian       FE FF
UTF-16 Little Endian    FF FE
UTF-32 Big Endian       00 00 FE FF
UTF-32 Little Endian    FF FE 00 00
*/

const ubyte8 UTF8_BOM[] = {0xEF, 0xBB, 0xBF};
const ubyte8 UTF16BE_BOM[] = {0xFE, 0xFF};
const ubyte8 UTF16LE_BOM[] = {0xFF, 0xFE};
const ubyte8 UTF32BE_BOM[] = {0x00, 0x00, 0xFE, 0xFF};
const ubyte8 UTF32LE_BOM[] = {0xFF, 0xFE, 0x00, 0x00};


//utf16 char
typedef short16 char16;
//utf32 char
typedef int32 	char32;

/**
* checks if the given utf8 byte is an ascii character 
*/
inline bool utf8_isascii(byte8 b)
{
	//00-7F
    return ((b & 0x80) == 0x00);
};

/**
* checks if the given byte is an utf extend character 10xxxxxx
*/
inline bool utf8_isutf(byte8 b)
{
    return ((b & 0xC0) == 0x80);
};

/**
* return the length of an utf8 byte
* 0xxxxxxx = 1
* 1xxxxxxx = 1
* 11xxxxxx = 2
* 111xxxxx = 3
* 1111xxxx = 4
*/
inline byte8 utf8_char_info(byte8 b)
{
	//utf8 - ascii char
	if(b >= 0x00 && b <= 0x7F)
		return 1;
	//utf8 - 2 byte char
	if(b >= 0xC2 && b <= 0xDF)
		return 2;
	//utf8 - 3 byte char
	if(b >= 0xE0 && b <= 0xEF)
		return 3;
	//utf8 - 4 byte char
	if(b >= 0xF0 && b <= 0xF4)
		return 4;
	// it is follow byte
	if(b >= 0x80 && b <= 0xBF)
		return 0;
	
	//invalid char
	return -1;
}

// utf follow byte 10xx xxxx
// utf no ascii start 11->2, 111->3, 1111-> 4 

/*
// constants
const UTF32 LEAD_OFFSET = 0xD800 - (0x10000 >> 10);
const UTF32 SURROGATE_OFFSET = 0x10000 - (0xD800 << 10) - 0xDC00;

// computations
UTF16 lead = LEAD_OFFSET + (codepoint >> 10);
UTF16 trail = 0xDC00 + (codepoint & 0x3FF);

UTF32 codepoint = (lead << 10) + trail + SURROGATE_OFFSET;
*/

} //end namespace cul

#endif // __CUL_UTF_HPP__
