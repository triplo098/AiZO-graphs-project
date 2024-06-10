#include "List.h"
#include <iostream>
#include <climits>

using namespace std;

List::List()
{
    this->v_num = 0;
    this->al = nullptr;
}

List::List(int v_num) : v_num(v_num)
{
    this->v_num = v_num;
    this->e_num = 0;
    
    this->al = new Node *[v_num];
    for (int i = 0; i < v_num; ++i)
    {
        this->al[i] = nullptr;
    }
}

int List::get_edge_weight(int start, int end)
{
    Node *tmp = this->al[start];
    while (tmp != nullptr)
    {
        if (tmp->vertex == end)
        {
            return tmp->weight;
        }
        tmp = tmp->next;
    }
    return 0; // edge does not exist
}

int List::get_vertices_num()
{
    return this->v_num;
}

void List::add_egde(int start, int end, int weight)
{   

    if (start == end)
        return;
    this->e_num++;
    if(this->get_edge_weight(start, end) != 0)
        return;
    

    if (this->al[start] == nullptr)
    {
        this->al[start] = new Node(end, weight);
    }
    else
    {
        Node *tmp = this->al[start];
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = new Node(end, weight);
    }

    // dodanie krawedzi dla nieskierowanego grafu
    if (this->al[end] == nullptr)
    {
        this->al[end] = new Node(start, -weight);
    }
    else
    {
        Node *tmp = this->al[end];
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = new Node(start, -weight);
    }


}

int *List::get_priority_queue_based_on_key(int start_vertex)
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
                swap(key_array[j], key_array[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    return arr;
}

int List::get_min_key(int vertex)
{
    Node *tmp = this->al[vertex];
    int min = INT_MAX;
    while (tmp != nullptr)
    {
        if (tmp->weight < min)
        {
            min = tmp->weight;
        }
        tmp = tmp->next;
    }
    return min;
}

void List::print()
{

    cout << "List: " << endl;
    for (int i = 0; i < this->v_num; i++)
    {
        cout << i << ": ";
        Node *tmp = al[i];
        while (tmp != nullptr)
        {
            cout << tmp->vertex << " (" << tmp->weight << "), ";
            tmp = tmp->next;
        }
        cout << endl;
    }
}