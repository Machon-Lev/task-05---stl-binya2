#pragma once


class City {
    std::string _name;
    Coordinate _coordinate;
public:
    // constructor
    City(std::string name, Coordinate coordinate);
    // getter
    std::string getName() const;
    Coordinate getCoordinate() const;
};



