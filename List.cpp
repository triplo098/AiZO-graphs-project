#include "List.h"
#include <iostream>

using namespace std;

List::List()
{
    this->v_num = 0;
    this->al = nullptr;
}

List::List(int v_num) : v_num(v_num)
{
    this->v_num = v_num;
    this->al = new Node *[v_num];
    for (int i = 0; i < v_num; ++i)
    {
        this->al[i] = nullptr;
        // al[i] = new Node(i, 0);
    }
}

void List::addEdge(int start, int end, int weight)
{
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

    //dodanie krawedzi dla nieskierowanego grafu
    if (this->al[end] == nullptr)
    {
        this->al[end] = new Node(start, weight);
    }
    else
    {
        Node *tmp = this->al[end];
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = new Node(start, weight);
    }
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