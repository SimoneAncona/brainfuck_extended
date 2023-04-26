#pragma once
#include "token.hh"
#include <vector>
#include "symbol.hh"

namespace BFE
{
    class Parser
    {
    private:
        std::vector<Token> tokens;
    public:
        Parser(std::vector<Token>&);
        ~Parser();

        std::vector<Symbol> parse();
    };
}