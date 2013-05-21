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

#include <culcore/Exception.hpp>
#include <culio/FileStream.hpp>

using namespace cul;


FileStream::FileStream()
	: file_(NULL)
{
}

FileStream::~FileStream()
{
}

void FileStream::open(const char* filename, FileMode mode)
{
	const char* fileMode = "r";
	
	mode_ = mode;
	file_ = fopen(filename, fileMode);
	
	if(file_==NULL)
		throw Exception("Error opening file");
}

void FileStream::close()
{
	if(!fclose(file_))
		throw Exception("Error closing file");
}

bool FileStream::isEOF() const
{
	return feof(file_);
}

bool FileStream::isWriteable() const
{
	return (ubyte8)mode_ & (ubyte8)FileMode::Write;
}

bool FileStream::isReadable() const
{
	return (ubyte8)mode_ & (ubyte8)FileMode::Read;
}

bool FileStream::isValid() const
{
	return ferror(file_);
}

size_t FileStream::offset() const
{
	return ftell (file_);
}

void FileStream::seek(size_t pos, Anchor anchor)
{
	int origin = (anchor == Anchor::Begin) ? SEEK_SET : 
	             (anchor == Anchor::End) ? SEEK_END : 
	             SEEK_CUR;

	if(!fseek(file_, pos, origin))
		throw Exception("Error seeking file");
}


size_t FileStream::write(ubyte8 buf[], size_t size)
{
	//size_t fwrite ( const void * ptr, size_t size, size_t count, FILE * stream );
}

size_t FileStream::read(ubyte8 buf[], size_t size)
{
	//size_t fread ( void * ptr, size_t size, size_t count, FILE * stream );

}
