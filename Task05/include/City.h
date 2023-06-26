#pragma once
#include "Coordinate.h"
#include <iostream>
class City {
    std::string _name;
    Coordinate _coordinate;
public:
    // constructor
    City(std::string name, Coordinate coordinate);
    City(const City& other) = default;

    // getter
    std::string getName() const;
    Coordinate getCoordinate() const;

    friend std::ostream& operator<<(std::ostream& os, const City& city);

    City& operator=(const City& other);

};



