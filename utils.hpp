// utils.hpp
#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include "server.hpp"
#include "location.hpp"

class Server;
class Location;


bool isValidHttpMethod(const std::string& method);
void printAllServers(std::vector<Server>& servers);


#endif  // UTILS_HPP
