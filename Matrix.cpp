#include "Matrix.h"
#include <iostream>
#include <climits>

using namespace std;

Matrix::Matrix()
{
    this->v_num = 0;
    this->e_num = 0;
    this->m = nullptr;
}

Matrix::Matrix(List l)
{
    this->v_num = l.get_vertices_num();
    this->e_num = 0;
    this->m = nullptr;


    for (int i = 0; i < this->v_num; i++)
    {
        Node *tmp = l.al[i];
        while (tmp != nullptr)
        {
            this->add_egde(i, tmp->vertex, tmp->weight);
            tmp = tmp->next;
        }
        if (this->e_num == l.e_num)
        {
            break;
        }
    }
}

Matrix::Matrix(int **m, int v_num, int e_num)
{
    this->m = m;
    this->v_num = v_num;
    this->e_num = e_num;
}

void Matrix::add_egde(int start, int end, int weight)
{
    if (this->e_num == 0 || this->m == nullptr)
    {
        this->m = new int *[this->v_num];
        this->e_num = 1;
        for (int i = 0; i < this->v_num; ++i)
        {
            this->m[i] = new int[this->e_num]{0};
        }

        this->m[start][0] = weight;
        this->m[end][0] = -weight;

        // cout << "Edge added 2" << endl;
        return;
    }

    if (start == end) {
        return;
    }

    if (this->get_edge_weight(start, end) != 0)
    {
        return;
    }

    this->e_num++;

    int **matrix = new int *[v_num];
    for (int i = 0; i < v_num; i++)
    {
        matrix[i] = this->m[i];
    }

    matrix[start][e_num - 1] = weight;
    matrix[end][e_num - 1] = -weight;

    this->m = matrix;

    // cout << "Edge added to matrix" << endl;
}

int Matrix::get_edge_weight(int start, int end)
{

    if (start == end)
        return 0;

    for (int j = 0; j < e_num; ++j)
    {

        int v1 = abs(this->m[start][j]); // value 1
        int v2 = abs(this->m[end][j]);   // value 2

        if (v1 == v2 && v1 != 0)
        {
            return v1;
        }
    }
    return 0; // krawędź nie istnieje
}

int *Matrix::get_priority_queue_based_on_key(int start_vertex)
{

    int *arr = new int[this->v_num];
    for (int i = 0; i < this->v_num; i++)
    {
        arr[i] = i;
    }
    int *key_array = new int[this->v_num];
    for (int i = 0; i < this->v_num; i++)
    {
        key_array[i] = get_min_key(i);
    }
    key_array[start_vertex] = 0;

    int i, j;
    bool swapped;
    for (i = 0; i < this->v_num - 1; i++)
    {
        swapped = false;
        for (j = 0; j < this->v_num - i - 1; j++)
        {
            if (key_array[j] > key_array[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    return arr;
}

int Matrix::get_min_key(int vertex)
{
    int min = INT_MAX;
    for (int i = 0; i < this->v_num; i++)
    {

        int v1 = abs(this->m[vertex][i]);

        if (v1 < min && v1 != 0)
        {
            min = v1;
        }
    }
    return min;
}

int Matrix::get_vertices_num()
{
    return this->v_num;
}

void Matrix::print()
{
    cout << "Matrix: " << endl;

    for (int i = 0; i < this->v_num; i++)
    {

        for (int j = 0; j < this->e_num; j++)
        {
            printf("%4d ", this->m[i][j]);
        }
        cout << endl;
    }
}