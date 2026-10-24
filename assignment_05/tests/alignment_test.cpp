
#include <gtest/gtest.h>
#include "alignment.hpp"

TEST(AlignmentTest, BasicAlignment) {
    auto res = needlemanWunsch("ACGT", "AGT");
    EXPECT_EQ(res.alignedA, "ACGT");
    EXPECT_EQ(res.alignedB, "A-GT");
    EXPECT_EQ(res.score, 2);
}

TEST(AlignmentTest, Mismatch) {
    auto res = needlemanWunsch("A", "T");
    EXPECT_EQ(res.alignedA, "A");
    EXPECT_EQ(res.alignedB, "T");
    EXPECT_EQ(res.score, -1);
}

TEST(AlignmentTest, EmptySequence) {
    auto res = needlemanWunsch("AC", "");
    EXPECT_EQ(res.alignedA, "AC");
    EXPECT_EQ(res.alignedB, "--");
    EXPECT_EQ(res.score, -2);
}
