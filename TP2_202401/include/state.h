// include/state.h
#ifndef STATE_H
#define STATE_H

struct State
{
    double cost;
    double heuristic_cost;
    int vertex;
    int portals_used;

    State(double c = 0, double hc = 0, int v = 0, int pu = 0)
        : cost(c), heuristic_cost(hc), vertex(v), portals_used(pu) {}

    bool operator<(const State &other) const
    {
        return heuristic_cost > other.heuristic_cost; // menor custo tem maior prioridade
    }
};

#endif // STATE_H
