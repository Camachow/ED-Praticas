// include/graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include "my_vector.h"

struct Edge
{
    int to;
    double weight;
    Edge(int t = 0, double w = 0.0) : to(t), weight(w) {}
};

struct Portal
{
    int to;
    Portal(int t = 0) : to(t) {}
};

class Graph
{
public:
    Graph(int n);

    void addEdge(int u, int v, double weight);
    void addPortal(int u, int v);
    void addCoordinates(int index, double x, double y);
    double euclideanDistance(int u, int v) const;
    const MyVector<Edge> &getAdjList(int u) const;
    const MyVector<Portal> &getPortals(int u) const;
    int size() const;

private:
    MyVector<MyVector<Edge>> adj_list;
    MyVector<MyVector<Portal>> portals;
    MyVector<std::pair<double, double>> coordinates;
    int n;
};

#endif // GRAPH_H
