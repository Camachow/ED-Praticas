// src/matrix_graph.cpp
#include "matrix_graph.h"

MatrixGraph::MatrixGraph(int n) : adjMatrix(n, std::vector<Edge>(n)), portalMatrix(n, std::vector<Portal>(n)), coordinates(n) {}

void MatrixGraph::addEdge(int u, int v, double weight)
{
    adjMatrix[u][v] = {v, weight};
}

void MatrixGraph::addPortal(int u, int v)
{
    portalMatrix[u][v] = {v};
}

void MatrixGraph::addCoordinates(int index, double x, double y)
{
    coordinates[index] = {x, y};
}

double MatrixGraph::euclideanDistance(int u, int v) const
{
    double dx = coordinates[u].first - coordinates[v].first;
    double dy = coordinates[u].second - coordinates[v].second;
    return std::sqrt(dx * dx + dy * dy);
}

const std::vector<Edge> &MatrixGraph::getAdjList(int u) const
{
    return adjMatrix[u];
}

const std::vector<Portal> &MatrixGraph::getPortals(int u) const
{
    return portalMatrix[u];
}

int MatrixGraph::size() const
{
    return adjMatrix.size();
}
