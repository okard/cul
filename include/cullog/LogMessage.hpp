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
#ifndef __CUL_LOGMESSAGE_HPP__
#define __CUL_LOGMESSAGE_HPP__

//Cul Includes
#include <culcore/Types.hpp>
#include <cullog/LogType.hpp>

namespace cul {
	
class LogSource;
    
/**
* Represents a Log Message
*/
class LogMessage
{
	friend class LogSource;

private:
	/// LogSource (ptr because of circular imports)
	const LogSource* logSource_;
	
	/// log event type
	LogType logType_;
	
	//TODO date/timestamp
	
	//message buffer
	ubyte8* buf_;
	size_t len_;
	
	//private ctor
	LogMessage(const LogSource* logSource_);
	
	
	LogMessage(const LogMessage& le);
	~LogMessage();
        
public:
	inline LogType getType() const { return logType_; }
	
	inline const LogSource* getLogSource() const { return logSource_; }
	
	inline const char* c_str() const { return reinterpret_cast<const char*>(buf_); }
	inline const size_t len() const { return len_; }
        
};   

} //end namespace cul
    
#endif /* __CUL_LOGMESSAGE_HPP__ */
