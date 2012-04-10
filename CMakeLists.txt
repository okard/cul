###############################################################################
# C++ Utility Library
# 
###############################################################################
cmake_minimum_required(VERSION 2.8)

project(cul)

include_directories(src)
include_directories(include)

# Enable C++11
#SET (CMAKE_C_COMPILER "/usr/bin/clang")
SET(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++11")

# Include Platform specific files to build
if(WIN32)
    add_definitions(-DCUL_LIBRARY)
    set(CUL_PLATFORM_SRC src/sys/ThreadWin.cpp)
else()
    set(CUL_PLATFORM_SRC src/sys/ThreadPosix.cpp)
    set(CUL_PLATFORM_LIBS "pthread" "dl")
endif()

#library
add_library(cul SHARED 
            ${CUL_PLATFORM_SRC}
            src/io/File.cpp
            src/io/TextFile.cpp 
            src/io/Utf.cpp
            src/io/Console.cpp
            src/String.cpp
            src/Convert.cpp
            src/Hash.cpp
            src/log/LogType.cpp
            src/log/LogEvent.cpp
            src/log/LogSource.cpp
            src/log/Log.cpp
            src/log/ConsoleListener.cpp
            src/log/FileListener.cpp
            src/sys/Thread.cpp
            src/sys/Guard.cpp
            src/sys/DynLib.cpp
            src/net/Socket.cpp
            src/net/Address.cpp)

target_link_libraries(cul ${CUL_PLATFORM_LIBS})

if(DEFINED CULTESTS)
  enable_testing()
  add_subdirectory(tests)
endif(DEFINED CULTESTS)

