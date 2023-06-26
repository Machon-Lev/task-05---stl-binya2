#include "Distance.h"
//constructor
Distance::Distance(){
    choiceToFunc[1] = euclidean;
    choiceToFunc[2] = chebyshev;
    choiceToFunc[3] = manhattan;
}

//static methods
double Distance::euclidean(City firstCity, City secondCity){
    return sqrt(pow(firstCity.getCoordinate().getX() - secondCity.getCoordinate().getX(), 2) +
    pow(firstCity.getCoordinate().getY() - secondCity.getCoordinate().getY(), 2));
}

double Distance::chebyshev(City firstCity, City secondCity){
    return std::max(abs(firstCity.getCoordinate().getX() - secondCity.getCoordinate().getX()),
    abs(firstCity.getCoordinate().getY() - secondCity.getCoordinate().getY()));
}

double Distance::manhattan(City firstCity, City secondCity){
    return abs(firstCity.getCoordinate().getX() - secondCity.getCoordinate().getX()) +
    abs(firstCity.getCoordinate().getY() - secondCity.getCoordinate().getY());
}
