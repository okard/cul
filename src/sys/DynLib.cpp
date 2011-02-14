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

#include <cul/sys/DynLib.hpp>

using namespace cul;
using namespace sys;

/**
* Open Dynamic Library
*/
DynLib::DynLib(const char* file)
{
    #ifdef WIN32
        hInstLib = LoadLibrary(file);
    #else
        lib = dlopen(file, RTLD_LAZY);
        //char *dlerror(void);
    #endif
}

/**
* Dtor
*/
DynLib::~DynLib()
{
    #ifdef WIN32
        FreeLibrary (hInstLib) ;
    #else
        dlclose(lib); 
    #endif
}

/**
* Get function from library
*/
void* DynLib::get(const char* func)
{
    #ifdef WIN32
        return GetProcAddress (hInstLib, func) ;
    #else
        return dlsym(lib, func);
    #endif
}
