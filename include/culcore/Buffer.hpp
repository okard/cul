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
* A resizeable array
* (rename to vector?)
*/	
template<typename T, class Alloc = Allocator<T>>
class Buffer : public Array<T, Alloc>
{	
public:
	/**
	* Create new Buffer
	*/
	Buffer(size_t size) 
		: Array<T>(size)
	{
		
	}
	
	/**
	* Resize Buffer
	*/
	void resize(size_t elements)
	{
		//destruct old elements
		if(elements < Array<T>::size_)
			for(int i = elements; i < Array<T>::size_; i++)
				Alloc::destruct(Array<T>::mem_[i]);
		
		auto nptr = Alloc::alloc(elements);
		memcpy(nptr, Array<T>::mem_, elements * sizeof(T));
		Alloc::free(Array<T>::mem_);
		
		//construct new elements
		if(elements > Array<T>::size_)
			for(int i = Array<T>::size_; i < elements; i++)
				Alloc::construct(nptr[i]);
		
		Array<T>::mem_ = nptr;
		Array<T>::size_ = elements;
	}
	
	//append
	//add
	//fill sized vs allocated size

	//get offset
	//get size
	//grow
	//shrink
};

} //end namespace cul

#endif // __CUL_BUFFER_HPP__
