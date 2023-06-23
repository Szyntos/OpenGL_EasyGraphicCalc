#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <cmath>
#include "Axis.h"
#include "Grid.h"
#include <GL/freeglut_ext.h>

using namespace std;


// Wartości początkowe
int screenWidth = 800;
int screenHeight = 800;

// Klatki na sekundę
int targetFPS = 60;

// Rozdzielczość funckji
int n = 100;

// Wartosći do obsługi myszy
double prevMousePosX = 0;
double prevMousePosY = 0;
double nextMousePosX = 0;
double nextMousePosY = 0;
double draggedDistanceX = 0;
double draggedDistanceY = 0;
double rotationSpeed = 5;



// Inicjalizacja osi
Axis ax(10, 0.05, 0.02);

// Inicjalizacja funkcji
Grid grid(ax, n);


// Przesunięcie wizualizacji
double xOff = -ax.limit/2;
double yOff = -ax.limit/2;
double zOff = -10;



void display();
void init();
void reshape(int, int);
void timer(int);
void mouseMove(int, int);
void mousePassiveMove(int, int);
void mouseWheel(int, int, int, int);
void processNormalKeys(unsigned char, int, int);


int main(int argc, char** argv)
{

//    Ustawienie przesunięcia funkcji i osi
    grid.setOffset(-ax.limit/2, -ax.limit/2, ax.limit/2);
    ax.setOffset(-ax.limit/2, -ax.limit/2, ax.limit/2);


//    Inicjalizacja okna
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowSize(screenWidth, screenHeight);
    glutInitWindowPosition(200, 100);

    glutCreateWindow("Graphical Calc");

    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);


//    Funkcje myszy i klawiatury
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

void mouseMove(int mx, int my) {

//    Aktualizuje wartości odpowiednich draggedDistance
//    Oblicza długość przesunięcia myszki podczas naciśnięcia jakiegoklwiek z przycisków
//    Używane do rotacji wizualizacji

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
//    Aktualizuje wartości nextMousePos i prevMousePos
//    Oblicza długość przesunięcia myszki bez naciśnięcia jakiegoklwiek z przycisków
//    Używane do rotacji wizualizacji

    prevMousePosX = nextMousePosX;
    prevMousePosY = nextMousePosY;
    nextMousePosX = mx;
    nextMousePosY = my;
}

void mouseWheel(int button, int dir, int x, int y){
//    Inkrementuje / dekrementuje zOff przy poruszeniu kółkiem myszy
//    Używane do przybliżania wizualizacji
    if (dir > 0)
    {
        zOff += 0.3;
    }
    else
    {
        zOff -= 0.3;
    }
}

void processNormalKeys(unsigned char key, int x, int y) {
//      Obsługuje naciśniecia klawiszy (nie specjalne)
    if (key == 27){
//      Jeśli Esc wyjdź
        exit(0);
    }else if (key == '=') {
//      Jeśli '=' (czyli '+') zwiększ rozdzielczość siatki
        n += 5;
        n = max(n, 1);
        grid.changeResolution(n);
    } else if (key == '-'){
//      Jeśli '=' (czyli '+') zmniejsz rozdzielczość siatki
        n -= 5;
        n = max(n, 1);
        grid.changeResolution(n);
    }else {
//      Zmień wyświetlaną funckję w zależności od klawisza '0 - 9'
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
//    Ustawienie kolorów
    glClearColor(1, 1, 1, 1);
    glColor3f(1, 1, 1);

}

void reshape(int w, int h){
//    Ustawienie perspektywy
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, ((float) screenWidth/(float) screenHeight), 1, 50);
    glMatrixMode(GL_MODELVIEW);
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

//    Translacja i rotacja sceny
    glTranslatef(0, 0, zOff);
    glRotatef((float) (draggedDistanceY / rotationSpeed), 1, 0, 0);
    glRotatef((float) (draggedDistanceX / rotationSpeed), 0, 1, 0);
    glTranslatef(xOff, yOff, -ax.limit/2);

//    Rysowanie osi
    ax.draw();
    ax.drawText();

//    Rysowanie funkcji
    grid.draw();

    glPopMatrix();
    glutSwapBuffers();
}

void timer(int a){
    glutPostRedisplay();
    glutTimerFunc(1000/targetFPS, timer, 0);
}