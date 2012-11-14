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
#ifndef __CUL_THREAD_HPP__
#define __CUL_THREAD_HPP__

//TODO Change to a PIMPL Implementation

namespace cul {

//forward declaration
class Thread;

/**
* Thread Call Base
*/
class IThread
{
public:
	/**
	* Virtual destructor
	*/
	virtual ~IThread(){}
	
	/**
	* Thread Run
	*/
	virtual void run(Thread&) = 0;
};

//class ThreadContext(Thread&)
// ThreadContext<T>(Thread&, T data)


/**
* Thread Class
*/
class Thread
{
private:
	//PIMPL Pattern
	class ThreadImpl;
	ThreadImpl* const impl_;
	
	//Thread Wrapper
	IThread* const threadWrapper_;
        
public:
	/**
	* Thread Status
	*/
	enum ThreadStatus
	{
		Running,
		Stop
	};

	/**
	* Construct Thread
	*/
	Thread(IThread* const thread);
	
	/**
	* Destructor
	*/
	~Thread();
	
	/**
	* Start Thread
	*/
	void run();
	
	//change interface
	//run(IThread& thread)
	//run(function thread)

	/**
	* Join thread
	*/
	void join();
	
	//template assign functions
	//template<class T> void run(T* obj, *func);
        
private:
	//status
	//terminate
	//events?
	
};



} //end namespace cul

#endif /* __CUL_THREAD_HPP__ */
