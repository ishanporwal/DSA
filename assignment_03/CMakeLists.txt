cmake_minimum_required(VERSION 3.14)

project(assignment_03)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

enable_testing()

include(GoogleTest)


add_executable(
    graph_test
    tests/graph_test.cpp
)

target_include_directories(
    graph_test
    PRIVATE
    include
)

target_link_libraries(
    graph_test
    PRIVATE
    GTest::gtest_main
)

gtest_discover_tests(graph_test)


add_executable(
    min_priority_queue_test
    tests/min_priority_queue_test.cpp
)

target_include_directories(
    min_priority_queue_test
    PRIVATE
    include
)

target_link_libraries(
    min_priority_queue_test
    PRIVATE
    GTest::gtest_main
)

gtest_discover_tests(min_priority_queue_test)


add_executable(
    dijkstra_test
    tests/dijkstra_test.cpp
)

target_include_directories(
    dijkstra_test
    PRIVATE
    include
)

target_link_libraries(
    dijkstra_test
    PRIVATE
    GTest::gtest_main
)

gtest_discover_tests(dijkstra_test)

add_executable(
    city_paths
    src/city_paths.cpp
)

target_include_directories(
    city_paths
    PRIVATE
    include
)
