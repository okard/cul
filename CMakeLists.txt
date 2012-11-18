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

# create lib directory
file(MAKE_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib/)

# I/O Module
file(GLOB_RECURSE CULIO_SOURCES src/culio/*.cpp)
add_library(culio SHARED ${CULIO_SOURCES})

# Sys Module
file(GLOB_RECURSE CULSYS_SOURCES src/culsys/*.cpp)
add_library(culsys SHARED ${CULSYS_SOURCES})
target_link_libraries(culsys ${CUL_SYS_LIBS})
get_target_property(CULSYS_LIB_NAME culsys LOCATION)
add_custom_command(TARGET culsys POST_BUILD COMMAND cp ARGS ${CULSYS_LIB_NAME} ${CMAKE_CURRENT_LIST_DIR}/lib/)

# Log Module
file(GLOB_RECURSE CULLOG_SOURCES src/cullog/*.cpp)
add_library(cullog SHARED ${CULLOG_SOURCES})

if(DEFINED CULTESTS)
  enable_testing()
  add_subdirectory(tests)
endif(DEFINED CULTESTS)

