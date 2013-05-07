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
#ifndef __CUL_ALLOC_HPP__
#define __CUL_ALLOC_HPP__

#include <culcore/Types.hpp>

namespace cul {
	
template<typename T>
class Allocator
{
public:

	static T* alloc(size_t count)
	{
		return reinterpret_cast<T*>(::operator new (sizeof(T)*count));
	}
	
	static void free(T* obj)
	{
		::operator delete(reinterpret_cast<void*>(obj));
	}
	
	static void construct(T& obj)
	{
		new (&obj) T;
	}
	
	static void destruct(T& obj)
	{
		obj.~T();
	}
};

//define this for all primary types?
template<>
class Allocator<ubyte8>
{
	typedef ubyte8 T;
	
public:
	static T* alloc(size_t count)
	{
		return reinterpret_cast<T*>(::operator new (sizeof(T)*count));
	}
	
	static void free(T* obj)
	{
		::operator delete(reinterpret_cast<void*>(obj));
	}
	
	static void construct(T& obj)
	{
		obj=0;
	}
	
	static void destruct(T& obj)
	{
		
	}
};
	
} //end namespace

#endif
