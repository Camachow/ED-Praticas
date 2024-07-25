#ifndef ASTAR_H
#define ASTAR_H

#include "graph.h"
#include "matrix_graph.h"
#include "priority_queue.h"
#include "state.h"
#include <limits>
#include <cmath>

template <typename GraphType>
bool a_star(const GraphType &graph, double max_energy, int max_portals);

#include "astar_impl.h"
#endif // ASTAR_H
