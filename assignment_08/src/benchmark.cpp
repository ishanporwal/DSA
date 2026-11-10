#include "Benchmark.hpp"
#include "KDTree.hpp"
#include "BruteForce.hpp"
#include <vector>
#include <random>
#include <chrono>

ExperimentResult runExperiment(int k, int numPoints) {
    // generate random points and queries
    std::mt19937 gen(42);
    std::uniform_real_distribution<double> dist(-100.0, 100.0);
    std::vector<Point> points;
    std::vector<Point> queries;
    for (int i = 0; i < numPoints; i++) {
        Point point(k);
        for (int j = 0; j < k; j++) {
            point[j] = dist(gen);
        }
        points.push_back(point);
    }
    // generate 1000 query points
    for (int i = 0; i < 1000; i++) {
        Point query(k);
        for (int j = 0; j < k; j++) {
            query[j] = dist(gen);
        }
        queries.push_back(query);
    }
    // measure time to build kd tree
    auto buildStart = std::chrono::steady_clock::now();
    KDTree tree(points);
    auto buildEnd = std::chrono::steady_clock::now();
    // measure time to query kd tree
    double kdSum = 0.0;
    auto kdStart = std::chrono::steady_clock::now();
    for (const Point& query : queries) {
        Point nearest = tree.nearestNeighbor(query);
        kdSum += nearest[0];
    }
    auto kdEnd = std::chrono::steady_clock::now();
    // measure time to query brute force
    double bruteSum = 0.0;
    auto bruteStart = std::chrono::steady_clock::now();
    for (const Point& query : queries) {
        Point nearest = bruteForceNearest(points, query);
        bruteSum += nearest[0];
    }
    auto bruteEnd = std::chrono::steady_clock::now();
    // make sure compiler doesn't optimize away the results
    volatile double checksum = kdSum + bruteSum;
    (void)checksum;
    return {
        buildEnd - buildStart,
        kdEnd - kdStart,
        bruteEnd - bruteStart
    };
}
