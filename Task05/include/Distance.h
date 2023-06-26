#pragma once
#include "City.h"
#include <cmath>
#include <algorithm>
#include <map>
class Distance {
    std::map<int, double (*)(City&, City&)> choiceFunc;
    std::map<int, double (*)(Coordinate, Coordinate)> choiceFunc2;

    // static methods
    static double euclidean(City& firstCity, City& secondCity);
    static double chebyshev(City& firstCity, City& secondCity);
    static double manhattan(City& firstCity, City& secondCity);
    static double euclidean(Coordinate first,  Coordinate second);
    static double chebyshev(Coordinate first,  Coordinate second);
    static double manhattan(Coordinate first,  Coordinate second);


public:
    // getter
    double getDistance(City firstCity, City secondCity, int choice);
    double getDistance(Coordinate first, Coordinate second, int choice);

    //constructor
    Distance();
};



