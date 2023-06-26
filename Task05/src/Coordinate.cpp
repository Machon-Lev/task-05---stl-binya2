#include "Coordinate.h"

// constructor
Coordinate::Coordinate(double x, double y)
{
    _myCoordinate.first = x;
    _myCoordinate.second = y;
}

//getter
Double Coordinate::getX() const
{
    return _myCoordinate.first;
}

Double Coordinate::getY() const
{
    return _myCoordinate.second;
}