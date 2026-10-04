#include <gtest/gtest.h>
#include <vector>

#include "sorting.hpp"

/**
 * Runs all sorting algorithms on the same input and checks that each one
 * matches the expected sorted result.
 *
 * @param input The input vector to sort.
 * @param expected The expected sorted vector.
 */
void expect_all_sorts(
    const std::vector<int>& input,
    const std::vector<int>& expected) {

    std::vector<int> insertion = input;
    insertion_sort(insertion);
    EXPECT_EQ(insertion, expected);

    std::vector<int> selection = input;
    selection_sort(selection);
    EXPECT_EQ(selection, expected);

    std::vector<int> merge = input;
    merge_sort(merge, 0, static_cast<int>(merge.size()) - 1);
    EXPECT_EQ(merge, expected);

    std::vector<int> quick = input;
    quickSort(quick);
    EXPECT_EQ(quick, expected);
}

TEST(SortingTest, NormalInput) {
    expect_all_sorts(
        {5, 2, 8, 1, 3},
        {1, 2, 3, 5, 8}
    );
}

TEST(SortingTest, AlreadySorted) {
    expect_all_sorts(
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5}
    );
}

TEST(SortingTest, ReverseSorted) {
    expect_all_sorts(
        {5, 4, 3, 2, 1},
        {1, 2, 3, 4, 5}
    );
}

TEST(SortingTest, Duplicates) {
    expect_all_sorts(
        {3, 1, 3, 2, 1},
        {1, 1, 2, 3, 3}
    );
}

TEST(SortingTest, SingleElement) {
    expect_all_sorts(
        {7},
        {7}
    );
}

TEST(SortingTest, EmptyVector) {
    expect_all_sorts(
        {},
        {}
    );
}

TEST(SortingTest, NegativeNumbers) {
    expect_all_sorts(
        {-2, 5, -10, 0, 3},
        {-10, -2, 0, 3, 5}
    );
}
