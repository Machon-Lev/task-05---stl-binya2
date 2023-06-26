#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "ICityDatabase.h"
#include "City.h"
class ImportFile {

    std::string filename;
    ICityDatabase& cityDatabase;
public:
    void readFile();
    ImportFile(const std::string& _filename, ICityDatabase& _cityDatabase);
};



