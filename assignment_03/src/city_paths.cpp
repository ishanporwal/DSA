#include <iostream>
#include <string>

#include "graph.hpp"
#include "dijkstra.hpp"

/**
 * Finds and prints the shortest path between two cities.
 *
 * @param graph The graph containing the city connections.
 * @param start The starting city.
 * @param goal The destination city.
 */
void printShortestPath(
    const Graph<std::string>& graph,
    const std::string& start,
    const std::string& goal
) {
    auto path = dijkstra(graph, start, goal);

    if (!path.has_value()) {
        std::cout << "No path found from " << start << " to " << goal << "\n";
        return;
    }
    std::cout << "Shortest path from " << start << " to " << goal << ": ";
    for (size_t i = 0; i < path->size(); i++) {
        std::cout << (*path)[i];

        if (i < path->size() - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << "\n";
}

/**
 * Builds a sample weighted city graph and prints several shortest paths.
 *
 * @return 0 after running the example program.
 */
int main() {
    Graph<std::string> graph;
    // Adds a road in both directions since the underlying graph is directed.
    auto addRoad = [&graph](
        const std::string& city1,
        const std::string& city2,
        double distance
    ) {
        graph.addEdge(city1, city2, distance);
        graph.addEdge(city2, city1, distance);
    };
    
    addRoad("New York", "Philadelphia", 97);
    addRoad("New York", "Chicago", 796);
    addRoad("Philadelphia", "Chicago", 758);
    addRoad("Chicago", "Dallas", 967);
    addRoad("Chicago", "Houston", 1083);
    addRoad("Dallas", "Fort Worth", 33);
    addRoad("Dallas", "Houston", 239);
    addRoad("Fort Worth", "San Antonio", 266);
    addRoad("Houston", "San Antonio", 197);
    addRoad("San Antonio", "Phoenix", 981);
    addRoad("Dallas", "Phoenix", 1064);
    addRoad("Phoenix", "San Diego", 354);
    addRoad("Phoenix", "Los Angeles", 373);
    addRoad("San Diego", "Los Angeles", 120);

    printShortestPath(graph, "New York", "San Diego");
    printShortestPath(graph, "Philadelphia", "Los Angeles");
    printShortestPath(graph, "Houston", "San Diego");
    return 0;
}
