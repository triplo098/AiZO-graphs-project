#include "Matrix.h"
#include <iostream>


using namespace std;

Matrix::Matrix() {
    this->i = 0;
    this->j = 0;
    this->m = nullptr;
}

Matrix::Matrix(int **m, int i, int j) {
    this->m = m;
    this->i = i;
    this->j = j;
}

void Matrix::print() {
    cout << "Matrix: " << endl;

    for(int i = 0; i < this->i; i++) {
        
        for(int j = 0; j < this->j; j++) {
            
            cout << this->m[j][i] << "  ";
        }    
        cout << endl;
    }

}