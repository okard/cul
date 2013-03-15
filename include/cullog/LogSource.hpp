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
#ifndef __CUL_LOGSOURCE_HPP__
#define __CUL_LOGSOURCE_HPP__

#include <cstdarg>
#include <vector>

#include <culcore/Signal.hpp>
#include <cullog/LogMessage.hpp>

// Common Namespace
namespace cul {
    
/**
* LogSource 
*/
class LogSource
{
friend class Log;
  
public:
	cul::signal<const LogMessage&> onLog;
	        
private:
	/// Log Source Name
	//std::string
	const char* sourceName;
         
	LogSource();
	LogSource(const char* name);
	~LogSource();
 
public:
	void verbose(const char* msg, ...);
	void info(const char* msg, ...);
	void warn(const char* msg, ...);
    void error(const char* msg, ...);
    void fatal(const char* msg, ...);
	
	inline const char* getName() const { return sourceName; }
	
private:
	//use a stack buffer
	void log(LogType type, size_t buf_size, const char* msg, va_list args);
	
	//seperater buffer
	//void log(logType, const char* msg, vp_start start)
		
};

} //end namespace cul

#endif /* __LOGSOURCE_HPP__ */
