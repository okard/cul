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

//Cpp Includes
#include<string>
#include<sstream>

//STL Includes
#include<vector>

//Basic Log Macro
#define LOG(x) cul::log::Log::Source().Event() << x << cul::log::LogEvent::End;

//Debug Log Macro
#ifdef DEBUG
    #define DEBUGMSG(x) cul::log::LogEvent() << x << cul::log::LogEvent::End;
#else
    #define DEBUGMSG(x) /*x*/
#endif


// Common Namespace
namespace cul {
namespace log {

//forward declaration
class LogSource;


//TODO Fix stupid enum
namespace LogType
{
    /**
    * Logging Types
    */
    enum LogType
    {
    Verbose,
    Information,
    Warning,
    Error,
    Fatal
    };
    
    /**
    * Convert a LogType to String
    */
    const char* toString(LogType type);
}

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


/**
* LogListener
*/
class LogListener
{
  public:
    virtual ~LogListener()
    { }
    
  public:
    virtual void logEvent(const LogSource* src, const LogEvent* event) = 0;
};

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
