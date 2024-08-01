#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string>

#include "Server.hpp"
// Classe per rappresentare un blocco location
class Location {
public:
    std::string path;
    std::string allow;
    std::string autoindex;
    std::string root;
    std::string index;

    Location() : autoindex("off") {}

    void print() const;
};



#endif
