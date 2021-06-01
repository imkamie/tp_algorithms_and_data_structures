#include "ArcGraph.h"

ArcGraph::ArcGraph(int _verticesCount) : verticesCount(_verticesCount) {
    graph.resize(verticesCount);
}

ArcGraph::ArcGraph(const IGraph &igraph) {
    verticesCount = igraph.VerticesCount();

    for (int from = 0; from < igraph.VerticesCount(); ++from) {
        for (auto &to : igraph.GetNextVertices(from)) {
            graph.emplace_back(from, to);
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    graph.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const {
    return verticesCount;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;

    for (const auto &i : graph) {
        if (i.first == vertex) {
            result.push_back(i.second);
        }
    }

    return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;

    for (const auto &i : graph) {
        if (i.second == vertex) {
            result.push_back(i.first);
        }
    }

    return result;
}
