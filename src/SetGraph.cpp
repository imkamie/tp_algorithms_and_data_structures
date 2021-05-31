#include <algorithm>

#include "SetGraph.h"

SetGraph::SetGraph(int _verticesCount) : verticesCount(_verticesCount) {
    graph.resize(verticesCount);
}

SetGraph::SetGraph(const IGraph &igraph) {
    verticesCount = igraph.VerticesCount();
    graph.resize(verticesCount);

    for (int from = 0; from < igraph.VerticesCount(); ++from) {
        std::vector<int> nextVertice = igraph.GetNextVertices(from);
        for (auto &to : nextVertice) {
            graph[from].insert(to);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    graph[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return verticesCount;
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    result.resize(graph[vertex].size());
    std::copy(graph[vertex].begin(), graph[vertex].end(), result.begin());
    return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;

    for (int parent = 0; parent < graph.size(); ++parent) {
        for (auto &child : graph[parent]) {
            if (child == vertex) {
                result.push_back(parent);
            }
        }
    }

    return result;
}
