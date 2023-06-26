#pragma once

#include <iostream>

class Coordinate{
    // private pair
    std::pair<double, double> _myCoordinate;
public:
    // constructor
    Coordinate(double x, double y);

    Coordinate();
    Coordinate& operator=(const Coordinate& other);

    // getter
    double getX() const;
    double getY() const;
    friend std::ostream& operator<<(std::ostream& os, const Coordinate& coordinate);
};