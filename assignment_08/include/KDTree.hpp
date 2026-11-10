#pragma once
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>

using Point = std::vector<double>;

/**
 * Stores points in a K-D tree and searches the tree for nearest neighbors.
 *
 * The tree splits points by cycling through dimensions and placing the median
 * point at each node.
 */
class KDTree {
public:
    /**
     * Builds a K-D tree from the provided points.
     *
     * @param points Points to store in the tree
     */
    KDTree(const std::vector<Point>& points) {
        if (points.empty()) {
            k = 0;
        }
        else {
            k = points[0].size();
        }
        std::vector<Point> copy = points;
        root = buildtree(copy);
    }

    /**
     * Finds the point in the tree closest to the query.
     *
     * @param query Point to compare against the stored points
     * @return Closest point in the tree
     */
    Point nearestNeighbor(const Point& query) const {
        Point best = root->point;
        double bestDist = distanceSquared(query, best);
        // recursively search for nearest point
        searchNearest(root.get(), query, 0, best, bestDist);
        return best;
    }

    /**
     * Prints the tree with indentation representing each node's depth.
     */
    void print() const {
        printTree(root.get(), 0);
    }

private:
    struct Node {
        Point point;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
    };

    std::unique_ptr<Node> root = nullptr;
    int k;

    /**
     * Builds a K-D tree recursively by sorting points along
     * the current axis and splitting around the median.
     *
     * @param points Points in the current subtree
     * @param depth Current depth of the tree
     * @return Root node of the constructed subtree
     */
    std::unique_ptr<Node> buildtree(std::vector<Point>& points, int depth=0) {
        // base case --> no points left to split
        if (points.empty()) {
            return nullptr;
        }
        if (k <= 0) {
            return nullptr;
        }
        // figure out what dimension splitting using
        int axis = depth % k;
        // find median of pts by sorting and split into left and right pts
        int medianidx = points.size() / 2;
        std::sort(points.begin(), points.end(),
            [axis](const Point& pt1, const Point& pt2) {
                return pt1[axis] < pt2[axis];
        });
        std::vector<Point> leftpoints(points.begin(), points.begin() + medianidx);
        std::vector<Point> rightpoints(points.begin() + medianidx + 1, points.end());
        // create median node and recurse left and right
        auto median = std::make_unique<Node>();
        median->point = points[medianidx];
        median->left = buildtree(leftpoints, depth + 1);
        median->right = buildtree(rightpoints, depth + 1);
        // return median node
        return median;
    }

    double distanceSquared(const Point& point1, const Point& point2) const {
        double tot = 0.0;
        for (int i = 0; i < point1.size(); i++) {
            double diff = point1[i] - point2[i];
            tot += diff * diff;
        }
        return tot;
    }

    void searchNearest(const Node* node, const Point& query, int depth, Point& best, double& bestDist) const {
        // base case -> no node
        if (!node) {
            return;
        }
        // check if cur node closest
        double dist = distanceSquared(query, node->point);
        if (dist < bestDist) {
            bestDist = dist;
            best = node->point;
        }
        // figure out dimension splitting on
        int axis = depth % k;
        double diff = query[axis] - node->point[axis];
        // search side most likely containing target first
        const Node* near;
        const Node* far;
        if (diff < 0) {
            near = node->left.get();
            far = node->right.get();
        }
        else {
            near = node->right.get();
            far = node->left.get();
        }
        searchNearest(near, query, depth + 1, best, bestDist);

        // check if other side could have closer
        if(diff * diff <= bestDist) {
            searchNearest(far, query, depth + 1, best, bestDist);
        }
    }
    
    // recursively print each node with indentation based on depth
    void printTree(const Node* node, int depth) const {
        if (!node) {
            return;
        }
        // indent based on tree depth
        for (int i = 0; i < depth; i++) {
            std::cout << "  ";
        }
        // print point coordinates
        std::cout << "(";
        for (size_t i = 0; i < node->point.size(); i++) {
            std::cout << node->point[i];
            if (i + 1 < node->point.size()) {
                std::cout << ", ";
            }
        }
        std::cout << ")" << std::endl;
        // print left and right subtrees
        printTree(node->left.get(), depth + 1);
        printTree(node->right.get(), depth + 1);
    } 
};
