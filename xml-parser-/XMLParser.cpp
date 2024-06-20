#include "XMLParser.h"

std::stringstream& XMLParser::saveFileToStream()
{
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "not open" << std::endl;
    }
    std::stringstream stream;
    stream << file.rdbuf();
    file.close();
    return stream;
}
