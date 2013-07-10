

#include <culio/ByteBuffer.hpp>

#include <cassert>

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
}


int main(void)
{
	test_bytebuffer_simple();
	test_buffer_objects();
	
	return 0;
}
