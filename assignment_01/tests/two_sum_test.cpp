#include <gtest/gtest.h>
#include "two_sum.hpp"

TEST(TwoSumTest, OGTestCase) {
    std::vector<int> nums{2, 7, 11, 15};
    
    EXPECT_EQ(
        twoSum(nums, 9),
        std::vector<int>({1, 0})
    );
}

TEST(TwoSumTest, DuplicateVals) {
    std::vector<int> nums{1, 1};

    EXPECT_EQ(
        twoSum(nums, 2),
        std::vector<int>({1, 0})
    );
}

TEST(TwoSumTest, NegativeNumbers) {
    std::vector<int> nums{-8, 4, 8, 10};

    EXPECT_EQ(
        twoSum(nums, 0),
        std::vector<int>({2, 0})
    );
}

TEST(TwoSumTest, NoSolution) {
    std::vector<int> nums{1, 2, 3};

    EXPECT_EQ(
        twoSum(nums, 21),
        std::vector<int>{}
    );
}
