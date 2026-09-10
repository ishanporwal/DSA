#include <gtest/gtest.h>
#include "meeting_scheduler.hpp"

TEST(MeetingSchedulerTest, EmptyScheduleHasNoConflict) {
    std::vector<Meeting> meetings{};

    EXPECT_FALSE(containsConflict(meetings));
    EXPECT_FALSE(containsConflictSorted(meetings));
}

TEST(MeetingSchedulerTest, SingleMeetingHasNoConflict) {
    std::vector<Meeting> meetings{
        {1, 3}
    };

    EXPECT_FALSE(containsConflict(meetings));
    EXPECT_FALSE(containsConflictSorted(meetings));
}

TEST(MeetingSchedulerTest, SeparateMeetingsHaveNoConflict) {
    std::vector<Meeting> meetings{
        {1, 3},
        {4, 6},
        {7, 9}
    };

    EXPECT_FALSE(containsConflict(meetings));
    EXPECT_FALSE(containsConflictSorted(meetings));
}

TEST(MeetingSchedulerTest, TouchingMeetingsHaveNoConflict) {
    std::vector<Meeting> meetings{
        {1, 3},
        {3, 5}
    };

    EXPECT_FALSE(containsConflict(meetings));
    EXPECT_FALSE(containsConflictSorted(meetings));
}

TEST(MeetingSchedulerTest, OverlappingMeetingsHaveConflict) {
    std::vector<Meeting> meetings{
        {1, 4},
        {3, 6}
    };

    EXPECT_TRUE(containsConflict(meetings));
    EXPECT_TRUE(containsConflictSorted(meetings));
}

TEST(MeetingSchedulerTest, NestedMeetingHasConflict) {
    std::vector<Meeting> meetings{
        {1, 10},
        {3, 5}
    };

    EXPECT_TRUE(containsConflict(meetings));
    EXPECT_TRUE(containsConflictSorted(meetings));
}

TEST(MeetingSchedulerTest, UnsortedMeetingsHaveConflict) {
    std::vector<Meeting> meetings{
        {8, 10},
        {1, 3},
        {5, 9}
    };

    EXPECT_TRUE(containsConflict(meetings));
    EXPECT_TRUE(containsConflictSorted(meetings));
}
