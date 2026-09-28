#include <gtest/gtest.h>

#include "graph.hpp"


TEST(GraphTest, StartsEmpty) {
    Graph<int> graph;

    EXPECT_TRUE(graph.getVertices().empty());
}


TEST(GraphTest, AddEdgeAddsBothVertices) {
    Graph<int> graph;

    graph.addEdge(1, 2, 5.0);

    auto vertices = graph.getVertices();

    EXPECT_EQ(vertices.size(), 2);
    EXPECT_NE(vertices.find(1), vertices.end());
    EXPECT_NE(vertices.find(2), vertices.end());
}


TEST(GraphTest, GetEdgesReturnsOutgoingEdges) {
    Graph<int> graph;

    graph.addEdge(1, 2, 5.0);
    graph.addEdge(1, 3, 2.0);

    auto edges = graph.getEdges(1);

    EXPECT_EQ(edges.size(), 2);
    EXPECT_DOUBLE_EQ(edges.at(2), 5.0);
    EXPECT_DOUBLE_EQ(edges.at(3), 2.0);
}


TEST(GraphTest, GraphIsDirected) {
    Graph<int> graph;

    graph.addEdge(1, 2, 5.0);

    auto edgesFromOne = graph.getEdges(1);
    auto edgesFromTwo = graph.getEdges(2);

    EXPECT_NE(edgesFromOne.find(2), edgesFromOne.end());
    EXPECT_TRUE(edgesFromTwo.empty());
}


TEST(GraphTest, UnknownVertexHasNoEdges) {
    Graph<int> graph;

    auto edges = graph.getEdges(100);

    EXPECT_TRUE(edges.empty());
}


TEST(GraphTest, ClearRemovesEverything) {
    Graph<int> graph;

    graph.addEdge(1, 2, 5.0);
    graph.addEdge(2, 3, 4.0);

    graph.clear();

    EXPECT_TRUE(graph.getVertices().empty());
}
