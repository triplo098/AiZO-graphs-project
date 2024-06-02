#include "Graph.h"
#include <iostream>

using namespace std;

Graph::Graph(Matrix m, List l)
{
    this->matrix = m;
    this->list = l;
}

Graph::Graph()
{
    
}

Graph::~Graph()
{
}

void Graph::print() {
    this->matrix.print();
    this->list.print();
}

