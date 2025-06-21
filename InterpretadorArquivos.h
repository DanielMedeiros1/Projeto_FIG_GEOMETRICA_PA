#ifndef INTERPRETADORARQUIVOS_H
#define INTERPRETADORARQUIVOS_H
#include <vector>
#include <string>
#include "FiguraGeometrica.h"
#include "Sculptor.h"


class InterpretadorArquivos{
    
    int dimX, dimY, dimZ;
    float r, g, b, a;

public:
    InterpretadorArquivos();
    std::vector<FiguraGeometrica*> parse(std::string filename);
    int getDimX();
    int getDimY();
    int getDimZ();
};

#endif