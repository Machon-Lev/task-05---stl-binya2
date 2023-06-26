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

City& City::operator=(const City& other)
{
    if (this != &other) {
        _name = other.getName();
        _coordinate = other.getCoordinate();
    }
    return *this;
}


std::ostream& operator<<(std::ostream& os, const City& city)
{
    os <<  city._name ;
    return os;
}