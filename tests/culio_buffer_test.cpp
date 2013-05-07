

#include <culio/Buffer.hpp>

#include <cassert>

class Foo 
{
public:
	int x, y, z;
	
};

int main(void)
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
	
	return 0;
}
