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
#if 1
#include <cassert>
#include <iostream>
#include <memory>
#include <culcore/Array.hpp>

using namespace cul;


// value type test
void value_type_test()
{
    Array<int> arr(10);
    
    for(int i=0; i < 10; i++)
    {
		arr[i] = i;
	}
    
    assert(arr[2] == 2);
}


class Foo
{
public:
	static int counter;
	
	int x;
	
	Foo()
	{
		x = Foo::counter;
		Foo::counter++;
	}
	
};

int Foo::counter = 0;


// class test
void class_type_test()
{
	Foo::counter = 0;
    Array<Foo> arr(10);
    
    assert(arr[5].x == 5);
    assert(Foo::counter == 10);
}

// class ptr test
void class_ptr_type_test()
{
	Foo::counter = 0;
    Array<std::shared_ptr<Foo>> arr(10);
    
    arr[5] = std::shared_ptr<Foo>(new Foo());
    
    assert(arr[5]->x == 0);
    assert(Foo::counter == 1);
    
    arr[6] = std::make_shared<Foo>();
    assert(arr[6]->x == 1);
    assert(Foo::counter == 2);
}


//test main
int main()
{
    value_type_test();
    class_type_test();
    class_ptr_type_test();
    
    return 0;
}
#else
	int main(){return 0;}
#endif
