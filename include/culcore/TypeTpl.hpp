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
#ifndef CUL_TYPETPL_HPP
#define CUL_TYPETPL_HPP

#include <type_traits>

//More Type Traits

namespace cul {

//Reference
template<class T>
using Ref = T&;
	
//Const Reference
template<class T>
using ConstRef = const T&;

//Pure Datatype
template<class T>
using Pure = T;


template<class RT>
struct FunctionType_ { };
template<class RT, class... ArgsF >
struct FunctionType_<RT(ArgsF...)>
{
	typedef RT (*type)(ArgsF...);
};


template<typename E>
constexpr auto EnumValue(E e) -> typename std::underlying_type<E>::type
{
   return static_cast<typename std::underlying_type<E>::type>(e);
}
	
}

#endif
