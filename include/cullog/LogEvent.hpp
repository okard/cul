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
#ifndef __CUL_LOGEVENT_HPP__
#define __CUL_LOGEVENT_HPP__

//Cpp Includes
#include <vector>

//Cul Includes
#include <culcore/Types.hpp>
#include <cullog/LogType.hpp>

namespace cul {
	
class LogSource;
    
/**
* Represents a Log Event
*/
class LogEvent
{
friend class LogSource;

private:
	/// LogSource
	const LogSource* logSource_;
	
	/// log event type
	LogType::LogType logType_;
	
	//date
	
	//message buffer
	std::vector<cul::ubyte8> buffer_;
	
	//private ctor
	LogEvent(const LogSource* logSource_);
	LogEvent(const LogEvent& le);
	~LogEvent();
        
public:
	inline LogType::LogType GetType() const { return logType_; }
	
	inline const LogSource* getLogSource() const { return logSource_; }
	
	const char* c_str() const { return reinterpret_cast<const char*>(&buffer_[0]); }
        
};   

} //end namespace cul
    
#endif /* __LOGEVENT_HPP__ */
