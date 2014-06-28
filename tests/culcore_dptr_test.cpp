/*
    C++ Utility Library

    Copyright (c) 2013  okard

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

#include <culcore/DPtr.hpp>
#include <culcore/DPtrImpl.hpp>

#include <iostream>

using namespace cul;

class Foo
{
private:
	class Impl;
	cul::dptr<Impl> impl_;
	
public:
	void test(int i);
	int get() const;
};


class Foo::Impl
{
private:
	int i=0;
public:
	void test(int i)
	{
		this->i=i;
	}
	
	int get() const
	{
		return i;
	}
};

void Foo::test(int i)
{
	impl_->test(i);
}

int Foo::get() const
{
	return impl_->get();
}

/*
void dptr_test()
{
	Foo f;
	assert(f.get() == 0);
	f.test(5);
	assert(f.get() == 5);
    
}
CUL_TEST(dptr_test)
*/
