// src/main.cpp
#include <iostream>
#include "graph.h"
#include "dijkstra.h"
#include "astar.h"
#include "matrix_graph.h"

int main()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    Graph listGraph(n);
    MatrixGraph matrixGraph(n);

    for (int i = 0; i < n; ++i)
    {
        double x, y;
        std::cin >> x >> y;
        listGraph.addCoordinates(i, x, y);
        matrixGraph.addCoordinates(i, x, y);
    }

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        listGraph.addEdge(u, v, listGraph.euclideanDistance(u, v));
        matrixGraph.addEdge(u, v, matrixGraph.euclideanDistance(u, v));
    }

    for (int i = 0; i < k; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        listGraph.addPortal(u, v);
        matrixGraph.addPortal(u, v);
    }

    double s;
    int q;
    std::cin >> s >> q;

    // Using listGraph with Dijkstra
    if (dijkstra(listGraph, s, q))
    {
        std::cout << "1 ";
    }
    else
    {
        std::cout << "0 ";
    }

    // Using listGraph with A*
    if (a_star(listGraph, s, q))
    {
        std::cout << "1 ";
    }
    else
    {
        std::cout << "0 ";
    }

    // Using matrixGraph with Dijkstra
    if (dijkstra(matrixGraph, s, q))
    {
        std::cout << "1 ";
    }
    else
    {
        std::cout << "0 ";
    }

    // Using matrixGraph with A*
    if (a_star(matrixGraph, s, q))
    {
        std::cout << "1" << std::endl;
    }
    else
    {
        std::cout << "0" << std::endl;
    }

    return 0;
}
