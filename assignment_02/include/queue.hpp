#pragma once

#include "doubly_linked_list.hpp"
#include <optional>

template <typename T>
class Queue {
public:
    /**
     * Adds a value to the back of the queue.
     *
     * @param data The value to add.
     */
    void enqueue(T data) {
        list.pushBack(data);
    }

    /**
     * Removes and returns the value at the front of the queue.
     *
     * @return The front value, or std::nullopt if the queue is empty.
     */
    std::optional<T> dequeue() {
        return list.popFront();
    }

    /**
     * Returns the value at the front of the queue without removing it.
     *
     * @return The front value, or std::nullopt if the queue is empty.
     */
    std::optional<T> peek() const {
        return list.peekFront();
    }

    /**
     * Checks whether the queue is empty.
     *
     * @return true if the queue has no elements; otherwise false.
     */
    bool isEmpty() const {
        return list.isEmpty();
    }

private:
    DoublyLinkedList<T> list;
};
