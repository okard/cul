/*
    C++ Utility Library
    Copyright (C) 2010  okard

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*/

#include "TextFile.hpp"

#include <iostream>
#include <cstring>
#include <cassert>
#include "Endian.hpp"

namespace cul {

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
     
    //reset position
    fseek(file, 0, SEEK_SET);
    
    //check for encoding
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


} //end namespace cul
