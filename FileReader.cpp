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
    
    List l = List(v_num);
    Matrix m = Matrix(nullptr, v_num, e_num = 0);

    int i = 0;
    while(!file.eof()) {
        
        int start, end, weight;
        file >> start >> end >> weight;

        // m[start][i] = weight;
        // m[end][i]þ = -weight;

        l.add_egde(start, end, weight);
        m.add_egde(start, end, weight);
        i++;
    }

    // g = Graph(Matrix(m, v_num, e_num), l);

    g = Graph(m, l);

    return g;
}