
@echo off
REM Check for build directory
IF EXIST build/NUL GOTO BUILDDIREXIST
   mkdir build
:BUILDDIREXIST

REM go into build
cd build

REM build library
cmake -DCMAKE_BUILD_TYPE=Debug -G "MinGW Makefiles" ..
mingw32-make

REM step back
cd..