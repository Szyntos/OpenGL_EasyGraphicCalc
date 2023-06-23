#include "Point.h"
#include "Cube.h"

void Point::draw() {
//    Rysuje punkt jako kostkę w danym punkcie o wymiarach size x size x size i kolorze clr
    Cube c(*this, size, size, size, clr);
    c.draw();
}
