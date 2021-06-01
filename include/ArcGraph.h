#pragma once

#include "IGraph.h"

class ArcGraph : public IGraph {
 public:
    explicit ArcGraph(int _verticesCount);
    explicit ArcGraph(const IGraph &igraph);

    ~ArcGraph() override = default;

    void AddEdge(int from, int to) override;

    [[nodiscard]] int VerticesCount() const override;

    [[nodiscard]] std::vector<int> GetNextVertices(int vertex) const override;
    [[nodiscard]] std::vector<int> GetPrevVertices(int vertex) const override;

 private:
    std::vector<std::pair<int, int>> graph;
    int verticesCount;
};
