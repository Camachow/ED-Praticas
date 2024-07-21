// src/graph.cpp
#include "../include/graph.h"
#include <cmath>

Graph::Graph(int n) : adj_list(n), portals(n), coordinates(n, {0.0, 0.0}), n(n) {}

void Graph::addEdge(int u, int v, double weight)
{
    adj_list[u].push_back(Edge(v, weight));
}

void Graph::addPortal(int u, int v)
{
    portals[u].push_back(Portal(v));
}

void Graph::addCoordinates(int index, double x, double y)
{
    coordinates[index] = {x, y};
}

double Graph::euclideanDistance(int u, int v) const
{
    double dx = coordinates[u].first - coordinates[v].first;
    double dy = coordinates[u].second - coordinates[v].second;
    return std::sqrt(dx * dx + dy * dy);
}

const MyVector<Edge> &Graph::getAdjList(int u) const
{
    return adj_list[u];
}

const MyVector<Portal> &Graph::getPortals(int u) const
{
    return portals[u];
}

int Graph::size() const
{
    return n;
}
