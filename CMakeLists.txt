###############################################################################
# C++ Utility Library
# 
###############################################################################
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(cul)

include_directories(src)
include_directories(include)

# Include Platform specific files to build
IF(WIN32)
    add_definitions(-DCUL_LIBRARY)
    set(CUL_PLATFORM_SRC src/sys/ThreadWin.cpp)
ELSE()
    set(CUL_PLATFORM_SRC src/sys/ThreadPosix.cpp)
    set(CUL_PLATFORM_LIBS "pthread" "dl")
ENDIF()

#library
add_library(cul SHARED 
            ${CUL_PLATFORM_SRC}
            src/io/File.cpp
            src/io/TextFile.cpp 
            src/io/Utf.cpp
            src/io/Console.cpp
            src/String.cpp
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

IF(DEFINED CULTESTS)
  ENABLE_TESTING()
  ADD_SUBDIRECTORY(tests)
ENDIF(DEFINED CULTESTS)

