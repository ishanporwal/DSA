cmake_minimum_required(VERSION 3.14)

project(assignment_02)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

enable_testing()

add_executable(
    doubly_linked_list_test
    tests/doubly_linked_list_test.cpp
)

target_include_directories(
    doubly_linked_list_test
    PRIVATE include
)

target_link_libraries(
    doubly_linked_list_test
    PRIVATE GTest::gtest_main
)

add_executable(
    stack_test
    tests/stack_test.cpp
)

target_include_directories(
    stack_test
    PRIVATE include
)

target_link_libraries(
    stack_test
    PRIVATE GTest::gtest_main
)
add_executable(
    queue_test
    tests/queue_test.cpp
)

target_include_directories(
    queue_test
    PRIVATE include
)

target_link_libraries(
    queue_test
    PRIVATE GTest::gtest_main
)

add_executable(
    valid_parentheses_test
    tests/valid_parentheses_test.cpp
)

target_include_directories(
    valid_parentheses_test
    PRIVATE include
)

target_link_libraries(
    valid_parentheses_test
    PRIVATE GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(doubly_linked_list_test)
gtest_discover_tests(stack_test)
gtest_discover_tests(queue_test)
gtest_discover_tests(valid_parentheses_test)
