#ifndef SERVER_HPP
#define SERVER_HPP

#include "Location.hpp"

class Location;


// Classe per rappresentare un blocco server
class Server {
public:
    std::string server_name;
    int listen;  
    std::string root;
    std::vector<Location> locations;

    Server() {}

    void print() const;
};

#endif