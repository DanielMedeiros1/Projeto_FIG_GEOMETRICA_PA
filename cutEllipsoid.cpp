#include "CutEllipsoid.h"


CutEllipsoid::CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
    this->xcenter = xcenter; this->ycenter = ycenter; this->zcenter = zcenter;
    this->rx = rx; this->ry = ry; this->rz = rz;
    
}

void CutEllipsoid::draw(Sculptor &t) {
     
    for (int i = xcenter - rx; i <= xcenter + rx; i++){
        for (int j = ycenter - ry; j <= ycenter + ry; j++){
            for (int k = zcenter - rz; k <= zcenter + rz; k++){
             
                float dx = (float)(i - xcenter) / rx; 
                float dy = (float)(j - ycenter) / ry; 
                float dz = (float)(k - zcenter) / rz; 

                if(dx * dx + dy * dy + dz * dz <= 1.0) {
                    t.cutVoxel(i, j, k);
                }
            }
        }
    }
}