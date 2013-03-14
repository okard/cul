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
#ifndef __CUL_HASHABLE_HPP__
#define __CUL_HASHABLE_HPP__

#include <functional>

namespace cul {
	
/**
* Hashable Interface
*/
class Hashable
{
public:
    virtual std::size_t hash() const = 0;
};

} //end namespace cul


namespace std {
	
/**
* Specialication hashing function for Hashable interface
*/ 
template<>
struct hash<cul::Hashable>
{
public:
	size_t operator()(const cul::Hashable& ha) const
	{
		return ha.hash();
	}
};


template<typename T>
struct hash<T*> 
{
public:
	size_t operator()(const T& obj) const
	{
		void* ptr = &obj;
		const size_t length = sizeof(T);
		
		size_t hash = 0;
		for (int i=0; i<length; i++) 
		{
			hash = 5*hash + ptr[i];
		}
		return hash;
	}
};
	
} //end namespace std

#endif
