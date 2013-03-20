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
#include <cul/Array.hpp>


// value type test
void value_type_test()
{
    Array<int> arr;
    
    arr.add(5);
    arr.add(4);
    arr.add(3);
    
    assert(arr[1] == 4);
}


class Foo
{
};

// class test
void class_type_test()
{
    Array<Foo> arr;
    
    //reference or pointer?
    Foo& foo = arr.add();
}

// class ptr test
void class_ptr_type_test()
{
    Array<Foo*> arr;
    arr.add(new Foo());
}


//test main
int main()
{
    
    
    return 0;
}
#endif
int main(){return 0;}
