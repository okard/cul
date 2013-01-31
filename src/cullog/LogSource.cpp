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
	: sourceName("")
{
}

/**
* Constructor 
*/
LogSource::LogSource(const char* name) 
	: sourceName(name)
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
	LogEvent le(this);
	
	le.logType_ = LogType::Verbose;
	le.buffer_.resize(1024);
	
	//but into buffer
	va_list argument_list;
	va_start(argument_list, msg);
	int len = vsnprintf(reinterpret_cast<char*>(&le.buffer_[0]), le.buffer_.size() - 2, msg, argument_list);  

	if(len < 0 || len > le.buffer_.size() - 2)  
	{
		len = le.buffer_.size() - 2;
	}
	le.buffer_[len] = '\0';
	va_end(argument_list);
	
	onLog_(le);
}
