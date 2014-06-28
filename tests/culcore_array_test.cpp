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
#include <culcore/Assert.hpp>
#include <cultest/Test.hpp>

#include <iostream>
#include <memory>

#include <culcollection/DynArray.hpp>

using namespace cul;


// value type test
void cul_dynarray_value_type_test()
{
    DynArray<ubyte8> arr(10);
    
    for(int i=0; i < 10; i++)
    {
		arr[i] = i;
	}
    
    assert(arr[2] == 2);
}
CUL_TEST(cul_dynarray_value_type_test)


class DynArray_Foo
{
public:
	static int counter;
	
	int x;
	
	DynArray_Foo()
	{
		x = DynArray_Foo::counter;
		DynArray_Foo::counter++;
	}
	
};

int DynArray_Foo::counter = 0;


// class test
void cul_dynarray_class_type_test()
{
	DynArray_Foo::counter = 0;
    DynArray<DynArray_Foo> arr(10);
    
    assert(arr[5].x == 5);
    //std::cout << DynArray_Foo::counter << std::endl;
    assert(DynArray_Foo::counter == 10);
}
CUL_TEST(cul_dynarray_class_type_test)

// class ptr test
void cul_dynarray_class_ptr_type_test()
{
	DynArray_Foo::counter = 0;
    DynArray<std::shared_ptr<DynArray_Foo>> arr(10);
    
    arr[5] = std::shared_ptr<DynArray_Foo>(new DynArray_Foo());
    
    assert(arr[5]->x == 0);
    assert(DynArray_Foo::counter == 1);
    
    arr[6] = std::make_shared<DynArray_Foo>();
    assert(arr[6]->x == 1);
    assert(DynArray_Foo::counter == 2);
}
CUL_TEST(cul_dynarray_class_ptr_type_test)
