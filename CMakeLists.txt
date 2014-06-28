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
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")


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

# Add header only libs for using in qtcreator

# (HEADER ONLY) Core Module
file(GLOB_RECURSE CULCORE_SOURCES include/culcore/*.hpp)
add_library(culcore STATIC ${CULCORE_SOURCES})
set_target_properties(culcore PROPERTIES LINKER_LANGUAGE CXX)

# (HEADER ONLY) Alloc Module
file(GLOB_RECURSE CULALLOC_SOURCES include/culalloc/*.hpp)
add_library(culalloc STATIC ${CULALLOC_SOURCES})
set_target_properties(culalloc PROPERTIES LINKER_LANGUAGE CXX)

# (HEADER ONLY) Collection Module
file(GLOB_RECURSE CULCOLLECTION_SOURCES include/culcollection/*.hpp)
add_library(culcollection STATIC ${CULCOLLECTION_SOURCES})
set_target_properties(culcollection PROPERTIES LINKER_LANGUAGE CXX)

# (HEADER ONLY) Mem Module
file(GLOB_RECURSE CULMEM_SOURCES include/culmem/*.hpp)
add_library(culmem STATIC ${CULMEM_SOURCES})
set_target_properties(culmem PROPERTIES LINKER_LANGUAGE CXX)

# (HEADER ONLY) Signal Module
file(GLOB_RECURSE CULSIGNAL_SOURCES include/culsignal/*.hpp)
add_library(culsignal STATIC ${CULSIGNAL_SOURCES})
set_target_properties(culsignal PROPERTIES LINKER_LANGUAGE CXX)

# (HEADER ONLY) Test Module
file(GLOB_RECURSE CULTEST_SOURCES include/cultest/*.hpp)
add_library(cultest STATIC ${CULTEST_SOURCES})
set_target_properties(cultest PROPERTIES LINKER_LANGUAGE CXX)


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


add_subdirectory(tests)

