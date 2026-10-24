cmake_minimum_required(VERSION 3.14)

project(assignment_05)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

enable_testing()

include(GoogleTest)

add_executable(
    matrix_test
    tests/matrix_test.cpp
)

target_include_directories(
    matrix_test
    PRIVATE
    include
)

target_link_libraries(
    matrix_test
    PRIVATE
    GTest::gtest_main
)

gtest_discover_tests(matrix_test)

add_executable(
    benchmark
    src/benchmark.cpp
)

target_include_directories(
    benchmark
    PRIVATE
    include
)

add_executable(
    alignment_test
    tests/alignment_test.cpp
)

target_include_directories(
    alignment_test
    PRIVATE
    include
)

target_link_libraries(
    alignment_test
    PRIVATE
    GTest::gtest_main
)

gtest_discover_tests(alignment_test)
add_executable(
    alignment_demo
    src/alignment_demo.cpp
)

target_include_directories(
    alignment_demo
    PRIVATE
    include
)
