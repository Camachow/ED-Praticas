// src/main.cpp
#include <iostream>
#include "graph.h"
#include "dijkstra.h"
#include "astar.h"
#include "graph_matrix.h"

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

    // Usando Grafo com Matriz
    // MatrixGraph graph(5);
    // graph.addEdge(0, 1, 10);
    // graph.addEdge(1, 2, 5);
    // graph.addEdge(2, 3, 2);
    // graph.addEdge(3, 4, 1);
    // graph.addPortal(0, 2);
    // graph.addPortal(2, 4);

    // double max_energy = 15.0;
    // int max_portals = 1;

    // bool can_escape = dijkstra(graph, max_energy, max_portals);
    // std::cout << (can_escape ? "Possible to escape" : "Not possible to escape") << std::endl;

    return 0;
}
