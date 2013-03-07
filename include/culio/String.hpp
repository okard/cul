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
#ifndef __CUL_STRING_HPP__
#define __CUL_STRING_HPP__

#include <cstring>

#include <culcore/Platform.hpp>
#include <culcore/Types.hpp>
#include <culio/Encoding.hpp>
#include <culio/Buffer.hpp>

/// Namespace for c++ utility library
namespace cul {
    
// TODO Simplify string to a minimal implementation, add a advanced string class on top for high level functions

/**
* \brief simple string class
*/
class CUL_EXPORT string
{
    private:
        ///buffer
        char* str;
        
        /// length of string
        uint length;
        
        /// allocated memory
        size_t alloc;
        
        /// encoding of string
        enum Encoding encoding;
        
    public:
        /**
        * Constructs a new string
        */
        string();
        
        /**
        * Constructs new string from an string
        */
        string(const string& pstr);
        
        /**
        * Constructs a new string
        */
        string(const char* pstr);
        
        /**
        * Constructs new string with given mem size
        */
        string(size_t memSize);
        
        /**
        * Destructor
        */
        ~string();
        
        /**
        * Assign an other string
        */
        string& operator = (const string& b);
        
        /**
        * Assign a const char*
        */
        string& operator = (const char* b);
        
        /**
        * append
        */
        string& operator += (const string& other);

        /**
        * append
        */
        string& operator += (const char* other);

        /**
        * Append a char
        */
        void append(char c);
        
        /**
        * Append a char array
        */
        void append(const char* str);
        
        /**
        * Append a string
        */
        void append(const string& str);
        
        /**
        * Append a string
        */
        void append(string* str);
        
        /**
        * Length of string
        */
        unsigned int len() const;
        
        /**
        * Get size of allocated memory
        */
        size_t mem()  const;
        
        /**
        * Equals
        */
        bool operator ==(const string& b) const;
        
        /**
        * Equals
        */
        bool operator ==(const char* b) const;
        
        /**
        * Equals
        */
        bool operator !=(const string& b) const;
        
        /**
        * Equals
        */
        bool operator !=(const char* b) const;
         
        /**
        * get c string
        */
        const char* c_str();
        
    private:
        
        /**
        * prepare memory
        */
        void prepareMem(size_t requiredSize);
        
        /**
        * shrink memory when possible
        */
        void shrinkMem();
        
        
        //change encoding?
};

} // end namespace cul

#endif //__CUL_STRING_HPP__
