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

#ifndef __THREADPOSIX_HPP__
#define __THREADPOSIX_HPP__

#include <cul/Self>

#include <pthread.h>

namespace cul {
namespace sys {

class Thread;

/**
* Posix Thread Implementation
*/
class ThreadImpl : public cul::Self<Thread>
{
    using cul::Self<Thread>::self;
    
    private:
        ///Thread id
        pthread_t tid;
    
    public:
        /**
        * Start thread
        */
        void run();
        
        /**
        * Join thread
        */
        void join();
        
        /**
        * static thread dispatch function
        */
        static void* run(void *p);
};

} //end namespace threading
} //end namespace c

#endif /* __THREADPOSIX_HPP__ */