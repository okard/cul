/*
    C++ Utility Library

    Copyright (c) 2013  okard

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
#ifndef __CUL_FILESTREAM_HPP__
#define __CUL_FILESTREAM_HPP__

#include <cstdio>

#include <culio/Stream.hpp>


namespace cul {
	
enum class FileMode : unsigned char
{
	Read = 1<<0,
	Write = 1<<1,
	Append = 1<<2,
	Update = 1<<3,
	
	ReadWrite = Read | Write
};

/**
* File Stream combines in and output
*/
class FileStream : public IOStream, public Seekable
{
private:
	FILE* file_;
	FileMode mode_;
public:

	FileStream();
	virtual ~FileStream();

	void open(const char* filename, FileMode mode);
	void close();

	virtual bool isEOF() const;
	virtual bool isWriteable() const;
	virtual bool isReadable() const;
	bool isValid() const;
	
	virtual size_t offset() const;
	virtual void seek(size_t pos, Anchor anchor);

	virtual size_t write(ubyte8 buf[], size_t size);
	virtual size_t read(ubyte8 buf[], size_t size);
};
	
	
} //end namespace cul


#endif
