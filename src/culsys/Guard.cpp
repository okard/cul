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
#include <culsys/Guard.hpp>

using namespace cul;
using namespace sys;

/**
* Creates a new Guard
*/
Guard::Guard()
{
    #ifdef WIN32
        // Initialize the critical section one time only.
        if (!InitializeCriticalSectionAndSpinCount(&CriticalSection, 0x80000400) ) 
            return;
    #else
         pthread_mutex_init (&mutex, NULL);
    #endif
}

/**
* Destructor
*/
Guard::~Guard()
{
    #ifdef WIN32
        // Release resources used by the critical section object.
        DeleteCriticalSection(&CriticalSection);
    #else
    #endif
}

/**
* lock
*/
void Guard::lock()
{
    locked = true;
    
    #ifdef WIN32
        // Request ownership of the critical section.
        EnterCriticalSection(&CriticalSection); 
    #else
        pthread_mutex_lock (&mutex);
    #endif
}
        
/**
* unlock
*/
void Guard::unlock()
{
    locked = false;
    
    #ifdef WIN32
        // Release ownership of the critical section.
        LeaveCriticalSection(&CriticalSection);
    #else
        pthread_mutex_unlock (&mutex);
    #endif
}
        
/**
* is locked
*/
bool Guard::isLocked()
{
    return locked;
}