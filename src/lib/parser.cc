#include "parser.hh"

BFE::Parser::Parser(std::vector<Token> &tokens)
{
    this->tokens = tokens;
    this->current_index = 0;
}

BFE::Parser::~Parser()
{
}

std::vector<BFE::Symbol> BFE::Parser::parse()
{
    if (this->tokens[this->current_index].value == "&")
    {
        
    }
}