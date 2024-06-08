#include "Algo.h"

#include <iostream>
#include <climits>

using namespace std;

void Algo::Prim_MST(GraphRep &g, int start_vertex)
{
    // cout << g.get_edge_weight(0, 1) << endl;
    // cout << g.get_edge_weight(0, 2) << endl;
    // cout << g.get_edge_weight(1, 2) << endl;
    // cout << g.get_edge_weight(1, 3) << endl;
    // cout << g.get_edge_weight(2, 3) << endl;

    int v_num = g.get_vertices_num();

    int parent[v_num];
    int key[v_num];
    bool in_mst[v_num];

    for (int i = 0; i < v_num; i++)
    {
        key[i] = INT_MAX;
        in_mst[i] = false;
    }

    key[start_vertex] = 0;
    parent[start_vertex] = -1;

    for (int i = 0; i < v_num; i++)
    {

        int u = min_key(key, in_mst, v_num);

        in_mst[u] = true;

        in_mst[u] = true;

        int adj_arr[v_num];
        for (int i = 0; i < v_num; i++)
        {
            adj_arr[i] = g.get_edge_weight(u, i);
        }

        for (int i = 0; i < v_num; i++)
        {
            if (adj_arr[i] <= 0 || i == u)
                continue;

            if (!in_mst[i] && adj_arr[i] < key[i])
            {
                key[i] = adj_arr[i];
                parent[i] = u;
                
            }
        }
    }

    int sum = 0;
    for (int i = 1; i < v_num; i++)
    {
        int weight = g.get_edge_weight(parent[i], i);
        cout << parent[i] << " - " << i << " \t" << weight << endl;
        sum += weight;
    }
    cout << "sum = " << sum << endl; 
}

int Algo::min_key(int *key, bool *mst_set, int v_num)
{
    int min = INT_MAX;
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