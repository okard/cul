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
#include <cul/log/Log.hpp>

using namespace cul;
using namespace log;

//== LOG ======================================================================

/**
* Constructor
*/
Log::Log()
{
  
}

/**
* Destructor
*/
Log::~Log()
{
  
}

/**
* LogListener interface
* dispatch the event to the internal log source
*/
void Log::logEvent(const LogSource* src, const LogEvent* event)
{
  LogSource::logEvent(src, event);
}

/**
* Get Instance
*/
Log& Log::getInstance()
{
    static Log instance;
    return instance;
};


/**
* Creates a new LogSource
*/
LogSource* Log::Source(const char* name)
{
  LogSource *log = new LogSource(name);
  
  //Add Default Listener
  log->AddListener(&Log::getInstance());
  
  return log;
}

/**
* Return Default LogSource
*/
LogSource& Log::Source()
{
    return Log::getInstance();
}

/**
* Return default log event 
*/
LogEvent& Log::Event()
{
    return Source().Event();
}
    
  