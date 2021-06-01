#pragma once

#include "IGraph.h"

class MatrixGraph : public IGraph {
 public:
    explicit MatrixGraph(int _verticesCount);
    explicit MatrixGraph(const IGraph &igraph);

    ~MatrixGraph() override = default;

    void AddEdge(int from, int to) override;

    [[nodiscard]] int VerticesCount() const override;

    [[nodiscard]] std::vector<int> GetNextVertices(int vertex) const override;
    [[nodiscard]] std::vector<int> GetPrevVertices(int vertex) const override;

 private:
    std::vector<std::vector<bool>> graph;
    int verticesCount;
};
