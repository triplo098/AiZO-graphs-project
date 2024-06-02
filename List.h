#include "GraphRep.h"

#ifndef LIST_H
#define LIST_H

struct Node
{
    Node(int v, int w) : vertex(v), weight(w), next(nullptr) {}

    Node *next;
    int vertex;
    int weight;
};


class List : public GraphRep
{
public:
    List();
    List(int v_num);
    void print();
    Node **al;  //adjacency list
    int v_num;
    void addEdge(int start, int end, int weight);
};


#endif