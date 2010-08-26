/*
    C++ Utility Library
    Copyright (C) 2010  okard

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*/
#include <cassert>
#include <iostream>
#include <String.hpp>
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