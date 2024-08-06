#ifndef SERVER_HPP
#define SERVER_HPP

#include "location.hpp"
#include "utils.hpp"

class Location;


class Server {
public:
    std::string server_name;
	std::string host; // not present in ngnix
	std::string listen;
    std::string root;
	// std::string index;  // this can be overridden by location block, if not present in location block, it will be  the default index of all the locations
    std::vector<Location> locations;

	Server();
	~Server();
	Server(const Server& server);
	Server& operator=(const Server& server);
	void setListen(const std::string& listen);
	void setServerName(const std::string& server_name);
	void setRoot(const std::string& root);
	void setHost(const std::string& host);

	void print();
	void printAllServers(std::vector<Server>& servers);
};

#endif
