//
// Created by Szymon on 21.06.2023.
//

#ifndef UNTITLED_CUBE_H
#define UNTITLED_CUBE_H


#include "Point.h"

class Cube {
public:
    Point origin;
    float width, height, depth;
    Color clr;

    Cube(){
        width = 1;
        height = 1;
        depth = 1;
        clr = Color(0.3, 0.3, 0.3);
    }

    Cube(Point o, float w, float h, float d){
        width = w;
        height = h;
        depth = d;
        origin = o;
        clr = Color(0.3, 0.3, 0.3);
    }
    Cube(Point o, float w, float h, float d, Color nclr){
        width = w;
        height = h;
        depth = d;
        origin = o;
        clr = nclr;
    }
    void draw();
};


#endif //UNTITLED_CUBE_H
