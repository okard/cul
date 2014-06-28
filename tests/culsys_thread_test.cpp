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
#include <culcore/Assert.hpp>
#include <cultest/Test.hpp>

#if 0
#include <culsys/Thread.hpp>
#include <culsys/ThreadDelegate.hpp>
#include <iostream>

using namespace cul;

/**
* Thread Test Class
*/
class ThreadTest
{
public:
    /**
    * Start a new thread
    */
    void start()
    {
        Thread thread(new ThreadDelegate<ThreadTest>(this, &ThreadTest::thread_func));
        thread.run();
        thread.join();
    }
    
    /**
    * Thread Function
    */
    void thread_func(Thread& thread)
    {
        std::cout << "Class Thread Started" << std::endl;
    }
    
};

/**
* Simple thread function
*/
void simple_thread_func(Thread& thread)
{
    std::cout << "Function Thread Started" << std::endl;
}

/**
* Test Thread Functions in Classes
*/
void thread_test_simple_class()
{
    ThreadTest t;
    t.start();
}

/**
* Test Thread Function
*/
void thread_test_simple_func()
{
    Thread thread(new ThreadFunction(&simple_thread_func));
    thread.run();
    thread.join();
}
CUL_TEST(thread_test_simple_func)

#endif

