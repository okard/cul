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
#include <cullog/Log.hpp>

#include <map>

using namespace cul;

//== LOG ======================================================================

/**
* Constructor
*/
Log::Log()
{
  
}

Log::Log(const Log& cc)
{
}

/**
* Destructor
*/
Log::~Log()
{
  
}


/**
* Create a new LogSource with given name 
*/
LogSource& Log::Source(const char* name, bool reg)
{
	static std::map<const char*, LogSource*> sources;
	
	if(sources.count(name))
	{
		return *sources[name];
	}
	
	sources[name] = new LogSource(name);
	
	//register callback to root event
	if(reg)
		sources[name]->onLog.connect(Log::Source().onLog);
	
	return *sources[name];
}
 
  /**
* Return the default LogSource
*/
LogSource& Log::Source()
{
	static LogSource log(nullptr);
	return log;
}

