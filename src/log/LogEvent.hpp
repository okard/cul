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
#ifndef __LOGEVENT_HPP__
#define __LOGEVENT_HPP__

//Cpp Includes
#include<string>
#include<sstream>


#include "LogType.hpp"
#include "LogSource.hpp"

namespace cul {
namespace log {

class LogSource;
    
/**
* Represents a Log Event
*/
class LogEvent
{
    private:
        /// string string for formatting
        std::ostringstream stream;
        /// log event type
        LogType::LogType logType;
        /// LogSource
        LogSource& logSource;
        
        /**
        * Log the current message
        */
        void log();  
    public:
        /**
        * Log Event Actions
        */
        enum LogEventAction { End, Endl }; 
        
        LogEvent(LogSource&);
        LogEvent(LogSource&, LogType::LogType); 
        LogEvent();
        LogEvent(LogType::LogType);
        ~LogEvent();
        
        std::ostringstream& GetStream();
        LogType::LogType GetType();
        LogSource& GetLogSource();
        
        LogEvent& operator<< (bool& val );
        LogEvent& operator<< (short& val );
        LogEvent& operator<< (unsigned short& val );
        LogEvent& operator<< (int& val );
        LogEvent& operator<< (unsigned int& val );
        LogEvent& operator<< (long& val );
        LogEvent& operator<< (unsigned long& val );
        LogEvent& operator<< (float& val );
        LogEvent& operator<< (double& val );
        LogEvent& operator<< (long double& val );
        LogEvent& operator<< (const void* val );
        LogEvent& operator<< (std::string& val); 
        LogEvent& operator<< (const char* val); 
        LogEvent& operator<< (LogType::LogType);
        LogEvent& operator<< (LogEventAction);
};   

} //end namespace log
} //end namespace cul
    
#endif /* __LOGEVENT_HPP__ */