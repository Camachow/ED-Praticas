#ifndef ASTAR_IMPL_H
#define ASTAR_IMPL_H

#include "astar.h"

template <typename GraphType>
bool a_star(const GraphType &graph, double max_energy, int max_portals)
{
    int n = graph.size();
    MyVector<MyVector<double>> dist(n, MyVector<double>(max_portals + 1, std::numeric_limits<double>::infinity()));
    dist[0][0] = 0.0;

    PriorityQueue<State> pq;
    pq.push(State(0, 0, 0.0, graph.euclideanDistance(0, n - 1)));

    auto heuristic = [&](int u)
    {
        return graph.euclideanDistance(u, n - 1);
    };

    while (!pq.empty())
    {
        State current = pq.top();
        pq.pop();

        int u = current.vertex;
        int portals_used = current.portals_used;
        double current_dist = current.distance;

        if (u == n - 1 && current_dist <= max_energy)
        {
            return true;
        }

        const auto &neighbors = graph.getAdjList(u);
        for (int i = 0; i < neighbors.size(); ++i)
        {
            int v = neighbors[i].to;
            double weight = neighbors[i].weight;
            double new_cost = current_dist + weight;
            if (new_cost < dist[v][portals_used])
            {
                dist[v][portals_used] = new_cost;
                pq.push(State(v, portals_used, new_cost, new_cost + heuristic(v)));
            }
        }

        if (portals_used < max_portals)
        {
            const auto &portals = graph.getPortals(u);
            for (int i = 0; i < portals.size(); ++i)
            {
                int v = portals[i].to;
                if (current_dist < dist[v][portals_used + 1])
                {
                    dist[v][portals_used + 1] = current_dist;
                    pq.push(State(v, portals_used + 1, current_dist, current_dist + heuristic(v)));
                }
            }
        }
    }

    return false;
}

#endif // ASTAR_IMPL_H
