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
 
#ifndef __CUL_STACK_HPP__
#define __CUL_STACK_HPP__

#include <cul/Exception.hpp>

namespace cul {
namespace ds {
    
/**
* Stack Container
*/
template<typename T>
class Stack
{
private:
    /// Array
    T* arr;
    
    /// Size
    unsigned int size;
    
    /// Current Position
    unsigned int pos;
    
public:
    /**
    * Create new stack with given size
    */
    Stack(unsigned int size = 256);
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
};

//=============================================================================
// Implementation
//=============================================================================
/**
* Constructor
*/
template<typename T>
Stack<T>::Stack(unsigned int size)
    : pos(0), size(size)
{
    arr = new T[size];
}

/**
* Destructor
*/
template<typename T>
Stack<T>::~Stack()
{
    delete arr;
}

/**
* Push a element on stack
*/
template<typename T>
void Stack<T>::push(T elem)
{
    if(pos >= size)
        throw cul::Exception("cul stack overflow");
    
    arr[++pos] = elem;
}

/**
* Pops a element from stack
*/
template<typename T>
T Stack<T>::pop()
{
    if(pos <= 0)
        throw cul::Exception("cul stack underflow");
    
    return arr[pos--];
}


} //end namespace ds
} //end namespace cul

#endif /* __CUL_STACK_HPP__ */