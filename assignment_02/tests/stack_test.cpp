#include <gtest/gtest.h>
#include "stack.hpp"

TEST(StackTest, StartsEmpty) {
    Stack<int> stack;

    EXPECT_TRUE(stack.isEmpty());
    EXPECT_EQ(stack.peek(), std::nullopt);
    EXPECT_EQ(stack.pop(), std::nullopt);
}

TEST(StackTest, PushSingle) {
    Stack<int> stack;

    stack.push(10);

    EXPECT_FALSE(stack.isEmpty());
    EXPECT_EQ(stack.peek().value(), 10);
}

TEST(StackTest, PushMultiple) {
    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    EXPECT_EQ(stack.peek().value(), 30);
}

TEST(StackTest, PopLIFO) {
    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    EXPECT_EQ(stack.pop().value(), 30);
    EXPECT_EQ(stack.pop().value(), 20);
    EXPECT_EQ(stack.pop().value(), 10);
}

TEST(StackTest, EmptyAfterPoppingAll) {
    Stack<int> stack;

    stack.push(10);
    stack.push(20);

    stack.pop();
    stack.pop();

    EXPECT_TRUE(stack.isEmpty());
    EXPECT_EQ(stack.peek(), std::nullopt);
    EXPECT_EQ(stack.pop(), std::nullopt);
}

TEST(StackTest, WorksWithStrings) {
    Stack<std::string> stack;

    stack.push("hello");
    stack.push("world");

    EXPECT_EQ(stack.peek().value(), "world");
    EXPECT_EQ(stack.pop().value(), "world");
    EXPECT_EQ(stack.pop().value(), "hello");
}
