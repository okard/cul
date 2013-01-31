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
#include <culio/Console.hpp>

#include <cstdio>

using namespace cul;

ConsoleStream::ConsoleStream()
{
}

ConsoleStream::ConsoleStream(const ConsoleStream& cstream)
{
}

/**
* Write string
*/
ConsoleStream& ConsoleStream::write(const char* str)
{
    fputs(str, stdout);
    return *this;
}
        
/**
* Write line
*/
ConsoleStream& ConsoleStream::writeLn(const char* str)
{   
    puts(str);
    return *this;
}
        
/**
* get singleton
*/
ConsoleStream& ConsoleStream::getSingleton()
{
    static ConsoleStream cstream;
    return cstream;
}


/*
	(const char* fmt, ...)
	
	const int buffer_size = 1024;
	char buffer[buffer_size];
	va_list argument_list;

	// Print the message to the buffer.
	va_start(argument_list, fmt);
	int len = vsnprintf(buffer, buffer_size - 2, fmt, argument_list);	
	if (len < 0 || len > buffer_size - 2)	
	{
		len = buffer_size - 2;
	}	
	buffer[len] = '\0';
	va_end(argument_list);
*/

