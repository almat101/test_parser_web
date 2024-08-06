#include "location.hpp"

Location::Location() : path(""), index() {}

Location::~Location() {}

Location::Location(const Location &location) : path(location.path), index(location.index) {}

Location &Location::operator=(const Location &location)
{
	path = location.path;
	// allow = location.allow;
	// autoindex = location.autoindex;
	// root = location.root;
	index = location.index;
	return *this;
}

void Location::setIndex(const std::string &index)
{
	this->index = index;
}

void Location::setPath(const std::string &path)
{
	this->path = path;
}

void Location::print()
{
	std::cout << "  Location |" << path << "|" << std::endl;
	// if (!allow.empty())
	// {
	// 	std::cout << "    allow: ";
	// 	for (std::vector<std::string>::const_iterator it = allow.begin(); it != allow.end(); ++it) {
	// 		std::cout << *it << " ";
	// 	}
	// 	std::cout << std::endl;
	// }
	// if (!autoindex.empty()) std::cout << "    autoindex: " << autoindex << std::endl;
	// if (!root.empty()) std::cout << "    root: " << root << std::endl;
	if (!index.empty()) std::cout << "    index: |" << index << "|" << std::endl;
}
