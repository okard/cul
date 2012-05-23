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
#pragma once
#ifndef __CUL_FILE_HPP__
#define __CUL_FILE_HPP__

#include <cstdio>

namespace cul {
    
/**
* File Class
* Wraps C FILE* 
*/
class File
{
    private:
        /// C File Handle
        FILE* file;
    
    //TODO maybe make FILE Constructor private?    
        
    public:
        /**
        * Ctor
        */
        File(FILE* file);
        
        //File()
        //File(const File& file)
        
        /**
        * Dtor
        */
        ~File();
        
        //void open()
        
        /**
        * is EOF
        */
        bool isEof();
    
        /**
        * Flush
        */
        void flush();
        
        /**
        * Printf
        */
        void printf(const char* msg, ...);
    
    /*
    D -> DONE
    
    · fclose
    D feof
    · ferror
    D fflush
    · fgetc
    · fgetpos
    · fgets
    · fopen
    · fprintf
    · fputc
    · fputs
    · fread
    · freopen
    · fscanf
    · fseek
    · fsetpos
    · ftell
    · fwrite
    · getc
    · putc
    if ferror throw new exception(strerror(errno)) clearerr
    */
};

} //end namespace cul

#endif // __CUL_FILE_HPP__
