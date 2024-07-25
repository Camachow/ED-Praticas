#ifndef STATE_H
#define STATE_H

struct State
{
    int vertex;
    int portals_used;
    double distance;
    double cost; // Adicionado para o custo do A*

    State() : vertex(0), portals_used(0), distance(0.0), cost(0.0) {} // Construtor padrão

    State(int v, int p, double d) : vertex(v), portals_used(p), distance(d), cost(d) {} // Construtor de 3 argumentos

    State(int v, int p, double d, double c) : vertex(v), portals_used(p), distance(d), cost(c) {} // Construtor de 4 argumentos

    bool operator>(const State &other) const
    {
        return cost > other.cost;
    }

    bool operator<(const State &other) const
    {
        return cost < other.cost;
    }
};

#endif // STATE_H
