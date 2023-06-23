#ifndef UNTITLED_GRID_H
#define UNTITLED_GRID_H


#include "Point.h"
#include "Axis.h"
#include <math.h>
#include <iostream>

class Grid {
//    Reprezantacja funkcji na siatce
public:
//    Rozdzielczość funkcji
    int n;
//    Osie, według których funkcja jest rysowana
    Axis ax;
//    Lista 2D punktów funkcji
    Point** arr;
//    Typ wyświetlanej funkcji
    int functionType = 0;
//    Przesunięcie funkcji
    double xOff = 0;
    double yOff = 0;
    double zOff = 0;


    Grid(){
        n = 1;
    }

    Grid(Axis nax, int nn){
        n = nn;
        ax = nax;
        constructArr();
    }
    void changeResolution(int nn){
        n = nn;
        constructArr();
    }

    void constructArr(){
//        Wypełnia listę punktami wg funkcji
        arr = new Point*[n+1];
        for (int i = 0; i < n+1; i++) {
            arr[i] = new Point[n+1];
        }
        float newX;
        float newZ;
        float value;
        float dx = ax.limit/n;
        float dz = ax.limit/n;
        int k = 0;
        for (int i = 0; i < n+1; ++i) {
            for (int j = 0; j < n+1; ++j) {
                newX = i * dx;
                newZ = j * dz;
                value = f(newX, newZ);
                arr[i][j] = Point(newX, value, newZ, Color(smoothstep((value - zOff)/5+0.3),
                                                           smoothstep((value - zOff)/5),
                                                           smoothstep((value - zOff)/9+0.3)));
                k++;
            }
        }
    }
    float smoothstep(float x, float edge0 = 0.0f, float edge1 = 1.0f) {
//        funkcja z wikipedii Smoothstep
        // Scale, and clamp x to 0..1 range
        x = clamp((x - edge0) / (edge1 - edge0));

        return x * x * (3.0f - 2.0f * x);

    }float clamp(float x, float lowerlimit = 0.0f, float upperlimit = 1.0f) {
        if (x < lowerlimit) return lowerlimit;
        if (x > upperlimit) return upperlimit;
        return x;
    }



    void setOffset(double x, double  y, double z){
//        Ustawia przesunięcie funkcji
        xOff = x;
        yOff = y;
        zOff = z;
        constructArr();

    }
    float sign(float x){
        if(x < 0){
            return -1;
        }else if (x > 0){
            return 1;
        }
        return 0;
    }

    float f(float x, float y){
//        Funkcje wyświetlane na ekranie
        float newX = x + xOff;
        float newY = y + yOff;
        switch (functionType) {
            
            case 0:
//                return (sign(0.2-((newX)*(newX)+(newY)*(newY))) + sign(0.2-((newX)*(newX)/3+(newY)*(newY)/3)))/3 + zOff;
                return 1.5 * pow(2.72, ((-newX*newX - newY*newY))) + zOff;
            case 1:
                return pow((0.4*0.4-pow((0.6-pow(((newX)*(newX)+(newY)*(newY)),0.5)),2)),0.5) + zOff;
            case 2:
                return sin((newX)*(newX))+cos((newY)*(newY)) + zOff;
            case 3:
                return sign((newX)*(newY)) * sign(1-pow(((newX)*9),2)+pow(((newY)*9),2))/9 + zOff;
            case 4:
                return sign((newX)) * atan((newX)*80)/6 * sign(-(newY)-(newX)+1) * sign(-(newY)+(newX)+1)*5 - 1.01 + zOff;
            case 5:
                return 4 * sin(10*((newX)*(newX)+(newY)*(newY)))/10 + zOff;
            case 6:
                return ( ((1-sign(-(newX)-.9+abs((newY)*2)))/3*(sign(.9-(newX))+1)/3)*(sign((newX)+.65)+1)/2 -
                ((1-sign(-(newX)-.39+abs((newY)*2)))/3*(sign(.9-(newX))+1)/3) +
                ((1-sign(-(newX)-.39+abs((newY)*2)))/3*(sign(.6-(newX))+1)/3)*(sign((newX)-.35)+1)/2) + zOff;

        }
        return 0;
    }

    void changeFunction(){
//        Cykluje rodzaj funkcji
        functionType++;
        functionType = functionType%7;
        constructArr();
    }

    void changeFunction(int f){
//        Zmienia typ funkcji na podany
        functionType = f % 7;
        constructArr();
    }

    void draw();

    void drawCubes();
};


#endif //UNTITLED_GRID_H
