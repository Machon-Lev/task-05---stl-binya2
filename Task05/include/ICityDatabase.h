#pragma once
#include "City.h"
#include "Distance"
#include <unordered_map>
class ICityDatabase {
    std::unordered_map<string, City> cities;

public:
    ICityDatabase();
    const City getCity(std::string cityName);
    void addCity(City city);
    void removeCity(std::string cityName);
    std::vector<City> FindingCitiesInRadius(std::string cityName, double radius, int norm);

};



