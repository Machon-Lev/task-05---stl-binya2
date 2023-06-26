#pragma once
#include "Coordinate.h"
#include "City.h"
class Distance {
//constructor
public:
    Distance();
    // static methods
    static double euclidean(City firstCity, City secondCity);
    static double chebyshev(City firstCity, City secondCity);
    static double manhattan(City firstCity, City secondCity);
};



