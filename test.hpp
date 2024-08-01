#ifndef TEST_HPP
#define TEST_HPP

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

struct Directive {
    std::string name;
    std::string value;
};

struct LocationBlock {
    std::string path;
    std::vector<Directive> directives;
};

struct ServerBlock {
    std::vector<Directive> directives;
    std::vector<LocationBlock> locations;
};

#endif