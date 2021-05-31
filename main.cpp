#include <iostream>

#include "ListGraph.h"

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

int main() {
    ListGraph graph(7);
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 4);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(4, 5);
    graph.AddEdge(4, 6);

    ListGraph anotherGraph(graph);

    dfs(graph, [](int v) {
        std::cout << v << " ";
    });

    std::cout << std::endl;

    dfs(anotherGraph, [](int v) {
      std::cout << v << " ";
    });

    return 0;
}
