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
#include <iostream>

#include <cullog/Log.hpp>
#include <cullog/LogType.hpp>

using namespace cul;

void logging_test_source()
{
    LogSource& ls = Log::Source("logging_test_source");
    
    ls.onLog_.connect([] (const LogMessage& le) { 
		std::cout << le.getLogSource()->getName() << ": ";
		std::cout << toString(le.getType()) << ": ";
		std::cout << le.c_str() << std::endl;
	});
    
    ls.verbose("Hello %s", "World");
}

void logging_test_formats()
{

}


/**
* Main function
*/
int main(int argc, char *argv[])
{
    LOG("Log test started");
    DEBUGMSG("Debug Message");
    
    //log tests
    logging_test_source();
    logging_test_formats();
    
    return 0;
}
