/*
    C++ Utility Library

    Copyright (c) 2014  okard

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

#include <culio/ByteBuffer.hpp>

using namespace cul;

class Foo 
{
public:
	int x, y, z;
	
	static int count;
	Foo()
	{
		count++;
	}
	
	~Foo()
	{
		count--;
	}
};

int Foo::count = 0;


void test_bytebuffer_simple()
{
	cul::ByteBuffer buf1(5);
	
	for(int i=0; i < 5; i++)
	{
		buf1[i] = i;
		assert(buf1[i] == i);
	}
		
	buf1.resize(10);
	
	for(int i=0; i < 5; i++)
		assert(buf1[i] == i);
		
	for(int i=5; i < 10; i++)
	{
		buf1[i] = i;
		assert(buf1[i] == i);
	}
}

/*
void test_buffer_objects()
{
	cul::Buffer<Foo> buf(5);
	assert(Foo::count == 5);
	
	buf[1].x = 6;
	buf[3].y = 5;
	buf[2].z = 4;
	
	buf.resize(10);
	assert(Foo::count == 10);
	
	assert(buf[1].x == 6);
	assert(buf[3].y == 5);
	assert(buf[2].z == 4);
	
	buf.resize(11);
	assert(Foo::count == 11);
	
	assert(buf[1].x == 6);
	assert(buf[3].y == 5);
	assert(buf[2].z == 4);
	
	buf.resize(5);
	assert(Foo::count == 5);
	
	assert(buf[1].x == 6);
	assert(buf[3].y == 5);
	assert(buf[2].z == 4);
}*/

