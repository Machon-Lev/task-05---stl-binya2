#pragma once

#include <iostream>

class Coordinate{
    // private pair
    std::pair<double, double> _myCoordinate;
public:
    // constructor
    Coordinate(double x, double y);

    Coordinate();

    // getter
    double getX() const;
    double getY() const;
};