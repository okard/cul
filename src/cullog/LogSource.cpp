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

#include <cstdarg>
#include <cstdio>

#include <cullog/LogSource.hpp>

using namespace cul;

//== LOGSOURCE ================================================================

/**
* Constructor 
*/
LogSource::LogSource() 
	: sourceName(""), msgBufferSize_(1024)
{
}

/**
* Constructor 
*/
LogSource::LogSource(const char* name) 
	: sourceName(name), msgBufferSize_(1024)
{
}

/**
* Destructor
*/
LogSource::~LogSource()
{
}

void LogSource::verbose(const char* msg, ...)
{
	va_list argument_list;
	va_start(argument_list, msg);
	log(LogType::Verbose, msgBufferSize_, msg, argument_list);
	va_end(argument_list);
}

void LogSource::info(const char* msg, ...)
{
	va_list argument_list;
	va_start(argument_list, msg);
	log(LogType::Information, msgBufferSize_, msg, argument_list);
	va_end(argument_list);
}

void LogSource::warn(const char* msg, ...)
{
	va_list argument_list;
	va_start(argument_list, msg);
	log(LogType::Warning, msgBufferSize_, msg, argument_list);
	va_end(argument_list);
}

void LogSource::error(const char* msg, ...)
{
	va_list argument_list;
	va_start(argument_list, msg);
	log(LogType::Error, msgBufferSize_, msg, argument_list);
	va_end(argument_list);
}

void LogSource::fatal(const char* msg, ...)
{
	va_list argument_list;
	va_start(argument_list, msg);
	log(LogType::Fatal, msgBufferSize_, msg, argument_list);
	va_end(argument_list);
}

void LogSource::log(LogType type, size_t buf_size, const char* msg, va_list args)
{
	//format message
	ubyte8 buf[buf_size];
	
	size_t len = vsnprintf(reinterpret_cast<char*>(buf), buf_size - 2, msg, args);
	if(len < 0 || len > buf_size - 2)  
	{
		len = buf_size - 2;
	}
	buf[len] = '\0';
	
	//handle log message
	LogMessage le(this);
	le.buf_ = buf;
	le.logType_ = type;
	le.len_ = len;
	onLog(le);
}
