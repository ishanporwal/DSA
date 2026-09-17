#include <gtest/gtest.h>
#include "doubly_linked_list.hpp"

TEST(DoublyLinkedListTest, StartsEmpty) {
    DoublyLinkedList<int> list;

    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.peekFront(), std::nullopt);
    EXPECT_EQ(list.peekBack(), std::nullopt);
    EXPECT_EQ(list.popFront(), std::nullopt);
    EXPECT_EQ(list.popBack(), std::nullopt);
}

TEST(DoublyLinkedListTest, PushFrontSingle) {
    DoublyLinkedList<int> list;

    list.pushFront(10);

    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.peekFront().value(), 10);
    EXPECT_EQ(list.peekBack().value(), 10);
}

TEST(DoublyLinkedListTest, PushFrontMultiple) {
    DoublyLinkedList<int> list;

    list.pushFront(10);
    list.pushFront(20);
    list.pushFront(30);

    EXPECT_EQ(list.peekFront().value(), 30);
    EXPECT_EQ(list.peekBack().value(), 10);
}

TEST(DoublyLinkedListTest, PushBackSingle) {
    DoublyLinkedList<int> list;

    list.pushBack(10);

    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.peekFront().value(), 10);
    EXPECT_EQ(list.peekBack().value(), 10);
}

TEST(DoublyLinkedListTest, PushBackMultiple) {
    DoublyLinkedList<int> list;

    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(30);

    EXPECT_EQ(list.peekFront().value(), 10);
    EXPECT_EQ(list.peekBack().value(), 30);
}

TEST(DoublyLinkedListTest, PopFront) {
    DoublyLinkedList<int> list;

    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(30);

    EXPECT_EQ(list.popFront().value(), 10);
    EXPECT_EQ(list.peekFront().value(), 20);

    EXPECT_EQ(list.popFront().value(), 20);
    EXPECT_EQ(list.popFront().value(), 30);

    EXPECT_TRUE(list.isEmpty());
}

TEST(DoublyLinkedListTest, PopBack) {
    DoublyLinkedList<int> list;

    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(30);

    EXPECT_EQ(list.popBack().value(), 30);
    EXPECT_EQ(list.peekBack().value(), 20);

    EXPECT_EQ(list.popBack().value(), 20);
    EXPECT_EQ(list.popBack().value(), 10);

    EXPECT_TRUE(list.isEmpty());
}

TEST(DoublyLinkedListTest, MixedPushAndPop) {
    DoublyLinkedList<int> list;

    list.pushFront(20);
    list.pushFront(10);
    list.pushBack(30);

    EXPECT_EQ(list.peekFront().value(), 10);
    EXPECT_EQ(list.peekBack().value(), 30);

    EXPECT_EQ(list.popFront().value(), 10);
    EXPECT_EQ(list.popBack().value(), 30);

    EXPECT_EQ(list.peekFront().value(), 20);
    EXPECT_EQ(list.peekBack().value(), 20);
}

TEST(DoublyLinkedListTest, WorksWithStrings) {
    DoublyLinkedList<std::string> list;

    list.pushBack("hello");
    list.pushBack("world");

    EXPECT_EQ(list.peekFront().value(), "hello");
    EXPECT_EQ(list.peekBack().value(), "world");
}
