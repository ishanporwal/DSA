#pragma once

#include <unordered_map>
#include <unordered_set>

template <typename VertexType>
class Graph {
    public:
        /**
         * Returns all vertices currently stored in the graph.
         *
         * @return A set containing every vertex in the graph.
         */
        std::unordered_set<VertexType> getVertices() const {
            std::unordered_set<VertexType> res;
            for (const auto& [vertex, edges] : graph_) {
                res.insert(vertex);
            }
            return res;
        }

        /**
         * Adds a directed edge from one vertex to another.
         *
         * @param from The starting vertex.
         * @param to The destination vertex.
         * @param cost The weight of the edge.
         */
        void addEdge(const VertexType& from, const VertexType& to, double cost) {
            graph_[from][to] = cost;
            if (graph_.find(to) == graph_.end()) {
                graph_[to];
            }
        }

        /**
         * Returns all outgoing edges from a given vertex.
         *
         * @param from The vertex whose outgoing edges should be retrieved.
         * @return A map of neighboring vertices to their edge weights.
         */
        std::unordered_map<VertexType, double> getEdges(const VertexType& from) const {
            auto it = graph_.find(from);
            if (it != graph_.end()) {
                return it->second;
            }
            else {
                return std::unordered_map<VertexType, double> {};
            }
        }

        /**
         * Removes all vertices and edges from the graph.
         */
        void clear() {
            graph_.clear();
        }

    private:
        std::unordered_map<VertexType, std::unordered_map<VertexType, double>> graph_;
};
