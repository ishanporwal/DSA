#include <vector>
#include <algorithm>

/**
 * Sorts a vector of integers in ascending order using insertion sort.
 *
 * @param unsorted The vector to sort.
 */
void insertion_sort(std::vector<int>& unsorted) {
    for (int i = 1; i < unsorted.size(); ++i) {
        int cur = unsorted[i];
        int j = i - 1;
        while (j >= 0 && cur < unsorted[j]) {
            unsorted[j + 1] = unsorted[j];
            j -= 1;
        }
        unsorted[j + 1] = cur;
    }
}

/**
 * Sorts a vector of integers in ascending order using selection sort.
 *
 * @param unsorted The vector to sort.
 */
void selection_sort(std::vector<int>& unsorted) {
    for (int i = 0; i < unsorted.size(); ++i) {
        int minidx = i;
        for (int j = i + 1; j < unsorted.size(); ++j) {
            if (unsorted[j] < unsorted[minidx]) {
                minidx = j;
            } 
        }
        if (minidx != i) {
            int tmp = unsorted[i];
            unsorted[i] = unsorted[minidx];
            unsorted[minidx] = tmp;
        }
    }
}

/**
 * Sorts a section of a vector in ascending order using merge sort.
 *
 * @param arr The vector to sort.
 * @param left The starting index of the section to sort.
 * @param right The ending index of the section to sort.
 */
void merge_sort(std::vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);

    static std::vector<int> tmp;
    if (tmp.size() < arr.size()) {
        tmp.resize(arr.size());
    }

    auto merge = [&](int l, int r, int m) {
        std::copy(arr.begin() + l, arr.begin() + r + 1, tmp.begin() + l);
        int i = l;
        int j = m + 1;
        int k = l;
        while (i <= m && j <= r) {
            if (tmp[i] <= tmp[j]) {
                arr[k++] = tmp[i++];
            }
            else {
                arr[k++] = tmp[j++];
            }
        }
        while (i <= m) {
            arr[k++] = tmp[i++];
        }
        while (j <= r) {
            arr[k++] = tmp[j++];
        }
    };

    merge(left, right, mid);
}

/**
 * Sorts a vector of integers in ascending order using quicksort.
 *
 * @param arr The vector to sort.
 */
void quickSort(std::vector<int>& arr) {
    auto partition = [&](int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (arr[j] <= pivot) {
                ++i;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        return i + 1;
    };

    auto sort = [&](auto&& self, int low, int high) -> void {
        if (low >= high) {
            return;
        }
        int pivotidx = partition(low, high);

        self(self, low, pivotidx - 1);
        self(self, pivotidx + 1, high);
    };

    if (!arr.empty()) {
        sort(sort, 0, arr.size() - 1);
    }
}
