/*
    C++ Utility Library

    Copyright (c) 2011  okard

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

#include <culcore/Delegate.hpp>

#include <cassert>
#include <iostream>

using namespace cul;

class Foo
{
    
public:
	int value;

    void slot_e()
    {
        std::cout << "Event occured" << std::endl;
    }
    
    void slot(int i)
    {
        std::cout << "Getting " << i << std::endl;
        value = i;
    }
    
    int slot_return(int i)
    {
		value = i;
		return i;
	}
    
};

void func_slot(int i)
{
	std::cout << "Getting " << i << " by function ptr" << std::endl;
}


int main(void)
{
    Foo f;
    
    //delegate without parameter
    delegate<void> d2 = delegate<void>(&f, &Foo::slot_e);
    d2();
    
    //delegate with parameter
    delegate<void, int> d3 = delegate<void, int>(&f, &Foo::slot);
    d3(42);
    assert(f.value == 42);
    
    /*
    d3.bind(&func_slot);
    d3(23);
    */
    
    //unbind and rebind
    d3.unbind();
    d3.bind(&f, &Foo::slot);
    d3(21);
    assert(f.value == 21);
    
    //test delegate chaining 
    delegate<void, int> d4;
    d4.bind(d3);
    d4(123);
    assert(f.value == 123);
    
    //test return value
    delegate<int, int> d5 = delegate<int, int>(&f, &Foo::slot_return);
    assert(d5(321) == 321);
    assert(f.value == 321);
    
    return 0;
}
