#ifndef UNTITLED_POINT_H
#define UNTITLED_POINT_H


#include "Color.h"

class Point {
//    Reprezentacja punktu
public:
    float x, y, z;
    float size;
    Color clr;

    Point(){
        x = 0;
        y = 0;
        z = 0;
        size = 0.04;
        clr = Color(0.3, 0.3, 0.3);
    }

    Point(float nx, float ny, float nz){
        x = nx;
        y = ny;
        z = nz;
        size = 0.04;
        clr = Color(0.3, 0.3, 0.3);
    }
    Point(float nx, float ny, float nz, float nsize){
        x = nx;
        y = ny;
        z = nz;
        size = nsize;
        clr = Color(0.3, 0.3, 0.3);
    }
    Point(float nx, float ny, float nz, Color nclr){
        x = nx;
        y = ny;
        z = nz;
        size = 0.04;
        clr = nclr;
    }

    void draw();
};


#endif //UNTITLED_POINT_H
