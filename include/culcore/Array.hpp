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
#ifndef __CUL_ARRAY_HPP__
#define __CUL_ARRAY_HPP__

#include <culcore/Types.hpp>
#include <culcore/Exception.hpp>
#include <culcore/Alloc.hpp>

namespace cul {
	
/**
* General Array class
*/
template<typename T, class Alloc = Allocator<T>>
class Array
{
protected:
	T* mem_;
	size_t size_;
	
public:

	Array(size_t size)
	  :	size_(size)
	{
		mem_ = Alloc::alloc(size_);
		for(int i = 0; i < size_; i++)
		{
			Alloc::construct(mem_[i]);
		}
	}
	
	virtual ~Array()
	{
		for(int i = 0; i < size_; i++)
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
	
	//ptr to data
	inline T* ptr() { return mem_; }
	inline const T* ptr() const { return mem_; }
	
	//size of array
	inline size_t size() const { return size_; }
	
};
	
} //end namespace cul

#endif
