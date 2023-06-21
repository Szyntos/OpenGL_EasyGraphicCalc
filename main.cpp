#include <GL/glut.h>
#include <GL/glu.h>
#include <cmath>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Point.h"
#include "Cube.h"
#include "Axis.h"
#include "Grid.h"
#include <GL/freeglut_ext.h>

using namespace std;

int screenWidth = 800;
int screenHeight = 800;
int targetFPS = 60;
double i = 0;
double prevMousePosX = 0;
double prevMousePosY = 0;
double nextMousePosX = 0;
double nextMousePosY = 0;

double draggedDistanceX = 0;
double draggedDistanceY = 0;
double passiveDistanceX = 0;
double passiveDistanceY = 0;
double rotationSpeed = 5;

double zOff = -10;

Point p(0, 0, 0);
Cube c(p, 2, 2, 2);
Axis ax(5, 0.05, 0.02);
int n = 100;
Grid grid(ax, n);
double xOff = -ax.limit/2;
double yOff = -ax.limit/2;

void display();

void init();
void reshape(int, int);
void timer(int);
void mouseMove(int, int);
void mousePassiveMove(int, int);
void onPress(int, int);
void mouseWheel(int, int, int, int);
void processNormalKeys(unsigned char, int, int);


int main(int argc, char** argv)
{

    grid.setOffset(-ax.limit/2, -ax.limit/2, ax.limit/3);
    ax.setOffset(-ax.limit/2, -ax.limit/2, ax.limit/3);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(200, 100);

    glutCreateWindow("Graphical Calc");

    glutDisplayFunc(display);

    glutMotionFunc(mouseMove);
    glutPassiveMotionFunc(mousePassiveMove);
    glutMouseWheelFunc(mouseWheel);
    glutKeyboardFunc(processNormalKeys);

    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    init();

    glutMainLoop();
    return 0;
}

void onPress(int mx, int my) {
    mouseMove(mx, my);
    cout << "b" << endl;
}

void mouseMove(int mx, int my) {
    double mdx;
    double mdy;


    prevMousePosX = nextMousePosX;
    prevMousePosY = nextMousePosY;
    nextMousePosX = mx;
    nextMousePosY = my;
    mdx = nextMousePosX - prevMousePosX;
    mdy = nextMousePosY - prevMousePosY;
    draggedDistanceX += mdx;
    draggedDistanceY += mdy;


}

void mousePassiveMove(int mx, int my){
    double mdx;
    double mdy;
    prevMousePosX = nextMousePosX;
    prevMousePosY = nextMousePosY;
    nextMousePosX = mx;
    nextMousePosY = my;
    mdx = nextMousePosX - prevMousePosX;
    mdy = nextMousePosY - prevMousePosY;

    passiveDistanceX += mdx;
    passiveDistanceY += mdy;
//    cout << passiveDistanceY << endl;
}

void mouseWheel(int button, int dir, int x, int y)
{
    if (dir > 0)
    {
        zOff += 0.3;
    }
    else
    {
        zOff -= 0.3;
    }
//    if (dir > 0)
//    {
//        n += 1;
//    }
//    else
//    {
//        n -= 1;
//    }
//    n = max(n, 1);
//    grid.changeResolution(n);
}

void processNormalKeys(unsigned char key, int x, int y) {

    if (key == 27){
        exit(0);
    }else if (key == '=') {
        n += 5;
        n = max(n, 1);
        grid.changeResolution(n);
    } else if (key == '-'){
        n -= 5;
        n = max(n, 1);
        grid.changeResolution(n);
    }else {
        switch (key) {
            case '1':
                grid.changeFunction(0);
                break;
            case '2':
                grid.changeFunction(1);
                break;
            case '3':
                grid.changeFunction(2);
                break;
            case '4':
                grid.changeFunction(3);
                break;
            case '5':
                grid.changeFunction(4);
                break;
            case '6':
                grid.changeFunction(5);
                break;
            case '7':
                grid.changeFunction(6);
                break;
            default:
                ;
        }

    }

}

void init(){
    glClearColor(0.5, 0.5, 0.5, 1);
    glColor3f(1, 1, 1);
    glEnable(GL_DEPTH_TEST);
}

void reshape(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, ((float) screenWidth/(float) screenHeight), 1, 50);
    glMatrixMode(GL_MODELVIEW);

}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//    glLoadIdentity();
    glPushMatrix();


    glTranslatef(0, 0, zOff);
//    glTranslatef(xOff, yOff, zOff);
    glRotatef((float) (draggedDistanceY / rotationSpeed), 1, 0, 0);
//    glTranslatef(0, 0, -(zOff-8));

//    glLoadIdentity();
//    glTranslatef(0, 0, zOff-8);
    glRotatef((float) (draggedDistanceX / rotationSpeed), 0, 1, 0);
    glTranslatef(xOff, yOff, -ax.limit/2);


//    c.draw();

    ax.draw();
    ax.drawText();

    grid.draw();
    glPopMatrix();
    glutSwapBuffers();
}

void timer(int a){
    glutPostRedisplay();
    glutTimerFunc(1000/targetFPS, timer, 0);
}