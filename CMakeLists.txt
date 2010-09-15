###############################################################################
# C++ Utility Library
# 
###############################################################################
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(cul)
ENABLE_TESTING()


include_directories(src)
include_directories(include)

# Include Platform specific files to build
IF(WIN32)
  set(CUL_PLATFORM_SRC src/threading/ThreadWin.cpp)
ELSE()
  set(CUL_PLATFORM_SRC src/threading/ThreadPosix.cpp)
  set(CUL_PLATFORM_LIBS "pthread")
ENDIF()

#library
add_library(cul ${CUL_PLATFORM_SRC}
                src/io/TextFile.cpp 
                src/io/Utf.cpp
                src/String.cpp
                src/log/LogType.cpp
                src/log/LogEvent.cpp
                src/log/LogSource.cpp
                src/log/Log.cpp
                src/log/ConsoleListener.cpp
                src/threading/Thread.cpp)

target_link_libraries(cul ${CUL_PLATFORM_LIBS})

#tests
subdirs(tests)