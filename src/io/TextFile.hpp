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

#ifndef TEXTFILE_HPP
#define TEXTFILE_HPP

#include <cstdio>

#include "Types.hpp"
#include "Utf.hpp"

namespace cul {

/**
* \brief Class to handle text files 
* UTF capable
*/
class TextFile
{
    private:
        enum Encoding encode;
        FILE* file;
        
    public:
        /**
        * Ctor
        */
        TextFile();
        
        /**
        * Dtor
        */
        ~TextFile();
        
        /**
        * Open a file
        */
        void open(const char* fileName);
        
        /**
        * Close file
        */
        void close();
        
        /**
        * Return encoding of TextFile
        */
        Encoding getEncoding();
        
        /**
        * read ascii character
        */
        char readAscii();
        
        /**
        * file is open
        */
        bool isOpen();
};

} //end namespace cul

#endif // TEXTFILE_HPP
