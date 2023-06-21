#include "Cube.h"
#include <GL/glut.h>
#include <GL/glu.h>

void Cube::draw() {
    glBegin(GL_QUADS);
    //front
    glColor3f(clr.r, clr.g, clr.b);
    glVertex3f(origin.x, origin.y + height, origin.z);
    glVertex3f(origin.x, origin.y, origin.z);
    glVertex3f(origin.x + width, origin.y, origin.z);
    glVertex3f(origin.x + width, origin.y  + height, origin.z);
    //back
    glVertex3f(origin.x + width, origin.y  + height, origin.z  - depth);
    glVertex3f(origin.x + width, origin.y, origin.z - depth);
    glVertex3f(origin.x, origin.y, origin.z - depth);
    glVertex3f(origin.x, origin.y + height, origin.z - depth);
    //right
    glVertex3f(origin.x + width, origin.y  + height, origin.z);
    glVertex3f(origin.x + width, origin.y, origin.z);
    glVertex3f(origin.x + width, origin.y, origin.z - depth);
    glVertex3f(origin.x + width, origin.y  + height, origin.z  - depth);
    //left
    glVertex3f(origin.x, origin.y + height, origin.z - depth);
    glVertex3f(origin.x, origin.y, origin.z - depth);
    glVertex3f(origin.x, origin.y, origin.z);
    glVertex3f(origin.x, origin.y + height, origin.z);

    //top
    glVertex3f(origin.x, origin.y + height, origin.z);
    glVertex3f(origin.x + width, origin.y + height, origin.z);
    glVertex3f(origin.x + width, origin.y + height, origin.z - depth);
    glVertex3f(origin.x, origin.y + height, origin.z - depth);
    //bottom
    glVertex3f(origin.x, origin.y, origin.z);
    glVertex3f(origin.x, origin.y, origin.z - depth);
    glVertex3f(origin.x + width, origin.y, origin.z - depth);
    glVertex3f(origin.x + width, origin.y, origin.z);
    glEnd();
}