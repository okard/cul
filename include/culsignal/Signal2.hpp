/*
    C++ Utility Library

    Copyright (c) 2014  okard

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
#ifndef CUL_SIGNAL2_HPP
#define CUL_SIGNAL2_HPP

namespace cul {
	
//Generic Callback
template<typename RT, typename... Args>
class Callback
{
public:
	virtual RT operator ()(Args... arg) const = 0;
	
	//compare?
};

//class callback
template<typename T, typename RT, typename... Args>
class MethodCallback : public Callback<RT, Args...>
{
private:
	T* const obj_;	
	
	RT (T::*function_)(Args...) = nullptr;	
public:

	MethodCallback(T* obj, RT (T::*function)(Args...))
		: obj_(obj), function_(function)
	{
	}
	
	virtual RT operator ()(Args... arg) const
	{
		(*obj_.*function_)(arg...);
	}
};


//signals
template<int slots=10, typename... Args>
class Signal
{
private:
	Callback<void, Args...>* callbacks_[slots] = {nullptr};
	
	
	class ConnectCtx
	{
	
	public:
		Signal<slots, Args...>& sig_;
		int i_=-1;
		
		ConnectCtx(Signal<slots, Args...>& sig, int i)
			: sig_(sig), i_(i)
		{
		}
		
		~ConnectCtx()
		{
			delete sig_.callbacks_[i_];
			sig_.callbacks_[i_] = nullptr;
		}
	};
	
public:

	~Signal()
	{
		for(int i=0; i < slots; i++)
		{
			if(callbacks_[i] != nullptr)
			{
				delete callbacks_[i];
			}
		}
	}

	/**
    * connect to object
    */
    template <class T>
    const ConnectCtx connect(T* obj, void (T::*Method)(Args...) )
    {
		for(int i=0; i < slots; i++)
		{
			if(callbacks_[i] == nullptr)
			{
				callbacks_[i] = new MethodCallback<T, void, Args...>(obj, Method);
				return ConnectCtx(*this, i);
			}
		}
		throw "error";
    }


	void operator ()(Args... arg) const
	{
		for(int i=0; i < slots; i++)
		{
			if(callbacks_[i] != nullptr)
			{
				(*callbacks_[i])(arg...);
			}
		}
	}

};


	
}


#endif // CUL_SIGNAL2_HPP
