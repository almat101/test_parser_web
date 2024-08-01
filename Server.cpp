#include "Server.hpp"
#include "Location.hpp"


void Server::print() const {
        std::cout << "Server:" << std::endl;
        if (!server_name.empty()) std::cout << "  server_name: " << server_name << std::endl;
        if (listen != 80) std::cout << "  listen: " << listen << std::endl;
        if (!root.empty()) std::cout << "  root: " << root << std::endl;
        for (size_t i = 0; i < locations.size(); ++i) {
            locations[i].print();
        }
    };