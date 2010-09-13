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
#include "LogSource.hpp"

using namespace cul;
using namespace log;

//== LOGSOURCE ================================================================

/**
* Constructor 
*/
LogSource::LogSource() : sourceName(""), event(0)
{
    event = new LogEvent(*this);
}

/**
* Constructor 
*/
LogSource::LogSource(const char* name) : sourceName(name), event(0)
{
    event = new LogEvent(*this);
}

/**
* Destructor
*/
LogSource::~LogSource()
{
    delete event;
}


/**
* Add Log Listener
*/
void LogSource::AddListener(LogListener* listener)
{
  this->listener.push_back(listener);
}

/**
* Dispatch logevent to listener
*/
void LogSource::logEvent(const LogSource* src, const LogEvent* event)
{
   //Inform all listener
    for(std::vector<LogListener*>::iterator it = listener.begin(); it != listener.end(); it++)
    {
      (*it)->logEvent(this, event);
    }
}

/**
* Log a Simple Message
*/
void LogSource::Log(LogType::LogType logType, const char* msg)
{
    //TODO make save
    LogEvent event(*this, logType);
    event << msg;
    this->logEvent(this, &event);
}

/**
* Return default log event
*/
LogEvent& LogSource::Event()
{
    return *event;
}
