/*
    C++ Utility Library

    Copyright (c) 2012  okard

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
#ifndef CUL_TYPES_HPP
#define CUL_TYPES_HPP

#include <cstddef> /* std::size_t */

//namespace
namespace cul {

//bit specific:

typedef unsigned char ubyte8;
typedef signed char byte8;
typedef ubyte8 u8;
typedef byte8 i8;

typedef unsigned short u16;
typedef signed short i16;

typedef unsigned int u32;
typedef signed int i32;

typedef unsigned long u64;
typedef signed long i64;

typedef float f32;
typedef double f64;

static_assert(sizeof(ubyte8) == 1, "Wrong ubyte8 size");
static_assert(sizeof(byte8) == 1, "Wrong byte8 size");
static_assert(sizeof(u16) == 2, "Wrong u16 size");
static_assert(sizeof(i16) == 2, "Wrong i16 size");
static_assert(sizeof(u32) == 4, "Wrong u32 size");
static_assert(sizeof(i32) == 4, "Wrong i32 size");
static_assert(sizeof(u64) == 8, "Wrong u64 size");
static_assert(sizeof(i64) == 8, "Wrong i64 size");

static_assert(sizeof(f32) == 4, "Wrong f32 size");
static_assert(sizeof(f64) == 8, "Wrong f64 size");


typedef std::size_t size_t;


} //end namespace cul

#endif // CUL_TYPES_HPP
