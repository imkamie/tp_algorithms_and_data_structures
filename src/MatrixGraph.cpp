#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int _verticesCount) : verticesCount(_verticesCount) {
    graph.resize(verticesCount);
    for (int i = 0; i < verticesCount; i++) {
        graph[i].resize(verticesCount, false);
    }
}

MatrixGraph::MatrixGraph(const IGraph &igraph) {
    verticesCount = igraph.VerticesCount();
    graph.resize(verticesCount);

    for (int i = 0; i < verticesCount; i++) {
        graph[i].resize(verticesCount, false);
    }

    for (int from = 0; from < verticesCount; ++from) {
        for (auto &to : igraph.GetNextVertices(from)) {
            graph[from][to] = true;
        }
    }

}

void MatrixGraph::AddEdge(int from, int to) {
    graph[from][to] = true;
}

int MatrixGraph::VerticesCount() const {
    return verticesCount;
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;

    for (int i = 0; i < graph[vertex].size(); ++i) {
        if (graph[vertex][i]) {
            result.push_back(i);
        }
    }

    return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;

    for (int i = 0; i < graph[vertex].size(); ++i) {
        if (graph[i][vertex]) {
            result.push_back(i);
        }
    }

    return result;
}
