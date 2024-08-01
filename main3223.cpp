#include "test.hpp"

std::string readFile(const char* filepath) {
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        std::cerr << "Errore nell'apertura del file: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }

    struct stat statbuf;
    if (stat(filepath, &statbuf) == -1) {
        std::cerr << "Errore nella chiamata stat: " << strerror(errno) << std::endl;
        close(fd);
        exit(EXIT_FAILURE);
    }

    char* buffer = new char[statbuf.st_size + 1];
    if (!buffer) {
        std::cerr << "Errore nell'allocazione della memoria" << std::endl;
        close(fd);
        exit(EXIT_FAILURE);
    }

    ssize_t bytesRead = read(fd, buffer, statbuf.st_size);
    if (bytesRead == -1) {
        std::cerr << "Errore nella lettura del file: " << strerror(errno) << std::endl;
        delete[] buffer;
        close(fd);
        exit(EXIT_FAILURE);
    }

    buffer[bytesRead] = '\0';

    close(fd);

    std::string fileContent(buffer);
    delete[] buffer;

    return fileContent;
}

void parseConfig(const std::string& content, std::vector<ServerBlock>& servers) {
    std::vector<std::string> lines;
    std::string line;
    size_t pos = 0, found;

    while ((found = content.find_first_of('\n', pos)) != std::string::npos) {
        lines.push_back(content.substr(pos, found - pos));
        pos = found + 1;
    }
    lines.push_back(content.substr(pos));

    ServerBlock currentServer;
    LocationBlock currentLocation;
    bool inServerBlock = false;
    bool inLocationBlock = false;

    for (size_t i = 0; i < lines.size(); ++i) {
        line = lines[i];
        // Ignora i commenti e le linee vuote
        if (line.empty() || line[0] == '#') {
            continue;
        }

        // Rimuovi spazi iniziali e finali
        line.erase(0, line.find_first_not_of(" \t"));
        line.erase(line.find_last_not_of(" \t") + 1);

        if (line == "server {") {
            inServerBlock = true;
            currentServer = ServerBlock();
        } else if (line == "}") {
            if (inLocationBlock) {
                currentServer.locations.push_back(currentLocation);
                inLocationBlock = false;
            } else if (inServerBlock) {
                servers.push_back(currentServer);
                inServerBlock = false;
            }
        } else if (line.find("location") == 0 && line.find('{') != std::string::npos) {
            inLocationBlock = true;
            currentLocation = LocationBlock();
            size_t pathStart = line.find_first_of(" \t") + 1;
            size_t pathEnd = line.find_last_of(" \t{");
            currentLocation.path = line.substr(pathStart, pathEnd - pathStart);
        } else {
            size_t delimiterPos = line.find(' ');
            if (delimiterPos != std::string::npos) {
                std::string directive = line.substr(0, delimiterPos);
                std::string value = line.substr(delimiterPos + 1);
                // Rimuove il punto e virgola alla fine
                if (!value.empty() && value[value.size() - 1] == ';') {
                    value.erase(value.size() - 1);
                }
                if (inLocationBlock) {
                    currentLocation.directives.push_back({directive, value});
                } else if (inServerBlock) {
                    currentServer.directives.push_back({directive, value});
                }
            }
        }
    }
}




int main() {
    const char* filepath = "config.conf";
    std::string content = readFile(filepath);

    std::vector<ServerBlock> servers;
    parseConfig(content, servers);

    // Stampa i risultati del parsing
    for (size_t i = 0; i < servers.size(); ++i) {
        std::cout << "Server " << i + 1 << ":" << std::endl;
        for (size_t j = 0; j < servers[i].directives.size(); ++j) {
            std::cout << "  " << servers[i].directives[j].name << ": " << servers[i].directives[j].value << std::endl;
        }
        for (size_t k = 0; k < servers[i].locations.size(); ++k) {
            std::cout << "  Location " << servers[i].locations[k].path << ":" << std::endl;
            for (size_t l = 0; l < servers[i].locations[k].directives.size(); ++l) {
                std::cout << "    " << servers[i].locations[k].directives[l].name << ": " << servers[i].locations[k].directives[l].value << std::endl;
            }
        }
    }

    return 0;
} 