#include <iostream>

#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"

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
//    ListGraph graph(8);
//    graph.AddEdge(0, 1);
//    graph.AddEdge(0, 4);
//    graph.AddEdge(1, 2);
//    graph.AddEdge(1, 3);
//    graph.AddEdge(4, 5);
//    graph.AddEdge(4, 6);
//    graph.AddEdge(2, 7);
//    graph.AddEdge(3, 7);

//
//
//    ListGraph anotherGraph(graph);
//
//    dfs(graph, [](int v) {
//        std::cout << v << " ";
//    });
//
//    std::cout << std::endl;
//
//    dfs(anotherGraph, [](int v) {
//      std::cout << v << " ";
//    });
//
//    std::cout << std::endl;
//
//    std::vector<int> a = graph.GetPrevVertices(7);
//    for (int i : a) {
//        std::cout << i << " ";
//    }

    MatrixGraph igraph(7);
    igraph.AddEdge(0, 1);
    igraph.AddEdge(0, 4);
    igraph.AddEdge(1, 2);
    igraph.AddEdge(1, 3);
    igraph.AddEdge(4, 5);
    igraph.AddEdge(4, 6);

    dfs(igraph, [](int v) {
      std::cout << v << " ";
    });

    std::cout << std::endl;

    ListGraph graph(igraph);
    dfs(igraph, [](int v) {
      std::cout << v << " ";
    });
    std::cout << std::endl;


//    std::vector<int> a = graph.GetNextVertices(1);
//    for (int i : a) {
//        std::cout << i << " ";
//    }

    SetGraph sgraph(igraph);
//    sgraph.AddEdge(0, 1);
//    sgraph.AddEdge(0, 4);
//    sgraph.AddEdge(1, 2);
//    sgraph.AddEdge(1, 3);
//    sgraph.AddEdge(4, 5);
//    sgraph.AddEdge(4, 6);
//    sgraph.AddEdge(2, 7);
//    sgraph.AddEdge(3, 7);

    dfs(sgraph, [](int v) {
      std::cout << v << " ";
    });

    std::cout << std::endl;
//
    std::vector<int> a = sgraph.GetPrevVertices(2);
    for (int i : a) {
        std::cout << i << " ";
    }


    return 0;
}
