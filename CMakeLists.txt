cmake_minimum_required(VERSION 3.5)
include(GoogleTest)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra -Wall")

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(spinlock.hpp)
set(unit_test test.cpp)
add_executable (unit_test ${unit_test})
target_link_libraries (unit_test gtest)
target_link_libraries (unit_test pthread)

gtest_add_tests(unit_test "" AUTO)
