#!/usr/bin/env bash

# Check for build directory
if [ ! -d "build" ]; then
    echo "Creating build directory..."
    mkdir build
fi

# enter build directory
cd build

# check for ninja build system availability
#if command -v ninja >/dev/null 2>&1; then
#    echo "ninja exists";
#fi
 

# create make files with cmake
cmake -G "Unix Makefiles" ..

# make program
make
