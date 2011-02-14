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
#include <cul/net/Socket.hpp>

#include <cul/Exception.hpp>

using namespace cul;
using namespace net;


/**
* Create a new Socket
*/
Socket::Socket()
{
    initialize();
}

/**
* Destructs socket
*/
Socket::~Socket()
{

}

/**
* Initialize Socket
*/
void Socket::initialize()
{
    #ifdef WIN32
    static bool init = false;
    if(!init)
    {
        WSADATA wsa;
        if (WSAStartup(MAKEWORD(1, 1), &wsa))
        {
            // (unsigned long)GetLastError()
            throw new Exception("WSAStartup failed");
        }
    }
    #endif
  
}

 

