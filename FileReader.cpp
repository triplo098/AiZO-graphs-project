#include "FileReader.h"
#include "Graph.h"

#include <fstream>


Graph FileReader::readFile(std::string fileName) {
    
    Graph g;
 
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cout << "Nie ma takiego pliku" << std::endl;
        return g;
    }

    int e_num, v_num;
    file >> e_num >> v_num;
    
    int** m = new int*[v_num];
    for (int i = 0; i < v_num; i++) {
        m[i] = new int[e_num];
    }

    List l = List(v_num);

    int i = 0;
    while(!file.eof()) {
        
        int start, end, weight;
        file >> start >> end >> weight;

        m[start][i] = weight;
        m[end][i] = -weight;

        l.addEdge(start, end, weight);

        
        i++;
    }

    g = Graph(Matrix(m, e_num, v_num), l);


    return g;
}