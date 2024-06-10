#include "Matrix.h"
#include "List.h"

#ifndef GRAPH_H
#define GRAPH_H


class Graph
{

public:
    Graph();
    Graph(int v_num, int density);
    ~Graph();    
    Graph(Matrix m, List l);
    Matrix matrix;
    List list;
    void print();
};


#endif