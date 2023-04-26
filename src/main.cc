#include ".\lib\lexer.hh"
#include ".\lib\module.hh"
#include ".\lib\parser.hh"
#include <iostream>
#include <string>
#include <filesystem>

void parse_argv(int, char **);

int main(int argc, char **argv)
{
    parse_argv(argc, argv);
    BFE::Lexer lexer(BFE::read_string_from_file(std::string(argv[1])));
    std::vector<BFE::Token> tokens = lexer.get_tokens();
    BFE::Parser parser(tokens);
    return 0;
}

void parse_argv(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << R"(
Usage:
    bfe input_file.bfe
            )" << std::endl;
        exit(0);
    }

    if (!std::filesystem::exists(argv[1]))
    {
        std::cerr << "Cannot find input file " << argv[1] << std::endl;
        exit(1);
    }
}