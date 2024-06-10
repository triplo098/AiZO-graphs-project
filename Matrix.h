#ifndef MATRIX_H
#define MATRIX_H

#include "GraphRep.h"
#include "List.h"

class Matrix : public GraphRep
{
public:
    Matrix();
    Matrix(List l);
    Matrix(int **m, int v_num, int e_num);

void add_egde(int start, int end, int weight) override;    int get_edge_weight(int start, int end) override; // (1)
    int get_vertices_num() override; // (2)
    void print() override;
    int *get_priority_queue_based_on_key(int start_vertex) override;
    int **m;
    int v_num;
    int e_num;
    int get_min_key(int vertex) override;
};

#endif