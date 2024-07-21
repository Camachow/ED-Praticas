// src/main.cpp
#include <iostream>
#include "graph.h"
#include "dijkstra.h"
#include "astar.h"

int main()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    Graph graph(n);

    for (int i = 0; i < n; ++i)
    {
        double x, y;
        std::cin >> x >> y;
        graph.addCoordinates(i, x, y);
    }

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        graph.addEdge(u, v, graph.euclideanDistance(u, v));
    }

    for (int i = 0; i < k; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        graph.addPortal(u, v);
    }

    double s;
    int q;
    std::cin >> s >> q;

    if (dijkstra(graph, s, q))
    {
        std::cout << "1 ";
    }
    else
    {
        std::cout << "0 ";
    }

    if (a_star(graph, s, q))
    {
        std::cout << "1" << std::endl;
    }
    else
    {
        std::cout << "0" << std::endl;
    }

    return 0;
}
