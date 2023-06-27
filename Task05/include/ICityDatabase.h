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
    std::vector<std::pair<std::string, City>> FindingCitiesInRadius(std::string cityName, double radius, int norm, std::vector<std::pair<std::string, City>>& result);

    int citiesInNorth(std::string cityName, std::vector<std::pair<std::string, City>>& result);
};



