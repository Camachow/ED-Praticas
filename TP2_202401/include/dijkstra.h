#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"
#include "matrix_graph.h"
#include "priority_queue.h"
#include "state.h"
#include <limits>

template <typename GraphType>
bool dijkstra(const GraphType &graph, double max_energy, int max_portals);

#include "dijkstra_impl.h"
#endif // DIJKSTRA_H
