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
#include <culio/String.hpp>

#include <cstdlib>
#include <cassert>


//char* strncat(char* s1, const char* s2,size_t n) n < alloc
//int strcmp(const char *x, const char *y);
//char * strncpy ( char * destination, const char * source, size_t num );
//size_t strlen ( const char * str );

//void * malloc ( size_t size );

//wchar_t

namespace cul
{

/**
* Constructor
*/
string::string() : str(0), length(0), alloc(512), encoding(Encoding::ASCII)
{
    str = static_cast<char*>(malloc(alloc));
    str[0] = '\0';
    assert(strlen(str) == 0);
}

/**
* Constructor
*/
string::string(const cul::string& pstr)
{
    alloc = pstr.length;
    str = static_cast<char*>(malloc(alloc));
    
    strncpy(str, pstr.str, pstr.length);
    length = alloc;
}

/**
* Constructor
*/
string::string(const char* pstr)
{
    alloc = strlen(pstr);
    str = static_cast<char*>(malloc(alloc));
    
    strncpy(str, pstr, alloc);
    str[alloc] = '\0';
    
    assert(strlen(str) == alloc);
    length = alloc;
}

/**
* Constructor
*/
string::string(size_t memSize) : alloc(memSize), length(0), encoding(Encoding::ASCII), str(0)
{
    str = static_cast<char*>(malloc(alloc));
    str[0] = '\0';
    assert(strlen(str) == 0);
}


/**
* Destructor
*/
string::~string()
{
    free(str);
}

/**
* Append
*/
void string::append(char c)
{
    length += 1;
    prepareMem(length);
    
    str[length-1] = c;
    str[length] = '\0';
}

/**
* Append
*/
void string::append(const char* nstr)
{
    size_t size = strlen(nstr);
    length += size;
    
    //prepare Memory
    prepareMem(length);
    
    //copy string
    strncpy (&str[length-size], nstr, size);
    
    //0 terminated
    str[length] = '\0';
}

/**
* Append
*/
void string::append(const string& pstr)
{
    append(pstr.str);
}

/**
* Append
*/
void string::append(string* pstr)
{
    append(pstr->str);
}


/**
* length of string
*/
unsigned int string::len() const
{
    return length;
}

/**
* get size of allocated memory
*/
size_t string::mem() const
{
    return alloc;
}

/**
* Assign
*/
string& string::operator = (const string& other)
{
    if(this != &(other))
    {
        this->operator=(other.str);
    }
    
    return *this;
}

/**
* Assign
*/
string& string::operator = (const char* other)
{
    size_t l = strlen(other);
    
    //check for realloc
    prepareMem(l+1);
    
    strncpy(str, other, l);
    length = l;
    str[l] = '\0';
    
    assert(l == strlen(str));
    
    return *this;
}

/**
* append operators
*/
string& string::string::operator+=(const cul::string& other)
{
    append(other);
    return *this;
}

/**
* append operators
*/
string& string::string::operator+=(const char* other)
{
    append(other);
    return *this;
}



/**
* Equals
*/
bool string::operator==(const string& b) const
{
    //compare
    
    return this->operator==(b.str);
}

/**
* Equals
*/
bool string::operator==(const char* b) const
{
    //compare
    size_t l = strlen(b);
    if(l != length)
        return false;
        
    return strncmp(b, str, length) == 0;
}

/**
* Equals
*/
bool string::operator!=(const cul::string& b) const
{
    return !(*this == b);
}

/**
* Equals
*/
bool string::operator!=(const char* b) const
{
    return!(*this == b);
}


/**
* get c string
*/
const char* string::c_str()
{
    return str;
}


/**
* prepare mem
*/
void string::prepareMem(size_t requiredSize)
{
    //realloc when neseccary
    if(requiredSize > alloc)
    {
        alloc = requiredSize;
        
        char* temp = static_cast<char*>(realloc((void*)str, alloc));
        if(temp == nullptr)
            throw "realloc failed";
        str = temp;
    }
}

/**
* shrink mem
*/
void string::shrinkMem()
{
    if(length+1 < alloc)
    { 
        alloc = length+1;
        //allocated memory getting smaller so it is expected that realloc doesnt fail
        str = static_cast<char*>(realloc((void*)str, alloc));
    } 
}



} //end namespace cul
