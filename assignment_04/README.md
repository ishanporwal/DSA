# Assignment 04 - Sorting Algorithms

## Complexity Analysis

### Insertion Sort

Insertion sort goes through the list and moves each element backwards until it gets to the right spot. If the list is already sorted, each element only needs one comparison, so the best case is O(n). In the average and worst cases, elements may have to move through a large part of the sorted section, which gives O(n^2).

### Selection Sort

Selection sort goes through the unsorted part of the list and finds the smallest element to put in the current position. Even if the list is already sorted, it still has to search through the rest of the list each time. Because of this, the best, average, and worst cases are all O(n^2).

### Merge Sort

Merge sort keeps splitting the list in half until each section only has one element. It then merges those sections back together in sorted order. There are about log(n) levels of splitting, and each level does O(n) work while merging, so the total runtime is O(n log n).

### Quick Sort

Quicksort picks a pivot, puts smaller values on one side and larger values on the other, and then recursively sorts both sides. If the pivot splits the list pretty evenly, the runtime is O(n log n), which is also the average case.

In the worst case, the pivot can keep ending up at one end of the list, which gives O(n^2). My implementation uses the last element as the pivot, so already sorted or reverse-sorted lists can cause this worst-case behavior.

## Performance Testing

I tested insertion sort, selection sort, merge sort, and quicksort on random lists of sizes 10, 100, 1,000, 10,000, and 100,000.

For each trial, I generated a list of random integers between 0 and 100,000. I then copied the same list for each sorting algorithm so they were all sorting the same values.

I used `std::chrono::high_resolution_clock` to measure how long each sort took in milliseconds. I did not include the time it took to generate or copy the lists.

I ran each test 3 times with new random data each time and averaged the runtimes.

## Results

| List Size | Insertion Sort (ms) | Selection Sort (ms) | Merge Sort (ms) | Quick Sort (ms) |
|----------:|--------------------:|--------------------:|----------------:|----------------:|
| 10 | 0.0004 | 0.000633 | 0.003467 | 0.0005 |
| 100 | 0.0207 | 0.034933 | 0.012233 | 0.007667 |
| 1,000 | 1.65373 | 2.2942 | 0.139667 | 0.106167 |
| 10,000 | 171.378 | 239.12 | 1.75807 | 1.20577 |
| 100,000 | 25094.8 | 37766.1 | 28.9556 | 19.7261 |

## Conclusions

For really small lists, all of the algorithms were pretty fast and the differences were small. Merge sort was actually slower at size 10, which makes sense because there is extra overhead from recursively splitting and merging the list.

Once the list sizes got bigger, insertion sort and selection sort got much slower than merge sort and quicksort. At 100,000 elements, insertion sort took about 25 seconds and selection sort took about 38 seconds, while merge sort took about 29 milliseconds and quicksort took about 20 milliseconds.

This lines up with the expected runtimes. Insertion sort and selection sort are O(n^2), while merge sort is O(n log n) and quicksort is O(n log n) on average. The difference gets way more noticeable as the list gets larger.

In my tests, quicksort was the fastest for most of the larger inputs, while selection sort was the slowest.
