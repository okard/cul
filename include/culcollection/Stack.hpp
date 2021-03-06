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
#ifndef __CUL_STACK_HPP__
#define __CUL_STACK_HPP__

#include <culcore/Types.hpp>
#include <culcore/Exception.hpp>

namespace cul {
    
/**
* Stack Container
*/
template<typename T, size_t N>
class Stack
{
private:
    /// Array
    T arr_[N];
    
    /// Current Position
    unsigned int pos_;
    
public:
    /**
    * Create new stack with given size
    */
    Stack();
    /**
    * Destructs a stack
    */
    ~Stack();
    
    /**
    * Push a element on stack
    */
    void push(T elem);
    
    /**
    * Pops a element from stack
    */
    T pop();
    
    /**
    * Get Element at position
    */
    const T& operator[] (size_t idx) const;

	/**
	* Get actual stack position
	*/
	inline const unsigned int& pos() const { return pos_; }
    
    /**
    * Get Stack size
    */ 
    inline const size_t& size() const { return N; }
};

//Implementation
#include "Stack.inl"


} //end namespace cul

#endif /* __CUL_STACK_HPP__ */
