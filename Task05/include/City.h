#pragma once
#include "Coordinate.h"
#include <iostream>
class City {
    std::string _name;
    Coordinate _coordinate;
public:
    // constructor
    City(std::string name, Coordinate coordinate);
    City(const City& other);

    // getter
    std::string getName() const;
    Coordinate getCoordinate() const;
    City& operator=(const City& other);
    friend std::ostream& operator<<(std::ostream& os, const City& city);

};



