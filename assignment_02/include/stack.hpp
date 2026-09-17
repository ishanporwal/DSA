#pragma once

#include "doubly_linked_list.hpp"
#include <optional>

template <typename T>
class Stack {
public:
    void push(T data) {
        list.pushFront(data);
    }

    std::optional<T> pop() {
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
