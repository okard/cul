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
#ifndef CUL_TESTIMPL_HPP
#define CUL_TESTIMPL_HPP

#include <vector>
#include <iostream>
#include <chrono>
#include <cmath>

#include <culcore/Test.hpp>



namespace cul {

/**
* @brief The TestRunner::Impl class
* The inner implementation
*/
class TestRunner::Impl
{
private:
	std::vector<Test*> testlist_;
	std::vector<TestModule*> modlist_;

	int test_count = 0;
	int fail_count = 0;

public:
	void reg_test(Test* t)
	{
		testlist_.push_back(t);
	}

	void reg_mod(TestModule* m)
	{
		modlist_.push_back(m);
	}

	void run_tests()
	{
		test_count = 0;
		fail_count = 0;

		//run modules and tests
		for(auto t: testlist_) {
			test_count++;
			run_test(t);
		}

		//print result

		int test_percent = std::round(((float)test_count-(float)fail_count)/(float)test_count*100.0f );
		std::cout << std::endl << test_percent << "% tests passed, "<< fail_count <<" tests failed out of " << test_count << std::endl;
	}

private:
	void run_test(Test* t)
	{
		// Starting timepoint
		const auto start_time = std::chrono::steady_clock::now();

		try
		{
			std::cout << "running " << t->desc << ": ";
			t->test_function();
			std::cout << " Success ";

			double time_in_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count() / 1000.0;
			std::cout << time_in_seconds << "s";
			std::cout << std::endl;

		}
		catch(std::exception& exc)
		{
			double time_in_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count() / 1000.0;


			fail_count++;
			std::cout << "Failed ";
			std::cout << time_in_seconds << "s";
			std::cout << std::endl << "\t\t" << exc.what() << std::endl;
		}
		//other catches
	}
};
	
TestRunner::Impl* TestRunner::impl = new TestRunner::Impl();

//macro for cultest main



//Implementation of TestRunner

void TestRunner::reg_test(Test* t)
{
	impl->reg_test(t);
}

void TestRunner::reg_mod(TestModule* m)
{
	impl->reg_mod(m);
}

void TestRunner::run_tests()
{
	impl->run_tests();
}





	
}

#endif // CUL_TESTIMPL_HPP
