cmake_minimum_required(VERSION 3.14)

project(assignment_07)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

enable_testing()

include(GoogleTest)

add_executable(
    associative_array_test
    tests/associative_array_test.cpp
)

target_include_directories(
    associative_array_test
    PRIVATE
    include
)

target_link_libraries(
    associative_array_test
    PRIVATE
    GTest::gtest_main
)

gtest_discover_tests(associative_array_test)

add_executable(markov src/markov.cpp)
target_include_directories(markov PRIVATE include)
