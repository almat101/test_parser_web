#include "server.hpp"
#include "location.hpp"

Server::Server() {};

Server::~Server() {};

Server::Server(const Server& server) : server_name(server.server_name), host(server.host), listen(server.listen), root(server.root), locations(server.locations) {};


Server& Server::operator=(const Server& server) {
		server_name = server.server_name;
		host = server.host;
		listen = server.listen;
		root = server.root;
		// index = server.index;
		locations = server.locations;
		return *this;
	};

void Server::setListen(const std::string& listen) {
		this->listen = listen;
}

void Server::setServerName(const std::string& server_name) {
	this->server_name = server_name;
}

void Server::setRoot(const std::string& root) {
	this->root = root;
}

void Server::setHost(const std::string& host) {
	this->host = host;
}

void Server::print(){
	std::cout << std::endl;
	std::cout << "Server:" << std::endl;
	if (!server_name.empty()) std::cout << "  server_name: |" << server_name << "|" << std::endl;
	if (!host.empty()) std::cout << "  host: |" << host << "|" << std::endl;
	if (!listen.empty()) std::cout << "  listen: |" << listen << "|" << std::endl;
	if (!root.empty()) std::cout << "  root: |" << root << "|" << std::endl;
	// if (!index.empty()) std::cout << "  index: " << index << std::endl;
	for (size_t i = 0; i < locations.size(); ++i) {
		locations[i].print();
	}
};

void Server::printAllServers(std::vector<Server>& servers) {
    for (size_t i = 0; i < servers.size(); ++i) {
        servers[i].print();
    }
}

