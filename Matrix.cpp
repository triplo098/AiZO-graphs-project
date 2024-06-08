#include "Matrix.h"
#include <iostream>
#include <climits>


using namespace std;

Matrix::Matrix() {
    this->v_num = 0;
    this->e_num = 0;
    this->m = nullptr;
}


Matrix::Matrix(int **m, int v_num, int e_num) {
    this->m = m;
    this->v_num = v_num;
    this->e_num = e_num;
}

int Matrix::get_edge_weight(int start, int end) {
    
    if (start == end) {
        return -1;
    }

    for (int j = 0; j < e_num; ++j) {

        int v1 = abs(this->m[start][j]); //value 1
        int v2 = abs(this->m[end][j]);  //value 2

        if (v1 == v2 && v1 != 0) {
            return v1;
        }
    }
    return -1;
}

int *Matrix::get_priority_queue_based_on_key( int start_vertex) {
    
    int *arr = new int[this->v_num];
    for (int i = 0; i < this->v_num; i++) {
        arr[i] = i;
    }
    int* key_array = new int[this->v_num];
    for (int i = 0; i < this->v_num; i++) {
        key_array[i] = get_min_key(i);
    }
    key_array[start_vertex] = 0;

    int i, j;
    bool swapped;
    for (i = 0; i < this->v_num - 1; i++) {
        swapped = false;
        for (j = 0; j < this->v_num - i - 1; j++) {
            if (key_array[j] > key_array[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    return arr;
}

int Matrix::get_min_key(int vertex) {
    int min = INT_MAX;
    for (int i = 0; i < this->v_num; i++) {
        
        int v1 = abs(this->m[vertex][i]);

        if (v1 < min && v1 != 0) {
            min = v1;
        }
    }
    return min;
}


int Matrix::get_vertices_num() {
    return this->v_num;
}

void Matrix::print() {
    cout << "Matrix: " << endl;

    for(int i = 0; i < this->v_num; i++) {
        
        for(int j = 0; j < this->e_num; j++) {
            
            cout << this->m[i][j] << "  ";
        }    
        cout << endl;
    }

}