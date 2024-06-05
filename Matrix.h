#ifndef MATRIX_H
#define MATRIX_H

#include "GraphRep.h"

class Matrix : public GraphRep
{
public:
    Matrix();
    Matrix(int **m, int i, int j);

    int get_edge_weight(int start, int end) override; // (1)
    int get_vertices_num() override; // (2)
    void print() override;
    int **m;
    int i;
    int j;
};

#endif