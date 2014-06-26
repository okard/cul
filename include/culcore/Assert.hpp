/*
    C++ Utility Library

    Copyright (c) 2014  okard

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
#ifndef CUL_ASSERT_HPP
#define CUL_ASSERT_HPP

#include <culcore/Platform.hpp>
#include <culcore/Exception.hpp>


#ifdef CUL_DEBUG
	#define CUL_ASSERT(cond, msg) cul::assert((cond), msg);
#else
	#define CUL_ASSERT(cond, msg)
#endif


namespace cul {

template<class E>
inline static void assert(bool cond, const char* msg)
{
	if(!cond) {
		throw E(msg);
	}
}


//Assert Functions (multiple purposes not only testing only)
inline static void assert(bool cond, const char* msg)
{
	if(!cond) {
		throw Exception(msg); 
	}
}

//Assert Functions (multiple purposes not only testing only)
inline static void assert(bool cond)
{
	if(!cond) {
		throw Exception("assert exception");
	}
}

//assert_eq
template<class E, typename V>
inline static void assert_eq(V is, V should)
{
	if(is != should) {
		throw E("Value is %x but should be %x", is, should);
	}
}



//throw exception
inline static void assert_fail()
{
	throw Exception("Assertion Error: Reached a point that never should be reached"); 
}


} //end namespace cul

#endif
