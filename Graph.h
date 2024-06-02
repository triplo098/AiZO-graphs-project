#include "Matrix.h"
#include "List.h"

#ifndef GRAPH_H
#define GRAPH_H


class Graph
{

public:
    Graph();
    ~Graph();    
    Graph(Matrix m, List l);
    Matrix matrix;
    List list;
    void print();
};


#endif