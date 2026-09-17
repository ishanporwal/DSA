#pragma once

#include "doubly_linked_list.hpp"
#include <optional>

template <typename T>
class Queue {
public:
    void enqueue(T data) {
        list.pushBack(data);
    }

    std::optional<T> dequeue() {
        return list.popFront();
    }

    std::optional<T> peek() const {
        return list.peekFront();
    }

    bool isEmpty() const {
        return list.isEmpty();
    }

private:
    DoublyLinkedList<T> list;
};
