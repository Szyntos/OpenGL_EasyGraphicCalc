#include "Axis.h"
#include "Cube.h"
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>




void Axis::draw() {
    Cube nAxis;
    corner.draw();
    xAxis.draw();

    yAxis.draw();
    zAxis.draw();
    float scale = 3;
    for (int i = 0; i < n; ++i) {
        nAxis = Cube(Point(xAxis.origin.x, xAxis.origin.y + (i+1) * limit/n, xAxis.origin.z), limit, xAxis.height/scale, xAxis.depth/scale);
        nAxis.draw();
        nAxis = Cube(Point(xAxis.origin.x, xAxis.origin.y, xAxis.origin.z + (i+1) * limit/n), limit, xAxis.height/scale, xAxis.depth/scale);
        nAxis.draw();
        nAxis = Cube(Point(yAxis.origin.x + (i+1) * limit/n, yAxis.origin.y, yAxis.origin.z), yAxis.width/scale, limit, yAxis.depth/scale);
        nAxis.draw();
        nAxis = Cube(Point(yAxis.origin.x, yAxis.origin.y , yAxis.origin.z+ (i+1) * limit/n), yAxis.width/scale, limit, yAxis.depth/scale);
        nAxis.draw();
        nAxis = Cube(Point(zAxis.origin.x+ (i+1) * limit/n, zAxis.origin.y , zAxis.origin.z), zAxis.width/scale, zAxis.height/scale, limit);
        nAxis.draw();
        nAxis = Cube(Point(zAxis.origin.x, zAxis.origin.y+ (i+1) * limit/n , zAxis.origin.z), zAxis.width/scale, zAxis.height/scale, limit);
        nAxis.draw();
    }
}

void Axis::drawText() {
    std::ostringstream streamObj;
    streamObj << std::setprecision(3);

    Point origin = Point(xOff, yOff, zOff);
    streamObj <<"(" << origin.x << ", " << origin.y << ", " << origin.z << ")";
    unsigned char s[20];
    glRasterPos3f(0, 0, 0);
    glColor3f(0, 0, 0);
    strcpy( (char*) s, streamObj.str().c_str() );
    glutBitmapString(GLUT_BITMAP_HELVETICA_10, ( s));
    streamObj.str("");
    streamObj.clear();

    origin = Point(xOff+limit, yOff, zOff);
    streamObj <<"(" << origin.x << ", " << origin.y << ", " << origin.z << ")";
    glRasterPos3f(limit, 0, 0);
    glColor3f(0, 0, 0);
    strcpy( (char*) s, streamObj.str().c_str() );
    glutBitmapString(GLUT_BITMAP_HELVETICA_10, ( s));
    streamObj.str("");
    streamObj.clear();

    origin = Point(xOff, yOff+limit, zOff);
    streamObj <<"(" << origin.x << ", " << origin.y << ", " << origin.z << ")";
    glRasterPos3f(0, limit, 0);
    glColor3f(0, 0, 0);
    strcpy( (char*) s, streamObj.str().c_str() );
    glutBitmapString(GLUT_BITMAP_HELVETICA_10, ( s));
    origin = Point(xOff, yOff, zOff-limit);
    streamObj.str("");
    streamObj.clear();

    streamObj <<"(" << origin.x << ", " << origin.y << ", " << origin.z << ")";
    glRasterPos3f(0, 0, limit);
    glColor3f(0, 0, 0);
    strcpy( (char*) s, streamObj.str().c_str() );
    glutBitmapString(GLUT_BITMAP_HELVETICA_10, ( s));
    streamObj.str("");
    streamObj.clear();


}
