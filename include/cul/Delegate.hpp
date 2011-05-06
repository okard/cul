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
#ifndef __CUL_DELEGATE_HPP__
#define __CUL_DELEGATE_HPP__

namespace cul {
    
/**
* Delegate
*/
template<typename RT, typename Arg0>
class delegate
{
private:
    /// callfunction
    typedef RT (*funcCall)(void* object_ptr, Arg0);

    /// points to object 
    void* objPtr;
    /// caller function
    funcCall func;
 
    /**
    * Wrapps object cast for function calling
    */
    template <class T, RT (T::*TMethod)(Arg0)>
    static RT methodStub(void* objPtr, Arg0 a0)
    {
        T* p = static_cast<T*>(objPtr);
        return (p->*TMethod)(a0); 

    }
    
public:
    /**
    * Constructor
    */
    delegate() : objPtr(0), func(0)
    {
    }

    /**
    * Create Delegate
    */
    template <class T, RT (T::*TMethod)(Arg0)>
    static delegate create(T* objPtr)
    {
        delegate d;
        d.objPtr = objPtr;
        d.func = &methodStub<T, TMethod>;
        return d;
    }

    /**
    * Call Delegate
    */
    RT operator()(Arg0 a0) const
    {
        return (*func)(objPtr, a0);
    }
};

} //end namespace cul

// delegate<void, int> d = delegate::create<Foo, &Foo::slot>(&obj);

#endif // __CUL_DELEGATE_HPP__