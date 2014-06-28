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
public:
    /**
    *  Default Constructor
    */
    delegate() 
        : func_(nullptr)
    { 
    }
    
    /**
    * Copy Constructor
    */
    delegate(const delegate<RT, Arg...>& d)
    {
		func_ = d.func_;
        //copy context
        mem_.obj = d.mem_.obj;
        mem_.method = d.mem_.method;
	}
    
    /**
    * Normal Constructor
    */
    template <class T>
    delegate(T* const objPtr, RT (T::*TMethod)(Arg...))
    {
        bind<T>(objPtr, TMethod);
	}
    
    /**
    * Bind (use std::shared_ptr here?)
    */
    template <class T>
    void bind(T* const objPtr , RT (T::*TMethod)(Arg...))
    {
        //the context size have to be identical for each type
        static_assert(sizeof(context<T, decltype(TMethod)>) == sizeof(context_t), "Wrong size");
            
        //use the context for this type
        auto ctx = reinterpret_cast<context<T, decltype(TMethod)>*>(&mem_);
        ctx->obj = objPtr;
        ctx->method = TMethod;
        
        //the lambda function for specific T
        func_ = [](const void* pCtx, Arg... args) -> RT {
            auto ctx = reinterpret_cast<context<T, decltype(TMethod)>*>(const_cast<void*>(pCtx));
            return ((ctx->obj)->*(ctx->method))(args...); 
        };  
    }
    
    void bind(const delegate<RT, Arg...>& obj)
    {
		auto objptr = const_cast<delegate<RT, Arg...>*>(&obj);
		bind<delegate<RT, Arg...>>(objptr, &delegate<RT, Arg...>::call);
	} 
    
    /**
    * unbind
    */
    void unbind()
    {
        func_ = nullptr;
        mem_.obj = nullptr;
        mem_.method = nullptr;
    }

    /**
    * Call Delegate
    */
    inline RT operator()(Arg... args) const
    {
        if(func_ == nullptr)
            return RT();
        return (*func_)(&mem_, args...);
    }
    
	/**
	* This is also required additional to hash
	* to store delegate in hashsets/maps
	* why?
	*/
	bool operator==(const delegate<RT, Arg...>& d) const
	{
		return d.func_ == func_
            && mem_.obj == d.mem_.obj
            && mem_.method == d.mem_.method;
	}
    
private:
    //context structure to save obj and func pointer
    template<class T, typename Method>
    struct context
    {
        T* obj;
        Method method;
    };
    
    //dummy mem allocation for context
    typedef context<delegate<RT, Arg...>, decltype(&delegate<RT, Arg...>::operator())> context_t;
    context_t mem_;
    
    //function pointer for class
    RT (*func_)(const void*, Arg...);
    
    inline RT call(Arg... args)
    {
		operator ()(args...);
	}
};
    
} //end namespace cul

#endif // __CUL_DELEGATE_HPP__
