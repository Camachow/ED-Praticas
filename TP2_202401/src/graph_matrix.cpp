#include "../include/graph_matrix.h"
#include <cmath>
#include <limits>

MatrixGraph::MatrixGraph(int n)
    : adj_matrix(n, MyVector<double>(n, std::numeric_limits<double>::infinity())),
      portal_matrix(n, MyVector<bool>(n, false)),
      coordinates(n, {0.0, 0.0}),
      n(n) {}

MatrixGraph::~MatrixGraph()
{
    // Memory deallocation is handled by MyVector's destructor
}

void MatrixGraph::addEdge(int u, int v, double weight)
{
    adj_matrix[u][v] = weight;
}

void MatrixGraph::addPortal(int u, int v)
{
    portal_matrix[u][v] = true;
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

double MatrixGraph::getEdgeWeight(int u, int v) const
{
    return adj_matrix[u][v];
}

bool MatrixGraph::hasPortal(int u, int v) const
{
    return portal_matrix[u][v];
}

int MatrixGraph::size() const
{
    return n;
}
