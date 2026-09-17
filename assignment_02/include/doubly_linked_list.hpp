#pragma once
#include <optional>

template <typename T>
class DoublyLinkedList {

public:
    /**
     * Creates an empty doubly linked list.
     */
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    /**
     * Inserts a value at the front of the list.
     *
     * @param data The value to insert.
     */
    void pushFront(T data) {
        ListNode* n = new ListNode{data, nullptr, head};
        if (isEmpty()) {
            head = n;
            tail = n;
            return;
        }
        head->prev = n;
        head = n;
    }

    /**
     * Inserts a value at the back of the list.
     *
     * @param data The value to insert.
     */
    void pushBack(T data) {
        ListNode* n = new ListNode{data, tail, nullptr};
        if (isEmpty()) {
            head = n;
            tail = n;
            return;
        }
        tail->next = n;
        tail = n;
    }

    /**
     * Removes and returns the value at the front of the list.
     *
     * @return The front value, or std::nullopt if the list is empty.
     */
    std::optional<T> popFront() {
        if (isEmpty()) {
            return std::nullopt;
        }
        ListNode* oldHead = head;
        T value = oldHead->val;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        
        delete oldHead;
        return value;
    }

    /**
     * Removes and returns the value at the back of the list.
     *
     * @return The back value, or std::nullopt if the list is empty.
     */
    std::optional<T> popBack() {
        if (isEmpty()) {
            return std::nullopt;
        }
        ListNode* oldTail = tail;
        T value = oldTail->val;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        
        delete oldTail;
        return value;
    }

    /**
     * Returns the value at the front of the list without removing it.
     *
     * @return The front value, or std::nullopt if the list is empty.
     */
    std::optional<T> peekFront() const {
        if (isEmpty()) {
            return std::nullopt;
        }
        return head->val;
    }

    /**
     * Returns the value at the back of the list without removing it.
     *
     * @return The back value, or std::nullopt if the list is empty.
     */
    std::optional<T> peekBack() const {
        if (isEmpty()) {
            return std::nullopt;
        }
        return tail->val;
    }

    /**
     * Checks whether the list is empty.
     *
     * @return true if the list has no elements; otherwise false.
     */
    bool isEmpty() const {
        if (head == nullptr) {
            return true;
        }
        return false;
    }

private:
    struct ListNode
    {
        T val;
        ListNode* prev;
        ListNode* next;
    };

    ListNode* head;
    ListNode* tail;
    
};
