#ifndef GRAPHREP_H
#define GRAPHREP_H

#include <iostream>

class GraphRep {
    public:
        virtual void print() {
            std::cout << "GraphRep print" << std::endl;
        }; 
        virtual int get_edge_weight(int start, int end) = 0;
        virtual int get_vertices_num() = 0;
};

#endif