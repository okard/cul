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


#include <unordered_set>
//#include <culcore/Hash.hpp>
#include <culcore/Delegate.hpp>


namespace std {

/**
* Hash function for delegate
* required for signal class to use delegates in hashsets/maps
*/
template<typename RT, typename... Arg>
struct hash<cul::delegate<RT, Arg...> > {
public:
    size_t operator()(const cul::delegate<RT, Arg...>& dg) const
    {
		const unsigned char* ptr = reinterpret_cast<const unsigned char*>(&dg);
		const size_t size = sizeof(cul::delegate<RT, Arg...>);
		
		size_t hash = 0;
		for (int i=0; i<size; i++) 
		{
			hash = 5*hash + ptr[i];
		}
		return hash;
    }
};

} //end namespace std


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
    //TODO right hash function
    std::unordered_set<dg> listener;
    
    //list with functions pointers
    std::unordered_set<func> funcs;

public:
    
    /**
    * connect to object
    */
    template <class T>
    void connect(T* obj, void (T::*TMethod)(Arg...) )
    {
        listener.insert(dg(obj, TMethod));
    }
    
    /**
    * connect to a delegate
    */
    void connect(dg d)
    {
		listener.insert(d);
	}
    
    /**
    * Connect to simple function
    */
    void connect(func f)
    {
        funcs.insert(f);
    }
    
    /**
    * Disconnect class mapping function
    */
    template <class T>
    void disconnect(T* obj, void (T::*TMethod)(Arg...))
    {
		listener.erase(dg(obj, TMethod));
	}
	
	/**
	* Disconnects a delegate
	*/
	void disconnect(dg d)
	{
		listener.erase(d);
	}
    
    /**
    * Disconnect event handling function
    */
    void disconnect(func f)
    {
		funcs.erase(f);
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
