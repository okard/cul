/*
C++ Utility Library

Copyright (c) 2013 okard

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
#ifndef __CUL_STREAM_HPP__
#define __CUL_STREAM_HPP__

#include <culcore/Types.hpp>

namespace cul {

/**
* Input Stream
*/
class InputStream
{
	/**
	* Try to read an amount of bytes from stream into buffer
	*/
	virtual size_t read(ubyte8 buf[], size_t size) = 0;
};

/**
* Output Stream
*/
class OutputStream 
{
	/**
	* Write a amount of bytes from buffer to stream
	*/
	virtual size_t write(ubyte8 buf[], size_t size) = 0;
};

/**
* Anchor for seek operations
*/
enum class Anchor : unsigned char
{
	Begin,
	End,
	Current
};

/**
* Input and Outputstream Interface
* Access to streams and to status
*/
class IOStream
{
	virtual bool isEOF() const = 0;
	virtual bool isWriteable() const = 0;
	virtual bool isReadable() const = 0;
	
	virtual size_t offset() = 0;
	virtual void seek(size_t pos, Anchor anchor) = 0;
	
	virtual InputStream& inputStream() const = 0;
	virtual OutputStream& outputStream() const = 0;	
};

} //end namespace cul

#endif // __CUL_STREAM_HPP__
