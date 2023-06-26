#include <iostream>
#include"ImportFile.h"
#include <memory>
int main(){

    ICityDatabase cityDatabase;
   try{
        ImportFile reader("data.txt", cityDatabase);
        reader.readFile();
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return 1;
   }

	std::string city;
	double radius;
	int norm;
	std::vector<City> result;

   
    
	while(true){
        try {
            std::cout << "Please enter selected city name (with line break after it): \n";
            std::getline(std::cin, city);
            if (city == "0")
				break;
            cityDatabase.getCity(city);
            std::cout << "Please enter the wanted radius: \n";
            std::cin >> radius;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Please enter the wanted norm (0 - L2, Euclidean distance, 1 - Linf, Chebyshev distance, 2 - L1, Manhattan distance): \n";
            std::cin >> norm;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            result = cityDatabase.FindingCitiesInRadius(city, radius, norm);
        }
        catch (const std::out_of_range& e) {
            std::cout << "ERROR: \"" << city << "\" is not found in the city list. Please try again.\n\n";
            continue;
        }

        std::cout << "Search result: \n" << result.size() <<  " city / cities found in the given radius.\n"<< cityDatabase.citiesInNorth(city) << " cities are to the north of the selected city.\nCity list : \n";
        std::copy(result.begin(), result.end(), std::ostream_iterator<City>(std::cout, "\n"));
        
	}
    std::cout << "Bye";

	return 0;
}
