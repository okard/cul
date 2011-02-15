#!/usr/bin/env bash

# Check for build directory
if [ ! -d "build" ]; then
    echo "Creating build directory..."
    mkdir build
fi

#enter build directory
cd build

#create make files with cmake
cmake -DCULTESTS=true -G "Unix Makefiles" ..

#make lib
make

#make program
make test
