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
#include <vector>
#include <sstream>
#include <algorithm>

#include "server.hpp"
#include "config_parser.hpp"
#include "utils.hpp"

//allow GET POST DELETE only

class Location {
public:
    std::string path;
    std::string index;  //this is present also in Server class
    std::vector<std::string> allow; // this is a list of HTTP methods it allows only GET POST DELETE
    bool autoindex;
    // std::string root;

	//getters
	std::vector<std::string> getAllow();
	std::string getIndex();
	std::string getPath();
	bool getAutoindex();

	//setters
	void setIndex(const std::string& index);
	void setPath(const std::string& path);
	void setAllow(const std::vector<std::string>& allow);
	void setAutoindex(bool autoindex);

    Location();
	~Location();
	Location(const Location& location);
	Location& operator=(const Location& location);

    void print();
};



#endif
