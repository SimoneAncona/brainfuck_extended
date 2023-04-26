#include "modules.hh"

std::string BFE::read_string_from_file(const std::string &filename)
{
    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}