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

#include <culcore/Hash.hpp>

#include <unordered_map>

using namespace cul;

class Foo 
{
public:
	int x, y, z;
	
};

void cul_hash_test()
{
	    Foo f;
    f.x=3;
    f.y=4;
    f.z=5;
    
	//simple general hash test
    cul::general_hash<Foo> hasher1;
    const size_t h1 = hasher1(f);
    const size_t h2 = hasher1(f);
    assert(h1 == h2);
    
    //difference test
    f.y=5;
    const size_t h3 = hasher1(f);
    assert(h1 != h3);
    
    //back to equal
    f.y=4;
    const size_t h4 = hasher1(f);
    assert(h1 == h4);
    
	std::unordered_map<Foo, int, cul::general_hash<Foo>> ids;

}
CUL_TEST(cul_hash_test)


