#include <algorithm>

#include "ListGraph.h"

ListGraph::ListGraph(int _verticesCount) : verticesCount(_verticesCount) {
    graph.resize(verticesCount);
}

ListGraph::ListGraph(const IGraph &igraph) {
    verticesCount = igraph.VerticesCount();
    graph.resize(verticesCount);

    for (int from = 0; from < igraph.VerticesCount(); ++from) {
        std::vector<int> nextVertice = igraph.GetNextVertices(from);
        for (auto &to : nextVertice) {
            graph[from].push_back(to);
        }
    }
}

void ListGraph::AddEdge(int from, int to) {
    graph[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return verticesCount;
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    result.resize(graph[vertex].size());
    std::copy(graph[vertex].begin(), graph[vertex].end(), result.begin());
    return result;
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;

    for (int parent = 0; parent < graph.size(); ++parent) {
        for (int child : graph[parent]) {
            if (child == vertex) {
                result.push_back(parent);
            }
        }
    }

    return result;
}
