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
#ifndef __CUL_BUFFER_HPP__
#define __CUL_BUFFER_HPP__

#include <cstring>

#include <culcore/Platform.hpp>
#include <culcore/Types.hpp>
#include <culcore/Array.hpp>

namespace cul {

/**
* Generic Memory Buffer
*/	
template<typename T>
class Buffer : public Array<T>
{
private:
	size_t pos_;
	
public:
	Buffer(size_t size) 
		: Array<T>(size)
	{
		
	}
	
	
	
	
	void resize(size_t elements)
	{
		
		auto nptr = new T[elements];
		memcpy(nptr, Array<T>::mem_, Array<T>::size_ * sizeof(T));
		//pos_ = Array<T>::size_;
		delete nptr; 
	}

	//get offset
	//get size
	//grow
	//shrink
	
};


extern template class Buffer<ubyte8>;
typedef Buffer<ubyte8> ByteBuffer;

//class ByteBuffer : public Buffer<ubyte8> {};

} //end namespace cul

#endif // __CUL_BUFFER_HPP__
