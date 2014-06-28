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

#include <culmem/RefPtr.hpp>

#include <iostream>
using namespace std;
using namespace cul;

//#define NDEBUG

///helper test class
class testcls
{
    public:
        /// count of class instances
        static int count;
        testcls() {count++;}
        ~testcls() {count--;}
};

int testcls::count = 0;

/**
* Simple test
*/
void refptr_test_simple()
{
    cout << "refptr_test_simple" << endl;
    RefPtr<int> a(new int(5));
    RefPtr<int> b = a;

    assert(b.refcount() == 2);
    assert(a.refcount() == 2);
    assert((*b) == 5);
    assert((*a) == 5);
}

/**
* Simple test 2
*/
void refptr_test_simple2()
{
    cout << "refptr_test_simple2" << endl;
    RefPtr<int> a(new int(6));
    RefPtr<int> b;
    b = a;

    assert(b.refcount() == 2);
    assert(a.refcount() == 2);
    assert((*b) == 6);
    assert((*a) == 6);
}

/**
* Test deletion of ref object
*/
void refptr_test_deletion()
{
    cout << "refptr_test_deletion" << endl;
    assert(testcls::count == 0);
    RefPtr<testcls>* a = new RefPtr<testcls>(new testcls());
    assert(testcls::count == 1);
    delete a;
    assert(testcls::count == 0);
}

/**
* Test deletion of ref object 2
*/
void refptr_test_deletion2()
{
    cout << "refptr_test_deletion2" << endl;
    assert(testcls::count == 0);
    RefPtr<testcls>* a = new RefPtr<testcls>(new testcls());
    RefPtr<testcls>* b = new RefPtr<testcls>();
    (*b) = (*a);
    assert(testcls::count == 1);
    assert((*a).refcount() == 2);

    delete a;
    assert(testcls::count == 1);
    assert((*b).refcount() == 1);

    delete b;
    assert(testcls::count == 0);
}

/**
* Test deletion of ref object 3
*/
void refptr_test_deletion3()
{
    cout << "refptr_test_deletion3" << endl;
    assert(testcls::count == 0);
    RefPtr<testcls> a(new testcls());
    assert(testcls::count == 1);
    a = new testcls();
    assert(testcls::count == 1);
}


