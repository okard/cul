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
#ifndef CUL_DYNARRAY_HPP
#define CUL_DYNARRAY_HPP

#include <cstring>

#include <culcore/Types.hpp>
#include <culcore/Exception.hpp>
#include <culalloc/Allocator.hpp>

namespace cul {
	
/**
* General Array class
* static container for x elements
*/
template<typename T, class Alloc = Allocator<T>>
class DynArray
{
protected:
	//pointer to memory
	T* mem_ = nullptr;
	//allocated elements in memory
	size_t size_ = 0;
	
public:

	DynArray(size_t size)
	  :	size_(size)
	{
		mem_ = Alloc::alloc(size_);
		for(size_t i = 0; i < size_; i++)
		{
			Alloc::construct(mem_[i]);
		}
	}
	
	virtual ~DynArray()
	{
		for(size_t i = 0; i < size_; i++)
		{
			Alloc::destruct(mem_[i]);
		}
			
		Alloc::free(mem_);
		size_ = 0;
	}
	
	//index operator
	inline T& operator[] (size_t idx) 
	{ 
		if(idx < 0 || idx > size_-1)
			throw Exception("index out of bounds");
			
		return mem_[idx]; 
	}
	
	inline const T& operator[] (size_t idx) const 
	{ 
		if(idx < 0 || idx > size_-1)
			throw Exception("index out of bounds");
			
		return mem_[idx]; 
	}
	
	/**
	* Resize Buffer
	*/
	void resize(size_t elements)
	{
		//destruct old elements
		if(elements < DynArray<T>::size_)
			for(size_t i = elements; i < DynArray<T>::size_; i++)
				Alloc::destruct(DynArray<T>::mem_[i]);
		
		auto nptr = Alloc::alloc(elements);
		memcpy(nptr, DynArray<T>::mem_, elements * sizeof(T));
		Alloc::free(DynArray<T>::mem_);
		
		//construct new elements
		if(elements > DynArray<T>::size_)
			for(size_t i = DynArray<T>::size_; i < elements; i++)
				Alloc::construct(nptr[i]);
		
		DynArray<T>::mem_ = nptr;
		DynArray<T>::size_ = elements;
	}
	
	//append
	//add
	//fill sized vs allocated size

	//get offset
	//get size
	//grow
	//shrink
	
	
	//ptr to data
	inline T* ptr() { return mem_; }
	inline const T* ptr() const { return mem_; }
	
	//size of array
	inline size_t size() const { return size_; }
};
	
} //end namespace cul

#endif
