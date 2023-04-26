#include "parser.hh"

BFE::Parser::Parser(std::vector<Token> &tokens)
{
    this->tokens = tokens;
}

BFE::Parser::~Parser()
{
}