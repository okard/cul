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
#ifndef __CUL_CONVERT_HPP__
#define __CUL_CONVERT_HPP__

#include <culcore/Platform.hpp>

namespace cul {

//NOTICE C++ has no reasonable support for specialized function templates so seperate in namespaces here   
     

/// To String Convert Functions
namespace Str{
    /**
    * Convert Integer to char*
    * need to be be free after usage
    */
    CUL_EXPORT char* to(int i);
}

/// To Long Convert Functions
namespace Long {
    /**
    * Convert string to long int
    */
    long to(const char* str);
}

/// To Unsigned Long Convert Functions
namespace ULong {
    /**
    * Convert string to unsigned long int
    */
    unsigned long to(const char* str);   
}

/// To Double Convert Functions
namespace Double {
    /**
    * Convert string to double
    */
    double to(const char* str);
}

    
} //end namespace cul


#endif // __CUL_CONVERT_HPP__
