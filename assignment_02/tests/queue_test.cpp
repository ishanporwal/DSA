#include <gtest/gtest.h>
#include "queue.hpp"

TEST(QueueTest, StartsEmpty) {
    Queue<int> queue;

    EXPECT_TRUE(queue.isEmpty());
    EXPECT_EQ(queue.peek(), std::nullopt);
    EXPECT_EQ(queue.dequeue(), std::nullopt);
}

TEST(QueueTest, EnqueueSingle) {
    Queue<int> queue;

    queue.enqueue(10);

    EXPECT_FALSE(queue.isEmpty());
    EXPECT_EQ(queue.peek().value(), 10);
}

TEST(QueueTest, EnqueueMultiple) {
    Queue<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    EXPECT_EQ(queue.peek().value(), 10);
}

TEST(QueueTest, DequeueFIFO) {
    Queue<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    EXPECT_EQ(queue.dequeue().value(), 10);
    EXPECT_EQ(queue.dequeue().value(), 20);
    EXPECT_EQ(queue.dequeue().value(), 30);
}

TEST(QueueTest, EmptyAfterDequeuingAll) {
    Queue<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);

    queue.dequeue();
    queue.dequeue();

    EXPECT_TRUE(queue.isEmpty());
    EXPECT_EQ(queue.peek(), std::nullopt);
    EXPECT_EQ(queue.dequeue(), std::nullopt);
}

TEST(QueueTest, WorksWithStrings) {
    Queue<std::string> queue;

    queue.enqueue("hello");
    queue.enqueue("world");

    EXPECT_EQ(queue.peek().value(), "hello");
    EXPECT_EQ(queue.dequeue().value(), "hello");
    EXPECT_EQ(queue.dequeue().value(), "world");
}
