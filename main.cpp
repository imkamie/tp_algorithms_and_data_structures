#include <cassert>
#include <iostream>

#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"

template<typename Callback>
void dfs_aux(const IGraph &graph, std::vector<bool> &visited, int v, Callback callback) {
    visited[v] = true;
    callback(v);
    std::vector<int> children = graph.GetNextVertices(v);
    for (auto child : children) {
        if (!visited[child]) {
            dfs_aux(graph, visited, child, callback);
        }
    }
}

template<typename Callback>
void dfs(const IGraph &graph, Callback callback) {
    std::vector<bool> visited(graph.VerticesCount(), false);
    for (int v = 0; v < graph.VerticesCount(); ++v) {
        if (!visited[v]) {
            dfs_aux(graph, visited, v, callback);
        }
    }
}

void compareNextVertices(const IGraph &first, const IGraph &second) {
    assert(first.VerticesCount() == second.VerticesCount());
    for (int i = 0; i < first.VerticesCount(); ++i) {
        assert(first.GetNextVertices(i) == second.GetNextVertices(i));
    }
}

void comparePrevVertices(const IGraph &first, const IGraph &second) {
    assert(first.VerticesCount() == second.VerticesCount());
    for (int i = 0; i < first.VerticesCount(); ++i) {
        assert(first.GetPrevVertices(i) == second.GetPrevVertices(i));
    }
}

void printGraph(const IGraph &graph) {
    dfs(graph, [](int v) {
      std::cout << v << " ";
    });
    std::cout << std::endl;
}

void test() {
    ListGraph listGraph(7);

    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(0, 2);
    listGraph.AddEdge(2, 5);
    listGraph.AddEdge(1, 3);
    listGraph.AddEdge(1, 4);
    listGraph.AddEdge(3, 6);
    listGraph.AddEdge(4, 6);
    listGraph.AddEdge(5, 4);

    MatrixGraph matrixGraph(listGraph);
    compareNextVertices(listGraph, matrixGraph);
    comparePrevVertices(listGraph, matrixGraph);

    SetGraph setGraph(listGraph);
    compareNextVertices(listGraph, setGraph);
    comparePrevVertices(listGraph, setGraph);

    ArcGraph arcGraph(listGraph);
    compareNextVertices(listGraph, arcGraph);
    comparePrevVertices(listGraph, arcGraph);

    std::cout << "List Graph:" << std::endl;
    printGraph(listGraph);
    std::cout << std::endl;

    std::cout << "Matrix Graph:" << std::endl;
    printGraph(matrixGraph);
    std::cout << std::endl;

    std::cout << "Set Graph:" << std::endl;
    printGraph(setGraph);
    std::cout << std::endl;

    std::cout << "Arc Graph:" << std::endl;
    printGraph(arcGraph);
}

int main() {
    test();
    return 0;
}
