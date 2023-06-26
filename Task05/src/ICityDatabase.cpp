#include "ICityDatabase.h"

// get city by name
const City& ICityDatabase::getCity(std::string cityName)
{
    return cities.at(cityName);
    ;
}

// add city to database
void ICityDatabase::addCity(const City& city)
{
    cities.at(city.getName()) = city;
}


// remove city from database
void ICityDatabase::removeCity(std::string cityName)
{
    cities.erase(cityName);
}

// find nearby cities
std::vector<City> ICityDatabase::FindingCitiesInRadius(std::string cityName, double radius, int norm)
{
    const City& city = getCity(cityName);
    std::vector<City> result;

    for (const auto& pair : cities) {
        if (distance.getDistance(city, pair.second, norm) <= radius)
            result.push_back(pair.second);
    }

    std::sort(result.begin(), result.end(),
        [&](const City& city1, const City& city2) {
            return distance.getDistance(city, city1, norm) < distance.getDistance(city, city2, norm);
        });

    return result;
}

