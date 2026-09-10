cmake_minimum_required(VERSION 3.14)

project(assignment_01)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

enable_testing()

# ---------------- Two Sum ----------------

add_executable(
    two_sum_test
    tests/two_sum_test.cpp
    src/two_sum.cpp
)

target_include_directories(
    two_sum_test
    PRIVATE include
)

target_link_libraries(
    two_sum_test
    PRIVATE GTest::gtest_main
)

# ------------- Meeting Scheduler -------------

add_executable(
    meeting_scheduler_test
    tests/meeting_scheduler_test.cpp
    src/meeting_scheduler.cpp
)

target_include_directories(
    meeting_scheduler_test
    PRIVATE include
)

target_link_libraries(
    meeting_scheduler_test
    PRIVATE GTest::gtest_main
)

# ---------------- Testing ----------------

include(GoogleTest)

gtest_discover_tests(two_sum_test)
gtest_discover_tests(meeting_scheduler_test)
