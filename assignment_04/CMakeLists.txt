cmake_minimum_required(VERSION 3.14)

project(assignment_04)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

enable_testing()

include(GoogleTest)

add_executable(
    sorting_test
    tests/sorting_test.cpp
)

target_include_directories(
    sorting_test
    PRIVATE
    include
)

target_link_libraries(
    sorting_test
    PRIVATE
    GTest::gtest_main
)

gtest_discover_tests(sorting_test)

add_executable(
    benchmark
    src/benchmark.cpp
)

target_include_directories(
    benchmark
    PRIVATE
    include
)
