#pragma once
#include "City.h"
#include "Distance.h"
#include <unordered_map>
#include <vector>
class ICityDatabase {
    std::unordered_map<std::string, City> cities;
    Distance distance;
public:
    const City& getCity(std::string cityName);
    void addCity(const City& city);
    void removeCity(std::string cityName);
    std::vector<City> FindingCitiesInRadius(std::string cityName, double radius, int norm);

};



