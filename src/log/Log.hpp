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
#ifndef LOG_H
#define LOG_H


//CUL Includes
#include "LogType.hpp"
#include "LogListener.hpp"
#include "LogEvent.hpp"
#include "LogSource.hpp"


//Basic Log Macro
#define LOG(x) cul::log::Log::Event() << x << cul::log::LogEvent::End;

//Debug Log Macro
#ifdef DEBUG
    #define DEBUGMSG(x) cul::log::Log::Event() << x << cul::log::LogEvent::End;
#else
    #define DEBUGMSG(x) /*x*/
#endif


// Common Namespace
namespace cul {
namespace log {
    
/**
* Logger
*/
class Log : public LogSource, public LogListener
{
  private:
    Log();
    Log(const Log& cc);

  public:
    virtual ~Log();
    
    /**
    * Create a new LogSource with given name 
    */
    static LogSource* Source(const char* name);
    
    /**
    * Return the default LogSource
    */
    static LogSource& Source();
    
    /**
    * Return default log event
    */
    static LogEvent& Event();
    
    /**
    * Get Instacne of logging class
    */
    static Log& getInstance();

    /**
    * Implemented Log Listener Interface
    */
    virtual void logEvent(const LogSource* src, const LogEvent* event);
};

} //end namespace log
} //end namespace cul

#endif // LOG_H
