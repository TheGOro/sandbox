# Required minimum CMake version
cmake_minimum_required(VERSION 2.6)
include(CheckIncludeFiles)

# Project name and variables
project(sandbox)
set(PROJECT_SOURCE_DIR src)
set(PROJECT_BINARY_DIR build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra -std=c++11")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
endif()

# Unit testing
option(build_tests "Build all unit test." ON)
if(build_tests)
    enable_testing()
    # Check for required headers for testing
    check_include_files(gtest/gtest.h HAVE_GTEST_H)

    # TimeType tests
    set(TEST_TIMETYPE ${PROJECT_BINARY_DIR}/timetype_test)
    add_executable(${TEST_TIMETYPE} test/timetype_test.cpp src/timetype.cpp)
    target_link_libraries(${TEST_TIMETYPE} pthread)
    target_link_libraries(${TEST_TIMETYPE} gtest gtest_main)
    add_test(timetype-tests ${TEST_TIMETYPE})
endif()
