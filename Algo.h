#ifndef ALGO_H
#define ALGO_H

#include "GraphRep.h"

class Algo
{
public:
    void static Prim_MST(GraphRep& g, int start_vertex);
    int static min_key(int key[], bool in_mst[], int v_num);
};

#endif