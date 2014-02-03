###############################################################################
# C++ Utility Libraries
###############################################################################
cmake_minimum_required(VERSION 2.8)

project(cul)

#Options:
#-Platform: WIN, POSIX, LINUX, ...
#-Arch: 32/64/ARM
#-Type: Static/Shared

# Enable C++11
#SET (CMAKE_C_COMPILER "/usr/bin/clang")
SET(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++11")

#TODO Remove handling for sources
# Include Platform specific files to build
if(WIN32)
    add_definitions(-DCUL_LIBRARY)
else()
    set(CUL_SYS_LIBS "pthread" "dl")
endif()

include_directories(include)

# set lib output directory
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# I/O Module
file(GLOB_RECURSE CULIO_SOURCES src/culio/*.cpp include/culio/*.hpp)
add_library(culio SHARED ${CULIO_SOURCES})

# Sys Module
file(GLOB_RECURSE CULSYS_SOURCES src/culsys/*.cpp include/culsys/*.hpp)
add_library(culsys SHARED ${CULSYS_SOURCES})
target_link_libraries(culsys ${CUL_SYS_LIBS})

# Log Module
file(GLOB_RECURSE CULLOG_SOURCES src/cullog/*.cpp include/cullog/*.hpp)
add_library(cullog SHARED ${CULLOG_SOURCES})


if(DEFINED CULTESTS)
  enable_testing()
  add_subdirectory(tests)
endif(DEFINED CULTESTS)

