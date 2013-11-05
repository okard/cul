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

using namespace cul;

/**
* Constructor
*/
string::string() 
	: buffer_(512), length_(0), encoding_(Encoding::ASCII)
{
	char* c = str();
    c[0] = '\0';
    assert(strlen(c) == 0);
}

/**
* Constructor
*/
string::string(const cul::string& pstr)
	: buffer_(pstr.length_)
{
    strncpy(str(), pstr.c_str(), pstr.length_);
    length_ = pstr.length_;
}

/**
* Constructor
*/
string::string(const char* pstr)
	: buffer_(strlen(pstr))
{
	auto memsize = strlen(pstr);
	char* c = str();
    strncpy(c, pstr, memsize);
    c[memsize] = '\0';
    
    assert(strlen(c) == buffer_.size());
    length_ = memsize;
}

/**
* Constructor
*/
string::string(size_t memSize) 
	: buffer_(memSize), length_(0), encoding_(Encoding::ASCII)
{
	char* c = str();
    c[0] = '\0';
    assert(strlen(c) == 0);
}


/**
* Destructor
*/
string::~string()
{
}

/**
* Append
*/
void string::append(char c)
{
    length_ += 1;
    
    if(buffer_.size() < length_)
		buffer_.resize(length_);
    
    char* cs = str();
    cs[length_-1] = c;
    cs[length_] = '\0';
}

/**
* Append
*/
void string::append(const char* nstr)
{
    size_t size = strlen(nstr);
    length_ += size;
    
    if(buffer_.size() < length_)
		buffer_.resize(length_);
    
    char* c = str();
    //copy string
    strncpy (&c[length_-size], nstr, size);
    
    //0 terminated
    c[length_] = '\0';
}

/**
* Append
*/
void string::append(const string& pstr)
{
    append(pstr.c_str());
}

/**
* Append
*/
void string::append(string* pstr)
{
    append(pstr->c_str());
}


/**
* length of string
*/
unsigned int string::len() const
{
    return length_;
}

/**
* get size of allocated memory
*/
size_t string::mem() const
{
    return buffer_.size();
}

/**
* Assign
*/
string& string::operator = (const string& other)
{
    if(this != &(other))
    {
        this->operator=(other.c_str());
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
    if(l > buffer_.size())
		buffer_.resize(l+1);
    
    char* c = str();
    strncpy(c, other, l);
    length_ = l;
    c[l] = '\0';
    
    assert(l == strlen(c));
    
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
    return this->operator==(b.c_str());
}

/**
* Equals
*/
bool string::operator==(const char* b) const
{
    //compare
    size_t l = strlen(b);
    if(l != length_)
        return false;
        
    return strncmp(b, c_str(), length_) == 0;
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
const char* string::c_str() const
{
    return reinterpret_cast<const char*>(buffer_.ptr());
}

char* string::str()
{
	return reinterpret_cast<char*>(buffer_.ptr());
}
