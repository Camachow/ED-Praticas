// src/graph.cpp
#include "graph.h"
#include <cmath>

Graph::Graph(int n) : adjList(n), portals(n), coordinates(n) {}

void Graph::addEdge(int u, int v, double weight)
{
    adjList[u].push_back({v, weight});
}

void Graph::addPortal(int u, int v)
{
    portals[u].push_back({v});
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
    return adjList[u];
}

const MyVector<Portal> &Graph::getPortals(int u) const
{
    return portals[u];
}

int Graph::size() const
{
    return adjList.size();
}
