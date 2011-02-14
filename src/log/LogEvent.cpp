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
#include <cul/log/LogEvent.hpp>

#include <cul/log/Log.hpp>

using namespace cul;
using namespace log;

//== LOGEVENT =================================================================

/**
* Constructor
*/
LogEvent::LogEvent(LogSource& source) : logSource(source), logType(LogType::Information)
{
}

/**
* Constructor
*/
LogEvent::LogEvent(LogSource& source, LogType::LogType type): logSource(source), logType(type)
{
}

/**
* Constructor
*/
LogEvent::LogEvent() : logSource(Log::Source()), logType(LogType::Information)
{
}

/**
* Constructor
*/
LogEvent::LogEvent(LogType::LogType type) : logSource(Log::Source()), logType(type)
{
}


/**
* Destructor
*/
LogEvent::~LogEvent()
{
   log();
}

/**
* Internal log event
*/
void LogEvent::log()
{
    if(stream.str().size() > 0)
    {
        logSource.logEvent(&logSource, this);
        stream.clear();
        stream.str("");
    }
}

/**
* Returning the interal ostringstream for logging listener
*/
std::ostringstream& LogEvent::GetStream()
{
    return stream;
}

/**
* Return the type
*/
LogType::LogType LogEvent::GetType() const
{
    return logType;
}

/**
* Gets the LogSource
*/
LogSource& LogEvent::GetLogSource() const
{
    return logSource;
}

/**
* Append a bool value to log message
*/
LogEvent& LogEvent::operator<<(bool& val)
{
    stream << val;
    return *this;
}

/**
* Append a short int value to log message
*/
LogEvent& LogEvent::operator<<(short int& val)
{
    stream << val;
    return *this;
}

LogEvent& LogEvent::operator<<(short unsigned int& val)
{
    stream << val;
    return *this;
}

LogEvent& LogEvent::operator<<(int& val)
{
    stream << val;
    return *this;
}

LogEvent& LogEvent::operator<<(unsigned int& val)
{
    stream << val;
    return *this;
}

LogEvent& LogEvent::operator<<(long int& val)
{
    stream << val;
    return *this;
}

LogEvent& LogEvent::operator<<(long unsigned int& val)
{
    stream << val;
    return *this;
}

LogEvent& LogEvent::operator<<(float& val)
{
    stream << val;
    return *this;
}

LogEvent& LogEvent::operator<<(double& val)
{
    stream << val;
    return *this;
}

LogEvent& LogEvent::operator<<(long double& val)
{
    stream << val;
    return *this;
}

LogEvent& LogEvent::operator<<(const void* val)
{
    stream << val;
    return *this;
}

LogEvent& LogEvent::operator<<(std::string& val)
{
    stream << val;
    return *this;
}

LogEvent& LogEvent::operator<<(const char* val)
{
    stream << val;
    return *this;
}

/**
* Set LogType of log message
*/
LogEvent& LogEvent::operator<<(LogType::LogType type)
{
    logType = type;
    return *this;
}


/**
* Execute Log Action
*/
LogEvent& LogEvent::operator<<(LogEvent::LogEventAction action )
{
    switch(action)
    {
        case Endl:
            stream << std::endl; break;
        default:
            log();
    }
    return *this;
}
