#include "Coordinate.h"

// constructor
Coordinate::Coordinate(double x, double y)
{
    _myCoordinate.first = x;
    _myCoordinate.second = y;
}

//getter
double Coordinate::getX() const
{
    return _myCoordinate.first;
}

double Coordinate::getY() const
{
    return _myCoordinate.second;
}

Coordinate::Coordinate() {}
