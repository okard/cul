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
#ifndef __LOGSOURCE_HPP__
#define __LOGSOURCE_HPP__

#include <vector>

#include "LogEvent.hpp"
#include "LogListener.hpp"

// Common Namespace
namespace cul {
namespace log {
    
class LogListener;
class LogEvent;

/**
* LogSource 
*/
class LogSource
{
    friend class Log;
    friend class LogEvent;
  
    private:
        /// Log Source Name
        const char* sourceName;
        /// Listener
        std::vector<LogListener*> listener;
    
        ///internal log event?
        LogEvent* event;
    private:
        LogSource();
        LogSource(const char* name);
        ~LogSource();
 
    protected:
        /**
        * Internal Log Event Dispatch to Listener
        */
        void logEvent(const LogSource* src, const LogEvent* event); 
    public:
        /**
        * Add a log listener to log source
        */
        void AddListener(LogListener* listener);
        
        /**
        * Log a Simple Message
        */
        void Log(LogType::LogType logType, const char* msg);  
        
        /**
        * Get a Default Event
        */
        LogEvent& Event();
};

} //end namespace log
} //end namespace cul

#endif /* __LOGSOURCE_HPP__ */