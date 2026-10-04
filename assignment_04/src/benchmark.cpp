#include <chrono>
#include <iostream>
#include <random>
#include <vector>

#include "sorting.hpp"

/**
 * Tests the runtime of each sorting algorithm on random lists of different sizes.
 * Each test is run three times and the average runtime is printed.
 *
 * @return 0 when the program finishes.
 */
int main() {
    std::vector<int> sizes = {10, 100, 1000, 10000, 100000};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 100000);

    for (int size : sizes) {
        double insertionTotal = 0;
        double selectionTotal = 0;
        double mergeTotal = 0;
        double quickTotal = 0;

        for (int trial = 0; trial < 3; ++trial) {
            std::vector<int> original;

            for (int i = 0; i < size; ++i) {
                original.push_back(dist(gen));
            }

            std::vector<int> insertion = original;
            std::vector<int> selection = original;
            std::vector<int> merge = original;
            std::vector<int> quick = original;

            // Insertion sort
            auto start = std::chrono::high_resolution_clock::now();
            insertion_sort(insertion);
            auto end = std::chrono::high_resolution_clock::now();
            double insertionTime = std::chrono::duration<double, std::milli>(end - start).count();
            insertionTotal += insertionTime;

            // Selection sort
            start = std::chrono::high_resolution_clock::now();
            selection_sort(selection);
            end = std::chrono::high_resolution_clock::now();
            double selectionTime = std::chrono::duration<double, std::milli>(end - start).count();
            selectionTotal += selectionTime;

            // Merge sort
            start = std::chrono::high_resolution_clock::now();
            merge_sort(merge, 0, merge.size() - 1);
            end = std::chrono::high_resolution_clock::now();
            double mergeTime = std::chrono::duration<double, std::milli>(end - start).count();
            mergeTotal += mergeTime;

            // Quick sort
            start = std::chrono::high_resolution_clock::now();
            quickSort(quick);
            end = std::chrono::high_resolution_clock::now();
            double quickTime = std::chrono::duration<double, std::milli>(end - start).count();
            quickTotal += quickTime;
        }

        std::cout << "Size: " << size << "\n";
        std::cout << "Insertion: " << insertionTotal / 3 << " ms\n";
        std::cout << "Selection: " << selectionTotal / 3 << " ms\n";
        std::cout << "Merge: " << mergeTotal / 3 << " ms\n";
        std::cout << "Quick: " << quickTotal / 3 << " ms\n";
        std::cout << "\n";
    }
}
