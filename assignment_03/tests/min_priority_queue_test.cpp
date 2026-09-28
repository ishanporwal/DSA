#include <gtest/gtest.h>

#include "min_priority_queue.hpp"


TEST(MinPriorityQueueTest, StartsEmpty) {
    MinPriorityQueue<int> pq;

    EXPECT_TRUE(pq.isEmpty());
}


TEST(MinPriorityQueueTest, AddMakesQueueNonEmpty) {
    MinPriorityQueue<int> pq;

    pq.addWithPriority(10, 5.0);

    EXPECT_FALSE(pq.isEmpty());
}


TEST(MinPriorityQueueTest, RemovesLowestPriorityFirst) {
    MinPriorityQueue<int> pq;

    pq.addWithPriority(10, 5.0);
    pq.addWithPriority(20, 2.0);
    pq.addWithPriority(30, 8.0);

    EXPECT_EQ(pq.next(), 20);
    EXPECT_EQ(pq.next(), 10);
    EXPECT_EQ(pq.next(), 30);
}


TEST(MinPriorityQueueTest, NextRemovesElement) {
    MinPriorityQueue<int> pq;

    pq.addWithPriority(10, 1.0);

    EXPECT_EQ(pq.next(), 10);
    EXPECT_TRUE(pq.isEmpty());
}


TEST(MinPriorityQueueTest, NextOnEmptyReturnsNullopt) {
    MinPriorityQueue<int> pq;

    EXPECT_EQ(pq.next(), std::nullopt);
}


TEST(MinPriorityQueueTest, AdjustPriorityLower) {
    MinPriorityQueue<int> pq;

    pq.addWithPriority(10, 5.0);
    pq.addWithPriority(20, 2.0);

    pq.adjustPriority(10, 1.0);

    EXPECT_EQ(pq.next(), 10);
    EXPECT_EQ(pq.next(), 20);
}


TEST(MinPriorityQueueTest, AdjustPriorityHigher) {
    MinPriorityQueue<int> pq;

    pq.addWithPriority(10, 1.0);
    pq.addWithPriority(20, 2.0);

    pq.adjustPriority(10, 5.0);

    EXPECT_EQ(pq.next(), 20);
    EXPECT_EQ(pq.next(), 10);
}


TEST(MinPriorityQueueTest, AdjustPriorityIgnoresMissingElement) {
    MinPriorityQueue<int> pq;

    pq.addWithPriority(10, 1.0);

    pq.adjustPriority(20, 0.5);

    EXPECT_EQ(pq.next(), 10);
    EXPECT_TRUE(pq.isEmpty());
}
