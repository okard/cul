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
#ifndef __CUL_DELEGATE_HPP__
#define __CUL_DELEGATE_HPP__

#if __cplusplus != 201103L
    #error A C++11 compiler is required!
#endif 


namespace cul {
    
/**
* Generic C++11 Delegate
*/
template<typename RT, typename... Arg>
class delegate
{
private:
    /// callfunction
    typedef RT (*funcCall)(void* object_ptr, Arg...);

    /// points to object 
    void* objPtr;
    /// caller function
    funcCall func;
 
    /**
    * Wrapps object cast for function calling
    */
    template <class T, RT (T::*TMethod)(Arg...)>
    static RT methodStub(void* objPtr, Arg... args)
    {
        T* p = static_cast<T*>(objPtr);
        return (p->*TMethod)(args...); 
    }
    
    friend class std::hash<delegate<RT, Arg...>>;
    
    /**
    * Private Default Constructor
    */
    delegate() : objPtr(0), func(0) { }
    
public:

    /**
    * Copy Constructor
    */
    delegate(const delegate<RT, Arg...>& d)
    {
		objPtr = d.objPtr;
		func = d.func;
	}

    /**
    * Create Delegate
    */
    template <class T, RT (T::*TMethod)(Arg...)>
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
    RT operator()(Arg... args) const
    {
        return (*func)(objPtr, args...);
    }
    
	/**
	* This is also required additional to hash
	* to store delegate in hashsets/maps
	* why?
	*/
	bool operator==(const delegate<RT, Arg...>& d) const
	{
		return objPtr == d.objPtr && func == d.func;
	}
	
	
};
    
} //end namespace cul

// delegate<void, int> d = delegate::create<Foo, &Foo::slot>(&obj);


namespace std {
	
/**
* Hash function for delegate
* required for signal class to use delegates in hashsets/maps
*/
template<typename RT, typename... Arg>
struct hash<cul::delegate<RT, Arg...> > {
public:
    size_t operator()(const cul::delegate<RT, Arg...> &dg) const 
    {
		size_t h1 = std::hash<void*>()(reinterpret_cast<void*>(dg.func));
        size_t h2 = std::hash<void*>()(reinterpret_cast<void*>(dg.objPtr));
        return h1 ^ ( h2 << 1 );
    }
}; 
	
} //end namespace std



#endif // __CUL_DELEGATE_HPP__
