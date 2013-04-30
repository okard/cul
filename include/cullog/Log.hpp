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
#ifndef __CUL_LOG_HPP__
#define __CUL_LOG_HPP__

//CUL Includes
#include <cullog/LogType.hpp>
#include <cullog/LogSource.hpp>

//Basic Log Macro

#define LOG(x) cul::Log::Source().info("File: %s Line: %d Message: %s", __FILE__, __LINE__, #x);

//Debug Log Macro
#ifdef DEBUG
    #define DEBUGMSG(x) cul::Log::Source().verbose("File: %s Line: %d Message: %s", __FILE__, __LINE__, #x);
#else
    #define DEBUGMSG(x) /*x*/
#endif


// Common Namespace
namespace cul {
    
/**
* Logger
*/
class Log
{
  private:
    Log();
    Log(const Log& cc);
    virtual ~Log();
  public:

    /**
    * Create a new LogSource with given name
    * reg: register callback of root log source handler 
    */
    static LogSource& Source(const char* name, bool reg = true);
    
    /**
    * Return the default LogSource
    */
    static LogSource& Source();
    
    
    static LogSignal& onLog();
};

} //end namespace cul

#endif // __CUL_LOG_HPP__
