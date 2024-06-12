#include "Algo.h"
#include "Graph.h"

#include <iostream>
#include <climits>

using namespace std;

Graph Algo::Prim_MST(GraphRep &g, int start_vertex, bool print_mst)
{
    // cout << g.get_edge_weight(0, 1) << endl;
    // cout << g.get_edge_weight(0, 2) << endl;
    // cout << g.get_edge_weight(1, 2) << endl;
    // cout << g.get_edge_weight(1, 3) << endl;
    // cout << g.get_edge_weight(2, 3) << endl;

    int v_num = g.get_vertices_num();
    int e_num = v_num - 1;

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
            // cout << "adj_arr[" << i << "] = " << adj_arr[i] << endl;
        }

        for (int i = 0; i < v_num; i++)
        {
            if (adj_arr[i] <= 0 || i == u)
                continue;

            if (!in_mst[i] && adj_arr[i] < key[i])
            {
                key[i] = adj_arr[i];
                parent[i] = u;

                // cout << "u = " << u << " i = " << i << " key[i] = " << key[i] << endl;
            }
        }
    }

    if (print_mst)
    {
        int sum = 0;
        for (int i = 1; i < v_num; i++)
        {
            int weight = g.get_edge_weight(parent[i], i);
            cout << parent[i] << " - " << i << " \t" << weight << endl;
            sum += weight;
        }
        cout << "sum = " << sum << endl;

        return Graph(Matrix(), List());
    }

    List l = List(v_num);
    Matrix m = Matrix(nullptr, v_num, e_num = 0);

    for (int i = 1; i < v_num; i++)
    {
        int weight = g.get_edge_weight(parent[i], i);
        l.add_egde(parent[i], i, weight);
        m.add_egde(parent[i], i, weight);
    }

    return Graph(m, l);
}

int Algo::min_key(int *key, bool *mst_set, int v_num)
{
    int min = INT_MAX;
    int min_index = 0;

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

void Algo::Dijkstra(GraphRep &g, int start_vertex, int end_vertex)
{
    int v_num = g.get_vertices_num();

    int dist[v_num];
    bool spt_set[v_num];

    for (int i = 0; i < v_num; i++)
    {
        dist[i] = INT_MAX;
        spt_set[i] = false;
    }

    dist[start_vertex] = 0;

    for (int i = 0; i < v_num; i++)
    {
        int u = min_key(dist, spt_set, v_num);

        spt_set[u] = true;

        int adj_arr[v_num];
        for (int i = 0; i < v_num; i++)
        {
            adj_arr[i] = g.get_edge_weight(u, i);
        }

        for (int i = 0; i < v_num; i++)
        {
            if (adj_arr[i] <= 0 || i == u)
                continue;

            if (!spt_set[i] && dist[u] != INT_MAX && dist[u] + adj_arr[i] < dist[i])
            {
                dist[i] = dist[u] + adj_arr[i];
            }
        }
    }

    for (int i = 0; i < v_num; i++)
    {
        cout << i << " - " << dist[i] << endl;
    }
}