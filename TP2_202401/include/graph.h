// include/graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include "my_vector.h"
#include "edge.h"
#include "portal.h"

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
    int size() const; // Adicionando método size()

private:
    MyVector<MyVector<Edge>> adjList;
    MyVector<MyVector<Portal>> portals;
    MyVector<std::pair<double, double>> coordinates;
};

#endif // GRAPH_H
