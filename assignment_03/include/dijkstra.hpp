#pragma once

#include "graph.hpp"
#include "min_priority_queue.hpp"
#include <limits>
#include <algorithm>
#include <optional>
#include <vector>
#include <unordered_map>

template <typename VertexType>
/**
 * Finds the shortest path between two vertices using Dijkstra's algorithm.
 *
 * @param graph The weighted graph to search.
 * @param start The starting vertex.
 * @param goal The destination vertex.
 * @return The shortest path from start to goal, or std::nullopt if no path exists.
 */
std::optional<std::vector<VertexType>> dijkstra(
    const Graph<VertexType>& graph,
    const VertexType& start,
    const VertexType& goal
) {
    std::vector<VertexType> path;

    if (start == goal) {
        path.push_back(start);
        return path;
    }

    MinPriorityQueue<VertexType> pq;
    pq.addWithPriority(start, 0);

    std::unordered_map<VertexType, double> distances;

    for (const auto& vertex : graph.getVertices()) {
        distances[vertex] = std::numeric_limits<double>::infinity();
    }

    distances[start] = 0;

    std::unordered_map<VertexType, VertexType> previous;

    while (!pq.isEmpty()) {
        auto nxt = pq.next();
        auto current = *nxt;

        for (const auto& [neighbor, distance] : graph.getEdges(current)) {
            double neighbor_distance = distance + distances[current];

            if (neighbor_distance < distances[neighbor]) {
                bool first_time =
                    distances[neighbor] == std::numeric_limits<double>::infinity();

                distances[neighbor] = neighbor_distance;
                previous[neighbor] = current;

                if (first_time) {
                    pq.addWithPriority(neighbor, neighbor_distance);
                }
                else {
                    pq.adjustPriority(neighbor, neighbor_distance);
                }
            }
        }
    }

    if (previous.find(goal) == previous.end()) {
        return std::nullopt;
    }
    else {
        auto cur = goal;

        // Reconstruct the path backwards from goal to start.
        while (cur != start) {
            path.push_back(cur);
            cur = previous[cur];
        }

        path.push_back(start);
        std::reverse(path.begin(), path.end());

        return path;
    }
}
