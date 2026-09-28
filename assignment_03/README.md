# Assignment 03 - Graphs and Dijkstra's Algorithm

For this assignment I implemented a weighted directed graph, a min priority queue, and Dijkstra's shortest path algorithm in C++.

## Implementation

The main parts are:

- `Graph` - stores vertices and weighted directed edges
- `MinPriorityQueue` - uses `std::priority_queue` and supports changing priorities
- `dijkstra` - returns the shortest path between two vertices, or `std::nullopt` if there isn't one

For changing priorities, I keep track of the current priority of each element separately. If an older version of that element is still in the priority queue, it gets skipped when it comes out (lazy deletion).

## Example

For the application part, I made a graph of 10 major U.S. cities using approximate driving distances as the edge weights.

One example output is:

```text
Shortest path from New York to San Diego: New York -> Chicago -> Dallas -> Phoenix -> San Diego
```

I also tested a few other city pairs to make sure the shortest path calculation was working.

## Build and Run

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

To run the city example:

```bash
.\build\city_paths.exe
```
