#pragma once

class Coordinate{
    // private pair
    std::pair<double, double> _myCoordinate;
public:
    // constructor
    Coordinate(double x, double y);
    // getter
    double getX() const;
    double getY() const;
};