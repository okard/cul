###############################################################################
# C++ Utility Library
# 
###############################################################################
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(cul)
ENABLE_TESTING()


include_directories(src)
include_directories(include)

add_library(cul src/TextFile.cpp 
                src/Utf.cpp
                src/String.cpp
                src/log/Log.cpp
                src/log/ConsoleListener.cpp)

#tests
subdirs(tests)