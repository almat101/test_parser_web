#include "server.hpp"
#include "location.hpp"

Server::Server() :
	host("0.0.0.0"),
	listen("80"),
	index("index.html") // default index if no index is specified in the location block
{}

Server::~Server()
{}

Server::Server(const Server& src)
{
	*this = src;
}


Server& Server::operator=(const Server& rhs) {
	if (this != &rhs) {
		server_names = rhs.server_names;
		host = rhs.host;
		listen = rhs.listen;
		root = rhs.root;
		index = rhs.index;
		locations = rhs.locations;
	}
		return *this;
	};

std::vector<std::string> Server::getServerNames() {
	return server_names;
}

std::string Server::getHost() {
	return host;
}

std::string Server::getListen() {
	return listen;
}

std::string Server::getRoot() {
	return root;
}

std::string Server::getIndex() {
	return index;
}



void Server::setServerNames(const std::vector<std::string>& server_names) {
	this->server_names = server_names;
}

void Server::setHost(const std::string& host) {
	this->host = host;
}

void Server::setListen(const std::string& listen) {
		this->listen = listen;
}

void Server::setRoot(const std::string& root) {
	this->root = root;
}


void Server::setIndex(const std::string& index) {
	this->index = index;
}



void Server::print(){
	std::cout << std::endl;
	std::cout << "Server:" << std::endl;
	if (!server_names.empty())
	{
		std::cout << "  server_names: ";
		for (std::vector<std::string>::const_iterator it = server_names.begin(); it != server_names.end(); ++it) {
			const std::string& name = *it;
			std::cout << "|" << name << "| ";
		}
		std::cout << std::endl;
	}
	if (!host.empty()) std::cout << "  host: |" << host << "|" << std::endl;
	if (!listen.empty()) std::cout << "  listen: |" << listen << "|" << std::endl;
	if (!root.empty()) std::cout << "  root: |" << root << "|" << std::endl;
	if (!index.empty()) std::cout << "  index: |" << index << "|" << std::endl;
	for (size_t i = 0; i < locations.size(); ++i) {
		locations[i].print();
	}
};

void Server::printAllServers(std::vector<Server>& servers) {
    for (size_t i = 0; i < servers.size(); ++i) {
        servers[i].print();
    }
}

