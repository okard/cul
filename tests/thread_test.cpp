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

#include <cul/threading/Thread>
#include <iostream>

using namespace cul;
using namespace threading;


class ThreadTest
{

public:
    
    void start()
    {
        ThreadDelegate<ThreadTest>* del = new ThreadDelegate<ThreadTest>(this, &ThreadTest::thread_func); 
        Thread thread(del);
        thread.run();
        thread.join();
    }
     
    void thread_func(Thread& thread)
    {
        std::cout << "Thread Started" << std::endl;
    }
    
};


void simple_thread_func(Thread& thread)
{
    
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
* main method
*/
int main(int argc, char *argv[])
{
    //file as argument?
    thread_test_simple_class();
    
    return 0;
}
