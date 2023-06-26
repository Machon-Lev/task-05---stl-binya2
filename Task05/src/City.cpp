#include "City.h"

//constructor
City::City(std::string name, Coordinate coordinate)
{
    _name = name;
    _coordinate = coordinate;
}

//getter
std::string City::getName() const
{
    return _name;
}

Coordinate City::getCoordinate() const
{
    return _coordinate;
}