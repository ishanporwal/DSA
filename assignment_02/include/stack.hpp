#pragma once

#include "doubly_linked_list.hpp"
#include <optional>

template <typename T>
class Stack {
public:
    /**
     * Adds a value to the top of the stack.
     *
     * @param data The value to add.
     */
    void push(T data) {
        list.pushFront(data);
    }

    /**
     * Removes and returns the value at the top of the stack.
     *
     * @return The top value, or std::nullopt if the stack is empty.
     */
    std::optional<T> pop() {
        return list.popFront();
    }

    /**
     * Returns the value at the top of the stack without removing it.
     *
     * @return The top value, or std::nullopt if the stack is empty.
     */
    std::optional<T> peek() const {
        return list.peekFront();
    }

    /**
     * Checks whether the stack is empty.
     *
     * @return true if the stack has no elements; otherwise false.
     */
    bool isEmpty() const {
        return list.isEmpty();
    }

private:
    DoublyLinkedList<T> list;
};
