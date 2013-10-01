# Required minimum CMake version
cmake_minimum_required(VERSION 2.6)
include(CheckIncludeFiles)

# Project name and variables
project(sandbox)
set(PROJECT_SOURCE_DIR src)
set(PROJECT_BINARY_DIR build)
set(PROJECT_TEST_DIR test)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra -std=c++11")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
endif()

include(TestForSTDNamespace)

# Unit testing
option(build_tests "Build all unit test." ON)
if(build_tests)
    # Check for GoogleTest
    find_package(GTEST)
    if(NOT GTEST_FOUND)
        message(FATAL_ERROR "You need GoogleTest to make test")
    endif()
    include_directories(${GTEST_INCLUDE_DIRS})

    # Check for Threads (we prefer pthread)
    set(CMAKE_THREAD_PREFER_PTHREAD ON)
    find_package(THREADS)
    if(NOT THREADS_FOUND)
        message(FATAL_ERROR "You need a system thread library (like pthread) to use GoogleTest")
    endif()
    enable_testing()

    # TimeType tests
    set(TEST_TIMETYPE timetype_test)
    add_executable(${TEST_TIMETYPE} test/timetype_test.cpp src/timetype.cpp)
    target_link_libraries(${TEST_TIMETYPE} ${CMAKE_THREAD_LIBS_INIT})
    target_link_libraries(${TEST_TIMETYPE} ${GTEST_BOTH_LIBRARIES})
    add_test(timetype-tests ${PROJECT_BINARY_DIR}/${TEST_TIMETYPE})

    # Shed tests
    set(TEST_SHED_SWAP shed_swap_test)
    add_executable(${TEST_SHED_SWAP} test/shed_swap_test.cpp src/shed.h)
    target_link_libraries(${TEST_SHED_SWAP} ${CMAKE_THREAD_LIBS_INIT})
    target_link_libraries(${TEST_SHED_SWAP} ${GTEST_BOTH_LIBRARIES})
    add_test(shed-swap-tests ${PROJECT_BINARY_DIR}/${TEST_SHED_SWAP})
endif()
