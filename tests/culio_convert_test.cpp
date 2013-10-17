/*
    C++ Utility Library

    Copyright (c) 2011  okard

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

#include "cul_test.hpp"
#include <culio/Convert.hpp>

using namespace cul;


int main(void)
{
    long l = Long::to("6");
    CUL_ASSERT(l == 6l, "Long conversion failed");
    
    unsigned long ul = Long::to("7");
    CUL_ASSERT(ul == 7ul, "ULong conversion failed");
    
    double d = Double::to("5.0");
    CUL_ASSERT(d == 5.0d, "Double conversion failed");
    
    char* str = Str::to(4);
    CUL_ASSERT(str[0] == '4', "Number->String conversion failed");
    delete str;
 
    return 0;
}
