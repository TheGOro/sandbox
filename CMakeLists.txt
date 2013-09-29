# Required minimum CMake version
cmake_minimum_required(VERSION 2.6)
include(CheckIncludeFiles)

# Project name and variables
project(sandbox)
set(PROJECT_SOURCE_DIR src)
set(PROJECT_BINARY_DIR build)
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")
endif()


option(build_tests "Build all unit test." ON)
if(build_tests)
    enable_testing()
    # Check for required headers for testing
    check_include_files(gtest/gtest.h HAVE_GTEST_H)

    add_executable(timetype_test test/timetype_test.cpp src/timetype.cpp)
    target_link_libraries(timetype_test pthread)
    target_link_libraries(timetype_test gtest gtest_main)
    add_test(timetype-tests timetype_test)
endif()
