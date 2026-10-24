
#include <gtest/gtest.h>
#include "matrix.hpp"

TEST(MatrixTest, ConstructorGetSet) {
    Matrix m(3);
    EXPECT_DOUBLE_EQ(m.get(0, 0), 0);
    EXPECT_DOUBLE_EQ(m.get(2, 2), 0);
    m.set(0, 0, 5.5);
    m.set(1, 2, -3);
    EXPECT_DOUBLE_EQ(m.get(0, 0), 5.5);
    EXPECT_DOUBLE_EQ(m.get(1, 2), -3);
    EXPECT_THROW(m.get(3, 0), std::out_of_range);
}

TEST(MatrixTest, Split) {
    Matrix m(4);
    double val = 1;
    for (std::size_t r = 0; r < 4; r++) {
        for (std::size_t c = 0; c < 4; c++) {
            m.set(r, c, val++);
        }
    }
    auto parts = m.split();
    ASSERT_EQ(parts.size(), 4);
    double expected[4][2][2] = {
        {{1, 2}, {5, 6}},
        {{3, 4}, {7, 8}},
        {{9, 10}, {13, 14}},
        {{11, 12}, {15, 16}}
    };
    for (std::size_t k = 0; k < 4; k++) {
        for (std::size_t r = 0; r < 2; r++) {
            for (std::size_t c = 0; c < 2; c++) {
                EXPECT_DOUBLE_EQ(parts[k].get(r, c), expected[k][r][c]);
            }
        }
    }
}

TEST(MatrixTest, AdditionSubtraction) {
    Matrix a(2), b(2);
    a.set(0, 0, 1);
    a.set(0, 1, 2);
    a.set(1, 0, 3);
    a.set(1, 1, 4);
    b.set(0, 0, 5);
    b.set(0, 1, 6);
    b.set(1, 0, 7);
    b.set(1, 1, 8);
    auto sum = a.add(b);
    auto diff = a.subtract(b);
    EXPECT_DOUBLE_EQ(sum.get(0, 0), 6);
    EXPECT_DOUBLE_EQ(sum.get(1, 1), 12);
    EXPECT_DOUBLE_EQ(diff.get(0, 0), -4);
    EXPECT_DOUBLE_EQ(diff.get(1, 1), -4);
}

TEST(MatrixTest, Multiply) {
    Matrix a(2), b(2);
    a.set(0, 0, 1);
    a.set(0, 1, 2);
    a.set(1, 0, 3);
    a.set(1, 1, 4);
    b.set(0, 0, 5);
    b.set(0, 1, 6);
    b.set(1, 0, 7);
    b.set(1, 1, 8);
    auto result = a.multiply(b);
    ASSERT_TRUE(result.has_value());
    EXPECT_DOUBLE_EQ(result->get(0, 0), 19);
    EXPECT_DOUBLE_EQ(result->get(0, 1), 22);
    EXPECT_DOUBLE_EQ(result->get(1, 0), 43);
    EXPECT_DOUBLE_EQ(result->get(1, 1), 50);
}

TEST(MatrixTest, Strassen2x2) {
    Matrix a(2), b(2);
    a.set(0, 0, 1);
    a.set(0, 1, 2);
    a.set(1, 0, 3);
    a.set(1, 1, 4);
    b.set(0, 0, 5);
    b.set(0, 1, 6);
    b.set(1, 0, 7);
    b.set(1, 1, 8);
    auto result = a.strassenMultiply(b);
    ASSERT_TRUE(result.has_value());
    EXPECT_DOUBLE_EQ(result->get(0, 0), 19);
    EXPECT_DOUBLE_EQ(result->get(0, 1), 22);
    EXPECT_DOUBLE_EQ(result->get(1, 0), 43);
    EXPECT_DOUBLE_EQ(result->get(1, 1), 50);
}


TEST(MatrixTest, Strassen4x4) {
    Matrix a(4), b(4);
    for (std::size_t r = 0; r < 4; r++) {
        for (std::size_t c = 0; c < 4; c++) {
            a.set(r, c, r * 4 + c + 1);
            b.set(r, c, r == c ? 2 : 1);
        }
    }
    auto expected = a.multiply(b);
    ASSERT_TRUE(expected.has_value());
    for (std::size_t threshold : {1, 2, 4, 8}) {
        auto result = a.strassenMultiply(b, threshold);
        ASSERT_TRUE(result.has_value());
        for (std::size_t r = 0; r < 4; r++) {
            for (std::size_t c = 0; c < 4; c++) {
                EXPECT_NEAR(result->get(r, c), expected->get(r, c), 1e-9);
            }
        }
    }
}

TEST(MatrixTest, DifferentSizes) {
    Matrix a(2), b(3);
    EXPECT_THROW(a.add(b), std::invalid_argument);
    EXPECT_THROW(a.subtract(b), std::invalid_argument);
    EXPECT_FALSE(a.multiply(b).has_value());
    EXPECT_FALSE(a.strassenMultiply(b).has_value());
}


TEST(MatrixTest, StrassenOddSize) {
    Matrix a(3), b(3);
    for (std::size_t r = 0; r < 3; r++) {
        for (std::size_t c = 0; c < 3; c++) {
            a.set(r, c, r * 3 + c + 1);
            b.set(r, c, c + 1);
        }
    }
    auto expected = a.multiply(b);
    auto result = a.strassenMultiply(b);
    ASSERT_TRUE(expected.has_value());
    ASSERT_TRUE(result.has_value());
    for (std::size_t r = 0; r < 3; r++) {
        for (std::size_t c = 0; c < 3; c++) {
            EXPECT_DOUBLE_EQ(result->get(r, c), expected->get(r, c));
        }
    }
}
