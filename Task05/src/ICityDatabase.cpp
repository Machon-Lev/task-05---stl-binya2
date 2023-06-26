#include "ICityDatabase.h"

// get city by name
const City ICityDatabase::getCity(std::string cityName)
{
    return cities[cityName];
}
// add city to database
void ICityDatabase::addCity(City city)
{
    cities[city.getName()] = city;
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
    Distance distance;

    std::copy_if(cities.begin(), cities.end(), std::back_inserter(result),
                 [&](const auto& pair) {
                     return distance.getDistance(city, pair.second, norm) <= radius;
                 });

    std::sort(result.begin(), result.end(),
              [&](const City& city1, const City& city2) {
                  return distance.getDistance(city, city1, norm) < distance.getDistance(city, city2, norm);
              });

    return result;
}
