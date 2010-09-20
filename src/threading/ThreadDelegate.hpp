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
#ifndef __THREADDELEGATE_HPP__
#define __THREADDELEGATE_HPP__

#include "Thread.hpp"

namespace cul {
namespace threading {
  
/**
* Thread Delegate for thread functions in classes
*/ 
template<class T>
class ThreadDelegate : public ThreadCall
{    
    private:
        ///pointer to class instance
        T* pInstance;
        ///pointer to class function
        void (T::*pRunFunc)(Thread&);

    public:
        /**
        * Constructor
        */
        ThreadDelegate(T* instance, void (T::*func)(Thread&))
            : pInstance(instance), pRunFunc(func)
        {
        }
        
        /**
        * Destructor
        */
        virtual ~ThreadDelegate(){}
        
        /**
        * run function
        */
        void run(Thread& t)
        {
            (pInstance->*pRunFunc)(t);
        }
}; 


/**
* Thread Delegate to simple function
*/
class ThreadFunction : public ThreadCall
{
    private:
        ///pointer to function
        void (*pRunFunc)(Thread&);
    public:
        /**
        * Constructor
        */
        ThreadFunction(void (*func)(Thread&))
            : pRunFunc(func)
        {
        }
        
        /**
        * Destructor
        */
        virtual ~ThreadFunction(){}
        
        /**
        * run function
        */
        void run(Thread& t)
        {
            (*pRunFunc)(t);
        }
};



} //end namespace threading
} //end namespace cul


#endif /* __THREADDELEGATE_HPP__ */