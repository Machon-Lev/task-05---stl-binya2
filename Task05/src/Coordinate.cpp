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

Coordinate& Coordinate::operator=(const Coordinate& other)
{
    if (this != &other) {
        _myCoordinate = other._myCoordinate;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Coordinate& coordinate)
{
    os << "(" << coordinate.getX() << ", " << coordinate.getY() << ")";
    return os;
}
