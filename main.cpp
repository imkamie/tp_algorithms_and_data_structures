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

int main() {

    return 0;
}
