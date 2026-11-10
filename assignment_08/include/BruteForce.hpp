#pragma once
#include <vector>

using Point = std::vector<double>;

/**
 * Computes the squared Euclidean distance between two points.
 *
 * @param point1 First point
 * @param point2 Second point
 * @return Squared distance between the points
 */
double distanceSquared(const Point& point1, const Point& point2) {
    // build euclidean distance total by iterating through points
    double tot = 0.0;
    for (int i = 0; i < point1.size(); i++) {
        double diff = point1[i] - point2[i];
        tot += diff * diff;
    }
    return tot;
}

/**
 * Finds the nearest point to a query by checking every point in the dataset.
 *
 * @param points Points to search
 * @param query Point to compare against the dataset
 * @return Closest point to the query
 */
Point bruteForceNearest(const std::vector<Point>& points, const Point& query) {
    // initially first is best
    Point best = points[0];
    double bestDist = distanceSquared(query, best);
    // iterate through the rest updating best if necessary
    for (int i = 1; i < points.size(); i++) {
        double dist = distanceSquared(query, points[i]);
        if (dist < bestDist) {
            bestDist = dist;
            best = points[i];
        }
    }
    return best;
}
