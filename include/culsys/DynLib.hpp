/*
C++ Utility Library

Copyright (c) 2010 okard

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
#ifndef __CUL_DYNLIB_HPP__
#define __CUL_DYNLIB_HPP__

#include <culcore/Platform.hpp>

#ifdef CUL_PLATFORM_WIN32
    #include <windows.h>
#else
    #include <dlfcn.h>
#endif


namespace cul {

/**
* Dynamic Library 
*/
class DynLib
{
private:
    #ifdef CUL_PLATFORM_WIN32
        HINSTANCE hInstLib;
    #else
        void* lib;
    #endif

public:
    /**
    * Open Dynamic Library
    */
    DynLib(const char* file);
    
    /**
    * Dtor
    */
    ~DynLib();
    
    /**
    * Get function from library
    */
    void* get(const char* func);
};

} // namespace cul

#endif //__CUL_DYNLIB_HPP__
