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
    void print() override;
    Node **al;  //adjacency list
    int v_num;
    void addEdge(int start, int end, int weight);
    int get_edge_weight(int start, int end) override;
    int get_vertices_num() override;
    int get_min_key(int vertex) override;
    int* get_priority_queue_based_on_key(int start_vertex) override;
};


#endif