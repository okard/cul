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
#ifndef __CUL_TYPES_HPP__
#define __CUL_TYPES_HPP__

#include <cstdlib>
#include <cstddef>

//namespace
namespace cul {

//bit specific:

typedef unsigned char ubyte8;
typedef signed char byte8;

typedef unsigned short ushort16;
typedef signed short short16;

typedef unsigned int uint32;
typedef signed int int32;

typedef unsigned long ulong64;
typedef signed long long64;

typedef float float32;
typedef double double64;

static_assert(sizeof(ubyte8) != 8, "Wrong ubyte8 size");
static_assert(sizeof(byte8) != 8, "Wrong byte8 size");
static_assert(sizeof(ushort16) != 16, "Wrong short size");
static_assert(sizeof(short16) != 16, "Wrong short size");
static_assert(sizeof(uint32) != 32, "Wrong int size");
static_assert(sizeof(int32) != 32, "Wrong int size");
static_assert(sizeof(ulong64) != 64, "Wrong long size");
static_assert(sizeof(long64) != 64, "Wrong long size");

static_assert(sizeof(float32) != 32, "Wrong float size");
static_assert(sizeof(double64) != 64, "Wrong double size");


typedef std::size_t size_t;


} //end namespace cul

#endif // __CUL_TYPES_HPP__
