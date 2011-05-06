/*
    C++ Utility Library

    Copyright (c) 2011  okard

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
#ifndef __CUL_ARRAY_HPP__
#define __CUL_ARRAY_HPP__

namespace cul {
<<<<<<< Updated upstream
=======
namespace ds {
    
    
//NOTICE: Classes and Structs directly, value types initializer?
>>>>>>> Stashed changes

/**
* Dynamic Array
*/
template<typename T>
class Array
{
private:
    /// Ptr to array
    T* arr;
    
    /// current size of array
    unsigned int size;
    
public:
    /** 
    * Create new dynamic array with given size
    */
    Array(unsigned int size = 16);
    
    /**
    * Destructs dynamic array
    */
    ~Array();
    
    /**
    * Add an element to array
    */
    T add();
    
    /**
    * index access to array
    */
    T& operator[](unsigned int i);
    
    /**
    * Get current size
    */
    unsigned int getSize();
    
    /**
    * Count of Elements
    */
    unsigned int getCount();
};


/**
* Specialisation for pointer types
* Array of pointer
*/
template<typename T>
class Array<T*>
{
private:
    //add(T* element);
    
public:
    
};




//=============================================================================
// Implementation
//=============================================================================

/**
* New dynamic array
*/
template<typename T>
Array<T>::Array(unsigned int size)
{
    //alloc memory
    arr = malloc(size*sizeof(T));
}

/**
* Destructs array
*/
template<typename T>
Array<T>::~Array()
{
    //kill elements
    free(arr);
}

/**
* Add an element to array
*/
template<typename T>
T Array<T>::add()
{
    //realloc array?
    //class handling with constructors?
    //memcopy
    //return new(arr[3]) T();
    
}

/**
* index access to array
*/
template<typename T>
T& Array<T>::operator[](unsigned int i)
{
}


} //end namespace cul

#endif // __CUL_ARRAY_HPP__