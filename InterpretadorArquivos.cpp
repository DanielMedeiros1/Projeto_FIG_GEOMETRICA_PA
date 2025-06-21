#include "InterpretadorArquivos.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "putVoxel.h"
#include "cutVoxel.h"
#include "putBox.h"
#include "cutBox.h"
#include "putSphere.h"
#include "cutSphere.h"
#include "putEllipsoid.h"
#include "cutEllipsoid.h"

InterpretadorArquivos::InterpretadorArquivos(){

}

std::vector<FiguraGeometrica*> InterpretadorArquivos::parse(std::string filename){
    std::vector<FiguraGeometrica*> figs;
    std::ifstream fin;
    std::stringstream ss;
    std::string linha, token;  

    fin.open(filename.c_str());
    if(!fin.is_open()){
        std::cout << "Erro na abertura do arquivo";
        exit(0);
    }

    while(fin.good()){
        getline(fin, linha);
        ss.clear();
        ss.str(linha);
        ss >> token;
    

        if (ss.good()){
            if(token.compare("dim") == 0){
                ss >> dimX >> dimY >> dimZ;
            }
            else if (token.compare("putVoxel") == 0){
                int x, y, z;
                ss >> x >> y >> z >> r >> g >> b >> a;
                figs.push_back(new PutVoxel(x, y, z, r, g, b, a));   
            }
            else if (token.compare("cutVoxel") == 0){
                int x, y, z;
                ss >> x >> y >> z;
                figs.push_back(new CutVoxel(x, y, z));   
            }
            else if (token.compare("putBox") == 0){
                int x0, x1, y0, y1, z0, z1;
                ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                figs.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));   
            }
            else if (token.compare("cutBox") == 0){
                int x0, x1, y0, y1, z0, z1;
                ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                figs.push_back(new CutBox(x0, x1, y0, y1, z0, z1));   
            }
            else if (token.compare("putSphere") == 0){
                int xcenter, ycenter, zcenter, radius;
                ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
                figs.push_back(new PutSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));   
            }
            else if (token.compare("cutSphere") == 0){
                int xcenter, ycenter, zcenter, radius;
                ss >> xcenter >> ycenter >> zcenter >> radius;
                figs.push_back(new CutSphere(xcenter, ycenter, zcenter, radius));   
            }
            else if (token.compare("putEllipsoid") == 0){
                int xcenter, ycenter, zcenter, rx, ry, rz;
                ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
                figs.push_back(new PutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a));   
            }
            else if (token.compare("cutEllipsoid") == 0){
                int xcenter, ycenter, zcenter, rx, ry, rz;
                ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz; 
                figs.push_back(new CutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));   
            }
        }
    }
    return(figs);
}

int InterpretadorArquivos::getDimX(){
    return dimX;
}

int InterpretadorArquivos::getDimY(){
    return dimY;
}

int InterpretadorArquivos::getDimZ(){
    return dimZ;
}

