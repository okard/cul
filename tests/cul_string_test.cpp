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
#if 0
#include <cassert>
#include <iostream>
#include <culio/String.hpp>
using namespace cul;

/// simple test for string equal
void string_test_equal_simple()
{
    string a = "hello";
    string b = "hello";
    
    assert(a == b);
}

/**
* test basic equal and string assignment
*/
void string_test_basic()
{
    //test assign const char*
    string str = "hello";
    assert(str == "hello");
    
    //test reassign const char*
    str = "foobar";
    assert(str == "foobar");
}

/**
* some extended basic tests 
*/
void string_test_extended()
{
    //test append char
    //test assign const char*
    string a = "hello";
    a.append(' ');
    a.append('w');
    a.append('o');
    std::cout << "string_test_extended: " << a.c_str() << std::endl;
    assert(a == "hello wo");
   
    
    //test assign string
    string b = a;
    assert(b == a);
    
    //test append string
    b = "rld";
    a.append(b);
    std::cout << "a: " << a.c_str() << " length: " << a.len() << std::endl;
    assert(a == "hello world");
}

/**
* next string tests
*/
void string_test_extended2()
{
    string a = "foobar";
    string b;
    b = a;
    assert(a == b);
}

/**
* test growing memory
*/
void string_test_growing()
{
    string a = "";
    assert(a.len() == 0);
    assert(a.mem() == 0);
    
    //char append
    a.append('h');
    assert(a.len() == 1);
    assert(a.mem() == 1);
    
    //const char* append
    a.append("ello");
    assert(a.len() == 5);
    assert(a.mem() == 5);
    
    //string append
    string b = " world"; 
    a.append(b);
    assert(a.len() == 11);
    assert(a.mem() == 11);
    
    //short
    a = "hello";
    assert(a.len() == 5);
    assert(a.mem() == 11);
}

/**
* test pre alloc mem ctor
*/
void string_test_memctr()
{
    string a(8);
    assert(a.len() == 0);
    assert(a.mem() == 8);
}

/**
* test some operators
*/
void string_test_operators()
{
    string a = "hello ";
    a += "world";
    assert(a == "hello world");
    assert(a != "hello ");
    
    string b = "!";
    a += b;
    assert(a == "hello world!");
}


/**
* main method
*/
int main(int argc, char *argv[])
{
    string_test_equal_simple();
    string_test_basic();
    string_test_extended();
    string_test_extended2();
    string_test_growing();
    string_test_memctr();
    string_test_operators();
    
    return 0;
}
#endif
int main(){return 0;}
