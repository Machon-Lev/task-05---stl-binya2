#include "Distance.h"
//constructor
Distance::Distance(){
    choiceFunc[0] = euclidean;
    choiceFunc[1] = chebyshev;
    choiceFunc[2] = manhattan;
    choiceFunc2[0] = euclidean;
    choiceFunc2[1] = chebyshev;
    choiceFunc2[2] = manhattan;
}

//static methods city
double Distance::euclidean(City& firstCity, City& secondCity){
    return sqrt(pow(firstCity.getCoordinate().getX() - secondCity.getCoordinate().getX(), 2) +
    pow(firstCity.getCoordinate().getY() - secondCity.getCoordinate().getY(), 2));
}

double Distance::chebyshev(City& firstCity, City& secondCity){
    return std::max(abs(firstCity.getCoordinate().getX() - secondCity.getCoordinate().getX()),
    abs(firstCity.getCoordinate().getY() - secondCity.getCoordinate().getY()));
}

double Distance::manhattan(City& firstCity, City& secondCity){
    return abs(firstCity.getCoordinate().getX() - secondCity.getCoordinate().getX()) +
    abs(firstCity.getCoordinate().getY() - secondCity.getCoordinate().getY());
}

double Distance::getDistance(City firstCity, City secondCity, int choice)
{
    return choiceFunc.at(choice)(firstCity, secondCity);
}


//static methods coordinate
double Distance::euclidean(Coordinate first, Coordinate second) {
    return sqrt(pow(first.getX() - second.getX(), 2) +
        pow(first.getY() - second.getY(), 2));
}

double Distance::chebyshev(Coordinate first, Coordinate second) {
    return std::max(abs(first.getX() - second.getX()),
        abs(first.getY() - second.getY()));
}

double Distance::manhattan(Coordinate first, Coordinate second) {
    return abs(first.getX() - second.getX()) +
           abs(first.getY() - second.getY());
}

double Distance::getDistance(Coordinate first, Coordinate second, int choice)
{
    return choiceFunc2.at(choice)(first, second);
}
