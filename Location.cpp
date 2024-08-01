#include "Location.hpp"

void Location::print() const {
        std::cout << "  Location " << path << ":" << std::endl;
        if (!allow.empty()) std::cout << "    allow: " << allow << std::endl;
        if (!autoindex.empty()) std::cout << "    autoindex: " << autoindex << std::endl;
        if (!root.empty()) std::cout << "    root: " << root << std::endl;
        if (!index.empty()) std::cout << "    index: " << index << std::endl;
    }