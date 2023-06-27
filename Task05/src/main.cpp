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
	std::vector<std::pair<std::string, City>> result;

   
    
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
            if (radius < 0)
                throw std::runtime_error("Radius cannot be negative");

            std::cout << "Please enter the wanted norm (0 - L2, Euclidean distance, 1 - Linf, Chebyshev distance, 2 - L1, Manhattan distance): \n";
            std::cin >> norm;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (norm < 0 || norm > 2)
				throw std::runtime_error("Norm must be 0, 1 or 2");

            cityDatabase.FindingCitiesInRadius(city, radius, norm , result);
        }
        catch (const std::out_of_range& e) {
            std::cout << "ERROR: \"" << city << "\" is not found in the city list. Please try again.\n\n";
            continue;
        }
        catch (const std::runtime_error& e) {
            std::cout << "ERROR: " << e.what() << "\n\n";
            continue;
        }


        std::cout << "Search result: \n" << result.size() <<  " city / cities found in the given radius.\n"<< cityDatabase.citiesInNorth(city, result) << " cities are to the north of the selected city.\nCity list : \n";

        std::transform(result.begin(), result.end(), std::ostream_iterator<std::string>(std::cout, "\n"),
                       [](const auto& pair) { return pair.second.getName(); });
        
	}
    std::cout << "Bye";

	return 0;
}
