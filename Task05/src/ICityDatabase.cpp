#include "ICityDatabase.h"

// get city by name
City& ICityDatabase::getCity(std::string cityName)
{
    return cities.at(cityName);
}

// add city to database
void ICityDatabase::addCity(const City& city)
{
    cities.insert(std::pair<std::string, City>(city.getName(), city)) ;
}

// find nearby cities
std::vector<std::pair<std::string, City>> ICityDatabase::FindingCitiesInRadius(std::string cityName, double radius, int norm, std::vector<std::pair<std::string, City>>& result)
{
    const City& city = getCity(cityName);
    Distance distance;
    //filter cities within a square distance
    std::copy_if(cities.begin(), cities.end(), std::back_inserter(result),
        [&](const auto& pair ) {
            return std::abs(city.getCoordinate().getX() - pair.second.getCoordinate().getX()) <= radius &&
                    std::abs(city.getCoordinate().getY() - pair.second.getCoordinate().getY()) <= radius;
        });
    //filter cities within a circle distance
    result.erase(std::remove_if(result.begin(), result.end(),
        [&](const auto& pair) {
            return distance.getDistance(city, pair.second, norm) > radius;
        }), result.end());
    //sort cities by distance
    std::sort(result.begin(), result.end(),
        [&](const  auto& pair1,  const auto& pair2) {
            return distance.getDistance(city, pair1.second, norm) < distance.getDistance(city, pair2.second, norm);
        });

    return result; 
}

int ICityDatabase::citiesInNorth(std::string cityName , std::vector<std::pair<std::string, City>>& result)
{
    //filter cities in north
    const City& city = getCity(cityName);
    return std::count_if(result.begin(), result.end(),
        [&](const auto& pair) {
            return pair.second.getCoordinate().getY() < city.getCoordinate().getY();
        });
}

