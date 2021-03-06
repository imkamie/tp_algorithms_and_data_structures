#pragma once

#include <set>

#include "IGraph.h"

class SetGraph : public IGraph {
 public:
    explicit SetGraph(int _verticesCount);
    explicit SetGraph(const IGraph &igraph);

    ~SetGraph() override = default;

    void AddEdge(int from, int to) override;

    [[nodiscard]] int VerticesCount() const override;

    [[nodiscard]] std::vector<int> GetNextVertices(int vertex) const override;
    [[nodiscard]] std::vector<int> GetPrevVertices(int vertex) const override;

 private:
    std::vector<std::set<int>> graph;
    int verticesCount;
};
