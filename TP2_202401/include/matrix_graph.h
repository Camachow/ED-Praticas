// include/matrix_graph.h
#ifndef MATRIX_GRAPH_H
#define MATRIX_GRAPH_H

#include "edge.h"
#include "portal.h"
#include <vector>
#include <cmath>
#include <limits>

class MatrixGraph
{
public:
    MatrixGraph(int n);
    void addEdge(int u, int v, double weight);
    void addPortal(int u, int v);
    void addCoordinates(int index, double x, double y);
    double euclideanDistance(int u, int v) const;
    const std::vector<Edge> &getAdjList(int u) const;
    const std::vector<Portal> &getPortals(int u) const;
    int size() const; // Adicionando método size()

private:
    std::vector<std::vector<Edge>> adjMatrix;
    std::vector<std::vector<Portal>> portalMatrix;
    std::vector<std::pair<double, double>> coordinates;
};

#endif // MATRIX_GRAPH_H
