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
#include <culcore/TypeTpl.hpp>
#include <culcore/Assert.hpp>
#include <cultest/Test.hpp>

using namespace cul;

namespace typetpl {

template<typename R, typename... Args>
class Test
{
public:
	R Print(Args&... args)
	{
	}
};

template<typename R, template<typename> class Wrapper, typename... Args>
class Test2
{
public:
	R Print(Wrapper<int> i, Args&... args)
	{
	}
};

enum class TestE : int
{
	ABC = 1,
	FOOBAR = 5
};

} //end namespace

void cul_typetpl_test()
{
	typetpl::Test<Pure<int>, ConstRef<int>, Ref<int>> test;
	int i=3;
	test.Print(2, i);
	
	typetpl::Test2<Pure<int>, Pure> test2;
	test2.Print(1);
	
	CUL_ASSERT(EnumValue(typetpl::TestE::FOOBAR) == 5, "Fail")
}

CUL_TEST(cul_typetpl_test)
