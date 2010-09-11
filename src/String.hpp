/*
    C++ Utility Library
    Copyright (C) 2010  okard

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*/

#ifndef __STRING_HPP__
#define __STRING_HPP__

#include <cstring>

#include "RefPtr.hpp"
#include "Types.hpp"
#include "io/Utf.hpp"

/// Namespace for c++ utility library
namespace cul
{


/**
* \brief simple string class
*/
class string
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

/**
* Ref Counted String Ptr
*/
typedef RefPtr<string> StringPtr;


} // end namespace cul

#endif //__STRING_HPP__