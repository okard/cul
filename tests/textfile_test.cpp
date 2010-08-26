
#include <cassert>
#include <TextFile.hpp>

using namespace cul;

void test_utf8_bom(const char* fileName)
{
    TextFile tf;
    tf.open(fileName);
    assert(tf.getEncoding() == UTF8);
}



/**
* main method
*/
int main(int argc, char *argv[])
{
    //file as argument?
    test_utf8_bom(argv[1]);
    
    return 0;
}