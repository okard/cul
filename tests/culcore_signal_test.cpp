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
#include <culcore/Assert.hpp>
#include <cultest/Test.hpp>

#include <culsignal/Signal.hpp>

#include<iostream>

void basic_handler(int i)
{
    //std::cout << "Value: " << i << std::endl;
};


class Foo
{
private:
    cul::signal<int> onEvent;
public:
    
    Foo()
    {
        onEvent.connect(this, &Foo::handle);
        onEvent.connect(&basic_handler);
    }
    
    void fire(int i)
    {
        onEvent(i);
    }
    
    void handle(int i)
    {
        //std::cout << "Value: " << i << std::endl;
    }
    
};

void cul_signal_test()
{
	Foo f;
    f.fire(10);
}
CUL_TEST(cul_signal_test)
