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
#include <cul/io/TextFile.hpp>

#include <cul/Endian.hpp>

#include <iostream>
#include <cstring>
#include <cassert>


using namespace cul;
using namespace io;

/**
* Ctor
*/
TextFile::TextFile() : file(null), encode(ASCII)
{

}

/**
* Dtor
*/
TextFile::~TextFile()
{
    if(isOpen())
        close();
}

/**
* open text file
*/
void TextFile::open(const char* fileName)
{
    file = fopen(fileName, "r+");
    if(file == null)
        throw "Cant open file";
    
    //read first 4 bytes to determinate bom
    uint bom = 0;
    assert(sizeof(uint) == 4);
    size_t t = fread(&bom, 1, 4, file);
    
    //swap order on an little endian system
    if(!is_bigendian())
        endian_swap(bom);
    
    //check for encoding
    /*
    if(t >= 3 && memcmp(&bom, &UTF8_BOM, 2))
    {   encode = UTF8; return; }
    
    if(t >= 2 && memcmp(&bom, &UTF16BE_BOM, 2))
    {   encode = UTF16BE; return; }
    
    if(t >= 2 && memcmp(&bom, &UTF16LE_BOM, 2))
    {   encode = UTF16LE; return; }
    
    if(t >= 4 && memcmp(&bom, &UTF32BE_BOM, 4))
    {   encode = UTF32BE; return; }
    
    if(t >= 4 && memcmp(&bom, &UTF32LE_BOM, 4))
    {   encode = UTF32LE; return; }   
    */
    
    //if it is ascii, reset position
    fseek(file, 0, SEEK_SET);
}

/**
* close text file
*/
void TextFile::close()
{
    fclose(file);
    file = null;
}

/**
* get encoding
*/
Encoding TextFile::getEncoding()
{
    return encode;
}

/**
* is textfile open
*/
bool TextFile::isOpen()
{
    return file != null;
}

/**
* read a ascii char
*/
char TextFile::readAscii()
{
    char c = fgetc(file);
    
    if(encode ==  UTF8 && utf8_isascii(c))
        return c;
}
