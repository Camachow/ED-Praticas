// src/dijkstra.cpp
#include "dijkstra.h"
#include <limits>

bool dijkstra(const Graph &graph, double s, int q)
{
    int n = graph.size();
    MyVector<MyVector<double>> dist(n, MyVector<double>(q + 1, std::numeric_limits<double>::infinity()));
    dist[0][0] = 0.0;

    PriorityQueue<State> pq;
    pq.push(State(0.0, 0.0, 0, 0));

    while (!pq.empty())
    {
        State current = pq.top();
        pq.pop();

        int u = current.vertex;
        double cost = current.cost;
        int portals_used = current.portals_used;

        if (u == n - 1 && cost <= s)
        {
            return true;
        }

        if (cost > dist[u][portals_used])
            continue;

        for (size_t i = 0; i < graph.getAdjList(u).size(); ++i)
        {
            Edge edge = graph.getAdjList(u)[i];
            int v = edge.to;
            double new_cost = cost + edge.weight;
            if (new_cost < dist[v][portals_used])
            {
                dist[v][portals_used] = new_cost;
                pq.push(State(new_cost, new_cost, v, portals_used));
            }
        }

        if (portals_used < q)
        {
            for (size_t i = 0; i < graph.getPortals(u).size(); ++i)
            {
                Portal portal = graph.getPortals(u)[i];
                int v = portal.to;
                if (cost < dist[v][portals_used + 1])
                {
                    dist[v][portals_used + 1] = cost;
                    pq.push(State(cost, cost, v, portals_used + 1));
                }
            }
        }
    }

    return false;
}
