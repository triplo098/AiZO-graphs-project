#include "Graph.h"
#include "Algo.h"

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

void Graph::print()
{
    this->matrix.print();
    this->list.print();
}

Graph::Graph(int v_num, int density)
{   
    
    srand (time(NULL));

    this->matrix = Matrix(nullptr, v_num, 0);

    // this->matrix.print();

    int e_num = (v_num * (v_num - 1) / 2) * density / 100;

    if(e_num < v_num - 1)
    {
        cout << "Za mała gęstość grafu" << endl;
        return;
    }
    else if (density > 100)
    {
        cout << "Za duża gęstość grafu" << endl;
        return;
    }

    this->list = List(v_num);

    // Tworzenie grafu pełnego
    for(int i = 0; i < v_num; i++)
    {
        for(int j = i + 1; j < v_num; j++)
        {
            list.add_egde(i, j, (rand() % 100) + 1);
        }
    }

    // list.print();   

    //Uzyskanie MST
    Graph g = Algo::Prim_MST(list, 0, false);
    // g.list.print();
    // g.matrix.print();
    // g.print();

    // cout << g.list.e_num << endl;
    // cout << e_num << endl;
    while (g.list.e_num < e_num)
    {
        
        int start = rand() % v_num;
        int end = rand() % v_num;
        int weight = (rand() % 100) + 1;

        // int start = 0;
        // int end = 2;
        // int weight = 87;

        if (start == end)
            continue;
        

        g.list.add_egde(start, end, weight);
        // g.list.print();
        // printf("List e_num: %d\n", g.list.e_num);
        // if(g.matrix.e_num >=  g.list.e_num)
        //     continue;
        g.matrix.add_egde(start, end, weight);
        // g.matrix.print();
        // printf("Matrix e_num: %d\n", g.matrix.e_num);
    }

    this->matrix = g.matrix;
    this->list = g.list;

}
