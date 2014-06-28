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

#include <culcore/Singleton.hpp>

using namespace cul;

/**
* Singleton Test Class
*/
class mySingleton : public cul::Singleton<mySingleton>
{
    //friend class for access to private constructor
    friend class cul::Singleton<mySingleton>;
    
    private:
      ///Constructor
      mySingleton() : value(5) {}
      /// Copy Constructor
      mySingleton(const mySingleton& cc){}
      
      ///test value
      int value;

    public:
        ///get test value
        int get()
        {
            return value;
        }
        
        ///set test value
        void set(int value)
        {
            this->value = value;
        }
        
};

/**
* Simple singleton test cases
*/
void singleton_test_simple()
{
    //basic asserts
    assert(mySingleton::getSingletonPtr() == mySingleton::getSingletonPtr());
    assert(mySingleton::getSingleton().get() == mySingleton::getSingleton().get());
    
    //test pointer
    mySingleton* my = mySingleton::getSingletonPtr();
    assert(my->get() == 5);
    
    //test reference
    mySingleton& mm = mySingleton::getSingleton();
    assert(mm.get() == 5);
    
    //test changing
    my->set(42);
    assert(mm.get() == 42);
}
CUL_TEST(singleton_test_simple)


