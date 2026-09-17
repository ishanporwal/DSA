#include <gtest/gtest.h>
#include "valid_parentheses.hpp"

TEST(ValidParenthesesTest, EmptyString) {
    EXPECT_TRUE(isValidParentheses(""));
}

TEST(ValidParenthesesTest, SimpleValid) {
    EXPECT_TRUE(isValidParentheses("()"));
}

TEST(ValidParenthesesTest, MultipleValid) {
    EXPECT_TRUE(isValidParentheses("()[]{}"));
}

TEST(ValidParenthesesTest, NestedValid) {
    EXPECT_TRUE(isValidParentheses("({[]})"));
}

TEST(ValidParenthesesTest, WrongMatch) {
    EXPECT_FALSE(isValidParentheses("(]"));
}

TEST(ValidParenthesesTest, WrongOrder) {
    EXPECT_FALSE(isValidParentheses("([)]"));
}

TEST(ValidParenthesesTest, MissingClosing) {
    EXPECT_FALSE(isValidParentheses("(()"));
}

TEST(ValidParenthesesTest, StartsWithClosing) {
    EXPECT_FALSE(isValidParentheses(")"));
}
