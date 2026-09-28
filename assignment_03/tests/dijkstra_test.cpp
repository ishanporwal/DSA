#include <gtest/gtest.h>

#include "dijkstra.hpp"


TEST(DijkstraTest, StartEqualsGoal) {
    Graph<int> graph;

    graph.addEdge(1, 2, 5.0);

    auto path = dijkstra(graph, 1, 1);

    ASSERT_TRUE(path.has_value());
    EXPECT_EQ(*path, std::vector<int>({1}));
}


TEST(DijkstraTest, FindsDirectPath) {
    Graph<int> graph;

    graph.addEdge(1, 2, 5.0);

    auto path = dijkstra(graph, 1, 2);

    ASSERT_TRUE(path.has_value());
    EXPECT_EQ(*path, std::vector<int>({1, 2}));
}


TEST(DijkstraTest, FindsShortestPathInsteadOfDirectPath) {
    Graph<int> graph;

    graph.addEdge(1, 2, 10.0);
    graph.addEdge(1, 3, 2.0);
    graph.addEdge(3, 2, 3.0);

    auto path = dijkstra(graph, 1, 2);

    ASSERT_TRUE(path.has_value());
    EXPECT_EQ(*path, std::vector<int>({1, 3, 2}));
}


TEST(DijkstraTest, FindsPathThroughMultipleVertices) {
    Graph<int> graph;

    graph.addEdge(1, 2, 4.0);
    graph.addEdge(1, 3, 1.0);
    graph.addEdge(3, 2, 2.0);
    graph.addEdge(2, 4, 1.0);
    graph.addEdge(3, 4, 5.0);

    auto path = dijkstra(graph, 1, 4);

    ASSERT_TRUE(path.has_value());
    EXPECT_EQ(*path, std::vector<int>({1, 3, 2, 4}));
}


TEST(DijkstraTest, AdjustsPriorityWhenShorterPathFound) {
    Graph<int> graph;

    graph.addEdge(1, 2, 8.0);
    graph.addEdge(1, 3, 2.0);
    graph.addEdge(3, 2, 1.0);
    graph.addEdge(2, 4, 1.0);
    graph.addEdge(3, 4, 10.0);

    auto path = dijkstra(graph, 1, 4);

    ASSERT_TRUE(path.has_value());
    EXPECT_EQ(*path, std::vector<int>({1, 3, 2, 4}));
}


TEST(DijkstraTest, ReturnsNulloptWhenNoPathExists) {
    Graph<int> graph;

    graph.addEdge(1, 2, 1.0);
    graph.addEdge(3, 4, 1.0);

    auto path = dijkstra(graph, 1, 4);

    EXPECT_FALSE(path.has_value());
}


TEST(DijkstraTest, RespectsDirectedEdges) {
    Graph<int> graph;

    graph.addEdge(1, 2, 1.0);

    auto path = dijkstra(graph, 2, 1);

    EXPECT_FALSE(path.has_value());
}
