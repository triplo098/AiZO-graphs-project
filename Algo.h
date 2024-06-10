#ifndef ALGO_H
#define ALGO_H

#include "GraphRep.h"
#include "Graph.h"

class Algo
{
public:
    Graph static Prim_MST(GraphRep& g, int start_vertex, bool print_mst = true);
    int static min_key(int key[], bool in_mst[], int v_num);
    void static Dijkstra(GraphRep& g, int start_vertex);
};

#endif