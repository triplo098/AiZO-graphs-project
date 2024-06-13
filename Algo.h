#ifndef ALGO_H
#define ALGO_H

#include "GraphRep.h"
#include "Graph.h"

class Algo
{
public:
    Graph static Prim_MST(GraphRep& g, int start_vertex, bool print_mst = true);
    Graph static Kruskal_MST(GraphRep& g, int start_vertex, bool print_mst = true);
    int static min_key(int key[], bool in_mst[], int v_num);
    void static Dijkstra(GraphRep& g, int start_vertex, int end_vertex, bool print_sp = true);
    int static find(int *parent, int i);
    int static min_weight(GraphRep &g, int vertex);
    void static union_set(int u, int v,int *parent, int v_num);
    void static Bellman_Ford(GraphRep& g, int start_vertex, int end_vertex, bool print_sp = true);

};

#endif