#pragma once

#include <optional>
#include <queue>
#include <vector>
#include <unordered_map>
#include <utility>

template <typename T>
class MinPriorityQueue {
    public:
        /**
         * Checks whether the queue contains any entries.
         *
         * @return true if the queue is empty; otherwise false.
         */
        bool isEmpty() const {
            return priorities_.empty();
        }

        /**
         * Adds an element to the queue with the given priority.
         * Lower priority values are removed first.
         *
         * @param elem The element to add.
         * @param priority The priority assigned to the element.
         */
        void addWithPriority(const T& elem, double priority) {
            pq_.push(std::pair<double, T>{priority, elem});
            priorities_[elem] = priority;
        }

        /**
         * Removes and returns the element with the lowest priority value.
         *
         * @return The next element, or std::nullopt if the queue is empty.
         */
        std::optional<T> next() {
            while (!pq_.empty()) {
                auto [priority, elem] = pq_.top();
                pq_.pop();
                // Skip old queue entries whose priority has since been changed.
                auto it = priorities_.find(elem);
                if (it != priorities_.end() && it->second == priority) {
                    priorities_.erase(it);
                    return elem;
                }
            }
            return std::nullopt;
        }

        /**
         * Changes the priority of an element already in the queue.
         *
         * @param elem The element whose priority should be changed.
         * @param newPriority The new priority value.
         */
        void adjustPriority(const T& elem, double newPriority) {
            auto it = priorities_.find(elem);
            if (it != priorities_.end()) {
                it->second = newPriority;
                pq_.push(std::pair<double, T>{newPriority, elem});
            }
        }

    private:
        /**
         * Compares two queue entries by priority so the heap keeps the smallest value on top.
         *
         * @param a The first entry to compare.
         * @param b The second entry to compare.
         * @return true if a should come after b in the heap ordering.
         */
        struct Compare {
            bool operator()(const std::pair<double, T>& a, 
                            const std::pair<double, T>& b) const {
                return a.first > b.first;
            }
        };

        std::priority_queue<
            std::pair<double, T>,
            std::vector<std::pair<double, T>>,
            Compare
        > pq_;

        std::unordered_map<T, double> priorities_;
};
