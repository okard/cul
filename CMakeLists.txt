###############################################################################
# C++ Utility Library
# 
###############################################################################
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(cul)
ENABLE_TESTING()


include_directories(src)

add_library(cul src/TextFile.cpp src/Utf.cpp
            src/String.cpp)

#tests
subdirs(tests)