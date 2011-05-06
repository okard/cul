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

#include <cul/Delegate.hpp>

#include <iostream>

using namespace cul;

class Foo
{
    
public:
    void slot_e()
    {
        std::cout << "Event occured" << std::endl;
    }
    
    void slot(int i)
    {
        std::cout << "Getting " << i << std::endl;
    }
    
};

int main(void)
{
    Foo f;

    delegate0<void> d0 = delegate0<void>::create<Foo, &Foo::slot_e>(&f);
    d0();
        
    delegate1<void, int> d1 = delegate1<void, int>::create<Foo, &Foo::slot>(&f);
    d1(42);
    

    
    return 0;
}