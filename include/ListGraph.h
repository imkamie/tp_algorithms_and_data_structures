#pragma once

#include "IGraph.h"

class ListGraph : public IGraph {
 public:
    explicit ListGraph(int _verticesCount);
    explicit ListGraph(const IGraph& graph);

    ~ListGraph() override = default;

    void AddEdge(int from, int to) override;

    [[nodiscard]] int VerticesCount() const override;

    [[nodiscard]] std::vector<int> GetNextVertices(int vertex) const override;
    [[nodiscard]] std::vector<int> GetPrevVertices(int vertex) const override;

 private:
    std::vector<std::vector<int>> graph;
    int verticesCount;
};
