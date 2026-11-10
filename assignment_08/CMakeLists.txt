cmake_minimum_required(VERSION 3.14)

project(assignment_08)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

enable_testing()
include(GoogleTest)

add_executable(
    nearest_neighbor
    src/main.cpp
    src/benchmark.cpp
)

target_include_directories(nearest_neighbor PRIVATE include)

add_executable(
    kd_tree_test
    tests/kd_tree_test.cpp
)

target_include_directories(kd_tree_test PRIVATE include)
target_link_libraries(kd_tree_test PRIVATE GTest::gtest_main)

gtest_discover_tests(kd_tree_test)
