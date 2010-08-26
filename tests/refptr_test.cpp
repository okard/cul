
#include <RefPtr.hpp>

// #include <cassert>
#include <cassert>
#include <iostream>
using namespace std;
using namespace cul;

//#define NDEBUG

///helper test class
class testcls
{
    public:
        /// count of class instances
        static int count;
        testcls() {count++;}
        ~testcls() {count--;}
};

int testcls::count = 0;

void refptr_test_simple()
{
    cout << "refptr_test_simple" << endl;
    RefPtr<int> a(new int(5));
    RefPtr<int> b = a;

    assert(b.refcount() == 2);
    assert(a.refcount() == 2);
    assert((*b) == 5);
    assert((*a) == 5);
}

void refptr_test_simple2()
{
    cout << "refptr_test_simple2" << endl;
    RefPtr<int> a(new int(6));
    RefPtr<int> b;
    b = a;

    assert(b.refcount() == 2);
    assert(a.refcount() == 2);
    assert((*b) == 6);
    assert((*a) == 6);
}

void refptr_test_deletion()
{
    cout << "refptr_test_deletion" << endl;
    assert(testcls::count == 0);
    RefPtr<testcls>* a = new RefPtr<testcls>(new testcls());
    delete a;
    assert(testcls::count == 0);
}

void refptr_test_deletion2()
{
    cout << "refptr_test_deletion2" << endl;
    assert(testcls::count == 0);
    RefPtr<testcls>* a = new RefPtr<testcls>(new testcls());
    RefPtr<testcls>* b = new RefPtr<testcls>();
    (*b) = (*a);
    assert(testcls::count == 1);
    assert((*a).refcount() == 2);

    delete a;
    assert(testcls::count == 1);
    assert((*b).refcount() == 1);

    delete b;
    assert(testcls::count == 0);
}


void refptr_test_deletion3()
{
    cout << "refptr_test_deletion3" << endl;
    assert(testcls::count == 0);
    RefPtr<testcls> a(new testcls());
    assert(testcls::count == 1);
    a = new testcls();
    assert(testcls::count == 1);
}

//#ifdef STRING_TEST_MAIN

int main(int argc, char *argv[])
{
    refptr_test_simple();
    refptr_test_simple2();
    refptr_test_deletion();
    refptr_test_deletion2();
    refptr_test_deletion3();
}
//#endif
