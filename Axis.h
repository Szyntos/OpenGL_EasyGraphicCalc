
#ifndef UNTITLED_AXIS_H
#define UNTITLED_AXIS_H


#include "Point.h"
#include "Cube.h"
#include "Color.h"
#include <iostream>

class Axis {
public:
    float limit;
    float size, cornerOffset;
    Cube corner, xAxis, yAxis, zAxis;
    double xOff = 0;
    double yOff = 0;
    double zOff = 0;
    int n = 10;
    Axis(){
        limit = 1;
        size = 1;
        cornerOffset = 0.01;
        setOffset(0, 0, 0);
        constructor();
    }
    Axis(float lim, float nsize, float noffset){
        size = nsize;
        limit = lim;
        cornerOffset = noffset;
        setOffset(0, 0, 0);
        constructor();
    }
    void setOffset(double x, double y, double z){

        xOff = x;
        yOff = y;
        zOff = z;
//        constructor();
    }

    void constructor(){
        Point cornerPoint(- size, - size, 0);
        Point xPoint(- size, - size, limit);
        Point yPoint(0, - size, 0);
        Point zPoint(- size, 0, 0);
        corner = Cube(cornerPoint, size, size, size, Color(0, 0, 0));
        xAxis = Cube(yPoint, limit, size, size,Color(1, 0, 0));
        yAxis = Cube(zPoint, size, limit, size, Color(0, 1, 0));
        zAxis = Cube(xPoint, size, size, limit,Color(0, 0, 1));
    }
    void draw();

    void drawText();
};


#endif //UNTITLED_AXIS_H
