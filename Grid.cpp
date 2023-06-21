//
// Created by Szymon on 21.06.2023.
//

#include "Grid.h"
#include <GL/glut.h>

void Grid::drawCubes() {
    for (int i = 0; i < (n+1); i++) {
        for (int j = 0; j < n+1; j++) {
            arr[i][j].draw();
        }
    }
}

void Grid::draw() {
    for (int i = 0; i < (n+1); i++) {
        for (int j = 0; j < n+1; j++) {
            if (i < n){
                if (j < n){
                    glBegin(GL_TRIANGLES);
                    glColor3f(arr[i][j].clr.r, arr[i][j].clr.g, arr[i][j].clr.b);

                    glVertex3f(arr[i][j].x, arr[i][j].y, arr[i][j].z);
                    glVertex3f(arr[i][j+1].x, arr[i][j+1].y, arr[i][j+1].z);
                    glVertex3f(arr[i+1][j].x, arr[i+1][j].y, arr[i+1][j].z);

                    glColor3f(arr[i+1][j+1].clr.r, arr[i+1][j+1].clr.g, arr[i+1][j+1].clr.b);

                    glVertex3f(arr[i][j+1].x, arr[i][j+1].y, arr[i][j+1].z);
                    glVertex3f(arr[i+1][j+1].x, arr[i+1][j+1].y, arr[i+1][j+1].z);
                    glVertex3f(arr[i+1][j].x, arr[i+1][j].y, arr[i+1][j].z);
                    glEnd();
                }

            }

        }
    }
}
