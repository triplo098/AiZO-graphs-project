#ifndef FILEREADER_H
#define FILEREADER_H
#include <iostream>

#include "Graph.h"

class FileReader{
    
    public:
        Graph readFile(std::string fileName); 

};


#endif