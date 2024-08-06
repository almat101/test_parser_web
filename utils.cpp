// utils.cpp
#include "utils.hpp"
#include <algorithm>  // for std::find
#include <vector>


/**
 * Checks if the provided string is a valid HTTP method.
 *
 * @param method A string representing the HTTP method to validate.
 * @return True if the method is a recognized HTTP method, false otherwise.
 */
bool isValidHttpMethod(const std::string& method)
{
	std::vector<std::string> validMethods;
	validMethods.push_back("GET");
	validMethods.push_back("POST");
	validMethods.push_back("DELETE");

	// std::find checks if 'method' is in 'validMethods'
	// std::find returns an iterator pointing to the found element, or validMethods.end() if it didn't find anything
	return std::find(validMethods.begin(), validMethods.end(), method) != validMethods.end();
}

/**
 * Prints all servers in the provided vector.
 *
 * @param servers A vector of Server objects to print.
 */
void printAllServers(std::vector<Server>& servers)
{
	for (size_t i = 0; i < servers.size(); ++i) {
		servers[i].print();
	}
}
