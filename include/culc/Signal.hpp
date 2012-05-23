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
#pragma once
#ifndef __CUL_SIGNAL_HPP__
#define __CUL_SIGNAL_HPP__


#include <vector>
#include <cul/Delegate.hpp>

namespace cul {
    
template<typename... Arg>
class signal
{
private:
    //delegate type
    typedef delegate<void, Arg...> dg;
    
    //function ptr type
    typedef void (*func)(Arg...);
    
    //list with delegate listener
    std::vector<dg> listener;
    
    std::vector<func> funcs;

public:
    
    /**
    * connect to object
    */
    template <class T, void (T::*TMethod)(Arg...)>
    void connect(T* obj)
    {
        auto d = dg::template create<T, TMethod>(obj);
        listener.push_back(d);
    }
    
    /**
    * Connect to simple function
    */
    void connect(func f)
    {
        funcs.push_back(f);
    }
    
    /**
    * Fire Event
    */
    void operator()(Arg... args) const
    {
        for(auto iter=listener.begin(); iter != listener.end(); ++iter)
        {
            (*iter)(args...);
        }
        
        for(auto iter=funcs.begin(); iter != funcs.end(); ++iter)
        {
            (*iter)(args...);
        }
    }
    
};

    
} //end namespace cul

#endif // __CUL_SIGNAL_HPP__
