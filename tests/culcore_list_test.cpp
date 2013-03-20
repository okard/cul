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

#include <cul/List.hpp>

using namespace cul;

/**
* test list 
*/
void list_test_simple()
{
    List<int> list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    
    std::cout << "List Count: " << list.count() << std::endl;
    assert(list.count() == 4);
}

/**
* test list iterator for loop
*/
void list_test_for()
{
    List<int> list;
    list.add(1);
    list.add(2);
    
    for(ListIterator<int> li(list); li.hasNext(); li.next())
    {
        //print out
        std::cout << "Value: " << li << std::endl;
    }
}

/**
* test list iterator while loop
*/
void list_test_while()
{
    List<int> list;
    list.add(1);
    list.add(2);
    
    ListIterator<int> li(list);
    while(li.next())
    {
        //print out
        std::cout << "Value: " << li << std::endl;
    }
}


/**
* main method
*/
int main(int argc, char *argv[])
{
    list_test_simple();
    list_test_for();
    list_test_while();
    
    return 0;
}
#endif
int main(){return 0;}
