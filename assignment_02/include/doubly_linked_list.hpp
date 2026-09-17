#pragma once
#include <optional>

template <typename T>
class DoublyLinkedList {

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

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

    std::optional<T> peekFront() const {
        if (isEmpty()) {
            return std::nullopt;
        }
        return head->val;
    }


    std::optional<T> peekBack() const {
        if (isEmpty()) {
            return std::nullopt;
        }
        return tail->val;
    }

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
