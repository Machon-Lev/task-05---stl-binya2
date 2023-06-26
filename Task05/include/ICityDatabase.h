#pragma once
#include "City.h"
#include "Distance.h"
#include <unordered_map>
#include <vector>
class ICityDatabase {
    std::unordered_map<std::string, City> cities;
public:
    City& getCity(std::string cityName);
    void addCity(const City& city);
    std::vector<City> FindingCitiesInRadius(std::string cityName, double radius, int norm);

    int citiesInNorth(std::string cityName);
};



