#include "ICityDatabase.h"

// get city by name
City& ICityDatabase::getCity(std::string cityName)
{
    return cities.at(cityName);
    ;
}

// add city to database
void ICityDatabase::addCity(const City& city)
{
    cities.insert(std::pair<std::string, City>(city.getName(), city)) ;
}

// find nearby cities
std::vector<City> ICityDatabase::FindingCitiesInRadius(std::string cityName, double radius, int norm)
{
    const City& city = getCity(cityName);
    std::vector<City> result;
    Distance distance;

   /* std::copy_if(cities.begin(), cities.end(), std::back_inserter(result),
        [&](const auto& pair ) {
            return distance.getDistance(city, pair.second, norm) <= radius;
        });*/

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

int ICityDatabase::citiesInNorth(std::string cityName)
{
    const City& city = getCity(cityName);
    return std::count_if(cities.begin(), cities.end(),
        [&](const auto& pair) {
            return pair.second.getCoordinate().getY() < city.getCoordinate().getY();
        });
}

