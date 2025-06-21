#include "Sculptor.h"
#include "FiguraGeometrica.h"
#include "InterpretadorArquivos.h"
#include <iostream>
#include <vector>
#include "putVoxel.h"
#include "cutVoxel.h"
#include "putBox.h"
#include "cutBox.h"
#include "putSphere.h"
#include "cutSphere.h"
#include "putEllipsoid.h"
#include "cutEllipsoid.h"

int main(){

    Sculptor *Desenho;

    InterpretadorArquivos parser;

    std::vector<FiguraGeometrica*> figs;

    figs = parser.parse("D:/C++ Visual Studio/Projeto_FIG_GEOMETRICA_PA/Desenho.txt");

    Desenho = new Sculptor(parser.getDimX(), parser.getDimY(), parser.getDimZ());

    for(size_t i = 0; i < figs.size(); i++){
        std::cout << "draw" << std::endl;
        figs[i]-> draw(*Desenho);
    }

    Desenho->writeOFF((char*) "D:/C++ Visual Studio/Projeto_FIG_GEOMETRICA_PA/Cubo_Esfera_Elipse.off");
    
    for(size_t i = 0; i < figs.size(); i++){
        delete figs[i];
    }
    delete Desenho;

    return 0; 

}