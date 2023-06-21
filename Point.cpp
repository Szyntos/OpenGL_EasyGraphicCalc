#include "Point.h"
#include "Cube.h"
#include <GL/glut.h>
#include <GL/glu.h>

void Point::draw() {
    Cube c(*this, size, size, size, clr);
    c.draw();
}
