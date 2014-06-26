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
#pragma once
#ifndef CUL_TEST_HPP
#define CUL_TEST_HPP

#include <functional>


#define CUL_ENTRY(name) {#name, name}
#define CUL_TEST(name) cul::Test test_reg_ ## name = CUL_ENTRY(name);

namespace cul {

class Test;
class TestModule;

/**
 * @brief The TestRunner class
 * Public interface for tests
 */
class TestRunner
{
private:
	//use private class here to completly hide the implementation in this header
	class Impl;
	static Impl& get();

	TestRunner() = default;
	TestRunner(const TestRunner&) = delete;
	TestRunner& operator=(const TestRunner& rhs) = delete;

public:
	//handle args?
	//void args(int argc, char *argv[]);

	//before all
	//after all

	//public interface
	static void reg_test(Test* t);
	static void reg_mod(TestModule* m);
	static void run_tests();
};


/**
* @brief The TestModule class
* a bunch of tests to a category
*/
class TestModule
{
private:
	const char* desc;
public:
//get tests

	//init with Test[] arr
};


/**
* this class is statically created for a single test
*
* CUL_TEST(file1_test1);
* cul::Test test = {"test1", file1_test1};
*/
struct Test
{
	const char* desc;
	const std::function<void()> test_function;
	
	Test(const char* desc, const std::function<void()> test_func)
		: desc(desc), test_function(test_func)
	{
		TestRunner::reg_test(this);
	}
};






} //end namespace cul

#endif
