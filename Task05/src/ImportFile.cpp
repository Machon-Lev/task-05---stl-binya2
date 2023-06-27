
#include "ImportFile.h"

//constructor
ImportFile::ImportFile(const std::string& _filename, ICityDatabase &_cityDatabase) 
    : filename(_filename), cityDatabase(_cityDatabase) {}

//read file
void ImportFile::readFile() {
    std::ifstream file(filename);
    if(!file)
        throw std::runtime_error("File not found");

    std::string line;
    std::string cityName;
    double coordX, coordy;
    char c;
    while(std::getline(file, line)){
        cityName = line;
        if (!std::getline(file, line)) 
            throw std::runtime_error("Incorrect file - missing information");

        std::istringstream iss(line);

        if (!(iss >> coordX >> c >> coordy)) 
            throw std::runtime_error(cityName + "Missing coordinates");
        cityDatabase.addCity(City(cityName, Coordinate( coordX, coordy)));
    }
}
