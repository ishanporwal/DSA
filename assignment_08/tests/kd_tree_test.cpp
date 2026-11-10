#include <gtest/gtest.h>
#include "KDTree.hpp"
#include "BruteForce.hpp"
#include <random>

TEST(KDTreeTest, SinglePoint) {
    std::vector<Point> points = {{2, 3}};
    Point query = {5, 6};
    KDTree tree(points);
    EXPECT_EQ(tree.nearestNeighbor(query), points[0]);
    EXPECT_EQ(bruteForceNearest(points, query), points[0]);
}

TEST(KDTreeTest, TwoDimensions) {
    std::vector<Point> points = {
        {2, 3}, {5, 4}, {9, 6}, {4, 7}, {8, 1}, {7, 2}
    };
    Point query = {9, 2};
    Point expected = {8, 1};
    KDTree tree(points);
    EXPECT_EQ(tree.nearestNeighbor(query), expected);
    EXPECT_EQ(bruteForceNearest(points, query), expected);
}

TEST(KDTreeTest, ThreeDimensions) {
    std::vector<Point> points = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {2, 3, 4}
    };
    Point query = {4.5, 5, 6};
    Point expected = {4, 5, 6};
    KDTree tree(points);
    EXPECT_EQ(tree.nearestNeighbor(query), expected);
    EXPECT_EQ(bruteForceNearest(points, query), expected);
}

TEST(KDTreeTest, OneDimension) {
    std::vector<Point> points = {
        {1}, {5}, {10}, {15}, {20}
    };
    Point query = {12};
    Point expected = {10};
    KDTree tree(points);
    EXPECT_EQ(tree.nearestNeighbor(query), expected);
    EXPECT_EQ(bruteForceNearest(points, query), expected);
}

TEST(KDTreeTest, ExactMatch) {
    std::vector<Point> points = {
        {1, 2}, {3, 4}, {5, 6}, {7, 8}
    };
    Point query = {5, 6};
    KDTree tree(points);
    EXPECT_EQ(tree.nearestNeighbor(query), query);
    EXPECT_EQ(bruteForceNearest(points, query), query);
}

TEST(KDTreeTest, NegativeCoordinates) {
    std::vector<Point> points = {
        {-5, -5}, {-2, 3}, {4, -1}, {6, 7}
    };
    Point query = {-4, -3};
    Point expected = {-5, -5};
    KDTree tree(points);
    EXPECT_EQ(tree.nearestNeighbor(query), expected);
    EXPECT_EQ(bruteForceNearest(points, query), expected);
}

TEST(KDTreeTest, OppositeSubtree) {
    // Nearest neighbor is across the splitting plane
    std::vector<Point> points = {
        {0, 0}, {4.9, 0}, {5, 20}, {10, 0}, {11, 5}
    };
    Point query = {5.2, 0};
    Point expected = {4.9, 0};
    KDTree tree(points);
    EXPECT_EQ(tree.nearestNeighbor(query), expected);
    EXPECT_EQ(bruteForceNearest(points, query), expected);
}

TEST(KDTreeTest, HigherDimensions) {
    std::vector<Point> points = {
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {8, 8, 8, 8, 8}
    };
    Point query = {1, 2, 3, 4, 6};
    Point expected = {1, 2, 3, 4, 5};
    KDTree tree(points);
    EXPECT_EQ(tree.nearestNeighbor(query), expected);
    EXPECT_EQ(bruteForceNearest(points, query), expected);
}

TEST(KDTreeTest, RandomPoints) {
    std::mt19937 gen(42);
    std::uniform_real_distribution<double> dist(-100, 100);
    // test different numbers of dimensions
    for (int k : {2, 3, 5, 10}) {
        std::vector<Point> points;
        // generate 100 random points
        for (int i = 0; i < 100; i++) {
            Point point(k);
            for (int j = 0; j < k; j++) {
                point[j] = dist(gen);
            }
            points.push_back(point);
        }
        KDTree tree(points);
        // compare Nearest neighbors for 20 random queries
        for (int i = 0; i < 20; i++) {
            Point query(k);
            for (int j = 0; j < k; j++) {
                query[j] = dist(gen);
            }

            Point kdResult = tree.nearestNeighbor(query);
            Point bruteResult = bruteForceNearest(points, query);
            EXPECT_DOUBLE_EQ(
                distanceSquared(query, kdResult),
                distanceSquared(query, bruteResult)
            );
        }
    }
}
