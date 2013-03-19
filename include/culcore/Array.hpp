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

namespace cul {
	
/**
* General Array class
*/
template<typename T>
class Array
{
protected:
	T* mem_;
	size_t size_;
	
public:

	Array(size_t size)
	  :	mem_(new T[size]), size_(size)
	{
		
	}
	
	virtual ~Array()
	{
		size_ = 0;
		delete[] mem_;
	}
	
	//index operator
	inline T operator[] (size_t idx) { return mem_[idx]; }
	inline const T operator[] (size_t idx) const { return mem_[idx]; }
	
	//ptr to data
	inline T* ptr() { return mem_; }
	inline const T* const ptr() const { return mem_; }
	
	//size of array
	inline size_t size() const { return size_; }
	
};
	
} //end namespace cul

#endif
