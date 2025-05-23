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

    // Para usar matriz de adjacencia
    //   GraphMatrix graph_matrix(n);
    //  Graph graph(n);

    // for (int i = 0; i < n; ++i) {
    //     double x, y;
    //     std::cin >> x >> y;
    //     graph_matrix.addCoordinates(i, x, y);
    //     graph.addCoordinates(i, x, y);
    // }

    // for (int i = 0; i < m; ++i) {
    //     int u, v;
    //     double weight;
    //     std::cin >> u >> v >> weight;
    //     graph_matrix.addEdge(u, v, weight);
    //     graph.addEdge(u, v, weight);
    // }

    // for (int i = 0; i < k; ++i) {
    //     int u, v;
    //     std::cin >> u >> v;
    //     graph_matrix.addPortal(u, v);
    //     graph.addPortal(u, v);
    // }

    // double max_energy;
    // int max_portals;
    // std::cin >> max_energy >> max_portals;

    // bool result_dijkstra_list = dijkstra(graph, max_energy, max_portals);
    // bool result_astar_list = a_star(graph, max_energy, max_portals);

    // bool result_dijkstra_matrix = dijkstra(graph_matrix, max_energy, max_portals);
    // bool result_astar_matrix = a_star(graph_matrix, max_energy, max_portals);

    // std::cout << result_dijkstra_list << " " << result_astar_list << std::endl;
    // std::cout << result_dijkstra_matrix << " " << result_astar_matrix << std::endl;

    // return 0;
}
