#ifndef MATRIX_GRAPH_H
#define MATRIX_GRAPH_H

#include "my_vector.h"

class MatrixGraph
{
public:
    MatrixGraph(int n);

    void addEdge(int u, int v, double weight);
    void addPortal(int u, int v);
    void addCoordinates(int index, double x, double y);
    double euclideanDistance(int u, int v) const;
    double getEdgeWeight(int u, int v) const;
    bool hasPortal(int u, int v) const;
    int size() const;

    ~MatrixGraph();

private:
    MyVector<MyVector<double>> adj_matrix;
    MyVector<MyVector<bool>> portal_matrix;
    MyVector<std::pair<double, double>> coordinates;
    int n;
};

#endif // MATRIX_GRAPH_H
