#include "Point.h"

Point::Point(int _x, int _y, Game& _f):
    api(_f),
    originX(_x),
    originY(_y),
    x(0),
    y(0)
    {;}
