/*
C++ Utility Library

Copyright (c) 2010 okard

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
#include "FileListener.hpp"

//namespaces
using namespace std;
using namespace cul;
using namespace log;

/**
* New file listener to given filename
*/
FileListener::FileListener(const char* filename)
{
    stream.open(filename, ios::out | ios::app);
}

/**
* Destructor
*/
FileListener::~FileListener()
{
    stream.close();
}

/**
* Log Event
*/
void FileListener::logEvent(const LogSource* src, const LogEvent* event)
{
    LogEvent* ev = const_cast<LogEvent*>(event);
    
    stream << "[" << LogType::toString(ev->GetType()) << "]: " << ev->GetStream().str() << std::endl;
}
