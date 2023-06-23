#include "Grid.h"
#include <GL/glut.h>

void Grid::drawCubes() {
//    Rysuje funkcję jako siatkę punktów
    for (int i = 0; i < (n+1); i++) {
        for (int j = 0; j < n+1; j++) {
            arr[i][j].draw();
        }
    }
}

void Grid::draw() {
//    Rysuje funkcje przybliżając ją trójkątami
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
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
