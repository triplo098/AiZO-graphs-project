#include "GraphRep.h"

#ifndef MATRIX_H
#define MATRIX_H

class Matrix : public GraphRep
{
public:
    Matrix();
    Matrix(int **m, int i, int j);
    void print();
    int **m;
    int i;
    int j;
};

#endif