#include "Algo.h"

#include <iostream>

const int INF = 2147483647;

using namespace std;

void Algo::Prim_MST(GraphRep& g, int start_vertex)
{
    int v_num = g.get_vertices_num();

    int *parent = new int[v_num];
    int *key = new int[v_num];
    bool *mst_set = new bool[v_num];

    for (int i = 0; i < v_num; ++i)
        key[i] = INF, mst_set[i] = false;


    key[start_vertex] = 0;
    parent[start_vertex] = -1;

    for (int i = 0; i < v_num - 1; i++) {

        int u = min_key(key, mst_set, v_num);
        mst_set[u] = true;

        for (int j = 0; j < v_num; j++)
        {
            if (g.get_edge_weight(u, j) && mst_set[j] == false && g.get_edge_weight(u, j) < key[j])
            {
                parent[j] = u;
                key[j] = g.get_edge_weight(u, j);
            }
        }
    }

    for (int i = 1; i < v_num; i++)
    {
        cout << parent[i] << " - " << i << " " << g.get_edge_weight(i, parent[i]) << endl;
    }
}

int Algo::min_key(int *key, bool *mst_set, int v_num)
{
    int min = INF;
    int min_index;

    for (int i = 0; i < v_num; i++)
    {
        if (mst_set[i] == false && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }

    return min_index;
}