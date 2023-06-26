#pragma once
#include "City.h"
#include <cmath>
#include <algorithm>
#include <map>
class Distance {
    std::map<int, double (*)(City, City)> choiceToFunc;

    // static methods
    static double euclidean(City firstCity, City secondCity);
    static double chebyshev(City firstCity, City secondCity);
    static double manhattan(City firstCity, City secondCity);
public:
    // getter
    double getDistance(City firstCity, City secondCity, double choice);

    //constructor
    Distance();
};



